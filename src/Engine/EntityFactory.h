#pragma once

#include "Engine/Entity.h"

namespace Engine {
    class EntityFactory {
    public:
        Entity *Create(Script *a1);
    };
};
