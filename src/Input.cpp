#include "src/kknd.h"

#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"

#include "src/Input.h"


/* 379 */
struct VKeyMap
{
    int virtual_key;
    int mask;
};

VKeyMap vkey_map[25] =
{
    { 72, 1 },
    { 80, 2 },
    { 75, 4 },
    { 77, 8 },
    { 29, 16 },
    { 56, 32 },
    { 71, 5 },
    { 79, 6 },
    { 73, 9 },
    { 81, 10 },
    { 42, 64 },
    { 28, 128 },
    { 15, 256 },
    { 1, 512 },
    { 30, 32768 },
    { 19, 16384 },
    { 33, 4096 },
    { 23, 8192 },
    { 35, 4096 },
    { 12, 2097152 },
    { 13, 1048576 },
    { 59, 4194304 },
    { 60, 8388608 },
    { 61, 16777216 },
    { 0, 0 }
};



KeyboardInput input_now_pressed_keys; // weak
KeyboardInput input_previous_state; // weak
KeyboardInput input_keyboard_state; // weak

MouseInput _47A540_mouse_input; // weak
MouseInput _47A5E0_mouse_input; // idb
int input_mouse_prev_buttons_mask; // weak
MouseInput input_mouse; // weak
int num_mouse_buttons; // weak
int input_47A58C; // weak
__int16 word_47A590; // weak





void input_reset_keyboard()
{
    input_keyboard_state.pressed_keys_mask = 0;
    input_keyboard_state.just_pressed_keys_mask = 0;
    input_keyboard_state.unpressed_keys_mask = 0;
    input_keyboard_state.field_C = 0;
    input_keyboard_state._10_wndproc_mapped_key = 0;
}

//----- (0041AAE0) --------------------------------------------------------
void input_update_keyboard()
{
    int nExt_pressed_key; // ecx@2
    int v1; // eax@3
    int v2; // eax@6
    int vk; // eax@10
    int v4; // edx@17

    input_479B6C_just_pressed_keys_mask = 0;
    input_now_pressed_keys.pressed_keys_mask = 0;
    input_now_pressed_keys.just_pressed_keys_mask = 0;
    input_now_pressed_keys.unpressed_keys_mask = 0;
    input_now_pressed_keys.field_C = -1;
    if (GetActiveWindow() == global_hwnd)
    {
        nExt_pressed_key = 0;
        next_pressed_key = 0;
        if (vkey_map[0].virtual_key)
        {
            do
            {
                LOWORD_HEXRAYS(input_static_async_key_state) = GetAsyncKeyState(virtual_keys[vkey_map[nExt_pressed_key].virtual_key]);
                v1 = vkey_map[next_pressed_key].mask;
                if (input_static_async_key_state & 0x8000)
                {
                    input_now_pressed_keys.pressed_keys_mask |= v1;
                    if (!(input_previous_state.pressed_keys_mask & v1))
                        input_now_pressed_keys.just_pressed_keys_mask |= v1;
                    v2 = v1 & 0xF;
                    if (v2)
                        input_479B6C_just_pressed_keys_mask |= v2;
                }
                else if (v1 & input_previous_state.pressed_keys_mask)
                {
                    input_now_pressed_keys.unpressed_keys_mask |= v1;
                }
                vk = vkey_map[next_pressed_key + 1].virtual_key;
                nExt_pressed_key = next_pressed_key++ + 1;
            } while (vk);
        }
    }
    else
    {
        nExt_pressed_key = next_pressed_key;
    }
    if (nExt_pressed_key && wnd_proc_pressed_key_id)
    {
        if (wnd_proc_pressed_key_id == -1)
        {
            input_now_pressed_keys._10_wndproc_mapped_key = 0;
        }
        else
        {
            v4 = input_465A80_wndprockey_map[wnd_proc_pressed_key_id];
            input_wnd_proc_pressed_key_id = wnd_proc_pressed_key_id;
            input_now_pressed_keys._10_wndproc_mapped_key = v4;
        }
        wnd_proc_pressed_key_id = 0;
    }
    input_now_pressed_keys.field_C = input_465FE8[input_479B6C_just_pressed_keys_mask];
    memcpy(&input_previous_state, &input_now_pressed_keys, sizeof(input_previous_state));
    memcpy(&input_keyboard_state, &input_now_pressed_keys, sizeof(input_keyboard_state));
}

//----- (0041AC30) --------------------------------------------------------
bool input_get_keyboard_state(KeyboardInput *state)
{
    memcpy(state, &input_keyboard_state, sizeof(KeyboardInput));
    return true;
}


//----- (00428310) --------------------------------------------------------
bool input_initialize()
{
    input_mouse.just_pressed_buttons_mask = 0;
    input_mouse.pressed_buttons_mask = 0;
    input_mouse.just_released_buttons_mask = 0;
    input_mouse_prev_buttons_mask = 0;
    input_47A58C = 0;
    num_mouse_buttons = GetSystemMetrics(SM_CMOUSEBUTTONS);
    if (num_mouse_buttons)
    {
        input_mouse_window_losing_focus_reset_to_defaults = 1;
        num_mouse_buttons = 2;
    }
    else
    {
        input_mouse_window_losing_focus_reset_to_defaults = 0;
    }
    input_mouse_prev_buttons_mask = 0;
    input_mouse.cursor_x_x256 = 0;
    input_mouse.cursor_y_x256 = 0;
    return input_mouse_window_losing_focus_reset_to_defaults != 0;
}

