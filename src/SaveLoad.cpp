#include "src/kknd.h"
#include "src/_unsorted_data.h"
#include "src/Map.h"
#include "src/RenderDrawHandlers.h"
#include "src/ScriptEvent.h"
#include "src/Sprite.h"

#include "src/Engine/Entity.h"
#include "src/Engine/EntityFactory.h"
#include "src/Engine/Infrastructure/EntityRepository.h"

using Engine::EntityFactory;



//----- (0041CAC0) --------------------------------------------------------
bool is_game_loading()
{
    return game_load_in_progress;
}
// 479FBC: using guessed type int game_load_in_progress;

//----- (0041CAD0) --------------------------------------------------------
bool is_game_saving()
{
    return game_save_in_progress;
}

//----- (0041CAE0) --------------------------------------------------------
bool _41CAE0_prepare_to_load_level(const char *a1, enum LEVEL_ID level)
{
    if (game_load_in_progress || game_save_in_progress) {
        return false;
    }

    strcpy(current_savegame_filename, a1);
    game_saveload_level_idx = level;
    game_load_in_progress = 1;
    return true;
}

//----- (0041CB30) --------------------------------------------------------
bool _41CB30_prepare_to_save_level(const char *a1, enum LEVEL_ID level)
{
    if (game_load_in_progress || game_save_in_progress)
    {
        return false;
    }
    else
    {
        strcpy(current_savegame_filename, a1);
        game_saveload_level_idx = level;
        game_save_in_progress = 1;
        return true;
    }
}

//----- (0041CB80) --------------------------------------------------------
enum LEVEL_ID get_saveload_level_id()
{
    return game_saveload_level_idx;
}

//----- (0041CB90) --------------------------------------------------------
OilDepositSaveStruct *GAME_Save_PackOilData(size_t *oil_data_size)
{
    OilDeposit *i; // eax@1
    OilDepositSaveStruct *result; // eax@3
    OilDeposit *v3; // edx@5
    OilDepositSaveStruct *j; // ecx@5
    int *v5; // ecx@6

    *oil_data_size = 4;
    for (i = oilspot_list_head; (OilDeposit **)i != &oilspot_list_head; i = i->next)
        *oil_data_size += 16;
    result = (OilDepositSaveStruct *)malloc(*oil_data_size);
    if (result)
    {
        v3 = oilspot_list_head;
        for (j = result; (OilDeposit **)v3 != &oilspot_list_head; j = (OilDepositSaveStruct *)(v5 + 1))
        {
            j->field_0 = v3->oil_left;
            v5 = &j->width_x256;
            *v5 = v3->sprite->x;
            ++v5;
            *v5 = v3->sprite->y;
            ++v5;
            *v5 = v3->drillrig_entity_id;
            v3 = v3->next;
        }
        j->field_0 = -1;
    }
    else
    {
        errmsg_save[1] = aMemory;
    }
    return result;
}

//----- (0041CC20) --------------------------------------------------------
int GAME_Load_UnpackOilData(OilDepositSaveStruct *a1)
{
    OilDepositSaveStruct *v1; // edi@1
    OilDeposit *v2; // esi@2
    Sprite *v3; // eax@6
    int *v4; // edi@7
    int v5; // eax@7
    int v6; // edx@9
    _DWORD *v7; // edi@9
    int v8; // ecx@9
    int v9; // edx@9
    OilDeposit *v10; // eax@9
    OilDeposit *v11; // ecx@9

    v1 = a1;
    if (a1->field_0 == -1)
    {
        return 1;
    }

    while (1)
    {
        v2 = oilspot_list_free_pool;
        if (oilspot_list_free_pool)
            oilspot_list_free_pool = oilspot_list_free_pool->next;
        else
            v2 = 0;
        if (!v2)
            break;
        v3 = sprite_create_scripted(MOBD_OIL_PATCH, 0, UNIT_Handler_OilPatch, SCRIPT_COROUTINE, 0);
        v2->sprite = v3;
        if (!v3)
            break;
        v4 = &v1->width_x256;
        v3->script->param = v2;
        v5 = *(v4 - 1);
        v2->oil_left = v5;
        if (v5 <= 0)
            v2->sprite->drawjob->flags |= 0x40000000u;
        v6 = *v4;
        v7 = v4 + 1;
        v2->sprite->x = v6;
        v8 = *v7;
        ++v7;
        v2->sprite->y = v8;
        v9 = *v7;
        v1 = (OilDepositSaveStruct *)(v7 + 1);
        v2->drillrig_entity_id = v9;
        v10 = oildeposit_list_end;
        v11 = oildeposit_list_end->next;
        v2->prev = oildeposit_list_end;
        v2->next = v11;
        v10->next->prev = v2;
        v10->next = v2;
        if (v1->field_0 == -1)
            return 1;
    }
    return 0;
}

//----- (0041CCE0) --------------------------------------------------------
bool GAME_Save_PackEntity(Entity *entity, int save_data, int save_data_size)
{
    Entity *v3; // ebp@1
    EntitySerialized *v4; // ebx@1
    Entity *v5; // eax@1
    int v6; // edx@1
    int v7; // eax@3
    int v8; // ecx@4
    Script *v9; // esi@9
    EntityTurret *v19; // eax@25
    Script *v21; // edi@26
    Entity *v29; // ecx@43
    int v30; // edx@43
    int v31; // eax@44
    Entity *v64; // eax@124
    int v65; // edx@124
    int v66; // eax@126
    int v67; // ecx@127
    Entity *v68; // eax@132
    int v69; // edx@132
    int v70; // eax@134
    int v71; // ecx@135
    Entity *v72; // eax@140
    int v73; // edx@140
    int v74; // eax@142
    int v75; // ecx@143
    Entity *v76; // eax@148
    int v77; // ecx@148
    int v78; // eax@150
    int v79; // edx@151
    int v80; // eax@156
    int *v81; // ecx@156
    enum UNIT_ID v82; // eax@158
    char *v83; // ebp@159
    char *v84; // ebx@159
    int v85; // eax@160
    int v86; // edx@160
    int v87; // eax@162
    int v88; // ecx@163
    int v89; // eax@168
    int v90; // edx@168
    int v91; // eax@170
    int v92; // ecx@171
    int v93; // eax@176
    int v94; // edx@176
    int v95; // eax@178
    int v96; // ecx@179
    int *v97; // eax@184
    int v98; // ebp@184
    int v99; // edx@184
    int v100; // ecx@185
    int v101; // ecx@186
    void *v102; // ebp@191
    OilDeposit *v103; // ecx@192
    OilDeposit *v104; // eax@194
    int v105; // edx@194
    OilDeposit *v106; // eax@199
    OilDeposit *v107; // esi@199
    int v108; // eax@201
    Entity *v109; // edx@202
    enum UNIT_ID v110; // eax@207
    int v116; // eax@217
    int v117; // eax@218
    int v118; // esi@221
    char *v127; // [sp-4h] [bp-18h]@68
    EntityTurret *v128; // [sp+10h] [bp-4h]@25
    bool result;

    v3 = entity;
    v4 = (EntitySerialized *)save_data;
    v5 = entity->entity_8;
    v6 = entity->entity_118_entity_id;
    if (!v5)
        goto LABEL_8;
    if (v6 != -1)
    {
        v8 = v5->entity_id;
        if (v8 && v8 == v6 && !v5->destroyed)
        {
            v7 = v5->entity_id;
            goto LABEL_9;
        }
    LABEL_8:
        v7 = -1;
        goto LABEL_9;
    }
    v7 = v5->entity_id;
LABEL_9:
    v4->id = v7;
    v9 = v3->script;
    if (v9->routine_type != SCRIPT_FUNCTION)
    {
        errmsg_save[1] = aTaskIsWrongTyp;
        return 0;
    }
    v4->entity_task_event = v9->script_type;
    v4->entity_task_handler_idx = get_handler_id(v9->handler);
    v4->entity_task_message_handler_idx = get_handler_id(v9->event_handler);
    v4->entity_task_field_20 = v9->flags_20;
    v4->entity_task_field_14 = v9->num_runs_to_skip;
    v4->entity_task_field_24 = v9->flags_24;
    v4->entity_task_field_28 = v9->_28_yield_flags;
    v4->entity_task_field_2C = v9->field_2C;
    v4->unit_stats_idx = v3->unit_id;
    v4->player_side = v3->player_side;
    v19 = v3->turret;
    v128 = v19;
    if (v19)
    {
        v21 = v19->sprite_task;
        if (v19->sprite_task->routine_type != SCRIPT_FUNCTION)
        {
            errmsg_save[1] = aTaskIsWrongTyp;
            return 0;
        }
        v4->turret_sprite_task_event = v21->script_type;
        v4->turret_sprite_task_handler_idx = get_handler_id(v21->handler);
        v4->turret_sprite_task_message_handler_idx = get_handler_id(v21->event_handler);
        v4->turret_sprite_task_field_20 = v21->flags_20;
        v4->turret_sprite_task_field_14 = v21->num_runs_to_skip;
        v4->turret_sprite_task_field_24 = v21->flags_24;
        v4->turret_sprite_task_field_28 = v21->_28_yield_flags;
        v4->turret_sprite_task_field_2C = v21->field_2C;
        result = GAME_Save_PackSprite(v128->turret_sprite, &v4->turret_sprite);
        if (!result)
            return result;
        v29 = v128->_C_entity;
        v30 = v128->_C_entity_idx;
        if (!v29 || (v31 = v29->entity_id, v30 != -1) && (!v31 || v31 != v30 || v29->destroyed))
            v31 = -1;
        v4->turret_C_entity_id = v31;
        v4->turret_mode = get_handler_id(v128->handler);
        if (v4->turret_mode < 0)
        {
            sprintf(byte_479EF8, aUnitDS, v3->unit_id, "unknown turret mode");
        LABEL_224:
            errmsg_save[1] = byte_479EF8;
            return 0;
        }
        v4->turret_mobd_lookup_id = v128->mobd_lookup_id;
        v4->turret_field_18 = v128->field_18;
        v4->turret_field_1C = v128->field_1C;
        v4->turret_field_20 = v128->field_20;
        v4->turret_field_2C = v128->field_2C;
        v4->turret_entity__or__C_entity_id = v128->_C_entity_idx;
        v4->turret_field_34 = v128->field_34;
    }
    else
    {
        v4->turret_sprite_task_handler_idx = 0;
    }

    v4->entity_mode = v3->ModeHandlerId();
    if (v4->entity_mode < 0)
    {
        sprintf(byte_479EF8, aUnitDS, v3->unit_id, "unknown mode");
        goto LABEL_224;
    }

    v4->entity_mode_idle = get_handler_id(v3->mode_idle);
    if (v4->entity_mode_idle < 0)
    {
        sprintf(byte_479EF8, "unit %d %s", v3->unit_id, "unknown idle mode");
        goto LABEL_224;
    }

    v4->entity_mode_arrive = get_handler_id(v3->mode_arrive);
    if (v4->entity_mode_arrive < 0)
    {
        sprintf(byte_479EF8, aUnitDS, v3->unit_id, "unknown arrive mode");
        goto LABEL_224;
    }

    v4->entity_mode_attacked = get_handler_id(v3->mode_attacked);
    if (v4->entity_mode_attacked < 0)
    {
        sprintf(byte_479EF8, aUnitDS, v3->unit_id, "unknown attacked mode");
        goto LABEL_224;
    }

    v4->entity_mode_return = get_handler_id(v3->mode_return);
    if (v4->entity_mode_return < 0)
    {
        sprintf(byte_479EF8, aUnitDS, v3->unit_id, "unknown return mode");
        goto LABEL_224;
    }

    v4->entity_mode_turn_return = get_handler_id(v3->mode_turn_return);
    if (v4->entity_mode_turn_return < 0)
    {
        sprintf(byte_479EF8, aUnitDS, v3->unit_id, "unknown turn-return mode");
        goto LABEL_224;
    }

    v4->entity_message_handler_idx = get_handler_id(v3->event_handler);
    if (v4->entity_message_handler_idx < 0)
    {
        sprintf(byte_479EF8, aUnitDS, v3->unit_id, "unknown message handler");
        goto LABEL_224;
    }

    result = GAME_Save_PackSprite(v3->sprite, &v4->entity_sprite);
    if (!result)
        return result;
    v4->entity_field_78 = v3->field_78;
    v4->entity_mobd_idx = (MOBD_ID)v3->GetCurrentAnimFrame();
    v4->entity_field_80 = v3->field_80;
    v4->entity_field_84 = v3->field_84;
    v4->entity_field_88 = v3->_88_dst_orientation;
    v4->entity_hitpoints = v3->hitpoints;
    v4->entity_field_94 = v3->experience;
    v4->entity_98_veterancy_damage_bonus_idx = v3->veterancy_level;
    v4->entity_9C_hp_regen_condition = v3->_9C_hp_regen_condition;
    v4->entity_A0_hp_regen_condition = v3->_A0_hp_regen_condition;
    v4->field_A4 = v3->_A4_idx_in_tile;
    v4->entity_sprite_width_shr13 = v3->sprite_map_x;
    v4->entity_sprite_height_shr13 = v3->sprite_map_y;
    v4->entity_sprite_width = v3->sprite_x;
    v4->entity_sprite_height = v3->sprite_y;
    v4->field_B8 = v3->_B8_move_dst_x;
    v4->field_BC = v3->_B8_move_dst_y;
    v4->field_C0 = v3->_C0_mobd_anim_speed_related;
    v4->field_C4 = v3->field_C4;
    v4->field_C8 = v3->field_C8;
    v4->field_CC = v3->field_CC;
    v4->field_D0 = v3->field_D0;
    v4->field_D4 = v3->field_D4;
    v4->field_D8 = v3->field_D8;
    v4->field_DC = v3->_DC_order;
    v64 = v3->retaliation_target;
    v65 = v3->retaliation_target_id;
    if (!v64)
        goto LABEL_243;
    if (v65 == -1)
    {
        v66 = v64->entity_id;
        goto LABEL_132;
    }
    v67 = v64->entity_id;
    if (v67 && v67 == v65 && !v64->destroyed)
        v66 = v64->entity_id;
    else
        LABEL_243:
    v66 = -1;
LABEL_132:
    v4->entity_EC_outpost_clanhall_entity_id = v66;
    v68 = v3->_E4_prev_attack_target;
    v69 = v3->_E4_prev_attack_target_entity_id;
    if (!v68)
        goto LABEL_139;
    if (v69 != -1)
    {
        v71 = v68->entity_id;
        if (v71 && v71 == v69 && !v68->destroyed)
        {
            v70 = v68->entity_id;
            goto LABEL_140;
        }
    LABEL_139:
        v70 = -1;
        goto LABEL_140;
    }
    v70 = v68->entity_id;
LABEL_140:
    v4->entity_E4_entity_id = v70;
    v4->retaliation_target_id = v3->retaliation_target_id;
    v4->_E4_prev_attack_target_entity_id = v3->_E4_prev_attack_target_entity_id;
    v4->entity_F4_entity_118_entity_id = v3->entity_118_entity_id;
    v4->entity_sprite_width_2 = v3->sprite_x_2;
    v4->entity_sprite_height_2 = v3->sprite_y_2;
    v72 = v3->entity_118;
    v73 = v3->entity_118_entity_id;
    if (!v72)
        goto LABEL_244;
    if (v73 == -1)
    {
        v74 = v72->entity_id;
        goto LABEL_148;
    }
    v75 = v72->entity_id;
    if (v75 && v75 == v73 && !v72->destroyed)
        v74 = v72->entity_id;
    else
        LABEL_244:
    v74 = -1;
LABEL_148:
    v4->entity_entity_118_entity_id = v74;
    v4->entity_field_11C = v3->_11C__infantry_sprite_y___drillrig_oil_spot;
    v4->entity_field_120 = v3->_120__infantry_sprite_x;
    v4->entity_field_124 = v3->field_124;
    v4->entity_field_128 = (int)v3->_128_spawn_param;
    v4->entity_field_12C = v3->_12C_prison_bunker_spawn_type;
    v4->entity_entity_id = v3->entity_id;
    v4->entity_field_134 = v3->_134_param__unitstats_after_mobile_outpost_plant;
    v4->entity_field_138 = v3->field_138;
    v4->entity_field_13C = v3->field_13C;
    v4->entity_field_140 = v3->field_140;
    v4->entity_field_144 = v3->field_144;
    v4->entity_field_148 = v3->field_148;
    v4->entity_field_14C = v3->field_14C;
    v4->entity_field_150 = v3->field_150;
    v4->entity_field_154 = v3->field_154;
    v4->entity_field_158 = v3->field_158;
    memcpy(v4->entity_array_15C, v3->_15C_waypoints_xs, sizeof(v4->entity_array_15C));
    memcpy(v4->entity_array_184, v3->_15C_waypoints_ys, sizeof(v4->entity_array_184));
    memcpy(v4->entity_array_1AC, v3->_1AC_waypoints_xs, sizeof(v4->entity_array_1AC));
    memcpy(v4->entity_array_1D4, v3->_1AC_waypoints_ys, sizeof(v4->entity_array_1D4));
    memcpy(v4->entity_array_1FC, v3->_1FC_waypoints_xs, sizeof(v4->entity_array_1FC));
    memcpy(v4->entity_array_224, v3->_1FC_waypoints_ys, sizeof(v4->entity_array_224));
    memcpy(v4->entity_array_24C, &v3->pathing, sizeof(v4->entity_array_24C));
    v76 = v3->entity_27C;
    v77 = v3->entity_27C_entity_id;
    if (!v76)
        goto LABEL_155;
    if (v77 != -1)
    {
        v79 = v76->entity_id;
        if (v79 && v79 == v77 && !v76->destroyed)
        {
            v78 = v76->entity_id;
            goto LABEL_156;
        }
    LABEL_155:
        v78 = -1;
        goto LABEL_156;
    }
    v78 = v76->entity_id;
LABEL_156:
    v4->entity_27C_entity_id = v78;
    v4->entity_27C_entity_id_2 = v3->entity_27C_entity_id;
    v80 = 0;
    v81 = v4->entity_array_294;
    do
    {
        *v81 = v3->array_294[v80++];
        ++v81;
    } while (v80 < 7);
    LOWORD_HEXRAYS(v4->entity_array_294[7]) = v3->_29C_idle_timer;
    HIWORD_HEXRAYS(v4->entity_array_294[7]) = v3->_29C_map_x;
    v4->field_2E8 = v3->_29C_map_y;
    v4->field_2EA = v3->field_2A0_hi;
    v82 = v3->unit_id;
    switch (v82)
    {
    case 0x17u:
    case 0x18u:
        v83 = (char *)v3->state;
        v84 = (char *)&v4->field_2EC;
        if (!v83)
        {
            *(_DWORD *)v84 = -67108864;
            return 1;
        }
        *(_DWORD *)v84 = *(_DWORD *)v83;
        v85 = *((_DWORD *)v83 + 1);
        v86 = *((_DWORD *)v83 + 6);
        if (!v85)
            goto LABEL_167;
        if (v86 == -1)
        {
            v87 = *(_DWORD *)(v85 + 304);
        }
        else
        {
            v88 = *(_DWORD *)(v85 + 304);
            if (!v88 || v88 != v86 || *(_DWORD *)(v85 + 140))
                LABEL_167:
            v87 = -1;
            else
                v87 = *(_DWORD *)(v85 + 304);
        }
        *((_DWORD *)v84 + 1) = v87;
        v89 = *((_DWORD *)v83 + 2);
        v90 = *((_DWORD *)v83 + 5);
        if (!v89)
            goto LABEL_175;
        if (v90 == -1)
        {
            v91 = *(_DWORD *)(v89 + 304);
        }
        else
        {
            v92 = *(_DWORD *)(v89 + 304);
            if (!v92 || v92 != v90 || *(_DWORD *)(v89 + 140))
                LABEL_175:
            v91 = -1;
            else
                v91 = *(_DWORD *)(v89 + 304);
        }
        *((_DWORD *)v84 + 2) = v91;
        v93 = *((_DWORD *)v83 + 3);
        v94 = *((_DWORD *)v83 + 4);
        if (!v93)
            goto LABEL_183;
        if (v94 == -1)
        {
            v95 = *(_DWORD *)(v93 + 304);
        }
        else
        {
            v96 = *(_DWORD *)(v93 + 304);
            if (!v96 || v96 != v94 || *(_DWORD *)(v93 + 140))
                LABEL_183:
            v95 = -1;
            else
                v95 = *(_DWORD *)(v93 + 304);
        }
        *((_DWORD *)v84 + 3) = v95;
        *((_DWORD *)v84 + 4) = *((_DWORD *)v83 + 4);
        *((_DWORD *)v84 + 5) = *((_DWORD *)v83 + 5);
        *((_DWORD *)v84 + 6) = *((_DWORD *)v83 + 6);
        *((_DWORD *)v84 + 7) = *((_DWORD *)v83 + 7);
        v97 = (int *)(v84 + 32);
        v98 = v83 - v84;
        v99 = 20;
        do
        {
            v100 = *(int *)((char *)v97 + v98);
            if (v100)
                v101 = *(_DWORD *)(v100 + 304);
            else
                v101 = -1;
            *v97 = v101;
            ++v97;
            --v99;
        } while (v99);
        return 1;
    case 0x19u:
        v102 = v3->state;
        v4->field_2EC = *(_DWORD *)v102;
        v4[1].id = *((_DWORD *)v102 + 1);
        v4[1].entity_task_event = (SCRIPT_TYPE)*((_DWORD *)v102 + 2);
        return 1;
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
        v103 = (OilDeposit *)v3->state;
        if (v82 == 46 || v82 == 47)
        {
            v104 = oilspot_list_head;
            v105 = 0;
            if ((OilDeposit **)oilspot_list_head == &oilspot_list_head)
            {
            LABEL_197:
                v105 = -1;
            }
            else
            {
                while (v104 != v103->next)
                {
                    v104 = v104->next;
                    ++v105;
                    if ((OilDeposit **)v104 == &oilspot_list_head)
                        goto LABEL_197;
                }
            }
            v4->field_2EC = v105;
        }
        v4[1].id = (int)v103->prev;
        v4[1].entity_task_event = (enum SCRIPT_TYPE)(int)v103->sprite;
        LOWORD_HEXRAYS(v4[1].entity_task_handler_idx) = v103->oil_left;
        HIWORD_HEXRAYS(v4[1].entity_task_handler_idx) = HIWORD_HEXRAYS(v103->oil_left);
        v106 = v103[1].next;
        v107 = v103[1].prev;
        if (!v106)
            goto LABEL_206;
        if (v107 == (OilDeposit *)-1)
        {
            v108 = (int)v106[12].drillrig;
        }
        else
        {
            v109 = v106[12].drillrig;
            if (!v109 || (OilDeposit *)v109 != v107 || v106[5].drillrig_entity_id)
                LABEL_206:
            v108 = -1;
            else
                v108 = (int)v106[12].drillrig;
        }
        v4[1].entity_task_message_handler_idx = v108;
        v4[1].entity_task_field_20 = (int)v103[1].prev;
        v4[1].entity_task_field_14 = v103[1].oil_left;
        v110 = v3->unit_id;
        if (v110 != UNIT_STATS_SURV_RESEARCH_LAB && v110 != UNIT_STATS_MUTE_ALCHEMY_HALL || !v103->sprite)
            goto LABEL_225;

        int v113; v113 = v103->next[2].oil_left;
        v4[1].entity_task_field_24 = get_handler_id(*(void **)(v113 + 0));
        v4[1].entity_task_field_28 = *(_DWORD *)(v113 + 4);
        v4[1].entity_task_field_2C = *(_DWORD *)(v113 + 8);
        v4[1].unit_stats_idx = (UNIT_ID)*(_DWORD *)(v113 + 12);
        v116 = *(_DWORD *)(v113 + 16);
        if (v116)
            v117 = *(_DWORD *)(v116 + 304);
        else
            v117 = -1;
        v4[1].player_side = v117;
        result = GAME_Save_PackSprite(*(Sprite **)(v113 + 24), (SpriteSerialized *)&v4[1].turret_sprite_task_event);
        if (result)
        {
            v118 = *(_DWORD *)(v113 + 28);
            if (*(_DWORD *)(v118 + 24) != SCRIPT_FUNCTION)
            {
                errmsg_save[1] = aTaskIsWrongTyp;
                sprintf(byte_479EF8, aUnitDS, v3->unit_id, "bad upgrade task");
                goto LABEL_224;
            }
            v4[1].turret_sprite.y = *(_DWORD *)(v118 + 12);
            v4[1].turret_sprite.z_index = get_handler_id(*(void **)(v118 + 64));
            v4[1].turret_sprite.x_speed = get_handler_id(*(void **)(v118 + 52));
            v4[1].turret_sprite.y_speed = *(_DWORD *)(v118 + 32);
            v4[1].turret_sprite.z_speed = *(_DWORD *)(v118 + 20);
            v4[1].turret_sprite._inside_mobd_item = *(_DWORD *)(v118 + 36);
            v4[1].turret_sprite._54_inside_mobd_ptr4 = *(_DWORD *)(v118 + 40);
            v4[1].turret_sprite._60_mobd_anim_speed = *(_DWORD *)(v118 + 44);
            result = 1;
        }
        break;
    default:
    LABEL_225:
        result = 1;
        break;
    }
    return result;
}

