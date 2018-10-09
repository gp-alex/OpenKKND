#if defined(_WINDOWS)
#define FIX_WINDOWS_BLOCKING_WINDOW
#endif

#if defined(FIX_WINDOWS_BLOCKING_WINDOW)
#include <Windows.h>
#include <SDL2/SDL_syswm.h>
#endif

#include "src/Infrastructure/Window/SdlWindow.h"

using Infrastructure::SdlWindow;
using Infrastructure::InputObserver;
using Infrastructure::WindowObserver;

/* kknd key mask to SDL scancode mapping */
std::map<int, int> kknd_key_mask_scancode_map =
{
    { INPUT_KEYBOARD_UP_MASK, SDL_SCANCODE_UP },                // VK_UP - up arrow
    { INPUT_KEYBOARD_DOWN_MASK, SDL_SCANCODE_DOWN },            // VK_DOWN - down arrow
    { INPUT_KEYBOARD_LEFT_MASK, SDL_SCANCODE_LEFT },            // VK_LEFT - left arrow
    { INPUT_KEYBOARD_RIGHT_MASK, SDL_SCANCODE_RIGHT },          // VK_RIGHT - right arrow
    { INPUT_KEYBOARD_CONTROL_MASK, SDL_SCANCODE_LCTRL },        // VK_CONTROL - ctrl key (special case also RCTRL)
    { INPUT_KEYBOARD_MENU_MASK, SDL_SCANCODE_LALT },            // VK_MENU - alt key (special case also RALT)
    { INPUT_KEYBOARD_HOME_MASK, SDL_SCANCODE_HOME },            // VK_HOME - home key 
    { INPUT_KEYBOARD_END_MASK ,SDL_SCANCODE_END },              // VK_END - end key
    { INPUT_KEYBOARD_PAGEUP_MASK, SDL_SCANCODE_PAGEUP },        // VK_PRIOR - page up key
    { INPUT_KEYBOARD_PAGEDOWN_MASK, SDL_SCANCODE_PAGEDOWN },    // VK_NEXT - page down key
    { INPUT_KEYBOARD_SHIFT_MASK, SDL_SCANCODE_LSHIFT },         // VK_SHIFT - shift key (special case also RSHIFT)
    { INPUT_KEYBOARD_RETURN_MASK, SDL_SCANCODE_RETURN },        // VK_RETURN  - enter key
    { INPUT_KEYBOARD_TAB_MASK, SDL_SCANCODE_TAB },              // VK_TAB - tab key
    { INPUT_KEYBOARD_ESCAPE_MASK, SDL_SCANCODE_ESCAPE },        // VK_ESCAPE - escape key
    { INPUT_KEYBOARD_A_MASK, SDL_SCANCODE_A },                  // 'A' key
    { INPUT_KEYBOARD_R_MASK, SDL_SCANCODE_R },                  // 'R' key
    { INPUT_KEYBOARD_F_MASK, SDL_SCANCODE_F },                  // 'F' key
    { INPUT_KEYBOARD_I_MASK, SDL_SCANCODE_I },                  // 'I' key
    { INPUT_KEYBOARD_H_MASK, SDL_SCANCODE_H },                  // 'H' key
    { INPUT_KEYBOARD_MINUS_MASK, SDL_SCANCODE_KP_MINUS },       // VK_OEM_MINUS - '-' minus key (special case also SDL_SCANCODE_MINUS ??)
    { INPUT_KEYBOARD_PLUS_MASK, SDL_SCANCODE_KP_PLUS },         // VK_OEM_PLUS - '+' plus key
    { INPUT_KEYBOARD_F1_MASK, SDL_SCANCODE_F1 },                // VK_F1 - F1 key
    { INPUT_KEYBOARD_F2_MASK, SDL_SCANCODE_F2 },                // VK_F2 - F2 key
    { INPUT_KEYBOARD_F3_MASK, SDL_SCANCODE_F3 },                // VK_F3 - F3 key
    { 0, 0 }
};


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

    // prevent cursor from leaving window (needed for window mode)
    SDL_SetWindowGrab(window, SDL_TRUE);

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
                    hwnd, HWND_NOTOPMOST, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SW_SHOW
                );
                UpdateWindow(hwnd);
            }
#endif
        }
    }
#endif
}

void *SdlWindow::GetHwnd() const {
    SDL_SysWMinfo info;
    SDL_VERSION(&info.version);

    if (SDL_GetWindowWMInfo(window, &info)) {
        return info.info.win.window;
    }
    return nullptr;
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
        for (auto observer : windowObservers) {
            observer->OnClose();
        }
        break;
    }

    case SDL_MOUSEMOTION: {
        for (auto observer : inputObservers) {
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
            for (auto observer : inputObservers) {
                observer->OnMouseLeftButton(x, y, pressed);
            }
        } else if (e.button.button == SDL_BUTTON_RIGHT) {
            for (auto observer : inputObservers) {
                observer->OnMouseRightButton(x, y, pressed);
            }
        }
        break;
    }
    }
}


void SdlWindow::AddObserver(std::shared_ptr<WindowObserver> observer) {
    windowObservers.push_back(observer);
}

void SdlWindow::AddObserver(std::shared_ptr<InputObserver> observer) {
    inputObservers.push_back(observer);
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

void SdlWindow::SetMousePos(int x, int y) {
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

bool SdlWindow::GetIsKKNDKeyPressed(int kknd_key_mask) const {
    return GetScancodePressed(kknd_key_mask_scancode_map[kknd_key_mask]);
}