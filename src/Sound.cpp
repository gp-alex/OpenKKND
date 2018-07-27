#include <direct.h>

#include <dsound.h>
#include <process.h>    // _beginthread, _endthread

#include "src/Sound.h"

#include "src/kknd.h"
#include "src/Random.h"
#include "src/ScriptEvent.h"
#include "src/_unsorted_functions.h"

#include "src/Engine/Entity.h"


#pragma comment(lib, "Dsound.lib") // DirectSoundCreate





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





int sound_list_end; // weak
Sound *sound_list_free_pool;
Sound *sound_list_47C3D4;
sound_stru_2 **_47C4E0_sounds;
LPDIRECTSOUND pds; // idb
int _47C4E8_num_sounds; // weak
int sound_volumes[16];
Sound *sound_list_head;
int sound_pans[16];
int Sound_47C578[16];
Sound *sound_list;
int _47C5C0_can_sound; // weak
int sound_list_last_id; // weak
void *faction_slv; // idb
bool sound_initialized = false;
int dword_47C5D0; // weak
int _47C5D4_sound_threaded_snd_id; // idb


SOUND_ID _468988_sound_ids[4] = { SOUND_69, SOUND_53, SOUND_51, SOUND_50 };
SOUND_ID _468998_sound_ids[4] = { SOUND_139, SOUND_116, SOUND_142, SOUND_140 };
SOUND_ID _4689A8_sound_ids[2] = { SOUND_181, SOUND_182 };
SOUND_ID _4689B0_sound_ids[4] = { SOUND_179, SOUND_180, SOUND_185, SOUND_0 };
SOUND_ID _4689C0_sound_ids[22] =
{
    SOUND_182,
    SOUND_183,
    SOUND_184,
    SOUND_182,
    SOUND_183,
    SOUND_184,
    SOUND_182,
    SOUND_183,
    SOUND_184,
    SOUND_182,
    SOUND_183,
    SOUND_184,
    SOUND_182,
    SOUND_183,
    SOUND_184,
    SOUND_182,
    SOUND_183,
    SOUND_184,
    SOUND_182,
    SOUND_183,
    SOUND_184,
    SOUND_186
};
SOUND_ID _468A18_sound_ids[2] = { SOUND_78, SOUND_85 };
SOUND_ID _468A20_sound_ids[2] = { SOUND_156, SOUND_158 };
SOUND_ID _468A28_sound_ids[4] = { SOUND_68, SOUND_49, SOUND_43, SOUND_0 };
SOUND_ID _468A38_sound_ids[4] = { SOUND_133, SOUND_131, SOUND_91, SOUND_0 };
SOUND_ID _468A48_sound_ids[2] = { SOUND_76, SOUND_85 };
SOUND_ID _468A50_sound_ids[2] = { SOUND_154, SOUND_148 };
SOUND_ID _468A58_sound_id = SOUND_69;


SOUND_ID _46BB70_dmg_handler_sounds[3] = { SOUND_RIFLE_FIRE_2, SOUND_RIFLE_FIRE_3, SOUND_RIFLE_FIRE_4 };
SOUND_ID _46BB80_dmg_handler_sounds[2] = { SOUND_GENERIC_PROJECTILE_DMG, SOUND_GENERIC_PROJECTILE_DMG_2 };

SOUND_ID _465988_sounds[5] = { SOUND_174, SOUND_175, SOUND_176, SOUND_177, SOUND_178 };


bool file_read_wav(File *file, WAVEFORMATEX *out_data, unsigned int *a3);
bool sound_stru_2_43A710(sound_stru_2 *a1, WAVEFORMATEX **a2, int *a3, unsigned int *out_buffer_size);
void _439C10_sound_thread(Sound *a1); // idb
void sound_list_remove(Sound *a1);





DSBUFFERDESC video_477DE4_dsb_desc; // weak
IDirectSoundBuffer *video_477DE4_dsb;

void sound_start_video_playback() {

}

void sound_end_video_playback() {

}

bool sound_video_get_position(int *play, int *write) {
    return S_OK == video_477DE4_dsb->GetCurrentPosition(
        (LPDWORD)play,
        (LPDWORD)write
    );
}

void sound_video_stop() {
    video_477DE4_dsb->Stop();
    video_477DE4_dsb->Release();
}




SOUND_ID get_unit_seletion_sound(UNIT_ID unit_id)
{
    switch (unit_id)
    {
    case UNIT_STATS_GORT:
    case UNIT_STATS_PLASMA_TANK:
    case UNIT_STATS_SENTINEL_DROID:
        return _4689A8_sound_ids[kknd_rand() % -2];
        break;
    case UNIT_STATS_MUTE_DIRE_WOLF:
        return (SOUND_ID)165;
        break;
    case UNIT_STATS_MUTE_GIANT_BEETLE:
        return (SOUND_ID)168;
        break;
    case UNIT_STATS_MUTE_GIANT_SCORPION:
        return (SOUND_ID)172;
        break;
    case UNIT_STATS_MUTE_MISSILE_CRAB:
        return (SOUND_ID)170;
        break;
    case UNIT_STATS_MUTE_WAR_MASTADONT:
        return (SOUND_ID)160;
        break;
    default:
        if (is_player_faction_evolved())
        {
            return _468998_sound_ids[(unsigned __int8)((char)kknd_rand() % -4)];
        }
        else
        {
            return _468988_sound_ids[(unsigned __int8)((char)kknd_rand() % -4)];
        }
        break;
    }
}


