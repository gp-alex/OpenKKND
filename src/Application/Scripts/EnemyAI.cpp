#include "src/kknd.h"
#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"
#include "src/Random.h"
#include "src/Script.h"
#include "src/ScriptEvent.h"
#include "src/Pathfind.h"
#include "src/Map.h"

#include "src/Engine/Entity.h"


//----- (004089B0) --------------------------------------------------------
void EventHandler_4089B0_generic_ai(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param)
{
    stru24 *v4; // esi@1
    void *v5; // ebp@3
    stru24_EnemyNode *l; // edi@8
    stru24_EnemyNode *v7; // eax@10
    stru24_EnemyNode *v8; // eax@13
    stru24_EnemyNode *v9; // edx@17
    enum PLAYER_SIDE v10; // eax@20
    stru24_stru94 *v11; // eax@23
    stru24_stru94 *v12; // ecx@24
    int v13; // eax@27
    int v14; // edi@29
    int v15; // ecx@30
    int v16; // ecx@31
    stru24_stru26C *v17; // eax@32
    stru24_stru26C *v18; // edx@33
    int v19; // ecx@36
    int v20; // eax@42
    int v21; // eax@43
    int v22; // ecx@43
    int v23; // ecx@44
    int v24; // ecx@46
    int v25; // ecx@47
    int v26; // ecx@49
    int v27; // ecx@50
    int v28; // ecx@52
    int v29; // ecx@53
    int v30; // ecx@55
    int v31; // ecx@56
    int v32; // ecx@58
    int v33; // ecx@59
    int v34; // ecx@61
    int v35; // ecx@62
    int v36; // eax@64
    int v37; // eax@65
    stru24_stru160 *v38; // eax@70
    int v39; // eax@74
    stru24_OilTankerNode *v40; // eax@82
    stru24_DrillRigNode *v41; // eax@88
    stru24 *v42; // ecx@94
    stru24_PowerPlantNode *v43; // edi@96
    int v44; // eax@103
    stru24_WandererNode *v45; // eax@107
    stru24_WandererNode *v46; // edx@111
    stru24_AttackerNode *v47; // eax@113
    bool v48; // zf@119
    enum PLAYER_SIDE v49; // eax@119
    stru24_EnemyNode *v50; // edi@120
    stru24_stru160 *k; // eax@121
    stru24_stru94 *v52; // ebx@128
    stru24_OilTankerNode *v53; // edi@137
    stru24_DrillRigNode *v54; // eax@141
    stru24_stru160 *v55; // edx@142
    stru24_DrillRigNode *v56; // ecx@144
    stru24_OilTankerNode *v57; // edx@146
    stru24_OilTankerNode *v58; // eax@146
    stru24_OilTankerNode *v59; // ecx@147
    stru24_stru310 *v60; // eax@149
    stru24_stru310 *v61; // esi@156
    int v62; // edx@156
    stru24_PowerPlantNode *v63; // ebx@157
    stru24 *i; // eax@160
    int v65; // ecx@165
    stru24_stru40 *v66; // edi@169
    stru24_AttackerNode *v67; // eax@172
    stru24_stru160 *v68; // ecx@174
    stru24_stru160 *j; // ecx@176
    stru24 *a3a; // [sp+14h] [bp+4h]@24

    v4 = (stru24 *)receiver->param;
    if (event == EVT_MSG_DESELECTED)
    {
        v48 = is_enemy(v4->_2A0_player_side, (Entity *)param) == 0;
        v49 = v4->_2A0_player_side;
        if (v48)
        {
            if (*((_DWORD *)param + 5) == v49)
            {
                switch (*((_DWORD *)param + 4))
                {
                case UNIT_STATS_SURV_OUTPOST:         // Outpost
                case UNIT_STATS_MUTE_CLANHALL:        // Clanhall
                case UNIT_STATS_SURV_MACHINE_SHOP:    // Machine Shop
                case UNIT_STATS_MUTE_BLACKSMITH:      // Blacksmith
                case UNIT_STATS_MUTE_BEAST_ENCLOSURE: // Beast Enclosure
                    v52 = (stru24_stru94 *)*((_DWORD *)param + v49 + 9);
                    if ((Script *)*((_DWORD *)param + 3) == v4->task)
                    {
                        v4->task = 0;
                        stru38_list_427FD0(&v4->field_34C, 0);
                        v4->field_34C = 0;
                    }
                    if (v52)
                    {
                        if (v52->_C_cost)
                        {
                            stru38_list_427FD0(&v52->_C_cost, 0);
                            v52->_C_cost = 0;
                        }
                        v52->next->prev = v52->prev;
                        v52->prev->next = (stru24 *)v52->next;
                        v52->next = v4->list_94_head;
                        v4->list_94_head = v52;
                        stru24_4095B0(v4, (Entity *)param);
                    }
                    break;
                case UNIT_STATS_SURV_GUARD_TOWER:     // Guard Tower
                case UNIT_STATS_MUTE_MACHINEGUN_NEST: // Machinegun Nest
                case UNIT_STATS_SURV_CANNON_TOWER:    // Cannon Tower
                case UNIT_STATS_MUTE_GRAPESHOT_TOWER: // Grapeshot Tower
                case UNIT_STATS_SURV_MISSILE_BATTERY: // Missile Battery
                case UNIT_STATS_MUTE_ROTARY_CANNON:   // Rotary Cannon
                    if ((Script *)*((_DWORD *)param + 3) == v4->task)
                    {
                        v4->task = 0;
                        stru38_list_427FD0(&v4->field_34C, 0);
                        v4->field_34C = 0;
                    }
                    stru24_4095B0(v4, (Entity *)param);
                    break;
                case UNIT_STATS_SURV_TANKER:          // Oil Tanker
                case UNIT_STATS_MUTE_TANKER:          // Oil Tanker
                    v53 = (stru24_OilTankerNode *)*((_DWORD *)param + v49 + 9);
                    if (v53)
                    {
                        if (v53->drillrig_node)
                        {
                            v53->next->prev = v53->prev;
                            v53->prev->next = v53->next;
                            --v53->drillrig_node->field_30;
                            v53->next = v4->tanker_list_free_pool;
                            v4->tanker_list_free_pool = v53;
                        }
                        else
                        {
                            v53->next->prev = v53->prev;
                            v53->prev->next = v53->next;
                            v53->next = v4->tanker_list_free_pool;
                            v4->tanker_list_free_pool = v53;
                        }
                    }
                    break;
                case UNIT_STATS_SURV_DRILL_RIG:       // Drill Rig
                case UNIT_STATS_MUTE_DRILL_RIG:       // Drill Rig
                    v54 = (stru24_DrillRigNode *)*((_DWORD *)param + v49 + 9);
                    if (v54)
                    {
                        v55 = v54->pstru24_stru160;
                        if (v55)
                        {
                            v55->next = v4->list_11C;
                            v54->pstru24_stru160->prev = (stru24_stru160 *)&v4->list_11C;
                            v4->list_11C->prev = v54->pstru24_stru160;
                            v4->list_11C = v54->pstru24_stru160;
                        }
                        v54->next->prev = v54->prev;
                        v54->prev->next = v54->next;
                        v54->next = v4->drill_rig_list_free_pool;
                        v56 = v4->_2E8_drillrig_node;
                        v4->drill_rig_list_free_pool = v54;
                        if (v56 == v54)
                            v4->_2E8_drillrig_node = 0;
                        v57 = (stru24_OilTankerNode *)&v54->_8_next;
                        v58 = v54->_8_next;
                        if (v58 != v57)
                        {
                            v59 = (stru24_OilTankerNode *)&v4->tanker_list_DC;
                            do
                            {
                                v58->next->prev = v58->prev;
                                v58->prev->next = v58->next;
                                v58->drillrig_node = 0;
                                v58->next = v59->next;
                                v58->prev = v59;
                                v59->next->prev = v58;
                                v59->next = v58;
                                v58 = v57->next;
                            } while (v57->next != v57);
                        }
                        v60 = v4->list_310_head;
                        if (v60)
                            v4->list_310_head = v60->next;
                        else
                            v60 = 0;
                        if (v60)
                        {
                            v60->field_8 = 0;
                            if (*(_DWORD *)(*((_DWORD *)param + 6) + 80) == 2)
                                v60->unit_id = UNIT_STATS_MUTE_MOBILE_DERRICK;
                            else
                                v60->unit_id = UNIT_STATS_SURV_MOBILE_DERRICK;
                            v61 = (stru24_stru310 *)&v4->list_318;
                            *(_DWORD *)(*((_DWORD *)param + 23) + 136) = 1;
                            v60->x = *(_DWORD *)(*((_DWORD *)param + 23) + 16);
                            v62 = *(_DWORD *)(*((_DWORD *)param + 23) + 20);
                            v60->_20_ai_importance = 0;
                            v60->y = v62;
                            v60->next = v61->next;
                            v60->prev = v61;
                            v61->next->prev = v60;
                            v61->next = v60;
                        }
                    }
                    break;
                case UNIT_STATS_SURV_POWER_STATION:   // Power Station
                case UNIT_STATS_MUTE_POWER_STATION:   // Power Station
                    v63 = (stru24_PowerPlantNode *)*((_DWORD *)param + v49 + 9);
                    if ((Script *)*((_DWORD *)param + 3) == v4->task)
                    {
                        v4->task = 0;
                        stru38_list_427FD0(&v4->field_34C, 0);
                        v4->field_34C = 0;
                    }
                    if (v63)
                    {
                        for (i = (stru24 *)v4->drill_rig_list_9C; (stru24_DrillRigNode **)i != &v4->drill_rig_list_9C; i = i->next)
                        {
                            if ((stru24_PowerPlantNode *)i->wanderer_list == v63)
                                i->wanderer_list = 0;
                        }
                        v63->next->prev = v63->prev;
                        v63->prev->next = v63->next;
                        v63->next = v4->power_plant_list_free_pool;
                        v4->power_plant_list_free_pool = v63;
                        stru24_4095B0(v4, (Entity *)param);
                        stru24_409650(v4);
                    }
                    break;
                default:
                    v65 = *((_DWORD *)param + 6);
                    if (*(_DWORD *)(v65 + 20) > 0 && (*(_DWORD *)(v65 + 68) || *(_DWORD *)(v65 + 72)))
                    {
                        if (*((_BYTE *)param + 292) & 0x80)
                        {
                            v66 = (stru24_stru40 *)*((_DWORD *)param + v49 + 9);
                            if (v66)
                            {
                                v66->next->prev = v66->prev;
                                v66->prev->next = v66->next;
                                v66->next = v4->list_40_head;
                                v4->list_40_head = v66;
                            }
                            else
                            {
                                show_message_ex(0, aWarningUnregis);
                            }
                        }
                        else
                        {
                            v67 = (stru24_AttackerNode *)*((_DWORD *)param + v49 + 9);
                            if (v67)
                            {
                                if (v67->list_8)
                                {
                                    v67->next->prev = v67->prev;
                                    v67->prev->next = v67->next;
                                    v67->list_8->_2C_ai_importance -= v67->entity->stats->_54_ai_importance;
                                    v68 = v67->list_8;
                                    if (v68 != v4->field_24C && v68->_C_next == &v68->_C_next)
                                    {
                                        for (j = v4->list_1B4; (stru24_stru160 **)j != &v4->list_1B4; j = j->next)
                                        {
                                            if (j->field_8 == v67->list_8)
                                                j->field_8 = 0;
                                        }
                                        v67->list_8->next->prev = v67->list_8->prev;
                                        v67->list_8->prev->next = v67->list_8->next;
                                        v67->list_8->next = v4->list_160_head;
                                        v4->list_160_head = v67->list_8;
                                    }
                                }
                                else
                                {
                                    v67->next->prev = v67->prev;
                                    v67->prev->next = v67->next;
                                }
                                v67->next = v4->attacker_list_free_pool;
                                v4->attacker_list_free_pool = v67;
                                --v4->field_2AC;
                            }
                        }
                    }
                    break;
                }
            }
        }
        else
        {
            v50 = (stru24_EnemyNode *)*((_DWORD *)param + v49 + 9);
            if (v50)
            {
                for (k = v4->list_11C; (stru24_stru160 **)k != &v4->list_11C; k = k->next)
                {
                    if (k->field_24 == v50)
                        k->field_24 = 0;
                }
                v50->next->prev = v50->prev;
                v50->prev->next = v50->next;
                v50->next = v4->enemy_list_free_pool;
                v4->enemy_list_free_pool = v50;
            }
        }
    }
    else if (event == EVT_MSG_1521_entity_created)
    {
        v5 = param;
        if (is_enemy(v4->_2A0_player_side, (Entity *)param))
        {
            if (*(_DWORD *)(*((_DWORD *)param + 6) + 80) != v4->_2A4_player_side
                || (int)current_level_idx >= 48 && (int)current_level_idx <= 67
                || _47C6D8_use__466098_cost_multipliers)
            {
                v8 = v4->enemy_list_free_pool;
                if (v8)
                    v4->enemy_list_free_pool = v8->next;
                else
                    v8 = 0;
                if (v8)
                {
                    *((_DWORD *)param + v4->_2A0_player_side + 9) = (int)v8;
                    v8->entity = (Entity *)param;
                    v9 = v4->enemy_list_108;
                    v8->prev = (stru24_EnemyNode *)&v4->enemy_list_108;
                    v8->next = v9;
                    v4->enemy_list_108->prev = v8;
                    v4->enemy_list_108 = v8;
                }
                else
                {
                    show_message_ex(0, aWarningOutOfEnemyNodes);
                }
            }
            else
            {
                game_globals_cpu[0].cash[7 * v4->_2A0_player_side + *((_DWORD *)param + 5)] = 1;
                for (l = v4->enemy_list_108; (stru24_EnemyNode **)l != &v4->enemy_list_108; l = l->next)
                {
                    if (!is_enemy(v4->_2A0_player_side, l->entity))
                    {
                        v7 = l->prev;
                        l->next->prev = v7;
                        l->prev->next = l->next;
                        l->next = v4->enemy_list_free_pool;
                        v4->enemy_list_free_pool = l;
                        l = v7;
                    }
                }
            }
        }
        else if (*((_DWORD *)param + 5) == v4->_2A0_player_side)
        {
            v10 = (PLAYER_SIDE)*(_DWORD *)(*((_DWORD *)param + 6) + 80);
            if (v10)
                v4->_2A4_player_side = v10;
            switch (*((_DWORD *)param + 4))
            {
            case UNIT_STATS_SURV_OUTPOST:           // Outpost
            case UNIT_STATS_MUTE_CLANHALL:          // Clanhall
            case UNIT_STATS_SURV_MACHINE_SHOP:      // Machine Shop
            case UNIT_STATS_MUTE_BLACKSMITH:        // Blacksmith
            case UNIT_STATS_MUTE_BEAST_ENCLOSURE:   // Beast Enclosure
                v11 = v4->list_94_head;
                if (v11)
                {
                    v12 = v4->list_94_head;
                    a3a = (stru24 *)v4->list_94_head;
                    v4->list_94_head = v11->next;
                }
                else
                {
                    a3a = 0;
                    v12 = 0;
                }
                if (v12)
                {
                    *((_DWORD *)param + v4->_2A0_player_side + 9) = (int)v12;
                    v12->_8_entity = (Entity *)param;
                    v12->_C_cost = 0;
                    v13 = *((_DWORD *)param + 4);
                    if (v13 == 59 || v13 == 58)       // Outpost & Clanhall
                    {
                        v14 = *(_DWORD *)(*((_DWORD *)param + 23) + 112);
                        if (v14)
                        {
                            v15 = *(_DWORD *)(v14 + 20);
                            if (v15)
                            {
                                v16 = v15 + 32;
                                if (v16)
                                {
                                    v17 = (stru24_stru26C *)&v4->list_260;
                                    do
                                    {
                                        v18 = v4->list_26C_head;
                                        if (v18)
                                        {
                                            v4->ptr_274 = v18;
                                            v4->list_26C_head = v4->list_26C_head->next;
                                        }
                                        else
                                        {
                                            v4->ptr_274 = 0;
                                        }
                                        v4->ptr_274->field_8 = *(_DWORD *)(v16 + 24);
                                        v4->ptr_274->next = v17->next;
                                        v4->ptr_274->prev = v17;
                                        v17->next->prev = v4->ptr_274;
                                        v17->next = v4->ptr_274;
                                        v19 = *(_DWORD *)(v16 + 20);
                                        if (v19)
                                            v16 = v19 + 32;
                                        else
                                            v16 = 0;
                                    } while (v16);
                                    v5 = param;
                                }
                                v4->ptr_274 = v4->list_260;
                            }
                            v20 = *(_DWORD *)(v14 + 28);
                            if (v20)
                            {
                                v4->_278_x_offset = *(_DWORD *)(v20 + 4);
                                v4->_27C_y_offset = *(_DWORD *)(*(_DWORD *)(v14 + 28) + 8);
                                v21 = *(_DWORD *)(v14 + 28) + 32;
                                v22 = *(_DWORD *)(*(_DWORD *)(v14 + 28) + 52);
                                if (v22)
                                    v23 = *(_DWORD *)(v22 + 4);
                                else
                                    v23 = -1;
                                v4->field_280[0][0] = v23;
                                v24 = *(_DWORD *)(v21 + 20);
                                if (v24)
                                    v25 = *(_DWORD *)(v24 + 8);
                                else
                                    v25 = -1;
                                v4->field_280[0][1] = v25;
                                v26 = *(_DWORD *)(v21 + 24);
                                if (v26)
                                    v27 = *(_DWORD *)(v26 + 4);
                                else
                                    v27 = -1;
                                v4->field_280[0][2] = v27;
                                v28 = *(_DWORD *)(v21 + 24);
                                if (v28)
                                    v29 = *(_DWORD *)(v28 + 8);
                                else
                                    v29 = -1;
                                v4->field_280[0][3] = v29;
                                v30 = *(_DWORD *)(v21 + 28);
                                if (v30)
                                    v31 = *(_DWORD *)(v30 + 4);
                                else
                                    v31 = -1;
                                v4->field_280[1][0] = v31;
                                v32 = *(_DWORD *)(v21 + 28);
                                if (v32)
                                    v33 = *(_DWORD *)(v32 + 8);
                                else
                                    v33 = -1;
                                v4->field_280[1][1] = v33;
                                v34 = *(_DWORD *)(v21 + 32);
                                if (v34)
                                    v35 = *(_DWORD *)(v34 + 4);
                                else
                                    v35 = -1;
                                v4->field_280[1][2] = v35;
                                v36 = *(_DWORD *)(v21 + 32);
                                if (v36)
                                    v37 = *(_DWORD *)(v36 + 8);
                                else
                                    v37 = -1;
                                v4->field_280[1][3] = v37;
                            }
                            if (!v4->field_24C && v4->_278_x_offset != -1)
                            {
                                v38 = v4->list_160_head;
                                if (v38)
                                {
                                    v4->field_24C = v38;
                                    v4->list_160_head = v38->next;
                                }
                                else
                                {
                                    v4->field_24C = 0;
                                }
                                v4->field_24C->_C_next = &v4->field_24C->_C_next;
                                v4->field_24C->_10_prev = &v4->field_24C->_C_next;
                                v4->field_24C->field_1C = 0;
                                v4->field_24C->field_8 = 0;
                                v4->field_24C->x_offset = v4->_278_x_offset;
                                v4->field_24C->y_offset = v4->_27C_y_offset;
                                v4->field_24C->field_24 = 0;
                                v4->field_24C->_2C_ai_importance = 0;
                                v4->field_24C->field_30 = 0;
                            }
                            v39 = *((_DWORD *)v5 + 4);
                            if (v39 == UNIT_STATS_MUTE_CLANHALL)
                            {
                                v4->_2DC_unit_id = UNIT_STATS_MUTE_TANKER;
                                v4->_2E0_unit_id = UNIT_STATS_MUTE_BLACKSMITH;
                            }
                            else if (v39 == UNIT_STATS_SURV_OUTPOST)
                            {
                                v4->_2DC_unit_id = UNIT_STATS_SURV_TANKER;
                                v4->_2E0_unit_id = UNIT_STATS_SURV_MACHINE_SHOP;
                            }
                        }
                    }
                    stru24_409540(v4, *((Sprite **)v5 + 23));
                    a3a->next = (stru24 *)v4->list_94_78;
                    a3a->prev = (stru24 *)((char *)v4 + 120);
                    v4->list_94_78->prev = a3a;
                    v4->list_94_78 = (stru24_stru94 *)a3a;
                }
                else
                {
                    show_message_ex(0, aWarningOutOfBu);
                }
                break;
            case UNIT_STATS_MUTE_TANKER:
                v4->_2DC_unit_id = UNIT_STATS_MUTE_TANKER;
                v4->_2E0_unit_id = UNIT_STATS_MUTE_BLACKSMITH;
                goto LABEL_82;
            case UNIT_STATS_SURV_TANKER:
                v4->_2DC_unit_id = UNIT_STATS_SURV_TANKER;
                v4->_2E0_unit_id = UNIT_STATS_SURV_MACHINE_SHOP;
            LABEL_82:
                v40 = v4->tanker_list_free_pool;
                if (v40)
                    v4->tanker_list_free_pool = v40->next;
                else
                    v40 = 0;
                if (v40)
                {
                    *((_DWORD *)param + v4->_2A0_player_side + 9) = (int)v40;
                    v40->entity = (Entity *)param;
                    v40->drillrig_node = 0;
                    v40->next = v4->tanker_list_DC;
                    v40->prev = (stru24_OilTankerNode *)&v4->tanker_list_DC;
                    v4->tanker_list_DC->prev = v40;
                    v4->tanker_list_DC = v40;
                    v4->field_2E4 = 0;
                }
                else
                {
                    show_message_ex(0, aWarningOutOfTa);
                    v4->field_2E4 = 0;
                }
                break;
            case UNIT_STATS_SURV_DRILL_RIG:
            case UNIT_STATS_MUTE_DRILL_RIG:
                v41 = v4->drill_rig_list_free_pool;
                if (v41)
                    v4->drill_rig_list_free_pool = v41->next;
                else
                    v41 = 0;
                if (v41)
                {
                    *((_DWORD *)param + v4->_2A0_player_side + 9) = (int)v41;
                    v41->_8_next = (stru24_OilTankerNode *)&v41->_8_next;
                    v41->_C_prev = (stru24_OilTankerNode *)&v41->_8_next;
                    v41->entity = (Entity *)param;
                    v41->field_18 = 0;
                    v41->pstru24_stru160 = 0;
                    v41->ptr_28 = 0;
                    v41->field_2C = 0;
                    v41->field_30 = 0;
                    v41->field_34 = 0;
                    v41->next = v4->drill_rig_list_9C;
                    v41->prev = (stru24_DrillRigNode *)&v4->drill_rig_list_9C;
                    v4->drill_rig_list_9C->prev = v41;
                    v4->drill_rig_list_9C = v41;
                    stru24_409650(v4);
                }
                else
                {
                    show_message_ex(0, aWarningOutOfDr);
                }
                break;
            case UNIT_STATS_SURV_MOBILE_DERRICK:    // Mobile Derrick
            case UNIT_STATS_MUTE_MOBILE_DERRICK:    // Mobile Derrick
                v42 = (stru24 *)v4->list_318;
                if ((stru24_stru310 **)v42 != &v4->list_318)
                    v42->_8_entity = (Entity *)param;
                break;
            case UNIT_STATS_SURV_POWER_STATION:     // Power Station
            case UNIT_STATS_MUTE_POWER_STATION:     // Power Station
                v43 = v4->power_plant_list_free_pool;
                if (v43)
                    v4->power_plant_list_free_pool = v43->next;
                else
                    v43 = 0;
                if (v43)
                {
                    *((_DWORD *)param + v4->_2A0_player_side + 9) = (int)v43;
                    v43->entity = (Entity *)param;
                    stru24_409540(v4, *((Sprite **)param + 23));
                    v43->next = v4->power_plant_list_F4;
                    v43->prev = (stru24_PowerPlantNode *)&v4->power_plant_list_F4;
                    v4->power_plant_list_F4->prev = v43;
                    v4->power_plant_list_F4 = v43;
                    stru24_409650(v4);
                }
                else
                {
                    show_message_ex(0, aWarningOutOfPo);
                }
                break;
            case UNIT_STATS_SURV_REPAIR_BAY:
            case UNIT_STATS_MUTE_MENAGERIE:
            case UNIT_STATS_SURV_RESEARCH_LAB:
            case UNIT_STATS_MUTE_ALCHEMY_HALL:
                stru24_409540(v4, *((Sprite **)param + 23));
                break;
            default:
                v44 = *((_DWORD *)param + 6);
                if (*(_DWORD *)(v44 + 20) > 0 && (*(_DWORD *)(v44 + 68) || *(_DWORD *)(v44 + 72)))
                {
                    if (*((_DWORD *)param + 75))
                    {
                        v45 = v4->wanderer_list_free_pool;
                        if (v45)
                            v4->wanderer_list_free_pool = v45->next;
                        else
                            v45 = 0;
                        if (v45)
                        {
                            *((_DWORD *)param + v4->_2A0_player_side + 9) = (int)v45;
                            v45->entity = (Entity *)param;
                            v46 = v4->wanderer_list_18;
                            v45->prev = (stru24_WandererNode *)&v4->wanderer_list_18;
                            v45->next = v46;
                            v4->wanderer_list_18->prev = v45;
                            v4->wanderer_list_18 = v45;
                        }
                        else
                        {
                            show_message_ex(0, aWarningOutOfWa);
                        }
                    }
                    else
                    {
                        v47 = v4->attacker_list_free_pool;
                        if (v47)
                            v4->attacker_list_free_pool = v47->next;
                        else
                            v47 = 0;
                        if (v47)
                        {
                            *((_DWORD *)param + v4->_2A0_player_side + 9) = (int)v47;
                            v47->entity = (Entity *)param;
                            v47->list_8 = 0;
                            v47->next = v4->attacker_list_48;
                            v47->prev = (stru24_AttackerNode *)&v4->attacker_list_48;
                            v4->attacker_list_48->prev = v47;
                            v4->attacker_list_48 = v47;
                            ++v4->field_2AC;
                        }
                        else
                        {
                            show_message_ex(0, "Warning: out of attacker nodes");
                        }
                    }
                }
                break;
            }
        }
    }
}

