#include <SDL2/SDL.h>

#include "src/Infrastructure/Window/WindowFactory.h"

#include "src/Infrastructure/Window/SdlWindow.h"

using Infrastructure::WindowFactory;
using Infrastructure::Window;
using Infrastructure::SdlWindow;
using Infrastructure::WindowConfig;

std::shared_ptr<Window> WindowFactory::CreateSdlWindow(
    std::shared_ptr<const WindowConfig> config
) {
    static bool _sdl2_winitialized = false;
    if (!_sdl2_winitialized) {
        _sdl2_winitialized = SDL_Init(SDL_INIT_VIDEO) == 0;
    }
    if (!_sdl2_winitialized) {
        log->Info("SDL_Init error: %s", SDL_GetError());
        return nullptr;
    }

    auto window = std::make_shared<SdlWindow>(config);
    
    if (window) {
        if (!window->Initialize()) {
            window = nullptr;
        }
    }

    return window;
}