#pragma once

#include <SDL2/SDL.h>

#include "src/Application/IWindow.h"
#include "src/Application/WindowConfig.h"

#include "src/Infrastructure/DependencyInjection.h"
#include "src/Infrastructure/Log.h"

namespace Application {
    class SdlWindow : public IWindow {
    using InfrastructureDependencies = Infrastructure::DependencyInjection;
    using Log = Infrastructure::Log;

    public:
        inline SdlWindow(std::shared_ptr<const WindowConfig> config) {
            this->config = config;
            this->log = InfrastructureDependencies::Resolve<Log>();
        }

        bool Initialize() override;

    private:
        std::shared_ptr<const WindowConfig> config = nullptr;
        std::shared_ptr<Log> log = nullptr;

        SDL_Window *window = nullptr;
    };
};