//----- (00409540) --------------------------------------------------------
int stru24_409540(stru24 *a1, Sprite *a2)
{
    int v2; // eax@1
    int v3; // eax@3
    int v4; // eax@5
    int v5; // edx@7
    int result; // eax@7

    v2 = a2->x;
    a2->field_88_unused = 1;
    if (v2 < a1->field_250)
    {
        a2->field_88_unused = 1;
        a1->field_250 = v2;
    }
    v3 = a2->x;
    a2->field_88_unused = 1;
    if (v3 > a1->field_258)
    {
        a2->field_88_unused = 1;
        a1->field_258 = v3;
    }
    v4 = a2->y;
    if (v4 < a1->field_254)
        a1->field_254 = v4;
    v5 = a2->y;
    result = a1->field_25C;
    if (v5 > result)
        a1->field_25C = v5;
    return result;
}

//----- (004095B0) --------------------------------------------------------
stru24_stru310 *stru24_4095B0(stru24 *a1, Entity *a2)
{
    stru24_stru310 *result; // eax@1
    stru24_stru310 *v3; // esi@5
    char *v4; // edx@5
    stru24_stru310 *i; // ecx@7
    stru24_stru310 *v6; // ecx@10
    stru24_stru310 *v7; // edx@10

    result = a1->list_310_head;
    if (result)
        a1->list_310_head = result->next;
    else
        result = 0;
    if (result)
    {
        result->unit_id = a2->unit_id;
        a2->sprite->field_88_unused = 1;
        result->x = a2->sprite->x;
        result->y = a2->sprite->y;
        result->x_offset = a2->stru60.ptr_C->x_offset;
        result->y_offset = a2->stru60.ptr_C->y_offset;
        result->_20_ai_importance = a2->stats->_58_ai_importance;
        v3 = a1->list_310_2EC;
        v4 = (char *)&a1->list_310_2EC;
        if ((stru24_stru310 **)v3 == &a1->list_310_2EC)
            a1->field_350 = 10;
        for (i = v3; (char *)i != v4; i = i->next)
        {
            if (result->_20_ai_importance > i->_20_ai_importance)
                break;
        }
        v6 = i->prev;
        v7 = v6->next;
        result->prev = v6;
        result->next = v7;
        v6->next->prev = result;
        v6->next = result;
    }
    return result;
}

//----- (00409650) --------------------------------------------------------
stru24_DrillRigNode **stru24_409650(stru24 *a1)
{
    stru24_DrillRigNode **result; // eax@1
    stru24_DrillRigNode *v2; // edi@1
    stru24_PowerPlantNode *v3; // ecx@2
    stru24_PowerPlantNode *v4; // edx@4
    int v5; // ebp@4
    int v6; // ebx@4
    Entity *v7; // eax@5
    Sprite *v8; // ecx@6
    Sprite *v9; // esi@6
    int v10; // eax@6
    int v11; // ecx@6
    int v12; // edx@16
    int v13; // [sp+4h] [bp-10h]@4
    stru24_PowerPlantNode *i; // [sp+8h] [bp-Ch]@2
    stru24_PowerPlantNode *v15; // [sp+Ch] [bp-8h]@4
    stru24_DrillRigNode **v16; // [sp+10h] [bp-4h]@1

    result = &a1->drill_rig_list_9C;
    v16 = &a1->drill_rig_list_9C;
    v2 = a1->drill_rig_list_9C;
    if ((stru24_DrillRigNode **)v2 != &a1->drill_rig_list_9C)
    {
        v3 = (stru24_PowerPlantNode *)&a1->power_plant_list_F4;
        for (i = v3; ; v3 = i)
        {
            v4 = v3->next;
            v5 = 0x20000000;
            v6 = 0x20000000;
            v15 = 0;
            v13 = 0x20000000;
            if (v3->next != v3)
            {
                do
                {
                    v7 = v4->entity;
                    if (!v7->destroyed)
                    {
                        v7->sprite->field_88_unused = 1;
                        v2->entity->sprite->field_88_unused = 1;
                        v8 = v4->entity->sprite;
                        v9 = v2->entity->sprite;
                        v10 = v8->x - v9->x;
                        v11 = v8->y - v9->y;
                        if (v10 < 0)
                            v10 = -v10;
                        if (v11 < 0)
                            v11 = -v11;
                        if (v11 + v10 >= v5 + v6)
                        {
                            v6 = v13;
                        }
                        else
                        {
                            v6 = v11;
                            v5 = v10;
                            v13 = v11;
                            v15 = v4;
                        }
                    }
                    v4 = v4->next;
                } while (v4 != i);
            }
            v2->ptr_28 = v15;
            if (current_level_idx == LEVEL_MUTE_03_BUBBLIN_CRUDE)
            {
                v2->field_34 = 1;
            }
            else
            {
                v12 = (v6 + v5) / 51200;
                v2->field_34 = v12;
                if (v12 >= 1)
                {
                    if (v12 > 3)
                        v2->field_34 = 3;
                }
                else
                {
                    v2->field_34 = 1;
                }
            }
            v2 = v2->next;
            result = v16;
            if ((stru24_DrillRigNode **)v2 == v16)
                break;
        }
    }
    return result;
}

