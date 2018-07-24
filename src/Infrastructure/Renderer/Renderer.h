#pragma once

#include <memory>

#include "src/Infrastructure/Renderer/RendererConfig.h"

namespace Infrastructure {
    class Renderer {
    public:
        inline Renderer(std::shared_ptr<const RendererConfig> config) {}
        virtual ~Renderer() {}

        virtual bool Initialize() = 0;
    };
};
