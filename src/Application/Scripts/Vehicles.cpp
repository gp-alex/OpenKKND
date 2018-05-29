#include "_unsorted_data.h"
#include "kknd.h"
#include "Script.h"
#include "ScriptEvent.h"

#include "Engine/Entity.h"
#include "Engine/EntityFactory.h"

using Engine::EntityFactory;

#include "Engine/Infrastructure/EntityRepository.h"

using Engine::Infrastructure::EntityRepository;

//----- (00444180) --------------------------------------------------------
void UNIT_Handler_OilTanker(Script *a1)
{
    Entity *v1; // esi@2
    int v2; // eax@4
    int v3; // eax@6

    if (!_47C6DC_dont_execute_unit_handlers)
    {
        v1 = (Entity *)a1->param;
        if (!v1)
        {
            v1 = EntityFactory().Create(a1);
            entity_oil_tanker_initialize(v1);
            entity_oil_tanker_initialize_state(v1);
        }
        (v1->mode)(v1);
        v1->script->script_type = SCRIPT_TANKER_CONVOY_HANDLER;
        v2 = v1->_12C_prison_bunker_spawn_type;
        if (v2)
            v1->_12C_prison_bunker_spawn_type = v2 - 1;
        v3 = v1->_134_param__unitstats_after_mobile_outpost_plant;
        if (v3)
            v1->_134_param__unitstats_after_mobile_outpost_plant = v3 - 1;
    }
}

//----- (004441E0) --------------------------------------------------------
void entity_oil_tanker_initialize(Entity *a1)
{
    Entity *v1; // esi@1
    EntityOilTankerState *v2; // eax@1
    UnitStat *v3; // eax@2
    int v4; // edi@3
    UnitStat *v5; // eax@5
    int v6; // eax@6
    int v7; // edi@8
    UnitStat *v8; // eax@9
    int v9; // eax@10
    unsigned int v10; // edx@12
    UnitStat *v11; // eax@12
    int v12; // eax@13
    Sprite *v13; // ecx@15
    int v14; // edx@15
    unsigned int v15; // edx@15
    int v16; // eax@15
    Script *v17; // edx@15
    Sprite *v18; // edx@18
    UnitStat *v19; // eax@19
    int v20; // eax@20
    int v21; // ecx@22
    UnitStat *v22; // eax@22
    int v23; // eax@23
    int v24; // ecx@25
    int v25; // eax@25
    Script *v26; // edx@25

    v1 = a1;
    a1->script->script_type = SCRIPT_TANKER_CONVOY_HANDLER;
    v2 = (EntityOilTankerState *)script_create_local_object(a1->script, 116);
    v1->state = v2;
    v2->_0_oil_loaded = 0;
    v2->_4_entity = 0;
    v2->drillrig = 0;
    v2->powerstation = 0;
    v2->drillrig_entity_id = 0;
    v2->powerstation_entity_id = 0;
    v2->_18_entity_id = 0;
    memset(v2->array_20, 0, sizeof(v2->array_20));
    if (v1->sprite->cplc_ptr1)
    {
        v3 = v1->stats;
        v1->_A4_idx_in_tile = 0;
        if (v3->is_infantry)
            v4 = entity_40F100_get_dy(v1, 0);
        else
            v4 = v3->field_4C != 128 ? 7424 : 4096;
        v5 = v1->stats;
        if (v5->is_infantry)
            v6 = entity_40F0A0_get_dx(v1, v1->_A4_idx_in_tile);
        else
            v6 = v5->field_4C != 128 ? 7424 : 4096;
        v7 = map_place_entity(v1, v6 + (v1->sprite->x & 0xFFFFE000), v4 + (v1->sprite->y & 0xFFFFE000), 0);
        if (v7 == 5)
        {
            entity_mode_419760_infantry_destroyed(v1);
        }
        else
        {
            v8 = v1->stats;
            if (v8->is_infantry)
                v9 = entity_40F0A0_get_dx(v1, v1->_A4_idx_in_tile);
            else
                v9 = v8->field_4C != 128 ? 7424 : 4096;
            v10 = v9 + (v1->sprite->x & 0xFFFFE000);
            v11 = v1->stats;
            v1->sprite_x = v10;
            if (v11->is_infantry)
                v12 = entity_40F100_get_dy(v1, v1->_A4_idx_in_tile);
            else
                v12 = v11->field_4C != 128 ? 7424 : 4096;
            v13 = v1->sprite;
            v14 = v13->y;
            v1->_DC_order = ENTITY_ORDER_MOVE;
            v1->_A4_idx_in_tile = v7;
            v15 = v12 + (v14 & 0xFFFFE000);
            v16 = v1->sprite_x;
            v1->sprite_y = v15;
            v1->sprite_x_2 = v16;
            v1->sprite_y_2 = v15;
            v17 = v1->script;
            v1->sprite_map_x = v13->x >> 13;
            v1->sprite_map_y = v13->y >> 13;
            v17->event_handler = EventHandler_OilTanker;
            v1->mode = entity_mode_4444D0_oiltanker;
        }
    }
    else if (entity_413860_boxd(v1))
    {
        v19 = v1->stats;
        if (v19->is_infantry)
            v20 = entity_40F0A0_get_dx(v1, v1->_A4_idx_in_tile);
        else
            v20 = v19->field_4C != 128 ? 7424 : 4096;
        v21 = v20 + (v1->sprite_map_x << 13);
        v22 = v1->stats;
        v1->sprite_x = v21;
        if (v22->is_infantry)
            v23 = entity_40F100_get_dy(v1, v1->_A4_idx_in_tile);
        else
            v23 = v22->field_4C != 128 ? 7424 : 4096;
        v24 = v1->sprite_x;
        v25 = (v1->sprite_map_y << 13) + v23;
        v26 = v1->script;
        v1->sprite_y = v25;
        v1->_DC_order = ENTITY_ORDER_MOVE;
        v1->sprite_x_2 = v24;
        v1->sprite_y_2 = v25;
        v1->_134_param__unitstats_after_mobile_outpost_plant = 0;
        v1->_98_465610_accuracy_dmg_bonus_idx = 0;
        v1->_12C_prison_bunker_spawn_type = 0;
        v26->event_handler = EventHandler_General_Scout;
        v1->mode_return = entity_mode_4448C0_oiltanker;
        entity_4172D0(v1);
    }
    else
    {
        script_trigger_event(v1->script, EVT_SHOW_UI_CONTROL, 0, task_mobd17_cursor);
        script_trigger_event_group(0, EVT_SHOW_UI_CONTROL, v1, SCRIPT_TYPE_39030);
        v1->script->script_type = SCRIPT_TYPE_INVALID;
        v18 = v1->sprite;
        v1->entity_id = 0;
        v18->x_speed = 0;
        v1->sprite->y_speed = 0;
        sprite_list_remove(v1->sprite);
        entityRepo->Delete(v1);
        script_terminate(v1->script);
    }
}

