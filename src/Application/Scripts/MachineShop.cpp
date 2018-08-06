#include "src/kknd.h"
#include "src/_unsorted_data.h"
#include "src/_unsorted_functions.h"
#include "src/ScriptEvent.h"
#include "src/Map.h"

#include "src/Engine/Entity.h"
#include "src/Engine/EntityFactory.h"

using Engine::EntityFactory;



//----- (00421E20) --------------------------------------------------------
bool is_machine_shop_maxed()
{
    return max_machineshop_level >= 5;
}
// 479FEC: using guessed type int max_machineshop_level;

//----- (00421E30) --------------------------------------------------------
void entity_machineshop_on_upgrade_complete(Script *receiver, Script *sender, enum SCRIPT_EVENT message, void *param)
{
    Script *v4; // edi@1
    Script *v5; // ebp@1
    Entity *v6; // esi@1
    EntityBuildingState *v7; // eax@1
    ProductionGroup *v8; // ebx@1
    int v9; // ecx@1
    bool v10; // sf@1
    int v11; // eax@10

    v4 = receiver;
    v5 = sender;
    v6 = (Entity *)receiver->param;
    v7 = (EntityBuildingState *)v6->state;
    v8 = v7->production_group;
    v9 = v7->num_upgrades + 1;
    v10 = v7->num_upgrades - 4 < 0;
    v7->num_upgrades = v9;
    if (!((unsigned __int8)(v10 ^ __OFSUB__(v9, 5)) | (v9 == 5)))
        v7->num_upgrades = 5;
    if (v6->player_side == player_side)
    {
        --__47739C_machineshop_negindex[v7->num_upgrades];
        ++_47739C_machineshop.num_buildings_by_level[v7->num_upgrades];
        if (v7->num_upgrades > max_machineshop_level)
            max_machineshop_level = v7->num_upgrades;
        switch (v7->num_upgrades)
        {
        case 2:
            production_group_enable(v8, UNIT_STATS_SURV_ATV_FLAMETHROWER, 2568);
            break;
        case 3:
            production_group_enable(v8, UNIT_STATS_SURV_ANACONDA_TANK, 2624);
            production_group_enable(v8, UNIT_STATS_SURV_TANKER, 2616);
            break;
        case 4:
            production_group_enable(v8, UNIT_STATS_SURV_BARRAGE_CRAFT, 2560);
            break;
        case 5:
            production_group_enable(v8, UNIT_STATS_SURV_AUTOCANNON_TANK, 2600);
            LOBYTE_HEXRAYS(v11) = is_outpost_maxed();
            if (v11)
                attempt_unlock_aircraft();
            break;
        default:
            break;
        }
    }
    entity_4109A0_status_bar(v6);
    EventHandler_DefaultBuildingsHandler(v4, v5, message, param);
}

//----- (00421F50) --------------------------------------------------------
void EventHandler_MachineShop(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param)
{
    Entity *v4; // esi@1

    v4 = (Entity *)receiver->param;
    if (!v4->destroyed)
    {
        switch (event)
        {
        case EVT_MSG_PRODUCTION_READY:
            v4->sprite->field_88_unused = 1;
            if (spawn_unit(
                (enum UNIT_ID)(int)param,
                v4->stru60.pstru4->x_offset + v4->sprite->x,
                v4->stru60.pstru4->y_offset + v4->sprite->y,
                v4->player_side))
            {
                if (player_side == v4->player_side)
                {
                    sound_play(SOUND_SURV_UNIT_READY, 0, _4690A8_unit_sounds_volume, 16, 0);
                    show_message_ex(0, aUnitReady);
                }
            }
            break;
        case EVT_MSG_UPGRADE_COMPLETE:
            entity_machineshop_on_upgrade_complete(receiver, sender, event, param);
            break;
        case EVT_MSG_SABOTAGE:
            entity_sabotage(v4, param, entity_mode_machineshop_on_death);
            break;
        case EVT_MSG_DESTROY:
            entity_402E40_destroy((Entity *)receiver->param, entity_mode_machineshop_on_death);
            break;
        case CMD_APPLY_DAMAGE:
            entity_402E90_on_damage(v4, param, entity_mode_machineshop_on_death);
            entity_410520_update_healthbar_color(v4);
            break;
        default:
            EventHandler_DefaultBuildingsHandler(receiver, sender, event, param);
            break;
        }
    }
}

