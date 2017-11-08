#include "src/kknd.h"

#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"

#include "src/Random.h"
#include "src/Render.h"
#include "src/Script.h"
#include "src/ScriptEvent.h"
#include "src/Entity.h"
#include "src/Cursor.h"



//----- (00424B90) --------------------------------------------------------
void UNIT_Handler_TechBunker_2(Script *a1)
{
    int v1; // eax@2
    int v2; // edx@2

    if (_47A300_stru51_tech_bunkers_num_items < 12)
    {
        a1->sprite->field_88_unused = 1;
        v1 = _47A300_stru51_tech_bunkers_num_items;
        _47A300_stru51_tech_bunkers[_47A300_stru51_tech_bunkers_num_items].x = a1->sprite->x;
        v2 = a1->sprite->y;
        _47A300_stru51_tech_bunkers_num_items = v1 + 1;
        _47A300_stru51_array__field_4__minus1_index[2 * (v1 + 1)] = v2;
    }
    sprite_list_remove(a1->sprite);
    script_yield(a1);
}

//----- (00424BF0) --------------------------------------------------------
void script_424BF0_mobd_20_handler(Script *a1)
{
    int v1; // eax@1
    int v2; // ecx@1
    int v3; // edx@1
    Script *i; // eax@2

    a1->sprite->field_88_unused = 1;
    v1 = _47A378_stru48_array_num_items;
    v2 = _47A378_stru48_array_num_items + 1;
    _47A378_stru48_array[v1].sprite_x = a1->sprite->x;
    _47A378_stru48_array[v1].sprite_y = a1->sprite->y;
    v3 = a1->sprite->cplc_ptr1_pstru20->field_18;
    _47A378_stru48_array_num_items = v2;
    _47A378_stru48_array[v1]._8_sprite_cplc = v3;
    if (v2 >= 6)
    {
        script_445370_yield_to_main_thread(a1, 0x80000000, 1);
        for (i = script_47A3CC; !script_47A3CC; i = script_47A3CC)
            script_445370_yield_to_main_thread(a1, 0x80000000, 1);
        script_trigger_event(0, EVT_MSG_1514, 0, i);
    }
    sprite_list_remove(a1->sprite);
    script_yield(a1);
}
// 47A3E4: using guessed type int _47A378_stru48_array_num_items;

//----- (00424CA0) --------------------------------------------------------
void _424CA0_script_47A3CC_evttrigger()
{
    if (script_47A3CC)
        script_trigger_event(0, EVT_MSG_MISSION_FAILED, 0, script_47A3CC);
}

//----- (00424CC0) --------------------------------------------------------
void _424CC0_script_47A3CC_evttrigger()
{
    if (script_47A3CC)
        script_trigger_event(0, EVT_ENTITY_MOVE, 0, script_47A3CC);
}

//----- (00424CE0) --------------------------------------------------------
void script_424CE0_mission_outcome_modal(Script *a1)
{
    Script *v1; // esi@1
    void *v2; // eax@1
    Sprite *v3; // ebp@1
    int v4; // eax@4
    int v5; // eax@5
    int v6; // ebx@7
    int v7; // edi@10
    int v8; // [sp+10h] [bp-8h]@0
    void *v9; // [sp+14h] [bp-4h]@1

    v1 = a1;
    v2 = a1->param;
    v3 = a1->sprite;
    v9 = a1->param;
    if ((unsigned __int8)v2 & 1 && (unsigned __int8)v2 & 2)
    {
        LOBYTE_HEXRAYS(v2) = (unsigned __int8)v2 & 0xFE;
        v9 = v2;
    }
    v4 = (int)v2 - 1;
    if (v4)
    {
        v5 = v4 - 1;
        if (!v5)
        {
            v6 = 72;
            a1 = (Script *)81920;
            v8 = 61440;
            dword_47A180 = 1;
            goto LABEL_10;
        }
        if (v5 != 6)
        {
            v6 = (int)a1;
        LABEL_10:
            v7 = 7;
            do
            {
                sound_play(SOUND_MISSION_OUTCOME_LETTER_APPEARING, 0, _4690A8_unit_sounds_volume, 16, 0);
                script_445370_yield_to_main_thread(v1, 0x80000000, 8);
                --v7;
            } while (v7);
            script_445370_yield_to_main_thread(v1, 0x80000000, 30);
            sprite_load_mobd(v3, v6);
            v3->drawjob->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_4483E0_sidebar;
            v3->x = (int)a1;
            v3->y = v8;
            v3->z_index = 999;
            script_445370_yield_to_main_thread(v1, 0x10000000, 0);
            sound_play(SOUND_MISSION_OUTCOME_LETTER_APPEARING, 0, _4690A8_unit_sounds_volume, 16, 0);
            script_445370_yield_to_main_thread(v1, 0x80000000, 200);
            script_408500_anim(v1);
            if (single_player_game)
            {
                if (_47C6D8_use__466098_cost_multipliers)
                {
                    _47C6D8_use__466098_cost_multipliers = 0;
                    game_state = 3;
                }
                else if (v9 == (void *)2)
                {
                    game_state = 2;
                }
                else if (current_level_idx < LEVEL_SURV_16 || current_level_idx > LEVEL_MUTE_25)
                {
                    if (current_level_idx == LEVEL_SURV_15 || current_level_idx == LEVEL_MUTE_15)
                    {
                        dword_47A3DC = 1;
                        game_state = 1;
                    }
                    else
                    {
                        _4224B0_update_last_level();
                        game_state = 1;
                    }
                }
                else
                {
                    game_state = 3;
                }
            }
            else
            {
                dword_47A180 = 2;
                netz_42F620();
                *(_DWORD *)&netz_47A740[2].str_0[0] = 1;
            }
            while (1)
                script_445370_yield_to_main_thread(v1, 0x80000000, 5000);
        }
    }
    v6 = 60;
    a1 = (Script *)87040;
    v8 = 61440;
    dword_47A180 = 2;
    goto LABEL_10;
}

//----- (00424EC0) --------------------------------------------------------
int sub_424EC0()
{
    Entity *v0; // eax@1
    int v1; // edi@1
    int v2; // ebx@1
    int v3; // ecx@2
    int v4; // ecx@14
    enum UNIT_ID v6; // ecx@23

    v0 = entity_list_head;
    v1 = 0;
    v2 = 0;
    if ((Entity **)entity_list_head != &entity_list_head)
    {
        while (1)
        {
            v3 = v0->unit_id;
            if (v3 <= (int)UNIT_STATS_MUTE_ALCHEMY_HALL
                || v3 >= (int)UNIT_STATS_GORT && v3 <= (int)UNIT_STATS_MECH)
            {
                break;
            }
            v0 = v0->next;
            if ((Entity **)v0 == &entity_list_head)
                goto LABEL_11;
        }
        if (game_globals_cpu[0].cash[7 * player_side + v0->player_side])
            v2 = 1;
        else
            v1 = 1;
        v0 = v0->next;
    }
LABEL_11:
    if (!v1)
    {
        if (_4269B0_task_attachment__num_units_created_manually <= 0)
        {
            if ((Entity **)v0 == &entity_list_head)
                return v2 | 2 * v1;
            while (1)
            {
                if (!game_globals_cpu[0].cash[7 * player_side + v0->player_side])
                {
                    v6 = v0->unit_id;
                    if ((int)v6 <= (int)UNIT_STATS_MUTE_ALCHEMY_HALL
                        || (int)v6 >= (int)UNIT_STATS_GORT && (int)v6 <= (int)UNIT_STATS_MECH)
                    {
                        break;
                    }
                }
                v0 = v0->next;
                if ((Entity **)v0 == &entity_list_head)
                    return v2;
            }
        }
        v1 = 1;
        return v2 | 2 * v1;
    }
    if ((Entity **)v0 == &entity_list_head)
        return v2 | 2 * v1;
    while (1)
    {
        if (game_globals_cpu[0].cash[7 * player_side + v0->player_side])
        {
            v4 = v0->unit_id;
            if (v4 <= (int)UNIT_STATS_MUTE_ALCHEMY_HALL
                || v4 >= (int)UNIT_STATS_GORT && v4 <= (int)UNIT_STATS_MECH)
            {
                break;
            }
        }
        v0 = v0->next;
        if ((Entity **)v0 == &entity_list_head)
            return v2 | 2 * v1;
    }
    return 2 * v1 | 1;
}
// 47A2F8: using guessed type int _4269B0_task_attachment__num_units_created_manually;

