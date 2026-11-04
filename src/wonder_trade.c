#include "global.h"
#include "event_data.h"
#include "pokemon.h"
#include "random.h"
#include "wonder_trade.h"
#include "randomizer.h"

// Wonder Trade: the right-hand counter upstairs in every Pokémon Center.
// The player sends one Pokémon and gets a random non-legendary one back at
// the same level (mythicals can come back too). The trade itself reuses the
// in-game trade scene in trade.c, which swaps the player's Pokémon with
// gParties[B_TRAINER_OPPONENT_A][0].

// Pasta-named trading partners.
static const u8 sWonderTradeOtNames[][PLAYER_NAME_LENGTH + 1] =
{
    _("PENNE"),
    _("ZITI"),
    _("ORZO"),
    _("FUSILLI"),
    _("GNOCCHI"),
    _("RAVIOLI"),
    _("LASAGNA"),
    _("ROTINI"),
    _("CAPELLI"),
    _("PASTINA"),
};

static bool32 IsWonderTradeSpecies(enum Species species)
{
    const struct SpeciesInfo *info = &gSpeciesInfo[species];

    if (RandomizerIsActive())
        return RandomizerIsSpeciesInPool(species);

    if (species == SPECIES_NONE || species >= NUM_SPECIES || !IsSpeciesEnabled(species))
        return FALSE;

    if (info->isRestrictedLegendary || info->isSubLegendary || info->isUltraBeast || info->isParadox)
        return FALSE;

    if (info->cannotBeTraded || info->isTotem || info->isMegaEvolution || info->isPrimalReversion
     || info->isUltraBurst || info->isGigantamax || info->isTeraForm)
        return FALSE;

    // Only base forms and regional forms (no battle forms, costumes, etc.)
    if (GET_BASE_SPECIES_ID(species) != species
     && !(info->isAlolanForm || info->isGalarianForm || info->isHisuianForm || info->isPaldeanForm))
        return FALSE;

    return TRUE;
}

static enum Species GetRandomWonderTradeSpecies(void)
{
    u32 i;

    for (i = 0; i < 1000; i++)
    {
        enum Species species = 1 + Random() % (NUM_SPECIES - 1);
        if (IsWonderTradeSpecies(species))
            return species;
    }
    return SPECIES_EEVEE;
}

// Builds the Pokémon the player will receive. The player's choice is in
// VAR_0x8004 (party slot, or PC_MON_CHOSEN). The received species is
// stored in VAR_0x8009 for the script.
void CreateWonderTradePokemon(void)
{
    struct Pokemon *mon = &gParties[B_TRAINER_OPPONENT_A][0];
    u32 level = GetLevelFromBoxMonExp(GetSelectedBoxMonFromPcOrParty());
    enum Species species = GetRandomWonderTradeSpecies();
    u8 otGender = Random() % 2;
    metloc_u8_t metLocation = METLOC_IN_GAME_TRADE;

    CreateMon(mon, species, level, Random32(), OTID_STRUCT_PRESET(Random32()));
    GiveMonInitialMoveset(mon);
    SetMonData(mon, MON_DATA_OT_NAME, sWonderTradeOtNames[Random() % ARRAY_COUNT(sWonderTradeOtNames)]);
    SetMonData(mon, MON_DATA_OT_GENDER, &otGender);
    SetMonData(mon, MON_DATA_MET_LOCATION, &metLocation);
    CalculateMonStats(mon);

    gSpecialVar_0x8009 = species;
}
