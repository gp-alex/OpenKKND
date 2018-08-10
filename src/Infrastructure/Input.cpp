#include "src/Infrastructure/Input.h"

#include "src/kknd.h"
#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"

#include "src/Infrastructure/InputWindowObserver.h"
#include "src/Infrastructure/Log.h"

using Infrastructure::InputWindowObserver;



/* 379 */
struct VKeyMap
{
    int virtual_key;
    int mask;
};

VKeyMap vkey_map[25] =
{
    { 72, INPUT_KEYBOARD_UP_MASK },
    { 80, INPUT_KEYBOARD_DOWN_MASK },
    { 75, INPUT_KEYBOARD_LEFT_MASK },
    { 77, INPUT_KEYBOARD_RIGHT_MASK },
    { 29, INPUT_KEYBOARD_CONTROL_MASK },
    { 56, INPUT_KEYBOARD_MENU_MASK },
    { 71, 5 },
    { 79, 6 },
    { 73, 9 },
    { 81, 10 },
    { 42, 0x40 }, // shift
    { 28, INPUT_KEYBOARD_RETURN_MASK },
    { 15, INPUT_KEYBOARD_TAB_MASK },
    {  1, INPUT_KEYBOARD_ESCAPE_MASK },
    { 30, 0x8000 },  // keyboard 2nd character row
    { 19, 0x4000 },
    { 33, 0x1000 },
    { 23, 0x2000 },
    { 35, 0x1000 },
    { 12, 0x200000 },  // -
    { 13, 0x100000 },  // +
    { 59, 0x400000 },  // F1
    { 60, 0x800000 },  // F2
    { 61, 0x1000000 }, // F3
    { 0, 0 }
};

// define windows virtual keys
#if !defined(_INC_WINDOWS)

/*
* Virtual Keys, Standard Set
*/
#define VK_LBUTTON        0x01
#define VK_RBUTTON        0x02
#define VK_CANCEL         0x03
#define VK_MBUTTON        0x04    /* NOT contiguous with L & RBUTTON */

#define VK_XBUTTON1       0x05    /* NOT contiguous with L & RBUTTON */
#define VK_XBUTTON2       0x06    /* NOT contiguous with L & RBUTTON */

/*
* 0x07 : reserved
*/

#define VK_BACK           0x08
#define VK_TAB            0x09

/*
* 0x0A - 0x0B : reserved
*/

#define VK_CLEAR          0x0C
#define VK_RETURN         0x0D

/*
* 0x0E - 0x0F : unassigned
*/

#define VK_SHIFT          0x10
#define VK_CONTROL        0x11
#define VK_MENU           0x12
#define VK_PAUSE          0x13
#define VK_CAPITAL        0x14

#define VK_KANA           0x15
#define VK_HANGEUL        0x15  /* old name - should be here for compatibility */
#define VK_HANGUL         0x15

/*
* 0x16 : unassigned
*/

#define VK_JUNJA          0x17
#define VK_FINAL          0x18
#define VK_HANJA          0x19
#define VK_KANJI          0x19

/*
* 0x1A : unassigned
*/

#define VK_ESCAPE         0x1B

#define VK_CONVERT        0x1C
#define VK_NONCONVERT     0x1D
#define VK_ACCEPT         0x1E
#define VK_MODECHANGE     0x1F

#define VK_SPACE          0x20
#define VK_PRIOR          0x21
#define VK_NEXT           0x22
#define VK_END            0x23
#define VK_HOME           0x24
#define VK_LEFT           0x25
#define VK_UP             0x26
#define VK_RIGHT          0x27
#define VK_DOWN           0x28
#define VK_SELECT         0x29
#define VK_PRINT          0x2A
#define VK_EXECUTE        0x2B
#define VK_SNAPSHOT       0x2C
#define VK_INSERT         0x2D
#define VK_DELETE         0x2E
#define VK_HELP           0x2F

/*
* VK_0 - VK_9 are the same as ASCII '0' - '9' (0x30 - 0x39)
* 0x3A - 0x40 : unassigned
* VK_A - VK_Z are the same as ASCII 'A' - 'Z' (0x41 - 0x5A)
*/

