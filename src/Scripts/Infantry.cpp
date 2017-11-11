#include "src/kknd.h"
#include "src/Random.h"

#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"

#include "src/Script.h"
#include "src/ScriptEvent.h"
#include "src/Entity.h"
#include "src/Cursor.h"


//----- (00412B60) --------------------------------------------------------
void UNIT_Handler_Vehicle(Script *a1)
{
    UNIT_Handler_Infantry(a1);
}

//----- (00412B70) --------------------------------------------------------
void UNIT_Handler_Infantry(Script *a1)
{
    Entity *v1; // esi@2
    Sprite *v2; // eax@6
    int v3; // ecx@6
    int v4; // eax@8
    Entity *v5; // eax@15
    int v6; // eax@16
    Entity *v7; // eax@18

    if (!_47C6DC_dont_execute_unit_handlers)
    {
        v1 = (Entity *)a1->param;
        if (!v1)
        {
            v1 = entity_list_create(a1);
            entity_init_infantry(v1);
            entity_attach_turret(v1);
            entity_set_draw_handlers(v1);
        }
        if (v1->entity_id == -1)
            sub_40F380_incdec(1);
        (v1->mode)(v1);
        v2 = v1->sprite;
        v3 = v2->x;
        if (v3 < 0 || v3 >= map2global(_4793F8_map_width) || (v4 = v2->y, v4 < 0) || v4 >= map2global(_478AAC_map_height))
        {
            v1->sprite->x = 25600;
            v1->sprite->y = 25600;
            v1->mode = entity_mode_419760_infantry_destroyed;
        }
        if (!(((unsigned __int8)v1->entity_id ^ (unsigned __int8)dword_47953C) & 0x3F))
            entity_414670(v1);
        if (v1->entity_id == -1)
            sub_40F380_incdec(0);
        v5 = v1->_E0_current_attack_target;
        if (v5)
        {
            v6 = v5->entity_id;
            if (v6)
            {
                if (v6 == v1->_E0_current_attack_target_entity_id)
                {
                    v7 = v1->_E0_current_attack_target;
                    v1->_11C__infantry_sprite_y___drillrig_oil_spot = v7->sprite->x;
                    v1->_120__infantry_sprite_x = v7->sprite->y;
                }
            }
        }
    }
}

//----- (00412C70) --------------------------------------------------------
void entity_init_infantry(Entity *a1)
{
    Entity *v1; // esi@1
    int v10; // eax@14
    Sprite *v11; // ecx@15
    Script *v12; // edx@15
    Script *v13; // ecx@16
    Script *v14; // ecx@18
    Sprite *v23; // eax@25
    int v24; // ecx@25
    int v25; // edx@25
    __int16 v26; // ax@25
    UnitStat *v27; // ecx@25

    v1 = a1;
    if (a1->sprite->cplc_ptr1)
    {
        a1->sprite->x = entity_transform_x(a1, a1->sprite->x);
        a1->sprite->y = entity_transform_y(a1, a1->sprite->y);

        a1->field_A4 = 0;

        v10 = entity_40DE80_boxd(v1, entity_transform_x(a1, a1->sprite->x), entity_transform_y(a1, v1->sprite->y), 0);
        if (v10 == 5)
        {
            v1->sprite->x_speed = 0;
            v1->sprite->y_speed = 0;
            entity_load_move_mobd(v1);
            v13 = v1->script;
            v1->mode = entity_mode_4197E0_infantry;
            v1->destroyed = 1;
            script_trigger_event_group(v13, EVT_SHOW_UI_CONTROL, v1, SCRIPT_TYPE_39030);
            entity_40DEC0_boxd(v1, v1->sprite_map_x, v1->sprite_map_y, v1->field_A4);
            v1->script->event_handler = EventHandler_General_Scout;
        }
        else
        {
            v11 = v1->sprite;
            v1->_DC_order = ENTITY_ORDER_MOVE;
            v1->sprite_x = v11->x;
            v1->sprite_y = v11->y;
            v1->sprite_x_2 = v1->sprite_x;
            v1->sprite_y_2 = v1->sprite_y;
            v1->field_A4 = v10;
            v12 = v1->script;
            v1->sprite_map_x = v11->x >> 13;
            v1->sprite_map_y = v11->y >> 13;
            v12->event_handler = EventHandler_Infantry;
            entity_mode_415540_infantry(v1);
        }
    }
    else if (entity_413860_boxd(a1))
    {
        v1->sprite_x = entity_transform_x(v1, v1->sprite_map_x << 13);
        v1->sprite_y = entity_transform_y(v1, v1->sprite_map_y << 13);
        v1->_DC_order = ENTITY_ORDER_MOVE;
        v1->sprite_x_2 = v1->sprite_x;
        v1->sprite_y_2 = v1->sprite_y;
        v1->_134_param__unitstats_after_mobile_outpost_plant = 0;
        v1->_98_465610_accuracy_dmg_bonus_idx = 0;
        v1->script->event_handler = EventHandler_General_Scout;
        v23 = v1->sprite;
        v24 = v1->sprite_y;
        v25 = v1->sprite_x;
        v1->mode_return = entity_mode_415540_infantry;
        v26 = _42D560_get_mobd_lookup_id_rotation(v25 - v23->x, v24 - v23->y);
        v27 = v1->stats;

        entity_load_move_mobd(v1, v26);
        v1->sprite->x_speed = v27->speed * _4731A8_speeds[__47CFC4_mobd_lookup_speeds[v26 + 1]] >> 6;
        v1->sprite->y_speed = -entity_get_mobd_speed_y(v1);
        v1->mode = entity_mode_417360_infantry;
    }
    else
    {
        v1->sprite->x_speed = 0;
        v1->sprite->y_speed = 0;
        entity_load_move_mobd(v1);
        v14 = v1->script;
        v1->mode = entity_mode_4197E0_infantry;
        v1->destroyed = 1;
        script_trigger_event_group(v14, EVT_SHOW_UI_CONTROL, v1, SCRIPT_TYPE_39030);
        entity_40DEC0_boxd(v1, v1->sprite_map_x, v1->sprite_map_y, v1->field_A4);
        v1->script->event_handler = EventHandler_General_Scout;
    }
}

//----- (00413030) --------------------------------------------------------
void entity_attach_turret(Entity *a1)
{
    Entity *v1; // ebx@1
    EntityTurret *v2; // esi@2
    Sprite *v3; // eax@3
    Script *v4; // eax@3
    UnitAttachmentPoint *v5; // ecx@3
    Script *v6; // ecx@3
    int v7; // eax@3

    v1 = a1;
    if (a1->stats->attach)
    {
        v2 = (EntityTurret *)script_create_local_object(a1->script, 56);
        if (v2)
        {
            memset(v2, 0, sizeof(EntityTurret));
            v3 = sprite_create_scripted(
                v1->stats->attach->mobd_id,
                v1->sprite,
                UNIT_AttachHandler_Turret,
                SCRIPT_FUNCTION,
                v1->stru60.ptr_0);
            v2->turret_sprite = v3;
            v3->drawjob->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_44BDC0_entity_turret;
            v2->turret_sprite->drawjob->flags |= 0x10000000u;
            v2->turret_sprite->drawjob->job_details.palette = per_player_sprite_palettes[player_sprite_color_by_player_side[v1->player_side]];
            v4 = v2->turret_sprite->script;
            v2->sprite_task = v4;
            v4->param = v2;
            v2->turret_sprite->param = v2;
            v2->entity = v1;
            v2->mobd_lookup_id = v1->current_mobd_lookup_idx;
            v5 = v1->stats->attach;
            v2->handler = tower_attachment_handler_448980;
            v2->stats_attachment_point = v5;
            v1->turret = v2;
            v6 = v2->sprite_task;
            v7 = v2->stats_attachment_point->volley_size;
            v2->field_18 = 0;
            v2->field_1C = v7;
            v2->field_20 = 0;
            v2->field_2C = 0;
            v2->_C_entity = 0;
            v2->_C_entity_idx = 0;
            v2->field_34 = 0;
            v6->event_handler = MessageHandler_448EC0;
        }
        v1->sprite->drawjob->flags &= 0xBFFFFFFF;
    }
}

//----- (00413120) --------------------------------------------------------
bool entity_413120(Entity *a1, Entity *a2, int entity_id)
{
    Entity *v3; // ebx@1
    Entity *v4; // esi@1
    Sprite *v5; // eax@4
    int v6; // ebp@5
    int v7; // edi@5
    int v8; // eax@6
    bool v9; // zf@6
    bool v10; // sf@6
    UnitStat *v11; // eax@6
    int v12; // ecx@6
    int v13; // eax@8
    int v14; // ebx@10
    int v15; // eax@12
    UnitStat *v16; // eax@15
    int v17; // eax@16
    int v18; // edx@18
    UnitStat *v19; // eax@18
    int v20; // ecx@18
    int v21; // eax@20
    int v22; // ecx@22
    int v23; // eax@24
    unsigned int v24; // eax@27
    Sprite *v25; // edx@28
    int v26; // eax@28
    int v27; // edx@30
    int v28; // ecx@30
    void(*v29)(Entity *); // eax@33
    int v30; // ebp@33
    Sprite *v31; // eax@38
    int v32; // ecx@38
    int v33; // edi@40
    __int16 v34; // ax@40
    int v35; // ecx@40
    int v36; // eax@40
    BOOL result; // eax@46
    Entity *a2a; // [sp+10h] [bp-4h]@1
    int entity_ida; // [sp+18h] [bp+4h]@27

    v3 = a2;
    a2a = a2;
    v4 = a1;
    if (!a2)
        goto LABEL_50;
    if (a2->entity_id != entity_id)
        goto LABEL_50;
    if (a2->destroyed)
        goto LABEL_50;
    v5 = a2->sprite;
    if (!v5)
        goto LABEL_50;
    v6 = v5->x;
    v7 = v5->y;
    if (a1->stats->is_infantry)
    {
        v8 = (a1->sprite->y & 0xFFFFE000) - v7 + entity_40F100_get_dy(a1, a1->field_A4);
        v9 = v8 == 0;
        v10 = v8 < 0;
        v11 = v4->stats;
        v12 = v11->is_infantry;
        if (v10 || v9)
        {
            v15 = v12 ? entity_40F100_get_dy(v4, v4->field_A4) : v11->field_4C != 128 ? 7424 : 4096;
            v14 = v7 - (v4->sprite->y & 0xFFFFE000) - v15;
        }
        else
        {
            v13 = v12 ? entity_40F100_get_dy(v4, v4->field_A4) : v11->field_4C != 128 ? 7424 : 4096;
            v14 = v13 + (v4->sprite->y & 0xFFFFE000) - v7;
        }
        v16 = v4->stats;
        v17 = v16->is_infantry ? entity_40F0A0_get_dx(v4, v4->field_A4) : v16->field_4C != 128 ? 7424 : 4096;
        v18 = v17 + (v4->sprite->x & 0xFFFFE000) - v6;
        v19 = v4->stats;
        v20 = v19->is_infantry;
        if (v18 <= 0)
        {
            v23 = v20 ? entity_40F0A0_get_dx(v4, v4->field_A4) : v19->field_4C != 128 ? 7424 : 4096;
            v22 = v6 - (v4->sprite->x & 0xFFFFE000) - v23;
        }
        else
        {
            v21 = v20 ? entity_40F0A0_get_dx(v4, v4->field_A4) : v19->field_4C != 128 ? 7424 : 4096;
            v22 = v21 + (v4->sprite->x & 0xFFFFE000) - v6;
        }
        v24 = math_42D64D_prolly_vec_length(v22 >> 8, v14 >> 8);
        v3 = a2a;
        entity_ida = v24;
    }
    else
    {
        v25 = a1->sprite;
        v26 = v25->y - v7;
        if (v26 <= 0)
            v26 = v7 - v25->y;
        v27 = v25->x;
        v28 = v27 - v6;
        if (v27 - v6 <= 0)
            v28 = v6 - v27;
        entity_ida = math_42D64D_prolly_vec_length(v28 >> 8, v26 >> 8);
    }
    v29 = v4->mode;
    v30 = v4->stats->firing_range;
    if (v29 != entity_mode_417F50 && v29 != entity_mode_418590 && v29 != entity_mode_415690)
    {
        if (v4->turret)
        {
            v30 >>= 1;
        }
        else
        {
            v31 = v3->sprite;
            v32 = v31->x_speed;
            if (v32 || v31->y_speed)
            {
                v33 = (signed __int16)_42D560_get_mobd_lookup_id_rotation(v32, v31->y_speed);
                v34 = _42D560_get_mobd_lookup_id_rotation(v3->sprite->x - v4->sprite->x, v3->sprite->x - v4->sprite->x);
                v35 = v34;
                v36 = v33 - v34;
                if (v36 <= 0)
                    v36 = v35 - v33;
                if (v36 < 64)
                    v30 = (v4->stats->firing_range >> 2) + (v4->stats->firing_range >> 1);
            }
        }
    }
    if (entity_ida <= v30 && entity_41B510(v4, v3))
        result = 1;
    else
        LABEL_50:
    result = 0;
    return result;
}

//----- (004133D0) --------------------------------------------------------
void entity_4133D0(Entity *a1)
{
    Entity *v1; // esi@1
    Entity *v2; // eax@1
    int v3; // ecx@2
    Entity *v4; // eax@5
    int v5; // ecx@6
    int v6; // ecx@9
    int v15; // edx@18
    int v16; // eax@18
    Script *v17; // ecx@20

    v1 = a1;
    v2 = a1->_E0_current_attack_target;
    a1->entity_8 = 0;
    if (v2 && (v3 = v2->entity_id) != 0 && v3 == v1->_E0_current_attack_target_entity_id && !v2->destroyed
        || (v4 = v1->_E8_entity) != 0 && (v5 = v4->entity_id) != 0 && v5 == v1->_E8_entity_id && !v4->destroyed)
    {
    LABEL_21:
        entity_mode_move_attack(v1);
    }
    else
    {
        v6 = v1->_DC_order;
        v1->_E0_current_attack_target = 0;
        v1->_E4_prev_attack_target = 0;
        v1->_E8_entity = 0;
        switch (v6)
        {
        case 3:
        case 5:
        case 10:
            v1->_DC_order = ENTITY_ORDER_MOVE;

            v1->sprite_x_2 = entity_transform_x(v1, v1->sprite->x);
            v1->sprite_y_2 = entity_transform_y(v1, v1->sprite->y);

            v1->sprite_y = v1->sprite_y_2;
            v1->sprite_x = v1->sprite_x_2;

            v1->mode_return = entity_mode_415540_infantry;
            entity_mode_416A70_oiltanker(v1);
            break;
        case 2:
        case 4:
            entity_4149A0(v1);
            break;
        case 8:
            v15 = v1->sprite_x_2;
            v16 = v1->sprite_y_2;
            v1->_DC_order = ENTITY_ORDER_MOVE;
            v1->sprite_x = v15;
            v1->sprite_y = v16;
            entity_mode_move_attack(v1);
            break;
        default:
            if (v6 < 12)
                goto LABEL_21;

            v1->sprite->x_speed = 0;
            v1->sprite->y_speed = 0;
            entity_load_move_mobd(v1);

            v17 = v1->script;
            v1->mode = entity_mode_4197E0_infantry;
            v1->destroyed = 1;
            script_trigger_event_group(v17, EVT_SHOW_UI_CONTROL, v1, SCRIPT_TYPE_39030);
            entity_40DEC0_boxd(v1, v1->sprite_map_x, v1->sprite_map_y, v1->field_A4);
            v1->script->event_handler = EventHandler_General_Scout;
            break;
        }
    }
}

//----- (004135E0) --------------------------------------------------------
bool entity_4135E0(Entity *a1)
{
    Entity *v1; // esi@1
    Entity *v2; // edx@1
    int v3; // eax@2
    Entity *v4; // eax@9
    BOOL result; // eax@9
    UnitStat *v6; // eax@11
    int v7; // eax@12
    unsigned int v8; // ecx@14
    UnitStat *v9; // eax@14
    int v10; // eax@15
    unsigned int v11; // ecx@17
    int v12; // ecx@17
    enum UNIT_ID v13; // eax@20
    Entity *v14; // edx@32
    int v15; // eax@33
    int v16; // eax@38

    v1 = a1;
    v2 = a1->_E0_current_attack_target;
    if (v2 && (v3 = v2->entity_id) != 0 && v3 == a1->_E0_current_attack_target_entity_id)
    {
        if ((a1->_DC_order == ENTITY_ORDER_ATTACK || a1->_DC_order == ENTITY_ORDER_5 || a1->_DC_order == ENTITY_ORDER_8)
            && entity_413120(a1, v2, a1->_E0_current_attack_target_entity_id)
            && sub_44CE40(v1->player_side, v1->_E0_current_attack_target))
        {
            v4 = v1->_E0_current_attack_target;
            v1->entity_118_entity_id = v1->_E0_current_attack_target_entity_id;
            v1->entity_8 = v4;
            entity_418290(v1);
            return 1;
        }
    LABEL_19:
        if (!v1->stats->attach)
        {
            v13 = v1->unit_id;
            if (v13 != UNIT_STATS_SURV_MOBILE_OUTPOST
                && v13 != UNIT_STATS_MUTE_CLANHALL_WAGON
                && v13 != UNIT_STATS_SURV_MOBILE_DERRICK
                && v13 != UNIT_STATS_MUTE_MOBILE_DERRICK
                && (v13 != UNIT_STATS_SURV_SABOTEUR || v1->_DC_order != ENTITY_ORDER_3)
                && (v13 != UNIT_STATS_MUTE_VANDAL || v1->_DC_order != ENTITY_ORDER_3)
                && (v13 != UNIT_STATS_SURV_TECHNICIAN || v1->_DC_order != ENTITY_ORDER_3)
                && (v13 != UNIT_STATS_MUTE_MEKANIK || v1->_DC_order != ENTITY_ORDER_3))
            {
                v14 = v1->_E4_prev_attack_target;
                if (v14)
                {
                    v15 = v14->entity_id;
                    if (v15)
                    {
                        if (v15 == v1->_E4_prev_attack_target_entity_id
                            && !v1->_134_param__unitstats_after_mobile_outpost_plant
                            && entity_413120(v1, v14, v1->_E4_prev_attack_target_entity_id)
                            && is_enemy(v1->player_side, v1->_E4_prev_attack_target))
                        {
                            v16 = v1->_E4_prev_attack_target_entity_id;
                            v1->entity_8 = v1->_E4_prev_attack_target;
                            v1->entity_118_entity_id = v16;
                            entity_418290(v1);
                            return 1;
                        }
                    }
                }
            }
            v1->_E4_prev_attack_target = 0;
        }
        result = 0;
    }
    else
    {
        switch (a1->_DC_order)
        {
        case ENTITY_ORDER_3:
        case ENTITY_ORDER_5:
        case ENTITY_ORDER_8:
            v6 = a1->stats;
            a1->_E0_current_attack_target = 0;
            a1->_DC_order = ENTITY_ORDER_0;
            if (v6->is_infantry)
                v7 = entity_40F0A0_get_dx(a1, a1->field_A4);
            else
                v7 = v6->field_4C != 128 ? 7424 : 4096;
            v8 = v7 + (v1->sprite->x & 0xFFFFE000);
            v9 = v1->stats;
            v1->sprite_x_2 = v8;
            if (v9->is_infantry)
                v10 = entity_40F100_get_dy(v1, v1->field_A4);
            else
                v10 = v9->field_4C != 128 ? 7424 : 4096;
            v11 = v1->sprite->y & 0xFFFFE000;
            v1->sprite_x = v1->sprite_x_2;
            v12 = v10 + v11;
            v1->mode_return = entity_mode_415540_infantry;
            v1->sprite_y_2 = v12;
            v1->sprite_y = v12;
            entity_mode_416A70_oiltanker(v1);
            result = 1;
            break;
        case ENTITY_ORDER_ATTACK:
            entity_4149A0(a1);
            result = 1;
            break;
        default:
            goto LABEL_19;
        }
    }
    return result;
}

//----- (00413860) --------------------------------------------------------
bool entity_413860_boxd(Entity *a1)
{
    Entity *v1; // esi@1
    int v2; // ebp@1
    int v3; // edx@2
    Sprite *v4; // eax@3
    int v5; // ecx@3
    int v6; // eax@3
    int v7; // ebx@5
    int v8; // ecx@5
    int v9; // edi@5
    int v10; // eax@8
    UnitStat *v11; // eax@9
    int v12; // edi@10
    UnitStat *v13; // eax@12
    int v14; // eax@13
    UnitStat *v16; // eax@21
    int v17; // edi@22
    UnitStat *v18; // eax@24
    int v19; // eax@25
    int v20; // [sp+10h] [bp-Ch]@6
    int v21; // [sp+14h] [bp-8h]@2
    int v22; // [sp+18h] [bp-4h]@5

    v1 = a1;
    v2 = a1->sprite->y >> 13;
    if (v2 >= _478AAC_map_height)
        return entity_413A90_boxd(a1);
    v3 = _4793F8_map_width;
    v21 = v2 << 13;
    while (1)
    {
        v4 = v1->sprite;
        v5 = v4->y >> 13;
        v6 = (v4->x >> 13) - v2 + v5 - 1;
        if (v6 < 0)
            v6 = 0;
        v7 = v6;
        v8 = 2 * (v2 - v5) + 3;
        v9 = v8 + v6;
        v22 = v8 + v6;
        if (v6 < v8 + v6)
            break;
    LABEL_19:
        ++v2;
        v21 += 0x2000;
        if (v2 >= _478AAC_map_height)
            return entity_413A90_boxd(v1);
    }
    v20 = v6 << 13;
    while (v7 >= v3)
    {
    LABEL_18:
        ++v7;
        v20 += 0x2000;
        if (v7 >= v9)
            goto LABEL_19;
    }
    v10 = boxd_40EA50(v1, v7, v2, &_478AA8_boxd_stru0_array[v7 + v3 * v2]);
    v1->stru224.field_50 = 0;
    v1->stru224.field_54 = 1;
    if (v10 != 2)
    {
    LABEL_17:
        v3 = _4793F8_map_width;
        goto LABEL_18;
    }
    v11 = v1->stats;
    if (v11->is_infantry)
        v12 = entity_40F100_get_dy(v1, v1->field_A4);
    else
        v12 = v11->field_4C != 128 ? 7424 : 4096;
    v13 = v1->stats;
    if (v13->is_infantry)
        v14 = entity_40F0A0_get_dx(v1, v1->field_A4);
    else
        v14 = v13->field_4C != 128 ? 7424 : 4096;
    if (!boxd_41C130(v14 + v20, v12 + v21, v1->sprite->x, v1->sprite->y, v1))
    {
        v9 = v22;
        goto LABEL_17;
    }
    v16 = v1->stats;
    v1->stru224.field_54 = 0;
    v1->sprite_map_x = v7;
    v1->sprite_map_y = v2;
    if (v16->is_infantry)
        v17 = entity_40F100_get_dy(v1, v1->field_A4);
    else
        v17 = v16->field_4C != 128 ? 7424 : 4096;
    v18 = v1->stats;
    if (v18->is_infantry)
        v19 = entity_40F0A0_get_dx(v1, v1->field_A4);
    else
        v19 = v18->field_4C != 128 ? 7424 : 4096;
    v1->field_A4 = entity_40DE80_boxd(v1, v19 + (v7 << 13), v17 + (v2 << 13), 0);
    return 1;
}
// 478AAC: using guessed type int _478AAC_map_height;
// 4793F8: using guessed type int _4793F8_map_width;