//----- (0041DA20) --------------------------------------------------------
bool GAME_Save_PackSprite(Sprite *a1, SpriteSerialized *out)
{
    DataMobdItem_stru0 **v2; // eax@1
    DataMobdItem_stru0 *v3; // eax@4

    out->mobd_idx = a1->mobd_id;
    out->x = a1->x;
    out->y = a1->y;
    out->z_index = a1->z_index;
    out->x_speed = a1->x_speed;
    out->y_speed = a1->y_speed;
    out->z_speed = a1->z_speed;
    v2 = a1->_inside_mobd_item;
    if (v2)
        out->_inside_mobd_item = (unsigned int)v2 - (unsigned int)currently_running_lvl_mobd[out->mobd_idx].items;
    else
        out->_inside_mobd_item = -1;
    v3 = a1->_54_inside_mobd_ptr4;
    if (v3)
    {
        out->_54_inside_mobd_ptr4 = (char *)v3 - (char *)currently_running_lvl_mobd[out->mobd_idx].items;
        out->_60_mobd_anim_speed = a1->_60_mobd_anim_speed;
    }
    else
    {
        out->_54_inside_mobd_ptr4 = -1;
        out->_60_mobd_anim_speed = a1->_60_mobd_anim_speed;
    }
    return true;
}

//----- (0041E8E0) --------------------------------------------------------
Sprite *GAME_Load_UnpackSprite(SpriteSerialized *serialized)
{
    SpriteSerialized *v1; // edi@1
    Sprite *v2; // eax@1
    Sprite *v3; // esi@1
    int v4; // edx@2
    int v5; // eax@3
    DataMobdItem_stru0 **v7; // eax@4
    DataMobdItem_stru0 *v8; // edx@5
    DataMobdItem_stru0 **v9; // eax@5
    int v11; // eax@7
    char *v12; // eax@8

    v1 = serialized;
    v2 = sprite_create(serialized->mobd_idx, 0, 0);
    v3 = v2;
    if (!v2)
        return v3;
    v2->x = v1->x;
    v2->y = v1->y;
    v2->z_index = v1->z_index;
    v2->x_speed = v1->x_speed;
    v2->y_speed = v1->y_speed;
    v2->z_speed = v1->z_speed;
    v4 = v1->_inside_mobd_item;
    if (v4 == -1)
    {
        v11 = v1->_54_inside_mobd_ptr4;
        if (v11 != -1)
        {
            v12 = (char *)currently_running_lvl_mobd[v1->mobd_idx].items + v11;
            v3->_54_inside_mobd_ptr4 = (DataMobdItem_stru0 *)v12;
            v3->pstru58 = (Sprite_stru58 *)*((_DWORD *)v12 + 4);
        }
        goto LABEL_9;
    }
    sprite_load_mobd(v2, v4);
    v5 = v1->_54_inside_mobd_ptr4;
    if (v5 == -1)
    {
    LABEL_9:
        v3->_60_mobd_anim_speed = v1->_60_mobd_anim_speed;
        return v3;
    }
    v7 = v3->_inside_mobd_item + 1;
    v3->_54_inside_mobd_ptr4 = (DataMobdItem_stru0 *)&currently_running_lvl_mobd[v1->mobd_idx].items->_[v5 / 4];
    v3->_inside_mobd_item_2 = v7;
    if (v7[0] != v3->_54_inside_mobd_ptr4)
    {
        do
        {
            v8 = v3->_54_inside_mobd_ptr4;
            v9 = v3->_inside_mobd_item_2 + 1;
            v3->_inside_mobd_item_2 = v9;
        } while (v9[0] != v8);
    }
    v3->pstru58 = (Sprite_stru58 *)v3->_54_inside_mobd_ptr4->ptr_10;
    v3->_60_mobd_anim_speed = v1->_60_mobd_anim_speed;
    return v3;
}

//----- (0041E9B0) --------------------------------------------------------
char *GAME_Save_PackProductionInfo(size_t *size)
{
    size_t *v1; // ebx@1
    ProductionGroup *v2; // esi@1
    ProductionGroup *i; // edx@2
    ProductionOption *v4; // eax@3
    char *result; // eax@7
                  //ProductionGroup *v6; // ecx@9
    ProductionGroup *v7; // edx@10
    char *v8; // ebp@10
    ProductionOption *v9; // ecx@11
    Entity *v10; // esi@11
    int v11; // esi@12
    char *v12; // esi@14
               //ProductionGroup *v13; // [sp+10h] [bp-Ch]@9
    char *v14; // [sp+14h] [bp-8h]@10
    char *v15; // [sp+18h] [bp-4h]@7

    v1 = size;
    *size = 20;
    for (int j = PRODUCTION_GROUP_INFANTRY; j <= PRODUCTION_GROUP_AIRCRAFT; ++j)
    {
        v2 = ProductionGroupAccessor((PRODUCTION_GROUP_ID)j);
        for (i = v2->prev; i != v2; i = i->prev)
        {
            *size += 16;
            for (v4 = i->prev_option; v4 != (ProductionOption *)&i->next_option; v4 = v4->prev) {
                *size += 24;
            }
        }
        //	v2 += 19;
    }
    //while ((int)v2 < (int) & _47C914_sidebar);

    result = (char *)malloc(*size);
    v15 = result;
    if (result)
    {
        //v6 = &_47C798_infantry_pg;
        //v13 = &_47C798_infantry_pg;
        for (int i = PRODUCTION_GROUP_INFANTRY; i <= PRODUCTION_GROUP_AIRCRAFT; ++i)
        {
            auto v6 = ProductionGroupAccessor((PRODUCTION_GROUP_ID)i);
            auto v13 = ProductionGroupAccessor((PRODUCTION_GROUP_ID)i);
            v7 = v6->prev;
            v8 = result;
            *(_DWORD *)result = 0;
            result += 4;
            v14 = v8;
            if (v7 != v6)
            {
                do
                {
                    v9 = v7->prev_option;
                    ++*(_DWORD *)v8;
                    v10 = v7->_C_entity;
                    if (v10)
                        v11 = v10->entity_id;
                    else
                        v11 = -1;
                    *(_DWORD *)result = v11;
                    *((_DWORD *)result + 1) = v7->group_id;
                    *((_DWORD *)result + 2) = v7->_44_mobd_lookup_idx;
                    v12 = result + 12;
                    result += 16;
                    *(_DWORD *)v12 = 0;
                    if ((ProductionOption **)v9 != &v7->next_option)
                    {
                        do
                        {
                            result += 24;
                            ++*(_DWORD *)v12;
                            *((_DWORD *)result - 6) = v9->unit_id;
                            *((_DWORD *)result - 5) = v9->mobd_lookup_table_offset;
                            *((_DWORD *)result - 4) = v9->_14_pcost;
                            *((_DWORD *)result - 3) = v9->field_18;
                            *((_DWORD *)result - 2) = v9->cost;
                            *((_DWORD *)result - 1) = v9->production_time_x60;
                            v9 = v9->prev;
                        } while (v9 != (ProductionOption *)&v7->next_option);
                        v8 = v14;
                    }
                    v7 = v7->prev;
                    v6 = v13;
                } while (v7 != v13);
            }
            //v6 += 19;
            //v13 = v6;
        }
        //while ((int)v6 < (int) & _47C914_sidebar);
        result = (char *)(&v15[4 * *v1] >= result ? (unsigned int)v15 : 0);
    }
    else
    {
        errmsg_save[1] = aMemory;
    }
    return result;
}

