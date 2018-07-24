#pragma once

#include <memory>
#include <string>

#include "src/Infrastructure/Window/Window.h"

namespace Infrastructure {
    class RendererConfig {
    public:
        std::string renderer = "SDL";
        std::shared_ptr<Window> window = nullptr;
        int width = 640;
        int height = 480;
        bool fullscreen = false;
    };
};