//----- (00409770) --------------------------------------------------------
void script_409770_ai(Script *a1)
{
    stru24 *v1; // esi@1
    signed int v2; // ebx@1
    stru24_DrillRigNode *v3; // eax@1
    stru24 *v4; // edi@3
    stru24_DrillRigNode *v5; // edi@9
    stru24_stru160 *v6; // ecx@10
    stru24_stru160 *v7; // eax@11
    int v8; // edx@11
    stru24 *i; // eax@12
    int v10; // eax@19
    int v11; // eax@20
    stru24_stru160 *v12; // edx@21
    stru24_DrillRigNode *v13; // eax@26
    EnemyAI_stru57 *v14; // ebp@26
    stru24_stru94 *j; // edi@28
    int *v16; // ebx@29
    enum UNIT_ID v17; // eax@31
    signed int v18; // ecx@31
    signed int v19; // eax@34
    signed int v20; // eax@36
    int v21; // eax@38
    int v22; // eax@38
    Entity *v23; // edx@38
    void *v24; // ST08_4@38
    stru24_stru310 *v25; // ebx@40
    int v26; // edi@42
    int v27; // edx@43
    signed int v28; // eax@43
    signed int v29; // eax@45
    stru24_stru94 *v30; // ecx@49
    int v31; // eax@54
    void *v32; // ST08_4@54
    stru24_stru26C *v33; // eax@55
    int v34; // ecx@56
    int v35; // eax@56
    enum UNIT_ID v36; // eax@61
    signed int v37; // ebx@61
    signed int v38; // ebx@63
    stru24_stru94 *k; // edi@67
    Entity *v40; // ecx@68
    int v41; // eax@72
    void *v42; // edx@72
    void *v43; // ST08_4@72
    Entity *v44; // edx@72
    stru24_stru26C *v45; // eax@77
    stru24_stru26C *v46; // edx@80
    bool v47; // zf@80
    enum PLAYER_SIDE v48; // ecx@84
    __int16 *v49; // edi@85
    int v50; // eax@91
    enum UNIT_ID v51; // ebx@91
    int v52; // eax@94
    int v53; // eax@99
    Script *v54; // ecx@101
    int v55; // eax@102
    int v56; // eax@104
    enum PLAYER_SIDE v57; // eax@106
    Script *v58; // ST0C_4@109
    enum PLAYER_SIDE v59; // ecx@109
    stru24_stru310 *v60; // edi@111
    enum UNIT_ID v61; // ecx@117
    int v62; // ebx@117
    enum UNIT_ID v63; // eax@117
    int v64; // eax@119
    enum UNIT_ID v65; // eax@120
    signed int v66; // eax@121
    int *v67; // ecx@124
    int v68; // ST00_4@124
    stru24_stru310 *v69; // edi@125
    int v71; // ecx@128
    int v72; // edx@128
    stru24_stru160 *v73; // edi@129
    int v74; // ebp@130
    stru24_stru160 *v75; // ecx@131
    stru24 *v76; // eax@132
    stru24_stru160 *l; // edx@132
    int v78; // ebx@137
    int v79; // eax@137
    int v80; // edx@137
    int v81; // eax@141
    int v82; // eax@144
    stru24_stru160 *m; // edi@147
    stru24_stru160 *v84; // ecx@148
    int v85; // ebp@148
    stru24 *v86; // eax@149
    stru24_stru160 *n; // edx@149
    int v88; // ebx@154
    int v89; // eax@154
    int v90; // edx@154
    int v91; // eax@158
    int v92; // eax@161
    stru24_stru160 *v93; // edi@164
    char *v94; // edx@164
    signed int ii; // ebx@165
    void **v96; // ecx@167
    int v97; // eax@168
    stru24_stru160 *jj; // ecx@168
    void **v99; // eax@173
    int v100; // ecx@175
    int v101; // eax@175
    int v102; // eax@175
    stru24_stru160 *v103; // edi@178
    stru24_stru160 *v104; // eax@179
    int v105; // edx@179
    signed int v106; // ecx@180
    int v107; // ebx@182
    int v108; // eax@182
    int v109; // eax@182
    int v110; // eax@184
    int v111; // ecx@188
    stru24_AttackerNode *v112; // eax@188
    char *v113; // edx@188
    enum PLAYER_SIDE v114; // ecx@188
    int v115; // edx@188
    stru24_AttackerNode *v116; // edi@190
    stru24_AttackerNode *i2; // eax@192
    Sprite *v118; // edx@193
    int v119; // ecx@193
    int v120; // edx@193
    stru24_AttackerNode *v121; // ecx@199
    stru24_stru160 *v122; // edx@199
    int v123; // ebx@199
    stru24_DrillRigNode *v124; // eax@201
    stru24_DrillRigNode *v125; // edx@201
    int v126; // ecx@215
    int v127; // edx@215
    stru24_stru160 *v128; // eax@215
    _DWORD *v129; // edi@215
    int v130; // ebx@215
    stru24_stru160 *v131; // edx@217
    char *v132; // eax@217
    int v133; // eax@219
    stru24_stru160 *v134; // eax@222
    stru24_stru160 *v135; // eax@225
    stru24_stru160 *kk; // edi@227
    stru24_stru160 *v137; // ecx@228
    int v138; // eax@229
    int v139; // ecx@229
    void **v140; // eax@235
    stru24_stru160 *v141; // ebx@235
    void **v142; // ecx@235
    stru24 *ll; // eax@237
    stru24_stru160 *v144; // eax@242
    stru24_stru160 *v145; // ebx@242
    int v146; // ecx@242
    int v147; // eax@242
    stru24_stru160 *v148; // ecx@245
    stru24_stru160 *mm; // eax@247
    int v150; // ecx@249
    int v151; // edx@249
    stru24_stru160 *v152; // edx@255
    stru24_stru160 *nn; // edi@257
    int v154; // ecx@258
    signed int v155; // ebx@258
    int v156; // eax@260
    int v157; // ecx@260
    int v158; // ecx@261
    int v159; // ST0C_4@261
    stru24_stru160 *v160; // eax@261
    stru24_stru160 *v161; // ebx@262
    int v162; // ecx@262
    int v163; // eax@262
    int v164; // [sp+10h] [bp-24h]@45
    int v165; // [sp+10h] [bp-24h]@63
    int v166; // [sp+10h] [bp-24h]@187
    int x; // [sp+14h] [bp-20h]@26
    int y; // [sp+18h] [bp-1Ch]@26
    enum PLAYER_SIDE v172; // [sp+1Ch] [bp-18h]@128
    int v170; // [sp+20h] [bp-14h]@128
    int i1; // [sp+24h] [bp-10h]@128
    char param[4]; // [sp+28h] [bp-Ch]@215
    int v173; // [sp+2Ch] [bp-8h]@215
    int v174; // [sp+30h] [bp-4h]@215

    v1 = (stru24 *)a1->param;
    v2 = 0;
    v3 = v1->_2E8_drillrig_node;
    if (v3 && v3->ptr_28)
    {
        v4 = (stru24 *)v1->tanker_list_DC;
        if ((stru24_OilTankerNode **)v4 != &v1->tanker_list_DC)
        {
            while (*((void(**)(Script *, Script *, enum SCRIPT_EVENT, void *))v4->struC->_C_param + 13) == EventHandler_General_Scout)
            {
                v4 = v4->next;
                if ((stru24_OilTankerNode **)v4 == &v1->tanker_list_DC)
                    goto LABEL_8;
            }
            v4->next->prev = v4->prev;
            v4->prev->next = v4->next;
            v4->next = (stru24 *)v1->_2E8_drillrig_node->_8_next;
            v4->prev = (stru24 *)&v1->_2E8_drillrig_node->_8_next;
            v1->_2E8_drillrig_node->_8_next->prev = (stru24_OilTankerNode *)v4;
            v1->_2E8_drillrig_node->_8_next = (stru24_OilTankerNode *)v4;
            v4->_8_entity = (Entity *)v1->_2E8_drillrig_node;
            ++v1->_2E8_drillrig_node->field_30;
            script_trigger_event(0, EVT_MSG_1542_tanker_set_drillrig, v1->_2E8_drillrig_node->entity, (Script *)v4->struC->_C_param);
            script_trigger_event(0, EVT_MSG_1541_tanker_set_base, v1->_2E8_drillrig_node->ptr_28->entity, (Script *)v4->struC->_C_param);
        }
    LABEL_8:
        v1->_2E8_drillrig_node = 0;
    }
    v5 = v1->drill_rig_list_9C;
    if ((stru24_DrillRigNode **)v5 != &v1->drill_rig_list_9C)
    {
        while (1)
        {
            v6 = v5->pstru24_stru160;
            if (!v6)
                goto LABEL_20;
            v7 = (stru24_stru160 *)v6->_C_next;
            v8 = (int)&v6->_C_next;
            if ((void **)v7 != &v6->_C_next)
                break;
            for (i = (stru24 *)v1->list_1B4; (stru24_stru160 **)i != &v1->list_1B4; i = i->next)
            {
                if ((stru24_stru160 *)i->_8_entity == v6)
                    i->_8_entity = 0;
            }
            v6->next = v1->list_160_head;
            v1->list_160_head = v6;
            v5->pstru24_stru160 = 0;
        LABEL_25:
            v5 = v5->next;
            if ((stru24_DrillRigNode **)v5 == &v1->drill_rig_list_9C)
                goto LABEL_26;
        }
        v6->y_offset = 0;
        for (v6->x_offset = 0; v7 != (stru24_stru160 *)v8; ++v2)
        {
            *(_DWORD *)(*((_DWORD *)v7->_C_next + 23) + 136) = 1;
            v6->x_offset += *(_DWORD *)(*((_DWORD *)v7->_C_next + 23) + 16);
            v6->y_offset += *(_DWORD *)(*((_DWORD *)v7->_C_next + 23) + 20);
            v7 = v7->next;
        }
        v6->x_offset /= v2;
        v10 = v6->y_offset / v2;
        v2 = 0;
        v6->y_offset = v10;
    LABEL_20:
        v5->entity->sprite->field_88_unused = 1;
        v11 = stru24_40B190(v1, 81920, v5->entity->sprite->x, v5->entity->sprite->y);
        v5->field_2C = v11;
        if (!v11)
        {
            v12 = v5->pstru24_stru160;
            if (v12)
            {
                stru24_40B020(v1, v12);
                v5->pstru24_stru160->next = v1->list_11C;
                v5->pstru24_stru160->prev = (stru24_stru160 *)&v1->list_11C;
                v1->list_11C->prev = v5->pstru24_stru160;
                v1->list_11C = v5->pstru24_stru160;
                v5->pstru24_stru160 = 0;
            }
            if (v5->field_30 < v5->field_34)
                v1->_2E8_drillrig_node = v5;
        }
        goto LABEL_25;
    }
LABEL_26:
    v13 = v1->_2E8_drillrig_node;
    v14 = array_464DD0;
    x = 0;
    y = 1;
    if (v13)
    {
        if (!v1->field_2E4)
        {
            for (j = v1->list_94_78; (stru24_stru94 **)j != &v1->list_94_78; j = j->next)
            {
                v16 = &j->_C_cost;
                if (j->_C_cost <= 0 && j->_8_entity->unit_id == v1->_2E0_unit_id)
                {
                    v17 = v1->_2DC_unit_id;
                    v18 = 60 * unit_stats[v17].production_time;
                    if (v18 < 1)
                        v18 = 1;
                    if (_47C6D8_use__466098_cost_multipliers)
                        v19 = _466098_cost_multiplier[_466098_cost_multiplier_idx] * unit_stats[v17].cost;
                    else
                        v19 = levels[current_level_idx]._12_cost_multiplier_idx * unit_stats[v17].cost;
                    v20 = v19 >> 8;
                    *v16 = v20;
                    if (v20 < 10)
                        *v16 = 10;
                    j->_8_entity_script_param = v1->_2DC_unit_id;
                    v21 = *v16;
                    j->_14_cost = *v16;
                    v22 = (v21 << 8) / v18;
                    v23 = j->_8_entity;
                    v24 = (void *)j->_8_entity_script_param;
                    j->_18_cost_per_time_step = v22;
                    stru37_list_427D60_enqueue_item(v1->_2A8_p_globals_cash, &j->_C_cost, v22, v23->script, v24, -1);
                    v1->field_2E4 = 1;
                }
            }
        }
    }
    v25 = v1->list_318;
    if ((stru24_stru310 **)v25 == &v1->list_318)
    {
        v33 = v1->ptr_274;
        if (v33)
        {
            v34 = v33->field_8;
            v35 = array_464DD0[0].field_0;
            if (array_464DD0[0].field_0 != -1)
            {
                while (v35 != v34)
                {
                    v35 = v14[1].field_0;
                    ++v14;
                    if (v35 == -1)
                        goto LABEL_79;
                }
                if (_47C6D8_use__466098_cost_multipliers)
                {
                    v36 = v14->unit_id;
                    v37 = _466098_cost_multiplier[_466098_cost_multiplier_idx] * unit_stats[v36].cost;
                }
                else
                {
                    v36 = v14->unit_id;
                    v37 = levels[current_level_idx]._12_cost_multiplier_idx * unit_stats[v36].cost;
                }
                v38 = v37 >> 8;
                v165 = 60 * unit_stats[v36].production_time;
                if (v165 < 1)
                    v165 = 1;
                if (v38 < 10)
                    v38 = 10;
                for (k = v1->list_94_78; (stru24_stru94 **)k != &v1->list_94_78; k = k->next)
                {
                    v40 = k->_8_entity;
                    if (v40->unit_id == unit_stats[v14->unit_id].factory)
                    {
                        if (!entity_402AC0_is_mode_402AB0(v40) && k->_C_cost <= 0 && v1->field_2AC < v1->list_58_and_70_size)
                        {
                            k->_8_entity_script_param = v14->unit_id;
                            v41 = (v38 << 8) / v165;
                            v42 = (void *)k->_8_entity_script_param;
                            k->_C_cost = v38;
                            v43 = v42;
                            v44 = k->_8_entity;
                            k->_14_cost = v38;
                            k->_18_cost_per_time_step = v41;
                            stru37_list_427D60_enqueue_item(v1->_2A8_p_globals_cash, &k->_C_cost, v41, v44->script, v43, -1);
                            x = 1;
                        }
                        y = 0;
                    }
                }
                if (x || y)
                {
                    v45 = v1->ptr_274->next;
                    v1->ptr_274 = v45;
                    if ((stru24_stru26C **)v45 == &v1->list_260)
                        v1->ptr_274 = v1->list_260;
                }
            }
        LABEL_79:
            if (v14->field_0 == -1)
            {
                show_message_ex(0, aEnemyaiCreatur);
                v46 = v1->ptr_274;
                v47 = v46->next == (stru24_stru26C *)&v1->list_260;
                v1->ptr_274 = v46->next;
                if (v47)
                    v1->ptr_274 = v1->list_260;
            }
        }
    }
    else if (!v25->_20_ai_importance)
    {
        v26 = v25->unit_id;
        if (_47C6D8_use__466098_cost_multipliers)
        {
            v27 = v26;
            v28 = _466098_cost_multiplier[_466098_cost_multiplier_idx] * unit_stats[v26].cost;
        }
        else
        {
            v27 = v26;
            v28 = levels[current_level_idx]._12_cost_multiplier_idx * unit_stats[v26].cost;
        }
        v29 = v28 >> 8;
        v164 = 60 * unit_stats[v27].production_time;
        if (60 * unit_stats[v27].production_time < 1)
            v164 = 1;
        if (v29 < 10)
            v29 = 10;
        v30 = v1->list_94_78;
        if ((stru24_stru94 **)v30 != &v1->list_94_78)
        {
            while (v30->_8_entity->unit_id != unit_stats[v27].factory || v30->_C_cost > 0)
            {
                v30 = v30->next;
                if ((stru24_stru94 **)v30 == &v1->list_94_78)
                    goto LABEL_82;
            }
            v30->_8_entity_script_param = v26;
            v30->_14_cost = v29;
            v30->_C_cost = v29;
            v31 = (v29 << 8) / v164;
            v32 = (void *)v30->_8_entity_script_param;
            v30->_18_cost_per_time_step = v31;
            stru37_list_427D60_enqueue_item(v1->_2A8_p_globals_cash, &v30->_C_cost, v31, v30->_8_entity->script, v32, -1);
            v25->_20_ai_importance = 1;
            v25->field_8 = 0;
        }
    }
LABEL_82:
    if (current_level_idx >= LEVEL_SURV_16 && current_level_idx <= LEVEL_MUTE_25)
    {
        v48 = v1->_2A0_player_side;
        v49 = game_globals_cpu[0].cash[v48 + 7 * player_side] ? &levels[current_level_idx].field_28 : &levels[current_level_idx].field_20;
        if ((v48 == 1 || v48 == 2) && v1->field_360 && (stru24_stru94 **)v1->list_94_78 != &v1->list_94_78)
        {
            v50 = v1->level_field_22_or_2A;
            v51 = (v1->_2A4_player_side == SURVIVORS) ? UNIT_STATS_SURV_BOMBER : UNIT_STATS_MUTE_WASP;
            if (v50 > 0)
            {
                v52 = v50 - 60;
            }
            else
            {
                if (stru24_40B490(v1, v51, &x, &y))
                {
                    spawn_unit(v51, x, y, v1->_2A0_player_side);
                    v1->level_field_22_or_2A = ((unsigned __int16)v49[2] + rnd_capped((unsigned __int16)v49[3])) >> 2;
                    --v1->field_360;
                    goto LABEL_97;
                }
                v52 = (unsigned __int16)v49[2] + rnd_capped((unsigned __int16)v49[3]);
            }
            v1->level_field_22_or_2A = v52;
            goto LABEL_97;
        }
    }
LABEL_97:
    if (*v1->_2A8_p_globals_cash && (stru24_stru94 **)v1->list_94_78 != &v1->list_94_78)
    {
        v53 = v1->field_350;
        if (v53 <= 0)
        {
            v54 = v1->task;
            if (v54)
            {
                v55 = v1->field_34C;
                if (v55 > 0)
                {
                    v56 = (v55 << 8) / v1->field_348;
                    if (v56 > 85)
                    {
                        if (v56 <= 171 && v1->field_344 < 1)
                        {
                            v58 = v1->task;
                            v59 = v1->_2A0_player_side;
                            v1->field_344 = 1;
                            script_trigger_event(task_ai_players[v59], EVT_MSG_NEXT_CONSTRUCTION_STATE, (void *)1, v58);
                        }
                    }
                    else if (v1->field_344 < 2)
                    {
                        v57 = v1->_2A0_player_side;
                        v1->field_344 = 2;
                        script_trigger_event(task_ai_players[v57], EVT_MSG_NEXT_CONSTRUCTION_STATE, (void *)2, v54);
                    }
                }
                else
                {
                    script_trigger_event(task_ai_players[v1->_2A0_player_side], EVT_MSG_NEXT_CONSTRUCTION_STATE, (void *)3, v1->task);
                    v1->task = 0;
                }
            }
            else if (game_globals_per_player.cash[v1->_2A0_player_side] > 0)
            {
                v60 = v1->list_310_2EC;
                if ((stru24_stru310 **)v60 != &v1->list_310_2EC)
                {
                    while (stru24_40B190(v1, 0x10000, v60->x, v60->y) >= unit_stats[33]._54_ai_importance
                        && v60->_20_ai_importance < unit_stats[48]._58_ai_importance
                        || !sub_40AB60(v60))
                    {
                        v60 = v60->next;
                        if ((stru24_stru310 **)v60 == &v1->list_310_2EC)
                            goto LABEL_125;
                    }
                    v61 = v60->unit_id;
                    v62 = unit_stats[v61].production_time;
                    v1->task = spawn_unit(v61, v60->x, v60->y, v1->_2A0_player_side)->script;
                    v63 = v60->unit_id;
                    if ((signed int)v63 < 52 || (signed int)v63 > 57)
                    {
                        v65 = v63;
                        if (_47C6D8_use__466098_cost_multipliers)
                            v66 = _466098_cost_multiplier[_466098_cost_multiplier_idx] * unit_stats[4 * v65 / 0x64].cost;
                        else
                            v66 = levels[current_level_idx]._12_cost_multiplier_idx * unit_stats[4 * v65 / 0x64].cost;
                        v64 = v66 >> 8;
                    }
                    else
                    {
                        v64 = unit_stats[v63].cost >> 2;
                    }
                    v1->field_348 = v64;
                    v1->field_34C = v64;
                    v67 = v1->_2A8_p_globals_cash;
                    v68 = (v1->field_348 << 8) / (60 * v62);
                    v1->field_354 = v68;
                    stru37_list_427D60_enqueue_item(v67, &v1->field_34C, v68, 0, 0, -1);
                    v1->field_344 = 0;
                    v60->next->prev = v60->prev;
                    v60->prev->next = v60->next;
                    v60->next = v1->list_310_head;
                    v1->list_310_head = v60;
                }
            }
        LABEL_125:
            v69 = v1->list_318;
            if ((stru24_stru310 **)v69 != &v1->list_318)
            {
                Entity *v70 = v69->field_8;
                if (v70)
                {
                    if (*(void(**)(Script *, Script *, enum SCRIPT_EVENT, void *))((int)v70->script + 52) != EventHandler_General_Scout)
                    {
                        v71 = v69->x;
                        v172 = v1->_2A0_player_side;
                        v72 = v69->y;
                        v170 = v71;
                        i1 = v72;

                        script_trigger_event(0, EVT_CMD_ENTITY_MOVE, &v172, v70->script);
                        v69->next->prev = v69->prev;
                        v69->prev->next = v69->next;
                        v69->next = v1->list_310_head;
                        v1->list_310_head = v69;
                    }
                }
            }
        }
        else
        {
            v1->field_350 = v53 - 1;
        }
    }
    v73 = v1->list_11C;
    if ((stru24_stru160 **)v73 != &v1->list_11C)
    {
        v74 = 0;
        do
        {
            v75 = (stru24_stru160 *)v73->_C_next;
            if ((void **)v75 == &v73->_C_next)
            {
                v76 = (stru24 *)v1->list_1B4;
                for (l = v73->prev; (stru24_stru160 **)v76 != &v1->list_1B4; v76 = v76->next)
                {
                    if ((stru24_stru160 *)v76->_8_entity == v73)
                        v76->_8_entity = 0;
                }
                v73->next->prev = v73->prev;
                v73->prev->next = v73->next;
                v73->next = v1->list_160_head;
                v1->list_160_head = v73;
                v73 = l;
            }
            else
            {
                do
                {
                    *(_DWORD *)(*((_DWORD *)v75->_C_next + 23) + 136) = 1;
                    v78 = *((_DWORD *)v75->_C_next + 23);
                    v79 = *(_DWORD *)(v78 + 16) - v1->_278_x_offset;
                    v80 = *(_DWORD *)(v78 + 20) - v1->_27C_y_offset;
                    if (v79 < 0)
                        v79 = -v79;
                    if (v80 < 0)
                        v80 = -v80;
                    v81 = v80 + v79;
                    if (v81 > v74)
                    {
                        v74 = v81;
                        *(_DWORD *)(v78 + 136) = 1;
                        v73->x_offset = *(_DWORD *)(*((_DWORD *)v75->_C_next + 23) + 16);
                        v73->y_offset = *(_DWORD *)(*((_DWORD *)v75->_C_next + 23) + 20);
                    }
                    v75 = v75->next;
                } while ((void **)v75 != &v73->_C_next);
                v74 = 0;
                v82 = stru24_40B190(v1, 0x10000, v73->x_offset, v73->y_offset);
                v73->field_30 = v82;
                if (v82 > v1->field_2C0)
                    v1->field_2C0 = v82;
            }
            v73 = v73->next;
        } while ((stru24_stru160 **)v73 != &v1->list_11C);
    }
    for (m = (stru24_stru160 *)v1->field_168; (int *)m != &v1->field_168; m = m->next)
    {
        v84 = (stru24_stru160 *)m->_C_next;
        v85 = 0;
        if ((void **)v84 == &m->_C_next)
        {
            v86 = (stru24 *)v1->list_1B4;
            for (n = m->prev; (stru24_stru160 **)v86 != &v1->list_1B4; v86 = v86->next)
            {
                if ((stru24_stru160 *)v86->_8_entity == m)
                    v86->_8_entity = 0;
            }
            m->next->prev = m->prev;
            m->prev->next = m->next;
            m->next = v1->list_160_head;
            v1->list_160_head = m;
            m = n;
        }
        else
        {
            do
            {
                *(_DWORD *)(*((_DWORD *)v84->_C_next + 23) + 136) = 1;
                v88 = *((_DWORD *)v84->_C_next + 23);
                v89 = *(_DWORD *)(v88 + 16) - v1->_278_x_offset;
                v90 = *(_DWORD *)(v88 + 20) - v1->_27C_y_offset;
                if (v89 < 0)
                    v89 = -v89;
                if (v90 < 0)
                    v90 = -v90;
                v91 = v90 + v89;
                if (v91 > v85)
                {
                    v85 = v91;
                    *(_DWORD *)(v88 + 136) = 1;
                    m->x_offset = *(_DWORD *)(*((_DWORD *)v84->_C_next + 23) + 16);
                    m->y_offset = *(_DWORD *)(*((_DWORD *)v84->_C_next + 23) + 20);
                }
                v84 = v84->next;
            } while ((void **)v84 != &m->_C_next);
            v92 = stru24_40B190(v1, 0x10000, m->x_offset, m->y_offset);
            m->field_30 = v92;
            if (v92 > v1->field_2C0)
                v1->field_2C0 = v92;
        }
    }
    v93 = v1->list_1B4;
    v94 = (char *)&v1->list_1B4;
    if ((stru24_stru160 **)v93 != &v1->list_1B4)
    {
        for (ii = 0; ; ii = 0)
        {
            v96 = &v93->_C_next;
            if (v93->_C_next == &v93->_C_next)
            {
                v97 = *(_DWORD *)v94;
                for (jj = v93->prev; (char *)v97 != v94; v97 = *(_DWORD *)v97)
                {
                    if (*(stru24_stru160 **)(v97 + 8) == v93)
                        *(_DWORD *)(v97 + 8) = 0;
                }
                v93->next->prev = v93->prev;
                v93->prev->next = v93->next;
                v93->next = v1->list_160_head;
                v1->list_160_head = v93;
                v93 = jj;
            }
            else
            {
                v99 = (void **)*v96;
                v93->y_offset = 0;
                for (v93->x_offset = 0; v99 != v96; ++ii)
                {
                    *(_DWORD *)(*((_DWORD *)v99[3] + 23) + 136) = 1;
                    v93->x_offset += *(_DWORD *)(*((_DWORD *)v99[3] + 23) + 16);
                    v93->y_offset += *(_DWORD *)(*((_DWORD *)v99[3] + 23) + 20);
                    v99 = (void **)*v99;
                }
                v100 = v93->x_offset / ii;
                v101 = v93->y_offset / ii;
                v93->x_offset = v100;
                v93->y_offset = v101;
                v102 = stru24_40B190(v1, 81920, v100, v101);
                v93->field_30 = v102;
                if (v102 > v1->field_2C0)
                    v1->field_2C0 = v102;
            }
            v93 = v93->next;
            v94 = (char *)&v1->list_1B4;
            if ((stru24_stru160 **)v93 == &v1->list_1B4)
                break;
        }
    }
    v103 = v1->field_24C;
    if (v103)
    {
        v104 = (stru24_stru160 *)v103->_C_next;
        v105 = (int)&v103->_C_next;
        if ((void **)v104 != &v103->_C_next)
        {
            v106 = 0;
            v103->y_offset = 0;
            v103->x_offset = 0;
            for (v103->_2C_ai_importance = 0; v104 != (stru24_stru160 *)v105; ++v106)
            {
                *(_DWORD *)(*((_DWORD *)v104->_C_next + 23) + 136) = 1;
                v103->x_offset += *(_DWORD *)(*((_DWORD *)v104->_C_next + 23) + 16);
                v103->y_offset += *(_DWORD *)(*((_DWORD *)v104->_C_next + 23) + 20);
                v103->_2C_ai_importance += *(_DWORD *)(*((_DWORD *)v104->_C_next + 6) + 84);
                v104 = v104->next;
            }
            v107 = v103->x_offset / v106;
            v108 = v103->y_offset / v106;
            v103->x_offset = v107;
            v103->y_offset = v108;
            v109 = stru24_40B190(v1, 81920, v107, v108);
            v103->field_30 = v109;
            if (v109 > v1->field_2C0)
                v1->field_2C0 = v109;
        }
    }
    v110 = v1->field_2C0;
    if (v110 > v1->field_2B4)
        v1->field_2C0 = v110 - 2;
    if ((stru24_EnemyNode **)v1->enemy_list_108 != &v1->enemy_list_108)
    {
        v166 = 0;
        stru24_40B230(v1);
        if (v1->_278_x_offset == -1)
        {
        LABEL_227:
            for (kk = v1->list_1B4; (stru24_stru160 **)kk != &v1->list_1B4; kk = kk->next)
            {
                v137 = kk->field_8;
                if (v137)
                {
                    v138 = v137->x_offset - kk->x_offset;
                    v139 = v137->y_offset - kk->y_offset;
                    if (v138 < 0)
                        v138 = -v138;
                    if (v139 < 0)
                        v139 = -v139;
                    if (v138 >= 0x4000 || v139 >= 0x4000)
                    {
                        v144 = kk->field_8;
                        v145 = (stru24_stru160 *)kk->_C_next;
                        v146 = v144->y_offset;
                        v147 = v144->x_offset;
                        *(_DWORD *)param = v1->_2A0_player_side;
                        kk->field_3C = v147;
                        v173 = v147;
                        kk->field_40 = v146;
                        v174 = v146;
                        for (kk->field_24 = 0; (void **)v145 != &kk->_C_next; v145 = v145->next)
                            script_trigger_event(0, EVT_CMD_ENTITY_MOVE, param, *((Script **)v145->_C_next + 3));
                    }
                    else
                    {
                        v140 = (void **)kk->_C_next;
                        v141 = kk->prev;
                        v142 = &kk->_C_next;
                        if (v140 != &kk->_C_next)
                        {
                            do
                            {
                                *((_DWORD *)*v140 + 1) = (int)v140[1];
                                *(_DWORD *)v140[1] = (int)v140[0];
                                *v140 = kk->field_8->_C_next;
                                v140[1] = &kk->field_8->_C_next;
                                *((_DWORD *)kk->field_8->_C_next + 1) = (int)v140;
                                kk->field_8->_C_next = v140;
                                kk->field_8->_2C_ai_importance += *(_DWORD *)(*((_DWORD *)v140[3] + 6) + 84);
                                v140[2] = kk->field_8;
                                v140 = (void **)*v142;
                            } while (*v142 != v142);
                        }
                        for (ll = (stru24 *)v1->list_1B4; (stru24_stru160 **)ll != &v1->list_1B4; ll = ll->next)
                        {
                            if ((stru24_stru160 *)ll->_8_entity == kk)
                                ll->_8_entity = (Entity *)kk->field_8;
                        }
                        kk->next->prev = kk->prev;
                        kk->prev->next = kk->next;
                        kk->next = v1->list_160_head;
                        v1->list_160_head = kk;
                        kk = v141;
                    }
                }
                else
                {
                    v148 = kk->prev;
                    kk->next->prev = v148;
                    kk->prev->next = kk->next;
                    kk->next = v1->list_11C;
                    kk->prev = (stru24_stru160 *)&v1->list_11C;
                    v1->list_11C->prev = kk;
                    v1->list_11C = kk;
                    kk = v148;
                }
            }
            for (mm = (stru24_stru160 *)v1->field_168; (int *)mm != &v1->field_168; mm = mm->next)
            {
                if (!mm->field_30)
                {
                    v150 = mm->x_offset - mm->field_3C;
                    v151 = mm->y_offset - mm->field_40;
                    if (v150 < 0)
                        v150 = -v150;
                    if (v151 < 0)
                        v151 = -v151;
                    if (v150 >= 49152 || v151 >= 49152)
                        continue;
                }
                v152 = mm->prev;
                mm->next->prev = v152;
                mm->prev->next = mm->next;
                mm->next = v1->list_11C;
                mm->prev = (stru24_stru160 *)&v1->list_11C;
                v1->list_11C->prev = mm;
                v1->list_11C = mm;
                mm = v152;
            }
            for (nn = v1->list_11C; (stru24_stru160 **)nn != &v1->list_11C; nn = nn->next)
            {
                v154 = nn->field_28 + 1;
                nn->field_28 = v154;
                v155 = v154;
                if (v166
                    || v1->_2BC_ai_importance
                    || (v156 = nn->_2C_ai_importance, v157 = nn->field_30, y = v156 + v157 + 1, 100 * (v156 - v157) / y >= v1->field_2B8))
                {
                    if (!nn->field_24 || v155 > 4)
                    {
                        stru24_40B020(v1, nn);
                        nn->field_28 = 0;
                    }
                }
                else
                {
                    v158 = nn->x_offset;
                    v159 = nn->y_offset;
                    y = (int)nn->prev;
                    nn->field_24 = 0;
                    v160 = stru24_40B410(v1, nn, v158, v159);
                    if (v160)
                    {
                        v161 = (stru24_stru160 *)nn->_C_next;
                        nn->field_8 = v160;
                        v162 = v160->y_offset;
                        v163 = v160->x_offset;
                        *(_DWORD *)param = v1->_2A0_player_side;
                        nn->field_3C = v163;
                        v173 = v163;
                        nn->field_40 = v162;
                        v174 = v162;
                        for (nn->field_24 = 0; (void **)v161 != &nn->_C_next; v161 = v161->next)
                            script_trigger_event(0, EVT_CMD_ENTITY_MOVE, param, *((Script **)v161->_C_next + 3));
                    }
                    else
                    {
                        nn->field_8 = v1->field_24C;
                        sub_40AFC0(v1, nn, v1->_278_x_offset, v1->_27C_y_offset);
                    }
                    nn->next->prev = nn->prev;
                    nn->prev->next = nn->next;
                    nn->next = v1->list_1B4;
                    nn->prev = (stru24_stru160 *)&v1->list_1B4;
                    v1->list_1B4->prev = nn;
                    v1->list_1B4 = nn;
                    nn = (stru24_stru160 *)y;
                }
            }
            stru24_42E070(v1);
            goto LABEL_272;
        }
        v111 = v1->array_2C8_idx;
        v170 = v1->_278_x_offset;
        x = 0;
        v112 = v1->attacker_list_48;
        v113 = (char *)v1->field_280 + 8 * v111;
        v114 = v1->_2A0_player_side;
        y = (int)v113;
        v115 = v1->_27C_y_offset;
        v172 = v114;
        for (i1 = v115; (stru24_AttackerNode **)v112 != &v1->attacker_list_48; v112 = v112->next)
        {
            if (v112->entity->script->event_handler != EventHandler_General_Scout)
            {
                v116 = v112->prev;
                v112->next->prev = v116;
                v112->prev->next = v112->next;
                v112->next = v1->marshalling_nodes_list__evmission8_only_60;
                v112->prev = (stru24_AttackerNode *)&v1->marshalling_nodes_list__evmission8_only_60;
                v1->marshalling_nodes_list__evmission8_only_60->prev = v112;
                v1->marshalling_nodes_list__evmission8_only_60 = v112;
                script_trigger_event(0, EVT_CMD_ENTITY_MOVE, &v172, v112->entity->script);
                v112 = v116;
            }
        }
        for (i2 = v1->marshalling_nodes_list__evmission8_only_60;
            (stru24_AttackerNode **)i2 != &v1->marshalling_nodes_list__evmission8_only_60;
            i2 = i2->next)
        {
            i2->entity->sprite->field_88_unused = 1;
            v118 = i2->entity->sprite;
            v119 = v118->x - v1->_278_x_offset;
            v120 = v118->y - v1->_27C_y_offset;
            if (v119 < 0)
                v119 = -v119;
            if (v120 < 0)
                v120 = -v120;
            if (v119 < 49152 && v120 < 49152)
            {
                v121 = i2->prev;
                i2->next->prev = v121;
                i2->prev->next = i2->next;
                i2->next = (stru24_AttackerNode *)v1->field_24C->_C_next;
                i2->prev = (stru24_AttackerNode *)&v1->field_24C->_C_next;
                *((_DWORD *)v1->field_24C->_C_next + 1) = (int)i2;
                v1->field_24C->_C_next = i2;
                i2->list_8 = v1->field_24C;
                v122 = v1->field_24C;
                v123 = i2->entity->stats->_54_ai_importance + v122->_2C_ai_importance;
                i2 = v121;
                v122->_2C_ai_importance = v123;
            }
        }
        v124 = v1->drill_rig_list_9C;
        v125 = 0;
        if ((stru24_DrillRigNode **)v124 != &v1->drill_rig_list_9C)
        {
            do
            {
                if (v124->field_2C && !v124->pstru24_stru160)
                    v125 = v124;
                v124 = v124->next;
            } while ((stru24_DrillRigNode **)v124 != &v1->drill_rig_list_9C);
            v166 = (int)v125;
        }
        if (v1->list_160_head)
        {
            if (v125 && v1->field_24C->_2C_ai_importance >= v1->field_2B4)
                goto LABEL_275;
            if (v1->_2BC_ai_importance)
                goto LABEL_218;
            if (v1->field_24C->_2C_ai_importance >= v1->field_2C0)
            {
            LABEL_275:
                if (!v1->_2BC_ai_importance && y && !v1->array_2C8_idx)
                {
                    v126 = *(_DWORD *)(y + 4);
                    v127 = *(_DWORD *)y;
                    v128 = v1->field_24C;
                    *(_DWORD *)param = v1->_2A0_player_side;
                    v173 = v127;
                    v129 = (int *)v128->_C_next;
                    v130 = (int)&v128->_C_next;
                    v128->field_3C = v127;
                    v128->field_40 = v126;
                    v174 = v126;
                    for (v128->field_24 = 0; v129 != (_DWORD *)v130; v129 = (_DWORD *)*v129)
                        script_trigger_event(0, EVT_CMD_ENTITY_MOVE, param, *(Script **)(v129[3] + 12));
                    v131 = v1->field_24C;
                    v132 = (char *)&v1->field_168;
                    goto LABEL_219;
                }
            LABEL_218:
                stru24_40B020(v1, v1->field_24C);
                v131 = v1->field_24C;
                v132 = (char *)&v1->list_11C;
            LABEL_219:
                v131->next = *(stru24_stru160 **)v132;
                v1->field_24C->prev = (stru24_stru160 *)v132;
                *(_DWORD *)(*(_DWORD *)v132 + 4) = (int)v1->field_24C;
                *(_DWORD *)v132 = (int)v1->field_24C;
                v133 = 1;
            LABEL_221:
                if (v133)
                {
                    v134 = v1->list_160_head;
                    if (v134)
                    {
                        v1->field_24C = v134;
                        v1->list_160_head = v134->next;
                    }
                    else
                    {
                        v1->field_24C = 0;
                    }
                    v135 = v1->field_24C;
                    if (v135)
                    {
                        v135->_C_next = &v135->_C_next;
                        v1->field_24C->_10_prev = &v1->field_24C->_C_next;
                        v1->field_24C->field_1C = 0;
                        v1->field_24C->field_8 = 0;
                        v1->field_24C->field_24 = 0;
                        v1->field_24C->_2C_ai_importance = 0;
                        v1->field_24C->field_30 = 0;
                        v1->field_24C->x_offset = v1->_278_x_offset;
                        v1->field_24C->y_offset = v1->_27C_y_offset;
                    }
                }
                goto LABEL_227;
            }
        }
        v133 = x;
        goto LABEL_221;
    }
LABEL_272:
    script_sleep(a1, 60);
}

