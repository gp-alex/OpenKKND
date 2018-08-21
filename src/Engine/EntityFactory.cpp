#include "src/Engine/EntityFactory.h"

#include "src/_unsorted_data.h"
#include "src/kknd.h"
#include "src/ScriptEvent.h"
#include "src/stru31.h"
#include "src/Map.h"
#include "src/Pathfind.h"

#include "src/Engine/Infrastructure/EntityRepository.h"

using Engine::EntityFactory;
using Engine::Infrastructure::EntityRepository;

//----- (0044C6B0) --------------------------------------------------------
Entity *EntityFactory::Create(Script *a1)
{
    Entity *v1; // esi@1
    Sprite *v2; // edx@1
    int v5; // eax@7
    enum PLAYER_SIDE v10; // eax@18
    Entity *v13; // ecx@22

    //v1 = entity_list_get();
    v1 = new Entity();
    if (!v1)
        return 0;

    memset(v1, 0, sizeof(Entity));
    v2 = a1->sprite;
    if (v2->cplc_ptr1)
    {
        v5 = v2->cplc_ptr1->script_handler_id;

        if (get_script_type(v5) == 3) {
            // Prison, Prison, Outpost, Clannhall
            v1->unit_id = get_script_unit_id(v5);
            v1->player_side = (PLAYER_SIDE)v2->cplc_ptr1_pstru20->param_24;
        }
        else
        {
            v1->unit_id = get_script_unit_id(v5);
            v1->player_side = (PLAYER_SIDE)v2->cplc_ptr1_pstru20->param_18;
            if (v1->_12C_prison_bunker_spawn_type = LOWORD_HEXRAYS(v2->cplc_ptr1_pstru20->param_1C))
                v1->field_124 |= 0x80;
        }
    }
    else
    {
        if ((int)v2->param & 0x8000)
        {
            v1->_12C_prison_bunker_spawn_type = 2;
            v1->field_124 = v1->field_124 | 0x80;
        }
        v1->unit_id = (UNIT_ID)((unsigned int)v2->param & 0x7FFF);
        v1->player_side = (PLAYER_SIDE)((int)v2->param >> 16);
    }

    v10 = v1->player_side;
    if (v10 == player_side)
    {
        ++UNIT_num_player_units;
    }
    else if (v10)
    {
        ++UNIT_num_nonplayer_units;
    }
    v1->field_110 = 0;
    v1->stru11_list_108 = (stru11unit *)&v1->stru11_list_104;
    v1->experience = 0;
    v1->stru11_list_104 = (stru11unit *)&v1->stru11_list_104;
    v1->veterancy_level = 0;
    v1->entity_id = ++_47DCC4_entity_id_counter;
    v1->SetMode(nullptr);
    v1->mode_idle = 0;
    v1->mode_arrive = 0;
    v1->mode_attacked = 0;
    v1->sprite = v2;
    v1->script = a1;
    a1->script_type = SCRIPT_TYPE_60138_ENTITY_SCRIPTS;
    a1->param = v1;
    a1->event_handler = MessageHandler_EntityScript;
    v2->param = v1;
    v1->stats = &unit_stats[v1->unit_id];
    v1->SetCurrentAnimFrame(128);
    v1->hitpoints = v1->stats->hitpoints;
    v1->field_78 = 0;

    memset32(&v1->stru60, (int)&entity_default_stru60_ptr, 6u);

    v2->drawjob->job_details.palette = per_player_sprite_palettes[player_sprite_color_by_player_side[v1->player_side]];
    v2->drawjob->flags |= 0x10000000u;

    script_trigger_event_group(a1, EVT_MSG_1521_entity_created, v1, SCRIPT_TYPE_39030);

    entityRepo->Save(v1);
    return v1;
}



