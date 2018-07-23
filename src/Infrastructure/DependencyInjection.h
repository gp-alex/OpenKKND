#pragma once

#include <memory>

#include "src/Infrastructure/Log.h"

namespace Infrastructure {
    class DependencyInjection {
    public:
        template<typename T>
        static std::shared_ptr<T> Resolve() {
            return nullptr;
        }

        template<>
        static std::shared_ptr<Log> Resolve() {
            if (log == nullptr) {
                log = std::make_shared<Log>();
            }
            return log;
        }

    private:
        static std::shared_ptr<Log> log;
    };
};