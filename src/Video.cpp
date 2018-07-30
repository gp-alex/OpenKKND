#include <Windows.h>
#include <mmeapi.h>
#include <dsound.h>

#include "src/Video.h"

#include "src/_unsorted_data.h"
#include "src/Render.h"
#include "src/Sound.h"

DetailedDrawHandler_VideoPlayer stru_477D90; // weak
int dword_477DB8; // weak
int dword_477DBC; // weak
DrawJob *video_477DC0;
int video_477DC4_current_sound_position; // weak
int dword_477DC8; // weak
VideoFile *video;
int video_477DEC_is_sound_playing; // weak
int video_477DF0; // weak
int dword_477DF4; // weak
char video_477DF8_subtitles[756];
int video_4780EC; // weak
int video_4780F0; // weak
int video_4780F4; // weak
RenderString *video_4780F8_subtitles;
VideoFileFrame *video_47F434_frame;
DetailedDrawHandler_VideoPlayer _477948_video_draw_details;
int _477970_video_header_field_6; // weak
int _477974_video_header_field_8; // weak
DrawJob *video_477978_draw_job;
_UNKNOWN video_477DE4_dsb_waveformatex; // weak
_UNKNOWN unk_477982; // weak
__int64 qword_477984; // weak
_UNKNOWN unk_47798C; // weak
_UNKNOWN unk_47798E; // weak
int dword_477940; // weak
int dword_477944; // weak
Palette _477990_video_palette; // idb


extern IDirectSound *pds;
extern DSBUFFERDESC video_477DE4_dsb_desc; // weak
extern IDirectSoundBuffer *video_477DE4_dsb;


//----- (0040CAE0) --------------------------------------------------------
int VIDEO_IsAllocated()
{
    int result; // eax@2

    if (video)
    {
        result = 0;
    }
    else
    {
        video_477DF0 = 0;
        result = 1;
    }
    return result;
}

//----- (0040CB00) --------------------------------------------------------
int VIDEO_ReadAndAllocDrawJob(const char *a1, int x, int y, int z_index)
{
    int v4; // esi@1
    int result; // eax@1
    DrawJob *v6; // eax@2

    v4 = x;
    result = (int)VIDEO_ReadFile(a1);
    video = (VideoFile *)result;
    if (result)
    {
        v6 = draw_list_add(0, 0);
        video_477978_draw_job = v6;
        if (v6)
        {
            v6->job_details.x = v4;
            video_477978_draw_job->job_details.y = y;
            video_477978_draw_job->job_details.z_index = z_index;
            video_477978_draw_job->job_details.image = &_477948_video_draw_details;
            _477970_video_header_field_6 = video->header.field_6;
            _477974_video_header_field_8 = video->header.field_8;
            _477948_video_draw_details.width = video->header.width;
            result = 1;
            _477948_video_draw_details.height = video->header.height;
            _477948_video_draw_details.handler = render_video_draw_handler;
            _477948_video_draw_details.field_14 = 1;
            video_477DC0 = 0;
            video_477DF0 = 0;
        }
        else
        {
            VIDEO_Clean(video);
            video = 0;
            result = 0;
        }
    }
    return result;
}

