#include <SDL2/SDL.h>

#include "src/Application/WindowFactory.h"

#include "src/Application/SdlWindow.h"

using Application::WindowFactory;
using Application::IWindow;
using Application::SdlWindow;
using Application::WindowConfig;

std::shared_ptr<IWindow> WindowFactory::CreateSdlWindow(
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