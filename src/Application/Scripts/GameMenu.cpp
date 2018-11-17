#include "src/Application/Scripts/GameMenu.h"

#include "src/_unsorted_data.h"
#include "src/_unsorted_functions.h"
#include "src/Cursor.h"
#include "src/RenderDrawHandlers.h"
#include "src/Script.h"
#include "src/ScriptEvent.h"
#include "src/Sprite.h"


#define VOLUME_SLIDER_MUSIC     (void *)0
#define VOLUME_SLIDER_SFX       (void *)1
#define VOLUME_SLIDER_UNKNOWN   (void *)2


#define INGAME_MENU_CONTROLS_MOBD_MISSION_BRIEFING_BACKGROUND   12
#define INGAME_MENU_CONTROLS_MOBD_SLIDER_PIMP                   48
#define INGAME_MENU_CONTROLS_MOBD_732                           732
#define INGAME_MENU_CONTROLS_MOBD_744                           744
#define INGAME_MENU_CONTROLS_MOBD_756                           756
#define INGAME_MENU_CONTROLS_MOBD_YESNO_NO                      768
#define INGAME_MENU_CONTROLS_MOBD_YESNO_YES                     780
#define INGAME_MENU_CONTROLS_MOBD_792                           792
#define INGAME_MENU_CONTROLS_MOBD_804                           804
#define INGAME_MENU_CONTROLS_MOBD_816                           816
#define INGAME_MENU_CONTROLS_MOBD_828                           828
#define INGAME_MENU_CONTROLS_MOBD_840                           840
#define INGAME_MENU_CONTROLS_MOBD_852                           852
#define INGAME_MENU_CONTROLS_MOBD_864                           864
#define INGAME_MENU_CONTROLS_MOBD_876                           876
#define INGAME_MENU_CONTROLS_MOBD_888                           888
#define INGAME_MENU_CONTROLS_MOBD_900                           900


//----- (00432620) --------------------------------------------------------
void script_ingame_menu_create_load_dialog(Script *a1)
{
    Script *v1; // esi@1
    Sprite *v2; // eax@1
    Sprite *v3; // eax@3
    Sprite *v4; // eax@5
    Sprite *v5; // eax@7
    Sprite *v6; // eax@9
    Sprite *v7; // eax@11
    Sprite *v8; // edi@11

    v1 = a1;
    script_trigger_event_group(a1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_INGAME_MENU_BUTTON);
    v2 = sprite_create_scripted(MOBD_FONT_ITALIC, v1->sprite, script_ingame_menu_load_game_list, SCRIPT_COROUTINE, 0);
    if (v2)
        v2->script->field_1C = 1;
    v3 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1->sprite, script_ingame_menu_load_game_load, SCRIPT_COROUTINE, 0);
    if (v3)
        v3->script->field_1C = 1;
    v4 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1->sprite, script_ingame_menu_load_game_cancel, SCRIPT_COROUTINE, 0);
    if (v4)
        v4->script->field_1C = 1;
    v5 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1->sprite, script_ingame_menu_load_game_up, SCRIPT_COROUTINE, 0);
    if (v5)
        v5->script->field_1C = 1;
    v6 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1->sprite, script_ingame_menu_load_game_down, SCRIPT_COROUTINE, 0);
    if (v6)
        v6->script->field_1C = 1;
    v7 = sprite_create(MOBD_INGAME_MENU_CONTROLS, 0, 0);
    v8 = v7;
    if (v7)
    {
        v7->drawjob->on_update_handler = (DrawUpdateHandler)drawjob_update_handler_4483E0_ui;
        v7->x = v1->sprite->x;
        v7->y = v1->sprite->y;
        v7->z_index = v1->sprite->z_index + 1;
        sprite_load_mobd(v7, 24);
        task_47C028->param = v8;
    }
}


//----- (00432F30) --------------------------------------------------------
void script_ingame_menu_save_game_list(Script *a1)
{
    script_ingame_menu_saveload(a1, SAVEGAME_LIST_APPEARANCE_INGAME_MENU, SAVEGAME_LIST_MODE_SAVING);
}

//----- (00432F20) --------------------------------------------------------
void script_ingame_menu_load_game_list(Script *a1)
{
    script_ingame_menu_saveload(a1, SAVEGAME_LIST_APPEARANCE_INGAME_MENU, SAVEGAME_LIST_MODE_LOADING);
}


//----- (00433E60) --------------------------------------------------------
void script_ingame_menu_save_game_save(Script *a1)
{
    _438630_read_save_lst();
    script_433640_init_script_ui(a1, SCRIPT_TYPE_UI_SLIDER, -80, 153, 3);
    while (true)
    {
        if (!script_434500(a1, INGAME_MENU_CONTROLS_MOBD_792, 1, 0)) {
            break;
        }
        script_trigger_event(a1, EVT_CMD_ENTITY_MOVE, 0, receiver);
    }

    sprite_list_remove((Sprite *)a1->param);
    sprite_list_remove(a1->sprite);
    script_terminate(a1);
}

//----- (00433ED0) --------------------------------------------------------
void script_ingame_menu_save_game_up(Script *a1)
{
    script_433640_init_script_ui(a1, SCRIPT_TYPE_UI_SLIDER, -180, 153, 3);
    while (true)
    {
        bool res = script_434500(a1, INGAME_MENU_CONTROLS_MOBD_744, 2, 0);
        script_trigger_event(a1, EVT_MSG_SHOW_UNIT_HINT, 0, receiver);
        if (!res) {
            break;
        }
    }

    sprite_list_remove((Sprite *)a1->param);
    sprite_list_remove(a1->sprite);
    script_terminate(a1);
}