//----- (0041EAF0) --------------------------------------------------------
bool GAME_Load_UnpackProductionInfo(void *a1)
{
    int v1; // esi@1
    void *v2; // ebx@1
    _DWORD *v3; // eax@2
    ProductionGroup *v4; // edi@3
    _DWORD *v6; // eax@16
    __int32 v7; // ecx@21
    ProductionOption *v8; // ebp@21
    int v9; // edx@21
    int v10; // eax@21
    Entity *v11; // ecx@21
    ProductionGroup **v12; // ecx@22
    ProductionGroup *v13; // eax@22
    ProductionGroup *v14; // edx@23
    ProductionGroup *v15; // eax@28
    ProductionGroup *v16; // edx@28
    Entity *v17; // ecx@29
    enum UNIT_ID v18; // eax@29
    ProductionOption *v19; // esi@34
    int v20; // edx@37
    int v21; // eax@37
    ProductionOption *v22; // eax@39
    int v24; // [sp+10h] [bp-14h]@1
    int v25; // [sp+14h] [bp-10h]@31
    _DWORD *v26; // [sp+18h] [bp-Ch]@3
    int v27; // [sp+1Ch] [bp-8h]@2
    _DWORD *v28; // [sp+20h] [bp-4h]@2

    v1 = 0;
    v2 = a1;
    v24 = 0;
    while (1)
    {
        v3 = (int *)v2;
        v2 = (char *)v2 + 4;
        v28 = v3;
        v27 = 0;
        if (*v3 > 0)
            break;
    LABEL_42:
        v24 = ++v1;
        if (v1 >= 5)
            return 1;
    }
    while (1)
    {
        v4 = production_group_free_pool;
        v26 = (int *)v2;
        if (production_group_free_pool)
            production_group_free_pool = production_group_free_pool->next;
        else
            v4 = 0;
        if (!v4)
            return 0;

        v4->_C_entity = entityRepo->FindById(*(_DWORD *)v2);
        switch (v1)
        {
        case 2:
            _47B3D0_building_production_group = v4;
            break;
        case 3:
            _47B3B8_tower_production_group = v4;
            break;
        case 4:
            _47B3D4_aircraft_production_group = v4;
            break;
        default:
            if (v4->_C_entity)
            {
                v6 = (int *)v4->_C_entity->state;
                if (!v6)
                    return 0;
                v6[4] = (int)v4;
            }
            break;
        }
        v7 = *((_DWORD *)v2 + 1);
        v8 = (ProductionOption *)&v4->next_option;
        v4->group_id = (PRODUCTION_GROUP_ID)v7;
        v4->_44_mobd_lookup_idx = *((_DWORD *)v2 + 2);
        v9 = v7;
        v10 = v4->_44_mobd_lookup_idx + 16 * v7;
        v11 = v4->_C_entity;
        v4->prev_option = (ProductionOption *)&v4->next_option;
        v8->next = v8;
        v4->field_20 = -1;
        v4->field_40 = v10;

        v12 = (ProductionGroup **)ProductionGroupAccessor(v4->group_id);
        v13 = ProductionGroupAccessor(v4->group_id)->next;
        if (entity_check_type(v11, v9) && v13 != (ProductionGroup *)v12)
        {
            v14 = ProductionGroupAccessor(v4->group_id)->next;
            if ((ProductionGroup **)v13 != v12)
            {
                do
                {
                    if (v13->_C_entity->unit_id == UNIT_STATS_MUTE_BLACKSMITH)
                        break;
                    v14 = v13;
                    v13 = v13->next;
                } while (v13 != (ProductionGroup *)v12);
                v1 = v24;
            }
            v14->next = v4;
            v4->prev = v14;
            v4->next = v13;
            v13->prev = v4;
        }
        else
        {
            v15 = ProductionGroupAccessor((PRODUCTION_GROUP_ID)v1);
            v16 = ProductionGroupAccessor((PRODUCTION_GROUP_ID)v1)->next;
            v4->next = v16;
            v4->prev = v15;
            v16->prev = v4;
            v15->next = v4;
        }
        v17 = v4->_C_entity;
        v18 = v17->unit_id;
        if ((int)v18 < 58 || (int)v18 > 62)
            return 0;
        entity_410950(v17, LOBYTE_HEXRAYS(_4701B8_mobd_lookups_per_ProductionGroup_field44[2 * v4->_44_mobd_lookup_idx]));
        v4->sprite = 0;
        v2 = (char *)v2 + 16;
        v25 = 0;
        if (v26[3] > 0)
        {
            do
            {
                if (v8->next == v8)
                    script_trigger_event(0, EVT_MSG_1514, 0, _47CA18_sidebar_production_buttons[v4->group_id]->task);
                v19 = production_option_list_free_pool;
                if (production_option_list_free_pool)
                    production_option_list_free_pool = production_option_list_free_pool->next;
                else
                    v19 = 0;
                v19->field_2C = v4->field_40;
                v19->stru21prod_unit_id = (enum UNIT_ID)(int)v4->_C_entity;
                v19->unit_id = (UNIT_ID)*(_DWORD *)v2;
                v19->mobd_lookup_table_offset = *((_DWORD *)v2 + 1);
                v19->field_18 = *((_DWORD *)v2 + 3);
                v20 = *((_DWORD *)v2 + 4);
                v19->cost = v20;
                v19->production_time_x60 = *((_DWORD *)v2 + 5);
                v21 = *((_DWORD *)v2 + 2);
                v19->_14_pcost = v21;
                if (v21 > 0)
                    stru37_list_427EB0_enqueue_infantry(
                    (int *)&game_globals_per_player + *(_DWORD *)(v19->stru21prod_unit_id + 20),
                        &v19->_14_pcost,
                        v19->cost,
                        (v20 << 8) / v19->production_time_x60,
                        game_cursor_script,
                        v19,
                        v19->field_2C);
                v19->field_1C = 0;
                v19->field_20 = 0;
                v19->prev = v8;
                v22 = v8->next;
                v19->next = v8->next;
                v2 = (char *)v2 + 24;
                v22->prev = v19;
                v8->next = v19;
                ++v25;
            } while (v25 < v26[3]);
            v1 = v24;
        }
        if (++v27 >= *v28)
            goto LABEL_42;
    }
}


//----- (004240E0) --------------------------------------------------------
void _4240E0_kknd_sve_read(const char *filename)
{
    FILE *v1; // edi@1
    int v2; // ecx@2
    int *v3; // esi@3
    int v4; // ecx@11
    int *v5; // esi@12
    int v6; // [sp+8h] [bp-10Ch]@2
    int v7; // [sp+Ch] [bp-108h]@4
    char FileName[260]; // [sp+10h] [bp-104h]@1

    sprintf(FileName, "%s\\%s", game_data_installation_dir, filename);
    //SetFileAttributesA(FileName, FILE_ATTRIBUTE_NORMAL);
    v1 = fopen(FileName, "r");
    if (v1)
    {
        fscanf(v1, "%03d", &v6);
        v2 = 47 - v6;
        v6 = 47 - v6;
        if (v6)
        {
            v3 = kknd_sve_array_463070;
            while (1)
            {
                fscanf(v1, "%03d", &v7);
                v2 = v6;
                v7 ^= *v3;
                if (v7 != v6)
                    break;
                ++v3;
                if ((int)v3 >= (int)kknd_sve_array_4630AC)
                    goto LABEL_8;
            }
            v2 = 0;
            v6 = 0;
        }
    LABEL_8:
        if (v2)
            current_surv_level = 47 - v2;
        else
            current_surv_level = 0;
        fscanf(v1, "%03d", &v6);
        v4 = 69 - v6;
        v6 = 69 - v6;
        if (v6)
        {
            v5 = kknd_sve_array_4630AC;
            while (1)
            {
                fscanf(v1, "%03d", &v7);
                v4 = v6;
                v7 ^= *v5;
                if (v7 != v6)
                    break;
                ++v5;
                if ((int)v5 >= (int)&dword_4630E8)
                    goto LABEL_17;
            }
            v4 = 0;
            v6 = 0;
        }
    LABEL_17:
        if (v4)
        {
            current_mute_level = 69 - v4;
            fclose(v1);
        }
        else
        {
            current_mute_level = 0;
            fclose(v1);
        }
    }
    else
    {
        current_surv_level = 0;
        current_mute_level = 0;
    }
}

//----- (00424270) --------------------------------------------------------
void _424270_kknd_sve_read(const char *a1, _WORD *a2, _WORD *a3)
{
    _WORD *v3; // ebx@1
    FILE *v4; // edi@1
    int v5; // ecx@2
    int *v6; // esi@3
    int v7; // ecx@11
    int *v8; // esi@12
    int v9; // [sp+8h] [bp-8h]@2
    int v10; // [sp+Ch] [bp-4h]@4

    v3 = a2;
    v4 = fopen(a1, aR);
    if (v4)
    {
        fscanf(v4, "%03d", &v9);
        v5 = 47 - v9;
        v9 = 47 - v9;
        if (v9)
        {
            v6 = kknd_sve_array_463070;
            while (1)
            {
                fscanf(v4, "%03d", &v10);
                v5 = v9;
                v10 ^= *v6;
                if (v10 != v9)
                    break;
                ++v6;
                if ((int)v6 >= (int)kknd_sve_array_4630AC)
                    goto LABEL_8;
            }
            v5 = 0;
            v9 = 0;
        }
    LABEL_8:
        if (v5)
            *v3 = 47 - v5;
        else
            *v3 = 0;
        fscanf(v4, "%03d", &v9);
        v7 = 69 - v9;
        v9 = 69 - v9;
        if (v9)
        {
            v8 = kknd_sve_array_4630AC;
            while (1)
            {
                fscanf(v4, "%03d", &v10);
                v7 = v9;
                v10 ^= *v8;
                if (v10 != v9)
                    break;
                ++v8;
                if ((int)v8 >= (int)&dword_4630E8)
                    goto LABEL_17;
            }
            v7 = 0;
            v9 = 0;
        }
    LABEL_17:
        if (v7)
        {
            *a3 = 69 - v7;
            fclose(v4);
        }
        else
        {
            *a3 = 0;
            fclose(v4);
        }
    }
    else
    {
        *v3 = 0;
        *a3 = 0;
    }
}
// 4630E8: using guessed type int dword_4630E8;

//----- (004243C0) --------------------------------------------------------
void _4243C0_kknd_sve_update_last_level(const char *a1)
{
    FILE *v1; // edi@1
    int v2; // ebx@3
    int *v3; // esi@5
    int v4; // ebx@8
    int *v5; // esi@10
    int v6; // [sp+8h] [bp-108h]@1
    int a2; // [sp+Ch] [bp-104h]@1
    char filename[256]; // [sp+10h] [bp-100h]@1

    a2 = 0;
    v6 = 0;
    sprintf(filename, "%s\\%s", game_data_installation_dir, a1);
    //SetFileAttributesA(filename, FILE_ATTRIBUTE_NORMAL);

    short _a2, _v6;
    _424270_kknd_sve_read(filename, &_a2, &_v6);
    a2 = _a2;
    v6 = _v6;

    v1 = fopen(filename, "w");
    if (v1)
    {
        if ((unsigned __int16)current_surv_level <= (int)(unsigned __int16)a2)
        {
            v2 = 47 - (unsigned __int16)a2;
            fprintf(v1, "%03d", (unsigned __int16)a2);
            current_surv_level = a2;
        }
        else
        {
            v2 = 47 - (unsigned __int16)current_surv_level;
            fprintf(v1, "%03d", (unsigned __int16)current_surv_level);
        }
        v3 = kknd_sve_array_463070;
        do
        {
            fprintf(v1, "%03d", *v3 ^ v2);
            ++v3;
        } while ((int)v3 < (int)kknd_sve_array_4630AC);
        if ((unsigned __int16)current_mute_level <= (int)(unsigned __int16)v6)
        {
            v4 = 69 - (unsigned __int16)v6;
            fprintf(v1, "%03d", (unsigned __int16)v6);
            current_mute_level = v6;
        }
        else
        {
            v4 = 69 - (unsigned __int16)current_mute_level;
            fprintf(v1, "%03d", (unsigned __int16)current_mute_level);
        }
        v5 = kknd_sve_array_4630AC;
        do
        {
            fprintf(v1, "%03d", *v5 ^ v4);
            ++v5;
        } while ((int)v5 < (int)&dword_4630E8);
        fclose(v1);
    }
}

//----- (00438740) --------------------------------------------------------
bool _438740_save_lst()
{
    int v0; // esi@1
    FILE *v1; // eax@3
    FILE *v2; // ebx@3
    int v3; // edi@4
    stru175 *v4; // esi@4

    v0 = _47C050_array_idx;
    if (_47C050_array[_47C050_array_idx].str_0[0]
        && (sprintf(byte_47C230, aSGameD_sav, game_data_installation_dir, _47C050_array_idx),
            _41CAE0_prepare_to_load_level(byte_47C230, _47C050_array[v0].level_id))
        && (game_state = GAME_STATE::Mission,
            sprintf(byte_47C230, aSSave_lst, game_data_installation_dir),
            //SetFileAttributesA(byte_47C230, 0x80u),
            v1 = fopen(byte_47C230, "w"),
            (v2 = v1) != 0))
    {
        fprintf(v1, aActiveslotD, _47C050_array_idx);
        v3 = 0;
        v4 = _47C050_array;
        do
        {
            if (v4->str_0[0])
                fprintf(v2, "Slot %d = %s %d\n", v3, v4, v4->level_id);
            ++v4;
            ++v3;
        } while ((int)v4 < (int)byte_47C230);
        fclose(v2);
        return true;
    }
    return false;
}

//----- (00438840) --------------------------------------------------------
bool _438840_save_lst()
{
    int v0; // esi@1
    FILE *v1; // eax@3
    FILE *v2; // ebx@3
    int v3; // edi@4
    stru175 *v4; // esi@4

    v0 = _47C050_array_idx;
    if (_47C050_array[_47C050_array_idx].str_0[0]
        && (sprintf(byte_47C230, aSGameD_sav, game_data_installation_dir, _47C050_array_idx),
            _41CB30_prepare_to_save_level(byte_47C230, _47C050_array[v0].level_id))
        && (sprintf(byte_47C230, aSSave_lst, game_data_installation_dir),
            //SetFileAttributesA(byte_47C230, 0x80u),
            v1 = fopen(byte_47C230, "w"),
            (v2 = v1) != 0))
    {
        fprintf(v1, aActiveslotD, _47C050_array_idx);
        v3 = 0;
        v4 = _47C050_array;
        do
        {
            if (v4->str_0[0])
                fprintf(v2, "Slot %d = %s %d\n", v3, v4, v4->level_id);
            ++v4;
            ++v3;
        } while ((int)v4 < (int)byte_47C230);
        fclose(v2);
        return true;
    }
    return false;
}





//----- (004224B0) --------------------------------------------------------
void _4224B0_update_last_level()
{
    enum LEVEL_ID v0; // eax@2

    if (single_player_game)
    {
        v0 = current_level_idx;
        if (current_level_idx >= LEVEL_MUTE_01 && current_level_idx <= LEVEL_MUTE_15)
        {
            current_mute_level = current_level_idx - 14;
            _4243C0_kknd_sve_update_last_level(pKknd_sve);
            v0 = current_level_idx;
        }
        if (v0 >= LEVEL_SURV_01_THE_NEXT_GENERATION && v0 <= LEVEL_SURV_15)
        {
            current_surv_level = v0 + 1;
            _4243C0_kknd_sve_update_last_level(pKknd_sve);
        }
    }
}



//----- (00420A90) --------------------------------------------------------
_BYTE *GAME_Save_PackMapInfo(int *a1)
{
    int v1; // ebx@1
    MapdScrlImageTile **v2; // edi@1
    _BYTE *result; // eax@1
    _BYTE *v4; // esi@3
    char v5; // cl@6
    int v6; // [sp+8h] [bp-Ch]@4
    int *v7; // [sp+10h] [bp-4h]@1

    v7 = a1;
    v1 = (map_get_height() + 4) * (map_get_width() + 4);
    v2 = map_fog_of_war_scrl_tiles;
    result = (char *)malloc(v1);
    if (result)
    {
        v4 = result;
        if (v1 > 0)
        {
            v6 = v1;
            do
            {
                if (!*v2)
                    goto LABEL_17;
                v5 = 0;
                while (fog_of_war_scrl_source->tiles[v5] != *v2)
                {
                    if (++v5 >= 16)
                        goto LABEL_11;
                }
                *v4 = v5;
            LABEL_11:
                if (v5 == 16)
                    LABEL_17 :
                    *v4 = 0;
                ++v2;
                ++v4;
                --v6;
            } while (v6);
        }
        *v7 = v1;
    }
    else
    {
        errmsg_save[1] = aMemory;
    }
    return result;
}