//----- (0041DAA0) --------------------------------------------------------
Entity *EntityFactory::Unpack(EntitySerialized *save_data)
{
    EntitySerialized *v2; // ebp@1
    unsigned int v5; // eax@6
    int result; // eax@8
    unsigned int v7; // ecx@12
    int v8; // ecx@14
    int v9; // eax@19
    EntityTurret *v10; // edi@20
    unsigned int v11; // eax@21
    unsigned int v12; // ecx@27
    int v13; // ecx@29
    enum UNIT_ID v14; // eax@34
    unsigned int v20; // eax@56
    int(*v21)(int); // eax@58
    unsigned int v22; // eax@60
    void(*v23)(Entity *); // eax@62
    unsigned int v24; // eax@64
    int(*v25)(int); // eax@66
    unsigned int v26; // eax@68
    void(*v27)(Entity *); // eax@70
    unsigned int v28; // eax@72
    void(*v29)(Entity *); // eax@74
    unsigned int v30; // eax@76
    void(*v31)(Script *, Script *, enum SCRIPT_EVENT, void *); // eax@78
    int v40; // eax@100
    int *v41; // esi@100
    char v42; // dl@101
    char *v43; // esi@103
    char *v50; // edx@120
    int v51; // esi@120
    int v52; // edi@120
    Sprite *v55; // eax@128
    void *v56; // esi@132
    enum UNIT_ID v57; // eax@134
    OilDeposit *v58; // eax@136
    int v59; // ecx@136
    int v60; // eax@143
    enum UNIT_ID v61; // ecx@143
    int v64; // edx@153
    int k; // edi@155
    Script *v66; // eax@156
    enum UNIT_ID v67; // eax@159
    unsigned int v68; // eax@162
    void(*v69)(Script *); // edx@164
    Script *v70; // edi@167
    Script *v71; // eax@168
    unsigned int v72; // ecx@169
    void(*v73)(Script *, Script *, enum SCRIPT_EVENT, void *); // ecx@171
    int v74; // esi@177
    unsigned int v75; // eax@178
    int v76; // eax@180
    DataMobdItem_stru1 *v79; // ecx@189
    int v80; // eax@190
    DataMobdItem_stru1 *v81; // ecx@195
    int i; // eax@196
    int j; // esi@200
    Script *v84; // eax@201
    EntityTurret *v85; // ebx@209
    int v86; // [sp-8h] [bp-1Ch]@128
    int *a2a; // [sp+10h] [bp-4h]@148

    v2 = save_data;
    auto v3 = new Entity();
    v3->entity_8 = entityRepo->FindById(save_data->id);
    v5 = save_data->entity_task_handler_idx - 1;
    auto _handler = get_handler(v5);
    if (_handler)
    {
        result = (int)script_create_function(save_data->entity_task_event, (void(*)(Script *))_handler);
        if (result)
        {
            v7 = v2->entity_task_message_handler_idx - 1;
            v8 = (int)get_handler(v7);
            *(_DWORD *)(result + 52) = v8;
            *(_DWORD *)(result + 32) = v2->entity_task_field_20;
            *(_DWORD *)(result + 20) = v2->entity_task_field_14;
            *(_DWORD *)(result + 36) = v2->entity_task_field_24;
            *(_DWORD *)(result + 40) = v2->entity_task_field_28;
            *(_DWORD *)(result + 44) = v2->entity_task_field_2C;
        }
    }
    v3->script = (Script *)result;
    if (result)
    {
        result = (int)GAME_Load_UnpackSprite(&v2->entity_sprite);
        v3->sprite = (Sprite *)result;
        if (result)
        {
            v3->script->sprite = (Sprite *)result;
            v3->sprite->script = v3->script;
            v3->sprite->param = v3;
            v3->script->param = v3;
            v3->unit_id = v2->unit_stats_idx;
            v9 = v2->player_side;
            v3->player_side = (PLAYER_SIDE)v9;
            v3->sprite->drawjob->job_details.palette = per_player_sprite_palettes[player_sprite_color_by_player_side[v9]];
            v3->sprite->drawjob->flags |= 0x10000000u;
            v3->stats = &unit_stats[v3->unit_id];
            if (v2->turret_sprite_task_handler_idx)
            {
                result = (int)script_create_local_object(v3->script, 56);
                v10 = (EntityTurret *)result;
                if (!result)
                    return delete v3, nullptr;
                v3->turret = (EntityTurret *)result;
                *(_DWORD *)(result + 8) = (int)v3;
                *(_DWORD *)(result + 40) = (int)v3->stats->attach;
                v11 = v2->turret_sprite_task_handler_idx - 1;
                auto _handler = get_handler(v11);
                if (_handler)
                {
                    result = (int)script_create_function(v2->turret_sprite_task_event, (void(*)(Script *))_handler);
                    if (result)
                    {
                        v12 = v2->turret_sprite_task_message_handler_idx - 1;
                        v13 = (int)get_handler(v12);
                        *(_DWORD *)(result + 52) = v13;
                        *(_DWORD *)(result + 32) = v2->turret_sprite_task_field_20;
                        *(_DWORD *)(result + 20) = v2->turret_sprite_task_field_14;
                        *(_DWORD *)(result + 36) = v2->turret_sprite_task_field_24;
                        *(_DWORD *)(result + 40) = v2->turret_sprite_task_field_28;
                        *(_DWORD *)(result + 44) = v2->turret_sprite_task_field_2C;
                    }
                }
                v10->sprite_task = (Script *)result;
                if (!result)
                    return delete v3, nullptr;
                result = (int)GAME_Load_UnpackSprite(&v2->turret_sprite);
                v10->turret_sprite = (Sprite *)result;
                if (!result)
                    return delete v3, nullptr;
                v10->sprite_task->sprite = (Sprite *)result;
                v10->turret_sprite->script = v10->sprite_task;
                v10->sprite_task->param = v10;
                v10->turret_sprite->param = v10;
                v10->turret_sprite->drawjob->job_details.palette = per_player_sprite_palettes[player_sprite_color_by_player_side[v3->player_side]];
                v10->turret_sprite->drawjob->flags |= 0x10000000u;
                v14 = v3->unit_id;
                if (v14 == 44 || v14 == 43)
                    v10->turret_sprite->drawjob->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_448580_entity_aircraft_turret;
                else
                    v10->turret_sprite->drawjob->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_44BDC0_entity_turret;
                v10->turret_sprite->parent = v3->sprite;
                v10->_C_entity = entityRepo->FindById(v2->turret_C_entity_id);

                v10->handler = (void(*)(EntityTurret *))get_handler(v2->turret_mode - 1);
                if (!v10->handler)
                    return delete v3, nullptr;
                v10->mobd_lookup_id = v2->turret_mobd_lookup_id;
                v10->field_18 = v2->turret_field_18;
                v10->field_1C = v2->turret_field_1C;
                v10->field_20 = v2->turret_field_20;
                v10->field_2C = v2->turret_field_2C;
                v10->_C_entity_idx = v2->turret_entity__or__C_entity_id;
                v10->field_34 = v2->turret_field_34;
            }
            else
            {
                v3->turret = 0;
            }

            EntityMode m = (void(*)(Entity *))get_handler(v2->entity_mode - 1);
            if (!m)
                return delete v3, nullptr;
            v3->SetMode(m);

            v20 = v2->entity_mode_idle;
            v3->mode_idle = (void(*)(Entity *))get_handler(v20 - 1);

            v22 = v2->entity_mode_arrive;
            v3->mode_arrive = (void(*)(Entity *))get_handler(v22 - 1);

            v24 = v2->entity_mode_attacked;
            v3->mode_attacked = (void(*)(Entity *))get_handler(v24 - 1);

            v26 = v2->entity_mode_return;
            v3->mode_return = (void(*)(Entity *))get_handler(v26 - 1);

            v28 = v2->entity_mode_turn_return;
            v3->mode_turn_return = (void(*)(Entity *))get_handler(v28 - 1);

            v30 = v2->entity_message_handler_idx;
            v3->event_handler = (void(*)(Script *, Script *, enum SCRIPT_EVENT, void *))get_handler(v30 - 1);

            memset(&v3->_24_ai_node_per_player_side, 0, sizeof(v3->_24_ai_node_per_player_side));
            memset32(&v3->stru60, (int)&entity_default_stru60_ptr, 6u);
            v3->field_78 = v2->entity_field_78;
            v3->SetCurrentAnimFrame(v2->entity_mobd_idx);
            v3->field_80 = v2->entity_field_80;
            v3->field_84 = v2->entity_field_84;
            v3->_88_dst_orientation = v2->entity_field_88;
            v3->destroyed = 0;
            v3->hitpoints = v2->entity_hitpoints;
            v3->experience = v2->entity_field_94;
            v3->veterancy_level = v2->entity_98_veterancy_damage_bonus_idx;
            v3->_9C_hp_regen_condition = v2->entity_9C_hp_regen_condition;
            v3->_A0_hp_regen_condition = v2->entity_A0_hp_regen_condition;
            v3->_A4_idx_in_tile = v2->field_A4;
            v3->sprite_map_x = v2->entity_sprite_width_shr13;
            v3->sprite_map_y = v2->entity_sprite_height_shr13;
            v3->sprite_x = v2->entity_sprite_width;
            v3->sprite_y = v2->entity_sprite_height;
            v3->_B8_move_dst_x = v2->field_B8;
            v3->_B8_move_dst_y = v2->field_BC;
            v3->_C0_mobd_anim_speed_related = v2->field_C0;
            v3->field_C4 = v2->field_C4;
            v3->field_C8 = v2->field_C8;
            v3->field_CC = v2->field_CC;
            v3->field_D0 = v2->field_D0;
            v3->field_D4 = v2->field_D4;
            v3->field_D8 = v2->field_D8;
            v3->_DC_order = (ENTITY_ORDER)v2->field_DC;

            v3->retaliation_target = entityRepo->FindById(v2->entity_EC_outpost_clanhall_entity_id);
            v3->_E4_prev_attack_target = entityRepo->FindById(v2->entity_E4_entity_id);
            v3->_E8_entity = 0;
            v3->retaliation_target_id = v2->retaliation_target_id;
            v3->_E4_prev_attack_target_entity_id = v2->_E4_prev_attack_target_entity_id;
            v3->entity_118_entity_id = v2->entity_F4_entity_118_entity_id;
            v3->_E8_entity_id = 0;
            v3->sprite_x_2 = v2->entity_sprite_width_2;
            v3->sprite_y_2 = v2->entity_sprite_height_2;
            v3->stru11_list_104 = (stru11unit *)&v3->stru11_list_104;
            v3->stru11_list_108 = (stru11unit *)&v3->stru11_list_104;
            v3->field_110 = 0;
            v3->entity_118 = entityRepo->FindById(v2->entity_entity_118_entity_id);
            v3->_11C__infantry_sprite_y___drillrig_oil_spot = v2->entity_field_11C;
            v3->_120__infantry_sprite_x = v2->entity_field_120;
            v3->field_124 = v2->entity_field_124;
            v3->_128_spawn_param = (void *)v2->entity_field_128;
            v3->_12C_prison_bunker_spawn_type = v2->entity_field_12C;
            v3->_134_param__unitstats_after_mobile_outpost_plant = v2->entity_field_134;
            v3->field_138 = v2->entity_field_138;
            v3->field_13C = v2->entity_field_13C;
            v3->field_140 = v2->entity_field_140;
            v3->field_144 = v2->entity_field_144;
            v3->field_148 = v2->entity_field_148;
            v3->field_14C = v2->entity_field_14C;
            v3->field_150 = v2->entity_field_150;
            v3->field_154 = v2->entity_field_154;
            v3->field_158 = v2->entity_field_158;
            memcpy(v3->_15C_waypoints_xs, v2->entity_array_15C, sizeof(v3->_15C_waypoints_xs));
            memcpy(v3->_15C_waypoints_ys, v2->entity_array_184, sizeof(v3->_15C_waypoints_ys));
            memcpy(v3->_1AC_waypoints_xs, v2->entity_array_1AC, sizeof(v3->_1AC_waypoints_xs));
            memcpy(v3->_1AC_waypoints_ys, v2->entity_array_1D4, sizeof(v3->_1AC_waypoints_ys));
            memcpy(v3->_1FC_waypoints_xs, v2->entity_array_1FC, sizeof(v3->_1FC_waypoints_xs));
            memcpy(v3->_1FC_waypoints_ys, v2->entity_array_224, sizeof(v3->_1FC_waypoints_ys));
            memcpy(&v3->pathing, v2->entity_array_24C, sizeof(v3->pathing));

            v3->entity_27C = entityRepo->FindById(v2->entity_27C_entity_id);
            v3->entity_27C_entity_id = v2->entity_27C_entity_id_2;
            v40 = 0;
            v41 = v2->entity_array_294;
            do
            {
                v42 = *(_BYTE *)v41;
                ++v41;
                v3->array_294[v40++] = v42;
            } while (v40 < 7);
            LOWORD_HEXRAYS(v3->field_29C) = v2->entity_array_294[7];
            HIWORD_HEXRAYS(v3->field_29C) = HIWORD_HEXRAYS(v2->entity_array_294[7]);
            LOWORD_HEXRAYS(v3->field_2A0) = v2->field_2E8;
            HIWORD_HEXRAYS(v3->field_2A0) = v2->field_2EA;
            switch (v3->unit_id)
            {
            case 0x17u:
            case 0x18u:
                v43 = (char *)&v2->field_2EC;
                if (v2->field_2EC == -67108864)
                {
                    v3->state = 0;
                    entity_set_draw_handlers(v3);
                    v3->sprite->field_88_unused = 1;
                    v55 = v3->sprite;
                    v86 = v55->y;
                LABEL_207:
                    map_place_entity(v3, v55->x, v86, 0);
                    goto LABEL_208;
                }
                result = (int)script_create_local_object(v3->script, 116);
                if (result)
                {
                    v3->state = (void *)result;
                    *(_DWORD *)result = *(_DWORD *)v43;
                    *(Entity **)(result + 4) = entityRepo->FindById(v2[1].id);
                    *(Entity **)(result + 8) = entityRepo->FindById((int)v2[1].entity_task_event);
                    *(Entity **)(result + 12) = entityRepo->FindById(v2[1].entity_task_handler_idx);
                    *(_DWORD *)(result + 16) = v2[1].entity_task_message_handler_idx;
                    *(_DWORD *)(result + 20) = v2[1].entity_task_field_20;
                    *(_DWORD *)(result + 24) = v2[1].entity_task_field_14;
                    *(_DWORD *)(result + 28) = v2[1].entity_task_field_24;
                    v50 = (char *)(result + 32);
                    v51 = (int)&v43[-result];
                    v52 = 20;
                    while (1)
                    {
                        *(Entity **)v50 = entityRepo->FindById(*(_DWORD *)&v50[v51]);
                        v50 += 4;
                        if (!--v52)
                        {
                            entity_oil_tanker_initialize_state(v3);
                            goto LABEL_131;
                        }
                    }
                }
                return delete v3, nullptr;
            case 0x19u:
                result = (int)script_create_local_object(v3->script, 12);
                if (!result)
                    return delete v3, nullptr;
                v3->state = (void *)result;
                *(_DWORD *)result = v2->field_2EC;
                *(_DWORD *)(result + 4) = v2[1].id;
                *(_DWORD *)(result + 8) = v2[1].entity_task_event;
                entity_set_draw_handlers(v3);
            LABEL_131:
                v3->sprite->field_88_unused = 1;
                v55 = v3->sprite;
                v86 = v55->y;
                goto LABEL_207;
            case 0x2Eu:
            case 0x2Fu:
            case 0x30u:
            case 0x31u:
            case 0x32u:
            case 0x33u:
            case 0x3Au:
            case 0x3Bu:
            case 0x3Cu:
            case 0x3Du:
            case 0x3Eu:
            case 0x3Fu:
            case 0x40u:
            case 0x41u:
            case 0x42u:
                v56 = script_create_local_object(v3->script, 40);
                if (!v56)
                    return delete v3, nullptr;
                v57 = v3->unit_id;
                v3->state = v56;
                if (v57 != 46 && v57 != 47)
                    goto LABEL_143;
                v58 = oilspot_list_head;
                v59 = 0;
                if ((OilDeposit **)oilspot_list_head == &oilspot_list_head)
                    goto LABEL_139;
                break;
            case 0x34u:
            case 0x35u:
            case 0x36u:
            case 0x37u:
            case 0x38u:
            case 0x39u:
                v3->state = 0;
                entity_set_draw_handlers(v3);
                v81 = v3->sprite->_54_inside_mobd_ptr4->field_18;
                if (v81)
                {
                    for (i = v81->field_0; i != -1; v81 = (DataMobdItem_stru1 *)((char *)v81 + 16))
                    {
                        if (i == 3)
                            v3->stru60.ptr_C = v81;
                        i = v81->field_10;
                    }
                }
                for (j = 0; j < (int)v3->_128_spawn_param; ++j)
                {
                    v84 = script_create_coroutine(SCRIPT_TYPE_INVALID, script_4188F0, 0);
                    if (v84)
                        v84->param = v3;
                }
                goto LABEL_204;
            case 0x2Bu:
            case 0x2Cu:
                v3->sprite->drawjob->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_448510_aircraft;
                entity_401070_stru31(v3);
                v3->state = 0;
                entity_410CF0_aircraft(v3);
                goto LABEL_208;
            default:
                v3->state = 0;
                entity_set_draw_handlers(v3);
                v3->sprite->field_88_unused = 1;
                v55 = v3->sprite;
                v86 = v55->y;
                goto LABEL_207;
            }
            while (v59 != v2->field_2EC)
            {
                v58 = v58->next;
                ++v59;
                if ((OilDeposit **)v58 == &oilspot_list_head)
                {
                LABEL_139:
                    v58 = 0;
                    break;
                }
            }
            if (v58)
                v58->drillrig = v3;
            *(_DWORD *)v56 = (int)v58;
        LABEL_143:
            v60 = v2[1].id;
            *((_DWORD *)v56 + 1) = v60;
            v61 = v3->unit_id;
            if ((v61 == 58 || v61 == 59) && v3->player_side == player_side && v60 > 1)
                sub_447000();
            a2a = (int *)((char *)v56 + 8);
            *((_DWORD *)v56 + 2) = v2[1].entity_task_event;
            *((_WORD *)v56 + 6) = v2[1].entity_task_handler_idx;
            *((_WORD *)v56 + 7) = HIWORD_HEXRAYS(v2[1].entity_task_handler_idx);
            *((_DWORD *)v56 + 4) = 0;
            *((Entity **)v56 + 6) = entityRepo->FindById(v2[1].entity_task_message_handler_idx);
            *((_DWORD *)v56 + 7) = v2[1].entity_task_field_20;
            entity_410DC0_building(v3);
            v64 = v2[1].entity_task_field_14;
            *((_DWORD *)v56 + 8) = 0;
            *((_DWORD *)v56 + 9) = v64;
            if (v3->player_side == player_side)
                building_limits_on_new_building(v3->unit_id);
            for (k = 0; k < *((_DWORD *)v56 + 9); ++k)
            {
                v66 = script_create_coroutine(SCRIPT_TYPE_INVALID, script_418A10, 0);
                if (v66)
                    v66->param = v3;
            }
            v67 = v3->unit_id;
            if (v67 != 65 && v67 != 66 || !*a2a)
                goto LABEL_189;
            v68 = v2[1].turret_sprite.z_index - 1;
            v69 = (void(*)(Script *))get_handler(v68);
            if (v69)
            {
                v71 = script_create_function((enum SCRIPT_TYPE)v2[1].turret_sprite.y, v69);
                if (v71)
                {
                    v72 = v2[1].turret_sprite.x_speed;
                    v71->event_handler = (void(*)(Script *, Script *, enum SCRIPT_EVENT, void *))get_handler(v72 - 1);
                    //v71->debug_handler_name = get_handler_name(v72 - 1);
                    v71->flags_20 = v2[1].turret_sprite.y_speed;
                    v71->num_runs_to_skip = v2[1].turret_sprite.z_speed;
                    v71->flags_24 = v2[1].turret_sprite._inside_mobd_item;
                    v71->_28_yield_flags = v2[1].turret_sprite._54_inside_mobd_ptr4;
                    v71->field_2C = v2[1].turret_sprite._60_mobd_anim_speed;
                }
                v70 = v71;
            }
            else
            {
                v70 = 0;
            }
            if (!v70)
                return delete v3, nullptr;
            *(_DWORD *)v56 = (int)v70;
            result = (int)script_create_local_object(v70, 32);
            v74 = result;
            if (result)
            {
                *(_DWORD *)(result + 28) = (int)v70;
                v75 = v2[1].entity_task_field_24;
                *(_DWORD *)v74 = (int)get_handler(v75 - 1);
                *(_DWORD *)(v74 + 4) = v2[1].entity_task_field_28;
                *(_DWORD *)(v74 + 8) = v2[1].entity_task_field_2C;
                *(_DWORD *)(v74 + 12) = v2[1].unit_stats_idx;
                *(Entity **)(v74 + 16) = entityRepo->FindById(v2[1].player_side);
                result = (int)GAME_Load_UnpackSprite((SpriteSerialized *)&v2[1].turret_sprite_task_event);
                *(_DWORD *)(v74 + 24) = result;
                if (result)
                {
                    *(_DWORD *)(result + 124) = (int)a2a;
                    *(_DWORD *)(*(_DWORD *)(v74 + 24) + 8) = (int)a2a;
                    v70->param = (void *)v74;
                    v3->sprite->parent = *(Sprite **)(*(_DWORD *)(v74 + 16) + 304);
                    stru37_list_427D80_enqueue_item(
                        (int *)(4 * v3->player_side + 4704680),
                        a2a,
                        300,
                        42,
                        v3->script,
                        *(void **)(v74 + 16),
                        -1);
                    v3->sprite->parent = *(Sprite **)(*(_DWORD *)(v74 + 16) + 304);
                LABEL_189:
                    v79 = v3->sprite->_54_inside_mobd_ptr4->field_18;
                    if (v79 && (v80 = v79->field_0, v79->field_0 != -1))
                    {
                        do
                        {
                            if (v80 == 3)
                                v3->stru60.ptr_C = v79;
                            v80 = v79->field_10;
                            v79 = (DataMobdItem_stru1 *)((char *)v79 + 16);
                        } while (v80 != -1);
                        entity_40DD00_boxd(v3);
                    }
                    else
                    {
                    LABEL_204:
                        entity_40DD00_boxd(v3);
                    }
                LABEL_208:
                    if (entity_402AC0_is_mode_402AB0(v3))
                    {
                        v85 = v3->turret;
                        if (v85)
                            v85->turret_sprite->drawjob->flags |= 0x40000000u;
                    }
                    return v3;
                }
            }
        }
    }
    return v3;
}