//----- (0040AB60) --------------------------------------------------------
bool sub_40AB60(stru24_stru310 *a1)
{
    int v1; // eax@1
    int v2; // esi@1
    int v3; // edi@1
    enum UNIT_ID v4; // ecx@1
    int v5; // edi@1
    enum UNIT_ID v6; // eax@1
    stru196 *v7; // edx@1
    int v8; // esi@1
    int v9; // edi@1
    int v10; // ebp@5
    int v11; // ebx@5
    int v12; // esi@6
    int v13; // esi@22
    int v14; // ebp@22
    int v15; // eax@22
    int v16; // ebx@22
    int v17; // edi@27
    int v18; // esi@28
    int v19; // edi@37
    int result; // eax@37
    int v21; // ebp@38
    int v22; // esi@38
    int v23; // ecx@38
    int v24; // ebx@38
    int v25; // eax@38
    int v26; // edi@43
    int v27; // esi@44
    int v28; // ecx@54
    int v29; // ebx@55
    int v30; // ebp@55
    int v31; // esi@60
    int k; // edi@60
    int v33; // ebx@70
    int v34; // edx@71
    int v35; // ebx@71
    int v36; // ebp@71
    int v37; // edi@76
    int v38; // esi@77
    int v39; // ebp@87
    int v40; // [sp+10h] [bp-24h]@5
    int i; // [sp+10h] [bp-24h]@38
    int v42; // [sp+10h] [bp-24h]@55
    int l; // [sp+10h] [bp-24h]@71
    int v44; // [sp+14h] [bp-20h]@5
    int v45; // [sp+18h] [bp-1Ch]@5
    int v46; // [sp+1Ch] [bp-18h]@1
    int v47; // [sp+1Ch] [bp-18h]@22
    stru196 *v48; // [sp+20h] [bp-14h]@1
    int v49; // [sp+24h] [bp-10h]@5
    int v50; // [sp+28h] [bp-Ch]@5
    stru24_stru310 *v51; // [sp+2Ch] [bp-8h]@1
    int v52; // [sp+30h] [bp-4h]@22
    int j; // [sp+30h] [bp-4h]@55

    v1 = a1->y;
    v51 = a1;
    v2 = a1->x + a1->x_offset;
    v3 = a1->y_offset;
    v4 = a1->unit_id;
    v5 = v1 + v3;
    v6 = array_4701D8[0].unit_id;
    v7 = array_4701D8;
    v8 = v2 >> 13;
    v9 = v5 >> 13;
    v46 = v8;
    v48 = array_4701D8;
    if (array_4701D8[0].unit_id == v4)
    {
    LABEL_5:
        v10 = v7->_4_x + v8;
        v11 = 0;
        v40 = v7->_8_y + v9;
        v45 = v7->_4_x + v8;
        v49 = v8 - 1;
        v44 = v7->_8_y + v9;
        v50 = v9 - 1;
        if (v9 >= v40)
        {
        LABEL_21:
            if (v11)
            {
                v13 = v48->_8_y;
                v14 = v45 + 1;
                v15 = v44 - v13;
                v16 = v45 + 1 - v48->_4_x;
                v47 = v44 - v13;
                v52 = v49 - 1;
                if (v16 < v49 - 1)
                {
                    while (1)
                    {
                        if (v15 >= 0 && v16 >= 0 && v14 < map_get_width() && v44 < map_get_height())
                        {
                            v17 = v47;
                            if (v47 >= v44)
                            {
                            LABEL_37:
                                v19 = (v17 << 13) - v51->y_offset;
                                v51->x = (v16 << 13) - v51->x_offset + 4096;
                                v51->y = v19 + 4096;
                                return 1;
                            }
                            while (1)
                            {
                                v18 = v16;
                                if (v16 < v14)
                                    break;
                            LABEL_32:
                                if (++v17 >= v44)
                                {
                                    v17 = v47;
                                    goto LABEL_37;
                                }
                            }
                            while (boxd_40EE70(v18, v17) && !boxd_40EE10_prolly_get_building(v18, v17 - 1))
                            {
                                if (++v18 >= v14)
                                    goto LABEL_32;
                            }
                        }
                        ++v16;
                        ++v14;
                        if (v16 >= v52)
                            break;
                        v15 = v47;
                    }
                }
                v21 = v45 + 1;
                v22 = v48->_8_y;
                v23 = v50 + 1;
                v24 = v45 + 1 - v48->_4_x;
                v25 = v22 + v50 + 1;
                for (i = v22 + v50 + 1; v24 < v52; ++v21)
                {
                    if (v23 >= 0 && v24 >= 0 && v21 < map_get_width() && v25 < map_get_height())
                    {
                        v26 = v23;
                        if (v23 >= v25)
                        {
                        LABEL_54:
                            v28 = (v23 << 13) - v51->y_offset;
                            v51->x = (v24 << 13) - v51->x_offset + 4096;
                            v51->y = v28 + 4096;
                            return 1;
                        }
                    LABEL_44:
                        v27 = v24;
                        if (v24 >= v21)
                            goto LABEL_49;
                        while (boxd_40EE70(v27, v26) && !boxd_40EE10_prolly_get_building(v27, v26 - 1))
                        {
                            if (++v27 >= v21)
                            {
                                v25 = i;
                                v23 = v50 + 1;
                            LABEL_49:
                                if (++v26 >= v25)
                                    goto LABEL_54;
                                goto LABEL_44;
                            }
                        }
                        v25 = i;
                        v23 = v50 + 1;
                    }
                    ++v24;
                }
                v42 = v44;
                v29 = v44 - v48->_8_y;
                v30 = v48->_4_x + v49 + 1;
                for (j = v50 - 1; v29 < j; ++v42)
                {
                    if (v29 >= 0 && v49 + 1 >= 0 && v30 < map_get_width() && v42 < map_get_height())
                    {
                        v31 = v49 + 1;
                        for (k = v29; k < v42; ++k)
                        {
                            if (v31 < v30)
                            {
                                do
                                {
                                    if (!boxd_40EE70(v31, k) || boxd_40EE10_prolly_get_building(v31, k - 1))
                                        goto LABEL_68;
                                    ++v31;
                                } while (v31 < v30);
                                v31 = v49 + 1;
                            }
                        }
                        v33 = (v29 << 13) - v51->y_offset;
                        v51->x = (v31 << 13) - v51->x_offset + 4096;
                        v51->y = v33 + 4096;
                        return 1;
                    }
                LABEL_68:
                    ++v29;
                }
                v34 = v44;
                v35 = v45 - v48->_4_x;
                v36 = v44 - v48->_8_y;
                for (l = v44; v36 < j; l = ++v34)
                {
                    if (v36 >= 0 && v35 >= 0 && v45 < map_get_width() && v34 < map_get_height())
                    {
                        v37 = v36;
                        if (v36 >= v34)
                        {
                        LABEL_87:
                            v39 = (v36 << 13) - v51->y_offset;
                            v51->x = (v35 << 13) - v51->x_offset + 4096;
                            v51->y = v39 + 4096;
                            return 1;
                        }
                        while (1)
                        {
                            v38 = v35;
                            if (v35 < v45)
                                break;
                        LABEL_82:
                            if (++v37 >= v34)
                                goto LABEL_87;
                        }
                        while (boxd_40EE70(v38, v37) && !boxd_40EE10_prolly_get_building(v38, v37 - 1))
                        {
                            if (++v38 >= v45)
                            {
                                v34 = l;
                                goto LABEL_82;
                            }
                        }
                        v34 = l;
                    }
                    ++v36;
                }
                result = 0;
            }
            else
            {
                result = 1;
            }
            return result;
        }
        while (1)
        {
            v12 = v46;
            if (v46 < v10)
                break;
        LABEL_20:
            if (++v9 >= v40)
                goto LABEL_21;
        }
        while (1)
        {
            if (boxd_40EE70(v12, v9) && !boxd_40EE10_prolly_get_building(v12, v9 - 1))
                goto LABEL_19;
            if (v12 >= v45)
            {
                if (v12 <= v49)
                    goto LABEL_14;
                v49 = v12;
            }
            else
            {
                v45 = v12;
            }
            v11 = 1;
        LABEL_14:
            if (v9 < v44)
            {
                v44 = v9;
            LABEL_18:
                v11 = 1;
                goto LABEL_19;
            }
            if (v9 > v50)
            {
                v50 = v9;
                goto LABEL_18;
            }
        LABEL_19:
            if (++v12 >= v10)
                goto LABEL_20;
        }
    }
    while (v6 != -1)
    {
        v6 = v7[1].unit_id;
        ++v7;
        if (v6 == v4)
        {
            v48 = v7;
            goto LABEL_5;
        }
    }
    return 0;
}