//----- (00413A90) --------------------------------------------------------
bool entity_413A90_boxd(Entity *a1)
{
    Sprite *v1; // eax@1
    int v2; // ebp@1
    int v3; // edi@1
    int v4; // ebx@1
    DataBoxd_stru0_per_map_unit *v5; // esi@1
    int v6; // ecx@1
    int v7; // eax@12
    int v8; // eax@12
    UnitStat *v10; // eax@18
    int v11; // esi@19
    UnitStat *v12; // eax@21
    int v13; // eax@22
    int v14; // [sp+10h] [bp-10h]@1
    int v15; // [sp+14h] [bp-Ch]@1
    int v16; // [sp+18h] [bp-8h]@2
    Entity *a1a; // [sp+1Ch] [bp-4h]@1

    v1 = a1->sprite;
    a1a = a1;
    v2 = (v1->x >> 13) - 1;
    v3 = (v1->y >> 13) + 1;
    v14 = 0;
    v4 = -1;
    v5 = &_478AA8_boxd_stru0_array[v2 + _4793F8_map_width * v3];
    v6 = 2;
    v15 = 2;
    while (1)
    {
        v16 = 0;
        if (v6 > 0)
            break;
    LABEL_12:
        v7 = v14 + 1;
        v14 = v7;
        v8 = v7 & 1;
        if (v8)
            v4 = -v4;
        if (!v8)
            v15 = ++v6;
        if (v6 >= 80)
            return 0;
    }
    while (boxd_40EA50(a1a, v2, v3, v5) != 2)
    {
        if (v14 & 1)
        {
            v2 += v4;
            if (v4 <= 0)
                --v5;
            else
                ++v5;
        }
        else
        {
            v3 += v4;
            if (v4 <= 0)
                v5 -= _4793F8_map_width;
            else
                v5 += _4793F8_map_width;
        }
        v6 = v15;
        if (++v16 >= v15)
            goto LABEL_12;
    }
    v10 = a1a->stats;
    a1a->sprite_map_x = v2;
    a1a->sprite_map_y = v3;
    if (v10->is_infantry)
        v11 = entity_40F100_get_dy(a1a, a1a->field_A4);
    else
        v11 = v10->field_4C != 128 ? 7424 : 4096;
    v12 = a1a->stats;
    if (v12->is_infantry)
        v13 = entity_40F0A0_get_dx(a1a, a1a->field_A4);
    else
        v13 = v12->field_4C != 128 ? 7424 : 4096;
    a1a->field_A4 = entity_40DE80_boxd(a1a, v13 + (v2 << 13), v11 + (v3 << 13), 0);
    return 1;
}
// 4793F8: using guessed type int _4793F8_map_width;

//----- (00413C10) --------------------------------------------------------
int entity_413C10(Entity *a1)
{
    Entity *v1; // edi@1
    Sprite *v2; // eax@1
    int v3; // ecx@1
    int v4; // eax@1
    int v5; // ebp@1
    int v6; // ebx@1
    int v7; // esi@1
    int result; // eax@1
    char v9; // bl@3
    int v10; // [sp+10h] [bp-Ch]@1
    int v11; // [sp+14h] [bp-8h]@1
    DataBoxd_stru0_per_map_unit *v12; // [sp+18h] [bp-4h]@1

    v1 = a1;
    v2 = a1->sprite;
    v3 = v2->x;
    v4 = v2->y;
    v10 = v4 >> 13;
    v5 = v3 >> 13;
    v11 = (signed __int16)_42D560_get_mobd_lookup_id_rotation(v1->sprite_x - v3, v1->sprite_y - v4);
    v6 = ((unsigned __int8)v1->current_mobd_lookup_idx + 16) & 0xE0;
    v7 = v6 >> 5;
    v12 = &_478AA8_boxd_stru0_array[v5 + _4793F8_map_width * v10];
    result = boxd_40EA50(v1, v5 + _465708_x_offsets[v7], v10 + _465728_y_offsets[v7], &v12[_478BE8_map_info__see40E6E0[v7]]);
    if (result != 2)
    {
        if (v11 >= v6)
        {
            if (v11 <= v6)
                goto LABEL_7;
            v7 = ((_BYTE)v7 + 1) & 7;
            v9 = v6 + 32;
        }
        else
        {
            v7 = ((_BYTE)v7 - 1) & 7;
            v9 = v6 - 32;
        }
        v6 = v9 & 0xE0;
    LABEL_7:
        result = boxd_40EA50(
            v1,
            v5 + _465708_x_offsets[v7],
            v10 + _465728_y_offsets[v7],
            &v12[_478BE8_map_info__see40E6E0[v7]]);
        if (result != 2)
            return result;
    }
    v1->current_mobd_lookup_idx = v6;
    return result;
}
// 4793F8: using guessed type int _4793F8_map_width;

//----- (00413D10) --------------------------------------------------------
bool entity_initialize_order(Entity *a1)
{
    Entity *v1; // esi@1
    Entity *v2; // ecx@2
    int v3; // eax@2
    int v4; // edi@2
    int v5; // edx@3
    Sprite *v6; // ebx@6
    int v7; // eax@7
    int v8; // ebx@10
    int v9; // eax@10
    BOOL result; // eax@13
    int v11; // eax@14
    int v12; // ecx@14
    Sprite *v13; // edx@14
    int v14; // eax@18
    int v15; // ecx@18
    Sprite *v16; // ebx@18
    int v17; // eax@19
    int v18; // ebx@22
    int v19; // eax@22
    Sprite *v20; // ebx@26
    int v21; // edx@26
    int v22; // ebp@26
    int v23; // edi@26
    int v24; // eax@26
    int v25; // ecx@26
    int v26; // edi@26
    int v27; // edx@26
    int v28; // eax@31
    int v29; // ecx@31
    Sprite *v30; // edx@31
    _DWORD *v31; // eax@36
    int v32; // ecx@36
    int v33; // eax@38
    int v34; // ecx@38
    Sprite *v35; // ebx@38
    int v36; // eax@39
    int v37; // ebx@42
    int v38; // eax@42
    void(*v39)(Entity *); // eax@45
    UnitStat *v40; // eax@47
    int v41; // eax@48
    unsigned int v42; // ecx@50
    UnitStat *v43; // eax@50
    int v44; // eax@51
    int v45; // ecx@53
    unsigned int v46; // ecx@53
    Entity *v47; // edx@54
    int v48; // eax@55
    int v49; // ecx@57
    UnitAttachmentPoint *v50; // eax@57
    Sprite *v51; // eax@64
    int v52; // ecx@64
    int v53; // eax@64
    int v54; // ecx@64
    char *v55; // edi@64
    int v56; // ebx@65
    Entity *v57; // ebp@66
    int v58; // ebx@67
    Sprite *v59; // eax@67
    int v60; // edi@67
    int v61; // ebp@67
    int v62; // ecx@67
    DataBoxd_stru0_per_map_unit *v63; // ebp@67
    int v64; // edi@71
    int v65; // ebx@71
    int v66; // ecx@72
    int v67; // eax@75
    Entity *v68; // eax@80
    int v69; // ecx@81
    Entity *v70; // eax@84
    int v71; // eax@85
    int v72; // ebx@87
    Sprite *v73; // edi@87
    int v74; // ecx@87
    int v75; // eax@87
    int v76; // ebp@88
    int v77; // eax@90
    int v78; // edi@90
    int v79; // eax@90
    int v80; // eax@91
    Entity *v81; // eax@95
    int v82; // ecx@96
    int v83; // edx@96
    int v84; // ecx@98
    Entity *v85; // eax@101
    int v86; // eax@102
    Sprite *v87; // edi@106
    Sprite *v88; // edx@106
    int v89; // ecx@106
    int v90; // ebp@106
    int v91; // eax@106
    int v92; // ebx@108
    int v93; // edx@108
    int v94; // edx@109
    Entity *v95; // eax@113
    int v96; // [sp+10h] [bp-4h]@67

    v1 = a1;
    switch (a1->_DC_order)
    {
    case ENTITY_ORDER_10:
        v2 = a1->_E0_current_attack_target;
        v3 = v1->sprite_x_2;
        v4 = v1->sprite_y_2;
        v1->sprite_x = v3;
        v1->sprite_y = v4;
        if (!v2)
            goto LABEL_25;
        v5 = v2->entity_id;
        if (!v5 || v5 != v1->_E0_current_attack_target_entity_id || *((_DWORD *)v2->state + 2))
            goto LABEL_25;
        v6 = v1->sprite;
        if (v6->x - v3 <= 0)
            v7 = v3 - v6->x;
        else
            v7 = v6->x - v3;
        if (v7 >= 4096)
            goto LABEL_35;
        v8 = v6->y;
        v9 = v8 - v4;
        if (v8 - v4 <= 0)
            v9 = v4 - v8;
        if (v9 >= 7936)
            goto LABEL_35;
        result = 1;
        v1->mode = v1->mode_arrive;
        return result;

    case ENTITY_ORDER_MOVE:
        v11 = a1->sprite_x_2;
        v12 = a1->sprite_y_2;
        v13 = v1->sprite;
        v1->sprite_x = v11;
        v1->sprite_y = v12;
        //if ((v11 ^ v13->x) & 0xFFFFE000 || (v12 ^ v13->y) & 0xFFFFE000)
        if (map_is_different_tile(v11, v13->x) || map_is_different_tile(v12, v13->y))
        {
            entity_414440_boxd(v1, &v1->sprite_x, &v1->sprite_y);
            return 0;
        }
        else if (v1->script->script_type != SCRIPT_MOBILE_DERRICK_HANDLER)
        {
            v1->mode_return = entity_mode_415540_infantry;
            entity_mode_416A70_oiltanker(v1);
            return 1;
        }
        else
        {
            v1->mode = v1->mode_arrive;
            return 1;
        }

    case ENTITY_ORDER_11:
        v14 = a1->sprite_x_2;
        v15 = a1->sprite_y_2;
        v16 = v1->sprite;
        v1->sprite_x = v14;
        v1->sprite_y = v15;
        if (v16->x - v14 <= 0)
            v17 = v14 - v16->x;
        else
            v17 = v16->x - v14;
        if (v17 >= 0x10000)
            goto LABEL_35;
        v18 = v16->y;
        v19 = v18 - v15;
        if (v18 - v15 <= 0)
            v19 = v15 - v18;
        if (v19 >= 0x10000)
            goto LABEL_35;
        goto LABEL_25;

    case ENTITY_ORDER_6_tanker:
        v20 = a1->sprite;
        v21 = a1->sprite_y_2;
        v22 = v20->y;
        v23 = v20->x;
        v24 = a1->sprite_x_2 >> 13;
        v25 = (v23 - 25600) >> 13;
        v1->sprite_x = v1->sprite_x_2;
        v26 = (v23 + 25600) >> 13;
        v27 = v21 >> 13;
        v1->sprite_y = v1->sprite_y_2;
        if (v24 <= v25 || v24 >= v26 || v27 <= (v22 - 25600) >> 13 || v27 >= (v22 + 25600) >> 13)
            goto LABEL_35;
        entity_4054D0_tanker_convoy(v1);
        return 1;

    case ENTITY_ORDER_9:
        v28 = a1->sprite_x_2;
        v29 = a1->sprite_y_2;
        v30 = v1->sprite;
        v1->sprite_x = v28;
        v1->sprite_y = v29;
        if ((v28 ^ v30->x) & 0xFFFFE000 || (v29 ^ v30->y) & 0xFFFFE000)
            goto LABEL_35;
        v1->mode_return = entity_mode_415540_infantry;
        entity_mode_416A70_oiltanker(v1);
        _424CA0_script_47A3CC_evttrigger();
        goto LABEL_34;

    case ENTITY_ORDER_7:
        v31 = (int *)a1->state;
        v32 = v31[1];
        if (!v32 || *(_DWORD *)(v32 + 304) != v31[6])
        {
            v40 = v1->stats;
            if (v40->is_infantry)
                v41 = entity_40F0A0_get_dx(v1, v1->field_A4);
            else
                v41 = v40->field_4C != 128 ? 7424 : 4096;
            v42 = v41 + (v1->sprite->x & 0xFFFFE000);
            v43 = v1->stats;
            v1->sprite_x = v42;
            if (v43->is_infantry)
                v44 = entity_40F100_get_dy(v1, v1->field_A4);
            else
                v44 = v43->field_4C != 128 ? 7424 : 4096;
            v45 = v1->sprite->y;
            v1->mode = entity_mode_416A70_oiltanker;
            v46 = v44 + (v45 & 0xFFFFE000);
            result = 1;
            v1->sprite_y = v46;
            return result;
        }
        v33 = v1->sprite_x_2;
        v34 = v1->sprite_y_2;
        v35 = v1->sprite;
        v1->sprite_x = v33;
        v1->sprite_y = v34;
        if (v35->x - v33 <= 0)
            v36 = v33 - v35->x;
        else
            v36 = v35->x - v33;
        if (v36 >= 768)
            goto LABEL_35;
        v37 = v35->y;
        v38 = v37 - v34;
        if (v37 - v34 <= 0)
            v38 = v34 - v37;
        if (v38 >= 768)
            goto LABEL_35;
        v39 = v1->mode_arrive;
        if (v39)
        {
            v1->mode = v39;
            result = 1;
        }
        else
        {
        LABEL_34:
            result = 1;
        }
        return result;

    case ENTITY_ORDER_3:
        v47 = a1->_E0_current_attack_target;
        if (!v47)
            goto LABEL_25;
        v48 = v47->entity_id;
        if (!v48 || v48 != a1->_E0_current_attack_target_entity_id)
            goto LABEL_25;
        v49 = 0;
        v50 = v47->stats->attach;
        if (v50 && v50->dmg_source)
            v49 = 1;
        if (!v49
            && *((_WORD *)v47->state + 7) >= 5
            && v1->player_side == v47->player_side
            && v1->mode_arrive == entity_mode_418D20)
        {
            goto LABEL_25;
        }
        v51 = v47->sprite;
        v52 = v51->x;
        v53 = v51->y >> 13;
        v54 = v52 >> 13;
        v55 = (char *)& _478AA8_boxd_stru0_array[v54]._4_entities[6 * _4793F8_map_width * v53];
        if (*(Entity **)v55 == v47)
        {
            v56 = 24 * _4793F8_map_width;
            do
            {
                v57 = *(Entity **)&v55[v56];
                v55 += v56;
                ++v53;
            } while (v57 == v47);
        }
        v58 = (v53 << 13) + 4096;
        v59 = v1->sprite;
        v60 = (v54 << 13) + 4096;
        v1->sprite_y = v58;
        v1->sprite_x = v60;
        v61 = v59->y >> 13;
        v62 = v59->x >> 13;
        v96 = v61;
        v63 = &_478AA8_boxd_stru0_array[v62 + v61 * _4793F8_map_width];
        if (v63[_478BE8_map_info__see40E6E0[0]]._4_entities[0] == v47
            || v63[_478BE8_map_info__see40E6E0[1]]._4_entities[0] == v47)
        {
            goto LABEL_79;
        }
        if (v63[_478BE8_map_info__see40E6E0[2]]._4_entities[0] == v47)
        {
            entity_4187F0(v1);
            return 1;
        }
        v64 = v60 >> 13;
        v65 = v58 >> 13;
        if (v64 - v62 <= 0)
            v66 = v62 - v64;
        else
            v66 = v64 - v62;
        if (v66 > 1)
            goto LABEL_35;
        v67 = v65 - v96;
        if (v65 - v96 <= 0)
            v67 = v96 - v65;
        if (v67 > 1 || !_478AA8_boxd_stru0_array[v64]._4_entities[6 * _4793F8_map_width * v65])
            goto LABEL_35;
    LABEL_79:
        entity_4187F0(v1);
        return 1;

    case ENTITY_ORDER_ATTACK:
    case ENTITY_ORDER_4:
        v68 = a1->_E0_current_attack_target;
        if (v68)
        {
            v69 = v68->entity_id;
            if (v69)
            {
                if (v69 == v1->_E0_current_attack_target_entity_id)
                    goto LABEL_100;
            }
        }
        goto LABEL_25;
    case ENTITY_ORDER_8:
        v70 = a1->_E0_current_attack_target;
        if (v70 && (v71 = v70->entity_id) != 0 && v71 == a1->_E0_current_attack_target_entity_id)
        {
            v72 = a1->sprite_x_2;
            v73 = a1->sprite;
            v74 = a1->sprite_x_2 >> 13;
            v75 = v73->x >> 13;
            if ((v1->sprite_x_2 >> 13) - v75 <= 0)
                v76 = v75 - v74;
            else
                v76 = (v1->sprite_x_2 >> 13) - v75;
            v77 = v73->y;
            v78 = v1->sprite_y_2;
            v79 = v77 >> 13;
            if ((v1->sprite_y_2 >> 13) - v79 <= 0)
                v80 = v79 - (v1->sprite_y_2 >> 13);
            else
                v80 = (v1->sprite_y_2 >> 13) - v79;
            if (v76 + v80 <= 5)
            {
                v81 = v1->_E0_current_attack_target;
                v1->sprite_x = v81->sprite->x;
                v1->sprite_y = v81->sprite->y;
            }
            else
            {
                v1->sprite_x = v72;
                v1->sprite_y = v78;
                v1->_E0_current_attack_target = 0;
                v1->_DC_order = ENTITY_ORDER_MOVE;
            }
        }
        else
        {
            v82 = a1->sprite_x_2;
            v83 = v1->sprite_y_2;
            v1->_DC_order = ENTITY_ORDER_MOVE;
            v1->sprite_x = v82;
            v1->sprite_y = v83;
        }
        goto LABEL_35;
    case ENTITY_ORDER_5:
        v68 = a1->_E0_current_attack_target;
        if (v68)
        {
            v84 = v68->entity_id;
            if (v84)
            {
                if (v84 == v1->_E0_current_attack_target_entity_id)
                {
                LABEL_100:
                    v1->sprite_x = v68->sprite->x;
                    v1->sprite_y = v68->sprite->y;
                LABEL_35:
                    entity_414440_boxd(v1, &v1->sprite_x, &v1->sprite_y);
                    return 0;
                }
            }
        }
        v85 = v1->_E8_entity;
        if (!v85 || (v86 = v85->entity_id) == 0 || v86 != v1->_E8_entity_id)
        {
        LABEL_25:
            v1->mode_return = entity_mode_415540_infantry;
            entity_mode_416A70_oiltanker(v1);
            return 1;
        }
        if (entity_414520_boxd(v1))
        {
            result = 1;
        }
        else
        {
            v87 = v1->sprite;
            v88 = v1->_E8_entity->sprite;
            v89 = v87->x;
            v90 = v88->x;
            v91 = v88->x - v89;
            if (v91 <= 0)
                v91 = v89 - v90;
            v92 = v88->y;
            v93 = v87->y;
            if (v92 - v93 <= 0)
                v94 = v93 - v92;
            else
                v94 = v92 - v93;
            if (v91 + v94 >= 0x8000)
            {
                v95 = v1->_E8_entity;
                v1->sprite_x = v90;
                v1->sprite_y = v95->sprite->y;
                goto LABEL_35;
            }
            entity_4158B0(v1);
            result = 1;
        }
        return result;
    default:
        goto LABEL_35;
    }
}
// 4793F8: using guessed type int _4793F8_map_width;

//----- (00414440) --------------------------------------------------------
void entity_414440_boxd(Entity *a1, int *a2, int *a3)
{
    Entity *v3; // ebp@1
    int v4; // esi@2
    int v5; // edi@2
    DataBoxd_stru0_per_map_unit *v6; // ebx@2
    int v7; // edi@5
    int *v8; // [sp+10h] [bp-8h]@1

    v3 = a1;
    v8 = a2;
    if (entity_is_xl_vehicle(a1))
    {
        v4 = *a2 >> 13;
        v5 = *a3 >> 13;
        v6 = &_478AA8_boxd_stru0_array[v4 + _4793F8_map_width * v5];
        if (!boxd_40EA50(a1, v4, v5, &_478AA8_boxd_stru0_array[v4 + _4793F8_map_width * v5]))
        {
            if (boxd_40EA50(v3, v4 - 1, v5, v6 - 1))
            {
                *v8 -= 0x2000;
                return;
            }
            v7 = v5 - 1;
            if (!boxd_40EA50(v3, v4, v7, &v6[-_4793F8_map_width]))
            {
                if (!boxd_40EA50(v3, v4 - 1, v7, &v6[-(_4793F8_map_width + 1)]))
                    return;
                *v8 -= 0x2000;
            }
            *a3 -= 0x2000;
        }
    }
}
// 4793F8: using guessed type int _4793F8_map_width;

//----- (00414520) --------------------------------------------------------
bool entity_414520_boxd(Entity *a1)
{
    Sprite *v1; // eax@1
    int v2; // ecx@1
    int v3; // ebx@1
    int v4; // eax@1
    int v5; // edx@5
    int v6; // ebp@7
    DataBoxd_stru0_per_map_unit *v7; // esi@7
    int v8; // edi@9
    Entity **v9; // esi@9
    Entity *v11; // edi@16
    int v12; // eax@16
    DataBoxd_stru0_per_map_unit *v13; // [sp+10h] [bp-18h]@7
    int v14; // [sp+14h] [bp-14h]@1
    int v15; // [sp+18h] [bp-10h]@5
    Entity *a1a; // [sp+1Ch] [bp-Ch]@1
    int v17; // [sp+24h] [bp-4h]@5

    a1a = a1;
    v1 = a1->sprite;
    v2 = 9;
    v3 = (v1->x >> 13) - 4;
    v4 = (v1->y >> 13) - 4;
    v14 = 9;
    if (v3 < 0)
    {
        v14 = v3 + 9;
        v3 = 0;
    }
    if (v4 < 0)
    {
        v2 = v4 + 9;
        v4 = 0;
    }
    v5 = v4;
    v15 = v4;
    v17 = v4 + v2;
    if (v4 < v4 + v2)
    {
        while (v5 < _478AAC_map_height)
        {
            v6 = v3;
            v7 = &_478AA8_boxd_stru0_array[v3 + _4793F8_map_width * v5];
            v13 = &_478AA8_boxd_stru0_array[v3 + _4793F8_map_width * v5];
            if (v3 < v14 + v3)
            {
                while (2)
                {
                    if (v6 < _4793F8_map_width)
                    {
                        v8 = 0;
                        v9 = v7->_4_entities;
                        do
                        {
                            if (*v9 && is_enemy(a1a->player_side, *v9))
                            {
                                a1a->_DC_order = ENTITY_ORDER_8;
                                v11 = v13->_4_entities[v8];
                                a1a->_E0_current_attack_target = v11;
                                v12 = v11->entity_id;
                                a1a->_134_param__unitstats_after_mobile_outpost_plant = 600;
                                a1a->_E0_current_attack_target_entity_id = v12;
                                a1a->_E4_prev_attack_target = 0;
                                a1a->entity_8 = 0;
                                entity_mode_move_attack(a1a);
                                return 1;
                            }
                            ++v8;
                            ++v9;
                        } while (v8 < 5);
                        ++v6;
                        v7 = v13 + 1;
                        ++v13;
                        if (v6 < v14 + v3)
                            continue;
                    }
                    break;
                }
            }
            v5 = v15++ + 1;
            if (v15 >= v17)
                return 0;
        }
    }
    return 0;
}

