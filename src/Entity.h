#pragma once

struct Script;
struct Entity;

void entity_drag_selection_init(int y, int x, int z, int w);
Script *entity_drag_selection_get_next_entity();

Entity *entity_list_get();
Entity *entity_list_end();

int entity_get_dx(Entity *entity);
int entity_get_dy(Entity *entity);
int entity_transform_x(Entity *entity, int x);
int entity_transform_y(Entity *entity, int y);



bool entity_is_building(Entity *unit);
bool entity_is_moveable(Entity *unit);
bool entity_is_attacker(Entity *unit);
bool entity_is_tower(Entity *entity);

bool is_21st_century(UNIT_ID unit_id);
bool entity_is_21st_century(Entity *entity);




void entity_attack(Entity *a1, _47CAF0_task_attachment1_attack_task *param);
void entity_move(Entity *a1, _47CAF0_task_attachment1_move_task *a2);