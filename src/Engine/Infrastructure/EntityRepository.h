#pragma once

#include <functional>
#include <list>

#include "Engine/Entity.h"

namespace Engine {
    namespace Infrastructure {
        class EntityRepository {
        public:
            typedef std::function<bool(Entity *)> EntitySpecification;

            Entity *FindSingle(EntitySpecification spec) const;
            std::list<Entity *> FindAll(EntitySpecification spec) const;
            Entity *FindById(int id) const;
            std::list<Entity *> FindAll() const;

            int CountAll() const;

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