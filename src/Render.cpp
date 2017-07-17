#include "src/kknd.h"

#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"

#include "src/Render.h"



IDirectDrawSurface *pdds_primary;
IDirectDrawSurface *pdds_backbuffer;


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
            if (!RegisterClassExA(&v17))
            {
                v10 = 0;
                goto LABEL_17;
            }
            if (global_fullscreen == 1)
            {
                v11 = 0x90080000;
                global_wnd_style_ex = 0x40008;
                global_wnd_style = 0x90080000;
            }
            else
            {
                v11 = 0x90CA0000;
                global_wnd_style_ex = 0x40000;
                global_wnd_style = 0x90CA0000;
            }
            global_wnd_rect.left = 0;
            global_wnd_rect.right = global_wnd_width;
            global_wnd_rect.top = 0;
            global_wnd_rect.bottom = global_wnd_height;
            AdjustWindowRect(&global_wnd_rect, v11, 0);
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
            if (!v14)
            {
                v10 = 0;
                goto LABEL_17;
            }
            UpdateWindow(v14);
        }
        render_sw_initialize();
        v10 = render_init_dd();
    }

LABEL_17:
    if (v10)
    {
        v15 = (stru1_draw_params *)malloc(0xFCu);
        stru1_list = v15;
        if (v15)
        {
            v16 = 0;
            do
            {
                v15[v16].next = &v15[v16 + 1];          // chain
                                                        // [0] -> [1] -> [2] -> [3] -> [4] -> [5] -> [6]
                v15 = stru1_list;
                ++v16;
            } while (v16 < 6);
            stru1_list[6].next = 0;
            stru1_list_free_pool = stru1_list;
            default_stru1.prev = &default_stru1;
            default_stru1.next = &default_stru1;
            default_stru1.field_8 = 0;
            default_stru1.anim_pos = 0x80000000;
            default_stru1.clip_y = 0;
            default_stru1.clip_x = 0;
            default_stru1.clip_z = w1dth;
            default_stru1.clip_w = he1ght;
            default_stru1.field_20 = 0;
            is_render_window_initialized = 1;

            return true;
        }
    }

    return false;
}