//----- (00420B30) --------------------------------------------------------
MiscSaveStruct *GAME_Save_PackMiscInfo(size_t *a1)
{
    void *v1; // ebp@1
    size_t *v2; // esi@1
    size_t v3; // eax@1
    MiscSaveStruct *result; // eax@1
    MiscSaveStruct *v5; // ebx@1
    int v6; // eax@4
    Entity **v7; // eax@6
    int *v8; // edx@6
    int v9; // ecx@8
    int v13; // edi@21
    int v21; // eax@35

    v1 = _47C970_sidebar_task->param;
    v2 = a1;
    v3 = stru13construct_list_get_saveload_packed_size() + 376;// + sizeof(MiscSaveStruct)
    *v2 = v3;
    result = (MiscSaveStruct *)malloc(v3);
    v5 = result;
    if (result)
    {
        result->size = stru13construct_list_get_saveload_packed_size();
        memcpy(v5->num_units_in_group, num_units_in_group, sizeof(num_units_in_group));
        v5->field_30 = _47B3E0_unit_int_outpost_clanhall;
        memcpy(&v5->outpost_levels, &_47B3E0_outpost_levels, sizeof(v5->outpost_levels));
        v5->max_outpost_level = max_outpost_level;
        memcpy(&v5->clanhall_levels, &_477378_clanhall, sizeof(v5->clanhall_levels));
        v5->max_clanhall_level = max_clanhall_level;
        memcpy(&v5->machineshop_levels, &_47739C_machineshop, sizeof(v5->machineshop_levels));
        v5->max_machineshop_level = max_machineshop_level;
        memcpy(&v5->beastenclosure_levels, &_477318_beastenclosure, sizeof(v5->beastenclosure_levels));
        v5->max_beastenclosure_level = max_beastenclosure_level;
        memcpy(&v5->stru19_unit, &_47C978_production, sizeof(v5->stru19_unit));
        v5->num_player_units = UNIT_num_player_units;
        v5->num_total_units = UNIT_num_nonplayer_units;
        v5->num_players_towers = num_players_towers;
        v5->field_174 = _4269B0_task_attachment__4_some_task_flags;
        v5->__47A3D0_unit = _47A3D0_unit;
        v5->_47A3D4_unit = _47A3D4_tanker_convoy_units_left;
        v5->_47A3D8_unit = _47A3D8_num_convoy_tankers_still_to_arrive;
        if (entity_scout)
            v6 = entity_scout->entity_id;
        else
            v6 = -1;
        v5->scout_entity_id = v6;
        v7 = _47B3C0_player_outposts_clanhalls;
        v8 = v5->outposts_clanhalls_entity_ids;
        do
        {
            if (*v7)
                v9 = (*v7)->entity_id;
            else
                v9 = -1;
            *v8 = v9;
            ++v7;
            ++v8;
        } while ((int)v7 < (int)& _47B3D0_building_production_group);
        v5->_47A370_unit = _4269B0_task_attachment__num_units_spawned;
        v5->_47A2F8_unit = _4269B0_task_attachment__num_units_created_manually;
        v5->dword_47CA2C = _47CA2C_should_airstrike_mess_with_sidebar;
        v5->_47C970_stru0_ptr_3C_handler = get_handler_id(*(void **)v1);
        if (result)
        {
            v5->field_128 = *((_DWORD *)v1 + 1);
            result = (MiscSaveStruct *)GAME_Save_PackSprite(*((Sprite **)v1 + 2), (SpriteSerialized *)&v5->field_12C);
            if (result)
            {
                v13 = *((_DWORD *)v1 + 4);
                if (*(_DWORD *)(v13 + 24) == 1)
                {
                    v5->field_154 = *(_DWORD *)(v13 + 12);
                    v5->_158_script_handler_id = get_handler_id(*(void **)(v13 + 64));
                    v5->_15C_script_handler_id = get_handler_id(*(void **)(v13 + 52));
                    v5->field_160 = *(_DWORD *)(v13 + 32);
                    v5->field_164 = *(_DWORD *)(v13 + 20);
                    v5->field_168 = *(_DWORD *)(v13 + 36);
                    v5->field_16C = *(_DWORD *)(v13 + 40);
                    v5->field_170 = *(_DWORD *)(v13 + 44);
                    if (stru13construct_list_saveload_pack(&v5->field_178))
                    {
                        result = v5;
                    }
                    else
                    {
                        errmsg_save[1] = aBadConstructs;
                        free(v5);
                        result = 0;
                    }
                }
                else
                {
                    errmsg_save[1] = aTaskIsWrongTyp;
                    result = 0;
                }
            }
        }
        else
        {
            errmsg_save[1] = aBadMode;
        }
    }
    else
    {
        errmsg_save[1] = aMemory;
    }
    return result;
}

//----- (00420E30) --------------------------------------------------------
bool GAME_Load_UnpackMiscInfo(void *save_data)
{
    void *v1; // ebx@1
    int v3; // ecx@1
    _DWORD *v6; // esi@8
    unsigned int v8; // eax@15
    void(*v9)(Script *); // edx@17

    task_sidebar_attachment *v13; // esi@28
    unsigned int v14; // eax@29
    Script *v15; // eax@35

    v1 = save_data;
    memcpy(num_units_in_group, (char *)save_data + 4, sizeof(num_units_in_group));
    _47B3E0_unit_int_outpost_clanhall = *((_DWORD *)save_data + 12);
    memcpy(&_47B3E0_outpost_levels, (char *)save_data + 52, sizeof(_47B3E0_outpost_levels));
    max_outpost_level = *((_DWORD *)save_data + 22);
    memcpy(&_477378_clanhall, (char *)save_data + 92, sizeof(_477378_clanhall));
    max_clanhall_level = *((_DWORD *)save_data + 32);
    memcpy(&_47739C_machineshop, (char *)save_data + 132, sizeof(_47739C_machineshop));
    max_machineshop_level = *((_DWORD *)save_data + 42);
    memcpy(&_477318_beastenclosure, (char *)save_data + 172, sizeof(_477318_beastenclosure));
    max_beastenclosure_level = *((_DWORD *)save_data + 52);
    memcpy(&_47C978_production, (char *)save_data + 212, sizeof(_47C978_production));
    UNIT_num_player_units = *((_DWORD *)save_data + 59);
    UNIT_num_nonplayer_units = *((_DWORD *)save_data + 60);
    num_players_towers = *((_DWORD *)save_data + 61);
    _4269B0_task_attachment__4_some_task_flags = *((_DWORD *)save_data + 93);
    _47A3D0_unit = *((_DWORD *)save_data + 62);
    _47A3D4_tanker_convoy_units_left = *((_DWORD *)save_data + 63);
    _47A3D8_num_convoy_tankers_still_to_arrive = *((_DWORD *)save_data + 64);

    v3 = *((_DWORD *)save_data + 65);
    entity_scout = entityRepo->FindById(v3);
    if (entity_scout)
    {
        sprite_create_scripted(
            MOBD_CURSORS, 0, script_426710_mission_objectives_draw_x_mark, SCRIPT_COROUTINE, 0
        );
    }

    v6 = (int *)((int)v1 + 264);
    for (int i = 0; i < 4; ++i) {
        _47B3C0_player_outposts_clanhalls[i] = entityRepo->FindById(*v6);
        ++v6;
    }
    _47CA2C_should_airstrike_mess_with_sidebar = *((_DWORD *)v1 + 72);
    v8 = *((_DWORD *)v1 + 86);
    v9 = (void(*)(Script *))get_handler(v8 - 1);
    if (v9)
    {
        _47C970_sidebar_task = script_create_function(*((enum SCRIPT_TYPE *)v1 + 85), v9);
        auto result = (long)_47C970_sidebar_task;
        if (result)
        {
            *(_DWORD *)(result + 52) = (int)get_handler(*((_DWORD *)v1 + 87) - 1);
            *(_DWORD *)(result + 32) = *((_DWORD *)v1 + 88);
            *(_DWORD *)(result + 20) = *((_DWORD *)v1 + 89);
            *(_DWORD *)(result + 36) = *((_DWORD *)v1 + 90);
            *(_DWORD *)(result + 40) = *((_DWORD *)v1 + 91);
            *(_DWORD *)(result + 44) = *((_DWORD *)v1 + 92);
        }
    }
    else
    {
        _47C970_sidebar_task = 0;
        return false;
    }

    v13 = (task_sidebar_attachment *)script_create_local_object(_47C970_sidebar_task, 20);
    if (v13)
    {
        *(_DWORD *)((long)v13 + 16) = (int)_47C970_sidebar_task;
        v14 = *((_DWORD *)v1 + 73) - 1;
        v13->handler = (void *)get_handler(v14);
        if (v13->handler)
        {
            v13->field_4 = *((_DWORD *)v1 + 74);
            v13->_8_sprite = GAME_Load_UnpackSprite((SpriteSerialized *)((char *)v1 + 300));
            if (v13->_8_sprite)
            {
                v15 = v13->__47C970_sidebar_task;
                v13->_C_sprite_sidebar = _47CA08_sidebar_buttons[1]->sprite;
                v15->param = v13;
                v13->__47C970_sidebar_task->sprite = v13->_8_sprite;
                v13->_8_sprite->script = v13->__47C970_sidebar_task;
                v13->_C_sprite_sidebar->field_88_unused = 1;
                v13->_C_sprite_sidebar->x = 155648;
                v13->_C_sprite_sidebar->field_88_unused = 1;
                v13->_C_sprite_sidebar->y = 73728;
                v13->_C_sprite_sidebar->z_index = 2;
                v13->_8_sprite->field_88_unused = 1;
                v13->_8_sprite->x = 156672;
                v13->_8_sprite->field_88_unused = 1;
                v13->_8_sprite->y = 79872;
                v13->_8_sprite->z_index = 3;
                v13->_8_sprite->drawjob->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_4483E0_sidebar;
                if (v13->field_4 <= 1)
                    v13->_8_sprite->drawjob->flags |= 0x40000000u;
                if (v13->field_4 > 0)
                    script_trigger_event(0, EVT_MSG_1514, 0, _47CA08_sidebar_buttons[1]->task);
                v13->_8_sprite->drawjob->job_details.palette = per_player_sprite_palettes[player_sprite_color_by_player_side[player_side]];
                v13->_8_sprite->drawjob->flags |= 0x10000000u;
                sprite_4272E0_load_mobd_item(v13->_8_sprite, 2276, 0);
                return stru13construct_list_saveload_unpack((int)v1 + 376, *(_DWORD *)v1) != 0;
            }
        }
    }

    return false;
}

