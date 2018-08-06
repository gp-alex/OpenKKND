#include "src/Infrastructure/InputWindowObserver.h"

using Infrastructure::InputWindowObserver;

#include "src/Infrastructure/Input.h"



void InputWindowObserver::OnMouseMove(int x, int y, int dx, int dy, bool lbuttonDown, bool rbuttonDown) {
    extern MouseInput input_mouse;

    /*input_mouse.cursor_x_x256 = x * 256;
    input_mouse.cursor_dx_x256 = dx * 256;
    input_mouse.cursor_y_x256 = y * 256;
    input_mouse.cursor_dy_x256 = dy * 256;*/
}


void InputWindowObserver::OnMouseLeftButton(int x, int y, bool pressed) {
    extern MouseInput input_mouse;
    extern int input_mouse_prev_buttons_mask;

    /*if (pressed) {
        input_mouse.pressed_buttons_mask |= INPUT_MOUSE_LBUTTON_MASK;
        if (input_mouse_prev_buttons_mask & INPUT_MOUSE_LBUTTON_MASK) {
            input_mouse.just_pressed_buttons_mask &= ~INPUT_MOUSE_LBUTTON_MASK;
        } else {
            input_mouse.just_pressed_buttons_mask |= INPUT_MOUSE_LBUTTON_MASK;
        }
        input_mouse.just_released_buttons_mask &= ~INPUT_MOUSE_LBUTTON_MASK;
    } else {
        input_mouse.pressed_buttons_mask &= ~INPUT_MOUSE_LBUTTON_MASK;
        if (input_mouse_prev_buttons_mask & INPUT_MOUSE_LBUTTON_MASK) {
            input_mouse.just_released_buttons_mask |= INPUT_MOUSE_LBUTTON_MASK;
        } else {
            input_mouse.just_released_buttons_mask &= ~INPUT_MOUSE_LBUTTON_MASK;
        }
        input_mouse.just_pressed_buttons_mask &= ~INPUT_MOUSE_LBUTTON_MASK;
    }

    input_mouse_prev_buttons_mask = input_mouse.pressed_buttons_mask;*/
}


void InputWindowObserver::OnMouseRightButton(int x, int y, bool pressed) {
    extern MouseInput input_mouse;
    extern int input_mouse_prev_buttons_mask;

    /*if (pressed) {
        input_mouse.pressed_buttons_mask |= INPUT_MOUSE_RBUTTON_MASK;
        if (input_mouse_prev_buttons_mask & INPUT_MOUSE_RBUTTON_MASK) {
            input_mouse.just_pressed_buttons_mask &= ~INPUT_MOUSE_RBUTTON_MASK;
        } else {
            input_mouse.just_pressed_buttons_mask |= INPUT_MOUSE_RBUTTON_MASK;
        }
        input_mouse.just_released_buttons_mask &= ~INPUT_MOUSE_RBUTTON_MASK;
    } else {
        input_mouse.pressed_buttons_mask &= ~INPUT_MOUSE_RBUTTON_MASK;
        if (input_mouse_prev_buttons_mask & INPUT_MOUSE_RBUTTON_MASK) {
            input_mouse.just_released_buttons_mask |= INPUT_MOUSE_RBUTTON_MASK;
        } else {
            input_mouse.just_released_buttons_mask &= ~INPUT_MOUSE_RBUTTON_MASK;
        }
        input_mouse.just_pressed_buttons_mask &= ~INPUT_MOUSE_RBUTTON_MASK;
    }

    input_mouse_prev_buttons_mask = input_mouse.pressed_buttons_mask;*/
}