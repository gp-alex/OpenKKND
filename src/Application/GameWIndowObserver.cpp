#include "src/Application/GameWindowObserver.h"

using Application::GameWindowObserver;

void GameWindowObserver::OnClose() {
    if (auto p = game.lock()) {
        p->Exit();
    }
}
