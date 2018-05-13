#pragma once

#include <memory>

#include "Application/GameConfig.h"

namespace Application {
    class GameConfigFactory {
    public:
        std::shared_ptr<GameConfig> Create();
    };
};