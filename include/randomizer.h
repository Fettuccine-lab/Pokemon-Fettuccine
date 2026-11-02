#ifndef GUARD_RANDOMIZER_H
#define GUARD_RANDOMIZER_H

// Each kind of Pokémon source rolls separately, so the same species can become
// different Pokémon depending on where it comes from.
enum RandomizerSource
{
    RANDOMIZER_WILD,     // the salt also includes the current map
    RANDOMIZER_STATIC,   // legendaries and other scripted wild battles, roamers
    RANDOMIZER_GIFT,     // givemon, giveegg and in-game trades
    RANDOMIZER_TRAINER,
    RANDOMIZER_FRONTIER,
    RANDOMIZER_STARTER,
};

void RandomizerSetNewGameChoice(bool32 enabled);
void RandomizerApplyNewGameChoice(void);
bool32 RandomizerIsActive(void);
bool32 RandomizerIsSpeciesInPool(enum Species species);
enum Species RandomizerGetSpecies(enum Species species, enum RandomizerSource source, u32 salt);
enum Species RandomizerGetStarter(enum Species species, u32 starterId);

#endif // GUARD_RANDOMIZER_H
