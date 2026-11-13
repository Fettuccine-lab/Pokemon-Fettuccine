LittlerootTown_ProfessorBirchsLab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_ProfessorBirchsLab_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_ProfessorBirchsLab_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_ProfessorBirchsLab_OnFrame
	.byte 0

	@ State descriptions for VAR_DEX_UPGRADE_JOHTO_STARTER_STATE
	@ 1: Beat Elite Four, Dex upgrade ready
	@ 2: Received National Dex
	@ 3: Left lab after receiving National Dex
	@ 4: Entered lab after catching all Hoenn mons
	@ 5: Birch told player to choose Johto starter
	@ 6: Chose Johto starter

	@ State descriptions for VAR_BIRCH_LAB_STATE
	@ 1: Never occurs
	@ 2: Chose starter
	@ 3: Received starter in lab
	@ 4: Defeated rival on Route 103
	@ 5: Received pokedex

LittlerootTown_ProfessorBirchsLab_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call ProfBirch_EventScript_UpdateLocation
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter
	end

LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter::
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter
	setobjectmovementtype LOCALID_BIRCHS_LAB_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectxyperm LOCALID_BIRCHS_LAB_RIVAL, 5, 10
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter::
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4
	goto LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout

LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout::
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout::
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
	setobjectmovementtype LOCALID_BIRCHS_LAB_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectxyperm LOCALID_BIRCHS_LAB_RIVAL, 5, 10
	end

LittlerootTown_ProfessorBirchsLab_OnWarp:
	map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
	.2byte 0

LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade::
	turnobject LOCALID_PLAYER, DIR_NORTH
	addobject LOCALID_BIRCHS_LAB_BIRCH
	addobject LOCALID_BIRCHS_LAB_RIVAL
	turnobject LOCALID_BIRCHS_LAB_RIVAL, DIR_NORTH
	setobjectxy LOCALID_BIRCHS_LAB_RIVAL, 5, 5
	turnobject LOCALID_BIRCHS_LAB_BIRCH, DIR_SOUTH
	setobjectxy LOCALID_BIRCHS_LAB_BIRCH, 6, 4
	turnobject LOCALID_BIRCHS_LAB_AIDE, DIR_EAST
	setobjectxy LOCALID_BIRCHS_LAB_AIDE, 10, 10
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject::
	addobject LOCALID_BIRCHS_LAB_RIVAL
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters::
	addobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL
	addobject LOCALID_BIRCHS_LAB_TOTODILE_BALL
	addobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL
	addobject LOCALID_BIRCHS_LAB_RIVAL
	turnobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL, DIR_SOUTH
	setobjectxy LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL, 8, 4
	turnobject LOCALID_BIRCHS_LAB_TOTODILE_BALL, DIR_SOUTH
	setobjectxy LOCALID_BIRCHS_LAB_TOTODILE_BALL, 9, 4
	turnobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL, DIR_SOUTH
	setobjectxy LOCALID_BIRCHS_LAB_CHIKORITA_BALL, 10, 4
	turnobject LOCALID_BIRCHS_LAB_BIRCH, DIR_SOUTH
	setobjectxy LOCALID_BIRCHS_LAB_BIRCH, 6, 4
	turnobject LOCALID_BIRCHS_LAB_RIVAL, DIR_EAST
	setobjectxy LOCALID_BIRCHS_LAB_RIVAL, 5, 5
	end

LittlerootTown_ProfessorBirchsLab_OnFrame:
	map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent
	map_script_2 VAR_BIRCH_LAB_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter
	.2byte 0

@ The starter is technically given prior to this on Route 101 by special ChooseStarter
@ This is just where the game tells you its yours and lets you nickname it
LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent::
	lockall
	bufferleadmonspeciesname STR_VAR_1
	message LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival::
	call LittlerootTown_ProfessorBirchsLab_EventScript_GiveBoxLink
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_ROUTE_101_BOY
	setvar VAR_BIRCH_LAB_STATE, 3
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent::
	lockall
	applymovement LOCALID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex
	waitmovement 0
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex
	end

LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex::
	lockall
	delay 30
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BIRCHS_LAB_BIRCH, LittlerootTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes
	waitmovement 0
	delay 20
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 20
	applymovement LOCALID_BIRCHS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayUpgradeComment
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment
	playse SE_PC_ON
	waitse
	delay 20
	applymovement LOCALID_BIRCHS_LAB_BIRCH, LittlerootTown_ProfessorBirchsLab_Movement_BirchReturnPokedex
	waitmovement 0
	applymovement LOCALID_BIRCHS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OkayAllDone, MSGBOX_DEFAULT
	@ Fettuccine: the Pokédex is already National, so Alan just backs up
	@ the data. This also switches on the National Dex for older saves.
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	call LittlerootTown_ProfessorBirchsLab_EventScript_ShowGrassyPatchWaiting2
	closemessage
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
	setvar VAR_SCOTT_BF_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayUpgradeComment::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool, MSGBOX_DEFAULT
	closemessage
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe, MSGBOX_DEFAULT
	closemessage
	return

LittlerootTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes:
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_ProfessorBirchsLab_Movement_BirchReturnPokedex:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_in_place_faster_down
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter::
	lockall
	applymovement LOCALID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter
	waitmovement 0
	call LittlerootTown_ProfessorBirchsLab_EventScript_ShowCompletedDexChoosePokemon
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_Aide::
	lock
	faceplayer
	goto_if_ge VAR_BIRCH_LAB_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter
	goto_if_set FLAG_BIRCH_AIDE_MET, LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork, MSGBOX_DEFAULT
	setflag FLAG_BIRCH_AIDE_MET
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Cyndaquil::
	release
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmonpic SPECIES_TORCHIC, 10, 3
	bufferspeciesname STR_VAR_1, SPECIES_TORCHIC
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveCyndaquil
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Totodile::
	release
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmonpic SPECIES_MUDKIP, 10, 3
	bufferspeciesname STR_VAR_1, SPECIES_MUDKIP
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveTotodile
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Chikorita::
	release
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmonpic SPECIES_TREECKO, 10, 3
	bufferspeciesname STR_VAR_1, SPECIES_TREECKO
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveChikorita
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime::
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GiveCyndaquil::
	bufferspeciesname STR_VAR_1, SPECIES_TORCHIC
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TORCHIC
	givemon SPECIES_TORCHIC, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil::
	hidemonpic
	call LittlerootTown_ProfessorBirchsLab_EventScript_ShowGrassyPatchWaiting
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	goto LittlerootTown_ProfessorBirchsLab_EventScript_AlanFirstOffer
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GiveTotodile::
	bufferspeciesname STR_VAR_1, SPECIES_MUDKIP
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MUDKIP
	givemon SPECIES_MUDKIP, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BIRCHS_LAB_TOTODILE_BALL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BIRCHS_LAB_TOTODILE_BALL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile::
	hidemonpic
	call LittlerootTown_ProfessorBirchsLab_EventScript_ShowGrassyPatchWaiting
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	goto LittlerootTown_ProfessorBirchsLab_EventScript_AlanFirstOffer
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GiveChikorita::
	bufferspeciesname STR_VAR_1, SPECIES_TREECKO
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TREECKO
	givemon SPECIES_TREECKO, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita::
	hidemonpic
	call LittlerootTown_ProfessorBirchsLab_EventScript_ShowGrassyPatchWaiting
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	goto LittlerootTown_ProfessorBirchsLab_EventScript_AlanFirstOffer
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter::
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter
	waitmessage
	waitfanfare
	return

@ In a randomizer game the Pokédex goal is any 200 different Pokémon (see HasAllHoennMons)
LittlerootTown_ProfessorBirchsLab_EventScript_ShowGrassyPatchWaiting2::
	goto_if_set FLAG_RANDOMIZER_ON, LittlerootTown_ProfessorBirchsLab_EventScript_ShowGrassyPatchWaiting2Randomizer
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_ShowGrassyPatchWaiting2Randomizer::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2Randomizer, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_ShowGrassyPatchWaiting::
	goto_if_set FLAG_RANDOMIZER_ON, LittlerootTown_ProfessorBirchsLab_EventScript_ShowGrassyPatchWaitingRandomizer
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_ShowGrassyPatchWaitingRandomizer::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaitingRandomizer, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_ShowCompletedDexChoosePokemon::
	goto_if_set FLAG_RANDOMIZER_ON, LittlerootTown_ProfessorBirchsLab_EventScript_ShowCompletedDexChoosePokemonRandomizer
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_ShowCompletedDexChoosePokemonRandomizer::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemonRandomizer, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_ShowAlanFirstOffer::
	goto_if_set FLAG_RANDOMIZER_ON, LittlerootTown_ProfessorBirchsLab_EventScript_ShowAlanFirstOfferRandomizer
	msgbox LittlerootTown_ProfessorBirchsLab_Text_AlanFirstOffer, MSGBOX_YESNO
	return

