#include <time.h>

#include "src/Application/Scripts/MainMenu.h"

#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"
#include "src/kknd.h"
#include "src/stru29.h"
#include "src/Random.h"
#include "src/Render.h"
#include "src/RenderDrawHandlers.h"
#include "src/Script.h"
#include "src/ScriptEvent.h"
#include "src/Sprite.h"

#include "src/Infrastructure/PlatformSpecific/OsTools.h"


#define MOBD_45_NEW_CAMPAIGN_FACTION_LOGO   1380
#define MOBD_45_NEW_CAMPAIGN_CANCEL         2044

#define MOBD_79_PLAY_MISSION    416
#define MOBD_79_LOAD            448
#define MOBD_79_BUTTON_PRESSED  464



//----- (0043C0E0) --------------------------------------------------------
void script_main_menu_new_campaign(Script *a1)
{
    Sprite *v1; // esi@1
    Sprite *v2; // eax@1
    Sprite *v3; // edi@3
    Sprite *v4; // esi@3
    DataMapd *v8; // eax@13

    _47C65C_render_string = 0;
    a1->sprite->y = 240 * 256;
    a1->sprite->z_index = 4;
    sprite_create_scripted(MOBD_79, a1->sprite, script_main_menu_play_mission, SCRIPT_COROUTINE, 0);
    sprite_create_scripted(MOBD_79, a1->sprite, script_main_menu_new_missions, SCRIPT_COROUTINE, 0);
    sprite_create_scripted(MOBD_79, a1->sprite, script_main_menu_kaos_mode, SCRIPT_COROUTINE, 0);
    script_sleep(a1, 1);
    v1 = a1->sprite;
    v2 = sprite_create(MOBD_79, 0, v1);
    v1->parent = v2;
    v2->parent = 0;
    v2->z_index = v1->z_index - 1;
    a1->script_type = SCRIPT_TYPE_1;
    v1->_80_entity__stru29__sprite__initial_hitpoints = stru29_list_4439F0(v1, 0, 0, 1, 1);
    while (!script_443380(a1, MOBD_79_BUTTON_PRESSED, 0))
    {
        v3 = a1->sprite;
        v4 = v3->parent;
        v3->drawjob->flags |= 0x40000000u;
        v4->drawjob->flags |= 0x40000000u;
        v4->pstru7 = &_479D48_stru7;
        stru29_list_set_bit_by_sprite(v3, 1);
        script_443380(a1, MOBD_79_BUTTON_PRESSED, 0);
        v3->drawjob->flags &= 0xBFFFFFFF;
        v4->drawjob->flags &= 0xBFFFFFFF;
        v4->pstru7 = _4640E0_stru7_array;
    }
    netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
    netz_47C6C0_mapd_idx = 2;
    script_408500_anim(a1);
    stru29_list_realloc(a1);
    bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    script_sleep(a1, 3);
    v8 = LVL_FindMapd();
    _40E400_set_palette(v8[2].items->GetPalette());
    _47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)2, 0, -10);
    cplc_select(2);
    cplc_406320();
    script_sleep(a1, 1);
    script_4084A0_animation(a1);
    script_terminate(a1);
}

//----- (0043C310) --------------------------------------------------------
void script_main_menu_load(Script *a1)
{
    Sprite *v1; // esi@1
    Sprite *v2; // eax@1
    Sprite *v3; // ebx@3
    Sprite *v4; // esi@3

    is_demo_build = 0;
    single_player_game = 1;
    a1->sprite->y = 270 * 256;
    a1->sprite->z_index = 6;
    script_sleep(a1, 1);
    v1 = a1->sprite;
    v2 = sprite_create(MOBD_79, 0, v1);
    v1->parent = v2;
    v2->parent = 0;
    v2->z_index = v1->z_index - 1;
    a1->script_type = SCRIPT_TYPE_19;
    v1->_80_entity__stru29__sprite__initial_hitpoints = stru29_list_4439F0(v1, 0, 0, 1, 1);
    while (1)
    {
        while (!script_443380(a1, MOBD_79_LOAD, 0))
            ;
        script_trigger_event_group(a1, EVT_MSG_1546_repair_at_station, 0, SCRIPT_TYPE_1);
        script_main_menu_create_load_dialog(a1);
        v3 = a1->sprite;
        v4 = v3->parent;
        v3->drawjob->flags |= 0x40000000u;
        v4->drawjob->flags |= 0x40000000u;
        v4->pstru7 = &_479D48_stru7;
        stru29_list_set_bit_by_sprite(v3, 1);
        script_443380(a1, MOBD_79_BUTTON_PRESSED, 0);
        v3->drawjob->flags &= 0xBFFFFFFF;
        v4->drawjob->flags &= 0xBFFFFFFF;
        v4->pstru7 = _4640E0_stru7_array;
    }
}

//----- (00432510) --------------------------------------------------------
void script_main_menu_create_load_dialog(Script *a1)
{
    sprite_create_scripted(MOBD_FONT_ITALIC, a1->sprite, script_432F00_ingame_menu, SCRIPT_COROUTINE, 0);
    sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, a1->sprite, script_434390_ingame_menu, SCRIPT_COROUTINE, 0);
    sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, a1->sprite, script_434220_ingame_menu, SCRIPT_COROUTINE, 0);
    sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, a1->sprite, script_434310_ingame_menu, SCRIPT_COROUTINE, 0);
    sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, a1->sprite, script_4342A0_ingame_menu, SCRIPT_COROUTINE, 0);
    sprite_create_scripted(MOBD_45, a1->sprite, script_434460_DA000007, SCRIPT_COROUTINE, 0);
    _47C6F8_main_menu_load_initialized = 1;
}

//----- (0043C430) --------------------------------------------------------
void script_main_menu_play_mission(Script *a1)
{
    Sprite *v1; // esi@1
    Sprite *v2; // eax@1
    Sprite *v3; // edi@3
    Sprite *v4; // esi@3
    DataMapd *v8; // eax@13

    a1->sprite->y = 300 * 256;
    a1->sprite->z_index = 8;
    script_sleep(a1, 1);
    v1 = a1->sprite;
    v2 = sprite_create(MOBD_79, 0, v1);
    v1->parent = v2;
    v2->parent = 0;
    v2->z_index = v1->z_index - 1;
    a1->script_type = SCRIPT_TYPE_1;
    v1->_80_entity__stru29__sprite__initial_hitpoints = stru29_list_4439F0(v1, 0, 0, 1, 1);
    while (!script_443380(a1, MOBD_79_PLAY_MISSION, 0))
    {
        v3 = a1->sprite;
        v4 = v3->parent;
        v3->drawjob->flags |= 0x40000000u;
        v4->drawjob->flags |= 0x40000000u;
        v4->pstru7 = &_479D48_stru7;
        stru29_list_set_bit_by_sprite(v3, 1);
        script_443380(a1, MOBD_79_BUTTON_PRESSED, 0);
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
    script_sleep(a1, 3);
    v8 = LVL_FindMapd();
    _40E400_set_palette(v8[11].items->GetPalette());
    _47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)11, 0, -10);
    cplc_select(11);
    cplc_406320();
    script_sleep(a1, 1);
    script_4084A0_animation(a1);
    script_terminate(a1);
}

//----- (0043CA10) --------------------------------------------------------
void script_main_menu_multiplayer(Script *a1)
{
    Sprite *v1; // esi@1
    Sprite *v2; // eax@1
    Sprite *v3; // edi@3
    Sprite *v4; // esi@3
    DataMapd *v8; // eax@13

    script_sleep(a1, 1);
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
    script_sleep(a1, 3);
    v8 = LVL_FindMapd();
    _40E400_set_palette(v8[1].items->GetPalette());
    _47A010_mapd_item_being_drawn[0] = MAPD_Draw(MAPD_FOG_OF_WAR, 0, -10);
    cplc_select(1);
    cplc_406320();
    script_sleep(a1, 1);
    script_4084A0_animation(a1);
    script_terminate(a1);
}

//----- (0043C630) --------------------------------------------------------
void script_main_menu_new_missions(Script *a1)
{
    Sprite *v1; // esi@1
    Sprite *v2; // eax@1
    Sprite *v3; // edi@3
    Sprite *v4; // esi@3
    DataMapd *v8; // eax@13

    a1->sprite->y = 360 * 256;
    a1->sprite->z_index = 11;
    script_sleep(a1, 1);
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
    script_sleep(a1, 3);
    v8 = LVL_FindMapd();
    _40E400_set_palette(v8[14].items->GetPalette());
    _47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)14, 0, -10);
    cplc_select(14);
    cplc_406320();
    script_sleep(a1, 1);
    script_4084A0_animation(a1);
    script_terminate(a1);
}