//----- (004444D0) --------------------------------------------------------
void entity_mode_4444D0_oiltanker(Entity *a1)
{
    a1->mode = entity_mode_4448C0_oiltanker;
    script_sleep(a1->script, 5);
}

//----- (004444F0) --------------------------------------------------------
void entity_mode_4444F0_oiltanker(Entity *a1)
{
    Entity *v1; // edi@1
    EntityOilTankerState *v2; // esi@1
    Entity *v3; // eax@2
    Entity *v4; // eax@5
    int v5; // ecx@5

    v1 = a1;
    v2 = (EntityOilTankerState *)a1->state;
    if (!v2->drillrig)
    {
        v2->array_20_size = 0;
        v2->array_20[0] = 0;
        script_trigger_event_group(a1->script, EVT_MSG_BUILDING_COMPLETE, 0, SCRIPT_DRILLRIG_HANDLER);
        v3 = entity_444BE0_oiltanker_get_state_entity(v1);
        v2->drillrig = v3;
        if (v3)
        {
            v2->drillrig_entity_id = v3->entity_id;
        }
        else
        {
            v1->sprite->x_speed = 0;
            v1->sprite->y_speed = 0;
        }
    }
    v4 = v2->drillrig;
    v5 = v2->drillrig_entity_id;
    v2->_4_entity = v4;
    v2->_18_entity_id = v5;
    if (v4)
    {
        entity_mode_4448C0_oiltanker(v1);
    }
    else
    {
        entity_load_idle_mobd(v1);
        script_sleep(v1->script, 20);
    }
}

//----- (00444590) --------------------------------------------------------
void entity_mode_444590_oiltanker(Entity *a1)
{
    Entity *v1; // edi@1
    EntityOilTankerState *v2; // esi@1
    Entity *v3; // eax@2
    Entity *v4; // eax@5
    int v5; // ecx@5

    v1 = a1;
    v2 = (EntityOilTankerState *)a1->state;
    if (!v2->powerstation)
    {
        v2->array_20_size = 0;
        v2->array_20[0] = 0;
        script_trigger_event_group(a1->script, EVT_MSG_BUILDING_COMPLETE, 0, SCRIPT_POWER_STATION_HANDLER);
        v3 = entity_444BE0_oiltanker_get_state_entity(v1);
        v2->powerstation = v3;
        if (v3)
        {
            v2->powerstation_entity_id = v3->entity_id;
        }
        else
        {
            v1->sprite->x_speed = 0;
            v1->sprite->y_speed = 0;
        }
    }
    v4 = v2->powerstation;
    v5 = v2->powerstation_entity_id;
    v2->_4_entity = v4;
    v2->_18_entity_id = v5;
    if (v4)
    {
        entity_mode_4447C0_oiltanker(v1);
    }
    else
    {
        entity_load_idle_mobd(v1);
        script_sleep(v1->script, 20);
    }
}

//----- (00444630) --------------------------------------------------------
void entity_mode_444630_oiltanker(Entity *a1)
{
    Entity *v1; // esi@1
    int *v2; // edi@1

    v1 = a1;
    v2 = &a1->current_mobd_lookup_idx;
    a1->sprite->x_speed = 0;
    a1->sprite->y_speed = 0;
    entity_load_idle_mobd(a1);
    if (!entity_advance_mobd_rotation(v2, 160, v1->stats->turning_speed))
        v1->mode = entity_mode_4446B0_oiltanker_load_oil;
    script_sleep(v1->script, 1);
}

