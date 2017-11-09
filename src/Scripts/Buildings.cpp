#include "src/kknd.h"

#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"

#include "src/Random.h"
#include "src/Script.h"
#include "src/ScriptEvent.h"
#include "src/Entity.h"



//----- (00402F30) --------------------------------------------------------
void EventHandler_DefaultBuildingsHandler(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param)
{
    void *v4; // ebp@1
    void *v5; // esi@1
    Script *v6; // ST00_4@14
    int v7; // eax@24
    int v8; // ecx@24
    int v9; // edx@24
    int v10; // eax@24
    enum SOUND_ID v11; // ecx@27
    int v12; // [sp-Ch] [bp-18h]@27
    enum PLAYER_SIDE v13; // [sp-4h] [bp-10h]@24

    v4 = 0;
    v5 = receiver->param;
    if (sender)
        v4 = sender->param;
    if (!*((_DWORD *)v5 + 35))
    {
        if (*((void(**)(Entity *))v5 + 16) != entity_mode_402AB0 || event != EVT_MSG_1529_ai)
        {
            switch (0)
            {
            case EVT_MSG_DESTROY:
                if (*((_DWORD *)v5 + 36) > 0)
                {
                    v6 = (Script *)*((_DWORD *)v5 + 3);
                    *((_DWORD *)v5 + 36) = 0;
                    script_445370_yield_to_main_thread(v6, 0x80000000, 1);
                    *((_DWORD *)v5 + 36) = 0;
                    *((_DWORD *)v5 + 16) = (_DWORD)entity_mode_building_default_on_death;
                    *((_DWORD *)v5 + 35) = 1;
                }
                break;
            case EVT_MSG_1507_stru11:
                entity_41A850_evt1507_mess_with_stru11((Entity *)receiver->param, param);
                break;
            case EVT_MSG_1509_stru11:
                entity_41A980_evt1509_unset_stru11((Entity *)receiver->param, param);
                break;
            case EVT_MSG_1497:
                entity_41A6D0_evt1497((Entity *)receiver->param, (Entity *)param);
                if (player_side == *((_DWORD *)v5 + 5) && !*((_DWORD *)v5 + 75))
                {
                    *((_DWORD *)v5 + 75) = 2000;
                    if (is_player_faction_evolved())
                        sound_play(SOUND_129, 0, _4690A8_unit_sounds_volume, 16, 0);
                    else
                        sound_play(SOUND_20, 0, _4690A8_unit_sounds_volume, 16, 0);
                }
                break;
            case EVT_MSG_SABOTAGE:
                entity_sabotage((Entity *)v5, param, entity_mode_building_default_on_death);
                break;
            case EVT_MSG_DAMAGE:
                entity_402E90_on_damage((Entity *)v5, param, entity_mode_building_default_on_death);
                entity_410520_update_healthbar_color((Entity *)v5);
                break;
            case EVT_MSG_PRODUCTION_READY:          // unit_stats_idx
                *(_DWORD *)(*((_DWORD *)v5 + 23) + 136) = 1;
                v7 = *((_DWORD *)v5 + 25);
                v8 = *((_DWORD *)v5 + 23);
                v9 = *(_DWORD *)(v8 + 16) + *(_DWORD *)(v7 + 4);
                v10 = *(_DWORD *)(v8 + 20) + *(_DWORD *)(v7 + 8);
                v13 = (PLAYER_SIDE)*((_DWORD *)v5 + 5);
                if (v13 == player_side)
                {
                    if (spawn_unit((enum UNIT_ID)(int)param, v9, v10, v13))
                    {
                        if (is_player_faction_evolved())
                        {
                            v12 = _4690A8_unit_sounds_volume;
                            v11 = SOUND_MUTE_UNIT_READY;
                        }
                        else
                        {
                            v12 = _4690A8_unit_sounds_volume;
                            v11 = SOUND_SURV_UNIT_READY;
                        }
                        sound_play(v11, 0, v12, 16, 0);
                        show_message_ex(0, aUnitReady);
                    }
                    else
                    {
                        show_message_ex(0, aCouldntCreateNewUnit);
                    }
                }
                else
                {
                    spawn_unit((enum UNIT_ID)(int)param, v9, v10, v13);
                }
                break;
            case EVT_MSG_BUILDING_COMPLETE:
                if (sender != receiver && *((_DWORD *)v4 + 5) == *((_DWORD *)v5 + 5))
                    script_trigger_event(receiver, EVT_MSG_COUNT_BUILDINGS_OF_THE_SAME_TYPE, 0, sender);
                break;
            case EVT_MSG_COUNT_BUILDINGS_OF_THE_SAME_TYPE:
                ++*(_WORD *)(*((_DWORD *)v5 + 8) + 12);
                break;
            case EVT_MSG_1511_sidebar_click_category:
                entity_410CB0_event1511((Entity *)receiver->param);
                break;
            case EVT_SHOW_UI_CONTROL:
                entity_410CD0_eventTextString((Entity *)receiver->param);
                break;
            case EVT_MSG_SHOW_UNIT_HINT:
                entity_show_hint((Entity *)receiver->param);
                break;
            default:
                return;
            }
        }
        else if (param == (void *)1)
        {
            sprite_4272E0_load_mobd_item(*((Sprite **)v5 + 23), *(_DWORD *)(*((_DWORD *)v5 + 6) + 52), 1);
        }
        else if (param == (void *)2)
        {
            sprite_4272E0_load_mobd_item(*((Sprite **)v5 + 23), *(_DWORD *)(*((_DWORD *)v5 + 6) + 52), 2);
        }
        else if ((char *)param - 2 == (_BYTE *)1)
        {
            *((_DWORD *)v5 + 16) = *((_DWORD *)v5 + 18);
        }
    }
}