//----- (0043C820) --------------------------------------------------------
void script_main_menu_kaos_mode(Script *a1)
{
    Sprite *v1; // esi@1
    Sprite *v2; // eax@1
    Sprite *v3; // edi@3
    Sprite *v4; // esi@3
    DataMapd *v8; // eax@13

    a1->sprite->y = 390 * 256;
    a1->sprite->z_index = 12;
    script_sleep(a1, 1);
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
    script_sleep(a1, 3);
    v8 = LVL_FindMapd();
    _40E400_set_palette(v8[15].items->GetPalette());
    _47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)15, 0, -10);
    cplc_select(15);
    cplc_406320();
    script_sleep(a1, 1);
    script_4084A0_animation(a1);
    script_terminate(a1);
}

//----- (0043CC00) --------------------------------------------------------
void script_main_menu_quit(Script *a1)
{
    Sprite *v1; // esi@1
    Sprite *v2; // eax@1
    Sprite *v3; // edi@3
    Sprite *v4; // esi@3

    script_sleep(a1, 1);
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
    game_state = GAME_STATE::GAME_3_quit_mission;
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
    v2->drawjob->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_4483E0_ui;
    v2->z_index = 2560;
    dword_47C6F0 = 0;
    dword_47C6EC = 1;
    if (dword_47A184)
    {
        dword_47A184 = 0;
        script_sleep(v1, 10);
        netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
        netz_47C6C0_mapd_idx = 12;
        script_408500_anim(v1);
        stru29_list_realloc(a1);
        bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
        script_sleep(v1, 3);
        v5 = LVL_FindMapd();
        _40E400_set_palette(v5[12].items->GetPalette());
        _47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)12, 0, -10);
        cplc_select(12);
        cplc_406320();
        script_sleep(v1, 1);
        script_4084A0_animation(v1);
        if (netz_47C6BC_mapd_idx)
            script_terminate(v1);
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
            script_sleep(v1, 3);
            v6 = LVL_FindMapd();
            _40E400_set_palette(v6[12].items->GetPalette());
            _47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)12, 0, -10);
            cplc_select(12);
            cplc_406320();
            script_sleep(v1, 1);
            script_4084A0_animation(v1);
            if (netz_47C6BC_mapd_idx)
                script_terminate(v1);
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
                            game_state = GAME_STATE::GAME_3_quit_mission;
                            sprite_list_remove(v1->sprite);
                            script_terminate(v1);
                        }
                    }
                    v10 = stru29_list_first();
                    if (v9 & INPUT_KEYBOARD_RETURN_MASK && v10 != stru29_list_end())
                    {
                        script_trigger_event(0, EVT_MSG_SELECTED, 0, _47C6D4_stru29->sprite->script);
                        script_trigger_event(0, EVT_MSG_DESELECTED, 0, _47C6D4_stru29->sprite->script);
                        v10 = stru29_list_first();
                    }
                    if (v9 & (INPUT_KEYBOARD_TAB_MASK | INPUT_KEYBOARD_ARROW_KEYS_MASK))
                        break;
                }
            }
        }
    LABEL_56:
        if (script_yield_any_trigger(v1, 1) & SCRIPT_FLAGS_20_EVENT_TRIGGER)
        {
            for (i = script_get_next_event(v1); i; i = script_get_next_event(v1))
            {
                if (i->event == EVT_MOUSE_HOVER)
                {
                    if (mouse_lbutton_just_pressed() && i->param && !dword_4778A0)
                        script_trigger_event(v1, EVT_MSG_SELECTED, 0, (Script *)i->param);
                    if (mouse_lbutton_just_released() && i->param && !dword_4778A0)
                        script_trigger_event(v1, EVT_MSG_DESELECTED, 0, (Script *)i->param);
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



//----- (0043CD20) --------------------------------------------------------
void script_main_menu_new_campaign_surv(Script *a1)
{
    Sprite *v1; // eax@1
    Sprite *v2; // esi@1
    int v3; // ebx@1
    ScriptEvent *i; // eax@2
    enum SCRIPT_EVENT v5; // edx@3

    v1 = a1->sprite;
    v1->x = 48640;
    v1->y = 43008;
    v2 = a1->sprite;
    v2->parent = 0;
    a1->script_type = SCRIPT_TYPE_15;
    stru29_list_4439F0(v2, 0, 0, 0, 0);
    sprite_load_mobd(v2, MOBD_45_NEW_CAMPAIGN_FACTION_LOGO);
    v3 = 0;
    do
    {
        script_wait_event(a1);
        for (i = script_get_next_event(a1); i; i = script_get_next_event(a1))
        {
            v5 = i->event;
            switch (v5)
            {
            case EVT_MOUSE_HOVER:
                stru29_list_443AE0_find_by_sprite(a1->sprite);
                break;
            case EVT_MSG_SELECTED:
                v3 = 1;
                break;
            case EVT_MSG_1528_cancel:
                v3 = 1;
                break;
            }
            script_discard_event(i);
        }
    } while (!v3);
    player_side = SURVIVORS;
    current_level_idx = LEVEL_SURV_01_THE_NEXT_GENERATION;
    script_408500_anim(a1);
    is_demo_build = 0;
    single_player_game = 1;
    netz_42E7F0();
    stru29_list_remove_all(a1);
    game_state = GAME_STATE::Mission;
    script_deinit(_47C6E0_task);
    _47C6E0_task = 0;
}

//----- (0043CE30) --------------------------------------------------------
void script_main_menu_new_campaign_mute(Script *a1)
{
    Sprite *v1; // eax@1
    Sprite *v2; // esi@1
    int v3; // ebx@1
    ScriptEvent *i; // eax@2
    enum SCRIPT_EVENT v5; // edx@3

    v1 = a1->sprite;
    v1->x = 0x1AC00;
    v1->y = 0xA800;
    v2 = a1->sprite;
    v2->parent = 0;
    a1->script_type = SCRIPT_TYPE_15;
    stru29_list_4439F0(v2, 0, 0, 0, 0);
    sprite_load_mobd(v2, MOBD_45_NEW_CAMPAIGN_FACTION_LOGO);
    v3 = 0;
    do
    {
        script_wait_event(a1);
        for (i = script_get_next_event(a1); i; i = script_get_next_event(a1))
        {
            v5 = i->event;
            switch (v5)
            {
            case EVT_MOUSE_HOVER:
                stru29_list_443AE0_find_by_sprite(a1->sprite);
                break;
            case EVT_MSG_SELECTED:
                v3 = 1;
                break;
            case EVT_MSG_1528_cancel:
                v3 = 1;
                break;
            }
            script_discard_event(i);
        }
    } while (!v3);
    player_side = EVOLVED;
    current_level_idx = LEVEL_MUTE_01;
    script_408500_anim(a1);
    is_demo_build = 0;
    single_player_game = 1;
    netz_42E7F0();
    stru29_list_remove_all(a1);
    game_state = GAME_STATE::Mission;
    script_deinit(_47C6E0_task);
    _47C6E0_task = 0;
}

//----- (0043CF50) --------------------------------------------------------
void script_main_menu_new_campaign_cancel(Script *a1)
{
    Sprite *v1; // edi@1
    Sprite *v2; // eax@1
    DataMapd *v5; // eax@7

    v1 = a1->sprite;
    v2 = sprite_create(MOBD_45, 0, a1->sprite);
    v1->mobd_id = MOBD_45;
    v1->parent = v2;
    v2->parent = 0;
    v2->z_index = 0;
    v1->z_index = 1;
    a1->script_type = SCRIPT_TYPE_17;
    stru29_list_4439F0(v1, 0, 1, 1, 0);
    while (!script_443780(a1, MOBD_45_NEW_CAMPAIGN_CANCEL, 1, 0))
        ;
    netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
    netz_47C6C0_mapd_idx = 0;
    script_408500_anim(a1);
    stru29_list_realloc(a1);
    bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    script_sleep(a1, 3);
    v5 = LVL_FindMapd();
    _40E400_set_palette(v5->items->GetPalette());
    _47A010_mapd_item_being_drawn[0] = MAPD_Draw(MAPD_MAP, 0, -10);
    cplc_select(0);
    cplc_406320();
    script_sleep(a1, 1);
    script_4084A0_animation(a1);
    script_terminate(a1);
}


//----- (00443140) --------------------------------------------------------
void script_main_menu_play_mission_ok(Script *a1)
{
    Sprite *v1; // ebx@1
    Sprite *v2; // eax@1
    Sprite *v3; // esi@4
    Sprite *v4; // eax@4
    enum LEVEL_ID v5; // eax@6

    v1 = a1->sprite;
    v2 = sprite_create(MOBD_FONT_ITALIC, 0, a1->sprite);
    _47C664_ingame_menu_sprite = v2;
    if (v2)
        sprite_load_mobd(v2, 1048);
    else
        game_state = GAME_STATE::GAME_3_quit_mission;
    v3 = a1->sprite;
    v4 = sprite_create(MOBD_45, 0, a1->sprite);
    v3->mobd_id = MOBD_45;
    v3->parent = v4;
    v4->parent = 0;
    v4->z_index = 0;
    v3->z_index = 1;
    a1->script_type = SCRIPT_TYPE_13;
    stru29_list_4439F0(v3, 0, 0, 1, 0);
    v1->parent->parent = _47C664_ingame_menu_sprite;
    while (!script_443780(a1, 1968, 1, 0))
        ;
    v5 = (LEVEL_ID)dword_47C6E8;
    if (netz_47C6C0_mapd_idx == 14)
    {
        if (dword_47C6E8 < -1 || dword_47C6E8 > 9)
            v5 = (LEVEL_ID)0;
        if (dword_47C6E4)
        {
            player_side = EVOLVED;
            v5 = (LEVEL_ID)((int)v5 + 58);
        }
        else
        {
            player_side = SURVIVORS;
            v5 = (LEVEL_ID)((int)v5 + 48);
        }
    }
    else
    {
        if (dword_47C6E8 < -1 || dword_47C6E8 > 14)
            v5 = (LEVEL_ID)0;
        if (dword_47C6E4)
        {
            player_side = EVOLVED;
            v5 = (LEVEL_ID)((int)v5 + 15);
        }
        else
        {
            player_side = SURVIVORS;
        }
    }
    current_level_idx = v5;
    dword_47C6E8 = -1;
    is_demo_build = 0;
    single_player_game = 1;
    script_deinit(_47C6E0_task);
    _47C6E0_task = 0;
    stru29_list_remove_all(a1);
    script_408500_anim(a1);
    game_state = GAME_STATE::Mission;
}


//----- (00443290) --------------------------------------------------------
void script_main_menu_play_mission_faction_toggle(Script *a1)
{
    Sprite *v1; // esi@1
    Sprite *v2; // eax@1
    int v3; // esi@2
    int v4; // eax@4

    v1 = a1->sprite;
    v2 = sprite_create(MOBD_45, 0, a1->sprite);
    v1->mobd_id = MOBD_45;
    v1->parent = v2;
    v2->parent = 0;
    v2->z_index = 0;
    v1->z_index = 1;
    a1->script_type = SCRIPT_TYPE_13;
    stru29_list_4439F0(v1, 0, 1, 1, 0);
    while (1)
    {
        v3 = dword_47C6E4 != 0 ? 2020 : 2128;
        while (!script_443780(a1, v3, 1, 0))
            ;
        v4 = 1 - dword_47C6E4;
        dword_47C6E4 = 1 - dword_47C6E4;
        if (netz_47C6C0_mapd_idx == 14)
        {
            dword_47C6E8 = 0;
            script_trigger_event_group(a1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_14);
        }
        else if (v4)
        {
            dword_47C6E8 = (unsigned __int16)current_mute_level;
            script_trigger_event_group(a1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_14);
        }
        else
        {
            dword_47C6E8 = (unsigned __int16)current_surv_level;
            script_trigger_event_group(a1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_14);
        }
    }
}



//----- (004404D0) --------------------------------------------------------
void script_main_menu_create_kaos_dialog(Script *a1)
{
    Script *v1; // edi@1
    Sprite *v2; // ebx@1
    Sprite *v3; // eax@2
    Sprite *v4; // eax@4
    Sprite *v5; // eax@6
    unsigned int v6; // eax@9
    void *v7; // eax@9
    int v8; // eax@11
    Sprite *v9; // eax@15
    Script *v10; // eax@16
    Sprite *v11; // eax@19
    Sprite *v12; // eax@21
    Script *v13; // eax@22
    Sprite *v14; // eax@24
    Sprite *v15; // eax@28
    Sprite *v16; // eax@30
    Sprite *v17; // eax@32
    Script *v18; // eax@33
    int v19; // [sp+0h] [bp-Ch]@11

    v1 = a1;
    v2 = a1->sprite;
    a1->script_type = SCRIPT_TYPE_8;
    if (netz_47C6C0_mapd_idx == 15)
    {
        v3 = sprite_create_scripted(MOBD_45, v2, script_main_menu_kaos_allies, SCRIPT_COROUTINE, 0);
        if (v3)
        {
            v3->x = 10240;
            v3->y = 62976;
        }
        v4 = sprite_create_scripted(MOBD_45, v2, script_main_menu_kaos_enemies, SCRIPT_COROUTINE, 0);
        if (v4)
        {
            v4->x = 45056;
            v4->y = 62976;
        }
        v5 = sprite_create_scripted(MOBD_45, v2, script_main_menu_kaos_difficulty, SCRIPT_COROUTINE, 0);
        if (v5)
        {
            v5->x = 83968;
            v5->y = 62976;
        }
    }
    else if (netz_47C6BC_mapd_idx != 4)
    {
        v6 = clock();
        srand(v6);
        v7 = (void *)(strlen(netz_default_player_name) + 1);
        memcpy(
            netz_47A740[(int)__47CA80_array_idx_and_netz_player_side + 2].player_name,
            netz_default_player_name,
            (unsigned int)v7);

        netz_42F8E0(1);
    }
    v9 = sprite_create_scripted(MOBD_45, v2, script_main_menu_kaos_player_name, SCRIPT_COROUTINE, 0);
    if (v9)
    {
        v10 = v9->script;
        if (v10)
            v10->script_type = v1->script_type;
    }
    else
    {
        game_state = GAME_STATE::GAME_3_quit_mission;
    }
    v11 = sprite_create_scripted(MOBD_45, v2, script_main_menu_kaos_starting_cash, SCRIPT_COROUTINE, 0);
    if (v11)
    {
        v11->x = 75264;
        v11->y = 17152;
    }
    v12 = sprite_create_scripted(MOBD_45, v2, script_main_menu_kaos_color, SCRIPT_COROUTINE, 0);
    if (v12)
    {
        v12->x = 14080;
        v12->y = 27904;
        v13 = v12->script;
        if (v13)
            v13->script_type = v1->script_type;
    }
    v14 = sprite_create_scripted(MOBD_45, v2, script_main_menu_kaos_map, SCRIPT_COROUTINE, 0);
    if (v14)
    {
        v14->x = 70656;
        v14->y = 27904;
    }
    if (netz_47C6C0_mapd_idx == 15)
    {
        BYTE1(_46E420_starting_cash_idx) = 5;
    }
    else
    {
        v15 = sprite_create_scripted(MOBD_45, v2, script_main_menu_kaos_max_tech_level, SCRIPT_COROUTINE, 0);
        if (v15)
        {
            v15->x = 97280;
            v15->y = 38400;
        }
    }
    v16 = sprite_create_scripted(MOBD_45, v2, script_main_menu_kaos_bunkers_toggle, SCRIPT_COROUTINE, 0);
    if (v16)
    {
        v16->x = 58368;
        v16->y = 38400;
    }
    v17 = sprite_create_scripted(MOBD_45, v2, script_main_menu_kaos_team, SCRIPT_COROUTINE, 0);
    if (v17)
    {
        v17->x = 0x2000;
        v17->y = 38400;
        v18 = v17->script;
        if (v18)
            v18->script_type = v1->script_type;
    }
    sprite_list_remove(v2);
    script_terminate(v1);
}


//----- (00441FC0) --------------------------------------------------------
void script_main_menu_kaos_allies(Script *a1)
{
    RenderString *v1; // ebx@2
    Sprite *v2; // edi@2
    Sprite *v3; // eax@2
    int i; // eax@2
    Sprite *v5; // esi@8
    Sprite *v6; // edx@8
    Sprite *v7; // eax@8
    Script *v8; // eax@9
    Sprite *v9; // eax@12
    Script *v10; // eax@13
    Sprite *v11; // eax@15
    Script *v12; // eax@16
    Sprite *v13; // eax@18
    Sprite *v14; // eax@20
    Sprite *v15; // eax@22
    Sprite *v16; // eax@24
    char a2[8]; // [sp+10h] [bp-8h]@5

    if (netz_47C6C0_mapd_idx == LEVEL_MUTE_01)
    {
        v1 = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 150, 252, 10, 3, 9, 14, 16);
        v2 = a1->sprite;
        v3 = sprite_create(MOBD_45, 0, a1->sprite);
        v2->mobd_id = MOBD_45;
        v2->parent = v3;
        v3->parent = 0;
        v3->z_index = 0;
        v2->z_index = 1;
        a1->script_type = SCRIPT_TYPE_8;
        stru29_list_4439F0(v2, v1, 0, 1, 0);
        for (i = dword_46E3F8; ; i = dword_46E3F8++ + 1)
        {
            if (i > 2)
            {
                i = 0;
                dword_46E3F8 = 0;
            }
            sprintf(a2, aD_2, i);
            v1->field_18 = 0;
            v1->num_lines = 0;
            render_string_443D80(v1, a2, 0);
            while (!script_443780(a1, 1668, 1, 2))
                ;
        }
    }
    v5 = a1->sprite;
    v6 = a1->sprite;
    a1->script_type = SCRIPT_TYPE_9;
    v7 = sprite_create_scripted(MOBD_45, v6, (void(*)(Script *))script_main_menu_kaos_player_name, SCRIPT_COROUTINE, 0);
    if (v7)
    {
        v8 = v7->script;
        if (v8)
            v8->script_type = a1->script_type;
    }
    else
    {
        stru29_list_remove_all(a1);
        game_state = GAME_STATE::GAME_3_quit_mission;
    }
    v9 = sprite_create_scripted(MOBD_45, v5, (void(*)(Script *))script_main_menu_kaos_color, SCRIPT_COROUTINE, 0);
    if (v9)
    {
        v9->x = 14080;
        v9->y = 27904;
        v10 = v9->script;
        if (v10)
            v10->script_type = a1->script_type;
    }
    v11 = sprite_create_scripted(MOBD_45, v5, (void(*)(Script *))script_main_menu_kaos_team, SCRIPT_COROUTINE, 0);
    if (v11)
    {
        v11->x = 0x2000;
        v11->y = 38400;
        v12 = v11->script;
        if (v12)
            v12->script_type = a1->script_type;
    }
    v13 = sprite_create_scripted(MOBD_45, v5, (void(*)(Script *))script_441550_mobd45_evt8, SCRIPT_COROUTINE, 0);
    if (v13)
    {
        v13->x = 75264;
        v13->y = 17152;
    }
    v14 = sprite_create_scripted(MOBD_45, v5, (void(*)(Script *))script_441340_mobd45_evt8, SCRIPT_COROUTINE, 0);
    if (v14)
    {
        v14->x = 58368;
        v14->y = 38400;
    }
    v15 = sprite_create_scripted(MOBD_45, v5, (void(*)(Script *))script_441150_mobd45_evt8, SCRIPT_COROUTINE, 0);
    if (v15)
    {
        v15->x = 70656;
        v15->y = 27904;
    }
    v16 = sprite_create_scripted(MOBD_45, v5, (void(*)(Script *))script_main_menu_kaos_enemies, SCRIPT_COROUTINE, 0);
    if (v16)
    {
        v16->x = 97280;
        v16->y = 38400;
    }
    sprite_list_remove(v5);
    script_terminate(a1);
}


//----- (00441780) --------------------------------------------------------
void script_main_menu_kaos_enemies(Script *a1)
{
    RenderString *v1; // ebp@2
    Sprite *v2; // esi@2
    Sprite *v3; // eax@2
    int i; // eax@2
    DataMobdItem *v5; // edx@8
    RenderString *v6; // edi@8
    Sprite *v7; // esi@8
    Sprite *v8; // eax@8
    char a2[4]; // [sp+10h] [bp-10h]@5
    char v11[8]; // [sp+18h] [bp-8h]@14

    if (netz_47C6C0_mapd_idx == LEVEL_MUTE_01)
    {
        v1 = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 284, 252, 10, 3, 9, 14, 16);
        v2 = a1->sprite;
        v3 = sprite_create(MOBD_45, 0, a1->sprite);
        v2->mobd_id = MOBD_45;
        v2->parent = v3;
        v3->parent = 0;
        v3->z_index = 0;
        v2->z_index = 1;
        a1->script_type = SCRIPT_TYPE_8;
        stru29_list_4439F0(v2, v1, 0, 1, 0);
        for (i = dword_46E3FC; ; i = dword_46E3FC++ + 1)
        {
            if (i > 3)
            {
                i = 1;
                dword_46E3FC = 1;
            }
            sprintf(a2, aD_2, i);
            v1->field_18 = 0;
            v1->num_lines = 0;
            render_string_443D80(v1, a2, 0);
            while (!script_443780(a1, 1656, 1, 2))
                ;
        }
    }
    v5 = currently_running_lvl_mobd[MOBD_FONT_ITALIC].items;
    *(_DWORD *)a2 = -1;
    v6 = render_string_create(0, v5, 500, 156, 10, 3, 9, 14, 16);
    v7 = a1->sprite;
    v8 = sprite_create(MOBD_45, 0, a1->sprite);
    v7->mobd_id = MOBD_45;
    v7->parent = v8;
    v8->parent = 0;
    v8->z_index = 0;
    v7->z_index = 1;
    a1->script_type = SCRIPT_TYPE_8;
    stru29_list_4439F0(v7, v6, 0, 1, 0);
    stru29_list_set_bit_by_sprite(a1->sprite, 1);
    while (1)
    {
        if (*(_DWORD *)a2 != SBYTE1(_46E420_starting_cash_idx))
        {
            sprintf(v11, aD_2, SBYTE1(_46E420_starting_cash_idx));
            v6->field_18 = 0;
            v6->num_lines = 0;
            render_string_443D80(v6, v11, 0);
            *(_DWORD *)a2 = SBYTE1(_46E420_starting_cash_idx);
        }
        script_443780(a1, 2112, 0, 2);
    }
}


//----- (004421F0) --------------------------------------------------------
void script_main_menu_kaos_difficulty(Script *a1)
{
    RenderString *v1; // esi@2
    Sprite *v2; // edi@2
    Sprite *v3; // eax@2
    int i; // eax@2
    Sprite *v5; // edi@6
    Sprite *v6; // eax@6
    int v7; // eax@13
    Sprite *v8; // eax@17
    int v9; // edx@17
    int v10; // ecx@17
    int v11; // ecx@20
    DataMapd *v12; // eax@20
    int v13; // ecx@20
    DataMapd *v16; // eax@25
    int v17; // [sp+0h] [bp-18h]@13
    char a2[12]; // [sp+Ch] [bp-Ch]@5

    if (netz_47C6C0_mapd_idx == 15)
    {
        v1 = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 456, 252, 10, 3, 9, 14, 16);
        v2 = a1->sprite;
        v3 = sprite_create(MOBD_45, 0, a1->sprite);
        v2->mobd_id = MOBD_45;
        v2->parent = v3;
        v3->parent = 0;
        v3->z_index = 0;
        v2->z_index = 1;
        a1->script_type = SCRIPT_TYPE_8;
        stru29_list_4439F0(v2, v1, 0, 1, 0);
        for (i = _466098_cost_multiplier_idx; ; i = _466098_cost_multiplier_idx++ + 1)
        {
            if (i >= 3)
            {
                i = 0;
                _466098_cost_multiplier_idx = 0;
            }
            sprintf(a2, aS_0, difficulties[i]);
            v1->field_18 = 0;
            v1->num_lines = 0;
            render_string_443D80(v1, a2, 0);
            script_43BA40(a1, 1680, nullsub_3, 0);
        }
    }
    v5 = a1->sprite;
    v6 = sprite_create(MOBD_45, 0, a1->sprite);
    v5->mobd_id = MOBD_45;
    v5->parent = v6;
    v6->parent = 0;
    v6->z_index = 0;
    v5->z_index = 1;
    a1->script_type = SCRIPT_TYPE_17;
    stru29_list_4439F0(v5, 0, 1, 1, 0);
    if (!script_create_coroutine(SCRIPT_TYPE_9, script_43F7C0, 0))
        game_state = GAME_STATE::GAME_3_quit_mission;
    if (!script_create_coroutine(SCRIPT_TYPE_9, script_441F10, 0))
        game_state = GAME_STATE::GAME_3_quit_mission;
    while (!script_443780(a1, 2044, 1, 0))
        ;
    netz_44A220(68, 0, 0);
    netz_42F9C0(0, 0);
    netz_42F650((void *)j_netz_430690());
    if (dword_47C6C4)
    {
        v8 = _47C6E0_task->sprite;
        v9 = v8->y >> 8;
        v10 = v8->x >> 8;
        v8->field_88_unused = 1;
        input_set_mouse_pos(v10, v9);
        dword_47C6C4 = 0;
        sprite_release_mobd_item(_47C664_ingame_menu_sprite);
    }
    if (netz_468B6C_providers_idx == 2 || netz_468B6C_providers_idx == 1)
    {
        netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
        netz_47C6C0_mapd_idx = 1;
        script_408500_anim(a1);
        stru29_list_realloc(a1);
        bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
        script_sleep(a1, 3);
        v16 = LVL_FindMapd();
        _40E400_set_palette(v16[1].items->GetPalette());
        _47A010_mapd_item_being_drawn[0] = MAPD_Draw(MAPD_FOG_OF_WAR, 0, -10);
        v13 = 1;
    }
    else
    {
        v11 = netz_47C6C0_mapd_idx;
        netz_47C6C0_mapd_idx = 4;
        netz_47C6BC_mapd_idx = v11;
        script_408500_anim(a1);
        stru29_list_remove_all(a1);
        stru29_list_alloc();
        bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
        script_sleep(a1, 3);
        v12 = LVL_FindMapd();
        _40E400_set_palette(v12[4].items->GetPalette());
        _47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)4, 0, -10);
        v13 = 4;
    }
    cplc_select(v13);
    cplc_406320();
    script_sleep(a1, 1);
    script_4084A0_animation(a1);
    script_terminate(a1);
}


