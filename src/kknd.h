#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <process.h>    // _beginthread, _endthread
#include <stdio.h>
#include <time.h>
#include <math.h>

#include "lib/src/legacy_dx/ddraw.h"
#include "lib/src/legacy_dx/dsound.h"

#include "src/hexrays-defs.h"

#include "src/File.h"
#include "src/Netz.h"
#include "src/Script.h"

struct UnitAttachmentPoint;
struct UnitDamageSource;
struct DrawJobDetails;
struct DrawHandlerData_Units;
struct DataSectionOffset;
struct Sprite;
struct stru7;
struct DataBoxdItem;
struct DataCplcItem;
struct DataCplc_stru0;
struct DataMapdItem;
struct stru11unit;
struct Sidebar;
struct SidebarButton;
struct DataMobdItem;
struct stru24_EnemyNode;
struct stru24_AttackerNode;
struct stru24_stru160;
struct stru24_WandererNode;
struct stru24_stru40;
struct stru24_stru10_convoy;
struct stru24_stru26C;
struct stru24_stru94;
struct stru24_DrillRigNode;
struct stru24_OilTankerNode;
struct stru24_PowerPlantNode;
struct stru24_stru310;
struct stru26_stru0;
struct stru27_stru0;
struct _47CAF0_task_attachment2;
struct EntityTurret;
struct MapdScrlImageTile;
struct DataMobdItem_stru0;
struct BoxdTile;
struct BoxdTile_stru0;
struct DataMobdItem_stru1;
struct DataCplcItem_ptr1;
struct stru53;
struct DataCplcItem_ptr1_stru20;
struct Entity_stru60_stru4;
struct EntityBuildingAttachment_stru14;
struct stru24_struC;
struct Sprite_stru58;
struct Sprite_stru58_stru0;
struct Entity_stru_dmg_related;
struct EVT_MSG_1523_param;
struct task_428940_attach__cursors;
struct task_428940_attach__cursors_2;

/* 63 */
struct UnitNameId
{
	const char *unit_name;
	int id;
};

/* 392 */
enum MOBD_ID : __int32
{
	MOBD_MUTE_ALCHEMY_HALL = 0x0,
	MOBD_SURV_ATV = 0x1,
	MOBD_SURV_BARRAGE_CRAFT = 0x2,
	MOBD_MUTE_BEAST_ENCLOSURE = 0x3,
	MOBD_MUTE_GIANT_BEETLE = 0x4,
	MOBD_MUTE_BERSERKER = 0x5,
	MOBD_6_some_letters_and_symbols = 0x6,
	MOBD_SURV_DIRT_BIKE = 0x7,
	MOBD_MUTE_BLACKSMITH = 0x8,
	MOBD_TECH_BUNKER = 0x9,
	MOBD_SIDEBAR_BUTTONS = 0xA,
	MOBD_SURV_AUTOCANNON_TANK = 0xB,
	MOBD_SURV_CANNON_TOWER = 0xC,
	MOBD_MUTE_CLANHALL = 0xD,
	MOBD_MUTE_CLANHALL_WAGON = 0xE,
	MOBD_MISSION_OUTCOME_MODAL = 0xF,
	MOBD_MUTE_MISSILE_CRAB = 0x10,
	MOBD_CURSORS = 0x11,
	MOBD_SURV_DETENTION_CENTER = 0x12,
	MOBD_MUTE_DIRE_WOLF = 0x13,
	MOBD_20 = 0x14,
	MOBD_SURV_GENERAL = 0x15,
	MOBD_EXPLOSIONS = 0x16,
	MOBD_23_some_fire_maybe_oil_burn = 0x17,
	MOBD_SURV_ATV_FLAMETHROWER = 0x18,
	MOBD_SURV_FLAMER = 0x19,
	MOBD_FONT_26 = 0x1A,
	MOBD_FONT_27 = 0x1B,
	MOBD_GORT = 0x1C,
	MOBD_MUTE_GRAPESHOT_TOWER = 0x1D,
	MOBD_INGAME_MENU_CONTROLS = 0x1E,
	MOBD_MUTE_CRAZY_HARRY = 0x1F,
	MOBD_MUTE_HOLDING_PEN = 0x20,
	MOBD_HUT = 0x21,
	MOBD_SURV_RIFLEMAN = 0x22,
	MOBD_MUTE_CHIEFTAN = 0x23,
	MOBD_PLASMA_TANK = 0x24,
	MOBD_SURV_MACHINE_SHOP = 0x25,
	MOBD_MUTE_WAR_MASTADONT = 0x26,
	MOBD_MUTE_MOBILE_DERRICK = 0x27,
	MOBD_MECH = 0x28,
	MOBD_MUTE_MEKANIK = 0x29,
	MOBD_MUTE_MENAGERIE = 0x2A,
	MOBD_MUTE_MACHINEGUN_NEST = 0x2B,
	MOBD_SURV_MISSILE_BATTERY = 0x2C,
	MOBD_45 = 0x2D,
	MOBD_46 = 0x2E,
	MOBD_MUTE_MONSTER_TRUCK = 0x2F,
	MOBD_MUTE_OIL_TANKER = 0x30,
	MOBD_MUTE_POWER_STATION = 0x31,
	MOBD_MUTE_DRILLRIG = 0x32,
	MOBD_OIL_PATCH = 0x33,
	MOBD_SURV_OUTPOST = 0x34,
	MOBD_SURV_MOBILE_OUTPOST = 0x35,
	MOBD_SURV_4x4_PICKUP = 0x36,
	MOBD_MUTE_PYROMANIAC = 0x37,
	MOBD_SURV_REPAIR_BAY = 0x38,
	MOBD_SURV_RESEARCH_LAB = 0x39,
	MOBD_MUTE_RIOTER = 0x3A,
	MOBD_SURV_RPG_LAUNCHER = 0x3B,
	MOBD_MUTE_BAZOOKA = 0x3C,
	MOBD_MUTE_ROTARY_CANNON = 0x3D,
	MOBD_SURV_SABOTEUR = 0x3E,
	MOBD_SURV_SAPPER = 0x3F,
	MOBD_MUTE_GIANT_SCORPION = 0x40,
	MOBD_SURV_MOBILE_DERRICK = 0x41,
	MOBD_SENTINEL_DROID = 0x42,
	MOBD_SURV_GUARD_TOWER = 0x43,
	MOBD_MUTE_SHOTGUNNER = 0x44,
	MOBD_69 = 0x45,
	MOBD_MUTE_BIKE_SIDECAR = 0x46,
	MOBD_SURV_SNIPER = 0x47,
	MOBD_72_looks_like_acid_spit = 0x48,
	MOBD_SURV_OIL_TANKER = 0x49,
	MOBD_SURV_POWER_STATION = 0x4A,
	MOBD_SURV_DRILLRIG = 0x4B,
	MOBD_SURV_SWAT = 0x4C,
	MOBD_SURV_ANACONDA_TANK = 0x4D,
	MOBD_SURV_TECHNICIAN = 0x4E,
	MOBD_79 = 0x4F,
	MOBD_FONT_ITALIC = 0x50,
	MOBD_MUTE_VANDAL = 0x51,
	MOBD_MUTE_WASP = 0x52,
	MOBD_SURV_BOMBER = 0x53,
	MOBD_INVALID = -1,
};

/* 381 */
enum PLAYER_SIDE : __int32
{
    PLAYER_SIDE_UNSPECIFIED = 0,
	SURVIVORS = 1,
	EVOLVED = 2,
};

