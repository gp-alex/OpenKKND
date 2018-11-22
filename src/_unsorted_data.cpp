#include "src/_unsorted_data.h"
#include "src/Render.h"
#include "src/Engine/Entity.h"


int _479DF0_mapd_initialized; // weak
int dword_478AB0; // weak
int _478BE8_map_info__see40E6E0[8];
char byte_478C08; // weak
int dword_478FF4; // weak
int dword_47952C; // weak
int dword_47953C; // weak
int currently_running_lvl_mapd_num_items; // weak
Mapd_stru0 _47C380_mapd;
int currently_running_lvl_mapd_valid; // weak
int _47C390_mapd; // weak
DataMapd *currently_running_lvl_mapd;
Bitmap *_47A010_mapd_item_being_drawn[3];
_UNKNOWN loc_45D19B; // weak
_UNKNOWN loc_45D1A4; // weak
_UNKNOWN loc_45D267; // weak
int sys_colors_elements = 0;
int kknd_sve_array_463070[15] = { 35, 62, 93, 42, 54, 12, 65, 89, 21, 30, 210, 87, 55, 66, 42 };
int kknd_sve_array_4630AC[15] = { 77, 24, 84, 36, 20, 43, 72, 20, 5, 89, 189, 233, 91, 21, 13 };
int dword_4630E8 = 2273464000; // weak
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
int veterancy_damage_bonus[3] = { 0, 51, 102 };
int veterancy_reload_bonus[3] = { 0, 38, 76 };
int veterancy_regeneration_rate[3] =  { 0, 1200, 600 };
int veterancy_accuracy_bonus[3] = { 0, 10, 20 };
stru201_displaymode _465650_display_modes[3] =
{
	{ { 'M', 'O', 'D', 'E', 'X', '\0', '\0', '\0' }, 0, 0 },
	{ "320", 0, 0 },
	{ "640", 0, 0 }
};
int _465680_get_sys_colors = 1; // weak

