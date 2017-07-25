#pragma once

struct Script;
struct Entity;

void entity_drag_selection_init(int y, int x, int z, int w);
Script *entity_drag_selection_get_next_entity();

Entity *entity_list_end();



bool entity_is_building(Entity *unit);
bool entity_is_moveable(Entity *unit);
bool entity_is_attacker(Entity *unit);
bool entity_is_tower(Entity *entity);

bool is_21st_century(UNIT_ID unit_id);
bool entity_is_21st_century(Entity *entity);