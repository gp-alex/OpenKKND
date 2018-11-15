#include "src/Sidebar.h"

#include "src/kknd.h"
#include "src/kknd.cpp"



//----- (004469F0) --------------------------------------------------------
bool sidebar_initialize()
{
    ProductionOption *v0; // eax@1
    int v1; // ecx@2
    ProductionGroup *v2; // eax@4
    int v3; // ecx@5
    ProductionGroup *v4; // eax@7
    ProductionOption *v5; // ecx@8
    Sidebar *v6; // eax@9
    int v7; // esi@9
    SidebarButton *v8; // eax@17
    int v9; // edx@17
    SidebarButton *v10; // eax@17
    int v11; // edx@17
    SidebarButton *v12; // eax@17
    int v13; // edx@17
    SidebarButton *v14; // eax@17
    int v15; // edx@17
    SidebarButton *v16; // eax@17
    int v17; // edx@17
    SidebarButton *v18; // eax@17
    int v19; // edx@17
    SidebarButton *v20; // eax@17
    int v21; // edx@17
    Sprite *v22; // eax@18
    Sprite *v23; // eax@21

    memset(&game_globals_per_player, 0, sizeof(game_globals_per_player));
    v0 = (ProductionOption *)malloc(0x3000u);
    production_option_list = v0;
    if (!v0)
        return 0;
    production_option_list_free_pool = v0;
    v1 = 0;
    do
    {
        v0[v1].next = &v0[v1 + 1];
        v0 = production_option_list;
        ++v1;
    } while (v1 < 255);
    production_option_list[255].next = 0;
    production_option_list_47C9C8 = (ProductionOption *)&production_option_list_47C9C8;
    production_option_list_47C9CC = (ProductionOption *)&production_option_list_47C9C8;
    v2 = (ProductionGroup *)malloc(0x980u);
    production_group_list = v2;
    if (!v2)
        return 0;
    production_group_free_pool = v2;
    v3 = 0;
    do
    {
        v2[v3].next = &v2[v3 + 1];
        v2 = production_group_list;
        ++v3;
    } while (v3 < 31);
    production_group_list[31].next = 0;
    _47C990_production.sidebar_open_mask[PRODUCTION_GROUP_INFANTRY] = 0;
    _47C990_production.sidebar_open_mask[PRODUCTION_GROUP_VEHICLES] = 0;
    _47C990_production.sidebar_open_mask[PRODUCTION_GROUP_BUILDINGS] = 0;
    _47C990_production.sidebar_open_mask[PRODUCTION_GROUP_TOWERS] = 0;
    _47C990_production.sidebar_open_mask[PRODUCTION_GROUP_AIRCRAFT] = 0;

    _47C978_production.sidebar_open_mask[PRODUCTION_GROUP_INFANTRY] = 0;
    _47C978_production.sidebar_open_mask[PRODUCTION_GROUP_VEHICLES] = 0;
    _47C978_production.sidebar_open_mask[PRODUCTION_GROUP_BUILDINGS] = 0;
    _47C978_production.sidebar_open_mask[PRODUCTION_GROUP_TOWERS] = 0;
    _47C978_production.sidebar_open_mask[PRODUCTION_GROUP_AIRCRAFT] = 0;
    _47C978_production.sidebar_open_mask[PRODUCTION_GROUP_BLACKSMITH] = 0;

    production_group_list_47C918 = (ProductionGroup *)&production_group_list_47C918;
    production_group_list_47C91C = (ProductionGroup *)&production_group_list_47C918;

    //v4 = (ProductionGroup *) & _47C798_infantry_production_group_first;
    //do
    for (int i = PRODUCTION_GROUP_INFANTRY; i <= PRODUCTION_GROUP_AIRCRAFT; ++i)
    {
        v4 = ProductionGroupAccessor((PRODUCTION_GROUP_ID)i);
        v4->prev = v4;
        v5 = (ProductionOption *)&v4->next_option;
        v4->next = v4;
        v4->prev_option = (ProductionOption *)&v4->next_option;
        v5->next = v5;
    }
    //while ((int)v4 < (int) & _47C914_sidebar);
    v6 = sidebar_list_create(0, 0, 288, 0, 0);
    v7 = 0;
    _47C914_sidebar = v6;
    if (_47C6D8_use__466098_cost_multipliers)
    {
        if (_47C658_faction_index)
            goto LABEL_16;
    }
    else if (single_player_game)
    {
        if (player_side == 2)
            goto LABEL_16;
    }
    else if (netz_47A740[player_side + 1].field_A)
    {
    LABEL_16:
        v7 = 11;
        goto LABEL_17;
    }
LABEL_17:
    sidebar_add_button_2(
        v6,
        _4704A8_per_sidebar_button_mobd_lookup_table_offsets[4 * v7 / 0x2Cu][0],
        sidebar_button_handler_cash_open,
        sidebar_button_handler_cash_close,
        (void *)0xFFFFFFFF);
    v8 = sidebar_add_button_2(
        _47C914_sidebar,
        _4704A8_per_sidebar_button_mobd_lookup_table_offsets[4 * v7 / 0x2Cu][1],
        sidebar_button_handler_minimap_open,
        sidebar_button_handler_minimap_close,
        (void *)0xFFFFFFFE);
    v9 = _4704A8_per_sidebar_button_mobd_lookup_table_offsets[4 * v7 / 0x2Cu][2];
    _47CA10_sidebar_button_minimap = v8;
    sidebar_add_button_1(_47C914_sidebar, v9, sidebar_button_handler_options_open, 0, (void *)0xFFFFFFFD);
    v10 = sidebar_add_button_3(
        _47C914_sidebar,
        _4704A8_per_sidebar_button_mobd_lookup_table_offsets[4 * v7 / 0x2Cu][3],
        sidebar_button_handler_help_open,
        sidebar_button_handler_help_close,
        (void *)0xFFFFFFFC);
    v11 = _4704A8_per_sidebar_button_mobd_lookup_table_offsets[4 * v7 / 0x2Cu][4];
    _47CA08_sidebar_buttons[0] = v10;
    v12 = sidebar_add_button_2(
        _47C914_sidebar,
        v11,
        sidebar_button_handler_infantry_open,
        sidebar_button_handler_infantry_close,
        (void *)0xFFFFFFFB);
    v13 = _4704A8_per_sidebar_button_mobd_lookup_table_offsets[4 * v7 / 0x2Cu][5];
    _47CA18_sidebar_production_buttons[0] = v12;
    v14 = sidebar_add_button_2(
        _47C914_sidebar,
        v13,
        sidebar_button_handler_vehicles_open,
        sidebar_button_handler_vehicles_close,
        (void *)0xFFFFFFFA);
    v15 = _4704A8_per_sidebar_button_mobd_lookup_table_offsets[4 * v7 / 0x2Cu][6];
    _47CA18_sidebar_production_buttons[1] = v14;
    v16 = sidebar_add_button_2(
        _47C914_sidebar,
        v15,
        sidebar_button_handler_buildings_open,
        sidebar_button_handler_buildings_close,
        (void *)0xFFFFFFF9);
    v17 = _4704A8_per_sidebar_button_mobd_lookup_table_offsets[4 * v7 / 0x2Cu][7];
    _47CA18_sidebar_production_buttons[2] = v16;
    v18 = sidebar_add_button_2(
        _47C914_sidebar,
        v17,
        sidebar_button_handler_towers_open,
        sidebar_button_handler_towers_close,
        (void *)0xFFFFFFF8);
    v19 = _4704A8_per_sidebar_button_mobd_lookup_table_offsets[4 * v7 / 0x2Cu][8];
    _47CA18_sidebar_production_buttons[3] = v18;
    v20 = sidebar_add_button_2(
        _47C914_sidebar,
        v19,
        sidebar_button_handler_airstrike_open,
        sidebar_button_handler_airstrike_close,
        (void *)0xFFFFFFF7);
    v21 = _4704A8_per_sidebar_button_mobd_lookup_table_offsets[4 * v7 / 0x2Cu][9];
    _47CA18_sidebar_production_buttons[4] = v20;
    _47CA08_sidebar_buttons[1] = sidebar_add_button_3(
        0,
        v21,
        sidebar_button_handler_446190_open,
        sidebar_button_handler_4461E0_close,
        (void *)0xFFFFFFF6);
    _47CA2C_should_airstrike_mess_with_sidebar = 0;
    if (!is_game_loading())
    {
        v22 = sprite_create_scripted(MOBD_SIDEBAR_BUTTONS, 0, script_401C30_sidebar, SCRIPT_FUNCTION, 0);
        if (v22)
            _47C970_sidebar_task = v22->script;
        else
            _47C970_sidebar_task = 0;
    }
    v23 = sprite_create(MOBD_INGAME_MENU_CONTROLS, 0, 0);
    _47C96C_mobd_1F_sidebar_empty_blocks = v23;
    if (v23)
    {
        v23->drawjob->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_4483E0_sidebar;
        sprite_load_mobd(_47C96C_mobd_1F_sidebar_empty_blocks, 72);
        _47C96C_mobd_1F_sidebar_empty_blocks->field_88_unused = 1;
        _47C96C_mobd_1F_sidebar_empty_blocks->x = (render_width - 32) << 8;
        _47C96C_mobd_1F_sidebar_empty_blocks->field_88_unused = 1;
        _47C96C_mobd_1F_sidebar_empty_blocks->y = 0x10000;
        _47C96C_mobd_1F_sidebar_empty_blocks->z_index = 0;
    }
    return 1;
}


