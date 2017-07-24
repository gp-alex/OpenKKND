#include "src/kknd.h"

#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"

#include "src/Cursor.h"
#include "src/Script.h"
#include "src/ScriptEvent.h"
#include "src/Random.h"
#include "src/Render.h"
#include "src/Entity.h"
#include "src/Input.h"



task_428940_attach__cursors *task_428940_attach__cursors_list;
task_428940_attach__cursors *task_428940_attach__cursors_list_free_pool;

task_428940_attach__cursors _47A714;

stru209 _47A660_array[10];

stru209 stru_47CAE0; // weak




void _428940_list_return(task_428940_attach__cursors *item)
{
    if (item)
    {
        item->next = task_428940_attach__cursors_list_free_pool;
        task_428940_attach__cursors_list_free_pool = item;
    }
}

task_428940_attach__cursors *_428940_list_get()
{
    auto next = task_428940_attach__cursors_list_free_pool;
    if (next)
    {
        task_428940_attach__cursors_list_free_pool = task_428940_attach__cursors_list_free_pool->next;
    }

    return next;
}


int _47A660_list_current_idx = 0; // 0047A728

//----- (0042D500) --------------------------------------------------------
stru209 *_47A660_list_get()
{
    if (_47A660_list_current_idx >= 10)
    {
        _47A660_list_current_idx = 0;
    }

    if (_47A660_array[_47A660_list_current_idx]._is_free)
    {
        _47A660_array[_47A660_list_current_idx]._is_free = 0;
        return &_47A660_array[_47A660_list_current_idx++];
    }
    return nullptr;
}

//----- (0042D540) --------------------------------------------------------
int _47A660_list_reset()
{
    memset(_47A660_array, 0, sizeof(_47A660_array));
    _47A660_array_num_items = 0;
    return _47A660_list_current_idx = 0;
}

//----- (00429770) --------------------------------------------------------
void _428940_list_do_stuff(stru209 *a1)
{
    task_428940_attach__cursors *ptr = _47A714.next;

    if (auto i = _428940_list_get())
    {
        i->_stru209.type = a1->type;
        i->_stru209.param = a1->param;
        i->_stru209.param2 = a1->param2;
        i->_stru209.param3 = a1->param3;

        i->next = nullptr;
        if (ptr)
        {
            auto v1 = ptr->next;
            if (v1)
            {
                do
                {
                    ptr = v1;
                    v1 = v1->next;
                } while (v1);
            }
            ptr->next = i;
        }
        else
        {
            _47A714.next = i;
        }
    }
}


void cursor_classify_selected_unit(_428940_local *a1, Entity *v19)
{

    if (entity_is_moveable(v19))
    {
        a1->_68_selected_moveable_entity = v19;
        a1->_40_is_infantry_or_vehicle_selected = true;

        if (v19->unit_id == UNIT_STATS_TANKER_CONVOY)
            a1->_40_is_infantry_or_vehicle_selected = false;
    }

    if (entity_is_attacker(v19))
    {
        a1->_44_is_combat_unit_selected = true;

        if (!entity_is_tower(v19))
        {
            auto v22 = a1->_48_highest_ranking_selected_unit;
            if (v19->unit_id > v22 && v19->unit_id != UNIT_STATS_MUTE_BIKE_AND_SIDECAR)
                a1->_48_highest_ranking_selected_unit = v19->unit_id;
        }
    }
}

//----- (0042C9E0) --------------------------------------------------------
void cursor_drag_selection(_428940_local *a1, int x, int y)
{
    task_428940_attach__cursors *v14; // eax@11
    _428940_local *v15; // eax@15
    task_428940_attach__cursors_2 *v18; // eax@24
    Entity *v19; // eax@28
    Sprite *v35; // ecx@65
    _428940_local *yb; // [sp+24h] [bp+4h]@15

    a1->_38_are_owned_units_selected = 0;
    a1->_40_is_infantry_or_vehicle_selected = 0;
    a1->_40_is_infantry_or_vehicle_selected = UNIT_STATS_SURV_RIFLEMAN;
    a1->_44_is_combat_unit_selected = 0;

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
        if (a1->_70_sprite->x < x)
        {
            drag_frame_x->x = a1->_70_sprite->x;
            drag_frame_z->x = a1->_70_sprite->x;
            drag_frame_y->x = x;
            drag_frame_w->x = x;
        }
        else
        {
            drag_frame_x->x = x;
            drag_frame_z->x = x;
            drag_frame_y->x = a1->_70_sprite->x;
            drag_frame_w->x = a1->_70_sprite->x;
        }

        if (a1->_70_sprite->y < y)
        {
            drag_frame_x->y = a1->_70_sprite->y;
            drag_frame_y->y = a1->_70_sprite->y;
            drag_frame_z->y = y;
            drag_frame_w->y = y;
        }
        else
        {
            drag_frame_x->y = y;
            drag_frame_y->y = y;
            drag_frame_z->y = a1->_70_sprite->y;
            drag_frame_w->y = a1->_70_sprite->y;
        }

        cursor_process_user_actions(a1, 0);
    }

    // drag ended

    _47A714._stru209.type = 3;
    _428940_list_do_stuff(&_47A714._stru209);

    a1->_38_are_owned_units_selected = false;
    a1->_68_selected_moveable_entity = nullptr;
    a1->_68_entity_type___0convoy__2lab__9scout__3saboteur_vandal__4technicial_mekanik__and_more_see429D40 = 0;

    dword_468980 = -1;
    v15 = a1->next;
    yb = a1->next;
    if (a1->next != a1)
    {
        while (1)
        {
            script_trigger_event(task_mobd17_cursor, EVT_MSG_TEXT_STRING, 0, v15->_8_task);
            yb = yb->next;
            if (yb == a1)
                break;
            v15 = yb;
        }
    }
    if (a1->next != a1)
    {
        a1->prev->next = (_428940_local *)a1->ptr_10;
        a1->ptr_10 = (task_428940_attach__cursors_2 *)a1->next;
        a1->next = a1;
        a1->prev = a1;
    }
    cursor_process_user_actions(a1, 0);

    entity_drag_selection_init(drag_frame_x->y, drag_frame_x->x, drag_frame_w->x, drag_frame_w->y);

    a1->_38_are_owned_units_selected = 0;

    int num_units_selected = 0;
    Entity *selected_unit = nullptr;
    for (auto v17 = entity_drag_selection_get_next_entity(); v17; v17 = entity_drag_selection_get_next_entity())
    {
        v18 = a1->ptr_10;
        if (v18)
            a1->ptr_10 = v18->next;
        else
            v18 = 0;
        if (v18)
        {
            v18->_8_task = v17;
            v18->next = (task_428940_attach__cursors_2 *)a1->next;
            v18->prev = (task_428940_attach__cursors_2 *)a1;
            a1->next->prev = (_428940_local *)v18;
            a1->next = (_428940_local *)v18;
            script_trigger_event(0, EVT_MSG_1511_sidebar_click_category, 0, v17);
            v19 = (Entity *)v17->param;
            if (v19->player_side == player_side)
            {
                a1->_38_are_owned_units_selected = 1;
                selected_unit = v19;
                ++num_units_selected;

                cursor_classify_selected_unit(a1, v19);
                    /*if (entity->unit_id <= UNIT_STATS_MUTE_MISSILE_CRAB || entity->unit_id >= UNIT_STATS_GORT)
                    {
                        a1->_68_selected_moveable_entity = v19;
                        a1->_40_is_infantry_or_vehicle_selected = 1;
                        
                        // if not mechanics or derricks/tankers
                        if ((v19->unit_id < UNIT_STATS_SURV_MOBILE_DERRICK || v19->unit_id > UNIT_STATS_TANKER_CONVOY)
                            && (v19->unit_id < UNIT_STATS_SURV_TECHNICIAN || v19->unit_id > UNIT_STATS_MUTE_MEKANIK))
                        {
                            auto v22 = a1->_48_highest_ranking_selected_unit;
                            a1->_44_is_combat_unit_selected = 1;
                            if (v19->unit_id > v22 && v19->unit_id != UNIT_STATS_MUTE_BIKE_AND_SIDECAR)
                                a1->_48_highest_ranking_selected_unit = v19->unit_id;
                        }
                        if (v19->unit_id == UNIT_STATS_TANKER_CONVOY)
                            a1->_40_is_infantry_or_vehicle_selected = 0;
                    }

                if (v19->unit_id >= UNIT_STATS_SURV_GUARD_TOWER && v19->unit_id <= UNIT_STATS_MUTE_ROTARY_CANNON)
                    a1->_44_is_combat_unit_selected = 1;*/
            }
        }
    }

    if (num_units_selected == 1)
    {
        a1->field_3C = 1;
        cursor_unit_selection_response_sound(a1, selected_unit);
    }
    else
    {
        a1->field_3C = 0;
        cursor_unit_group_selection_response_sound(a1);
    }

    _47A714._stru209.type = 1;
    ((short *)&_47A714._stru209.param)[0] = drag_frame_x->x >> 8;
    ((short *)&_47A714._stru209.param)[1] = drag_frame_x->y >> 8;
    ((short *)&_47A714._stru209.param)[2] = drag_frame_w->x >> 8;
    ((short *)&_47A714._stru209.param)[3] = drag_frame_w->y >> 8;
    _428940_list_do_stuff(&_47A714._stru209);

    sprite_list_remove(drag_frame_x);
    sprite_list_remove(drag_frame_y);
    sprite_list_remove(drag_frame_z);
    sprite_list_remove(drag_frame_w);

    dword_468984 = -1;
    if (a1->_20_load_mobd_item_offset != 12)
    {
        v35 = a1->_70_sprite;
        a1->_20_load_mobd_item_offset = 12;
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
    int v11; // eax@10
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
    Entity *v65; // eax@170
    int v92; // ecx@214
    int v93; // edx@216
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

                _47A714._stru209.type = 11;
                _47A714._stru209.param = v3->field_8;
                _47A714._stru209.param2 = 3;
                _428940_list_do_stuff(&_47A714._stru209);

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
                v3->field_10 = 2;

                _47A714._stru209.type = 11;
                _47A714._stru209.param = v3->field_8;
                _47A714._stru209.param2 = 2;
                _428940_list_do_stuff(&_47A714._stru209);

                script_445370_yield_to_main_thread(v2->_14_task, 0xC0000000, 1);
                goto LABEL_26;
            }
        LABEL_26:
            v3 = v3->next;
            if ((stru13construct **)v3 == &stru13construct_list_47A638)
                goto LABEL_27;
        }
        if (v11 > 171 || v3->field_10 >= 1)
            goto LABEL_26;

        v3->field_10 = 1;

        _47A714._stru209.type = 11;
        _47A714._stru209.param = v3->field_8;
        _47A714._stru209.param2 = 1;
        _428940_list_do_stuff(&_47A714._stru209);

        script_445370_yield_to_main_thread(v2->_14_task, 0xC0000000, 1);
        goto LABEL_26;
    }