//----- (00424FD0) --------------------------------------------------------
int sub_424FD0()
{
    Entity *v0; // eax@1
    int v1; // edi@1
    int v2; // ebx@1
    enum UNIT_ID v3; // ecx@2
    enum PLAYER_SIDE v4; // ecx@5
    enum UNIT_ID v5; // ecx@17
    enum UNIT_ID v7; // ecx@26

    v0 = entity_list_head;
    v1 = 0;
    v2 = 0;
    if ((Entity **)entity_list_head != &entity_list_head)
    {
        while (1)
        {
            v3 = v0->unit_id;
            if ((int)v3 <= (int)UNIT_STATS_MUTE_ALCHEMY_HALL
                || (int)v3 >= (int)UNIT_STATS_GORT && (int)v3 <= (int)UNIT_STATS_MECH)
            {
                v4 = v0->player_side;
                if (v4 == player_side)
                {
                    v2 = 1;
                }
                else if (!game_globals_cpu[0].cash[v4 + 7 * player_side])
                {
                    v1 = 1;
                }
                if (v1 || v2)
                    break;
            }
            v0 = v0->next;
            if ((Entity **)v0 == &entity_list_head)
                goto LABEL_14;
        }
        v0 = v0->next;
    }
LABEL_14:
    if (!v1)
    {
        if (_4269B0_task_attachment__num_units_created_manually <= 0)
        {
            if ((Entity **)v0 == &entity_list_head)
                return v2 | 2 * v1;
            while (1)
            {
                if (!game_globals_cpu[0].cash[7 * player_side + v0->player_side])
                {
                    v7 = v0->unit_id;
                    if ((int)v7 <= 66 || (int)v7 >= 74 && (int)v7 <= 78)
                        break;
                }
                v0 = v0->next;
                if ((Entity **)v0 == &entity_list_head)
                    return v2;
            }
        }
        v1 = 1;
        return v2 | 2 * v1;
    }
    if ((Entity **)v0 == &entity_list_head)
        return v2 | 2 * v1;
    while (1)
    {
        if (v0->player_side == player_side)
        {
            v5 = v0->unit_id;
            if ((int)v5 <= (int)UNIT_STATS_MUTE_ALCHEMY_HALL
                || (int)v5 >= (int)UNIT_STATS_GORT && (int)v5 <= (int)UNIT_STATS_MECH)
            {
                break;
            }
        }
        v0 = v0->next;
        if ((Entity **)v0 == &entity_list_head)
            return v2 | 2 * v1;
    }
    return 2 * v1 | 1;
}
// 47A2F8: using guessed type int _4269B0_task_attachment__num_units_created_manually;

//----- (004250E0) --------------------------------------------------------
int sub_4250E0()
{
    Entity *v0; // eax@1
    int v1; // esi@1
    int v2; // edi@1
    enum UNIT_ID v3; // ecx@2
    enum UNIT_ID v4; // ecx@14
    enum UNIT_ID v6; // ecx@23

    v0 = entity_list_head;
    v1 = 0;
    v2 = 0;
    if ((Entity **)entity_list_head != &entity_list_head)
    {
        while (1)
        {
            v3 = v0->unit_id;
            if ((int)v3 <= (int)UNIT_STATS_MUTE_ALCHEMY_HALL
                || (int)v3 >= (int)UNIT_STATS_GORT && (int)v3 <= (int)UNIT_STATS_MECH)
            {
                break;
            }
            v0 = v0->next;
            if ((Entity **)v0 == &entity_list_head)
                goto LABEL_11;
        }
        if (v0->player_side == player_side)
            v2 = 1;
        else
            v1 = 1;
        v0 = v0->next;
    }
LABEL_11:
    if (!v1)
    {
        if (_4269B0_task_attachment__num_units_created_manually <= 0)
        {
            if ((Entity **)v0 == &entity_list_head)
                return v2 | 2 * v1;
            while (1)
            {
                if (v0->player_side != player_side)
                {
                    v6 = v0->unit_id;
                    if ((int)v6 <= (int)UNIT_STATS_MUTE_ALCHEMY_HALL
                        || (int)v6 >= (int)UNIT_STATS_GORT && (int)v6 <= (int)UNIT_STATS_MECH)
                    {
                        break;
                    }
                }
                v0 = v0->next;
                if ((Entity **)v0 == &entity_list_head)
                    return v2;
            }
        }
        v1 = 1;
        return v2 | 2 * v1;
    }
    if ((Entity **)v0 == &entity_list_head)
        return v2 | 2 * v1;
    while (1)
    {
        if (v0->player_side == player_side)
        {
            v4 = v0->unit_id;
            if ((int)v4 <= (int)UNIT_STATS_MUTE_ALCHEMY_HALL
                || (int)v4 >= (int)UNIT_STATS_GORT && (int)v4 <= (int)UNIT_STATS_MECH)
            {
                break;
            }
        }
        v0 = v0->next;
        if ((Entity **)v0 == &entity_list_head)
            return v2 | 2 * v1;
    }
    return 2 * v1 | 1;
}