//----- (004220B0) --------------------------------------------------------
void entity_4220B0_machineshop(Entity *a1)
{
    Entity *v1; // esi@1
    EntityBuildingState *v2; // edi@1

    v1 = a1;
    v2 = (EntityBuildingState *)a1->state;
    v2->same_buildings_count = 0;
    script_trigger_event_group(a1->script, EVT_MSG_BUILDING_COMPLETE, 0, SCRIPT_SURV_MACHINESHOP_HANDLER);
    if (!v2->same_buildings_count && player_side == v1->player_side)
    {
        max_machineshop_level = 1;
        memset(&_47739C_machineshop, 0, sizeof(_47739C_machineshop));
    }
}
// 479FEC: using guessed type int max_machineshop_level;

//----- (00422100) --------------------------------------------------------
void UNIT_Handler_MachineShop(Script *a1)
{
    Entity *v1; // esi@1
    EntityBuildingState *v2; // edi@3

    v1 = (Entity *)a1->param;
    if (!_47C6DC_dont_execute_unit_handlers)
    {
        if (!v1)
        {
            v1 = EntityFactory().Create(a1);
            v1->script->event_handler = EventHandler_MachineShop;
            map_reveal_fog_around_entity(v1);
            v1->script->script_type = SCRIPT_SURV_MACHINESHOP_HANDLER;
            entity_initialize_building(
                v1,
                2,
                entity_mode_machineshop_on_death_no_default,
                entity_mode_machineshop_set_default_production);
            v2 = (EntityBuildingState *)v1->state;    // -- START OF INLINED entity_404040_production_clanhall -like sub
            v2->same_buildings_count = 0;
            script_trigger_event_group(v1->script, EVT_MSG_BUILDING_COMPLETE, 0, SCRIPT_SURV_MACHINESHOP_HANDLER);
            if (!v2->same_buildings_count && player_side == v1->player_side)
            {
                max_machineshop_level = 1;
                memset(&_47739C_machineshop, 0, sizeof(_47739C_machineshop));
            }                                         // -- END OF INLINED
            if (!v1->sprite->cplc_ptr1_pstru20)
            {
                entity_402BB0_set_arrive_handler(v1, entity_mode_4223A0_machineshop);
                v1->ExecMode();
                return;
            }
            v1->SetMode(entity_mode_4223A0_machineshop);
        }
        v1->ExecMode();
    }
}