//----- (00446D60) --------------------------------------------------------
void sidebar_button_handler_cash_open(SidebarButton *a1)
{
    SidebarButton *v1; // esi@1
    int v2; // edi@1
    int v3; // eax@1

    v1 = a1;
    v2 = _445C00_text(asc_470198, 12);
    v3 = _445C80_text(asc_470198, 12);
    v1->sprite->field_88_unused = 1;
    _47CA00_render_string = render_string_create(
        0,
        currently_running_lvl_mobd[MOBD_FONT_27].items,
        (v1->sprite->x >> 8) - (8 * v3 + 24),
        v1->sprite->y >> 8,
        v3 + 2,
        v2 + 2,
        0x40000000,
        8,
        8);
    v1->param = _47CA00_render_string;
}

//----- (00446DE0) --------------------------------------------------------
void sidebar_button_handler_cash_close(SidebarButton *a1)
{
    render_string_list_remove((RenderString *)a1->param);
    _47CA00_render_string = 0;
}

//----- (00446E00) --------------------------------------------------------
void sidebar_button_handler_help_open(SidebarButton *a1)
{
    SidebarButton **v1; // esi@1

    v1 = _47CA08_sidebar_buttons;
    do
    {
        if (v1 != _47CA08_sidebar_buttons)
            script_trigger_event(0, EVT_MSG_DESELECTED, 0, (*v1)->task);
        ++v1;
    } while ((int)v1 < (int)& _47CA10_sidebar_button_minimap);
    script_trigger_event(0, EVT_MSG_SHOW_UNIT_HINT, 0, game_cursor_script);
}

