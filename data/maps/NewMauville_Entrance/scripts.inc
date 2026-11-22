NewMauville_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, NewMauville_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, NewMauville_Entrance_OnTransition
	.byte 0

NewMauville_Entrance_OnLoad:
	call_if_eq VAR_NEW_MAUVILLE_STATE, 0, NewMauville_Entrance_EventScript_CloseDoor
	end

NewMauville_Entrance_EventScript_CloseDoor::
	setmetatile 3, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile0, TRUE
	setmetatile 4, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile1, TRUE
	setmetatile 5, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile2, TRUE
	setmetatile 3, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile3, TRUE
	setmetatile 4, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile4, TRUE
	setmetatile 5, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile5, TRUE
	return

NewMauville_Entrance_OnTransition:
	call NewMauville_Entrance_EventScript_SetupLegendZeraora
	setflag FLAG_LANDMARK_NEW_MAUVILLE
	end

NewMauville_Entrance_EventScript_Door::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox NewMauville_Entrance_Text_DoorIsLocked, MSGBOX_DEFAULT
	checkitem ITEM_BASEMENT_KEY
	goto_if_eq VAR_RESULT, FALSE, NewMauville_Entrance_EventScript_DontOpenDoor
	msgbox NewMauville_Entrance_Text_UseBasementKey, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NewMauville_Entrance_EventScript_DontOpenDoor
	msgbox NewMauville_Entrance_Text_UsedBasementKey, MSGBOX_DEFAULT
	setmetatile 3, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile0, FALSE
	setmetatile 4, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile1, FALSE
	setmetatile 5, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile2, FALSE
	setmetatile 3, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile3, TRUE
	setmetatile 4, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile4, FALSE
	setmetatile 5, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile5, TRUE
	special DrawWholeMapView
	playse SE_BANG
	setvar VAR_NEW_MAUVILLE_STATE, 1
	releaseall
	end

NewMauville_Entrance_EventScript_DontOpenDoor::
	releaseall
	end

NewMauville_Entrance_Text_DoorIsLocked:
	.string "The door is locked.$"

NewMauville_Entrance_Text_UseBasementKey:
	.string "Use the BASEMENT KEY?$"

NewMauville_Entrance_Text_UsedBasementKey:
	.string "{PLAYER} used the BASEMENT KEY.\p"
	.string "The door opened!$"

@ Fettuccine: Zeraora (Lv 40). Here from the start (reaching this room takes Surf).
@ One chance only: it's gone for good once it's caught, knocked out or run from.
NewMauville_Entrance_EventScript_SetupLegendZeraora::
	setflag FLAG_HIDE_LEGEND_ZERAORA
	goto_if_set FLAG_ZERAORA_GONE, NewMauville_Entrance_EventScript_SetupLegendZeraoraDone
	getcaughtmon SPECIES_ZERAORA
	goto_if_eq VAR_RESULT, TRUE, NewMauville_Entrance_EventScript_SetupLegendZeraoraDone
	clearflag FLAG_HIDE_LEGEND_ZERAORA
NewMauville_Entrance_EventScript_SetupLegendZeraoraDone::
	return

NewMauville_Entrance_EventScript_LegendZeraora::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZERAORA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_ZERAORA, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, NewMauville_Entrance_EventScript_CaughtLegendZeraora
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NewMauville_Entrance_EventScript_LostLegendZeraora
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewMauville_Entrance_EventScript_LostLegendZeraora
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NewMauville_Entrance_EventScript_LostLegendZeraora
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_FLED, NewMauville_Entrance_EventScript_LostLegendZeraora
	release
	end

NewMauville_Entrance_EventScript_LostLegendZeraora::
	setflag FLAG_ZERAORA_GONE
	setflag FLAG_HIDE_LEGEND_ZERAORA
	goto Common_EventScript_RemoveStaticPokemon
	end

NewMauville_Entrance_EventScript_CaughtLegendZeraora::
	setflag FLAG_HIDE_LEGEND_ZERAORA
	goto Common_EventScript_RemoveStaticPokemon
	end
