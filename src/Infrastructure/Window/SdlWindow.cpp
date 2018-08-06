#if defined(_WINDOWS)
    #define FIX_WINDOWS_BLOCKING_WINDOW
#endif

#if defined(FIX_WINDOWS_BLOCKING_WINDOW)
    #include <Windows.h>
    #include <SDL2/SDL_syswm.h>
#endif

#include "src/Infrastructure/Window/SdlWindow.h"

using Infrastructure::SdlWindow;
using Infrastructure::WindowObserver;
    
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
    #if !defined(_DEBUG) || defined(_RELEASE)
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    #else
    {
        SDL_MaximizeWindow(window);
        #if defined(FIX_WINDOWS_BLOCKING_WINDOW)
        {
            SDL_SysWMinfo info;
            SDL_VERSION(&info.version);

            if (SDL_GetWindowWMInfo(window, &info)) {
                auto hwnd = info.info.win.window;

                SetWindowLongPtrA(hwnd, GWL_STYLE, WS_VISIBLE | WS_POPUP | WS_SYSMENU | WS_GROUP);
                SetWindowLongPtrA(hwnd, GWL_EXSTYLE, WS_EX_APPWINDOW);

                ShowWindow(hwnd, SW_MAXIMIZE);
                SetWindowPos(
                    hwnd, HWND_NOTOPMOST, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), 0
                );
                UpdateWindow(hwnd);
            }
        #endif
        }
    }
    #endif
}

void SdlWindow::SetWindowed() {
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

void SdlWindow::PeekMessageSingle() {
    SDL_Event e;
    if (SDL_PollEvent(&e) != 0) {
        MessageProcessor(e);
    }
}

void SdlWindow::PeekMessageAll() {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        MessageProcessor(e);
    }
}

void SdlWindow::WaitMessage() {
}


void SdlWindow::MessageProcessor(SDL_Event &e) {
    switch (e.type) {
        case SDL_QUIT: {
            for (auto observer : observerList) {
                observer->OnClose();
            }
            break;
        }

        case SDL_MOUSEMOTION: {
            for (auto observer : observerList) {
                observer->OnMouseMove(
                    e.motion.x, e.motion.y,
                    e.motion.xrel, e.motion.yrel,
                    e.motion.state & SDL_BUTTON_LMASK,
                    e.motion.state & SDL_BUTTON_RMASK
                );
            }
            break;
        }

        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP: {
            int x = e.button.x;
            int y = e.button.y;
            int numClicks = e.button.clicks;
            bool pressed = e.button.state == SDL_PRESSED;

            if (e.button.button == SDL_BUTTON_LEFT) {
                for (auto observer : observerList) {
                    observer->OnMouseLeftButton(x, y, pressed);
                }
            } else if (e.button.button == SDL_BUTTON_RIGHT) {
                for (auto observer : observerList) {
                    observer->OnMouseRightButton(x, y, pressed);
                }
            }
            break;
        }
    }
}


void SdlWindow::AddObserver(std::shared_ptr<WindowObserver> observer) {
    observerList.push_back(observer);
}

int SdlWindow::GetMouseX() const {
    int x, y;
    SDL_GetMouseState(&x, &y);
    return x;
}

int SdlWindow::GetMouseY() const {
    int x, y;
    SDL_GetMouseState(&x, &y);
    return y;
}

void SdlWindow::SetMouseX(int x) {
    int y = GetMouseY();
    SDL_WarpMouseInWindow(window, x, y);
}

void SdlWindow::SetMouseY(int y) {
    int x = GetMouseX();
    SDL_WarpMouseInWindow(window, x, y);
}

bool SdlWindow::GetMousePressed(int button) const {
    return SDL_GetRelativeMouseState(nullptr, nullptr) & SDL_BUTTON(button);
}

bool SdlWindow::GetIsActive() const {
    int activeFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_MOUSE_FOCUS;
    return (SDL_GetWindowFlags(window) & activeFlags) == activeFlags;
}

bool SdlWindow::GetScancodePressed(int scancode) const {
    auto state = SDL_GetKeyboardState(nullptr);
    return state[scancode] != 0;
}

bool SdlWindow::GetKeyPressedWindowsTmpHack(int vk) const {
    #if defined(_WINDOWS)
    {
        int scan = MapVirtualKey(vk, MAPVK_VK_TO_VSC);
        return GetScancodePressed(scan);
    }
    #else
    {
        throw 42;
    }
    #endif
}