//----- (00433F40) --------------------------------------------------------
void script_ingame_menu_save_game_down(Script *a1)
{
    script_433640_init_script_ui(a1, SCRIPT_TYPE_UI_SLIDER, -130, 153, 3);
    while (true)
    {
        bool res = script_434500(a1, INGAME_MENU_CONTROLS_MOBD_732, 2, 0);
        script_trigger_event(a1, EVT_MSG_DESELECTED, 0, receiver);
        if (!res) {
            break;
        }
    }

    sprite_list_remove((Sprite *)a1->param);
    sprite_list_remove(a1->sprite);
    script_terminate(a1);
}

//----- (00433FB0) --------------------------------------------------------
void script_ingame_menu_save_game_cancel(Script *a1)
{
    script_433640_init_script_ui(a1, SCRIPT_TYPE_UI_SLIDER, 0, 153, 3);
    if (script_434500(a1, INGAME_MENU_CONTROLS_MOBD_816, 1, 0))
    {
        script_trigger_event_group(a1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_UI_SLIDER);
        sprite_list_remove((Sprite *)task_47C028->param);
        if (a1 != task_47C028)
            script_trigger_event(a1, EVT_MSG_1522_plan_building_construction, 0, task_47C028);
    }

    sprite_list_remove((Sprite *)a1->param);
    sprite_list_remove(a1->sprite);
    script_terminate(a1);
}

//----- (00434040) --------------------------------------------------------
void script_ingame_menu_load_game_load(Script *a1)
{
    _438630_read_save_lst();
    script_433640_init_script_ui(a1, SCRIPT_TYPE_UI_SLIDER, -80, 153, 3);
    while (true)
    {
        if (!script_434500(a1, INGAME_MENU_CONTROLS_MOBD_804, 1, 0)) {
            break;
        }
        script_trigger_event(a1, EVT_MSG_1549, 0, receiver);
    }

    sprite_list_remove((Sprite *)a1->param);
    sprite_list_remove(a1->sprite);
    script_terminate(a1);
}

//----- (004340B0) --------------------------------------------------------
void script_ingame_menu_load_game_up(Script *a1)
{
    script_433640_init_script_ui(a1, SCRIPT_TYPE_UI_SLIDER, -180, 153, 3);
    while (true)
    {
        bool res = script_434500(a1, INGAME_MENU_CONTROLS_MOBD_744, 2, 0);
        script_trigger_event(a1, EVT_MSG_SHOW_UNIT_HINT, 0, receiver);
        if (!res) {
            break;
        }
    }

    sprite_list_remove((Sprite *)a1->param);
    sprite_list_remove(a1->sprite);
    script_terminate(a1);
}

//----- (00434120) --------------------------------------------------------
void script_ingame_menu_load_game_down(Script *a1)
{
    script_433640_init_script_ui(a1, SCRIPT_TYPE_UI_SLIDER, -130, 153, 3);
    while (true)
    {
        bool res = script_434500(a1, INGAME_MENU_CONTROLS_MOBD_732, 2, 0);
        script_trigger_event(a1, EVT_MSG_DESELECTED, 0, receiver);
        if (!res) {
            break;
        }
    }

    sprite_list_remove((Sprite *)a1->param);
    sprite_list_remove(a1->sprite);
    script_terminate(a1);
}

//----- (00434190) --------------------------------------------------------
void script_ingame_menu_load_game_cancel(Script *a1)
{
    script_433640_init_script_ui(a1, SCRIPT_TYPE_UI_SLIDER, 0, 153, 3);
    if (script_434500(a1, INGAME_MENU_CONTROLS_MOBD_816, 1, 0))
    {
        script_trigger_event_group(a1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_UI_SLIDER);
        sprite_list_remove((Sprite *)task_47C028->param);
        if (a1 != task_47C028)
            script_trigger_event(a1, EVT_MSG_1522_plan_building_construction, 0, task_47C028);
    }

    sprite_list_remove((Sprite *)a1->param);
    sprite_list_remove(a1->sprite);
    script_terminate(a1);
}


//----- (00432F40) --------------------------------------------------------
void script_ingame_menu_create_save_dialog(Script *a1)
{
    Sprite *v1; // eax@1
    Sprite *v2; // eax@3
    Sprite *v3; // eax@5
    Sprite *v4; // eax@7
    Sprite *v5; // eax@9
    Sprite *v6; // eax@11
    Sprite *v7; // edi@11

    script_trigger_event_group(a1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_INGAME_MENU_BUTTON);
    //list
    v1 = sprite_create_scripted(MOBD_FONT_ITALIC, a1->sprite, script_ingame_menu_save_game_list, SCRIPT_COROUTINE, 0);
    if (v1)
        v1->script->field_1C = 1;
    //save
    v2 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, a1->sprite, script_ingame_menu_save_game_save, SCRIPT_COROUTINE, 0);
    if (v2)
        v2->script->field_1C = 1;
    v3 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, a1->sprite, script_ingame_menu_save_game_cancel, SCRIPT_COROUTINE, 0);
    if (v3)
        v3->script->field_1C = 1;
    v4 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, a1->sprite, script_ingame_menu_save_game_up, SCRIPT_COROUTINE, 0);
    if (v4)
        v4->script->field_1C = 1;
    v5 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, a1->sprite, script_ingame_menu_save_game_down, SCRIPT_COROUTINE, 0);
    if (v5)
        v5->script->field_1C = 1;
    v6 = sprite_create(MOBD_INGAME_MENU_CONTROLS, 0, 0);
    v7 = v6;
    if (v6)
    {
        v6->drawjob->on_update_handler = (DrawUpdateHandler)drawjob_update_handler_4483E0_ui;
        v6->x = a1->sprite->x;
        v6->y = a1->sprite->y;
        v6->z_index = a1->sprite->z_index + 256;
        sprite_load_mobd(v6, 24);
        task_47C028->param = v7;
    }
}



