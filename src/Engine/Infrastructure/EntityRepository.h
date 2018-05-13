#pragma once

#include <list>

#include "Engine/Entity.h"

namespace Engine {
    namespace Infrastructure {
        class EntityRepository {
        public:
            void Save(Entity *entity);
            void Delete(Entity *entity);

        private:
            std::list<Entity> entities;
        };
    };
};