//----- (00414670) --------------------------------------------------------
void entity_414670(Entity *a1)
{
    Entity *v1; // edi@1
    int v2; // eax@1
    Entity *v3; // eax@3
    UnitStat *v4; // edx@6
    Sprite *v5; // eax@6
    int v6; // ecx@6
    int v7; // ebx@6
    int v8; // eax@6
    int v9; // edx@6
    int v10; // esi@7
    int v11; // ecx@10
    int v12; // ebp@12
    DataBoxd_stru0_per_map_unit *v13; // esi@12
    int v14; // edi@14
    Entity **v15; // esi@14
    UnitStat *v16; // eax@17
    stru31 *v17; // esi@23
    Entity *v18; // edx@24
    Entity *a1a; // [sp+10h] [bp-18h]@1
    DataBoxd_stru0_per_map_unit *v20; // [sp+14h] [bp-14h]@12
    int v21; // [sp+18h] [bp-10h]@6
    int v22; // [sp+1Ch] [bp-Ch]@10
    int i; // [sp+24h] [bp-4h]@10

    v1 = a1;
    a1a = a1;
    v2 = a1->_134_param__unitstats_after_mobile_outpost_plant;
    if (v2)
        a1->_134_param__unitstats_after_mobile_outpost_plant = v2 - 1;
    v3 = a1->entity_8;
    if ((!v3 || v3->entity_id != a1->entity_118_entity_id) && !entity_413120(a1, a1->_E4_prev_attack_target, a1->_E4_prev_attack_target_entity_id))
    {
        v4 = v1->stats;
        v1->_E4_prev_attack_target = 0;
        v5 = v1->sprite;
        v6 = v4->firing_range >> 5;
        v7 = (v5->x >> 13) - v6;
        v8 = (v5->y >> 13) - v6;
        v21 = 2 * v6 + 1;
        v9 = 2 * v6 + 1;
        if (v7 < 0)
        {
            v10 = v7 + 2 * v6 + 1;
            v7 = 0;
            v21 = v10;
        }
        if (v8 < 0)
        {
            v9 += v8;
            v8 = 0;
        }
        v11 = v8;
        v22 = v8;
        for (i = v8 + v9; v22 < i; v11 = v22++ + 1)
        {
            if (v11 >= _478AAC_map_height)
                break;
            v12 = v7;
            v13 = &_478AA8_boxd_stru0_array[v7 + _4793F8_map_width * v11];
            v20 = &_478AA8_boxd_stru0_array[v7 + _4793F8_map_width * v11];
            if (v7 < v21 + v7)
            {
                while (2)
                {
                    if (v12 < _4793F8_map_width)
                    {
                        v14 = 0;
                        v15 = v13->_4_entities;
                        do
                        {
                            if (*v15)
                            {
                                if (is_enemy(a1a->player_side, *v15))
                                {
                                    v16 = (*v15)->stats;
                                    if (v16->field_54 || v16->speed)
                                    {
                                        if (entity_413120(a1a, *v15, (*v15)->entity_id))
                                        {
                                            a1a->_E4_prev_attack_target = v20->_4_entities[v14];
                                            a1a->_E4_prev_attack_target_entity_id = v20->_4_entities[v14]->entity_id;
                                            return;
                                        }
                                    }
                                }
                            }
                            ++v14;
                            ++v15;
                        } while (v14 < 5);
                        v1 = a1a;
                        ++v12;
                        v13 = v20 + 1;
                        ++v20;
                        if (v12 < v21 + v7)
                            continue;
                    }
                    break;
                }
            }
        }
        v17 = stru31_list_477300;
        if ((stru31 **)stru31_list_477300 != &stru31_list_477300)
        {
            while (1)
            {
                v18 = v17->param__entity__int;
                if (v18)
                {
                    if (is_enemy(v1->player_side, v18)
                        && entity_413120(v1, v17->param__entity__int, v17->param__entity__int->entity_id))
                    {
                        break;
                    }
                }
                v17 = v17->next;
                if ((stru31 **)v17 == &stru31_list_477300)
                    return;
            }
            v1->_E4_prev_attack_target = v17->param__entity__int;
            v1->_E4_prev_attack_target_entity_id = v17->param__entity__int->entity_id;
        }
    }
}

//----- (00414870) --------------------------------------------------------
bool entity_414870_boxd(Entity *a1)
{
    Entity *v1; // esi@1
    int v2; // ebx@1
    Sprite *v3; // edx@1
    int v4; // eax@1
    int v5; // edi@1
    int v6; // ebp@1
    int v7; // ecx@1
    int v8; // edx@1
    int v9; // eax@1
    int v10; // edi@1
    bool v11; // zf@10
    Sprite *v12; // eax@10
    BOOL result; // eax@11
    Sprite *v14; // eax@13
    int v15; // edx@13
    Sprite *v16; // eax@14
    int v17; // edx@15
    Sprite *v18; // eax@17

    v1 = a1;
    v2 = 0x2000;
    v3 = a1->sprite;
    v4 = a1->sprite_x;
    v5 = a1->sprite_y;
    v6 = 0x2000;
    v7 = v3->x;
    v8 = v3->y;
    v9 = (v4 - v7) >> 13;
    v10 = (v5 - v8) >> 13;
    if (v9 < 0)
        v6 = -8192;
    if (v10 < 0)
        v2 = -8192;
    if (v9 <= 0)
        v9 = -v9;
    if (v10 <= 0)
        v10 = -v10;
    if (v9 <= v10)
    {
        v11 = boxd_41C130(v7, v2 + v8, v7, v8, v1) == 0;
        v16 = v1->sprite;
        if (!v11)
        {
            v1->sprite_x = v16->x;
            v17 = v16->y;
            result = 1;
            v1->sprite_y = v2 + v17;
            return result;
        }
        if (boxd_41C130(v6 + v16->x, v16->y, v16->x, v16->y, v1))
        {
            v18 = v1->sprite;
            v1->sprite_x = v6 + v18->x;
            v1->sprite_y = v18->y;
            return 1;
        }
    }
    else
    {
        v11 = boxd_41C130(v6 + v7, v8, v7, v8, v1) == 0;
        v12 = v1->sprite;
        if (!v11)
        {
            v1->sprite_x = v6 + v12->x;
            v1->sprite_y = v12->y;
            return 1;
        }
        if (boxd_41C130(v12->x, v2 + v12->y, v12->x, v12->y, v1))
        {
            v14 = v1->sprite;
            v1->sprite_x = v14->x;
            v15 = v14->y;
            result = 1;
            v1->sprite_y = v2 + v15;
            return result;
        }
    }
    return 0;
}

//----- (004149A0) --------------------------------------------------------
void entity_4149A0(Entity *a1)
{
    Entity *v1; // esi@1
    Sprite *v2; // edx@1
    int v3; // ebx@1
    int v4; // eax@1
    int v5; // eax@2
    int v6; // eax@5
    int v7; // eax@6
    UnitStat *v8; // eax@9
    int v9; // eax@10
    unsigned int v10; // edx@12
    UnitStat *v11; // eax@12
    int v12; // eax@13
    unsigned int v13; // edx@15
    int v14; // eax@16

    v1 = a1;
    v2 = a1->sprite;
    v3 = a1->_11C__infantry_sprite_y___drillrig_oil_spot;
    a1->_E0_current_attack_target = 0;
    v4 = v2->x;
    if (v3 - v4 <= 0)
        v5 = v4 - v3;
    else
        v5 = v3 - v4;
    if (v5 > 0x10000
        || ((v6 = v2->y, a1->_120__infantry_sprite_x - v6 <= 0) ? (v7 = v6 - a1->_120__infantry_sprite_x) : (v7 = a1->_120__infantry_sprite_x - v6),
            v7 > 0x10000))
    {
        v14 = a1->_120__infantry_sprite_x;
        a1->_DC_order = ENTITY_ORDER_11;
        a1->sprite_x_2 = v3;
        a1->sprite_y_2 = v14;
        entity_mode_move_attack(a1);
    }
    else
    {
        v2->x_speed = 0;
        a1->sprite->y_speed = 0;
        v8 = a1->stats;
        a1->_DC_order = ENTITY_ORDER_MOVE;
        if (v8->is_infantry)
            v9 = entity_40F0A0_get_dx(a1, a1->field_A4);
        else
            v9 = v8->field_4C != 128 ? 7424 : 4096;
        v10 = v9 + (v1->sprite->x & 0xFFFFE000);
        v11 = v1->stats;
        v1->sprite_x_2 = v10;
        if (v11->is_infantry)
            v12 = entity_40F100_get_dy(v1, v1->field_A4);
        else
            v12 = v11->field_4C != 128 ? 7424 : 4096;
        v13 = v1->sprite->y & 0xFFFFE000;
        v1->mode_return = entity_mode_415540_infantry;
        v1->sprite_y_2 = v12 + v13;
        entity_mode_416A70_oiltanker(v1);
    }
}

//----- (00414AD0) --------------------------------------------------------
bool entity_414AD0_vehicle_collide_vehicle(Entity *a1)
{
    Entity *v1; // esi@1
    Sprite *v2; // ecx@2
    int v3; // eax@2
    DataBoxd_stru0_per_map_unit *v6; // ebp@2
    int v7; // eax@2
    int v8; // edi@5
    Entity **v9; // ebp@5
    int v10; // edx@7
    int v11; // eax@7
    int v12; // eax@8

    v1 = a1;
    if (a1->stats->field_4C != 128)
        return 0;
    v2 = a1->sprite;
    v3 = v1->current_mobd_lookup_idx >> 4;
    int map_y = global2map(v2->y + _465948_per_mobd_lookup_idx[((_BYTE)v3 - 4) & 0xF]);
    int map_x = global2map(v2->x + _465948_per_mobd_lookup_idx[v3]);
    v6 = &_478AA8_boxd_stru0_array[map_x + _4793F8_map_width * map_y];
    v7 = boxd_40EA50(v1, map_x, map_y, v6);
    if (v7 < 0)
        return 0;
    if (v7 <= 1)
    {
        entity_414E80(v1);
        return 0;
    }
    if (v7 != 3)
        return 0;
    v1->stru224._2C_map_x = map_x;
    v8 = 0;
    v1->stru224._30_map_y = map_y;
    v9 = v6->_4_entities;
    while (1)
    {
        if (*v9)
        {
            v10 = (*v9)->current_mobd_lookup_idx;
            v11 = v1->current_mobd_lookup_idx;
            v12 = abs(v10 - v11);
            if (v12 > 48)
                break;
        }
        ++v8;
        ++v9;
        if (v8 >= 5)
        {
            entity_load_idle_mobd(v1);
            v1->sprite->x_speed = 0;
            v1->sprite->y_speed = 0;
            v1->_128_spawn_param = (void *)60;
            v1->mode = entity_mode_4181B0;
            return 1;
        }
    }

    entity_load_idle_mobd(v1);
    v1->sprite->x_speed = 0;
    v1->sprite->y_speed = 0;
    v1->_128_spawn_param = (void *)60;
    entity_40DF50_boxd_update_map_tile(v1, 0);
    v1->mode = entity_mode_4181B0;
    return 1;
}
// 4793F8: using guessed type int _4793F8_map_width;

//----- (00414C30) --------------------------------------------------------
void entity_414C30_boxd(Entity *a1)
{
    Entity *v1; // esi@1
    __int16 v2; // ax@1
    int v3; // ebx@1
    Sprite *v4; // eax@3
    UnitStat *v5; // eax@5
    int v6; // eax@6
    Sprite *v7; // ecx@6
    int v8; // edx@6
    UnitStat *v9; // eax@9
    Sprite *v10; // eax@15
    UnitStat *v11; // eax@17
    int v12; // eax@18
    int v13; // edx@18
    int v14; // eax@20
    UnitStat *v15; // eax@21

    v1 = a1;
    v2 = _42D560_get_mobd_lookup_id_rotation(a1->sprite_x - a1->sprite->x, a1->sprite_y - a1->sprite->y);
    v3 = v2;
    if (v2 & 0x3F)
    {
        v1->sprite->x_speed = v1->stats->speed * _4731A8_speeds[__47CFC4_mobd_lookup_speeds[v2 + 1]] >> 6;
        v1->sprite->y_speed = 0;
        if (entity_40DA90_update_tile_info(v1) == 4)
        {
            v4 = v1->sprite;
            if (v4->x_speed <= 0)
            {
                if ((int)(v4->x & 0xFFFFE000) > 0)
                {
                    v9 = v1->stats;
                    if (v9->is_infantry)
                        v6 = entity_40F0A0_get_dx(v1, v1->field_A4);
                    else
                        v6 = v9->field_4C != 128 ? 7424 : 4096;
                    v7 = v1->sprite;
                    v8 = v7->x - 4096;
                    goto LABEL_13;
                }
            }
            else if (v4->x >> 13 < _4793F8_map_width - 1)
            {
                v5 = v1->stats;
                if (v5->is_infantry)
                {
                    v6 = entity_40F0A0_get_dx(v1, v1->field_A4);
                    v7 = v1->sprite;
                    v8 = v7->x + 4096;
                }
                else
                {
                    v7 = v1->sprite;
                    v6 = v5->field_4C != 128 ? 7424 : 4096;
                    v8 = v7->x + 4096;
                }
            LABEL_13:
                v1->sprite_x = v6 + (v8 & 0xFFFFE000);
                v1->sprite_y = v7->y;
                v1->mode = entity_mode_416790_vehicle_move;
                return;
            }
        }
        v1->sprite->x_speed = 0;
        v1->sprite->y_speed = -entity_get_mobd_speed_y(v1);
        if (entity_40DA90_update_tile_info(v1) == 4)
        {
            v10 = v1->sprite;
            if (v10->y_speed <= 0)
            {
                v14 = v10->x;
                if ((int)(v14 & 0xFFFFE000) > 0)
                {
                    v1->sprite_x = v14;
                    v15 = v1->stats;
                    if (v15->is_infantry)
                        v12 = entity_40F100_get_dy(v1, v1->field_A4);
                    else
                        v12 = v15->field_4C != 128 ? 7424 : 4096;
                    v13 = v1->sprite->y - 4096;
                    goto LABEL_25;
                }
            }
            else if (v10->y >> 13 < _478AAC_map_height - 1)
            {
                v1->sprite_x = v10->x;
                v11 = v1->stats;
                if (v11->is_infantry)
                {
                    v12 = entity_40F100_get_dy(v1, v1->field_A4);
                    v13 = v1->sprite->y + 4096;
                }
                else
                {
                    v12 = v11->field_4C != 128 ? 7424 : 4096;
                    v13 = v1->sprite->y + 4096;
                }
            LABEL_25:
                v1->mode = entity_mode_416790_vehicle_move;
                v1->sprite_y = v12 + (v13 & 0xFFFFE000);
                return;
            }
        }
    }
    entity_mode_attack_move_4_order_3_7_417E60(v1);
}

//----- (00414E80) --------------------------------------------------------
void entity_414E80(Entity *a1)
{
    Entity *v1; // esi@1
    int v2; // eax@1
    int v3; // eax@3
    int v4; // edi@3
    UnitStat *v5; // ecx@18
    int v6; // ebp@18
    Sprite *v7; // ecx@19
    int v8; // eax@19
    int v9; // edx@19
    int v10; // eax@19
    int v11; // eax@19
    UnitStat *v12; // edx@23
    Sprite *v13; // ecx@24
    int v14; // edx@24
    int v15; // eax@24
    int v16; // eax@24
    UnitStat *v17; // eax@30
    int v18; // eax@31
    int v19; // ecx@33
    UnitStat *v20; // eax@35
    int v21; // eax@36
    int v22; // edx@38
    UnitStat *v23; // eax@39
    int v24; // eax@40
    Sprite *v25; // ecx@40
    int v26; // edx@40
    UnitStat *v27; // eax@42
    int v28; // eax@43
    int v29; // edx@45
    UnitStat *v30; // eax@46

    v1 = a1;
    v2 = (signed __int16)_42D560_get_mobd_lookup_id_rotation(
        a1->sprite_x - a1->sprite->x,
        a1->sprite_y - a1->sprite->y);
    if (!(v2 & 0x3F))
    {
        entity_mode_attack_move_4_order_3_7_417E60(v1);
        return;
    }
    if (v2 > 32)
    {
        if (v2 > 64)
        {
            if (v2 > 96)
            {
                if (v2 > 128)
                {
                    if (v2 > 160)
                    {
                        if (v2 <= 192)
                        {
                            v3 = 192;
                            v4 = 128;
                            goto LABEL_18;
                        }
                        if (v2 <= 224)
                        {
                            v3 = 192;
                            v4 = 0;
                            goto LABEL_18;
                        }
                        v3 = 0;
                    }
                    else
                    {
                        v3 = 128;
                    }
                    v4 = 192;
                    goto LABEL_18;
                }
                v3 = 128;
                v4 = 64;
            }
            else
            {
                v3 = 64;
                v4 = 128;
            }
        }
        else
        {
            v3 = 64;
            v4 = 0;
        }
    }
    else
    {
        v3 = 0;
        v4 = 64;
    }
LABEL_18:
    v5 = v1->stats;
    v6 = v1->current_mobd_lookup_idx;
    v1->current_mobd_lookup_idx = v3;
    if (v5->field_4C == 128)
    {
        v7 = v1->sprite;
        v8 = v3 >> 4;
        v9 = v7->x + _465948_per_mobd_lookup_idx[v8];
        v10 = (v7->y + _465948_per_mobd_lookup_idx[((_BYTE)v8 - 4) & 0xF]) >> 13;
        v11 = boxd_40EA50(v1, v9 >> 13, v10, &_478AA8_boxd_stru0_array[(v9 >> 13) + _4793F8_map_width * v10]);
    }
    else
    {
        v11 = 2;
    }
    if (v11 == 2 || v11 == 3)
    {
        switch (v1->current_mobd_lookup_idx)
        {
        case 0:
            v1->sprite_x = v1->sprite->x;
            v20 = v1->stats;
            if (v20->is_infantry)
                v21 = entity_40F100_get_dy(v1, v1->field_A4);
            else
                v21 = v20->field_4C != 128 ? 7424 : 4096;
            v22 = v1->sprite->y;
            v1->current_mobd_lookup_idx = v6;
            v1->mode = entity_mode_attack_move_2_5_4165C0;
            v1->sprite_y = v21 + ((v22 - 0x2000) & 0xFFFFE000);
            return;
        case 0x40:
        LABEL_39:
            v23 = v1->stats;
            if (v23->is_infantry)
            {
                v24 = entity_40F0A0_get_dx(v1, v1->field_A4);
                v25 = v1->sprite;
                v26 = v25->x + 0x2000;
            }
            else
            {
                v25 = v1->sprite;
                v24 = v23->field_4C != 128 ? 7424 : 4096;
                v26 = v25->x + 0x2000;
            }
            goto LABEL_50;
        case 0x80:
        LABEL_42:
            v27 = v1->stats;
            v1->sprite_x = v1->sprite->x;
            if (v27->is_infantry)
                v28 = entity_40F100_get_dy(v1, v1->field_A4);
            else
                v28 = v27->field_4C != 128 ? 7424 : 4096;
            v29 = v1->sprite->y;
            v1->current_mobd_lookup_idx = v6;
            v1->mode = entity_mode_attack_move_2_5_4165C0;
            v1->sprite_y = v28 + ((v29 + 0x2000) & 0xFFFFE000);
            return;
        case 0xC0:
        LABEL_46:
            v30 = v1->stats;
            if (v30->is_infantry)
                v24 = entity_40F0A0_get_dx(v1, v1->field_A4);
            else
                v24 = v30->field_4C != 128 ? 7424 : 4096;
            v25 = v1->sprite;
            v26 = v25->x - 0x2000;
        LABEL_50:
            v1->sprite_x = v24 + (v26 & 0xFFFFE000);
            v1->sprite_y = v25->y;
            break;
        default:
            break;
        }
    }
    else
    {
        v12 = v1->stats;
        v1->current_mobd_lookup_idx = v4;
        if (v12->field_4C == 128)
        {
            v13 = v1->sprite;
            v14 = v13->x + _465948_per_mobd_lookup_idx[v4 >> 4];
            v15 = v13->y + _465948_per_mobd_lookup_idx[((unsigned __int8)(v4 >> 4) - 4) & 0xF];
            v16 = boxd_40EA50(
                v1,
                v14 >> 13,
                v15 >> 13,
                &_478AA8_boxd_stru0_array[(v14 >> 13) + _4793F8_map_width * (v15 >> 13)]);
        }
        else
        {
            v16 = 2;
        }
        if (v16 != 2 && v16 != 3)
        {
            v1->current_mobd_lookup_idx = v6;
            entity_mode_attack_move_4_order_3_7_417E60(v1);
            return;
        }
        switch (v1->current_mobd_lookup_idx)
        {
        case 0:
            v17 = v1->stats;
            v1->sprite_x = v1->sprite->x;
            if (v17->is_infantry)
                v18 = entity_40F100_get_dy(v1, v1->field_A4);
            else
                v18 = v17->field_4C != 128 ? 7424 : 4096;
            v19 = v1->sprite->y;
            v1->current_mobd_lookup_idx = v6;
            v1->mode = entity_mode_attack_move_2_5_4165C0;
            v1->sprite_y = v18 + ((v19 - 0x2000) & 0xFFFFE000);
            return;
        case 0x40:
            goto LABEL_39;
        case 0x80:
            goto LABEL_42;
        case 0xC0:
            goto LABEL_46;
        default:
            break;
        }
    }
    v1->current_mobd_lookup_idx = v6;
    v1->mode = entity_mode_attack_move_2_5_4165C0;
}
// 4793F8: using guessed type int _4793F8_map_width;

//----- (00415400) --------------------------------------------------------
bool entity_415400_tanker(Entity *a1)
{
    Entity *v1; // esi@1
    enum UNIT_ID v2; // eax@1
    EntityOilTankerState *v3; // ecx@4
    Entity *v4; // eax@4
    Sprite *v5; // edx@7
    Sprite *v6; // edi@7
    int v7; // ecx@7
    int v8; // eax@7
    int v9; // ebx@9
    int v10; // edx@9
    int v11; // edx@10
    BOOL result; // eax@13
    UnitStat *v13; // eax@14
    int v14; // eax@15
    unsigned int v15; // ecx@17
    UnitStat *v16; // eax@17
    int v17; // eax@18
    int v18; // ecx@20
    unsigned int v19; // ecx@20

    v1 = a1;
    v2 = a1->unit_id;
    if (v2 != UNIT_STATS_SURV_TANKER && v2 != UNIT_STATS_MUTE_TANKER || a1->_DC_order != ENTITY_ORDER_7)
        return 0;
    v3 = (EntityOilTankerState *)a1->state;
    v4 = v3->_4_entity;
    if (v4 && v4->entity_id == v3->_18_entity_id)
    {
        if (*((Entity **)v4->state + 6) != v1)
        {
            v5 = v1->sprite;
            v6 = v4->sprite;
            v7 = v6->y;
            v8 = v5->y - v7;
            if (v8 <= 0)
                v8 = v7 - v5->y;
            v9 = v5->x;
            v10 = v6->x;
            v11 = v9 - v10 <= 0 ? v10 - v9 : v9 - v10;
            if ((int)math_42D64D_prolly_vec_length(v11 >> 8, v8 >> 8) < 128)
            {
                entity_4192F0(v1);
                return 1;
            }
        }
        return 0;
    }
    v13 = v1->stats;
    if (v13->is_infantry)
        v14 = entity_40F0A0_get_dx(v1, v1->field_A4);
    else
        v14 = v13->field_4C != 128 ? 7424 : 4096;
    v15 = v14 + (v1->sprite->x & 0xFFFFE000);
    v16 = v1->stats;
    v1->sprite_x = v15;
    if (v16->is_infantry)
        v17 = entity_40F100_get_dy(v1, v1->field_A4);
    else
        v17 = v16->field_4C != 128 ? 7424 : 4096;
    v18 = v1->sprite->y;
    v1->mode = entity_mode_416A70_oiltanker;
    v19 = v17 + (v18 & 0xFFFFE000);
    result = 1;
    v1->sprite_y = v19;
    return result;
}