//----- (00433780) --------------------------------------------------------
void script_ingame_menu_options(Script *a1)
{
    signed __int16 v1; // ax@2
    Sprite *v2; // edi@6

    if (!single_player_game || (v1 = 18, is_demo_build))
        v1 = 66;
    script_433640_init_script_ui(a1, SCRIPT_TYPE_INGAME_MENU_BUTTON, -92, v1, 1);
    if (script_434500(a1, INGAME_MENU_CONTROLS_MOBD_864, 0, 0))
    {
        script_trigger_event(a1, EVT_CMD_ENTITY_MOVE, 0, task_47C028);
        script_sleep(a1, 1);
    }
    v2 = a1->sprite;
    sprite_list_remove((Sprite *)a1->param);
    sprite_list_remove(v2);
    script_terminate(a1);
}


//----- (00433A60) --------------------------------------------------------
void script_ingame_menu_quit(Script *a1)
{
    signed __int16 v1; // ax@2
    Sprite *v2; // edi@6

    if (!single_player_game || (v1 = 162, is_demo_build))
        v1 = 114;
    script_433640_init_script_ui(a1, SCRIPT_TYPE_INGAME_MENU_BUTTON, -92, v1, 7);
    if (script_434500(a1, INGAME_MENU_CONTROLS_MOBD_828, 0, 0))
    {
        script_trigger_event(a1, EVT_CMD_ENTITY_ATTACK, 0, task_47C028);
        script_sleep(a1, 1);
    }
    v2 = a1->sprite;
    sprite_list_remove((Sprite *)a1->param);
    sprite_list_remove(v2);
    script_terminate(a1);
}


//----- (00433960) --------------------------------------------------------
void script_ingame_menu_resume(Script *a1)
{
    signed __int16 v1; // ax@2
    Sprite *v2; // edi@6

    if (!single_player_game || (v1 = 114, is_demo_build))
        v1 = 90;
    script_433640_init_script_ui(a1, SCRIPT_TYPE_INGAME_MENU_BUTTON, -92, v1, 5);
    if (script_434500(a1, INGAME_MENU_CONTROLS_MOBD_840, 0, 0))
    {
        script_trigger_event(a1, EVT_MSG_1528_cancel, 0, task_47C028);
        script_sleep(a1, 1);
    }
    v2 = a1->sprite;
    sprite_list_remove((Sprite *)a1->param);
    sprite_list_remove(v2);
    script_terminate(a1);
}


//----- (004322D0) --------------------------------------------------------
void script_ingame_menu_create_briefing_dialog(Script *script)
{
    RenderString *render_string; // eax@1
    int num_lines; // edi@2
    int v4; // ebp@2
    char *current_mission_briefing; // esi@4
    int counter; // ecx@8
    char current_letter; // al@9
    int loop_counter; // [sp+10h] [bp-6Ch]@6
    char text_line[512]; // [sp+18h] [bp-64h]@11

    script_trigger_event_group(script, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_INGAME_MENU_BUTTON);
    render_string = render_string_create(
        0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 120, 70, 42, 15, 0x200003E9, 14, 5
    );
    _47C65C_render_string = render_string;
    if (render_string)
    {
        num_lines = 0;
        v4 = 5;
        // get current level mission briefing
        if (current_level_idx < LEVEL_SURV_16 || current_level_idx > LEVEL_MUTE_25)
            current_mission_briefing = mission_briefings[current_level_idx];
        else
            current_mission_briefing = *(char **)&aNoFreeLinks[4 * current_level_idx + 12];

        render_string_445AE0(render_string);
        loop_counter = 0;
        do
        {
            // if no mission briefing
            if (!*current_mission_briefing)
                break;

            // extract line of text into array
            counter = 0;
            while (1)
            {
                current_letter = *current_mission_briefing;
                if (*current_mission_briefing == '\n' || !current_letter)
                    break;
                text_line[counter++] = current_letter;
                ++current_mission_briefing;
            }
            text_line[counter] = 0;

            // skip new line character
            if (*current_mission_briefing == '\n')
                ++current_mission_briefing;

            // render text line
            _47C65C_render_string->field_18 = v4;
            _47C65C_render_string->num_lines = num_lines;
            render_string_443D80(_47C65C_render_string, text_line, 0);

            // calculate line number
            if (loop_counter)
            {
                ++num_lines;
            }
            else
            {
                num_lines += 2;
                v4 = 0;
            }
            ++loop_counter;
        } while (loop_counter < 11);
    }
    auto v5 = sprite_create_scripted(
        MOBD_INGAME_MENU_CONTROLS, script->sprite, script_ingame_menu_briefing_done, SCRIPT_COROUTINE, 0
    );
    if (v5)
        v5->script->field_1C = 1;
    sprite_load_mobd(task_47C028->sprite, INGAME_MENU_CONTROLS_MOBD_MISSION_BRIEFING_BACKGROUND);
}


