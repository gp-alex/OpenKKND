#include <SDL2/SDL.h>

#include "src/Infrastructure/Window/SdlWindow.h"

using Infrastructure::SdlWindow;
    
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

    static const char *icons[] = {
        "assets/iconsurv.bmp",
        "assets/iconmute.bmp"
    };

    auto surface = SDL_LoadBMP(
        icons[SDL_GetTicks() / 10 % 2]
    );
    if (surface) {
        SDL_SetWindowIcon(window, surface);
        SDL_FreeSurface(surface);
    }

    return true;
}