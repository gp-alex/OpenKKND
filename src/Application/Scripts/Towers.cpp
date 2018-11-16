#include "src/_unsorted_data.h"
#include "src/kknd.h"
#include "src/Map.h"
#include "src/Pathfind.h"
#include "src/RenderDrawHandlers.h"
#include "src/Script.h"
#include "src/ScriptEvent.h"
#include "src/Sprite.h"
#include "src/stru31.h"

#include "src/Engine/Entity.h"
#include "src/Engine/EntityFactory.h"

using Engine::EntityFactory;

#include "src/Engine/Infrastructure/EntityRepository.h"

using Engine::Infrastructure::EntityRepository;



//----- (00447380) --------------------------------------------------------
void UNIT_Handler_GuardTower(Script *a1)
{
    UNIT_Handler_Towers(a1);
}

//----- (00447390) --------------------------------------------------------
void UNIT_Handler_Towers(Script *a1)
{
    Entity *v1; // esi@2
    Entity *v2; // eax@3
    DataMobdItem_stru1 *v3; // eax@3
    int i; // ecx@4

    if (_47C6DC_dont_execute_unit_handlers)
        return;
    v1 = (Entity *)a1->param;
    if (v1)
    {
    LABEL_15:
        v1->ExecMode();
        return;
    }
    v2 = EntityFactory().Create(a1);
    v1 = v2;
    v2->script->event_handler = EventHandler_Towers;
    entity_load_idle_mobd(v2);
    v3 = v1->sprite->_54_inside_mobd_ptr4->field_18;
    if (v3)
    {
        for (i = v3->field_0; i != -1; v3 = (DataMobdItem_stru1 *)((char *)v3 + 16))
        {
            if (i == 3)
                v1->stru60.ptr_C = v3;
            i = v3->field_10;
        }
    }
    entity_40DD00_boxd(v1);
    v1->sprite->x = map_point_to_tile_global(v1->sprite->x + v1->stru60.ptr_C->x_offset) - v1->stru60.ptr_C->x_offset + 4096;
    v1->sprite->y = map_point_to_tile_global(v1->sprite->y + v1->stru60.ptr_C->y_offset) - v1->stru60.ptr_C->y_offset + 4096;
    map_reveal_fog_around_entity(v1);
    entity_set_draw_handlers(v1);
    if (v1->player_side == player_side)
        ++num_players_towers;
    if (v1->sprite->cplc_ptr1_pstru20)
    {
        entity_mode_4478E0_towers(v1);
        v1->SetMode(entity_mode_4474D0_towers);
        goto LABEL_15;
    }
    if (v1->player_side == player_side)
        script_trigger_event(v1->script, EVT_MSG_NEXT_CONSTRUCTION_STATE, v1, game_cursor_script);
    sprite_4272E0_load_mobd_item(v1->sprite, v1->stats->mobd_lookup_offset_attack, 0);
    v1->SetMode(entity_mode_4474E0_towers);
    v1->ExecMode();
}

//----- (004474D0) --------------------------------------------------------
void entity_mode_4474D0_towers(Entity *a1)
{
    dword_477358 = 1123344;
}
// 477358: using guessed type int dword_477358;

//----- (004474E0) --------------------------------------------------------
void entity_mode_4474E0_towers(Entity *a1)
{
    dword_477358 = 908793;
}
// 477358: using guessed type int dword_477358;

//----- (004474F0) --------------------------------------------------------
void entity_mode_tower_on_death(Entity *a1)
{
    Entity *v1; // esi@1
    Sprite *v2; // eax@1
    EntityTurret *v3; // eax@3
    Script *v4; // ecx@5
    Script *v5; // ST00_4@5

    v1 = a1;
    v2 = entity_439120_add_explosion(a1);
    if (v2)
        v2->z_index = v1->sprite->z_index + 256;
    v3 = v1->turret;
    if (v3)
        v3->handler = (void(*)(EntityTurret *))nullsub_1;
    v4 = v1->script;
    v1->destroyed = 1;
    v1->entity_id = 0;
    script_trigger_event(v4, EVT_MSG_DESELECTED, 0, game_cursor_script);
    script_trigger_event_group(v1->script, EVT_MSG_DESELECTED, v1, SCRIPT_TYPE_39030);
    v1->script->script_type = SCRIPT_TYPE_INVALID;
    v5 = v1->script;
    v1->SetMode(entity_mode_tower_dead);
    script_sleep(v5, 60);
}