//----- (00433D20) --------------------------------------------------------
void script_ingame_menu_briefing_done(Script *a1)
{
    Sprite *v1; // edi@6

    script_433640_init_script_ui(a1, SCRIPT_TYPE_UI_SLIDER, -55, 185, 3);
    if (script_434500(a1, INGAME_MENU_CONTROLS_MOBD_756, 1, 0))
    {
        script_trigger_event_group(a1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_UI_SLIDER);
        if (_47C65C_render_string)
            render_string_list_remove(_47C65C_render_string);
        if (a1 != task_47C028)
            script_trigger_event(a1, EVT_MSG_1522_plan_building_construction, 0, task_47C028);
    }
    v1 = a1->sprite;
    sprite_list_remove((Sprite *)a1->param);
    sprite_list_remove(v1);
    script_terminate(a1);
}

//----- (00432400) --------------------------------------------------------
void script_ingame_menu_create_dialog(Script *a1)
{
    Sprite *v2; // eax@1
    Sprite *v3; // eax@3
    Sprite *v4; // eax@5
    Sprite *v5; // eax@9
    Sprite *v6; // eax@11
    Sprite *v7; // eax@13
    Sprite *v8; // eax@15

    v2 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, a1->sprite, script_ingame_menu_options, SCRIPT_COROUTINE, 0);
    if (v2)
        v2->script->field_1C = 1;
    v3 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, a1->sprite, script_ingame_menu_quit, SCRIPT_COROUTINE, 0);
    if (v3)
        v3->script->field_1C = 1;
    v4 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, a1->sprite, script_ingame_menu_resume, SCRIPT_COROUTINE, 0);
    if (v4)
        v4->script->field_1C = 1;

    if (single_player_game && !is_demo_build)
    {
        v5 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, a1->sprite, script_ingame_menu_save, SCRIPT_COROUTINE, 0);
        if (v5)
            v5->script->field_1C = 1;
        v6 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, a1->sprite, script_ingame_menu_load, SCRIPT_COROUTINE, 0);
        if (v6)
            v6->script->field_1C = 1;
        v7 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, a1->sprite, script_ingame_menu_restart, SCRIPT_COROUTINE, 0);
        if (v7)
            v7->script->field_1C = 1;
        v8 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, a1->sprite, script_ingame_menu_briefing, SCRIPT_COROUTINE, 0);
        if (v8)
            v8->script->field_1C = 1;
    }
    sprite_load_mobd(a1->sprite, 0);
}


//----- (00433810) --------------------------------------------------------
void script_ingame_menu_load(Script *a1)
{
    Sprite *v1; // edi@3

    script_433640_init_script_ui(a1, SCRIPT_TYPE_INGAME_MENU_BUTTON, -92, 42, 2);
    if (script_434500(a1, INGAME_MENU_CONTROLS_MOBD_888, 0, 0))
    {
        script_trigger_event(a1, EVT_MSG_1509_stru11, 0, task_47C028);
        script_sleep(a1, 1);
    }
    v1 = a1->sprite;
    sprite_list_remove((Sprite *)a1->param);
    sprite_list_remove(v1);
    script_terminate(a1);
}

//----- (00433880) --------------------------------------------------------
void script_ingame_menu_save(Script *a1)
{
    Sprite *v1; // edi@3

    script_433640_init_script_ui(a1, SCRIPT_TYPE_INGAME_MENU_BUTTON, -92, 66, 3);
    if (script_434500(a1, INGAME_MENU_CONTROLS_MOBD_900, 0, 0))
    {
        script_trigger_event(a1, EVT_MSG_1507_stru11, 0, task_47C028);
        script_sleep(a1, 1);
    }
    v1 = a1->sprite;
    sprite_list_remove((Sprite *)a1->param);
    sprite_list_remove(v1);
    script_terminate(a1);
}

//----- (004338F0) --------------------------------------------------------
void script_ingame_menu_briefing(Script *a1)
{
    Sprite *v1; // edi@3

    script_433640_init_script_ui(a1, SCRIPT_TYPE_INGAME_MENU_BUTTON, -92, 90, 4);
    if (script_434500(a1, INGAME_MENU_CONTROLS_MOBD_852, 0, 0))
    {
        script_trigger_event(a1, EVT_MSG_1526_infiltrate, 0, task_47C028);
        script_sleep(a1, 1);
    }
    v1 = a1->sprite;
    sprite_list_remove((Sprite *)a1->param);
    sprite_list_remove(v1);
    script_terminate(a1);
}

//----- (004339F0) --------------------------------------------------------
void script_ingame_menu_restart(Script *a1)
{
    script_433640_init_script_ui(a1, SCRIPT_TYPE_INGAME_MENU_BUTTON, -92, 138, 6);
    if (script_434500(a1, INGAME_MENU_CONTROLS_MOBD_876, 0, 0))
    {
        script_trigger_event(a1, EVT_MSG_1527_restart_level, 0, task_47C028);
        script_sleep(a1, 1);
    }
    sprite_list_remove((Sprite *)a1->param);
    sprite_list_remove(a1->sprite);
    script_terminate(a1);
}


