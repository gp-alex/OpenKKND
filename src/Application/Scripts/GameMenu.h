#pragma once
#include "src/Script.h"


// =========== IN-GAME MENU dialog scripts ===================
void script_ingame_menu_create_dialog(Script *a1);  // ingame menu dialog script
void script_ingame_menu_options(Script *a1);        // options btn
void script_ingame_menu_load(Script *a1);           // load btn
void script_ingame_menu_save(Script *a1);           // save btn
void script_ingame_menu_briefing(Script *a1);       // briefing btn
void script_ingame_menu_resume(Script *a1);         // return to game btn
void script_ingame_menu_restart(Script *a1);        // restart mission btn
void script_ingame_menu_quit(Script *a1);           // quit to main menu btn
// =======


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
