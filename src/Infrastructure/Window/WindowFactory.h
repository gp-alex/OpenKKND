#pragma once

#include <memory>

#include "src/Infrastructure/DependencyInjection.h"

#include "src/Infrastructure/Window/Window.h"
#include "src/Infrastructure/Window/WindowConfig.h"
#include "src/Infrastructure/Window/WindowObserver.h"


namespace Infrastructure {
    class WindowFactory {
    public:
        inline WindowFactory() {
            this->log = InfrastructureDependencies::Resolve<Log>();
        }

        std::shared_ptr<Window> CreateSdlWindow(
            std::shared_ptr<const WindowConfig> config,
            std::shared_ptr<WindowObserver> observer = nullptr
        );

    private:
        std::shared_ptr<Log> log;
    };
};