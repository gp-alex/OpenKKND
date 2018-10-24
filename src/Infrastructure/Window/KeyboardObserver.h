#pragma once

namespace Infrastructure {
    class KeyboardObserver {
    public:
        virtual void OnCharUp(int key, bool ctrl_status, bool alt_status) {}
        virtual void OnSpecialKeyUp(int key, bool ctrl_status, bool alt_status) {}
    };
};
