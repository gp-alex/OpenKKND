#include "src/Sprite.h"

#include "src/_unsorted_data.h"
#include "src/Pathfind.h"
#include "src/RenderDrawHandlers.h"
#include "src/ScriptEvent.h"


//----- (00426CB0) --------------------------------------------------------
bool sprite_list_alloc(const int num_sprites)
{
    currently_running_lvl_mobd = (DataMobd *)LVL_FindSection((const char *)MOBD);
    if (currently_running_lvl_mobd)
    {
        currently_running_lvl_mobd_valid = 1;
        if (sprite_list = new Sprite[num_sprites])
        {
            sprite_list_free_pool = sprite_list;
            sprite_list_free_pool->prev = (Sprite *)&sprite_list_free_pool;
            for (int i = 0; i < num_sprites - 1; ++i)
            {
                sprite_list[i].next = &sprite_list[i + 1];
            }
            sprite_list[num_sprites - 1].next = (Sprite *)&sprite_list_free_pool;
            sprite_list_47A4A4 = (Sprite *)&sprite_list_47A4A0;
            sprite_list_47A4A0 = (Sprite *)&sprite_list_47A4A0;
            sprite_init_47A400();
            j_drawjob_update_handler_426C40_default_sprite_handler = drawjob_update_handler_426C40_mobd;
            return true;
        }
        return false;
    }
    else
    {
        currently_running_lvl_mobd_valid = 0;
        return true;
    }
}

//----- (00426D40) --------------------------------------------------------
void sprite_init_47A400()
{
    sprite_47A400.parent = 0;
    sprite_47A400.z_index = 0;
    sprite_47A400.y = 0;
    sprite_47A400.x = 0;
    sprite_47A400.z_speed = 0;
    sprite_47A400.y_speed = 0;
    sprite_47A400.x_speed = 0;
    sprite_47A400.z_speed_factor_2 = 0;
    sprite_47A400.y_speed_factor_2 = 0;
    sprite_47A400.x_speed_factor_2 = 0;
    sprite_47A400.z_speed_limit = 0x7FFFFFFF;
    sprite_47A400.y_speed_limit = 0x7FFFFFFF;
    sprite_47A400.x_speed_limit = 0x7FFFFFFF; // max signed int
    sprite_47A400.z_speed_factor_1 = 0;
    sprite_47A400.y_speed_factor_1 = 0;
    sprite_47A400.x_speed_factor_1 = 0;
    sprite_47A400._64_mobd_anim_related = 0;
    sprite_47A400._60_mobd_anim_speed = 0;
    sprite_47A400._inside_mobd_item = 0;
    sprite_47A400._inside_mobd_item_2 = 0;
    sprite_47A400._54_inside_mobd_ptr4 = 0;
    sprite_47A400.script = 0;
    sprite_47A400.cplc_ptr1 = 0;
    sprite_47A400.cplc_stru0 = 0;
    sprite_47A400.cplc_ptr1_pstru20 = 0;
    sprite_47A400.param = 0;
    sprite_47A400._80_entity__stru29__sprite__initial_hitpoints = 0;
    sprite_47A400.field_84 = 0;
    sprite_47A400.pstru7 = _4640E0_stru7_array;
    sprite_47A400.pstru58 = 0;
    sprite_47A400.field_88_unused = 0;
    sprite_47A400.field_8C_infantry_damage = 0;
    sprite_47A400.field_8E_vehicle_damage = 0;
    sprite_47A400.field_90_building_damage = 0;
}
// 47A400: using guessed type Sprite sprite_47A400;

//----- (00426E00) --------------------------------------------------------
Sprite *sprite_create(enum MOBD_ID mobd_item_idx, Script *script, Sprite *parent)
{
    Script *v3; // ebp@1
    Sprite *result; // eax@2
    Sprite *v5; // ebx@3
    enum MOBD_ID v6; // [sp+10h] [bp-4h]@1

    v6 = mobd_item_idx;
    v3 = script;
    if ((Sprite **)sprite_list_free_pool == &sprite_list_free_pool)
    {
        result = 0;
    }
    else
    {
        v5 = sprite_list_free_pool;
        result = (Sprite *)draw_list_add(
            sprite_list_free_pool,
            (DrawUpdateHandler)j_drawjob_update_handler_426C40_default_sprite_handler);
        if (result)
        {
            sprite_list_free_pool = v5->next;
            memcpy(v5, &sprite_47A400, sizeof(Sprite));
            v5->next = (Sprite *)&sprite_list_47A4A0;
            v5->prev = sprite_list_47A4A4;
            sprite_list_47A4A4->next = v5;
            sprite_list_47A4A4 = v5;
            v5->mobd_id = v6;
            v5->script = v3;
            if (v3)
                v3->sprite = v5;
            v5->drawjob = (DrawJob *)result;
            if (parent)
            {
                v5->parent = parent;
                v5->x = parent->x;
                v5->y = parent->y;
                v5->z_index = parent->z_index;
                if (!v3)
                    v5->script = parent->script;
            }
            result = v5;
        }
    }
    return result;
}
// 47A400: using guessed type Sprite sprite_47A400;