//----- (0040AFC0) --------------------------------------------------------
int sub_40AFC0(stru24 *a1, stru24_stru160 *a2, int a3, int a4)
{
    int v4; // esi@1
    char *v5; // edi@1
    int result; // eax@1
    enum PLAYER_SIDE v7; // [sp+8h] [bp-Ch]@1
    int v8; // [sp+Ch] [bp-8h]@1
    int v9; // [sp+10h] [bp-4h]@1

    v4 = (int)a2->_C_next;
    v7 = a1->_2A0_player_side;
    v5 = (char *)&a2->_C_next;
    a2->field_3C = a3;
    v8 = a3;
    result = a4;
    a2->field_40 = a4;
    v9 = a4;
    a2->field_24 = 0;
    if ((void **)v4 != &a2->_C_next)
    {
        do
        {
            result = script_trigger_event(0, EVT_CMD_ENTITY_MOVE, &v7, *(Script **)(*(_DWORD *)(v4 + 12) + 12));
            v4 = *(_DWORD *)v4;
        } while ((char *)v4 != v5);
    }
    return result;
}

//----- (0040B020) --------------------------------------------------------
stru24_EnemyNode **stru24_40B020(stru24 *a1, stru24_stru160 *a2)
{
    stru24 *v2; // esi@1
    stru24_stru160 *v3; // edi@1
    stru24_EnemyNode *v4; // ebx@1
    stru24_EnemyNode **result; // eax@1
    int v6; // ecx@1
    stru24_EnemyNode *v7; // edx@1
    int v8; // ebp@1
    Entity *v9; // eax@2
    Entity *v10; // edx@4
    Sprite *v11; // eax@4
    int v12; // esi@4
    int v13; // edi@4
    int v14; // ecx@20
    int v15; // esi@20
    int v16; // edi@20
    stru24_stru160 *v17; // [sp+10h] [bp-18h]@1
    int v18; // [sp+14h] [bp-14h]@1
    stru24_EnemyNode *v19; // [sp+18h] [bp-10h]@1
    int v20; // [sp+1Ch] [bp-Ch]@1
    stru24 *v21; // [sp+20h] [bp-8h]@1
    //int i; // [sp+24h] [bp-4h]@20

    v2 = a1;
    v3 = a2;
    v4 = a1->enemy_list_108;
    result = &a1->enemy_list_108;
    v6 = 0x20000000;
    v7 = 0;
    v8 = 0x20000000;
    v17 = v3;
    v21 = v2;
    v18 = 0x20000000;
    v20 = 0;
    v19 = 0;
    if ((stru24_EnemyNode **)v4 != result)
    {
        do
        {
            v9 = v4->entity;
            if (!v9->destroyed && v9->stats->_58_ai_importance)
            {
                v9->sprite->field_88_unused = 1;
                v10 = v4->entity;
                v11 = v10->sprite;
                v12 = v11->x - v17->x_offset;
                v13 = v11->y - v17->y_offset;
                if (v12 < 0)
                    v12 = -v12;
                if (v13 < 0)
                    v13 = -v13;
                if (v21->_2BC_ai_importance || v12 < 0x10000 && v13 < 0x10000)
                {
                    if (v13 + v12 < v8 + v6)
                    {
                        v8 = v13;
                        v6 = v12;
                        v18 = v13;
                        v19 = v4;
                    }
                    v20 = 1;
                }
                else if (!v20)
                {
                    v8 = v18;
                    if ((v13 + v12) / v10->stats->_58_ai_importance < v18 + v6)
                    {
                        v8 = v13;
                        v6 = v12;
                        v18 = v13;
                        v19 = v4;
                    }
                }
            }
            v2 = v21;
            v4 = v4->next;
            result = &v21->enemy_list_108;
        } while ((stru24_EnemyNode **)v4 != &v21->enemy_list_108);
        v3 = v17;
        v7 = v19;
    }
    if (v7)
    {
        result = (stru24_EnemyNode **)v2->_2A0_player_side;
        v14 = (int)v7->entity;
        v15 = (int)v3->_C_next;
        v3->field_24 = v7;
        v16 = (int)&v3->_C_next;
        _47CAF0_task_attachment1_attack_task _hidden_local;
        _hidden_local.player_side = (int)result;
        _hidden_local.target = (Entity *)v14;
        for (; v15 != v16; v15 = *(_DWORD *)v15)
            result = (stru24_EnemyNode **)script_trigger_event(
                0,
                EVT_CMD_ENTITY_ATTACK,
                &_hidden_local,
                *(Script **)(*(_DWORD *)(v15 + 12) + 12));
    }
    v17->field_28 = 0;
    return result;
}

//----- (0040B190) --------------------------------------------------------
int stru24_40B190(stru24 *a1, int size, int x, int y)
{
    stru24_EnemyNode *v4; // ebx@1
    char *v5; // edx@1
    Entity *v6; // ecx@2
    Entity *v7; // edi@4
    Sprite *v8; // esi@4
    int v9; // ecx@4
    int v10; // esi@4
    int v12; // [sp+4h] [bp-8h]@1
    int v13; // [sp+8h] [bp-4h]@1

    v13 = size;
    v4 = a1->enemy_list_108;
    v5 = (char *)&a1->enemy_list_108;
    v12 = 0;
    if ((stru24_EnemyNode **)v4 != &a1->enemy_list_108)
    {
        do
        {
            v6 = v4->entity;
            if (!v6->destroyed && v6->stats->_54_ai_importance)
            {
                v6->sprite->field_88_unused = 1;
                v7 = v4->entity;
                v8 = v7->sprite;
                v9 = v8->x - x;
                v10 = v8->y - y;
                if (v9 < 0)
                    v9 = -v9;
                if (v10 < 0)
                    v10 = -v10;
                if (v9 < v13 && v10 < v13)
                    v12 += v7->stats->_54_ai_importance;
            }
            v4 = v4->next;
        } while ((char *)v4 != v5);
    }
    return v12;
}

//----- (0040B230) --------------------------------------------------------
void stru24_40B230(stru24 *a1)
{
    stru24 *v1; // ebp@1
    stru24_EnemyNode *v2; // esi@2
    char *v3; // edi@2
    Entity *v4; // eax@3
    Entity *v5; // edx@4
    Sprite *v6; // eax@4
    int v7; // ecx@4
    int v8; // eax@4
    int v9; // edi@10
    int *v10; // ebx@11
    stru24 *i; // esi@13
    Entity *v12; // eax@14
    Entity *v13; // edx@16
    Sprite *v14; // ecx@16
    int v15; // eax@16
    int v16; // ecx@16
    UnitStat *v17; // edx@22
    int v18; // ecx@26
    int v19; // eax@31
    int v20; // [sp+10h] [bp-4h]@10

    v1 = a1;
    if (a1->_278_x_offset != -1)
    {
        v2 = a1->enemy_list_108;
        v3 = (char *)&a1->enemy_list_108;
        a1->_2BC_ai_importance = 0;
        if ((stru24_EnemyNode **)v2 != &a1->enemy_list_108)
        {
            do
            {
                v4 = v2->entity;
                if (!v4->destroyed)
                {
                    v4->sprite->field_88_unused = 1;
                    v5 = v2->entity;
                    v6 = v5->sprite;
                    v7 = v6->x;
                    v8 = v6->y;
                    if (v7 > v1->field_250 - 49152
                        && v7 < v1->field_258 + 49152
                        && v8 > v1->field_254 - 49152
                        && v8 < v1->field_25C + 49152)
                    {
                        v1->_2BC_ai_importance += v5->stats->_54_ai_importance;
                    }
                }
                v2 = v2->next;
            } while ((char *)v2 != v3);
        }
    }
    v9 = (int)v1->field_280;
    v1->array_2C8_idx = 4;
    v1->field_2D8 = 0x80000000;
    v20 = 0;
    if (v1->field_280[0][0] != -1)
    {
        v10 = v1->array_2C8;
        do
        {
            if (v20 >= 4)
                break;
            *v10 = 0;
            for (i = (stru24 *)v1->enemy_list_108; (stru24_EnemyNode **)i != &v1->enemy_list_108; i = i->next)
            {
                v12 = i->_8_entity;
                if (!v12->destroyed && v12->stats->_54_ai_importance)
                {
                    v12->sprite->field_88_unused = 1;
                    v13 = i->_8_entity;
                    v14 = v13->sprite;
                    v15 = v14->x - *(_DWORD *)v9;
                    v16 = v14->y - *(_DWORD *)(v9 + 4);
                    if (v15 < 0)
                        v15 = -v15;
                    if (v16 < 0)
                        v16 = -v16;
                    if (v15 < 81920 && v16 < 81920)
                    {
                        v17 = v13->stats;
                        if (v17->speed)
                            *v10 += v17->_54_ai_importance;
                        else
                            *v10 -= v17->_54_ai_importance >> 1;
                    }
                }
            }
            v18 = v1->array_2C8[v1->array_2C8_idx];
            if (*v10 <= v18)
            {
                if (*v10 == v18)
                {
                    if (kknd_rand_debug(__FILE__, __LINE__) & 1)
                        v1->array_2C8_idx = v20;
                }
            }
            else
            {
                v1->array_2C8_idx = v20;
            }
            v19 = *(_DWORD *)(v9 + 8);
            v9 += 8;
            ++v10;
            ++v20;
        } while (v19 != -1);
    }
}

//----- (0040B410) --------------------------------------------------------
stru24_stru160 *stru24_40B410(stru24 *a1, stru24_stru160 *a2, int a3, int a4)
{
    stru24_stru160 **v4; // ecx@1
    stru24_stru160 *v5; // edi@1
    int v6; // ebx@1
    int v7; // ebp@1
    int v8; // ecx@3
    int v9; // esi@3
    stru24_stru160 *v11; // [sp+Ch] [bp-Ch]@1
    stru24_stru160 *v12; // [sp+14h] [bp-4h]@1

    v4 = &a1->list_11C;
    v5 = *v4;
    v6 = 0x20000000;
    v7 = 0x20000000;
    v11 = 0;
    v12 = (stru24_stru160 *)v4;
    if ((stru24_stru160 **)*v4 != v4)
    {
        do
        {
            if (v5 != a2)
            {
                v8 = a3 - v5->x_offset;
                v9 = a4 - v5->y_offset;
                if (v8 < 0)
                    v8 = -v8;
                if (v9 < 0)
                    v9 = -v9;
                if (v9 + v8 < v7 + v6)
                {
                    v6 = v8;
                    v7 = v9;
                    v11 = v5;
                }
            }
            v5 = v5->next;
        } while (v5 != v12);
    }
    return v11;
}