//----- (00447580) --------------------------------------------------------
void entity_mode_tower_dead(Entity *a1)
{
    Entity *v1; // esi@1
    EntityTurret *v2; // eax@1
    Script *v3; // ecx@6

    v1 = a1;
    v2 = a1->turret;
    if (v2)
    {
        v2->turret_sprite->param = 0;
        sprite_list_remove(a1->turret->turret_sprite);
        script_terminate(v1->turret->sprite_task);
        v1->turret = 0;
    }
    if (v1->player_side == player_side && num_players_towers > 0)
        --num_players_towers;
    entity_40DDD0_boxd(v1);
    sprite_list_remove(v1->sprite);
    v3 = v1->script;
    v1->sprite = 0;
    script_terminate(v3);
    entityRepo->Delete(v1);
}

void tower_on_attacked(Entity *e, Entity *attacker) {
    //quick fix - TODO - find out why retaliation_target is NULL
    if (e->retaliation_target == 0) 
    {
        return;
    }
    auto v5 = e->retaliation_target;
    int v6 = v5->entity_id;
    if (!v5 || v6 == 0 || v6 != e->retaliation_target_id)
    {
        auto v7 = &e->turret->sprite_task;
        if (v7)
        {
            e->retaliation_target = attacker;
            e->retaliation_target_id = attacker->entity_id;
            script_trigger_event(e->script, EVT_CMD_ENTITY_ATTACK, 0, *v7);
        }
    }
}

//----- (00447600) --------------------------------------------------------
void EventHandler_Towers(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param)
{
    Entity *v4; // esi@1
    Entity *v5; // eax@11
    int v6; // eax@12
    Script **v7; // eax@14

    v4 = (Entity *)receiver->param;
    if (!v4->destroyed)
    {
        switch (event)
        {
        case EVT_MSG_NEXT_CONSTRUCTION_STATE:
            if (v4->IsMode(entity_mode_4474E0_towers))
            {
                if (param == (void *)1)
                {
                    sprite_4272E0_load_mobd_item(v4->sprite, v4->stats->mobd_lookup_offset_attack, 1);
                }
                else if (param == (void *)2)
                {
                    sprite_4272E0_load_mobd_item(v4->sprite, v4->stats->mobd_lookup_offset_attack, 2);
                }
                else if (param == (void *)3)
                {
                    entity_load_idle_mobd(v4);
                    entity_mode_4478E0_towers(v4);
                    script_trigger_event_group(v4->script, EVT_MSG_1551, 0, SCRIPT_TYPE_CA000012);
                    v4->SetMode(entity_mode_4474D0_towers);
                }
            }
            break;
        case EVT_CMD_ENTITY_ATTACK:
            tower_attack(v4, (int)param);
            break;
        case MSG_ATTACKED:
            tower_on_attacked(v4, (Entity *)param);
            break;
        case EVT_MSG_SELECTED:
            entity_selected_default(v4);
            break;
        case EVT_MSG_DESELECTED:
            entity_deselected_default(v4);
            break;
        case EVT_MSG_SHOW_UNIT_HINT:
            entity_show_hint(v4);
            break;
        case EVT_MSG_DESTROY:
            entity_402E40_destroy(v4, entity_mode_tower_on_death);
            break;
        case CMD_APPLY_DAMAGE:
            entity_402E90_on_damage(v4, param, entity_mode_tower_on_death);
            entity_410710_status_bar(v4);
            break;
        default:
            return;
        }
    }
}