#define VK_LWIN           0x5B
#define VK_RWIN           0x5C
#define VK_APPS           0x5D

/*
* 0x5E : reserved
*/

#define VK_SLEEP          0x5F

#define VK_NUMPAD0        0x60
#define VK_NUMPAD1        0x61
#define VK_NUMPAD2        0x62
#define VK_NUMPAD3        0x63
#define VK_NUMPAD4        0x64
#define VK_NUMPAD5        0x65
#define VK_NUMPAD6        0x66
#define VK_NUMPAD7        0x67
#define VK_NUMPAD8        0x68
#define VK_NUMPAD9        0x69
#define VK_MULTIPLY       0x6A
#define VK_ADD            0x6B
#define VK_SEPARATOR      0x6C
#define VK_SUBTRACT       0x6D
#define VK_DECIMAL        0x6E
#define VK_DIVIDE         0x6F
#define VK_F1             0x70
#define VK_F2             0x71
#define VK_F3             0x72
#define VK_F4             0x73
#define VK_F5             0x74
#define VK_F6             0x75
#define VK_F7             0x76
#define VK_F8             0x77
#define VK_F9             0x78
#define VK_F10            0x79
#define VK_F11            0x7A
#define VK_F12            0x7B
#define VK_F13            0x7C
#define VK_F14            0x7D
#define VK_F15            0x7E
#define VK_F16            0x7F
#define VK_F17            0x80
#define VK_F18            0x81
#define VK_F19            0x82
#define VK_F20            0x83
#define VK_F21            0x84
#define VK_F22            0x85
#define VK_F23            0x86
#define VK_F24            0x87

#define VK_NUMLOCK        0x90
#define VK_SCROLL         0x91

#define VK_OEM_1          0xBA   // ';:' for US
#define VK_OEM_PLUS       0xBB   // '+' any country
#define VK_OEM_COMMA      0xBC   // ',' any country
#define VK_OEM_MINUS      0xBD   // '-' any country
#define VK_OEM_PERIOD     0xBE   // '.' any country
#define VK_OEM_2          0xBF   // '/?' for US
#define VK_OEM_3          0xC0   // '`~' for US

#define VK_OEM_4          0xDB  //  '[{' for US
#define VK_OEM_5          0xDC  //  '\|' for US
#define VK_OEM_6          0xDD  //  ']}' for US
#define VK_OEM_7          0xDE  //  ''"' for US
#define VK_OEM_8          0xDF
#endif

int virtual_keys[90] =
{
    -1,
    /*  [1] */ VK_ESCAPE,
    /*  [2] */ '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    /* [12] */ VK_SUBTRACT,
    VK_ADD,
    VK_BACK,
    /* [15] */ VK_TAB,
    /* [16] */ 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
    /* [26] */ VK_OEM_4, // {[
    VK_OEM_6, // }]
    /* [28] */ VK_RETURN,
    /* [29] */ VK_CONTROL,
    /* [30] */ 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
    /* [39] */ VK_OEM_1, // ;:
    -1,
    -1,
    /* [42] */ VK_SHIFT,
    /* [43] */ VK_OEM_2, // /?
    /* [44] */ 'Z', 'X', 'C', 'V', 'B', 'N', 'M',
    /* [51] */ VK_OEM_COMMA,
    /* [52] */ VK_OEM_PERIOD,
    /* [53] */ VK_OEM_5, // \|
    VK_SHIFT,
    VK_MULTIPLY,
    /* [56] */ VK_MENU,
    /* [57] */ VK_SPACE,
    VK_CAPITAL,
    /* [59] */ VK_F1, VK_F2, VK_F3, VK_F4, VK_F5, VK_F6, VK_F7, VK_F8, VK_F9, VK_F10,
    /* [69] */ VK_NUMLOCK,
    VK_SCROLL,
    '$' ,
    /* [72] */ VK_UP,
    '!',
    VK_SUBTRACT,
    /* [75] */ VK_LEFT,
    VK_NUMPAD5,
    /* [77] */ VK_RIGHT,
    VK_ADD,
    '#',
    /* [80] */ VK_DOWN,
    '"',
    '-',
    '.',
    -1,
    -1,
    -1,
    VK_F11,
    VK_F12,
    0
};