//----- (00403230) --------------------------------------------------------
void script_403230_building_mini_explosion(Script *a1)
{
    Sprite *v1; // esi@1
    __int16 v2; // ax@1
    int v3; // edx@1

    v1 = a1->sprite;
    v1->pstru7 = &_479D48_stru7;
    sprite_408800_play_sound(v1, SOUND_3, _4690A8_unit_sounds_volume, 0);
    v1->field_88_unused = 1;
    v2 = kknd_rand_debug(__FILE__, __LINE__);
    v3 = v1->x;
    v1->field_88_unused = 1;
    v1->x = (v2 & 0x3FFF) - 0x2000 + v3;
    v1->y += (kknd_rand_debug(__FILE__, __LINE__) & 0x3FFF) - 0x2000;
    sprite_load_mobd(v1, SPRITE_EXPLOSION_MOBD_OFFSET_SMALL);
    v1->z_index = 0x4000;
    script_445370_yield_to_main_thread(a1, 0x10000000, 0);
    decrease_num_explosions();
    sprite_list_remove(v1);
    script_yield(a1);
}

//----- (004032F0) --------------------------------------------------------
void script_4032F0_building_grand_explosion(Script *a1)
{
    Sprite *v1; // esi@1
    int v2; // ecx@1

    v1 = a1->sprite;
    v1->pstru7 = &_479D48_stru7;
    script_445370_yield_to_main_thread(a1, 0x80000000, 130);
    sprite_408800_play_sound(v1, SOUND_3, _4690A8_unit_sounds_volume, 0);
    sprite_load_mobd(v1, SPRITE_EXPLOSION_MOBD_OFFSET_BIG);
    v2 = v1->y + 2048;
    v1->field_88_unused = 1;
    v1->y = v2;
    v1->_60_mobd_field_0_int = 0x20000000;
    script_445370_yield_to_main_thread(a1, 0x10000000, 0);
    decrease_num_explosions();
    sprite_list_remove(v1);
    script_yield(a1);
}