//----- (00426EC0) --------------------------------------------------------
Sprite *sprite_create_scripted(
    enum MOBD_ID mobd_item_idx, Sprite *parent, void(*script)(Script *), enum SCRIPT_ROUTINE_TYPE task_type,
    Entity_stru_dmg_related *a5
)
{
    Sprite *v5; // esi@1
    enum MOBD_ID v6; // edi@1
    Sprite *result; // eax@3

    v5 = parent;
    v6 = mobd_item_idx;

    if (!script)
    {
        result = 0;
    LABEL_8:
        result = sprite_create(v6, (Script *)result, v5);
        if (result && v5)
        {
            if (a5)
            {
                result->x = a5->x_offset + v5->x;
                result->y = a5->y_offset + v5->y;
                result->z_index = a5->z_index_offset + v5->z_index;
            }
        }
        return result;
    }
    if (task_type == SCRIPT_FUNCTION)
        result = (Sprite *)script_create_function(SCRIPT_TYPE_INVALID, script);
    else if (task_type == SCRIPT_COROUTINE)
        result = (Sprite *)script_create_coroutine(SCRIPT_TYPE_INVALID, script, 0);
    else
    {
        __debugbreak();
        result = false;
    }
    if (result)
        goto LABEL_8;
    return result;
}

//----- (00426F40) --------------------------------------------------------
void sprite_list_remove(Sprite *a1)
{
    Sprite *v1; // esi@1
    DrawJob *v2; // eax@1
    DataCplcItem_ptr1 *v3; // eax@3
    DataCplc_stru0 *v4; // ecx@6

    v1 = a1;
    v2 = a1->drawjob;
    if (v2)
        v2->flags |= 0x80000000;
    v3 = a1->cplc_ptr1;
    if (v3 && v3->_20_stru20.sprite == a1)
        v3->_20_stru20.sprite = 0;
    v4 = a1->cplc_stru0;
    if (v4)
        cplc_4062E0_stru0_list_remove(v4);
    v1->prev->next = v1->next;
    v1->next->prev = v1->prev;
    v1->next = sprite_list_free_pool;
    sprite_list_free_pool = v1;
}

//----- (00426F90) --------------------------------------------------------
void sprite_list_remove_scripted(Sprite *a1)
{
    Sprite *v1; // esi@1
    Script *v2; // ecx@1
    DrawJob *v3; // eax@3
    DataCplcItem_ptr1 *v4; // eax@5
    DataCplc_stru0 *v5; // ecx@8

    v1 = a1;
    v2 = a1->script;
    if (v2)
    {
        script_deinit(v2);
        v1->script = 0;
    }
    v3 = v1->drawjob;                             // INLINED  426F40  sprite_list_remove
    if (v3)
        v3->flags |= 0x80000000;
    v4 = v1->cplc_ptr1;
    if (v4 && v4->_20_stru20.sprite == v1)
        v4->_20_stru20.sprite = 0;
    v5 = v1->cplc_stru0;
    if (v5)
        cplc_4062E0_stru0_list_remove(v5);
    v1->prev->next = v1->next;
    v1->next->prev = v1->prev;
    v1->next = sprite_list_free_pool;
    sprite_list_free_pool = v1;
}

//----- (00427000) --------------------------------------------------------
Sprite *sprite_list_find_by_mobd_id(enum MOBD_ID mobd_id)
{
    Sprite *result; // eax@1

    result = sprite_list_47A4A0;
    if ((Sprite **)sprite_list_47A4A0 == &sprite_list_47A4A0)
    {
    LABEL_4:
        result = 0;
    }
    else
    {
        while (result->mobd_id != mobd_id)
        {
            result = result->next;
            if ((Sprite **)result == &sprite_list_47A4A0)
                goto LABEL_4;
        }
    }
    return result;
}