//----- (0040CBD0) --------------------------------------------------------
int VIDEO_DoFrame()
{
    VideoFile *v0; // ecx@1
    VideoFile *v1; // edi@4
    signed __int64 v2; // rax@5
    int v3; // ecx@6
    int v4; // esi@6
    int v5; // eax@9
    int result; // eax@19
    int v7; // eax@20
    VideoFile *v8; // ebx@21
    DWORD v9; // eax@24
    DWORD v10; // ecx@26
    DWORD v11; // ecx@33
    char *v12; // eax@35
    DWORD v13; // eax@41
    VideoFile *v14; // edi@45
    signed __int64 v15; // rax@46
    int v16; // ecx@47
    int v17; // esi@47
    int v18; // eax@50
    VideoFile *v19; // eax@57
    int v20; // edx@60
    int v21; // ecx@60
    int v22; // esi@60
    char v23; // dl@61
    int v24; // ecx@64
    unsigned int v25; // [sp+68h] [bp-10h]@23
    void *v26; // [sp+6Ch] [bp-Ch]@23
    char *v27; // [sp+70h] [bp-8h]@8
    short *current_play_position; // [sp+74h] [bp-4h]@8

    v0 = video;
    if (!video)
        return 0;
    if (!dword_477DF4)
    {
        if (video->header.current_frame >= video->header.num_frames - 1)
        {
            v1 = video;
            if (video_477DEC_is_sound_playing)
            {
                v3 = video->header.field_18;
                v4 = ((_BYTE)v3 != 8) + 1;
                if (BYTE1(v3) & 1)
                    v4 *= 2;
                if (!sound_video_get_position((int *)&current_play_position, (int *)&v27)) {
                    v5 = 0;
                    goto LABEL_14;
                }
                if ((int)current_play_position < video_477DC4_current_sound_position)
                    dword_477DC8 += 0x10000;
                video_477DC4_current_sound_position = (int)current_play_position;
                current_play_position = (__int16 *)(((int)current_play_position + dword_477DC8) / v4);
                v2 = (signed __int64)((double)(int)current_play_position * 1000.0 / (double)v1->header._14_looks_like_fps);
            }
            else
            {
                LODWORD(v2) = timeGetTime();
            }
            v5 = (unsigned int)v2 < dword_477940;
        LABEL_14:
            if (!v5 && video)
            {
                if (video_477DEC_is_sound_playing)
                {
                    sound_video_stop();
                    video_477DEC_is_sound_playing = 0;
                }
                VIDEO_Clean(video);
                video = 0;
                video_477978_draw_job->job_details.image = 0;
                video_477978_draw_job->flags |= 0x80000000;
                video_477978_draw_job = 0;
                if (video_477DC0)
                {
                    video_477DC0->job_details.image = 0;
                    video_477DC0->flags |= 0x80000000;
                    video_477DC0 = 0;
                    return 0;
                }
            }
            return 0;
        }
        VIDEO_ReadNextFrame(video);
        v0 = video;
        v7 = video->header.num_sound_bytes;
        if (v7)
        {
            v8 = video;
            if (video_477DEC_is_sound_playing)
            {
                if (S_OK == video_477DE4_dsb->Lock(
                    (((unsigned __int64)dword_477944 >> 32) ^ abs(dword_477944)) - ((unsigned __int64)dword_477944 >> 32),
                    v7,
                    (LPVOID *)&current_play_position,
                    (LPDWORD)&v25,
                    (LPVOID *)&v27,
                    (LPDWORD)&v26,
                    0))
                {
                    v9 = v25;
                    if (v25)
                    {
                        memcpy(current_play_position, v8->header.ptr_20, v25);
                        v9 = v25;
                    }
                    v10 = (DWORD)v26;
                    if (v26)
                    {
                        memcpy(v27, (char *)v8->header.ptr_20 + v9, (unsigned int)v26);
                        v10 = (DWORD)v26;
                        v9 = v25;
                    }
                    dword_477944 += v8->header.num_sound_bytes;
                    video_477DE4_dsb->Unlock(current_play_position, v9, v27, v10);
                }
            }
            else
            {
                VIDEO_40D090(video);
            }
            v0 = video;
        }
        if (v0->header.current_frame >= v0->header.num_frames - 1 && video_477DEC_is_sound_playing)
        {
            if (!video_477DE4_dsb->Lock(
                (((unsigned __int64)dword_477944 >> 32) ^ abs(dword_477944)) - ((unsigned __int64)dword_477944 >> 32),
                0x10000,
                &v26,
                (LPDWORD)&v25,
                (LPVOID *)&v27,
                (LPDWORD)&current_play_position,
                0))
            {
                v11 = v25;
                if (v25)
                {
                    memset(v26, 0x80u, v25);
                    v11 = v25;
                }
                v12 = (char *)current_play_position;
                if (current_play_position)
                {
                    memset(v27, 0x80u, (unsigned int)current_play_position);
                    v12 = (char *)current_play_position;
                    v11 = v25;
                }
                dword_477944 += (int)&v12[v11];
                video_477DE4_dsb->Unlock(v26, v11, v27, (DWORD)v12);
            }
            v0 = video;
        }
        if (v0->header.current_frame)
        {
            video_477DF0 = 1;
        }
        else if (video_477DEC_is_sound_playing)
        {
            dword_477940 = 0;
        }
        else
        {
            v13 = timeGetTime();
            v0 = video;
            dword_477940 = v13;
        }
        dword_477DF4 = 1;
    }
    v14 = v0;
    if (video_477DEC_is_sound_playing)
    {
        v16 = v0->header.field_18;
        v17 = ((_BYTE)v16 != 8) + 1;
        if (BYTE1(v16) & 1)
            v17 *= 2;
        if (video_477DE4_dsb->GetCurrentPosition((LPDWORD)&current_play_position, (LPDWORD)&v27))
        {
            v18 = 0;
            goto LABEL_55;
        }
        if ((int)current_play_position < video_477DC4_current_sound_position)
            dword_477DC8 += 0x10000;
        video_477DC4_current_sound_position = (int)current_play_position;
        current_play_position = (__int16 *)(((int)current_play_position + dword_477DC8) / v17);
        v15 = (signed __int64)((double)(int)current_play_position * 1000.0 / (double)v14->header._14_looks_like_fps);
    }
    else
    {
        LODWORD(v15) = timeGetTime();
    }
    v18 = (unsigned int)v15 < dword_477940;
LABEL_55:
    if (v18)
    {
        video_477DF0 = 0;
        return 0;
    }
    v19 = video;
    dword_477DF4 = 0;
    dword_477940 += video->header.field_E;
    if (video->field_330 & 0x40)
    {
        VIDEO_40D450((char *)video->header.field_28, video->header.field_24);
        v19 = video;
    }
    if (*(_WORD *)&v19->gap2C[0])
    {
        v20 = *(_WORD *)&v19->gap2C[2];
        v21 = 3 * v20;
        v22 = 4 * v20 + 4684177;
        do
        {
            v23 = v19->gap2C[v21 + 4];
            v21 += 3;
            *(_BYTE *)(v22 - 1) = v23;
            *(_BYTE *)v22 = v19->gap2C[v21 + 2];
            *(_BYTE *)(v22 + 1) = v19->gap2C[v21 + 3];
            --*(_WORD *)&v19->gap2C[0];
            v19 = video;
            v22 += 4;
        } while (*(_WORD *)&video->gap2C[0]);
        _40E400_set_palette(&_477990_video_palette);
        v19 = video;
    }
    if (!video_477DF0)
    {
        _477948_video_draw_details._18_img_data = (void *)v19->header.field_10;
        v24 = v19->header.field_10;
        result = 1;
        stru_477D90._18_img_data = (void *)(v24 + _477948_video_draw_details.height * _477948_video_draw_details.width);
        return result;
    }
    return 0;
}
// 477940: using guessed type int dword_477940;
// 477944: using guessed type int dword_477944;
// 477D90: using guessed type DetailedDrawHandler_VideoPlayer stru_477D90;
// 477DC4: using guessed type int video_477DC4_current_sound_position;
// 477DC8: using guessed type int dword_477DC8;
// 477DEC: using guessed type int video_477DEC_is_sound_playing;
// 477DF0: using guessed type int video_477DF0;
// 477DF4: using guessed type int dword_477DF4;

