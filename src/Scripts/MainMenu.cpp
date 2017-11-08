#include "src/kknd.h"

#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"

#include "src/stru29.h"
#include "src/Script.h"
#include "src/ScriptEvent.h"

//----- (0043C0E0) --------------------------------------------------------
void script_mobd79_evt1__main_menu_new_game(Script *a1)
{
    Sprite *v1; // esi@1
    Sprite *v2; // eax@1
    Sprite *v3; // edi@3
    Sprite *v4; // esi@3
    DataMapd *v8; // eax@13

    _47C65C_render_string = 0;
    a1->sprite->y = 240 * 256;
    a1->sprite->z_index = 4;
    sprite_create_scripted(MOBD_79, a1->sprite, script_mobd79_evt1__main_menu_play_mission, SCRIPT_COROUTINE, 0);
    sprite_create_scripted(MOBD_79, a1->sprite, script_mobd79_evt1__main_menu_new_missions, SCRIPT_COROUTINE, 0);
    sprite_create_scripted(MOBD_79, a1->sprite, script_mobd79_evt1__main_menu_kaos_mode, SCRIPT_COROUTINE, 0);
    script_445370_yield_to_main_thread(a1, 0x80000000, 1);
    v1 = a1->sprite;
    v2 = sprite_create(MOBD_79, 0, v1);
    v1->parent = v2;
    v2->parent = 0;
    v2->z_index = v1->z_index - 1;
    a1->script_type = SCRIPT_TYPE_1;
    v1->_80_entity__stru29__sprite__initial_hitpoints = stru29_list_4439F0(v1, 0, 0, 1, 1);
    while (!script_443380(a1, 464, 0))
    {
        v3 = a1->sprite;
        v4 = v3->parent;
        v3->drawjob->flags |= 0x40000000u;
        v4->drawjob->flags |= 0x40000000u;
        v4->pstru7 = &_479D48_stru7;
        stru29_list_set_bit_by_sprite(v3, 1);
        script_443380(a1, 464, 0);
        v3->drawjob->flags &= 0xBFFFFFFF;
        v4->drawjob->flags &= 0xBFFFFFFF;
        v4->pstru7 = _4640E0_stru7_array;
    }
    netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
    netz_47C6C0_mapd_idx = 2;
    script_408500_anim(a1);
    stru29_list_realloc(a1);
    bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    script_445370_yield_to_main_thread(a1, 0x80000000, 3);
    v8 = LVL_FindMapd();
    _40E400_set_palette(&v8[2].items->palette);
    _47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)2, 0, -10);
    cplc_select(2);
    cplc_406320();
    script_445370_yield_to_main_thread(a1, 0x80000000, 1);
    script_4084A0_animation(a1);
    script_yield(a1);
}

//----- (0043C310) --------------------------------------------------------
void script_mobd79_evt19__main_menu_load(Script *a1)
{
    Sprite *v1; // esi@1
    Sprite *v2; // eax@1
    Sprite *v3; // ebx@3
    Sprite *v4; // esi@3

    _47C6D8_use__466098_cost_multipliers = 0;
    single_player_game = 1;
    a1->sprite->y = 270 * 256;
    a1->sprite->z_index = 6;
    script_445370_yield_to_main_thread(a1, 0x80000000, 1);
    v1 = a1->sprite;
    v2 = sprite_create(MOBD_79, 0, v1);
    v1->parent = v2;
    v2->parent = 0;
    v2->z_index = v1->z_index - 1;
    a1->script_type = SCRIPT_TYPE_19;
    v1->_80_entity__stru29__sprite__initial_hitpoints = stru29_list_4439F0(v1, 0, 0, 1, 1);
    while (1)
    {
        while (!script_443380(a1, 448, 0))
            ;
        script_trigger_event_group(a1, EVT_MSG_1546_repair_at_station, 0, SCRIPT_TYPE_1);
        script_432510_ingame_menu_create_sprites(a1);
        v3 = a1->sprite;
        v4 = v3->parent;
        v3->drawjob->flags |= 0x40000000u;
        v4->drawjob->flags |= 0x40000000u;
        v4->pstru7 = &_479D48_stru7;
        stru29_list_set_bit_by_sprite(v3, 1);
        script_443380(a1, 464, 0);
        v3->drawjob->flags &= 0xBFFFFFFF;
        v4->drawjob->flags &= 0xBFFFFFFF;
        v4->pstru7 = _4640E0_stru7_array;
    }
}

