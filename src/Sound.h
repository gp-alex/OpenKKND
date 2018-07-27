#pragma once

#include "src/Script.h"

#include "src/Infrastructure/File.h"



/* 363 */
enum SOUND_ID : __int32
{
    SOUND_0 = 0,
    SOUND_3 = 3,
    SOUND_RIFLE_FIRE = 4,
    SOUND_LOW_CALIBER_MACHINEGUN_FIRE = 5,
    SOUND_CANNON_FIRE = 6,
    SOUND_BIKE_AND_SIDECAR_FIRE = 7,
    SOUND_MACHINEGUN_FIRE = 8,
    SOUND_GENERIC_PROJECTILE_DMG = 9,
    SOUND_GENERIC_PROJECTILE_DMG_2 = 10,
    SOUND_RIFLE_FIRE_2 = 11,
    SOUND_RIFLE_FIRE_3 = 12,
    SOUND_RIFLE_FIRE_4 = 13,
    SOUND_14_dmg = 14,
    SOUND_SHOTGUN_FIRE = 17,
    SOUND_20 = 20,
    SOUND_23 = 23,
    SOUND_26_sabotage = 26,
    SOUND_28_technician = 28,
    SOUND_SURV_BUILDING_COMPLETED = 32,
    SOUND_SURV_UNIT_READY = 33,
    SOUND_40_sabotage = 40,
    SOUND_43 = 43,
    SOUND_45_surv_saboteur = 45,
    SOUND_SURV_LOW_OIL_WARNING = 47,
    SOUND_48 = 48,
    SOUND_49 = 49,
    SOUND_50 = 50,
    SOUND_51 = 51,
    SOUND_52 = 52,
    SOUND_53 = 53,
    SOUND_SURV_COMMENCING_UPGRADE = 54,
    SOUND_SURV_UPGRADE_COMPLETE_1 = 55,
    SOUND_SURV_UNIT_DRILL_RIG = 56,
    SOUND_59 = 59,
    SOUND_60 = 60,
    SOUND_SURV_UPGRADE_COMPLETE_2 = 62,
    SOUND_SURV_AIRSTRIKE_READY = 66,
    SOUND_68 = 68,
    SOUND_69 = 69,
    SOUND_70 = 70,
    SOUND_71 = 71,
    SOUND_72 = 72,
    SOUND_73 = 73,
    SOUND_76 = 76,
    SOUND_78 = 78,
    SOUND_85 = 85,
    SOUND_LASER_DMG = 87,
    SOUND_88 = 88,
    SOUND_89_dmg_handler = 89,
    SOUND_90_dmg_handler = 90,
    SOUND_91 = 91,
    SOUND_92 = 92,
    SOUND_93_sabotage = 93,
    SOUND_MUTE_BUILDING_COMPLETED = 96,
    SOUND_101 = 101,
    SOUND_MUTE_UPGRADE_COMPLETE_1 = 102,
    SOUND_MUTE_UPGRADE_COMPLETE_2 = 104,
    SOUND_105_sabotage = 105,
    SOUND_108_mekanik = 108,
    SOUND_116 = 116,
    SOUND_119 = 119,
    SOUND_MUTE_LOW_OIL_WARNING = 122,
    SOUND_124_mute_saboteur = 124,
    SOUND_MUTE_UNIT_READY = 125,
    SOUND_MUTE_COMMENCING_UPGRADE = 126,
    SOUND_MUTE_UNIT_DRILL_RIG = 128,
    SOUND_129 = 129,
    SOUND_131 = 131,
    SOUND_132 = 132,
    SOUND_133 = 133,
    SOUND_MUTE_AIRSTRIKE_READY = 136,
    SOUND_139 = 139,
    SOUND_140 = 140,
    SOUND_141 = 141,
    SOUND_142 = 142,
    SOUND_148 = 148,
    SOUND_153 = 153,
    SOUND_154 = 154,
    SOUND_155 = 155,
    SOUND_156 = 156,
    SOUND_157 = 157,
    SOUND_158 = 158,
    SOUND_MUTE_UNIT_WAR_MASTADONT_2 = 159,
    SOUND_MUTE_UNIT_WAR_MASTADONT_READY = 160,
    SOUND_ACID_SPIT_DMG = 161,
    SOUND_163 = 163,
    SOUND_MUTE_UNIT_DIRE_WOLF_2 = 164,
    SOUND_MUTE_UNIT_DIRE_WOLF_READY = 165,
    SOUND_MISSION_OUTCOME_LETTER_APPEARING = 166,
    SOUND_MUTE_UNIT_GIANT_BEETLE_READY = 168,
    SOUND_MUTE_UNIT_GIANT_BEETLE_2 = 169,
    SOUND_MUTE_UNIT_MISSILE_CRAB_READY = 170,
    SOUND_MUTE_UNIT_MISSILE_CRAB_2 = 171,
    SOUND_MUTE_UNIT_GIANT_SCORPION_READY = 172,
    SOUND_MUTE_UNIT_GIANT_SCORPION_2 = 173,
    SOUND_174 = 174,
    SOUND_175 = 175,
    SOUND_176 = 176,
    SOUND_177 = 177,
    SOUND_178 = 178,
    SOUND_179 = 179,
    SOUND_180 = 180,
    SOUND_181 = 181,
    SOUND_182 = 182,
    SOUND_183 = 183,
    SOUND_184 = 184,
    SOUND_185 = 185,
    SOUND_186 = 186,
    SOUND_187 = 187,
    SOUND_188 = 188,
    SOUND_MobileOutpost_ClanhallWagon_Planted = 189,
    SOUND_SHOTGUN_FIRE_2 = 190,
    SOUND_TANKER_OIL_UNLOADING = 191,
    SOUND_SURV_UNIT_SCOUT_192 = 192,
    SOUND_193 = 193,
};