KeyboardInput input_now_pressed_keys; // weak
KeyboardInput input_previous_state; // weak
KeyboardInput input_keyboard_state; // weak

MouseInput _47A5E0_mouse_input; // idb
int input_mouse_prev_buttons_mask; // weak
MouseInput input_mouse; // weak
int num_mouse_buttons; // weak
int input_47A58C; // weak
__int16 word_47A590; // weak
int input_mouse_window_losing_focus_reset_to_defaults; // weak
std::shared_ptr<InputWindowObserver> inputObserver;
int dword_468940[16] = { -1, 2, 6, -1, 4, 3, 5, -1, 0, 1, 7, -1, -1, -1, -1, -1 };
int input_465FE8[16] = { -1, 0, 4, -1, 6, 7, 5, 6, 2, 1, 3, 2, -1, 0, 4, -1 };


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

    if (gWindow->GetIsActive())
    {
        nExt_pressed_key = 0;
        next_pressed_key = 0;
        if (vkey_map[0].virtual_key)
        {
            do
            {
                bool pressed = gWindow->GetKeyPressedWindowsTmpHack(
                    virtual_keys[vkey_map[nExt_pressed_key].virtual_key]
                );
                //short key_state = GetAsyncKeyState(virtual_keys[vkey_map[nExt_pressed_key].virtual_key]);
                v1 = vkey_map[next_pressed_key].mask;
                //if (key_state & 0x8000)
                if (pressed)
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
    if (!inputObserver) {
        inputObserver = std::make_shared<InputWindowObserver>();
        gWindow->AddObserver(inputObserver);
    }

    input_mouse.just_pressed_buttons_mask = 0;
    input_mouse.pressed_buttons_mask = 0;
    input_mouse.just_released_buttons_mask = 0;
    input_mouse_prev_buttons_mask = 0;
    input_47A58C = 0;

    num_mouse_buttons = 3; // GetSystemMetrics(SM_CMOUSEBUTTONS);
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
bool input_set_mouse_pos(int x, int y)
{
    if (input_mouse_window_losing_focus_reset_to_defaults)
    {
        log("input_set_mouse_pos(x = %d, y = %d)", x, y);
        gWindow->SetMousePos(x, y);

        input_mouse.cursor_x_x256 = x * 256;
        input_mouse.cursor_y_x256 = y * 256;
        return 1;
    }

    return 0;
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

bool input_get_cursor_state(MouseInput *a1)
{
    memcpy(a1, &_47A5E0_mouse_input, sizeof(MouseInput));
    return input_mouse_window_losing_focus_reset_to_defaults != 0;
}

//----- (004284A0) --------------------------------------------------------
void input_update_mouse()
{
    if (gWindow->GetIsActive()) {
        input_mouse_window_losing_focus_reset_to_defaults = 1;
        input_mouse._C_unused = 0;
        input_mouse.pressed_buttons_mask = 0;
        if (gWindow->GetMousePressed(1)) {
            input_mouse.pressed_buttons_mask |= INPUT_MOUSE_LBUTTON_MASK;
        }
        if (gWindow->GetMousePressed(2)) {
            input_mouse.pressed_buttons_mask |= INPUT_MOUSE_MBUTTON_MASK;
        }
        if (gWindow->GetMousePressed(3)) {
            input_mouse.pressed_buttons_mask |= INPUT_MOUSE_RBUTTON_MASK;
        }

        input_mouse.just_pressed_buttons_mask = input_mouse.pressed_buttons_mask & ~input_mouse_prev_buttons_mask;
        input_mouse.just_released_buttons_mask = ~input_mouse.pressed_buttons_mask & input_mouse_prev_buttons_mask;
        input_mouse_prev_buttons_mask = input_mouse.pressed_buttons_mask;

        int mouse_x = 256 * gWindow->GetMouseX();
        int mouse_y = 256 * gWindow->GetMouseY();
        input_mouse.cursor_dx_x256 = mouse_x - input_mouse.cursor_x_x256;
        input_mouse.cursor_x_x256 = mouse_x;
        input_mouse.cursor_dy_x256 = mouse_y - input_mouse.cursor_y_x256;
        input_mouse.cursor_y_x256 = mouse_y;
        if (input_mouse.cursor_dy_x256) {
            input_mouse.pressed_buttons_mask |= input_mouse.cursor_dy_x256 >= 0 ? INPUT_MOUSE_MOVE_DOWN : INPUT_MOUSE_MOVE_UP;
            input_mouse._C_unused |= input_mouse.cursor_dy_x256 >= 0 ? 4 : 8;
        }
        if (input_mouse.cursor_dx_x256) {
            input_mouse.pressed_buttons_mask |= input_mouse.cursor_dx_x256 >= 0 ? INPUT_MOUSE_MOVE_RIGHT : INPUT_MOUSE_MOVE_LEFT;
            input_mouse._C_unused |= (input_mouse.cursor_dx_x256 < 0) + 1;
        }

        input_mouse._C_unused = dword_468940[input_mouse._C_unused];
        input_mouse._C_unused = input_465FE8[input_mouse.pressed_buttons_mask & 0xF];
        input_mouse.just_pressed_buttons_mask = ~input_47A58C & input_mouse.pressed_buttons_mask;
        input_mouse.just_released_buttons_mask = ~input_mouse.pressed_buttons_mask & input_47A58C;
        input_47A58C = input_mouse.pressed_buttons_mask;
    } /*else if (input_mouse_window_losing_focus_reset_to_defaults) {
        input_mouse_window_losing_focus_reset_to_defaults = 0;
        input_mouse.just_released_buttons_mask = input_mouse.just_pressed_buttons_mask | input_mouse.pressed_buttons_mask;
        input_mouse.just_pressed_buttons_mask = 0;
        input_mouse.pressed_buttons_mask = 0;
        input_mouse.cursor_x_x256 = (640 / 2) * 256;
        input_mouse.cursor_y_x256 = (480 / 2) * 256;
        input_mouse.cursor_dx_x256 = 0;
        input_mouse.cursor_dy_x256 = 0;
        input_mouse._C_unused = 0;
        input_mouse_prev_buttons_mask = 0;
        input_47A58C = 0;
    }*/

    DebugMouseInput(&input_mouse);
}



bool Equals(const MouseInput *a, const MouseInput *b) {
    return a->pressed_buttons_mask == b->pressed_buttons_mask
        && a->just_pressed_buttons_mask == b->just_pressed_buttons_mask
        && a->just_released_buttons_mask == b->just_released_buttons_mask
        //&& a->_C_unused == b->_C_unused
        //&& a->cursor_x_x256 == b->cursor_x_x256
        //&& a->cursor_y_x256 == b->cursor_y_x256
        //&& a->cursor_dx_x256 == b->cursor_dx_x256
        //&& a->cursor_dy_x256 == b->cursor_dy_x256
        ;
}



#include "src/Infrastructure/Log.h"
void DebugMouseInput(const MouseInput *m) {
    static MouseInput prev_m;
    static int repeats = 0;
    if (Equals(m, &prev_m)) {
        ++repeats;
        //log("Mouse x%u ", repeats);
        return;
    }

    repeats = 0;
    memcpy(&prev_m, m, sizeof(MouseInput));


    log(
        "Mouse\n"
        "\tpressed_buttons_mask=\t%08X\n"
        "\tjust_pressed_buttons_mask=\t%08X\n"
        "\tjust_released_buttons_mask=\t%08X\n"
        "\tcursor_x_x256=%u\n"
        "\tcursor_y_x256=%u\n"
        "\tcursor_dx_x256=%d\n"
        "\tcursor_dy_x256=%d",
        m->pressed_buttons_mask,
        m->just_pressed_buttons_mask,
        m->just_released_buttons_mask,
        m->cursor_x_x256 / 256,
        m->cursor_y_x256 / 256,
        m->cursor_dx_x256 / 256,
        m->cursor_dy_x256 / 256
    );
}