//----- (0043C430) --------------------------------------------------------
void script_mobd79_evt1__main_menu_play_mission(Script *a1)
{
    Sprite *v1; // esi@1
    Sprite *v2; // eax@1
    Sprite *v3; // edi@3
    Sprite *v4; // esi@3
    DataMapd *v8; // eax@13

    a1->sprite->y = 300 * 256;
    a1->sprite->z_index = 8;
    script_445370_yield_to_main_thread(a1, 0x80000000, 1);
    v1 = a1->sprite;
    v2 = sprite_create(MOBD_79, 0, v1);
    v1->parent = v2;
    v2->parent = 0;
    v2->z_index = v1->z_index - 1;
    a1->script_type = SCRIPT_TYPE_1;
    v1->_80_entity__stru29__sprite__initial_hitpoints = stru29_list_4439F0(v1, 0, 0, 1, 1);
    while (!script_443380(a1, 416, 0))
    {
        v3 = a1->sprite;
        v4 = v3->parent;
        v3->drawjob->flags |= 0x40000000u;
        v4->drawjob->flags |= 0x40000000u;
        v4->pstru7 = &_479D48_stru7;
        stru29_list_set_bit_by_sprite(v3, 1);
        script_443380(a1, 464, 0);
        v3->drawjob->flags &= 0xBFFFFFFF;
        v4->drawjob->flags &= 0xBFFFFFFF;
        v4->pstru7 = _4640E0_stru7_array;
    }
    _4240E0_kknd_sve_read(pKknd_sve);
    netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
    netz_47C6C0_mapd_idx = 11;
    script_408500_anim(a1);
    stru29_list_realloc(a1);
    bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    script_445370_yield_to_main_thread(a1, 0x80000000, 3);
    v8 = LVL_FindMapd();
    _40E400_set_palette(&v8[11].items->palette);
    _47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)11, 0, -10);
    cplc_select(11);
    cplc_406320();
    script_445370_yield_to_main_thread(a1, 0x80000000, 1);
    script_4084A0_animation(a1);
    script_yield(a1);
}

//----- (0043CA10) --------------------------------------------------------
void script_mobd79_evt1__main_menu_multiplayer(Script *a1)
{
    Sprite *v1; // esi@1
    Sprite *v2; // eax@1
    Sprite *v3; // edi@3
    Sprite *v4; // esi@3
    DataMapd *v8; // eax@13

    script_445370_yield_to_main_thread(a1, 0x80000000, 1);
    a1->sprite->y = 330 * 256;
    a1->sprite->z_index = 10;
    v1 = a1->sprite;
    v2 = sprite_create(MOBD_79, 0, v1);
    v1->parent = v2;
    v2->parent = 0;
    v2->z_index = v1->z_index - 1;
    a1->script_type = SCRIPT_TYPE_1;
    v1->_80_entity__stru29__sprite__initial_hitpoints = stru29_list_4439F0(v1, 0, 1, 1, 0);
    while (!script_443380(a1, 432, 0))
    {
        v3 = a1->sprite;
        v4 = v3->parent;
        v3->drawjob->flags |= 0x40000000u;
        v4->drawjob->flags |= 0x40000000u;
        v4->pstru7 = &_479D48_stru7;
        stru29_list_set_bit_by_sprite(v3, 1);
        script_443380(a1, 464, 0);
        v3->drawjob->flags &= 0xBFFFFFFF;
        v4->drawjob->flags &= 0xBFFFFFFF;
        v4->pstru7 = _4640E0_stru7_array;
    }
    netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
    netz_47C6C0_mapd_idx = 1;
    script_408500_anim(a1);
    stru29_list_realloc(a1);
    bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    script_445370_yield_to_main_thread(a1, 0x80000000, 3);
    v8 = LVL_FindMapd();
    _40E400_set_palette(&v8[1].items->palette);
    _47A010_mapd_item_being_drawn[0] = MAPD_Draw(MAPD_FOG_OF_WAR, 0, -10);
    cplc_select(1);
    cplc_406320();
    script_445370_yield_to_main_thread(a1, 0x80000000, 1);
    script_4084A0_animation(a1);
    script_yield(a1);
}

