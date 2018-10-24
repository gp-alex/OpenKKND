#pragma once
#include "src/kknd.h"
#include "src/Script.h"




bool sprite_list_alloc(const int pool_size = 2000);
void sprite_init_47A400();
Sprite *sprite_create(enum MOBD_ID mobd_item_idx, Script *script, Sprite *parent);
Sprite *sprite_create_scripted(enum MOBD_ID mobd_item_idx, Sprite *parent, void(*script)(Script *), enum SCRIPT_ROUTINE_TYPE task_type, Entity_stru_dmg_related *a5);
void sprite_list_remove(Sprite *a1);
void sprite_list_remove_scripted(Sprite *a1);
Sprite *sprite_list_find_by_mobd_id(enum MOBD_ID mobd_id);
void sprite_list_update_positions();
void sprite_load_mobd(Sprite *a1, int offset); // idb
void sprite_4272E0_load_mobd_item(Sprite *a1, int lookup_table_offset, int lookup_idx); // idb
void sprite_427320_load_mobd_item_sound(Sprite *a1, int offset); // idb
void sprite_4273B0_load_mobd_item_sound(Sprite *a1, int mobd_lookup_offset, int mobd_lookup_id); // idb
void sprite_release_mobd_item(Sprite *a1);
void sprite_427460_init_mobd_item(Sprite *pstru6);
void sprite_list_init_mobd_items();
void sprite_list_free();