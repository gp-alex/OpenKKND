#include "src/kknd.h"

#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"

#include "src/Random.h"
#include "src/Script.h"
#include "src/ScriptEvent.h"

//----- (00435A40) --------------------------------------------------------
void UNIT_DmgHandler_Sapper(Script *a1)
{
    Sprite *v1; // esi@1
    Entity *v2; // eax@1
    int v3; // ST1C_4@1
    Entity *v4; // ebp@1
    int v5; // edx@1
    Sprite *v6; // eax@1
    int v7; // ebx@1
    int v8; // edi@1
    int v9; // eax@1
    int v10; // edi@1
    int v11; // eax@1
    int v12; // edx@1
    UnitStat *v13; // ecx@1
    int v14; // edx@1
    int v15; // eax@1
    int v16; // ebx@1
    int v17; // eax@5
    int v18; // ecx@5
    int v19; // ebx@5
    int v20; // edx@5
    int v21; // ebp@7
    int v22; // eax@9
    int v23; // ST04_4@13
    char v24; // al@13
    Sprite *v25; // eax@14
    int v26; // [sp+10h] [bp-14h]@3
    int v27; // [sp+10h] [bp-14h]@5
    Entity *v28; // [sp+14h] [bp-10h]@1
    int v29; // [sp+18h] [bp-Ch]@1
    int a3; // [sp+1Ch] [bp-8h]@1
    int v31; // [sp+20h] [bp-4h]@1

    v1 = a1->sprite;
    v2 = (Entity *)a1->param;
    v28 = v2;
    v3 = (int)v1->param;
    v4 = (Entity *)v1->parent->param;
    v2->sprite->field_88_unused = 1;
    v5 = v1->y;
    v1->field_88_unused = 1;
    v6 = v2->sprite;
    v7 = (v6->y - v5) >> 8;
    v8 = (v6->x - v1->x) >> 8;
    v29 = (signed __int16)_42D560_get_mobd_lookup_id_rotation(v8, v7);
    v9 = math_42D64D_prolly_vec_length(v8, v7);
    v10 = v3;
    v11 = v9 / *(_DWORD *)(v3 + 16);
    v12 = v28->entity_id;
    v1->pstru7 = &_479D48_stru7;
    v13 = v4->stats;
    v31 = v12;
    a3 = v11;
    v14 = _465640_accuracy_bonus[v4->_98_465610_accuracy_dmg_bonus_idx];
    v15 = v14 + v13->accuracy;
    v16 = v14 + v13->accuracy;
    if (v15 >= 100)
        v16 = 99;
    v26 = v14 + v13->accuracy;
    if (v15 >= 100)
        v26 = 99;
    v17 = kknd_rand_debug(__FILE__, __LINE__);
    v18 = _465640_accuracy_bonus[v4->_98_465610_accuracy_dmg_bonus_idx];
    v19 = 16 * (v17 % (100 - v16) - (100 - v26) / 2);
    v20 = v4->stats->accuracy;
    v27 = v18 + v20;
    if (v18 + v20 >= 100)
        v27 = 99;
    v21 = v18 + v20;
    if (v18 + v20 >= 100)
        v21 = 99;
    v22 = kknd_rand_debug(__FILE__, __LINE__);
    v1->x_speed = v19 + *(_DWORD *)(v10 + 16) * _4731A8_speeds[__47CFC4_mobd_lookup_speeds[v29 + 1]];
    v1->y_speed = 16 * (v22 % (100 - v27) - (100 - v21) / 2)
        - *(_DWORD *)(v10 + 16) * _4731C8_speeds[__47CFC4_mobd_lookup_speeds[v29 + 1]];
    v1->z_speed_limit = 512;
    v1->z_speed = 512;
    if (a3 > 2)
        v1->z_speed_factor_2 = -512 / (a3 / 2);
    else
        v1->z_speed_factor_2 = -512;
    v1->_60_mobd_field_0_int = (kknd_rand_debug(__FILE__, __LINE__) % 3 + 1) << 28;
    script_445370_yield_to_main_thread(a1, 0x80000000, a3);
    v1->z_index = 1;
    v1->x_speed = 0;
    v1->y_speed = 0;
    v1->z_speed = 0;
    v1->z_speed_factor_2 = 0;
    if (*(_DWORD *)(v10 + 12) != -1)
    {
        v1->z_index = 255;
        v23 = _4690A8_unit_sounds_volume;
        v24 = kknd_rand_debug(__FILE__, __LINE__);
        sprite_408800_play_sound(v1, _46BB80_dmg_handler_sounds[(unsigned __int8)(v24 % -2)], v23, 0);
        v1->mobd_id = MOBD_EXPLOSIONS;
        sprite_4272A0_load_mobd_item(v1, *(_DWORD *)(v10 + 12));
        v1->_60_mobd_field_0_int = 0x20000000;
        if (v28->entity_id == v31)
        {
            v25 = v28->sprite;
            if (v25)
                v1->z_index = v25->z_index + 256;
        }
        sprite_40D8B0_dmg(v1, *(_DWORD *)(v10 + 32));
    }
    script_445370_yield_to_main_thread(a1, 0x10000000, 0);
    sprite_list_remove(v1);
    --_47C048_unit_bomberdmg;
}
// 47C048: using guessed type int _47C048_unit_bomberdmg;

//----- (00435CF0) --------------------------------------------------------
void script_435CF0_rocket_dmg_handler(Script *a1)
{
    Sprite *v1; // esi@1

    v1 = a1->sprite;
    ++_47C04C_num_explosions_max20;
    sprite_4272A0_load_mobd_item(v1, 412);
    script_445370_yield_to_main_thread(a1, 0x10000000, 0);
    sprite_list_remove(v1);
    --_47C04C_num_explosions_max20;
}
// 47C04C: using guessed type int _47C04C_num_explosions_max20;

//----- (00435D40) --------------------------------------------------------
void script_435D40_bombers_dmg(Sprite *a1, int a2)
{
    Entity *v2; // esi@1
    int v3; // ebx@1
    Sprite *i; // edi@1
    enum UNIT_ID v5; // eax@2
    int v6; // eax@6

    v2 = entity_list_head;
    v3 = a2;
    for (i = a1; (Entity **)v2 != &entity_list_head; v2 = v2->next)
    {
        v5 = v2->unit_id;
        if ((v5 == UNIT_STATS_SURV_BOMBER || v5 == UNIT_STATS_MUTE_WASP) && !v2->destroyed && v2->script)
        {
            LOBYTE_HEXRAYS(v6) = _40D860_prolly_sprite_distance(i, v2->sprite, v3);
            if (v6)
                script_trigger_event(i->script, EVT_MSG_DAMAGE, i, v2->script);
        }
    }
}

