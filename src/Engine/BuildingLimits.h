#pragma once

#include "kknd.h"

/* 349 */
struct BuildingLimits
{
    BuildingLimits *next;
    BuildingLimits *prev;
    enum UNIT_ID building_unit_stat_idx;
    int num_buildings_of_this_type;
};

extern BuildingLimits *building_limits_list_head;
extern BuildingLimits *building_limits_list_end;
extern BuildingLimits *building_limits_list;
extern BuildingLimits *building_limits_list_free_pool;