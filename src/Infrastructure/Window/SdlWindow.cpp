#if defined(WIN32)
    #define FIX_WINDOWS_BLOCKING_WINDOW
#endif

#if defined(FIX_WINDOWS_BLOCKING_WINDOW)
    #include <Windows.h>
    #include <SDL2/SDL_syswm.h>
#endif

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

void SdlWindow::SetWidth(int width) {
    SDL_SetWindowSize(window, width, GetHeight());
}

void SdlWindow::SetHeight(int height) {
    SDL_SetWindowSize(window, GetWidth(), height);
}

void SdlWindow::SetFullscreen() {
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);

    #if defined(FIX_WINDOWS_BLOCKING_WINDOW)
    {
        SDL_SysWMinfo info;
        SDL_VERSION(&info.version);

        if (SDL_GetWindowWMInfo(window, &info)) {
            auto hwnd = info.info.win.window;
            SetWindowPos(hwnd, HWND_BOTTOM, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_NOACTIVATE | SWP_SHOWWINDOW);
        }
    }
    #endif
}

int SdlWindow::GetWidth() const {
    int w, h;
    SDL_GetWindowSize(window, &w, &h);
    return w;
}

int SdlWindow::GetHeight() const {
    int w, h;
    SDL_GetWindowSize(window, &w, &h);
    return h;
}

void SdlWindow::PeekMessages() {
    //Event handler
    SDL_Event e;

    //Handle events on queue
    while (SDL_PollEvent(&e) != 0)
    {
        //User requests quit
        if (e.type == SDL_QUIT)
        {
            //quit = true;
        }
    }
}

void SdlWindow::WaitMessage() {
}
