#pragma once
#include "src/kknd.h"

void log_init();
void log(const char *, ...);

void stru28_list_free();
int stru31_list_alloc();
void stru31_list_free();
void entity_401070_stru31(Entity *a1);
void UNIT_AttachHandler_DockPoint(Script *self);
void EntityTowerAttachment_handler_4010C0(EntityTurret *a1);
void EntityTowerAttachment_handler_4010E0(EntityTurret *a1);
void entity_401110_aircraft(Entity *a1);
void EventHandler_Aircraft(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void UNIT_Handler_Aircraft(Script *a1);
void entity_mode_401480_aircraft(Entity *a1);
void entity_401530_aircraft(Entity *a1, int a2);
void entity_mode_401600_aircraft_stru31(Entity *a1);
void entity_mode_401660_aircraft(Entity *a1);
void entity_401670_aircraft(Entity *a1);
void entity_401680(Entity *a1);
void entity_mode_4016B0_aircraft(Entity *a1);
void entity_4017E0(Entity *a1);
void entity_mode_401800_aircraft(Entity *a1);
void Task_context_0_4019A0(Task_context_0 *a1);
void Task_context_0_401A40(Task_context_0 *a1);
void Task_context_0_401A80(Task_context_0 *a1);
void Task_context_0_401AF0(Task_context_0 *a1);
void EventHandler_401B80(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void script_401C30_sidebar(Script *a1);
void Task_context_1_BomberDmgHandler_401D10(Task_context_1_BomberDmgHandler *a1);
void Task_context_1_BomberDmgHandler_401D30(Task_context_1_BomberDmgHandler *a1);
void Task_context_1_BomberDmgHandler_401DC0(Task_context_1_BomberDmgHandler *a1);
void Task_context_1_BomberDmgHandler_401DE0(Task_context_1_BomberDmgHandler *a1);
void UNIT_DmgHandler_Bomber(Script *a1);
bool BeastEnclosureAllowsNuke();
void EventHandler_BeastEnclosure(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void entity_402150_beastenclosure(Entity *a1);
void UNIT_Handler_BeastEnclosure(Script *a1);
void entity_mode_beastenclosure_set_default_production(Entity *a1);
void entity_mode_402350_beastenclosure(Entity *); // idb
void entity_mode_beastenclosure_on_death(Entity *); // idb
void entity_mode_402440_beastenclosure(Entity *a1);
void entity_blacksmith_on_upgrade_complete(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void MessageHandler_Blacksmith(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void UNIT_Handler_Blacksmith(Script *a1);
void entity_mode_402780_blacksmith(Entity *a1);
void entity_mode_402840_blacksmith(Entity *); // idb
void entity_mode_402870_blacksmith(Entity *a1);
void entity_mode_blacksmith_on_death(Entity *a1);
bool coroutine_list_alloc();
Coroutine *couroutine_create(void(*function)(), size_t stack_size, const char *debug_handler_name);
void coroutine_list_remove(Coroutine *a1);
int script_execute(Script *self);
void coroutine_list_free();
int coroutine_resume(Coroutine *self); // idb
void entity_mode_402AB0(Entity *);
bool entity_402AC0_is_mode_402AB0(Entity *a1);
void entity_attach_docking_point(Entity *a1);
DrawJob *entity_402BB0_set_arrive_handler(Entity *a1, void(*mode_arrive)(Entity *));
void entity_402C40_lower_hp_mute09_surv21(Entity *a1);
void entity_initialize_building(Entity *a1, __int16 sabotage_points, void(*mode_turn_return)(Entity *), void(*mode_return)(Entity *));
bool entity_sabotage(Entity *a1, void *param, void(*on_death_mode)(Entity *));
int entity_402E40_destroy(Entity *a1, void(*new_mode)(Entity *)); // idb
void entity_402E90_on_damage(Entity *a1, void *param, void(*on_death_mode)(Entity *)); // idb
void EventHandler_DefaultBuildingsHandler(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void script_403230_building_mini_explosion(Script *a1); // idb
void script_4032F0_building_grand_explosion(Script *a1); // idb
void script_403380_explosions(Script *a1); // idb
void entity_mode_4034B0(Entity *a1);
void entity_mode_403540(Entity *a1);
void entity_mode_4035C0_building(Entity *a1);
void entity_mode_403650_building(Entity *a1);
void entity_mode_403720_on_prison_death__or__prolly_any_generic_building(Entity *a1);
void entity_mode_building_default_on_death(Entity *a1);
void entity_4038B0(Entity *a1, enum PLAYER_SIDE side);
int building_limits_list_alloc();
int building_limits_count(enum UNIT_ID unit_stats_idx);
bool building_limits_can_build(enum UNIT_ID unit_id);
int building_limits_on_new_building(enum UNIT_ID stats_idx);
void building_limits_on_building_destroyed(Entity *a1);
void building_limits_list_free();
int sub_403B70(CHAR a1);
int get_max_clanhall_level();
bool is_clanhall_maxed();
void entity_clanhall_on_upgrade_complete(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void EventHandler_Clanhall(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void entity_mode_clanhall_set_default_production(Entity *a1);
void UNIT_Handler_Clanhall(Script *task);
void entity_mode_clanhall_on_building_completed(Entity *a1);
void entity_mode_4042A0_clanhall(Entity *a1);
void entity_mode_clanhall_on_death_reset_production_options(Entity *); // idb
bool is_tower_available(enum UNIT_ID unit_id);
bool is_building_available(enum UNIT_ID a1);
void entity_mode_clanhall_on_death(Entity *); // idb
void copy_player_sprite_palette_aligned(unsigned __int8 *palette, unsigned __int8 *aligned);
bool sub_404530(Sprite *a1, Sprite *a2, int a3, void *a4, void *a5);
bool sub_404760(Sprite *a1, Sprite *a2, int a3, void *a4, void *a5);
bool sub_4047E0(Sprite *a1, Sprite *a2, int a3, void *a4, void *);
bool sub_404870(Sprite *a1, Sprite *a2, int a3, void *a4, void *);
bool sub_404900(Sprite *a1, Sprite *a2, int a3, void *a4, void *);
bool sub_4049D0(Sprite *a1, Sprite *a2, int a3, void *a4, void *);
bool sub_404AA0(Sprite *a1, Sprite *a2, int a3, void *a4, void *);
bool sub_404B80(Sprite *a1, Sprite *a2, int a3, void *a4, void *);
bool sub_404C60(Sprite *a1, Sprite *a2, int a3, void *a4, void *a5);
bool boxd_init();
void bodx_404D50_sprite_list(Sprite *list);
void boxd_404F40_sprite(Sprite *a1, int a2, int a3);
void boxd_free();
void entity_show_hint(Entity *a1);
void entity_4054D0_tanker_convoy(Entity *a1);
void EventHandler_TankerConvoy(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void entity_mode_405680_tanker_convoy(Entity *);
void entity_mode_405690(Entity *a1);
void entity_4056E0_tanker_convoy_update_checkpoint(int x, EntityTankerConvoyAttachment *a2);
bool entity_405750_tanker_convoy(Entity *a1);
void UNIT_Handler_OilTankerConvoy(Script *a1);
bool render_string_4059C0(RenderString *a1, int a2, int a3);
void render_string_405A20(RenderString *a1, int a2, int y);
void render_string_405A60(RenderString *a1, const char *str, DataMobdItem *custom_font, int y);
void script_credits_or_custom_mission_briefing_loop(Script *a1);
bool cplc_init();
bool cplc_select(int id);
void cplc_4060F0();
void cplc_create_sprite_script(DataCplcItem_ptr1 *a1);
void cplc_4062E0_stru0_list_remove(DataCplc_stru0 *a1);
void cplc_406320();
void cplc_init_script_do_reinit(int a1);
void cplc_init_script(int handler_id, bool reinit_ptrs);
void cplc_init_script_dont_reinit(int a1);
void cplc_free();
void UNIT_Handler_MobileDerrick(Script *a1);
void entity_initialize_mobile_derrick(Entity *a1);
void entity_mode_406CC0_mobilederrick(Entity *a1);
void EventHandler_MobileDerrick(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void entity_mode_406DC0_mobilederrick(Entity *a1);
void entity_mode_plant_mobile_derrick(Entity *a1);
void entity_remove_unit_after_mobile_derrick_outpost_clanhall_plant(Entity *a1);
bool oilspot_list_alloc();
void oilspot_list_free();
OilDeposit *oilspot_list_407040_find_by_coordinates(int x, int y); // idb
OilDeposit *oilspot_list_407090_find_by_sprite_coordinates(int x, int y); // idb
int oilspot_subtract_oil(OilDeposit *a1, int amount); // idb
void UNIT_Handler_OilPatch(Script *a1); // idb
void EventHandler_Prison(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void entity_mode_407300_prison(Entity *a1);
void entity_mode_407390_prison(Entity *a1);
void UNIT_Handler_Prison(Script *a1);
void entity_mode_prison_spawn_unit(Entity *a1);
void entity_mode_prison_on_death(Entity *a1);
void entity_mode_prison_spawn_unit_surv09(Entity *a1);
void entity_mode_prison_on_death_surv09(Entity *a1);
void EventHandler_TechBunker(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void entity_4075F0_techbunker(Entity *a1);
void entity_mode_407630_bunker(Entity *a1);
void entity_407690_techbunker_spawn(Entity *a1);
void entity_mode_407870_techbubker(Entity *a1);
Entity *entity_4078B0_techbunker_find_entity(Entity *a1, int a2); // idb
void entity_mode_407950_techbunker_spawn_generic(Entity *a1);
void entity_mode_4079F0_techbunker_spawn10_surv18_lvl(Entity *a1);
void entity_mode_407A90_techbunker(Entity *a1);
void entity_mode_407B70_techbunker(Entity *a1);
void UNIT_Handler_TechBunker(Script *a1);
void entity_mode_407C20_on_death_tech_bunker(Entity *a1);
void entity_mode_407C60_on_death_tech_bunker(Entity *a1);
void entity_mode_407D10(Entity *a1);
void entity_mode_hut_on_death(Entity *a1);
void entity_mode_407DA0(Entity *a1);
void EventHandler_Hut(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void entity_mode_407E70_hut(Entity *a1);
void entity_mode_407F00_hut(Entity *a1);
void UNIT_Handler_Hut(Script *a1);
void EventHandler_DrillRig(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void UNIT_Handler_DrillRig(Script *a1);
void entity_mode_4081C0_drillrig(Entity *a1);
void entity_mode_408240_drillrig(Entity *a1);
void entity_mode_408260_drillrig(Entity *a1);
void entity_mode_drillrig_on_death(Entity *a1);
void script_408370(Script *a1);
void sub_4083D0();
int sub_408400();
void _408410_palettes();
void sub_408460();
void stru1_408480_reset_animation();
void script_4084A0_animation(Script *a1);
void script_408500_anim(Script *a1);
void _408550_multi_pal();
bool stru1_init_anim();
void stru1_set_animation(stru1_draw_params *a1, int start, int end, int length);
void sprite_408800_play_sound(Sprite *a1, enum SOUND_ID sound, int volume, Script *script);
void stru1_animate();
void EventHandler_4089B0_generic_ai(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
int stru24_409540(stru24 *a1, Sprite *a2); // idb
stru24_stru310 *stru24_4095B0(stru24 *a1, Entity *a2);
stru24_DrillRigNode **stru24_409650(stru24 *a1);
void script_409770_ai(Script *a1);
bool sub_40AB60(stru24_stru310 *a1);
int sub_40AFC0(stru24 *a1, stru24_stru160 *a2, int a3, int a4); // idb
stru24_EnemyNode **stru24_40B020(stru24 *a1, stru24_stru160 *a2); // idb
int stru24_40B190(stru24 *a1, int size, int x, int y); // idb
void stru24_40B230(stru24 *a1);
stru24_stru160 *stru24_40B410(stru24 *a1, stru24_stru160 *a2, int a3, int a4); // idb
bool stru24_40B490(stru24 *a1, UNIT_ID a2, int *out_x, int *out_y);
void script_40B700_ai(Script *a1);
int UNIT_InitAiPlayers();
void UNIT_FreeAiPlayers();
int VIDEO_IsAllocated();
int VIDEO_ReadAndAllocDrawJob(const char *a1, int x, int y, int z_index);
int VIDEO_DoFrame();
void VIDEO_40D090(VideoFile *a1);
void VIDEO_free();
bool VIDEO_IsVideoInvalid();
bool VIDEO_ReadAndAllocDrawJob_2(const char *a1, stru1_draw_params *a2, stru1_draw_params *a3, RenderString *a4, int width, int height, int z_index);
void VIDEO_40D430(RenderString *a1);
void VIDEO_40D450(char *a1, int a2);
int timer_init(unsigned int fps);
void TimedMessagePump();
int entity_40D600_infantry_get_new_movement_orientation(Entity *a1, int sprite_width, int sprite_height, int a4);
int entity_40D6F0_vehicle_get_new_movement_orientation(Entity *a1, int sprite_width, int sprite_height, int a4);
bool _40D860_prolly_sprite_distance(Sprite *a1, Sprite *a2, int a3); // idb
int sprite_40D8B0_dmg(Sprite *a1, int a2); // idb
int entity_40DA90_update_tile_info(Entity *a1);
bool entity_40DBF0_boxd_does_unit_fit(Entity *a1);
bool entity_40DD00_boxd(Entity *a1);
int entity_40DDD0_boxd(Entity *a1);
int entity_40DE80_boxd(Entity *a1, int x, int y, int a3); // idb
char *entity_40DEC0_boxd(Entity *a1, int a2, int a3, int a4);
void entity_40DF50_boxd_update_map_tile(Entity *a1, int a2);
int entity_40E000_boxd(Entity *a1, int a2, int a3);
int entity_40E1B0_boxd(Entity *a1, int x, int y, int a4); // idb
int REND_SetRoutines();
bool GAME_SetResolution();
char *get_resource_res_subfolder();
void _40E400_set_palette(PALETTEENTRY *palette);
void _40E430_update_palette(unsigned int a1);
void RENDER_SetViewportAndClear();
PALETTEENTRY *sub_40E550();
void _40E560_flip_gdi_update_syscolors();
void _40E6B0_set_sys_colors();
bool boxd_40E6E0();
void boxd_40EA20();
void boxd_40EA30_cleanup();
int boxd_40EA50(Entity *a1, int map_x, int map_y, DataBoxd_stru0_per_map_unit *a4);
int boxd_40ED00(Entity *a1, DataBoxd_stru0_per_map_unit *a2);
bool boxd_40EDF0(DataBoxd_stru0_per_map_unit *a1, Entity *a2, Entity *a3);
Entity *boxd_40EE10_prolly_get_building(int map_x, int map_y); // idb
int boxd_40EE70(int map_x, int map_y); // idb
int boxd_40EEB0(Entity *a1, int map_x, int map_y, int a4);
int entity_40F0A0_get_dx(Entity *a1, int a2); // idb
int entity_40F100_get_dy(Entity *a1, int a2); // idb
int boxd_40F160(Entity *a1, int map_x, int map_y, int a4);
void boxd_40F230_update_map_tile(Entity *a1, int map_x, int map_y, int a4, int a5);
void sub_40F380_incdec(int inc_dec);
bool sidebar_button_list_alloc();
void script_sidebar(Script *a1); // idb
Sidebar *sidebar_list_create(Sprite *sprite, Script *script, int width, int height, int sidebar_horizontal); // idb
void script_40F5D0_sidebar_button_1_2(Script *a1); // idb
void script_40F8F0_sidebar_button_3(Script *a1); // idb
void script_40FC10_sidebar_button_4(Script *a1);
SidebarButton *sidebar_add_button_1(Sidebar *sidebar, int mobd_lookup_table_offset, void(*open_handler)(SidebarButton *), void *param, void *task_context); // idb
SidebarButton *sidebar_add_button_2(Sidebar *sidebar, int mobd_lookup_table_offset, void(*button_open_handler)(SidebarButton *), void(*button_close_handler)(SidebarButton *), void *task_context); // idb
SidebarButton *sidebar_add_button_3(Sidebar *sidebar, int mobd_lookup_table_offset, void(*button_open_handler)(SidebarButton *), void(*button_close_handler)(SidebarButton *), void *task_context); // idb
SidebarButton *sidebar_add_button_4(Sidebar *sidebar, int mobd_lookup_table_offset, void(*button_open_handler)(SidebarButton *), int a4, int a5, void *param, enum UNIT_ID a7); // idb
SidebarButton *sidebar_add_buttton_internal(Sidebar *a1, int mobd_lookup_table_offset, void(*task_routine)(Script *), void(*open_handler)(SidebarButton *), void(*close_handler)(SidebarButton *), void *param, void *task_context, enum SCRIPT_TYPE event); // idb
void sidebar_remove_button(Sidebar *a1, SidebarButton *a2); // idb
void sidebar_list_remove(Sidebar *a1);
void sidebar_list_free();
bool stru2_list_alloc();
stru2 *stru2_list_create(int hunk);
int stru2_list_init_elements();
void stru2_list_remove_elements();
void stru2_list_free();
void entity_410520_update_healthbar_color(Entity *a1); // idb
__int16 entity_410640_tanker_status_bar(Entity *a1); // idb
int entity_410710_status_bar(Entity *a1);
void entity_4107B0_oiltanker_oil_bar(Entity *a1);
void entity_update_sabotage_bar(Entity *a1);
void entity_410950(Entity *a1, int a2);
void entity_4109A0_status_bar(Entity *a1);
void entity_410B00_building_status_bar(Entity *a1);
void entity_410BE0_status_bar(Entity *a1);
void entity_410CB0_event1511(Entity *a1);
void entity_410CD0_eventTextString(Entity *a1);
void entity_410CF0_aircraft(Entity *a1);
void entity_set_draw_handlers(Entity *a1);
void entity_410DC0_building(Entity *a1);
void entity_oil_tanker_initialize_state(Entity *a1);
bool stru27_array_initialize();
bool stru26_array_initialize();
void stru26_stru27_free();
int __stdcall WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam); // idb
void UNIT_Handler_Vehicle(Script *a1); // idb
void UNIT_Handler_Infantry(Script *a1);
void entity_init_infantry(Entity *a1);
void entity_attach_turret(Entity *a1);
bool entity_413120(Entity *a1, Entity *a2, int entity_id);
void entity_4133D0(Entity *a1);
bool entity_4135E0(Entity *a1);
bool entity_413860_boxd(Entity *a1);
bool entity_413A90_boxd(Entity *a1);
int entity_413C10(Entity *a1);
bool entity_initialize_order(Entity *a1);
void entity_414440_boxd(Entity *a1, int *a2, int *a3);
bool entity_414520_boxd(Entity *a1);
void entity_414670(Entity *a1);
bool entity_414870_boxd(Entity *a1);
void entity_4149A0(Entity *a1);
bool entity_414AD0_vehicle_collide_vehicle(Entity *a1);
void entity_414C30_boxd(Entity *a1);
void entity_414E80(Entity *a1);
bool entity_415400_tanker(Entity *a1);
void entity_mode_415540_infantry(Entity *a1);
void entity_mode_415690(Entity *a1);
void entity_mode_4157F0(Entity *a1);
void entity_4158B0(Entity *a1);
void entity_mode_415980(Entity *a1);
void entity_415A20(Entity *a1);
void entity_mode_415A60_vehicle_rotate(Entity *a1);
void entity_mode_move_attack(Entity *a1);
void entity_mode_attack_move_1_415D30(Entity *a1);
void entity_mode_416060(Entity *a1);
void entity_mode_attack_move_2_5_4165C0(Entity *a1);
void entity_mode_416790_vehicle_move(Entity *a1);
void entity_mode_416A70_oiltanker(Entity *a1);
void entity_mode_416CD0(Entity *a1);
void entity_mode_416EB0(Entity *a1);
void entity_mode_417100(Entity *a1);
void entity_4172D0(Entity *a1);
void entity_mode_417360_infantry(Entity *a1);
void entity_mode_attack_move_4_417550(Entity *a1);
void entity_mode_417670(Entity *a1);
void entity_417810(Entity *a1);
void entity_417980(Entity *a1);
void entity_mode_417A20(Entity *a1);
void entity_mode_417BD0(Entity *a1);
void entity_mode_attack_move_4_order_3_7_417E60(Entity *a1);
void entity_mode_417F50(Entity *a1);
void entity_417F60(Entity *a1);
void entity_mode_417FC0(Entity *a1);
void entity_418120(Entity *a1);
void entity_418170(Entity *a1);
void entity_mode_4181B0(Entity *a1);
void entity_418290(Entity *a1);
void entity_mode_418550(Entity *a1);
void entity_mode_418590(Entity *a1);
void entity_4187F0(Entity *a1);
void script_4188F0(Script *); // idb
void script_418A10(Script *); // idb
void entity_mode_418B30(Entity *a1);
void entity_mode_418D20(Entity *a1);
void entity_mode_418E90(Entity *a1);
void entity_mode_418F60(Entity *a1);
void entity_mode_418FE0(Entity *a1);
void entity_mode_419180(Entity *a1);
void entity_mode_419230(Entity *a1);
char *entity_4192F0(Entity *a1);
void entity_mode_419390_oiltanker(Entity *a1);
void entity_mode_move_tanker(Entity *a1);
void entity_419560_on_death(Entity *a1);
void entity_419720(Entity *a1);
void entity_mode_419760_infantry_destroyed(Entity *a1);
void entity_mode_4197E0_infantry(Entity *a1);
void EventHandler_Infantry(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void EventHandler_419CA0(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void EventHandler_General_Scout(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void EventHandler_419DF0(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void EventHandler_419E80(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void entity_41A060_evt1525(Entity *a1, void *a2); // idb
void entity_41A170_evt1524(Entity *a1, int a2);
void entity_41A400_evt1547(Entity *a1, Entity *a2);
void entity_41A470(Entity *a1, Entity *a2);
void entity_41A510_evt1503(Entity *a1, int a2);
void entity_41A610_evt1503(Entity *a1, void *a2); // idb
void entity_41A6D0_evt1497(Entity *a1, Entity *a2);
void entity_41A850_evt1507_mess_with_stru11(Entity *a1, void *param);
void entity_41A890_evt1528(Entity *a1);
void entity_41A980_evt1509_unset_stru11(Entity *a1, void *param);
void entity_41A9B0_unit(Entity *a1, int a2);
bool array_479B98_array_479C60_init();
__int16 input_get_string(const char *a1, unsigned __int16 a2, void(*handler)(const char *, int), int a4, Script *a5);
bool _41B000_stru7_handler(Sprite *a1, Sprite *a2, int a3, void *a4, void *a5);
bool _41B020_stru7_handler(Sprite *a1, Sprite *a2, int a3, void *a4, void *a5);
bool _41B070_stru7_handler(Sprite *a1, Sprite *a2, int a3, void *a4, void *a5);
bool LVL_SysInit();
DataHunk *LVL_LoadLevel(const char *filename);
bool LVL_RunLevel(DataHunk *lvl);
void LVL_Deinit();
void GAME_Deinit();
void *LVL_FindSection(const char *name);
DataMapd *LVL_FindMapd();
bool LVL_SubstHunk(DataHunk *dst, DataHunk *src, const char *hunk);
bool entity_41B510(Entity *a1, Entity *a2);
int entity_41B970_boxd(Entity *a1, int a2, int a3); // idb
int boxd_41BA30(int x, int y, int a3, int a4, int x_step, int y_step, Entity *a1);
int boxd_41BC60(int x, int y, int a3, int a4, int a5, int a6, Entity *a7);
int boxd_41BE90(_DWORD *a1, int a2, _DWORD *a3, _DWORD *a4, Entity *a5, int *a6, int *a7, int *a8, int map_x, int map_y, _DWORD *a11, _DWORD *a12);
int boxd_41C060(int a1, Entity *a2, int a3, int a4, int *a5, int *a6, int *a7, int a8);
bool boxd_41C130(int x, int y, int z, int w, Entity *entity);
bool boxd_41C190(int x, int y, int z, int w, Entity *a5);
bool boxd_41C250(int x, int y, int z, int w, Entity *a5);
bool boxd_41C660(int x, int y, int width, int height, int a5, int a6, Entity *a7);
bool boxd_41C890(int x, int y, int width, int height, int a5, int a6, Entity *a7);
bool is_game_loading();
bool is_game_saving();
bool _41CAE0_prepare_to_load_level(const char *a1, enum LEVEL_ID level);
bool __41CB30_prepare_to_save_level(const char *a1, enum LEVEL_ID level);
enum LEVEL_ID get_saveload_level_id();
OilDepositSaveStruct *GAME_Save_PackOilData(size_t *oil_data_size);
int GAME_Load_UnpackOilData(OilDepositSaveStruct *a1);
bool GAME_Save_PackEntity(Entity *entity, int save_data, int save_data_size);
bool GAME_Save_PackSprite(Sprite *a1, SpriteSerialized *out);
bool GAME_Load_UnpackEntity(Entity *a1, EntitySerialized *save_data);
Sprite *GAME_Load_UnpackSprite(SpriteSerialized *serialized);
char *GAME_Save_PackProductionInfo(size_t *size);
bool GAME_Load_UnpackProductionInfo(void *a1);
void sub_41ED90(void *a1, stru24_struC *a2);
void sub_41EE20(stru24 *a1, int a2, stru24_stru160 *a3);
void *GAME_Save_PackAiPlayers(size_t *size);
bool GAME_Load_UnpackAiPlayers(void *save_data);
_BYTE *GAME_Save_PackMapInfo(int *a1);
MiscSaveStruct *GAME_Save_PackMiscInfo(size_t *a1);
bool GAME_Load_UnpackMiscInfo(void *save_data);
int GAME_Save();
int GAME_Load();
void GAME_OnSaveFailed();
void script_421D60_on_savegame_failed(Script *a1);
bool is_machine_shop_maxed();
void entity_machineshop_on_upgrade_complete(Script *receiver, Script *sender, enum SCRIPT_EVENT message, void *param);
void EventHandler_MachineShop(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void entity_4220B0_machineshop(Entity *a1);
void UNIT_Handler_MachineShop(Script *a1);
void entity_mode_machineshop_set_default_production(Entity *a1);
void entity_mode_machineshop_on_death_no_default(Entity *); // idb
void entity_mode_4223A0_machineshop(Entity *a1);
void entity_mode_machineshop_on_death(Entity *); // idb
void _4224B0_update_last_level();
void GAME_ReadRegistry();
bool GAME_ShowWait();
void GAME_PrepareSuperLvl(int mapd_idx);
int VIDEO_Play(int id);
void GAME_PrepareLevel();
bool on_level_finished();
int GAME_Main();
void script_custom_mission_briefing_loop(Script *a1); // idb
void _423C60_custom_mission_make_briefing_lines(int a1);
void cplc_init_sripts_with_reinit();
void cplc_init_scripts();
void set_player_side_by_level();
char GAME_ParseCommandLine();
void _4240E0_kknd_sve_read(const char *filename);
void _424270_kknd_sve_read(const char *a1, _WORD *a2, _WORD *a3);
void _4243C0_kknd_sve_update_last_level(const char *a1);
bool _424560_parse_unit_stats_table(const char *filename);
void UNIT_Handler_TechBunker_2(Script *a1);
void script_424BF0_mobd_20_handler(Script *a1);
void _424CA0_script_47A3CC_evttrigger();
void _424CC0_script_47A3CC_evttrigger();
void script_424CE0_mission_outcome_modal(Script *a1); // idb
int sub_424EC0();
int sub_424FD0();
int sub_4250E0();
int sub_4251B0();
void script_4252C0(Script *a1, void *param);
void script_425400(Script *a1); // idb
void script_47A3CC_die();
void entity_check_special_mission_death_conditions(Entity *victim);
Entity *entity_425820_find(Entity *a1, int a2); // idb
void entity_4258C0_init_palettes_inc_unit_counter(Entity *a1, enum PLAYER_SIDE side);
void entity_mode_425920_scout(Entity *a1);
void entity_425A50_setup_spawn(Entity *a1, void *spawn_param, int spawn_type); // idb
void UNIT_Handler_General(Script *a1);
void UNIT_Handler_Scout(Script *a1);
void script_425BE0_check_special_victory_conditions(Script *a1); // idb
int sub_425EC0(enum UNIT_ID a1, enum PLAYER_SIDE a2);
Entity *sub_425F20(enum UNIT_ID unit_id, enum PLAYER_SIDE side); // idb
void script_425F50_stru48_stru51_tech_bunkers(Script *a1);
void script_426680_cursor_mobd(Script *a1); // idb
void script_426710_mission_objectives_draw_x_mark(Script *a1);
bool handler_4267F0(enum UNIT_ID unit_id, int x, int y, enum PLAYER_SIDE side);
void _426860_4269B0_task_attachment_handler(_4269B0_task_attachment *a1);
void _4268B0_4269B0_task_attachment_handler(_4269B0_task_attachment *a1);
void task_4269B0_mobd_20_handler(Script *a1);
void drawjob_update_handler_426C40_mobd(Sprite *a1, DrawJob *a2);
bool sprite_list_alloc();
void sprite_init_47A400();
Sprite *sprite_create(enum MOBD_ID mobd_item_idx, Script *script, Sprite *parent);
Sprite *sprite_create_scripted(enum MOBD_ID mobd_item_idx, Sprite *parent, void(*script)(Script *), enum SCRIPT_ROUTINE_TYPE task_type, Entity_stru_dmg_related *a5);
void sprite_list_remove(Sprite *a1);
void sprite_list_remove_scripted(Sprite *a1);
Sprite *sprite_list_find_by_mobd_id(enum MOBD_ID mobd_id);
void sprite_list_update_positions();
void sprite_load_mobd(Sprite *a1, int offset); // idb
void sprite_4272E0_load_mobd_item(Sprite *a1, int lookup_table_offset, int lookup_idx); // idb
void sprite_427320_load_mobd_item_sound(Sprite *a1, int offset); // idb
void sprite_4273B0_load_mobd_item_sound(Sprite *a1, int mobd_lookup_offset, int mobd_lookup_id); // idb
void sprite_release_mobd_item(Sprite *a1);
void sprite_427460_init_mobd_item(Sprite *pstru6);
void sprite_list_init_mobd_items();
void sprite_list_free();
void UNIT_Handler_MobileOutpost(Script *a1);
void entity_mobile_outpost_init(Entity *a1);
void entity_mode_4278C0_mobile_outpost(Entity *a1);
void MessageHandler_MobileOutpost(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void __stdcall nullsub_2(int a1, int a2);
void entity_4279E0_mobile_outpost_clanhall_wagon_plant(Entity *a1);
void entity_427BB0_mobile_outpost_clanhall_planting(Entity *a1);
void entity_mode_427BF0_mobile_outpost_clanhall_planting(Entity *a1);
void entity_427C30_after_mobile_outpost_clanhall_wagon_plant(Entity *a1);
bool stru37_stru38_list_alloc();
void stru37_list_427D60_enqueue_item(int *pcash, int *pcost, int cost_per_time_step, Script *production_task, void *production_task_param, int a6); // idb
void stru37_list_427D80_enqueue_item(int *pcash, int *pcost, int cost, int cost_per_time_step, Script *production_task, void *production_task_param, int a7); // idb
void stru37_list_427E90_enqueue_infantry(int *pcash, int *pcost, int cost_per_time_step, Script *production_task, void *production_task_param, int a6); // idb
void stru37_list_427EB0_enqueue_infantry(int *pcash, int *pcost, int cost, int cost_per_time_step, Script *production_task, void *production_task_param, int a7); // idb
void stru38_list_427FD0(int *pcost, int a2); // idb
void add_integer(int *a1, int a2); // idb
void stru37_stru38_list_free();
void script_4280A0_stru38_list__production_loop(Script *task);
bool stru13construct_list_alloc();
void stru13_list_free();
int stru13construct_list_get_saveload_packed_size();
bool stru13construct_list_saveload_pack(stru13constructSaveStruct *a1);
bool stru13construct_list_saveload_unpack(int save_data, int save_data_size);
bool is_building_or_tower_available(enum UNIT_ID unit_id);
bool sub_42C810(Sprite **sprite_list, int x, int y, int a4, int map_x, int a6, int a7);
void sub_42C9C0(Sprite **sprite_list);
void script_42D030_sidebar_tooltips(Script *a1);
void _41AC50_read_keyboard_input___42D220_handler(const char *a1, int a2);
char render_string_42D260(RenderString *a1, const char *a2, DataMobdItem *custom_font); // idb
void script_42D390_cursors(Script *a1); // idb
int _47A660_list_reset();
int _42D560_get_mobd_lookup_id_rotation(int x, int y); // idb
__int16 _42D639_mobd_lookup(int x, int y); // idb
__int16 _42D63B_mobd_do_lookup(int x, int y); // idb
unsigned int math_42D64D_prolly_vec_length(int a1, int a2);
unsigned int math_42D669_prolly_vec_length(unsigned int a1);
void EventHandler_42D6B0_evolved_mission8_ai(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void script_42DA90_ai(Script *a2);
void script_42DC70_ai(Script *a1);
void EventHandler_42DC90_evolved_mission5_ai(Script *a1, Script *a2, enum SCRIPT_EVENT event, Entity *param);
void script_42DE80(Script *a1);
void script_42DF20(Script *a1);
Entity *stru24_42DF40(stru24 *a1, Entity *a2, int *a3); // idb
void stru24_42E030(stru24 *a1, Entity *a2);
void stru24_42E070(stru24 *a1);
void _430F10_unit_inits();
void entity_register_player_main_building(Entity *a1);
void entity_430F90_clanhall(Entity *a1);
int get_max_outpost_level();
bool is_outpost_maxed();
void entity_outpost_on_upgrade_complete(Script *receiver, Script *sender, enum SCRIPT_EVENT message, void *param);
void EventHandler_Outpost(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void entity_mode_outpost_enable_basic_construction(Entity *a1);
void UNIT_Handler_Outpost(Script *a1);
void entity_mode_outpost_set_default_production(Entity *a1);
void entity_mode_431680_outpost_arrive(Entity *a1);
void entity_mode_outpost_on_death_update_production(Entity *a1);
void _4318E0_free_building_production();
void entity_mode_outpost_on_death(Entity *a1);
void render_sw_initialize();
void render_sw_free_palette();
void _431980_update_primary_palette(PALETTEENTRY *palette_entries);
HPALETTE _431B60_create_palette(PALETTEENTRY *a1, int num_entries); // idb
void script_431E60_mobd_20_input(Script *a1);
void script_431F10_ingame_menu(Script *a1); // idb
void script_4321A0_ingame_menu(Script *a1);
void script_4322D0_ingame_menu(Script *a1);
void script_432400_ingame_menu_create_sprites(Script *a1);
void script_432510_ingame_menu_create_sprites(Script *a1);
void script_4325B0_ingame_menu_trigger_events(Script *a1);
void script_432620_ingame_menu(Script *a1);
void script_432730_ingame_menu(Script *a1); // idb
void script_432800_ingame_menu(Script *a1); // idb
void _41AC50_read_keyboard_input___handler_4328F0(const char *a1, int a2);
void script_432990_ingame_menu_read_keyboard_input(Script *a1, int a2, int a3); // idb
void script_432F00_ingame_menu(Script *a1); // idb
void script_432F20_ingame_menu_read_keyboard_input(Script *);
void script_432F30_ingame_menu_read_keyboard_input(Script *a1); // idb
void script_432F40_ingame_menu(Script *a1);
void script_433060_ingame_menu_DA000000(Script *a1);
void script_433640(Script *a1, enum SCRIPT_TYPE event, int x_offset, int y_offset, int z_index_offset);
void script_4336E0(Script *script, enum SCRIPT_TYPE type, int x_offset, int y_offset, int z_index_offset);
void script_433780_ingame_menu(Script *a1); // idb
void script_433810_ingame_menu(Script *a1); // idb
void script_433880_ingame_menu(Script *a1); // idb
void script_4338F0_ingame_menu(Script *a1); // idb
void script_433960_ingame_menu(Script *a1); // idb
void script_4339F0_ingame_menu(Script *a1); // idb
void script_433A60_ingame_menu(Script *a1); // idb
void script_433AF0_ingame_menu(Script *a1); // idb
void script_433BA0_ingame_menu(Script *a1); // idb
void script_433C30_ingame_menu(Script *a1); // idb
void script_433C90_ingame_menu(Script *a1); // idb
void script_433D20_ingame_menu(Script *a1); // idb
void script_433DB0_ingame_menu(Script *a1); // idb
void script_433E60_ingame_menu(Script *a1); // idb
void script_433ED0_ingame_menu(Script *a1); // idb
void script_433F40_ingame_menu(Script *a1); // idb
void script_433FB0_ingame_menu(Script *a1); // idb
void script_434040_ingame_menu_load_game_related(Script *a1); // idb
void script_4340B0_ingame_menu(Script *a1); // idb
void script_434120_ingame_menu(Script *a1); // idb
void script_434190_ingame_menu(Script *a1); // idb
void script_434220_ingame_menu(Script *a1); // idb
void script_4342A0_ingame_menu(Script *a1); // idb
void script_434310_ingame_menu(Script *a1); // idb
void script_434390_ingame_menu(Script *a1); // idb
void script_434460_DA000007(Script *a1); // idb
bool script_434500(Script *a1, int a2, int a3, int a4);

void EventHandler_PowerStation(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void UNIT_Handler_PowerStation(Script *a1);
void entity_mode_powerstation_spawn_tanker(Entity *a1);
void entity_mode_powerstation_completed(Entity *a1);
void entity_mode_powerstation_on_death(Entity *a1);
void UNIT_DmgHandler_Sapper(Script *a1);
void script_435CF0_rocket_dmg_handler(Script *a1);
void script_435D40_bombers_dmg(Sprite *a1, int a2); // idb
void UNIT_DmgHandler_Rocket(Script *a1);
void script_436140_flamethrower_dmg_handler(Script *a1);
void UNIT_DmgHandler_Flamethrower(Script *a1);
void script_4363C0_giant_bettle_dmg(Script *a1);
void UNIT_DmgHandler_Beetle(Script *a1);
void script_4368B0_plasma_tank_dmg_handler(Script *a1);
void UNIT_DmgHandler_Mech(Script *a1);
void script_436FB0_dmg_handler(Script *a1);
void script_436FF0_rifle_dmg_handler(Script *a1);
void script_4370D0_gort_dmg_handler(Script *a1); // idb
void UNIT_DmgHandler_GORT(Script *a1);
void UNIT_DmgHandler_Rifle(Script *a1);
int sub_437690(Script *a1);
void UNIT_DmgHandler_Bow(Script *a1);
void UNIT_DmgHandler_Projectile(Script *a1);
int HUNK_FixPointers(void *data, RllcHunk *rllc);
void EventHandler_RepairStation(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void UNIT_Handler_RepairStation(Script *a1);
void entity_mode_437F30_repairstation(Entity *a1);
void EventHandler_UpgradeProcess(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void EntityUpgradeAttachment_438000(EntityUpgradeAttachment *a1);
void EntityUpgradeAttachment_438030(EntityUpgradeAttachment *a1);
void EntityUpgradeAttachment_438160_handler(EntityUpgradeAttachment *a1);
void script_4381A0_upgrade_process(Script *a1);
void EventHandler_ResearchBuilding(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void UNIT_Handler_ResearchBuilding(Script *a1);
void entity_mode_researchlab_completed(Entity *a1);
void entity_mode_researchlab_on_death(Entity *); // idb
int _438630_read_save_lst();
bool _438740_save_lst();
bool _438840_save_lst();
int stru28_list_alloc();
void _4389A0_prolly_create_map_damage_decal(int map_x, int map_y); // idb
void _438B40_reset_explosions();
int _438B50_can_create_more_explosions();
void decrease_num_explosions();
void script_438B80_on_death_infantry_gore(Script *task); // idb
void script_438C20_on_death_explosion(Script *a1); // idb
void entity_438D90_on_death_explosion(Entity *a1);
void script_438F50_explosions(Script *a1); // idb
void script_439050_explosions(Script *a1); // idb
Sprite *entity_4390F0_add_explosion(Entity *a1);
Sprite *entity_439120_add_explosion(Entity *a1);
Sprite *entity_439150_add_explosion(Entity *a1);
void sprite_439180_add_explosions(Sprite *a2);
void _4391D0_mapd_handler(Mapd_stru0 *a1, void *a2);
void drawjob_update_handler_mapd_menu(Bitmap *a1, DrawJob *a2);
bool LVL_InitMapd();
Bitmap *MAPD_Draw(enum MAPD_ID mapd_idx, unsigned int image_id, int z_index);
void bitmap_list_remove(Bitmap *a1);
void _4393F0_call_mapd();
void bitmap_list_free();
bool sound_initialize();
bool LVL_LoadSlv(const char *slv_filename);
int sound_play(enum SOUND_ID sound_id, int a2, int volume_offset, int pan_offset, Script *script);
int sound_play_threaded(const char *name, int a2, int sound_volume_offset, int sound_pan_offset, Script *task); // idb
void _439C10_sound_thread(Sound *a1); // idb
void sound_stop(int sound_id);
void sound_free_sounds();
void _43A370_process_sound();
void sound_deinit();
bool file_read_wav(File *file, WAVEFORMATEX *out_data, unsigned int *a3);
bool sound_stru_2_43A710(sound_stru_2 *a1, WAVEFORMATEX **a2, int *a3, unsigned int *out_buffer_size);
void sound_list_43A800(int a1);
void sound_list_remove(Sound *a1);
void script_43BA40(Script *a1, int a2, int(*a3)(void), int a4);
void script_netz_43BA70(Script *a1);
int nullsub_3(void);
Script *netz_43BA90_create_script_43BA70();
void sub_43BAA0();
void _43BAB0_move_cursor(Sprite *a1);
void script_mobd79__main_menu_mouse_handler(Script *a1); // idb
void script_43C040_cursors_handler(Script *a1);
void script_mobd79_evt1__main_menu_new_game(Script *a1);
void script_mobd79_evt19__main_menu_load(Script *a1); // idb
void script_mobd79_evt1__main_menu_play_mission(Script *a1); // idb
void script_mobd79_evt1__main_menu_new_missions(Script *a1); // idb
void script_mobd79_evt1__main_menu_kaos_mode(Script *a1); // idb
void script_mobd79_evt1__main_menu_multiplayer(Script *a1); // idb
void script_mobd79_evt1__main_menu_quit(Script *a1); // idb
void script_43CD20_mobd45_begin_surv_campaign(Script *a1);
void script_43CE30_mobd45_begin_mute_campaign(Script *a1);
void script_43CF50_mobd45(Script *a1);
void script_43D090_mobd45_directx_ipx(Script *a1);
void script_43D270_mobd45_directx_serial(Script *a1);
void script_43D430_mobd45_directx_modem(Script *a1);
void script_43D5F0_mobd45(Script *a1);
void script_43D740_mobd45_evt17(Script *a1);
void script_43D890_mobd45(Script *a1);
void input_get_string_43D9E0_handler(const char *, int); // idb
void script_43DA80_mobd45_modem(Script *a1); // idb
void input_get_string_43DCF0_handler(const char *, int); // idb
void script_43DD90_mobd45_modem(Script *a1); // idb
void script_43E010_mobd45_modem(Script *a1); // idb
int script_43E110_modem(Script *a1, netz_modem *param, int a3);
void script_43E230_mobd45_modems(Script *a1); // idb
void script_43E470_mobd45_modems(Script *a1);
void script_43E670_mobd45(Script *a1);
void script_43E7B0_mobd45(Script *a1);
void script_43E820_mobd45(Script *a1);
void script_43E890_mobd45_modems(Script *a1); // idb
void script_43EA90_mobd45(Script *a1); // idb
void script_43EB80_mobd45(Script *a1); // idb
void script_43EC70_mobd45(Script *a1); // idb
void script_43ED60_mobd45_modems(Script *a1); // idb
void script_43EE90_mobd45(Script *a1); // idb
void script_43F0E0_mobd45_modems(Script *a1);
void script_43F330_mobd45(Script *a1);
void script_43F520_mobd45(Script *a1);
void script_43F670_mobd45(Script *a1);
void script_43F7C0(Script *a1); // idb
void script_43F9E0_mobd45(Script *a1); // idb
void script_43FAD0_mobd45_evt5(Script *a1); // idb
void script_43FDE0_mobd45(Script *a1);
void script_43FF30_mobd45(Script *a1);
void script_4402A0_mobd45_evt5(Script *a1);
void script_4404D0_mobd45_evt8(Script *a1);
void input_get_string_440770_handler(const char *, int); // idb
void script_440810_mobd45(Script *a1); // idb
void script_440CA0_mobd45_evt8(Script *a1); // idb
void script_440ED0_mobd45_evt8(Script *a1); // idb
void script_441050_mobd45_evt8(Script *a1); // idb
void script_441150_mobd45_evt8(Script *a1); // idb
bool _441240_techbunker_should_create();
void script_441260_mobd45_evt8(Script *a1); // idb
void script_441340_mobd45_evt8(Script *a1); // idb
int get_current_level_starting_cash();
void script_441470_mobd45_evt8(Script *a1); // idb
void script_441550_mobd45_evt8(Script *a1); // idb
int _441630_get_current_level_field14__get_max_upgrade_level(int a1);
void script_441680_mobd45_evt8(Script *a1); // idb
void script_441780_mobd45_evt8(Script *a1); // idb
void script_441940_mobd45_evt17(Script *a1);
void script_441CE0_mobd45_evt8(Script *a1); // idb
void netz_441EF0(int a1);
void script_441F10(Script *a1); // idb
void script_441FC0_mobd45_evt8(Script *a1); // idb
void script_4421F0_mobd45_evt8(Script *a1); // idb
void script_442580_mobd45_evt17(Script *task); // idb
void script_4426D0_mobd45_evt6(Script *a1);
void script_4428C0_mobd45_evt6(Script *a1);
void script_442BB0_mobd46(Script *a1);
void script_443000_mobd45(Script *a1);
void script_443140_mobd45(Script *a1);
void script_443290_mobd45(Script *a1);
int script_443380(Script *a1, int lookup_table_offset, bool a3);
int script_443570(Script *a1, int a2, int a3, int a4);
int script_443780(Script *a1, int a2, int a3, int a4);
void script_443C40(Script *a1, int cplc_item);
void script_443D40_mobd20(Script *a1);
int _443D60_strlen_before_newline(const char *str);
stru8 *render_string_443D80(RenderString *a1, const char *a2, DataMobdItem *custom_font); // idb
int render_string_443EE0(RenderString *a1, int a2, int a3); // idb
void netz_443F10();
int sub_443F20();
void sub_444080(int mapd_idx);
void UNIT_Handler_OilTanker(Script *a1);
void entity_oil_tanker_initialize(Entity *a1);
void entity_mode_4444D0_oiltanker(Entity *a1);
void entity_mode_4444F0_oiltanker(Entity *a1);
void entity_mode_444590_oiltanker(Entity *a1);
void entity_mode_444630_oiltanker(Entity *a1);
void entity_mode_4446A0_oiltanker(Entity *);
void entity_mode_4446B0_oiltanker_load_oil(Entity *a1);
void entity_mode_4447C0_oiltanker(Entity *a1);
void entity_mode_4448C0_oiltanker(Entity *a1);
void entity_mode_4449D0_oiltanker(Entity *a1);
void entity_mode_444A40_oiltanker(Entity *a1);
void entity_mode_444AB0_oiltanker(Entity *a1);
void entity_mode_444B40_oiltanker_unload_oil(Entity *a1);
Entity *entity_444BE0_oiltanker_get_state_entity(Entity *a1);
void entity_mode_444CC0_oiltanker(Entity *a1);
void entity_mode_444D10_oiltanker(Entity *a1);
void EventHandler_OilTanker(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void *_431C40_on_WM_ACTIVATEAPP_software_render(void *result);
void coroutine_main();
bool render_string_list_alloc();
void render_string_445770(RenderString *a1, const char *text, DataMobdItem *custom_font); // idb
RenderString *render_string_create(stru1_draw_params *a1, DataMobdItem *custom_font, int a3, int a4, int a5, int a6, int z_index, int a8, int a9); // idb
void render_string_list_remove(RenderString *a1);
int render_string_445AE0(RenderString *a1);
void render_string_list_free();
int _445C00_text(const char *str, int num_bytes);
int _445C80_text(const char *a1, int a2); // idb
bool entity_check_type(Entity *a1, int a2); // idb
void sidebar_button_handler_infantry_open(SidebarButton *a1);
void sidebar_button_handler_order_unit_click(SidebarButton *a1);
void sidebar_button_handler_infantry_close(SidebarButton *a1);
void sidebar_button_handler_vehicles_open(SidebarButton *a1);
void sidebar_button_handler_vehicles_close(SidebarButton *a1);
void sidebar_button_handler_airstrike_open(SidebarButton *a1);
void sidebar_button_handler_airstrike_close(SidebarButton *a1);
void sidebar_button_handler_446190_open(SidebarButton *a1);
void sidebar_button_handler_4461E0_close(SidebarButton *a1);
void sidebar_button_handler_buildings_open(SidebarButton *a1);
void sidebar_button_handler_order_building_click(SidebarButton *a1);
void sidebar_button_handler_buildings_close(SidebarButton *a1);
void sidebar_button_handler_towers_open(SidebarButton *a1);
void sidebar_button_handler_towers_close(SidebarButton *a1);
ProductionGroup *entity_building_create_production_group(Entity *a1, enum PRODUCTION_GROUP_ID production_group); // idb
void production_group_enable(ProductionGroup *a1, enum UNIT_ID unit_id, int mobd_lookup_table_offset); // idb
void production_group_disable(ProductionGroup *a1, enum UNIT_ID unit_id); // idb
void production_group_4467E0(ProductionGroup *a1, enum UNIT_ID unit_id); // idb
void production_group_446860(ProductionGroup *a1);
void sidebar_button_handler_options_open(SidebarButton *a1);
bool sidebar_initialize();
void sidebar_button_handler_cash_open(SidebarButton *a1);
void sidebar_button_handler_cash_close(SidebarButton *a1);
void sidebar_button_handler_help_open(SidebarButton *a1);
void sidebar_button_handler_help_close(SidebarButton *a1);
void sidebar_button_handler_minimap_open(SidebarButton *a1);
void sidebar_button_handler_minimap_close(SidebarButton *a1);
void sidebar_deinit();
void script_446ED0_sidebar_buttons(Script *a1);
bool is_player_faction_evolved();
void sub_447000();
void disable_minimap();
void attempt_unlock_aircraft();
void on_airstrike_ready();
void _4471E0_send_sidebar_buttons_message();
void _447250_toggle_aircraft();
Sprite *_447310_minimap();
void _447340_send_sidebar_buttons_message(int exception_id);
void UNIT_Handler_GuardTower(Script *a1);
void UNIT_Handler_Towers(Script *a1);
void entity_mode_4474D0_towers(Entity *);
void entity_mode_4474E0_towers(Entity *);
void entity_mode_tower_on_death(Entity *); // idb
void entity_mode_tower_dead(Entity *a1);
void EventHandler_Towers(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void entity_4477B0_towers(Entity *a1, int a2);
void entity_mode_4478E0_towers(Entity *a1);
void UNIT_AttachHandler_Turret(Script *a1);
int EntityTowerAttachment_4479F0(EntityTurret *a1);
void EntityTowerAttachment_handler_447C40(EntityTurret *a1);
void EntityTowerAttachment_handler_447CA0(EntityTurret *a1);
void EntityTowerAttachment_handler_447DD0(EntityTurret *a1);
void EntityTowerAttachment_handler_447E20(EntityTurret *a1);
void EntityTowerAttachment_handler_447F50(EntityTurret *a1);
void EntityTowerAttachment_handler_447FA0(EntityTurret *a1);
void EntityTowerAttachment_handler_448110(EntityTurret *a1);
void EntityTowerAttachment_handler_448160(EntityTurret *a1);
void EntityTowerAttachment_handler_448230(EntityTurret *a1);
void EntityTowerAttachment_handler_448290(EntityTurret *a1);
void EntityTowerAttachment_handler_4482D0_missile_battery(EntityTurret *a1);
void nullsub_1();
void MessageHandler_TowersAttachment(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void drawjob_update_handler_level_background(void *a1, DrawJob *a2);
void drawjob_update_handler_448390_fog_of_war(void *unused, DrawJob *a2);
void drawjob_update_handler_4483E0_sidebar(Sprite *a1, DrawJob *a2);
void drawjob_update_handler_cursors(Sprite *a1, DrawJob *a2);
void drawjob_update_handler_4484A0_explosions(Sprite *a1, DrawJob *a2);
void drawjob_update_handler_448510_aircraft(Sprite *sprite, DrawJob *job);
void drawjob_update_handler_448580_entity_aircraft_turret(Sprite *sprite, DrawJob *job);
void drawjob_update_handler_448600_oilspot(Sprite *a1, DrawJob *a2);
void drawjob_update_handler_448680(Sprite *param, DrawJob *job);
void drawjob_update_handler_4486D0_building(Entity *param, DrawJob *job); // idb
void drawjob_update_handler_448750_infantry(Entity *a1, DrawJob *job);
void drawjob_update_handler_4487B0_vehicles_buildings(Entity *a1, DrawJob *job); // idb
void drawjob_update_handler_oiltanker(Entity *param, DrawJob *job); // idb
void drawjob_update_draw_handler_aircraft(Entity *param, DrawJob *job); // idb
int entity_4488F0_is_in_firing_range(Entity *a1, Entity *a2, int entity_id); // idb
void tower_attachment_handler_448980(EntityTurret *a1);
void tower_attachment_handler_4489B0(EntityTurret *a1);
void tower_attachment_handler_448B40(EntityTurret *a1);
void tower_attachment_handler_448BF0(EntityTurret *a1);
void tower_attachment_handler_448C40(EntityTurret *a1);
void tower_attachment_handler_448E90(EntityTurret *a1);
void MessageHandler_448EC0(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void MessageHandler_task4_evt39030(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
void script_evt39030_handler(Script *a1);
bool UNIT_InitTasks();
void __47CAF0_tasks_evt39030_array_free();
void script_44A500_fog_of_war(Script *a1); // idb
void show_minimap_sprite();
void hide_minimap_sprite();
void _44A6B0_minimap(int x, int y);
void script_44A700_minimap(Script *a1);
_BYTE *_44A780_gof_of_war();
bool mapd_init_fog_of_war();
void mapd_44AE30_fog_of_war();
bool is_map_revealed_at(int x, int y); // idb
void entity_44B100_buildings__mess_with_fog_of_war(Entity *a1);
void minimap_free();
int sub_44BC80(int a1, int a2, int a3, int a4);
int MAPD_44BD50_alter_tile_flags();
void drawjob_update_handler_44BDC0_entity_turret(Sprite *a1, DrawJob *a2);
void script_44BE60_explosions(Script *a1); // idb
void EntityTurret_44BF00_handler(EntityTurret *);
void EntityTurret_44BF70(EntityTurret *a1);
void sub_44BFC0(int a1);
void MessageHandler_EntityScript(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param);
bool _44C010_init_mission_globals();
void per_player_sprite_palettes_47DC88_free();
int UNIT_Init();
void drawjob_update_handler_44C430_default_sprite(Sprite *a1, DrawJob *a2);
void _44C4B0_mess_with_turrets();
void _44C5C0_level_cleanup();
Entity *entity_list_create(Script *a1);
void entity_list_remove(Entity *a1);
Sprite *spawn_unit(enum UNIT_ID unit_id, int x, int y, enum PLAYER_SIDE player_side); // idb
Entity *entity_find_by_id(int entity_id);
bool sub_44CA50(enum UNIT_ID id); // idb
Entity *entity_44CA70_find(Entity *a1, enum UNIT_ID a2, int player_side); // idb
bool show_message_ex(Entity *a1, const char *text);
bool show_message(const char *text);
int entity_advance_mobd_rotation(int *src_lookup_id, int dst, int step); // idb
void script_show_message_ex(Script *a1); // idb
bool _44CDC0_sidebar_is_units_limit();
bool is_enemy(enum PLAYER_SIDE player_side, Entity *a2);
bool sub_44CE40(enum PLAYER_SIDE player_side, Entity *a2);
void script_show_message(Script *a1);
int entity_44D000_boxd(Entity *a1);
_DWORD *boxd_44D250(_DWORD *a1, _DWORD *a2, int a3, Entity *a4, int *a5);
bool boxd_44D340(int *out_x, int *out_y, int a3, Entity *a1, int *out_idx);
void message_pump();
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd);
int nullsub_4();
VideoFile *VIDEO_ReadFile(const char *video_name);
void VIDEO_Clean(VideoFile *video); // idb
int VIDEO_ReadNextFrame(VideoFile *a1);
__int16 video_45A110(VideoFile *a1, VideoFileFrame *frame); // idb
FILE *j_fopen_weirdmode_3(const char *a1);
_BYTE *sub_45A48E(unsigned __int16 a1, __int16 a2, _BYTE *a3, int a4, int a5, int a6, int a7, int a8);
_BYTE *sub_45D3B8(unsigned __int16 a1, __int16 a2, _BYTE *a3, int a4, int a5, int a6, int a7, int a8, int a9);


SOUND_ID get_unit_move_confirmation_sound(UNIT_ID unit_id, bool experienced);
SOUND_ID get_unit_attack_confirmation_sound(UNIT_ID unit_id, bool experienced);
SOUND_ID get_unit_ready_sound(UNIT_ID unit_id);
bool mobile_base_can_deploy(Entity *entity);

int global2map(int coordinate);
int map2global(int coordinate);
bool map_is_same_tile(int coord1, int coord2);
bool map_is_different_tile(int coord1, int coord2);