//----- (004477B0) --------------------------------------------------------
void tower_attack(Entity *a1, int a2)
{
    Entity *v2; // esi@1
    int v3; // edi@1
    enum PLAYER_SIDE v4; // ecx@2
    Entity *v5; // eax@3
    int v6; // edx@4
    int v7; // eax@4
    int v8; // eax@8

    v2 = a1;
    v3 = a2;
    if (a1->turret)
    {
        v4 = a1->player_side;
        if (*(_DWORD *)a2 == v4)
        {
            v5 = *(Entity **)(a2 + 4);
            if (v5->entity_id != v2->retaliation_target_id)
            {
                v2->retaliation_target = v5;
                v2->retaliation_target_id = v5->entity_id;
                v6 = *(_DWORD *)(a2 + 4);
                v7 = *(_DWORD *)(v6 + 20);
                if (v7 && v7 != v4 && !is_enemy(v4, (Entity *)v6))
                {
                    if (!single_player_game)
                    {
                        v8 = *(_DWORD *)(*(_DWORD *)(v3 + 4) + 20);
                        if (player_side == v8 || player_side == v2->player_side)
                        {
                            sprintf(
                                netz_47CA30,
                                aAllegianceBroken,
                                netz_47A740[v8 + 1].player_name,
                                netz_47A740[v2->player_side + 1].player_name);
                            show_message_ex(0, netz_47CA30);
                        }
                    }
                    if (!_47C6D8_use__466098_cost_multipliers)
                    {
                        game_globals_cpu[0].cash[v2->player_side + 7 * *(_DWORD *)(*(_DWORD *)(v3 + 4) + 20)] = 0;
                        game_globals_cpu[0].cash[7 * v2->player_side + *(_DWORD *)(*(_DWORD *)(v3 + 4) + 20)] = 0;
                    }
                }
                script_trigger_event(v2->script, EVT_CMD_ENTITY_ATTACK, 0, v2->turret->sprite_task);
            }
        }
    }
}
// 468B5C: using guessed type int single_player_game;

//----- (004478E0) --------------------------------------------------------
void entity_mode_4478E0_towers(Entity *a1)
{
    Entity *v1; // ebx@1
    EntityTurret *v2; // esi@3
    Sprite *v3; // eax@4
    enum PLAYER_SIDE v4; // eax@4
    Script *v5; // eax@6
    UnitAttachmentPoint *v6; // eax@6
    Script *v7; // eax@6

    v1 = a1;
    if (a1->stats->attach)
    {
        if (!a1->turret)
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
                v4 = v1->player_side;
                if (v4)
                {
                    v2->turret_sprite->drawjob->job_details.palette = per_player_sprite_palettes[player_sprite_color_by_player_side[v4]];
                    v2->turret_sprite->drawjob->flags |= 0x10000000u;
                }
                v5 = v2->turret_sprite->script;
                v2->sprite_task = v5;
                v5->param = v2;
                v2->turret_sprite->param = v2;
                v2->entity = v1;
                v2->mobd_lookup_id = v1->GetCurrentAnimFrame();
                v6 = v1->stats->attach;
                v2->SetHandler(EntityTowerAttachment_handler_447C40);
                v2->stats_attachment_point = v6;
                v2->field_18 = 0;
                v2->field_2C = 0;
                v2->field_1C = v6->volley_size;
                v2->field_20 = v6->reload2_time;
                v1->turret = v2;
                v7 = v2->sprite_task;
                v2->field_34 = 0;
                v7->event_handler = MessageHandler_TowersAttachment;
            }
        }
    }
}


//----- (004479D0) --------------------------------------------------------
void UNIT_AttachHandler_Turret(Script *a1)
{
    EntityTurret *v1; // esi@1
    int v2; // eax@1

    v1 = (EntityTurret *)a1->param;
    (v1->handler)(v1);
    v2 = v1->field_18;
    if (v2)
        v1->field_18 = v2 - 1;
}

