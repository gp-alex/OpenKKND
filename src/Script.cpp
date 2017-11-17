#include "src/kknd.h"

#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"

#include "src/Script.h"
#include "src/ScriptEvent.h"
#include "src/Cursor.h"
#include "src/Coroutine.h"



Script1 stru_46E5B0 = { MOBD_20, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN, 0, 0, 0, 0 };
Script2 stru_46E5D8 = { MOBD_20, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN, 0x54, 0 };
Script3 stru_46E5F8 = { MOBD_SURV_DETENTION_CENTER, UNIT_Handler_Prison, SCRIPT_FUNCTION, 0, 0, 0, 0, 0, UNIT_STATS_SURV_DETENTION_CENTER, 1, 0, 0 };
Script3 stru_46E628 = { MOBD_MUTE_HOLDING_PEN, UNIT_Handler_Prison, SCRIPT_FUNCTION, 0, 0, 0, 0, 0, UNIT_STATS_MUTE_HOLDING_PENS, 2, 0, 0 };
Script3 stru_46E658 = { MOBD_MUTE_CLANHALL, UNIT_Handler_Clanhall, SCRIPT_FUNCTION, 0, 0, 0, 0, 0, UNIT_STATS_MUTE_CLANHALL, 2, 0, 0 };
Script3 stru_46E688 = { MOBD_SURV_OUTPOST, UNIT_Handler_Outpost, SCRIPT_FUNCTION, 0, 0, 0, 0, 0, UNIT_STATS_SURV_OUTPOST, 1, 0, 0 };
Script4 stru_46E6B8 = { MOBD_6_some_letters_and_symbols, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E6D0 = { MOBD_EXPLOSIONS, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E6E8 = { MOBD_23_some_fire_maybe_oil_burn, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E700 = { MOBD_MISSION_OUTCOME_MODAL, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E718 = { MOBD_MUTE_ALCHEMY_HALL, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E730 = { MOBD_MUTE_BEAST_ENCLOSURE, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E748 = { MOBD_MUTE_BLACKSMITH, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E760 = { MOBD_MUTE_CLANHALL, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E778 = { MOBD_MUTE_MENAGERIE, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E790 = { MOBD_MUTE_POWER_STATION, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E7A8 = { MOBD_MUTE_DRILLRIG, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E7C0 = { MOBD_MUTE_BERSERKER, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E7D8 = { MOBD_MUTE_CRAZY_HARRY, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E7F0 = { MOBD_MUTE_CHIEFTAN, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E808 = { MOBD_MUTE_PYROMANIAC, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E820 = { MOBD_MUTE_RIOTER, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E838 = { MOBD_MUTE_BAZOOKA, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E850 = { MOBD_MUTE_SHOTGUNNER, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E868 = { MOBD_MUTE_MEKANIK, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E880 = { MOBD_MUTE_VANDAL, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E898 = { MOBD_MUTE_MACHINEGUN_NEST, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E8B0 = { MOBD_MUTE_GRAPESHOT_TOWER, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E8C8 = { MOBD_MUTE_ROTARY_CANNON, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E8E0 = { MOBD_MUTE_GIANT_BEETLE, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E8F8 = { MOBD_MUTE_MISSILE_CRAB, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E910 = { MOBD_MUTE_MOBILE_DERRICK, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E928 = { MOBD_MUTE_DIRE_WOLF, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E940 = { MOBD_MUTE_WAR_MASTADONT, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E958 = { MOBD_MUTE_MONSTER_TRUCK, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E970 = { MOBD_MUTE_GIANT_SCORPION, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E988 = { MOBD_MUTE_BIKE_SIDECAR, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E9A0 = { MOBD_MUTE_OIL_TANKER, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E9B8 = { MOBD_MUTE_WASP, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E9D0 = { MOBD_72_looks_like_acid_spit, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46E9E8 = { MOBD_SURV_MACHINE_SHOP, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EA00 = { MOBD_SURV_OUTPOST, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EA18 = { MOBD_SURV_POWER_STATION, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EA30 = { MOBD_SURV_REPAIR_BAY, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EA48 = { MOBD_SURV_RESEARCH_LAB, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EA60 = { MOBD_SURV_DRILLRIG, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EA78 = { MOBD_SURV_BOMBER, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EA90 = { MOBD_SURV_GENERAL, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EAA8 = { MOBD_SURV_FLAMER, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EAC0 = { MOBD_SURV_RPG_LAUNCHER, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EAD8 = { MOBD_SURV_SABOTEUR, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EAF0 = { MOBD_SURV_SAPPER, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EB08 = { MOBD_SURV_SNIPER, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EB20 = { MOBD_SURV_SWAT, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EB38 = { MOBD_SURV_TECHNICIAN, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EB50 = { MOBD_SURV_RIFLEMAN, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EB68 = { MOBD_SURV_CANNON_TOWER, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EB80 = { MOBD_SURV_GUARD_TOWER, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EB98 = { MOBD_SURV_MISSILE_BATTERY, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EBB0 = { MOBD_SURV_4x4_PICKUP, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EBC8 = { MOBD_SURV_ATV, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EBE0 = { MOBD_SURV_ANACONDA_TANK, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EBF8 = { MOBD_SURV_BARRAGE_CRAFT, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EC10 = { MOBD_SURV_DIRT_BIKE, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EC28 = { MOBD_SURV_AUTOCANNON_TANK, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EC40 = { MOBD_SURV_MOBILE_DERRICK, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EC58 = { MOBD_SURV_ATV_FLAMETHROWER, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EC70 = { MOBD_SURV_OIL_TANKER, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EC88 = { MOBD_GORT, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46ECA0 = { MOBD_PLASMA_TANK, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46ECB8 = { MOBD_MECH, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46ECD0 = { MOBD_SENTINEL_DROID, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46ECE8 = { MOBD_69, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46ED00 = { MOBD_FONT_ITALIC, 0, SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46ED18 = { MOBD_FONT_ITALIC, script_credits_or_custom_mission_briefing_loop, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46ED30 = { MOBD_20, script_431E60_mobd_20_input, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46ED48 = { MOBD_20, script_443D40_mobd20, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46ED60 = { MOBD_INGAME_MENU_CONTROLS, script_433060_ingame_menu_DA000000, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46ED78 = { MOBD_SIDEBAR_BUTTONS, script_446ED0_sidebar_buttons, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46ED90 = { MOBD_MISSION_OUTCOME_MODAL, script_424CE0_mission_outcome_modal, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EDA8 = { MOBD_CURSORS, script_game_cursor_handler, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EDC0 = { MOBD_FONT_27, script_42D030_sidebar_tooltips, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EDD8 = { MOBD_CURSORS, script_43C040_cursors_handler, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EDF0 = { MOBD_FONT_26, 0, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46EE08 = { MOBD_20, 0, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script2 stru_46EE20 = { MOBD_46, script_442BB0_mobd46, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN, 0, 0 };
Script1 stru_46EE40 = { MOBD_SURV_OIL_TANKER, UNIT_Handler_OilTankerConvoy, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_TANKER_CONVOY, 1, 0, 0, 0 };
Script1 stru_46EE68 = { MOBD_SURV_GENERAL, UNIT_Handler_General, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_GENERAL, 0, 0, 0, 0 };
Script1 stru_46EE90 = { MOBD_HUT, UNIT_Handler_Hut, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_HUT, 2, 0, 0, 0 };
Script1 stru_46EEB8 = { MOBD_TECH_BUNKER, UNIT_Handler_TechBunker_2, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_TECH_BUNKER, 0, 9, 0, 0 };
Script1 stru_46EEE0 = { MOBD_20, script_424BF0_mobd_20_handler, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_LAST, 0, 0, 0, 0 };
Script1 stru_46EF08 = { MOBD_MUTE_ALCHEMY_HALL, UNIT_Handler_ResearchBuilding, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_ALCHEMY_HALL, 2, 0, 0, 0 };
Script1 stru_46EF30 = { MOBD_MUTE_BEAST_ENCLOSURE, UNIT_Handler_BeastEnclosure, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_BEAST_ENCLOSURE, 2, 0, 0, 0 };
Script1 stru_46EF58 = { MOBD_MUTE_BLACKSMITH, UNIT_Handler_Blacksmith, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_BLACKSMITH, 2, 0, 0, 0 };
Script1 stru_46EF80 = { MOBD_MUTE_MENAGERIE, UNIT_Handler_RepairStation, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_MENAGERIE, 2, 0, 0, 0 };
Script1 stru_46EFA8 = { MOBD_MUTE_POWER_STATION, UNIT_Handler_PowerStation, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_POWER_STATION, 2, 0, 0, 0 };
Script1 stru_46EFD0 = { MOBD_MUTE_DRILLRIG, UNIT_Handler_DrillRig, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_DRILL_RIG, 2, 0, 0, 0 };
Script1 stru_46EFF8 = { MOBD_MUTE_BERSERKER, UNIT_Handler_Infantry, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_BERSERKER, 2, 0, 0, 0 };
Script1 stru_46F020 = { MOBD_MUTE_CRAZY_HARRY, UNIT_Handler_Infantry, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_CRAZY_HARRY, 2, 0, 0, 0 };
Script1 stru_46F048 = { MOBD_MUTE_CHIEFTAN, UNIT_Handler_Infantry, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_KING_ZOG, 2, 0, 0, 0 };
Script1 stru_46F070 = { MOBD_MUTE_PYROMANIAC, UNIT_Handler_Infantry, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_PYROMANIAC, 2, 0, 0, 0 };
Script1 stru_46F098 = { MOBD_MUTE_RIOTER, UNIT_Handler_Infantry, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_RIOTER, 2, 0, 0, 0 };
Script1 stru_46F0C0 = { MOBD_MUTE_BAZOOKA, UNIT_Handler_Infantry, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_BAZOOKA, 2, 0, 0, 0 };
Script1 stru_46F0E8 = { MOBD_MUTE_SHOTGUNNER, UNIT_Handler_Infantry, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_SHOTGUNNER, 2, 0, 0, 0 };
Script1 stru_46F110 = { MOBD_MUTE_MEKANIK, UNIT_Handler_Infantry, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_MEKANIK, 2, 0, 0, 0 };
Script1 stru_46F138 = { MOBD_MUTE_VANDAL, UNIT_Handler_Infantry, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_VANDAL, 2, 0, 0, 0 };
Script1 stru_46F160 = { MOBD_MUTE_CHIEFTAN, UNIT_Handler_Infantry, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_WARLORD, 2, 0xFFFF, 0, 0 };
Script1 stru_46F188 = { MOBD_MUTE_OIL_TANKER, UNIT_Handler_Scout, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_TANKER, 0, 0, 0, 0 };
Script1 stru_46F1B0 = { MOBD_MUTE_MACHINEGUN_NEST, UNIT_Handler_GuardTower, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_MACHINEGUN_NEST, 2, 0, 0, 0 };
Script1 stru_46F1D8 = { MOBD_MUTE_GRAPESHOT_TOWER, UNIT_Handler_GuardTower, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_GRAPESHOT_TOWER, 2, 0, 0, 0 };
Script1 stru_46F200 = { MOBD_MUTE_ROTARY_CANNON, UNIT_Handler_GuardTower, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_ROTARY_CANNON, 2, 0, 0, 0 };
Script1 stru_46F228 = { MOBD_MUTE_GIANT_BEETLE, UNIT_Handler_Vehicle, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_GIANT_BEETLE, 2, 0, 0, 0 };
Script1 stru_46F250 = { MOBD_MUTE_MISSILE_CRAB, UNIT_Handler_Vehicle, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_MISSILE_CRAB, 2, 0, 0, 0 };
Script1 stru_46F278 = { MOBD_MUTE_MOBILE_DERRICK, UNIT_Handler_MobileDerrick, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_MOBILE_DERRICK, 2, 0, 0, 0 };
Script1 stru_46F2A0 = { MOBD_MUTE_DIRE_WOLF, UNIT_Handler_Vehicle, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_DIRE_WOLF, 2, 0, 0, 0 };
Script1 stru_46F2C8 = { MOBD_MUTE_WAR_MASTADONT, UNIT_Handler_Vehicle, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_WAR_MASTADONT, 2, 0, 0, 0 };
Script1 stru_46F2F0 = { MOBD_MUTE_CLANHALL_WAGON, UNIT_Handler_MobileOutpost, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_CLANHALL_WAGON, 0, 0, 0, 0 };
Script1 stru_46F318 = { MOBD_MUTE_MONSTER_TRUCK, UNIT_Handler_Vehicle, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MONSTER_TRUCK, 2, 0, 0, 0 };
Script1 stru_46F340 = { MOBD_MUTE_GIANT_SCORPION, UNIT_Handler_Vehicle, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_GIANT_SCORPION, 2, 0, 0, 0 };
Script1 stru_46F368 = { MOBD_MUTE_BIKE_SIDECAR, UNIT_Handler_Vehicle, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_BIKE_AND_SIDECAR, 2, 0, 0, 0 };
Script1 stru_46F390 = { MOBD_MUTE_OIL_TANKER, UNIT_Handler_OilTanker, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_TANKER, 2, 0, 0, 0 };
Script1 stru_46F3B8 = { MOBD_MUTE_WASP, 0, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_WASP, 1, 0, 0, 0 };
Script1 stru_46F3E0 = { MOBD_20, task_4269B0_mobd_20_handler, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_LAST, 0, 0, 0, 0 };
Script1 stru_46F408 = { MOBD_OIL_PATCH, UNIT_Handler_OilPatch, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_LAST, 0, 0, 0, 0 };
Script1 stru_46F430 = { MOBD_SURV_ANACONDA_TANK, UNIT_Handler_Vehicle, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_ANACONDA_TANK, 1, 0, 0, 0 };
Script1 stru_46F458 = { MOBD_SURV_MACHINE_SHOP, UNIT_Handler_MachineShop, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_MACHINE_SHOP, 1, 0, 0, 0 };
Script1 stru_46F480 = { MOBD_SURV_POWER_STATION, UNIT_Handler_PowerStation, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_POWER_STATION, 1, 0, 0, 0 };
Script1 stru_46F4A8 = { MOBD_SURV_REPAIR_BAY, UNIT_Handler_RepairStation, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_REPAIR_BAY, 1, 0, 0, 0 };
Script1 stru_46F4D0 = { MOBD_SURV_RESEARCH_LAB, UNIT_Handler_ResearchBuilding, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_RESEARCH_LAB, 1, 0, 0, 0 };
Script1 stru_46F4F8 = { MOBD_SURV_DRILLRIG, UNIT_Handler_DrillRig, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_DRILL_RIG, 1, 0, 0, 0 };
Script1 stru_46F520 = { MOBD_SURV_GENERAL, UNIT_Handler_Infantry, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_EL_PRESIDENTE, 1, 0, 0, 0 };
Script1 stru_46F548 = { MOBD_SURV_FLAMER, UNIT_Handler_Infantry, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_FLAMER, 1, 0, 0, 0 };
Script1 stru_46F570 = { MOBD_SURV_RPG_LAUNCHER, UNIT_Handler_Infantry, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_RPG_LAUNCHER, 1, 0, 0, 0 };
Script1 stru_46F598 = { MOBD_SURV_SABOTEUR, UNIT_Handler_Infantry, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_SABOTEUR, 1, 0, 0, 0 };
Script1 stru_46F5C0 = { MOBD_SURV_SAPPER, UNIT_Handler_Infantry, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_SAPPER, 1, 0, 0, 0 };
Script1 stru_46F5E8 = { MOBD_SURV_SNIPER, UNIT_Handler_Infantry, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_SNIPER, 1, 0, 0, 0 };
Script1 stru_46F610 = { MOBD_SURV_SWAT, UNIT_Handler_Infantry, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_SWAT, 1, 0, 0, 0 };
Script1 stru_46F638 = { MOBD_SURV_TECHNICIAN, UNIT_Handler_Infantry, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_TECHNICIAN, 1, 0, 0, 0 };
Script1 stru_46F660 = { MOBD_SURV_RIFLEMAN, UNIT_Handler_Infantry, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_RIFLEMAN, 1, 0, 0, 0 };
Script1 stru_46F688 = { MOBD_SURV_RIFLEMAN, UNIT_Handler_Scout, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_SCOUT, 0, 0, 0, 0 };
Script1 stru_46F6B0 = { MOBD_SURV_CANNON_TOWER, UNIT_Handler_GuardTower, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_CANNON_TOWER, 1, 0, 0, 0 };
Script1 stru_46F6D8 = { MOBD_SURV_GUARD_TOWER, UNIT_Handler_GuardTower, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_GUARD_TOWER, 1, 0, 0, 0 };
Script1 stru_46F700 = { MOBD_SURV_MISSILE_BATTERY, UNIT_Handler_GuardTower, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_MISSILE_BATTERY, 1, 0, 0, 0 };
Script1 stru_46F728 = { MOBD_SURV_4x4_PICKUP, UNIT_Handler_Vehicle, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_4x4_PICKUP, 1, 0, 0, 0 };
Script1 stru_46F750 = { MOBD_SURV_ATV, UNIT_Handler_Vehicle, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_ATV, 1, 0, 0, 0 };
Script1 stru_46F778 = { MOBD_SURV_BARRAGE_CRAFT, UNIT_Handler_Vehicle, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_BARRAGE_CRAFT, 1, 0, 0, 0 };
Script1 stru_46F7A0 = { MOBD_SURV_DIRT_BIKE, UNIT_Handler_Vehicle, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_DIRT_BIKE, 1, 0, 0, 0 };
Script1 stru_46F7C8 = { MOBD_SURV_AUTOCANNON_TANK, UNIT_Handler_Vehicle, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_AUTOCANNON_TANK, 1, 0, 0, 0 };
Script1 stru_46F7F0 = { MOBD_SURV_MOBILE_DERRICK, UNIT_Handler_MobileDerrick, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_MOBILE_DERRICK, 1, 0, 0, 0 };
Script1 stru_46F818 = { MOBD_SURV_ATV_FLAMETHROWER, UNIT_Handler_Vehicle, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_ATV_FLAMETHROWER, 1, 0, 0, 0 };
Script1 stru_46F840 = { MOBD_SURV_MOBILE_OUTPOST, UNIT_Handler_MobileOutpost, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_MOBILE_OUTPOST, 1, 0, 0, 0 };
Script1 stru_46F868 = { MOBD_SURV_OIL_TANKER, UNIT_Handler_OilTanker, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_TANKER, 1, 0, 0, 0 };
Script1 stru_46F890 = { MOBD_TECH_BUNKER, UNIT_Handler_TechBunker, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_TECH_BUNKER, 0, 0, 0, 0 };
Script1 stru_46F8B8 = { MOBD_GORT, UNIT_Handler_Vehicle, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_GORT, 1, 0, 0, 0 };
Script1 stru_46F8E0 = { MOBD_PLASMA_TANK, UNIT_Handler_Vehicle, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_PLASMA_TANK, 1, 0, 0, 0 };
Script1 stru_46F908 = { MOBD_MECH, UNIT_Handler_Vehicle, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MECH, 1, 0, 0, 0 };
Script1 stru_46F930 = { MOBD_SENTINEL_DROID, UNIT_Handler_Vehicle, SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SENTINEL_DROID, 1, 0, 0, 0 };
Script4 stru_46F958 = { MOBD_45, script_441FC0_mobd45_evt8, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46F970 = { MOBD_45, script_4421F0_mobd45_evt8, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46F988 = { MOBD_45, script_43D740_mobd45_evt17, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46F9A0 = { MOBD_45, script_43E470_mobd45_modems, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46F9B8 = { MOBD_45, script_43E230_mobd45_modems, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46F9D0 = { MOBD_45, script_43D890_mobd45, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46F9E8 = { MOBD_45, script_43E670_mobd45, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FA00 = { MOBD_45, script_43E7B0_mobd45, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FA18 = { MOBD_45, script_43E820_mobd45, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FA30 = { MOBD_45, script_443000_mobd45, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FA48 = { MOBD_45, script_443140_mobd45, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FA60 = { MOBD_45, script_443290_mobd45, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FA78 = { MOBD_45, script_43F670_mobd45, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FA90 = { MOBD_45, script_43ED60_mobd45_modems, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FAA8 = { MOBD_45, script_43F0E0_mobd45_modems, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FAC0 = { MOBD_45, script_43F520_mobd45, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FAD8 = { MOBD_45, script_43EE90_mobd45, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FAF0 = { MOBD_45, script_43F330_mobd45, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FB08 = { MOBD_45, script_43D5F0_mobd45, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FB20 = { MOBD_45, script_43D090_mobd45_directx_ipx, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FB38 = { MOBD_45, script_43D430_mobd45_directx_modem, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FB50 = { MOBD_45, script_43D270_mobd45_directx_serial, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FB68 = { MOBD_45, (void(*)(Script *))nullsub_1, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FB80 = { MOBD_45, script_43CF50_mobd45, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FB98 = { MOBD_45, script_43CE30_mobd45_begin_mute_campaign, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FBB0 = { MOBD_45, script_43CD20_mobd45_begin_surv_campaign, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FBC8 = { MOBD_45, script_43FDE0_mobd45, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FBE0 = { MOBD_45, script_43FF30_mobd45, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FBF8 = { MOBD_45, script_4402A0_mobd45_evt5, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FC10 = { MOBD_45, script_442580_mobd45_evt17, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FC28 = { MOBD_45, script_4428C0_mobd45_evt6, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FC40 = { MOBD_45, script_4404D0_mobd45_evt8, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FC58 = { MOBD_45, script_441940_mobd45_evt17, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FC70 = { MOBD_45, script_441CE0_mobd45_evt8, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FC88 = { MOBD_45, script_4426D0_mobd45_evt6, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FCA0 = { MOBD_79, script_mobd79_evt1__main_menu_quit, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FCB8 = { MOBD_79, script_mobd79_evt19__main_menu_load, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FCD0 = { MOBD_79, script_mobd79_evt1__main_menu_multiplayer, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
Script4 stru_46FCE8 = { MOBD_79, script_mobd79_evt1__main_menu_new_game, SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };

Script4 *scripts[196] =
{
    (Script4 *)&stru_46E5B0,
    (Script4 *)&stru_46E5D8,
    (Script4 *)&stru_46E5F8,
    (Script4 *)&stru_46E628,
    (Script4 *)&stru_46E658,
    (Script4 *)&stru_46E688,
    &stru_46E6B8,
    &stru_46E6D0,
    &stru_46E6E8,
    &stru_46E700,
    &stru_46E718,
    &stru_46E730,
    &stru_46E748,
    &stru_46E760,
    &stru_46E778,
    &stru_46E790,
    &stru_46E7A8,
    &stru_46E7C0,
    &stru_46E7D8,
    &stru_46E7F0,
    &stru_46E808,
    &stru_46E820,
    &stru_46E838,
    &stru_46E850,
    &stru_46E868,
    &stru_46E880,
    &stru_46E898,
    &stru_46E8B0,
    &stru_46E8C8,
    &stru_46E8E0,
    &stru_46E8F8,
    &stru_46E910,
    &stru_46E928,
    &stru_46E940,
    &stru_46E958,
    &stru_46E970,
    &stru_46E988,
    &stru_46E9A0,
    &stru_46E9B8,
    &stru_46E9D0,
    &stru_46E9E8,
    &stru_46EA00,
    &stru_46EA18,
    &stru_46EA30,
    &stru_46EA48,
    &stru_46EA60,
    &stru_46EA78,
    &stru_46EA90,
    &stru_46EAA8,
    &stru_46EAC0,
    &stru_46EAD8,
    &stru_46EAF0,
    &stru_46EB08,
    &stru_46EB20,
    &stru_46EB38,
    &stru_46EB50,
    &stru_46EB68,
    &stru_46EB80,
    &stru_46EB98,
    &stru_46EBB0,
    &stru_46EBC8,
    &stru_46EBE0,
    &stru_46EBF8,
    &stru_46EC10,
    &stru_46EC28,
    &stru_46EC40,
    &stru_46EC58,
    &stru_46EC70,
    &stru_46EC88,
    &stru_46ECA0,
    &stru_46ECB8,
    &stru_46ECD0,
    &stru_46ECE8,
    &stru_46ED00,
    &stru_46ED18,
    &stru_46ED30,
    &stru_46ED48,
    &stru_46ED60,
    &stru_46ED78,
    &stru_46ED90,
    &stru_46EDA8,
    &stru_46EDC0,
    &stru_46EDD8,
    &stru_46EDF0,
    &stru_46EE08,
    (Script4 *)&stru_46EE20,
    (Script4 *)&stru_46EE40,
    (Script4 *)&stru_46EE68,
    (Script4 *)&stru_46EE90,
    (Script4 *)&stru_46EEB8,
    (Script4 *)&stru_46EEE0,
    (Script4 *)&stru_46EF08,
    (Script4 *)&stru_46EF30,
    (Script4 *)&stru_46EF58,
    (Script4 *)&stru_46EF80,
    (Script4 *)&stru_46EFA8,
    (Script4 *)&stru_46EFD0,
    (Script4 *)&stru_46EFF8,
    (Script4 *)&stru_46F020,
    (Script4 *)&stru_46F048,
    (Script4 *)&stru_46F070,
    (Script4 *)&stru_46F098,
    (Script4 *)&stru_46F0C0,
    (Script4 *)&stru_46F0E8,
    (Script4 *)&stru_46F110,
    (Script4 *)&stru_46F138,
    (Script4 *)&stru_46F160,
    (Script4 *)&stru_46F188,
    (Script4 *)&stru_46F1B0,
    (Script4 *)&stru_46F1D8,
    (Script4 *)&stru_46F200,
    (Script4 *)&stru_46F228,
    (Script4 *)&stru_46F250,
    (Script4 *)&stru_46F278,
    (Script4 *)&stru_46F2A0,
    (Script4 *)&stru_46F2C8,
    (Script4 *)&stru_46F2F0,
    (Script4 *)&stru_46F318,
    (Script4 *)&stru_46F340,
    (Script4 *)&stru_46F368,
    (Script4 *)&stru_46F390,
    (Script4 *)&stru_46F3B8,
    (Script4 *)&stru_46F3E0,
    (Script4 *)&stru_46F408,
    (Script4 *)&stru_46F430,
    (Script4 *)&stru_46F458,
    (Script4 *)&stru_46F480,
    (Script4 *)&stru_46F4A8,
    (Script4 *)&stru_46F4D0,
    (Script4 *)&stru_46F4F8,
    (Script4 *)&stru_46F520,
    (Script4 *)&stru_46F548,
    (Script4 *)&stru_46F570,
    (Script4 *)&stru_46F598,
    (Script4 *)&stru_46F5C0,
    (Script4 *)&stru_46F5E8,
    (Script4 *)&stru_46F610,
    (Script4 *)&stru_46F638,
    (Script4 *)&stru_46F660,
    (Script4 *)&stru_46F688,
    (Script4 *)&stru_46F6B0,
    (Script4 *)&stru_46F6D8,
    (Script4 *)&stru_46F700,
    (Script4 *)&stru_46F728,
    (Script4 *)&stru_46F750,
    (Script4 *)&stru_46F778,
    (Script4 *)&stru_46F7A0,
    (Script4 *)&stru_46F7C8,
    (Script4 *)&stru_46F7F0,
    (Script4 *)&stru_46F818,
    (Script4 *)&stru_46F840,
    (Script4 *)&stru_46F868,
    (Script4 *)&stru_46F890,
    (Script4 *)&stru_46F8B8,
    (Script4 *)&stru_46F8E0,
    (Script4 *)&stru_46F908,
    (Script4 *)&stru_46F930,
    &stru_46F958,
    &stru_46F970,
    &stru_46F988,
    &stru_46F9A0,
    &stru_46F9B8,
    &stru_46F9D0,
    &stru_46F9E8,
    &stru_46FA00,
    &stru_46FA18,
    &stru_46FA30,
    &stru_46FA48,
    &stru_46FA60,
    &stru_46FA78,
    &stru_46FA90,
    &stru_46FAA8,
    &stru_46FAC0,
    &stru_46FAD8,
    &stru_46FAF0,
    &stru_46FB08,
    &stru_46FB20,
    &stru_46FB38,
    &stru_46FB50,
    &stru_46FB68,
    &stru_46FB80,
    &stru_46FB98,
    &stru_46FBB0,
    &stru_46FBC8,
    &stru_46FBE0,
    &stru_46FBF8,
    &stru_46FC10,
    &stru_46FC28,
    &stru_46FC40,
    &stru_46FC58,
    &stru_46FC70,
    &stru_46FC88,
    &stru_46FCA0,
    &stru_46FCB8,
    &stru_46FCD0,
    &stru_46FCE8
};




Script *script_execute_list_first()
{
    return script_execute_list;
}

Script *script_execute_list_end()
{
    return (Script *)&script_execute_list;
}

bool script_execute_list_prepend(Script *script)
{
    auto head = script_execute_list_first();
    head->prev = script;

    script->next = head;
    script->prev = script_execute_list_end();

    script_execute_list = script;

    return true;
}



//----- (00445170) --------------------------------------------------------
bool script_list_alloc(int coroutine_stack_size)
{
    int v1; // esi@1
    Script *result; // eax@3
    int v3; // ecx@5

    v1 = coroutine_stack_size;
    if (!coroutine_stack_size)
        v1 = 1048576;
    result = (Script *)script_event_list_alloc();
    if (result)
    {
        result = (Script *)malloc(0x21340u);
        script_list = result;
        if (result)
        {
            v3 = 0;
            do
            {
                result[v3].next = &result[v3 + 1];
                result = script_list;
                ++v3;
            } while (v3 < 1999);
            script_list[1999].next = 0;
            script_list_free_pool = script_list;
            script_execute_list = (Script *)&script_execute_list;
            script_list_47C714 = (Script *)&script_execute_list;
            result = (Script *)coroutine_list_alloc();
            if (result)
            {
                coroutine_default_stack_size = v1;
                coroutine_current = coroutine_list_head;
                is_coroutine_list_initialization_failed = 0;
                result = (Script *)1;
            }
        }
    }
    return (BOOL)result;
}

//----- (00445210) --------------------------------------------------------
Script *script_create_coroutine_impl(enum SCRIPT_TYPE type, void(*handler)(Script *), int stack_size, const char *debug_handler_name)
{
    Script *v3; // esi@1

    v3 = script_list_free_pool;
    if (script_list_free_pool)
    {
        script_list_free_pool = script_list_free_pool->next;

        memset(v3, SCRIPT_COROUTINE, sizeof(Script));
        v3->script_type = type;
        v3->routine_type = SCRIPT_COROUTINE;

        auto coroutine = couroutine_create(coroutine_main, debug_handler_name);
        v3->handler = (void(*)(Script *))coroutine;

        if (coroutine)
        {
            task_creation_handler = handler;
            task_creation_handler_arg = v3;

            script_execute_list_prepend(v3);

            // call coroutine_main to queue up execution of  task_creation_handler( task_creation_handler_arg )
            coroutine->resume();

            return v3;
        }
    }

    return nullptr;
}

//----- (004452B0) --------------------------------------------------------
Script *script_create_function(enum SCRIPT_TYPE type, void(*function)(Script *))
{
    Script *v2; // esi@1
    Script *result; // eax@2

    v2 = script_list_free_pool;
    if (script_list_free_pool)
    {
        script_list_free_pool = script_list_free_pool->next;
        result = 0;
        memset(v2, 0, sizeof(Script));
        v2->script_type = type;
        v2->routine_type = SCRIPT_FUNCTION;
        v2->handler = function;
        if (function)
        {
            script_execute_list_prepend(v2);

            result = v2;
        }
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (00445310) --------------------------------------------------------
void script_deinit(Script *a1)
{
    Script *v1; // edi@1
    ScriptLocalObject *v2; // eax@1
    ScriptLocalObject *v3; // esi@2

    v1 = a1;
    v2 = a1->locals_list;
    if (v2)
    {
        do
        {
            v3 = v2->next;
            free(v2);
            v2 = v3;
        } while (v3);
    }
    script_discard_all_events(v1);
    v1->prev->next = v1->next;
    v1->next->prev = v1->prev;
    v1->next = script_list_free_pool;
    script_list_free_pool = v1;
    if (v1->routine_type == SCRIPT_COROUTINE)
        coroutine_list_remove((Coroutine *)v1->handler);
    v1->handler = 0;
}

//----- (00445370) --------------------------------------------------------
int script_445370_yield_to_main_thread(Script *a1, int flags, int a3)
{
    int v5; // eax@8
    unsigned int v6; // eax@8

    if (flags & 0x40000000 && a1->event_list)
    {
        int v4 = a1->flags_20 | 0x40000000;
        a1->flags_20 = v4;
        a1->field_24 |= v4;
    }
    if (flags & 0x80000000)
    {
        if (a3)
            a1->field_14 = a3;
        if (!a1->field_14)
        {
            a1->field_28 = 0;
            a1->field_24 |= 0x80000000;
            int v6 = a1->flags_20 | 0x80000000;
            a1->flags_20 = 0;
            return flags & v6;
        }
    }
    else if (a3)
    {
        a1->field_2C |= a3;
    }

    a1->flags_20 = 0;
    a1->field_28 = flags;
    if (a1->routine_type == SCRIPT_COROUTINE)
    {
        coroutine_list_head->resume();
        a1->field_28 = 0;
        a1->field_2C = 0;
    }
    return a1->flags_20;
}

//----- (00445400) --------------------------------------------------------
void *script_create_local_object(Script *a1, int size)
{
    Script *v2; // esi@1
    ScriptLocalObject *object; // eax@1
    ScriptLocalObject *v4; // ecx@2
    ScriptLocalObject *v5; // ecx@2

    v2 = a1;
    object = (ScriptLocalObject *)malloc(size + 8);
    if (object)
    {
        v4 = v2->locals_list;
        object->prev = 0;
        object->next = v4;
        v5 = v2->locals_list;
        if (v5)
            v5->prev = object;
        v2->locals_list = object;
        object = (ScriptLocalObject *)((char *)object + 8);
    }
    return object;
}

//----- (00445440) --------------------------------------------------------
void script_free_local_object(Script *a1, void *data)
{
    ScriptLocalObject *v2; // eax@1
    ScriptLocalObject **prev; // edx@1

    v2 = CONTAINING_RECORD(data, ScriptLocalObject, data);
    prev = (ScriptLocalObject **)*((_DWORD *)data - 1);
    if (prev)
        *prev = v2->next;
    else
        a1->locals_list = v2->next;
    if (v2->next)
        v2->next->prev = v2->prev;
    free(v2);
}

//----- (00445470) --------------------------------------------------------
void script_yield(Script *a1)
{
    int v2; // eax@1

    v2 = a1->flags_20 | 0x20000000;
    a1->flags_20 = v2;
    a1->field_24 |= v2;
    if (a1->routine_type == SCRIPT_COROUTINE)
        coroutine_list_head->resume();
}

//----- (004454A0) --------------------------------------------------------
void script_list_update()
{
    Script *i; // esi@1
    Script *v1; // edi@3
    ScriptLocalObject *v2; // eax@3
    ScriptLocalObject *v3; // ebx@4
    signed __int16 v4; // ax@9
    int v5; // eax@12
    int v6; // eax@13
    int v7; // ecx@14
    unsigned int v8; // eax@14
    int v9; // ecx@15
    int v10; // eax@16

    for (i = script_execute_list_first(); i != script_execute_list_end(); i = i->next)
    {
        if (i->flags_20 & 0x20000000)
        {
            i = i->prev;
            v1 = i->next;
            v2 = i->next->locals_list;
            if (v2)
            {
                do
                {
                    v3 = v2->next;
                    free(v2);
                    v2 = v3;
                } while (v3);
            }
            script_discard_all_events(v1);
            v1->prev->next = v1->next;
            v1->next->prev = v1->prev;
            v1->next = script_list_free_pool;
            script_list_free_pool = v1;
            if (v1->routine_type == SCRIPT_COROUTINE)
                coroutine_list_remove((Coroutine *)v1->handler);
            v1->handler = 0;
        }
        else
        {
            if (is_coroutine_list_initialization_failed)
                v4 = i->field_1C & 1;
            else
                v4 = 1;
            if (v4)
            {
                v5 = i->field_14;
                if (v5)
                {
                    v6 = v5 - 1;
                    i->field_14 = v6;
                    if (!v6)
                    {
                        v7 = i->field_24;
                        v8 = i->flags_20 | 0x80000000;
                        i->flags_20 = v8;
                        i->field_24 = v8 | v7;
                    }
                }
                v9 = i->field_28;
                if (!v9 || (v10 = i->flags_20, v9 & v10) || (int)i->field_2C & ~v10)
                {
                    switch (i->routine_type)
                    {
                    case SCRIPT_COROUTINE:
                        ((Coroutine *)i->handler)->resume();
                        break;

                    case SCRIPT_FUNCTION:
                        script_execute(i);
                        break;

                    default: __debugbreak();
                    }
                }
            }
        }
    }
}

//----- (004455A0) --------------------------------------------------------
void script_list_free()
{
    Script *v0; // ebx@2
    Script *v1; // esi@4
    ScriptLocalObject *v2; // eax@4
    ScriptLocalObject *v3; // edi@5

    if (script_list)
    {
        v0 = script_execute_list_first();
        if (coroutine_current == coroutine_list_head)
        {
            if (v0 != script_execute_list_end())
            {
                do
                {
                    v1 = v0;
                    v0 = v0->next;
                    v2 = v1->locals_list;
                    if (v2)
                    {
                        do
                        {
                            v3 = v2->next;
                            free(v2);
                            v2 = v3;
                        } while (v3);
                    }
                    script_discard_all_events(v1);
                    v1->prev->next = v1->next;
                    v1->next->prev = v1->prev;
                    v1->next = script_list_free_pool;
                    script_list_free_pool = v1;
                    if (v1->routine_type == SCRIPT_COROUTINE)
                        coroutine_list_remove((Coroutine *)v1->handler);
                    v1->handler = 0;
                } while ((Script **)v0 != &script_execute_list);
            }
            free(script_list);
            script_list = 0;
            coroutine_list_free();
            script_event_list_free();
        }
    }
}