LittlerootTown_ProfessorBirchsLab_EventScript_ShowAlanFirstOfferRandomizer::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_AlanFirstOfferRandomizer, MSGBOX_YESNO
	return

@ Secret boss: offered once the player has their Hoenn starter, repeatable, no prize
LittlerootTown_ProfessorBirchsLab_EventScript_AlanFirstOffer::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ShowAlanFirstOffer
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_AlanBattle
	msgbox LittlerootTown_ProfessorBirchsLab_Text_AlanDeclined, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AlanLaterOffer::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_AlanLaterOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_AlanBattle
	msgbox LittlerootTown_ProfessorBirchsLab_Text_AlanDeclined, MSGBOX_DEFAULT
	goto LittlerootTown_ProfessorBirchsLab_EventScript_BirchRateOrRegister
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AlanBattle::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_AlanAccepted, MSGBOX_DEFAULT
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrianRootsAgainstAlan, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PROF_ALAN, LittlerootTown_ProfessorBirchsLab_Text_AlanDefeat
	msgbox LittlerootTown_ProfessorBirchsLab_Text_AlanPostBattle, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Birch::
	lock
	faceplayer
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlanLaterOffer
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting
LittlerootTown_ProfessorBirchsLab_EventScript_BirchRateOrRegister::
	goto_if_unset FLAG_HAS_MATCH_CALL, LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch
	goto LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
	end

LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ShowGrassyPatchWaiting2
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister::
	goto_if_unset FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380, ProfBirch_EventScript_RatePokedexOrRegister
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, ProfBirch_EventScript_RatePokedexOrRegister
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, ProfBirch_EventScript_RatePokedexOrRegister
	goto_if_eq VAR_BIRCH_LAB_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome, MSGBOX_DEFAULT
	release
	end

EventScript_RegisterProfBirch::
	msgbox MatchCall_Text_BirchRegisterCall, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredBirch, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	setvar VAR_REGISTER_BIRCH_STATE, 2
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex, MSGBOX_DEFAULT
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BIRCHS_LAB_RIVAL, LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls
	setvar VAR_BIRCH_LAB_STATE, 5
	setflag FLAG_ADVENTURE_STARTED
	setvar VAR_OLDALE_TOWN_STATE, 1
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
	setvar VAR_LITTLEROOT_TOWN_STATE, 3
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese, MSGBOX_DEFAULT
	giveitem ITEM_POKE_BALL, 5
	call_if_eq VAR_RESULT, FALSE, LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese, MSGBOX_DEFAULT
	giveitem ITEM_POKE_BALL, 5
	call_if_eq VAR_RESULT, FALSE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls, MSGBOX_DEFAULT
	setvar VAR_RESULT, 1
	return

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex::
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	@ Fettuccine: the Pokédex is the full National Dex from the start
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	return

LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer:
	walk_down
	walk_in_place_faster_left
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_Machine::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Rival::
	lock
	faceplayer
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly:
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_PC::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Fireplace::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Fireplace, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ComfyChair::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ComfyChair, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Bookshelf::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ScottAboardSSTidalCall::
	lockall
	pokenavcall LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall
	waitmessage
	clearflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork:
	.string "Hunh? PROF. ALAN?\p"
	.string "The PROF's away on fieldwork.\n"
	.string "Ergo, he isn't here.\p"
	.string "Oh, let me explain what fieldwork is.\p"
	.string "It is to study things in the natural\n"
	.string "environment, like fields and mountains,\l"
	.string "instead of a laboratory.\p"
	.string "The PROF isn't one for doing desk work.\n"
	.string "He's the type of person who would\l"
	.string "rather go outside and experience\l"
	.string "things than read about them here.$"

LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork:
	.string "The PROF keeps every POKéMON\n"
	.string "CENTER stocked with Jammie Dodgers\l"
	.string "from his own stash.$"

LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo:
	.string "PROF. ALAN is studying the habitats\n"
	.string "and distribution of POKéMON.\p"
	.string "He's been trying to get BRIAN to try\n"
	.string "his homemade bolognese.\p"
	.string "BRIAN says it's from a jar. It is not\n"
	.string "from a jar.$"

LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon:
	.string "PROF. ALAN: Now then, {PLAYER}{KUN}.\p"
	.string "Your father's told me all about you.\p"
	.string "He mentioned you don't have a\n"
	.string "POKéMON of your own yet.\p"
	.string "But the way you battled out there…\n"
	.string "like a seasoned pro!\p"
	.string "Must run in the family!\p"
	.string "As thanks for saving my skin, I'd\n"
	.string "like you to keep the POKéMON you\l"
	.string "used.\p"
	.string "{PLAYER} received the {STR_VAR_1}!$"

LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon:
	.string "PROF. ALAN: While you're at it, why\n"
	.string "not give that {STR_VAR_1}\l"
	.string "a nickname?$"

LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival:
	.string "PROF. ALAN: Train hard, and I\n"
	.string "reckon you'll make a cracking\l"
	.string "TRAINER.\p"
	.string "Your neighbour, BRIAN, is out\n"
	.string "training on ROUTE 103.\p"
	.string "He's a good lad, though he has some\n"
	.string "funny ideas about sauce.\p"
	.string "Reckons it all comes out of a jar.\n"
	.string "Even my bolognese. The cheek!\p"
	.string "Why don't you pop over and\n"
	.string "say hello?$"

LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou:
	.string "PROF. ALAN: Splendid!\p"
	.string "BRIAN's been a TRAINER for a while.\n"
	.string "He can show you the ropes.$"

LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay:
	.string "PROF. ALAN: Oh, come now, don't be\n"
	.string "like that.\p"
	.string "Do go and meet BRIAN.$"

LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome:
	.string "PROF. ALAN: BRIAN? Gone home,\n"
	.string "I expect.\p"
	.string "Or he's off training again…\p"
	.string "If you or your POKéMON get tired,\n"
	.string "have a rest at home.\p"
	.string "And a nice cup of tea!$"

LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex:
	.string "PROF. ALAN: Ah, {PLAYER}!\p"
	.string "I hear you beat BRIAN on your first\n"
	.string "try. Jolly good show!\p"
	.string "He brought his DUCKLETT all the way\n"
	.string "from CANADA, so he's no beginner.\p"
	.string "Here. I ordered this for my\n"
	.string "research, but I think you should\l"
	.string "have this POKéDEX.$"

LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex:
	.string "{PLAYER} received the POKéDEX!$"

LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex:
	.string "PROF. ALAN: The POKéDEX is a clever\n"
	.string "gadget that records every POKéMON\l"
	.string "you meet or catch.\p"
	.string "BRIAN has one, too.\p"
	.string "Whenever either of you catches a\n"
	.string "rare POKéMON, do come and show me!$"

LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait:
	.string "PROF. ALAN: Countless POKéMON\n"
	.string "await you!\p"
	.string "Blimey, I'm getting the itch to go\n"
	.string "out and do fieldwork again!$"

LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese:
	.string "BRIAN: Huh… So he gave you a POKéDEX,\n"
	.string "too.\p"
	.string "He gave me one to “help his research.”\p"
	.string "Fine. I'll use it to find POKéMON that\n"
	.string "live far away from all this sauce.\p"
	.string "Here. These are for you. My mom says I\n"
	.string "have to be nice to the neighbors.$"

LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls:
	.string "BRIAN: The more POKéMON I catch, the\n"
	.string "stronger my team.\p"
	.string "The stronger my team, the sooner I'm\n"
	.string "CHAMPION.\p"
	.string "And the sooner I'm CHAMPION, the\n"
	.string "sooner PASTALIA is sauce-free.$"

LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull:
	.string "Oh? Your BAG's full.$"

LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext:
	.string "BRIAN: Where should I go next…\p"
	.string "Somewhere that doesn't smell like\n"
	.string "simmering sauce.\p"
	.string "It's not even simmering. It's from a\n"
	.string "jar. They just heat it up.$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese:
	.string "BRIAN: Huh… So he gave you a POKéDEX,\n"
	.string "too.\p"
	.string "He gave me one to “help his research.”\p"
	.string "Fine. I'll use it to find POKéMON that\n"
	.string "live far away from all this sauce.\p"
	.string "Here. These are for you. My mom says I\n"
	.string "have to be nice to the neighbors.$"

LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls:
	.string "BRIAN: The more POKéMON I catch, the\n"
	.string "stronger my team.\p"
	.string "The stronger my team, the sooner I'm\n"
	.string "CHAMPION.\p"
	.string "And the sooner I'm CHAMPION, the\n"
	.string "sooner PASTALIA is sauce-free.$"

LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull:
	.string "Hey, your BAG's full.$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext:
	.string "BRIAN: Where should I go next…\p"
	.string "Somewhere that doesn't smell like\n"
	.string "simmering sauce.\p"
	.string "It's not even simmering. It's from a\n"
	.string "jar. They just heat it up.$"

LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine:
	.string "It's a serious-looking machine.\n"
	.string "The PROF must use this for research.$"

LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch:
	.string "It's a PC used for research.\n"
	.string "Better not mess around with it.$"

LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon:
	.string "It's crammed with books on POKéMON.$"

LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational:
	.string "PROF. ALAN: Now then…\p"
	.string "{PLAYER}{KUN} and BRIAN, you've both\n"
	.string "been helping me study POKéMON.\p"
	.string "Thanks to you, all sorts of new\n"
	.string "facts are coming to light.\p"
	.string "POKéMON from every corner of the\n"
	.string "world, all living in PASTALIA!\p"
	.string "Just goes to show how rich and\n"
	.string "varied PASTALIA is.\l"
	.string "Like a good bolognese!\p"
	.string "Let me back up your POKéDEX data\n"
	.string "on my PC. For science!\p"
	.string "Here, hand over your POKéDEX units.$"

LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool:
	.string "BRIAN: Don't get excited. I only came\n"
	.string "back because the PROF says there are\l"
	.string "POKéMON from other regions.\p"
	.string "Regions with NO sauce!\p"
	.string "If you find out where they're from,\n"
	.string "tell me first. I'm moving there.$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe:
	.string "BRIAN: Don't get excited. I only came\n"
	.string "back because the PROF says there are\l"
	.string "POKéMON from other regions.\p"
	.string "Regions with NO sauce!\p"
	.string "If you find out where they're from,\n"
	.string "tell me first. I'm moving there.$"

LittlerootTown_ProfessorBirchsLab_Text_OkayAllDone:
	.string "PROF. ALAN: Right, all saved!$"

LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2:
	.string "PROF. ALAN: But listen. You may be\n"
	.string "the CHAMPION, but your POKéMON\l"
	.string "journey isn't over.\p"
	.string "Fill in every PASTALIA entry in your\n"
	.string "POKéDEX and pop back to the LAB.\l"
	.string "I'll have a little something for you.\p"
	.string "And the game designer at the\n"
	.string "COVE LILY MOTEL in LINGUICOVE\l"
	.string "would love to see it, too.\p"
	.string "There's no end to the road\n"
	.string "that is POKéMON.\p"
	.string "Somewhere out there, a patch of\n"
	.string "long grass is waiting for you!$"

LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork:
	.string "BRIAN: The PROF asked me to help out\n"
	.string "here for a while.\p"
	.string "He keeps offering me his “homemade”\n"
	.string "bolognese.\p"
	.string "It's jar sauce. I can tell.$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork:
	.string "BRIAN: The PROF asked me to help out\n"
	.string "here for a while.\p"
	.string "He keeps offering me his “homemade”\n"
	.string "bolognese.\p"
	.string "It's jar sauce. I can tell.$"

LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon:
	.string "PROF. ALAN: Ah, {PLAYER}{KUN}!\n"
	.string "Let's have a look at your POKéDEX.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Well, I'll be.\n"
	.string "There's no doubt about it.\p"
	.string "You've really completed the\n"
	.string "PASTALIA POKéDEX.\p"
	.string "That's not just impressive,\n"
	.string "that's absolutely brilliant!\p"
	.string "I have a gift for you, as thanks\n"
	.string "for all your fantastic work.\p"
	.string "A rare POKéMON, hardly ever\n"
	.string "seen in the wild!\p"
	.string "You may have any one of these\n"
	.string "three!$"

LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon:
	.string "PROF. ALAN: These are rare POKéMON,\n"
	.string "hardly ever seen in the wild!\p"
	.string "You may have any one of these\n"
	.string "three!$"

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil:
	.string "PROF. ALAN: {STR_VAR_1} caught\n"
	.string "your eye!\p"
	.string "Sharp as ever!\p"
	.string "So, {STR_VAR_1} it is?$"

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile:
	.string "PROF. ALAN: {STR_VAR_1}!\p"
	.string "You know how to pick a good one.\p"
	.string "So, you'll take {STR_VAR_1}?$"

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita:
	.string "PROF. ALAN: {STR_VAR_1}!\p"
	.string "You certainly know what you're\n"
	.string "doing.\p"
	.string "So, you'll take {STR_VAR_1}?$"

LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable:
	.string "PROF. ALAN: No rush.\n"
	.string "Take your time.\p"
	.string "They're all priceless POKéMON.$"

@ Unused
LittlerootTown_ProfessorBirchsLab_Text_PickedFinePokemon:
	.string "PROF. ALAN: Marvellous!\n"
	.string "You picked a fine POKéMON!$"

LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter:
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from PROF. ALAN!$"

@ Unused
LittlerootTown_ProfessorBirchsLab_Text_NicknameJohtoStarter:
	.string "Want to give a nickname to\n"
	.string "the {STR_VAR_1} you received?$"

LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting:
	.string "PROF. ALAN: Listen, {PLAYER}{KUN}.\n"
	.string "You've completed the PASTALIA\l"
	.string "POKéDEX, but your POKéMON journey\l"
	.string "isn't over.\p"
	.string "There's no end to the road\n"
	.string "that is POKéMON.\p"
	.string "Somewhere out there, a patch of\n"
	.string "long grass is waiting for you!$"

LittlerootTown_ProfessorBirchsLab_Text_AlanFirstOffer:
	.string "PROF. ALAN: Oh, before you dash off,\n"
	.string "{PLAYER}{KUN}…\p"
	.string "I don't just study POKéMON, you know.\n"
	.string "I've a little team of my own.\p"
	.string "Never mentioned them. A gentleman\n"
	.string "doesn't like to show off.\p"
	.string "But you've filled the whole POKéDEX,\n"
	.string "so I think you've earned a proper go.\p"
	.string "What do you say? Fancy a battle?$"

LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2Randomizer:
	.string "PROF. ALAN: But listen. You may be\n"
	.string "the CHAMPION, but your POKéMON\l"
	.string "journey isn't over.\p"
	.string "Catch any 200 different POKéMON and\n"
	.string "pop back to the LAB.\l"
	.string "I'll have a little something for you.\p"
	.string "And the game designer at the\n"
	.string "COVE LILY MOTEL in LINGUICOVE\l"
	.string "would love to see it, too.\p"
	.string "There's no end to the road\n"
	.string "that is POKéMON.\p"
	.string "Somewhere out there, a patch of\n"
	.string "long grass is waiting for you!$"

LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemonRandomizer:
	.string "PROF. ALAN: Ah, {PLAYER}{KUN}!\n"
	.string "Let's have a look at your POKéDEX.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Well, I'll be.\n"
	.string "There's no doubt about it.\p"
	.string "You've really caught 200 different\n"
	.string "POKéMON.\p"
	.string "That's not just impressive,\n"
	.string "that's absolutely brilliant!\p"
	.string "I have a gift for you, as thanks\n"
	.string "for all your fantastic work.\p"
	.string "A rare POKéMON, hardly ever\n"
	.string "seen in the wild!\p"
	.string "You may have any one of these\n"
	.string "three!$"

LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaitingRandomizer:
	.string "PROF. ALAN: Listen, {PLAYER}{KUN}.\n"
	.string "You've caught 200 POKéMON, but your\l"
	.string "POKéMON journey isn't over.\p"
	.string "There's no end to the road\n"
	.string "that is POKéMON.\p"
	.string "Somewhere out there, a patch of\n"
	.string "long grass is waiting for you!$"

LittlerootTown_ProfessorBirchsLab_Text_AlanFirstOfferRandomizer:
	.string "PROF. ALAN: Oh, before you dash off,\n"
	.string "{PLAYER}{KUN}…\p"
	.string "I don't just study POKéMON, you know.\n"
	.string "I've a little team of my own.\p"
	.string "Never mentioned them. A gentleman\n"
	.string "doesn't like to show off.\p"
	.string "But you've caught 200 POKéMON, so\n"
	.string "I think you've earned a proper go.\p"
	.string "What do you say? Fancy a battle?$"

LittlerootTown_ProfessorBirchsLab_Text_AlanLaterOffer:
	.string "PROF. ALAN: Back for another round?\n"
	.string "I've only just poured a fresh one.\p"
	.string "Fancy a battle?$"

LittlerootTown_ProfessorBirchsLab_Text_AlanAccepted:
	.string "PROF. ALAN: Splendid! Let me just put\n"
	.string "down my whiskey. Carefully, now.$"