//----- (00403380) --------------------------------------------------------
void script_403380_explosions(Script *a1)
{
    Sprite *v1; // esi@1
    int v2; // edi@1
    Script *v3; // ebx@1
    int v4; // ebp@3
    char v5; // al@7
    int v6; // eax@8
    Sprite *v7; // eax@12
    int v8; // ecx@12
    int v9; // esi@12
    int v10; // edi@12
    int v11; // eax@12
    int v12; // ebp@13
    int v13; // [sp+10h] [bp-4h]@12
    int a1a; // [sp+18h] [bp+4h]@12

    v1 = 0;
    v2 = 0;
    v3 = a1;
    if (_438B50_can_create_more_explosions())
        v1 = sprite_create_scripted(MOBD_EXPLOSIONS, a1->sprite, script_4032F0_building_grand_explosion, SCRIPT_COROUTINE, 0);
    v4 = 8;
    do
    {
        if (_438B50_can_create_more_explosions())
        {
            v1 = sprite_create_scripted(MOBD_EXPLOSIONS, a1->sprite, script_403230_building_mini_explosion, SCRIPT_COROUTINE, 0);
            if (v1)
                v1->z_index = a1->sprite->z_index + 0x20000000;
        }
        v5 = kknd_rand_debug(__FILE__, __LINE__);
        v2 += v5 & 0x1F;
        script_445370_yield_to_main_thread(a1, 0x80000000, v5 & 0x1F);
        --v4;
    } while (v4);
    v6 = 120 - v2;
    if (120 - v2 < 0)
        v6 = 0;
    script_445370_yield_to_main_thread(a1, 0x80000000, v6);
    if (v1)
        v1->z_index = a1->sprite->z_index + 1024;
    a1->sprite->field_88_unused = 1;
    v7 = a1->sprite;
    v8 = v7->x;
    v9 = v7->y;
    v13 = v7->y;
    v10 = v8 - 0x2000;
    v11 = v8 + 0x2000;
    a1a = v8 + 0x2000;
    if (v8 - 0x2000 <= v8 + 0x2000)
    {
        v12 = v9 + 0x2000;
        do
        {
            if (v9 <= v12)
            {
                do
                {
                    _4389A0_prolly_create_map_damage_decal(v10, v9);
                    v9 += 0x2000;
                } while (v9 <= v12);
                v11 = a1a;
                v9 = v13;
            }
            v10 += 0x2000;
        } while (v10 <= v11);
    }
    decrease_num_explosions();
    sprite_list_remove(v3->sprite);
    script_yield(v3);
}

//----- (004034B0) --------------------------------------------------------
void entity_mode_4034B0(Entity *a1)
{
    Entity *v1; // esi@1
    Script *v2; // eax@1

    v1 = a1;
    a1->sprite->field_88_unused = 1;
    a1->sprite->field_88_unused = 1;
    a1->sprite->x = ((a1->stru60.ptr_C->x_offset + a1->sprite->x) & 0xFFFFE000) - a1->stru60.ptr_C->x_offset + 4096;
    a1->sprite->field_88_unused = 1;
    a1->sprite->y = ((a1->stru60.ptr_C->y_offset + a1->sprite->y) & 0xFFFFE000) - a1->stru60.ptr_C->y_offset + 4096;
    entity_40DD00_boxd(a1);
    v2 = v1->script;
    v1->mode = entity_mode_403650_building;
    script_445370_yield_to_main_thread(v2, 0x80000000, 1);
}

//----- (00403540) --------------------------------------------------------
void entity_mode_403540(Entity *a1)
{
    Entity *v1; // esi@1

    v1 = a1;
    if (entity_425820_find(a1, 76800))
    {
        sound_play(SOUND_MobileOutpost_ClanhallWagon_Planted, 0, _4690A8_unit_sounds_volume, 16, 0);
        entity_4258C0_init_palettes_inc_unit_counter(v1, player_side);
        building_limits_on_new_building(v1->unit_id);
        entity_410BE0_status_bar(v1);
        script_trigger_event_group(v1->script, EVT_MSG_1521_entity_created, v1, SCRIPT_TYPE_39030);
        v1->mode = v1->mode_arrive;
    }
    script_445370_yield_to_main_thread(v1->script, 0x80000000, 1);
}

