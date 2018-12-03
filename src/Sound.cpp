#include <dsound.h>
#include <process.h>    // _beginthread, _endthread
#include <list>
#include <thread>

#include "src/Sound.h"
#include "src/kknd.h"
#include "src/Random.h"
#include "src/ScriptEvent.h"
#include "src/_unsorted_functions.h"
#include "src/Engine/Entity.h"

#include "src/Infrastructure/PlatformSpecific/OsTools.h"

#pragma comment(lib, "Dsound.lib") // DirectSoundCreate


/* 262 */
struct Sound
{
    int id = 0;
    IDirectSoundBuffer *pdsb = nullptr;
    Script *task = nullptr;
    File *file = nullptr;
    void *hthread_depricated; //int hthread = 0;
    int field_14 = 0;
    int field_18 = 0;
    int sound_volume_offset = 0;
    int field_20 = 0;
    int field_24 = 0;
    int sound_pan_offset = 0;
    int field_2C = 0;
    int field_30 = 0;
    int flags = 0;
    int field_40 = 0;
    char filename[32] = { 0 };
    char gap64[42] = { 0 };
    char field_8E[100] = { 0 };
    char field_F2[80] = { 0 };
    char field_142 = '\0';
    char field_143 = '\0';
    char field_144 = '\0';
    char field_145 = '\0';
    char field_146 = '\0';
    char field_147 = '\0';
};

/* 428 */
struct sound_stru_2
{
    int riff_fourcc = 0;
    int riff_chunk_size = 0;
    int data_fourcc = 0;
    int data = 0;
};


DSBUFFERDESC video_477DE4_dsb_desc; // weak
IDirectSoundBuffer *video_477DE4_dsb;
LPDIRECTSOUND pds; // idb

std::list<std::shared_ptr<Sound>> sound_list_free_pool;
int sound_list_last_id; // weak
int _47C5D4_sound_threaded_snd_id; // idb
sound_stru_2 **_47C4E0_sounds;
bool sound_initialized = false;
int _47C4E8_num_sounds; // weak
int sound_volumes[17];
int sound_pans[17];
int _47C5C0_can_sound; // weak
void *faction_slv; // idb
int dword_47C5D0; // weak


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
void _439C10_sound_thread(std::shared_ptr<Sound> sound); // idb
void sound_list_remove(std::shared_ptr<Sound> snd);
void sound_cleanup(std::shared_ptr<Sound> snd);


void sound_start_video_playback()
{

}

void sound_end_video_playback()
{

}

bool sound_video_get_position(int *play, int *write)
{
    return S_OK == video_477DE4_dsb->GetCurrentPosition(
        (LPDWORD)play,
        (LPDWORD)write
    );
}

void sound_video_stop()
{
    video_477DE4_dsb->Stop();
    video_477DE4_dsb->Release();
}

//----- (00439440) --------------------------------------------------------
// Initialize game sound
bool sound_initialize()
{
    //init sound volumes & sound pans
    for (int i = 0; i < 17; ++i)
    {
        sound_volumes[i] = sound_pans[i] = 1000.0 * 0.69314718055994528623 * log2((double)(i + 1) * 0.05882352941176471);
    }

    // init globals
    sound_initialized = 0;
    sound_list_last_id = 0;

    // init sound engine
    if (DirectSoundCreate(0, &pds, 0))
        return 1;

    // set window cooporative level
    HWND hwnd = (HWND)gWindow->GetHwnd();
    if (pds->SetCooperativeLevel(hwnd, 1))
    {
        pds->Release();
        pds = 0;
        return 1;
    }

    //sound initialation done
    sound_initialized = 1;
    return 1;
}