LittlerootTown_ProfessorBirchsLab_Text_AlanDeclined:
	.string "PROF. ALAN: Very sensible. I'll pour\n"
	.string "another while I wait.\p"
	.string "Come and find me when you fancy it.$"

LittlerootTown_ProfessorBirchsLab_Text_BrianRootsAgainstAlan:
	.string "BRIAN: Sorry in advance, PROF., but\n"
	.string "I'm rooting for whoever hates sauce.$"

LittlerootTown_ProfessorBirchsLab_Text_AlanDefeat:
	.string "Good heavens, well played!\n"
	.string "And I'd only had the one…$"

LittlerootTown_ProfessorBirchsLab_Text_AlanPostBattle:
	.string "PROF. ALAN: Marvellous! Best battle\n"
	.string "I've had in ages.\p"
	.string "Right. Where did I put my whiskey?\p"
	.string "Come back for another round any time.$"

LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone:
	.string "You received the promised POKéMON.\n"
	.string "Better leave the others alone.$"

@ Unused
LittlerootTown_ProfessorBirchsLab_Text_DontHaveAnyRoomForPokemon:
	.string "Oh, you don't have any room for\n"
	.string "this POKéMON.$"

LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere:
	.string "BRIAN: So you beat me. Fine.\p"
	.string "But I'm still not eating the pasta. I'm\n"
	.string "getting wings.\p"
	.string "What now, {PLAYER}? Fill the NATIONAL\n"
	.string "POKéDEX?\p"
	.string "Me, I'm training. I'll be back.$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly:
	.string "BRIAN: So you beat me. Fine.\p"
	.string "But I'm still not eating the pasta. I'm\n"
	.string "getting wings.\p"
	.string "What now, {PLAYER}? Fill the NATIONAL\n"
	.string "POKéDEX?\p"
	.string "Me, I'm training. I'll be back.$"

LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier:
	.string "BRIAN: Hey, {PLAYER}! Have you been to\n"
	.string "the BUCATINI FRONTIER?\p"
	.string "I hear the snack bar puts marinara\n"
	.string "on everything. Jar marinara.$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier:
	.string "BRIAN: Hey, {PLAYER}! Have you been to\n"
	.string "the BUCATINI FRONTIER?\p"
	.string "I hear the snack bar puts marinara\n"
	.string "on everything. Jar marinara.$"

LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "JOE Q: Hi, hi, {PLAYER}!\n"
	.string "It's me, JOE Q.\p"
	.string "I'm aboard the S.S. TIDAL now.\p"
	.string "Five hundred episodes of radio, and\n"
	.string "I've never been this excited to\l"
	.string "share news.\p"
	.string "I've found a place for you.\p"
	.string "If you're interested, board a ferry\n"
	.string "at either SPAGHETTIPORT or LINGUICOVE.\p"
	.string "I'll fill you in on the details when\n"
	.string "we meet. I'll be waiting!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

@ Fettuccine: Birch (Alan) gives the Pokemon Box Link with the starter,
@ so the player can open Pokemon Storage from the bag anywhere.
LittlerootTown_ProfessorBirchsLab_EventScript_GiveBoxLink:
	msgbox LittlerootTown_ProfessorBirchsLab_Text_TakeBoxLink, MSGBOX_DEFAULT
	giveitem ITEM_POKEMON_BOX_LINK
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BoxLinkExplained, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_Text_TakeBoxLink:
	.string "PROF. ALAN: Oh, and before you\n"
	.string "dash off, take this as well.$"

LittlerootTown_ProfessorBirchsLab_Text_BoxLinkExplained:
	.string "PROF. ALAN: That's a POKéMON BOX\n"
	.string "LINK. Open it from your BAG to use\l"
	.string "the POKéMON STORAGE SYSTEM from\l"
	.string "anywhere at all.\p"
	.string "I keep mine in my coat pocket, right\n"
	.string "next to my hip flask.\p"
	.string "Purely for medicinal purposes,\n"
	.string "of course!$"

LittlerootTown_ProfessorBirchsLab_Text_Fireplace:
	.string "A cozy fire is crackling away.\n"
	.string "It smells faintly of whiskey.$"

LittlerootTown_ProfessorBirchsLab_Text_ComfyChair:
	.string "It's PROF. ALAN's big comfy chair.\p"
	.string "There's a whiskey glass wedged\n"
	.string "down the side of the cushion.$"