//----- (00427020) --------------------------------------------------------
void sprite_list_update_positions()
{
    //Sprite *i; // esi@2
    //Script *v1; // eax@4
    //int v2; // eax@5

    //if (currently_running_lvl_mobd_valid)
    //{
    //    bodx_404D50_sprite_list((Sprite *)&sprite_list_47A4A0);
    //    for (i = sprite_list_47A4A0; (Sprite **)i != &sprite_list_47A4A0; i = i->next)
    //    {
    //        if (is_async_execution_supported && (v1 = i->script) != 0)
    //            v2 = v1->field_1C & 1;
    //        else
    //            v2 = 1;
    //        if (!v2)
    //            continue;

    //        i->x += i->x_speed;
    //        if (i->x_speed > 0)
    //            boxd_404F40_sprite(i, 0, 1);
    //        else if (i->x_speed < 0)
    //            boxd_404F40_sprite(i, 1, 1);

    //        i->y += i->y_speed;
    //        if (i->y_speed > 0)
    //            boxd_404F40_sprite(i, 2, 1);
    //        else if (i->y_speed < 0)
    //            boxd_404F40_sprite(i, 3, 1);

    //        i->z_index += i->z_speed;
    //        if (i->x_speed == 0 && i->y_speed == 0)
    //        {
    //            boxd_404F40_sprite(i, 0, i->field_88_unused ? 1 : 0);
    //        }

    //        i->field_88_unused = 1;
    //        if (i->x_speed < 0)
    //        {
    //            i->x_speed += i->x_speed_factor_1;
    //            if (i->x_speed > 0)
    //                i->x_speed = 0;
    //        }
    //        else
    //        {
    //            i->x_speed -= i->x_speed_factor_1;
    //            if (i->x_speed < 0)
    //                i->x_speed = 0;
    //        }

    //        if (i->x_speed_factor_2)
    //        {
    //            i->x_speed += i->x_speed_factor_2;
    //            if (i->x_speed < 0)
    //            {
    //                if (i->x_speed < -i->x_speed_limit)
    //                {
    //                    i->x_speed = -i->x_speed_limit;
    //                    if (i->script)
    //                    {
    //                        i->script->flags_20 |= SCRIPT_FLAGS_20_X_SPEED_LIMIT;
    //                        i->script->flags_24 |= i->script->flags_20;
    //                    }
    //                }
    //            }
    //            else
    //            {
    //                if (i->x_speed > i->x_speed_limit)
    //                {
    //                    i->x_speed = i->x_speed_limit;
    //                    if (i->script)
    //                    {
    //                        i->script->flags_20 |= SCRIPT_FLAGS_20_X_SPEED_LIMIT;
    //                        i->script->flags_24 |= i->script->flags_20;
    //                    }
    //                }
    //            }
    //        }


    //        if (i->y_speed < 0)
    //        {
    //            i->y_speed += i->y_speed_factor_1;
    //            if (i->y_speed > 0)
    //                i->y_speed = 0;
    //        }
    //        else
    //        {
    //            i->y_speed -= i->y_speed_factor_1;
    //            if (i->y_speed < 0)
    //                i->y_speed = 0;
    //        }

    //        if (i->y_speed_factor_2)
    //        {
    //            i->y_speed += i->y_speed_factor_2;
    //            if (i->y_speed < 0)
    //            {
    //                if (i->y_speed < -i->y_speed_limit)
    //                {
    //                    i->y_speed = -i->y_speed_limit;
    //                    if (i->script)
    //                    {
    //                        i->script->flags_20 |= SCRIPT_FLAGS_20_Y_SPEED_LIMIT;
    //                        i->script->flags_24 |= i->script->flags_20;

    //                    }
    //                }
    //            }
    //            else
    //            {
    //                if (i->y_speed > i->y_speed_limit)
    //                {
    //                    i->y_speed = i->y_speed_limit;
    //                    if (i->script)
    //                    {
    //                        i->script->flags_20 |= SCRIPT_FLAGS_20_Y_SPEED_LIMIT;
    //                        i->script->flags_24 |= i->script->flags_20;
    //                    }
    //                }
    //            }
    //        }

    //        if (i->z_speed < 0)
    //        {
    //            i->z_speed += i->z_speed_factor_1;
    //            if (i->z_speed > 0)
    //                i->z_speed = 0;
    //        }
    //        else
    //        {
    //            i->z_speed -= i->z_speed_factor_1;
    //            if (i->z_speed < 0)
    //                i->z_speed = 0;
    //        }

    //        if (i->z_speed_factor_2)
    //        {
    //            i->z_speed += i->z_speed_factor_2;
    //            if (i->z_speed < 0)
    //            {
    //                if (i->z_speed < -i->z_speed_limit)
    //                {
    //                    i->z_speed = -i->z_speed_limit;
    //                    if (i->script)
    //                    {
    //                        i->script->flags_20 |= SCRIPT_FLAGS_20_Z_SPEED_LIMIT;
    //                        i->script->flags_24 |= i->script->flags_20;
    //                    }
    //                }
    //            }
    //            else
    //            {
    //                if (i->z_speed > i->z_speed_limit)
    //                {
    //                    i->z_speed = i->z_speed_limit;
    //                    if (!i->script)
    //                    {
    //                        i->script->flags_20 |= SCRIPT_FLAGS_20_Z_SPEED_LIMIT;
    //                        i->script->flags_24 |= i->script->flags_20;
    //                    }
    //                }
    //            }
    //        }
    //    }
    //}

    Sprite *i; // esi
    Script *v1; // eax
    int v2; // eax
    int v3; // ecx
    signed int v4; // eax
    int v5; // ecx
    int v6; // eax
    int v7; // eax
    int v8; // eax
    int v9; // ecx
    int v10; // eax
    bool v11; // sf
    int v12; // eax
    int v13; // edx
    int v14; // eax
    int v15; // eax
    int v16; // eax
    int v17; // eax
    int v18; // ecx
    int v19; // eax
    int v20; // eax
    int v21; // edx
    int v22; // eax
    int v23; // eax
    int v24; // eax
    int v25; // eax
    int v26; // ecx
    int v27; // eax
    int v28; // eax
    int v29; // edx
    int v30; // eax

    if (currently_running_lvl_mobd_valid)
    {
        bodx_404D50_sprite_list((Sprite *)&sprite_list_47A4A0);
        for (i = sprite_list_47A4A0; i != (Sprite *)&sprite_list_47A4A0; i = i->next)
        {
            if (is_async_execution_supported && (v1 = i->script) != 0)
                v2 = v1->field_1C & 1;
            else
                v2 = 1;
            if (!v2)
                continue;
            v3 = i->x_speed;
            v4 = 0;
            i->x += v3;
            if (v3 <= 0)
            {
                if (i->x_speed >= 0)
                    goto LABEL_13;
                boxd_404F40_sprite(i, 1, 1);
            }
            else
            {
                boxd_404F40_sprite(i, 0, 1);
            }
            v4 = 1;
        LABEL_13:
            v5 = i->y_speed;
            i->y += v5;
            if (v5 <= 0)
            {
                if (i->y_speed >= 0)
                    goto LABEL_18;
                boxd_404F40_sprite(i, 3, 1);
            }
            else
            {
                boxd_404F40_sprite(i, 2, 1);
            }
            v4 = 1;
        LABEL_18:
            i->z_index += i->z_speed;
            if (!v4)
            {
                if (i->field_88_unused)
                    boxd_404F40_sprite(i, 0, 1);
                else
                    boxd_404F40_sprite(i, 0, 0);
            }
            v6 = i->x_speed;
            i->field_88_unused = 1;
            if (v6 < 0)
            {
                v8 = i->x_speed_factor_1 + i->x_speed;
                i->x_speed = v8;
                if (v8 <= 0)
                    goto LABEL_27;
            }
            else
            {
                v7 = v6 - i->x_speed_factor_1;
                i->x_speed = v7;
                if (v7 >= 0)
                    goto LABEL_27;
            }
            i->x_speed = 0;
        LABEL_27:
            if (!i->x_speed_factor_2)
                goto LABEL_35;
            v9 = i->x_speed_factor_2;
            v10 = i->x_speed;
            v11 = v9 + v10 < 0;
            v12 = v9 + v10;
            i->x_speed = v12;
            if (v11)
            {
                if (i->x_speed < -i->x_speed_limit)
                {
                    i->x_speed = -i->x_speed_limit;
                    if (i->script)
                    {
                    LABEL_34:
                        i->script->flags_20 |= 0x8000000u;
                        i->script->flags_24 |= i->script->flags_20;
                        goto LABEL_35;
                    }
                }
            }
            else
            {
                v13 = v12;
                v14 = i->x_speed_limit;
                if (v13 > v14)
                {
                    i->x_speed = v14;
                    if (i->script)
                        goto LABEL_34;
                }
            }
        LABEL_35:
            v15 = i->y_speed;
            if (v15 < 0)
            {
                v17 = i->y_speed_factor_1 + i->y_speed;
                i->y_speed = v17;
                if (v17 <= 0)
                    goto LABEL_40;
            }
            else
            {
                v16 = v15 - i->y_speed_factor_1;
                i->y_speed = v16;
                if (v16 >= 0)
                    goto LABEL_40;
            }
            i->y_speed = 0;
        LABEL_40:
            if (!i->y_speed_factor_2)
                goto LABEL_48;
            v18 = i->y_speed_factor_2;
            v19 = i->y_speed;
            v11 = v18 + v19 < 0;
            v20 = v18 + v19;
            i->y_speed = v20;
            if (v11)
            {
                if (i->y_speed < -i->y_speed_limit)
                {
                    i->y_speed = -i->y_speed_limit;
                    if (i->script)
                    {
                    LABEL_47:
                        i->script->flags_20 |= 0x4000000u;
                        i->script->flags_24 |= i->script->flags_20;
                        goto LABEL_48;
                    }
                }
            }
            else
            {
                v21 = v20;
                v22 = i->y_speed_limit;
                if (v21 > v22)
                {
                    i->y_speed = v22;
                    if (i->script)
                        goto LABEL_47;
                }
            }
        LABEL_48:
            v23 = i->z_speed;
            if (v23 < 0)
            {
                v25 = i->z_speed_factor_1 + i->z_speed;
                i->z_speed = v25;
                if (v25 <= 0)
                    goto LABEL_53;
            }
            else
            {
                v24 = v23 - i->z_speed_factor_1;
                i->z_speed = v24;
                if (v24 >= 0)
                    goto LABEL_53;
            }
            i->z_speed = 0;
        LABEL_53:
            if (i->z_speed_factor_2)
            {
                v26 = i->z_speed_factor_2;
                v27 = i->z_speed;
                v11 = v26 + v27 < 0;
                v28 = v26 + v27;
                i->z_speed = v28;
                if (v11)
                {
                    if (i->z_speed >= -i->z_speed_limit)
                        continue;
                    i->z_speed = -i->z_speed_limit;
                    if (!i->script)
                        continue;
                }
                else
                {
                    v29 = v28;
                    v30 = i->z_speed_limit;
                    if (v29 <= v30)
                        continue;
                    i->z_speed = v30;
                    if (!i->script)
                        continue;
                }
                i->script->flags_20 |= 0x2000000u;
                i->script->flags_24 |= i->script->flags_20;
            }
        }
    }
}


