#pragma once

#include "src/Infrastructure/Window/WindowConfig.h"

namespace Infrastructure {
    class Window {
    public:
        inline Window(std::shared_ptr<const WindowConfig> config) {}
        virtual ~Window() {}


        virtual bool Initialize() = 0;
        virtual void SetWidth(int width) = 0;
        virtual int GetWidth() const = 0;
        virtual void SetHeight(int height) = 0;
        virtual int GetHeight() const = 0;
        virtual void SetFullscreen() = 0;
        virtual void PeekMessages() = 0;
        virtual void WaitMessage() = 0;

        virtual void *GetApiHandle() const = 0;
    };
};