SOUND_ID get_unit_move_confirmation_sound(UNIT_ID unit_id, bool experienced)
{
    if (is_21st_century(unit_id))
    {
        return _4689C0_sound_ids[kknd_rand() % 22];
    }
    else if (unit_id == UNIT_STATS_SURV_SCOUT)
    {
        return SOUND_SURV_UNIT_SCOUT_192;
    }
    else if (unit_id == UNIT_STATS_MUTE_MISSILE_CRAB)
    {
        return SOUND_MUTE_UNIT_MISSILE_CRAB_2;
    }
    else if (unit_id == UNIT_STATS_MUTE_GIANT_BEETLE)
    {
        return SOUND_MUTE_UNIT_GIANT_BEETLE_2;
    }
    else if (unit_id == UNIT_STATS_MUTE_WAR_MASTADONT)
    {
        return SOUND_MUTE_UNIT_WAR_MASTADONT_2;
    }
    else if (unit_id == UNIT_STATS_MUTE_GIANT_SCORPION)
    {
        return SOUND_MUTE_UNIT_GIANT_SCORPION_2;
    }
    else if (unit_id == UNIT_STATS_MUTE_DIRE_WOLF)
    {
        return SOUND_MUTE_UNIT_DIRE_WOLF_2;
    }
    else
    {
        if (!is_player_faction_evolved())
        {
            if (experienced)
            {
                int v13 = kknd_rand();
                return _468A48_sound_ids[(((unsigned __int64)v13 >> 32) ^ abs(v13) & 1) - ((unsigned __int64)v13 >> 32)];
            }
            else
            {
                return _468A28_sound_ids[kknd_rand() % 3];
            }
        }
        else
        {
            if (experienced)
            {
                int v14 = kknd_rand();
                return _468A50_sound_ids[(((unsigned __int64)v14 >> 32) ^ abs(v14) & 1) - ((unsigned __int64)v14 >> 32)];
            }
            else
            {
                return _468A38_sound_ids[kknd_rand() % 3];
            }
        }
    }
}


SOUND_ID get_unit_attack_confirmation_sound(UNIT_ID unit_id, bool experienced)
{
    if (is_21st_century(unit_id))
    {
        return _4689B0_sound_ids[kknd_rand() % 3];
    }
    else if (unit_id == UNIT_STATS_MUTE_MISSILE_CRAB)
    {
        return SOUND_MUTE_UNIT_MISSILE_CRAB_2;
    }
    else if (unit_id == UNIT_STATS_MUTE_GIANT_BEETLE)
    {
        return SOUND_MUTE_UNIT_GIANT_BEETLE_2;
    }
    else if (unit_id == UNIT_STATS_MUTE_WAR_MASTADONT)
    {
        return SOUND_MUTE_UNIT_WAR_MASTADONT_2;
    }
    else if (unit_id == UNIT_STATS_MUTE_GIANT_SCORPION)
    {
        return SOUND_MUTE_UNIT_GIANT_SCORPION_2;
    }
    else if (unit_id == UNIT_STATS_MUTE_DIRE_WOLF)
    {
        return SOUND_MUTE_UNIT_DIRE_WOLF_2;
    }
    else if (unit_id == UNIT_STATS_SURV_SCOUT)
    {
        return SOUND_SURV_UNIT_SCOUT_192;
    }
    else
    {
        if (experienced)
        {
            if (is_player_faction_evolved())
                return SOUND_153;
            else
                return SOUND_73;
        }
        else
        {
            if (!is_player_faction_evolved())
            {
                if ((char)kknd_rand() % -2)
                {
                    return SOUND_59;
                }
                else
                {
                    return SOUND_48;
                }
            }
            else
            {
                if ((char)kknd_rand() % -2)
                {
                    return SOUND_92;
                }
                else
                {
                    return SOUND_119;
                }
            }
        }
    }
}


SOUND_ID get_unit_ready_sound(UNIT_ID unit_id)
{
    switch (unit_id)
    {
    case UNIT_STATS_MUTE_DIRE_WOLF:
        return SOUND_MUTE_UNIT_DIRE_WOLF_READY;

    case UNIT_STATS_MUTE_GIANT_BEETLE:
        return SOUND_MUTE_UNIT_GIANT_BEETLE_READY;

    case UNIT_STATS_MUTE_GIANT_SCORPION:
        return SOUND_MUTE_UNIT_GIANT_SCORPION_READY;

    case UNIT_STATS_MUTE_MISSILE_CRAB:
        return SOUND_MUTE_UNIT_MISSILE_CRAB_READY;

    case UNIT_STATS_MUTE_WAR_MASTADONT:
        return SOUND_MUTE_UNIT_WAR_MASTADONT_READY;

    default:
    {
        int v14 = kknd_rand();
        if (is_player_faction_evolved())
        {
            return _468998_sound_ids[(((unsigned __int64)v14 >> 32) ^ abs(v14) & 3) - ((unsigned __int64)v14 >> 32)];
        }
        else
        {
            return _468988_sound_ids[(((unsigned __int64)v14 >> 32) ^ abs(v14) & 3) - ((unsigned __int64)v14 >> 32)];
        }
    }
    }
}