//----- (004479F0) --------------------------------------------------------
int EntityTowerAttachment_4479F0(EntityTurret *a1)
{
    EntityTurret *v1; // ebx@1
    Entity *v2; // eax@1
    UnitStat *v3; // ecx@1
    Sprite *v4; // eax@1
    int v5; // ecx@1
    int v6; // esi@1
    int v7; // ebp@1
    int v8; // eax@1
    int v9; // edx@1
    int v10; // ecx@5
    DataBoxd_stru0_per_map_unit *v11; // edi@7
    int v12; // eax@7
    int v13; // ebp@9
    Entity **v14; // edi@9
    Entity *v15; // esi@12
    UnitStat *v16; // eax@12
    int v17; // eax@15
    Entity *v18; // ecx@15
    bool v19; // sf@19
    unsigned __int8 v20; // of@19
    int v21; // eax@20
    int result; // eax@22
    stru31 *v23; // edi@23
    Entity *v24; // edx@24
    Entity *v25; // esi@26
    int v26; // eax@27
    Entity *v27; // ecx@27
    int v28; // [sp+10h] [bp-20h]@1
    int v29; // [sp+14h] [bp-1Ch]@5
    DataBoxd_stru0_per_map_unit *v30; // [sp+18h] [bp-18h]@7
    int v31; // [sp+1Ch] [bp-14h]@7
    int v32; // [sp+20h] [bp-10h]@1
    Entity *v33; // [sp+24h] [bp-Ch]@1
    int v34; // [sp+28h] [bp-8h]@7
    int v35; // [sp+2Ch] [bp-4h]@5

    v1 = a1;
    v2 = a1->entity;
    v33 = v2;
    v3 = v2->stats;
    v4 = v2->sprite;
    v5 = v3->firing_range >> 5;
    v6 = (v4->x >> 13) - v5;
    v7 = 2 * v5 + 1;
    v8 = (v4->y >> 13) - v5;
    v32 = 2 * v5 + 1;
    v9 = 2 * v5 + 1;
    v28 = v6;
    if (v6 < 0)
    {
        v7 += v6;
        v28 = 0;
        v6 = 0;
        v32 = v7;
    }
    if (v8 < 0)
    {
        v9 += v8;
        v8 = 0;
    }
    v10 = v8;
    v29 = v8;
    v35 = v8 + v9;
    if (v8 < v8 + v9)
    {
        while (v10 < map_get_height())
        {
            v34 = v7 + v6;
            v11 = boxd_get_tile(v6, v10);
            v12 = v6;
            v30 = boxd_get_tile(v6, v10);
            v31 = v6;
            if (v6 < v7 + v6)
            {
                while (2)
                {
                    if (v12 < map_get_width())
                    {
                        v13 = 0;
                        v14 = v11->_4_entities;
                        do
                        {
                            if (*v14 && is_enemy(v33->player_side, *v14))
                            {
                                v15 = *v14;
                                v16 = (*v14)->stats;
                                if ((v16->_54_ai_importance || v16->speed) && !v15->destroyed)
                                {
                                    v17 = math_42D64D_vec_length_2d(
                                        (v1->entity->sprite->x - v15->sprite->x) >> 8,
                                        (v1->entity->sprite->y - v15->sprite->y) >> 8);
                                    v18 = v1->entity;
                                    if (v17 < v18->stats->firing_range)
                                    {
                                        if (entity_41B510(v18, v15))
                                        {
                                            v1->_C_entity = v30->_4_entities[v13];
                                            v1->_C_entity_idx = v30->_4_entities[v13]->entity_id;
                                            return 1;
                                        }
                                    }
                                }
                                v6 = v28;
                            }
                            ++v13;
                            ++v14;
                        } while (v13 < 5);
                        v12 = v31 + 1;
                        v11 = v30 + 1;
                        v20 = __OFSUB__(v31 + 1, v34);
                        v19 = v31++ + 1 - v34 < 0;
                        ++v30;
                        if (v19 ^ v20)
                            continue;
                    }
                    break;
                }
            }
            v21 = v29++ + 1;
            if (v29 >= v35)
                break;
            v7 = v32;
            v10 = v21;
        }
    }
    v23 = stru31_list_477300;
    if ((stru31 **)stru31_list_477300 == &stru31_list_477300)
    {
    LABEL_32:
        result = 0;
    }
    else
    {
        while (1)
        {
            v24 = v23->param__entity__int;
            if (v24)
            {
                if (is_enemy(v33->player_side, v24))
                {
                    v25 = v23->param__entity__int;
                    if (!v25->destroyed)
                    {
                        v26 = math_42D64D_vec_length_2d(
                            (v1->entity->sprite->x - v25->sprite->x) >> 8,
                            (v1->entity->sprite->y - v25->sprite->y) >> 8);
                        v27 = v1->entity;
                        if (v26 < v27->stats->firing_range)
                        {
                            if (entity_41B510(v27, v25))
                                break;
                        }
                    }
                }
            }
            v23 = v23->next;
            if ((stru31 **)v23 == &stru31_list_477300)
                goto LABEL_32;
        }
        v1->_C_entity = v23->param__entity__int;
        result = 1;
        v1->_C_entity_idx = v23->param__entity__int->entity_id;
    }
    return result;
}
// 478AAC: using guessed type int map_get_height();
// 4793F8: using guessed type int map_get_width();

//----- (00447C40) --------------------------------------------------------
void EntityTowerAttachment_handler_447C40(EntityTurret *a1)
{
    EntityTurret *v1; // esi@1
    int v2; // eax@1
    UnitAttachmentPoint *v3; // edx@1
    Script *v4; // ST00_4@2

    v1 = a1;
    v2 = a1->mobd_lookup_id;
    v3 = a1->stats_attachment_point;
    a1->_C_entity_idx = 0;
    sprite_4272E0_load_mobd_item(a1->turret_sprite, v3->mobd_lookup_offset_idle, _47D3C4_entity_mobd_lookup_ids[v2 + 1]);
    if (EntityTowerAttachment_4479F0(v1))
    {
        v4 = v1->sprite_task;
        v1->handler = EntityTowerAttachment_handler_447CA0;
        script_sleep(v4, 1);
    }
    script_sleep(v1->sprite_task, 90);
}

