
//----- (00437FE0) --------------------------------------------------------
void EventHandler_UpgradeProcess(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param)
{
    int v4; // ecx@1

    v4 = (int)receiver->param;
    if (event == EVT_MSG_1545)
        *(_DWORD *)(v4 + 12) = 1;
}

//----- (00438000) --------------------------------------------------------
void EntityUpgradeAttachment_438000(EntityUpgradeAttachment *a1)
{
    EntityUpgradeAttachment *v1; // esi@1
    int *v2; // edi@1

    v1 = a1;
    v2 = (int *)a1->_18_sprite->param;
    stru38_list_427FD0(v2, 0);
    *v2 = 0;
    sprite_list_remove(v1->_18_sprite);
    script_yield(v1->script);
}

//----- (00438030) --------------------------------------------------------
void EntityUpgradeAttachment_438030(EntityUpgradeAttachment *a1)
{
    EntityUpgradeAttachment *v1; // esi@1
    Sprite *v2; // ecx@1
    int v3; // eax@1
    int v4; // edx@3

    v1 = a1;
    v2 = a1->_18_sprite;
    v3 = *(_DWORD *)v2->param;
    if (v3 <= 0)
    {
        v1->handler = EntityUpgradeAttachment_438000;
        return;
    }
    v4 = (v3 << 8) / 300;
    if (v4 > 50)
    {
        if (v4 > 100)
        {
            if (v4 > 150)
            {
                if (v4 > 200)
                {
                    if (v4 > 220)
                    {
                        if (v1->field_8 != 1)
                        {
                            v1->field_8 = 1;
                            sprite_load_mobd(v2, 604);
                        }
                    }
                    else if (v1->field_8 != 2)
                    {
                        sprite_427320_load_mobd_item_sound(v2, 640);
                        v1->field_8 = 2;
                        v1->handler = EntityUpgradeAttachment_438160_handler;
                        return;
                    }
                }
                else if (v1->field_8 != 3)
                {
                    sprite_427320_load_mobd_item_sound(v2, 676);
                    v1->field_8 = 3;
                    v1->handler = EntityUpgradeAttachment_438160_handler;
                    return;
                }
            }
            else if (v1->field_8 != 4)
            {
                sprite_427320_load_mobd_item_sound(v2, 712);
                v1->field_8 = 4;
                v1->handler = EntityUpgradeAttachment_438160_handler;
                return;
            }
        }
        else if (v1->field_8 != 5)
        {
            sprite_427320_load_mobd_item_sound(v2, 748);
            v1->field_8 = 5;
            v1->handler = EntityUpgradeAttachment_438160_handler;
            return;
        }
    }
    else if (v1->field_8 != 6)
    {
        sprite_427320_load_mobd_item_sound(v2, 784);
        v1->field_8 = 6;
        v1->handler = EntityUpgradeAttachment_438160_handler;
        return;
    }
    v1->handler = EntityUpgradeAttachment_438160_handler;
}

//----- (00438160) --------------------------------------------------------
void EntityUpgradeAttachment_438160_handler(EntityUpgradeAttachment *a1)
{
    int v1; // eax@3

    if (*(_DWORD *)&a1->_18_sprite_parent->field_8C_infantry_damage || a1->field_C)
    {
        a1->handler = EntityUpgradeAttachment_438000;
    }
    else
    {
        v1 = a1->field_4 - 1;
        a1->field_4 = v1;
        if (v1 <= 0)
        {
            a1->field_4 = 8;
            a1->handler = EntityUpgradeAttachment_438030;
        }
    }
}

//----- (004381A0) --------------------------------------------------------
void script_4381A0_upgrade_process(Script *a1)
{
    EntityUpgradeAttachment *v1; // eax@1
    Sprite *v2; // edx@3

    v1 = (EntityUpgradeAttachment *)a1->param;
    if (!v1)
    {
        v1 = (EntityUpgradeAttachment *)script_create_local_object(a1, 32);
        if (v1)
        {
            a1->param = v1;
            v1->field_4 = 0;
            v1->field_8 = 0;
            v2 = a1->sprite->parent;
            v1->field_C = 0;
            v1->_18_sprite_parent = v2;
            v1->_18_sprite = a1->sprite;
            v1->script = a1;
            v1->handler = EntityUpgradeAttachment_438160_handler;
            a1->script_type = SCRIPT_UPGRADE_PROCESS;
            a1->event_handler = EventHandler_UpgradeProcess;
        }
    }
    (v1->handler)(v1);
}

