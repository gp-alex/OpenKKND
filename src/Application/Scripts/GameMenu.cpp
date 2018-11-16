#include "src/Application/Scripts/GameMenu.h"

#include "src/_unsorted_data.h"
#include "src/_unsorted_functions.h"
#include "src/Cursor.h"
#include "src/RenderDrawHandlers.h"
#include "src/Script.h"
#include "src/ScriptEvent.h"
#include "src/Sprite.h"


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
    script_trigger_event_group(a1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_DA000002);
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
        v7->drawjob->on_update_handler = (DrawUpdateHandler)drawjob_update_handler_4483E0_sidebar;
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
    script_ingame_menu_saveload(a1, 0, true);
}

//----- (00432F20) --------------------------------------------------------
void script_ingame_menu_load_game_list(Script *a1)
{
    script_ingame_menu_saveload(a1, 0, false);
}


//----- (00433E60) --------------------------------------------------------
void script_ingame_menu_save_game_save(Script *a1)
{
    _438630_read_save_lst();
    script_433640(a1, SCRIPT_TYPE_DA000001, -80, 153, 3);
    while (true)
    {
        if (!script_434500(a1, CURSOR_MOBD_OFFSET_UPGRADE_5_RUNNING, 1, 0)) {
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
    script_433640(a1, SCRIPT_TYPE_DA000001, -180, 153, 3);
    while (true)
    {
        bool res = script_434500(a1, CURSOR_MOBD_OFFSET_744, 2, 0);
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
    script_433640(a1, SCRIPT_TYPE_DA000001, -130, 153, 3);
    while (true)
    {
        bool res = script_434500(a1, CURSOR_MOBD_OFFSET_UPGRADE_3_STILL, 2, 0);
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
    script_433640(a1, SCRIPT_TYPE_DA000001, 0, 153, 3);
    if (script_434500(a1, CURSOR_MOBD_OFFSET_816, 1, 0))
    {
        script_trigger_event_group(a1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_DA000001);
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
    script_433640(a1, SCRIPT_TYPE_DA000001, -80, 153, 3);
    while (true)
    {
        if (!script_434500(a1, CURSOR_MOBD_OFFSET_UPGRADE_5_FLASHING, 1, 0)) {
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
    script_433640(a1, SCRIPT_TYPE_DA000001, -180, 153, 3);
    while (true)
    {
        bool res = script_434500(a1, CURSOR_MOBD_OFFSET_744, 2, 0);
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
    script_433640(a1, SCRIPT_TYPE_DA000001, -130, 153, 3);
    while (true)
    {
        bool res = script_434500(a1, CURSOR_MOBD_OFFSET_UPGRADE_3_STILL, 2, 0);
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
    script_433640(a1, SCRIPT_TYPE_DA000001, 0, 153, 3);
    if (script_434500(a1, CURSOR_MOBD_OFFSET_816, 1, 0))
    {
        script_trigger_event_group(a1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_DA000001);
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

    script_trigger_event_group(a1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_DA000002);
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
        v6->drawjob->on_update_handler = (DrawUpdateHandler)drawjob_update_handler_4483E0_sidebar;
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
    script_433640(a1, SCRIPT_TYPE_DA000002, -92, v1, 1);
    if (script_434500(a1, CURSOR_MOBD_OFFSET_MISSION_ARROW_SW, 0, 0))
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
    script_433640(a1, SCRIPT_TYPE_DA000002, -92, v1, 7);
    if (script_434500(a1, CURSOR_MOBD_OFFSET_828, 0, 0))
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
    script_433640(a1, SCRIPT_TYPE_DA000002, -92, v1, 5);
    if (script_434500(a1, CURSOR_MOBD_OFFSET_BORDERLESS_CURSOR, 0, 0))
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
void script_ingame_menu_mission_briefing(Script *script)
{
    Script *temp_script_1; // esi@1
    RenderString *render_string; // eax@1
    int num_lines; // edi@2
    int v4; // ebp@2
    char *current_mission_briefing; // esi@4
    int counter; // ecx@8
    char current_letter; // al@9
    Sprite *sprite; // eax@21
    int loop_counter; // [sp+10h] [bp-6Ch]@6
    Script *temp_script_2; // [sp+14h] [bp-68h]@1
    char text_line[512]; // [sp+18h] [bp-64h]@11

    temp_script_1 = script;
    temp_script_2 = script;
    script_trigger_event_group(script, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_DA000002);
    render_string = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 120, 70, 42, 15, 0x200003E9, 14, 5);
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
        temp_script_1 = temp_script_2;
    }
    sprite = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, temp_script_1->sprite, script_433D20_ingame_menu, SCRIPT_COROUTINE, 0);
    if (sprite)
        sprite->script->field_1C = 1;
    sprite_load_mobd(task_47C028->sprite, 12);
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

    script_433640(a1, SCRIPT_TYPE_DA000002, -92, 42, 2);
    if (script_434500(a1, CURSOR_MOBD_OFFSET_888, 0, 0))
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

    script_433640(a1, SCRIPT_TYPE_DA000002, -92, 66, 3);
    if (script_434500(a1, CURSOR_MOBD_OFFSET_900, 0, 0))
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

    script_433640(a1, SCRIPT_TYPE_DA000002, -92, 90, 4);
    if (script_434500(a1, CURSOR_MOBD_OFFSET_MISSION_ARROW_S_BLINK, 0, 0))
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
    Sprite *v1; // edi@3

    script_433640(a1, SCRIPT_TYPE_DA000002, -92, 138, 6);
    if (script_434500(a1, CURSOR_MOBD_OFFSET_876, 0, 0))
    {
        script_trigger_event(a1, EVT_MSG_1527, 0, task_47C028);
        script_sleep(a1, 1);
    }
    v1 = a1->sprite;
    sprite_list_remove((Sprite *)a1->param);
    sprite_list_remove(v1);
    script_terminate(a1);
}
