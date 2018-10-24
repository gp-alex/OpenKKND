#pragma once

#include "src/Infrastructure/Window/MouseObserver.h"

namespace Infrastructure {
    class InputWindowObserver : public MouseObserver {
    public:
        inline InputWindowObserver() {}

        virtual void OnMouseMove(int x, int y, int dx, int dy, bool lbuttonDown, bool rbuttonDown) override;
        virtual void OnMouseLeftButton(int x, int y, bool pressed) override;
        virtual void OnMouseRightButton(int x, int y, bool pressed) override;
    };
}
