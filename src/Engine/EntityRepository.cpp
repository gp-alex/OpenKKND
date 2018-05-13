
//----- (0044C890) --------------------------------------------------------
void entity_list_remove(Entity *a1)
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
    a1->next = entity_list_free_pool;
    entity_list_free_pool = a1;
}
