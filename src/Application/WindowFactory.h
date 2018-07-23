#pragma once

#include <memory>

#include "src/Application/IWindow.h"
#include "src/Application/WindowConfig.h"

#include "src/Infrastructure/DependencyInjection.h"

namespace Application {
    using InfrastructureDependencies = Infrastructure::DependencyInjection;
    using Infrastructure::Log;

    class WindowFactory {
    public:
        inline WindowFactory() {
            this->log = InfrastructureDependencies::Resolve<Log>();
        }

        std::shared_ptr<IWindow> CreateSdlWindow(
            std::shared_ptr<const WindowConfig> config
        );

    private:
        std::shared_ptr<Log> log;
    };
};