//----- (00435DB0) --------------------------------------------------------
void UNIT_DmgHandler_Rocket(Script *a1)
{
    Entity *v1; // ebp@1
    Sprite *v2; // esi@1
    Entity *v3; // ecx@1
    int v4; // ebx@1
    int v5; // edx@1
    Sprite *v6; // eax@1
    int v7; // edi@1
    int v8; // ebx@1
    int v9; // eax@2
    int v10; // eax@3
    int v11; // ecx@3
    DrawJob *v12; // edx@4
    int v13; // ecx@6
    int v14; // eax@6
    int v15; // ebp@6
    int v16; // ebx@8
    int v17; // eax@10
    int v18; // ecx@10
    int v19; // ebp@10
    int v20; // edx@10
    int v21; // edi@10
    int v22; // ebx@12
    int v23; // eax@14
    int v24; // edi@14
    int v25; // edi@15
    int v26; // ST04_4@22
    char v27; // al@22
    DrawJob *v28; // ecx@23
    Entity *v29; // edi@24
    int i; // ebx@24
    enum UNIT_ID v31; // eax@25
    int v32; // eax@29
    int v33; // [sp+10h] [bp-18h]@1
    void *v34; // [sp+14h] [bp-14h]@1
    int v35; // [sp+18h] [bp-10h]@1
    Entity *v36; // [sp+1Ch] [bp-Ch]@1
    int v37; // [sp+20h] [bp-8h]@3
    int v38; // [sp+24h] [bp-4h]@3

    v1 = (Entity *)a1->param;
    v2 = a1->sprite;
    v33 = 0;
    v34 = v2->param;
    v3 = (Entity *)v2->parent->param;
    v35 = v1->sprite->z_index >= 5120;
    v36 = (Entity *)v2->parent->param;
    v2->drawjob->job_details.palette = per_player_sprite_palettes[player_sprite_color_by_player_side[v3->player_side]];
    v2->drawjob->flags |= 0x10000000u;
    v1->sprite->field_88_unused = 1;
    v4 = v2->x;
    v5 = v2->y;
    v2->field_88_unused = 1;
    v6 = v1->sprite;
    v7 = (v6->x - v4) >> 8;
    v8 = (v6->y - v5) >> 8;
    if (v3->turret)
    {
        v9 = v2->z_index;
        v2->field_88_unused = 1;
        v2->z_index = v9 + 5120;
        v2->y = v5 + 2560;
    }
    v37 = (signed __int16)_42D560_get_mobd_lookup_id_rotation(v7, v8);
    v10 = math_42D64D_prolly_vec_length(v7, v8);
    v11 = 2 * (v10 / *((_DWORD *)v34 + 4)) + 1;
    v38 = 2 * (v10 / *((_DWORD *)v34 + 4)) + 1;
    if (v35)
    {
        v12 = v2->drawjob;
        v2->z_index = 0;
        v12->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_448510_aircraft;
        if (v11 > 0)
            v2->z_speed = (v2->z_index + v1->sprite->z_index) / v11;
    }
    v13 = v36->stats->accuracy;
    v14 = v13 + _465640_accuracy_bonus[v36->_98_465610_accuracy_dmg_bonus_idx];
    v15 = v13 + _465640_accuracy_bonus[v36->_98_465610_accuracy_dmg_bonus_idx];
    if (v14 >= 100)
        v15 = 99;
    v16 = v13 + _465640_accuracy_bonus[v36->_98_465610_accuracy_dmg_bonus_idx];
    if (v14 >= 100)
        v16 = 99;
    v17 = kknd_rand_debug(__FILE__, __LINE__);
    v18 = _465640_accuracy_bonus[v36->_98_465610_accuracy_dmg_bonus_idx];
    v19 = 16 * (v17 % (100 - v15) - (100 - v16) / 2);
    v20 = v36->stats->accuracy;
    v21 = v18 + v20;
    if (v18 + v20 >= 100)
        v21 = 99;
    v22 = v18 + v20;
    if (v18 + v20 >= 100)
        v22 = 99;
    v23 = kknd_rand_debug(__FILE__, __LINE__);
    v2->pstru7 = &_479D48_stru7;
    v24 = 16 * (v23 % (100 - v21) - (100 - v22) / 2);
    sprite_408800_play_sound(v2, SOUND_14_dmg, _4690A8_unit_sounds_volume, 0);
    v2->x_speed = (v19 + *((_DWORD *)v34 + 4) * _4731A8_speeds[__47CFC4_mobd_lookup_speeds[v37 + 1]]) >> 1;
    v2->y_speed = (v24 - *((_DWORD *)v34 + 4) * _4731C8_speeds[__47CFC4_mobd_lookup_speeds[v37 + 1]]) >> 1;
    if (v38 > 0)
    {
        v25 = v38;
        do
        {
            if (v33 <= 0)
            {
                if (_47C04C_num_explosions_max20 < 20)
                    sprite_create_scripted(MOBD_EXPLOSIONS, v2, script_435CF0_rocket_dmg_handler, SCRIPT_COROUTINE, 0);
                v33 = 12;
            }
            script_445370_yield_to_main_thread(a1, 0x80000000, 1);
            --v25;
            --v33;
        } while (v25);
    }
    v2->x_speed = 0;
    v2->y_speed = 0;
    v2->z_speed = 0;
    v2->x_speed_factor_2 = 0;
    v2->y_speed_factor_2 = 0;
    v2->z_speed_factor_2 = 0;
    if (*((_DWORD *)v34 + 3) != -1)
    {
        v26 = _4690A8_unit_sounds_volume;
        v27 = kknd_rand_debug(__FILE__, __LINE__);
        sprite_408800_play_sound(v2, _46BB80_dmg_handler_sounds[(unsigned __int8)(v27 % -2)], v26, 0);
        v2->mobd_id = MOBD_EXPLOSIONS;
        sprite_4272A0_load_mobd_item(v2, *((_DWORD *)v34 + 3));
        v2->_60_mobd_field_0_int = 0x20000000;
        if (v35)
        {
            v29 = entity_list_head;
            for (i = *((_DWORD *)v34 + 8); (Entity **)v29 != &entity_list_head; v29 = v29->next)
            {
                v31 = v29->unit_id;
                if ((v31 == UNIT_STATS_SURV_BOMBER || v31 == UNIT_STATS_MUTE_WASP) && !v29->destroyed)
                {
                    if (v29->script)
                    {
                        LOBYTE_HEXRAYS(v32) = _40D860_prolly_sprite_distance(v2, v29->sprite, i);
                        if (v32)
                            script_trigger_event(v2->script, EVT_MSG_DAMAGE, v2, v29->script);
                    }
                }
            }
        }
        else
        {
            v28 = v2->drawjob;
            v2->z_index = 0;
            v28->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_4484A0_explosions;
            _4389A0_prolly_create_map_damage_decal(v2->x, v2->y);
            sprite_40D8B0_dmg(v2, *((_DWORD *)v34 + 8));
        }
    }
    script_445370_yield_to_main_thread(a1, 0x10000000, 0);
    sprite_list_remove(v2);
    --_47C048_unit_bomberdmg;
}
// 47C048: using guessed type int _47C048_unit_bomberdmg;
// 47C04C: using guessed type int _47C04C_num_explosions_max20;

//----- (00436140) --------------------------------------------------------
void script_436140_flamethrower_dmg_handler(Script *a1)
{
    Sprite *v1; // esi@1
    Entity *v2; // eax@1
    int v3; // ebp@1
    int v4; // edx@1
    Sprite *v5; // eax@1
    int v6; // ebx@1
    int v7; // edi@1
    int v8; // ST1C_4@1
    int v9; // eax@1

    v1 = a1->sprite;
    v2 = (Entity *)a1->param;
    v3 = (int)v1->param;
    v2->sprite->field_88_unused = 1;
    v4 = v1->x;
    v1->field_88_unused = 1;
    v5 = v2->sprite;
    v6 = (v5->y - v1->y) >> 8;
    v7 = (v5->x - v4) >> 8;
    v8 = (signed __int16)_42D560_get_mobd_lookup_id_rotation(v7, v6);
    sprite_408800_play_sound(v1, (SOUND_ID)((int)SOUND_70 | 0x10), _4690A8_unit_sounds_volume, 0);
    sprite_4272A0_load_mobd_item(v1, 496);
    v1->x_speed = (kknd_rand_debug(__FILE__, __LINE__) & 0xF)
        + *(_DWORD *)(v3 + 16) * _4731A8_speeds[__47CFC4_mobd_lookup_speeds[v8 + 1]]
        - 8;
    v1->y_speed = (kknd_rand_debug(__FILE__, __LINE__) & 0xF)
        - *(_DWORD *)(v3 + 16) * _4731C8_speeds[__47CFC4_mobd_lookup_speeds[v8 + 1]]
        - 8;
    v9 = math_42D64D_prolly_vec_length(v7, v6);
    script_445370_yield_to_main_thread(a1, 0x80000002, v9 / *(_DWORD *)(v3 + 16));
    sprite_list_remove(v1);
    --_47C048_unit_bomberdmg;
}
// 47C048: using guessed type int _47C048_unit_bomberdmg;

