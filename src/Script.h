#pragma once
#include <list>


#define SCRIPT_FLAGS_20_1               0x00000001 // oil related
#define SCRIPT_FLAGS_20_2               0x00000002
#define SCRIPT_FLAGS_20_20000           0x00020000
#define SCRIPT_FLAGS_20_40000           0x00040000
#define SCRIPT_FLAGS_20_80000           0x00080000
#define SCRIPT_FLAGS_20_100000          0x00100000
#define SCRIPT_FLAGS_20_200000          0x00200000
#define SCRIPT_FLAGS_20_400000          0x00400000
#define SCRIPT_FLAGS_20_800000          0x00800000
#define SCRIPT_FLAGS_20_1000000         0x01000000
#define SCRIPT_FLAGS_20_Z_SPEED_LIMIT   0x02000000
#define SCRIPT_FLAGS_20_Y_SPEED_LIMIT   0x04000000
#define SCRIPT_FLAGS_20_X_SPEED_LIMIT   0x08000000
#define SCRIPT_FLAGS_20_10000000        0x10000000  // turret-related
#define SCRIPT_FLAGS_20_TERMINATE       0x20000000  // yield by 00445470 script_terminate 
#define SCRIPT_FLAGS_20_EVENT_TRIGGER   0x40000000  // when script gets triggered by
// script_trigger_event / script_trigger_event_group
// or yielded via script_yield
// with 0x40000000 flag
#define SCRIPT_FLAGS_20_REPEATS_TRIGGER 0x80000000  // when script gets triggered by exhausting _14_num_repeats
#define SCRIPT_FLAGS_20_ANY_TRIGGER     (SCRIPT_FLAGS_20_EVENT_TRIGGER | SCRIPT_FLAGS_20_REPEATS_TRIGGER)


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
    SCRIPT_TYPE_INGAME_MENU_MASTER_SCRIPT = 3657433088,
    SCRIPT_TYPE_UI_SLIDER = 3657433089,
    SCRIPT_TYPE_INGAME_MENU_BUTTON = 3657433090,
    SCRIPT_TYPE_INGAME_MENU_YESNO = 3657433091,
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

struct Script;
typedef void (*ScriptEventHandler)(
    Script *receiver,
    Script *sender,
    enum SCRIPT_EVENT event,
    void *param
);

/* 72 */
struct Script
{
    inline void SetEventHandler(ScriptEventHandler eventHandler) {
        this->event_handler = eventHandler;
    }

    void *next_deprecated; //Script *next;
    void *prev_deprecated; //Script *prev;
    ScriptLocalObject *locals_list;
    enum SCRIPT_TYPE script_type;
    int(*mode_turret)(int);
    int num_runs_to_skip; // decreases with each execution until 0, then SCRIPT_FLAGS_20_REPEATS_TRIGGER
    SCRIPT_ROUTINE_TYPE routine_type;
    int field_1C; // & 1 - speial case when coroutine init failed (depricated)
    int flags_20; // C0000000 - when mouse hovered (SCRIPT_FLAGS_20_EVENT_TRIGGER | SCRIPT_FLAGS_20_REPEATS_TRIGGER)
                  // 20000000 - terminate script
    int flags_24;
    int _28_yield_flags; // flags requested in script_yield
    int field_2C;
    ScriptEvent *event_list;
    ScriptEventHandler event_handler;
    Sprite *sprite;
    void *param;
    void(*handler)(Script *);   // function or class Coroutine

    const char *debug_handler_name;
};

extern std::list<Script*> script_execute_list;

Script *create_script(int script_id);
int get_script_type(int script_id);
enum UNIT_ID get_script_unit_id(int script_id);
enum MOBD_ID get_script_mobd(int script_id);
const char *get_script_name(int script_id);
void *get_handler(int handler_id);
int get_handler_id(void *function);
const char *get_handler_name(int handler_id);
const char *get_handler_name(void *function);

bool script_list_alloc(int coroutine_stack_size = 0);
Script *script_create_coroutine(enum SCRIPT_TYPE type, void(*handler)(Script *), int stack_size);
Script *script_create_function(enum SCRIPT_TYPE type, void(*function)(Script *));
void script_deinit(Script *s);
int script_sleep(Script *s, int num_turns);
int script_wait_event(Script *s);
int script_yield_any_trigger(Script *s, int repeats);
int script_yield(Script *s, int flags, int a3);
void *script_create_local_object(Script *s, int size);
void script_free_local_object(Script *s, void *data); // idb
void script_terminate(Script *s);
void script_list_update();
void script_list_free();