//----- (00439440) --------------------------------------------------------
bool sound_initialize()
{
    int v0; // eax@1
    int *v1; // esi@1
    int v2; // eax@3
    int *v3; // esi@3
    int v4; // esi@5
    int *v5; // edi@5
    Sound *v6; // ecx@9
    BOOL result; // eax@10
    int v8; // eax@11
    int v9; // [sp+Ch] [bp-4h]@5

    v0 = 0;
    v1 = sound_volumes;
    for (int i = 0; i < 16; ++i)
    {
        //*v1 = (signed __int64)(__FYL2X__((double)(v0 + 1) * 0.05882352941176471, 0.69314718055994528623) * 1000.0);
        *v1 = 1000.0 * 0.69314718055994528623 * log2((double)(v0 + 1) * 0.05882352941176471);
        ++v1;
        ++v0;
    }
    v2 = 0;
    v3 = sound_pans;
    for (int i = 0; i < 16; ++i)
    {
        //*v3 = (signed __int64)(__FYL2X__((double)(v2 + 1) * 0.05882352941176471, 0.69314718055994528623) * 1000.0);
        *v3 = 1000.0 * 0.69314718055994528623 * log2((double)(v2 + 1) * 0.05882352941176471);
        ++v3;
        ++v2;
    }
    v4 = 17;
    v5 = Sound_47C578;
    v9 = 17;
    do
    {
        //*v5 = (signed __int64)(__FYL2X__((double)v9 * 0.05882352941176471, 0.69314718055994528623) * -1000.0);
        *v5 = -1000.0 * 0.69314718055994528623 * log2((double)v9 * 0.05882352941176471);
        --v4;
        ++v5;
        v9 = v4;
    } while (v4 >= 1);
    sound_initialized = 0;
    sound_list_last_id = 0;
    sound_list_end = 0;
    sound_list_free_pool = (Sound *)&sound_list_end;
    sound_list_47C3D4 = (Sound *)&sound_list_end;
    sound_list_head = 0;
    if (DirectSoundCreate(0, &pds, 0))
        return 1;

    extern HWND global_hwnd;
    if (pds->SetCooperativeLevel(global_hwnd, 1))
    {
        pds->Release();
        pds = 0;
        return 1;
    }
    sound_list = (Sound *)malloc(0xA40u);
    memset(sound_list, 0, 0xA40u);
    v6 = sound_list;
    if (sound_list)
    {
        v8 = 0;
        while (1)
        {
            v6[v8].next = &v6[v8 + 1];
            ++v8;
            if (v8 >= 7)
                break;
            v6 = sound_list;
        }
        sound_list[7].next = 0;
        sound_list_end = 0;
        sound_list_free_pool = (Sound *)&sound_list_end;
        sound_list_47C3D4 = (Sound *)&sound_list_end;
        sound_list_head = sound_list;
        sound_initialized = 1;
        result = 1;
    }
    else
    {
        pds->Release();
        pds = 0;
        result = 1;
    }
    return result;
}




//----- (00439610) --------------------------------------------------------
bool LVL_LoadSlv(const char *slv_filename)
{
    DataHunk *v1; // eax@2
    DataSectionOffset *v2; // eax@4
    sound_stru_2 **v3; // edx@4
    char *v4; // esi@4
    int v5; // ecx@7
    int v6; // ecx@9
    sound_stru_2 **v7; // eax@10
    sound_stru_2 *v8; // edx@11

    _47C5C0_can_sound = 0;
    if (sound_initialized)
    {
        v1 = LVL_LoadLevel(slv_filename);
        faction_slv = v1;
        if (v1 || (v1 = LVL_LoadLevel("sound.slv"), (faction_slv = v1) != 0))
        {
            v2 = v1->section_table;
            v3 = 0;
            _47C4E0_sounds = 0;
            v4 = (char *)&v2->ptr;
            if (v2->ptr)
            {
                do
                {
                    if (!strncmp("SOUN", v2->name, 4u))
                        _47C4E0_sounds = *(sound_stru_2 ***)v4;
                    v5 = *((_DWORD *)v4 + 2);
                    v4 += 8;
                    v2 = (DataSectionOffset *)(v4 - 4);
                } while (v5);
                v3 = _47C4E0_sounds;
            }
            v6 = 0;
            if (*v3)
            {
                v7 = v3;
                do
                {
                    v8 = v7[1];
                    ++v7;
                    ++v6;
                } while (v8);
            }
            _47C4E8_num_sounds = v6;
            _47C5C0_can_sound = 1;
        }
    }
    return 1;
}