//----- (004272A0) --------------------------------------------------------
void sprite_load_mobd(Sprite *a1, int offset)
{
    if (a1)
    {
        DataMobdItem_stru0 **v2 = &currently_running_lvl_mobd[a1->mobd_id].items->_[offset / 4];
        a1->_inside_mobd_item = v2;
        a1->_inside_mobd_item_2 = v2;

        if (*v2)
            a1->_60_mobd_anim_speed = ((DataMobdItem_stru2 *)v2)->flags;
        a1->_64_mobd_anim_related = -1;

        sprite_427460_init_mobd_item(a1);
    }
}

//----- (004272E0) --------------------------------------------------------
void sprite_4272E0_load_mobd_item(Sprite *a1, int lookup_table_offset, int lookup_idx)
{
    auto lookup_table = (DataMobdItem_stru2 **)(
        (char *)&currently_running_lvl_mobd[a1->mobd_id].items->_ + lookup_table_offset
        );
    auto v = lookup_table[lookup_idx];

    DataMobdItem_stru0 **v3; // eax@1
    v3 = *(DataMobdItem_stru0 ***)(
        (char *)&currently_running_lvl_mobd[a1->mobd_id].items->_ + lookup_table_offset + 4 * lookup_idx
        );

    a1->_inside_mobd_item = (DataMobdItem_stru0 **)v;
    if (v)
    {
        if (v->flags)
            a1->_60_mobd_anim_speed = v->flags;
        a1->_64_mobd_anim_related = -1;
        a1->_inside_mobd_item_2 = (DataMobdItem_stru0 **)v;
        sprite_427460_init_mobd_item(a1);
    }
}