//----- (0043C630) --------------------------------------------------------
void script_mobd79_evt1__main_menu_new_missions(Script *a1)
{
    Sprite *v1; // esi@1
    Sprite *v2; // eax@1
    Sprite *v3; // edi@3
    Sprite *v4; // esi@3
    DataMapd *v8; // eax@13

    a1->sprite->y = 360 * 256;
    a1->sprite->z_index = 11;
    script_445370_yield_to_main_thread(a1, 0x80000000, 1);
    v1 = a1->sprite;
    v2 = sprite_create(MOBD_79, 0, v1);
    v1->parent = v2;
    v2->parent = 0;
    v2->z_index = v1->z_index - 1;
    a1->script_type = SCRIPT_TYPE_1;
    v1->_80_entity__stru29__sprite__initial_hitpoints = stru29_list_4439F0(v1, 0, 0, 1, 1);
    while (!script_443380(a1, 388, 0))
    {
        v3 = a1->sprite;
        v4 = v3->parent;
        v3->drawjob->flags |= 0x40000000u;
        v4->drawjob->flags |= 0x40000000u;
        v4->pstru7 = &_479D48_stru7;
        stru29_list_set_bit_by_sprite(v3, 1);
        script_443380(a1, 464, 0);
        v3->drawjob->flags &= 0xBFFFFFFF;
        v4->drawjob->flags &= 0xBFFFFFFF;
        v4->pstru7 = _4640E0_stru7_array;
    }
    netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
    netz_47C6C0_mapd_idx = 14;
    script_408500_anim(a1);
    stru29_list_realloc(a1);
    bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    script_445370_yield_to_main_thread(a1, 0x80000000, 3);
    v8 = LVL_FindMapd();
    _40E400_set_palette(&v8[14].items->palette);
    _47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)14, 0, -10);
    cplc_select(14);
    cplc_406320();
    script_445370_yield_to_main_thread(a1, 0x80000000, 1);
    script_4084A0_animation(a1);
    script_yield(a1);
}

//----- (0043C820) --------------------------------------------------------
void script_mobd79_evt1__main_menu_kaos_mode(Script *a1)
{
    Sprite *v1; // esi@1
    Sprite *v2; // eax@1
    Sprite *v3; // edi@3
    Sprite *v4; // esi@3
    DataMapd *v8; // eax@13

    a1->sprite->y = 390 * 256;
    a1->sprite->z_index = 12;
    script_445370_yield_to_main_thread(a1, 0x80000000, 1);
    v1 = a1->sprite;
    v2 = sprite_create(MOBD_79, 0, v1);
    v1->parent = v2;
    v2->parent = 0;
    v2->z_index = v1->z_index - 1;
    a1->script_type = SCRIPT_TYPE_1;
    v1->_80_entity__stru29__sprite__initial_hitpoints = stru29_list_4439F0(v1, 0, 0, 1, 1);
    while (!script_443380(a1, 372, 0))
    {
        v3 = a1->sprite;
        v4 = v3->parent;
        v3->drawjob->flags |= 0x40000000u;
        v4->drawjob->flags |= 0x40000000u;
        v4->pstru7 = &_479D48_stru7;
        stru29_list_set_bit_by_sprite(v3, 1);
        script_443380(a1, 464, 0);
        v3->drawjob->flags &= 0xBFFFFFFF;
        v4->drawjob->flags &= 0xBFFFFFFF;
        v4->pstru7 = _4640E0_stru7_array;
    }
    netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
    netz_47C6C0_mapd_idx = 15;
    script_408500_anim(a1);
    stru29_list_realloc(a1);
    bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    script_445370_yield_to_main_thread(a1, 0x80000000, 3);
    v8 = LVL_FindMapd();
    _40E400_set_palette(&v8[15].items->palette);
    _47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)15, 0, -10);
    cplc_select(15);
    cplc_406320();
    script_445370_yield_to_main_thread(a1, 0x80000000, 1);
    script_4084A0_animation(a1);
    script_yield(a1);
}