//----- (00441470) --------------------------------------------------------
void script_main_menu_kaos_starting_cash(Script *a1)
{
    RenderString *v1; // ebp@3
    Sprite *v2; // esi@3
    Sprite *v3; // eax@3

    if (netz_47C6C0_mapd_idx == LEVEL_MUTE_01)
        LOBYTE_HEXRAYS(_46E420_starting_cash_idx) = 0;
    v1 = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 424, 74, 10, 3, 9, 14, 16);
    v2 = a1->sprite;
    v3 = sprite_create(MOBD_45, 0, a1->sprite);
    v2->mobd_id = MOBD_45;
    v2->parent = v3;
    v3->parent = 0;
    v3->z_index = 0;
    v2->z_index = 1;
    a1->script_type = SCRIPT_TYPE_8;
    stru29_list_4439F0(v2, v1, 0, 1, 0);
    while (1)
    {
        v1->field_18 = 0;
        v1->num_lines = 0;
        render_string_443D80(v1, _46E420_starting_cash[(char)_46E420_starting_cash_idx], 0);
        while (!script_443780(a1, 2140, 1, 0))
            ;
        LOBYTE_HEXRAYS(_46E420_starting_cash_idx) = (_46E420_starting_cash_idx + 1) & 7;
        if (netz_47C6C0_mapd_idx != 15)
            netz_44A2A0(64, (int)&_46E420_starting_cash_idx, 5);
    }
}


