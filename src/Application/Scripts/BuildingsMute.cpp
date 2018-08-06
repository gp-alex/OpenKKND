#include "src/_unsorted_data.h"
#include "src/kknd.h"
#include "src/Script.h"
#include "src/ScriptEvent.h"
#include "src/Sound.h"

#include "src/Engine/Entity.h"
#include "src/Engine/EntityFactory.h"

using Engine::EntityFactory;


//----- (00401E60) --------------------------------------------------------
bool BeastEnclosureAllowsNuke()
{
    return max_beastenclosure_level >= 4;
}
// 47733C: using guessed type int max_beastenclosure_level;

//----- (00401E70) --------------------------------------------------------
void EventHandler_BeastEnclosure(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param)
{
    Script *v4; // edi@1
    Script *v5; // ebx@1
    Entity *v6; // esi@1
    EntityBuildingState *v7; // eax@14
    ProductionGroup *v8; // ecx@14
    int v9; // edx@14
    bool v10; // sf@14
    int tech_level; // eax@19
    int v12; // eax@20
    int v13; // eax@22

    v4 = receiver;
    v5 = sender;
    v6 = (Entity *)receiver->param;
    if (!v6->destroyed)
    {
        switch (event)
        {
        case EVT_MSG_DESTROY:
            entity_402E40_destroy(v6, entity_mode_beastenclosure_on_death);
            return;
        case CMD_APPLY_DAMAGE:
            entity_402E90_on_damage(v6, param, entity_mode_beastenclosure_on_death);
            entity_410520_update_healthbar_color(v6);
            return;
        case EVT_MSG_SABOTAGE:
            entity_sabotage(v6, param, entity_mode_beastenclosure_on_death);
            return;
        case EVT_MSG_PRODUCTION_READY:
            v6->sprite->field_88_unused = 1;
            if (spawn_unit(
                (enum UNIT_ID)(int)param,
                v6->stru60.pstru4->x_offset + v6->sprite->x,
                v6->stru60.pstru4->y_offset + v6->sprite->y,
                v6->player_side)
                && player_side == v6->player_side)
            {
                show_message_ex(0, aUnitReady);
                switch ((int)param)
                {
                case UNIT_STATS_MUTE_DIRE_WOLF:     // Dire Wolf
                    sound_play(SOUND_MUTE_UNIT_DIRE_WOLF_READY, 0, _4690A8_unit_sounds_volume, 16, 0);
                    break;
                case UNIT_STATS_MUTE_GIANT_BEETLE:  // Giant Beetle
                    sound_play(SOUND_MUTE_UNIT_GIANT_BEETLE_READY, 0, _4690A8_unit_sounds_volume, 16, 0);
                    break;
                case UNIT_STATS_MUTE_GIANT_SCORPION:// Giant Scorpion
                    sound_play(SOUND_MUTE_UNIT_GIANT_SCORPION_READY, 0, _4690A8_unit_sounds_volume, 16, 0);
                    break;
                case UNIT_STATS_MUTE_MISSILE_CRAB:  // Missile Crab
                    sound_play(SOUND_MUTE_UNIT_MISSILE_CRAB_READY, 0, _4690A8_unit_sounds_volume, 16, 0);
                    break;
                case UNIT_STATS_MUTE_WAR_MASTADONT: // War Mastadont
                    sound_play(SOUND_MUTE_UNIT_WAR_MASTADONT_READY, 0, _4690A8_unit_sounds_volume, 16, 0);
                    break;
                default:
                    return;
                }
            }
            return;
        case EVT_MSG_UPGRADE_COMPLETE:            // -- INLINED entity_beastclosure_upgrade_complete(a1, a2, message, param)
            v7 = (EntityBuildingState *)v6->state;
            v8 = v7->production_group;
            v9 = v7->num_upgrades + 1;
            v10 = v7->num_upgrades - 3 < 0;
            v7->num_upgrades = v9;
            if (!((unsigned __int8)(v10 ^ __OFSUB__(v9, 4)) | (v9 == 4)))
                v7->num_upgrades = 4;
            if (v6->player_side != player_side)
                goto LABEL_26;
            --__477318_beastenclosure_negindex[v7->num_upgrades];
            ++_477318_beastenclosure.num_buildings_by_level[v7->num_upgrades];
            if (v7->num_upgrades > max_beastenclosure_level)
                max_beastenclosure_level = v7->num_upgrades;
            tech_level = v7->num_upgrades - 2;
            if (tech_level)
            {
                v12 = tech_level - 1;
                if (v12)
                {
                    if (v12 == 1)
                    {
                        production_group_enable(v8, UNIT_STATS_MUTE_MISSILE_CRAB, 2504);
                        LOBYTE_HEXRAYS(v13) = is_clanhall_maxed();
                        if (v13)
                        {
                            attempt_unlock_aircraft();
                            entity_4109A0_status_bar(v6);
                            EventHandler_DefaultBuildingsHandler(v4, v5, event, param);
                            return;
                        }
                    }
                }
                else
                {
                    production_group_enable(v8, UNIT_STATS_MUTE_GIANT_BEETLE, 2512);
                }
            }
            else
            {
                production_group_enable(v8, UNIT_STATS_MUTE_WAR_MASTADONT, 2520);
            }
        LABEL_26:
            entity_4109A0_status_bar(v6);
            EventHandler_DefaultBuildingsHandler(v4, v5, event, param);
            break;
        default:
            EventHandler_DefaultBuildingsHandler(receiver, sender, event, param);
            return;
        }
    }
}

