#include "Engine/Infrastructure/EntityRepository.h"

using Engine::Infrastructure::EntityRepository;

#include <algorithm>

#include "_unsorted_data.h"
#include "kknd.h"



EntityRepository *entityRepo = nullptr;

Entity *entity_list_head;
Entity *entity_list_47D9AC;
Entity *entity_list;
Entity *entity_list_free_pool;


Entity *EntityRepository::FindById(int id) {
    if (id == -1) {
        return nullptr;
    }

    auto entity = std::find_if(
        entities.begin(),
        entities.end(),
        [&](Entity *const& entity) {
            return entity->entity_id == id;
        }
    );

    if (entity != entities.end()) {
        return *entity;
    }

    return nullptr;
}

std::list<Entity *> EntityRepository::FindAll() {
    return std::list<Entity *>(entities);
}

void EntityRepository::Save(Entity *entity) {
    if (entities.size() > 0) {
        auto last = *entities.rbegin();

        last->next = entity;
        entity->prev = last;
    } else {
        entity->prev = nullptr;
    }

    entity->next = nullptr;

    entities.push_back(entity);
}

//----- (0044C890) --------------------------------------------------------
void EntityRepository::Delete(Entity *a1)
{
    enum PLAYER_SIDE v1; // eax@1
    DrawJob *v2; // eax@7

    v1 = a1->player_side;
    if (v1 == player_side)
    {
        if (UNIT_num_player_units > 0)
            --UNIT_num_player_units;
    }
    else if (v1 && UNIT_num_nonplayer_units > 0)
    {
        --UNIT_num_nonplayer_units;
    }
    v2 = a1->drawjob;
    a1->entity_id = 0;
    v2->job_details.image = 0;
    a1->drawjob->flags |= 0x80000000;

    a1->next->prev = a1->prev;
    a1->prev->next = a1->next;
    //a1->next = entity_list_free_pool;
    //entity_list_free_pool = a1;
    entities.remove(a1);
}