//----- (00415540) --------------------------------------------------------
void entity_mode_415540_infantry(Entity *a1)
{
    Entity *v1; // esi@1
    UnitStat *v2; // eax@1
    int v3; // eax@2
    unsigned int v4; // edx@4
    UnitStat *v5; // eax@4
    int v6; // eax@5
    Sprite *v7; // ecx@7
    unsigned int v8; // edx@7
    int v9; // eax@7
    Sprite *v10; // ecx@9
    int v12; // ecx@9
    UnitStat *v13; // eax@10
    int v14; // eax@11

    v1 = a1;
    v2 = a1->stats;
    LOWORD_HEXRAYS(a1->field_29C) = 0;
    if (v2->is_infantry)
        v3 = entity_40F0A0_get_dx(a1, a1->field_A4);
    else
        v3 = v2->field_4C != 128 ? 7424 : 4096;
    v4 = v3 + (v1->sprite->x & 0xFFFFE000);
    v5 = v1->stats;
    v1->sprite_x = v4;
    if (v5->is_infantry)
        v6 = entity_40F100_get_dy(v1, v1->field_A4);
    else
        v6 = v5->field_4C != 128 ? 7424 : 4096;
    v7 = v1->sprite;
    v8 = v6 + (v7->y & 0xFFFFE000);
    v9 = v1->sprite_x;
    v1->sprite_y = v8;
    v7->x_speed = v9 - v7->x;
    v1->sprite->y_speed = v1->sprite_y - v1->sprite->y;
    if (entity_40DA90_update_tile_info(v1) == 4)
    {
        v1->sprite->x += v1->sprite->x_speed;
        v1->sprite->y += v1->sprite->y_speed;
    }
    v1->sprite->x_speed = 0;
    v1->sprite->y_speed = 0;
    v10 = v1->sprite;
    v1->sprite_x_2 = v10->x;
    entity_load_idle_mobd(v1);
    v1->sprite_y_2 = v10->y;
    v1->mode = entity_mode_415690;
    entity_40DF50_boxd_update_map_tile(v1, 0);
    v12 = v1->_98_465610_accuracy_dmg_bonus_idx;
    if (v12)
    {
        v13 = v1->stats;
        if (v13->is_infantry)
        {
            v14 = (v13->hitpoints << 8) / _465610_damage_multipliers[v12 + 8];
            v1->_9C_hp_regen_condition = 0;
            v1->_A0_hp_regen_condition = v14;
        }
    }
}

//----- (00415690) --------------------------------------------------------
void entity_mode_415690(Entity *a1)
{
    Entity *v1; // esi@1
    UnitStat *v2; // ecx@1
    int v3; // eax@7
    int v4; // ecx@7
    int v5; // eax@8
    Script *v6; // ST00_4@10
    int v7; // eax@10
    Entity *v8; // eax@17
    int v9; // eax@18

    v1 = a1;
    v2 = a1->stats;
    ++LOWORD_HEXRAYS(v1->field_29C);
    if (v2->is_infantry)
    {
        if (SLOWORD_HEXRAYS(v1->field_29C) > 50)
        {
            int rnd = kknd_rand_3();
            if (!(_BYTE)rnd)
                v1->mode = entity_mode_4157F0;
        }
    }
    if (v1->_98_465610_accuracy_dmg_bonus_idx)
    {
        if (v1->stats->is_infantry)
        {
            v3 = v1->_9C_hp_regen_condition;
            v4 = v3 + v1->_A0_hp_regen_condition;
            v1->_9C_hp_regen_condition = v4;
            if ((v4 ^ v3) & 0xFFFFFF00)
            {
                ++v1->hitpoints;
                entity_410710_status_bar(v1);
                v5 = v1->stats->hitpoints;
                if (v1->hitpoints > v5)
                    v1->hitpoints = v5;
            }
        }
    }
    v6 = v1->script;
    v1->_134_param__unitstats_after_mobile_outpost_plant = 0;
    script_445370_yield_to_main_thread(v6, 0x80000000, 6);
    v7 = v1->entity_id & 0x3F;
    if ((dword_47953C & 0x3F) <= v7 && ((dword_47953C + 6) & 0x3F) > v7 && (entity_414670(v1), entity_4135E0(v1)))
    {
        script_445370_yield_to_main_thread(v1->script, 0x80000000, 1);
    }
    else if (v1->script->script_type != SCRIPT_TANKER_CONVOY_HANDLER || v1->_DC_order != 7)
    {
        v8 = v1->_E8_entity;
        if (v8)
        {
            v9 = v8->entity_id;
            if (v9)
            {
                if (v9 == v1->_E8_entity_id)
                    entity_4158B0(v1);
            }
        }
    }
    else
    {
        entity_mode_attack_move_4_order_3_7_417E60(v1);
    }
}

//----- (004157F0) --------------------------------------------------------
void entity_mode_4157F0(Entity *a1)
{
    Entity *v1; // esi@1
    int v3; // eax@1
    bool v5; // sf@4
    unsigned __int8 v6; // of@4
    int v7; // eax@4
    Script *v11; // ST00_4@7

    v1 = a1;
    v3 = kknd_rand_3() & 0x7F;
    if (v3 >= 70)
    {
        v6 = __OFSUB__(v3, 100);
        v5 = v3 - 100 < 0;
        v7 = a1->current_mobd_lookup_idx;
        if (v5 ^ v6)
        {
            entity_load_idle_mobd(a1, v7 + 32);
        }
        else
        {
            entity_load_idle_mobd(a1, v7 - 32);
        }
    }
    else
    {
        if (a1->stats->mobd_lookup_offset_attack != -1)
        {
            entity_load_attack_mobd(a1);
            v1->sprite->_60_mobd_anim_speed = 0;
        }
    }
    v11 = v1->script;
    v1->mode = entity_mode_415540_infantry;
    script_445370_yield_to_main_thread(v11, 0x80000000, 80);
}

//----- (004158B0) --------------------------------------------------------
void entity_4158B0(Entity *a1)
{
    Entity *v1; // esi@1
    Sprite *v2; // eax@1
    UnitStat *v3; // eax@1
    int v4; // eax@2
    UnitStat *v5; // eax@4
    int v6; // eax@5

    v1 = a1;
    entity_load_idle_mobd(a1);
    v2 = v1->sprite;
    v1->mode = entity_mode_415980;
    v2->x_speed = 0;
    v1->sprite->y_speed = 0;
    v3 = v1->stats;
    if (v3->is_infantry)
        v4 = entity_40F0A0_get_dx(v1, v1->field_A4);
    else
        v4 = v3->field_4C != 128 ? 7424 : 4096;
    v1->sprite->x = v4 + (v1->sprite->x & 0xFFFFE000);
    v5 = v1->stats;
    if (v5->is_infantry)
        v6 = entity_40F100_get_dy(v1, v1->field_A4);
    else
        v6 = v5->field_4C != 128 ? 7424 : 4096;
    v1->sprite->y = v6 + (v1->sprite->y & 0xFFFFE000);
    entity_40DF50_boxd_update_map_tile(v1, 0);
}

//----- (00415980) --------------------------------------------------------
void entity_mode_415980(Entity *a1)
{
    Entity *v1; // edi@1
    Entity *v2; // eax@1
    int v3; // eax@2
    Sprite *v4; // edx@5
    Sprite *v5; // esi@5
    int v6; // eax@5
    int v7; // eax@6
    int v8; // ebx@8
    int v9; // edx@8
    int v10; // esi@8
    int v11; // edx@9

    v1 = a1;
    v2 = a1->_E8_entity;
    if (v2 && (v3 = v2->entity_id) != 0 && v3 == a1->_E8_entity_id)
    {
        if (!entity_414520_boxd(a1))
        {
            v4 = v1->sprite;
            v5 = v1->_E8_entity->sprite;
            v6 = v4->x;
            if (v5->x - v6 <= 0)
                v7 = v6 - v5->x;
            else
                v7 = v5->x - v6;
            v8 = v5->y;
            v9 = v4->y;
            v10 = v5->y - v9;
            if (v10 <= 0)
                v11 = v9 - v8;
            else
                v11 = v10;
            if (v7 + v11 >= 0x8000)
                entity_mode_move_attack(v1);
        }
    }
    else
    {
        a1->_DC_order = ENTITY_ORDER_0;
        a1->mode_return = entity_mode_415540_infantry;
        entity_mode_416A70_oiltanker(a1);
    }
}

//----- (00415A20) --------------------------------------------------------
void entity_415A20(Entity *a1)
{
    entity_load_move_mobd(a1);
    a1->sprite->x_speed = 0;
    a1->sprite->y_speed = 0;
    a1->mode = entity_mode_415A60_vehicle_rotate;
}

//----- (00415A60) --------------------------------------------------------
void entity_mode_415A60_vehicle_rotate(Entity *a1)
{
    if (a1->current_mobd_lookup_idx == a1->_88_dst_orientation)
    {
        a1->mode = a1->mode_turn_return;
    }
    else
    {
        entity_advance_mobd_rotation(&a1->current_mobd_lookup_idx, a1->_88_dst_orientation, a1->stats->turning_speed);
        sprite_4273B0_load_mobd_item_sound(
            a1->sprite,
            a1->stats->mobd_lookup_offset_move,
            _47D3C4_entity_mobd_lookup_ids[a1->current_mobd_lookup_idx + 1]);
    }
}

//----- (00415AB0) --------------------------------------------------------
void entity_mode_move_attack(Entity *a1)
{
    Entity *v1; // esi@1
    enum UNIT_ID v2; // eax@1
    Sprite *v3; // eax@3
    int v4; // eax@7
    int v5; // eax@9
    int v6; // eax@11
    int v12; // eax@19
    int v13; // ecx@22
    int v14; // eax@23
    int v15; // eax@25
    int v16; // eax@26

    v1 = a1;
    v2 = a1->unit_id;
    v3 = a1->sprite;
    if (v2 == UNIT_STATS_SURV_TANKER || v2 == UNIT_STATS_MUTE_TANKER)
    {
        if (global2map(v3->x) != a1->sprite_map_x || global2map(v3->y) != a1->sprite_map_y)
        {
            entity_mode_move_tanker(a1);
            return;
        }
    }

    a1->sprite->x_speed = 0;
    a1->sprite->y_speed = 0;
    entity_40DF50_boxd_update_map_tile(a1, 1);

    if (!entity_initialize_order(v1))
    {
        entity_load_idle_mobd(v1);
        v4 = v1->stru224.field_50;
        if (v4)
            v1->stru224.field_50 = v4 - 1;
        v5 = v1->stru224.field_54;
        if (v5)
            v1->stru224.field_54 = v5 - 1;
        v6 = entity_41B970_boxd(v1, v1->sprite_x, v1->sprite_y);
        v1->stru224.field_4C = v6;

        switch (v6)
        {
            case 2:
            {
                if (v1->stru224._44_map_x || v1->stru224._48_map_y)
                {
                    v1->sprite_x = entity_transform_x(v1, map2global(v1->stru224._44_map_x));
                    v1->sprite_y = entity_transform_y(v1, map2global(v1->stru224._48_map_y));
                }
                entity_mode_attack_move_2_5_4165C0(v1);
            }
            break;

        case 4:
            v12 = v1->_DC_order;
            if (v12 == ENTITY_ORDER_7 || v12 == ENTITY_ORDER_3)
                entity_mode_attack_move_4_order_3_7_417E60(v1);
            else
                entity_mode_attack_move_4_417550(v1);
            return;

        case 3:
            v13 = 0;
            if (v1->stru224._28_indexer > 0)
            {
                v14 = (int)v1->array_1AC;
                do
                {
                    ++v13;
                    *(_DWORD *)v14 = *(_DWORD *)(v14 + 80);
                    *(_DWORD *)(v14 + 40) = *(_DWORD *)(v14 + 120);
                    v14 += 4;
                } while (v13 < v1->stru224._28_indexer);
            }
            v15 = v1->field_124;
            LOBYTE_HEXRAYS(v15) = v15 | 6;
            v1->field_124 = v15;
            entity_mode_attack_move_1_415D30(v1);
            return;

        case 1:
            v16 = v1->field_124;
            LOBYTE_HEXRAYS(v16) = v16 & 0xF9;
            v1->field_124 = v16;
            entity_mode_attack_move_1_415D30(v1);
            return;

        case 5:
            if (v1->stru224._44_map_x || v1->stru224._48_map_y)
            {
                v1->sprite_x = entity_transform_x(v1, map2global(v1->stru224._44_map_x));
                v1->sprite_y = entity_transform_y(v1, map2global(v1->stru224._48_map_y));
                entity_mode_attack_move_2_5_4165C0(v1);
            }
            else
            {
                entity_mode_attack_move_4_order_3_7_417E60(v1);
            }
            break;
        case 0:
            entity_mode_attack_move_2_5_4165C0(v1);
            break;

        default:
            return;
        }
    }
}

//----- (00415D30) --------------------------------------------------------
void entity_mode_attack_move_1_415D30(Entity *a1)
{
    Entity *v1; // esi@1
    int v2; // eax@1
    int v3; // eax@6
    UnitStat *v4; // eax@8
    int v5; // edi@9
    UnitStat *v6; // eax@11
    int v7; // eax@12
    UnitStat *v8; // eax@15
    int v9; // eax@16
    int v10; // edx@18
    UnitStat *v11; // eax@18
    int v12; // eax@19
    char v13; // al@22
    int v14; // edx@22
    int v15; // eax@22
    UnitStat *v16; // eax@28
    int v17; // eax@29
    int v18; // ecx@31
    UnitStat *v19; // eax@31
    int v20; // eax@32

    v1 = a1;
    v2 = a1->stru224._28_indexer - 1;
    a1->stru224._28_indexer = v2;
    if (v2 < 0)
    {
        if (a1->stru224.field_54)
        {
            if (a1->stru224._44_map_x || a1->stru224._48_map_y)
            {
                v16 = a1->stats;
                if (v16->is_infantry)
                    v17 = entity_40F0A0_get_dx(a1, a1->field_A4);
                else
                    v17 = v16->field_4C != 128 ? 7424 : 4096;
                v18 = v17 + (v1->stru224._44_map_x << 13);
                v19 = v1->stats;
                v1->sprite_x = v18;
                if (v19->is_infantry)
                    v20 = entity_40F100_get_dy(v1, v1->field_A4);
                else
                    v20 = v19->field_4C != 128 ? 7424 : 4096;
                v1->sprite_y = v20 + (v1->stru224._48_map_y << 13);
                entity_mode_attack_move_2_5_4165C0(v1);
            }
            else
            {
                entity_mode_attack_move_4_order_3_7_417E60(a1);
            }
        }
        else
        {
            a1->stru224.field_54 = 4;
            entity_mode_attack_move_4_order_3_7_417E60(a1);
        }
    }
    else
    {
        a1->stru224._2C_map_x = a1->array_15C[v2];
        a1->stru224._30_map_y = a1->array_184[v2];
        a1->stru224._34_x = a1->array_15C[v2];
        a1->stru224._38_y = a1->array_184[v2];
        if (a1->stru224._2C_map_x == -1 && a1->stru224._30_map_y == -1)
        {
            if (v2)
                a1->stru224._28_indexer = v2 - 1;
            v3 = a1->stru224._28_indexer;
            a1->stru224._2C_map_x = a1->array_15C[v3];
            a1->stru224._30_map_y = a1->array_184[v3];
            a1->stru224._34_x = a1->array_15C[v3];
            a1->stru224._38_y = a1->array_184[v3];
        }
        if (boxd_40EA50(
            a1,
            a1->stru224._2C_map_x,
            a1->stru224._30_map_y,
            &_478AA8_boxd_stru0_array[a1->stru224._2C_map_x + a1->stru224._30_map_y * _4793F8_map_width]) == 2
            && ((v4 = v1->stats, !v4->is_infantry) ? (v5 = v4->field_4C != 128 ? 7424 : 4096) : (v5 = entity_40F100_get_dy(v1, v1->field_A4)),
            (v6 = v1->stats, !v6->is_infantry) ? (v7 = v6->field_4C != 128 ? 7424 : 4096) : (v7 = entity_40F0A0_get_dx(v1, v1->field_A4)),
                boxd_41C130(
                    v7 + (v1->stru224._2C_map_x << 13),
                    v5 + (v1->stru224._30_map_y << 13),
                    v1->sprite->x,
                    v1->sprite->y,
                    v1)))
        {
            v8 = v1->stats;
            if (v8->is_infantry)
                v9 = entity_40F0A0_get_dx(v1, v1->field_A4);
            else
                v9 = v8->field_4C != 128 ? 7424 : 4096;
            v10 = v9 + (v1->stru224._2C_map_x << 13);
            v11 = v1->stats;
            v1->sprite_x = v10;
            if (v11->is_infantry)
                v12 = entity_40F100_get_dy(v1, v1->field_A4);
            else
                v12 = v11->field_4C != 128 ? 7424 : 4096;
            v1->sprite_y = v12 + (v1->stru224._30_map_y << 13);
            entity_mode_attack_move_2_5_4165C0(v1);
        }
        else
        {
            v13 = ((_42D560_get_mobd_lookup_id_rotation(
                v1->array_1AC[v1->stru224._28_indexer] - v1->array_15C[v1->stru224._28_indexer],
                v1->array_1D4[v1->stru224._28_indexer] - v1->array_184[v1->stru224._28_indexer])
                + 16) >> 5) & 7;
            v1->field_140 = 0;
            v1->mode = entity_mode_416060;
            v14 = (v13 + 2) & 7;
            v1->stru224._40_xy_idx = (v13 - 2) & 7;
            v15 = v1->field_124;
            v1->stru224.field_3C = v14;
            LOBYTE_HEXRAYS(v15) = v15 & 0xDF | 0x18;
            v1->field_124 = v15;
        }
    }
}
// 4793F8: using guessed type int _4793F8_map_width;

//----- (00416060) --------------------------------------------------------
void entity_mode_416060(Entity *a1)
{
    Entity *v1; // esi@1
    int v2; // eax@3
    int *v3; // ebp@3
    int *v4; // ebx@3
    Sprite *v5; // eax@4
    int v6; // eax@6
    UnitStat *v7; // eax@8
    int v8; // edi@9
    UnitStat *v9; // eax@11
    int v10; // eax@12
    int v11; // ecx@16
    int v12; // edx@18
    int v13; // eax@21
    int v14; // eax@23
    int *v15; // ebp@23
    int *v16; // ebx@23
    Sprite *v17; // eax@24
    int v18; // eax@26
    UnitStat *v19; // eax@28
    int v20; // edi@29
    UnitStat *v21; // eax@31
    int v22; // eax@32
    int v23; // ecx@36
    int v24; // edx@38
    int v25; // eax@41
    int v26; // ecx@42
    int v27; // edi@42
    int v28; // eax@44
    int v29; // edx@45
    int v30; // eax@52
    int v31; // eax@55
    UnitStat *v32; // eax@57
    int v33; // eax@58
    int v34; // ecx@60
    UnitStat *v35; // eax@60
    int v36; // eax@61
    int v37; // edx@61
    UnitStat *v38; // eax@64
    int v39; // eax@65
    int v40; // ecx@67
    UnitStat *v41; // eax@67
    int v42; // eax@72
    int out_x; // [sp+10h] [bp-18h]@18
    int out_y; // [sp+14h] [bp-14h]@18
    int a5; // [sp+18h] [bp-10h]@18
    int v46; // [sp+1Ch] [bp-Ch]@1
    int v47; // [sp+20h] [bp-8h]@3
    int v48; // [sp+24h] [bp-4h]@3

    v1 = a1;
    v46 = 0;
    while (1)
    {
        if (v1->field_124 & 8)
        {
            v2 = v1->stru224._2C_map_x;
            v3 = &v1->stru224._30_map_y;
            v4 = &v1->stru224._2C_map_x;
            v48 = v1->stru224._30_map_y;
            v47 = v2;
            if (boxd_44D340(&v1->stru224._2C_map_x, &v1->stru224._30_map_y, 1, v1, &v1->stru224.field_3C))
            {
                v5 = v1->sprite;
                if (*v4 == v5->x >> 13 && *v3 == v5->y >> 13)
                {
                LABEL_63:
                    v1->stru224.field_54 = 0;
                    v1->stru224.field_50 = 2;
                    v1->mode_return = entity_mode_attack_move_4_order_3_7_417E60;
                    entity_mode_416A70_oiltanker(v1);
                    return;
                }
                v6 = boxd_40EA50(v1, *v4, *v3, &_478AA8_boxd_stru0_array[*v4 + *v3 * _4793F8_map_width]);
                if (v6 == 2 || v6 == 3)
                {
                    v7 = v1->stats;
                    v8 = v7->is_infantry ? entity_40F100_get_dy(v1, v1->field_A4) : v7->field_4C != 128 ? 7424 : 4096;
                    v9 = v1->stats;
                    v10 = v9->is_infantry ? entity_40F0A0_get_dx(v1, v1->field_A4) : v9->field_4C != 128 ? 7424 : 4096;
                    if (boxd_41C130(v10 + (*v4 << 13), v8 + (*v3 << 13), v1->sprite->x, v1->sprite->y, v1))
                    {
                        v32 = v1->stats;
                        if (v32->is_infantry)
                            v33 = entity_40F0A0_get_dx(v1, v1->field_A4);
                        else
                            v33 = v32->field_4C != 128 ? 7424 : 4096;
                        v34 = v33 + (v1->stru224._2C_map_x << 13);
                        v35 = v1->stats;
                        v1->sprite_x = v34;
                        if (v35->is_infantry)
                        {
                            v36 = entity_40F100_get_dy(v1, v1->field_A4);
                            v37 = v1->stru224._30_map_y;
                        }
                        else
                        {
                            v37 = v1->stru224._30_map_y;
                            v36 = v35->field_4C != 128 ? 7424 : 4096;
                        }
                        goto LABEL_71;
                    }
                }
                if (v1->field_124 & 0x20)
                {
                    v11 = v1->stru224._34_x;
                    if (*v4 == v11 && *v3 == v1->stru224._38_y)
                    {
                        v12 = v1->stru224._40_xy_idx;
                        out_y = v1->stru224._38_y;
                        out_x = v11;
                        a5 = v12;
                        boxd_44D340(&out_x, &out_y, 0, v1, &a5);
                        if (out_x == v47 && out_y == v48)
                            break;
                    }
                }
            }
            else
            {
                v13 = v1->field_124;
                LOBYTE_HEXRAYS(v13) = v13 & 0xF7;
                v1->field_124 = v13;
            }
        }
        if (v1->field_124 & 0x10)
        {
            v14 = v1->stru224._34_x;
            v15 = &v1->stru224._38_y;
            v16 = &v1->stru224._34_x;
            v47 = v1->stru224._38_y;
            v48 = v14;
            if (boxd_44D340(&v1->stru224._34_x, &v1->stru224._38_y, 0, v1, &v1->stru224._40_xy_idx))
            {
                v17 = v1->sprite;
                if (*v16 == v17->x >> 13 && *v15 == v17->y >> 13)
                    goto LABEL_63;
                v18 = boxd_40EA50(v1, *v16, *v15, &_478AA8_boxd_stru0_array[*v16 + *v15 * _4793F8_map_width]);
                if (v18 == 2 || v18 == 3)
                {
                    v19 = v1->stats;
                    v20 = v19->is_infantry ? entity_40F100_get_dy(v1, v1->field_A4) : v19->field_4C != 128 ? 7424 : 4096;
                    v21 = v1->stats;
                    v22 = v21->is_infantry ? entity_40F0A0_get_dx(v1, v1->field_A4) : v21->field_4C != 128 ? 7424 : 4096;
                    if (boxd_41C130(v22 + (*v16 << 13), v20 + (*v15 << 13), v1->sprite->x, v1->sprite->y, v1))
                    {
                        v38 = v1->stats;
                        if (v38->is_infantry)
                            v39 = entity_40F0A0_get_dx(v1, v1->field_A4);
                        else
                            v39 = v38->field_4C != 128 ? 7424 : 4096;
                        v40 = v39 + (v1->stru224._34_x << 13);
                        v41 = v1->stats;
                        v1->sprite_x = v40;
                        if (v41->is_infantry)
                            v36 = entity_40F100_get_dy(v1, v1->field_A4);
                        else
                            v36 = v41->field_4C != 128 ? 7424 : 4096;
                        v37 = v1->stru224._38_y;
                    LABEL_71:
                        v1->sprite_y = v36 + (v37 << 13);
                        entity_mode_attack_move_2_5_4165C0(v1);
                        return;
                    }
                }
                if (v1->field_124 & 0x20)
                {
                    v23 = v1->stru224._2C_map_x;
                    if (v23 == *v16 && v1->stru224._30_map_y == *v15)
                    {
                        v24 = v1->stru224.field_3C;
                        out_y = v1->stru224._30_map_y;
                        out_x = v23;
                        a5 = v24;
                        boxd_44D340(&out_x, &out_y, 1, v1, &a5);
                        if (out_x == v48 && out_y == v47)
                            break;
                    }
                }
            }
            else
            {
                v25 = v1->field_124;
                LOBYTE_HEXRAYS(v25) = v25 & 0xEF;
                v1->field_124 = v25;
            }
        }
        v26 = v1->stru224._2C_map_x;
        v27 = v1->stru224._34_x;
        if (v26 != v27 || v1->stru224._30_map_y != v1->stru224._38_y)
        {
            v28 = v1->field_124;
            LOBYTE_HEXRAYS(v28) = v28 | 0x20;
            v1->field_124 = v28;
        }
        v29 = v1->field_140;
        if (v29 > 20 && !(v1->field_124 & 0x20))
            break;
        if ((int *)v26 == v1->array_15C && (int *)v1->stru224._30_map_y == v1->array_184)
            v1->field_124 &= 0xFFFFFFF7;
        if ((int *)v27 == v1->array_15C && (int *)v1->stru224._38_y == v1->array_184)
        {
            v30 = v1->field_124;
            LOBYTE_HEXRAYS(v30) = v30 & 0xEF;
            v1->field_124 = v30;
        }
        if (!(v1->field_124 & 0x18) || v29 > 350)
            break;
        v31 = v46 + 1;
        v1->field_140 = v29 + 1;
        v46 = v31;
        if (v31 >= 4)
            return;
    }
    v42 = v1->field_124;
    LOBYTE_HEXRAYS(v42) = v42 & 0xF9;
    v1->field_124 = v42;
    entity_mode_attack_move_1_415D30(v1);
}
// 4793F8: using guessed type int _4793F8_map_width;

