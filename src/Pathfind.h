#pragma once

#include "src/Engine/Entity.h"



#define BOXD_STRU0_TILE_SLOT(n)         (1 << (n))
#define BOXD_STRU0_TILE_SLOT0           BOXD_STRU0_TILE_SLOT(0)
#define BOXD_STRU0_TILE_SLOT1           BOXD_STRU0_TILE_SLOT(1)
#define BOXD_STRU0_TILE_SLOT2           BOXD_STRU0_TILE_SLOT(2)
#define BOXD_STRU0_TILE_SLOT3           BOXD_STRU0_TILE_SLOT(3)
#define BOXD_STRU0_TILE_SLOT4           BOXD_STRU0_TILE_SLOT(4)
#define BOXD_STRU0_ALL_SLOTS            (BOXD_STRU0_TILE_SLOT0 | BOXD_STRU0_TILE_SLOT1 | BOXD_STRU0_TILE_SLOT2 | BOXD_STRU0_TILE_SLOT3 | BOXD_STRU0_TILE_SLOT4)
#define BOXD_STRU0_OBSTRUCTED           0x20    // edges of some landscapes
#define BOXD_STRU0_BLOCKED              0x40    // completely blocked terrrain
#define BOXD_STRU0_IMPASSIBLE           (BOXD_STRU0_BLOCKED | BOXD_STRU0_OBSTRUCTED)
#define BOXD_STRU0_VEHICLE_BUILDING     0x80    // tile is occupied by a vehicle or a building
/* 389 */
struct DataBoxd_stru0_per_map_unit
{
    bool IsImpassibleTerrain() const {
        return flags & BOXD_STRU0_IMPASSIBLE;
    }
    bool IsAnySlotOccupied() const {
        return flags & BOXD_STRU0_ALL_SLOTS;
    }
    bool IsVehicleOrBuilding() const {
        return flags & BOXD_STRU0_VEHICLE_BUILDING;
    }

    char flags;
    char flags2;
    char field_2;
    char field_3;
    Entity *_4_entities[5];
};

/* 390 */
struct BoxdTile
{
    BoxdTile_stru0 *pstru0;
    void *ptr_4;
    int field_8;
};

/* 391 */
struct BoxdTile_stru0
{
    int type;
    int _4_x;
    int _8_y;
    int field_C;
    int _10_z;
    int _14_w;
};


bool boxd_init();
void bodx_404D50_sprite_list(Sprite *list);
void boxd_404F40_sprite(Sprite *a1, int a2, int a3);
void boxd_free();



int boxd_40EA50_classify_tile_objects(Entity *a1, int map_x, int map_y, DataBoxd_stru0_per_map_unit *a4);
DataBoxd_stru0_per_map_unit *boxd_get_tile(int map_x, int map_y);

bool entity_40DBF0_boxd_does_unit_fit(Entity *a1);
bool entity_40DD00_boxd(Entity *a1);
int entity_40DDD0_boxd(Entity *a1);
char *entity_40DEC0_boxd(Entity *a1, int a2, int a3, int a4);
void Map_40DF50_update_tile(Entity *a1, int a2);
bool boxd_40E6E0();
void boxd_40EA20_gameloop_update();
void boxd_40EA30_cleanup();
int boxd_40ED00(Entity *a1, DataBoxd_stru0_per_map_unit *a2);
bool boxd_40EDF0(DataBoxd_stru0_per_map_unit *a1, Entity *a2, Entity *a3);
Entity *boxd_40EE10_prolly_get_building(int map_x, int map_y); // idb
int boxd_40EE70(int map_x, int map_y); // idb
int boxd_40F160(Entity *a1, int map_x, int map_y, int a4);
void Map_40F230_update_tile(Entity *a1, int map_x, int map_y, int slot, int a5);


void entity_414440_boxd(Entity *a1, int *a2, int *a3);
bool entity_414520_boxd(Entity *a1);
bool entity_414870_boxd(Entity *a1);
bool entity_413860_boxd(Entity *a1);
bool entity_413A90_boxd(Entity *a1);
bool entity_414AD0_vehicle_collide_vehicle(Entity *a1);
void entity_mode_adjust_unit_placement_inside_tile(Entity *a1);


int Map_41B970_straight_line_pathing(Entity *a1, int a2, int a3); // idb
int boxd_41BA30(int x, int y, int a3, int a4, int x_step, int y_step, Entity *a1);
int boxd_41BC60(int x, int y, int a3, int a4, int a5, int a6, Entity *a7);
int Map_41BE90_add_waypoint(_DWORD *a1, int a2, _DWORD *a3, _DWORD *a4, Entity *a5, int *a6, int *a7, int *a8, int map_x, int map_y, _DWORD *a11, _DWORD *a12);
int boxd_41C060(int a1, Entity *a2, int a3, int a4, int *a5, int *a6, int *a7, int a8);
bool boxd_41C130(int x, int y, int z, int w, Entity *entity);
bool boxd_41C190(int x, int y, int z, int w, Entity *a5);
bool boxd_41C250(int x, int y, int z, int w, Entity *a5);
bool boxd_41C660(int x, int y, int width, int height, int a5, int a6, Entity *a7);
bool boxd_41C890(int x, int y, int width, int height, int a5, int a6, Entity *a7);



extern DataBoxd_stru0_per_map_unit *_478AA8_boxd_stru0_array;


extern int _4773A0_boxd_item0_num_things; // weak
extern DataBoxd *currently_running_lvl_boxd;
extern Boxd_stru0 *_4773A8_boxd_parray;
extern int _4773AC_boxd_item0_map_x_scale; // weak
extern Boxd_stru0 **_4773B0_boxd_item0_things;
extern int _4773B4_boxd_item0_map_num_y_tiles; // weak
extern int _4773B8_boxd_item0_map_y_scale; // weak
extern int currently_running_lvl_boxd_valid; // weak
extern Boxd_stru0 *_4773C0_boxd_array;
extern BoxdTile **_4773C4_boxd_item0_map_tiles;
extern int _4773C8_boxd_item0_map_num_x_tiles; // weak