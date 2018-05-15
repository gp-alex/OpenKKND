#pragma once

#include "Engine/Entity.h"

struct EntitySerialized;

namespace Engine {
    class EntityFactory {
    public:
        Entity *Create(Script *a1);
        Entity *Unpack(EntitySerialized *a1);
    };
};