//----- (0043CC00) --------------------------------------------------------
void script_mobd79_evt1__main_menu_quit(Script *a1)
{
    Sprite *v1; // esi@1
    Sprite *v2; // eax@1
    Sprite *v3; // edi@3
    Sprite *v4; // esi@3

    script_445370_yield_to_main_thread(a1, 0x80000000, 1);
    a1->sprite->y = 420 * 256;
    a1->sprite->z_index = 13;
    v1 = a1->sprite;
    v2 = sprite_create(MOBD_79, 0, v1);
    v1->parent = v2;
    v2->parent = 0;
    v2->z_index = v1->z_index - 1;
    a1->script_type = SCRIPT_TYPE_1;
    v1->_80_entity__stru29__sprite__initial_hitpoints = stru29_list_4439F0(v1, 0, 0, 1, 0);
    while (!script_443380(a1, 404, 0))
    {
        v3 = a1->sprite;
        v4 = v3->parent;
        v3->drawjob->flags |= 0x40000000u;
        v4->drawjob->flags |= 0x40000000u;
        v4->pstru7 = &_479D48_stru7;
        stru29_list_set_bit_by_sprite(v3, 1);
        script_443380(a1, 464, 0);
        v3->drawjob->flags &= 0xBFFFFFFF;
        v4->drawjob->flags &= 0xBFFFFFFF;
        v4->pstru7 = _4640E0_stru7_array;
    }
    script_408500_anim(a1);
    stru29_list_remove_all(a1);
    game_state = 3;
}


