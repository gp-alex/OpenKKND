#include "src/_unsorted_data.h"
#include "src/_unsorted_functions.h"

#include "src/Render.h"

_UNKNOWN loc_45D19B; // weak
_UNKNOWN loc_45D1A4; // weak
_UNKNOWN loc_45D267; // weak
int sys_colors_elements = 0;
int kknd_sve_array_463070[15] = { 35, 62, 93, 42, 54, 12, 65, 89, 21, 30, 210, 87, 55, 66, 42 };
int kknd_sve_array_4630AC[15] = { 77, 24, 84, 36, 20, 43, 72, 20, 5, 89, 189, 233, 91, 21, 13 };
int dword_4630E8 = 2273464000; // weak
GUID netz_463DE0 = { 2638611840u, 43042u, 4559u,{ 150u, 12u, 0u, 128u, 199u, 83u, 78u, 130u } };
char asc_464068[4] = "#:\\"; // weak
BasicProductionOption mute_default_buildings[6] =
{
	{ 1, UNIT_STATS_MUTE_CLANHALL, 2688 },
	{ 64, UNIT_STATS_MUTE_BEAST_ENCLOSURE, 2496 },
	{ 32, UNIT_STATS_MUTE_POWER_STATION, 2672 },
	{ 2, UNIT_STATS_MUTE_BLACKSMITH, 2696 },
	{ 16, UNIT_STATS_MUTE_ALCHEMY_HALL, 2664 },
	{ 4, UNIT_STATS_MUTE_MENAGERIE, 2680 }
};
BasicProductionOption mute_default_infantry[3] =
{
	{ 262144, UNIT_STATS_MUTE_BERSERKER, 2808 },
	{ 1048576, UNIT_STATS_MUTE_SHOTGUNNER, 2792 },
	{ 524288, UNIT_STATS_MUTE_MEKANIK, 2776 }
};
stru7 _4640E0_stru7_array[20] =
{
	{ 1, 2, NULL, NULL },
	{ 0, 1, NULL, &sub_404530 },
	{ 0, 1, NULL, &sub_404760 },
	{ 0, 1, NULL, &sub_4047E0 },
	{ 0, 1, NULL, &sub_404870 },
	{ 0, 1, NULL, &sub_404900 },
	{ 0, 1, NULL, &sub_4049D0 },
	{ 0, 1, NULL, &sub_404760 },
	{ 0, 1, NULL, &sub_404530 },
	{ 0, 1, NULL, &sub_404530 },
	{ 0, 1, NULL, &sub_404530 },
	{ 0, 1, NULL, &sub_404530 },
	{ 0, 1, NULL, &sub_404530 },
	{ 0, 1, NULL, &sub_404AA0 },
	{ 0, 1, NULL, &sub_404B80 },
	{ 0, 1, NULL, &sub_404530 },
	{ 0, 0, NULL, NULL },
	{ 5, 0, NULL, NULL },
	{ 2, 0, &sub_404C60, NULL },
	{ 0, 4, NULL, &sub_404530 }
};
char BOXD[] = "BOXD"; // idb
char aSSS[] = "%s's %s"; // idb
Vec2 _464230_tankerconvoy_checkpoints_surv07[18] =
{
	{ 5695, 685 },
	{ 5606, 596 },
	{ 4901, 596 },
	{ 4804, 500 },
	{ 4436, 501 },
	{ 4159, 689 },
	{ 3332, 689 },
	{ 3226, 785 },
	{ 2781, 786 },
	{ 2681, 686 },
	{ 2422, 685 },
	{ 2335, 598 },
	{ 1885, 599 },
	{ 1631, 785 },
	{ 989, 785 },
	{ 897, 693 },
	{ 100, 692 },
	{ 34, 692 }
};
Vec2 _4642C0_tankerconvoy_checkpoints_mute08[30] =
{
	{ 421, 2480 },
	{ 418, 2087 },
	{ 796, 2084 },
	{ 874, 2014 },
	{ 814, 1788 },
	{ 920, 1695 },
	{ 924, 1527 },
	{ 868, 1387 },
	{ 909, 1206 },
	{ 832, 1046 },
	{ 873, 842 },
	{ 902, 671 },
	{ 871, 465 },
	{ 997, 351 },
	{ 1204, 199 },
	{ 1600, 1224 },
	{ 1628, 1002 },
	{ 1100, 918 },
	{ 820, 1148 },
	{ 760, 1616 },
	{ 1478, 1762 },
	{ 1600, 1224 },
	{ 1628, 1002 },
	{ 1100, 918 },
	{ 820, 1148 },
	{ 760, 1616 },
	{ 1600, 1224 },
	{ 1628, 1002 },
	{ 1100, 918 },
	{ 820, 1148 }
};
char *credits[117] =
{
	"%Publisher",
	"Alfred Milgrom",
	"%Executive Producer",
	"Adam Lancman",
	"%Producer",
	"David Giles",
	"%Associate Producer",
	"Justin Halliday",
	"%Technical Director",
	"Iain Cartwright",
	"Andrew Carter",
	"%Programming",
	"Paul Baulch",
	"Andrew Scott",
	"Shane Lontis",
	"Toby Charlton",
	"Louis Solomon",
	"Brian Post",
	"Hien Tran",
	"%Opponent AI Programming",
	"Paul Baulch",
	"%Network Programming",
	"Louis Solomon",
	"%Design",
	"Shane Collier",
	"David Giles",
	"%Sprite Artist",
	"Daniel Tonkin",
	"%Background Artist",
	"John Tsiglev",
	"%Superstructure Artist",
	"Damian Borg",
	"Russell Murchie",
	"%Cinema Artists",
	"Daniel Tonkin",
	"Damian Borg",
	"%Additional Artwork",
	"Toby Charlton",
	"Craig Duturbure",
	"Paul Baulch",
	"Adam Ryan",
	"Justin Halliday",
	"%Mission Designers",
	"Justin Halliday",
	"Brian Uniacke",
	"Ian Malcolm",
	"Daniel Walker",
	"%Script Writer",
	"Craig Duturbure",
	"%Lead Testers",
	"Shane Collier",
	"Andrew Buttery",
	"%Quality Assurance",
	"Leigh Reynolds",
	"Toby Couchman",
	"Alex McNeilly",
	"Ashley Parker",
	"Mike Cody",
	"Brian Pulliam",
	"Karen Tarantino",
	"Rodd Karp",
	"Joel Skirvin",
	"Michael Alsept",
	"Christopher Mason",
	"Zac Evans",
	"Rhys Quinert",
	"Daniel Walters",
	"Damon Fredrickson",
	"%Manual Writer",
	"Craig Duturbure",
	"%Manual Illustrator",
	"Daniel Tonkin",
	"%Localisation Coordinator",
	"Ben Palmer",
	"%Technical Assistance",
	"Adrian Thewlis",
	"Brian Post",
	"%Music and Sound",
	"Marshall Parker",
	"Gavin Parker",
	"    and",
	"Cameron Brown",
	"%On-line Editing",
	"Digiline",
	"%Cast",
	"Matthew King",
	"Kirk Alexander",
	"Christopher Schlusser",
	"Linda Ross",
	"%December Films",
	"Stuart Menzies",
	"David Stevens",
	"Georgina Campbell",
	"Andrew Butt",
	"Jimmy Hunt",
	"Nic Dorning",
	"Rose Chong",
	"Anne Maree Holley",
	"Fiona Munday",
	"Georgia Cordukes",
	"%Set Construction by Illusions",
	"%Casting by Chameleon",
	"%Electronic Arts Team",
	"Darren MacBeth",
	"Michael DePlater",
	"George Fidler",
	"%Additional Thanks To",
	"Kevin 'Zaph ' Burfitt",
	"Cameron Brown",
	"Simon Hart",
	"Tim Bos",
	"%  ",
	"%  ",
	"%  ",
	"%  ",
	"%  ",
	"%  "
}; // weak
char *off_464ACC[100] =
{
	"Brian Post",
	"Hien Tran",
	"%Opponent AI Programming",
	"Paul Baulch",
	"%Network Programming",
	"Louis Solomon",
	"%Design",
	"Shane Collier",
	"David Giles",
	"%Sprite Artist",
	"Daniel Tonkin",
	"%Background Artist",
	"John Tsiglev",
	"%Superstructure Artist",
	"Damian Borg",
	"Russell Murchie",
	"%Cinema Artists",
	"Daniel Tonkin",
	"Damian Borg",
	"%Additional Artwork",
	"Toby Charlton",
	"Craig Duturbure",
	"Paul Baulch",
	"Adam Ryan",
	"Justin Halliday",
	"%Mission Designers",
	"Justin Halliday",
	"Brian Uniacke",
	"Ian Malcolm",
	"Daniel Walker",
	"%Script Writer",
	"Craig Duturbure",
	"%Lead Testers",
	"Shane Collier",
	"Andrew Buttery",
	"%Quality Assurance",
	"Leigh Reynolds",
	"Toby Couchman",
	"Alex McNeilly",
	"Ashley Parker",
	"Mike Cody",
	"Brian Pulliam",
	"Karen Tarantino",
	"Rodd Karp",
	"Joel Skirvin",
	"Michael Alsept",
	"Christopher Mason",
	"Zac Evans",
	"Rhys Quinert",
	"Daniel Walters",
	"Damon Fredrickson",
	"%Manual Writer",
	"Craig Duturbure",
	"%Manual Illustrator",
	"Daniel Tonkin",
	"%Localisation Coordinator",
	"Ben Palmer",
	"%Technical Assistance",
	"Adrian Thewlis",
	"Brian Post",
	"%Music and Sound",
	"Marshall Parker",
	"Gavin Parker",
	"    and",
	"Cameron Brown",
	"%On-line Editing",
	"Digiline",
	"%Cast",
	"Matthew King",
	"Kirk Alexander",
	"Christopher Schlusser",
	"Linda Ross",
	"%December Films",
	"Stuart Menzies",
	"David Stevens",
	"Georgina Campbell",
	"Andrew Butt",
	"Jimmy Hunt",
	"Nic Dorning",
	"Rose Chong",
	"Anne Maree Holley",
	"Fiona Munday",
	"Georgia Cordukes",
	"%Set Construction by Illusions",
	"%Casting by Chameleon",
	"%Electronic Arts Team",
	"Darren MacBeth",
	"Michael DePlater",
	"George Fidler",
	"%Additional Thanks To",
	"Kevin 'Zaph ' Burfitt",
	"Cameron Brown",
	"Simon Hart",
	"Tim Bos",
	"%  ",
	"%  ",
	"%  ",
	"%  ",
	"%  ",
	"%  "
}; // weak
char asc_464C60[39] = "                                      ";
char asc_464C88[] = "\n"; // idb
char CPLC[] = "CPLC"; // idb
enum UNIT_ID mute_prison_spawns_table[10] =
{
	UNIT_STATS_MUTE_BERSERKER,
	UNIT_STATS_MUTE_BERSERKER,
	UNIT_STATS_MUTE_BERSERKER,
	UNIT_STATS_MUTE_PYROMANIAC,
	UNIT_STATS_MUTE_PYROMANIAC,
	UNIT_STATS_MUTE_SHOTGUNNER,
	UNIT_STATS_MUTE_SHOTGUNNER,
	UNIT_STATS_MUTE_SHOTGUNNER,
	UNIT_STATS_MUTE_RIOTER,
	UNIT_STATS_MUTE_RIOTER
};
enum UNIT_ID surv_prison_spawns_table[10] =
{
	UNIT_STATS_SURV_RIFLEMAN,
	UNIT_STATS_SURV_RIFLEMAN,
	UNIT_STATS_SURV_RIFLEMAN,
	UNIT_STATS_SURV_FLAMER,
	UNIT_STATS_SURV_FLAMER,
	UNIT_STATS_SURV_SWAT,
	UNIT_STATS_SURV_SWAT,
	UNIT_STATS_SURV_SWAT,
	UNIT_STATS_SURV_SAPPER,
	UNIT_STATS_SURV_SAPPER
};
enum UNIT_ID techbunker_spawns_table[4] =
{
	UNIT_STATS_GORT,
	UNIT_STATS_PLASMA_TANK,
	UNIT_STATS_SENTINEL_DROID,
	UNIT_STATS_MECH
};
char aCouldnTCreateS[] = "Couldn't create spawned unit"; // idb
int dword_464D38 = 30; // weak
int dword_464D3C[24] =
{
    -30, 25, -25, 20,
    -20, 15, -15, 12,
    -12, 10, -10, 9,
    -9, 9, -9, 8,
    -8, 8, -8, 7,
    -7, 7, -7, 0
};
char aDDD[] = "%d %d %d\n"; // idb
char aR[] = "r"; // idb
char aSLevelsMulti_p[] = "%s\\LEVELS\\multi.pal"; // idb
int dword_464DC0[] = { 0 }; // weak
int dword_464DCC = 1; // weak
EnemyAI_stru57 array_464DD0[47] =
{
	{ 4, UNIT_STATS_MUTE_CLANHALL },
	{ 92, UNIT_STATS_MUTE_BEAST_ENCLOSURE },
	{ 93, UNIT_STATS_MUTE_BLACKSMITH },
	{ 94, UNIT_STATS_MUTE_MENAGERIE },
	{ 95, UNIT_STATS_MUTE_POWER_STATION },
	{ 96, UNIT_STATS_MUTE_DRILL_RIG },
	{ 97, UNIT_STATS_MUTE_BERSERKER },
	{ 98, UNIT_STATS_MUTE_CRAZY_HARRY },
	{ 99, UNIT_STATS_MUTE_KING_ZOG },
	{ 100, UNIT_STATS_MUTE_PYROMANIAC },
	{ 101, UNIT_STATS_MUTE_RIOTER },
	{ 102, UNIT_STATS_MUTE_BAZOOKA },
	{ 103, UNIT_STATS_MUTE_SHOTGUNNER },
	{ 104, UNIT_STATS_MUTE_MEKANIK },
	{ 105, UNIT_STATS_MUTE_VANDAL },
	{ 111, UNIT_STATS_MUTE_GIANT_BEETLE },
	{ 112, UNIT_STATS_MUTE_MISSILE_CRAB },
	{ 113, UNIT_STATS_MUTE_MOBILE_DERRICK },
	{ 114, UNIT_STATS_MUTE_DIRE_WOLF },
	{ 115, UNIT_STATS_MUTE_WAR_MASTADONT },
	{ 117, UNIT_STATS_MONSTER_TRUCK },
	{ 118, UNIT_STATS_MUTE_GIANT_SCORPION },
	{ 119, UNIT_STATS_MUTE_BIKE_AND_SIDECAR },
	{ 121, UNIT_STATS_MUTE_WASP },
	{ 5, UNIT_STATS_SURV_OUTPOST },
	{ 125, UNIT_STATS_SURV_MACHINE_SHOP },
	{ 126, UNIT_STATS_SURV_POWER_STATION },
	{ 127, UNIT_STATS_SURV_REPAIR_BAY },
	{ 129, UNIT_STATS_SURV_DRILL_RIG },
	{ 130, UNIT_STATS_SURV_EL_PRESIDENTE },
	{ 131, UNIT_STATS_SURV_FLAMER },
	{ 132, UNIT_STATS_SURV_RPG_LAUNCHER },
	{ 133, UNIT_STATS_SURV_SABOTEUR },
	{ 134, UNIT_STATS_SURV_SAPPER },
	{ 135, UNIT_STATS_SURV_SNIPER },
	{ 136, UNIT_STATS_SURV_SWAT },
	{ 137, UNIT_STATS_SURV_TECHNICIAN },
	{ 138, UNIT_STATS_SURV_RIFLEMAN },
	{ 124, UNIT_STATS_SURV_ANACONDA_TANK },
	{ 143, UNIT_STATS_SURV_4x4_PICKUP },
	{ 144, UNIT_STATS_SURV_ATV },
	{ 146, UNIT_STATS_SURV_DIRT_BIKE },
	{ 145, UNIT_STATS_SURV_BARRAGE_CRAFT },
	{ 147, UNIT_STATS_SURV_AUTOCANNON_TANK },
	{ 148, UNIT_STATS_SURV_MOBILE_DERRICK },
	{ 149, UNIT_STATS_SURV_ATV_FLAMETHROWER },
	{ -1, UNIT_INVALID }
};
char aWarningUnregis[] = "Warning: unregistered Loner"; // idb
char aWarningOutOfAt[] = "Warning: out of attacker nodes"; // idb
char aWarningOutOfWa[] = "Warning: out of wanderer nodes"; // idb
char aWarningOutOfPo[] = "Warning: out of powerplant nodes"; // idb
char aWarningOutOfDr[] = "Warning: out of drillrig nodes"; // idb
char aWarningOutOfTa[] = "Warning: out of tanker nodes"; // idb
char aWarningOutOfBu[] = "Warning: out of building nodes"; // idb
char aWarningOutOfEnemyNodes[] = "Warning: out of enemy nodes"; // idb
char aEnemyaiCreatur[] = "EnemyAI: Creature ID unknown"; // idb
char aWb__AND__handlers_minus1_indexer[3] = "wb";
void *script_handlers[353] =
{
	NULL,
	&UNIT_Handler_Outpost,
	&UNIT_Handler_OilTanker,
	&UNIT_Handler_MachineShop,
	&UNIT_Handler_Clanhall,
	&UNIT_Handler_BeastEnclosure,
	&UNIT_Handler_PowerStation,
	&UNIT_Handler_DrillRig,
	&UNIT_Handler_OilPatch,
	&UNIT_Handler_MobileDerrick,
	&UNIT_Handler_RepairStation,
	&UNIT_Handler_ResearchBuilding,
	&UNIT_Handler_ResearchBuilding,
	&UNIT_Handler_Blacksmith,
	&UNIT_Handler_RepairStation,
	&UNIT_Handler_GuardTower,
	&UNIT_Handler_GuardTower,
	&UNIT_Handler_GuardTower,
	&UNIT_Handler_GuardTower,
	&UNIT_Handler_GuardTower,
	&script_433060_ingame_menu_DA000000,
	&script_424CE0_mission_outcome_modal,
	&script_425400,
	&UNIT_Handler_General,
	&UNIT_Handler_OilTankerConvoy,
	&UNIT_Handler_Scout,
	&UNIT_Handler_Prison,
	&UNIT_Handler_Prison,
	&UNIT_AttachHandler_DockPoint,
	&UNIT_Handler_Aircraft,
	&EntityTowerAttachment_handler_4010C0,
	&EntityTowerAttachment_handler_4010E0,
	&EventHandler_Aircraft,
	&entity_mode_401480_aircraft,
	&entity_401530_aircraft,
	&entity_mode_401600_aircraft_stru31,
	&entity_mode_401660_aircraft,
	&entity_401670_aircraft,
	&entity_401680,
	&entity_mode_4016B0_aircraft,
	&entity_4017E0,
	&entity_mode_401800_aircraft,
	&UNIT_DmgHandler_Bomber,
	&Task_context_1_BomberDmgHandler_401D10,
	&Task_context_1_BomberDmgHandler_401D30,
	&Task_context_1_BomberDmgHandler_401DC0,
	&Task_context_1_BomberDmgHandler_401DE0,
	&EventHandler_BeastEnclosure,
	&entity_402150_beastenclosure,
	&UNIT_Handler_BeastEnclosure,
	&entity_mode_beastenclosure_set_default_production,
	&entity_mode_402350_beastenclosure,
	&entity_mode_beastenclosure_on_death,
	&entity_mode_402440_beastenclosure,
	&entity_blacksmith_on_upgrade_complete,
	&MessageHandler_Blacksmith,
	&UNIT_Handler_Blacksmith,
	&entity_mode_402780_blacksmith,
	&entity_mode_402840_blacksmith,
	&entity_mode_402870_blacksmith,
	&entity_mode_blacksmith_on_death,
	&entity_mode_402AB0,
	&entity_402AC0_is_mode_402AB0,
	&entity_402BB0_set_arrive_handler,
	&entity_402C40_lower_hp_mute09_surv21,
	&entity_initialize_building,
	&entity_sabotage,
	&EventHandler_DefaultBuildingsHandler,
	&script_403230_building_mini_explosion,
	&script_4032F0_building_grand_explosion,
	&script_403380_explosions,
	&entity_mode_4034B0,
	&entity_mode_403540,
	&entity_mode_4035C0_building,
	&entity_mode_403650_building,
	&entity_mode_403720_on_prison_death__or__prolly_any_generic_building,
	&entity_mode_building_default_on_death,
	&entity_4038B0,
	&entity_clanhall_on_upgrade_complete,
	&EventHandler_Clanhall,
	&entity_mode_clanhall_set_default_production,
	&UNIT_Handler_Clanhall,
	&entity_mode_clanhall_on_building_completed,
	&entity_mode_4042A0_clanhall,
	&entity_mode_clanhall_on_death_reset_production_options,
	&_4318E0_free_building_production,
	&entity_mode_clanhall_on_death,
	&entity_4054D0_tanker_convoy,
	&EventHandler_TankerConvoy,
	&entity_mode_405680_tanker_convoy,
	&entity_mode_405690,
	&entity_405750_tanker_convoy,
	&UNIT_Handler_OilTankerConvoy,
	&UNIT_Handler_MobileDerrick,
	&entity_mode_406CC0_mobilederrick,
	&EventHandler_MobileDerrick,
	&entity_mode_406DC0_mobilederrick,
	&entity_mode_plant_mobile_derrick,
	&entity_remove_unit_after_mobile_derrick_outpost_clanhall_plant,
	&UNIT_Handler_OilPatch,
	&EventHandler_Prison,
	&nullsub_1,
	&UNIT_Handler_Prison,
	&entity_mode_407300_prison,
	&entity_mode_407390_prison,
	&entity_mode_prison_spawn_unit,
	&entity_mode_prison_on_death,
	&UNIT_Handler_Prison,
	&entity_mode_prison_spawn_unit_surv09,
	&entity_mode_prison_on_death_surv09,
	&EventHandler_TechBunker,
	&entity_4075F0_techbunker,
	&entity_407690_techbunker_spawn,
	&entity_mode_407870_techbubker,
	&entity_mode_407950_techbunker_spawn_generic,
	&entity_mode_4079F0_techbunker_spawn10_surv18_lvl,
	&entity_mode_407A90_techbunker,
	&entity_mode_407B70_techbunker,
	&UNIT_Handler_TechBunker,
	&entity_mode_407C20_on_death_tech_bunker,
	&entity_mode_407C60_on_death_tech_bunker,
	&entity_mode_407D10,
	&entity_mode_hut_on_death,
	&entity_mode_407DA0,
	&EventHandler_Hut,
	&entity_mode_407E70_hut,
	&entity_mode_407F00_hut,
	&UNIT_Handler_Hut,
	&EventHandler_DrillRig,
	&UNIT_Handler_DrillRig,
	&entity_mode_4081C0_drillrig,
	&entity_mode_408240_drillrig,
	&entity_mode_408260_drillrig,
	&entity_mode_drillrig_on_death,
	&UNIT_Handler_Vehicle,
	&UNIT_Handler_Infantry,
	&entity_mode_415540_infantry,
	&entity_mode_415690,
	&entity_mode_4157F0,
	&entity_4158B0,
	&entity_mode_415980,
	&entity_415A20,
	&entity_mode_415A60_vehicle_rotate,
	&entity_mode_move_attack,
	&entity_mode_attack_move_1_415D30,
	&entity_mode_416060,
	&entity_mode_attack_move_2_5_4165C0,
	&entity_mode_416790_vehicle_move,
	&entity_mode_416A70_oiltanker,
	&entity_mode_416CD0,
	&entity_mode_416EB0,
	&entity_mode_417100,
	&entity_4172D0,
	&entity_mode_417360_infantry,
	&entity_mode_attack_move_4_417550,
	&entity_mode_417670,
	&entity_417810,
	&entity_417980,
	&entity_mode_417A20,
	&entity_mode_417BD0,
	&entity_mode_attack_move_4_order_3_7_417E60,
	&entity_mode_417F50,
	&entity_417F60,
	&entity_mode_417FC0,
	&entity_418120,
	&entity_418170,
	&entity_mode_4181B0,
	&entity_418290,
	&entity_mode_418550,
	&entity_mode_418590,
	&entity_4187F0,
	&script_418A10,
	&entity_mode_418B30,
	&entity_mode_418D20,
	&entity_mode_418E90,
	&entity_mode_418F60,
	&entity_mode_418FE0,
	&entity_mode_419180,
	&entity_mode_419230,
	&entity_4192F0,
	&entity_mode_419390_oiltanker,
	&entity_mode_move_tanker,
	&entity_419560_on_death,
	&entity_419720,
	&entity_mode_419760_infantry_destroyed,
	&entity_mode_4197E0_infantry,
	&EventHandler_Infantry,
	&EventHandler_419CA0,
	&EventHandler_General_Scout,
	&EventHandler_419DF0,
	&EventHandler_419E80,
	&entity_machineshop_on_upgrade_complete,
	&EventHandler_MachineShop,
	&entity_4220B0_machineshop,
	&UNIT_Handler_MachineShop,
	&entity_mode_machineshop_set_default_production,
	&entity_mode_machineshop_on_death_no_default,
	&entity_mode_4223A0_machineshop,
	&entity_mode_machineshop_on_death,
	&script_424BF0_mobd_20_handler,
	&_424CA0_script_47A3CC_evttrigger,
	&_424CC0_script_47A3CC_evttrigger,
	&script_424CE0_mission_outcome_modal,
	&sub_4250E0,
	&sub_4251B0,
	&script_4252C0,
	&script_425400,
	&entity_check_special_mission_death_conditions,
	&entity_425820_find,
	&entity_4258C0_init_palettes_inc_unit_counter,
	&entity_mode_425920_scout,
	&entity_425A50_setup_spawn,
	&UNIT_Handler_General,
	&UNIT_Handler_Scout,
	&sub_425EC0,
	&sub_425F20,
	&script_425F50_stru48_stru51_tech_bunkers,
	&script_425BE0_check_special_victory_conditions,
	&handler_4267F0,
	&nullsub_1,
	&script_426710_mission_objectives_draw_x_mark,
	&_4268B0_4269B0_task_attachment_handler,
	&_426860_4269B0_task_attachment_handler,
	&task_4269B0_mobd_20_handler,
	&UNIT_Handler_MobileOutpost,
	&entity_mode_4278C0_mobile_outpost,
	&MessageHandler_MobileOutpost,
	&nullsub_2,
	&entity_427BB0_mobile_outpost_clanhall_planting,
	&entity_mode_427BF0_mobile_outpost_clanhall_planting,
	&entity_427C30_after_mobile_outpost_clanhall_wagon_plant,
	&entity_remove_unit_after_mobile_derrick_outpost_clanhall_plant,
	&EventHandler_4089B0_generic_ai,
	&script_409770_ai,
	&script_40B700_ai,
	&EventHandler_42D6B0_evolved_mission8_ai,
	&script_42DA90_ai,
	&script_42DC70_ai,
	&EventHandler_42DC90_evolved_mission5_ai,
	&script_42DE80,
	&script_42DF20,
	&stru24_42DF40,
	&stru24_42E030,
	&stru24_42E070,
	&entity_outpost_on_upgrade_complete,
	&EventHandler_Outpost,
	&entity_mode_outpost_enable_basic_construction,
	&UNIT_Handler_Outpost,
	&entity_mode_outpost_set_default_production,
	&entity_mode_431680_outpost_arrive,
	&entity_mode_outpost_on_death_update_production,
	&_4318E0_free_building_production,
	&entity_mode_outpost_on_death,
	&EventHandler_PowerStation,
	&UNIT_Handler_PowerStation,
	&entity_mode_powerstation_spawn_tanker,
	&entity_mode_powerstation_completed,
	&entity_mode_powerstation_on_death,
	&UNIT_DmgHandler_Sapper,
	&script_435CF0_rocket_dmg_handler,
	&script_435D40_bombers_dmg,
	&UNIT_DmgHandler_Rocket,
	&script_436140_flamethrower_dmg_handler,
	&UNIT_DmgHandler_Flamethrower,
	&script_4363C0_giant_bettle_dmg,
	&UNIT_DmgHandler_Beetle,
	&script_4368B0_plasma_tank_dmg_handler,
	&UNIT_DmgHandler_Mech,
	&script_436FB0_dmg_handler,
	&script_436FF0_rifle_dmg_handler,
	&script_4370D0_gort_dmg_handler,
	&UNIT_DmgHandler_GORT,
	&UNIT_DmgHandler_Rifle,
	&sub_437690,
	&UNIT_DmgHandler_Bow,
	&UNIT_DmgHandler_Projectile,
	&EventHandler_RepairStation,
	&UNIT_Handler_RepairStation,
	&UNIT_Handler_RepairStation,
	&entity_mode_437F30_repairstation,
	&EventHandler_UpgradeProcess,
	&EntityUpgradeAttachment_438000,
	&EntityUpgradeAttachment_438030,
	&EntityUpgradeAttachment_438160_handler,
	&script_4381A0_upgrade_process,
	&EventHandler_ResearchBuilding,
	&UNIT_Handler_ResearchBuilding,
	&UNIT_Handler_ResearchBuilding,
	&entity_mode_researchlab_completed,
	&entity_mode_researchlab_on_death,
	&script_438B80_on_death_infantry_gore,
	&script_438C20_on_death_explosion,
	&entity_mode_4444D0_oiltanker,
	&entity_mode_4444F0_oiltanker,
	&entity_mode_444590_oiltanker,
	&entity_mode_444630_oiltanker,
	&entity_mode_4446B0_oiltanker_load_oil,
	&entity_mode_4447C0_oiltanker,
	&entity_mode_4448C0_oiltanker,
	&entity_mode_4449D0_oiltanker,
	&entity_mode_444A40_oiltanker,
	&entity_mode_444AB0_oiltanker,
	&entity_mode_444B40_oiltanker_unload_oil,
	&entity_mode_444CC0_oiltanker,
	&entity_mode_444D10_oiltanker,
	&entity_mode_4446A0_oiltanker,
	&EventHandler_OilTanker,
	&script_401C30_sidebar,
	&Task_context_0_4019A0,
	&Task_context_0_401A40,
	&Task_context_0_401A80,
	&Task_context_0_401AF0,
	&EventHandler_401B80,
	&UNIT_Handler_GuardTower,
	&UNIT_Handler_GuardTower,
	&UNIT_Handler_GuardTower,
	&UNIT_Handler_GuardTower,
	&UNIT_Handler_GuardTower,
	&UNIT_Handler_Towers,
	&entity_mode_4474D0_towers,
	&entity_mode_4474E0_towers,
	&entity_mode_tower_on_death,
	&entity_mode_tower_dead,
	&EventHandler_Towers,
	&UNIT_AttachHandler_Turret,
	&EntityTowerAttachment_handler_447C40,
	&EntityTowerAttachment_handler_447CA0,
	&EntityTowerAttachment_handler_447DD0,
	&EntityTowerAttachment_handler_447E20,
	&EntityTowerAttachment_handler_447F50,
	&EntityTowerAttachment_handler_447FA0,
	&EntityTowerAttachment_handler_448110,
	&EntityTowerAttachment_handler_448160,
	&EntityTowerAttachment_handler_448230,
	&EntityTowerAttachment_handler_448290,
	&EntityTowerAttachment_handler_4482D0_missile_battery,
	&nullsub_1,
	&MessageHandler_TowersAttachment,
	&UNIT_AttachHandler_Turret,
	&tower_attachment_handler_448980,
	&tower_attachment_handler_4489B0,
	&tower_attachment_handler_448B40,
	&tower_attachment_handler_448BF0,
	&tower_attachment_handler_448C40,
	&tower_attachment_handler_448E90,
	&MessageHandler_448EC0,
	&script_44BE60_explosions,
	&UNIT_AttachHandler_DockPoint,
	&EntityTurret_44BF00_handler,
	&EntityTurret_44BF70,
	&sub_44BFC0,
	&MessageHandler_EntityScript,
	(void *)0xFFFFFFFF
};
int num_script_handlers = 353; // weak
int _465610_damage_multipliers[12] = { 0, 51, 102, 0, 0, 38, 76, 0, 0, 1200, 600, 0 };
int _465640_accuracy_bonus[4] = { 0, 10, 20, 0 };
stru201_displaymode _465650_display_modes[3] =
{
	{ { 'M', 'O', 'D', 'E', 'X', '\0', '\0', '\0' }, 0, 0 },
	{ "320", 0, 0 },
	{ "640", 0, 0 }
};
int _465680_get_sys_colors = 1; // weak
int dword_465688[32] =
{
	4, 	4, 	4, 	4, 	4, 	4, 	4, 	4, 	4,
	4, 	4, 	4, 	4, 	4, 	4, 	4, 	3, 	3,
	3, 	3, 	3, 	3, 	3, 	3, 	2, 	2, 	2,
	2, 	1, 	1, 	0, 	5
};
int _465708_x_offsets[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int _465728_y_offsets[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int _4657C8_hint_entity_id = -1; // weak
stru3 stru3s[2] =
{
	{
		1397772884,
		&render_sprt_draw_handler_setup_palettes,
		&render_sprt_draw_handler,
		&nullsub_1
	},
	{ 1396920908, &nullsub_3, &render_scrl_draw_handler, &nullsub_1 }
}; // weak
unsigned __int8 _4657F0_tanker_status_color_breakpoints[8] = { 145u, 146u, 173u, 172u, 175u, 0u, 0u, 0u };
unsigned __int8 _4657F8_tanker_status_color_breakpoints[8] = { 144u, 145u, 239u, 223u, 174u, 0u, 0u, 0u };
unsigned __int8 _465800_stru26_stru27_initializer[4] = { 166u, 170u, 145u, 172u };
unsigned __int8 _465804_stru26_stru27_initializer[4] = { 164u, 169u, 145u, 223u };
stru1_draw_params default_stru1;
stru1_draw_params *render_default_stru1 = &default_stru1;
int render_first_drawing_item = 1; // weak
RECT stru_465810 = { 0, 0, 640, 480 };
char *aFailedToSetupDirectdraw = "Failed to setup DirectDraw";
char *Caption = "Error";
unsigned __int8 palette_465848_sprt[256] =
{
	0u,
	1u,
	2u,
	3u,
	4u,
	5u,
	6u,
	7u,
	8u,
	9u,
	10u,
	11u,
	12u,
	13u,
	14u,
	15u,
	16u,
	17u,
	18u,
	19u,
	20u,
	21u,
	22u,
	23u,
	24u,
	25u,
	26u,
	27u,
	28u,
	29u,
	30u,
	31u,
	32u,
	33u,
	34u,
	35u,
	36u,
	37u,
	38u,
	39u,
	40u,
	41u,
	42u,
	43u,
	44u,
	45u,
	46u,
	47u,
	48u,
	49u,
	50u,
	51u,
	52u,
	53u,
	54u,
	55u,
	56u,
	57u,
	58u,
	59u,
	60u,
	61u,
	62u,
	63u,
	64u,
	65u,
	66u,
	67u,
	68u,
	69u,
	70u,
	71u,
	72u,
	73u,
	74u,
	75u,
	76u,
	77u,
	78u,
	79u,
	80u,
	81u,
	82u,
	83u,
	84u,
	85u,
	86u,
	87u,
	88u,
	89u,
	90u,
	91u,
	92u,
	93u,
	94u,
	95u,
	96u,
	97u,
	98u,
	99u,
	100u,
	101u,
	102u,
	103u,
	104u,
	105u,
	106u,
	107u,
	108u,
	109u,
	110u,
	111u,
	112u,
	113u,
	114u,
	115u,
	116u,
	117u,
	118u,
	119u,
	120u,
	121u,
	122u,
	123u,
	124u,
	125u,
	126u,
	127u,
	128u,
	129u,
	130u,
	131u,
	132u,
	133u,
	134u,
	135u,
	136u,
	137u,
	138u,
	139u,
	140u,
	141u,
	142u,
	143u,
	144u,
	145u,
	146u,
	147u,
	148u,
	149u,
	150u,
	151u,
	152u,
	153u,
	154u,
	155u,
	156u,
	157u,
	158u,
	159u,
	160u,
	161u,
	162u,
	163u,
	164u,
	165u,
	166u,
	167u,
	168u,
	169u,
	170u,
	171u,
	172u,
	173u,
	174u,
	175u,
	176u,
	177u,
	178u,
	179u,
	180u,
	181u,
	182u,
	183u,
	184u,
	185u,
	186u,
	187u,
	188u,
	189u,
	190u,
	191u,
	192u,
	193u,
	194u,
	195u,
	196u,
	197u,
	198u,
	199u,
	200u,
	201u,
	202u,
	203u,
	204u,
	205u,
	206u,
	207u,
	208u,
	209u,
	210u,
	211u,
	212u,
	213u,
	214u,
	215u,
	216u,
	217u,
	218u,
	219u,
	220u,
	221u,
	222u,
	223u,
	224u,
	225u,
	226u,
	227u,
	228u,
	229u,
	230u,
	231u,
	232u,
	233u,
	234u,
	235u,
	236u,
	237u,
	238u,
	239u,
	240u,
	241u,
	242u,
	243u,
	244u,
	245u,
	246u,
	247u,
	248u,
	249u,
	250u,
	251u,
	252u,
	253u,
	254u,
	255u
};
int _465948_per_mobd_lookup_idx[16] =
{
	0,
	1567,
	2896,
	3784,
	4096,
	3784,
	2896,
	1567,
	0,
	4294965729,
	4294964400,
	4294963512,
	4294963200,
	4294963512,
	4294964400,
	4294965729
};
enum SOUND_ID _465988_sounds[5] = { SOUND_174, SOUND_175, SOUND_176, SOUND_177, SOUND_178 };

int input_465A80_wndprockey_map[256] =
{
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	14,
	15,
	-1,
	-1,
	-1,
	-1,
	13,
	-1,
	-1,
	42,
	29,
	56,
	-1,
	58,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	1,
	-1,
	-1,
	-1,
	-1,
	57,
	-1,
	-1,
	79,
	71,
	75,
	72,
	77,
	80,
	-1,
	-1,
	-1,
	-1,
	82,
	83,
	-1,
	11,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	10,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	30,
	48,
	46,
	32,
	18,
	33,
	34,
	35,
	23,
	36,
	37,
	38,
	50,
	49,
	24,
	25,
	16,
	19,
	31,
	20,
	22,
	47,
	17,
	45,
	21,
	44,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	76,
	-1,
	-1,
	-1,
	-1,
	55,
	78,
	13,
	12,
	-1,
	-1,
	59,
	60,
	61,
	62,
	63,
	64,
	65,
	66,
	67,
	68,
	87,
	88,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0
};
int input_465FE8[16] =
{
	-1,
	0,
	4,
	-1,
	6,
	7,
	5,
	6,
	2,
	1,
	3,
	2,
	-1,
	0,
	4,
	-1
};
stru7 array_466028[7] =
{
	{ 0, 5, NULL, NULL },
	{ 0, 2, NULL, NULL },
	{ 1, 0, &_41B000_stru7_handler, NULL },
	{ 2, 0, &_41B020_stru7_handler, NULL },
	{ 4, 0, &_41B070_stru7_handler, NULL },
	{ 0, 0, NULL, NULL },
	{ 0, 0, NULL, NULL }
};
int _466098_cost_multiplier[4] = { 374, 312, 256, 0 };
const char *slvs[2] = { "surv.slv", "mute.slv" };
LevelDesc levels[68] =
{
	{
		"surv_01.lvl",
		"surv2.wav",
		"heads01.vbc",
		1000,
		5000,
		0,
		256,
		1,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"surv_02.lvl",
		"surv1.wav",
		"heads02.vbc",
		4500,
		5000,
		0,
		256,
		0,
		0,
		1835039u,
		787,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"surv_03.lvl",
		"surv2.wav",
		"heads03.vbc",
		1000,
		5000,
		0,
		256,
		0,
		0,
		720925u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"surv_04.lvl",
		"surv1.wav",
		"heads04.vbc",
		0,
		5000,
		0,
		256,
		2,
		0,
		0u,
		768,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"surv_05.lvl",
		"surv2.wav",
		"heads05.vbc",
		5000,
		100,
		0,
		328,
		1,
		0,
		16u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"surv_06.lvl",
		"surv1.wav",
		"heads06.vbc",
		0,
		50,
		0,
		256,
		2,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"surv_07.lvl",
		"surv2.wav",
		"heads07.vbc",
		4000,
		5000,
		0,
		256,
		2,
		0,
		0u,
		768,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"surv_08.lvl",
		"surv1.wav",
		"heads08.vbc",
		5000,
		1000,
		0,
		280,
		3,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"surv_09.lvl",
		"surv2.wav",
		"heads09.vbc",
		1000,
		100,
		0,
		256,
		3,
		0,
		0u,
		1795,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"surv_10.lvl",
		"surv1.wav",
		"heads10.vbc",
		6500,
		1000,
		0,
		296,
		3,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"surv_11.lvl",
		"surv2.wav",
		"heads11.vbc",
		5000,
		1000,
		0,
		256,
		4,
		0,
		0u,
		779,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"surv_12.lvl",
		"surv1.wav",
		"heads12.vbc",
		0,
		50,
		0,
		256,
		5,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"surv_13.lvl",
		"surv2.wav",
		"heads13.vbc",
		4000,
		100,
		0,
		256,
		5,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"surv_14.lvl",
		"surv1.wav",
		"heads14.vbc",
		5000,
		5000,
		0,
		256,
		5,
		0,
		0u,
		775,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"surv_15.lvl",
		"surv2.wav",
		"heads15.vbc",
		6000,
		1000,
		0,
		256,
		5,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mute_01.lvl",
		"mute1.wav",
		"headm01.vbc",
		5000,
		5000,
		0,
		256,
		1,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mute_02.lvl",
		"mute2.wav",
		"headm02.vbc",
		2600,
		1000,
		0,
		256,
		1,
		0,
		119u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mute_03.lvl",
		"mute1.wav",
		"headm03.vbc",
		2500,
		500,
		0,
		256,
		1,
		0,
		21u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mute_04.lvl",
		"mute2.wav",
		"headm04.vbc",
		5000,
		500,
		0,
		256,
		2,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mute_05.lvl",
		"mute1.wav",
		"headm05.vbc",
		5000,
		5000,
		0,
		256,
		2,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mute_06.lvl",
		"mute2.wav",
		"headm06.vbc",
		2500,
		100,
		0,
		304,
		2,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mute_07.lvl",
		"mute1.wav",
		"headm07.vbc",
		5000,
		100,
		0,
		256,
		2,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mute_08.lvl",
		"mute2.wav",
		"headm08.vbc",
		5000,
		5000,
		0,
		256,
		2,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mute_09.lvl",
		"mute1.wav",
		"headm09.vbc",
		5000,
		100,
		0,
		320,
		2,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mute_10.lvl",
		"mute2.wav",
		"headm10.vbc",
		5000,
		100,
		0,
		304,
		3,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mute_11.lvl",
		"mute1.wav",
		"headm11.vbc",
		6500,
		100,
		0,
		256,
		3,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mute_12.lvl",
		"mute2.wav",
		"headm12.vbc",
		5000,
		100,
		0,
		256,
		3,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mute_13.lvl",
		"mute1.wav",
		"headm13.vbc",
		6000,
		800,
		0,
		256,
		4,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mute_14.lvl",
		"mute2.wav",
		"headm14.vbc",
		4000,
		5000,
		0,
		256,
		5,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mute_15.lvl",
		"mute1.wav",
		"headm15.vbc",
		7000,
		100,
		0,
		240,
		5,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mlti_01.lvl",
		"surv1.wav",
		NULL,
		5000,
		5000,
		0,
		256,
		5,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mlti_02.lvl",
		"surv2.wav",
		NULL,
		5000,
		5000,
		0,
		256,
		5,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mlti_03.lvl",
		"surv3.wav",
		NULL,
		5000,
		5000,
		0,
		256,
		5,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mlti_04.lvl",
		"surv4.wav",
		NULL,
		5000,
		5000,
		0,
		256,
		5,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mlti_05.lvl",
		"mute1.wav",
		NULL,
		5000,
		5000,
		0,
		256,
		5,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mlti_06.lvl",
		"mute2.wav",
		NULL,
		5000,
		5000,
		0,
		256,
		5,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mlti_07.lvl",
		"mute3.wav",
		NULL,
		5000,
		5000,
		0,
		256,
		5,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mlti_08.lvl",
		"mute4.wav",
		NULL,
		5000,
		5000,
		0,
		256,
		5,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mlti_09.lvl",
		"surv1.wav",
		NULL,
		5000,
		5000,
		0,
		256,
		5,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mlti_10.lvl",
		"surv2.wav",
		NULL,
		5000,
		5000,
		0,
		256,
		5,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mlti_11.lvl",
		"surv3.wav",
		NULL,
		5000,
		5000,
		0,
		256,
		5,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mlti_12.lvl",
		"surv4.wav",
		NULL,
		5000,
		5000,
		0,
		256,
		5,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mlti_13.lvl",
		"mute1.wav",
		NULL,
		5000,
		5000,
		0,
		256,
		5,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mlti_14.lvl",
		"mute2.wav",
		NULL,
		5000,
		5000,
		0,
		256,
		5,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mlti_15.lvl",
		"mute4.wav",
		NULL,
		5000,
		5000,
		0,
		256,
		5,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mlti_10.lvl",
		"mute3.wav",
		NULL,
		5000,
		5000,
		0,
		256,
		5,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mlti_10.lvl",
		"surv1.wav",
		NULL,
		5000,
		5000,
		0,
		304,
		5,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mlti_10.lvl",
		"surv1.wav",
		NULL,
		5000,
		5000,
		0,
		328,
		5,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"surv_16.lvl",
		"surv4.wav",
		NULL,
		3000,
		50,
		0,
		328,
		3,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"surv_17.lvl",
		"surv1.wav",
		NULL,
		3000,
		50,
		0,
		296,
		3,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"surv_18.lvl",
		"surv4.wav",
		NULL,
		0,
		50,
		0,
		256,
		5,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"surv_19.lvl",
		"surv2.wav",
		NULL,
		0,
		50,
		0,
		256,
		5,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"surv_20.lvl",
		"surv4.wav",
		NULL,
		0,
		50,
		0,
		312,
		4,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"surv_21.lvl",
		"surv3.wav",
		NULL,
		5000,
		50,
		0,
		328,
		4,
		0,
		8192u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"surv_22.lvl",
		"surv4.wav",
		NULL,
		0,
		50,
		0,
		416,
		5,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"surv_23.lvl",
		"surv1.wav",
		NULL,
		0,
		50,
		0,
		320,
		5,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"surv_24.lvl",
		"surv4.wav",
		NULL,
		5000,
		50,
		0,
		312,
		5,
		0,
		0u,
		771,
		10,
		40000,
		196633000,
		0,
		0,
		0
	},
	{
		"surv_25.lvl",
		"surv4.wav",
		NULL,
		6500,
		50,
		0,
		256,
		5,
		0,
		0u,
		771,
		10,
		30000,
		196633000,
		0,
		0,
		0
	},
	{
		"mute_16.lvl",
		"mute4.wav",
		NULL,
		4500,
		50,
		0,
		328,
		3,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mute_17.lvl",
		"mute1.wav",
		NULL,
		2600,
		50,
		0,
		280,
		3,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mute_18.lvl",
		"mute4.wav",
		NULL,
		4500,
		50,
		0,
		312,
		3,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mute_19.lvl",
		"mute2.wav",
		NULL,
		5000,
		50,
		0,
		320,
		4,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mute_20.lvl",
		"mute4.wav",
		NULL,
		5000,
		50,
		0,
		264,
		4,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mute_21.lvl",
		"mute3.wav",
		NULL,
		4500,
		50,
		0,
		374,
		4,
		0,
		0u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mute_22.lvl",
		"mute4.wav",
		NULL,
		5500,
		0,
		0,
		312,
		5,
		0,
		8192u,
		771,
		0,
		0,
		0,
		0,
		0,
		0
	},
	{
		"mute_23.lvl",
		"mute1.wav",
		NULL,
		5000,
		50,
		0,
		280,
		5,
		0,
		0u,
		771,
		6,
		35000,
		196638000,
		0,
		0,
		0
	},
	{
		"mute_24.lvl",
		"mute4.wav",
		NULL,
		6000,
		50,
		0,
		328,
		5,
		0,
		0u,
		771,
		4,
		19000,
		65553000,
		0,
		0,
		0
	},
	{
		"mute_25.lvl",
		"mute4.wav",
		NULL,
		5000,
		50,
		0,
		264,
		5,
		0,
		0u,
		771,
		30,
		30000,
		196633000,
		0,
		0,
		0
	}
};
const char *errmsg_save[2] = { "unknown error", "non-specific" };
char aMemory[7] = "memory"; // weak
char aUnitDS[] = "unit %d %s"; // idb
char aBadUpgradeTask[17] = "bad upgrade task"; // weak
char aUnknownMessage[24] = "unknown message handler"; // weak
char aUnknownTurnRet[25] = "unknown turn-return mode"; // weak
char aUnknownReturnM[20] = "unknown return mode"; // weak
char aUnknownAttacke[22] = "unknown attacked mode"; // weak
char aUnknownArriveM[20] = "unknown arrive mode"; // weak
char aUnknownIdleMod[18] = "unknown idle mode"; // weak
char aUnknownMode[13] = "unknown mode"; // weak
char aUnknownTurretM[20] = "unknown turret mode"; // weak
char aTaskIsWrongTyp[19] = "task is wrong type"; // weak
char aBadConstructs[15] = "bad constructs"; // weak
char aBadMode[9] = "bad mode"; // weak
char aCouldNotSaveUn[32] = "Could not save unit information"; // weak
char aCouldnTWriteTo[33] = "couldn't write to save-game file"; // weak
char aCouldnTOpenSav[29] = "couldn't open save-game file"; // weak
char aCouldNotSaveMi[41] = "Could not save miscellaneous information"; // weak
char aCouldNotSaveMa[31] = "Could not save map information"; // weak
char aCouldNotSavePr[38] = "Could not save production information"; // weak
char aCouldNotSaveCp[38] = "Could not save cpu player information"; // weak
char aCouldNotAlloca[36] = "Could not allocate buffer for units"; // weak
char aCouldNotSaveOi[31] = "Could not save oil information"; // weak
char aCouldnTAllocat[35] = "Couldn't allocate temporary buffer"; // weak
char aSS_0[] = "%s (%s)"; // idb
int prev_level_idx = -1; // weak
const char *pKknd_sve = "kknd.sve";
char aC[3] = "%c"; // idb
char *reg_MinimumInstall = "MinimumInstall";
char *reg_DriveLetter = "DriveLetter";
char *reg_GamePath = "GamePath";
char a_[2] = "."; // weak
char *aS = "%s";
char *aLvl_runlevelFa = "LVL_RunLevel() failed\n";
char *aLvl_substhunkF = "LVL_SubstHunk( ) failed\n";
char *MOBD = "MOBD";
char *aLvl_loadlevelS = "LVL_LoadLevel(%s) failed\n";
char *aSLevelsSS = "%s\\LEVELS\\%s\\%s";
char *aSuperSpriteLoa = "super sprite load failed\n";
char *aSLevelsSSupspr = "%s\\LEVELS\\%s\\supspr.lvl";
char intro_vbc[10] = "intro.vbc"; // weak
char *aSFmvMh_fmv_vbc = "%s\\FMV\\mh_fmv.vbc";
char *fmv_lvl = "fmv.lvl";
char *aSFmvS = "%s\\FMV\\%s";
char *aEvolvout_vbc = "evolvout.vbc";
char *aSurvout_vbc = "survout.vbc";
char *aLoadgamestateF = "LoadGameState() failed\n";
char *aUnit_initFaile = "UNIT_Init() failed\n";
char *aSLevelsS = "%s\\LEVELS\\%s";
char *aSpriteLoadFail = "sprite load failed\n";
CustomMission custom_missions[20] =
{
	{ /*&off_46C4F0*/nullptr, "mb_m01.wav" },
	{ /*&off_46C520*/nullptr, "mb_m02.wav" },
	{ /*&off_46C548*/nullptr, "mb_m03.wav" },
	{ /*&off_46C578*/nullptr, "mb_m04.wav" },
	{ /*&off_46C598*/nullptr, "mb_m05.wav" },
	{ /*&off_46C5C0*/nullptr, "mb_m06.wav" },
	{ /*&off_46C5F8*/nullptr, "mb_m07.wav" },
	{ /*&off_46C630*/nullptr, "mb_m08.wav" },
	{ /*&off_46C658*/nullptr, "mb_m09.wav" },
	{ /*&off_46C688*/nullptr, "mb_m10.wav" },
	{ /*&off_46C6B0*/nullptr, "mb_s01.wav" },
	{ /*&off_46C6D0*/nullptr, "mb_s02.wav" },
	{ /*&off_46C6F0*/nullptr, "mb_s03.wav" },
	{ /*&off_46C738*/nullptr, "mb_s04.wav" },
	{ /*&off_46C778*/nullptr, "mb_s05.wav" },
	{ /*&off_46C7B8*/nullptr, "mb_s06.wav" },
	{ /*&off_46C7F0*/nullptr, "mb_s07.wav" },
	{ /*&off_46C828*/nullptr, "mb_s08.wav" },
	{ /*&off_46C860*/nullptr, "mb_s09.wav" },
	{ /*&off_46C888*/nullptr, "mb_s10.wav" }
};
UnitNameId unit_name_id_lut[66] =
{
	{ "UNIT_SURV_INFANTRY", 0 },
	{ "UNIT_MUTE_BERSERKER", 1 },
	{ "UNIT_SURV_FLAMER", 2 },
	{ "UNIT_MUTE_PYRO", 3 },
	{ "UNIT_SURV_SWAT", 4 },
	{ "UNIT_MUTE_SHOTGUNNER", 5 },
	{ "UNIT_SURV_SAPPER", 6 },
	{ "UNIT_MUTE_RIOTER", 7 },
	{ "UNIT_SURV_ELPRESIDENTE", 8 },
	{ "UNIT_MUTE_KINGZOG", 9 },
	{ "UNIT_SURV_SABOTEUR", 10 },
	{ "UNIT_MUTE_VANDAL", 11 },
	{ "UNIT_SURV_TECHNICIAN", 12 },
	{ "UNIT_MUTE_TECHNICIAN", 13 },
	{ "UNIT_SURV_ROCKETLAUNCHER", 14 },
	{ "UNIT_MUTE_ROCKETLAUNCHER", 15 },
	{ "UNIT_SURV_SNIPER", 16 },
	{ "UNIT_MUTE_CRAZYHARRY", 17 },
	{ "UNIT_SURV_GENERAL", 18 },
	{ "UNIT_MUTE_LEADER", 19 },
	{ "UNIT_SURV_SCOUT", 20 },
	{ "UNIT_SURV_DERRICK", 21 },
	{ "UNIT_MUTE_DERRICK", 22 },
	{ "UNIT_SURV_TANKER", 23 },
	{ "UNIT_MUTE_TANKER", 24 },
	{ "UNIT_SURV_BIKE", 26 },
	{ "UNIT_MUTE_WOLF", 27 },
	{ "UNIT_SURV_PICKUP", 28 },
	{ "UNIT_MUTE_SIDECAR", 29 },
	{ "UNIT_SURV_ATV", 30 },
	{ "UNIT_MUTE_MONTRUCK", 31 },
	{ "UNIT_SURV_FLAMEATV", 32 },
	{ "UNIT_MUTE_SCORPION", 33 },
	{ "UNIT_SURV_ANACONDA", 34 },
	{ "UNIT_MUTE_MASTODON", 35 },
	{ "UNIT_SURV_BARAGECRAFT", 36 },
	{ "UNIT_MUTE_BEETLE", 37 },
	{ "UNIT_SURV_CANNONTANK", 38 },
	{ "UNIT_MUTE_CRAB", 39 },
	{ "UNIT_SURV_MOBILE_BASE", 40 },
	{ "UNIT_MUTE_MOBILE_BASE", 41 },
	{ "UNIT_MUTE_WASP", 43 },
	{ "UNIT_SURV_BOMBER", 44 },
	{ "UNIT_SURV_DRILLRIG", 46 },
	{ "UNIT_MUTE_DRILLRIG", 47 },
	{ "UNIT_SURV_POWERPLANT", 48 },
	{ "UNIT_MUTE_POWERPLANT", 49 },
	{ "UNIT_SURV_GUARDTOWER", 52 },
	{ "UNIT_MUTE_MACHGUNNEST", 53 },
	{ "UNIT_SURV_CANNONTOWER", 54 },
	{ "UNIT_MUTE_GRAPESHOT", 55 },
	{ "UNIT_SURV_MISSILEBATTERY", 56 },
	{ "UNIT_MUTE_ROTARYCANNON", 57 },
	{ "UNIT_SURV_OUTPOST", 58 },
	{ "UNIT_MUTE_CLANHALL", 59 },
	{ "UNIT_SURV_MACHINESHOP", 60 },
	{ "UNIT_MUTE_BLACKSMITH", 61 },
	{ "UNIT_MUTE_BEASTENCLOSURE", 62 },
	{ "UNIT_SURV_REPAIRBAY", 63 },
	{ "UNIT_MUTE_MENAGERIE", 64 },
	{ "UNIT_SURV_RESEARCHLAB", 65 },
	{ "UNIT_MUTE_ALCHEMYHALL", 66 },
	{ "UNIT_GORT", 74 },
	{ "UNIT_LASERTANK", 76 },
	{ "UNIT_SENTINEL", 77 },
	{ "UNIT_MECH", 78 }
};
char *console_switch_nocd = "-nocd";
char *console_switch_noblack = "-noblack";
char *errmsg_no_stats_file_specified = "no stats file specified\n";
char *console_switch_stats = "-stats";
char *aSS = "%s\\%s";
char *aW = "w";
char *errmsg_could_not_open_file = "Error: could not open file %s\n";
char *errmsg_unrecognized_name = "Warning: unrecognised name %s\n";
char aDamageToBuildi[20] = "damage to buildings"; // weak
char aDamageToVehicl[19] = "damage to vehicles"; // weak
char aDamageToInfant[19] = "damage to infantry"; // weak
char aAccuracy[9] = "accuracy"; // weak
char aFiringVisualRa[20] = "firing/visual range"; // weak
char aTurningSpeed[14] = "turning speed"; // weak
char aVolleySize[12] = "volley size"; // weak
char aReload2Time[13] = "reload2 time"; // weak
char aReloadTime[12] = "reload time"; // weak
char aSpeed[6] = "speed"; // weak
char aWarningUnitSIs[] = "Warning: unit %s is a building, speed ignored\n"; // idb
char aHitpoints[10] = "hitpoints"; // weak
char aProductionTime[16] = "production time"; // weak
char errmsg_unit_out_of_range[] = "Warning: unit %s %s out of range (%d - %d)\n"; // idb
char cost[5] = "cost"; // weak
char _4681EC_whitespace[] = " \t\r\n"; // idb
char asc_space[] = " \t"; // idb

stru52 stru_4681F8 = { UNIT_STATS_MUTE_BERSERKER, UNIT_STATS_MUTE_SHOTGUNNER, UNIT_STATS_MUTE_SHOTGUNNER, UNIT_STATS_MUTE_SHOTGUNNER, UNIT_STATS_MUTE_BERSERKER, UNIT_INVALID };
stru52 stru_468210 = { UNIT_STATS_MUTE_BERSERKER, UNIT_STATS_MUTE_SHOTGUNNER, UNIT_STATS_MUTE_BIKE_AND_SIDECAR, UNIT_STATS_MUTE_DIRE_WOLF, UNIT_INVALID, UNIT_STATS_SURV_RIFLEMAN };
stru52 stru_468228 = { UNIT_STATS_SURV_ATV, UNIT_STATS_SURV_ATV_FLAMETHROWER, UNIT_STATS_SURV_SWAT, UNIT_STATS_SURV_SAPPER, UNIT_STATS_SURV_ANACONDA_TANK, UNIT_INVALID };
stru53 stru_468240 = { UNIT_STATS_MUTE_WAR_MASTADONT, UNIT_STATS_MUTE_GIANT_SCORPION, UNIT_STATS_MONSTER_TRUCK, UNIT_INVALID };
stru53 stru_468250 = { UNIT_STATS_MUTE_GIANT_SCORPION, UNIT_STATS_MUTE_GIANT_BEETLE, UNIT_INVALID, UNIT_STATS_SURV_RIFLEMAN };
stru53 stru_468260 = { UNIT_STATS_MUTE_GIANT_SCORPION, UNIT_STATS_MONSTER_TRUCK, UNIT_STATS_MUTE_BIKE_AND_SIDECAR, UNIT_INVALID };
stru53 stru_468270 = { UNIT_STATS_MUTE_GIANT_SCORPION, UNIT_STATS_MONSTER_TRUCK, UNIT_INVALID, UNIT_STATS_SURV_RIFLEMAN };
stru53 stru_468280 = { UNIT_STATS_SURV_ATV_FLAMETHROWER, UNIT_STATS_SURV_ANACONDA_TANK, UNIT_STATS_SURV_BARRAGE_CRAFT, UNIT_INVALID };
stru53 stru_468290 = { UNIT_STATS_SURV_AUTOCANNON_TANK, UNIT_STATS_SURV_ANACONDA_TANK, UNIT_STATS_SURV_BARRAGE_CRAFT, UNIT_INVALID };
stru54 stru_4682A0 = { UNIT_STATS_MUTE_GIANT_SCORPION, UNIT_STATS_MUTE_BERSERKER, UNIT_STATS_MUTE_BERSERKER, UNIT_STATS_MUTE_BERSERKER, UNIT_STATS_MUTE_SHOTGUNNER, UNIT_STATS_MUTE_SHOTGUNNER, UNIT_INVALID, UNIT_STATS_SURV_RIFLEMAN };
stru54 stru_4682C0 = { UNIT_STATS_MUTE_GIANT_SCORPION, UNIT_STATS_MUTE_WAR_MASTADONT, UNIT_STATS_MUTE_BERSERKER, UNIT_STATS_MUTE_BERSERKER, UNIT_STATS_MUTE_BERSERKER, UNIT_STATS_MUTE_SHOTGUNNER, UNIT_STATS_MUTE_SHOTGUNNER, UNIT_INVALID };
stru55 stru_4682E0 = { UNIT_STATS_SURV_ATV, UNIT_STATS_SURV_ATV_FLAMETHROWER, UNIT_STATS_SURV_SWAT, UNIT_STATS_SURV_SWAT, UNIT_STATS_SURV_SWAT, UNIT_STATS_SURV_SWAT, UNIT_STATS_SURV_SWAT, UNIT_STATS_SURV_ATV, UNIT_INVALID, UNIT_STATS_SURV_RIFLEMAN };
stru54 stru_468308 = { UNIT_STATS_SURV_ANACONDA_TANK, UNIT_STATS_SURV_ATV_FLAMETHROWER, UNIT_STATS_SURV_SAPPER, UNIT_STATS_SURV_SAPPER, UNIT_STATS_SURV_SAPPER, UNIT_STATS_SURV_SAPPER, UNIT_STATS_SURV_ANACONDA_TANK, UNIT_INVALID };
stru53 stru_468328 = { UNIT_STATS_SURV_ANACONDA_TANK, UNIT_STATS_SURV_BARRAGE_CRAFT, UNIT_STATS_SURV_AUTOCANNON_TANK, UNIT_INVALID };
stru55 stru_468338 = { UNIT_STATS_SURV_ATV, UNIT_STATS_SURV_ATV_FLAMETHROWER, UNIT_STATS_SURV_SWAT, UNIT_STATS_SURV_SWAT, UNIT_STATS_SURV_SWAT, UNIT_STATS_SURV_SWAT, UNIT_STATS_SURV_SWAT, UNIT_STATS_SURV_ATV, UNIT_INVALID, UNIT_STATS_SURV_RIFLEMAN };
stru54 stru_468360 = { UNIT_STATS_SURV_ANACONDA_TANK, UNIT_STATS_SURV_ATV_FLAMETHROWER, UNIT_STATS_SURV_SAPPER, UNIT_STATS_SURV_SAPPER, UNIT_STATS_SURV_SAPPER, UNIT_STATS_SURV_SAPPER, UNIT_STATS_SURV_ANACONDA_TANK, UNIT_INVALID };
stru53 stru_468380 = { UNIT_STATS_SURV_ANACONDA_TANK, UNIT_STATS_SURV_BARRAGE_CRAFT, UNIT_STATS_SURV_AUTOCANNON_TANK, UNIT_INVALID };
stru55 stru_468390 = { UNIT_STATS_SURV_ATV, UNIT_STATS_SURV_ATV_FLAMETHROWER, UNIT_STATS_SURV_SWAT, UNIT_STATS_SURV_SWAT, UNIT_STATS_SURV_SWAT, UNIT_STATS_SURV_SWAT, UNIT_STATS_SURV_SWAT, UNIT_STATS_SURV_ATV, UNIT_INVALID, UNIT_STATS_SURV_RIFLEMAN };
stru54 stru_4683B8 = { UNIT_STATS_SURV_ANACONDA_TANK, UNIT_STATS_SURV_ATV_FLAMETHROWER, UNIT_STATS_SURV_SAPPER, UNIT_STATS_SURV_SAPPER, UNIT_STATS_SURV_SAPPER, UNIT_STATS_SURV_SAPPER, UNIT_STATS_SURV_ANACONDA_TANK, UNIT_INVALID };
stru53 stru_4683D8 = { UNIT_STATS_SURV_ANACONDA_TANK, UNIT_STATS_SURV_BARRAGE_CRAFT, UNIT_STATS_SURV_AUTOCANNON_TANK, UNIT_INVALID };
stru55 stru_4683E8 = { UNIT_STATS_SURV_ANACONDA_TANK, UNIT_STATS_SURV_SWAT, UNIT_STATS_SURV_SAPPER, UNIT_STATS_SURV_SWAT, UNIT_STATS_SURV_SNIPER, UNIT_STATS_SURV_SNIPER, UNIT_STATS_SURV_BARRAGE_CRAFT, UNIT_STATS_SURV_AUTOCANNON_TANK, UNIT_INVALID, UNIT_STATS_SURV_RIFLEMAN };
stru49 _468410_stru49_array[21] =
{
	{ (stru53 *)&stru_4681F8, 6000, 1000, 1 },
	{ (stru53 *)&stru_468210, 12000, 1100, 2 },
	{ (stru53 *)&stru_468228, 3500, 1000, 4 },
	{ &stru_468240, 15000, 10000, 10 },
	{ &stru_468250, 15000, 10000, 10 },
	{ &stru_468260, 6000, 1500, 3 },
	{ &stru_468270, 25000, 8000, 4 },
	{ &stru_468280, 20000, 14000, 6 },
	{ &stru_468290, 35000, 14000, 6 },
	{ (stru53 *)&stru_4682A0, 30000, 7000, 4 },
	{ (stru53 *)&stru_4682C0, 37000, 6000, 3 },
	{ (stru53 *)&stru_4682E0, 5000, 15000, 10 },
	{ (stru53 *)&stru_468308, 10000, 15000, 10 },
	{ &stru_468328, 15000, 15000, 10 },
	{ (stru53 *)&stru_468338, 47000, 6000, 2 },
	{ (stru53 *)&stru_468360, 50000, 5000, 2 },
	{ &stru_468380, 52000, 4000, 2 },
	{ (stru53 *)&stru_468390, 10000, 30000, 3 },
	{ (stru53 *)&stru_4683B8, 20000, 35000, 3 },
	{ &stru_4683D8, 40000, 35000, 3 },
	{ (stru53 *)&stru_4683E8, 25000, 8000, 2 }
};
stru50 _468560_stru50_array[16] =
{
	{ UNIT_STATS_MUTE_CLANHALL_WAGON, 0, 0 },
	{ UNIT_STATS_MUTE_BERSERKER, 128, 0 },
	{ UNIT_STATS_MUTE_BERSERKER, 128, 0 },
	{ UNIT_STATS_MUTE_BERSERKER, 128, 0 },
	{ UNIT_STATS_MUTE_BERSERKER, 128, 0 },
	{ UNIT_STATS_MUTE_BERSERKER, 128, 0 },
	{ UNIT_STATS_MUTE_SHOTGUNNER, 128, 64 },
	{ UNIT_STATS_MUTE_SHOTGUNNER, 128, 64 },
	{ UNIT_STATS_MUTE_SHOTGUNNER, 128, 64 },
	{ UNIT_STATS_MUTE_SHOTGUNNER, 128, 64 },
	{ UNIT_STATS_MUTE_SHOTGUNNER, 128, 64 },
	{ UNIT_STATS_MUTE_DIRE_WOLF, 4294967168, 0 },
	{ UNIT_STATS_MUTE_DIRE_WOLF, 4294967168, 64 },
	{ UNIT_STATS_MONSTER_TRUCK, 0, 128 },
	{ UNIT_STATS_MUTE_GIANT_SCORPION, 0, 4294967232 },
	{ UNIT_INVALID, 0, 0 }
};
stru50 _468620_stru50_array[16] =
{
	{ UNIT_STATS_SURV_MOBILE_OUTPOST, 0, 0 },
	{ UNIT_STATS_SURV_RIFLEMAN, 128, 0 },
	{ UNIT_STATS_SURV_RIFLEMAN, 128, 0 },
	{ UNIT_STATS_SURV_RIFLEMAN, 128, 0 },
	{ UNIT_STATS_SURV_RIFLEMAN, 128, 0 },
	{ UNIT_STATS_SURV_RIFLEMAN, 128, 0 },
	{ UNIT_STATS_SURV_SWAT, 128, 64 },
	{ UNIT_STATS_SURV_SWAT, 128, 64 },
	{ UNIT_STATS_SURV_SWAT, 128, 64 },
	{ UNIT_STATS_SURV_SWAT, 128, 64 },
	{ UNIT_STATS_SURV_SWAT, 128, 64 },
	{ UNIT_STATS_SURV_DIRT_BIKE, 4294967168, 0 },
	{ UNIT_STATS_SURV_DIRT_BIKE, 4294967168, 64 },
	{ UNIT_STATS_SURV_4x4_PICKUP, 0, 128 },
	{ UNIT_STATS_SURV_ATV, 0, 4294967232 },
	{ UNIT_INVALID, 0, 0 }
};
stru50 __4686E0_stru50_array[20] =
{
	{ UNIT_STATS_MUTE_CLANHALL_WAGON, 0, 0 },
	{ UNIT_STATS_MUTE_BERSERKER, 128, 0 },
	{ UNIT_STATS_MUTE_BERSERKER, 128, 0 },
	{ UNIT_STATS_MUTE_BERSERKER, 128, 0 },
	{ UNIT_STATS_MUTE_BERSERKER, 128, 0 },
	{ UNIT_STATS_MUTE_BERSERKER, 128, 0 },
	{ UNIT_STATS_MUTE_SHOTGUNNER, 128, 64 },
	{ UNIT_STATS_MUTE_SHOTGUNNER, 128, 64 },
	{ UNIT_STATS_MUTE_SHOTGUNNER, 128, 64 },
	{ UNIT_STATS_MUTE_SHOTGUNNER, 128, 64 },
	{ UNIT_STATS_MUTE_SHOTGUNNER, 128, 64 },
	{ UNIT_STATS_MUTE_WAR_MASTADONT, 4294967280, 128 },
	{ UNIT_STATS_MUTE_WAR_MASTADONT, 16, 128 },
	{ UNIT_STATS_MUTE_GIANT_SCORPION, 4294967286, 4294967168 },
	{ UNIT_STATS_MUTE_GIANT_SCORPION, 10, 4294967168 },
	{ UNIT_STATS_MUTE_DIRE_WOLF, 4294967168, 4294967232 },
	{ UNIT_STATS_MUTE_DIRE_WOLF, 4294967168, 32 },
	{ UNIT_STATS_MONSTER_TRUCK, 4294967168, 4294967286 },
	{ UNIT_STATS_MUTE_BIKE_AND_SIDECAR, 4294967168, 20 },
	{ UNIT_INVALID, 0, 0 }
};
stru50 _4687D0_stru50_array[20] =
{
	{ UNIT_STATS_SURV_MOBILE_OUTPOST, 0, 0 },
	{ UNIT_STATS_SURV_RIFLEMAN, 128, 0 },
	{ UNIT_STATS_SURV_RIFLEMAN, 128, 0 },
	{ UNIT_STATS_SURV_RIFLEMAN, 128, 0 },
	{ UNIT_STATS_SURV_RIFLEMAN, 128, 0 },
	{ UNIT_STATS_SURV_RIFLEMAN, 128, 0 },
	{ UNIT_STATS_SURV_SWAT, 128, 64 },
	{ UNIT_STATS_SURV_SWAT, 128, 64 },
	{ UNIT_STATS_SURV_SWAT, 128, 64 },
	{ UNIT_STATS_SURV_SWAT, 128, 64 },
	{ UNIT_STATS_SURV_SWAT, 128, 64 },
	{ UNIT_STATS_SURV_ANACONDA_TANK, 4294967280, 128 },
	{ UNIT_STATS_SURV_ANACONDA_TANK, 16, 128 },
	{ UNIT_STATS_SURV_ATV, 4294967286, 4294967168 },
	{ UNIT_STATS_SURV_ATV, 10, 4294967168 },
	{ UNIT_STATS_SURV_DIRT_BIKE, 4294967168, 4294967232 },
	{ UNIT_STATS_SURV_DIRT_BIKE, 4294967168, 32 },
	{ UNIT_STATS_SURV_4x4_PICKUP, 4294967168, 4294967286 },
	{ UNIT_STATS_SURV_ATV_FLAMETHROWER, 4294967168, 20 },
	{ UNIT_INVALID, 0, 0 }
};
DataCplcItem_ptr1_stru20 _4688E0_DataCplcItem_ptr1_stru20_clanhall =
{
	MOBD_MUTE_CLANHALL,
	&UNIT_Handler_Clanhall,
	1,
	0,
	NULL,
	0,
	0,
	0,
	UNIT_STATS_MUTE_CLANHALL,
	2,
	0,
	0
}; // weak
DataCplcItem_ptr1_stru20 _468910_DataCplcItem_ptr1_stru20_outpost =
{
	MOBD_SURV_OUTPOST,
	&UNIT_Handler_Outpost,
	1,
	0,
	NULL,
	0,
	0,
	0,
	UNIT_STATS_SURV_OUTPOST,
	1,
	0,
	0
}; // weak
int dword_468940[] = { -1 }; // weak
int dword_468980 = -1; // weak
int dword_468984 = -1; // weak
enum SOUND_ID _468988_sound_ids[4] = { SOUND_69, SOUND_53, SOUND_51, SOUND_50 };
enum SOUND_ID _468998_sound_ids[4] = { SOUND_139, SOUND_116, SOUND_142, SOUND_140 };
enum SOUND_ID _4689A8_sound_ids[2] = { SOUND_181, SOUND_182 };
enum SOUND_ID _4689B0_sound_ids[4] = { SOUND_179, SOUND_180, SOUND_185, SOUND_0 };
enum SOUND_ID _4689C0_sound_ids[22] =
{
	SOUND_182,
	SOUND_183,
	SOUND_184,
	SOUND_182,
	SOUND_183,
	SOUND_184,
	SOUND_182,
	SOUND_183,
	SOUND_184,
	SOUND_182,
	SOUND_183,
	SOUND_184,
	SOUND_182,
	SOUND_183,
	SOUND_184,
	SOUND_182,
	SOUND_183,
	SOUND_184,
	SOUND_182,
	SOUND_183,
	SOUND_184,
	SOUND_186
};
enum SOUND_ID _468A18_sound_ids[2] = { SOUND_78, SOUND_85 };
enum SOUND_ID _468A20_sound_ids[2] = { SOUND_156, SOUND_158 };
enum SOUND_ID _468A28_sound_ids[4] = { SOUND_68, SOUND_49, SOUND_43, SOUND_0 };
enum SOUND_ID _468A38_sound_ids[4] = { SOUND_133, SOUND_131, SOUND_91, SOUND_0 };
enum SOUND_ID _468A48_sound_ids[2] = { SOUND_76, SOUND_85 };
enum SOUND_ID _468A50_sound_ids[2] = { SOUND_154, SOUND_148 };
enum SOUND_ID _468A58_sound_id = SOUND_69;
char aSD[] = "%s $%d"; // idb
char aSS_1[] = "%s: %s"; // idb
unsigned __int8 _468A6C_mobd_lookups[68] =
{
	0u,
	0u,
	1u,
	1u,
	2u,
	3u,
	3u,
	4u,
	5u,
	5u,
	6u,
	6u,
	7u,
	8u,
	8u,
	9u,
	9u,
	10u,
	11u,
	11u,
	12u,
	12u,
	13u,
	14u,
	14u,
	15u,
	15u,
	16u,
	16u,
	17u,
	17u,
	18u,
	18u,
	19u,
	19u,
	20u,
	20u,
	21u,
	21u,
	22u,
	22u,
	23u,
	23u,
	24u,
	24u,
	24u,
	25u,
	25u,
	26u,
	26u,
	27u,
	27u,
	27u,
	28u,
	28u,
	28u,
	29u,
	29u,
	29u,
	30u,
	30u,
	31u,
	31u,
	31u,
	32u,
	0u,
	0u,
	0u
};
char aWarningUnreg_0[] = "Warning: unregistered enemy"; // idb
char aWarningOutOfMa[] = "Warning: out of marshalling nodes"; // idb
char aWarningUnreg_2[] = "Warning: unregistered wanderer"; // idb
char aWarningUnreg_1[] = "Warning: unregistered neutral"; // idb
char aWarningOutOfNe[] = "Warning: out of neutral nodes"; // idb
int netz_468B50_available_units_denom = 1; // weak
int dword_468B54 = -1;
void *__47CA80_array_idx_and_netz_player_side = (void *)0xFFFFFFFF; // idb
int single_player_game = 1; // weak
int dword_468CE8 = 0; // weak
int netz_468CF0 = 1750844416; // weak
int netz_468CF4 = 298818860; // weak
int netz_468CF8 = 2852179369; // weak
int netz_468CFC = 3817236480; // weak
int netz_468D00 = 1156228960; // weak
int netz_468D04 = 298830696; // weak
int netz_468D08 = 2684374684; // weak
int netz_468D0C = 1581385161; // weak
int netz_468D10 = 253585504; // weak
int netz_468D14 = 298813657; // weak
int netz_468D18 = 2684374684; // weak
int netz_468D1C = 1581385161; // weak
int netz_468D20 = -1; // weak
char aS_1[2] = "S"; // weak
char aC_0[2] = "C"; // weak
char aUnknown[8] = "Unknown"; // weak
char aUnknownNetzE_0[42] = "unknown NETZ error (no protocol selected)"; // weak
char aUnknownNetzErr[38] = "unknown NETZ error (no error message)"; // weak
char aNotYetImplemen[20] = "not yet implemented"; // weak
char aDisabled[9] = "disabled"; // weak
char aLinkLost[10] = "link lost"; // weak
char aNetzRequiresA4[40] = "NETZ requires a 486 or better processor"; // weak
char aOperatingSyste[34] = "operating system is just too lame"; // weak
char aFailed[7] = "failed"; // weak
char aNameIsNotUniqu[19] = "name is not unique"; // weak
char aWrongModeForNe[28] = "wrong mode for NETZ command"; // weak
char aCouldNotCreate[28] = "could not create NETZ event"; // weak
char aPacketIsTooBig[18] = "packet is too big"; // weak
char aInternalResour[32] = "internal resource pool is empty"; // weak
char aPortSocketInUs[31] = "port/socket in use or unusable"; // weak
char aWrongTypeOfLin[36] = "wrong type of link for this command"; // weak
char aProtocolIsNotP[24] = "protocol is not present"; // weak
char aLinkIsNotConne[22] = "link is not connected"; // weak
char aNoFreeLinks[14] = "no free links"; // weak
char aLinkInUseAlrea[26] = "link in use: already open"; // weak
char aLinkNotOpen[14] = "link not open"; // weak
char aOutOfMemory[14] = "out of memory"; // weak
char aNoError[10] = "no error!"; // weak
BasicProductionOption surv_basic_buildings[5] =
{
	{ 1, UNIT_STATS_SURV_OUTPOST, 2488 },
	{ 2, UNIT_STATS_SURV_MACHINE_SHOP, 2736 },
	{ 32, UNIT_STATS_SURV_POWER_STATION, 2704 },
	{ 4, UNIT_STATS_SURV_REPAIR_BAY, 2728 },
	{ 16, UNIT_STATS_SURV_RESEARCH_LAB, 2720 }
}; // weak
BasicProductionOption surv_basic_infantry[3] =
{
	{ 262144, UNIT_STATS_SURV_RIFLEMAN, 2888 },
	{ 1048576, UNIT_STATS_SURV_SWAT, 2872 },
	{ 524288, UNIT_STATS_SURV_TECHNICIAN, 2848 }
}; // weak
int dword_468FD4 = 1; // weak
int dword_468FD8 = 2; // weak
int dword_468FDC = 3; // weak
char *off_469030[30] =
{
	"THE NEXT GENERATION\nThe surface is currently owned by the\nmutants.   To start reclaiming the land,\nwe must destroy all mutants in the\nsurrounding area.",
	"    BUILD AN OUTPOST\nProtect the Outpost and build a Power\nStation.  Don't let any buildings fall.\nEstablish a drill site with the Oil\nDerrick, and use the Power Station's\ntanker to collect at least 5000\nResource Units.",
	"WITHSTAND THE RAIDING PARTY\nRecently built camp is targetted for\nenemy attack.  Protect all buildings,\ndon't let any fall.",
	"    RESCUE THE SCOUT\nA scout has gone missing while\nmapping the area.  Locate him and\nbring him home, alive.",
	"        TOLL GATE\nA mutant base has been discovered on\na ruined highway north of a ruined\ncity.   The base protects a supply\nroute along the road.  Set up a base\nto rupture the supply line, then\ndestroy all mutants and their base.",
	"EXTERMINATE THE VILLAGE\nA Survivor force has drawn mutants\naway from their camp.  They will not be\ngone long. While they are away, get\ninto their camp, destroy their 4 oil\nrigs and the surrounding buildings,\nthen return to where you started.",
	"PROTECT THE CONVOY\nA convoy of six Survivor vehicles is\nmaking its way to another Survivor\ncamp.   Protect them as they travel,\nand ensure that at least four of the\nsix arrive at the other camp intact.",
	"   BACK TO THE BEACH\nTake the beach in the name of the\nSurvivors.  Establish a base there,\nbuild it up, then destroy all mutants\nin the area.",
	"RESCUE THE COMMANDER\nA Survivor Commander has been\ncaptured and his regiment destroyed.\nWe believe he's been taken to the\nmutant camp he was trying to destroy.\nLocate the camp, rescue the Commander,\nthen destroy the camp entirely.\nEnsure his safety.",
	"     OCCUPATION FORCE\nThe mutants have set up a stronghold in\nthe H7 Hills.  The area is limited in \nresources.  Secure the oil sites and\nbreak up the mutant supply lines, then\ndestroy their stronghold.",
	"    GIVE ME LIBERTY\nA rich oil deposit has been discovered\nnear the fallen city of Mareindad.\nBuild up your forces and destroy\nall mutants and mutant buildings.",
	"   SURGICAL STRIKE\nThe mutant chieftain is preparing to\nshare his battle plans with the mutant\nwarlords.  Kill the chieftain before\nthe other leaders get there, and keep\na low profile.",
	"   HOLD THE BRIDGE\nThe mutants are headed over the\nbridges.  Prevent the mutants from\ncrossing either bridge, kill any who\nmake it through.  Then push forward\nand kill all remaining mutants in the\narea.",
	"   THE ROUT/RETREAT\nThe mutants are spearheading their\nforces and headed towards our main\nbunker.  Hold off the mutants for half\nan hour from our left flank while we\nwithdraw all forces to protect the\nbunker.",
	"      BESIEGED\nThe mutants have our main bunker\nunder siege, but have left their own\nbases virtually undefended.  Protect\nthe base as you work your way through\nthe enemy.  Then push through them and\ndestroy their base.",
	"  RETURN OF THE SLUGS\nThe Chieftain has a feeling the\nSymmetrics are actually alive and some\nmay have broken through to the surface.\nHunt them down and kill them.",
	"       REPEL THEM!\nThe Symmetrics are congregating near\none of our villages.  They are trying\nto establish themselves on the surface.\nStop them.",
	"       BUBBLIN' CRUDE\nOur Mekaniks have reconstructed a rig.\nTake a mobile derrick to the hills and\nset it up over an Earth Blood deposit.\nCreate a Power Station, and use its\ntanker to transport the Earth Blood.\nClear all Symmetrics from the area.",
	"    RAID THE FORT\nOur raids have left a Symmetric\nsupply post very much under-defended.\nTake a party and some Monster Trucks\nand steal their abandoned tankers.\nEscape west with at least two\ntankers.",
	"       AMBUSH\nA Symmetric attack party heads for\nthe village of Granbretan.  We have\nlost contact with our original ambush\nparty near the southern bridge.\nRegain contact with our ambush\nparty, band together and prevent all\nSymmetrics from crossing the bridges.",
	"       SIEGE\nOne of our camps has come under\nsiege.  We are cut off from our\nsupply of Earth Blood.  Clear a safe\npath through the Symmetrics for our\nEarth Blood, then wipe out all\nSymmetrics and their camp.",
	"  RELEASE THE PRISIONERS\nThe Symmetrics have raided another\nvillage, taking our people to their\nnests.  Rescue the innocents, enlist\ntheir help, then destroy the Symmetric\ncamp.",
	"  SMASH THE CONVOY\nA Symmetric convoy are protected and\nmoving north.  We suspect they're\nheading for a Symmetric camp.  Stop\nthem from getting anywhere near it.",
	"FIGHT FOR TERRITORY\nA leader of the Evolved is in trouble.\nHis battle with a Symmetric base goes\npoorly, and his base will soon fall.\nRepair his base, then destroy the\nSymmetric base entirely.",
	"  CLOSE ENCOUNTERS\nThe Symmetrics are headed towards\none of our forbidden sites.  Find\nout if the Symmetrics have located\nold technology.  Whether they have\nor not, destroy them all.",
	"IT'S THE END OF THE WORLD\nThe Symmetrics have a rich source of\nwar materials, which we need. \nEstablish a base for the Evolved, take\nover or destroy their stealing of the\nEarth Blood, and eradicate them.",
	"  THE BIG ATTACK\nWe have been blessed with fruitful\nbreeding grounds.  Prevent a Symmetric\nwar party from destroying what we have\nmade, then destroy the Symmetrics\nthemselves.",
	"BATTLE FOR THE ISLANDS\nWe want to take the area around the\nSouthern Barl river delta.  Take the\nruined highway to the nearby Evolved\ncamp. Build up your forces, then remove\nall Symmetrics from the area.",
	"  THE FINAL ASSAULT\nSix of our Warlords head to the hills\nto meet with our Chieftain and discuss\nthe final battle.  The Symmetrics will\ntry to break up the meeting.  Protect\nall seven leaders from Symmetric\nattack.",
	"    COUNTER ATTACK\nThe Symmetrics have been forced back\nto their main base. Destroy them,\ndestroy their base, and win the war\nfor the surface."
}; // weak
int _4690A8_unit_sounds_volume = 16;
int _4690AC_level_wav_sound_offset = 16; // idb
int dword_4690B0 = 16; // weak
int dword_4690B4 = 24576; // weak
char asc_46BB14[18] = "                 ";
char aD_1[] = "%d:"; // idb
char aD_0[5] = " %d:"; // weak
char aD[6] = "  %d:"; // weak
RECT _46BB40_enum_attached_surfaces_blt_rect = { 0, 0, 640, 480 };
RECT _46BB50_blt_rect = { 0, 0, 640, 480 };
int _46BB60_dmg_handler_mobd_offsets[3] = { 332, 364, 388 };
enum SOUND_ID _46BB70_dmg_handler_sounds[3] = { SOUND_RIFLE_FIRE_2, SOUND_RIFLE_FIRE_3, SOUND_RIFLE_FIRE_4 };
enum SOUND_ID _46BB80_dmg_handler_sounds[2] = { SOUND_GENERIC_PROJECTILE_DMG, SOUND_GENERIC_PROJECTILE_DMG_2 };
char aSGameD_sav[] = "%s\\game%d.sav"; // idb
char aSlotDSD[] = "Slot %d = %s %d\n"; // idb
char aActiveslotD[] = "ActiveSlot=%d\n"; // idb
char aSSave_lst[] = "%s\\save.lst"; // idb
int _46BBE8_mobd_offset_table_by_stru22[8] = { 1976, 1988, 2000, 2012, 2024, 2036, 2048, 2060 };
int dword_46BC20[8] = { 60, 40, 4294967286, 4294967266, 4294967251, 4294967261, 0, 30 };
int dword_46BC40[8] = { 10, 4294967251, 4294967241, 4294967261, 0, 25, 35, 40 };
int dword_46BC60[9] = { 0, 40, 80, 120, 292, 448, 620, 660, 700 };
int dword_46BC84[5] = { 736, 748, 772, 792, 760 };
int dword_46BC98[8] = { 496, 496, 496, 496, 276, 220, 72, 144 };
char aSoun[] = "SOUN"; // idb
char shared_slv_filename[] = "sound.slv"; // idb
char aData[5] = "data"; // weak
char fmt[5] = "fmt "; // weak
char WAVE[5] = "WAVE"; // weak
char RIFF[5] = "RIFF"; // weak
int render_43B4A6_46BD04 = 0; // weak
__int16 word_46BD08 = 0; // weak
int dword_46BD0A = 0; // weak
__int16 word_46BD0E = 0; // weak
char aEvol[7] = "-EVOL-"; // weak
_BYTE aSurv[] = { 45, 83, 85, 82, 86, 45, 0 }; // idb
char aEvol_0[5] = "EVOL"; // weak
_BYTE a2[] = { 83, 85, 82, 86, 0 }; // idb
char aUnitReady[] = "Unit Ready"; // idb
char aCouldntCreateNewUnit[] = "Couldn't create new unit"; // idb
char aBuildingCompleted[] = "Building completed"; // idb
char aBuildingSabotaged[] = "Building Sabotaged"; // idb
char aAirStrikeReady[] = "AirStrike ready"; // idb
char a5000ResourceUn[20] = "5000 Resource Units"; // weak
char a1000ResourceUn[] = "1000 Resource Units"; // idb
char aNoMoneyToStartBuilding[] = "No Money to start building"; // idb
char aNoTowersAvaila[] = "No towers available for building"; // idb
char aCommencingUpgrade[] = "Commencing upgrade"; // idb
char aUpgradeComplete[] = "Upgrade complete"; // idb
const char *player_colors[15] =
{
	"Blue",
	"Red",
	"Orange",
	"Yellow",
	"Green",
	"Aqua",
	"Purple",
	"HotPink",
	"DkBlue",
	"Pink",
	"Brown",
	"White",
	"Black",
	"Gold",
	"Bronze"
};
char *off_46C358[15] =
{
	"Urbane Assault",
	"War is Heck",
	"Highland Jig",
	"Bridge Too Far",
	"Napalm Death",
	"No Future",
	"Seas of Blood",
	"Crabs of Fury",
	"Scorched Earth",
	"Desert Storm",
	"Ground Zero",
	"No Mans Land",
	"City State",
	"Hardware War",
	"Black Ice"
}; // weak
const char *difficulties[3] = { "EASY  ", "NORMAL", "HARD  " };
const char *sidebar_category_labels[11] =
{
	"RESOURCES",
	"MAP",
	"OPTIONS",
	"INFORMATION",
	"INFANTRY",
	"VEHICLES",
	"BUILDINGS",
	"DEFENCES",
	"AIRCRAFT",
	"AIRSTRIKE",
	"DECONSTRUCT"
};
char aSfxVolumeMusicVolume[28] = " SFX VOLUME\n\n\n\nMUSIC VOLUME"; // weak
char aAreYouSureYo_0[34] = "Are you sure\nYou want to\n   quit?"; // weak
char aAreYouSureYouW[35] = "Are you sure\nYou want to\n restart?"; // weak
char aBuildingIsUnav[] = "Building is unavailable."; // idb
char aAllegianceBroken[] = "%s's allegiance with %s is broken"; // idb
char aUnitsAreUnavai[] = "Units are unavailable."; // idb
char aSSwearingAlleg[] = "%s Swearing allegiance to %s"; // idb
int dword_46E3F0 = 4294967294; // weak
int dword_46E3F8 = 2; // weak
int dword_46E3FC = 3; // weak
int _466098_cost_multiplier_idx = 1; // weak
int dword_46E404 = 1; // weak
int dword_46E408[6] = { 9600, 19200, 38400, 57600, 115200, 0 };
const char *_46E420_starting_cash[8] = { "5000 ", "6000 ", "8000 ", "10000", "12500", "15000", "3300 ", "4000 " };
int _46E440_mobd_offsets[15] = { 180, 192, 204, 216, 228, 240, 252, 264, 276, 288, 300, 312, 324, 336, 348 };
int _46E480_mobd_offsets[15] = { 0, 12, 24, 36, 48, 60, 72, 84, 96, 108, 120, 132, 144, 156, 168 };
int _46E4C0_mobd_offsets[10] = { 492, 504, 516, 528, 540, 552, 564, 576, 588, 600 };
int _46E4F0_mobd_offsets[10] = { 372, 384, 396, 408, 420, 432, 444, 456, 468, 480 };
char format[] = "name=%s . phone=%s . baud=%d\n"; // idb
char aModem_lst[] = "modem.lst"; // idb
char aSS_2[] = "%s-%s"; // idb
char aD_2[] = "%d\n"; // idb
char aS_0[4] = "%s\n"; // idb
char aCLevelsMute1_wav[20] = "C:\\LEVELS\\MUTE1.WAV"; // weak

char asc_470198[] = "        0"; // idb
int _4701A8_sidebar_mask_per_44_mobd_lookup_idx[] = { 1, 2, 4, 8 }; // idb
int _4701B8_mobd_lookups_per_ProductionGroup_field44[8] = { 146, 2016, 174, 2028, 169, 2004, 172, 2040 };
stru196 array_4701D8[28] =
{
	{ UNIT_STATS_SURV_DRILL_RIG, 3, 2, 300, 15, 3758096384 },
	{ UNIT_STATS_SURV_OUTPOST, 4, 3, 1000, 25, 1845493760u },
	{ UNIT_STATS_SURV_MACHINE_SHOP, 4, 4, 1000, 25, 4278190080u },
	{ UNIT_STATS_SURV_POWER_STATION, 4, 3, 300, 15, 3959422976u },
	{ UNIT_STATS_SURV_REPAIR_BAY, 4, 4, 300, 15, 4278190080u },
	{ UNIT_STATS_SURV_RESEARCH_LAB, 4, 3, 25, 25, 1845493760u },
	{ UNIT_STATS_SURV_GUARD_TOWER, 2, 2, 200, 5, 3221225472u },
	{ UNIT_STATS_SURV_CANNON_TOWER, 2, 2, 200, 5, 3221225472u },
	{ UNIT_STATS_SURV_MISSILE_BATTERY, 2, 2, 300, 10, 3221225472u },
	{ UNIT_STATS_TECH_BUNKER, 3, 2, 30, 5, 3758096384u },
	{ UNIT_WALL_1, 1, 1, 50, 5, -1 },
	{ UNIT_WALL_3, 1, 1, 100, 10, -1 },
	{ UNIT_STATS_SURV_DETENTION_CENTER, 4, 3, 500, 15, -1 },
	{ UNIT_STATS_MUTE_HOLDING_PENS, 4, 3, 500, 15, -1 },
	{ UNIT_STATS_MUTE_DRILL_RIG, 3, 2, 300, 15, 3758096384u },
	{ UNIT_STATS_MUTE_CLANHALL, 5, 4, 1000, 25, 867696640u },
	{ UNIT_STATS_MUTE_BLACKSMITH, 5, 3, 500, 25, 4026531840u },
	{ UNIT_STATS_MUTE_BEAST_ENCLOSURE, 5, 4, 500, 25, 2009071616u },
	{ UNIT_STATS_MUTE_POWER_STATION, 4, 3, 300, 15, 3925868544u },
	{ UNIT_STATS_MUTE_MENAGERIE, 4, 4, 300, 15, 1845493760u },
	{ UNIT_STATS_MUTE_ALCHEMY_HALL, 3, 2, 500, 25, 3758096384u },
	{ UNIT_STATS_MUTE_MACHINEGUN_NEST, 2, 2, 200, 5, 3221225472u },
	{ UNIT_STATS_MUTE_GRAPESHOT_TOWER, 2, 2, 200, 5, 3221225472u },
	{ UNIT_STATS_MUTE_ROTARY_CANNON, 2, 2, 300, 10, 3221225472u },
	{ UNIT_STATS_HUT, 2, 2, 30, 5, 3221225472u },
	{ UNIT_WALL_2, 1, 1, 50, 5, -1 },
	{ UNIT_WALL_4, 1, 1, 100, 10, -1 },
	{ UNIT_INVALID, 0, 0, 0, 0, 0 }
};
void (*_470478_sidebar_button_open_handlers[5])(SidebarButton *) =
{
	&sidebar_button_handler_infantry_close,
	&sidebar_button_handler_vehicles_close,
	&sidebar_button_handler_buildings_close,
	&sidebar_button_handler_towers_close,
	&sidebar_button_handler_airstrike_close
};
void(*_470490_sidebar_button_close_handlers[5])(SidebarButton *) =
{
	&sidebar_button_handler_infantry_open,
	&sidebar_button_handler_vehicles_open,
	&sidebar_button_handler_buildings_open,
	&sidebar_button_handler_towers_open,
	&sidebar_button_handler_airstrike_open
};
int _4704A8_per_sidebar_button_mobd_lookup_table_offsets[2][11] =
{
	{ 2920, 2944, 2928, 2936, 2464, 2648, 2480, 2472, 2268, 2252, 2252 },
	{ 2896, 2944, 2904, 2912, 2440, 2640, 2456, 2448, 2260, 2244, 2244 }
};
char a8d[] = " %8d"; // idb
enum PLAYER_SIDE player_side = SURVIVORS;
int dword_47050C = -1; // weak
int dword_470510[] = { 2 }; // weak
int array_470514[7] = { 2, 2, 2, 2, 2, 2, 2 };
char aCouldnTCreat_0[] = "Couldn't create new building"; // idb
char aWaitingForServ[] = "waiting for server packet"; // idb
char aWaitingForPlay[] = "waiting for player packet"; // idb

int dword_470588[] = { 1, 0, 0, 0xC0000000 };
int dword_470598 = 0; // weak
int dword_47059C = 0; // weak
int *_4705A8_minimap_smthn = dword_470588; // weak

MobdSprtImage _47CBA0_MobdSprtImage_fog_of_war;
DataMobdItem_stru0 _4705B0_minimap = { 0, 0, 0, &_47CBA0_MobdSprtImage_fog_of_war, NULL, SOUND_0, NULL }; // weak


UnitDamageSource dmg_rifle = { MOBD_EXPLOSIONS, UNIT_DmgHandler_Rifle, -1, 0x14C, 0, 40, 30, 15, 0x20, 0 };
UnitDamageSource dmg_shell_anaconda = { MOBD_SURV_ANACONDA_TANK, UNIT_DmgHandler_Projectile, 0x340, 0x114, 5, 100, 200, 100, 0x20, 0 };
UnitDamageSource dmg_shell_cannontower = { MOBD_SURV_ANACONDA_TANK, UNIT_DmgHandler_Projectile, 0x340, 0x114, 7, 80, 150, 80, 0x20, 0 };
UnitDamageSource dmg_shell_mastadont = { MOBD_MUTE_WAR_MASTADONT, UNIT_DmgHandler_Projectile, 0x540, 0x114, 5, 25, 50, 25, 0x20, 0 };
UnitDamageSource dmg_swat = { MOBD_EXPLOSIONS, UNIT_DmgHandler_Rifle, -1, 0x14C, 0, 70, 55, 30, 0x20, 0 };
UnitDamageSource dmg_bow = { MOBD_MUTE_BERSERKER, UNIT_DmgHandler_Bow, 0x500, -1, 5, 40, 30, 15, 0x20, 0 };
UnitDamageSource dmg_shotgunner = { MOBD_EXPLOSIONS, UNIT_DmgHandler_Rifle, -1, 0x14C, 0, 70, 55, 30, 0x20, 0 };
UnitDamageSource dmg_sniper = { MOBD_EXPLOSIONS, UNIT_DmgHandler_Rifle, -1, 0x14C, 0, 250, 90, 50, 0x20, 0 };
UnitDamageSource dmg_flamethrower = { MOBD_EXPLOSIONS, UNIT_DmgHandler_Flamethrower, -1, 0x1F0, 1, 15, 15, 18, 0x20, 0 };
UnitDamageSource dmg_scorpion = { MOBD_72_looks_like_acid_spit, UNIT_DmgHandler_Projectile, 0xC0, 0x2C0, 5, 50, 100, 70, 0x20, 0 };
UnitDamageSource dmg_beetle = { MOBD_MUTE_GIANT_BEETLE, UNIT_DmgHandler_Beetle, -1, 0x2C0, 2, 50, 60, 40, 0x20, 0 };
UnitDamageSource dmg_rocket_rpg = { MOBD_MUTE_BAZOOKA, UNIT_DmgHandler_Rocket, 0x580, 0x114, 3, 80, 130, 90, 0x20, 0 };
UnitDamageSource dmg_rocket_tower = { MOBD_MUTE_BAZOOKA, UNIT_DmgHandler_Rocket, 0x580, 0x114, 4, 150, 150, 100, 0x20, 0 };
UnitDamageSource dmg_rocket_barragecraft = { MOBD_MUTE_MISSILE_CRAB, UNIT_DmgHandler_Rocket, 0x540, 0x114, 3, 150, 170, 120, 0x20, 0 };
UnitDamageSource dmg_grapeshot = { MOBD_MUTE_GRAPESHOT_TOWER, UNIT_DmgHandler_Projectile, 0x1BC, 0x114, 8, 20, 17, 12, 0x20, 0 };
UnitDamageSource dmg_rocket_misslecraft = { MOBD_MUTE_MISSILE_CRAB, UNIT_DmgHandler_Rocket, 0x540, 0x114, 4, 100, 180, 120, 0x20, 0 };
UnitDamageSource dmg_mech = { MOBD_MUTE_BAZOOKA, UNIT_DmgHandler_Mech, 0x580, 0x114, 6, 200, 200, 130, 0x20, 0 };
UnitDamageSource dmg_plasma_ball = { MOBD_PLASMA_TANK, UNIT_DmgHandler_Projectile, 0x318, 0x824, 0x0A, 150, 150, 90, 0x20, 0 };
UnitDamageSource dmg_gort = { MOBD_GORT, UNIT_DmgHandler_GORT, 0x93C, -1, 0, 10, 20, 5, 0x20, 0 };
UnitDamageSource dmg_laser_cannon = { MOBD_SENTINEL_DROID, UNIT_DmgHandler_Projectile, 0x600, 0x824, 0x0A, 300, 300, 100, 0x20, 0 };
UnitDamageSource dmg_sapper = { MOBD_SURV_SAPPER, UNIT_DmgHandler_Sapper, 0x740, 0x0DC, 1, 180, 150, 120, 0x20, 0 };
UnitDamageSource dmg_bomber = { MOBD_SURV_BOMBER, UNIT_DmgHandler_Bomber, 0x180, 0, 1, 2000, 2900, 1500, 0x80, 0 };
UnitDamageSource dmg_drill_rig = { MOBD_MUTE_ALCHEMY_HALL, 0, 0, 0, 1, 15, 15, 15, 0x20, 0 };


UnitAttachmentPoint turret_AnacondaCannon = { MOBD_SURV_ANACONDA_TANK, UNIT_AttachHandler_Turret, 3, 105, 105, 1, 0x3C0, 0x3C0, &dmg_shell_anaconda, 0 };
UnitAttachmentPoint turret_PlasmaCannon = { MOBD_PLASMA_TANK, UNIT_AttachHandler_Turret, 3, 10, 60, 3, 0x398, 0x398, &dmg_plasma_ball, 0 };
UnitAttachmentPoint turret_SentinelDroid = { MOBD_SENTINEL_DROID, UNIT_AttachHandler_Turret, 3, 30, 120, 2, 0x680, 0x680, &dmg_laser_cannon, 0 };
UnitAttachmentPoint turret_mech = { MOBD_MECH, UNIT_AttachHandler_Turret, 3, 20, 120, 3, 0x518, 0x518, &dmg_mech, 0 };
UnitAttachmentPoint turret_Atv = { MOBD_SURV_ATV, UNIT_AttachHandler_Turret, 8, 30, 90, 10, 0x300, 0x300, &dmg_rifle, 0 };
UnitAttachmentPoint turret_AtvFlamethrower = { MOBD_SURV_ATV_FLAMETHROWER, UNIT_AttachHandler_Turret, 8, 120, 120, 1, 0x300, 0x300, &dmg_flamethrower, 0 };
UnitAttachmentPoint turret_MonsterTruck = { MOBD_MUTE_MONSTER_TRUCK, UNIT_AttachHandler_Turret, 8, 30, 90, 10, 0x2C0, 0x2C0, &dmg_rifle, 0 };
UnitAttachmentPoint turret_4x4Pickup = { MOBD_MUTE_MONSTER_TRUCK, UNIT_AttachHandler_Turret, 8, 45, 60, 10, 0x2C0, 0x2C0, &dmg_rifle, 0 };
UnitAttachmentPoint turret_SidecarBike = { MOBD_MUTE_BIKE_SIDECAR, UNIT_AttachHandler_Turret, 8, 45, 60, 10, 0x300, 0x300, &dmg_rifle, 0 };
UnitAttachmentPoint turret_WarMastadont = { MOBD_MUTE_WAR_MASTADONT, UNIT_AttachHandler_Turret, 8, 10, 160, 4, 0x5C0, 0x5C0, &dmg_shell_mastadont, 0 };
UnitAttachmentPoint turret_BarrageCraft = { MOBD_SURV_BARRAGE_CRAFT, UNIT_AttachHandler_Turret, 8, 20, 420, 6, 0x2C0, 0x2C0, &dmg_rocket_barragecraft, 0 };
UnitAttachmentPoint turret_AutocannonTank = { MOBD_SURV_AUTOCANNON_TANK, UNIT_AttachHandler_Turret, 8, 5, 5, 1, 0x480, 0x440, &dmg_rifle, 0 };
UnitAttachmentPoint turret_MissileCrab = { MOBD_MUTE_MISSILE_CRAB, UNIT_AttachHandler_Turret, 8, 30, 90, 2, 0x5C0, 0x5C0, &dmg_rocket_misslecraft, 0 };
UnitAttachmentPoint turret_CannonTower = { MOBD_SURV_CANNON_TOWER, UNIT_AttachHandler_Turret, 8, 10, 125, 2, 0x2BC, 0x27C, &dmg_shell_cannontower, 0 };
UnitAttachmentPoint turret_GuardTower = { MOBD_SURV_GUARD_TOWER, UNIT_AttachHandler_Turret, 8, 15, 90, 10, 0x1A0, 0x1A0, &dmg_rifle, 0 };
UnitAttachmentPoint turret_MachineGunNest = { MOBD_MUTE_MACHINEGUN_NEST, UNIT_AttachHandler_Turret, 8, 15, 90, 10, 0x17C, 0x17C, &dmg_rifle, 0 };
UnitAttachmentPoint turret_GrapeshotCannon = { MOBD_MUTE_GRAPESHOT_TOWER, UNIT_AttachHandler_Turret, 8, 0, 120, 10, 0x23C, 0x23C, &dmg_grapeshot, 0 };
UnitAttachmentPoint turret_RocketTower = { MOBD_SURV_MISSILE_BATTERY, UNIT_AttachHandler_Turret, 2, 30, 120, 3, 0x1B4, 0x174, &dmg_rocket_tower, 0 };
UnitAttachmentPoint turret_RotaryCannon = { MOBD_MUTE_ROTARY_CANNON, UNIT_AttachHandler_Turret, 8, 6, 10, 10, 0x2FC, 0x2BC, &dmg_rifle, 0 };
UnitAttachmentPoint attach_Bomber = { MOBD_SURV_BOMBER, UNIT_AttachHandler_DockPoint, 0, 0, 0, 0, 0x1FC, 0x1FC, 0, 0 };
UnitAttachmentPoint attach_Wasp = { MOBD_MUTE_WASP, UNIT_AttachHandler_DockPoint, 0, 0, 0, 0, 0x240, 0x240, 0, 0 };
UnitAttachmentPoint attach_PowerStation1 = { MOBD_SURV_POWER_STATION, UNIT_AttachHandler_DockPoint, 0, 0, 0, 0, 0x104, 0x104, 0, 0 };
UnitAttachmentPoint attach_PowerStation2 = { MOBD_MUTE_POWER_STATION, UNIT_AttachHandler_DockPoint, 0, 0, 0, 0, 0x104, 0x104, 0, 0 };
UnitAttachmentPoint attach_Outpost = { MOBD_SURV_OUTPOST, UNIT_AttachHandler_DockPoint, 0, 0, 0, 0, 0x410, 0x410, 0, 0 };
UnitAttachmentPoint attach_MachineShop = { MOBD_SURV_MACHINE_SHOP, UNIT_AttachHandler_DockPoint, 0, 0, 0, 0, 0x104, 0x104, 0, 0 };
UnitAttachmentPoint attach_BeastEnclosure = { MOBD_MUTE_BEAST_ENCLOSURE, UNIT_AttachHandler_DockPoint, 0, 0, 0, 0, 0x104, 0x104, 0, 0 };
UnitAttachmentPoint attach_RepairBay = { MOBD_SURV_REPAIR_BAY, UNIT_AttachHandler_DockPoint, 0, 0, 0, 0, 0x140, 0x140, 0, 0 };
UnitAttachmentPoint attach_surv_drillrig = { MOBD_SURV_DRILLRIG, UNIT_AttachHandler_DockPoint, 0, 0, 0, 0, 0xEC, 0xEC, 0, 0 };
UnitAttachmentPoint attach_mute_drillrig = { MOBD_MUTE_DRILLRIG, UNIT_AttachHandler_DockPoint, 0, 0, 0, 0, 0xC8, 0xC8, 0, 0 };
UnitAttachmentPoint attach_Research1 = { MOBD_SURV_RESEARCH_LAB, UNIT_AttachHandler_DockPoint, 0, 0, 0, 0, 0xE0, 0xE0, 0, 0 };
UnitAttachmentPoint attach_TechBunker = { MOBD_TECH_BUNKER, UNIT_AttachHandler_DockPoint, 0, 0, 0, 0, 0xDC, 0xDC, 0, 0 };
UnitAttachmentPoint attach_Research2 = { MOBD_MUTE_ALCHEMY_HALL, UNIT_AttachHandler_DockPoint, 0, 0, 0, 0, 0xE0, 0xE0, 0, 0 };
UnitAttachmentPoint attach_blacksmith = { MOBD_MUTE_BLACKSMITH, UNIT_AttachHandler_DockPoint, 0, 0, 0, 0, 0xE0, 0xE0, 0, 0 };
UnitAttachmentPoint attach_MobileDerrick = { MOBD_MUTE_MOBILE_DERRICK, UNIT_AttachHandler_DockPoint, 0x14, 0, 0, 0, 0x240, 0x240, 0, 0 };
UnitAttachmentPoint attach_clanhall = { MOBD_MUTE_CLANHALL, UNIT_AttachHandler_DockPoint, 0, 0, 0, 0, 0x308, 0x308, 0, 0 };


UnitStat unit_stats[89] =
{
	{
		MOBD_SURV_RIFLEMAN,
		&UNIT_Handler_Infantry,
		"Rifleman",
		50,
		400,
		30,
		60,
		64,
		160,
		96,
		65,
		0,
		1,
		1408,
		1472,
		1344,
		-1,
		NULL,
		&dmg_rifle,
		512,
		SURVIVORS,
		10,
		10,
		UNIT_STATS_SURV_OUTPOST,
		2
	},
	{
		MOBD_MUTE_BERSERKER,
		&UNIT_Handler_Infantry,
		"Berserker",
		40,
		320,
		30,
		60,
		64,
		160,
		96,
		60,
		0,
		1,
		1600,
		1664,
		1536,
		-1,
		NULL,
		&dmg_bow,
		512,
		EVOLVED,
		12,
		12,
		UNIT_STATS_MUTE_CLANHALL,
		3
	},
	{
		MOBD_SURV_FLAMER,
		&UNIT_Handler_Infantry,
		"Flamer",
		75,
		400,
		30,
		120,
		64,
		128,
		80,
		50,
		0,
		1,
		1408,
		1472,
		1344,
		-1,
		NULL,
		&dmg_flamethrower,
		512,
		SURVIVORS,
		15,
		15,
		UNIT_STATS_SURV_OUTPOST,
		5
	},
	{
		MOBD_MUTE_PYROMANIAC,
		&UNIT_Handler_Infantry,
		"Pyromaniac",
		75,
		400,
		30,
		120,
		64,
		128,
		80,
		50,
		0,
		1,
		1408,
		1472,
		1344,
		-1,
		NULL,
		&dmg_flamethrower,
		512,
		EVOLVED,
		15,
		15,
		UNIT_STATS_MUTE_CLANHALL,
		5
	},
	{
		MOBD_SURV_SWAT,
		&UNIT_Handler_Infantry,
		"SWAT",
		75,
		500,
		30,
		60,
		64,
		192,
		128,
		70,
		0,
		1,
		1408,
		1472,
		1344,
		-1,
		NULL,
		&dmg_swat,
		512,
		SURVIVORS,
		15,
		15,
		UNIT_STATS_SURV_OUTPOST,
		5
	},
	{
		MOBD_MUTE_SHOTGUNNER,
		&UNIT_Handler_Infantry,
		"Shotgunner",
		75,
		500,
		30,
		90,
		64,
		160,
		128,
		90,
		0,
		1,
		1472,
		1536,
		1408,
		-1,
		NULL,
		&dmg_shotgunner,
		512,
		EVOLVED,
		15,
		15,
		UNIT_STATS_MUTE_CLANHALL,
		5
	},
	{
		MOBD_SURV_SAPPER,
		&UNIT_Handler_Infantry,
		"Sapper",
		125,
		500,
		30,
		120,
		64,
		160,
		96,
		90,
		0,
		1,
		2176,
		2240,
		2112,
		-1,
		NULL,
		&dmg_sapper,
		512,
		SURVIVORS,
		20,
		20,
		UNIT_STATS_SURV_OUTPOST,
		7
	},
	{
		MOBD_MUTE_RIOTER,
		&UNIT_Handler_Infantry,
		"Rioter",
		125,
		500,
		30,
		120,
		64,
		160,
		96,
		90,
		0,
		1,
		1536,
		1600,
		1472,
		-1,
		NULL,
		&dmg_sapper,
		512,
		EVOLVED,
		20,
		20,
		UNIT_STATS_MUTE_CLANHALL,
		7
	},
	{
		MOBD_SURV_GENERAL,
		&UNIT_Handler_Infantry,
		"El Presidente",
		450,
		600,
		30,
		90,
		64,
		160,
		96,
		75,
		0,
		1,
		1408,
		1472,
		1344,
		-1,
		NULL,
		&dmg_rifle,
		512,
		SURVIVORS,
		10,
		100,
		UNIT_STATS_SURV_OUTPOST,
		10
	},
	{
		MOBD_MUTE_CHIEFTAN,
		&UNIT_Handler_Infantry,
		"King Zog",
		450,
		600,
		30,
		90,
		64,
		160,
		96,
		75,
		0,
		1,
		1408,
		1472,
		1344,
		-1,
		NULL,
		&dmg_rifle,
		512,
		EVOLVED,
		10,
		100,
		UNIT_STATS_MUTE_CLANHALL,
		10
	},
	{
		MOBD_SURV_SABOTEUR,
		&UNIT_Handler_Infantry,
		"Saboteur",
		100,
		600,
		35,
		120,
		64,
		160,
		96,
		75,
		0,
		1,
		1408,
		1472,
		1344,
		-1,
		NULL,
		&dmg_rifle,
		512,
		SURVIVORS,
		10,
		100,
		UNIT_STATS_SURV_OUTPOST,
		8
	},
	{
		MOBD_MUTE_VANDAL,
		&UNIT_Handler_Infantry,
		"Vandal",
		100,
		600,
		35,
		120,
		64,
		160,
		96,
		75,
		0,
		1,
		1408,
		1472,
		1344,
		-1,
		NULL,
		&dmg_rifle,
		512,
		EVOLVED,
		10,
		100,
		UNIT_STATS_MUTE_CLANHALL,
		8
	},
	{
		MOBD_SURV_TECHNICIAN,
		&UNIT_Handler_Infantry,
		"Technician",
		150,
		500,
		35,
		10,
		64,
		160,
		96,
		75,
		0,
		1,
		-1,
		1088,
		960,
		-1,
		NULL,
		NULL,
		512,
		SURVIVORS,
		0,
		20,
		UNIT_STATS_SURV_OUTPOST,
		9
	},
	{
		MOBD_MUTE_MEKANIK,
		&UNIT_Handler_Infantry,
		"Mekanik",
		150,
		500,
		35,
		10,
		64,
		160,
		96,
		75,
		0,
		1,
		-1,
		1088,
		960,
		-1,
		NULL,
		NULL,
		512,
		EVOLVED,
		0,
		20,
		UNIT_STATS_MUTE_CLANHALL,
		9
	},
	{
		MOBD_SURV_RPG_LAUNCHER,
		&UNIT_Handler_Infantry,
		"RPG Launcher",
		150,
		400,
		30,
		150,
		64,
		224,
		160,
		75,
		0,
		1,
		1472,
		1536,
		1408,
		-1,
		NULL,
		&dmg_rocket_rpg,
		512,
		SURVIVORS,
		30,
		30,
		UNIT_STATS_SURV_OUTPOST,
		8
	},
	{
		MOBD_MUTE_BAZOOKA,
		&UNIT_Handler_Infantry,
		"Bazooka",
		150,
		400,
		30,
		150,
		64,
		224,
		160,
		75,
		0,
		1,
		1728,
		1792,
		1664,
		-1,
		NULL,
		&dmg_rocket_rpg,
		512,
		EVOLVED,
		30,
		30,
		UNIT_STATS_MUTE_CLANHALL,
		8
	},
	{
		MOBD_SURV_SNIPER,
		&UNIT_Handler_Infantry,
		"Sniper",
		200,
		600,
		35,
		90,
		64,
		288,
		224,
		90,
		0,
		1,
		1408,
		1472,
		1344,
		-1,
		NULL,
		&dmg_sniper,
		512,
		SURVIVORS,
		40,
		40,
		UNIT_STATS_SURV_OUTPOST,
		10
	},
	{
		MOBD_MUTE_CRAZY_HARRY,
		&UNIT_Handler_Infantry,
		"Crazy Harry",
		200,
		500,
		30,
		30,
		64,
		256,
		192,
		50,
		0,
		1,
		1408,
		1472,
		1344,
		-1,
		NULL,
		&dmg_sniper,
		512,
		EVOLVED,
		40,
		40,
		UNIT_STATS_MUTE_CLANHALL,
		10
	},
	{
		MOBD_SURV_GENERAL,
		&UNIT_Handler_General,
		"General",
		100,
		400,
		30,
		60,
		64,
		160,
		96,
		50,
		0,
		1,
		1408,
		1472,
		1344,
		-1,
		NULL,
		&dmg_rifle,
		512,
		SURVIVORS,
		10,
		100,
		UNIT_STATS_SURV_OUTPOST,
		10
	},
	{
		MOBD_MUTE_CHIEFTAN,
		&UNIT_Handler_Infantry,
		"Warlord",
		450,
		400,
		30,
		90,
		64,
		160,
		96,
		75,
		0,
		1,
		1408,
		1472,
		1344,
		-1,
		NULL,
		&dmg_rifle,
		512,
		EVOLVED,
		10,
		100,
		UNIT_STATS_MUTE_CLANHALL,
		10
	},
	{
		MOBD_SURV_RIFLEMAN,
		&UNIT_Handler_Infantry,
		"Scout",
		100,
		400,
		35,
		60,
		64,
		160,
		96,
		50,
		0,
		1,
		1408,
		1472,
		1344,
		-1,
		NULL,
		&dmg_rifle,
		512,
		SURVIVORS,
		15,
		15,
		UNIT_STATS_SURV_OUTPOST,
		4
	},
	{
		MOBD_SURV_MOBILE_DERRICK,
		&UNIT_Handler_MobileDerrick,
		"Derrick",
		1000,
		4000,
		30,
		12,
		3,
		0,
		0,
		0,
		1,
		0,
		-1,
		860,
		732,
		-1,
		NULL,
		NULL,
		128,
		SURVIVORS,
		0,
		500,
		UNIT_STATS_SURV_MACHINE_SHOP,
		15
	},
	{
		MOBD_MUTE_MOBILE_DERRICK,
		&UNIT_Handler_MobileDerrick,
		"Derrick",
		1000,
		4000,
		30,
		12,
		3,
		0,
		0,
		0,
		1,
		0,
		-1,
		832,
		704,
		-1,
		&attach_MobileDerrick,
		NULL,
		128,
		EVOLVED,
		0,
		500,
		UNIT_STATS_MUTE_BLACKSMITH,
		15
	},
	{
		MOBD_SURV_OIL_TANKER,
		&UNIT_Handler_OilTanker,
		"Oil Tanker",
		600,
		3000,
		35,
		35,
		3,
		0,
		0,
		0,
		1,
		0,
		-1,
		832,
		704,
		-1,
		NULL,
		NULL,
		128,
		SURVIVORS,
		0,
		200,
		UNIT_STATS_SURV_MACHINE_SHOP,
		10
	},
	{
		MOBD_MUTE_OIL_TANKER,
		&UNIT_Handler_OilTanker,
		"Oil Tanker",
		600,
		3000,
		35,
		35,
		3,
		0,
		0,
		0,
		1,
		0,
		-1,
		832,
		704,
		-1,
		NULL,
		NULL,
		128,
		EVOLVED,
		0,
		200,
		UNIT_STATS_MUTE_BLACKSMITH,
		10
	},
	{
		MOBD_SURV_OIL_TANKER,
		&UNIT_Handler_OilTankerConvoy,
		"Convoy Tanker",
		600,
		2000,
		18,
		10,
		3,
		0,
		0,
		0,
		1,
		0,
		-1,
		832,
		704,
		-1,
		NULL,
		NULL,
		128,
		SURVIVORS,
		0,
		200,
		UNIT_STATS_SURV_MACHINE_SHOP,
		10
	},
	{
		MOBD_SURV_DIRT_BIKE,
		&UNIT_Handler_Vehicle,
		"Dirt Bike",
		250,
		500,
		80,
		60,
		3,
		224,
		128,
		70,
		0,
		0,
		960,
		1024,
		896,
		-1,
		NULL,
		&dmg_rifle,
		128,
		SURVIVORS,
		10,
		10,
		UNIT_STATS_SURV_MACHINE_SHOP,
		4
	},
	{
		MOBD_MUTE_DIRE_WOLF,
		&UNIT_Handler_Vehicle,
		"Dire Wolf",
		250,
		600,
		75,
		60,
		16,
		224,
		128,
		70,
		0,
		0,
		1712,
		1776,
		1648,
		-1,
		NULL,
		&dmg_rifle,
		128,
		EVOLVED,
		20,
		20,
		UNIT_STATS_MUTE_BEAST_ENCLOSURE,
		4
	},
	{
		MOBD_SURV_4x4_PICKUP,
		&UNIT_Handler_Vehicle,
		"4x4 Pickup",
		350,
		800,
		70,
		60,
		3,
		224,
		128,
		70,
		0,
		0,
		-1,
		1024,
		896,
		-1,
		&turret_4x4Pickup,
		NULL,
		128,
		SURVIVORS,
		20,
		20,
		UNIT_STATS_SURV_MACHINE_SHOP,
		6
	},
	{
		MOBD_MUTE_BIKE_SIDECAR,
		&UNIT_Handler_Vehicle,
		"Bike & Sidecar",
		300,
		700,
		70,
		60,
		3,
		224,
		128,
		70,
		0,
		0,
		-1,
		1024,
		896,
		-1,
		&turret_SidecarBike,
		NULL,
		128,
		EVOLVED,
		20,
		20,
		UNIT_STATS_MUTE_BLACKSMITH,
		6
	},
	{
		MOBD_SURV_ATV,
		&UNIT_Handler_Vehicle,
		"All terrain Vehicle",
		500,
		1200,
		60,
		30,
		3,
		256,
		160,
		70,
		1,
		0,
		-1,
		1024,
		896,
		-1,
		&turret_Atv,
		NULL,
		128,
		SURVIVORS,
		30,
		30,
		UNIT_STATS_SURV_MACHINE_SHOP,
		7
	},
	{
		MOBD_MUTE_MONSTER_TRUCK,
		&UNIT_Handler_Vehicle,
		"Monster Truck",
		450,
		1000,
		55,
		30,
		3,
		256,
		160,
		70,
		1,
		0,
		-1,
		1024,
		896,
		-1,
		&turret_MonsterTruck,
		NULL,
		128,
		EVOLVED,
		30,
		30,
		UNIT_STATS_MUTE_BLACKSMITH,
		7
	},
	{
		MOBD_SURV_ATV_FLAMETHROWER,
		&UNIT_Handler_Vehicle,
		"ATV Flamethrower",
		550,
		1200,
		55,
		90,
		3,
		256,
		96,
		50,
		1,
		0,
		-1,
		1024,
		896,
		-1,
		&turret_AtvFlamethrower,
		NULL,
		128,
		SURVIVORS,
		70,
		70,
		UNIT_STATS_SURV_MACHINE_SHOP,
		10
	},
	{
		MOBD_MUTE_GIANT_SCORPION,
		&UNIT_Handler_Vehicle,
		"Giant Scorpion",
		600,
		1000,
		45,
		120,
		3,
		224,
		160,
		70,
		1,
		0,
		1536,
		1600,
		1472,
		-1,
		NULL,
		&dmg_scorpion,
		128,
		EVOLVED,
		50,
		50,
		UNIT_STATS_MUTE_BEAST_ENCLOSURE,
		8
	},
	{
		MOBD_SURV_ANACONDA_TANK,
		&UNIT_Handler_Vehicle,
		"Anaconda Tank",
		850,
		1600,
		45,
		150,
		3,
		256,
		192,
		75,
		1,
		0,
		-1,
		1216,
		1088,
		-1,
		&turret_AnacondaCannon,
		NULL,
		128,
		SURVIVORS,
		60,
		60,
		UNIT_STATS_SURV_MACHINE_SHOP,
		10
	},
	{
		MOBD_MUTE_WAR_MASTADONT,
		&UNIT_Handler_Vehicle,
		"War Mastodon",
		800,
		1600,
		35,
		140,
		3,
		256,
		192,
		80,
		1,
		0,
		-1,
		1728,
		1600,
		-1,
		&turret_WarMastadont,
		NULL,
		128,
		EVOLVED,
		80,
		80,
		UNIT_STATS_MUTE_BEAST_ENCLOSURE,
		12
	},
	{
		MOBD_SURV_BARRAGE_CRAFT,
		&UNIT_Handler_Vehicle,
		"Barrage Craft",
		1000,
		1800,
		30,
		60,
		3,
		304,
		240,
		80,
		1,
		0,
		-1,
		832,
		832,
		-1,
		&turret_BarrageCraft,
		NULL,
		128,
		SURVIVORS,
		80,
		80,
		UNIT_STATS_SURV_MACHINE_SHOP,
		12
	},
	{
		MOBD_MUTE_GIANT_BEETLE,
		&UNIT_Handler_Vehicle,
		"Giant Beetle",
		900,
		1200,
		30,
		150,
		3,
		256,
		192,
		85,
		1,
		0,
		2488,
		2552,
		2424,
		-1,
		NULL,
		&dmg_beetle,
		128,
		EVOLVED,
		90,
		90,
		UNIT_STATS_MUTE_BEAST_ENCLOSURE,
		13
	},
	{
		MOBD_SURV_AUTOCANNON_TANK,
		&UNIT_Handler_Vehicle,
		"Autocannon Tank",
		1200,
		1700,
		30,
		3,
		3,
		288,
		224,
		70,
		1,
		0,
		-1,
		1408,
		1280,
		-1,
		&turret_AutocannonTank,
		NULL,
		4096,
		SURVIVORS,
		120,
		100,
		UNIT_STATS_SURV_MACHINE_SHOP,
		15
	},
	{
		MOBD_MUTE_MISSILE_CRAB,
		&UNIT_Handler_Vehicle,
		"Missile Crab",
		1100,
		1800,
		30,
		60,
		3,
		320,
		256,
		93,
		1,
		0,
		-1,
		1728,
		1600,
		-1,
		&turret_MissileCrab,
		NULL,
		4096,
		EVOLVED,
		120,
		100,
		UNIT_STATS_MUTE_BEAST_ENCLOSURE,
		15
	},
	{
		MOBD_SURV_MOBILE_OUTPOST,
		&UNIT_Handler_MobileOutpost,
		"Mobile Outpost",
		300,
		6000,
		20,
		60,
		3,
		160,
		96,
		70,
		1,
		0,
		-1,
		960,
		832,
		768,
		NULL,
		NULL,
		4096,
		SURVIVORS,
		0,
		200,
		UNIT_STATS_SURV_MACHINE_SHOP,
		30
	},
	{
		MOBD_MUTE_CLANHALL_WAGON,
		&UNIT_Handler_MobileOutpost,
		"Clanhall Wagon",
		300,
		6000,
		20,
		60,
		3,
		160,
		96,
		70,
		1,
		0,
		-1,
		832,
		704,
		640,
		NULL,
		NULL,
		4096,
		EVOLVED,
		0,
		200,
		UNIT_STATS_MUTE_BLACKSMITH,
		30
	},
	{
		MOBD_SURV_ANACONDA_TANK,
		NULL,
		"Orville ultralight",
		1500,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		NULL,
		NULL,
		0,
        PLAYER_SIDE_UNSPECIFIED,
		0,
		0,
		UNIT_STATS_SURV_RIFLEMAN,
		0
	},
	{
		MOBD_MUTE_WASP,
		&UNIT_Handler_Aircraft,
		"Wasp",
		2000,
		750,
		120,
		60,
		1,
		160,
		96,
		70,
		0,
		0,
		832,
		896,
		768,
		704,
		&attach_Wasp,
		&dmg_bomber,
		128,
		EVOLVED,
		120,
		100,
		UNIT_INVALID,
		300
	},
	{
		MOBD_SURV_BOMBER,
		&UNIT_Handler_Aircraft,
		"Bomber",
		2000,
		750,
		120,
		60,
		1,
		160,
		96,
		70,
		0,
		0,
		764,
		828,
		700,
		636,
		&attach_Bomber,
		&dmg_bomber,
		128,
		SURVIVORS,
		120,
		100,
		UNIT_INVALID,
		300
	},
	{
		MOBD_SURV_ANACONDA_TANK,
		NULL,
		"Kamikaze Rocket",
		2000,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		NULL,
		NULL,
		0,
        PLAYER_SIDE_UNSPECIFIED,
		0,
		0,
		UNIT_STATS_SURV_RIFLEMAN,
		0
	},
	{
		MOBD_SURV_DRILLRIG,
		&UNIT_Handler_DrillRig,
		"Drill Rig",
		1000,
		4000,
		0,
		0,
		0,
		0,
		0,
		0,
		1,
		0,
		428,
		-1,
		364,
		300,
		&attach_surv_drillrig,
		&dmg_drill_rig,
		128,
		SURVIVORS,
		0,
		500,
		UNIT_STATS_SURV_MACHINE_SHOP,
		0
	},
	{
		MOBD_MUTE_DRILLRIG,
		&UNIT_Handler_DrillRig,
		"Drill Rig",
		1000,
		4000,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		392,
		-1,
		328,
		264,
		&attach_mute_drillrig,
		&dmg_drill_rig,
		128,
		EVOLVED,
		0,
		500,
		UNIT_STATS_MUTE_BLACKSMITH,
		0
	},
	{
		MOBD_SURV_POWER_STATION,
		&UNIT_Handler_PowerStation,
		"Power Station",
		1300,
		4000,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		452,
		516,
		388,
		324,
		&attach_PowerStation1,
		&dmg_drill_rig,
		128,
		SURVIVORS,
		0,
		120,
		UNIT_INVALID,
		15
	},
	{
		MOBD_MUTE_POWER_STATION,
		&UNIT_Handler_PowerStation,
		"Power Station",
		1300,
		4000,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		452,
		516,
		388,
		324,
		&attach_PowerStation2,
		&dmg_drill_rig,
		128,
		EVOLVED,
		0,
		120,
		UNIT_INVALID,
		15
	},
	{
		MOBD_SURV_DETENTION_CENTER,
		&UNIT_Handler_Prison,
		"Detention Center",
		250,
		2000,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		344,
		408,
		280,
		216,
		NULL,
		&dmg_drill_rig,
		128,
		SURVIVORS,
		0,
		100,
		UNIT_INVALID,
		15
	},
	{
		MOBD_MUTE_HOLDING_PEN,
		&UNIT_Handler_Prison,
		"Holding Pen",
		250,
		2000,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		344,
		408,
		280,
		216,
		NULL,
		&dmg_drill_rig,
		128,
		EVOLVED,
		0,
		100,
		UNIT_INVALID,
		15
	},
	{
		MOBD_SURV_GUARD_TOWER,
		&UNIT_Handler_GuardTower,
		"Guard Tower",
		500,
		1200,
		0,
		0,
		0,
		208,
		192,
		90,
		0,
		0,
		608,
		672,
		544,
		544,
		&turret_GuardTower,
		NULL,
		128,
		SURVIVORS,
		100,
		100,
		UNIT_INVALID,
		15
	},
	{
		MOBD_MUTE_MACHINEGUN_NEST,
		&UNIT_Handler_GuardTower,
		"Machinegun Nest",
		500,
		1200,
		0,
		0,
		0,
		208,
		192,
		90,
		0,
		0,
		572,
		636,
		508,
		508,
		&turret_MachineGunNest,
		NULL,
		128,
		EVOLVED,
		100,
		100,
		UNIT_INVALID,
		15
	},
	{
		MOBD_SURV_CANNON_TOWER,
		&UNIT_Handler_GuardTower,
		"Cannon Tower",
		2500,
		2400,
		0,
		0,
		0,
		320,
		256,
		90,
		0,
		0,
		892,
		956,
		828,
		764,
		&turret_CannonTower,
		NULL,
		128,
		SURVIVORS,
		80,
		80,
		UNIT_INVALID,
		45
	},
	{
		MOBD_MUTE_GRAPESHOT_TOWER,
		&UNIT_Handler_GuardTower,
		"GrapeShot Cannon",
		1500,
		1800,
		0,
		0,
		0,
		320,
		256,
		50,
		0,
		0,
		764,
		828,
		700,
		636,
		&turret_GrapeshotCannon,
		NULL,
		128,
		EVOLVED,
		80,
		80,
		UNIT_INVALID,
		30
	},
	{
		MOBD_SURV_MISSILE_BATTERY,
		&UNIT_Handler_GuardTower,
		"Missile Battery",
		1500,
		1800,
		0,
		0,
		0,
		320,
		256,
		90,
		0,
		0,
		628,
		692,
		564,
		500,
		&turret_RocketTower,
		NULL,
		128,
		SURVIVORS,
		80,
		80,
		UNIT_INVALID,
		30
	},
	{
		MOBD_MUTE_ROTARY_CANNON,
		&UNIT_Handler_GuardTower,
		"Rotary Cannon",
		2500,
		2500,
		0,
		0,
		0,
		324,
		260,
		75,
		0,
		0,
		956,
		1020,
		892,
		892,
		&turret_RotaryCannon,
		NULL,
		128,
		EVOLVED,
		100,
		100,
		UNIT_INVALID,
		45
	},
	{
		MOBD_SURV_OUTPOST,
		&UNIT_Handler_Outpost,
		"Outpost",
		1000,
		6000,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		1232,
		1296,
		1168,
		1104,
		&attach_Outpost,
		NULL,
		128,
		SURVIVORS,
		0,
		300,
		UNIT_INVALID,
		25
	},
	{
		MOBD_MUTE_CLANHALL,
		&UNIT_Handler_Clanhall,
		"Clanhall",
		1000,
		6000,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		968,
		1032,
		904,
		840,
		&attach_clanhall,
		NULL,
		128,
		EVOLVED,
		0,
		300,
		UNIT_INVALID,
		25
	},
	{
		MOBD_SURV_MACHINE_SHOP,
		&UNIT_Handler_MachineShop,
		"Machine Shop",
		1000,
		4000,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		452,
		516,
		388,
		324,
		&attach_MachineShop,
		NULL,
		128,
		SURVIVORS,
		0,
		200,
		UNIT_INVALID,
		25
	},
	{
		MOBD_MUTE_BLACKSMITH,
		&UNIT_Handler_Blacksmith,
		"Blacksmith",
		550,
		3200,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		416,
		480,
		352,
		288,
		&attach_blacksmith,
		NULL,
		128,
		EVOLVED,
		0,
		150,
		UNIT_INVALID,
		20
	},
	{
		MOBD_MUTE_BEAST_ENCLOSURE,
		&UNIT_Handler_BeastEnclosure,
		"Beast Enclosure",
		550,
		3200,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		452,
		516,
		388,
		324,
		&attach_BeastEnclosure,
		NULL,
		128,
		EVOLVED,
		0,
		200,
		UNIT_INVALID,
		20
	},
	{
		MOBD_SURV_REPAIR_BAY,
		&UNIT_Handler_RepairStation,
		"Repair Bay",
		1000,
		3000,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		512,
		576,
		448,
		384,
		&attach_RepairBay,
		NULL,
		128,
		SURVIVORS,
		0,
		100,
		UNIT_INVALID,
		30
	},
	{
		MOBD_MUTE_MENAGERIE,
		&UNIT_Handler_RepairStation,
		"Menagerie",
		1000,
		3000,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		428,
		492,
		364,
		300,
		NULL,
		NULL,
		128,
		EVOLVED,
		0,
		100,
		UNIT_INVALID,
		30
	},
	{
		MOBD_SURV_RESEARCH_LAB,
		&UNIT_Handler_ResearchBuilding,
		"Research Lab",
		700,
		3000,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		416,
		480,
		352,
		288,
		&attach_Research1,
		NULL,
		128,
		SURVIVORS,
		0,
		10,
		UNIT_INVALID,
		25
	},
	{
		MOBD_MUTE_ALCHEMY_HALL,
		&UNIT_Handler_ResearchBuilding,
		"Alchemy Hall",
		700,
		3000,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		416,
		480,
		352,
		288,
		&attach_Research2,
		NULL,
		128,
		EVOLVED,
		0,
		10,
		UNIT_INVALID,
		25
	},
	{
		MOBD_TECH_BUNKER,
		&UNIT_Handler_TechBunker,
		"Tech Bunker",
		700,
		3000,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		412,
		476,
		348,
		-1,
		&attach_TechBunker,
		NULL,
		128,
        PLAYER_SIDE_UNSPECIFIED,
		0,
		10,
		UNIT_INVALID,
		25
	},
	{
		MOBD_HUT,
		&UNIT_Handler_Hut,
		"Hut",
		700,
		300,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		-1,
		528,
		400,
		336,
		NULL,
		NULL,
		128,
		EVOLVED,
		0,
		10,
		UNIT_INVALID,
		25
	},
	{
		MOBD_SURV_ANACONDA_TANK,
		NULL,
		"Wall",
		50,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		NULL,
		NULL,
		0,
        PLAYER_SIDE_UNSPECIFIED,
		0,
		0,
		UNIT_STATS_SURV_RIFLEMAN,
		0
	},
	{
		MOBD_SURV_ANACONDA_TANK,
		NULL,
		"Wall",
		50,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		NULL,
		NULL,
		0,
        PLAYER_SIDE_UNSPECIFIED,
		0,
		0,
		UNIT_STATS_SURV_RIFLEMAN,
		0
	},
	{
		MOBD_SURV_ANACONDA_TANK,
		NULL,
		"Wall",
		150,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		NULL,
		NULL,
		0,
        PLAYER_SIDE_UNSPECIFIED,
		0,
		0,
		UNIT_STATS_SURV_RIFLEMAN,
		0
	},
	{
		MOBD_SURV_ANACONDA_TANK,
		NULL,
		"Wall",
		150,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		NULL,
		NULL,
		0,
        PLAYER_SIDE_UNSPECIFIED,
		0,
		0,
		UNIT_STATS_SURV_RIFLEMAN,
		0
	},
	{
		MOBD_SURV_ANACONDA_TANK,
		NULL,
		"U.F.O.",
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		NULL,
		NULL,
		0,
        PLAYER_SIDE_UNSPECIFIED,
		0,
		0,
		UNIT_STATS_SURV_RIFLEMAN,
		0
	},
	{
		MOBD_GORT,
		&UNIT_Handler_Vehicle,
		"Gort The Robot",
		50,
		3500,
		40,
		35,
		64,
		192,
		128,
		80,
		1,
		0,
		2684,
		2748,
		2620,
		-1,
		NULL,
		&dmg_gort,
		4096,
        PLAYER_SIDE_UNSPECIFIED,
		100,
		100,
		UNIT_INVALID,
		0
	},
	{
		MOBD_SURV_ANACONDA_TANK,
		&UNIT_Handler_Vehicle,
		"G.O.R.N.",
		50,
		3600,
		40,
		120,
		3,
		224,
		160,
		80,
		1,
		0,
		-1,
		1216,
		1088,
		-1,
		&turret_AnacondaCannon,
		NULL,
		128,
        PLAYER_SIDE_UNSPECIFIED,
		100,
		100,
		UNIT_INVALID,
		0
	},
	{
		MOBD_PLASMA_TANK,
		&UNIT_Handler_Vehicle,
		"Plasma Tank",
		50,
		3600,
		40,
		120,
		3,
		288,
		224,
		85,
		1,
		0,
		-1,
		1176,
		1048,
		-1,
		&turret_PlasmaCannon,
		NULL,
		4096,
        PLAYER_SIDE_UNSPECIFIED,
		80,
		80,
		UNIT_INVALID,
		0
	},
	{
		MOBD_SENTINEL_DROID,
		&UNIT_Handler_Vehicle,
		"Sentinel Droid",
		50,
		3600,
		40,
		90,
		3,
		288,
		224,
		95,
		1,
		0,
		-1,
		1920,
		1792,
		-1,
		&turret_SentinelDroid,
		NULL,
		128,
        PLAYER_SIDE_UNSPECIFIED,
		70,
		70,
		UNIT_INVALID,
		0
	},
	{
		MOBD_MECH,
		&UNIT_Handler_Vehicle,
		"Mech",
		50,
		3600,
		40,
		120,
		3,
		256,
		192,
		95,
		1,
		0,
		-1,
		1560,
		1432,
		-1,
		&turret_mech,
		NULL,
		128,
        PLAYER_SIDE_UNSPECIFIED,
		50,
		50,
		UNIT_INVALID,
		0
	},
	{
		MOBD_SURV_ANACONDA_TANK,
		NULL,
		"Satellite radar",
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		NULL,
		NULL,
		0,
        PLAYER_SIDE_UNSPECIFIED,
		0,
		0,
		UNIT_STATS_SURV_RIFLEMAN,
		0
	},
	{
		MOBD_SURV_ANACONDA_TANK,
		NULL,
		"F.O.B.S.system",
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		NULL,
		NULL,
		0,
        PLAYER_SIDE_UNSPECIFIED,
		0,
		0,
		UNIT_STATS_SURV_RIFLEMAN,
		0
	},
	{
		MOBD_SURV_ANACONDA_TANK,
		NULL,
		"Micro fusion reactor",
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		NULL,
		NULL,
		0,
        PLAYER_SIDE_UNSPECIFIED,
		0,
		0,
		UNIT_STATS_SURV_RIFLEMAN,
		0
	},
	{
		MOBD_HUT,
		&UNIT_Handler_Hut,
		"Hut",
		700,
		300,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		464,
		528,
		400,
		-1,
		NULL,
		NULL,
		128,
		EVOLVED,
		0,
		10,
		UNIT_INVALID,
		25
	},
	{
		MOBD_TECH_BUNKER,
		&UNIT_Handler_TechBunker,
		"Tech Bunker",
		700,
		3000,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		412,
		476,
		348,
		-1,
		&attach_TechBunker,
		NULL,
		128,
        PLAYER_SIDE_UNSPECIFIED,
		0,
		10,
		UNIT_INVALID,
		25
	},
	{
		MOBD_MUTE_CHIEFTAN,
		&UNIT_Handler_Infantry,
		"Infiltrator",
		450,
		400,
		30,
		90,
		64,
		160,
		96,
		75,
		0,
		1,
		1408,
		1472,
		1344,
		-1,
		NULL,
		&dmg_rifle,
		512,
		SURVIVORS,
		10,
		100,
		UNIT_STATS_SURV_OUTPOST,
		10
	},
	{
		MOBD_SURV_ANACONDA_TANK,
		NULL,
		"Timebomb",
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		NULL,
		NULL,
		0,
        PLAYER_SIDE_UNSPECIFIED,
		0,
		0,
		UNIT_STATS_SURV_RIFLEMAN,
		0
	},
	{
		MOBD_SURV_DRILLRIG,
		NULL,
		"Tree",
		0,
		100,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		-1,
		-1,
		0,
		0,
		NULL,
		NULL,
		128,
		PLAYER_SIDE_UNSPECIFIED,
		0,
		0,
		UNIT_STATS_SURV_RIFLEMAN,
		0
	},
	{
		MOBD_SURV_ANACONDA_TANK,
		NULL,
		"AirStrike",
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		NULL,
		NULL,
		0,
        PLAYER_SIDE_UNSPECIFIED,
		0,
		0,
		UNIT_STATS_SURV_RIFLEMAN,
		0
	},
	{
		MOBD_INVALID,
		NULL,
		"No unit here massa...",
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		NULL,
		NULL,
		0,
        PLAYER_SIDE_UNSPECIFIED,
		0,
		0,
		UNIT_STATS_SURV_RIFLEMAN,
		0
	}
};
int _4731A8_speeds[] = { 0, 50, 98, 142, 181, 213, 237, 251, 256, 251, 237, 213, 181, 142, 98, 50,
	0,
	-50,
	-98,
	-142,
    -181,
    -213,
    -237,
    -251,
    -256,
    -251,
    -237,
    -213,
    -181,
    -142,
    -98,
    -50,
	0,
	50,
	98,
	142,
	181,
	213,
	237,
	251
}; // idb
char *errmsg_win95_or_later = "KKND Xtreme needs Windows 95 or Windows NT 4.0 (with Service Pack 3)";
char *errmsg_dx3_or_later = "KKND Xtreme needs DirectX 3 or greater";
char *errmsg_dx5_or_later = "KKND Xtreme needs DirectX 5 or greater";
char *errmsg_generic = "KKND Xtreme Error";
char *backslash = "\\";
char *ddraw_dll_filename = "ddraw.dll";
char aRbwbrBwB[] = "rbwbr+bw+b"; // idb
int dword_476AC0 = 0; // weak
int dword_476AC4 = 0; // weak
/*int(*off_476AC8[196])() =
{
	&sub_45A556,
	&sub_45A594,
	&sub_45A5D2,
	&sub_45A610,
	&sub_45A64E,
	&sub_45A68C,
	&sub_45A6CA,
	&sub_45A708,
	&sub_45A746,
	&sub_45A784,
	&sub_45A7C2,
	&sub_45A800,
	&sub_45A83E,
	&sub_45A87C,
	&sub_45A8BA,
	&sub_45A8F8,
	&sub_45A936,
	&sub_45A974,
	&sub_45A9B2,
	&sub_45A9F0,
	&sub_45AA2E,
	&sub_45AA6C,
	&sub_45AAAA,
	&sub_45AAE8,
	&sub_45AB26,
	&sub_45AB64,
	&sub_45ABA2,
	&sub_45ABE0,
	&sub_45AC1E,
	&sub_45AC5C,
	&sub_45AC9A,
	&sub_45ACD8,
	&sub_45AD16,
	&sub_45AD54,
	&sub_45AD92,
	&sub_45ADD0,
	&sub_45AE0E,
	&sub_45AE4C,
	&sub_45AE8A,
	&sub_45AEC8,
	&sub_45AF06,
	&sub_45AF44,
	&sub_45AF82,
	&sub_45AFC0,
	&sub_45AFFE,
	&sub_45B03C,
	&sub_45B07A,
	&sub_45B0B8,
	&sub_45B0F6,
	&sub_45B134,
	&sub_45B172,
	&sub_45B1B0,
	&sub_45B1EE,
	&sub_45B22C,
	&sub_45B26A,
	&sub_45B2A8,
	&sub_45B2E6,
	&sub_45B324,
	&sub_45B362,
	&sub_45B3A0,
	&sub_45B3DE,
	&sub_45B41C,
	&sub_45B45A,
	&sub_45B498,
	&sub_45C459,
	&sub_45C48C,
	&sub_45C4B9,
	&sub_45C4F6,
	&sub_45C51B,
	&sub_45C558,
	&sub_45C57E,
	&sub_45C5A3,
	&sub_45C5E1,
	&sub_45C620,
	&sub_45C65B,
	&sub_45C695,
	&sub_45C6C2,
	&sub_45C6EF,
	&sub_45C717,
	&sub_45C73F,
	&sub_45C76C,
	&sub_45C799,
	&sub_45C7C8,
	&sub_45C7F7,
	&sub_45C824,
	&sub_45C86C,
	&sub_45C891,
	&sub_45C8B6,
	&sub_45C8DB,
	&sub_45C918,
	&sub_45C948,
	&sub_45C985,
	&sub_45C9B6,
	&sub_45C9E9,
	&sub_45CA21,
	&sub_45CA59,
	&sub_45CA98,
	&sub_45CACB,
	&sub_45CAF8,
	&sub_45CB2A,
	&sub_45CB59,
	&sub_45CB8A,
	&sub_45CBC7,
	&sub_45CBF9,
	&sub_45CC2C,
	&sub_45CC54,
	&sub_45CC81,
	&sub_45CCA8,
	&sub_45CCC9,
	&sub_45CD06,
	&sub_45CD33,
	&sub_45CD61,
	&sub_45CD9E,
	&sub_45CDCD,
	&sub_45CE00,
	&sub_45CE33,
	&sub_45CE61,
	&sub_45CEA3,
	&sub_45CED4,
	&sub_45CF0B,
	&sub_45CF4C,
	&sub_45CF87,
	&sub_45CFBA,
	&sub_45CFEA,
	&sub_45D01C,
	&sub_45D057,
	&sub_45D098,
	&sub_45D0D0,
	&sub_45B4D6,
	&sub_45B51C,
	&sub_45B54A,
	&sub_45B58B,
	&sub_45B5C1,
	&sub_45B606,
	&sub_45B63B,
	&sub_45B67C,
	&sub_45B6AE,
	&sub_45B6E0,
	&sub_45B716,
	&sub_45B74C,
	&sub_45B78D,
	&sub_45B7CD,
	&sub_45B80B,
	&sub_45B84A,
	&sub_45B88A,
	&sub_45B8C9,
	&sub_45B906,
	&sub_45B944,
	&sub_45B972,
	&sub_45B9BE,
	&sub_45B9F4,
	&sub_45BA2A,
	&sub_45BA6F,
	&sub_45BAB4,
	&sub_45BAEE,
	&sub_45BB31,
	&sub_45BB6A,
	&sub_45BBA9,
	&sub_45BBEA,
	&sub_45BC2B,
	&sub_45BC6A,
	&sub_45BCB0,
	&sub_45BCF0,
	&sub_45BD34,
	&sub_45BD72,
	&sub_45BDAB,
	&sub_45BDEE,
	&sub_45BE26,
	&sub_45BE65,
	&sub_45BEA7,
	&sub_45BEE9,
	&sub_45BF29,
	&sub_45BF69,
	&sub_45BFAC,
	&sub_45BFE3,
	&sub_45C019,
	&sub_45C05C,
	&sub_45C091,
	&sub_45C0D0,
	&sub_45C10F,
	&sub_45C145,
	&sub_45C179,
	&sub_45C1BA,
	&sub_45C1FD,
	&sub_45C241,
	&sub_45C284,
	&sub_45C2C7,
	&sub_45C30A,
	&sub_45C34B,
	&sub_45C38E,
	&sub_45C3D2,
	&sub_45C417,
	&sub_45A3C4,
	&sub_45A3E7,
	&sub_45A43F,
	&sub_45A460
}; // weak*/
//int(*off_476DC8[4])() = { &sub_45A3C4, &sub_45A3E7, &sub_45A43F, &sub_45A460 }; // weak
int dword_476DD8 = 0; // weak
int dword_476DDC = 0; // weak
__int16 word_476DE0[] = { 0 }; // weak
int dword_476FE0 = 0; // weak
/*int(*off_476FE4[196])() =
{
	&sub_45D4D0,
	&sub_45D511,
	&sub_45D55A,
	&sub_45D5CB,
	&sub_45D612,
	&sub_45D65F,
	&sub_45D6A6,
	&sub_45D6FF,
	&sub_45D757,
	&sub_45D7AF,
	&sub_45D80D,
	&sub_45D86B,
	&sub_45D8BD,
	&sub_45D90F,
	&sub_45D964,
	&sub_45D9B9,
	&sub_45DA14,
	&sub_45DA6F,
	&sub_45DACA,
	&sub_45DB25,
	&sub_45DB6E,
	&sub_45DBAB,
	&sub_45DBF2,
	&sub_45DC39,
	&sub_45DC86,
	&sub_45DCDF,
	&sub_45DD24,
	&sub_45DD83,
	&sub_45DDC8,
	&sub_45DE2D,
	&sub_45DE8F,
	&sub_45DEF1,
	&sub_45DF62,
	&sub_45DFA3,
	&sub_45DFFE,
	&sub_45E03F,
	&sub_45E09A,
	&sub_45E0DF,
	&sub_45E13E,
	&sub_45E183,
	&sub_45E1E8,
	&sub_45E22B,
	&sub_45E274,
	&sub_45E2B7,
	&sub_45E306,
	&sub_45E365,
	&sub_45E3B7,
	&sub_45E409,
	&sub_45E468,
	&sub_45E4BA,
	&sub_45E51F,
	&sub_45E584,
	&sub_45E5D6,
	&sub_45E61B,
	&sub_45E669,
	&sub_45E6B9,
	&sub_45E714,
	&sub_45E772,
	&sub_45E7C5,
	&sub_45E813,
	&sub_45E866,
	&sub_45E8C4,
	&sub_45E91F,
	&sub_45E96F,
	&sub_45FF85,
	&sub_45FFDC,
	&sub_46001B,
	&sub_46006B,
	&sub_4600A8,
	&sub_4600FF,
	&sub_46013E,
	&sub_460199,
	&sub_4601EE,
	&sub_460245,
	&sub_46029F,
	&sub_4602F7,
	&sub_46033E,
	&sub_460386,
	&sub_4603D0,
	&sub_460419,
	&sub_46045E,
	&sub_4604A4,
	&sub_4604EC,
	&sub_460533,
	&sub_460572,
	&sub_4605E5,
	&sub_460622,
	&sub_46065F,
	&sub_4606B6,
	&sub_46070D,
	&sub_460758,
	&sub_4607AB,
	&sub_4607F8,
	&sub_46084F,
	&sub_4608A5,
	&sub_4608FB,
	&sub_46094D,
	&sub_4609A4,
	&sub_4609E9,
	&sub_460A40,
	&sub_460A87,
	&sub_460AD3,
	&sub_460B27,
	&sub_460B75,
	&sub_460BCD,
	&sub_460C16,
	&sub_460C5F,
	&sub_460CA8,
	&sub_460CF3,
	&sub_460D46,
	&sub_460D88,
	&sub_460DCC,
	&sub_460E20,
	&sub_460E65,
	&sub_460EBD,
	&sub_460F14,
	&sub_460F57,
	&sub_460FB2,
	&sub_461002,
	&sub_461057,
	&sub_4610B3,
	&sub_46110F,
	&sub_461166,
	&sub_4611B4,
	&sub_46120B,
	&sub_461268,
	&sub_4612C3,
	&sub_461318,
	&sub_45E9D1,
	&sub_45EA30,
	&sub_45EA71,
	&sub_45EAC5,
	&sub_45EB08,
	&sub_45EB78,
	&sub_45EBB9,
	&sub_45EC25,
	&sub_45EC7C,
	&sub_45ECD2,
	&sub_45ED25,
	&sub_45ED79,
	&sub_45EDCD,
	&sub_45EE20,
	&sub_45EE71,
	&sub_45EEC3,
	&sub_45EF10,
	&sub_45EF5C,
	&sub_45EFA6,
	&sub_45EFF1,
	&sub_45F032,
	&sub_45F0A9,
	&sub_45F0EC,
	&sub_45F12F,
	&sub_45F19F,
	&sub_45F20F,
	&sub_45F25F,
	&sub_45F2C1,
	&sub_45F30F,
	&sub_45F36D,
	&sub_45F3CD,
	&sub_45F42D,
	&sub_45F47F,
	&sub_45F4DE,
	&sub_45F52B,
	&sub_45F588,
	&sub_45F5D3,
	&sub_45F622,
	&sub_45F684,
	&sub_45F6D1,
	&sub_45F72F,
	&sub_45F781,
	&sub_45F7DC,
	&sub_45F82C,
	&sub_45F885,
	&sub_45F8E7,
	&sub_45F92E,
	&sub_45F973,
	&sub_45F9D5,
	&sub_45FA19,
	&sub_45FA77,
	&sub_45FAD5,
	&sub_45FB1B,
	&sub_45FB74,
	&sub_45FBC8,
	&sub_45FC27,
	&sub_45FC8A,
	&sub_45FCEC,
	&sub_45FD4B,
	&sub_45FDA1,
	&sub_45FDFE,
	&sub_45FE60,
	&sub_45FEC3,
	&sub_45FF24,
	&sub_45D108,
	&sub_45D147,
	&sub_45D25B,
	&sub_45D2C1
}; // weak*/
//int(*off_4772E4[4])() = { &sub_45D108, &sub_45D147, &sub_45D25B, &sub_45D2C1 }; // weak
//int(*off_4772E8[3])() = { &sub_45D147, &sub_45D25B, &sub_45D2C1 }; // weak
//int(*off_4772EC[2])() = { &sub_45D25B, &sub_45D2C1 }; // weak
//int(*off_4772F0)() = &sub_45D2C1; // weak
stru31 *stru31_list_477300 = NULL;
stru31 *stru31_list_477304 = NULL;
stru31 *stru31_list = NULL;
stru31 *stru31_list_free_pool = NULL;
int __477318_beastenclosure_negindex[] = { 0 }; // weak
stru15unit _477318_beastenclosure = { { 0, 0, 0, 0, 0 }, 0, 0, 0, 0 };
int max_beastenclosure_level = 0; // weak
int dword_477358 = 0; // weak
stru15unit _477378_clanhall = { { 0, 0, 0, 0, 0 }, 0, 0, 0, 0 };
int max_clanhall_level = 0; // weak
int _4773A0_boxd_item0_num_things = 0; // weak
DataBoxd *currently_running_lvl_boxd = NULL;
Boxd_stru0 *_4773A8_boxd_parray = NULL;
int _4773AC_boxd_item0_map_x_scale = 0; // weak
Boxd_stru0 **_4773B0_boxd_item0_things = NULL;
int _4773B4_boxd_item0_map_num_y_tiles = 0; // weak
int _4773B8_boxd_item0_map_y_scale = 0; // weak
int currently_running_lvl_boxd_valid = 0; // weak
Boxd_stru0 *_4773C0_boxd_array = NULL;
BoxdTile **_4773C4_boxd_item0_map_tiles = NULL;
int _4773C8_boxd_item0_map_num_x_tiles = 0; // weak
char byte_4773D0[68] =
{
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
	'\0',
}; // idb
int dword_477410; // weak
DataCplcItem_ptr1 *_477414_cplc_next2;
int currently_running_lvl_cplc_valid; // weak
DataCplcItem *currently_running_lvl_cplc_item;
DataCplcItem_ptr1 *_477420_cplc_next1;
void *currently_running_lvl_cplc_data; // idb
int __47C380_mapd_cplc_item0_ptr_field_4_minus_3FFF; // weak
DataCplc *currently_running_lvl_cplc;
DataCplcItem_ptr1 *_477430_cplc_item0_ptr1;
int _47C384_mapd_cplc_item0_ptr_field_8_minus_3FFF; // weak
void *_477438_cplc_item0_ptr3;
int dword_47743C; // weak
int dword_477440; // weak
DataCplc_stru0 *cplc_stru0_list_free_pool;
int _477448_cplc_x; // weak
void *_47744C_cplc_item0_ptr4;
DataCplc_stru0 *cplc_stru0_list;
int _477454_cplc_y; // weak
DataCplcItem_ptr1 *_477458_cplc_prev2;
int dword_47745C; // weak
int dword_477460; // weak
DataCplc_stru0 *cplc_stru0_list_477464;
int currently_running_lvl_cplc_data_size; // weak
DataCplcItem_ptr1 *_47746C_cplc_prev1;
OilDeposit *oilspot_list_head;
OilDeposit *oildeposit_list_end;
OilDeposit *oilspot_list;
OilDeposit *oilspot_list_free_pool;
PALETTEENTRY palette_477490[256];
int dword_477890;
int dword_477894;
int dword_477898; // weak
int dword_47789C; // weak
int dword_4778A0; // weak
PALETTEENTRY *palette_4778A4;
int dword_4778A8; // weak
int dword_4778AC; // weak
int __4778C0_stru1_anim_length; // weak
int __4778C0_stru1_anim_start; // weak
int _4087A0_stru1_should_animate; // weak
int __4778C0_stru1_anim_end; // weak
stru1_draw_params *_4778C0_stru1_anim;
int _4778C0_stru1_anim_t; // weak
int _4778C8_singleplayer_available_units_denom; // weak
Script *task_ai_players[7];
_UNKNOWN unk_4778EC; // weak
stru24 *cpu_player_scripts_attached_stru24s[7];
int dword_477940; // weak
int dword_477944; // weak
DetailedDrawHandler_VideoPlayer _477948_video_draw_details;
int _477970_video_header_field_6; // weak
int _477974_video_header_field_8; // weak
DrawJob *video_477978_draw_job;
_UNKNOWN video_477DE4_dsb_waveformatex; // weak
_UNKNOWN unk_477982; // weak
__int64 qword_477984; // weak
_UNKNOWN unk_47798C; // weak
_UNKNOWN unk_47798E; // weak
PALETTEENTRY stru_477990; // idb
DetailedDrawHandler_VideoPlayer stru_477D90; // weak
int dword_477DB8; // weak
int dword_477DBC; // weak
DrawJob *video_477DC0;
int video_477DC4_current_sound_position; // weak
int dword_477DC8; // weak
DSBUFFERDESC video_477DE4_dsb_desc; // weak
IDirectSoundBuffer *video_477DE4_dsb;
VideoFile *video;
int video_477DEC_is_sound_playing; // weak
int video_477DF0; // weak
int dword_477DF4; // weak
char video_477DF8_subtitles[756];
int video_4780EC; // weak
int video_4780F0; // weak
int video_4780F4; // weak
RenderString *video_4780F8_subtitles;
int timer_delta_updated; // weak
int timer_delta_ms; // weak
int timer_time; // weak
Entity *dword_478108[300];
int j_render_nullsub_2; // weak
int j_render_434B70; // weak
PALETTEENTRY *ppalette_4785C0;
int j_render_434A90; // weak
int(*j_render_434EA0)(void *pixels, int x, int y, int w, int h); // idb
PALETTEENTRY *_4785DC_syscolors_palette_entries;
void (*j_render_4349D0_draw_tile_32x32)(void *pixels, int x, int y); // idb
int(*j_render_4351A0_draw)(void *pixels, int x, int y, int w, int h); // idb
PALETTEENTRY palette_4785F0[256]; // weak
void(*p_render_set_clip)(int, int, int, int);
void(*j_render_434C60)(unsigned __int8 *pixels, unsigned __int8 *palette, int x, int y, int w, int h); // idb
int(*j_render_435320)(void *pixels, int x, int y, int w, int h);
void(*j_render_draw_tile)(void *data, int image_off_x, int image_off_y, int image_x_size, int image_y_size);
void(*j_render_draw_cursor_434A00)(void *pixels, int x, int y, int w, int h); // idb
int render_478A0C; // weak
int(*j_render_4349A0_draw_tile_32x32)(void *pixels, int x, int y); // idb
int _478A14_prev_stru1_palette_entries; // weak
COLORREF sys_colors[25];
void(*j_render_434BD0)(unsigned __int8 *sprite_data, unsigned __int8 *palette, int x, int y, int width, int height); // idb
int render_height; // idb
int render_width; // idb
void(*j_render_434AD0)(void *pixels, int x, int y, int w, int h); // idb
int render_478A94; // weak
int j_render_nullsub_1; // weak
DataBoxd_stru0_per_map_unit *_478AA8_boxd_stru0_array;
int _478AAC_map_height; // weak
int dword_478AB0; // weak
int _478AB4_map_width_shl_13; // weak
int _478BE8_map_info__see40E6E0[8];
char byte_478C08; // weak
int _478FF0_map_height_shl_13; // weak
int dword_478FF4; // weak
int _4793F8_map_width; // weak
int dword_47952C; // weak
int dword_47953C; // weak
int dword_479540; // weak
Sidebar *stru22_list_479548;
Sidebar *stru22_list_47954C;
Sidebar *sidebar_list;
Sidebar *sidebar_list_head;
SidebarButton *sidebar_button_list_4795A0;
SidebarButton *sidebar_button_list_4795A4;
SidebarButton *sidebar_button_list;
SidebarButton *sidebar_button_list_head;
int sidebar_button_list_sidebar_height; // weak
int sidebar_button_list_item_width; // weak
stru2 *stru2_list_4795D8;
stru2 *stru2_list_4795DC;
stru2 *stru2_list_free_pool;
stru2 *stru2_list;
stru26 _4795F0_stru26_array[3];
stru27 _479740_stru27_array[3];
tagRECT global_wnd_rect; // idb
void *render_locked_surface_ptr;
DDPIXELFORMAT pixelformat_primary;
DWORD global_wnd_style; // idb
int global_wnd_bpp; // weak
unsigned int render_locked_surface_width_px; // idb
DDSURFACEDESC ddsd_primary;
int global_fullscreen; // weak
int global_time_flows; // weak
stru1_draw_params *stru1_list_free_pool;
int global_wnd_height; // idb
DWORD global_wnd_style_ex; // idb
stru1_draw_params *stru1_list;
int fullscreen_flip_or_blt; // weak
int global_wnd_width; // idb
bool is_render_window_initialized; // 411760
IDirectDraw *pdd;
IDirectDrawPalette *pddpal_primary;
IDirectDrawClipper *pddclipper;
HWND global_hwnd; // idb
int RenderDD_initialized; // weak
int timer_render_skips; // weak
char palette_4798F8_sprt_aligned[512];
stru1_draw_params *current_drawing_params;
char byte_479B00[88]; // idb
int input_479B6C_just_pressed_keys_mask; // weak
int wnd_proc_pressed_key_id; // weak
int next_pressed_key; // weak
int input_wnd_proc_pressed_key_id; // weak
int array_479B98[25][2];
int array_479C60[25][2];
int array_479B98_array_479C60_inited; // weak
stru7 _479D48_stru7;
int is_task_list_initialized; // weak
int dword_479DBC; // weak
int _479DC0_render_string_list_initialized; // weak
int draw_list_initialized; // weak
DataSectionOffset *currently_running_lvl_sections;
int _479DCC_cplc_initialized; // weak
int _479DD0_mobd_initialized; // weak
int timer_initialized; // weak
int input_initialized; // weak
DataHunk *currently_running_lvl;
int stru1_global_obj_anim_initialized; // weak
int game_window_created; // weak
int _479DE8_boxd_initialized; // weak
int stru2_list_elements_initialized; // weak
int _479DF0_mapd_initialized; // weak
__int16 stru2_list_initialized; // weak
char current_savegame_filename[256];
char byte_479EF8[192]; // idb
char str[128];
enum LEVEL_ID game_saveload_level_idx;
int game_load_in_progress; // weak
int game_save_in_progress; // weak
int __47739C_machineshop_negindex[5]; // weak
stru15unit _47739C_machineshop;
int max_machineshop_level; // weak
char app_root_dir[20]; // idb
DataHunk *current_level_lvl; // idb
char game_installation_drive_letter; // weak
Bitmap *_47A010_mapd_item_being_drawn[3];
int _47A01C_sound_id; // weak
char game_data_root_dir[80]; // idb
char game_data_installation_dir[256];
DataHunk *wait_lvl;
int is_minimal_install;
DataHunk *sprites_lvl; // idb
int dword_47A180; // weak
int dword_47A184; // weak
int _47A18C_probably_play_outro_movie; // weak
int _47A198_custom_mission_briefing_sound_id; // idb
int dword_47A19C; // weak
int dword_47A1A0; // weak
int _47A1A4_custom_mission_briefing_line; // weak
int _47A1A8_custom_mission_idx; // weak
int _47A1AC_is_custom_surv_mission; // weak
int _47A1B0_custom_mission_briefing_ui; // weak
char global_console_argv[260];
int dword_47A2BC; // weak
char *global_cmd_line;
int game_state; // weak
int netz_47A2C8; // weak
enum LEVEL_ID current_level_idx;
__int16 current_mute_level; // weak
__int16 current_surv_level; // weak
int _47A2E4_mess_with_game_dir; // weak
int nocd; // weak
int _47A2EC_noblack; // weak
int units_stats_parsed_from_argv; // weak
int _4269B0_task_attachment__num_units_created_manually; // weak
int _47A300_stru51_array__field_4__minus1_index[5]; // weak
stru51_tech_bunkers _47A300_stru51_tech_bunkers[14];
int _4269B0_task_attachment__num_units_spawned; // weak
stru48 _47A378_stru48_array[7];
Script *script_47A3CC; // idb
int _47A3D0_unit; // weak
int _47A3D4_tanker_convoy_units_left; // weak
int _47A3D8_num_convoy_tankers_still_to_arrive; // weak
int dword_47A3DC; // weak
Entity *entity_scout;
int _47A378_stru48_array_num_items; // weak
int _47A300_stru51_tech_bunkers_num_items; // weak
DataMobd *currently_running_lvl_mobd;
Sprite *sprite_list_free_pool;
Sprite sprite_47A400; // weak
void(*j_drawjob_update_handler_426C40_default_sprite_handler)(Sprite *param, DrawJob *job);
int currently_running_lvl_mobd_valid; // weak
Sprite *sprite_list_47A4A0;
Sprite *sprite_list_47A4A4;
Sprite *sprite_list;
stru38 *stru38_list_47A4B0;
stru38 *stru38_list_47A4B4;
stru38 *stru38_list;
stru38 *stru38_list_free_pool;
stru37 *stru37_list_47A500;
stru37 *stru37_list_47A504;
stru37 *stru37_list;
stru37 *stru37_list_free_pool;
int input_mouse_window_losing_focus_reset_to_defaults; // weak
int dword_47A5A0; // weak
char byte_47A5A8[56];
Script *task_mobd17_cursor; // idb
stru13_stru0 _47A608_stru13_associated_array; // weak
stru13construct *stru13construct_list_47A638;
stru13construct *stru13construct_list_47A63C;
stru13construct *stru13construct_list;
stru13construct *stru13construct_list_free_pool;
int dword_47A6F0; // weak
int dword_47A6FC; // weak
KeyboardInput _47A700_input; // idb
int _47A660_array_num_items; // weak
RenderString *_47A730_render_string; // idb
Script *_47A734_sidebar_tooltips_task; // idb
int dword_47A738; // weak
int netz_47A828; // weak
int netz_47A82C; // weak
int dword_47A830; // weak
void *netz_47A834; // idb
int dword_47A83C; // weak
int netz_47A840; // weak
int netz_47A844; // weak
int netz_47A848; // weak
_UNKNOWN unk_47A84C; // weak
_UNKNOWN unk_47A858; // weak
netz_stru0 netz_47A868;
void *netz_47A88C; // idb
int netz_47A890; // weak
int netz_47A898_object; // weak
int netz_47A89C; // weak
int netz_47A8A0; // weak
int netz_47A8A4; // weak
int netz_47A8A8; // weak
int netz_47A8DC; // weak
void *dword_47A8E0; // idb
int netz_47A934; // weak
char byte_47A938; // weak
int netz_47B3A0; // weak
int nezt_47B3B0; // weak
ProductionGroup *_47B3B8_tower_production_group;
Entity *_47B3C0_player_outposts_clanhalls[4];
ProductionGroup *_47B3D0_building_production_group;
ProductionGroup *_47B3D4_aircraft_production_group;
int _47B3E0_unit_int_outpost_clanhall; // weak
int __47B3E0_outpost_levels_negindex[5]; // weak
stru15unit _47B3E0_outpost_levels;
int max_outpost_level; // weak
PALETTEENTRY _47B408_palette_entries[256];
PALETTEENTRY RenderDD_primary_palette_values[256];
HDC render_sw_hdc; // idb
PALETTEENTRY palette_47BC10[256];
HPALETTE render_sw_palette;
HPALETTE render_sw_default_palette; // idb
int dword_47C018; // weak
Script *receiver; // idb
Script *task_47C028; // idb
int dword_47C030; // weak
int render_clip_w; // weak
int render_clip_z; // weak
int render_clip_x; // weak
int render_clip_y; // weak
int _47C048_unit_bomberdmg; // weak
int _47C04C_num_explosions_max20; // weak
stru175 _47C050_array[20];
char byte_47C230[256]; // idb
int _47C050_array_idx; // idb
stru28 *stru28_list_47C338;
stru28 *stru28_list_47C33C;
stru28 *stru28_list;
stru28 *stru28_list_free_pool;
int _47C350_num_explosions_min0_max30; // weak
int num_explosions; // weak
Bitmap *bitmap_list;
Bitmap *bitmap_list_47C360;
Bitmap *bitmap_list_47C364;
void(*mapd_j_4391D0_handler)(Mapd_stru0 *, void *);
Bitmap *bitmap_list_free_pool;
void(*j_drawjob_update_handler_mapd_menu)(Bitmap *param, DrawJob *job);
int currently_running_lvl_mapd_num_items; // weak
Mapd_stru0 _47C380_mapd;
int currently_running_lvl_mapd_valid; // weak
int _47C390_mapd; // weak
DataMapd *currently_running_lvl_mapd;
int sound_list_end; // weak
Sound *sound_list_free_pool;
Sound *sound_list_47C3D4;
sound_stru_2 **_47C4E0_sounds;
LPDIRECTSOUND pds; // idb
int _47C4E8_num_sounds; // weak
int sound_volumes[16];
Sound *sound_list_head;
int sound_pans[16];
int Sound_47C578[16];
Sound *sound_list;
int _47C5C0_can_sound; // weak
int sound_list_last_id; // weak
void *faction_slv; // idb
BOOL sound_initialized;
int dword_47C5D0; // weak
int _47C5D4_sound_threaded_snd_id; // idb
DrawJobList draw_list_47C5D8; // idb
DrawJob *draw_list_free_pool;
DrawJobList draw_list_47C5E8; // idb
DrawJob *draw_list;
int dword_47C5F8; // weak
int _46E420_starting_cash_idx; // weak
char byte_47C600; // weak
RenderString *_47C604_mission_briefing; // idb
int dword_47C608; // idb
netz_modem *netz_modem_list;
netz_modem *netz_modem_list_free_pool;
char byte_47C654; // weak
char _47C658_faction_index; // weak
RenderString *_47C65C_render_string; // idb
int dword_47C660; // weak
Sprite *_47C664_ingame_menu_sprite;
Sprite *_47C668_ingame_menu_sprites[10];
_UNKNOWN unk_47C690; // weak
int dword_47C6B8; // idb
int netz_47C6BC_mapd_idx;
int netz_47C6C0_mapd_idx;
int dword_47C6C4; // weak
int stru29_list_initialized; // weak
int netz_modem_47C6CC_idx; // weak
int netz_modem_list_used; // idb
int _47C6D8_use__466098_cost_multipliers;
int _47C6DC_dont_execute_unit_handlers; // weak
Script *_47C6E0_task; // idb
int dword_47C6E4; // weak
int dword_47C6E8; // weak
int dword_47C6EC; // idb
int dword_47C6F0; // weak
int dword_47C6F4; // weak
int dword_47C6F8; // weak
int dword_47C700; // weak
Script *script_list_free_pool;
void(*task_creation_handler)(Script *);
Script *script_execute_list;
Script *script_list_47C714;
size_t coroutine_default_stack_size; // idb
Script *task_creation_handler_arg;
__int16 is_coroutine_list_initialization_failed; // weak
Script *script_list;
int stru8_list_size; // weak
int stru8_list_allocated; // weak
stru8 *stru8_list;
stru8 *stru8_list_head;
RenderString *render_string_list;
RenderString *render_string_list_free_pool;
RenderString *render_string_list_47C784;
BuildingPlanner _47C788_building_planner; // weak
ProductionGroup *_47C798_infantry_production_group_first;
ProductionGroup *_47C79C_infantry_production_group_last;
ProductionGroup *_47C7E4_vehicles_production_group;
ProductionGroup *stru21prod_buildings_first;
ProductionGroup *stru21prod_buildings_last;
ProductionGroup *_47C87C_stru21prod_towers_first;
ProductionGroup *_47C880_stru21prod_towers_last;
ProductionGroup *_47C8C8_stru21prod_airstrike_first;
ProductionGroup *_47C8CC_stru21prod_airstrike_last;
Sidebar *_47C914_sidebar;
ProductionGroup *production_group_list_47C918;
ProductionGroup *production_group_list_47C91C;
ProductionGroup *production_group_list;
ProductionGroup *production_group_free_pool;
Sprite *_47C96C_mobd_1F_sidebar_empty_blocks; // idb
Script *_47C970_sidebar_task; // idb
stru19production _47C978_production;
stru19production _47C990_production;
stru12_game_globals game_globals_per_player;
ProductionOption *production_option_list_47C9C8;
ProductionOption *production_option_list_47C9CC;
ProductionOption *production_option_list;
ProductionOption *production_option_list_free_pool;
RenderString *_47CA00_render_string;
SidebarButton *_47CA08_sidebar_buttons[2];
SidebarButton *_47CA10_sidebar_button_minimap;
SidebarButton *_47CA18_sidebar_production_buttons[5];
int _47CA2C_should_airstrike_mess_with_sidebar; // weak
char netz_47CA30[80]; // idb
_47CA80_global _47CA80_array[7];
Script *_47CAF0_tasks_evt39030[7];
int dword_47CB0C; // weak
int dword_47CB10; // weak
_DWORD dword_47CB14; // idb
int dword_47CB18; // weak
int dword_47CB1C; // weak
int dword_47CB20; // weak
MapdScrlImageTile *fog_of_war_tile_15;
int __478AAC_map_height_plus4; // weak
MapdScrlImage *fog_of_war_scrl_source;
int __478AAC_map_height_x2; // weak
MapdScrlImageTile *fog_of_war_tile_1;
MapdScrlImageTile *fog_of_war_tile_10;
MapdScrlImageTile *fog_of_war_tile_14;
MapdScrlImageTile *fog_of_war_tile_4;
MapdScrlImage *map_fog_of_war_scrl;
int dword_47CB4C; // weak
char byte_47CB50[8];
Sprite *_47CB58_minimap_sprite;
MapdScrlImageTile *fog_of_war_tile_11;
MapdScrlImageTile *fog_of_war_tile_7;
MapdScrlImageTile *fog_of_war_tile_3;
int dword_47CB68; // weak
int dword_47CB6C; // weak
MapdScrlImageTile *fog_of_war_tile_13;
void *_47CB74_fow_map_x2; // idb
MapdScrlImageTile *fog_of_war_tile_6;
int __4793F8_map_width_x2; // weak
int __4793F8_map_width_plus4; // weak
MapdScrlImageTile *fog_of_war_tile_8;
void *_47CB88_fow_map_x2; // idb
DrawHandlerData_Units *_47CB8C_fow;
MapdScrlImageTile *fog_of_war_tile_5;
MapdScrlImageTile *fog_of_war_tile_12;
void *_47CB98_fow_map_x2;
int dword_47CBAC; // weak
Bitmap *fog_of_war_bitmap;
MapdScrlImageTile **map_fog_of_war_scrl_tiles;
MapdScrlImageTile *fog_of_war_tile_9;
MapdScrlImageTile *fog_of_war_tile_2;
int _47CBC0_fow[256];
int dword_47CFC0; // weak
int __47CFC4_mobd_lookup_speeds[256];
int _47D3C4_entity_mobd_lookup_ids[257];
unsigned __int8 player_sprite_palette_tmp[256];
stru12_game_globals game_globals_cpu[7];
int entity_drag_selection_x; // weak
Script *pscript_show_message_ex; // idb
int entity_drag_selection_w; // weak
int entity_drag_selection_z; // weak
Script *pscript_show_message; // idb
int entity_drag_selection_y; // weak
Entity *entity_list_head;
Entity *entity_list_47D9AC;
Entity *entity_list;
Entity *entity_list_free_pool;
int _4269B0_task_attachment__4_some_task_flags; // weak
stru11unit *stru11unit_list_47DC70;
stru11unit *stru11unit_list_47DC74;
stru11unit *stru11unit_list;
stru11unit *stru11unit_list_head;
unsigned __int8 *per_player_sprite_palettes[7];
Entity *entity_drag_selection_list;
int player_sprite_color_by_player_side[7];
int _47DCC4_entity_id_counter; // weak
int UNIT_num_player_units; // weak
int UNIT_num_nonplayer_units; // weak
int num_players_towers; // weak
void *entity_default_stru60_ptr;
int dword_47DCE8; // weak
HINSTANCE global_hinstance; // idb
int global_win32_nCmdShow; // idb
bool _47DCF4_wm_quit_received = false; // weak
VideoFileFrame *video_47F434_frame;