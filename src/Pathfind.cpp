#include <assert.h>

#include "src/Pathfind.h"

#include "src/_unsorted_data.h"
#include "src/Map.h"
#include "src/Random.h"
#include "src/ScriptEvent.h"





int _4773A0_boxd_item0_num_things = 0; // weak
DataBoxd *currently_running_lvl_boxd = NULL;
Boxd_stru0 *_4773A8_boxd_parray = NULL;
int _4773AC_boxd_item0_map_x_scale = 0; // weak
Boxd_stru0 **_4773B0_boxd_item0_things = NULL;
int _4773B4_boxd_item0_map_num_y_tiles = 0; // weak
int _4773B8_boxd_item0_map_y_scale = 0; // weak
int currently_running_lvl_boxd_valid = 0; // weak
Boxd_stru0 *_4773C0_boxd_array = NULL;
BoxdTile **_4773C4_boxd_item0_map_tiles = NULL;
int _4773C8_boxd_item0_map_num_x_tiles = 0; // weak


DataBoxd_stru0_per_map_unit *_478AA8_boxd_stru0_array;



Entity **map_get_tile_entities(int map_x, int map_y) {
    assert(map_x >= 0 && map_x < map_get_width());
    assert(map_y >= 0 && map_y < map_get_height());

    return _478AA8_boxd_stru0_array[map_x + map_y * map_get_width()]._4_entities;
}

bool map_is_entity_in_tile(int map_x, int map_y, Entity *entity) {
    auto entities = map_get_tile_entities(map_x, map_y);
    for (int i = 0; i < 5; ++i) {
        if (entities[i] == entity) {
            return true;
        }
    }

    return false;
}

//----- (00404C90) --------------------------------------------------------
bool boxd_init()
{
    currently_running_lvl_boxd_valid = 0;
    currently_running_lvl_boxd = (DataBoxd *)LVL_FindSection(BOXD);
    if (currently_running_lvl_boxd)
    {
        _4773C0_boxd_array = (Boxd_stru0 *)malloc(0x17700u); // 8000 items
        if (_4773C0_boxd_array)
        {
            _4773B0_boxd_item0_things = 0;
            _4773A0_boxd_item0_num_things = currently_running_lvl_boxd->items->field_0_num_things;
            _4773AC_boxd_item0_map_x_scale = currently_running_lvl_boxd->items->some_map_width_scale;
            _4773B8_boxd_item0_map_y_scale = currently_running_lvl_boxd->items->some_map_height_scale;
            _4773C8_boxd_item0_map_num_x_tiles = currently_running_lvl_boxd->items->map_num_x_tiles;
            _4773B4_boxd_item0_map_num_y_tiles = currently_running_lvl_boxd->items->map_num_y_tiles;
            _4773C4_boxd_item0_map_tiles = currently_running_lvl_boxd->items->map_tiles;
            _4773B0_boxd_item0_things = (Boxd_stru0 **)malloc(4 * _4773A0_boxd_item0_num_things);
            if (_4773B0_boxd_item0_things)
            {
                currently_running_lvl_boxd_valid = 1;
                return true;
            }
            else
            {
                free(_4773C0_boxd_array);
                return false;
            }
        }
    }

    return true;
}

//----- (00404D50) --------------------------------------------------------
void bodx_404D50_sprite_list(Sprite *list)
{
    Sprite *v1; // edx@1
    Sprite *v2; // edi@5
    Script *v3; // eax@7
    signed __int16 v4; // cx@8
    Sprite_stru58 *v5; // eax@10
    Sprite_stru58_stru0 *v6; // esi@12
    int v7; // eax@12
    int v8; // ebx@16
    int v9; // eax@16
    int v10; // edx@16
    char v11; // cl@17
    int v12; // edx@17
    int v13; // ebx@19
    int v14; // ebx@23
    int v15; // eax@25
    int v16; // ebp@25
    bool v17; // sf@25
    int v18; // eax@25
    int v19; // eax@26
    int v20; // esi@28
    int v21; // esi@32
    Boxd_stru0 **v22; // edx@34
    Boxd_stru0 **v23; // eax@36
    int v24; // ecx@37
    int v25; // [sp+10h] [bp-Ch]@25
    int v26; // [sp+10h] [bp-Ch]@35
    Sprite_stru58 *v27; // [sp+14h] [bp-8h]@10
    Sprite *v28; // [sp+18h] [bp-4h]@1

    v1 = list;
    v28 = list;
    if (currently_running_lvl_boxd_valid)
    {
        if (_4773B0_boxd_item0_things && _4773A0_boxd_item0_num_things)
            memset(_4773B0_boxd_item0_things, 0, 4 * _4773A0_boxd_item0_num_things);
        _4773A8_boxd_parray = _4773C0_boxd_array;
        v2 = list->next;
        if (list->next != list)
        {
            do
            {
                if (is_async_execution_supported && (v3 = v2->script) != 0)
                    v4 = v3->field_1C & 1;
                else
                    v4 = 1;
                v5 = v2->pstru58;
                v27 = v2->pstru58;
                if (v5 && v4)
                {
                    v6 = v5->pstru0;
                    v7 = v5->pstru0->psrite_pstru7_idx;
                    if (v7 >= 0)
                    {
                        if (v2->pstru7[v7]._4_psprite_pstru7_idx)
                        {
                        LABEL_16:
                            v8 = v2->x_speed;
                            v9 = v2->x;
                            v10 = v6->x;
                            if (v8 < 0)
                            {
                                v11 = _4773AC_boxd_item0_map_x_scale;
                                v12 = (v8 + v9 + v10) >> _4773AC_boxd_item0_map_x_scale;
                                if (v12 < 0)
                                    v12 = 0;
                                v13 = v6->z + v9 - 1;
                            }
                            else
                            {
                                v11 = _4773AC_boxd_item0_map_x_scale;
                                v12 = (v9 + v10) >> _4773AC_boxd_item0_map_x_scale;
                                if (v12 < 0)
                                    v12 = 0;
                                v13 = v9 + v6->z + v8 - 1;
                            }
                            v14 = (v13 >> v11) - v12;
                            if (v12 + v14 >= _4773C8_boxd_item0_map_num_x_tiles)
                                v14 = _4773C8_boxd_item0_map_num_x_tiles - v12 - 1;
                            v15 = v2->y_speed;
                            v16 = v2->y;
                            v25 = v15;
                            v17 = v15 < 0;
                            v18 = v6->y;
                            if (v17)
                            {
                                v19 = (v2->y_speed + v16 + v18) >> _4773B8_boxd_item0_map_y_scale;
                                if (v19 < 0)
                                    v19 = 0;
                                v20 = v6->w + v16 - 1;
                            }
                            else
                            {
                                v19 = (v16 + v18) >> _4773B8_boxd_item0_map_y_scale;
                                if (v19 < 0)
                                    v19 = 0;
                                v20 = v16 + v6->w + v25 - 1;
                            }
                            v21 = (v20 >> _4773B8_boxd_item0_map_y_scale) - v19;
                            if (v19 + v21 >= _4773B4_boxd_item0_map_num_y_tiles)
                                v21 = _4773B4_boxd_item0_map_num_y_tiles - v19 - 1;
                            v22 = &_4773B0_boxd_item0_things[v12 + _4773C8_boxd_item0_map_num_x_tiles * v19];
                            if (v21 >= 0)
                            {
                                v26 = v21 + 1;
                                do
                                {
                                    v23 = v22;
                                    if (v14 >= 0)
                                    {
                                        v24 = v14 + 1;
                                        do
                                        {
                                            ++v23;
                                            _4773A8_boxd_parray->sprite_pstru58 = v27;
                                            _4773A8_boxd_parray->sprite = v2;
                                            _4773A8_boxd_parray->ptr_8 = *(v23 - 1);
                                            *(v23 - 1) = _4773A8_boxd_parray;
                                            --v24;
                                            ++_4773A8_boxd_parray;
                                        } while (v24);
                                    }
                                    v22 += _4773C8_boxd_item0_map_num_x_tiles;
                                    --v26;
                                } while (v26);
                            }
                            v1 = v28;
                            goto LABEL_41;
                        }
                    }
                    else if (v7 != -2)
                    {
                        goto LABEL_16;
                    }
                }
            LABEL_41:
                v2 = v2->next;
            } while (v2 != v1);
        }
    }
}