//----- (004165C0) --------------------------------------------------------
void entity_mode_attack_move_2_5_4165C0(Entity *a1)
{
    Entity *v1; // esi@1
    Sprite *v2; // eax@1
    int v3; // edx@1
    UnitStat *v4; // ecx@1
    char v7; // al@7

    v1 = a1;
    v2 = a1->sprite;
    a1->mode = entity_mode_416790_vehicle_move;
    a1->field_B8 = v2->x;
    v3 = v2->y;
    a1->field_124 &= 0xFFFFFFFE;
    v4 = a1->stats;
    v1->field_BC = v3;
    if (v4->is_infantry)
    {
        v1->current_mobd_lookup_idx = _42D560_get_mobd_lookup_id_rotation(
            v1->sprite_x - v2->x,
            v1->sprite_y - v2->y);
        entity_413C10(v1);

        entity_load_move_mobd(v1);

        int rnd = kknd_rand_3();
        v1->sprite->_60_mobd_anim_speed -= rnd << 9;
        v1->_C0_mobd_anim_speed_related = v1->sprite->_60_mobd_anim_speed;
    }
    else if (v4->field_4C == 128 || boxd_41C130(v1->sprite_x, v1->sprite_y, v2->x, v2->y, v1))
    {
        entity_load_move_mobd(v1);

        int rnd = kknd_rand_3();
        v1->sprite->_60_mobd_anim_speed -= rnd << 9;
        v1->_C0_mobd_anim_speed_related = v1->sprite->_60_mobd_anim_speed;
        v7 = _42D560_get_mobd_lookup_id_rotation(
            v1->sprite_x - v1->sprite->x,
            v1->sprite_y - v1->sprite->y
        );
        v1->_88_dst_orientation = (v7 + 8) & 0xF0;
        entity_load_move_mobd(v1);

        v1->sprite->x_speed = 0;
        v1->sprite->y_speed = 0;
        v1->mode = entity_mode_415A60_vehicle_rotate;
        v1->mode_turn_return = entity_mode_416790_vehicle_move;
    }
    else if (!entity_414870_boxd(v1))
    {
        entity_mode_attack_move_4_order_3_7_417E60(v1);
    }
}

//----- (00416790) --------------------------------------------------------
void entity_mode_416790_vehicle_move(Entity *a1)
{
    Entity *v1; // esi@1
    Sprite *v13; // edi@21
    int v15; // eax@22
    int v17; // eax@26
    int v18; // eax@31
    int v21; // eax@35
    UnitStat *v22; // eax@35
    int v23; // eax@38
    UnitStat *v25; // eax@44
    Sprite *v26; // eax@44
    int v27; // eax@44
    Sprite *v28; // ecx@49

    v1 = a1;
    a1->sprite->_60_mobd_anim_speed = a1->_C0_mobd_anim_speed_related;

    int distance_x = abs(a1->sprite->x - a1->sprite_x);
    int distance_y = abs(a1->sprite->y - a1->sprite_y);
    if (!a1->stats->is_infantry)
    {
        if (distance_x < 7 * 256 && distance_y < 7 * 256)
        {
            a1->field_124 |= 1; // infantry is in tile, take 1 of 5 positions
        }
    }

    if (distance_x < 3 * 256 && distance_y < 3 * 256)
    {
        entity_mode_move_attack(v1);
        return;
    }

    if (entity_4135E0(a1) || entity_415400_tanker(v1))
    {
        return;
    }


    v13 = v1->sprite;
    v15 = abs(v13->x - v1->field_B8);
    v17 = abs(v13->y - v1->field_BC);
    if (v15 > 256 * 256 || v17 > 256 * 256)
    {
    LABEL_52:
        entity_mode_move_attack(v1);
        return;
    }

    if (v1->stats->is_infantry)
    {
        v18 = entity_40D600_infantry_get_new_movement_orientation(v1, v1->sprite_x, v1->sprite_y, 512);
    }
    else
    {
        v18 = entity_40D6F0_vehicle_get_new_movement_orientation(v1, v1->sprite_x, v1->sprite_y, 512);
    }

    v1->_88_dst_orientation = v18;

    if (v1->field_124 & 1 || // infantry is in the tile, taking 1 of 5 positions
        v18 == -1 || v18 == v1->current_mobd_lookup_idx) // if rotation is uncertain or we are facing right direction - move
    {
    LABEL_37:
        v1->sprite->x_speed = entity_get_mobd_speed_x(v1);
        v1->sprite->y_speed = -entity_get_mobd_speed_y(v1);
        v1->sprite->x_speed += v1->sprite->x_speed < 0 ? 1 : 0;
        v1->sprite->y_speed += v1->sprite->y_speed < 0 ? 1 : 0;
        if (v1->stats->is_infantry)
        {
            v23 = entity_40DA90_update_tile_info(v1);
            if (v23 >= 0)
            {
                if (v23 <= 1)
                {
                    entity_mode_attack_move_4_order_3_7_417E60(v1);
                    return;
                }
            LABEL_43:
                if (v23 == 3)
                {
                    v25 = v1->stats;
                    v1->mode_return = entity_mode_attack_move_2_5_4165C0;
                    entity_load_idle_mobd(v1);
                    v26 = v1->sprite;
                    v1->stru224._2C_map_x = v26->x_speed;
                    v1->stru224._30_map_y = v26->y_speed;
                    v26->x_speed = 0;
                    v1->sprite->y_speed = 0;
                    v27 = v1->field_124;
                    LOBYTE_HEXRAYS(v27) = v27 & 0xBF;
                    v1->_128_spawn_param = (void *)60;
                    v1->field_124 = v27;
                    v1->mode = entity_mode_417FC0;
                    return;
                }
                goto LABEL_46;
            }
        }
        else
        {
            v23 = entity_40DA90_update_tile_info(v1);
            if (v23 && v23 != 1)
                goto LABEL_43;
            entity_414C30_boxd(v1);
        }
    LABEL_46:
        entity_414AD0_vehicle_collide_vehicle(v1);

        if (v1->stats->field_4C == 128)
        log("v18 = %d\tv23 = %d\tx_speed = %d\ty_speed = %d", v18, v23, v1->sprite->x_speed, v1->sprite->y_speed);
        return;
    }

    v21 = v1->field_124;
    LOBYTE_HEXRAYS(v21) = v21 | 1;
    v1->field_124 = v21;
    v22 = v1->stats;
    if (v22->is_infantry)
    {
        entity_load_move_mobd(v1, v18);
        goto LABEL_37;
    }
    v28 = v1->sprite;
    v1->mode_turn_return = entity_mode_416790_vehicle_move;
    sprite_4272E0_load_mobd_item(v28, v22->mobd_lookup_offset_move, _47D3C4_entity_mobd_lookup_ids[v1->current_mobd_lookup_idx + 1]);
    v1->sprite->x_speed = 0;
    v1->sprite->y_speed = 0;
    v1->mode = entity_mode_415A60_vehicle_rotate;
}

//----- (00416A70) --------------------------------------------------------
void entity_mode_416A70_oiltanker(Entity *a1)
{
    Entity *v1; // esi@1
    UnitStat *v2; // ecx@1
    int v3; // eax@1
    int v4; // eax@3
    unsigned int v5; // ecx@5
    UnitStat *v6; // eax@5
    int v7; // ecx@5
    int v8; // eax@6
    int v9; // eax@8
    Sprite *v10; // ecx@10
    int v11; // eax@12
    int v12; // ecx@15
    bool v13; // sf@15
    unsigned __int8 v14; // of@15
    int v15; // eax@17
    Sprite *v16; // ecx@19
    int v17; // eax@21
    int v18; // ebp@24
    int v19; // eax@24
    int v20; // edx@24
    int v21; // edx@27
    int v22; // edx@28
    __int16 v23; // ax@32
    UnitStat *v24; // ecx@32

    v1 = a1;
    a1->sprite->x_speed = 0;
    a1->sprite->y_speed = 0;
    v2 = a1->stats;
    v3 = v2->field_4C;
    if (v3 != 4096)
    {
        if (v2->is_infantry)
            v4 = entity_40F0A0_get_dx(v1, v1->field_A4);
        else
            v4 = v3 != 128 ? 7424 : 4096;
        v5 = v4 + (v1->sprite->x & 0xFFFFE000);
        v6 = v1->stats;
        v1->sprite_x = v5;
        v7 = v6->is_infantry;
    LABEL_16:
        if (v7)
            v15 = entity_40F100_get_dy(v1, v1->field_A4);
        else
            v15 = v6->field_4C != 128 ? 7424 : 4096;
        v16 = v1->sprite;
        v1->sprite_y = v15 + (v16->y & 0xFFFFE000);
        goto LABEL_24;
    }
    v8 = v2->is_infantry;
    if ((v1->sprite->x & 0x1FFF) < 4096)
    {
        if (v8)
            v11 = entity_40F0A0_get_dx(v1, v1->field_A4);
        else
            v11 = 7424;
        v10 = v1->sprite;
        v1->sprite_x = (v10->x & 0xFFFFE000) + v11 - 0x2000;
    }
    else
    {
        if (v8)
            v9 = entity_40F0A0_get_dx(v1, v1->field_A4);
        else
            v9 = 7424;
        v10 = v1->sprite;
        v1->sprite_x = v9 + (v10->x & 0xFFFFE000);
    }
    v6 = v1->stats;
    v12 = v10->y & 0x1FFF;
    v14 = __OFSUB__(v12, 4096);
    v13 = v12 - 4096 < 0;
    v7 = v6->is_infantry;
    if (!(v13 ^ v14))
        goto LABEL_16;
    if (v7)
        v17 = entity_40F100_get_dy(v1, v1->field_A4);
    else
        v17 = v6->field_4C != 128 ? 7424 : 4096;
    v16 = v1->sprite;
    v1->sprite_y = (v16->y & 0xFFFFE000) + v17 - 0x2000;
LABEL_24:
    v18 = v16->x;
    v19 = v1->sprite_x;
    v20 = v16->x - v19;
    if (v20 <= 0)
        v20 = v19 - v18;
    if (v20 >= 512
        || ((v21 = v1->sprite_y, v16->y - v21 <= 0) ? (v22 = v21 - v16->y) : (v22 = v16->y - v21), v22 >= 512))
    {
        v23 = _42D560_get_mobd_lookup_id_rotation(v19 - v18, v1->sprite_y - v16->y);
        v24 = v1->stats;
        if (v24->is_infantry || v1->current_mobd_lookup_idx == v23)
        {
            entity_load_move_mobd(v1, v23);
            v1->mode = entity_mode_416CD0;
        }
        else
        {
            v1->_88_dst_orientation = v23;
            v1->mode = entity_mode_415A60_vehicle_rotate;
            v1->mode_turn_return = entity_mode_416A70_oiltanker;

            entity_load_move_mobd(v1);
            v1->sprite->x_speed = 0;
            v1->sprite->y_speed = 0;
        }
    }
    else
    {
        v16->x = v19;
        v1->sprite->y = v1->sprite_y;
        v1->sprite->x_speed = 0;
        v1->sprite->y_speed = 0;
        v1->mode = v1->mode_return;
    }
}

//----- (00416CD0) --------------------------------------------------------
void entity_mode_416CD0(Entity *a1)
{
    Entity *v1; // esi@1
    Sprite *v2; // edx@1
    int v3; // eax@1
    int v4; // ebp@1
    int v5; // ecx@1
    int v6; // ecx@4
    int v7; // ecx@5
    Sprite *v9; // ecx@9
    UnitStat *v10; // edi@10
    int v11; // edx@10
    int v12; // eax@11
    char *v13; // ecx@11
    int v14; // eax@16
    UnitStat *v15; // eax@18
    int v16; // eax@19

    v1 = a1;
    v2 = a1->sprite;
    v3 = a1->sprite_x;
    v4 = v2->x;
    v5 = v2->x - v3;
    if (v5 <= 0)
        v5 = v3 - v4;
    if (v5 >= 512 || ((v6 = v1->sprite_y, v2->y - v6 <= 0) ? (v7 = v6 - v2->y) : (v7 = v2->y - v6), v7 >= 512))
    {
        v9 = v1->sprite;
        v1->current_mobd_lookup_idx = _42D560_get_mobd_lookup_id_rotation(v3 - v4, v1->sprite_y - v2->y);
        sprite_4273B0_load_mobd_item_sound(
            v9,
            v1->stats->mobd_lookup_offset_move,
            _47D3C4_entity_mobd_lookup_ids[v1->current_mobd_lookup_idx + 1]);
        v1->sprite->x_speed = v1->stats->speed * _4731A8_speeds[__47CFC4_mobd_lookup_speeds[v1->current_mobd_lookup_idx + 1]] >> 6;
        v1->sprite->y_speed = -entity_get_mobd_speed_y(v1);
        if (entity_40DA90_update_tile_info(v1) != 4)
        {
            v1->sprite->x_speed = 0;
            v1->sprite->y_speed = 0;
            v10 = v1->stats;
            v11 = v10->field_4C;
            if (v11 != 4096)
            {
                v12 = 0;
                v13 = (char *)& _478AA8_boxd_stru0_array[v1->sprite->x >> 13]._4_entities[6
                    * _4793F8_map_width
                    * (v1->sprite->y >> 13)];
                while (*(Entity **)v13 != v1)
                {
                    ++v12;
                    v13 += 4;
                    if (v12 >= 5)
                        return;
                }
                if (v10->is_infantry)
                    v14 = entity_40F0A0_get_dx(v1, v1->field_A4);
                else
                    v14 = v11 != 128 ? 7424 : 4096;
                v1->sprite->x = v14 + (v1->sprite->x & 0xFFFFE000);
                v15 = v1->stats;
                if (v15->is_infantry)
                    v16 = entity_40F100_get_dy(v1, v1->field_A4);
                else
                    v16 = v15->field_4C != 128 ? 7424 : 4096;
                v1->sprite->y = v16 + (v1->sprite->y & 0xFFFFE000);
                v1->mode = v1->mode_return;
            }
        }
    }
    else
    {
        v2->x = v3;
        v1->sprite->y = v1->sprite_y;
        v1->sprite->x_speed = 0;
        v1->sprite->y_speed = 0;
        v1->mode = v1->mode_return;
    }
}

//----- (00416EB0) --------------------------------------------------------
void entity_mode_416EB0(Entity *a1)
{
    Entity *v1; // esi@1
    UnitStat *v2; // ecx@1
    int v3; // eax@1
    int v4; // eax@3
    unsigned int v5; // ecx@5
    UnitStat *v6; // eax@5
    int v7; // ecx@5
    int v8; // eax@6
    int v9; // eax@8
    Sprite *v10; // ecx@10
    int v11; // eax@12
    int v12; // ecx@15
    bool v13; // sf@15
    unsigned __int8 v14; // of@15
    int v15; // eax@17
    Sprite *v16; // ecx@19
    int v17; // eax@21
    int v18; // ebp@24
    int v19; // eax@24
    int v20; // edx@24
    int v21; // edx@27
    int v22; // edx@28
    __int16 v23; // ax@32
    UnitStat *v24; // ecx@32
    int v25; // edx@33

    v1 = a1;
    a1->sprite->x_speed = 0;
    a1->sprite->y_speed = 0;
    v2 = a1->stats;
    v3 = v2->field_4C;
    if (v3 != 4096)
    {
        if (v2->is_infantry)
            v4 = entity_40F0A0_get_dx(v1, v1->field_A4);
        else
            v4 = v3 != 128 ? 7424 : 4096;
        v5 = v4 + (v1->sprite->x & 0xFFFFE000);
        v6 = v1->stats;
        v1->sprite_x = v5;
        v7 = v6->is_infantry;
    LABEL_16:
        if (v7)
            v15 = entity_40F100_get_dy(v1, v1->field_A4);
        else
            v15 = v6->field_4C != 128 ? 7424 : 4096;
        v16 = v1->sprite;
        v1->sprite_y = v15 + (v16->y & 0xFFFFE000);
        goto LABEL_24;
    }
    v8 = v2->is_infantry;
    if ((v1->sprite->x & 0x1FFF) < 4096)
    {
        if (v8)
            v11 = entity_40F0A0_get_dx(v1, v1->field_A4);
        else
            v11 = 7424;
        v10 = v1->sprite;
        v1->sprite_x = (v10->x & 0xFFFFE000) + v11 - 0x2000;
    }
    else
    {
        if (v8)
            v9 = entity_40F0A0_get_dx(v1, v1->field_A4);
        else
            v9 = 7424;
        v10 = v1->sprite;
        v1->sprite_x = v9 + (v10->x & 0xFFFFE000);
    }
    v6 = v1->stats;
    v12 = v10->y & 0x1FFF;
    v14 = __OFSUB__(v12, 4096);
    v13 = v12 - 4096 < 0;
    v7 = v6->is_infantry;
    if (!(v13 ^ v14))
        goto LABEL_16;
    if (v7)
        v17 = entity_40F100_get_dy(v1, v1->field_A4);
    else
        v17 = v6->field_4C != 128 ? 7424 : 4096;
    v16 = v1->sprite;
    v1->sprite_y = (v16->y & 0xFFFFE000) + v17 - 0x2000;
LABEL_24:
    v18 = v16->x;
    v19 = v1->sprite_x;
    v20 = v16->x - v19;
    if (v20 <= 0)
        v20 = v19 - v18;
    if (v20 >= 1792
        || ((v21 = v1->sprite_y, v16->y - v21 <= 0) ? (v22 = v21 - v16->y) : (v22 = v16->y - v21), v22 >= 1792))
    {
        v23 = _42D560_get_mobd_lookup_id_rotation(v19 - v18, v1->sprite_y - v16->y);
        v24 = v1->stats;
        if (v24->is_infantry || (v25 = v1->current_mobd_lookup_idx, v25 == v23))
        {
            entity_load_move_mobd(v1, v23);
            v1->mode = entity_mode_417100;
        }
        else
        {
            v1->_88_dst_orientation = v23;
            v1->mode_turn_return = entity_mode_416EB0;

            entity_load_move_mobd(v1);
            v1->sprite->x_speed = 0;
            v1->sprite->y_speed = 0;
            v1->mode = entity_mode_415A60_vehicle_rotate;
        }
    }
    else
    {
        v16->x_speed = 0;
        v1->sprite->y_speed = 0;
        v1->mode = v1->mode_return;
    }
}

//----- (00417100) --------------------------------------------------------
void entity_mode_417100(Entity *a1)
{
    Entity *v1; // esi@1
    Sprite *v2; // edi@1
    int v3; // eax@1
    int v4; // ebp@1
    int v5; // ecx@1
    int v6; // ecx@4
    int v7; // ecx@5
    Sprite *v9; // ecx@9
    UnitStat *v10; // edi@10
    int v11; // edx@10
    int v12; // eax@11
    char *v13; // ecx@11
    int v14; // eax@16
    UnitStat *v15; // eax@18
    int v16; // eax@19

    v1 = a1;
    v2 = a1->sprite;
    v3 = a1->sprite_x;
    v4 = v2->x;
    v5 = v2->x - v3;
    if (v5 <= 0)
        v5 = v3 - v4;
    if (v5 >= 1792 || ((v6 = v1->sprite_y, v2->y - v6 <= 0) ? (v7 = v6 - v2->y) : (v7 = v2->y - v6), v7 >= 1792))
    {
        v9 = v1->sprite;
        entity_load_move_mobd(v1, _42D560_get_mobd_lookup_id_rotation(v3 - v4, v1->sprite_y - v2->y));
        v1->sprite->x_speed = v1->stats->speed * _4731A8_speeds[__47CFC4_mobd_lookup_speeds[v1->current_mobd_lookup_idx + 1]] >> 6;
        v1->sprite->y_speed = -entity_get_mobd_speed_y(v1);
        if (entity_40DA90_update_tile_info(v1) != 4)
        {
            v1->sprite->x_speed = 0;
            v1->sprite->y_speed = 0;
            v10 = v1->stats;
            v11 = v10->field_4C;
            if (v11 != 4096)
            {
                v12 = 0;
                v13 = (char *)& _478AA8_boxd_stru0_array[v1->sprite->x >> 13]._4_entities[6
                    * _4793F8_map_width
                    * (v1->sprite->y >> 13)];
                while (*(Entity **)v13 != v1)
                {
                    ++v12;
                    v13 += 4;
                    if (v12 >= 5)
                        return;
                }
                if (v10->is_infantry)
                    v14 = entity_40F0A0_get_dx(v1, v1->field_A4);
                else
                    v14 = v11 != 128 ? 7424 : 4096;
                v1->sprite->x = v14 + (v1->sprite->x & 0xFFFFE000);
                v15 = v1->stats;
                if (v15->is_infantry)
                    v16 = entity_40F100_get_dy(v1, v1->field_A4);
                else
                    v16 = v15->field_4C != 128 ? 7424 : 4096;
                v1->sprite->y = v16 + (v1->sprite->y & 0xFFFFE000);
                v1->mode = v1->mode_return;
            }
        }
    }
    else
    {
        v2->x_speed = 0;
        v1->sprite->y_speed = 0;
        v1->mode = v1->mode_return;
    }
}
// 4793F8: using guessed type int _4793F8_map_width;

//----- (004172D0) --------------------------------------------------------
void entity_4172D0(Entity *a1)
{
    Entity *v1; // esi@1
    __int16 v2; // ax@1
    UnitStat *v3; // ecx@1

    v1 = a1;
    v2 = _42D560_get_mobd_lookup_id_rotation(a1->sprite_x - a1->sprite->x, a1->sprite_y - a1->sprite->y);
    v3 = v1->stats;
    entity_load_move_mobd(v1, v2);
    v1->sprite->x_speed = v3->speed * _4731A8_speeds[__47CFC4_mobd_lookup_speeds[v2 + 1]] >> 6;
    v1->sprite->y_speed = -entity_get_mobd_speed_y(v1);
    v1->mode = entity_mode_417360_infantry;
}

