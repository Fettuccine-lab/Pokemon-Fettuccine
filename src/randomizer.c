#include "global.h"
#include "event_data.h"
#include "move.h"
#include "pokemon.h"
#include "random.h"
#include "randomizer.h"
#include "constants/moves.h"

// The player's answer at New Game. It's kept here because New Game clears all
// flags and vars after the opening speech ends.
static EWRAM_DATA bool8 sNewGameChoice = FALSE;

#define MAX_ROLLS 256
#define STARTER_LEVEL 5

void RandomizerSetNewGameChoice(bool32 enabled)
{
    sNewGameChoice = enabled;
}

void RandomizerApplyNewGameChoice(void)
{
    if (sNewGameChoice)
    {
        u32 seed = Random32();

        FlagSet(FLAG_RANDOMIZER_ON);
        VarSet(VAR_RANDOMIZER_SEED_LOW, seed);
        VarSet(VAR_RANDOMIZER_SEED_HIGH, seed >> 16);
    }
    sNewGameChoice = FALSE;
}

bool32 RandomizerIsActive(void)
{
    return FlagGet(FLAG_RANDOMIZER_ON);
}

#include "data/randomizer_pool.h"

bool32 RandomizerIsSpeciesInPool(enum Species species)
{
    s32 low = 0, high = ARRAY_COUNT(sRandomizerPool) - 1;

    while (low <= high)
    {
        s32 middle = (low + high) / 2;

        if (sRandomizerPool[middle] == species)
            return TRUE;
        if (sRandomizerPool[middle] < species)
            low = middle + 1;
        else
            high = middle - 1;
    }
    return FALSE;
}

// The same inputs always give the same output, so a save's results never change.
static u32 Mix(u32 value)
{
    value ^= value >> 16;
    value *= 0x85EBCA6B;
    value ^= value >> 13;
    value *= 0xC2B2AE35;
    value ^= value >> 16;
    return value;
}

static u32 GetSeed(void)
{
    return VarGet(VAR_RANDOMIZER_SEED_LOW) | (VarGet(VAR_RANDOMIZER_SEED_HIGH) << 16);
}

static enum Species RollSpecies(u32 *state)
{
    *state = Mix(*state + 0x9E3779B9);
    return sRandomizerPool[*state % ARRAY_COUNT(sRandomizerPool)];
}

static u32 GetInitialState(enum Species species, enum RandomizerSource source, u32 salt)
{
    return Mix(GetSeed() ^ Mix(species ^ (source << 16)) ^ Mix(salt + 1));
}

enum Species RandomizerGetSpecies(enum Species species, enum RandomizerSource source, u32 salt)
{
    u32 state, i;

    if (!RandomizerIsActive() || species == SPECIES_NONE || species >= NUM_SPECIES)
        return species;

    state = GetInitialState(species, source, salt);
    for (i = 0; i < MAX_ROLLS; i++)
    {
        enum Species rolled = RollSpecies(&state);

        if (RandomizerIsSpeciesInPool(rolled))
            return rolled;
    }
    return species;
}

// Checks the four moves it would actually know, the last ones it learned by that level.
static bool32 KnowsDamagingMoveAtLevel(enum Species species, u32 level)
{
    const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(species);
    u16 moves[MAX_MON_MOVES] = {MOVE_NONE};
    u32 i, count = 0;

    for (i = 0; learnset[i].move != LEVEL_UP_MOVE_END && learnset[i].level <= level; i++)
        moves[count++ % MAX_MON_MOVES] = learnset[i].move;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i] != MOVE_NONE && GetMovePower(moves[i]) > 0)
            return TRUE;
    }
    return FALSE;
}

// The first battle comes right after choosing, so a starter has to be able to fight.
enum Species RandomizerGetStarter(enum Species species, u32 starterId)
{
    u32 state, i;

    if (!RandomizerIsActive())
        return species;

    state = GetInitialState(species, RANDOMIZER_STARTER, starterId);
    for (i = 0; i < MAX_ROLLS; i++)
    {
        enum Species rolled = RollSpecies(&state);

        if (RandomizerIsSpeciesInPool(rolled) && KnowsDamagingMoveAtLevel(rolled, STARTER_LEVEL))
            return rolled;
    }
    return species;
}
