LilycoveCity_DepartmentStore_3F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_3F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_Vitamins
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_3F_Pokemart_Vitamins:
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	.2byte ITEM_HEALTH_MOCHI
	.2byte ITEM_MUSCLE_MOCHI
	.2byte ITEM_RESIST_MOCHI
	.2byte ITEM_GENIUS_MOCHI
	.2byte ITEM_CLEVER_MOCHI
	.2byte ITEM_SWIFT_MOCHI
	.2byte ITEM_FRESH_START_MOCHI
	.2byte ITEM_EXP_CANDY_M
	.2byte ITEM_EXP_CANDY_L
	.2byte ITEM_ABILITY_CAPSULE
	pokemartlistend

LilycoveCity_DepartmentStore_3F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_StatBoosters
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_3F_Pokemart_StatBoosters:
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_CHOICE_BAND
	.2byte ITEM_CHOICE_SPECS
	.2byte ITEM_CHOICE_SCARF
	.2byte ITEM_LIFE_ORB
	.2byte ITEM_FOCUS_SASH
	.2byte ITEM_ASSAULT_VEST
	.2byte ITEM_EVIOLITE
	.2byte ITEM_ROCKY_HELMET
	.2byte ITEM_WEAKNESS_POLICY
	.2byte ITEM_EXPERT_BELT
	.2byte ITEM_EJECT_BUTTON
	.2byte ITEM_EJECT_PACK
	.2byte ITEM_CLEAR_AMULET
	.2byte ITEM_MIRROR_HERB
	.2byte ITEM_BLUNDER_POLICY
	.2byte ITEM_HEAVY_DUTY_BOOTS
	.2byte ITEM_COVERT_CLOAK
	.2byte ITEM_LOADED_DICE
	.2byte ITEM_ABILITY_SHIELD
	.2byte ITEM_BINDING_BAND
	.2byte ITEM_ROOM_SERVICE
	.2byte ITEM_THROAT_SPRAY
	.2byte ITEM_PROTECTIVE_PADS
	.2byte ITEM_RING_TARGET
	.2byte ITEM_LUCK_INCENSE
	.2byte ITEM_PURE_INCENSE
	.2byte ITEM_FULL_INCENSE
	.2byte ITEM_ADRENALINE_ORB
	.2byte ITEM_RED_CARD
	.2byte ITEM_X_SP_DEF
	pokemartlistend

LilycoveCity_DepartmentStore_3F_EventScript_TriathleteM::
	msgbox LilycoveCity_DepartmentStore_3F_Text_ItemsBestForTougheningPokemon, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_3F_EventScript_PokefanM::
	msgbox LilycoveCity_DepartmentStore_3F_Text_WantMoreEndurance, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_3F_EventScript_Woman::
	msgbox LilycoveCity_DepartmentStore_3F_Text_GaveCarbosToSpeedUpMon, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_3F_Text_ItemsBestForTougheningPokemon:
	.string "For quickly toughening up POKéMON,\n"
	.string "items are the best.\p"
	.string "PROTEIN boosts ATTACK,\n"
	.string "and CALCIUM raises SP. ATK.$"

LilycoveCity_DepartmentStore_3F_Text_WantMoreEndurance:
	.string "I want my POKéMON to have more\n"
	.string "endurance.\p"
	.string "I'm trying to decide whether to raise\n"
	.string "DEFENSE with IRON, or SP. DEF with ZINC.$"

LilycoveCity_DepartmentStore_3F_Text_GaveCarbosToSpeedUpMon:
	.string "I gave a CARBOS to my POKéMON,\n"
	.string "and its SPEED went up.$"