//----- (004446A0) --------------------------------------------------------
void entity_mode_4446A0_oiltanker(Entity *a1)
{
    dword_477358 = 901223;
}
// 477358: using guessed type int dword_477358;

//----- (004446B0) --------------------------------------------------------
void entity_mode_4446B0_oiltanker_load_oil(Entity *a1)
{
    Entity *v1; // esi@1
    EntityOilTankerState *v2; // edi@1
    EntityBuildingState *v3; // ebx@3
    OilDeposit *v4; // ebp@3
    Entity *v5; // eax@5
    int v6; // eax@11

    v1 = a1;
    entity_40DF50_boxd_update_map_tile(a1, 0);
    v2 = (EntityOilTankerState *)v1->state;
    if (v2->_0_oil_loaded < 500)
    {
        v3 = 0;
        v4 = 0;
        if (dword_470510[v1->player_side] == 1)
        {
            ++v2->_0_oil_loaded;
        LABEL_22:
            entity_4107B0_oiltanker_oil_bar(v1);
            goto LABEL_23;
        }
        v5 = v2->drillrig;
        if (v5)
            v3 = (EntityBuildingState *)v5->state;
        if (v3)
            v4 = (OilDeposit *)v3->oilspot_for_drillrig__task_for_researchlab;
        if (v4)
        {
            if (oilspot_subtract_oil(v4, 1))
            {
                ++v2->_0_oil_loaded;
                v6 = v4->oil_left;
                if ((v6 == 5000 || v6 <= 2500 && !(v6 % 500)) && v1->player_side == player_side)
                {
                    if (!is_player_faction_evolved())
                    {
                        sound_play(SOUND_SURV_LOW_OIL_WARNING, 0, _4690A8_unit_sounds_volume, 16, 0);
                        v1->mode = entity_mode_4446B0_oiltanker_load_oil;
                        goto LABEL_22;
                    }
                    sound_play(SOUND_MUTE_LOW_OIL_WARNING, 0, _4690A8_unit_sounds_volume, 16, 0);
                }
                v1->mode = entity_mode_4446B0_oiltanker_load_oil;
                goto LABEL_22;
            }
            if (v3)
                v3->oilspot_for_drillrig__task_for_researchlab = 0;
        }
        v1->mode = entity_mode_4446A0_oiltanker;
        goto LABEL_22;
    }
    v1->mode = entity_mode_4447C0_oiltanker;
LABEL_23:
    script_sleep(v1->script, 1);
}
// 470510: using guessed type int dword_470510[];

//----- (004447C0) --------------------------------------------------------
void entity_mode_4447C0_oiltanker(Entity *a1)
{
    Entity *v1; // esi@1
    EntityOilTankerState *v2; // edi@1
    Entity *v3; // eax@1
    int v4; // eax@3
    EntityOilTankerState *v5; // ebx@6
    Entity *v6; // eax@6
    Entity *v7; // eax@9
    int v8; // edx@9
    int v9; // edx@11
    int v10; // ecx@11
    int v11; // edx@11
    int v12; // ecx@14

    v1 = a1;
    v2 = (EntityOilTankerState *)a1->state;
    v3 = v2->_4_entity;
    if (v3)
    {
        if (v3->entity_id == v2->_18_entity_id)
        {
            v4 = (int)v3->state;
            if (v4)
                *(_DWORD *)(v4 + 24) = 0;
        }
    }
    if (!v2->powerstation)
    {
        v5 = (EntityOilTankerState *)a1->state;
        v5->array_20_size = 0;
        v5->array_20[0] = 0;
        script_trigger_event_group(a1->script, EVT_MSG_BUILDING_COMPLETE, 0, SCRIPT_POWER_STATION_HANDLER);
        v6 = entity_444BE0_oiltanker_get_state_entity(v1);
        v5->powerstation = v6;
        if (v6)
        {
            v5->powerstation_entity_id = v6->entity_id;
        }
        else
        {
            v1->sprite->x_speed = 0;
            v1->sprite->y_speed = 0;
        }
    }
    v7 = v2->powerstation;
    v8 = v2->powerstation_entity_id;
    v2->_4_entity = v7;
    v2->_18_entity_id = v8;
    if (v7)
    {
        v9 = v7->stru60.ptr_14;
        v10 = *(_DWORD *)(v9 + 4);
        v11 = *(_DWORD *)(v9 + 8);
        if (!v10 && !v11)
        {
            v10 = -8192;
            v11 = 0x2000;
        }
        v7->sprite->field_88_unused = 1;
        v1->sprite_x_2 = v10 + v2->_4_entity->sprite->x;
        v12 = v2->_4_entity->sprite->y;
        v1->_DC_order = ENTITY_ORDER_7;
        v1->mode_arrive = entity_mode_4449D0_oiltanker;
        v1->sprite_y_2 = v11 + v12;
        entity_mode_move_attack(v1);
    }
    else
    {
        v1->mode = entity_mode_444590_oiltanker;
    }
}

