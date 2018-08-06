#pragma once

#include <memory>
#include <list>

#include <SDL2/SDL.h>

#include "src/Infrastructure/DependencyInjection.h"
#include "src/Infrastructure/Window/Window.h"
#include "src/Infrastructure/Window/WindowConfig.h"
#include "src/Infrastructure/Window/WindowObserver.h"



namespace Infrastructure {
    class SdlWindow : public Window {
    public:
        inline SdlWindow(std::shared_ptr<const WindowConfig> config) : Window(config) {
            this->config = config;
            this->log = InfrastructureDependencies::Resolve<Log>();
        }

        // 
        virtual bool Initialize() override;
        virtual void AddObserver(std::shared_ptr<WindowObserver> observer) override;

        // dimensions
        virtual void SetWidth(int width) override;
        virtual int GetWidth() const override;
        virtual void SetHeight(int height) override;
        virtual int GetHeight() const override;

        // appearance
        virtual void SetFullscreen() override;
        virtual void SetWindowed() override;

        // behaviour
        virtual bool GetIsActive() const override;

        // input
        virtual int GetMouseX() const override;
        virtual void SetMouseX(int x) override;
        virtual int GetMouseY() const override;
        virtual void SetMouseY(int y) override;
        virtual bool GetMousePressed(int button) const override;
        virtual bool GetKeyPressedWindowsTmpHack(int vk) const override;

        // messaging
        virtual void PeekMessageSingle() override;
        virtual void PeekMessageAll() override;
        virtual void WaitMessage() override;

        // misc
        virtual void *GetApiHandle() const {
            return window;
        };

    private:
        void MessageProcessor(SDL_Event &e);

        bool GetScancodePressed(int scancode) const;

        std::shared_ptr<const WindowConfig> config = nullptr;
        std::shared_ptr<Log> log = nullptr;

        typedef std::list<std::shared_ptr<WindowObserver>> ObserverList;
        ObserverList observerList;

        SDL_Window *window = nullptr;
    };
};
