#ifndef GUARD_STARTER_CHOOSE_H
#define GUARD_STARTER_CHOOSE_H

extern const u16 gBirchBagGrass_Pal[];
extern const u32 gBirchBagTilemap[];
extern const u32 gBirchGrassTilemap[];
extern const u32 gBirchBagGrass_Gfx[];
extern const u32 gPokeballSelection_Gfx[];

// Fettuccine: the secret "Joe" starter (shiny Charcadet), returned by the starter screen
#define STARTER_JOE_CHARCADET 3

u16 GetStarterPokemon(u16 chosenStarterId);
u16 GetPlayerStarterSpecies(void);
void CB2_ChooseStarter(void);

#endif // GUARD_STARTER_CHOOSE_H
