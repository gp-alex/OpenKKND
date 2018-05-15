#include "Engine/Entity.h"

#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"
#include "src/kknd.h"
#include "src/Script.h"

#include "Engine/Infrastructure/EntityRepository.h"

using Engine::Infrastructure::EntityRepository;


int entity_get_mobd_speed_x(Entity *entity)
{
    if (entity->current_mobd_lookup_idx != -1)
    {
        return entity->stats->speed * _4731A8_speeds[__47CFC4_mobd_lookup_speeds[entity->current_mobd_lookup_idx + 1]] / 64;
    }
    return 0;
}

int entity_get_mobd_speed_y(Entity *entity)
{
    if (entity->current_mobd_lookup_idx != -1)
    {
        return entity->stats->speed * _4731A8_speeds[8 + __47CFC4_mobd_lookup_speeds[entity->current_mobd_lookup_idx + 1]] / 64;
    }
    return 0;
}

// XL vehicles: mobile outpost, autocannon tank & missile crab
bool entity_is_xl_vehicle(Entity *entity) {
    return entity->stats->field_4C == 4096;
}


bool entity_is_tower(Entity *entity) {
    return is_tower(entity->unit_id);
}

bool entity_is_bomber(Entity *entity) {
    return is_bomber(entity->unit_id);
}

bool entity_is_21st_century(Entity *entity) {
    return is_21st_century(entity->unit_id);
}

bool entity_is_moveable(Entity *entity) {
    return entity->unit_id <= UNIT_STATS_MUTE_MISSILE_CRAB || entity->unit_id >= UNIT_STATS_GORT;
}

bool entity_is_attacker(Entity *entity)
{
    return
        entity_is_moveable(entity)
        && (entity->unit_id < UNIT_STATS_SURV_MOBILE_DERRICK || entity->unit_id > UNIT_STATS_TANKER_CONVOY)
        && (entity->unit_id < UNIT_STATS_SURV_TECHNICIAN || entity->unit_id > UNIT_STATS_MUTE_MEKANIK)
        || entity_is_tower(entity);
}



bool is_21st_century(UNIT_ID unit_id) {
    return unit_id >= UNIT_STATS_GORT && unit_id <= UNIT_STATS_MECH;
}

bool is_tower(UNIT_ID unit_id) {
    return unit_id >= UNIT_STATS_SURV_GUARD_TOWER && unit_id <= UNIT_STATS_MUTE_ROTARY_CANNON;
}

bool is_bomber(UNIT_ID unitId) {
    return unitId == UNIT_STATS_SURV_BOMBER || unitId == UNIT_STATS_MUTE_WASP;
}




int entity_get_dx(Entity *entity)
{
    if (entity->stats->is_infantry)
        return entity_40F0A0_get_dx(entity, entity->field_A4);
    else
        return entity->stats->field_4C != 128 ? 7424 : 4096;
}

int entity_get_dy(Entity *entity)
{
    if (entity->stats->is_infantry)
        return entity_40F100_get_dy(entity, entity->field_A4);
    else
        return entity->stats->field_4C != 128 ? 7424 : 4096;
}


int entity_transform_x(Entity *entity, int x)
{
    return entity_get_dx(entity) + (x & 0xFFFFE000);
}

int entity_transform_y(Entity *entity, int y)
{
    return entity_get_dy(entity) + (y & 0xFFFFE000);
}



void entity_load_mobd_4(Entity *entity)
{
    if (entity->stats->mobd_lookup_offset_4 != -1)
    {
        sprite_4272E0_load_mobd_item(
            entity->sprite,
            entity->stats->mobd_lookup_offset_4,
            _47D3C4_entity_mobd_lookup_ids[entity->current_mobd_lookup_idx + 1]);
    }
}

void entity_load_idle_mobd(Entity *entity, int idx)
{
    entity->current_mobd_lookup_idx = idx;
    entity_load_idle_mobd(entity);
}

void entity_load_idle_mobd(Entity *entity)
{
    if (entity->stats->mobd_lookup_offset_idle != -1)
    {
        sprite_4272E0_load_mobd_item(
            entity->sprite,
            entity->stats->mobd_lookup_offset_idle,
            _47D3C4_entity_mobd_lookup_ids[entity->current_mobd_lookup_idx + 1]);
    }
}

void entity_load_move_mobd(Entity *entity, int idx)
{
    entity->current_mobd_lookup_idx = idx;
    entity_load_move_mobd(entity);
}

void entity_load_move_mobd(Entity *entity)
{
    if (entity->stats->mobd_lookup_offset_move != -1)
    {
        sprite_4272E0_load_mobd_item(
            entity->sprite,
            entity->stats->mobd_lookup_offset_move,
            _47D3C4_entity_mobd_lookup_ids[entity->current_mobd_lookup_idx + 1]);
    }
}

void entity_load_attack_mobd(Entity *entity)
{
    if (entity->stats->mobd_lookup_offset_attack != -1)
    {
        sprite_4272E0_load_mobd_item(
            entity->sprite,
            entity->stats->mobd_lookup_offset_attack,
            _47D3C4_entity_mobd_lookup_ids[entity->current_mobd_lookup_idx + 1]);
    }
}


