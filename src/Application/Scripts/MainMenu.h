#pragma once
#include "src/Script.h"


// =========== MAIN MENU dialog scripts ===================
void script_main_menu_new_campaign(Script *a1);
void script_main_menu_load(Script *a1);
void script_main_menu_play_mission(Script *a1);
void script_main_menu_new_missions(Script *a1);
void script_main_menu_kaos_mode(Script *a1);
void script_main_menu_multiplayer(Script *a1);
void script_main_menu_quit(Script *a1);
// =======



// =========== MAIN MENU NEW CAMPAIGN dialog scripts ===================
void script_main_menu_new_campaign_surv(Script *a1);
void script_main_menu_new_campaign_mute(Script *a1);
void script_main_menu_new_campaign_cancel(Script *a1);
// =======



// =========== MAIN MENU LOAD dialog scripts ===================
void script_main_menu_create_load_dialog(Script *a1);   // dialog initialization script
// =======



// =========== MAIN MENU PLAY MISSION dialog scripts ===================
void script_main_menu_play_mission_faction_toggle(Script *a1);
void script_main_menu_play_mission_ok(Script *a1);
void script_main_menu_play_mission_cancel(Script *a1);
// =======



// =========== MAIN MENU KAOS dialog scripts ===================
void script_main_menu_create_kaos_dialog(Script *a1);
void script_main_menu_kaos_player_name(Script *a1); // idb
void script_main_menu_kaos_starting_cash(Script *a1);
void script_main_menu_kaos_color(Script *a1);
void script_main_menu_kaos_map(Script *a1);
void script_main_menu_kaos_max_tech_level(Script *a1);
void script_main_menu_kaos_bunkers_toggle(Script *a1);
void script_main_menu_kaos_team(Script *a1); // idb
void script_main_menu_kaos_allies(Script *a1);
void script_main_menu_kaos_enemies(Script *a1);
void script_main_menu_kaos_difficulty(Script *a1);
void script_main_menu_kaos_start(Script *a1); // idb
void script_main_menu_kaos_cancel(Script *a1);
// =======