//----- (00440CA0) --------------------------------------------------------
void script_main_menu_kaos_color(Script *a1)
{
    RenderString *v1; // edi@4
    Sprite *v2; // esi@4
    Sprite *v3; // eax@4
    bool v4; // sf@7
    unsigned __int8 v5; // of@7
    char v6; // dl@11
    void *v7; // ecx@14
    char *v8; // eax@14
    int v9; // eax@20
    int v10; // eax@23
    int v11; // esi@24
    char v12; // cl@27
    void *v13; // eax@29

    if (netz_47C6C0_mapd_idx == LEVEL_MUTE_01)
        byte_47C654 = 0;
    else
        byte_47C654 = netz_47A740[(int)__47CA80_array_idx_and_netz_player_side + 2].field_9;
    v1 = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 164, 116, 10, 3, 9, 14, 16);
    v2 = a1->sprite;
    v3 = sprite_create(MOBD_45, 0, a1->sprite);
    v2->mobd_id = MOBD_45;
    v2->parent = v3;
    v3->parent = 0;
    v3->z_index = 0;
    v2->z_index = 1;
    a1->script_type = SCRIPT_TYPE_8;
    stru29_list_4439F0(v2, v1, 0, 1, 0);
    while (1)
    {
        while (1)
        {
            while (1)
            {
                render_string_445AE0(v1);
                v1->field_18 = 0;
                v1->num_lines = 0;
                render_string_443D80(v1, player_colors[byte_47C654], 0);
                if (netz_47C6C0_mapd_idx != 15)
                    break;
                while (!script_443780(a1, 2056, 1, 2))
                    ;
                v5 = __OFSUB__(byte_47C654 + 1, 15);
                v4 = (char)(byte_47C654++ - 14) < 0;
                if (!(v4 ^ v5))
                    byte_47C654 = 0;
            }
            if (netz_47A834)
                break;
            do
            {
                v11 = script_443570(a1, 2056, 1, 2);
                render_string_445AE0(v1);
                v1->field_18 = 0;
                v1->num_lines = 0;
                render_string_443D80(v1, player_colors[byte_47C654], 0);
            } while (!v11);
            if (v11 == 300)
            {
                byte_47C654 = netz_47A740[(int)__47CA80_array_idx_and_netz_player_side + 2].field_9;
            }
            else
            {
                v12 = byte_47C654 + 1;
                v5 = __OFSUB__(byte_47C654 + 1, 15);
                v4 = (char)(byte_47C654++ - 14) < 0;
                if (!(v4 ^ v5))
                {
                    v12 = 0;
                    byte_47C654 = 0;
                }
                v13 = __47CA80_array_idx_and_netz_player_side;
                netz_47A740[(int)__47CA80_array_idx_and_netz_player_side + 2].field_9 = v12;
                netz_42E450(v13, 1, 69);
                byte_47C654 = netz_47A740[(int)__47CA80_array_idx_and_netz_player_side + 2].field_9;
            }
        }
        while (!script_443780(a1, 2056, 1, 2))
            ;
        v6 = byte_47C654;
        do
        {
            if (++v6 >= 15)
                v6 = 0;
            v7 = 0;
            v8 = (char *)&netz_47A740[3].ptr_4;
            while (v7 == __47CA80_array_idx_and_netz_player_side || !*(v8 - 24) || !*(_DWORD *)v8 || *(v8 - 23) != v6)
            {
                v8 += 28;
                v7 = (char *)v7 + 1;
                if ((int)v8 >= (int)&netz_47A840)
                {
                    v9 = 0;
                    goto LABEL_22;
                }
            }
            v9 = 1;
        LABEL_22:
            ;
        } while (v9);
        byte_47C654 = v6;
        v10 = 7 * (_DWORD)__47CA80_array_idx_and_netz_player_side;
        netz_47A740[4 * v10 / 0x1Cu + 2].field_9 = v6;
        netz_42E450((void *)v10, 0, 65);
    }
}


