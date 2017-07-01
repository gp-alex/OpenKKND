#pragma once

struct stru1_draw_params;
struct DrawJob;
struct DrawJobDetails;

bool render_create_window(int width, int height, int bpp, int run, bool fullscreen);
bool render_init_dd();
void render_cleanup_dd();
bool render_should_render();
void render_on_wm_paint(struct tagRECT *);
stru1_draw_params *render_create_stru1(int a1, int clip_x, int clip_y, int clip_z, int clip_w); // idb
void render_remove_stru1(stru1_draw_params *a1);
bool render_dd_is_primary_surface_lost();
void render_draw_list(DrawJob *list);
int render_call_draw_handler_mode1(DrawJobDetails *a1);
int render_call_draw_handler_mode2(DrawJobDetails *a1);
void render_cleanup();
int render_sprt_draw_handler_setup_palettes();
int render_sprt_draw_handler(DrawJobDetails *data, int mode); // idb
int nullsub_3(void); // idb
int render_scrl_draw_handler(DrawJobDetails *data, int mode);
int render_video_draw_handler(DrawJobDetails *a1, int mode);