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

//----- (0040F480) --------------------------------------------------------
Sidebar *sidebar_list_create(Sprite *sprite, Script *script, int width, int height, int sidebar_horizontal)
{
    Sidebar *v5; // esi@1
    Sprite *v6; // edi@1
    Sidebar *result; // eax@5
    int v8; // ecx@8

    v5 = sidebar_list_head;
    v6 = sprite;
    if (sidebar_list_head)
        sidebar_list_head = sidebar_list_head->next;
    else
        v5 = 0;
    if (v5)
    {
        v5->script = script;
        if (!script)
            v5->script = script_create_coroutine(SCRIPT_TYPE_51914_sidebar, script_sidebar, 0);
        v5->num_buttons = 0;
        v5->x = (width + render_width - 320) << 8;
        v5->w = height << 8;
        v5->sprite_width_step = sidebar_horizontal == 1 ? sidebar_button_list_item_width : 0;
        v8 = sidebar_button_list_sidebar_height;
        v5->sprite = v6;
        v5->sprite_height_step = sidebar_horizontal == 0 ? v8 : 0;
        if (!v6)
            v5->sprite = sprite_create(MOBD_SIDEBAR_BUTTONS, v5->script, 0);
        v5->sprite->drawjob->on_update_handler = (DrawUpdateHandler)drawjob_update_handler_4483E0_sidebar;
        v5->sprite->field_88_unused = 1;
        v5->sprite->x = v5->x;
        v5->sprite->field_88_unused = 1;
        v5->sprite->y = v5->w;
        v5->sprite->z_index = 1;
        v5->sprite->drawjob->job_details.palette = per_player_sprite_palettes[player_sprite_color_by_player_side[player_side]];
        v5->sprite->drawjob->flags |= 0x10000000u;
        v5->sprite->param = v5;
        v5->button_list_head = (SidebarButton *)&v5->button_list_free_pool;
        v5->button_list_free_pool = (SidebarButton *)&v5->button_list_free_pool;
        v5->next = stru22_list_479548;
        v5->prev = (Sidebar *)&stru22_list_479548;
        result = v5;
        stru22_list_479548->prev = v5;
        stru22_list_479548 = v5;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (0040F3A0) --------------------------------------------------------
bool sidebar_button_list_alloc()
{
    Sidebar *v0; // eax@1
    int v1; // ecx@2
    SidebarButton *v2; // eax@4
    int v3; // ecx@5

    v0 = (Sidebar *)malloc(0x4C0u);
    sidebar_list = v0;
    if (!v0)
        goto LABEL_11;
    sidebar_list_head = v0;
    v1 = 0;
    do
    {
        v0[v1].next = &v0[v1 + 1];
        v0 = sidebar_list;
        ++v1;
    } while (v1 < 15);
    sidebar_list[15].next = 0;
    stru22_list_479548 = (Sidebar *)&stru22_list_479548;
    stru22_list_47954C = (Sidebar *)&stru22_list_479548;
    v2 = (SidebarButton *)malloc(0x7D0u);
    sidebar_button_list = v2;
    if (v2)
    {
        sidebar_button_list_head = v2;
        v3 = 0;
        do
        {
            v2[v3].next = &v2[v3 + 1];
            v2 = sidebar_button_list;
            ++v3;
        } while (v3 < 49);
        sidebar_button_list[49].next = 0;
        sidebar_button_list_4795A0 = (SidebarButton *)&sidebar_button_list_4795A0;
        sidebar_button_list_4795A4 = (SidebarButton *)&sidebar_button_list_4795A0;
        sidebar_button_list_item_width = 0x2000;
        sidebar_button_list_sidebar_height = 0x2000;
        return true;
    }
    else
    {
    LABEL_11:
        return false;
    }
}

//----- (0040F5D0) --------------------------------------------------------
void script_40F5D0_sidebar_button_1_2(Script *a1)
{
    Script *v1; // ebx@1
    Sprite *v2; // ecx@1
    int v3; // edx@1
    int v4; // esi@3
    int v5; // edi@3
    int v6; // ebp@3
    ScriptEvent *i; // eax@3
    enum SCRIPT_EVENT v8; // ecx@4
    int v9; // esi@15
    ScriptEvent *j; // eax@15
    enum SCRIPT_EVENT v11; // ecx@16
    SidebarButton *v12; // edi@27
    void(*v13)(SidebarButton *); // eax@27
    int v14; // esi@30
    ScriptEvent *k; // eax@32
    enum SCRIPT_EVENT v16; // ecx@33
    Sprite *v17; // ebp@43
    int v18; // edi@43
    int v19; // esi@44
    ScriptEvent *m; // eax@44
    enum SCRIPT_EVENT v21; // ecx@45
    void(*v22)(SidebarButton *); // eax@59
    ScriptEvent *l; // eax@65
    Sprite *v24; // [sp+10h] [bp-Ch]@1
    int v25; // [sp+14h] [bp-8h]@14
    int v26; // [sp+14h] [bp-8h]@30
    int v27; // [sp+18h] [bp-4h]@14
    SidebarButton *a1a; // [sp+20h] [bp+4h]@1

    v1 = a1;
    v2 = a1->sprite;
    v24 = v2;
    a1a = (SidebarButton *)v2->param;
    v3 = a1a->mobd_lookup_table_offset;
    while (1)
    {
        sprite_4272E0_load_mobd_item(v2, v3, 0);
        while (1)
        {
            v4 = 0;
            v5 = 0;
            v6 = 0;
            script_wait_event(v1);
            for (i = script_get_next_event(v1); i; i = script_get_next_event(v1))
            {
                v8 = i->event;
                if (v8 == EVT_MSG_1548_sidebar)
                    v6 = 1;
                if (v8 == EVT_MSG_1514)
                    v4 = 1;
                if (v8 == EVT_MSG_SELECTED)
                    v5 = 1;
                script_discard_event(i);
            }
            if (v6 && !v4)
            {
                v12 = a1a;
                goto LABEL_64;
            }
            if (v5)
            {
                v25 = 0;
                v27 = 0;
                sprite_4272E0_load_mobd_item(v24, a1a->mobd_lookup_table_offset, 1);
                do
                {
                    script_yield_any_trigger(v1, 1);
                    v9 = 0;
                    for (j = script_get_next_event(v1); j; j = script_get_next_event(v1))
                    {
                        v11 = j->event;
                        if (v11 == EVT_MSG_1548_sidebar)
                            v27 = 1;
                        if (v11 == -2)
                        {
                            v9 = 1;
                        }
                        else if (v11 == EVT_MSG_DESELECTED)
                        {
                            v25 = 1;
                        }
                        script_discard_event(j);
                    }
                    if (v27)
                        break;
                    sprite_4272E0_load_mobd_item(v24, a1a->mobd_lookup_table_offset, v9 != 0);
                } while (!v25);
                if (v9 && v25)
                    break;
            }
        }
        v12 = a1a;
        v6 = 0;
        v13 = a1a->open_handler;
        if (v13)
            (v13)(a1a);
        if (!a1a->close_handler)
        {
            v17 = v24;
            goto LABEL_62;
        }
        v26 = 0;
        v14 = 0;
        do
        {
            if (v6)
                goto LABEL_64;
            script_wait_event(v1);
            for (k = script_get_next_event(v1); k; k = script_get_next_event(v1))
            {
                v16 = k->event;
                if (v16 == EVT_MSG_1548_sidebar)
                    v6 = 1;
                if (v16 == EVT_MSG_SELECTED)
                {
                    v14 = 1;
                }
                else if (v16 == EVT_MSG_DESELECTED)
                {
                    v26 = 1;
                }
                script_discard_event(k);
            }
        } while (!v14);
        if (v6)
        {
        LABEL_64:
            sprite_load_mobd(v24, 1980);
            while (v6)
            {
                script_wait_event(v1);
                for (l = script_get_next_event(v1); l; l = script_get_next_event(v1))
                {
                    if (l->event == EVT_MSG_1514)
                        v6 = 0;
                    script_discard_event(l);
                }
            }
            v3 = v12->mobd_lookup_table_offset;
            v2 = v24;
        }
        else
        {
            if (v26)
            {
                v17 = v24;
            }
            else
            {
                v17 = v24;
                v18 = 0;
                sprite_4272E0_load_mobd_item(v24, a1a->mobd_lookup_table_offset, 1);
                do
                {
                    script_yield_any_trigger(v1, 1);
                    v19 = 0;
                    for (m = script_get_next_event(v1); m; m = script_get_next_event(v1))
                    {
                        v21 = m->event;
                        if (v21 == EVT_MSG_1548_sidebar)
                            v18 = 1;
                        if (v21 == EVT_MOUSE_HOVER)
                        {
                            v19 = 1;
                        }
                        else if (v21 == EVT_MSG_DESELECTED)
                        {
                            v26 = 1;
                        }
                        script_discard_event(m);
                    }
                    if (v18)
                        break;
                    if (v19)
                    {
                        sprite_4272E0_load_mobd_item(v24, a1a->mobd_lookup_table_offset, 1);
                    }
                    else if (!a1a->close_handler)
                    {
                        sprite_4272E0_load_mobd_item(v24, a1a->mobd_lookup_table_offset, 0);
                    }
                } while (!v26);
                v12 = a1a;
            }
            v22 = v12->close_handler;
            if (v22)
            {
                (v22)(v12);
                v3 = v12->mobd_lookup_table_offset;
                v2 = v17;
                continue;
            }
        LABEL_62:
            v3 = v12->mobd_lookup_table_offset;
            v2 = v17;
        }
    }
}

//----- (0040F8F0) --------------------------------------------------------
void script_40F8F0_sidebar_button_3(Script *a1)
{
    Script *v1; // ebp@1
    Sprite *v2; // ecx@1
    int v3; // edx@1
    int v4; // esi@3
    int v5; // edi@3
    int v6; // ebx@3
    ScriptEvent *i; // eax@3
    enum SCRIPT_EVENT v8; // ecx@4
    int v9; // edi@14
    int v10; // ebx@14
    int v11; // esi@15
    ScriptEvent *j; // eax@15
    enum SCRIPT_EVENT v13; // ecx@16
    SidebarButton *v14; // edi@31
    void(*v15)(SidebarButton *); // eax@31
    int v16; // esi@34
    ScriptEvent *k; // eax@37
    enum SCRIPT_EVENT v18; // edx@38
    int v19; // edi@49
    int v20; // esi@50
    ScriptEvent *l; // eax@50
    enum SCRIPT_EVENT v22; // ecx@51
    void(*v23)(SidebarButton *); // eax@66
    ScriptEvent *m; // eax@71
    Sprite *v25; // [sp+10h] [bp-8h]@1
    int v26; // [sp+14h] [bp-4h]@34
    SidebarButton *a1a; // [sp+1Ch] [bp+4h]@1

    v1 = a1;
    v2 = a1->sprite;
    v25 = v2;
    a1a = (SidebarButton *)v2->param;
    v3 = a1a->mobd_lookup_table_offset;
    while (1)
    {
        sprite_4272E0_load_mobd_item(v2, v3, 0);
        while (1)
        {
            v4 = 0;
            v5 = 0;
            v6 = 0;
            script_wait_event(v1);
            for (i = script_get_next_event(v1); i; i = script_get_next_event(v1))
            {
                v8 = i->event;
                if (v8 == EVT_MSG_1548_sidebar)
                    v6 = 1;
                if (v8 == EVT_MSG_1514)
                    v4 = 1;
                if (v8 == EVT_MSG_SELECTED)
                    v5 = 1;
                script_discard_event(i);
            }
            if (v6 && !v4)
            {
                v14 = a1a;
                goto LABEL_70;
            }
            if (v5)
            {
                v9 = 0;
                v10 = 0;
                sprite_4272E0_load_mobd_item(v25, a1a->mobd_lookup_table_offset, 1);
                do
                {
                    script_yield_any_trigger(v1, 1);
                    v11 = 0;
                    for (j = script_get_next_event(v1); j; j = script_get_next_event(v1))
                    {
                        v13 = j->event;
                        if (v13 == EVT_MSG_1548_sidebar)
                            v10 = 1;
                        if (v13 == EVT_MOUSE_HOVER)
                        {
                            v11 = 1;
                        }
                        else if (v13 == EVT_MSG_DESELECTED || v13 == EVT_MSG_1513)
                        {
                            v9 = 1;
                        }
                        script_discard_event(j);
                    }
                    if (v10)
                        break;
                    if (v11)
                        sprite_4272E0_load_mobd_item(v25, a1a->mobd_lookup_table_offset, 1);
                    else
                        sprite_4272E0_load_mobd_item(v25, a1a->mobd_lookup_table_offset, 0);
                } while (!v9);
                if (v11 && v9)
                    break;
            }
        }
        v14 = a1a;
        v6 = 0;
        v15 = a1a->open_handler;
        if (v15)
            (v15)(a1a);
        if (a1a->close_handler)
        {
            v26 = 0;
            v16 = 0;
            do
            {
                if (v6)
                    goto LABEL_70;
                if (v26)
                    break;
                script_wait_event(v1);
                for (k = script_get_next_event(v1); k; k = script_get_next_event(v1))
                {
                    v18 = k->event;
                    if (v18 == EVT_MSG_1548_sidebar)
                        v6 = 1;
                    if (v18 == EVT_MSG_SELECTED)
                    {
                        v16 = 1;
                    }
                    else if (v18 == EVT_MSG_DESELECTED || v18 == EVT_MSG_1513)
                    {
                        v26 = 1;
                    }
                    script_discard_event(k);
                }
            } while (!v16);
            if (!v6)
            {
                if (!v26)
                {
                    v19 = 0;
                    sprite_4272E0_load_mobd_item(v25, a1a->mobd_lookup_table_offset, 1);
                    do
                    {
                        script_yield_any_trigger(v1, 1);
                        v20 = 0;
                        for (l = script_get_next_event(v1); l; l = script_get_next_event(v1))
                        {
                            v22 = l->event;
                            if (v22 == EVT_MSG_1548_sidebar)
                                v19 = 1;
                            if (v22 == EVT_MOUSE_HOVER)
                            {
                                v20 = 1;
                            }
                            else if (v22 == EVT_MSG_DESELECTED || v22 == EVT_MSG_1513)
                            {
                                v26 = 1;
                            }
                            script_discard_event(l);
                        }
                        if (v19)
                            break;
                        if (v20)
                        {
                            sprite_4272E0_load_mobd_item(v25, a1a->mobd_lookup_table_offset, 1);
                        }
                        else if (!a1a->close_handler)
                        {
                            sprite_4272E0_load_mobd_item(v25, a1a->mobd_lookup_table_offset, 0);
                        }
                    } while (!v26);
                    v14 = a1a;
                }
                v23 = v14->close_handler;
                if (v23)
                    (v23)(v14);
                goto LABEL_68;
            }
        LABEL_70:
            sprite_load_mobd(v25, 1980);
            while (v6)
            {
                script_wait_event(v1);
                for (m = script_get_next_event(v1); m; m = script_get_next_event(v1))
                {
                    if (m->event == EVT_MSG_1514)
                        v6 = 0;
                    script_discard_event(m);
                }
            }
            v3 = v14->mobd_lookup_table_offset;
            v2 = v25;
        }
        else
        {
        LABEL_68:
            v3 = v14->mobd_lookup_table_offset;
            v2 = v25;
        }
    }
}

//----- (0040FC10) --------------------------------------------------------
void script_40FC10_sidebar_button_4(Script *a1)
{
    Script *v1; // ebp@1
    Sprite *v2; // edi@1
    SidebarButton *v3; // ebx@1
    int v4; // esi@1
    ScriptEvent *j; // eax@5
    ScriptEvent *k; // eax@11
    enum SCRIPT_EVENT v7; // ecx@12
    void(*v8)(SidebarButton *); // eax@21
    Sprite *v9; // ebp@26
    Sprite *v10; // eax@26
    int v11; // ecx@26
    Sprite *v12; // edi@26
    int v13; // eax@29
    int v14; // ebx@34
    int v15; // edx@34
    int v16; // edi@36
    int v17; // edx@36
    int v18; // edi@37
    int v19; // ebx@37
    ScriptEvent *i; // eax@39
    enum SCRIPT_EVENT v21; // edx@40
    int v22; // edx@41
    int v23; // edx@46
    int v24; // edi@54
    int v25; // eax@57
    DrawJob *v26; // eax@61
    unsigned int v27; // ecx@61
    Sprite *v28; // ecx@72
    Sprite *v29; // ecx@74
    int v30; // [sp+10h] [bp-1Ch]@3
    int v31; // [sp+10h] [bp-1Ch]@11
    int v32; // [sp+10h] [bp-1Ch]@26
    int lookup_idx; // [sp+14h] [bp-18h]@26
    Sprite *v34; // [sp+18h] [bp-14h]@10
    Sprite *v35; // [sp+18h] [bp-14h]@26
    int v36; // [sp+1Ch] [bp-10h]@37
    SidebarButton *v37; // [sp+20h] [bp-Ch]@1
    Sprite *v38; // [sp+24h] [bp-8h]@1
    int v39; // [sp+28h] [bp-4h]@26

    v1 = a1;
    v2 = a1->sprite;
    v38 = v2;
    v3 = (SidebarButton *)v2->param;
    v37 = v3;
    v4 = v3->ptr_1C;
    while (1)
    {
        do
        {
            while (1)
            {
                v30 = 0;
                if (!*(_DWORD *)v4 && !*(_DWORD *)(v4 + 4))
                    break;
            LABEL_23:
                sprite_4272E0_load_mobd_item(v2, v3->mobd_lookup_table_offset, 1);
                if (*(_DWORD *)v4 <= 0)
                    *(_DWORD *)v4 = v3->field_18;
                if (*(_DWORD *)v4)
                {
                    v32 = *(_DWORD *)v4;
                    lookup_idx = 0;
                    v39 = v3->field_18 / 16;
                    v9 = sprite_create(MOBD_SIDEBAR_BUTTONS, 0, v2);
                    v10 = sprite_create(MOBD_SIDEBAR_BUTTONS, 0, v2);
                    v11 = v3->field_18;
                    v12 = v10;
                    v35 = v10;
                    if (v32 < v11)
                        lookup_idx = 15 * (v11 - *(_DWORD *)v4) / v11;
                    if (v10)
                    {
                        v10->drawjob->on_update_handler = (DrawUpdateHandler)drawjob_update_handler_4483E0_sidebar;
                        v13 = *(_DWORD *)(v4 + 4);
                        if (v13 <= 1)
                        {
                            v12->drawjob->flags |= 0x40000000u;
                        }
                        else if (v13 >= 10)
                        {
                            sprite_load_mobd(v12, 2160);
                        }
                        else
                        {
                            sprite_4272E0_load_mobd_item(v12, 2276, v13 - 1);
                        }
                        v14 = v12->y + 6656;
                        v15 = v12->z_index + 2;
                        v12->x += 2048;
                        v12->field_88_unused = 1;
                        v12->y = v14;
                        v12->z_index = v15;
                        v12->drawjob->job_details.palette = per_player_sprite_palettes[player_sprite_color_by_player_side[player_side]];
                        v12->drawjob->flags |= 0x10000000u;
                        *(_DWORD *)(v4 + 12) = (int)v12;
                    }
                    if (v9)
                    {
                        v9->drawjob->on_update_handler = (DrawUpdateHandler)drawjob_update_handler_4483E0_sidebar;
                        sprite_4272E0_load_mobd_item(v9, 2312, lookup_idx);
                        v16 = v9->x + 256;
                        v17 = v9->z_index + 2;
                        v9->field_88_unused = 1;
                        v9->x = v16;
                        v9->z_index = v17;
                        v9->drawjob->job_details.palette = per_player_sprite_palettes[player_sprite_color_by_player_side[player_side]];
                        v9->drawjob->flags |= 0x10000000u;
                        *(_DWORD *)(v4 + 8) = (int)v9;
                    }
                    while (1)
                    {
                        v18 = *(_DWORD *)(v4 + 4);
                        v19 = 0;
                        v36 = 0;
                        script_sleep(a1, 6);
                        if (v18 != *(_DWORD *)(v4 + 4))
                            v36 = 1;
                        for (i = script_get_next_event(a1); i; i = script_get_next_event(a1))
                        {
                            v21 = i->event;
                            if (v21 == 1513)
                            {
                                v22 = *(_DWORD *)(v4 + 4);
                                if (v22 > 0)
                                {
                                    if (v22 <= 9)
                                        *(_DWORD *)(v4 + 4) = v22 - 1;
                                    else
                                        *(_DWORD *)(v4 + 4) = 9;
                                LABEL_49:
                                    v19 = 1;
                                    goto LABEL_50;
                                }
                            }
                            else if (v21 == 1511)
                            {
                                v23 = *(_DWORD *)(v4 + 4);
                                if (v23 >= 9)
                                    *(_DWORD *)(v4 + 4) = 4000000;
                                else
                                    *(_DWORD *)(v4 + 4) = v23 + 1;
                                goto LABEL_49;
                            }
                        LABEL_50:
                            script_discard_event(i);
                        }
                        if (!*(_DWORD *)(v4 + 4))
                            goto LABEL_71;
                        if (_44CDC0_sidebar_is_units_limit())
                            break;
                        if (v36)
                        {
                            v24 = 0;
                            v32 = *(_DWORD *)v4;
                            lookup_idx = 0;
                            v19 = 1;
                            sprite_4272E0_load_mobd_item(v9, 2312, 0);
                        }
                        else
                        {
                            v24 = lookup_idx;
                        }
                        if (v19)
                        {
                            v25 = *(_DWORD *)(v4 + 4);
                            if (v25 <= 1)
                            {
                                v26 = v35->drawjob;
                                v27 = v26->flags | 0x40000000;
                            }
                            else
                            {
                                if (v25 >= 10)
                                    sprite_load_mobd(v35, 2160);
                                else
                                    sprite_4272E0_load_mobd_item(v35, 2276, v25 - 1);
                                v26 = v35->drawjob;
                                v27 = v26->flags & 0xBFFFFFFF;
                            }
                            v26->flags = v27;
                        }
                        if (v32 - *(_DWORD *)v4 >= v39)
                        {
                            v32 -= v39;
                            if (v24 < 15)
                            {
                                lookup_idx = v24 + 1;
                                sprite_4272E0_load_mobd_item(v9, 2312, v24 + 1);
                            }
                        }
                        if (!*(_DWORD *)v4)
                            goto LABEL_72;
                    }
                    if (*(_DWORD *)(v4 + 4))
                    {
                        *(_DWORD *)(v4 + 4) = 0;
                        show_message_ex(0, aUnitsAreUnavai);
                    }
                LABEL_71:
                    stru38_list_427FD0((int *)v4, 1);
                    *(_DWORD *)v4 = 0;
                LABEL_72:
                    v28 = *(Sprite **)(v4 + 8);
                    if (v28)
                    {
                        sprite_list_remove(v28);
                        *(_DWORD *)(v4 + 8) = 0;
                    }
                    v29 = *(Sprite **)(v4 + 12);
                    if (v29)
                    {
                        sprite_list_remove(v29);
                        *(_DWORD *)(v4 + 12) = 0;
                    }
                    v3 = v37;
                    v2 = v38;
                    v1 = a1;
                }
            }
            sprite_4272E0_load_mobd_item(v2, v3->mobd_lookup_table_offset, 0);
            script_wait_event(v1);
            for (j = script_get_next_event(v1); j; j = script_get_next_event(v1))
            {
                if (j->event == 1511)
                    v30 = 1;
                script_discard_event(j);
            }
        } while (!v30);
        v34 = 0;
        sprite_4272E0_load_mobd_item(v2, v3->mobd_lookup_table_offset, 1);
        do
        {
            script_yield_any_trigger(v1, 1);
            v31 = 0;
            for (k = script_get_next_event(v1); k; k = script_get_next_event(v1))
            {
                v7 = k->event;
                if (v7 == -2)
                {
                    v31 = 1;
                }
                else if (v7 == 1512)
                {
                    v34 = (Sprite *)1;
                }
                script_discard_event(k);
            }
            sprite_4272E0_load_mobd_item(v2, v3->mobd_lookup_table_offset, v31 != 0);
        } while (!v34);
        if (!v31)
            goto LABEL_23;
        if (!_44CDC0_sidebar_is_units_limit())
        {
            *(_DWORD *)v4 = v3->field_18;
            *(_DWORD *)(v4 + 4) = 1;
            v8 = v3->open_handler;
            if (v8)
                v8(v3);
            goto LABEL_23;
        }
        show_message_ex(0, aUnitsAreUnavai);
    }
}

//----- (004100C0) --------------------------------------------------------
SidebarButton *sidebar_add_button_1(Sidebar *sidebar, int mobd_lookup_table_offset, void(*open_handler)(SidebarButton *), void *param, void *task_context)
{
    return sidebar_add_buttton_internal(
        sidebar,
        mobd_lookup_table_offset,
        script_40F5D0_sidebar_button_1_2,
        open_handler,
        0,
        param,
        task_context,
        SCRIPT_TYPE_47802_fog_of_war
    );
}

//----- (004100F0) --------------------------------------------------------
SidebarButton *sidebar_add_button_2(Sidebar *sidebar, int mobd_lookup_table_offset, void(*button_open_handler)(SidebarButton *), void(*button_close_handler)(SidebarButton *), void *task_context)
{
    return sidebar_add_buttton_internal(
        sidebar,
        mobd_lookup_table_offset,
        script_40F5D0_sidebar_button_1_2,
        button_open_handler,
        button_close_handler,
        0,
        task_context,
        SCRIPT_TYPE_47802_fog_of_war
    );
}

//----- (00410120) --------------------------------------------------------
SidebarButton *sidebar_add_button_3(Sidebar *sidebar, int mobd_lookup_table_offset, void(*button_open_handler)(SidebarButton *), void(*button_close_handler)(SidebarButton *), void *task_context)
{
    return sidebar_add_buttton_internal(
        sidebar,
        mobd_lookup_table_offset,
        script_40F8F0_sidebar_button_3,
        button_open_handler,
        button_close_handler,
        0,
        task_context,
        SCRIPT_TYPE_48059
    );
}

//----- (00410150) --------------------------------------------------------
SidebarButton *sidebar_add_button_4(Sidebar *sidebar, int mobd_lookup_table_offset, void(*button_open_handler)(SidebarButton *), int a4, int a5, void *param, enum UNIT_ID a7)
{
    SidebarButton *result; // eax@1

    result = sidebar_add_buttton_internal(
        sidebar,
        mobd_lookup_table_offset,
        (void(*)(Script *))script_40FC10_sidebar_button_4,
        button_open_handler,
        0,
        param,
        (void *)a7,
        SCRIPT_TYPE_47802_fog_of_war
    );
    if (result)
    {
        result->field_18 = a5;
        result->ptr_1C = a4;
    }
    return result;
}

//----- (00410190) --------------------------------------------------------
SidebarButton *sidebar_add_buttton_internal(
    Sidebar *a1, int mobd_lookup_table_offset, void(*task_routine)(Script *),
    void(*open_handler)(SidebarButton *), void(*close_handler)(SidebarButton *), void *param,
    void *task_context, enum SCRIPT_TYPE event
)
{
    SidebarButton *v8; // esi@1
    int mobd_lookup_table_0ffset; // ebp@1
    Sidebar *v10; // edi@1
    SidebarButton *result; // eax@5
    Script *v12; // eax@6
    Script *v13; // edx@6
    Sprite *v14; // eax@6
    int v15; // eax@8

    v8 = sidebar_button_list_head;
    mobd_lookup_table_0ffset = mobd_lookup_table_offset;
    v10 = a1;
    if (sidebar_button_list_head)
        sidebar_button_list_head = sidebar_button_list_head->next;
    else
        v8 = 0;
    if (v8)
    {
        v12 = script_create_coroutine(event, task_routine, 0);
        v8->task = v12;
        v12->param = task_context;
        v8->mobd_lookup_table_offset = mobd_lookup_table_0ffset;
        v8->open_handler = open_handler;
        v8->close_handler = close_handler;
        v13 = v8->task;
        v8->param = param;
        v8->field_18 = 0;
        v8->ptr_1C = 0;
        v14 = sprite_create(MOBD_SIDEBAR_BUTTONS, v13, 0);
        v8->sprite = v14;
        v14->drawjob->on_update_handler = (DrawUpdateHandler)drawjob_update_handler_4483E0_sidebar;
        v8->sprite->param = v8;
        if (v10)
        {
            v8->prev = v10->button_list_head;
            v8->next = (SidebarButton *)&v10->button_list_free_pool;
            v10->button_list_head->next = v8;
            v10->button_list_head = v8;
            v8->sprite->field_88_unused = 1;
            v8->sprite->x = v10->x + v10->num_buttons * v10->sprite_width_step;
            if (task_context == (void *)-11)
            {
                v8->sprite->field_88_unused = 1;
                v15 = 13 * v10->sprite_height_step;
            }
            else
            {
                v8->sprite->field_88_unused = 1;
                v15 = v10->num_buttons * v10->sprite_height_step;
            }
            v8->sprite->y = v10->w + v15;
            ++v10->num_buttons;
            v8->sprite->z_index = 1;
            v8->sprite->drawjob->job_details.palette = per_player_sprite_palettes[player_sprite_color_by_player_side[player_side]];
            v8->sprite->drawjob->flags |= 0x10000000u;
        }
        result = v8;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (004102D0) --------------------------------------------------------
void sidebar_remove_button(Sidebar *a1, SidebarButton *a2)
{
    SidebarButton *v2; // edi@1
    int v3; // esi@3
    Sprite *v4; // ecx@5

    v2 = a2;
    if (a1)
    {
        --a1->num_buttons;
        a2->prev->next = a2->next;
        a2->next->prev = a2->prev;
        if (a2->field_18)
        {
            v3 = a2->ptr_1C + 8;
            if (*(_DWORD *)v3)
            {
                sprite_list_remove(*(Sprite **)v3);
                *(_DWORD *)v3 = 0;
            }
            v4 = *(Sprite **)(v3 + 4);
            if (v4)
            {
                sprite_list_remove(v4);
                *(_DWORD *)(v3 + 4) = 0;
            }
        }
    }
    sprite_list_remove(v2->sprite);
    script_deinit(v2->task);
    v2->next = sidebar_button_list_head;
    sidebar_button_list_head = v2;
}

//----- (00410340) --------------------------------------------------------
void sidebar_list_remove(Sidebar *a1)
{
    Sidebar *v1; // edi@1
    SidebarButton *v2; // edx@1
    SidebarButton *v3; // edx@1
    Script *v4; // ecx@3

    if (a1 == 0)
    {
        return;
    }

    v1 = a1;
    v2 = a1->button_list_free_pool;
    v3 = (SidebarButton *)&a1->button_list_free_pool;
    if (v2 != (SidebarButton *)&a1->button_list_free_pool)
    {
        do
        {
            sidebar_remove_button(v1, v2);
            v2 = v3->next;
        } while (v3->next != v3);
    }
    sprite_list_remove(v1->sprite);
    v4 = v1->script;
    if (v4->script_type == SCRIPT_TYPE_51914_sidebar)
        script_deinit(v4);
    v1->next->prev = v1->prev;
    v1->prev->next = v1->next;
    v1->next = sidebar_list_head;
    sidebar_list_head = v1;
}

//----- (004103A0) --------------------------------------------------------
void sidebar_list_free()
{
    free(sidebar_button_list);
    free(sidebar_list);
}

//----- (00446E90) --------------------------------------------------------
void sidebar_deinit()
{
    sprite_list_remove(_47C96C_mobd_1F_sidebar_empty_blocks);
    free(production_group_list);
    free(production_option_list);
    _47CA00_render_string = 0;
}