//----- (00447CA0) --------------------------------------------------------
void EntityTowerAttachment_handler_447CA0(EntityTurret *a1)
{
    EntityTurret *v1; // esi@1
    Entity *v2; // eax@1
    int v3; // ecx@2
    Sprite *v4; // ecx@5
    int v5; // ebx@5
    Entity *v6; // ebx@6
    int v7; // eax@7
    Entity *v8; // ecx@7
    UnitAttachmentPoint *v9; // eax@9
    int v10; // [sp-4h] [bp-14h]@9

    v1 = a1;
    v2 = a1->_C_entity;
    if (v2)
        v3 = v2->entity_id == a1->_C_entity_idx;
    else
        v3 = 0;
    if (!v3)
        goto LABEL_15;
    v4 = v1->turret_sprite;
    v1->handler = EntityTowerAttachment_handler_447CA0;
    v5 = (signed __int16)_42D560_get_mobd_lookup_id_rotation(v2->sprite->x - v4->x, v2->sprite->y - v4->y);
    mobd_advance_anim(&v1->mobd_lookup_id, v5, v1->stats_attachment_point->mobd_frame_step);
    sprite_4272E0_load_mobd_item(
        v1->turret_sprite,
        v1->stats_attachment_point->mobd_lookup_offset_idle,
        _47D3C4_entity_mobd_lookup_ids[v1->mobd_lookup_id + 1]);
    if (v1->mobd_lookup_id != v5)
        return;
    v6 = v1->_C_entity;
    if (!v6->destroyed
        && (v7 = math_42D64D_vec_length_2d(
        (v1->entity->sprite->x - v6->sprite->x) >> 8,
            (v1->entity->sprite->y - v6->sprite->y) >> 8),
            v8 = v1->entity,
            v7 < v8->stats->firing_range)
        && entity_41B510(v8, v6))
    {
        v9 = v1->stats_attachment_point;
        v10 = _47D3C4_entity_mobd_lookup_ids[v1->mobd_lookup_id + 1];
        if (v1->entity->unit_id == 57)
        {
            sprite_4272E0_load_mobd_item(v1->turret_sprite, v9->mobd_lookup_offset_attack, v10);
            v1->handler = EntityTowerAttachment_handler_447E20;
        }
        else
        {
            sprite_4272E0_load_mobd_item(v1->turret_sprite, v9->mobd_lookup_offset_idle, v10);
            v1->handler = EntityTowerAttachment_handler_447E20;
        }
    }
    else
    {
    LABEL_15:
        v1->handler = EntityTowerAttachment_handler_447C40;
    }
}

//----- (00447DD0) --------------------------------------------------------
void EntityTowerAttachment_handler_447DD0(EntityTurret *a1)
{
    EntityTurret *v1; // esi@1
    UnitAttachmentPoint *v2; // eax@1
    int v3; // [sp-4h] [bp-8h]@1

    v1 = a1;
    v2 = a1->stats_attachment_point;
    v3 = _47D3C4_entity_mobd_lookup_ids[a1->mobd_lookup_id + 1];
    if (a1->entity->unit_id == UNIT_STATS_MUTE_ROTARY_CANNON)
    {
        sprite_4272E0_load_mobd_item(a1->turret_sprite, v2->mobd_lookup_offset_attack, v3);
        v1->handler = EntityTowerAttachment_handler_447E20;
    }
    else
    {
        sprite_4272E0_load_mobd_item(a1->turret_sprite, v2->mobd_lookup_offset_idle, v3);
        v1->handler = EntityTowerAttachment_handler_447E20;
    }
}

