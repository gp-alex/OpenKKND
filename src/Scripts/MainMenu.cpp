#include "src/kknd.h"

#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"


//----- (0043C0E0) --------------------------------------------------------
void script_mobd79_evt1__main_menu_new_game(Script *a1)
{
    Sprite *v1; // esi@1
    Sprite *v2; // eax@1
    Sprite *v3; // edi@3
    Sprite *v4; // esi@3
    stru29 *v5; // eax@3
    stru29 *v6; // eax@9
    int v7; // ecx@10
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
        v5 = stru29_list_47C610;
        if ((stru29 **)stru29_list_47C610 != &stru29_list_47C610)
        {
            while (v5->sprite != v3)
            {
                v5 = v5->next;
                if ((stru29 **)v5 == &stru29_list_47C610)
                    goto LABEL_8;
            }
            v5->field_C |= 1u;
        }
    LABEL_8:
        script_443380(a1, 464, 0);
        v3->drawjob->flags &= 0xBFFFFFFF;
        v4->drawjob->flags &= 0xBFFFFFFF;
        v4->pstru7 = _4640E0_stru7_array;
    }
    netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
    netz_47C6C0_mapd_idx = 2;
    script_408500_anim(a1);
    stru29_list_remove_all(a1);
    _47C6D4_stru29 = 0;
    v6 = (stru29 *)malloc(0x1E0u);
    stru29_list = v6;
    if (v6)
    {
        stru29_list_free_pool = v6;
        v7 = 0;
        do
        {
            v6[v7].next = &v6[v7 + 1];
            v6 = stru29_list;
            ++v7;
        } while (v7 < 29);
        stru29_list[29].next = 0;
        stru29_list_47C610 = (stru29 *)&stru29_list_47C610;
        stru29_list_47C614 = (stru29 *)&stru29_list_47C610;
        stru29_list_initialized = 1;
    }
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
    stru29 *v5; // eax@3

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
        script_trigger_event_group(a1, EVT_MSG_1546, 0, SCRIPT_TYPE_1);
        script_432510_ingame_menu_create_sprites(a1);
        v3 = a1->sprite;
        v4 = v3->parent;
        v3->drawjob->flags |= 0x40000000u;
        v4->drawjob->flags |= 0x40000000u;
        v4->pstru7 = &_479D48_stru7;
        v5 = stru29_list_47C610;
        if ((stru29 **)stru29_list_47C610 != &stru29_list_47C610)
        {
            while (v5->sprite != v3)
            {
                v5 = v5->next;
                if ((stru29 **)v5 == &stru29_list_47C610)
                    goto LABEL_8;
            }
            v5->field_C |= 1u;
        }
    LABEL_8:
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
    stru29 *v5; // eax@3
    stru29 *v6; // eax@9
    int v7; // ecx@10
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
        v5 = stru29_list_47C610;
        if ((stru29 **)stru29_list_47C610 != &stru29_list_47C610)
        {
            while (v5->sprite != v3)
            {
                v5 = v5->next;
                if ((stru29 **)v5 == &stru29_list_47C610)
                    goto LABEL_8;
            }
            v5->field_C |= 1u;
        }
    LABEL_8:
        script_443380(a1, 464, 0);
        v3->drawjob->flags &= 0xBFFFFFFF;
        v4->drawjob->flags &= 0xBFFFFFFF;
        v4->pstru7 = _4640E0_stru7_array;
    }
    _4240E0_kknd_sve_read(pKknd_sve);
    netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
    netz_47C6C0_mapd_idx = 11;
    script_408500_anim(a1);
    stru29_list_remove_all(a1);
    _47C6D4_stru29 = 0;
    v6 = (stru29 *)malloc(0x1E0u);
    stru29_list = v6;
    if (v6)
    {
        stru29_list_free_pool = v6;
        v7 = 0;
        do
        {
            v6[v7].next = &v6[v7 + 1];
            v6 = stru29_list;
            ++v7;
        } while (v7 < 29);
        stru29_list[29].next = 0;
        stru29_list_47C610 = (stru29 *)&stru29_list_47C610;
        stru29_list_47C614 = (stru29 *)&stru29_list_47C610;
        stru29_list_initialized = 1;
    }
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
    stru29 *v5; // eax@3
    stru29 *v6; // eax@9
    int v7; // ecx@10
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
        v5 = stru29_list_47C610;
        if ((stru29 **)stru29_list_47C610 != &stru29_list_47C610)
        {
            while (v5->sprite != v3)
            {
                v5 = v5->next;
                if ((stru29 **)v5 == &stru29_list_47C610)
                    goto LABEL_8;
            }
            v5->field_C |= 1u;
        }
    LABEL_8:
        script_443380(a1, 464, 0);
        v3->drawjob->flags &= 0xBFFFFFFF;
        v4->drawjob->flags &= 0xBFFFFFFF;
        v4->pstru7 = _4640E0_stru7_array;
    }
    netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
    netz_47C6C0_mapd_idx = 1;
    script_408500_anim(a1);
    stru29_list_remove_all(a1);
    _47C6D4_stru29 = 0;
    v6 = (stru29 *)malloc(0x1E0u);
    stru29_list = v6;
    if (v6)
    {
        stru29_list_free_pool = v6;
        v7 = 0;
        do
        {
            v6[v7].next = &v6[v7 + 1];
            v6 = stru29_list;
            ++v7;
        } while (v7 < 29);
        stru29_list[29].next = 0;
        stru29_list_47C610 = (stru29 *)&stru29_list_47C610;
        stru29_list_47C614 = (stru29 *)&stru29_list_47C610;
        stru29_list_initialized = 1;
    }
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
    stru29 *v5; // eax@3
    stru29 *v6; // eax@9
    int v7; // ecx@10
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
        v5 = stru29_list_47C610;
        if ((stru29 **)stru29_list_47C610 != &stru29_list_47C610)
        {
            while (v5->sprite != v3)
            {
                v5 = v5->next;
                if ((stru29 **)v5 == &stru29_list_47C610)
                    goto LABEL_8;
            }
            v5->field_C |= 1u;
        }
    LABEL_8:
        script_443380(a1, 464, 0);
        v3->drawjob->flags &= 0xBFFFFFFF;
        v4->drawjob->flags &= 0xBFFFFFFF;
        v4->pstru7 = _4640E0_stru7_array;
    }
    netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
    netz_47C6C0_mapd_idx = 14;
    script_408500_anim(a1);
    stru29_list_remove_all(a1);
    _47C6D4_stru29 = 0;
    v6 = (stru29 *)malloc(0x1E0u);
    stru29_list = v6;
    if (v6)
    {
        stru29_list_free_pool = v6;
        v7 = 0;
        do
        {
            v6[v7].next = &v6[v7 + 1];
            v6 = stru29_list;
            ++v7;
        } while (v7 < 29);
        stru29_list[29].next = 0;
        stru29_list_47C610 = (stru29 *)&stru29_list_47C610;
        stru29_list_47C614 = (stru29 *)&stru29_list_47C610;
        stru29_list_initialized = 1;
    }
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
    stru29 *v5; // eax@3
    stru29 *v6; // eax@9
    int v7; // ecx@10
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
        v5 = stru29_list_47C610;
        if ((stru29 **)stru29_list_47C610 != &stru29_list_47C610)
        {
            while (v5->sprite != v3)
            {
                v5 = v5->next;
                if ((stru29 **)v5 == &stru29_list_47C610)
                    goto LABEL_8;
            }
            v5->field_C |= 1u;
        }
    LABEL_8:
        script_443380(a1, 464, 0);
        v3->drawjob->flags &= 0xBFFFFFFF;
        v4->drawjob->flags &= 0xBFFFFFFF;
        v4->pstru7 = _4640E0_stru7_array;
    }
    netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
    netz_47C6C0_mapd_idx = 15;
    script_408500_anim(a1);
    stru29_list_remove_all(a1);
    _47C6D4_stru29 = 0;
    v6 = (stru29 *)malloc(0x1E0u);
    stru29_list = v6;
    if (v6)
    {
        stru29_list_free_pool = v6;
        v7 = 0;
        do
        {
            v6[v7].next = &v6[v7 + 1];
            v6 = stru29_list;
            ++v7;
        } while (v7 < 29);
        stru29_list[29].next = 0;
        stru29_list_47C610 = (stru29 *)&stru29_list_47C610;
        stru29_list_47C614 = (stru29 *)&stru29_list_47C610;
        stru29_list_initialized = 1;
    }
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
    stru29 *v5; // eax@3

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
        v5 = stru29_list_47C610;
        if ((stru29 **)stru29_list_47C610 != &stru29_list_47C610)
        {
            while (v5->sprite != v3)
            {
                v5 = v5->next;
                if ((stru29 **)v5 == &stru29_list_47C610)
                    goto LABEL_8;
            }
            v5->field_C |= 1u;
        }
    LABEL_8:
        script_443380(a1, 464, 0);
        v3->drawjob->flags &= 0xBFFFFFFF;
        v4->drawjob->flags &= 0xBFFFFFFF;
        v4->pstru7 = _4640E0_stru7_array;
    }
    script_408500_anim(a1);
    stru29_list_remove_all(a1);
    game_state = 3;
}