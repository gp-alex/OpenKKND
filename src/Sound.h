#pragma once

#include <process.h>    // _beginthread, _endthread
#include <dsound.h>

#include "src/Script.h"

#include "src/Infrastructure/File.h"



/* 262 */
struct Sound
{
    int id;
    IDirectSoundBuffer *pdsb;
    Script *task;
    File *file;
    int hthread;
    int field_14;
    int field_18;
    int sound_volume_offset;
    int field_20;
    int field_24;
    int sound_pan_offset;
    int field_2C;
    int field_30;
    int flags;
    Sound *next;
    Sound *prev;
    int field_40;
    char filename[32];
    char gap64[42];
    char field_8E[100];
    char field_F2[80];
    char field_142;
    char field_143;
    char field_144;
    char field_145;
    char field_146;
    char field_147;
};


/* 428 */
struct sound_stru_2
{
    int riff_fourcc;
    int riff_chunk_size;
    int data_fourcc;
    int data;
};



bool LVL_LoadSlv(const char *slv_filename);
bool sound_initialize();
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

void sound_start_video_playback();
void sound_end_video_playback();
bool sound_video_get_position(int *play, int *write);
void sound_video_stop();


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