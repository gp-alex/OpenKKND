#include "src/kknd.h"

#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"


//----- (00438930) --------------------------------------------------------
int stru28_list_alloc()
{
    stru28 *v0; // eax@1
    int v1; // ecx@2
    int result; // eax@4

    v0 = (stru28 *)malloc(0x280u);
    stru28_list = v0;
    if (v0)
    {
        stru28_list_free_pool = v0;
        v1 = 0;
        do
        {
            v0[v1].next = &v0[v1 + 1];
            v0 = stru28_list;
            ++v1;
        } while (v1 < 39);
        stru28_list[39].next = 0;
        stru28_list_47C338 = (stru28 *)&stru28_list_47C338;
        stru28_list_47C33C = (stru28 *)&stru28_list_47C338;
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (004389A0) --------------------------------------------------------
void _4389A0_prolly_create_map_damage_decal(int map_x, int map_y)
{
    int v2; // edi@1
    int v3; // esi@1
    int v4; // ebp@5
    int v5; // esi@6
    int v6; // edi@6
    int v7; // ebx@6
    stru28 *v8; // eax@7
    Sprite *v9; // ecx@8
    stru28 *v10; // esi@11
    stru28 *v11; // edx@15
    stru28 **v12; // eax@15
    Sprite *v13; // eax@15
    stru28 *v14; // edx@18
    int v15; // ecx@19
    int v16; // edx@21

    v2 = map_x;
    v3 = map_y;
    if (map_x >= 0 && map_y >= 0 && map_x < _478AB4_map_width_shl_13 && map_y < _478FF0_map_height_shl_13)
    {
        v4 = rand2(__FILE__, __LINE__) & 0x7FFF;
        if (v4 < 5000)
        {
            v5 = v3 & 0xFFFFE000;
            v6 = v2 & 0xFFFFE000;
            v7 = v5;
            if (!(_478AA8_boxd_stru0_array[(v6 >> 13) + _4793F8_map_width * (v5 >> 13)].flags & 0xE0))
            {
                v8 = stru28_list_47C338;
                if ((stru28 **)stru28_list_47C338 == &stru28_list_47C338)
                {
                LABEL_11:
                    v10 = stru28_list_free_pool;
                    if (stru28_list_free_pool)
                        stru28_list_free_pool = stru28_list_free_pool->next;
                    else
                        v10 = 0;
                    if (v10)
                    {
                        v13 = sprite_create(MOBD_EXPLOSIONS, 0, 0);
                        if (!v13)
                        {
                            v10->next = stru28_list_free_pool;
                            stru28_list_free_pool = v10;
                            return;
                        }
                        v14 = stru28_list_47C338;
                        v10->prev = (stru28 *)&stru28_list_47C338;
                        v10->next = v14;
                        stru28_list_47C338->prev = v10;
                        stru28_list_47C338 = v10;
                        v13->drawjob->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_448600_oilspot;
                    }
                    else
                    {
                        v11 = stru28_list_47C33C;
                        v12 = &stru28_list_47C33C->prev;
                        stru28_list_47C33C->next->prev = stru28_list_47C33C->prev;
                        (*v12)->next = v11->next;
                        v11->next = stru28_list_47C338;
                        *v12 = (stru28 *)&stru28_list_47C338;
                        v10 = v11;
                        stru28_list_47C338->prev = v11;
                        stru28_list_47C338 = v11;
                        v13 = v11->sprite;
                    }
                    v13->x = v6;
                    v15 = v4 & 7;
                    v13->y = v7;
                    v10->sprite = v13;
                    v10->mobd_offset_idx = v15;
                    sprite_4272A0_load_mobd_item(v13, _46BBE8_mobd_offset_table_by_stru22[v15]);
                }
                else
                {
                    while (1)
                    {
                        v9 = v8->sprite;
                        if (v9->x == v6 && v9->y == v5)
                            break;
                        v8 = v8->next;
                        if ((stru28 **)v8 == &stru28_list_47C338)
                            goto LABEL_11;
                    }
                    v16 = v8->mobd_offset_idx + 1;
                    v8->mobd_offset_idx = v16;
                    if (v16 >= 8)
                        v8->mobd_offset_idx = 0;
                    sprite_4272A0_load_mobd_item(v9, _46BBE8_mobd_offset_table_by_stru22[v8->mobd_offset_idx]);
                }
            }
        }
    }
}