//----- (00402150) --------------------------------------------------------
void entity_402150_beastenclosure(Entity *a1)
{
    EntityBuildingState *v1; // esi@1

    v1 = (EntityBuildingState *)a1->state;
    v1->same_buildings_count = 0;
    script_trigger_event_group(a1->script, EVT_MSG_BUILDING_COMPLETE, 0, SCRIPT_MUTE_BEAST_ENCLOSURE_HANDLER);
    if (!v1->same_buildings_count)
    {
        memset(&_477318_beastenclosure, 0, sizeof(_477318_beastenclosure));
        max_beastenclosure_level = 1;
    }
}
// 47733C: using guessed type int max_beastenclosure_level;

//----- (004021A0) --------------------------------------------------------
void UNIT_Handler_BeastEnclosure(Script *a1)
{
    Entity *v1; // esi@1
    EntityBuildingState *v2; // edi@3

    v1 = (Entity *)a1->param;
    if (!_47C6DC_dont_execute_unit_handlers)
    {
        if (!v1)
        {
            v1 = EntityFactory().Create(a1);
            v1->script->event_handler = EventHandler_BeastEnclosure;
            entity_initialize_building(
                v1,
                2,
                entity_mode_402350_beastenclosure,
                entity_mode_beastenclosure_set_default_production);
            v2 = (EntityBuildingState *)v1->state;
            v2->same_buildings_count = 0;
            script_trigger_event_group(v1->script, EVT_MSG_BUILDING_COMPLETE, 0, SCRIPT_MUTE_BEAST_ENCLOSURE_HANDLER);
            if (!v2->same_buildings_count)
            {
                max_beastenclosure_level = 1;
                memset(&_477318_beastenclosure, 0, sizeof(_477318_beastenclosure));
            }
            if (!v1->sprite->cplc_ptr1_pstru20)
            {
                entity_402BB0_set_arrive_handler(v1, entity_mode_402440_beastenclosure);
                v1->ExecMode();
                return;
            }
            v1->SetMode(entity_mode_402440_beastenclosure);
        }
        v1->ExecMode();
    }
}

//----- (00402250) --------------------------------------------------------
void entity_mode_beastenclosure_set_default_production(Entity *a1)
{
    Entity *v1; // esi@1
    enum PLAYER_SIDE v2; // eax@1
    EntityBuildingState *v3; // ebx@1
    ProductionGroup *v4; // eax@8
    ProductionGroup *v5; // esi@8
    enum LEVEL_ID v6; // eax@8
    unsigned int v7; // edx@8

    v1 = a1;
    v2 = a1->player_side;
    v3 = (EntityBuildingState *)a1->state;
    if (player_side == v2)
    {
        if (a1->mode_arrive == entity_mode_beastenclosure_set_default_production)
        {
            v3->same_buildings_count = 0;
            script_trigger_event_group(a1->script, EVT_MSG_BUILDING_COMPLETE, 0, SCRIPT_MUTE_BEAST_ENCLOSURE_HANDLER);
            if (!v3->same_buildings_count)
            {
                max_beastenclosure_level = 1;
                memset(&_477318_beastenclosure, 0, sizeof(_477318_beastenclosure));
            }
            v1->mode_arrive = 0;
            v1->SetMode(entity_mode_403650_building);
        }
        if (!v1->sprite->cplc_ptr1_pstru20)
            show_message_ex(0, aBuildingCompleted);
        v4 = entity_building_create_production_group(v1, PRODUCTION_GROUP_VEHICLES);
        v5 = v4;
        v3->production_group = v4;
        v6 = current_level_idx;
        v7 = levels[current_level_idx].disabled_units_mask;
        if (!(BYTE1(v7) & 0x80))
        {
            production_group_enable(v5, UNIT_STATS_MUTE_DIRE_WOLF, 2552);
            v6 = current_level_idx;
        }
        if (!(levels[v6].disabled_units_mask & 0x10000))
            production_group_enable(v5, UNIT_STATS_MUTE_GIANT_SCORPION, 2528);
        ++_477318_beastenclosure.num_buildings_by_level[1];
    }
    else if (v2 == 0)
    {
        a1->mode_arrive = entity_mode_beastenclosure_set_default_production;
    }
}
// 47733C: using guessed type int max_beastenclosure_level;

