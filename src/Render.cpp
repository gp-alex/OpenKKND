#include "src/kknd.h"

#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"

#include "src/Render.h"

#include "src/Engine/Entity.h"



HWND global_hwnd = nullptr;
HDC render_sw_hdc = nullptr; // idb

const bool debug_outline_tiles = true;
extern bool is_mission_running;
extern Entity *debug_pathing_entity;


PALETTEENTRY *render_current_palette = nullptr;

//----- (00411760) --------------------------------------------------------
bool render_create_window(int width, int height, int bpp, int run, bool fullscreen)
{
    int he1ght; // ebx@1
    int w1dth; // ebp@1
    BOOL result; // eax@2
    BOOL v10; // eax@6
    DWORD v11; // eax@11
    LONG v12; // eax@13
    int v13; // ST18_4@13
    HWND v14; // eax@13
    stru1_draw_params *v15; // eax@19
    int v16; // ecx@21
    WNDCLASSEXA v17; // [sp+10h] [bp-30h]@8

    he1ght = height;
    w1dth = width;
    if (is_render_window_initialized)
        return false;

    if (bpp == 15)
    {
        bpp = 16;
    }
    else if (bpp != 8 && bpp != 16 && bpp != 24 && bpp != 32)
    {
        return false;
    }
    global_wnd_bpp = bpp;
    global_wnd_width = width;
    global_wnd_height = height;
    global_time_flows = run;
    global_fullscreen = fullscreen;

    HWND v9 = FindWindowA("OpenKKNDWindowClass", "OpenKKND");
    if (v9)
    {
        SetForegroundWindow(v9);
        v10 = 0;
    }
    else
    {
        ShowCursor(0);
        if (!global_hwnd)
        {
            v17.style = 8;
            v17.hInstance = global_hinstance;
            v17.lpszClassName = "KKNDXtremeMainWindowClass";
            v17.lpfnWndProc = (WNDPROC)WndProc;
            v17.cbSize = 48;
            v17.hIcon = LoadIconA(global_hinstance, (LPCSTR)0x65);
            v17.cbClsExtra = 0;
            v17.cbWndExtra = 0;
            v17.hIconSm = LoadIconA(global_hinstance, (LPCSTR)0x65);
            v17.hCursor = 0;
            v17.lpszMenuName = 0;
            v17.hbrBackground = (HBRUSH)GetStockObject(5);
            if (RegisterClassExA(&v17))
            {

                global_wnd_style = WS_VISIBLE | WS_POPUP | WS_SYSMENU;
                global_wnd_style_ex = WS_EX_APPWINDOW;
                if (global_fullscreen == 1)
                {
                    global_wnd_style_ex |= WS_EX_TOPMOST;
                }
                else
                {
                    global_wnd_style |= WS_DLGFRAME | WS_BORDER | WS_GROUP;
                }
                global_wnd_rect.left = 0;
                global_wnd_rect.right = global_wnd_width;
                global_wnd_rect.top = 0;
                global_wnd_rect.bottom = global_wnd_height;
                AdjustWindowRect(&global_wnd_rect, global_wnd_style, 0);
                global_wnd_rect.bottom -= global_wnd_rect.top;
                global_wnd_rect.right -= global_wnd_rect.left;
                global_wnd_rect.top = 0;
                global_wnd_rect.left = 0;
                v12 = GetSystemMetrics(0) - global_wnd_rect.right;
                global_wnd_rect.right += v12;
                v13 = global_wnd_rect.right - (v12 + global_wnd_rect.left);
                global_wnd_rect.left += v12;
                v14 = CreateWindowExA(
                    global_wnd_style_ex,
                    "KKNDXtremeMainWindowClass",
                    "KKND Xtreme",
                    global_wnd_style,
                    global_wnd_rect.left,
                    global_wnd_rect.top,
                    v13,
                    global_wnd_rect.bottom - global_wnd_rect.top,
                    0,
                    0,
                    global_hinstance,
                    0);
                global_hwnd = v14;
                if (v14)
                {
                    UpdateWindow(v14);
                }

                return v14 != nullptr;
            }
        }
    }

    return false;
}

//----- (00411A50) --------------------------------------------------------
bool render_init_dd()
{   
    //----- (00431920) --------------------------------------------------------
    //void render_sw_initialize()
    {
	    if (global_wnd_bpp == 8)
		    render_sw_hdc = GetDC(global_hwnd);
    }

    return true;
}

//----- (00411FE0) --------------------------------------------------------
void render_cleanup_dd()
{
}

//----- (00412190) --------------------------------------------------------
bool render_should_render()
{
    BOOL result; // eax@3
    bool v1; // sf@4
    unsigned __int8 v2; // of@4

    if (global_time_flows)
    {
        if (timer_time < timeGetTime())
        {
            if (timer_time < timeGetTime())
            {
                if (++timer_render_skips < 4)
                {
                    return 0;
                }
                else
                {
                    timer_time = timeGetTime();
                    timer_render_skips = 0;
                    return 1;
                }
            }
        }
        else
        {
            timer_render_skips = 0;
            result = 1;
        }
    }
    else
    {
        result = 1;
    }
    return result;
}

