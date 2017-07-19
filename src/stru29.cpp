#include "src/kknd.h"

#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"

#include "src/stru29.h"


stru29 stru29_list_47C610;

stru29 *stru29_list = nullptr;
stru29 *stru29_list_free_pool = nullptr;
stru29 *_47C6D4_stru29 = nullptr;




stru29 *stru29_list_first()
{
    return stru29_list_47C610.next;
}
stru29 *stru29_list_end()
{
    return &stru29_list_47C610;
}

stru29 *stru29_list_toggle_by_sprite(Sprite *sprite, int flag)
{
    for (stru29 *i = stru29_list_first(); i != stru29_list_end(); i = i->next)
    {
        if (i->sprite == sprite)
        {
            i->field_C |= flag;
            return i;
        }
    }
    return nullptr;
}

bool stru29_list_realloc(Script *a1)
{
    stru29_list_remove_all(a1);
    return stru29_list_alloc();
}

//----- (00443980) --------------------------------------------------------
bool stru29_list_alloc()
{
    _47C6D4_stru29 = nullptr;

    stru29_list = new stru29[30];
    if (stru29_list)
    {
        stru29_list_free_pool = stru29_list;
        stru29_list[29].next = nullptr;

        for (int i = 0; i < 29; ++i)
        {
            stru29_list[i].next = &stru29_list[i + 1];
        }

        stru29_list_47C610.next = &stru29_list_47C610;
        stru29_list_47C610.prev = &stru29_list_47C610;

        stru29_list_initialized = true;
        return true;
    }
    return false;
}

//----- (004439F0) --------------------------------------------------------
stru29 *stru29_list_4439F0(Sprite *a1, void *param, int a3, int a4, int a5)
{
    int v5; // esi@1
    stru29 *i; // eax@2
    stru29 *v7; // esi@5
    stru29 *v8; // eax@5
    stru29 *v9; // edx@10
    stru29 *v10; // edx@16
    int v11; // eax@20

    v5 = a1->y;
    a1->param = param;
    if (a4)
    {
        for (i = stru29_list_first(); i != stru29_list_end(); i = i->next)
        {
            if (v5 < i->sprite->y)
                break;
        }
        v7 = stru29_list_free_pool;
        v8 = i->prev;
        if (stru29_list_free_pool)
            stru29_list_free_pool = stru29_list_free_pool->next;
        else
            v7 = 0;
        if (v7)
        {
            v7->sprite = a1;
            v7->field_C = 0;
            v9 = v8->next;
            v7->prev = v8;
            v7->next = v9;
            v8->next->prev = v7;
            v8->next = v7;
        }
        else
        {
            game_state = 3;
        }
    }
    else
    {
        v7 = stru29_list_free_pool;
        if (stru29_list_free_pool)
            stru29_list_free_pool = stru29_list_free_pool->next;
        else
            v7 = 0;
        if (v7)
        {
            v7->sprite = a1;
            v7->field_C = 0;
            v10 = stru29_list_first();
            v7->prev = stru29_list_end();
            v7->next = v10;
            stru29_list_47C610.next->prev = v7;
            stru29_list_47C610.next = v7;
        }
        else
        {
            game_state = 3;
        }
    }
    if (a3)
    {
        _43BAB0_move_cursor(a1);
        _47C6D4_stru29 = v7;
    }
    if (a5)
    {
        v11 = v7->field_C;
        LOBYTE_HEXRAYS(v11) = v11 | 2;
        v7->field_C = v11;
    }
    return v7;
}

//----- (00443AE0) --------------------------------------------------------
stru29 *stru29_list_443AE0_find_by_sprite(Sprite *a1)
{
    stru29 *result; // eax@1

    result = stru29_list_first();
    if (result != stru29_list_end())
    {
        while (a1 != result->sprite)
        {
            result = result->next;
            if (result == stru29_list_end())
                return result;
        }
        _47C6D4_stru29 = result;
    }
    return result;
}

//----- (00443B10) --------------------------------------------------------
void stru29_list_free()
{
    if (stru29_list && stru29_list_initialized)
    {
        delete[] stru29_list;
        stru29_list_initialized = false;
    }
}

//----- (00443B40) --------------------------------------------------------
void stru29_list_remove_all(Script *a1)
{
    stru29 *v1; // esi@1
    Script *v2; // ebp@1
    Sprite *v3; // edi@2
    RenderString *v4; // ecx@2
    Script *v5; // ebx@2
    Sprite *v6; // eax@4
    Sprite *v7; // eax@5
    stru29 **v8; // eax@11

    v1 = stru29_list_first();
    v2 = a1;
    if (v1 != stru29_list_end())
    {
        do
        {
            v3 = v1->sprite;
            v4 = (RenderString *)v3->param;
            v5 = v3->script;
            if (v4)
                render_string_list_remove(v4);
            v6 = v3->parent;
            if (v6)
            {
                v7 = v6->parent;
                if (v7)
                    sprite_list_remove(v7);
                sprite_list_remove(v3->parent);
            }
            sprite_list_remove(v3);
            if (v5 != v2 && v5)
                script_deinit(v5);
            v8 = &v1->prev->next;
            v1->next->prev = (stru29 *)v8;
            v1->prev->next = v1->next;
            v1->next = stru29_list_free_pool;
            stru29_list_free_pool = v1;
            v1 = *v8;
        } while (*v8 != stru29_list_end());
    }
    stru29_list_free();
}

//----- (00443BF0) --------------------------------------------------------
void stru29_list_443BF0_remove_some()
{
    stru29 *i; // eax@1
    int v1; // ecx@2
    stru29 *v2; // ecx@4

    for (i = stru29_list_first(); i != stru29_list_end(); i = i->next)
    {
        v1 = i->field_C;
        if (v1 & 1)
        {
            i->field_C = v1 & 0xFFFFFFFE;
        }
        else
        {
            v2 = i->prev;
            i->next->prev = v2;
            i->prev->next = i->next;
            i->next = stru29_list_free_pool;
            stru29_list_free_pool = i;
            i = v2;
        }
    }
}