//----- (00433060) --------------------------------------------------------
void script_ingame_menu_master_script(Script *a1)
{
    Script *v1; // esi@1
    signed __int16 v2; // bp@1
    Sprite *v3; // edi@1
    DrawJob *v4; // ecx@1
    int v5; // eax@1
    ScriptEvent *i; // eax@7
    int v7; // edi@27
    ScriptEvent *j; // ebp@29
    Script *v9; // eax@33
    Sprite *v10; // eax@54
    Sprite *v11; // eax@56
    Sprite *v12; // eax@58
    Sprite *v13; // eax@60
    int v14; // [sp+10h] [bp-8h]@1
    Sprite *v15; // [sp+14h] [bp-4h]@1
    int a1a; // [sp+1Ch] [bp+4h]@5

    v1 = a1;
    v2 = 1;
    v3 = a1->sprite;
    task_47C028 = a1;
    a1->script_type = SCRIPT_TYPE_INGAME_MENU_MASTER_SCRIPT;
    v4 = v3->drawjob;
    v3->field_88_unused = 1;
    v5 = render_width;
    v3->field_88_unused = 1;
    LOBYTE_HEXRAYS(v5) = v5 & 0xFE;
    v3->y = 0x4000;
    v3->x = v5 << 7;
    v3->z_index = 1000;
    v4->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_4483E0_ui;
    a1->field_1C = 1;
    v14 = 0;
    v15 = v3;
    dword_47C030 = 0;
    script_4084A0_animation(a1);
    while (1)
    {
        if (single_player_game)
        {
            a1a = 0;
            is_async_execution_supported = 0;
            script_trigger_event(v1, EVT_MSG_1533, 0, game_cursor_script);
            sub_408460();
            sprite_load_mobd(v3, 60);
        }
        else
        {
            if (dword_47C030)
            {
                dword_47C030 = 0;
                script_trigger_event(v1, EVT_MSG_1533, 0, game_cursor_script);
                sprite_load_mobd(v3, 60);
            }
            a1a = 0;
            sub_408460();
        }
        do
        {
            script_yield_any_trigger(v1, 1);
            for (i = script_get_next_event(v1); i; i = script_get_next_event(v1))
            {
                if (i->event == EVT_MSG_1530_OPEN_GAME_MENU)
                {
                    a1a = 1;
                }
                else if (i->event == 1531)
                {
                    v14 = 1;
                }
                script_discard_event(i);
            }
            if (is_async_execution_supported)
                a1a = 1;
            if (v14)
                a1a = 0;
        } while (!a1a);
        if (single_player_game)
            break;
        if (!is_async_execution_supported)
        {
            script_trigger_event(v1, EVT_MSG_1532, 0, game_cursor_script);
            while (!is_async_execution_supported)
                script_sleep(v1, 1);
            if (dword_47050C == 1)
            {
                dword_47C030 = 1;
            LABEL_26:
                script_ingame_menu_create_dialog(v1);
                goto LABEL_27;
            }
        }
        dword_47C030 = 0;
    LABEL_27:
        _408410_dim_palette();
        v7 = 1;
        do
        {
            if (script_yield_any_trigger(v1, 1) & SCRIPT_FLAGS_20_EVENT_TRIGGER)
            {
                for (j = script_get_next_event(v1); j; j = script_get_next_event(v1))
                {
                    switch (j->event)
                    {
                    case EVT_MSG_1530_OPEN_GAME_MENU:
                        switch (v7)
                        {
                        case 5:
                            script_trigger_event_group(v1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_UI_SLIDER);
                            if (!_47C65C_render_string)
                                goto LABEL_45;
                            render_string_list_remove(_47C65C_render_string);
                            v9 = task_47C028;
                            if (v1 != task_47C028)
                                goto LABEL_46;
                            goto LABEL_47;
                        case 6:
                            script_trigger_event_group(v1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_UI_SLIDER);
                            sprite_list_remove((Sprite *)task_47C028->param);
                            v9 = task_47C028;
                            if (v1 != task_47C028)
                                goto LABEL_46;
                            goto LABEL_47;
                        case 7:
                            script_trigger_event_group(v1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_UI_SLIDER);
                            sprite_list_remove((Sprite *)task_47C028->param);
                            v9 = task_47C028;
                            if (v1 != task_47C028)
                                goto LABEL_46;
                            goto LABEL_47;
                        case 3:
                        case 4:
                            script_trigger_event_group(v1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_INGAME_MENU_YESNO);
                            if (!_47C65C_render_string)
                                goto LABEL_45;
                            render_string_list_remove(_47C65C_render_string);
                            _47C65C_render_string = 0;
                            if (v1 == task_47C028)
                                goto LABEL_47;
                            script_trigger_event(v1, EVT_MSG_1522_plan_building_construction, 0, task_47C028);
                            v7 = 1;
                            script_ingame_menu_create_dialog(v1);
                            goto LABEL_64;
                        case 2:
                            if (_47C65C_render_string)
                            {
                                render_string_list_remove(_47C65C_render_string);
                                _47C65C_render_string = 0;
                            }
                            script_trigger_event_group(v1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_UI_SLIDER);
                        LABEL_45:
                            v9 = task_47C028;
                            if (v1 != task_47C028)
                                LABEL_46:
                            script_trigger_event(v1, EVT_MSG_1522_plan_building_construction, 0, v9);
                            goto LABEL_47;
                        case 1:
                            goto LABEL_51;
                        default:
                            goto LABEL_64;
                        }
                    case EVT_MSG_1522_plan_building_construction:
                    LABEL_47:
                        v7 = 1;
                        script_ingame_menu_create_dialog(v1);
                        break;
                    case EVT_MSG_1531:
                        v14 = 1;
                        a1a = 0;
                        break;
                    case EVT_CMD_ENTITY_MOVE: // options
                        v7 = 2;
                        script_ingame_menu_create_options_dialog(v1);
                        break;
                    case EVT_MSG_1526_infiltrate: // briefing
                        v7 = 5;
                        script_ingame_menu_create_briefing_dialog(v1);
                        break;
                    case EVT_MSG_1528_cancel:
                    LABEL_51:
                        if (single_player_game || dword_47C030)
                            a1a = 0;
                        break;
                    case EVT_MSG_1527_restart_level: //restart level
                        v7 = 4;
                        script_trigger_event_group(v1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_INGAME_MENU_BUTTON);
                        _47C65C_render_string = render_string_create(
                            0,
                            currently_running_lvl_mobd[MOBD_FONT_ITALIC].items,
                            256,
                            96,
                            22,
                            8,
                            0x200003E9,
                            14,
                            5);
                        render_string_445AE0(_47C65C_render_string);
                        _47C65C_render_string->field_18 = 0;
                        _47C65C_render_string->num_lines = 0;
                        render_string_443D80(_47C65C_render_string, aAreYouSureYouW, 0);
                        v10 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1->sprite, script_ingame_menu_restart_yes, SCRIPT_COROUTINE, 0);
                        if (v10)
                            v10->script->field_1C = 1;
                        v11 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1->sprite, script_ingame_menu_restart_no, SCRIPT_COROUTINE, 0);
                        if (v11)
                            v11->script->field_1C = 1;
                        break;
                    case EVT_CMD_ENTITY_ATTACK: // quit to main menu
                        v7 = 3;
                        script_trigger_event_group(v1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_INGAME_MENU_BUTTON);
                        _47C65C_render_string = render_string_create(
                            0,
                            currently_running_lvl_mobd[MOBD_FONT_ITALIC].items,
                            256,
                            96,
                            22,
                            8,
                            0x200003E9,
                            14,
                            5);
                        render_string_445AE0(_47C65C_render_string);
                        _47C65C_render_string->field_18 = 0;
                        _47C65C_render_string->num_lines = 0;
                        render_string_443D80(_47C65C_render_string, aAreYouSureYo_0, 0);
                        v12 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1->sprite, script_ingame_menu_quit_yes, SCRIPT_COROUTINE, 0);
                        if (v12)
                            v12->script->field_1C = 1;
                        v13 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1->sprite, script_ingame_menu_quit_no, SCRIPT_COROUTINE, 0);
                        if (v13)
                            v13->script->field_1C = 1;
                        break;
                    case EVT_MSG_1509_stru11:
                        v7 = 6;
                        script_ingame_menu_create_load_dialog(v1);
                        break;
                    case EVT_MSG_1507_stru11:
                        v7 = 7;
                        script_ingame_menu_create_save_dialog(v1);
                        break;
                    default:
                        break;
                    }
                LABEL_64:
                    script_discard_event(j);
                }
                v2 = 1;
            }
            if (!is_async_execution_supported)
                a1a = 0;
        } while (a1a);
        script_trigger_event_group(v1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_INGAME_MENU_BUTTON);
        v3 = v15;
    }
    is_async_execution_supported = v2;
    script_trigger_event(v1, EVT_MSG_1532, 0, game_cursor_script);
    goto LABEL_26;
}