//----- (0040D090) --------------------------------------------------------
void VIDEO_40D090(VideoFile *a1)
{
    VideoFile *v1; // ebx@1
    int v2; // ecx@1
    __int16 v3; // ax@1
    __int16 *v4; // [sp+30h] [bp-10h]@5
    DWORD v5; // [sp+34h] [bp-Ch]@5
    void *v6; // [sp+38h] [bp-8h]@5
    DWORD v7; // [sp+3Ch] [bp-4h]@5

    v1 = a1;
    v2 = a1->header.field_18;
    v3 = ((_BYTE)v2 != 8) + 1;
    if (BYTE1(v2) & 1)
        v3 *= 2;
    video_477DE4_dsb_waveformatex = 0;
    video_477DE4_dsb_waveformatex = 1;
    qword_477984 = 0i64;
    unk_47798C = 0;
    unk_477982 = (unsigned __int16)(((v1->header.field_18 & 0x100) != 0) + 1);
    LODWORD(qword_477984) = v1->header._14_looks_like_fps;
    unk_47798C = v3;
    HIDWORD(qword_477984) = v1->header._14_looks_like_fps * v3;
    unk_47798E = (unsigned __int8)v1->header.field_18 != 8 ? 16 : 8;


    video_477DE4_dsb_desc.dwReserved = 0;
    video_477DE4_dsb_desc.dwSize = 20;
    video_477DE4_dsb_desc.dwFlags = 0;
    video_477DE4_dsb_desc.dwBufferBytes = 0x10000;
    video_477DE4_dsb_desc.lpwfxFormat = (LPWAVEFORMATEX)&video_477DE4_dsb_waveformatex;
    if (pds
        && S_OK == pds->CreateSoundBuffer(&video_477DE4_dsb_desc, &video_477DE4_dsb, 0)
        && S_OK == video_477DE4_dsb->Lock(0, 0x10000, (LPVOID *)&v4, &v7, &v6, &v5, 0))
    {
        memcpy(v4, v1->header.ptr_20, v1->header.num_sound_bytes);
        dword_477944 = v1->header.num_sound_bytes;
        dword_477DC8 = 0;
        video_477DC4_current_sound_position = 0;
        video_477DE4_dsb->Unlock(v4, v7, v6, v5);
        video_477DE4_dsb->Play(0, 0, 1);
        video_477DEC_is_sound_playing = 1;
    }
}

