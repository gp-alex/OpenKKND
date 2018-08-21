#pragma once

#include <memory>

#include "src/Application/Game.h"

#include "src/Infrastructure/Window/WindowObserver.h"

namespace Application {
    class GameWindowObserver : public Infrastructure::WindowObserver {
    public:
        inline GameWindowObserver(std::weak_ptr<Game> game) {
            this->game = game;
        }


        virtual void OnClose() override;

    private:
        std::weak_ptr<Game> game;
    };
}