//----- (00439610) --------------------------------------------------------
// Load game sound file
bool LVL_LoadSlv(const char *slv_filename)
{
    DataHunk *data_hunk; // eax@2
    DataSectionOffset *data_section_offset; // eax@4
    sound_stru_2 **sound_structure_1; // edx@4
    char *offset_pointer; // esi@4
    int offset_pointer_data; // ecx@7
    int num_sounds; // ecx@9
    sound_stru_2 **sound_structure_2; // eax@10
    sound_stru_2 *sound_structure_3; // edx@11

    _47C5C0_can_sound = 0;
    if (sound_initialized)
    {
        data_hunk = LVL_LoadLevel(slv_filename);
        faction_slv = data_hunk;
        if (data_hunk || (data_hunk = LVL_LoadLevel("sound.slv"), (faction_slv = data_hunk) != 0))
        {
            data_section_offset = data_hunk->section_table;
            sound_structure_1 = 0;
            _47C4E0_sounds = 0;
            offset_pointer = (char *)&data_section_offset->ptr;
            if (data_section_offset->ptr)
            {
                do
                {
                    if (!strncmp("SOUN", data_section_offset->name, 4u))
                        _47C4E0_sounds = *(sound_stru_2 ***)offset_pointer;
                    offset_pointer_data = *((_DWORD *)offset_pointer + 2);
                    offset_pointer += 8;
                    data_section_offset = (DataSectionOffset *)(offset_pointer - 4);
                } while (offset_pointer_data);
                sound_structure_1 = _47C4E0_sounds;
            }
            num_sounds = 0;
            if (*sound_structure_1)
            {
                sound_structure_2 = sound_structure_1;
                do
                {
                    sound_structure_3 = sound_structure_2[1];
                    ++sound_structure_2;
                    ++num_sounds;
                } while (sound_structure_3);
            }
            _47C4E8_num_sounds = num_sounds;
            _47C5C0_can_sound = 1;
        }
    }
    return 1;
}

// Get unit sound ID
SOUND_ID get_unit_seletion_sound(UNIT_ID unit_id)
{
    switch (unit_id)
    {
    case UNIT_STATS_GORT:
    case UNIT_STATS_PLASMA_TANK:
    case UNIT_STATS_SENTINEL_DROID:
        return _4689A8_sound_ids[rnd_capped(2)];
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
            return _468998_sound_ids[rnd_capped(4)];
        }
        else
        {
            return _468988_sound_ids[rnd_capped(4)];
        }
        break;
    }
}

// Get unit confirmation sound
SOUND_ID get_unit_move_confirmation_sound(UNIT_ID unit_id, bool experienced)
{
    if (is_21st_century(unit_id))
    {
        return _4689C0_sound_ids[rnd_capped(22)];
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
                return _468A48_sound_ids[rnd_capped(2)];
            }
            else
            {
                return _468A28_sound_ids[rnd_capped(3)];
            }
        }
        else
        {
            if (experienced)
            {
                return _468A50_sound_ids[rnd_capped(2)];
            }
            else
            {
                return _468A38_sound_ids[rnd_capped(3)];
            }
        }
    }
}

// Get unit confirmation sound
SOUND_ID get_unit_attack_confirmation_sound(UNIT_ID unit_id, bool experienced)
{
    if (is_21st_century(unit_id))
    {
        return _4689B0_sound_ids[rnd_capped(3)];
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
                if (rnd_capped(2))
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
                if (rnd_capped(2))
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

// Get unit ready sound ID
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
        if (is_player_faction_evolved())
        {
            return _468998_sound_ids[rnd_capped(4)];
        }
        else
        {
            return _468988_sound_ids[rnd_capped(4)];
        }
    }
    }
}