//----- (00441050) --------------------------------------------------------
void script_main_menu_kaos_map(Script *a1)
{
    RenderString *v1; // edi@3
    Sprite *v2; // esi@3
    Sprite *v3; // eax@3
    bool v4; // sf@6
    unsigned __int8 v5; // of@6
    char a2; // [sp+10h] [bp-14h]@4

    if (netz_47C6C0_mapd_idx == 15)
        BYTE3(_46E420_starting_cash_idx) = 0;
    v1 = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 406, 116, 20, 3, 9, 14, 16);
    v2 = a1->sprite;
    v3 = sprite_create(MOBD_45, 0, a1->sprite);
    v2->mobd_id = MOBD_45;
    v2->parent = v3;
    v3->parent = 0;
    v3->z_index = 0;
    v2->z_index = 1;
    a1->script_type = SCRIPT_TYPE_8;
    stru29_list_4439F0(v2, v1, 0, 1, 0);
    while (1)
    {
        sprintf(&a2, aS_0, off_46C358[SBYTE3(_46E420_starting_cash_idx)]);
        v1->field_18 = 0;
        v1->num_lines = 0;
        render_string_445AE0(v1);
        render_string_443D80(v1, &a2, 0);
        while (!script_443780(a1, 2156, 1, 0))
            ;
        v5 = __OFSUB__(BYTE3(_46E420_starting_cash_idx) + 1, 15);
        v4 = (char)(BYTE3(_46E420_starting_cash_idx)++ - 14) < 0;
        if (!(v4 ^ v5))
            BYTE3(_46E420_starting_cash_idx) = 0;
        if (netz_47C6C0_mapd_idx != 15)
            netz_44A2A0(64, (int)&_46E420_starting_cash_idx, 5);
    }
}