//----- (004035C0) --------------------------------------------------------
void entity_mode_4035C0_building(Entity *a1)
{
    Entity *v1; // esi@1
    Script *v2; // eax@1

    v1 = a1;
    a1->sprite->field_88_unused = 1;
    a1->sprite->field_88_unused = 1;
    a1->sprite->x = ((a1->stru60.ptr_C->x_offset + a1->sprite->x) & 0xFFFFE000) - a1->stru60.ptr_C->x_offset + 4096;
    a1->sprite->field_88_unused = 1;
    a1->sprite->y = ((a1->stru60.ptr_C->y_offset + a1->sprite->y) & 0xFFFFE000) - a1->stru60.ptr_C->y_offset + 4096;
    entity_40DD00_boxd(a1);
    v2 = v1->script;
    v1->mode = entity_mode_403540;
    script_445370_yield_to_main_thread(v2, 0x80000000, 1);
}

//----- (00403650) --------------------------------------------------------
void entity_mode_403650_building(Entity *a1)
{
    Entity *v1; // esi@1
    UnitStat *v2; // ecx@4
    int v3; // edx@5
    int v4; // eax@9

    v1 = a1;
    if (a1->script->script_type == 0xCA00000E)
        entity_410B00_building_status_bar(a1);
    if (v1->player_side)
    {
        v2 = v1->stats;
        if (v1->hitpoints >= v2->hitpoints / 3 || (v3 = v2->mobd_lookup_offset_4, v3 == -1))
            entity_load_mobd_3(v1);
        else
            entity_load_mobd_4(v1);
    }
    else
    {
        entity_load_mobd_3(v1);
        v1->mode = entity_mode_4035C0_building;
    }
    v4 = v1->_12C_prison_bunker_spawn_type;
    if (v4 <= 0)
        v1->_12C_prison_bunker_spawn_type = 0;
    else
        v1->_12C_prison_bunker_spawn_type = v4 - 1;
    script_445370_yield_to_main_thread(v1->script, 0x80000000, 1);
}

//----- (00403720) --------------------------------------------------------
void entity_mode_403720_on_prison_death__or__prolly_any_generic_building(Entity *a1)
{
    Entity *v1; // esi@1
    enum SOUND_ID v2; // ecx@3
    int v3; // [sp-Ch] [bp-10h]@3

    v1 = a1;
    if (a1->player_side == player_side)
    {
        if (is_player_faction_evolved())
        {
            v2 = SOUND_101;
            v3 = _4690A8_unit_sounds_volume;
        }
        else
        {
            v3 = _4690A8_unit_sounds_volume;
            v2 = SOUND_23;
        }
        sound_play(v2, 0, v3, 16, 0);
    }
    entity_40DDD0_boxd(v1);
    sprite_list_remove(v1->sprite);
    script_yield(v1->script);
    entity_list_remove(v1);
}

