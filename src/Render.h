#pragma once

struct stru1_draw_params;
struct DrawJob;
struct DrawJobList;
struct DrawJobDetails;

bool render_create_window(int width, int height, int bpp, int run, bool fullscreen);
bool render_init_dd();
void render_cleanup_dd();
bool render_should_render();
void render_on_wm_paint(struct tagRECT *);
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

void REND_SetClip(int a1, int a2, int a3, int a4);
HRESULT __stdcall EnumAttachedSurfacesCallback(IDirectDrawSurface *lpDDSurface, DDSURFACEDESC *lpDDSurfaceDesc, void *lpContext);
int render_clip(_DWORD *clipped_x, _DWORD *clipped_y, _DWORD *width, _DWORD *height, _DWORD *x, _DWORD *y); // idb
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
void render_do_draw_cursor_43A910(bool _CF, char _ZF, char _SF, unsigned __int8 _OF, _BYTE *a5, unsigned __int16 a6, unsigned __int16 a7, unsigned __int16 a8, __int16 a9, int a11, unsigned __int16 a12, unsigned __int16 a13, unsigned __int16 a14);
void render_draw_43B59F(bool _CF, char _ZF, char _SF, unsigned __int8 _OF, unsigned __int8 *sprite_data, unsigned __int16 x, unsigned __int16 y, unsigned __int16 width, __int16 height, unsigned __int8 *palette, unsigned __int8 *dst_surface, __int16 dst_surface_x, unsigned __int16 dst_surface_y, unsigned __int16 dst_surface_pitch);
void REND_DirectDrawClearScreen(int a2);

void render_draw_43A9E7(_BYTE *a1, unsigned __int16 a2, unsigned __int16 a3, unsigned __int16 a4, __int16 a5, int a7, __int16 a8, unsigned __int16 a9, unsigned __int16 a10);
void render_draw_43B4A6(unsigned __int8 *sprite_data, unsigned __int16 clipped_x, unsigned __int16 clipped_y, unsigned __int16 clipped_width, __int16 clipped_height, unsigned __int8 *palette, int dst_surface, unsigned __int16 dst_surface_x, unsigned __int16 dst_surface_y, unsigned __int16 dst_surface_pitch); // idb
bool draw_list_alloc();
DrawJob *draw_list_add(void *param, void(*on_update_handler)(void *, DrawJob *)); // idb
bool draw_list_update_and_draw();
void draw_list_update(DrawJobList *list);
void draw_list_z_order(DrawJobList *list);
void draw_list_free();

extern PALETTEENTRY *render_current_palette;