/* 369 */
enum UNIT_ID : __int32
{
	UNIT_STATS_SURV_RIFLEMAN = 0,
	UNIT_STATS_MUTE_BERSERKER = 1,
	UNIT_STATS_SURV_FLAMER = 2,
	UNIT_STATS_MUTE_PYROMANIAC = 3,
	UNIT_STATS_SURV_SWAT = 4,
	UNIT_STATS_MUTE_SHOTGUNNER = 5,
	UNIT_STATS_SURV_SAPPER = 6,
	UNIT_STATS_MUTE_RIOTER = 7,
	UNIT_STATS_SURV_EL_PRESIDENTE = 8,
	UNIT_STATS_MUTE_KING_ZOG = 9,
	UNIT_STATS_SURV_SABOTEUR = 10,
	UNIT_STATS_MUTE_VANDAL = 11,
	UNIT_STATS_SURV_TECHNICIAN = 12,
	UNIT_STATS_MUTE_MEKANIK = 13,
	UNIT_STATS_SURV_RPG_LAUNCHER = 14,
	UNIT_STATS_MUTE_BAZOOKA = 15,
	UNIT_STATS_SURV_SNIPER = 16,
	UNIT_STATS_MUTE_CRAZY_HARRY = 17,
	UNIT_STATS_SURV_GENERAL = 18,
	UNIT_STATS_MUTE_WARLORD = 19,
	UNIT_STATS_SURV_SCOUT = 20,
	UNIT_STATS_SURV_MOBILE_DERRICK = 21,
	UNIT_STATS_MUTE_MOBILE_DERRICK = 22,
	UNIT_STATS_SURV_TANKER = 23,
	UNIT_STATS_MUTE_TANKER = 24,
	UNIT_STATS_TANKER_CONVOY = 25,
	UNIT_STATS_SURV_DIRT_BIKE = 26,
	UNIT_STATS_MUTE_DIRE_WOLF = 27,
	UNIT_STATS_SURV_4x4_PICKUP = 28,
	UNIT_STATS_MUTE_BIKE_AND_SIDECAR = 29,
	UNIT_STATS_SURV_ATV = 30,
	UNIT_STATS_MONSTER_TRUCK = 31,
	UNIT_STATS_SURV_ATV_FLAMETHROWER = 32,
	UNIT_STATS_MUTE_GIANT_SCORPION = 33,
	UNIT_STATS_SURV_ANACONDA_TANK = 34,
	UNIT_STATS_MUTE_WAR_MASTADONT = 35,
	UNIT_STATS_SURV_BARRAGE_CRAFT = 36,
	UNIT_STATS_MUTE_GIANT_BEETLE = 37,
	UNIT_STATS_SURV_AUTOCANNON_TANK = 38,
	UNIT_STATS_MUTE_MISSILE_CRAB = 39,
	UNIT_STATS_SURV_MOBILE_OUTPOST = 40,
	UNIT_STATS_MUTE_CLANHALL_WAGON = 41,
	UNIT_STATS_MUTE_WASP = 43,
	UNIT_STATS_SURV_BOMBER = 44,
	UNIT_STATS_SURV_DRILL_RIG = 46,
	UNIT_STATS_MUTE_DRILL_RIG = 47,
	UNIT_STATS_SURV_POWER_STATION = 48,
	UNIT_STATS_MUTE_POWER_STATION = 49,
	UNIT_STATS_SURV_DETENTION_CENTER = 50,
	UNIT_STATS_MUTE_HOLDING_PENS = 51,
	UNIT_STATS_SURV_GUARD_TOWER = 52,
	UNIT_STATS_MUTE_MACHINEGUN_NEST = 53,
	UNIT_STATS_SURV_CANNON_TOWER = 54,
	UNIT_STATS_MUTE_GRAPESHOT_TOWER = 55,
	UNIT_STATS_SURV_MISSILE_BATTERY = 56,
	UNIT_STATS_MUTE_ROTARY_CANNON = 57,
	UNIT_STATS_SURV_OUTPOST = 58,
	UNIT_STATS_MUTE_CLANHALL = 59,
	UNIT_STATS_SURV_MACHINE_SHOP = 60,
	UNIT_STATS_MUTE_BLACKSMITH = 61,
	UNIT_STATS_MUTE_BEAST_ENCLOSURE = 62,
	UNIT_STATS_SURV_REPAIR_BAY = 63,
	UNIT_STATS_MUTE_MENAGERIE = 64,
	UNIT_STATS_SURV_RESEARCH_LAB = 65,
	UNIT_STATS_MUTE_ALCHEMY_HALL = 66,
	UNIT_STATS_TECH_BUNKER = 67,
	UNIT_STATS_HUT = 68,
	UNIT_WALL_1 = 69,
	UNIT_WALL_2 = 70,
	UNIT_WALL_3 = 71,
	UNIT_WALL_4 = 72,
	UNIT_STATS_GORT = 74,
	UNIT_STATS_PLASMA_TANK = 76,
	UNIT_STATS_SENTINEL_DROID = 77,
	UNIT_STATS_MECH = 78,
	UNIT_STATS_LAST = 88,
	UNIT_INVALID = -1,
};

#pragma pack(push, 1)
/* 64 */
struct UnitStat
{
	enum MOBD_ID mobd_idx;
	void(*script_handler)(Script *);
	const char *name;
	int cost;
	int hitpoints;
	int speed;
	int reload_time;
	int turning_speed;
	int field_20;
	int firing_range;
	int accuracy;
	int field_2C;
	int field_30_hp_regen_condition;
	int mobd_lookup_table_offset;
	int _38_mobd_lookup_table_offset;
	int mobd_lookup_offset;
	int mobd_lookup_table_offset_2;
	UnitAttachmentPoint *attach;
	UnitDamageSource *dmg_source;
	int field_4C;
	enum PLAYER_SIDE player_side;
	int field_54;
	int field_58;
	enum UNIT_ID _5C_unit_id;
	int production_time;
};

/* 65 */
struct UnitAttachmentPoint
{
	enum MOBD_ID mobd_id;
	void (*mode_attach)(Script *);
	int mobd_frame_step;
	int reload_time;
	int reload2_time;
	int volley_size;
	int mobd_lookup_table_offset;
	int _1C_mobd_lookup_table_offset_for_rotary_cannon;
	UnitDamageSource *dmg_source;
	int field_24;
};

/* 66 */
struct UnitDamageSource
{
	enum MOBD_ID mobd_id;
	void(*dmg_handler)(Script *);
	int field_8;
	int field_C;
	int field_10;
	int damage_infantry;
	int damage_vehicle;
	int damage_building;
	int field_20;
	int field_24;
};


/* 73 */
struct stru1_draw_params
{
	stru1_draw_params *next;
	stru1_draw_params *prev;
	int field_8;
	int anim_pos;
	int clip_x;
	int clip_y;
	int clip_z;
	int clip_w;
	int field_20;
};

/* 144 */
struct __declspec(align(4)) LevelDesc
{
	const char *lvl_filename;
	const char *wav_filename;
	const char *vbc_filename;
	__int16 starting_cash;
	__int16 field_E;
	__int16 field_10;
	__int16 _12_cost_multiplier_idx;
	__int16 field_14;
	__int16 field_16;
	unsigned int disabled_units_mask;
	int field_1C;
	__int16 field_20;
	__int16 field_22;
	int field_24;
	__int16 field_28;
	__int16 field_2A;
	int field_2C;
};


/* 262 */
struct Sound
{
	int id;
	IDirectSoundBuffer *pdsb;
	Script *task;
	File *file;
	int hthread;
	int field_14;
	int field_18;
	int sound_volume_offset;
	int field_20;
	int field_24;
	int sound_pan_offset;
	int field_2C;
	int field_30;
	int flags;
	Sound *next;
	Sound *prev;
	int field_40;
	char filename[32];
	_BYTE gap64[42];
	char field_8E[100];
	char field_F2[80];
	char field_142;
	char field_143;
	char field_144;
	char field_145;
	char field_146;
	char field_147;
};

/* 270 */
struct CustomMission
{
	const char **briefing;
	const char *wav_filename;
};


/* 273 */
struct DrawJobDetails
{
    int flags;
    void *image;
    int field_8;
    stru1_draw_params *params;
    int x;
    int y;
    int z_index;
    unsigned __int8 *palette;
};


typedef void(*DrawJobUpdateHandler)(void *param, struct DrawJob *job);

/* 272 */
struct DrawJob
{
	DrawJob *next;
	DrawJob *prev;
	int flags;
	void *on_update_handler_param;
    DrawJobUpdateHandler on_update_handler;
	DrawJobDetails job_details;
	int field_34;
	int field_38;
};

struct DrawJobList
{
    DrawJob *next;
    DrawJob *prev;
};


/* 274 */
struct MobdSprtImage
{
	int(*handler)(DrawJobDetails *data, int mode);
	int flags;
	DrawHandlerData_Units *data;
};

/* 276 */
struct DrawHandlerData_Units
{
	int width;
	int height;
	char type;
	unsigned __int8 sprite_data[2];
};

