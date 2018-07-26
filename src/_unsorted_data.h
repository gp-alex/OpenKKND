#pragma once

#include <list>

#include "src/kknd.h"
#include "src/_unsorted_functions.h"
#include "src/Render.h"

extern _UNKNOWN loc_45D19B; // weak
extern _UNKNOWN loc_45D1A4; // weak
extern _UNKNOWN loc_45D267; // weak
extern int sys_colors_elements;
extern int kknd_sve_array_463070[15];
extern int kknd_sve_array_4630AC[15];
extern int dword_4630E8; // weak
extern GUID netz_463DE0;
extern char asc_464068[4];
extern BasicProductionOption mute_default_buildings[6];
extern BasicProductionOption mute_default_infantry[3];
extern stru7 _4640E0_stru7_array[20];
extern char BOXD[];
extern char aSSS[];
extern Vec2 _464230_tankerconvoy_checkpoints_surv07[18];
extern Vec2 _4642C0_tankerconvoy_checkpoints_mute08[30];
extern char *credits[117];
extern char *off_464ACC[100]; // weak
extern char asc_464C60[39];
extern char asc_464C88[]; // idb
extern char CPLC[]; // idb
extern enum UNIT_ID mute_prison_spawns_table[10];
extern enum UNIT_ID surv_prison_spawns_table[10];
extern enum UNIT_ID techbunker_spawns_table[4];
extern char aCouldnTCreateS[]; // idb
extern int dword_464D38; // weak
extern int dword_464D3C[24];
extern char aDDD[]; // idb
extern char aR[]; // idb
extern char aSLevelsMulti_p[]; // idb
extern int dword_464DC0[]; // weak
extern int dword_464DCC; // weak
extern EnemyAI_stru57 array_464DD0[47];
extern char aWarningUnregis[]; // idb
extern char aWarningOutOfAt[]; // idb
extern char aWarningOutOfWa[]; // idb
extern char aWarningOutOfPo[]; // idb
extern char aWarningOutOfDr[]; // idb
extern char aWarningOutOfTa[]; // idb
extern char aWarningOutOfBu[]; // idb
extern char aWarningOutOfEnemyNodes[]; // idb
extern char aEnemyaiCreatur[]; // idb
extern int _465610_damage_multipliers[12];
extern int _465640_accuracy_bonus[4];
extern stru201_displaymode _465650_display_modes[3];
extern int _465680_get_sys_colors; // weak
extern int dword_465688[32];
extern int _465708_x_offsets[8];
extern int _465728_y_offsets[8];
extern int _4657C8_hint_entity_id; // weak
extern stru3 stru3s[2]; // weak
extern unsigned __int8 _4657F0_tanker_status_color_breakpoints[8];
extern unsigned __int8 _4657F8_tanker_status_color_breakpoints[8];
extern unsigned __int8 _465800_stru26_stru27_initializer[4];
extern unsigned __int8 _465804_stru26_stru27_initializer[4];
extern stru1_draw_params default_stru1;
extern stru1_draw_params *render_default_stru1;
extern int render_first_drawing_item; // weak
extern RECT stru_465810;
extern char *aFailedToSetupDirectdraw;
extern char *Caption;
extern unsigned __int8 palette_465848_sprt[256];
extern int _465948_per_mobd_lookup_idx[16];
extern enum SOUND_ID _465988_sounds[5];
extern int input_465A80_wndprockey_map[256];
extern int input_465FE8[16];
extern stru7 array_466028[7];
extern int _466098_cost_multiplier[4];
extern const char *slvs[2];
extern LevelDesc levels[68];
extern const char *errmsg_save[2];
extern char aMemory[7]; // weak
extern char aUnitDS[]; // idb
extern char aTaskIsWrongTyp[19]; // weak
extern char aBadConstructs[15]; // weak
extern char aBadMode[9]; // weak
extern char aCouldNotSaveUn[32]; // weak
extern char aCouldnTWriteTo[33]; // weak
extern char aCouldnTOpenSav[29]; // weak
extern char aCouldNotSaveMi[41]; // weak
extern char aCouldNotSaveMa[31]; // weak
extern char aCouldNotSavePr[38]; // weak
extern char aCouldNotSaveCp[38]; // weak
extern char aCouldNotAlloca[36]; // weak
extern char aCouldNotSaveOi[31]; // weak
extern char aCouldnTAllocat[35]; // weak
extern char aSS_0[]; // idb
extern int prev_level_idx; // weak
extern const char *pKknd_sve;
extern char aC[3]; // idb
extern char *reg_MinimumInstall;
extern char *reg_DriveLetter;
extern char *reg_GamePath;
extern char a_[2]; // weak
extern char *aS;
extern char *aLvl_runlevelFa;
extern char *aLvl_substhunkF;
extern char *MOBD;
extern char *aLvl_loadlevelS;
extern char *aSLevelsSS;
extern char *aSuperSpriteLoa;
extern char *aSLevelsSSupspr;
extern char intro_vbc[10]; // weak
extern char *aSFmvMh_fmv_vbc;
extern char *fmv_lvl;
extern char *aSFmvS;
extern char *aEvolvout_vbc;
extern char *aSurvout_vbc;
extern char *aLoadgamestateF;
extern char *aUnit_initFaile;
extern char *aSLevelsS;
extern char *aSpriteLoadFail;
extern CustomMission custom_missions[20];
extern UnitNameId unit_name_id_lut[66];
extern char *console_switch_nocd;
extern char *console_switch_noblack;
extern char *errmsg_no_stats_file_specified;
extern char *console_switch_stats;
extern char *aSS;
extern char *aW;
extern char *errmsg_could_not_open_file;
extern char *errmsg_unrecognized_name;
extern char aDamageToBuildi[20]; // weak
extern char aDamageToVehicl[19]; // weak
extern char aDamageToInfant[19]; // weak
extern char aAccuracy[9]; // weak
extern char aFiringVisualRa[20]; // weak
extern char aTurningSpeed[14]; // weak
extern char aVolleySize[12]; // weak
extern char aReload2Time[13]; // weak
extern char aReloadTime[12]; // weak
extern char aSpeed[6]; // weak
extern char aWarningUnitSIs[]; // idb
extern char aHitpoints[10]; // weak
extern char aProductionTime[16]; // weak
extern char errmsg_unit_out_of_range[]; // idb
extern char cost[5]; // weak
extern char _4681EC_whitespace[]; // idb
extern char asc_space[]; // idb

