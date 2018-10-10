#include "src/Infrastructure/Input.h"

#include "src/kknd.h"
#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"

#include "src/Infrastructure/InputWindowObserver.h"
#include "src/Infrastructure/Log.h"

using Infrastructure::InputWindowObserver;

/* kknd input key masks */
int kknd_key_masks[25] =
{
    INPUT_KEYBOARD_UP_MASK,
    INPUT_KEYBOARD_DOWN_MASK,
    INPUT_KEYBOARD_LEFT_MASK,
    INPUT_KEYBOARD_RIGHT_MASK,
    INPUT_KEYBOARD_CONTROL_MASK,
    INPUT_KEYBOARD_MENU_MASK,
    INPUT_KEYBOARD_HOME_MASK,
    INPUT_KEYBOARD_END_MASK,
    INPUT_KEYBOARD_PAGEUP_MASK,
    INPUT_KEYBOARD_PAGEDOWN_MASK,
    INPUT_KEYBOARD_SHIFT_MASK,
    INPUT_KEYBOARD_RETURN_MASK,
    INPUT_KEYBOARD_TAB_MASK,
    INPUT_KEYBOARD_ESCAPE_MASK,
    INPUT_KEYBOARD_A_MASK,
    INPUT_KEYBOARD_R_MASK,
    INPUT_KEYBOARD_F_MASK,
    INPUT_KEYBOARD_I_MASK,
    INPUT_KEYBOARD_H_MASK,
    INPUT_KEYBOARD_MINUS_MASK,
    INPUT_KEYBOARD_PLUS_MASK,
    INPUT_KEYBOARD_F1_MASK,
    INPUT_KEYBOARD_F2_MASK,
    INPUT_KEYBOARD_F3_MASK,
    0
};


// VirtualKey code of key pressed simultaneously with system key (alt/ctrl)
int combo_pressed_vk;
// Special param for special key combinations
int combo_press_params_map[256] =
{
    /* 0 */ -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    /* 7 - ? */ 14,
    /* 8 - VK_BACK */ 15,
    -1,
    /* 10 */ -1,
    -1,
    -1,
    /* 13 - VK_RETURN */ 13,
    -1,
    -1,
    /* 16 - VK_SHIFT */ 42,
    29,
    56,
    -1,
    /* 20 */ 58,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    1,
    -1,
    -1,
    /* 30 */ -1,
    -1,
    57,
    -1,
    -1,
    79,
    71,
    75,
    72,
    77,
    /* 40 */ 80,
    -1,
    -1,
    -1,
    -1,
    82,
    83,
    -1,
    11,
    /* 49 - VK_1 */ 2,
    /* 50 - VK_2 */ 3,
    /* 51 - VK_3 */ 4,
    /* 52 - VK_4 */ 5,
    /* 53 - VK_5 */ 6,
    /* 54 - VK_6 */ 7,
    /* 55 - VK_7 */ 8,
    /* 56 - VK_8 */ 9,
    /* 57 - VK_9 */ 10,
    -1,
    -1,
    /* 60 */ -1,
    -1,
    -1,
    -1,
    -1,
    30,
    48,
    46,
    32,
    18,
    /* 70 */ 33,
    34,
    35,
    23,
    36,
    37,
    38,
    50,
    49,
    24,
    /* 80 */ 25,
    16,
    19,
    31,
    20,
    22,
    47,
    17,
    45,
    21,
    /* 90 */ 44,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    /* 100 */ -1,
    76,
    -1,
    -1,
    -1,
    -1,
    55,
    78,
    13,
    12,
    /* 110 */ -1,
    -1,
    59,
    60,
    61,
    62,
    63,
    64,
    65,
    66,
    /* 120 */ 67,
    68,
    87,
    88,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
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
    input_keyboard_state.combo_key_param = 0;
}

//----- (0041AAE0) --------------------------------------------------------
void input_update_keyboard()
{
    int nExt_pressed_key; // ecx@2
    int v1; // eax@3
    int v2; // eax@6
    int vk; // eax@10

    input_479B6C_just_pressed_keys_mask = 0;
    input_now_pressed_keys.pressed_keys_mask = 0;
    input_now_pressed_keys.just_pressed_keys_mask = 0;
    input_now_pressed_keys.unpressed_keys_mask = 0;
    input_now_pressed_keys.field_C = -1;

    if (gWindow->GetIsActive())
    {
        nExt_pressed_key = 0;
        next_pressed_key = 0;
        if (kknd_key_masks[0])
        {
            do
            {
                bool key_pressed = gWindow->GetIsKKNDKeyPressed(kknd_key_masks[nExt_pressed_key]);
                v1 = kknd_key_masks[next_pressed_key];
                if (key_pressed)
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
                vk = kknd_key_masks[next_pressed_key + 1];
                nExt_pressed_key = next_pressed_key++ + 1;
            } while (vk);
        }
    }
    else
    {
        nExt_pressed_key = next_pressed_key;
    }

    // CTRL + num combo check
	if (gWindow->GetIsKKNDKeyPressed(INPUT_KEYBOARD_CONTROL_MASK)) {
        bool ctrl_num_combo_pressed = false;
        for (int i = 1; i <= 9; i++) {
            if (gWindow->GetIsCharKeyPressed('0' + i)) {
                log("CTRL + %d pressed", i);
                ctrl_num_combo_pressed = true;

                //set VK of combo
                input_combo_pressed_vk = (48 + i); // VK for numbers
                combo_pressed_vk = input_combo_pressed_vk;
                input_now_pressed_keys.combo_key_param = combo_press_params_map[combo_pressed_vk];
                break;
            }
        }

        if (!ctrl_num_combo_pressed) {
            input_now_pressed_keys.combo_key_param = 0;
        }

        combo_pressed_vk = 0;
	}

    /*if (nExt_pressed_key && combo_pressed_vk)
    {
        if (combo_pressed_vk == -1)
        {
            input_now_pressed_keys.combo_key_param = 0;
        }
        else
        {
            input_combo_pressed_vk = combo_pressed_vk;
            input_now_pressed_keys.combo_key_param = combo_press_params_map[combo_pressed_vk];
        }
        combo_pressed_vk = 0;
    }*/

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
    } else if (input_mouse_window_losing_focus_reset_to_defaults) {
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
    }

    //DebugMouseInput(&input_mouse);
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