//----- (00403780) --------------------------------------------------------
void entity_mode_building_default_on_death(Entity *a1)
{
    Entity *v1; // esi@1
    EntityBuildingState *v2; // edi@2
    ProductionGroup *v3; // ecx@2
    Script *v4; // eax@5
    EntityTurret *v5; // eax@5
    Script *v6; // ecx@7
    Script *v7; // ecx@9
    Sprite *v8; // eax@11
    Script *v9; // edx@11

    v1 = a1;
    entity_439120_add_explosion(a1);
    sub_4083D0();
    if (v1->player_side == player_side)
    {
        v2 = (EntityBuildingState *)v1->state;
        v3 = v2->production_group;
        if (v3)
        {
            production_group_446860(v3);
            v2->production_group = 0;
        }
        building_limits_on_building_destroyed(v1);
    }
    v4 = v1->script;
    v1->destroyed = 1;
    v1->state = 0;
    v4->field_24 &= 0xEFFFFFFF;
    v5 = v1->turret;
    if (v5)
    {
        v5->turret_sprite->param = 0;
        sprite_list_remove(v1->turret->turret_sprite);
        script_deinit(v1->turret->sprite_task);
        script_free_local_object(v1->script, v1->turret);
    }
    script_trigger_event(v1->script, EVT_SHOW_UI_CONTROL, 0u, task_mobd17_cursor);
    script_trigger_event_group(v1->script, EVT_SHOW_UI_CONTROL, v1, SCRIPT_TYPE_39030);
    v6 = v1->script;
    if (v6->script_type == SCRIPT_POWER_STATION_HANDLER)
        script_trigger_event_group(v6, EVT_MSG_1539, v1, SCRIPT_TANKER_CONVOY_HANDLER);
    v7 = v1->script;
    if (v7->script_type == SCRIPT_DRILLRIG_HANDLER)
        script_trigger_event_group(v7, EVT_MSG_1540, v1, SCRIPT_TANKER_CONVOY_HANDLER);
    v1->script->script_type = SCRIPT_TYPE_INVALID;
    v8 = v1->sprite;
    v1->entity_id = 0;
    v8->x_speed = 0;
    v1->sprite->y_speed = 0;
    entity_439150_add_explosion(v1);
    entity_438D90_on_death_explosion(v1);
    v9 = v1->script;
    v1->mode = entity_mode_403720_on_prison_death__or__prolly_any_generic_building;
    script_445370_yield_to_main_thread(v9, 0x80000000, 165);
}

//----- (004038B0) --------------------------------------------------------
void entity_4038B0(Entity *a1, enum PLAYER_SIDE side)
{
    Entity *v2; // esi@1
    enum PLAYER_SIDE v3; // edi@1
    void(*v4)(Entity *); // eax@2
    Sprite *v5; // edx@4
    EntityTurret *v6; // eax@4
    void(*v7)(Entity *); // eax@7

    v2 = a1;
    v3 = side;
    if (a1->player_side == player_side)
    {
        v4 = a1->mode_turn_return;
        if (v4)
        {
            (v4)(a1);
            --UNIT_num_player_units;
            ++UNIT_num_nonplayer_units;
        }
    }
    v5 = v2->sprite;
    v2->player_side = v3;
    v5->drawjob->job_details.palette = per_player_sprite_palettes[player_sprite_color_by_player_side[v3]];
    v6 = v2->turret;
    if (v6)
        v6->turret_sprite->drawjob->job_details.palette = per_player_sprite_palettes[player_sprite_color_by_player_side[v3]];
    if (v2->player_side == player_side)
    {
        entity_44B100_buildings__mess_with_fog_of_war(v2);
        ++UNIT_num_player_units;
        --UNIT_num_nonplayer_units;
        v7 = v2->mode_return;
        if (v7)
        {
            v2->mode_arrive = v7;
            (v7)(v2);
        }
    }
}

//----- (00403960) --------------------------------------------------------
int building_limits_list_alloc()
{
    building_limits_list = new BuildingLimits[20];
    if (building_limits_list)
    {
        building_limits_list_free_pool = building_limits_list;
        building_limits_list[19].next = nullptr;

        for (int i = 0; i < 20; ++i)
        {
            building_limits_list[i].next = &building_limits_list[i + 1];
        }

        building_limits_list_head = (BuildingLimits *)&building_limits_list_head;
        building_limits_list_end = (BuildingLimits *)&building_limits_list_head;
        return true;
    }
    return false;
}

//----- (004039C0) --------------------------------------------------------
int building_limits_count(enum UNIT_ID unit_stats_idx)
{
    BuildingLimits *v1; // eax@1
    int result; // eax@4

    v1 = building_limits_list_head;
    if ((BuildingLimits **)building_limits_list_head == &building_limits_list_head)
    {
        result = 0;
    }
    else
    {
        while (v1->building_unit_stat_idx != unit_stats_idx)
        {
            v1 = v1->next;
            if ((BuildingLimits **)v1 == &building_limits_list_head)
                return 0;
        }
        result = v1->num_buildings_of_this_type;
    }
    return result;
}