//----- (00411A50) --------------------------------------------------------
bool render_init_dd()
{
    int v0; // eax@11
    int v1; // eax@15
    int v2; // eax@19
    int v3; // eax@23
    int v4; // eax@31
    int v5; // eax@35
    int v6; // eax@45
    HWND v8; // eax@46
    IDirectDrawSurface *v9; // [sp+68h] [bp-280h]@10
    IDirectDraw *lpDD; // [sp+6Ch] [bp-27Ch]@3
    DDCAPS v11; // [sp+70h] [bp-278h]@5
    DDCAPS v12; // [sp+1ACh] [bp-13Ch]@5

    if (!RenderDD_initialized && !pdd)
    {
        RenderDD_initialized = 1;
        lpDD = 0;
        if (!DirectDrawCreate(0, &lpDD, 0))
        {
            pdd = lpDD;
            if (lpDD)
            {
                v11.dwSize = 316;
                memset(&v11.dwCaps, 0, 0x138u);
                v12.dwSize = 316;
                memset(&v12.dwCaps, 0, 0x138u);
                lpDD->GetCaps(&v11, &v12);
                if (v11.dwCaps & DDCAPS_CANBLTSYSMEM || v12.dwCaps & DDCAPS_CANBLTSYSMEM)
                {
                    if (global_fullscreen == 1)
                    {
                        global_wnd_style = 0x90080000;
                        global_wnd_style_ex = 0x40008;
                        SetWindowLongA(global_hwnd, GWL_STYLE, 0x90080000);
                        SetWindowLongA(global_hwnd, GWL_EXSTYLE, global_wnd_style_ex);
                        SetWindowPos(global_hwnd, (HWND)(void *)((int)HWND_MESSAGE | 0x2), 0, 0, global_wnd_width, global_wnd_height, 0x60u);
                        InvalidateRect(global_hwnd, 0, 1);
                        UpdateWindow(global_hwnd);
                        if (!pdd->SetCooperativeLevel(
                            global_hwnd,
                            DDSCL_EXCLUSIVE | DDSCL_NOWINDOWCHANGES | DDSCL_ALLOWREBOOT | DDSCL_FULLSCREEN)
                            && !pdd->SetDisplayMode(global_wnd_width, global_wnd_height, global_wnd_bpp))
                        {
                            pdds_backbuffer = 0;
                            ddsd_primary.dwSize = 108;
                            ddsd_primary.dwFlags = 33;
                            ddsd_primary.ddsCaps.dwCaps = DDCAPS_BLTSTRETCH | DDCAPS_ALIGNSIZESRC | DDCAPS_ALIGNBOUNDARYSRC;
                            ddsd_primary.dwBackBufferCount = 2;
                            fullscreen_flip_or_blt = 1;
                            if (pdd->CreateSurface(&ddsd_primary, &v9, 0))
                            {
                                v0 = 0;
                            }
                            else
                            {
                                pdds_primary = v9;
                                v0 = v9 != 0;
                            }
                            if (v0
                                || ((ddsd_primary.ddsCaps.dwCaps = DDCAPS_BLTSTRETCH | DDCAPS_ALIGNSIZESRC | DDCAPS_ALIGNBOUNDARYSRC,
                                    ddsd_primary.dwBackBufferCount = 1,
                                    !pdd->CreateSurface(&ddsd_primary, &v9, 0)) ? (pdds_primary = v9, v1 = v9 != 0) : (v1 = 0),
                                    v1
                                    || ((fullscreen_flip_or_blt = 0,
                                        ddsd_primary.dwFlags = 1,
                                        ddsd_primary.ddsCaps.dwCaps = 512,
                                        !pdd->CreateSurface(&ddsd_primary, &v9, 0)) ? (pdds_primary = v9, v2 = v9 != 0) : (v2 = 0),
                                        v2
                                        && ((ddsd_primary.dwHeight = global_wnd_height,
                                            ddsd_primary.dwWidth = global_wnd_width,
                                            ddsd_primary.dwFlags = 7,
                                            ddsd_primary.ddsCaps.dwCaps = 2112,
                                            !pdd->CreateSurface(&ddsd_primary, &v9, 0)) ? (pdds_backbuffer = v9, v3 = v9 != 0) : (v3 = 0),
                                            v3))))
                            {
                                if (pdds_backbuffer
                                    || (v9 = (IDirectDrawSurface *)4,
                                        !pdds_primary->GetAttachedSurface((LPDDSCAPS)&v9, &pdds_backbuffer)))
                                {
                                LABEL_38:
                                    if ((global_fullscreen != 1
                                        || !pdd->CreatePalette(68, RenderDD_primary_palette_values, &pddpal_primary, 0)
                                        && !pdds_primary->SetPalette(pddpal_primary))
                                        && !pdd->CreateClipper(0, &pddclipper, 0)
                                        && !pddclipper->SetHWnd(0, global_hwnd)
                                        && !pdds_primary->SetClipper(pddclipper)
                                        && !pdds_primary->GetSurfaceDesc(&ddsd_primary))
                                    {
                                        memcpy(&pixelformat_primary, &ddsd_primary.ddpfPixelFormat, sizeof(pixelformat_primary));
                                        v6 = ShowWindow(global_hwnd, global_win32_nCmdShow);
                                        RenderDD_initialized = 0;
                                        REND_DirectDrawClearScreen(1);
                                        return 1;
                                    }
                                    goto LABEL_46;
                                }
                            }
                        }
                    }
                    else                                  // windowed
                    {
                        global_wnd_style = 0x90CA0000;
                        global_wnd_style_ex = 0x40000;
                        SetWindowLongA(global_hwnd, GWL_STYLE, 0x90CA0000);
                        SetWindowLongA(global_hwnd, GWL_EXSTYLE, global_wnd_style_ex);
                        SetWindowPos(
                            global_hwnd,
                            (HWND)0xFFFFFFFE,
                            global_wnd_rect.left,
                            global_wnd_rect.top,
                            global_wnd_rect.right - global_wnd_rect.left,
                            global_wnd_rect.bottom - global_wnd_rect.top,
                            0x60u);
                        InvalidateRect(global_hwnd, 0, 1);
                        UpdateWindow(global_hwnd);
                        if (!pdd->SetCooperativeLevel(global_hwnd, DDSCL_NORMAL))
                        {
                            memset(&ddsd_primary, 0, sizeof(ddsd_primary));
                            ddsd_primary.dwSize = 108;
                            ddsd_primary.dwFlags = 1;
                            ddsd_primary.ddsCaps.dwCaps = 512;
                            if (pdd->CreateSurface(&ddsd_primary, &v9, 0))
                            {
                                v4 = 0;
                            }
                            else
                            {
                                pdds_primary = v9;
                                v4 = v9 != 0;
                            }
                            if (v4)
                            {
                                ddsd_primary.dwHeight = global_wnd_height;
                                ddsd_primary.dwWidth = global_wnd_width;
                                ddsd_primary.dwFlags = 7;
                                ddsd_primary.ddsCaps.dwCaps = DDCAPS_OVERLAYSTRETCH | DDCAPS_BLT;
                                if (pdd->CreateSurface(&ddsd_primary, &v9, 0))
                                {
                                    v5 = 0;
                                }
                                else
                                {
                                    pdds_backbuffer = v9;
                                    v5 = v9 != 0;
                                }
                                if (v5)
                                    goto LABEL_38;
                            }
                        }
                    }
                }
            }
        }
    LABEL_46:
        RenderDD_initialized = 0;
        render_cleanup_dd();
        v8 = GetActiveWindow();
        MessageBoxA(v8, (LPCSTR)aFailedToSetupDirectdraw, (LPCSTR)Caption, 0);
        return 0;
    }
    return 1;
}

