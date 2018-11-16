#pragma once
#include "src/Script.h"


// =========== IN-GAME LOAD dialog scripts ===================
void script_ingame_menu_create_load_dialog(Script *a1); // main dialog script
void script_ingame_menu_load_game_list(Script *);       // control with savegames list 
void script_ingame_menu_load_game_load(Script *a1);     // load btn
void script_ingame_menu_load_game_cancel(Script *a1);   // cancel btn
void script_ingame_menu_load_game_up(Script *a1);       // up arrow
void script_ingame_menu_load_game_down(Script *a1);     // down arrow
// =======



// =========== IN-GAME SAVE dialog scripts ===================
void script_ingame_menu_create_save_dialog(Script *a1); // main dialog script
void script_ingame_menu_save_game_list(Script *a1);     // control with savegames list 
void script_ingame_menu_save_game_save(Script *a1);     // save btn
void script_ingame_menu_save_game_cancel(Script *a1);   // cancel btn
void script_ingame_menu_save_game_up(Script *a1);       // up arrow
void script_ingame_menu_save_game_down(Script *a1);     // down arrow
// =======
