#include "src/Application/WindowConfigFactory.h"

using Application::WindowConfigFactory;
using Application::WindowConfig;

std::shared_ptr<const WindowConfig> WindowConfigFactory::Create(
    const std::string &title, int width, int height
) {
    auto config = std::make_shared<WindowConfig>();

    if (config != nullptr) {
        config->title = std::string(title);
        config->width = width;
        config->height = height;
    }

    return config;
}