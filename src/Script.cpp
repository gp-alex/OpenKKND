#include <vector>

#include "src/hexrays-defs.h"
#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"

#include "src/Script.h"
#include "src/ScriptEvent.h"
#include "src/kknd.h"
#include "src/Cursor.h"
#include "src/Coroutine.h"
#include "src/Pathfind.h"
#include "src/Map.h"
#include "src/Engine/Entity.h"
#include "src/Application/Scripts/GameMenu.h"
#include "src/Application/Scripts/MainMenu.h"

#define SCRIPT_DESC_HANDLER(x) (void(*)(Script *))x, #x
#define MAKE_HANDLER_PTR(x) { (x), #x }

std::list<Script*> script_execute_list;

/* 359 */
struct ScriptDescType1
{
    enum MOBD_ID mobd_id;
    void(*script_handler)(Script *);
    const char *script_handler_name;
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
struct ScriptDescType2
{
    enum MOBD_ID mobd_id;
    void(*script_handler)(Script *);
    const char *script_handler_name;
    SCRIPT_ROUTINE_TYPE script_type;
    int field_C;
    int field_10;
    enum UNIT_ID stats_idx;
    int field_18;
    int field_1C;
};

/* 361 */
struct ScriptDescType3
{
    enum MOBD_ID mobd_id;
    void(*script_handler)(Script *);
    const char *script_handler_name;
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
struct ScriptDescType4
{
    enum MOBD_ID mobd_id;
    void(*script_handler)(Script *);
    const char *script_handler_name;
    SCRIPT_ROUTINE_TYPE script_type;
    int field_C;
    int field_10;
    enum UNIT_ID stats_idx;
};

struct ScriptHandler 
{
    void *function;
    const char *function_name;
};


ScriptDescType1 stru_46E5B0 = { MOBD_20,                        SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN, 0, 0, 0, 0 };
ScriptDescType2 stru_46E5D8 = { MOBD_20,                        SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN, 0x54, 0 };
ScriptDescType3 stru_46E5F8 = { MOBD_SURV_DETENTION_CENTER,     SCRIPT_DESC_HANDLER(UNIT_Handler_Prison), SCRIPT_FUNCTION, 0, 0, 0, 0, 0, UNIT_STATS_SURV_DETENTION_CENTER, 1, 0, 0 };
ScriptDescType3 stru_46E628 = { MOBD_MUTE_HOLDING_PEN,          SCRIPT_DESC_HANDLER(UNIT_Handler_Prison), SCRIPT_FUNCTION, 0, 0, 0, 0, 0, UNIT_STATS_MUTE_HOLDING_PENS, 2, 0, 0 };
ScriptDescType3 stru_46E658 = { MOBD_MUTE_CLANHALL,             SCRIPT_DESC_HANDLER(UNIT_Handler_Clanhall), SCRIPT_FUNCTION, 0, 0, 0, 0, 0, UNIT_STATS_MUTE_CLANHALL, 2, 0, 0 };
ScriptDescType3 stru_46E688 = { MOBD_SURV_OUTPOST,              SCRIPT_DESC_HANDLER(UNIT_Handler_Outpost), SCRIPT_FUNCTION, 0, 0, 0, 0, 0, UNIT_STATS_SURV_OUTPOST, 1, 0, 0 };
ScriptDescType4 stru_46E6B8 = { MOBD_6_some_letters_and_symbols, SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E6D0 = { MOBD_EXPLOSIONS,                SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E6E8 = { MOBD_23_some_fire_maybe_oil_burn, SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E700 = { MOBD_MISSION_OUTCOME_MODAL,     SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E718 = { MOBD_MUTE_ALCHEMY_HALL,         SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E730 = { MOBD_MUTE_BEAST_ENCLOSURE,      SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E748 = { MOBD_MUTE_BLACKSMITH,           SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E760 = { MOBD_MUTE_CLANHALL,             SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E778 = { MOBD_MUTE_MENAGERIE,            SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E790 = { MOBD_MUTE_POWER_STATION,        SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E7A8 = { MOBD_MUTE_DRILLRIG,             SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E7C0 = { MOBD_MUTE_BERSERKER,            SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E7D8 = { MOBD_MUTE_CRAZY_HARRY,          SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E7F0 = { MOBD_MUTE_CHIEFTAN,             SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E808 = { MOBD_MUTE_PYROMANIAC,           SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E820 = { MOBD_MUTE_RIOTER,               SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E838 = { MOBD_MUTE_BAZOOKA,              SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E850 = { MOBD_MUTE_SHOTGUNNER,           SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E868 = { MOBD_MUTE_MEKANIK,              SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E880 = { MOBD_MUTE_VANDAL,               SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E898 = { MOBD_MUTE_MACHINEGUN_NEST,      SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E8B0 = { MOBD_MUTE_GRAPESHOT_TOWER,      SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E8C8 = { MOBD_MUTE_ROTARY_CANNON,        SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E8E0 = { MOBD_MUTE_GIANT_BEETLE,         SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E8F8 = { MOBD_MUTE_MISSILE_CRAB,         SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E910 = { MOBD_MUTE_MOBILE_DERRICK,       SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E928 = { MOBD_MUTE_DIRE_WOLF,            SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E940 = { MOBD_MUTE_WAR_MASTADONT,        SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E958 = { MOBD_MUTE_MONSTER_TRUCK,        SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E970 = { MOBD_MUTE_GIANT_SCORPION,       SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E988 = { MOBD_MUTE_BIKE_SIDECAR,         SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E9A0 = { MOBD_MUTE_OIL_TANKER,           SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E9B8 = { MOBD_MUTE_WASP,                 SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E9D0 = { MOBD_72_looks_like_acid_spit,   SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46E9E8 = { MOBD_SURV_MACHINE_SHOP,         SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EA00 = { MOBD_SURV_OUTPOST,              SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EA18 = { MOBD_SURV_POWER_STATION,        SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EA30 = { MOBD_SURV_REPAIR_BAY,           SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EA48 = { MOBD_SURV_RESEARCH_LAB,         SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EA60 = { MOBD_SURV_DRILLRIG,             SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EA78 = { MOBD_SURV_BOMBER,               SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EA90 = { MOBD_SURV_GENERAL,              SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EAA8 = { MOBD_SURV_FLAMER,               SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EAC0 = { MOBD_SURV_RPG_LAUNCHER,         SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EAD8 = { MOBD_SURV_SABOTEUR,             SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EAF0 = { MOBD_SURV_SAPPER,               SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EB08 = { MOBD_SURV_SNIPER,               SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EB20 = { MOBD_SURV_SWAT,                 SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EB38 = { MOBD_SURV_TECHNICIAN,           SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EB50 = { MOBD_SURV_RIFLEMAN,             SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EB68 = { MOBD_SURV_CANNON_TOWER,         SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EB80 = { MOBD_SURV_GUARD_TOWER,          SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EB98 = { MOBD_SURV_MISSILE_BATTERY,      SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EBB0 = { MOBD_SURV_4x4_PICKUP,           SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EBC8 = { MOBD_SURV_ATV,                  SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EBE0 = { MOBD_SURV_ANACONDA_TANK,        SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EBF8 = { MOBD_SURV_BARRAGE_CRAFT,        SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EC10 = { MOBD_SURV_DIRT_BIKE,            SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EC28 = { MOBD_SURV_AUTOCANNON_TANK,      SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EC40 = { MOBD_SURV_MOBILE_DERRICK,       SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EC58 = { MOBD_SURV_ATV_FLAMETHROWER,     SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EC70 = { MOBD_SURV_OIL_TANKER,           SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EC88 = { MOBD_GORT,                      SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46ECA0 = { MOBD_PLASMA_TANK,               SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46ECB8 = { MOBD_MECH,                      SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46ECD0 = { MOBD_SENTINEL_DROID,            SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46ECE8 = { MOBD_69,                        SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46ED00 = { MOBD_FONT_ITALIC,               SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 1, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46ED18 = { MOBD_FONT_ITALIC,               SCRIPT_DESC_HANDLER(script_credits_or_custom_mission_briefing_loop), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46ED30 = { MOBD_20,                        SCRIPT_DESC_HANDLER(script_431E60_mobd_20_input), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46ED48 = { MOBD_20,                        SCRIPT_DESC_HANDLER(script_443D40_mobd20), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46ED60 = { MOBD_INGAME_MENU_CONTROLS,      SCRIPT_DESC_HANDLER(script_ingame_menu_master_script), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46ED78 = { MOBD_SIDEBAR_BUTTONS,           SCRIPT_DESC_HANDLER(script_446ED0_sidebar_buttons), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46ED90 = { MOBD_MISSION_OUTCOME_MODAL,     SCRIPT_DESC_HANDLER(script_424CE0_mission_outcome_modal), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EDA8 = { MOBD_CURSORS,                   SCRIPT_DESC_HANDLER(script_game_cursor_handler), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EDC0 = { MOBD_FONT_27,                   SCRIPT_DESC_HANDLER(script_42D030_sidebar_tooltips), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EDD8 = { MOBD_CURSORS,                   SCRIPT_DESC_HANDLER(script_43C040_cursors_handler), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EDF0 = { MOBD_FONT_26,                   SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46EE08 = { MOBD_20,                        SCRIPT_DESC_HANDLER(nullptr), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType2 stru_46EE20 = { MOBD_46,                        SCRIPT_DESC_HANDLER(script_442BB0_mobd46), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN, 0, 0 };
ScriptDescType1 stru_46EE40 = { MOBD_SURV_OIL_TANKER,           SCRIPT_DESC_HANDLER(UNIT_Handler_OilTankerConvoy), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_TANKER_CONVOY, 1, 0, 0, 0 };
ScriptDescType1 stru_46EE68 = { MOBD_SURV_GENERAL,              SCRIPT_DESC_HANDLER(UNIT_Handler_General), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_GENERAL, 0, 0, 0, 0 };
ScriptDescType1 stru_46EE90 = { MOBD_HUT,                       SCRIPT_DESC_HANDLER(UNIT_Handler_Hut), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_HUT, 2, 0, 0, 0 };
ScriptDescType1 stru_46EEB8 = { MOBD_TECH_BUNKER,               SCRIPT_DESC_HANDLER(UNIT_Handler_TechBunker_2), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_TECH_BUNKER, 0, 9, 0, 0 };
ScriptDescType1 stru_46EEE0 = { MOBD_20,                        SCRIPT_DESC_HANDLER(script_424BF0_mobd_20_handler), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_LAST, 0, 0, 0, 0 };
ScriptDescType1 stru_46EF08 = { MOBD_MUTE_ALCHEMY_HALL,         SCRIPT_DESC_HANDLER(UNIT_Handler_ResearchBuilding), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_ALCHEMY_HALL, 2, 0, 0, 0 };
ScriptDescType1 stru_46EF30 = { MOBD_MUTE_BEAST_ENCLOSURE,      SCRIPT_DESC_HANDLER(UNIT_Handler_BeastEnclosure), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_BEAST_ENCLOSURE, 2, 0, 0, 0 };
ScriptDescType1 stru_46EF58 = { MOBD_MUTE_BLACKSMITH,           SCRIPT_DESC_HANDLER(UNIT_Handler_Blacksmith), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_BLACKSMITH, 2, 0, 0, 0 };
ScriptDescType1 stru_46EF80 = { MOBD_MUTE_MENAGERIE,            SCRIPT_DESC_HANDLER(UNIT_Handler_RepairStation), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_MENAGERIE, 2, 0, 0, 0 };
ScriptDescType1 stru_46EFA8 = { MOBD_MUTE_POWER_STATION,        SCRIPT_DESC_HANDLER(UNIT_Handler_PowerStation), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_POWER_STATION, 2, 0, 0, 0 };
ScriptDescType1 stru_46EFD0 = { MOBD_MUTE_DRILLRIG,             SCRIPT_DESC_HANDLER(UNIT_Handler_DrillRig), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_DRILL_RIG, 2, 0, 0, 0 };
ScriptDescType1 stru_46EFF8 = { MOBD_MUTE_BERSERKER,            SCRIPT_DESC_HANDLER(UNIT_Handler_Infantry), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_BERSERKER, 2, 0, 0, 0 };
ScriptDescType1 stru_46F020 = { MOBD_MUTE_CRAZY_HARRY,          SCRIPT_DESC_HANDLER(UNIT_Handler_Infantry), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_CRAZY_HARRY, 2, 0, 0, 0 };
ScriptDescType1 stru_46F048 = { MOBD_MUTE_CHIEFTAN,             SCRIPT_DESC_HANDLER(UNIT_Handler_Infantry), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_KING_ZOG, 2, 0, 0, 0 };
ScriptDescType1 stru_46F070 = { MOBD_MUTE_PYROMANIAC,           SCRIPT_DESC_HANDLER(UNIT_Handler_Infantry), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_PYROMANIAC, 2, 0, 0, 0 };
ScriptDescType1 stru_46F098 = { MOBD_MUTE_RIOTER,               SCRIPT_DESC_HANDLER(UNIT_Handler_Infantry), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_RIOTER, 2, 0, 0, 0 };
ScriptDescType1 stru_46F0C0 = { MOBD_MUTE_BAZOOKA,              SCRIPT_DESC_HANDLER(UNIT_Handler_Infantry), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_BAZOOKA, 2, 0, 0, 0 };
ScriptDescType1 stru_46F0E8 = { MOBD_MUTE_SHOTGUNNER,           SCRIPT_DESC_HANDLER(UNIT_Handler_Infantry), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_SHOTGUNNER, 2, 0, 0, 0 };
ScriptDescType1 stru_46F110 = { MOBD_MUTE_MEKANIK,              SCRIPT_DESC_HANDLER(UNIT_Handler_Infantry), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_MEKANIK, 2, 0, 0, 0 };
ScriptDescType1 stru_46F138 = { MOBD_MUTE_VANDAL,               SCRIPT_DESC_HANDLER(UNIT_Handler_Infantry), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_VANDAL, 2, 0, 0, 0 };
ScriptDescType1 stru_46F160 = { MOBD_MUTE_CHIEFTAN,             SCRIPT_DESC_HANDLER(UNIT_Handler_Infantry), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_WARLORD, 2, 0xFFFF, 0, 0 };
ScriptDescType1 stru_46F188 = { MOBD_MUTE_OIL_TANKER,           SCRIPT_DESC_HANDLER(UNIT_Handler_Scout), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_TANKER, 0, 0, 0, 0 };
ScriptDescType1 stru_46F1B0 = { MOBD_MUTE_MACHINEGUN_NEST,      SCRIPT_DESC_HANDLER(UNIT_Handler_GuardTower), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_MACHINEGUN_NEST, 2, 0, 0, 0 };
ScriptDescType1 stru_46F1D8 = { MOBD_MUTE_GRAPESHOT_TOWER,      SCRIPT_DESC_HANDLER(UNIT_Handler_GuardTower), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_GRAPESHOT_TOWER, 2, 0, 0, 0 };
ScriptDescType1 stru_46F200 = { MOBD_MUTE_ROTARY_CANNON,        SCRIPT_DESC_HANDLER(UNIT_Handler_GuardTower), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_ROTARY_CANNON, 2, 0, 0, 0 };
ScriptDescType1 stru_46F228 = { MOBD_MUTE_GIANT_BEETLE,         SCRIPT_DESC_HANDLER(UNIT_Handler_Vehicle), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_GIANT_BEETLE, 2, 0, 0, 0 };
ScriptDescType1 stru_46F250 = { MOBD_MUTE_MISSILE_CRAB,         SCRIPT_DESC_HANDLER(UNIT_Handler_Vehicle), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_MISSILE_CRAB, 2, 0, 0, 0 };
ScriptDescType1 stru_46F278 = { MOBD_MUTE_MOBILE_DERRICK,       SCRIPT_DESC_HANDLER(UNIT_Handler_MobileDerrick), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_MOBILE_DERRICK, 2, 0, 0, 0 };
ScriptDescType1 stru_46F2A0 = { MOBD_MUTE_DIRE_WOLF,            SCRIPT_DESC_HANDLER(UNIT_Handler_Vehicle), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_DIRE_WOLF, 2, 0, 0, 0 };
ScriptDescType1 stru_46F2C8 = { MOBD_MUTE_WAR_MASTADONT,        SCRIPT_DESC_HANDLER(UNIT_Handler_Vehicle), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_WAR_MASTADONT, 2, 0, 0, 0 };
ScriptDescType1 stru_46F2F0 = { MOBD_MUTE_CLANHALL_WAGON,       SCRIPT_DESC_HANDLER(UNIT_Handler_MobileOutpost), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_CLANHALL_WAGON, 0, 0, 0, 0 };
ScriptDescType1 stru_46F318 = { MOBD_MUTE_MONSTER_TRUCK,        SCRIPT_DESC_HANDLER(UNIT_Handler_Vehicle), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MONSTER_TRUCK, 2, 0, 0, 0 };
ScriptDescType1 stru_46F340 = { MOBD_MUTE_GIANT_SCORPION,       SCRIPT_DESC_HANDLER(UNIT_Handler_Vehicle), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_GIANT_SCORPION, 2, 0, 0, 0 };
ScriptDescType1 stru_46F368 = { MOBD_MUTE_BIKE_SIDECAR,         SCRIPT_DESC_HANDLER(UNIT_Handler_Vehicle), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_BIKE_AND_SIDECAR, 2, 0, 0, 0 };
ScriptDescType1 stru_46F390 = { MOBD_MUTE_OIL_TANKER,           SCRIPT_DESC_HANDLER(UNIT_Handler_OilTanker), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_TANKER, 2, 0, 0, 0 };
ScriptDescType1 stru_46F3B8 = { MOBD_MUTE_WASP,                 SCRIPT_DESC_HANDLER(nullptr), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MUTE_WASP, 1, 0, 0, 0 };
ScriptDescType1 stru_46F3E0 = { MOBD_20,                        SCRIPT_DESC_HANDLER(task_4269B0_mobd_20_handler), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_LAST, 0, 0, 0, 0 };
ScriptDescType1 stru_46F408 = { MOBD_OIL_PATCH,                 SCRIPT_DESC_HANDLER(UNIT_Handler_OilPatch), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_LAST, 0, 0, 0, 0 };
ScriptDescType1 stru_46F430 = { MOBD_SURV_ANACONDA_TANK,        SCRIPT_DESC_HANDLER(UNIT_Handler_Vehicle), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_ANACONDA_TANK, 1, 0, 0, 0 };
ScriptDescType1 stru_46F458 = { MOBD_SURV_MACHINE_SHOP,         SCRIPT_DESC_HANDLER(UNIT_Handler_MachineShop), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_MACHINE_SHOP, 1, 0, 0, 0 };
ScriptDescType1 stru_46F480 = { MOBD_SURV_POWER_STATION,        SCRIPT_DESC_HANDLER(UNIT_Handler_PowerStation), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_POWER_STATION, 1, 0, 0, 0 };
ScriptDescType1 stru_46F4A8 = { MOBD_SURV_REPAIR_BAY,           SCRIPT_DESC_HANDLER(UNIT_Handler_RepairStation), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_REPAIR_BAY, 1, 0, 0, 0 };
ScriptDescType1 stru_46F4D0 = { MOBD_SURV_RESEARCH_LAB,         SCRIPT_DESC_HANDLER(UNIT_Handler_ResearchBuilding), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_RESEARCH_LAB, 1, 0, 0, 0 };
ScriptDescType1 stru_46F4F8 = { MOBD_SURV_DRILLRIG,             SCRIPT_DESC_HANDLER(UNIT_Handler_DrillRig), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_DRILL_RIG, 1, 0, 0, 0 };
ScriptDescType1 stru_46F520 = { MOBD_SURV_GENERAL,              SCRIPT_DESC_HANDLER(UNIT_Handler_Infantry), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_EL_PRESIDENTE, 1, 0, 0, 0 };
ScriptDescType1 stru_46F548 = { MOBD_SURV_FLAMER,               SCRIPT_DESC_HANDLER(UNIT_Handler_Infantry), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_FLAMER, 1, 0, 0, 0 };
ScriptDescType1 stru_46F570 = { MOBD_SURV_RPG_LAUNCHER,         SCRIPT_DESC_HANDLER(UNIT_Handler_Infantry), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_RPG_LAUNCHER, 1, 0, 0, 0 };
ScriptDescType1 stru_46F598 = { MOBD_SURV_SABOTEUR,             SCRIPT_DESC_HANDLER(UNIT_Handler_Infantry), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_SABOTEUR, 1, 0, 0, 0 };
ScriptDescType1 stru_46F5C0 = { MOBD_SURV_SAPPER,               SCRIPT_DESC_HANDLER(UNIT_Handler_Infantry), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_SAPPER, 1, 0, 0, 0 };
ScriptDescType1 stru_46F5E8 = { MOBD_SURV_SNIPER,               SCRIPT_DESC_HANDLER(UNIT_Handler_Infantry), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_SNIPER, 1, 0, 0, 0 };
ScriptDescType1 stru_46F610 = { MOBD_SURV_SWAT,                 SCRIPT_DESC_HANDLER(UNIT_Handler_Infantry), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_SWAT, 1, 0, 0, 0 };
ScriptDescType1 stru_46F638 = { MOBD_SURV_TECHNICIAN,           SCRIPT_DESC_HANDLER(UNIT_Handler_Infantry), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_TECHNICIAN, 1, 0, 0, 0 };
ScriptDescType1 stru_46F660 = { MOBD_SURV_RIFLEMAN,             SCRIPT_DESC_HANDLER(UNIT_Handler_Infantry), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_RIFLEMAN, 1, 0, 0, 0 };
ScriptDescType1 stru_46F688 = { MOBD_SURV_RIFLEMAN,             SCRIPT_DESC_HANDLER(UNIT_Handler_Scout), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_SCOUT, 0, 0, 0, 0 };
ScriptDescType1 stru_46F6B0 = { MOBD_SURV_CANNON_TOWER,         SCRIPT_DESC_HANDLER(UNIT_Handler_GuardTower), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_CANNON_TOWER, 1, 0, 0, 0 };
ScriptDescType1 stru_46F6D8 = { MOBD_SURV_GUARD_TOWER,          SCRIPT_DESC_HANDLER(UNIT_Handler_GuardTower), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_GUARD_TOWER, 1, 0, 0, 0 };
ScriptDescType1 stru_46F700 = { MOBD_SURV_MISSILE_BATTERY,      SCRIPT_DESC_HANDLER(UNIT_Handler_GuardTower), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_MISSILE_BATTERY, 1, 0, 0, 0 };
ScriptDescType1 stru_46F728 = { MOBD_SURV_4x4_PICKUP,           SCRIPT_DESC_HANDLER(UNIT_Handler_Vehicle), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_4x4_PICKUP, 1, 0, 0, 0 };
ScriptDescType1 stru_46F750 = { MOBD_SURV_ATV,                  SCRIPT_DESC_HANDLER(UNIT_Handler_Vehicle), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_ATV, 1, 0, 0, 0 };
ScriptDescType1 stru_46F778 = { MOBD_SURV_BARRAGE_CRAFT,        SCRIPT_DESC_HANDLER(UNIT_Handler_Vehicle), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_BARRAGE_CRAFT, 1, 0, 0, 0 };
ScriptDescType1 stru_46F7A0 = { MOBD_SURV_DIRT_BIKE,            SCRIPT_DESC_HANDLER(UNIT_Handler_Vehicle), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_DIRT_BIKE, 1, 0, 0, 0 };
ScriptDescType1 stru_46F7C8 = { MOBD_SURV_AUTOCANNON_TANK,      SCRIPT_DESC_HANDLER(UNIT_Handler_Vehicle), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_AUTOCANNON_TANK, 1, 0, 0, 0 };
ScriptDescType1 stru_46F7F0 = { MOBD_SURV_MOBILE_DERRICK,       SCRIPT_DESC_HANDLER(UNIT_Handler_MobileDerrick), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_MOBILE_DERRICK, 1, 0, 0, 0 };
ScriptDescType1 stru_46F818 = { MOBD_SURV_ATV_FLAMETHROWER,     SCRIPT_DESC_HANDLER(UNIT_Handler_Vehicle), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_ATV_FLAMETHROWER, 1, 0, 0, 0 };
ScriptDescType1 stru_46F840 = { MOBD_SURV_MOBILE_OUTPOST,       SCRIPT_DESC_HANDLER(UNIT_Handler_MobileOutpost), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_MOBILE_OUTPOST, 1, 0, 0, 0 };
ScriptDescType1 stru_46F868 = { MOBD_SURV_OIL_TANKER,           SCRIPT_DESC_HANDLER(UNIT_Handler_OilTanker), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SURV_TANKER, 1, 0, 0, 0 };
ScriptDescType1 stru_46F890 = { MOBD_TECH_BUNKER,               SCRIPT_DESC_HANDLER(UNIT_Handler_TechBunker), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_TECH_BUNKER, 0, 0, 0, 0 };
ScriptDescType1 stru_46F8B8 = { MOBD_GORT,                      SCRIPT_DESC_HANDLER(UNIT_Handler_Vehicle), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_GORT, 1, 0, 0, 0 };
ScriptDescType1 stru_46F8E0 = { MOBD_PLASMA_TANK,               SCRIPT_DESC_HANDLER(UNIT_Handler_Vehicle), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_PLASMA_TANK, 1, 0, 0, 0 };
ScriptDescType1 stru_46F908 = { MOBD_MECH,                      SCRIPT_DESC_HANDLER(UNIT_Handler_Vehicle), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_MECH, 1, 0, 0, 0 };
ScriptDescType1 stru_46F930 = { MOBD_SENTINEL_DROID,            SCRIPT_DESC_HANDLER(UNIT_Handler_Vehicle), SCRIPT_FUNCTION, 0, 0, UNIT_STATS_SENTINEL_DROID, 1, 0, 0, 0 };
ScriptDescType4 stru_46F958 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_main_menu_kaos_allies), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46F970 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_main_menu_kaos_difficulty), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46F988 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43D740_mobd45_evt17), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46F9A0 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43E470_mobd45_modems), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46F9B8 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43E230_mobd45_modems), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46F9D0 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43D890_mobd45), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46F9E8 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43E670_mobd45), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FA00 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43E7B0_mobd45), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FA18 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43E820_mobd45), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FA30 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_main_menu_play_mission_cancel), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FA48 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_main_menu_play_mission_ok), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FA60 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_main_menu_play_mission_faction_toggle), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FA78 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43F670_mobd45), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FA90 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43ED60_mobd45_modems), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FAA8 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43F0E0_mobd45_modems), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FAC0 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43F520_mobd45), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FAD8 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43EE90_mobd45), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FAF0 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43F330_mobd45), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FB08 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_main_menu_multiplayer_cancel), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FB20 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_main_menu_multiplayer_ipx), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FB38 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_main_menu_multiplayer_modem), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FB50 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_main_menu_multiplayer_serial), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FB68 = { MOBD_45,                        SCRIPT_DESC_HANDLER(nullsub_1), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FB80 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_main_menu_new_campaign_cancel), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FB98 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_main_menu_new_campaign_mute), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FBB0 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_main_menu_new_campaign_surv), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FBC8 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43FDE0_mobd45), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FBE0 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43FF30_mobd45), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FBF8 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_4402A0_mobd45_evt5), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FC10 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_442580_mobd45_evt17), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FC28 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_4428C0_mobd45_evt6), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FC40 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_main_menu_create_kaos_dialog), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FC58 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_main_menu_kaos_cancel), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FC70 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_main_menu_kaos_start), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FC88 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_4426D0_mobd45_evt6), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FCA0 = { MOBD_79,                        SCRIPT_DESC_HANDLER(script_main_menu_quit), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FCB8 = { MOBD_79,                        SCRIPT_DESC_HANDLER(script_main_menu_load), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FCD0 = { MOBD_79,                        SCRIPT_DESC_HANDLER(script_main_menu_multiplayer), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FCE8 = { MOBD_79,                        SCRIPT_DESC_HANDLER(script_main_menu_new_campaign), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };

ScriptDescType4 *scripts[] = 
{
    (ScriptDescType4 *)&stru_46E5B0,
    (ScriptDescType4 *)&stru_46E5D8,
    (ScriptDescType4 *)&stru_46E5F8,
    (ScriptDescType4 *)&stru_46E628,
    (ScriptDescType4 *)&stru_46E658,
    (ScriptDescType4 *)&stru_46E688,
    &stru_46E6B8,
    &stru_46E6D0,
    &stru_46E6E8,
    &stru_46E700,
    &stru_46E718,
    &stru_46E730,
    &stru_46E748,
    &stru_46E760,
    &stru_46E778,
    &stru_46E790,
    &stru_46E7A8,
    &stru_46E7C0,
    &stru_46E7D8,
    &stru_46E7F0,
    &stru_46E808,
    &stru_46E820,
    &stru_46E838,
    &stru_46E850,
    &stru_46E868,
    &stru_46E880,
    &stru_46E898,
    &stru_46E8B0,
    &stru_46E8C8,
    &stru_46E8E0,
    &stru_46E8F8,
    &stru_46E910,
    &stru_46E928,
    &stru_46E940,
    &stru_46E958,
    &stru_46E970,
    &stru_46E988,
    &stru_46E9A0,
    &stru_46E9B8,
    &stru_46E9D0,
    &stru_46E9E8,
    &stru_46EA00,
    &stru_46EA18,
    &stru_46EA30,
    &stru_46EA48,
    &stru_46EA60,
    &stru_46EA78,
    &stru_46EA90,
    &stru_46EAA8,
    &stru_46EAC0,
    &stru_46EAD8,
    &stru_46EAF0,
    &stru_46EB08,
    &stru_46EB20,
    &stru_46EB38,
    &stru_46EB50,
    &stru_46EB68,
    &stru_46EB80,
    &stru_46EB98,
    &stru_46EBB0,
    &stru_46EBC8,
    &stru_46EBE0,
    &stru_46EBF8,
    &stru_46EC10,
    &stru_46EC28,
    &stru_46EC40,
    &stru_46EC58,
    &stru_46EC70,
    &stru_46EC88,
    &stru_46ECA0,
    &stru_46ECB8,
    &stru_46ECD0,
    &stru_46ECE8,
    &stru_46ED00,
    &stru_46ED18,
    &stru_46ED30,
    &stru_46ED48,
    &stru_46ED60,
    &stru_46ED78,
    &stru_46ED90,
    &stru_46EDA8, // 80
    &stru_46EDC0,
    &stru_46EDD8,
    &stru_46EDF0,
    &stru_46EE08,
    (ScriptDescType4 *)&stru_46EE20, // 85
    (ScriptDescType4 *)&stru_46EE40, // 86
    (ScriptDescType4 *)&stru_46EE68,
    (ScriptDescType4 *)&stru_46EE90,
    (ScriptDescType4 *)&stru_46EEB8,
    (ScriptDescType4 *)&stru_46EEE0,
    (ScriptDescType4 *)&stru_46EF08,
    (ScriptDescType4 *)&stru_46EF30,
    (ScriptDescType4 *)&stru_46EF58,
    (ScriptDescType4 *)&stru_46EF80,
    (ScriptDescType4 *)&stru_46EFA8,
    (ScriptDescType4 *)&stru_46EFD0,
    (ScriptDescType4 *)&stru_46EFF8,
    (ScriptDescType4 *)&stru_46F020,
    (ScriptDescType4 *)&stru_46F048,
    (ScriptDescType4 *)&stru_46F070,
    (ScriptDescType4 *)&stru_46F098,
    (ScriptDescType4 *)&stru_46F0C0,
    (ScriptDescType4 *)&stru_46F0E8,
    (ScriptDescType4 *)&stru_46F110,
    (ScriptDescType4 *)&stru_46F138,
    (ScriptDescType4 *)&stru_46F160,
    (ScriptDescType4 *)&stru_46F188,
    (ScriptDescType4 *)&stru_46F1B0,
    (ScriptDescType4 *)&stru_46F1D8,
    (ScriptDescType4 *)&stru_46F200,
    (ScriptDescType4 *)&stru_46F228,
    (ScriptDescType4 *)&stru_46F250,
    (ScriptDescType4 *)&stru_46F278,
    (ScriptDescType4 *)&stru_46F2A0,
    (ScriptDescType4 *)&stru_46F2C8,
    (ScriptDescType4 *)&stru_46F2F0,
    (ScriptDescType4 *)&stru_46F318,
    (ScriptDescType4 *)&stru_46F340,
    (ScriptDescType4 *)&stru_46F368,
    (ScriptDescType4 *)&stru_46F390,
    (ScriptDescType4 *)&stru_46F3B8,
    (ScriptDescType4 *)&stru_46F3E0,
    (ScriptDescType4 *)&stru_46F408,
    (ScriptDescType4 *)&stru_46F430,
    (ScriptDescType4 *)&stru_46F458,
    (ScriptDescType4 *)&stru_46F480,
    (ScriptDescType4 *)&stru_46F4A8,
    (ScriptDescType4 *)&stru_46F4D0,
    (ScriptDescType4 *)&stru_46F4F8,
    (ScriptDescType4 *)&stru_46F520,
    (ScriptDescType4 *)&stru_46F548,
    (ScriptDescType4 *)&stru_46F570,
    (ScriptDescType4 *)&stru_46F598,
    (ScriptDescType4 *)&stru_46F5C0,
    (ScriptDescType4 *)&stru_46F5E8,
    (ScriptDescType4 *)&stru_46F610,
    (ScriptDescType4 *)&stru_46F638,
    (ScriptDescType4 *)&stru_46F660,
    (ScriptDescType4 *)&stru_46F688,
    (ScriptDescType4 *)&stru_46F6B0,
    (ScriptDescType4 *)&stru_46F6D8,
    (ScriptDescType4 *)&stru_46F700,
    (ScriptDescType4 *)&stru_46F728,
    (ScriptDescType4 *)&stru_46F750,
    (ScriptDescType4 *)&stru_46F778,
    (ScriptDescType4 *)&stru_46F7A0,
    (ScriptDescType4 *)&stru_46F7C8,
    (ScriptDescType4 *)&stru_46F7F0,
    (ScriptDescType4 *)&stru_46F818,
    (ScriptDescType4 *)&stru_46F840,
    (ScriptDescType4 *)&stru_46F868,
    (ScriptDescType4 *)&stru_46F890,
    (ScriptDescType4 *)&stru_46F8B8,
    (ScriptDescType4 *)&stru_46F8E0,
    (ScriptDescType4 *)&stru_46F908,
    (ScriptDescType4 *)&stru_46F930, // 156
    &stru_46F958,
    &stru_46F970,
    &stru_46F988,
    &stru_46F9A0,
    &stru_46F9B8,
    &stru_46F9D0,
    &stru_46F9E8,
    &stru_46FA00,
    &stru_46FA18,
    &stru_46FA30,
    &stru_46FA48,
    &stru_46FA60,
    &stru_46FA78,
    &stru_46FA90,
    &stru_46FAA8,
    &stru_46FAC0,
    &stru_46FAD8,
    &stru_46FAF0,
    &stru_46FB08,
    &stru_46FB20,
    &stru_46FB38,
    &stru_46FB50,
    &stru_46FB68,
    &stru_46FB80,
    &stru_46FB98,
    &stru_46FBB0,
    &stru_46FBC8,
    &stru_46FBE0,
    &stru_46FBF8,
    &stru_46FC10,
    &stru_46FC28,
    &stru_46FC40,
    &stru_46FC58,
    &stru_46FC70,
    &stru_46FC88,
    &stru_46FCA0,
    &stru_46FCB8,
    &stru_46FCD0,
    &stru_46FCE8,
};

ScriptHandler script_handlers[] =
{
    MAKE_HANDLER_PTR(UNIT_Handler_Outpost),
    MAKE_HANDLER_PTR(UNIT_Handler_OilTanker),
    MAKE_HANDLER_PTR(UNIT_Handler_MachineShop),
    MAKE_HANDLER_PTR(UNIT_Handler_Clanhall),
    MAKE_HANDLER_PTR(UNIT_Handler_BeastEnclosure),
    MAKE_HANDLER_PTR(UNIT_Handler_PowerStation),
    MAKE_HANDLER_PTR(UNIT_Handler_DrillRig),
    MAKE_HANDLER_PTR(UNIT_Handler_OilPatch),
    MAKE_HANDLER_PTR(UNIT_Handler_MobileDerrick),
    MAKE_HANDLER_PTR(UNIT_Handler_RepairStation),
    MAKE_HANDLER_PTR(UNIT_Handler_ResearchBuilding),
    MAKE_HANDLER_PTR(UNIT_Handler_ResearchBuilding),
    MAKE_HANDLER_PTR(UNIT_Handler_Blacksmith),
    MAKE_HANDLER_PTR(UNIT_Handler_RepairStation),
    MAKE_HANDLER_PTR(UNIT_Handler_GuardTower),
    MAKE_HANDLER_PTR(UNIT_Handler_GuardTower),
    MAKE_HANDLER_PTR(UNIT_Handler_GuardTower),
    MAKE_HANDLER_PTR(UNIT_Handler_GuardTower),
    MAKE_HANDLER_PTR(UNIT_Handler_GuardTower),
    MAKE_HANDLER_PTR(script_ingame_menu_master_script),
    MAKE_HANDLER_PTR(script_424CE0_mission_outcome_modal),
    MAKE_HANDLER_PTR(script_425400),
    MAKE_HANDLER_PTR(UNIT_Handler_General),
    MAKE_HANDLER_PTR(UNIT_Handler_OilTankerConvoy),
    MAKE_HANDLER_PTR(UNIT_Handler_Scout),
    MAKE_HANDLER_PTR(UNIT_Handler_Prison),
    MAKE_HANDLER_PTR(UNIT_Handler_Prison),
    MAKE_HANDLER_PTR(UNIT_AttachHandler_DockPoint),
    MAKE_HANDLER_PTR(UNIT_Handler_Aircraft),
    MAKE_HANDLER_PTR(EntityTowerAttachment_handler_4010C0),
    MAKE_HANDLER_PTR(EntityTowerAttachment_handler_4010E0),
    MAKE_HANDLER_PTR(EventHandler_Aircraft),
    MAKE_HANDLER_PTR(entity_mode_401480_aircraft),
    MAKE_HANDLER_PTR(entity_401530_aircraft),
    MAKE_HANDLER_PTR(entity_mode_401600_aircraft_stru31),
    MAKE_HANDLER_PTR(entity_mode_401660_aircraft),
    MAKE_HANDLER_PTR(entity_401670_aircraft),
    MAKE_HANDLER_PTR(entity_401680),
    MAKE_HANDLER_PTR(entity_mode_4016B0_aircraft),
    MAKE_HANDLER_PTR(entity_yield_40_repeats),
    MAKE_HANDLER_PTR(entity_mode_401800_aircraft),
    MAKE_HANDLER_PTR(UNIT_DmgHandler_Bomber),
    MAKE_HANDLER_PTR(Task_context_1_BomberDmgHandler_401D10),
    MAKE_HANDLER_PTR(Task_context_1_BomberDmgHandler_401D30),
    MAKE_HANDLER_PTR(Task_context_1_BomberDmgHandler_401DC0),
    MAKE_HANDLER_PTR(Task_context_1_BomberDmgHandler_401DE0),
    MAKE_HANDLER_PTR(EventHandler_BeastEnclosure),
    MAKE_HANDLER_PTR(entity_402150_beastenclosure),
    MAKE_HANDLER_PTR(UNIT_Handler_BeastEnclosure),
    MAKE_HANDLER_PTR(entity_mode_beastenclosure_set_default_production),
    MAKE_HANDLER_PTR(entity_mode_402350_beastenclosure),
    MAKE_HANDLER_PTR(entity_mode_beastenclosure_on_death),
    MAKE_HANDLER_PTR(entity_mode_402440_beastenclosure),
    MAKE_HANDLER_PTR(entity_blacksmith_on_upgrade_complete),
    MAKE_HANDLER_PTR(MessageHandler_Blacksmith),
    MAKE_HANDLER_PTR(UNIT_Handler_Blacksmith),
    MAKE_HANDLER_PTR(entity_mode_402780_blacksmith),
    MAKE_HANDLER_PTR(entity_mode_402840_blacksmith),
    MAKE_HANDLER_PTR(entity_mode_402870_blacksmith),
    MAKE_HANDLER_PTR(entity_mode_blacksmith_on_death),
    MAKE_HANDLER_PTR(entity_mode_402AB0),
    MAKE_HANDLER_PTR(entity_402AC0_is_mode_402AB0),
    MAKE_HANDLER_PTR(entity_402BB0_set_arrive_handler),
    MAKE_HANDLER_PTR(entity_402C40_lower_hp_mute09_surv21),
    MAKE_HANDLER_PTR(entity_initialize_building),
    MAKE_HANDLER_PTR(entity_sabotage),
    MAKE_HANDLER_PTR(EventHandler_DefaultBuildingsHandler),
    MAKE_HANDLER_PTR(script_403230_building_mini_explosion),
    MAKE_HANDLER_PTR(script_4032F0_building_grand_explosion),
    MAKE_HANDLER_PTR(script_403380_explosions),
    MAKE_HANDLER_PTR(entity_mode_4034B0),
    MAKE_HANDLER_PTR(entity_mode_403540),
    MAKE_HANDLER_PTR(entity_mode_4035C0_building),
    MAKE_HANDLER_PTR(entity_mode_403650_building),
    MAKE_HANDLER_PTR(entity_mode_403720_on_prison_death__or__prolly_any_generic_building),
    MAKE_HANDLER_PTR(entity_mode_building_on_death_default),
    MAKE_HANDLER_PTR(entity_4038B0),
    MAKE_HANDLER_PTR(entity_clanhall_on_upgrade_complete),
    MAKE_HANDLER_PTR(EventHandler_Clanhall),
    MAKE_HANDLER_PTR(entity_mode_clanhall_set_default_production),
    MAKE_HANDLER_PTR(UNIT_Handler_Clanhall),
    MAKE_HANDLER_PTR(entity_mode_clanhall_on_building_completed),
    MAKE_HANDLER_PTR(entity_mode_4042A0_clanhall),
    MAKE_HANDLER_PTR(entity_mode_clanhall_on_death_reset_production_options),
    MAKE_HANDLER_PTR(_4318E0_free_building_production),
    MAKE_HANDLER_PTR(entity_mode_clanhall_on_death),
    MAKE_HANDLER_PTR(entity_4054D0_tanker_convoy),
    MAKE_HANDLER_PTR(EventHandler_TankerConvoy),
    MAKE_HANDLER_PTR(entity_mode_405680_tanker_convoy),
    MAKE_HANDLER_PTR(entity_mode_405690),
    MAKE_HANDLER_PTR(entity_405750_tanker_convoy),
    MAKE_HANDLER_PTR(UNIT_Handler_OilTankerConvoy),
    MAKE_HANDLER_PTR(UNIT_Handler_MobileDerrick),
    MAKE_HANDLER_PTR(entity_mode_406CC0_mobilederrick),
    MAKE_HANDLER_PTR(EventHandler_MobileDerrick),
    MAKE_HANDLER_PTR(entity_mode_406DC0_mobilederrick),
    MAKE_HANDLER_PTR(entity_mode_plant_mobile_derrick),
    MAKE_HANDLER_PTR(entity_remove_unit_after_mobile_derrick_outpost_clanhall_plant),
    MAKE_HANDLER_PTR(UNIT_Handler_OilPatch),
    MAKE_HANDLER_PTR(EventHandler_Prison),
    MAKE_HANDLER_PTR(nullsub_1),
    MAKE_HANDLER_PTR(UNIT_Handler_Prison),
    MAKE_HANDLER_PTR(entity_mode_407300_prison),
    MAKE_HANDLER_PTR(entity_mode_407390_prison),
    MAKE_HANDLER_PTR(entity_mode_prison_spawn_unit),
    MAKE_HANDLER_PTR(entity_mode_prison_on_death),
    MAKE_HANDLER_PTR(UNIT_Handler_Prison),
    MAKE_HANDLER_PTR(entity_mode_prison_spawn_unit_surv09),
    MAKE_HANDLER_PTR(entity_mode_prison_on_death_surv09),
    MAKE_HANDLER_PTR(EventHandler_TechBunker),
    MAKE_HANDLER_PTR(entity_4075F0_techbunker),
    MAKE_HANDLER_PTR(entity_407690_techbunker_spawn),
    MAKE_HANDLER_PTR(entity_mode_407870_techbubker),
    MAKE_HANDLER_PTR(entity_mode_407950_techbunker_spawn_generic),
    MAKE_HANDLER_PTR(entity_mode_4079F0_techbunker_spawn10_surv18_lvl),
    MAKE_HANDLER_PTR(entity_mode_407A90_techbunker),
    MAKE_HANDLER_PTR(entity_mode_407B70_techbunker),
    MAKE_HANDLER_PTR(UNIT_Handler_TechBunker),
    MAKE_HANDLER_PTR(entity_mode_407C20_on_death_tech_bunker),
    MAKE_HANDLER_PTR(entity_mode_407C60_on_death_tech_bunker),
    MAKE_HANDLER_PTR(entity_mode_407D10),
    MAKE_HANDLER_PTR(entity_mode_hut_on_death),
    MAKE_HANDLER_PTR(entity_mode_407DA0),
    MAKE_HANDLER_PTR(EventHandler_Hut),
    MAKE_HANDLER_PTR(entity_mode_407E70_hut),
    MAKE_HANDLER_PTR(entity_mode_407F00_hut),
    MAKE_HANDLER_PTR(UNIT_Handler_Hut),
    MAKE_HANDLER_PTR(EventHandler_DrillRig),
    MAKE_HANDLER_PTR(UNIT_Handler_DrillRig),
    MAKE_HANDLER_PTR(entity_mode_4081C0_drillrig),
    MAKE_HANDLER_PTR(entity_mode_408240_drillrig),
    MAKE_HANDLER_PTR(entity_mode_408260_drillrig),
    MAKE_HANDLER_PTR(entity_mode_drillrig_on_death),
    MAKE_HANDLER_PTR(UNIT_Handler_Vehicle),
    MAKE_HANDLER_PTR(UNIT_Handler_Infantry),
    MAKE_HANDLER_PTR(entity_mode_adjust_unit_placement_inside_tile),
    MAKE_HANDLER_PTR(entity_mode_default_idle),
    MAKE_HANDLER_PTR(entity_mode_4157F0_infantry_idle_fidgeting),
    MAKE_HANDLER_PTR(entity_4158B0),
    MAKE_HANDLER_PTR(entity_mode_415980),
    MAKE_HANDLER_PTR(entity_415A20),
    MAKE_HANDLER_PTR(entity_mode_rotate_to_target_415A60),
    MAKE_HANDLER_PTR(entity_mode_move_attack),
    MAKE_HANDLER_PTR(entity_mode_attack_move_1_415D30),
    MAKE_HANDLER_PTR(entity_mode_416060),
    MAKE_HANDLER_PTR(entity_mode_attack_move_2_5_4165C0),
    MAKE_HANDLER_PTR(entity_mode_move_to_target_416790),
    MAKE_HANDLER_PTR(entity_mode_416A70_infantry),
    MAKE_HANDLER_PTR(entity_mode_416CD0),
    MAKE_HANDLER_PTR(entity_mode_416EB0),
    MAKE_HANDLER_PTR(entity_mode_417100),
    MAKE_HANDLER_PTR(entity_4172D0),
    MAKE_HANDLER_PTR(entity_mode_417360_infantry),
    MAKE_HANDLER_PTR(entity_mode_attack_move_4_417550),
    MAKE_HANDLER_PTR(entity_mode_417670),
    MAKE_HANDLER_PTR(entity_417810),
    MAKE_HANDLER_PTR(entity_417980),
    MAKE_HANDLER_PTR(entity_mode_417A20),
    MAKE_HANDLER_PTR(entity_mode_417BD0),
    MAKE_HANDLER_PTR(entity_mode_attack_move_4_order_3_7_417E60),
    MAKE_HANDLER_PTR(entity_mode_417F50),
    MAKE_HANDLER_PTR(entity_417F60),
    MAKE_HANDLER_PTR(entity_mode_417FC0),
    MAKE_HANDLER_PTR(entity_418120),
    MAKE_HANDLER_PTR(entity_418170),
    MAKE_HANDLER_PTR(entity_mode_4181B0),
    MAKE_HANDLER_PTR(entity_418290),
    MAKE_HANDLER_PTR(entity_mode_418550),
    MAKE_HANDLER_PTR(entity_mode_418590),
    MAKE_HANDLER_PTR(entity_4187F0),
    MAKE_HANDLER_PTR(script_418A10),
    MAKE_HANDLER_PTR(entity_mode_418B30),
    MAKE_HANDLER_PTR(entity_mode_418D20),
    MAKE_HANDLER_PTR(entity_mode_418E90_leaving_repair_bay),
    MAKE_HANDLER_PTR(entity_mode_418F60),
    MAKE_HANDLER_PTR(entity_mode_418FE0_repairing_in_bay),
    MAKE_HANDLER_PTR(entity_mode_419180_in_repairbay),
    MAKE_HANDLER_PTR(entity_mode_419230_arrive_at_repairbay),
    MAKE_HANDLER_PTR(entity_4192F0),
    MAKE_HANDLER_PTR(entity_mode_419390_oiltanker),
    MAKE_HANDLER_PTR(entity_mode_move_tanker),
    MAKE_HANDLER_PTR(entity_419560_on_death),
    MAKE_HANDLER_PTR(entity_infantry_on_dead),
    MAKE_HANDLER_PTR(entity_mode_419760_infantry_destroyed),
    MAKE_HANDLER_PTR(entity_mode_4197E0_infantry),
    MAKE_HANDLER_PTR(EventHandler_Infantry),
    MAKE_HANDLER_PTR(EventHandler_419CA0),
    MAKE_HANDLER_PTR(EventHandler_General_Scout),
    MAKE_HANDLER_PTR(EventHandler_419DF0_unit_repairing_in_bay),
    MAKE_HANDLER_PTR(EventHandler_419E80_unit_in_repairbay),
    MAKE_HANDLER_PTR(entity_machineshop_on_upgrade_complete),
    MAKE_HANDLER_PTR(EventHandler_MachineShop),
    MAKE_HANDLER_PTR(entity_4220B0_machineshop),
    MAKE_HANDLER_PTR(UNIT_Handler_MachineShop),
    MAKE_HANDLER_PTR(entity_mode_machineshop_set_default_production),
    MAKE_HANDLER_PTR(entity_mode_machineshop_on_death_no_default),
    MAKE_HANDLER_PTR(entity_mode_4223A0_machineshop),
    MAKE_HANDLER_PTR(entity_mode_machineshop_on_death),
    MAKE_HANDLER_PTR(script_424BF0_mobd_20_handler),
    MAKE_HANDLER_PTR(_424CA0_script_47A3CC_evttrigger),
    MAKE_HANDLER_PTR(_424CC0_script_47A3CC_evttrigger),
    MAKE_HANDLER_PTR(script_424CE0_mission_outcome_modal),
    MAKE_HANDLER_PTR(sub_4250E0),
    MAKE_HANDLER_PTR(sub_4251B0),
    MAKE_HANDLER_PTR(script_4252C0),
    MAKE_HANDLER_PTR(script_425400),
    MAKE_HANDLER_PTR(entity_check_special_mission_death_conditions),
    MAKE_HANDLER_PTR(entity_find_player_entity_in_radius),
    MAKE_HANDLER_PTR(entity_4258C0_init_palettes_inc_unit_counter),
    MAKE_HANDLER_PTR(entity_mode_425920_scout),
    MAKE_HANDLER_PTR(entity_425A50_setup_spawn),
    MAKE_HANDLER_PTR(UNIT_Handler_General),
    MAKE_HANDLER_PTR(UNIT_Handler_Scout),
    MAKE_HANDLER_PTR(_425EC0_entities_check_modes),
    MAKE_HANDLER_PTR(FindEntityBySideAndType),
    MAKE_HANDLER_PTR(script_425F50_stru48_stru51_tech_bunkers),
    MAKE_HANDLER_PTR(script_425BE0_check_special_victory_conditions),
    MAKE_HANDLER_PTR(handler_4267F0),
    MAKE_HANDLER_PTR(nullsub_1),
    MAKE_HANDLER_PTR(script_426710_mission_objectives_draw_x_mark),
    MAKE_HANDLER_PTR(_4268B0_4269B0_task_attachment_handler),
    MAKE_HANDLER_PTR(_426860_4269B0_task_attachment_handler),
    MAKE_HANDLER_PTR(task_4269B0_mobd_20_handler),
    MAKE_HANDLER_PTR(UNIT_Handler_MobileOutpost),
    MAKE_HANDLER_PTR(entity_mode_4278C0_mobile_outpost),
    MAKE_HANDLER_PTR(MessageHandler_MobileOutpost),
    MAKE_HANDLER_PTR(MessageHandler_MobileOutpostEmpty),
    MAKE_HANDLER_PTR(entity_427BB0_mobile_outpost_clanhall_planting),
    MAKE_HANDLER_PTR(entity_mode_427BF0_mobile_outpost_clanhall_planting),
    MAKE_HANDLER_PTR(entity_427C30_after_mobile_outpost_clanhall_wagon_plant),
    MAKE_HANDLER_PTR(entity_remove_unit_after_mobile_derrick_outpost_clanhall_plant),
    MAKE_HANDLER_PTR(EventHandler_4089B0_generic_ai),
    MAKE_HANDLER_PTR(script_409770_ai),
    MAKE_HANDLER_PTR(script_40B700_ai),
    MAKE_HANDLER_PTR(EventHandler_42D6B0_evolved_mission8_ai),
    MAKE_HANDLER_PTR(script_42DA90_ai),
    MAKE_HANDLER_PTR(script_42DC70_ai),
    MAKE_HANDLER_PTR(EventHandler_42DC90_evolved_mission5_ai),
    MAKE_HANDLER_PTR(script_42DE80),
    MAKE_HANDLER_PTR(script_42DF20),
    MAKE_HANDLER_PTR(stru24_42DF40),
    MAKE_HANDLER_PTR(stru24_42E030),
    MAKE_HANDLER_PTR(stru24_42E070),
    MAKE_HANDLER_PTR(entity_outpost_on_upgrade_complete),
    MAKE_HANDLER_PTR(EventHandler_Outpost),
    MAKE_HANDLER_PTR(entity_mode_outpost_enable_basic_construction),
    MAKE_HANDLER_PTR(UNIT_Handler_Outpost),
    MAKE_HANDLER_PTR(entity_mode_outpost_set_default_production),
    MAKE_HANDLER_PTR(entity_mode_431680_outpost_arrive),
    MAKE_HANDLER_PTR(entity_mode_outpost_on_death_update_production),
    MAKE_HANDLER_PTR(_4318E0_free_building_production),
    MAKE_HANDLER_PTR(entity_mode_outpost_on_death),
    MAKE_HANDLER_PTR(EventHandler_PowerStation),
    MAKE_HANDLER_PTR(UNIT_Handler_PowerStation),
    MAKE_HANDLER_PTR(entity_mode_powerstation_spawn_tanker),
    MAKE_HANDLER_PTR(entity_mode_powerstation_completed),
    MAKE_HANDLER_PTR(entity_mode_powerstation_on_death),
    MAKE_HANDLER_PTR(UNIT_DmgHandler_Sapper),
    MAKE_HANDLER_PTR(script_435CF0_rocket_dmg_handler),
    MAKE_HANDLER_PTR(script_435D40_bombers_dmg),
    MAKE_HANDLER_PTR(UNIT_DmgHandler_Rocket),
    MAKE_HANDLER_PTR(script_436140_flamethrower_dmg_handler),
    MAKE_HANDLER_PTR(UNIT_DmgHandler_Flamethrower),
    MAKE_HANDLER_PTR(script_4363C0_giant_bettle_dmg),
    MAKE_HANDLER_PTR(UNIT_DmgHandler_Beetle),
    MAKE_HANDLER_PTR(script_4368B0_plasma_tank_dmg_handler),
    MAKE_HANDLER_PTR(UNIT_DmgHandler_Mech),
    MAKE_HANDLER_PTR(script_436FB0_dmg_handler),
    MAKE_HANDLER_PTR(script_436FF0_rifle_dmg_handler),
    MAKE_HANDLER_PTR(script_4370D0_gort_dmg_handler),
    MAKE_HANDLER_PTR(UNIT_DmgHandler_GORT),
    MAKE_HANDLER_PTR(UNIT_DmgHandler_Rifle),
    MAKE_HANDLER_PTR(sub_437690),
    MAKE_HANDLER_PTR(UNIT_DmgHandler_Bow),
    MAKE_HANDLER_PTR(UNIT_DmgHandler_Projectile),
    MAKE_HANDLER_PTR(EventHandler_RepairStation),
    MAKE_HANDLER_PTR(UNIT_Handler_RepairStation),
    MAKE_HANDLER_PTR(UNIT_Handler_RepairStation),
    MAKE_HANDLER_PTR(entity_mode_437F30_repairstation),
    MAKE_HANDLER_PTR(EventHandler_UpgradeProcess),
    MAKE_HANDLER_PTR(EntityUpgradeAttachment_438000),
    MAKE_HANDLER_PTR(EntityUpgradeAttachment_438030),
    MAKE_HANDLER_PTR(EntityUpgradeAttachment_438160_handler),
    MAKE_HANDLER_PTR(script_4381A0_upgrade_process),
    MAKE_HANDLER_PTR(EventHandler_ResearchBuilding),
    MAKE_HANDLER_PTR(UNIT_Handler_ResearchBuilding),
    MAKE_HANDLER_PTR(UNIT_Handler_ResearchBuilding),
    MAKE_HANDLER_PTR(entity_mode_researchlab_completed),
    MAKE_HANDLER_PTR(entity_mode_researchlab_on_death),
    MAKE_HANDLER_PTR(script_438B80_on_death_infantry_gore),
    MAKE_HANDLER_PTR(script_438C20_on_death_explosion),
    MAKE_HANDLER_PTR(entity_mode_4444D0_oiltanker),
    MAKE_HANDLER_PTR(entity_mode_4444F0_oiltanker),
    MAKE_HANDLER_PTR(entity_mode_444590_oiltanker),
    MAKE_HANDLER_PTR(entity_mode_444630_oiltanker),
    MAKE_HANDLER_PTR(entity_mode_4446B0_oiltanker_load_oil),
    MAKE_HANDLER_PTR(entity_mode_4447C0_oiltanker),
    MAKE_HANDLER_PTR(entity_mode_4448C0_oiltanker),
    MAKE_HANDLER_PTR(entity_mode_4449D0_oiltanker),
    MAKE_HANDLER_PTR(entity_mode_444A40_oiltanker),
    MAKE_HANDLER_PTR(entity_mode_444AB0_oiltanker),
    MAKE_HANDLER_PTR(entity_mode_444B40_oiltanker_unload_oil),
    MAKE_HANDLER_PTR(entity_mode_444CC0_oiltanker),
    MAKE_HANDLER_PTR(entity_mode_444D10_oiltanker),
    MAKE_HANDLER_PTR(entity_mode_4446A0_oiltanker),
    MAKE_HANDLER_PTR(EventHandler_OilTanker),
    MAKE_HANDLER_PTR(script_401C30_sidebar),
    MAKE_HANDLER_PTR(Task_context_0_4019A0),
    MAKE_HANDLER_PTR(Task_context_0_401A40),
    MAKE_HANDLER_PTR(Task_context_0_401A80),
    MAKE_HANDLER_PTR(Task_context_0_401AF0),
    MAKE_HANDLER_PTR(EventHandler_401B80),
    MAKE_HANDLER_PTR(UNIT_Handler_GuardTower),
    MAKE_HANDLER_PTR(UNIT_Handler_GuardTower),
    MAKE_HANDLER_PTR(UNIT_Handler_GuardTower),
    MAKE_HANDLER_PTR(UNIT_Handler_GuardTower),
    MAKE_HANDLER_PTR(UNIT_Handler_GuardTower),
    MAKE_HANDLER_PTR(UNIT_Handler_Towers),
    MAKE_HANDLER_PTR(entity_mode_4474D0_towers),
    MAKE_HANDLER_PTR(entity_mode_4474E0_towers),
    MAKE_HANDLER_PTR(entity_mode_tower_on_death),
    MAKE_HANDLER_PTR(entity_mode_tower_dead),
    MAKE_HANDLER_PTR(EventHandler_Towers),
    MAKE_HANDLER_PTR(UNIT_AttachHandler_Turret),
    MAKE_HANDLER_PTR(EntityTowerAttachment_handler_447C40),
    MAKE_HANDLER_PTR(EntityTowerAttachment_handler_447CA0),
    MAKE_HANDLER_PTR(EntityTowerAttachment_handler_447DD0),
    MAKE_HANDLER_PTR(EntityTowerAttachment_handler_447E20),
    MAKE_HANDLER_PTR(EntityTowerAttachment_handler_447F50),
    MAKE_HANDLER_PTR(EntityTowerAttachment_handler_447FA0),
    MAKE_HANDLER_PTR(EntityTowerAttachment_handler_448110),
    MAKE_HANDLER_PTR(EntityTowerAttachment_handler_448160),
    MAKE_HANDLER_PTR(EntityTowerAttachment_handler_448230),
    MAKE_HANDLER_PTR(EntityTowerAttachment_handler_448290),
    MAKE_HANDLER_PTR(EntityTowerAttachment_handler_4482D0_missile_battery),
    MAKE_HANDLER_PTR(nullsub_1),
    MAKE_HANDLER_PTR(MessageHandler_TowersAttachment),
    MAKE_HANDLER_PTR(UNIT_AttachHandler_Turret),
    MAKE_HANDLER_PTR(tower_attachment_handler_448980),
    MAKE_HANDLER_PTR(tower_attachment_handler_4489B0),
    MAKE_HANDLER_PTR(tower_attachment_handler_448B40),
    MAKE_HANDLER_PTR(tower_attachment_handler_448BF0),
    MAKE_HANDLER_PTR(tower_attachment_handler_448C40),
    MAKE_HANDLER_PTR(tower_attachment_handler_448E90),
    MAKE_HANDLER_PTR(MessageHandler_448EC0),
    MAKE_HANDLER_PTR(script_44BE60_explosions),
    MAKE_HANDLER_PTR(UNIT_AttachHandler_DockPoint),
    MAKE_HANDLER_PTR(EntityTurret_44BF00_handler),
    MAKE_HANDLER_PTR(EntityTurret_44BF70),
    MAKE_HANDLER_PTR(sub_44BFC0),
    MAKE_HANDLER_PTR(MessageHandler_EntityScript),
};

ScriptHandler other_unsorted_handlers[] = {
    MAKE_HANDLER_PTR(script_main_menu_play_mission),
    MAKE_HANDLER_PTR(script_main_menu_new_missions),
    MAKE_HANDLER_PTR(script_main_menu_kaos_mode),
    MAKE_HANDLER_PTR(script_mobd79__main_menu_mouse_handler),
    MAKE_HANDLER_PTR(script_sidebar),
    MAKE_HANDLER_PTR(script_40F5D0_sidebar_button_1_2),
    MAKE_HANDLER_PTR(script_40F8F0_sidebar_button_3),
    MAKE_HANDLER_PTR(script_show_message_ex),
    MAKE_HANDLER_PTR(script_show_message),
    MAKE_HANDLER_PTR(script_evt39030_handler),
    MAKE_HANDLER_PTR(script_44A500_fog_of_war),
    MAKE_HANDLER_PTR(script_4280A0_stru38_list__production_loop),

    // load game menu
    MAKE_HANDLER_PTR(script_432F00_ingame_menu),
    MAKE_HANDLER_PTR(script_434390_ingame_menu),
    MAKE_HANDLER_PTR(script_434220_ingame_menu),
    MAKE_HANDLER_PTR(script_434310_ingame_menu),
    MAKE_HANDLER_PTR(script_4342A0_ingame_menu),
    MAKE_HANDLER_PTR(script_434460_DA000007),
    MAKE_HANDLER_PTR(script_432800_ingame_menu),
    MAKE_HANDLER_PTR(script_ingame_menu_savegame_list_line),

    // menu in game (esc)
    MAKE_HANDLER_PTR(script_ingame_menu_options),
    MAKE_HANDLER_PTR(script_ingame_menu_quit),
    MAKE_HANDLER_PTR(script_ingame_menu_resume),
    MAKE_HANDLER_PTR(script_ingame_menu_save),
    MAKE_HANDLER_PTR(script_ingame_menu_load),
    MAKE_HANDLER_PTR(script_ingame_menu_restart),
    MAKE_HANDLER_PTR(script_ingame_menu_briefing),
    MAKE_HANDLER_PTR(script_ingame_menu_quit_yes),
    MAKE_HANDLER_PTR(script_ingame_menu_quit_no),
    MAKE_HANDLER_PTR(script_ingame_menu_restart_yes),
    MAKE_HANDLER_PTR(script_ingame_menu_restart_no),
    MAKE_HANDLER_PTR(script_ingame_menu_briefing_done), //mission briefing
    MAKE_HANDLER_PTR(script_ingame_menu_options_done), //options - sound settings
    MAKE_HANDLER_PTR(script_ingame_menu_options_volume_slider), //options - sound settings

    MAKE_HANDLER_PTR(script_main_menu_kaos_player_name),
    MAKE_HANDLER_PTR(script_main_menu_kaos_enemies),
    MAKE_HANDLER_PTR(script_main_menu_kaos_starting_cash),
    MAKE_HANDLER_PTR(script_main_menu_kaos_color),
    MAKE_HANDLER_PTR(script_main_menu_kaos_map),
    MAKE_HANDLER_PTR(script_main_menu_kaos_max_tech_level),
    MAKE_HANDLER_PTR(script_main_menu_kaos_bunkers_toggle),
    MAKE_HANDLER_PTR(script_main_menu_kaos_team),

    // ingame menu - save game
    MAKE_HANDLER_PTR(script_ingame_menu_save_game_list),
    MAKE_HANDLER_PTR(script_ingame_menu_save_game_save),
    MAKE_HANDLER_PTR(script_ingame_menu_save_game_cancel),
    MAKE_HANDLER_PTR(script_ingame_menu_save_game_up),
    MAKE_HANDLER_PTR(script_ingame_menu_save_game_down),
    MAKE_HANDLER_PTR(script_421D60_on_savegame_failed),

    // ingame menu - load game
    MAKE_HANDLER_PTR(script_ingame_menu_create_load_dialog),
    MAKE_HANDLER_PTR(script_ingame_menu_load_game_list),
    MAKE_HANDLER_PTR(script_ingame_menu_load_game_load),
    MAKE_HANDLER_PTR(script_ingame_menu_load_game_cancel),
    MAKE_HANDLER_PTR(script_ingame_menu_load_game_up),
    MAKE_HANDLER_PTR(script_ingame_menu_load_game_down),

    //kaos mode
    MAKE_HANDLER_PTR(script_40FC10_sidebar_button_4),
    MAKE_HANDLER_PTR(script_408370),
    MAKE_HANDLER_PTR(script_439050_explosions),
    MAKE_HANDLER_PTR(script_438F50_explosions)
};



Script *create_script(int script_id) 
{
    auto desc = scripts[script_id];
    if (desc->script_handler)
    {
        return (desc->script_type == SCRIPT_FUNCTION)
            ? script_create_function(SCRIPT_TYPE_INVALID, desc->script_handler)
            : script_create_coroutine(SCRIPT_TYPE_INVALID, desc->script_handler, 0);
    }

    return nullptr;
}

int get_script_type(int script_id)
{
    if (script_id >= 86 && script_id <= 156) 
    {
        return 1;
    }

    switch (script_id) 
    {
        case 0:
            return 1;
        case 1:
        case 85:
            return 2;
        case 2:
        case 3:
        case 4:
        case 5:
            return 3;

        default:
            return 4;
    }
}

int get_num_scripts() 
{
    return sizeof(scripts) / sizeof(*scripts);
}

UNIT_ID get_script_unit_id(int script_id) 
{
    // Prison, Prison, Outpost, Clannhall
    //if (script_id != 4 && script_id != 5 && script_id != 2 && script_id != 3) {
    if (get_script_type(script_id) != 3) 
    {
        return scripts[script_id]->stats_idx;
    }
    else 
    {
        auto script_desc = (ScriptDescType3 *)scripts[script_id];
        return script_desc->stats_idx;
    }
}

MOBD_ID get_script_mobd(int script_id) 
{
    return scripts[script_id]->mobd_id;
}

const char *get_script_name(int script_id) 
{
    return scripts[script_id]->script_handler_name;
}

const char *get_script_name(void *handler) {
    for (int i = 0; i < get_num_scripts(); ++i) 
    {
        if (scripts[i]->script_handler == handler) 
        {
            return scripts[i]->script_handler_name;
        }
    }
    return nullptr;
}

int get_num_handlers() 
{
    return sizeof(script_handlers) / sizeof(script_handlers[0]);
}

void *get_handler(int handler_id) 
{
    return script_handlers[handler_id].function;
}

const char *get_handler_name(int handler_id) 
{
    return script_handlers[handler_id].function_name;
}

int get_handler_id(void *function) 
{
    for (int i = 0; i < get_num_handlers(); ++i) 
    {
        if (script_handlers[i].function == function) 
        {
            return i;
        }
    }
    return -1;
}

int get_num_other_unsorted_handlers()
{
    return sizeof(other_unsorted_handlers) / sizeof(*other_unsorted_handlers);
}

const char *get_handler_name(void *function) 
{
    int unit_handler_id = get_handler_id(function);
    if (unit_handler_id >= 0) 
    {
        return script_handlers[unit_handler_id].function_name;
    }

    auto script_name = get_script_name(function);
    if (script_name) 
    {
        return script_name;
    }

    for (int i = 0; i < get_num_other_unsorted_handlers(); ++i)
    {
        if (other_unsorted_handlers[i].function == function)
        {
            return other_unsorted_handlers[i].function_name;
        }
    }

    // please add the script to   other_unsorted_handlers
    __debugbreak();
    return nullptr;
}


//----- (00445400) --------------------------------------------------------
void *script_create_local_object(Script *s, int size)
{
    Script *script; // esi@1
    ScriptLocalObject *loc_object_1; // eax@1
    ScriptLocalObject *loc_object_2; // ecx@2
    ScriptLocalObject *loc_object_3; // ecx@2

    script = s;
    loc_object_1 = (ScriptLocalObject *)malloc(size + 8);
    if (loc_object_1)
    {
        loc_object_2 = script->locals_list;
        loc_object_1->prev = 0;
        loc_object_1->next = loc_object_2;
        loc_object_3 = script->locals_list;
        if (loc_object_3)
            loc_object_3->prev = loc_object_1;
        script->locals_list = loc_object_1;
        loc_object_1 = (ScriptLocalObject *)((char *)loc_object_1 + 8);
    }
    return loc_object_1;
}

//----- (00445440) --------------------------------------------------------
void script_free_local_object(Script *s, void *data)
{
    ScriptLocalObject *loc_object; // eax@1
    ScriptLocalObject **prev_loc_object; // edx@1

    loc_object = CONTAINING_RECORD(data, ScriptLocalObject, data);
    prev_loc_object = (ScriptLocalObject **)*((_DWORD *)data - 1);
    if (prev_loc_object)
    {
        *prev_loc_object = loc_object->next;
    }
    else
    {
        s->locals_list = loc_object->next;
    }
    if (loc_object->next)
    {
        loc_object->next->prev = loc_object->prev;
    }
    free(loc_object);
}

//----- (00445210) --------------------------------------------------------
Script *script_create_coroutine(enum SCRIPT_TYPE type, void(*task_main)(Script *), int stack_size)
{
    Script *script = new Script();
    if (script != nullptr)
    {
        memset(script, 0, sizeof(Script));
        script->script_type = type;
        script->routine_type = SCRIPT_COROUTINE;

        auto coroutine = couroutine_create(coroutine_main, get_handler_name(task_main));
        script->handler = (void(*)(Script *))coroutine;
        script->debug_handler_name = get_handler_name(task_main);

        if (coroutine)
        {
            task_creation_handler = task_main;
            task_creation_handler_arg = script;

            //add script to script_execute_list head
            script_execute_list.push_front(script);

            // call coroutine_main to queue up execution of  task_creation_handler( task_creation_handler_arg )
            coroutine->resume();

            return script;
        }
    }

    return nullptr;
}

//----- (004452B0) --------------------------------------------------------
Script *script_create_function(enum SCRIPT_TYPE type, void(*function)(Script *))
{
    Script *script = new Script();
    if (script != nullptr)
    {
        memset(script, 0, sizeof(Script));
        script->script_type = type;
        script->routine_type = SCRIPT_FUNCTION;
        script->handler = function;
        script->debug_handler_name = get_handler_name(function);
        if (function)
        {
            //add script to script_execute_list head
            script_execute_list.push_front(script);

            return script;
        }
    }

    return nullptr;
}

//----- (00402A30) --------------------------------------------------------
void script_execute_function(Script *s)
{
    if (s->routine_type == SCRIPT_FUNCTION) {
        s->handler(s);
    }
}

void script_execute_coroutine(Script *s)
{
    if (s->routine_type == SCRIPT_COROUTINE) {
        auto coroutine = (Coroutine *)s->handler;
        coroutine->resume();
    }
}


void script_free_handler(Script *s)
{
    if (s->routine_type == SCRIPT_COROUTINE)
    {
        coroutine_list_remove((Coroutine *)s->handler);
    }
    s->handler = 0;
}

// thread will awake after REPEATS attempts
int script_sleep(Script *s, int num_turns) 
{
    return script_yield(s, SCRIPT_FLAGS_20_REPEATS_TRIGGER, num_turns);
}

// thread will awake after receiving an event
int script_wait_event(Script *s) 
{
    return script_yield(s, SCRIPT_FLAGS_20_EVENT_TRIGGER, 0);
}

int script_yield_any_trigger(Script *s, int num_turns) 
{
    return script_yield(s, SCRIPT_FLAGS_20_ANY_TRIGGER, num_turns);
}

//----- (00445370) --------------------------------------------------------
int script_yield(Script *s, int yield_flags, int param)
{
    if (yield_flags & SCRIPT_FLAGS_20_EVENT_TRIGGER && s->event_list)
    {
        s->flags_20 |= SCRIPT_FLAGS_20_EVENT_TRIGGER;
        s->flags_24 |= s->flags_20;
    }
    if (yield_flags & SCRIPT_FLAGS_20_REPEATS_TRIGGER)
    {
        if (param)
        {
            s->num_runs_to_skip = param;
        }
        if (s->num_runs_to_skip == 0)
        {
            // return immediately as 0 repeats elapsed
            s->flags_24 |= SCRIPT_FLAGS_20_REPEATS_TRIGGER;
            int v6 = s->flags_20 | SCRIPT_FLAGS_20_REPEATS_TRIGGER;
            s->flags_20 = 0;
            s->_28_yield_flags = 0;
            return yield_flags & v6;
        }
    }
    else if (param)
    {
        s->field_2C |= param;
    }

    s->flags_20 = 0;
    s->_28_yield_flags = yield_flags;
    if (s->routine_type == SCRIPT_COROUTINE)
    {
        (coroutine_list_get_head())->resume();
        s->_28_yield_flags = 0;
        s->field_2C = 0;
    }
    return s->flags_20;
}

//----- (00445470) --------------------------------------------------------
void script_terminate(Script *s)
{
    s->flags_20 |= SCRIPT_FLAGS_20_TERMINATE;
    s->flags_24 |= s->flags_20;
    if (s->routine_type == SCRIPT_COROUTINE) 
    {
        (coroutine_list_get_head())->resume();
    }
}

void script_terminate_internal(Script *s) 
{
    ScriptLocalObject *loc_object_1; // eax@3
    ScriptLocalObject *loc_object_2; // ebx@4

    if (loc_object_1 = s->locals_list)
    {
        do
        {
            loc_object_2 = loc_object_1->next;
            free(loc_object_1);
            loc_object_1 = loc_object_2;
        } while (loc_object_2);
    }

    script_discard_all_events(s);
    script_free_handler(s);
}

//----- (00445310) --------------------------------------------------------
void script_deinit(Script *s)
{
    Script *script; // edi@1
    ScriptLocalObject *loc_object_1; // eax@1
    ScriptLocalObject *loc_object_2; // esi@2

    script = s;
    loc_object_1 = s->locals_list;
    if (loc_object_1)
    {
        do
        {
            loc_object_2 = loc_object_1->next;
            free(loc_object_1);
            loc_object_1 = loc_object_2;
        } while (loc_object_2);
    }

    script_discard_all_events(script);
    script_execute_list.remove(script);
    script_free_handler(script);
    delete script;
}

//----- (00445170) --------------------------------------------------------
bool script_list_alloc(int coroutine_stack_size)
{
    if (script_event_list_alloc())
    {
        if (coroutine_list_alloc())
        {
            if (coroutine_stack_size <= 0)
            {
                coroutine_stack_size = 1 * 1024 * 1024; // 1M
            }

            coroutine_default_stack_size = coroutine_stack_size;
            coroutine_current = coroutine_list_get_head();
            is_async_execution_supported = 0;

            return true;
        }
    }
    return false;
}

//----- (004454A0) --------------------------------------------------------
void script_list_update()
{
    int yield_flags; // ecx@15
    int flags; // eax@16

    std::vector<Script *> remove_list;
    for (auto script : script_execute_list)
    {
        if (script->flags_20 & SCRIPT_FLAGS_20_TERMINATE) 
        {
            log(
                "Script[%s] %s(%08X) terminated",
                script->routine_type == SCRIPT_COROUTINE ? "Coroutine" : "Function",
                script->debug_handler_name,
                script->handler
            );

            script_terminate_internal(script);
            remove_list.push_back(script);
        }
        else 
        {
            if (script->num_runs_to_skip > 0)
            {
                script->num_runs_to_skip -= 1;
                if (script->num_runs_to_skip == 0)
                {
                    script->flags_20 |= SCRIPT_FLAGS_20_REPEATS_TRIGGER;
                    script->flags_24 |= script->flags_20;
                }
            }
            flags = script->flags_20;
            yield_flags = script->_28_yield_flags;
            if (!yield_flags || (yield_flags & flags) || script->field_2C & ~flags)
            {
                switch (script->routine_type)
                {
                case SCRIPT_COROUTINE:
                    script_execute_coroutine(script);
                    break;

                case SCRIPT_FUNCTION:
                    script_execute_function(script);
                    break;

                default: __debugbreak();
                }
            }
        }
    }

    //remove from script_execute_list & clear remove_list
    for (auto script : remove_list) 
    {
        script_execute_list.remove(script);
    }
    remove_list.clear();
}

//----- (004455A0) --------------------------------------------------------
void script_list_free()
{
    Script *script; // esi@4
    ScriptLocalObject *loc_object_1; // eax@4
    ScriptLocalObject *loc_object_2; // edi@5

    if (coroutine_current == coroutine_list_get_head())
    {
        if(!script_execute_list.empty())
        {
            for (auto v0 : script_execute_list)
            {
                script = v0;
                loc_object_1 = script->locals_list;
                if (loc_object_1)
                {
                    do
                    {
                        loc_object_2 = loc_object_1->next;
                        free(loc_object_1);
                        loc_object_1 = loc_object_2;
                    } while (loc_object_2);
                }

                script_discard_all_events(script);
                script_free_handler(script);
                delete script;
            }
        }
        script_execute_list.clear();
        coroutine_list_free();
        script_event_list_free();
    }
}