//----- (00438200) --------------------------------------------------------
void EventHandler_ResearchBuilding(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param)
{
    Script *v4; // ebp@1
    Entity *v5; // edi@1
    EntityBuildingState *v6; // ebx@1
    int v7; // eax@3
    int *v8; // ebx@3
    Sprite *v9; // eax@4
    int v10; // edx@4
    int v11; // edx@4
    int v12; // ecx@4
    int v13; // ecx@4
    int v14; // edx@4
    Script *v15; // ecx@4
    EntityBuildingState *v16; // [sp+10h] [bp-4h]@1

    v4 = receiver;
    v5 = (Entity *)receiver->param;
    v6 = (EntityBuildingState *)v5->state;
    v16 = (EntityBuildingState *)v5->state;
    if (!v5->destroyed)
    {
        switch (event)
        {
        case EVT_MSG_COMMENCE_UPGRADE:
            v7 = v6->field_8__0_for_repstation;
            v8 = &v6->field_8__0_for_repstation;
            if (!v7)
            {
                *v8 = 300;
                v9 = sprite_create_scripted(
                    MOBD_CURSORS,
                    *((Sprite **)param + 23),
                    script_4381A0_upgrade_process,
                    SCRIPT_FUNCTION,
                    0);
                v9->field_88_unused = 1;
                v10 = *(_DWORD *)(*((_DWORD *)param + 26) + 4);
                v9->field_88_unused = 1;
                v9->x += v10;
                v11 = *(_DWORD *)(*((_DWORD *)param + 26) + 8);
                v12 = v9->y;
                v9->param = v8;
                v13 = v11 + 0x100A00 + v12;
                v14 = v9->z_index;
                v9->y = v13;
                v15 = v9->script;
                v9->parent = (Sprite *)param;
                v9->z_index = v14 + 0x200000;
                v15->param = 0;
                v16->oilspot_for_drillrig__task_for_researchlab = v9->script;
                v5->sprite->parent = (Sprite *)*((_DWORD *)param + 76);
                stru37_list_427D60_enqueue_item((int *)&game_globals_per_player + v5->player_side, v8, 42, v4, param, -1);
                if (v5->player_side == player_side)
                {
                    show_message_ex(0, aCommencingUpgrade);
                    if (is_player_faction_evolved())
                        sound_play(SOUND_MUTE_COMMENCING_UPGRADE, 0, _4690A8_unit_sounds_volume, 16, 0);
                    else
                        sound_play(SOUND_SURV_COMMENCING_UPGRADE, 0, _4690A8_unit_sounds_volume, 16, 0);
                }
            }
            break;
        case EVT_MSG_PRODUCTION_READY:
            script_trigger_event(receiver, EVT_MSG_UPGRADE_COMPLETE, *((void **)param + 76), task_mobd17_cursor);
            if (v5->player_side == player_side)
            {
                show_message_ex(0, aUpgradeComplete);
                if (is_player_faction_evolved())
                {
                    if ((char)kknd_rand() % -2)
                        sound_play(SOUND_MUTE_UPGRADE_COMPLETE_2, 0, _4690A8_unit_sounds_volume, 16, 0);
                    else
                        sound_play(SOUND_MUTE_UPGRADE_COMPLETE_1, 0, _4690A8_unit_sounds_volume, 16, 0);
                }
                else if ((char)kknd_rand() % -2)
                {
                    sound_play(SOUND_SURV_UPGRADE_COMPLETE_2, 0, _4690A8_unit_sounds_volume, 16, 0);
                }
                else
                {
                    sound_play(SOUND_SURV_UPGRADE_COMPLETE_1, 0, _4690A8_unit_sounds_volume, 16, 0);
                }
            }
            break;
        case EVT_MSG_SABOTAGE:
            entity_sabotage(v5, param, entity_mode_researchlab_on_death);
            break;
        case EVT_MSG_DESTROY:
            entity_402E40_destroy(v5, entity_mode_researchlab_on_death);
            break;
        case EVT_MSG_DAMAGE:
            entity_402E90_on_damage(v5, param, entity_mode_researchlab_on_death);
            entity_410520_update_healthbar_color(v5);
            break;
        default:
            EventHandler_DefaultBuildingsHandler(receiver, sender, event, param);
            break;
        }
    }
}

