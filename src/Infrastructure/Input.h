#pragma once

#pragma pack(push, 1)

#define INPUT_KEYBOARD_UP_MASK      0x1
#define INPUT_KEYBOARD_DOWN_MASK    0x2
#define INPUT_KEYBOARD_LEFT_MASK    0x4
#define INPUT_KEYBOARD_RIGHT_MASK   0x8
#define INPUT_KEYBOARD_ARROW_KEYS_MASK (INPUT_KEYBOARD_UP_MASK | INPUT_KEYBOARD_DOWN_MASK | INPUT_KEYBOARD_LEFT_MASK | INPUT_KEYBOARD_RIGHT_MASK)

#define INPUT_KEYBOARD_CONTROL_MASK 0x10
#define INPUT_KEYBOARD_MENU_MASK    0x20
#define INPUT_KEYBOARD_RETURN_MASK  0x80
#define INPUT_KEYBOARD_TAB_MASK     0x100
#define INPUT_KEYBOARD_ESCAPE_MASK  0x200

/* 378 */
struct KeyboardInput
{
    int pressed_keys_mask;
    int just_pressed_keys_mask;
    int unpressed_keys_mask;
    int field_C;
    int _10_wndproc_mapped_key;
};


#define INPUT_MOUSE_MOVE_UP      0x01
#define INPUT_MOUSE_MOVE_DOWN    0x02
#define INPUT_MOUSE_MOVE_LEFT    0x04
#define INPUT_MOUSE_MOVE_RIGHT   0x08
#define INPUT_MOUSE_LBUTTON_MASK 0x10
#define INPUT_MOUSE_RBUTTON_MASK 0x20
#define INPUT_MOUSE_MBUTTON_MASK 0x80

/* 356 */
struct MouseInput
{
    int pressed_buttons_mask;
    int just_pressed_buttons_mask;
    int just_released_buttons_mask;
    int _C_unused;
    int cursor_x_x256;
    int cursor_y_x256;
    int cursor_dx_x256;
    int cursor_dy_x256;
};

#pragma pack(pop)


bool input_initialize();

void input_update_keyboard();
bool input_get_keyboard_state(KeyboardInput *state);
void input_reset_keyboard();


void input_update_mouse();
bool input_get_mouse_state(MouseInput *a1);
bool input_get_cursor_state(MouseInput *a1); // same as mouse state but separate MouseInput stru used in CursorHandler

bool input_4283A0_set_cursor_pos(__int16 x, __int16 y);
bool input_428470(__int16 a1);




inline bool mouse_lbutton_just_pressed() {
    MouseInput state;
    input_get_mouse_state(&state);
    return state.just_pressed_buttons_mask & INPUT_MOUSE_LBUTTON_MASK;
}

inline bool mouse_lbutton_just_released() {
    MouseInput state;
    input_get_mouse_state(&state);
    return state.just_released_buttons_mask & INPUT_MOUSE_LBUTTON_MASK;
}


inline bool mouse_rbutton_is_pressed() {
    MouseInput state;
    input_get_mouse_state(&state);
    return state.pressed_buttons_mask & INPUT_MOUSE_RBUTTON_MASK;
}

inline bool mouse_rbutton_just_pressed() {
    MouseInput state;
    input_get_mouse_state(&state);
    return state.just_pressed_buttons_mask & INPUT_MOUSE_RBUTTON_MASK;
}

inline bool mouse_rbutton_just_released() {
    MouseInput state;
    input_get_mouse_state(&state);
    return state.just_released_buttons_mask & INPUT_MOUSE_RBUTTON_MASK;
}


inline bool cursor_lbutton_just_pressed() {
    MouseInput state;
    input_get_cursor_state(&state);
    return state.just_pressed_buttons_mask & INPUT_MOUSE_LBUTTON_MASK;
}

inline bool cursor_lbutton_just_released() {
    MouseInput state;
    input_get_cursor_state(&state);
    return state.just_released_buttons_mask & INPUT_MOUSE_LBUTTON_MASK;
}


inline bool cursor_rbutton_is_pressed() {
    MouseInput state;
    input_get_cursor_state(&state);
    return state.pressed_buttons_mask & INPUT_MOUSE_RBUTTON_MASK;
}

inline bool cursor_rbutton_just_pressed() {
    MouseInput state;
    input_get_cursor_state(&state);
    return state.just_pressed_buttons_mask & INPUT_MOUSE_RBUTTON_MASK;
}

inline bool cursor_rbutton_just_released() {
    MouseInput state;
    input_get_cursor_state(&state);
    return state.just_released_buttons_mask & INPUT_MOUSE_RBUTTON_MASK;
}




extern MouseInput _47A5E0_mouse_input; // idb;




void DebugMouseInput(const MouseInput *m);