//----- (004251B0) --------------------------------------------------------
int sub_4251B0()
{
    Entity *v0; // eax@1
    int v1; // ebx@1
    int v2; // ebp@1
    int v3; // esi@1
    enum PLAYER_SIDE v4; // edx@1
    enum UNIT_ID v5; // ecx@2
    enum UNIT_ID v6; // ecx@13
    enum UNIT_ID v8; // ecx@27

    v0 = entity_list_head;
    v1 = 0;
    v2 = 0;
    v3 = 0;
    v4 = PLAYER_SIDE_UNSPECIFIED;
    if ((Entity **)entity_list_head != &entity_list_head)
    {
        while (1)
        {
            v5 = v0->unit_id;
            if ((int)v5 <= (int)UNIT_STATS_MUTE_ALCHEMY_HALL
                || (int)v5 >= (int)UNIT_STATS_GORT && (int)v5 <= (int)UNIT_STATS_MECH)
            {
                break;
            }
            v0 = v0->next;
            if ((Entity **)v0 == &entity_list_head)
                goto LABEL_11;
        }
        if (v0->player_side == player_side)
        {
            v2 = 1;
        }
        else
        {
            v4 = v0->player_side;
            v1 = 1;
        }
        v0 = v0->next;
    }
LABEL_11:
    if (!v1)
    {
        if ((Entity **)v0 != &entity_list_head)
        {
            while (1)
            {
                if (v0->player_side != player_side)
                {
                    v8 = v0->unit_id;
                    if ((int)v8 <= (int)UNIT_STATS_MUTE_ALCHEMY_HALL
                        || (int)v8 >= (int)UNIT_STATS_GORT && (int)v8 <= (int)UNIT_STATS_MECH)
                    {
                        break;
                    }
                }
                v0 = v0->next;
                if ((Entity **)v0 == &entity_list_head)
                    return v2;
            }
            v1 = 1;
        }
        return v2 | 2 * (v1 | 2 * v3);
    }
    v3 = 1;
    if ((Entity **)v0 == &entity_list_head)
        return v2 | 2 * (v1 | 2 * v3);
    while (1)
    {
        v6 = v0->unit_id;
        if (((int)v6 <= (int)UNIT_STATS_MUTE_ALCHEMY_HALL
            || (int)v6 >= (int)UNIT_STATS_GORT && (int)v6 <= (int)UNIT_STATS_MECH)
            && v0->player_side != v4)
        {
            v3 = 0;
        }
        if (v0->player_side == player_side
            && ((int)v6 <= (int)UNIT_STATS_MUTE_ALCHEMY_HALL
                || (int)v6 >= (int)UNIT_STATS_GORT && (int)v6 <= (int)UNIT_STATS_MECH))
        {
            break;
        }
        v0 = v0->next;
        if ((Entity **)v0 == &entity_list_head)
            return v2 | 2 * (v1 | 2 * v3);
    }
    return 2 * (v1 | 2 * v3) | 1;
}

//----- (004252C0) --------------------------------------------------------
void script_4252C0(Script *a1, void *param)
{
    Script *v2; // esi@1
    Sprite *v3; // eax@3
    Sprite *v4; // esi@3
    Sprite *v5; // eax@5
    Sprite *v6; // esi@5
    Sprite *v7; // eax@7
    Sprite *v8; // esi@7
    Sprite *v9; // eax@9
    void *v10; // [sp+8h] [bp-4h]@1

    v2 = a1;
    v10 = param;
    a1->field_1C = 1;
    is_coroutine_list_initialization_failed = 1;
    while (sub_408400())
        script_445370_yield_to_main_thread(v2, 0x80000000, 1);
    v3 = sprite_create(MOBD_MISSION_OUTCOME_MODAL, 0, 0);
    v4 = v3;
    if (v3)
    {
        v3->drawjob->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_4483E0_sidebar;
        sprite_load_mobd(v3, SPRITE_OUTCOME_MODAL_MOBD_OFFSET_LEFT);
        v4->x = 81920;
        v4->y = 61440;
        v4->z_index = 997;
    }
    v5 = sprite_create(MOBD_MISSION_OUTCOME_MODAL, 0, 0);
    v6 = v5;
    if (v5)
    {
        sprite_load_mobd(v5, SPRITE_OUTCOME_MODAL_MOBD_OFFSET_RIGHT);
        v6->drawjob->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_4483E0_sidebar;
        v6->x = 81920;
        v6->y = 61440;
        v6->z_index = 997;
    }
    v7 = sprite_create(MOBD_MISSION_OUTCOME_MODAL, 0, 0);
    v8 = v7;
    if (v7)
    {
        sprite_load_mobd(v7, SPRITE_OUTCOME_MODAL_MOBD_OFFSET_MISSION);
        v8->drawjob->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_4483E0_sidebar;
        v8->x = 81920;
        v8->y = 61440;
        v8->z_index = 998;
    }
    v9 = sprite_create_scripted(
        MOBD_MISSION_OUTCOME_MODAL,
        0,
        (void(*)(Script *))script_424CE0_mission_outcome_modal,
        SCRIPT_COROUTINE,
        0);
    v9->script->param = v10;
    v9->script->field_1C = 1;
    script_trigger_event(0, EVT_MSG_1531, 0, task_47C028);
}

//----- (00425400) --------------------------------------------------------
void script_425400(Script *a1)
{
    Script *v1; // ebp@2
    char v2; // al@3
    void *v3; // esi@9
    ScriptEvent *i; // eax@9
    char v5; // cl@17
    char v6; // al@20
    char v7; // bl@22
    enum PLAYER_SIDE v8; // edi@25
    int v9; // eax@25
    Entity *v10; // esi@27
    int j; // eax@27
    void *v12; // edx@46
    char v13; // al@49

    dword_47A180 = 0;
    script_create_coroutine(SCRIPT_TYPE_INVALID, script_425BE0_check_special_victory_conditions, 0);
    if (_47C6D8_use__466098_cost_multipliers)
    {
        v1 = a1;
        script_425F50_stru48_stru51_tech_bunkers(a1);
        while (1)
        {
            script_445370_yield_to_main_thread(a1, 0x80000000, 30);
            v2 = sub_424EC0();
            if (!(v2 & 2))
                break;
            if (!(v2 & 1))
                goto LABEL_53;
        }
    LABEL_52:
        v12 = (void *)8;
    LABEL_54:
        script_4252C0(v1, v12);
        goto LABEL_55;
    }
    v1 = a1;
    if (!single_player_game)
    {
        script_425F50_stru48_stru51_tech_bunkers(a1);
        while (1)
        {
            script_445370_yield_to_main_thread(a1, 0x80000000, 30);
            v13 = sub_4251B0();
            if (!(v13 & 2))
                goto LABEL_52;
            if (v13 & 4)
            {
            LABEL_53:
                v12 = (void *)2;
                goto LABEL_54;
            }
        }
    }
    script_47A3CC = a1;
    _47A3D0_unit = levels[current_level_idx].field_1C;
    if (_47A3D0_unit)
    {
        do
        {
            while (script_445370_yield_to_main_thread(a1, 0x80000000, 30) != 0x80000000)
            {
                v3 = 0;
                for (i = script_get_next_event(a1); i; i = script_get_next_event(a1))
                {
                    if (i->event == EVT_MSG_MISSION_FAILED)
                    {
                        v3 = (void *)((unsigned int)v3 | 2);
                    }
                    else if (i->event == EVT_ENTITY_MOVE)
                    {
                        v3 = (void *)((unsigned int)v3 | 1);
                    }
                    script_discard_event(i);
                }
                if (v3)
                {
                    v12 = v3;
                    goto LABEL_54;
                }
            }
            v5 = _47A3D0_unit;
            if (_47A3D0_unit & 0x303)
            {
                if (current_level_idx < LEVEL_SURV_16 || current_level_idx > LEVEL_MUTE_25)
                    v6 = sub_4250E0();
                else
                    v6 = sub_424FD0();
                v5 = _47A3D0_unit;
                v7 = v6;
                if (!(v6 & 1) && BYTE1(_47A3D0_unit) & 3)
                    goto LABEL_53;
                if (_47A3D0_unit & 0x10)
                {
                    v8 = player_side;
                    v9 = game_globals_per_player.cash[player_side];
                    if (v9 >= 5000)
                        break;
                    if (v9 < unit_stats[UNIT_STATS_SURV_POWER_STATION].cost)
                    {
                        v10 = entity_list_head;
                        for (j = 0; (Entity **)v10 != &entity_list_head; v10 = v10->next)
                        {
                            if (!v10->destroyed && v10->player_side == v8 && v10->unit_id == UNIT_STATS_SURV_POWER_STATION)
                            {
                                if (!entity_402AC0_is_mode_402AB0(v10))
                                {
                                    v5 = _47A3D0_unit;
                                    j = 2;
                                    break;
                                }
                                v5 = _47A3D0_unit;
                                j = 1;
                            }
                        }
                        if (j != 2 && (!j || j == 1 && !game_globals_per_player.cash[player_side]))
                            goto LABEL_53;
                    }
                }
                if (!(v7 & 2) && v5 & 3 && !(v5 & 0x10))
                    break;
            }
        } while (!(v5 & 4) || _4269B0_task_attachment__4_some_task_flags < 108000);
        v12 = (void *)1;
        goto LABEL_54;
    }
LABEL_55:
    script_47A3CC = 0;
    script_445370_yield_to_main_thread(v1, 0x80000000, 300);
    script_yield(v1);
}

