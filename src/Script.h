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
    void(*handler)(Script *);
};




/* 359 */
struct Script1
{
    enum MOBD_ID mobd_id;
    void(*script_handler)(Script *);
    SCRIPT_ROUTINE_TYPE script_type;
    int field_C;
    int field_10;
    enum UNIT_ID stats_idx;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
};

/* 360 */
struct Script2
{
    enum MOBD_ID mobd_id;
    void(*script_handler)(Script *);
    SCRIPT_ROUTINE_TYPE script_type;
    int field_C;
    int field_10;
    enum UNIT_ID stats_idx;
    int field_18;
    int field_1C;
};

/* 361 */
struct Script3
{
    enum MOBD_ID mobd_id;
    void(*script_handler)(Script *);
    SCRIPT_ROUTINE_TYPE script_type;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    enum UNIT_ID stats_idx;
    int field_24;
    int field_28;
    int field_2C;
};

/* 362 */
struct Script4
{
    enum MOBD_ID mobd_id;
    void(*script_handler)(Script *);
    SCRIPT_ROUTINE_TYPE script_type;
    int field_C;
    int field_10;
    enum UNIT_ID stats_idx;
};




Script *script_execute_list_first();
Script *script_execute_list_end();
bool script_execute_list_prepend(Script *script);

Script *script_create_coroutine_impl(enum SCRIPT_TYPE type, void(*handler)(Script *), int stack_size, const char *debug_handler_name);
#define script_create_coroutine(type, handler, stack_size) script_create_coroutine_impl(type, handler, stack_size, #handler)

bool script_list_alloc(int coroutine_stack_size = 0);
Script *script_create_function(enum SCRIPT_TYPE type, void(*function)(Script *)); // idb
void script_deinit(Script *a1);
int script_445370_yield_to_main_thread(Script *a1, int flags, int a3);
void *script_create_local_object(Script *a1, int size);
void script_free_local_object(Script *a1, void *data); // idb
void script_yield(Script *a1);
void script_list_update();
void script_list_free();