//----- (00436250) --------------------------------------------------------
void UNIT_DmgHandler_Flamethrower(Script *a1)
{
    Sprite *v1; // ebx@1
    Entity *v2; // eax@1
    int v3; // edi@1
    int v4; // ebp@1
    Entity *v5; // esi@1
    EntityTurret *v6; // eax@7
    Sprite *v7; // edx@8
    Sprite *v8; // eax@10
    Script *v9; // edx@10
    void(*v10)(Script *); // [sp-Ch] [bp-20h]@8
    Entity_stru_dmg_related *v11; // [sp-4h] [bp-18h]@8
    Entity *v12; // [sp+10h] [bp-4h]@1

    v1 = a1->sprite;
    v2 = (Entity *)a1->param;
    v12 = v2;
    v3 = (int)v1->param;
    v4 = 0;
    v5 = (Entity *)v1->parent->param;
    v2->sprite->field_88_unused = 1;
    v1->field_88_unused = 1;
    while (!v2->destroyed && v5->entity_id && !v5->destroyed && _47C048_unit_bomberdmg < 200)
    {
        ++_47C048_unit_bomberdmg;
        v6 = v5->turret;
        if (v6)
        {
            v7 = v6->turret_sprite;
            v11 = v6->ptr_24;
            v10 = script_436140_flamethrower_dmg_handler;
        }
        else
        {
            v11 = v5->stru60.ptr_0;
            v7 = v1->parent;
            v10 = script_436140_flamethrower_dmg_handler;
        }
        v8 = sprite_create_scripted(MOBD_EXPLOSIONS, v7, v10, SCRIPT_COROUTINE, v11);
        v9 = v8->script;
        v8->parent = v1->parent;
        v9->param = v12;
        v8->param = (void *)v3;
        v8->_80_entity__stru29__sprite__initial_hitpoints = v5;
        v8->field_84 = v5->entity_id;
        v8->field_8C_infantry_damage = *(_WORD *)(v3 + 20)
            + (*(_DWORD *)(v3 + 20)
                * _465610_damage_multipliers[v5->_98_465610_accuracy_dmg_bonus_idx] >> 8);
        v8->field_8E_vehicle_damage = *(_WORD *)(v3 + 24)
            + (*(_DWORD *)(v3 + 24)
                * _465610_damage_multipliers[v5->_98_465610_accuracy_dmg_bonus_idx] >> 8);
        ++v4;
        v8->field_90_building_damage = *(_WORD *)(v3 + 28)
            + (*(_DWORD *)(v3 + 28)
                * _465610_damage_multipliers[v5->_98_465610_accuracy_dmg_bonus_idx] >> 8);
        script_445370_yield_to_main_thread(a1, 0x80000000, 5);
        if (v4 >= 8)
            break;
        v2 = v12;
    }
    sprite_list_remove(v1);
    --_47C048_unit_bomberdmg;
}
// 47C048: using guessed type int _47C048_unit_bomberdmg;

//----- (004363C0) --------------------------------------------------------
void script_4363C0_giant_bettle_dmg(Script *a1)
{
    Script *v1; // edi@1
    Entity *v2; // ebx@1
    Sprite *v3; // esi@1
    int v4; // ebp@1
    int v5; // ecx@1
    int v6; // eax@1
    int v7; // ebp@1
    int v8; // edx@4
    int v9; // eax@4
    Sprite *v10; // ebx@7
    int v11; // [sp+10h] [bp-4h]@1
    int v12; // [sp+18h] [bp+4h]@1

    v1 = a1;
    v2 = (Entity *)a1->param;
    v3 = a1->sprite;
    v4 = (int)v3->param;
    v11 = (int)v3->param;
    v2->sprite->field_88_unused = 1;
    v5 = v3->y;
    v3->field_88_unused = 1;
    v6 = math_42D64D_prolly_vec_length((v2->sprite->x - v3->x) >> 8, (v2->sprite->y - v5) >> 8);
    v12 = v2->entity_id;
    v7 = v6 / *(_DWORD *)(v4 + 16);
    sprite_4272A0_load_mobd_item(v3, 1784);
    v3->pstru7 = &_479D48_stru7;
    v3->z_speed_limit = 512;
    v3->z_speed = 512;
    if (v7 > 2)
        v3->z_speed_factor_2 = -512 / (v7 / 2);
    else
        v3->z_speed_factor_2 = -512;
    v8 = kknd_rand_debug(__FILE__, __LINE__) % 3;
    v9 = v3->z_index;
    v3->_60_mobd_field_0_int = (v8 + 1) << 28;
    if (v9 >= 0)
    {
        do
            script_445370_yield_to_main_thread(v1, 0x80000000, 1);
        while (v3->z_index >= 0);
    }
    v3->x_speed = 0;
    v3->y_speed = 0;
    v3->z_speed = 0;
    v3->z_speed_factor_2 = 0;
    v3->z_index = 255;
    sprite_408800_play_sound(v3, SOUND_ACID_SPIT_DMG, _4690A8_unit_sounds_volume, 0);
    v3->mobd_id = MOBD_EXPLOSIONS;
    sprite_4272A0_load_mobd_item(v3, 704);
    v3->_60_mobd_field_0_int = 0x20000000;
    if (v2->entity_id == v12)
    {
        v10 = v2->sprite;
        if (v10)
            v3->z_index = v10->z_index + 256;
    }
    sprite_40D8B0_dmg(v3, *(_DWORD *)(v11 + 32));
    script_445370_yield_to_main_thread(v1, 0x10000000, 0);
    sprite_list_remove(v3);
    --_47C048_unit_bomberdmg;
}
// 47C048: using guessed type int _47C048_unit_bomberdmg;

//----- (00436530) --------------------------------------------------------
void UNIT_DmgHandler_Beetle(Script *a1)
{
    Sprite *v1; // ebp@1
    int v2; // edi@1
    Entity *v3; // ebx@1
    int v4; // esi@1
    Sprite *v5; // ecx@1
    Sprite *v6; // eax@2
    Sprite *v7; // esi@2
    Script *v8; // ecx@2
    UnitStat *v9; // ecx@2
    int v10; // edx@2
    int v11; // eax@2
    int v12; // ecx@6
    int v13; // edx@6
    int v14; // eax@10
    Sprite *v15; // esi@14
    Script *v16; // edx@14
    int v17; // eax@16
    Entity *v18; // [sp+10h] [bp-24h]@1
    int v19; // [sp+14h] [bp-20h]@2
    int v20; // [sp+14h] [bp-20h]@8
    int v21; // [sp+18h] [bp-1Ch]@4
    int v22; // [sp+18h] [bp-1Ch]@6
    int v23; // [sp+1Ch] [bp-18h]@1
    Sprite *v24; // [sp+20h] [bp-14h]@2
    int v25; // [sp+24h] [bp-10h]@1
    int v26; // [sp+28h] [bp-Ch]@6
    int v27; // [sp+2Ch] [bp-8h]@1
    int v28; // [sp+30h] [bp-4h]@1

    v1 = a1->sprite;
    v18 = (Entity *)a1->param;
    v2 = (int)v1->param;
    v3 = (Entity *)v1->parent->param;
    v18->sprite->field_88_unused = 1;
    v4 = v1->x;
    v1->field_88_unused = 1;
    v5 = v18->sprite;
    v28 = (v5->x - v4) >> 8;
    v27 = (v5->y - v1->y) >> 8;
    v23 = (signed __int16)_42D560_get_mobd_lookup_id_rotation(v28, v27);
    v25 = 0;
    sprite_408800_play_sound(v3->sprite, SOUND_ACID_SPIT_DMG, _4690A8_unit_sounds_volume, 0);
    if (_47C048_unit_bomberdmg < 200)
    {
        ++_47C048_unit_bomberdmg;
        v6 = sprite_create_scripted(MOBD_MUTE_GIANT_BEETLE, v1->parent, script_4363C0_giant_bettle_dmg, SCRIPT_COROUTINE, v3->stru60.ptr_0);
        v7 = v6;
        v24 = v6;
        v8 = v6->script;
        v6->parent = v1->parent;
        v8->param = v18;
        v6->param = (void *)v2;
        v9 = v3->stats;
        v10 = _465640_accuracy_bonus[v3->_98_465610_accuracy_dmg_bonus_idx];
        v11 = v10 + v9->accuracy;
        v19 = v10 + v9->accuracy;
        if (v11 >= 100)
            v19 = 99;
        v21 = v10 + v9->accuracy;
        if (v11 >= 100)
            v21 = 99;
        v26 = 4 * (kknd_rand_debug(__FILE__, __LINE__) % (100 - v19) - (100 - v21) / 2);
        v12 = _465640_accuracy_bonus[v3->_98_465610_accuracy_dmg_bonus_idx];
        v13 = v3->stats->accuracy;
        v22 = v12 + v13;
        if (v12 + v13 >= 100)
            v22 = 99;
        v20 = v12 + v13;
        if (v12 + v13 >= 100)
            v20 = 99;
        v14 = kknd_rand_debug(__FILE__, __LINE__);
        v7->x_speed = v26 + *(_DWORD *)(v2 + 16) * _4731A8_speeds[__47CFC4_mobd_lookup_speeds[v23 + 1]];
        v7->y_speed = 4 * (v14 % (100 - v22) - (100 - v20) / 2)
            - *(_DWORD *)(v2 + 16) * _4731C8_speeds[__47CFC4_mobd_lookup_speeds[v23 + 1]];
        script_445370_yield_to_main_thread(a1, 0x80000000, 2);
        do
        {
            if (v18->destroyed || v3->destroyed)
                break;
            if (_47C048_unit_bomberdmg < 200)
            {
                ++_47C048_unit_bomberdmg;
                v15 = sprite_create_scripted(
                    MOBD_MUTE_GIANT_BEETLE,
                    v1->parent,
                    script_4363C0_giant_bettle_dmg,
                    SCRIPT_COROUTINE,
                    v3->stru60.ptr_0);
                v16 = v15->script;
                v15->parent = v1->parent;
                v16->param = v18;
                v15->param = (void *)v2;
                v15->_80_entity__stru29__sprite__initial_hitpoints = v3;
                v15->field_84 = v3->entity_id;
                v15->field_8C_infantry_damage = *(_WORD *)(v2 + 20)
                    + (*(_DWORD *)(v2 + 20)
                        * _465610_damage_multipliers[v3->_98_465610_accuracy_dmg_bonus_idx] >> 8);
                v15->field_8E_vehicle_damage = *(_WORD *)(v2 + 24)
                    + (*(_DWORD *)(v2 + 24)
                        * _465610_damage_multipliers[v3->_98_465610_accuracy_dmg_bonus_idx] >> 8);
                v15->field_90_building_damage = *(_WORD *)(v2 + 28)
                    + (*(_DWORD *)(v2 + 28)
                        * _465610_damage_multipliers[v3->_98_465610_accuracy_dmg_bonus_idx] >> 8);
                v15->x_speed = v24->x_speed + 4 * (kknd_rand_debug(__FILE__, __LINE__) & 0x1F) - 64;
                v15->y_speed = v24->y_speed + 4 * (kknd_rand_debug(__FILE__, __LINE__) & 0x1F) - 64;
            }
            ++v25;
            script_445370_yield_to_main_thread(a1, 0x80000000, 2);
        } while (v25 < 6);
        v17 = math_42D64D_prolly_vec_length(v28, v27);
        script_445370_yield_to_main_thread(a1, 0x80000000, v17 / *(_DWORD *)(v2 + 16) - 12);
    }
    sprite_list_remove(v1);
    --_47C048_unit_bomberdmg;
}
// 47C048: using guessed type int _47C048_unit_bomberdmg;