//----- (00402350) --------------------------------------------------------
void entity_mode_402350_beastenclosure(Entity *a1)
{
    void *v1; // esi@1
    int v2; // edx@2
    int v3; // eax@2
    char *v4; // ecx@5
    int v5; // edx@6
    ProductionGroup *v6; // ecx@9

    v1 = a1->state;
    if (player_side == a1->player_side)
    {
        v2 = max_beastenclosure_level;
        --_477318_beastenclosure.num_buildings_by_level[*((_DWORD *)v1 + 1)];
        v3 = *((_DWORD *)v1 + 1);
        if (v3 == v2 && !_477318_beastenclosure.num_buildings_by_level[v3])
        {
            if (v3 > 0)
            {
                v4 = (char *)& _477318_beastenclosure + 4 * v3;
                do
                {
                    v5 = *((_DWORD *)v4 - 1);
                    v4 -= 4;
                    --v3;
                } while (!v5 && v3 > 0);
            }
            max_beastenclosure_level = v3;
        }
        v6 = (ProductionGroup *)*((_DWORD *)v1 + 4);
        if (v6)
        {
            production_group_446860(v6);
            *((_DWORD *)v1 + 4) = 0;
        }
    }
}
// 47733C: using guessed type int max_beastenclosure_level;

//----- (004023C0) --------------------------------------------------------
void entity_mode_beastenclosure_on_death(Entity *a1)
{
    Entity *v1; // edi@1
    void *v2; // esi@1
    int v3; // edx@2
    int v4; // eax@2
    char *v5; // ecx@5
    int v6; // edx@6
    ProductionGroup *v7; // ecx@9

    v1 = a1;
    v2 = a1->state;
    if (player_side == a1->player_side)
    {
        v3 = max_beastenclosure_level;
        --_477318_beastenclosure.num_buildings_by_level[*((_DWORD *)v2 + 1)];
        v4 = *((_DWORD *)v2 + 1);
        if (v4 == v3 && !_477318_beastenclosure.num_buildings_by_level[v4])
        {
            if (v4 > 0)
            {
                v5 = (char *)& _477318_beastenclosure + 4 * v4;
                do
                {
                    v6 = *((_DWORD *)v5 - 1);
                    v5 -= 4;
                    --v4;
                } while (!v6 && v4 > 0);
            }
            max_beastenclosure_level = v4;
        }
        v7 = (ProductionGroup *)*((_DWORD *)v2 + 4);
        if (v7)
        {
            production_group_446860(v7);
            *((_DWORD *)v2 + 4) = 0;
        }
    }
    entity_mode_building_on_death_default(v1);
}
// 47733C: using guessed type int max_beastenclosure_level;

//----- (00402440) --------------------------------------------------------
void entity_mode_402440_beastenclosure(Entity *a1)
{
    Entity *v1; // esi@1
    EntityTurret *v2; // eax@1

    v1 = a1;
    a1->mode_arrive = 0;
    entity_mode_beastenclosure_set_default_production(a1);
    v2 = v1->turret;
    if (v2)
        v2->turret_sprite->drawjob->flags &= 0xBFFFFFFF;
    if (player_side == v1->player_side && !v1->sprite->cplc_ptr1_pstru20)
        sound_play(SOUND_MUTE_BUILDING_COMPLETED, 0, _4690A8_unit_sounds_volume, 16, 0);
    v1->script->event_handler = EventHandler_BeastEnclosure;
    v1->script->script_type = SCRIPT_MUTE_BEAST_ENCLOSURE_HANDLER;
    if (v1->sprite->cplc_ptr1_pstru20)
    {
        v1->SetMode(entity_mode_4034B0);
    }
    else
    {
        v1->SetMode(entity_mode_403650_building);
    }
    entity_mode_403650_building(v1);
}