LABEL_27:
    script_445370_yield_to_main_thread(v2->_14_task, 0xC0000000, 1);
    input_get_mouse_state(&_47A5E0_mouse_input);
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
        _47A714._stru209.type = 3;
        _428940_list_do_stuff(&_47A714._stru209);

        v2->_38_are_owned_units_selected = false;
        v2->_68_selected_moveable_entity = nullptr;
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
                v2->_48_highest_ranking_selected_unit = UNIT_STATS_SURV_RIFLEMAN;
                for (v64 = v2->next; v64 != v2; v64 = v64->next)
                {
                    v65 = (Entity *)v64->_8_task->param;
                    if (v65->player_side == player_side)
                    {
                        // cursor_classify_selected_unit is slightly differs from original code
                        // cursor_classify_selected_unit body is taken from 0042C9E0 cursor_drag_selection wich is 95% identical
                        cursor_classify_selected_unit(v2, v65);

                        /*v66 = *((_DWORD *)v65 + 4);
                        if (v66 <= 39 || v66 >= 74)
                        {
                            v2->_68_selected_moveable_entity = (Entity *)v65;
                            v67 = *((_DWORD *)v65 + 4);
                            if ((v67 < 21 || v67 > 25) && (v67 < 12 || v67 > 13))
                            {
                                v68 = v2->_48_highest_ranking_selected_unit;
                                v2->_40_is_infantry_or_vehicle_selected = true;
                                v2->_44_is_combat_unit_selected = true;
                                v69 = (UNIT_ID)*((_DWORD *)v65 + 4);
                                if ((int)v69 > (int)v68 && v69 != 29)
                                    v2->_48_highest_ranking_selected_unit = v69;
                            }
                        }
                        v70 = *((_DWORD *)v65 + 4);
                        if (v70 >= 52 && v70 <= 57)
                            v2->_44_is_combat_unit_selected = true;*/
                    }
                }
                break;

            case EVT_MSG_PRODUCTION_READY:
                _47A714._stru209.type = 8;
                _47A714._stru209.param = *(_DWORD *)(*(_DWORD *)((int)j->param + 8) + 304);
                _47A714._stru209.param2 = *(_DWORD *)((int)j->param + 12);
                _428940_list_do_stuff(&_47A714._stru209);
                break;

            case EVT_MSG_1532:
                _47A714._stru209.type = 15;
                _428940_list_do_stuff(&_47A714._stru209);
                break;

            case EVT_MSG_UPGRADE_COMPLETE:
                _47A714._stru209.type = 12;
                _47A714._stru209.param = (int)j->param;
                _428940_list_do_stuff(&_47A714._stru209);
                break;

            case EVT_MSG_1533:
                _47A714._stru209.type = 16;
                _428940_list_do_stuff(&_47A714._stru209);
                break;

            case EVT_MSG_1532 | 0x2:
                _47A714._stru209.type = 18;
                _47A714._stru209.param = *(int *)j->param;
                _428940_list_do_stuff(&_47A714._stru209);

                script_discard_event(j);
                break;

            default:
                break;
            }
        }
        else if (v45 == EVT_MSG_1510)
        {
            _47A714._stru209.type = 13;
            _47A714._stru209.param = *((_DWORD *)j->param + 76);
            ((short *)&_47A714._stru209.param)[2] = game_globals_per_player.cash[*((_DWORD *)j->param + 5)] != 0 ? 4 : 0;
            _428940_list_do_stuff(&_47A714._stru209);
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

    if (_47A714.next)
    {
        memcpy(&stru_47CAE0, &_47A714.next->_stru209, sizeof(stru_47CAE0));

        auto v91 = _47A714.next;
        _47A714.next = _47A714.next->next;
        _428940_list_return(v91);

        if (dword_47CB0C)
        {
            v92 = _47A660_array_num_items;
            if (_47A660_array_num_items >= 10)
                v92 = 0;
            _47A660_array_num_items = v92 + 1;

            _47A660_array[v92]._is_free = 1;
            memcpy(&_47A660_array[v92], &stru_47CAE0, sizeof(stru_47CAE0));
        }
    }
    else
    {
        stru_47CAE0.type = 0;
    }
}



//----- (00429C40) --------------------------------------------------------
bool cursor_unit_move(_428940_local *a1)
{
    _428940_local *v1; // esi@1
    Sprite *v2; // eax@2
    int v3; // ebx@2
    int v4; // ebp@2
    int v5; // edi@2
    Sprite *v6; // ecx@3
    int v7; // eax@3
    int v8; // edx@5
    BOOL result; // eax@16
    Sprite *v10; // ecx@18
    int v11; // [sp+4h] [bp-4h]@2

    v1 = a1;
    if (_47A5E0_mouse_input.just_pressed_buttons_mask & INPUT_MOUSE_LBUTTON_MASK)
    {
        a1->_70_sprite->field_88_unused = 1;
        v2 = a1->_70_sprite;
        v3 = 0;
        v4 = 0;
        v5 = v2->x;
        v11 = v2->y;
        if (!(_47A5E0_mouse_input.just_released_buttons_mask & INPUT_MOUSE_LBUTTON_MASK))
        {
            while (1)
            {
                cursor_process_user_actions(v1, 0);
                v1->_70_sprite->field_88_unused = 1;
                v6 = v1->_70_sprite;
                v7 = v6->x - v5;
                if (v7 < 0)
                    v7 = -v7;
                v8 = v6->y - v11;
                if (v8 < 0)
                    v8 = -v8;
                if (v4 > 6 && (v8 > 4096 || v7 > 4096))
                    break;
                ++v4;
                if (!v1->_68_selected_moveable_entity
                    && !v1->_38_are_owned_units_selected
                    && !v1->_68_entity_type___0convoy__2lab__9scout__3saboteur_vandal__4technicial_mekanik__and_more_see429D40
                    && v1->_20_load_mobd_item_offset != 12)
                {
                    v1->_20_load_mobd_item_offset = 12;
                    sprite_4272A0_load_mobd_item(v6, 12);
                }
                if (_47A5E0_mouse_input.just_released_buttons_mask & INPUT_MOUSE_LBUTTON_MASK)
                    return 1;
            }
            if (v1->_20_load_mobd_item_offset != 12)
            {
                v10 = v1->_70_sprite;
                v1->_20_load_mobd_item_offset = 12;
                sprite_4272A0_load_mobd_item(v10, 12);
            }
            cursor_drag_selection(v1, v5, v11);
            v3 = 1;
        }
        result = v3 == 0;
    }
    else
    {
        result = 0;
    }
    return result;
}