//----- (004368B0) --------------------------------------------------------
void script_4368B0_plasma_tank_dmg_handler(Script *a1)
{
    Sprite *v1; // esi@1
    Entity *v2; // ebp@1
    int v3; // edx@1
    int v4; // ecx@1
    Sprite *v5; // eax@1
    int v6; // ST20_4@1
    int v7; // edi@1
    int v8; // ebx@1
    int v9; // eax@1
    int v10; // ST04_4@1
    char v11; // al@1
    int v12; // [sp+10h] [bp-8h]@1

    v1 = a1->sprite;
    v2 = (Entity *)a1->param;
    v12 = (int)v1->param;
    v2->sprite->field_88_unused = 1;
    v3 = v1->y;
    v4 = v1->x;
    v1->field_88_unused = 1;
    v5 = v2->sprite;
    v6 = v2->entity_id;
    v7 = (v5->x - v4) >> 8;
    v8 = (v5->y - v3) >> 8;
    sprite_4272A0_load_mobd_item(v1, 1152);
    v1->pstru7 = &_479D48_stru7;
    v9 = math_42D64D_prolly_vec_length(v7, v8);
    script_445370_yield_to_main_thread(a1, 0x80000000, v9 / *(_DWORD *)(v12 + 16));
    v1->x_speed = 0;
    v1->y_speed = 0;
    v1->z_speed = 0;
    v1->z_speed_factor_2 = 0;
    v1->z_index = 255;
    v10 = _4690A8_unit_sounds_volume;
    v11 = kknd_rand_debug(__FILE__, __LINE__);
    sprite_408800_play_sound(v1, _46BB80_dmg_handler_sounds[(unsigned __int8)(v11 % -2)], v10, 0);
    v1->mobd_id = MOBD_PLASMA_TANK;
    sprite_4272A0_load_mobd_item(v1, 2084);
    v1->_60_mobd_field_0_int = 0x20000000;
    if (v6 == v2->entity_id)
        v1->z_index = v2->sprite->z_index + 256;
    sprite_40D8B0_dmg(v1, *(_DWORD *)(v12 + 32));
    script_445370_yield_to_main_thread(a1, 0x10000000, 0);
    sprite_list_remove(v1);
    --_47C048_unit_bomberdmg;
}
// 47C048: using guessed type int _47C048_unit_bomberdmg;

