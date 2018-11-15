#pragma once

#include "src/Script.h"


/* 331 */
struct SidebarButton
{
    SidebarButton *next;
    SidebarButton *prev;
    Script *task;
    void(*open_handler)(SidebarButton *);
    void(*close_handler)(SidebarButton *);
    int mobd_lookup_table_offset;
    int field_18;
    int ptr_1C;
    void *param;
    Sprite *sprite;
};

/* 330 */
struct Sidebar
{
    Sidebar *next;
    Sidebar *prev;
    Script *script;
    int num_buttons;
    int x;
    int w;
    int sprite_width_step;
    int sprite_height_step;
    Sprite *sprite;
    SidebarButton *button_list_free_pool;
    SidebarButton *button_list_head;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
};

bool sidebar_initialize();
void sidebar_button_handler_cash_open(SidebarButton *a1);
void sidebar_button_handler_cash_close(SidebarButton *a1);
void sidebar_button_handler_help_open(SidebarButton *a1);
void sidebar_button_handler_help_close(SidebarButton *a1);
void sidebar_button_handler_infantry_open(SidebarButton *a1);
void sidebar_button_handler_infantry_close(SidebarButton *a1);
void sidebar_button_handler_order_unit_click(SidebarButton *a1);
void sidebar_button_handler_vehicles_open(SidebarButton *a1);
void sidebar_button_handler_vehicles_close(SidebarButton *a1);
void sidebar_button_handler_airstrike_open(SidebarButton *a1);
void sidebar_button_handler_airstrike_close(SidebarButton *a1);
void sidebar_button_handler_446190_open(SidebarButton *a1);
void sidebar_button_handler_4461E0_close(SidebarButton *a1);
void sidebar_button_handler_buildings_open(SidebarButton *a1);
void sidebar_button_handler_buildings_close(SidebarButton *a1);
void sidebar_button_handler_order_building_click(SidebarButton *a1);
void sidebar_button_handler_towers_open(SidebarButton *a1);
void sidebar_button_handler_towers_close(SidebarButton *a1);
void sidebar_close_all();
void sidebar_deinit();