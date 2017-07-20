#include "src/kknd.h"

#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"

#include "src/Cursor.h"
#include "src/Script.h"
#include "src/ScriptEvent.h"
#include "src/Random.h"


//----- (0042C9E0) --------------------------------------------------------
void cursor_drag_selection(_428940_local *a1, int x, int y)
{
    _428940_local *v3; // esi@1
    int v6; // edx@2
    Sprite *v8; // edx@5
    bool v10; // sf@5
    unsigned __int8 v11; // of@5
    task_428940_attach__cursors *v12; // ecx@9
    char *v13; // eax@10
    task_428940_attach__cursors *v14; // eax@11
    _428940_local *v15; // eax@15
    int v16; // ecx@21
    Script *v17; // ecx@21
    task_428940_attach__cursors_2 *v18; // eax@24
    int v19; // eax@28
    int v20; // ecx@29
    int v21; // ecx@31
    enum UNIT_ID v22; // edx@35
    enum UNIT_ID v23; // ecx@35
    int v24; // eax@40
    int v25; // eax@46
    enum SOUND_ID v26; // ecx@48
    int v27; // edx@58
    int v28; // ecx@58
    int v29; // edx@58
    task_428940_attach__cursors *v30; // ecx@58
    task_428940_attach__cursors *v31; // edx@58
    int v32; // eax@59
    char v33; // bl@59
    task_428940_attach__cursors *v34; // eax@60
    Sprite *v35; // ecx@65
    int v36; // [sp-Ch] [bp-2Ch]@48
    int v39; // [sp+18h] [bp-8h]@21
    int a2; // [sp+1Ch] [bp-4h]@1
    Entity *a2a; // [sp+1Ch] [bp-4h]@21
    task_428940_attach__cursors *ya; // [sp+24h] [bp+4h]@9
    _428940_local *yb; // [sp+24h] [bp+4h]@15
    Script *yc; // [sp+24h] [bp+4h]@21

    a2 = x;
    v3 = a1;
    a1->field_40 = 0;
    a1->_48_unit_stats_idx = (UNIT_ID)0;
    a1->field_44 = 0;

    Sprite *cursor_460 = sprite_create(MOBD_CURSORS, 0, 0);
    sprite_4272A0_load_mobd_item(cursor_460, 460);
    cursor_460->drawjob->on_update_handler = (DrawJobUpdateHandler)drawjob_update_handler_448430;

    Sprite *cursor_472 = sprite_create(MOBD_CURSORS, 0, 0);
    sprite_4272A0_load_mobd_item(cursor_472, 472);
    cursor_472->drawjob->on_update_handler = (DrawJobUpdateHandler)drawjob_update_handler_448430;

    Sprite *cursor_484 = sprite_create(MOBD_CURSORS, 0, 0);
    sprite_4272A0_load_mobd_item(cursor_484, 484);
    cursor_484->drawjob->on_update_handler = (DrawJobUpdateHandler)drawjob_update_handler_448430;

    Sprite *cursor_496 = sprite_create(MOBD_CURSORS, 0, 0);
    sprite_4272A0_load_mobd_item(cursor_496, 496);
    cursor_496->drawjob->on_update_handler = (DrawJobUpdateHandler)drawjob_update_handler_448430;

    /*while (true)
    {
        v3->_70_sprite->field_88 = 1;
        v6 = v3->_70_sprite->x;
        cursor_460->field_88 = 1;

        v3->_70_sprite->field_88 = 1;
        cursor_460->x = v3->_70_sprite->x;
        cursor_484->field_88 = 1;
        v3->_70_sprite->field_88 = 1;
        cursor_484->x = v3->_70_sprite->x;
        cursor_472->field_88 = 1;
        cursor_472->x = a2;
        cursor_496->x = a2;
        cursor_496->field_88 = 1;


        cursor_460->y = v3->_70_sprite->y;
        cursor_472->field_88 = 1;
        cursor_472->y = v3->_70_sprite->y;
        cursor_484->field_88 = 1;
        cursor_484->y = y;
        cursor_496->field_88 = 1;


        cursor_496->y = y;
        _42B740_cursors(v3, 0);
    }*/

    while (!(_47A5E0_mouse_input.just_released_buttons_mask & INPUT_MOUSE_LBUTTON_MASK))
    {
        v3->_70_sprite->field_88 = 1;
        v6 = v3->_70_sprite->x;
        cursor_460->field_88 = 1;
        if (v6 < a2)
        {
            v3->_70_sprite->field_88 = 1;
            cursor_460->x = v3->_70_sprite->x;
            cursor_484->field_88 = 1;
            v3->_70_sprite->field_88 = 1;
            cursor_484->x = v3->_70_sprite->x;
            cursor_472->field_88 = 1;
            cursor_472->x = a2;
            cursor_496->x = a2;
            cursor_496->field_88 = 1;
        }
        else
        {
            cursor_460->x = a2;
            cursor_484->x = a2;
            cursor_484->field_88 = 1;
            cursor_472->field_88 = 1;
            v3->_70_sprite->field_88 = 1;
            cursor_472->x = v3->_70_sprite->x;
            cursor_496->field_88 = 1;
            v3->_70_sprite->field_88 = 1;
            cursor_496->x = v3->_70_sprite->x;
        }
        v8 = v3->_70_sprite;
        v11 = __OFSUB__(v8->y, y);
        v10 = v8->y - y < 0;
        cursor_460->field_88 = 1;
        if (v10 ^ v11)
        {
            cursor_460->y = v3->_70_sprite->y;
            cursor_472->field_88 = 1;
            cursor_472->y = v3->_70_sprite->y;
            cursor_484->field_88 = 1;
            cursor_484->y = y;
            cursor_496->field_88 = 1;
            cursor_496->y = y;
        }
        else
        {
            cursor_460->y = y;
            cursor_472->field_88 = 1;
            cursor_472->y = y;
            cursor_484->field_88 = 1;
            cursor_484->y = v3->_70_sprite->y;
            cursor_496->field_88 = 1;
            cursor_496->y = v3->_70_sprite->y;
        }
        _42B740_cursors(v3, 0);
    }
    v12 = _47A714.ptr_0;
    LOBYTE_HEXRAYS(stru_47A718.ptr_0) = 3;
    ya = task_428940_attach__cursors_list_free_pool;
    if (task_428940_attach__cursors_list_free_pool)
    {
        v13 = (char *)&task_428940_attach__cursors_list_free_pool->field_4;
        task_428940_attach__cursors_list_free_pool = task_428940_attach__cursors_list_free_pool->next;
        *(_DWORD *)v13 = (int)stru_47A718.ptr_0;
        *((_DWORD *)v13 + 1) = stru_47A718.field_4;
        *((_DWORD *)v13 + 2) = stru_47A718.field_8;
        v13[12] = stru_47A718.field_C;
        ya->next = 0;
        if (_47A714.ptr_0)
        {
            v14 = v12->next;
            if (v12->next)
            {
                do
                {
                    v12 = v14;
                    v14 = v14->next;
                } while (v14);
            }
            v12->next = ya;
        }
        else
        {
            _47A714.ptr_0 = ya;
        }
    }
    v3->field_38 = 0;
    v3->_68_entity = 0;
    v3->_68_entity_type___0convoy__2lab__9scout__3saboteur_vandal__4technicial_mekanik__and_more_see429D40 = 0;
    dword_468980 = -1;
    v15 = v3->next;
    yb = v3->next;
    if (v3->next != v3)
    {
        while (1)
        {
            script_trigger_event(task_mobd17_cursor, EVT_MSG_TEXT_STRING, 0, v15->_8_task);
            yb = yb->next;
            if (yb == v3)
                break;
            v15 = yb;
        }
    }
    if (v3->next != v3)
    {
        v3->prev->next = (_428940_local *)v3->ptr_10;
        v3->ptr_10 = (task_428940_attach__cursors_2 *)v3->next;
        v3->next = v3;
        v3->prev = v3;
    }
    _42B740_cursors(v3, 0);
    cursor_496->field_88 = 1;
    v16 = cursor_460->y;
    cursor_460->field_88 = 1;
    sub_44C970(v16, cursor_460->x, cursor_496->x, cursor_496->y);
    v39 = 0;
    a2a = 0;
    v3->field_38 = 0;
    v17 = _44C9A0_get__47DCA4_entity_task();
    yc = v17;
    if (v17)
    {
        while (1)
        {
            v18 = v3->ptr_10;
            if (v18)
                v3->ptr_10 = v18->next;
            else
                v18 = 0;
            if (v18)
            {
                v18->_8_task = v17;
                v18->next = (task_428940_attach__cursors_2 *)v3->next;
                v18->prev = (task_428940_attach__cursors_2 *)v3;
                v3->next->prev = (_428940_local *)v18;
                v3->next = (_428940_local *)v18;
                script_trigger_event(0, EVT_MSG_1511_sidebar_click_category, 0, v17);
                v19 = (int)yc->param;
                if (*(_DWORD *)(v19 + 20) == player_side)
                {
                    v3->field_38 = 1;
                    a2a = (Entity *)v19;
                    ++v39;
                    v20 = *(_DWORD *)(v19 + 16);
                    if (v20 <= (int)UNIT_STATS_MUTE_MISSILE_CRAB || v20 >= (int)UNIT_STATS_GORT)
                    {
                        v3->_68_entity = (Entity *)v19;
                        v3->field_40 = 1;
                        v21 = *(_DWORD *)(v19 + 16);
                        if ((v21 < (int)UNIT_STATS_SURV_MOBILE_DERRICK || v21 >(int)UNIT_STATS_TANKER_CONVOY)
                            && (v21 < (int)UNIT_STATS_SURV_TECHNICIAN || v21 >(int)UNIT_STATS_MUTE_MEKANIK))
                        {
                            v22 = v3->_48_unit_stats_idx;
                            v3->field_44 = 1;
                            v23 = (UNIT_ID)*(_DWORD *)(v19 + 16);
                            if ((int)v23 > (int)v22 && v23 != UNIT_STATS_MUTE_BIKE_AND_SIDECAR)
                                v3->_48_unit_stats_idx = v23;
                        }
                        if (*(_DWORD *)(v19 + 16) == UNIT_STATS_TANKER_CONVOY)
                            v3->field_40 = 0;
                    }
                    v24 = *(_DWORD *)(v19 + 16);
                    if (v24 >= (int)UNIT_STATS_SURV_GUARD_TOWER && v24 <= (int)UNIT_STATS_MUTE_ROTARY_CANNON)
                        v3->field_44 = 1;
                }
            }
            yc = _44C9A0_get__47DCA4_entity_task();
            if (!yc)
                break;
            v17 = yc;
        }
    }
    if (v39 == 1)
    {
        v3->field_3C = 1;
        sub_429D40(v3, a2a);
    }
    else
    {
        v25 = v3->field_38;
        v3->field_3C = 0;
        if (v25)
        {
            switch (v3->_48_unit_stats_idx)
            {
            case UNIT_STATS_GORT:
            case UNIT_STATS_PLASMA_TANK:
            case UNIT_STATS_SENTINEL_DROID:
            case UNIT_STATS_MECH:
                v36 = _4690A8_unit_sounds_volume;
                v26 = _4689A8_sound_ids[kknd_rand() % -2];
                goto LABEL_57;
            case UNIT_STATS_MUTE_DIRE_WOLF:
                v36 = _4690A8_unit_sounds_volume;
                v26 = (SOUND_ID)165;
                goto LABEL_57;
            case UNIT_STATS_MUTE_GIANT_BEETLE:
                v36 = _4690A8_unit_sounds_volume;
                v26 = (SOUND_ID)168;
                goto LABEL_57;
            case UNIT_STATS_MUTE_GIANT_SCORPION:
                v36 = _4690A8_unit_sounds_volume;
                v26 = (SOUND_ID)172;
                goto LABEL_57;
            case UNIT_STATS_MUTE_MISSILE_CRAB:
                v36 = _4690A8_unit_sounds_volume;
                v26 = (SOUND_ID)170;
                goto LABEL_57;
            case UNIT_STATS_MUTE_WAR_MASTADONT:
                v36 = _4690A8_unit_sounds_volume;
                v26 = (SOUND_ID)160;
                goto LABEL_57;
            default:
                if (get_player_faction())
                {
                    v36 = _4690A8_unit_sounds_volume;
                    v26 = _468998_sound_ids[(unsigned __int8)((char)kknd_rand() % -4)];
                }
                else
                {
                    v36 = _4690A8_unit_sounds_volume;
                    v26 = _468988_sound_ids[(unsigned __int8)((char)kknd_rand() % -4)];
                }
            LABEL_57:
                sound_play(v26, 0, v36, 16, 0);
                break;
            case UNIT_STATS_TANKER_CONVOY:
                break;
            }
        }
    }
    v27 = cursor_460->x;
    cursor_460->field_88 = 1;
    *(_WORD *)((char *)&stru_47A718.ptr_0 + 1) = v27 >> 8;
    *(_WORD *)((char *)&stru_47A718.ptr_0 + 3) = cursor_460->y >> 8;
    v28 = cursor_496->x >> 8;
    cursor_496->field_88 = 1;
    *(_WORD *)((char *)&stru_47A718.field_4 + 1) = v28;
    v29 = cursor_496->y;
    v30 = _47A714.ptr_0;
    LOBYTE_HEXRAYS(stru_47A718.ptr_0) = 1;
    *(_WORD *)((char *)&stru_47A718.field_4 + 3) = v29 >> 8;
    v31 = task_428940_attach__cursors_list_free_pool;
    if (task_428940_attach__cursors_list_free_pool)
    {
        task_428940_attach__cursors_list_free_pool = task_428940_attach__cursors_list_free_pool->next;
        v32 = (int)&v31->field_4;
        v31->field_4 = (int)stru_47A718.ptr_0;
        *(_DWORD *)(v32 + 4) = stru_47A718.field_4;
        *(_DWORD *)(v32 + 8) = stru_47A718.field_8;
        v33 = stru_47A718.field_C;
        v31->next = 0;
        *(_BYTE *)(v32 + 12) = v33;
        if (_47A714.ptr_0)
        {
            v34 = v30->next;
            if (v30->next)
            {
                do
                {
                    v30 = v34;
                    v34 = v34->next;
                } while (v34);
            }
            v30->next = v31;
        }
        else
        {
            _47A714.ptr_0 = v31;
        }
    }
    sprite_list_remove(cursor_460);
    sprite_list_remove(cursor_472);
    sprite_list_remove(cursor_484);
    sprite_list_remove(cursor_496);
    dword_468984 = -1;
    if (v3->_20_load_mobd_item_offset != 12)
    {
        v35 = v3->_70_sprite;
        v3->_20_load_mobd_item_offset = 12;
        sprite_4272A0_load_mobd_item(v35, 12);
    }
}