@ Fettuccine: evolution counter. Sells every item that any Pokemon uses to evolve.
LilycoveCity_DepartmentStore_3F_EventScript_ClerkEvolution::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_EvolutionItems
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_3F_Pokemart_EvolutionItems:
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_SUN_STONE
	.2byte ITEM_SHINY_STONE
	.2byte ITEM_DUSK_STONE
	.2byte ITEM_DAWN_STONE
	.2byte ITEM_ICE_STONE
	.2byte ITEM_LINKING_CORD
	.2byte ITEM_KINGS_ROCK
	.2byte ITEM_METAL_COAT
	.2byte ITEM_DRAGON_SCALE
	.2byte ITEM_UPGRADE
	.2byte ITEM_DUBIOUS_DISC
	.2byte ITEM_PROTECTOR
	.2byte ITEM_ELECTIRIZER
	.2byte ITEM_MAGMARIZER
	.2byte ITEM_REAPER_CLOTH
	.2byte ITEM_DEEP_SEA_TOOTH
	.2byte ITEM_DEEP_SEA_SCALE
	.2byte ITEM_PRISM_SCALE
	.2byte ITEM_OVAL_STONE
	.2byte ITEM_RAZOR_CLAW
	.2byte ITEM_RAZOR_FANG
	.2byte ITEM_SACHET
	.2byte ITEM_WHIPPED_DREAM
	.2byte ITEM_TART_APPLE
	.2byte ITEM_SWEET_APPLE
	.2byte ITEM_SYRUPY_APPLE
	.2byte ITEM_CRACKED_POT
	.2byte ITEM_CHIPPED_POT
	.2byte ITEM_UNREMARKABLE_TEACUP
	.2byte ITEM_MASTERPIECE_TEACUP
	.2byte ITEM_GALARICA_CUFF
	.2byte ITEM_GALARICA_WREATH
	.2byte ITEM_STRAWBERRY_SWEET
	.2byte ITEM_BERRY_SWEET
	.2byte ITEM_LOVE_SWEET
	.2byte ITEM_STAR_SWEET
	.2byte ITEM_CLOVER_SWEET
	.2byte ITEM_FLOWER_SWEET
	.2byte ITEM_RIBBON_SWEET
	.2byte ITEM_BLACK_AUGURITE
	.2byte ITEM_PEAT_BLOCK
	.2byte ITEM_AUSPICIOUS_ARMOR
	.2byte ITEM_MALICIOUS_ARMOR
	.2byte ITEM_METAL_ALLOY
	.2byte ITEM_SCROLL_OF_DARKNESS
	.2byte ITEM_SCROLL_OF_WATERS
	.2byte ITEM_LEADERS_CREST
	pokemartlistend

@ Fettuccine: gives 999 Gimmighoul Coins (what Gimmighoul needs to evolve), again whenever the player has none
LilycoveCity_DepartmentStore_3F_EventScript_CoinCollector::
	lock
	faceplayer
	checkitem ITEM_GIMMIGHOUL_COIN
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_DepartmentStore_3F_EventScript_CoinCollectorStillHasCoins
	msgbox LilycoveCity_DepartmentStore_3F_Text_TakeTheseCoins, MSGBOX_DEFAULT
	giveitem ITEM_GIMMIGHOUL_COIN, 999
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LilycoveCity_DepartmentStore_3F_Text_LevelUpGimmighoul, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_3F_EventScript_CoinCollectorStillHasCoins::
	msgbox LilycoveCity_DepartmentStore_3F_Text_YouStillHaveCoins, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_3F_Text_TakeTheseCoins:
	.string "I collect GIMMIGHOUL COINS.\n"
	.string "Far too many of them, honestly.\p"
	.string "A GIMMIGHOUL evolves once you\n"
	.string "carry 999 of them. Here, take a pile!$"

LilycoveCity_DepartmentStore_3F_Text_LevelUpGimmighoul:
	.string "Level up a GIMMIGHOUL while\n"
	.string "those coins are in your BAG,\l"
	.string "and watch what happens!\p"
	.string "Used them all? Come back for more.$"

LilycoveCity_DepartmentStore_3F_Text_YouStillHaveCoins:
	.string "You've still got some\n"
	.string "GIMMIGHOUL COINS!\p"
	.string "Come back once they're all spent,\n"
	.string "and I'll give you another 999.$"
