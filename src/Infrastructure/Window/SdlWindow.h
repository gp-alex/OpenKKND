#pragma once

#include <SDL2/SDL.h>

#include "src/Infrastructure/DependencyInjection.h"

#include "src/Infrastructure/Window/Window.h"
#include "src/Infrastructure/Window/WindowConfig.h"

namespace Infrastructure {
    class SdlWindow : public Window {
    public:
        inline SdlWindow(std::shared_ptr<const WindowConfig> config) : Window(config) {
            this->config = config;
            this->log = InfrastructureDependencies::Resolve<Log>();
        }

        virtual bool Initialize() override;

        virtual void *GetApiHandle() const {
            return window;
        };

    private:
        std::shared_ptr<const WindowConfig> config = nullptr;
        std::shared_ptr<Log> log = nullptr;

        SDL_Window *window = nullptr;
    };
};