//----- (00425660) --------------------------------------------------------
void script_47A3CC_die()
{
    Script *v0; // ecx@1

    v0 = script_47A3CC;
    script_47A3CC = 0;
    if (v0)
        script_yield(v0);
}

//----- (00425680) --------------------------------------------------------
void entity_check_special_mission_death_conditions(Entity *victim)
{
    int mission_failed; // edi@1
    enum UNIT_ID v2; // eax@1
    int mission_accomplished; // ebp@1
    bool v4; // sf@15
    unsigned __int8 v5; // of@15

    mission_failed = 0;
    v2 = victim->unit_id;
    mission_accomplished = 0;
    switch (0)                                  // DECOMPILATION ERROR
    {
    case LEVEL_SURV_02_BUILD_AN_OUTPOST:
        if (v2 == UNIT_STATS_SURV_MOBILE_DERRICK
            || v2 == UNIT_STATS_SURV_DRILL_RIG
            || v2 == UNIT_STATS_SURV_POWER_STATION
            || v2 == UNIT_STATS_SURV_TANKER)
        {
            goto LABEL_31;
        }
        break;
    case LEVEL_SURV_03_WITHSTAND_THE_RAIDING_PARTY:
        if (v2 == UNIT_STATS_SURV_MOBILE_DERRICK
            || v2 == UNIT_STATS_SURV_DRILL_RIG
            || v2 == UNIT_STATS_SURV_POWER_STATION
            || v2 == UNIT_STATS_SURV_OUTPOST)
        {
            goto LABEL_31;
        }
        break;
    case LEVEL_SURV_04_RESCUE_THE_SCOUT:
        if (v2 == UNIT_STATS_SURV_SCOUT)
        {
            entity_scout = 0;
            goto LABEL_31;
        }
        break;
    case LEVEL_SURV_07_PROTECT_THE_CONVOY:
        if (v2 == UNIT_STATS_TANKER_CONVOY)
        {
            v5 = __OFSUB__(_47A3D4_tanker_convoy_units_left + 1, 3);
            v4 = _47A3D4_tanker_convoy_units_left++ - 2 < 0;
            if (!(v4 ^ v5))
                mission_failed = 1;
            if (victim->mode_arrive == entity_mode_405680_tanker_convoy)
                --_47A3D8_num_convoy_tankers_still_to_arrive;
        }
        break;
    case LEVEL_SURV_09_RESCUE_THE_COMMANDER:
        if (v2 == UNIT_STATS_SURV_GENERAL)
            goto LABEL_31;
        break;
    case LEVEL_SURV_12_SURGICAL_STRIKE:
        if (v2 == UNIT_STATS_MUTE_WARLORD)
            mission_accomplished = 1;
        break;
    case LEVEL_MUTE_03_BUBBLIN_CRUDE:
        if (v2 == UNIT_STATS_MUTE_DRILL_RIG)
            goto LABEL_31;
        break;
    case LEVEL_MUTE_08_SMASH_THE_CONVOY:
        if (v2 == UNIT_STATS_TANKER_CONVOY)
        {
            v5 = __OFSUB__(_47A3D4_tanker_convoy_units_left + 1, 5);
            v4 = _47A3D4_tanker_convoy_units_left++ - 4 < 0;
            if (!(v4 ^ v5))
                mission_accomplished = 1;
        }
        break;
    case LEVEL_MUTE_14_THE_FINAL_ASSAULT:
        if (v2 == UNIT_STATS_MUTE_KING_ZOG)
            goto LABEL_31;
        break;
    case LEVEL_SURV_18:
        if (v2 == UNIT_STATS_SURV_EL_PRESIDENTE)
            LABEL_31 :
            mission_failed = 1;
        break;
    default:
        break;
    }
    if (mission_accomplished)
    {
        if (script_47A3CC)
            script_trigger_event(0, EVT_ENTITY_MOVE, 0, script_47A3CC);
    }
    else if (mission_failed && script_47A3CC)
    {
        script_trigger_event(0, EVT_MSG_MISSION_FAILED, 0, script_47A3CC);
    }
}

//----- (00425820) --------------------------------------------------------
Entity *entity_425820_find(Entity *a1, int a2)
{
    Sprite *v2; // ecx@1
    Entity *result; // eax@1
    int v4; // ebx@1
    Sprite *v5; // ecx@4
    int v6; // esi@4
    int v7; // esi@4
    bool v8; // zf@4
    bool v9; // sf@4
    Sprite *v10; // esi@4
    int v11; // ecx@5
    int v12; // esi@7
    int v13; // edi@7
    int v14; // [sp+10h] [bp-4h]@1

    a1->sprite->field_88_unused = 1;
    v2 = a1->sprite;
    result = entity_list_head;
    v4 = v2->x;
    v14 = v2->y;
    if ((Entity **)entity_list_head == &entity_list_head)
    {
    LABEL_11:
        result = 0;
    }
    else
    {
        while (1)
        {
            if (!result->destroyed && result->player_side == player_side)
            {
                result->sprite->field_88_unused = 1;
                v5 = result->sprite;
                v6 = v5->x;
                v5->field_88_unused = 1;
                v7 = v6 - v4;
                v8 = v7 == 0;
                v9 = v7 < 0;
                v10 = result->sprite;
                v11 = v9 || v8 ? v4 - v10->x : v10->x - v4;
                v12 = v10->y;
                v13 = v12 - v14;
                if (v12 - v14 <= 0)
                    v13 = v14 - v12;
                if (v11 + v13 < a2)
                    break;
            }
            result = result->next;
            if ((Entity **)result == &entity_list_head)
                goto LABEL_11;
        }
    }
    return result;
}

//----- (004258C0) --------------------------------------------------------
void entity_4258C0_init_palettes_inc_unit_counter(Entity *a1, enum PLAYER_SIDE side)
{
    Sprite *v2; // esi@4
    EntityTurret *v3; // eax@4

    if (side == player_side)
        ++UNIT_num_player_units;
    else
        ++UNIT_num_nonplayer_units;
    v2 = a1->sprite;
    a1->player_side = side;
    v2->drawjob->job_details.palette = per_player_sprite_palettes[player_sprite_color_by_player_side[side]];
    v3 = a1->turret;
    if (v3)
        v3->turret_sprite->drawjob->job_details.palette = per_player_sprite_palettes[player_sprite_color_by_player_side[side]];
    entity_44B100_buildings__mess_with_fog_of_war(a1);
}