/* 277 */
struct MapdScrlImage
{
	int(*on_draw_handler)(DrawJobDetails *data, int mode);
	int tile_x_size;
	int tile_y_size;
	int num_x_tiles;
	int num_y_tiles;
	MapdScrlImageTile *tiles[16];
};


/* 279 */
struct stru2
{
	stru2 *next;
	stru2 *prev;
	int hunk;
	int(*init_handler)();
	int(*draw_handler)(void *data, int mode);
	void(*deinit_handler)();
};

/* 280 */
struct stru3
{
	int magic;
	int(*init_handler)();
	int(*draw_handler)(DrawJobDetails *data, int mode);
	void(*deinit_handler)();
};

/* 283 */
struct Hunk
{
	int magic;
	int size;
};

/* 285 */
struct RllcHunk
{
	int num_relocations;
	unsigned int relocations;
};

/* 286 */
struct DataHunk
{
	DataSectionOffset *section_table;
};

/* 288 */
struct CplcSectionData
{
};

/* 290 */
struct Coroutine
{
    inline Coroutine()
    {
        static int _id = 0;

        this->id = _id++;
        this->yield_to = nullptr;
        this->context = nullptr;
        this->stack = 0;
        this->next = nullptr;
    }

	Coroutine *yield_to;
	int *context;
	int stack;
	Coroutine *next;

    int         id;
    const char *debug_handler_name;
};

/* 291 */
struct DataSectionOffset
{
	char name[4];
	void *ptr;
};

/* 292 */
struct Bitmap
{
	Bitmap *next;
	Bitmap *prev;
	DrawJob *draw_job;
	MapdScrlImage *draw_job_scrl;
	int z_index;
};

/* 293 */
struct Sprite
{
	Sprite *next;
	Sprite *prev;
	Sprite *parent;
	enum MOBD_ID mobd_id;
	int x;
	int y;
	int z_index;

	int x_speed;
	int y_speed;
	int z_speed;

	int x_speed_factor_2;
	int y_speed_factor_2;
	int z_speed_factor_2;

	int x_speed_limit;
	int y_speed_limit;
	int z_speed_limit;

	int x_speed_factor_1;
	int y_speed_factor_1;
	int z_speed_factor_1;

	DataMobdItem *_inside_mobd_item;
	DataMobdItem *_inside_mobd_item_2;
	DataMobdItem_stru0 *_54_inside_mobd_ptr4;
	Sprite_stru58 *pstru58;
	stru7 *pstru7;
	int _60_mobd_field_0_int;
	int field_64;
	DrawJob *drawjob;
	Script *script;
	DataCplcItem_ptr1_stru20 *cplc_ptr1_pstru20;
	DataCplcItem_ptr1 *cplc_ptr1;
	DataCplc_stru0 *cplc_stru0;
	void *param;
	void *_80_entity__stru29__sprite__initial_hitpoints;
	int field_84;
	int field_88_unused;
	__int16 field_8C_infantry_damage;
	__int16 field_8E_vehicle_damage;
	__int16 field_90_building_damage;
	__int16 field_92;
};

/* 294 */
struct stru7
{
	int field_0;
	int _4_psprite_pstru7_idx;
	bool (*pfn_8_ui_hint_box)(Sprite *, Sprite *, int, void *, void *);
	bool (*pfn_C)(Sprite *, Sprite *, int, void *, void *);
};

/* 295 */
struct DataBoxd
{
	DataBoxdItem *items;
};

/* 296 */
struct DataBoxdItem
{
	int field_0_num_things;
	int some_map_width_scale;
	int some_map_height_scale;
	int map_num_x_tiles;
	int map_num_y_tiles;
	BoxdTile *map_tiles[2];
};

/* 297 */
struct DataCplc
{
	DataCplcItem *items;
};

/* 298 */
struct DataCplcItem
{
	int size;
	DataCplcItem_ptr1 *ptr1;
	DataCplcItem_ptr1 *ptr2;
	DataCplcItem_ptr1 *ptr3;
	DataCplcItem_ptr1 *ptr4;
};

/* 299 */
struct DataCplc_stru0
{
	DataCplc_stru0 *next;
	DataCplc_stru0 *prev;
	Sprite *sprite;
};

/* 300 */
struct DataCplcItem_ptr3
{
	int field_0;
	int field_4_x_width;
	int field_8_y_height;
	int field_C;
	int ptr_10;
	int ptr_14;
	DataCplcItem_ptr3 *next;
	DataCplcItem_ptr3 *next2;
};

/* 301 */
struct stru8
{
	stru8 *next;
	DrawJob *drawjob;
};

/* 302 */
struct RenderString
{
	RenderString *next;
	RenderString *prev;
	stru8 *pstru8;
	int field_C;
	int field_10;
	DataMobdItem *mobd_font__see_sub405A60;
	int field_18;
	int num_lines;
};


/* 304 */
struct DataMapd
{
	DataMapdItem *items;
};

/* 305 */
struct DataMapdItem
{
	int num_images;
	MapdScrlImage *images[1];
	int num_palette_entries;
	PALETTEENTRY palette;
};

/* 306 */
struct stru10
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
};

/* 430 */
struct Entity_stru24_ai
{
	int _0_ai_node_per_player_side[2];
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
};

/* 396 */
struct Entity_stru60
{
	Entity_stru_dmg_related *ptr_0;
	Entity_stru60_stru4 *pstru4;
	int ptr_8;
	DataMobdItem_stru1 *ptr_C;
	int ptr_10;
	int ptr_14;
};

/* 427 */
struct Entity_stru224
{
	int array_0[10];
	int _28_indexer;
	int _2C_map_x;
	int _30_map_y;
	int _34_x;
	int _38_y;
	int field_3C;
	int _40_xy_idx;
	int field_44;
	int field_48;
	int field_4C;
	int field_50;
	int field_54;
};

/* 307 */
struct Entity
{
	Entity *next;
	Entity *prev;
	Entity *entity_8;
	Script *script;
	enum UNIT_ID unit_id;
	enum PLAYER_SIDE player_side;
	UnitStat *stats;
	EntityTurret *turret;
	void *state;
	Entity_stru24_ai _24_ai_node_per_player_side;
	void(*mode)(Entity *);
	int(*mode_idle)(int);
	void(*mode_arrive)(Entity *);
	int(*mode_attacked)(int);
	void(*mode_return)(Entity *);
	void(*mode_turn_return)(Entity *);
	void(*event_handler)(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
	Sprite *sprite;
	Entity_stru60 stru60;
	int field_78;
	int mobd_lookup_idx;
	int field_80;
	int field_84;
	int field_88;
	int destroyed;
	int hitpoints;
	int field_94;
	int _98_465610_accuracy_dmg_bonus_idx;
	int _9C_hp_regen_condition;
	int _A0_hp_regen_condition;
	int field_A4;
	int sprite_width_shr13;
	int sprite_height_shr13;
	int sprite_width;
	int sprite_height;
	int field_B8;
	int field_BC;
	int field_C0;
	int field_C4;
	int field_C8;
	int field_CC;
	int field_D0;
	int field_D4;
	int field_D8;
	int field_DC;
	Entity *entity_E0_outpost_clanhall;
	Entity *_E4_entity;
	Entity *_E8_entity;
	int entity_E0_outpost_clanhall_entity_id;
	int _E4_entity_id;
	int entity_118_entity_id;
	int _E8_entity_id;
	int sprite_width_2;
	int sprite_height_2;
	stru11unit *stru11_list_104;
	stru11unit *stru11_list_108;
	int field_10C;
	int field_110;
	int field_114;
	Entity *entity_118;
	int _11C__infantry_sprite_y___drillrig_oil_spot;
	int _120__infantry_sprite_x;
	int field_124;
	void *_128_spawn_param;
	int _12C_prison_bunker_spawn_type;
	int entity_id;
	int _134_param__unitstats_after_mobile_outpost_plant;
	int field_138;
	int field_13C;
	int field_140;
	int field_144;
	int field_148;
	int field_14C;
	int field_150;
	int field_154;
	int field_158;
	int array_15C[10];
	int array_184[10];
	int array_1AC[10];
	int array_1D4[10];
	int array_1FC[10];
	Entity_stru224 stru224;
	Entity *entity_27C;
	int entity_27C_entity_id;
	int(*pfn_render_DrawUnitsAndUi)(DrawJobDetails *data, int mode);
	int field_288;
	void *_28C_stru26_stru0__or__stru27_stru0__or__EntityBuildingAttachment_stru14__or__EntityOilTankerAttachment_stru70;
	DrawJob *drawjob;
	char array_294[8];
	int field_29C;
	int field_2A0;
	int field_2A4;
	Entity *_2A8_entity;
	int _2A8_entity_id;
	int sprite_width_3;
	int sprite_height_3;
};

/* 308 */
struct stru11unit
{
	stru11unit *next;
	stru11unit *prev;
	void *param;
};

/* 309 */
struct Entity_stru0
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
};