//----- (00447E20) --------------------------------------------------------
void EntityTowerAttachment_handler_447E20(EntityTurret *a1)
{
    EntityTurret *v1; // esi@1
    Entity *v2; // edi@1
    int v3; // eax@2
    int v4; // eax@7
    Entity *v5; // ecx@7
    __int16 v6; // ax@10
    Entity *v7; // ecx@10
    enum UNIT_ID v8; // eax@14

    v1 = a1;
    v2 = a1->_C_entity;
    if (v2)
        v3 = v2->entity_id == a1->_C_entity_idx;
    else
        v3 = 0;
    if (v3)
    {
        if (!v2->destroyed
            && (v4 = math_42D64D_vec_length_2d(
            (a1->entity->sprite->x - v2->sprite->x) >> 8,
                (a1->entity->sprite->y - v2->sprite->y) >> 8),
                v5 = v1->entity,
                v4 < v5->stats->firing_range)
            && entity_41B510(v5, v2))
        {
            v6 = _42D560_get_mobd_lookup_id_rotation(
                v1->_C_entity->sprite->x - v1->turret_sprite->x,
                v1->_C_entity->sprite->y - v1->turret_sprite->y);
            v7 = v1->entity;
            v1->mobd_lookup_id = v6;
            if (v7->unit_id == UNIT_STATS_MUTE_ROTARY_CANNON)
                sprite_4273B0_load_mobd_item_sound(
                    v1->turret_sprite,
                    v1->stats_attachment_point->mobd_lookup_offset_attack,
                    _47D3C4_entity_mobd_lookup_ids[v6 + 1]);
            else
                sprite_4273B0_load_mobd_item_sound(
                    v1->turret_sprite,
                    v1->stats_attachment_point->mobd_lookup_offset_idle,
                    _47D3C4_entity_mobd_lookup_ids[v6 + 1]);
            if (!v1->field_18)
            {
                v8 = v1->entity->unit_id;
                if (v8 != UNIT_STATS_SURV_MISSILE_BATTERY && v8 != UNIT_STATS_MUTE_ROTARY_CANNON)
                    sprite_4272E0_load_mobd_item(
                        v1->turret_sprite,
                        v1->stats_attachment_point->mobd_lookup_offset_attack,
                        _47D3C4_entity_mobd_lookup_ids[v1->mobd_lookup_id + 1]);
                v1->handler = EntityTowerAttachment_handler_447FA0;
                v1->sprite_task->flags_24 &= ~SCRIPT_FLAGS_20_10000000;
            }
        }
        else
        {
            v1->handler = EntityTowerAttachment_handler_447C40;
        }
    }
    else
    {
        a1->handler = EntityTowerAttachment_handler_447C40;
    }
}

//----- (00447F50) --------------------------------------------------------
void EntityTowerAttachment_handler_447F50(EntityTurret *a1)
{
    EntityTurret *v1; // esi@1
    enum UNIT_ID v2; // eax@1

    v1 = a1;
    v2 = a1->entity->unit_id;
    if (v2 != UNIT_STATS_SURV_MISSILE_BATTERY && v2 != UNIT_STATS_MUTE_ROTARY_CANNON)
        sprite_4272E0_load_mobd_item(
            a1->turret_sprite,
            a1->stats_attachment_point->mobd_lookup_offset_attack,
            _47D3C4_entity_mobd_lookup_ids[a1->mobd_lookup_id + 1]);
    v1->handler = EntityTowerAttachment_handler_447FA0;
    v1->sprite_task->flags_24 &= ~SCRIPT_FLAGS_20_10000000;
}