//----- (004448C0) --------------------------------------------------------
void entity_mode_4448C0_oiltanker(Entity *a1)
{
    Entity *v1; // esi@1
    EntityOilTankerState *v2; // edi@1
    int v3; // ecx@1
    Entity *v4; // eax@1
    int *v5; // eax@2
    EntityOilTankerState *v6; // ebx@7
    Entity *v7; // eax@7
    Entity *v8; // eax@10
    int v9; // edx@10
    int v10; // edx@12
    int v11; // ecx@12
    int v12; // edx@12
    int v13; // ecx@15

    v1 = a1;
    v2 = (EntityOilTankerState *)a1->state;
    v3 = 0;
    v4 = v2->drillrig;
    if (v4)
    {
        v5 = (int *)v4->state;
        if (v5)
            v3 = *v5;
        if (!v3)
            v2->drillrig = 0;
    }
    v1->sprite->x_speed = 0;
    v1->sprite->y_speed = 0;
    v1->sprite->x_speed = 0;
    v1->sprite->y_speed = 0;
    v1->script->event_handler = EventHandler_OilTanker;
    if (!v2->drillrig)
    {
        v6 = (EntityOilTankerState *)v1->state;
        v6->array_20_size = 0;
        v6->array_20[0] = 0;
        script_trigger_event_group(v1->script, EVT_MSG_BUILDING_COMPLETE, 0, SCRIPT_DRILLRIG_HANDLER);
        v7 = entity_444BE0_oiltanker_get_state_entity(v1);
        v6->drillrig = v7;
        if (v7)
        {
            v6->drillrig_entity_id = v7->entity_id;
        }
        else
        {
            v1->sprite->x_speed = 0;
            v1->sprite->y_speed = 0;
        }
    }
    v8 = v2->drillrig;
    v9 = v2->drillrig_entity_id;
    v2->_4_entity = v8;
    v2->_18_entity_id = v9;
    if (v8)
    {
        v10 = v8->stru60.ptr_14;
        v11 = *(_DWORD *)(v10 + 4);
        v12 = *(_DWORD *)(v10 + 8);
        if (!v11 && !v12)
        {
            v11 = -7168;
            v12 = 11520;
        }
        v1->sprite_x_2 = v11 + v8->sprite->x;
        v13 = v2->_4_entity->sprite->y;
        v1->_DC_order = ENTITY_ORDER_7;
        v1->mode_arrive = entity_mode_444630_oiltanker;
        v1->sprite_y_2 = v12 + v13;
        entity_mode_move_attack(v1);
    }
    else
    {
        v1->mode = entity_mode_4444F0_oiltanker;
    }
}

//----- (004449D0) --------------------------------------------------------
void entity_mode_4449D0_oiltanker(Entity *a1)
{
    a1->sprite->x_speed = 0;
    a1->sprite->y_speed = 0;
    entity_load_idle_mobd(a1);

    if (!entity_advance_mobd_rotation(&a1->current_mobd_lookup_idx, 160, a1->stats->turning_speed))
        a1->mode = entity_mode_444A40_oiltanker;
    script_sleep(a1->script, 1);
}

//----- (00444A40) --------------------------------------------------------
void entity_mode_444A40_oiltanker(Entity *a1)
{
    Script *v1; // ST00_4@1

    a1->sprite->x_speed = -(a1->stats->speed * _4731A8_speeds[__47CFC4_mobd_lookup_speeds[a1->current_mobd_lookup_idx + 1]] >> 6);
    a1->sprite->y_speed = -(-entity_get_mobd_speed_y(a1));
    v1 = a1->script;
    a1->mode = entity_mode_444B40_oiltanker_unload_oil;
    script_sleep(v1, 80);
}

//----- (00444AB0) --------------------------------------------------------
void entity_mode_444AB0_oiltanker(Entity *a1)
{
    EntityOilTankerState *v1; // edx@1
    Entity *v2; // eax@1
    int v3; // eax@3
    Script *v4; // ST00_4@5

    v1 = (EntityOilTankerState *)a1->state;
    v2 = v1->_4_entity;
    if (v2)
    {
        if (v2->entity_id == v1->_18_entity_id)
        {
            v3 = (int)v2->state;
            if (v3)
                *(_DWORD *)(v3 + 24) = 0;
        }
    }
    a1->sprite->x_speed = a1->stats->speed * _4731A8_speeds[__47CFC4_mobd_lookup_speeds[a1->current_mobd_lookup_idx + 1]] >> 6;
    a1->sprite->y_speed = -entity_get_mobd_speed_y(a1);
    v4 = a1->script;
    a1->mode = entity_mode_4448C0_oiltanker;
    script_sleep(v4, 80);
}