extern stru52 stru_4681F8;
extern stru52 stru_468210;
extern stru52 stru_468228;
extern stru53 stru_468240;
extern stru53 stru_468250;
extern stru53 stru_468260;
extern stru53 stru_468270;
extern stru53 stru_468280;
extern stru53 stru_468290;
extern stru54 stru_4682A0;
extern stru54 stru_4682C0;
extern stru55 stru_4682E0;
extern stru54 stru_468308;
extern stru53 stru_468328;
extern stru55 stru_468338;
extern stru54 stru_468360;
extern stru53 stru_468380;
extern stru55 stru_468390;
extern stru54 stru_4683B8;
extern stru53 stru_4683D8;
extern stru55 stru_4683E8;
extern stru49 _468410_stru49_array[21];
extern stru50 _468560_stru50_array[16];
extern stru50 _468620_stru50_array[16];
extern stru50 __4686E0_stru50_array[20];
extern stru50 _4687D0_stru50_array[20];
extern DataCplcItem_ptr1_stru20 _4688E0_DataCplcItem_ptr1_stru20_clanhall; // weak
extern DataCplcItem_ptr1_stru20 _468910_DataCplcItem_ptr1_stru20_outpost; // weak

extern int dword_468940[]; // weak
extern int dword_468980; // weak
extern int dword_468984; // weak
extern enum SOUND_ID _468988_sound_ids[4];
extern enum SOUND_ID _468998_sound_ids[4];
extern enum SOUND_ID _4689A8_sound_ids[2];
extern enum SOUND_ID _4689B0_sound_ids[4];
extern enum SOUND_ID _4689C0_sound_ids[22];
extern enum SOUND_ID _468A18_sound_ids[2];
extern enum SOUND_ID _468A20_sound_ids[2];
extern enum SOUND_ID _468A28_sound_ids[4];
extern enum SOUND_ID _468A38_sound_ids[4];
extern enum SOUND_ID _468A48_sound_ids[2];
extern enum SOUND_ID _468A50_sound_ids[2];
extern enum SOUND_ID _468A58_sound_id;
extern char aSD[]; // idb
extern char aSS_1[]; // idb
extern unsigned __int8 _468A6C_mobd_lookups[68];
extern char aWarningUnreg_0[]; // idb
extern char aWarningOutOfMa[]; // idb
extern char aWarningUnreg_2[]; // idb
extern char aWarningUnreg_1[]; // idb
extern char aWarningOutOfNe[]; // idb
extern int netz_468B50_available_units_denom; // weak
extern int dword_468B54;
extern void *__47CA80_array_idx_and_netz_player_side; // idb
extern int single_player_game; // weak
extern int dword_468CE8; // weak
extern int netz_468CF0; // weak
extern int netz_468CF4; // weak
extern int netz_468CF8; // weak
extern int netz_468CFC; // weak
extern int netz_468D00; // weak
extern int netz_468D04; // weak
extern int netz_468D08; // weak
extern int netz_468D0C; // weak
extern int netz_468D10; // weak
extern int netz_468D14; // weak
extern int netz_468D18; // weak
extern int netz_468D1C; // weak
extern int netz_468D20; // weak
extern char aS_1[2]; // weak
extern char aC_0[2]; // weak
extern char aUnknown[8]; // weak
extern char aUnknownNetzE_0[42]; // weak
extern char aUnknownNetzErr[38]; // weak
extern char aNotYetImplemen[20]; // weak
extern char aDisabled[9]; // weak
extern char aLinkLost[10]; // weak
extern char aNetzRequiresA4[40]; // weak
extern char aOperatingSyste[34]; // weak
extern char aFailed[7]; // weak
extern char aNameIsNotUniqu[19]; // weak
extern char aWrongModeForNe[28]; // weak
extern char aCouldNotCreate[28]; // weak
extern char aPacketIsTooBig[18]; // weak
extern char aInternalResour[32]; // weak
extern char aPortSocketInUs[31]; // weak
extern char aWrongTypeOfLin[36]; // weak
extern char aProtocolIsNotP[24]; // weak
extern char aLinkIsNotConne[22]; // weak
extern char aNoFreeLinks[14]; // weak
extern char aLinkInUseAlrea[26]; // weak
extern char aLinkNotOpen[14]; // weak
extern char aOutOfMemory[14]; // weak
extern char aNoError[10]; // weak
extern BasicProductionOption surv_basic_buildings[5]; // weak
extern BasicProductionOption surv_basic_infantry[3]; // weak
extern int dword_468FD4; // weak
extern int dword_468FD8; // weak
extern int dword_468FDC; // weak
extern char *off_469030[30]; // weak
extern int _4690A8_unit_sounds_volume;
extern int _4690AC_level_wav_sound_offset; // idb
extern int dword_4690B0; // weak
extern int dword_4690B4; // weak
extern char asc_46BB14[18];
extern char aD_1[]; // idb
extern char aD_0[5]; // weak
extern char aD[6]; // weak
extern RECT _46BB40_enum_attached_surfaces_blt_rect;
extern RECT _46BB50_blt_rect;
extern int _46BB60_dmg_handler_mobd_offsets[3];
extern enum SOUND_ID _46BB70_dmg_handler_sounds[3];
extern enum SOUND_ID _46BB80_dmg_handler_sounds[2];
extern char aSGameD_sav[]; // idb
extern char aSlotDSD[]; // idb
extern char aActiveslotD[]; // idb
extern char aSSave_lst[]; // idb
extern int _46BBE8_mobd_offset_table_by_stru22[8];
extern int dword_46BC20[8];
extern int dword_46BC40[8];
extern int dword_46BC60[9];
extern int dword_46BC84[5];
extern int dword_46BC98[8];
extern char aSoun[]; // idb
extern char shared_slv_filename[]; // idb
extern char aData[5]; // weak
extern char fmt[5]; // weak
extern char WAVE[5]; // weak
extern char RIFF[5]; // weak
extern int render_43B4A6_46BD04; // weak
extern __int16 word_46BD08; // weak
extern int dword_46BD0A; // weak
extern __int16 word_46BD0E; // weak
extern char aEvol[7]; // weak
extern _BYTE aSurv[]; // idb
extern char aEvol_0[5]; // weak
extern _BYTE a2[]; // idb
extern char aUnitReady[]; // idb
extern char aCouldntCreateNewUnit[]; // idb
extern char aBuildingCompleted[]; // idb
extern char aBuildingSabotaged[]; // idb
extern char aAirStrikeReady[]; // idb
extern char a5000ResourceUn[20]; // weak
extern char a1000ResourceUn[]; // idb
extern char aNoMoneyToStartBuilding[]; // idb
extern char aNoTowersAvaila[]; // idb
extern char aCommencingUpgrade[]; // idb
extern char aUpgradeComplete[]; // idb
extern const char *player_colors[15];
extern char *off_46C358[15]; // weak
extern const char *difficulties[3];
extern const char *sidebar_category_labels[11];
extern char aSfxVolumeMusicVolume[28]; // weak
extern char aAreYouSureYo_0[34]; // weak
extern char aAreYouSureYouW[35]; // weak
extern char aBuildingIsUnav[]; // idb
extern char aAllegianceBroken[]; // idb
extern char aUnitsAreUnavai[]; // idb
extern char aSSwearingAlleg[]; // idb
extern int dword_46E3F0; // weak
extern int dword_46E3F8; // weak
extern int dword_46E3FC; // weak
extern int _466098_cost_multiplier_idx; // weak
extern int dword_46E404; // weak
extern int dword_46E408[6];
extern const char *_46E420_starting_cash[8];
extern int _46E440_mobd_offsets[15];
extern int _46E480_mobd_offsets[15];
extern int _46E4C0_mobd_offsets[10];
extern int _46E4F0_mobd_offsets[10];
extern char format[]; // idb
extern char aModem_lst[]; // idb
extern char aSS_2[]; // idb
extern char aD_2[]; // idb
extern char aS_0[4]; // idb
extern char aCLevelsMute1_wav[20]; // weak

