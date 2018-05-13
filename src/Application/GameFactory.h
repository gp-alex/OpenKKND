#pragma once

#include <memory>

#include "Application/Game.h"

namespace Application {
    class GameFactory {
    public:
        std::shared_ptr<Game> Create();
    };
};