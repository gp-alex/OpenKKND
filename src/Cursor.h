#pragma once

#include "src/Script.h"

struct Entity;

enum SELECTED_ENTITY_TYPE : __int32
{
    SELECTED_ENTITY_0 = 0,
    SELECTED_ENTITY_TANKER = 1,
    SELECTED_ENTITY_LABORATORY = 2,
    SELECTED_ENTITY_SABOTEUR = 3,
    SELECTED_ENTITY_TECHNICIAN = 4,
    SELECTED_ENTITY_COMBAT_VEHICLE = 6,
    SELECTED_ENTITY_MOBILE_BASE = 7,
    SELECTED_ENTITY_MOBILE_DERRICK = 8,
    SELECTED_ENTITY_COMBAT_INFANTRY = 9,
};



enum stru209_TYPE : __int8
{
    stru209_TYPE_0 = 0,
    stru209_TYPE_SELECT_UNIT_GROUP = 1,
    stru209_TYPE_SELECT_UNIT = 2,
    stru209_TYPE_DESELECT = 3,
    stru209_TYPE_ASSIGN_UNIT_GROUP = 4,
    stru209_TYPE_FORCE_ATTACK = 5,
    stru209_TYPE_MOVE = 6,
    stru209_TYPE_ATTACK = 7,
    stru209_TYPE_8_production_ready = 8,
    stru209_TYPE_9_spawn_unit = 9,
    stru209_TYPE_DEPLOY_MOBILE_OUTPOST = 10,
    stru209_TYPE_11 = 11,
    stru209_TYPE_12_upgrade_complete = 12,
    stru209_TYPE_13 = 13,
    stru209_TYPE_PAUSE_GAME = 15,
    stru209_TYPE_RESUME_GAME = 16,
    stru209_TYPE_17_multiplayer = 17,
    stru209_TYPE_18 = 18,
    stru209_TYPE_TANKER_SET_DRILLRIG = 19,
    stru209_TYPE_TANKER_SET_BASE = 20,
    stru209_TYPE_REPAIR_AT_STATION = 21,
    stru209_TYPE_TECHNICIAN_REPAIR = 22,
    stru209_TYPE_INFILTRATE = 24,
    stru209_TYPE_25_spawn_unit = 25,
    stru209_TYPE_26_destroy = 26,
    stru209_TYPE_SWEAR_ALLEGIANCE = 27,
};
const char *stru209type_to_string(stru209_TYPE);



#pragma pack(push, 1)
struct stru209
{
    stru209_TYPE type;
    int param;
    int param2;
    int param3;
    char _is_free;
};
#pragma pack(pop)


/* 422 */
#pragma pack(push, 1)
struct task_428940_attach__cursors_2
{
    task_428940_attach__cursors_2 *next;
    task_428940_attach__cursors_2 *prev;
    Script *_8_task;
};
#pragma pack(pop)


/* 421 */
#pragma pack(push, 1)
struct task_428940_attach__cursors
{
    task_428940_attach__cursors *next;
    stru209 _stru209;
    char field_12;
    char field_13;
};
#pragma pack(pop)

/* 435 */
#pragma pack(push, 1)
struct CursorHandler
{
    CursorHandler *next;
    CursorHandler *prev;
    Script *_8_task;
    task_428940_attach__cursors_2 *pstru2;
    task_428940_attach__cursors_2 *ptr_10;
    Script *cursor_task;
    Script *_18_script;
    Script *cursor_target_ai;
    int _20_load_mobd_item_offset;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int _34_is_cursor_over_impassible_terrain;
    int _38_are_owned_units_selected;
    int _3C_is_single_unit_selected;
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
    SELECTED_ENTITY_TYPE _68_selected_moveable_entity_type;
    Sprite *_70_sprite;
    Sprite *_74_sprite;
    void *_78_msg1522_param;
};
#pragma pack(pop)





