#include "global.h"
#include "data.h"
#include "event_data.h"
#include "move.h"
#include "pokemon.h"
#include "random.h"
#include "randomizer.h"
#include "script_pokemon_util.h"
#include "trainer_util.h"
#include "wild_encounter.h"
#include "test/test.h"

static void TurnRandomizerOn(void)
{
    FlagSet(FLAG_RANDOMIZER_ON);
    VarSet(VAR_RANDOMIZER_SEED_LOW, 0x1234);
    VarSet(VAR_RANDOMIZER_SEED_HIGH, 0xABCD);
}

TEST("Fettuccine randomizer: off means nothing changes")
{
    FlagClear(FLAG_RANDOMIZER_ON);
    EXPECT_EQ(RandomizerGetSpecies(SPECIES_PIDGEY, RANDOMIZER_WILD, 1), SPECIES_PIDGEY);
    EXPECT_EQ(RandomizerGetStarter(SPECIES_ROWLET, 0), SPECIES_ROWLET);
}

TEST("Fettuccine randomizer: results are repeatable and leave the pool never")
{
    u32 i;

    TurnRandomizerOn();
    for (i = 1; i < NUM_SPECIES; i += 7)
    {
        enum Species rolled = RandomizerGetSpecies(i, RANDOMIZER_TRAINER, i);

        EXPECT(RandomizerIsSpeciesInPool(rolled));
        EXPECT_EQ(rolled, RandomizerGetSpecies(i, RANDOMIZER_TRAINER, i));
    }
    FlagClear(FLAG_RANDOMIZER_ON);
}

TEST("Fettuccine randomizer: the pool has no battle-only forms or Mike's Spearow")
{
    EXPECT(!RandomizerIsSpeciesInPool(SPECIES_SPEAROW_MIKE));
    EXPECT(!RandomizerIsSpeciesInPool(SPECIES_CHARIZARD_MEGA_X));
    EXPECT(!RandomizerIsSpeciesInPool(SPECIES_AEGISLASH_BLADE));
    EXPECT(!RandomizerIsSpeciesInPool(SPECIES_KYOGRE_PRIMAL));
    EXPECT(RandomizerIsSpeciesInPool(SPECIES_AEGISLASH_SHIELD));
    EXPECT(RandomizerIsSpeciesInPool(SPECIES_ARCEUS_NORMAL));
    EXPECT(RandomizerIsSpeciesInPool(SPECIES_RATTATA_ALOLA));
}

TEST("Fettuccine randomizer: starters always know a damaging move")
{
    u32 seed;

    for (seed = 0; seed < 50; seed++)
    {
        struct Pokemon mon;
        enum Species starter;
        u32 j;
        bool32 canFight = FALSE;

        TurnRandomizerOn();
        VarSet(VAR_RANDOMIZER_SEED_LOW, seed * 977);
        starter = RandomizerGetStarter(SPECIES_ROWLET, seed % 3);
        CreateMon(&mon, starter, 5, 0, OTID_STRUCT_PLAYER_ID);
        GiveMonInitialMoveset(&mon);
        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            if (GetMovePower(GetMonData(&mon, MON_DATA_MOVE1 + j)) > 0)
                canFight = TRUE;
        }
        EXPECT(canFight);
    }
    FlagClear(FLAG_RANDOMIZER_ON);
}

TEST("Fettuccine randomizer: trainer Pokemon lose their set moves and Mega Stones")
{
    static const struct TrainerMon trainerMon =
    {
        .species = SPECIES_CHARIZARD,
        .lvl = 50,
        .gender = TRAINER_MON_RANDOM_GENDER,
        .heldItem = ITEM_CHARIZARDITE_X,
        .ability = ABILITY_BLAZE,
        .moves = {MOVE_SPLASH, MOVE_NONE, MOVE_NONE, MOVE_NONE},
    };
    struct TrainerGenerator generator = {0};
    struct Pokemon mon;

    TurnRandomizerOn();
    GenerateMonFromTrainerMon(&mon, &trainerMon, &generator);
    EXPECT(RandomizerIsSpeciesInPool(GetMonData(&mon, MON_DATA_SPECIES)));
    EXPECT_EQ(GetMonData(&mon, MON_DATA_HELD_ITEM), ITEM_NONE);
    EXPECT_NE(GetMonData(&mon, MON_DATA_MOVE1), MOVE_SPLASH);
    FlagClear(FLAG_RANDOMIZER_ON);
}

TEST("Fettuccine randomizer: wild and scripted battles are random, and stay the same")
{
    enum Species first;

    TurnRandomizerOn();
    CreateWildMon(SPECIES_PIDGEY, 5);
    first = GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_SPECIES);
    EXPECT(RandomizerIsSpeciesInPool(first));
    CreateWildMon(SPECIES_PIDGEY, 5);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_SPECIES), first);
    CreateScriptedWildMon(SPECIES_RAYQUAZA, 70, ITEM_NONE);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_SPECIES), RandomizerGetSpecies(SPECIES_RAYQUAZA, RANDOMIZER_STATIC, 0));
    FlagClear(FLAG_RANDOMIZER_ON);
}
