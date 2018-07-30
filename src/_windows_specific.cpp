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
        if (!is_render_window_initialized || global_fullscreen != 1)
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

            render_on_wm_paint(&v8);
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