#include "Engine/EntityFactory.h"

#include "_unsorted_data.h"
#include "kknd.h"
#include "ScriptEvent.h"

//----- (0044C6B0) --------------------------------------------------------
Entity *entity_list_create(Script *a1)
{
    Entity *v1; // esi@1
    Sprite *v2; // edx@1
    DataCplcItem_ptr1 *v4; // eax@6
    int v5; // eax@7
    unsigned __int16 v6; // ax@11
    enum PLAYER_SIDE v7; // eax@13
    void *v8; // eax@14
    int v9; // eax@15
    enum PLAYER_SIDE v10; // eax@18
    Entity *v13; // ecx@22

    v1 = entity_list_get();
    v2 = a1->sprite;
    if (!v1)
        return 0;

    memset(v1, 0, sizeof(Entity));
    v4 = v2->cplc_ptr1;
    if (v4)
    {
        v5 = v4->script_handler_id;
        if (v5 != 4 && v5 != 5 && v5 != 2 && v5 != 3)// Prison, Prison, Outpost, Clannhall
        {
            v1->unit_id = scripts[v5]->stats_idx;
            v1->player_side = (PLAYER_SIDE)v2->cplc_ptr1_pstru20->field_18;
            v6 = v2->cplc_ptr1_pstru20->_1C_oilspot_oil_units__or__param;
            v1->_12C_prison_bunker_spawn_type = v6;
            if (v6)
                v1->field_124 |= 0x80u;
        }
        else
        {
            v1->unit_id = (UNIT_ID)scripts[v5][1].script_type;
            v7 = (PLAYER_SIDE)v2->cplc_ptr1_pstru20->field_24;
            v1->player_side = v7;
        }
    }
    else
    {
        v8 = v2->param;
        if (BYTE1(v8) & 0x80)
        {
            v9 = v1->field_124;
            v1->_12C_prison_bunker_spawn_type = 2;
            v1->field_124 = v9 | 0x80;
        }
        v1->unit_id = (UNIT_ID)((unsigned int)v2->param & 0x7FFF);
        v7 = (PLAYER_SIDE)((int)v2->param >> 16);
        v1->player_side = v7;
    }

    v10 = v1->player_side;
    if (v10 == player_side)
    {
        ++UNIT_num_player_units;
    }
    else if (v10)
    {
        ++UNIT_num_nonplayer_units;
    }
    v1->field_110 = 0;
    v1->stru11_list_108 = (stru11unit *)&v1->stru11_list_104;
    v1->field_94 = 0;
    v1->stru11_list_104 = (stru11unit *)&v1->stru11_list_104;
    v1->_98_465610_accuracy_dmg_bonus_idx = 0;
    v1->entity_id = ++_47DCC4_entity_id_counter;
    v1->mode = 0;
    v1->mode_idle = 0;
    v1->mode_arrive = 0;
    v1->mode_attacked = 0;
    v1->sprite = v2;
    v1->script = a1;
    a1->script_type = SCRIPT_TYPE_60138_ENTITY_SCRIPTS;
    a1->param = v1;
    a1->event_handler = MessageHandler_EntityScript;
    v2->param = v1;
    v1->stats = &unit_stats[v1->unit_id];
    v1->current_mobd_lookup_idx = 128;
    v1->hitpoints = v1->stats->hitpoints;
    v1->field_78 = 0;

    memset32(&v1->stru60, (int)&entity_default_stru60_ptr, 6u);

    v2->drawjob->job_details.palette = per_player_sprite_palettes[player_sprite_color_by_player_side[v1->player_side]];
    v2->drawjob->flags |= 0x10000000u;

    script_trigger_event_group(a1, EVT_MSG_1521_entity_created, v1, SCRIPT_TYPE_39030);

    v13 = entity_list_head;
    v1->prev = (Entity *)&entity_list_head;
    v1->next = v13;
    entity_list_head->prev = v1;
    entity_list_head = v1;
    return v1;
}