//----- (004321A0) --------------------------------------------------------
void script_ingame_menu_create_options_dialog(Script *a1)
{
    Sprite *v1; // esi@1
    Sprite *v2; // eax@1
    Sprite *v3; // eax@3
    Sprite *v6; // eax@5

    v1 = a1->sprite;
    dword_47C6C4 = 1;
    script_trigger_event_group(a1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_INGAME_MENU_BUTTON);
    _47C65C_render_string = render_string_create(
        0,
        currently_running_lvl_mobd[MOBD_FONT_ITALIC].items,
        248,
        88,
        22,
        8,
        0x200003E9,
        14,
        5);
    render_string_445AE0(_47C65C_render_string);
    _47C65C_render_string->field_18 = 0;
    _47C65C_render_string->num_lines = 0;
    render_string_443D80(_47C65C_render_string, " SFX VOLUME\n\n\n\nMUSIC VOLUME", 0);
    v2 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1, script_ingame_menu_options_done, SCRIPT_COROUTINE, 0);
    if (v2)
        v2->script->field_1C = 1;
    v3 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1, script_ingame_menu_options_volume_slider, SCRIPT_COROUTINE, 0);
    if (v3)
    {
        v3->script->field_1C = 1;
        v3->param = VOLUME_SLIDER_SFX;
        v3->x -= 50 * 256;
        v3->y += 72 * 256;
    }
    v6 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1, script_ingame_menu_options_volume_slider, SCRIPT_COROUTINE, 0);
    if (v6)
    {
        v6->script->field_1C = 1;
        v6->param = VOLUME_SLIDER_MUSIC;
        v6->x -= 50 * 256;
        v6->y += 140 * 256;
    }
    else
    {
        game_state = GAME_STATE::GAME_3_quit_mission;
    }
}