extern Script1 stru_46E5B0;
extern Script2 stru_46E5D8;
extern Script3 stru_46E5F8;
extern Script3 stru_46E628;
extern Script3 stru_46E658;
extern Script3 stru_46E688;
extern Script4 stru_46E6B8;
extern Script4 stru_46E6D0;
extern Script4 stru_46E6E8;
extern Script4 stru_46E700;
extern Script4 stru_46E718;
extern Script4 stru_46E730;
extern Script4 stru_46E748;
extern Script4 stru_46E760;
extern Script4 stru_46E778;
extern Script4 stru_46E790;
extern Script4 stru_46E7A8;
extern Script4 stru_46E7C0;
extern Script4 stru_46E7D8;
extern Script4 stru_46E7F0;
extern Script4 stru_46E808;
extern Script4 stru_46E820;
extern Script4 stru_46E838;
extern Script4 stru_46E850;
extern Script4 stru_46E868;
extern Script4 stru_46E880;
extern Script4 stru_46E898;
extern Script4 stru_46E8B0;
extern Script4 stru_46E8C8;
extern Script4 stru_46E8E0;
extern Script4 stru_46E8F8;
extern Script4 stru_46E910;
extern Script4 stru_46E928;
extern Script4 stru_46E940;
extern Script4 stru_46E958;
extern Script4 stru_46E970;
extern Script4 stru_46E988;
extern Script4 stru_46E9A0;
extern Script4 stru_46E9B8;
extern Script4 stru_46E9D0;
extern Script4 stru_46E9E8;
extern Script4 stru_46EA00;
extern Script4 stru_46EA18;
extern Script4 stru_46EA30;
extern Script4 stru_46EA48;
extern Script4 stru_46EA60;
extern Script4 stru_46EA78;
extern Script4 stru_46EA90;
extern Script4 stru_46EAA8;
extern Script4 stru_46EAC0;
extern Script4 stru_46EAD8;
extern Script4 stru_46EAF0;
extern Script4 stru_46EB08;
extern Script4 stru_46EB20;
extern Script4 stru_46EB38;
extern Script4 stru_46EB50;
extern Script4 stru_46EB68;
extern Script4 stru_46EB80;
extern Script4 stru_46EB98;
extern Script4 stru_46EBB0;
extern Script4 stru_46EBC8;
extern Script4 stru_46EBE0;
extern Script4 stru_46EBF8;
extern Script4 stru_46EC10;
extern Script4 stru_46EC28;
extern Script4 stru_46EC40;
extern Script4 stru_46EC58;
extern Script4 stru_46EC70;
extern Script4 stru_46EC88;
extern Script4 stru_46ECA0;
extern Script4 stru_46ECB8;
extern Script4 stru_46ECD0;
extern Script4 stru_46ECE8;
extern Script4 stru_46ED00;
extern Script4 stru_46ED18;
extern Script4 stru_46ED30;
extern Script4 stru_46ED48;
extern Script4 stru_46ED60;
extern Script4 stru_46ED78;
extern Script4 stru_46ED90;
extern Script4 stru_46EDA8;
extern Script4 stru_46EDC0;
extern Script4 stru_46EDD8;
extern Script4 stru_46EDF0;
extern Script4 stru_46EE08;
extern Script2 stru_46EE20;
extern Script1 stru_46EE40;
extern Script1 stru_46EE68;
extern Script1 stru_46EE90;
extern Script1 stru_46EEB8;
extern Script1 stru_46EEE0;
extern Script1 stru_46EF08;
extern Script1 stru_46EF30;
extern Script1 stru_46EF58;
extern Script1 stru_46EF80;
extern Script1 stru_46EFA8;
extern Script1 stru_46EFD0;
extern Script1 stru_46EFF8;
extern Script1 stru_46F020;
extern Script1 stru_46F048;
extern Script1 stru_46F070;
extern Script1 stru_46F098;
extern Script1 stru_46F0C0;
extern Script1 stru_46F0E8;
extern Script1 stru_46F110;
extern Script1 stru_46F138;
extern Script1 stru_46F160;
extern Script1 stru_46F188;
extern Script1 stru_46F1B0;
extern Script1 stru_46F1D8;
extern Script1 stru_46F200;
extern Script1 stru_46F228;
extern Script1 stru_46F250;
extern Script1 stru_46F278;
extern Script1 stru_46F2A0;
extern Script1 stru_46F2C8;
extern Script1 stru_46F2F0;
extern Script1 stru_46F318;
extern Script1 stru_46F340;
extern Script1 stru_46F368;
extern Script1 stru_46F390;
extern Script1 stru_46F3B8;
extern Script1 stru_46F3E0;
extern Script1 stru_46F408;
extern Script1 stru_46F430;
extern Script1 stru_46F458;
extern Script1 stru_46F480;
extern Script1 stru_46F4A8;
extern Script1 stru_46F4D0;
extern Script1 stru_46F4F8;
extern Script1 stru_46F520;
extern Script1 stru_46F548;
extern Script1 stru_46F570;
extern Script1 stru_46F598;
extern Script1 stru_46F5C0;
extern Script1 stru_46F5E8;
extern Script1 stru_46F610;
extern Script1 stru_46F638;
extern Script1 stru_46F660;
extern Script1 stru_46F688;
extern Script1 stru_46F6B0;
extern Script1 stru_46F6D8;
extern Script1 stru_46F700;
extern Script1 stru_46F728;
extern Script1 stru_46F750;
extern Script1 stru_46F778;
extern Script1 stru_46F7A0;
extern Script1 stru_46F7C8;
extern Script1 stru_46F7F0;
extern Script1 stru_46F818;
extern Script1 stru_46F840;
extern Script1 stru_46F868;
extern Script1 stru_46F890;
extern Script1 stru_46F8B8;
extern Script1 stru_46F8E0;
extern Script1 stru_46F908;
extern Script1 stru_46F930;
extern Script4 stru_46F958;
extern Script4 stru_46F970;
extern Script4 stru_46F988;
extern Script4 stru_46F9A0;
extern Script4 stru_46F9B8;
extern Script4 stru_46F9D0;
extern Script4 stru_46F9E8;
extern Script4 stru_46FA00;
extern Script4 stru_46FA18;
extern Script4 stru_46FA30;
extern Script4 stru_46FA48;
extern Script4 stru_46FA60;
extern Script4 stru_46FA78;
extern Script4 stru_46FA90;
extern Script4 stru_46FAA8;
extern Script4 stru_46FAC0;
extern Script4 stru_46FAD8;
extern Script4 stru_46FAF0;
extern Script4 stru_46FB08;
extern Script4 stru_46FB20;
extern Script4 stru_46FB38;
extern Script4 stru_46FB50;
extern Script4 stru_46FB68;
extern Script4 stru_46FB80;
extern Script4 stru_46FB98;
extern Script4 stru_46FBB0;
extern Script4 stru_46FBC8;
extern Script4 stru_46FBE0;
extern Script4 stru_46FBF8;
extern Script4 stru_46FC10;
extern Script4 stru_46FC28;
extern Script4 stru_46FC40;
extern Script4 stru_46FC58;
extern Script4 stru_46FC70;
extern Script4 stru_46FC88;
extern Script4 stru_46FCA0;
extern Script4 stru_46FCB8;
extern Script4 stru_46FCD0;
extern Script4 stru_46FCE8;

extern Script4 *scripts[196];