//----- (00411FE0) --------------------------------------------------------
void render_cleanup_dd()
{
    IDirectDrawSurface *v0; // esi@3
    int v1; // eax@15
    IDirectDrawSurface *v2; // esi@23
    int v3; // eax@24
    IDirectDrawPalette *v4; // [sp+14h] [bp-4h]@9

    if (!RenderDD_initialized && pdd)
    {
        v0 = pdds_primary;
        if (pdds_primary)
        {
            pdds_primary->SetClipper(0);
            v0 = pdds_primary;
        }
        if (pddclipper)
        {
            pddclipper->Release();
            v0 = pdds_primary;
            pddclipper = 0;
        }
        if (global_fullscreen == 1)
        {
            if (v0)
            {
                v4 = 0;
                v0->GetPalette(&v4);
                if (v4)
                    pdds_primary->SetPalette(0);
                v0 = pdds_primary;
            }
            if (pddpal_primary)
            {
                pddpal_primary->Release();
                v0 = pdds_primary;
                pddpal_primary = 0;
            }
        }
        if (v0)
        {
            while (1)
            {
                v1 = v0->GetBltStatus(2);
                if (v1 != 0x887601AE && v1 != 0x8876021C)
                    break;
                Sleep(0xAu);
            }
            if (fullscreen_flip_or_blt && v0->GetFlipStatus(2) == 0x887601AE)
            {
                do
                    Sleep(0xAu);
                while (v0->GetFlipStatus(2) == 0x887601AE);
            }
            v0->Release();
        }
        pdds_primary = 0;
        if (!fullscreen_flip_or_blt)
        {
            v2 = pdds_backbuffer;
            if (pdds_backbuffer)
            {
                while (1)
                {
                    v3 = v2->GetBltStatus(2);
                    if (v3 != 0x887601AE && v3 != 0x8876021C)
                        break;
                    Sleep(0xAu);
                }
                if (fullscreen_flip_or_blt && v2->GetFlipStatus(2) == -2005532242)
                {
                    do
                        Sleep(0xAu);
                    while (v2->GetFlipStatus(2) == -2005532242);
                }
                v2->Release();
            }
        }
        pdds_backbuffer = 0;
        if (global_fullscreen != 1 && !GetWindowRect(global_hwnd, &global_wnd_rect))
        {
            global_wnd_rect.top = 0;
            global_wnd_rect.left = 0;
        }
        if (pdd)
        {
            pdd->Release();
            pdd = 0;
        }
    }
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
    BOOL result; // eax@2

    if (!pdds_primary || (result = pdds_primary->IsLost()) != 0)
        result = 1;
    return result;
}

