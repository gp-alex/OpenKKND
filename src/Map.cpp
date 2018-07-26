#include "src/Map.h"



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