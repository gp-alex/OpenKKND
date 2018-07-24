#pragma once

#include <SDL2/SDL.h>

#include "src/Infrastructure/DependencyInjection.h"

#include "src/Infrastructure/Renderer/Renderer.h"

namespace Infrastructure {
    class SdlRenderer : public Renderer {
    public:
        inline SdlRenderer(std::shared_ptr<const RendererConfig> config) : Renderer(config) {
            this->config = config;
            this->log = InfrastructureDependencies::Resolve<Log>();
        }

        virtual bool Initialize() override;

    private:
        std::shared_ptr<const RendererConfig> config = nullptr;
        std::shared_ptr<Log> log = nullptr;

        SDL_Renderer *renderer = nullptr;
    };
};
