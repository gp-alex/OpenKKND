#pragma once

#include "src/Infrastructure/Window/WindowConfig.h"

namespace Infrastructure {
    class Window {
    public:
        inline Window(std::shared_ptr<const WindowConfig> config) {}
        virtual ~Window() {}


        virtual bool Initialize() = 0;

        virtual void *GetApiHandle() const = 0;
    };
};