extern char asc_470198[]; // idb
extern int _4701A8_sidebar_mask_per_44_mobd_lookup_idx[]; // idb
extern int _4701B8_mobd_lookups_per_ProductionGroup_field44[8];
extern stru196 array_4701D8[28];
extern void(*_470478_sidebar_button_open_handlers[5])(SidebarButton *);
extern void(*_470490_sidebar_button_close_handlers[5])(SidebarButton *);
extern int _4704A8_per_sidebar_button_mobd_lookup_table_offsets[2][11];
extern char a8d[]; // idb
extern enum PLAYER_SIDE player_side;
extern int dword_47050C; // weak
extern int dword_470510[8]; // weak
extern char aCouldnTCreat_0[]; // idb
extern char aWaitingForServ[]; // idb
extern char aWaitingForPlay[]; // idb

extern int dword_470588[];
extern int dword_470598; // weak
extern int dword_47059C; // weak
extern int *_4705A8_minimap_smthn; // weak

extern MobdSprtImage _47CBA0_MobdSprtImage_fog_of_war;
extern DataMobdItem_stru0 _4705B0_minimap; // weak


extern UnitDamageSource dmg_rifle;
extern UnitDamageSource dmg_shell_anaconda;
extern UnitDamageSource dmg_shell_cannontower;
extern UnitDamageSource dmg_shell_mastadont;
extern UnitDamageSource dmg_swat;
extern UnitDamageSource dmg_bow;
extern UnitDamageSource dmg_shotgunner;
extern UnitDamageSource dmg_sniper;
extern UnitDamageSource dmg_flamethrower;
extern UnitDamageSource dmg_scorpion;
extern UnitDamageSource dmg_beetle;
extern UnitDamageSource dmg_rocket_rpg;
extern UnitDamageSource dmg_rocket_tower;
extern UnitDamageSource dmg_rocket_barragecraft;
extern UnitDamageSource dmg_grapeshot;
extern UnitDamageSource dmg_rocket_misslecraft;
extern UnitDamageSource dmg_mech;
extern UnitDamageSource dmg_plasma_ball;
extern UnitDamageSource dmg_gort;
extern UnitDamageSource dmg_laser_cannon;
extern UnitDamageSource dmg_sapper;
extern UnitDamageSource dmg_bomber;
extern UnitDamageSource dmg_drill_rig;


