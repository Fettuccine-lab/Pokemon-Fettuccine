LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesignerDex
	goto_if_unset FLAG_ENABLE_SHIP_FARAWAY_ISLAND, LilycoveCity_CoveLilyMotel_2F_EventScript_GiveOldSeaMap
LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesignerDex::
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.string "Hey! I'm JOE FETTUCCINE, the\n"
	.string "GAME DESIGNER.\p"
	.string "Yes, like the pasta. Around here,\n"
	.string "everything is like the pasta.\p"
	.string "My cousin told me to stop spending\n"
	.string "money on POKéMON games.\p"
	.string "So I made my own!\p"
	.string "You're working on a POKéDEX? It's\n"
	.string "tough to fill, but don't give up.\p"
	.string "Fill every PASTALIA entry, then come\n"
	.string "show me. I'll make it official.$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "Whoa! This POKéDEX is completely\n"
	.string "filled!\p"
	.string "I put all those POKéMON in here, and\n"
	.string "even I never caught them all.\p"
	.string "You really must love POKéMON!\p"
	.string "Here, this makes it official!$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "Me? You're talking to me?\n"
	.string "I'm the PROGRAMMER.\p"
	.string "I wonder what the SLOTS are\n"
	.string "like here.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "I'm the GRAPHIC ARTIST! Aren't the\n"
	.string "POKéMON of PASTALIA interesting?$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.string "The girl TUBERS, they're cute, hey?\n"
	.string "To battle against a cute TUBER…\p"
	.string "Whoop, it's so awesome!\p"
	.string "And the TWINS! Aren't they cute?\n"
	.string "A 2-on-2 battle with TWINS…\p"
	.string "Whoop, it's unbearably fun!$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "The sea breeze tickles my heart.\n"
	.string "It feels wonderful here!$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "You never know when and where\n"
	.string "people will challenge you.\p"
	.string "That's why I never leave home without\n"
	.string "my GAME BOY ADVANCE.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "JOE Q: … … … … …\n"
	.string "… … … … … Zzz…\p"
	.string "… … … … … Huh?!\n"
	.string "I wasn't sleeping, I was… buffering.\p"
	.string "I came to check out this POKéMON\n"
	.string "CONTEST thing.\p"
	.string "CONTESTS aren't really my thing.\p"
	.string "But I once played SPIDER-MAN on kid\n"
	.string "mode with the door shut…\p"
	.string "So who am I to judge?\p"
	.string "{PLAYER}{KUN}, I hope you'll enjoy everything\n"
	.string "like the GYMS, CONTESTS, BATTLE TENT,\l"
	.string "the whole works!$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "JOE Q: Don't tell anyone about\n"
	.string "the kid mode thing.$"

@ Post-game: the GAME DESIGNER gives the OLD SEA MAP (Faraway Island)
LilycoveCity_CoveLilyMotel_2F_EventScript_GiveOldSeaMap::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_OldSeaMapOffer, MSGBOX_DEFAULT
	checkitemspace ITEM_OLD_SEA_MAP
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_CoveLilyMotel_2F_EventScript_GiveOldSeaMapBagFull
	giveitem ITEM_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_RECEIVED_OLD_SEA_MAP
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_OldSeaMapUseAtPort, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GiveOldSeaMapBagFull::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_OldSeaMapBagFull, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_OldSeaMapOffer:
	.string "Oh! You're the new CHAMPION!\p"
	.string "I'm JOE FETTUCCINE, the GAME DESIGNER.\p"
	.string "Want to know a secret? I hid an island\n"
	.string "in this region that nobody has ever\l"
	.string "found.\p"
	.string "Not even my testers. Here, take this\n"
	.string "OLD SEA MAP.$"

LilycoveCity_CoveLilyMotel_2F_Text_OldSeaMapUseAtPort:
	.string "Show it at the LINGUICOVE harbor. The\n"
	.string "ferry will take you to FARAWAY ISLAND.\p"
	.string "Don't tell anyone I told you!\n"
	.string "Especially not that WILDCARD guy at\l"
	.string "the castle. We've never met.$"

LilycoveCity_CoveLilyMotel_2F_Text_OldSeaMapBagFull:
	.string "Your BAG is full! Come back when you've\n"
	.string "made some room, and I'll tell you my\l"
	.string "secret.$"
