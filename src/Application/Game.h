#pragma once

#include <memory>

#include "src/Application/GameConfig.h"

#include "src/Infrastructure/Renderer/Renderer.h"
#include "src/Infrastructure/Window/Window.h"

namespace Application {
    class Game : public std::enable_shared_from_this<Game> {
    typedef Infrastructure::Renderer Renderer;
    typedef Infrastructure::Window Window;
    public:
        void Run();
        void Exit();

    private:
        void WaitScreen();
        void MainMenu();
        void Terminate();

        std::shared_ptr<const GameConfig> config;

        std::shared_ptr<Window> window;
        std::shared_ptr<Renderer> renderer;
    };
};