void cursor_unit_group_selection_response_sound(_428940_local *v3)
{
    enum SOUND_ID v26; // ecx@48
    int v36; // [sp-Ch] [bp-2Ch]@48

    if (v3->_38_are_owned_units_selected)
    {
        switch (v3->_48_highest_ranking_selected_unit)
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

//----- (00429D40) --------------------------------------------------------
void cursor_unit_selection_response_sound(_428940_local *a1, Entity *a2)
{
    _428940_local *v2; // esi@1
    Entity *v3; // edi@1
    enum UNIT_ID v4; // eax@1
    enum SCRIPT_TYPE v5; // ecx@22
    enum UNIT_ID v6; // eax@31
    enum SOUND_ID v7; // ecx@37
    int v8; // ST00_4@40
    int v9; // eax@40
    bool v10; // zf@46
    int v11; // eax@46
    int v12; // eax@54
    int v13; // edi@59
    int v14; // [sp-Ch] [bp-1Ch]@37

    v2 = a1;
    v3 = a2;
    a1->_48_highest_ranking_selected_unit = UNIT_STATS_SURV_RIFLEMAN;
    v4 = a2->unit_id;
    if ((int)v4 < (int)UNIT_STATS_SURV_MOBILE_OUTPOST
        || (int)v4 >(int)UNIT_STATS_MUTE_CLANHALL_WAGON)
    {
        if ((int)v4 < (int)UNIT_STATS_SURV_MOBILE_DERRICK
            || (int)v4 >(int)UNIT_STATS_MUTE_MOBILE_DERRICK)
        {
            if ((int)v4 < (int)UNIT_STATS_SURV_DIRT_BIKE
                || (int)v4 >(int)UNIT_STATS_MUTE_MISSILE_CRAB)
            {
                if (v4 == UNIT_STATS_SURV_SCOUT)
                {
                    a1->_68_selected_moveable_entity = a2;
                    a1->_68_entity_type___0convoy__2lab__9scout__3saboteur_vandal__4technicial_mekanik__and_more_see429D40 = 9;
                }
                else if ((int)v4 < (int)UNIT_STATS_GORT || (int)v4 >(int)UNIT_STATS_MECH)
                {
                    if (v4 == UNIT_STATS_SURV_SABOTEUR || v4 == UNIT_STATS_MUTE_VANDAL)
                    {
                        a1->_68_selected_moveable_entity = a2;
                        a1->_68_entity_type___0convoy__2lab__9scout__3saboteur_vandal__4technicial_mekanik__and_more_see429D40 = 3;
                    }
                    else if (v4 == UNIT_STATS_SURV_TECHNICIAN || v4 == UNIT_STATS_MUTE_MEKANIK)
                    {
                        a1->_68_selected_moveable_entity = a2;
                        a1->_68_entity_type___0convoy__2lab__9scout__3saboteur_vandal__4technicial_mekanik__and_more_see429D40 = 4;
                    }
                    else if ((v4 & 0x80000000) != 0 || (int)v4 > 20)
                    {
                        v5 = a2->script->script_type;
                        if (v5 == SCRIPT_RESEARCH_BUILDING_HANDLER)
                        {
                            v2->_68_selected_moveable_entity = a2;
                            v2->_68_entity_type___0convoy__2lab__9scout__3saboteur_vandal__4technicial_mekanik__and_more_see429D40 = 2;
                        }
                        else if (v5 == SCRIPT_TANKER_CONVOY_HANDLER)
                        {
                            if (v4 == UNIT_STATS_TANKER_CONVOY)
                            {
                                v2->_68_selected_moveable_entity = 0;
                                v2->_68_entity_type___0convoy__2lab__9scout__3saboteur_vandal__4technicial_mekanik__and_more_see429D40 = 0;
                                v2->_40_is_infantry_or_vehicle_selected = false;
                                v2->_44_is_combat_unit_selected = false;
                                return;
                            }
                            v2->_68_selected_moveable_entity = a2;
                            v2->_68_entity_type___0convoy__2lab__9scout__3saboteur_vandal__4technicial_mekanik__and_more_see429D40 = 1;
                        }
                        else
                        {
                            v2->_68_selected_moveable_entity = 0;
                            v2->_68_entity_type___0convoy__2lab__9scout__3saboteur_vandal__4technicial_mekanik__and_more_see429D40 = 0;
                        }
                    }
                    else
                    {
                        a1->_68_selected_moveable_entity = a2;
                        a1->_68_entity_type___0convoy__2lab__9scout__3saboteur_vandal__4technicial_mekanik__and_more_see429D40 = 9;
                    }
                }
                else
                {
                    a1->_68_selected_moveable_entity = a2;
                }
            }
            else
            {
                a1->_68_selected_moveable_entity = a2;
                a1->_68_entity_type___0convoy__2lab__9scout__3saboteur_vandal__4technicial_mekanik__and_more_see429D40 = 6;
            }
        }
        else
        {
            a1->_68_selected_moveable_entity = a2;
            a1->_68_entity_type___0convoy__2lab__9scout__3saboteur_vandal__4technicial_mekanik__and_more_see429D40 = 8;
        }
    }
    else
    {
        a1->_68_selected_moveable_entity = a2;
        a1->_68_entity_type___0convoy__2lab__9scout__3saboteur_vandal__4technicial_mekanik__and_more_see429D40 = 7;
    }
    v6 = a2->unit_id;
    switch (v6)
    {
    case UNIT_STATS_MUTE_DIRE_WOLF:
        sound_play(SOUND_MUTE_UNIT_DIRE_WOLF_READY, 0, _4690A8_unit_sounds_volume, 16, 0);
        v2->_48_highest_ranking_selected_unit = v3->unit_id;
        break;
    case UNIT_STATS_MUTE_GIANT_BEETLE:
        sound_play(SOUND_MUTE_UNIT_GIANT_BEETLE_READY, 0, _4690A8_unit_sounds_volume, 16, 0);
        v2->_48_highest_ranking_selected_unit = v3->unit_id;
        break;
    case UNIT_STATS_MUTE_GIANT_SCORPION:
        sound_play(SOUND_MUTE_UNIT_GIANT_SCORPION_READY, 0, _4690A8_unit_sounds_volume, 16, 0);
        v2->_48_highest_ranking_selected_unit = v3->unit_id;
        break;
    case UNIT_STATS_MUTE_MISSILE_CRAB:
        sound_play(SOUND_MUTE_UNIT_MISSILE_CRAB_READY, 0, _4690A8_unit_sounds_volume, 16, 0);
        v2->_48_highest_ranking_selected_unit = v3->unit_id;
        break;
    case UNIT_STATS_MUTE_WAR_MASTADONT:
        sound_play(SOUND_MUTE_UNIT_WAR_MASTADONT_READY, 0, _4690A8_unit_sounds_volume, 16, 0);
        v2->_48_highest_ranking_selected_unit = v3->unit_id;
        break;
    case UNIT_STATS_SURV_SCOUT:
        v14 = _4690A8_unit_sounds_volume;
        v7 = (SOUND_ID)192;
        goto LABEL_53;
    default:
        if ((int)v6 < (int)UNIT_STATS_GORT || (int)v6 >(int)UNIT_STATS_MECH)
        {
            if (((int)v6 < (int)UNIT_STATS_SURV_OUTPOST || (int)v6 >(int)UNIT_WALL_4)
                && ((int)v6 < (int)UNIT_STATS_SURV_DRILL_RIG
                    || (int)v6 >(int)UNIT_STATS_MUTE_POWER_STATION)
                && v2->_38_are_owned_units_selected)
            {
                v10 = get_player_faction() == 0;
                v11 = v3->_98_465610_accuracy_dmg_bonus_idx;
                if (v10)
                {
                    if (v11)
                    {
                        v14 = _4690A8_unit_sounds_volume;
                        v7 = _468A18_sound_ids[kknd_rand() % -2];
                    }
                    else
                    {
                        v14 = _4690A8_unit_sounds_volume;
                        v7 = _468988_sound_ids[(unsigned __int8)((char)kknd_rand() % -4)];
                    }
                }
                else if (v11)
                {
                    v14 = _4690A8_unit_sounds_volume;
                    v7 = _468A20_sound_ids[kknd_rand() % -2];
                }
                else
                {
                    v14 = _4690A8_unit_sounds_volume;
                    v7 = _468998_sound_ids[(unsigned __int8)((char)kknd_rand() % -4)];
                }
            LABEL_53:
                sound_play(v7, 0, v14, 16, 0);
            }
        }
        else
        {
            v8 = _4690A8_unit_sounds_volume;
            v9 = kknd_rand();
            sound_play(
                _4689A8_sound_ids[(((unsigned __int64)v9 >> 32) ^ abs(v9) & 1) - ((unsigned __int64)v9 >> 32)],
                0,
                v8,
                16,
                0);
            v2->_48_highest_ranking_selected_unit = v3->unit_id;
        }
        break;
    }
    v2->_40_is_infantry_or_vehicle_selected = false;
    v2->_44_is_combat_unit_selected = false;
    v12 = v3->unit_id;
    if (v12 <= (int)UNIT_STATS_MUTE_MISSILE_CRAB
        || v12 >= (int)UNIT_STATS_GORT
        || v12 == UNIT_STATS_SURV_MOBILE_OUTPOST
        || v12 == UNIT_STATS_MUTE_CLANHALL_WAGON)
    {
        v2->_40_is_infantry_or_vehicle_selected = true;
        v2->_44_is_combat_unit_selected = true;
    }
    v13 = v3->unit_id;
    if (v13 >= (int)UNIT_STATS_SURV_GUARD_TOWER && v13 <= (int)UNIT_STATS_MUTE_ROTARY_CANNON)
        v2->_44_is_combat_unit_selected = true;
}

//----- (0042A0A0) --------------------------------------------------------
void cursor_drag_selection_handler(_428940_local *a1)
{
    int v1; // ebx@1
    _428940_local *v2; // esi@1
    _428940_local *v3; // eax@5
    int v4; // edx@5
    enum PLAYER_SIDE v5; // edi@6
    char v6; // cl@7
    int v12; // ebx@19
    Entity *v13; // ebp@21
    int v14; // edx@21
    enum UNIT_ID v15; // eax@21
    int v16; // edi@23
    UnitStat *v17; // ecx@25
    UnitAttachmentPoint *v18; // eax@25
    int v19; // edx@34
    int v20; // eax@36
    Sprite *v21; // ecx@46
    Entity *v22; // eax@48
    enum SOUND_ID v23; // ecx@50
    Sprite *v30; // ecx@63
    Entity *v36; // ecx@71
    int v37; // eax@72
    int v38; // esi@74
    int v39; // ST00_4@76
    int v40; // eax@76
    int v41; // esi@102
    int v42; // ST00_4@104
    int v43; // eax@104
    int v44; // eax@118
    Sprite *v45; // ecx@123
    Entity *v46; // eax@125
    enum SOUND_ID v47; // ecx@127
    Sprite *v52; // ecx@142
    Sprite *v57; // ecx@152
    enum UNIT_ID v62; // edi@168
    BOOL v63; // eax@168
    Sprite *v64; // ecx@170
    int v68; // edi@183
    int v69; // ebx@183
    Sprite *v70; // ecx@186
    Entity *v71; // eax@188
    Sprite *v72; // ecx@191
    Entity *v73; // eax@192
    Sprite *v74; // ecx@196
    Sprite *v75; // ecx@200
    int v76; // eax@203
    _428940_local *i; // edi@213
    task_428940_attach__cursors_2 *v83; // eax@217
    int v84; // eax@221
    Sprite *v85; // ecx@228
    int v86; // edx@232
    Sprite *v87; // ecx@235
    int v88; // eax@238
    Sprite *v89; // ecx@240
    Sprite *v90; // ecx@243
    int v91; // [sp-Ch] [bp-24h]@50
    int v92; // [sp-Ch] [bp-24h]@127
    enum SCRIPT_TYPE v93; // [sp+10h] [bp-8h]@21
    int v94; // [sp+14h] [bp-4h]@21

    v1 = _47A700_input._10_wndproc_mapped_key;
    v2 = a1;
    if (_47A700_input._10_wndproc_mapped_key >= 2u
        && _47A700_input._10_wndproc_mapped_key <= 0xBu
        && dword_47A6FC == 29
        && _47A700_input._10_wndproc_mapped_key - 2 != dword_468984)
    {
        v3 = a1->next;
        v4 = _47A700_input._10_wndproc_mapped_key - 1;
        if (a1->next != a1)
        {
            v5 = player_side;
            do
            {
                v6 = *((_BYTE *)v3->_8_task->param + v5 + 660);
                if (v6 > 0 && v6 < 11)
                    --_47A608_stru13_associated_array.field_0[v6];
                ++_47A608_stru13_associated_array.field_0[v4];
                v3 = v3->next;
            } while (v3 != v2);
        }

        _47A714._stru209.type = 4;
        _47A714._stru209.param = v1 - 1;
        _428940_list_do_stuff(&_47A714._stru209);

        dword_468984 = v1 - 2;
        return;
    }
    if (a1->_18_script)
        return;
    v12 = 1;
    if (!a1->_1C_script || (a1->_70_sprite->field_88_unused = 1, !_44B0D0_not_fog_of_war(a1->_70_sprite->x, a1->_70_sprite->y)))
    {
        if (!v2->_38_are_owned_units_selected || !v2->_40_is_infantry_or_vehicle_selected)
        {
            v88 = v2->_20_load_mobd_item_offset;
            if (_47A5E0_mouse_input.just_pressed_buttons_mask & INPUT_MOUSE_LBUTTON_MASK)
            {
                if (v88 != 12)
                {
                    v89 = v2->_70_sprite;
                    v2->_20_load_mobd_item_offset = 12;
                    sprite_4272A0_load_mobd_item(v89, 12);
                }
                v2->_70_sprite->field_88_unused = 1;
                cursor_drag_selection(v2, v2->_70_sprite->x, v2->_70_sprite->y);
            }
            else if (v88 != 12)
            {
                v90 = v2->_70_sprite;
                v2->_20_load_mobd_item_offset = 12;
                sprite_4272A0_load_mobd_item(v90, 12);
            }
            return;
        }
        v2->_70_sprite->field_88_unused = 1;
        if (!_44B0D0_not_fog_of_war(v2->_70_sprite->x, v2->_70_sprite->y))
            goto LABEL_246;
        if (v2->field_34)
        {
            if (v2->_20_load_mobd_item_offset != 448)
            {
                v85 = v2->_70_sprite;
                v2->_20_load_mobd_item_offset = 448;
                sprite_4272A0_load_mobd_item(v85, 448);
            }
            cursor_unit_move(v2);
            return;
        }
        if (v2->_68_entity_type___0convoy__2lab__9scout__3saboteur_vandal__4technicial_mekanik__and_more_see429D40 == 8
            && (v2->_70_sprite->field_88_unused = 1, oilspot_list_407040_find_by_coordinates(v2->_70_sprite->x, v2->_70_sprite->y)))
        {
            v86 = 572;
            if (v2->_20_load_mobd_item_offset == 572)
                goto LABEL_236;
        }
        else
        {
        LABEL_246:
            v86 = 384;
            if (v2->_20_load_mobd_item_offset == 384)
                goto LABEL_236;
        }
        v87 = v2->_70_sprite;
        v2->_20_load_mobd_item_offset = v86;
        sprite_4272A0_load_mobd_item(v87, v86);
    LABEL_236:
        if (cursor_unit_move(v2))
            cursor_unit_move_confirmation(v2);
        return;
    }
    v13 = (Entity *)v2->_1C_script->param;
    v14 = 0;
    v15 = v13->unit_id;
    v93 = v13->script->script_type;
    v94 = v15 == UNIT_STATS_TECH_BUNKER;
    v16 = v15 == UNIT_STATS_SURV_DETENTION_CENTER || v15 == UNIT_STATS_MUTE_HOLDING_PENS;
    v17 = v13->stats;
    v18 = v17->attach;
    if (v18 && v18->dmg_source)
        v14 = 1;
    v19 = !v17->speed && !v14 && !v94 && !v16 && (v13->player_side != player_side || *((_WORD *)v13->state + 7) < 5);
    v20 = v2->_68_entity_type___0convoy__2lab__9scout__3saboteur_vandal__4technicial_mekanik__and_more_see429D40;
    if (v20 && (v20 >= 1 && v20 <= 4 || v20 >= 7 && v20 <= 8))
        v12 = 0;
    if (v2->_38_are_owned_units_selected && v20 == 3 && v19)
    {
        if (v2->_20_load_mobd_item_offset != 244)
        {
            v21 = v2->_70_sprite;
            v2->_20_load_mobd_item_offset = 244;
            sprite_4272A0_load_mobd_item(v21, 244);
        }
        if (cursor_unit_move(v2))
        {
            v22 = v2->_68_selected_moveable_entity;
            if (v22)
            {
                if (v22->unit_id == UNIT_STATS_SURV_SABOTEUR)
                {
                    v91 = _4690A8_unit_sounds_volume;
                    v23 = SOUND_45_surv_saboteur;
                }
                else
                {
                    v91 = _4690A8_unit_sounds_volume;
                    v23 = SOUND_124_mute_saboteur;
                }

                sound_play(v23, 0, v91, 16, 0);

                _47A714._stru209.type = 24;
                _47A714._stru209.param = v2->_68_selected_moveable_entity->entity_id;
                _47A714._stru209.param2 = v13->entity_id;
                _428940_list_do_stuff(&_47A714._stru209);
            }
        }
        return;
    }
    if ((sub_44CE00(player_side, v13) || dword_47A6FC == 56) && v2->_38_are_owned_units_selected && v2->_44_is_combat_unit_selected && v12)
    {
        if (v2->_20_load_mobd_item_offset != 304)
        {
            v30 = v2->_70_sprite;
            v2->_20_load_mobd_item_offset = 304;
            sprite_4272A0_load_mobd_item(v30, 304);
        }
        if (!cursor_unit_move(v2))
            return;

        _47A714._stru209.type = 7;
        _47A714._stru209.param = v13->entity_id;
        _428940_list_do_stuff(&_47A714._stru209);

        v36 = v2->_68_selected_moveable_entity;
        if (v36)
        {
            v37 = v36->unit_id;
            if (v37 >= (int)UNIT_STATS_GORT && v37 <= (int)UNIT_STATS_MECH
                || (v38 = v2->_48_highest_ranking_selected_unit, v38 >= (int)UNIT_STATS_GORT) && v38 <= (int)UNIT_STATS_MECH)
            {
                v39 = _4690A8_unit_sounds_volume;
                v40 = kknd_rand();
                sound_play(_4689B0_sound_ids[v40 % 3], 0, v39, 16, 0);
                return;
            }
            if (v37 == UNIT_STATS_MUTE_MISSILE_CRAB || v38 == UNIT_STATS_MUTE_MISSILE_CRAB)
            {
                sound_play(SOUND_MUTE_UNIT_MISSILE_CRAB_2, 0, _4690A8_unit_sounds_volume, 16, 0);
                return;
            }
            if (v37 != UNIT_STATS_MUTE_GIANT_BEETLE && v38 != UNIT_STATS_MUTE_GIANT_BEETLE)
            {
                if (v37 == UNIT_STATS_MUTE_WAR_MASTADONT || v38 == UNIT_STATS_MUTE_WAR_MASTADONT)
                {
                    sound_play(SOUND_MUTE_UNIT_WAR_MASTADONT_2, 0, _4690A8_unit_sounds_volume, 16, 0);
                    return;
                }
                if (v37 == UNIT_STATS_MUTE_GIANT_SCORPION || v38 == UNIT_STATS_MUTE_GIANT_SCORPION)
                {
                    sound_play(SOUND_MUTE_UNIT_GIANT_SCORPION_2, 0, _4690A8_unit_sounds_volume, 16, 0);
                    return;
                }
                if (v37 != UNIT_STATS_MUTE_DIRE_WOLF && v38 != UNIT_STATS_MUTE_DIRE_WOLF)
                {
                    if (v37 == UNIT_STATS_SURV_SCOUT)
                    {
                        sound_play(SOUND_SURV_UNIT_SCOUT_192, 0, _4690A8_unit_sounds_volume, 16, 0);
                        return;
                    }
                    if (v36->_98_465610_accuracy_dmg_bonus_idx)
                    {
                        if (get_player_faction())
                            sound_play(SOUND_153, 0, _4690A8_unit_sounds_volume, 16, 0);
                        else
                            sound_play(SOUND_73, 0, _4690A8_unit_sounds_volume, 16, 0);
                        return;
                    }
                    if (!get_player_faction())
                    {
                        if ((char)kknd_rand() % -2)
                            sound_play(SOUND_59, 0, _4690A8_unit_sounds_volume, 16, 0);
                        else
                            sound_play(SOUND_48, 0, _4690A8_unit_sounds_volume, 16, 0);
                        return;
                    }
                    if ((char)kknd_rand() % -2)
                    {
                        sound_play(SOUND_92, 0, _4690A8_unit_sounds_volume, 16, 0);
                        return;
                    }
                LABEL_117:
                    sound_play(SOUND_119, 0, _4690A8_unit_sounds_volume, 16, 0);
                    return;
                }
                goto LABEL_114;
            }
        }
        else
        {
            v41 = v2->_48_highest_ranking_selected_unit;
            if (v41 >= (int)UNIT_STATS_GORT && v41 <= (int)UNIT_STATS_MECH)
            {
                v42 = _4690A8_unit_sounds_volume;
                v43 = kknd_rand();
                sound_play(_4689B0_sound_ids[v43 % 3], 0, v42, 16, 0);
                return;
            }
            if (v41 == UNIT_STATS_MUTE_MISSILE_CRAB)
            {
                sound_play(SOUND_MUTE_UNIT_MISSILE_CRAB_2, 0, _4690A8_unit_sounds_volume, 16, 0);
                return;
            }
            if (v41 != UNIT_STATS_MUTE_GIANT_BEETLE)
            {
                if (v41 == UNIT_STATS_MUTE_WAR_MASTADONT)
                {
                    sound_play(SOUND_MUTE_UNIT_WAR_MASTADONT_2, 0, _4690A8_unit_sounds_volume, 16, 0);
                    return;
                }
                if (v41 == UNIT_STATS_MUTE_GIANT_SCORPION)
                {
                    sound_play(SOUND_MUTE_UNIT_GIANT_SCORPION_2, 0, _4690A8_unit_sounds_volume, 16, 0);
                    return;
                }
                if (v41 != UNIT_STATS_MUTE_DIRE_WOLF)
                {
                    if (!get_player_faction())
                    {
                        sound_play(SOUND_59, 0, _4690A8_unit_sounds_volume, 16, 0);
                        return;
                    }
                    goto LABEL_117;
                }
            LABEL_114:
                sound_play(SOUND_MUTE_UNIT_DIRE_WOLF_2, 0, _4690A8_unit_sounds_volume, 16, 0);
                return;
            }
        }
        sound_play(SOUND_MUTE_UNIT_GIANT_BEETLE_2, 0, _4690A8_unit_sounds_volume, 16, 0);
        return;
    }
    v44 = v2->_68_entity_type___0convoy__2lab__9scout__3saboteur_vandal__4technicial_mekanik__and_more_see429D40;
    if (v44 == 4 && !v13->stats->speed && !v94 && v13->player_side == player_side)
    {
        if (v2->_20_load_mobd_item_offset != 144)
        {
            v45 = v2->_70_sprite;
            v2->_20_load_mobd_item_offset = 144;
            sprite_4272A0_load_mobd_item(v45, 144);
        }
        if (!cursor_unit_move(v2))
            return;
        v46 = v2->_68_selected_moveable_entity;
        if (!v46)
            return;
        if (v46->unit_id == 12)
        {
            v92 = _4690A8_unit_sounds_volume;
            v47 = (SOUND_ID)45;
        }
        else
        {
            v92 = _4690A8_unit_sounds_volume;
            v47 = (SOUND_ID)124;
        }
        sound_play(v47, 0, v92, 16, 0);

        _47A714._stru209.type = 22;
        _47A714._stru209.param = v2->_68_selected_moveable_entity->entity_id;
        _47A714._stru209.param2 = v13->entity_id;
        _428940_list_do_stuff(&_47A714._stru209);
    }
    if (v44 == 1)
    {
        if (v93 == SCRIPT_POWER_STATION_HANDLER)
        {
        LABEL_139:
            if (!entity_402AC0_is_mode_402AB0(v13) && v13->player_side == player_side)
            {
                if (v2->_20_load_mobd_item_offset != 572)
                {
                    v52 = v2->_70_sprite;
                    v2->_20_load_mobd_item_offset = 572;
                    sprite_4272A0_load_mobd_item(v52, 572);
                }
                if (cursor_unit_move(v2))
                {
                    if (v2->_68_selected_moveable_entity)
                    {
                        _47A714._stru209.type = 20;
                        _47A714._stru209.param = v2->_68_selected_moveable_entity->entity_id;
                        _47A714._stru209.param2 = v13->entity_id;
                        _428940_list_do_stuff(&_47A714._stru209);
                    }
                }
                return;
            }
        LABEL_150:
            if (v93 != SCRIPT_DRILLRIG_HANDLER)
            {
                if (v93 == SCRIPT_REPAIR_STATION_HANDLER && v13->player_side == player_side)
                    sub_42AFD0(v2, v13);
                return;
            }
            if (v2->_20_load_mobd_item_offset != 572)
            {
                v57 = v2->_70_sprite;
                v2->_20_load_mobd_item_offset = 572;
                sprite_4272A0_load_mobd_item(v57, 572);
            }
            if (cursor_unit_move(v2))
            {
                if (v2->_68_selected_moveable_entity)
                {
                    _47A714._stru209.type = 19;
                    _47A714._stru209.param = v2->_68_selected_moveable_entity->entity_id;
                    _47A714._stru209.param2 = v13->entity_id;
                    _428940_list_do_stuff(&_47A714._stru209);
                }
            }
            return;
        }
        if (v93 == SCRIPT_DRILLRIG_HANDLER || v93 == SCRIPT_REPAIR_STATION_HANDLER)
        {
            if (v93 != SCRIPT_POWER_STATION_HANDLER)
                goto LABEL_150;
            goto LABEL_139;
        }
    }
    if (v44 == 6 && v93 == SCRIPT_REPAIR_STATION_HANDLER)
    {
        sub_42AFD0(v2, v13);
        return;
    }
    if (v44 == 7
        && v13->entity_id == v2->_68_selected_moveable_entity->entity_id
        && (v62 = v13->unit_id,
            v13->unit_id = v62 == UNIT_STATS_SURV_MOBILE_OUTPOST ? UNIT_STATS_SURV_OUTPOST : UNIT_STATS_MUTE_CLANHALL,
            v63 = entity_40DBF0_boxd(v13),
            v13->unit_id = v62,
            v63))
    {
        if (v2->_20_load_mobd_item_offset != 188)
        {
            v64 = v2->_70_sprite;
            v2->_20_load_mobd_item_offset = 188;
            sprite_4272A0_load_mobd_item(v64, 188);
        }
        if (cursor_unit_move(v2))
        {
            _47A714._stru209.type = 10;
            //_47A714._stru209.param = ;
            _47A714._stru209.param2 = v13->entity_id;
            _428940_list_do_stuff(&_47A714._stru209);

            return;
        }
    }
    else if (v2->_68_entity_type___0convoy__2lab__9scout__3saboteur_vandal__4technicial_mekanik__and_more_see429D40 != 2
        || (int)v93 < (int)SCRIPT_SURV_OUTPOST_HANDLER
        || (int)v93 >= (int)SCRIPT_RESEARCH_BUILDING_HANDLER
        || entity_402AC0_is_mode_402AB0(v13)
        || v13->player_side != player_side)
    {
        if (v2->_20_load_mobd_item_offset != 48)
        {
            v75 = v2->_70_sprite;
            v2->_20_load_mobd_item_offset = 48;
            sprite_4272A0_load_mobd_item(v75, 48);
        }
        if (cursor_unit_move(v2))
        {
            if (v2->field_3C)
                v76 = v2->next->_8_task == v13->script;
            else
                v76 = 0;
            if (v76)
            {
                sub_4297D0(v2, v13->array_294[player_side]);
            }
            else
            {
                _47A714._stru209.type = 2;
                _47A714._stru209.param = v13->entity_id;
                _428940_list_do_stuff(&_47A714._stru209);

                v2->_68_selected_moveable_entity = nullptr;
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
                v83 = v2->ptr_10;
                if (v83)
                    v2->ptr_10 = v83->next;
                else
                    v83 = 0;
                if (v83)
                {
                    v83->_8_task = v13->script;
                    v83->next = (task_428940_attach__cursors_2 *)v2->next;
                    v83->prev = (task_428940_attach__cursors_2 *)v2;
                    v2->next->prev = (_428940_local *)v83;
                    v2->next = (_428940_local *)v83;
                    script_trigger_event(0, EVT_MSG_1511_sidebar_click_category, 0, v13->script);
                    v84 = v13->player_side == player_side;
                    v2->_38_are_owned_units_selected = v84;
                    if (v84)
                        cursor_unit_selection_response_sound(v2, v13);
                }
            }
        }
    }
    else
    {
        v68 = (int)v13->state;
        v69 = (int)v2->_68_selected_moveable_entity->state;
        if (*(_DWORD *)(v68 + 4) >= _441630_get_current_level_field14(v13->unit_id) || *(_DWORD *)(v69 + 8))
        {
            if (v2->_20_load_mobd_item_offset != 448)
            {
                v72 = v2->_70_sprite;
                v2->_20_load_mobd_item_offset = 448;
                sprite_4272A0_load_mobd_item(v72, 448);
            }
            v73 = v2->_68_selected_moveable_entity;
            if (v73 && *(_DWORD *)(v69 + 8) && v73->sprite->parent == (Sprite *)v13->entity_id)
            {
                if (v2->_20_load_mobd_item_offset != 280)
                {
                    v74 = v2->_70_sprite;
                    v2->_20_load_mobd_item_offset = 280;
                    sprite_4272A0_load_mobd_item(v74, 280);
                }
                if (cursor_unit_move(v2))
                    script_trigger_event_group(v2->_14_task, EVT_MSG_1545, 0, SCRIPT_UPGRADE_PROCESS);
            }
        }
        else
        {
            if (v2->_20_load_mobd_item_offset != 216)
            {
                v70 = v2->_70_sprite;
                v2->_20_load_mobd_item_offset = 216;
                sprite_4272A0_load_mobd_item(v70, 216);
            }
            if (cursor_unit_move(v2))
            {
                v71 = v2->_68_selected_moveable_entity;
                if (v71)
                    script_trigger_event(v2->_14_task, EVT_MSG_COMMENCE_UPGRADE, v13, v71->script);
            }
        }
    }
}


//----- (004297D0) --------------------------------------------------------
void sub_4297D0(_428940_local *a1, int edx0)
{
    _428940_local *v2; // esi@1
    _428940_local *v8; // edi@8
    Entity *v9; // edi@12
    Entity *i; // ebp@12
    task_428940_attach__cursors_2 *v11; // eax@15
    int v12; // eax@22
    enum UNIT_ID v13; // ecx@26
    enum UNIT_ID v14; // eax@26
    int v15; // eax@29
    enum SOUND_ID v16; // ecx@35
    _428940_local *v17; // ecx@48
    int v18; // ebx@48
    int v19; // eax@48
    int j; // edi@48
    Script *v21; // edx@49
    int v22; // edx@49
    DrawJobDetails *v23; // ebp@51
    int v24; // esi@51
    int v25; // edi@51
    int v26; // [sp-Ch] [bp-24h]@35
    int v27; // [sp+10h] [bp-8h]@2
    int a2; // [sp+14h] [bp-4h]@1

    a2 = edx0;
    v2 = a1;
    if (_47A608_stru13_associated_array.field_0[edx0] > 0)
    {
        v27 = 0;

        _47A714._stru209.type = 5;
        _47A714._stru209.param = edx0;
        _428940_list_do_stuff(&_47A714._stru209);

        v8 = v2->next;
        v2->_38_are_owned_units_selected = false;
        v2->_68_selected_moveable_entity = nullptr;
        v2->_40_is_infantry_or_vehicle_selected = false;
        v2->_44_is_combat_unit_selected = false;
        v2->_48_highest_ranking_selected_unit = UNIT_STATS_SURV_RIFLEMAN;
        for (v2->_68_entity_type___0convoy__2lab__9scout__3saboteur_vandal__4technicial_mekanik__and_more_see429D40 = 0;
            v8 != v2;
            v8 = v8->next)
        {
            script_trigger_event(task_mobd17_cursor, EVT_MSG_TEXT_STRING, 0, v8->_8_task);
        }
        if (v2->next != v2)
        {
            v2->prev->next = (_428940_local *)v2->ptr_10;
            v2->ptr_10 = (task_428940_attach__cursors_2 *)v2->next;
            v2->next = v2;
            v2->prev = v2;
        }
        v9 = entity_list_head;
        for (i = (Entity *)a2; (Entity **)v9 != &entity_list_head; v9 = v9->next)
        {
            if (v9->array_294[player_side] == a2 && !v9->destroyed)
            {
                v11 = v2->ptr_10;
                if (v11)
                    v2->ptr_10 = v11->next;
                else
                    v11 = 0;
                if (v11)
                {
                    v11->_8_task = v9->script;
                    v11->next = (task_428940_attach__cursors_2 *)v2->next;
                    v11->prev = (task_428940_attach__cursors_2 *)v2;
                    v2->next->prev = (_428940_local *)v11;
                    v2->next = (_428940_local *)v11;
                    script_trigger_event(0, EVT_MSG_1511_sidebar_click_category, 0, v11->_8_task);
                    if (v9->player_side == player_side)
                        v2->_38_are_owned_units_selected = true;
                    ++v27;
                    i = v9;
                    if (v9->player_side == player_side)
                    {
                        v12 = v9->unit_id;
                        if (v12 <= (int)UNIT_STATS_MUTE_MISSILE_CRAB
                            || v12 >= (int)UNIT_STATS_GORT
                            || v12 == UNIT_STATS_SURV_MOBILE_OUTPOST
                            || v12 == UNIT_STATS_MUTE_CLANHALL_WAGON)
                        {
                            v13 = v2->_48_highest_ranking_selected_unit;
                            v2->_68_selected_moveable_entity = v9;
                            v2->_40_is_infantry_or_vehicle_selected = true;
                            v2->_44_is_combat_unit_selected = true;
                            v14 = v9->unit_id;
                            if ((int)v14 > (int)v13 && v14 != UNIT_STATS_MUTE_BIKE_AND_SIDECAR)
                                v2->_48_highest_ranking_selected_unit = v14;
                        }
                        v15 = v9->unit_id;
                        if (v15 >= (int)UNIT_STATS_SURV_GUARD_TOWER && v15 <= (int)UNIT_STATS_MUTE_ROTARY_CANNON)
                            v2->_44_is_combat_unit_selected = true;
                    }
                }
            }
        }
        if (v27 > 1)
        {
            switch (v2->_48_highest_ranking_selected_unit)
            {
            case 0x4Au:
            case 0x4Cu:
            case 0x4Du:
            case 0x4Eu:
                v26 = _4690A8_unit_sounds_volume;
                v16 = _4689A8_sound_ids[kknd_rand() % -2];
                break;
            case 0x1Bu:
                v26 = _4690A8_unit_sounds_volume;
                v16 = (SOUND_ID)165;
                break;
            case 0x25u:
                v26 = _4690A8_unit_sounds_volume;
                v16 = (SOUND_ID)168;
                break;
            case 0x21u:
                v26 = _4690A8_unit_sounds_volume;
                v16 = (SOUND_ID)172;
                break;
            case 0x27u:
                v26 = _4690A8_unit_sounds_volume;
                v16 = (SOUND_ID)170;
                break;
            case 0x23u:
                v26 = _4690A8_unit_sounds_volume;
                v16 = (SOUND_ID)160;
                break;
            default:
                if (get_player_faction())
                {
                    v26 = _4690A8_unit_sounds_volume;
                    v16 = _468998_sound_ids[(unsigned __int8)((char)kknd_rand() % -4)];
                }
                else
                {
                    v26 = _4690A8_unit_sounds_volume;
                    v16 = _468988_sound_ids[(unsigned __int8)((char)kknd_rand() % -4)];
                }
                break;
            }
            sound_play(v16, 0, v26, 16, 0);
        }
        v2->field_3C = v27 == 1;
        if (v27 == 1)
            cursor_unit_selection_response_sound(v2, i);
        if (_47A700_input.pressed_keys_mask & 0x20)
        {
            v17 = v2->next;
            v18 = 0;
            v19 = 0;
            for (j = 0; v17 != v2; j += *(_DWORD *)(v22 + 20))
            {
                v21 = v17->_8_task;
                v17 = v17->next;
                ++v18;
                v22 = *((_DWORD *)v21->param + 23);
                v19 += *(_DWORD *)(v22 + 16);
            }
            if (v18)
            {
                v23 = &_47A010_mapd_item_being_drawn[0]->draw_job->job_details;
                v24 = v19 / v18 - (render_width << 7) + 4096;
                v25 = j / v18 - (render_height << 7);
                if (v24 >= 0)
                {
                    if (v24 > (32
                        - render_width
                        + render_call_draw_handler_mode1(&_47A010_mapd_item_being_drawn[0]->draw_job->job_details)) << 8)
                        v24 = (32 - render_width + render_call_draw_handler_mode1(v23)) << 8;
                }
                else
                {
                    v24 = 0;
                }
                if (v25 >= 0)
                {
                    if (v25 > (render_call_draw_handler_mode2(v23) - render_height) << 8)
                        v25 = (render_call_draw_handler_mode2(v23) - render_height) << 8;
                    _47C380_mapd.mapd_cplc_render_x = v24;
                    _47C380_mapd.mapd_cplc_render_y = v25;
                }
                else
                {
                    _47C380_mapd.mapd_cplc_render_x = v24;
                    _47C380_mapd.mapd_cplc_render_y = 0;
                }
            }
        }
    }
}
// 47A608: using guessed type stru13_stru0 _47A608_stru13_associated_array;

//----- (00429C20) --------------------------------------------------------
void _429C20_load_mobd(_428940_local *a1, int offset)
{
    if (offset != a1->_20_load_mobd_item_offset)
    {
        a1->_20_load_mobd_item_offset = offset;
        sprite_4272A0_load_mobd_item(a1->_70_sprite, offset);
    }
}

//----- (0042AFD0) --------------------------------------------------------
void sub_42AFD0(_428940_local *a1, Entity *a2)
{
    Entity *v2; // edi@1
    _428940_local *v3; // esi@1
    Entity *v4; // eax@3
    Sprite *v5; // ecx@6
    int v11; // ST00_4@22
    int v12; // eax@22
    int v13; // ST00_4@23
    int v14; // eax@23
    Sprite *v15; // ecx@25
    Sprite *v16; // ecx@27

    v2 = a2;
    v3 = a1;
    if (entity_402AC0_is_mode_402AB0(a2) || *((_DWORD *)v2->state + 2))
    {
        if (v3->_20_load_mobd_item_offset != 292)
        {
            v16 = v3->_70_sprite;
            v3->_20_load_mobd_item_offset = 292;
            sprite_4272A0_load_mobd_item(v16, 292);
        }
    }
    else
    {
        v4 = v3->_68_selected_moveable_entity;
        if (v4 && v4->hitpoints < v4->stats->hitpoints)
        {
            if (v3->_20_load_mobd_item_offset != 144)
            {
                v5 = v3->_70_sprite;
                v3->_20_load_mobd_item_offset = 144;
                sprite_4272A0_load_mobd_item(v5, 144);
            }
            if (cursor_unit_move(v3) && v3->_68_selected_moveable_entity)
            {
                _47A714._stru209.type = 21;
                _47A714._stru209.param = v3->_68_selected_moveable_entity->entity_id;
                _47A714._stru209.param2 = v2->entity_id;
                _428940_list_do_stuff(&_47A714._stru209);

                switch (v3->_68_selected_moveable_entity->unit_id)
                {
                case UNIT_STATS_MUTE_DIRE_WOLF:
                    sound_play(SOUND_MUTE_UNIT_DIRE_WOLF_READY, 0, _4690A8_unit_sounds_volume, 16, 0);
                    break;
                case UNIT_STATS_MUTE_GIANT_BEETLE:
                    sound_play(SOUND_MUTE_UNIT_GIANT_BEETLE_READY, 0, _4690A8_unit_sounds_volume, 16, 0);
                    break;
                case UNIT_STATS_MUTE_GIANT_SCORPION:
                    sound_play(SOUND_MUTE_UNIT_GIANT_SCORPION_READY, 0, _4690A8_unit_sounds_volume, 16, 0);
                    break;
                case UNIT_STATS_MUTE_MISSILE_CRAB:
                    sound_play(SOUND_MUTE_UNIT_MISSILE_CRAB_READY, 0, _4690A8_unit_sounds_volume, 16, 0);
                    break;
                case UNIT_STATS_MUTE_WAR_MASTADONT:
                    sound_play(SOUND_MUTE_UNIT_WAR_MASTADONT_READY, 0, _4690A8_unit_sounds_volume, 16, 0);
                    break;
                default:
                    if (get_player_faction())
                    {
                        v13 = _4690A8_unit_sounds_volume;
                        v14 = kknd_rand();
                        sound_play(
                            _468998_sound_ids[(((unsigned __int64)v14 >> 32) ^ abs(v14) & 3) - ((unsigned __int64)v14 >> 32)],
                            0,
                            v13,
                            16,
                            0);
                    }
                    else
                    {
                        v11 = _4690A8_unit_sounds_volume;
                        v12 = kknd_rand();
                        sound_play(
                            _468988_sound_ids[(((unsigned __int64)v12 >> 32) ^ abs(v12) & 3) - ((unsigned __int64)v12 >> 32)],
                            0,
                            v11,
                            16,
                            0);
                    }
                    break;
                }
            }
        }
        else if (v3->_20_load_mobd_item_offset != 292)
        {
            v15 = v3->_70_sprite;
            v3->_20_load_mobd_item_offset = 292;
            sprite_4272A0_load_mobd_item(v15, 292);
        }
    }
}

//----- (0042B230) --------------------------------------------------------
void cursor_unit_move_confirmation(_428940_local *a1)
{
    _428940_local *v1; // edi@1
    Entity *v7; // edx@7
    int v8; // eax@8
    int v9; // ecx@12
    enum SOUND_ID v10; // ecx@14
    bool v11; // zf@35
    Entity *v12; // eax@35
    int v13; // eax@38
    int v14; // eax@46
    int v15; // eax@47
    Sprite *v16; // esi@53
    int v17; // ebx@53
    int v18; // eax@53
    int v19; // [sp-Ch] [bp-1Ch]@14

    v1 = a1;
    a1->_70_sprite->field_88_unused = 1;

    _47A714._stru209.type = 6;
    _47A714._stru209.param = a1->_70_sprite->x;
    _47A714._stru209.param2 = a1->_70_sprite->y;
    _428940_list_do_stuff(&_47A714._stru209);

    v7 = v1->_68_selected_moveable_entity;
    if (v7)
    {
        v8 = v7->unit_id;
        if (v8 < (int)UNIT_STATS_SURV_DRILL_RIG || v8 >(int)UNIT_WALL_4)
        {
            if (v8 >= (int)UNIT_STATS_GORT && v8 <= (int)UNIT_STATS_MECH
                || (v9 = v1->_48_highest_ranking_selected_unit, v9 >= (int)UNIT_STATS_GORT) && v9 <= (int)UNIT_STATS_MECH)
            {
                v19 = _4690A8_unit_sounds_volume;
                v10 = _4689C0_sound_ids[kknd_rand() % 22];
                goto LABEL_53;
            }
            if (v8 == UNIT_STATS_SURV_SCOUT)
            {
                v19 = _4690A8_unit_sounds_volume;
                v10 = (SOUND_ID)192;
                goto LABEL_53;
            }
            if (v8 == UNIT_STATS_MUTE_MISSILE_CRAB || v9 == UNIT_STATS_MUTE_MISSILE_CRAB)
            {
                v19 = _4690A8_unit_sounds_volume;
                v10 = (SOUND_ID)171;
            }
            else if (v8 == UNIT_STATS_MUTE_GIANT_BEETLE || v9 == UNIT_STATS_MUTE_GIANT_BEETLE)
            {
                v19 = _4690A8_unit_sounds_volume;
                v10 = (SOUND_ID)169;
            }
            else if (v8 == UNIT_STATS_MUTE_WAR_MASTADONT || v9 == UNIT_STATS_MUTE_WAR_MASTADONT)
            {
                v19 = _4690A8_unit_sounds_volume;
                v10 = (SOUND_ID)159;
            }
            else if (v8 == UNIT_STATS_MUTE_GIANT_SCORPION || v9 == UNIT_STATS_MUTE_GIANT_SCORPION)
            {
                v19 = _4690A8_unit_sounds_volume;
                v10 = (SOUND_ID)173;
            }
            else if (v8 == UNIT_STATS_MUTE_DIRE_WOLF || v9 == UNIT_STATS_MUTE_DIRE_WOLF)
            {
                v19 = _4690A8_unit_sounds_volume;
                v10 = (SOUND_ID)164;
            }
            else
            {
                if (v8 != UNIT_STATS_MUTE_BIKE_AND_SIDECAR
                    && v8 != UNIT_STATS_MONSTER_TRUCK
                    && v8 != UNIT_STATS_MUTE_MOBILE_DERRICK
                    && v8 != UNIT_STATS_MUTE_TANKER
                    && v9 != UNIT_STATS_MUTE_BIKE_AND_SIDECAR
                    && v9 != UNIT_STATS_MONSTER_TRUCK
                    && v9 != UNIT_STATS_MUTE_MOBILE_DERRICK
                    && v9 != UNIT_STATS_MUTE_TANKER)
                {
                    v11 = get_player_faction() == 0;
                    v12 = v1->_68_selected_moveable_entity;
                    if (v11)
                    {
                        if (v12)
                        {
                            if (v12->_98_465610_accuracy_dmg_bonus_idx)
                            {
                                v19 = _4690A8_unit_sounds_volume;
                                v13 = kknd_rand();
                                v10 = _468A48_sound_ids[(((unsigned __int64)v13 >> 32) ^ abs(v13) & 1) - ((unsigned __int64)v13 >> 32)];
                            }
                            else
                            {
                                v19 = _4690A8_unit_sounds_volume;
                                v10 = _468A28_sound_ids[kknd_rand() % 3];
                            }
                        }
                        else
                        {
                            v19 = _4690A8_unit_sounds_volume;
                            v10 = _468A28_sound_ids[kknd_rand() % 3];
                        }
                        goto LABEL_53;
                    }
                    if (!v12)
                    {
                        v19 = _4690A8_unit_sounds_volume;
                        v10 = _468A38_sound_ids[kknd_rand() % 3];
                        goto LABEL_53;
                    }
                    if (!v12->_98_465610_accuracy_dmg_bonus_idx)
                    {
                        v19 = _4690A8_unit_sounds_volume;
                        v10 = _468A38_sound_ids[kknd_rand() % 3];
                        goto LABEL_53;
                    }
                    goto LABEL_46;
                }
                if (v7->_98_465610_accuracy_dmg_bonus_idx)
                {
                LABEL_46:
                    v19 = _4690A8_unit_sounds_volume;
                    v14 = kknd_rand();
                    v10 = _468A50_sound_ids[(((unsigned __int64)v14 >> 32) ^ abs(v14) & 1) - ((unsigned __int64)v14 >> 32)];
                    goto LABEL_53;
                }
                v19 = _4690A8_unit_sounds_volume;
                v15 = kknd_rand();
                v10 = _468A38_sound_ids[(((unsigned __int64)v15 >> 32) ^ abs(v15) & 1) - ((unsigned __int64)v15 >> 32)];
            }
        LABEL_53:
            sound_play(v10, 0, v19, 16, 0);
            v16 = sprite_create(MOBD_CURSORS, 0, 0);
            v16->drawjob->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_cursors;
            sprite_4272A0_load_mobd_item(v16, 508);
            v16->field_88_unused = 1;
            v17 = 10;
            v1->_70_sprite->field_88_unused = 1;
            v18 = v1->_70_sprite->x;
            v16->field_88_unused = 1;
            v16->x = v18;
            v16->y = v1->_70_sprite->y;
            v16->z_index = v1->_70_sprite->z_index - 1;
            do
            {
                cursor_process_user_actions(v1, 1);
                --v17;
            } while (v17);
            sprite_list_remove(v16);
            return;
        }
    }
}

//----- (0042B600) --------------------------------------------------------
void sub_42B600(_428940_local *a1)
{
    _428940_local *v1; // esi@1
    Sprite *v2; // ecx@2
    Script *v3; // edi@4
    Script *v4; // edi@8
    Sprite *v5; // eax@21

    v1 = a1;
    if (a1->_20_load_mobd_item_offset != 12)
    {
        v2 = a1->_70_sprite;
        v1->_20_load_mobd_item_offset = 12;
        sprite_4272A0_load_mobd_item(v2, 12);
    }
    if (_47A5E0_mouse_input.just_pressed_buttons_mask & INPUT_MOUSE_LBUTTON_MASK)
    {
        v3 = v1->_18_script;
        script_trigger_event(0, EVT_MSG_1511_sidebar_click_category, 0, v1->_18_script);
        while (!(_47A5E0_mouse_input.just_released_buttons_mask & INPUT_MOUSE_LBUTTON_MASK))
            cursor_process_user_actions(v1, 0);
        script_trigger_event(0, EVT_MSG_TEXT_STRING, 0, v3);
    }
    if (_47A5E0_mouse_input.just_pressed_buttons_mask & INPUT_MOUSE_RBUTTON_MASK)
    {
        v4 = v1->_18_script;
        while (!(_47A5E0_mouse_input.just_released_buttons_mask & INPUT_MOUSE_RBUTTON_MASK))
            cursor_process_user_actions(v1, 0);
        script_trigger_event(0, EVT_MSG_1513, 0, v4);
        if (v1->field_28)
            v1->field_28 = 0;
        if (v1->field_24)
            v1->field_24 = 0;
    }
    if (_47A734_sidebar_tooltips_task && !is_coroutine_list_initialization_failed)
    {
        if (!v1->_18_script || _47A5E0_mouse_input.cursor_dx_x256 || _47A5E0_mouse_input.cursor_dy_x256)
        {
            if (!dword_47A5A0)
                script_trigger_event(0, EVT_MSG_TEXT_STRING, 0, _47A734_sidebar_tooltips_task);
            dword_47A5A0 = 10;
        }
        else if (dword_47A5A0 > 0 && !--dword_47A5A0)
        {
            v5 = v1->_18_script->sprite;
            if (v5)
                script_trigger_event(0, EVT_MSG_1511_sidebar_click_category, v5->param, _47A734_sidebar_tooltips_task);
        }
    }
}
