# Pokémon Fettuccine Version — Design Doc

Working title. A Pokémon Emerald ROM hack built on **pokeemerald-expansion**. This file is the source of truth for what the game should be. Items marked **Decided** are final; items marked **Open** still need a decision from Joe before implementation.

## Overview

Most features below already exist in pokeemerald-expansion as built-in systems or config toggles. The main custom work is the story and character changes, the randomizer, the PC item, and possibly the party-menu move relearner.

Workflow rule: build and test after every change, and `git commit` each working step so any broken edit can be rolled back.

## Region

The game takes place in one region, **Pastalia** (Hoenn renamed; pasta + Italia). Johto and Kanto were considered and cut to keep the scope manageable.

- **Decided and done:** the region is called **PASTALIA** in all dialogue, the Pokédex ("PASTALIA DEX"), the PokéNav, the Town Map title, and the diploma.
- **Still to do (art):** two PokéNav graphics have "HOENN MAP" drawn into the pixels: `graphics/pokenav/options/hoenn_map.png` and `graphics/pokenav/left_headers/hoenn_map.png`. They need "PASTALIA MAP" (or similar) redrawn in Aseprite.
- **Still to do (art):** the Pokédex list screen draws "HOENN" from `graphics/pokedex/interface.png` (the label just above "NATIONAL", about two-thirds of the way down the sheet). It needs "PASTALIA" redrawn in the same space; it's 8 letters instead of 5, so it may need a narrower font.

## Town names

Every town gets a pasta-themed name that echoes the original. Update the location name, signs, NPC dialogue, the Town Map, and Fly destinations.

**Done.** Names appear in all dialogue, signs, popups, the Town Map, Fly map, PokéNav, and save screen. Long names automatically switch to a narrower font on the Town Map, Fly map, PokéNav map, and save screen. Town sign slogans are unchanged. Internal map names (what Porymap shows, e.g. `LittlerootTown`) keep their original names.

- **Known issue:** the map-name popup is too narrow for FETTUCCINE GRANDE CITY, so it is cut off there. Fixing it needs wider popup frame art (a later sprite task).

| Original | New name | Pasta reference |
| --- | --- | --- |
| Littleroot Town | Lil Ragu Town | Ragù sauce |
| Oldale Town | Orzodale Town | Orzo |
| Petalburg City | Pestoburg City | Pesto |
| Rustboro City | Rotiniboro City | Rotini |
| Dewford Town | Ditalinford Town | Ditalini |
| Slateport City | Spaghettiport City | Spaghetti |
| Mauville City | Macaroville City | Macaroni |
| Verdanturf Town | Cavatapurf Town | Cavatappi |
| Fallarbor Town | Farfallarbor Town | Farfalle |
| Lavaridge Town | Lasagnaridge Town | Lasagna |
| Fortree City | Fortellini City | Tortellini |
| Lilycove City | Linguicove City | Linguine |
| Mossdeep City | Mostaccideep City | Mostaccioli |
| Sootopolis City | Sugopolis City | Sugo (sauce) |
| Pacifidlog Town | Raviolog Town | Ravioli |
| Ever Grande City | Fettuccine Grande City | Fettuccine (the title) |
| Battle Frontier | Bucatini Frontier | Bucatini |
| Petalburg Woods | Pestoburg Woods | Pesto (matches Pestoburg) |
| New Mauville | New Macaroville | Macaroni (matches Macaroville) |
| Rusturf Tunnel | Rotipurf Tunnel | Rotini + Cavatapurf |

## Landmark names

**Done.** Key landmarks also get pasta names, in location names, the PokéNav, and dialogue.

| Original | New name | Pasta reference |
| --- | --- | --- |
| Mt. Chimney | Mt. Calzone | Calzone (oozing like lava) |
| Mt. Pyre | Mt. Penne | Penne |
| Meteor Falls | Meatball Falls | Meatballs |
| Cave of Origin | Cave of Oregano | Oregano |
| Sky Pillar | Sky Breadstick | Breadstick |
| Terra Cave (Groudon) | Terramisu Cave | Tiramisu |
| Marine Cave (Kyogre) | Marsala Cave | Marsala sauce (renamed from Marinara Cave to avoid clashing with Team Marinara) |
| Granite Cave | Gouda Grotto | Gouda, for Sam the cheese collector |
| Trick House | Wildcard's Castle | WILDCARD's new kingdom (see "WILDCARD and his castle") |
| Fiery Path | Peperoncino Path | Peperoncino, the Italian hot chili pepper |

- **Done: Gouda Grotto** in the location name, Town Map, Sam's Meteor Falls line, and the PokéNav call that mentions it.
- **Done: Devon Corporation is now GARLIC CORP.** Every DEVON in dialogue, signs and PokéNav calls says GARLIC; the Devon Goods and Devon Scope are the **Garlic Parts** and **Garlic Scope**; Mr. Stone's PokéNav tag is **GARLIC PRES**. A contest trainer whose personal name is Devon is unchanged. Internal map names (`RustboroCity_DevonCorp_1F`, etc.) are unchanged.
- **Done:** the Letter's bag description says it's addressed to Sam (was Steven).

## Starters

The player picks one of three starters from different generations. They replace Treecko, Torchic, and Mudkip.

| Starter | Type | Final evolution | Play style |
| --- | --- | --- | --- |
| Rowlet (Gen 7) | Grass/Flying | Decidueye (Grass/Ghost) | Steady physical attacker |
| Scorbunny (Gen 8) | Fire | Cinderace | Fast physical attacker |
| Froakie (Gen 6) | Water | Greninja (Water/Dark) | Fast special attacker |

Balance notes:

- All three final evolutions have a base stat total of 530 and evolve at similar levels.
- None of them can Mega Evolve, because the new Megas from Legends Z-A are excluded for now.
- Roxanne's Rock types are tough for Rowlet and Scorbunny; consider slightly lower levels for her team or an easy early catch with a type advantage.
- Scorbunny has the easiest time against Brian and Rowlet the hardest; tweak Brian's moves or levels based on the player's starter (Emerald already varies the rival's team by starter).

**Done.** Birch's bag offers Rowlet (left), Scorbunny (middle), and Froakie (right). The woman in the Pestoburg Pokémon Center who explains your starter's type is updated too.

- **Done:** the rival's teams no longer use Treecko, Torchic, or Mudkip (see Brian's battles).

## Shops and Pokémon Centers

### Retro Salvage Games (replaces every Poké Mart)

- **Decided:** Every Poké Mart becomes a **Retro Salvage Games** shop.
- **Decided:** **Jason** runs every shop, with different dialogue in each town. That's about 11 shops, plus he replaces one of the shopkeepers in the Lilycove Department Store and is the shopkeeper at the Pokémon League.
- **Decided:** Every customer NPC in the shops talks about how awesome Retro Salvage Games is.
- **Decided:** Jason's sprite is a recolor of an existing NPC sprite (palette edit only, no new drawing).
- **Decided:** Shop roofs are orange instead of blue. This is a palette change; check that no other buildings share that palette, or they'll turn orange too.
- The "MART" sign on the roof is part of the building's tile graphics and needs a new tile.
- **Done: dialogue (approved by Joe).** Jason greets the player with a different line in every shop (13 shops, the Pokémon League counter, and the left clerk on the Linguicove Department Store's 2F), and every shop ends with "Thanks for shopping at RETRO SALVAGE GAMES! By Collectors, For Everyone." Every shop customer praises the shop while keeping their original tip (Potions, Repels, Nest Balls…); the Sugopolis customers' crisis lines stay crisis lines. Dialogue stays general: no specific claims about the real store or Jason. Jason uses the regular clerk sprite until his recolor exists.
- **Done:** every "POKéMON MART" in the game now says RETRO SALVAGE GAMES, including the shop signs ("“Keep it retro!” RETRO SALVAGE GAMES"), the Orzodale shop worker who gives a Potion, Mom's and Nurse Joy's Potion tips, and a few townsfolk. The Orzodale worker's "look for our blue roof" was dropped; add "orange roof" when the roof recolor is done.
- The department store's other clerks, and the herb, flower and decoration shops, keep the regular shop lines.

### Cellar Dweller Collections (Spaghettiport market stall)

**Done (approved by Joe).** **Blobby** runs this stall in the Spaghettiport market, replacing the doll clerk (the dolls are still sold at the Linguicove Dept. Store 5F). In real life he runs a retro shop built from his own collection; his tagline is "From my childhood to your collection, welcome to the cellar." He uses a generic townsperson sprite (`OBJ_EVENT_GFX_MAN_5`) as a placeholder.

- **Stock:** all 21 Nature Mints (¥1,000 each, moved from the Linguicove Dept. Store 3F), Everstone, Soothe Bell, Amulet Coin, and the display pieces Strange Souvenir, Rare Bone, Comet Shard, Pearl String and Big Nugget (standard prices).

### Nurse Joy and the Jammie Dodger

- **Decided:** Talking to Nurse Joy skips the usual "Would you like me to heal your Pokémon?" exchange.
- Sequence: she says **"Here, have a Jammie Dodger!"**, the **"item obtained" fanfare** plays, the party is healed, and she says **"Seems like your Pokémon loved it!"**
- **Decided:** The healing machine animation is skipped.
- This is one shared script, so the change applies to every Pokémon Center at once.
- **Decided:** after the player blacks out and wakes up in a Pokémon Center, Nurse Joy says **"QUICK! TAKE THIS COOKIE!"**, the "item obtained" fanfare plays, the party is healed (no healing machine), and she says **"Looks like they ate it all, that was a close one..."** This replaces the usual "restore your Pokémon" and Potion-tip lines.
- Blacking out before reaching the first Pokémon Center (Mom heals you at home) is unchanged.
- **Done** (both the normal and blackout versions).

### Wonder Trade (upstairs in every Pokémon Center)

**Done.** The attendant at the **right-hand counter** upstairs (Emerald's Direct Corner, which needs a wireless adapter and can't work on emulators) now runs Wonder Trade in every Pokémon Center. The left counter (cable link) and the middle counter (Union Room) are unchanged.

- The player sends one Pokémon from the **party or the PC** and gets a **fully random** Pokémon back at the **same level**, with the normal trade animation.
- **Decided:** anything can come back except **legendaries and Ultra Beasts**; **mythicals are included**. Regional forms can appear; Megas, Gigantamax and other battle-only forms can't. Fully random means a low-level trade can return a fully evolved Pokémon.
- Eggs can't be sent. A held item goes with the Pokémon that's sent.
- It's a real trade: the received Pokémon is registered in the Pokédex and trade evolutions trigger. Traded Pokémon follow the usual badge-based obedience rules.
- **Decided:** trading partners have pasta names (PENNE, ZITI, ORZO, FUSILLI, GNOCCHI, RAVIOLI, LASAGNA, ROTINI, CAPELLI, PASTINA).
- **Done:** the trade scene shows the incoming Pokémon's own nickname and trainer (it used to show names from Emerald's in-game trade table, like "PLUSES"), and the upstairs attendant's first-visit and help text now describes all three counters, Wonder Trade included.
- Code: `src/wonder_trade.c`, `data/scripts/wonder_trade.inc`.

