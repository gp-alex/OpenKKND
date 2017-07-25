#include "src/kknd.h"

#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"

#include "src/Entity.h"
#include "src/Script.h"

Entity *entity_list_end()
{
    return (Entity *)&entity_list_head;
}



bool entity_is_tower(Entity *entity)
{
    return entity->unit_id >= UNIT_STATS_SURV_GUARD_TOWER && entity->unit_id <= UNIT_STATS_MUTE_ROTARY_CANNON;
}

bool entity_is_moveable(Entity *entity)
{
    return entity->unit_id <= UNIT_STATS_MUTE_MISSILE_CRAB || entity->unit_id >= UNIT_STATS_GORT;

}

bool entity_is_attacker(Entity *entity)
{
    return
        entity_is_moveable(entity)
        && (entity->unit_id < UNIT_STATS_SURV_MOBILE_DERRICK || entity->unit_id > UNIT_STATS_TANKER_CONVOY)
        && (entity->unit_id < UNIT_STATS_SURV_TECHNICIAN || entity->unit_id > UNIT_STATS_MUTE_MEKANIK)
        || entity_is_tower(entity);
}



bool is_21st_century(UNIT_ID unit_id)
{
    return unit_id >= UNIT_STATS_GORT && unit_id <= UNIT_STATS_MECH;
}

bool entity_is_21st_century(Entity *entity)
{
    return is_21st_century(entity->unit_id);
}