Common_EventScript_PkmnCenterNurse::
	lock
	faceplayer
	incrementgamestat GAME_STAT_USED_POKECENTER
	msgbox gText_HereHaveAJammieDodger, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	call EventScript_PkmnCenterNurse_TryGiveMegaStoneCase
	call EventScript_PkmnCenterNurse_TryGiveExpShare
	goto_if_unset FLAG_POKERUS_EXPLAINED, EventScript_PkmnCenterNurse_CheckPokerus
	goto EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom
	end

EventScript_PkmnCenterNurse_TakeAndHealPkmn::
	hidefollower 0
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Turn
	waitmovement 0
	dofieldeffect FLDEFF_POKECENTER_HEAL
.if OW_UNION_DISABLE_CHECK == FALSE && OW_FLAG_MOVE_UNION_ROOM_CHECK != 0
	setflag OW_FLAG_MOVE_UNION_ROOM_CHECK
	call CableClub_OnResume
	clearflag OW_FLAG_MOVE_UNION_ROOM_CHECK
.endif
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	return

EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom::
	specialvar VAR_RESULT, PlayerNotAtTrainerHillEntrance
	goto_if_eq VAR_RESULT, 0, EventScript_PkmnCenterNurse_ReturnPkmn
	specialvar VAR_RESULT, BufferUnionRoomPlayerName
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, EventScript_PkmnCenterNurse_ReturnPkmn
	goto_if_eq VAR_0x8008, 1, EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom
	end

EventScript_PkmnCenterNurse_ReturnPkmn::
	message gText_PkmnLovedJammieDodger
	waitmessage
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	return

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom::
	goto_if_set FLAG_NURSE_UNION_ROOM_REMINDER, EventScript_PkmnCenterNurse_ReturnPkmn
	msgbox gText_PkmnLovedJammieDodger, MSGBOX_DEFAULT
	setflag FLAG_NURSE_UNION_ROOM_REMINDER
	message CableClub_Text_PlayerIsWaiting
	waitmessage
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	message gText_WeHopeToSeeYouAgain
	return

EventScript_PkmnCenterNurse_CheckPokerus::
	specialvar VAR_RESULT, IsPokerusInParty
	goto_if_eq VAR_RESULT, TRUE, EventScript_PkmnCenterNurse_ExplainPokerus
	goto_if_eq VAR_RESULT, FALSE, EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom
	end

EventScript_PkmnCenterNurse_ExplainPokerus::
	message gText_PokerusExplanation
	setflag FLAG_POKERUS_EXPLAINED
	return

Movement_PkmnCenterNurse_Bow:
	nurse_joy_bow
	delay_4
	step_end

Movement_PkmnCenterNurse_Turn:
	walk_in_place_faster_left
	step_end

@ Fettuccine: saves from before the Mega Stone Case already have the Mega
@ Ring from Sam but not the case. Hand it over here and clear the old
@ Mega Stones out of the Items pocket.
EventScript_PkmnCenterNurse_TryGiveMegaStoneCase::
	checkitem ITEM_MEGA_RING
	goto_if_eq VAR_RESULT, FALSE, EventScript_PkmnCenterNurse_TryGiveMegaStoneCaseEnd
	checkitem ITEM_MEGA_STONE_CASE
	goto_if_eq VAR_RESULT, TRUE, EventScript_PkmnCenterNurse_TryGiveMegaStoneCaseEnd
	msgbox gText_SamLeftMegaStoneCase, MSGBOX_DEFAULT
	giveitem ITEM_MEGA_STONE_CASE
	goto_if_eq VAR_RESULT, FALSE, EventScript_PkmnCenterNurse_TryGiveMegaStoneCaseEnd
	special MegaStoneCase_ClearBagStones
	msgbox gText_SamLeftMegaStoneCaseExplain, MSGBOX_DEFAULT
EventScript_PkmnCenterNurse_TryGiveMegaStoneCaseEnd:
	return

@ Fettuccine: saves from before the key item version of the Exp. Share don't
@ have it in the Key Items pocket. Hand it over here, switched on.
EventScript_PkmnCenterNurse_TryGiveExpShare::
	checkitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, TRUE, EventScript_PkmnCenterNurse_TryGiveExpShareEnd
	msgbox gText_MrGarlicLeftExpShare, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, EventScript_PkmnCenterNurse_TryGiveExpShareEnd
	setflag FLAG_EXP_SHARE_ON
	msgbox gText_MrGarlicLeftExpShareExplain, MSGBOX_DEFAULT
EventScript_PkmnCenterNurse_TryGiveExpShareEnd:
	return

gText_MrGarlicLeftExpShare:
	.string "Oh, and MR. GARLIC left this\n"
	.string "here for you!$"

gText_MrGarlicLeftExpShareExplain:
	.string "It shares EXP. Points with your whole\n"
	.string "team. Turn it off from your BAG.$"

gText_SamLeftMegaStoneCase:
	.string "Oh, and SAM left this here for you!$"

gText_SamLeftMegaStoneCaseExplain:
	.string "It holds every MEGA STONE, so the\n"
	.string "ones in your BAG went inside it.$"