//----- (004024D0) --------------------------------------------------------
void entity_blacksmith_on_upgrade_complete(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param)
{
    Script *v4; // edi@1
    Script *v5; // ebx@1
    Entity *v6; // esi@1
    EntityBuildingState *v7; // eax@1
    ProductionGroup *v8; // ecx@1
    int v9; // edx@1
    bool v10; // sf@1
    int v11; // eax@4

    v4 = receiver;
    v5 = sender;
    v6 = (Entity *)receiver->param;
    v7 = (EntityBuildingState *)v6->state;
    v8 = v7->production_group;
    v9 = v7->num_upgrades + 1;
    v10 = v7->num_upgrades - 2 < 0;
    v7->num_upgrades = v9;
    if (!((unsigned __int8)(v10 ^ __OFSUB__(v9, 3)) | (v9 == 3)))
        v7->num_upgrades = 3;
    if (v6->player_side == player_side)
    {
        v11 = v7->num_upgrades - 2;
        if (v11)
        {
            if (v11 == 1)
                production_group_enable(v8, UNIT_STATS_MUTE_TANKER, 2608);
        }
        else
        {
            production_group_enable(v8, UNIT_STATS_MONSTER_TRUCK, 2536);
        }
    }
    entity_4109A0_status_bar(v6);
    EventHandler_DefaultBuildingsHandler(v4, v5, event, param);
}

//----- (00402550) --------------------------------------------------------
void MessageHandler_Blacksmith(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param)
{
    Script *v4; // edi@1
    Script *v5; // ebx@1
    void *v6; // esi@1
    EntityBuildingState *v7; // eax@9
    ProductionGroup *v8; // ecx@9
    int v9; // edx@9
    bool v10; // sf@9
    int v11; // eax@12

    v4 = receiver;
    v5 = sender;
    v6 = receiver->param;
    if (!*((_DWORD *)v6 + 35))
    {
        switch (event)
        {
        case EVT_MSG_DESTROY:
            entity_402E40_destroy((Entity *)v6, entity_mode_blacksmith_on_death);
            break;
        case CMD_APPLY_DAMAGE:
            entity_402E90_on_damage((Entity *)v6, param, entity_mode_blacksmith_on_death);
            entity_410520_update_healthbar_color((Entity *)v6);
            break;
        case EVT_MSG_SABOTAGE:
            entity_sabotage((Entity *)v6, param, entity_mode_blacksmith_on_death);
            break;
        case EVT_MSG_PRODUCTION_READY:
            *(_DWORD *)(*((_DWORD *)v6 + 23) + 136) = 1;
            if (spawn_unit(
                (enum UNIT_ID)(int)param,
                *(_DWORD *)(*((_DWORD *)v6 + 25) + 4) + *(_DWORD *)(*((_DWORD *)v6 + 23) + 16),
                *(_DWORD *)(*((_DWORD *)v6 + 25) + 8) + *(_DWORD *)(*((_DWORD *)v6 + 23) + 20),
                *((enum PLAYER_SIDE *)v6 + 5)))
            {
                if (player_side == *((_DWORD *)v6 + 5))
                {
                    sound_play(SOUND_MUTE_UNIT_READY, 0, _4690A8_unit_sounds_volume, 16, 0);
                    show_message_ex(0, aUnitReady);
                }
            }
            break;
        case EVT_MSG_UPGRADE_COMPLETE:
            v7 = (EntityBuildingState *)*((_DWORD *)v6 + 8);
            v8 = v7->production_group;
            v9 = v7->num_upgrades + 1;
            v10 = v7->num_upgrades - 2 < 0;
            v7->num_upgrades = v9;
            if (!((unsigned __int8)(v10 ^ __OFSUB__(v9, 3)) | (v9 == 3)))
                v7->num_upgrades = 3;
            if (*((_DWORD *)v6 + 5) == player_side)
            {
                v11 = v7->num_upgrades - 2;
                if (v11)
                {
                    if (v11 == 1)
                        production_group_enable(v8, UNIT_STATS_MUTE_TANKER, 2608);
                }
                else
                {
                    production_group_enable(v8, UNIT_STATS_MONSTER_TRUCK, 2536);
                }
            }
            entity_4109A0_status_bar((Entity *)v6);
            EventHandler_DefaultBuildingsHandler(v4, v5, event, param);
            break;
        default:
            EventHandler_DefaultBuildingsHandler(receiver, sender, event, param);
            break;
        }
    }
}