/* 310 */
struct OilDeposit
{
	OilDeposit *next;
	OilDeposit *prev;
	Sprite *sprite;
	int oil_left;
	Entity *drillrig;
	int drillrig_entity_id;
};

/* 311 */
struct OilDepositSaveStruct
{
	int field_0;
	int width_x256;
	int height_x256;
	int field_C;
};

/* 313 */
struct EntitySaveStructIndex
{
	int entity_field_130;
	int entity_save_size;
};

/* 314 */
struct stru12_game_globals
{
	int cash[7];
};

/* 315 */
struct stru14_globals
{
	stru12_game_globals cpu_globals_see_stru12_game_globals[7];
};

/* 316 */
struct stru13construct
{
	stru13construct *next;
	stru13construct *prev;
	int field_8;
	int field_C;
	int field_10;
	int _14_cost;
	int _18_cost;
	int _1C_cost_per_time_step;
};

/* 318 */
struct stru13_stru0
{
	int field_0[5];
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
};

/* 319 */
struct stru15unit
{
	int num_buildings_by_level[5];
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
};

/* 325 */
struct stru19production
{
	int sidebar_open_mask[6];
};

/* 326 */
struct stru13constructSaveStruct
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
};

/* 317 */
struct MiscSaveStruct
{
	int size;
	stru13_stru0 stru13stru0;
	int field_30;
	stru15unit outpost_levels;
	int max_outpost_level;
	stru15unit clanhall_levels;
	int max_clanhall_level;
	stru15unit machineshop_levels;
	int max_machineshop_level;
	stru15unit beastenclosure_levels;
	int max_beastenclosure_level;
	stru19production stru19_unit;
	int num_player_units;
	int num_total_units;
	int num_players_towers;
	int __47A3D0_unit;
	int _47A3D4_unit;
	int _47A3D8_unit;
	int scout_entity_id;
	int outposts_clanhalls_entity_ids[4];
	int _47A370_unit;
	int _47A2F8_unit;
	int dword_47CA2C;
	int _47C970_stru0_ptr_3C_handler;
	int field_128;
	int field_12C;
	int field_130;
	int field_134;
	int field_138;
	int field_13C;
	int field_140;
	int field_144;
	int field_148;
	int field_14C;
	int field_150;
	int field_154;
	int field_158;
	int field_15C;
	int field_160;
	int field_164;
	int field_168;
	int field_16C;
	int field_170;
	int field_174;
	stru13constructSaveStruct field_178;
};

/* 323 */
struct struc_72
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
};

/* 327 */
struct ProductionOption
{
	ProductionOption *next;
	ProductionOption *prev;
	enum UNIT_ID stru21prod_unit_id;
	enum UNIT_ID unit_id;
	int mobd_lookup_table_offset;
	int _14_pcost;
	int field_18;
	int field_1C;
	int field_20;
	int cost;
	int production_time_x60;
	int field_2C;
};

/* 443 */
enum PRODUCTION_GROUP_ID : __int32
{
	PRODUCTION_GROUP_INFANTRY = 0,
	PRODUCTION_GROUP_VEHICLES = 1,
	PRODUCTION_GROUP_BUILDINGS = 2,
	PRODUCTION_GROUP_TOWERS = 3,
	PRODUCTION_GROUP_AIRCRAFT = 4,
	PRODUCTION_GROUP_BLACKSMITH = 5,
};

/* 328 */
struct ProductionGroup
{
	ProductionGroup *next;
	ProductionGroup *prev;
	enum PRODUCTION_GROUP_ID group_id;
	Entity *_C_entity;
	Sidebar *sidebar;
	ProductionOption *next_option;
	ProductionOption *prev_option;
	Entity *outpost_clanhall;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int _44_mobd_lookup_idx;
	Sprite *sprite;
};

/* 330 */
struct Sidebar
{
	Sidebar *next;
	Sidebar *prev;
	Script *script;
	int num_buttons;
	int x;
	int w;
	int sprite_width_step;
	int sprite_height_step;
	Sprite *sprite;
	SidebarButton *button_list_free_pool;
	SidebarButton *button_list_head;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
};

/* 331 */
struct SidebarButton
{
	SidebarButton *next;
	SidebarButton *prev;
	Script *task;
	void(*open_handler)(SidebarButton *);
	void(*close_handler)(SidebarButton *);
	int mobd_lookup_table_offset;
	int field_18;
	int ptr_1C;
	void *param;
	Sprite *sprite;
};

/* 332 */
struct stru6_stru68
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int on_update_handler;
	int field_14;
	int field_18;
	int field_1C;
	stru1_draw_params *pstru1;
	int field_24;
	int field_28;
	int field_2C;
	void *_off_47DC88_element;
};

/* 333 */
struct DataMobd
{
	DataMobdItem *items;
};

/* 334 */
struct DataMobdItem
{
	DataMobdItem_stru0 *ptr_0;
	DataMobdItem_stru0 *ptr_4;
	int field_8;
};


struct EVT_MSG_1523_param
{
    PLAYER_SIDE side;
    Entity *entity;
};

/* 336 */
struct stru24
{
	stru24 *next;
	stru24 *prev;
	Entity *_8_entity;
	stru24_struC *struC;
	stru24_stru10_convoy *list_10_convoy;
	stru24_stru10_convoy *list_10_convoy_head;
	stru24_WandererNode *wanderer_list_18;
	stru24_WandererNode *wanderer_list_1C;
	_BYTE gap20[8];
	stru24_WandererNode *wanderer_list;
	stru24_WandererNode *wanderer_list_free_pool;
	stru24_stru40 *list_40_30;
	stru24_stru40 *list_40_34;
	_BYTE gap38[8];
	stru24_stru40 *list_40;
	stru24_stru40 *list_40_head;
	stru24_AttackerNode *attacker_list_48;
	stru24_AttackerNode *attacker_list_4C;
	_BYTE gap50[8];
	stru24_AttackerNode *attacker_list;
	stru24_AttackerNode *attacker_list_free_pool;
	stru24_AttackerNode *marshalling_nodes_list__evmission8_only_60;
	stru24_AttackerNode *marshalling_nodes_list__evmission8_only_64;
	_BYTE gap68[8];
	stru24_AttackerNode *marshalling_nodes_list__evmission8_only;
	stru24_AttackerNode *marshalling_nodes_list__evmission8_only_free_pool;
	stru24_stru94 *list_94_78;
	stru24_stru94 *list_94_7C;
	_BYTE gap80[20];
	stru24_stru94 *list_94;
	stru24_stru94 *list_94_head;
	stru24_DrillRigNode *drill_rig_list_9C;
	stru24_DrillRigNode *drill_rig_list_A0;
	_BYTE gapA4[44];
	int field_D0;
	stru24_DrillRigNode *drill_rig_list;
	stru24_DrillRigNode *drill_rig_list_free_pool;
	stru24_OilTankerNode *tanker_list_DC;
	stru24_OilTankerNode *tanker_list_E0;
	_BYTE gapE4[4];
	int field_E8;
	stru24_OilTankerNode *tanker_list;
	stru24_OilTankerNode *tanker_list_free_pool;
	stru24_PowerPlantNode *power_plant_list_F4;
	stru24_PowerPlantNode *list_104_F8;
	_BYTE gapFC[4];
	stru24_PowerPlantNode *power_plant_list;
	stru24_PowerPlantNode *power_plant_list_free_pool;
	stru24_EnemyNode *enemy_list_108;
	stru24_EnemyNode *enemy_list_10C;
	_BYTE gap110[4];
	stru24_EnemyNode *enemy_list;
	stru24_EnemyNode *enemy_list_free_pool;
	stru24_stru160 *list_11C;
	stru24_stru160 *list_160_120;
	_BYTE gap124[60];
	stru24_stru160 *list_160;
	stru24_stru160 *list_160_head;
	int field_168;
	int field_16C;
	_BYTE gap170[60];
	int field_1AC;
	_BYTE gap1B0[4];
	stru24_stru160 *list_1B4;
	int field_1B8;
	_BYTE gap1BC[60];
	int field_1F8;
	_BYTE gap1FC[4];
	int field_200;
	int field_204;
	_BYTE gap208[60];
	int field_244;
	_BYTE gap248[4];
	stru24_stru160 *field_24C;
	int field_250;
	int field_254;
	int field_258;
	int field_25C;
	stru24_stru26C *list_260;
	stru24_stru26C *list_26C_264;
	int field_268;
	stru24_stru26C *list_26C;
	stru24_stru26C *list_26C_head;
	stru24_stru26C *ptr_274;
	int _278_x_offset;
	int _27C_y_offset;
	int field_280[2][4];
	enum PLAYER_SIDE _2A0_player_side;
	enum PLAYER_SIDE _2A4_player_side;
	int *_2A8_p_globals_cash;
	int field_2AC;
	int list_58_and_70_size;
	int field_2B4;
	int field_2B8;
	int field_2BC;
	int field_2C0;
	int array_2C8_idx;
	int array_2C8[4];
	int field_2D8;
	enum UNIT_ID _2DC_unit_id;
	enum UNIT_ID _2E0_unit_id;
	int field_2E4;
	stru24_DrillRigNode *_2E8_drillrig_node;
	stru24_stru310 *list_310_2EC;
	stru24_stru310 *list_310_2F0;
	_BYTE gap2F4[28];
	stru24_stru310 *list_310;
	stru24_stru310 *list_310_head;
	stru24_stru310 *list_318;
	int field_31C;
	_BYTE gap320[28];
	int field_33C;
	_BYTE gap340[4];
	int field_344;
	int field_348;
	int field_34C;
	int field_350;
	int field_354;
	Script *task;
	int level_field_22_or_2A;
	int field_360;
};