//----- (00444B40) --------------------------------------------------------
void entity_mode_444B40_oiltanker_unload_oil(Entity *a1)
{
    Entity *v1; // esi@1
    EntityOilTankerState *v2; // edi@1

    v1 = a1;
    v2 = (EntityOilTankerState *)a1->state;
    a1->sprite->x_speed = 0;
    a1->sprite->y_speed = 0;
    entity_40DF50_boxd_update_map_tile(a1, 0);
    if (v2->_0_oil_loaded > 0)
    {
        v1->mode = entity_mode_444B40_oiltanker_unload_oil;
        v2->_0_oil_loaded -= 20;
        if (v1->player_side == player_side)
            sound_play(SOUND_TANKER_OIL_UNLOADING, 0, _4690A8_unit_sounds_volume, 16, 0);
        add_integer((int *)&game_globals_per_player + v1->player_side, 20);
        entity_4107B0_oiltanker_oil_bar(v1);
        script_sleep(v1->script, 20);
    }
    else
    {
        v1->mode = entity_mode_444AB0_oiltanker;
    }
}

//----- (00444BE0) --------------------------------------------------------
Entity *entity_444BE0_oiltanker_get_state_entity(Entity *a1)
{
    EntityOilTankerState *v1; // eax@1
    int v2; // ebp@1
    int v3; // edi@1
    Entity **v4; // eax@2
    Entity *v5; // eax@2
    Sprite *v6; // esi@3
    Sprite *v7; // edx@3
    int v8; // ebx@3
    int v9; // ecx@3
    int v10; // eax@3
    int v11; // ecx@5
    int v12; // edx@5
    int v13; // edx@6
    Entity **v14; // ebp@9
    Sprite *v15; // edx@10
    int v16; // eax@10
    int v17; // eax@11
    int v18; // edx@13
    int v19; // edx@14
    int v20; // eax@16
    Entity *result; // eax@19
    int v22; // [sp+10h] [bp-14h]@8
    Entity **v23; // [sp+14h] [bp-10h]@2
    int v24; // [sp+18h] [bp-Ch]@1
    int v25; // [sp+20h] [bp-4h]@1

    v1 = (EntityOilTankerState *)a1->state;
    v2 = v1->array_20_size;
    v3 = 0;
    v25 = v2;
    v24 = 0;
    if (v2 && (v4 = v1->array_20, v23 = v4, (v5 = *v4) != 0))
    {
        v6 = a1->sprite;
        v7 = v5->sprite;
        v8 = v6->x;
        v9 = v7->x;
        v10 = v6->x - v9;
        if (v10 <= 0)
            v10 = v9 - v8;
        v11 = v6->y;
        v12 = v7->y;
        if (v11 - v12 <= 0)
            v13 = v12 - v11;
        else
            v13 = v11 - v12;
        v22 = v10 + v13;
        if (v2 > 0)
        {
            v14 = v23;
            do
            {
                v15 = (*v14)->sprite;
                v16 = v15->x;
                if (v8 - v16 <= 0)
                    v17 = v16 - v8;
                else
                    v17 = v8 - v16;
                v18 = v15->y;
                if (v11 - v18 <= 0)
                    v19 = v18 - v11;
                else
                    v19 = v11 - v18;
                v20 = v19 + v17;
                if (v20 <= v22)
                {
                    v22 = v20;
                    v24 = v3;
                }
                ++v3;
                ++v14;
            } while (v3 < v25);
        }
        result = v23[v24];
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (00444CC0) --------------------------------------------------------
void entity_mode_444CC0_oiltanker(Entity *a1)
{
    Entity *v1; // esi@1
    EntityOilTankerState *v2; // edi@1
    Entity *v3; // eax@1

    v1 = a1;
    v2 = (EntityOilTankerState *)a1->state;
    v2->array_20_size = 0;
    v2->array_20[0] = 0;
    script_trigger_event_group(a1->script, EVT_MSG_BUILDING_COMPLETE, 0, SCRIPT_POWER_STATION_HANDLER);
    v3 = entity_444BE0_oiltanker_get_state_entity(v1);
    v2->powerstation = v3;
    if (v3)
    {
        v2->powerstation_entity_id = v3->entity_id;
    }
    else
    {
        v1->sprite->x_speed = 0;
        v1->sprite->y_speed = 0;
    }
}

//----- (00444D10) --------------------------------------------------------
void entity_mode_444D10_oiltanker(Entity *a1)
{
    Entity *v1; // esi@1
    EntityOilTankerState *v2; // edi@1
    Entity *v3; // eax@1

    v1 = a1;
    v2 = (EntityOilTankerState *)a1->state;
    v2->array_20_size = 0;
    v2->array_20[0] = 0;
    script_trigger_event_group(a1->script, EVT_MSG_BUILDING_COMPLETE, 0, SCRIPT_DRILLRIG_HANDLER);
    v3 = entity_444BE0_oiltanker_get_state_entity(v1);
    v2->drillrig = v3;
    if (v3)
    {
        v2->drillrig_entity_id = v3->entity_id;
    }
    else
    {
        v1->sprite->x_speed = 0;
        v1->sprite->y_speed = 0;
    }
}

//----- (00444D60) --------------------------------------------------------
void EventHandler_OilTanker(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param)
{
    Entity *v4; // edi@1
    Entity *v5; // esi@3
    void *v6; // eax@3
    Entity *v7; // ecx@8
    int v8; // ecx@10
    int v9; // ecx@13
    int v10; // ecx@15
    int v11; // esi@28
    int v12; // ecx@29
    enum UNIT_ID v13; // eax@30
    _DWORD *v14; // eax@32
    Entity *v15; // ecx@35
    int v16; // ecx@37
    int v17; // eax@39
    Entity *v18; // ecx@45
    int v19; // ecx@47
    int v20; // eax@49
    Script *v21; // [sp-Ch] [bp-18h]@58

    v4 = 0;
    if (sender)
        v4 = (Entity *)sender->param;
    v5 = (Entity *)receiver->param;
    v6 = v5->state;
    if (!v5->destroyed)
    {
        switch (event)
        {
        case EVT_MSG_1511_sidebar_click_category:
            entity_410CB0_event1511(v5);
            break;
        case EVT_SHOW_UI_CONTROL:
            entity_410CD0_eventTextString(v5);
            break;
        case EVT_MSG_SHOW_UNIT_HINT:
            entity_show_hint(v5);
            break;
        case EVT_MSG_1528:
            v7 = (Entity *)*((_DWORD *)v6 + 1);
            if (v7 && v7->entity_id == *((_DWORD *)v6 + 6))
            {
                v8 = (int)v7->state;
                if (v8)
                    *(_DWORD *)(v8 + 24) = 0;
            }
            entity_41A890_evt1528(v5);
            break;

        case EVT_ENTITY_MOVE:
            v9 = *((_DWORD *)v6 + 1);
            if (v9)
            {
                if (*(_DWORD *)(v9 + 304) == *((_DWORD *)v6 + 6))
                {
                    v10 = *(_DWORD *)(v9 + 32);
                    if (v10)
                        *(_DWORD *)(v10 + 24) = 0;
                }
            }
            entity_move(v5, (_47CAF0_task_attachment1_move_task *)param);
            break;

        case EVT_MSG_1507_stru11:
            entity_41A850_evt1507_mess_with_stru11(v5, param);
            break;
        case EVT_MSG_1509_stru11:
            entity_41A980_evt1509_unset_stru11(v5, param);
            break;
        case EVT_MSG_DAMAGE:
            entity_41A610_evt1503(v5, param);
            entity_410640_tanker_status_bar(v5);
            break;
        case EVT_MSG_1497:
            if (player_side == v5->player_side && !v5->_12C_prison_bunker_spawn_type)
            {
                v5->_12C_prison_bunker_spawn_type = 1000;
                if (is_player_faction_evolved())
                    sound_play(SOUND_132, 0, _4690A8_unit_sounds_volume, 16, 0);
                else
                    sound_play(SOUND_60, 0, _4690A8_unit_sounds_volume, 16, 0);
            }
            break;
        case EVT_MSG_COUNT_BUILDINGS_OF_THE_SAME_TYPE:
            if (!v4->destroyed && !entity_402AC0_is_mode_402AB0(v4))
            {
                v11 = (int)v5->state;
                if (v4->entity_id)
                {
                    v12 = *(_DWORD *)(v11 + 28);
                    if (v12 != 20)
                    {
                        if ((v13 = v4->unit_id, v13 != 47) && v13 != 46 || (v14 = (int *)v4->state) != 0 && *v14)
                        {
                            *(_DWORD *)(v11 + 4 * v12 + 32) = (int)v4;
                            ++*(_DWORD *)(v11 + 28);
                        }
                    }
                }
            }
            break;
        case EVT_MSG_1542_tanker_set_drillrig:
            v15 = (Entity *)*((_DWORD *)v6 + 1);
            if (v15)
            {
                if (v15->entity_id == *((_DWORD *)v6 + 6))
                {
                    v16 = (int)v15->state;
                    if (v16)
                        *(_DWORD *)(v16 + 24) = 0;
                }
            }
            v17 = (int)v5->state;
            if (*(_DWORD *)(v17 + 12) == *(_DWORD *)(v17 + 4))
                v5->mode = entity_mode_4448C0_oiltanker;
            *(_DWORD *)(v17 + 12) = (int)param;
            *(_DWORD *)(v17 + 16) = *((_DWORD *)param + 76);
            if (v5->player_side == player_side)
            {
                if (v5->unit_id == UNIT_STATS_MUTE_TANKER)
                    sound_play(SOUND_131, 0, _4690A8_unit_sounds_volume, 16, 0);
                else
                    sound_play(SOUND_49, 0, _4690A8_unit_sounds_volume, 16, 0);
            }
            break;
        case EVT_MSG_1541_tanker_set_base:
            v18 = (Entity *)*((_DWORD *)v6 + 1);
            if (v18)
            {
                if (v18->entity_id == *((_DWORD *)v6 + 6))
                {
                    v19 = (int)v18->state;
                    if (v19)
                        *(_DWORD *)(v19 + 24) = 0;
                }
            }
            v20 = (int)v5->state;
            if (*(_DWORD *)(v20 + 8) == *(_DWORD *)(v20 + 4))
                v5->mode = entity_mode_4447C0_oiltanker;
            *(_DWORD *)(v20 + 8) = (int)param;
            *(_DWORD *)(v20 + 20) = *((_DWORD *)param + 76);
            if (v5->player_side == player_side)
            {
                if (v5->unit_id == UNIT_STATS_MUTE_TANKER)
                    sound_play(SOUND_133, 0, _4690A8_unit_sounds_volume, 16, 0);
                else
                    sound_play(SOUND_43, 0, _4690A8_unit_sounds_volume, 16, 0);
            }
            break;
        case EVT_MSG_1546_repair_at_station:
            entity_41A470(v5, (Entity *)param);
            break;
        case EVT_MSG_1540:
            if (*((Entity **)v6 + 1) == v4)
            {
                if (v5->mode == entity_mode_4446B0_oiltanker_load_oil)
                {
                    v21 = v5->script;
                    goto LABEL_65;
                }
                *((_DWORD *)v6 + 3) = 0;
                v5->mode = entity_mode_4448C0_oiltanker;
            }
            else if (*((Entity **)v6 + 3) == v4)
            {
                *((_DWORD *)v6 + 3) = 0;
            }
            break;
        case EVT_MSG_1539:
            if (*((Entity **)v6 + 1) == v4)
            {
                if (v5->mode == entity_mode_444B40_oiltanker_unload_oil)
                {
                    v21 = v5->script;
                LABEL_65:
                    script_sleep(v21, 1);
                    v5->hitpoints = 0;
                    v5->mode = entity_419560_on_death;
                    v5->destroyed = 1;
                }
                else
                {
                    *((_DWORD *)v6 + 2) = 0;
                    v5->mode = entity_mode_4447C0_oiltanker;
                }
            }
            else if (*((Entity **)v6 + 2) == v4)
            {
                *((_DWORD *)v6 + 2) = 0;
            }
            break;
        default:
            return;
        }
    }
}


//----- (004069F0) --------------------------------------------------------
void UNIT_Handler_MobileDerrick(Script *a1)
{
    Entity *v1; // esi@2
    int v2; // eax@4

    if (!_47C6DC_dont_execute_unit_handlers)
    {
        v1 = (Entity *)a1->param;
        if (!v1)
        {
            v1 = EntityFactory().Create(a1);
            entity_initialize_mobile_derrick(v1);
            entity_set_draw_handlers(v1);
        }
        (v1->mode)(v1);
        v2 = v1->_134_param__unitstats_after_mobile_outpost_plant;
        if (v2)
            v1->_134_param__unitstats_after_mobile_outpost_plant = v2 - 1;
    }
}

//----- (00406A40) --------------------------------------------------------
void entity_initialize_mobile_derrick(Entity *a1)
{
    Entity *v1; // esi@1
    Script *v2; // eax@
    Sprite *v12; // ecx@15
    Script *v22; // edx@24

    v1 = a1;
    v2 = a1->script;
    a1->mode_arrive = entity_mode_406DC0_mobilederrick;
    v2->script_type = SCRIPT_MOBILE_DERRICK_HANDLER;
    if (a1->sprite->cplc_ptr1)
    {
        v1->sprite->x = entity_transform_x(a1, a1->sprite->x);
        v1->sprite->y = entity_transform_y(a1, a1->sprite->y);
        v1->_A4_idx_in_tile = 0;
        auto v11 = map_place_entity(
            v1, entity_transform_x(a1, a1->sprite->x), entity_transform_y(a1, a1->sprite->y), 0
        );
        if (v11 != 5) {
            v12 = v1->sprite;
            v1->sprite_x = v12->x;
            v1->sprite_y = v12->y;
            v1->sprite_x_2 = v1->sprite_x;
            v1->sprite_y_2 = v1->sprite_y;
            v1->_DC_order = ENTITY_ORDER_MOVE;
            v1->_A4_idx_in_tile = v11;
            v1->sprite_map_x = global2map(v12->x);
            v1->sprite_map_y = global2map(v12->y);
            v1->script->event_handler = EventHandler_MobileDerrick;
            entity_mode_415540_infantry_adjust_placement_inside_tile(v1);
        }
        else {
            entity_mode_419760_infantry_destroyed(v1);
        }
    }
    else if (!entity_413860_boxd(a1))
    {
        entity_mode_419760_infantry_destroyed(v1);
    }
    else {
        v22 = v1->script;
        v1->sprite_x = entity_transform_x(a1, map2global(a1->sprite_map_x));
        v1->sprite_y = entity_transform_y(a1, map2global(a1->sprite_map_y));
        v1->_DC_order = ENTITY_ORDER_MOVE;
        v1->sprite_x_2 = v1->sprite_x;
        v1->sprite_y_2 = v1->sprite_y;
        v1->_134_param__unitstats_after_mobile_outpost_plant = 0;
        v1->_98_465610_accuracy_dmg_bonus_idx = 0;
        v22->event_handler = EventHandler_General_Scout;
        v1->mode_return = entity_mode_406CC0_mobilederrick;
        entity_4172D0(v1);
    }
}

//----- (00406CC0) --------------------------------------------------------
void entity_mode_406CC0_mobilederrick(Entity *a1)
{
    a1->script->event_handler = EventHandler_MobileDerrick;
    entity_mode_415540_infantry_adjust_placement_inside_tile(a1);
}

//----- (00406CD0) --------------------------------------------------------
void EventHandler_MobileDerrick(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param)
{
    Entity *v4; // esi@1

    v4 = (Entity *)receiver->param;
    if (!v4->destroyed)
    {
        switch (event)
        {
        case EVT_MSG_1511_sidebar_click_category:
            entity_410CB0_event1511(v4);
            break;
        case EVT_SHOW_UI_CONTROL:
            entity_410CD0_eventTextString(v4);
            break;
        case EVT_MSG_SHOW_UNIT_HINT:
            entity_show_hint(v4);
            break;
        case EVT_ENTITY_MOVE:
            entity_move(v4, (_47CAF0_task_attachment1_move_task *)param);
            break;

        case EVT_MSG_1507_stru11:
            entity_41A850_evt1507_mess_with_stru11(v4, param);
            break;
        case EVT_MSG_1509_stru11:
            entity_41A980_evt1509_unset_stru11(v4, param);
            break;
        case EVT_MSG_DAMAGE:
            entity_41A610_evt1503(v4, param);
            entity_410710_status_bar(v4);
            break;
        case EVT_MSG_1497:
            entity_41A6D0_evt1497(v4, (Entity *)param);
            break;
        default:
            return;
        }
    }
}

//----- (00406DC0) --------------------------------------------------------
void entity_mode_406DC0_mobilederrick(Entity *a1)
{
    Entity *v1; // esi@1
    OilDeposit *v2; // ecx@1
    Sprite *v3; // edi@2
    Sprite *v4; // eax@3

    v1 = a1;
    a1->sprite->field_88_unused = 1;
    v2 = oilspot_list_head;
    if ((OilDeposit **)oilspot_list_head == &oilspot_list_head)
    {
    LABEL_7:
        v2 = 0;
    }
    else
    {
        v3 = v1->sprite;
        while (1)
        {
            v4 = v2->sprite;
            if (!((v3->x ^ v4->x) & 0xFFFFE000) && !((v3->y ^ v4->y) & 0xFFFFE000) && !(v4->drawjob->flags & 0x40000000))
                break;
            v2 = v2->next;
            if ((OilDeposit **)v2 == &oilspot_list_head)
                goto LABEL_7;
        }
    }
    v1->state = v2;
    if (v2)
    {
        v1->sprite->x_speed = 0;
        v1->sprite->y_speed = 0;
        entity_load_idle_mobd(v1);
        if (!entity_advance_mobd_rotation(&v1->current_mobd_lookup_idx, 160, v1->stats->turning_speed))
            v1->mode = entity_mode_plant_mobile_derrick;
        script_yield_any_trigger(v1->script, 1);
    }
    else
    {
        entity_mode_415540_infantry_adjust_placement_inside_tile(v1);
        script_yield_any_trigger(v1->script, 1);
    }
}

//----- (00406EB0) --------------------------------------------------------
void entity_mode_plant_mobile_derrick(Entity *a1)
{
    Entity *v1; // esi@1
    Sprite *v2; // eax@1
    Sprite *v3; // eax@2
    Script *v4; // ST00_4@6
    enum PLAYER_SIDE v5; // [sp-4h] [bp-8h]@1

    v1 = a1;
    a1->script->event_handler = EventHandler_General_Scout;
    entity_40DEC0_boxd(a1, a1->sprite_map_x, a1->sprite_map_y, a1->_A4_idx_in_tile);
    v2 = v1->sprite;
    v5 = v1->player_side;
    if (v1->unit_id == UNIT_STATS_SURV_MOBILE_DERRICK)
        v3 = spawn_unit(UNIT_STATS_SURV_DRILL_RIG, v2->x, v2->y - 4096, v5);
    else
        v3 = spawn_unit(UNIT_STATS_MUTE_DRILL_RIG, v2->x, v2->y, v5);
    if (v3)
        v3->_80_entity__stru29__sprite__initial_hitpoints = (void *)v1->hitpoints;
    v4 = v1->script;
    v1->mode = entity_remove_unit_after_mobile_derrick_outpost_clanhall_plant;
    script_sleep(v4, 5);
}

//----- (00406F40) --------------------------------------------------------
void entity_remove_unit_after_mobile_derrick_outpost_clanhall_plant(Entity *a1)
{
    Entity *v1; // esi@1
    Script *v2; // eax@1
    Sprite *v3; // ecx@1

    v1 = a1;
    v2 = a1->script;
    a1->destroyed = 1;
    v2->flags_24 &= ~SCRIPT_FLAGS_20_10000000;
    script_trigger_event(a1->script, EVT_SHOW_UI_CONTROL, 0, task_mobd17_cursor);
    script_trigger_event_group(v1->script, EVT_SHOW_UI_CONTROL, v1, SCRIPT_TYPE_39030);
    entity_40DEC0_boxd(v1, v1->sprite_map_x, v1->sprite_map_y, v1->_A4_idx_in_tile);
    v1->script->script_type = SCRIPT_TYPE_INVALID;
    v3 = v1->sprite;
    v1->entity_id = 0;
    sprite_list_remove(v3);
    script_terminate(v1->script);
    entityRepo->Delete(v1);
}