extern UnitAttachmentPoint turret_AnacondaCannon;
extern UnitAttachmentPoint turret_PlasmaCannon;
extern UnitAttachmentPoint turret_SentinelDroid;
extern UnitAttachmentPoint turret_mech;
extern UnitAttachmentPoint turret_Atv;
extern UnitAttachmentPoint turret_AtvFlamethrower;
extern UnitAttachmentPoint turret_MonsterTruck;
extern UnitAttachmentPoint turret_4x4Pickup;
extern UnitAttachmentPoint turret_SidecarBike;
extern UnitAttachmentPoint turret_WarMastadont;
extern UnitAttachmentPoint turret_BarrageCraft;
extern UnitAttachmentPoint turret_AutocannonTank;
extern UnitAttachmentPoint turret_MissileCrab;
extern UnitAttachmentPoint turret_CannonTower;
extern UnitAttachmentPoint turret_GuardTower;
extern UnitAttachmentPoint turret_MachineGunNest;
extern UnitAttachmentPoint turret_GrapeshotCannon;
extern UnitAttachmentPoint turret_RocketTower;
extern UnitAttachmentPoint turret_RotaryCannon;
extern UnitAttachmentPoint attach_Bomber;
extern UnitAttachmentPoint attach_Wasp;
extern UnitAttachmentPoint attach_PowerStation1;
extern UnitAttachmentPoint attach_PowerStation2;
extern UnitAttachmentPoint attach_Outpost;
extern UnitAttachmentPoint attach_MachineShop;
extern UnitAttachmentPoint attach_BeastEnclosure;
extern UnitAttachmentPoint attach_RepairBay;
extern UnitAttachmentPoint attach_surv_drillrig;
extern UnitAttachmentPoint attach_mute_drillrig;
extern UnitAttachmentPoint attach_Research1;
extern UnitAttachmentPoint attach_TechBunker;
extern UnitAttachmentPoint attach_Research2;
extern UnitAttachmentPoint attach_blacksmith;
extern UnitAttachmentPoint attach_MobileDerrick;
extern UnitAttachmentPoint attach_clanhall;

extern UnitStat unit_stats[89];