//----- (00427320) --------------------------------------------------------
void sprite_427320_load_mobd_item_sound(Sprite *a1, int offset)
{
    DataMobdItem_stru0 **v2; // esi@1
    DataMobdItem_stru0 **v3; // eax@3
    DataMobdItem_stru0 **v6; // edx@6
    DataMobdItem_stru0 **v7; // eax@6
    DataMobdItem_stru0 *v9; // edx@6
    Sprite_stru58 *v10; // eax@6
    enum SOUND_ID v11; // edx@6

    v2 = a1->_inside_mobd_item;
    if (v2)
    {
        v6 = (DataMobdItem_stru0 **)((char *)currently_running_lvl_mobd[a1->mobd_id].items + offset);
        v7 = (DataMobdItem_stru0 **)((char *)v6 + (unsigned int)((char *)a1->_inside_mobd_item_2 - (char *)v2));
        a1->_inside_mobd_item = v6;
        a1->_inside_mobd_item_2 = v7;
        a1->_54_inside_mobd_ptr4 = v7[0];
        v9 = a1->_54_inside_mobd_ptr4;
        v10 = (Sprite_stru58 *)v7[4];
        a1->field_88_unused = 1;
        a1->pstru58 = v10;
        v11 = v9->_14_sound_id;
        if (v11)
            sprite_408800_play_sound(a1, v11, 16, 0);
    }
    else if (a1)
    {
        sprite_4272E0_load_mobd_item(a1, offset, 0);
        /*v3 = (DataMobdItem_stru0 **)((char *)currently_running_lvl_mobd[a1->mobd_id].items + offset);
        a1->_inside_mobd_item = v3;
        a1->_inside_mobd_item_2 = a1->_inside_mobd_item;
        if (v3[0])
        a1->_60_mobd_field_0_int = (int)v3[0];
        a1->field_64 = -1;
        sprite_427460_init_mobd_item(a1);*/
    }
}

