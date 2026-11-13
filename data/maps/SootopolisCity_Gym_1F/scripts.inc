SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SCOTT  @ JOE Q arrives in his street clothes
	end

SootopolisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	goto_if_lt VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

SootopolisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement LOCALID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

@ JOE Q (Scott's sprite) runs the GYM. Before a battle he spins into his
@ BATTLE DUDS (Juan's sprite), which is also the sprite he battles with.
SootopolisCity_Gym_1F_EventScript_Juan::
	lock
	faceplayer
	goto_if_defeated TRAINER_JUAN_1, SootopolisCity_Gym_1F_EventScript_JuanAlreadyBeaten
	msgbox SootopolisCity_Gym_1F_Text_JoeQGreeting, MSGBOX_DEFAULT
	closemessage
	call SootopolisCity_Gym_1F_EventScript_PutOnBattleDuds
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
SootopolisCity_Gym_1F_EventScript_JuanAlreadyBeaten::
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_JuanRematch
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanDefeated::
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	call SootopolisCity_Gym_1F_EventScript_TakeOffBattleDuds
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch::
	special HasEnoughMonsForDoubleBattle
	goto_if_ne VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS, SootopolisCity_Gym_1F_EventScript_JuanRematchBattle  @ no suit-up if he'll just send you away
	call_if_eq VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SCOTT, SootopolisCity_Gym_1F_EventScript_SuitUpForRematch
SootopolisCity_Gym_1F_EventScript_JuanRematchBattle::
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_DEFAULT
	closemessage
	call SootopolisCity_Gym_1F_EventScript_TakeOffBattleDuds
	release
	end

SootopolisCity_Gym_1F_EventScript_SuitUpForRematch::
	msgbox SootopolisCity_Gym_1F_Text_JoeQSuitUpRematch, MSGBOX_DEFAULT
	closemessage
	call SootopolisCity_Gym_1F_EventScript_PutOnBattleDuds
	return

@ The spin: speeds up, swaps to the BATTLE DUDS sprite mid-spin, then slows down.
@ VAR_OBJ_GFX_ID_0 keeps him in the DUDS when the map reloads after the battle.
SootopolisCity_Gym_1F_EventScript_PutOnBattleDuds::
	setvar VAR_0x8001, OBJ_EVENT_GFX_JUAN
	call SootopolisCity_Gym_1F_EventScript_SpinIntoOutfit
	faceplayer
	playse SE_M_SWAGGER
	applymovement LOCALID_SOOTOPOLIS_GYM_JOE_Q, Common_Movement_ExclamationMark
	waitmovement 0
	return

@ After a battle: spins back into his street clothes (Scott's sprite).
@ The spin ends facing down, toward the player.
SootopolisCity_Gym_1F_EventScript_TakeOffBattleDuds::
	setvar VAR_0x8001, OBJ_EVENT_GFX_SCOTT
	call SootopolisCity_Gym_1F_EventScript_SpinIntoOutfit
	msgbox SootopolisCity_Gym_1F_Text_BackInStreetClothes, MSGBOX_DEFAULT
	return

@ VAR_0x8001 = the outfit to change into.
SootopolisCity_Gym_1F_EventScript_SpinIntoOutfit::
	playse SE_M_DOUBLE_TEAM
	applymovement LOCALID_SOOTOPOLIS_GYM_JOE_Q, SootopolisCity_Gym_1F_Movement_SpinFaster
	waitmovement 0
	copyvar VAR_OBJ_GFX_ID_0, VAR_0x8001
	setvar VAR_0x8000, LOCALID_SOOTOPOLIS_GYM_JOE_Q
	special SetObjectEventGraphicsByLocalId
	playse SE_SHINY
	applymovement LOCALID_SOOTOPOLIS_GYM_JOE_Q, SootopolisCity_Gym_1F_Movement_SpinSlower
	waitmovement 0
	return

SootopolisCity_Gym_1F_Movement_SpinFaster:
	face_left
	delay_4
	face_up
	delay_4
	face_right
	delay_4
	face_down
	delay_4
	face_left
	delay_2
	face_up
	delay_2
	face_right
	delay_2
	face_down
	delay_2
	face_left
	delay_1
	face_up
	delay_1
	face_right
	delay_1
	face_down
	delay_1
	face_left
	delay_1
	face_up
	delay_1
	face_right
	delay_1
	face_down
	delay_1
	face_left
	face_up
	face_right
	face_down
	face_left
	face_up
	face_right
	face_down
	step_end

SootopolisCity_Gym_1F_Movement_SpinSlower:
	face_left
	face_up
	face_right
	face_down
	face_left
	face_up
	face_right
	face_down
	face_left
	delay_1
	face_up
	delay_1
	face_right
	delay_1
	face_down
	delay_1
	face_left
	delay_2
	face_up
	delay_2
	face_right
	delay_2
	face_down
	delay_2
	face_left
	delay_4
	face_up
	delay_4
	face_right
	delay_4
	face_down
	delay_8
	step_end

SootopolisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "Yo! How's it going, CHAMPION-\n"
	.string "bound {PLAYER}?\p"
	.string "SUGOPOLIS's GYM LEADER JOE Q is\n"
	.string "a master of WATER-type POKéMON.\p"
	.string "Word is, he dresses up for GYM\n"
	.string "battles. Nobody knows why.\p"
	.string "And, to get to JOE Q, an icy floor\n"
	.string "will hamper your progress…\p"
	.string "Listen, I'm sorry, but that's all the\n"
	.string "advice that I have for you.\p"
	.string "The rest of the way, you have to\n"
	.string "go for it yourself!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "Yow! You've beaten even JOE Q, who\n"
	.string "was supposedly the best in all PASTALIA!\p"
	.string "Okay! Check out your TRAINER CARD.\p"
	.string "If you've gotten all the BADGES, you're\n"
	.string "set for the POKéMON LEAGUE challenge!$"

SootopolisCity_Gym_1F_Text_JoeQGreeting:
	.string "JOE Q: Well, hi, hi, {PLAYER}{KUN}!\n"
	.string "Surprised to see me here?\p"
	.string "Here's a scoop for you, live and\n"
	.string "exclusive.\p"
	.string "Before I got into talent scouting,\n"
	.string "I was the LEADER of this GYM.\p"
	.string "I taught my little brother MIKE\n"
	.string "everything he knows about POKéMON.\p"
	.string "When I went off scouting, I left\n"
	.string "the GYM to MIKE.\p"
	.string "But MIKE moved up to bigger things,\n"
	.string "so this old man is back on the air!\p"
	.string "I've been watching you battle all\n"
	.string "over PASTALIA.\p"
	.string "Now I finally get a front-row seat.\p"
	.string "But hold on. I can't battle in my\n"
	.string "street clothes.\p"
	.string "Time to suit up in my…\n"
	.string "BATTLE DUDS!$"

SootopolisCity_Gym_1F_Text_JoeQSuitUpRematch:
	.string "JOE Q: {PLAYER}{KUN}! Back for more?\p"
	.string "Hold that thought. I can't battle\n"
	.string "in my street clothes.\p"
	.string "BATTLE DUDS, go!$"

SootopolisCity_Gym_1F_Text_BackInStreetClothes:
	.string "JOE Q: Ahh, much better.\p"
	.string "Those BATTLE DUDS were starting\n"
	.string "to pinch.$"

SootopolisCity_Gym_1F_Text_JuanIntro:
	.string "JOE Q: Ta-da!\n"
	.string "The BATTLE DUDS!\p"
	.string "Pretty slick, right? I only bust\n"
	.string "these out for GYM battles.\p"
	.string "They still fit, too. Mostly.\n"
	.string "I may have to hold my breath.\p"
	.string "Okay, {PLAYER}{KUN}, this is it.\p"
	.string "Let's find out if you're…\n"
	.string "JUST COOL ENOUGH!$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string "Ha! You beat me fair and square,\n"
	.string "BATTLE DUDS and all!\p"
	.string "Folks, you heard it here first.\n"
	.string "{PLAYER} is the real deal.\p"
	.string "I'd lend you the BATTLE DUDS, but\n"
	.string "then what would I wear?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Hahaha, I'm only kidding!\p"
	.string "Instead of the DUDS, I'll give you\n"
	.string "this. The RAIN BADGE!$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER} received the RAIN BADGE\n"
	.string "from JOE Q.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "With the RAIN BADGE, all of your\n"
	.string "POKéMON will obey your every command.\p"
	.string "The RAIN BADGE also lets you use\n"
	.string "the HM move WATERFALL to climb\l"
	.string "up rushing waterfalls.\p"
	.string "And so you never forget the day you\n"
	.string "beat the BATTLE DUDS, take this…$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "That TECHNICAL MACHINE has\n"
	.string "WATER PULSE on it.\p"
	.string "Sometimes it confuses the target\n"
	.string "with ultrasonic waves.\p"
	.string "And it was free! Never let anyone\n"
	.string "tell you a TM is worth paying for.$"

SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string "Registered GYM LEADER JOE Q\n"
	.string "in the POKéNAV.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string "JOE Q: With every BADGE in PASTALIA,\n"
	.string "there's only one place left to go.\p"
	.string "The POKéMON LEAGUE.\p"
	.string "Head to the far east of PASTALIA,\n"
	.string "to the island FETTUCCINE GRANDE.\p"
	.string "If you see my little brother MIKE\n"
	.string "out there, tell him I said hi.\p"
	.string "And tell him to call Mom.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "JOE Q: Hold on, you're still one\n"
	.string "BADGE short.\p"
	.string "If you want to take on the POKéMON\n"
	.string "LEAGUE, get the last BADGE from\l"
	.string "the GYM in FORTELLINI first.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "SUGOPOLIS CITY POKéMON GYM$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "SUGOPOLIS CITY POKéMON GYM\p"
	.string "JOE Q'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string "JOE Q: And we're back on the air!\p"
	.string "Our young typhoon has returned\n"
	.string "to put the GYM to the test again!\p"
	.string "Let's see if you're still\n"
	.string "just cool enough!$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string "Hahaha! Beaten again!\n"
	.string "These DUDS need an upgrade.$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string "JOE Q: I'd ask you to be my\n"
	.string "apprentice, but you'd say no.\p"
	.string "I'd give you my BATTLE DUDS, but\n"
	.string "you'd say no to that, too.\p"
	.string "Smart kid.\n"
	.string "They're dry-clean only.$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string "JOE Q: And we're back on the air!\p"
	.string "Our young typhoon has returned\n"
	.string "to put the GYM to the test again!\p"
	.string "Oh, wait. You've only got one\n"
	.string "POKéMON with you.\p"
	.string "Come back with two or more, and\n"
	.string "we'll do this right.$"