//ENTITY_TILE_POSITION_*
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
char aTaskIsWrongTyp[19] = "task is wrong type"; // weak
char aBadConstructs[15] = "bad constructs"; // weak
char aBadMode[9] = "bad mode"; // weak
char aCouldnTWriteTo[33] = "couldn't write to save-game file"; // weak
char aCouldnTOpenSav[29] = "couldn't open save-game file"; // weak
char aCouldNotSaveMi[41] = "Could not save miscellaneous information"; // weak
char aCouldNotSaveMa[31] = "Could not save map information"; // weak
char aCouldNotSavePr[38] = "Could not save production information"; // weak
char aCouldNotSaveCp[38] = "Could not save cpu player information"; // weak
char aCouldNotSaveOi[31] = "Could not save oil information"; // weak
char aSS_0[] = "%s (%s)"; // idb
int prev_level_idx = -1; // weak
const char *pKknd_sve = "kknd.sve";
char aC[3] = "%c"; // idb
char *MOBD = "MOBD";
char *aSLevelsSS = "%s\\LEVELS\\%s\\%s";
char *aSLevelsSSupspr = "%s\\LEVELS\\%s\\supspr.lvl";
char intro_vbc[10] = "intro.vbc"; // weak
char *aSFmvMh_fmv_vbc = "%s\\FMV\\mh_fmv.vbc";
char *fmv_lvl = "fmv.lvl";
char *aSFmvS = "%s\\FMV\\%s";
char *aEvolvout_vbc = "evolvout.vbc";
char *aSurvout_vbc = "survout.vbc";
char *aUnit_initFaile = "UNIT_Init() failed\n";
char *aSpriteLoadFail = "sprite load failed\n";
CustomMission custom_missions[20] =
{
    { { "%FRESH MEAT", "~Though it makes me shiver to my", "soul, I sense that the Symmetrics", "have made their presence felt near", "one of our camps.", "~Their vile buildings taint our", "sweeping view of the landscape and", "would lower property values if such", "things still existed.", "~Clear their sorry, Symmetric selves", "from the land." } , "mb_m01.wav" },
    { { "%THE AMOEBA", "~Our prosperous war camp is coming", "under threat -- the Symmetrics are", "gathering their forces, and we fear", "the results.", "~Our big camp, though prosperous, is", "too distant from the enemy, so you", "must set up another camp and deal", "with the enemy in close quarters." }, "mb_m02.wav" },
    { { "%THE GAUNTLET", "~We have the Symmetrics backed into", "a defended valley.", "~They are cringing and will soon beg", "for mercy.", "~We need you to enter the valley", "through its only entrance and show", "the enemy none of this mercy.", "~Let them taste what a second Scourge", "would be like." }, "mb_m03.wav" },
    { { "%STAND AND FIGHT", "~We keep weeding out the foul", "Symmetrics and, just like weeds,", "they keep returning.", "~This time they pester one of our", "camps like pests.", "~Exterminate them." }, "mb_m04.wav" },
    { { "%THE PROPHECY", "~I feel a disturbance in the ... well,", "just a disturbance.", "~I fear that an enormous attack from", "the Symmetrics is in the making.", "I cannot be sure.", "~I feel that you should build up", "defenses that can withstand just", "such an attack, should it eventuate." }, "mb_m05.wav" },
    { { "%TRAITORS", "~Alas, one of our Chieftains has", "fallen ill to the Scourge sickness.", "His mind betrays him as it betrays", "us -- he has made a pact with the", "Symmetrics!", "~His loyal clan follows him, and the", "two groups now fight as one.", "~He must be brought into alignment", "with his spirit once again.", "~So kill him.", "~That should do it." }, "mb_m06.wav" },
    { { "%THE PURSUIT", "~We are a peaceful people.", "All we wish is to set up our homes", "and help prevent the Earth from", "further damage.", "~But the Symmetrics won't let us.", "Even now, they pursue and harass a", "convoy which only wants to set up a", "war camp.", "~Use our head start to complete the", "camp's set-up, then, with much love,", "annihilate the enemy." }, "mb_m07.wav" },
    { { "%HIVE MIND", "~The enemy is falling to its", "claustrophobic nature -- they have", "set up their supply lines in a", "valley.", "~It's time to attack from the", "heavens -- use our glorious", "Thunder Wasps to accomplish", "this task." }, "mb_m08.wav" },
    { { "%BOMBARDMENT", "~The creatures stir.", "They hear sounds on the horizon,", "and I fear it is the Symmetric's own", "heavenly attack -- the metal birds.", "Or it could be a Wilbur Bomber Air", "Strike.", "~Whatever it is, prepare for it,", "survive it, then hunt down the enemy", "and destroy them for daring to use", "our skies for themselves." }, "mb_m09.wav" },
    { { "%HAND OF GOD", "~As we speak, our glorious warriors", "and beasts surround a Symmetric base.", "Our animals grow excited at the smell", "of soiled uniforms.", "~Using all of our forces, tighten your", "grip on the base and crush it,", "destroying everything." }, "mb_m10.wav" },
    { { "%SQUISH", "~An unsightly Freaker village has", "sprung up near one of our pristine,", "high-tech encampments. Even if it's", "just for the pure aesthetics of it", "all, go in there and take out the", "garbage." }, "mb_s01.wav" },
    { { "%COUNTER - ATTACK", "~Those mutants failed at their ambush,", "and we want them to fail even more.", "We've traced them back to their", "pitiful camp.", "You know what to do." }, "mb_s02.wav" },
    { { "%DISTRESS", "~Our people in Communications have", "picked up a distress signal.", "Sure, it could be an old-world mobile", "phone with really good batteries, but", "we'd best be sure.", "~The signal is coming from a bunker in", "the badlands.", "~I don't know exactly what some of our", "highest ranking leaders were doing in", "the badlands in the first place, but", "that's where you have to go to rescue", "them.", "~And if it is just a mobile phone,", "bring it back.", "~I feel so common without one. " }, "mb_s03.wav" },
    { { "%TRICKLE FEED", "~Well, Commander, what we've got here", "is a SNAFU, and don't say", "'Gesundheit' -- I really tire of", "that gag.", "~What's happened is some joker", "changed everyone's watches, so", "instead of having a big force to", "trash a Freak camp, you've initially", "only got a little force.", "~Over the course of the mission, your", "reinforcements will trickle in as", "their watches catch up -- hopefully,", "you won't be dead by then." }, "mb_s04.wav" },
    { { "%S.O.S.", "~We've got a small base, and generally", "size doesn't count.", "But not this time.", "~This time, we've got a small base,", "the Freaks have got a large one, and", "we're in trouble.", "~Your mission is to hold off those", "freaky little dung people.", "~Reinforcements are on the way from a", "Survivor camp 15 minutes away; wait", "until they arrive, then reduce the", "size of the Freak camp to nothing.", "~That'll learn them for overextending." }, "mb_s05.wav" },
    { { "%BUG HUNT", "~We've lost communications with an", "isolated base, Commander, and we want", "you to deal with it.", "~It's probably nothing more than one", "of those dead-beat communications", "guys kicking the power out of the", "wall again, but fix what needs to be", "fixed and deal with whatever needs to", "be dealt with, and slap everyone's", "wrists for wasting our time while", "you're at it." }, "mb_s06.wav" },
    { { "%THE INFILTRATOR", "~The enemy have set up a camp and", "sent stragglers all over the place.", "They know we're here, and they're", "going to expect a big, crushing", "attack which could easily wipe", "them off this part of our world.", "~But we're not going to play their", "little game. We're going to send", "one single sniper with one gun and", "no armour to clear the whole damn", "area. That'll show 'em." }, "mb_s07.wav" },
    { { "%JAIL BREAK", "~It's rescue time again, Commander.", "One of our patrols was captured by a", "mutant ambush.", "~Our people are alive, but there's no", "telling how long it'll be before the", "Freaks start performing some crazy", "death ceremony or other.", "~We want you to get in there and", "rescue the captured patrol, then", "perform a religious ceremony of your", "own -- sacrifice all the Freaks to", "nothing in particular." }, "mb_s08.wav" },
    { { "%WAGONS HO", "~Those filthy Freaks have taken to the", "high ground and they're stinking up", "all the valleys around them.", "And they are killing people, which is", "a bad thing as well.Hold your nose", "while you hunt them down and kill", "them." }, "mb_s09.wav" },
    { { "%TAG TEAM", "~One of our little bases is under", "constant attack.", "~And that really ticks us off.", "~What's worse is that the base is in a", "tight position and it can't be", "expanded enough to eradicate those", "irritating little Freaks.", "~Take a Mobile Outpost and set it up", "somewhere spacious, then build up", "your army.", "~Join forces with the original little", "camp and squash the Freaks like the", "cockroaches they aspire to be." }, "mb_s10.wav" }
};
char *aW = "w";

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
int dword_468980 = -1; // weak
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
char *mission_briefings[30] =
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
int _4690A8_sfx_volume = 16;
int _4690AC_music_volume = 16; // idb
int _4690B0_sound_volume_previous = 16; // weak
int _4690B4_unk_volume = 24576; // weak
char asc_46BB14[18] = "                 ";
int _46BB60_dmg_handler_mobd_offsets[3] = { 332, 364, 388 };
char aSGameD_sav[] = "%s\\game%d.sav"; // idb
char aActiveslotD[] = "ActiveSlot=%d\n"; // idb
char aSSave_lst[] = "%s\\save.lst"; // idb
int _46BBE8_mobd_offset_table_by_stru22[8] = { 1976, 1988, 2000, 2012, 2024, 2036, 2048, 2060 };
int dword_46BC20[8] = { 60, 40, 4294967286, 4294967266, 4294967251, 4294967261, 0, 30 };
int dword_46BC40[8] = { 10, 4294967251, 4294967241, 4294967261, 0, 25, 35, 40 };
int dword_46BC60[9] = { 0, 40, 80, 120, 292, 448, 620, 660, 700 };
int dword_46BC84[5] = { 736, 748, 772, 792, 760 };
int dword_46BC98[8] = { 496, 496, 496, 496, 276, 220, 72, 144 };
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
char a8d[] = " %8d"; // idb
enum PLAYER_SIDE player_side = SURVIVORS;
int dword_47050C = -1; // weak
int dword_470510[] = { 2, 2, 2, 2, 2, 2, 2, 2 }; // weak
char aCouldnTCreat_0[] = "Couldn't create new building"; // idb
char aWaitingForServ[] = "waiting for server packet"; // idb
char aWaitingForPlay[] = "waiting for player packet"; // idb


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
int dword_476DD8 = 0; // weak
int dword_476DDC = 0; // weak
__int16 word_476DE0[] = { 0 }; // weak
int dword_476FE0 = 0; // weak
int __477318_beastenclosure_negindex[] = { 0 }; // weak
stru15unit _477318_beastenclosure = { { 0, 0, 0, 0, 0 }, 0, 0, 0, 0 };
int max_beastenclosure_level = 0; // weak
int dword_477358 = 0; // weak
stru15unit _477378_clanhall = { { 0, 0, 0, 0, 0 }, 0, 0, 0, 0 };
int max_clanhall_level = 0; // weak
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
int dword_477890;
int dword_477894;
int dword_477898; // weak
int dword_47789C; // weak
int dword_4778A0; // weak
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
int timer_delta_updated; // weak
int timer_delta_ms; // weak
int timer_time; // weak
Entity *dword_478108[300];
stru2 *stru2_list_4795D8;
stru2 *stru2_list_4795DC;
stru2 *stru2_list_free_pool;
stru2 *stru2_list;
stru26 _4795F0_stru26_array[3];
stru27 _479740_stru27_array[3];
void *render_locked_surface_ptr;
unsigned int render_locked_surface_width_px; // idb
stru1_draw_params *stru1_list_free_pool;
stru1_draw_params *stru1_list;
int timer_render_skips; // weak
char palette_4798F8_sprt_aligned[512];
stru1_draw_params *current_drawing_params;
char byte_479B00[88]; // idb
int input_479B6C_just_pressed_keys_mask; // weak
int next_pressed_key; // weak
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
int _47A01C_sound_id; // weak
char game_data_root_dir[80]; // idb
char game_data_installation_dir[256];
DataHunk *wait_lvl;
bool is_minimal_install;
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
GAME_STATE game_state = GAME_STATE::MainMenu;
int netz_47A2C8; // weak
enum LEVEL_ID current_level_idx;
__int16 current_mute_level; // weak
__int16 current_surv_level; // weak
int _47A2E4_mess_with_game_dir; // weak
int debug_unit_stats_supplied; // weak
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
Entity volatile *entity_scout;
int _47A378_stru48_array_num_items; // weak
int _47A300_stru51_tech_bunkers_num_items; // weak
DataMobd *currently_running_lvl_mobd;
Sprite *sprite_list_free_pool;
Sprite sprite_47A400; // weak
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
int dword_47A5A0; // weak
char byte_47A5A8[56];
Script *game_cursor_script; // idb
int num_units_in_group[11]; // weak
stru13construct *stru13construct_list_47A638;
stru13construct *stru13construct_list_47A63C;
stru13construct *stru13construct_list;
stru13construct *stru13construct_list_free_pool;
int dword_47A6F0; // weak
KeyboardInput _47A700_input; // idb
int _47A660_array_num_items; // weak
RenderString *_47A730_render_string; // idb
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
int dword_47C018; // weak
Script *receiver; // idb
Script *task_47C028; // idb
int dword_47C030; // weak
int _47C048_num_attack_projectile_sprites; // weak
int _47C04C_num_explosions_max20; // weak
stru175_savegame _47C050_savegames[savegames_max];
char byte_47C230[256]; // idb
int _47C050_current_savegame_idx; // idb
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
int is_demo_build;
int _47C6DC_dont_execute_unit_handlers; // weak
Script *_47C6E0_task; // idb
int dword_47C6E4; // weak
int dword_47C6E8; // weak
int dword_47C6EC; // idb
int dword_47C6F0; // weak
int dword_47C6F4; // weak
int _47C6F8_main_menu_load_initialized; // weak
int dword_47C700; // weak
Script *script_list_free_pool;
void(*task_creation_handler)(Script *);
Script *script_execute_list;
Script *script_list_47C714;
size_t coroutine_default_stack_size; // idb
Script *task_creation_handler_arg;
__int16 is_async_execution_supported; // weak
Script *script_list;
int stru8_list_size; // weak
int stru8_list_allocated; // weak
stru8 *stru8_list;
stru8 *stru8_list_head;
RenderString *render_string_list;
RenderString *render_string_list_free_pool;
RenderString *render_string_list_47C784;
BuildingPlanner _47C788_building_planner; // weak
ProductionGroup _47C798_infantry_pg;    // 47C798
ProductionGroup _47C7E4_vehicles_pg;    // 47C7E4
ProductionGroup _47C830_buildings_pg;   // 47C830
ProductionGroup _47C87C_towers_pg;      // 47C87C
ProductionGroup _47C8C8_aircraft_pg;    // 47C8C8
ProductionGroup *ProductionGroupAccessor(PRODUCTION_GROUP_ID group) {
    switch (group) {
        case PRODUCTION_GROUP_INFANTRY: {
            return &_47C798_infantry_pg;
        } break;

        case PRODUCTION_GROUP_VEHICLES: {
            return &_47C7E4_vehicles_pg;
        } break;

        case PRODUCTION_GROUP_BUILDINGS: {
            return &_47C830_buildings_pg;
        } break;

        case PRODUCTION_GROUP_TOWERS: {
            return &_47C87C_towers_pg;
        } break;

        case PRODUCTION_GROUP_AIRCRAFT: {
            return &_47C8C8_aircraft_pg;
        } break;

        case PRODUCTION_GROUP_BLACKSMITH: {
            __debugbreak();
            //return _47C7E4_vehicles_production_group;
        } break;

        default:
            __debugbreak();
    }
}