/* 337 */
struct stru24_EnemyNode
{
	stru24_EnemyNode *next;
	stru24_EnemyNode *prev;
	Entity *entity;
};

/* 338 */
struct stru24_AttackerNode
{
	stru24_AttackerNode *next;
	stru24_AttackerNode *prev;
	stru24_stru160 *list_8;
	Entity *entity;
};

/* 339 */
struct stru24_stru160
{
	stru24_stru160 *next;
	stru24_stru160 *prev;
	stru24_stru160 *field_8;
	void *_C_next;
	void *_10_prev;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	stru24_EnemyNode *field_24;
	int field_28;
	int field_2C;
	int field_30;
	int x_offset;
	int y_offset;
	int field_3C;
	int field_40;
};

/* 340 */
struct stru24_WandererNode
{
	stru24_WandererNode *next;
	stru24_WandererNode *prev;
	int field_8;
	Entity *entity;
};

/* 341 */
struct stru24_stru40
{
	stru24_stru40 *next;
	stru24_stru40 *prev;
	int field_8;
	Entity *_C__entity;
};

/* 342 */
struct stru24_stru10_convoy
{
	stru24_stru10_convoy *next;
	stru24_stru10_convoy *prev;
	Entity *_8_entity;
	int field_C;
};

/* 343 */
struct stru24_stru26C
{
	stru24_stru26C *next;
	stru24_stru26C *prev;
	int field_8;
};

/* 344 */
struct stru24_stru94
{
	stru24_stru94 *next;
	stru24 *prev;
	Entity *_8_entity;
	int _C_cost;
	int _8_entity_script_param;
	int _14_cost;
	int _18_cost_per_time_step;
};

/* 345 */
struct stru24_DrillRigNode
{
	stru24_DrillRigNode *next;
	stru24_DrillRigNode *prev;
	stru24_OilTankerNode *_8_next;
	stru24_OilTankerNode *_C_prev;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	Entity *entity;
	stru24_stru160 *pstru24_stru160;
	stru24_PowerPlantNode *ptr_28;
	int field_2C;
	int field_30;
	int field_34;
};

/* 346 */
struct stru24_OilTankerNode
{
	stru24_OilTankerNode *next;
	stru24_OilTankerNode *prev;
	stru24_DrillRigNode *drillrig_node;
	Entity *entity;
};

/* 347 */
struct stru24_PowerPlantNode
{
	stru24_PowerPlantNode *next;
	stru24_PowerPlantNode *prev;
	Entity *entity;
};

/* 348 */
struct stru24_stru310
{
	stru24_stru310 *next;
	stru24_stru310 *prev;
	int field_8;
	enum UNIT_ID unit_id;
	int x;
	int y;
	int x_offset;
	int y_offset;
	int field_20;
};

/* 349 */
struct BuildingLimits
{
	BuildingLimits *next;
	BuildingLimits *prev;
	enum UNIT_ID building_unit_stat_idx;
	int num_buildings_of_this_type;
};

/* 350 */
struct stru26
{
	stru26_stru0 *data[28];
};

/* 351 */
struct stru26_stru0
{
	int field_0;
	int field_4;
	char field_8;
	char array_9[192];
	char field_C9;
	char field_CA;
	char field_CB;
};

/* 352 */
struct stru27
{
	stru27_stru0 *data[12];
};

/* 353 */
struct stru27_stru0
{
	int field_0;
	int field_4;
	char field_8;
	char array_9[96];
	char field_69;
	char field_6A;
	char field_6B;
};

/* 354 */
struct stru28
{
	stru28 *next;
	stru28 *prev;
	int mobd_offset_idx;
	Sprite *sprite;
};


#define INPUT_MOUSE_LBUTTON_MASK 0x10
#define INPUT_MOUSE_RBUTTON_MASK 0x20
#define INPUT_MOUSE_MBUTTON_MASK 0x80

/* 356 */
struct MouseInput
{
	int pressed_buttons_mask;
	int just_pressed_buttons_mask;
	int just_released_buttons_mask;
	int field_C;
	int cursor_x_x256;
	int cursor_y_x256;
	int cursor_dx_x256;
	int cursor_dy_x256;
};

/* 357 */
struct stru31
{
	stru31 *next;
	stru31 *prev;
	Entity *param__entity__int;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
};