//----- (0040B490) --------------------------------------------------------
bool stru24_40B490(stru24 *a1, UNIT_ID a2, int *out_x, int *out_y)
{
    int v3; // ebp@1
    int v4; // ebx@1
    size_t v5; // esi@1
    char *v6; // edx@1
    stru24 *v7; // ecx@2
    Sprite *v8; // esi@5
    int v9; // eax@5
    Sprite *v10; // esi@5
    int v11; // edi@5
    int v12; // eax@5
    int v13; // esi@5
    int v14; // ebp@5
    int v15; // ebx@5
    int v16; // esi@5
    Entity *v17; // edx@13
    int v18; // eax@13
    char v19; // al@15
    int v20; // eax@15
    char v21; // al@18
    int v22; // esi@21
    char *v23; // ecx@21
    int v24; // edx@23
    int v25; // ebx@24
    int *v26; // edi@30
    int v27; // esi@30
    char *i; // ecx@30
    int *v29; // eax@31
    stru24_EnemyNode *v31; // [sp+Ch] [bp-20h]@2
    int v32; // [sp+10h] [bp-1Ch]@1
    int v33; // [sp+14h] [bp-18h]@1
    char *v34; // [sp+18h] [bp-14h]@1
    stru24 *v35; // [sp+1Ch] [bp-10h]@1
    int v36; // [sp+1Ch] [bp-10h]@21
    int v37; // [sp+20h] [bp-Ch]@1
    int v38; // [sp+28h] [bp-4h]@2

    v35 = a1;
    v37 = 0;
    v3 = map_get_height_global() / 0x4000;
    v4 = map_get_width_global() / 0x4000;
    v32 = map_get_width_global() / 0x4000;
    v33 = map_get_height_global() / 0x4000;
    v5 = 4 * map_get_width_global() / 0x4000 * (map_get_height_global() / 0x4000);
    v6 = (char *)malloc(v5);
    v34 = v6;
    if (v6)
    {
        memset(v6, 0, v5);
        v38 = (int)&v35->enemy_list_108;
        v7 = (stru24 *)v35->enemy_list_108;
        v31 = v35->enemy_list_108;
        if ((stru24_EnemyNode **)v7 != &v35->enemy_list_108)
        {
            while (1)
            {
                v7->_8_entity->sprite->field_88_unused = 1;
                v8 = v7->_8_entity->sprite;
                v9 = v8->x;
                v8->field_88_unused = 1;
                v10 = v7->_8_entity->sprite;
                v11 = (v9 - 0x2000) / 0x4000 - 1;
                v12 = v10->x;
                v13 = v10->y;
                v14 = (v12 + 0x2000) / 0x4000 + 1;
                v15 = (v13 - 0x2000) / 0x4000 - 1;
                v16 = (v13 + 0x2000) / 0x4000 + 1;
                if (v11 < 0)
                    v11 = 0;
                if (v14 >= v32)
                    v14 = v32 - 1;
                if (v15 < 0)
                    v15 = 0;
                if (v16 >= v33)
                    v16 = v33 - 1;
                v17 = v7->_8_entity;
                v18 = v17->unit_id;
                if (v18 < (int)UNIT_STATS_SURV_DRILL_RIG || v18 >(int)UNIT_STATS_MUTE_ALCHEMY_HALL)
                {
                    if (v18 < (int)UNIT_STATS_SURV_GUARD_TOWER || v18 >(int)UNIT_STATS_MUTE_ROTARY_CANNON)
                    {
                        v20 = (v17->stats->_58_ai_importance + v17->stats->_54_ai_importance + 10) >> 2;
                    }
                    else
                    {
                        v21 = kknd_rand_debug(0, 0);
                        v7 = (stru24 *)v31;
                        v20 = (v21 & 7) + 15;
                    }
                }
                else
                {
                    v19 = kknd_rand_debug(0, 0);
                    v7 = (stru24 *)v31;
                    v20 = (v19 & 7) + 1;
                }
                if (v15 <= v16)
                {
                    v22 = v16 - v15 + 1;
                    v23 = &v34[4 * (v11 + v32 * v15)];
                    v36 = (int)&v34[4 * (v11 + v32 * v15)];
                    do
                    {
                        if (v11 <= v14)
                        {
                            v24 = v14 - v11 + 1;
                            do
                            {
                                v25 = *(_DWORD *)v23;
                                v23 += 4;
                                --v24;
                                *((_DWORD *)v23 - 1) = v20 + v25;
                            } while (v24);
                            v23 = (char *)v36;
                        }
                        v23 += 4 * v32;
                        --v22;
                        v36 = (int)v23;
                    } while (v22);
                    v7 = (stru24 *)v31;
                }
                v31 = (stru24_EnemyNode *)v7->next;
                if (v7->next == (stru24 *)v38)
                    break;
                v7 = v7->next;
            }
            v4 = v32;
            v3 = v33;
            v6 = v34;
        }
        v26 = out_x;
        v27 = 0;
        for (i = v6; v27 < v3; ++v27)
        {
            v29 = 0;
            if (v4 > 0)
            {
                do
                {
                    if (*(_DWORD *)i >= *(_DWORD *)v6)
                    {
                        v6 = i;
                        v26 = v29;
                        v38 = v27;
                    }
                    v29 = (int *)((char *)v29 + 1);
                    i += 4;
                } while ((int)v29 < v4);
                v3 = v33;
            }
        }
        if (*(_DWORD *)v6 > 0)
        {
            *out_x = (_DWORD)v26 << 14;
            *out_y = v38 << 14;
            v37 = 1;
        }
        free(v34);
    }
    return v37;
}

//----- (0040B700) --------------------------------------------------------
void script_40B700_ai(Script *a1)
{
    a1->handler = script_409770_ai;
    script_sleep(a1, 60);
}