//----- (004396C0) --------------------------------------------------------
// Play unit sound
int sound_play(enum SOUND_ID sound_id, int sound_flags, int volume_offset, int pan_offset, Script *script)
{
    int result; // eax@7
    sound_stru_2 *sound_structure_1; // esi@10
    std::shared_ptr<Sound> sound; // ebx@12
    IDirectSoundBuffer **sound_buffer_1; // edi@20
    IDirectSoundBuffer *sound_buffer_2; // eax@21
    bool v13; // zf@21
    unsigned int v14; // ecx@25
    void *v15; // eax@27
    DSBUFFERDESC buffer_desc; // [sp+Ch] [bp-30h]@4
    int flags; // [sp+20h] [bp-1Ch]@1
    IDirectSoundBuffer *sound_buffer_3; // [sp+24h] [bp-18h]@21
    void *v26; // [sp+28h] [bp-14h]@24
    char *v27; // [sp+2Ch] [bp-10h]@24
    unsigned int v28; // [sp+30h] [bp-Ch]@24
    const void *v29; // [sp+34h] [bp-8h]@21
    int a3a; // [sp+38h] [bp-4h]@4

    flags = sound_flags;

    buffer_desc.dwFlags = 0;
    buffer_desc.dwSize = 0;
    buffer_desc.dwBufferBytes = 0;
    a3a = 0;
    buffer_desc.dwReserved = 0;
    buffer_desc.lpwfxFormat = 0;
    if (volume_offset)
    {
        if (_47C5C0_can_sound && sound_id < _47C4E8_num_sounds)
        {
            sound_structure_1 = _47C4E0_sounds[sound_id];
            if (sound_structure_1 != faction_slv && sound_structure_1)
            {
                sound = std::make_shared<Sound>();
                if (sound)
                {
                    if (!++sound_list_last_id)
                    {
                        sound_list_last_id = 1;
                    }
                    sound->id = sound_list_last_id;
                    sound_list_free_pool.push_front(sound);

                    sound->task = script;
                    sound->sound_volume_offset = volume_offset;
                    sound->sound_pan_offset = pan_offset;
                    sound->field_14 = -2;
                    sound_stru_2_43A710(sound_structure_1, &buffer_desc.lpwfxFormat, &a3a, (unsigned int *)&buffer_desc.dwBufferBytes);
                    sound_buffer_1 = &sound->pdsb;
                    buffer_desc.dwSize = 20;
                    buffer_desc.dwFlags = 232;
                    if (pds->CreateSoundBuffer(&buffer_desc, &sound->pdsb, 0))
                    {
                        result = 0;
                    }
                    else
                    {
                        sound_buffer_2 = *sound_buffer_1;
                        v13 = *sound_buffer_1 == 0;
                        v29 = (const void *)a3a;
                        sound_buffer_3 = sound_buffer_2;
                        if (v13
                            || !a3a
                            || !buffer_desc.dwBufferBytes
                            || sound_buffer_2->Lock(0, buffer_desc.dwBufferBytes, &v26, (LPDWORD)&script, (LPVOID *)&v27, (LPDWORD)&v28, 0))
                        {
                            (*sound_buffer_1)->Release();
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
                            sound_buffer_3->Unlock(v26, (DWORD)script, v27, v14);
                            sound->pdsb->SetPan(sound_pans[pan_offset]);
                            sound->pdsb->SetVolume(sound_volumes[volume_offset]);
                            v15 = (void *)dword_47C5D0;
                            if (dword_47C5D0)
                                ++sound->field_18;
                            else
                                v15 = (void *)sound->pdsb->Play(0, 0, flags);

                            result = sound->id;
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
// Play background music (on new thread)
int sound_play_threaded(const char *name_, int a2, int sound_volume_offset, int sound_pan_offset, Script *task)
{
    int result; // eax@2
    std::shared_ptr<Sound> sound; // ebx@3
    int flags; // esi@11
    int flags_2; // eax@11
    const char *file_name_2; // edi@13
    int thread_ptr; // eax@13
    int sound_id; // ecx@13
    void *flags_3; // eax@13
    const char *file_name; // [sp+Ch] [bp-4h]@1

    char name[1024];
    sprintf(
        name,
        "%s\\LEVELS\\%s",
        OsGetCurrentDirectory().c_str(),
        name_
    );

    file_name = name;
    if (sound_initialized)
    {
        sound = std::make_shared<Sound>();
        if (sound)
        {
            if (!++sound_list_last_id)
            {
                sound_list_last_id = 1;
            }
            sound->id = sound_list_last_id;
            sound_list_free_pool.push_front(sound);

            flags = sound->flags | 8;
            sound->task = task;
            sound->field_14 = -3;
            sound->sound_volume_offset = sound_volume_offset;
            sound->flags = flags;
            flags_2 = flags;
            if (a2 == 1)
            {
                LOBYTE_HEXRAYS(flags_2) = flags | 0x10;
                sound->flags = flags_2;
            }
            file_name_2 = file_name;
            sound->sound_pan_offset = sound_pan_offset;
            strcpy(sound->filename, file_name_2);

            //start new thread
            std::thread sound_worker(_439C10_sound_thread, sound); 
            sound_worker.detach();

            sound_id = sound->id;
            //sound->hthread = thread_ptr;
            _47C5D4_sound_threaded_snd_id = sound_id;
            flags_3 = (void *)sound->flags;
            LOBYTE_HEXRAYS(flags_3) = (unsigned __int8)flags_3 | 8;
            sound->flags = (int)flags_3;

            result = sound->id;
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


//----- (00439C10) --------------------------------------------------------
// Background sound thread
void _439C10_sound_thread(std::shared_ptr<Sound> sound)
{
    char *v2; // ebp@1
    const char *v3; // ecx@1
    File *v4; // ecx@5
    IDirectSoundBuffer **sound_buffer; // ebx@7
    int v6; // eax@8
    DWORD v7; // edi@9
    int v8; // eax@9
    Sound *sound_2; // ecx@12
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
    DWORD v37; // eax@78
    char *v38; // edi@84
    char v39; // dl@85
    unsigned int v40; // ecx@85
    int v41; // eax@90
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

    auto a1 = sound.get();

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
    if (true && *v3)
        sound->file = File::open(v3);
    else
        a1->file = 0;
    v4 = sound->file;
    if (!v4 || !file_read_wav(v4, &out_data, &a3))
    {
        sound->file->close();
        sound->flags = sound->flags & 0xFFFFFFF7 | 0x40;
        return;
    }
    sound->field_40 = a3;
    sound_buffer = &sound->pdsb;
    v57.dwBufferBytes = 3 * out_data.nAvgBytesPerSec;
    v57.lpwfxFormat = &out_data;
    v57.dwSize = 20;
    v57.dwFlags = 232;
    if (pds->CreateSoundBuffer(&v57, &sound->pdsb, 0))
    {
        sound->file->close();
        sound->flags = sound->flags & 0xFFFFFFF7 | 0x40;
        return;
    }
    (*sound_buffer)->SetPan(sound_pans[sound->sound_pan_offset]);
    (*sound_buffer)->SetVolume(sound_volumes[sound->sound_volume_offset]);
    v6 = sound->flags;
    LOBYTE_HEXRAYS(v6) = v6 | 8;
    v56.dwSize = 20;
    sound->flags = v6;
    (*sound_buffer)->GetCaps(&v56);
    (*sound_buffer)->GetCurrentPosition((LPDWORD)&v52, (LPDWORD)&v50);
    v49 = sound->field_40;
    if (!v52)
    {
        v7 = v56.dwBufferBytes - v50;
        v8 = (*sound_buffer)->Lock(v50, v56.dwBufferBytes - v50, &v48, (LPDWORD)&a1, &v47, (LPDWORD)&num_bytes, 0);
        if (v8 == DSERR_BUFFERLOST)
        {
            (*sound_buffer)->Restore();
            v8 = (*sound_buffer)->Lock(v50, v7, &v48, (LPDWORD)&a1, &v47, (LPDWORD)&num_bytes, 0);
        }
        if (v8)
        {
            v17 = sound->flags;
            LOBYTE_HEXRAYS(v17) = v17 | 0x20;
            sound->flags = v17;
        }
        else
        {
            sound_2 = a1;
            if (a1)
            {
                v10 = v49;
                if (v49 < (unsigned int)a1)
                    sound_2 = (Sound *)v49;
                v11 = sound->file->read(v48, (int)sound_2);
                sound_2 = a1;
                v12 = v10 - v11;
                v49 = v12;
                v2 = (char *)a1 + v50;
                if ((unsigned int)a1 + v50 >= v56.dwBufferBytes)
                    v2 -= v56.dwBufferBytes;
                if (v11 < (unsigned int)a1)
                {
                    memset((char *)v48 + v11, 0, (unsigned int)a1 - v11);
                    v13 = sound->flags;
                    sound_2 = a1;
                    v12 = v49;
                    LOBYTE_HEXRAYS(v13) = v13 | 0x20;
                    sound->flags = v13;
                }
                if (v47)
                {
                    v14 = num_bytes;
                    if (v12 < num_bytes)
                        v14 = v12;
                    v15 = sound->file->read(v47, v14);
                    v49 = v12 - v15;
                    v2 = (char *)(v50 + num_bytes);
                    if (v50 + num_bytes >= v56.dwBufferBytes)
                        v2 -= v56.dwBufferBytes;
                    if (v15 < num_bytes)
                    {
                        memset((char *)v47 + v15, 0, num_bytes - v15);
                        v16 = sound->flags;
                        LOBYTE_HEXRAYS(v16) = v16 | 0x20;
                        sound->flags = v16;
                    }
                    sound_2 = a1;
                }
            }
            (*sound_buffer)->Unlock(v48, (DWORD)sound_2, v47, num_bytes);
            if (dword_47C5D0)
                ++sound->field_18;
            else
                (*sound_buffer)->Play(0, 0, 1);
            sound->flags &= 0xFFFFFFF7;
            Sleep(0xAu);
        }
    }
    v18 = v51;
    do
    {
        if (sound->flags & 0x20)
        {
            sound->pdsb->Stop();
            sound->file->close();
            v41 = sound->flags;
            sound->file = 0;
            LOBYTE_HEXRAYS(v41) = v41 | 0x40;
            sound->flags = v41;
            return;
        }
        while (!v18)
        {
            v19 = sound->flags;
            if (v19 & 0x20)
                break;
            if (!(v19 & 4))
            {
                LOBYTE_HEXRAYS(v19) = v19 | 8;
                sound->flags = v19;
                sound->pdsb->GetCurrentPosition((LPDWORD)&v52, (LPDWORD)&v50);
                if (v52 < (unsigned int)v2)
                    v20 = v56.dwBufferBytes + v52 - (_DWORD)v2;
                else
                    v20 = v52 - (_DWORD)v2;
                v21 = v20;
                v22 = sound->pdsb->Lock((DWORD)v2, v20, &v48, (LPDWORD)&a1, &v47, (LPDWORD)&num_bytes, 0);
                if (v22 == DSERR_BUFFERLOST)
                {
                    sound->pdsb->Restore();
                    v22 = sound->pdsb->Lock((DWORD)v2, v21, &v48, (LPDWORD)&a1, &v47, (LPDWORD)&num_bytes, 0);
                }
                if (!v22)
                {
                    v23 = a1;
                    if (a1)
                    {
                        v24 = v49;
                        if (v49 < (unsigned int)a1)
                            v23 = (Sound *)v49;
                        v25 = sound->file->read(v48, (int)v23);
                        v23 = a1;
                        v26 = v25;
                        v27 = v24 - v25;
                        v28 = sound->flags & 0x10;
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
                            v30 = sound->file->read(v47, v29);
                            v31 = sound->flags & 0x10;
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
                    sound->pdsb->Unlock(v48, (DWORD)v23, v47, num_bytes);
                }
                v32 = sound->flags;
                v18 = v51;
                LOBYTE_HEXRAYS(v32) = v32 & 0xF7;
                sound->flags = v32;
            }
            Sleep(0x64u);
        }
        v33 = sound->flags;
        if (!(v33 & 0x20))
        {
            if (v33 & 0x10)
            {
                v34 = sound->file;
                v18 = 0;
                v49 = sound->field_40;
                v51 = 0;
                v34->seek(0, 0);
                file_read_wav(sound->file, &v55, &v50);
            }
            else
            {
                v18 = 1;
                v51 = 1;
            }
        }
    } while (!v18);


    if (!(sound->flags & 0x20))
    {
        auto v35 = 0;
        do
        {
            auto v36 = sound->flags;
            if (v36 & 0x20)
                break;
            LOBYTE_HEXRAYS(v36) = v36 | 8;
            sound->flags = v36;
            sound->pdsb->GetCurrentPosition((LPDWORD)&v52, (LPDWORD)&v50);
            if (v52 < (unsigned int)v2)
                v37 = v56.dwBufferBytes + v52 - (_DWORD)v2;
            else
                v37 = v52 - (_DWORD)v2;
            if (!sound->pdsb->Lock((DWORD)v2, v37, &v48, (LPDWORD)&a1, &v47, (LPDWORD)&num_bytes, 0))
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
                sound->pdsb->Unlock(v48, (DWORD)a1, v47, num_bytes);
            }
            sound->flags &= 0xFFFFFFF7;
            Sleep(0x64u);
            ++v35;
        } while (v35 < 50);
    }

    sound->pdsb->Stop();
    sound->file->close();
    v41 = sound->flags;
    sound->file = 0;
    LOBYTE_HEXRAYS(v41) = v41 | 0x40;
    sound->flags = v41;
    return;
}


//----- (0043A800) --------------------------------------------------------
// Set background sound volume
void sound_threaded_set_volume(int sound_volume)
{
    std::shared_ptr<Sound>sound; // eax@3
    IDirectSoundBuffer *sound_buffer; // edx@6

    if (_47C5D4_sound_threaded_snd_id && sound_initialized)
    {
        if (!sound_list_free_pool.empty())
        {
            //find sound by id - look only list head
            sound = *sound_list_free_pool.begin();
            if (sound->id == _47C5D4_sound_threaded_snd_id)
            {
                sound_buffer = sound->pdsb;
                sound->sound_volume_offset = sound_volume;
                if (sound_buffer)
                    sound_buffer->SetVolume(sound_volumes[sound_volume]); //set volume
            }
            else  //find sound by id - look through list
            {
                for (auto sound : sound_list_free_pool)
                {
                    if (sound->id == _47C5D4_sound_threaded_snd_id)
                    {
                        sound_buffer = sound->pdsb;
                        sound->sound_volume_offset = sound_volume;
                        if (sound_buffer)
                            sound_buffer->SetVolume(sound_volumes[sound_volume]); //set volume
                    }
                }
            }
        }
    }
}
// 47C398: using guessed type int sound_list_free_pool_end;


//----- (0043A2B0) --------------------------------------------------------
// Stop music playback
void sound_stop(int sound_id)
{
    std::shared_ptr<Sound> sound; // esi@3
    int flags; // eax@7
    int flags2; // eax@10

    if (sound_id && sound_initialized)
    {
        if (!sound_list_free_pool.empty())
        {
            //find sound by id - look only list head
            sound = *sound_list_free_pool.begin();
            if (sound->id == sound_id)
            {
                if (sound->field_14 == -3)
                {
                    flags = sound->flags;
                    LOBYTE_HEXRAYS(flags) = flags | 0x20;
                    sound->flags = flags;
                }
                else
                {
                    sound->pdsb->Stop();
                    sound->pdsb->SetCurrentPosition(0);
                }
                if (sound->field_18)
                {
                    flags2 = sound->flags;
                    sound->field_18 = 0;
                    LOBYTE_HEXRAYS(flags2) = flags2 & 0xFB;
                    sound->flags = flags2;
                }
            }
            else //find sound by id - look through list
            {
                for (auto sound : sound_list_free_pool)
                {
                    if (sound->id == sound_id)
                    {
                        if (sound->field_14 == -3)
                        {
                            flags = sound->flags;
                            LOBYTE_HEXRAYS(flags) = flags | 0x20;
                            sound->flags = flags;
                        }
                        else
                        {
                            sound->pdsb->Stop();
                            sound->pdsb->SetCurrentPosition(0);
                        }
                        if (sound->field_18)
                        {
                            flags2 = sound->flags;
                            sound->field_18 = 0;
                            LOBYTE_HEXRAYS(flags2) = flags2 & 0xFB;
                            sound->flags = flags2;
                        }
                    }
                }
            }
        }
    }
}


//----- (0043A370) --------------------------------------------------------
// Process sound
void _43A370_process_sound()
{
    IDirectSoundBuffer *sound_buffer_1; // eax@4
    IDirectSoundBuffer *sound_buffer_2; // eax@9
    int *sound_volume_offset_ptr; // edi@9
    int v5; // ebx@9
    int loop_counter_1; // ebp@9
    int *sound_volume_ptr; // ecx@9
    int v8; // eax@10
    IDirectSoundBuffer *sound_buffer_3; // ecx@15
    int v10; // eax@15
    IDirectSoundBuffer *sound_buffer_4; // eax@19
    int *sound_pan_offset_ptr; // edi@19
    int v13; // ebx@19
    int loop_counter_2; // ebp@19 //loop_counter_2
    int *sound_pans_ptr; // ecx@19
    int v16; // eax@20
    IDirectSoundBuffer *sound_buffer_5; // ecx@25
    int v18; // eax@25
    int i; // [sp+1Ch] [bp-8h]@1
    int v20; // [sp+20h] [bp-4h]@9
    std::list<std::shared_ptr<Sound>> remove_list;

    for (auto sound : sound_list_free_pool)
    {
        if (!sound)
            break;
        if (!(sound->flags & 8))
        {
            sound_buffer_1 = sound->pdsb;
            if (sound_buffer_1)
            {
                sound_buffer_1->GetStatus((LPDWORD)&i);
                if (i & 1 || sound->flags & 4)
                {
                    if (sound->field_20)
                    {
                        sound_buffer_2 = sound->pdsb;
                        sound_volume_offset_ptr = &sound->sound_volume_offset;
                        --sound->field_20;
                        sound_buffer_2->GetVolume((LPLONG)&sound->sound_volume_offset);
                        v5 = 100000;
                        loop_counter_1 = 0;
                        v20 = 17;
                        sound_volume_ptr = sound_volumes;
                        while (1)
                        {
                            v8 = abs(*sound_volume_ptr - *sound_volume_offset_ptr);
                            if (!v8)
                                break;
                            if (v5 > v8)
                            {
                                v20 = loop_counter_1;
                                v5 = v8;
                            }
                            ++sound_volume_ptr;
                            ++loop_counter_1;
                        }
                        sound_buffer_3 = sound->pdsb;
                        v10 = sound->field_24 + loop_counter_1;
                        *sound_volume_offset_ptr = v10;
                        sound_buffer_3->SetVolume(sound_pans[v10]);
                        if (!sound->field_20 && sound->task)
                            script_trigger_event(0, EVT_MSG_sound_neg4, 0, sound->task);
                    }
                    if (sound->field_2C)
                    {
                        sound_buffer_4 = sound->pdsb;
                        sound_pan_offset_ptr = &sound->sound_pan_offset;
                        --sound->field_2C;
                        sound_buffer_4->GetPan((LPLONG)&sound->sound_pan_offset);
                        v13 = 100000;
                        loop_counter_2 = 0;
                        v20 = 16;
                        sound_pans_ptr = sound_pans;
                        while (1)
                        {
                            v16 = abs(*sound_pans_ptr - *sound_pan_offset_ptr);
                            if (!v16)
                                break;
                            if (v13 > v16)
                            {
                                v20 = loop_counter_2;
                                v13 = v16;
                            }
                            ++sound_pans_ptr;
                            ++loop_counter_2;
                        }
                        sound_buffer_5 = sound->pdsb;
                        v18 = sound->field_30 + loop_counter_2;
                        *sound_pan_offset_ptr = v18;
                        sound_buffer_5->SetPan(sound_pans[v18]);
                        if (!sound->field_2C)
                        {
                            if (sound->task)
                                script_trigger_event(0, EVT_MSG_sound_neg5, 0, sound->task);
                        }
                    }
                }
                else
                {
                    // add to remove list
                    remove_list.push_front(sound);
                }
            }
        }
    }

    //remove from sound_list_free_pool & clear remove_list
    for (auto sound : remove_list) {
        sound_list_free_pool.remove(sound);
    }
    remove_list.clear();
}


//----- (0043A320) --------------------------------------------------------
void sound_free_sounds()
{
    for (auto sound : sound_list_free_pool)
    {
        sound_cleanup(sound);
    }
    sound_list_free_pool.clear();

    _47C5C0_can_sound = 0;
    if (faction_slv)
    {
        free(faction_slv);
        faction_slv = 0;
    }
}


//----- (0043A850) --------------------------------------------------------
void sound_list_remove(std::shared_ptr<Sound> snd)
{
    std::shared_ptr<Sound> sound; // esi@1

    sound = snd;
    if (snd)
    {
        sound_cleanup(sound);
        sound_list_free_pool.remove(sound);
    }
}

void sound_cleanup(std::shared_ptr<Sound> snd)
{
    std::shared_ptr<Sound> sound; // esi@1
    int flags; // edx@5
    File *sound_file; // ecx@7
    IDirectSoundBuffer *sound_buffer; // eax@9

    sound = snd;
    if (snd)
    {
        if (_47C5D4_sound_threaded_snd_id == snd->id)
            _47C5D4_sound_threaded_snd_id = 0;
        if (snd->field_14 == -3)
        {
            flags = snd->flags | 0x20;
            snd->flags = flags;
            if (!(flags & 0x40))
            {
                do
                    Sleep(0x14u);
                while (!(sound->flags & 0x40));
            }
            sound_file = sound->file;
            if (sound_file)
            {
                sound_file->close();
                sound->file = 0;
            }
        }
        sound_buffer = sound->pdsb;
        if (sound_buffer)
        {
            sound_buffer->Stop();
            sound->pdsb->Release();
            sound->pdsb = 0;
        }
        if (sound->task)
            script_trigger_event(0, EVT_MSG_sound_neg3, 0, sound->task);
        sound->task = 0;
    }
}

//----- (0043A510) --------------------------------------------------------
void sound_deinit()
{
    for (auto sound : sound_list_free_pool)
    {
        sound_cleanup(sound);
    }
    sound_list_free_pool.clear();

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
    }
}


//----- (0043A590) --------------------------------------------------------
bool file_read_wav(File *file, WAVEFORMATEX *out_data, unsigned int *a3)
{
    File *sound_file; // ebx@1
    unsigned int v4; // ebp@1
    __int16 *v5; // esi@8
    char v7[4]; // [sp+10h] [bp-Ch]@2
    unsigned int v8; // [sp+14h] [bp-8h]@3
    void *out_data_2; // [sp+18h] [bp-4h]@1

    sound_file = file;
    v4 = 0;
    out_data_2 = out_data;
    if (file)
    {
        file->read(v7, 4);
        if (!memcmp("RIFF", v7, 4u))
        {
            sound_file->read(&v8, 4);
            sound_file->read(v7, 4);
            if (!memcmp("WAVE", v7, 4u) && sound_file->read(v7, 4) == 4)
            {
                while (v4 < 0x20)
                {
                    if (!memcmp("fmt ", v7, 4u))
                    {
                        sound_file->read(&v8, 4);
                        if (v8 < 0xE)
                            return 0;
                        v5 = (__int16 *)out_data_2;
                        sound_file->read(out_data_2, 14);
                        if (*v5 == 1)
                            sound_file->read(v5 + 7, 2);
                        v4 = 0;
                        if (sound_file->read(v7, 4) == 4)
                        {
                            while (v4 < 0x20)
                            {
                                if (!memcmp("data", v7, 4u))
                                {
                                    sound_file->read(&v8, 4);
                                    if (a3)
                                        *a3 = v8;
                                    return 1;
                                }
                                ++v4;
                                if (sound_file->read(v7, 4) != 4)
                                    break;
                            }
                        }
                    }
                    ++v4;
                    if (sound_file->read(v7, 4) != 4)
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