/* 363 */
enum SOUND_ID : __int32
{
	SOUND_0 = 0,
	SOUND_3 = 3,
	SOUND_RIFLE_FIRE = 4,
	SOUND_LOW_CALIBER_MACHINEGUN_FIRE = 5,
	SOUND_CANNON_FIRE = 6,
	SOUND_BIKE_AND_SIDECAR_FIRE = 7,
	SOUND_MACHINEGUN_FIRE = 8,
	SOUND_GENERIC_PROJECTILE_DMG = 9,
	SOUND_GENERIC_PROJECTILE_DMG_2 = 10,
	SOUND_RIFLE_FIRE_2 = 11,
	SOUND_RIFLE_FIRE_3 = 12,
	SOUND_RIFLE_FIRE_4 = 13,
	SOUND_14_dmg = 14,
	SOUND_SHOTGUN_FIRE = 17,
	SOUND_20 = 20,
	SOUND_23 = 23,
	SOUND_26_sabotage = 26,
	SOUND_28_technician = 28,
	SOUND_SURV_BUILDING_COMPLETED = 32,
	SOUND_SURV_UNIT_READY = 33,
	SOUND_40_sabotage = 40,
	SOUND_43 = 43,
	SOUND_45_surv_saboteur = 45,
	SOUND_SURV_LOW_OIL_WARNING = 47,
	SOUND_48 = 48,
	SOUND_49 = 49,
	SOUND_50 = 50,
	SOUND_51 = 51,
	SOUND_52 = 52,
	SOUND_53 = 53,
	SOUND_SURV_COMMENCING_UPGRADE = 54,
	SOUND_SURV_UPGRADE_COMPLETE_1 = 55,
	SOUND_SURV_UNIT_DRILL_RIG = 56,
	SOUND_59 = 59,
	SOUND_60 = 60,
	SOUND_SURV_UPGRADE_COMPLETE_2 = 62,
	SOUND_SURV_AIRSTRIKE_READY = 66,
	SOUND_68 = 68,
	SOUND_69 = 69,
	SOUND_70 = 70,
	SOUND_71 = 71,
	SOUND_72 = 72,
	SOUND_73 = 73,
	SOUND_76 = 76,
	SOUND_78 = 78,
	SOUND_85 = 85,
	SOUND_LASER_DMG = 87,
	SOUND_88 = 88,
	SOUND_89_dmg_handler = 89,
	SOUND_90_dmg_handler = 90,
	SOUND_91 = 91,
	SOUND_92 = 92,
	SOUND_93_sabotage = 93,
	SOUND_MUTE_BUILDING_COMPLETED = 96,
	SOUND_101 = 101,
	SOUND_MUTE_UPGRADE_COMPLETE_1 = 102,
	SOUND_MUTE_UPGRADE_COMPLETE_2 = 104,
	SOUND_105_sabotage = 105,
	SOUND_108_mekanik = 108,
	SOUND_116 = 116,
	SOUND_119 = 119,
	SOUND_MUTE_LOW_OIL_WARNING = 122,
	SOUND_124_mute_saboteur = 124,
	SOUND_MUTE_UNIT_READY = 125,
	SOUND_MUTE_COMMENCING_UPGRADE = 126,
	SOUND_MUTE_UNIT_DRILL_RIG = 128,
	SOUND_129 = 129,
	SOUND_131 = 131,
	SOUND_132 = 132,
	SOUND_133 = 133,
	SOUND_MUTE_AIRSTRIKE_READY = 136,
	SOUND_139 = 139,
	SOUND_140 = 140,
	SOUND_141 = 141,
	SOUND_142 = 142,
	SOUND_148 = 148,
	SOUND_153 = 153,
	SOUND_154 = 154,
	SOUND_155 = 155,
	SOUND_156 = 156,
	SOUND_157 = 157,
	SOUND_158 = 158,
	SOUND_MUTE_UNIT_WAR_MASTADONT_2 = 159,
	SOUND_MUTE_UNIT_WAR_MASTADONT_READY = 160,
	SOUND_ACID_SPIT_DMG = 161,
	SOUND_163 = 163,
	SOUND_MUTE_UNIT_DIRE_WOLF_2 = 164,
	SOUND_MUTE_UNIT_DIRE_WOLF_READY = 165,
	SOUND_MISSION_OUTCOME_LETTER_APPEARING = 166,
	SOUND_MUTE_UNIT_GIANT_BEETLE_READY = 168,
	SOUND_MUTE_UNIT_GIANT_BEETLE_2 = 169,
	SOUND_MUTE_UNIT_MISSILE_CRAB_READY = 170,
	SOUND_MUTE_UNIT_MISSILE_CRAB_2 = 171,
	SOUND_MUTE_UNIT_GIANT_SCORPION_READY = 172,
	SOUND_MUTE_UNIT_GIANT_SCORPION_2 = 173,
	SOUND_174 = 174,
	SOUND_175 = 175,
	SOUND_176 = 176,
	SOUND_177 = 177,
	SOUND_178 = 178,
	SOUND_179 = 179,
	SOUND_180 = 180,
	SOUND_181 = 181,
	SOUND_182 = 182,
	SOUND_183 = 183,
	SOUND_184 = 184,
	SOUND_185 = 185,
	SOUND_186 = 186,
	SOUND_187 = 187,
	SOUND_188 = 188,
	SOUND_MobileOutpost_ClanhallWagon_Planted = 189,
	SOUND_SHOTGUN_FIRE_2 = 190,
	SOUND_TANKER_OIL_UNLOADING = 191,
	SOUND_SURV_UNIT_SCOUT_192 = 192,
	SOUND_193 = 193,
};

/* 364 */
struct _47CAF0_task_attachment1
{
	_47CAF0_task_attachment1 *next;
	_47CAF0_task_attachment1 *prev;
	Script *_8_script;
	_47CAF0_task_attachment2 *attach2_list;
	_47CAF0_task_attachment2 *attach2_list_free_pool;
	Script *owning_task;
	int owning_task_idx_1;
	int field_1C;
	int owning_task_idx_2;
	int field_24;
	int owning_task_idx_3;
	int field_2C;
	int field_30;
};

/* 366 */
struct _47CAF0_task_attachment2
{
	_47CAF0_task_attachment2 *next;
	int field_4;
	int field_8;
};

/* 368 */
struct BasicProductionOption
{
	int production_mask;
	enum UNIT_ID unit_stats_idx;
	int mobd_lookup_table_offset;
};

/* 370 */
struct EntityBuildingState
{
	void *oilspot_for_drillrig__task_for_researchlab;
	int num_upgrades;
	int field_8__0_for_repstation;
	__int16 same_buildings_count;
	__int16 sabotage_points;
	ProductionGroup *production_group;
	EntityBuildingAttachment_stru14 *pstru14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
};

/* 371 */
enum LEVEL_ID : __int32
{
	LEVEL_SURV_01_THE_NEXT_GENERATION = 0,
	LEVEL_SURV_02_BUILD_AN_OUTPOST = 1,
	LEVEL_SURV_03_WITHSTAND_THE_RAIDING_PARTY = 2,
	LEVEL_SURV_04_RESCUE_THE_SCOUT = 3,
	LEVEL_SURV_06_EXTERMINATE_THE_VILLAGE = 5,
	LEVEL_SURV_07_PROTECT_THE_CONVOY = 6,
	LEVEL_SURV_09_RESCUE_THE_COMMANDER = 8,
	LEVEL_SURV_12_SURGICAL_STRIKE = 11,
	LEVEL_SURV_15 = 14,
	LEVEL_MUTE_01 = 15,
	LEVEL_MUTE_03_BUBBLIN_CRUDE = 17,
	LEVEL_MUTE_04_RAID_THE_FORT = 18,
	LEVEL_MUTE_05_AMBUSH = 19,
	LEVEL_MUTE_08_SMASH_THE_CONVOY = 22,
	LEVEL_MUTE_09_FIGHT_FOR_TERRITORY = 23,
	LEVEL_MUTE_14_THE_FINAL_ASSAULT = 28,
	LEVEL_MUTE_15 = 29,
	LEVEL_SURV_16 = 48,
	LEVEL_SURV_18 = 50,
	LEVEL_SURV_21 = 53,
	LEVEL_SURV_23 = 55,
	LEVEL_SURV_25 = 57,
	LEVEL_MUTE_16 = 58,
	LEVEL_MUTE_25 = 67,

    LEVEL_INVALID = -1
};

/* 372 */
struct EntityTurret
{
	Script *sprite_task;
	Sprite *turret_sprite;
	Entity *entity;
	Entity *_C_entity;
	void(*handler)(EntityTurret *);
	int mobd_lookup_id;
	int field_18;
	int field_1C;
	int field_20;
	Entity_stru_dmg_related *ptr_24;
	UnitAttachmentPoint *stats_attachment_point;
	int field_2C;
	int _C_entity_idx;
	int field_34;
};

/* 373 */
struct EntityTankerConvoyAttachment
{
	int x;
	int y;
	int checkpoint;
};

/* 374 */
struct VideoFileHeader
{
	__int16 _0__first_4_bits_eq_bpp;
	__int16 width;
	__int16 height;
	__int16 field_6;
	__int16 field_8;
	__int16 num_frames;
	__int16 current_frame;
	__int16 field_E;
	int field_10;
	int _14_looks_like_fps;
	int field_18;
	int num_sound_bytes;
	__int16 *ptr_20;
	int field_24;
	int field_28;
};

/* 376 */
struct VideoFileFrame
{
	int frame_size;
	__int16 field_4;
	__int16 field_6;
	__int16 field_8;
	__int16 field_A;
	char gap_C[8];
	__int16 _14__first_4_bits_eq_bpp;
	__int16 width;
	__int16 height;
	__int16 field_1A;
	__int16 field_1C;
	__int16 num_frames;
	__int16 field_20;
	__declspec(align(1)) int _22_looks_like_fps;
	__int16 field_26;
	__int16 field_28;
	__int16 field_2A;
	__int16 field_2C;
	__int16 field_2E;
	__int16 field_30;
	__int16 field_32;
	__int16 field_34;
	__int16 field_36;
	__int16 field_38;
	__int16 field_3A;
};