ProductionGroup *production_group_list_47C918;
ProductionGroup *production_group_list_47C91C;
ProductionGroup *production_group_list;
ProductionGroup *production_group_free_pool;
stru19production _47C978_production;
stru19production _47C990_production;
stru12_game_globals game_globals_per_player;
ProductionOption *production_option_list_47C9C8;
ProductionOption *production_option_list_47C9CC;
ProductionOption *production_option_list;
ProductionOption *production_option_list_free_pool;
RenderString *_47CA00_render_string;
char netz_47CA30[80]; // idb
_47CA80_global _47CA80_array[7];
Script *_47CAF0_tasks_evt39030[7];
int dword_47CB0C; // weak
int dword_47CB10; // weak
_DWORD dword_47CB14; // idb
int dword_47CB18; // weak
int dword_47CB1C; // weak
int dword_47CB20; // weak
int _47CBC0_fow[256];
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
int _4269B0_task_attachment__4_some_task_flags; // weak
stru11unit *stru11unit_list_47DC70;
stru11unit *stru11unit_list_47DC74;
stru11unit *stru11unit_list;
stru11unit *stru11unit_list_head;
unsigned __int8 *per_player_sprite_palettes[7];
std::list<Entity *>entity_drag_selection_list;
int player_sprite_color_by_player_side[7];
int _47DCC4_entity_id_counter; // weak
int UNIT_num_player_units; // weak
int UNIT_num_nonplayer_units; // weak
int num_players_towers; // weak
void *entity_default_stru60_ptr;
int dword_47DCE8; // weak
bool _47DCF4_wm_quit_received = false; // weak