//----- (00441680) --------------------------------------------------------
void script_main_menu_kaos_max_tech_level(Script *a1)
{
    RenderString *v1; // ebx@3
    Sprite *v2; // esi@3
    Sprite *v3; // eax@3
    bool v4; // zf@6
    bool v5; // sf@6
    unsigned __int8 v6; // of@6
    char v7[8]; // [sp+10h] [bp-8h]@4

    if (netz_47C6C0_mapd_idx == 15)
        BYTE1(_46E420_starting_cash_idx) = 5;
    v1 = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 500, 156, 10, 3, 9, 14, 16);
    v2 = a1->sprite;
    v3 = sprite_create(MOBD_45, 0, a1->sprite);
    v2->mobd_id = MOBD_45;
    v2->parent = v3;
    v3->parent = 0;
    v3->z_index = 0;
    v2->z_index = 1;
    a1->script_type = SCRIPT_TYPE_8;
    stru29_list_4439F0(v2, v1, 0, 1, 0);
    while (1)
    {
        sprintf(v7, aD_2, SBYTE1(_46E420_starting_cash_idx));
        v1->field_18 = 0;
        v1->num_lines = 0;
        render_string_443D80(v1, v7, 0);
        while (!script_443780(a1, 2112, 1, 2))
            ;
        v6 = __OFSUB__(BYTE1(_46E420_starting_cash_idx) + 1, 5);
        v4 = BYTE1(_46E420_starting_cash_idx) == 4;
        v5 = (char)(BYTE1(_46E420_starting_cash_idx)++ - 4) < 0;
        if (!((unsigned __int8)(v5 ^ v6) | v4))
            BYTE1(_46E420_starting_cash_idx) = 2;
        if (netz_47C6C0_mapd_idx != 15)
            netz_44A2A0(64, (int)&_46E420_starting_cash_idx, 5);
    }
}


//----- (00441260) --------------------------------------------------------
void script_main_menu_kaos_bunkers_toggle(Script *a1)
{
    RenderString *v1; // ebp@3
    Sprite *v2; // esi@3
    Sprite *v3; // eax@3
    const char *v4; // edx@4

    if (netz_47C6C0_mapd_idx == 15)
        BYTE2(_46E420_starting_cash_idx) = 0;
    v1 = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 340, 156, 10, 3, 9, 14, 16);
    v2 = a1->sprite;
    v3 = sprite_create(MOBD_45, 0, a1->sprite);
    v2->mobd_id = MOBD_45;
    v2->parent = v3;
    v3->parent = 0;
    v3->z_index = 0;
    v2->z_index = 1;
    a1->script_type = SCRIPT_TYPE_8;
    stru29_list_4439F0(v2, v1, 0, 1, 0);
    while (1)
    {
        v1->field_18 = 0;
        v1->num_lines = 0;
        v4 = "ON ";
        if (!BYTE2(_46E420_starting_cash_idx))
            v4 = "OFF";
        render_string_443D80(v1, v4, 0);
        while (!script_443780(a1, 2096, 1, 2))
            ;
        BYTE2(_46E420_starting_cash_idx) ^= 1u;
        if (netz_47C6C0_mapd_idx != 15)
            netz_44A2A0(64, (int)&_46E420_starting_cash_idx, 5);
    }
}


//----- (00440ED0) --------------------------------------------------------
void script_main_menu_kaos_team(Script *a1)
{
    RenderString *v1; // ebp@4
    Sprite *v2; // edi@4
    Sprite *v3; // eax@4
    const char *v4; // edx@5
    void *v5; // eax@12
    bool v6; // zf@12
    int v7; // eax@15

    if (netz_47C6C0_mapd_idx == LEVEL_MUTE_01)
        _47C658_faction_index = 0;
    else
        _47C658_faction_index = netz_47A740[(int)__47CA80_array_idx_and_netz_player_side + 2].field_A;
    v1 = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 142, 156, 10, 3, 9, 14, 16);
    v2 = a1->sprite;
    v3 = sprite_create(MOBD_45, 0, a1->sprite);
    v2->mobd_id = MOBD_45;
    v2->parent = v3;
    v3->parent = 0;
    v3->z_index = 0;
    v2->z_index = 1;
    a1->script_type = SCRIPT_TYPE_8;
    stru29_list_4439F0(v2, v1, 0, 1, 0);
    while (1)
    {
        while (1)
        {
            v1->field_18 = 0;
            v1->num_lines = 0;
            v4 = aEvol_0;
            if (!_47C658_faction_index)
                v4 = a2;
            render_string_443D80(v1, v4, 0);
            if (netz_47C6C0_mapd_idx != 15)
                break;
            while (!script_443780(a1, 2032, 1, 2))
                ;
            _47C658_faction_index ^= 1u;
        }
        if (netz_47A834)
            break;
        do
            v7 = script_443570(a1, 2032, 1, 2);
        while (!v7);
        if (v7 == 300)
        {
            _47C658_faction_index = netz_47A740[(int)__47CA80_array_idx_and_netz_player_side + 2].field_A;
        }
        else
        {
        LABEL_12:
            v5 = netz_47A834;
            v6 = netz_47A834 == 0;
            _47C658_faction_index ^= 1u;
            netz_47A740[(int)__47CA80_array_idx_and_netz_player_side + 2].field_A = _47C658_faction_index;
            if (v6)
                netz_42E450(v5, 0, 66);
            else
                netz_42E450(v5, 0, 65);
        }
    }
    while (!script_443780(a1, 2032, 1, 2))
        ;
    goto LABEL_12;
}



