#include "src/Application/GameWindowObserver.h"

using Application::GameWindowObserver;

void GameWindowObserver::OnClose() {
    extern bool _47DCF4_wm_quit_received;
    _47DCF4_wm_quit_received = true;

    if (auto p = game.lock()) {
        p->Exit();
    }
}