#define CURSOR_MOBD_0                               0
#define CURSOR_MOBD_OFFSET_DEFAULT                  12  // default arrow
#define CURSOR_MOBD_OFFSET_HELP                     24  // bright help arrow
#define CURSOR_MOBD_OFFSET_HELP_2                   36  // dim help arrow
#define CURSOR_MOBD_OFFSET_UNIT_HOVER               48  //
#define CURSOR_MOBD_OFFSET_REPAIR                   144 //
#define CURSOR_MOBD_OFFSET_DEPLOY_MOBILE_OUTPOST    188 //
#define CURSOR_MOBD_OFFSET_RESEARCH                 216 //
#define CURSOR_MOBD_OFFSET_INFILTRATE               244 // sabotage
#define CURSOR_MOBD_OFFSET_CANT_RESEARCH            280 //
#define CURSOR_MOBD_OFFSET_CANT_REPAIR              292 //
#define CURSOR_MOBD_OFFSET_ATTACK                   304 //
#define CURSOR_MOBD_OFFSET_MOVE                     384 //
#define CURSOR_MOBD_OFFSET_DENIED                   448 // impassible terrain cursor
#define CURSOR_MOBD_OFFSET_DRAG_FRAME_X             460 // units selection top left
#define CURSOR_MOBD_OFFSET_DRAG_FRAME_Y             472 //
#define CURSOR_MOBD_OFFSET_DRAG_FRAME_Z             484 //
#define CURSOR_MOBD_OFFSET_DRAG_FRAME_W             496 //
#define CURSOR_MOBD_OFFSET_MOVE_CLICK               508 // issue move order
#define CURSOR_MOBD_OFFSET_DRILL                    572 //
#define CURSOR_MOBD_OFFSET_UPGRADE_3_STILL          732
#define CURSOR_MOBD_OFFSET_UPGRADE_4_RUNNING        756
#define CURSOR_MOBD_OFFSET_UPGRADE_4_STILL          768
#define CURSOR_MOBD_OFFSET_UPGRADE_5_RUNNING        792
#define CURSOR_MOBD_OFFSET_UPGRADE_5_FLASHING       804
#define CURSOR_MOBD_OFFSET_BORDERLESS_CURSOR        840 // borderless default arrow
#define CURSOR_MOBD_OFFSET_MISSION_ARROW_S_BLINK    852
#define CURSOR_MOBD_OFFSET_MISSION_ARROW_SW         864
#define CURSOR_MOBD_OFFSET_MISSION_ARROW_SW_BLINK   868
#define CURSOR_MOBD_OFFSET_1728                     1728
#define CURSOR_MOBD_OFFSET_1740                     1740
#define CURSOR_MOBD_OFFSET_1752                     1752
#define CURSOR_MOBD_OFFSET_1764                     1764

void cursor_drag_selection(CursorHandler *a1, int x, int y); // idb
void cursor_on_unit_selection(CursorHandler *a1, Entity *a2);
void cursor_on_unit_group_selection(CursorHandler *a1);
void cursor_classify_selected_unit(CursorHandler *a1, Entity *entity);


void script_game_cursor_handler(Script *a1); // idb


task_428940_attach__cursors *_428940_list_get();
void _428940_list_return(task_428940_attach__cursors *item);

stru209 *_47A660_list_get();
void _428940_list_do_stuff(stru209 *a1);

void sub_4297D0(CursorHandler *a1, int a2);
void cursor_load_mobd(CursorHandler *a1, int offset); // idb
bool cursor_check_click(CursorHandler *a1);
void cursor_group_orders(CursorHandler *a1); // cursor handler for unit group
void _42AFD0_vehicle_repair_station_handler(CursorHandler *a1, Entity *a2); // idb
void cursor_unit_move_confirmation(CursorHandler *a1);
void cursor_sidebar_handler(CursorHandler *a1);
void cursor_process_user_actions(CursorHandler *a1, int a2);


extern task_428940_attach__cursors *task_428940_attach__cursors_list;
extern task_428940_attach__cursors *task_428940_attach__cursors_list_free_pool;

extern task_428940_attach__cursors _47A714;

extern stru209 _47A660_array[10];

extern stru209 stru_47CAE0; // weak