//----- (0040D230) --------------------------------------------------------
void VIDEO_free()
{
    if (video)
    {
        if (video_477DEC_is_sound_playing)
        {
            video_477DE4_dsb->Stop();
            video_477DE4_dsb->Release();
            video_477DEC_is_sound_playing = 0;
        }
        VIDEO_Clean(video);
        video = 0;
        video_477978_draw_job->job_details.image = 0;
        video_477978_draw_job->flags |= 0x80000000;
        video_477978_draw_job = 0;
        if (video_477DC0)
        {
            video_477DC0->job_details.image = 0;
            video_477DC0->flags |= 0x80000000;
            video_477DC0 = 0;
        }
    }
}

//----- (0040D2C0) --------------------------------------------------------
bool VIDEO_IsVideoInvalid()
{
    return video == 0;
}

//----- (0040D2D0) --------------------------------------------------------
bool VIDEO_ReadAndAllocDrawJob_2(const char *a1, stru1_draw_params *a2, stru1_draw_params *a3, RenderString *a4, int width, int height, int z_index)
{
    stru1_draw_params *v7; // ebx@1
    BOOL result; // eax@2
    DrawJob *v9; // eax@5
    int v10; // ecx@8

    v7 = a2;
    video = VIDEO_ReadFile(a1);
    if (video)
    {
        if (a3)
            video_477DC0 = draw_list_add(0, 0);
        v9 = draw_list_add(0, 0);
        video_477978_draw_job = v9;
        if (v9)
        {
            v9->job_details.params = v7;
            video_477978_draw_job->job_details.x = 0;
            video_477978_draw_job->job_details.y = 0;
            video_477978_draw_job->job_details.z_index = z_index;
            video_477978_draw_job->job_details.image = &_477948_video_draw_details;
            _477970_video_header_field_6 = video->header.field_6;
            _477974_video_header_field_8 = video->header.field_8;
            _477948_video_draw_details.width = width;
            _477948_video_draw_details.height = height;
            _477948_video_draw_details.handler = render_video_draw_handler;
            _477948_video_draw_details.field_14 = 0;
            if (a3)
            {
                video_477DC0->job_details.params = a3;
                video_477DC0->job_details.x = 0;
                video_477DC0->job_details.y = 0;
                video_477DC0->job_details.z_index = z_index;
                video_477DC0->job_details.image = &stru_477D90;
                dword_477DB8 = 0;
                dword_477DBC = 0;
                stru_477D90.width = video->header.width;
                v10 = video->header.height - height;
                stru_477D90.handler = render_video_draw_handler;
                stru_477D90.height = v10;
                stru_477D90.field_14 = 0;
            }
            else
            {
                video_477DC0 = 0;
            }
            if (a4)
                VIDEO_40D430(a4);
            video_477DF0 = 0;
            result = 1;
        }
        else
        {
            VIDEO_Clean(video);
            video = 0;
            result = 0;
        }
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (0040D430) --------------------------------------------------------
void VIDEO_40D430(RenderString *a1)
{
    video_4780F8_subtitles = a1;
    video_4780F0 = 0;
    video_4780F4 = 0;
    video_4780EC = 0;
}

//----- (0040D450) --------------------------------------------------------
void VIDEO_40D450(char *a1, int a2)
{
    char *v2; // esi@1
    int v3; // edi@3
    char v4; // al@4
    bool v5; // sf@6
    unsigned __int8 v6; // of@6
    char *v7; // eax@10

    v2 = a1;
    if (video_4780F8_subtitles && a2 > 0)
    {
        v3 = a2;
        do
        {
            v4 = *v2++;
            if (v4 >= 32 && v4 < 127)
            {
                video_477DF8_subtitles[video_4780F0++] = v4;
                v6 = __OFSUB__(video_4780F4 + 1, 23);
                v5 = video_4780F4++ - 22 < 0;
                if (!(v5 ^ v6))
                    v4 = '\n';
            }
            if (v4 == '\n')
            {
                ++video_4780EC;
                video_477DF8_subtitles[video_4780F0++] = '\n';
                video_4780F4 = 0;
                if (video_4780EC >= 26)
                {
                    v7 = strchr(video_477DF8_subtitles, '\n') + 1;
                    video_4780F0 -= v7 - video_477DF8_subtitles;
                    --video_4780EC;
                    memcpy(video_477DF8_subtitles, v7, 675 - (v7 - video_477DF8_subtitles));
                    render_string_445AE0(video_4780F8_subtitles);
                }
            }
            video_477DF8_subtitles[video_4780F0] = 0;
            video_4780F8_subtitles->field_18 = 0;
            video_4780F8_subtitles->num_lines = 0;
            render_string_445770(video_4780F8_subtitles, video_477DF8_subtitles, 0);
            --v3;
        } while (v3);
    }
}


//----- (00459E80) --------------------------------------------------------
VideoFile *VIDEO_ReadFile(const char *video_name)
{
    VideoFile *result; // eax@1
    VideoFile *v2; // ebx@1
    VideoFile *v3; // esi@2
    __int32 v4; // eax@4
    char v5; // dl@4
    SIZE_T v6; // edi@4
    HLOCAL v7; // eax@4
    void *v8; // ecx@4
    __int16 v9; // bp@6
    int v10; // edi@8
    int v11; // eax@9
    int v12; // ebx@10
    int v13; // edx@10

    result = (VideoFile *)j_fopen_weirdmode_3(video_name);
    v2 = result;
    if (result)
    {
        v3 = (VideoFile *)LocalAlloc(0, 0x20748u);
        if (v3)
        {
            memset(v3, 0, 0x748u);
            video_47F434_frame = &v3->_744_frame;
            fread(&v3->_744_frame, 0x3Cu, 1u, (FILE *)v2);
            v3->header._0__first_4_bits_eq_bpp = video_47F434_frame->_14__first_4_bits_eq_bpp;
            v3->header.width = video_47F434_frame->width;
            v3->header.height = video_47F434_frame->height;
            v3->header.num_frames = video_47F434_frame->num_frames;
            v3->header.field_6 = video_47F434_frame->field_1A;
            v3->header.field_8 = video_47F434_frame->field_1C;
            v3->header._14_looks_like_fps = video_47F434_frame->_22_looks_like_fps;
            v3->header.field_18 = video_47F434_frame->field_20;
            v3->header.num_sound_bytes = 0;
            v3->header.current_frame = -1;
            v3->file = (FILE *)v2;
            v4 = ftell((FILE *)v2);
            v5 = v3->header._0__first_4_bits_eq_bpp;
            v3->data_offset = v4;
            v6 = v3->header.height * v3->header.width * (v5 & 0xF);
            v3->field_332 = 1;
            v3->frame_front_buffer = LocalAlloc(0, v6);
            v7 = LocalAlloc(0, v6);
            v8 = v3->frame_front_buffer;
            v3->frame_back_buffer = v7;
            v9 = !v8 || !v7;
            v10 = -8;
            do
            {
                v11 = -8;
                do
                {
                    v12 = (v3->header._0__first_4_bits_eq_bpp & 0xF) * (v11 + v3->header.width * v10);
                    v13 = 16 * (v10 & 0xF) | v11++ & 0xF;
                    v3->_344_prolly_palette[v13] = v12;
                } while (v11 < 8);
                ++v10;
            } while (v10 < 8);
            if (v9)
            {
                VIDEO_Clean(v3);
                result = 0;
            }
            else
            {
                result = v3;
            }
        }
        else
        {
            LocalFree(0);
            fclose((FILE *)v2);
            result = 0;
        }
    }
    return result;
}

//----- (0045A030) --------------------------------------------------------
void VIDEO_Clean(VideoFile *video)
{
    FILE *v1; // eax@2

    if (video)
    {
        v1 = video->file;
        if (v1)
            fclose(v1);
        LocalFree(video->frame_back_buffer);
        LocalFree(video->frame_front_buffer);
        LocalFree(video);
    }
}

//----- (0045A070) --------------------------------------------------------
int VIDEO_ReadNextFrame(VideoFile *a1)
{
    VideoFileFrame *v1; // edi@3
    int v2; // edx@6
    int result; // eax@8

    if (++a1->header.current_frame == a1->header.num_frames)
    {
        fseek(a1->file, a1->data_offset, 0);
        a1->header.current_frame = 0;
    }
    v1 = &a1->_744_frame;
    if (a1->header.current_frame)
        v1->frame_size = *(int *)((char *)&a1->_744_frame.frame_size + v1->frame_size);
    else
        fread(&a1->_744_frame, 4u, 1u, a1->file);
    v2 = v1->frame_size;
    if (a1->header.current_frame == a1->header.num_frames - 1)
        v2 -= 4;
    fread(&a1->_744_frame.field_4, v2, 1u, a1->file);
    video_45A110(a1, &a1->_744_frame);
    LOWORD_HEXRAYS(result) = 0;
    return result;
}

//----- (0045A110) --------------------------------------------------------
__int16 video_45A110(VideoFile *a1, VideoFileFrame *frame)
{
    VideoFileFrame *v2; // edi@1
    int v3; // edx@1
    int v4; // eax@1
    char *v5; // ebx@1
    __int16 v6; // cx@5
    char v7; // al@7
    int v8; // ecx@8
    __int16 *v9; // eax@9
    __int16 v10; // si@10
    __int16 v11; // ax@16
    int v12; // edx@16
    __int16 v13; // ax@19
    __int16 v14; // cx@24

    v2 = frame;
    v3 = 0;
    LOWORD_HEXRAYS(v4) = frame->field_4;
    a1->header.num_sound_bytes = 0;
    a1->field_330 = v4;
    a1->header.field_24 = 0;
    LOWORD_HEXRAYS(v4) = frame->field_4;
    v5 = (char *)&frame->field_6;
    if (v4 & 1)
    {
        v3 = *(_WORD *)v5 + frame->field_8 * a1->header.width;
        v5 = (char *)&frame->field_A;
    }
    if (v4 & 4)
    {
        a1->header.ptr_20 = (__int16 *)(v5 + 4);
        a1->header.num_sound_bytes = *(_DWORD *)v5 - 4;
        v4 = *(_DWORD *)v5;
        v5 += *(_DWORD *)v5;
    }
    v6 = frame->field_4;
    if (v6 & 8)
    {
        if ((a1->header._0__first_4_bits_eq_bpp & 0xF) == 2)
        {
            v7 = 0;
            if (v6 & 0x10)
            {
                memcpy(word_476DE0, &v5[*(_DWORD *)v5 + 4], 0x200u);
                v8 = dword_476FE0;
                if (dword_476FE0)
                {
                    v9 = word_476DE0;
                    do
                    {
                        v10 = *v9;
                        ++v9;
                        *(v9 - 1) = *(_WORD *)(v8 + 2 * (v10 & 0x7FFF));
                    } while ((int)v9 < (int)&dword_476FE0);
                }
                v2 = frame;
                v7 = 1;
            }
            else if (dword_476FE0)
            {
                v7 = 2;
            }
            __debugbreak(); // video codec
                            /*sub_45D3B8(
                            a1->header.width / 4,
                            a1->header.height / 4,
                            v5 + 4,
                            *((_DWORD *)&a1->frame_front_buffer + a1->field_332),
                            *((_DWORD *)&a1->frame_front_buffer + (a1->field_332 ^ 1)),
                            v3,
                            a1->header.width,
                            (int)a1->_344_prolly_palette,
                            v7);*/
        }
        else
        {
            __debugbreak(); // video codec
                            /*sub_45A48E(
                            a1->header.width / 4,
                            a1->header.height / 4,
                            v5 + 4,
                            *((_DWORD *)&a1->frame_front_buffer + a1->field_332),
                            *((_DWORD *)&a1->frame_front_buffer + (a1->field_332 ^ 1)),
                            v3,
                            a1->header.width,
                            (int)a1->_344_prolly_palette);*/
        }
        v11 = a1->field_332;
        v12 = *((_DWORD *)&a1->frame_front_buffer + v11);
        a1->field_332 = v11 ^ 1;
        a1->header.field_10 = v12;
        v4 = *(_DWORD *)v5;
        v5 += *(_DWORD *)v5;
    }
    if (v2->field_4 & 0x10)
    {
        if (a1->header._0__first_4_bits_eq_bpp == 1)
        {
            *(_WORD *)&a1->gap2C[2] = (unsigned __int8)v5[4];
            v13 = (unsigned __int8)v5[5];
            *(_WORD *)&a1->gap2C[0] = v13;
            if (!v13)
                *(_WORD *)&a1->gap2C[0] = 256;
            v4 = 3 * *(_WORD *)&a1->gap2C[0];
            memcpy((char *)&a1->header.field_10 + 2 * (*(_WORD *)&a1->gap2C[2] + 16) + *(_WORD *)&a1->gap2C[2], v5 + 6, v4);
            v2 = frame;
        }
        v5 += *(_DWORD *)v5;
    }
    if (v2->field_4 & 0x20)
    {
        v14 = *(_WORD *)v5;
        v5 += 2;
        a1->header.field_E = v14;
    }
    if (v2->field_4 & 0x40)
    {
        a1->header.field_24 = *(_DWORD *)v5 - 4;
        a1->header.field_28 = (int)(v5 + 4);
    }
    return v4;
}