//----- (004039F0) --------------------------------------------------------
bool building_limits_can_build(enum UNIT_ID unit_id)
{
    BuildingLimits *v1; // eax@3

    if (unit_id != UNIT_STATS_SURV_DRILL_RIG && unit_id != UNIT_STATS_MUTE_DRILL_RIG)
    {
        v1 = building_limits_list_head;
        if ((BuildingLimits **)building_limits_list_head != &building_limits_list_head)
        {
            while (v1->building_unit_stat_idx != unit_id)
            {
                v1 = v1->next;
                if ((BuildingLimits **)v1 == &building_limits_list_head)
                    return 1;
            }
            if (unit_id == UNIT_STATS_SURV_RESEARCH_LAB || unit_id == UNIT_STATS_MUTE_ALCHEMY_HALL)
            {
                show_message_ex(0, aYouCanOnlyBuild1OfThese);
                return 0;
            }
            if (v1->num_buildings_of_this_type >= 4)
            {
                show_message_ex(0, aYouCanOnlyBuild4OfThese);
                return 0;
            }
        }
    }
    return 1;
}

//----- (00403A50) --------------------------------------------------------
int building_limits_on_new_building(enum UNIT_ID stats_idx)
{
    BuildingLimits *v1; // eax@3
    BuildingLimits *v2; // eax@6
    BuildingLimits *v3; // ecx@9

    if (stats_idx == 46 || stats_idx == 47)
        return 1;
    v1 = building_limits_list_head;
    if ((BuildingLimits **)building_limits_list_head == &building_limits_list_head)
    {
    LABEL_6:
        v2 = building_limits_list_free_pool;
        if (building_limits_list_free_pool)
            building_limits_list_free_pool = building_limits_list_free_pool->next;
        else
            v2 = 0;
        v2->num_buildings_of_this_type = 1;
        v2->building_unit_stat_idx = stats_idx;
        v3 = building_limits_list_head;
        v2->prev = (BuildingLimits *)&building_limits_list_head;
        v2->next = v3;
        building_limits_list_head->prev = v2;
        building_limits_list_head = v2;
        return 1;
    }
    while (v1->building_unit_stat_idx != stats_idx)
    {
        v1 = v1->next;
        if ((BuildingLimits **)v1 == &building_limits_list_head)
            goto LABEL_6;
    }
    ++v1->num_buildings_of_this_type;
    return 1;
}

//----- (00403AD0) --------------------------------------------------------
void building_limits_on_building_destroyed(Entity *a1)
{
    enum UNIT_ID v1; // esi@1
    BuildingLimits *v2; // eax@3
    int v3; // edx@5

    v1 = a1->unit_id;
    if (v1 != 46 && v1 != 47)
    {
        v2 = building_limits_list_head;
        if ((BuildingLimits **)building_limits_list_head != &building_limits_list_head)
        {
            while (1)
            {
                if (v2->building_unit_stat_idx == v1)
                {
                    v3 = v2->num_buildings_of_this_type - 1;
                    v2->num_buildings_of_this_type = v3;
                    if (!v3)
                        break;
                }
                v2 = v2->next;
                if ((BuildingLimits **)v2 == &building_limits_list_head)
                    goto LABEL_9;
            }
            v2->next->prev = v2->prev;
            v2->prev->next = v2->next;
            v2->next = building_limits_list_free_pool;
            building_limits_list_free_pool = v2;
        }
    LABEL_9:
        if ((BuildingLimits **)building_limits_list_head == &building_limits_list_head && a1->player_side == player_side)
        {
            nullsub_1();
            if (sub_44CA50(v1))
                _4318E0_free_building_production();
            else
                _4318E0_free_building_production();
        }
    }
}

//----- (00403B60) --------------------------------------------------------
void building_limits_list_free()
{
    free(building_limits_list);
}