//----- (004369F0) --------------------------------------------------------
void UNIT_DmgHandler_Mech(Script *a1)
{
    Sprite *v1; // esi@1
    Entity *v2; // ecx@1
    Sprite *v3; // ebx@1
    Entity *v4; // edi@1
    int v5; // ebx@2
    int v6; // edx@2
    Sprite *v7; // ecx@2
    int v8; // ebp@2
    int v9; // ecx@2
    int v10; // eax@2
    int v11; // ebx@4
    int v12; // ecx@6
    int v13; // edx@6
    int v14; // ebx@6
    int v15; // eax@10
    int v16; // ebx@10
    int v17; // eax@10
    int v18; // ST04_4@11
    char v19; // al@11
    DrawJob *v20; // ecx@11
    int v21; // ebp@13
    Sprite *v22; // ecx@13
    EntityTurret *v23; // eax@13
    int v24; // ebx@13
    int v25; // ebp@13
    int v26; // eax@15
    int v27; // ecx@15
    DrawJob *v28; // edx@16
    UnitStat *v29; // ecx@18
    int v30; // edx@18
    int v31; // eax@18
    int v32; // ebx@18
    int v33; // ebp@20
    int v34; // eax@22
    int v35; // ecx@22
    int v36; // ebx@22
    int v37; // edx@22
    int v38; // edi@22
    int v39; // ebp@24
    int v40; // eax@26
    int v41; // edi@26
    int v42; // edi@27
    int v43; // ST04_4@34
    char v44; // al@34
    DrawJob *v45; // ecx@35
    Entity *v46; // edi@36
    int i; // ebp@36
    enum UNIT_ID v48; // eax@37
    int v49; // eax@41
    int v50; // [sp+10h] [bp-18h]@1
    int v51; // [sp+10h] [bp-18h]@2
    int v52; // [sp+10h] [bp-18h]@8
    int v53; // [sp+14h] [bp-14h]@2
    int v54; // [sp+14h] [bp-14h]@15
    int v55; // [sp+18h] [bp-10h]@1
    int v56; // [sp+1Ch] [bp-Ch]@1
    int v57; // [sp+1Ch] [bp-Ch]@6
    int v58; // [sp+20h] [bp-8h]@1
    int v59; // [sp+20h] [bp-8h]@2
    int v60; // [sp+24h] [bp-4h]@15

    v1 = a1->sprite;
    v2 = (Entity *)a1->param;
    v3 = v2->sprite;
    v58 = (int)a1->param;
    v4 = (Entity *)v1->parent->param;
    v55 = (int)v1->param;
    v56 = v3->z_index >= 5120;
    v50 = 0;
    if (v4->turret->field_1C % 3)
    {
        v3->field_88_unused = 1;
        v5 = v1->y;
        v6 = v1->x;
        v1->field_88_unused = 1;
        v7 = v2->sprite;
        v8 = (v7->x - v6) >> 8;
        v59 = (v7->y - v5) >> 8;
        v53 = (signed __int16)_42D560_get_mobd_lookup_id_rotation(v8, v59);
        v1->mobd_id = MOBD_MECH;
        sprite_4272A0_load_mobd_item(v1, 1152);
        v1->pstru7 = &_479D48_stru7;
        v9 = v4->stats->accuracy;
        v10 = v9 + _465640_accuracy_bonus[v4->_98_465610_accuracy_dmg_bonus_idx];
        v51 = v9 + _465640_accuracy_bonus[v4->_98_465610_accuracy_dmg_bonus_idx];
        if (v10 >= 100)
            v51 = 99;
        v11 = v9 + _465640_accuracy_bonus[v4->_98_465610_accuracy_dmg_bonus_idx];
        if (v10 >= 100)
            v11 = 99;
        v57 = 8 * (kknd_rand_debug(__FILE__, __LINE__) % (100 - v51) - (100 - v11) / 2);
        v12 = _465640_accuracy_bonus[v4->_98_465610_accuracy_dmg_bonus_idx];
        v13 = v4->stats->accuracy;
        v14 = v12 + v13;
        if (v12 + v13 >= 100)
            v14 = 99;
        v52 = v12 + v13;
        if (v12 + v13 >= 100)
            v52 = 99;
        v15 = kknd_rand_debug(__FILE__, __LINE__);
        v1->z_index = v4->sprite->z_index + 2560;
        v16 = 8 * (v15 % (100 - v14) - (100 - v52) / 2);
        sprite_408800_play_sound(v4->sprite, SOUND_LASER_DMG, _4690A8_unit_sounds_volume, 0);
        v1->x_speed = v57 + *(_DWORD *)(v55 + 16) * _4731A8_speeds[__47CFC4_mobd_lookup_speeds[v53 + 1]];
        v1->y_speed = v16 - *(_DWORD *)(v55 + 16) * _4731C8_speeds[__47CFC4_mobd_lookup_speeds[v53 + 1]];
        v17 = math_42D64D_prolly_vec_length(v8, v59);
        script_445370_yield_to_main_thread(a1, 0x80000000, v17 / *(_DWORD *)(v55 + 16));
        v1->x_speed = 0;
        v1->y_speed = 0;
        if (*(_DWORD *)(v55 + 12) != -1)
        {
            v18 = _4690A8_unit_sounds_volume;
            v19 = kknd_rand_debug(__FILE__, __LINE__);
            sprite_408800_play_sound(v1, _46BB80_dmg_handler_sounds[(unsigned __int8)(v19 % -2)], v18, 0);
            v1->mobd_id = MOBD_EXPLOSIONS;
            sprite_4272A0_load_mobd_item(v1, 2084);
            v20 = v1->drawjob;
            v1->_60_mobd_field_0_int = 0x20000000;
            v1->z_index = 0;
            v20->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_4484A0_explosions;
            _4389A0_prolly_create_map_damage_decal(v1->x, v1->y);
            sprite_40D8B0_dmg(v1, *(_DWORD *)(v55 + 32));
        }
    }
    else
    {
        v1->drawjob->job_details.palette = per_player_sprite_palettes[player_sprite_color_by_player_side[v4->player_side]];
        v1->drawjob->flags |= 0x10000000u;
        v2->sprite->field_88_unused = 1;
        v21 = v1->x;
        v1->field_88_unused = 1;
        v22 = v2->sprite;
        v23 = v4->turret;
        v24 = (v22->x - v21) >> 8;
        v25 = (v22->y - v1->y) >> 8;
        if (v23)
            v1->z_index = v23->turret_sprite->z_index + 1280;
        v54 = (signed __int16)_42D560_get_mobd_lookup_id_rotation(v24, v25);
        v26 = math_42D64D_prolly_vec_length(v24, v25);
        v27 = 2 * (v26 / *(_DWORD *)(v55 + 16)) + 1;
        v60 = 2 * (v26 / *(_DWORD *)(v55 + 16)) + 1;
        if (v56)
        {
            v28 = v1->drawjob;
            v1->z_index = 0;
            v28->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_448510_aircraft;
            if (v27 > 0)
                v1->z_speed = 2 * *(_DWORD *)(*(_DWORD *)(v58 + 92) + 24) / v27;
        }
        v29 = v4->stats;
        v30 = _465640_accuracy_bonus[v4->_98_465610_accuracy_dmg_bonus_idx];
        v31 = v30 + v29->accuracy;
        v32 = v30 + v29->accuracy;
        if (v31 >= 100)
            v32 = 99;
        v33 = v30 + v29->accuracy;
        if (v31 >= 100)
            v33 = 99;
        v34 = kknd_rand_debug(__FILE__, __LINE__);
        v35 = _465640_accuracy_bonus[v4->_98_465610_accuracy_dmg_bonus_idx];
        v36 = 16 * (v34 % (100 - v32) - (100 - v33) / 2);
        v37 = v4->stats->accuracy;
        v38 = v35 + v37;
        if (v35 + v37 >= 100)
            v38 = 99;
        v39 = v35 + v37;
        if (v35 + v37 >= 100)
            v39 = 99;
        v40 = kknd_rand_debug(__FILE__, __LINE__);
        v1->pstru7 = &_479D48_stru7;
        v41 = 16 * (v40 % (100 - v38) - (100 - v39) / 2);
        sprite_408800_play_sound(v1, SOUND_14_dmg, _4690A8_unit_sounds_volume, 0);
        v1->x_speed = (v36 + *(_DWORD *)(v55 + 16) * _4731A8_speeds[__47CFC4_mobd_lookup_speeds[v54 + 1]]) >> 1;
        v1->y_speed = (v41 - *(_DWORD *)(v55 + 16) * _4731C8_speeds[__47CFC4_mobd_lookup_speeds[v54 + 1]]) >> 1;
        if (v60 > 0)
        {
            v42 = v60;
            do
            {
                if (v50 <= 0)
                {
                    if (_47C04C_num_explosions_max20 < 20)
                        sprite_create_scripted(MOBD_EXPLOSIONS, v1, script_435CF0_rocket_dmg_handler, SCRIPT_COROUTINE, 0);
                    v50 = 8;
                }
                script_445370_yield_to_main_thread(a1, 0x80000000, 1);
                --v42;
                --v50;
            } while (v42);
        }
        v1->x_speed = 0;
        v1->y_speed = 0;
        v1->x_speed_factor_2 = 0;
        v1->y_speed_factor_2 = 0;
        v1->z_speed = 0;
        v1->z_speed_factor_2 = 0;
        if (*(_DWORD *)(v55 + 12) != -1)
        {
            v43 = _4690A8_unit_sounds_volume;
            v44 = kknd_rand_debug(__FILE__, __LINE__);
            sprite_408800_play_sound(v1, _46BB80_dmg_handler_sounds[(unsigned __int8)(v44 % -2)], v43, 0);
            v1->mobd_id = MOBD_EXPLOSIONS;
            sprite_4272A0_load_mobd_item(v1, *(_DWORD *)(v55 + 12));
            v1->_60_mobd_field_0_int = 0x20000000;
            if (v56)
            {
                v46 = entity_list_head;
                for (i = *(_DWORD *)(v55 + 32); (Entity **)v46 != &entity_list_head; v46 = v46->next)
                {
                    v48 = v46->unit_id;
                    if ((v48 == UNIT_STATS_SURV_BOMBER || v48 == UNIT_STATS_MUTE_WASP) && !v46->destroyed)
                    {
                        if (v46->script)
                        {
                            LOBYTE_HEXRAYS(v49) = _40D860_prolly_sprite_distance(v1, v46->sprite, i);
                            if (v49)
                                script_trigger_event(v1->script, EVT_MSG_DAMAGE, v1, v46->script);
                        }
                    }
                }
            }
            else
            {
                v45 = v1->drawjob;
                v1->z_index = 0;
                v45->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_4484A0_explosions;
                _4389A0_prolly_create_map_damage_decal(v1->x, v1->y);
                sprite_40D8B0_dmg(v1, *(_DWORD *)(v55 + 32));
            }
        }
    }
    script_445370_yield_to_main_thread(a1, 0x10000000, 0);
    sprite_list_remove(v1);
    --_47C048_unit_bomberdmg;
}
// 47C048: using guessed type int _47C048_unit_bomberdmg;
// 47C04C: using guessed type int _47C04C_num_explosions_max20;

