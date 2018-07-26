#pragma once

#include <Windows.h>
#include <mmeapi.h>

#include "src/hexrays-defs.h"
#include "src/kknd.h"



/* 374 */
struct VideoFileHeader
{
    __int16 _0__first_4_bits_eq_bpp;
    __int16 width;
    __int16 height;
    __int16 field_6;
    __int16 field_8;
    __int16 num_frames;
    __int16 current_frame;
    __int16 field_E;
    int field_10;
    int _14_looks_like_fps;
    int field_18;
    int num_sound_bytes;
    __int16 *ptr_20;
    int field_24;
    int field_28;
};

/* 376 */
struct VideoFileFrame
{
    int frame_size;
    __int16 field_4;
    __int16 field_6;
    __int16 field_8;
    __int16 field_A;
    char gap_C[8];
    __int16 _14__first_4_bits_eq_bpp;
    __int16 width;
    __int16 height;
    __int16 field_1A;
    __int16 field_1C;
    __int16 num_frames;
    __int16 field_20;
    __declspec(align(1)) int _22_looks_like_fps;
    __int16 field_26;
    __int16 field_28;
    __int16 field_2A;
    __int16 field_2C;
    __int16 field_2E;
    __int16 field_30;
    __int16 field_32;
    __int16 field_34;
    __int16 field_36;
    __int16 field_38;
    __int16 field_3A;
};

/* 375 */
struct VideoFile
{
    VideoFileHeader header;
    _BYTE gap2C[372];
    int field_1A0[80];
    _BYTE gap2E0[36];
    int field_304[9];
    _BYTE gap328[8];
    __int16 field_330;
    __int16 field_332;
    FILE *file;
    int data_offset;
    void *frame_front_buffer;
    void *frame_back_buffer;
    int _344_prolly_palette[256];
    VideoFileFrame _744_frame;
    char field_780[131015];
    char field_20747;
};

/* 377 */
struct DetailedDrawHandler_VideoPlayer
{
    int(*handler)(DrawJobDetails *data, int mode);
    int width;
    int height;
    int field_C;
    int field_10;
    int field_14;
    void *_18_img_data;
};




int VIDEO_Play(int id);

VideoFile *VIDEO_ReadFile(const char *video_name);
void VIDEO_Clean(VideoFile *video); // idb
int VIDEO_ReadNextFrame(VideoFile *a1);
__int16 video_45A110(VideoFile *a1, VideoFileFrame *frame); // idb



int VIDEO_IsAllocated();
int VIDEO_ReadAndAllocDrawJob(const char *a1, int x, int y, int z_index);
int VIDEO_DoFrame();
void VIDEO_40D090(VideoFile *a1);
void VIDEO_free();
bool VIDEO_IsVideoInvalid();
bool VIDEO_ReadAndAllocDrawJob_2(const char *a1, stru1_draw_params *a2, stru1_draw_params *a3, RenderString *a4, int width, int height, int z_index);
void VIDEO_40D430(RenderString *a1);
void VIDEO_40D450(char *a1, int a2);



extern DetailedDrawHandler_VideoPlayer stru_477D90; // weak
extern int dword_477DB8; // weak
extern int dword_477DBC; // weak
extern DrawJob *video_477DC0;
extern int video_477DC4_current_sound_position; // weak
extern int dword_477DC8; // weak
extern VideoFile *video;
extern int video_477DEC_is_sound_playing; // weak
extern int video_477DF0; // weak
extern int dword_477DF4; // weak
extern char video_477DF8_subtitles[756];
extern int video_4780EC; // weak
extern int video_4780F0; // weak
extern int video_4780F4; // weak
extern RenderString *video_4780F8_subtitles;
extern VideoFileFrame *video_47F434_frame;
extern DetailedDrawHandler_VideoPlayer _477948_video_draw_details;
extern int _477970_video_header_field_6; // weak
extern int _477974_video_header_field_8; // weak
extern DrawJob *video_477978_draw_job;
extern _UNKNOWN video_477DE4_dsb_waveformatex; // weak
extern _UNKNOWN unk_477982; // weak
extern __int64 qword_477984; // weak
extern _UNKNOWN unk_47798C; // weak
extern _UNKNOWN unk_47798E; // weak
extern int dword_477944; // weak
extern Palette _477990_video_palette; // idb