//----- (004283A0) --------------------------------------------------------
bool input_4283A0_set_cursor_pos(__int16 x, __int16 y)
{
    BOOL result; // eax@2
    int v3; // esi@3
    int v4; // edi@3
    int v5; // eax@5
    int v6; // [sp-8h] [bp-14h]@5
    int v7; // [sp+0h] [bp-Ch]@1
    struct tagPOINT Point; // [sp+4h] [bp-8h]@1

    LOWORD_HEXRAYS(v7) = y;
    LOWORD_HEXRAYS(Point.y) = x;
    if (input_mouse_window_losing_focus_reset_to_defaults)
    {
        v3 = LOWORD_HEXRAYS(Point.y);
        v4 = (unsigned __int16)v7;
        Point.x = LOWORD_HEXRAYS(Point.y);
        Point.y = (unsigned __int16)v7;

        ClientToScreen(global_hwnd, &Point);
        SetCursorPos(Point.x, Point.y);

        input_mouse.cursor_x_x256 = v3 << 8;
        input_mouse.cursor_y_x256 = v4 << 8;
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (00428470) --------------------------------------------------------
bool input_428470(__int16 a1)
{
    word_47A590 = a1;
    return 1;
}
// 47A590: using guessed type __int16 word_47A590;

//----- (00428480) --------------------------------------------------------
bool input_get_mouse_state(MouseInput *a1)
{
    memcpy(a1, &input_mouse, sizeof(MouseInput));
    return input_mouse_window_losing_focus_reset_to_defaults != 0;
}

//----- (004284A0) --------------------------------------------------------
int input_update_mouse()
{
    int result; // eax@3
    int v1; // edx@13
    bool v2; // zf@13
    int v3; // edx@13
    int v4; // eax@17
    struct tagPOINT Point; // [sp+8h] [bp-8h]@13

    if (GetActiveWindow() == global_hwnd)
    {
        input_mouse_window_losing_focus_reset_to_defaults = 1;
        input_mouse.pressed_buttons_mask = 0;
        if (((unsigned __int16)GetAsyncKeyState(VK_LBUTTON) >> 8) & 0x80)
            input_mouse.pressed_buttons_mask |= INPUT_MOUSE_LBUTTON_MASK;
        if (((unsigned __int16)GetAsyncKeyState(VK_RBUTTON) >> 8) & 0x80)
            input_mouse.pressed_buttons_mask |= INPUT_MOUSE_RBUTTON_MASK;
        if (num_mouse_buttons == 3 && ((unsigned __int16)GetAsyncKeyState(VK_MBUTTON) >> 8) & 0x80)
            input_mouse.pressed_buttons_mask |= INPUT_MOUSE_MBUTTON_MASK;
        input_mouse.just_pressed_buttons_mask = input_mouse.pressed_buttons_mask & ~input_mouse_prev_buttons_mask;
        input_mouse.just_released_buttons_mask = ~input_mouse.pressed_buttons_mask & input_mouse_prev_buttons_mask;
        input_mouse_prev_buttons_mask = input_mouse.pressed_buttons_mask;
        GetCursorPos(&Point);
        ScreenToClient(global_hwnd, &Point);
        v1 = input_mouse.cursor_x_x256;
        input_mouse.field_C = 0;
        input_mouse.cursor_x_x256 = Point.x << 8;
        input_mouse.cursor_dx_x256 = (Point.x << 8) - v1;
        v3 = (Point.y << 8) - input_mouse.cursor_y_x256;
        v2 = Point.y << 8 == input_mouse.cursor_y_x256;
        input_mouse.cursor_y_x256 = Point.y << 8;
        input_mouse.cursor_dy_x256 = v3;
        if (!v2)
        {
            input_mouse.pressed_buttons_mask |= (input_mouse.cursor_dy_x256 >= 0) + 1;
            input_mouse.field_C |= input_mouse.cursor_dy_x256 >= 0 ? 4 : 8;
        }
        if (input_mouse.cursor_dx_x256)
        {
            input_mouse.pressed_buttons_mask |= input_mouse.cursor_dx_x256 >= 0 ? 8 : 4;
            input_mouse.field_C |= (input_mouse.cursor_dx_x256 < 0) + 1;
        }
        v4 = dword_468940[input_mouse.field_C];
        input_mouse.field_C = input_465FE8[input_mouse.pressed_buttons_mask & 0xF];
        input_mouse.just_pressed_buttons_mask = ~input_47A58C & input_mouse.pressed_buttons_mask;
        input_mouse.just_released_buttons_mask = ~input_mouse.pressed_buttons_mask & input_47A58C;
        input_47A58C = input_mouse.pressed_buttons_mask;
        memcpy(&_47A540_mouse_input, &input_mouse, sizeof(_47A540_mouse_input));
        result = 1;
    }
    else if (input_mouse_window_losing_focus_reset_to_defaults)
    {
        input_mouse_window_losing_focus_reset_to_defaults = 0;
        input_mouse.just_released_buttons_mask = input_mouse.just_pressed_buttons_mask | input_mouse.pressed_buttons_mask;
        input_mouse.just_pressed_buttons_mask = 0;
        input_mouse.pressed_buttons_mask = 0;
        input_mouse.cursor_x_x256 = 0x14000;
        input_mouse.cursor_y_x256 = 0xF000;
        input_mouse.cursor_dx_x256 = 0;
        input_mouse.cursor_dy_x256 = 0;
        input_mouse.field_C = 0;
        input_mouse_prev_buttons_mask = 0;
        input_47A58C = 0;
        result = 0;
    }
    else
    {
        result = 0;
    }
    return result;
}