//----- (004121F0) --------------------------------------------------------
stru1_draw_params *render_create_stru1(int a1, int clip_x, int clip_y, int clip_z, int clip_w)
{
    stru1_draw_params *result; // eax@5

    if (clip_x < global_wnd_width
        && clip_y < global_wnd_height
        && clip_z + clip_x <= global_wnd_width
        && clip_w + clip_y <= global_wnd_height
        && (result = stru1_list_free_pool) != 0)
    {
        stru1_list_free_pool = stru1_list_free_pool->next;
        result->next = default_stru1.next;
        default_stru1.next = result;
        result->next->prev = result;
        result->prev = &default_stru1;
        result->field_8 = a1;
        result->anim_pos = 0x80000000;
        result->clip_x = clip_x;
        result->clip_y = clip_y;
        result->clip_z = clip_z;
        result->clip_w = clip_w;
        result->field_20 = 0;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (00412280) --------------------------------------------------------
void render_remove_stru1(stru1_draw_params *a1)
{
    if (a1)
    {
        a1->next->prev = a1->prev;
        a1->prev->next = a1->next;
        a1->field_8 |= 0x80000000;
        a1->next = stru1_list_free_pool;
        stru1_list_free_pool = a1;
    }
}

//----- (004122B0) --------------------------------------------------------
bool render_dd_is_primary_surface_lost()
{
    return false;
    /*BOOL result; // eax@2

    if (!pdds_primary || (result = pdds_primary->IsLost()) != 0)
        result = 1;
    return result;*/
}

//----- (004122D0) --------------------------------------------------------
void render_draw_list(DrawJobList *list)
{
    int restore_palettes; // ebx@4
    int v4; // eax@8
    HRESULT v5; // eax@9
    int v7; // eax@15
    HRESULT v8; // eax@16
    DrawJob *i; // esi@25
    MapdScrlImage *v10; // eax@26
    int(*v11)(DrawJobDetails *, int); // eax@27
    RECT v12; // [sp+44h] [bp-94h]@34
    POINT Point; // [sp+54h] [bp-84h]@35
    POINT v14; // [sp+5Ch] [bp-7Ch]@35
    RECT v15; // [sp+64h] [bp-74h]@35

    if (list && render_default_stru1)
    /*if (list && render_default_stru1 && pdds_primary)
    {
        restore_palettes = 0;
        if (pdds_primary->IsLost() == 0x887601C2 && global_fullscreen == 1)
            restore_palettes = 1;
        v3 = pdds_primary;
        if (pdds_primary)
        {
            v5 = pdds_primary->IsLost();
            if (v5 == 0x887601C2)
                v4 = v3->Restore() == 0;
            else
                v4 = v5 == 0;
        }
        else
        {
            v4 = 0;
        }
        if (v4)
        {
            if (global_fullscreen == 1
                || ((v6 = pdds_backbuffer) != 0 ? ((v8 = pdds_backbuffer->IsLost(), v8 != 0x887601C2) ? (v7 = v8 == 0) : (v7 = v6->Restore() == 0)) : (v7 = 0),
                    v7))
            {
                if (restore_palettes)
                {
                    pdds_primary->SetPalette(pddpal_primary);
                    pddpal_primary->SetEntries(0, 0, 256, RenderDD_primary_palette_values);
                }
                _40E430_update_palette(render_default_stru1->anim_pos);
                if (!pdds_backbuffer->Lock(&stru_465810, &ddsd_primary, 1, 0))
                {
                    render_locked_surface_width_px = ddsd_primary.dwWidth;*/
                    render_locked_surface_width_px = 640;

                    // 8/16 bpp are hardcoded, introduce a walkaround for ordinary bpp
                    //static auto pixels_8bpp = new unsigned char[ddsd_primary.dwWidth * ddsd_primary.dwHeight];
                    static auto pixels_8bpp = new unsigned char[640 * 480];

                    //render_locked_surface_ptr = ddsd_primary.lpSurface;
                    render_locked_surface_ptr = pixels_8bpp;

                    render_first_drawing_item = 1;
                    for (i = list->next; i != (DrawJob *)list; i = i->next)
                    {
                        v10 = (MapdScrlImage *)i->job_details.image;
                        if (v10)
                        {
                            v11 = v10->on_draw_handler;
                            if (v11)
                                v11(&i->job_details, 0);
                        }
                    }

                    // convert 8bpp to target bpp (32 here)
                    /*for (int y = 0; y < ddsd_primary.dwHeight; ++y)
                    {
                        for (int x = render_locked_surface_width_px - 1; x >= 0; --x)
                        {
                            auto c = pixels_8bpp[render_locked_surface_width_px * y + x];

                            auto p = (unsigned char *)ddsd_primary.lpSurface;
                            //*(unsigned int *)(p + ddsd_primary.lPitch * y + x * 4) = (c << 16) | (c << 8) | c;

                            int r, g, b;
                            r = c;
                            g = c;
                            b = c;
                            if (render_current_palette)
                            {
                                r = render_current_palette[c].peRed;
                                g = render_current_palette[c].peGreen;
                                b = render_current_palette[c].peBlue;
                            }

                            *(unsigned int *)(p + ddsd_primary.lPitch * y + x * 4) = (r << 16) | (g << 8) | b;
                        }
                    }*/



                    static auto pixels_32bpp = new unsigned int[640 * 480];

                    for (int y = 0; y < 480; ++y)
                    {
                        for (int x = 640 - 1; x >= 0; --x)
                        {
                            auto c = pixels_8bpp[render_locked_surface_width_px * y + x];

                            //auto p = (unsigned char *)ddsd_primary.lpSurface;
                            //*(unsigned int *)(p + ddsd_primary.lPitch * y + x * 4) = (c << 16) | (c << 8) | c;

                            int r, g, b;
                            r = c;
                            g = c;
                            b = c;
                            if (render_current_palette)
                            {
                                r = render_current_palette[c].peRed;
                                g = render_current_palette[c].peGreen;
                                b = render_current_palette[c].peBlue;
                            }

                            pixels_32bpp[y * 640 + x] = RGB(b, g, r);
                            //SetPixel(render_sw_hdc, x, y, RGB(r, g, b));
                            //*(unsigned int *)(p + ddsd_primary.lPitch * y + x * 4) = (r << 16) | (g << 8) | b;
                        }
                    }

                    static HDC dc_backbuffer = CreateCompatibleDC(nullptr);
                    static HBITMAP hbm_backbuffer = nullptr;
                    if (hbm_backbuffer == nullptr) {
                        hbm_backbuffer = CreateCompatibleBitmap(render_sw_hdc, 640, 480);
                        DeleteObject(SelectObject(dc_backbuffer, hbm_backbuffer));
                    }

                    BITMAPINFO bmpInfo = { 0 };
                    BITMAPINFOHEADER bmpInfoHeader = { 0 };
                    BITMAP ImageBitmap;
                    void *bits;

                    bmpInfoHeader.biSize = sizeof(BITMAPINFOHEADER);
                    bmpInfoHeader.biBitCount = 32;
                    bmpInfoHeader.biClrImportant = 0;
                    bmpInfoHeader.biClrUsed = 0;
                    bmpInfoHeader.biCompression = BI_RGB;
                    bmpInfoHeader.biHeight = -480;
                    bmpInfoHeader.biWidth = 640;
                    bmpInfoHeader.biPlanes = 1;
                    bmpInfoHeader.biSizeImage = 640 * 480 * 4;

                    ZeroMemory(&bmpInfo, sizeof(bmpInfo));
                    bmpInfo.bmiHeader = bmpInfoHeader;
                    bmpInfo.bmiColors->rgbBlue = 0;
                    bmpInfo.bmiColors->rgbGreen = 0;
                    bmpInfo.bmiColors->rgbRed = 0;
                    bmpInfo.bmiColors->rgbReserved = 0;

                    SetDIBitsToDevice(render_sw_hdc, 0, 0, 640, 480, 0, 0, 0, 480, pixels_32bpp, &bmpInfo, DIB_RGB_COLORS);




                    //delete[] pixels_8bpp;
                    //delete[] rgb32bits;


                    /*if (!pdds_backbuffer->Unlock(ddsd_primary.lpSurface))
                    {
                        if (global_fullscreen == 1)
                        {
                            if (fullscreen_flip_or_blt)
                            {
                                pdds_primary->Flip(0, 0);
                            }
                            else
                            {
                                v12.bottom = global_wnd_height;
                                v12.top = 0;
                                v12.left = 0;
                                v12.right = global_wnd_width;
                                memset(&v16, 0, sizeof(v16));
                                v16.dwSize = 100;
                                v16.dwDDFX = 8;
                                pdds_primary->Blt(
                                    &v12,
                                    pdds_backbuffer,
                                    &v12,
                                    DDBLT_WAIT | DDBLT_DDFX | DDBLT_ASYNC,
                                    &v16);
                            }
                        }
                        else
                        {
                            v14.x = global_wnd_width;
                            v14.y = global_wnd_height;
                            Point.x = 0;
                            Point.y = 0;
                            ClientToScreen(global_hwnd, &Point);
                            ClientToScreen(global_hwnd, &v14);
                            v12.top = 0;
                            v12.left = 0;
                            *(struct tagPOINT *)&v15.left = Point;
                            v12.right = global_wnd_width;
                            *(struct tagPOINT *)&v15.right = v14;
                            v12.bottom = global_wnd_height;
                            memset(&v16, 0, sizeof(v16));
                            v16.dwSize = 100;
                            v16.dwDDFX = 8;
                            pdds_primary->Blt(&v15, pdds_backbuffer, &v12, DDBLT_WAIT | DDBLT_DDFX | DDBLT_ASYNC, &v16);
                        }
                    }
                }
            }
        }
    }*/
}

//----- (004125D0) --------------------------------------------------------
int render_call_draw_handler_mode1(DrawJobDetails *a1)
{
    MapdScrlImage *v1; // eax@1
    int result; // eax@2

    v1 = (MapdScrlImage *)a1->image;
    if (v1)
        result = v1->on_draw_handler(a1, 1);
    else
        result = 0;
    return result;
}

//----- (004125F0) --------------------------------------------------------
int render_call_draw_handler_mode2(DrawJobDetails *a1)
{
    MapdScrlImage *v1; // eax@1
    int result; // eax@2

    v1 = (MapdScrlImage *)a1->image;
    if (v1)
        result = v1->on_draw_handler(a1, 2);
    else
        result = 0;
    return result;
}

//----- (00412610) --------------------------------------------------------
void render_cleanup()
{
    if (is_render_window_initialized == 1)
    {
        render_cleanup_dd();
        render_sw_free_palette();
        ShowWindow(global_hwnd, 0);
        UpdateWindow(global_hwnd);
        free(stru1_list);
    }
}

//----- (00412650) --------------------------------------------------------
int render_sprt_draw_handler_setup_palettes()
{
    copy_player_sprite_palette_aligned(palette_465848_sprt, (unsigned __int8 *)palette_4798F8_sprt_aligned);
    return 1;
}

//----- (00412670) --------------------------------------------------------
int render_sprt_draw_handler(DrawJobDetails *data, int mode)
{
    DrawJobDetails *v2; // esi@1
    int result; // eax@4
    stru1_draw_params *v4; // eax@7
    DrawHandlerData_Units *v5; // edi@7
    int v6; // ecx@9
    int v7; // ebx@9
    int v8; // ebp@9
    int v9; // edx@10
    int width; // ecx@17
    char v11; // bl@19
    int _x; // edx@26
    char *pixels; // ecx@26
    int _y; // [sp-Ch] [bp-20h]@26
    int _width; // [sp-8h] [bp-1Ch]@26
    int he1ght; // [sp-4h] [bp-18h]@20
    int height; // [sp-4h] [bp-18h]@23
    int _height; // [sp-4h] [bp-18h]@26

    v2 = data;

    auto image = (MobdSprtImage *)data->image;
    v5 = image->data;
    if (mode != 0)
    {
        if (mode == 1)
            return v5->width;
        if (mode == 2)
            return v5->height;
        return 0;
    }
    if (data->flags & 0xC0000000)
        return 0;

    v4 = data->params;
    if (!v4)
        v4 = render_default_stru1;

    v6 = data->x;
    v7 = v5->width;
    v8 = v5->height;
    if (v6 > v4->clip_z)
        return 0;
    v9 = v2->y;
    if (v9 > v4->clip_w || !(v7 + v6) || !(v8 + v9))
        return 0;
    if (v4 != current_drawing_params)
    {
        current_drawing_params = v4;
        p_render_set_clip(v4->clip_x, v4->clip_y, v4->clip_z, v4->clip_w);
    }
    if (v5->type == 0)
    {
        _height = v5->height;
        _width = v5->width;
        _y = v2->y;
        _x = v2->x;
        pixels = (char *)v5->sprite_data;
        if (image->flags & 1)        // MobdSprtImage::flags
        {
            j_render_435320(pixels, _x, _y, _width, _height);
            render_first_drawing_item = 0;
            return 0;
        }
        j_render_4351A0_draw(pixels, _x, _y, _width, _height);
        goto LABEL_29;
    }
    if (v5->type != 2 || (width = v5->width, v7 != v5->width) || v8 != v5->height)
    {
    LABEL_29:
        render_first_drawing_item = 0;
        return 0;
    }
    v11 = image->flags;              // MobdSprtImage::flags
    if ((v2->flags & 0x10000000) == 0x10000000)
    {
        he1ght = v5->height;
        if (v11 & 1)
        {
            j_render_434C60(v5->sprite_data, v2->palette, v2->x, v2->y, width, he1ght);
            render_first_drawing_item = 0;
            result = 0;
        }
        else
        {
            j_render_434BD0(v5->sprite_data, v2->palette, v2->x, v2->y, width, he1ght);
            render_first_drawing_item = 0;
            result = 0;
        }
    }
    else
    {
        height = v5->height;
        if (v11 & 1)
        {
            j_render_434AD0(v5->sprite_data, v2->x, v2->y, width, height);
            render_first_drawing_item = 0;
            result = 0;
        }
        else
        {
            j_render_draw_cursor_434A00(v5->sprite_data, v2->x, v2->y, width, height);
            render_first_drawing_item = 0;
            result = 0;
        }
    }
    return result;
}

void debug_mission_pathing_outline(int map_x, int map_y, int draw_x, int draw_y) {
    if (!debug_pathing_entity) {
        return;
    }
    if (map_x < 0 || map_x >= _4793F8_map_width || map_y < 0 || map_y >= _478AAC_map_height)
        return;

    bool should_outline = false;
    int black = 0;
    for (int i = 0; i < 10; ++i) {
        if (debug_pathing_entity->_15C_waypoints_xs[i] == map_x && debug_pathing_entity->_15C_waypoints_ys[i] == map_y) {
            should_outline = true;
        }
        if (debug_pathing_entity->_1AC_waypoints_xs[i] == map_x && debug_pathing_entity->_1AC_waypoints_ys[i] == map_y) {
            should_outline = true;
        }
        if (debug_pathing_entity->_1FC_waypoints_xs[i] == map_x && debug_pathing_entity->_1FC_waypoints_ys[i] == map_y) {
            should_outline = true;
        }
    }

    if (should_outline) {
        int w = 32;
        int h = 4;
        for (int _y = draw_y; _y < draw_y + h; ++_y) {
            if (_y < 0)
                continue;
            if (_y >= 480)
                break;
            for (int _x = draw_x; _x < draw_x + w; ++_x) {
                if (_x < 0)
                    continue;
                if (_x >= 640)
                    break;
                int y_off = render_locked_surface_width_px * (render_clip_y + _y);
                int x_off = _x + render_clip_x;
                auto dst = (unsigned __int8 *)render_locked_surface_ptr + x_off + y_off;
                *dst = black;
            }
        }
    }
}
void debug_mission_tile_outline(int map_x, int map_y, int draw_x, int draw_y) {
    if (map_x < 0 || map_x >= _4793F8_map_width || map_y < 0 || map_y >= _478AAC_map_height)
        return;

    int black = 0;
    int blue = 11;
    int lightblue = 12;
    int teal = 13;
    int orange = 14;

    auto tile = Map_get_tile(map_x, map_y);
    if (tile->IsVehicleOrBuilding()) {
        int w = 32;
        int h = 4;
        for (int _y = draw_y; _y < draw_y + h; ++_y) {
            if (_y < 0)
                continue;
            if (_y >= 480)
                break;
            for (int _x = draw_x; _x < draw_x + w; ++_x) {
                if (_x < 0)
                    continue;
                if (_x >= 640)
                    break;
                int y_off = render_locked_surface_width_px * (render_clip_y + _y);
                int x_off = _x + render_clip_x;
                auto dst = (unsigned __int8 *)render_locked_surface_ptr + x_off + y_off;
                *dst = blue;
            }
        }
    } else if (tile->IsImpassibleTerrain()) {
        int w = 32;
        int h = 4;
        int c = black;
        if (tile->flags & BOXD_STRU0_OBSTRUCTED)
            c = teal;
        else if (tile->flags & BOXD_STRU0_BLOCKED)
            c = orange;
        for (int _y = draw_y; _y < draw_y + h; ++_y) {
            if (_y < 0)
                continue;
            if (_y >= 480)
                break;
            for (int _x = draw_x; _x < draw_x + w; ++_x) {
                if (_x < 0)
                    continue;
                if (_x >= 640)
                    break;
                int y_off = render_locked_surface_width_px * (render_clip_y + _y);
                int x_off = _x + render_clip_x;
                auto dst = (unsigned __int8 *)render_locked_surface_ptr + x_off + y_off;
                *dst = c;
            }
        }
    }
}

//----- (00412860) --------------------------------------------------------
int render_scrl_draw_handler(DrawJobDetails *data, int mode)
{
    MapdScrlImage *data_draw_handler; // edi@1
    stru1_draw_params *data_params; // esi@7
    int data_y; // ebp@7
    int data_x; // ebx@7
    unsigned int v7; // ecx@18
    unsigned int v8; // ebx@18
    int v9; // ebp@18
    unsigned int x_tiles_to_draw; // eax@18
    unsigned int v11; // ecx@18
    int starting_y_tile; // ecx@22
    unsigned int v13; // edx@22
    unsigned int y_tiles_to_draw; // eax@22
    unsigned int tile_y_size; // ebx@24
    unsigned int v16; // ebp@24
    unsigned int v17; // edx@24
    int *image_data; // ebx@27
    unsigned int v19; // eax@29
    int v20; // esi@29
    _BYTE *tile_ptr; // eax@31
    unsigned int num_x_tiles_to_draw; // [sp+10h] [bp-10h]@16
    int dAta_y; // [sp+14h] [bp-Ch]@7
    unsigned int y_tiles_left; // [sp+14h] [bp-Ch]@28
    int starting_x_tile; // [sp+18h] [bp-8h]@16
    unsigned int x_tiles_left; // [sp+18h] [bp-8h]@30
    int leftover_x; // [sp+1Ch] [bp-4h]@16

    data_draw_handler = (MapdScrlImage *)data->image;
    if (mode == 0)
    {
        if (data->flags & 0xC0000000)
            return 0;
        data_params = data->params;
        data_y = data->y;
        data_x = data->x;
        dAta_y = data->y;
        if (!data_params)
            data_params = render_default_stru1;
        if (data_x >= data_params->clip_z
            || data_x <= -(signed __int16)(LOWORD_HEXRAYS(data_draw_handler->tile_x_size) * LOWORD_HEXRAYS(data_draw_handler->num_x_tiles))
            || data_y >= data_params->clip_w
            || data_y <= -(signed __int16)(LOWORD_HEXRAYS(data_draw_handler->tile_y_size) * LOWORD_HEXRAYS(data_draw_handler->num_y_tiles)))
        {
            return 0;
        }
        if (data_params != current_drawing_params)
        {
            current_drawing_params = data_params;
            p_render_set_clip(data_params->clip_x, data_params->clip_y, data_params->clip_z, data_params->clip_w);
        }
        if (data_x < 0)
        {
            v7 = data_draw_handler->tile_x_size;
            v8 = -data_x;
            v9 = v8 / v7;
            starting_x_tile = v9;
            leftover_x = ~(v8 % v7);
            x_tiles_to_draw = (v7 + data_params->clip_z - 1) / v7;
            v11 = data_draw_handler->num_x_tiles;
            num_x_tiles_to_draw = x_tiles_to_draw + 1;
            if (v9 + x_tiles_to_draw + 1 > v11)
                num_x_tiles_to_draw = v11 - v9;
            data_y = dAta_y;
        }
        else
        {
            leftover_x = data_x;
            starting_x_tile = 0;
            num_x_tiles_to_draw = (unsigned int)(data_draw_handler->tile_x_size - data_x + data_params->clip_z - 1)
                / data_draw_handler->tile_x_size
                + 1;
            if (num_x_tiles_to_draw > data_draw_handler->num_x_tiles)
                num_x_tiles_to_draw = data_draw_handler->num_x_tiles;
        }
        if (data_y < 0)
        {
            tile_y_size = data_draw_handler->tile_y_size;
            v16 = -data_y;
            starting_y_tile = v16 / tile_y_size;
            data_y = ~(v16 % tile_y_size);
            v17 = data_draw_handler->num_y_tiles;
            y_tiles_to_draw = (tile_y_size + data_params->clip_w - 1) / tile_y_size + 1;
            if (y_tiles_to_draw + starting_y_tile > v17)
            {
                v13 = v17 - starting_y_tile;
            LABEL_26:
                y_tiles_to_draw = v13;
                goto LABEL_27;
            }
        }
        else
        {
            starting_y_tile = 0;
            v13 = data_draw_handler->num_y_tiles;
            y_tiles_to_draw = (unsigned int)(data_draw_handler->tile_y_size - dAta_y + data_params->clip_w - 1)
                / data_draw_handler->tile_y_size
                + 1;
            if (y_tiles_to_draw > v13)
                goto LABEL_26;
        }
    LABEL_27:
        image_data = (int *)&data_draw_handler->tiles[starting_x_tile + data_draw_handler->num_x_tiles * starting_y_tile];
        if (y_tiles_to_draw)
        {
            y_tiles_left = y_tiles_to_draw;
            do
            {
                v19 = num_x_tiles_to_draw;
                v20 = leftover_x;
                if (num_x_tiles_to_draw)
                {
                    x_tiles_left = num_x_tiles_to_draw;
                    do
                    {
                        tile_ptr = (_BYTE *)*image_data;
                        if (*image_data)
                        {
                            if (render_first_drawing_item || *tile_ptr & 1)
                                j_render_4349A0_draw_tile_32x32(tile_ptr + 4, v20, data_y);// second param -> neg (x leftover)
                                                                                           // last param = neg (y leftover)
                            else
                                j_render_4349D0_draw_tile_32x32(tile_ptr + 4, v20, data_y);

                            if (debug_outline_tiles) {
                                if (is_mission_running) {
                                    debug_mission_tile_outline(
                                        starting_x_tile + num_x_tiles_to_draw - x_tiles_left,
                                        starting_y_tile + y_tiles_to_draw - y_tiles_left,
                                        v20,
                                        data_y
                                    );
                                    debug_mission_pathing_outline(
                                        starting_x_tile + num_x_tiles_to_draw - x_tiles_left,
                                        starting_y_tile + y_tiles_to_draw - y_tiles_left,
                                        v20,
                                        data_y
                                    );
                                }
                            }
                        }
                        v20 += data_draw_handler->tile_x_size;
                        ++image_data;
                        --x_tiles_left;
                    } while (x_tiles_left);
                    v19 = num_x_tiles_to_draw;
                }
                image_data += data_draw_handler->num_x_tiles - v19;
                data_y += data_draw_handler->tile_y_size;
                --y_tiles_left;
            } while (y_tiles_left);
        }
        render_first_drawing_item = 0;
        return 0;
    }
    if (mode == 1)
        return data_draw_handler->num_x_tiles * data_draw_handler->tile_x_size;
    if (mode == 2)
        return data_draw_handler->num_y_tiles * data_draw_handler->tile_y_size;
    return 0;
}
// 46580C: using guessed type int render_first_drawing_item;

//----- (00412A80) --------------------------------------------------------
int render_video_draw_handler(DrawJobDetails *a1, int mode)
{
    DrawJobDetails *v2; // esi@1
    DetailedDrawHandler_VideoPlayer *v3; // edi@1
    stru1_draw_params *v5; // eax@7
    int v6; // ecx@9
    int v7; // ecx@11
    void *v8; // ecx@15

    v2 = a1;
    v3 = (DetailedDrawHandler_VideoPlayer *)a1->image;
    if (mode)
    {
        if (mode == 1)
            return v3->width;
        if (mode == 2)
            return v3->height;
    }
    else if (!(a1->flags & 0xC0000000))
    {
        v5 = a1->params;
        if (!v5)
            v5 = render_default_stru1;
        v6 = a1->x;
        if (v6 <= v5->clip_z)
        {
            if (v6 + v3->width)
            {
                v7 = v2->y;
                if (v7 <= v5->clip_w)
                {
                    if (v7 + v3->height)
                    {
                        if (v5 != current_drawing_params)
                        {
                            current_drawing_params = v5;
                            p_render_set_clip(v5->clip_x, v5->clip_y, v5->clip_z, v5->clip_w);
                        }
                        v8 = v3->_18_img_data;
                        if (v8)
                        {
                            if (v3->field_14)
                            {
                                j_render_434EA0(v8, v2->x, v2->y, v3->width, v3->height);
                                render_first_drawing_item = 0;
                                return 0;
                            }
                            j_render_draw_tile(v8, v2->x, v2->y, v3->width, v3->height);
                        }
                        render_first_drawing_item = 0;
                    }
                }
            }
        }
    }
    return 0;
}


//----- (00434790) --------------------------------------------------------
void REND_DirectDrawClearScreen(int a2)
{
    /*int v2; // esi@1
    int v3; // eax@3
    int v8; // [sp+0h] [bp-6Ch]@3

    v2 = a2;

    if (global_fullscreen == 1)
    {
        pdds_primary->EnumAttachedSurfaces(0, EnumAttachedSurfacesCallback);
    }
    else if (pdds_backbuffer)
    {
        memset(&v9, 0, sizeof(v9));
        v9.dwFillColor = 0;
        v9.dwSize = 100;
        pdds_backbuffer->Blt(&_46BB50_blt_rect, 0, 0, DDBLT_WAIT | DDBLT_COLORFILL, &v9);
    }
    if (v2 && pdds_primary)
    {
        memset(&v9, 0, sizeof(v9));
        v9.dwFillColor = 0;
        v9.dwSize = 100;
        pdds_primary->Blt(&_46BB50_blt_rect, 0, 0, DDBLT_WAIT | DDBLT_COLORFILL, &v9);
    }*/
}

//----- (0040E2A0) --------------------------------------------------------
int REND_SetRoutines()
{
    render_width = 640;
    render_height = 480;
    render_478A94 = 1;
    render_478A0C = 1;
    p_render_set_clip = REND_SetClip;
    REND_SetClip(0, 0, render_width, render_height);
    j_render_draw_tile = render_draw_tile;
    j_render_4351A0_draw = (decltype(j_render_4351A0_draw))render_4351A0_draw;
    j_render_434EA0 = (decltype(j_render_434EA0))render_434EA0;
    j_render_draw_cursor_434A00 = (decltype(j_render_draw_cursor_434A00))render_draw_cursor_434A00;
    j_render_434A90 = (int)render_434A90;
    j_render_nullsub_1 = (int)nullsub_1;
    j_render_435320 = render_435320;
    j_render_434AD0 = (decltype(j_render_434AD0))render_434AD0;
    j_render_434B70 = (int)render_434B70;
    j_render_434BD0 = (decltype(j_render_434BD0))render_434BD0;
    j_render_434C60 = (decltype(j_render_434C60))render_434C60;
    j_render_4349A0_draw_tile_32x32 = (decltype(j_render_4349A0_draw_tile_32x32))render_draw_tile_32x32;
    j_render_4349D0_draw_tile_32x32 = (decltype(j_render_4349D0_draw_tile_32x32))render_draw_tile_transparent_edges_32x32;
    j_render_nullsub_2 = (int)nullsub_1;
    return 1;
}


//----- (00434710) --------------------------------------------------------
void REND_SetClip(int a1, int a2, int a3, int a4)
{
    render_clip_x = a1;
    render_clip_y = a2;
    render_clip_z = a3;
    render_clip_w = a4;
}
/*
//----- (00434740) --------------------------------------------------------
HRESULT __stdcall EnumAttachedSurfacesCallback(IDirectDrawSurface *lpDDSurface, DDSURFACEDESC *lpDDSurfaceDesc, void *lpContext)
{
    DDBLTFX v5; // [sp+0h] [bp-64h]@2

    if (lpDDSurface)
    {
        memset(&v5, 0, sizeof(v5));
        v5.dwFillColor = 0;
        v5.dwSize = 100;
        lpDDSurface->Blt(&_46BB40_enum_attached_surfaces_blt_rect, 0, 0, DDBLT_WAIT | DDBLT_COLORFILL, &v5);
    }
    return 1;
}
*/
//----- (004348B0) --------------------------------------------------------
int render_clip(_DWORD *clipped_x, _DWORD *clipped_y, _DWORD *width, _DWORD *height, _DWORD *x, _DWORD *y)
{
    int result; // eax@3

    if (*y < 0)
    {
        *clipped_y -= *y;
        *height += *y;
        if (*height <= 0)
            return 0;
        *y = 0;
    }
    if (*height + *y > render_clip_w)
    {
        *height = render_clip_w - *y;
        if (*height <= 0)
            return 0;
    }
    if (*x < 0)
    {
        *clipped_x -= *x;
        *width += *x;
        if (*width <= 0)
            return 0;
        *x = 0;
    }
    result = 1;
    if (*width + *x > render_clip_z)
    {
        *width = render_clip_z - *x;
        if (*width <= 0)
            result = 0;
    }
    return result;
}

void render_draw_tile_outlines(int x, int y, int w, int h) {
    //for (int _y = y; _y < y + h; ++_y) {
    //    for (int _x = x; _x < x + w; ++_x) {
    //        auto dst
    //    }
    //}
    for (int _y = y, _x = x; _x < x + w; ++_x) {
        if (_x < 0)
            continue;
        if (_x >= 640)
            break;
        if (_y < 0 || _y >= 480)
            break;
        int y_off = render_locked_surface_width_px * (render_clip_y + _y);
        int x_off = _x + render_clip_x;
        auto dst = (unsigned __int8 *)render_locked_surface_ptr + x_off + y_off;
        *dst = 123;
    }
    for (int _y = y, _x = x; _y < y + h; ++_y) {
        if (_x < 0 || _x >= 640)
            break;
        if (_y < 0)
            continue;
        if (_y >= 480)
            break;
        int y_off = render_locked_surface_width_px * (render_clip_y + _y);
        int x_off = _x + render_clip_x;
        auto dst = (unsigned __int8 *)render_locked_surface_ptr + x_off + y_off;
        *dst = 123;
    }
}

//----- (004349A0) --------------------------------------------------------
void render_draw_tile_32x32(void *tile, int x_arg, int y_arg)
{
    render_draw_tile(tile, x_arg, y_arg, 32, 32);
    if (debug_outline_tiles) {
        if (is_mission_running) {
            render_draw_tile_outlines(x_arg, y_arg, 32, 32);
        }
    }
}

//----- (004349D0) --------------------------------------------------------
void render_draw_tile_transparent_edges_32x32(unsigned __int8 *tile, int a2, int a3)
{
    render_draw_tile_transparent_edges(tile, a2, a3, 32, 32);
}

//----- (00434A00) --------------------------------------------------------
void render_draw_cursor_434A00(void *pixels, int x, __int16 y, __int16 width, __int16 height)
{
    int X; // [sp+0h] [bp-10h]@1
    _BYTE *v7; // [sp+4h] [bp-Ch]@1
    int clipped_y; // [sp+8h] [bp-8h]@1
    int clipped_x; // [sp+Ch] [bp-4h]@1

    X = x;
    v7 = (char *)pixels;
    clipped_y = 0;
    clipped_x = 0;

    int _w = width, _h = height, _x = x, _y = y;
    if (render_clip(&clipped_x, &clipped_y, &_w, &_h, &_x, &_y))
    {
        width = _w;
        height = _h;
        X = _x;
        y = _y;

        render_do_draw_cursor_43A910(
            __CFADD__(render_clip_x, X),
            render_clip_x + X == 0,
            render_clip_x + X < 0,
            __OFADD__(render_clip_x, X),
            v7,
            clipped_x,
            clipped_y,
            width,
            height,
            (int)render_locked_surface_ptr,
            render_clip_x + X,
            render_clip_y + y,
            render_locked_surface_width_px);
    }
}

//----- (00434A90) --------------------------------------------------------
int render_434A90(int a1, int a2, char a3, char a4, char a5, int a6)
{
    int v7; // [sp+0h] [bp-10h]@1
    int v8; // [sp+4h] [bp-Ch]@1
    int v9; // [sp+8h] [bp-8h]@1
    int v10; // [sp+Ch] [bp-4h]@1

    v7 = a2;
    v8 = a1;
    v9 = 0;
    v10 = 0;

    int _a3 = a3, _a4 = a4, _a5 = a5;
    auto r = render_clip(&v10, &v9, &_a4, &_a5, &v7, &_a3);
    a3 = _a3;
    a4 = _a4;
    a5 = _a5;

    return r;
}

//----- (00434AD0) --------------------------------------------------------
void render_434AD0(int a1, int a2, __int16 a3, int a4, __int16 a5)
{
    int v6; // [sp+0h] [bp-14h]@1
    _BYTE *v7; // [sp+4h] [bp-10h]@1
    int v8; // [sp+8h] [bp-Ch]@1
    int v9; // [sp+Ch] [bp-8h]@1
    int v10; // [sp+10h] [bp-4h]@1

    v6 = a2;
    v7 = (_BYTE *)a1;
    v8 = 0;
    v9 = 0;
    v10 = a4;

    int _a3 = a3, _a5 = a5;
    if (render_clip(&v9, &v8, &a4, &_a5, &v6, &_a3))
    {
        a3 = _a3;
        a5 = _a5;

        v9 = v10 - (a4 + v9);
        render_draw_43A9E7(
            v7,
            v9,
            v8,
            a4,
            a5,
            (int)render_locked_surface_ptr,
            render_clip_x + v6,
            render_clip_y + a3,
            render_locked_surface_width_px);
    }
}

//----- (00434B70) --------------------------------------------------------
int render_434B70(int a1, int a2, char a3, int a4, char a5, int a6)
{
    int result; // eax@1
    int v7; // [sp+0h] [bp-14h]@1
    int v8; // [sp+4h] [bp-10h]@1
    int v9; // [sp+8h] [bp-Ch]@1
    int v10; // [sp+Ch] [bp-8h]@1
    int v11; // [sp+10h] [bp-4h]@1

    v7 = a2;
    v8 = a1;
    v9 = 0;
    v10 = 0;
    v11 = a4;

    int _a5 = a5;
    int _a3 = a3;
    result = render_clip(&v10, &v9, &a4, &_a5, &v7, &_a3);
    a3 = _a3;
    a5 = _a5;

    if (result)
        result = a4 + v10;
    return result;
}

//----- (00434BD0) --------------------------------------------------------
void render_434BD0(unsigned __int8 *sprite_data, unsigned __int8 *palette, int x, int y, int width, int height)
{
    unsigned __int8 *pAlette; // [sp+0h] [bp-10h]@1
    unsigned __int8 *spr1te_data; // [sp+4h] [bp-Ch]@1
    int clipped_y; // [sp+8h] [bp-8h]@1
    int clipped_x; // [sp+Ch] [bp-4h]@1

    pAlette = palette;
    spr1te_data = sprite_data;
    clipped_y = 0;
    clipped_x = 0;
    if (render_clip(&clipped_x, &clipped_y, &width, &height, &x, &y))
    {
        render_draw_43B4A6(
            spr1te_data,
            clipped_x,
            clipped_y,
            width,
            height,
            pAlette,
            (int)render_locked_surface_ptr,
            render_clip_x + x,
            render_clip_y + y,
            render_locked_surface_width_px);
    }
}

//----- (00434C60) --------------------------------------------------------
void render_434C60(unsigned __int8 *sprite_data, unsigned __int8 *palette, int x, int y, int width, int height)
{
    unsigned __int8 *pAlette; // [sp+0h] [bp-14h]@1
    unsigned __int8 *spr1te_data; // [sp+4h] [bp-10h]@1
    int clipped_y; // [sp+8h] [bp-Ch]@1
    int clipped_x; // [sp+Ch] [bp-8h]@1
    int v11; // [sp+10h] [bp-4h]@1

    pAlette = palette;
    spr1te_data = sprite_data;
    clipped_y = 0;
    clipped_x = 0;
    v11 = width;

    if (render_clip(&clipped_x, &clipped_y, &width, &height, &x, &y))
    {
        clipped_x = v11 - (width + clipped_x);

        render_draw_43B59F(
            __CFADD__(render_clip_x, x),
            render_clip_x + x == 0,
            render_clip_x + x < 0,
            __OFADD__(render_clip_x, x),
            spr1te_data,
            clipped_x,
            clipped_y,
            width,
            height,
            pAlette,
            (unsigned __int8 *)render_locked_surface_ptr,
            render_clip_x + x,
            render_clip_y + y,
            render_locked_surface_width_px);
    }
}

//----- (00434D00) --------------------------------------------------------
void render_draw_tile(void *data, int image_off_x, int image_off_y, int image_x_size, int image_y_size)
{
    unsigned __int8 *pdAta; // esi@17
    unsigned __int8 *dst; // edi@17
    int v7; // edx@17
    unsigned int this_row_x_pixels; // ecx@18
    char v9; // al@24
    unsigned int v10; // ecx@24
    int v11; // eax@24
    unsigned __int8 *v12; // edi@24
    unsigned __int8 *v13; // esi@24
    unsigned __int8 v14; // of@26
    char *pdata; // [sp+10h] [bp-20h]@1
    int x_pixels_to_render; // [sp+18h] [bp-18h]@12
    int y_off; // [sp+20h] [bp-10h]@4
    int v18; // [sp+24h] [bp-Ch]@12
    int y_clip_off; // [sp+28h] [bp-8h]@6
    int num_pixels_to_skip; // [sp+28h] [bp-8h]@14
    int row_pitch_leftover; // [sp+2Ch] [bp-4h]@17

    pdata = (char *)data;
    if (image_off_y < 0)
    {
        if (image_y_size + image_off_y <= 0)
            return;
        y_off = image_y_size + image_off_y;
        pdata = (char *)data + image_x_size * -image_off_y;
        y_clip_off = render_locked_surface_width_px * render_clip_y;
    }
    else
    {
        if (image_y_size + image_off_y <= render_clip_w)
        {
            y_off = image_y_size;
        }
        else
        {
            if (image_off_y >= render_clip_w)
                return;
            y_off = render_clip_w - image_off_y;
        }
        y_clip_off = render_locked_surface_width_px * (render_clip_y + image_off_y);
    }
    if (image_off_x < 0)
    {
        if (image_x_size + image_off_x > 0)
        {
            x_pixels_to_render = image_x_size + image_off_x;
            pdata -= image_off_x;
            v18 = -image_off_x;
            num_pixels_to_skip = render_clip_x + y_clip_off;
            goto LABEL_17;
        }
    }
    else
    {
        if (image_x_size + image_off_x <= render_clip_z)
        {
            x_pixels_to_render = image_x_size;
            v18 = 0;
            goto LABEL_14;
        }
        if (image_off_x < render_clip_z)
        {
            x_pixels_to_render = render_clip_z - image_off_x;
            v18 = image_x_size - (render_clip_z - image_off_x);
        LABEL_14:
            num_pixels_to_skip = render_clip_x + image_off_x + y_clip_off;
        LABEL_17:
            row_pitch_leftover = render_locked_surface_width_px - x_pixels_to_render;
            pdAta = (unsigned __int8 *)pdata;
            dst = (unsigned __int8 *)render_locked_surface_ptr + num_pixels_to_skip;
            v7 = y_off;
            while (1)
            {
                v14 = __OFSUB__(v7--, 1);
                if ((v7 < 0) ^ v14)
                    return;
                this_row_x_pixels = x_pixels_to_render;
                if (!((unsigned __int8)dst & 1)
                    || (*dst = *pdAta, ++pdAta, ++dst, this_row_x_pixels = x_pixels_to_render - 1, x_pixels_to_render != 1))
                {
                    if ((unsigned __int8)dst & 2)
                    {
                        if (this_row_x_pixels == 1)
                        {
                            *dst++ = *pdAta++;
                            goto LABEL_25;
                        }
                        *(_WORD *)dst = *(_WORD *)pdAta;
                        pdAta += 2;
                        dst += 2;
                        this_row_x_pixels -= 2;
                    }
                    v9 = this_row_x_pixels;
                    v10 = this_row_x_pixels >> 2;
                    v11 = v9 & 3;
                    memcpy(dst, pdAta, v9);
                    //qmemcpy(dst, pdAta, 4 * v10);
                    v13 = &pdAta[4 * v10];
                    v12 = &dst[4 * v10];
                    //qmemcpy(v12, v13, v11);
                    pdAta = &v13[v11];
                    dst = &v12[v11];
                }
            LABEL_25:
                pdAta += v18;
                dst += row_pitch_leftover;
            }
        }
    }
}

//----- (00434EA0) --------------------------------------------------------
void render_434EA0(int a1, int a2, int a3, unsigned int a4, int a5)
{
    int v5; // [sp+Ch] [bp-20h]@1
    int v6; // [sp+10h] [bp-1Ch]@17
    unsigned int v7; // [sp+14h] [bp-18h]@12
    int v8; // [sp+18h] [bp-14h]@17
    int v9; // [sp+18h] [bp-14h]@21
    int v10; // [sp+1Ch] [bp-10h]@4
    unsigned int v11; // [sp+20h] [bp-Ch]@12
    int v12; // [sp+24h] [bp-8h]@6
    int v13; // [sp+24h] [bp-8h]@14
    int v14; // [sp+28h] [bp-4h]@17

    v5 = a1;
    if (a3 < 0)
    {
        if (a5 + a3 <= 0)
            return;
        v10 = a5 + a3;
        v5 = a4 * -a3 + a1;
        v12 = render_locked_surface_width_px * render_clip_y;
    }
    else
    {
        if (a5 + a3 <= render_clip_w)
        {
            v10 = a5;
        }
        else
        {
            if (a3 >= render_clip_w)
                return;
            v10 = render_clip_w - a3;
        }
        v12 = render_locked_surface_width_px * (render_clip_y + a3);
    }
    if (a2 < 0)
    {
        if ((int)(a4 + a2) <= 0)
            return;
        v7 = a4 + a2;
        v5 -= a2;
        v11 = -a2;
        v13 = render_clip_x + v12;
    }
    else
    {
        if ((int)(a4 + a2) <= render_clip_z)
        {
            v7 = a4;
            v11 = 0;
        }
        else
        {
            if (a2 >= render_clip_z)
                return;
            v7 = render_clip_z - a2;
            v11 = a4 - (render_clip_z - a2);
        }
        v13 = render_clip_x + a2 + v12;
    }
    v14 = render_locked_surface_width_px - v7;
    v6 = v5;
    v8 = (int)render_locked_surface_ptr + v13;
    while (v10)
    {
        if (v8 & 3)
        {
            if ((v8 & 3) == 3)
            {
                *(_BYTE *)v8 = *(_BYTE *)v6;
                memcpy((void *)(v8 + 1), (const void *)(v6 + 1), v7 - 1);
                v9 = v14 + v7 + v8;
                memcpy((void *)(v9 + 1), (const void *)(v6 + 1), v7 - 1);
            }
            else if (v8 & 1)
            {
                *(_BYTE *)v8 = *(_BYTE *)v6;
                memcpy((void *)(v8 + 1), (const void *)(v6 + 1), v7 - 1);
                v9 = v14 + v7 + v8;
                memcpy((void *)(v9 + 1), (const void *)(v6 + 1), v7 - 1);
            }
            else
            {
                *(_WORD *)v8 = *(_WORD *)v6;
                memcpy((void *)(v8 + 2), (const void *)(v6 + 2), v7 - 2);
                v9 = v14 + v7 + v8;
                memcpy((void *)(v9 + 2), (const void *)(v6 + 2), v7 - 2);
            }
        }
        else
        {
            memcpy((void *)v8, (const void *)v6, v7);
            v9 = v14 + v7 + v8;
            memcpy((void *)v9, (const void *)v6, v7);
        }
        v6 += v7 + 2 * v11;
        v8 = v14 + v7 + v9;
        --v10;
    }
}

//----- (004351A0) --------------------------------------------------------
char render_4351A0_draw(unsigned __int8 *pixels, int x, int y, int width, int height)
{
    int dst_px_offset; // eax@11
    unsigned __int8 *src; // esi@13
    char *dst; // edi@13
    int height_left; // ecx@13
    int width_left; // ebx@14
    int v11; // [sp+Ch] [bp-20h]@1
    int dst_y_offset; // [sp+14h] [bp-18h]@5
    int dst_x_offset; // [sp+18h] [bp-14h]@2
    int actual_height; // [sp+1Ch] [bp-10h]@5
    int actual_width; // [sp+20h] [bp-Ch]@2
    unsigned __int8 *p1xels; // [sp+28h] [bp-4h]@1
    int ya; // [sp+34h] [bp+8h]@1

    p1xels = pixels;
    v11 = render_clip_x + x;
    ya = render_clip_y + y;
    if (render_clip_x + x >= render_clip_x)
    {
        dst_x_offset = render_clip_x + x;
        actual_width = width;
    }
    else
    {
        dst_x_offset = render_clip_x;
        actual_width = width + x;
        p1xels = &pixels[-x];
    }
    if (ya >= render_clip_y)
    {
        dst_y_offset = ya;
        actual_height = height;
    }
    else
    {
        dst_y_offset = render_clip_y;
        actual_height = height - (render_clip_y - ya);
        p1xels += width * (render_clip_y - ya);
    }
    if (width + v11 > render_clip_z + render_clip_x)
        actual_width -= width + v11 - (render_clip_z + render_clip_x);
    if (height + ya > render_clip_w + render_clip_y)
        actual_height -= height + ya - (render_clip_w + render_clip_y);
    dst_px_offset = dst_x_offset + dst_y_offset * render_locked_surface_width_px;
    if (actual_width > 0 && actual_height > 0)
    {
        src = p1xels;
        dst = (char *)render_locked_surface_ptr + dst_px_offset;
        height_left = actual_height;
        do
        {
            width_left = actual_width;
            do
            {
                LOBYTE_HEXRAYS(dst_px_offset) = src[width_left - 1];
                if ((_BYTE)dst_px_offset)
                    dst[width_left - 1] = dst_px_offset;
                --width_left;
            } while (width_left);
            src += width;
            dst += render_locked_surface_width_px;
            --height_left;
        } while (height_left);
    }
    return dst_px_offset;
}

//----- (00435320) --------------------------------------------------------
int render_435320(void *pxiels, int x, int y, int w, int h)
{
    int result; // eax@11
    char *v6; // esi@13
    char *v7; // edi@13
    int v8; // ecx@13
    int v9; // ebx@14
    signed int v10; // edx@14
    int v11; // [sp+Ch] [bp-20h]@1
    int v12; // [sp+14h] [bp-18h]@5
    int v13; // [sp+18h] [bp-14h]@2
    int v14; // [sp+1Ch] [bp-10h]@5
    int v15; // [sp+20h] [bp-Ch]@2
    char *v16; // [sp+28h] [bp-4h]@1
    int ya; // [sp+34h] [bp+8h]@1

    v16 = (char *)pxiels;
    v11 = render_clip_x + x;
    ya = render_clip_y + y;
    if (render_clip_x + x >= render_clip_x)
    {
        v13 = render_clip_x + x;
        v15 = w;
    }
    else
    {
        v13 = render_clip_x;
        v15 = w + x;
        v16 = (char *)pxiels - x;
    }
    if (ya >= render_clip_y)
    {
        v12 = ya;
        v14 = h;
    }
    else
    {
        v12 = render_clip_y;
        v14 = h - (render_clip_y - ya);
        v16 += w * (render_clip_y - ya);
    }
    if (w + v11 > render_clip_z + render_clip_x)
        v15 -= w + v11 - (render_clip_z + render_clip_x);
    if (h + ya > render_clip_w + render_clip_y)
        v14 -= h + ya - (render_clip_w + render_clip_y);
    result = v13 + v12 * render_locked_surface_width_px;
    if (v15 > 0 && v14 > 0)
    {
        v6 = v16;
        v7 = (char *)render_locked_surface_ptr + result;
        v8 = v14;
        do
        {
            v9 = v15;
            v10 = 1;
            do
            {
                LOBYTE_HEXRAYS(result) = v6[v10 - 1];
                if ((_BYTE)result)
                    v7[v9 - 1] = result;
                ++v10;
                --v9;
            } while (v9);
            v6 += w;
            v7 += render_locked_surface_width_px;
            --v8;
        } while (v8);
    }
    return result;
}

//----- (004354A0) --------------------------------------------------------
void render_draw_tile_transparent_edges(unsigned __int8 *tile, int a2, int a3, int a4, int a5)
{
    char *result; // eax@2
    unsigned __int8 *t1le; // [sp+4h] [bp-28h]@1
    unsigned int v7; // [sp+8h] [bp-24h]@24
    unsigned int v8; // [sp+8h] [bp-24h]@32
    unsigned __int8 *v9; // [sp+Ch] [bp-20h]@17
    int v10; // [sp+10h] [bp-1Ch]@12
    char *v11; // [sp+14h] [bp-18h]@17
    int v12; // [sp+18h] [bp-14h]@4
    int v13; // [sp+1Ch] [bp-10h]@19
    int v14; // [sp+20h] [bp-Ch]@12
    int v15; // [sp+24h] [bp-8h]@6
    int v16; // [sp+24h] [bp-8h]@14
    int v17; // [sp+28h] [bp-4h]@17

    t1le = tile;
    if (a3 < 0)
    {
        if (a5 + a3 <= 0)
            return;
        v12 = a5 + a3;
        t1le = &tile[a4 * -a3];
        result = (char *)(render_locked_surface_width_px * render_clip_y);
        v15 = render_locked_surface_width_px * render_clip_y;
    }
    else
    {
        result = (char *)(a5 + a3);
        if (a5 + a3 <= render_clip_w)
        {
            result = (char *)a5;
            v12 = a5;
        }
        else
        {
            if (a3 >= render_clip_w)
                return;
            v12 = render_clip_w - a3;
        }
        v15 = render_locked_surface_width_px * (render_clip_y + a3);
    }
    if (a2 < 0)
    {
        if (a4 + a2 <= 0)
            return;
        v10 = a4 + a2;
        t1le -= a2;
        v14 = -a2;
        v16 = render_clip_x + v15;
    }
    else
    {
        if (a4 + a2 <= render_clip_z)
        {
            v10 = a4;
            v14 = 0;
        }
        else
        {
            if (a2 >= render_clip_z)
                return;
            v10 = render_clip_z - a2;
            v14 = a4 - (render_clip_z - a2);
        }
        v16 = render_clip_x + a2 + v15;
    }
    v17 = render_locked_surface_width_px - v10;
    result = (char *)t1le;
    v9 = t1le;
    v11 = (char *)render_locked_surface_ptr + v16;
    while (v12)
    {
        v13 = v10;
        if ((unsigned __int8)v11 & 1)
        {
            if (*v9)
                *v11 = *v9;
            ++v11;
            ++v9;
            v13 = v10 - 1;
        }
        while (v13 >= 4)
        {
            v7 = *(_DWORD *)v9;
            if (*(_DWORD *)v9)
            {
                if ((_BYTE)v7)
                {
                    if (v7 & 0xFF00)
                        *(_WORD *)v11 = v7;
                    else
                        *v11 = v7;
                }
                else if (v7 & 0xFF00)
                {
                    v11[1] = (unsigned __int16)(v7 & 0xFF00) >> 8;
                }
                v8 = v7 >> 16;
                if ((_BYTE)v8)
                {
                    if (v8 & 0xFF00)
                        *((_WORD *)v11 + 1) = v8;
                    else
                        v11[2] = v8;
                }
                else if (v8 & 0xFF00)
                {
                    v11[3] = (unsigned __int16)(v8 & 0xFF00) >> 8;
                }
            }
            v9 += 4;
            v11 += 4;
            v13 -= 4;
        }
        while (v13)
        {
            if (*v9)
                *v11 = *v9;
            ++v9;
            ++v11;
            --v13;
        }
        result = (char *)&v9[v14];
        v9 += v14;
        v11 += v17;
        --v12;
    }
}


//----- (0043A910) --------------------------------------------------------
void render_do_draw_cursor_43A910(bool _CF, char _ZF, char _SF, unsigned __int8 _OF, _BYTE *a5, unsigned __int16 a6, unsigned __int16 a7, unsigned __int16 a8, __int16 a9, int a11, unsigned __int16 a12, unsigned __int16 a13, unsigned __int16 a14)
{
    _BYTE *v14; // esi@1
    unsigned int v15; // ecx@1
    int v16; // eax@2
    char *v17; // edi@4
    unsigned int v18; // eax@4
    char *v19; // esi@5
    unsigned int v20; // ecx@5
    unsigned int v21; // ebx@5
    _BYTE *v22; // esi@6
    unsigned int v23; // ebx@6
    char *v24; // esi@9
    int v25; // edi@18
    unsigned __int16 v26; // ax@19
    _BYTE *v28; // [sp-1Ah] [bp-22h]@5
    int v29; // [sp+4h] [bp-4h]@0

    v14 = a5;
    v15 = a7;
    if (a7)
    {
        v16 = 0;
        do
        {
            LOBYTE_HEXRAYS(v16) = *v14;
            v14 += v16;
            --v15;
        } while (v15);
    }
    v17 = (char *)(a12 + a14 * a13 + a11);
    render_43B4A6_46BD04 = a14 - a8;
    v18 = 0;
    LOWORD_HEXRAYS(v15) = a9;
    do
    {
        v28 = v14;
        v19 = v14 + 1;
        v20 = _byteswap_ulong(v15);
        LOWORD_HEXRAYS(v20) = a8;
        v21 = a6;
        if (a6)
        {
            while (1)
            {
                LOBYTE_HEXRAYS(v18) = *v19;
                v22 = v19 + 1;
                _CF = v21 < v18;
                v23 = v21 - v18;
                if (_CF || v23 == 0)
                    break;
                LOBYTE_HEXRAYS(v18) = *v22;
                v19 = &v22[v18 + 1];
                _CF = v23 < v18;
                v21 = v23 - v18;
                if (_CF || v21 == 0)
                {
                    if (v21)
                    {
                        v24 = &v19[v21];
                        v18 = -(int)v21;
                        goto LABEL_16;
                    }
                    goto LABEL_12;
                }
            }
            if (v23)
            {
                v18 = -(int)v23;
                goto LABEL_13;
            }
            goto LABEL_15;
        }
        while (1)
        {
        LABEL_12:
            LOBYTE_HEXRAYS(v18) = *v19;
            v22 = v19 + 1;
        LABEL_13:
            _OF = __OFSUB__((_WORD)v20, (_WORD)v18);
            LOWORD_HEXRAYS(v20) = v20 - v18;
            if ((unsigned __int8)(((v20 & 0x8000u) != 0) ^ _OF) | ((_WORD)v20 == 0))
            {
                LOWORD_HEXRAYS(v18) = v20 + v18;
                v25 = (int)&v17[v18];
                goto LABEL_20;
            }
            v17 += v18;
        LABEL_15:
            LOBYTE_HEXRAYS(v18) = *v22;
            v24 = v22 + 1;
        LABEL_16:
            _OF = __OFSUB__((_WORD)v20, (_WORD)v18);
            LOWORD_HEXRAYS(v20) = v20 - v18;
            if ((unsigned __int8)(((v20 & 0x8000u) != 0) ^ _OF) | ((_WORD)v20 == 0))
                break;
            memcpy(v17, v24, (unsigned __int16)v18);
            v19 = &v24[(unsigned __int16)v18];
            v17 += (unsigned __int16)v18;
            v18 = 0;
        }
        v26 = v20 + v18;
        memcpy(v17, v24, v26);
        v25 = (int)&v17[v26];
        v18 = 0;
    LABEL_20:
        LOBYTE_HEXRAYS(v18) = *v28;
        v14 = &v28[v18];
        v17 = (char *)(render_43B4A6_46BD04 + v25);
        v15 = _byteswap_ulong(v20);
        LOWORD_HEXRAYS(v15) = v15 - 1;
    } while ((_WORD)v15);
}

//----- (0043A9E7) --------------------------------------------------------
void render_draw_43A9E7(_BYTE *a1, unsigned __int16 a2, unsigned __int16 a3, unsigned __int16 a4, __int16 a5, int a7, __int16 a8, unsigned __int16 a9, unsigned __int16 a10)
{
    _BYTE *v10; // esi@1
    unsigned int v11; // ecx@1
    int v12; // eax@2
    int v13; // edi@4
    unsigned int v14; // eax@6
    _BYTE *v15; // esi@7
    unsigned int v16; // ecx@7
    unsigned int v17; // ebx@7
    _BYTE *v18; // esi@8
    bool v19; // cf@8
    unsigned int v20; // ebx@8
    unsigned __int8 v21; // of@15
    int v22; // ecx@19
    int v23; // ecx@23
    unsigned int v25; // [sp-1Ch] [bp-24h]@19
    unsigned int v26; // [sp-1Ch] [bp-24h]@23
    _BYTE *v27; // [sp-18h] [bp-20h]@7
    int v28; // [sp+4h] [bp-4h]@0

    v10 = a1;
    v11 = a3;
    if (a3)
    {
        v12 = 0;
        do
        {
            LOBYTE_HEXRAYS(v12) = *v10;
            v10 += v12;
            --v11;
        } while (v11);
    }
    v13 = (unsigned __int16)(a4 + a8) + a10 * a9 + a7;

    render_43B4A6_46BD04 = a4 + a10;
    v14 = 0;
    LOWORD_HEXRAYS(v11) = a5;
    do
    {
        v27 = v10;
        v15 = v10 + 1;
        v16 = _byteswap_ulong(v11);
        LOWORD_HEXRAYS(v16) = a4;
        v17 = a2;
        if (a2)
        {
            while (1)
            {
                LOBYTE_HEXRAYS(v14) = *v15;
                v18 = v15 + 1;
                v19 = v17 < v14;
                v20 = v17 - v14;
                if (v19 || v20 == 0)
                    break;
                LOBYTE_HEXRAYS(v14) = *v18;
                v15 = &v18[v14 + 1];
                v19 = v20 < v14;
                v17 = v20 - v14;
                if (v19 || v17 == 0)
                {
                    if (v17)
                    {
                        v15 += v17;
                        v14 = -(int)v17;
                        goto LABEL_18;
                    }
                    goto LABEL_14;
                }
            }
            if (v20)
            {
                v14 = -(int)v20;
                goto LABEL_15;
            }
            goto LABEL_17;
        }
        while (1)
        {
        LABEL_14:
            LOBYTE_HEXRAYS(v14) = *v15;
            v18 = v15 + 1;
        LABEL_15:
            v21 = __OFSUB__((_WORD)v16, (_WORD)v14);
            LOWORD_HEXRAYS(v16) = v16 - v14;
            if ((unsigned __int8)(((v16 & 0x8000u) != 0) ^ v21) | ((_WORD)v16 == 0))
            {
                LOWORD_HEXRAYS(v14) = v16 + v14;
                v13 -= v14;
                goto LABEL_26;
            }
            v13 -= v14;
        LABEL_17:
            LOBYTE_HEXRAYS(v14) = *v18;
            v15 = v18 + 1;
        LABEL_18:
            v21 = __OFSUB__((_WORD)v16, (_WORD)v14);
            LOWORD_HEXRAYS(v16) = v16 - v14;
            if ((unsigned __int8)(((v16 & 0x8000u) != 0) ^ v21) | ((_WORD)v16 == 0))
                break;
            v25 = v16;
            v22 = (unsigned __int16)v14;
            do
            {
                *(_BYTE *)--v13 = *v15++;
                --v22;
            } while (v22);
            v14 = 0;
            v16 = v25;
        }
        v26 = v16;
        v23 = (unsigned __int16)(v16 + v14);
        do
        {
            *(_BYTE *)--v13 = *v15++;
            --v23;
        } while (v23);
        v14 = 0;
        v16 = v26;
    LABEL_26:
        LOBYTE_HEXRAYS(v14) = *v27;
        v10 = &v27[v14];
        v13 += render_43B4A6_46BD04;
        v11 = _byteswap_ulong(v16);
        LOWORD_HEXRAYS(v11) = v11 - 1;
    } while ((_WORD)v11);
}

//----- (0043AAD2) --------------------------------------------------------
void render_draw_43AAD2(__int16 a1, _BYTE *a2, unsigned __int16 a3, unsigned __int16 a4, unsigned __int16 a5, unsigned __int16 a6, int a8, unsigned __int16 a9, unsigned __int16 a10, unsigned __int16 a11, unsigned __int16 a12, unsigned __int16 a13)
{
    _BYTE *v13; // edi@1
    _BYTE *v14; // esi@3
    int v15; // ecx@3
    int v16; // eax@4
    unsigned int v17; // ecx@6
    unsigned int v18; // ebx@6
    unsigned int v19; // eax@6
    unsigned int v20; // ebx@7
    char *v21; // esi@7
    unsigned int v22; // ecx@7
    unsigned int v23; // edx@7
    _BYTE *v24; // esi@8
    unsigned __int8 v25; // cf@8
    unsigned int v26; // edx@8
    char v27; // ah@11
    int v28; // eax@13
    char v29; // al@19
    _BYTE *v31; // [sp-18h] [bp-20h]@7
    int v32; // [sp+4h] [bp-4h]@0

    v13 = (_BYTE *)(a9 + a13 * a10 + a8);
    render_43B4A6_46BD04 = (unsigned __int16)(a13 - a11);
    v14 = a2;
    v15 = a4;
    if (a4)
    {
        v16 = 0;
        do
        {
            LOBYTE_HEXRAYS(v16) = *v14;
            v14 += v16;
            --v15;
        } while (v15);
    }
    HIBYTE_HEXRAYS(a1) = ((unsigned int)a5 << 8) / a11;
    v18 = _byteswap_ulong(a1);
    v17 = a12;
    BYTE1(v18) = ((unsigned int)a6 << 8) / a12;
    LOBYTE_HEXRAYS(v18) = 0;
    v19 = 0;
    while (1)
    {
        v20 = _byteswap_ulong(v18);
        LOBYTE_HEXRAYS(v20) = 0;
        v31 = v14;
        v21 = v14 + 1;
        v22 = _byteswap_ulong(v17);
        LOWORD_HEXRAYS(v22) = a11;
        v23 = a3;
        if (a3)
        {
            do
            {
                LOBYTE_HEXRAYS(v19) = *v21;
                v24 = v21 + 1;
                v25 = v23 < v19;
                v26 = v23 - v19;
                if (v25 | (v26 == 0))
                {
                    if (v26)
                    {
                        v28 = -(int)v26;
                        goto LABEL_15;
                    }
                    goto LABEL_18;
                }
                LOBYTE_HEXRAYS(v19) = *v24;
                v21 = &v24[v19 + 1];
                v25 = v26 < v19;
                v23 = v26 - v19;
            } while (!(v25 | (v23 == 0)));
            if (!v23)
                goto LABEL_14;
            v21 += v23;
            v27 = -(char)v23;
        LABEL_19:
            v29 = *v21++;
            while (1)
            {
                *v13++ = v29;
                LOWORD_HEXRAYS(v22) = v22 - 1;
                if (!(_WORD)v22)
                    break;
                v25 = __CFADD__(BYTE1(v20), (_BYTE)v20);
                LOBYTE_HEXRAYS(v20) = BYTE1(v20) + v20;
                if (v25)
                {
                    if (--v27)
                        goto LABEL_19;
                    goto LABEL_14;
                }
            }
        }
        else
        {
        LABEL_14:
            while (1)
            {
                LOBYTE_HEXRAYS(v28) = *v21;
                v24 = v21 + 1;
                if ((_BYTE)v28)
                    break;
            LABEL_18:
                v27 = *v24;
                v21 = v24 + 1;
                if (v27)
                    goto LABEL_19;
            }
        LABEL_15:
            while (1)
            {
                ++v13;
                LOWORD_HEXRAYS(v22) = v22 - 1;
                if (!(_WORD)v22)
                    break;
                v25 = __CFADD__(BYTE1(v20), (_BYTE)v20);
                LOBYTE_HEXRAYS(v20) = BYTE1(v20) + v20;
                if (v25)
                {
                    LOBYTE_HEXRAYS(v28) = v28 - 1;
                    if (!(_BYTE)v28)
                        goto LABEL_18;
                }
            }
        }
        v19 = 0;
        v14 = v31;
        v17 = _byteswap_ulong(v22);
        LOWORD_HEXRAYS(v17) = v17 - 1;
        if (!(_WORD)v17)
            return;
        v13 += render_43B4A6_46BD04;
        v18 = _byteswap_ulong(v20);
        v25 = __CFADD__(BYTE1(v18), (_BYTE)v18);
        LOBYTE_HEXRAYS(v18) = BYTE1(v18) + v18;
        if (v25)
        {
            LOBYTE_HEXRAYS(v19) = *v31;
            v14 = &v31[v19];
        }
    }
}

//----- (0043ABDE) --------------------------------------------------------
void render_draw_43ABDE(__int16 a1, _BYTE *a2, unsigned __int16 a3, unsigned __int16 a4, unsigned __int16 a5, unsigned __int16 a6, int a8, unsigned __int16 a9, unsigned __int16 a10, unsigned __int16 a11, unsigned __int16 a12, unsigned __int16 a13)
{
    _BYTE *v13; // edi@1
    _BYTE *v14; // esi@3
    int v15; // ecx@3
    int v16; // eax@4
    unsigned int v17; // ecx@6
    unsigned int v18; // ebx@6
    unsigned int v19; // eax@6
    unsigned int v20; // ebx@7
    char *v21; // esi@7
    unsigned int v22; // ecx@7
    unsigned int v23; // edx@7
    _BYTE *v24; // esi@8
    unsigned __int8 v25; // cf@8
    unsigned int v26; // edx@8
    char v27; // ah@11
    int v28; // eax@13
    char v29; // al@19
    _BYTE *v31; // [sp-18h] [bp-20h]@7
    int v32; // [sp+4h] [bp-4h]@0

    v13 = (_BYTE *)(a9 + a13 * a10 + a8);
    render_43B4A6_46BD04 = (unsigned __int16)(a13 - a11);
    v14 = a2;
    v15 = a4;
    if (a4)
    {
        v16 = 0;
        do
        {
            LOBYTE_HEXRAYS(v16) = *v14;
            v14 += v16;
            --v15;
        } while (v15);
    }
    HIBYTE_HEXRAYS(a1) = ((unsigned int)a5 << 8) / a11;
    v18 = _byteswap_ulong(a1);
    v17 = a12;
    word_46BD0E = ((unsigned int)a6 << 8) / a12;
    LOWORD_HEXRAYS(v18) = 0;
    v19 = 0;
    while (1)
    {
        v20 = _byteswap_ulong(v18);
        LOBYTE_HEXRAYS(v20) = 0;
        v31 = v14;
        v21 = v14 + 1;
        v22 = _byteswap_ulong(v17);
        LOWORD_HEXRAYS(v22) = a11;
        v23 = a3;
        if (a3)
        {
            do
            {
                LOBYTE_HEXRAYS(v19) = *v21;
                v24 = v21 + 1;
                v25 = v23 < v19;
                v26 = v23 - v19;
                if (v25 | (v26 == 0))
                {
                    if (v26)
                    {
                        v28 = -(int)v26;
                        goto LABEL_15;
                    }
                    goto LABEL_18;
                }
                LOBYTE_HEXRAYS(v19) = *v24;
                v21 = &v24[v19 + 1];
                v25 = v26 < v19;
                v23 = v26 - v19;
            } while (!(v25 | (v23 == 0)));
            if (!v23)
                goto LABEL_14;
            v21 += v23;
            v27 = -(char)v23;
        LABEL_19:
            v29 = *v21++;
            while (1)
            {
                *v13++ = v29;
                LOWORD_HEXRAYS(v22) = v22 - 1;
                if (!(_WORD)v22)
                    break;
                v25 = __CFADD__(BYTE1(v20), (_BYTE)v20);
                LOBYTE_HEXRAYS(v20) = BYTE1(v20) + v20;
                if (v25)
                {
                    if (--v27)
                        goto LABEL_19;
                    goto LABEL_14;
                }
            }
        }
        else
        {
        LABEL_14:
            while (1)
            {
                LOBYTE_HEXRAYS(v28) = *v21;
                v24 = v21 + 1;
                if ((_BYTE)v28)
                    break;
            LABEL_18:
                v27 = *v24;
                v21 = v24 + 1;
                if (v27)
                    goto LABEL_19;
            }
        LABEL_15:
            while (1)
            {
                ++v13;
                LOWORD_HEXRAYS(v22) = v22 - 1;
                if (!(_WORD)v22)
                    break;
                v25 = __CFADD__(BYTE1(v20), (_BYTE)v20);
                LOBYTE_HEXRAYS(v20) = BYTE1(v20) + v20;
                if (v25)
                {
                    LOBYTE_HEXRAYS(v28) = v28 - 1;
                    if (!(_BYTE)v28)
                        goto LABEL_18;
                }
            }
        }
        v19 = 0;
        v14 = v31;
        v17 = _byteswap_ulong(v22);
        LOWORD_HEXRAYS(v17) = v17 - 1;
        if (!(_WORD)v17)
            return;
        v13 += render_43B4A6_46BD04;
        v18 = _byteswap_ulong(v20);
        LOWORD_HEXRAYS(v18) = word_46BD0E + v18;
        do
        {
            LOBYTE_HEXRAYS(v19) = *v14;
            v14 += v19;
            --BYTE1(v18);
        } while (BYTE1(v18));
    }
}

//----- (0043ACF6) --------------------------------------------------------
void render_draw_43ACF6(unsigned int a1, _BYTE *a2, unsigned __int16 a3, unsigned __int16 a4, unsigned __int16 a5, unsigned __int16 a6, int a8, unsigned __int16 a9, unsigned __int16 a10, unsigned __int16 a11, unsigned __int16 a12, unsigned __int16 a13)
{
    _BYTE *v13; // edi@1
    _BYTE *v14; // esi@3
    int v15; // ecx@3
    int v16; // eax@4
    unsigned int v17; // ecx@6
    unsigned int v18; // ebx@6
    unsigned int v19; // ebx@7
    _BYTE *v20; // esi@7
    unsigned int v21; // ecx@7
    unsigned int v22; // eax@7
    unsigned int v23; // edx@7
    _BYTE *v24; // esi@8
    bool v25; // cf@8
    unsigned int v26; // edx@8
    _BYTE *v27; // esi@11
    unsigned __int8 v28; // ah@11
    unsigned __int8 v29; // ah@13
    unsigned __int8 v30; // ah@20
    char v31; // ah@25
    _BYTE *v32; // esi@25
    int v33; // eax@26
    _BYTE *v35; // [sp-18h] [bp-20h]@7
    int v36; // [sp+4h] [bp-4h]@0

    v13 = (_BYTE *)(a9 + a13 * a10 + a8);
    render_43B4A6_46BD04 = (unsigned __int16)(a13 - a11);
    v14 = a2;
    v15 = a4;
    if (a4)
    {
        v16 = 0;
        do
        {
            LOBYTE_HEXRAYS(v16) = *v14;
            v14 += v16;
            --v15;
        } while (v15);
    }
    word_46BD08 = ((unsigned int)a5 << 8) / a11;
    v18 = _byteswap_ulong(a1);
    dword_46BD0A = 0;
    v17 = a12;
    word_46BD0E = ((unsigned int)a6 << 8) / a12;
    LOWORD_HEXRAYS(v18) = 0;
    while (1)
    {
        v19 = _byteswap_ulong(v18);
        LOWORD_HEXRAYS(v19) = 0;
        v35 = v14;
        v20 = v14 + 1;
        v21 = _byteswap_ulong(v17);
        LOWORD_HEXRAYS(v21) = a11;
        v22 = 0;
        v23 = a3;
        if (a3)
        {
            do
            {
                LOBYTE_HEXRAYS(v22) = *v20;
                v24 = v20 + 1;
                v25 = v23 < v22;
                v26 = v23 - v22;
                if (v25 || v26 == 0)
                {
                    if (v26)
                    {
                        v29 = -(char)v26;
                        goto LABEL_17;
                    }
                    v28 = *v24;
                    v27 = v24 + 1;
                    if (!v28)
                        goto LABEL_24;
                    while (1)
                    {
                    LABEL_21:
                        LOBYTE_HEXRAYS(dword_46BD0A) = BYTE1(v19);
                        v27 += dword_46BD0A;
                    LABEL_22:
                        *v13++ = *v27;
                        LOWORD_HEXRAYS(v21) = v21 - 1;
                        if (!(_WORD)v21)
                            goto LABEL_26;
                        LOWORD_HEXRAYS(v19) = word_46BD08 + (unsigned __int8)v19;
                    LABEL_24:
                        v25 = v28 < BYTE1(v19);
                        v28 -= BYTE1(v19);
                        if (v25 || v28 == 0)
                            goto LABEL_25;
                    }
                }
                LOBYTE_HEXRAYS(v22) = *v24;
                v20 = &v24[v22 + 1];
                v25 = v26 < v22;
                v23 = v26 - v22;
            } while (!v25 && v23 != 0);
            if (v23)
            {
                v27 = &v20[v23];
                v28 = -(char)v23;
                goto LABEL_22;
            }
        }
        v29 = *v20;
        v24 = v20 + 1;
        if (!v29)
        {
        LABEL_19:
            while (2)
            {
                v25 = v29 < BYTE1(v19);
                v29 -= BYTE1(v19);
                if (v25 || v29 == 0)
                {
                    BYTE1(v19) = -v29;
                    v30 = *v24;
                    v27 = v24 + 1;
                    v25 = v30 < BYTE1(v19);
                    v28 = v30 - BYTE1(v19);
                    if (!v25 && v28 != 0)
                        goto LABEL_21;
                LABEL_25:
                    v31 = BYTE1(v19) + v28;
                    BYTE1(v19) -= v31;
                    LOBYTE_HEXRAYS(dword_46BD0A) = v31;
                    v32 = &v27[dword_46BD0A];
                    v29 = *v32;
                    v24 = v32 + 1;
                    continue;
                }
                break;
            }
        }
    LABEL_17:
        ++v13;
        LOWORD_HEXRAYS(v21) = v21 - 1;
        if ((_WORD)v21)
        {
            LOWORD_HEXRAYS(v19) = word_46BD08 + (unsigned __int8)v19;
            goto LABEL_19;
        }
    LABEL_26:
        v33 = 0;
        v14 = v35;
        v17 = _byteswap_ulong(v21);
        LOWORD_HEXRAYS(v17) = v17 - 1;
        if (!(_WORD)v17)
            return;
        v13 += render_43B4A6_46BD04;
        v18 = _byteswap_ulong(v19);
        LOWORD_HEXRAYS(v18) = word_46BD0E + v18;
        do
        {
            LOBYTE_HEXRAYS(v33) = *v14;
            v14 += v33;
            --BYTE1(v18);
        } while (BYTE1(v18));
    }
}

//----- (0043AE53) --------------------------------------------------------
void render_draw_43AE53(unsigned int a1, _BYTE *a2, unsigned __int16 a3, unsigned __int16 a4, unsigned __int16 a5, unsigned __int16 a6, int a8, unsigned __int16 a9, unsigned __int16 a10, unsigned __int16 a11, unsigned __int16 a12, unsigned __int16 a13)
{
    _BYTE *v13; // edi@1
    _BYTE *v14; // esi@3
    int v15; // ecx@3
    int v16; // eax@4
    unsigned int v17; // ecx@6
    unsigned int v18; // ebx@6
    unsigned int v19; // ebx@7
    _BYTE *v20; // esi@7
    unsigned int v21; // ecx@7
    unsigned int v22; // eax@7
    unsigned int v23; // edx@7
    _BYTE *v24; // esi@8
    unsigned __int8 v25; // cf@8
    unsigned int v26; // edx@8
    _BYTE *v27; // esi@11
    unsigned __int8 v28; // ah@11
    unsigned __int8 v29; // ah@13
    unsigned __int8 v30; // ah@20
    char v31; // ah@25
    _BYTE *v32; // esi@25
    _BYTE *v34; // [sp-18h] [bp-20h]@7
    int v35; // [sp+4h] [bp-4h]@0

    v13 = (_BYTE *)(a9 + a13 * a10 + a8);
    render_43B4A6_46BD04 = (unsigned __int16)(a13 - a11);
    v14 = a2;
    v15 = a4;
    if (a4)
    {
        v16 = 0;
        do
        {
            LOBYTE_HEXRAYS(v16) = *v14;
            v14 += v16;
            --v15;
        } while (v15);
    }
    word_46BD08 = ((unsigned int)a5 << 8) / a11;
    v18 = _byteswap_ulong(a1);
    dword_46BD0A = 0;
    v17 = a12;
    BYTE1(v18) = ((unsigned int)a6 << 8) / a12;
    LOBYTE_HEXRAYS(v18) = 0;
    while (1)
    {
        v19 = _byteswap_ulong(v18);
        LOWORD_HEXRAYS(v19) = 0;
        v34 = v14;
        v20 = v14 + 1;
        v21 = _byteswap_ulong(v17);
        LOWORD_HEXRAYS(v21) = a11;
        v22 = 0;
        v23 = a3;
        if (a3)
        {
            do
            {
                LOBYTE_HEXRAYS(v22) = *v20;
                v24 = v20 + 1;
                v25 = v23 < v22;
                v26 = v23 - v22;
                if (v25 | (v26 == 0))
                {
                    if (v26)
                    {
                        v29 = -(char)v26;
                        goto LABEL_17;
                    }
                    v28 = *v24;
                    v27 = v24 + 1;
                    if (!v28)
                        goto LABEL_24;
                    while (1)
                    {
                    LABEL_21:
                        LOBYTE_HEXRAYS(dword_46BD0A) = BYTE1(v19);
                        v27 += dword_46BD0A;
                    LABEL_22:
                        *v13++ = *v27;
                        LOWORD_HEXRAYS(v21) = v21 - 1;
                        if (!(_WORD)v21)
                            goto LABEL_26;
                        LOWORD_HEXRAYS(v19) = word_46BD08 + (unsigned __int8)v19;
                    LABEL_24:
                        v25 = v28 < BYTE1(v19);
                        v28 -= BYTE1(v19);
                        if (v25 | (v28 == 0))
                            goto LABEL_25;
                    }
                }
                LOBYTE_HEXRAYS(v22) = *v24;
                v20 = &v24[v22 + 1];
                v25 = v26 < v22;
                v23 = v26 - v22;
            } while (!(v25 | (v23 == 0)));
            if (v23)
            {
                v27 = &v20[v23];
                v28 = -(char)v23;
                goto LABEL_22;
            }
        }
        v29 = *v20;
        v24 = v20 + 1;
        if (!v29)
        {
        LABEL_19:
            while (2)
            {
                v25 = v29 < BYTE1(v19);
                v29 -= BYTE1(v19);
                if (v25 | (v29 == 0))
                {
                    BYTE1(v19) = -v29;
                    v30 = *v24;
                    v27 = v24 + 1;
                    v25 = v30 < BYTE1(v19);
                    v28 = v30 - BYTE1(v19);
                    if (!(v25 | (v28 == 0)))
                        goto LABEL_21;
                LABEL_25:
                    v31 = BYTE1(v19) + v28;
                    BYTE1(v19) -= v31;
                    LOBYTE_HEXRAYS(dword_46BD0A) = v31;
                    v32 = &v27[dword_46BD0A];
                    v29 = *v32;
                    v24 = v32 + 1;
                    continue;
                }
                break;
            }
        }
    LABEL_17:
        ++v13;
        LOWORD_HEXRAYS(v21) = v21 - 1;
        if ((_WORD)v21)
        {
            LOWORD_HEXRAYS(v19) = word_46BD08 + (unsigned __int8)v19;
            goto LABEL_19;
        }
    LABEL_26:
        v14 = v34;
        v17 = _byteswap_ulong(v21);
        LOWORD_HEXRAYS(v17) = v17 - 1;
        if (!(_WORD)v17)
            return;
        v13 += render_43B4A6_46BD04;
        v18 = _byteswap_ulong(v19);
        v25 = __CFADD__(BYTE1(v18), (_BYTE)v18);
        LOBYTE_HEXRAYS(v18) = BYTE1(v18) + v18;
        if (v25)
            v14 = &v34[*v34];
    }
}

//----- (0043AFAA) --------------------------------------------------------
void render_draw_43AFAA(__int16 a1, _BYTE *a2, unsigned __int16 a3, unsigned __int16 a4, unsigned __int16 a5, unsigned __int16 a6, int a8, __int16 a9, unsigned __int16 a10, unsigned __int16 a11, unsigned __int16 a12, unsigned __int16 a13)
{
    _BYTE *v13; // edi@1
    _BYTE *v14; // esi@3
    int v15; // ecx@3
    int v16; // eax@4
    unsigned int v17; // ecx@6
    unsigned int v18; // ebx@6
    unsigned int v19; // eax@6
    unsigned int v20; // ebx@7
    char *v21; // esi@7
    unsigned int v22; // ecx@7
    unsigned int v23; // edx@7
    _BYTE *v24; // esi@8
    unsigned __int8 v25; // cf@8
    unsigned int v26; // edx@8
    char v27; // ah@11
    int v28; // eax@13
    char v29; // al@19
    _BYTE *v31; // [sp-18h] [bp-20h]@7
    int v32; // [sp+4h] [bp-4h]@0

    v13 = (_BYTE *)((unsigned __int16)(a11 + a9 - 1) + a13 * a10 + a8);
    render_43B4A6_46BD04 = (unsigned __int16)(a11 + a13);
    v14 = a2;
    v15 = a4;
    if (a4)
    {
        v16 = 0;
        do
        {
            LOBYTE_HEXRAYS(v16) = *v14;
            v14 += v16;
            --v15;
        } while (v15);
    }
    HIBYTE_HEXRAYS(a1) = ((unsigned int)a5 << 8) / a11;
    v18 = _byteswap_ulong(a1);
    v17 = a12;
    BYTE1(v18) = ((unsigned int)a6 << 8) / a12;
    LOBYTE_HEXRAYS(v18) = 0;
    v19 = 0;
    while (1)
    {
        v20 = _byteswap_ulong(v18);
        LOBYTE_HEXRAYS(v20) = 0;
        v31 = v14;
        v21 = v14 + 1;
        v22 = _byteswap_ulong(v17);
        LOWORD_HEXRAYS(v22) = a11;
        v23 = a3;
        if (a3)
        {
            do
            {
                LOBYTE_HEXRAYS(v19) = *v21;
                v24 = v21 + 1;
                v25 = v23 < v19;
                v26 = v23 - v19;
                if (v25 | (v26 == 0))
                {
                    if (v26)
                    {
                        v28 = -(int)v26;
                        goto LABEL_15;
                    }
                    goto LABEL_18;
                }
                LOBYTE_HEXRAYS(v19) = *v24;
                v21 = &v24[v19 + 1];
                v25 = v26 < v19;
                v23 = v26 - v19;
            } while (!(v25 | (v23 == 0)));
            if (!v23)
                goto LABEL_14;
            v21 += v23;
            v27 = -(char)v23;
        LABEL_19:
            v29 = *v21++;
            while (1)
            {
                *v13-- = v29;
                LOWORD_HEXRAYS(v22) = v22 - 1;
                if (!(_WORD)v22)
                    break;
                v25 = __CFADD__(BYTE1(v20), (_BYTE)v20);
                LOBYTE_HEXRAYS(v20) = BYTE1(v20) + v20;
                if (v25)
                {
                    if (--v27)
                        goto LABEL_19;
                    goto LABEL_14;
                }
            }
        }
        else
        {
        LABEL_14:
            while (1)
            {
                LOBYTE_HEXRAYS(v28) = *v21;
                v24 = v21 + 1;
                if ((_BYTE)v28)
                    break;
            LABEL_18:
                v27 = *v24;
                v21 = v24 + 1;
                if (v27)
                    goto LABEL_19;
            }
        LABEL_15:
            while (1)
            {
                --v13;
                LOWORD_HEXRAYS(v22) = v22 - 1;
                if (!(_WORD)v22)
                    break;
                v25 = __CFADD__(BYTE1(v20), (_BYTE)v20);
                LOBYTE_HEXRAYS(v20) = BYTE1(v20) + v20;
                if (v25)
                {
                    LOBYTE_HEXRAYS(v28) = v28 - 1;
                    if (!(_BYTE)v28)
                        goto LABEL_18;
                }
            }
        }
        v19 = 0;
        v14 = v31;
        v17 = _byteswap_ulong(v22);
        LOWORD_HEXRAYS(v17) = v17 - 1;
        if (!(_WORD)v17)
            return;
        v13 += render_43B4A6_46BD04;
        v18 = _byteswap_ulong(v20);
        v25 = __CFADD__(BYTE1(v18), (_BYTE)v18);
        LOBYTE_HEXRAYS(v18) = BYTE1(v18) + v18;
        if (v25)
        {
            LOBYTE_HEXRAYS(v19) = *v31;
            v14 = &v31[v19];
        }
    }
}

//----- (0043B0BF) --------------------------------------------------------
void render_draw_43B0BF(__int16 a1, _BYTE *a2, unsigned __int16 a3, unsigned __int16 a4, unsigned __int16 a5, unsigned __int16 a6, int a8, __int16 a9, unsigned __int16 a10, unsigned __int16 a11, unsigned __int16 a12, unsigned __int16 a13)
{
    _BYTE *v13; // edi@1
    _BYTE *v14; // esi@3
    int v15; // ecx@3
    int v16; // eax@4
    unsigned int v17; // ecx@6
    unsigned int v18; // ebx@6
    unsigned int v19; // eax@6
    unsigned int v20; // ebx@7
    char *v21; // esi@7
    unsigned int v22; // ecx@7
    unsigned int v23; // edx@7
    _BYTE *v24; // esi@8
    unsigned __int8 v25; // cf@8
    unsigned int v26; // edx@8
    char v27; // ah@11
    int v28; // eax@13
    char v29; // al@19
    _BYTE *v31; // [sp-18h] [bp-20h]@7
    int v32; // [sp+4h] [bp-4h]@0

    v13 = (_BYTE *)((unsigned __int16)(a11 + a9 - 1) + a13 * a10 + a8);
    render_43B4A6_46BD04 = (unsigned __int16)(a11 + a13);
    v14 = a2;
    v15 = a4;
    if (a4)
    {
        v16 = 0;
        do
        {
            LOBYTE_HEXRAYS(v16) = *v14;
            v14 += v16;
            --v15;
        } while (v15);
    }
    HIBYTE_HEXRAYS(a1) = ((unsigned int)a5 << 8) / a11;
    v18 = _byteswap_ulong(a1);
    v17 = a12;
    word_46BD0E = ((unsigned int)a6 << 8) / a12;
    LOWORD_HEXRAYS(v18) = 0;
    v19 = 0;
    while (1)
    {
        v20 = _byteswap_ulong(v18);
        LOBYTE_HEXRAYS(v20) = 0;
        v31 = v14;
        v21 = v14 + 1;
        v22 = _byteswap_ulong(v17);
        LOWORD_HEXRAYS(v22) = a11;
        v23 = a3;
        if (a3)
        {
            do
            {
                LOBYTE_HEXRAYS(v19) = *v21;
                v24 = v21 + 1;
                v25 = v23 < v19;
                v26 = v23 - v19;
                if (v25 | (v26 == 0))
                {
                    if (v26)
                    {
                        v28 = -(int)v26;
                        goto LABEL_15;
                    }
                    goto LABEL_18;
                }
                LOBYTE_HEXRAYS(v19) = *v24;
                v21 = &v24[v19 + 1];
                v25 = v26 < v19;
                v23 = v26 - v19;
            } while (!(v25 | (v23 == 0)));
            if (!v23)
                goto LABEL_14;
            v21 += v23;
            v27 = -(char)v23;
        LABEL_19:
            v29 = *v21++;
            while (1)
            {
                *v13-- = v29;
                LOWORD_HEXRAYS(v22) = v22 - 1;
                if (!(_WORD)v22)
                    break;
                v25 = __CFADD__(BYTE1(v20), (_BYTE)v20);
                LOBYTE_HEXRAYS(v20) = BYTE1(v20) + v20;
                if (v25)
                {
                    if (--v27)
                        goto LABEL_19;
                    goto LABEL_14;
                }
            }
        }
        else
        {
        LABEL_14:
            while (1)
            {
                LOBYTE_HEXRAYS(v28) = *v21;
                v24 = v21 + 1;
                if ((_BYTE)v28)
                    break;
            LABEL_18:
                v27 = *v24;
                v21 = v24 + 1;
                if (v27)
                    goto LABEL_19;
            }
        LABEL_15:
            while (1)
            {
                --v13;
                LOWORD_HEXRAYS(v22) = v22 - 1;
                if (!(_WORD)v22)
                    break;
                v25 = __CFADD__(BYTE1(v20), (_BYTE)v20);
                LOBYTE_HEXRAYS(v20) = BYTE1(v20) + v20;
                if (v25)
                {
                    LOBYTE_HEXRAYS(v28) = v28 - 1;
                    if (!(_BYTE)v28)
                        goto LABEL_18;
                }
            }
        }
        v19 = 0;
        v14 = v31;
        v17 = _byteswap_ulong(v22);
        LOWORD_HEXRAYS(v17) = v17 - 1;
        if (!(_WORD)v17)
            return;
        v13 += render_43B4A6_46BD04;
        v18 = _byteswap_ulong(v20);
        LOWORD_HEXRAYS(v18) = word_46BD0E + v18;
        do
        {
            LOBYTE_HEXRAYS(v19) = *v14;
            v14 += v19;
            --BYTE1(v18);
        } while (BYTE1(v18));
    }
}

//----- (0043B1E0) --------------------------------------------------------
void render_draw_43B1E0(unsigned int a1, _BYTE *a2, unsigned __int16 a3, unsigned __int16 a4, unsigned __int16 a5, unsigned __int16 a6, int a8, __int16 a9, unsigned __int16 a10, unsigned __int16 a11, unsigned __int16 a12, unsigned __int16 a13)
{
    _BYTE *v13; // edi@1
    _BYTE *v14; // esi@3
    int v15; // ecx@3
    int v16; // eax@4
    unsigned int v17; // ecx@6
    unsigned int v18; // ebx@6
    unsigned int v19; // ebx@7
    _BYTE *v20; // esi@7
    unsigned int v21; // ecx@7
    unsigned int v22; // eax@7
    unsigned int v23; // edx@7
    _BYTE *v24; // esi@8
    bool v25; // cf@8
    unsigned int v26; // edx@8
    _BYTE *v27; // esi@11
    unsigned __int8 v28; // ah@11
    unsigned __int8 v29; // ah@13
    unsigned __int8 v30; // ah@20
    char v31; // ah@25
    _BYTE *v32; // esi@25
    int v33; // eax@26
    _BYTE *v35; // [sp-18h] [bp-20h]@7
    int v36; // [sp+4h] [bp-4h]@0

    v13 = (_BYTE *)((unsigned __int16)(a11 + a9 - 1) + a13 * a10 + a8);
    render_43B4A6_46BD04 = (unsigned __int16)(a11 + a13);
    v14 = a2;
    v15 = a4;
    if (a4)
    {
        v16 = 0;
        do
        {
            LOBYTE_HEXRAYS(v16) = *v14;
            v14 += v16;
            --v15;
        } while (v15);
    }
    word_46BD08 = ((unsigned int)a5 << 8) / a11;
    v18 = _byteswap_ulong(a1);
    dword_46BD0A = 0;
    v17 = a12;
    word_46BD0E = ((unsigned int)a6 << 8) / a12;
    LOWORD_HEXRAYS(v18) = 0;
    while (1)
    {
        v19 = _byteswap_ulong(v18);
        LOWORD_HEXRAYS(v19) = 0;
        v35 = v14;
        v20 = v14 + 1;
        v21 = _byteswap_ulong(v17);
        LOWORD_HEXRAYS(v21) = a11;
        v22 = 0;
        v23 = a3;
        if (a3)
        {
            do
            {
                LOBYTE_HEXRAYS(v22) = *v20;
                v24 = v20 + 1;
                v25 = v23 < v22;
                v26 = v23 - v22;
                if (v25 || v26 == 0)
                {
                    if (v26)
                    {
                        v29 = -(char)v26;
                        goto LABEL_17;
                    }
                    v28 = *v24;
                    v27 = v24 + 1;
                    if (!v28)
                        goto LABEL_24;
                    while (1)
                    {
                    LABEL_21:
                        LOBYTE_HEXRAYS(dword_46BD0A) = BYTE1(v19);
                        v27 += dword_46BD0A;
                    LABEL_22:
                        *v13-- = *v27;
                        LOWORD_HEXRAYS(v21) = v21 - 1;
                        if (!(_WORD)v21)
                            goto LABEL_26;
                        LOWORD_HEXRAYS(v19) = word_46BD08 + (unsigned __int8)v19;
                    LABEL_24:
                        v25 = v28 < BYTE1(v19);
                        v28 -= BYTE1(v19);
                        if (v25 || v28 == 0)
                            goto LABEL_25;
                    }
                }
                LOBYTE_HEXRAYS(v22) = *v24;
                v20 = &v24[v22 + 1];
                v25 = v26 < v22;
                v23 = v26 - v22;
            } while (!v25 && v23 != 0);
            if (v23)
            {
                v27 = &v20[v23];
                v28 = -(char)v23;
                goto LABEL_22;
            }
        }
        v29 = *v20;
        v24 = v20 + 1;
        if (!v29)
        {
        LABEL_19:
            while (2)
            {
                v25 = v29 < BYTE1(v19);
                v29 -= BYTE1(v19);
                if (v25 || v29 == 0)
                {
                    BYTE1(v19) = -v29;
                    v30 = *v24;
                    v27 = v24 + 1;
                    v25 = v30 < BYTE1(v19);
                    v28 = v30 - BYTE1(v19);
                    if (!v25 && v28 != 0)
                        goto LABEL_21;
                LABEL_25:
                    v31 = BYTE1(v19) + v28;
                    BYTE1(v19) -= v31;
                    LOBYTE_HEXRAYS(dword_46BD0A) = v31;
                    v32 = &v27[dword_46BD0A];
                    v29 = *v32;
                    v24 = v32 + 1;
                    continue;
                }
                break;
            }
        }
    LABEL_17:
        --v13;
        LOWORD_HEXRAYS(v21) = v21 - 1;
        if ((_WORD)v21)
        {
            LOWORD_HEXRAYS(v19) = word_46BD08 + (unsigned __int8)v19;
            goto LABEL_19;
        }
    LABEL_26:
        v33 = 0;
        v14 = v35;
        v17 = _byteswap_ulong(v21);
        LOWORD_HEXRAYS(v17) = v17 - 1;
        if (!(_WORD)v17)
            return;
        v13 += render_43B4A6_46BD04;
        v18 = _byteswap_ulong(v19);
        LOWORD_HEXRAYS(v18) = word_46BD0E + v18;
        do
        {
            LOBYTE_HEXRAYS(v33) = *v14;
            v14 += v33;
            --BYTE1(v18);
        } while (BYTE1(v18));
    }
}

//----- (0043B346) --------------------------------------------------------
void render_draw_43B346(unsigned int a1, _BYTE *a2, unsigned __int16 a3, unsigned __int16 a4, unsigned __int16 a5, unsigned __int16 a6, int a8, __int16 a9, unsigned __int16 a10, unsigned __int16 a11, unsigned __int16 a12, unsigned __int16 a13)
{
    _BYTE *v13; // edi@1
    _BYTE *v14; // esi@3
    int v15; // ecx@3
    int v16; // eax@4
    unsigned int v17; // ecx@6
    unsigned int v18; // ebx@6
    unsigned int v19; // ebx@7
    _BYTE *v20; // esi@7
    unsigned int v21; // ecx@7
    unsigned int v22; // eax@7
    unsigned int v23; // edx@7
    _BYTE *v24; // esi@8
    unsigned __int8 v25; // cf@8
    unsigned int v26; // edx@8
    _BYTE *v27; // esi@11
    unsigned __int8 v28; // ah@11
    unsigned __int8 v29; // ah@13
    unsigned __int8 v30; // ah@20
    char v31; // ah@25
    _BYTE *v32; // esi@25
    _BYTE *v34; // [sp-18h] [bp-20h]@7
    int v35; // [sp+4h] [bp-4h]@0

    v13 = (_BYTE *)((unsigned __int16)(a11 + a9 - 1) + a13 * a10 + a8);
    render_43B4A6_46BD04 = (unsigned __int16)(a11 + a13);
    v14 = a2;
    v15 = a4;
    if (a4)
    {
        v16 = 0;
        do
        {
            LOBYTE_HEXRAYS(v16) = *v14;
            v14 += v16;
            --v15;
        } while (v15);
    }
    word_46BD08 = ((unsigned int)a5 << 8) / a11;
    v18 = _byteswap_ulong(a1);
    dword_46BD0A = 0;
    v17 = a12;
    BYTE1(v18) = ((unsigned int)a6 << 8) / a12;
    LOBYTE_HEXRAYS(v18) = 0;
    while (1)
    {
        v19 = _byteswap_ulong(v18);
        LOWORD_HEXRAYS(v19) = 0;
        v34 = v14;
        v20 = v14 + 1;
        v21 = _byteswap_ulong(v17);
        LOWORD_HEXRAYS(v21) = a11;
        v22 = 0;
        v23 = a3;
        if (a3)
        {
            do
            {
                LOBYTE_HEXRAYS(v22) = *v20;
                v24 = v20 + 1;
                v25 = v23 < v22;
                v26 = v23 - v22;
                if (v25 | (v26 == 0))
                {
                    if (v26)
                    {
                        v29 = -(char)v26;
                        goto LABEL_17;
                    }
                    v28 = *v24;
                    v27 = v24 + 1;
                    if (!v28)
                        goto LABEL_24;
                    while (1)
                    {
                    LABEL_21:
                        LOBYTE_HEXRAYS(dword_46BD0A) = BYTE1(v19);
                        v27 += dword_46BD0A;
                    LABEL_22:
                        *v13-- = *v27;
                        LOWORD_HEXRAYS(v21) = v21 - 1;
                        if (!(_WORD)v21)
                            goto LABEL_26;
                        LOWORD_HEXRAYS(v19) = word_46BD08 + (unsigned __int8)v19;
                    LABEL_24:
                        v25 = v28 < BYTE1(v19);
                        v28 -= BYTE1(v19);
                        if (v25 | (v28 == 0))
                            goto LABEL_25;
                    }
                }
                LOBYTE_HEXRAYS(v22) = *v24;
                v20 = &v24[v22 + 1];
                v25 = v26 < v22;
                v23 = v26 - v22;
            } while (!(v25 | (v23 == 0)));
            if (v23)
            {
                v27 = &v20[v23];
                v28 = -(char)v23;
                goto LABEL_22;
            }
        }
        v29 = *v20;
        v24 = v20 + 1;
        if (!v29)
        {
        LABEL_19:
            while (2)
            {
                v25 = v29 < BYTE1(v19);
                v29 -= BYTE1(v19);
                if (v25 | (v29 == 0))
                {
                    BYTE1(v19) = -v29;
                    v30 = *v24;
                    v27 = v24 + 1;
                    v25 = v30 < BYTE1(v19);
                    v28 = v30 - BYTE1(v19);
                    if (!(v25 | (v28 == 0)))
                        goto LABEL_21;
                LABEL_25:
                    v31 = BYTE1(v19) + v28;
                    BYTE1(v19) -= v31;
                    LOBYTE_HEXRAYS(dword_46BD0A) = v31;
                    v32 = &v27[dword_46BD0A];
                    v29 = *v32;
                    v24 = v32 + 1;
                    continue;
                }
                break;
            }
        }
    LABEL_17:
        --v13;
        LOWORD_HEXRAYS(v21) = v21 - 1;
        if ((_WORD)v21)
        {
            LOWORD_HEXRAYS(v19) = word_46BD08 + (unsigned __int8)v19;
            goto LABEL_19;
        }
    LABEL_26:
        v14 = v34;
        v17 = _byteswap_ulong(v21);
        LOWORD_HEXRAYS(v17) = v17 - 1;
        if (!(_WORD)v17)
            return;
        v13 += render_43B4A6_46BD04;
        v18 = _byteswap_ulong(v19);
        v25 = __CFADD__(BYTE1(v18), (_BYTE)v18);
        LOBYTE_HEXRAYS(v18) = BYTE1(v18) + v18;
        if (v25)
            v14 = &v34[*v34];
    }
}

//----- (0043B4A6) --------------------------------------------------------
void render_draw_43B4A6(unsigned __int8 *sprite_data, unsigned __int16 clipped_x, unsigned __int16 clipped_y, unsigned __int16 clipped_width, __int16 clipped_height, unsigned __int8 *palette, int dst_surface, unsigned __int16 dst_surface_x, unsigned __int16 dst_surface_y, unsigned __int16 dst_surface_pitch)
{
    unsigned __int8 *p1xels; // esi@1
    unsigned int v12; // ecx@1
    int v13; // eax@2
    unsigned __int8 *dst; // edi@4
    unsigned int data; // eax@6
    unsigned __int8 *pAlette; // edx@6
    _BYTE *p1xels_next; // esi@7
    unsigned int bswap_cliph_clipw; // ecx@7
    unsigned int v19; // ebx@7
    _BYTE *p1xels_next_next; // esi@8
    bool v21; // cf@8
    unsigned int v22; // ebx@8
    unsigned __int8 v23; // of@15
    int num_pixels; // ecx@19
    int v25; // ecx@23
    unsigned int v27; // [sp-1Ch] [bp-24h]@19
    unsigned int v28; // [sp-1Ch] [bp-24h]@23
    unsigned __int8 *p1xels_; // [sp-18h] [bp-20h]@7
    int v30; // [sp+4h] [bp-4h]@0

    p1xels = sprite_data;
    v12 = clipped_y;
    if (clipped_y)
    {
        v13 = 0;
        do
        {
            LOBYTE_HEXRAYS(v13) = *p1xels;
            p1xels += v13;
            --v12;
        } while (v12);
    }
    dst = (unsigned __int8 *)(dst_surface_x + dst_surface_pitch * dst_surface_y + dst_surface);
    render_43B4A6_46BD04 = dst_surface_pitch - clipped_width;
    data = 0;
    LOWORD_HEXRAYS(v12) = clipped_height;
    pAlette = (unsigned __int8 *)((unsigned int)(palette + 255) & 0xFFFFFF00);
    do
    {
        p1xels_ = p1xels;
        p1xels_next = (char *)p1xels + 1;
        bswap_cliph_clipw = _byteswap_ulong(v12);
        LOWORD_HEXRAYS(bswap_cliph_clipw) = clipped_width;
        v19 = clipped_x;
        if (clipped_x)
        {
            while (1)
            {
                LOBYTE_HEXRAYS(data) = *p1xels_next;
                p1xels_next_next = p1xels_next + 1;
                v21 = v19 < data;
                v22 = v19 - data;
                if (v21 || v22 == 0)
                    break;
                LOBYTE_HEXRAYS(data) = *p1xels_next_next;
                p1xels_next = &p1xels_next_next[data + 1];
                v21 = v22 < data;
                v19 = v22 - data;
                if (v21 || v19 == 0)
                {
                    if (v19)
                    {
                        p1xels_next += v19;
                        data = -(int)v19;
                        goto LABEL_18;
                    }
                    goto LABEL_14;
                }
            }
            if (v22)
            {
                data = -(int)v22;
                goto LABEL_15;
            }
            goto LABEL_17;
        }
        while (1)
        {
        LABEL_14:
            LOBYTE_HEXRAYS(data) = *p1xels_next;              // row x offset
            p1xels_next_next = p1xels_next + 1;
        LABEL_15:
            v23 = __OFSUB__((_WORD)bswap_cliph_clipw, (_WORD)data);
            LOWORD_HEXRAYS(bswap_cliph_clipw) = bswap_cliph_clipw - data;
            if ((unsigned __int8)(((bswap_cliph_clipw & 0x8000u) != 0) ^ v23) | ((_WORD)bswap_cliph_clipw == 0))
            {
                LOWORD_HEXRAYS(data) = bswap_cliph_clipw + data;
                dst += data;
                goto LABEL_26;
            }
            dst += data;
        LABEL_17:
            LOBYTE_HEXRAYS(data) = *p1xels_next_next;
            p1xels_next = p1xels_next_next + 1;
        LABEL_18:
            v23 = __OFSUB__((_WORD)bswap_cliph_clipw, (_WORD)data);
            LOWORD_HEXRAYS(bswap_cliph_clipw) = bswap_cliph_clipw - data;
            if ((unsigned __int8)(((bswap_cliph_clipw & 0x8000u) != 0) ^ v23) | ((_WORD)bswap_cliph_clipw == 0))
                break;
            v27 = bswap_cliph_clipw;
            num_pixels = (unsigned __int16)data;
            do
            {
                LOBYTE_HEXRAYS(pAlette) = *p1xels_next;
                *dst = *pAlette;
                ++p1xels_next;
                ++dst;
                --num_pixels;
            } while (num_pixels);
            data = 0;
            bswap_cliph_clipw = v27;
        }
        v28 = bswap_cliph_clipw;
        v25 = (unsigned __int16)(bswap_cliph_clipw + data);
        do
        {
            LOBYTE_HEXRAYS(pAlette) = *p1xels_next;
            *dst = *pAlette;
            ++p1xels_next;
            ++dst;
            --v25;
        } while (v25);
        bswap_cliph_clipw = v28;
    LABEL_26:
        data = *p1xels_;
        p1xels = &p1xels_[data];
        dst += render_43B4A6_46BD04;
        v12 = _byteswap_ulong(bswap_cliph_clipw);
        LOWORD_HEXRAYS(v12) = v12 - 1;
    } while ((_WORD)v12);
}

//----- (0043B59F) --------------------------------------------------------
void render_draw_43B59F(
    bool _CF, char _ZF, char _SF, unsigned __int8 _OF, unsigned __int8 *sprite_data, unsigned __int16 x,
    unsigned __int16 y, unsigned __int16 width, __int16 height, unsigned __int8 *palette,
    unsigned __int8 *dst_surface, __int16 dst_surface_x, unsigned __int16 dst_surface_y, unsigned __int16 dst_surface_pitch
)
{
    unsigned __int8 *spr1te_data; // esi@1
    unsigned int v16; // ecx@1
    int v17; // eax@2
    unsigned __int8 *dst; // edi@4
    unsigned int v19; // eax@6
    unsigned __int8 *pAlette; // edx@6
    _BYTE *v21; // esi@7
    unsigned int v22; // ecx@7
    unsigned int v23; // ebx@7
    _BYTE *v24; // esi@8
    unsigned int v25; // ebx@8
    int v26; // ecx@19
    int v27; // ecx@23
    unsigned int v29; // [sp-1Eh] [bp-26h]@19
    unsigned int v30; // [sp-1Eh] [bp-26h]@23
    unsigned __int8 *v31; // [sp-1Ah] [bp-22h]@7
    int v32; // [sp+4h] [bp-4h]@0

    spr1te_data = sprite_data;
    v16 = y;
    if (y)
    {
        v17 = 0;
        do
        {
            LOBYTE_HEXRAYS(v17) = *spr1te_data;
            spr1te_data += v17;
            --v16;
        } while (v16);
    }
    dst = &dst_surface[dst_surface_pitch * dst_surface_y] + (unsigned __int16)(width + dst_surface_x);
    render_43B4A6_46BD04 = width + dst_surface_pitch;
    v19 = 0;
    LOWORD_HEXRAYS(v16) = height;
    pAlette = (unsigned __int8 *)((unsigned int)(palette + 255) & 0xFFFFFF00);
    do
    {
        v31 = spr1te_data;
        v21 = (char *)spr1te_data + 1;
        v22 = _byteswap_ulong(v16);
        LOWORD_HEXRAYS(v22) = width;
        v23 = x;
        if (x)
        {
            while (1)
            {
                LOBYTE_HEXRAYS(v19) = *v21;
                v24 = v21 + 1;
                _CF = v23 < v19;
                v25 = v23 - v19;
                if (_CF || v25 == 0)
                    break;
                LOBYTE_HEXRAYS(v19) = *v24;
                v21 = &v24[v19 + 1];
                _CF = v25 < v19;
                v23 = v25 - v19;
                if (_CF || v23 == 0)
                {
                    if (v23)
                    {
                        v21 += v23;
                        v19 = -(int)v23;
                        goto LABEL_18;
                    }
                    goto LABEL_14;
                }
            }
            if (v25)
            {
                v19 = -(int)v25;
                goto LABEL_15;
            }
            goto LABEL_17;
        }
        while (1)
        {
        LABEL_14:
            LOBYTE_HEXRAYS(v19) = *v21;
            v24 = v21 + 1;
        LABEL_15:
            _OF = __OFSUB__((_WORD)v22, (_WORD)v19);
            LOWORD_HEXRAYS(v22) = v22 - v19;
            if ((unsigned __int8)(((v22 & 0x8000u) != 0) ^ _OF) | ((_WORD)v22 == 0))
            {
                LOWORD_HEXRAYS(v19) = v22 + v19;
                dst -= v19;
                goto LABEL_26;
            }
            dst -= v19;
        LABEL_17:
            LOBYTE_HEXRAYS(v19) = *v24;
            v21 = v24 + 1;
        LABEL_18:
            _OF = __OFSUB__((_WORD)v22, (_WORD)v19);
            LOWORD_HEXRAYS(v22) = v22 - v19;
            if ((unsigned __int8)(((v22 & 0x8000u) != 0) ^ _OF) | ((_WORD)v22 == 0))
                break;
            v29 = v22;
            v26 = (unsigned __int16)v19;
            do
            {
                --dst;
                LOBYTE_HEXRAYS(pAlette) = *v21;
                *dst = *pAlette;
                ++v21;
                --v26;
            } while (v26);
            v19 = 0;
            v22 = v29;
        }
        v30 = v22;
        v27 = (unsigned __int16)(v22 + v19);
        do
        {
            --dst;
            LOBYTE_HEXRAYS(pAlette) = *v21;
            *dst = *pAlette;
            ++v21;
            --v27;
        } while (v27);
        v19 = 0;
        v22 = v30;
    LABEL_26:
        LOBYTE_HEXRAYS(v19) = *v31;
        spr1te_data = &v31[v19];
        dst += render_43B4A6_46BD04;
        v16 = _byteswap_ulong(v22);
        LOWORD_HEXRAYS(v16) = v16 - 1;
    } while ((_WORD)v16);

    return;
}

//----- (0043B6B0) --------------------------------------------------------
bool draw_list_alloc()
{
    draw_list = new DrawJob[3000];
    if (draw_list)
    {
        draw_list_free_pool = draw_list;

        for (int i = 0; i < 3000; ++i)
        {
            draw_list[i].next = &draw_list[i + 1];
        }
        draw_list[0].prev = (DrawJob *)&draw_list_free_pool;
        draw_list[2999].next = (DrawJob *)&draw_list_free_pool;

        draw_list_47C5D8.prev = (DrawJob *)&draw_list_47C5D8;
        draw_list_47C5D8.next = (DrawJob *)&draw_list_47C5D8;

        draw_list_47C5E8.prev = (DrawJob *)&draw_list_47C5E8;
        draw_list_47C5E8.next = (DrawJob *)&draw_list_47C5E8;
        return true;
    }
    return false;
}

//----- (0043B710) --------------------------------------------------------
DrawJob *draw_list_add(void *param, void(*on_update_handler)(void *, DrawJob *))
{
    DrawJob *result; // eax@1

    result = draw_list_free_pool;
    if ((DrawJob **)draw_list_free_pool == &draw_list_free_pool)
    {
        result = 0;
    }
    else
    {
        draw_list_free_pool = draw_list_free_pool->next;

        result->next = (DrawJob *)&draw_list_47C5E8;
        result->prev = draw_list_47C5E8.prev;
        draw_list_47C5E8.prev->next = result;
        draw_list_47C5E8.prev = result;

        result->job_details.params = render_default_stru1;
        result->on_update_handler_param = param;
        result->job_details.field_8 = 0;
        result->job_details.image = 0;
        result->field_34 = 0;
        result->field_38 = 0;
        result->job_details.palette = 0;
        result->job_details.flags = 0;
        result->flags = 0;
        result->on_update_handler = on_update_handler;
    }
    return result;
}

//----- (0043B770) --------------------------------------------------------
bool draw_list_update_and_draw()
{
    DrawJob *v0; // eax@2
    DrawJob *v1; // ecx@2
    DrawJob *v2; // edx@5
    BOOL result; // eax@10

    if (render_should_render())
    {
        draw_list_update(&draw_list_47C5D8);
        draw_list_z_order(&draw_list_47C5D8);
        draw_list_update(&draw_list_47C5E8);
        draw_list_z_order(&draw_list_47C5E8);
        v0 = draw_list_47C5E8.next;
        v1 = draw_list_47C5D8.next;
        if (draw_list_47C5E8.next != (DrawJob *)&draw_list_47C5E8)
        {
            do
            {
                if (v1 == (DrawJob *)&draw_list_47C5D8)
                    break;
                if (v0->job_details.z_index > v1->job_details.z_index)
                {
                    v1 = v1->next;
                }
                else
                {
                    v2 = v0->next;
                    v0->prev = v1->prev;
                    v1->prev->next = v0;
                    v1->prev = v0;
                    v0->next = v1;
                    v0 = v2;
                }
            } while (v0 != (DrawJob *)&draw_list_47C5E8);

            if (v0 != (DrawJob *)&draw_list_47C5E8)
            {
                v0->prev = draw_list_47C5D8.prev;
                draw_list_47C5D8.prev->next = v0;
                draw_list_47C5D8.prev = draw_list_47C5E8.prev;
                draw_list_47C5E8.prev->next = (DrawJob *)&draw_list_47C5D8;
            }
        }
        draw_list_47C5E8.prev = (DrawJob *)&draw_list_47C5E8;
        draw_list_47C5E8.next = (DrawJob *)&draw_list_47C5E8;
        render_draw_list(&draw_list_47C5D8);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (0043B840) --------------------------------------------------------
void draw_list_update(DrawJobList *list)
{
    DrawJob *end; // ebp@1
    DrawJob *next; // esi@1
    int is_list_47C5E8; // edi@1
    DrawJob *v4; // eax@6
    void(*v5)(void *, DrawJob *); // eax@7

    end = (DrawJob *)list;
    next = list->next;
    is_list_47C5E8 = list == &draw_list_47C5E8;

    while (next != end)
    {
        if (is_list_47C5E8)
        {
            if (next->flags & 0x80000000)
                goto _delete;
            if (is_list_47C5E8)
                goto LABEL_7;
        }
        if (!(next->job_details.flags & 0x80000000))
        {
        LABEL_7:
            v5 = next->on_update_handler;
            if (v5)
            {
                if (!(next->flags & 0x80000000))
                    v5(next->on_update_handler_param, next);
            }
            next->job_details.flags = next->flags;
            next = next->next;
            continue;
        }
    _delete:
        next->prev->next = next->next;
        next->next->prev = next->prev;
        v4 = next->next;
        next->next = draw_list_free_pool;
        draw_list_free_pool = next;
        next = v4;
    }
}

//----- (0043B8C0) --------------------------------------------------------
void draw_list_z_order(DrawJobList *list)
{
    DrawJob *v1; // esi@1
    DrawJob *v2; // eax@2
    int v3; // edi@2
    DrawJob *v4; // edx@3

    v1 = list->prev;
    do
    {
        v2 = list->next;
        v3 = 1;
        while (v2 != v1)
        {
            v4 = v2->next;
            if (v2->job_details.z_index <= v2->next->job_details.z_index)
            {
                v2 = v2->next;
            }
            else
            {
                v2->prev->next = v4;
                v4->next->prev = v2;
                v2->next = v4->next;
                v4->prev = v2->prev;
                v2->prev = v4;
                v4->next = v2;
                if (v4 == v1)
                    v1 = v2;
                v3 = 0;
            }
        }
        v1 = v1->prev;
    } while (!v3);
}

//----- (0043B910) --------------------------------------------------------
void draw_list_free()
{
    DrawJob *i; // eax@1
    DrawJob *j; // eax@3
    DrawJob *v2; // eax@6
    DrawJob *v3; // ecx@6
    DrawJob *v4; // edx@9
    int v5; // eax@14

    for (i = draw_list_47C5D8.next; i != (DrawJob *)&draw_list_47C5D8; i = i->next)
        i->flags |= 0x80000000;
    for (j = draw_list_47C5E8.next; j != (DrawJob *)&draw_list_47C5E8; j = j->next)
        j->flags |= 0x80000000;
    while (1)
    {
        if (render_should_render())
        {
            draw_list_update(&draw_list_47C5D8);
            draw_list_z_order(&draw_list_47C5D8);
            draw_list_update(&draw_list_47C5E8);
            draw_list_z_order(&draw_list_47C5E8);
            v2 = draw_list_47C5E8.next;
            v3 = draw_list_47C5D8.next;
            if (draw_list_47C5E8.next != (DrawJob *)&draw_list_47C5E8)
            {
                do
                {
                    if (v3 == (DrawJob *)&draw_list_47C5D8)
                        break;
                    if (v2->job_details.z_index > v3->job_details.z_index)
                    {
                        v3 = v3->next;
                    }
                    else
                    {
                        v4 = v2->next;
                        v2->prev = v3->prev;
                        v3->prev->next = v2;
                        v3->prev = v2;
                        v2->next = v3;
                        v2 = v4;
                    }
                } while (v2 != (DrawJob *)&draw_list_47C5E8);
                if (v2 != (DrawJob *)&draw_list_47C5E8)
                {
                    v2->prev = draw_list_47C5D8.prev;
                    draw_list_47C5D8.prev->next = v2;
                    draw_list_47C5D8.prev = draw_list_47C5E8.prev;
                    draw_list_47C5E8.prev->next = (DrawJob *)&draw_list_47C5D8;
                }
            }
            draw_list_47C5E8.prev = (DrawJob *)&draw_list_47C5E8;
            draw_list_47C5E8.next = (DrawJob *)&draw_list_47C5E8;
            render_draw_list(&draw_list_47C5D8);
            v5 = 1;
        }
        else
        {
            v5 = 0;
        }
        if (v5)
            break;
        TimedMessagePump();
    }
    while (!render_should_render())
        TimedMessagePump();
    free(draw_list);
}


void render_on_wm_paint(struct tagRECT *a1)
{
    /*if (pdds_primary)
    {
        if (pdds_backbuffer)
        {
            pdds_primary->Blt(a1, pdds_backbuffer, a1, 0, 0);
        }
    }*/
}


//----- (00431940) --------------------------------------------------------
void render_sw_free_palette()
{
    HPALETTE v0; // eax@3

    if (global_wnd_bpp == 8)
    {
        if (render_sw_default_palette)
        {
            v0 = SelectPalette(render_sw_hdc, render_sw_default_palette, 0);
            DeleteObject(v0);
        }
        render_sw_palette = 0;
    }
}

//----- (00431980) --------------------------------------------------------
void _431980_update_primary_palette(PALETTEENTRY *palette_entries)
{
    PALETTEENTRY *v1; // edx@1
    int v2; // eax@4
    char *v3; // ecx@9
    BYTE *v4; // eax@9
    int v5; // eax@11
    _BYTE *v6; // ecx@14
    int v7; // eax@14
    HPALETTE v8; // esi@16
    int v9; // [sp-Ch] [bp-410h]@4
    _BYTE v10[1024]; // [sp+0h] [bp-404h]@14
    int v11; // [sp+400h] [bp-4h]@14

    v1 = palette_entries;
    if (global_wnd_bpp == 8)
    {
        dword_47C018 = 0;
        dword_468FD4 = 1;
        dword_468FD8 = 2;
        dword_468FDC = 4;
        if (palette_entries)
            memcpy(_47B408_palette_entries, palette_entries, sizeof(_47B408_palette_entries));
        else
            v1 = _47B408_palette_entries;
        if (global_fullscreen == 1)
        {
            v3 = (char *)&RenderDD_primary_palette_values[0].peGreen;
            v4 = &v1->peBlue;
            do
            {
                v4[&RenderDD_primary_palette_values[0].peGreen - (BYTE *)v1] = 0;
                *(v3 - 1) = *(v4 - 2);
                *v3 = *(v4 - 1);
                v4[(char *)RenderDD_primary_palette_values - (char *)v1] = *v4;
                v3 += 4;
                v4 += 4;
            } while ((int)v3 < (int)&render_sw_hdc + 1);
            /*v5 = render_dd_is_primary_surface_lost();
            if (!v5)
            {
                v5 = (int)pddpal_primary;
                if (pddpal_primary)
                    v5 = pddpal_primary->SetEntries(0, 0, 256, RenderDD_primary_palette_values);
            }*/
        }
        else
        {
            v6 = v10;
            v7 = (int)&v1->peGreen;
            v11 = 256;
            do
            {
                *(_BYTE *)(&v10[2] - (_BYTE *)v1 + v7) = 0;
                *v6 = *(_BYTE *)(v7 + 1);
                *(_BYTE *)(v10 - (_BYTE *)v1 + v7) = *(_BYTE *)v7;
                *(_BYTE *)(&v10[1] - (_BYTE *)v1 + v7) = *(_BYTE *)(v7 - 1);
                v6 += 4;
                v7 += 4;
                --v11;
            } while (v11);
            v8 = render_sw_palette;
            if (render_sw_palette)
            {
                render_sw_palette = _431B60_create_palette((PALETTEENTRY *)v10, 256);
                SelectPalette(render_sw_hdc, render_sw_palette, 0);
                DeleteObject(v8);
            }
            else
            {
                render_sw_palette = _431B60_create_palette((PALETTEENTRY *)v10, 256);
                render_sw_default_palette = SelectPalette(render_sw_hdc, render_sw_palette, 0);
            }
            v5 = RealizePalette(render_sw_hdc);
        }
    }
}

//----- (00431B60) --------------------------------------------------------
HPALETTE _431B60_create_palette(PALETTEENTRY *a1, int num_entries)
{
    PALETTEENTRY *v2; // ebx@1
    int v3; // ecx@1
    char *v4; // esi@1
    char *v5; // edi@1
    int v6; // eax@1
    char *v7; // ebp@1
    int v8; // edx@1
    int v9; // eax@4
    int v10; // edx@4
    int v11; // eax@6
    int v12; // edx@6
    int v14; // [sp+14h] [bp-408h]@1
    struct
    {
        LOGPALETTE plpal; // [sp+18h] [bp-404h]@1
        char pixels[0x400];
    } v15;

    v2 = a1;
    v15.plpal.palVersion = 768;
    v15.plpal.palNumEntries = 256;
    memset(v15.plpal.palPalEntry, 0, 0x400u);
    v14 = num_entries - 10;
    v3 = &v15.plpal.palPalEntry[0].peBlue - (BYTE *)a1;
    v4 = (char *)((char *)&v15.plpal.palNumEntries + 1 - (char *)v2);
    v5 = (char *)((char *)v15.plpal.palPalEntry - (char *)v2);
    v6 = (int)&v2->peGreen;
    v7 = (char *)(&v15.plpal.palPalEntry[0].peGreen - (BYTE *)v2);
    v8 = 10;
    do
    {
        *(_BYTE *)(v3 + v6) = 0;
        *(_BYTE *)(v6 + 1) = v4[v6];
        *(_BYTE *)v6 = v5[v6];
        *(_BYTE *)(v6 - 1) = v7[v6];
        v6 += 4;
        --v8;
    } while (v8);
    if (v14 > 10)
    {
        v9 = (int)&v2[10].peGreen;
        v10 = v14 - 10;
        do
        {
            v4[v9] = *(_BYTE *)(v9 + 1);
            v5[v9] = *(_BYTE *)v9;
            v7[v9] = *(_BYTE *)(v9 - 1);
            *(_BYTE *)(v9 + v3) = 5;
            v9 += 4;
            --v10;
        } while (v10);
    }
    v11 = (int)&v2[246].peGreen;
    v12 = 10;
    do
    {
        *(_BYTE *)(v11 + v3) = 0;
        *(_BYTE *)(v11 + 1) = v4[v11];
        *(_BYTE *)v11 = v5[v11];
        *(_BYTE *)(v11 - 1) = v7[v11];
        v11 += 4;
        --v12;
    } while (v12);
    return CreatePalette(&v15.plpal);
}

//----- (00431C40) --------------------------------------------------------
void _431C40_on_WM_ACTIVATEAPP_software_render(void *result)
{
    int v1; // edx@2
    int i; // ecx@2
    int v3; // eax@9
    PALETTEENTRY *v4; // edx@10
    char *v5; // ecx@14
    BYTE *v6; // eax@14
    PALETTEENTRY *v8; // ecx@19
    int v9; // eax@19
    HPALETTE v10; // esi@21
    int v11; // [sp-Ch] [bp-410h]@9
    PALETTEENTRY v12[256]; // [sp+0h] [bp-404h]@19
    int v13; // [sp+400h] [bp-4h]@19

    if (global_wnd_bpp == 8)
    {
        v1 = dword_468FDC << 8;
        for (i = 0; i < v1; ++i)
        {
            if (((*(&_47B408_palette_entries[0].peRed + i) << 8) & 0xFFFFFF00) >= 0xFF00)
                result = (void *)255;
            else
                result = (void *)*(&_47B408_palette_entries[0].peRed + i);
            *(&palette_47BC10[0].peRed + i) = (unsigned __int8)result;
        }

        v4 = palette_47BC10;
        dword_47C018 = 0;
        dword_468FD4 = 1;
        dword_468FD8 = 2;
        dword_468FDC = 4;
        if (palette_47BC10)
            memcpy(_47B408_palette_entries, palette_47BC10, sizeof(_47B408_palette_entries));
        else
            v4 = _47B408_palette_entries;
        if (global_fullscreen == 1)
        {
            v5 = (char *)&RenderDD_primary_palette_values[0].peGreen;
            v6 = &v4->peBlue;
            do
            {
                v6[&RenderDD_primary_palette_values[0].peGreen - (BYTE *)v4] = 0;
                *(v5 - 1) = *(v6 - 2);
                *v5 = *(v6 - 1);
                v6[(char *)RenderDD_primary_palette_values - (char *)v4] = *v6;
                v5 += 4;
                v6 += 4;
            } while ((int)v5 < (int)&render_sw_hdc + 1);
            /*v7 = (IDirectDrawPalette *)render_dd_is_primary_surface_lost();
            if (!v7)
            {
                v7 = pddpal_primary;
                if (pddpal_primary)
                    v7 = (IDirectDrawPalette *)pddpal_primary->SetEntries(
                        0,
                        0,
                        256,
                        RenderDD_primary_palette_values);
            }*/
        }
        else
        {
            v8 = v12;
            v9 = (int)&v4->peGreen;
            v13 = 256;
            do
            {
                *(_BYTE *)(&v12[0].peBlue - (BYTE *)v4 + v9) = 0;
                v8->peRed = *(_BYTE *)(v9 + 1);
                *(_BYTE *)((char *)v12 - (char *)v4 + v9) = *(_BYTE *)v9;
                *(_BYTE *)(&v12[0].peGreen - (BYTE *)v4 + v9) = *(_BYTE *)(v9 - 1);
                ++v8;
                v9 += 4;
                --v13;
            } while (v13);
            v10 = render_sw_palette;
            if (render_sw_palette)
            {
                render_sw_palette = _431B60_create_palette(v12, 256);
                SelectPalette(render_sw_hdc, render_sw_palette, 0);
                DeleteObject(v10);
            }
            else
            {
                render_sw_palette = _431B60_create_palette(v12, 256);
                render_sw_default_palette = SelectPalette(render_sw_hdc, render_sw_palette, 0);
            }
            RealizePalette(render_sw_hdc);
        }
    }
}