//----- (00436FB0) --------------------------------------------------------
void script_436FB0_dmg_handler(Script *a1)
{
    Sprite *v1; // esi@1

    v1 = a1->sprite;
    script_445370_yield_to_main_thread(a1, 0x80000000, 30);
    sprite_408800_play_sound(v1, SOUND_3, _4690A8_unit_sounds_volume, 0);
    sprite_list_remove(v1);
    --_47C048_unit_bomberdmg;
}
// 47C048: using guessed type int _47C048_unit_bomberdmg;

//----- (00436FF0) --------------------------------------------------------
void script_436FF0_rifle_dmg_handler(Script *a1)
{
    Sprite *v1; // edi@1
    Entity *v2; // esi@1
    EntityTurret *v3; // eax@3
    EntityTurret *v4; // eax@4
    Sprite *v5; // edx@4
    int v6; // eax@4
    int v7; // ecx@4
    EntityTurret *v8; // eax@4
    Entity_stru_dmg_related *v9; // ecx@4
    Sprite *v10; // edx@4
    int v11; // eax@5
    int v12; // ecx@5

    v1 = a1->sprite;
    v2 = (Entity *)v1->parent->param;
    while (!v2->destroyed)
    {
        if (a1->flags_20 & 0x10000000)
            break;
        v3 = v2->turret;
        v1->field_88_unused = 1;
        if (v3)
        {
            v2->turret->turret_sprite->field_88_unused = 1;
            v4 = v2->turret;
            v5 = v4->turret_sprite;
            v6 = v4->ptr_24->x_offset;
            v7 = v5->x;
            v1->field_88_unused = 1;
            v1->x = v7 + v6;
            v8 = v2->turret;
            v9 = v8->ptr_24;
            v10 = v8->turret_sprite;
        }
        else
        {
            v2->sprite->field_88_unused = 1;
            v11 = v2->stru60.ptr_0->x_offset;
            v12 = v2->sprite->x;
            v1->field_88_unused = 1;
            v1->x = v12 + v11;
            v9 = v2->stru60.ptr_0;
            v10 = v2->sprite;
        }
        v1->y = v9->y_offset + v10->y + 2560;
        script_445370_yield_to_main_thread(a1, 0x80000000, 1);
    }
    sprite_list_remove(v1);
    --_47C048_unit_bomberdmg;
}
// 47C048: using guessed type int _47C048_unit_bomberdmg;

//----- (004370D0) --------------------------------------------------------
void script_4370D0_gort_dmg_handler(Script *a1)
{
    Sprite *v1; // esi@1

    v1 = a1->sprite;
    sprite_408800_play_sound(a1->sprite, SOUND_187, _4690A8_unit_sounds_volume, 0);
    script_445370_yield_to_main_thread(a1, 0x10000000, 0);
    sprite_list_remove(v1);
}

//----- (00437110) --------------------------------------------------------
void UNIT_DmgHandler_GORT(Script *a1)
{
    Sprite *v1; // edi@1
    Entity *v2; // ebp@1
    Entity *v3; // esi@1
    Sprite *v4; // eax@1
    Script *v5; // ecx@1
    int v6; // edx@1
    int v7; // edx@3

    v1 = a1->sprite;
    v2 = (Entity *)a1->param;
    v3 = (Entity *)v1->parent->param;
    v4 = sprite_create_scripted(MOBD_EXPLOSIONS, v3->sprite, script_4370D0_gort_dmg_handler, SCRIPT_COROUTINE, v3->stru60.ptr_0);
    v5 = v4->script;
    v4->parent = v1->parent;
    v5->param = v2;
    v4->z_index = v3->sprite->z_index + 5120;
    v4->field_88_unused = 1;
    v2->sprite->field_88_unused = 1;
    v6 = v2->sprite->x;
    v4->field_88_unused = 1;
    v4->x = v6;
    v4->y = v2->sprite->y + 2560;
    sprite_4272A0_load_mobd_item(v4, 2112);
    sprite_408800_play_sound(v3->sprite, SOUND_188, _4690A8_unit_sounds_volume, 0);
    v1->z_index = v3->sprite->z_index + 5120;
    while (!v3->destroyed)
    {
        if (a1->flags_20 & 0x10000000)
            break;
        v1->field_88_unused = 1;
        v3->sprite->field_88_unused = 1;
        v7 = v3->stru60.ptr_0->x_offset + v3->sprite->x;
        v1->field_88_unused = 1;
        v1->x = v7;
        v1->y = v3->sprite->y + v3->stru60.ptr_0->y_offset + 2560;
        if (!v3->destroyed)
            script_trigger_event(a1, EVT_MSG_DAMAGE, v1, v2->script);
        script_445370_yield_to_main_thread(a1, 0x80000000, 1);
    }
    sprite_list_remove(v1);
    --_47C048_unit_bomberdmg;
}
// 47C048: using guessed type int _47C048_unit_bomberdmg;

//----- (00437270) --------------------------------------------------------
void UNIT_DmgHandler_Rifle(Script *a1)
{
    Entity *v1; // ebx@1
    Sprite *v2; // edi@1
    Entity *v3; // esi@1
    enum SOUND_ID v4; // edx@2
    Sprite *v5; // eax@12
    Script *v6; // edx@12
    int v7; // ecx@12
    Sprite *v8; // ecx@14
    Script *v9; // edx@14
    int v10; // edx@14
    int v11; // edx@14
    int v12; // eax@19
    int v13; // ST04_4@20
    int v14; // eax@20
    enum UNIT_ID v15; // eax@21
    int v16; // esi@29
    int v18; // [sp+10h] [bp-8h]@1
    int v19; // [sp+14h] [bp-4h]@1

    v1 = (Entity *)a1->param;
    v2 = a1->sprite;
    v3 = (Entity *)v2->parent->param;
    v19 = v1->entity_id;
    v18 = v1->sprite->z_index >= 5120;
    switch (v3->unit_id)
    {
    case UNIT_STATS_MUTE_SHOTGUNNER:
    case UNIT_STATS_MUTE_DIRE_WOLF:
        v4 = SOUND_SHOTGUN_FIRE;
        break;

    case UNIT_STATS_SURV_AUTOCANNON_TANK:
        v4 = SOUND_CANNON_FIRE;
        break;

    case UNIT_STATS_MUTE_CRAZY_HARRY:
    case UNIT_STATS_SURV_ATV:
        v4 = SOUND_MACHINEGUN_FIRE;
        break;

    case UNIT_STATS_SURV_DIRT_BIKE:
    case UNIT_STATS_SURV_4x4_PICKUP:
    case UNIT_STATS_MONSTER_TRUCK:
        v4 = SOUND_LOW_CALIBER_MACHINEGUN_FIRE;
        break;

    case UNIT_STATS_MUTE_BIKE_AND_SIDECAR:
        v4 = SOUND_BIKE_AND_SIDECAR_FIRE;
        break;

    default:
        v4 = SOUND_RIFLE_FIRE;
        break;
    }
    sprite_408800_play_sound(v3->sprite, v4, _4690A8_unit_sounds_volume, 0);
    if (!v3->destroyed)
    {
        if (v3->turret)
        {
            if (v3->unit_id != UNIT_STATS_SURV_AUTOCANNON_TANK && _47C048_unit_bomberdmg < 200)
            {
                ++_47C048_unit_bomberdmg;
                v5 = sprite_create_scripted(
                    MOBD_EXPLOSIONS,
                    v3->turret->turret_sprite,
                    script_436FF0_rifle_dmg_handler,
                    SCRIPT_COROUTINE,
                    v3->turret->ptr_24);
                v6 = v5->script;
                v5->parent = v2->parent;
                v6->param = v1;
                v7 = v3->turret->turret_sprite->z_index;
                v5->field_88_unused = 1;
                v5->z_index = v7 + 5120;
                v5->y = v3->turret->ptr_24->y_offset + v3->turret->turret_sprite->y + 2560;
                sprite_4272E0_load_mobd_item(v5, 2184, _47D3C4_entity_mobd_lookup_ids[v3->turret->mobd_lookup_id + 1]);
            }
        }
        else if (_47C048_unit_bomberdmg < 200)
        {
            ++_47C048_unit_bomberdmg;
            v8 = sprite_create_scripted(MOBD_EXPLOSIONS, v3->sprite, script_436FF0_rifle_dmg_handler, SCRIPT_COROUTINE, v3->stru60.ptr_0);
            v9 = v8->script;
            v8->parent = v2->parent;
            v9->param = v1;
            v10 = v3->sprite->z_index;
            v8->field_88_unused = 1;
            v8->z_index = v10 + 5120;
            v8->y = v3->sprite->y + v3->stru60.ptr_0->y_offset + 2560;
            v11 = 2248;
            if (!v3->stats->field_30_hp_regen_condition)
                v11 = 2184;
            sprite_4272E0_load_mobd_item(v8, v11, _47D3C4_entity_mobd_lookup_ids[v3->mobd_lookup_idx + 1]);
        }
    }
    if (v18)
        v2->drawjob->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_448510_aircraft;
    v2->field_88_unused = 1;
    v1->sprite->field_88_unused = 1;
    v2->x = v1->sprite->x + (((kknd_rand_debug(__FILE__, __LINE__) & 0x1F) - 16) << 8);
    v2->field_88_unused = 1;
    v2->y = v1->sprite->y + (((kknd_rand_debug(__FILE__, __LINE__) & 0x1F) - 16) << 8);
    v2->z_index = v1->sprite->z_index + 256;
    script_445370_yield_to_main_thread(a1, 0x80000000, 10);
    v2->x_speed = 0;
    v2->y_speed = 0;
    v2->mobd_id = MOBD_EXPLOSIONS;
    v12 = kknd_rand_debug(__FILE__, __LINE__);
    sprite_4272A0_load_mobd_item(v2, _46BB60_dmg_handler_mobd_offsets[v12 % 3]);
    if (!(kknd_rand_debug(__FILE__, __LINE__) % 3))
    {
        v13 = _4690A8_unit_sounds_volume;
        v14 = kknd_rand_debug(__FILE__, __LINE__);
        sprite_408800_play_sound(v2, _46BB70_dmg_handler_sounds[v14 % 3], v13, 0);
    }
    v15 = v3->unit_id;
    if ((v15 == UNIT_STATS_SURV_RIFLEMAN || v15 == UNIT_STATS_MUTE_SHOTGUNNER || v15 == UNIT_STATS_MUTE_DIRE_WOLF)
        && !(kknd_rand_debug(__FILE__, __LINE__) % 3))
    {
        sprite_408800_play_sound(v2, SOUND_SHOTGUN_FIRE_2, _4690A8_unit_sounds_volume, 0);
    }
    if (!v18)
        v2->z_index = 2048;
    if (v19 == v1->entity_id)
    {
        v16 = v3->stats->accuracy + _465640_accuracy_bonus[v3->_98_465610_accuracy_dmg_bonus_idx];
        if (v16 >= 100)
            v16 = 99;
        if (kknd_rand_debug(__FILE__, __LINE__) % 100 < v16)
            script_trigger_event(a1, EVT_MSG_DAMAGE, v2, v1->script);
    }
    script_445370_yield_to_main_thread(a1, 0x10000000, 0);
    sprite_list_remove(v2);
    --_47C048_unit_bomberdmg;
}

