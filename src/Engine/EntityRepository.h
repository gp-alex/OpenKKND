#pragma once

#include <list>

#include "Engine/Entity.h"

class EntityRepository {
public:
    void Save(Entity *entity);
    void Delete(Entity *entity);

private:
    std::list<Entity> entities;
};