//----- (00446E50) --------------------------------------------------------
void sidebar_button_handler_help_close(SidebarButton *a1)
{
    script_trigger_event(0, EVT_MSG_1516, 0, game_cursor_script);
}

//----- (00445DA0) --------------------------------------------------------
void sidebar_button_handler_infantry_open(SidebarButton *a1)
{
    ProductionGroup *v1; // edi@1
    int v3; // ebp@6
    Sprite *v4; // eax@8
    int v5; // ecx@9
    ProductionOption *i; // esi@10

    sidebar_close_all();

    //v1 = _47C79C_infantry_production_group_last;
    v1 = ProductionGroupAccessor(PRODUCTION_GROUP_INFANTRY)->prev;
    if (v1 != (ProductionGroup *)&_47C798_infantry_pg)
    {
        v3 = 256;
        do
        {
            v1->sidebar = sidebar_list_create(0, 0, v3, 128, 0);
            if (!v1->sprite)
            {
                v4 = sprite_create(MOBD_SIDEBAR_BUTTONS, 0, v1->sidebar->sprite);
                if (v4)
                {
                    v1->sprite = v4;
                    v4->drawjob->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_4483E0_sidebar;
                    v5 = v4->y;
                    v4->field_88_unused = 1;
                    v4->y = v5 - 1024;
                    v4->z_index = 3;
                    sprite_load_mobd(
                        v4,
                        _4701B8_mobd_lookups_per_ProductionGroup_field44[2 * v1->_44_mobd_lookup_idx + 1]);
                }
            }
            for (i = v1->prev_option; (ProductionOption **)i != &v1->next_option; i = i->prev)
                sidebar_add_button_4(
                    v1->sidebar,
                    i->mobd_lookup_table_offset,
                    sidebar_button_handler_order_unit_click,
                    (int)&i->_14_pcost,
                    i->cost,
                    i,
                    i->unit_id);
            v1 = v1->prev;
            v3 -= 32;
        } while (v1 != (ProductionGroup *)&_47C798_infantry_pg);
    }
    _47C990_production.sidebar_open_mask[PRODUCTION_GROUP_INFANTRY] = 1;
}