void entity_load_attack_mobd(Entity *entity, int idx)
{
    entity->current_mobd_lookup_idx = idx;
    entity_load_attack_mobd(entity);
}

//----- (0041A270) --------------------------------------------------------
void entity_move(Entity *a1, _47CAF0_task_attachment1_move_task *a2)
{
    int v4; // eax@5
    int v5; // eax@9
    int v6; // eax@11

    if (a1->player_side == a2->player_side)
    {
        v4 = a1->_DC_order == ENTITY_ORDER_MOVE
            && map_is_same_tile(a2->dst_x, a1->sprite_x_2)
            && map_is_same_tile(a2->dst_y, a1->sprite_y_2);
        if (!v4 || a1->entity_8)
        {
            v5 = a2->dst_x;
            if (v5 >= 0 && v5 < map2global(_4793F8_map_width))
            {
                v6 = a2->dst_y;
                if (v6 >= 0 && v6 < map2global(_478AAC_map_height))
                {
                    a1->stru224.field_54 = 0;
                    a1->stru224.field_50 = 0;
                    script_445370_yield_to_main_thread(a1->script, 0x80000000, 1);

                    a1->_DC_order = ENTITY_ORDER_MOVE;
                    a1->_E4_prev_attack_target = a1->_E0_current_attack_target;
                    a1->_E4_prev_attack_target_entity_id = a1->_E0_current_attack_target_entity_id;
                    a1->_E0_current_attack_target = nullptr;
                    a1->_134_param__unitstats_after_mobile_outpost_plant = 600;

                    a1->sprite_x_2 = entity_transform_x(a1, a2->dst_x);
                    a1->sprite_y_2 = entity_transform_y(a1, a2->dst_y);
                    entity_414440_boxd(a1, &a1->sprite_x_2, &a1->sprite_y_2);

                    a1->entity_8 = 0;
                    entity_40DF50_boxd_update_map_tile(a1, 1);

                    a1->mode = entity_mode_move_attack;
                }
            }
        }
    }
}


//----- (00419F00) --------------------------------------------------------
void entity_attack(Entity *a1, _47CAF0_task_attachment1_attack_task *param)
{
    Entity *v3; // esi@1
    enum PLAYER_SIDE v4; // ecx@1
    Entity *v5; // edx@2
    enum PLAYER_SIDE v6; // eax@3
    int v7; // eax@7

    v3 = a1;
    v4 = a1->player_side;
    if (v4 == param->player_side)
    {
        v5 = param->target;
        if (v5 == v3->_E0_current_attack_target)
        {
            v3->_E4_prev_attack_target = 0;
            v3->_134_param__unitstats_after_mobile_outpost_plant = 600;
            if (v3->entity_8 != v3->_E0_current_attack_target)
                v3->entity_8 = 0;
        }
        else
        {
            v6 = v5->player_side;
            if (v6 && v6 != v4 && !is_enemy(v4, v5))
            {
                if (!single_player_game)
                {
                    v7 = param->target->player_side;
                    if (player_side == v7 || player_side == v3->player_side)
                    {
                        sprintf(
                            byte_479B00,
                            aAllegianceBroken,
                            netz_47A740[v7 + 1].player_name,
                            netz_47A740[v3->player_side + 1].player_name);
                        show_message_ex(0, byte_479B00);
                    }
                }
                game_globals_cpu[param->target->player_side].cash[v3->player_side] = 0;
                game_globals_cpu[v3->player_side].cash[param->target->player_side] = 0;
            }
            v3->stru224.field_54 = 0;
            v3->stru224.field_50 = 0;
            script_445370_yield_to_main_thread(v3->script, 0x80000000, 1);
            v3->_DC_order = ENTITY_ORDER_ATTACK;
            v3->_E0_current_attack_target = param->target;
            v3->_E0_current_attack_target_entity_id = param->target->entity_id;
            v3->_E4_prev_attack_target = 0;
            v3->_134_param__unitstats_after_mobile_outpost_plant = 600;
            v3->entity_8 = 0;
            v3->mode = entity_mode_move_attack;
        }
    }
}


//----- (00425820) --------------------------------------------------------
Entity *entity_find_player_entity_in_radius(Entity *a1, int max_distance_squared)
{
    for (auto i : entityRepo->FindAll())
    {
        if (!i->destroyed && i->player_side == player_side)
        {
            int dx = abs(a1->sprite->x - i->sprite->x);
            int dy = abs(a1->sprite->y - i->sprite->y);
            if (dx + dy < max_distance_squared)
                return i;
        }
    }
    return nullptr;
}


//----- (004078B0) --------------------------------------------------------
Entity *entity_find_any_entity_in_radius(Entity *a1, int max_distance_squared)
{
    for (auto i : entityRepo->FindAll())
    {
        if (!i->destroyed && i->player_side != PLAYER_SIDE_UNSPECIFIED)
        {
            int dx = abs(a1->sprite->x - i->sprite->x);
            int dy = abs(a1->sprite->y - i->sprite->y);
            if (dx + dy < max_distance_squared)
                return i;
        }
    }
    return nullptr;
}