//----- (00404F40) --------------------------------------------------------
void boxd_404F40_sprite(Sprite *a1, int a2, int a3)
{
    Sprite *v3; // esi@1
    Script *v4; // eax@3
    signed __int16 v5; // ax@4
    Sprite_stru58 *v6; // ecx@6
    Sprite_stru58_stru0 *v7; // edi@8
    int v8; // eax@8
    Sprite_stru58 *v16; // ecx@28
    int v17; // eax@30
    int v18; // ebp@38
    stru7 *v19; // ecx@41
    bool(*v20)(Sprite *, Sprite *, int, void *, void *); // eax@41
    Sprite_stru58 *v24; // eax@45
    Sprite_stru58_stru0 *v25; // eax@45
    stru7 *v26; // ebp@46
    int v27; // ecx@47
    int v28; // ecx@49
    int(*v29)(Sprite *, void *, int, int *, int *); // eax@51
    Sprite_stru58 *v33; // eax@56
    Sprite_stru58 *v36; // [sp+10h] [bp-8Ch]@28
    Sprite_stru58 *v37; // [sp+14h] [bp-88h]@8
    Sprite_stru58 *v38; // [sp+14h] [bp-88h]@45
    int v45; // [sp+24h] [bp-78h]@31
    int v46; // [sp+28h] [bp-74h]@28
    int v48; // [sp+30h] [bp-6Ch]@9
    int v51; // [sp+3Ch] [bp-60h]@1
    int v58; // [sp+60h] [bp-3Ch]@46
    int v59; // [sp+64h] [bp-38h]@34
    int v60; // [sp+68h] [bp-34h]@34
    int v61; // [sp+6Ch] [bp-30h]@36
    int v62; // [sp+74h] [bp-28h]@35
    int v63; // [sp+78h] [bp-24h]@37
    int v64; // [sp+80h] [bp-1Ch]@47
    int v65; // [sp+84h] [bp-18h]@47
    int v66; // [sp+88h] [bp-14h]@49
    int v67; // [sp+90h] [bp-Ch]@48
    int v68; // [sp+94h] [bp-8h]@50

    v51 = a2;
    v3 = a1;
    if (currently_running_lvl_boxd_valid)
    {
        if (is_async_execution_supported && (v4 = a1->script) != 0)
            v5 = v4->field_1C & 1;
        else
            v5 = 1;
        v6 = a1->pstru58;
        if (v6)
        {
            if (v5)
            {
                v7 = v6->pstru0;
                v37 = v3->pstru58;
                v8 = v6->pstru0->psrite_pstru7_idx;
                if (v8 < 0)
                {
                    if (v8 == -3)
                        return;
                    v48 = -1;
                }
                else
                {
                    v48 = v3->pstru7[v8].field_0;
                    if (!v48)
                        return;
                }

                int z = v3->x + v7->z;
                int y_y = v3->y + v7->w;

                int x = v3->x + v7->x;
                int y = v3->y + v7->y;

                int v53 = v6->pstru0->psrite_pstru7_idx;

                int x_scaled = x >> _4773AC_boxd_item0_map_x_scale;
                if (x_scaled < 0)
                    x_scaled = 0;

                int z_scaled = (z - 1) >> _4773AC_boxd_item0_map_x_scale;
                if (z_scaled >= _4773C8_boxd_item0_map_num_x_tiles)
                    z_scaled = _4773C8_boxd_item0_map_num_x_tiles - 1;

                int width_scaled = z_scaled - x_scaled;

                int y_scaled = y >> _4773B8_boxd_item0_map_y_scale;
                if (y_scaled < 0)
                    y_scaled = 0;

                int w_scaled = (y_y - 1) >> _4773B8_boxd_item0_map_y_scale;
                if (w_scaled >= _4773B4_boxd_item0_map_num_y_tiles)
                    w_scaled = _4773B4_boxd_item0_map_num_y_tiles - 1;

                int height_scaled = w_scaled - y_scaled;


                for (int k = 0; k <= height_scaled; ++k)
                {
                    for (int j = 0; j <= width_scaled; ++j)
                    {
                        int tile_idx = (x_scaled + j) + (y_scaled + k) * _4773C8_boxd_item0_map_num_x_tiles;
                        BoxdTile **tile = &_4773C4_boxd_item0_map_tiles[tile_idx];
                        Boxd_stru0 **tile_extra = &_4773B0_boxd_item0_things[tile_idx];

                        for (Boxd_stru0 *i = *tile_extra; i; i = i->ptr_8)
                        {
                            if (i->sprite != v3)
                            {
                                v16 = i->sprite_pstru58;
                                v46 = 1;
                                v36 = i->sprite_pstru58;
                                do
                                {
                                    if (!v16->pstru0)
                                        break;
                                    v17 = v16->pstru0->psrite_pstru7_idx;
                                    if (v17 >= 0)
                                    {
                                        v45 = v3->pstru7[v17]._4_psprite_pstru7_idx;
                                        v16 = v36;
                                    }
                                    else
                                    {
                                        v46 = 0;
                                        v45 = -1;
                                    }
                                    if (v48 & v45)
                                    {
                                        v59 = v17;
                                        v60 = i->sprite->x + v16->pstru0->x;
                                        if (v60 < z)
                                        {
                                            v62 = i->sprite->x + v16->pstru0->z;
                                            if (v62 > x)
                                            {
                                                v61 = i->sprite->y + v16->pstru0->y;
                                                if (v61 < y_y)
                                                {
                                                    v63 = i->sprite->y + v16->pstru0->w;
                                                    if (v63 > y)
                                                    {
                                                        v18 = v16->pstru0->psrite_pstru7_idx;
                                                        if (v18 >= 0)
                                                        {
                                                            if (v7->psrite_pstru7_idx < 0)
                                                            {
                                                                v24 = v37 + 1;
                                                                v38 = v24;
                                                                v25 = v24->pstru0;
                                                                if (v25)
                                                                {
                                                                    do
                                                                    {
                                                                        v26 = v3->pstru7;
                                                                        v58 = v25->psrite_pstru7_idx;
                                                                        if (v45 & v26[v58].field_0)
                                                                        {
                                                                            v27 = v3->x;
                                                                            v64 = v58;
                                                                            v65 = v27 + v38->pstru0->x;
                                                                            if (v65 < v62)
                                                                            {
                                                                                v67 = v27 + v38->pstru0->z;
                                                                                if (v67 > v60)
                                                                                {
                                                                                    v28 = v3->y;
                                                                                    v66 = v28 + v38->pstru0->y;
                                                                                    if (v66 < v63)
                                                                                    {
                                                                                        v68 = v28 + v38->pstru0->w;
                                                                                        if (v68 > v61)
                                                                                        {
                                                                                            v29 = (int(*)(Sprite *, void *, int, int *, int *))v26[v38->pstru0->psrite_pstru7_idx].pfn_8_ui_hint_box;
                                                                                            if (v29
                                                                                                || (v29 = (int(*)(Sprite *, void *, int, int *, int *))v26[v36->pstru0->psrite_pstru7_idx].pfn_C) != 0)
                                                                                            {
                                                                                                if (v29(v3, i->sprite, v51, &v64, &v59))
                                                                                                {
                                                                                                    x = v3->x + v7->x;
                                                                                                    y = v3->y + v7->y;

                                                                                                    z = v3->x + v7->z;
                                                                                                    y_y = v3->y + v7->w;
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                        v33 = v38 + 1;
                                                                        v38 = v33;
                                                                        v25 = v33->pstru0;
                                                                    } while (v25);
                                                                    v16 = v36;
                                                                }
                                                                v37 = v3->pstru58;
                                                            }
                                                            else
                                                            {
                                                                v19 = v3->pstru7;
                                                                v20 = v19[v7->psrite_pstru7_idx].pfn_8_ui_hint_box;
                                                                if (v20 || (v20 = v19[v18].pfn_C) != 0)
                                                                {
                                                                    if (v20(v3, i->sprite, v51, &v53, &v59))
                                                                    {
                                                                        x = v3->x + v7->x;
                                                                        y = v3->y + v7->y;

                                                                        z = v3->x + v7->z;
                                                                        y_y = v3->y + v7->w;
                                                                    }
                                                                }
                                                                v16 = v36;
                                                            }
                                                        }
                                                        else
                                                        {
                                                            v46 = 1;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    ++v16;
                                    v36 = v16;
                                } while (v46);
                            }
                        }
                        ++_4773A8_boxd_parray;
                    }
                }
            }
        }
    }
}

//----- (00405430) --------------------------------------------------------
void boxd_free()
{
    if (currently_running_lvl_boxd_valid)
    {
        if (_4773B0_boxd_item0_things)
            free(_4773B0_boxd_item0_things);
        if (_4773C0_boxd_array)
            free(_4773C0_boxd_array);
    }
}
// 4773BC: using guessed type int currently_running_lvl_boxd_valid;



//----- (0040DBF0) --------------------------------------------------------
bool entity_40DBF0_boxd_does_unit_fit(Entity *a1)
{
    enum UNIT_ID v1; // eax@1
    stru196 *v2; // edx@1
    enum UNIT_ID v3; // esi@1
    Sprite *v4; // eax@4
    int v5; // esi@4
    int v6; // edi@4
    int v7; // eax@4
    int v8; // ebx@6
    int v9; // edx@7
    int v10; // edx@9
    DataBoxd_stru0_per_map_unit *v11; // ebp@9
    DataBoxd_stru0_per_map_unit *v12; // eax@10
    int v13; // esi@10
    Entity *v14; // edx@12
    int v16; // [sp+10h] [bp-Ch]@8
    int v17; // [sp+18h] [bp-4h]@7

    v1 = array_4701D8[0].unit_id;
    v2 = array_4701D8;
    v3 = a1->unit_id;
    if (array_4701D8[0].unit_id == v3)
    {
    LABEL_4:
        v4 = a1->sprite;
        v5 = (int)&a1->stru60.ptr_C->field_0;
        v6 = (*(_DWORD *)(v5 + 4) + v4->x) >> 13;
        v7 = (*(_DWORD *)(v5 + 8) + v4->y) >> 13;
        if (v6 >= 0 && v7 >= 0)
        {
            v8 = v2->_4_x + v6;
            if (v8 - 1 < map_get_width())
            {
                v9 = v7 + v2->_8_y;
                v17 = v9;
                if (v9 - 1 < map_get_height())
                {
                    v16 = v7;
                    if (v7 >= v9)
                        return 1;
                    v10 = 24 * map_get_width();
                    v11 = boxd_get_tile(v6, v7);
                    while (1)
                    {
                        v12 = v11;
                        v13 = v6;
                        if (v6 < v8)
                            break;
                    LABEL_17:
                        v11 = (DataBoxd_stru0_per_map_unit *)((char *)v11 + v10);
                        if (++v16 >= v17)
                            return 1;
                    }
                    while (1)
                    {
                        if (v12->flags & 0x1F)
                        {
                            v14 = v12->_4_entities[0];
                            if (!v14 || v14->entity_id != a1->entity_id)
                                break;
                        }
                        if (v12->flags2 & 0x40)
                            break;
                        ++v12;
                        if (++v13 >= v8)
                        {
                            v10 = 24 * map_get_width();
                            goto LABEL_17;
                        }
                    }
                }
            }
        }
    }
    else
    {
        while (v1 != -1)
        {
            v1 = v2[1].unit_id;
            ++v2;
            if (v1 == v3)
                goto LABEL_4;
        }
    }
    return 0;
}

//----- (0040DD00) --------------------------------------------------------
bool entity_40DD00_boxd(Entity *a1)
{
    enum UNIT_ID v1; // edx@1
    enum UNIT_ID v2; // eax@1
    stru196 *v3; // ebx@1
    DataMobdItem_stru1 *v4; // eax@4
    Sprite *v5; // ecx@4
    int v6; // edx@4
    int v7; // ebp@4
    int v8; // eax@4
    int v9; // edx@4
    int v10; // edi@4
    int i; // ebp@4
    int v12; // esi@5
    unsigned int v14; // [sp+10h] [bp-Ch]@1
    Entity *a1a; // [sp+14h] [bp-8h]@1
    int v16; // [sp+18h] [bp-4h]@4

    v1 = a1->unit_id;
    v2 = array_4701D8[0].unit_id;
    a1a = a1;
    v14 = 0x80000000;
    v3 = array_4701D8;
    if (array_4701D8[0].unit_id == v1)
    {
    LABEL_4:
        v4 = a1->stru60.ptr_C;
        v5 = a1->sprite;
        v6 = v4->y_offset + v5->y;
        v7 = v4->x_offset + v5->x;
        v8 = 0;
        v9 = v6 >> 13;
        v16 = v9;
        v10 = v9;
        for (i = v7 >> 13; v10 < v3->_8_y + v9; ++v10)
        {
            v12 = i;
            if (i < v3->_4_x + i)
            {
                do
                {
                    if (v14 & v3->field_14)
                        v8 = Map_40EEB0_place_entity(a1a, v12, v10, 0);
                    else
                        v8 = Map_40EEB0_place_entity(a1a, v12, v10, 64);
                    v14 >>= 1;
                    ++v12;
                } while (v12 < v3->_4_x + i);
                v9 = v16;
            }
            if (v8 == 5)
                break;
        }
        return true;
    }
    else
    {
        while (v2 != -1)
        {
            v2 = v3[1].unit_id;
            ++v3;
            if (v2 == v1)
                goto LABEL_4;
        }
        return false;
    }
}

//----- (0040DDD0) --------------------------------------------------------
int entity_40DDD0_boxd(Entity *a1)
{
    enum UNIT_ID v1; // edx@1
    int result; // eax@1
    stru196 *v3; // ebx@1
    Sprite *v4; // eax@4
    DataMobdItem_stru1 *v5; // ecx@4
    int v6; // edi@4
    int v7; // ebp@4
    int i; // edi@4
    int v9; // esi@5
    int v10; // [sp+10h] [bp-Ch]@1
    Entity *v11; // [sp+14h] [bp-8h]@1
    int v12; // [sp+18h] [bp-4h]@4

    v1 = a1->unit_id;
    result = array_4701D8[0].unit_id;
    v11 = a1;
    v10 = 0x80000000;
    v3 = array_4701D8;
    if (array_4701D8[0].unit_id == v1)
    {
    LABEL_4:
        v4 = a1->sprite;
        v5 = a1->stru60.ptr_C;
        v6 = v5->x_offset + v4->x;
        result = (v5->y_offset + v4->y) >> 13;
        v12 = result;
        v7 = result;
        for (i = v6 >> 13; v7 < v3->_8_y + result; ++v7)
        {
            v9 = i;
            if (i < v3->_4_x + i)
            {
                do
                {
                    boxd_40F160(v11, v9++, v7, 0);
                    v10 >>= 1;
                } while (v9 < v3->_4_x + i);
                result = v12;
            }
        }
    }
    else
    {
        while (result != -1)
        {
            result = v3[1].unit_id;
            ++v3;
            if (result == v1)
                goto LABEL_4;
        }
    }
    return result;
}

//----- (0040DE80) --------------------------------------------------------
int map_place_entity(Entity *a1, int x, int y, int a3)
{
    if (entity_is_xl_vehicle(a1))
        return Map_40E1B0_place_xl_entity(a1, x, y, a3) != 4 ? ENTITY_TILE_POSITION_INVALID : ENTITY_MAKE_TILE_POSITION(0);
    else
        return Map_40EEB0_place_entity(a1, global2map(x), global2map(y), a3);
}

//----- (0040DEC0) --------------------------------------------------------
char *entity_40DEC0_boxd(Entity *a1, int a2, int a3, int a4)
{
    Entity *v4; // ebp@1
    char *result; // eax@2
    Sprite *v6; // eax@3
    int v7; // ecx@3
    int v8; // eax@3
    int v9; // esi@3
    int v10; // edi@3
    int v11; // ebx@3
    int v12; // esi@3
    int v13; // edi@3
    char *i; // [sp+14h] [bp+4h]@3
    int v15; // [sp+18h] [bp+8h]@3

    v4 = a1;
    if (entity_is_xl_vehicle(a1))
    {
        v6 = a1->sprite;
        v7 = v6->y;
        v8 = v6->x;
        v9 = v8 - 4096;
        v10 = v8 + 4096;
        v11 = (v7 - 4096) >> 13;
        result = (char *)((v7 + 4096) >> 13);
        v12 = v9 >> 13;
        v13 = v10 >> 13;
        v15 = v12;
        for (i = (char *)((v7 + 4096) >> 13); v11 <= (int)result; ++v11)
        {
            if (v12 <= v13)
            {
                do
                    boxd_40F160(v4, v12++, v11, 0);
                while (v12 <= v13);
                v12 = v15;
                result = i;
            }
        }
    }
    else
    {
        result = (char *)boxd_40F160(a1, a2, a3, a4);
    }
    return result;
}

//----- (0040DF50) --------------------------------------------------------
void Map_40DF50_update_tile(Entity *a1, int a2)
{
    Entity *v2; // ebp@1
    int v3;
    int v7; // ebx@3
    int v8; // esi@3
    int v9; // edi@3
    int v11; // [sp+14h] [bp-8h]@3

    v2 = a1;
    if (entity_is_xl_vehicle(a1))
    {
        v7 = global2map(a1->sprite->y - 1 * 4096);
        v3 = global2map(a1->sprite->y + 1 * 4096);
        v8 = global2map(a1->sprite->x - 1 * 4096);
        v9 = global2map(a1->sprite->x + 1 * 4096);
        for (v7; v7 <= v3; ++v7)
        {
            for (v11 = v8; v11 <= v9; ++v11)
            {
                Map_40F230_update_tile(v2, v11++, v7, 0, a2);
            }
        }
    }
    else
    {
        Map_40F230_update_tile(a1, a1->sprite_map_x, a1->sprite_map_y, a1->_A4_idx_in_tile, a2);
    }
}

//----- (0040E000) --------------------------------------------------------
int entity_40E000_boxd(Entity *a1, int a2, int a3)
{
    Entity *v3; // edi@1
    DataBoxd_stru0_per_map_unit *v4; // ebx@1
    DataBoxd_stru0_per_map_unit *v5; // esi@2
    int result; // eax@2
    int v7; // ecx@4
    Entity **v8; // edx@4
    int v9; // edi@9
    int v10; // ebp@9
    int v11; // esi@9
    int v12; // edx@9
    int v13; // edi@9
    int v14; // ebp@9
    int v15; // ecx@9
    int v16; // ebx@10
    DataBoxd_stru0_per_map_unit *v17; // esi@10
    int v18; // eax@11
    int v19; // eax@12
    int v20; // eax@24
    Entity **v21; // ecx@24
    int v22; // eax@29
    DataBoxd_stru0_per_map_unit *v23; // [sp+10h] [bp-14h]@1
    int v24; // [sp+14h] [bp-10h]@9
    int v25; // [sp+18h] [bp-Ch]@9
    Entity *a1a; // [sp+1Ch] [bp-8h]@1
    int v27; // [sp+20h] [bp-4h]@9
    int v28; // [sp+28h] [bp+4h]@9

    v3 = a1;
    v4 = 0;
    a1a = a1;
    v23 = 0;
    if (a1->stats->field_4C != 4096)
    {
        v5 = boxd_get_tile(a2 >> 13, a3 >> 13);
        result = boxd_40ED00(a1, v5);
        if (result == 1 || result == 3)
        {
            v7 = 0;
            v8 = v5->_4_entities;
            while (!*v8)
            {
                ++v7;
                ++v8;
                if (v7 >= 5)
                    return result;
            }
            v3->entity_27C = v5->_4_entities[v7];
            v3->entity_27C_entity_id = v5->_4_entities[v7]->entity_id;
        }
        return result;
    }
    v9 = a2 - 4096;
    v10 = a2 + 4096;
    v11 = 0;
    v12 = (a3 + 4096) >> 13;
    v13 = v9 >> 13;
    v14 = v10 >> 13;
    v27 = (a3 + 4096) >> 13;
    v25 = 0;
    v24 = 0;
    v28 = (a3 - 4096) >> 13;
    v15 = v28;
    if (v28 <= v12)
    {
        do
        {
            v16 = v13;
            v17 = boxd_get_tile(v13, v15);
            if (v13 <= v14)
            {
                while (1)
                {
                    v18 = boxd_40ED00(a1a, v17);
                    if (!v18)
                        return 0;
                    v19 = v18 - 1;
                    if (!v19)
                        break;
                    if (v19 == 2)
                    {
                        ++v25;
                    LABEL_16:
                        v23 = v17;
                    }
                    ++v16;
                    ++v17;
                    if (v16 > v14)
                    {
                        v15 = v28;
                        v12 = v27;
                        goto LABEL_19;
                    }
                }
                ++v24;
                goto LABEL_16;
            }
        LABEL_19:
            v28 = ++v15;
        } while (v15 <= v12);
        v4 = v23;
        v11 = v24;
    }
    if (v11 || v25)
    {
        v20 = 0;
        v21 = v4->_4_entities;
        while (!*v21)
        {
            ++v20;
            ++v21;
            if (v20 >= 5)
                goto LABEL_29;
        }
        a1a->entity_27C = v4->_4_entities[v20];
        a1a->entity_27C_entity_id = v4->_4_entities[v20]->entity_id;
    LABEL_29:
        v22 = -(v11 != 0);
        LOBYTE_HEXRAYS(v22) = v22 & 0xFE;
        result = v22 + 3;
    }
    else
    {
        result = 2;
    }
    return result;
}
// 4793F8: using guessed type int map_get_width();

//----- (0040E1B0) --------------------------------------------------------
int Map_40E1B0_place_xl_entity(Entity *a1, int x, int y, int a4)
{
    Entity *v4; // edi@1
    int v5; // esi@1
    int v6; // eax@1
    int v7; // ecx@1
    int v8; // ebp@1
    int v9; // ebx@1
    int v11; // eax@9
    int v12; // ebp@9
    int i; // esi@10
    int a2a; // [sp+10h] [bp-8h]@1
    int v15; // [sp+14h] [bp-4h]@1
    int ya; // [sp+1Ch] [bp+4h]@1
    int a4a; // [sp+20h] [bp+8h]@9

    v4 = a1;
    v5 = -1;
    v6 = -1;
    v7 = a1->stats->field_4C;
    a2a = (x - v7) >> 13;
    v8 = (y - v7) >> 13;
    v9 = (v7 + x) >> 13;
    v15 = v8;
    ya = (y + v7) >> 13;
    if (v8 > ya)
    {
    LABEL_7:
        if (v6 != 5)
        {
            v4->_A4_idx_in_tile = 0;
            return 4;
        }
    }
    else
    {
        while (1)
        {
            v5 = a2a;
            if (a2a <= v9)
                break;
        LABEL_5:
            if (v6 == 5)
                goto LABEL_9;
            if (++v8 > ya)
                goto LABEL_7;
        }
        while (1)
        {
            v6 = Map_40EEB0_place_entity(v4, v5, v8, a4);
            if (v6 == 5)
                break;
            if (++v5 > v9)
                goto LABEL_5;
        }
    }
LABEL_9:
    v11 = boxd_40EA50_classify_tile_objects(v4, v5, v8, boxd_get_tile(v5, v8));
    v12 = v15;
    for (a4a = v11; v12 <= ya; ++v12)
    {
        for (i = a2a; i <= v9; ++i)
            boxd_40F160(v4, i, v12, 0);
    }
    return a4a;
}


//----- (0040E6E0) --------------------------------------------------------
bool boxd_40E6E0()
{
    DataBoxd *v0; // eax@1
    DataBoxdItem *v1; // ebx@2
    int v2; // edi@2
    int v3; // eax@2
    DataBoxd_stru0_per_map_unit *v4; // eax@2
    BOOL result; // eax@3
    int v6; // esi@4
    int v7; // ecx@5
    int v8; // eax@6
    int v9; // edx@6
    BoxdTile *ptile; // edx@12
    BoxdTile_stru0 *ptilE; // eax@12
    int v12; // eax@13
    DataBoxd_stru0_per_map_unit *v13; // esi@16
    int v14; // edi@16
    int v15; // ebp@16
    int v16; // edx@17
    int v17; // edi@19
    int v18; // ebp@19
    int v19; // eax@21
    BoxdTile_stru0 *v20; // ecx@21
    int v21; // edx@21
    int v22; // ecx@25
    int v23; // ecx@26
    DataBoxd_stru0_per_map_unit *v24; // [sp+10h] [bp-34h]@9
    BoxdTile *pt1le; // [sp+14h] [bp-30h]@12
    int j; // [sp+18h] [bp-2Ch]@10
    BoxdTile **tiles; // [sp+1Ch] [bp-28h]@4
    int i; // [sp+20h] [bp-24h]@9
    int v29; // [sp+24h] [bp-20h]@19
    DataBoxdItem *v30; // [sp+28h] [bp-1Ch]@2
    int v31; // [sp+2Ch] [bp-18h]@16
    int v32; // [sp+30h] [bp-14h]@2
    int v33; // [sp+34h] [bp-10h]@2
    int v34; // [sp+38h] [bp-Ch]@19

    extern int _4793F8_map_width;
    extern int _478AAC_map_height;
    extern int _478AB4_map_width_shl_13;
    extern int _478FF0_map_height_shl_13;

    byte_478C08 = 0;
    kknd_srand_3(0);
    dword_478FF4 = 0;
    dword_47953C = 0;
    dword_47952C = 0;
    dword_478AB0 = 0;
    v0 = (DataBoxd *)LVL_FindSection(BOXD);
    if (v0)
    {
        v1 = v0->items;
        v30 = v1;
        v2 = v0->items->some_map_width_scale - 13;
        v32 = v0->items->some_map_width_scale - 13;
        _4793F8_map_width = v0->items->map_num_x_tiles << v32;
        v33 = v1->some_map_height_scale - 13;
        v3 = v1->map_num_y_tiles << v33;
        _478AAC_map_height = v3;

        _478AB4_map_width_shl_13 = map2global(map_get_width());
        _478FF0_map_height_shl_13 = map2global(v3);
        v4 = (DataBoxd_stru0_per_map_unit *)malloc(24 * map_get_width() * v3);
        _478AA8_boxd_stru0_array = v4;
        if (!v4)
            return 0;
        tiles = v1->map_tiles;
        v6 = 0;
        if (map_get_width() * map_get_height() > 0)
        {
            v7 = 0;
            do
            {
                v4[v7].flags = 0;
                v8 = v7 * 24 + 4;
                _478AA8_boxd_stru0_array[v7].flags2 = 0;
                v9 = 5;
                do
                {
                    v8 += 4;
                    --v9;
                    *(_DWORD *)((char *)_478AA8_boxd_stru0_array + v8 - 4) = 0;// array_4 (5 bytes)
                } while (v9);
                ++v6;
                ++v7;
                v4 = _478AA8_boxd_stru0_array;
            } while (v6 < map_get_width() * map_get_height());
        }
        v24 = v4;
        for (i = 0; i < v1->map_num_y_tiles; ++i)
        {
            for (j = 0; j < v1->map_num_x_tiles; ++j)
            {
                if (*tiles)
                {
                    ptile = *tiles;
                    pt1le = *tiles;
                    ptilE = (*tiles)->pstru0;
                    if (ptilE)
                    {
                        do
                        {
                            v12 = ptilE->type;
                            if (v12 == 6 || v12 == 7 || v12 == 8)
                            {
                                v13 = v24;
                                v14 = 0;
                                v15 = 1 << v33;
                                v31 = 0;
                                if (1 << v33 > 0)
                                {
                                    v16 = 1 << v32;
                                    do
                                    {
                                        if (v16 > 0)
                                        {
                                            v17 = v14 << 13;
                                            v34 = v17;
                                            v18 = 0;
                                            v29 = v16;
                                            while (1)
                                            {
                                                v19 = v18 + (j << v1->some_map_width_scale);
                                                v20 = pt1le->pstru0;
                                                v21 = v17 + (i << v1->some_map_height_scale);
                                                if (pt1le->pstru0->_4_x < v19 + 0x2000
                                                    && v20->_10_z > v19
                                                    && v20->_8_y < v21 + 0x2000
                                                    && v20->_14_w > v21)
                                                {
                                                    v22 = v20->type - 6;
                                                    if (v22)
                                                    {
                                                        v23 = v22 - 1;
                                                        if (v23)
                                                        {
                                                            if (v23 == 1)
                                                            {
                                                                v13->flags = 0;
                                                                v13->flags2 = 64;
                                                            }
                                                        }
                                                        else
                                                        {
                                                            v13->flags = 63;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        v13->flags = 95;
                                                    }
                                                }
                                                v1 = v30;
                                                v18 += 0x2000;
                                                ++v13;
                                                if (!--v29)
                                                    break;
                                                v17 = v34;
                                            }
                                            v14 = v31;
                                            v15 = 1 << v33;
                                            v16 = 1 << v32;
                                        }
                                        v31 = ++v14;
                                        v13 += map_get_width() - v16;
                                    } while (v14 < v15);
                                    ptile = pt1le;
                                }
                            }
                            ptilE = (BoxdTile_stru0 *)ptile->ptr_4;
                            ptile = (BoxdTile *)((char *)ptile + 4);
                            pt1le = ptile;
                        } while (ptilE);
                        LOBYTE_HEXRAYS(v2) = v32;
                    }
                }
                v24 += 1 << v2;
                ++tiles;
            }
            v24 += map_get_width() * ((1 << v33) - 1);
        }
    }
    else
    {
        _478AAC_map_height = 0;
        _4793F8_map_width = 0;
        _478AA8_boxd_stru0_array = 0;
    }
    result = 1;
    _478BE8_map_info__see40E6E0[0] = -map_get_width();
    _478BE8_map_info__see40E6E0[1] = 1 - map_get_width();
    _478BE8_map_info__see40E6E0[3] = map_get_width() + 1;
    _478BE8_map_info__see40E6E0[5] = map_get_width() - 1;
    _478BE8_map_info__see40E6E0[2] = 1;
    _478BE8_map_info__see40E6E0[4] = map_get_width();
    _478BE8_map_info__see40E6E0[6] = -1;
    _478BE8_map_info__see40E6E0[7] = -1 - map_get_width();
    return result;
}

//----- (0040EA20) --------------------------------------------------------
void boxd_40EA20_gameloop_update()
{
    ++dword_47953C;
}
// 47953C: using guessed type int dword_47953C;

//----- (0040EA30) --------------------------------------------------------
void boxd_40EA30_cleanup()
{
    free(_478AA8_boxd_stru0_array);
    _478AA8_boxd_stru0_array = 0;
}

//----- (0040EA50) --------------------------------------------------------
int boxd_40EA50_original(Entity *a1, int map_x, int map_y, DataBoxd_stru0_per_map_unit *a4)
{
    int v4; // eax@1
    int v5; // edx@2
    int v6; // eax@5
    int v7; // eax@8
    int v8; // edi@8
    DataBoxd_stru0_per_map_unit *v9; // ebx@13
    char v10; // al@13
    enum PLAYER_SIDE v11; // ebp@24
    int v12; // edi@24
    Entity **v13; // esi@24
    int result; // eax@37
    char v15; // al@39
    char v16; // al@44
    Entity **v17; // esi@46
    enum PLAYER_SIDE v18; // ebx@51
    int v19; // edi@51
    int v20; // eax@57
    int v21; // [sp+10h] [bp-1Ch]@8
    int v22; // [sp+14h] [bp-18h]@8
    int v23; // [sp+18h] [bp-14h]@8
    int v24; // [sp+1Ch] [bp-10h]@8
    Entity *v25; // [sp+20h] [bp-Ch]@1
    int v26; // [sp+24h] [bp-8h]@8
    int v27; // [sp+28h] [bp-4h]@1

    v4 = map_x;
    v27 = map_x;
    v25 = a1;
    if (map_x < 0)
        return 0;
    v5 = map_get_width();
    if (v4 >= map_get_width() || map_y < 0 || map_y >= map_get_height())
        return 0;
    v6 = a1->stats->field_4C;
    if (v6 == 128)
    {
        v16 = a4->flags;
        if (a4->flags & 0x60 && !(v16 & 0x80))
            return 0;
        v17 = a4->_4_entities;
        if (a4->_4_entities[0] == a1)
        {
            result = 2;
        }
        else if (v16 & 0x1F)
        {
            if (!(v16 & 0x80))
            {
                v18 = a1->player_side;
                v19 = 0;
                while (!*v17 || is_enemy(v18, *v17))
                {
                    ++v19;
                    ++v17;
                    if (v19 >= 5)
                    {
                        if (!v25->stats->can_squash_infantry)
                            break;
                        return 2;
                    }
                }
            }
            v20 = -(((a4->flags ^ a4->flags2) & 0x1F) != 0);
            LOBYTE_HEXRAYS(v20) = v20 & 0xFE;
            result = v20 + 3;
        }
        else
        {
            result = 2;
        }
        return result;
    }
    else if (v6 == 512)
    {
        v15 = a4->flags;
        if (!(a4->flags & 0x60) || v15 & 0x80)
        {
            if ((v15 & 0x1F) == 31)
                result = (a4->flags2 & 0x1F) != 0 ? 3 : 1;
            else
                result = 2;
            return result;
        }
    }
    else if (entity_is_xl_vehicle(a1))
    {
        v7 = 0;
        v8 = 0;
        v23 = 0;
        v24 = 0;
        v26 = 0;
        v22 = 0;
        v21 = 0;
        while (v8 + v27 < v5 && v7 + map_y < map_get_height())
        {
            v9 = &a4[v8 + (v7 != 0 ? v5 : 0)];
            v10 = v9->flags;
            if (v9->flags & 0x60 && !(v10 & 0x80))
                v26 = 1;
            if (v10 & 0x80 && v9->_4_entities[0] != v25)
            {
                if ((v9->flags2 & 0x1F) == 31)
                    v24 = 1;
                else
                    v23 = 1;
            }
            if (!(v10 & 0x80) && v10 & 0x1F)
            {
                if (v25->stats->can_squash_infantry)
                {
                    v11 = v25->player_side;
                    v12 = 0;
                    v13 = v9->_4_entities;
                    while (!*v13 || is_enemy(v11, *v13))
                    {
                        ++v12;
                        ++v13;
                        if (v12 >= 5)
                        {
                            v8 = v21;
                            goto LABEL_33;
                        }
                    }
                    v8 = v21;
                }
                if ((v9->flags ^ v9->flags2) & 0x1F)
                    v23 = 1;
                else
                    v24 = 1;
            }
        LABEL_33:
            v7 = v22;
            v21 = ++v8;
            if (v8 < 2)
            {
                v5 = map_get_width();
            }
            else
            {
                v7 = v22 + 1;
                v22 = v7;
                if (v7 >= 2)
                {
                    if (v26)
                        return 0;
                    if (v23)
                        result = 1;
                    else
                        result = (v24 != 0) + 2;
                    return result;
                }
                v5 = map_get_width();
                v8 = 0;
                v21 = 0;
            }
        }
    }
    return 0;
}

//----- (0040EA50) --------------------------------------------------------
int boxd_40EA50_refactored(Entity *entity, int map_x, int map_y, DataBoxd_stru0_per_map_unit *tile)
{
    int v6; // eax@5
    int v7; // eax@8
    int v8; // edi@8
    DataBoxd_stru0_per_map_unit *v9; // ebx@13
    enum PLAYER_SIDE v11; // ebp@24
    int v12; // edi@24
    Entity **v13; // esi@24
    int result; // eax@37
    Entity **v17; // esi@46
    enum PLAYER_SIDE v18; // ebx@51
    int v19; // edi@51
    int v20; // eax@57
    int v21; // [sp+10h] [bp-1Ch]@8
    int v22; // [sp+14h] [bp-18h]@8
    int v23; // [sp+18h] [bp-14h]@8
    int v24; // [sp+1Ch] [bp-10h]@8
    int v26; // [sp+24h] [bp-8h]@8

    if (map_x < 0 || map_x >= map_get_width() || map_y < 0 || map_y >= map_get_height())
        return 0;
    v6 = entity->stats->field_4C;
    if (v6 == 128)
    {
        if (tile->IsImpassibleTerrain() && !tile->IsVehicleOrBuilding())
            return 0;
        v17 = tile->_4_entities;
        if (tile->_4_entities[0] == entity)
        {
            return 2;
        }
        else if (tile->flags & BOXD_STRU0_ALL_SLOTS)
        {
            if (!tile->IsVehicleOrBuilding())
            {
                v18 = entity->player_side;
                v19 = 0;
                while (!*v17 || is_enemy(v18, *v17))
                {
                    ++v19;
                    ++v17;
                    if (v19 >= 5)
                    {
                        if (!entity->stats->can_squash_infantry)
                            break;
                        return 2;
                    }
                }
            }
            v20 = -(((tile->flags ^ tile->flags2) & BOXD_STRU0_ALL_SLOTS) != 0);
            LOBYTE_HEXRAYS(v20) = v20 & 0xFE;
            return v20 + 3;
        }
        else
        {
            return 2;
        }
    }
    else if (v6 == 512)
    {
        if (!tile->IsImpassibleTerrain() || tile->IsVehicleOrBuilding())
        {
            if ((tile->flags & BOXD_STRU0_ALL_SLOTS) == BOXD_STRU0_ALL_SLOTS)
                return (tile->flags2 & BOXD_STRU0_ALL_SLOTS) != 0 ? 3 : 1;
            else
                return 2;
        }
    }
    else if (entity_is_xl_vehicle(entity))
    {
        v7 = 0;
        v8 = 0;
        v23 = 0;
        v24 = 0;
        v26 = 0;
        v22 = 0;
        v21 = 0;
        while (v8 + map_x < map_get_width() && v7 + map_y < map_get_height())
        {
            v9 = &tile[v8 + (v7 != 0 ? map_get_width() : 0)];
            if (v9->IsImpassibleTerrain() && !v9->IsVehicleOrBuilding())
                v26 = 1;
            if (v9->IsVehicleOrBuilding() && v9->_4_entities[0] != entity)
            {
                if ((v9->flags2 & BOXD_STRU0_ALL_SLOTS) == BOXD_STRU0_ALL_SLOTS)
                    v24 = 1;
                else
                    v23 = 1;
            }
            if (!v9->IsVehicleOrBuilding() && v9->flags & BOXD_STRU0_ALL_SLOTS)
            {
                if (entity->stats->can_squash_infantry)
                {
                    v11 = entity->player_side;
                    v12 = 0;
                    v13 = v9->_4_entities;
                    while (!*v13 || is_enemy(v11, *v13))
                    {
                        ++v12;
                        ++v13;
                        if (v12 >= 5)
                        {
                            v8 = v21;
                            goto LABEL_33;
                        }
                    }
                    v8 = v21;
                }
                if ((v9->flags ^ v9->flags2) & BOXD_STRU0_ALL_SLOTS)
                    v23 = 1;
                else
                    v24 = 1;
            }
        LABEL_33:
            v7 = v22;
            v21 = ++v8;
            if (v8 < 2)
            {
                ;
            }
            else
            {
                v7 = v22 + 1;
                v22 = v7;
                if (v7 >= 2)
                {
                    if (v26)
                        return 0;
                    if (v23)
                        result = 1;
                    else
                        result = (v24 != 0) + 2;
                    return result;
                }
                v8 = 0;
                v21 = 0;
            }
        }
    }
    return 0;
}

int boxd_40EA50_classify_tile_objects(Entity *a1, int map_x, int map_y, DataBoxd_stru0_per_map_unit *a4) {
    int one = boxd_40EA50_original(a1, map_x, map_y, a4);
    int two = boxd_40EA50_refactored(a1, map_x, map_y, a4);
    assert(one == two);
    return two;
}

//----- (0040ED00) --------------------------------------------------------
int boxd_40ED00(Entity *a1, DataBoxd_stru0_per_map_unit *a2)
{
    Entity *v2; // ebp@1
    int v3; // eax@1
    int result; // eax@4
    char v5; // al@5
    char v6; // al@11
    Entity **v7; // esi@14
    enum PLAYER_SIDE v8; // ebx@19
    int v9; // edi@19
    int v10; // eax@26
    DataBoxd_stru0_per_map_unit *v11; // [sp+10h] [bp-4h]@1

    v2 = a1;
    v11 = a2;
    v3 = a1->stats->field_4C;
    if (v3 != 128)
    {
        if (v3 == 512)
        {
            v5 = a2->flags;
            if (!(a2->flags & 0x60) || v5 & 0x80)
            {
                if ((v5 & 0x1F) == 31)
                    result = (a2->flags2 & 0x1F) != 0 ? 3 : 1;
                else
                    result = 2;
            }
            else
            {
                result = 0;
            }
            return result;
        }
        if (v3 != 4096)
            return 0;
    }
    v6 = a2->flags;
    if (!(a2->flags & 0x60) || v6 & 0x80)
    {
        v7 = a2->_4_entities;
        if (a2->_4_entities[0] == a1)
        {
            result = 2;
        }
        else if (v6 & 0x1F)
        {
            if (!(v6 & 0x80))
            {
                v8 = a1->player_side;
                v9 = 0;
                while (!*v7 || is_enemy(v8, *v7))
                {
                    ++v9;
                    ++v7;
                    if (v9 >= 5)
                    {
                        if (v2->stats->can_squash_infantry)
                            return 2;
                        break;
                    }
                }
                a2 = v11;
            }
            v10 = -(((a2->flags ^ a2->flags2) & 0x1F) != 0);
            LOBYTE_HEXRAYS(v10) = v10 & 0xFE;
            result = v10 + 3;
        }
        else
        {
            result = 2;
        }
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (0040EDF0) --------------------------------------------------------
bool boxd_40EDF0(DataBoxd_stru0_per_map_unit *a1, Entity *a2, Entity *a3)
{
    Entity *v3; // eax@2

    if (a1->flags & 0x40)
    {
        v3 = a1->_4_entities[0];
        if (v3 != a2 && v3 != a3)
            return false;
    }
    return true;
}

//----- (0040EE10) --------------------------------------------------------
Entity *boxd_40EE10_prolly_get_building(int map_x, int map_y)
{
    DataBoxd_stru0_per_map_unit *v2; // eax@5
    Entity *v3; // ecx@6
    int v4; // ecx@7
    Entity *result; // eax@9
    enum UNIT_ID v6; // ecx@11

    if (map_x < 0 || map_y < 1 || map_x >= map_get_width() || map_y >= map_get_height())
        goto LABEL_16;
    v2 = boxd_get_tile(map_x, map_y);
    if (v2->flags2 & 0x40)
    {
        v3 = v2[-1]._4_entities[0];
        if (v3)
        {
            v4 = v3->unit_id;
            if (v4 >= (int)UNIT_STATS_SURV_DRILL_RIG && v4 <= (int)UNIT_STATS_MUTE_ALCHEMY_HALL)
                return v2[-1]._4_entities[0];
        }
    }
    result = v2->_4_entities[0];
    if (!result
        || (v6 = result->unit_id, (int)v6 < (int)UNIT_STATS_SURV_DRILL_RIG)
        || (int)v6 >(int)UNIT_STATS_MUTE_ALCHEMY_HALL)
    {
    LABEL_16:
        result = 0;
    }
    return result;
}

//----- (0040EE70) --------------------------------------------------------
int boxd_40EE70(int map_x, int map_y)
{
    DataBoxd_stru0_per_map_unit *v2; // eax@5
    int result; // eax@7

    result = 0;
    if (map_x >= 0 && map_y >= 1 && map_x < map_get_width() && map_y < map_get_height())
    {
        v2 = boxd_get_tile(map_x, map_y);
        if (!(v2->flags & 0x1F) && !(v2->flags2 & 0x40))
            result = 1;
    }
    return result;
}

int Map_40EEB0_place_entity_infantry(Entity *a1, DataBoxd_stru0_per_map_unit *v5, int a4) {
    int v8 = v5->flags & 0x1F;
    if (v8 < 31)
    {
        int v9 = a1->_A4_idx_in_tile;
        if ((1 << a1->_A4_idx_in_tile) & v8)
            v9 = dword_465688[v8];
        if (v9 != ENTITY_TILE_POSITION_INVALID)
        {
            int v10 = v5->flags2;
            v5->flags |= (1 << v9);
            v5->flags2 = ((_BYTE)a4 << v9) | v10;
            v5->_4_entities[v9] = a1;
            map_reveal_fog_around_entity(a1);
            return v9;
        }
    }
    return ENTITY_TILE_POSITION_INVALID;
}

//----- (0040EEB0) --------------------------------------------------------
int Map_40EEB0_place_entity(Entity *a1, int map_x, int map_y, int a4)
{
    Entity *v4; // ebx@1
    DataBoxd_stru0_per_map_unit *v5; // ebp@5
    char v7; // al@5
    int result; // eax@10
    char v12; // cl@19
    char v13; // cl@20
    Entity **v14; // esi@25
    int v15; // edi@30
    Entity *v16; // esi@34
    int v17; // edi@34
    char v18; // al@39
    char v19; // al@40
    enum PLAYER_SIDE player_side; // [sp+10h] [bp-4h]@30

    v4 = a1;
    if (map_x < 0 || map_x >= map_get_width() || map_y < 0 || map_y >= map_get_height())
        return ENTITY_TILE_POSITION_INVALID;

    v5 = boxd_get_tile(map_x, map_y);
    v7 = v5->flags;
    if (a1->IsInfantry())
    {
        return Map_40EEB0_place_entity_infantry(a1, v5, a4);
    }
    if (v5->IsAnySlotOccupied())
    {
        v14 = v5->_4_entities;
        if (v5->_4_entities[0] == v4)
            return ENTITY_MAKE_TILE_POSITION(0);
        if (!v5->IsImpassibleTerrain() && !(v7 & 0x80) && a1->stats->can_squash_infantry)
        {
            v15 = 0;
            player_side = v4->player_side;
            while (!*v14 || is_enemy(player_side, *v14))
            {
                ++v15;
                ++v14;
                if (v15 >= 5)
                {
                    v16 = (Entity *)v5->_4_entities;
                    v17 = 5;
                    do
                    {
                        if (v16->next && v16->next->script)
                        {
                            script_trigger_event(v4->script, EVT_MSG_1499, 0, v16->next->script);
                            v16->next = 0;
                        }
                        v16 = (Entity *)((char *)v16 + 4);
                        --v17;
                    } while (v17);
                    v18 = v5->flags2;
                    v5->flags |= 0x9Fu;
                    if (a4)
                        v19 = v18 | 0x1F;
                    else
                        v19 = v18 & 0xE0;
                    v5->flags2 = v19;
                    v5->_4_entities[0] = v4;
                    goto LABEL_43;
                }
            }
        }
        return ENTITY_TILE_POSITION_INVALID;
    }

    if (!a1->stats->speed)
    {
        if (!(v5->flags2 & 0x40))
        {
            v5->flags = v7 | 0x40;
            goto LABEL_15;
        }
        return ENTITY_TILE_POSITION_INVALID;
    }

LABEL_15:
    if (a4 == 64)
        v5->flags = 0;
    else {
        v5->flags |= BOXD_STRU0_ALL_SLOTS | BOXD_STRU0_VEHICLE_BUILDING;
    }

    if (a4)
    {
        v12 = v5->flags2;
        if (a4 == 64)
            v13 = v12 | 0x40;
        else
            v13 = v12 | 0x1F;
    }
    else
    {
        v13 = v5->flags2 & 0xE0;
    }
    v5->flags2 = v13;
    if (a4 == 64)
    {
    LABEL_43:
        map_reveal_fog_around_entity(v4);
        result = ENTITY_MAKE_TILE_POSITION(0);
    }
    else
    {
        v5->_4_entities[0] = v4;
        map_reveal_fog_around_entity(v4);
        result = ENTITY_MAKE_TILE_POSITION(0);
    }
    return result;
}





Entity *debug_pathing_entity = nullptr;
//----- (0041B970) --------------------------------------------------------
int Map_41B970_straight_line_pathing(Entity *a1, int target_x, int target_y)
{
    Sprite *v5; // edx@1
    int v8; // eax@2
    int v9; // ebx@2
    debug_pathing_entity = a1;
    v5 = a1->sprite;
    a1->pathing.num_waypoints = 0;
    if (v5->y > target_y)
    {
        // moving up
        int dx = (target_x - v5->x) / 256;
        int dy = (v5->y - target_y) / 256;
        if (dx <= 0)
        {
            // up left
            if (abs(dx) > dy)
                return boxd_41BA30(v5->x, v5->y, abs(dx), dy, -256, -256, a1);
            else
                return boxd_41BC60(v5->x, v5->y, abs(dx), dy, -256, -256, a1);
        }
        else
        {
            //up right
            if (dx > dy)
                return boxd_41BA30(v5->x, v5->y, dx, dy, 256, -256, a1);
            else
                return boxd_41BC60(v5->x, v5->y, dx, dy, 256, -256, a1);
        }
    }
    else
    {
        // moving down
        int dx = (target_x - v5->x) / 256;
        int dy = (target_y - v5->y) / 256;
        if (dx <= 0)
        {
            // down left
            if (abs(dx) > dy)
                return boxd_41BA30(v5->x, v5->y, abs(dx), dy, -256, 256, a1);
            else
                return boxd_41BC60(v5->x, v5->y, abs(dx), dy, -256, 256, a1);
        }
        else
        {
            // down right
            if (dx > dy)
                return boxd_41BA30(v5->x, v5->y, dx, dy, 256, 256, a1);
            else
                return boxd_41BC60(v5->x, v5->y, dx, dy, 256, 256, a1);
        }
    }
}

//----- (0041BA30) --------------------------------------------------------
int boxd_41BA30(int x, int y, int a3, int a4, int x_step, int y_step, Entity *a1)
{
    int v8; // esi@1
    int v10; // eax@7
    int v16; // eax@20
    int a3a; // [sp+1Ch] [bp-9Ch]@3
    int a8; // [sp+20h] [bp-98h]@3
    int v23; // [sp+24h] [bp-94h]@3
    int v26; // [sp+30h] [bp-88h]@1
    int a11; // [sp+38h] [bp-80h]@3
    int v29; // [sp+3Ch] [bp-7Ch]@1
    int v30[10]; // [sp+40h] [bp-78h]@2
    int a6a[10]; // [sp+68h] [bp-50h]@20
    int a5a[10]; // [sp+90h] [bp-28h]@20

    a1->pathing.destination_map_x = 0;
    a1->pathing.destination_map_y = 0;

    int map_x = global2map(x);
    int map_y = global2map(y);
    int next_x = x;
    int next_y = y;
    DataBoxd_stru0_per_map_unit *tile = boxd_get_tile(map_x, map_y);
    v26 = 2 * a4;
    v29 = 2 * a4 - 2 * a3;
    v8 = 2 * a4 - a3;
    int v19 = 0;
    for (int i = 0; i < 10; ++i)
    {
        v19 = i + 1;
        v30[i] = 0;
        a1->_15C_waypoints_xs[i] = -1;
        a1->_15C_waypoints_ys[i] = -1;
    }
    a3a = 0;
    v23 = 0;
    a11 = 0;
    a8 = 0;

    for (int i = a3 - 1; i > 0; --i)
    {
        map_x = global2map(next_x);
        map_y = global2map(next_y);

        if (v8 < 0)
        {
            v10 = v26;
        }
        else
        {
            v10 = v29;
            next_y += y_step;
        }
        next_x += x_step;
        v8 += v10;

        int next_map_x = global2map(next_x);
        int next_map_y = global2map(next_y);
        unsigned __int8 v15 = __OFSUB__(next_map_x, map_x);
        bool v13 = next_x == map_x;
        bool v14 = next_x - map_x < 0;
        if (next_map_x == map_x)
        {
            if (next_map_y == map_y)
                continue;
            v15 = __OFSUB__(next_map_x, map_x);
            v13 = next_map_x == map_x;
            v14 = next_map_x - map_x < 0;
        }
        if (!((unsigned __int8)(v14 ^ v15) | v13))
        {
            v15 = __OFSUB__(next_map_x, map_x);
            v14 = next_map_x - map_x < 0;
            ++tile;
        }
        if (v14 ^ v15)
            --tile;
        if (next_map_y > map_y)
            tile += map_get_width();
        if (next_map_y < map_y)
            tile -= map_get_width();

        v16 = boxd_40EA50_classify_tile_objects(a1, next_map_x, next_map_y, tile);
        if (Map_41BE90_add_waypoint(&v19, v16, &a3a, &v23, a1, v30, a5a, a6a, next_map_x, next_map_y, &a11, &a8) != 6)
            return 1;
    }

    return boxd_41C060(v19, a1, a3a, v23, a5a, a6a, v30, a8);
}

void entity_log_pathing(Entity *e) {
    log("indexer: %u", e->pathing.num_waypoints);
    if (e->pathing.num_waypoints > 0) {
        char buf[4096];

        buf[0] = 0;
        for (int i = 0; i < e->pathing.num_waypoints; ++i) {
            sprintf(buf + strlen(buf), "(%X,%X), ", e->_15C_waypoints_xs[i], e->_15C_waypoints_ys[i]);
        }
        log("_15C_waypoints = [%s]", buf);

        buf[0] = 0;
        for (int i = 0; i < e->pathing.num_waypoints; ++i) {
            sprintf(buf + strlen(buf), "(%X,%X), ", e->_1AC_waypoints_xs[i], e->_1AC_waypoints_ys[i]);
        }
        log("_1AC_waypoints = [%s]", buf);

        buf[0] = 0;
        for (int i = 0; i < e->pathing.num_waypoints; ++i) {
            sprintf(buf + strlen(buf), "(%X,%X), ", e->_1FC_waypoints_xs[i], e->_1FC_waypoints_ys[i]);
        }
        log("_1FC_waypoints = [%s]", buf);
    }
}


//----- (0041BC60) --------------------------------------------------------
int boxd_41BC60_new(int x, int y, int dx, int dy, int x_step, int y_step, Entity *entity)
{
    int v8; // esi@1
    int a3a; // [sp+1Ch] [bp-9Ch]@3
    int a8; // [sp+20h] [bp-98h]@3
    int v23; // [sp+24h] [bp-94h]@
    int a11; // [sp+38h] [bp-80h]@3
    int v30[10]; // [sp+40h] [bp-78h]@2
    int v31[10]; // [sp+68h] [bp-50h]@20
    int v32[10]; // [sp+90h] [bp-28h]@20

    entity->pathing.destination_map_x = 0;
    entity->pathing.destination_map_y = 0;
    int map_x = global2map(x);
    int map_y = global2map(y);
    auto tile = boxd_get_tile(map_x, map_y);
    v8 = 2 * dx - dy;
    for (int i = 0; i < 10; ++i) {
        v30[i] = 0;
        entity->_15C_waypoints_xs[i] = -1;
        entity->_15C_waypoints_ys[i] = -1;
    }

    int v19 = 0;
    a3a = 0;
    v23 = 0;
    a11 = 0;
    a8 = 0;
    if (dy == 0)
        return boxd_41C060(0, entity, 0, 0, v32, v31, v30, 0);

    for (int current_y = dy - 1; current_y >= 0; --current_y)
    {
        if (v8 < 0)
        {
            v8 += 2 * dx;
        }
        else
        {
            v8 += 2 * dx - 2 * dy;
            x += x_step;
        }

        y += y_step;
        int new_map_x = global2map(x);
        int new_map_y = global2map(y);
        if (new_map_x == map_x && new_map_y == map_y) {
            continue;
        }
        if (new_map_x > map_x)
            ++tile;
        else if (new_map_x < map_x)
            --tile;
        if (new_map_y > map_y)
            tile += map_get_width();
        else if (new_map_y < map_y)
            tile -= map_get_width();

        map_x = new_map_x;
        map_y = new_map_y;
        int v16 = boxd_40EA50_classify_tile_objects(entity, new_map_x, new_map_y, tile);
        int r = Map_41BE90_add_waypoint(&v19, v16, &a3a, &v23, entity, v30, v32, v31, new_map_x, new_map_y, &a11, &a8);
        if (entity->player_side == player_side) {
            //log("PATHING map(%X,%X)\tclassf %u\twayp %u", map_x, map_y, v16, r);
        }
        if (r != 6) {
            if (entity->player_side == player_side) {
                //log("PATHING complete(1): %u", r);
                //entity_log_pathing(entity);
            }
            return 1;
        }
    }

    int result = boxd_41C060(v19, entity, a3a, v23, v32, v31, v30, a8);

    if (entity->player_side == player_side) {
        //log("PATHING complete(2): %u", result);
        //entity_log_pathing(entity);
    }
    return result;
}

//----- (0041BC60) --------------------------------------------------------
int boxd_41BC60_old(int x, int y, int a3, int a4, int a5, int a6, Entity *a7)
{
    int v7; // ebx@1
    int v8; // esi@1 
    int v9; // eax@1
    int v10; // eax@7
    int v11; // esi@9
    int v12; // edi@9 
    bool v13; // zf@9
    bool v14; // sf@9
    unsigned __int8 v15; // of@9
    int v16; // eax@20
    DataBoxd_stru0_per_map_unit *a4a; // [sp+10h] [bp-A8h]@1
    int v19; // [sp+14h] [bp-A4h]@1
    int v20; // [sp+18h] [bp-A0h]@1
    int a3a; // [sp+1Ch] [bp-9Ch]@3
    int a8; // [sp+20h] [bp-98h]@3
    int v23; // [sp+24h] [bp-94h]@3
    int v24; // [sp+28h] [bp-90h]@1
    int v25; // [sp+2Ch] [bp-8Ch]@5 
    int v26; // [sp+30h] [bp-88h]@1
    int v27; // [sp+34h] [bp-84h]@9
    int a11; // [sp+38h] [bp-80h]@3
    int v29; // [sp+3Ch] [bp-7Ch]@1
    int v30[10]; // [sp+40h] [bp-78h]@2
    int v31[10]; // [sp+68h] [bp-50h]@20
    int v32[10]; // [sp+90h] [bp-28h]@20 
    int v33; // [sp+C0h] [bp+8h]@3

    a7->pathing.destination_map_x = 0;
    a7->pathing.destination_map_y = 0;
    v20 = y >> 13;
    v7 = x >> 13;
    v24 = x;
    a4a = boxd_get_tile(x >> 13, y >> 13);
    v26 = 2 * a3;
    v29 = 2 * a3 - 2 * a4;
    v8 = 2 * a3 - a4;
    v9 = 0;
    v19 = 0;
    do
    {
        v30[v9] = 0;
        a7->_15C_waypoints_xs[v9] = -1;
        a7->_15C_waypoints_ys[v19] = -1;
        v9 = v19 + 1;
        v15 = __OFSUB__(v19 + 1, 10);
        v14 = v19++ - 9 < 0;
    } while (v14 ^ v15);
    v19 = 0;
    a3a = 0;
    v23 = 0;
    a11 = 0;
    a8 = 0;
    v13 = a4 == 0;
    v33 = a4 - 1;
    if (v13)
        return boxd_41C060(v19, a7, a3a, v23, v32, v31, v30, a8);
    while (1)
    {
        if (v8 < 0)
        {
            v10 = v26;
        }
        else
        {
            v10 = v29;
            x += a5;
            v24 = x;
        }
        v25 = v10 + v8;
        y += a6;
        v11 = x >> 13;
        v12 = y >> 13;
        v15 = __OFSUB__(x >> 13, v7);
        v13 = x >> 13 == v7;
        v14 = (x >> 13) - v7 < 0;
        v27 = y;
        if (x >> 13 == v7)
        {
            if (v12 == v20)
                goto LABEL_22;
            v15 = __OFSUB__(v11, v7);
            v13 = v11 == v7;
            v14 = v11 - v7 < 0;
        }
        if (!((unsigned __int8)(v14 ^ v15) | v13))
        {
            v15 = __OFSUB__(v11, v7);
            v14 = v11 - v7 < 0;
            ++a4a;
        }
        if (v14 ^ v15)
            --a4a;
        if (v12 > v20)
            a4a += map_get_width();
        if (v12 < v20)
            a4a -= map_get_width();
        v7 = x >> 13;
        v20 = y >> 13;
        v16 = boxd_40EA50_classify_tile_objects(a7, v11, v12, a4a);
        if (Map_41BE90_add_waypoint(&v19, v16, &a3a, &v23, a7, v30, v32, v31, v11, v12, &a11, &a8) != 6)
            return 1;
        y = v27;
        x = v24;
    LABEL_22:
        v13 = v33-- == 0;
        if (v13)
            return boxd_41C060(v19, a7, a3a, v23, v32, v31, v30, a8);
        v8 = v25;
    }
}

int boxd_41BC60(int x, int y, int dx, int dy, int x_step, int y_step, Entity *entity) {
    int one = boxd_41BC60_new(x, y, dx, dy, x_step, y_step, entity);
    entity->pathing.num_waypoints = 0; // reset
    int two = boxd_41BC60_old(x, y, dx, dy, x_step, y_step, entity);
    assert(one == two);
    return two;
}


DataBoxd_stru0_per_map_unit *boxd_get_tile(int map_x, int map_y) {
    if (map_x < 0 || map_x >= map_get_width()) {
        return nullptr;
    }
    if (map_y < 0 || map_y >= map_get_height()) {
        return nullptr;
    }

    return &_478AA8_boxd_stru0_array[map_x + map_get_width() * map_y];
}

//----- (0041BE90) --------------------------------------------------------
int Map_41BE90_add_waypoint(
    _DWORD *a1, int tile_classification_result, _DWORD *a3, _DWORD *a4, Entity *a5,
    int *a6, int *a7, int *a8, int map_x, int map_y, _DWORD *a11, _DWORD *a12
)
{
    int v13; // edi@3
    int v17; // ecx@29

    switch (tile_classification_result)
    {
    case 1:
        if (!a5->pathing.field_54)
            goto LABEL_6;
        v13 = 0;
        break;
    case 3:
        if (a5->pathing.field_50)
            goto LABEL_6;
        v13 = 0;
        break;
    case 2:
        v13 = 0;
        break;
    default:
    LABEL_6:
        v13 = 1;
        a5->_1AC_waypoints_xs[a5->pathing.num_waypoints] = map_x;
        a5->_1AC_waypoints_ys[a5->pathing.num_waypoints] = map_y;
        break;
    }

    if (tile_classification_result == 0)
    {
        a5->_1FC_waypoints_xs[a5->pathing.num_waypoints] = map_x;
        a5->_1FC_waypoints_ys[a5->pathing.num_waypoints] = map_y;
        *a3 = 1;
        a6[a5->pathing.num_waypoints] = 0;
    }
    if (tile_classification_result == 3)
        *a12 = 1;
    if (tile_classification_result == 2)
    {
        *a4 = 1;
    }
    else
    {
        *a11 = 1;
    }
    if (tile_classification_result == 2 && !*a3 && !*a11)
    {
        a5->pathing.destination_map_x = map_x;
        a5->pathing.destination_map_y = map_y;
    }
    if (*a1)
    {
        if (*a1 == 1)
        {
            if (!v13)
            {
                a5->_15C_waypoints_xs[a5->pathing.num_waypoints] = map_x;
                a5->_15C_waypoints_ys[a5->pathing.num_waypoints] = map_y;
                if (++a5->pathing.num_waypoints == 10)
                    return 1;
                *a1 = 0;
            }
            if (tile_classification_result == 1 || tile_classification_result == 3)
            {
                if (*a3)
                {
                    v17 = a5->pathing.num_waypoints;
                    if (!a6[v17])
                    {
                        a7[v17] = map_x;
                        a8[a5->pathing.num_waypoints] = map_y;
                        a6[a5->pathing.num_waypoints] = 1;
                        return 6;
                    }
                }
            }
        }
    }
    else if (v13)
    {
        *a1 = 1;
    }
    return 6;
}

//----- (0041C060) --------------------------------------------------------
int boxd_41C060(int a1, Entity *a2, int a3, int a4, int *a5, int *a6, int *a7, int a8)
{
    int v8; // eax@3
    int result; // eax@7

    if (a1)
    {
        if (a1 != 1)
            goto LABEL_21;
        v8 = a2->pathing.num_waypoints;
        if (!v8 && !a3 && !a4 && !a8)
            return 4;
        if (v8)
        {
            if (!a3)
                return 1;
        }
        else if (!a3)
        {
            return 2;
        }
        if (a7[v8])
        {
            a2->_15C_waypoints_xs[v8] = a5[v8];
            a2->_15C_waypoints_ys[v8] = a6[v8];
            ++a2->pathing.num_waypoints;
            return 3;
        }
        if (v8)
            result = 1;
        else
            LABEL_21:
        result = 5;
    }
    else
    {
        result = a2->pathing.num_waypoints != 0;
    }
    return result;
}

//----- (0041C130) --------------------------------------------------------
bool boxd_41C130(int x, int y, int z, int w, Entity *entity)
{
    if (entity_is_infantry(entity) || entity_is_regular_vehicle(entity))
    {
        return boxd_41C190(x, y, z, w, entity);
    }
    else if (entity_is_xl_vehicle(entity))
    {
        return boxd_41C250(x, y, z, w, entity);
    }

    return false;
}

//----- (0041C190) --------------------------------------------------------
bool boxd_41C190(int x, int y, int z, int w, Entity *a5)
{
    int v5; // eax@2
    int v6; // esi@2
    int v8; // eax@7
    int v9; // esi@7
    int v10; // [sp-14h] [bp-1Ch]@3
    int v11; // [sp-10h] [bp-18h]@3
    int v12; // [sp-Ch] [bp-14h]@3
    int v13; // [sp-8h] [bp-10h]@3
    Entity *v14; // [sp-4h] [bp-Ch]@3

    if (y > w)
    {
        v8 = (z - x) >> 8;
        v9 = (y - w) >> 8;
        if (v8 <= 0)
        {
            v14 = a5;
            v13 = -256;
            v12 = -256;
            v11 = (y - w) >> 8;
            v10 = -v8;
            if (-v8 > v9)
                return boxd_41C660(x, y, v10, v9, -256, -256, a5);
        }
        else
        {
            v14 = a5;
            v13 = -256;
            v12 = 256;
            v11 = (y - w) >> 8;
            v10 = (z - x) >> 8;
            if (v8 > v9)
                return boxd_41C660(x, y, v8, v9, 256, -256, a5);
        }
    }
    else
    {
        v5 = (z - x) >> 8;
        v6 = (w - y) >> 8;
        if (v5 <= 0)
        {
            v14 = a5;
            v13 = 256;
            v12 = -256;
            v11 = (w - y) >> 8;
            v10 = -v5;
            if (-v5 > v6)
                return boxd_41C660(x, y, v10, v6, -256, 256, a5);
        }
        else
        {
            v14 = a5;
            v13 = 256;
            v12 = 256;
            v11 = (w - y) >> 8;
            v10 = (z - x) >> 8;
            if (v5 > v6)
                return boxd_41C660(x, y, v5, v6, 256, 256, a5);
        }
    }
    return boxd_41C890(x, y, v10, v11, v12, v13, v14);
}

//----- (0041C250) --------------------------------------------------------
bool boxd_41C250(int x, int y, int z, int w, Entity *a5)
{
    int v5; // esi@1
    int v6; // edi@1
    int v7; // ebp@2
    int v8; // ebx@2
    int v10; // edx@12
    int v11; // ebp@12
    int v12; // ecx@12
    int v13; // ebp@21
    int v14; // ebx@21
    int v15; // edx@22
    int v16; // ecx@22
    int v17; // ebp@31

    v5 = y;
    v6 = x;
    if (y > w)
    {
        v13 = (z - x) >> 8;
        v14 = (y - w) >> 8;
        if (v13 <= 0)
        {
            v17 = -v13;
            if (v17 <= v14)
            {
                if (boxd_41C890(x - 4096, y + 4096, v17, v14, -256, -256, a5)
                    && boxd_41C890(v6 + 4096, v5 - 4096, v17, v14, -256, -256, a5)
                    && boxd_41C890(v6, v5, v17, v14, -256, -256, a5))
                {
                    return 1;
                }
            }
            else if (boxd_41C660(x + 4096, y - 4096, v17, v14, -256, -256, a5)
                && boxd_41C660(v6 - 4096, v5 + 4096, v17, v14, -256, -256, a5)
                && boxd_41C660(v6, v5, v17, v14, -256, -256, a5))
            {
                return 1;
            }
        }
        else
        {
            v15 = y - 4096;
            v16 = x - 4096;
            if (v13 <= v14)
            {
                if (boxd_41C890(v16, v15, v13, v14, 256, -256, a5)
                    && boxd_41C890(v6 + 4096, v5 + 4096, v13, v14, 256, -256, a5)
                    && boxd_41C890(v6, v5, v13, v14, 256, -256, a5))
                {
                    return 1;
                }
            }
            else if (boxd_41C660(v16, v15, v13, v14, 256, -256, a5)
                && boxd_41C660(v6 + 4096, v5 + 4096, v13, v14, 256, -256, a5)
                && boxd_41C660(v6, v5, v13, v14, 256, -256, a5))
            {
                return 1;
            }
        }
    }
    else
    {
        v7 = (z - x) >> 8;
        v8 = (w - y) >> 8;
        if (v7 <= 0)
        {
            v10 = y - 4096;
            v11 = -v7;
            v12 = x - 4096;
            if (v11 <= v8)
            {
                if (boxd_41C890(v12, v10, v11, v8, -256, 256, a5)
                    && boxd_41C890(v6 + 4096, v5 + 4096, v11, v8, -256, 256, a5)
                    && boxd_41C890(v6, v5, v11, v8, -256, 256, a5))
                {
                    return 1;
                }
            }
            else if (boxd_41C660(v12, v10, v11, v8, -256, 256, a5)
                && boxd_41C660(v6 + 4096, v5 + 4096, v11, v8, -256, 256, a5)
                && boxd_41C660(v6, v5, v11, v8, -256, 256, a5))
            {
                return 1;
            }
        }
        else if (v7 <= v8)
        {
            if (boxd_41C890(x - 4096, y + 4096, v7, v8, 256, 256, a5)
                && boxd_41C890(v6 + 4096, v5 - 4096, v7, v8, 256, 256, a5)
                && boxd_41C890(v6, v5, v7, v8, 256, 256, a5))
            {
                return 1;
            }
        }
        else if (boxd_41C660(x + 4096, y - 4096, v7, v8, 256, 256, a5)
            && boxd_41C660(v6 - 4096, v5 + 4096, v7, v8, 256, 256, a5)
            && boxd_41C660(v6, v5, v7, v8, 256, 256, a5))
        {
            return 1;
        }
    }
    return 0;
}

//----- (0041C660) --------------------------------------------------------
bool boxd_41C660(int x, int y, int width, int height, int a5, int a6, Entity *a7)
{
    int v7; // esi@1
    int v8; // ebx@1
    int v9; // eax@2
    int v10; // edx@4
    int v11; // eax@5
    int v12; // eax@7
    Entity *v13; // ebp@15
    Sprite *v14; // eax@15
    DataBoxd_stru0_per_map_unit *v15; // edi@15
    int v17; // eax@19
    int v18; // eax@19
    bool v19; // zf@19
    int v20; // ecx@21
    int v21; // eax@23
    int v22; // eax@23
    int v23; // ecx@23
    bool v24; // sf@27
    unsigned __int8 v25; // of@27
    int v26; // [sp+10h] [bp-14h]@1
    int v27; // [sp+14h] [bp-10h]@1
    int v28; // [sp+18h] [bp-Ch]@19
    int v29; // [sp+1Ch] [bp-8h]@15
    int v30; // [sp+20h] [bp-4h]@15
    int a3a; // [sp+28h] [bp+4h]@19
    int a4a; // [sp+2Ch] [bp+8h]@19
    Entity *a7a; // [sp+38h] [bp+14h]@23

    v7 = x >> 13;
    v8 = y >> 13;
    v26 = y;
    v27 = x;
    if (a5 <= 0)
        v9 = -(width >> 5);
    else
        v9 = width >> 5;
    v10 = v7 + v9;
    if (a6 <= 0)
        v11 = -(height >> 5);
    else
        v11 = height >> 5;
    v12 = v8 + v11;
    if (v7 >= 0
        && v7 < map_get_width()
        && v8 >= 0
        && v8 < map_get_height()
        && v10 >= 0
        && v10 < map_get_width()
        && v12 >= 0
        && v12 < map_get_height())
    {
        v13 = a7;
        v14 = a7->sprite;
        v30 = v14->y >> 13;
        v29 = v14->x >> 13;
        v15 = boxd_get_tile(v7, v8);
        switch (boxd_40ED00(a7, v15))
        {
        case 1:
            if (a7->pathing.field_54)
                break;
            return 0;
        case 3:
            if (a7->pathing.field_50)
                return 0;
            break;
        case 2:
            break;
        default:
            return 0;
        }
        v17 = 2 * height;
        a4a = v17;
        v28 = v17 - 2 * width;
        v18 = v17 - width;
        v19 = width == 0;
        a3a = width - 1;
        if (v19)
            return 1;
        while (1)
        {
            if (v18 < 0)
            {
                v20 = a4a;
            }
            else
            {
                v20 = v28;
                v26 += a6;
            }
            a7a = (Entity *)(v20 + v18);
            v21 = a5 + v27;
            v27 = v21;
            v22 = v21 >> 13;
            v23 = v26 >> 13;
            if (v22 != v7 || v23 != v8)
                break;
        LABEL_39:
            v19 = a3a-- == 0;
            if (v19)
                return 1;
            v18 = (int)a7a;
        }
        if (v22 == v29 && v23 == v30)
            return 1;
        v25 = __OFSUB__(v22, v7);
        v24 = v22 - v7 < 0;
        if (v22 > v7)
        {
            ++v15;
            v25 = __OFSUB__(v22, v7);
            v24 = v22 - v7 < 0;
        }
        if (v24 ^ v25)
            --v15;
        if (v23 > v8)
            v15 += map_get_width();
        if (v23 < v8)
            v15 -= map_get_width();
        v8 = v26 >> 13;
        v7 = v22;
        switch (boxd_40ED00(v13, v15))
        {
        case 1:
            if (v13->pathing.field_54)
                goto LABEL_39;
            return 0;
        case 3:
            if (!v13->pathing.field_50)
                goto LABEL_39;
            return 0;
        case 2:
            goto LABEL_39;
        default:
            return 0;
        }
    }
    return 0;
}
// 478AAC: using guessed type int map_get_height();
// 4793F8: using guessed type int map_get_width();

//----- (0041C890) --------------------------------------------------------
bool boxd_41C890(int x, int y, int width, int height, int a5, int a6, Entity *a7)
{
    int v7; // esi@1
    int v8; // ebx@1
    int v9; // eax@2
    int v10; // edx@4
    int v11; // eax@5
    int v12; // eax@7
    Entity *v13; // ebp@15
    Sprite *v14; // eax@15
    DataBoxd_stru0_per_map_unit *v15; // edi@15
    int v17; // eax@19
    int v18; // eax@19
    bool v19; // zf@19
    int v20; // ecx@21
    int v21; // eax@23
    int v22; // ecx@23
    bool v23; // sf@27
    unsigned __int8 v24; // of@27
    int v25; // [sp+10h] [bp-14h]@1
    int v26; // [sp+14h] [bp-10h]@1
    int v27; // [sp+18h] [bp-Ch]@19
    int v28; // [sp+1Ch] [bp-8h]@15
    int v29; // [sp+20h] [bp-4h]@15
    int a3a; // [sp+28h] [bp+4h]@19
    int a4a; // [sp+2Ch] [bp+8h]@19
    Entity *a7a; // [sp+38h] [bp+14h]@23

    v7 = x >> 13;
    v8 = y >> 13;
    v26 = y;
    v25 = x;
    if (a5 <= 0)
        v9 = -(width >> 5);
    else
        v9 = width >> 5;
    v10 = v7 + v9;
    if (a6 <= 0)
        v11 = -(height >> 5);
    else
        v11 = height >> 5;
    v12 = v8 + v11;
    if (v7 >= 0
        && v7 < map_get_width()
        && v8 >= 0
        && v8 < map_get_height()
        && v10 >= 0
        && v10 < map_get_width()
        && v12 >= 0
        && v12 < map_get_height())
    {
        v13 = a7;
        v14 = a7->sprite;
        v29 = v14->y >> 13;
        v28 = v14->x >> 13;
        v15 = boxd_get_tile(v7, v8);
        switch (boxd_40ED00(a7, v15))
        {
        case 1:
            if (a7->pathing.field_54)
                break;
            return 0;
        case 3:
            if (a7->pathing.field_50)
                return 0;
            break;
        case 2:
            break;
        default:
            return 0;
        }
        v17 = 2 * width;
        a3a = v17;
        v27 = v17 - 2 * height;
        v18 = v17 - height;
        v19 = height == 0;
        a4a = height - 1;
        if (v19)
            return 1;
        while (1)
        {
            if (v18 < 0)
            {
                v20 = a3a;
            }
            else
            {
                v20 = v27;
                v25 += a5;
            }
            a7a = (Entity *)(v20 + v18);
            v26 += a6;
            v21 = v25 >> 13;
            v22 = v26 >> 13;
            if (v25 >> 13 != v7 || v22 != v8)
                break;
        LABEL_39:
            v19 = a4a-- == 0;
            if (v19)
                return 1;
            v18 = (int)a7a;
        }
        if (v21 == v28 && v22 == v29)
            return 1;
        v24 = __OFSUB__(v21, v7);
        v23 = v21 - v7 < 0;
        if (v21 > v7)
        {
            ++v15;
            v24 = __OFSUB__(v21, v7);
            v23 = v21 - v7 < 0;
        }
        if (v23 ^ v24)
            --v15;
        if (v22 > v8)
            v15 += map_get_width();
        if (v22 < v8)
            v15 -= map_get_width();
        v8 = v26 >> 13;
        v7 = v25 >> 13;
        switch (boxd_40ED00(v13, v15))
        {
        case 1:
            if (v13->pathing.field_54)
                goto LABEL_39;
            return 0;
        case 3:
            if (!v13->pathing.field_50)
                goto LABEL_39;
            return 0;
        case 2:
            goto LABEL_39;
        default:
            return 0;
        }
    }
    return 0;
}
// 478AAC: using guessed type int map_get_height();
// 4793F8: using guessed type int map_get_width();