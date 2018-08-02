#include <windows.h>

#include "src/kknd.h"


//----- (00411420) --------------------------------------------------------
int __stdcall WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    int result; // eax@4
    HWND v5; // eax@17
    struct tagPOINT Point; // [sp+Ch] [bp-60h]@7
    struct tagPOINT v7; // [sp+14h] [bp-58h]@7
    RECT v8; // [sp+1Ch] [bp-50h]@7
    struct tagPAINTSTRUCT Paint; // [sp+2Ch] [bp-40h]@5

    switch (Msg)
    {
    case WM_ERASEBKGND:
        return 1;
    case WM_ACTIVATEAPP:
        extern bool render_fullscreen;
        if (!render_fullscreen)
            goto LABEL_18;
        if (wParam)
        {
            ShowWindow(hWnd, 3);
            /*if (!RenderDD_initialized)
            {
            _431C40_on_WM_ACTIVATEAPP_software_render();
            return DefWindowProcA(hWnd, Msg, wParam, lParam);
            }*/
        }
        else if (GetForegroundWindow() != hWnd)
        {
            ShowWindow(hWnd, 6);
            v5 = GetDesktopWindow();
            SetForegroundWindow(v5);
        }
    LABEL_18:
        result = DefWindowProcA(hWnd, Msg, wParam, lParam);
        break;
    case WM_KEYUP:
    case WM_SYSKEYUP:
        wnd_proc_pressed_key_id = -1;
        return 0;
    case WM_SYSCOMMAND:
        if (wParam == 61760)
            result = 0;
        else
            result = DefWindowProcA(hWnd, Msg, wParam, lParam);
        return result;
    case WM_KEYFIRST:
    case WM_SYSKEYDOWN:
        wnd_proc_pressed_key_id = wParam;
        return 0;
    case WM_CHAR:
    case WM_DEADCHAR:
    case WM_SYSCHAR:
    case WM_SYSDEADCHAR:
        return 0;

    case WM_PAINT:
        BeginPaint(hWnd, &Paint);
        {
            Point = *(struct tagPOINT *)&Paint.rcPaint.left;
            v7 = *(struct tagPOINT *)&Paint.rcPaint.right;
            ClientToScreen(hWnd, &Point);
            ClientToScreen(hWnd, &v7);
            *(struct tagPOINT *)&v8.left = Point;
            *(struct tagPOINT *)&v8.right = v7;

            render_on_wm_paint(v8.left, v8.top, v8.right, v8.bottom);
        }
        EndPaint(hWnd, &Paint);
        result = 1;
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        result = 0;
        break;

    default:
        result = DefWindowProcA(hWnd, Msg, wParam, lParam);
        break;
    }

    return result;
}


//----- (0044D560) --------------------------------------------------------
void message_pump()
{
    MSG msg;

    gWindow->PeekMessages();

    while (PeekMessageA(&msg, 0, 0, 0, PM_REMOVE))
    {
        if (msg.message == WM_QUIT)
            _47DCF4_wm_quit_received = true;
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
}



//----- (00411760) --------------------------------------------------------
bool render_create_window(int width, int height, bool fullscreen)
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

    if (bpp == 15)
    {
        bpp = 16;
    }
    else if (bpp != 8 && bpp != 16 && bpp != 24 && bpp != 32)
    {
        return false;
    }

    HWND v9 = FindWindowA("OpenKKNDWindowClass", "OpenKKND");
    if (v9)
    {
        SetForegroundWindow(v9);
        v10 = 0;
    }
    else
    {
        OsShowCursor(false);
        if (!global_hwnd)
        {
            v17.style = 8;
            v17.hInstance = GetModuleHandle(nullptr);
            v17.lpszClassName = "KKNDXtremeMainWindowClass";
            v17.lpfnWndProc = (WNDPROC)WndProc;
            v17.cbSize = 48;
            v17.hIcon = LoadIconA(v17.hInstance, (LPCSTR)0x65);
            v17.cbClsExtra = 0;
            v17.cbWndExtra = 0;
            v17.hIconSm = LoadIconA(v17.hInstance, (LPCSTR)0x65);
            v17.hCursor = 0;
            v17.lpszMenuName = 0;
            v17.hbrBackground = (HBRUSH)GetStockObject(5);
            if (RegisterClassExA(&v17))
            {

                DWORD global_wnd_style = WS_VISIBLE | WS_POPUP | WS_SYSMENU;
                DWORD global_wnd_style_ex = WS_EX_APPWINDOW;
                if (render_fullscreen == 1) {
                    global_wnd_style_ex |= WS_EX_TOPMOST;
                }
                else {
                    global_wnd_style |= WS_DLGFRAME | WS_BORDER | WS_GROUP;
                }

                RECT global_wnd_rect;
                global_wnd_rect.left = 0;
                global_wnd_rect.right = render_width;
                global_wnd_rect.top = 0;
                global_wnd_rect.bottom = render_height;
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
                    v17.hInstance,
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