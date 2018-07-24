#pragma once

#include <memory>

#include "src/Application/GameConfig.h"

#include "src/Infrastructure/Renderer/Renderer.h"

#include "src/Infrastructure/Window/Window.h"

namespace Application {
    class Game {
    typedef Infrastructure::Renderer Renderer;
    typedef Infrastructure::Window Window;
    public:
        void Run();

    private:
        void WaitScreen();
        void MainMenu();
        void Terminate();

        std::shared_ptr<const GameConfig> config;

        std::shared_ptr<Window> window;
        std::shared_ptr<Renderer> renderer;
    };
};