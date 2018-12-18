#pragma once

#include "src/Script.h"


/* 365 */
enum SCRIPT_EVENT : __int32
{
    MSG_ATTACKED = 1497,
    EVT_MSG_MISSION_FAILED = 1498,
    EVT_MSG_1499 = 1499,
    EVT_MSG_1500 = 1500,
    CMD_APPLY_DAMAGE = 1503,
    MSG_RECEIVE_EXPERIENCE = 1505,
    EVT_MSG_SABOTAGE = 1506,
    EVT_MSG_1507_stru11 = 1507,
    EVT_MSG_1508 = 1508,
    EVT_MSG_1509_stru11 = 1509,
    EVT_MSG_1510 = 1510,
    EVT_MSG_SELECTED = 1511,
    EVT_MSG_DESELECTED = 1512,
    EVT_MSG_1513 = 1513,
    EVT_MSG_1514 = 1514,
    EVT_MSG_SHOW_UNIT_HINT = 1515,
    EVT_MSG_1516 = 1516,
    EVT_MSG_DESTROY = 1517,
    EVT_MSG_1518 = 1518,
    EVT_MSG_1519 = 1519,
    EVT_MSG_1520 = 1520,
    EVT_MSG_1521_entity_created = 1521,
    EVT_MSG_1522_plan_building_construction = 1522,
    EVT_CMD_ENTITY_ATTACK = 1523,
    EVT_CMD_ENTITY_MOVE = 1524,
    EVT_MSG_1525 = 1525,
    EVT_MSG_1526_infiltrate = 1526,
    EVT_MSG_1527_restart_level = 1527,
    EVT_MSG_1528_cancel = 1528,
    EVT_MSG_NEXT_CONSTRUCTION_STATE = 1529,
    EVT_MSG_1530_OPEN_GAME_MENU = 1530,
    EVT_MSG_1531 = 1531,
    EVT_MSG_1532 = 1532,
    EVT_MSG_1533 = 1533,
    EVT_MSG_PRODUCTION_READY = 1535,
    EVT_MSG_BUILDING_COMPLETE = 1537,
    EVT_MSG_COUNT_BUILDINGS_OF_THE_SAME_TYPE = 1538,
    EVT_MSG_1539 = 1539,
    EVT_MSG_1540 = 1540,
    EVT_MSG_1541_tanker_set_base = 1541,
    EVT_MSG_1542_tanker_set_drillrig = 1542,
    EVT_MSG_UPGRADE_COMPLETE = 1543,
    EVT_MSG_COMMENCE_UPGRADE = 1544,
    EVT_MSG_1545 = 1545,
    EVT_MSG_1546_repair_at_station = 1546,
    EVT_MSG_1547_technician_repair = 1547,
    EVT_MSG_1548_sidebar = 1548,
    EVT_MSG_1549 = 1549,
    EVT_MSG_1551 = 1551,
    EVT_MSG_sound_neg5 = -5,
    EVT_MSG_sound_neg4 = -4,
    EVT_MSG_sound_neg3 = -3,
    EVT_MOUSE_HOVER = -2,
};

/* 67 */
struct ScriptEvent
{
    ScriptEvent *next;
    Script *sender;
    enum SCRIPT_EVENT event;
    void *param;
};


bool script_event_list_alloc();
bool script_trigger_event(Script *sender, enum SCRIPT_EVENT event, void *param, Script *receiver);
bool script_trigger_event_group(Script *sender, enum SCRIPT_EVENT event, void *param, enum SCRIPT_TYPE receiver_type);
ScriptEvent *script_get_next_event(Script *a1);
void script_discard_event(ScriptEvent *a1);
void script_discard_all_events(Script *a1);
void script_event_list_free();



extern ScriptEvent *script_event_list_free_pool;
extern ScriptEvent *script_event_list;