//----- (00440810) --------------------------------------------------------
void script_main_menu_kaos_player_name(Script *a1)
{
    Script *v1; // edi@1
    Sprite *v2; // ebx@1
    stru8 *v3; // eax@8
    int v4; // ecx@8
    Sprite *v5; // esi@10
    RenderString *v6; // edx@10
    char v7; // cl@14
    int v8; // ebx@17
    ScriptEvent *i; // eax@18
    enum SCRIPT_EVENT v10; // edx@19
    Sprite *v12; // eax@31
    int v13; // edx@31
    int v14; // ecx@31
    int v15; // esi@31
    char v16; // al@32
    int v17; // eax@41
    stru8 *v18; // ecx@44
    int v19; // eax@44
    int v20; // [sp+0h] [bp-Ch]@41

    v1 = a1;
    v2 = a1->sprite;
    _47C65C_render_string = render_string_create(
        0,
        currently_running_lvl_mobd[MOBD_FONT_ITALIC].items,
        144,
        72,
        14,
        3,
        9,
        14,
        16);
    if (!_47C65C_render_string)
    {
        sprite_list_remove(v2);
        script_terminate(a1);
    }
    _47C664_ingame_menu_sprite = sprite_create(MOBD_FONT_ITALIC, 0, v2);
    if (!_47C664_ingame_menu_sprite)
    {
        sprite_list_remove(v2);
        render_string_list_remove(_47C65C_render_string);
        script_terminate(a1);
    }
    if (netz_47C6C0_mapd_idx != LEVEL_MUTE_01 && !netz_47A834)
    {
        strcpy(netz_47A740[(int)__47CA80_array_idx_and_netz_player_side + 2].player_name, netz_default_player_name);
        v1 = a1;
    }
    render_string_445AE0(_47C65C_render_string);
    _47C65C_render_string->field_18 = 0;
    _47C65C_render_string->num_lines = 0;
    render_string_443D80(_47C65C_render_string, netz_default_player_name, 0);
    _47C664_ingame_menu_sprite->field_88_unused = 1;
    v3 = _47C65C_render_string->pstru8;
    v4 = _47C65C_render_string->field_C + 1;
    if (_47C65C_render_string->field_C != -1)
    {
        do
        {
            v3 = v3->next;
            --v4;
        } while (v4);
    }
    _47C664_ingame_menu_sprite->x = v3->drawjob->job_details.x << 8;
    _47C664_ingame_menu_sprite->field_88_unused = 1;
    _47C664_ingame_menu_sprite->y = 22528;
    v2->parent = _47C664_ingame_menu_sprite;
    v5 = v1->sprite;
    v6 = _47C65C_render_string;
    v5->parent = 0;
    v1->script_type = SCRIPT_TYPE_18;
    stru29_list_4439F0(v5, v6, 0, 0, 0);
    sprite_load_mobd(v5, 1368);
    v2->x = 40960;
    v2->field_88_unused = 1;
    v2->y = 22528;
    while (1)
    {
        if (netz_47C6C0_mapd_idx != 15)
        {
            if (netz_47A834)
                v7 = 65;
            else
                v7 = 66;
            netz_42E450(netz_47A834, 0, v7);
        }
        v8 = 0;
        do
        {
            script_wait_event(v1);
            for (i = script_get_next_event(v1); i; i = script_get_next_event(v1))
            {
                v10 = i->event;
                switch (v10)
                {
                case EVT_MOUSE_HOVER:
                    stru29_list_443AE0_find_by_sprite(v1->sprite);
                    break;
                case EVT_MSG_SELECTED:
                    v8 = 1;
                    break;
                case EVT_MSG_1528_cancel:
                    v8 = 1;
                    break;
                }
                script_discard_event(i);
            }
        } while (!v8);
        _47C664_ingame_menu_sprite->field_88_unused = 1;
        _47C664_ingame_menu_sprite->x = 40960;
        _47C664_ingame_menu_sprite->field_88_unused = 1;
        _47C664_ingame_menu_sprite->y = 22528;
        _47C664_ingame_menu_sprite->z_index = 10;
        sprite_load_mobd(_47C664_ingame_menu_sprite, 1096);
        dword_47C6C4 = 1;
        input_get_string(netz_default_player_name, 8u, input_get_string_440770_handler, 1, v1);
        v12 = _47C6E0_task->sprite;
        v13 = v12->y >> 8;
        v14 = v12->x >> 8;
        v12->field_88_unused = 1;
        input_set_mouse_pos(v14, v13);
        v15 = 0;
        dword_47C6C4 = 0;
        do
        {
            v16 = netz_default_player_name[v15];
            if (!v16)
                break;
            if (!isalpha(v16) && !isdigit(netz_default_player_name[v15]))
                netz_default_player_name[v15] = 95;
            ++v15;
        } while (v15 < 7);
        LOBYTE_HEXRAYS(dword_468CE8) = 0;
        _47C664_ingame_menu_sprite->field_88_unused = 1;
        _47C664_ingame_menu_sprite->x = 40960;
        _47C664_ingame_menu_sprite->field_88_unused = 1;
        _47C664_ingame_menu_sprite->y = 22528;
        sprite_release_mobd_item(_47C664_ingame_menu_sprite);
        if (netz_47C6C0_mapd_idx != 15 && netz_47A834)
        {
            j_netz_430670((int)netz_default_player_name);
        }
        __debugbreak(); // decompiation error: 4695939 is an absolute address in original exe
        strcpy((char *)(28 * (_DWORD)__47CA80_array_idx_and_netz_player_side + 4695939), netz_default_player_name);
        render_string_445AE0(_47C65C_render_string);
        _47C65C_render_string->field_18 = 0;
        _47C65C_render_string->num_lines = 0;
        render_string_443D80(_47C65C_render_string, netz_default_player_name, 0);
        _47C664_ingame_menu_sprite->field_88_unused = 1;
        v18 = _47C65C_render_string->pstru8;
        v19 = _47C65C_render_string->field_C + 1;
        if (_47C65C_render_string->field_C != -1)
        {
            do
            {
                v18 = v18->next;
                --v19;
            } while (v19);
        }
        _47C664_ingame_menu_sprite->x = v18->drawjob->job_details.x << 8;
        _47C664_ingame_menu_sprite->field_88_unused = 1;
        _47C664_ingame_menu_sprite->y = 22528;
        if (netz_47C6C0_mapd_idx != 15)
            netz_42E450((void *)netz_47C6C0_mapd_idx, 0, 65);
        v1 = a1;
    }
}



//----- (00441940) --------------------------------------------------------
void script_main_menu_kaos_cancel(Script *a1)
{
    Sprite *v1; // edi@1
    Sprite *v2; // eax@1
    int v3; // edx@2
    DataMapd *v4; // eax@4
    int v5; // eax@7
    int v6; // eax@12
    DataMapd *v9; // eax@21
    int v10; // ecx@21
    int v11; // ecx@22
    DataMapd *v14; // eax@26
    int v15; // [sp+0h] [bp-Ch]@7

    v1 = a1->sprite;
    v2 = sprite_create(MOBD_45, 0, a1->sprite);
    v1->mobd_id = MOBD_45;
    v1->parent = v2;
    v2->parent = 0;
    v2->z_index = 0;
    v1->z_index = 1;
    a1->script_type = SCRIPT_TYPE_17;
    stru29_list_4439F0(v1, 0, 1, 1, 0);
    while (!script_443780(a1, 2044, 1, 0))
        ;
    if (netz_47C6C0_mapd_idx == 15)
    {
        netz_47C6BC_mapd_idx = 15;
        netz_47C6C0_mapd_idx = 0;
        script_408500_anim(a1);
        stru29_list_remove_all(a1);
        stru29_list_alloc();
        bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
        script_sleep(a1, 3);
        v4 = LVL_FindMapd();
        _40E400_set_palette(v4->items->GetPalette());
        _47A010_mapd_item_being_drawn[0] = MAPD_Draw(MAPD_MAP, 0, -10);
        cplc_select(0);
        cplc_406320();
        script_sleep(a1, 1);
        script_4084A0_animation(a1);
        script_terminate(a1);
    }
    else
    {

        LOBYTE_HEXRAYS(v3) = 67;
        netz_42FA00(-1, v3, 0, 0, 1);
        netz_42F9C0(0, 0);
        netz_42F650((void *)j_netz_430690());
        netz_42F8E0(0);
    }
    if (netz_468B6C_providers_idx == 2 || netz_468B6C_providers_idx == 1)
    {
        v11 = netz_47C6C0_mapd_idx;
        netz_47C6C0_mapd_idx = 1;
        netz_47C6BC_mapd_idx = v11;
        script_408500_anim(a1);
        stru29_list_realloc(a1);
        bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
        script_sleep(a1, 3);
        v14 = LVL_FindMapd();
        _40E400_set_palette(v14[1].items->GetPalette());
        _47A010_mapd_item_being_drawn[0] = MAPD_Draw(MAPD_FOG_OF_WAR, 0, -10);
        v10 = 1;
    }
    else
    {
        netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
        netz_47C6C0_mapd_idx = 4;
        script_408500_anim(a1);
        stru29_list_realloc(a1);
        bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
        script_sleep(a1, 3);
        v9 = LVL_FindMapd();
        _40E400_set_palette(v9[4].items->GetPalette());
        _47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)4, 0, -10);
        v10 = 4;
    }
    cplc_select(v10);
    cplc_406320();
    script_sleep(a1, 1);
    script_4084A0_animation(a1);
    script_terminate(a1);
}