//----- (0040B720) --------------------------------------------------------
int UNIT_InitAiPlayers()
{
    int v0; // ecx@1
    int *v1; // eax@2
    Script **v2; // ebp@6
    Script *v3; // eax@9
    stru24 *v4; // eax@9
    stru24 *v5; // esi@9
    char *v6; // eax@9
    enum PLAYER_SIDE v7; // eax@10
    enum LEVEL_ID v8; // ecx@17
    enum LEVEL_ID v9; // ecx@18
    int v10; // ecx@20
    int *v11; // eax@20
    stru24_stru26C *v12; // eax@22
    int v13; // eax@23
    stru24_AttackerNode *v14; // eax@25
    int v15; // eax@26
    int v16; // ecx@27
    stru24_stru94 *v17; // eax@29
    int v18; // eax@30
    stru24_DrillRigNode *v19; // eax@32
    int v20; // eax@33
    stru24_OilTankerNode *v21; // eax@35
    int v22; // eax@36
    stru24_PowerPlantNode *v23; // eax@38
    int v24; // eax@39
    stru24_EnemyNode *v25; // eax@41
    int v26; // eax@42
    stru24_stru160 *v27; // eax@44
    int v28; // eax@45
    stru24_stru310 *v29; // eax@47
    int v30; // eax@48
    stru24_WandererNode *v31; // eax@50
    int v32; // eax@51
    stru24_stru40 *v33; // eax@53
    int v34; // eax@54
    bool v35; // sf@58
    unsigned __int8 v36; // of@58
    int result; // eax@59
    Script **v38; // ebp@63
    Script *v39; // eax@66
    stru24 *v40; // esi@66
    int v41; // edx@66
    stru24_EnemyNode *v42; // eax@66
    int v43; // eax@67
    stru24_stru160 *v44; // eax@69
    int v45; // eax@70
    stru24_AttackerNode *v46; // eax@72
    int v47; // eax@73
    int v48; // ecx@74
    stru24_AttackerNode *v49; // eax@76
    int v50; // ecx@77
    int v51; // eax@77
    int v52; // ecx@78
    stru24_stru10_convoy *v53; // eax@80
    int v54; // eax@81
    stru24_WandererNode *v55; // eax@83
    int v56; // eax@84
    stru24_stru40 *v57; // eax@86
    int v58; // eax@87
    int *v59; // eax@93
    Script **v60; // ebp@97
    Script *v61; // eax@100
    stru24 *v62; // esi@100
    enum LEVEL_ID v63; // eax@100
    stru24_EnemyNode *v64; // eax@100
    int v65; // eax@101
    stru24_AttackerNode *v66; // eax@103
    int v67; // eax@104
    int v68; // ecx@105
    stru24_stru160 *v69; // eax@107
    int v70; // eax@108
    stru24_WandererNode *v71; // eax@110
    int v72; // eax@111
    stru24_stru40 *v73; // eax@113
    int v74; // eax@114
    int v75; // [sp+10h] [bp-Ch]@6
    enum PLAYER_SIDE v76; // [sp+10h] [bp-Ch]@63
    enum PLAYER_SIDE v77; // [sp+10h] [bp-Ch]@97
    unsigned int v78; // [sp+14h] [bp-8h]@6
    stru24 **v79; // [sp+14h] [bp-8h]@63
    stru24 **v80; // [sp+14h] [bp-8h]@97
    stru24 **v81; // [sp+18h] [bp-4h]@6
    int v82; // [sp+18h] [bp-4h]@63
    int v83; // [sp+18h] [bp-4h]@97

    v0 = 0;
    _4778C8_singleplayer_available_units_denom = 0;
    if (current_level_idx == LEVEL_MUTE_05_AMBUSH)// Evolved Mission #5: Ambush
    {
        v59 = dword_470510 + 1;
        do
        {
            if (*v59 == 1)
                ++v0;
            ++v59;
        } while ((int)v59 < (int)&dword_470510[7]);
        _4778C8_singleplayer_available_units_denom = v0;
        v77 = SURVIVORS;
        v80 = cpu_player_scripts_attached_stru24s;
        v60 = &task_ai_players[1];
        v83 = 0;
        while (1)
        {
            if (dword_470510[v83+1] == 1 && dword_464DCC)
            {
                v61 = script_create_function(SCRIPT_TYPE_INVALID, script_42DF20);
                *v60 = v61;
                v61->script_type = SCRIPT_TYPE_39030;
                (*v60)->event_handler = (void(*)(Script *, Script *, enum SCRIPT_EVENT, void *))EventHandler_42DC90_evolved_mission5_ai;
                v62 = (stru24 *)script_create_local_object(*v60, 868);
                memset(v62, 0, sizeof(stru24));
                (*v60)->param = v62;
                *v80 = v62;
                v62->_2A0_player_side = v77;
                v62->_2A8_p_globals_cash = &game_globals_per_player.cash[v83 + 1];
                v62->list_58_and_70_size = 549 / (_4778C8_singleplayer_available_units_denom + 1);
                v62->field_2B4 = 4;
                v62->field_2B8 = -50;
                v62->_2BC_ai_importance = 0;
                v63 = current_level_idx;
                game_globals_per_player.cash[v83 + 1] = levels[current_level_idx].evolved_starting_cash;
                v62->level_field_22_or_2A = levels[v63].field_22;
                v62->list_260 = (stru24_stru26C *)&v62->list_260;
                v62->list_26C_264 = (stru24_stru26C *)&v62->list_260;
                v62->list_26C = 0;
                v62->list_94_78 = (stru24_stru94 *)&v62->list_94_78;
                v62->list_94_7C = (stru24_stru94 *)&v62->list_94_78;
                v62->list_94 = 0;
                v62->drill_rig_list_9C = (stru24_DrillRigNode *)&v62->drill_rig_list_9C;
                v62->drill_rig_list_A0 = (stru24_DrillRigNode *)&v62->drill_rig_list_9C;
                v62->drill_rig_list = 0;
                v62->tanker_list_DC = (stru24_OilTankerNode *)&v62->tanker_list_DC;
                v62->tanker_list_E0 = (stru24_OilTankerNode *)&v62->tanker_list_DC;
                v62->tanker_list = 0;
                v62->power_plant_list_F4 = (stru24_PowerPlantNode *)&v62->power_plant_list_F4;
                v62->list_104_F8 = (stru24_PowerPlantNode *)&v62->power_plant_list_F4;
                v62->power_plant_list = 0;
                v64 = (stru24_EnemyNode *)malloc(0x1C14u);
                v62->enemy_list = v64;
                if (!v64)
                    return 0;
                v62->enemy_list_free_pool = v64;
                v65 = 0;
                do
                {
                    v62->enemy_list[v65].next = &v62->enemy_list[v65 + 1];
                    ++v65;
                } while (v65 < 598);
                v62->enemy_list[598].next = 0;
                v62->enemy_list_108 = (stru24_EnemyNode *)&v62->enemy_list_108;
                v62->enemy_list_10C = (stru24_EnemyNode *)&v62->enemy_list_108;
                v66 = (stru24_AttackerNode *)malloc(16 * (v62->list_58_and_70_size + 16));
                v62->attacker_list = v66;
                if (!v66)
                    return 0;
                v62->attacker_list_free_pool = v66;
                v67 = 0;
                if (v62->list_58_and_70_size + 15 > 0)
                {
                    v68 = 0;
                    do
                    {
                        ++v67;
                        v62->attacker_list[v68].next = &v62->attacker_list[v68 + 1];
                        ++v68;
                    } while (v67 < v62->list_58_and_70_size + 15);
                }
                v62->attacker_list[v67].next = 0;
                v62->attacker_list_48 = (stru24_AttackerNode *)&v62->attacker_list_48;
                v62->attacker_list_4C = (stru24_AttackerNode *)&v62->attacker_list_48;
                v69 = (stru24_stru160 *)malloc(0x880u);
                v62->list_160 = v69;
                if (!v69)
                    return 0;
                v62->list_160_head = v69;
                v70 = 0;
                do
                {
                    v62->list_160[v70].next = &v62->list_160[v70 + 1];
                    ++v70;
                } while (v70 < 31);
                v62->list_160[31].next = 0;
                v62->list_160_120 = (stru24_stru160 *)&v62->list_11C;
                v62->marshalling_nodes_list__evmission8_only = 0;
                v62->list_11C = (stru24_stru160 *)&v62->list_11C;
                v62->marshalling_nodes_list__evmission8_only_64 = (stru24_AttackerNode *)&v62->marshalling_nodes_list__evmission8_only_60;
                v62->next = v62;
                v62->marshalling_nodes_list__evmission8_only_60 = (stru24_AttackerNode *)&v62->marshalling_nodes_list__evmission8_only_60;
                v62->prev = v62;
                v62->list_10_convoy = 0;
                v71 = (stru24_WandererNode *)malloc(0x2570u);
                v62->wanderer_list = v71;
                if (!v71)
                    return 0;
                v62->wanderer_list_free_pool = v71;
                v72 = 0;
                do
                {
                    v62->wanderer_list[v72].next = &v62->wanderer_list[v72 + 1];
                    ++v72;
                } while (v72 < 598);
                v62->wanderer_list[598].next = 0;
                v62->wanderer_list_1C = (stru24_WandererNode *)&v62->wanderer_list_18;
                v62->wanderer_list_18 = (stru24_WandererNode *)&v62->wanderer_list_18;
                v73 = (stru24_stru40 *)malloc(0x2570u);
                v62->list_40 = v73;
                if (!v73)
                    return 0;
                v62->list_40_head = v73;
                v74 = 0;
                do
                {
                    v62->list_40[v74].next = &v62->list_40[v74 + 1];
                    ++v74;
                } while (v74 < 598);
                v62->list_40[598].next = 0;
                v62->list_40_34 = (stru24_stru40 *)&v62->list_40_30;
                v62->field_1AC = 0;
                v62->list_40_30 = (stru24_stru40 *)&v62->list_40_30;
                v62->field_16C = (int)&v62->field_168;
                v62->field_1F8 = 0;
                v62->field_168 = (int)&v62->field_168;
                v62->field_1B8 = (int)&v62->list_1B4;
                v62->field_244 = 0;
                v62->list_1B4 = (stru24_stru160 *)&v62->list_1B4;
                v62->field_204 = (int)&v62->field_200;
                v62->list_310 = 0;
                v62->field_200 = (int)&v62->field_200;
                v62->list_310_2F0 = (stru24_stru310 *)&v62->list_310_2EC;
                v62->field_33C = 0;
                v62->list_310_2EC = (stru24_stru310 *)&v62->list_310_2EC;
                v62->field_31C = (int)&v62->list_318;
                v62->list_318 = (stru24_stru310 *)&v62->list_318;
            }
            else
            {
                *v60 = 0;
                *v80 = 0;
            }
            ++v60;
            v77 = (PLAYER_SIDE)((int)v77 + 1);
            v36 = __OFSUB__(v83 * 4 + 4, 24);
            v35 = v83 * 4 - 20 < 0;
            ++v83;
            ++v80;
            if (!(v35 ^ v36))
                return 1;
        }
    }
    v1 = dword_470510+1;
    if (current_level_idx == LEVEL_MUTE_08_SMASH_THE_CONVOY)// Evolved Mission #8
    {
        do
        {
            if (*v1 == 1)
                ++v0;
            ++v1;
        } while ((int)v1 < (int)&dword_470510[7]);
        _4778C8_singleplayer_available_units_denom = v0;
        v76 = SURVIVORS;
        v79 = cpu_player_scripts_attached_stru24s;
        v38 = &task_ai_players[1];
        v82 = 0;
        do
        {
            if (dword_470510[v82+1] == 1 && dword_464DCC)
            {
                v39 = script_create_function(SCRIPT_TYPE_INVALID, script_42DC70_ai);
                *v38 = v39;
                v39->script_type = SCRIPT_TYPE_39030;
                (*v38)->event_handler = EventHandler_42D6B0_evolved_mission8_ai;
                v40 = (stru24 *)script_create_local_object(*v38, 868);
                memset(v40, 0, sizeof(stru24));
                (*v38)->param = v40;
                *v79 = v40;
                v40->_2A0_player_side = v76;
                v40->_2A8_p_globals_cash = &game_globals_per_player.cash[v82 + 1];
                v41 = _4778C8_singleplayer_available_units_denom;
                game_globals_per_player.cash[v82 + 1] = levels[current_level_idx].evolved_starting_cash;
                v40->list_58_and_70_size = 549 / (v41 + 1);
                v40->field_2B4 = 4;
                v40->field_2B8 = -50;
                v40->_2BC_ai_importance = 0;
                v40->level_field_22_or_2A = levels[current_level_idx].field_22;
                v40->list_260 = (stru24_stru26C *)&v40->list_260;
                v40->list_26C_264 = (stru24_stru26C *)&v40->list_260;
                v40->list_26C = 0;
                v40->list_94_78 = (stru24_stru94 *)&v40->list_94_78;
                v40->list_94_7C = (stru24_stru94 *)&v40->list_94_78;
                v40->list_94 = 0;
                v40->drill_rig_list_9C = (stru24_DrillRigNode *)&v40->drill_rig_list_9C;
                v40->drill_rig_list_A0 = (stru24_DrillRigNode *)&v40->drill_rig_list_9C;
                v40->drill_rig_list = 0;
                v40->tanker_list_DC = (stru24_OilTankerNode *)&v40->tanker_list_DC;
                v40->tanker_list_E0 = (stru24_OilTankerNode *)&v40->tanker_list_DC;
                v40->tanker_list = 0;
                v40->power_plant_list_F4 = (stru24_PowerPlantNode *)&v40->power_plant_list_F4;
                v40->list_104_F8 = (stru24_PowerPlantNode *)&v40->power_plant_list_F4;
                v40->power_plant_list = 0;
                v42 = (stru24_EnemyNode *)malloc(0x1C14u);
                v40->enemy_list = v42;
                if (!v42)
                    return 0;
                v40->enemy_list_free_pool = v42;
                v43 = 0;
                do
                {
                    v40->enemy_list[v43].next = &v40->enemy_list[v43 + 1];
                    ++v43;
                } while (v43 < 598);
                v40->enemy_list[598].next = 0;
                v40->enemy_list_108 = (stru24_EnemyNode *)&v40->enemy_list_108;
                v40->enemy_list_10C = (stru24_EnemyNode *)&v40->enemy_list_108;
                v44 = (stru24_stru160 *)malloc(0x880u);
                v40->list_160 = v44;
                if (!v44)
                    return 0;
                v40->list_160_head = v44;
                v45 = 0;
                do
                {
                    v40->list_160[v45].next = &v40->list_160[v45 + 1];
                    ++v45;
                } while (v45 < 31);
                v40->list_160[31].next = 0;
                v40->list_11C = (stru24_stru160 *)&v40->list_11C;
                v40->list_160_120 = (stru24_stru160 *)&v40->list_11C;
                v46 = (stru24_AttackerNode *)malloc(16 * (v40->list_58_and_70_size + 16));
                v40->marshalling_nodes_list__evmission8_only = v46;
                if (!v46)
                    return 0;
                v40->marshalling_nodes_list__evmission8_only_free_pool = v46;
                v47 = 0;
                if (v40->list_58_and_70_size + 15 > 0)
                {
                    v48 = 0;
                    do
                    {
                        ++v47;
                        v40->marshalling_nodes_list__evmission8_only[v48].next = &v40->marshalling_nodes_list__evmission8_only[v48 + 1];
                        ++v48;
                    } while (v47 < v40->list_58_and_70_size + 15);
                }
                v40->marshalling_nodes_list__evmission8_only[v47].next = 0;
                v40->marshalling_nodes_list__evmission8_only_60 = (stru24_AttackerNode *)&v40->marshalling_nodes_list__evmission8_only_60;
                v40->marshalling_nodes_list__evmission8_only_64 = (stru24_AttackerNode *)&v40->marshalling_nodes_list__evmission8_only_60;
                v49 = (stru24_AttackerNode *)malloc(16 * (v40->list_58_and_70_size + 16));
                v40->attacker_list = v49;
                if (!v49)
                    return 0;
                v50 = v40->list_58_and_70_size;
                v40->attacker_list_free_pool = v49;
                v51 = 0;
                if (v50 + 15 > 0)
                {
                    v52 = 0;
                    do
                    {
                        ++v51;
                        v40->attacker_list[v52].next = &v40->attacker_list[v52 + 1];
                        ++v52;
                    } while (v51 < v40->list_58_and_70_size + 15);
                }
                v40->attacker_list[v51].next = 0;
                v40->attacker_list_4C = (stru24_AttackerNode *)&v40->attacker_list_48;
                v40->attacker_list_48 = (stru24_AttackerNode *)&v40->attacker_list_48;
                v53 = (stru24_stru10_convoy *)malloc(0x2570u);
                v40->list_10_convoy = v53;
                if (!v53)
                    return 0;
                v40->list_10_convoy_head = v53;
                v54 = 0;
                do
                {
                    v40->list_10_convoy[v54].next = &v40->list_10_convoy[v54 + 1];
                    ++v54;
                } while (v54 < 598);
                v40->list_10_convoy[598].next = 0;
                v40->next = v40;
                v40->prev = v40;
                v55 = (stru24_WandererNode *)malloc(0x2570u);
                v40->wanderer_list = v55;
                if (!v55)
                    return 0;
                v40->wanderer_list_free_pool = v55;
                v56 = 0;
                do
                {
                    v40->wanderer_list[v56].next = &v40->wanderer_list[v56 + 1];
                    ++v56;
                } while (v56 < 598);
                v40->wanderer_list[598].next = 0;
                v40->wanderer_list_1C = (stru24_WandererNode *)&v40->wanderer_list_18;
                v40->wanderer_list_18 = (stru24_WandererNode *)&v40->wanderer_list_18;
                v57 = (stru24_stru40 *)malloc(0x2570u);
                v40->list_40 = v57;
                if (!v57)
                    return 0;
                v40->list_40_head = v57;
                v58 = 0;
                do
                {
                    v40->list_40[v58].next = &v40->list_40[v58 + 1];
                    ++v58;
                } while (v58 < 598);
                v40->list_40[598].next = 0;
                v40->list_40_34 = (stru24_stru40 *)&v40->list_40_30;
                v40->field_1AC = 0;
                v40->list_40_30 = (stru24_stru40 *)&v40->list_40_30;
                v40->field_16C = (int)&v40->field_168;
                v40->field_1F8 = 0;
                v40->field_168 = (int)&v40->field_168;
                v40->field_1B8 = (int)&v40->list_1B4;
                v40->field_244 = 0;
                v40->list_1B4 = (stru24_stru160 *)&v40->list_1B4;
                v40->field_204 = (int)&v40->field_200;
                v40->list_310 = 0;
                v40->field_200 = (int)&v40->field_200;
                v40->list_310_2F0 = (stru24_stru310 *)&v40->list_310_2EC;
                v40->field_33C = 0;
                v40->list_310_2EC = (stru24_stru310 *)&v40->list_310_2EC;
                v40->field_31C = (int)&v40->list_318;
                v40->list_318 = (stru24_stru310 *)&v40->list_318;
            }
            else
            {
                *v38 = 0;
                *v79 = 0;
            }
            ++v38;
            v76 = (PLAYER_SIDE)((int)v76 + 1);
            v36 = __OFSUB__(v82 * 4 + 4, 24);
            v35 = v82 * 4 - 20 < 0;
            ++v82;
            ++v79;
        } while (v35 ^ v36);
        result = 1;
    }
    else
    {
        do
        {
            if (*v1 == 1)
                ++v0;
            ++v1;
        } while ((int)v1 < (int)&dword_470510[7]);
        _4778C8_singleplayer_available_units_denom = v0;
        v75 = 1;
        v81 = cpu_player_scripts_attached_stru24s;
        v2 = &task_ai_players[1];
        v78 = 0;
        do
        {
            if (dword_470510[v78+1] == 1 && dword_464DCC)
            {
                v3 = script_create_function(SCRIPT_TYPE_INVALID, script_40B700_ai);
                *v2 = v3;
                v3->script_type = SCRIPT_TYPE_39030;
                (*v2)->event_handler = EventHandler_4089B0_generic_ai;
                v4 = (stru24 *)script_create_local_object(*v2, 868);
                v5 = v4;
                *v81 = v4;
                memset(v4, 0, sizeof(stru24));
                (*v2)->param = v4;
                v6 = (char *)&game_globals_per_player.cash[v78 + 1];
                v5->_2A0_player_side = (PLAYER_SIDE)v75;
                v5->_2A8_p_globals_cash = &game_globals_per_player.cash[v78 + 1];
                if (_47C6D8_use__466098_cost_multipliers)
                {
                    v7 = v5->_2A0_player_side;
                    if (v7 != player_side)
                    {
                        if (game_globals_cpu[0].cash[v7 + 7 * player_side])
                            game_globals_per_player.cash[v7] = 0;
                        else
                            game_globals_per_player.cash[v7] = dword_464DC0[_466098_cost_multiplier_idx];
                    }
                }
                else if (current_level_idx < LEVEL_SURV_16 || current_level_idx > LEVEL_MUTE_25)
                {
                    *(_DWORD *)v6 = levels[current_level_idx].evolved_starting_cash;
                    v5->level_field_22_or_2A = 0;
                    v5->field_360 = 0;
                }
                else if (game_globals_cpu[0].cash[v75 + 7 * player_side])
                {
                    v8 = current_level_idx;
                    *(_DWORD *)v6 = levels[current_level_idx].field_10;
                    v5->level_field_22_or_2A = levels[v8].field_2A;
                    v5->field_360 = levels[current_level_idx].field_28;
                }
                else
                {
                    v9 = current_level_idx;
                    *(_DWORD *)v6 = levels[current_level_idx].evolved_starting_cash;
                    v5->level_field_22_or_2A = levels[v9].field_22;
                    v5->field_360 = levels[current_level_idx].field_20;
                }
                v10 = 4;
                v5->list_58_and_70_size = 549 / (_4778C8_singleplayer_available_units_denom + 1);
                v5->field_2B4 = 200;
                v5->field_2C0 = 0;
                v5->_278_x_offset = -1;
                v11 = (int *)v5->field_280;
                do
                {
                    *v11 = -1;
                    v11 += 2;
                    --v10;
                } while (v10);
                v5->field_2B8 = -50;
                v5->field_250 = 0x40000000;
                v5->field_258 = -1;
                v5->field_254 = 0x40000000;
                v5->field_25C = -1;
                v5->_2BC_ai_importance = 0;
                v12 = (stru24_stru26C *)malloc(0x180u);
                v5->list_26C = v12;
                if (!v12)
                    return 0;
                v5->list_26C_head = v12;
                v13 = 0;
                do
                {
                    v5->list_26C[v13].next = &v5->list_26C[v13 + 1];
                    ++v13;
                } while (v13 < 31);
                v5->list_26C[31].next = 0;
                v5->list_260 = (stru24_stru26C *)&v5->list_260;
                v5->list_26C_264 = (stru24_stru26C *)&v5->list_260;
                v14 = (stru24_AttackerNode *)malloc(16 * (v5->list_58_and_70_size + 16));
                v5->attacker_list = v14;
                if (!v14)
                    return 0;
                v5->attacker_list_free_pool = v14;
                v15 = 0;
                if (v5->list_58_and_70_size + 15 > 0)
                {
                    v16 = 0;
                    do
                    {
                        ++v15;
                        v5->attacker_list[v16].next = &v5->attacker_list[v16 + 1];
                        ++v16;
                    } while (v15 < v5->list_58_and_70_size + 15);
                }
                v5->attacker_list[v15].next = 0;
                v5->attacker_list_48 = (stru24_AttackerNode *)&v5->attacker_list_48;
                v5->attacker_list_4C = (stru24_AttackerNode *)&v5->attacker_list_48;
                v5->marshalling_nodes_list__evmission8_only_60 = (stru24_AttackerNode *)&v5->marshalling_nodes_list__evmission8_only_60;
                v5->marshalling_nodes_list__evmission8_only_64 = (stru24_AttackerNode *)&v5->marshalling_nodes_list__evmission8_only_60;
                v5->marshalling_nodes_list__evmission8_only = 0;
                v5->next = v5;
                v5->prev = v5;
                v5->list_10_convoy = 0;
                v17 = (stru24_stru94 *)malloc(0x380u);
                v5->list_94 = v17;
                if (!v17)
                    return 0;
                v5->list_94_head = v17;
                v18 = 0;
                do
                {
                    v5->list_94[v18].next = &v5->list_94[v18 + 1];
                    ++v18;
                } while (v18 < 31);
                v5->list_94[31].next = 0;
                v5->list_94_78 = (stru24_stru94 *)&v5->list_94_78;
                v5->list_94_7C = (stru24_stru94 *)&v5->list_94_78;
                v19 = (stru24_DrillRigNode *)malloc(0x380u);
                v5->drill_rig_list = v19;
                if (!v19)
                    return 0;
                v5->drill_rig_list_free_pool = v19;
                v20 = 0;
                do
                {
                    v5->drill_rig_list[v20].next = &v5->drill_rig_list[v20 + 1];
                    ++v20;
                } while (v20 < 15);
                v5->drill_rig_list[15].next = 0;
                v5->drill_rig_list_9C = (stru24_DrillRigNode *)&v5->drill_rig_list_9C;
                v5->drill_rig_list_A0 = (stru24_DrillRigNode *)&v5->drill_rig_list_9C;
                v21 = (stru24_OilTankerNode *)malloc(0x200u);
                v5->tanker_list = v21;
                if (!v21)
                    return 0;
                v5->tanker_list_free_pool = v21;
                v22 = 0;
                do
                {
                    v5->tanker_list[v22].next = &v5->tanker_list[v22 + 1];
                    ++v22;
                } while (v22 < 31);
                v5->tanker_list[31].next = 0;
                v5->tanker_list_DC = (stru24_OilTankerNode *)&v5->tanker_list_DC;
                v5->tanker_list_E0 = (stru24_OilTankerNode *)&v5->tanker_list_DC;
                v23 = (stru24_PowerPlantNode *)malloc(0xC0u);
                v5->power_plant_list = v23;
                if (!v23)
                    return 0;
                v5->power_plant_list_free_pool = v23;
                v24 = 0;
                do
                {
                    v5->power_plant_list[v24].next = &v5->power_plant_list[v24 + 1];
                    ++v24;
                } while (v24 < 15);
                v5->power_plant_list[15].next = 0;
                v5->power_plant_list_F4 = (stru24_PowerPlantNode *)&v5->power_plant_list_F4;
                v5->list_104_F8 = (stru24_PowerPlantNode *)&v5->power_plant_list_F4;
                v25 = (stru24_EnemyNode *)malloc(0x1C14u);
                v5->enemy_list = v25;
                if (!v25)
                    return 0;
                v5->enemy_list_free_pool = v25;
                v26 = 0;
                do
                {
                    v5->enemy_list[v26].next = &v5->enemy_list[v26 + 1];
                    ++v26;
                } while (v26 < 598);
                v5->enemy_list[598].next = 0;
                v5->enemy_list_10C = (stru24_EnemyNode *)&v5->enemy_list_108;
                v5->enemy_list_108 = (stru24_EnemyNode *)&v5->enemy_list_108;
                v27 = (stru24_stru160 *)malloc(0x880u);
                v5->list_160 = v27;
                if (!v27)
                    return 0;
                v5->list_160_head = v27;
                v28 = 0;
                do
                {
                    v5->list_160[v28].next = &v5->list_160[v28 + 1];
                    ++v28;
                } while (v28 < 31);
                v5->list_160[31].next = 0;
                v5->list_160_120 = (stru24_stru160 *)&v5->list_11C;
                v5->field_1AC = 0;
                v5->list_11C = (stru24_stru160 *)&v5->list_11C;
                v5->field_16C = (int)&v5->field_168;
                v5->field_1F8 = 0;
                v5->field_168 = (int)&v5->field_168;
                v5->field_1B8 = (int)&v5->list_1B4;
                v5->field_244 = 0;
                v5->list_1B4 = (stru24_stru160 *)&v5->list_1B4;
                v5->field_204 = (int)&v5->field_200;
                v5->field_200 = (int)&v5->field_200;
                v29 = (stru24_stru310 *)malloc(0x900u);
                v5->list_310 = v29;
                if (!v29)
                    return 0;
                v5->list_310_head = v29;
                v30 = 0;
                do
                {
                    v5->list_310[v30].next = &v5->list_310[v30 + 1];
                    ++v30;
                } while (v30 < 63);
                v5->list_310[63].next = 0;
                v5->list_310_2F0 = (stru24_stru310 *)&v5->list_310_2EC;
                v5->field_33C = 0;
                v5->list_310_2EC = (stru24_stru310 *)&v5->list_310_2EC;
                v5->field_31C = (int)&v5->list_318;
                v5->list_318 = (stru24_stru310 *)&v5->list_318;
                v31 = (stru24_WandererNode *)malloc(0x2570u);
                v5->wanderer_list = v31;
                if (!v31)
                    return 0;
                v5->wanderer_list_free_pool = v31;
                v32 = 0;
                do
                {
                    v5->wanderer_list[v32].next = &v5->wanderer_list[v32 + 1];
                    ++v32;
                } while (v32 < 598);
                v5->wanderer_list[598].next = 0;
                v5->wanderer_list_1C = (stru24_WandererNode *)&v5->wanderer_list_18;
                v5->wanderer_list_18 = (stru24_WandererNode *)&v5->wanderer_list_18;
                v33 = (stru24_stru40 *)malloc(0x2570u);
                v5->list_40 = v33;
                if (!v33)
                    return 0;
                v5->list_40_head = v33;
                v34 = 0;
                do
                {
                    v5->list_40[v34].next = &v5->list_40[v34 + 1];
                    ++v34;
                } while (v34 < 598);
                v5->list_40[598].next = 0;
                v5->list_40_34 = (stru24_stru40 *)&v5->list_40_30;
                v5->list_40_30 = (stru24_stru40 *)&v5->list_40_30;
            }
            else
            {
                *v2 = 0;
                *v81 = 0;
            }
            ++v2;
            ++v75;
            v36 = __OFSUB__(v78 * 4 + 4, 24);
            v35 = ((v78 * 4 - 20) & 0x80000000) != 0;
            ++v78;
            ++v81;
        } while (v35 ^ v36);
        result = 1;
    }
    return result;
}

//----- (0040C590) --------------------------------------------------------
void UNIT_FreeAiPlayers()
{
    Script **v0; // edi@1
    Script *v1; // eax@2
    stru24 *v2; // esi@4
    stru24 *v3; // esi@7

    v0 = task_ai_players;
    do
    {
        v1 = *v0;
        if (*v0)
        {
            if (current_level_idx == LEVEL_MUTE_05_AMBUSH)
            {
                v3 = (stru24 *)v1->param;
                free(v3->enemy_list);
                free(v3->attacker_list);
                free(v3->wanderer_list);
                free(v3->list_40);
            }
            else
            {
                v2 = (stru24 *)v1->param;
                if (current_level_idx == LEVEL_MUTE_08_SMASH_THE_CONVOY)
                {
                    free(v2->enemy_list);
                    free(v2->attacker_list);
                    free(v2->marshalling_nodes_list__evmission8_only);
                    free(v2->list_10_convoy);
                    free(v2->list_160);
                    free(v2->wanderer_list);
                    free(v2->list_40);
                }
                else
                {
                    free(v2->list_26C);
                    free(v2->attacker_list);
                    free(v2->list_94);
                    free(v2->drill_rig_list);
                    free(v2->enemy_list);
                    free(v2->list_160);
                    free(v2->tanker_list);
                    free(v2->power_plant_list);
                    free(v2->list_310);
                    free(v2->wanderer_list);
                    free(v2->list_40);
                }
            }
            script_deinit(*v0);
        }
        ++v0;
    } while ((int)v0 < (int)&unk_4778EC);
}