//----- (004384D0) --------------------------------------------------------
void UNIT_Handler_ResearchBuilding(Script *a1)
{
    Entity *v1; // esi@1

    v1 = (Entity *)a1->param;
    if (!_47C6DC_dont_execute_unit_handlers)
    {
        if (!v1)
        {
            v1 = entity_list_create(a1);
            v1->script->event_handler = EventHandler_DefaultBuildingsHandler;
            entity_44B100_buildings__mess_with_fog_of_war(v1);
            entity_initialize_building(v1, 1, 0, 0);
            *((_DWORD *)v1->state + 2) = 0;
            *(_DWORD *)v1->state = 0;
            if (!v1->sprite->cplc_ptr1_pstru20)
            {
                entity_402BB0_set_arrive_handler(v1, entity_mode_researchlab_completed);
                (v1->mode)(v1);
                return;
            }
            v1->mode = entity_mode_researchlab_completed;
        }
        (v1->mode)(v1);
    }
}
// 47C6DC: using guessed type int _47C6DC_dont_execute_unit_handlers;

//----- (00438550) --------------------------------------------------------
void entity_mode_researchlab_completed(Entity *a1)
{
    Entity *v1; // esi@1
    EntityTurret *v2; // eax@1
    enum SOUND_ID v3; // ecx@6
    int v4; // [sp-Ch] [bp-10h]@6

    v1 = a1;
    v2 = a1->turret;
    if (v2)
        v2->turret_sprite->drawjob->flags &= 0xBFFFFFFF;
    if (player_side == a1->player_side && !a1->sprite->cplc_ptr1_pstru20)
    {
        show_message_ex(0, aBuildingCompleted);
        if (is_player_faction_evolved())
        {
            v4 = _4690A8_unit_sounds_volume;
            v3 = SOUND_MUTE_BUILDING_COMPLETED;
        }
        else
        {
            v4 = _4690A8_unit_sounds_volume;
            v3 = SOUND_SURV_BUILDING_COMPLETED;
        }
        sound_play(v3, 0, v4, 16, 0);
    }
    v1->script->event_handler = EventHandler_ResearchBuilding;
    v1->script->script_type = SCRIPT_RESEARCH_BUILDING_HANDLER;
    if (v1->sprite->cplc_ptr1_pstru20)
    {
        v1->mode = entity_mode_4034B0;
        entity_mode_403650_building(v1);
    }
    else
    {
        v1->mode = entity_mode_403650_building;
        entity_mode_403650_building(v1);
    }
}

//----- (00438600) --------------------------------------------------------
void entity_mode_researchlab_on_death(Entity *a1)
{
    Entity *v1; // edi@1
    int *v2; // esi@1

    v1 = a1;
    v2 = (int *)((char *)a1->state + 8);
    if (*v2)
    {
        stru38_list_427FD0(v2, 0);
        *v2 = 0;
    }
    entity_mode_building_default_on_death(v1);
}

//----- (00438630) --------------------------------------------------------
int _438630_read_save_lst()
{
    FILE *v0; // ebx@1
    stru175 *v1; // eax@2
    stru175 *v2; // edx@3
    int v3; // eax@4
    int v4; // eax@7
    int v5; // edx@10
    int v7; // [sp+Ch] [bp-18h]@7
    stru175 *v8; // [sp+10h] [bp-14h]@10
    enum LEVEL_ID v9; // [sp+14h] [bp-10h]@7
    int v10; // [sp+18h] [bp-Ch]@7
    int v11; // [sp+1Ch] [bp-8h]@7
    int v12; // [sp+20h] [bp-4h]@7

    sprintf(byte_47C230, aSSave_lst, game_data_installation_dir);
    v0 = fopen(byte_47C230, aR);
    if (v0)
    {
        _47C050_array_idx = 0;
        v1 = _47C050_array;
        do
        {
            v2 = v1;
            ++v1;
            *(_DWORD *)&v2->str_0[0] = 0;
            *(_DWORD *)&v2->str_0[4] = 0;
            *(_DWORD *)&v2->str_0[8] = 0;
        } while ((int)v1 < (int)byte_47C230);
        v3 = fscanf(v0, aActiveslotD, &_47C050_array_idx);
        if (!v3)
            _47C050_array_idx = 0;
        if (v3 != -1)
        {
            while (1)
            {
                v10 = 0;
                v11 = 0;
                v12 = 0;
                v4 = fscanf(v0, aSlotDSD, &v7, &v10, &v9);
                if (!v4 || v4 == -1)
                    break;
                if (v7 <= 19)
                {
                    v5 = v7;
                    v8 = &_47C050_array[v7];
                    strcpy(_47C050_array[v7].str_0, (const char *)&v10);
                    _47C050_array[v5].level_id = v9;
                }
            }
        }
        fclose(v0);
    }
    return 0;
}