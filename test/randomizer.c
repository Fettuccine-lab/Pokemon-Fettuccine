#include "global.h"
#include "event_data.h"
#include "move.h"
#include "pokemon.h"
#include "randomizer.h"
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