//----- (004211D0) --------------------------------------------------------
int GAME_Save()
{
    EntitySaveStructIndex *entity_sAve_data_index; // ebp@1
    OilDepositSaveStruct *oil_save_data; // ebx@3
    int entity_save_size; // eax@7
    enum UNIT_ID v5; // ecx@9
    void *entity_save_data; // eax@20
    void *entity_sAve_data; // ebp@20
    int entity_save_data_i; // edi@22
    int *pentity_save_data_size; // ebx@23
    void *cpu_players; // esi@29
    char *production_info; // edi@31
    _BYTE *map_info; // ebx@34
    FILE *file; // eax@41
    FILE *fIle; // esi@41
    int v17; // ebx@50
    char *entity_offsets; // ebx@59
    void *entity_indices; // edi@60
    int all_data_ok; // [sp+14h] [bp-44h]@1
    void *entity_savE_data; // [sp+18h] [bp-40h]@1
    void *cpU_players; // [sp+1Ch] [bp-3Ch]@1
    char *productiOn_info; // [sp+20h] [bp-38h]@1
    void *v26; // [sp+24h] [bp-34h]@1
    MiscSaveStruct *misc_info; // [sp+28h] [bp-30h]@1
    int save; // [sp+2Ch] [bp-2Ch]@1
    size_t total_entity_size; // [sp+30h] [bp-28h]@1
    int max_entity_save_size; // [sp+34h] [bp-24h]@1
    size_t oil_data_size; // [sp+38h] [bp-20h]@3
    size_t cpu_players_size; // [sp+3Ch] [bp-1Ch]@29
    size_t production_info_size; // [sp+40h] [bp-18h]@31
    size_t map_info_size; // [sp+44h] [bp-14h]@34
    size_t misc_info_size; // [sp+48h] [bp-10h]@36
    int minus_1; // [sp+4Ch] [bp-Ch]@1
    int mapd_cplc_dim[2]; // [sp+50h] [bp-8h]@3

    entity_savE_data = 0;
    cpU_players = 0;
    productiOn_info = 0;
    v26 = 0;
    misc_info = 0;
    minus_1 = -1;
    max_entity_save_size = 0;
    all_data_ok = 0;
    total_entity_size = 0;
    entity_sAve_data_index = (EntitySaveStructIndex *)malloc(0x12B8u);
    save = (int)entity_sAve_data_index;
    if (!entity_sAve_data_index)
    {
        errmsg_save[0] = aCouldnTAllocat;
        return 0;
    }
    mapd_cplc_dim[1] = _47C380_mapd.mapd_cplc_render_y;
    mapd_cplc_dim[0] = _47C380_mapd.mapd_cplc_render_x;
    oil_save_data = GAME_Save_PackOilData(&oil_data_size);
    if (!oil_save_data)
    {
        errmsg_save[0] = aCouldNotSaveOi;
        goto LABEL_40;
    }

    for (auto i : entityRepo->FindAll()) {
        //for (i = entity_list_head; (Entity **)i != &entity_list_head; i = i->next)
        //{
        if (!i->destroyed)
        {
            entity_save_size = 748;
            entity_sAve_data_index->entity_field_130 = i->entity_id;
            if (i->destroyed)
            {
                entity_save_size = 0;
            }
            else
            {
                v5 = i->unit_id;
                switch (v5)
                {
                case 0x17u:
                case 0x18u:
                    entity_save_size = 860;
                    break;
                case 0x19u:
                    entity_save_size = 760;
                    break;
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
                    entity_save_size = 776;
                    if ((v5 == 65 || v5 == 66) && *((_DWORD *)i->state + 2))
                        entity_save_size = 868;
                    break;
                default:
                    break;
                }
            }
            entity_sAve_data_index->entity_save_size = entity_save_size;
            total_entity_size += entity_save_size;
            if (entity_save_size > max_entity_save_size)
                max_entity_save_size = entity_save_size;
            ++entity_sAve_data_index;
        }
    }
    entity_save_data = malloc(total_entity_size);
    entity_sAve_data = entity_save_data;
    entity_savE_data = entity_save_data;
    if (!entity_save_data)
    {
        errmsg_save[0] = aCouldNotAlloca;
        free(oil_save_data);
        goto LABEL_40;
    }

    entity_save_data_i = (int)entity_save_data;
    pentity_save_data_size = (int *)(save + 4);
    for (auto v8 : entityRepo->FindAll()) {
        if (!v8->destroyed)
        {
            if (!GAME_Save_PackEntity(v8, entity_save_data_i, *pentity_save_data_size))
            {
                free(entity_sAve_data);
                free(oil_save_data);
                game_save_in_progress = 0;
                errmsg_save[0] = aCouldNotSaveUn;
                return 0;
            }
            entity_save_data_i += *pentity_save_data_size;
            pentity_save_data_size += 2;
        }
    }

    cpu_players = GAME_Save_PackAiPlayers(&cpu_players_size);
    cpU_players = cpu_players;
    if (!cpu_players)
    {
        errmsg_save[0] = aCouldNotSaveCp;
    LABEL_33:
        free(entity_sAve_data);
        free(oil_save_data);
        goto LABEL_40;
    }
    production_info = GAME_Save_PackProductionInfo(&production_info_size);
    productiOn_info = production_info;
    if (!production_info)
    {
        errmsg_save[0] = aCouldNotSavePr;
        free(cpu_players);
        goto LABEL_33;
    }
    map_info = GAME_Save_PackMapInfo((int *)&map_info_size);
    v26 = map_info;
    if (map_info)
    {
        misc_info = GAME_Save_PackMiscInfo(&misc_info_size);
        if (misc_info)
        {
            all_data_ok = 1;
        }
        else
        {
            errmsg_save[0] = aCouldNotSaveMi;
            free(map_info);
            free(production_info);
            free(cpu_players);
            free(entity_sAve_data);
            free(oil_save_data);
        }
    }
    else
    {
        errmsg_save[0] = aCouldNotSaveMa;
        free(production_info);
        free(cpu_players);
        free(entity_sAve_data);
        free(oil_save_data);
    }

LABEL_40:
    if (!all_data_ok)
    {
    LABEL_80:
        game_save_in_progress = 0;
        free((void *)save);
        return all_data_ok;
    }
    all_data_ok = 0;
    //SetFileAttributesA(current_savegame_filename, 0x80u);
    file = fopen(current_savegame_filename, "wb");
    fIle = file;
    if (!file)
    {
        game_save_in_progress = 0;
        errmsg_save[0] = aCouldnTOpenSav;
        return 0;
    }
    if (!fwrite(&player_side, 1u, 4u, file)
        || !fwrite(&game_globals_per_player, 1u, 0x1Cu, fIle)
        || !fwrite(game_globals_cpu, 1u, 0xC4u, fIle)
        || !fwrite(mapd_cplc_dim, 1u, 8u, fIle)
        || !fwrite(&oil_data_size, 1u, 4u, fIle)
        || !fwrite(oil_save_data, 1u, oil_data_size, fIle))
    {
        goto LABEL_78;
    }
    free(oil_save_data);

    v17 = save;
    for (auto v16 : entityRepo->FindAll()) {
        //if ((Entity **)entity_list_head != &entity_list_head)
        if (!v16->destroyed)
        {
            if (!fwrite((void *)v17, 1u, 4u, fIle))
            {
                free(misc_info);
                free(v26);
                free(productiOn_info);
                free(cpU_players);
                free(entity_savE_data);
                goto LABEL_68;
            }
            v17 += 8;
        }
    }
    if (!fwrite(&minus_1, 1u, 4u, fIle) || !fwrite(&max_entity_save_size, 1u, 4u, fIle))
    {
    LABEL_78:
        fclose(fIle);
        if (!all_data_ok)
            errmsg_save[0] = aCouldnTWriteTo;
        goto LABEL_80;
    }

    entity_offsets = (char *)entity_savE_data;
    entity_indices = (void *)(save + 4);
    for (auto v18 : entityRepo->FindAll()) {
        if (!v18->destroyed) {
            if (fwrite(entity_indices, 1u, 4u, fIle) && fwrite(entity_offsets, 1u, *(_DWORD *)entity_indices, fIle)) {
                entity_offsets += *(_DWORD *)entity_indices;
                entity_indices = (char *)entity_indices + 8;
            } else {
                break;
            }
        }
    }

    free(entity_savE_data);
    if (fwrite(&cpu_players_size, 1u, 4u, fIle))
    {
        if (fwrite(cpU_players, 1u, cpu_players_size, fIle))
        {
            free(cpU_players);
            if (fwrite(&production_info_size, 1u, 4u, fIle))
            {
                if (fwrite(productiOn_info, 1u, production_info_size, fIle))
                {
                    free(productiOn_info);
                    if (fwrite(&map_info_size, 1u, 4u, fIle))
                    {
                        if (fwrite(v26, 1u, map_info_size, fIle))
                        {
                            free(v26);
                            if (fwrite(&misc_info_size, 1u, 4u, fIle))
                            {
                                if (fwrite(misc_info, 1u, misc_info_size, fIle))
                                {
                                    free(misc_info);
                                    all_data_ok = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    entity_indices = (void *)(save + 4);

    free(misc_info);
    free(v26);
    free(cpU_players);
    free(productiOn_info);
    free(entity_savE_data);
    free(oil_save_data);

LABEL_68:
    fclose(fIle);
    game_save_in_progress = 0;
    return 0;
}

//----- (004218B0) --------------------------------------------------------
int GAME_Load()
{
    char v0; // bl@1
    Sprite *v1; // eax@1
    Script *v2; // eax@2
    FILE *v3; // eax@3
    FILE *v4; // edi@3
    OilDepositSaveStruct *oil_save_data; // eax@9
    int i; // ecx@13
    Entity *v8; // eax@14
    Entity *v9; // ecx@20
    Entity *v10; // edx@20
    void *minus1_sized_block; // ebp@23
                              //Entity *v12; // esi@24
    enum PLAYER_SIDE v13; // eax@28
    void *entity_data; // eax@34
    void *v16; // eax@38
    void *v17; // esi@38
    char *v18; // eax@42
    char *v19; // ebp@42
    MapdScrlImageTile **v20; // ecx@44
    char *v21; // edx@44
    int v22; // esi@45
    char v23; // al@46
    MapdScrlImageTile *v24; // eax@48
    void *v25; // esi@52
    int result; // eax@56
    size_t block_size; // [sp+10h] [bp-14h]@8
    int ptr; // [sp+14h] [bp-10h]@1
    int v29; // [sp+18h] [bp-Ch]@1
    int mapd_cplc_dim[2]; // [sp+1Ch] [bp-8h]@7

    v0 = 0;
    ptr = -1;
    v29 = 0;
    v1 = sprite_list_find_by_mobd_id(MOBD_CURSORS);
    if (!v1
        || (v2 = v1->script) == 0
        || (game_cursor_script = v2,
            UNIT_num_player_units = 0,
            UNIT_num_nonplayer_units = 0,
            v3 = fopen(current_savegame_filename, "rb"),
            (v4 = v3) == 0))
    {
        game_load_in_progress = 0;
        return 0;
    }
    if (!fread(&player_side, 1u, 4u, v3))
        goto LABEL_56;
    if (!fread(&game_globals_per_player, 1u, 0x1Cu, v4))
        goto LABEL_56;
    if (!fread(game_globals_cpu, 1u, 0xC4u, v4))
        goto LABEL_56;
    if (!fread(mapd_cplc_dim, 1u, 8u, v4))
        goto LABEL_56;
    _47C380_mapd.mapd_cplc_render_x = mapd_cplc_dim[0];
    _47C380_mapd.mapd_cplc_render_y = mapd_cplc_dim[1];
    if (!fread(&block_size, 1u, 4u, v4))
        goto LABEL_56;
    oil_save_data = (OilDepositSaveStruct *)malloc(block_size);
    if (!oil_save_data)
        goto LABEL_56;
    if (!fread(oil_save_data, 1u, block_size, v4))
        goto LABEL_56;
    if (!GAME_Load_UnpackOilData(oil_save_data))
        goto LABEL_56;
    free(oil_save_data);

    if (!fread(&ptr, 1u, 4u, v4))
        goto LABEL_56;

    for (i = ptr; ptr != -1; i = ptr)
    {
        //v8 = entity_list_free_pool;
        //if (entity_list_free_pool)
        //	entity_list_free_pool = entity_list_free_pool->next;
        //else
        //	v8 = 0;
        v8 = 0;//if (!v8)
        goto LABEL_59;
        v8->entity_id = i;
        if (ptr >= _47DCC4_entity_id_counter)
            _47DCC4_entity_id_counter = ptr + 1;
        //v9 = entity_list_47D9AC;
        //v10 = entity_list_47D9AC->next;
        //v8->prev = entity_list_47D9AC;
        //v8->next = v10;
        //v9->next->prev = v8;
        //v9->next = v8;
        if (!fread(&ptr, 1u, 4u, v4))
            goto LABEL_59;
    }
    if (!fread(&block_size, 1u, 4u, v4))
        goto LABEL_56;
    minus1_sized_block = malloc(block_size);
    if (!minus1_sized_block)
    {
    LABEL_56:
        fclose(v4);
        result = v29;
        game_load_in_progress = 0;
        return result;
    }

    if (entityRepo->CountAll() <= 0)
    {
    LABEL_33:
        free(minus1_sized_block);
        if (fread(&block_size, 1u, 4u, v4))// max entity save size
        {
            entity_data = malloc(block_size);
            if (entity_data)
            {
                if (fread(entity_data, 1u, block_size, v4))
                {
                    if (GAME_Load_UnpackAiPlayers(entity_data))
                    {
                        free(entity_data);
                        if (fread(&block_size, 1u, 4u, v4))
                        {
                            v16 = malloc(block_size);
                            v17 = v16;
                            if (v16)
                            {
                                if (fread(v16, 1u, block_size, v4))
                                {
                                    if (GAME_Load_UnpackProductionInfo(v17))
                                    {
                                        free(v17);
                                        if (fread(&block_size, 1u, 4u, v4))
                                        {
                                            v18 = (char *)malloc(block_size);
                                            v19 = v18;
                                            if (v18)
                                            {
                                                if (fread(v18, 1u, block_size, v4))
                                                {
                                                    v20 = map_fog_of_war_scrl_tiles;
                                                    v21 = v19;
                                                    if ((map_get_height() + 4) * (map_get_width() + 4) > 0)
                                                    {
                                                        v22 = (map_get_height() + 4) * (map_get_width() + 4);
                                                        do
                                                        {
                                                            v23 = *v21;
                                                            if (*v21 <= v0 || v23 >= 16)
                                                            {
                                                                v24 = 0;
                                                            }
                                                            else
                                                            {
                                                                v24 = fog_of_war_scrl_source->tiles[v23];
                                                                v0 = 0;
                                                            }
                                                            *v20 = v24;
                                                            ++v20;
                                                            ++v21;
                                                            --v22;
                                                        } while (v22);
                                                    }
                                                    _44A780_gof_of_war();
                                                    free(v19);
                                                    if (fread(&block_size, 1u, 4u, v4))
                                                    {
                                                        v25 = malloc(block_size);
                                                        if (v25)
                                                        {
                                                            if (fread(v25, 1u, block_size, v4))
                                                            {
                                                                if (GAME_Load_UnpackMiscInfo(v25))
                                                                {
                                                                    free(v25);
                                                                    v29 = 1;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        goto LABEL_56;
    }

    while (fread(&block_size, 1u, 4u, v4)
        && fread(minus1_sized_block, 1u, block_size, v4))
    {
        auto v12 = EntityFactory().Unpack((EntitySerialized *)minus1_sized_block);
        if (v12 == nullptr) {
            break;
        }
        entityRepo->Save(v12);

        v13 = v12->player_side;
        if (v13 == player_side)
        {
            ++UNIT_num_player_units;
        }
        else if (v13)
        {
            ++UNIT_num_nonplayer_units;
        }
    }
    free(minus1_sized_block);
LABEL_59:
    fclose(v4);
    game_load_in_progress = 0;
    return 0;
}

//----- (00421D40) --------------------------------------------------------
void GAME_OnSaveFailed()
{
    auto v0 = script_create_coroutine(
        SCRIPT_TYPE_INVALID, script_421D60_on_savegame_failed, 0
    );
    if (v0)
        v0->field_1C |= 1;
}

//----- (00421D60) --------------------------------------------------------
void script_421D60_on_savegame_failed(Script *a1)
{
    unsigned int v1; // esi@1
    unsigned int v2; // edi@1
    int v3; // ebx@1
    int v4; // eax@1
    RenderString *v5; // eax@1
    RenderString *v6; // esi@1

    sprintf(str, aSS_0, errmsg_save[0], errmsg_save[1]);
    v1 = (unsigned int)render_width >> 1;
    v2 = (unsigned int)render_height >> 1;
    v3 = _445C00_text(str, 128);
    v4 = _445C80_text(str, 128);
    v5 = render_string_create(
        0,
        currently_running_lvl_mobd[MOBD_FONT_27].items,
        v1 - (8 * (v4 + 2) >> 1),
        v2 - 32,
        v4 + 2,
        v3 + 2,
        0x40000000,
        8,
        8);
    v6 = v5;
    if (v5)
    {
        render_string_445770(v5, str, 0);
        script_sleep(a1, 180);
        render_string_list_remove(v6);
    }
}


//----- (0041F960) --------------------------------------------------------
bool GAME_Load_UnpackAiPlayers(void *save_data)
{
    int v1; // eax@1
    char *v2; // edi@1
    Script *v3; // ecx@2
    stru24 *v4; // ebx@3
    char *v5; // ebp@3
    int v6; // edi@3
    unsigned int v7; // eax@3
    void(*v8)(Script *); // eax@5
    enum PLAYER_SIDE v9; // eax@8
    int v10; // esi@8
    stru24_EnemyNode *v11; // ecx@9
    stru24_stru10_convoy *v14; // esi@23
    _DWORD *v16; // ebp@32
    stru24_stru160 *v17; // eax@33
    int v18; // edi@37
    stru24_AttackerNode *v19; // eax@38
    int v23; // esi@54
    stru24_WandererNode *v24; // ecx@55
    int v27; // esi@68
    stru24_stru40 *v28; // ecx@69
    int v31; // esi@82
    stru24_AttackerNode *v32; // eax@83
    Entity *v35; // ecx@94
    int v36; // esi@96
    stru24_AttackerNode *v37; // eax@97
    Entity *v40; // ecx@108
    int i; // ebp@110
    stru24_stru94 *v42; // esi@111
    void *v44; // ecx@120
    int v45; // eax@120
    int j; // esi@123
    stru24_PowerPlantNode *v47; // eax@124
    int v50; // eax@134
    stru24_DrillRigNode *v51; // esi@135
    int v52; // edi@135
    stru24 *v54; // eax@146
    _DWORD *v55; // ebp@152
    int *v56; // edi@152
    stru24_DrillRigNode *v57; // ecx@152
    stru24_stru160 *v58; // eax@153
    stru24_AttackerNode *v59; // eax@158
    int v62; // ecx@173
    int v63; // ebp@173
    stru24_OilTankerNode *v64; // eax@174
    int v65; // edi@178
    char *v67; // edi@185
    int k; // esi@185
    stru24_OilTankerNode *v69; // eax@186
    int v70; // edx@190
    stru24_stru160 *v72; // esi@197
    _DWORD *v73; // edi@197
    int v74; // ebp@201
    stru24_AttackerNode *v75; // eax@202
    int v76; // edx@206
    Entity *v78; // edx@213
    stru24_stru160 *v79; // esi@218
    _DWORD *v80; // edi@218
    int v81; // ebp@222
    stru24_AttackerNode *v82; // eax@223
    int v83; // edx@227
    Entity *v85; // edx@234
    stru24_stru160 *v86; // eax@237
    stru24_stru160 *v87; // eax@240
    _DWORD *v88; // esi@241
    int v89; // ebp@242
    stru24_AttackerNode *v90; // eax@243
    int v91; // edx@247
    stru24_stru160 *v93; // esi@259
    _DWORD *v94; // edi@259
    int v95; // ebp@263
    stru24_AttackerNode *v96; // eax@264
    int v97; // edx@268
    Entity *v99; // ecx@275
    int v100; // edx@278
    int *v101; // edi@279
    stru24_stru26C *v102; // eax@280
    int v103; // ecx@284
    int v104; // ecx@284
    int v105; // esi@287
    int v106; // edi@287
    int l; // ecx@287
    stru24_stru310 *v108; // eax@288
    stru24_stru310 *v109; // eax@294
    int v111; // eax@304
    int v112; // ecx@306
    enum UNIT_ID v113; // ecx@307
    int a2; // [sp+10h] [bp-18h]@3
    char *v117; // [sp+14h] [bp-14h]@3
    int v118; // [sp+18h] [bp-10h]@22
    int v119; // [sp+18h] [bp-10h]@157
    int v120; // [sp+18h] [bp-10h]@196
    int v121; // [sp+18h] [bp-10h]@217
    int v122; // [sp+18h] [bp-10h]@258
    _DWORD *v123; // [sp+1Ch] [bp-Ch]@152
    int v124; // [sp+20h] [bp-8h]@1
    int v125; // [sp+24h] [bp-4h]@139

    v1 = 0;
    v2 = (char *)save_data;
    v124 = 0;
    while (1)
    {
        v3 = task_ai_players[v1];
        if (!v3)
            goto LABEL_316;
        v4 = (stru24 *)v3->param;
        v5 = v2;
        v6 = (int)(v2 + 284);
        v117 = v5;
        v7 = *(_DWORD *)v5;
        a2 = v6;
        v3->handler = (void(*)(Script *))get_handler(v7 - 1);
        v3->debug_handler_name = get_handler_name(v7 - 1);
        if (!v3->handler)
            return 0;
        v9 = (PLAYER_SIDE)*((_DWORD *)v5 + 40);
        v4->_2A0_player_side = v9;
        v10 = 0;
        v4->_2A8_p_globals_cash = &game_globals_per_player.cash[v9];
        v4->_2DC_unit_id = (UNIT_ID)*((_DWORD *)v5 + 54);
        if (*((_DWORD *)v5 + 10) > 0)
            break;
    LABEL_22:
        v118 = 0;
        if (*((_DWORD *)v5 + 1) > 0)
        {
            do
            {
                v14 = v4->list_10_convoy_head;
                if (v14)
                    v4->list_10_convoy_head = v14->next;
                else
                    v14 = 0;
                if (!v14)
                    return 0;

                auto v15 = entityRepo->FindById(*(_DWORD *)v6);
                v14->_8_entity = v15;
                v16 = (_DWORD *)(v6 + 4);
                v15->_24_ai_node_per_player_side._0_ai_node_per_player_side[v4->_2A0_player_side] = (int)v14;
                a2 = v6 + 44;
                if (*(_DWORD *)(v6 + 4))
                {
                    v17 = v4->list_160_head;
                    if (v17)
                    {
                        v14->field_C = (int)v17;
                        v4->list_160_head = v4->list_160_head->next;
                    }
                    else
                    {
                        v14->field_C = 0;
                    }
                    if (!v14->field_C)
                        return 0;
                    sub_41EE20(v4, (int)v16, (stru24_stru160 *)v14->field_C);
                    v18 = 0;
                    if (*v16 > 0)
                    {
                        do
                        {
                            v19 = v4->attacker_list_free_pool;
                            if (v19)
                                v4->attacker_list_free_pool = v19->next;
                            else
                                v19 = 0;
                            if (!v19)
                                return 0;
                            a2 += 4;
                            auto v22 = entityRepo->FindById(*(_DWORD *)a2);
                            v19->entity = v22;
                            if (v22)
                            {
                                v19->list_8 = (stru24_stru160 *)v14->field_C;
                                v19->entity->_24_ai_node_per_player_side._0_ai_node_per_player_side[v4->_2A0_player_side] = (int)v19;
                                v19->next = *(stru24_AttackerNode **)(v14->field_C + 12);
                                v19->prev = (stru24_AttackerNode *)(v14->field_C + 12);
                                *(_DWORD *)(*(_DWORD *)(v14->field_C + 12) + 4) = (int)v19;
                                *(_DWORD *)(v14->field_C + 12) = (int)v19;
                            }
                            else
                            {
                                v19->next = v4->attacker_list_free_pool;
                                v4->attacker_list_free_pool = v19;
                            }
                        } while (++v18 < *v16);
                    }
                    *(_DWORD *)v14->field_C = (int)v4->list_11C;
                    *(_DWORD *)(v14->field_C + 4) = (int)((char *)v4 + 284);
                    v4->list_11C->prev = (stru24_stru160 *)v14->field_C;
                    v4->list_11C = (stru24_stru160 *)v14->field_C;
                }
                else
                {
                    v14->field_C = 0;
                }
                v14->next = (stru24_stru10_convoy *)v4->next;
                v14->prev = (stru24_stru10_convoy *)v4;
                v6 = a2;
                v4->next->prev = (stru24 *)v14;
                v4->next = (stru24 *)v14;
            } while (++v118 < *((_DWORD *)v117 + 1));
        }
        v23 = 0;
        if (*((_DWORD *)v117 + 2) > 0)
        {
            do
            {
                v24 = v4->wanderer_list_free_pool;
                if (v24)
                    v4->wanderer_list_free_pool = v24->next;
                else
                    v24 = 0;
                if (!v24)
                    return 0;
                v6 += 4;
                a2 = v6;
                auto v26 = entityRepo->FindById(*(_DWORD *)v6);
                v24->entity = v26;
                if (v26)
                {
                    v24->entity->_24_ai_node_per_player_side._0_ai_node_per_player_side[v4->_2A0_player_side] = (int)v24;
                    v24->next = v4->wanderer_list_18;
                    v24->prev = (stru24_WandererNode *)&v4->wanderer_list_18;
                    v4->wanderer_list_18->prev = v24;
                    v4->wanderer_list_18 = v24;
                }
                else
                {
                    v24->next = v4->wanderer_list_free_pool;
                    v4->wanderer_list_free_pool = v24;
                }
            } while (++v23 < *((_DWORD *)v117 + 2));
        }
        v27 = 0;
        if (*((_DWORD *)v117 + 3) > 0)
        {
            do
            {
                v28 = v4->list_40_head;
                if (v28)
                    v4->list_40_head = v28->next;
                else
                    v28 = 0;
                if (!v28)
                    return 0;
                v6 += 4;
                a2 = v6;
                auto v30 = entityRepo->FindById(*(_DWORD *)v6);
                v28->_C__entity = v30;
                if (v30)
                {
                    v28->_C__entity->_24_ai_node_per_player_side._0_ai_node_per_player_side[v4->_2A0_player_side] = (int)v28;
                    v28->next = v4->list_40_30;
                    v28->prev = (stru24_stru40 *)&v4->list_40_30;
                    v4->list_40_30->prev = v28;
                    v4->list_40_30 = v28;
                }
                else
                {
                    v28->next = v4->list_40_head;
                    v4->list_40_head = v28;
                }
            } while (++v27 < *((_DWORD *)v117 + 3));
        }
        v31 = 0;
        if (*((_DWORD *)v117 + 4) > 0)
        {
            do
            {
                v32 = v4->attacker_list_free_pool;
                if (v32)
                    v4->attacker_list_free_pool = v32->next;
                else
                    v32 = 0;
                if (!v32)
                    return 0;
                v6 += 4;
                a2 = v6;
                auto v34 = entityRepo->FindById(*(_DWORD *)v6);
                v32->entity = v34;
                if (v34)
                {
                    v35 = v32->entity;
                    v32->list_8 = 0;
                    v35->_24_ai_node_per_player_side._0_ai_node_per_player_side[v4->_2A0_player_side] = (int)v32;
                    v32->next = v4->attacker_list_48;
                    v32->prev = (stru24_AttackerNode *)&v4->attacker_list_48;
                    v4->attacker_list_48->prev = v32;
                    v4->attacker_list_48 = v32;
                }
                else
                {
                    v32->next = v4->attacker_list_free_pool;
                    v4->attacker_list_free_pool = v32;
                }
            } while (++v31 < *((_DWORD *)v117 + 4));
        }
        v36 = 0;
        if (*((_DWORD *)v117 + 5) > 0)
        {
            do
            {
                v37 = v4->attacker_list_free_pool;
                if (v37)
                    v4->attacker_list_free_pool = v37->next;
                else
                    v37 = 0;
                if (!v37)
                    return 0;
                v6 += 4;
                a2 = v6;

                auto v39 = entityRepo->FindById(*(_DWORD *)v6);
                v37->entity = v39;
                if (v39)
                {
                    v40 = v37->entity;
                    v37->list_8 = 0;
                    v40->_24_ai_node_per_player_side._0_ai_node_per_player_side[v4->_2A0_player_side] = (int)v37;
                    v37->next = v4->marshalling_nodes_list__evmission8_only_60;
                    v37->prev = (stru24_AttackerNode *)&v4->marshalling_nodes_list__evmission8_only_60;
                    v4->marshalling_nodes_list__evmission8_only_60->prev = v37;
                    v4->marshalling_nodes_list__evmission8_only_60 = v37;
                }
                else
                {
                    v37->next = v4->attacker_list_free_pool;
                    v4->attacker_list_free_pool = v37;
                }
            } while (++v36 < *((_DWORD *)v117 + 5));
        }
        for (i = 0; i < *((_DWORD *)v117 + 6); a2 = v6)
        {
            v42 = v4->list_94_head;
            if (v42)
                v4->list_94_head = v42->next;
            else
                v42 = 0;
            if (!v42)
                return 0;

            auto v43 = entityRepo->FindById(*(_DWORD *)v6);
            v42->_8_entity = v43;
            v43->_24_ai_node_per_player_side._0_ai_node_per_player_side[v4->_2A0_player_side] = (int)v42;
            v42->_14_cost = *(_DWORD *)(v6 + 8);
            v42->_18_cost_per_time_step = *(_DWORD *)(v6 + 12);
            v44 = *(void **)(v6 + 16);
            v42->_8_entity_script_param = (int)v44;
            v45 = *(_DWORD *)(v6 + 4);
            v42->_C_cost = v45;
            if (v45 > 0)
                stru37_list_427D80_enqueue_item(
                (int *)(4 * v4->_2A0_player_side + 4704680),
                    &v42->_C_cost,
                    v42->_14_cost,
                    v42->_18_cost_per_time_step,
                    v42->_8_entity->script,
                    v44,
                    -1);
            v42->next = v4->list_94_78;
            v42->prev = (stru24 *)((char *)v4 + 120);
            v6 += 20;
            ++i;
            v4->list_94_78->prev = (stru24 *)v42;
            v4->list_94_78 = v42;
        }
        for (j = 0; j < *((_DWORD *)v117 + 9); v4->power_plant_list_F4 = v47)
        {
            v47 = v4->power_plant_list_free_pool;
            if (v47)
                v4->power_plant_list_free_pool = v47->next;
            else
                v47 = 0;
            if (!v47)
                return 0;
            v6 += 4;
            a2 = v6;

            auto v49 = entityRepo->FindById(*(_DWORD *)v6);
            v47->entity = v49;
            ++j;
            v49->_24_ai_node_per_player_side._0_ai_node_per_player_side[v4->_2A0_player_side] = (int)v47;
            v47->next = v4->power_plant_list_F4;
            v47->prev = (stru24_PowerPlantNode *)&v4->power_plant_list_F4;
            v4->power_plant_list_F4->prev = v47;
        }
        v50 = 0;
        if (*((_DWORD *)v117 + 7) > 0)
        {
            do
            {
                v51 = v4->drill_rig_list_free_pool;
                v52 = a2;
                if (v51)
                    v4->drill_rig_list_free_pool = v51->next;
                else
                    v51 = 0;
                if (!v51)
                    return 0;
                v125 = v50 + 1;
                if (*((_DWORD *)v117 + 57) == v50 + 1)
                    v4->_2E8_drillrig_node = v51;

                auto v53 = entityRepo->FindById(*(_DWORD *)a2);
                v51->entity = v53;
                v53->_24_ai_node_per_player_side._0_ai_node_per_player_side[v4->_2A0_player_side] = (int)v51;
                v51->ptr_28 = 0;
                v54 = (stru24 *)v4->power_plant_list_F4;
                if ((stru24_PowerPlantNode **)v54 != &v4->power_plant_list_F4)
                {
                    while (v54->_8_entity->entity_id != *(_DWORD *)(a2 + 44))
                    {
                        v54 = v54->next;
                        if ((stru24_PowerPlantNode **)v54 == &v4->power_plant_list_F4)
                            goto LABEL_151;
                    }
                    v51->ptr_28 = (stru24_PowerPlantNode *)v54;
                LABEL_151:
                    v52 = a2;
                }
                v55 = (_DWORD *)(a2 + 4);
                v51->field_2C = *(_DWORD *)(v52 + 48);
                v51->field_30 = *(_DWORD *)(v52 + 52);
                v123 = (_DWORD *)(v52 + 52);
                v51->field_34 = *(_DWORD *)(v52 + 56);
                v56 = (int *)(v52 + 60);
                v57 = v4->drill_rig_list_9C;
                v51->prev = (stru24_DrillRigNode *)&v4->drill_rig_list_9C;
                v51->next = v57;
                a2 = (int)v56;
                v4->drill_rig_list_9C->prev = v51;
                v4->drill_rig_list_9C = v51;
                if (*v55)
                {
                    v58 = v4->list_160_head;
                    if (v58)
                    {
                        v51->pstru24_stru160 = v58;
                        v4->list_160_head = v4->list_160_head->next;
                    }
                    else
                    {
                        v51->pstru24_stru160 = 0;
                    }
                    if (!v51->pstru24_stru160)
                        return 0;
                    sub_41EE20(v4, (int)v55, v51->pstru24_stru160);
                    v119 = 0;
                    if (*v55 > 0)
                    {
                        do
                        {
                            v59 = v4->attacker_list_free_pool;
                            if (v59)
                                v4->attacker_list_free_pool = v59->next;
                            else
                                v59 = 0;
                            if (!v59)
                                return 0;
                            ++v56;
                            a2 = (int)v56;

                            auto v61 = entityRepo->FindById(*v56);
                            v59->entity = v61;
                            if (v61)
                            {
                                v59->list_8 = v51->pstru24_stru160;
                                v59->entity->_24_ai_node_per_player_side._0_ai_node_per_player_side[v4->_2A0_player_side] = (int)v59;
                                v59->next = (stru24_AttackerNode *)v51->pstru24_stru160->_C_next;
                                v59->prev = (stru24_AttackerNode *)&v51->pstru24_stru160->_C_next;
                                *((_DWORD *)v51->pstru24_stru160->_C_next + 1) = (int)v59;
                                v51->pstru24_stru160->_C_next = v59;
                            }
                            else
                            {
                                v59->next = v4->attacker_list_free_pool;
                                v4->attacker_list_free_pool = v59;
                            }
                        } while (++v119 < *v55);
                    }
                }
                else
                {
                    v51->pstru24_stru160 = 0;
                }
                v62 = (int)&v51->_8_next;
                v63 = 0;
                v51->_C_prev = (stru24_OilTankerNode *)&v51->_8_next;
                *(_DWORD *)v62 = v62;
                for (v51->field_18 = 0; v63 < *v123; *(_DWORD *)v62 = (int)v64)
                {
                    v64 = v4->tanker_list_free_pool;
                    if (v64)
                        v4->tanker_list_free_pool = v64->next;
                    else
                        v64 = 0;
                    if (!v64)
                        return 0;
                    v65 = *(_DWORD *)a2;
                    a2 += 4;

                    auto v66 = entityRepo->FindById(*(_DWORD *)a2);
                    v64->entity = v66;
                    v64->drillrig_node = v51;
                    ++v63;
                    v66->_24_ai_node_per_player_side._0_ai_node_per_player_side[v4->_2A0_player_side] = (int)v64;
                    v64->next = *(stru24_OilTankerNode **)v62;
                    v64->prev = (stru24_OilTankerNode *)v62;
                    *(_DWORD *)(*(_DWORD *)v62 + 4) = (int)v64;
                }
                v50 = v125;
            } while (v125 < *((_DWORD *)v117 + 7));
        }
        v67 = v117;
        for (k = 0; k < *((_DWORD *)v117 + 8); v4->tanker_list_DC = v69)
        {
            v69 = v4->tanker_list_free_pool;
            if (v69)
                v4->tanker_list_free_pool = v69->next;
            else
                v69 = 0;
            if (!v69)
                return 0;
            v70 = *(_DWORD *)a2;
            a2 += 4;

            auto v71 = entityRepo->FindById(*(_DWORD *)a2);
            v69->entity = v71;
            v69->drillrig_node = 0;
            ++k;
            v71->_24_ai_node_per_player_side._0_ai_node_per_player_side[v4->_2A0_player_side] = (int)v69;
            v69->next = v4->tanker_list_DC;
            v69->prev = (stru24_OilTankerNode *)&v4->tanker_list_DC;
            v4->tanker_list_DC->prev = v69;
        }
        v120 = 0;
        if (*((_DWORD *)v117 + 11) > 0)
        {
            while (1)
            {
                v72 = v4->list_160_head;
                v73 = (_DWORD *)a2;
                if (v72)
                    v4->list_160_head = v72->next;
                else
                    v72 = 0;
                if (!v72)
                    return 0;
                sub_41EE20(v4, a2, v72);
                v72->next = v4->list_11C;
                v72->prev = (stru24_stru160 *)&v4->list_11C;
                a2 += 40;
                v74 = 0;
                v4->list_11C->prev = v72;
                v4->list_11C = v72;
                if (*v73 > 0)
                {
                    do
                    {
                        v75 = v4->attacker_list_free_pool;
                        if (v75)
                            v4->attacker_list_free_pool = v75->next;
                        else
                            v75 = 0;
                        if (!v75)
                            return 0;
                        v76 = *(_DWORD *)a2;
                        a2 += 4;

                        auto v77 = entityRepo->FindById(*(_DWORD *)a2);
                        v75->entity = v77;
                        if (v77)
                        {
                            v78 = v75->entity;
                            v75->list_8 = v72;
                            v78->_24_ai_node_per_player_side._0_ai_node_per_player_side[v4->_2A0_player_side] = (int)v75;
                            v75->next = (stru24_AttackerNode *)v72->_C_next;
                            v75->prev = (stru24_AttackerNode *)&v72->_C_next;
                            *((_DWORD *)v72->_C_next + 1) = (int)v75;
                            v72->_C_next = v75;
                        }
                        else
                        {
                            v75->next = v4->attacker_list_free_pool;
                            v4->attacker_list_free_pool = v75;
                        }
                    } while (++v74 < *v73);
                }
                if (++v120 >= *((_DWORD *)v117 + 11))
                {
                    v67 = v117;
                    break;
                }
            }
        }
        v121 = 0;
        if (*((_DWORD *)v67 + 12) > 0)
        {
            do
            {
                v79 = v4->list_160_head;
                v80 = (_DWORD *)a2;
                if (v79)
                    v4->list_160_head = v79->next;
                else
                    v79 = 0;
                if (!v79)
                    return 0;
                sub_41EE20(v4, a2, v79);
                v79->next = (stru24_stru160 *)v4->field_168;
                v79->prev = (stru24_stru160 *)&v4->field_168;
                a2 += 40;
                v81 = 0;
                *(_DWORD *)(v4->field_168 + 4) = (int)v79;
                v4->field_168 = (int)v79;
                if (*v80 > 0)
                {
                    do
                    {
                        v82 = v4->attacker_list_free_pool;
                        if (v82)
                            v4->attacker_list_free_pool = v82->next;
                        else
                            v82 = 0;
                        if (!v82)
                            return 0;
                        v83 = *(_DWORD *)a2;
                        a2 += 4;

                        auto v84 = entityRepo->FindById(*(_DWORD *)a2);
                        v82->entity = v84;
                        if (v84)
                        {
                            v85 = v82->entity;
                            v82->list_8 = v79;
                            v85->_24_ai_node_per_player_side._0_ai_node_per_player_side[v4->_2A0_player_side] = (int)v82;
                            v82->next = (stru24_AttackerNode *)v79->_C_next;
                            v82->prev = (stru24_AttackerNode *)&v79->_C_next;
                            *((_DWORD *)v79->_C_next + 1) = (int)v82;
                            v79->_C_next = v82;
                        }
                        else
                        {
                            v82->next = v4->attacker_list_free_pool;
                            v4->attacker_list_free_pool = v82;
                        }
                    } while (++v81 < *v80);
                }
            } while (++v121 < *((_DWORD *)v117 + 12));
        }
        v86 = v4->list_160_head;
        if (v86)
        {
            v4->field_24C = v86;
            v4->list_160_head = v86->next;
        }
        else
        {
            v4->field_24C = 0;
        }
        v87 = v4->field_24C;
        if (!v87)
            return 0;
        v88 = (int *)(v117 + 56);
        if (*((_DWORD *)v117 + 14))
        {
            sub_41EE20(v4, (int)(v117 + 56), v4->field_24C);
            v89 = 0;
            if (*v88 > 0)
            {
                do
                {
                    v90 = v4->attacker_list_free_pool;
                    if (v90)
                        v4->attacker_list_free_pool = v90->next;
                    else
                        v90 = 0;
                    if (!v90)
                        return 0;
                    v91 = *(_DWORD *)a2;
                    a2 += 4;

                    auto v92 = entityRepo->FindById(*(_DWORD *)a2);
                    v90->entity = v92;
                    if (v92)
                    {
                        v90->list_8 = v4->field_24C;
                        v90->entity->_24_ai_node_per_player_side._0_ai_node_per_player_side[v4->_2A0_player_side] = (int)v90;
                        v90->next = (stru24_AttackerNode *)v4->field_24C->_C_next;
                        v90->prev = (stru24_AttackerNode *)&v4->field_24C->_C_next;
                        *((_DWORD *)v4->field_24C->_C_next + 1) = (int)v90;
                        v4->field_24C->_C_next = v90;
                    }
                    else
                    {
                        v90->next = v4->attacker_list_free_pool;
                        v4->attacker_list_free_pool = v90;
                    }
                } while (++v89 < *v88);
            }
        }
        else
        {
            v87->_C_next = &v87->_C_next;
            v4->field_24C->_10_prev = &v4->field_24C->_C_next;
            v4->field_24C->field_1C = 0;
            v4->field_24C->field_8 = 0;
            v4->field_24C->field_24 = 0;
            v4->field_24C->_2C_ai_importance = 0;
        }
        v122 = 0;
        if (*((_DWORD *)v117 + 13) > 0)
        {
            do
            {
                v93 = v4->list_160_head;
                v94 = (_DWORD *)a2;
                if (v93)
                    v4->list_160_head = v93->next;
                else
                    v93 = 0;
                if (!v93)
                    return 0;
                sub_41EE20(v4, a2, v93);
                v93->next = v4->list_1B4;
                v93->prev = (stru24_stru160 *)&v4->list_1B4;
                a2 += 40;
                v95 = 0;
                v4->list_1B4->prev = v93;
                v4->list_1B4 = v93;
                if (*v94 > 0)
                {
                    do
                    {
                        v96 = v4->attacker_list_free_pool;
                        if (v96)
                            v4->attacker_list_free_pool = v96->next;
                        else
                            v96 = 0;
                        if (!v96)
                            return 0;
                        v97 = *(_DWORD *)a2;
                        a2 += 4;

                        auto v98 = entityRepo->FindById(*(_DWORD *)a2);
                        v96->entity = v98;
                        if (v98)
                        {
                            v99 = v96->entity;
                            v96->list_8 = v93;
                            v99->_24_ai_node_per_player_side._0_ai_node_per_player_side[v4->_2A0_player_side] = (int)v96;
                            v96->next = (stru24_AttackerNode *)v93->_C_next;
                            v96->prev = (stru24_AttackerNode *)&v93->_C_next;
                            *((_DWORD *)v93->_C_next + 1) = (int)v96;
                            v93->_C_next = v96;
                        }
                        else
                        {
                            v96->next = v4->attacker_list_free_pool;
                            v4->attacker_list_free_pool = v96;
                        }
                    } while (++v95 < *v94);
                }
            } while (++v122 < *((_DWORD *)v117 + 13));
        }
        v4->field_250 = *((_DWORD *)v117 + 24);
        v4->field_254 = *((_DWORD *)v117 + 25);
        v4->field_258 = *((_DWORD *)v117 + 26);
        v4->field_25C = *((_DWORD *)v117 + 27);
        v100 = 0;
        if (*((_DWORD *)v117 + 28) > 0)
        {
            v101 = (int *)a2;
            do
            {
                v102 = v4->list_26C_head;
                if (v102)
                    v4->list_26C_head = v102->next;
                else
                    v102 = 0;
                if (!v102)
                    return 0;
                v103 = *v101;
                ++v101;
                v102->field_8 = v103;
                v102->next = v4->list_260;
                v102->prev = (stru24_stru26C *)&v4->list_260;
                a2 = (int)v101;
                v4->list_260->prev = v102;
                v4->list_260 = v102;
                v104 = v100 + 1;
                if (*((_DWORD *)v117 + 29) == v100 + 1)
                    v4->ptr_274 = v102;
                ++v100;
            } while (v104 < *((_DWORD *)v117 + 28));
        }
        v4->_278_x_offset = *((_DWORD *)v117 + 30);
        v4->_27C_y_offset = *((_DWORD *)v117 + 31);
        memcpy(v4->field_280, v117 + 128, sizeof(v4->field_280));
        v4->_2A4_player_side = (PLAYER_SIDE)*((_DWORD *)v117 + 41);
        v4->field_2AC = *((_DWORD *)v117 + 42);
        v4->list_58_and_70_size = *((_DWORD *)v117 + 43);
        v4->field_2B4 = *((_DWORD *)v117 + 44);
        v4->field_2B8 = *((_DWORD *)v117 + 45);
        v4->_2BC_ai_importance = *((_DWORD *)v117 + 46);
        v4->field_2C0 = *((_DWORD *)v117 + 47);
        v4->array_2C8_idx = *((_DWORD *)v117 + 48);
        memcpy(v4->array_2C8, v117 + 196, 0x14u);
        v105 = a2;
        v4->_2DC_unit_id = (UNIT_ID)*((_DWORD *)v117 + 54);
        v4->_2E0_unit_id = (UNIT_ID)*((_DWORD *)v117 + 55);
        v4->field_2E4 = *((_DWORD *)v117 + 56);
        v106 = 0;
        for (l = 0; l < *((_DWORD *)v117 + 58); a2 = v105)
        {
            v108 = v4->list_310_head;
            if (v108)
                v4->list_310_head = v108->next;
            else
                v108 = 0;
            if (!v108)
                return 0;
            v108->field_8 = 0;
            v108->unit_id = (UNIT_ID)*(_DWORD *)(v105 + 4);
            v108->x = *(_DWORD *)(v105 + 8);
            v108->y = *(_DWORD *)(v105 + 12);
            v108->x_offset = *(_DWORD *)(v105 + 16);
            v108->y_offset = *(_DWORD *)(v105 + 20);
            v108->_20_ai_importance = *(_DWORD *)(v105 + 24);
            v105 += 28;
            ++l;
        }
        if (*((_DWORD *)v117 + 59) > 0)
        {
            do
            {
                v109 = v4->list_310_head;
                if (v109)
                    v4->list_310_head = v109->next;
                else
                    v109 = 0;
                if (!v109)
                    return 0;

                v109->field_8 = entityRepo->FindById(*(_DWORD *)v105);
                v109->unit_id = (UNIT_ID)*(_DWORD *)(v105 + 4);
                v109->x = *(_DWORD *)(v105 + 8);
                v109->y = *(_DWORD *)(v105 + 12);
                v109->x_offset = *(_DWORD *)(v105 + 16);
                v109->y_offset = *(_DWORD *)(v105 + 20);
                v109->_20_ai_importance = *(_DWORD *)(v105 + 24);
                v105 += 28;
                ++v106;
                a2 = v105;
            } while (v106 < *((_DWORD *)v117 + 59));
        }
        v4->field_344 = *((_DWORD *)v117 + 60);
        v4->field_348 = *((_DWORD *)v117 + 61);
        v4->field_350 = *((_DWORD *)v117 + 63);
        v4->field_354 = *((_DWORD *)v117 + 65);
        v111 = *((_DWORD *)v117 + 62);
        v4->field_34C = v111;
        if (v111 > 0)
            stru37_list_427D80_enqueue_item(v4->_2A8_p_globals_cash, &v4->field_34C, v4->field_348, v4->field_354, 0, 0, -1);
        v112 = *((_DWORD *)v117 + 64);
        if (v112 == -1)
        {
            v113 = (UNIT_ID)*((_DWORD *)v117 + 66);
            if (v113 == -1)
                v4->task = 0;
            else
                v4->task = spawn_unit(v113, *((_DWORD *)v117 + 67), *((_DWORD *)v117 + 68), v4->_2A0_player_side)->script;
        }
        else
        {
            auto v114 = entityRepo->FindById(v112);
            if (v114) {
                v4->task = v114->script;
            }
        }
        v2 = (char *)a2;
        v4->level_field_22_or_2A = *((_DWORD *)v117 + 69);
        v1 = v124;
        v4->field_360 = *((_DWORD *)v117 + 70);
    LABEL_316:
        v124 = ++v1;
        if (v1 >= 7)
            return 1;
    }
    while (1)
    {
        v11 = v4->enemy_list_free_pool;
        if (v11)
            v4->enemy_list_free_pool = v11->next;
        else
            v11 = 0;
        if (!v11)
            return 0;
        v6 += 4;
        a2 = v6;

        auto v13 = entityRepo->FindById(*(_DWORD *)v6);
        v11->entity = v13;
        if (v13)
        {
            v11->entity->_24_ai_node_per_player_side._0_ai_node_per_player_side[v4->_2A0_player_side] = (int)v11;
            v11->next = v4->enemy_list_108;
            v11->prev = (stru24_EnemyNode *)&v4->enemy_list_108;
            v4->enemy_list_108->prev = v11;
            v4->enemy_list_108 = v11;
        }
        else
        {
            v11->next = v4->enemy_list_free_pool;
            v4->enemy_list_free_pool = v11;
        }
        if (++v10 >= *((_DWORD *)v5 + 10))
            goto LABEL_22;
    }
}


//----- (0041EF20) --------------------------------------------------------
void *GAME_Save_PackAiPlayers(size_t *size)
{
    Script **v1; // ebp@1
    stru24 *v2; // ebx@3
    stru24 *i; // eax@3
    stru24 *j; // edx@5
    stru24_struC *v5; // eax@6
    int v6; // esi@7
    void **v7; // eax@7
    stru24_WandererNode *k; // eax@10
    stru24_stru40 *l; // eax@12
    stru24_AttackerNode *m; // eax@14
    stru24_AttackerNode *n; // eax@16
    stru24_stru94 *ii; // eax@18
    stru24_PowerPlantNode *jj; // eax@20
    stru24_DrillRigNode *kk; // edx@22
    stru24_stru160 *v15; // eax@23
    int v16; // esi@24
    void **v17; // eax@24
    stru24_OilTankerNode **ll; // eax@26
    stru24_OilTankerNode *mm; // eax@29
    stru24 *nn; // esi@31
    stru24_struC **i1; // eax@32
    stru24 *i2; // esi@35
    stru24_struC **i3; // eax@36
    stru24 *i4; // esi@39
    stru24_struC **i5; // eax@40
    stru24_stru160 *v26; // eax@43
    int v27; // edx@44
    stru24_stru160 *v28; // eax@44
    stru24_stru26C *i6; // eax@46
    stru24_stru310 *i7; // eax@48
    int i8; // eax@50
    void *result; // eax@53
    int v33; // ecx@55
    void *i19; // ebx@55
    int v35; // edx@56
    Script *v36; // eax@56
    stru24 *v37; // esi@57
    void *v38; // ebp@57
    stru24 *i9; // eax@65
    stru24 *v45; // edi@67
    void *v46; // eax@68
    stru24_struC *v47; // edx@68
    _DWORD *v48; // esi@69
    stru24_struC *v49; // eax@69
    int v50; // ecx@69
    int v51; // eax@69
    stru24 *i10; // eax@75
    stru24 *i11; // eax@77
    stru24 *i12; // eax@79
    stru24 *i13; // eax@81
    stru24 *i14; // eax@83
    stru24 *i15; // eax@85
    stru24_DrillRigNode *v58; // edi@87
    int v59; // eax@88
    void *v60; // ecx@88
    stru24_PowerPlantNode *v61; // eax@90
    Entity *v62; // eax@91
    int v63; // eax@95
    int v64; // eax@95
    stru24_struC *v65; // edx@95
    _DWORD *v66; // esi@96
    stru24_stru160 *v67; // eax@96
    int v68; // ecx@96
    stru24_stru160 *v69; // eax@96
    stru24_DrillRigNode *i16; // eax@100
    stru24 *i17; // eax@103
    stru24_struC *i18; // edi@105
    _DWORD *v73; // esi@106
    stru24_struC *v74; // eax@106
    stru24_struC *i20; // edi@109
    _DWORD *v76; // esi@110
    stru24_struC *v77; // eax@110
    stru24_struC *v78; // edx@113
    stru24_stru160 *v79; // eax@114
    int v80; // ecx@114
    stru24_stru160 *v81; // eax@114
    stru24 *v82; // ecx@118
    stru24_struC *v83; // edi@118
    _DWORD *v84; // esi@119
    stru24_struC *v85; // eax@119
    stru24_stru26C *i21; // eax@123
    stru24_stru310 *i22; // ecx@127
    stru24_stru310 *i23; // ecx@129
    int v89; // edx@130
    int v90; // edx@131
    Script *v91; // ecx@134
    _DWORD *v92; // ecx@135
    stru24 *v93; // [sp+10h] [bp-30h]@57
    int v94; // [sp+14h] [bp-2Ch]@55
    _DWORD *v95; // [sp+18h] [bp-28h]@95
    char *v96; // [sp+1Ch] [bp-24h]@87
    void *v97; // [sp+20h] [bp-20h]@53
    int v98[7]; // [sp+24h] [bp-1Ch]@57

    *size = 0;
    v1 = task_ai_players;
    do
    {
        if (*v1)
        {
            v2 = (stru24 *)(*v1)->param;
            *size += 284;
            for (i = (stru24 *)v2->enemy_list_108; (stru24_EnemyNode **)i != &v2->enemy_list_108; i = i->next)
                *size += 4;
            for (j = v2->next; j != v2; j = j->next)
            {
                *size += 44;
                v5 = j->struC;
                if (v5)
                {
                    v6 = (int)&v5->_C_param;
                    v7 = (void **)v5->_C_param;
                    if (v7 != (void **)v6)
                    {
                        do
                        {
                            *size += 4;
                            v7 = (void **)*v7;
                        } while (v7 != &j->struC->_C_param);
                    }
                }
            }
            for (k = v2->wanderer_list_18; (stru24_WandererNode **)k != &v2->wanderer_list_18; k = k->next)
                *size += 4;
            for (l = v2->list_40_30; (stru24_stru40 **)l != &v2->list_40_30; l = l->next)
                *size += 4;
            for (m = v2->attacker_list_48; (stru24_AttackerNode **)m != &v2->attacker_list_48; m = m->next)
                *size += 4;
            for (n = v2->marshalling_nodes_list__evmission8_only_60;
                (stru24_AttackerNode **)n != &v2->marshalling_nodes_list__evmission8_only_60;
                n = n->next)
            {
                *size += 4;
            }
            for (ii = v2->list_94_78; (stru24_stru94 **)ii != &v2->list_94_78; ii = ii->next)
                *size += 20;
            for (jj = v2->power_plant_list_F4; (stru24_PowerPlantNode **)jj != &v2->power_plant_list_F4; jj = jj->next)
                *size += 4;
            for (kk = v2->drill_rig_list_9C; (stru24_DrillRigNode **)kk != &v2->drill_rig_list_9C; kk = kk->next)
            {
                *size += 60;
                v15 = kk->pstru24_stru160;
                if (v15)
                {
                    v16 = (int)&v15->_C_next;
                    v17 = (void **)v15->_C_next;
                    if (v17 != (void **)v16)
                    {
                        do
                        {
                            *size += 4;
                            v17 = (void **)*v17;
                        } while (v17 != &kk->pstru24_stru160->_C_next);
                    }
                }
                for (ll = &kk->_8_next->next; ll != &kk->_8_next; ll = (stru24_OilTankerNode **)*ll)
                    *size += 4;
            }
            for (mm = v2->tanker_list_DC; (stru24_OilTankerNode **)mm != &v2->tanker_list_DC; mm = mm->next)
                *size += 4;
            for (nn = (stru24 *)v2->list_11C; (stru24_stru160 **)nn != &v2->list_11C; nn = nn->next)
            {
                *size += 40;
                for (i1 = &nn->struC->next; i1 != &nn->struC; i1 = (stru24_struC **)*i1)
                    *size += 4;
            }
            for (i2 = (stru24 *)v2->field_168; (int *)i2 != &v2->field_168; i2 = i2->next)
            {
                *size += 40;
                for (i3 = &i2->struC->next; i3 != &i2->struC; i3 = (stru24_struC **)*i3)
                    *size += 4;
            }
            for (i4 = (stru24 *)v2->list_1B4; (stru24_stru160 **)i4 != &v2->list_1B4; i4 = i4->next)
            {
                *size += 40;
                for (i5 = &i4->struC->next; i5 != &i4->struC; i5 = (stru24_struC **)*i5)
                    *size += 4;
            }
            v26 = v2->field_24C;
            if (v26)
            {
                v27 = (int)&v26->_C_next;
                v28 = (stru24_stru160 *)v26->_C_next;
                if (v28 != (stru24_stru160 *)v27)
                {
                    do
                    {
                        *size += 4;
                        v28 = v28->next;
                    } while (v28 != (stru24_stru160 *)((char *)v2->field_24C + 12));
                }
            }
            for (i6 = v2->list_260; (stru24_stru26C **)i6 != &v2->list_260; i6 = i6->next)
                *size += 4;
            for (i7 = v2->list_310_2EC; (stru24_stru310 **)i7 != &v2->list_310_2EC; i7 = i7->next)
                *size += 28;
            for (i8 = (int)v2->list_318; (stru24_stru310 **)i8 != &v2->list_318; i8 = *(_DWORD *)i8)
                *size += 28;
        }
        ++v1;
    } while ((int)v1 < (int)&unk_4778EC);
    result = malloc(*size);
    v97 = result;
    if (!result)
    {
        errmsg_save[1] = aMemory;
        return result;
    }
    v33 = 0;
    i19 = result;
    v94 = 0;
    while (1)
    {
        v35 = v33;
        v36 = task_ai_players[v33];
        if (v36)
            break;
    LABEL_140:
        v94 = ++v33;
        if (v33 >= 7)
            return v97;
    }
    v37 = (stru24 *)v36->param;
    v38 = i19;
    v98[v35] = (int)i19;
    memset(i19, 0, 0x11Cu);
    i19 = (char *)i19 + 284;
    v93 = v37;

    *(_DWORD *)v38 = get_handler_id(task_ai_players[v35]->handler);
    if (*(_DWORD *)v38 >= 0)
    {
        for (i9 = (stru24 *)v37->enemy_list_108; (stru24_EnemyNode **)i9 != &v37->enemy_list_108; i9 = i9->next)
        {
            i19 = (char *)i19 + 4;
            ++*((_DWORD *)v38 + 10);
            *((_DWORD *)i19 - 1) = i9->_8_entity->entity_id;
        }
        v45 = v37->next;
        if (v37->next != v37)
        {
            do
            {
                v46 = i19;
                i19 = (char *)i19 + 44;
                ++*((_DWORD *)v38 + 1);
                *((_DWORD *)i19 - 11) = v45->_8_entity->entity_id;
                v47 = v45->struC;
                if (v47)
                {
                    v48 = (int *)v46 + 1;
                    sub_41ED90((char *)v46 + 4, v47);
                    v49 = v45->struC;
                    v50 = (int)&v49->_C_param;
                    v51 = (int)v49->_C_param;
                    if (v51 != v50)
                    {
                        do
                        {
                            i19 = (char *)i19 + 4;
                            ++*v48;
                            *((_DWORD *)i19 - 1) = *(_DWORD *)(*(_DWORD *)(v51 + 12) + 304);
                            v51 = *(_DWORD *)v51;
                        } while ((void **)v51 != &v45->struC->_C_param);
                    }
                }
                else
                {
                    *((_DWORD *)v46 + 1) = 0;
                }
                v45 = v45->next;
            } while (v45 != v93);
            v37 = v93;
        }
        for (i10 = (stru24 *)v37->wanderer_list_18; (stru24_WandererNode **)i10 != &v37->wanderer_list_18; i10 = i10->next)
        {
            i19 = (char *)i19 + 4;
            ++*((_DWORD *)v38 + 2);
            *((_DWORD *)i19 - 1) = i10->struC->field_130;
        }
        for (i11 = (stru24 *)v37->list_40_30; (stru24_stru40 **)i11 != &v37->list_40_30; i11 = i11->next)
        {
            i19 = (char *)i19 + 4;
            ++*((_DWORD *)v38 + 3);
            *((_DWORD *)i19 - 1) = i11->struC->field_130;
        }
        for (i12 = (stru24 *)v37->attacker_list_48; (stru24_AttackerNode **)i12 != &v37->attacker_list_48; i12 = i12->next)
        {
            i19 = (char *)i19 + 4;
            ++*((_DWORD *)v38 + 4);
            *((_DWORD *)i19 - 1) = i12->struC->field_130;
        }
        for (i13 = (stru24 *)v37->marshalling_nodes_list__evmission8_only_60;
            (stru24_AttackerNode **)i13 != &v37->marshalling_nodes_list__evmission8_only_60;
            i13 = i13->next)
        {
            i19 = (char *)i19 + 4;
            ++*((_DWORD *)v38 + 5);
            *((_DWORD *)i19 - 1) = i13->struC->field_130;
        }
        for (i14 = (stru24 *)v37->list_94_78; (stru24_stru94 **)i14 != &v37->list_94_78; i14 = i14->next)
        {
            i19 = (char *)i19 + 20;
            ++*((_DWORD *)v38 + 6);
            *((_DWORD *)i19 - 5) = i14->_8_entity->entity_id;
            *((_DWORD *)i19 - 4) = (int)i14->struC;
            *((_DWORD *)i19 - 3) = (int)i14->list_10_convoy_head;
            *((_DWORD *)i19 - 2) = (int)i14->wanderer_list_18;
            *((_DWORD *)i19 - 1) = (int)i14->list_10_convoy;
        }
        for (i15 = (stru24 *)v37->power_plant_list_F4;
            (stru24_PowerPlantNode **)i15 != &v37->power_plant_list_F4;
            i15 = i15->next)
        {
            i19 = (char *)i19 + 4;
            ++*((_DWORD *)v38 + 9);
            *((_DWORD *)i19 - 1) = i15->_8_entity->entity_id;
        }
        v58 = v37->drill_rig_list_9C;
        v96 = (char *)&v37->drill_rig_list_9C;
        if ((stru24_DrillRigNode **)v58 != &v37->drill_rig_list_9C)
        {
            do
            {
                v59 = *((_DWORD *)v38 + 7) + 1;
                v60 = i19;
                *((_DWORD *)v38 + 7) = v59;
                if (v93->_2E8_drillrig_node == v58)
                    *((_DWORD *)v38 + 57) = v59;
                *(_DWORD *)i19 = v58->entity->entity_id;
                v61 = v58->ptr_28;
                if (v61)
                {
                    v62 = v61->entity;
                    if (v62)
                        *((_DWORD *)i19 + 11) = v62->entity_id;
                    else
                        *((_DWORD *)i19 + 11) = -1;
                }
                else
                {
                    *((_DWORD *)i19 + 11) = -1;
                }
                v63 = v58->field_2C;
                *((_DWORD *)i19 + 13) = 0;
                *((_DWORD *)i19 + 12) = v63;
                v64 = (int)i19 + 52;
                *((_DWORD *)i19 + 14) = v58->field_34;
                v65 = (stru24_struC *)v58->pstru24_stru160;
                i19 = (char *)i19 + 60;
                v95 = (_DWORD *)v64;
                if (v65)
                {
                    v66 = (int *)v60 + 1;
                    sub_41ED90((char *)v60 + 4, v65);
                    v67 = v58->pstru24_stru160;
                    v68 = (int)&v67->_C_next;
                    v69 = (stru24_stru160 *)v67->_C_next;
                    if (v69 != (stru24_stru160 *)v68)
                    {
                        do
                        {
                            i19 = (char *)i19 + 4;
                            ++*v66;
                            *((_DWORD *)i19 - 1) = *((_DWORD *)v69->_C_next + 76);
                            v69 = v69->next;
                        } while (v69 != (stru24_stru160 *)((char *)v58->pstru24_stru160 + 12));
                    }
                }
                else
                {
                    *((_DWORD *)v60 + 1) = 0;
                }
                for (i16 = (stru24_DrillRigNode *)v58->_8_next; (stru24_OilTankerNode **)i16 != &v58->_8_next; i16 = i16->next)
                {
                    i19 = (char *)i19 + 4;
                    ++*v95;
                    *((_DWORD *)i19 - 1) = (int)i16->_C_prev[19].next;
                }
                v58 = v58->next;
            } while ((char *)v58 != v96);
        }
        for (i17 = (stru24 *)v93->tanker_list_DC; (stru24_OilTankerNode **)i17 != &v93->tanker_list_DC; i17 = i17->next)
        {
            i19 = (char *)i19 + 4;
            ++*((_DWORD *)v38 + 8);
            *((_DWORD *)i19 - 1) = i17->struC->field_130;
        }
        for (i18 = (stru24_struC *)v93->list_11C; (stru24_stru160 **)i18 != &v93->list_11C; i18 = i18->next)
        {
            v73 = (int *)i19;
            ++*((_DWORD *)v38 + 11);
            sub_41ED90(i19, i18);
            v74 = (stru24_struC *)i18->_C_param;
            for (i19 = (char *)i19 + 40; (void **)v74 != &i18->_C_param; v74 = v74->next)
            {
                i19 = (char *)i19 + 4;
                ++*v73;
                *((_DWORD *)i19 - 1) = *((_DWORD *)v74->_C_param + 76);
            }
        }
        for (i20 = (stru24_struC *)v93->field_168; (int *)i20 != &v93->field_168; i20 = i20->next)
        {
            v76 = (int *)i19;
            ++*((_DWORD *)v38 + 12);
            sub_41ED90(i19, i20);
            v77 = (stru24_struC *)i20->_C_param;
            for (i19 = (char *)i19 + 40; (void **)v77 != &i20->_C_param; v77 = v77->next)
            {
                i19 = (char *)i19 + 4;
                ++*v76;
                *((_DWORD *)i19 - 1) = *((_DWORD *)v77->_C_param + 76);
            }
        }
        v78 = (stru24_struC *)v93->field_24C;
        if (v78)
        {
            sub_41ED90((char *)v38 + 56, v78);
            v79 = v93->field_24C;
            v80 = (int)&v79->_C_next;
            v81 = (stru24_stru160 *)v79->_C_next;
            if (v81 != (stru24_stru160 *)v80)
            {
                do
                {
                    i19 = (char *)i19 + 4;
                    ++*((_DWORD *)v38 + 14);
                    *((_DWORD *)i19 - 1) = *((_DWORD *)v81->_C_next + 76);
                    v81 = v81->next;
                } while (v81 != (stru24_stru160 *)((char *)v93->field_24C + 12));
            }
        }
        else
        {
            *((_DWORD *)v38 + 14) = 0;
        }
        v82 = v93;
        v83 = (stru24_struC *)v93->list_1B4;
        if ((stru24_stru160 **)v83 != &v93->list_1B4)
        {
            do
            {
                v84 = (int *)i19;
                ++*((_DWORD *)v38 + 13);
                sub_41ED90(i19, v83);
                v85 = (stru24_struC *)v83->_C_param;
                for (i19 = (char *)i19 + 40; (void **)v85 != &v83->_C_param; v85 = v85->next)
                {
                    i19 = (char *)i19 + 4;
                    ++*v84;
                    *((_DWORD *)i19 - 1) = *((_DWORD *)v85->_C_param + 76);
                }
                v83 = v83->next;
            } while ((stru24_stru160 **)v83 != &v93->list_1B4);
            v82 = v93;
        }
        *((_DWORD *)v38 + 24) = v82->field_250;
        *((_DWORD *)v38 + 25) = v82->field_254;
        *((_DWORD *)v38 + 26) = v82->field_258;
        *((_DWORD *)v38 + 27) = v82->field_25C;
        *((_DWORD *)v38 + 28) = 0;
        for (i21 = v82->list_260; (stru24_stru26C **)i21 != &v82->list_260; i21 = i21->next)
        {
            i19 = (char *)i19 + 4;
            ++*((_DWORD *)v38 + 28);
            *((_DWORD *)i19 - 1) = i21->field_8;
            if (v82->ptr_274 == i21)
                *((_DWORD *)v38 + 29) = *((_DWORD *)v38 + 28);
        }
        *((_DWORD *)v38 + 30) = v93->_278_x_offset;
        *((_DWORD *)v38 + 31) = v93->_27C_y_offset;
        memcpy((char *)v38 + 128, v93->field_280, 0x28u);
        *((_DWORD *)v38 + 42) = v93->field_2AC;
        *((_DWORD *)v38 + 43) = v93->list_58_and_70_size;
        *((_DWORD *)v38 + 44) = v93->field_2B4;
        *((_DWORD *)v38 + 45) = v93->field_2B8;
        *((_DWORD *)v38 + 46) = v93->_2BC_ai_importance;
        *((_DWORD *)v38 + 47) = v93->field_2C0;
        *((_DWORD *)v38 + 48) = v93->array_2C8_idx;
        memcpy((char *)v38 + 196, v93->array_2C8, 0x20u);
        for (i22 = v93->list_310_2EC; (stru24_stru310 **)i22 != &v93->list_310_2EC; i22 = i22->next)
        {
            i19 = (char *)i19 + 28;
            ++*((_DWORD *)v38 + 58);
            *((_DWORD *)i19 - 6) = i22->unit_id;
            *((_DWORD *)i19 - 5) = i22->x;
            *((_DWORD *)i19 - 4) = i22->y;
            *((_DWORD *)i19 - 3) = i22->x_offset;
            *((_DWORD *)i19 - 2) = i22->y_offset;
            *((_DWORD *)i19 - 1) = i22->_20_ai_importance;
        }
        for (i23 = v93->list_318; (stru24_stru310 **)i23 != &v93->list_318; i19 = (char *)i19 + 28)
        {
            ++*((_DWORD *)v38 + 59);
            v89 = (int)i23->field_8;
            if (v89)
                v90 = *(_DWORD *)(v89 + 304);
            else
                v90 = -1;
            *(_DWORD *)i19 = v90;
            *((_DWORD *)i19 + 1) = i23->unit_id;
            *((_DWORD *)i19 + 2) = i23->x;
            *((_DWORD *)i19 + 3) = i23->y;
            *((_DWORD *)i19 + 4) = i23->x_offset;
            *((_DWORD *)i19 + 5) = i23->y_offset;
            *((_DWORD *)i19 + 6) = i23->_20_ai_importance;
            i23 = i23->next;
        }
        *((_DWORD *)v38 + 60) = v93->field_344;
        *((_DWORD *)v38 + 61) = v93->field_348;
        *((_DWORD *)v38 + 62) = v93->field_34C;
        *((_DWORD *)v38 + 63) = v93->field_350;
        *((_DWORD *)v38 + 65) = v93->field_354;
        v91 = v93->task;
        if (v91)
        {
            v92 = (int *)v91->param;
            if (v92)
            {
                *((_DWORD *)v38 + 64) = v92[76];
            }
            else
            {
                *((_DWORD *)v38 + 64) = -1;
                v93->task->sprite->field_88_unused = 1;
                *((_DWORD *)v38 + 67) = v93->task->sprite->x;
                *((_DWORD *)v38 + 68) = v93->task->sprite->y;
            }
        }
        else
        {
            *((_DWORD *)v38 + 64) = -1;
            *((_DWORD *)v38 + 66) = -1;
        }
        *((_DWORD *)v38 + 69) = v93->level_field_22_or_2A;
        v33 = v94;
        *((_DWORD *)v38 + 70) = v93->field_360;
        goto LABEL_140;
    }
    errmsg_save[1] = "unknown mode";
    return 0;
}
// 41EF20: using guessed type int var_1C[7];
