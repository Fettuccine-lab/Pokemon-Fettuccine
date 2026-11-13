EverGrandeCity_PokemonLeague_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonLeague_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

EverGrandeCity_PokemonLeague_1F_OnTransition:
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY_POKEMON_LEAGUE
	setflag FLAG_LANDMARK_POKEMON_LEAGUE
	call_if_unset FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor
	end

EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor::
	setobjectxyperm LOCALID_LEAGUE_GUARD_1, 9, 2
	setobjectxyperm LOCALID_LEAGUE_GUARD_2, 10, 2
	return

EverGrandeCity_PokemonLeague_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_LEAGUE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

EverGrandeCity_PokemonLeague_1F_EventScript_Clerk::
	lock
	faceplayer
	message EverGrandeCity_PokemonLeague_1F_Text_JasonGreeting
	waitmessage
	pokemart EverGrandeCity_PokemonLeague_1F_Pokemart
	msgbox gText_RetroSalvageGames_ThanksForShopping, MSGBOX_DEFAULT
	release
	end

	.align 2
EverGrandeCity_PokemonLeague_1F_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_TM_CLOSE_COMBAT
	.2byte ITEM_TM_FLARE_BLITZ
	.2byte ITEM_EXP_CANDY_XL
	.2byte ITEM_ABILITY_PATCH
	pokemartlistend

@ The door guards only check for FLAG_BADGE06_GET because Winonas badge is the only one that can be skipped
@ Its assumed the player has the remaining badges
EverGrandeCity_PokemonLeague_1F_EventScript_DoorGuard::
	lockall
	goto_if_set FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_GoForth
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_ge VAR_TEMP_0, 11, EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight
	call_if_le VAR_TEMP_0, 8, EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft
	message EverGrandeCity_PokemonLeague_1F_Text_MustHaveAllGymBadges
	waitmessage
	delay 120
	goto_if_unset FLAG_BADGE06_GET, EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges
	closemessage
	applymovement LOCALID_LEAGUE_GUARD_1, EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay
	applymovement LOCALID_LEAGUE_GUARD_2, EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay
	waitmovement 0
	delay 10
	playfanfare MUS_OBTAIN_BADGE
	message EverGrandeCity_PokemonLeague_1F_Text_GoForth
	waitmessage
	waitfanfare
	closemessage
	copyobjectxytoperm LOCALID_LEAGUE_GUARD_1
	copyobjectxytoperm LOCALID_LEAGUE_GUARD_2
	setflag FLAG_ENTERED_ELITE_FOUR
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight::
	applymovement LOCALID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight
	waitmovement 0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft::
	applymovement LOCALID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft
	waitmovement 0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges::
	playse SE_FAILURE
	msgbox EverGrandeCity_PokemonLeague_1F_Text_HaventObtainedAllBadges, MSGBOX_DEFAULT
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_EventScript_GoForth::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox EverGrandeCity_PokemonLeague_1F_Text_GoForth, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

@ MIKE, the former CHAMPION Brian beat, waits by the ELITE FOUR door.
@ After the HALL OF FAME he challenges the player, and can be battled again any time.
EverGrandeCity_PokemonLeague_1F_EventScript_Mike::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, EverGrandeCity_PokemonLeague_1F_EventScript_MikeChallenge
	msgbox EverGrandeCity_PokemonLeague_1F_Text_MikeBrianBeatMe, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonLeague_1F_EventScript_MikeChallenge::
	goto_if_defeated TRAINER_WALLACE, EverGrandeCity_PokemonLeague_1F_EventScript_MikeRematch
	msgbox EverGrandeCity_PokemonLeague_1F_Text_MikeChallenge, MSGBOX_YESNO
	goto EverGrandeCity_PokemonLeague_1F_EventScript_MikeBattle
	end

EverGrandeCity_PokemonLeague_1F_EventScript_MikeRematch::
	msgbox EverGrandeCity_PokemonLeague_1F_Text_MikeRematch, MSGBOX_YESNO
	goto EverGrandeCity_PokemonLeague_1F_EventScript_MikeBattle
	end

EverGrandeCity_PokemonLeague_1F_EventScript_MikeBattle::
	goto_if_eq VAR_RESULT, NO, EverGrandeCity_PokemonLeague_1F_EventScript_MikeDecline
	msgbox EverGrandeCity_PokemonLeague_1F_Text_MikeAndiamo, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_PokemonLeague_1F_Text_MikeDefeat
	msgbox EverGrandeCity_PokemonLeague_1F_Text_MikePostBattle, MSGBOX_DEFAULT
	goto_if_unset FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, EverGrandeCity_PokemonLeague_1F_EventScript_MikeGiveEonTicket
	release
	end

