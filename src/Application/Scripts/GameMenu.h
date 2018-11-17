#pragma once
#include "src/Script.h"

// master script to control all menu UIs
void script_ingame_menu_master_script(Script *a1);

void script_ingame_menu_savegame_list_line(Script *a1);


// =========== IN-GAME MENU dialog scripts ===================
void script_ingame_menu_create_dialog(Script *a1);  // dialog initialization script
void script_ingame_menu_options(Script *a1);        // options btn
void script_ingame_menu_load(Script *a1);           // load btn
void script_ingame_menu_save(Script *a1);           // save btn
void script_ingame_menu_briefing(Script *a1);       // briefing btn
void script_ingame_menu_resume(Script *a1);         // return to game btn
void script_ingame_menu_restart(Script *a1);        // restart mission btn
void script_ingame_menu_quit(Script *a1);           // quit to main menu btn
// =======



// =========== IN-GAME OPTIONS dialog scripts ===================
void script_ingame_menu_create_options_dialog(Script *a1);  // dialog initialization script
void script_ingame_menu_options_volume_slider(Script *a1);  // volume slider for both sfx and music (distinguished by param)
void script_ingame_menu_options_done(Script *a1);           // done btn
// =======



// =========== IN-GAME LOAD dialog scripts ===================
void script_ingame_menu_create_load_dialog(Script *a1); // dialog initialization script
void script_ingame_menu_load_game_list(Script *);       // control with savegames list 
void script_ingame_menu_load_game_load(Script *a1);     // load btn
void script_ingame_menu_load_game_cancel(Script *a1);   // cancel btn
void script_ingame_menu_load_game_up(Script *a1);       // up arrow
void script_ingame_menu_load_game_down(Script *a1);     // down arrow
// =======



// =========== IN-GAME SAVE dialog scripts ===================
void script_ingame_menu_create_save_dialog(Script *a1); // dialog initialization script
void script_ingame_menu_save_game_list(Script *a1);     // control with savegames list 
void script_ingame_menu_save_game_save(Script *a1);     // save btn
void script_ingame_menu_save_game_cancel(Script *a1);   // cancel btn
void script_ingame_menu_save_game_up(Script *a1);       // up arrow
void script_ingame_menu_save_game_down(Script *a1);     // down arrow
// =======



// =========== IN-GAME MISSION BRIEFING dialog scripts ===================
void script_ingame_menu_create_briefing_dialog(Script *script); // dialog initialization script
void script_ingame_menu_briefing_done(Script *a1);              // done btn
// =======



// =========== IN-GAME RESTART MISSION dialog scripts ===================
void script_ingame_menu_restart_yes(Script *a1);
void script_ingame_menu_restart_no(Script *a1);
// =======


// =========== IN-GAME QUIT MISSION dialog scripts ===================
void script_ingame_menu_quit_yes(Script *a1);
void script_ingame_menu_quit_no(Script *a1);
// =======