/* 375 */
struct VideoFile
{
	VideoFileHeader header;
	_BYTE gap2C[372];
	int field_1A0[80];
	_BYTE gap2E0[36];
	int field_304[9];
	_BYTE gap328[8];
	__int16 field_330;
	__int16 field_332;
	FILE *file;
	int data_offset;
	void *frame_front_buffer;
	void *frame_back_buffer;
	int _344_prolly_palette[256];
	VideoFileFrame _744_frame;
	char field_780[131015];
	char field_20747;
};

/* 377 */
struct DetailedDrawHandler_VideoPlayer
{
	int(*handler)(DrawJobDetails *data, int mode);
	int width;
	int height;
	int field_C;
	int field_10;
	int field_14;
	void *_18_img_data;
};

/* 378 */
struct KeyboardInput
{
	int pressed_keys_mask;
	int just_pressed_keys_mask;
	int unpressed_keys_mask;
	int field_C;
	int _10_wndproc_mapped_key;
};

/* 379 */
struct VKeyMap
{
	int virtual_key;
	int mask;
};

/* 382 */
enum GAME_STATE : __int32
{
	GAME_MAIN_MENU = 0,
	GAME_STATE_1 = 1,
	GAME_STATE_4 = 4,
	GAME_STATE_7 = 7,
	GAME_STATE_8 = 8,
	GAME_STATE_13 = 13,
};

/* 383 */
struct stru32
{
	int field_0;
	int field_4;
	int field_8;
};

/* 384 */
struct stru37
{
	stru37 *next;
	stru37 *prev;
	int _8_cost_per_time_step;
	int _C_cost_per_time_step;
	int _10_cost;
	int *_14_pcost;
	int *_18_pcash;
	int field_1C;
	int *_20_pcost_plus1;
	void *_28_production_task_param;
	Script *_28_production_task;
};

/* 385 */
struct stru38
{
	stru38 *next;
	stru38 *prev;
	stru37 *pstru37;
	stru37 *_C_pstru37;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
};

/* 386 */
struct MapdScrlImageTile
{
	int flags;
	unsigned char pixels[2];
};

/* 388 */
struct DataMobdItem_stru0
{
	int x_offset;
	int y_offset;
	int field_8;
	MobdSprtImage *sprt;
	void *ptr_10;
	SOUND_ID _14_sound_id;
	DataMobdItem_stru1 *field_18;
};

/* 389 */
struct DataBoxd_stru0_per_map_unit
{
	char flags;
	char flags2;
	char field_2;
	char field_3;
	Entity *_4_entities[5];
};

/* 390 */
struct BoxdTile
{
	BoxdTile_stru0 *pstru0;
	void *ptr_4;
	int field_8;
};

/* 391 */
struct BoxdTile_stru0
{
	int type;
	int _4_x;
	int _8_y;
	int field_C;
	int _10_z;
	int _14_w;
};

/* 393 */
struct Task_context_0
{
	void(*handler)(Task_context_0 *);
	int field_4;
	Sprite *sprite_2;
	Sprite *sprite_1;
	Script *task;
};

/* 394 */
struct Task_context_1_BomberDmgHandler
{
	void(*handler)(Task_context_1_BomberDmgHandler *);
	Sprite *sprite;
	Script *task;
};

/* 395 */
struct DataMobdItem_stru1
{
	int field_0;
	int x_offset;
	int y_offset;
	int field_C;
	int field_10;
};

/* 397 */
enum MAPD_ID : __int32
{
	MAPD_MAP = 0x0,
	MAPD_FOG_OF_WAR = 0x1,
};

/* 412 */
struct DataCplcItem_ptr1_stru20
{
    enum MOBD_ID mobd_id;
    void(*handler)(Script *);
    int field_8;
    int field_C;
    Sprite *sprite;
    int field_14;
    int field_18;
    int _1C_oilspot_oil_units__or__param;
    enum UNIT_ID unit_stats_id;
    int field_24;
    int field_28;
    int field_2C;
};

/* 398 */
struct DataCplcItem_ptr1
{
	int script_handler_id;
	int x;
	int y;
	int z_index;
	DataCplcItem_ptr1 *next1;
	DataCplcItem_ptr1 *prev1;
	DataCplcItem_ptr1 *next2;
	DataCplcItem_ptr1 *prev2;
	DataCplcItem_ptr1_stru20 _20_stru20;
};

/* 399 */
struct _4269B0_task_attachment
{
	void(*handler)(_4269B0_task_attachment *);
	Script *task;
	int x;
	int y;
	int field_10;
	int field_14;
	int field_18;
	int __468410_stru49_array_idx;
	int stru53_54_55_unit_stats_idx_idx;
	int _24_iftrue__call_UNIT_Spawn__else__create_manually;
	int field_28;
};

/* 402 */
struct stru48
{
	int sprite_x;
	int sprite_y;
	int _8_sprite_cplc;
};

/* 403 */
struct stru49
{
	stru53 *pstru_53_54_55;
	int _4_some_task_flags;
	int _8_some_task_flags;
	int field_C;
};

/* 404 */
struct stru50
{
	enum UNIT_ID unit_stats_idx;
	int x;
	int y;
};

/* 406 */
struct stru51_tech_bunkers
{
	int x;
	int y;
};

/* 407 */
struct Sprite_stru74
{
	int field_0;
};

/* 408 */
struct stru52
{
	int unit_stats_idx[6];
};

/* 409 */
struct stru53
{
	enum UNIT_ID unit_stats_idx[4];
};

/* 410 */
struct stru54
{
	enum UNIT_ID unit_stats_idx[8];
};

/* 411 */
struct stru55
{
	enum UNIT_ID unit_stats_idx[10];
};

/* 415 */
struct SpriteSerialized
{
	enum MOBD_ID mobd_idx;
	int x;
	int y;
	int z_index;
	int x_speed;
	int y_speed;
	int z_speed;
	int _inside_mobd_item;
	int _54_inside_mobd_ptr4;
	int _60_mobd_field_0;
};

/* 414 */
struct EntitySerialized
{
	int id;
	enum SCRIPT_TYPE entity_task_event;
	int entity_task_handler_idx;
	int entity_task_message_handler_idx;
	int entity_task_field_20;
	int entity_task_field_14;
	int entity_task_field_24;
	int entity_task_field_28;
	int entity_task_field_2C;
	enum UNIT_ID unit_stats_idx;
	int player_side;
	enum SCRIPT_TYPE turret_sprite_task_event;
	int turret_sprite_task_handler_idx;
	int turret_sprite_task_message_handler_idx;
	int turret_sprite_task_field_20;
	int turret_sprite_task_field_14;
	int turret_sprite_task_field_24;
	int turret_sprite_task_field_28;
	int turret_sprite_task_field_2C;
	SpriteSerialized turret_sprite;
	int turret_C_entity_id;
	int turret_mode;
	int turret_mobd_lookup_id;
	int turret_field_18;
	int turret_field_1C;
	int turret_field_20;
	int turret_field_2C;
	int turret_entity__or__C_entity_id;
	int turret_field_34;
	int entity_mode;
	int entity_mode_idle;
	int entity_mode_arrive;
	int entity_mode_attacked;
	int entity_mode_return;
	int entity_mode_turn_return;
	int entity_message_handler_idx;
	SpriteSerialized entity_sprite;
	int entity_field_78;
	enum MOBD_ID entity_mobd_idx;
	int entity_field_80;
	int entity_field_84;
	int entity_field_88;
	int entity_hitpoints;
	int entity_field_94;
	int entity_98__465610_damage_multipliers_idx;
	int entity_9C_hp_regen_condition;
	int entity_A0_hp_regen_condition;
	int field_A4;
	int entity_sprite_width_shr13;
	int entity_sprite_height_shr13;
	int entity_sprite_width;
	int entity_sprite_height;
	int field_B8;
	int field_BC;
	int field_C0;
	int field_C4;
	int field_C8;
	int field_CC;
	int field_D0;
	int field_D4;
	int field_D8;
	int field_DC;
	int entity_EC_outpost_clanhall_entity_id;
	int entity_E4_entity_id;
	int entity_E0_outpost_clanhall_entity_id;
	int _E4_entity_id;
	int entity_F4_entity_118_entity_id;
	int entity_sprite_width_2;
	int entity_sprite_height_2;
	int entity_entity_118_entity_id;
	int entity_field_11C;
	int entity_field_120;
	int entity_field_124;
	int entity_field_128;
	int entity_field_12C;
	int entity_entity_id;
	int entity_field_134;
	int entity_field_138;
	int entity_field_13C;
	int entity_field_140;
	int entity_field_144;
	int entity_field_148;
	int entity_field_14C;
	int entity_field_150;
	int entity_field_154;
	int entity_field_158;
	char entity_array_15C[40];
	char entity_array_184[40];
	char entity_array_1AC[40];
	char entity_array_1D4[40];
	char entity_array_1FC[40];
	char entity_array_224[88];
	int entity_27C_entity_id;
	int entity_27C_entity_id_2;
	int entity_array_294[8];
	__int16 field_2E8;
	__int16 field_2EA;
	int field_2EC;
};

