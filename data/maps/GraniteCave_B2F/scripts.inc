GraniteCave_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GraniteCave_B2F_OnTransition
	.byte 0

GraniteCave_B2F_OnTransition:
	call GraniteCave_B2F_EventScript_SetupLegendMarshadow
	end

@ Fettuccine: Marshadow (Lv 15). There from the start, until it's caught or knocked out.
GraniteCave_B2F_EventScript_SetupLegendMarshadow::
	setflag FLAG_HIDE_LEGEND_MARSHADOW
	goto_if_set FLAG_MARSHADOW_GONE, GraniteCave_B2F_EventScript_SetupLegendMarshadowDone
	getcaughtmon SPECIES_MARSHADOW
	goto_if_eq VAR_RESULT, TRUE, GraniteCave_B2F_EventScript_SetupLegendMarshadowDone
	clearflag FLAG_HIDE_LEGEND_MARSHADOW
GraniteCave_B2F_EventScript_SetupLegendMarshadowDone::
	return

GraniteCave_B2F_EventScript_LegendMarshadow::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MARSHADOW, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_MARSHADOW, 15
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, GraniteCave_B2F_EventScript_CaughtLegendMarshadow
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, GraniteCave_B2F_EventScript_KnockedOutLegendMarshadow
	release
	end

@ Knocked out: gone for good. Running away or blacking out leaves it there.
GraniteCave_B2F_EventScript_KnockedOutLegendMarshadow::
	setflag FLAG_MARSHADOW_GONE
	setflag FLAG_HIDE_LEGEND_MARSHADOW
	goto Common_EventScript_RemoveStaticPokemon
	end

GraniteCave_B2F_EventScript_CaughtLegendMarshadow::
	setflag FLAG_HIDE_LEGEND_MARSHADOW
	goto Common_EventScript_RemoveStaticPokemon
	end