//----- (00441CE0) --------------------------------------------------------
void script_main_menu_kaos_start(Script *a1)
{
    Script *v1; // esi@1
    Sprite *v2; // edi@1
    Sprite *v3; // eax@1
    void *v6; // eax@8
    Script *v7; // edx@8
    signed __int64 v8; // rtt@8
    int v9; // eax@11
    int v10; // eax@16
    int v11; // [sp+0h] [bp-Ch]@11

    v1 = a1;
    dword_47C6B8 = 0;
    v2 = a1->sprite;
    v3 = sprite_create(MOBD_45, 0, a1->sprite);
    v2->mobd_id = MOBD_45;
    v2->parent = v3;
    v3->parent = 0;
    v3->z_index = 0;
    v2->z_index = 1;
    v1->script_type = SCRIPT_TYPE_8;
    stru29_list_4439F0(v2, 0, 0, 1, 0);
    if (netz_47C6C0_mapd_idx == 15)
    {
        while (!script_443780(v1, 1872, 1, 0))
            ;
    }
    else
    {
        if (!script_create_coroutine(SCRIPT_TYPE_8, script_43F7C0, 0))
            game_state = GAME_STATE::GAME_3_quit_mission;
        do
        {
            while (!script_443780(v1, 1872, dword_47C6B8, 0))
                ;
        } while (!netz_42E7B0());
    }

    srand(clock());
    v8 = rand();
    v6 = (void *)(v8 / 0xFFFF);
    v7 = (Script *)(v8 % 0xFFFF);
    kknd_srand_debug((int)v7);
    if (netz_47C6C0_mapd_idx == 15)
    {
        is_demo_build = 1;
        _47C6DC_dont_execute_unit_handlers = 1;
        single_player_game = 1;
        netz_42E7F0();
        v10 = rnd_capped(3);
        player_side = (PLAYER_SIDE)(2 * v10 + 2);
        if (!_47C658_faction_index)
            player_side = (PLAYER_SIDE)(2 * v10 + 1);
        current_level_idx = (LEVEL_ID)(SBYTE3(_46E420_starting_cash_idx) + 30);
        game_state = GAME_STATE::Mission;
        if (_47C6E0_task)
            script_deinit(_47C6E0_task);
    }
    else
    {
        a1 = v7;
        j_netz_430610();
        netz_44A2A0(71, (int)&a1, 4);
        is_demo_build = 0;
        single_player_game = 0;
        _47C6DC_dont_execute_unit_handlers = 1;
        netz_42E7F0();
        current_level_idx = (LEVEL_ID)(SBYTE3(_46E420_starting_cash_idx) + 30);
        game_state = GAME_STATE::Mission;
        if (_47C6E0_task)
        {
            script_deinit(_47C6E0_task);
            _47C6E0_task = 0;
            return;
        }
    }
    _47C6E0_task = 0;
}



//----- (0043D5F0) --------------------------------------------------------
void script_main_menu_multiplayer_cancel(Script *a1)
{
    Sprite *v1; // edi@1
    Sprite *v2; // eax@1
    DataMapd *v5; // eax@7

    netz_free_provider_async();
    v1 = a1->sprite;
    v2 = sprite_create(MOBD_45, 0, a1->sprite);
    v1->mobd_id = MOBD_45;
    v1->parent = v2;
    v2->parent = 0;
    v2->z_index = 0;
    v1->z_index = 1;
    a1->script_type = SCRIPT_TYPE_17;
    stru29_list_4439F0(v1, 0, 1, 1, 0);
    while (!script_443780(a1, 2044, 1, 0))
        ;
    netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
    netz_47C6C0_mapd_idx = 0;
    script_408500_anim(a1);
    stru29_list_realloc(a1);
    bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    script_sleep(a1, 3);
    v5 = LVL_FindMapd();
    _40E400_set_palette(v5->items->GetPalette());
    _47A010_mapd_item_being_drawn[0] = MAPD_Draw(MAPD_MAP, 0, -10);
    cplc_select(0);
    cplc_406320();
    script_sleep(a1, 1);
    script_4084A0_animation(a1);
    script_terminate(a1);
}


//----- (0043D090) --------------------------------------------------------
void script_main_menu_multiplayer_ipx(Script *a1)
{
    Sprite *v1; // edi@3
    Sprite *v2; // eax@3
    int v3; // eax@3
    int v4; // edi@3
    DataMapd *v7; // eax@11
    DWORD pcbBuffer; // [sp+Ch] [bp-4h]@2

    if (dword_46E404)
    {
        netz_default_player_name[0] = 0;

        auto username = OsGetUserName();
        strncat(netz_default_player_name, username.c_str(), 12);
        //pcbBuffer = 12;
        //GetUserNameA(netz_default_player_name, &pcbBuffer);
    }
    v1 = a1->sprite;
    v2 = sprite_create(MOBD_45, 0, a1->sprite);
    v1->mobd_id = MOBD_45;
    v1->parent = v2;
    v2->parent = 0;
    v2->z_index = 0;
    v1->z_index = 1;
    a1->script_type = SCRIPT_TYPE_2;
    stru29_list_4439F0(v1, 0, 0, 1, 0);
    v3 = netz_42FAC0(aDirectxIpx);
    v4 = v3;
    if (v3 != -1)
    {
        if (netz_468B6C_providers[v3].is_directplay_initialized)
        {
            while (!script_443780(a1, 1792, 1, 0))
                ;
            _46E420_starting_cash_idx = 1280;
            if (netz_42E170(v4, netz_default_player_name))
            {
                netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
                netz_47C6C0_mapd_idx = 4;
                script_408500_anim(a1);
                stru29_list_realloc(a1);
                bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
                script_sleep(a1, 3);
                v7 = LVL_FindMapd();
                _40E400_set_palette(v7[4].items->GetPalette());
                _47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)4, 0, -10);
                cplc_select(4);
                cplc_406320();
                script_sleep(a1, 1);
                script_4084A0_animation(a1);
                script_terminate(a1);
            }
        }
        else
        {
            while (!script_443780(a1, 1792, 0, 0))
                ;
        }
    }
}

//----- (0043D270) --------------------------------------------------------
void script_main_menu_multiplayer_serial(Script *a1)
{
    Sprite *v1; // edi@1
    Sprite *v2; // eax@1
    int v3; // edi@1
    DataMapd *v6; // eax@9

    v1 = a1->sprite;
    v2 = sprite_create(MOBD_45, 0, a1->sprite);
    v1->mobd_id = MOBD_45;
    v1->parent = v2;
    v2->parent = 0;
    v2->z_index = 0;
    v1->z_index = 1;
    a1->script_type = SCRIPT_TYPE_2;
    stru29_list_4439F0(v1, 0, 0, 1, 0);
    v3 = netz_42FAC0(aDirectxSerial);
    if (v3 != -1)
    {
        if (netz_468B6C_providers[v3].is_directplay_initialized)
        {
            while (!script_443780(a1, 1904, 1, 0))
                ;
            _46E420_starting_cash_idx = 1280;
            if (netz_42E170(v3, netz_default_player_name))
            {
                netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
                netz_47C6C0_mapd_idx = 5;
                script_408500_anim(a1);
                stru29_list_realloc(a1);
                bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
                script_sleep(a1, 3);
                v6 = LVL_FindMapd();
                _40E400_set_palette(v6[5].items->GetPalette());
                _47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)5, 0, -10);
                cplc_select(5);
                cplc_406320();
                script_sleep(a1, 1);
                script_4084A0_animation(a1);
                script_terminate(a1);
            }
        }
        else
        {
            while (!script_443780(a1, 1904, 0, 0))
                ;
        }
    }
}
//----- (0043D430) --------------------------------------------------------
void script_main_menu_multiplayer_modem(Script *a1)
{
    Sprite *v1; // edi@1
    Sprite *v2; // eax@1
    int v3; // edi@1
    DataMapd *v6; // eax@9

    v1 = a1->sprite;
    v2 = sprite_create(MOBD_45, 0, a1->sprite);
    v1->mobd_id = MOBD_45;
    v1->parent = v2;
    v2->parent = 0;
    v2->z_index = 0;
    v1->z_index = 1;
    a1->script_type = SCRIPT_TYPE_2;
    stru29_list_4439F0(v1, 0, 0, 1, 0);
    v3 = netz_42FAC0(aDirectxModem);
    if (v3 != -1)
    {
        if (netz_468B6C_providers[v3].is_directplay_initialized)
        {
            while (!script_443780(a1, 1888, 1, 0))
                ;
            _46E420_starting_cash_idx = 1280;
            if (netz_42E170(v3, netz_default_player_name))
            {
                netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
                netz_47C6C0_mapd_idx = 6;
                script_408500_anim(a1);
                stru29_list_realloc(a1);
                bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
                script_sleep(a1, 3);
                v6 = LVL_FindMapd();
                _40E400_set_palette(v6[6].items->GetPalette());
                _47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)6, 0, -10);
                cplc_select(6);
                cplc_406320();
                script_sleep(a1, 1);
                script_4084A0_animation(a1);
                script_terminate(a1);
            }
        }
        else
        {
            while (!script_443780(a1, 1888, 0, 0))
                ;
        }
    }
}