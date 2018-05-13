#pragma once

#include <memory>

#include "Application/GameConfig.h"

namespace Application {
    class Game {
    public:
        void Run();

    private:
        void WaitScreen();
        void Terminate();

        std::shared_ptr<const GameConfig> config;
    };
};