#include <SDL2/SDL.h>

#include "src/Application/SdlWindow.h"

using Application::SdlWindow;

bool SdlWindow::Initialize() {
    window = SDL_CreateWindow(
		config->title.c_str(),      // window title
        SDL_WINDOWPOS_UNDEFINED,    // initial x position
        SDL_WINDOWPOS_UNDEFINED,    // initial y position
        config->width,              // width, in pixels
        config->height,             // height, in pixels
        SDL_WINDOW_OPENGL           // flags - see below
    );

    if (window == nullptr) {
        log->Info("SdlWindow::Initialize: %s", SDL_GetError());
        return false;
    }

    return true;
}