//----- (00425920) --------------------------------------------------------
void entity_mode_425920_scout(Entity *a1)
{
    Entity *v1; // esi@1
    void *v2; // edx@2
    enum PLAYER_SIDE v3; // eax@3
    Sprite *v4; // edx@3
    EntityTurret *v5; // ecx@3

    v1 = a1;
    if (!a1->_134_param__unitstats_after_mobile_outpost_plant)
    {
        v2 = a1->_128_spawn_param;
        a1->_134_param__unitstats_after_mobile_outpost_plant = a1->_12C_prison_bunker_spawn_type;
        if (entity_425820_find(a1, (int)v2))
        {
            v3 = player_side;
            ++UNIT_num_player_units;
            v4 = v1->sprite;
            v1->player_side = player_side;
            v4->drawjob->job_details.palette = per_player_sprite_palettes[player_sprite_color_by_player_side[v3]];
            v5 = v1->turret;
            if (v5)
                v5->turret_sprite->drawjob->job_details.palette = per_player_sprite_palettes[player_sprite_color_by_player_side[v3]];
            entity_44B100_buildings__mess_with_fog_of_war(v1);
            script_trigger_event_group(v1->script, EVT_MSG_1521_entity_created, v1, SCRIPT_TYPE_39030);
            entity_mode_415540_infantry(v1);
            if (v1->unit_id == UNIT_STATS_SURV_SCOUT)
            {
                entity_scout = v1;
                sprite_create_scripted(MOBD_CURSORS, v1->sprite, script_426710_mission_objectives_draw_x_mark, SCRIPT_COROUTINE, 0);
                sound_play(SOUND_SURV_UNIT_SCOUT_192, 0, _4690A8_unit_sounds_volume, 16, 0);
            }
            else if (current_level_idx == LEVEL_MUTE_04_RAID_THE_FORT && !entity_scout)
            {
                entity_scout = v1;
                sprite_create_scripted(MOBD_CURSORS, v1->sprite, script_426710_mission_objectives_draw_x_mark, SCRIPT_COROUTINE, 0);
                sound_play(SOUND_MobileOutpost_ClanhallWagon_Planted, 0, _4690A8_unit_sounds_volume, 16, 0);
            }
        }
    }
}

//----- (00425A50) --------------------------------------------------------
void entity_425A50_setup_spawn(Entity *a1, void *spawn_param, int spawn_type)
{
    Entity *v3; // esi@1
    void *v4; // edi@1
    Sprite *v5; // ecx@1

    v3 = a1;
    v4 = spawn_param;
    entity_load_mobd_3(a1);
    v5 = v3->sprite;
    v3->mode = entity_mode_425920_scout;
    v5->x_speed = 0;
    v3->sprite->y_speed = 0;
    v3->_128_spawn_param = v4;
    v3->_12C_prison_bunker_spawn_type = 60 * spawn_type;
    entity_40DF50_boxd_update_map_tile(v3, 0);
}

//----- (00425AB0) --------------------------------------------------------
void UNIT_Handler_General(Script *a1)
{
    Entity *v1; // esi@1
    int v2; // eax@3

    v1 = (Entity *)a1->param;
    if (!v1)
    {
        v1 = entity_list_create(a1);
        entity_init_infantry(v1);
        entity_set_draw_handlers(v1);
        v1->player_side = player_side;
        v1->sprite->drawjob->job_details.palette = per_player_sprite_palettes[player_sprite_color_by_player_side[player_side]];
        script_trigger_event_group(v1->script, EVT_MSG_1521_entity_created, v1, SCRIPT_TYPE_39030);
        v1->script->event_handler = EventHandler_Infantry;
        entity_mode_415540_infantry(v1);
    }
    (v1->mode)(v1);
    v2 = v1->_134_param__unitstats_after_mobile_outpost_plant;
    if (v2)
        v1->_134_param__unitstats_after_mobile_outpost_plant = v2 - 1;
}

//----- (00425B40) --------------------------------------------------------
void UNIT_Handler_Scout(Script *a1)
{
    Entity *v1; // esi@1
    Sprite *v2; // eax@2
    int v3; // eax@3

    v1 = (Entity *)a1->param;
    if (!v1)
    {
        v1 = entity_list_create(a1);
        entity_init_infantry(v1);
        entity_set_draw_handlers(v1);
        entity_load_mobd_3(v1);
        v2 = v1->sprite;
        v1->mode = entity_mode_425920_scout;
        v2->x_speed = 0;
        v1->sprite->y_speed = 0;
        v1->_12C_prison_bunker_spawn_type = 60;
        v1->_128_spawn_param = (void *)76800;
        entity_40DF50_boxd_update_map_tile(v1, 0);
        v1->script->event_handler = EventHandler_Infantry;
    }
    (v1->mode)(v1);
    v3 = v1->_134_param__unitstats_after_mobile_outpost_plant;
    if (v3)
        v1->_134_param__unitstats_after_mobile_outpost_plant = v3 - 1;
}

//----- (00425BE0) --------------------------------------------------------
void script_425BE0_check_special_victory_conditions(Script *a1)
{
    Sprite *v1; // eax@3
    int v2; // ecx@3
    int v3; // eax@3
    Script *v4; // eax@7
    Entity *v5; // eax@9
    int v6; // edx@9
    UnitStat *v7; // ecx@11
    UnitAttachmentPoint *v8; // ecx@12
    int v9; // esi@19
    Entity *v10; // eax@19
    Sprite *v11; // ecx@21
    Entity *v12; // eax@30
    int v13; // edx@30
    int i; // esi@30
    Sprite *v15; // ecx@32
    enum SCRIPT_EVENT v16; // edx@41
    int v17; // edi@42
    Entity *v18; // eax@43
    Sprite *v19; // ecx@45
    Script *v20; // [sp-4h] [bp-14h]@41

    switch (current_level_idx)
    {
    case LEVEL_SURV_04_RESCUE_THE_SCOUT:
        do
        {
            do
                script_445370_yield_to_main_thread(a1, 0x80000000, 30);
            while (!entity_scout);
            entity_scout->sprite->field_88_unused = 1;
            v1 = entity_scout->sprite;
            v2 = v1->x;
            v3 = v1->y;
        } while (v2 <= 35328 || v2 >= 59904 || v3 <= 378112 || v3 >= 402688);
        v4 = script_47A3CC;
        if (script_47A3CC)
            goto mission_accomplished;
        break;
    case LEVEL_SURV_06_EXTERMINATE_THE_VILLAGE:
        do
        {
            while (1)
            {
                script_445370_yield_to_main_thread(a1, 0x80000000, 30);
                v5 = entity_list_head;
                v6 = 0;
                if ((Entity **)entity_list_head == &entity_list_head)
                    break;
                while (1)
                {
                    if (v5->player_side != player_side)
                    {
                        v7 = v5->stats;
                        if (!v7->speed)
                        {
                            v8 = v7->attach;
                            v6 = 1;
                            if (v8 && v8->dmg_source)
                                v6 = 0;
                            if (v6)
                                break;
                        }
                    }
                    v5 = v5->next;
                    if ((Entity **)v5 == &entity_list_head)
                        goto LABEL_17;
                }
            }
        LABEL_17:
            ;
        } while (v6);
        sprite_create_scripted(MOBD_CURSORS, 0, script_426710_mission_objectives_draw_x_mark, SCRIPT_COROUTINE, 0);
        do
        {
            v9 = 1;
            script_445370_yield_to_main_thread(a1, 0x80000000, 30);
            v10 = entity_list_head;
            if ((Entity **)entity_list_head != &entity_list_head)
            {
                while (1)
                {
                    if (v10->player_side == player_side)
                    {
                        v10->sprite->field_88_unused = 1;
                        v11 = v10->sprite;
                        if (v11->x > 76800 || v11->y <= 604160)
                            break;
                    }
                    v10 = v10->next;
                    if ((Entity **)v10 == &entity_list_head)
                        goto LABEL_26;
                }
                v9 = 0;
            }
        LABEL_26:
            ;
        } while (!v9);
        v4 = script_47A3CC;
        if (script_47A3CC)
            goto mission_accomplished;
        break;
    case LEVEL_MUTE_04_RAID_THE_FORT:
        while (1)
        {
            do
                script_445370_yield_to_main_thread(a1, 2147483648, 30);
            while (!entity_scout);
            v12 = entity_list_head;
            v13 = 0;
            for (i = 0; (Entity **)v12 != &entity_list_head; v12 = v12->next)
            {
                if (v12->unit_id == 24)
                {
                    ++v13;
                    v12->sprite->field_88_unused = 1;
                    v15 = v12->sprite;
                    if (v15->x <= 118784 && v15->y >= 414208)
                        ++i;
                }
            }
            if (v13 <= 1)
                break;
            if (i == v13)
            {
                v4 = script_47A3CC;
                if (script_47A3CC)
                    goto mission_accomplished;
                goto end;
            }
        }
        if (script_47A3CC)
        {
            v20 = script_47A3CC;
            v16 = (SCRIPT_EVENT)1498;
            goto mission_failed;
        }
        break;
    case LEVEL_SURV_18:
        v17 = 0;
        do
        {
            script_445370_yield_to_main_thread(a1, 2147483648, 30);
            v18 = entity_list_head;
            if ((Entity **)entity_list_head != &entity_list_head)
            {
                while (1)
                {
                    if (v18->unit_id == 8)
                    {
                        v18->sprite->field_88_unused = 1;
                        v19 = v18->sprite;
                        if (v19->x >= 866816 && v19->y >= 484864)
                            break;
                    }
                    v18 = v18->next;
                    if ((Entity **)v18 == &entity_list_head)
                        goto LABEL_50;
                }
                v17 = 1;
            }
        LABEL_50:
            ;
        } while (!v17);
        v4 = script_47A3CC;
        if (script_47A3CC)
        {
        mission_accomplished:
            v20 = v4;
            v16 = (SCRIPT_EVENT)1524;
        mission_failed:
            script_trigger_event(0, v16, 0, v20);
        }
        break;
    default:
        break;
    }
end:
    script_yield(a1);
}

