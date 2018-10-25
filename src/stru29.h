#pragma once
#include "src/kknd.h"
#include "src/Script.h"

/* 355 */
struct stru29
{
    stru29 *next;
    stru29 *prev;
    Sprite *sprite;
    int field_C;
};


stru29 *stru29_list_4439F0(Sprite *a1, void *param, int a3, int a4, int a5);
stru29 *stru29_list_443AE0_find_by_sprite(Sprite *a1);
bool stru29_list_alloc();
bool stru29_list_realloc(Script *a1);
void stru29_list_remove_all(Script *a1);
void stru29_list_443BF0_remove_some();
void stru29_list_free();

stru29 *stru29_list_first();
stru29 *stru29_list_end();
stru29 *stru29_list_set_bit_by_sprite(Sprite *sprite, int flag);
stru29 *stru29_list_clear_bit_by_sprite(Sprite *sprite, int flag);


//extern stru29 stru29_list_47C610;
extern stru29 *_47C6D4_stru29;