#pragma once

#include <list>

#include "Engine/Entity.h"

namespace Engine {
    namespace Infrastructure {
        class EntityRepository {
        public:
            Entity *FindById(int id);
            std::list<Entity *> FindAll();

            void Save(Entity *entity);
            void Delete(Entity *entity);
            void DeleteAll();



        private:
            std::list<Entity *> entities;
        };
    };
};

// should be injected
extern Engine::Infrastructure::EntityRepository *entityRepo;

//extern Entity *entity_list_head;
//extern Entity *entity_list_47D9AC;
//extern Entity *entity_list;
//extern Entity *entity_list_free_pool;