//----- (00447FA0) --------------------------------------------------------
void EntityTowerAttachment_handler_447FA0(EntityTurret *a1)
{
    EntityTurret *v1; // esi@1
    UnitDamageSource *v2; // edi@1
    Sprite *v3; // eax@3
    int v4; // edx@3
    Sprite *v5; // ebx@3
    Script *v6; // ecx@5
    int v7; // eax@5
    UnitAttachmentPoint *v8; // eax@6
    int v9; // ecx@6
    int v10; // edx@6
    int v11; // edx@7
    Entity *v12; // eax@7

    v1 = a1;
    v2 = a1->stats_attachment_point->dmg_source;
    if (v2 && _47C048_num_attack_projectile_sprites < 200)
    {
        ++_47C048_num_attack_projectile_sprites;
        v3 = sprite_create_scripted(v2->mobd_id, a1->turret_sprite, v2->dmg_handler, SCRIPT_COROUTINE, a1->ptr_24);
        v4 = v2->mobd_lookup_offset_flying;
        v5 = v3;
        if (v4 != -1)
            sprite_4272E0_load_mobd_item(v3, v4, _47D3C4_entity_mobd_lookup_ids[v1->mobd_lookup_id + 1]);
        v6 = v5->script;
        v7 = v1->turret_sprite->z_index;
        v5->param = v2;
        v5->z_index = v7 + 768;
        v6->param = v1->_C_entity;
        v5->_80_entity__stru29__sprite__initial_hitpoints = v1->entity;
        v5->field_84 = v1->entity->entity_id;
        v5->field_8C_infantry_damage = LOWORD_HEXRAYS(v2->damage_infantry)
            + (v2->damage_infantry
                * veterancy_damage_bonus[v1->entity->veterancy_level] >> 8);
        v5->field_8E_vehicle_damage = LOWORD_HEXRAYS(v2->damage_vehicle)
            + (v2->damage_vehicle
                * veterancy_damage_bonus[v1->entity->veterancy_level] >> 8);
        v5->field_90_building_damage = LOWORD_HEXRAYS(v2->damage_building)
            + (v2->damage_building
                * veterancy_damage_bonus[v1->entity->veterancy_level] >> 8);
        v5->parent = v1->turret_sprite->parent;
        script_trigger_event(v1->entity->script, MSG_ATTACKED, v1->entity, v1->_C_entity->script);
    }
    v8 = v1->stats_attachment_point;
    v9 = v1->field_1C - 1;
    v10 = v8->reload_time;
    v1->field_1C = v9;
    v1->field_18 = v10;
    if (v9)
    {
        v1->handler = EntityTowerAttachment_handler_447E20;
        EntityTowerAttachment_handler_447E20(v1);
    }
    else
    {
        v1->field_18 = v8->reload2_time + v10;
        v11 = v8->volley_size;
        v12 = v1->entity;
        v1->field_1C = v11;
        if (v12->unit_id == UNIT_STATS_SURV_MISSILE_BATTERY)
            v1->handler = EntityTowerAttachment_handler_4482D0_missile_battery;
        else
            v1->handler = EntityTowerAttachment_handler_448160;
    }
}
// 47C048: using guessed type int _47C048_num_attack_projectile_sprites;

//----- (00448110) --------------------------------------------------------
void EntityTowerAttachment_handler_448110(EntityTurret *a1)
{
    UnitAttachmentPoint *v1; // eax@1
    int v2; // edx@1
    Entity *v3; // edx@2

    v1 = a1->stats_attachment_point;
    a1->field_18 = v1->reload_time;
    v2 = a1->field_1C - 1;
    a1->field_1C = v2;
    if (v2)
    {
        a1->handler = EntityTowerAttachment_handler_447E20;
        EntityTowerAttachment_handler_447E20(a1);
    }
    else
    {
        v3 = a1->entity;
        a1->field_18 += v1->reload2_time;
        a1->field_1C = v1->volley_size;
        if (v3->unit_id == UNIT_STATS_SURV_MISSILE_BATTERY)
            a1->handler = EntityTowerAttachment_handler_4482D0_missile_battery;
        else
            a1->handler = EntityTowerAttachment_handler_448160;
    }
}

//----- (00448160) --------------------------------------------------------
void EntityTowerAttachment_handler_448160(EntityTurret *a1)
{
    EntityTurret *v1; // esi@1
    Entity *v2; // eax@1
    int v3; // ecx@2
    __int16 v4; // ax@6
    Entity *v5; // ecx@6
    UnitAttachmentPoint *v6; // ecx@9
    int v7; // [sp-4h] [bp-10h]@9

    v1 = a1;
    v2 = a1->_C_entity;
    if (v2)
        v3 = v2->entity_id == a1->_C_entity_idx;
    else
        v3 = 0;
    if (v3)
    {
        v4 = _42D560_get_mobd_lookup_id_rotation(v2->sprite->x - v1->turret_sprite->x, v2->sprite->y - v1->turret_sprite->y);
        v5 = v1->entity;
        v1->mobd_lookup_id = v4;
        if (v5->unit_id != UNIT_STATS_MUTE_ROTARY_CANNON)
            sprite_4272E0_load_mobd_item(
                v1->turret_sprite,
                v1->stats_attachment_point->mobd_lookup_offset_idle,
                _47D3C4_entity_mobd_lookup_ids[v4 + 1]);
        if (!v1->field_18)
        {
            v6 = v1->stats_attachment_point;
            v7 = _47D3C4_entity_mobd_lookup_ids[v1->mobd_lookup_id + 1];
            if (v1->entity->unit_id == UNIT_STATS_MUTE_ROTARY_CANNON)
            {
                sprite_4272E0_load_mobd_item(v1->turret_sprite, v6->mobd_lookup_offset_attack, v7);
                v1->handler = EntityTowerAttachment_handler_447E20;
            }
            else
            {
                sprite_4272E0_load_mobd_item(v1->turret_sprite, v6->mobd_lookup_offset_idle, v7);
                v1->handler = EntityTowerAttachment_handler_447E20;
            }
        }
    }
    else
    {
        v1->handler = EntityTowerAttachment_handler_447C40;
    }
}