//----- (0043BBA0) --------------------------------------------------------
void script_mobd79__main_menu_mouse_handler(Script *a1)
{
    Script *v1; // esi@1
    Sprite *v2; // edi@1
    DataMapd *v5; // eax@6
    DataMapd *v6; // eax@12
    int v7; // ecx@15
    int v8; // edx@15
    __int16 v9; // bx@15
    stru29 *v10; // eax@23
    Sprite *v11; // ecx@30
    stru29 *v12; // eax@31
    ScriptEvent *i; // edi@57
    int v14; // [sp+10h] [bp-38h]@1
    KeyboardInput out; // [sp+14h] [bp-34h]@15
    MouseInput v16; // [sp+28h] [bp-20h]@15
    Sprite *v17; // [sp+4Ch] [bp+4h]@1

    v1 = a1;
    _47C6E0_task = a1;
    v2 = a1->sprite;
    v14 = 18000;
    v17 = v2;
    sprite_load_mobd(v2, 312);
    v2->drawjob->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_4483E0_sidebar;
    v2->z_index = 2560;
    dword_47C6F0 = 0;
    dword_47C6EC = 1;
    if (dword_47A184)
    {
        dword_47A184 = 0;
        script_445370_yield_to_main_thread(v1, 0x80000000, 10);
        netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
        netz_47C6C0_mapd_idx = 12;
        script_408500_anim(v1);
        stru29_list_realloc(a1);
        bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
        script_445370_yield_to_main_thread(v1, 0x80000000, 3);
        v5 = LVL_FindMapd();
        _40E400_set_palette(&v5[12].items->palette);
        _47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)12, 0, -10);
        cplc_select(12);
        cplc_406320();
        script_445370_yield_to_main_thread(v1, 0x80000000, 1);
        script_4084A0_animation(v1);
        if (netz_47C6BC_mapd_idx)
            script_yield(v1);
    }
    while (1)
    {
        sub_443F20();
        if (!netz_47C6C0_mapd_idx && !_47C65C_render_string && --v14 < 0)
        {
            v14 = 18000;
            netz_47C6BC_mapd_idx = 0;
            netz_47C6C0_mapd_idx = 12;
            script_408500_anim(v1);
            stru29_list_remove_all(v1);
            stru29_list_alloc();
            bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
            script_445370_yield_to_main_thread(v1, 0x80000000, 3);
            v6 = LVL_FindMapd();
            _40E400_set_palette(&v6[12].items->palette);
            _47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)12, 0, -10);
            cplc_select(12);
            cplc_406320();
            script_445370_yield_to_main_thread(v1, 0x80000000, 1);
            script_4084A0_animation(v1);
            if (netz_47C6BC_mapd_idx)
                script_yield(v1);
        }
        if (!dword_47C6C4)
        {
            input_get_mouse_state(&v16);
            v2->field_88_unused = 1;
            v7 = v16.cursor_x_x256;
            v8 = _47C380_mapd.mapd_cplc_render_x;
            v2->field_88_unused = 1;
            v2->x = v8 + v7;
            v2->y = _47C380_mapd.mapd_cplc_render_y + v16.cursor_y_x256;
            input_get_keyboard_state(&out);
            v9 = out.just_pressed_keys_mask;
            if (!dword_4778A0)
            {
                if (out.just_pressed_keys_mask)
                {
                    if (out.just_pressed_keys_mask & INPUT_KEYBOARD_ESCAPE_MASK)
                    {
                        if (netz_47C6C0_mapd_idx)
                        {
                            script_trigger_event_group(v1, EVT_MSG_1526_infiltrate, 0, SCRIPT_TYPE_17);
                        }
                        else if (_47C65C_render_string)
                        {
                            script_4325B0_ingame_menu_trigger_events(v1);
                        }
                        else
                        {
                            script_408500_anim(v1);
                            stru29_list_remove_all(v1);
                            game_state = 3;
                            sprite_list_remove(v1->sprite);
                            script_yield(v1);
                        }
                    }
                    v10 = stru29_list_first();
                    if (v9 & INPUT_KEYBOARD_RETURN_MASK && v10 != stru29_list_end())
                    {
                        script_trigger_event(0, EVT_MSG_1511_sidebar_click_category, 0, _47C6D4_stru29->sprite->script);
                        script_trigger_event(0, EVT_SHOW_UI_CONTROL, 0, _47C6D4_stru29->sprite->script);
                        v10 = stru29_list_first();
                    }
                    if (v9 & (INPUT_KEYBOARD_TAB_MASK | INPUT_KEYBOARD_ARROW_KEYS_MASK))
                        break;
                }
            }
        }
    LABEL_56:
        if (script_445370_yield_to_main_thread(v1, 0xC0000000, 1) & 0x40000000)
        {
            for (i = script_get_next_event(v1); i; i = script_get_next_event(v1))
            {
                if (i->event == EVT_MOUSE_HOVER)
                {
                    if (v16.just_pressed_buttons_mask & INPUT_MOUSE_LBUTTON_MASK && i->param && !dword_4778A0)
                        script_trigger_event(v1, EVT_MSG_1511_sidebar_click_category, 0, (Script *)i->param);
                    if (v16.just_released_buttons_mask & INPUT_MOUSE_LBUTTON_MASK && i->param && !dword_4778A0)
                        script_trigger_event(v1, EVT_SHOW_UI_CONTROL, 0, (Script *)i->param);
                }
                script_discard_event(i);
            }
            v2 = v17;
        }
    }
    if (v9 & INPUT_KEYBOARD_TAB_MASK)
    {
        if (BYTE1(out.pressed_keys_mask) & 0xC)
        {
            if (v10 == stru29_list_end())
            {
                v11 = 0;
                goto LABEL_54;
            }
            v12 = _47C6D4_stru29;
            do
            {
                do
                {
                    v12 = v12->prev;
                    _47C6D4_stru29 = v12;
                } while (v12 == stru29_list_end());
            } while (v12->field_C & 1);
        }
        else
        {
            if (v10 == stru29_list_end())
            {
                v11 = 0;
                goto LABEL_54;
            }
            v12 = _47C6D4_stru29;
            do
            {
                do
                {
                    v12 = v12->next;
                    _47C6D4_stru29 = v12;
                } while (v12 == stru29_list_end());
            } while (v12->field_C & 1);
        }
    }
    else if (v9 & 5)
    {
        if (v10 == stru29_list_end())
        {
            v11 = 0;
            goto LABEL_54;
        }
        v12 = _47C6D4_stru29;
        do
        {
            do
            {
                v12 = v12->prev;
                _47C6D4_stru29 = v12;
            } while (v12 == stru29_list_end());
        } while (v12->field_C & 1);
    }
    else
    {
        if (v10 == stru29_list_end())
        {
            v11 = 0;
            goto LABEL_54;
        }
        v12 = _47C6D4_stru29;
        do
        {
            do
            {
                v12 = v12->next;
                _47C6D4_stru29 = v12;
            } while (v12 == stru29_list_end());
        } while (v12->field_C & 1);
    }
    v11 = v12->sprite;
LABEL_54:
    if (v11)
        _43BAB0_move_cursor(v11);
    goto LABEL_56;
}
