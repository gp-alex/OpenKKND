#pragma once

#include <memory>
#include <string>

#include "src/Infrastructure/Renderer/RendererConfig.h"

namespace Infrastructure {
    class RendererConfigFactory {
    public:
        inline std::shared_ptr<const RendererConfig> Create(
            const std::string &renderer,
            std::shared_ptr<Window> window,
            int width,
            int height,
            bool fullscreen
        ) {
            auto config = std::make_shared<RendererConfig>();
            
            if (config) {
                config->renderer = renderer;
                config->window = window;
                config->width = width;
                config->height = height;
                config->fullscreen = fullscreen;
            }

            return config;
        }
    };
};
