#pragma once

#include "kknd.h"


struct Script;
struct DrawJob;
struct DrawJobDetails;
struct stru11unit;



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
struct EntityPathing
{
    int num_waypoints;
    int _2C_waypoint_map_x;
    int _2C_waypoint_map_y;
    int _34_waypoint_map_x;
    int _34_waypoint_map_y;
    int field_3C;
    int _40_xy_idx;
    int destination_map_x;
    int destination_map_y;
    int _41B970_result; // 4C
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

#define ORIENTATION_N   0       // north
#define ORIENTATION_NNE 16      // north-north-east
#define ORIENTATION_NE  32      // north-east
#define ORIENTATION_E   64      // east
#define ORIENTATION_SE  96      // south-east
#define ORIENTATION_SSE 112     // south-south-east
#define ORIENTATION_S   128     // south
#define ORIENTATION_SSW 144     // south-south-west
#define ORIENTATION_SW  160     // south-west
#define ORIENTATION_W   192     // west
#define ORIENTATION_NW  224     // north-west
#define ORIENTATION_NNW 240     // north-north-west

/* 307 */
typedef void (*EntityMode)(struct Entity *);
struct Entity
{
    bool IsTanker() const {
        return unit_id == UNIT_STATS_SURV_TANKER || unit_id == UNIT_STATS_MUTE_TANKER;
    }

    bool IsInfantry() const {
        return stats->is_infantry;
    }

    inline void SetScriptEventHandler(ScriptEventHandler eventHandler) {
        script->SetEventHandler(eventHandler);
    }

    void SetMode(EntityMode mode);
    bool IsMode(EntityMode mode) const;
    void ExecMode();
    int ModeHandlerId() const;

    void SetReturnModeFromMode();

    inline void SetReturnMode(EntityMode mode) {
        this->mode_return = mode;
    }
    inline void SetTurnReturnMode(EntityMode mode) {
        this->mode_turn_return = mode;
    }

    inline void SetOrder(ENTITY_ORDER order) {
        this->_DC_order = order;
    }

    inline ENTITY_ORDER GetOrder() {
        return this->_DC_order;
    }

    inline int GetFiringRange() const {
        return this->stats->firing_range;
    }

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
private:
    void (*mode)(Entity *);
public:
    void (*mode_idle)(Entity *);
    void (*mode_arrive)(Entity *);
    void (*mode_attacked)(Entity *);
    void (*mode_return)(Entity *);
    void (*mode_turn_return)(Entity *);
    void (*event_handler)(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
    Sprite *sprite;
    Entity_stru60 stru60;
    int field_78;
    int current_mobd_lookup_idx;
    int field_80;
    int field_84;
    int _88_dst_orientation;    // mobd lookup idx of desired rotation
                                // ORIENTATION_*
    int destroyed;
    int hitpoints;
    int field_94;
    int _98_465610_accuracy_dmg_bonus_idx;
    int _9C_hp_regen_condition;
    int _A0_hp_regen_condition;
    int _A4_idx_in_tile;  // ENTITY_TILE_POSITION_*
    int sprite_map_x;
    int sprite_map_y;
    int sprite_x;
    int sprite_y;
    int _B8_move_dst_x;
    int _B8_move_dst_y;
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
    int _15C_waypoints_xs[10]; // map_x`s
    int _15C_waypoints_ys/*array_184*/[10]; // map_y`s
    int _1AC_waypoints_xs[10]; // map_x`s
    int _1AC_waypoints_ys/*array_1D4*/[10]; // map_y`s
    int _1FC_waypoints_xs[10]; // map_x`s  for map classification 0
    int _1FC_waypoints_ys/*array_224*/[10]; // map_y`s
    EntityPathing pathing;
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



bool entity_is_building(Entity *unit);
bool entity_is_moveable(Entity *unit);
bool entity_is_attacker(Entity *unit);
bool entity_is_tower(Entity *entity);
bool entity_is_bomber(Entity *entity);

bool is_21st_century(UNIT_ID unit_id);
bool is_tower(UNIT_ID unit_id);
bool is_bomber(UNIT_ID unitId);
bool entity_is_21st_century(Entity *entity);

bool entity_is_xl_vehicle(Entity *entity);
bool entity_is_regular_vehicle(Entity *entity);
bool entity_is_infantry(Entity *entity);

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


Entity *entity_find_player_entity_in_radius(Entity *a1, int max_distance_squared);
Entity *entity_find_any_entity_in_radius(Entity *a1, int max_distance_squared);