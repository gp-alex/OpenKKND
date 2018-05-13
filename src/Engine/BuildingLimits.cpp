#include "Engine/BuildingLimits.h"

#include "_unsorted_data.h"
#include "_unsorted_functions.h"

#include "Engine/Entity.h"

BuildingLimits *building_limits_list_head = nullptr;
BuildingLimits *building_limits_list_end = nullptr;
BuildingLimits *building_limits_list = nullptr;
BuildingLimits *building_limits_list_free_pool = nullptr;

//----- (00403960) --------------------------------------------------------
int building_limits_list_alloc()
{
    static_assert(sizeof(BuildingLimits) == 0x10);

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
                show_message_ex(0, "You can only build 1 of these");
                return 0;
            }
            if (v1->num_buildings_of_this_type >= 4)
            {
                show_message_ex(0, "You can only build 4 of these");
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
