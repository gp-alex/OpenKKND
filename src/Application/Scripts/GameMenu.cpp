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