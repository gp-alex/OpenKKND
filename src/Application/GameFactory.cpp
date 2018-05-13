#include "Application/GameFactory.h"

using Application::Game;
using Application::GameFactory;

std::shared_ptr<Game> GameFactory::Create() {
    return std::make_shared<Game>();
}