@ Post-game: MIKE gives the EON TICKET (Southern Island) the first time he's beaten
EverGrandeCity_PokemonLeague_1F_EventScript_MikeGiveEonTicket::
	msgbox EverGrandeCity_PokemonLeague_1F_Text_MikeEonTicketOffer, MSGBOX_DEFAULT
	checkitemspace ITEM_EON_TICKET
	goto_if_eq VAR_RESULT, FALSE, EverGrandeCity_PokemonLeague_1F_EventScript_MikeGiveEonTicketBagFull
	giveitem ITEM_EON_TICKET
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
	msgbox EverGrandeCity_PokemonLeague_1F_Text_MikeEonTicketUseAtPort, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonLeague_1F_EventScript_MikeGiveEonTicketBagFull::
	msgbox EverGrandeCity_PokemonLeague_1F_Text_MikeEonTicketBagFull, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonLeague_1F_EventScript_MikeDecline::
	msgbox EverGrandeCity_PokemonLeague_1F_Text_MikeDecline, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight:
	walk_down
	walk_left
	walk_in_place_faster_up
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft:
	walk_down
	walk_right
	walk_in_place_faster_up
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay:
	walk_left
	walk_in_place_faster_down
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay:
	walk_right
	walk_in_place_faster_down
	step_end

EverGrandeCity_PokemonLeague_1F_Text_MustHaveAllGymBadges:
	.string "Beyond this point, only those TRAINERS\n"
	.string "who have collected all the GYM BADGES\l"
	.string "are permitted to enter.\p"
	.string "TRAINER, let us confirm that you have\n"
	.string "all the GYM BADGES.$"

EverGrandeCity_PokemonLeague_1F_Text_HaventObtainedAllBadges:
	.string "You haven't obtained all the BADGES.\p"
	.string "If you're bound for the POKéMON\n"
	.string "LEAGUE, you must return with them.$"

EverGrandeCity_PokemonLeague_1F_Text_GoForth:
	.string "TRAINER! Believe in yourself and your\n"
	.string "POKéMON, and go forth!$"

EverGrandeCity_PokemonLeague_1F_Text_MikeBrianBeatMe:
	.string "MIKE: Ayyy, {PLAYER}.\p"
	.string "Yeah, you heard right. A kid from\n"
	.string "CANADA beat me. Took the CHAMPION's\l"
	.string "chair right out from under me.\p"
	.string "His ABOMASNOW froze my whole team\n"
	.string "solid. Gotta respect that.\p"
	.string "But now he says he's gonna ban sauce.\n"
	.string "Says it all comes outta a JAR!\p"
	.string "My nonna's Sunday gravy? A JAR?!\n"
	.string "Fuhgeddaboudit.\p"
	.string "Go on in there and show him what\n"
	.string "PASTALIA's made of.$"

EverGrandeCity_PokemonLeague_1F_Text_MikeChallenge:
	.string "MIKE: Ayyy, the new CHAMPION!\p"
	.string "You beat the kid who beat me.\n"
	.string "Correctamundo.\p"
	.string "But I gotta see for myself if you're\n"
	.string "the real deal.\p"
	.string "You and me, one battle. Capisce?$"

EverGrandeCity_PokemonLeague_1F_Text_MikeRematch:
	.string "MIKE: Ayyy, {PLAYER}! Back for another\n"
	.string "round?\p"
	.string "You and me, one more time. Capisce?$"

EverGrandeCity_PokemonLeague_1F_Text_MikeAndiamo:
	.string "MIKE: That's what I like to hear.\n"
	.string "Andiamo!$"

EverGrandeCity_PokemonLeague_1F_Text_MikeDefeat:
	.string "MIKE: Ayyy…\p"
	.string "Now THAT's a CHAMPION.$"

EverGrandeCity_PokemonLeague_1F_Text_MikePostBattle:
	.string "MIKE: You're the real deal, {PLAYER}.\n"
	.string "PASTALIA's in good hands.\p"
	.string "Come back anytime. I'll make you my\n"
	.string "nonna's lasagna.$"

EverGrandeCity_PokemonLeague_1F_Text_MikeDecline:
	.string "MIKE: No? Eh, take your time.\p"
	.string "I ain't goin' anywhere.$"

EverGrandeCity_PokemonLeague_1F_Text_MikeEonTicketOffer:
	.string "MIKE: Ayyy, one more thing.\p"
	.string "A buddy of mine says there's an island\n"
	.string "way down south where a rare POKéMON\l"
	.string "hangs out.\p"
	.string "You earned this. Take my EON TICKET.$"

EverGrandeCity_PokemonLeague_1F_Text_MikeEonTicketUseAtPort:
	.string "MIKE: Show it at the LINGUICOVE\n"
	.string "harbor, and the ferry'll take you to\l"
	.string "SOUTHERN ISLAND. Capisce?$"

EverGrandeCity_PokemonLeague_1F_Text_MikeEonTicketBagFull:
	.string "MIKE: Ayyy, your BAG's stuffed like a\n"
	.string "cannoli!\p"
	.string "Make some room and come see me.$"

EverGrandeCity_PokemonLeague_1F_Text_JasonGreeting:
	.string "JASON: You made it to\n"
	.string "the POKéMON LEAGUE!\p"
	.string "RETRO SALVAGE GAMES has your back.\n"
	.string "Stock up before the ELITE FOUR!$"
