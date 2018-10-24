#pragma once

#include "src/Infrastructure/DependencyInjection.h"

#include "src/Infrastructure/Window/KeyboardObserver.h"

namespace Infrastructure {
    class InputKeyboardObserver : public KeyboardObserver {
    public:
        inline InputKeyboardObserver() {
            this->log = InfrastructureDependencies::Resolve<Log>();
        }

        virtual void OnCharUp(int key, bool ctrl_status, bool alt_status) override;
        virtual void OnSpecialKeyUp(int key, bool ctrl_status, bool alt_status) override;

    private:
        std::shared_ptr<Log> log;
    };
}
