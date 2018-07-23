#pragma once

#include <memory>
#include <string>

#include "src/Application/WindowConfig.h"

namespace Application {
    class WindowConfigFactory {
    public:
        std::shared_ptr<const WindowConfig> Create(
            const std::string &title, int width, int height
        );
    };
};
