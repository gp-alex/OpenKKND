#include "src/Infrastructure/Renderer/SdlRenderer.h"

using Infrastructure::SdlRenderer;

bool SdlRenderer::Initialize() {
    renderer = SDL_CreateRenderer(
        (SDL_Window *)config->window->GetApiHandle(),
        -1,
        SDL_RENDERER_ACCELERATED
    );

    if (renderer == nullptr) {
        log->Info("SdlRenderer::Initialize: %s", SDL_GetError());
    }

    return renderer != nullptr;
}