//----- (00417360) --------------------------------------------------------
void entity_mode_417360_infantry(Entity *a1)
{
    Entity *v1; // esi@1
    Sprite *v2; // edi@1
    int v3; // eax@1
    int v4; // ebp@1
    int v5; // ecx@1
    int v6; // ecx@4
    int v7; // ecx@5
    enum UNIT_ID v8; // eax@8
    __int16 v9; // ax@12
    int v10; // eax@13
    Script *v11; // ST00_4@15
    Entity *v12; // edx@15
    int v13; // eax@15
    Script *v14; // ST00_4@16
    int v15; // eax@16
    __int16 v16; // ax@18
    UnitStat *v17; // ecx@18

    v1 = a1;
    v2 = a1->sprite;
    v3 = a1->sprite_x;
    v4 = v2->x;
    v5 = v2->x - v3;
    if (v5 <= 0)
        v5 = v3 - v4;
    if (v5 >= 512 || ((v6 = v1->sprite_y, v2->y - v6 <= 0) ? (v7 = v6 - v2->y) : (v7 = v2->y - v6), v7 >= 512))
    {
        v16 = _42D560_get_mobd_lookup_id_rotation(v3 - v4, v1->sprite_y - v2->y);
        v17 = v1->stats;
        entity_load_move_mobd(v1, v16);
        v1->sprite->x_speed = v1->stats->speed * _4731A8_speeds[__47CFC4_mobd_lookup_speeds[v16 + 1]] >> 6;
        v1->sprite->y_speed = -entity_get_mobd_speed_y(v1);
    }
    else
    {
        v8 = v1->unit_id;
        if (v8 != UNIT_STATS_SURV_TANKER
            && v8 != UNIT_STATS_MUTE_TANKER
            && v8 != UNIT_STATS_SURV_MOBILE_DERRICK
            && v8 != UNIT_STATS_MUTE_MOBILE_DERRICK)
        {
            v1->script->event_handler = EventHandler_Infantry;
            v9 = v1->field_2A4;
            if (v9)
            {
                v10 = v9 - 1;
                if (!v10)
                {
                    v14 = v1->script;
                    v1->stru224.field_54 = 0;
                    v1->stru224.field_50 = 0;
                    script_445370_yield_to_main_thread(v14, 0x80000000, 1);
                    v15 = v1->sprite_height_3;
                    v1->sprite_x_2 = v1->sprite_width_3;
                    v1->_DC_order = ENTITY_ORDER_MOVE;
                    v1->_E0_current_attack_target = 0;
                    v1->_134_param__unitstats_after_mobile_outpost_plant = 600;
                    v1->sprite_y_2 = v15;
                    v1->entity_8 = 0;
                    entity_40DF50_boxd_update_map_tile(v1, 1);
                    v1->mode = entity_mode_move_attack;
                    return;
                }
                if (v10 == 1)
                {
                    v11 = v1->script;
                    v1->stru224.field_54 = 0;
                    v1->stru224.field_50 = 0;
                    script_445370_yield_to_main_thread(v11, 0x80000000, 1);
                    v12 = v1->_2A8_entity;
                    v13 = v1->_2A8_entity_id;
                    v1->_DC_order = ENTITY_ORDER_ATTACK;
                    v1->_E0_current_attack_target = v12;
                    v1->_E0_current_attack_target_entity_id = v13;
                    v1->_E4_prev_attack_target = 0;
                    v1->_134_param__unitstats_after_mobile_outpost_plant = 600;
                    v1->entity_8 = 0;
                    v1->mode = entity_mode_move_attack;
                    return;
                }
            }
        }
        v1->mode = v1->mode_return;
    }
}

//----- (00417550) --------------------------------------------------------
void entity_mode_attack_move_4_417550(Entity *a1)
{
    Entity *v1; // esi@1
    Sprite *v2; // edx@1
    int v3; // eax@1
    int v4; // ecx@1
    int v5; // edi@1
    int v6; // edx@1
    int v7; // edi@1
    int v8; // eax@1
    int v9; // edx@1
    int v10; // ecx@1
    int v11; // eax@1
    int v12; // edx@3
    int v13; // edi@3
    int v14; // eax@5

    v1 = a1;
    entity_load_idle_mobd(a1);
    v1->sprite->x_speed = 0;
    v1->sprite->y_speed = 0;

    v2 = v1->sprite;
    v3 = v1->sprite_x >> 13;
    v4 = v1->sprite_y >> 13;
    v1->field_CC = v3;
    v1->field_D0 = v4;
    v5 = v2->x >> 13;
    v1->field_138 = v5;
    v1->field_13C = v2->y >> 13;
    v6 = v5;
    v7 = v1->field_13C;
    v1->stru224._34_x = v6;
    v1->stru224._2C_map_x = v6;
    v1->stru224._38_y = v7;
    v1->stru224._30_map_y = v7;
    v8 = _42D560_get_mobd_lookup_id_rotation(v3 - v6, v4 - v7);
    v9 = v1->field_CC;
    LOBYTE_HEXRAYS(v8) = ((v8 + 16) >> 5) & 7;
    v1->stru224.field_3C = ((_BYTE)v8 + 2) & 7;
    v10 = v1->field_138;
    v1->stru224._40_xy_idx = ((_BYTE)v8 - 2) & 7;
    v11 = v9 - v10;
    if (v9 - v10 <= 0)
        v11 = v10 - v9;
    v12 = v1->field_13C;
    v13 = v1->field_D0 - v12;
    if (v13 <= 0)
        v13 = v12 - v1->field_D0;
    v14 = v13 + v11;
    v1->field_150 = v12;
    v1->field_148 = v14;
    v1->field_14C = v10;
    v1->field_154 = 0;
    v1->field_140 = 0;
    v1->field_144 = 2 * v14;
    v1->mode = entity_mode_417670;
}

//----- (00417670) --------------------------------------------------------
void entity_mode_417670(Entity *a1)
{
    Entity *v1; // esi@1
    int *v2; // ebp@1
    int v3; // edx@2
    int v4; // eax@2
    int v5; // edi@4
    int v6; // ecx@4
    int v7; // ecx@6
    int v8; // eax@6
    int v9; // ebx@7
    int v10; // ebx@9
    int v11; // eax@9
    int v12; // edx@11
    int v13; // ecx@11
    int v14; // ecx@13
    int v15; // eax@13
    int v16; // edi@14
    int v17; // edi@16
    int v18; // eax@18
    int v19; // eax@19
    int v20; // eax@22
    int v21; // eax@23
    int v22; // [sp+10h] [bp-4h]@1

    v1 = a1;
    v22 = 0;
    v2 = &a1->stru224._2C_map_x;
    while (1)
    {
        boxd_44D250(v2, &v1->stru224._30_map_y, 1, v1, &v1->stru224.field_3C);
        v3 = *v2;
        v4 = v1->field_CC - *v2;
        if (v4 <= 0)
            v4 = v3 - v1->field_CC;
        v5 = v1->stru224._30_map_y;
        v6 = v1->field_D0 - v5;
        if (v6 <= 0)
            v6 = v5 - v1->field_D0;
        v7 = v4 + v6;
        v8 = v1->field_148;
        v1->field_158 = v7;
        if (v7 < v8)
        {
            v9 = v1->field_140;
            if (v9 < 2 * (v8 - v7))
            {
                v1->field_148 = v7;
                v1->field_14C = v3;
                v1->field_150 = v5;
                v1->field_154 = v9;
                v1->field_D4 = 1;
            }
        }
        boxd_44D250(&v1->stru224._34_x, &v1->stru224._38_y, 0, v1, &v1->stru224._40_xy_idx);
        v10 = v1->stru224._34_x;
        v11 = v1->field_CC - v1->stru224._34_x;
        if (v11 <= 0)
            v11 = v10 - v1->field_CC;
        v12 = v1->stru224._38_y;
        v13 = v1->field_D0 - v12;
        if (v13 <= 0)
            v13 = v12 - v1->field_D0;
        v14 = v11 + v13;
        v15 = v1->field_148;
        v1->field_158 = v14;
        if (v14 < v15)
        {
            v16 = v1->field_140;
            if (v16 < 2 * (v15 - v14))
            {
                v1->field_148 = v14;
                v1->field_14C = v10;
                v1->field_150 = v12;
                v1->field_154 = v16;
                v1->field_D4 = 0;
            }
        }
        v17 = v1->field_140;
        if (v17 == v1->field_144)
            break;
        if (v17 > 1)
        {
            v18 = v1->field_138;
            v19 = *v2 - v18 <= 0 ? v18 - *v2 : *v2 - v18;
            if (v19 <= 1)
            {
                v20 = v1->field_13C;
                v21 = v1->stru224._30_map_y - v20 <= 0 ? v20 - v1->stru224._30_map_y : v1->stru224._30_map_y - v20;
                if (v21 <= 1)
                    break;
            }
        }
        v1->field_140 = v17 + 1;
        if (++v22 >= 4)
            return;
    }
    entity_417810(v1);
}

//----- (00417810) --------------------------------------------------------
void entity_417810(Entity *a1)
{
    Entity *v1; // esi@1
    Sprite *v2; // ecx@1
    int v3; // eax@1
    int v4; // edx@4
    int v5; // eax@4
    UnitStat *v6; // eax@4
    int v7; // eax@5
    int v8; // ecx@7
    UnitStat *v9; // eax@7
    int v10; // eax@8
    int v13; // eax@10

    v1 = a1;
    v2 = a1->sprite;
    v3 = v1->field_14C;
    if (v3 != v2->x >> 13 || v1->field_150 != v2->y >> 13)
    {
        v4 = v1->field_150;
        v1->field_CC = v3;
        v5 = v1->field_154;
        v1->field_D0 = v4;
        v1->_C0_mobd_anim_speed_related = v5 + 1;
        v6 = v1->stats;
        if (v6->is_infantry)
            v7 = entity_40F0A0_get_dx(v1, v1->field_A4);
        else
            v7 = v6->field_4C != 128 ? 7424 : 4096;
        v8 = v7 + (v1->field_CC << 13);
        v9 = v1->stats;
        v1->sprite_x = v8;
        if (v9->is_infantry)
            v10 = entity_40F100_get_dy(v1, v1->field_A4);
        else
            v10 = v9->field_4C != 128 ? 7424 : 4096;
        v1->sprite_y = v10 + (v1->field_D0 << 13);
        v1->stru224._2C_map_x = v1->sprite->_60_mobd_anim_speed;
        v13 = v1->field_124;
        v1->_128_spawn_param = 0;
        LOBYTE_HEXRAYS(v13) = v13 & 0xFE;
        v1->mode = entity_mode_417BD0;
        v1->field_124 = v13;

        entity_load_move_mobd(v1);
        v1->sprite->x_speed = 0;
        v1->sprite->y_speed = 0;
        if (v1->field_D4)
        {
            v1->field_D8 = ((unsigned __int8)v1->current_mobd_lookup_idx + 64) & 0xE0;
        }
        else
        {
            v1->field_D8 = ((unsigned __int8)v1->current_mobd_lookup_idx - 64) & 0xE0;
        }
        entity_mode_417A20(v1);
    }
    else
    {
        v1->mode_return = entity_mode_415540_infantry;
        entity_mode_416A70_oiltanker(v1);
    }
}

//----- (00417980) --------------------------------------------------------
void entity_417980(Entity *a1)
{
    Entity *v1; // esi@1
    int v4; // eax@1
    int v5; // eax@1

    v1 = a1;
    v4 = a1->sprite->_60_mobd_anim_speed;
    v1->_128_spawn_param = 0;
    v1->stru224._2C_map_x = v4;
    v5 = v1->field_124;
    LOBYTE_HEXRAYS(v5) = v5 & 0xFE;
    v1->mode = entity_mode_417BD0;
    v1->field_124 = v5;

    entity_load_move_mobd(v1);
    v1->sprite->x_speed = 0;
    v1->sprite->y_speed = 0;

    if (v1->field_D4)
    {
        v1->field_D8 = ((unsigned __int8)v1->current_mobd_lookup_idx + 64) & 0xE0;
    }
    else
    {
        v1->field_D8 = ((unsigned __int8)v1->current_mobd_lookup_idx - 64) & 0xE0;
    }
    entity_mode_417A20(v1);
}

//----- (00417A20) --------------------------------------------------------
void entity_mode_417A20(Entity *a1)
{
    Entity *v1; // esi@1
    Sprite *v2; // eax@1
    void *v3; // eax@4
    int v4; // eax@6
    UnitStat *v5; // eax@8
    int v6; // edx@9
    int v7; // eax@9
    __int16 v8; // ax@14
    UnitStat *v9; // edx@14

    v1 = a1;
    v2 = a1->sprite;
    if (a1->field_14C != v2->x >> 13 || a1->field_150 != v2->y >> 13)
    {
        v3 = a1->_128_spawn_param;
        a1->_128_spawn_param = (char *)v3 + 1;
        if ((int)v3 < a1->_C0_mobd_anim_speed_related)
        {
            a1->mode = entity_mode_417BD0;
            v4 = entity_44D000_boxd(a1);
            if (v4)
            {
                if (v4 == 2)
                {
                    entity_mode_move_attack(v1);
                }
                else
                {
                    v5 = v1->stats;
                    if (v5->is_infantry)
                    {
                        v6 = (signed __int16)_42D560_get_mobd_lookup_id_rotation(
                            v1->sprite_x - v1->sprite->x,
                            v1->sprite_y - v1->sprite->y);
                        v7 = v1->_88_dst_orientation;
                        v1->current_mobd_lookup_idx = v6;
                        v1->field_D8 = v7;
                        entity_413C10(v1);
                        entity_load_move_mobd(v1);
                    }
                    else if (v5->field_4C == 128
                        || boxd_41C130(v1->sprite_x, v1->sprite_y, v1->sprite->x, v1->sprite->y, v1))
                    {
                        v8 = _42D560_get_mobd_lookup_id_rotation(v1->sprite_x - v1->sprite->x, v1->sprite_y - v1->sprite->y);
                        v1->field_D8 = v8;
                        v9 = v1->stats;
                        v1->_88_dst_orientation = ((_BYTE)v8 + 8) & 0xF0;
                        v1->mode_turn_return = entity_mode_417BD0;
                        entity_load_move_mobd(v1);
                        v1->sprite->x_speed = 0;
                        v1->sprite->y_speed = 0;
                        v1->mode = entity_mode_415A60_vehicle_rotate;
                    }
                    else if (!entity_414870_boxd(v1))
                    {
                        entity_mode_attack_move_4_order_3_7_417E60(v1);
                    }
                }
            }
            else
            {
                entity_mode_attack_move_4_order_3_7_417E60(v1);
            }
        }
        else
        {
            entity_mode_move_attack(a1);
        }
    }
    else
    {
        a1->mode_return = entity_mode_415540_infantry;
        entity_mode_416A70_oiltanker(a1);
    }
}

//----- (00417BD0) --------------------------------------------------------
void entity_mode_417BD0(Entity *a1)
{
    Entity *v1; // esi@1
    Sprite *v2; // edi@2
    int v3; // eax@2
    int v4; // eax@3
    int v5; // eax@6
    int v6; // eax@7
    int v7; // eax@10
    Sprite *v8; // edi@11
    int v9; // eax@11
    int v10; // eax@12
    int v11; // eax@15
    int v12; // eax@16
    int v13; // eax@23
    int v16; // eax@27
    UnitStat *v17; // eax@27
    int v18; // eax@30
    int v22; // eax@36

    v1 = a1;
    a1->sprite->_60_mobd_anim_speed = a1->stru224._2C_map_x;
    if (!a1->stats->is_infantry)
    {
        v2 = a1->sprite;
        v3 = a1->sprite_x;
        v4 = v2->x - v3 <= 0 ? v3 - v2->x : v2->x - v3;
        if (v4 < 1792)
        {
            v5 = a1->sprite_y;
            v6 = v2->y - v5 <= 0 ? v5 - v2->y : v2->y - v5;
            if (v6 < 1792)
            {
                v7 = a1->field_124;
                LOBYTE_HEXRAYS(v7) = v7 | 1;
                a1->field_124 = v7;
            }
        }
    }
    v8 = a1->sprite;
    v9 = a1->sprite_x;
    if (v8->x - v9 <= 0)
        v10 = v9 - v8->x;
    else
        v10 = v8->x - v9;
    if (v10 < 768)
    {
        v11 = a1->sprite_y;
        v12 = v8->y - v11 <= 0 ? v11 - v8->y : v8->y - v11;
        if (v12 < 768)
        {
            a1->mode = entity_mode_417A20;
            return;
        }
    }
    if (!entity_4135E0(a1))
    {
        if (!(v1->field_124 & 1))
        {
            v13 = v1->stats->is_infantry ? entity_40D600_infantry_get_new_movement_orientation(v1, v1->sprite_x, v1->sprite_y, 512) : entity_40D6F0_vehicle_get_new_movement_orientation(v1, v1->sprite_x, v1->sprite_y, 512);
            v1->_88_dst_orientation = v13;
            if (v13 != -1)
            {
                if (v1->current_mobd_lookup_idx != v13)
                {
                    v16 = v1->field_124;
                    LOBYTE_HEXRAYS(v16) = v16 | 1;
                    v1->field_124 = v16;
                    v17 = v1->stats;
                    if (!v17->is_infantry)
                    {
                        entity_load_move_mobd(v1);
                        v1->sprite->x_speed = 0;
                        v1->sprite->y_speed = 0;
                        v1->mode = entity_mode_415A60_vehicle_rotate;
                        v1->mode_turn_return = entity_mode_417BD0;
                        return;
                    }
                    entity_load_move_mobd(v1, v13);
                }
            }
        }
        v1->sprite->x_speed = v1->stats->speed * _4731A8_speeds[__47CFC4_mobd_lookup_speeds[v1->current_mobd_lookup_idx + 1]] >> 6;
        v1->sprite->y_speed = -entity_get_mobd_speed_y(v1);
        v1->sprite->x_speed += v1->sprite->x_speed < 0 ? 1 : 0;
        v1->sprite->y_speed += v1->sprite->y_speed < 0 ? 1 : 0;
        if (v1->stats->is_infantry)
        {
            v18 = entity_40DA90_update_tile_info(v1);
            if (v18 >= 0)
            {
                if (v18 <= 1)
                {
                    entity_mode_attack_move_4_order_3_7_417E60(v1);
                    return;
                }
            LABEL_35:
                if (v18 == 3)
                {
                    entity_load_idle_mobd(v1);
                    v1->mode = entity_mode_417FC0;
                    v1->mode_return = entity_mode_attack_move_2_5_4165C0;
                    v1->stru224._2C_map_x = v1->sprite->x_speed;
                    v1->stru224._30_map_y = v1->sprite->y_speed;
                    v1->sprite->x_speed = 0;
                    v1->sprite->y_speed = 0;
                    v22 = v1->field_124;
                    LOBYTE_HEXRAYS(v22) = v22 & 0xBF;
                    v1->_128_spawn_param = (void *)60;
                    v1->field_124 = v22;
                    return;
                }
                goto LABEL_38;
            }
        }
        else
        {
            v18 = entity_40DA90_update_tile_info(v1);
            if (v18 && v18 != 1)
                goto LABEL_35;
            entity_414C30_boxd(v1);
        }
    LABEL_38:
        entity_414AD0_vehicle_collide_vehicle(v1);
    }
}

//----- (00417F50) --------------------------------------------------------
void entity_mode_417F50(Entity *a1)
{
    entity_mode_move_attack(a1);
}

//----- (00417E60) --------------------------------------------------------
void entity_mode_attack_move_4_order_3_7_417E60(Entity *a1)
{
    Entity *v1; // esi@1
    Sprite *v2; // ecx@2
    int v3; // eax@2
    int v4; // ecx@2
    int v5; // edi@6
    int v6; // edi@8

    v1 = a1;
    a1->mode = entity_mode_417F50;
    if (!entity_4135E0(a1))
    {
        v2 = v1->sprite;
        v3 = v2->x >> 13;
        v4 = v2->y >> 13;
        if ((_WORD)v3 != HIWORD_HEXRAYS(v1->field_29C) || (_WORD)v4 != LOWORD_HEXRAYS(v1->field_2A0))
        {
            HIWORD_HEXRAYS(v1->field_2A0) = 0;
            HIWORD_HEXRAYS(v1->field_29C) = v3;
            LOWORD_HEXRAYS(v1->field_2A0) = v4;
        }
        else
        {
            ++HIWORD_HEXRAYS(v1->field_2A0);
        }
        v5 = 16 * HIWORD_HEXRAYS(v1->field_2A0);
        if (v5 >= 240)
            v5 = 240;
        v6 = (kknd_rand_3() & 7) + v5;
        entity_40DF50_boxd_update_map_tile(v1, 1);
        v1->sprite->_60_mobd_anim_speed = 0;
        v1->sprite->x_speed = 0;
        v1->sprite->y_speed = 0;
        if (v1->stats->is_infantry)
        {
            v1->mode_return = entity_mode_417F50;
            entity_mode_416A70_oiltanker(v1);
        }
        script_445370_yield_to_main_thread(v1->script, 0x80000000, v6);
    }
}

//----- (00417F60) --------------------------------------------------------
void entity_417F60(Entity *a1)
{
    Entity *v1; // esi@1
    Sprite *v2; // eax@1
    int v3; // eax@1

    v1 = a1;
    entity_load_idle_mobd(a1);
    v2 = v1->sprite;
    v1->stru224._2C_map_x = v2->x_speed;
    v1->stru224._30_map_y = v2->y_speed;
    v2->x_speed = 0;
    v1->sprite->y_speed = 0;
    v3 = v1->field_124;
    LOBYTE_HEXRAYS(v3) = v3 & 0xBF;
    v1->_128_spawn_param = (void *)60;
    v1->field_124 = v3;
    v1->mode = entity_mode_417FC0;
}

//----- (00417FC0) --------------------------------------------------------
void entity_mode_417FC0(Entity *a1)
{
    Entity *v1; // esi@1
    bool v2; // zf@1
    Sprite *v3; // eax@1
    int v4; // eax@3
    char *v5; // eax@5
    Entity *v6; // edi@7
    int v7; // eax@8
    int v8; // eax@10
    int v9; // eax@11
    int v10; // eax@14

    v1 = a1;
    a1->sprite->x_speed = a1->stru224._2C_map_x;
    a1->sprite->y_speed = a1->stru224._30_map_y;
    v2 = entity_40DA90_update_tile_info(a1) == 4;
    v1->sprite->x_speed = 0;
    v1->sprite->y_speed = 0;
    v3 = v1->sprite;
    if (v2)
    {
        v3->x += v1->stru224._2C_map_x;
        v1->sprite->y += v1->stru224._30_map_y;
        v1->mode = v1->mode_return;
        v1->stru224.field_50 = 0;
        return;
    }
    v4 = entity_40E000_boxd(v1, v1->stru224._2C_map_x + v3->x, v1->stru224._30_map_y + v3->y);
    if (v4 == 1 || !v4)
    {
        entity_mode_attack_move_4_order_3_7_417E60(v1);
        return;
    }
    v5 = (char *)v1->_128_spawn_param;
    v1->_128_spawn_param = v5 - 1;
    if (!v5)
    {
        v1->stru224.field_50 = 2;
        entity_mode_attack_move_4_order_3_7_417E60(v1);
        return;
    }
    v6 = v1->entity_27C;
    if (v6)
    {
        v7 = v6->entity_id;
        if (v7)
        {
            if (v7 == v1->entity_27C_entity_id)
            {
                v8 = v1->current_mobd_lookup_idx;
                if (v6->current_mobd_lookup_idx - v8 <= 0)
                    v9 = v8 - v6->current_mobd_lookup_idx;
                else
                    v9 = v6->current_mobd_lookup_idx - v8;
                if (v9 <= 48)
                {
                    if (v6->stats->speed < v1->stats->speed)
                    {
                        v1->stru224.field_50 = 2;
                        entity_mode_move_attack(v1);
                        return;
                    }
                }
                else
                {
                    v10 = v1->field_124;
                    LOBYTE_HEXRAYS(v10) = v10 | 0x40;
                    v1->field_124 = v10;
                }
            }
        }
    }
    if (v1->field_124 & 0x40)
        entity_40DF50_boxd_update_map_tile(v1, 0);
    script_445370_yield_to_main_thread(v1->script, 0x80000000, 3);
}

//----- (00418120) --------------------------------------------------------
void entity_418120(Entity *a1)
{
    entity_load_idle_mobd(a1);
    a1->sprite->x_speed = 0;
    a1->sprite->y_speed = 0;
    a1->_128_spawn_param = (void *)60;
    entity_40DF50_boxd_update_map_tile(a1, 0);
    a1->mode = entity_mode_4181B0;
}

//----- (00418170) --------------------------------------------------------
void entity_418170(Entity *a1)
{
    entity_load_idle_mobd(a1);
    a1->sprite->x_speed = 0;
    a1->sprite->y_speed = 0;
    a1->_128_spawn_param = (void *)60;
    a1->mode = entity_mode_4181B0;
}