## Characters and sprites

- **Decided:** The player keeps the boy/girl choice.
- **Decided:** Player sprites use community Gen 3-style sprites of **Ethan** (boy) and **Kris from Crystal** (girl), from PokéCommunity or The Spriters Resource, with credit to the artists. Pick packs with full sheets: walking, running, biking, surfing, fishing, field moves, and a battle back sprite with the throw animation. Rearrange frames to match Emerald's layout if needed.
- **Decided:** No recolor; use the Ethan and Kris sprites as they are.
- **Decided:** The rival is always **Brian**, regardless of the player's gender choice. Replace the Brendan/May rival logic, name, dialogue, front battle sprite, and overworld sprite.
- Sprites are indexed PNGs with 16 colors each (one transparent).

## Brian's story

Brian is a proud Canadian who hates all Italian food. He wants to become Champion so he can rid the world of it, and he won't let the player get in his way. In a region where every town is named after pasta, he's surrounded by everything he hates.

**Decided:** Brian stays a pasta hater forever, even after he loses.

**Decided: Brian's backstory and running jokes.** His mom moved the family to Pastalia from Canada, and his Ducklett came with him. He's rude about pasta but compulsively polite as a Canadian ("Sorry in advance!"). He's **obsessed with chicken wings**, his favorite food and his main running joke; other jokes are maple syrup, poutine, renaming Rotiniboro "Mapleboro", and his mom's lasagna. His anger grows across the game: annoyed at first, then he sees the player as an obstacle (Route 110), then furious (Route 119).

**Decided:** Brian is **not** Prof. Birch's (Alan's) son. In Emerald the rival is Birch's child, so the rival's "my dad" lines get written out in the dialogue rewrite.