bool LVL_LoadSlv(const char *slv_filename);
bool sound_initialize();
int sound_play(enum SOUND_ID sound_id, int a2, int volume_offset, int pan_offset, Script *script);
int sound_play_threaded(const char *name, int a2, int sound_volume_offset, int sound_pan_offset, Script *task); // idb
void sound_stop(int sound_id);
void sound_free_sounds();
void _43A370_process_sound();
void sound_deinit();
void sound_list_43A800(int a1);

SOUND_ID get_unit_seletion_sound(UNIT_ID unit_id);
SOUND_ID get_unit_move_confirmation_sound(UNIT_ID unit_id, bool experienced);
SOUND_ID get_unit_attack_confirmation_sound(UNIT_ID unit_id, bool experienced);
SOUND_ID get_unit_ready_sound(UNIT_ID unit_id);

void sound_start_video_playback();
void sound_end_video_playback();
bool sound_video_get_position(int *play, int *write);
void sound_video_stop();


extern int _47C5D4_sound_threaded_snd_id; // idb



extern SOUND_ID _468988_sound_ids[4];
extern SOUND_ID _468998_sound_ids[4];
extern SOUND_ID _4689A8_sound_ids[2];
extern SOUND_ID _4689B0_sound_ids[4];
extern SOUND_ID _4689C0_sound_ids[22];
extern SOUND_ID _468A18_sound_ids[2];
extern SOUND_ID _468A20_sound_ids[2];
extern SOUND_ID _468A28_sound_ids[4];
extern SOUND_ID _468A38_sound_ids[4];
extern SOUND_ID _468A48_sound_ids[2];
extern SOUND_ID _468A50_sound_ids[2];
extern SOUND_ID _468A58_sound_id;

extern SOUND_ID _46BB70_dmg_handler_sounds[3];
extern SOUND_ID _46BB80_dmg_handler_sounds[2];

extern SOUND_ID _465988_sounds[5];