//----- (004221D0) --------------------------------------------------------
void entity_mode_machineshop_set_default_production(Entity *a1)
{
    Entity *v1; // esi@1
    enum PLAYER_SIDE v2; // eax@1
    EntityBuildingState *v3; // ebx@1
    ProductionGroup *v4; // eax@9
    ProductionGroup *v5; // esi@9
    enum LEVEL_ID v6; // eax@9
    unsigned int v7; // ecx@9
    unsigned int v8; // edx@11

    v1 = a1;
    v2 = a1->player_side;
    v3 = (EntityBuildingState *)a1->state;
    if (v2 == player_side)
    {
        if (a1->mode_arrive == entity_mode_machineshop_set_default_production)
        {
            v3->same_buildings_count = 0;
            script_trigger_event_group(a1->script, EVT_MSG_BUILDING_COMPLETE, 0, SCRIPT_SURV_MACHINESHOP_HANDLER);
            if (!v3->same_buildings_count && player_side == v1->player_side)
            {
                max_machineshop_level = 1;
                memset(&_47739C_machineshop, 0, sizeof(_47739C_machineshop));
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
        if (!(BYTE1(v7) & 0x40))
        {
            production_group_enable(v5, UNIT_STATS_SURV_DIRT_BIKE, 2592);
            v6 = current_level_idx;
        }
        v8 = levels[v6].disabled_units_mask;
        if (!(BYTE1(v8) & 0x80))
        {
            production_group_enable(v5, UNIT_STATS_SURV_4x4_PICKUP, 2584);
            v6 = current_level_idx;
        }
        if (!(levels[v6].disabled_units_mask & 0x10000))
        {
            production_group_enable(v5, UNIT_STATS_SURV_ATV, 2576);
            v6 = current_level_idx;
        }
        if (!(levels[v6].disabled_units_mask & 0x20000))
            production_group_enable(v5, UNIT_STATS_SURV_MOBILE_DERRICK, 2228);
        ++_47739C_machineshop.num_buildings_by_level[1];
    }
    else if (v2 == 0)
    {
        a1->mode_arrive = entity_mode_machineshop_set_default_production;
    }
}
// 479FEC: using guessed type int max_machineshop_level;

//----- (00422330) --------------------------------------------------------
void entity_mode_machineshop_on_death_no_default(Entity *a1)
{
    EntityBuildingState *v1; // esi@1
    int v2; // edx@2
    int v3; // eax@2
    int *v4; // ecx@5
    int v5; // edx@6
    ProductionGroup *v6; // ecx@9

    v1 = (EntityBuildingState *)a1->state;
    if (player_side == a1->player_side)
    {
        v2 = max_machineshop_level;                 // INLINED recalc new max level
        --_47739C_machineshop.num_buildings_by_level[v1->num_upgrades];
        v3 = v1->num_upgrades;
        if (v3 == v2 && !_47739C_machineshop.num_buildings_by_level[v3])
        {
            if (v3 > 0)
            {
                v4 = &_47739C_machineshop.num_buildings_by_level[v3];
                do
                {
                    v5 = *(v4 - 1);
                    --v4;
                    --v3;
                } while (!v5 && v3 > 0);
            }
            max_machineshop_level = v3;
        }
        v6 = v1->production_group;
        if (v6)
        {
            production_group_446860(v6);
            v1->production_group = 0;
        }
    }
}
// 479FEC: using guessed type int max_machineshop_level;

//----- (004223A0) --------------------------------------------------------
void entity_mode_4223A0_machineshop(Entity *a1)
{
    Entity *v1; // esi@1
    EntityTurret *v2; // eax@5

    v1 = a1;
    a1->mode_arrive = 0;
    entity_mode_machineshop_set_default_production(a1);
    if (player_side == v1->player_side && !v1->sprite->cplc_ptr1_pstru20 && !is_player_faction_evolved())
        sound_play(SOUND_SURV_BUILDING_COMPLETED, 0, _4690A8_unit_sounds_volume, 16, 0);
    v2 = v1->turret;
    if (v2)
        v2->turret_sprite->drawjob->flags &= 0xBFFFFFFF;
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

//----- (00422430) --------------------------------------------------------
void entity_mode_machineshop_on_death(Entity *a1)
{
    Entity *v1; // edi@1
    EntityBuildingState *v2; // esi@1
    int v3; // edx@2
    int v4; // eax@2
    int *v5; // ecx@5
    int v6; // edx@6
    ProductionGroup *v7; // ecx@9

    v1 = a1;
    v2 = (EntityBuildingState *)a1->state;
    if (player_side == a1->player_side)
    {
        v3 = max_machineshop_level;                 // INLINED recalc new max level
        --_47739C_machineshop.num_buildings_by_level[v2->num_upgrades];
        v4 = v2->num_upgrades;
        if (v4 == v3 && !_47739C_machineshop.num_buildings_by_level[v4])
        {
            if (v4 > 0)
            {
                v5 = &_47739C_machineshop.num_buildings_by_level[v4];
                do
                {
                    v6 = *(v5 - 1);
                    --v5;
                    --v4;
                } while (!v6 && v4 > 0);
            }
            max_machineshop_level = v4;
        }
        v7 = v2->production_group;
        if (v7)
        {
            production_group_446860(v7);
            v2->production_group = 0;
        }
    }
    entity_mode_building_on_death_default(v1);
}