//----- (00433DB0) --------------------------------------------------------
void script_ingame_menu_options_done(Script *a1)
{
    Sprite *v1; // edi@6

    script_433640_init_script_ui(a1, SCRIPT_TYPE_UI_SLIDER, -200, 153, 3);
    script_sleep(a1, 2);
    dword_47C6C4 = 0;
    if (script_434500(a1, INGAME_MENU_CONTROLS_MOBD_756, 1, 0))
    {
        if (_47C65C_render_string)
        {
            render_string_list_remove(_47C65C_render_string);
            _47C65C_render_string = 0;
        }
        script_trigger_event_group(a1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_UI_SLIDER);
        if (a1 != task_47C028)
            script_trigger_event(a1, EVT_MSG_1522_plan_building_construction, 0, task_47C028);
    }
    v1 = a1->sprite;
    sprite_list_remove((Sprite *)a1->param);
    sprite_list_remove(v1);
    script_terminate(a1);
}



//----- (00431F10) --------------------------------------------------------
void script_ingame_menu_options_volume_slider(Script *a1)
{
    Sprite *v1; // edi@1
    Sprite *v2; // eax@1
    bool v5; // zf@4
    int v6; // eax@4
    ScriptEvent *i; // eax@9
    int v8; // edx@10
    int v9; // edx@13
    int v10; // eax@19
    int v11; // ecx@19
    void *v12; // ecx@22
    int v13; // eax@22
    int v14; // ecx@23
    __int64 v15; // rax@28
    int sound_volume; // eax@28
    int v17; // [sp+10h] [bp-10Ch]@1
    int v18; // [sp+14h] [bp-108h]@1
             //char name[260]; // [sp+18h] [bp-104h]@36

    v1 = a1->sprite;
    a1->script_type = SCRIPT_TYPE_UI_SLIDER;
    v18 = 0;
    v17 = 0;
    v1->drawjob->on_update_handler = (DrawJobUpdateHandler)drawjob_update_handler_4483E0_ui;
    v1->z_index += 768;
    sprite_load_mobd(v1, 36);

    // slider pimp
    v2 = sprite_create(MOBD_INGAME_MENU_CONTROLS, 0, 0);
    if (v2)
    {
        v2->drawjob->on_update_handler = (DrawJobUpdateHandler)drawjob_update_handler_4483E0_ui;
        sprite_load_mobd(v2, INGAME_MENU_CONTROLS_MOBD_SLIDER_PIMP);
        auto v4 = v1->param;
        if (v4 == VOLUME_SLIDER_UNKNOWN) {
            v2->x = v1->x + _4690B4_unk_volume;
        } else if (v4 == VOLUME_SLIDER_SFX) {
            v2->x = v1->x + ((_4690A8_sfx_volume << 7) / 16 << 8);
        } else if (v4 == VOLUME_SLIDER_MUSIC) {
            v2->x = v1->x + ((_4690AC_music_volume << 7) / 16 << 8);
        }
        else __debugbreak(); // error

        v2->y = v1->y;
        v2->z_index = v1->x + 256;
    }
    do
    {
        if (script_yield_any_trigger(a1, 1) & SCRIPT_FLAGS_20_EVENT_TRIGGER)
        {
            for (i = script_get_next_event(a1); i; i = script_get_next_event(a1))
            {
                v8 = i->event;
                if (v8 > (int)EVT_MSG_SELECTED)
                {
                    v9 = v8 - EVT_MSG_DESELECTED;
                    if (v9)
                    {
                        if (v9 == 16)
                            v18 = 1;
                    }
                    else
                    {
                        v17 = 0;
                    }
                }
                else if (v8 == EVT_MSG_SELECTED)
                {
                    v17 = 1;
                }
                script_discard_event(i);
            }
        }
        if (v17)
        {
            game_cursor_script->sprite->field_88_unused = 1;
            v10 = game_cursor_script->sprite->x;
            v2->x = v10;
            v11 = v1->x;
            if (v10 < v11 || (v11 += 0x8000, v10 > v11))
                v2->x = v11;
            v12 = v1->param;
            v13 = v2->x;
            if (v12 == VOLUME_SLIDER_UNKNOWN)
            {
                _4690B4_unk_volume = v13 - v1->x;
                v14 = 32 - (_4690B4_unk_volume >> 8) / 4;
                if (v14 < 1)
                    v14 = 1;
                if (v14 >= 32)
                    LOWORD_HEXRAYS(v14) = 32;
                input_428470(v14);
            }
            else
            {
                v15 = 16 * ((v13 - v1->x) >> 8);
                sound_volume = ((BYTE4(v15) & 0x7F) + (int)v15) >> 7;
                if (v12 == VOLUME_SLIDER_SFX)
                {
                    _4690A8_sfx_volume = sound_volume;
                }
                else
                {
                    _4690AC_music_volume = sound_volume;
                    if (sound_volume)
                    {
                        goto LABEL_44;
                    }
                    if (_4690B0_sound_volume_previous && _47C5D4_sound_threaded_snd_id)
                    {
                        sound_stop(_47C5D4_sound_threaded_snd_id);
                        sound_volume = _4690AC_music_volume;
                    }
                    if (sound_volume)
                    {
                    LABEL_44:
                        if (!_4690B0_sound_volume_previous)
                        {
                            sound_play_threaded(levels[current_level_idx].wav_filename, 1, _4690AC_music_volume, 16, 0);
                            sound_volume = _4690AC_music_volume;
                        }
                        if (sound_volume) // sound volume in ingame menu
                        {
                            sound_threaded_set_volume(sound_volume);
                            sound_volume = _4690AC_music_volume;
                        }
                    }
                    _4690B0_sound_volume_previous = sound_volume;
                }
            }
        }
    } while (!v18);
    sprite_list_remove(v2);
    sprite_list_remove(v1);
    script_terminate(a1);
}