//----- (0042D6B0) --------------------------------------------------------
void EventHandler_42D6B0_evolved_mission8_ai(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param)
{
    stru24 *v4; // esi@1
    stru24_EnemyNode *v5; // eax@4
    stru24_EnemyNode *v6; // edx@8
    stru24_stru10_convoy *v7; // eax@11
    int v8; // eax@16
    stru24_WandererNode *v9; // eax@17
    stru24_WandererNode *v10; // edx@21
    int v11; // eax@24
    stru24_AttackerNode *v12; // eax@24
    enum PLAYER_SIDE v13; // edx@28
    stru24_AttackerNode *v14; // esi@28
    stru24_AttackerNode *v15; // eax@30
    enum PLAYER_SIDE v16; // edx@34
    stru24_AttackerNode *v17; // esi@34
    int v18; // edx@36
    enum PLAYER_SIDE v19; // ecx@37
    stru24_EnemyNode *v20; // eax@38
    stru24_stru10_convoy *v21; // ecx@42
    stru24_stru160 *v22; // edi@42
    stru24_stru160 *v23; // eax@43
    stru24_stru40 *v24; // edx@44
    stru24_stru160 *v25; // edi@45
    void *v26; // ecx@45
    int v27; // ecx@49
    stru24_stru40 *v28; // eax@50
    bool v29; // zf@53
    enum PLAYER_SIDE v30; // ecx@53
    stru24_AttackerNode *v31; // ecx@54
    stru24_stru160 *v32; // edi@54
    int v33; // eax@55
    Sprite *v34; // ecx@56
    stru24_AttackerNode *v35; // eax@62
    stru24_stru10_convoy *v36; // [sp+14h] [bp+4h]@42
    int v37; // [sp+18h] [bp+8h]@42
             // context -> stru24
    v4 = (stru24 *)receiver->param;
    if (event == EVT_MSG_DESELECTED)
    {
        v18 = *((_DWORD *)param + 5);
        if (v18 && (v19 = v4->_2A0_player_side, v18 != v19))
        {
            v20 = (stru24_EnemyNode *)*((_DWORD *)param + v19 + 9);
            if (v20)
            {
                v20->next->prev = v20->prev;
                v20->prev->next = v20->next;
                v20->next = v4->enemy_list_free_pool;
                v4->enemy_list_free_pool = v20;
            }
            else
            {
                show_message_ex(0, aWarningUnreg_0);
            }
        }
        else if (*((_DWORD *)param + 4) == 25)
        {
            v21 = (stru24_stru10_convoy *)*((_DWORD *)param + v4->_2A0_player_side + 9);
            v36 = v21;
            v22 = (stru24_stru160 *)v21->field_C;
            v37 = v21->field_C;
            if (v22)
            {
                v23 = (stru24_stru160 *)v22->_C_next;
                if ((void **)v23 != &v22->_C_next)
                {
                    v24 = (stru24_stru40 *)&v4->list_40_30;
                    do
                    {
                        v25 = v23->prev;
                        v26 = v23->_C_next;
                        v23->next->prev = v25;
                        v23->prev->next = v23->next;
                        *((_DWORD *)v26 + 73) |= 0x80u;
                        *((_DWORD *)v26 + 55) = 0;
                        *((_DWORD *)v26 + 2) = 0;
                        *((_DWORD *)v26 + 56) = 0;
                        v23->field_8 = 0;
                        v23->next = (stru24_stru160 *)v24->next;
                        v23->prev = (stru24_stru160 *)v24;
                        v24->next->prev = (stru24_stru40 *)v23;
                        v24->next = (stru24_stru40 *)v23;
                        v23 = v25->next;
                        v22 = (stru24_stru160 *)v37;
                    } while (v23 != (stru24_stru160 *)(v37 + 12));
                    v21 = v36;
                }
                v22->next->prev = v22->prev;
                v22->prev->next = v22->next;
                v22->next = v4->list_160_head;
                v4->list_160_head = v22;
            }
            v21->next->prev = v21->prev;
            v21->prev->next = v21->next;
            v21->next = v4->list_10_convoy_head;
            v4->list_10_convoy_head = v21;
        }
        else
        {
            v27 = *((_DWORD *)param + 73);
            if (v27 & 0x80)
            {
                v28 = (stru24_stru40 *)*((_DWORD *)param + v4->_2A0_player_side + 9);
                if (v28)
                {
                    v28->next->prev = v28->prev;
                    v28->prev->next = v28->next;
                    v28->next = v4->list_40_head;
                    v4->list_40_head = v28;
                }
                else
                {
                    show_message_ex(0, aWarningUnregis);
                }
            }
            else
            {
                v29 = (BYTE1(v27) & 2) == 0;
                v30 = v4->_2A0_player_side;
                if (v29)
                {
                    v35 = (stru24_AttackerNode *)*((_DWORD *)param + v30 + 9);
                    v35->next->prev = v35->prev;
                    v35->prev->next = v35->next;
                    v35->next = v4->attacker_list_free_pool;
                    v4->attacker_list_free_pool = v35;
                }
                else
                {
                    v31 = (stru24_AttackerNode *)*((_DWORD *)param + v30 + 9);
                    v32 = v31->list_8;
                    if (v32)
                    {
                        v33 = (int)v32->_C_next;
                        if ((void **)v33 != &v32->_C_next)
                        {
                            v34 = v31->entity->sprite;
                            while (v34 != *(Sprite **)(*(_DWORD *)(v33 + 12) + 92))
                            {
                                v33 = *(_DWORD *)v33;
                                if ((void **)v33 == &v32->_C_next)
                                    return;
                            }
                            *(_DWORD *)(*(_DWORD *)v33 + 4) = *(_DWORD *)(v33 + 4);
                            **(_DWORD **)(v33 + 4) = *(_DWORD *)v33;
                            *(_DWORD *)v33 = v32->field_20;
                            v32->field_20 = v33;
                        }
                    }
                    else
                    {
                        v31->next->prev = v31->prev;
                        v31->prev->next = v31->next;
                        v31->next = v4->marshalling_nodes_list__evmission8_only_free_pool;
                        v4->marshalling_nodes_list__evmission8_only_free_pool = v31;
                    }
                }
            }
        }
    }
    else
    {
        if (event != EVT_MSG_1521_entity_created)
            return;
        if (is_enemy(v4->_2A0_player_side, (Entity *)param))
        {
            v5 = v4->enemy_list_free_pool;
            if (v5)
                v4->enemy_list_free_pool = v5->next;
            else
                v5 = 0;
            if (v5)
            {
                *((_DWORD *)param + v4->_2A0_player_side + 9) = (int)v5;
                v5->entity = (Entity *)param;
                v6 = v4->enemy_list_108;
                v5->prev = (stru24_EnemyNode *)&v4->enemy_list_108;
                v5->next = v6;
                v4->enemy_list_108->prev = v5;
                v4->enemy_list_108 = v5;
            }
            else
            {
                show_message_ex(0, aWarningOutOfEnemyNodes);
            }
            return;
        }
        if (*((_DWORD *)param + 4) == 25)
        {
            v7 = v4->list_10_convoy_head;
            if (v7)
                v4->list_10_convoy_head = v7->next;
            else
                v7 = 0;
            if (v7)
            {
                *((_DWORD *)param + v4->_2A0_player_side + 9) = (int)v7;
                v7->_8_entity = (Entity *)param;
                v7->field_C = 0;
                v7->next = (stru24_stru10_convoy *)v4->next;
                v7->prev = (stru24_stru10_convoy *)v4;
                v4->next->prev = (stru24 *)v7;
                v4->next = (stru24 *)v7;
                return;
            }
        LABEL_22:
            show_message_ex(0, aWarningOutOfWa);
            return;
        }
        v8 = *((_DWORD *)param + 75);
        if (v8 > 1)
        {
            v9 = v4->wanderer_list_free_pool;
            if (v9)
                v4->wanderer_list_free_pool = v9->next;
            else
                v9 = 0;
            if (v9)
            {
                *((_DWORD *)param + v4->_2A0_player_side + 9) = (int)v9;
                v9->entity = (Entity *)param;
                v10 = v4->wanderer_list_18;
                v9->prev = (stru24_WandererNode *)&v4->wanderer_list_18;
                v9->next = v10;
                v4->wanderer_list_18->prev = v9;
                v4->wanderer_list_18 = v9;
                return;
            }
            goto LABEL_22;
        }
        if (v8 == 1)
        {
            v11 = *((_DWORD *)param + 73);
            LOBYTE_HEXRAYS(v11) = v11 & 0x7F;
            BYTE1(v11) |= 2u;
            *((_DWORD *)param + 73) = v11;
            v12 = v4->marshalling_nodes_list__evmission8_only_free_pool;
            if (v12)
                v4->marshalling_nodes_list__evmission8_only_free_pool = v12->next;
            else
                v12 = 0;
            if (v12)
            {
                v13 = v4->_2A0_player_side;
                v14 = (stru24_AttackerNode *)&v4->marshalling_nodes_list__evmission8_only_60;
                *((_DWORD *)param + v13 + 9) = (int)v12;
                v12->entity = (Entity *)param;
                v12->list_8 = 0;
                v12->next = v14->next;
                v12->prev = v14;
                v14->next->prev = v12;
                v14->next = v12;
            }
            else
            {
                show_message_ex(0, aWarningOutOfMa);
            }
        }
        else
        {
            v15 = v4->attacker_list_free_pool;
            if (v15)
                v4->attacker_list_free_pool = v15->next;
            else
                v15 = 0;
            if (v15)
            {
                v16 = v4->_2A0_player_side;
                v17 = (stru24_AttackerNode *)&v4->attacker_list_48;
                *((_DWORD *)param + v16 + 9) = (int)v15;
                v15->entity = (Entity *)param;
                v15->list_8 = 0;
                v15->next = v17->next;
                v15->prev = v17;
                v17->next->prev = v15;
                v17->next = v15;
            }
            else
            {
                show_message_ex(0, aWarningOutOfAt);
            }
        }
    }
}

//----- (0042DA90) --------------------------------------------------------
void script_42DA90_ai(Script *a2)
{
    stru24 *v1; // ebx@1
    stru24_AttackerNode *v2; // edi@2
    Entity *v3; // eax@3
    stru24 *v4; // esi@3
    Sprite *v5; // eax@3
    int v6; // ebp@3
    stru24 *i; // eax@3
    Entity *v8; // ecx@4
    Sprite *v9; // ecx@5
    int v10; // ebx@5
    Sprite *v11; // edx@6
    int v12; // ecx@6
    int v13; // edx@8
    int v14; // ebx@8
    int v15; // ecx@10
    stru24_stru160 *v16; // edx@15
    stru24_stru160 *v17; // eax@16
    stru24_stru160 **v18; // ecx@19
    Entity *v19; // eax@21
    Entity *v20; // edx@21
    int v21; // [sp+8h] [bp-18h]@3
    int v22; // [sp+Ch] [bp-14h]@3
    stru24_AttackerNode *v23; // [sp+Ch] [bp-14h]@15
    stru24 *v24; // [sp+10h] [bp-10h]@1
    char *v25; // [sp+14h] [bp-Ch]@2
    enum PLAYER_SIDE v26; // [sp+18h] [bp-8h]@21
    Entity *v27; // [sp+1Ch] [bp-4h]@21

    v1 = (stru24 *)a2->param;
    v24 = v1;
    if (v1->next != v1)
    {
        v2 = v1->marshalling_nodes_list__evmission8_only_60;
        v25 = (char *)&v1->marshalling_nodes_list__evmission8_only_60;
        if ((stru24_AttackerNode **)v2 != &v1->marshalling_nodes_list__evmission8_only_60)
        {
            do
            {
                v3 = v2->entity;
                v4 = 0;
                v22 = 0x7FFFFFFF;
                v3->sprite->field_88_unused = 1;
                v5 = v3->sprite;
                v6 = v5->x;
                v21 = v5->y;
                for (i = v1->next; i != v1; i = i->next)
                {
                    v8 = i->_8_entity;
                    if (!v8->destroyed)
                    {
                        v8->sprite->field_88_unused = 1;
                        v9 = i->_8_entity->sprite;
                        v10 = v9->x;
                        v9->field_88_unused = 1;
                        if (v10 - v6 <= 0)
                        {
                            v11 = i->_8_entity->sprite;
                            v12 = v6 - v11->x;
                        }
                        else
                        {
                            v11 = i->_8_entity->sprite;
                            v12 = v11->x - v6;
                        }
                        v13 = v11->y;
                        v14 = v13 - v21;
                        if (v13 - v21 <= 0)
                            v14 = v21 - v13;
                        v15 = v14 + v12;
                        if (v15 < v22)
                        {
                            v22 = v15;
                            v4 = i;
                        }
                        v1 = v24;
                    }
                }
                if (v4)
                {
                    v23 = v2->prev;
                    v16 = (stru24_stru160 *)v4->struC;
                    if (!v16)
                    {
                        v17 = v1->list_160_head;
                        if (v17)
                        {
                            v4->struC = (stru24_struC *)v17;
                            v1->list_160_head = v1->list_160_head->next;
                        }
                        else
                        {
                            v4->struC = 0;
                        }
                        v18 = (stru24_stru160 **)v4->struC;
                        if (v18)
                        {
                            *v18 = v1->list_11C;
                            v4->struC->field_4 = (int)&v1->list_11C;
                            v1->list_11C->prev = (stru24_stru160 *)v4->struC;
                            v1->list_11C = (stru24_stru160 *)v4->struC;
                            v4->struC->_C_param = &v4->struC->_C_param;
                            v4->struC->field_10 = (int)&v4->struC->_C_param;
                            v4->struC->field_1C = 0;
                        }
                    }
                    v2->list_8 = v16;
                    v19 = v4->_8_entity;
                    v20 = v2->entity;
                    v26 = v1->_2A0_player_side;
                    v27 = v19;
                    script_trigger_event(v19->script, EVT_MSG_1527, &v26, v20->script);
                    v2->next->prev = v2->prev;
                    v2->prev->next = v2->next;
                    v2->next = (stru24_AttackerNode *)v4->struC->_C_param;
                    v2->prev = (stru24_AttackerNode *)&v4->struC->_C_param;
                    *((_DWORD *)v4->struC->_C_param + 1) = (int)v2;
                    v4->struC->_C_param = v2;
                    v2 = v23;
                }
                v2 = v2->next;
            } while ((char *)v2 != v25);
        }
    }
    stru24_42E070(v1);
    script_sleep(a2, 60);
}

//----- (0042DC70) --------------------------------------------------------
void script_42DC70_ai(Script *a1)
{
    a1->handler = script_42DA90_ai;
    script_sleep(a1, 60);
}

//----- (0042DC90) --------------------------------------------------------
void EventHandler_42DC90_evolved_mission5_ai(Script *a1, Script *a2, enum SCRIPT_EVENT event, Entity *param)
{
    stru24 *v4; // esi@1
    stru24_EnemyNode *v5; // eax@4
    stru24_EnemyNode *v6; // edx@8
    stru24_AttackerNode *v7; // eax@11
    stru24_AttackerNode *v8; // edx@15
    stru24_WandererNode *v9; // eax@17
    enum PLAYER_SIDE v10; // ecx@23
    enum PLAYER_SIDE v11; // edx@24
    stru24_EnemyNode *v12; // eax@25
    stru24_AttackerNode *v13; // eax@29
    stru24_stru40 *v14; // eax@32
                        // 40B720: context -> stru24
    v4 = (stru24 *)a1->param;
    if (event == EVT_MSG_DESELECTED)
    {
        v10 = param->player_side;
        if (v10 == 0)
            goto LABEL_37;
        v11 = v4->_2A0_player_side;
        if (v10 != v11)
        {
            v12 = (stru24_EnemyNode *)param->_24_ai_node_per_player_side._0_ai_node_per_player_side[v11];
            if (v12)
            {
                v12->next->prev = v12->prev;
                v12->prev->next = v12->next;
                v12->next = v4->enemy_list_free_pool;
                v4->enemy_list_free_pool = v12;
            }
            else
            {
                show_message_ex(0, aWarningUnreg_0);
            }
            return;
        }
        if (v10)
        {
            v14 = (stru24_stru40 *)param->_24_ai_node_per_player_side._0_ai_node_per_player_side[v4->_2A0_player_side];
            if (v14)
            {
                v14->next->prev = v14->prev;
                v14->prev->next = v14->next;
                v14->next = v4->list_40_head;
                v4->list_40_head = v14;
            }
            else
            {
                show_message_ex(0, aWarningUnreg_2);
            }
        }
        else
        {
        LABEL_37:
            v13 = (stru24_AttackerNode *)param->_24_ai_node_per_player_side._0_ai_node_per_player_side[v4->_2A0_player_side];
            if (v13)
            {
                v13->next->prev = v13->prev;
                v13->prev->next = v13->next;
                v13->next = v4->attacker_list_free_pool;
                v4->attacker_list_free_pool = v13;
            }
            else
            {
                show_message_ex(0, aWarningUnreg_1);
            }
        }
    }
    else if (event == EVT_MSG_1521_entity_created)
    {
        if (is_enemy(v4->_2A0_player_side, param))
        {
            v5 = v4->enemy_list_free_pool;
            if (v5)
                v4->enemy_list_free_pool = v5->next;
            else
                v5 = 0;
            if (v5)
            {
                param->_24_ai_node_per_player_side._0_ai_node_per_player_side[v4->_2A0_player_side] = (int)v5;
                v5->entity = param;
                v6 = v4->enemy_list_108;
                v5->prev = (stru24_EnemyNode *)&v4->enemy_list_108;
                v5->next = v6;
                v4->enemy_list_108->prev = v5;
                v4->enemy_list_108 = v5;
            }
            else
            {
                show_message_ex(0, aWarningOutOfEnemyNodes);
            }
        }
        else if (param->player_side)
        {
            v9 = v4->wanderer_list_free_pool;
            if (v9)
                v4->wanderer_list_free_pool = v9->next;
            else
                v9 = 0;
            if (v9)
            {
                param->_24_ai_node_per_player_side._0_ai_node_per_player_side[v4->_2A0_player_side] = (int)v9;
                v9->entity = param;
                param->_12C_prison_bunker_spawn_type = 2;
                v9->next = v4->wanderer_list_18;
                v9->prev = (stru24_WandererNode *)&v4->wanderer_list_18;
                v4->wanderer_list_18->prev = v9;
                v4->wanderer_list_18 = v9;
            }
            else
            {
                show_message_ex(0, aWarningOutOfWa);
            }
        }
        else
        {
            v7 = v4->attacker_list_free_pool;
            if (v7)
                v4->attacker_list_free_pool = v7->next;
            else
                v7 = 0;
            if (v7)
            {
                param->_24_ai_node_per_player_side._0_ai_node_per_player_side[v4->_2A0_player_side] = (int)v7;
                v7->entity = param;
                v8 = v4->attacker_list_48;
                v7->prev = (stru24_AttackerNode *)&v4->attacker_list_48;
                v7->next = v8;
                v4->attacker_list_48->prev = v7;
                v4->attacker_list_48 = v7;
            }
            else
            {
                show_message_ex(0, aWarningOutOfNe);
            }
        }
    }
}