//----- (004396C0) --------------------------------------------------------
int sound_play(enum SOUND_ID sound_id, int a2, int volume_offset, int pan_offset, Script *script)
{
    return 0;
    void *v5; // eax@0
    int v6; // eax@3
    Sound *v7; // eax@4
    int result; // eax@7
    sound_stru_2 *v9; // esi@10
    Sound *v10; // ebx@12
    IDirectSoundBuffer **v11; // edi@20
    IDirectSoundBuffer *v12; // eax@21
    bool v13; // zf@21
    unsigned int v14; // ecx@25
    void *v15; // eax@27
    Sound *v16; // eax@33
    Sound *v17; // eax@35
    Sound *v18; // eax@37
    Sound *v19; // eax@46
    Sound *v20; // eax@48
    Sound *v21; // eax@50
    int v22; // [sp+0h] [bp-3Ch]@3
    DSBUFFERDESC v23; // [sp+Ch] [bp-30h]@4
    int v24; // [sp+20h] [bp-1Ch]@1
    IDirectSoundBuffer *v25; // [sp+24h] [bp-18h]@21
    void *v26; // [sp+28h] [bp-14h]@24
    char *v27; // [sp+2Ch] [bp-10h]@24
    unsigned int v28; // [sp+30h] [bp-Ch]@24
    const void *v29; // [sp+34h] [bp-8h]@21
    int a3a; // [sp+38h] [bp-4h]@4

    v24 = a2;

    v7 = 0;
    v23.dwFlags = 0;
    v23.dwSize = 0;
    v23.dwBufferBytes = 0;
    a3a = 0;
    v23.dwReserved = 0;
    v23.lpwfxFormat = 0;
    if (volume_offset)
    {
        if (_47C5C0_can_sound && sound_id < _47C4E8_num_sounds)
        {
            v9 = _47C4E0_sounds[sound_id];
            if (v9 != faction_slv && v9)
            {
                v10 = sound_list_head;
                if (sound_list_head)
                {
                    sound_list_head = sound_list_head->next;
                    memset(v10, 0, sizeof(Sound));
                    if (!++sound_list_last_id)
                        sound_list_last_id = 1;
                    v10->id = sound_list_last_id;
                    v7 = sound_list_free_pool;
                    v10->next = sound_list_free_pool;
                    v10->prev = (Sound *)&sound_list_end;
                    sound_list_free_pool->prev = v10;
                    sound_list_free_pool = v10;
                }
                if (v10)
                {
                    v10->task = script;
                    v10->sound_volume_offset = volume_offset;
                    v10->sound_pan_offset = pan_offset;
                    v10->field_14 = -2;
                    sound_stru_2_43A710(v9, &v23.lpwfxFormat, &a3a, (unsigned int *)&v23.dwBufferBytes);
                    v11 = &v10->pdsb;
                    v23.dwSize = 20;
                    v23.dwFlags = 232;
                    if (pds->CreateSoundBuffer(&v23, &v10->pdsb, 0))
                    {
                        v16 = v10->next;
                        if (v16)
                            v16->prev = v10->prev;
                        v17 = v10->prev;
                        if (v17)
                            v17->next = v10->next;
                        v18 = sound_list_head;
                        v10->next = sound_list_head;
                        sound_list_head = v10;

                        result = 0;
                    }
                    else
                    {
                        v12 = *v11;
                        v13 = *v11 == 0;
                        v29 = (const void *)a3a;
                        v25 = v12;
                        if (v13
                            || !a3a
                            || !v23.dwBufferBytes
                            || v12->Lock(0, v23.dwBufferBytes, &v26, (LPDWORD)&script, (LPVOID *)&v27, (LPDWORD)&v28, 0))
                        {
                            (*v11)->Release();
                            v19 = v10->next;
                            *v11 = 0;
                            if (v19)
                                v19->prev = v10->prev;
                            v20 = v10->prev;
                            if (v20)
                                v20->next = v10->next;
                            v21 = sound_list_head;
                            v10->next = sound_list_head;
                            sound_list_head = v10;

                            result = 0;
                        }
                        else
                        {
                            memcpy(v26, v29, (unsigned int)script);
                            v14 = v28;
                            if (v28)
                            {
                                memcpy(v27, (char *)script + (_DWORD)v29, v28);
                                v14 = v28;
                            }
                            v25->Unlock(v26, (DWORD)script, v27, v14);
                            v10->pdsb->SetPan(sound_pans[pan_offset]);
                            v10->pdsb->SetVolume(sound_volumes[volume_offset]);
                            v15 = (void *)dword_47C5D0;
                            if (dword_47C5D0)
                                ++v10->field_18;
                            else
                                v15 = (void *)v10->pdsb->Play(0, 0, v24);

                            result = v10->id;
                        }
                    }
                }
                else
                {

                    result = 0;
                }
            }
            else
            {
                result = 0;
            }
        }
        else
        {
            result = 0;
        }
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (00439AA0) --------------------------------------------------------
int sound_play_threaded(const char *name_, int a2, int sound_volume_offset, int sound_pan_offset, Script *task)
{
    int result; // eax@2
    Sound *v6; // ebx@3
    Sound *v7; // eax@6
    int v8; // eax@10
    int v9; // esi@11
    int v10; // eax@11
    const char *v11; // edi@13
    int v12; // eax@13
    int v13; // ecx@13
    void *v14; // eax@13
    int v15; // [sp+0h] [bp-10h]@10
    const char *v16; // [sp+Ch] [bp-4h]@1


    char cwd[1024];
    char name[1024];
    sprintf(
        name,
        "%s\\LEVELS\\%s",
        _getcwd(cwd, sizeof(cwd)),
        name_
    );

    v16 = name;
    if (sound_initialized)
    {
        v6 = sound_list_head;
        if (!sound_list_head)
            goto LABEL_18;
        sound_list_head = sound_list_head->next;
        memset(v6, 0, sizeof(Sound));
        if (!++sound_list_last_id)
            sound_list_last_id = 1;
        v6->id = sound_list_last_id;
        v7 = sound_list_free_pool;
        v6->next = sound_list_free_pool;
        v6->prev = (Sound *)&sound_list_end;
        sound_list_free_pool->prev = v6;
        sound_list_free_pool = v6;
        if (v6)
        {
            v9 = v6->flags | 8;
            v6->task = task;
            v6->field_14 = -3;
            v6->sound_volume_offset = sound_volume_offset;
            v6->flags = v9;
            v10 = v9;
            if (a2 == 1)
            {
                LOBYTE_HEXRAYS(v10) = v9 | 0x10;
                v6->flags = v10;
            }
            v11 = v16;
            v6->sound_pan_offset = sound_pan_offset;
            strcpy(v6->filename, v11);
            v12 = _beginthread((_beginthread_proc_type)_439C10_sound_thread, 0x1000u, v6);
            v13 = v6->id;
            v6->hthread = v12;
            _47C5D4_sound_threaded_snd_id = v13;
            v14 = (void *)v6->flags;
            LOBYTE_HEXRAYS(v14) = (unsigned __int8)v14 | 8;
            v6->flags = (int)v14;

            result = v6->id;
        }
        else
        {
        LABEL_18:
            result = 0;
        }
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (00439C10) --------------------------------------------------------
void _439C10_sound_thread(Sound *a1)
{
    Sound *v1; // esi@1
    char *v2; // ebp@1
    const char *v3; // ecx@1
    File *v4; // ecx@5
    IDirectSoundBuffer **v5; // ebx@7
    int v6; // eax@8
    DWORD v7; // edi@9
    int v8; // eax@9
    Sound *v9; // ecx@12
    unsigned int v10; // edi@13
    unsigned int v11; // eax@15
    unsigned int v12; // edi@15
    int v13; // eax@18
    int v14; // eax@20
    unsigned int v15; // edx@22
    int v16; // eax@25
    int v17; // eax@31
    int v18; // edi@32
    int v19; // eax@35
    DWORD v20; // eax@38
    DWORD v21; // edi@40
    int v22; // eax@40
    Sound *v23; // ecx@43
    unsigned int v24; // edi@44
    int v25; // eax@46
    unsigned int v26; // edx@46
    unsigned int v27; // edi@46
    int v28; // eax@46
    int v29; // eax@55
    unsigned int v30; // edx@57
    int v31; // eax@57
    int v32; // eax@67
    int v33; // eax@69
    File *v34; // ecx@71
    int v35; // ebx@75
    int v36; // eax@76
    DWORD v37; // eax@78
    char *v38; // edi@84
    char v39; // dl@85
    unsigned int v40; // ecx@85
    int v41; // eax@90
    Sound *v42; // eax@91
    Sound *v43; // eax@93
    Sound *v44; // eax@96
    Sound *v45; // eax@98
    int num_bytes; // [sp+108h] [bp-70h]@9
    void *v47; // [sp+10Ch] [bp-6Ch]@9
    void *v48; // [sp+110h] [bp-68h]@9
    unsigned int v49; // [sp+114h] [bp-64h]@8
    unsigned int v50; // [sp+118h] [bp-60h]@1
    int v51; // [sp+11Ch] [bp-5Ch]@1
    unsigned int v52; // [sp+120h] [bp-58h]@1
    unsigned int a3; // [sp+124h] [bp-54h]@6
    WAVEFORMATEX out_data; // [sp+128h] [bp-50h]@6
    WAVEFORMATEX v55; // [sp+13Ch] [bp-3Ch]@71
    DSBCAPS v56; // [sp+150h] [bp-28h]@8
    DSBUFFERDESC v57; // [sp+164h] [bp-14h]@1

    v1 = a1;
    v57.dwFlags = 0;
    v57.dwBufferBytes = 0;
    v2 = 0;
    v3 = a1->filename;
    v57.dwReserved = 0;
    v52 = 0;
    v50 = 0;
    v51 = 0;
    v57.dwSize = 0;
    v57.lpwfxFormat = 0;
    if (a1 != (Sound *)0xFFFFFFBC && *v3)
        v1->file = File::open(v3);
    else
        a1->file = 0;
    v4 = v1->file;
    if (!v4 || !file_read_wav(v4, &out_data, &a3))
    {
        v1->file->close();
        v44 = v1->next;
        v1->flags = v1->flags & 0xFFFFFFF7 | 0x40;
        if (v44)
            v44->prev = v1->prev;
        v45 = v1->prev;
        if (v45)
            v45->next = v1->next;
        v1->next = sound_list_head;
        sound_list_head = v1;
        _endthread();
    }
    v1->field_40 = a3;
    v5 = &v1->pdsb;
    v57.dwBufferBytes = 3 * out_data.nAvgBytesPerSec;
    v57.lpwfxFormat = &out_data;
    v57.dwSize = 20;
    v57.dwFlags = 232;
    if (pds->CreateSoundBuffer(&v57, &v1->pdsb, 0))
    {
        v1->file->close();
        v42 = v1->next;
        v1->flags = v1->flags & 0xFFFFFFF7 | 0x40;
        if (v42)
            v42->prev = v1->prev;
        v43 = v1->prev;
        if (v43)
            v43->next = v1->next;
        v1->next = sound_list_head;
        sound_list_head = v1;
        _endthread();
    }
    (*v5)->SetPan(sound_pans[v1->sound_pan_offset]);
    (*v5)->SetVolume(sound_volumes[v1->sound_volume_offset]);
    v6 = v1->flags;
    LOBYTE_HEXRAYS(v6) = v6 | 8;
    v56.dwSize = 20;
    v1->flags = v6;
    (*v5)->GetCaps(&v56);
    (*v5)->GetCurrentPosition((LPDWORD)&v52, (LPDWORD)&v50);
    v49 = v1->field_40;
    if (!v52)
    {
        v7 = v56.dwBufferBytes - v50;
        v8 = (*v5)->Lock(v50, v56.dwBufferBytes - v50, &v48, (LPDWORD)&a1, &v47, (LPDWORD)&num_bytes, 0);
        if (v8 == DSERR_BUFFERLOST)
        {
            (*v5)->Restore();
            v8 = (*v5)->Lock(v50, v7, &v48, (LPDWORD)&a1, &v47, (LPDWORD)&num_bytes, 0);
        }
        if (v8)
        {
            v17 = v1->flags;
            LOBYTE_HEXRAYS(v17) = v17 | 0x20;
            v1->flags = v17;
        }
        else
        {
            v9 = a1;
            if (a1)
            {
                v10 = v49;
                if (v49 < (unsigned int)a1)
                    v9 = (Sound *)v49;
                v11 = v1->file->read(v48, (int)v9);
                v9 = a1;
                v12 = v10 - v11;
                v49 = v12;
                v2 = (char *)a1 + v50;
                if ((unsigned int)a1 + v50 >= v56.dwBufferBytes)
                    v2 -= v56.dwBufferBytes;
                if (v11 < (unsigned int)a1)
                {
                    memset((char *)v48 + v11, 0, (unsigned int)a1 - v11);
                    v13 = v1->flags;
                    v9 = a1;
                    v12 = v49;
                    LOBYTE_HEXRAYS(v13) = v13 | 0x20;
                    v1->flags = v13;
                }
                if (v47)
                {
                    v14 = num_bytes;
                    if (v12 < num_bytes)
                        v14 = v12;
                    v15 = v1->file->read(v47, v14);
                    v49 = v12 - v15;
                    v2 = (char *)(v50 + num_bytes);
                    if (v50 + num_bytes >= v56.dwBufferBytes)
                        v2 -= v56.dwBufferBytes;
                    if (v15 < num_bytes)
                    {
                        memset((char *)v47 + v15, 0, num_bytes - v15);
                        v16 = v1->flags;
                        LOBYTE_HEXRAYS(v16) = v16 | 0x20;
                        v1->flags = v16;
                    }
                    v9 = a1;
                }
            }
            (*v5)->Unlock(v48, (DWORD)v9, v47, num_bytes);
            if (dword_47C5D0)
                ++v1->field_18;
            else
                (*v5)->Play(0, 0, 1);
            v1->flags &= 0xFFFFFFF7;
            Sleep(0xAu);
        }
    }
    v18 = v51;
    do
    {
        if (v1->flags & 0x20)
            goto LABEL_89;
        while (!v18)
        {
            v19 = v1->flags;
            if (v19 & 0x20)
                break;
            if (!(v19 & 4))
            {
                LOBYTE_HEXRAYS(v19) = v19 | 8;
                v1->flags = v19;
                v1->pdsb->GetCurrentPosition((LPDWORD)&v52, (LPDWORD)&v50);
                if (v52 < (unsigned int)v2)
                    v20 = v56.dwBufferBytes + v52 - (_DWORD)v2;
                else
                    v20 = v52 - (_DWORD)v2;
                v21 = v20;
                v22 = v1->pdsb->Lock((DWORD)v2, v20, &v48, (LPDWORD)&a1, &v47, (LPDWORD)&num_bytes, 0);
                if (v22 == DSERR_BUFFERLOST)
                {
                    v1->pdsb->Restore();
                    v22 = v1->pdsb->Lock((DWORD)v2, v21, &v48, (LPDWORD)&a1, &v47, (LPDWORD)&num_bytes, 0);
                }
                if (!v22)
                {
                    v23 = a1;
                    if (a1)
                    {
                        v24 = v49;
                        if (v49 < (unsigned int)a1)
                            v23 = (Sound *)v49;
                        v25 = v1->file->read(v48, (int)v23);
                        v23 = a1;
                        v26 = v25;
                        v27 = v24 - v25;
                        v28 = v1->flags & 0x10;
                        v49 = v27;
                        if (v28)
                            v2 += v26;
                        else
                            v2 = &v2[(_DWORD)a1];
                        if ((unsigned int)v2 >= v56.dwBufferBytes)
                            v2 -= v56.dwBufferBytes;
                        if (v26 < (unsigned int)a1 && !v28)
                        {
                            memset((char *)v48 + v26, 0, (unsigned int)a1 - v26);
                            v23 = a1;
                            v27 = v49;
                        }
                        v51 = v26 == 0;
                        if (v47)
                        {
                            v29 = num_bytes;
                            if (v27 < num_bytes)
                                v29 = v27;
                            v30 = v1->file->read(v47, v29);
                            v31 = v1->flags & 0x10;
                            v49 = v27 - v30;
                            if (v31)
                                v2 += v30;
                            else
                                v2 += num_bytes;
                            if ((unsigned int)v2 >= v56.dwBufferBytes)
                                v2 -= v56.dwBufferBytes;
                            if (v30 < num_bytes && !v31)
                                memset((char *)v47 + v30, 0, num_bytes - v30);
                            v51 = v30 == 0;
                            v23 = a1;
                        }
                    }
                    v1->pdsb->Unlock(v48, (DWORD)v23, v47, num_bytes);
                }
                v32 = v1->flags;
                v18 = v51;
                LOBYTE_HEXRAYS(v32) = v32 & 0xF7;
                v1->flags = v32;
            }
            Sleep(0x64u);
        }
        v33 = v1->flags;
        if (!(v33 & 0x20))
        {
            if (v33 & 0x10)
            {
                v34 = v1->file;
                v18 = 0;
                v49 = v1->field_40;
                v51 = 0;
                v34->seek(0, 0);
                file_read_wav(v1->file, &v55, &v50);
            }
            else
            {
                v18 = 1;
                v51 = 1;
            }
        }
    } while (!v18);
    if (!(v1->flags & 0x20))
    {
        v35 = 0;
        do
        {
            v36 = v1->flags;
            if (v36 & 0x20)
                break;
            LOBYTE_HEXRAYS(v36) = v36 | 8;
            v1->flags = v36;
            v1->pdsb->GetCurrentPosition((LPDWORD)&v52, (LPDWORD)&v50);
            if (v52 < (unsigned int)v2)
                v37 = v56.dwBufferBytes + v52 - (_DWORD)v2;
            else
                v37 = v52 - (_DWORD)v2;
            if (!v1->pdsb->Lock((DWORD)v2, v37, &v48, (LPDWORD)&a1, &v47, (LPDWORD)&num_bytes, 0))
            {
                if (a1)
                {
                    memset(v48, 0, (unsigned int)a1);
                    v2 = &v2[(_DWORD)a1];
                    if ((unsigned int)v2 >= v56.dwBufferBytes)
                        v2 -= v56.dwBufferBytes;
                    v38 = (char *)v47;
                    if (v47)
                    {
                        v39 = num_bytes;
                        v40 = (unsigned int)num_bytes >> 2;
                        memset(v47, 0, 4 * ((unsigned int)num_bytes >> 2));
                        memset(&v38[4 * v40], 0, v39 & 3);
                        v2 += num_bytes;
                        if ((unsigned int)v2 >= v56.dwBufferBytes)
                            v2 -= v56.dwBufferBytes;
                    }
                }
                v1->pdsb->Unlock(v48, (DWORD)a1, v47, num_bytes);
            }
            v1->flags &= 0xFFFFFFF7;
            Sleep(0x64u);
            ++v35;
        } while (v35 < 50);
    }
LABEL_89:
    v1->pdsb->Stop();
    v1->file->close();
    v41 = v1->flags;
    v1->file = 0;
    LOBYTE_HEXRAYS(v41) = v41 | 0x40;
    v1->flags = v41;
    _endthread();
}

//----- (0043A2B0) --------------------------------------------------------
void sound_stop(int sound_id)
{
    Sound *v1; // esi@3
    int v2; // eax@7
    int v3; // eax@10

    if (sound_id && sound_initialized)
    {
        v1 = sound_list_free_pool;
        if (sound_list_free_pool->id == sound_id)
        {
        LABEL_6:
            if (v1->field_14 == -3)
            {
                v2 = v1->flags;
                LOBYTE_HEXRAYS(v2) = v2 | 0x20;
                v1->flags = v2;
            }
            else
            {
                v1->pdsb->Stop();
                v1->pdsb->SetCurrentPosition(0);
            }
            if (v1->field_18)
            {
                v3 = v1->flags;
                v1->field_18 = 0;
                LOBYTE_HEXRAYS(v3) = v3 & 0xFB;
                v1->flags = v3;
            }
        }
        else
        {
            while ((int *)v1 != &sound_list_end)
            {
                v1 = v1->next;
                if (v1->id == sound_id)
                    goto LABEL_6;
            }
        }
    }
}

//----- (0043A320) --------------------------------------------------------
void sound_free_sounds()
{
    Sound *v0; // ecx@1
    Sound *v1; // esi@3

    v0 = sound_list_free_pool;
    if (sound_list_free_pool)
    {
        do
        {
            if ((int *)v0 == &sound_list_end)
                break;
            v1 = v0->next;
            sound_list_remove(v0);
            v0 = v1;
        } while (v1);
    }
    _47C5C0_can_sound = 0;
    if (faction_slv)
    {
        free(faction_slv);
        faction_slv = 0;
    }
}

//----- (0043A370) --------------------------------------------------------
void _43A370_process_sound()
{
    Sound *v0; // esi@1
    IDirectSoundBuffer *v1; // eax@4
    Sound *v2; // edi@7
    IDirectSoundBuffer *v3; // eax@9
    int *v4; // edi@9
    int v5; // ebx@9
    int v6; // ebp@9
    int *v7; // ecx@9
    int v8; // eax@10
    IDirectSoundBuffer *v9; // ecx@15
    int v10; // eax@15
    IDirectSoundBuffer *v11; // eax@19
    int *v12; // edi@19
    int v13; // ebx@19
    int v14; // ebp@19
    int *v15; // ecx@19
    int v16; // eax@20
    IDirectSoundBuffer *v17; // ecx@25
    int v18; // eax@25
    int i; // [sp+1Ch] [bp-8h]@1
    int v20; // [sp+20h] [bp-4h]@9

    v0 = sound_list_free_pool;
    for (i = 0; (int *)v0 != &sound_list_end; v0 = v0->next)
    {
        if (!v0)
            break;
        if (!(v0->flags & 8))
        {
            v1 = v0->pdsb;
            if (v1)
            {
                v1->GetStatus((LPDWORD)&i);
                if (i & 1 || v0->flags & 4)
                {
                    if (v0->field_20)
                    {
                        v3 = v0->pdsb;
                        v4 = &v0->sound_volume_offset;
                        --v0->field_20;
                        v3->GetVolume((LPLONG)&v0->sound_volume_offset);
                        v5 = 100000;
                        v6 = 0;
                        v20 = 17;
                        v7 = sound_volumes;
                        while (1)
                        {
                            v8 = abs(*v7 - *v4);
                            if (!v8)
                                break;
                            if (v5 > v8)
                            {
                                v20 = v6;
                                v5 = v8;
                            }
                            ++v7;
                            ++v6;
                            if ((int)v7 >= (int)&sound_list_head)
                            {
                                v6 = v20;
                                break;
                            }
                        }
                        v9 = v0->pdsb;
                        v10 = v0->field_24 + v6;
                        *v4 = v10;
                        v9->SetVolume(sound_pans[v10]);
                        if (!v0->field_20 && v0->task)
                            script_trigger_event(0, EVT_MSG_sound_neg4, 0, v0->task);
                    }
                    if (v0->field_2C)
                    {
                        v11 = v0->pdsb;
                        v12 = &v0->sound_pan_offset;
                        --v0->field_2C;
                        v11->GetPan((LPLONG)&v0->sound_pan_offset);
                        v13 = 100000;
                        v14 = 0;
                        v20 = 16;
                        v15 = sound_pans;
                        while (1)
                        {
                            v16 = abs(*v15 - *v12);
                            if (!v16)
                                break;
                            if (v13 > v16)
                            {
                                v20 = v14;
                                v13 = v16;
                            }
                            ++v15;
                            ++v14;
                            if ((int)v15 >= (int)&sound_list)
                            {
                                v14 = v20;
                                break;
                            }
                        }
                        v17 = v0->pdsb;
                        v18 = v0->field_30 + v14;
                        *v12 = v18;
                        v17->SetPan(sound_pans[v18]);
                        if (!v0->field_2C)
                        {
                            if (v0->task)
                                script_trigger_event(0, EVT_MSG_sound_neg5, 0, v0->task);
                        }
                    }
                }
                else
                {
                    v2 = v0->next;
                    sound_list_remove(v0);
                    v0 = v2;
                }
            }
        }
    }
}

//----- (0043A510) --------------------------------------------------------
void sound_deinit()
{
    Sound *v0; // ecx@1
    Sound *v1; // esi@3

    v0 = sound_list_free_pool;                    // INLINED 43A320
    if (sound_list_free_pool)
    {
        do
        {
            if ((int *)v0 == &sound_list_end)
                break;
            v1 = v0->next;
            sound_list_remove(v0);
            v0 = v1;
        } while (v1);
    }
    _47C5C0_can_sound = 0;
    if (faction_slv)
    {
        free(faction_slv);
        faction_slv = 0;
    }
    if (sound_initialized == 1)
    {
        sound_initialized = 0;
        pds->Release();
        pds = 0;
        free(sound_list);
    }
}

//----- (0043A590) --------------------------------------------------------
bool file_read_wav(File *file, WAVEFORMATEX *out_data, unsigned int *a3)
{
    File *v3; // ebx@1
    unsigned int v4; // ebp@1
    __int16 *v5; // esi@8
    char v7[4]; // [sp+10h] [bp-Ch]@2
    unsigned int v8; // [sp+14h] [bp-8h]@3
    void *out_dataa; // [sp+18h] [bp-4h]@1

    v3 = file;
    v4 = 0;
    out_dataa = out_data;
    if (file)
    {
        file->read(v7, 4);
        if (!memcmp("RIFF", v7, 4u))
        {
            v3->read(&v8, 4);
            v3->read(v7, 4);
            if (!memcmp("WAVE", v7, 4u) && v3->read(v7, 4) == 4)
            {
                while (v4 < 0x20)
                {
                    if (!memcmp("fmt ", v7, 4u))
                    {
                        v3->read(&v8, 4);
                        if (v8 < 0xE)
                            return 0;
                        v5 = (__int16 *)out_dataa;
                        v3->read(out_dataa, 14);
                        if (*v5 == 1)
                            v3->read(v5 + 7, 2);
                        v4 = 0;
                        if (v3->read(v7, 4) == 4)
                        {
                            while (v4 < 0x20)
                            {
                                if (!memcmp("data", v7, 4u))
                                {
                                    v3->read(&v8, 4);
                                    if (a3)
                                        *a3 = v8;
                                    return 1;
                                }
                                ++v4;
                                if (v3->read(v7, 4) != 4)
                                    break;
                            }
                        }
                    }
                    ++v4;
                    if (v3->read(v7, 4) != 4)
                        return 0;
                }
            }
        }
    }
    return 0;
}

//----- (0043A710) --------------------------------------------------------
bool sound_stru_2_43A710(sound_stru_2 *a1, WAVEFORMATEX **a2, int *a3, unsigned int *out_buffer_size)
{
    char *v4; // eax@7
    unsigned int v5; // edi@9
    int v6; // ecx@10
    unsigned int v7; // esi@10
    WAVEFORMATEX *v8; // eax@10

    if (a2)
        *a2 = 0;
    if (a3)
        *a3 = 0;
    if (out_buffer_size)
        *out_buffer_size = 0;
    v4 = (char *)&a1->data;
    if (a1->riff_fourcc == 0x46464952 && a1->data_fourcc == 0x45564157)// 'RIFF' 'WAVE'
    {
        v5 = (unsigned int)&v4[a1->riff_chunk_size - 4];
        if ((unsigned int)v4 < v5)
        {
            while (1)
            {
                v6 = *(_DWORD *)v4;
                v7 = *((_DWORD *)v4 + 1);
                v8 = (WAVEFORMATEX *)(v4 + 8);
                if (v6 == 0x20746D66)                 // 'fmt '
                {
                    if (a2 && !*a2)
                    {
                        if (v7 < 0xE)
                            return 0;
                        *a2 = v8;
                        if ((!a3 || *a3) && (!out_buffer_size || *out_buffer_size))
                            return 1;
                    }
                }
                else if (v6 == 0x61746164 && (a3 && !*a3 || out_buffer_size && !*out_buffer_size))// 'data'
                {
                    if (a3)
                        *a3 = (int)v8;
                    if (out_buffer_size)
                        *out_buffer_size = v7;
                    if (!a2 || *a2)
                        return 1;
                }
                v4 = (char *)v8 + ((v7 + 1) & 0xFFFFFFFE);
                if ((unsigned int)v4 >= v5)
                    return 0;
            }
        }
    }
    return 0;
}

//----- (0043A800) --------------------------------------------------------
void sound_list_43A800(int a1)
{
    Sound *v1; // eax@3
    IDirectSoundBuffer *v2; // edx@6

    if (_47C5D4_sound_threaded_snd_id && sound_initialized)
    {
        v1 = sound_list_free_pool;
        if (sound_list_free_pool->id == _47C5D4_sound_threaded_snd_id)
        {
        LABEL_6:
            v2 = v1->pdsb;
            v1->sound_volume_offset = a1;
            if (v2)
                v2->SetVolume(sound_volumes[a1]);
        }
        else
        {
            while ((int *)v1 != &sound_list_end)
            {
                v1 = v1->next;
                if (v1->id == _47C5D4_sound_threaded_snd_id)
                    goto LABEL_6;
            }
        }
    }
}
// 47C398: using guessed type int sound_list_end;

//----- (0043A850) --------------------------------------------------------
void sound_list_remove(Sound *a1)
{
    Sound *v1; // esi@1
    int v2; // edx@5
    File *v3; // ecx@7
    IDirectSoundBuffer *v4; // eax@9
    Sound *v5; // eax@13
    Sound *v6; // eax@15

    v1 = a1;
    if (a1)
    {
        if (_47C5D4_sound_threaded_snd_id == a1->id)
            _47C5D4_sound_threaded_snd_id = 0;
        if (a1->field_14 == -3)
        {
            v2 = a1->flags | 0x20;
            a1->flags = v2;
            if (!(v2 & 0x40))
            {
                do
                    Sleep(0x14u);
                while (!(v1->flags & 0x40));
            }
            v3 = v1->file;
            if (v3)
            {
                v3->close();
                v1->file = 0;
            }
        }
        v4 = v1->pdsb;
        if (v4)
        {
            v4->Stop();
            v1->pdsb->Release();
            v1->pdsb = 0;
        }
        if (v1->task)
            script_trigger_event(0, EVT_MSG_sound_neg3, 0, v1->task);
        v5 = v1->next;
        v1->task = 0;
        if (v5)
            v5->prev = v1->prev;
        v6 = v1->prev;
        if (v6)
            v6->next = v1->next;
        v1->next = sound_list_head;
        sound_list_head = v1;
    }
}