//----- (004122D0) --------------------------------------------------------
void render_draw_list(DrawJobList *list)
{
    int restore_palettes; // ebx@4
    IDirectDrawSurface *v3; // esi@7
    int v4; // eax@8
    HRESULT v5; // eax@9
    IDirectDrawSurface *v6; // esi@14
    int v7; // eax@15
    HRESULT v8; // eax@16
    DrawJob *i; // esi@25
    MapdScrlImage *v10; // eax@26
    int(*v11)(DrawJobDetails *, int); // eax@27
    RECT v12; // [sp+44h] [bp-94h]@34
    POINT Point; // [sp+54h] [bp-84h]@35
    POINT v14; // [sp+5Ch] [bp-7Ch]@35
    RECT v15; // [sp+64h] [bp-74h]@35
    DDBLTFX v16; // [sp+74h] [bp-64h]@34

    if (list && render_default_stru1 && pdds_primary)
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
                    render_locked_surface_width_px = ddsd_primary.dwWidth;

                    // 8/16 bpp are hardcoded, introduce a walkaround for ordinary bpp
                    auto *pixels_8bpp = new unsigned char[ddsd_primary.dwWidth * ddsd_primary.dwHeight];

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
                    for (int y = 0; y < ddsd_primary.dwHeight; ++y)
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
                    }

                    delete[] pixels_8bpp;


                    if (!pdds_backbuffer->Unlock(ddsd_primary.lpSurface))
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
    }
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
// 4798CC: using guessed type int is_render_window_initialized;

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

//----- (00412850) --------------------------------------------------------
int nullsub_3(void)
{
    return 1;
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
    int v2; // esi@1
    int v3; // eax@3
    void *v4; // eax@4
    int v8; // [sp+0h] [bp-6Ch]@3
    DDBLTFX v9; // [sp+8h] [bp-64h]@7

    v2 = a2;

    _477340_coroutine_yield_item = __EAX__;
    if (coroutine_list_head != coroutine_current && ++_47734C_coroutine_int == 1)
    {
        v3 = coroutine_list_head->stack;
        __asm
        {
            mov _477344_esp, esp
            mov esp, v3
        }
    }
    v4 = _477340_coroutine_yield_item;
    if (global_fullscreen == 1)
    {
        v4 = (void *)pdds_primary->EnumAttachedSurfaces(0, EnumAttachedSurfacesCallback);
    }
    else if (pdds_backbuffer)
    {
        memset(&v9, 0, sizeof(v9));
        v9.dwFillColor = 0;
        v9.dwSize = 100;
        v4 = (void *)pdds_backbuffer->Blt(&_46BB50_blt_rect, 0, 0, DDBLT_WAIT | DDBLT_COLORFILL, &v9);
    }
    if (v2 && pdds_primary)
    {
        memset(&v9, 0, sizeof(v9));
        v9.dwFillColor = 0;
        v9.dwSize = 100;
        v4 = (void *)pdds_primary->Blt(&_46BB50_blt_rect, 0, 0, DDBLT_WAIT | DDBLT_COLORFILL, &v9);
    }
    _477340_coroutine_yield_item = v4;
    if (coroutine_list_head != coroutine_current)
    {
        if (--_47734C_coroutine_int == 0)
        {
            v3 = coroutine_list_head->stack;
            __asm
            {
                mov esp, _477344_esp
            }
        }
    }
}

//----- (0040E2A0) --------------------------------------------------------
int REND_SetRoutines()
{
    render_width = _478AA0_game_width;
    render_height = _478A84_game_height;
    REND_434890_set_ds();
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
    j_render_4349D0_draw_tile_32x32 = (decltype(j_render_4349D0_draw_tile_32x32))render_4349D0_draw_tile_32x32;
    j_render_nullsub_2 = (int)nullsub_1;
    return 1;
}


void render_on_wm_paint(struct tagRECT *a1)
{
    if (pdds_primary)
    {
        if (pdds_backbuffer)
        {
            pdds_primary->Blt(a1, pdds_backbuffer, a1, 0, 0);
        }
    }
}