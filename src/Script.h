#pragma once

struct Sprite;

struct ScriptEvent;



/* 367 */
enum SCRIPT_TYPE : unsigned __int32
{
    SCRIPT_TYPE_INVALID = 0,
    SCRIPT_TYPE_1 = 1,
    SCRIPT_TYPE_2 = 2,
    SCRIPT_TYPE_4 = 4,
    SCRIPT_TYPE_5 = 5,
    SCRIPT_TYPE_6 = 6,
    SCRIPT_TYPE_7 = 7,
    SCRIPT_TYPE_8 = 8,
    SCRIPT_TYPE_9 = 9,
    SCRIPT_TYPE_10 = 10,
    SCRIPT_TYPE_13 = 13,
    SCRIPT_TYPE_14 = 14,
    SCRIPT_TYPE_15 = 15,
    SCRIPT_TYPE_16 = 16,
    SCRIPT_TYPE_17 = 17,
    SCRIPT_TYPE_18 = 18,
    SCRIPT_TYPE_19 = 19,
    SCRIPT_TYPE_39030 = 39030,
    SCRIPT_TYPE_47802_fog_of_war = 47802,
    SCRIPT_TYPE_48059 = 48059,
    SCRIPT_TYPE_51914_sidebar = 51914,
    SCRIPT_TYPE_60138_ENTITY_SCRIPTS = 60138,
    SCRIPT_TYPE__C0000000 = 3221225472,
    SCRIPT_SURV_OUTPOST_HANDLER = 3388997632,
    SCRIPT_MUTE_CLANHALL_HANDLER = 3388997633,
    SCRIPT_SURV_MACHINESHOP_HANDLER = 3388997634,
    SCRIPT_MUTE_BLACKSMITH_HANDLER = 3388997636,
    SCRIPT_MUTE_BEAST_ENCLOSURE_HANDLER = 3388997637,
    SCRIPT_REPAIR_STATION_HANDLER = 3388997638,
    SCRIPT_RESEARCH_BUILDING_HANDLER = 3388997642,
    SCRIPT_POWER_STATION_HANDLER = 3388997645,
    SCRIPT_DRILLRIG_HANDLER = 3388997646,
    SCRIPT_TANKER_CONVOY_HANDLER = 3388997647,
    SCRIPT_MOBILE_DERRICK_HANDLER = 0xCA000010,
    SCRIPT_TYPE_CA000012 = 3388997650,
    SCRIPT_UPGRADE_PROCESS = 3388997651,
    SCRIPT_TYPE_CA000014 = 3388997652,
    SCRIPT_TYPE_DA000000 = 3657433088,
    SCRIPT_TYPE_DA000001 = 3657433089,
    SCRIPT_TYPE_DA000002 = 3657433090,
    SCRIPT_TYPE_DA000003 = 3657433091,
    SCRIPT_TYPE_DA000006 = 3657433094,
    SCRIPT_TYPE_DA000007 = 3657433095,
    SCRIPT_TYPE_DA000008 = 3657433096,
    SCRIPT_TYPE_ANY = 0xFFFFFFFF,
};

/* 433 */
enum SCRIPT_ROUTINE_TYPE : __int32
{
    SCRIPT_COROUTINE = 0,
    SCRIPT_FUNCTION = 1,
};

/* 335 */
struct ScriptLocalObject
{
    ScriptLocalObject *next;
    ScriptLocalObject *prev;
    char data;
};

#define SCRIPT_FLAGS_20_X_SPEED_LIMIT 0x8000000
#define SCRIPT_FLAGS_20_Y_SPEED_LIMIT 0x4000000
#define SCRIPT_FLAGS_20_Z_SPEED_LIMIT 0x2000000
/* 72 */
struct Script
{
    Script *next;
    Script *prev;
    ScriptLocalObject *locals_list;
    enum SCRIPT_TYPE script_type;
    int(*mode_turret)(int);
    int field_14;
    SCRIPT_ROUTINE_TYPE routine_type;
    int field_1C;
    int flags_20; // C00000000 - when mouse hovered
    int field_24;
    int field_28;
    int field_2C;
    ScriptEvent *event_list;
    void(*event_handler)(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
    Sprite *sprite;
    void *param;
    void(*handler)(Script *);   // function or class Coroutine

    const char *debug_handler_name;
};



Script *script_execute_list_first();
Script *script_execute_list_end();
bool script_execute_list_prepend(Script *script);

Script *script_create_coroutine(enum SCRIPT_TYPE type, void(*handler)(Script *), int stack_size, const char *debug_handler_name);

bool script_list_alloc(int coroutine_stack_size = 0);
Script *script_create_function(enum SCRIPT_TYPE type, void(*function)(Script *), const char *function_name);
void script_deinit(Script *a1);
int script_445370_yield_to_main_thread(Script *a1, int flags, int a3);
void *script_create_local_object(Script *a1, int size);
void script_free_local_object(Script *a1, void *data); // idb
void script_yield(Script *a1);
void script_list_update();
void script_list_free();


Script *create_script(int script_id);
int get_script_type(int script_id);
enum UNIT_ID get_script_unit_id(int script_id);
enum MOBD_ID get_script_mobd(int script_id);

void *get_handler(int handler_id);
const char *get_handler_name(int handler_id);
int get_handler_id(void *function);