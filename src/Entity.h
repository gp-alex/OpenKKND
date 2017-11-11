#pragma once

struct Script;
struct DrawJob;
struct DrawJobDetails;



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
    int _44_map_x;
    int _48_map_y;
    int field_4C;
    int field_50;
    int field_54;
};

enum ENTITY_ORDER : int
{
    ENTITY_ORDER_0 = 0,
    ENTITY_ORDER_MOVE = 1,
    ENTITY_ORDER_ATTACK = 2,
    ENTITY_ORDER_3 = 3,
    ENTITY_ORDER_4 = 4,
    ENTITY_ORDER_5 = 5,
    ENTITY_ORDER_6_tanker = 6,
    ENTITY_ORDER_7 = 7,
    ENTITY_ORDER_8 = 8,
    ENTITY_ORDER_9 = 9,
    ENTITY_ORDER_10 = 10,
    ENTITY_ORDER_11 = 11,
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
    int current_mobd_lookup_idx;
    int field_80;
    int field_84;
    int _88_dst_orientation; // mobd lookup idx of desired rotation
                             // 0 north
                             // 64 east
                             // 128 south
                             // 192 west
    int destroyed;
    int hitpoints;
    int field_94;
    int _98_465610_accuracy_dmg_bonus_idx;
    int _9C_hp_regen_condition;
    int _A0_hp_regen_condition;
    int field_A4;
    int sprite_map_x;
    int sprite_map_y;
    int sprite_x;
    int sprite_y;
    int field_B8;
    int field_BC;
    int _C0_mobd_anim_speed_related;
    int field_C4;
    int field_C8;
    int field_CC;
    int field_D0;
    int field_D4;
    int field_D8;
    ENTITY_ORDER _DC_order;
    Entity *_E0_current_attack_target;
    Entity *_E4_prev_attack_target;
    Entity *_E8_entity;
    int _E0_current_attack_target_entity_id;
    int _E4_prev_attack_target_entity_id;
    int entity_118_entity_id;
    int _E8_entity_id;
    int sprite_x_2;
    int sprite_y_2;
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



void entity_drag_selection_init(int y, int x, int z, int w);
Script *entity_drag_selection_get_next_entity();

Entity *entity_list_get();
Entity *entity_list_end();

int entity_get_dx(Entity *entity);
int entity_get_dy(Entity *entity);
int entity_transform_x(Entity *entity, int x);
int entity_transform_y(Entity *entity, int y);



bool entity_is_building(Entity *unit);
bool entity_is_moveable(Entity *unit);
bool entity_is_attacker(Entity *unit);
bool entity_is_tower(Entity *entity);

bool is_21st_century(UNIT_ID unit_id);
bool entity_is_21st_century(Entity *entity);

bool entity_is_xl_vehicle(Entity *entity);

void entity_load_attack_mobd(Entity *entity);
void entity_load_attack_mobd(Entity *entity, int idx);
void entity_load_move_mobd(Entity *entity);
void entity_load_move_mobd(Entity *entity, int idx);
void entity_load_idle_mobd(Entity *entity);
void entity_load_idle_mobd(Entity *entity, int idx);
void entity_load_mobd_4(Entity *entity);

int entity_get_mobd_speed_x(Entity *entity);
int entity_get_mobd_speed_y(Entity *entity);



void entity_attack(Entity *a1, _47CAF0_task_attachment1_attack_task *param);
void entity_move(Entity *a1, _47CAF0_task_attachment1_move_task *a2);