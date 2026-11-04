AbandonedShip_CaptainsOffice_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AbandonedShip_CaptainsOffice_OnTransition
	.byte 0

AbandonedShip_CaptainsOffice_OnTransition:
	call AbandonedShip_CaptainsOffice_EventScript_SetupLegendMagearna
	end

AbandonedShip_CaptainsOffice_EventScript_SetupLegendMagearna::
	setflag FLAG_HIDE_LEGEND_MAGEARNA
	goto_if_unset FLAG_SYS_GAME_CLEAR, AbandonedShip_CaptainsOffice_EventScript_SetupLegendMagearnaDone
	getcaughtmon SPECIES_MAGEARNA
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_CaptainsOffice_EventScript_SetupLegendMagearnaDone
	clearflag FLAG_HIDE_LEGEND_MAGEARNA
AbandonedShip_CaptainsOffice_EventScript_SetupLegendMagearnaDone::
	return

AbandonedShip_CaptainsOffice_EventScript_LegendMagearna::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGEARNA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_MAGEARNA, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, AbandonedShip_CaptainsOffice_EventScript_CaughtLegendMagearna
	release
	end

AbandonedShip_CaptainsOffice_EventScript_CaughtLegendMagearna::
	setflag FLAG_HIDE_LEGEND_MAGEARNA
	goto Common_EventScript_RemoveStaticPokemon
	end

AbandonedShip_CaptainsOffice_EventScript_CaptSternAide::
	lock
	faceplayer
	goto_if_set FLAG_EXCHANGED_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner
	goto_if_set FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_2_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	msgbox AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner::
	msgbox AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus::
	msgbox AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner:
	.string "I'm investigating this ship on behalf\n"
	.string "of CAPT. STERN.\p"
	.string "He also asked me to find a SCANNER,\n"
	.string "but I haven't had any success…$"

AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner:
	.string "Oh! That's a SCANNER!\p"
	.string "Listen, can I get you to deliver that\n"
	.string "to CAPT. STERN?\p"
	.string "I want to investigate this ship a\n"
	.string "little more.$"

AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus:
	.string "This ship is called S.S. CACTUS.\n"
	.string "It seems to be from an earlier era.$"

