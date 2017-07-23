#include "src/kknd.h"

#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"

#include "src/Cursor.h"
#include "src/Script.h"
#include "src/ScriptEvent.h"
#include "src/Random.h"
#include "src/Render.h"
#include "src/Entity.h"



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
        _429D40_unit_selection_response_sound(a1, selected_unit);
    }
    else
    {
        a1->field_3C = 0;
        unit_group_selection_response_sound(a1);
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