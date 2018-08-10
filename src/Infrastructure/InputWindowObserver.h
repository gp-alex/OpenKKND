#pragma once

#include "src/Infrastructure/Window/InputObserver.h"

namespace Infrastructure {
    class InputWindowObserver : public InputObserver {
    public:
        inline InputWindowObserver() {}

        virtual void OnMouseMove(int x, int y, int dx, int dy, bool lbuttonDown, bool rbuttonDown) override;
        virtual void OnMouseLeftButton(int x, int y, bool pressed) override;
        virtual void OnMouseRightButton(int x, int y, bool pressed) override;
    };
}