//----- (00402710) --------------------------------------------------------
void UNIT_Handler_Blacksmith(Script *a1)
{
    Entity *v1; // esi@1

    v1 = (Entity *)a1->param;
    if (!_47C6DC_dont_execute_unit_handlers)
    {
        if (!v1)
        {
            v1 = EntityFactory().Create(a1);
            v1->script->event_handler = MessageHandler_Blacksmith;
            entity_initialize_building(v1, 2, entity_mode_402840_blacksmith, entity_mode_402780_blacksmith);
            if (!v1->sprite->cplc_ptr1_pstru20)
            {
                entity_402BB0_set_arrive_handler(v1, entity_mode_402870_blacksmith);
                v1->ExecMode();
                return;
            }
            v1->SetMode(entity_mode_402870_blacksmith);
        }
        v1->ExecMode();
    }
}
// 47C6DC: using guessed type int _47C6DC_dont_execute_unit_handlers;

//----- (00402780) --------------------------------------------------------
void entity_mode_402780_blacksmith(Entity *a1)
{
    Entity *v1; // esi@1
    enum PLAYER_SIDE v2; // eax@1
    EntityBuildingState *v3; // edi@1
    ProductionGroup *v4; // eax@6
    ProductionGroup *v5; // esi@6
    enum LEVEL_ID v6; // eax@6
    unsigned int v7; // edx@6

    v1 = a1;
    v2 = a1->player_side;
    v3 = (EntityBuildingState *)a1->state;
    if (player_side == v2)
    {
        if (a1->mode_arrive == entity_mode_402780_blacksmith)
        {
            a1->mode_arrive = 0;
            a1->SetMode(entity_mode_403650_building);
        }
        if (!a1->sprite->cplc_ptr1_pstru20)
            show_message_ex(0, aBuildingCompleted);
        v4 = entity_building_create_production_group(v1, PRODUCTION_GROUP_VEHICLES);
        v5 = v4;
        v3->production_group = v4;
        v6 = current_level_idx;
        v7 = levels[current_level_idx].disabled_units_mask;
        if (!(BYTE1(v7) & 0x40))
        {
            production_group_enable(v5, UNIT_STATS_MUTE_BIKE_AND_SIDECAR, 2544);
            v6 = current_level_idx;
        }
        if (!(levels[v6].disabled_units_mask & 0x20000))
            production_group_enable(v5, UNIT_STATS_MUTE_MOBILE_DERRICK, 2220);
    }
    else if (v2 == 0)
    {
        a1->mode_arrive = entity_mode_402780_blacksmith;
    }
}

//----- (00402840) --------------------------------------------------------
void entity_mode_402840_blacksmith(Entity *a1)
{
    void *v1; // esi@1
    ProductionGroup *v2; // ecx@2

    v1 = a1->state;
    if (player_side == a1->player_side)
    {
        v2 = (ProductionGroup *)*((_DWORD *)v1 + 4);
        if (v2)
        {
            production_group_446860(v2);
            *((_DWORD *)v1 + 4) = 0;
        }
    }
}

//----- (00402870) --------------------------------------------------------
void entity_mode_402870_blacksmith(Entity *a1)
{
    Entity *v1; // esi@1
    EntityTurret *v2; // eax@1

    v1 = a1;
    a1->mode_arrive = 0;
    entity_mode_402780_blacksmith(a1);
    v2 = v1->turret;
    if (v2)
        v2->turret_sprite->drawjob->flags &= 0xBFFFFFFF;
    if (player_side == v1->player_side && !v1->sprite->cplc_ptr1_pstru20)
        sound_play(SOUND_MUTE_BUILDING_COMPLETED, 0, _4690A8_unit_sounds_volume, 16, 0);
    v1->script->script_type = SCRIPT_MUTE_BLACKSMITH_HANDLER;
    if (v1->sprite->cplc_ptr1_pstru20)
    {
        v1->SetMode(entity_mode_4034B0);
    }
    else
    {
        v1->SetMode(entity_mode_403650_building);
    }
    entity_mode_403650_building(v1);
}

//----- (00402900) --------------------------------------------------------
void entity_mode_blacksmith_on_death(Entity *a1)
{
    entity_mode_building_on_death_default(a1);
}