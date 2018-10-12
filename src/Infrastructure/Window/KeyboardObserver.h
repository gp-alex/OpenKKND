#pragma once

namespace Infrastructure {
    class KeyboardObserver {
    public:
        virtual void OnKeyUp(int key, bool ctrl_status, bool alt_status) {}
    };
};