//----- (00425EC0) --------------------------------------------------------
int sub_425EC0(enum UNIT_ID a1, enum PLAYER_SIDE a2)
{
    Entity *v2; // esi@1
    int result; // eax@1
    enum PLAYER_SIDE v4; // edi@1
    enum UNIT_ID i; // ebx@1

    v2 = entity_list_head;
    result = 0;
    v4 = a2;
    for (i = a1; (Entity **)v2 != &entity_list_head; v2 = v2->next)
    {
        if (!v2->destroyed && v2->player_side == v4 && v2->unit_id == i)
        {
            if (!entity_402AC0_is_mode_402AB0(v2))
                return 2;
            result = 1;
        }
    }
    return result;
}

//----- (00425F20) --------------------------------------------------------
Entity *sub_425F20(enum UNIT_ID unit_id, enum PLAYER_SIDE side)
{
    Entity *result; // eax@1

    result = entity_list_head;
    if ((Entity **)entity_list_head == &entity_list_head)
    {
    LABEL_6:
        result = 0;
    }
    else
    {
        while (result->destroyed || result->player_side != side || result->unit_id != unit_id)
        {
            result = result->next;
            if ((Entity **)result == &entity_list_head)
                goto LABEL_6;
        }
    }
    return result;
}

//----- (00425F50) --------------------------------------------------------
void script_425F50_stru48_stru51_tech_bunkers(Script *a1)
{
    int v1; // edi@2
    ScriptEvent *i; // eax@2
    int v3; // eax@7
    char *v4; // ebp@7
    int v5; // esi@9
    int *v6; // ebx@9
    int v7; // eax@10
    int v8; // edi@11
    int v9; // eax@14
    int v10; // eax@16
    int v11; // ecx@22
    char *v12; // eax@22
    int v13; // edi@28
    int v14; // esi@29
    int v15; // ebx@29
    int v16; // eax@30
    int v17; // edx@30
    __int16 *v18; // ecx@31
    int v19; // ecx@37
    __int16 *v20; // edx@38
    int v21; // ebp@38
    int v22; // eax@39
    int v23; // eax@40
    DrawJobDetails *v24; // esi@48
    int v25; // edi@48
    int v26; // ebp@58
    int v27; // edx@58
    unsigned __int8 v28; // cl@59
    int *v29; // edi@59
    int *v30; // esi@59
    int v31; // eax@60
    int v32; // ebp@65
    int *v33; // edi@66
    int *v34; // esi@66
    int v35; // eax@67
    Sprite *v36; // ecx@70
    int *v37; // eax@71
    Sprite **v38; // ebx@71
    int v39; // eax@72
    int v40; // edi@72
    int v41; // ebp@72
    int v42; // eax@79
    int *v43; // esi@80
    unsigned __int8 v44; // si@88
    int v45; // ecx@88
    int v46; // eax@89
    int v47; // edx@90
    enum UNIT_ID v48; // ecx@95
    stru50 *v49; // esi@96
    Sprite *v50; // ecx@99
    int *v51; // eax@100
    Sprite **v52; // esi@100
    int v53; // eax@101
    int v54; // edx@101
    enum PLAYER_SIDE v55; // edi@110
    int v56; // eax@112
    DrawJobDetails *v57; // esi@112
    int v58; // ebp@112
    int v59; // ebx@112
    stru50 *v60; // esi@121
    enum UNIT_ID j; // ecx@123
    int v62; // ebp@128
    int v63; // esi@129
    int v64; // edx@129
    __int16 *v65; // eax@132
    int v66; // eax@136
    int v67; // [sp+10h] [bp-DCh]@7
    int v68; // [sp+10h] [bp-DCh]@29
    stru50 *v69; // [sp+10h] [bp-DCh]@56
    __int16 *v70; // [sp+10h] [bp-DCh]@110
    int v71; // [sp+14h] [bp-D8h]@7
    int v72; // [sp+14h] [bp-D8h]@29
    char *v73; // [sp+14h] [bp-D8h]@110
    int v74; // [sp+18h] [bp-D4h]@7
    int *v75; // [sp+18h] [bp-D4h]@28
    int v76; // [sp+18h] [bp-D4h]@48
    __int16 v77[12]; // [sp+1Ch] [bp-D0h]@26
    int v78[10]; // [sp+34h] [bp-B8h]@58
    int v79[36]; // [sp+5Ch] [bp-90h]@9

    script_47A3CC = a1;
    do
    {
        v1 = 0;
        script_445370_yield_to_main_thread(a1, 0x40000000, 0);
        for (i = script_get_next_event(a1); i; i = script_get_next_event(a1))
        {
            if (i->event == EVT_MSG_1514)
                v1 = 1;
            script_discard_event(i);
        }
    } while (!v1);
    v3 = 1;
    v71 = 0;
    v67 = 0;
    v74 = 1;
    v4 = (char *)& _47A378_stru48_array[0].sprite_y;
    do
    {
        if (v3 < 6)
        {
            v5 = (int)(v4 + 8);
            v6 = &v79[v67 + v74];
            do
            {
                v7 = *(_DWORD *)(v5 + 4);
                if (*(_DWORD *)v4 - v7 <= 0)
                    v8 = v7 - *(_DWORD *)v4;
                else
                    v8 = *(_DWORD *)v4 - v7;
                if (*((_DWORD *)v4 - 1) - *(_DWORD *)v5 <= 0)
                    v9 = *(_DWORD *)v5 - *((_DWORD *)v4 - 1);
                else
                    v9 = *((_DWORD *)v4 - 1) - *(_DWORD *)v5;
                v10 = math_42D64D_prolly_vec_length(v9 >> 8, v8 >> 8);
                *v6 = v10;
                if (v71 < v10)
                    v71 = v10;
                v5 += 12;
                ++v6;
            } while (v5 < (int)& _47A378_stru48_array[6]);
            v3 = v74;
        }
        ++v3;
        v4 += 12;
        v74 = v3;
        v67 += 6;
    } while (v3 - 1 < 6);
    if (_47C6D8_use__466098_cost_multipliers)
    {
        v11 = 0;
        v12 = (char *)& _47A378_stru48_array[0]._8_sprite_cplc;
        while (*(_DWORD *)v12 != player_side)
        {
            v12 += 12;
            ++v11;
            if ((int)v12 >= (int)& _47A3D4_tanker_convoy_units_left)
                goto LABEL_28;
        }
        *(_DWORD *)v77 = v11;
    }
    else
    {
        *(_DWORD *)v77 = kknd_rand_debug(__FILE__, __LINE__) % 6;
    }
LABEL_28:
    v13 = 1;
    v75 = (int *)&v77[2];
    do
    {
        v14 = 0;
        v72 = 0;
        v68 = 0;
        v15 = 0;
        do
        {
            v16 = 0;
            v17 = 1;
            if (v13 > 0)
            {
                v18 = v77;
                while (*(_DWORD *)v18 != v14)
                {
                    ++v16;
                    v18 += 2;
                    if (v16 >= v13)
                        goto LABEL_36;
                }
                v17 = 0;
            }
        LABEL_36:
            if (v17)
            {
                v19 = 0;
                if (v13 > 0)
                {
                    v20 = v77;
                    v21 = v13;
                    do
                    {
                        v22 = *(_DWORD *)v20;
                        if (v14 >= *(_DWORD *)v20)
                            v23 = v14 + 6 * v22;
                        else
                            v23 = v15 + v22;
                        v19 += v79[v23];
                        v20 += 2;
                        --v21;
                    } while (v21);
                }
                if (v19 > v72)
                {
                    v72 = v19;
                    v68 = v14;
                }
            }
            v15 += 6;
            ++v14;
        } while (v15 < 36);
        ++v13;
        *v75 = v68;
        ++v75;
    } while (v13 < 6);
    if (_47C6D8_use__466098_cost_multipliers)
    {
        v24 = &_47A010_mapd_item_being_drawn[0]->draw_job->job_details;
        v25 = _47A378_stru48_array[*(_DWORD *)v77].sprite_y;
        v76 = *(_DWORD *)v77;
        _47C380_mapd.mapd_cplc_render_x = _47A378_stru48_array[*(_DWORD *)v77].sprite_x - ((render_width & 0xFFFFFF) << 7);
        if (_47C380_mapd.mapd_cplc_render_x >= 0)
        {
            if (_47C380_mapd.mapd_cplc_render_x >= (render_call_draw_handler_mode1(v24) - render_width) << 8)
                _47C380_mapd.mapd_cplc_render_x = (render_call_draw_handler_mode1(v24) - render_width) << 8;
        }
        else
        {
            _47C380_mapd.mapd_cplc_render_x = 0;
        }
        _47C380_mapd.mapd_cplc_render_y = v25 - ((render_height & 0xFFFFFF) << 7);
        if (_47C380_mapd.mapd_cplc_render_y >= 0)
        {
            if (_47C380_mapd.mapd_cplc_render_y >= (render_call_draw_handler_mode2(v24) - render_height) << 8)
                _47C380_mapd.mapd_cplc_render_y = (render_call_draw_handler_mode2(v24) - render_height) << 8;
        }
        else
        {
            _47C380_mapd.mapd_cplc_render_y = 0;
        }
        v69 = __4686E0_stru50_array;
        if (!_47C658_faction_index)
            v69 = _4687D0_stru50_array;
        v26 = dword_46E3F8;
        v27 = 0;
        memset(v78, 0, 0x20u);
        if (dword_46E3F8 <= 0)
        {
            v28 = player_side;
        }
        else
        {
            v28 = player_side;
            v29 = v78;
            v30 = (int *)&v77[2];
            do
            {
                v31 = _47A378_stru48_array[*v30]._8_sprite_cplc;
                if (!(((unsigned __int8)v31 ^ v28) & 1))
                {
                    *v29 = v31;
                    ++v27;
                    ++v29;
                }
                ++v30;
            } while (v27 < v26);
        }
        v32 = dword_46E3FC + v26;
        if (v27 < v32)
        {
            v33 = &v78[v27];
            v34 = (int *)&v77[2];
            do
            {
                v35 = _47A378_stru48_array[*v34]._8_sprite_cplc;
                if (((unsigned __int8)v35 ^ v28) & 1)
                {
                    *v33 = v35;
                    ++v27;
                    ++v33;
                }
                ++v34;
            } while (v27 < v32);
        }
        v36 = sprite_list_47A4A0;
        if ((Sprite **)sprite_list_47A4A0 != &sprite_list_47A4A0)
        {
            do
            {
                v37 = &v36->cplc_ptr1->script_handler_id;
                v38 = &v36->next->next;
                if (v37)
                {
                    v39 = *v37;
                    v40 = 0;
                    v41 = 0;
                    if (v39 == 4 || v39 == 5)
                    {
                        v40 = v36->cplc_ptr1_pstru20->field_24;
                    }
                    else if (v39 >= 91 && v39 <= 156)
                    {
                        v40 = v36->cplc_ptr1_pstru20->field_18;
                    }
                    if (v40)
                    {
                        v42 = 0;
                        if (dword_46E3FC + dword_46E3F8 > 0)
                        {
                            v43 = v78;
                            while (v40 != *v43)
                            {
                                ++v42;
                                ++v43;
                                if (v42 >= dword_46E3FC + dword_46E3F8)
                                    goto LABEL_85;
                            }
                            v41 = 1;
                        }
                    LABEL_85:
                        if (!v41)
                            sprite_list_remove_scripted(v36);
                    }
                }
                v36 = (Sprite *)v38;
            } while (v38 != &sprite_list_47A4A0);
        }
        v44 = 0;
        v45 = 0;
        do
        {
            v46 = 0;
            do
            {
                v47 = v46 + v45;
                if ((v44 ^ (unsigned __int8)v46) & 1)
                    game_globals_cpu[0].cash[v47] = 0;
                else
                    game_globals_cpu[0].cash[v47] = 1;
                ++v46;
            } while (v46 < 7);
            v45 += 7;
            ++v44;
        } while (v45 < 49);
        _47C6DC_dont_execute_unit_handlers = 0;
        v48 = v69->unit_stats_idx;
        if (v69->unit_stats_idx != -1)
        {
            v49 = v69;
            do
            {
                spawn_unit(
                    v48,
                    _47A378_stru48_array[v76].sprite_x + (v49->x << 8),
                    _47A378_stru48_array[v76].sprite_y + (v49->y << 8),
                    (enum PLAYER_SIDE)_47A378_stru48_array[v76]._8_sprite_cplc);
                v48 = v49[1].unit_stats_idx;
                ++v49;
            } while (v48 != -1);
        }
    }
    else
    {
        v50 = sprite_list_47A4A0;
        if ((Sprite **)sprite_list_47A4A0 != &sprite_list_47A4A0)
        {
            do
            {
                v51 = &v50->cplc_ptr1->script_handler_id;
                v52 = &v50->next->next;
                if (v51)
                {
                    v53 = *v51;
                    v54 = 0;
                    if (v53 == 4 || v53 == 5 || v53 >= 91 && v53 <= 156 && v53 != 123)
                        v54 = 1;
                    if (v54)
                        sprite_list_remove_scripted(v50);
                }
                v50 = (Sprite *)v52;
            } while (v52 != &sprite_list_47A4A0);
        }
        _47C6DC_dont_execute_unit_handlers = 0;
        v55 = SURVIVORS;
        v73 = &netz_47A740[2].field_A;
        v70 = v77;
        do
        {
            if (*(v73 - 2))
            {
                v56 = *(_DWORD *)v70;
                v57 = &_47A010_mapd_item_being_drawn[0]->draw_job->job_details;
                v70 += 2;
                v56 *= 12;
                v58 = *(int *)((char *)& _47A378_stru48_array[0].sprite_x + v56);
                v59 = *(int *)((char *)& _47A378_stru48_array[0].sprite_y + v56);
                if (v55 == player_side)
                {
                    _47C380_mapd.mapd_cplc_render_x = v58 - ((render_width & 0xFFFFFF) << 7);
                    if (_47C380_mapd.mapd_cplc_render_x >= 0)
                    {
                        if (_47C380_mapd.mapd_cplc_render_x >= (render_call_draw_handler_mode1(v57) - render_width) << 8)
                            _47C380_mapd.mapd_cplc_render_x = (render_call_draw_handler_mode1(v57) - render_width) << 8;
                    }
                    else
                    {
                        _47C380_mapd.mapd_cplc_render_x = 0;
                    }
                    _47C380_mapd.mapd_cplc_render_y = v59 - ((render_height & 0xFFFFFF) << 7);
                    if (_47C380_mapd.mapd_cplc_render_y >= 0)
                    {
                        if (_47C380_mapd.mapd_cplc_render_y >= (render_call_draw_handler_mode2(v57) - render_height) << 8)
                            _47C380_mapd.mapd_cplc_render_y = (render_call_draw_handler_mode2(v57) - render_height) << 8;
                    }
                    else
                    {
                        _47C380_mapd.mapd_cplc_render_y = 0;
                    }
                }
                v60 = _468560_stru50_array;
                if (!*v73)
                    v60 = _468620_stru50_array;
                for (j = v60->unit_stats_idx; j != -1; ++v60)
                {
                    spawn_unit(j, v58 + (v60->x << 8), v59 + (v60->y << 8), v55);
                    j = v60[1].unit_stats_idx;
                }
            }
            v55 = (PLAYER_SIDE)((int)v55 + 1);
            v73 += 28;
        } while (v55 - 1 < 6);
    }
    if (_441240_techbunker_should_create())
    {
        if (_47A300_stru51_tech_bunkers_num_items >= 12)
        {
            v62 = 0;
            v77[0] = 0;
            v77[1] = 0;
            v77[2] = 0;
            v77[3] = 0;
            v77[4] = 0;
            v77[5] = 0;
            v77[6] = 0;
            v77[7] = 0;
            v77[8] = 0;
            v77[9] = 0;
            v77[10] = 0;
            for (v77[11] = 0; v62 < netz_468B50_available_units_denom / 2 + 1; ++v62)
            {
                v63 = 19;
                v64 = kknd_rand_debug(__FILE__, __LINE__) % 12;
                while (v77[v64])
                {
                    v64 = kknd_rand_debug(__FILE__, __LINE__) % 12;
                    if (--v63 <= 0)
                    {
                        v64 = 0;
                        v65 = v77;
                        do
                        {
                            if (!*v65)
                                break;
                            ++v64;
                            ++v65;
                        } while (v64 < 12);
                        break;
                    }
                }
                if (v64 < 12)
                {
                    v66 = _47A300_stru51_tech_bunkers[v64].y;
                    v77[v64] = 1;
                    spawn_unit(UNIT_STATS_TECH_BUNKER, _47A300_stru51_tech_bunkers[v64].x, v66, PLAYER_SIDE_UNSPECIFIED);
                }
            }
        }
    }
    _47A300_stru51_tech_bunkers_num_items = 0;
    _47A378_stru48_array_num_items = 0;
}

