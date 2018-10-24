#pragma once

namespace Infrastructure {
    class MouseObserver {
    public:
        // mouse events
        virtual void OnMouseMove(int x, int y, int dx, int dy, bool lbuttonDown, bool rbuttonDown) {}
        virtual void OnMouseLeftButton(int x, int y, bool pressed) {}
        virtual void OnMouseRightButton(int x, int y, bool pressed) {}
        virtual void OnMouseRightDrag(int startx, int starty, int endx, int endy, int dx, int dy) {}
    };
};
