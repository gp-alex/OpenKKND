#pragma once

#include <memory>

#include "src/Infrastructure/Renderer/Renderer.h"
#include "src/Infrastructure/Window/Window.h"

extern std::shared_ptr<Infrastructure::Renderer> gRenderer;
extern std::shared_ptr<Infrastructure::Window> gWindow;



struct PaletteEntry {
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};

struct Palette {
    PaletteEntry entires[256];
};

struct stru1_draw_params;
struct DrawJob;
struct DrawJobList;
struct DrawJobDetails;

bool render_init(int width, int height, int bpp, bool fullscreen);
void render_cleanup();
bool render_should_render();
void render_on_wm_paint(long left, long top, long right, long bottom);
stru1_draw_params *render_create_stru1(int a1, int clip_x, int clip_y, int clip_z, int clip_w); // idb
void render_remove_stru1(stru1_draw_params *a1);
bool render_dd_is_primary_surface_lost();
void render_draw_list(DrawJobList *list);
int render_call_draw_handler_mode1(DrawJobDetails *a1);
int render_call_draw_handler_mode2(DrawJobDetails *a1);
void render_cleanup();
int render_sprt_draw_handler_setup_palettes();
int render_sprt_draw_handler(DrawJobDetails *data, int mode); // idb
int render_scrl_draw_handler(DrawJobDetails *data, int mode);
int render_video_draw_handler(DrawJobDetails *a1, int mode);
void render_copy_palette(Palette *dst, Palette *src);

void REND_SetClip(int a1, int a2, int a3, int a4);
int render_clip(int *clipped_x, int *clipped_y, int *width, int *height, int *x, int *y); // idb
void render_draw_tile_32x32(void *tile, int x_arg, int y_arg); // idb
void render_draw_tile_transparent_edges_32x32(unsigned __int8 *tile, int a2, int a3);
void render_draw_cursor_434A00(void *pixels, int x, __int16 y, __int16 width, __int16 height); // idb
int render_434A90(int a1, int a2, char a3, char a4, char a5, int a6);
void render_434AD0(int a1, int a2, __int16 a3, int a4, __int16 a5);
int render_434B70(int a1, int a2, char a3, int a4, char a5, int a6);
void render_434BD0(unsigned __int8 *sprite_data, unsigned __int8 *palette, int x, int y, int width, int height); // idb
void render_434C60(unsigned __int8 *sprite_data, unsigned __int8 *palette, int x, int y, int width, int height); // idb
void render_draw_tile(void *data, int image_off_x, int image_off_y, int image_x_size, int image_y_size); // idb
void render_434EA0(int a1, int a2, int a3, unsigned int a4, int a5);
char render_4351A0_draw(unsigned __int8 *pixels, int x, int y, int width, int height); // idb
int render_435320(void *pixels, int x, int y, int w, int h);
void render_draw_tile_transparent_edges(unsigned __int8 *tile, int a2, int a3, int a4, int a5); // idb
void render_do_draw_cursor_43A910(bool _CF, char _ZF, char _SF, unsigned __int8 _OF, char *a5, unsigned __int16 a6, unsigned __int16 a7, unsigned __int16 a8, __int16 a9, int a11, unsigned __int16 a12, unsigned __int16 a13, unsigned __int16 a14);
void render_draw_43B59F(bool _CF, char _ZF, char _SF, unsigned __int8 _OF, unsigned __int8 *sprite_data, unsigned __int16 x, unsigned __int16 y, unsigned __int16 width, __int16 height, unsigned __int8 *palette, unsigned __int8 *dst_surface, __int16 dst_surface_x, unsigned __int16 dst_surface_y, unsigned __int16 dst_surface_pitch);
void render_draw_43A9E7(char *a1, unsigned __int16 a2, unsigned __int16 a3, unsigned __int16 a4, __int16 a5, int a7, __int16 a8, unsigned __int16 a9, unsigned __int16 a10);
void render_draw_43B4A6(unsigned __int8 *sprite_data, unsigned __int16 clipped_x, unsigned __int16 clipped_y, unsigned __int16 clipped_width, __int16 clipped_height, unsigned __int8 *palette, int dst_surface, unsigned __int16 dst_surface_x, unsigned __int16 dst_surface_y, unsigned __int16 dst_surface_pitch); // idb
void _40E400_set_palette(Palette *palette);
void _431980_update_primary_palette(Palette *palette_entries);
void _408410_dim_palette();
void sub_408460();
void _408550_multi_pal();
void RENDER_SetViewportAndClear();
Palette *GetSysPalette();
void _40E6B0_set_sys_colors();
void _40E560_flip_gdi_update_syscolors();
int REND_SetRoutines();



typedef void(*DrawUpdateHandler)(void *, DrawJob *);
bool draw_list_alloc();
DrawJob *draw_list_add(void *update_handler_param, DrawUpdateHandler on_update_handler);
bool draw_list_update_and_draw();
void draw_list_update(DrawJobList *list);
void draw_list_z_order(DrawJobList *list);
void draw_list_free();



int render_unproject_x(int global_x);
int render_unproject_y(int global_y);
int render_get_color_blue();
void render_draw_line(int src_global_x, int src_global_y, int dst_global_x, int dst_global_y, int color_idx);
void render_outline_tile(
    int map_x, int map_y, int draw_x, int draw_y, int color_idx
    , const int tile_width = 32
    , const int tile_height = 32
    , const int border_size = 3
);



extern int j_render_nullsub_2; // weak
extern int j_render_434B70; // weak
extern Palette *ppalette_4785C0;
extern int j_render_434A90; // weak
extern int(*j_render_434EA0)(void *pixels, int x, int y, int w, int h); // idb
extern void(*j_render_4349D0_draw_tile_32x32)(void *pixels, int x, int y); // idb
extern int(*j_render_4351A0_draw)(void *pixels, int x, int y, int w, int h); // idb
extern Palette palette_4785F0; // weak
extern void(*p_render_set_clip)(int, int, int, int);
extern void(*j_render_434C60)(unsigned __int8 *pixels, unsigned __int8 *palette, int x, int y, int w, int h); // idb
extern int(*j_render_435320)(void *pixels, int x, int y, int w, int h);
extern void(*j_render_draw_tile)(void *data, int image_off_x, int image_off_y, int image_x_size, int image_y_size);
extern void(*j_render_draw_cursor_434A00)(void *pixels, int x, int y, int w, int h); // idb
extern int render_478A0C; // weak
extern int(*j_render_4349A0_draw_tile_32x32)(void *pixels, int x, int y); // idb
extern int _478A14_prev_stru1_palette_entries; // weak
extern void(*j_render_434BD0)(unsigned __int8 *sprite_data, unsigned __int8 *palette, int x, int y, int width, int height); // idb
extern int render_height; // idb
extern int render_width; // idb
extern void(*j_render_434AD0)(void *pixels, int x, int y, int w, int h); // idb
extern int render_478A94; // weak
extern int j_render_nullsub_1; // weak



