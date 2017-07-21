#include "src/kknd.h"

#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"

#include "src/Cursor.h"
#include "src/Script.h"
#include "src/ScriptEvent.h"
#include "src/Random.h"
#include "src/Render.h"


//----- (0042C9E0) --------------------------------------------------------
void cursor_drag_selection(_428940_local *a1, int x, int y)
{
    _428940_local *v3; // esi@1
    task_428940_attach__cursors *v12; // ecx@9
    char *v13; // eax@10
    task_428940_attach__cursors *v14; // eax@11
    _428940_local *v15; // eax@15
    int v16; // ecx@21
    Script *v17; // ecx@21
    task_428940_attach__cursors_2 *v18; // eax@24
    int v19; // eax@28
    int v20; // ecx@29
    int v21; // ecx@31
    enum UNIT_ID v22; // edx@35
    enum UNIT_ID v23; // ecx@35
    int v24; // eax@40
    int v25; // eax@46
    enum SOUND_ID v26; // ecx@48
    int v27; // edx@58
    int v28; // ecx@58
    int v29; // edx@58
    task_428940_attach__cursors *v30; // ecx@58
    task_428940_attach__cursors *v31; // edx@58
    int v32; // eax@59
    char v33; // bl@59
    task_428940_attach__cursors *v34; // eax@60
    Sprite *v35; // ecx@65
    int v36; // [sp-Ch] [bp-2Ch]@48
    int v39; // [sp+18h] [bp-8h]@21
    Entity *a2a; // [sp+1Ch] [bp-4h]@21
    task_428940_attach__cursors *ya; // [sp+24h] [bp+4h]@9
    _428940_local *yb; // [sp+24h] [bp+4h]@15
    Script *yc; // [sp+24h] [bp+4h]@21

    v3 = a1;
    a1->field_40 = 0;
    a1->_48_unit_stats_idx = (UNIT_ID)0;
    a1->field_44 = 0;

    Sprite *drag_frame_x = sprite_create(MOBD_CURSORS, 0, 0);
    sprite_4272A0_load_mobd_item(drag_frame_x, 460);
    drag_frame_x->drawjob->on_update_handler = (DrawJobUpdateHandler)drawjob_update_handler_cursors;

    Sprite *drag_frame_y = sprite_create(MOBD_CURSORS, 0, 0);
    sprite_4272A0_load_mobd_item(drag_frame_y, 472);
    drag_frame_y->drawjob->on_update_handler = (DrawJobUpdateHandler)drawjob_update_handler_cursors;

    Sprite *drag_frame_z = sprite_create(MOBD_CURSORS, 0, 0);
    sprite_4272A0_load_mobd_item(drag_frame_z, 484);
    drag_frame_z->drawjob->on_update_handler = (DrawJobUpdateHandler)drawjob_update_handler_cursors;

    Sprite *drag_frame_w = sprite_create(MOBD_CURSORS, 0, 0);
    sprite_4272A0_load_mobd_item(drag_frame_w, 496);
    drag_frame_w->drawjob->on_update_handler = (DrawJobUpdateHandler)drawjob_update_handler_cursors;

    // while dragging
    while (!(_47A5E0_mouse_input.just_released_buttons_mask & INPUT_MOUSE_LBUTTON_MASK))
    {
        if (v3->_70_sprite->x < x)
        {
            drag_frame_x->x = v3->_70_sprite->x;
            drag_frame_z->x = v3->_70_sprite->x;
            drag_frame_y->x = x;
            drag_frame_w->x = x;
        }
        else
        {
            drag_frame_x->x = x;
            drag_frame_z->x = x;
            drag_frame_y->x = v3->_70_sprite->x;
            drag_frame_w->x = v3->_70_sprite->x;
        }

        if (v3->_70_sprite->y < y)
        {
            drag_frame_x->y = v3->_70_sprite->y;
            drag_frame_y->y = v3->_70_sprite->y;
            drag_frame_z->y = y;
            drag_frame_w->y = y;
        }
        else
        {
            drag_frame_x->y = y;
            drag_frame_y->y = y;
            drag_frame_z->y = v3->_70_sprite->y;
            drag_frame_w->y = v3->_70_sprite->y;
        }

        cursor_process_user_actions(v3, 0);
    }

    // drag ended
    v12 = _47A714.ptr_0;
    LOBYTE_HEXRAYS(stru_47A718.ptr_0) = 3;
    ya = task_428940_attach__cursors_list_free_pool;
    if (task_428940_attach__cursors_list_free_pool)
    {
        v13 = (char *)&task_428940_attach__cursors_list_free_pool->field_4;
        task_428940_attach__cursors_list_free_pool = task_428940_attach__cursors_list_free_pool->next;
        *(_DWORD *)v13 = (int)stru_47A718.ptr_0;
        *((_DWORD *)v13 + 1) = stru_47A718.field_4;
        *((_DWORD *)v13 + 2) = stru_47A718.field_8;
        v13[12] = stru_47A718.field_C;
        ya->next = 0;
        if (_47A714.ptr_0)
        {
            v14 = v12->next;
            if (v12->next)
            {
                do
                {
                    v12 = v14;
                    v14 = v14->next;
                } while (v14);
            }
            v12->next = ya;
        }
        else
        {
            _47A714.ptr_0 = ya;
        }
    }
    v3->field_38 = 0;
    v3->_68_entity = 0;
    v3->_68_entity_type___0convoy__2lab__9scout__3saboteur_vandal__4technicial_mekanik__and_more_see429D40 = 0;
    dword_468980 = -1;
    v15 = v3->next;
    yb = v3->next;
    if (v3->next != v3)
    {
        while (1)
        {
            script_trigger_event(task_mobd17_cursor, EVT_MSG_TEXT_STRING, 0, v15->_8_task);
            yb = yb->next;
            if (yb == v3)
                break;
            v15 = yb;
        }
    }
    if (v3->next != v3)
    {
        v3->prev->next = (_428940_local *)v3->ptr_10;
        v3->ptr_10 = (task_428940_attach__cursors_2 *)v3->next;
        v3->next = v3;
        v3->prev = v3;
    }
    cursor_process_user_actions(v3, 0);
    drag_frame_w->field_88_unused = 1;
    v16 = drag_frame_x->y;
    drag_frame_x->field_88_unused = 1;
    sub_44C970(v16, drag_frame_x->x, drag_frame_w->x, drag_frame_w->y);
    v39 = 0;
    a2a = 0;
    v3->field_38 = 0;
    v17 = _44C9A0_get__47DCA4_entity_task();
    yc = v17;
    if (v17)
    {
        while (1)
        {
            v18 = v3->ptr_10;
            if (v18)
                v3->ptr_10 = v18->next;
            else
                v18 = 0;
            if (v18)
            {
                v18->_8_task = v17;
                v18->next = (task_428940_attach__cursors_2 *)v3->next;
                v18->prev = (task_428940_attach__cursors_2 *)v3;
                v3->next->prev = (_428940_local *)v18;
                v3->next = (_428940_local *)v18;
                script_trigger_event(0, EVT_MSG_1511_sidebar_click_category, 0, v17);
                v19 = (int)yc->param;
                if (*(_DWORD *)(v19 + 20) == player_side)
                {
                    v3->field_38 = 1;
                    a2a = (Entity *)v19;
                    ++v39;
                    v20 = *(_DWORD *)(v19 + 16);
                    if (v20 <= (int)UNIT_STATS_MUTE_MISSILE_CRAB || v20 >= (int)UNIT_STATS_GORT)
                    {
                        v3->_68_entity = (Entity *)v19;
                        v3->field_40 = 1;
                        v21 = *(_DWORD *)(v19 + 16);
                        if ((v21 < (int)UNIT_STATS_SURV_MOBILE_DERRICK || v21 >(int)UNIT_STATS_TANKER_CONVOY)
                            && (v21 < (int)UNIT_STATS_SURV_TECHNICIAN || v21 >(int)UNIT_STATS_MUTE_MEKANIK))
                        {
                            v22 = v3->_48_unit_stats_idx;
                            v3->field_44 = 1;
                            v23 = (UNIT_ID)*(_DWORD *)(v19 + 16);
                            if ((int)v23 > (int)v22 && v23 != UNIT_STATS_MUTE_BIKE_AND_SIDECAR)
                                v3->_48_unit_stats_idx = v23;
                        }
                        if (*(_DWORD *)(v19 + 16) == UNIT_STATS_TANKER_CONVOY)
                            v3->field_40 = 0;
                    }
                    v24 = *(_DWORD *)(v19 + 16);
                    if (v24 >= (int)UNIT_STATS_SURV_GUARD_TOWER && v24 <= (int)UNIT_STATS_MUTE_ROTARY_CANNON)
                        v3->field_44 = 1;
                }
            }
            yc = _44C9A0_get__47DCA4_entity_task();
            if (!yc)
                break;
            v17 = yc;
        }
    }
    if (v39 == 1)
    {
        v3->field_3C = 1;
        sub_429D40(v3, a2a);
    }
    else
    {
        v25 = v3->field_38;
        v3->field_3C = 0;
        if (v25)
        {
            switch (v3->_48_unit_stats_idx)
            {
            case UNIT_STATS_GORT:
            case UNIT_STATS_PLASMA_TANK:
            case UNIT_STATS_SENTINEL_DROID:
            case UNIT_STATS_MECH:
                v36 = _4690A8_unit_sounds_volume;
                v26 = _4689A8_sound_ids[kknd_rand() % -2];
                goto LABEL_57;
            case UNIT_STATS_MUTE_DIRE_WOLF:
                v36 = _4690A8_unit_sounds_volume;
                v26 = (SOUND_ID)165;
                goto LABEL_57;
            case UNIT_STATS_MUTE_GIANT_BEETLE:
                v36 = _4690A8_unit_sounds_volume;
                v26 = (SOUND_ID)168;
                goto LABEL_57;
            case UNIT_STATS_MUTE_GIANT_SCORPION:
                v36 = _4690A8_unit_sounds_volume;
                v26 = (SOUND_ID)172;
                goto LABEL_57;
            case UNIT_STATS_MUTE_MISSILE_CRAB:
                v36 = _4690A8_unit_sounds_volume;
                v26 = (SOUND_ID)170;
                goto LABEL_57;
            case UNIT_STATS_MUTE_WAR_MASTADONT:
                v36 = _4690A8_unit_sounds_volume;
                v26 = (SOUND_ID)160;
                goto LABEL_57;
            default:
                if (get_player_faction())
                {
                    v36 = _4690A8_unit_sounds_volume;
                    v26 = _468998_sound_ids[(unsigned __int8)((char)kknd_rand() % -4)];
                }
                else
                {
                    v36 = _4690A8_unit_sounds_volume;
                    v26 = _468988_sound_ids[(unsigned __int8)((char)kknd_rand() % -4)];
                }
            LABEL_57:
                sound_play(v26, 0, v36, 16, 0);
                break;
            case UNIT_STATS_TANKER_CONVOY:
                break;
            }
        }
    }
    v27 = drag_frame_x->x;
    drag_frame_x->field_88_unused = 1;
    *(_WORD *)((char *)&stru_47A718.ptr_0 + 1) = v27 >> 8;
    *(_WORD *)((char *)&stru_47A718.ptr_0 + 3) = drag_frame_x->y >> 8;
    v28 = drag_frame_w->x >> 8;
    drag_frame_w->field_88_unused = 1;
    *(_WORD *)((char *)&stru_47A718.field_4 + 1) = v28;
    v29 = drag_frame_w->y;
    v30 = _47A714.ptr_0;
    LOBYTE_HEXRAYS(stru_47A718.ptr_0) = 1;
    *(_WORD *)((char *)&stru_47A718.field_4 + 3) = v29 >> 8;
    v31 = task_428940_attach__cursors_list_free_pool;
    if (task_428940_attach__cursors_list_free_pool)
    {
        task_428940_attach__cursors_list_free_pool = task_428940_attach__cursors_list_free_pool->next;
        v32 = (int)&v31->field_4;
        v31->field_4 = (int)stru_47A718.ptr_0;
        *(_DWORD *)(v32 + 4) = stru_47A718.field_4;
        *(_DWORD *)(v32 + 8) = stru_47A718.field_8;
        v33 = stru_47A718.field_C;
        v31->next = 0;
        *(_BYTE *)(v32 + 12) = v33;
        if (_47A714.ptr_0)
        {
            v34 = v30->next;
            if (v30->next)
            {
                do
                {
                    v30 = v34;
                    v34 = v34->next;
                } while (v34);
            }
            v30->next = v31;
        }
        else
        {
            _47A714.ptr_0 = v31;
        }
    }
    sprite_list_remove(drag_frame_x);
    sprite_list_remove(drag_frame_y);
    sprite_list_remove(drag_frame_z);
    sprite_list_remove(drag_frame_w);
    dword_468984 = -1;
    if (v3->_20_load_mobd_item_offset != 12)
    {
        v35 = v3->_70_sprite;
        v3->_20_load_mobd_item_offset = 12;
        sprite_4272A0_load_mobd_item(v35, 12);
    }
}




