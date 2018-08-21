#pragma once

#include <memory>

#include "src/Infrastructure/Renderer/RendererConfig.h"

namespace Infrastructure {
    class Renderer {
    public:
        inline Renderer(std::shared_ptr<const RendererConfig> config) {}
        virtual ~Renderer() {}

        virtual bool Initialize() = 0;
        virtual void ClearTarget(int r, int g, int b) = 0;
        virtual void Present() = 0;
        virtual void DrawImageCentered(int width, int height, const void *argb) = 0;
    };
};