//----- (00426680) --------------------------------------------------------
void script_426680_cursor_mobd(Script *a1)
{
    Sprite *v1; // esi@1
    int v2; // ecx@1

    v1 = a1->sprite;
    v1->drawjob->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_4483E0_sidebar;
    v1->z_index = 5;
    v1->field_88_unused = 1;
    v2 = render_width;
    v1->field_88_unused = 1;
    v1->x = v2 << 7;
    v1->y = render_height << 7;
    v1->pstru7 = &_479D48_stru7;
    sprite_load_mobd(v1, current_level_idx != LEVEL_MUTE_04_RAID_THE_FORT ? CURSOR_MOBD_OFFSET_MISSION_ARROW_S_BLINK : CURSOR_MOBD_OFFSET_MISSION_ARROW_SW_BLINK);
    script_445370_yield_to_main_thread(a1, 0x80000000, 600);
    sprite_list_remove(v1);
    script_yield(a1);
}

//----- (00426710) --------------------------------------------------------
void script_426710_mission_objectives_draw_x_mark(Script *a1)
{
    task_426710_attachment_x_mark *v1; // edi@1
    task_426710_attachment_x_mark *v2; // eax@2
    Sprite *v3; // esi@3

    v1 = (task_426710_attachment_x_mark *)a1->param;
    if (!v1)
    {
        v2 = (task_426710_attachment_x_mark *)script_create_local_object(a1, 12);
        v1 = v2;
        if (v2)
        {
            v3 = a1->sprite;
            a1->param = v2;
            v2->sprite = v3;
            v2->task = a1;
            v2->handler = (void(*)(task_426710_attachment_x_mark *))nullsub_1;
            sprite_load_mobd(v3, 820);
            v3->z_index = 0;
            v3->pstru7 = &_479D48_stru7;
            sprite_create_scripted(MOBD_CURSORS, 0, script_426680_cursor_mobd, SCRIPT_COROUTINE, 0);
            if (current_level_idx == LEVEL_SURV_04_RESCUE_THE_SCOUT)
            {
                v3->x = 47616;
                v3->field_88_unused = 1;
                v3->y = 390400;
            }
            else
            {
                if (current_level_idx == LEVEL_SURV_06_EXTERMINATE_THE_VILLAGE)
                {
                    v3->x = 38400;
                    v3->field_88_unused = 1;
                    v3->y = 628736;
                    (v1->handler)(v1);
                    return;
                }
                if (current_level_idx == LEVEL_MUTE_04_RAID_THE_FORT)
                {
                    v3->x = 59392;
                    v3->field_88_unused = 1;
                    v3->y = 465408;
                    (v1->handler)(v1);
                    return;
                }
            }
        }
    }
    (v1->handler)(v1);
}