//----- (004273B0) --------------------------------------------------------
void sprite_4273B0_load_mobd_item_sound(Sprite *a1, int mobd_lookup_offset, int mobd_lookup_id)
{
    DataMobdItem_stru0 **v3; // esi@1
    DataMobdItem_stru0 **v4; // eax@2
    DataMobdItem_stru0 **v7; // eax@6
    DataMobdItem_stru0 **v8; // edx@6
    DataMobdItem_stru0 **v9; // eax@7
    DataMobdItem_stru0 *v11; // edx@7
    Sprite_stru58 *v12; // eax@7
    enum SOUND_ID v13; // edx@7

    v3 = a1->_inside_mobd_item;
    if (v3)
    {
        v7 = (DataMobdItem_stru0 **)((char *)a1->_inside_mobd_item_2 - (char *)v3);
        v8 = *(DataMobdItem_stru0 ***)((char *)&currently_running_lvl_mobd[a1->mobd_id].items->_
            + 4 * mobd_lookup_id
            + mobd_lookup_offset);
        a1->_inside_mobd_item = v8;
        if (v8)
        {
            v9 = (DataMobdItem_stru0 **)((char *)v7 + (_DWORD)v8);
            a1->_inside_mobd_item_2 = v9;

            a1->_54_inside_mobd_ptr4 = v9[0];
            v11 = a1->_54_inside_mobd_ptr4;
            v12 = (Sprite_stru58 *)(*v9)->ptr_10;
            a1->field_88_unused = 1;
            a1->pstru58 = v12;
            v13 = v11->_14_sound_id;
            if (v13)
                sprite_408800_play_sound(a1, v13, 16, 0);
        }
    }
    else
    {
        sprite_4272E0_load_mobd_item(a1, mobd_lookup_offset, mobd_lookup_id);
        /*v4 = *(DataMobdItem_stru0 ***)((char *)&currently_running_lvl_mobd[a1->mobd_id].items->_
        + 4 * mobd_lookup_id
        + mobd_lookup_offset);
        a1->_inside_mobd_item = v4;
        if (v4)
        {
        if (v4[0])
        a1->_60_mobd_anim_speed = (int)v4[0];
        a1->field_64 = -1;
        a1->_inside_mobd_item_2 = a1->_inside_mobd_item;
        sprite_427460_init_mobd_item(a1);
        }*/
    }
}

