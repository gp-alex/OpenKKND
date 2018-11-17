#pragma once

#include "src/Engine/Entity.h"


// Drawing Update Handlers are called each frame to adjust drawing parameters
//  like position, flags, etc


void drawjob_update_draw_handler_aircraft(Entity *param, DrawJob *job);
void drawjob_update_handler_448510_aircraft(Sprite *sprite, DrawJob *job);
void drawjob_update_handler_448580_entity_aircraft_turret(Sprite *sprite, DrawJob *job);

void drawjob_update_handler_4483E0_ui(Sprite *a1, DrawJob *a2);
void drawjob_update_handler_cursors(Sprite *a1, DrawJob *a2);
void drawjob_update_handler_mapd_menu(Bitmap *a1, DrawJob *a2);
void drawjob_update_handler_426C40_mobd(Sprite *a1, DrawJob *a2);
void drawjob_update_handler_44C430_default_sprite(Sprite *a1, DrawJob *a2);

void drawjob_update_handler_4484A0_explosions(Sprite *a1, DrawJob *a2);
void drawjob_update_handler_448600_oilspot(Sprite *a1, DrawJob *a2);
void drawjob_update_handler_448680_repair(Sprite *param, DrawJob *job);

void drawjob_update_handler_448750_infantry(Entity *a1, DrawJob *job);
void drawjob_update_handler_4487B0_vehicles_buildings(Entity *a1, DrawJob *job);
void drawjob_update_handler_4486D0_building(Entity *param, DrawJob *job);
void drawjob_update_handler_oiltanker(Entity *param, DrawJob *job);
void drawjob_update_handler_44BDC0_entity_turret(Sprite *a1, DrawJob *a2);


extern void (*j_drawjob_update_handler_426C40_default_sprite_handler)(Sprite *param, DrawJob *job);
extern void (*j_drawjob_update_handler_mapd_menu)(Bitmap *param, DrawJob *job);