//----- (00437690) --------------------------------------------------------
int sub_437690(Script *a1)
{
    Sprite *v1; // esi@1
    _DWORD *v2; // eax@1
    void *v3; // ebx@1
    int v4; // ebp@1
    __int16 v5; // ax@1
    int v6; // ecx@1
    int v7; // edx@1
    int v8; // eax@1
    int v9; // ebp@1
    int v10; // edi@3
    int v11; // eax@5
    int v12; // ecx@5
    int v13; // ebp@5
    int v14; // edx@5
    int v15; // edi@5
    int v16; // edi@9
    int v18; // [sp+10h] [bp-Ch]@7
    _DWORD *v19; // [sp+14h] [bp-8h]@1
    int v20; // [sp+18h] [bp-4h]@1

    v1 = a1->sprite;
    v2 = (int *)a1->param;
    v19 = (int *)v1->param;
    v3 = v1->parent->param;
    *(_DWORD *)(v2[23] + 136) = 1;
    v4 = v1->y;
    v1->field_88_unused = 1;
    v5 = _42D560_get_mobd_lookup_id_rotation((*(_DWORD *)(v2[23] + 16) - v1->x) >> 8, (*(_DWORD *)(v2[23] + 20) - v4) >> 8);
    v6 = *((_DWORD *)v3 + 38);
    v7 = *((_DWORD *)v3 + 6);
    v20 = v5;
    v8 = *(_DWORD *)(v7 + 40) + _465640_accuracy_bonus[v6];
    v9 = *(_DWORD *)(v7 + 40) + _465640_accuracy_bonus[v6];
    if (v8 >= 100)
        v9 = 99;
    v10 = *(_DWORD *)(v7 + 40) + _465640_accuracy_bonus[v6];
    if (v8 >= 100)
        v10 = 99;
    v11 = kknd_rand_debug(__FILE__, __LINE__);
    v12 = _465640_accuracy_bonus[*((_DWORD *)v3 + 38)];
    v13 = 8 * (v11 % (100 - v9) - (100 - v10) / 2);
    v14 = *(_DWORD *)(*((_DWORD *)v3 + 6) + 40);
    v15 = v12 + v14;
    if (v12 + v14 >= 100)
        v15 = 99;
    v18 = v12 + v14;
    if (v12 + v14 >= 100)
        v18 = 99;
    v16 = 8 * (kknd_rand_debug(__FILE__, __LINE__) % (100 - v15) - (100 - v18) / 2);
    if (v19[4])
    {
        sprite_408800_play_sound(*((Sprite **)v3 + 23), SOUND_LASER_DMG, _4690A8_unit_sounds_volume, 0);
        v1->x_speed = v13 + v19[4] * _4731A8_speeds[__47CFC4_mobd_lookup_speeds[v20 + 1]];
        v1->y_speed = v16 - v19[4] * _4731C8_speeds[__47CFC4_mobd_lookup_speeds[v20 + 1]];
    }
    v1->_60_mobd_field_0_int *= 2;
    script_445370_yield_to_main_thread(a1, 2147483648, 30);
    sprite_list_remove(v1);
    return _47C048_unit_bomberdmg-- - 1;
}
// 47C048: using guessed type int _47C048_unit_bomberdmg;

