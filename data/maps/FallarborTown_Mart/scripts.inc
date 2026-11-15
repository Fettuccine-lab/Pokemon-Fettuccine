FallarborTown_Mart_MapScripts::
	.byte 0

FallarborTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message FallarborTown_Mart_Text_JasonGreeting
	waitmessage
	pokemart FallarborTown_Mart_Pokemart
	msgbox gText_RetroSalvageGames_ThanksForShopping, MSGBOX_DEFAULT
	release
	end

	.align 2
FallarborTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_MOON_BALL
	.2byte ITEM_DUSK_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_TM_ROCK_SLIDE
	.2byte ITEM_TM_POISON_JAB
	.2byte ITEM_TM_SHADOW_CLAW
	.2byte ITEM_SMOOTH_ROCK
	.2byte ITEM_SAFETY_GOGGLES
	.2byte ITEM_AUSPICIOUS_ARMOR
	.2byte ITEM_MALICIOUS_ARMOR
	pokemartlistend

FallarborTown_Mart_EventScript_Woman::
	msgbox FallarborTown_Mart_Text_DecidingSkittyEvolve, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_PokefanM::
	msgbox FallarborTown_Mart_Text_SellNuggetIFound, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox FallarborTown_Mart_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_Mart_Text_DecidingSkittyEvolve:
	.string "Should I use this MOON\n"
	.string "STONE on my SKITTY?\p"
	.string "It'd be stronger, but\n"
	.string "look so different…\p"
	.string "I'll think it over while I browse!$"

FallarborTown_Mart_Text_Skitty:
	.string "SKITTY: Miyao?$"

FallarborTown_Mart_Text_SellNuggetIFound:
	.string "I found this NUGGET and it has\n"
	.string "no other use, so I'm selling it.\p"
	.string "JASON pays a fair price!$"

FallarborTown_Mart_Text_JasonGreeting:
	.string "JASON: Ash from MT. CALZONE\n"
	.string "gets everywhere around here.\p"
	.string "I wipe down every cartridge\n"
	.string "before it hits the shelf!\p"
	.string "What'll it be?$"