//----- (004181B0) --------------------------------------------------------
void entity_mode_4181B0(Entity *a1)
{
    Entity *v1; // esi@1
    DataBoxd_stru0_per_map_unit *v2; // ebx@1
    int v3; // edi@1
    int v4; // edx@5
    Entity **v5; // ecx@5
    char *v6; // eax@9

    v1 = a1;
    v2 = &_478AA8_boxd_stru0_array[a1->stru224._2C_map_x + _4793F8_map_width * a1->stru224._30_map_y];
    v3 = boxd_40ED00(a1, &_478AA8_boxd_stru0_array[a1->stru224._2C_map_x + _4793F8_map_width * a1->stru224._30_map_y]);
    if (v3 == 2)
    {
        entity_40DF50_boxd_update_map_tile(v1, 1);
        entity_mode_attack_move_2_5_4165C0(v1);
    }
    if (v3 != 1 && v3)
    {
        v4 = 0;
        v5 = v2->_4_entities;
        do
        {
            if (*v5 && (*v5)->stats->speed < v1->stats->speed)
            {
                v1->stru224.field_50 = 2;
                entity_mode_move_attack(v1);
                return;
            }
            ++v4;
            ++v5;
        } while (v4 < 5);
        v6 = (char *)v1->_128_spawn_param;
        v1->_128_spawn_param = v6 - 1;
        if (v6)
        {
            script_445370_yield_to_main_thread(v1->script, 0x80000000, 3);
        }
        else
        {
            v1->stru224.field_50 = 2;
            entity_mode_attack_move_4_order_3_7_417E60(v1);
        }
    }
    else
    {
        entity_mode_attack_move_4_order_3_7_417E60(v1);
    }
}
// 4793F8: using guessed type int _4793F8_map_width;

//----- (00418290) --------------------------------------------------------
void entity_418290(Entity *a1)
{
    Entity *v1; // esi@1
    int v2; // edx@5
    UnitStat *v4; // edx@5
    int v5; // edi@6
    int v6; // eax@6
    bool v7; // zf@6
    bool v8; // sf@6
    UnitStat *v9; // eax@6
    int v10; // ecx@6
    int v11; // eax@8
    int v12; // ecx@10
    int v13; // eax@12
    UnitStat *v14; // eax@16
    int v15; // eax@17
    int v16; // edx@19
    UnitStat *v17; // eax@19
    int v18; // ecx@19
    int v19; // eax@21
    int v20; // ecx@23
    int v21; // eax@25

    v1 = a1;
    a1->sprite->x_speed = 0;
    a1->sprite->y_speed = 0;
    if (_47C048_unit_bomberdmg >= 200)
    {
        a1->mode = entity_mode_418550;
        return;
    }
    entity_load_idle_mobd(a1);
    entity_40DF50_boxd_update_map_tile(v1, 0);
    v1->sprite->x_speed = 0;
    v1->sprite->y_speed = 0;
    if (!v1->stats->is_infantry)
    {
        if (v1->current_mobd_lookup_idx != (signed __int16)_42D560_get_mobd_lookup_id_rotation(
            v1->entity_8->sprite->x - v1->sprite->x,
            v1->entity_8->sprite->y - v1->sprite->y))
        {
            v2 = (signed __int16)_42D560_get_mobd_lookup_id_rotation(
                v1->entity_8->sprite->x - v1->sprite->x,
                v1->entity_8->sprite->y - v1->sprite->y);
            v1->_88_dst_orientation = v2;
            v4 = v1->stats;
            v1->mode_turn_return = entity_mode_418590;
            entity_load_move_mobd(v1);
            v1->sprite->x_speed = 0;
            v1->sprite->y_speed = 0;
            v1->mode = entity_mode_415A60_vehicle_rotate;
            return;
        }
        goto LABEL_29;
    }
    v5 = v1->sprite->x;
    v6 = (v5 & 0xFFFFE000) - v5 + entity_40F0A0_get_dx(v1, v1->field_A4);
    v7 = v6 == 0;
    v8 = v6 < 0;
    v9 = v1->stats;
    v10 = v9->is_infantry;
    if (v8 || v7)
    {
        if (v10)
            v13 = entity_40F0A0_get_dx(v1, v1->field_A4);
        else
            v13 = v9->field_4C != 128 ? 7424 : 4096;
        v12 = v1->sprite->x - (v1->sprite->x & 0xFFFFE000) - v13;
    }
    else
    {
        if (v10)
            v11 = entity_40F0A0_get_dx(v1, v1->field_A4);
        else
            v11 = v9->field_4C != 128 ? 7424 : 4096;
        v12 = v11 + (v1->sprite->x & 0xFFFFE000) - v1->sprite->x;
    }
    if (v12 <= 1792)
    {
        v14 = v1->stats;
        v15 = v14->is_infantry ? entity_40F100_get_dy(v1, v1->field_A4) : v14->field_4C != 128 ? 7424 : 4096;
        v16 = v15 + (v1->sprite->y & 0xFFFFE000) - v1->sprite->y;
        v17 = v1->stats;
        v18 = v17->is_infantry;
        if (v16 <= 0)
        {
            v21 = v18 ? entity_40F100_get_dy(v1, v1->field_A4) : v17->field_4C != 128 ? 7424 : 4096;
            v20 = v1->sprite->y - (v1->sprite->y & 0xFFFFE000) - v21;
        }
        else
        {
            v19 = v18 ? entity_40F100_get_dy(v1, v1->field_A4) : v17->field_4C != 128 ? 7424 : 4096;
            v20 = v19 + (v1->sprite->y & 0xFFFFE000) - v1->sprite->y;
        }
        if (v20 <= 1792)
        {
        LABEL_29:
            v1->mode = entity_mode_418550;
            int rnd = kknd_rand_3();
            v1->stru224._2C_map_x = rnd & 0x3F;
            return;
        }
    }
    v1->mode_return = entity_mode_418590;
    entity_mode_416EB0(v1);
}

//----- (00418550) --------------------------------------------------------
void entity_mode_418550(Entity *a1)
{
    --a1->stru224._2C_map_x;
    if (_47C048_unit_bomberdmg >= 200)
        a1->stru224._2C_map_x = 10;
    if (!a1->stru224._2C_map_x)
        a1->mode = entity_mode_418590;
}

//----- (00418590) --------------------------------------------------------
void entity_mode_418590(Entity *a1)
{
    Entity *v1; // esi@1
    Entity *v2; // edx@1
    __int16 v3; // ax@6
    int v5; // edx@6
    UnitDamageSource *v6; // edi@9
    Sprite *v7; // eax@11
    int v8; // edx@11
    Sprite *v9; // ebx@11
    Script *v10; // eax@13
    int v11; // edx@13
    int v12; // ebx@15
    Sprite *v13; // edi@15
    int v14; // eax@15
    int v15; // ebp@16
    int v16; // eax@18
    int v17; // edi@18
    int v18; // eax@18
    int v19; // eax@19

    v1 = a1;
    v2 = a1->entity_8;
    if (!v2 || !entity_413120(a1, v2, a1->entity_118_entity_id))
    {
    LABEL_23:
        entity_4133D0(v1);
        return;
    }
    if (!sub_44CE40(v1->player_side, v1->entity_8))
    {
        if (v1->entity_8 == v1->_E0_current_attack_target)
        {
            v1->_E0_current_attack_target = 0;
            entity_4133D0(v1);
            return;
        }
        goto LABEL_23;
    }
    v3 = _42D560_get_mobd_lookup_id_rotation(
        (v1->entity_8->sprite->x - v1->sprite->x) >> 8,
        (v1->entity_8->sprite->y - v1->sprite->y) >> 8);

    if (v1->stats->mobd_lookup_offset_attack == -1)
        entity_load_idle_mobd(v1, v3);
    else
        entity_load_attack_mobd(v1, v3);

    v6 = v1->stats->dmg_source;
    if (v6 && _47C048_unit_bomberdmg < 200)
    {
        ++_47C048_unit_bomberdmg;
        v7 = sprite_create_scripted(v6->mobd_id, v1->sprite, v6->dmg_handler, SCRIPT_COROUTINE, v1->stru60.ptr_0);
        v8 = v6->mobd_offset;
        v9 = v7;
        if (v8 != -1)
            sprite_4272E0_load_mobd_item(v7, v8, _47D3C4_entity_mobd_lookup_ids[v1->current_mobd_lookup_idx + 1]);
        v10 = v9->script;
        v11 = v1->sprite->z_index;
        v9->param = v6;
        v9->z_index = v11 + 256;
        v10->param = v1->entity_8;
        v9->_80_entity__stru29__sprite__initial_hitpoints = v1;
        v9->field_84 = v1->entity_id;
        v9->field_8C_infantry_damage = LOWORD_HEXRAYS(v6->damage_infantry)
            + (v6->damage_infantry * _465610_damage_multipliers[v1->_98_465610_accuracy_dmg_bonus_idx] >> 8);
        v9->field_8E_vehicle_damage = LOWORD_HEXRAYS(v6->damage_vehicle)
            + (v6->damage_vehicle * _465610_damage_multipliers[v1->_98_465610_accuracy_dmg_bonus_idx] >> 8);
        v9->field_90_building_damage = LOWORD_HEXRAYS(v6->damage_building)
            + (v6->damage_building * _465610_damage_multipliers[v1->_98_465610_accuracy_dmg_bonus_idx] >> 8);
        script_trigger_event(v1->script, EVT_MSG_1497, v1, v1->entity_8->script);
        script_445370_yield_to_main_thread(
            v1->script,
            0x80000000,
            v1->stats->reload_time
            - (v1->stats->reload_time * _465610_damage_multipliers[v1->_98_465610_accuracy_dmg_bonus_idx + 4] >> 8));
    }
    if (v1->_DC_order == 8)
    {
        v12 = v1->sprite_x_2;
        v13 = v1->sprite;
        v14 = v13->x >> 13;
        if ((v1->sprite_x_2 >> 13) - v14 <= 0)
            v15 = v14 - (v1->sprite_x_2 >> 13);
        else
            v15 = (v1->sprite_x_2 >> 13) - v14;
        v16 = v13->y;
        v17 = v1->sprite_y_2;
        v18 = v16 >> 13;
        if ((v1->sprite_y_2 >> 13) - v18 <= 0)
            v19 = v18 - (v1->sprite_y_2 >> 13);
        else
            v19 = (v1->sprite_y_2 >> 13) - v18;
        if (v15 + v19 > 5)
        {
            v1->_DC_order = ENTITY_ORDER_MOVE;
            v1->sprite_x = v12;
            v1->sprite_y = v17;
            v1->_E0_current_attack_target = 0;
            entity_mode_move_attack(v1);
        }
    }
}
// 47C048: using guessed type int _47C048_unit_bomberdmg;

//----- (004187F0) --------------------------------------------------------
void entity_4187F0(Entity *a1)
{
    Entity *v1; // esi@1
    Entity *v2; // eax@1
    int v3; // eax@1
    Sprite *v4; // ecx@1
    __int16 v5; // ax@1
    UnitStat *v6; // edx@1

    v1 = a1;
    a1->script->event_handler = EventHandler_419CA0;
    entity_40DEC0_boxd(a1, a1->sprite_map_x, a1->sprite_map_y, a1->field_A4);
    script_trigger_event(v1->script, EVT_SHOW_UI_CONTROL, 0, task_mobd17_cursor);
    v2 = v1->_E0_current_attack_target;
    v1->sprite_x = v2->sprite->x + v2->stru60.pstru4->x_offset;
    v3 = v2->stru60.pstru4->y_offset + v2->sprite->y;
    v4 = v1->sprite;
    v1->sprite_y = v3;
    v5 = _42D560_get_mobd_lookup_id_rotation(v1->sprite_x - v4->x, v3 - v4->y);
    v6 = v1->stats;

    entity_load_move_mobd(v1, v5);
    v1->sprite->x_speed = v1->stats->speed * _4731A8_speeds[__47CFC4_mobd_lookup_speeds[v5 + 1]] >> 6;
    v1->sprite->y_speed = -entity_get_mobd_speed_y(v1);

    v1->mode = v1->mode_arrive;
}

//----- (004188F0) --------------------------------------------------------
void script_4188F0(Script *a1)
{
    Entity *v1; // esi@1
    int v2; // ebp@1
    int v3; // ebx@1
    Sprite *v4; // edi@1
    Sprite *v5; // eax@2
    DrawJob *v6; // eax@8
    unsigned int v7; // ecx@8
    int v8; // eax@11
    int v9; // ecx@11
    int v10; // eax@11
    int v11; // ecx@14
    int v12; // edx@14

    v1 = (Entity *)a1->param;
    v2 = 0;
    v3 = 4;
    v4 = v1->sprite->parent;
    if (v4)
    {
        v1->_128_spawn_param = (void *)((int)v1->_128_spawn_param + 1);
    }
    else
    {
        v5 = sprite_create(MOBD_CURSORS, 0, v1->sprite);
        v4 = v5;
        if (v5)
        {
            v5->drawjob->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_448680;
            sprite_load_mobd(v5, CURSOR_MOBD_OFFSET_REPAIR);
            v4->z_index = 0;
            v4->_60_mobd_anim_speed = 0;
            v1->sprite->parent = v4;
            v1->_128_spawn_param = (void *)1;
        }
    }
    while (!v1->destroyed)
    {
        if (v3 >= 10)
        {
            v6 = v4->drawjob;
            v3 = 0;
            v7 = v6->flags & 0xBFFFFFFF;
            goto LABEL_10;
        }
        if (++v3 == 5)
        {
            v6 = v4->drawjob;
            v7 = v6->flags | 0x40000000;
        LABEL_10:
            v6->flags = v7;
        }
        v8 = v1->hitpoints + 5;
        v1->hitpoints = v8;
        v9 = v8;
        v10 = v1->stats->hitpoints;
        if (v9 >= v10)
            v1->hitpoints = v10;
        entity_410710_status_bar(v1);
        script_445370_yield_to_main_thread(a1, 0x80000000, 1);
        if (++v2 >= 600)
            break;
    }
    v11 = v1->destroyed;
    v12 = (int)v1->_128_spawn_param - 1;
    v1->_128_spawn_param = (void *)v12;
    if (v11 || v4 && !v12)
    {
        if (v4)
        {
            sprite_list_remove(v4);
            v1->sprite->parent = 0;
        }
    }
    script_yield(a1);
}

//----- (00418A10) --------------------------------------------------------
void script_418A10(Script *a1)
{
    Entity *v1; // esi@1
    int v2; // ebx@1
    int v3; // ebp@1
    Sprite *v4; // edi@1
    Sprite *v5; // eax@2
    int v6; // ebp@5
    DrawJob *v7; // eax@9
    unsigned int v8; // ecx@9
    int v9; // eax@12
    int v10; // ecx@12
    int v11; // eax@12
    int v12; // edx@15
    int v13; // [sp+10h] [bp-4h]@1

    v1 = (Entity *)a1->param;
    v2 = 4;
    v3 = (int)v1->state;
    v13 = v3;
    v4 = *(Sprite **)(v3 + 32);
    if (v4)
    {
        ++*(_DWORD *)(v3 + 36);
    }
    else
    {
        v5 = sprite_create(MOBD_CURSORS, 0, v1->sprite);
        v4 = v5;
        if (v5)
        {
            v5->drawjob->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_448680;
            sprite_load_mobd(v5, CURSOR_MOBD_OFFSET_REPAIR);
            v4->z_index = 0;
            v4->_60_mobd_anim_speed = 0;
            *(_DWORD *)(v3 + 32) = (int)v4;
            *(_DWORD *)(v3 + 36) = 1;
        }
    }
    v6 = 0;
    while (!v1->destroyed)
    {
        if (v2 >= 10)
        {
            v7 = v4->drawjob;
            v2 = 0;
            v8 = v7->flags & 0xBFFFFFFF;
            goto LABEL_11;
        }
        if (++v2 == 5)
        {
            v7 = v4->drawjob;
            v8 = v7->flags | 0x40000000;
        LABEL_11:
            v7->flags = v8;
        }
        v9 = v1->hitpoints + 5;
        v1->hitpoints = v9;
        v10 = v9;
        v11 = v1->stats->hitpoints;
        if (v10 >= v11)
            v1->hitpoints = v11;
        entity_410520_update_healthbar_color(v1);
        script_445370_yield_to_main_thread(a1, 0x80000000, 1);
        if (++v6 >= 600)
            break;
    }
    v12 = *(_DWORD *)(v13 + 36) - 1;
    *(_DWORD *)(v13 + 36) = v12;
    if (v1->destroyed || v4 && !v12)
    {
        if (v4)
        {
            sprite_list_remove(v4);
            *(_DWORD *)(v13 + 32) = 0;
        }
    }
    script_yield(a1);
}

//----- (00418B30) --------------------------------------------------------
void entity_mode_418B30(Entity *a1)
{
    Entity *v1; // esi@1
    Entity *v2; // eax@1
    int v3; // eax@2
    Sprite *v4; // edi@4
    int v5; // eax@4
    int v6; // ebp@4
    int v7; // ecx@4
    int v8; // ecx@7
    int v9; // ecx@8
    Entity *v10; // eax@11
    int v11; // ecx@12
    int v12; // ecx@14
    UnitAttachmentPoint *v13; // eax@14
    Script *v15; // edi@19
    enum SOUND_ID v16; // ecx@21
    Script *v17; // edx@26
    __int16 v18; // ax@27
    Script *v20; // eax@28
    int v21; // [sp-Ch] [bp-1Ch]@21

    v1 = a1;
    v2 = a1->_E0_current_attack_target;
    if (!v2 || (v3 = v2->entity_id) == 0 || v3 != a1->_E0_current_attack_target_entity_id)
    {
        v20 = a1->script;
        a1->destroyed = 1;
        v20->script_type = SCRIPT_TYPE_INVALID;
        a1->entity_id = 0;
    LABEL_29:
        sprite_list_remove(v1->sprite);
        script_yield(v1->script);
        entity_list_remove(v1);
        return;
    }
    v4 = a1->sprite;
    v5 = a1->sprite_x;
    v6 = v4->x;
    v7 = v4->x - v5;
    if (v7 <= 0)
        v7 = v5 - v6;
    if (v7 >= 512 || ((v8 = v1->sprite_y, v4->y - v8 <= 0) ? (v9 = v8 - v4->y) : (v9 = v4->y - v8), v9 >= 512))
    {
        v18 = _42D560_get_mobd_lookup_id_rotation(v5 - v6, v1->sprite_y - v4->y);
        entity_load_move_mobd(v1, v18);
        v1->sprite->x_speed = v1->stats->speed * _4731A8_speeds[__47CFC4_mobd_lookup_speeds[v18 + 1]] >> 6;
        v1->sprite->y_speed = -entity_get_mobd_speed_y(v1);
        return;
    }
    script_trigger_event_group(v1->script, EVT_SHOW_UI_CONTROL, v1, SCRIPT_TYPE_39030);
    v10 = v1->_E0_current_attack_target;
    if (v10)
    {
        v11 = v10->entity_id;
        if (v11)
        {
            if (v11 == v1->_E0_current_attack_target_entity_id)
            {
                v12 = 0;
                v13 = v10->stats->attach;
                if (v13 && v13->dmg_source)
                    v12 = 1;
                if (!v12)
                {
                    v15 = script_create_coroutine(SCRIPT_TYPE_INVALID, script_418A10, 0);
                }
                else
                {
                    v15 = script_create_coroutine(SCRIPT_TYPE_INVALID, script_4188F0, 0);
                }
                if (v1->player_side == player_side)
                {
                    if (v1->unit_id == UNIT_STATS_SURV_TECHNICIAN)
                    {
                        v16 = SOUND_28_technician;
                        v21 = _4690A8_unit_sounds_volume;
                    }
                    else
                    {
                        v21 = _4690A8_unit_sounds_volume;
                        v16 = SOUND_108_mekanik;
                    }
                    sound_play(v16, 0, v21, 16, 0);
                }
                if (v15)
                    v15->param = v1->_E0_current_attack_target;
                v17 = v1->script;
                v1->destroyed = 1;
                v17->script_type = SCRIPT_TYPE_INVALID;
                v1->entity_id = 0;
                goto LABEL_29;
            }
        }
    }
}

//----- (00418D20) --------------------------------------------------------
void entity_mode_418D20(Entity *a1)
{
    Entity *v1; // esi@1
    Entity *v2; // eax@1
    int v3; // eax@2
    Sprite *v4; // edi@4
    int v5; // eax@4
    int v6; // ebp@4
    int v7; // ecx@4
    int v8; // ecx@7
    int v9; // ecx@8
    Script *v10; // ecx@11
    __int16 v11; // ax@12
    UnitStat *v12; // ecx@12
    Script *v13; // eax@13

    v1 = a1;
    v2 = a1->_E0_current_attack_target;
    if (v2 && (v3 = v2->entity_id) != 0 && v3 == a1->_E0_current_attack_target_entity_id)
    {
        v4 = a1->sprite;
        v5 = a1->sprite_x;
        v6 = v4->x;
        v7 = v4->x - v5;
        if (v7 <= 0)
            v7 = v5 - v6;
        if (v7 >= 512 || ((v8 = v1->sprite_y, v4->y - v8 <= 0) ? (v9 = v8 - v4->y) : (v9 = v4->y - v8), v9 >= 512))
        {
            v11 = _42D560_get_mobd_lookup_id_rotation(v5 - v6, v1->sprite_y - v4->y);
            v12 = v1->stats;
            entity_load_move_mobd(v1, v11);
            v1->sprite->x_speed = v1->stats->speed * _4731A8_speeds[__47CFC4_mobd_lookup_speeds[v11 + 1]] >> 6;
            v1->sprite->y_speed = -entity_get_mobd_speed_y(v1);
            return;
        }
        script_trigger_event(v1->script, EVT_MSG_SABOTAGE, v1, v1->_E0_current_attack_target->script);
        v10 = v1->script;
        v1->destroyed = 1;
        script_trigger_event_group(v10, EVT_SHOW_UI_CONTROL, v1, SCRIPT_TYPE_39030);
        v1->script->script_type = SCRIPT_TYPE_INVALID;
        v1->entity_id = 0;
    }
    else
    {
        v13 = a1->script;
        a1->destroyed = 1;
        v13->script_type = SCRIPT_TYPE_INVALID;
        a1->entity_id = 0;
    }
    sprite_list_remove(v1->sprite);
    script_yield(v1->script);
    entity_list_remove(v1);
}

//----- (00418E90) --------------------------------------------------------
void entity_mode_418E90(Entity *a1)
{
    Entity *v1; // esi@1
    char *v2; // eax@1
    Entity *v3; // eax@2
    int v4; // ecx@3

    v1 = a1;
    v2 = (char *)a1->_128_spawn_param;
    a1->_128_spawn_param = v2 - 1;
    if ((int)v2 <= 0)
    {
        a1->script->event_handler = a1->event_handler;
        a1->sprite->x_speed = 0;
        a1->sprite->y_speed = 0;
        v3 = a1->_E0_current_attack_target;
        if (v3)
        {
            v4 = v3->entity_id;
            if (v4)
            {
                if (v4 == v1->_E0_current_attack_target_entity_id && v3->script->script_type == SCRIPT_REPAIR_STATION_HANDLER)
                    *((_DWORD *)v3->state + 2) = 0;
            }
        }
        if (v1->_DC_order == 1)
        {
            v1->_E0_current_attack_target = 0;
            v1->_E4_prev_attack_target = 0;
            v1->_134_param__unitstats_after_mobile_outpost_plant = 600;
            v1->mode = entity_mode_move_attack;
        }
        else
        {
            entity_load_idle_mobd(v1);
            v1->mode_return = entity_mode_415540_infantry;
            entity_mode_416A70_oiltanker(v1);
        }
    }
    script_445370_yield_to_main_thread(v1->script, 0x80000000, 1);
}

