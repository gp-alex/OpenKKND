#pragma once

#include "src/Engine/Entity.h"


#define ENTITY_MAKE_TILE_POSITION(idx)  (idx)
#define ENTITY_TILE_POSITION_0          0
#define ENTITY_TILE_POSITION_1          1
#define ENTITY_TILE_POSITION_2          2
#define ENTITY_TILE_POSITION_3          3
#define ENTITY_TILE_POSITION_4          4
#define ENTITY_TILE_POSITION_INVALID    5


inline int global2map(int coordinate) {
    return coordinate >> 13;
}

inline int map2global(int coordinate) {
    return coordinate << 13;
}

inline int tile2global(int x) {
    return x * 256;
}

inline int global2tile(int x) {
    return x / 256 % 32;
}

inline bool map_is_different_tile(int coord1, int coord2) {
    // original code, equivalent to global2map(coord1) != global2map(coord2)
    return (coord1 ^ coord2) & 0xFFFFE000;
}

inline bool map_is_same_tile(int coord1, int coord2) {
    return !map_is_different_tile(coord1, coord2);
}

// get global coordinate of a tile that contains given point
inline int map_point_to_tile_global(int point) {
    // global coordinates are << 13
    return point & 0xFFFFE000;
}

inline int map_get_width() {
    extern int _4793F8_map_width; // weak
    return _4793F8_map_width;
}

inline int map_get_height() {
    extern int _478AAC_map_height; // weak
    return _478AAC_map_height;
}

inline int map_get_width_global() {
    extern int _478AB4_map_width_shl_13; // weak
    return _478AB4_map_width_shl_13;
}

inline int map_get_height_global() {
    extern int _478FF0_map_height_shl_13; // weak
    return _478FF0_map_height_shl_13;
}


Entity **map_get_tile_entities(int map_x, int map_y);
bool map_is_entity_in_tile(int map_x, int map_y, Entity *entity);



void drawjob_update_handler_level_background(void *a1, DrawJob *a2);
void drawjob_update_handler_448390_fog_of_war(Sprite *, DrawJob *a2);


int map_place_entity(Entity *a1, int x, int y, int a3); // idb
int Map_40EEB0_place_entity(Entity *a1, int map_x, int map_y, int a4);
int Map_40E1B0_place_xl_entity(Entity *a1, int x, int y, int a4); // idb
int map_40DA90_move_entity(Entity *a1);

void script_44A500_fog_of_war(Script *a1); // idb
void show_minimap_sprite();
void hide_minimap_sprite();
void _44A6B0_minimap(int x, int y);
void script_44A700_minimap(Script *a1);
char *_44A780_gof_of_war();
bool minimap_init();
void mapd_44AE30_fog_of_war();
bool is_map_revealed_at(int x, int y); // idb
void map_reveal_fog_around_entity(Entity *a1);
void minimap_free();
int sub_44BC80(int a1, int a2, int a3, int a4);
int MAPD_44BD50_alter_tile_flags();
void enable_minimap();
void disable_minimap();

int map_adjust_entity_in_tile_x(Entity *entity, int x);
int map_adjust_entity_in_tile_y(Entity *entity, int y);
int map_adjust_entity_in_tile_x_2(Entity *entity, int x);
int map_adjust_entity_in_tile_y_2(Entity *entity, int y);
int map_get_entity_placement_inside_tile_x(Entity *a1, int a2); // idb
int map_get_entity_placement_inside_tile_y(Entity *a1, int a2); // idb


extern int minimap_width; // weak
extern int __4793F8_map_width_plus4; // weak
extern int minimap_height; // weak
extern int __478AAC_map_height_plus4; // weak

extern MapdScrlImageTile *fog_of_war_tile_15;
extern MapdScrlImage *fog_of_war_scrl_source;
extern MapdScrlImageTile *fog_of_war_tile_1;
extern MapdScrlImageTile *fog_of_war_tile_10;
extern MapdScrlImageTile *fog_of_war_tile_14;
extern MapdScrlImageTile *fog_of_war_tile_4;
extern MapdScrlImage *map_fog_of_war_scrl;
extern char minimap_fog_of_war_color; // weak
extern char byte_47CB50[8];
extern Sprite *_47CB58_minimap_sprite;
extern MapdScrlImageTile *fog_of_war_tile_11;
extern MapdScrlImageTile *fog_of_war_tile_7;
extern MapdScrlImageTile *fog_of_war_tile_3;
extern int dword_47CB68; // weak
extern int dword_47CB6C; // weak
extern MapdScrlImageTile *fog_of_war_tile_13;
extern void *minimap_revealed_pixels; // idb
extern MapdScrlImageTile *fog_of_war_tile_6;
extern MapdScrlImageTile *fog_of_war_tile_8;
extern void *minimap_fog_of_war_pixels; // idb
extern DrawHandlerData_Units *_47CB8C_fow;
extern MapdScrlImageTile *fog_of_war_tile_5;
extern MapdScrlImageTile *fog_of_war_tile_12;
extern void *minimap_pixels;
extern int dword_47CBAC; // weak
extern Bitmap *fog_of_war_bitmap;
extern MapdScrlImageTile **map_fog_of_war_scrl_tiles;
extern MapdScrlImageTile *fog_of_war_tile_9;
extern MapdScrlImageTile *fog_of_war_tile_2;
extern int _47CBC0_fow[256];