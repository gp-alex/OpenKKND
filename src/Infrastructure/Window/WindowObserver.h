#pragma once

namespace Infrastructure {
    class WindowObserver {
    public:
        // mouse events
        virtual void OnMouseMove(int x, int y, int dx, int dy, bool lbuttonDown, bool rbuttonDown) {}
        virtual void OnMouseLeftButton(bool pressed) {}
        virtual void OnMouseRightButton(bool pressed) {}

        // other
        virtual void OnClose() {}
    };
};