**Done:** the sign outside the rival's house in Lil Ragu reads **BRIAN'S HOUSE** (was PROF. ALAN'S HOUSE). **Done:** Brian's PokéNav tag is **ANTI-PASTA** (was RAD NEIGHBOR).

**Done (step 5): Brian as Champion.** Brian sits in the Champion's Room and battles with his own trainer entry (`TRAINER_BRIAN_CHAMPION`). After he loses, Prof. Birch arrives (the old rival run-in is cut), and Brian escorts the player to the Hall of Fame because "it's a rule." **Decided:** Brian is still in the Champion's seat on post-game League re-challenges, while also appearing in Prof. Birch's lab.

**Done (step 4): Brian replaces Wally.** Pestoburg Gym and Route 102: Brian asks Norman for help, uses his own Ducklett in the catching tutorial, and catches a Bidoof (no Zigzagoon loan). Macaroville: Brian waits outside the gym alone after losing to Wattson (Wally's uncle removed; Wally is never registered in the PokéNav). Victory Road: Brian shows off his Mega Ring, battles, then storms off toward the Elite Four. **Decided:** Wally's post-game Victory Road rematches are dropped. **Decided:** Wally's house in Pestoburg is now **THE CARBONARA FAMILY**, big fans of the Pestoburg Gym; the father still gives HM Surf after the player beats Norman. Wally's relatives in Cavatapurf are now just Wanda's family (Wally removed). The Wildcard's Castle quiz asks which Pokémon Brian caught on Route 102 (Bidoof). Every Brian battle now uses the rival battle music.

**Done (step 3): Brian's dialogue** in Lil Ragu (his mom and his bedroom), Prof. Birch's lab (including post-game), Route 103, Oldale, Rotiniboro and Route 104, Lasagnaridge, Route 110, Route 119, Linguicove, his 16 PokéNav calls, and his PokéNav profile (strategy: "Battle first, Wings after."). Both rival versions now share the same lines. The Champion's Room comes with the Champion step.

**Done (step 1):** the rival is named BRIAN for both genders (dialogue, PokéNav, trainer names, Fan Club), and his mom calls him her son. Both versions of the rival use Brendan's overworld, bike, battle, and PokéNav sprites as a placeholder. Both versions play Brendan's encounter music.

**Decided:** Brian fills three roles from Emerald: **the rival, Wally, and the Champion** (replacing Wallace). His appearances:

1. **Route 103 (first battle).** Introduces his hatred of Italian food and his goal of becoming Champion.
2. **Petalburg City and Route 102 (replaces Wally's catch scene).** Instead of meeting Wally, the player finds Brian demanding that Norman help him catch his second Pokémon. The scene plays out as normal, with the player helping Brian catch **Bidoof** (his future Bibarel). This is a scene, not a battle. (Changed from Snover.)
3. **Rotiniboro City.** Complains about the town's name and vows to rename it once he wins.
4. **Macaroville City (replaces Wally's battle in Mauville).** Brian just lost to the Mauville Gym and takes his anger out on the player. (It doesn't help that the city is named after macaroni.)
5. **Route 110.** Starts to see the player as a real obstacle to his plan.
6. **Route 119 / Linguicove City.** His frustration peaks; the player is the only thing standing between him and a pasta-free world.
7. **Victory Road (replaces Wally's final battle).** After losing, Brian is furious and runs ahead to the Elite Four.
8. **Champion battle.** Brian beats the Elite Four before the player arrives and becomes the new Champion. The player has to beat him one last time to become Champion.

### Mike at the Pokémon League (replaces Wallace)

- **Decided:** **Mike** (Joe's cousin) takes Wallace's place. Wallace is no longer the Champion; after Victory Road, Mike is standing outside the Elite Four entrance in Fettuccine Grande.
- Talking to him gets a line along the lines of: "That angry fellow who hates pasta just stormed through here... and he's the new Champion!" (draft wording)
- **Decided:** In the post-game, after the player becomes Champion, Mike stays in the same spot. Talking to him starts a challenge to see whether the new Champion is the real deal.
- **Decided:** Mike is outside because **Brian beat him** for the title just before the player arrives. Mike's post-game challenge is **repeatable**.
- **Done:** Mike stands in the Pokémon League lobby, right of the Elite Four door (tile 13, 3; Joe may move him in Porymap). Before the Hall of Fame he tells the player a kid from Canada beat him; after it, he offers a battle (yes/no) every time he's talked to, using his trainer data (`TRAINER_WALLACE`, levels 57–60).
- **Decided:** Mike replaces Wallace **everywhere** (Sugopolis and HM Waterfall, Cave of Origin, Sky Pillar, Mostaccideep, the Champion's Room until Brian takes it over, and every line that mentions him). **Done:** all dialogue and his trainer name say MIKE. Wallace's sprites are his placeholder.
- **Decided:** Mike's ace is an **overpowered Spearow**, a unique Spearow form only he has (`SPECIES_SPEAROW_MIKE`). Wild Spearow are unaffected. Both Mike and his Spearow get custom sprite work by Joe. **Done:** the form exists with boosted stats (80 HP / 145 Atk / 90 Def / 55 SpA / 90 SpD / 140 Spe, 600 total, vs. 262 for Spearow), using Spearow's sprites as a placeholder. Moves: Brave Bird, Double-Edge, Drill Run, U-turn, with a Life Orb.
- **Decided: Mike's personality** is an over-the-top Italian stereotype mixed with the Fonz ("Ayyy!", "Correctamundo!", "Capisce?"). He's confident but not overconfident: he knows he's strong and doesn't rub it in. Above all he's a proud Pastalian with a deep love for every pasta and sauce, so he won't take a side between red and white sauce. He keeps Wallace's backstory (former Sugopolis Gym Leader, Juan's student). **Done:** all his lines in Sugopolis, the Cave of Oregano, the Sky Breadstick, the Champion's Room, the Hall of Fame, and his PokéNav call and profile. (The Champion's Room and Hall of Fame lines have since moved to Brian.)
- **Decided: Mike's team is hyper-Italian,** with a Mega (Gallade). (The earlier three-Gen-1 rule was dropped when Falinks replaced Snorlax.) **Done** (levels 57–60, Spearow last):

| Pokémon | Gen | Type | Italian theme |
| --- | --- | --- | --- |
| Smeargle | 2 | Normal | Renaissance painter (leads with Spore and Sticky Web) |
| Chandelure | 5 | Ghost/Fire | Murano glass chandelier |
| Kingambit | 9 | Dark/Steel | Julius Caesar, commanding the Falinks legion |
| Falinks | 8 | Fighting | A Roman legion marching in shield formation |
| Gallade (Mega) | 4 | Psychic/Fighting | Roman gladiator; holds a Galladite and Mega Evolves |
| Spearow (Mike's form, ace) | 1 | Normal/Flying | Mike's overpowered ace |

### Notes on merging the roles

- Brian battles the player seven times; his team has to grow consistently across all of them, with his full team at its highest levels for the Champion battle.
- Wally's scenes need new reasons for Brian to be there. Mauville is decided (he lost to the gym). **Decided:** Verdanturf is dropped; Brian doesn't appear there, and Wally's relatives' house becomes an ordinary NPC house.
- Confirm that the rival and Wally never appear in the same scene by searching the scripts.
- The Champion's trainer data, room, and dialogue all switch to Brian.

### Brian's team (Champion battle)

**Decided:** Canadian-themed, with Swanna as his ace and a Mega Abomasnow, as balanced as possible while keeping the theme: seven different types, and no single attacking type hits more than three of his Pokémon super-effectively. Brian has no starter.

| Pokémon | Type | Canadian link |
| --- | --- | --- |
| Bibarel | Normal/Water | Beaver, Canada's national animal |
| Abomasnow (Mega) | Grass/Ice | Sasquatch of the snowy forests |
| Swanna | Water/Flying | Stand-in for the Canada goose; his ace |
| Wyrdeer | Normal/Psychic | The closest thing to a moose |
| Sawsbuck (Autumn form) | Normal/Grass | Maple-leaf colors, a nod to maple syrup |
| Alolan Ninetales | Ice/Fairy | Arctic fox; its Aurora Veil move is the northern lights |

- **Swanna is his ace,** saved for last, and its shiny Canada goose colors are the big reveal. Give it an ace build (highest level, perfect IVs, a good item and strong moveset); its stats are modest for an ace. **Decided:** no stat buff; it's an ace through level, perfect IVs and its item.
- **Swanna is also his day-one partner.** Players never see the rival pick a starter, so Ducklett is his first Pokémon and the one he uses in the Route 103 battle. Bidoof (caught on Route 102) is his second; Snover joins by Route 110.
- **Abomasnow Mega Evolves** in later battles, so Brian needs a Mega Ring in the story (story flavor only: trainers Mega Evolve without one).
- **Lock Sawsbuck to its Autumn form** in his trainer data.
- **Decided: Brian's Swanna is recolored as a Canada goose:** black head and neck, a white chinstrap patch, a gray-brown body, a pale chest, and a black beak and tail. Same approach as Sam's Metagross: Brian's Swanna is shiny in his trainer data, and Swanna's shiny palette gets the goose colors, so any shiny Swanna the player finds is a Canada goose too. Because the white chinstrap and black neck may share a color with the rest of the body, the sprite probably needs a few pixel edits in Aseprite as well as the palette change. Brian's Ducklett stays normal-colored in earlier battles, so the goose colors are a surprise when it evolves.
- **Watch out for Fire.** Abomasnow, Sawsbuck, and Ninetales are all weak to it. Bibarel and Swanna can switch in against Fire types; give the others coverage moves.
- Earlier battles use pre-evolved forms (Ducklett, Snover, Bidoof, Stantler, Deerling, Alolan Vulpix) as the team grows.

#### Brian's battles (Decided)

Eight battles, in play order (the Linguicove battle stays optional, as in Emerald). Levels are for a Froakie player; against **Rowlet** (his hardest matchup) Brian is 1 level lower from Rotiniboro on and his Snover has no Ice move until Route 119, then only Icy Wind; against **Scorbunny** (his easiest) he's 1 level higher and Ducklett/Bibarel lead with Water moves. Macaroville, Victory Road and the Champion battle are the same for every starter.

| # | Battle | Team (ace last) | IVs | Status |
| --- | --- | --- | --- | --- |
| 1 | Route 103 | Ducklett 5 | 0 | Done |
| 2 | Rotiniboro | Bidoof 13, Ducklett 15 | 6 | Done |
| 3 | Route 110 | Snover 17, Bibarel 19, Ducklett 21 | 9 | Done |
| 4 | Macaroville | Snover 19, Stantler 20, Bibarel 21, Ducklett 22 | 12 | Done |
| 5 | Route 119 | Deerling 28, Stantler 29, Bibarel 29, Snover 30, Ducklett 31 | 15 | Done |
| 6 | Linguicove (optional) | Bibarel 32, Stantler 32, Deerling 32, Snover 33, Swanna 35 (shiny; 35 for every starter) | 18 | Done |
| 7 | Victory Road | Alolan Ninetales 44, Wyrdeer 44, Bibarel 44, Sawsbuck 45, Mega Abomasnow 46, Swanna 47 | 24 | Done |
| 8 | Champion | Alolan Ninetales 55, Wyrdeer 56, Bibarel 55, Sawsbuck 56, Mega Abomasnow 57, Swanna 58 | 31 | Done |

Deerling and Sawsbuck are Autumn form. Champion sets: Ninetales (Light Clay, Snow Warning) Aurora Veil, Freeze-Dry, Dazzling Gleam, Nasty Plot; Wyrdeer (Sitrus Berry, Intimidate) Psyshield Bash, Double-Edge, Earthquake, Thunder Wave; Bibarel (Sitrus Berry, Simple) Swords Dance, Waterfall, Crunch, Aqua Jet; Sawsbuck (Lum Berry, Sap Sipper) Horn Leech, Double-Edge, Megahorn, Swords Dance; Abomasnow (Abomasite, Snow Warning) Blizzard, Wood Hammer, Earthquake, Ice Shard; Swanna (Life Orb) Hurricane, Surf, Ice Beam, Roost. Victory Road uses the same idea at lower levels (Abomasnow: Ice Beam instead of Blizzard; Swanna: Brave Bird instead of Hurricane).

### Brian's bedroom: SNES and Time Toggle

- **Decided:** the GameCube in Brian's bedroom (the rival's house, second floor, in Lil Ragu) is described as a Super Nintendo with a copy of *Time Toggle* in it. Text only: no minigame, no new code, no sprite change.
- New text: "It's a Super Nintendo. Brian's copy of Time Toggle is in it... a mediocre RPG that certain people won't stop calling the greatest game ever made." Break it to fit the text box with `\n` and `\p`.
- Change only the rival's-room GameCube. The player's bedroom GameCube has its own secret (see "Secret minigame: Pocket Knight Adventures").
- The boy and girl houses swap roles depending on the player's gender, so check whether they share a script and apply the change wherever Brian's room is used.
- **Done:** both houses share one GameCube script, so each house now checks the player's gender and shows the Super Nintendo text only in Brian's room.

## Villain teams: White Sauce vs. Red Sauce

Decided: Team Aqua and Team Magma become two rival sauce fanatics, each convinced theirs is the one true sauce. (This replaced the earlier "sauce vs. boil" theme, Team Marinara vs. Team Al Dente.)

**Team Alfredo** (replaces Team Aqua). Obsessed with white sauce: Alfredo and sauces like it. Wants to wake Kyogre and flood the world with their ideal sauce.
**Team Marinara** (replaces Team Magma). Passionate about red sauce: marinara and sauces like it. Wants to wake Groudon so the world's volcanoes spray red sauce everywhere.

What this touches:

Team names in all dialogue, signs, and trainer classes (for example, "Team Alfredo Grunt").
Recolored grunt and admin sprites to match each team.
Story dialogue for both leaders and their admins.

Status:

- **Done:** team names in all dialogue and signs; trainer classes TEAM ALFREDO, ALFREDO ADMIN, ALFREDO LEADER, TEAM MARINARA, MARINARA ADMIN, MARINARA LEADER; hideouts renamed ALFREDO HIDEOUT and MARINARA HIDEOUT; the Magma Emblem key item is now the Marinara Emblem. Admin names (Shelly, Matt, Tabitha, Courtney) are unchanged.
- **Done:** leaders renamed. Archie is now **PARMIGIANO** (Parmesan, the cheese in Alfredo) and Maxie is now **MARZANO** (San Marzano, the marinara tomato). These replace the earlier names Marzano (Archie) and Bollito (Maxie).
- **Done:** white-vs-red dialogue for every villain scene: the Oceanic Museum, Meatball Falls, Mt. Calzone (including the Route 112 cable car guards), the Weather Institute (including the Route 119 bridge lookouts), the Mt. Penne summit (orb theft and the old couple's legends), and both hideouts (including the Team Alfredo lines around Linguicove), the Mostaccideep Space Center, the Seafloor Cavern (and the Route 128 scene right after), plus the grunts' jokes there. Kyogre's downpour is a downpour of Alfredo sauce. The Pokédex entries for Groudon, Kyogre, their Primal forms, and Rayquaza also tell the sauce legend. Sugopolis is done too: the townspeople describe the clash as a sauce legend, and one calls Kyogre "the white one" (this relies on the cream Kyogre recolor). The leaders' lines in Sugopolis, Wallace's lines, and the orb return at Mt. Penne didn't need changes. All villain story scenes are now on the white-vs-red plot; Joe may revise any of these lines later.
- **Not started:** recolored sprites (art). Team Marinara can keep Team Magma's red outfits. Team Alfredo's grunt, admin, and leader sprites need a white or cream recolor instead of blue.
- **Not started: Kyogre recolored cream instead of blue** (art). Covers its battle sprites and overworld sprites (the asleep, front, and side views used in the Seafloor Cavern and Sugopolis scenes). Check which palettes are shared before changing them.
- **Decided:** dialogue tone is mostly serious for leaders and admins (sincere villains whose worldview is built on sauce), with the jokes and puns going to the grunts.
- **Decided: keep Team Alfredo's dialogue free of innuendo.** White sauce is easy to read as a sexual joke, so lean on butter, cheese, Parmesan, and "Alfredo sauce" rather than "cream". Avoid pairing white sauce or cream with words like squirt, spray, shoot, load, slurp, swallow, thick, sticky, or "all over", and with bodies or faces. Team Marinara's red sauce can erupt and spray; Team Alfredo's sauce floods and covers.
- **Decided:** rewrite key scenes first, starting with the leader introductions, then the other scenes one at a time.

**Decided:** Brian does not show up during the teams' schemes. (Considered: both teams want more pasta while Brian wants it gone, so he could have appeared furious, on the player's side. Dropped.)

## Retrotopia cast

| Person | Replaces | Role in the game |
| --- | --- | --- |
| Alan | Professor Birch | Gives the player their starter and introduces the world |
| Sam | Steven Stone | Kind mentor, gives the player the Mega Ring, secret post-game boss |
| Joe Fettuccine | Game designer (Cove Lily Motel, Linguicove) | Awards the diploma for completing the Pokédex |
| WILDCARD (Joe's former persona) | Trick Master | Runs Wildcard's Castle (the Trick House) |
| Brian | The rival, Wally, and Wallace (Champion) | See Brian's story |
| Jason | Every shopkeeper | Runs every Retro Salvage Games shop |
| Joe Q | Scott | Talent scout who keeps turning up to watch the player battle, then invites them to the Bucatini Frontier |

**Decided:** Alan, Sam, and Joe Fettuccine all get custom sprites (overworld; Sam also needs a battle sprite; Alan also needs the large Birch portrait from the opening scene).

### Alan as Birch

- The lovable British gentleman of Retrotopia, and the first character players meet.
- Loves Italian food, which makes him a natural foil for Brian.
- **Decided:** His love of whiskey is a running joke in his dialogue.
- The Jammie Dodgers at the Pokémon Centers can come from Alan's own stash.
- **Done: post-game lab scene rewritten.** The Pokédex is National from the start, so after the Hall of Fame Alan no longer "upgrades" it. He asks how the player's Pokédex is coming along, says Pokémon from every corner of the world live in Pastalia ("Like a good bolognese!"), and backs up the player's Pokédex data on his PC. Brian: "Regions with NO pasta! If you find out where they're from, tell me first. I'm moving there." Alan's send-off points the player to the post-game: fill every PASTALIA entry for "a little something" (now Treecko, Torchic and Mudkip instead of the Johto starters) and show the game designer at the Cove Lily Motel. The scene still switches on the National Dex silently, which fixes saves from before the National Dex change.

- **Done: wall-to-wall bookcases.** Six bookcases line the lab's back wall in both layouts, replacing the back PC desk and book desks. The row in front stays walkable.
- **Done: secret boss battle (approved by Joe).** After the player chooses their Treecko, Torchic or Mudkip, Alan offers a battle, and offers it again whenever he's talked to; saying no there leads into the usual Pokédex rating. Repeatable, no prize. Trainer `TRAINER_PROF_ALAN`, class PKMN PROF., Champion battle music, 4 Full Restores. He uses the Gentleman battle sprite as a placeholder, so **he needs a custom battle sprite too**. Brian chimes in that he's "rooting for whoever hates pasta."

| Pokémon | Lv | Item | Ability | Moves |
| --- | --- | --- | --- | --- |
| Stoutland | 80 | Sitrus Berry | Intimidate | Facade, Crunch, Play Rough, Thunder Wave |
| Sirfetch'd | 80 | Leek | Scrappy | Close Combat, Brave Bird, Leaf Blade, Knock Off |
| Decidueye | 81 | Leftovers | Long Reach | Spirit Shackle, Leaf Blade, Swords Dance, Roost |
| Greninja | 81 | Focus Sash | Protean | Surf, Dark Pulse, Ice Beam, Water Shuriken |
| Cinderace | 81 | Life Orb | Libero | Pyro Ball, High Jump Kick, U-turn, Sucker Punch |
| Polteageist (ace) | 82 | White Herb | Weak Armor | Shell Smash, Shadow Ball, Giga Drain, Strength Sap |

### Sam as Steven

- The heart of Retrotopia: kind and always looking out for the player.
- Instead of rare stones, Sam collects rare Wisconsin cheeses.
- **Decided:** Sam gives the player the **Mega Ring and the Mega Stone Case in Gouda Grotto** when they first meet him (see Mega Evolution). This replaced the earlier plan to spread Mega Stones across the game.
- Steven's post-game battle at Meteor Falls becomes Sam's.

#### Sam's team (post-game battle)

Every Pokémon is from Gens 1–3 and has a cheese connection.

| Pokémon | Gen | Type | Cheese link |
| --- | --- | --- | --- |
| Metagross (shiny, Mega, ace) | 3 | Steel/Psychic | The Big Cheese, recolored cheddar yellow |
| Miltank | 2 | Normal | Dairy cow, for Wisconsin, "America's Dairyland" |
| Tauros | 1 | Normal | Dairy bull, Miltank's partner on the farm |
| Raichu | 1 | Electric | A mouse, and mice love cheese |
| Ampharos | 2 | Electric | A yellow sheep, for sheep's-milk cheeses like feta |
| Lunatone | 3 | Rock/Psychic | Yellow crescent moon shaped like a cheese wedge; the moon is made of cheese |

- **Decided: shiny cheddar Metagross.** Sam's Metagross is shiny in his trainer data, and Metagross's shiny palette is recolored cheddar yellow (Mega Metagross's shiny palette too). Any shiny Metagross the player finds will also be yellow.
- **Balance:** Ground is the biggest weakness, hitting Metagross, Raichu, and Ampharos (Lunatone is immune thanks to Levitate). Give the team coverage moves for Ground types, such as Grass Knot on Raichu, Ice Punch on Metagross, and Earthquake on Tauros.
- As a post-game boss, the whole team should have high levels, good items, and strong movesets.

### Joe Fettuccine as the game designer

- Replaces the Game Freak developer cameo in the Cove Lily Motel.
- Awards the diploma for completing the Pokédex. The diploma checks the **PASTALIA (regional) Dex**, not the full National Dex.
- **Done: dialogue (approved by Joe).** He introduces himself by name, jokes that his cousin told him to stop spending money on Pokémon games ("So I made my own!"), and denies ever meeting WILDCARD. The diploma is signed JOE FETTUCCINE. The motel owner says the big group booked in under FETTUCCINE instead of GAME FREAK.

### WILDCARD and his castle (replaces the Trick Master and Trick House)

**Who he is:** WILDCARD is Joe's known former persona. In another Discord server, Joe hosted a weekly **Mario Kart Night** that grew a small following and turned into a group goofing off. Joe and Brian started a sarcastic rivalry, openly taking jabs at each other, and that's where their friendship grew. Joe became the **Mario Kart King**, went mad with power, watched his "kingdom" crash and burn, and then started **RetroBytes** with Brian. The group made their own game modes, **Blue Shell Hell** and **Bullets Over Bombsway**, and a short fake-news video series, the **Mario Kart Weekly ReKap**, recapping each night's shenanigans.

**Done:**

- The Trick House is **WILDCARD'S CASTLE** everywhere: dialogue, the Route 110 sign, and the Town Map landmark. His "tricks" are still called tricks. Internal map names (`Route110_TrickHouse…`) are unchanged.
- Every TRICK MASTER is now **WILDCARD**, including the secret door codes ("WILDCARD is huggable.").
- **Sprite:** WILDCARD and the room-5 Mechadolls use Joe Fettuccine's placeholder sprite (`OBJ_EVENT_GFX_MAN_3`). When Joe Fettuccine's custom sprite is made, switch WILDCARD over too if it's a new graphics ID.
- **Dialogue:** introduces himself as the "Former KART KING of MARIO KART NIGHT! Banned from servers far and wide!"; says his old kingdom crashed and burned but this one will stand forever; teases rooms as cruel as BLUE SHELL HELL and as explosive as BULLETS OVER BOMBSWAY; jokes that not even a blue shell could get you through; needs "a pit stop"; is humbled like no one since "that pasta-hating BRIAN"; brags that he invented BLUE SHELL HELL (and was there for BULLETS OVER BOMBSWAY) when his ideas run dry; signs off with "Tune in next time for the CASTLE WEEKLY REKAP!"; and in his farewell jokes about starting a podcast "With BRIAN, of all people! As if!" and denies being "some game designer at a motel in LINGUICOVE."
- **Done: the Mechadoll quiz.** All 15 questions are about Mario Kart Night, the ReKap, RetroBytes Neo and the Retrotopia crew (one still asks which Pokémon Brian caught on Route 102).
- **Trainers gossip:** Robin (room 1) heard he used to be a KING; Paul (room 2) says rigging tricks is easier than surviving BLUE SHELL HELL; Joshua (room 7) heard he vanished when his old kingdom fell; Leroy (room 8) isn't sure if he'll be pleased or furious.

### Joe Q as Scott

**Decided:** Joe Q, Joe's older cousin and a guest on the RetroBytes Neo nostalgia episode (July 2026), replaces Scott.

- **Decided:** Joe Q is a different person from Joe Fettuccine (the game designer). His in-game name is "Joe Q" so he isn't confused with Joe.
- **Decided:** Joe Q keeps Scott's sprite.
- **Done:** every SCOTT in dialogue and the PokéNav now says JOE Q (the Battle Frontier guide calls him "MR. Q").

**Who he is:**

- **"Big Joe."** Joe's older cousin. Because of him, Joe was called "Little Joe" well into his 20s. He jokes that he was kind of a big deal in Downriver, Michigan.
- **Radio and podcast veteran.** He did internet radio before podcasting had a name and has thousands of hours of shows behind him, including a World of Warcraft radio show and a podcast called *Just Cool Enough* (about 500 episodes). He also covered the video game industry.
- **Now:** almost 40, works a corporate job, has two kids, and supports Retrotopia on the lowest Patreon tier ("the bare minimum").
- **Gaming roots:** a hand-me-down NES with Duck Hunt and Super Mario Bros., shareware on an IBM 386, The Sims, and Age of Empires (he loved it but was never good at it). He'd buy a PlayStation just to play Heli Attack 2 again.
- **Personality:** warm, self-deprecating, and passionate. He hates corporate cash grabs, believes in voting with your wallet, and grieves what's happened to Star Wars.

**Running jokes for his dialogue:**

- **"Just Cool Enough."** Scott's job is scouting talent, so Joe Q scouts trainers who are "just cool enough." When he invites the player to the Bucatini Frontier, it's the highest compliment he gives.
- **The Pokémon intervention.** On the episode, he told Joe, as his bigger cousin, to stop spending money on Pokémon games. In-game, he can warn the player not to waste money, even at Retro Salvage Games.
- **Kid mode.** He played Spider-Man on kid mode with the door shut so nobody would know. He can admit to secretly playing on easy.
- **Kind of a big deal.** He introduces himself as someone everyone around here has heard of.
- **Old radio host.** He talks like he's still on the air.

**Scene notes:**

- Keep all of Scott's existing appearances and their place in the story. Rewrite only his name and dialogue.
- His final scene is the post-game invitation to the Bucatini Frontier, where he declares the player "just cool enough."
- Starting point: search `data/maps/` for every line Scott speaks and list each one with its map and story order before rewriting.

**Done:** new dialogue (approved by Joe) in all 13 Scott scenes and PokéNav calls 1, 4, 5 and 7 (calls 2, 3 and 6 are unchanged). His PokéNav profile tag is **BIG JOE**. The Macaroville and Route 119 lines refer to the pasta-hating rival, and call 1 mentions Retro Salvage Games, so both will fully make sense once the Brian and shop features are done.

### Retrotopia promo office (Ditalinford Hall)

**Done.** Dewford Hall's trendy-phrase gimmick is gone. The sign reads **RETROTOPIA PROMO OFFICE / "Tune in, retro fans!"** The same NPCs are there, but all their dialogue is promotional talk about how great Retrotopia is (kept general, with no invented facts about the real show). The painting is a Retrotopia poster, the bookshelf holds an episode guide and old game magazines, the two debaters pick one of five chats at random, and the man who gives TM Sludge Bomb still does ("take this while you catch up").

## Joe's cousins

| Person | Replaces | Role in the game |
| --- | --- | --- |
| Mike | Wallace | Waits outside the Elite Four; post-game challenge with an overpowered Spearow ace (see "Mike at the Pokémon League") |
| Joe Q | Scott | Talent scout and Bucatini Frontier recruiter (see "Joe Q as Scott" under Retrotopia cast) |

- **Decided:** Mike and his Spearow get custom sprites (placeholder for now).

## Trainer and Gym Leader teams

- **Decided:** every trainer and Gym Leader gets a different team from base Emerald, drawn from Pokémon of Gens 1–9. Each keeps their current theme (for example, a Bug Catcher still uses Bug types and a Gym Leader keeps their gym's type).
- **Decided:** this is a fixed set of new teams that every player gets. It is separate from the optional randomizer at New Game.
- **Decided:** from the 3rd gym on, each Gym Leader has a Mega-Evolving Pokémon.
- **Done: new teams for every ordinary trainer** (765 trainers, about 1,500 Pokémon), generated by a one-time script and then spot-checked. The rules:
  - Each Pokémon is replaced by one that shares its main type, so class themes hold (Bug Catchers keep Bug types, Fishermen keep Water types, and so on).
  - Replacements fit the level (sensible evolution stage) and have similar strength (86% within 10% of the original's base stat total).
  - Pool: Gens 1–9 plus regional forms. No legendaries, mythicals, Ultra Beasts, Paradox Pokémon, or Megas. No Pokémon is repeated on a team, and no trainer uses a Pokémon line from their own Emerald team (including rematches).
  - Rematches and repeat villain battles reuse the same new Pokémon, evolving as levels rise.
  - Moves are automatic (the latest level-up moves) for ordinary trainers. Custom movesets and abilities were dropped; held items kept.
  - Elite Four keep their specialty: Sidney Dark (Sableye, Weavile, Bombirdier, Houndoom, Overqwil), Phoebe Ghost (Drifblim, Houndstone, Golurk, Gourgeist, Trevenant), Glacia Ice (Beartic, Lapras, Cryogonal, Arctozolt, Hisuian Avalugg), Drake Dragon (Arctibax, Druddigon, Noivern, Dracovish, Dragonite).
  - **Sauce grunts:** Team Marinara uses red-bodied Pokémon; Team Alfredo uses white- or cream-bodied Pokémon.
  - Villain bosses and admins keep their aces (Camerupt and Sharpedo lines, and Matt's Golbat); the rest of their teams follow the sauce colors.
  - Not changed: Brian, Sam, Mike, Wally's battles (Brian's), and the Frontier Brains.
- **Done: hand-built movesets for every Gym Leader battle (including rematches) and the Elite Four.** Strategic roles (setup, support, speed control, coverage), only moves the Pokémon can learn in this game by that level, and each Gym Leader's ace uses the gym's TM. Rematches are double battles, so those sets use spread moves, Fake Out, Tailwind, and Protect.
- **Done: hand-picked Gym Leader teams.** No Pokémon from their Emerald teams (including rematches); same team sizes and levels. Rematches keep the same lineup, evolved, with one or two additions.

| Leader | Type | First battle (ace last) | Rematch additions |
| --- | --- | --- | --- |
| Roxanne | Rock | Rolycoly, Nacli, Tyrunt | **Mega Aerodactyl** (rematches only), Lycanroc, Tyranitar |
| Brawly | Fighting | Timburr, Mienfoo, Crabrawler | **Mega Heracross** (rematches only), Pangoro, Annihilape |
| Wattson | Electric | Joltik, Helioptile, Dedenne, **Mega Manectric** | Pawmot, Vikavolt, Kilowattrel |
| Flannery | Fire | Litleo, Salandit, Torracat, **Mega Houndoom** | Centiskorch, Armarouge |
| Norman | Normal | Oinkologne, Furret, Ambipom, **Mega Kangaskhan** | Bewear, Ursaluna, Snorlax |
| Winona | Flying | Hawlucha, Corvisquire, Toucannon, Cramorant, **Mega Altaria** | Staraptor |
| Tate & Liza | Psychic | Gothitelle, Reuniclus, Espeon, **Mega Alakazam** | Bronzong, Hatterene |
| Juan | Water | Primarina, Lanturn, Golisopod, Barraskewda, **Mega Gyarados** | Dondozo |
- **Decided:** trainers' names are replaced with names from the Retrotopia community. Joe will supply the list; build this near the end.

## Pokémon, moves, items and abilities

All built into pokeemerald-expansion; the work is deciding where things appear.

- **All Pokémon through Gen IX.** **Decided:** every Gen 3 Pokémon stays where it is in Emerald.
  - **Decided:** every non-legendary Pokémon is catchable (not a curated set); **no time-of-day encounters** (changed Oct 2026; every Pokémon in an area appears at all hours); some legendaries become one-off encounters (see "Legendary one-off encounters"); the Pokédex keeps the **National Dex order**.
  - **Done: the Pokédex is the National Dex from the moment Alan gives it** (in Emerald it unlocked after the Hall of Fame). See Alan's post-game scene for the follow-up.
  - **Done (Oct 2026): encounters don't depend on the time of day.** Each area's four time tables were merged into one. **Decided:** no wild Pokémon is rarer than 4%; common ones can be higher. Grass, surfing, Rock Smash and the Super Rod have 25 slots at 4% each, the Old Rod 10 slots at 10% and the Good Rod 20 slots at 5%, so a Pokémon's chance is how many slots it fills (edit rates in Porymap by adding or removing copies). Rates came from each Pokémon's average over the four times, reviewed by Joe; he hand-set the surfing, fishing and Rock Smash tables on Routes 102–104, 111, 114, 117, 118 and 120. The build fails on purpose if the slot percentages stop being even. Lures no longer favor rare slots (there are none) but still raise levels.
  - **Done:** the first stage of 21 lines that were only placed evolved (Litten, Popplio, Sprigatito, Chimchar and others) now appears in an early area.
  - **Done: Feebas evolves into Milotic at Lv 35;** the Prism Scale still works.
  - **Done (original placement):** wild placement by a one-time script, `tools/fettuccine/place_wild_pokemon.py`. Each Emerald area had four time-of-day tables (merged since). Every Emerald Pokémon keeps its best slot in every table; 315 missing Pokémon lines fill duplicate slots, each in three different areas, matched by type to the area and by level (stronger Pokémon only appear at higher levels, and they're placed already evolved where the level allows). Ghost and Dark types lean toward night, Grass/Bug/Fire toward day. Starters and pseudo-legendary lines only get rare slots (5% or less). At most 3 new Pokémon per area and time (2 on the first routes), 1 per surfing, Rock Smash or fishing-rod table. The full list by area is in `docs/wild_pokemon_placements.md`.
  - **Done: regional evolutions.** The 13 regional forms that only evolve "in" their home region now evolve in a Hoenn spot standing in for that region. Level-up evolutions happen on a route (players level up by battling); item evolutions happen in the neighboring town. Evolving anywhere else gives the normal form.
    - **Alola:** level up on Route 106 (Alolan Marowak, Lv 28 at night); use a stone in Ditalinford Town (Alolan Raichu, Alolan Exeggutor).
    - **Galar:** level up on Route 117 (Galarian Weezing; Galarian Mr. Mime from Mime Jr. knowing Mimic, which then evolves into Mr. Rime as normal).
    - **Hisui:** level up on Route 119 (Hisuian Typhlosion, Samurott, Decidueye, Braviary, Sliggoo, Avalugg; Hisuian Goodra still needs rain or fog anywhere); use an item in Fortellini City (Hisuian Lilligant with a Sun Stone; Ursaluna with a Peat Block at night).
    - Hisuian Decidueye evolves at Lv 34 (was 36) so it doesn't overlap with regular Decidueye.
    - **Prof. Birch (Alan) calls** on the player's first visit to Macaroville to explain all three spots (it used to wait for the third badge).
- **Every item, ability, and move effect through Gen IX.** Still to plan: where items are found or sold, and which TMs exist.
  - **Done: TMs are reusable** (`I_REUSABLE_TMS`).
  - **Done: TM51–TM100 (approved by Joe, Oct 2026).** 50 Gen 4–9 moves sold at Retro Salvage Games along the main path; stronger moves come later and cost more. Which Pokémon can learn each TM is generated automatically from the official games (TM or tutor), so no per-Pokémon edits. Rotiniboro ¥1,500: Bulldoze, Thunder Wave. Spaghettiport ¥1,500: Icy Wind, Acrobatics, Draining Kiss. Macaroville ¥3,000: Thunder/Fire/Ice Punch, Wild Charge. Cavatapurf: Seed Bomb, Hex, Swords Dance. Farfallarbor: Rock Slide, Poison Jab, Shadow Claw. Lasagnaridge: Heat Wave, Will-O-Wisp, Zen Headbutt. Pestoburg: Crunch, Drain Punch, Knock Off, Substitute. Fortellini: U-turn, Air Slash, Brave Bird, Roost. Linguicove Dept. Store 2F, Jason's counter, ¥5,000: X-Scissor, Bug Buzz, Dark Pulse, Nasty Plot, Dragon Pulse, Play Rough, Dazzling Gleam, Energy Ball, Earth Power, Psyshock, Trick Room, Stealth Rock, Iron Head, Flash Cannon, Scald, Liquidation. Mostaccideep ¥7,500: Volt Switch, Focus Blast, Stone Edge. Sugopolis ¥7,500: Hydro Pump, Outrage, Dragon Dance. Pokémon League ¥10,000: Close Combat, Flare Blitz. TM01–50 and the Gym Leader TM rewards are unchanged.
  - **Done: newer held items (approved by Joe, Oct 2026).** 59 held items are sold at Retro Salvage Games, placed by theme: Rotiniboro Rock Incense; Spaghettiport Wave Incense, Fairy Feather; Macaroville Muscle Band, Wise Glasses, Terrain Extender; Cavatapurf Rose Incense, Big Root, Destiny Knot; Farfallarbor Smooth Rock, Safety Goggles; Lasagnaridge Heat Rock, Flame Orb, Toxic Orb; Pestoburg Lucky Egg, the six Power items, Punching Glove; Fortellini Damp Rock, Float Stone, Air Balloon, Utility Umbrella; Mostaccideep Scope Lens, Zoom Lens, Odd Incense, Icy Rock. The competitive items (Choice items, Life Orb, Focus Sash, Assault Vest, Eviolite, Rocky Helmet, Weakness Policy, Heavy-Duty Boots and 21 more) are at the Linguicove Dept. Store 3F X-item counter. Official prices, except the Choice Band, Specs and Scarf at ¥50,000 (half). **Decided:** no Booster Energy (no Paradox Pokémon in the game) and no Berserk Gene.
  - **Done: training items (approved by Joe, Oct 2026).** Spaghettiport harbor market, Energy Guru's stall (next to his vitamins): the six Feathers, Exp. Candy XS and S. Linguicove Dept. Store 3F vitamin counter: the six stat Mochi and Fresh-Start Mochi, Exp. Candy M and L, Ability Capsule. Pokémon League shop: Exp. Candy XL, Ability Patch. Official prices, except Ability Capsule ¥50,000 and Ability Patch ¥125,000 (half). **Decided:** the harbor market stays its own set of stalls, not Retro Salvage Games. **Decided:** no Bottle Caps (they'd need a Hyper Training NPC; the engine has the script commands if that's wanted later).
  - **Done: newer Poké Balls (approved by Joe, Oct 2026).** Orzodale Friend Ball (after the shop gets Poké Balls in); Rotiniboro Heal Ball; Spaghettiport Lure Ball; Macaroville Fast Ball, Quick Ball; Farfallarbor Moon Ball, Dusk Ball; Lasagnaridge Heavy Ball; Pestoburg Level Ball; Fortellini Sport Ball; Mostaccideep Dream Ball; Linguicove Dept. Store 2F (Jason) Love Ball. Apricorn balls and the Sport Ball cost ¥300 and the Dream Ball ¥1,000 (none have an official price). **Decided:** no Beast Ball (no Ultra Beasts), Safari Ball (handed out in the Safari Zone), Park Ball (no effect in this engine), Cherish or Strange Ball.
  - **Done: newer berries (approved by Joe, Oct 2026).** A florist behind the Pretty Petal Flower Shop counter (Route 104) sells the 18 type-resist berries (Chilan, Occa, Passho, Wacan, Rindo, Yache, Chople, Kebia, Shuca, Coba, Payapa, Tanga, Charti, Kasib, Haban, Colbur, Babiri, Roseli). The Berry Master's apprentice in his house (Route 123) sells the 11 battle berries (Ganlon, Salac, Petaya, Apicot, Micle, Custap, Jaboca, Rowap, Kee, Maranga, Enigma). All ¥80 (official price). Every berry can be planted to grow more.
  - **Done: form items (approved by Joe, Oct 2026).** Macaroville Retro Salvage Games: Rotom Catalog (¥5,000). Pretty Petal florist (Route 104): Gracidea (¥1,000), Yellow, Pink and Purple Nectar (¥300) for Shaymin and Oricorio (which lives in the Marinara Hideout). Bucatini Frontier Retro Salvage Games (post-game, with the legendaries): all 17 Plates and 4 Drives (¥1,000), Adamant Crystal, Lustrous Globe, Griseous Core, the Adamant, Lustrous and Griseous Orbs, Soul Dew and Zygarde Cube (¥10,000). Items without an official price were given one. **Decided:** no items for Pokémon that aren't in the game: Memories (Silvally), Rusted Sword and Shield, Ogerpon's masks, DNA Splicers, Reveal Glass, Prison Bottle, N-Solarizer and N-Lunarizer, Reins of Unity.
  - **Done: charms (approved by Joe, Oct 2026).** Oval Charm at Cavatapurf (near the Day Care), Exp. Charm at Pestoburg, Catching Charm at Jason's Linguicove Dept. Store 2F counter; ¥30,000 each, one per save. **Decided:** no Vs. Seeker (turning it on would disable PokéNav rematches, the only way to rematch Gym Leaders), no Glimmering Charm (no Tera raids), no Poké Radar (not functional in this engine).
  - **Done: the last item groups (approved by Joe, Oct 2026).** Spaghettiport harbor market TM stall: all 18 Gems (¥4,000, the Gen 7 price; officially ¥15,000). Linguicove Dept. Store 2F medicine counter: Sweet Heart, Max Honey, the three Remedies and the 8 regional status-healing snacks (Pewter Crunchies, Rage Candy Bar, Old Gateau, Casteliacone, Lumiose Galette, Shalour Sable, Big Malasada, Jubilife Muffin), plus Dream and Fab Mail; Jason's counter: Retro Mail. 3F X-item counter: X Sp. Def. Orzodale: Poké Doll, Poké Toy. Lure / Super Lure / Max Lure at Rotiniboro / Fortellini / Mostaccideep. **Decided (skipped):** new fossils (their Pokémon are already wild), Legends: Arceus battle items (no effect in this engine), sell-only valuables and Relics, Odd Keystone, Apricorns, Galarica Twig, Wishing Piece, and Mulch (berry mulching stays off so planting stays quick).
  - **Item inventory finished.** Every item the engine has is now either obtainable or deliberately left out; the review page is at https://claude.ai/artifact/Gx72DVvinmpGEekfDT9iSw.
  - **Done: the TM pocket holds all 108 TMs and HMs.** It used to have 64 slots. Since TMs are reusable, the save now records one "owned" bit per TM/HM (14 bytes in spare save space), and the pocket lists them in number order. Older saves' TMs carry over on load.
  - **Done: evolution counter.** A third clerk on the Linguicove Department Store's 3rd floor sells all 51 items any Pokémon uses to evolve: every evolution stone, the Linking Cord, every held trade item (Metal Coat, King's Rock, Dragon Scale, Up-Grade…), and the newer items (apples, teacups, sweets, Galarica items, armors, Black Augurite, Peat Block, Metal Alloy, both Scrolls). The Scrolls had no price, so they now cost ¥3,000.
  - **Done: Kingambit and Gholdengo are obtainable.** The counter also sells the **Leader's Crest** (¥3,000), which now works like an evolution stone on Bisharp (it used to need Bisharp to defeat three Bisharp holding one). A gentleman beside the counter gives **999 Gimmighoul Coins**; Gimmighoul evolves into Gholdengo when it levels up with 999 coins in the bag (unchanged), which uses them up, so he gives another 999 whenever the player has none left.
- **Physical/special split.** Built in and on by default.

## Legendary one-off encounters

**Decided:** legendaries and mythicals only (no Ultra Beasts or Paradox Pokémon). Mewtwo and Diancie stay mid-game; everything new unlocks after the Hall of Fame. Each stands on the map with its overworld sprite and can be retried if it faints or the player runs.

**Done: the four event islands** are unlocked in-game. The ferry at the Linguicove harbor takes the player there once they have the ticket (post-game only, as in Emerald):

| Ticket | Island | Pokémon | Given by |
| --- | --- | --- | --- |
| Eon Ticket | Southern Island | Whichever of Latias/Latios didn't roam (Lv 50) | Mike, the first time the player beats him |
| Old Sea Map | Faraway Island | Mew (Lv 50) | Joe Fettuccine, Cove Lily Motel |
| Mystic Ticket | Navel Rock | Lugia and Ho-Oh (Lv 70) | Joe Q, his house at the Bucatini Frontier |
| Aurora Ticket | Birth Island | Deoxys (Lv 50) | Scientist, Mostaccideep Space Center 1F |

**Done: themed one-offs (27).** Levels: Arceus 80; cover legendaries 70; other legendaries 60; mythicals 50. Each is hidden until the Hall of Fame (and until its prerequisites are caught), and disappears once it's registered as caught in the Pokédex. Spots were picked automatically on open floor that can't block a path, so Joe may want to move some in Porymap (look for `OBJ_EVENT_GFX_SPECIES(...)` objects). Flags `FLAG_HIDE_LEGEND_*` (0x264–0x27E).

| Pokémon | Where |
| --- | --- |
| Articuno | Shoal Cave, Ice Room |
| Zapdos | New Macaroville, generator room |
| Moltres | Peperoncino Path |
| Raikou | Route 120 |
| Entei | Mt. Calzone summit |
| Suicune | Route 119, by the waterfall |
| Celebi | Pestoburg Woods |
| Jirachi | Meatball Falls 1F |
| Darkrai | Cave of Oregano |
| Shaymin | Route 117 flower fields |
| Manaphy | Seafloor Cavern |
| Dialga, Palkia | Sky Breadstick 3F and 5F, after catching Rayquaza |
| Arceus | Sky Breadstick summit, after catching Dialga, Palkia and Giratina |
| Giratina | Mt. Penne summit |
| Cresselia | Mt. Penne exterior |
| Heatran | Marinara Hideout, deepest room |
| Regigigas | Sealed Chamber, after catching the three Regis |
| Kyurem | Shoal Cave, low-tide lower room |
| Zygarde | Desert Underpass |
| Xerneas | Safari Zone, forest area |
| Yveltal | Route 113 |
| Solgaleo | Route 111 desert (the Mirage Tower vanishes for good once its fossil is taken, so it can't be used post-game) |
| Lunala | Altering Cave |
| Genesect | Weather Institute lab |
| Marshadow | Gouda Grotto B2F |
| Zeraora | New Macaroville entrance |

Not included for now: the other legendaries, mythicals, Ultra Beasts and Paradox Pokémon (about 110).

## Battle mechanics

- **Mega Evolution.** Built in. **Done:** Steven (Sam) gives the **Mega Ring** in Gouda Grotto, right after TM Steel Wing, followed by the Mega Stone Case. **Decided:** the item keeps the engine's name, Mega Ring (Joe briefly tried "Key Stone" and switched back). **Decided:** the new Megas from Legends Z-A are excluded for now.
  - **Decided (Oct 2026): every Mega is available from badge 1.** Sam gives the **Mega Stone Case** along with the Mega Ring. It holds every Mega Stone and never runs out, so two Pokémon can hold the same stone. This replaces the earlier plan of spreading stones out as item balls; Joe accepted that Megas are no longer gated by progress.
  - **Done: Mega Stone Case** (key item, `ITEM_MEGA_STONE_CASE`, code in `src/mega_stone_case.c`). While the player has it, the bag treats every Mega Stone as owned: giving one takes nothing, and taking one off a Pokémon returns it to the case. Using the case lists every stone, then opens the party menu to give the chosen one.
  - **Done:** all 39 Mega Stone item balls and Alan's 7 starter-stone gift are removed. The Dawn Stone and the two Metal Coats stay on the map. **Old saves:** Nurse Joy gives the case to anyone who already has the Mega Ring, and Mega Stones in their bag move into it.
  - **Decided: Marzano Mega Evolves Camerupt** (Space Center double battle) and **Parmigiano Mega Evolves Sharpedo** (Seafloor Cavern).
  - **Done: every Mega-capable Pokémon is obtainable before Brian** (see "Pokémon added for Mega Evolution" below).
  - **Done: Safari Zone expansion open from the start** (Mareep and Houndour live there; in Emerald it opened after the Hall of Fame).
  - **Done: the Latias/Latios roamer starts after the Sugopolis crisis,** when Wallace gives HM Waterfall and mentions reports of a rare red or blue Pokémon (picked at random). In Emerald it started after the Hall of Fame.
  - **Done: Beldum is offered by Steven (Sam) with HM Dive** after the Space Center, instead of after the Hall of Fame.
  - **Done: trade evolutions without trading.** Two Linking Cords (Routes 110 and 123) evolve Kadabra, Haunter and other trade Pokémon. `I_USE_EVO_HELD_ITEMS_FROM_BAG` is on, so held-item trade evolutions (Metal Coat, Dragon Scale, Electirizer…) work by using the item from the bag. Two Metal Coats are placed (New Macaroville, Route 121) for Steelix and Scizor.
  - **Done: plain trade evolutions are now level-up evolutions.** Kadabra Lv 36; Machoke, Graveler (both forms), Haunter, Boldore, Gurdurr Lv 40; Phantump and all Pumpkaboo sizes Lv 35; Karrablast and Shelmet Lv 30 (no partner needed). The Linking Cord still works on them as an early shortcut. **Decided:** held-item trade evolutions stay as they are (use the item from the bag).

### Pokémon added for Mega Evolution

**Decided:** these Pokémon were added so every Mega Stone is usable before the final battle with Brian. New wild Pokémon take over a slot of a species that already appears two or more times in that area, so every Gen 3 Pokémon stays where it was in Emerald.

| Pokémon | Where |
| --- | --- |
| Weedle | Pestoburg Woods |
| Pidgey | Routes 102, 103, 104 |
| Bulbasaur, Buneary, Audino | Route 117 (rare) |
| Slowpoke | Route 117 (surfing), Shoal Cave (surfing) |
| Onix | Gouda Grotto 1F, Rotipurf Tunnel |
| Snover | Shoal Cave, ice room |
| Gastly | Mt. Penne 1F–6F |
| Meditite | Mt. Penne outside and summit |
| Larvitar, Gible | Route 111 desert (rare) |
| Scyther, Treecko | Route 119 (rare) |
| Torchic | Peperoncino Path (rare) |
| Charmander | Route 112 (rare) |
| Squirtle | Route 118 (surfing) |
| Mudkip | Route 120 (rare) |
| Kangaskhan | Safari Zone South |
| Riolu | Egg from a Black Belt next to the Ditalinford Gym |
| Aerodactyl | Old Amber from the Fossil Maniac (Route 114), revived at Garlic Corp. in Rotiniboro |
| Diancie | One-time encounter, Lv 50, Meatball Falls B1F back room |
| Mewtwo | One-time encounter, Lv 70, Victory Road B2F |

Diancie and Mewtwo stay put if the player knocks them out or runs, so they can be retried.
- **Primal Reversion (Kyogre and Groudon).** Built in; triggers when they hold the Blue Orb or Red Orb. **Decided:** the orbs come from the elderly couple at the Mt. Pyre summit, as in Omega Ruby/Alpha Sapphire (Emerald never gives them to the player). **Done:** after Marzano and Parmigiano return the orbs (after Sugopolis, before the Elite Four), the old woman gives the player both orbs. If the bag is full, she offers them again later. **Done:** Terramisu Cave (Groudon) and Marsala Cave (Kyogre) open at the same point instead of after the Hall of Fame: the Weather Institute scientist (2F) reports the abnormal weather once the orbs are returned, and the old woman points the player there.
- **Decided (Oct 2026): no Z-Moves, Terastallization or Dynamax.** They stay switched off: the player can never get the key items they need (Z-Power Ring, Tera Orb, Dynamax Band), and no trainer uses them. Z-Crystals, Tera Shards, Max Mushrooms, Dynamax Candy and the like stay out of the game.
- **Double wild battles.** Config option with an adjustable encounter chance. **Done:** 15% chance; always a single battle when the player has only one usable Pokémon.

## Battle UI and speed

Mostly quality-of-life config options. Feature names change between expansion versions, so read `include/config/` and report what this copy offers before editing.

**Done.** Most were already on by default; Run shortcut and skipping the intro slide were turned on. Simultaneous HP reduction is built in (confirmed in playtest). **Decided (Oct 2026): faster AI calculations are dropped;** the AI stays as it is.

- **Poké Ball quick menu** ("last used ball" shortcut). R throws the last ball; hold R and press the D-Pad to switch.
- **Move description menu** in the fight menu. Press L while choosing a move.
- **Shortcut to Run** in wild battles. B jumps the cursor to Run.
- **Faster battle intro.**
- **Faster HP drain.**
- **Simultaneous HP reduction** for spread moves in doubles.
- **Done: caught Pokémon are fully healed** (HP, status and PP) as soon as they're caught.
- **Done: battle speed option.** BATTLE SPEED (1X / 2X) in the Options menu, 4th row. At 2X the battle runs twice per frame (animations, HP bars, text); the overworld and music are unaffected, and each button press only counts once. Off in link and recorded battles. Defaults to 1X; existing saves start at 1X. To fit 8 rows, the title and list now share one frame. Screen fades always run at 1X: running them twice per frame could stop a fade from ever finishing, which froze the game after forgetting a move to learn a new one in battle (found in Playtest 2, fixed in the rebuilt Playtest 2).
- **Walking-down bug: safety net in place (Playtest 4); root cause still open.** Seen three times (mGBA on the Mac and the mGBA core on the Anbernic), always right after catching a Pokémon with 2X speed on. The player keeps walking south and bumps into walls; no button works (Up doesn't override, Start won't open). A save state from Playtest 3 showed why: the main loop keeps a few values in CPU registers for the whole game (one is the address of the button register), and they had been overwritten with leftovers from the end-of-battle cleanup (`FreeBattleResources`). The game was reading "buttons" from battle memory, which happened to say DOWN. Not an emulator problem: the stuck value has bits no controller can produce. **Done:** the main loop now runs each frame as its own function (`RunFrame` in `src/main.c`), so those values are reloaded every frame and the game recovers on the next frame. **Open:** what corrupts the registers at the end of a wild battle is still unknown and could cause other glitches; testers are asked to send a save state if anything odd happens right after a battle.

## Overworld and menus

- **Done: the player starts with the Running Shoes.** Mom's scene in Lil Ragu Town after getting the starter is now just a goodbye.
- **Done: the player starts with the Shiny Charm** in the bag (it only works from the bag, not the PC).
- **Done: INSTANT text speed.** TEXT SPEED in the Options menu cycles SLOW / MID / FAST / INSTANT with Left and Right; only the chosen speed is shown, like FRAME.
- **Done: one combined BIKE.** Rydel gives a single BIKE. Press **B** while riding to switch between **FAST mode** (Mach Bike) and **ACRO mode** (Acro Bike); the bike bell rings and the sprite changes. In Acro mode, **R** does wheelies, bunny hops and jumps (they used to be on B). The bike remembers the last mode (`FLAG_BIKE_ACRO_MODE`). Switching is blocked mid-trick and on rails, bumpy slopes and sandy slopes. **Decided:** two modes, not three (a "normal" mode would have ridden exactly like Acro mode). Both old bike items are now named "Bike" and work the same, so old saves need nothing. Rydel's handbooks, Ethan (Jagged Pass), Sam's call and the Cycling Road gatekeeper talk about modes.
- **Done: MEDICINE pocket.** 68 items (potions, revives, status heals, PP restorers, vitamins, feathers, mochi, Rare Candy, Exp. Candies) moved from Items to a new 40-slot pocket between ITEMS and POKé BALLS. Honey and Dynamax Candy stay in Items. Its slots use spare space at the end of the save, so **old saves still load**; the first load moves their medicine over (`FLAG_MEDICINE_POCKET_READY`). Wally's (Brian's) catching tutorial starts on this pocket so it still lands on Poké Balls. **Decided:** the pocket keeps using the Items bag picture.
- **Done: Pokédex search by typed name.** The Name list has **TYPE A NAME** below DON'T SPECIFY. It opens the nickname keyboard ("Which POKéMON?"); the search screen comes back with the name filled in and every other setting kept. It finds names that start with the typed text (upper/lower case doesn't matter) and combines with color, type and order. Search also defaults to the National Dex, so Pokémon outside the Pastalia Dex are found.
- **Done: no random PokéNav calls from trainers.** Story calls (Alan, Sam, Mom, etc.) are unchanged.
- **Done: Route 111's smashed rocks stay broken** (Rotipurf Tunnel's already did).
- **Done: Gabby and Ty ask one YES/NO question:** "Does butter belong on a sandwich?" Later interviews ask if the player still stands by it, and the TV show reports the answer.
- **Done: faster berry picking.** Talking to a ripe tree picks it right away: no "Do you want to pick?" question, a short sound instead of the fanfare, and one message ("{PLAYER} picked 3 ORAN BERRIES!") instead of two.

- **HMs are not permanent.** HM moves can be forgotten like normal moves. **Decided:** field moves only need the badge plus the HM in the bag; no Pokémon has to know the move. Forgetting HMs is **done** (config). **Done:** using field moves without knowing them. If no party Pokémon knows the move, a phantom Magikarp uses it (Magikarp in the animation), even with no Magikarp in the party. FLY and FLASH appear in every Pokémon's party menu once the badge and HM are in hand, and can also be used straight from HM02 and HM05 in the bag (USE still teaches the move). **Done (Playtest 4): faster HMs.** CUT, ROCK SMASH, STRENGTH, SURF, WATERFALL and DIVE (down and up) ask a single "Use CUT?" (etc.) YES/NO and act right away; the description pages and the "MAGIKARP used CUT!" / "used STRENGTH!" messages are gone. Without the HM or badge, the tree, rock or boulder still explains what it is. Pressing A on a boulder with Strength already on still says STRENGTH is active.
- **Move relearner in the party menu.** A "Relearn" option on each Pokémon. This version already has a relearner on the summary screen's moves page. **Decided:** add it as a party-menu option anyway (custom). **Done:** RELEARN appears for any Pokémon with moves to relearn and returns to the party menu when finished. It's free, like the summary-screen relearner.
- **PC access anywhere via a bag item.** A key item that opens the storage system. **Done (built in):** the expansion's Pkmn Box Link. Alan gives it with the starter in his lab.
- **"Move" as the default PC option.** **Done (built in):** MOVE POKéMON is the first PC menu option, with the cursor on it, in every PC and the Box Link. **Decided:** keep the menu rather than skipping straight into Move mode, so MOVE ITEMS stays available.

## Secret minigame: Pocket Knight Adventures

**Decided:** the GameCube in the player's bedroom in Lil Ragu is a secret unlock. If the player's name is exactly **Joe F.**, interacting with it starts a simple side-scrolling rocket-pack minigame, *Pocket Knight Adventures*: a homemade tribute to Rocket Knight Adventures (Sega Genesis), and a nod to it being a tiny game inside a GBA game. **Late-build bonus:** do it after the main custom features, before or alongside the randomizer.

- **Decided:** in-game, the console is described as a Sega Genesis for every player, secret name or not.
- **Decided:** the name match is exact and case-sensitive: uppercase J, lowercase o, lowercase e, space, uppercase F, period. "JOE F." or "joe f." does not unlock it. It's 6 characters (within Emerald's 7-character limit), and the space and period are both on the naming screen.

**Constraints:**

- **Do not emulate or include Rocket Knight Adventures.** The GBA can't emulate the Genesis, and putting Konami's ROM in a shared hack would be piracy.
- The minigame must be **original**: original code and original sprites. It can nod to the style (a jetpack hero, side-scrolling, Genesis-era feel) but must not copy Konami's characters, art, music, or levels.
- Keep the scope small. This is a bonus feature, not a second game.

**Unlock logic:**

- The GameCube's script compares `gSaveBlock2Ptr->playerName` to "Joe F." (exact, case-sensitive).
- Match: ask "Boot up the game?" (yes/no) and launch the minigame.
- No match: show this text instead (no minigame): "It's a Sega Genesis. There's a copy of Pocket Knight Adventures in it... universally agreed upon to be the greatest 2D platformer of all time." Break it to fit the text box with `\n` and `\p`.
- Returning from the minigame drops the player back in the bedroom without disturbing the overworld state.

**Minigame scope (first pass):**

- One screen-scrolling level, or a short endless runner.
- **Decided:** the hero is a generic blue armored knight with a rocket pack, as an original sprite. Not an opossum or any other animal, so it doesn't copy Sparkster.
- Controls: D-pad to move, A to jump, B for a rocket-boost dash.
- A few obstacle and enemy types, plus a goal or score counter.
- Win or lose screen, then return to the bedroom.
- Optional: a high score saved to a spare save variable.
- **Decided:** the first clear gives one Master Ball (one time only, tracked with a flag; replays give nothing extra).

**Suggested approach:**

- Build it as its own callback/task screen (like the Berry Blender or Pokéblock minigames), separate from the battle and overworld systems. Check how pokeemerald-expansion structures existing minigames before writing anything new.
- Do it in steps, building and committing after each: (1) name check plus placeholder screen, (2) scrolling background, (3) player movement, (4) obstacles and enemies, (5) win/lose and return, (6) polish.

**Done** (the polish step was skipped). **Decided:** the placeholder art stays as the final art.

- Title screen ("PRESS A TO START", "B: QUIT", in-game controls listed) leads into one side-scrolling level about four screens wide, with a parallax mountain backdrop. Code is in `src/pocket_knight.c`.
- Controls: D-pad runs, A jumps (hold for higher), B is a rocket dash (once per jump, recharged on landing or by stomping), START quits.
- Two original enemies: Clank (walker, turns at walls and ledges) and Buzz (flying drone that bobs up and down). Stomp or dash through them for 100 points each. Spikes and pits hurt too.
- 3 lives. A hit restarts the level from the beginning with a short invincibility flicker. GAME OVER plays the "too bad" jingle; touching the flagpole shows YOU WIN! with the score and the level-up fanfare.
- The first win gives one Master Ball back in the bedroom ("Something popped out of the cartridge slot!"), tracked with `FLAG_POCKET_KNIGHT_CLEARED` (the former unused flag 0x1AA). If the bag is full, the next win tries again.
- **Level layout** is ASCII art in `src/data/pocket_knight_level.h` (`#` ground, `=` brick, `^` spikes, `E` walker, `Y` flyer, `S` start, `|` flagpole). Every row must stay 128 characters.
- Not done (optional): saved high score, death animation, checkpoints, its own music.

## Randomizer option at game start

A yes/no choice at New Game that randomizes Pokémon for that save file. It must run inside the ROM at runtime (save-file flag plus a seed), not as a separate patching tool. **Build this last.**

**Decided:**

- Randomizes **wild Pokémon, starters, and trainer teams**.
- **Full random** (no matching by strength).
- **No exclusions;** legendaries can appear anywhere.
- **Simple on/off.** The New Game prompt must tell the player exactly what gets randomized: wild Pokémon, starters, and trainer teams.

## Feature tracker

| Feature | Type of work | Status |
| --- | --- | --- |
| Pasta town names | Text, signs, Town Map | Done |
| Pasta landmark names | Text, Town Map | Done |
| Villain teams: Alfredo and Marinara (names) | Text, trainer classes | Done |
| Villain teams: recolored sprites | Palette edits | Not started |
| Kyogre recolored cream | Palette edits, possibly pixel edits | Not started |
| Villain teams: white vs. red sauce story dialogue | Dialogue | Done |
| Villain leaders renamed: Parmigiano and Marzano | Text, trainer data | Done |
| Pasta region name: Pastalia (replaces Hoenn) | Text, plus 2 PokéNav graphics and 1 Pokédex graphic | Text done; PokéNav "HOENN MAP" and Pokédex "HOENN" art still to redraw |
| Starters: Rowlet, Scorbunny, Froakie | Script and data change | Done |
| Nurse Joy Jammie Dodger heal (plus blackout cookie) | One shared script change | Done |
| Retro Salvage Games shops (Jason, orange roofs) | Sprite recolor, palette, tiles | Dialogue done; Jason sprite, orange roofs and sign tile still to do |
| Main character sprites (Ethan and Kris) | Community sprites, no recolor | Not started |
| Brian as rival (sprites, name, logic, anti-pasta story) | Art plus code and dialogue | Partly done: named BRIAN for both genders, uses Brendan's sprites as a placeholder; rival teams and dialogue done (Macaroville, Victory Road and Champion come with those steps); custom sprites still to do |
| Brian replaces Wally (Petalburg catch, Mauville, Victory Road) | Scripts and dialogue | Done (Brendan's sprites as placeholder) |
| Brian as Champion, Mike (replaces Wallace) outside the Elite Four | Scripts, trainer data, dialogue, custom sprites | Done (placeholder sprites: Brendan for Brian, Wallace for Mike) |
| Brian's room SNES / Time Toggle text | Text edit | Done |
| Joe Q replaces Scott | Dialogue rewrite (keeps Scott's sprite) | Name and dialogue done (keeps Scott's sprite) |
| New themed teams for all trainers and Gym Leaders (Gens 1–9, Megas from gym 3) | Trainer data | Done |
| Trainer names from the Retrotopia community | Text (waiting on Joe's list) | Not started |
| Retrotopia cast: Alan (Birch), Sam (Steven), Joe Fettuccine (designer) | Custom sprites, scripts, dialogue | Partly done: names and dialogue done for all three (Joe Fettuccine gives the Old Sea Map and signs the diploma); all three custom sprites still to do |
| All Pokémon through Gen IX | Built in; plan placement | Done: wild placement, event islands, 27 legendary one-offs, regional evolutions |
| Items, abilities, move effects through Gen IX | Built in; plan placement | Done: TM51–100, held items, training items, balls, berries, form items, charms, gems, snacks placed in shops; the rest skipped on purpose |
| Physical/special split | Built in | Done (built in) |
| Mega Evolution (Mega Ring and Mega Stone Case from Sam in Gouda Grotto) | Built in, plus custom key item | Done |
| Primal Reversion | Built in; place Blue/Red Orbs | Done (orbs given at Mt. Penne) |
| Double wild battles | Config toggle | Done (config, 15%) |
| Poké Ball quick menu | Config toggle | Done (built in) |
| Move description menu | Verify in config | Done (built in) |
| Shortcut to Run | Verify in config | Done (config) |
| Faster battle intro | Config toggle | Done (config) |
| Faster HP drain | Config toggle | Done (built in) |
| Simultaneous HP reduction | Verify in config | Done (built in) |
| Battle speed option (battles only) | Custom (Options menu) | Done |
| Non-permanent HMs | Config toggle plus custom | Done: HMs forgettable (config); with the badge and HM in the bag, a phantom Magikarp uses the move; FLY and FLASH also in every party menu and usable from HM02/HM05 in the bag; one-question "Use CUT?" prompts |
| Move relearner in party menu | Custom (party-menu option) | Done: RELEARN appears for Pokémon with moves to relearn (summary-screen relearner also still there) |
| PC access via bag item, "Move" default in storage | Built in | Done: Pkmn Box Link (from Alan with the starter); MOVE POKéMON is already the default option |
| Start with Running Shoes | New-game setup, Mom's script | Done |
| Start with Shiny Charm | New-game setup | Done |
| Faster berry picking | Berry tree script | Done |
| Secret Pocket Knight Adventures minigame (name "Joe F.") | Custom minigame, original sprites | Done |
| Randomizer at New Game | Custom (large) | Not started |
| Instant text speed | Options menu | Done |
| National Dex from the start | Script | Done |
| Reusable TMs | Config toggle | Done |
| Plain trade evolutions become level-up | Species data | Done |
| Wonder Trade (right-hand counter, every Pokémon Center) | Custom | Done |
| Retrotopia promo office (Ditalinford Hall) | Dialogue | Done |
| Gouda Grotto (Granite Cave) | Text, Town Map | Done |
| Garlic Corp. (Devon) | Text, item names | Done |
| WILDCARD and Wildcard's Castle (Trick Master, Trick House) | Dialogue, sprite swap | Done (Joe Fettuccine's placeholder sprite) |
| Alan's post-game lab scene | Dialogue | Done |
| Brian's house sign and ANTI-PASTA PokéNav tag | Text | Done |
| One combined BIKE (B: Fast/Acro, R: tricks) | Custom | Done |
| MEDICINE bag pocket | Custom | Done |
| Pokédex search by typed name | Custom | Done |
| Wild encounters without time of day (4% minimum) | Data plus engine change | Done |
| Caught Pokémon fully healed | Custom | Done |
| No random trainer PokéNav calls | Custom | Done |
| Peperoncino Path (Fiery Path) | Text | Done |
| Gabby and Ty butter question | Script | Done |
| Wildcard's Castle quiz (WILDCARD and Retrotopia questions) | Dialogue | Done |
| Retro Salvage Games shop dialogue | Dialogue | Done |
| Cellar Dweller Collections (Blobby's stall, Spaghettiport) | Script, dialogue | Done (placeholder sprite) |
| Alan's lab bookcases | Map layout | Done |
| Alan secret boss battle | Script, trainer data, dialogue | Done (placeholder battle sprite) |

## Playtests

Testers download from **https://github.com/jchiparo-lab/Pokemon-Fettuccine/releases/latest**, which always opens the newest playtest. Each release is a zip with a `.bps` patch (applied to a clean US Emerald ROM) and a README; the ROM itself is never shared. Tester notes live in `docs/playtests/playtest-N.txt`, and `tools/fettuccine/make_playtest.sh N` builds, patches, checks and zips a playtest. Builds include the debug menus.

| Playtest | Highlights |
|---|---|
| 1 | First build |
| 2 | Brian, Retrotopia cast, new teams, every Pokémon in the wild, battle speed; rebuilt to fix the 2X move-forget freeze |
| 3 | Wonder Trade, National Dex from the start, reusable TMs, level-up trade evolutions, INSTANT text, Wildcard's Castle, Gouda Grotto, Garlic Corp. |
| 4 | Faster HMs, walking-down bug safety net |
| 5 | One combined Bike, time-free wild encounters, Medicine pocket, full TM pocket, Pokédex name search, Retro Salvage Games dialogue, TM51–100 and about 270 new shop items, Mega Stone Case |

**Idea (not scheduled): free up save space.** `include/config/save.h` can switch off unused save data (Mystery Event, record-mixing Hall records, Mystery Gift, Union Room chat, Battle Tower e-Reader and smaller ones), about 3.7 KB in all. Any of these shifts the save layout and breaks existing saves, so do them together, once, in a playtest where testers start a new save. Keep Match Call (the story calls use it).

## Suggested build order

Work from easiest to hardest so there's always a playable build.

1. ~~Build pokeemerald-expansion unchanged and confirm it runs in mGBA. (Intel Mac with MacPorts, not Homebrew.)~~ **Done.** devkitARM 16.1.0; the hack lives on the `fettuccine` git branch, based on upstream commit `90c30f02ae`.
2. ~~Audit `include/config/` and report which "Verify" features exist in this version.~~ **Done.**
3. ~~Turn on the config toggles (battle speed, double wilds, HMs) and playtest.~~ **Done.** Legends Z-A Megas turned off.
4. ~~Small visible changes: town names, Nurse Joy, starters.~~ **Done**, plus landmark names.
5. ~~Script the Mega Ring (Sam in Gouda Grotto), Mega Stones, and Orbs into the story.~~ **Done.**
6. Story and character changes: Brian (rival, Wally, Champion), the Retrotopia cast, Retro Salvage Games.
7. ~~Small custom features: PC item and Move-default storage; party-menu relearner if needed.~~ **Done**, plus HM field moves without knowing the move.
8. Sprites (as art becomes available).
9. Randomizer, last.