//----- (00448230) --------------------------------------------------------
void EntityTowerAttachment_handler_448230(EntityTurret *a1)
{
    EntityTurret *v1; // esi@1
    Entity *v2; // eax@1
    int v3; // eax@2

    v1 = a1;
    sprite_4272E0_load_mobd_item(
        a1->turret_sprite,
        a1->stats_attachment_point->mobd_lookup_offset_attack,
        _47D3C4_entity_mobd_lookup_ids[129]);
    script_yield(v1->sprite_task, SCRIPT_FLAGS_20_10000000, 0);
    v2 = v1->_C_entity;
    if (v2)
        v3 = v2->entity_id == v1->_C_entity_idx;
    else
        v3 = 0;
    if (v3)
        v1->handler = EntityTowerAttachment_handler_447DD0;
    else
        v1->handler = EntityTowerAttachment_handler_447C40;
}

//----- (00448290) --------------------------------------------------------
void EntityTowerAttachment_handler_448290(EntityTurret *a1)
{
    EntityTurret *v1; // esi@1
    char *v2; // edi@1

    v1 = a1;
    v2 = (char *)&a1->mobd_lookup_id;
    if (!mobd_advance_anim(&a1->mobd_lookup_id, 160, a1->stats_attachment_point->mobd_frame_step))
        v1->handler = EntityTowerAttachment_handler_448230;
    sprite_4272E0_load_mobd_item(
        v1->turret_sprite,
        v1->stats_attachment_point->mobd_lookup_offset_idle,
        _47D3C4_entity_mobd_lookup_ids[*(_DWORD *)v2 + 1]);
}

//----- (004482D0) --------------------------------------------------------
void EntityTowerAttachment_handler_4482D0_missile_battery(EntityTurret *a1)
{
    EntityTurret *v1; // esi@1
    Script *v2; // eax@1

    v1 = a1;
    sprite_4272E0_load_mobd_item(
        a1->turret_sprite,
        a1->stats_attachment_point->mobd_lookup_offset_idle,
        _47D3C4_entity_mobd_lookup_ids[a1->mobd_lookup_id + 1]);
    v2 = v1->sprite_task;
    v1->handler = EntityTowerAttachment_handler_448290;
    script_sleep(v2, 15);
}

//----- (00448320) --------------------------------------------------------
void MessageHandler_TowersAttachment(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param)
{
    EntityTurret *v4; // eax@1
    Entity *v5; // ecx@1

    v4 = (EntityTurret *)receiver->param;
    v5 = v4->entity;
    if (!v5->destroyed && event == EVT_CMD_ENTITY_ATTACK)
    {
        v4->handler = EntityTowerAttachment_handler_447CA0;
        v4->_C_entity = v5->retaliation_target;
        v4->_C_entity_idx = v5->retaliation_target->entity_id;
    }
}


//----- (004010B0) --------------------------------------------------------
void UNIT_AttachHandler_DockPoint(Script *self)
{
    auto turret = (EntityTurret *)self->param;
    (turret->handler)(turret);
}

//----- (004010C0) --------------------------------------------------------
void EntityTowerAttachment_handler_4010C0(EntityTurret *a1)
{
    int v1; // eax@1

    v1 = a1->entity->GetCurrentAnimFrame();
    a1->mobd_lookup_id = v1;
    sprite_4272E0_load_mobd_item(
        a1->turret_sprite,
        a1->stats_attachment_point->mobd_lookup_offset_idle,
        _47D3C4_entity_mobd_lookup_ids[v1 + 1]);
}

//----- (004010E0) --------------------------------------------------------
void EntityTowerAttachment_handler_4010E0(EntityTurret *a1)
{
    EntityTurret *v1; // esi@1

    v1 = a1;
    sprite_4272E0_load_mobd_item(
        a1->turret_sprite,
        a1->stats_attachment_point->mobd_lookup_offset_idle,
        _47D3C4_entity_mobd_lookup_ids[a1->mobd_lookup_id + 1]);
    v1->SetHandler(EntityTowerAttachment_handler_4010C0);
}