//----- (00445F00) --------------------------------------------------------
void sidebar_button_handler_infantry_close(SidebarButton *a1)
{
    //ProductionGroup *i; // esi@1
    //Sprite *v2; // ecx@3

    //for (i = &_47C798_infantry_pg;
    //    i->next != (ProductionGroup *)&_47C798_infantry_pg;
    //    i = i->next)
    //{
    //    if (i->sidebar)
    //    {
    //        v2 = i->sprite;
    //        if (v2)
    //        {
    //            sprite_list_remove(v2);
    //            i->sprite = 0;
    //        }
    //        sidebar_list_remove(i->sidebar);
    //        i->sidebar = 0;
    //    }
    //}
    //_47C990_production.sidebar_open_mask[PRODUCTION_GROUP_INFANTRY] = 0;

    auto p = ProductionGroupAccessor(PRODUCTION_GROUP_INFANTRY);
    if (p->next != p)
        sidebar_list_remove(p->next->sidebar);
    _47C990_production.sidebar_open_mask[PRODUCTION_GROUP_INFANTRY] = 0;
}

//----- (00445EC0) --------------------------------------------------------
void sidebar_button_handler_order_unit_click(SidebarButton *a1)
{
    ProductionOption *v1; // esi@1

    v1 = (ProductionOption *)a1->param;
    if (!_44CDC0_sidebar_is_units_limit())
        stru37_list_427E90_enqueue_infantry(
        (int *)&game_globals_per_player + player_side,
            &v1->_14_pcost,
            (v1->cost << 8) / v1->production_time_x60,
            game_cursor_script,
            v1,
            v1->field_2C);
}

//----- (00445F50) --------------------------------------------------------
void sidebar_button_handler_vehicles_open(SidebarButton *a1)
{
    ProductionGroup *v1; // edi@1
    int v3; // ebp@6
    Sprite *v4; // eax@8
    int v5; // ecx@9
    ProductionOption *i; // esi@10

    sidebar_close_all();

    v1 = ProductionGroupAccessor(PRODUCTION_GROUP_VEHICLES)->next;
    if (v1 != ProductionGroupAccessor(PRODUCTION_GROUP_VEHICLES))
    {
        v3 = 256;
        do
        {
            v1->sidebar = sidebar_list_create(0, 0, v3, 160, 0);
            if (!v1->sprite)
            {
                v4 = sprite_create(MOBD_SIDEBAR_BUTTONS, 0, v1->sidebar->sprite);
                if (v4)
                {
                    v1->sprite = v4;
                    v4->drawjob->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_4483E0_sidebar;
                    v5 = v4->y;
                    v4->field_88_unused = 1;
                    v4->y = v5 - 1024;
                    v4->z_index = 3;
                    sprite_load_mobd(
                        v4,
                        _4701B8_mobd_lookups_per_ProductionGroup_field44[2 * v1->_44_mobd_lookup_idx + 1]);
                }
            }
            for (i = v1->prev_option; (ProductionOption **)i != &v1->next_option; i = i->prev)
                sidebar_add_button_4(
                    v1->sidebar,
                    i->mobd_lookup_table_offset,
                    sidebar_button_handler_order_unit_click,
                    (int)&i->_14_pcost,
                    i->cost,
                    i,
                    i->unit_id);
            v1 = v1->next;
            v3 -= 32;
        } while (v1->next != ProductionGroupAccessor(PRODUCTION_GROUP_VEHICLES));
    }
    _47C990_production.sidebar_open_mask[PRODUCTION_GROUP_VEHICLES] = 1;
}