//----- (00427450) --------------------------------------------------------
void sprite_release_mobd_item(Sprite *a1)
{
    a1->_inside_mobd_item = 0;
    a1->_inside_mobd_item_2 = 0;
    a1->_54_inside_mobd_ptr4 = 0;
    a1->pstru58 = 0;
}

//----- (00427460) --------------------------------------------------------
void sprite_427460_init_mobd_item(Sprite *pstru6)
{
    Sprite *v1; // esi@1
    int v3; // eax@2
            //DataMobdItem_stru0 **v4; // eax@3
    DataMobdItem_stru0 *v5; // ecx@3
    Script *v6; // eax@4
    DataMobdItem_stru0 *v7; // eax@7
    Script *v10; // eax@7
    DataMobdItem_stru0 *v12; // eax@10
    enum SOUND_ID v13; // edx@10
    DataMobdItem_stru1 *v14; // ecx@12
    Script *v15; // eax@13

    v1 = pstru6;
    DataMobdItem_stru2 *v2 = (DataMobdItem_stru2 *)pstru6->_inside_mobd_item_2;
    if (v2)
    {
        v3 = v1->_64_mobd_anim_related;
        if (v3 < 0)
        {
            v1->_64_mobd_anim_related = v3 & 0x7FFFFFFF;

            v5 = v2->pstru0;
            if (v5)
            {
                if (v5 == (DataMobdItem_stru0 *)-1)
                {
                    v1->_inside_mobd_item_2 = v1->_inside_mobd_item + 1;

                    v7 = v1->_inside_mobd_item_2[0];
                    v1->_54_inside_mobd_ptr4 = v7;

                    v10 = v1->script;
                    v1->pstru58 = (Sprite_stru58 *)v7->ptr_10;
                    if (v10)
                    {
                        v10->flags_20 |= SCRIPT_FLAGS_20_10000000;
                        v1->script->flags_24 |= v1->script->flags_20;
                    }
                }
                else
                {
                    v1->_inside_mobd_item_2 = v1->_inside_mobd_item_2 + 1;
                    v1->_54_inside_mobd_ptr4 = v5;
                    v1->pstru58 = (Sprite_stru58 *)v5->ptr_10;
                }
                v12 = v1->_54_inside_mobd_ptr4;
                v1->field_88_unused = 1;
                v13 = v12->_14_sound_id;
                if (v13)
                    sprite_408800_play_sound(v1, v13, 16, 0);
                v14 = v1->_54_inside_mobd_ptr4->field_18;
                if (v14)
                {
                    v15 = v1->script;
                    if (v15)
                    {
                        if (v15->_28_yield_flags & SCRIPT_FLAGS_20_40000)
                        {
                            script_trigger_event(0, (SCRIPT_EVENT)((int)EVT_MOUSE_HOVER | 0x1), v14, v1->script);
                            v1->script->flags_20 |= SCRIPT_FLAGS_20_40000;
                            v1->script->flags_24 |= v1->script->flags_20;
                        }
                    }
                }
            }
            else
            {
                v6 = v1->script;
                v1->_inside_mobd_item_2 = 0;
                v1->_inside_mobd_item = 0;
                if (v6)
                {
                    v6->flags_20 |= SCRIPT_FLAGS_20_10000000;
                    v1->script->flags_24 |= v1->script->flags_20;
                    v1->_64_mobd_anim_related -= v1->_60_mobd_anim_speed;
                    return;
                }
            }
        }
        v1->_64_mobd_anim_related -= v1->_60_mobd_anim_speed;
    }
}

//----- (00427580) --------------------------------------------------------
void sprite_list_init_mobd_items()
{
    Sprite *i; // esi@2
    Script *v1; // eax@4
    signed __int16 v2; // ax@5

    if (currently_running_lvl_mobd_valid)
    {
        for (i = sprite_list_47A4A0; (Sprite **)i != &sprite_list_47A4A0; i = i->next)
        {
            if (is_async_execution_supported && (v1 = i->script) != 0)
                v2 = v1->field_1C & 1;
            else
                v2 = 1;
            if (v2)
                sprite_427460_init_mobd_item(i);
        }
    }
}

//----- (004275D0) --------------------------------------------------------
void sprite_list_free()
{
    if (currently_running_lvl_mobd_valid)
    {
        if (sprite_list)
        {
            free(sprite_list);
            currently_running_lvl_mobd_valid = 0;
            sprite_list = 0;
        }
    }
}
