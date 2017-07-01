#include "src/kknd.h"

#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"

#include "src/Random.h"


//----- (00438B40) --------------------------------------------------------
void _438B40_reset_explosions()
{
    _47C350_num_explosions_min0_max30 = 0;
    num_explosions = 0;
}

//----- (00438B50) --------------------------------------------------------
int _438B50_can_create_more_explosions()
{
    int result; // eax@2

    if (num_explosions <= 10)
    {
        ++num_explosions;
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (00438B70) --------------------------------------------------------
void decrease_num_explosions()
{
    if (num_explosions > 0)
        --num_explosions;
}

//----- (00438B80) --------------------------------------------------------
void script_438B80_on_death_explosion(Script *task)
{
    Sprite *v1; // esi@1
    int v2; // eax@1
    char v3; // al@1

    v1 = task->sprite;
    v2 = kknd_rand_debug("k/Scripts/Schrap.cpp", 155);
    sprite_4272A0_load_mobd_item(v1, dword_46BC84[v2 % 5]);
    v1->z_index = 0;
    v1->field_3C = 549;
    v3 = kknd_rand_debug("k/Scripts/Schrap.cpp", 158);
    v1->field_30 = -10;
    v1->field_24 = (v3 & 0x7F) + 336;
    while (v1->z_index >= 0)
        script_445370_yield(task, 0x80000000, 1);
    if (_47C350_num_explosions_min0_max30 > 0)
        --_47C350_num_explosions_min0_max30;
    sprite_list_remove(v1);
    script_445470_yield(task);
}

//----- (00438C20) --------------------------------------------------------
void script_438C20_on_death_explosion(Script *a1)
{
    Sprite *v1; // esi@1
    int v2; // ebx@1
    int v3; // ebp@1
    int v4; // ebp@1
    int v5; // eax@2

    v1 = a1->sprite;
    v2 = kknd_rand_debug("k/Scripts/Schrap.cpp", 173) % 9;
    v3 = kknd_rand_debug("k/Scripts/Schrap.cpp", 176) & 7;
    v1->field_1C_speed = dword_46BC20[v3] + (unsigned __int8)kknd_rand_debug("k/Scripts/Schrap.cpp", 176) - 128;
    v4 = kknd_rand_debug("k/Scripts/Schrap.cpp", 177) & 7;
    v1->field_20_neg_speed = dword_46BC40[v4] + (unsigned __int8)kknd_rand_debug("k/Scripts/Schrap.cpp", 177) - 128;
    sprite_4272A0_load_mobd_item(v1, dword_46BC60[v2]);
    v1->z_index = 0;
    v1->field_3C = 549;
    v1->field_24 = (kknd_rand_debug("k/Scripts/Schrap.cpp", 183) & 0x7F) + 352;
    if (v2 <= 2)
    {
        v1->field_30 = -9;
    }
    else
    {
        v1->field_30 = -5;
        v5 = kknd_rand_debug("k/Scripts/Schrap.cpp", 187);
        v1->_60_mobd_field_0_int *= (((unsigned __int64)v5 >> 32) ^ abs(v5) & 1) - ((unsigned __int64)v5 >> 32) + 1;
    }
    while (v1->z_index >= 0)
        script_445370_yield(a1, 0x80000000, 1);
    v1->z_index = 1;
    v1->field_1C_speed = 0;
    v1->field_20_neg_speed = 0;
    v1->field_24 = 0;
    v1->field_30 = 0;
    v1->mobd_id = MOBD_EXPLOSIONS;
    sprite_4272A0_load_mobd_item(v1, 412);
    script_445370_yield(a1, 0x10000000, 0);
    if (_47C350_num_explosions_min0_max30 > 0)
        --_47C350_num_explosions_min0_max30;
    sprite_list_remove(v1);
    script_445470_yield(a1);
}

//----- (00438D90) --------------------------------------------------------
void entity_438D90_on_death_explosion(Entity *a1)
{
    Entity *v1; // ebp@1
    enum UNIT_ID v2; // eax@1
    int v3; // ebx@4
    Sprite *v4; // edi@6
    int v5; // esi@7
    int v6; // esi@10
    int v7; // ebx@14
    Sprite *v8; // edi@16
    int v9; // esi@17
    int v10; // esi@19

    v1 = a1;
    v2 = a1->unit_id;
    if (((v2 & 0x80000000) != 0 || (int)v2 > (int)UNIT_STATS_SURV_SCOUT) && v2 != UNIT_STATS_MUTE_DIRE_WOLF)
    {
        if (v2 == UNIT_STATS_MUTE_WAR_MASTADONT)
        {
            v6 = 0;
            do
            {
                if (_47C350_num_explosions_min0_max30 > 30)
                    break;
                ++_47C350_num_explosions_min0_max30;
                if (!sprite_create_scripted(MOBD_69, v1->sprite, script_438C20_on_death_explosion, SCRIPT_COROUTINE, 0))
                    break;
                ++v6;
            } while (v6 < 8);
            v7 = 0;
            do
            {
                if (_47C350_num_explosions_min0_max30 > 30)
                    break;
                ++_47C350_num_explosions_min0_max30;
                v8 = sprite_create_scripted(MOBD_69, v1->sprite, script_438B80_on_death_explosion, SCRIPT_COROUTINE, 0);
                if (!v8)
                    break;
                v9 = (unsigned __int8)((char)v7 % -8);
                v8->field_1C_speed = (kknd_rand_debug("k/Scripts/Schrap.cpp", 263) & 0x7F) + dword_46BC20[v9] - 64;
                ++v7;
                v8->field_20_neg_speed = (kknd_rand_debug("k/Scripts/Schrap.cpp", 264) & 0x7F) + dword_46BC40[v9] - 64;
            } while (v7 < 8);
        }
        else
        {
            v10 = 0;
            do
            {
                if (_47C350_num_explosions_min0_max30 > 30)
                    break;
                ++_47C350_num_explosions_min0_max30;
                if (!sprite_create_scripted(MOBD_69, v1->sprite, script_438C20_on_death_explosion, SCRIPT_COROUTINE, 0))
                    break;
                ++v10;
            } while (v10 < 24);
        }
    }
    else
    {
        v3 = 0;
        do
        {
            if (_47C350_num_explosions_min0_max30 > 30)
                break;
            ++_47C350_num_explosions_min0_max30;
            v4 = sprite_create_scripted(MOBD_69, v1->sprite, script_438B80_on_death_explosion, SCRIPT_COROUTINE, 0);
            if (!v4)
                break;
            v5 = (unsigned __int8)((char)v3 % -8);
            v4->field_1C_speed = (kknd_rand_debug("k/Scripts/Schrap.cpp", 231) & 0x7F) + dword_46BC20[v5] - 64;
            ++v3;
            v4->field_20_neg_speed = (kknd_rand_debug("k/Scripts/Schrap.cpp", 232) & 0x7F) + dword_46BC40[v5] - 64;
        } while (v3 < 6);
    }
}

//----- (00438F50) --------------------------------------------------------
void script_438F50_explosions(Script *a1)
{
    Sprite *v1; // esi@1
    int v2; // ebp@1
    int v3; // edi@1
    unsigned __int8 v4; // al@3
    int v5; // ecx@3
    char v6; // al@3

    v1 = a1->sprite;
    v2 = 30;
    v3 = (unsigned __int8)((char)kknd_rand_debug("k/Scripts/Schrap.cpp", 293) % -8);
    if (v3 < 4)
        v2 = 60;
    v1->pstru7 = &_479D48_stru7;
    v1->x += ((unsigned __int8)kknd_rand_debug("k/Scripts/Schrap.cpp", 300) - 128) << 8;
    v4 = kknd_rand_debug("k/Scripts/Schrap.cpp", 301);
    v5 = v1->y;
    v1->z_index = 0;
    v1->y = ((v4 - 128) << 8) + v5;
    v6 = kknd_rand_debug("k/Scripts/Schrap.cpp", 303);
    script_445370_yield(a1, 0x80000000, v2 + (v6 & 0x3F));
    sprite_4272A0_load_mobd_item(v1, dword_46BC98[v3]);
    _4389A0_prolly_create_map_damage_decal(v1->x, v1->y);
    script_445370_yield(a1, 0x10000000, 0);
    if (_47C350_num_explosions_min0_max30 > 0)
        --_47C350_num_explosions_min0_max30;
    sprite_list_remove(v1);
    script_445470_yield(a1);
}

//----- (00439050) --------------------------------------------------------
void script_439050_explosions(Script *a1)
{
    Sprite *v1; // esi@1
    int v2; // [sp+Ch] [bp-24h]@1
    int v3; // [sp+10h] [bp-20h]@1
    int v4; // [sp+14h] [bp-1Ch]@1
    int v5; // [sp+18h] [bp-18h]@1
    int v6; // [sp+1Ch] [bp-14h]@1
    int v7; // [sp+20h] [bp-10h]@1
    int v8; // [sp+24h] [bp-Ch]@1
    int v9; // [sp+28h] [bp-8h]@1
    int v10; // [sp+2Ch] [bp-4h]@1

    v1 = a1->sprite;
    v2 = 0;
    v3 = 0;
    v4 = 0;
    v5 = 0;
    v6 = 0;
    v7 = 0;
    v8 = 0;
    v9 = 0;
    v10 = 0;
    if (!v1->param)
        v1->param = &v2;
    sprite_408800_play_sound(v1, SOUND_3, _4690A8_unit_sounds_volume, 0);
    sprite_4272A0_load_mobd_item(v1, 144);
    script_445370_yield(a1, 0x10000000, 0);
    if (num_explosions > 0)
        --num_explosions;
    sprite_list_remove(a1->sprite);
    script_445470_yield(a1);
}

//----- (004390F0) --------------------------------------------------------
Sprite *entity_4390F0_add_explosion(Entity *a1)
{
    Sprite *result; // eax@1

    result = 0;
    if (num_explosions <= 10)                   // INLINED _438B50_can_create_more_explosions
    {
        ++num_explosions;
        result = sprite_create_scripted(MOBD_EXPLOSIONS, a1->sprite, script_439050_explosions, SCRIPT_COROUTINE, 0);
    }
    return result;
}

//----- (00439120) --------------------------------------------------------
Sprite *entity_439120_add_explosion(Entity *a1)
{
    Sprite *result; // eax@1

    result = 0;
    if (num_explosions <= 10)                   // INLINED _438B50_can_create_more_explosions
    {
        ++num_explosions;
        result = sprite_create_scripted(MOBD_EXPLOSIONS, a1->sprite, script_44BE60_explosions, SCRIPT_COROUTINE, 0);
    }
    return result;
}

//----- (00439150) --------------------------------------------------------
Sprite *entity_439150_add_explosion(Entity *a1)
{
    Sprite *result; // eax@1

    result = 0;
    if (num_explosions <= 10)                   // INLINED _438B50_can_create_more_explosions
    {
        ++num_explosions;
        result = sprite_create_scripted(MOBD_EXPLOSIONS, a1->sprite, script_403380_explosions, SCRIPT_COROUTINE, 0);
    }
    return result;
}

//----- (00439180) --------------------------------------------------------
void sprite_439180_add_explosions(Sprite *a2)
{
    Sprite *v1; // edi@1
    int v2; // ebx@1

    v1 = a2;
    nullsub_1();
    v2 = 0;
    do
    {
        if (_47C350_num_explosions_min0_max30 > 30)
            break;
        ++_47C350_num_explosions_min0_max30;
        if (!sprite_create_scripted(MOBD_EXPLOSIONS, v1, script_438F50_explosions, SCRIPT_COROUTINE, 0))
            break;
        ++v2;
    } while (v2 < 20);
}