//----- (00446070) --------------------------------------------------------
void sidebar_button_handler_vehicles_close(SidebarButton *a1)
{
    //Sprite *v2; // ecx@3

    //for (
    //    auto i = ProductionGroupAccessor(PRODUCTION_GROUP_VEHICLES);
    //    i != ProductionGroupAccessor(PRODUCTION_GROUP_VEHICLES);
    //    i = i->next
    //    )
    //{
    //    if (i->sidebar)
    //    {
    //        v2 = i->sprite;
    //        if (v2)
    //        {
    //            sprite_list_remove(v2);
    //            i->sprite = 0;
    //        }
    //        sidebar_list_remove(i->sidebar);
    //        i->sidebar = 0;
    //    }
    //}
    //_47C990_production.sidebar_open_mask[PRODUCTION_GROUP_VEHICLES] = 0;

    auto p = ProductionGroupAccessor(PRODUCTION_GROUP_VEHICLES);
    if (p->next != p)
        sidebar_list_remove(p->next->sidebar);
    _47C990_production.sidebar_open_mask[PRODUCTION_GROUP_VEHICLES] = 0;
}

//----- (004460C0) --------------------------------------------------------
void sidebar_button_handler_airstrike_open(SidebarButton *a1)
{
    ProductionGroup *v1; // ebx@1
    Sidebar *v3; // eax@6
    ProductionOption *v4; // esi@6

    sidebar_close_all();

    v1 = ProductionGroupAccessor(PRODUCTION_GROUP_AIRCRAFT)->prev;
    if (v1 != ProductionGroupAccessor(PRODUCTION_GROUP_AIRCRAFT))
    {
        v3 = sidebar_list_create(0, 0, 256, 256, 0);
        v4 = v1->prev_option;
        for (v1->sidebar = v3; (ProductionOption **)v4 != &v1->next_option; v4 = v4->prev)
            sidebar_add_button_4(
                v1->sidebar,
                v4->mobd_lookup_table_offset,
                sidebar_button_handler_order_unit_click,
                (int)&v4->_14_pcost,
                v4->cost,
                v4,
                v4->unit_id);
    }
    _47C990_production.sidebar_open_mask[PRODUCTION_GROUP_AIRCRAFT] = 1;
}

//----- (00446170) --------------------------------------------------------
void sidebar_button_handler_airstrike_close(SidebarButton *a1)
{
    auto p = ProductionGroupAccessor(PRODUCTION_GROUP_AIRCRAFT);
    if (p->next != p)
        sidebar_list_remove(p->next->sidebar);
    _47C990_production.sidebar_open_mask[PRODUCTION_GROUP_AIRCRAFT] = 0;
}

//----- (00446190) --------------------------------------------------------
void sidebar_button_handler_446190_open(SidebarButton *a1)
{
    SidebarButton **v1; // esi@1

    script_trigger_event(0, EVT_MSG_1519, 0, game_cursor_script);
    v1 = _47CA08_sidebar_buttons;
    do
    {
        if (v1 != &_47CA08_sidebar_buttons[1])
            script_trigger_event(0, EVT_MSG_DESELECTED, 0, (*v1)->task);
        ++v1;
    } while (v1 <= &_47CA08_sidebar_buttons[1]);
}

//----- (004461E0) --------------------------------------------------------
void sidebar_button_handler_4461E0_close(SidebarButton *a1)
{
    script_trigger_event(0, EVT_MSG_1520, 0, game_cursor_script);
}

//----- (00446200) --------------------------------------------------------
void sidebar_button_handler_buildings_open(SidebarButton *a1)
{
    ProductionGroup *v1; // ebx@1
    Sidebar *v3; // eax@6
    ProductionOption *v4; // esi@6

    sidebar_close_all();

    v1 = _47C830_buildings_pg.next;
    if (v1 != (ProductionGroup *)&_47C830_buildings_pg)
    {
        v3 = sidebar_list_create(0, 0, 256, 192, 0);
        v4 = v1->prev_option;
        for (v1->sidebar = v3; (ProductionOption **)v4 != &v1->next_option; v4 = v4->prev)
            sidebar_add_button_1(
                v1->sidebar,
                v4->mobd_lookup_table_offset,
                sidebar_button_handler_order_building_click,
                (void *)v4->unit_id,
                (void *)v4->unit_id);
    }
    _47C990_production.sidebar_open_mask[PRODUCTION_GROUP_BUILDINGS] = 1;
}

