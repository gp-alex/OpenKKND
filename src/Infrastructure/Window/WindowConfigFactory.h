#pragma once

#include <memory>
#include <string>

#include "src/Infrastructure/Window/WindowConfig.h"

namespace Infrastructure {
    class WindowConfigFactory {
    public:
        std::shared_ptr<const WindowConfig> Create(
            const std::string &title, int width, int height
        );
    };
};
