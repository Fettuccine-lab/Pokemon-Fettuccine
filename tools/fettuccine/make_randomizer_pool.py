#!/usr/bin/env python3
"""
Writes src/data/randomizer_pool.h: every Pokémon a player can actually obtain
in this game, for the New Game randomizer to pick from.

Run from the project root whenever wild Pokémon, gifts or legendary spots change:
    python3 tools/fettuccine/make_randomizer_pool.py

A Pokémon counts when it's in a wild table, a starter, a scripted gift, egg,
trade or battle, or when one of those can evolve into it, breed down to it or
change into it outside of battle. Wonder Trade doesn't count: it can return
nearly anything, including Paradox Pokémon.
"""

import glob
import json
import os
import re
import subprocess

OUTPUT = "src/data/randomizer_pool.h"
SCRIPT_COMMANDS = ("givemon", "giveegg", "setwildbattle", "wildbattle", "dowildbattle", "seteventmon")
NEVER = {"SPECIES_NONE", "SPECIES_EGG", "SPECIES_SPEAROW_MIKE"}
BATTLE_METHOD = re.compile(r"FORM_CHANGE_BATTLE|FORM_CHANGE_BEGIN_BATTLE|FORM_CHANGE_END_BATTLE|FORM_CHANGE_FAINT")


def preprocess(path):
    cpp = os.path.join(os.environ.get("DEVKITARM", "/opt/devkitpro/devkitARM"), "bin", "arm-none-eabi-cpp")
    args = [cpp, "-iquote", "include", "-Wno-trigraphs", "-DMODERN=1", "-DTESTING=0", "-DEMERALD", "-std=gnu17", path]
    return subprocess.run(args, capture_output=True, text=True, check=True).stdout


def read_block(text, start):
    depth, i = 0, start
    while True:
        if text[i] == "{":
            depth += 1
        elif text[i] == "}":
            depth -= 1
            if depth == 0:
                return text[start + 1:i], i
        i += 1


def read_species(text):
    """Every enabled species' block out of the preprocessed gSpeciesInfo table."""
    table = re.search(r"gSpeciesInfo\[\]\s*=\s*\{", text)
    body, _ = read_block(text, table.end() - 1)
    species = {}
    for match in re.finditer(r"\[(SPECIES_\w+)\]\s*=\s*\{", body):
        block, _ = read_block(body, match.end() - 1)
        species[match.group(1)] = block
    return species


def evolutions_of(block):
    match = re.search(r"\.evolutions\s*=", block)
    if not match:
        return []
    start = block.index("{", match.end())
    inner, _ = read_block(block, start)
    return re.findall(r"\bSPECIES_\w+", inner)


def has_flag(block, *flags):
    return any(re.search(r"\.%s\s*=\s*(TRUE|1)\b" % flag, block) for flag in flags)


def form_table(block, text):
    match = re.search(r"\.formChangeTable\s*=\s*(\w+)", block)
    if not match or match.group(1) == "NULL":
        return []
    found = re.search(r"\b%s\[\]\s*=\s*(\{)" % match.group(1), text)
    if not found:
        return []
    inner, _ = read_block(text, found.start(1))
    return [(m.group(1), m.group(2)) for m in re.finditer(r"\{\s*(FORM_CHANGE_\w+)\s*,\s*(SPECIES_\w+)", inner)]


def starting_species():
    found = set()
    wild = open("src/data/wild_encounters.json", encoding="utf-8").read()
    found |= set(re.findall(r'"(SPECIES_\w+)"', wild))
    found |= set(re.findall(r"\bSPECIES_\w+", re.search(r"GRASS_STARTER.*?WATER_STARTER[^\n]*", open("src/starter_choose.c").read(), re.S).group(0)))
    found -= {"SPECIES_BULBASAUR", "SPECIES_CHARMANDER", "SPECIES_SQUIRTLE"}  # the FRLG side of those lines
    command = re.compile(r"^\s*(?:%s)\s+(SPECIES_\w+)" % "|".join(SCRIPT_COMMANDS), re.M)
    for path in glob.glob("data/maps/*/scripts.inc") + glob.glob("data/scripts/*.inc") + glob.glob("data/maps/*/scripts.pory"):
        if "frlg" in path.lower() or path.endswith("debug.inc"):
            continue
        found |= set(command.findall(open(path, encoding="utf-8").read()))
    trades = open("src/data/trade.h", encoding="utf-8").read()
    found |= set(re.findall(r"\.species\s*=\s*(SPECIES_\w+)", trades))
    return found


def main():
    text = preprocess("src/pokemon.c")
    species = read_species(text)
    evolves_to = {name: evolutions_of(block) for name, block in species.items()}
    evolves_from = {}
    for name, targets in evolves_to.items():
        for target in targets:
            evolves_from.setdefault(target, set()).add(name)
    changes = {name: form_table(block, text) for name, block in species.items()}

    # Scripts use short names like SPECIES_ARCEUS for SPECIES_ARCEUS_NORMAL.
    aliases = dict(re.findall(r"(SPECIES_\w+)\s*=\s*(SPECIES_\w+)\s*,", open("include/constants/species.h", encoding="utf-8").read()))
    pool = {aliases.get(name, name) for name in starting_species()} & set(species)
    frontier = list(pool)
    while frontier:
        name = frontier.pop()
        next_up = list(evolves_to.get(name, []))
        next_up += list(evolves_from.get(name, []))
        next_up += [target for method, target in changes.get(name, []) if not BATTLE_METHOD.search(method)]
        for other in next_up:
            if other in species and other not in pool:
                pool.add(other)
                frontier.append(other)

    def keep(name):
        block = species[name]
        return name not in NEVER and not has_flag(block, "isTotem", "isMegaEvolution", "isPrimalReversion",
                                                  "isUltraBurst", "isGigantamax", "isTeraForm", "isParadox", "isUltraBeast")

    numbers = {name: int(number) for name, number in re.findall(r"(SPECIES_\w+)\s*=\s*(\d+)\s*,", open("include/constants/species.h", encoding="utf-8").read())}
    ids = sorted((name for name in species if name in pool and keep(name)), key=lambda name: numbers[name])
    lines = ["// Generated by tools/fettuccine/make_randomizer_pool.py. Don't edit by hand.",
             "// Sorted by species number, so RandomizerIsSpeciesInPool can search it.",
             "static const u16 sRandomizerPool[] =", "{"]
    lines += ["    %s," % name for name in ids]
    lines += ["};", ""]
    with open(OUTPUT, "w", encoding="utf-8") as out:
        out.write("\n".join(lines))
    print("%d of %d species in the pool" % (len(ids), len(species)))
    report = {"out": sorted(name for name in species if name not in ids)}
    json.dump(report, open(os.environ.get("POOL_REPORT", os.devnull), "w"), indent=0)


if __name__ == "__main__":
    main()
