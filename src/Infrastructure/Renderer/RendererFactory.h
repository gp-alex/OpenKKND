#pragma once

#include <memory>

#include "src/Infrastructure/Renderer/Renderer.h"
#include "src/Infrastructure/Renderer/RendererConfig.h"

namespace Infrastructure {
    class RendererFactory {
    public:
        std::shared_ptr<Renderer> CreateSdl2(
            std::shared_ptr<const RendererConfig> config
        );
    };
};