extern int _4731A8_speeds[]; // idb
extern char *errmsg_win95_or_later;
extern char *errmsg_dx3_or_later;
extern char *errmsg_dx5_or_later;
extern char *errmsg_generic;
extern char *backslash;
extern char *ddraw_dll_filename;
extern char aRbwbrBwB[]; // idb
extern int dword_476AC0; // weak
extern int dword_476AC4; // weak
extern int dword_476DD8; // weak
extern int dword_476DDC; // weak
extern __int16 word_476DE0[]; // weak
extern int dword_476FE0; // weak
extern int __477318_beastenclosure_negindex[]; // weak
extern stru15unit _477318_beastenclosure;
extern int max_beastenclosure_level; // weak
extern int dword_477358; // weak
extern stru15unit _477378_clanhall;
extern int max_clanhall_level; // weak
extern int _4773A0_boxd_item0_num_things; // weak
extern DataBoxd *currently_running_lvl_boxd;
extern Boxd_stru0 *_4773A8_boxd_parray;
extern int _4773AC_boxd_item0_map_x_scale; // weak
extern Boxd_stru0 **_4773B0_boxd_item0_things;
extern int _4773B4_boxd_item0_map_num_y_tiles; // weak
extern int _4773B8_boxd_item0_map_y_scale; // weak
extern int currently_running_lvl_boxd_valid; // weak
extern Boxd_stru0 *_4773C0_boxd_array;
extern BoxdTile **_4773C4_boxd_item0_map_tiles;
extern int _4773C8_boxd_item0_map_num_x_tiles; // weak
extern char byte_4773D0[68]; // idb
extern int dword_477410; // weak
extern DataCplcItem_ptr1 *_477414_cplc_next2;
extern int currently_running_lvl_cplc_valid; // weak
extern DataCplcItem *currently_running_lvl_cplc_item;
extern DataCplcItem_ptr1 *_477420_cplc_next1;
extern void *currently_running_lvl_cplc_data; // idb
extern int __47C380_mapd_cplc_item0_ptr_field_4_minus_3FFF; // weak
extern DataCplc *currently_running_lvl_cplc;
extern DataCplcItem_ptr1 *_477430_cplc_item0_ptr1;
extern int _47C384_mapd_cplc_item0_ptr_field_8_minus_3FFF; // weak
extern void *_477438_cplc_item0_ptr3;
extern int dword_47743C; // weak
extern int dword_477440; // weak
extern DataCplc_stru0 *cplc_stru0_list_free_pool;
extern int _477448_cplc_x; // weak
extern void *_47744C_cplc_item0_ptr4;
extern DataCplc_stru0 *cplc_stru0_list;
extern int _477454_cplc_y; // weak
extern DataCplcItem_ptr1 *_477458_cplc_prev2;
extern int dword_47745C; // weak
extern int dword_477460; // weak
extern DataCplc_stru0 *cplc_stru0_list_477464;
extern int currently_running_lvl_cplc_data_size; // weak
extern DataCplcItem_ptr1 *_47746C_cplc_prev1;
extern OilDeposit *oilspot_list_head;
extern OilDeposit *oildeposit_list_end;
extern OilDeposit *oilspot_list;
extern OilDeposit *oilspot_list_free_pool;
extern int dword_477890;
extern int dword_477894;
extern int dword_477898; // weak
extern int dword_47789C; // weak
extern int dword_4778A0; // weak
extern int dword_4778A8; // weak
extern int dword_4778AC; // weak
extern int __4778C0_stru1_anim_length; // weak
extern int __4778C0_stru1_anim_start; // weak
extern int _4087A0_stru1_should_animate; // weak
extern int __4778C0_stru1_anim_end; // weak
extern stru1_draw_params *_4778C0_stru1_anim;
extern int _4778C0_stru1_anim_t; // weak
extern int _4778C8_singleplayer_available_units_denom; // weak
extern Script *task_ai_players[7];
extern _UNKNOWN unk_4778EC; // weak
extern stru24 *cpu_player_scripts_attached_stru24s[7];
extern int timer_delta_updated; // weak
extern int timer_delta_ms; // weak
extern int timer_time; // weak
extern Entity *dword_478108[300];
extern DataBoxd_stru0_per_map_unit *_478AA8_boxd_stru0_array;
extern int _478AAC_map_height; // weak
extern int dword_478AB0; // weak
extern int _478AB4_map_width_shl_13; // weak
extern int _478BE8_map_info__see40E6E0[8];
extern char byte_478C08; // weak
extern int _478FF0_map_height_shl_13; // weak
extern int dword_478FF4; // weak
extern int _4793F8_map_width; // weak
extern int dword_47952C; // weak
extern int dword_47953C; // weak
extern Sidebar *stru22_list_479548;
extern Sidebar *stru22_list_47954C;
extern Sidebar *sidebar_list;
extern Sidebar *sidebar_list_head;
extern SidebarButton *sidebar_button_list_4795A0;
extern SidebarButton *sidebar_button_list_4795A4;
extern SidebarButton *sidebar_button_list;
extern SidebarButton *sidebar_button_list_head;
extern int sidebar_button_list_sidebar_height; // weak
extern int sidebar_button_list_item_width; // weak
extern stru2 *stru2_list_4795D8;
extern stru2 *stru2_list_4795DC;
extern stru2 *stru2_list_free_pool;
extern stru2 *stru2_list;
extern stru26 _4795F0_stru26_array[3];
extern stru27 _479740_stru27_array[3];
extern tagRECT global_wnd_rect; // idb
extern void *render_locked_surface_ptr;
extern DWORD global_wnd_style; // idb
extern int global_wnd_bpp; // weak
extern unsigned int render_locked_surface_width_px; // idb
extern int global_fullscreen; // weak
extern int global_time_flows; // weak
extern stru1_draw_params *stru1_list_free_pool;
extern int global_wnd_height; // idb
extern DWORD global_wnd_style_ex; // idb
extern stru1_draw_params *stru1_list;
extern int global_wnd_width; // idb
extern bool is_render_window_initialized; // 411760
extern int timer_render_skips; // weak
extern char palette_4798F8_sprt_aligned[512];
extern stru1_draw_params *current_drawing_params;
extern char byte_479B00[88]; // idb
extern int input_479B6C_just_pressed_keys_mask; // weak
extern int wnd_proc_pressed_key_id; // weak
extern int next_pressed_key; // weak
extern int input_wnd_proc_pressed_key_id; // weak
extern int array_479B98[25][2];
extern int array_479C60[25][2];
extern int array_479B98_array_479C60_inited; // weak
extern stru7 _479D48_stru7;
extern int is_task_list_initialized; // weak
extern int dword_479DBC; // weak
extern int _479DC0_render_string_list_initialized; // weak
extern int draw_list_initialized; // weak
extern DataSectionOffset *currently_running_lvl_sections;
extern int _479DCC_cplc_initialized; // weak
extern int _479DD0_mobd_initialized; // weak
extern int timer_initialized; // weak
extern int input_initialized; // weak
extern DataHunk *currently_running_lvl;
extern int stru1_global_obj_anim_initialized; // weak
extern int game_window_created; // weak
extern int _479DE8_boxd_initialized; // weak
extern int stru2_list_elements_initialized; // weak
extern int _479DF0_mapd_initialized; // weak
extern char current_savegame_filename[256];
extern char byte_479EF8[192]; // idb
extern char str[128];
extern enum LEVEL_ID game_saveload_level_idx;
extern int game_load_in_progress; // weak
extern int game_save_in_progress; // weak
extern int __47739C_machineshop_negindex[]; // weak
extern stru15unit _47739C_machineshop;
extern int max_machineshop_level; // weak
extern char app_root_dir[20]; // idb
extern DataHunk *current_level_lvl; // idb
extern char game_installation_drive_letter; // weak
extern Bitmap *_47A010_mapd_item_being_drawn[3];
extern int _47A01C_sound_id; // weak
extern char game_data_root_dir[80]; // idb
extern char game_data_installation_dir[256];
extern DataHunk *wait_lvl;
extern int is_minimal_install;
extern DataHunk *sprites_lvl; // idb
extern int dword_47A180; // weak
extern int dword_47A184; // weak
extern int _47A18C_probably_play_outro_movie; // weak
extern int _47A198_custom_mission_briefing_sound_id; // idb
extern int dword_47A19C; // weak
extern int dword_47A1A0; // weak
extern int _47A1A4_custom_mission_briefing_line; // weak
extern int _47A1A8_custom_mission_idx; // weak
extern int _47A1AC_is_custom_surv_mission; // weak
extern int _47A1B0_custom_mission_briefing_ui; // weak
extern char global_console_argv[260];
extern int dword_47A2BC; // weak
extern char *global_cmd_line;
extern int netz_47A2C8; // weak
extern enum LEVEL_ID current_level_idx;
extern __int16 current_mute_level; // weak
extern __int16 current_surv_level; // weak
extern int _47A2E4_mess_with_game_dir; // weak
extern int nocd; // weak
extern int _47A2EC_noblack; // weak
extern int units_stats_parsed_from_argv; // weak
extern int _4269B0_task_attachment__num_units_created_manually; // weak
extern int _47A300_stru51_array__field_4__minus1_index[]; // weak
extern stru51_tech_bunkers _47A300_stru51_tech_bunkers[14];
extern int _4269B0_task_attachment__num_units_spawned; // weak
extern stru48 _47A378_stru48_array[7];
extern Script *script_47A3CC; // idb
extern int _47A3D0_unit; // weak
extern int _47A3D4_tanker_convoy_units_left; // weak
extern int _47A3D8_num_convoy_tankers_still_to_arrive; // weak
extern int dword_47A3DC; // weak
extern Entity volatile *entity_scout;
extern int _47A378_stru48_array_num_items; // weak
extern int _47A300_stru51_tech_bunkers_num_items; // weak
extern DataMobd *currently_running_lvl_mobd;
extern Sprite *sprite_list_free_pool;
extern Sprite sprite_47A400; // weak
extern void(*j_drawjob_update_handler_426C40_default_sprite_handler)(Sprite *param, DrawJob *job);
extern int currently_running_lvl_mobd_valid; // weak
extern Sprite *sprite_list_47A4A0;
extern Sprite *sprite_list_47A4A4;
extern Sprite *sprite_list;
extern stru38 *stru38_list_47A4B0;
extern stru38 *stru38_list_47A4B4;
extern stru38 *stru38_list;
extern stru38 *stru38_list_free_pool;
extern stru37 *stru37_list_47A500;
extern stru37 *stru37_list_47A504;
extern stru37 *stru37_list;
extern stru37 *stru37_list_free_pool;
extern int input_mouse_window_losing_focus_reset_to_defaults; // weak
extern int dword_47A5A0; // weak
extern char byte_47A5A8[56];
extern Script *task_mobd17_cursor; // idb
extern stru13_stru0 _47A608_stru13_associated_array; // weak
extern stru13construct *stru13construct_list_47A638;
extern stru13construct *stru13construct_list_47A63C;
extern stru13construct *stru13construct_list;
extern stru13construct *stru13construct_list_free_pool;
extern int dword_47A6F0; // weak
extern int dword_47A6FC; // weak
extern KeyboardInput _47A700_input; // idb
extern int _47A660_array_num_items; // weak
extern RenderString *_47A730_render_string; // idb
extern Script *_47A734_sidebar_tooltips_task; // idb
extern int dword_47A738; // weak
extern int netz_47A828; // weak
extern int netz_47A82C; // weak
extern int dword_47A830; // weak
extern void *netz_47A834; // idb
extern int dword_47A83C; // weak
extern int netz_47A840; // weak
extern int netz_47A844; // weak
extern int netz_47A848; // weak
extern _UNKNOWN unk_47A84C; // weak
extern _UNKNOWN unk_47A858; // weak
extern netz_stru0 netz_47A868;
extern void *netz_47A88C; // idb
extern int netz_47A890; // weak
extern int netz_47A898_object; // weak
extern int netz_47A89C; // weak
extern int netz_47A8A0; // weak
extern int netz_47A8A4; // weak
extern int netz_47A8A8; // weak
extern int netz_47A8DC; // weak
extern void *dword_47A8E0; // idb
extern int netz_47A934; // weak
extern char byte_47A938; // weak
extern int netz_47B3A0; // weak
extern int nezt_47B3B0; // weak
extern ProductionGroup *_47B3B8_tower_production_group;
extern Entity *_47B3C0_player_outposts_clanhalls[4];
extern ProductionGroup *_47B3D0_building_production_group;
extern ProductionGroup *_47B3D4_aircraft_production_group;
extern int _47B3E0_unit_int_outpost_clanhall; // weak
extern int __47B3E0_outpost_levels_negindex[]; // weak
extern stru15unit _47B3E0_outpost_levels;
extern int max_outpost_level; // weak
extern int dword_47C018; // weak
extern Script *receiver; // idb
extern Script *task_47C028; // idb
extern int dword_47C030; // weak
extern int _47C048_unit_bomberdmg; // weak
extern int _47C04C_num_explosions_max20; // weak
extern stru175 _47C050_array[20];
extern char byte_47C230[256]; // idb
extern int _47C050_array_idx; // idb
extern stru28 *stru28_list_47C338;
extern stru28 *stru28_list_47C33C;
extern stru28 *stru28_list;
extern stru28 *stru28_list_free_pool;
extern int _47C350_num_explosions_min0_max30; // weak
extern int num_explosions; // weak
extern Bitmap *bitmap_list;
extern Bitmap *bitmap_list_47C360;
extern Bitmap *bitmap_list_47C364;
extern void(*mapd_j_4391D0_handler)(Mapd_stru0 *, void *);
extern Bitmap *bitmap_list_free_pool;
extern void(*j_drawjob_update_handler_mapd_menu)(Bitmap *param, DrawJob *job);
extern int currently_running_lvl_mapd_num_items; // weak
extern Mapd_stru0 _47C380_mapd;
extern int currently_running_lvl_mapd_valid; // weak
extern int _47C390_mapd; // weak
extern DataMapd *currently_running_lvl_mapd;
extern int sound_list_end; // weak
extern Sound *sound_list_free_pool;
extern Sound *sound_list_47C3D4;
extern sound_stru_2 **_47C4E0_sounds;
extern LPDIRECTSOUND pds; // idb
extern int _47C4E8_num_sounds; // weak
extern int sound_volumes[16];
extern Sound *sound_list_head;
extern int sound_pans[16];
extern int Sound_47C578[16];
extern Sound *sound_list;
extern int _47C5C0_can_sound; // weak
extern int sound_list_last_id; // weak
extern void *faction_slv; // idb
extern BOOL sound_initialized;
extern int dword_47C5D0; // weak
extern int _47C5D4_sound_threaded_snd_id; // idb
extern DrawJobList draw_list_47C5D8; // idb
extern DrawJob *draw_list_free_pool;
extern DrawJobList draw_list_47C5E8; // idb
extern DrawJob *draw_list;
extern int dword_47C5F8; // weak
extern int _46E420_starting_cash_idx; // weak
extern char byte_47C600; // weak
extern RenderString *_47C604_mission_briefing; // idb
extern int dword_47C608; // idb
extern netz_modem *netz_modem_list;
extern netz_modem *netz_modem_list_free_pool;
extern char byte_47C654; // weak
extern char _47C658_faction_index; // weak
extern RenderString *_47C65C_render_string; // idb
extern int dword_47C660; // weak
extern Sprite *_47C664_ingame_menu_sprite;
extern Sprite *_47C668_ingame_menu_sprites[10];
extern _UNKNOWN unk_47C690; // weak
extern int dword_47C6B8; // idb
extern int netz_47C6BC_mapd_idx;
extern int netz_47C6C0_mapd_idx;
extern int dword_47C6C4; // weak
extern int stru29_list_initialized; // weak
extern int netz_modem_47C6CC_idx; // weak
extern int netz_modem_list_used; // idb
extern int _47C6D8_use__466098_cost_multipliers;
extern int _47C6DC_dont_execute_unit_handlers; // weak
extern Script *_47C6E0_task; // idb
extern int dword_47C6E4; // weak
extern int dword_47C6E8; // weak
extern int dword_47C6EC; // idb
extern int dword_47C6F0; // weak
extern int dword_47C6F4; // weak
extern int dword_47C6F8; // weak
extern int dword_47C700; // weak
extern Script *script_list_free_pool;
extern void(*task_creation_handler)(Script *);
extern Script *script_execute_list;
extern Script *script_list_47C714;
extern size_t coroutine_default_stack_size; // idb
extern Script *task_creation_handler_arg;
extern __int16 is_async_execution_supported; // weak
extern Script *script_list;
extern int stru8_list_size; // weak
extern int stru8_list_allocated; // weak
extern stru8 *stru8_list;
extern stru8 *stru8_list_head;
extern RenderString *render_string_list;
extern RenderString *render_string_list_free_pool;
extern RenderString *render_string_list_47C784;
extern BuildingPlanner _47C788_building_planner; // weak
extern ProductionGroup _47C798_infantry_pg;     // 47C798
extern ProductionGroup _47C7E4_vehicles_pg;     // 47C7E4
extern ProductionGroup _47C830_buildings_pg;    // 47C830
extern ProductionGroup _47C87C_towers_pg;       // 47C87C
extern ProductionGroup _47C8C8_aircraft_pg;     // 47C8C8
ProductionGroup *ProductionGroupAccessor(PRODUCTION_GROUP_ID group);
extern Sidebar *_47C914_sidebar;
extern ProductionGroup *production_group_list_47C918;
extern ProductionGroup *production_group_list_47C91C;
extern ProductionGroup *production_group_list;
extern ProductionGroup *production_group_free_pool;
extern Sprite *_47C96C_mobd_1F_sidebar_empty_blocks; // idb
extern Script *_47C970_sidebar_task; // idb
extern stru19production _47C978_production;
extern stru19production _47C990_production;
extern stru12_game_globals game_globals_per_player;
extern ProductionOption *production_option_list_47C9C8;
extern ProductionOption *production_option_list_47C9CC;
extern ProductionOption *production_option_list;
extern ProductionOption *production_option_list_free_pool;
extern RenderString *_47CA00_render_string;
extern SidebarButton *_47CA08_sidebar_buttons[2];
extern SidebarButton *_47CA10_sidebar_button_minimap;
extern SidebarButton *_47CA18_sidebar_production_buttons[5];
extern int _47CA2C_should_airstrike_mess_with_sidebar; // weak
extern char netz_47CA30[80]; // idb
extern _47CA80_global _47CA80_array[7];
extern Script *_47CAF0_tasks_evt39030[7];
extern int dword_47CB0C; // weak
extern int dword_47CB10; // weak
extern _DWORD dword_47CB14; // idb
extern int dword_47CB18; // weak
extern int dword_47CB1C; // weak
extern int dword_47CB20; // weak
extern MapdScrlImageTile *fog_of_war_tile_15;
extern int __478AAC_map_height_plus4; // weak
extern MapdScrlImage *fog_of_war_scrl_source;
extern int __478AAC_map_height_x2; // weak
extern MapdScrlImageTile *fog_of_war_tile_1;
extern MapdScrlImageTile *fog_of_war_tile_10;
extern MapdScrlImageTile *fog_of_war_tile_14;
extern MapdScrlImageTile *fog_of_war_tile_4;
extern MapdScrlImage *map_fog_of_war_scrl;
extern int dword_47CB4C; // weak
extern char byte_47CB50[8];
extern Sprite *_47CB58_minimap_sprite;
extern MapdScrlImageTile *fog_of_war_tile_11;
extern MapdScrlImageTile *fog_of_war_tile_7;
extern MapdScrlImageTile *fog_of_war_tile_3;
extern int dword_47CB68; // weak
extern int dword_47CB6C; // weak
extern MapdScrlImageTile *fog_of_war_tile_13;
extern void *_47CB74_fow_map_x2; // idb
extern MapdScrlImageTile *fog_of_war_tile_6;
extern int __4793F8_map_width_x2; // weak
extern int __4793F8_map_width_plus4; // weak
extern MapdScrlImageTile *fog_of_war_tile_8;
extern void *_47CB88_fow_map_x2; // idb
extern DrawHandlerData_Units *_47CB8C_fow;
extern MapdScrlImageTile *fog_of_war_tile_5;
extern MapdScrlImageTile *fog_of_war_tile_12;
extern void *_47CB98_fow_map_x2;
extern int dword_47CBAC; // weak
extern Bitmap *fog_of_war_bitmap;
extern MapdScrlImageTile **map_fog_of_war_scrl_tiles;
extern MapdScrlImageTile *fog_of_war_tile_9;
extern MapdScrlImageTile *fog_of_war_tile_2;
extern int _47CBC0_fow[256];
extern int dword_47CFC0; // weak
extern int __47CFC4_mobd_lookup_speeds[256];
extern int _47D3C4_entity_mobd_lookup_ids[257];
extern unsigned __int8 player_sprite_palette_tmp[256];
extern stru12_game_globals game_globals_cpu[7];
extern int entity_drag_selection_x; // weak
extern Script *pscript_show_message_ex; // idb
extern int entity_drag_selection_w; // weak
extern int entity_drag_selection_z; // weak
extern Script *pscript_show_message; // idb
extern int entity_drag_selection_y; // weak
extern int _4269B0_task_attachment__4_some_task_flags; // weak
extern stru11unit *stru11unit_list_47DC70;
extern stru11unit *stru11unit_list_47DC74;
extern stru11unit *stru11unit_list;
extern stru11unit *stru11unit_list_head;
extern unsigned __int8 *per_player_sprite_palettes[7];
extern std::list<Entity *> entity_drag_selection_list;
extern int player_sprite_color_by_player_side[7];
extern int _47DCC4_entity_id_counter; // weak
extern int UNIT_num_player_units; // weak
extern int UNIT_num_nonplayer_units; // weak
extern int num_players_towers; // weak
extern void *entity_default_stru60_ptr;
extern int dword_47DCE8; // weak
extern HINSTANCE global_hinstance; // idb
extern int global_win32_nCmdShow; // idb
extern bool _47DCF4_wm_quit_received; // weak