/* 416 */
struct Entity_stru60_stru4
{
	int field_0;
	int x_offset;
	int y_offset;
};

/* 420 */
struct EnemyAI_stru57
{
	int field_0;
	enum UNIT_ID unit_id;
};

/* 423 */
struct BuildingPlanner
{
	enum UNIT_ID unit_stats_idx;
	int field_4;
	int field_8;
	int cost;
};

/* 456 */
struct EntityBuildingAttachment_stru14_stru2
{
	char field_0[59];
};

/* 453 */
struct EntityBuildingAttachment_stru14_stru0
{
	EntityBuildingAttachment_stru14_stru2 field_0;
	char field_3B;
	char field_3C;
	char field_3D;
	char field_3E;
	char field_3F;
	char field_40;
	char field_41;
};

/* 454 */
struct EntityBuildingAttachment_stru14_stru1
{
	char field_0[12];
};

/* 455 */
struct EntityBuildingAttachment_stru14_stru29D
{
	char field_0[2];
	EntityBuildingAttachment_stru14_stru1 field_2[5];
	char field_3E[6];
	EntityBuildingAttachment_stru14_stru0 field_44;
	char field_86[192];
	char field_146;
	char field_147;
	char field_148;
	char field_149;
};

/* 424 */
struct EntityBuildingAttachment_stru14
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	char unk_10[127];
	EntityBuildingAttachment_stru14_stru0 _8F_healthbar[2];
	char gap_113[66];
	EntityBuildingAttachment_stru14_stru0 field_155;
	EntityBuildingAttachment_stru14_stru1 field_197[5];
	char unk_1D3[202];
	EntityBuildingAttachment_stru14_stru29D field_29D;
	char field_3E7;
	char field_3E8[2];
};

/* 425 */
struct EntityOilTankerAttachment_stru70
{
	int field_0;
	int field_4;
	int field_8;
	char gap_C[63];
	char field_4B[28];
	__declspec(align(1)) int field_67;
	char field_6B[28];
	char gap87[36];
	char array_AB[28];
	__declspec(align(1)) int field_C7;
	char array_CB[28];
	char gapE7[65];
	char field_128;
	char field_129;
	char field_12A;
	char field_12B;
};

/* 426 */
struct EntityOilTankerState
{
	int _0_oil_loaded;
	Entity *_4_entity;
	Entity *powerstation;
	Entity *drillrig;
	int drillrig_entity_id;
	int powerstation_entity_id;
	int _18_entity_id;
	int array_20_size;
	Entity *array_20[20];
	EntityOilTankerAttachment_stru70 *pstru70;
};

/* 428 */
struct sound_stru_2
{
	int riff_fourcc;
	int riff_chunk_size;
	int data_fourcc;
	int data;
};

/* 429 */
struct stru175
{
	char str_0[12];
	int field_C;
	int field_10;
	enum LEVEL_ID level_id;
};

/* 431 */
struct stru24_struC
{
	stru24_struC *next;
	int field_4;
	int field_8;
	void *_C_param;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
	int field_4C;
	int field_50;
	int field_54;
	int field_58;
	int field_5C;
	int field_60;
	int field_64;
	int field_68;
	int field_6C;
	int field_70;
	int field_74;
	int field_78;
	int field_7C;
	int field_80;
	int field_84;
	int field_88;
	int field_8C;
	int field_90;
	int field_94;
	int field_98;
	int field_9C;
	int field_A0;
	int field_A4;
	int field_A8;
	int field_AC;
	int field_B0;
	int field_B4;
	int field_B8;
	int field_BC;
	int field_C0;
	int field_C4;
	int field_C8;
	int field_CC;
	int field_D0;
	int field_D4;
	int field_D8;
	int field_DC;
	int field_E0;
	int field_E4;
	int field_E8;
	int field_EC;
	int field_F0;
	int field_F4;
	int field_F8;
	int field_FC;
	int field_100;
	int field_104;
	int field_108;
	int field_10C;
	int field_110;
	int field_114;
	int field_118;
	int field_11C;
	int field_120;
	int field_124;
	int field_128;
	int field_12C;
	int field_130;
};

/* 432 */
struct task_sidebar_attachment
{
	void *handler;
	int field_4;
	Sprite *_8_sprite;
	Sprite *_C_sprite_sidebar;
	Script *__47C970_sidebar_task;
};

/* 434 */
struct task_426710_attachment_x_mark
{
	void(*handler)(task_426710_attachment_x_mark *);
	Script *task;
	Sprite *sprite;
};

/* 435 */
struct _428940_local
{
	_428940_local *next;
	_428940_local *prev;
	Script *_8_task;
	task_428940_attach__cursors_2 *pstru2;
	task_428940_attach__cursors_2 *ptr_10;
	Script *_14_task;
	Script *_18_script;
	Script *_1C_script;
	int _20_load_mobd_item_offset;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int _38_are_owned_units_selected;
	int field_3C;
	int _40_is_infantry_or_vehicle_selected;
	int _44_is_combat_unit_selected;
	enum UNIT_ID _48_highest_ranking_selected_unit;
	int field_4C;
	int cursor_x;
	int cursor_y;
	int field_58;
	int field_5C;
	int field_60;
	int field_64;
	Entity *_68_selected_moveable_entity;
	int _68_entity_type___0convoy__2lab__9scout__3saboteur_vandal__4technicial_mekanik__and_more_see429D40;
	Sprite *_70_sprite;
	Sprite *_74_sprite;
	void *_78_msg1522_param;
};

/* 436 */
struct _428940_global
{
    task_428940_attach__cursors *ptr;
    int field_4;
    int field_8;
    int field_C;
	int _10_current_idx;
};

/* 437 */
/*struct _47A660_global
{
	int field_0;
	int field_4;
	int field_8;
	char field_C;
	char _D_is_free;
};*/

/* 438 */
struct _47CA80_global
{
	int field_0;
	int field_4;
	int field_8;
	char field_C;
};

/* 439 */
struct _47A780_global
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
};

/* 444 */
struct Boxd_stru0
{
	Sprite_stru58 *sprite_pstru58;
	Sprite *sprite;
	Boxd_stru0 *ptr_8;
};

/* 445 */
struct Sprite_stru58
{
	Sprite_stru58_stru0 *pstru0;
};

/* 446 */
struct Sprite_stru58_stru0
{
	int psrite_pstru7_idx;
	int x;
	int y;
	int field_C;
	int z;
	int w;
};

/* 451 */
struct Vec2
{
	int x;
	int y;
};

/* 452 */
struct stru196
{
	enum UNIT_ID unit_id;
	int _4_x;
	int _8_y;
	int field_C;
	int field_10;
	unsigned int field_14;
};

/* 457 */
struct stru201_displaymode
{
	char name[8];
	int field_8;
	int field_C;
};

/* 458 */
struct Entity_stru_dmg_related
{
	int field_0;
	int x_offset;
	int y_offset;
	int z_index_offset;
};

/* 459 */
struct EntityUpgradeAttachment
{
	void(*handler)(EntityUpgradeAttachment *);
	int field_4;
	int field_8;
	int field_C;
	Sprite *_18_sprite_parent;
	int field_14;
	Sprite *_18_sprite;
	Script *script;
};

/* 460 */
struct Mapd_stru0
{
	int mapd_cplc_render_x;
	int mapd_cplc_render_y;
	int mapd_cplc_item0_ptr_field_C;
};

#pragma pack(pop)