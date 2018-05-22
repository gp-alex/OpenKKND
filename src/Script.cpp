#include "src/kknd.h"

#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"

#include "src/Script.h"
#include "src/ScriptEvent.h"
#include "src/Cursor.h"
#include "src/Coroutine.h"


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


#define SCRIPT_DESC_HANDLER(x) (void(*)(Script *))x, #x

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
ScriptDescType4 stru_46ED60 = { MOBD_INGAME_MENU_CONTROLS,      SCRIPT_DESC_HANDLER(script_433060_ingame_menu_DA000000), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
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
ScriptDescType4 stru_46F958 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_441FC0_mobd45_evt8), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46F970 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_4421F0_mobd45_evt8), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46F988 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43D740_mobd45_evt17), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46F9A0 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43E470_mobd45_modems), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46F9B8 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43E230_mobd45_modems), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46F9D0 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43D890_mobd45), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46F9E8 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43E670_mobd45), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FA00 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43E7B0_mobd45), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FA18 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43E820_mobd45), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FA30 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_443000_mobd45), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FA48 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_443140_mobd45), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FA60 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_443290_mobd45), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FA78 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43F670_mobd45), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FA90 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43ED60_mobd45_modems), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FAA8 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43F0E0_mobd45_modems), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FAC0 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43F520_mobd45), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FAD8 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43EE90_mobd45), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FAF0 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43F330_mobd45), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FB08 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43D5F0_mobd45), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FB20 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43D090_mobd45_directx_ipx), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FB38 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43D430_mobd45_directx_modem), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FB50 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43D270_mobd45_directx_serial), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FB68 = { MOBD_45,                        SCRIPT_DESC_HANDLER(nullsub_1), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FB80 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43CF50_mobd45), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FB98 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43CE30_mobd45_begin_mute_campaign), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FBB0 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43CD20_mobd45_begin_surv_campaign), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FBC8 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43FDE0_mobd45), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FBE0 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_43FF30_mobd45), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FBF8 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_4402A0_mobd45_evt5), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FC10 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_442580_mobd45_evt17), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FC28 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_4428C0_mobd45_evt6), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FC40 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_4404D0_mobd45_evt8), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FC58 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_441940_mobd45_evt17), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FC70 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_441CE0_mobd45_evt8), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FC88 = { MOBD_45,                        SCRIPT_DESC_HANDLER(script_4426D0_mobd45_evt6), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FCA0 = { MOBD_79,                        SCRIPT_DESC_HANDLER(script_mobd79_evt1__main_menu_quit), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FCB8 = { MOBD_79,                        SCRIPT_DESC_HANDLER(script_mobd79_evt19__main_menu_load), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FCD0 = { MOBD_79,                        SCRIPT_DESC_HANDLER(script_mobd79_evt1__main_menu_multiplayer), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };
ScriptDescType4 stru_46FCE8 = { MOBD_79,                        SCRIPT_DESC_HANDLER(script_mobd79_evt1__main_menu_new_game), SCRIPT_COROUTINE, 0, 0, UNIT_STATS_SURV_RIFLEMAN };

ScriptDescType4 *scripts[196] =
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
    &stru_46EDA8,
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
    &stru_46FCE8
};


Script *create_script(int script_id) {
    auto desc = scripts[script_id];
    if (desc->script_handler) {
        return (desc->script_type == SCRIPT_FUNCTION)
            ? script_create_function(SCRIPT_TYPE_INVALID, desc->script_handler, desc->script_handler_name)
            : script_create_coroutine(SCRIPT_TYPE_INVALID, desc->script_handler, 0, desc->script_handler_name);
    }

    return nullptr;
}


int get_script_type(int script_id) {
    if (script_id >= 86 && script_id <= 156) {
        return 1;
    }

    switch (script_id) {
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


UNIT_ID get_script_unit_id(int script_id) {
    // Prison, Prison, Outpost, Clannhall
    //if (script_id != 4 && script_id != 5 && script_id != 2 && script_id != 3) {
    if (get_script_type(script_id) != 3) {
        return scripts[script_id]->stats_idx;
    }
    else {
        auto script_desc = (ScriptDescType3 *)scripts[script_id];
        return script_desc->stats_idx;
    }
}






Script *script_execute_list_first()
{
    return script_execute_list;
}

Script *script_execute_list_end()
{
    return (Script *)&script_execute_list;
}

bool script_execute_list_prepend(Script *script)
{
    auto head = script_execute_list_first();
    head->prev = script;

    script->next = head;
    script->prev = script_execute_list_end();

    script_execute_list = script;

    return true;
}

struct UnitHandler {
    void *function;
    const char *function_name;
};

void *script_handlers[353] =
{
    &UNIT_Handler_Outpost,
    &UNIT_Handler_OilTanker,
    &UNIT_Handler_MachineShop,
    &UNIT_Handler_Clanhall,
    &UNIT_Handler_BeastEnclosure,
    &UNIT_Handler_PowerStation,
    &UNIT_Handler_DrillRig,
    &UNIT_Handler_OilPatch,
    &UNIT_Handler_MobileDerrick,
    &UNIT_Handler_RepairStation,
    &UNIT_Handler_ResearchBuilding,
    &UNIT_Handler_ResearchBuilding,
    &UNIT_Handler_Blacksmith,
    &UNIT_Handler_RepairStation,
    &UNIT_Handler_GuardTower,
    &UNIT_Handler_GuardTower,
    &UNIT_Handler_GuardTower,
    &UNIT_Handler_GuardTower,
    &UNIT_Handler_GuardTower,
    &script_433060_ingame_menu_DA000000,
    &script_424CE0_mission_outcome_modal,
    &script_425400,
    &UNIT_Handler_General,
    &UNIT_Handler_OilTankerConvoy,
    &UNIT_Handler_Scout,
    &UNIT_Handler_Prison,
    &UNIT_Handler_Prison,
    &UNIT_AttachHandler_DockPoint,
    &UNIT_Handler_Aircraft,
    &EntityTowerAttachment_handler_4010C0,
    &EntityTowerAttachment_handler_4010E0,
    &EventHandler_Aircraft,
    &entity_mode_401480_aircraft,
    &entity_401530_aircraft,
    &entity_mode_401600_aircraft_stru31,
    &entity_mode_401660_aircraft,
    &entity_401670_aircraft,
    &entity_401680,
    &entity_mode_4016B0_aircraft,
    &entity_4017E0,
    &entity_mode_401800_aircraft,
    &UNIT_DmgHandler_Bomber,
    &Task_context_1_BomberDmgHandler_401D10,
    &Task_context_1_BomberDmgHandler_401D30,
    &Task_context_1_BomberDmgHandler_401DC0,
    &Task_context_1_BomberDmgHandler_401DE0,
    &EventHandler_BeastEnclosure,
    &entity_402150_beastenclosure,
    &UNIT_Handler_BeastEnclosure,
    &entity_mode_beastenclosure_set_default_production,
    &entity_mode_402350_beastenclosure,
    &entity_mode_beastenclosure_on_death,
    &entity_mode_402440_beastenclosure,
    &entity_blacksmith_on_upgrade_complete,
    &MessageHandler_Blacksmith,
    &UNIT_Handler_Blacksmith,
    &entity_mode_402780_blacksmith,
    &entity_mode_402840_blacksmith,
    &entity_mode_402870_blacksmith,
    &entity_mode_blacksmith_on_death,
    &entity_mode_402AB0,
    &entity_402AC0_is_mode_402AB0,
    &entity_402BB0_set_arrive_handler,
    &entity_402C40_lower_hp_mute09_surv21,
    &entity_initialize_building,
    &entity_sabotage,
    &EventHandler_DefaultBuildingsHandler,
    &script_403230_building_mini_explosion,
    &script_4032F0_building_grand_explosion,
    &script_403380_explosions,
    &entity_mode_4034B0,
    &entity_mode_403540,
    &entity_mode_4035C0_building,
    &entity_mode_403650_building,
    &entity_mode_403720_on_prison_death__or__prolly_any_generic_building,
    &entity_mode_building_default_on_death,
    &entity_4038B0,
    &entity_clanhall_on_upgrade_complete,
    &EventHandler_Clanhall,
    &entity_mode_clanhall_set_default_production,
    &UNIT_Handler_Clanhall,
    &entity_mode_clanhall_on_building_completed,
    &entity_mode_4042A0_clanhall,
    &entity_mode_clanhall_on_death_reset_production_options,
    &_4318E0_free_building_production,
    &entity_mode_clanhall_on_death,
    &entity_4054D0_tanker_convoy,
    &EventHandler_TankerConvoy,
    &entity_mode_405680_tanker_convoy,
    &entity_mode_405690,
    &entity_405750_tanker_convoy,
    &UNIT_Handler_OilTankerConvoy,
    &UNIT_Handler_MobileDerrick,
    &entity_mode_406CC0_mobilederrick,
    &EventHandler_MobileDerrick,
    &entity_mode_406DC0_mobilederrick,
    &entity_mode_plant_mobile_derrick,
    &entity_remove_unit_after_mobile_derrick_outpost_clanhall_plant,
    &UNIT_Handler_OilPatch,
    &EventHandler_Prison,
    &nullsub_1,
    &UNIT_Handler_Prison,
    &entity_mode_407300_prison,
    &entity_mode_407390_prison,
    &entity_mode_prison_spawn_unit,
    &entity_mode_prison_on_death,
    &UNIT_Handler_Prison,
    &entity_mode_prison_spawn_unit_surv09,
    &entity_mode_prison_on_death_surv09,
    &EventHandler_TechBunker,
    &entity_4075F0_techbunker,
    &entity_407690_techbunker_spawn,
    &entity_mode_407870_techbubker,
    &entity_mode_407950_techbunker_spawn_generic,
    &entity_mode_4079F0_techbunker_spawn10_surv18_lvl,
    &entity_mode_407A90_techbunker,
    &entity_mode_407B70_techbunker,
    &UNIT_Handler_TechBunker,
    &entity_mode_407C20_on_death_tech_bunker,
    &entity_mode_407C60_on_death_tech_bunker,
    &entity_mode_407D10,
    &entity_mode_hut_on_death,
    &entity_mode_407DA0,
    &EventHandler_Hut,
    &entity_mode_407E70_hut,
    &entity_mode_407F00_hut,
    &UNIT_Handler_Hut,
    &EventHandler_DrillRig,
    &UNIT_Handler_DrillRig,
    &entity_mode_4081C0_drillrig,
    &entity_mode_408240_drillrig,
    &entity_mode_408260_drillrig,
    &entity_mode_drillrig_on_death,
    &UNIT_Handler_Vehicle,
    &UNIT_Handler_Infantry,
    &entity_mode_415540_infantry,
    &entity_mode_415690,
    &entity_mode_4157F0,
    &entity_4158B0,
    &entity_mode_415980,
    &entity_415A20,
    &entity_mode_415A60_vehicle_rotate,
    &entity_mode_move_attack,
    &entity_mode_attack_move_1_415D30,
    &entity_mode_416060,
    &entity_mode_attack_move_2_5_4165C0,
    &entity_mode_416790_vehicle_move,
    &entity_mode_416A70_oiltanker,
    &entity_mode_416CD0,
    &entity_mode_416EB0,
    &entity_mode_417100,
    &entity_4172D0,
    &entity_mode_417360_infantry,
    &entity_mode_attack_move_4_417550,
    &entity_mode_417670,
    &entity_417810,
    &entity_417980,
    &entity_mode_417A20,
    &entity_mode_417BD0,
    &entity_mode_attack_move_4_order_3_7_417E60,
    &entity_mode_417F50,
    &entity_417F60,
    &entity_mode_417FC0,
    &entity_418120,
    &entity_418170,
    &entity_mode_4181B0,
    &entity_418290,
    &entity_mode_418550,
    &entity_mode_418590,
    &entity_4187F0,
    &script_418A10,
    &entity_mode_418B30,
    &entity_mode_418D20,
    &entity_mode_418E90,
    &entity_mode_418F60,
    &entity_mode_418FE0,
    &entity_mode_419180,
    &entity_mode_419230,
    &entity_4192F0,
    &entity_mode_419390_oiltanker,
    &entity_mode_move_tanker,
    &entity_419560_on_death,
    &entity_419720,
    &entity_mode_419760_infantry_destroyed,
    &entity_mode_4197E0_infantry,
    &EventHandler_Infantry,
    &EventHandler_419CA0,
    &EventHandler_General_Scout,
    &EventHandler_419DF0,
    &EventHandler_419E80,
    &entity_machineshop_on_upgrade_complete,
    &EventHandler_MachineShop,
    &entity_4220B0_machineshop,
    &UNIT_Handler_MachineShop,
    &entity_mode_machineshop_set_default_production,
    &entity_mode_machineshop_on_death_no_default,
    &entity_mode_4223A0_machineshop,
    &entity_mode_machineshop_on_death,
    &script_424BF0_mobd_20_handler,
    &_424CA0_script_47A3CC_evttrigger,
    &_424CC0_script_47A3CC_evttrigger,
    &script_424CE0_mission_outcome_modal,
    &sub_4250E0,
    &sub_4251B0,
    &script_4252C0,
    &script_425400,
    &entity_check_special_mission_death_conditions,
    &entity_find_player_entity_in_radius,
    &entity_4258C0_init_palettes_inc_unit_counter,
    &entity_mode_425920_scout,
    &entity_425A50_setup_spawn,
    &UNIT_Handler_General,
    &UNIT_Handler_Scout,
    &_425EC0_entities_check_modes,
    &FindEntityBySideAndType,
    &script_425F50_stru48_stru51_tech_bunkers,
    &script_425BE0_check_special_victory_conditions,
    &handler_4267F0,
    &nullsub_1,
    &script_426710_mission_objectives_draw_x_mark,
    &_4268B0_4269B0_task_attachment_handler,
    &_426860_4269B0_task_attachment_handler,
    &task_4269B0_mobd_20_handler,
    &UNIT_Handler_MobileOutpost,
    &entity_mode_4278C0_mobile_outpost,
    &MessageHandler_MobileOutpost,
    &nullsub_2,
    &entity_427BB0_mobile_outpost_clanhall_planting,
    &entity_mode_427BF0_mobile_outpost_clanhall_planting,
    &entity_427C30_after_mobile_outpost_clanhall_wagon_plant,
    &entity_remove_unit_after_mobile_derrick_outpost_clanhall_plant,
    &EventHandler_4089B0_generic_ai,
    &script_409770_ai,
    &script_40B700_ai,
    &EventHandler_42D6B0_evolved_mission8_ai,
    &script_42DA90_ai,
    &script_42DC70_ai,
    &EventHandler_42DC90_evolved_mission5_ai,
    &script_42DE80,
    &script_42DF20,
    &stru24_42DF40,
    &stru24_42E030,
    &stru24_42E070,
    &entity_outpost_on_upgrade_complete,
    &EventHandler_Outpost,
    &entity_mode_outpost_enable_basic_construction,
    &UNIT_Handler_Outpost,
    &entity_mode_outpost_set_default_production,
    &entity_mode_431680_outpost_arrive,
    &entity_mode_outpost_on_death_update_production,
    &_4318E0_free_building_production,
    &entity_mode_outpost_on_death,
    &EventHandler_PowerStation,
    &UNIT_Handler_PowerStation,
    &entity_mode_powerstation_spawn_tanker,
    &entity_mode_powerstation_completed,
    &entity_mode_powerstation_on_death,
    &UNIT_DmgHandler_Sapper,
    &script_435CF0_rocket_dmg_handler,
    &script_435D40_bombers_dmg,
    &UNIT_DmgHandler_Rocket,
    &script_436140_flamethrower_dmg_handler,
    &UNIT_DmgHandler_Flamethrower,
    &script_4363C0_giant_bettle_dmg,
    &UNIT_DmgHandler_Beetle,
    &script_4368B0_plasma_tank_dmg_handler,
    &UNIT_DmgHandler_Mech,
    &script_436FB0_dmg_handler,
    &script_436FF0_rifle_dmg_handler,
    &script_4370D0_gort_dmg_handler,
    &UNIT_DmgHandler_GORT,
    &UNIT_DmgHandler_Rifle,
    &sub_437690,
    &UNIT_DmgHandler_Bow,
    &UNIT_DmgHandler_Projectile,
    &EventHandler_RepairStation,
    &UNIT_Handler_RepairStation,
    &UNIT_Handler_RepairStation,
    &entity_mode_437F30_repairstation,
    &EventHandler_UpgradeProcess,
    &EntityUpgradeAttachment_438000,
    &EntityUpgradeAttachment_438030,
    &EntityUpgradeAttachment_438160_handler,
    &script_4381A0_upgrade_process,
    &EventHandler_ResearchBuilding,
    &UNIT_Handler_ResearchBuilding,
    &UNIT_Handler_ResearchBuilding,
    &entity_mode_researchlab_completed,
    &entity_mode_researchlab_on_death,
    &script_438B80_on_death_infantry_gore,
    &script_438C20_on_death_explosion,
    &entity_mode_4444D0_oiltanker,
    &entity_mode_4444F0_oiltanker,
    &entity_mode_444590_oiltanker,
    &entity_mode_444630_oiltanker,
    &entity_mode_4446B0_oiltanker_load_oil,
    &entity_mode_4447C0_oiltanker,
    &entity_mode_4448C0_oiltanker,
    &entity_mode_4449D0_oiltanker,
    &entity_mode_444A40_oiltanker,
    &entity_mode_444AB0_oiltanker,
    &entity_mode_444B40_oiltanker_unload_oil,
    &entity_mode_444CC0_oiltanker,
    &entity_mode_444D10_oiltanker,
    &entity_mode_4446A0_oiltanker,
    &EventHandler_OilTanker,
    &script_401C30_sidebar,
    &Task_context_0_4019A0,
    &Task_context_0_401A40,
    &Task_context_0_401A80,
    &Task_context_0_401AF0,
    &EventHandler_401B80,
    &UNIT_Handler_GuardTower,
    &UNIT_Handler_GuardTower,
    &UNIT_Handler_GuardTower,
    &UNIT_Handler_GuardTower,
    &UNIT_Handler_GuardTower,
    &UNIT_Handler_Towers,
    &entity_mode_4474D0_towers,
    &entity_mode_4474E0_towers,
    &entity_mode_tower_on_death,
    &entity_mode_tower_dead,
    &EventHandler_Towers,
    &UNIT_AttachHandler_Turret,
    &EntityTowerAttachment_handler_447C40,
    &EntityTowerAttachment_handler_447CA0,
    &EntityTowerAttachment_handler_447DD0,
    &EntityTowerAttachment_handler_447E20,
    &EntityTowerAttachment_handler_447F50,
    &EntityTowerAttachment_handler_447FA0,
    &EntityTowerAttachment_handler_448110,
    &EntityTowerAttachment_handler_448160,
    &EntityTowerAttachment_handler_448230,
    &EntityTowerAttachment_handler_448290,
    &EntityTowerAttachment_handler_4482D0_missile_battery,
    &nullsub_1,
    &MessageHandler_TowersAttachment,
    &UNIT_AttachHandler_Turret,
    &tower_attachment_handler_448980,
    &tower_attachment_handler_4489B0,
    &tower_attachment_handler_448B40,
    &tower_attachment_handler_448BF0,
    &tower_attachment_handler_448C40,
    &tower_attachment_handler_448E90,
    &MessageHandler_448EC0,
    &script_44BE60_explosions,
    &UNIT_AttachHandler_DockPoint,
    &EntityTurret_44BF00_handler,
    &EntityTurret_44BF70,
    &sub_44BFC0,
    &MessageHandler_EntityScript,
    (void *)0xFFFFFFFF
};
int num_script_handlers = 353; // weak


void *get_handler(int handler_id) {
    return script_handlers[handler_id].function;
}

const char *get_handler_name(int handler_id) {
    return script_handlers[handler_id].function_name;
}

int get_handler_id(void *function) {
    for (int i = 0; i < num_script_handlers; ++i) {
        if (script_handlers[i].function == function) {
            return i;
        }
    }
    return -1;
}

//----- (00445170) --------------------------------------------------------
bool script_list_alloc(int coroutine_stack_size)
{
    int v1; // esi@1
    Script *result; // eax@3
    int v3; // ecx@5

    v1 = coroutine_stack_size;
    if (!coroutine_stack_size)
        v1 = 1048576;
    result = (Script *)script_event_list_alloc();
    if (result)
    {
        result = (Script *)malloc(0x21340u);
        script_list = result;
        if (result)
        {
            v3 = 0;
            do
            {
                result[v3].next = &result[v3 + 1];
                result = script_list;
                ++v3;
            } while (v3 < 1999);
            script_list[1999].next = 0;
            script_list_free_pool = script_list;
            script_execute_list = (Script *)&script_execute_list;
            script_list_47C714 = (Script *)&script_execute_list;
            result = (Script *)coroutine_list_alloc();
            if (result)
            {
                coroutine_default_stack_size = v1;
                coroutine_current = coroutine_list_head;
                is_coroutine_list_initialization_failed = 0;
                result = (Script *)1;
            }
        }
    }
    return (BOOL)result;
}

//----- (00445210) --------------------------------------------------------
Script *script_create_coroutine(enum SCRIPT_TYPE type, void(*handler)(Script *), int stack_size, const char *debug_handler_name)
{
    Script *v3; // esi@1

    v3 = script_list_free_pool;
    if (script_list_free_pool)
    {
        script_list_free_pool = script_list_free_pool->next;

        memset(v3, SCRIPT_COROUTINE, sizeof(Script));
        v3->script_type = type;
        v3->routine_type = SCRIPT_COROUTINE;

        auto coroutine = couroutine_create(coroutine_main, debug_handler_name);
        v3->handler = (void(*)(Script *))coroutine;
        v3->debug_handler_name = debug_handler_name;

        if (coroutine)
        {
            task_creation_handler = handler;
            task_creation_handler_arg = v3;

            script_execute_list_prepend(v3);

            // call coroutine_main to queue up execution of  task_creation_handler( task_creation_handler_arg )
            coroutine->resume();

            return v3;
        }
    }

    return nullptr;
}

//----- (004452B0) --------------------------------------------------------
Script *script_create_function(enum SCRIPT_TYPE type, void(*function)(Script *), const char *function_name)
{
    Script *v2; // esi@1
    Script *result; // eax@2

    v2 = script_list_free_pool;
    if (script_list_free_pool)
    {
        script_list_free_pool = script_list_free_pool->next;
        result = 0;
        memset(v2, 0, sizeof(Script));
        v2->script_type = type;
        v2->routine_type = SCRIPT_FUNCTION;
        v2->handler = function;
        v2->debug_handler_name = function_name;
        if (function)
        {
            script_execute_list_prepend(v2);

            result = v2;
        }
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (00445310) --------------------------------------------------------
void script_deinit(Script *a1)
{
    Script *v1; // edi@1
    ScriptLocalObject *v2; // eax@1
    ScriptLocalObject *v3; // esi@2

    v1 = a1;
    v2 = a1->locals_list;
    if (v2)
    {
        do
        {
            v3 = v2->next;
            free(v2);
            v2 = v3;
        } while (v3);
    }
    script_discard_all_events(v1);
    v1->prev->next = v1->next;
    v1->next->prev = v1->prev;
    v1->next = script_list_free_pool;
    script_list_free_pool = v1;
    if (v1->routine_type == SCRIPT_COROUTINE)
        coroutine_list_remove((Coroutine *)v1->handler);
    v1->handler = 0;
}

//----- (00445370) --------------------------------------------------------
int script_445370_yield_to_main_thread(Script *a1, int flags, int a3)
{
    int v5; // eax@8
    unsigned int v6; // eax@8

    if (flags & 0x40000000 && a1->event_list)
    {
        int v4 = a1->flags_20 | 0x40000000;
        a1->flags_20 = v4;
        a1->field_24 |= v4;
    }
    if (flags & 0x80000000)
    {
        if (a3)
            a1->field_14 = a3;
        if (!a1->field_14)
        {
            a1->field_28 = 0;
            a1->field_24 |= 0x80000000;
            int v6 = a1->flags_20 | 0x80000000;
            a1->flags_20 = 0;
            return flags & v6;
        }
    }
    else if (a3)
    {
        a1->field_2C |= a3;
    }

    a1->flags_20 = 0;
    a1->field_28 = flags;
    if (a1->routine_type == SCRIPT_COROUTINE)
    {
        coroutine_list_head->resume();
        a1->field_28 = 0;
        a1->field_2C = 0;
    }
    return a1->flags_20;
}

//----- (00445400) --------------------------------------------------------
void *script_create_local_object(Script *a1, int size)
{
    Script *v2; // esi@1
    ScriptLocalObject *object; // eax@1
    ScriptLocalObject *v4; // ecx@2
    ScriptLocalObject *v5; // ecx@2

    v2 = a1;
    object = (ScriptLocalObject *)malloc(size + 8);
    if (object)
    {
        v4 = v2->locals_list;
        object->prev = 0;
        object->next = v4;
        v5 = v2->locals_list;
        if (v5)
            v5->prev = object;
        v2->locals_list = object;
        object = (ScriptLocalObject *)((char *)object + 8);
    }
    return object;
}

//----- (00445440) --------------------------------------------------------
void script_free_local_object(Script *a1, void *data)
{
    ScriptLocalObject *v2; // eax@1
    ScriptLocalObject **prev; // edx@1

    v2 = CONTAINING_RECORD(data, ScriptLocalObject, data);
    prev = (ScriptLocalObject **)*((_DWORD *)data - 1);
    if (prev)
        *prev = v2->next;
    else
        a1->locals_list = v2->next;
    if (v2->next)
        v2->next->prev = v2->prev;
    free(v2);
}

//----- (00445470) --------------------------------------------------------
void script_yield(Script *a1)
{
    int v2; // eax@1

    v2 = a1->flags_20 | 0x20000000;
    a1->flags_20 = v2;
    a1->field_24 |= v2;
    if (a1->routine_type == SCRIPT_COROUTINE)
        coroutine_list_head->resume();
}

//----- (004454A0) --------------------------------------------------------
void script_list_update()
{
    Script *i; // esi@1
    Script *v1; // edi@3
    ScriptLocalObject *v2; // eax@3
    ScriptLocalObject *v3; // ebx@4
    signed __int16 v4; // ax@9
    int v5; // eax@12
    int v6; // eax@13
    int v7; // ecx@14
    unsigned int v8; // eax@14
    int v9; // ecx@15
    int v10; // eax@16

    for (i = script_execute_list_first(); i != script_execute_list_end(); i = i->next)
    {
        if (i->flags_20 & 0x20000000)
        {
            i = i->prev;
            v1 = i->next;
            v2 = i->next->locals_list;
            if (v2)
            {
                do
                {
                    v3 = v2->next;
                    free(v2);
                    v2 = v3;
                } while (v3);
            }
            script_discard_all_events(v1);
            v1->prev->next = v1->next;
            v1->next->prev = v1->prev;
            v1->next = script_list_free_pool;
            script_list_free_pool = v1;
            if (v1->routine_type == SCRIPT_COROUTINE)
                coroutine_list_remove((Coroutine *)v1->handler);
            v1->handler = 0;
        }
        else
        {
            if (is_coroutine_list_initialization_failed)
                v4 = i->field_1C & 1;
            else
                v4 = 1;
            if (v4)
            {
                v5 = i->field_14;
                if (v5)
                {
                    v6 = v5 - 1;
                    i->field_14 = v6;
                    if (!v6)
                    {
                        v7 = i->field_24;
                        v8 = i->flags_20 | 0x80000000;
                        i->flags_20 = v8;
                        i->field_24 = v8 | v7;
                    }
                }
                v9 = i->field_28;
                if (!v9 || (v10 = i->flags_20, v9 & v10) || (int)i->field_2C & ~v10)
                {
                    switch (i->routine_type)
                    {
                    case SCRIPT_COROUTINE:
                        ((Coroutine *)i->handler)->resume();
                        break;

                    case SCRIPT_FUNCTION:
                        script_execute(i);
                        break;

                    default: __debugbreak();
                    }
                }
            }
        }
    }
}

//----- (004455A0) --------------------------------------------------------
void script_list_free()
{
    Script *v0; // ebx@2
    Script *v1; // esi@4
    ScriptLocalObject *v2; // eax@4
    ScriptLocalObject *v3; // edi@5

    if (script_list)
    {
        v0 = script_execute_list_first();
        if (coroutine_current == coroutine_list_head)
        {
            if (v0 != script_execute_list_end())
            {
                do
                {
                    v1 = v0;
                    v0 = v0->next;
                    v2 = v1->locals_list;
                    if (v2)
                    {
                        do
                        {
                            v3 = v2->next;
                            free(v2);
                            v2 = v3;
                        } while (v3);
                    }
                    script_discard_all_events(v1);
                    v1->prev->next = v1->next;
                    v1->next->prev = v1->prev;
                    v1->next = script_list_free_pool;
                    script_list_free_pool = v1;
                    if (v1->routine_type == SCRIPT_COROUTINE)
                        coroutine_list_remove((Coroutine *)v1->handler);
                    v1->handler = 0;
                } while ((Script **)v0 != &script_execute_list);
            }
            free(script_list);
            script_list = 0;
            coroutine_list_free();
            script_event_list_free();
        }
    }
}