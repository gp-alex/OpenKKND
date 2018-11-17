#include "src/Infrastructure/InputKeyboardObserver.h"

using Infrastructure::InputKeyboardObserver;

#include "src/Infrastructure/Input.h"



void InputKeyboardObserver::OnCharUp(int key, bool ctrl_status, bool alt_status) {
    extern int combo_pressed_vk,
        input_combo_pressed_vk,
        combo_press_params_map[];
    extern KeyboardInput input_now_pressed_keys;

    combo_pressed_vk = key;
    input_combo_pressed_vk = key;
    int combo_pressed_vk_param = 0;
    if (ctrl_status) {
        combo_pressed_vk_param = combo_press_params_map[combo_pressed_vk];
    } else {
        combo_pressed_vk_param = 0;
    }
    input_now_pressed_keys.combo_key_param = combo_pressed_vk_param;

    if (combo_pressed_vk) {
        log->Info(
            "Pressed: %c\t\tCTRL=%s (param=%d)\tALT=%s",
            (char)input_combo_pressed_vk,
            ctrl_status ? "true" : "false",
            combo_pressed_vk_param,
            alt_status ? "true" : "false"
        );
    }
}


void InputKeyboardObserver::OnSpecialKeyUp(int key, bool ctrl_status, bool alt_status) {
    extern int combo_pressed_vk,
        input_combo_pressed_vk,
        combo_press_params_map[];
    extern KeyboardInput input_now_pressed_keys;

    combo_pressed_vk = key;
    input_combo_pressed_vk = key;
    int combo_pressed_vk_param = 0;
    if (ctrl_status) {
        combo_pressed_vk_param = combo_press_params_map[combo_pressed_vk];
    }
    else {
        combo_pressed_vk_param = 0;
    }
    input_now_pressed_keys.combo_key_param = combo_pressed_vk_param;

    if (combo_pressed_vk) {
        log->Info(
            "Pressed: special: %d\tCTRL=%s (param=%d)\tALT=%s",
            (int)input_combo_pressed_vk,
            ctrl_status ? "true" : "false",
            combo_pressed_vk_param,
            alt_status ? "true" : "false"
        );
    }
}