//----- (00446330) --------------------------------------------------------
void sidebar_button_handler_buildings_close(SidebarButton *a1)
{
    //if (_47C830_buildings_pg.next != (ProductionGroup *)&_47C830_buildings_pg)
    //    sidebar_list_remove(_47C830_buildings_pg.next->sidebar);
    //_47C990_production.sidebar_open_mask[PRODUCTION_GROUP_BUILDINGS] = 0;

    auto p = ProductionGroupAccessor(PRODUCTION_GROUP_BUILDINGS);
    if (p->next != p)
        sidebar_list_remove(p->next->sidebar);
    _47C990_production.sidebar_open_mask[PRODUCTION_GROUP_BUILDINGS] = 0;
}


//----- (004462B0) --------------------------------------------------------
void sidebar_button_handler_order_building_click(SidebarButton *a1)
{
    enum UNIT_ID v1; // ecx@1
    enum UNIT_ID v2; // eax@1
    stru196 *v3; // esi@1
    int v4; // eax@6
    int v5; // ecx@6
    enum UNIT_ID v6; // esi@6

    v1 = (enum UNIT_ID)(int)a1->param;
    v2 = array_4701D8[0].unit_id;
    v3 = array_4701D8;
    _47C788_building_planner.unit_stats_idx = v1;
    if (array_4701D8[0].unit_id == v1)
    {
    LABEL_4:
        if (_44CDC0_sidebar_is_units_limit())
        {
            show_message_ex(0, aBuildingIsUnav);
        }
        else
        {
            v4 = v3->_4_x;
            v5 = v3->_8_y;
            v6 = v3->unit_id;
            _47C788_building_planner.field_4 = v4;
            _47C788_building_planner.field_8 = v5;
            _47C788_building_planner.cost = unit_stats[v6].cost;
            script_trigger_event(0, EVT_MSG_1522_plan_building_construction, &_47C788_building_planner, game_cursor_script);
        }
    }
    else
    {
        while (v2 != -1)
        {
            v2 = v3[1].unit_id;
            ++v3;
            if (v2 == v1)
                goto LABEL_4;
        }
    }
}

//----- (00446350) --------------------------------------------------------
void sidebar_button_handler_towers_open(SidebarButton *a1)
{
    ProductionGroup *v1; // ebx@1	int v2; // esi@1
    Sidebar *v3; // eax@6
    ProductionOption *v4; // esi@6

    sidebar_close_all();

    v1 = ProductionGroupAccessor(PRODUCTION_GROUP_TOWERS)->prev;
    if (v1 != ProductionGroupAccessor(PRODUCTION_GROUP_TOWERS))
    {
        v3 = sidebar_list_create(0, 0, 256, 224, 0);
        v4 = v1->prev_option;
        for (v1->sidebar = v3; (ProductionOption **)v4 != &v1->next_option; v4 = v4->prev)
            sidebar_add_button_1(
                v1->sidebar,
                v4->mobd_lookup_table_offset,
                sidebar_button_handler_order_building_click,
                (void *)v4->unit_id,
                (void *)v4->unit_id);
    }
    _47C990_production.sidebar_open_mask[PRODUCTION_GROUP_TOWERS] = 1;
}

//----- (00446400) --------------------------------------------------------
void sidebar_button_handler_towers_close(SidebarButton *a1)
{
    auto p = ProductionGroupAccessor(PRODUCTION_GROUP_TOWERS);
    if (p->next != p)
        sidebar_list_remove(p->next->sidebar);
    _47C990_production.sidebar_open_mask[PRODUCTION_GROUP_TOWERS] = 0;
}

void sidebar_close_all() 
{
    //v2 = 0;
    //do
    for (int v2 = PRODUCTION_GROUP_INFANTRY; v2 <= PRODUCTION_GROUP_AIRCRAFT; ++v2)
    {
        if (_47C990_production.sidebar_open_mask[v2])
        {
            script_trigger_event(0, EVT_MSG_SELECTED, 0, _47CA18_sidebar_production_buttons[v2]->task);
            script_trigger_event(0, EVT_MSG_DESELECTED, 0, _47CA18_sidebar_production_buttons[v2]->task);
        }
        //++v2;
    }
    //while (v2 < 5);
}

//----- (00446E90) --------------------------------------------------------
void sidebar_deinit()
{
    sprite_list_remove(_47C96C_mobd_1F_sidebar_empty_blocks);
    free(production_group_list);
    free(production_option_list);
    _47CA00_render_string = 0;
}