//----- (00437840) --------------------------------------------------------
void UNIT_DmgHandler_Bow(Script *a1)
{
    Sprite *v1; // esi@1
    Entity *v2; // eax@1
    Entity *v3; // ebp@1
    Sprite *v5; // eax@1
    int v6; // ebx@1
    int v7; // edi@1
    UnitStat *v8; // ecx@1
    int v9; // edx@1
    int v10; // eax@1
    int v11; // ecx@5
    int v12; // edx@5
    int v13; // ecx@9
    int v14; // eax@9
    int v15; // ecx@9
    int v16; // eax@10
    Script *v17; // edi@10
    int v18; // ebx@12
    int v19; // [sp+10h] [bp-18h]@1
    int v20; // [sp+14h] [bp-14h]@1
    int v21; // [sp+14h] [bp-14h]@7
    int v22; // [sp+18h] [bp-10h]@3
    int v23; // [sp+18h] [bp-10h]@5
    int v24; // [sp+1Ch] [bp-Ch]@1
    int v25; // [sp+20h] [bp-8h]@5
    Entity *v26; // [sp+24h] [bp-4h]@1

    v1 = a1->sprite;
    v2 = (Entity *)a1->param;
    v26 = v2;
    v19 = (int)v1->param;
    v3 = (Entity *)v1->parent->param;
    v2->sprite->field_88_unused = 1;
    v1->field_88_unused = 1;
    v5 = v2->sprite;
    v6 = (v5->y - v1->y) >> 8;
    v7 = (v5->x - v1->x) >> 8;
    v24 = (signed __int16)_42D560_get_mobd_lookup_id_rotation(v7, v6);
    sprite_408800_play_sound(v3->sprite, SOUND_89_dmg_handler, _4690A8_unit_sounds_volume, 0);
    v1->drawjob->job_details.palette = per_player_sprite_palettes[player_sprite_color_by_player_side[v3->player_side]];
    v1->drawjob->flags |= 0x10000000u;
    v8 = v3->stats;
    v9 = _465640_accuracy_bonus[v3->_98_465610_accuracy_dmg_bonus_idx];
    v10 = v9 + v8->accuracy;
    v20 = v9 + v8->accuracy;
    if (v10 >= 100)
        v20 = 99;
    v22 = v9 + v8->accuracy;
    if (v10 >= 100)
        v22 = 99;
    v25 = 8 * (kknd_rand_debug(__FILE__, __LINE__) % (100 - v20) - (100 - v22) / 2);
    v11 = _465640_accuracy_bonus[v3->_98_465610_accuracy_dmg_bonus_idx];
    v12 = v3->stats->accuracy;
    v23 = v11 + v12;
    if (v11 + v12 >= 100)
        v23 = 99;
    v21 = v11 + v12;
    if (v11 + v12 >= 100)
        v21 = 99;
    v13 = kknd_rand_debug(__FILE__, __LINE__) % (100 - v23);
    v14 = *(_DWORD *)(v19 + 16);
    v15 = 8 * (v13 - (100 - v21) / 2);
    if (v14)
    {
        v1->x_speed = v25 + v14 * _4731A8_speeds[__47CFC4_mobd_lookup_speeds[v24 + 1]];
        v1->y_speed = v15 - *(_DWORD *)(v19 + 16) * _4731C8_speeds[__47CFC4_mobd_lookup_speeds[v24 + 1]];
        v16 = math_42D64D_prolly_vec_length(v7, v6);
        v17 = a1;
        script_445370_yield_to_main_thread(a1, 0x80000000, v16 / *(_DWORD *)(v19 + 16));
        sprite_408800_play_sound(v1, SOUND_90_dmg_handler, _4690A8_unit_sounds_volume, 0);
    }
    else
    {
        v17 = a1;
    }
    v1->x_speed = 0;
    v1->y_speed = 0;
    v18 = _465640_accuracy_bonus[v3->_98_465610_accuracy_dmg_bonus_idx] + v3->stats->accuracy;
    if (v18 >= 100)
        v18 = 99;
    if (kknd_rand_debug(__FILE__, __LINE__) % 100 < v18 && !v26->destroyed)
        script_trigger_event(v17, EVT_MSG_DAMAGE, v1, v26->script);
    script_445370_yield_to_main_thread(v17, 0x10000000, 0);
    sprite_list_remove(v1);
    --_47C048_unit_bomberdmg;
}

//----- (00437AD0) --------------------------------------------------------
void UNIT_DmgHandler_Projectile(Script *a1)
{
    Sprite *v1; // esi@1
    Entity *v2; // eax@1
    Entity *v3; // edi@1
    int v4; // edx@1
    Sprite *v5; // eax@1
    int v6; // ebp@1
    int v7; // ebx@1
    __int16 v8; // ax@1
    int v9; // ecx@1
    UnitStat *v10; // edx@1
    int v11; // eax@1
    int v12; // ecx@5
    int v13; // edx@5
    int v14; // edi@5
    int v15; // edi@9
    Entity *v16; // eax@9
    int v17; // edi@9
    enum UNIT_ID v18; // ecx@10
    enum SOUND_ID v19; // edx@11
    int v20; // eax@16
    int v21; // ST04_4@20
    enum SOUND_ID v22; // edx@20
    DrawJob *v23; // edx@21
    int v24; // [sp-8h] [bp-2Ch]@11
    int v25; // [sp+10h] [bp-14h]@1
    int v26; // [sp+14h] [bp-10h]@1
    int v27; // [sp+14h] [bp-10h]@5
    int v28; // [sp+18h] [bp-Ch]@3
    int v29; // [sp+18h] [bp-Ch]@7
    Entity *v30; // [sp+1Ch] [bp-8h]@1
    int v31; // [sp+20h] [bp-4h]@1

    v1 = a1->sprite;
    v2 = (Entity *)a1->param;
    v25 = (int)v1->param;
    v3 = (Entity *)v1->parent->param;
    v30 = (Entity *)v1->parent->param;
    v2->sprite->field_88_unused = 1;
    v4 = v1->x;
    v1->field_88_unused = 1;
    v5 = v2->sprite;
    v6 = (v5->y - v1->y) >> 8;
    v7 = (v5->x - v4) >> 8;
    v8 = _42D560_get_mobd_lookup_id_rotation(v7, v6);
    v1->pstru7 = &_479D48_stru7;
    v9 = v3->_98_465610_accuracy_dmg_bonus_idx;
    v10 = v3->stats;
    v31 = v8;
    v11 = v10->accuracy + _465640_accuracy_bonus[v9];
    v26 = v10->accuracy + _465640_accuracy_bonus[v9];
    if (v11 >= 100)
        v26 = 99;
    v28 = v10->accuracy + _465640_accuracy_bonus[v9];
    if (v11 >= 100)
        v28 = 99;
    v27 = 8 * (kknd_rand_debug(__FILE__, __LINE__) % (100 - v26) - (100 - v28) / 2);
    v12 = _465640_accuracy_bonus[v3->_98_465610_accuracy_dmg_bonus_idx];
    v13 = v3->stats->accuracy;
    v14 = v12 + v13;
    if (v12 + v13 >= 100)
        v14 = 99;
    v29 = v12 + v13;
    if (v12 + v13 >= 100)
        v29 = 99;
    v15 = kknd_rand_debug(__FILE__, __LINE__) % (100 - v14) - (100 - v29) / 2;
    v16 = v30;
    v17 = 8 * v15;
    v1->z_index = v30->sprite->z_index + 2560;
    if (*(_DWORD *)(v25 + 16))
    {
        v18 = v30->unit_id;
        if (v18 == UNIT_STATS_MUTE_GIANT_SCORPION)
        {
            v24 = _4690A8_unit_sounds_volume;
            v19 = SOUND_ACID_SPIT_DMG;
        }
        else if (v18 == UNIT_STATS_PLASMA_TANK || v18 == UNIT_STATS_SENTINEL_DROID)
        {
            v24 = _4690A8_unit_sounds_volume;
            v19 = SOUND_LASER_DMG;
        }
        else
        {
            v24 = _4690A8_unit_sounds_volume;
            v19 = SOUND_GENERIC_PROJECTILE_DMG;
        }
        sprite_408800_play_sound(v30->sprite, v19, v24, 0);
        v1->x_speed = v27 + *(_DWORD *)(v25 + 16) * _4731A8_speeds[__47CFC4_mobd_lookup_speeds[v31 + 1]];
        v1->y_speed = v17 - *(_DWORD *)(v25 + 16) * _4731C8_speeds[__47CFC4_mobd_lookup_speeds[v31 + 1]];
        v20 = math_42D64D_prolly_vec_length(v7, v6);
        script_445370_yield_to_main_thread(a1, 0x80000000, v20 / *(_DWORD *)(v25 + 16));
        v16 = v30;
    }
    v1->x_speed = 0;
    v1->y_speed = 0;
    if (*(_DWORD *)(v25 + 12) != -1)
    {
        if (v16->unit_id == UNIT_STATS_MUTE_GIANT_SCORPION)
        {
            sprite_408800_play_sound(v1, SOUND_ACID_SPIT_DMG, _4690A8_unit_sounds_volume, 0);
        }
        else
        {
            v21 = _4690A8_unit_sounds_volume;
            v22 = _46BB80_dmg_handler_sounds[(unsigned __int8)((char)kknd_rand_debug(__FILE__, __LINE__) % -2)];
            sprite_408800_play_sound(v1, v22, v21, 0);
        }
        v1->mobd_id = MOBD_EXPLOSIONS;
        sprite_4272A0_load_mobd_item(v1, *(_DWORD *)(v25 + 12));
        v23 = v1->drawjob;
        v1->_60_mobd_field_0_int = 0x20000000;
        v1->z_index = 0;
        v23->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_4484A0_explosions;
        _4389A0_prolly_create_map_damage_decal(v1->x, v1->y);
        sprite_40D8B0_dmg(v1, *(_DWORD *)(v25 + 32));
    }
    script_445370_yield_to_main_thread(a1, 0x10000000, 0);
    sprite_list_remove(v1);
    --_47C048_unit_bomberdmg;
}