//----- (00418F60) --------------------------------------------------------
void entity_mode_418F60(Entity *a1)
{
    Entity *v1; // esi@1
    Sprite *v2; // ecx@1
    Entity *v3; // eax@1
    int v4; // ecx@2
    EntityTurret *v5; // eax@4

    v1 = a1;
    a1->script->event_handler = EventHandler_419E80;
    v2 = a1->sprite;
    v1->mode = entity_mode_418E90;
    v2->x_speed = -64;
    v1->sprite->y_speed = 64;
    entity_load_move_mobd(v1);
    v3 = v1->_E0_current_attack_target;
    v1->_128_spawn_param = (void *)100;
    if (v3)
    {
        v4 = v3->entity_id;
        if (v4)
        {
            if (v4 == v1->_E0_current_attack_target_entity_id)
            {
                v5 = v3->turret;
                if (v5)
                    v5->turret_sprite->_60_mobd_anim_speed = 0;
            }
        }
    }
}

//----- (00418FE0) --------------------------------------------------------
void entity_mode_418FE0(Entity *a1)
{
    Entity *v1; // esi@1
    int v2; // ebp@1
    Entity *v3; // eax@1
    int v4; // ecx@2
    int v5; // edi@4
    enum UNIT_ID v6; // eax@7
    enum PLAYER_SIDE v7; // ecx@11
    int v8; // ebx@12
    int v9; // eax@20
    Sprite *v10; // ecx@21
    Entity *v11; // eax@21
    int v12; // ecx@22
    EntityTurret *v13; // eax@24

    v1 = a1;
    v2 = 1;
    v3 = a1->_E0_current_attack_target;
    if (!v3 || (v4 = v3->entity_id) == 0 || v4 != v1->_E0_current_attack_target_entity_id)
    {
        v1->hitpoints = 0;
        v1->destroyed = 1;
        v1->mode = entity_419560_on_death;
        entity_check_special_mission_death_conditions(v1);
        goto LABEL_27;
    }
    v5 = *((_DWORD *)v3->state + 1);
    if (v5 < 4 || v5 > 5)
        v2 = 5 - v5;
    v6 = v1->unit_id;
    if (v6 == UNIT_STATS_SURV_TANKER || v6 == UNIT_STATS_MUTE_TANKER)
        entity_410640_tanker_status_bar(v1);
    else
        entity_410710_status_bar(v1);
    v7 = v1->player_side;
    if (v7 == player_side)
    {
        v8 = game_globals_per_player.cash[v7];
        if (v8 > 0)
        {
            if (v5 < 4 || v5 > 5)
            {
                if (!(v1->hitpoints % 10))
                {
                LABEL_18:
                    game_globals_per_player.cash[v7] = v8 - 1;
                    goto LABEL_19;
                }
            }
            else if (!(v1->hitpoints % (20 * (v5 - 3))))
            {
                goto LABEL_18;
            }
        LABEL_19:
            script_trigger_event(v1->script, EVT_MSG_1510, v1, task_mobd17_cursor);
            goto LABEL_20;
        }
    }
LABEL_20:
    v9 = v1->stats->hitpoints;
    if (v1->hitpoints >= v9)
    {
        v1->hitpoints = v9;
        v1->script->event_handler = EventHandler_419E80;
        v10 = v1->sprite;
        v1->mode = entity_mode_418E90;
        v10->x_speed = -64;
        v1->sprite->y_speed = 64;
        entity_load_move_mobd(v1);
        v11 = v1->_E0_current_attack_target;
        v1->_128_spawn_param = (void *)100;
        if (v11)
        {
            v12 = v11->entity_id;
            if (v12)
            {
                if (v12 == v1->_E0_current_attack_target_entity_id)
                {
                    v13 = v11->turret;
                    if (v13)
                        v13->turret_sprite->_60_mobd_anim_speed = 0;
                }
            }
        }
    }
LABEL_27:
    script_445370_yield_to_main_thread(v1->script, 0x80000000, 4 * v2);
}

//----- (00419180) --------------------------------------------------------
void entity_mode_419180(Entity *a1)
{
    Entity *v1; // esi@1
    Entity *v2; // eax@1
    int v3; // eax@2
    char *v4; // eax@4
    UnitStat *v6; // edx@5

    v1 = a1;
    a1->script->event_handler = EventHandler_419E80;
    v2 = a1->_E0_current_attack_target;
    if (v2 && (v3 = v2->entity_id) != 0 && v3 == a1->_E0_current_attack_target_entity_id)
    {
        v4 = (char *)a1->_128_spawn_param;
        a1->_128_spawn_param = v4 - 1;
        if ((int)v4 <= 0)
        {
            a1->sprite->x_speed = 0;
            a1->sprite->y_speed = 0;
            v6 = a1->stats;
            a1->mode = entity_mode_418FE0;
            entity_load_idle_mobd(a1);
            v1->script->event_handler = EventHandler_419DF0;
        }
    }
    else
    {
        a1->sprite->x_speed = 0;
        a1->sprite->y_speed = 0;
        a1->mode_return = entity_mode_415540_infantry;
        entity_mode_416A70_oiltanker(a1);
        v1->script->event_handler = v1->event_handler;
    }
    script_445370_yield_to_main_thread(v1->script, 0x80000000, 1);
}

//----- (00419230) --------------------------------------------------------
void entity_mode_419230(Entity *a1)
{
    Entity *v1; // esi@1
    int *v2; // edi@1
    Entity *v3; // eax@2

    v1 = a1;
    v2 = &a1->current_mobd_lookup_idx;
    a1->sprite->x_speed = 0;
    a1->sprite->y_speed = 0;
    entity_load_idle_mobd(a1);
    if (!entity_advance_mobd_rotation(v2, 160, v1->stats->turning_speed))
    {
        v1->sprite->x_speed = 64;
        v1->sprite->y_speed = -64;
        sprite_4272E0_load_mobd_item(
            v1->sprite,
            v1->stats->mobd_lookup_offset_move,
            _47D3C4_entity_mobd_lookup_ids[*v2 + 1]);
        v3 = v1->_E0_current_attack_target;
        v1->_128_spawn_param = (void *)100;
        v1->_DC_order = ENTITY_ORDER_0;
        v1->mode = entity_mode_419180;
        *((_DWORD *)v3->state + 2) = 1;
        v1->event_handler = v1->script->event_handler;
    }
    script_445370_yield_to_main_thread(v1->script, 0x80000000, 1);
}

//----- (004192F0) --------------------------------------------------------
char *entity_4192F0(Entity *a1)
{
    Entity *v1; // esi@1
    char *result; // eax@1
    EntityOilTankerState *v3; // edx@1
    Entity *v4; // eax@2
    int v5; // ecx@2
    int v6; // edi@2
    int v7; // ecx@2
    Sprite *v8; // edx@2
    int v9; // eax@2
    Sprite *v10; // ecx@2

    v1 = a1;
    entity_load_idle_mobd(a1);
    result = 0;
    v1->sprite->x_speed = 0;
    v1->sprite->y_speed = 0;
    v3 = (EntityOilTankerState *)v1->state;
    v1->mode = entity_mode_419390_oiltanker;
    if (v3)
    {
        v4 = v3->_4_entity;
        v5 = v4->stru60.ptr_14;
        v6 = *(_DWORD *)(v5 + 4);
        v7 = *(_DWORD *)(v5 + 8);
        v4->sprite->field_88_unused = 1;
        v8 = v3->_4_entity->sprite;
        v9 = v7 + v8->y;
        v10 = v1->sprite;
        result = (char *)(v9 >> 13);
        if (!((v10->x ^ (v6 + v8->x)) & 0xFFFFE000) && (char *)(v10->y >> 13) == result)
            result = entity_40DEC0_boxd(v1, v1->sprite_map_x, v1->sprite_map_y, v1->field_A4);
    }
    return result;
}

//----- (00419390) --------------------------------------------------------
void entity_mode_419390_oiltanker(Entity *a1)
{
    Entity *v1; // edi@1
    EntityOilTankerState *v2; // ecx@1
    Entity *v3; // eax@1
    int v4; // esi@3
    int v5; // eax@4

    v1 = a1;
    v2 = (EntityOilTankerState *)a1->state;
    v3 = v2->_4_entity;
    if (v3 && v3->entity_id == v2->_18_entity_id)
    {
        v4 = (int)v3->state;
        entity_40DF50_boxd_update_map_tile(v1, 0);
        if (!v4 || (v5 = *(_DWORD *)(v4 + 24)) != 0 && *(_DWORD *)(v5 + 304) == *(_DWORD *)(v4 + 28))
        {
            script_445370_yield_to_main_thread(v1->script, 0x80000000, 30);
        }
        else
        {
            *(_DWORD *)(v4 + 24) = (int)v1;
            *(_DWORD *)(v4 + 28) = v1->entity_id;
            entity_mode_move_attack(v1);
        }
    }
    else if (v3 == v2->drillrig)
    {
        v1->mode = entity_mode_4448C0_oiltanker;
    }
    else
    {
        v1->mode = entity_mode_4447C0_oiltanker;
    }
}

//----- (00419420) --------------------------------------------------------
void entity_mode_move_tanker(Entity *a1)
{
    Entity *v1; // esi@1
    void(*v2)(Entity *); // eax@1
    int v3; // edx@1
    Sprite *v4; // ecx@1
    UnitStat *v5; // eax@4
    int v6; // eax@5
    int v7; // edi@7
    UnitStat *v8; // eax@7
    int v9; // eax@8
    Sprite *v10; // ebx@10
    int v11; // ecx@10
    int v12; // eax@10
    int v13; // edx@10
    int v14; // eax@11
    int v15; // eax@14
    int v16; // eax@15
    __int16 v17; // ax@19
    UnitStat *v18; // ecx@19
    int v19; // [sp-4h] [bp-10h]@1

    v1 = a1;
    v2 = a1->mode;
    v3 = a1->stats->mobd_lookup_offset_move;
    v19 = _47D3C4_entity_mobd_lookup_ids[a1->current_mobd_lookup_idx + 1];
    v4 = a1->sprite;
    if (v2 == entity_mode_move_tanker)
    {
        sprite_4273B0_load_mobd_item_sound(v4, v3, v19);
    }
    else
    {
        entity_load_move_mobd(a1);
        v1->mode = entity_mode_move_tanker;
    }
    v5 = v1->stats;
    if (v5->is_infantry)
        v6 = entity_40F0A0_get_dx(v1, v1->field_A4);
    else
        v6 = v5->field_4C != 128 ? 7424 : 4096;
    v7 = v6 + (v1->sprite_map_x << 13);
    v8 = v1->stats;
    if (v8->is_infantry)
        v9 = entity_40F100_get_dy(v1, v1->field_A4);
    else
        v9 = v8->field_4C != 128 ? 7424 : 4096;
    v10 = v1->sprite;
    v11 = v9 + (v1->sprite_map_y << 13);
    v12 = v10->x;
    v13 = v7 - v12;
    if (v7 - v12 <= 0)
        v14 = v12 - v7;
    else
        v14 = v7 - v12;
    if (v14 >= 768 || ((v15 = v10->y, v11 - v15 <= 0) ? (v16 = v15 - v11) : (v16 = v11 - v15), v16 >= 768))
    {
        v17 = _42D560_get_mobd_lookup_id_rotation(v13, v11 - v10->y);
        v18 = v1->stats;
        v1->current_mobd_lookup_idx = v17;
        v1->sprite->x_speed = v18->speed * _4731A8_speeds[__47CFC4_mobd_lookup_speeds[v17 + 1]] >> 6;
        v1->sprite->y_speed = -entity_get_mobd_speed_y(v1);
    }
    else
    {
        entity_mode_move_attack(v1);
    }
}

//----- (00419560) --------------------------------------------------------
void entity_419560_on_death(Entity *a1)
{
    Entity *v1; // esi@1
    Script *v2; // eax@1
    EntityTurret *v3; // eax@1
    UnitStat *v4; // edx@3
    signed __int64 v5; // rax@5
    int v6; // ecx@5
    int v7; // edx@7
    int v8; // ST04_4@10
    int v9; // eax@10
    Sprite *v10; // eax@12
    int v11; // [sp-8h] [bp-10h]@5

    v1 = a1;
    v2 = a1->script;
    a1->destroyed = 1;
    v2->field_24 &= 0xEFFFFFFF;
    script_trigger_event(a1->script, EVT_SHOW_UI_CONTROL, 0, task_mobd17_cursor);
    v3 = v1->turret;
    if (v3)
    {
        sprite_list_remove(v3->turret_sprite);
        script_deinit(v1->turret->sprite_task);
        script_free_local_object(v1->script, v1->turret);
        v1->turret = 0;
    }
    script_trigger_event_group(v1->script, EVT_SHOW_UI_CONTROL, v1, SCRIPT_TYPE_39030);
    v1->script->script_type = SCRIPT_TYPE_INVALID;
    v1->sprite->x_speed = 0;
    v1->sprite->y_speed = 0;
    v4 = v1->stats;
    v1->mode = entity_419720;
    if (v4->is_infantry)
    {
        if (v1->_98_465610_accuracy_dmg_bonus_idx)
        {
            v11 = _4690A8_unit_sounds_volume;
            v5 = kknd_rand_debug(__FILE__, __LINE__);
            v6 = 6;
        }
        else
        {
            v11 = _4690A8_unit_sounds_volume;
            v5 = kknd_rand_debug(__FILE__, __LINE__);
            v6 = 5;
        }
        sprite_408800_play_sound(v1->sprite, _465988_sounds[(unsigned __int64)(v5 % v6)], v11, 0);
        v1->sprite->mobd_id = MOBD_EXPLOSIONS;
        v7 = SPRITE_EXPLOSION_MOBD_OFFSET_UNIT_SURV_RIFLEMAN_DEATH;
        if (v1->stats->player_side != 1)
        {
            v7 = SPRITE_EXPLOSION_MOBD_OFFSET_UNIT_MUTE_BERSERKER_DEATH;
        }
    LABEL_11:
        sprite_load_mobd(v1->sprite, v7);
        entity_438D90_on_death_explosion(v1);
        goto LABEL_15;
    }
    if (v1->unit_id == UNIT_STATS_MUTE_DIRE_WOLF)
    {
        v8 = _4690A8_unit_sounds_volume;
        v9 = kknd_rand_debug(__FILE__, __LINE__);
        sprite_408800_play_sound(v1->sprite, _465988_sounds[v9 % 5], v8, 0);
        v1->sprite->mobd_id = MOBD_MUTE_DIRE_WOLF;
        v7 = SPRITE_DIRE_WOLF_MOBD_OFFSET_DEATH;
        goto LABEL_11;
    }
    v10 = entity_439120_add_explosion(v1);
    if (v10)
        v10->z_index = v1->sprite->z_index + 256;
    entity_438D90_on_death_explosion(v1);
    entity_load_idle_mobd(v1);

LABEL_15:
    script_445370_yield_to_main_thread(v1->script, 0x80000000, 60);
}

//----- (00419720) --------------------------------------------------------
void entity_419720(Entity *a1)
{
    Entity *v1; // esi@1

    v1 = a1;
    entity_40DEC0_boxd(a1, a1->sprite_map_x, a1->sprite_map_y, a1->field_A4);
    sprite_list_remove(v1->sprite);
    script_yield(v1->script);
    entity_list_remove(v1);
}

//----- (00419760) --------------------------------------------------------
void entity_mode_419760_infantry_destroyed(Entity *a1)
{
    a1->sprite->x_speed = 0;
    a1->sprite->y_speed = 0;
    entity_load_move_mobd(a1);

    a1->mode = entity_mode_4197E0_infantry;
    a1->destroyed = 1;
    script_trigger_event_group(a1->script, EVT_SHOW_UI_CONTROL, a1, SCRIPT_TYPE_39030);
    entity_40DEC0_boxd(a1, a1->sprite_map_x, a1->sprite_map_y, a1->field_A4);
    a1->script->event_handler = EventHandler_General_Scout;
}

//----- (004197E0) --------------------------------------------------------
void entity_mode_4197E0_infantry(Entity *a1)
{
    Entity *v1; // esi@1
    Sprite *v3; // ecx@1

    v1 = a1;
    a1->sprite->x_speed = 0;
    a1->sprite->y_speed = 0;
    v3 = a1->sprite;
    entity_load_move_mobd(a1, a1->current_mobd_lookup_idx + 64);
    script_445370_yield_to_main_thread(v1->script, 0x10000000, 0);
}

//----- (00419830) --------------------------------------------------------
void EventHandler_Infantry(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param)
{
    Entity *v4; // esi@1
    Entity *v5; // eax@15
    Script *v6; // ecx@15
    stru11unit *v7; // eax@16
    Entity *v8; // eax@26
    UnitStat *v9; // ebx@34
    int v10; // edi@34
    int v11; // ecx@34
    bool v12; // zf@34
    int v13; // ecx@38
    int v14; // ecx@38
    int v15; // edx@38

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
        case EVT_ENTITY_ATTACK:
            entity_attack(v4, (_47CAF0_task_attachment1_attack_task *)param);
            break;
        case EVT_MSG_1528:
            entity_41A890_evt1528(v4);
            break;
        case EVT_MSG_1525:
            entity_41A060_evt1525(v4, param);
            break;

        case EVT_ENTITY_MOVE:
            entity_move(v4, (_47CAF0_task_attachment1_move_task *)param);
            break;

        case EVT_MSG_1526_infiltrate:                        // param -> Entity *
            if (param != v4->_E0_current_attack_target || v4->_DC_order != ENTITY_ORDER_3)
            {
                script_445370_yield_to_main_thread(v4->script, 0x80000000, 1);
                v4->_DC_order = ENTITY_ORDER_3;
                v4->_E0_current_attack_target = (Entity *)param;
                v4->_E0_current_attack_target_entity_id = *((_DWORD *)param + 76);// ->entity_id
                v4->_E4_prev_attack_target = 0;
                v4->_134_param__unitstats_after_mobile_outpost_plant = 600;
                v4->mode_arrive = entity_mode_418D20;
                v4->entity_8 = 0;
                entity_mode_move_attack(v4);
            }
            break;
        case EVT_MSG_1527:
            if (v4->player_side == *(_DWORD *)param && (Entity *)*((_DWORD *)param + 1) != v4->_E8_entity)
            {
                script_445370_yield_to_main_thread(v4->script, 0x80000000, 1);
                v4->_DC_order = ENTITY_ORDER_5;
                v5 = (Entity *)*((_DWORD *)param + 1);
                v4->_E8_entity = v5;
                v4->_E8_entity_id = v5->entity_id;
                v6 = v4->script;
                v4->_E4_prev_attack_target = 0;
                v4->_134_param__unitstats_after_mobile_outpost_plant = 600;
                script_trigger_event(v6, EVT_MSG_1507_stru11, v4, v5->script);
                v4->entity_8 = 0;
                entity_mode_move_attack(v4);
            }
            break;
        case EVT_MSG_1507_stru11:
            v7 = stru11unit_list_head;
            if (stru11unit_list_head)
                stru11unit_list_head = stru11unit_list_head->next;
            else
                v7 = 0;
            v7->next = v4->stru11_list_104;
            v7->prev = (stru11unit *)&v4->stru11_list_104;
            v4->stru11_list_104->prev = v7;
            v4->stru11_list_104 = v7;
            v7->param = param;
            break;
        case EVT_MSG_1508:
            if (v4->_DC_order != 5 || v4->_E8_entity != param)
            {
                script_trigger_event(v4->script, EVT_MSG_1509_stru11, v4, *((Script **)param + 3));
            }
            else if (!v4->_E0_current_attack_target && !v4->entity_8)
            {
                v4->_E0_current_attack_target = (Entity *)*((_DWORD *)param + 70);
                v4->_E0_current_attack_target_entity_id = *(_DWORD *)(*((_DWORD *)param + 70) + 304);
                entity_mode_move_attack(v4);
            }
            break;
        case EVT_MSG_1509_stru11:
            v8 = (Entity *)v4->stru11_list_104;
            if ((stru11unit **)v8 != &v4->stru11_list_104)
            {
                while (v8->entity_8 != param)
                {
                    v8 = v8->next;
                    if ((stru11unit **)v8 == &v4->stru11_list_104)
                        return;
                }
                v8->entity_8 = 0;
            }
            break;
        case EVT_MSG_1499:
            script_445370_yield_to_main_thread(v4->script, 0x80000000, 1);
            v4->hitpoints = 0;
            v4->destroyed = 1;
            v4->mode = entity_419560_on_death;
            entity_check_special_mission_death_conditions(v4);
            break;
        case EVT_MSG_DAMAGE:
            entity_41A610_evt1503(v4, param);
            entity_410710_status_bar(v4);
            break;
        case EVT_MSG_1497:
            entity_41A6D0_evt1497(v4, (Entity *)param);
            break;
        case EVT_MSG_1505:
            v9 = v4->stats;
            v10 = (int)param + v4->field_94;
            v4->field_94 = v10;
            v11 = v4->_98_465610_accuracy_dmg_bonus_idx;
            v4->_98_465610_accuracy_dmg_bonus_idx = v11 + v10 / v9->hitpoints;
            v12 = v4->_98_465610_accuracy_dmg_bonus_idx == v11;
            v4->field_94 = v10 % v9->hitpoints;
            if (!v12)
                entity_410710_status_bar(v4);
            if (v4->_98_465610_accuracy_dmg_bonus_idx >= 3)
                v4->_98_465610_accuracy_dmg_bonus_idx = 2;
            break;
        case EVT_MSG_1546_repair_at_station:
            script_445370_yield_to_main_thread(v4->script, 0x80000000, 1);
            v4->_DC_order = ENTITY_ORDER_10;
            v4->_E0_current_attack_target = (Entity *)param;
            v13 = *((_DWORD *)param + 76);
            v4->_E4_prev_attack_target = 0;
            v4->_E0_current_attack_target_entity_id = v13;
            v4->_134_param__unitstats_after_mobile_outpost_plant = 600;
            v4->mode_arrive = entity_mode_419230;
            *(_DWORD *)(*((_DWORD *)param + 23) + 136) = 1;
            v4->sprite_x_2 = *(_DWORD *)(*((_DWORD *)param + 23) + 16) + *(_DWORD *)(*((_DWORD *)param + 29) + 4);
            v14 = *(_DWORD *)(*((_DWORD *)param + 29) + 8);
            v15 = *(_DWORD *)(*((_DWORD *)param + 23) + 20);
            v4->entity_8 = 0;
            v4->sprite_y_2 = v15 + v14;
            entity_40DF50_boxd_update_map_tile(v4, 1);
            v4->mode = entity_mode_move_attack;
            break;
        case EVT_MSG_1547_technician_repair:
            entity_41A400_evt1547(v4, (Entity *)param);
            break;
        default:
            return;
        }
    }
}

//----- (00419CA0) --------------------------------------------------------
void EventHandler_419CA0(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param)
{
    Entity *v4; // ecx@1

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
        case EVT_MSG_DAMAGE:
            entity_41A610_evt1503(v4, param);
            break;
        default:
            return;
        }
    }
}

//----- (00419D20) --------------------------------------------------------
void EventHandler_General_Scout(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param)
{
    Entity *v4; // esi@1
    Entity *v5; // eax@4

    v4 = (Entity *)receiver->param;
    switch (event)
    {
    case EVT_ENTITY_MOVE:
        entity_41A9B0_unit(v4, (int)param);
        break;
    case EVT_ENTITY_ATTACK:
        if (v4->player_side == *(_DWORD *)param)
        {
            LOWORD_HEXRAYS(v4->field_2A4) = 2;
            v5 = (Entity *)*((_DWORD *)param + 1);
            v4->_2A8_entity = v5;
            v4->_2A8_entity_id = v5->entity_id;
        }
        break;
    case EVT_MSG_1511_sidebar_click_category:
        entity_410CB0_event1511(v4);
        break;
    case EVT_SHOW_UI_CONTROL:
        entity_410CD0_eventTextString(v4);
        break;
    case EVT_MSG_SHOW_UNIT_HINT:
        entity_show_hint(v4);
        break;
    case EVT_MSG_DAMAGE:
        entity_41A610_evt1503(v4, param);
        entity_410710_status_bar(v4);
        break;
    default:
        return;
    }
}
