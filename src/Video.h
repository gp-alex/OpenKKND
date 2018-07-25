#pragma once


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