//----- (00433C30) --------------------------------------------------------
void script_ingame_menu_restart_yes(Script *a1)
{
    Sprite *v1; // edi@3

    script_433640_init_script_ui(a1, SCRIPT_TYPE_INGAME_MENU_YESNO, -90, 120, 1);
    if (script_434500(a1, INGAME_MENU_CONTROLS_MOBD_YESNO_YES, 1, 0))
        game_state = GAME_STATE::GAME_2_restart_mission;
    v1 = a1->sprite;
    sprite_list_remove((Sprite *)a1->param);
    sprite_list_remove(v1);
    script_terminate(a1);
}

//----- (00433C90) --------------------------------------------------------
void script_ingame_menu_restart_no(Script *a1)
{
    Sprite *v1; // edi@6

    script_433640_init_script_ui(a1, SCRIPT_TYPE_INGAME_MENU_YESNO, 0, 120, 1);
    if (script_434500(a1, INGAME_MENU_CONTROLS_MOBD_YESNO_NO, 1, 0))
    {
        script_trigger_event_group(0, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_INGAME_MENU_YESNO);
        if (_47C65C_render_string)
        {
            render_string_list_remove(_47C65C_render_string);
            _47C65C_render_string = 0;
        }
        if (task_47C028)
            script_trigger_event(0, EVT_MSG_1522_plan_building_construction, 0, task_47C028);
    }
    v1 = a1->sprite;
    sprite_list_remove((Sprite *)a1->param);
    sprite_list_remove(v1);
    script_terminate(a1);
}



//----- (00433AF0) --------------------------------------------------------
void script_ingame_menu_quit_yes(Script *a1)
{
    Sprite *v1; // edi@7

    script_433640_init_script_ui(a1, SCRIPT_TYPE_INGAME_MENU_YESNO, -90, 120, 1);
    if (script_434500(a1, INGAME_MENU_CONTROLS_MOBD_YESNO_YES, 1, 0))
    {
        if (!single_player_game)
        {
            if (netz_468B50_available_units_denom <= 2)
                *(_DWORD *)&netz_47A740[2].str_0[0] = 1;
            netz_449FF0();
            is_async_execution_supported = 0;
            dword_47C030 = -1;
            dword_47050C = -1;
            dword_47A738 = 0;
            dword_47CB14 = -1;
            dword_47A180 = 6;
        }
        script_408500_anim(a1);
        script_47A3CC_die();
        game_state = GAME_STATE::GAME_3_quit_mission;
    }
    v1 = a1->sprite;
    sprite_list_remove((Sprite *)a1->param);
    sprite_list_remove(v1);
    script_terminate(a1);
}

//----- (00433BA0) --------------------------------------------------------
void script_ingame_menu_quit_no(Script *a1)
{
    Sprite *v1; // edi@6

    script_433640_init_script_ui(a1, SCRIPT_TYPE_INGAME_MENU_YESNO, 0, 120, 1);
    if (script_434500(a1, INGAME_MENU_CONTROLS_MOBD_YESNO_NO, 1, 0))
    {
        script_trigger_event_group(0, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_INGAME_MENU_YESNO);
        if (_47C65C_render_string)
        {
            render_string_list_remove(_47C65C_render_string);
            _47C65C_render_string = 0;
        }
        if (task_47C028)
            script_trigger_event(0, EVT_MSG_1522_plan_building_construction, 0, task_47C028);
    }
    v1 = a1->sprite;
    sprite_list_remove((Sprite *)a1->param);
    sprite_list_remove(v1);
    script_terminate(a1);
}


//----- (00432730) --------------------------------------------------------
void script_ingame_menu_savegame_list_line(Script *a1)
{
    Script *v1; // edi@1
    Sprite *v2; // ebp@1
    int v3; // ebx@2
    int v4; // esi@2
    ScriptEvent *v5; // eax@3
    enum SCRIPT_EVENT v6; // ecx@4

    v1 = a1;
    v2 = a1->sprite;
    a1 = (Script *)a1->param;
    v2->drawjob->on_update_handler = (DrawUpdateHandler)drawjob_update_handler_4483E0_ui;
    sprite_load_mobd(v2, 696);
    _47C668_ingame_menu_sprites[(int)a1] = v1->sprite;
    while (1)
    {
        v3 = 0;
        v4 = 0;
        do
        {
            script_wait_event(v1);
            v5 = script_get_next_event(v1);
            if (v5)
            {
                while (1)
                {
                    v6 = v5->event;
                    if (v6 != EVT_MOUSE_HOVER)
                    {
                        if (v6 == EVT_MSG_SELECTED)
                            goto LABEL_8;
                        if (v6 == EVT_MSG_1528_cancel)
                            break;
                    }
                LABEL_9:
                    script_discard_event(v5);
                    v5 = script_get_next_event(v1);
                    if (!v5)
                        goto LABEL_10;
                }
                v3 = 1;
            LABEL_8:
                v4 = 1;
                goto LABEL_9;
            }
        LABEL_10:
            ;
        } while (!v4);
        if (v3)
            break;
        script_trigger_event(v1, EVT_MSG_SELECTED, &a1, receiver);
    }
    _47C668_ingame_menu_sprites[(int)a1] = 0;
    sprite_list_remove(v2);
    script_terminate(v1);
}
