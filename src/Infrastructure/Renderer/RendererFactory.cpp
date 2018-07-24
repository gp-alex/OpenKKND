#include "src/Infrastructure/Renderer/RendererFactory.h"

#include "src/Infrastructure/Renderer/SdlRenderer.h"

using Infrastructure::Renderer;
using Infrastructure::RendererConfig;
using Infrastructure::RendererFactory;
using Infrastructure::SdlRenderer;


std::shared_ptr<Renderer> RendererFactory::CreateSdl2(
    std::shared_ptr<const RendererConfig> config
) {
    auto renderer = std::make_shared<SdlRenderer>(config);

    if (renderer) {
        if (!renderer->Initialize()) {
            renderer = nullptr;
        }
    }

    return renderer;
}