//----- (0042B740) --------------------------------------------------------
void cursor_process_user_actions(_428940_local *a1, int a2)
{
    _428940_local *v2; // ebp@1
    stru13construct *v3; // esi@1
    int v4; // eax@2
    stru13construct *v5; // edi@3
    task_428940_attach__cursors *v6; // ecx@3
    task_428940_attach__cursors *v7; // edx@3
    int v8; // eax@4
    char v9; // bl@4
    task_428940_attach__cursors *v10; // eax@5
    int v11; // eax@10
    task_428940_attach__cursors *v12; // ecx@12
    task_428940_attach__cursors *v13; // ecx@12
    task_428940_attach__cursors *v14; // edx@12
    int v15; // eax@13
    task_428940_attach__cursors *v16; // eax@14
    task_428940_attach__cursors *v17; // ecx@15
    task_428940_attach__cursors *v18; // edx@19
    int v19; // eax@20
    task_428940_attach__cursors *v20; // eax@21
    __int16 v21; // dx@27
    char v22; // al@27
    __int16 v23; // si@27
    int v24; // ecx@44
    DrawJobDetails *v25; // ebx@48
    int v26; // edx@55
    int v27; // eax@55
    int v28; // eax@59
    int v29; // esi@65
    int v30; // edi@65
    DrawJobDetails *v31; // ebx@70
    int v32; // esi@86
    task_428940_attach__cursors *v33; // ecx@97
    task_428940_attach__cursors *v34; // edx@97
    int v35; // eax@98
    char v36; // bl@98
    task_428940_attach__cursors *v37; // eax@99
    _428940_local *i; // esi@103
    Sprite *v39; // eax@108
    int v40; // ecx@108
    int v41; // eax@108
    char v42; // al@116
    Script *v43; // ecx@116
    ScriptEvent *j; // ebx@116
    int v45; // eax@117
    Script *v46; // ecx@122
    SCRIPT_TYPE v47; // eax@122
    task_428940_attach__cursors *v48; // ecx@132
    task_428940_attach__cursors *v49; // edx@132
    int v50; // edi@133
    char v51; // al@133
    task_428940_attach__cursors *v52; // eax@134
    _DWORD *v53; // ecx@135
    stru13construct *v54; // esi@138
    void *v55; // ecx@138
    int v56; // eax@142
    int v57; // eax@142
    stru13construct *v58; // ecx@142
    void *v59; // eax@156
    stru13construct *v60; // esi@157
    void *v61; // edi@157
    _428940_local *v62; // eax@162
    char v63; // cl@166
    _428940_local *v64; // edx@169
    void *v65; // eax@170
    int v66; // ecx@171
    int v67; // ecx@173
    enum UNIT_ID v68; // edi@177
    enum UNIT_ID v69; // ecx@177
    int v70; // eax@180
    int v71; // eax@185
    int v72; // edi@186
    char v73; // al@186
    task_428940_attach__cursors *v74; // eax@187
    task_428940_attach__cursors *v75; // ecx@188
    int v76; // edi@191
    char v77; // al@191
    task_428940_attach__cursors *v78; // eax@192
    _DWORD *v79; // ecx@193
    int v80; // edi@196
    char v81; // al@196
    task_428940_attach__cursors *v82; // eax@197
    _DWORD *v83; // ecx@198
    int v84; // edi@201
    char v85; // al@201
    task_428940_attach__cursors *v86; // eax@202
    _DWORD *v87; // ecx@203
    int v88; // edi@206
    char v89; // al@206
    task_428940_attach__cursors *v90; // eax@207
    task_428940_attach__cursors *v91; // eax@212
    int v92; // ecx@214
    int v93; // edx@216
    _47A660_global *v94; // eax@216
    DrawJobDetails *a1a; // [sp+10h] [bp-Ch]@1
    int v96; // [sp+14h] [bp-8h]@1

    v2 = a1;
    a1a = &_47A010_mapd_item_being_drawn[0]->draw_job->job_details;
    a1->_18_script = 0;
    a1->_1C_script = 0;
    v3 = stru13construct_list_47A638;
    v96 = a2;
    if ((stru13construct **)stru13construct_list_47A638 != &stru13construct_list_47A638)
    {
        while (1)
        {
            v4 = v3->_18_cost;
            if (v4 <= 0)
            {
                v5 = v3->prev;
                *(task_428940_attach__cursors **)((char *)&stru_47A718.ptr_0 + 1) = (task_428940_attach__cursors *)v3->field_8;
                v6 = _47A714.ptr_0;
                *(int *)((char *)&stru_47A718.field_4 + 1) = 3;
                LOBYTE_HEXRAYS(stru_47A718.ptr_0) = 11;
                v7 = task_428940_attach__cursors_list_free_pool;
                if (task_428940_attach__cursors_list_free_pool)
                {
                    task_428940_attach__cursors_list_free_pool = task_428940_attach__cursors_list_free_pool->next;
                    v8 = (int)&v7->field_4;
                    v7->field_4 = (int)stru_47A718.ptr_0;
                    *(_DWORD *)(v8 + 4) = stru_47A718.field_4;
                    *(_DWORD *)(v8 + 8) = stru_47A718.field_8;
                    v9 = stru_47A718.field_C;
                    v7->next = 0;
                    *(_BYTE *)(v8 + 12) = v9;
                    if (_47A714.ptr_0)
                    {
                        v10 = v6->next;
                        if (v6->next)
                        {
                            do
                            {
                                v6 = v10;
                                v10 = v10->next;
                            } while (v10);
                        }
                        v6->next = v7;
                    }
                    else
                    {
                        _47A714.ptr_0 = v7;
                    }
                }
                script_445370_yield_to_main_thread(v2->_14_task, 0xC0000000, 1);
                v3->next->prev = v3->prev;
                v3->prev->next = v3->next;
                v3->next = stru13construct_list_free_pool;
                stru13construct_list_free_pool = v3;
                v3 = v5;
                goto LABEL_26;
            }
            v11 = (v3->_18_cost << 8) / v3->_14_cost;
            if (v11 > 85)
                break;
            if (v3->field_10 < 2)
            {
                v12 = (task_428940_attach__cursors *)v3->field_8;
                v3->field_10 = 2;
                *(int *)((char *)&stru_47A718.field_4 + 1) = 2;
                *(task_428940_attach__cursors **)((char *)&stru_47A718.ptr_0 + 1) = v12;
                v13 = _47A714.ptr_0;
                LOBYTE_HEXRAYS(stru_47A718.ptr_0) = 11;
                v14 = task_428940_attach__cursors_list_free_pool;
                if (!task_428940_attach__cursors_list_free_pool)
                    goto LABEL_25;
                task_428940_attach__cursors_list_free_pool = task_428940_attach__cursors_list_free_pool->next;
                v15 = (int)&v14->field_4;
                v14->field_4 = (int)stru_47A718.ptr_0;
                *(_DWORD *)(v15 + 4) = stru_47A718.field_4;
                *(_DWORD *)(v15 + 8) = stru_47A718.field_8;
                LOBYTE_HEXRAYS(v15) = stru_47A718.field_C;
                v14->next = 0;
                LOBYTE_HEXRAYS(v14->field_10) = v15;
                if (_47A714.ptr_0)
                {
                    v16 = v13->next;
                    if (v13->next)
                    {
                        do
                        {
                            v17 = v16;
                            v16 = v16->next;
                        } while (v16);
                        v17->next = v14;
                        goto LABEL_25;
                    }
                LABEL_23:
                    v13->next = v14;
                LABEL_25:
                    script_445370_yield_to_main_thread(v2->_14_task, 0xC0000000, 1);
                    goto LABEL_26;
                }
            LABEL_24:
                _47A714.ptr_0 = v14;
                goto LABEL_25;
            }
        LABEL_26:
            v3 = v3->next;
            if ((stru13construct **)v3 == &stru13construct_list_47A638)
                goto LABEL_27;
        }
        if (v11 > 171 || v3->field_10 >= 1)
            goto LABEL_26;
        v18 = (task_428940_attach__cursors *)v3->field_8;
        v3->field_10 = 1;
        v13 = _47A714.ptr_0;
        *(task_428940_attach__cursors **)((char *)&stru_47A718.ptr_0 + 1) = v18;
        *(int *)((char *)&stru_47A718.field_4 + 1) = 1;
        LOBYTE_HEXRAYS(stru_47A718.ptr_0) = 11;
        v14 = task_428940_attach__cursors_list_free_pool;
        if (!task_428940_attach__cursors_list_free_pool)
            goto LABEL_25;
        task_428940_attach__cursors_list_free_pool = task_428940_attach__cursors_list_free_pool->next;
        v19 = (int)&v14->field_4;
        v14->field_4 = (int)stru_47A718.ptr_0;
        *(_DWORD *)(v19 + 4) = stru_47A718.field_4;
        *(_DWORD *)(v19 + 8) = stru_47A718.field_8;
        LOBYTE_HEXRAYS(v19) = stru_47A718.field_C;
        v14->next = 0;
        LOBYTE_HEXRAYS(v14->field_10) = v19;
        if (_47A714.ptr_0)
        {
            v20 = v13->next;
            if (v13->next)
            {
                do
                {
                    v13 = v20;
                    v20 = v20->next;
                } while (v20);
            }
            goto LABEL_23;
        }
        goto LABEL_24;
    }
LABEL_27:
    script_445370_yield_to_main_thread(v2->_14_task, 0xC0000000, 1);
    input_get_mouse_data(&_47A5E0_mouse_input);
    input_get_keyboard_state(&_47A700_input);
    v21 = is_coroutine_list_initialization_failed;
    v22 = _47A700_input.pressed_keys_mask;
    v23 = 0;
    if (is_coroutine_list_initialization_failed)
    {
        dword_47A6FC = 0;
    }
    else if (_47A700_input.pressed_keys_mask & 0x10)
    {
        dword_47A6FC = 29;
    }
    else
    {
        dword_47A6FC = (_47A700_input.pressed_keys_mask & 0x20) != 0 ? 0x38 : 0;
    }
    if (_47A5E0_mouse_input.pressed_buttons_mask & INPUT_MOUSE_RBUTTON_MASK && !is_coroutine_list_initialization_failed && dword_47A6F0 < 100)
        ++dword_47A6F0;
    if (_47A5E0_mouse_input.just_pressed_buttons_mask & INPUT_MOUSE_RBUTTON_MASK && !is_coroutine_list_initialization_failed)
    {
        v2->field_4C = 1;
        v2->cursor_x = _47A5E0_mouse_input.cursor_x_x256;
        v2->cursor_y = _47A5E0_mouse_input.cursor_y_x256;
        _47A5E0_mouse_input.cursor_x_x256 = (render_width << 8) / 2;
        _47A5E0_mouse_input.cursor_y_x256 = (render_height << 8) / 2;
        v2->field_64 = 0;
        v2->field_60 = 0;
        v2->field_5C = 0;
        v2->field_58 = 0;
        v22 = _47A700_input.pressed_keys_mask;
        v21 = is_coroutine_list_initialization_failed;
    }
    if (v2->field_4C && (v21 || _47A5E0_mouse_input.just_released_buttons_mask & INPUT_MOUSE_RBUTTON_MASK))
    {
        v2->field_4C = 0;
        if (dword_47A6F0 < 10)
            _447340_send_sidebar_buttons_message(-1);
        dword_47A6F0 = 0;
        input_4283A0_set_cursor_pos(v2->cursor_x >> 8, v2->cursor_y >> 8);
        v24 = v2->cursor_x;
        v21 = is_coroutine_list_initialization_failed;
        _47A5E0_mouse_input.cursor_x_x256 = v2->cursor_x;
        _47A5E0_mouse_input.cursor_y_x256 = v2->cursor_y;
        v22 = _47A700_input.pressed_keys_mask;
    }
    else
    {
        v24 = _47A5E0_mouse_input.cursor_x_x256;
    }
    if (!v2->field_4C)
    {
        if (v21)
        {
        LABEL_81:
            v25 = a1a;
            v2->_70_sprite->field_88_unused = 1;
            v2->_70_sprite->x = _47C380_mapd.mapd_cplc_render_x + _47A5E0_mouse_input.cursor_x_x256;
            v2->_70_sprite->field_88_unused = 1;
            v23 = 0;
            v2->_70_sprite->y = _47C380_mapd.mapd_cplc_render_y + _47A5E0_mouse_input.cursor_y_x256;
            v2->_74_sprite->field_88_unused = 1;
            v2->_74_sprite->x = _47A5E0_mouse_input.cursor_x_x256;
            v2->_74_sprite->field_88_unused = 1;
            v2->_74_sprite->y = _47A5E0_mouse_input.cursor_y_x256;
            goto LABEL_82;
        }
        v29 = _47C380_mapd.mapd_cplc_render_x - dword_477898;
        v30 = _47C380_mapd.mapd_cplc_render_y - dword_47789C;
        if ((v24 < 256 || v22 & 4) && v29 > 0)
        {
            _47C380_mapd.mapd_cplc_render_x = v29 - ((v22 & 4) != 0 ? 3840 : 1024);
            if (_47C380_mapd.mapd_cplc_render_x < 0)
                _47C380_mapd.mapd_cplc_render_x = 0;
        }
        else if (v24 >= (render_width << 8) - 256 || v22 & 8)
        {
            v31 = a1a;
            if (v29 >= (32 - render_width + render_call_draw_handler_mode1(a1a)) << 8
                || (_47C380_mapd.mapd_cplc_render_x = v29 + ((_47A700_input.pressed_keys_mask & 8) != 0 ? 3840 : 1024),
                    _47C380_mapd.mapd_cplc_render_x < (32 - render_width + render_call_draw_handler_mode1(a1a)) << 8))
            {
                v22 = _47A700_input.pressed_keys_mask;
            }
            else
            {
                _47C380_mapd.mapd_cplc_render_x = (32 - render_width + render_call_draw_handler_mode1(a1a)) << 8;
                v22 = _47A700_input.pressed_keys_mask;
            }
        LABEL_71:
            if ((_47A5E0_mouse_input.cursor_y_x256 < 256 || v22 & 1) && v30 > 0)
            {
                _47C380_mapd.mapd_cplc_render_y = v30 - ((v22 & 1) != 0 ? 3840 : 1024);
                if (_47C380_mapd.mapd_cplc_render_y < 0)
                    _47C380_mapd.mapd_cplc_render_y = 0;
            }
            else if ((_47A5E0_mouse_input.cursor_y_x256 >= (render_height << 8) - 256 || v22 & 2)
                && v30 < (render_call_draw_handler_mode2(v31) - render_height) << 8)
            {
                _47C380_mapd.mapd_cplc_render_y = v30 + ((_47A700_input.pressed_keys_mask & 2) != 0 ? 3840 : 1024);
                if (_47C380_mapd.mapd_cplc_render_y >= (render_call_draw_handler_mode2(v31) - render_height) << 8)
                    _47C380_mapd.mapd_cplc_render_y = (render_call_draw_handler_mode2(v31) - render_height) << 8;
            }
            goto LABEL_81;
        }
        v31 = a1a;
        goto LABEL_71;
    }
    _47C380_mapd.mapd_cplc_render_x += 2 * _47A5E0_mouse_input.cursor_dx_x256 - dword_477898;
    if (_47C380_mapd.mapd_cplc_render_x >= 0)
    {
        v25 = a1a;
        if (_47C380_mapd.mapd_cplc_render_x >= (32 - render_width + render_call_draw_handler_mode1(a1a)) << 8)
            _47C380_mapd.mapd_cplc_render_x = (32 - render_width + render_call_draw_handler_mode1(a1a)) << 8;
    }
    else
    {
        v25 = a1a;
        _47C380_mapd.mapd_cplc_render_x = 0;
    }
    _47C380_mapd.mapd_cplc_render_y += 2 * _47A5E0_mouse_input.cursor_dy_x256 - dword_47789C;
    if (_47C380_mapd.mapd_cplc_render_y >= 0)
    {
        if (_47C380_mapd.mapd_cplc_render_y >= (render_call_draw_handler_mode2(v25) - render_height) << 8)
            _47C380_mapd.mapd_cplc_render_y = (render_call_draw_handler_mode2(v25) - render_height) << 8;
    }
    else
    {
        _47C380_mapd.mapd_cplc_render_y = 0;
    }
    v2->_70_sprite->field_88_unused = 1;
    v2->_70_sprite->x = v2->cursor_x + _47C380_mapd.mapd_cplc_render_x;
    v2->_70_sprite->field_88_unused = 1;
    v2->_70_sprite->y = v2->cursor_y + _47C380_mapd.mapd_cplc_render_y;
    v2->_74_sprite->field_88_unused = 1;
    v2->_74_sprite->x = v2->cursor_x;
    v2->_74_sprite->field_88_unused = 1;
    v2->_74_sprite->y = v2->cursor_y;
    v26 = _47A5E0_mouse_input.cursor_x_x256 - (render_width << 7) + v2->field_60;
    v27 = v26;
    v2->field_60 = v26;
    if (v26 < 0)
        v27 = -v26;
    if (v27 > v2->field_58)
        v2->field_58 = v27;
    v28 = _47A5E0_mouse_input.cursor_y_x256 - (render_height << 7) + v2->field_64;
    v2->field_64 = v28;
    if (v28 < 0)
        v28 = -v28;
    if (v28 > v2->field_5C)
        v2->field_5C = v28;
    input_4283A0_set_cursor_pos((unsigned int)render_width >> 1, (unsigned int)render_height >> 1);
LABEL_82:
    if ((dword_477890 || dword_477894) && is_coroutine_list_initialization_failed == v23 && dword_477890)
    {
        v32 = dword_477890 + _47C380_mapd.mapd_cplc_render_x;
        if (dword_477890 + _47C380_mapd.mapd_cplc_render_x >= 0)
        {
            if (v32 <= (32 - render_width + render_call_draw_handler_mode1(v25)) << 8)
            {
                dword_477898 = dword_477890;
            }
            else
            {
                v32 = (32 - render_width + render_call_draw_handler_mode1(v25)) << 8;
                dword_477898 = v32 - _47C380_mapd.mapd_cplc_render_x;
            }
        }
        else
        {
            v32 = 0;
            dword_477898 = -_47C380_mapd.mapd_cplc_render_x;
        }
        _47C380_mapd.mapd_cplc_render_x = v32;
        v23 = 0;
    }
    if (_47A5E0_mouse_input.just_released_buttons_mask & INPUT_MOUSE_RBUTTON_MASK
        && is_coroutine_list_initialization_failed == v23
        && _47A5E0_mouse_input.cursor_x_x256 < (render_width - 32) << 8
        && v2->field_58 < 4096
        && v2->field_5C < 4096)
    {
        v33 = _47A714.ptr_0;
        LOBYTE_HEXRAYS(stru_47A718.ptr_0) = 3;
        v34 = task_428940_attach__cursors_list_free_pool;
        if (task_428940_attach__cursors_list_free_pool)
        {
            task_428940_attach__cursors_list_free_pool = task_428940_attach__cursors_list_free_pool->next;
            v35 = (int)&v34->field_4;
            v34->field_4 = (int)stru_47A718.ptr_0;
            *(_DWORD *)(v35 + 4) = stru_47A718.field_4;
            *(_DWORD *)(v35 + 8) = stru_47A718.field_8;
            v36 = stru_47A718.field_C;
            v34->next = 0;
            *(_BYTE *)(v35 + 12) = v36;
            if (_47A714.ptr_0)
            {
                v37 = v33->next;
                if (v33->next)
                {
                    do
                    {
                        v33 = v37;
                        v37 = v37->next;
                    } while (v37);
                }
                v33->next = v34;
            }
            else
            {
                _47A714.ptr_0 = v34;
            }
        }
        v2->field_38 = 0;
        v2->_68_entity = 0;
        v2->_68_entity_type___0convoy__2lab__9scout__3saboteur_vandal__4technicial_mekanik__and_more_see429D40 = 0;
        dword_468980 = -1;
        for (i = v2->next; i != v2; i = i->next)
            script_trigger_event(task_mobd17_cursor, EVT_MSG_TEXT_STRING, 0, i->_8_task);
        if (v2->next != v2)
        {
            v2->prev->next = (_428940_local *)v2->ptr_10;
            v2->ptr_10 = (task_428940_attach__cursors_2 *)v2->next;
            v2->next = v2;
            v2->prev = v2;
        }
        script_445370_yield_to_main_thread(v2->_14_task, 0xC0000000, 1);
    }
    v2->_70_sprite->field_88_unused = 1;
    v39 = v2->_70_sprite;
    v40 = v39->x >> 13;
    v41 = v39->y >> 13;
    if (v40 >= 0)
    {
        if (v40 >= _4793F8_map_width)
            v40 = _4793F8_map_width - 1;
    }
    else
    {
        v40 = 0;
    }
    if (v41 >= 0)
    {
        if (v41 >= _478AAC_map_height)
            v41 = _478AAC_map_height - 1;
    }
    else
    {
        v41 = 0;
    }
    v42 = _478AA8_boxd_stru0_array[v40 + _4793F8_map_width * v41].flags;
    v43 = v2->_14_task;
    v2->field_34 = v42 & 0x60;
    for (j = script_get_next_event(v43); j; j = script_get_next_event(v2->_14_task))
    {
        v45 = j->event;
        if (v45 > (int)EVT_MSG_1510)
        {
            switch (v45)
            {
            case EVT_MSG_1529_ai:
                v54 = stru13construct_list_free_pool;
                v55 = j->param;
                if (stru13construct_list_free_pool)
                    stru13construct_list_free_pool = stru13construct_list_free_pool->next;
                else
                    v54 = 0;
                if (v54)
                {
                    v54->field_8 = *((_DWORD *)v55 + 76);
                    v54->field_C = *((_DWORD *)v55 + 5);
                    v54->field_10 = 0;
                    v56 = unit_stats[*((_DWORD *)v55 + 4)].cost;
                    v54->_18_cost = v56;
                    v54->_14_cost = v56;
                    v57 = (v56 << 8) / (60 * *(_DWORD *)(*((_DWORD *)v55 + 6) + 96));
                    v54->_1C_cost_per_time_step = v57;
                    stru37_list_427D60_enqueue_item(
                        (int *)&game_globals_per_player + v54->field_C,
                        &v54->_18_cost,
                        v57,
                        0,
                        0,
                        -1);
                    v58 = stru13construct_list_47A638;
                    v54->prev = (stru13construct *)&stru13construct_list_47A638;
                    v54->next = v58;
                    stru13construct_list_47A638->prev = v54;
                    stru13construct_list_47A638 = v54;
                }
                break;
            case EVT_MSG_1519:
                if (v96)
                    v2->field_28 = 1;
                break;
            case EVT_MSG_1520:
                if (v96)
                    v2->field_28 = 0;
                break;
            case EVT_MSG_SHOW_UNIT_HINT:
                if (v96)
                    v2->field_24 = 1;
                break;
            case EVT_MSG_DESTROY:
                if (v96)
                    v2->field_30 = 1;
                break;
            case EVT_MSG_1516:
                if (v96)
                    v2->field_24 = 0;
                break;
            case EVT_MSG_1518:
                if (v96)
                    v2->field_30 = 0;
                break;
            case EVT_MSG_1522_plan_building_construction:
                if (v96)
                {
                    v59 = j->param;
                    v2->field_2C = 1;
                    v2->_78_msg1522_param = v59;
                }
                break;
            case EVT_MSG_TEXT_STRING:
                v60 = stru13construct_list_47A638;
                v61 = j->sender->param;
                dword_468980 = -1;
                if ((stru13construct **)stru13construct_list_47A638 != &stru13construct_list_47A638)
                {
                    while (v60->field_8 != *((_DWORD *)v61 + 76))
                    {
                        v60 = v60->next;
                        if ((stru13construct **)v60 == &stru13construct_list_47A638)
                            goto LABEL_162;
                    }
                    stru38_list_427FD0(&v60->_18_cost, 0);
                    v60->next->prev = v60->prev;
                    v60->prev->next = v60->next;
                    v60->next = stru13construct_list_free_pool;
                    stru13construct_list_free_pool = v60;
                }
            LABEL_162:
                v62 = v2->next;
                if (v2->next != v2)
                {
                    while (v62->_8_task != j->sender)
                    {
                        v62 = v62->next;
                        if (v62 == v2)
                            goto LABEL_169;
                    }
                    v63 = *((_BYTE *)v61 + player_side + 660);
                    if (v63)
                        --_47A608_stru13_associated_array.field_0[v63];
                    v62->next->prev = v62->prev;
                    v62->prev->next = v62->next;
                    v62->next = (_428940_local *)v2->ptr_10;
                    v2->ptr_10 = (task_428940_attach__cursors_2 *)v62;
                }
            LABEL_169:
                v64 = v2->next;
                for (v2->_48_unit_stats_idx = (UNIT_ID)0; v64 != v2; v64 = v64->next)
                {
                    v65 = v64->_8_task->param;
                    if (*((_DWORD *)v65 + 5) == player_side)
                    {
                        v66 = *((_DWORD *)v65 + 4);
                        if (v66 <= 39 || v66 >= 74)
                        {
                            v2->_68_entity = (Entity *)v65;
                            v67 = *((_DWORD *)v65 + 4);
                            if ((v67 < 21 || v67 > 25) && (v67 < 12 || v67 > 13))
                            {
                                v68 = v2->_48_unit_stats_idx;
                                v2->field_40 = 1;
                                v2->field_44 = 1;
                                v69 = (UNIT_ID)*((_DWORD *)v65 + 4);
                                if ((int)v69 > (int)v68 && v69 != 29)
                                    v2->_48_unit_stats_idx = v69;
                            }
                        }
                        v70 = *((_DWORD *)v65 + 4);
                        if (v70 >= 52 && v70 <= 57)
                            v2->field_44 = 1;
                    }
                }
                break;
            case EVT_MSG_PRODUCTION_READY:
                v71 = (int)j->param;
                *(task_428940_attach__cursors **)((char *)&stru_47A718.ptr_0 + 1) = *(task_428940_attach__cursors **)(*(_DWORD *)(v71 + 8) + 304);
                v48 = _47A714.ptr_0;
                *(int *)((char *)&stru_47A718.field_4 + 1) = *(_DWORD *)(v71 + 12);
                LOBYTE_HEXRAYS(stru_47A718.ptr_0) = 8;
                v49 = task_428940_attach__cursors_list_free_pool;
                if (task_428940_attach__cursors_list_free_pool)
                {
                    task_428940_attach__cursors_list_free_pool = task_428940_attach__cursors_list_free_pool->next;
                    v72 = (int)&v49->field_4;
                    *(_DWORD *)v72 = (int)stru_47A718.ptr_0;
                    *(_DWORD *)(v72 + 4) = stru_47A718.field_4;
                    *(_DWORD *)(v72 + 8) = stru_47A718.field_8;
                    v73 = stru_47A718.field_C;
                    v49->next = 0;
                    *(_BYTE *)(v72 + 12) = v73;
                    if (!_47A714.ptr_0)
                        goto LABEL_210;
                    v74 = v48->next;
                    if (!v48->next)
                        goto LABEL_209;
                    do
                    {
                        v75 = v74;
                        v74 = v74->next;
                    } while (v74);
                    v75->next = v49;
                }
                break;
            case EVT_MSG_1532:
                v48 = _47A714.ptr_0;
                LOBYTE_HEXRAYS(stru_47A718.ptr_0) = 15;
                v49 = task_428940_attach__cursors_list_free_pool;
                if (task_428940_attach__cursors_list_free_pool)
                {
                    task_428940_attach__cursors_list_free_pool = task_428940_attach__cursors_list_free_pool->next;
                    v76 = (int)&v49->field_4;
                    *(_DWORD *)v76 = (int)stru_47A718.ptr_0;
                    *(_DWORD *)(v76 + 4) = stru_47A718.field_4;
                    *(_DWORD *)(v76 + 8) = stru_47A718.field_8;
                    v77 = stru_47A718.field_C;
                    v49->next = 0;
                    *(_BYTE *)(v76 + 12) = v77;
                    if (!_47A714.ptr_0)
                        goto LABEL_210;
                    v78 = v48->next;
                    if (!v48->next)
                        goto LABEL_209;
                    do
                    {
                        v79 = (int *)v78;
                        v78 = v78->next;
                    } while (v78);
                    *v79 = (int)v49;
                }
                break;
            case EVT_MSG_UPGRADE_COMPLETE:
                LOBYTE_HEXRAYS(stru_47A718.ptr_0) = 12;
                v49 = task_428940_attach__cursors_list_free_pool;
                *(task_428940_attach__cursors **)((char *)&stru_47A718.ptr_0 + 1) = (task_428940_attach__cursors *)j->param;
                v48 = _47A714.ptr_0;
                if (task_428940_attach__cursors_list_free_pool)
                {
                    task_428940_attach__cursors_list_free_pool = task_428940_attach__cursors_list_free_pool->next;
                    v80 = (int)&v49->field_4;
                    *(_DWORD *)v80 = (int)stru_47A718.ptr_0;
                    *(_DWORD *)(v80 + 4) = stru_47A718.field_4;
                    *(_DWORD *)(v80 + 8) = stru_47A718.field_8;
                    v81 = stru_47A718.field_C;
                    v49->next = 0;
                    *(_BYTE *)(v80 + 12) = v81;
                    if (!_47A714.ptr_0)
                        goto LABEL_210;
                    v82 = v48->next;
                    if (!v48->next)
                        goto LABEL_209;
                    do
                    {
                        v83 = (int *)v82;
                        v82 = v82->next;
                    } while (v82);
                    *v83 = (int)v49;
                }
                break;
            case EVT_MSG_1533:
                v48 = _47A714.ptr_0;
                LOBYTE_HEXRAYS(stru_47A718.ptr_0) = 16;
                v49 = task_428940_attach__cursors_list_free_pool;
                if (task_428940_attach__cursors_list_free_pool)
                {
                    task_428940_attach__cursors_list_free_pool = task_428940_attach__cursors_list_free_pool->next;
                    v84 = (int)&v49->field_4;
                    *(_DWORD *)v84 = (int)stru_47A718.ptr_0;
                    *(_DWORD *)(v84 + 4) = stru_47A718.field_4;
                    *(_DWORD *)(v84 + 8) = stru_47A718.field_8;
                    v85 = stru_47A718.field_C;
                    v49->next = 0;
                    *(_BYTE *)(v84 + 12) = v85;
                    if (!_47A714.ptr_0)
                        goto LABEL_210;
                    v86 = v48->next;
                    if (!v48->next)
                        goto LABEL_209;
                    do
                    {
                        v87 = (int *)v86;
                        v86 = v86->next;
                    } while (v86);
                    *v87 = (int)v49;
                }
                break;
            case EVT_MSG_1532 | 0x2:
                v48 = _47A714.ptr_0;
                *(task_428940_attach__cursors **)((char *)&stru_47A718.ptr_0 + 1) = *(task_428940_attach__cursors **)j->param;
                LOBYTE_HEXRAYS(stru_47A718.ptr_0) = 18;
                v49 = task_428940_attach__cursors_list_free_pool;
                if (task_428940_attach__cursors_list_free_pool)
                {
                    task_428940_attach__cursors_list_free_pool = task_428940_attach__cursors_list_free_pool->next;
                    v88 = (int)&v49->field_4;
                    *(_DWORD *)v88 = (int)stru_47A718.ptr_0;
                    *(_DWORD *)(v88 + 4) = stru_47A718.field_4;
                    *(_DWORD *)(v88 + 8) = stru_47A718.field_8;
                    v89 = stru_47A718.field_C;
                    v49->next = 0;
                    *(_BYTE *)(v88 + 12) = v89;
                    if (!_47A714.ptr_0)
                        goto LABEL_210;
                    v90 = v48->next;
                    if (v48->next)
                    {
                        do
                        {
                            v48 = v90;
                            v90 = v90->next;
                        } while (v90);
                    }
                    goto LABEL_209;
                }
                break;
            default:
                break;
            }
        }
        else if (v45 == EVT_MSG_1510)
        {
            LOBYTE_HEXRAYS(stru_47A718.ptr_0) = 13;
            *(task_428940_attach__cursors **)((char *)&stru_47A718.ptr_0 + 1) = (task_428940_attach__cursors *)*((_DWORD *)j->param + 76);
            v48 = _47A714.ptr_0;
            *(_WORD *)((char *)&stru_47A718.field_4 + 1) = game_globals_per_player.cash[*((_DWORD *)j->param + 5)] != 0 ? 4 : 0;
            v49 = task_428940_attach__cursors_list_free_pool;
            if (task_428940_attach__cursors_list_free_pool)
            {
                task_428940_attach__cursors_list_free_pool = task_428940_attach__cursors_list_free_pool->next;
                v50 = (int)&v49->field_4;
                *(_DWORD *)v50 = (int)stru_47A718.ptr_0;
                *(_DWORD *)(v50 + 4) = stru_47A718.field_4;
                *(_DWORD *)(v50 + 8) = stru_47A718.field_8;
                v51 = stru_47A718.field_C;
                v49->next = 0;
                *(_BYTE *)(v50 + 12) = v51;
                if (_47A714.ptr_0)
                {
                    v52 = v48->next;
                    if (v48->next)
                    {
                        do
                        {
                            v53 = (int *)v52;
                            v52 = v52->next;
                        } while (v52);
                        *v53 = (int)v49;
                    }
                    else
                    {
                    LABEL_209:
                        v48->next = v49;
                    }
                }
                else
                {
                LABEL_210:
                    _47A714.ptr_0 = v49;
                }
            }
        }
        else if (v45 == EVT_MSG_neg2 && v96 && !dword_47C6C4)
        {
            v46 = (Script *)j->param;
            v47 = v46->script_type;
            if (v47 == SCRIPT_TYPE_60138_ENTITY_SCRIPTS || v47 >= SCRIPT_SURV_OUTPOST_HANDLER && v47 < SCRIPT_TYPE_CA000014)
            {
                v2->_1C_script = v46;
            }
            else if (v47 == SCRIPT_TYPE_47802_fog_of_war
                || v47 == SCRIPT_TYPE_48059
                || v47 == SCRIPT_TYPE_DA000002
                || v47 == SCRIPT_TYPE_DA000003
                || v47 == SCRIPT_TYPE_DA000001)
            {
                v2->_1C_script = v46;
                v2->_18_script = v46;
            }
        }
        script_discard_event(j);
    }
    v91 = _47A714.ptr_0;
    if (_47A714.ptr_0)
    {
        dword_47CAE0 = _47A714.ptr_0->field_4;
        dword_47CAE4 = _47A714.ptr_0->field_8;
        dword_47CAE8 = _47A714.ptr_0->field_C;
        byte_47CAEC = _47A714.ptr_0->field_10;
        _47A714.ptr_0 = _47A714.ptr_0->next;
        v91->next = task_428940_attach__cursors_list_free_pool;
        task_428940_attach__cursors_list_free_pool = v91;
        if (dword_47CB0C)
        {
            v92 = _47A660_array_num_items;
            if (_47A660_array_num_items >= 10)
                v92 = 0;
            v93 = dword_47CAE0;
            _47A660_array[v92]._D_is_free = 1;
            v94 = &_47A660_array[v92];
            _47A660_array_num_items = v92 + 1;
            v94->field_0 = v93;
            v94->field_4 = dword_47CAE4;
            v94->field_8 = dword_47CAE8;
            v94->field_C = byte_47CAEC;
        }
    }
    else
    {
        LOBYTE_HEXRAYS(dword_47CAE0) = 0;
    }
}