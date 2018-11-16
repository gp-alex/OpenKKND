#include <assert.h>
#include <time.h>

#include "src/kknd.h"

#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"
#include "src/Cursor.h"
#include "src/Coroutine.h"
#include "src/Map.h"
#include "src/Pathfind.h"
#include "src/Random.h"
#include "src/Render.h"
#include "src/RenderDrawHandlers.h"
#include "src/Script.h"
#include "src/ScriptEvent.h"
#include "src/Sound.h"
#include "src/Sprite.h"
#include "src/stru29.h"
#include "src/stru31.h"
#include "src/Video.h"

#include "src/Application/Game.h"
#include "src/Application/GameFactory.h"

using Application::Game;
using Application::GameFactory;

#include "src/Application/Scripts/GameMenu.h"

#include "src/Engine/BuildingLimits.h"
#include "src/Engine/Entity.h"
#include "src/Engine/EntityFactory.h"

using Engine::EntityFactory;

#include "src/Engine/Infrastructure/EntityRepository.h"

using Engine::Infrastructure::EntityRepository;

#include "src/Infrastructure/File.h"
#include "src/Infrastructure/Input.h"

#include "src/Infrastructure/PlatformSpecific/OsTools.h"


void MessageHandler_MobileOutpostEmpty(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param) {
}
void nullsub_1(void) {}







bool mobile_base_can_deploy(Entity *entity)
{
    UNIT_ID unit_id = entity->unit_id;

    entity->unit_id = unit_id == UNIT_STATS_SURV_MOBILE_OUTPOST ? UNIT_STATS_SURV_OUTPOST : UNIT_STATS_MUTE_CLANHALL;

    bool result = entity_40DBF0_boxd_does_unit_fit(entity);
    entity->unit_id = unit_id;

    return result;
}

//----- (004019A0) --------------------------------------------------------
void Task_context_0_4019A0(Task_context_0 *a1)
{
	int v1; // eax@2
	int v2; // eax@5

	if (a1->field_4 > 0)
	{
		a1->sprite_1->pstru7 = _4640E0_stru7_array;
		a1->sprite_1->drawjob->flags &= 0xBFFFFFFF;
		v1 = a1->field_4;
		a1->handler = Task_context_0_401A80;
		if (v1 > 0)
		{
			if (v1 <= 1)
			{
				a1->sprite_2->drawjob->flags |= 0x40000000u;
			}
			else
			{
				a1->sprite_2->drawjob->flags &= 0xBFFFFFFF;
				v2 = a1->field_4;
				if (v2 <= 9)
					sprite_4272E0_load_mobd_item(a1->sprite_2, 2276, v2 - 1);
				else
					sprite_4272E0_load_mobd_item(a1->sprite_2, 2276, 8);
			}
		}
		else
		{
			a1->field_4 = 0;
			a1->handler = Task_context_0_401A40;
		}
	}
}

//----- (00401A40) --------------------------------------------------------
void Task_context_0_401A40(Task_context_0 *a1)
{
	a1->sprite_1->pstru7 = &_479D48_stru7;
	a1->sprite_1->drawjob->flags |= 0x40000000u;
	a1->sprite_2->drawjob->flags |= 0x40000000u;
	a1->handler = Task_context_0_4019A0;
}

//----- (00401A80) --------------------------------------------------------
void Task_context_0_401A80(Task_context_0 *a1)
{
	int v1; // eax@1
	int v2; // eax@4

	v1 = a1->field_4;
	if (v1 > 0)
	{
		if (v1 <= 1)
		{
			a1->sprite_2->drawjob->flags |= 0x40000000u;
		}
		else
		{
			a1->sprite_2->drawjob->flags &= 0xBFFFFFFF;
			v2 = a1->field_4;
			if (v2 <= 9)
				sprite_4272E0_load_mobd_item(a1->sprite_2, 2276, v2 - 1);
			else
				sprite_4272E0_load_mobd_item(a1->sprite_2, 2276, 8);
		}
	}
	else
	{
		a1->field_4 = 0;
		a1->handler = Task_context_0_401A40;
	}
}

//----- (00401AF0) --------------------------------------------------------
void Task_context_0_401AF0(Task_context_0 *a1)
{
	int v1; // eax@1
	int v2; // eax@4

	a1->sprite_1->pstru7 = _4640E0_stru7_array;
	a1->sprite_1->drawjob->flags &= 0xBFFFFFFF;
	v1 = a1->field_4;
	a1->handler = Task_context_0_401A80;
	if (v1 > 0)
	{
		if (v1 <= 1)
		{
			a1->sprite_2->drawjob->flags |= 0x40000000u;
		}
		else
		{
			a1->sprite_2->drawjob->flags &= 0xBFFFFFFF;
			v2 = a1->field_4;
			if (v2 <= 9)
				sprite_4272E0_load_mobd_item(a1->sprite_2, 2276, v2 - 1);
			else
				sprite_4272E0_load_mobd_item(a1->sprite_2, 2276, 8);
		}
	}
	else
	{
		a1->field_4 = 0;
		a1->handler = Task_context_0_401A40;
	}
}

//----- (00401B80) --------------------------------------------------------
void EventHandler_401B80(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param)
{
	Task_context_0 *v4; // eax@1
	int v5; // ecx@5
	int v6; // ecx@8

	v4 = (Task_context_0 *)receiver->param;
	switch (event)
	{
	case EVT_MSG_1548_sidebar:
		if (v4->field_4 > 0)
		{
			do
			{
				if (UNIT_num_player_units > 0)
					--UNIT_num_player_units;
				v5 = v4->field_4 - 1;
				v4->field_4 = v5;
			} while (v5 > 0);
		}
		goto LABEL_6;
	case EVT_MSG_1514:
	LABEL_6:
		v4->field_4 = 0;
		v4->handler = Task_context_0_401A40;
		break;
	case EVT_MSG_SELECTED:
		++v4->field_4;
		break;
	case EVT_MSG_DESELECTED:
		v6 = v4->field_4;
		if (v6 > 0)
			v4->field_4 = v6 - 1;
		break;
	default:
		return;
	}
}
// 47DCC8: using guessed type int UNIT_num_player_units;

//----- (00401C30) --------------------------------------------------------
void script_401C30_sidebar(Script *a1)
{
	Task_context_0 *v1; // edi@1
	Sprite *v2; // esi@3
	Sprite *v3; // ebx@3
	DrawJob *v4; // ecx@3

	v1 = (Task_context_0 *)a1->param;
	if (!v1)
	{
		v1 = (Task_context_0 *)script_create_local_object(a1, 20);
		if (v1)
		{
			v2 = a1->sprite;
			v3 = _47CA08_sidebar_buttons[1]->sprite;
			a1->param = v1;
			v1->sprite_1 = v3;
			v1->field_4 = 0;
			v1->sprite_2 = v2;
			v1->task = a1;
			v1->handler = Task_context_0_401A40;
			a1->event_handler = EventHandler_401B80;
			is_player_faction_evolved();
			v3->x = 0x26000;
			v3->field_88_unused = 1;
			v3->y = 0x12000;
			v3->z_index = 2;
			v4 = v2->drawjob;
			v2->x = 0x26400;
			v2->field_88_unused = 1;
			v2->y = 0x13800;
			v2->z_index = 3;
			v4->on_update_handler = (DrawUpdateHandler)drawjob_update_handler_4483E0_sidebar;
			v2->drawjob->job_details.palette = per_player_sprite_palettes[player_sprite_color_by_player_side[player_side]];
			v2->drawjob->flags |= 0x10000000u;
			sprite_4272E0_load_mobd_item(v2, 2276, 0);
		}
	}
	(v1->handler)(v1);
}

//----- (00402AB0) --------------------------------------------------------
void entity_mode_402AB0(Entity *a1)
{
	dword_477358 = 76354;
}
// 477358: using guessed type int dword_477358;

//----- (00402AC0) --------------------------------------------------------
bool entity_402AC0_is_mode_402AB0(Entity *a1)
{
    return a1->IsMode(entity_mode_402AB0);
}

//----- (00402AD0) --------------------------------------------------------
void entity_attach_docking_point(Entity *a1)
{
	Entity *v1; // ebx@1
	EntityTurret *v2; // esi@1
	Sprite *v3; // eax@2
	Script *v4; // eax@2

	v1 = a1;
	v2 = (EntityTurret *)script_create_local_object(a1->script, 56);
	if (v2)
	{
		memset(v2, 0, sizeof(EntityTurret));
		v3 = sprite_create_scripted(
			v1->stats->attach->mobd_id,
			v1->sprite,
			UNIT_AttachHandler_DockPoint,
			SCRIPT_FUNCTION,
			v1->stru60.ptr_0
        );
		v2->turret_sprite = v3;
		v3->drawjob->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_44BDC0_entity_turret;
		v2->turret_sprite->drawjob->job_details.palette = per_player_sprite_palettes[player_sprite_color_by_player_side[v1->player_side]];
		v2->turret_sprite->drawjob->flags |= 0x10000000u;
		v2->turret_sprite->drawjob->flags |= 0x40000000u;
		v4 = v2->turret_sprite->script;
		v2->sprite_task = v4;
		v4->param = v2;
		v2->turret_sprite->param = v2;
		v2->sprite_task->SetEventHandler(MessageHandler_EntityScript);
		v2->entity = v1;
		v2->_C_entity = 0;
		v2->SetHandler(EntityTurret_44BF00_handler);
		v2->field_18 = 0;
		v2->mobd_lookup_id = v1->GetCurrentAnimFrame();
		v2->stats_attachment_point = v1->stats->attach;
	}
	v1->turret = v2;
}

//----- (00402BB0) --------------------------------------------------------
DrawJob *entity_402BB0_set_arrive_handler(Entity *a1, void(*mode_arrive)(Entity *))
{
	Entity *v2; // esi@1
	void(*mOde_arrive)(Entity *); // edi@1
	Sprite *v4; // eax@3
	DataMobdItem_stru1 *v5; // eax@3
	int i; // ecx@4
	DrawJob *result; // eax@8

	v2 = a1;
	mOde_arrive = mode_arrive;
	sprite_4272E0_load_mobd_item(a1->sprite, a1->stats->mobd_lookup_offset_attack, 0);
	if (v2->player_side == player_side)
		script_trigger_event(v2->script, EVT_MSG_NEXT_CONSTRUCTION_STATE, v2, game_cursor_script);
	v4 = v2->sprite;
	v2->mode_arrive = mode_arrive;
	v5 = v4->_54_inside_mobd_ptr4->field_18;
	if (v5)
	{
		for (i = v5->field_0; i != -1; v5 = (DataMobdItem_stru1 *)((char *)v5 + 16))
		{
			if (i == 3)
				v2->stru60.ptr_C = v5;
			i = v5->field_10;
		}
	}
	entity_40DD00_boxd(v2);
	result = v2->sprite->drawjob;
	result->flags &= 0xBFFFFFFF;
	v2->SetMode(entity_mode_402AB0);
	return result;
}

//----- (00402C40) --------------------------------------------------------
void entity_402C40_lower_hp_mute09_surv21(Entity *a1)
{
	if (a1->player_side == 0
		&& (current_level_idx == LEVEL_MUTE_09_FIGHT_FOR_TERRITORY || current_level_idx == LEVEL_SURV_21))
	{
		a1->hitpoints = a1->stats->hitpoints / 5 - 1;
	}
}

//----- (00402C80) --------------------------------------------------------
void entity_initialize_building(Entity *a1, __int16 sabotage_points, void(*mode_turn_return)(Entity *), void(*mode_return)(Entity *))
{
	Entity *v4; // esi@1
	__int16 v5; // bx@1
	EntityBuildingState *v6; // eax@1

	v4 = a1;
	v5 = sabotage_points;
	v6 = (EntityBuildingState *)script_create_local_object(a1->script, 40);
	v4->state = v6;
	v6->oilspot_for_drillrig__task_for_researchlab = 0;
	v6->num_upgrades = 1;
	v6->field_8__0_for_repstation = 0;
	v6->sabotage_points = v5;
	v6->same_buildings_count = 0;
	v6->production_group = 0;
	v6->field_18 = 0;
	v6->field_1C = 0;
	v6->field_20 = 0;
	v6->field_24 = 0;
	if (v4->player_side == player_side)
		building_limits_on_new_building(v4->unit_id);
	if (v4->sprite->cplc_ptr1_pstru20
		&& v4->player_side == 0
		&& (current_level_idx == LEVEL_MUTE_09_FIGHT_FOR_TERRITORY || current_level_idx == LEVEL_SURV_21))
	{
		v4->hitpoints = v4->stats->hitpoints / 5 - 1;// allied buildings are damaged in these missions
	}
	if (v4->stats->attach)
		entity_attach_docking_point(v4);
	entity_410DC0_building(v4);
	v4->mode_turn_return = mode_turn_return;
	v4->mode_return = mode_return;
}

//----- (00402D40) --------------------------------------------------------
bool entity_sabotage(Entity *a1, void *param, void(*on_death_mode)(Entity *))
{
	int v3; // edi@1
	Entity *v4; // esi@1
	int sabotageur_side; // eax@1
	enum PLAYER_SIDE sabotage_target_side; // ecx@1
	EntityBuildingState *v7; // ebx@1
	__int16 v8; // ax@2
	enum SOUND_ID v10; // ecx@7
	__int16 v11; // ax@14
	int v12; // [sp-Ch] [bp-18h]@7

	v3 = (int)param;
	v4 = a1;
	sabotageur_side = *((_DWORD *)param + 5);
	sabotage_target_side = a1->player_side;
	v7 = (EntityBuildingState *)v4->state;
	if (sabotageur_side == sabotage_target_side)// reinforce
	{
		v8 = v7->sabotage_points;
		if (v8 < 5)
		{
			v7->sabotage_points = v8 + 1;
			entity_update_sabotage_bar(v4);
			return 0;
		}
		return 0;
	}
	if (sabotageur_side == player_side)
	{
		if (sabotage_target_side != player_side)
		{
			show_message_ex(v4, aBuildingSabotaged);
			if (*(_DWORD *)(v3 + 16) == 10)
			{
				v12 = _4690A8_unit_sounds_volume;
				v10 = SOUND_40_sabotage;
			}
			else
			{
				v12 = _4690A8_unit_sounds_volume;
				v10 = SOUND_105_sabotage;
			}
		LABEL_13:
			sound_play(v10, 0, v12, 16, 0);
			goto LABEL_14;
		}
	}
	else if (sabotage_target_side == player_side)
	{
		show_message_ex(v4, aBuildingSabotaged);
		if (*(_DWORD *)(v3 + 16) == 10)
		{
			v10 = SOUND_26_sabotage;
			v12 = _4690A8_unit_sounds_volume;
		}
		else
		{
			v12 = _4690A8_unit_sounds_volume;
			v10 = SOUND_93_sabotage;
		}
		goto LABEL_13;
	}
LABEL_14:
	v11 = v7->sabotage_points;
	if (!v11)
	{
		game_globals_per_player.cash[*(_DWORD *)(v3 + 20)] += v4->stats->cost;
		v4->SetMode(on_death_mode);
		return 0;
	}
	v7->sabotage_points = v11 - 1;
	entity_update_sabotage_bar(v4);
	return 0;
}

//----- (00402E40) --------------------------------------------------------
int entity_402E40_destroy(Entity *a1, void(*new_mode)(Entity *))
{
	int result; // eax@1
	Script *v5; // ST00_4@2

	result = a1->hitpoints;
	if (result > 0)
	{
		v5 = a1->script;
		a1->hitpoints = 0;
		result = script_sleep(v5, 1);
		a1->hitpoints = 0;
		a1->SetMode(new_mode);
		a1->destroyed = 1;
	}
	return result;
}

//----- (00402E90) --------------------------------------------------------
void entity_402E90_on_damage(Entity *a1, void *param, void(*on_death_mode)(Entity *))
{
	Entity *v3; // esi@1
	void *damage_amount; // edi@2
	int v5; // eax@4
	Script *v6; // eax@6
	int v7; // eax@8

	v3 = a1;
	if (param)
	{
		damage_amount = (void *)*((_WORD *)param + 72);
		if (a1->hitpoints > 0)
		{
			if (a1->stats->_54_ai_importance)
			{
				v5 = *((_DWORD *)param + 32);
				if (v5)
				{
					if (*(_DWORD *)(v5 + 304) == *((_DWORD *)param + 33))
					{
						v6 = *(Script **)(v5 + 12);
						if (v6)
							script_trigger_event(a1->script, MSG_RECEIVE_EXPERIENCE, damage_amount, v6);
					}
				}
			}
			v7 = v3->hitpoints - (_DWORD)damage_amount;
			v3->hitpoints = v7;
			if (v7 <= 0)
			{
                script_sleep(v3->script, 1);
				v3->hitpoints = 0;
				v3->SetMode(on_death_mode);
				v3->destroyed = 1;
			}
		}
	}
}

//----- (00403B70) --------------------------------------------------------
//int sub_403B70_get_drive_type(char drive_letter)
//{
//	int v1; // eax@3
//	int v2; // ecx@4
//	int result; // eax@7
//	char RootPathName[4]; // [sp+0h] [bp-4h]@1
//
//	strcpy(RootPathName, "#:\\");
//	RootPathName[0] = drive_letter;
//
//	v2 = GetDriveTypeA(RootPathName);
//
//	switch (v2)
//	{
//	case DRIVE_CDROM:
//		result = 1;
//		break;
//	case DRIVE_UNKNOWN:
//	case DRIVE_NO_ROOT_DIR:
//		result = -1;
//		break;
//	default:
//		result = 0;
//		break;
//	}
//	return result;
//}

//----- (00403C20) --------------------------------------------------------
int get_max_clanhall_level()
{
	return max_clanhall_level;
}

//----- (00403C30) --------------------------------------------------------
bool is_clanhall_maxed()
{
	return max_clanhall_level >= 5;
}

//----- (00403C40) --------------------------------------------------------
void entity_clanhall_on_upgrade_complete(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param)
{
	Script *v4; // ebp@1
	Entity *v5; // ebx@1
	EntityBuildingState *v6; // eax@1
	ProductionGroup *v7; // edi@1
	int v8; // ecx@1
	int can_unlock_towers; // esi@4
	unsigned int v10; // ecx@10
	enum LEVEL_ID v11; // eax@12
	unsigned int v12; // ecx@17
	enum LEVEL_ID v13; // eax@19
	unsigned int v14; // eax@22
	int v15; // eax@26
	Script *a2a; // [sp+10h] [bp-4h]@1

	v4 = receiver;
	a2a = sender;
	v5 = (Entity *)receiver->param;
	v6 = (EntityBuildingState *)v5->state;
	v7 = v6->production_group;
	v8 = v6->num_upgrades + 1;
	v6->num_upgrades = v8;
	if (v8 > 5)
		v6->num_upgrades = 5;
	if (v5->player_side == player_side)
	{
		can_unlock_towers = 0;
        --_477378_clanhall.num_buildings_by_level[v6->num_upgrades - 1];
		++_477378_clanhall.num_buildings_by_level[v6->num_upgrades];
		if (v6->num_upgrades > max_clanhall_level)
		{
			max_clanhall_level = v6->num_upgrades;
			can_unlock_towers = 1;
		}
		switch (v6->num_upgrades)
		{
		case 2:
			if (!(levels[current_level_idx].disabled_units_mask & 0x200000))
				production_group_enable(v7, UNIT_STATS_MUTE_PYROMANIAC, 2800);
			if (can_unlock_towers)
			{
				sub_447000();
				v10 = levels[current_level_idx].disabled_units_mask;
				if (!(BYTE1(v10) & 8))
					production_group_enable(_47B3B8_tower_production_group, UNIT_STATS_MUTE_MACHINEGUN_NEST, 2432);
			}
			break;
		case 3:
			v11 = current_level_idx;
			if (!(levels[current_level_idx].disabled_units_mask & 0x400000))
			{
				production_group_enable(v7, UNIT_STATS_MUTE_VANDAL, 2760);
				v11 = current_level_idx;
			}
			if (!(levels[v11].disabled_units_mask & 0x800000))
			{
				production_group_enable(v7, UNIT_STATS_MUTE_RIOTER, 2784);
				v11 = current_level_idx;
			}
			if (can_unlock_towers)
			{
				v12 = levels[v11].disabled_units_mask;
				if (!(BYTE1(v12) & 2))
					production_group_enable(_47B3B8_tower_production_group, UNIT_STATS_MUTE_GRAPESHOT_TOWER, 2424);
			}
			break;
		case 4:
			v13 = current_level_idx;
			if (!(levels[current_level_idx].disabled_units_mask & 0x1000000))
			{
				production_group_enable(v7, UNIT_STATS_MUTE_BAZOOKA, 2768);
				v13 = current_level_idx;
			}
			if (can_unlock_towers)
			{
				v14 = levels[v13].disabled_units_mask;
				if (!(BYTE1(v14) & 0x10))
					production_group_enable(_47B3B8_tower_production_group, UNIT_STATS_MUTE_ROTARY_CANNON, 2408);
			}
			break;
		case 5:
			if (!(levels[current_level_idx].disabled_units_mask & 0x2000000))
				production_group_enable(v7, UNIT_STATS_MUTE_CRAZY_HARRY, 2752);
			if (BeastEnclosureAllowsNuke())
				attempt_unlock_aircraft();
			break;
		default:
			break;
		}
	}
	entity_4109A0_status_bar(v5);
	EventHandler_DefaultBuildingsHandler(v4, a2a, event, param);
}

//----- (00403E90) --------------------------------------------------------
void EventHandler_Clanhall(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param)
{
	Entity *v4; // esi@1

	v4 = (Entity *)receiver->param;
	switch (event)
	{
	case EVT_MSG_DESTROY:
		entity_402E40_destroy((Entity *)receiver->param, entity_mode_clanhall_on_death);
		break;
	case EVT_MSG_PRODUCTION_READY:
		if (param == (void *)UNIT_STATS_MUTE_WASP)// wasp
		{
			if (v4->player_side == player_side)
			{
				show_message_ex(0, aAirStrikeReady);
				on_airstrike_ready();
			}
		}
		else
		{
			v4->sprite->field_88_unused = 1;
			if (spawn_unit(
				(enum UNIT_ID)(int)param,
				v4->stru60.pstru4->x_offset + v4->sprite->x,
				v4->stru60.pstru4->y_offset + v4->sprite->y,
				v4->player_side))
			{
				if (v4->player_side == player_side)
				{
					show_message_ex(0, aUnitReady);
					sound_play(SOUND_MUTE_UNIT_READY, 0, _4690A8_unit_sounds_volume, 16, 0);
				}
			}
			else
			{
				show_message_ex(0, aCouldntCreateNewUnit);
			}
		}
		break;
	case CMD_APPLY_DAMAGE:
		entity_402E90_on_damage(v4, param, entity_mode_clanhall_on_death);
		entity_410520_update_healthbar_color(v4);
		break;
	case EVT_MSG_SABOTAGE:
		if (v4->player_side == player_side)
			show_message_ex((Entity *)receiver->param, aBuildingSabotaged);
		entity_sabotage(v4, param, entity_mode_clanhall_on_death);
		break;
	case EVT_MSG_UPGRADE_COMPLETE:
		entity_clanhall_on_upgrade_complete(receiver, sender, event, param);
		break;
	default:
		EventHandler_DefaultBuildingsHandler(receiver, sender, event, param);
		break;
	}
}

//----- (00404040) --------------------------------------------------------
void entity_mode_clanhall_set_default_production(Entity *a1)
{
	Entity *v1; // edi@1
	EntityBuildingState *v2; // esi@2
	enum LEVEL_ID v3; // eax@7
	int *v4; // esi@7

	v1 = a1;
	if (player_side == a1->player_side)
	{
		v2 = (EntityBuildingState *)a1->state;
		v2->same_buildings_count = 0;
		script_trigger_event_group(a1->script, EVT_MSG_BUILDING_COMPLETE, 0, SCRIPT_MUTE_CLANHALL_HANDLER);
		if (!v2->same_buildings_count)
		{
			if (!_47B3E0_unit_int_outpost_clanhall && !_47B3D0_building_production_group)
				_47B3D0_building_production_group = entity_building_create_production_group(v1, PRODUCTION_GROUP_BUILDINGS);
			if (!_47B3B8_tower_production_group)
			{
				_47B3B8_tower_production_group = entity_building_create_production_group(v1, PRODUCTION_GROUP_TOWERS);
				v3 = current_level_idx;
				v4 = &mute_default_buildings[0].mobd_lookup_table_offset;
				do
				{
					if (!(levels[v3].disabled_units_mask & *(v4 - 2)))
					{
						production_group_enable(_47B3D0_building_production_group, (enum UNIT_ID)*(v4 - 1), *v4);
						v3 = current_level_idx;
					}
					v4 += 3;
				} while ((int)v4 < (int)&mute_default_infantry[0].mobd_lookup_table_offset);
				if (!_47B3D4_aircraft_production_group)
					_47B3D4_aircraft_production_group = entity_building_create_production_group(v1, PRODUCTION_GROUP_AIRCRAFT);
				max_clanhall_level = 1;
				memset(&_477378_clanhall, 0, sizeof(_477378_clanhall));
			}
		}
	}
}

//----- (00404130) --------------------------------------------------------
void UNIT_Handler_Clanhall(Script *task)
{
	Entity *v1; // esi@1
	void *v2; // eax@8

	v1 = (Entity *)task->param;
	if (!_47C6DC_dont_execute_unit_handlers)
	{
		if (!v1)
		{
			v1 = EntityFactory().Create(task);
			if (v1->player_side == player_side)
				entity_register_player_main_building(v1);
			v1->script->event_handler = EventHandler_Clanhall;
			v1->script->script_type = SCRIPT_MUTE_CLANHALL_HANDLER;
			map_reveal_fog_around_entity(v1);
			entity_initialize_building(
				v1,
				3,
				entity_mode_clanhall_on_death_reset_production_options,
				entity_mode_clanhall_on_building_completed);
			entity_mode_clanhall_set_default_production(v1);
			if (v1->sprite->cplc_ptr1_pstru20)
				v1->SetMode(entity_mode_4042A0_clanhall);
			else
				entity_402BB0_set_arrive_handler(v1, entity_mode_4042A0_clanhall);
			v2 = task->sprite->_80_entity__stru29__sprite__initial_hitpoints;
			if (v2)
			{
				v1->hitpoints = (int)v2;
				entity_410520_update_healthbar_color(v1);
			}
		}
        v1->ExecMode();
	}
}
// 47C6DC: using guessed type int _47C6DC_dont_execute_unit_handlers;

//----- (004041F0) --------------------------------------------------------
void entity_mode_clanhall_on_building_completed(Entity *a1)
{
	Entity *v1; // esi@1
	enum PLAYER_SIDE v2; // eax@1
	EntityBuildingState *v3; // ebx@1
	ProductionGroup *v4; // eax@6
	ProductionGroup *v5; // edi@6
	int *v6; // esi@6
	enum LEVEL_ID v7; // eax@6

	v1 = a1;
	v2 = a1->player_side;
	v3 = (EntityBuildingState *)a1->state;
	if (v2 == player_side)
	{
		if (a1->mode_arrive == entity_mode_clanhall_on_building_completed)
		{
			entity_mode_clanhall_set_default_production(a1);
			v1->mode_arrive = 0;
			v1->SetMode(entity_mode_403650_building);
		}
		if (!v1->sprite->cplc_ptr1_pstru20)
			show_message_ex(0, aBuildingCompleted);
		v4 = entity_building_create_production_group(v1, PRODUCTION_GROUP_INFANTRY);
		v5 = v4;
		v6 = &mute_default_infantry[0].mobd_lookup_table_offset;
		v3->production_group = v4;
		v7 = current_level_idx;
		do
		{
			if (!(levels[v7].disabled_units_mask & *(v6 - 2)))
			{
				production_group_enable(v5, (enum UNIT_ID)*(v6 - 1), *v6);
				v7 = current_level_idx;
			}
			v6 += 3;
		} while ((int)v6 < (int)&_4640E0_stru7_array[0]._4_psprite_pstru7_idx);
		++_477378_clanhall.num_buildings_by_level[1];
	}
	else if (v2 == 0)
	{
		a1->mode_arrive = entity_mode_clanhall_on_building_completed;
	}
}

//----- (004042A0) --------------------------------------------------------
void entity_mode_4042A0_clanhall(Entity *a1)
{
	Entity *v1; // esi@1
	EntityTurret *v2; // eax@1

	v1 = a1;
	a1->mode_arrive = 0;
	entity_mode_clanhall_on_building_completed(a1);
	v2 = v1->turret;
	if (v2)
		v2->turret_sprite->drawjob->flags &= 0xBFFFFFFF;
	if (player_side == v1->player_side && !v1->sprite->cplc_ptr1_pstru20)
		sound_play(SOUND_MUTE_BUILDING_COMPLETED, 0, _4690A8_unit_sounds_volume, 16, 0);
	if (v1->sprite->cplc_ptr1_pstru20)
	{
		v1->SetMode(entity_mode_4034B0);
	}
	else
	{
		v1->SetMode(entity_mode_403650_building);
	}
    entity_mode_403650_building(v1);
}

//----- (00404320) --------------------------------------------------------
void entity_mode_clanhall_on_death_reset_production_options(Entity *a1)
{
	Entity *v1; // edi@1
	enum PLAYER_SIDE v2; // edx@1
	EntityBuildingState *v3; // ecx@1
	int v4; // esi@2
	enum LEVEL_ID v5; // ecx@5
	enum UNIT_ID v6; // edx@13
	int v7; // eax@18
	Entity *v8; // [sp+10h] [bp-4h]@1

	v1 = a1;
	v8 = a1;
	v2 = a1->player_side;
	v3 = (EntityBuildingState *)a1->state;
	if (player_side != v2)
		return;
	--_477378_clanhall.num_buildings_by_level[v3->num_upgrades];
	v4 = v3->num_upgrades;
	if (v4 != max_clanhall_level || _477378_clanhall.num_buildings_by_level[v4])
		goto LABEL_22;
	if (v4 <= 0)
		goto LABEL_21;
	v5 = current_level_idx;
	do
	{
		if (v4 == 2)
		{
			if (levels[v5].disabled_units_mask & 0x800)
				goto LABEL_18;
			v6 = UNIT_STATS_MUTE_MACHINEGUN_NEST;
			goto LABEL_16;
		}
		if (v4 == 3)
		{
			if (levels[v5].disabled_units_mask & 0x200)
				goto LABEL_18;
			v6 = UNIT_STATS_MUTE_GRAPESHOT_TOWER;
		LABEL_16:
			production_group_disable(_47B3B8_tower_production_group, v6);
		LABEL_17:
			v5 = current_level_idx;
			goto LABEL_18;
		}
		if (v4 == 4)
		{
			if (!(levels[v5].disabled_units_mask & 0x1000))
				production_group_disable(_47B3B8_tower_production_group, UNIT_STATS_MUTE_ROTARY_CANNON);
			_447250_toggle_aircraft();
			goto LABEL_17;
		}
	LABEL_18:
		v7 = (int)building_limits_list_free_pool[v4--].next;
	} while (!v7 && v4 > 0);
	v1 = v8;
LABEL_21:
	max_clanhall_level = v4;
LABEL_22:
	if (building_limits_count(v1->unit_id) == 1)
	{
		if (_47B3D0_building_production_group)
		{
			production_group_4467E0(_47B3D0_building_production_group, UNIT_STATS_MUTE_CLANHALL);
			_47B3E0_unit_int_outpost_clanhall = 1;
		}
		production_group_446860(_47B3B8_tower_production_group);
		_447250_toggle_aircraft();
		production_group_446860(_47B3D4_aircraft_production_group);
		_47B3D4_aircraft_production_group = 0;
		_47B3B8_tower_production_group = 0;
		disable_minimap();
	}
	else
	{
		if (max_clanhall_level < 2)
			disable_minimap();
		entity_430F90_clanhall(v1);
	}
}

//----- (00404490) --------------------------------------------------------
bool is_tower_available(enum UNIT_ID unit_id)
{
	ProductionOption *v1; // eax@2

	if (_47B3B8_tower_production_group
		&& (v1 = _47B3B8_tower_production_group->next_option,
		(ProductionOption **)v1 != &_47B3B8_tower_production_group->next_option))
	{
		while (v1->unit_id != unit_id)
		{
			v1 = v1->next;
			if ((ProductionOption **)v1 == &_47B3B8_tower_production_group->next_option)
				return false;
		}
        return true;
	}
    return false;
}

//----- (004044C0) --------------------------------------------------------
bool is_building_available(enum UNIT_ID a1)
{
	ProductionGroup *v1; // eax@2

	if (_47B3D0_building_production_group
		&& (v1 = (ProductionGroup *)_47B3D0_building_production_group->next_option,
		(ProductionOption **)v1 != &_47B3D0_building_production_group->next_option))
	{
		while (v1->_C_entity != (Entity *)a1)
		{
			v1 = v1->next;
			if ((ProductionOption **)v1 == &_47B3D0_building_production_group->next_option)
				return false;
		}
        return true;
	}
    return false;
}

//----- (004044F0) --------------------------------------------------------
void entity_mode_clanhall_on_death(Entity *a1)
{
	Entity *v1; // esi@1

	v1 = a1;
	entity_mode_clanhall_on_death_reset_production_options(a1);
	entity_mode_building_on_death_default(v1);
}

//----- (00404510) --------------------------------------------------------
void copy_player_sprite_palette_aligned(unsigned __int8 *palette, unsigned __int8 *aligned)
{
	unsigned __int8 *v2; // eax@1
	int v3; // edx@1
	int v4; // eax@1

	v2 = aligned + 255;
	LOBYTE_HEXRAYS(v2) = 0;
	v3 = 64;
	v4 = v2 - palette;
	do
	{
		*(_DWORD *)&palette[v4] = *(_DWORD *)palette;
		palette += 4;
		--v3;
	} while (v3);
}

//----- (00404530) --------------------------------------------------------
bool sub_404530(Sprite *a1, Sprite *a2, int a3, void *a4, void *a5)
{
	int v5; // eax@2
	bool result; // eax@3
	int v7; // edx@4
	int v8; // esi@6
	Script *v9; // eax@6
	int v10; // esi@7
	int v11; // eax@8
	int v12; // edx@10
	int v13; // esi@12
	Script *v14; // eax@12
	int v15; // edx@13
	int v16; // eax@14
	int v17; // edx@16
	int v18; // esi@18
	int v19; // eax@20
	int v20; // edx@22
	int v21; // esi@24
	int v22; // eax@26
	int v23; // edx@28
	int v24; // esi@30
	int v25; // eax@33
	int v26; // edx@35
	int v27; // esi@37

	switch (a3)
	{
	case 0:
		v5 = *((_DWORD *)a5 + 1);
		if (*((_DWORD *)a4 + 1) < v5)
		{
			v7 = *((_DWORD *)a4 + 4);
			if (v7 < *((_DWORD *)a5 + 4))
			{
				v8 = v5 - v7 + a1->x;
				v9 = a1->script;
				a1->x = v8;
				if (!v9)
					goto LABEL_40;
				v10 = v9->flags_20 | SCRIPT_FLAGS_20_1000000;
				goto LABEL_32;
			}
			result = 0;
		}
		else
		{
			result = 0;
		}
		break;
	case 1:
		v11 = *((_DWORD *)a5 + 4);
		if (*((_DWORD *)a4 + 4) > v11)
		{
			v12 = *((_DWORD *)a4 + 1);
			if (v12 > *((_DWORD *)a5 + 1))
			{
				v13 = v11 - v12 + a1->x;
				v14 = a1->script;
				a1->x = v13;
				if (!v14)
					goto LABEL_40;
				v15 = v14->flags_20 | SCRIPT_FLAGS_20_800000;
				goto LABEL_39;
			}
			result = 0;
		}
		else
		{
			result = 0;
		}
		break;
	case 2:
		v16 = *((_DWORD *)a5 + 2);
		if (*((_DWORD *)a4 + 2) < v16)
		{
			v17 = *((_DWORD *)a4 + 5);
			if (v17 < *((_DWORD *)a5 + 5))
			{
				v18 = v16 - v17 + a1->y;
				v9 = a1->script;
				a1->y = v18;
				a1->y_speed = 0;
				if (!v9)
					goto LABEL_40;
				v10 = v9->flags_20 | SCRIPT_FLAGS_20_400000;
				goto LABEL_32;
			}
			result = 0;
		}
		else
		{
			result = 0;
		}
		break;
	case 3:
		v19 = *((_DWORD *)a5 + 5);
		if (*((_DWORD *)a4 + 5) > v19)
		{
			v20 = *((_DWORD *)a4 + 2);
			if (v20 > *((_DWORD *)a5 + 2))
			{
				v21 = v19 - v20 + a1->y;
				v14 = a1->script;
				a1->y = v21;
				a1->y_speed = 0;
				if (!v14)
					goto LABEL_40;
				v15 = v14->flags_20 | SCRIPT_FLAGS_20_200000;
				goto LABEL_39;
			}
			result = 0;
		}
		else
		{
			result = 0;
		}
		break;
	case 4:
		v22 = *((_DWORD *)a5 + 3);
		if (*((_DWORD *)a4 + 3) < v22)
		{
			v23 = *((_DWORD *)a4 + 6);
			if (v23 < *((_DWORD *)a5 + 6))
			{
				v24 = v22 - v23 + a1->z_index;
				v9 = a1->script;
				a1->z_index = v24;
				if (!v9)
					goto LABEL_40;
				v10 = v9->flags_20 | SCRIPT_FLAGS_20_100000;
			LABEL_32:
				v9->flags_20 = v10;
				result = 1;
				a1->script->flags_24 |= a1->script->flags_20;
			}
			else
			{
				result = 0;
			}
		}
		else
		{
			result = 0;
		}
		break;
	case 5:
		v25 = *((_DWORD *)a5 + 6);
		if (*((_DWORD *)a4 + 6) > v25)
		{
			v26 = *((_DWORD *)a4 + 3);
			if (v26 > *((_DWORD *)a5 + 3))
			{
				v27 = v25 - v26 + a1->z_index;
				v14 = a1->script;
				a1->z_index = v27;
				if (v14)
				{
					v15 = v14->flags_20 | SCRIPT_FLAGS_20_80000;
				LABEL_39:
					v14->flags_20 = v15;
					a1->script->flags_24 |= a1->script->flags_20;
				}
				goto LABEL_40;
			}
			result = 0;
		}
		else
		{
			result = 0;
		}
		break;
	default:
	LABEL_40:
		result = 1;
		break;
	}
	return result;
}

//----- (00404760) --------------------------------------------------------
bool sub_404760(Sprite *a1, Sprite *a2, int a3, void *a4, void *a5)
{
	int v5; // edx@2
	int v6; // edx@4
	int v7; // esi@5
	Script *v8; // eax@7

	if (a3 != 2
		|| (v5 = a1->x, v5 > *((_DWORD *)a5 + 4))
		|| v5 < *((_DWORD *)a5 + 1)
		|| (v6 = *((_DWORD *)a5 + 2), *((_DWORD *)a4 + 2) >= v6)
		|| (v7 = *((_DWORD *)a4 + 5), v7 >= *((_DWORD *)a5 + 5))
		|| v7 >= v6 + 2048)
	{
        return false;
	}
	else
	{
		v8 = a1->script;
		a1->y = v6;
		a1->y_speed = 0;
		if (v8)
		{
			v8->flags_20 |= SCRIPT_FLAGS_20_400000;
			a1->script->flags_24 |= a1->script->flags_20;
		}
        return true;
	}
}

//----- (004047E0) --------------------------------------------------------
bool sub_4047E0(Sprite *a1, Sprite *a2, int a3, void *a4, void *a5)
{
	int v5; // edx@2
	int v6; // esi@2
	int v7; // edi@3
	int v8; // ebx@4
	int v9; // eax@5
	Script *v10; // eax@6

	if (a3 == 1
		|| (v5 = a1->x, v6 = *((_DWORD *)a5 + 4), v5 > v6)
		|| (v7 = *((_DWORD *)a5 + 1), v5 < v7)
		|| (v8 = *((_DWORD *)a5 + 5), *((_DWORD *)a4 + 5) > v8 + 2048)
		|| (v9 = v8 + (v5 - v7) * (*((_DWORD *)a5 + 2) - v8) / (v6 - v7), v9 >= a1->y))
	{
        return false;
	}
	else
	{
		a1->y = v9;
		v10 = a1->script;
		a1->y_speed = 0;
		if (v10)
		{
			v10->flags_20 |= SCRIPT_FLAGS_20_400000;
			a1->script->flags_24 |= a1->script->flags_20;
		}
        return true;
	}
}

//----- (00404870) --------------------------------------------------------
bool sub_404870(Sprite *a1, Sprite *a2, int a3, void *a4, void *a5)
{
	int v5; // edx@2
	int v6; // edi@2
	int v7; // esi@3
	int v8; // ebx@4
	int v9; // eax@5
	Script *v10; // eax@6

	if (a3
		&& (v5 = a1->x, v6 = *((_DWORD *)a5 + 4), v5 <= v6)
		&& (v7 = *((_DWORD *)a5 + 1), v5 >= v7)
		&& (v8 = *((_DWORD *)a5 + 5), *((_DWORD *)a4 + 5) <= v8 + 2048)
		&& (v9 = v8 + (v5 - v6) * (*((_DWORD *)a5 + 2) - v8) / (v7 - v6), v9 < a1->y))
	{
		a1->y = v9;
		v10 = a1->script;
		a1->y_speed = 0;
		if (v10)
		{
			v10->flags_20 |= SCRIPT_FLAGS_20_400000;
			a1->script->flags_24 |= a1->script->flags_20;
		}
        return true;
	}

    return false;
}

//----- (00404900) --------------------------------------------------------
bool sub_404900(Sprite *a1, Sprite *a2, int a3, void *a4, void *a5)
{
	int v5; // edi@1
	int v6; // eax@1
	int v8; // edx@3
	int v9; // ebx@3
	int v10; // eax@4
	Script *v11; // eax@8

	v5 = *((_DWORD *)a4 + 2);
	v6 = *((_DWORD *)a5 + 2);
	if (v5 < v6 - 2048)
		return 0;
	v8 = *((_DWORD *)a4 + 1);
	v9 = *((_DWORD *)a5 + 1);
	if (v8 < v9)
	{
		a1->y += *((_DWORD *)a5 + 5) - v5;
		if (a3 > 1)
			a1->y_speed = 0;
		if (!a1)
			return 1;
		v11 = a1->script;
		if (!v11)
			return 1;
		goto LABEL_15;
	}
	v10 = *((_DWORD *)a5 + 5) + (v8 - v9) * (v6 - *((_DWORD *)a5 + 5)) / (*((_DWORD *)a5 + 4) - v9);
	if (v10 <= v5)
		return 0;
	a1->y += v10 - v5;
	if (a3 > 1)
		a1->y_speed = 0;
	if (a1)
	{
		v11 = a1->script;
		if (v11)
		{
		LABEL_15:
			v11->flags_20 |= SCRIPT_FLAGS_20_200000;
			a1->script->flags_24 |= a1->script->flags_20;
			return 1;
		}
	}
	return 1;
}

//----- (004049D0) --------------------------------------------------------
bool sub_4049D0(Sprite *a1, Sprite *a2, int a3, void *a4, void *a5)
{
	int v5; // edi@1
	int v6; // eax@1
	int v8; // edx@3
	int v9; // ebx@3
	int v10; // eax@4
	Script *v11; // eax@8

	v5 = *((_DWORD *)a4 + 2);
	v6 = *((_DWORD *)a5 + 2);
	if (v5 < v6 - 2048)
		return 0;
	v8 = *((_DWORD *)a4 + 4);
	v9 = *((_DWORD *)a5 + 4);
	if (v8 > v9)
	{
		a1->y += *((_DWORD *)a5 + 5) - v5;
		if (a3 > 1)
			a1->y_speed = 0;
		if (!a1)
			return 1;
		v11 = a1->script;
		if (!v11)
			return 1;
		goto LABEL_15;
	}
	v10 = *((_DWORD *)a5 + 5) + (v8 - v9) * (v6 - *((_DWORD *)a5 + 5)) / (*((_DWORD *)a5 + 1) - v9);
	if (v10 <= v5)
		return 0;
	a1->y += v10 - v5;
	if (a3 > 1)
		a1->y_speed = 0;
	if (a1)
	{
		v11 = a1->script;
		if (v11)
		{
		LABEL_15:
			v11->flags_20 |= SCRIPT_FLAGS_20_200000;
			a1->script->flags_24 |= a1->script->flags_20;
			return 1;
		}
	}
	return 1;
}

//----- (00404AA0) --------------------------------------------------------
bool sub_404AA0(Sprite *a1, Sprite *a2, int a3, void *a4, void *a5)
{
	int v5; // eax@4
	Script *v7; // eax@8
	int v8; // eax@10
	int v9; // edx@12
	int v10; // esi@14
	Script *v11; // eax@14

	if (a3 != 1)
	{
		if (a3 == 2 && a1->x >= *((_DWORD *)a5 + 1))
		{
			v5 = *((_DWORD *)a5 + 2);
			if (*((_DWORD *)a4 + 2) >= v5)
				return 0;
			if (*((_DWORD *)a4 + 5) >= *((_DWORD *)a5 + 5))
				return 0;
			a1->y = v5;
			v7 = a1->script;
			a1->y_speed = 0;
			if (v7)
			{
				v7->flags_20 |= SCRIPT_FLAGS_20_400000;
				a1->script->flags_24 |= a1->script->flags_20;
				return 1;
			}
			return 1;
		}
		return 0;
	}
	v8 = *((_DWORD *)a5 + 4);
	if (*((_DWORD *)a4 + 4) <= v8)
		return 0;
	v9 = *((_DWORD *)a4 + 1);
	if (v9 <= *((_DWORD *)a5 + 1))
		return 0;
	v10 = v8 - v9 + a1->x;
	v11 = a1->script;
	a1->x = v10;
	if (v11)
	{
		v11->flags_20 |= SCRIPT_FLAGS_20_800000;
		a1->script->flags_24 |= a1->script->flags_20;
	}
	return 1;
}

//----- (00404B80) --------------------------------------------------------
bool sub_404B80(Sprite *a1, Sprite *a2, int a3, void *a4, void *a5)
{
	int v5; // eax@4
	Script *v7; // eax@8
	int v8; // eax@10
	int v9; // edx@12
	int v10; // esi@14
	Script *v11; // eax@14

	if (a3)
	{
		if (a3 == 2 && a1->x <= *((_DWORD *)a5 + 4))
		{
			v5 = *((_DWORD *)a5 + 2);
			if (*((_DWORD *)a4 + 2) >= v5)
				return 0;
			if (*((_DWORD *)a4 + 5) >= *((_DWORD *)a5 + 5))
				return 0;
			a1->y = v5;
			v7 = a1->script;
			a1->y_speed = 0;
			if (v7)
			{
				v7->flags_20 |= SCRIPT_FLAGS_20_400000;
				a1->script->flags_24 |= a1->script->flags_20;
				return 1;
			}
			return 1;
		}
		return 0;
	}
	v8 = *((_DWORD *)a5 + 1);
	if (*((_DWORD *)a4 + 1) >= v8)
		return 0;
	v9 = *((_DWORD *)a4 + 4);
	if (v9 >= *((_DWORD *)a5 + 4))
		return 0;
	v10 = v8 - v9 + a1->x;
	v11 = a1->script;
	a1->x = v10;
	if (v11)
	{
		v11->flags_20 |= SCRIPT_FLAGS_20_1000000;
		a1->script->flags_24 |= a1->script->flags_20;
	}
	return 1;
}

//----- (00404C60) --------------------------------------------------------
bool sub_404C60(Sprite *a1, Sprite *a2, int a3, void *a4, void *a5)
{
	Script *v5; // eax@1

	v5 = a1->script;
	if (v5 && v5->_28_yield_flags & SCRIPT_FLAGS_20_EVENT_TRIGGER)
		script_trigger_event(0, EVT_MOUSE_HOVER, a2, a1->script);
	return 0;
}


//----- (00405460) --------------------------------------------------------
void entity_show_hint(Entity *a1)
{
	Entity *v1; // esi@1
	enum PLAYER_SIDE v2; // eax@3

	v1 = a1;
	_4657C8_hint_entity_id = a1->entity_id;
	if (single_player_game)
	{
		show_message_ex(a1, a1->stats->name);
	}
	else
	{
		v2 = a1->player_side;
		if (v2)
		{
			sprintf(byte_4773D0, aSSS, netz_47A740[v2 + 1].player_name, a1->stats->name);
			show_message_ex(v1, byte_4773D0);
		}
	}
}

//----- (004054D0) --------------------------------------------------------
void entity_4054D0_tanker_convoy(Entity *a1)
{
	Entity *v1; // esi@1
	UnitStat *v2; // eax@2
	int v3; // edi@2
	int v4; // eax@3
	unsigned int v5; // ecx@5
	UnitStat *v6; // eax@5
	int v7; // eax@6
	unsigned int v8; // edx@8

	v1 = a1;
	if (entity_405750_tanker_convoy(a1))
	{
		v2 = v1->stats;
		v1->SetOrder(ENTITY_ORDER_6_tanker);
		v1->retaliation_target = 0;
		v1->_E4_prev_attack_target = 0;
		v1->_134_param__unitstats_after_mobile_outpost_plant = 5;
		v3 = (int)v1->state;
		if (v2->is_infantry)
			v4 = map_get_entity_placement_inside_tile_x(v1, v1->_A4_idx_in_tile);
		else
			v4 = v2->field_4C != 128 ? 7424 : 4096;
		v5 = v4 + map_point_to_tile_global(*(_DWORD *)v3);
		v6 = v1->stats;
		v1->sprite_x_2 = v5;
		if (v6->is_infantry)
			v7 = map_get_entity_placement_inside_tile_y(v1, v1->_A4_idx_in_tile);
		else
			v7 = v6->field_4C != 128 ? 7424 : 4096;
		v8 = map_point_to_tile_global(*(_DWORD *)(v3 + 4));
		v1->entity_8 = 0;
		v1->mode_return = entity_mode_move_attack;
		v1->sprite_y_2 = v7 + v8;
		entity_mode_move_attack(v1);
	}
	else
	{
		v1->_DC_order = ENTITY_ORDER_0;
	}
}

//----- (004055B0) --------------------------------------------------------
void EventHandler_TankerConvoy(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param)
{
	Entity *v4; // esi@1

	v4 = (Entity *)receiver->param;
	if (!v4->destroyed)
	{
		switch (event)
		{
		case CMD_APPLY_DAMAGE:
			entity_do_damage(v4, (Sprite *)param);
			entity_410710_status_bar(v4);
			break;
		case EVT_MSG_SELECTED:
			entity_selected_default(v4);
			break;
		case EVT_MSG_DESELECTED:
			entity_deselected_default(v4);
			break;
		case EVT_MSG_SHOW_UNIT_HINT:
			entity_show_hint(v4);
			break;
		case EVT_MSG_1507_stru11:
			entity_41A850_evt1507_mess_with_stru11(v4, param);
			break;
		case EVT_MSG_1509_stru11:
			entity_41A980_evt1509_unset_stru11(v4, param);
			break;
		case MSG_ATTACKED:
			entity_on_attacked_default(v4, (Entity *)param);
			break;
		default:
			return;
		}
	}
}

//----- (00405680) --------------------------------------------------------
void entity_mode_405680_tanker_convoy(Entity *a1)
{
	dword_477358 = 2371645;
}
// 477358: using guessed type int dword_477358;

//----- (00405690) --------------------------------------------------------
void entity_mode_405690(Entity *a1)
{
	Entity *v1; // esi@1

	v1 = a1;
	if (!a1->_134_param__unitstats_after_mobile_outpost_plant)
	{
		entity_40DEC0_boxd(a1, a1->sprite_map_x, a1->sprite_map_y, a1->_A4_idx_in_tile);
		v1->sprite->x_speed = 0;
		v1->sprite->y_speed = 0;
		v1->SetMode(entity_mode_405680_tanker_convoy);
	}
}

//----- (004056E0) --------------------------------------------------------
void entity_4056E0_tanker_convoy_update_checkpoint(int x, EntityTankerConvoyAttachment *a2)
{
	int v2; // eax@3
	int v3; // eax@7

	if (current_level_idx == LEVEL_SURV_07_PROTECT_THE_CONVOY)
	{
		if (a2->checkpoint < 18)
		{
			while (1)
			{
				v3 = a2->checkpoint;
				a2->x = _464230_tankerconvoy_checkpoints_surv07[v3].x << 8;
				a2->y = _464230_tankerconvoy_checkpoints_surv07[v3].y << 8;
				if (a2->x <= x)
					break;
				a2->checkpoint = v3 + 1;
			}
		}
	}
	else if (current_level_idx == LEVEL_MUTE_08_SMASH_THE_CONVOY)
	{
		v2 = a2->checkpoint;
		if (v2 < 15)
		{
			a2->x = _4642C0_tankerconvoy_checkpoints_mute08[v2].x << 8;
			a2->y = _4642C0_tankerconvoy_checkpoints_mute08[v2].y << 8;
		}
	}
}

//----- (00405750) --------------------------------------------------------
bool entity_405750_tanker_convoy(Entity *a1)
{
	Entity *v1; // esi@1
	EntityTankerConvoyAttachment *v2; // eax@1
	int v3; // ecx@1
	Sprite *v5; // edx@7

	v1 = a1;
	v2 = (EntityTankerConvoyAttachment *)a1->state;
	v3 = v2->checkpoint + 1;
	v2->checkpoint = v3;
	if (current_level_idx == LEVEL_SURV_07_PROTECT_THE_CONVOY)// INLINED 4056E0
	{
		if (v3 < 18)
		{
			v2->x = _464230_tankerconvoy_checkpoints_surv07[v3].x << 8;
			v2->y = _464230_tankerconvoy_checkpoints_surv07[v3].y << 8;
			return 1;
		}
	}
	else if (current_level_idx == LEVEL_MUTE_08_SMASH_THE_CONVOY && v3 < 15)
	{
		v2->x = _4642C0_tankerconvoy_checkpoints_mute08[v3].x << 8;
		v2->y = _4642C0_tankerconvoy_checkpoints_mute08[v3].y << 8;
		return 1;
	}
	v5 = v1->sprite;
	v1->SetMode(entity_mode_405690);
	v1->mode_return = entity_mode_405690;
    entity_load_idle_mobd(v1, 192);
	v1->_134_param__unitstats_after_mobile_outpost_plant = 600;
	v5->x_speed = -64;
	v1->sprite->y_speed = 0;
	v1->mode_arrive = entity_mode_405680_tanker_convoy;
	++_47A3D8_num_convoy_tankers_still_to_arrive;
	if (current_level_idx == LEVEL_SURV_07_PROTECT_THE_CONVOY)
	{
		if (6 - _47A3D4_tanker_convoy_units_left >= 4
			&& _47A3D8_num_convoy_tankers_still_to_arrive == 6 - _47A3D4_tanker_convoy_units_left)
		{
			_424CC0_script_47A3CC_evttrigger();
		}
	}
	else if (current_level_idx == LEVEL_MUTE_08_SMASH_THE_CONVOY)
	{
		_424CA0_script_47A3CC_evttrigger();
		return 0;
	}
	return 0;
}

//----- (00405850) --------------------------------------------------------
void UNIT_Handler_OilTankerConvoy(Script *a1)
{
	Entity *v1; // esi@1
	DataCplcItem_ptr1_stru20 *v2; // ebx@2
	Script *v3; // edx@2
	EntityTankerConvoyAttachment *v4; // eax@2
	int v14; // eax@13

	v1 = (Entity *)a1->param;
	if (!v1)
	{
		v2 = a1->sprite->cplc_ptr1_pstru20;
		v1 = EntityFactory().Create(a1);
		entity_init_infantry(v1);
		entity_set_draw_handlers(v1);
		v1->script->event_handler = EventHandler_TankerConvoy;
		v3 = v1->script;
		v3->script_type = SCRIPT_TANKER_CONVOY_HANDLER;
		v4 = (EntityTankerConvoyAttachment *)script_create_local_object(v1->script, 12);
		if (v4)
		{
			v1->state = v4;
			if (LOWORD_HEXRAYS(v2->param_1C) >= 0xFu)
				v4->checkpoint = 0;
			else
				v4->checkpoint = LOWORD_HEXRAYS(v2->param_1C);
			entity_4056E0_tanker_convoy_update_checkpoint(v1->sprite->x, v4);

			v1->SetOrder(ENTITY_ORDER_6_tanker);
			v1->retaliation_target = 0;
			v1->_E4_prev_attack_target = 0;
			v1->_134_param__unitstats_after_mobile_outpost_plant = 600;
			v1->sprite_x_2 = map_adjust_entity_in_tile_x(v1, v4->x);
            v1->sprite_y_2 = map_adjust_entity_in_tile_y(v1, v4->y);
			v1->entity_8 = 0;
			v1->mode_arrive = 0;
            entity_load_idle_mobd(v1, 192);
			entity_mode_move_attack(v1);
		}
	}
	v1->ExecMode();
	v14 = v1->_134_param__unitstats_after_mobile_outpost_plant;
	if (v14)
		v1->_134_param__unitstats_after_mobile_outpost_plant = v14 - 1;
}

//----- (004059C0) --------------------------------------------------------
bool render_string_4059C0(RenderString *a1, int a2, int a3)
{
	int v3; // edi@1
	stru8 *v5; // esi@1
	int i; // edx@1
	int v7; // ebx@5
	DrawJob *v8; // edx@7
	int v9; // ebp@7
	int v10; // ebp@8

	v3 = a1->field_C;
	v5 = a1->pstru8;
	for (i = v3 * (a2 + 1) + 1; i; --i)
		v5 = v5->next;

    bool result = false;
	if (v5->drawjob->job_details.y < -10)
		result = true;

	v7 = 0;
	if (v3 > 0)
	{
		do
		{
			--v5->drawjob->job_details.y;
			if (a3)
			{
				v8 = v5->drawjob;
				v9 = v8->job_details.x;
				if (a3 >= 0)
					v10 = v9 + 1;
				else
					v10 = v9 - 1;
				v8->job_details.x = v10;
			}
			v5 = v5->next;
			++v7;
		} while (v7 < a1->field_C);
	}
	return result;
}

//----- (00405A20) --------------------------------------------------------
void render_string_405A20(RenderString *a1, int a2, int y)
{
	int v3; // esi@1
	stru8 *v4; // eax@1
	int i; // edx@1
	int v6; // edx@3

	v3 = a1->field_C;
	v4 = a1->pstru8;
	for (i = v3 * (a2 + 1) + 1; i; --i)
		v4 = v4->next;
	v6 = 0;
	if (v3 > 0)
	{
		do
		{
			++v6;
			v4->drawjob->job_details.y = y;
			v4 = v4->next;
		} while (v6 < a1->field_C);
	}
}

//----- (00405A60) --------------------------------------------------------
void render_string_405A60(RenderString *a1, const char *str, DataMobdItem *custom_font, int y)
{
	RenderString *v4; // edi@1
	const char *v5; // ebp@1
	DrawJob *v6; // ecx@1
	int x; // esi@1
	int v8; // ebx@2
	int v9; // ecx@5
	int v10; // eax@6
	stru8 *v11; // ecx@6
	int v12; // edx@6
    DataMobdItem_stru0 *v13; // eax@13
    DataMobdItem_stru1 *v14; // eax@15
	bool v15; // zf@18
	int v16; // [sp+Ch] [bp-8h]@11
	int v17; // [sp+10h] [bp-4h]@1

	v4 = a1;
	v5 = str;
	v6 = a1->pstru8->drawjob;
	x = v6->job_details.x + 14;
	v17 = v6->job_details.x + 14;
	while (*v5)
	{
		v8 = _443D60_strlen_before_newline(v5);
		if (!v8)
			v8 = 1;
		if (*v5 == '\n')
		{
			x = v17;
			v9 = v4->num_lines + 1;
			v4->field_18 = 0;
			v4->num_lines = v9;
			++v5;
		}
		else
		{
			v10 = v4->field_18;
			v11 = v4->pstru8;
			v12 = v4->field_C * (v4->num_lines + 1) + v10 + 1;
			if (v4->field_C * (v4->num_lines + 1) + v10 != -1)
			{
				do
				{
					v11 = v11->next;
					--v12;
				} while (v12);
			}
			if (v10 > 1)
				x = v11->drawjob->job_details.x;
			if (v8)
			{
				v16 = v8;
				do
				{
					if (custom_font)
						v13 = custom_font->_[*v5 + 1];
					else
						v13 = v4->mobd_font__see_sub405A60->_[1 + *v5];
					v11->drawjob->job_details.image = v13->sprt;
					v11->drawjob->job_details.y = y - v13->y_offset;
					v11->drawjob->job_details.x = x - v13->x_offset;
					v14 = v13->field_18;
					if (v14)
						x = v11->drawjob->job_details.x + (v14->x_offset >> 8);
					else
						x = v11->drawjob->job_details.x + 14;
					v11 = v11->next;
					++v5;
					v11->drawjob->job_details.x = x;
					v15 = v16 == 1;
					++v4->field_18;
					--v16;
				} while (!v15);
			}
		}
	}
}

//----- (00405B80) --------------------------------------------------------
void script_credits_or_custom_mission_briefing_loop(Script *a1)
{
	int v1; // esi@3
	RenderString *v2; // eax@3
	char **v3; // ebx@4
	const char *v4; // edx@5
	int v5; // edi@5
	int v6; // ebp@14
	int v7; // edx@18
	char **v8; // edi@18
	char *v9; // eax@20
	char **v10; // edi@24
	RenderString *v11; // edi@31
	int v12; // ebx@31
	char *v13; // edx@31
	stru8 *v14; // ecx@31
	int v15; // eax@31
	int v16; // eax@33
	int v17; // eax@37
	bool v18; // sf@40
	unsigned __int8 v19; // of@40
	int v20; // [sp+0h] [bp-20h]@14
	int v21; // [sp+4h] [bp-1Ch]@3
	int v22; // [sp+8h] [bp-18h]@20
	int v23; // [sp+Ch] [bp-14h]@14
	int v24; // [sp+10h] [bp-10h]@14
	char *str; // [sp+14h] [bp-Ch]@24
	char **v26; // [sp+18h] [bp-8h]@24
	int v27; // [sp+1Ch] [bp-4h]@18

	if (netz_47C6C0_mapd_idx == 12)
	{
		a1->script_type = SCRIPT_TYPE_17;
		v21 = 0;
		v1 = 480;
		v2 = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 84, 84, 39, 19, 90, 14, 16);
		_47C65C_render_string = v2;
		dword_477410 = 0;
		if (v2)
		{
			render_string_445AE0(v2);
			v21 = 17;
			_47C65C_render_string->field_18 = 0;
			_47C65C_render_string->num_lines = 0;
			v3 = credits;
			do
			{
				v4 = *v3;
				v5 = 0;
				if (**v3 == '%')
				{
					v5 = 1;
					++v4;
				}
				if (v5 && v3 != credits)
					v1 += 100;
				render_string_405A60(_47C65C_render_string, v4, 0, v1);
				render_string_405A60(_47C65C_render_string, asc_464C88, 0, v1);
				if (v5)
					v1 += 30;
				else
					v1 += 20;
				++v3;
			} while ((int)v3 < (int)off_464ACC);
		}
		v6 = 16;
		v20 = v1;
		v23 = 480;
		v24 = 0;
		while (!(script_yield_any_trigger(a1, 2) & SCRIPT_FLAGS_20_EVENT_TRIGGER))
		{
			++dword_477410;
			if (v24)
			{
				if (--v23 < 0)
					break;
			}
			v7 = 0;
			v27 = 0;
			v8 = &credits[v21];
			do
			{
				if (render_string_4059C0(_47C65C_render_string, v7, 0))
				{
					v9 = *v8;
					v22 = 0;
					if (*v8)
					{
						v10 = v8 + 1;
						str = v9;
						++v21;
						v26 = v10;
						if (*v9 == '%')
						{
							v22 = 1;
							str = v9 + 1;
						}
						if (++v6 == 17)
							v6 = 0;
						_47C65C_render_string->num_lines = v6;
						if (v22 && v10 != credits)
							v20 += 100;
						v11 = _47C65C_render_string;
						v12 = _47C65C_render_string->field_C;
						v13 = (char *) & _47C65C_render_string->field_C;
						v1 = v20 - dword_477410;
						v14 = _47C65C_render_string->pstru8;
						v15 = v12 * (v6 + 1) + 1;
						if (v12 * (v6 + 1) != -1)
						{
							do
							{
								v14 = v14->next;
								--v15;
							} while (v15);
						}
						v16 = 0;
						if (v12 > 0)
						{
							do
							{
								++v16;
								v14->drawjob->job_details.y = v1;
								v14 = v14->next;
							} while (v16 < *(_DWORD *)v13);
							v11 = _47C65C_render_string;
						}
						v11->field_18 = 0;
						render_string_405A60(_47C65C_render_string, asc_464C60, 0, v1);
						_47C65C_render_string->field_18 = 0;
						render_string_405A60(_47C65C_render_string, str, 0, v1);
						render_string_405A60(_47C65C_render_string, asc_464C88, 0, v1);
						if (v22)
							v17 = v20 + 30;
						else
							v17 = v20 + 20;
						v8 = v26;
						v20 = v17;
					}
					else
					{
						++v6;
						v24 = 1;
						if (v6 == 17)
							v6 = 0;
						_47C65C_render_string->num_lines = v6;
						_47C65C_render_string->field_18 = 0;
						render_string_405A60(_47C65C_render_string, asc_464C60, 0, v1);
					}
				}
				v7 = v27 + 1;
				v19 = __OFSUB__(v27 + 1, 17);
				v18 = v27++ - 16 < 0;
			} while (v18 ^ v19);
		}
		render_string_list_remove(_47C65C_render_string);
		_47C65C_render_string = 0;
		a1->sprite->script = 0;
		sprite_list_remove(a1->sprite);
		script_443C40(a1, 0);
	}
	else
	{
		script_custom_mission_briefing_loop(a1);
	}
}

//----- (00405E60) --------------------------------------------------------
bool cplc_init()
{
	DataCplcItem *v1; // eax@3
	void *v2; // eax@3
	DataCplcItem *v3; // esi@4
	char v4; // dl@4
	int v8; // edx@4
	DataCplc_stru0 *v9; // eax@4
	DataCplcItem_ptr1 *v10; // eax@6
	DataCplcItem_ptr1 *v11; // eax@6
	DataCplcItem_ptr1 *v12; // ecx@6
	int v13; // eax@9
					// wait.lvl cpcl:
					// items[0]
					// 
					// item = 0:
					// 00000004: 00 00 00 44    item size
					// 00000008: 00 00 00 18    ptr1
					// 0000000C: 00 00 00 18    ptr2
					// 00000010: 00 00 00 18    ptr3
					// 00000014: 00 00 00 18    ptr4
					// 
					// 00000018: 00 00 00 54    ptr#.field_0
					//           00 00 00 00    ptr#.field_4
					//           00 00 01 00    ptr#.field_8
					//           00 00 00 00    ptr#.field_C
					//           00 00 00 00    ptr#.field_10
					//           00 00 00 00    ptr#.field_14
					//           00 00 00 00    ptr#.field_18
					//           00 00 00 00
					//           00 00 00 14
					//           00 00 00 00
					//           00 00 00 00
					//           00 00 00 00
	currently_running_lvl_cplc_valid = 0;
	currently_running_lvl_cplc = (DataCplc *)LVL_FindSection(CPLC);
	if (currently_running_lvl_cplc)
	{
		cplc_stru0_list = (DataCplc_stru0 *)malloc(0x5DC0u);
		if (!cplc_stru0_list)
			return false;
		currently_running_lvl_cplc_data = 0;
		v1 = currently_running_lvl_cplc->items;
		currently_running_lvl_cplc_item = v1;
		currently_running_lvl_cplc_data_size = v1->size + 4;
		v2 = malloc(currently_running_lvl_cplc_data_size);
		currently_running_lvl_cplc_data = v2;
		if (!v2)
			goto LABEL_9;
		v3 = currently_running_lvl_cplc_item;
		v4 = currently_running_lvl_cplc_data_size;
        memcpy(v2, currently_running_lvl_cplc_item, currently_running_lvl_cplc_data_size);
		v8 = 1999;
		v9 = cplc_stru0_list;
		cplc_stru0_list_free_pool = cplc_stru0_list;
		do
		{
			--v8;
			v9->next = v9 + 1;
			++v9;
		} while (v8);
		v9->next = 0;
		cplc_stru0_list_477464 = 0;
		v10 = currently_running_lvl_cplc_item->ptr1;
		_477430_cplc_item0_ptr1 = v10;
		_477420_cplc_next1 = v10;
		_47746C_cplc_prev1 = currently_running_lvl_cplc_item->ptr2;
		v11 = currently_running_lvl_cplc_item->ptr3;
		_477414_cplc_next2 = v11;
		_477438_cplc_item0_ptr3 = v11;
		v12 = currently_running_lvl_cplc_item->ptr4;
		_47744C_cplc_item0_ptr4 = v11;
		_477458_cplc_prev2 = v12;
		if (v11)
		{
			while (v11->script_handler_id != 84)    // //  46EE08  Script4  MOBD_20
			{
				v11 = v11->next2;
				_47744C_cplc_item0_ptr4 = v11;
				if (!v11)
					goto LABEL_9;
			}
			_47C380_mapd.mapd_cplc_render_x = v11->x;
			_47C380_mapd.mapd_cplc_render_y = v11->y;
			_47C380_mapd.mapd_cplc_item0_ptr_field_C = v11->z_index;
			__47C380_mapd_cplc_item0_ptr_field_4_minus_3FFF = _47C380_mapd.mapd_cplc_render_x - 0x3FFF;
			_47C384_mapd_cplc_item0_ptr_field_8_minus_3FFF = _47C380_mapd.mapd_cplc_render_y - 0x3FFF;
			v13 = 1;
		}
		else
		{
		LABEL_9:
			v13 = 0;
		}
		if (!v13)
		{
			free(cplc_stru0_list);
			return 0;
		}
		currently_running_lvl_cplc_valid = 1;
	}
	return 1;
}

//----- (00405FD0) --------------------------------------------------------
bool cplc_select(int id)
{
	size_t v1; // eax@1
	DataCplcItem *v2; // eax@3
	DataCplcItem *v3; // esi@4
	char v4; // dl@4
	int v8; // edx@4
	DataCplc_stru0 *v9; // eax@4
	DataCplcItem_ptr1 *v10; // eax@6
	DataCplcItem_ptr1 *v11; // eax@6
	DataCplcItem_ptr1 *v12; // ecx@6

	currently_running_lvl_cplc_item = currently_running_lvl_cplc[id].items;
	v1 = currently_running_lvl_cplc_item->size + 4;
	currently_running_lvl_cplc_data_size = currently_running_lvl_cplc_item->size + 4;
	if (currently_running_lvl_cplc_data)
	{
		free(currently_running_lvl_cplc_data);
		v1 = currently_running_lvl_cplc_data_size;
	}
	v2 = (DataCplcItem *)malloc(v1);
	currently_running_lvl_cplc_data = v2;
	if (!v2)
		goto LABEL_15;
	v3 = currently_running_lvl_cplc_item;
	v4 = currently_running_lvl_cplc_data_size;
    memcpy(v2, currently_running_lvl_cplc_item, currently_running_lvl_cplc_data_size);
	v8 = 1999;
	v9 = cplc_stru0_list;
	cplc_stru0_list_free_pool = cplc_stru0_list;
	do
	{
		--v8;
		v9->next = v9 + 1;
		++v9;
	} while (v8);
	v9->next = 0;
	cplc_stru0_list_477464 = 0;
	v10 = currently_running_lvl_cplc_item->ptr1;
	_477430_cplc_item0_ptr1 = v10;
	_477420_cplc_next1 = v10;
	_47746C_cplc_prev1 = currently_running_lvl_cplc_item->ptr2;
	v11 = currently_running_lvl_cplc_item->ptr3;
	_477414_cplc_next2 = v11;
	_477438_cplc_item0_ptr3 = v11;
	v12 = currently_running_lvl_cplc_item->ptr4;
	_47744C_cplc_item0_ptr4 = v11;
	_477458_cplc_prev2 = v12;
	if (v11)
	{
		while (v11->script_handler_id != 84)      // //  46EE08  Script4  MOBD_20
		{
			v11 = v11->next2;
			_47744C_cplc_item0_ptr4 = v11;
			if (!v11)
				return (unsigned int)v11;
		}
		_47C380_mapd.mapd_cplc_render_x = v11->x;
		_47C380_mapd.mapd_cplc_render_y = v11->y;
		_47C380_mapd.mapd_cplc_item0_ptr_field_C = v11->z_index;
		__47C380_mapd_cplc_item0_ptr_field_4_minus_3FFF = _47C380_mapd.mapd_cplc_render_x - 0x3FFF;
		_47C384_mapd_cplc_item0_ptr_field_8_minus_3FFF = _47C380_mapd.mapd_cplc_render_y - 0x3FFF;
		return 1;
	}
	else
	{
	LABEL_15:
		return 0;
	}
}

//----- (004060F0) --------------------------------------------------------
void cplc_4060F0()
{
	char *v0; // esi@1
	DataCplcItem *v1; // edi@2
	int v3; // edx@2
	DataCplc_stru0 *v5; // eax@2
	DataCplcItem_ptr1 *v6; // eax@4
	DataCplcItem_ptr1 *v7; // eax@4
	DataCplcItem_ptr1 *v8; // ecx@4

	v0 = (char *)currently_running_lvl_cplc_data;
	if (currently_running_lvl_cplc_data)
	{
		v1 = currently_running_lvl_cplc_item;
		v3 = 1999;

        memcpy(currently_running_lvl_cplc_item, currently_running_lvl_cplc_data, currently_running_lvl_cplc_data_size);

		v5 = cplc_stru0_list;
		cplc_stru0_list_free_pool = cplc_stru0_list;
		do
		{
			--v3;
			v5->next = v5 + 1;
			++v5;
		} while (v3);
		v5->next = 0;
		cplc_stru0_list_477464 = 0;
		v6 = currently_running_lvl_cplc_item->ptr1;
		_477430_cplc_item0_ptr1 = v6;
		_477420_cplc_next1 = v6;
		_47746C_cplc_prev1 = currently_running_lvl_cplc_item->ptr2;
		v7 = currently_running_lvl_cplc_item->ptr3;
		_477414_cplc_next2 = v7;
		_477438_cplc_item0_ptr3 = v7;
		v8 = currently_running_lvl_cplc_item->ptr4;
		_47744C_cplc_item0_ptr4 = v7;
		_477458_cplc_prev2 = v8;
		if (v7)
		{
			while (v7->script_handler_id != 84)
			{
				v7 = v7->next2;
				_47744C_cplc_item0_ptr4 = v7;
				if (!v7)
					return;
			}
			_47C380_mapd.mapd_cplc_render_x = v7->x;
			_47C380_mapd.mapd_cplc_render_y = v7->y;
			_47C380_mapd.mapd_cplc_item0_ptr_field_C = v7->z_index;
			__47C380_mapd_cplc_item0_ptr_field_4_minus_3FFF = _47C380_mapd.mapd_cplc_render_x - 0x3FFF;
			_47C384_mapd_cplc_item0_ptr_field_8_minus_3FFF = _47C380_mapd.mapd_cplc_render_y - 0x3FFF;
		}
	}
}

//----- (004061D0) --------------------------------------------------------
void cplc_create_sprite_script(DataCplcItem_ptr1 *a1)
{
	DataCplcItem_ptr1 *v1; // esi@1
	DataCplcItem_ptr1 *v2; // eax@1
	DataCplcItem_ptr1 *v3; // eax@4
	DataCplcItem_ptr1 *v4; // eax@6
	DataCplcItem_ptr1 *v5; // eax@9
	Sprite *v10; // eax@19
	DataCplc_stru0 *v11; // eax@19

	v1 = a1;
	v2 = a1->prev1;
	if (v2)
		v2->next1 = a1->next1;
	else
		_477430_cplc_item0_ptr1 = a1->next1;
	v3 = a1->next1;
	if (v3)
		v3->prev1 = a1->prev1;
	v4 = a1->prev2;
	if (v4)
		v4->next2 = a1->next2;
	else
		_477438_cplc_item0_ptr3 = a1->next2;
	v5 = a1->next2;
	if (v5)
		v5->prev2 = a1->prev2;
	if (!a1->_20_stru20.field_C)
	{
        if (v1->script_handler_id >= 0)
        {
            auto v8 = create_script(v1->script_handler_id);
			auto v9 = get_script_mobd(v1->script_handler_id);
			if (v9 >= 0)
			{
				v10 = sprite_create(v9, v8, 0);
				v10->cplc_ptr1 = v1;
				v10->x = v1->x;
				v10->y = v1->y;
				v10->z_index = v1->z_index;
				v10->cplc_ptr1_pstru20 = &v1->_20_stru20;
				v1->_20_stru20.sprite = v10;
				v10->cplc_stru0 = cplc_stru0_list_free_pool;
				cplc_stru0_list_free_pool->sprite = v10;
				v11 = cplc_stru0_list_free_pool;
				cplc_stru0_list_free_pool->prev = 0;
				cplc_stru0_list_free_pool = cplc_stru0_list_free_pool->next;
				v11->next = cplc_stru0_list_477464;
				if (cplc_stru0_list_477464)
					cplc_stru0_list_477464->prev = v11;
				cplc_stru0_list_477464 = v11;
			}
		}
	}
}

//----- (004062E0) --------------------------------------------------------
void cplc_4062E0_stru0_list_remove(DataCplc_stru0 *a1)
{
	DataCplc_stru0 *v1; // eax@1

	a1->sprite->cplc_stru0 = 0;
	v1 = a1->prev;
	if (v1)
		v1->next = a1->next;
	else
		cplc_stru0_list_477464 = a1->next;
	if (a1->next)
		a1->next->prev = a1->prev;
	a1->next = cplc_stru0_list_free_pool;
	cplc_stru0_list_free_pool = a1;
}

//----- (00406320) --------------------------------------------------------
void cplc_406320()
{
	int v0; // ebx@2
	int v1; // edi@2
	int v2; // edx@2
	DataCplc_stru0 *v3; // ecx@2
	int v4; // esi@2
	Sprite *v5; // eax@3
	int v6; // edi@3
	int v7; // edi@5
	Script *v8; // eax@8
	DataCplc_stru0 *v9; // eax@10
	DataCplc_stru0 **v10; // edx@10
	DataCplcItem_ptr1 *v11; // eax@19
	DataCplcItem_ptr1 *v12; // ebx@19
	DataCplcItem_ptr1 *v13; // ecx@19
	DataCplcItem_ptr1 *v14; // edi@19
	int v15; // ebp@19
	int v16; // esi@20
	int v17; // edx@21
	DataCplcItem_ptr1 *v18; // edx@42
	DataCplcItem_ptr1 *v19; // eax@47
	DataCplcItem_ptr1 *v20; // edi@51
	DataCplcItem_ptr1 *v21; // eax@51
	int v22; // ebp@51
	int v23; // esi@52
	int v24; // edx@53
	DataCplcItem_ptr1 *v25; // edx@74
	DataCplcItem_ptr1 *v26; // eax@79
	int v27; // edi@83
	int v28; // esi@84
	int v29; // edx@86
	int v30; // eax@87
	DataCplcItem_ptr1 *v31; // eax@92
	DataCplcItem_ptr1 *v32; // eax@106
	DataCplcItem_ptr1 *v33; // eax@111
	int v34; // esi@115
	int v35; // edx@116
	int v36; // eax@117
	DataCplcItem_ptr1 *v37; // eax@126
	DataCplcItem_ptr1 *v38; // eax@136
	DataCplcItem_ptr1 *v39; // eax@141
	int v40; // [sp+10h] [bp-4h]@2

	if (currently_running_lvl_cplc_valid)
	{
		v0 = __47C380_mapd_cplc_item0_ptr_field_4_minus_3FFF;
		v1 = _47C380_mapd.mapd_cplc_render_x - 0x4000;
		__47C380_mapd_cplc_item0_ptr_field_4_minus_3FFF = _47C380_mapd.mapd_cplc_render_x - 0x4000;
		dword_47745C = _47C380_mapd.mapd_cplc_render_x + ((render_width + 64) << 8);
		_477448_cplc_x = _47C380_mapd.mapd_cplc_render_x - 24576;
		v2 = _47C380_mapd.mapd_cplc_render_x + ((render_width + 96) << 8);
		v40 = _47C384_mapd_cplc_item0_ptr_field_8_minus_3FFF;
		dword_477440 = _47C380_mapd.mapd_cplc_render_x + ((render_width + 96) << 8);
		_47C384_mapd_cplc_item0_ptr_field_8_minus_3FFF = _47C380_mapd.mapd_cplc_render_y - 0x4000;
		dword_477460 = _47C380_mapd.mapd_cplc_render_y + ((render_height - 64) << 8);
		_477454_cplc_y = _47C380_mapd.mapd_cplc_render_y - 24576;
		v3 = cplc_stru0_list_477464;
		v4 = _47C380_mapd.mapd_cplc_render_y + ((render_height - 32) << 8);
		dword_47743C = _47C380_mapd.mapd_cplc_render_y + ((render_height - 32) << 8);
		if (cplc_stru0_list_477464)
		{
			do
			{
				v5 = v3->sprite;
				v6 = v5->x;
				if (v6 < _477448_cplc_x || v6 > v2 || (v7 = v5->y, v7 < _477454_cplc_y) || v7 > v4)
				{
					v8 = v5->script;
					if (v8)
					{
						v8->flags_20 |= SCRIPT_FLAGS_20_20000;
						v3->sprite->script->flags_24 |= v3->sprite->script->flags_20;
					}
					v9 = v3;
					v3 = v3->next;
					v9->sprite->cplc_stru0 = 0;
					v10 = &v9->prev->next;
					if (v10)
						*v10 = v9->next;
					else
						cplc_stru0_list_477464 = v9->next;
					if (v9->next)
						v9->next->prev = v9->prev;
					v9->next = cplc_stru0_list_free_pool;
					v2 = dword_477440;
					v4 = dword_47743C;
					cplc_stru0_list_free_pool = v9;
				}
				else
				{
					v3 = v3->next;
				}
			} while (v3);
			v1 = __47C380_mapd_cplc_item0_ptr_field_4_minus_3FFF;
		}
		if (v1 >= v0)
		{
			if (v1 <= v0)
			{
				v12 = _477458_cplc_prev2;
				v13 = _477414_cplc_next2;
			}
			else
			{
				v20 = _47746C_cplc_prev1;
				v12 = _477458_cplc_prev2;
				v13 = _477414_cplc_next2;
				v21 = _477420_cplc_next1;
				v22 = 0;
				do
				{
					v23 = v21->x;
					if (v23 > dword_47745C)
						break;
					v24 = v21->y;
					if (v24 >= _47C384_mapd_cplc_item0_ptr_field_8_minus_3FFF
						&& v24 <= dword_477460
						&& v23 >= __47C380_mapd_cplc_item0_ptr_field_4_minus_3FFF
						&& v21->script_handler_id != 84)
					{
						cplc_create_sprite_script(v21);
						v21 = _477420_cplc_next1;
						v12 = _477458_cplc_prev2;
						if (_477420_cplc_next1 == _477458_cplc_prev2)
						{
							if (_477458_cplc_prev2->prev2)
								v12 = _477458_cplc_prev2->prev2;
							else
								v12 = _477458_cplc_prev2->next2;
							_477458_cplc_prev2 = v12;
						}
						v13 = _477414_cplc_next2;
						if (_477420_cplc_next1 == _477414_cplc_next2)
						{
							if (_477414_cplc_next2->next2)
								v13 = _477414_cplc_next2->next2;
							else
								v13 = _477414_cplc_next2->prev2;
							_477414_cplc_next2 = v13;
						}
						v20 = _47746C_cplc_prev1;
						if (_477420_cplc_next1 == _47746C_cplc_prev1)
						{
							if (_47746C_cplc_prev1->next1)
								v20 = _47746C_cplc_prev1->next1;
							else
								v20 = _47746C_cplc_prev1->prev1;
							_47746C_cplc_prev1 = v20;
						}
						if (!_477420_cplc_next1->next1)
						{
							v21 = _477420_cplc_next1->prev1;
							_477420_cplc_next1 = _477420_cplc_next1->prev1;
						}
					}
					v25 = v21->next1;
					if (v25)
					{
						v21 = v21->next1;
						_477420_cplc_next1 = v25;
					}
					else
					{
						v22 = 1;
					}
				} while (!v22);
				if (v20->x <= __47C380_mapd_cplc_item0_ptr_field_4_minus_3FFF)
				{
					do
					{
						v26 = v20->next1;
						if (!v26)
							break;
						v20 = v20->next1;
						_47746C_cplc_prev1 = v26;
					} while (v26->x <= __47C380_mapd_cplc_item0_ptr_field_4_minus_3FFF);
				}
			}
		}
		else
		{
			v11 = _47746C_cplc_prev1;
			v12 = _477458_cplc_prev2;
			v13 = _477414_cplc_next2;
			v14 = _477420_cplc_next1;
			v15 = 0;
			do
			{
				v16 = v11->x;
				if (v16 < __47C380_mapd_cplc_item0_ptr_field_4_minus_3FFF)
					break;
				v17 = v11->y;
				if (v17 >= _47C384_mapd_cplc_item0_ptr_field_8_minus_3FFF
					&& v17 <= dword_477460
					&& v16 <= dword_47745C
					&& v11->script_handler_id != 84)
				{
					cplc_create_sprite_script(v11);
					v11 = _47746C_cplc_prev1;
					v12 = _477458_cplc_prev2;
					if (_47746C_cplc_prev1 == _477458_cplc_prev2)
					{
						if (_477458_cplc_prev2->prev2)
							v12 = _477458_cplc_prev2->prev2;
						else
							v12 = _477458_cplc_prev2->next2;
						_477458_cplc_prev2 = v12;
					}
					v13 = _477414_cplc_next2;
					if (_47746C_cplc_prev1 == _477414_cplc_next2)
					{
						if (_477414_cplc_next2->next2)
							v13 = _477414_cplc_next2->next2;
						else
							v13 = _477414_cplc_next2->prev2;
						_477414_cplc_next2 = v13;
					}
					v14 = _477420_cplc_next1;
					if (_47746C_cplc_prev1 == _477420_cplc_next1)
					{
						if (_477420_cplc_next1->prev1)
							v14 = _477420_cplc_next1->prev1;
						else
							v14 = _477420_cplc_next1->next1;
						_477420_cplc_next1 = v14;
					}
					if (!_47746C_cplc_prev1->prev1)
					{
						v11 = _47746C_cplc_prev1->next1;
						_47746C_cplc_prev1 = _47746C_cplc_prev1->next1;
					}
				}
				v18 = v11->prev1;
				if (v18)
				{
					v11 = v11->prev1;
					_47746C_cplc_prev1 = v18;
				}
				else
				{
					v15 = 1;
				}
			} while (!v15);
			if (v14->x >= dword_47745C)
			{
				do
				{
					v19 = v14->prev1;
					if (!v19)
						break;
					v14 = v14->prev1;
					_477420_cplc_next1 = v19;
				} while (v19->x >= dword_47745C);
			}
		}
		v27 = _47C384_mapd_cplc_item0_ptr_field_8_minus_3FFF;
		if (_47C384_mapd_cplc_item0_ptr_field_8_minus_3FFF >= v40)
		{
			if (_47C384_mapd_cplc_item0_ptr_field_8_minus_3FFF > v40)
			{
				v34 = 0;
				do
				{
					v35 = v13->y;
					if (v35 > dword_477460)
						break;
					v36 = v13->x;
					if (v36 >= __47C380_mapd_cplc_item0_ptr_field_4_minus_3FFF
						&& v36 <= dword_47745C
						&& v35 >= v27
						&& v13->script_handler_id != 84)
					{
						cplc_create_sprite_script(v13);
						v13 = _477414_cplc_next2;
						if (_477414_cplc_next2 == _47746C_cplc_prev1)
						{
							if (_47746C_cplc_prev1->prev1)
								_47746C_cplc_prev1 = _47746C_cplc_prev1->prev1;
							else
								_47746C_cplc_prev1 = _47746C_cplc_prev1->next1;
						}
						if (_477414_cplc_next2 == _477420_cplc_next1)
						{
							v37 = _477420_cplc_next1->next1;
							if (!v37)
								v37 = _477420_cplc_next1->prev1;
							_477420_cplc_next1 = v37;
						}
						v12 = _477458_cplc_prev2;
						if (_477414_cplc_next2 == _477458_cplc_prev2)
						{
							if (_477458_cplc_prev2->next2)
								v12 = _477458_cplc_prev2->next2;
							else
								v12 = _477458_cplc_prev2->prev2;
							_477458_cplc_prev2 = v12;
						}
						if (!_477414_cplc_next2->next2)
						{
							v13 = _477414_cplc_next2->prev2;
							_477414_cplc_next2 = _477414_cplc_next2->prev2;
						}
					}
					v38 = v13->next2;
					if (v38)
					{
						v13 = v13->next2;
						_477414_cplc_next2 = v38;
					}
					else
					{
						v34 = 1;
					}
					v27 = _47C384_mapd_cplc_item0_ptr_field_8_minus_3FFF;
				} while (!v34);
				if (v12->y <= v27)
				{
					do
					{
						v39 = v12->next2;
						if (!v39)
							break;
						v12 = v12->next2;
						_477458_cplc_prev2 = v39;
					} while (v39->y <= v27);
				}
			}
		}
		else
		{
			v28 = 0;
			while (1)
			{
				v29 = v12->y;
				if (v29 < v27)
					break;
				v30 = v12->x;
				if (v30 >= __47C380_mapd_cplc_item0_ptr_field_4_minus_3FFF
					&& v30 <= dword_47745C
					&& v29 <= dword_477460
					&& v12->script_handler_id != 84)
				{
					cplc_create_sprite_script(v12);
					v12 = _477458_cplc_prev2;
					if (_477458_cplc_prev2 == _47746C_cplc_prev1)
					{
						v31 = _47746C_cplc_prev1->prev1;
						if (!v31)
							v31 = _47746C_cplc_prev1->next1;
						_47746C_cplc_prev1 = v31;
					}
					if (_477458_cplc_prev2 == _477420_cplc_next1)
					{
						if (_477420_cplc_next1->next1)
							_477420_cplc_next1 = _477420_cplc_next1->next1;
						else
							_477420_cplc_next1 = _477420_cplc_next1->prev1;
					}
					v13 = _477414_cplc_next2;
					if (_477458_cplc_prev2 == _477414_cplc_next2)
					{
						if (_477414_cplc_next2->prev2)
							v13 = _477414_cplc_next2->prev2;
						else
							v13 = _477414_cplc_next2->next2;
						_477414_cplc_next2 = v13;
					}
					if (!_477458_cplc_prev2->prev2)
					{
						v12 = _477458_cplc_prev2->next2;
						_477458_cplc_prev2 = _477458_cplc_prev2->next2;
					}
				}
				v32 = v12->prev2;
				if (v32)
				{
					v12 = v12->prev2;
					_477458_cplc_prev2 = v32;
				}
				else
				{
					v28 = 1;
				}
				if (v28)
					break;
				v27 = _47C384_mapd_cplc_item0_ptr_field_8_minus_3FFF;
			}
			if (v13->y >= dword_477460)
			{
				do
				{
					v33 = v13->prev2;
					if (!v33)
						break;
					v13 = v13->prev2;
					_477414_cplc_next2 = v33;
				} while (v33->y >= dword_477460);
			}
		}
	}
}
// 477418: using guessed type int currently_running_lvl_cplc_valid;
// 477428: using guessed type int __47C380_mapd_cplc_item0_ptr_field_4_minus_3FFF;
// 477434: using guessed type int _47C384_mapd_cplc_item0_ptr_field_8_minus_3FFF;
// 47743C: using guessed type int dword_47743C;
// 477440: using guessed type int dword_477440;
// 477448: using guessed type int _477448_cplc_x;
// 477454: using guessed type int _477454_cplc_y;
// 47745C: using guessed type int dword_47745C;
// 477460: using guessed type int dword_477460;

//----- (004068B0) --------------------------------------------------------
void cplc_init_script_do_reinit(int a1)
{
	cplc_init_script(a1, 1);
}

//----- (004068C0) --------------------------------------------------------
void cplc_init_script(int handler_id, bool reinit_ptrs)
{
	DataCplcItem_ptr1 *v3; // esi@2
	DataCplcItem_ptr1 *v4; // edx@3
	DataCplcItem_ptr1 *v5; // ecx@3
	DataCplcItem_ptr1 *v6; // edi@3
	DataCplcItem_ptr1 *v7; // ebx@3

	if (currently_running_lvl_cplc_valid)
	{
		v3 = _477430_cplc_item0_ptr1;
		if (_477430_cplc_item0_ptr1)
		{
			v4 = _477458_cplc_prev2;
			v5 = _477414_cplc_next2;
			v6 = _477420_cplc_next1;
			v7 = _47746C_cplc_prev1;
			do
			{
				if (v3->script_handler_id == handler_id)
				{
					if (reinit_ptrs)
					{
						cplc_create_sprite_script(v3);
						v7 = _47746C_cplc_prev1;
						v6 = _477420_cplc_next1;
						v4 = _477458_cplc_prev2;
						v5 = _477414_cplc_next2;
					}
					if (v3 == v7)
					{
						if (v7->prev1)
							v7 = v7->prev1;
						else
							v7 = v7->next1;
						_47746C_cplc_prev1 = v7;
					}
					if (v3 == v6)
					{
						if (v6->next1)
							v6 = v6->next1;
						else
							v6 = v6->prev1;
						_477420_cplc_next1 = v6;
					}
					if (v3 == v4)
					{
						if (v4->prev2)
							v4 = v4->prev2;
						else
							v4 = v4->next2;
						_477458_cplc_prev2 = v4;
					}
					if (v3 == v5)
					{
						if (v5->next2)
							v5 = v5->next2;
						else
							v5 = v5->prev2;
						_477414_cplc_next2 = v5;
					}
				}
				v3 = v3->next1;
			} while (v3);
		}
	}
}
// 477418: using guessed type int currently_running_lvl_cplc_valid;

//----- (004069A0) --------------------------------------------------------
void cplc_init_script_dont_reinit(int a1)
{
	cplc_init_script(a1, 0);
}

//----- (004069B0) --------------------------------------------------------
void cplc_free()
{
	if (currently_running_lvl_cplc_valid)
	{
		if (cplc_stru0_list)
		{
			free(cplc_stru0_list);
			if (currently_running_lvl_cplc_data)
				free(currently_running_lvl_cplc_data);
		}
	}
	currently_running_lvl_cplc_valid = 0;
}

//----- (00406FD0) --------------------------------------------------------
bool oilspot_list_alloc()
{
	int v1; // ecx@2

	oilspot_list = (OilDeposit *)malloc(0x1800u);
	if (oilspot_list)
	{
		oilspot_list_free_pool = oilspot_list;
		v1 = 0;
		do
		{
            oilspot_list[v1].next = &oilspot_list[v1 + 1];
			++v1;
		} while (v1 < 255);
		oilspot_list[255].next = 0;
		oilspot_list_head = (OilDeposit *)&oilspot_list_head;
		oildeposit_list_end = (OilDeposit *)&oilspot_list_head;
        return true;
	}
    return false;
}

//----- (00407030) --------------------------------------------------------
void oilspot_list_free()
{
	free(oilspot_list);
}

//----- (00407040) --------------------------------------------------------
OilDeposit *oilspot_list_407040_find_by_coordinates(int x, int y)
{
	OilDeposit *result; // eax@1
	Sprite *v3; // esi@2

	result = oilspot_list_head;
	if ((OilDeposit **)oilspot_list_head == &oilspot_list_head)
	{
	LABEL_6:
		result = 0;
	}
	else
	{
		while (1)
		{
			v3 = result->sprite;
			if (map_is_same_tile(x, v3->x) && map_is_same_tile(y, v3->y) && !(v3->drawjob->flags & 0x40000000))
				break;
			result = result->next;
			if ((OilDeposit **)result == &oilspot_list_head)
				goto LABEL_6;
		}
	}
	return result;
}

//----- (00407090) --------------------------------------------------------
OilDeposit *oilspot_list_407090_find_by_sprite_coordinates(int x, int y)
{
	OilDeposit *v2; // ebp@1
	int v3; // eax@1
	OilDeposit *i; // edx@1
	Sprite *v5; // ebx@2
	int v6; // esi@2
	int v7; // ebx@4
	int v8; // edi@4
	int v9; // esi@6
	int v11; // [sp+4h] [bp-4h]@1

	v2 = oilspot_list_head;
	v11 = y;
	v3 = 81920;
	for (i = 0; (OilDeposit **)v2 != &oilspot_list_head; v2 = v2->next)
	{
		v5 = v2->sprite;
		v6 = v5->x - x;
		if (v6 <= 0)
			v6 = x - v5->x;
		v7 = v5->y;
		v8 = v7 - v11;
		if (v7 - v11 <= 0)
			v8 = v11 - v7;
		v9 = v8 + v6;
		if (v9 < v3)
		{
			i = v2;
			v3 = v9;
		}
	}
	return i;
}

//----- (004070F0) --------------------------------------------------------
int oilspot_subtract_oil(OilDeposit *a1, int amount)
{
	int v2; // esi@1
	int result; // eax@1
	Sprite *v4; // esi@2
	Entity *v5; // esi@2
	EntityTurret *v6; // esi@4
	Sprite *v7; // esi@5

	v2 = a1->oil_left;
	result = amount;
	if (v2 > amount)
	{
		a1->oil_left = v2 - amount;
	}
	else
	{
		result = a1->oil_left;
		v4 = a1->sprite;
		a1->oil_left = 0;
		v4->script->flags_20 |= SCRIPT_FLAGS_20_1;
		a1->sprite->script->flags_24 |= a1->sprite->script->flags_20;
		v5 = a1->drillrig;
		if (v5)
		{
			if (v5->entity_id == a1->drillrig_entity_id)
			{
				v6 = v5->turret;
				if (v6)
				{
					v7 = v6->turret_sprite;
					if (v7)
						v7->_60_mobd_anim_speed = 0;
				}
			}
		}
	}
	return result;
}

//----- (00407160) --------------------------------------------------------
void UNIT_Handler_OilPatch(Script *a1)
{
	Sprite *v1; // esi@1
	DataCplcItem_ptr1 *v2; // eax@1
	OilDeposit *v4; // edi@2
	int v6; // eax@7
	char *v7; // eax@7

	v1 = a1->sprite;
	v1->drawjob->on_update_handler = (DrawJobUpdateHandler)drawjob_update_handler_448600_oilspot;
	sprite_load_mobd(v1, 0);
	v2 = v1->cplc_ptr1;
	v1->x = map_point_to_tile_global(v1->x) + 4096;
	v1->field_88_unused = 1;
	v1->y = map_point_to_tile_global(v1->y) + 4096;
	if (v2)
	{
		v4 = oilspot_list_free_pool;
		if (oilspot_list_free_pool)
			oilspot_list_free_pool = oilspot_list_free_pool->next;
		else
			v4 = 0;
		v4->sprite = v1;
		v4->drillrig = 0;
		v4->drillrig_entity_id = 0;
		v4->oil_left = 500 * LOWORD_HEXRAYS(v1->cplc_ptr1_pstru20->param_1C);
		v4->next = oilspot_list_head;
		v4->prev = (OilDeposit *)&oilspot_list_head;
		oilspot_list_head->prev = v4;
		oilspot_list_head = v4;
	}
	else
	{
		v4 = (OilDeposit *)a1->param;
	}
	v6 = v1->y;
	v1->field_88_unused = 1;
	v7 = &boxd_get_tile(v1->x >> 13, v6 >> 13)->flags2;
	*v7 |= 0x80u;
	script_yield(a1, 1, 0);
	v1->drawjob->flags |= 0x40000000u;
	if (a1)
	{
		while (1)
            script_sleep(a1, 1000);
	}
	v4->next->prev = v4->prev;
	v4->prev->next = v4->next;
	v4->next = oilspot_list_free_pool;
	oilspot_list_free_pool = v4;
	sprite_list_remove(v1);
}

void entity_on_attacked_drillrig(Entity *e) {
    if (player_side == e->player_side && e->_12C_prison_bunker_spawn_type == 0)
    {
        e->_12C_prison_bunker_spawn_type = 1500;
        if (is_player_faction_evolved())
            sound_play(SOUND_MUTE_UNIT_DRILL_RIG, 0, _4690A8_unit_sounds_volume, 16, 0);
        else
            sound_play(SOUND_SURV_UNIT_DRILL_RIG, 0, _4690A8_unit_sounds_volume, 16, 0);
    }
}

//----- (00407FD0) --------------------------------------------------------
void EventHandler_DrillRig(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param)
{
	Entity *v4; // esi@1

	v4 = (Entity *)receiver->param;
	if (!v4->destroyed)
	{
		switch (event)
		{
		case MSG_ATTACKED:
            entity_on_attacked_drillrig(v4);
			break;
		case CMD_APPLY_DAMAGE:
			entity_402E90_on_damage(v4, param, entity_mode_drillrig_on_death);
			entity_410520_update_healthbar_color(v4);
			break;
		case EVT_MSG_DESTROY:
			entity_402E40_destroy((Entity *)receiver->param, entity_mode_drillrig_on_death);
			break;
		default:
			if (event != 1523)
				EventHandler_DefaultBuildingsHandler(receiver, sender, event, param);
			break;
		}
	}
}

//----- (004080A0) --------------------------------------------------------
void UNIT_Handler_DrillRig(Script *a1)
{
	Entity *v1; // esi@1
	Entity *v2; // eax@3
	OilDeposit *v3; // eax@3
	void *v4; // eax@8
	int v5; // eax@11

	v1 = (Entity *)a1->param;
	if (!_47C6DC_dont_execute_unit_handlers)
	{
		if (!v1)
		{
			v2 = EntityFactory().Create(a1);
			v1 = v2;
			v2->script->event_handler = EventHandler_DrillRig;
			map_reveal_fog_around_entity(v2);
			v1->script->script_type = SCRIPT_DRILLRIG_HANDLER;
			entity_initialize_building(v1, 2, 0, 0);
			v1->sprite->field_88_unused = 1;
			v3 = oilspot_list_407090_find_by_sprite_coordinates(v1->sprite->x, v1->sprite->y);
			if (v3)
			{
				v1->sprite->x = map_point_to_tile_global(v3->sprite->x) + 4096;
				v1->sprite->y = map_point_to_tile_global(v3->sprite->y) + 4096;
			}
			v1->_11C__infantry_sprite_y___drillrig_oil_spot = (int)v3;
			v1->sprite->field_88_unused = 1;
			*(_DWORD *)v1->state = (int)oilspot_list_407040_find_by_coordinates(v1->sprite->x, v1->sprite->y);
			if (v1->sprite->cplc_ptr1_pstru20)
				v1->SetMode(entity_mode_408240_drillrig);
			else
				v1->SetMode(entity_mode_4081C0_drillrig);
			v4 = a1->sprite->_80_entity__stru29__sprite__initial_hitpoints;
			if (v4)
			{
				v1->hitpoints = (int)v4;
				entity_410520_update_healthbar_color(v1);
			}
			v1->_12C_prison_bunker_spawn_type = 0;
		}
		v1->ExecMode();
		v5 = v1->_12C_prison_bunker_spawn_type;
		if (v5)
			v1->_12C_prison_bunker_spawn_type = v5 - 1;
	}
}
// 47C6DC: using guessed type int _47C6DC_dont_execute_unit_handlers;

//----- (004081C0) --------------------------------------------------------
void entity_mode_4081C0_drillrig(Entity *a1)
{
	Entity *v1; // esi@1
	EntityTurret *v2; // eax@1
	Script *v3; // ecx@3

	v1 = a1;
	a1->sprite->x_speed = 0;
	a1->sprite->y_speed = 0;
	v2 = a1->turret;
	if (v2)
	{
		v2->turret_sprite->drawjob->flags |= 0x40000000u;
        entity_load_attack_mobd(a1);
		v3 = v1->script;
		v1->SetMode(entity_mode_408260_drillrig);
		script_yield(v3, SCRIPT_FLAGS_20_10000000, 0);
	}
	else
	{
        script_sleep(a1->script, 1);
	}
}

//----- (00408240) --------------------------------------------------------
void entity_mode_408240_drillrig(Entity *a1)
{
	a1->SetMode(entity_mode_408260_drillrig);
    script_sleep(a1->script, 1);
}

//----- (00408260) --------------------------------------------------------
void entity_mode_408260_drillrig(Entity *a1)
{
	Entity *v1; // esi@1
	OilDeposit *v2; // eax@2
	EntityTurret *v3; // eax@4

	v1 = a1;
	if (!a1->_11C__infantry_sprite_y___drillrig_oil_spot)
	{
		a1->sprite->field_88_unused = 1;
		v2 = oilspot_list_407090_find_by_sprite_coordinates(a1->sprite->x, a1->sprite->y);
		if (v2)
		{
			v1->sprite->x = map_point_to_tile_global(v2->sprite->x) + 4096;
			v1->sprite->y = map_point_to_tile_global(v2->sprite->y) + 4096;
		}
	}
	v3 = v1->turret;
	if (v3)
		v3->turret_sprite->drawjob->flags &= 0xBFFFFFFF;
	if (v1->sprite->cplc_ptr1_pstru20)
	{
		v1->SetMode(entity_mode_4034B0);
	}
	else
	{
		v1->SetMode(entity_mode_403650_building);
		entity_40DD00_boxd(v1);
	}
	v1->sprite->field_88_unused = 1;
	*(_DWORD *)v1->state = (int)oilspot_list_407040_find_by_coordinates(v1->sprite->x, v1->sprite->y);
	*(_DWORD *)(*(_DWORD *)v1->state + 16) = (int)v1;
	*(_DWORD *)(*(_DWORD *)v1->state + 20) = v1->entity_id;
	entity_mode_403650_building(v1);
}

//----- (00408330) --------------------------------------------------------
void entity_mode_drillrig_on_death(Entity *a1)
{
	script_trigger_event_group(a1->script, EVT_MSG_1540, 0, SCRIPT_TANKER_CONVOY_HANDLER);

    a1->destroyed = 1;
    a1->SetMode(entity_mode_building_on_death_default);
    script_sleep(a1->script, 1);
}

//----- (00408370) --------------------------------------------------------
void script_408370(Script *a1)
{
	int v1; // eax@1
	int *v2; // esi@2

	v1 = dword_464D38;
	if (dword_464D38)
	{
		v2 = dword_464D3C;
		do
		{
			dword_477890 = v1 << 8;
            script_sleep(a1, 1);
			v1 = *v2;
			++v2;
		} while (v1);
	}
	dword_477890 = 0;
	dword_477894 = 0;
	dword_477898 = 0;
	dword_47789C = 0;
	script_terminate(a1);
}

//----- (004083D0) --------------------------------------------------------
void sub_4083D0()
{
	if (!dword_477890 && !dword_477894)
		script_create_coroutine(SCRIPT_TYPE_INVALID, script_408370, 0);
}

//----- (00408400) --------------------------------------------------------
int sub_408400()
{
	return dword_4778AC;
}

//----- (00408480) --------------------------------------------------------
void stru1_408480_reset_animation()
{
	dword_4778A0 = 0;
	stru1_set_animation(0, 0, 0, 0);
}
// 4778A0: using guessed type int dword_4778A0;

//----- (004084A0) --------------------------------------------------------
void script_4084A0_animation(Script *a1)
{
	Script *v1; // esi@1

	v1 = a1;
	if (!dword_4778A0)
	{
		dword_4778A0 = 0;
		stru1_set_animation(0, 0, 0, 0);
		dword_4778A0 = 1;
		stru1_set_animation(0, 0, 0x80000000, 30);
        script_sleep(v1, 30);
		dword_4778A0 = 0;
	}
}
// 4778A0: using guessed type int dword_4778A0;

//----- (00408500) --------------------------------------------------------
void script_408500_anim(Script *a1)
{
	Script *v1; // esi@1

	v1 = a1;
	dword_4778A0 = 1;
	stru1_set_animation(0, 0x80000000, 0, 30);
    script_sleep(v1, 30);
	dword_4778A0 = 0;
	stru1_set_animation(0, 0, 0, 0);
	dword_4778A0 = 0;
}
// 4778A0: using guessed type int dword_4778A0;

//----- (00408780) --------------------------------------------------------
bool stru1_init_anim()
{
	render_default_stru1->anim_pos = 0x80000000;
	_4087A0_stru1_should_animate = 0;
	return 1;
}
// 4778B8: using guessed type int _4087A0_stru1_should_animate;

//----- (004087A0) --------------------------------------------------------
void stru1_set_animation(stru1_draw_params *a1, int start, int end, int length)
{
	if (!a1)
		a1 = render_default_stru1;
	if (length)
	{
		__4778C0_stru1_anim_length = length;
		_4778C0_stru1_anim_t = length;
		__4778C0_stru1_anim_start = start;
		__4778C0_stru1_anim_end = end;
		_4778C0_stru1_anim = a1;
		a1->anim_pos = start;
		_4087A0_stru1_should_animate = 1;
	}
	else
	{
		a1->anim_pos = end;
		_4087A0_stru1_should_animate = 0;
	}
}

//----- (00408800) --------------------------------------------------------
void sprite_408800_play_sound(Sprite *a1, enum SOUND_ID sound, int volume, Script *script)
{
	DrawJob *v4; // eax@1
	enum SOUND_ID s0und; // ebp@1
	stru1_draw_params *v6; // ebx@2
	int v7; // esi@4
	int v8; // edx@6
	int v9; // edx@6
	int v10; // edi@7
	int v11; // edx@7
	bool v12; // zf@14
	bool v13; // sf@14
	int v14; // esi@17
	int v15; // ecx@17
	int v16; // eax@18

	v4 = a1->drawjob;
	s0und = sound;
	if (!v4 || (v6 = v4->job_details.params) == 0)
		v6 = render_default_stru1;
	v7 = v6->clip_z << 7;
	if (v7 < 256)
		v7 = 256;
	v8 = a1->x;
	a1->field_88_unused = 1;
	v9 = v8 - _47C380_mapd.mapd_cplc_render_x - v7;
	if (v9 <= v7)
	{
		if (v9 >= -v7)
		{
			if (v9 < 0)
				v10 = 16 - 16 * (-v9 >> 8) / (v7 >> 8);
			else
				v10 = 16 * (v9 >> 8) / (v7 >> 8) + 16;
			v11 = volume;
		}
		else
		{
			v10 = 0;
			v11 = volume * (v9 + 2 * v7) / v7;
		}
	}
	else
	{
		v10 = 32;
		v11 = volume * (2 * v7 - v9) / v7;
	}
	v12 = v11 == 0;
	v13 = v11 < 0;
	if (v11 < 0)
	{
		v11 = 0;
		v12 = 1;
		v13 = 0;
	}
	if (!v13 && !v12)
	{
		v14 = v6->clip_w << 7;
		v15 = a1->y - _47C380_mapd.mapd_cplc_render_y - v14;
		if (v15 <= v14)
		{
			if (v15 >= -128 * v6->clip_w)
				goto LABEL_22;
			v16 = v15 + (v6->clip_w << 8);
		}
		else
		{
			v16 = (v6->clip_w << 8) - v15;
		}
		v11 = v11 * v16 / v14;
	LABEL_22:
		if (v11 < 0)
			v11 = 0;
	}
	if (v11 < 2)
		v11 = 2;
	if (v11 > _4690A8_unit_sounds_volume)
		v11 = _4690A8_unit_sounds_volume;
	if (script || v11)
		sound_play(s0und, 0, v11, v10, script);
}

//----- (00408930) --------------------------------------------------------
void stru1_animate()
{
	int v0; // esi@2

	if (_4087A0_stru1_should_animate)
	{
		v0 = _4778C0_stru1_anim_t-- - 1;
		if (_4778C0_stru1_anim_t)
		{
			if (__4778C0_stru1_anim_end <= (unsigned int)__4778C0_stru1_anim_start)
				_4778C0_stru1_anim->anim_pos = __4778C0_stru1_anim_end
				+ v0
				* ((__4778C0_stru1_anim_start - __4778C0_stru1_anim_end)
					/ (unsigned int)__4778C0_stru1_anim_length);
			else
				_4778C0_stru1_anim->anim_pos = __4778C0_stru1_anim_end
				- v0
				* ((__4778C0_stru1_anim_end - __4778C0_stru1_anim_start)
					/ (unsigned int)__4778C0_stru1_anim_length);
		}
		else
		{
			_4778C0_stru1_anim->anim_pos = __4778C0_stru1_anim_end;
			_4087A0_stru1_should_animate = 0;
		}
	}
}

//----- (0040D580) --------------------------------------------------------
int timer_init(unsigned int fps)
{
	int result; // eax@1

	timer_delta_ms = 1000 / fps;
	result = 1;
	timer_delta_updated = 1;
	return result;
}

//----- (0040D5A0) --------------------------------------------------------
void TimedMessagePump()
{
	DWORD v0; // eax@3

	if (timer_delta_updated)
	{
		timer_delta_updated = 0;
		timer_time = timer_delta_ms + OsGetPrecisionTime();
	}
	else
	{
		v0 = OsGetPrecisionTime();
		if ((int)(timer_time - v0) > 0)
			OsThreadSleep(timer_time - v0);
		timer_time += timer_delta_ms;
        gWindow->PeekMessageAll();
	}
}

//----- (0040D600) --------------------------------------------------------
int entity_40D600_infantry_get_new_movement_orientation(Entity *a1, int sprite_width, int sprite_height, int a4)
{
	Sprite *v4; // esi@1
	int v5; // ebp@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // ecx@1
	int v9; // edi@1
	int v10; // eax@1
	int v11; // ebx@3
	int v12; // edx@5
	int v13; // esi@8
	int v14; // edx@12
	int result; // eax@16
	int v16; // [sp+18h] [bp-4h]@1

	v4 = a1->sprite;
	v5 = sprite_width;
	v6 = v4->x;
	v7 = v4->y;
	v8 = sprite_width - v6;
	v9 = sprite_height - v7;
	v16 = v6;
	v10 = sprite_width - v6;
	if (v10 <= 0)
		v10 = -v10;
	v11 = sprite_height - v7;
	if (v9 <= 0)
		v11 = -v9;
	v12 = a4;
	if (v10 > a4)
		goto LABEL_22;
	if (v11 <= a4)
		return -1;
	if (v10 >= a4)
	{
	LABEL_22:
		v13 = -1;
	}
	else
	{
		v12 = a4;
		v13 = v7 >= sprite_height ? 0 : 0x80;
	}
	if (v11 < v12)
		v13 = v16 >= v5 ? 192 : 64;
	v14 = v10 - v11;
	if (v10 - v11 <= 0)
		v14 = v11 - v10;
	if (v14 >= a4)
		return v13;
	if (v8 <= 0)
		result = v9 <= 0 ? 224 : 160;
	else
		result = v9 <= 0 ? 32 : 96;
	return result;
}

//----- (0040D6F0) --------------------------------------------------------
int entity_40D6F0_vehicle_get_new_movement_orientation(
    Entity *a1, int x, int y, int range
)
{
	int result; // eax@8
	int v13; // ecx@12
	int v15; // edx@18
	int v18; // ecx@25
	int v19; // eax@30

    int dx = x - a1->sprite->x;
	int dy = y - a1->sprite->y;
	int dx_abs = abs(dx);
	int dy_abs = abs(dy);
	if (dx_abs <= range && dy_abs <= range)
		return -1;

    if (dx_abs >= range) {
        result = -1;
    }
	else
		result = a1->sprite->y >= y ? ORIENTATION_N : ORIENTATION_S;

	if (dy_abs < range)
	{
		result = a1->sprite->x >= x ? ORIENTATION_W : ORIENTATION_E;
	}

	v13 = abs(dx_abs - dy_abs);
	if (v13 < range)
	{
		if (dx <= 0) {
            result = dy <= 0 ? ORIENTATION_NW : ORIENTATION_SW;
		} else {
			result = dy <= 0 ? ORIENTATION_NE : ORIENTATION_SE;
		}
	}

	v15 = abs(618 * dx_abs / 256 - dy_abs);
	if (v15 < range)
	{
		if (dx <= 0) {
            result = dy <= 0 ? ORIENTATION_NNW : ORIENTATION_SSW;
		} else {
			result = dy <= 0 ? ORIENTATION_NNE : ORIENTATION_SSE;
		}
	}

    v18 = abs(618 * dy_abs / 256 - dx_abs);
	if (v18 < range)
	{
		if (dx <= 0) {
            result = dy <= 0 ? 208 : 208 - 32;
		} else {
			result = dy <= 0 ? 48 : 80;
		}
	}
	return result;
}

//----- (0040D860) --------------------------------------------------------
bool _40D860_prolly_sprite_distance(Sprite *a1, Sprite *a2, int a3)
{
	int v3; // esi@1

	a2->field_88_unused = 1;
	v3 = a1->x;
	a1->field_88_unused = 1;
	return ((a2->y - a1->y) >> 8) * ((a2->y - a1->y) >> 8) + ((a2->x - v3) >> 8) * ((a2->x - v3) >> 8) <= a3 * a3;
}

//----- (0040D8B0) --------------------------------------------------------
int sprite_40D8B0_dmg(Sprite *a1, int a2)
{
	int v2; // ebp@1
	Sprite *v3; // esi@1
	int v4; // ebx@1
	int v5; // edx@1
	int v6; // ecx@1
	int result; // eax@1
	int v8; // edi@1
	int v9; // edx@5
	int v10; // edi@9
	DataBoxd_stru0_per_map_unit *v11; // eax@9
	Entity **v12; // ebx@10
	Entity **v13; // edi@12
	Sprite *v14; // ecx@14
	int v15; // edx@14
	int v16; // eax@14
	int v17; // ecx@14
	Entity *v18; // edx@15
	int v19; // eax@17
	Entity **v20; // ecx@18
	bool v21; // sf@25
	unsigned __int8 v22; // of@25
	int v23; // [sp+10h] [bp-28h]@1
	int v24; // [sp+14h] [bp-24h]@1
	int v25; // [sp+18h] [bp-20h]@5
	int v26; // [sp+1Ch] [bp-1Ch]@1
	int v27; // [sp+20h] [bp-18h]@1
	int v28; // [sp+24h] [bp-14h]@12
	int v29; // [sp+28h] [bp-10h]@9
	Entity **v30; // [sp+2Ch] [bp-Ch]@10
	int v31; // [sp+30h] [bp-8h]@9
	int v32; // [sp+34h] [bp-4h]@5

	v2 = a2;
	v3 = a1;
	v4 = (a2 >> 4) + 1;
	v5 = a2 >> 5;
	v6 = (a1->x >> 13) - v5;
	result = (v3->y >> 13) - v5;
	v27 = v2;
	v23 = 0;
	v26 = v4;
	v8 = v4;
	v24 = v6;
	if (v6 < 0)
	{
		v4 += v6;
		v24 = 0;
		v6 = 0;
		v26 = v4;
	}
	if (result < 0)
	{
		v8 += result;
		result = 0;
	}
	v9 = result;
	v25 = result;
	v32 = result + v8;
	if (result < result + v8)
	{
		while (v9 < map_get_height())
		{
			v10 = v6;
			v29 = v6;
			v11 = boxd_get_tile(v6, v9);
			v31 = v4 + v6;
			if (v6 < v4 + v6)
			{
				v12 = v11->_4_entities;
				v30 = v11->_4_entities;
				do
				{
					if (v10 >= map_get_width())
						break;
					v28 = 0;
					v13 = &dword_478108[v23];
					do
					{
						if (*v12)
						{
							v14 = (*v12)->sprite;
							v14->field_88_unused = 1;
							v15 = v3->x;
							v3->field_88_unused = 1;
							v16 = v14->x;
							v17 = (v14->y - v3->y) >> 8;
							if (v17 * v17 + ((v16 - v15) >> 8) * ((v16 - v15) >> 8) <= v2 * v2)
							{
								v18 = *v12;
								if (!(*v12)->destroyed)
								{
									if (v18->script)
									{
										v19 = 0;
										if ((int)v13 > (int)dword_478108)
										{
											v20 = dword_478108;
											do
											{
												if (*v20 == v18)
													break;
												++v19;
												++v20;
											} while (v19 < v23);
										}
										if (v19 >= v23)
										{
											result = script_trigger_event(v3->script, CMD_APPLY_DAMAGE, v3, v18->script);
											*v13 = *v12;
											++v13;
											++v23;
											if ((int *)v13 == &j_render_nullsub_2)
												return result;
										}
									}
									v2 = v27;
								}
							}
							v6 = v24;
						}
						++v12;
						v22 = __OFSUB__(v28 + 1, 5);
						v21 = v28++ - 4 < 0;
					} while (v21 ^ v22);
					v10 = v29 + 1;
					v12 = v30 + 6;
					v22 = __OFSUB__(v29 + 1, v31);
					v21 = v29++ + 1 - v31 < 0;
					v30 += 6;
				} while (v21 ^ v22);
			}
			result = v25++ + 1;
			if (v25 >= v32)
				break;
			v4 = v26;
			v9 = v25;
		}
	}
	return result;
}

//----- (0040DA90) --------------------------------------------------------
int map_40DA90_move_entity(Entity *a1)
{
	Entity *v1; // edi@1
	Sprite *v2; // eax@1
	int v5; // esi@2
	int v6; // ebx@2
	int v7; // ebp@2
	int v8; // eax@2
	int v9; // esi@2
	int v10; // ebx@2
	int result; // eax@7
	int v12; // esi@7
	int v15; // ebp@11
	int i; // [sp+10h] [bp-8h]@2
	int v17; // [sp+14h] [bp-4h]@2

	v1 = a1;
	v2 = a1->sprite;
    if (entity_is_xl_vehicle(a1))
    {
        v5 = v2->x - 4096;
        v6 = v2->x + 4096;
        v7 = (v2->y - 4096) >> 13;
        v8 = (v2->y + 4096) >> 13;
        v9 = v5 >> 13;
        v10 = v6 >> 13;
        v17 = v9;
        for (i = (v2->y + 4096) >> 13; v7 <= v8; ++v7)
        {
            if (v9 <= v10)
            {
                do
                    boxd_40F160(v1, v9++, v7, 0);
                while (v9 <= v10);
                v8 = i;
                v9 = v17;
            }
        }
        result = Map_40E1B0_place_xl_entity(
            v1,
            v1->sprite->x_speed + v1->sprite->x,
            v1->sprite->y + v1->sprite->y_speed,
            1);
        v12 = result;
        if (result != 4)
        {
            Map_40E1B0_place_xl_entity(v1, v1->sprite->x, v1->sprite->y, 1);
            result = v12;
        }
        return result;
    }
    else
	{
		int new_map_x = global2map(v2->x + v2->x_speed);
        int new_map_y = global2map(v2->y + v2->y_speed);
		if (new_map_x != a1->sprite_map_x || new_map_y != a1->sprite_map_y)
		{
			v15 = Map_40EEB0_place_entity(a1, new_map_x, new_map_y, 1);
			if (v15 == 5)
				return boxd_40EA50_classify_tile_objects(v1, new_map_x, new_map_y, boxd_get_tile(new_map_x, new_map_y));
			boxd_40F160(v1, v1->sprite_map_x, v1->sprite_map_y, v1->_A4_idx_in_tile);
			v1->_A4_idx_in_tile = v15;
			v1->sprite_map_x = new_map_x;
			v1->sprite_map_y = new_map_y;
		}
		return 4;
	}
}

//----- (0040E3E0) --------------------------------------------------------
char *get_resource_res_subfolder()
{
	char *result; // eax@1

	result = _465650_display_modes[1].name;
	//if (_478AA0_game_width >= 640)
		result = _465650_display_modes[2].name;
	return result;
}

//----- (0040F160) --------------------------------------------------------
int boxd_40F160(Entity *a1, int map_x, int map_y, int a4)
{
	int result; // eax@1
	enum UNIT_ID v5; // edx@6
	char v6; // bl@9
	char v7; // cl@12

	result = (int) & _478AA8_boxd_stru0_array[map_x + map_get_width() * map_y].flags;
	if (map_x >= 0 && map_x < map_get_width() && map_y >= 0 && map_y < map_get_height())
	{
		if (!a1->stats->speed || (v5 = a1->unit_id, v5 == UNIT_STATS_SURV_OUTPOST) || v5 == UNIT_STATS_MUTE_CLANHALL)// 58 -> Outpost, 59 -> Clanhall
			*(_BYTE *)(result + 1) &= 0xBFu;
		v6 = *(_BYTE *)result;
		if (*(_BYTE *)result & 0x80)
		{
			if (!a4 && *(Entity **)(result + 4) == a1)
			{
				v7 = *(_BYTE *)(result + 1) & 0xE0;
				*(_BYTE *)result = v6 & 0x20;
				*(_BYTE *)(result + 1) = v7;
				*(_DWORD *)(result + 4) = 0;
			}
		}
		else if (a1->stats->is_infantry && (1 << a4) & v6)
		{
			*(_BYTE *)result = v6 - (1 << a4);
			*(_BYTE *)(result + 1) &= ~(1 << a4);
			*(_DWORD *)(result + 4 * a4 + 4) = 0;
		}
	}
	return result;
}

//----- (0040F230) --------------------------------------------------------
void Map_40F230_update_tile(Entity *a1, int map_x, int map_y, int slot, int a5)
{
    DataBoxd_stru0_per_map_unit *tile = boxd_get_tile(map_x, map_y);

	if (map_x >= 0 && map_x < map_get_width() && map_y >= 0 && map_y < map_get_height())
	{
		if (tile->IsVehicleOrBuilding())
		{
			if (slot == 0 && tile->_4_entities[0] == a1)
			{
				if (a5)
					tile->flags2 |= BOXD_STRU0_ALL_SLOTS;
				else
					tile->flags2 &= ~BOXD_STRU0_ALL_SLOTS;
			}
		}
		else if (a1->IsInfantry() && tile->flags & BOXD_STRU0_TILE_SLOT(slot))
		{
			if (a5)
                tile->flags2 |= BOXD_STRU0_TILE_SLOT(slot);
			else
                tile->flags2 &= ~BOXD_STRU0_TILE_SLOT(slot);
		}
	}
}

//----- (0040F460) --------------------------------------------------------
void script_sidebar(Script *a1)
{
	while (1)
	{
		while (!(script_yield(a1, 1, 0) & 1))
			;
		script_terminate(a1);
	}
}

//----- (004103C0) --------------------------------------------------------
bool stru2_list_alloc(const int num_stru2s)
{
	if (stru2_list = new stru2[num_stru2s])
	{
		for (int i = 0; i < num_stru2s - 1; ++i) {
            stru2_list[i].next = stru2_list + i + 1;
		}

        stru2_list_free_pool = stru2_list;
        stru2_list[0].prev = (stru2 *)&stru2_list_free_pool;
        stru2_list[num_stru2s - 1].next = (stru2 *)&stru2_list_free_pool;

		stru2_list_4795DC = (stru2 *)&stru2_list_4795D8;
		stru2_list_4795D8 = (stru2 *)&stru2_list_4795D8;
        return true;
	}
    return false;
}

//----- (00410410) --------------------------------------------------------
stru2 *stru2_list_create(int hunk)
{
	stru2 *result; // eax@1
	stru3 *v2; // edx@4
	int v3; // eax@5

	result = stru2_list_4795D8;
	if ((stru2 **)stru2_list_4795D8 == &stru2_list_4795D8)
	{
	LABEL_4:
		v2 = stru3s;
		if (stru3s[0].magic == hunk)
		{
		LABEL_7:
			result = stru2_list_free_pool;
			if ((stru2 **)stru2_list_free_pool != &stru2_list_free_pool)
			{
				stru2_list_free_pool = stru2_list_free_pool->next;
				result->next = (stru2 *)&stru2_list_4795D8;
				result->prev = stru2_list_4795DC;
				stru2_list_4795DC->next = result;
				stru2_list_4795DC = result;
				result->hunk = hunk;
				result->init_handler = v2->init_handler;
				result->draw_handler = (int(*)(void *, int))v2->draw_handler;
				result->deinit_handler = v2->deinit_handler;
				return result;
			}
		}
		else
		{
			while (1)
			{
				v3 = v2->magic;
				++v2;
				if (!v3)
					break;
				if (v2->magic == hunk)
					goto LABEL_7;
			}
		}
		return 0;
	}
	while (result->hunk != hunk)
	{
		result = result->next;
		if ((stru2 **)result == &stru2_list_4795D8)
			goto LABEL_4;
	}
	return result;
}
// 4657D0: using guessed type stru3 stru3s[2];

//----- (004104A0) --------------------------------------------------------
int stru2_list_init_elements()
{
	stru2 *v0; // esi@1
	int(*init_handler)(void); // eax@2
	int result; // eax@5

	v0 = stru2_list_4795D8;
	if ((stru2 **)stru2_list_4795D8 == &stru2_list_4795D8)
	{
		result = 1;
	}
	else
	{
		while (1)
		{
			init_handler = (int(*)(void))v0->init_handler;
			if (init_handler)
			{
				if (!init_handler())
					break;
			}
			v0 = v0->next;
			if ((stru2 **)v0 == &stru2_list_4795D8)
				return 1;
		}
		result = 0;
	}
	return result;
}

//----- (004104E0) --------------------------------------------------------
void stru2_list_remove_elements()
{
	stru2 *i; // esi@1
	void(*v1)(void); // eax@2

	for (i = stru2_list_4795D8; (stru2 **)i != &stru2_list_4795D8; i = i->next)
	{
		v1 = (void(*)(void))i->deinit_handler;
		if (v1)
			v1();
	}
}

//----- (00410510) --------------------------------------------------------
void stru2_list_free()
{
	free(stru2_list);
}

//----- (00410520) --------------------------------------------------------
void entity_410520_update_healthbar_color(Entity *a1)
{
	int v1; // ebx@1
	EntityBuildingState *v2; // esi@1
	EntityBuildingAttachment_stru14_stru0 *v3; // edx@2
	char *v4; // edi@2
	char *v5; // edi@2
	char *v6; // edi@2
	EntityBuildingAttachment_stru14_stru0 *v7; // edi@2
	char *v8; // esi@2
	unsigned int v9; // ebp@2
	int v10; // ST10_4@2
	int v11; // eax@2
	int v12; // edx@2
	int v13; // eax@2
	int v14; // eax@2

	HIWORD_HEXRAYS(v1) = HIWORD_HEXRAYS(a1);
	v2 = (EntityBuildingState *)a1->state;
	if (v2)
	{
		v3 = v2->pstru14->_8F_healthbar;
		memset(v3, 0xA6u, 0x38u);                   // INLINED memset
		v4 = &v3->field_0.field_0[56];
		*(_WORD *)v4 = 0xA6A6u;
		v4[2] = 0xA6u;
		++v3;
		memset(v3, 0xA0u, 0x38u);
		v5 = &v3->field_0.field_0[56];
		*(_WORD *)v5 = 0xA0A0u;
		v5[2] = 0xA0u;
		memset(&v3[1], 0xA0u, 0x38u);
		v6 = &v3[1].field_0.field_0[56];
		*(_WORD *)v6 = 0xA0A0u;
		v6[2] = 0xA0u;
		v7 = v2->pstru14->_8F_healthbar;
		v8 = v2->pstru14->_8F_healthbar[1].field_0.field_0;
		v9 = 59 * a1->hitpoints / a1->stats->hitpoints;
		v10 = (int)(4 * v9) / 59;
		LOBYTE_HEXRAYS(v1) = _4657F0_tanker_status_color_breakpoints[v10];
		BYTE1(v1) = _4657F0_tanker_status_color_breakpoints[v10];
		v11 = v1 << 16;
		LOWORD_HEXRAYS(v11) = v1;
		memset32(v7, v11, v9 >> 2);
		v12 = (int)(4 * v9) / 59;
		memset((char *)v7 + 4 * (v9 >> 2), v1, v9 & 3);
		LOBYTE_HEXRAYS(v1) = _4657F8_tanker_status_color_breakpoints[v12];
		BYTE1(v1) = _4657F8_tanker_status_color_breakpoints[v12];
		v13 = v1 << 16;
		LOWORD_HEXRAYS(v13) = v1;
		memset32(v8, v13, v9 >> 2);
		memset(&v8[4 * (v9 >> 2)], v1, v9 & 3);
		LOBYTE_HEXRAYS(v1) = _4657F8_tanker_status_color_breakpoints[v10];
		BYTE1(v1) = _4657F8_tanker_status_color_breakpoints[v10];
		v14 = v1 << 16;
		LOWORD_HEXRAYS(v14) = v1;
		memset32(v8 + 66, v14, v9 >> 2);
		memset(&v8[4 * (v9 >> 2) + 66], v1, v9 & 3);
	}
}

//----- (00410640) --------------------------------------------------------
__int16 entity_410640_tanker_status_bar(Entity *a1)
{
	Entity *v1; // ebx@1
	EntityOilTankerState *v2; // esi@1
	char *v3; // edx@1
	char *v4; // esi@1
	unsigned int v5; // ebp@1
	unsigned int v6; // ecx@1
	int v7; // ST10_4@1
	int v8; // eax@1
	int v9; // eax@1

	v1 = a1;
	v2 = (EntityOilTankerState *)a1->state;
	v3 = v2->pstru70->field_4B;
	memset(v3, 0xA6u, 0x1Cu);
	memset(v3 + 32, 0xA0u, 0x1Cu);
	v4 = v2->pstru70->field_4B;
	v5 = 28 * v1->hitpoints / v1->stats->hitpoints;
	v6 = 28 * v1->hitpoints / v1->stats->hitpoints;
	v7 = (int)(4 * v5) / 28;
	LOBYTE_HEXRAYS(v3) = v5;
	LOBYTE_HEXRAYS(v1) = _4657F0_tanker_status_color_breakpoints[v7];
	BYTE1(v1) = _4657F0_tanker_status_color_breakpoints[v7];
	v8 = (_DWORD)v1 << 16;
	LOWORD_HEXRAYS(v8) = (_WORD)v1;
	v6 >>= 2;
	memset32(v4, v8, v6);
	memset(&v4[4 * v6], (char)v1, (unsigned __int8)v3 & 3);
	LOBYTE_HEXRAYS(v1) = _4657F8_tanker_status_color_breakpoints[v7];
	BYTE1(v1) = _4657F8_tanker_status_color_breakpoints[v7];
	v9 = (_DWORD)v1 << 16;
	LOWORD_HEXRAYS(v9) = (_WORD)v1;
	memset32(v4 + 32, v9, v5 >> 2);
	memset(&v4[4 * (v5 >> 2) + 32], (char)v1, v5 & 3);
	return v9;
}

//----- (00410710) --------------------------------------------------------
int entity_410710_status_bar(Entity *a1)
{
	int v1; // esi@1
	enum UNIT_ID v2; // eax@3
	int v3; // eax@5
	int result; // eax@9
	int v5; // eax@10

	v1 = 2;
	if (a1->veterancy_level <= 2)
		v1 = a1->veterancy_level;
	v2 = a1->unit_id;
	if ((int)v2 > (int)UNIT_STATS_SURV_SCOUT || (v2 & 0x80000000) != 0)
	{
		v5 = 28 * a1->hitpoints / a1->stats->hitpoints;
		if (v5 < 0)
			v5 = 0;
		if (v5 > 27)
			v5 = 27;
		result = v5 + 28 * v1;
		a1->_28C_stru26_stru0__or__stru27_stru0__or__EntityBuildingAttachment_stru14__or__EntityOilTankerAttachment_stru70 = _4795F0_stru26_array[0].data[result];
	}
	else
	{
		v3 = 12 * a1->hitpoints / a1->stats->hitpoints;
		if (v3 < 0)
			v3 = 0;
		if (v3 > 11)
			v3 = 11;
		result = v3 + 12 * v1;
		a1->_28C_stru26_stru0__or__stru27_stru0__or__EntityBuildingAttachment_stru14__or__EntityOilTankerAttachment_stru70 = _479740_stru27_array[0].data[result];
	}
	return result;
}

//----- (004107B0) --------------------------------------------------------
void entity_4107B0_oiltanker_oil_bar(Entity *a1)
{
	EntityOilTankerState *v1; // ebx@1
	char *v2; // edx@1
	char *v3; // esi@1
	int v4; // edx@1

	v1 = (EntityOilTankerState *)a1->state;
	v2 = v1->pstru70->array_AB;
	memset(v2, 0xA6u, 0x1Cu);
	memset(v2 + 32, 0xA0u, 0x1Cu);
	v3 = v1->pstru70->array_AB;
	v4 = 28 * v1->_0_oil_loaded / 500;
	memset(v3, 0xAAu, v4);
	memset(v3 + 32, 0xA9u, v4);
}

//----- (00410840) --------------------------------------------------------
void entity_update_sabotage_bar(Entity *a1)
{
	EntityBuildingState *v1; // eax@1
	int v2; // edi@1
	EntityBuildingAttachment_stru14_stru1 *v3; // esi@1
	EntityBuildingAttachment_stru14_stru1 *v4; // ecx@1
	EntityBuildingAttachment_stru14_stru1 *v5; // ebx@2
	char *v6; // esi@3
	int v7; // edi@3
	char *v8; // ecx@3
	char *v9; // ebx@4
	int v10; // ecx@5
	int v11; // esi@5
	int v12; // edi@6
	__int16 v13; // dx@7
	int v14; // ecx@8
	EntityBuildingAttachment_stru14_stru1 *v15; // esi@8
	EntityBuildingAttachment_stru14_stru1 *v16; // edi@9
	EntityBuildingAttachment_stru14_stru1 *v17; // ebx@10
	int v18; // ecx@11
	char *v19; // esi@11
	char *v20; // edi@12
	char *v21; // ebx@13
	int v22; // ecx@14
	int v23; // esi@14
	int v24; // edi@15

	v1 = (EntityBuildingState *)a1->state;
	v2 = 5;
	v3 = v1->pstru14->field_197;
	v4 = v1->pstru14->field_197;
	do
	{
		v5 = v4;
		++v4;
		--v2;
		*(_DWORD *)&v5->field_0[0] = 0xA6A6A6A6;
		*(_DWORD *)&v5->field_0[4] = 0xA6A6A6A6;
		*(_WORD *)&v5->field_0[8] = 0xA6A6u;
		v5->field_0[10] = 0xA6u;
	} while (v2);
	v6 = &v3[5].field_0[6];
	v7 = 5;
	v8 = v6;
	do
	{
		v9 = v8;
		v8 += 12;
		--v7;
		*(_DWORD *)v9 = 0xA0A0A0A0;
		*((_DWORD *)v9 + 1) = 0xA0A0A0A0;
		*((_WORD *)v9 + 4) = 0xA0A0u;
		v9[10] = 0xA0u;
	} while (v7);
	v10 = (int)(v6 + 66);
	v11 = 5;
	do
	{
		v12 = v10;
		v10 += 12;
		--v11;
		*(_DWORD *)v12 = 0xA0A0A0A0;
		*(_DWORD *)(v12 + 4) = 0xA0A0A0A0;
		*(_WORD *)(v12 + 8) = 0xA0A0u;
		*(_BYTE *)(v12 + 10) = 0xA0u;
	} while (v11);
	v13 = v1->sabotage_points;
	if (v13 <= 5)
	{
		v14 = 0;
		v15 = v1->pstru14->field_197;
		if (v13)
		{
			v16 = v1->pstru14->field_197;
			do
			{
				v17 = v16;
				++v14;
				++v16;
				*(_DWORD *)&v17->field_0[0] = 0x92929292;
				*(_DWORD *)&v17->field_0[4] = 0x92929292;
				*(_WORD *)&v17->field_0[8] = 0x9292u;
				v17->field_0[10] = 0x92u;
			} while (v14 != v1->sabotage_points);
		}
		v18 = 0;
		v19 = &v15[5].field_0[6];
		if (v1->sabotage_points)
		{
			v20 = v19;
			do
			{
				v21 = v20;
				++v18;
				v20 += 12;
				*(_DWORD *)v21 = 0x91919191;
				*((_DWORD *)v21 + 1) = 0x91919191;
				*((_WORD *)v21 + 4) = 0x9191u;
				v21[10] = 0x91u;
			} while (v18 != v1->sabotage_points);
		}
		v22 = 0;
		v23 = (int)(v19 + 66);
		if (v1->sabotage_points)
		{
			do
			{
				v24 = v23;
				++v22;
				v23 += 12;
				*(_DWORD *)v24 = 0x91919191;
				*(_DWORD *)(v24 + 4) = 0x91919191;
				*(_WORD *)(v24 + 8) = 0x9191u;
				*(_BYTE *)(v24 + 10) = 0x91u;
			} while (v22 != v1->sabotage_points);
		}
	}
}

//----- (00410950) --------------------------------------------------------
void entity_410950(Entity *a1, int a2)
{
	_DWORD *v2; // eax@2
	int v3; // ecx@2
	int v4; // eax@5
	int v5; // esi@5
	__int16 v6; // cx@6

	if (a2)
	{
		v4 = *((_DWORD *)a1->state + 5) + 203;      // param -> EntityBuildingAttachment
													// result = &a1->param->pstru14->_8F_healthbarr[0].field_3C;
		v5 = 11;
		do
		{
			LOBYTE_HEXRAYS(v6) = a2;
			v4 += 66;
			HIBYTE_HEXRAYS(v6) = a2;
			--v5;
			*(_WORD *)(v4 - 66) = v6;
		} while (v5);
	}
	else
	{
		v2 = (_DWORD *)(*((_DWORD *)a1->state + 5) + 71);// param -> EntityBuildingAttachment
														 // result = &a1->param->pstru14->field_10[55];
		v3 = 15;
		do
		{
			*v2 = 0;
			*(_BYTE *)v2 = 0xA4u;
			v2 = (_DWORD *)((char *)v2 + 66);
			--v3;
		} while (v3);
	}
}

//----- (004109A0) --------------------------------------------------------
void entity_4109A0_status_bar(Entity *a1)
{
	EntityBuildingState *v1; // eax@1
	enum UNIT_ID v2; // edx@1
	EntityBuildingAttachment_stru14_stru1 *v3; // edi@4
	int v4; // esi@4
	EntityBuildingAttachment_stru14_stru1 *v5; // edx@4
	EntityBuildingAttachment_stru14_stru1 *v6; // ebx@5
	EntityBuildingAttachment_stru14_stru1 *v7; // edi@6
	int v8; // esi@6
	EntityBuildingAttachment_stru14_stru1 *v9; // edx@6
	EntityBuildingAttachment_stru14_stru1 *v10; // ebx@7
	int v11; // esi@8
	char *v12; // ecx@8
	char *v13; // edi@9
	EntityBuildingAttachment_stru14_stru1 *v14; // esi@10
	int v15; // ecx@10
	EntityBuildingAttachment_stru14_stru1 *v16; // edi@11
	EntityBuildingAttachment_stru14_stru1 *v17; // ebx@12
	EntityBuildingAttachment_stru14_stru1 *v18; // esi@13
	int v19; // ecx@13
	EntityBuildingAttachment_stru14_stru1 *v20; // edi@14
	EntityBuildingAttachment_stru14_stru1 *v21; // ebx@15
	char *v22; // esi@16
	int v23; // ecx@16
	char *v24; // edi@17
	EntityBuildingAttachment_stru14_stru29D *v25; // edx@19
	EntityBuildingAttachment_stru14_stru29D *v26; // edi@19
	int v27; // edi@19

	v1 = (EntityBuildingState *)a1->state;
	v2 = a1->unit_id;
	if ((int)v2 >= (int)UNIT_STATS_SURV_RESEARCH_LAB
		|| (int)v2 <= (int)UNIT_STATS_MUTE_HOLDING_PENS
		|| a1->player_side != player_side)
	{
		v25 = &v1->pstru14->field_29D;
		v26 = &v1->pstru14->field_29D;
		memset(v26, 0, 0x148u);
		*(_WORD *)&v26->field_148 = 0;
		memset(v25, 0xA4u, 0x3Cu);
		v27 = (int)&v25->field_2[4].field_0[10];
		*(_WORD *)v27 = 0xA4A4u;
		*(_BYTE *)(v27 + 2) = 0xA4u;
	}
	else
	{
		v3 = v1->pstru14->field_29D.field_2;
		v4 = 5;
		v5 = v1->pstru14->field_29D.field_2;
		do
		{
			v6 = v5;
			++v5;
			--v4;
			*(_DWORD *)&v6->field_0[0] = 0xA6A6A6A6;
			*(_DWORD *)&v6->field_0[4] = 0xA6A6A6A6;
			*(_WORD *)&v6->field_0[8] = 0xA6A6u;
			v6->field_0[10] = 0xA6u;
		} while (v4);
		v7 = (EntityBuildingAttachment_stru14_stru1 *)((char *)v3 + 66);
		v8 = 5;
		v9 = v7;
		do
		{
			v10 = v9;
			++v9;
			--v8;
			*(_DWORD *)&v10->field_0[0] = 0xA0A0A0A0;
			*(_DWORD *)&v10->field_0[4] = 0xA0A0A0A0;
			*(_WORD *)&v10->field_0[8] = 0xA0A0u;
			v10->field_0[10] = 0xA0u;
		} while (v8);
		v11 = 5;
		v12 = &v7[5].field_0[6];
		do
		{
			v13 = v12;
			v12 += 12;
			--v11;
			*(_DWORD *)v13 = 0xA0A0A0A0;
			*((_DWORD *)v13 + 1) = 0xA0A0A0A0;
			*((_WORD *)v13 + 4) = 0xA0A0u;
			v13[10] = 0xA0u;
		} while (v11);
		v14 = v1->pstru14->field_29D.field_2;
		v15 = 0;
		if (v1->num_upgrades)
		{
			v16 = v1->pstru14->field_29D.field_2;
			do
			{
				v17 = v16;
				++v15;
				++v16;
				*(_DWORD *)&v17->field_0[0] = 0xAAAAAAAA;
				*(_DWORD *)&v17->field_0[4] = 0xAAAAAAAA;
				*(_WORD *)&v17->field_0[8] = 0xAAAAu;
				v17->field_0[10] = 0xAAu;
			} while (v15 != v1->num_upgrades);
		}
		v18 = (EntityBuildingAttachment_stru14_stru1 *)((char *)v14 + 66);
		v19 = 0;
		if (v1->num_upgrades)
		{
			v20 = v18;
			do
			{
				v21 = v20;
				++v19;
				++v20;
				*(_DWORD *)&v21->field_0[0] = 0xA9A9A9A9;
				*(_DWORD *)&v21->field_0[4] = 0xA9A9A9A9;
				*(_WORD *)&v21->field_0[8] = 0xA9A9u;
				v21->field_0[10] = 0xA9u;
			} while (v19 != v1->num_upgrades);
		}
		v22 = &v18[5].field_0[6];
		v23 = 0;
		if (v1->num_upgrades)
		{
			do
			{
				v24 = v22;
				++v23;
				v22 += 12;
				*(_DWORD *)v24 = 0xA9A9A9A9;
				*((_DWORD *)v24 + 1) = 0xA9A9A9A9;
				*((_WORD *)v24 + 4) = 0xA9A9u;
				v24[10] = 0xA9u;
			} while (v23 != v1->num_upgrades);
		}
	}
}

//----- (00410B00) --------------------------------------------------------
void entity_410B00_building_status_bar(Entity *a1)
{
	EntityBuildingState *v1; // esi@1
	int v2; // ebx@1
	int v3; // edi@1
	EntityBuildingAttachment_stru14_stru0 *v4; // edx@1
	int v5; // edi@1
	int v6; // edi@1
	EntityBuildingAttachment_stru14_stru1 *v7; // esi@1
	int v8; // ecx@2
	int v9; // edx@2
	char *v10; // edi@8
	char *v11; // esi@8

	v1 = (EntityBuildingState *)a1->state;
	v2 = (int)v1->oilspot_for_drillrig__task_for_researchlab;
	v3 = (int)v1->pstru14->field_29D.field_2;
	v4 = &v1->pstru14->field_29D.field_44;
	memset((void *)v3, 0xA6u, 0x38u);
	v3 += 56;
	*(_WORD *)v3 = 0xA6A6u;
	*(_BYTE *)(v3 + 2) = 0xA6u;
	memset(v4, 0xA0u, 0x38u);
	v5 = (int)&v4->field_0.field_0[56];
	*(_WORD *)v5 = 0xA0A0u;
	*(_BYTE *)(v5 + 2) = 0xA0u;
	memset(&v4[1], 0xA0u, 0x38u);
	v6 = (int)&v4[1].field_0.field_0[56];
	*(_WORD *)v6 = 0xA0A0u;
	*(_BYTE *)(v6 + 2) = 0xA0u;
	v7 = v1->pstru14->field_29D.field_2;
	if (v2)
	{
		v8 = *(_DWORD *)(v2 + 12);
		v9 = 59 * v8 / 100000;
		if (v9 < 1 && v8 > 0)
			v9 = 1;
	}
	else
	{
		v9 = 0;
	}
	if (v9 > 59)
		v9 = 59;
	memset(v7, 0xAAu, 4 * ((unsigned int)v9 >> 2));
	v10 = &v7->field_0[4 * ((unsigned int)v9 >> 2)];
	v11 = &v7[5].field_0[6];
	memset(v10, -86, v9 & 3);
	memset(v11, 0xA9u, v9);
	memset(v11 + 66, 0xA9u, v9);
}

//----- (00410BE0) --------------------------------------------------------
void entity_410BE0_status_bar(Entity *a1)
{
	Entity *v1; // esi@1
	int v2; // edx@1
	int v3; // edi@1
	int v4; // edx@1
	int v5; // eax@1
	int v6; // eax@3
	int v7; // ecx@6
	_WORD *v8; // eax@6
	int v9; // ecx@9
	_DWORD *v10; // eax@9
	enum UNIT_ID v11; // eax@11

	v1 = a1;
	v2 = *((_DWORD *)a1->state + 5) + 9;          // state -> EntityBuildingState
												  // v2 = (int)&a1->state->pstru14->field_8 + 1;
	memset((void *)v2, 1u, 0x3DCu);
	*(_WORD *)(v2 + 988) = 257;
	memset((void *)v2, 0xA6u, 0x40u);
	*(_WORD *)(v2 + 64) = 0xA6A6u;
	v3 = v2 + 924;
	v4 = v2 + 66;
	memset((void *)v3, 0xA4u, 0x40u);
	*(_WORD *)(v3 + 64) = 0xA4A4u;
	v5 = 13;
	do
	{
		*(_BYTE *)v4 = 0xA6u;
		*(_BYTE *)(v4 + 65) = 0xA4u;
		v4 += 66;
		--v5;
	} while (v5);
	entity_update_sabotage_bar(a1);
	entity_410520_update_healthbar_color(v1);
	v6 = v1->unit_id;
	if (v6 >= (int)UNIT_STATS_SURV_REPAIR_BAY
		|| v6 <= (int)UNIT_STATS_MUTE_HOLDING_PENS
		|| v1->player_side != player_side)
	{
		v9 = 15;
		v10 = (_DWORD *)(*((_DWORD *)v1->state + 5) + 71);
		do
		{
			*v10 = 0;
			*(_BYTE *)v10 = 0xA4u;
			v10 = (_DWORD *)((char *)v10 + 66);
			--v9;
		} while (v9);
	}
	else
	{
		v7 = 11;
		v8 = (_WORD *)(*((_DWORD *)v1->state + 5) + 203);
		do
		{
			*v8 = 257;
			v8 += 33;
			--v7;
		} while (v7);
	}
	v11 = v1->unit_id;
	if (v11 != UNIT_STATS_SURV_DRILL_RIG && v11 != UNIT_STATS_MUTE_DRILL_RIG)
		entity_4109A0_status_bar(v1);
}

//----- (00410CB0) --------------------------------------------------------
void entity_selected_default(Entity *a1)
{
	DrawJob *v1; // eax@1

	v1 = a1->drawjob;
	if (v1)
		v1->flags &= 0xBFFFFFFF;
}

//----- (00410CD0) --------------------------------------------------------
void entity_deselected_default(Entity *a1)
{
	DrawJob *v1; // eax@1

	v1 = a1->drawjob;
	if (v1)
		v1->flags |= 0x40000000u;
}

//----- (00410CF0) --------------------------------------------------------
void entity_410CF0_aircraft(Entity *a1)
{
	Entity *v1; // esi@1
	Sprite *v2; // ecx@1

	v1 = a1;
	v2 = a1->sprite;
	v1->field_288 = 0;
	v1->pfn_render_DrawUnitsAndUi = render_sprt_draw_handler;
	v1->_28C_stru26_stru0__or__stru27_stru0__or__EntityBuildingAttachment_stru14__or__EntityOilTankerAttachment_stru70 = _4795F0_stru26_array[0].data[27];
	v1->drawjob = draw_list_add(v1, (DrawUpdateHandler)drawjob_update_draw_handler_aircraft);
	v1->drawjob->flags |= 0x40000000u;
}

//----- (00410D40) --------------------------------------------------------
void entity_set_draw_handlers(Entity *a1)
{
	Entity *v1; // esi@1
	enum UNIT_ID v2; // eax@1
	void(*v3)(Entity *, DrawJob *); // edx@3

	v1 = a1;
	v2 = a1->unit_id;
	a1->field_288 = 0;
	a1->pfn_render_DrawUnitsAndUi = render_sprt_draw_handler;
	if ((int)v2 > (int)UNIT_STATS_SURV_SCOUT || (v2 & 0x80000000) != 0)
	{
		v3 = drawjob_update_handler_4487B0_vehicles_buildings;
		a1->_28C_stru26_stru0__or__stru27_stru0__or__EntityBuildingAttachment_stru14__or__EntityOilTankerAttachment_stru70 = _4795F0_stru26_array[0].data[27];
	}
	else
	{
		v3 = drawjob_update_handler_448750_infantry;
		a1->_28C_stru26_stru0__or__stru27_stru0__or__EntityBuildingAttachment_stru14__or__EntityOilTankerAttachment_stru70 = _479740_stru27_array[0].data[11];
	}

	v1->drawjob = draw_list_add(v1, (DrawUpdateHandler)v3);
	entity_410710_status_bar(v1);
	v1->drawjob->flags |= 0x40000000u;
}

//----- (00410DC0) --------------------------------------------------------
void entity_410DC0_building(Entity *a1)
{
	Entity *v1; // esi@1
	EntityBuildingState *v2; // edi@1
	EntityBuildingAttachment_stru14 *v3; // eax@1
	EntityBuildingAttachment_stru14 *v4; // eax@2

	v1 = a1;
	v2 = (EntityBuildingState *)a1->state;
	v3 = (EntityBuildingAttachment_stru14 *)script_create_local_object(a1->script, 1002);
	v2->pstru14 = v3;
	if (v3)
	{
		v3->field_0 = 66;
		v2->pstru14->field_4 = 15;
		LOBYTE_HEXRAYS(v2->pstru14->field_8) = 0;
		v4 = v2->pstru14;
		v1->field_288 = 0;
		v1->_28C_stru26_stru0__or__stru27_stru0__or__EntityBuildingAttachment_stru14__or__EntityOilTankerAttachment_stru70 = v4;
		v1->pfn_render_DrawUnitsAndUi = render_sprt_draw_handler;
		v1->drawjob = draw_list_add(v1, (DrawUpdateHandler)drawjob_update_handler_4486D0_building);
		entity_410BE0_status_bar(v1);
		v1->drawjob->flags |= 0x40000000u;
	}
}

//----- (00410E40) --------------------------------------------------------
void entity_oil_tanker_initialize_state(Entity *a1)
{
	Entity *v1; // esi@1
	EntityOilTankerState *v2; // edi@1
	EntityOilTankerAttachment_stru70 *v3; // eax@1
	EntityOilTankerAttachment_stru70 *v4; // eax@2
	void *v7; // edx@2
	void *v8; // edi@2
	int v9; // edx@2
	int v10; // eax@2
	EntityOilTankerState *v11; // ebp@4
	char *v12; // edx@4
	char *v13; // ebx@4
	int v14; // edx@4
	EntityOilTankerState *v15; // ebx@4
	char *v16; // edx@4
	char *v17; // ebp@4
	unsigned int v18; // ST10_4@4
	int v19; // ST14_4@4
	unsigned int v20; // edx@4
	int v21; // eax@4
	int v22; // eax@4

	v1 = a1;
	v2 = (EntityOilTankerState *)a1->state;
	v3 = (EntityOilTankerAttachment_stru70 *)script_create_local_object(a1->script, 300);
	v2->pstru70 = v3;
	if (v3)
	{
		v3->field_0 = 32;
		v2->pstru70->field_4 = 9;
		LOBYTE_HEXRAYS(v2->pstru70->field_8) = 0;
		v4 = v2->pstru70;
		v1->field_288 = 0;
		v1->_28C_stru26_stru0__or__stru27_stru0__or__EntityBuildingAttachment_stru14__or__EntityOilTankerAttachment_stru70 = v4;
		v1->pfn_render_DrawUnitsAndUi = render_sprt_draw_handler;
		v1->drawjob = draw_list_add(v1, (DrawUpdateHandler)drawjob_update_handler_oiltanker);
		v7 = (void *)(*((_DWORD *)v1->state + 28) + 9);
		memset(v7, 1u, 0x120u);
		memset(v7, 0xA6u, 0x20u);
		v8 = (char *)v7 + 256;
		v9 = (int)v7 + 32;
		memset(v8, 0xA4u, 0x20u);
		v10 = 7;
		do
		{
			*(_BYTE *)v9 = 0xA6u;
			*(_BYTE *)(v9 + 31) = 0xA4u;
			v9 += 32;
			--v10;
		} while (v10);
		v11 = (EntityOilTankerState *)v1->state;
		v12 = v11->pstru70->array_AB;
		memset(v12, 0xA6u, 0x1Cu);
		memset(v12 + 32, 0xA0u, 0x1Cu);
		v13 = v11->pstru70->array_AB;
		v14 = 28 * v11->_0_oil_loaded / 500;
		memset(v13, 0xAAu, v14);
		memset(v13 + 32, 0xA9u, v14);
		v15 = (EntityOilTankerState *)v1->state;
		v16 = v15->pstru70->field_4B;
		memset(v16, 0xA6u, 0x1Cu);
		memset(v16 + 32, 0xA0u, 0x1Cu);
		v17 = v15->pstru70->field_4B;
		v18 = 28 * v1->hitpoints / v1->stats->hitpoints;
		v19 = (int)(4 * v18) / 28;
		v20 = 28 * v1->hitpoints / v1->stats->hitpoints;
		LOBYTE_HEXRAYS(v15) = _4657F0_tanker_status_color_breakpoints[v19];
		BYTE1(v15) = _4657F0_tanker_status_color_breakpoints[v19];
		v21 = (_DWORD)v15 << 16;
		LOWORD_HEXRAYS(v21) = (_WORD)v15;
		memset32(v17, v21, v18 >> 2);
		memset(&v17[4 * (v18 >> 2)], (char)v15, v20 & 3);
		LOBYTE_HEXRAYS(v15) = _4657F8_tanker_status_color_breakpoints[v19];
		BYTE1(v15) = _4657F8_tanker_status_color_breakpoints[v19];
		v22 = (_DWORD)v15 << 16;
		LOWORD_HEXRAYS(v22) = (_WORD)v15;
		memset32(v17 + 32, v22, v20 >> 2);
		memset(&v17[4 * (v20 >> 2) + 32], (char)v15, v20 & 3);
		v1->drawjob->flags |= 0x40000000u;
	}
}

//----- (00411040) --------------------------------------------------------
bool stru27_array_initialize()
{
	int v0; // esi@1
	stru27_stru0 **v1; // ebp@1
	unsigned int v2; // ebx@2
	stru27_stru0 *v3; // eax@3
	char *v4; // edx@4
	unsigned __int16 v5; // cx@4
	int v6; // eax@4
	int v7; // ecx@4
	int v8; // edi@4
	int v9; // eax@4
	_BYTE *v10; // edx@4
	int v11; // edi@4
	_BYTE *v12; // edx@5
	int v13; // eax@7
	bool v14; // zf@7
	bool v15; // sf@7
	unsigned __int8 v16; // of@7
	int v17; // ebx@10
	char *v18; // ecx@10
	char *v19; // edi@10
	char *v20; // esi@10
	unsigned int v21; // ecx@10
	unsigned int v22; // edx@10
	int v23; // eax@10
	int v24; // eax@10
	char *v25; // edi@10
	int v27; // [sp+10h] [bp-18h]@2
	int v28; // [sp+14h] [bp-14h]@1
	unsigned __int8 v29; // [sp+18h] [bp-10h]@1
	char v30; // [sp+1Ch] [bp-Ch]@1
	stru27 *v31; // [sp+20h] [bp-8h]@1

	v0 = 0;
	v1 = (stru27_stru0 **)_479740_stru27_array;
	v29 = -1;
	v30 = -1;
	v28 = 0;
	v31 = _479740_stru27_array;
	while (2)
	{
		v2 = 0;
		v27 = 0;
		do
		{
			v3 = (stru27_stru0 *)malloc(0x6Cu);
			*v1 = v3;
			if (!v3)
				return 0;
			v3->field_0 = 16;
			(*v1)->field_4 = 6;
			(*v1)->field_8 = 0;
			v4 = (*v1)->array_9;
			memset(v4, 1u, 0x60u);
			LOBYTE_HEXRAYS(v5) = _465800_stru26_stru27_initializer[v0];
			HIBYTE_HEXRAYS(v5) = _465800_stru26_stru27_initializer[v0];
			v6 = v5 << 16;
			LOWORD_HEXRAYS(v6) = v5;
			v7 = (int)(v4 + 80);
			*(_DWORD *)v4 = v6;
			*((_DWORD *)v4 + 1) = v6;
			*((_DWORD *)v4 + 2) = v6;
			*((_DWORD *)v4 + 3) = v6;
			v8 = (int)(v4 + 80);
			LOBYTE_HEXRAYS(v7) = _465804_stru26_stru27_initializer[v0];
			BYTE1(v7) = _465804_stru26_stru27_initializer[v0];
			v9 = v7 << 16;
			LOWORD_HEXRAYS(v9) = v7;
			v10 = v4 + 16;
			*(_DWORD *)v8 = v9;
			*(_DWORD *)(v8 + 4) = v9;
			*(_DWORD *)(v8 + 8) = v9;
			*(_DWORD *)(v8 + 12) = v9;
			v11 = 4;
			do
			{
				*v10 = _465800_stru26_stru27_initializer[v0];
				v12 = v10 + 15;
				*v12 = _465804_stru26_stru27_initializer[v0];
				v10 = v12 + 1;
				--v11;
			} while (v11);
			if ((char)v2 % -2)
			{
				LOBYTE_HEXRAYS(v13) = v29;
			}
			else
			{
				v13 = _4657F0_tanker_status_color_breakpoints[v27];
				v29 = _4657F0_tanker_status_color_breakpoints[v27];
				v16 = __OFSUB__(v27 + 1, 4);
				v14 = v27 == 3;
				v15 = v27 - 3 < 0;
				v30 = _4657F8_tanker_status_color_breakpoints[v27++];
				if (!((unsigned __int8)(v15 ^ v16) | v14))
					v27 = 4;
			}
			v17 = v2 + 1;
			v18 = &(*v1)->array_9[34];
			v19 = &(*v1)->array_9[34];
			v20 = &(*v1)->array_9[50];
			*(_DWORD *)v18 = 0xA6A6A6A6;
			++v1;
			*((_DWORD *)v18 + 1) = 0xA6A6A6A6;
			*((_DWORD *)v18 + 2) = 0xA6A6A6A6;
			v21 = v17;
			LOBYTE_HEXRAYS(v17) = v13;
			v22 = v21;
			BYTE1(v17) = v13;
			v23 = v17 << 16;
			LOWORD_HEXRAYS(v23) = v17;
			v2 = v21;
			v21 >>= 2;
			memset32(v19, v23, v21);
			memset(&v19[4 * v21], v23, v22 & 3);
			*(_DWORD *)v20 = 0xA0A0A0A0;
			*((_DWORD *)v20 + 1) = 0xA0A0A0A0;
			*((_DWORD *)v20 + 2) = 0xA0A0A0A0;
			LOBYTE_HEXRAYS(v22) = v30;
			BYTE1(v22) = v30;
			v24 = v22 << 16;
			LOWORD_HEXRAYS(v24) = v22;
			memset32(v20, v24, v2 >> 2);
			v25 = &v20[4 * (v2 >> 2)];
			v0 = v28;
			memset(v25, v30, v2 & 3);
		} while (v2 != 12);
		v0 = v28 + 1;
		v1 = v31[1].data;
		++v28;
		++v31;
        if (v28 >= 3) {
            break;
        }
	}
	return 1;
}

//----- (00411200) --------------------------------------------------------
bool stru26_array_initialize()
{
	stru26_stru0 **v0; // ebp@1
	unsigned int v1; // ebx@2
	stru26_stru0 *v2; // eax@3
	int v3; // edx@4
	char *v4; // esi@4
	int v5; // eax@4
	void *v6; // edi@4
	int v7; // eax@4
	int v8; // esi@4
	int v9; // eax@4
	int v10; // edx@7
	bool v11; // zf@7
	bool v12; // sf@7
	unsigned __int8 v13; // of@7
	char *v14; // esi@10
	int v15; // ebx@10
	unsigned int v16; // ecx@10
	unsigned int v17; // edx@10
	char *v18; // edi@10
	int v19; // eax@10
	int v20; // eax@10
	int v22; // [sp+10h] [bp-18h]@1
	int v23; // [sp+14h] [bp-14h]@2
	unsigned __int8 v24; // [sp+18h] [bp-10h]@1
	char v25; // [sp+1Ch] [bp-Ch]@1
	stru26 *v26; // [sp+20h] [bp-8h]@1

	v0 = (stru26_stru0 **)_4795F0_stru26_array;
	v24 = -1;
	v25 = -1;
	v22 = 0;
	v26 = _4795F0_stru26_array;
	while (2)
	{
		v1 = 0;
		v23 = 0;
		do
		{
			v2 = (stru26_stru0 *)malloc(0xCCu);
			*v0 = v2;
			if (!v2)
				return 0;
			v2->field_0 = 32;
			HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(v22);
			(*v0)->field_4 = 6;
			(*v0)->field_8 = 0;
			v4 = (*v0)->array_9;
			memset(v4, 1u, 0xC0u);
			LOBYTE_HEXRAYS(v3) = _465800_stru26_stru27_initializer[v22];
			BYTE1(v3) = _465800_stru26_stru27_initializer[v22];
			v5 = v3 << 16;
			LOWORD_HEXRAYS(v5) = v3;
			HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(v22);
			memset32(v4, v5, 8u);
			v6 = v4 + 160;
			LOBYTE_HEXRAYS(v3) = _465804_stru26_stru27_initializer[v22];
			BYTE1(v3) = _465804_stru26_stru27_initializer[v22];
			v7 = v3 << 16;
			LOWORD_HEXRAYS(v7) = v3;
			v8 = (int)(v4 + 32);
			memset32(v6, v7, 8u);
			v9 = 4;
			do
			{
				v8 += 32;
				--v9;
				*(_BYTE *)(v8 - 32) = _465800_stru26_stru27_initializer[v22];
				*(_BYTE *)(v8 - 1) = _465804_stru26_stru27_initializer[v22];
			} while (v9);
			if ((int)v1 % 5)
			{
				LOBYTE_HEXRAYS(v10) = v24;
			}
			else
			{
				v10 = _4657F0_tanker_status_color_breakpoints[v23];
				v24 = _4657F0_tanker_status_color_breakpoints[v23];
				v13 = __OFSUB__(v23 + 1, 4);
				v11 = v23 == 3;
				v12 = v23 - 3 < 0;
				v25 = _4657F8_tanker_status_color_breakpoints[v23++];
				if (!((unsigned __int8)(v12 ^ v13) | v11))
					v23 = 4;
			}
			v14 = &(*v0)->array_9[66];
			v15 = v1 + 1;
			memset(v14, 0xA6u, 0x1Cu);
			v16 = v15;
			LOBYTE_HEXRAYS(v15) = v10;
			BYTE1(v15) = v10;
			v17 = v16;
			v18 = v14;
			v19 = v15 << 16;
			LOWORD_HEXRAYS(v19) = v15;
			v14 += 32;
			v16 >>= 2;
			memset32(v18, v19, v16);
			v1 = v17;
			++v0;
			memset(&v18[4 * v16], v19, v17 & 3);
			memset(v14, 0xA0u, 0x1Cu);
			LOBYTE_HEXRAYS(v17) = v25;
			BYTE1(v17) = v25;
			v20 = v17 << 16;
			LOWORD_HEXRAYS(v20) = v17;
			memset32(v14, v20, v1 >> 2);
			memset(&v14[4 * (v1 >> 2)], v25, v1 & 3);
		} while (v1 != 28);
		v0 = v26[1].data;
		v11 = (stru27 *)&v26[1] == _479740_stru27_array;
		++v22;
		++v26;
		if (!v11)
			continue;
		break;
	}
	return 1;
}

//----- (004113D0) --------------------------------------------------------
void stru26_stru27_free()
{
	stru27 *v0; // esi@1
	int v1; // edi@2
	stru26 *v2; // esi@5
	int v3; // edi@6

    int i = 0;
	v0 = _479740_stru27_array;
	do
	{
		v1 = 12;
		do
		{
			free(v0->data[0]);
			v0 = (stru27 *)((char *)v0 + 4);
			--v1;
		} while (v1);
	} while (++i < 3);

    i = 0;
	v2 = _4795F0_stru26_array;
	do
	{
		v3 = 28;
		do
		{
			free(v2->data[0]);
			v2 = (stru26 *)((char *)v2 + 4);
			--v3;
		} while (v3);
	} while (++i < 3);
}


//----- (0041A060) --------------------------------------------------------
void entity_41A060_evt1525(Entity *a1, void *param)
{
	auto v2 = (int *)param;

    int param_player_side = v2[0];
    int param_x = v2[1];
    int param_y = v2[2];

	if (a1->player_side == param_player_side
		&& (a1->GetOrder() != ENTITY_ORDER_9
			|| !map_is_same_tile(param_x, a1->sprite_x_2)
			|| !map_is_same_tile(param_y, a1->sprite_y_2)))
	{
        script_sleep(a1->script, 1);

		a1->SetOrder(ENTITY_ORDER_9);
        a1->_134_param__unitstats_after_mobile_outpost_plant = 600;
        a1->retaliation_target = 0;
        a1->_E4_prev_attack_target = 0;

        a1->sprite_x_2 = map_adjust_entity_in_tile_x(a1, param_x);
        a1->sprite_y_2 = map_adjust_entity_in_tile_y(a1, param_y);
        a1->entity_8 = 0;
		entity_mode_move_attack(a1);
	}
}

//----- (0041A170) --------------------------------------------------------
void entity_41A170_evt1524(Entity *a1, void *param)
{
    auto v2 = (int *)param;

    int param_player_side = v2[0];
    int param_x = v2[1];
    int param_y = v2[2];

	if (a1->player_side == param_player_side
		&& (a1->_DC_order != ENTITY_ORDER_MOVE
			|| !map_is_same_tile(param_x, a1->sprite_x_2)
			|| !map_is_same_tile(param_y, a1->sprite_y_2)))
	{
        script_sleep(a1->script, 1);

        a1->_DC_order = ENTITY_ORDER_MOVE;

        a1->sprite_x_2 = map_adjust_entity_in_tile_x(a1, param_x);
        a1->sprite_y_2 = map_adjust_entity_in_tile_y(a1, param_y);
        a1->entity_8 = 0;
        a1->SetMode(entity_mode_418F60);
	}
}

//----- (0041A400) --------------------------------------------------------
void entity_41A400_evt1547(Entity *a1, Entity *a2)
{
	Entity *v2; // esi@1
	Entity *v3; // edi@1

	v2 = a1;
	v3 = a2;
	if (a2 != a1->retaliation_target)
	{
        script_sleep(a1->script, 1);
		v2->_DC_order = ENTITY_ORDER_3;
		v2->retaliation_target = v3;
		v2->retaliation_target_id = v3->entity_id;
		v2->_E4_prev_attack_target = 0;
		v2->_134_param__unitstats_after_mobile_outpost_plant = 600;
		v2->mode_arrive = entity_mode_418B30;
		v2->entity_8 = 0;
		entity_mode_move_attack(v2);
	}
}

//----- (0041A470) --------------------------------------------------------
void entity_41A470_vehicle_repair_at_station(Entity *a1, Entity *a2)
{
	Entity *v2; // esi@1
	Entity *v3; // edi@1
	int v4; // edx@1
	int v5; // edi@1

	v2 = a1;
	v3 = a2;
    script_sleep(a1->script, 1);
	v2->_DC_order = ENTITY_ORDER_10;
	v2->retaliation_target = v3;
	v2->retaliation_target_id = v3->entity_id;
	v2->_E4_prev_attack_target = 0;
	v2->_134_param__unitstats_after_mobile_outpost_plant = 600;
	v2->mode_arrive = entity_mode_419230_arrive_at_repairbay;
	v3->sprite->field_88_unused = 1;
	v2->sprite_x_2 = v3->sprite->x + *(_DWORD *)(v3->stru60.ptr_14 + 4);
	v4 = *(_DWORD *)(v3->stru60.ptr_14 + 8);
	v5 = v3->sprite->y;
	v2->entity_8 = 0;
	v2->sprite_y_2 = v5 + v4;
	Map_40DF50_update_tile(v2, 1);
	v2->SetMode(entity_mode_move_attack);
}

//----- (0041A510) --------------------------------------------------------
void entity_41A510_evt1503(Entity *a1, int a2)
{
	Entity *v2; // esi@1
	UnitStat *v3; // eax@2
	void *v4; // edi@3
	Entity *v5; // eax@8
	Script *v6; // eax@10
	int v7; // eax@12
	Entity *v8; // eax@13
	int v9; // ecx@14

	v2 = a1;
	if (a2)
	{
		v3 = a1->stats;
		if (v3->is_infantry)
			v4 = (void *)*(_WORD *)(a2 + 140);
		else
			v4 = (void *)(v3->speed ? *(_WORD *)(a2 + 142) : (int)*(_WORD *)(a2 + 144));
		if (a1->hitpoints > 0)
		{
			v5 = *(Entity **)(a2 + 128);
			if (v5)
			{
				if (v5->entity_id == *(_DWORD *)(a2 + 132))
				{
					v6 = v5->script;
					if (v6)
						script_trigger_event(a1->script, MSG_RECEIVE_EXPERIENCE, v4, v6);
				}
			}
			v7 = v2->hitpoints - (_DWORD)v4;
			v2->hitpoints = v7;
			if (v7 <= 0)
			{
                script_sleep(v2->script, 1);
				v8 = v2->retaliation_target;
				if (v8)
				{
					v9 = v8->entity_id;
					if (v9)
					{
						if (v9 == v2->retaliation_target_id
							&& v8->script->script_type == SCRIPT_REPAIR_STATION_HANDLER)
						{
							*((_DWORD *)v8->state + 2) = 0;
						}
					}
				}
				v2->hitpoints = 0;
				v2->SetMode(entity_419560_on_death);
				v2->destroyed = 1;
				entity_check_special_mission_death_conditions(v2);
			}
		}
	}
}

//----- (0041A610) --------------------------------------------------------
void entity_do_damage(Entity *a1, Sprite *a2)
{
	Entity *v2; // esi@1
	UnitStat *v3; // eax@2
	int v4; // edi@3
	Entity *v5; // eax@8
	Script *v6; // eax@10
	int v7; // eax@12

	v2 = a1;
	if (a2)
	{
		v3 = a1->stats;
		if (v3->is_infantry)
			v4 = a2->field_8C_infantry_damage;
		else
			v4 = v3->speed ? a2->field_8E_vehicle_damage : a2->field_90_building_damage;
		if (a1->hitpoints > 0)
		{
			v5 = (Entity *)a2->_80_entity__stru29__sprite__initial_hitpoints;
			if (v5)
			{
				if (v5->entity_id == a2->field_84)
				{
					v6 = v5->script;
					if (v6)
						script_trigger_event(a1->script, MSG_RECEIVE_EXPERIENCE, (void *)v4, v6);
				}
			}
			v7 = v2->hitpoints - (_DWORD)v4;
			v2->hitpoints = v7;
			if (v7 <= 0)
			{
                script_sleep(v2->script, 1);
				v2->hitpoints = 0;
				v2->SetMode(entity_419560_on_death);
				v2->destroyed = 1;
				entity_check_special_mission_death_conditions(v2);
			}
		}
	}
}

//----- (0041A6D0) --------------------------------------------------------
void entity_on_attacked_default(Entity *a1, Entity *a2)
{
	Entity *v2; // esi@1
	enum UNIT_ID v3; // eax@1
	int v4; // eax@13
	Sprite *v5; // eax@15
	stru11unit *v6; // ebx@18
	stru11unit *v7; // eax@19
	int v8; // ecx@19
	stru11unit *v9; // edi@25
	void *v10; // eax@26

	v2 = a1;
	v3 = a1->unit_id;
	if (v3 == UNIT_STATS_SURV_MOBILE_OUTPOST
		|| v3 == UNIT_STATS_MUTE_CLANHALL_WAGON
		|| v3 == UNIT_STATS_SURV_MOBILE_DERRICK
		|| v3 == UNIT_STATS_MUTE_MOBILE_DERRICK
		|| v3 == UNIT_STATS_SURV_SABOTEUR && a1->_DC_order == ENTITY_ORDER_3
		|| v3 == UNIT_STATS_MUTE_VANDAL && a1->_DC_order == ENTITY_ORDER_3
		|| v3 == UNIT_STATS_SURV_TECHNICIAN && a1->_DC_order == ENTITY_ORDER_3
		|| v3 == UNIT_STATS_MUTE_MEKANIK && a1->_DC_order == ENTITY_ORDER_3
		|| (v4 = a1->GetOrder(), v4 != ENTITY_ORDER_MOVE) && v4 != ENTITY_ORDER_0
		|| (v5 = a1->sprite, !map_is_same_tile(v5->x, a1->sprite_x_2))
		|| !map_is_same_tile(v5->y, a1->sprite_y_2))
	{
		a1->_E4_prev_attack_target = a2;
		a1->_E4_prev_attack_target_entity_id = a2->entity_id;
		v6 = (stru11unit *)&a1->stru11_list_104;
		do
		{
			v7 = v6->next;
			v8 = 0;
			if (v6->next != v6)
			{
				while (v7->param)
				{
					v7 = v7->next;
					if (v7 == v6)
						goto LABEL_24;
				}
				v7->next->prev = v7->prev;
				v7->prev->next = v7->next;
				v7->next = stru11unit_list_head;
				stru11unit_list_head = v7;
				v8 = 1;
			}
		LABEL_24:
			;
		} while (v8);
		v9 = v6->next;
		for (v2->entity_118 = a2; v9 != v6; v9 = v9->next)
		{
			v10 = v9->param;
			if (v10)
				script_trigger_event(v2->script, EVT_MSG_1508, v2, *((Script **)v10 + 3));
		}
	}
	else
	{
		a1->retaliation_target = a2;
		a1->retaliation_target_id = a2->entity_id;
		a1->_E4_prev_attack_target = 0;
		a1->SetOrder(ENTITY_ORDER_8);
		a1->entity_8 = 0;
		entity_mode_move_attack(a1);
        script_sleep(v2->script, 1);
	}
}

//----- (0041A850) --------------------------------------------------------
void entity_41A850_evt1507_mess_with_stru11(Entity *a1, void *param)
{
	stru11unit *v2; // eax@1
	stru11unit *v3; // esi@4
	stru11unit *v4; // ecx@4

	v2 = stru11unit_list_head;
	if (stru11unit_list_head)
		stru11unit_list_head = stru11unit_list_head->next;
	else
		v2 = 0;
	v3 = a1->stru11_list_104;
	v4 = (stru11unit *)&a1->stru11_list_104;
	v2->next = v3;
	v2->prev = v4;
	v4->next->prev = v2;
	v4->next = v2;
	v2->param = param;
}

//----- (0041A890) --------------------------------------------------------
void entity_41A890_evt1528(Entity *a1)
{
	Entity *v2; // eax@2

	if (sub_44CA50(a1->unit_id))
		v2 = entity_44CA70_find(a1, UNIT_STATS_SURV_OUTPOST, a1->player_side);
	else
		v2 = entity_44CA70_find(a1, UNIT_STATS_MUTE_CLANHALL, a1->player_side);
	if (v2)
	{
        a1->SetOrder(ENTITY_ORDER_4);
        a1->retaliation_target = v2;
        a1->retaliation_target_id = v2->entity_id;
		entity_mode_move_attack(a1);
	}
	else
	{
        a1->sprite_x = map_adjust_entity_in_tile_x(a1, a1->sprite->x);
        a1->sprite_y = map_adjust_entity_in_tile_y(a1, a1->sprite->y);
        a1->SetOrder(ENTITY_ORDER_MOVE);
		entity_mode_move_attack(a1);
	}
}

//----- (0041A980) --------------------------------------------------------
void entity_41A980_evt1509_unset_stru11(Entity *a1, void *param)
{
	stru11unit *v2; // eax@1
	stru11unit *end; // ecx@1

	v2 = a1->stru11_list_104;
	end = (stru11unit *)&a1->stru11_list_104;
	if (v2 != end)
	{
		while (v2->param != param)
		{
			v2 = v2->next;
			if (v2 == end)
				return;
		}
		v2->param = 0;
	}
}

//----- (0041A9B0) --------------------------------------------------------
void entity_41A9B0_unit(Entity *a1, void *param)
{
    auto param_ = (int *)param;
    int param_player_side = param_[0];
    int param_x = param_[1];
    int param_y = param_[2];

	if (a1->player_side == param_player_side)
	{
		if (param_x >= 0 && param_x < map2global(map_get_width()))
		{
			if (param_y >= 0 && param_y < map2global(map_get_height()))
			{
				a1->sprite_width_3 = map_adjust_entity_in_tile_x(a1, param_x);
                a1->sprite_height_3 = map_adjust_entity_in_tile_y(a1, param_y);

				entity_414440_boxd(a1, &a1->sprite_width_3, &a1->sprite_height_3);
			}
		}
	}
}

//----- (0041AAA0) --------------------------------------------------------
bool array_479B98_array_479C60_init()
{
	int v0; // eax@1
	int v1; // edx@2

	v0 = 0;
	array_479B98_array_479C60_inited = 1;
	do
	{
		v1 = 25;
		do
		{
			array_479C60[v0][0] = 0;
			array_479B98[v0][0] = 0;
			array_479C60[v0][1] = 0;
			array_479B98[v0][1] = 0;
			++v0;
			--v1;
		} while (v1);
	} while (v0 < 25);
	return 1;
}

//----- (0041AC50) --------------------------------------------------------
__int16 input_get_string(
    const char *a1, int max_len, void(*draw_handler)(const char *, int), int a4, Script *a5
)
{
	int v5; // ebx@1
	char *v6; // ebp@1
	//void(*v7)(const char *, int); // edi@1
	bool v8; // zf@42
	int v11; // [sp+14h] [bp-Ch]@1
	char *v12; // [sp+18h] [bp-8h]@1

	v5 = 0;
	v6 = (char *)a1;
	v11 = 1;
    input_char_clear();
	v12 = (char *)malloc(max_len + 1);
	strcpy(v12, v6);
    draw_handler(v6, 0);
	while (v11)
	{
        input_char_clear();
		do
		{
			if (a5)
			{
                script_sleep(a5, 1);
			}
			else
			{
				script_list_update();
				sprite_list_init_mobd_items();
				sprite_list_update_positions();
				draw_list_update_and_draw();
				TimedMessagePump();
			}
		} while (!input_char_is_any());

		switch (auto c = (unsigned)input_char_get())
		{
		case 37: // vk_left
			if (v5 > 0)
			{
				v5--;
                draw_handler(v6, v5);
			}
			goto LABEL_41;
		case 39: // vk_right
			if (strlen(v6) != 0 && (unsigned __int16)v5 < (int)(max_len - 1) && (unsigned __int16)v5 < strlen(v6) - 1)
			{
				++v5;
				goto LABEL_40;
			}
			goto LABEL_41;
		case 36: // vk_home
			v5 = 0;
            draw_handler(v6, 0);
			goto LABEL_41;

		case 35: // vk_end
			if (strlen(v6) != 0)
			{
				v5 = strlen(v6) - 1;
				goto LABEL_40;
			}
			goto LABEL_41;
		case 27: // vk_escape
			strcpy((char *)v6, v12);
			goto LABEL_19;
		case 13: // vk_return
        case INPUT_KEYBOARD_RETURN_MASK: // kknd return
		LABEL_19:
			v11 = 0;
			goto LABEL_41;
		case 45: // vk_insert
			if (strlen(v6) >= max_len)
				goto LABEL_41;
			memcpy((void *)&v6[(unsigned __int16)v5 + 1], &v6[(unsigned __int16)v5], strlen(v6) - (unsigned __int16)v5);
			v6[(unsigned __int16)v5] = 32;
			goto LABEL_40;
		case 46: // vk_delete
			if (strlen(v6) == 0)
				goto LABEL_41;
			strcpy((char *)&v6[(unsigned __int16)v5], &v6[(unsigned __int16)v5 + 1]);
			if ((unsigned __int16)v5 >= strlen(v6) && (_WORD)v5)
				v5 += 0xFFFF;
			goto LABEL_40;
		case 8: // vk_backspace
			if (strlen(v6) == 0 || !(_WORD)v5)
				goto LABEL_41;
			strcpy((char *)&v6[(unsigned __int16)v5 - 1], &v6[(unsigned __int16)v5]);
			v5 += 0xFFFF;
			goto LABEL_40;
		default:
			if (input_char_is_alpha()
				|| input_char_is_numeric()
				|| input_char_is_whitespace())
			{
				v6[(unsigned __int16)v5] = c;
				if ((unsigned __int16)v5 < (int)(max_len - 1))
				{
					if ((unsigned __int16)v5 >= strlen(v6) - 1)
					{
						if ((unsigned __int16)v5 < (int)(max_len - 1) && (unsigned __int16)v5 == strlen(v6) - 1)
							v6[(unsigned __int16)++v5] = 0;
					}
					else
					{
						++v5;
					}
				}
			LABEL_40:
                draw_handler(v6, v5);
			}
        LABEL_41:;
		}
	}


    free(v12);

    input_reset_keyboard();

    v8 = input_char_is_escape();
    input_char_clear();
    return !v8;
}

//----- (0041B000) --------------------------------------------------------
bool _41B000_stru7_handler(Sprite *a1, Sprite *a2, int a3, void *a4, void *a5)
{
	if (a1->script)
		script_trigger_event(0, EVT_MOUSE_HOVER, a2->script, a1->script);
	return 0;
}

//----- (0041B020) --------------------------------------------------------
bool _41B020_stru7_handler(Sprite *a1, Sprite *a2, int a3, void *a4, void *a5)
{
	Script *v7; // eax@1
	Script *v8; // eax@4

	v7 = a1->script;
	if (v7 && v7->_28_yield_flags & SCRIPT_FLAGS_20_EVENT_TRIGGER)
		script_trigger_event(0, EVT_MOUSE_HOVER, a2->script, a1->script);
	v8 = a2->script;
	if (v8 && v8->_28_yield_flags & SCRIPT_FLAGS_20_EVENT_TRIGGER)
		script_trigger_event(0, EVT_MOUSE_HOVER, a1, a2->script);
	return 0;
}

//----- (0041B070) --------------------------------------------------------
bool _41B070_stru7_handler(Sprite *a1, Sprite *a2, int a3, void *a4, void *a5)
{
	Sprite *v5; // esi@1
	Script *v6; // ecx@1
	int v7; // edi@1
	Sprite *v8; // eax@2
	int v9; // eax@4
	int v10; // eax@6

	v5 = a1;
	v6 = a2->script;
	v7 = (int)a2->param;
	if (v6)
	{
		v8 = v5->parent;
		if (v8 != a2)
		{
			if (v8)
			{
				v9 = (int)v8->param;
				if (v9)
				{
					if (*(_DWORD *)(v9 + 20) != *(_DWORD *)(v7 + 20) || (v10 = *(_DWORD *)(v7 + 16), v10 >= 46) && v10 <= 72)
					{
						script_trigger_event(0, CMD_APPLY_DAMAGE, v5, v6);
						v5->script->flags_20 |= SCRIPT_FLAGS_20_2;
						v5->script->flags_24 |= v5->script->flags_20;
					}
				}
			}
		}
	}
	return 0;
}



//----- (0041B0E0) --------------------------------------------------------
bool LVL_SysInit()
{
	currently_running_lvl_sections = 0;
	if (stru2_list_alloc())
	{
        int window_width = 640;
        int window_height = 480;
        bool fullsreen = false;

        /*if (render_create_window(window_width, window_height, fullsreen))*/ {
            if (render_init(window_width, window_height, 8, fullsreen)) {
                return sound_initialize() != false;
            }
        }
	}

	return false;
}

//----- (0041B140) --------------------------------------------------------
DataHunk *LVL_LoadLevel(const char *filename_)
{
	char filename[1024];

	const char *ext = strrchr(filename_, '.');
	if (!_stricmp(ext, ".slv"))
	{
		sprintf(
			filename,
            "%s\\LEVELS\\%s",
            OsGetCurrentDirectory().c_str(),//game_data_installation_dir,
			filename_);
	}
	else if (!_stricmp(ext, ".lvl"))
	{
		sprintf(
			filename,
			(const char *)aSLevelsSS,
            OsGetCurrentDirectory().c_str(),//game_data_root_dir,
			get_resource_res_subfolder(),
			filename_
		);
	}
	else throw 42;

	DataHunk *result = nullptr;

	File *level_file = File::open(filename);
	if (level_file) {
    void *level_data = (DataHunk*)level_file->read_hunk();
		if (level_data) {
			RllcHunk *level_rllc = (RllcHunk*)level_file->read_hunk();
			if (level_rllc) {
				level_file->close();
				result = (DataHunk *)HUNK_FixPointers(level_data, level_rllc);
				if (result) {
					free(level_rllc);
					result = (DataHunk *)level_data;
				}
			}
		}
	}
	return result;
}

//----- (0041B1A0) --------------------------------------------------------
bool LVL_RunLevel(DataHunk *lvl)
{
	_479DE8_boxd_initialized = 0;
	_479DCC_cplc_initialized = 0;
	_479DC0_render_string_list_initialized = 0;
	stru1_global_obj_anim_initialized = 0;
	input_initialized = 0;
	game_window_created = 0;
	stru2_list_elements_initialized = 0;
	draw_list_initialized = 0;
	_479DF0_mapd_initialized = 0;
	_479DD0_mobd_initialized = 0;
	is_task_list_initialized = 0;
	timer_initialized = 0;
	dword_479DBC = 0;
	if (!currently_running_lvl_sections)
	{
		currently_running_lvl = lvl;
		currently_running_lvl_sections = lvl->section_table;
		if (script_list_alloc())
		{
			is_task_list_initialized = 1;
			if (timer_init(60u))
			{
				timer_initialized = 1;
				if (array_479B98_array_479C60_init())
				{
					dword_479DBC = 1;
					if (stru2_list_init_elements())
					{
						stru2_list_elements_initialized = 1;
						if (draw_list_alloc())
						{
							draw_list_initialized = 1;
							if (LVL_InitMapd())
							{
								_479DF0_mapd_initialized = 1;
								if (sprite_list_alloc())
								{
									_479DD0_mobd_initialized = 1;
									if (boxd_init())
									{
										_479DE8_boxd_initialized = 1;
										if (cplc_init())
										{
											_479DCC_cplc_initialized = 1;
											if (render_string_list_alloc())
											{
												_479DC0_render_string_list_initialized = 1;
												if (stru1_init_anim())
												{
													stru1_global_obj_anim_initialized = 1;
													if (input_initialize())
													{
														input_initialized = 1;
                                                        return true;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}

//----- (0041B2E0) --------------------------------------------------------
void LVL_Deinit()
{
	if (input_initialized)
		nullsub_3();
	if (stru1_global_obj_anim_initialized)
		nullsub_1();
	if (_479DC0_render_string_list_initialized)
		render_string_list_free();
	if (_479DCC_cplc_initialized)
		cplc_free();
	if (_479DE8_boxd_initialized)
		boxd_free();
	if (_479DD0_mobd_initialized)
		sprite_list_free();
	if (_479DF0_mapd_initialized)
		bitmap_list_free();
	if (draw_list_initialized)
		draw_list_free();
	if (stru2_list_elements_initialized)
		stru2_list_remove_elements();
	if (dword_479DBC)
		nullsub_1();
	if (timer_initialized)
		nullsub_1();
	if (is_task_list_initialized)
		script_list_free();
	_479DE8_boxd_initialized = 0;
	_479DCC_cplc_initialized = 0;
	_479DC0_render_string_list_initialized = 0;
	stru1_global_obj_anim_initialized = 0;
	input_initialized = 0;
	game_window_created = 0;
	stru2_list_elements_initialized = 0;
	draw_list_initialized = 0;
	_479DF0_mapd_initialized = 0;
	_479DD0_mobd_initialized = 0;
	is_task_list_initialized = 0;
	timer_initialized = 0;
	dword_479DBC = 0;
	currently_running_lvl = 0;
	currently_running_lvl_sections = 0;
}

//----- (0041B3F0) --------------------------------------------------------
void GAME_Deinit()
{
	if (currently_running_lvl_sections)
		LVL_Deinit();
	if (game_window_created)
		render_cleanup();
	sound_deinit();
	stru2_list_free();
	VIDEO_free();
}

DataMapd *LVL_FindMapd()
{
    return (DataMapd *)LVL_FindSection("MAPD");
}
//----- (0041B420) --------------------------------------------------------
void *LVL_FindSection(const char *name)
{
	DataSectionOffset *v1; // eax@1
	const char *v2; // edi@1
	int v3; // esi@1
	void *result; // eax@4

	v1 = currently_running_lvl_sections;
	v2 = name;
	v3 = 0;
	if (currently_running_lvl_sections->ptr)
	{
		while (strncmp(v2, v1[v3].name, 4u))
		{
			v1 = currently_running_lvl_sections;
			if (!currently_running_lvl_sections[++v3].ptr)
				return 0;
		}
		return currently_running_lvl_sections[v3].ptr;
	}

    return nullptr;
}

//----- (0041B470) --------------------------------------------------------
bool LVL_SubstHunk(DataHunk *dst, DataHunk *src, const char *hunk)
{
	DataSectionOffset *src_hunk_name; // eax@1
	DataSectionOffset *dst_hunk_table; // ecx@1
	int *src_hunk_offset; // esi@1
	void *src_hunk_items; // ebp@1
	int v7; // ecx@4
	int dst_hunk_idx; // edi@7
	DataSectionOffset *dst_hunk_name; // eax@8
	DataSectionOffset *v10; // esi@8
	void *v11; // ecx@10
	DataSectionOffset *dst_hunk_tAble; // [sp+10h] [bp-4h]@1

	src_hunk_name = src->section_table;
	dst_hunk_table = dst->section_table;
	src_hunk_offset = (int *)&src->section_table->ptr;
	src_hunk_items = 0;
	dst_hunk_tAble = dst_hunk_table;
	if (*src_hunk_offset)
	{
		do
		{
			if (!strncmp(hunk, src_hunk_name->name, 4u))
				src_hunk_items = (void *)*src_hunk_offset;
			v7 = src_hunk_offset[2];
			src_hunk_offset += 2;
			src_hunk_name = (DataSectionOffset *)(src_hunk_offset - 1);
		} while (v7);
		dst_hunk_table = dst_hunk_tAble;
	}
	if (src_hunk_items && (dst_hunk_idx = 0, dst_hunk_table->ptr))
	{
		dst_hunk_name = dst_hunk_table;
		v10 = dst_hunk_table;
		while (strncmp(hunk, dst_hunk_name->name, 4u))
		{
			v11 = v10[1].ptr;
			++v10;
			++dst_hunk_idx;
			dst_hunk_name = v10;
			if (!v11)
				return 0;
		}
		dst_hunk_tAble[dst_hunk_idx].ptr = src_hunk_items;
        return true;
	}
    return false;
}

//----- (0041B510) --------------------------------------------------------
bool entity_41B510(Entity *a1, Entity *a2)
{
	Sprite *v2; // eax@1
	int v3; // ebx@1
	int v4; // ecx@3
	Sprite *v5; // eax@5
	int v6; // edi@5
	int v7; // esi@7
	int v8; // ebx@9
	int v9; // edi@9
	int v10; // ecx@9
	int v11; // esi@9
	int v13; // eax@12
	DataBoxd_stru0_per_map_unit *v14; // edx@12
	int v15; // edi@13
	int v16; // ecx@13
	DataBoxd_stru0_per_map_unit *v17; // esi@14
	int v18; // ecx@15
	int v19; // ebp@15
	int v20; // ebx@15
	bool v21; // zf@21
	int v22; // ebp@23
	int v23; // ebx@23
	int v24; // edi@23
	int v25; // edi@32
	DataBoxd_stru0_per_map_unit *v26; // esi@32
	int v27; // ebp@33
	int v28; // ebx@33
	int v29; // ebp@42
	int v30; // ebx@42
	int v31; // edi@42
	int v32; // edi@51
	int v33; // ecx@51
	DataBoxd_stru0_per_map_unit *v34; // esi@52
	int v35; // ecx@53
	int v36; // ebp@53
	int v37; // ebx@53
	int v38; // ebp@61
	int v39; // ebx@61
	int v40; // edi@61
	int v41; // edi@70
	DataBoxd_stru0_per_map_unit *v42; // esi@70
	int v43; // ebp@71
	int v44; // ebx@71
	int v45; // ebp@80
	int v46; // ebx@80
	int v47; // edi@80
	Entity *a3; // [sp+10h] [bp-10h]@1
	Entity *a2a; // [sp+14h] [bp-Ch]@1
	int v50; // [sp+18h] [bp-8h]@15
	int v51; // [sp+18h] [bp-8h]@23
	int v52; // [sp+18h] [bp-8h]@33
	int v53; // [sp+18h] [bp-8h]@42
	int v54; // [sp+18h] [bp-8h]@53
	int v55; // [sp+18h] [bp-8h]@61
	int v56; // [sp+18h] [bp-8h]@71
	int v57; // [sp+18h] [bp-8h]@80
	int v58; // [sp+1Ch] [bp-4h]@15
	int v59; // [sp+1Ch] [bp-4h]@33
	int v60; // [sp+1Ch] [bp-4h]@53
	int v61; // [sp+1Ch] [bp-4h]@71

	v2 = a1->sprite;
	v3 = v2->x;
	a3 = a2;
	a2a = a1;
	if (v3 >= 0 && v3 < map_get_width_global())
	{
		v4 = v2->y;
		if (v4 >= 0 && v4 < map_get_height_global())
		{
			v5 = a2->sprite;
			v6 = v5->x;
			if (v6 >= 0 && v6 < map_get_width_global())
			{
				v7 = v5->y;
				if (v7 >= 0 && v7 < map_get_height_global())
				{
					v8 = v3 >> 13;
					v9 = v6 >> 13;
					v10 = v4 >> 13;
					v11 = v7 >> 13;
					if (v8 == v9 && v10 == v11)
						return 1;
					v13 = map_get_width();
					v14 = boxd_get_tile(v8, v10);
					if (v10 > v11)
					{
						v32 = v9 - v8;
						v33 = v10 - v11;
						if (v32 <= 0)
						{
							v41 = -v32;
							v42 = v14;
							if (v41 <= v33)
							{
								v45 = 2 * v41;
								v46 = 2 * v41 - 2 * v33;
								v47 = 2 * v41 - v33;
								v57 = v33 - 1;
								if (v33)
								{
									while (1)
									{
										if (v47 < 0)
										{
											v47 += v45;
										}
										else
										{
											--v42;
											v47 += v46;
										}
										v42 -= v13;
										if (!boxd_40EDF0(v42, a2a, a3))
											break;
										v21 = v57-- == 0;
										if (v21)
											return 1;
										v13 = map_get_width();
									}
									return 0;
								}
							}
							else
							{
								v61 = 2 * v33;
								v43 = 2 * v33 - 2 * v41;
								v44 = 2 * v33 - v41;
								v56 = v41 - 1;
								if (v41)
								{
									while (1)
									{
										if (v44 < 0)
										{
											v44 += v61;
										}
										else
										{
											v44 += v43;
											v42 -= v13;
										}
										--v42;
										if (!boxd_40EDF0(v42, a2a, a3))
											break;
										v21 = v56-- == 0;
										if (v21)
											return 1;
										v13 = map_get_width();
									}
									return 0;
								}
							}
						}
						else
						{
							v34 = v14;
							if (v32 > v33)
							{
								v35 = 2 * v33;
								v36 = v35 - 2 * v32;
								v37 = v35 - v32;
								v60 = v35;
								v54 = v32 - 1;
								while (1)
								{
									if (v37 < 0)
									{
										v37 += v35;
									}
									else
									{
										v37 += v36;
										v34 -= v13;
									}
									++v34;
									if (!boxd_40EDF0(v34, a2a, a3))
										break;
									v21 = v54-- == 0;
									if (v21)
										return 1;
									v13 = map_get_width();
									v35 = v60;
								}
								return 0;
							}
							v38 = 2 * v32;
							v39 = 2 * v32 - 2 * v33;
							v40 = 2 * v32 - v33;
							v55 = v33 - 1;
							if (v33)
							{
								while (1)
								{
									if (v40 < 0)
									{
										v40 += v38;
									}
									else
									{
										++v34;
										v40 += v39;
									}
									v34 -= v13;
									if (!boxd_40EDF0(v34, a2a, a3))
										break;
									v21 = v55-- == 0;
									if (v21)
										return 1;
									v13 = map_get_width();
								}
								return 0;
							}
						}
					}
					else
					{
						v15 = v9 - v8;
						v16 = v11 - v10;
						if (v15 <= 0)
						{
							v25 = -v15;
							v26 = v14;
							if (v25 <= v16)
							{
								v29 = 2 * v25;
								v30 = 2 * v25 - 2 * v16;
								v31 = 2 * v25 - v16;
								v53 = v16 - 1;
								if (v16)
								{
									while (1)
									{
										if (v31 < 0)
										{
											v31 += v29;
										}
										else
										{
											--v26;
											v31 += v30;
										}
										v26 += v13;
										if (!boxd_40EDF0(v26, a2a, a3))
											break;
										v21 = v53-- == 0;
										if (v21)
											return 1;
										v13 = map_get_width();
									}
									return 0;
								}
							}
							else
							{
								v59 = 2 * v16;
								v27 = 2 * v16 - 2 * v25;
								v28 = 2 * v16 - v25;
								v52 = v25 - 1;
								if (v25)
								{
									while (1)
									{
										if (v28 < 0)
										{
											v28 += v59;
										}
										else
										{
											v28 += v27;
											v26 += v13;
										}
										--v26;
										if (!boxd_40EDF0(v26, a2a, a3))
											break;
										v21 = v52-- == 0;
										if (v21)
											return 1;
										v13 = map_get_width();
									}
									return 0;
								}
							}
						}
						else
						{
							v17 = v14;
							if (v15 > v16)
							{
								v18 = 2 * v16;
								v19 = v18 - 2 * v15;
								v20 = v18 - v15;
								v58 = v18;
								v50 = v15 - 1;
								while (1)
								{
									if (v20 < 0)
									{
										v20 += v18;
									}
									else
									{
										v20 += v19;
										v17 += v13;
									}
									++v17;
									if (!boxd_40EDF0(v17, a2a, a3))
										break;
									v21 = v50-- == 0;
									if (v21)
										return 1;
									v13 = map_get_width();
									v18 = v58;
								}
								return 0;
							}
							v22 = 2 * v15;
							v23 = 2 * v15 - 2 * v16;
							v24 = 2 * v15 - v16;
							v51 = v16 - 1;
							if (v16)
							{
								while (1)
								{
									if (v24 < 0)
									{
										v24 += v22;
									}
									else
									{
										++v17;
										v24 += v23;
									}
									v17 += v13;
									if (!boxd_40EDF0(v17, a2a, a3))
										break;
									v21 = v51-- == 0;
									if (v21)
										return 1;
									v13 = map_get_width();
								}
								return 0;
							}
						}
					}
					return 1;
				}
			}
		}
	}
	return 0;
}

//----- (0041ED90) --------------------------------------------------------
void sub_41ED90(void *a1, stru24_struC *a2)
{
	int v2; // eax@1
	int v3; // esi@2
	Entity *v4; // esi@4
	int v5; // eax@8
	int v6; // eax@9
	int v7; // eax@10

	*(_DWORD *)a1 = 0;
	v2 = a2->field_8;
	if (v2)
	{
		v3 = *(_DWORD *)(v2 + 12);
		if (v3 == v2 + 12)
		{
			*((_DWORD *)a1 + 2) = -2;
		}
		else
		{
			v4 = *(Entity **)(v3 + 12);
			if (v4)
				*((_DWORD *)a1 + 2) = v4->entity_id;
			else
				*((_DWORD *)a1 + 2) = -1;
		}
	}
	else
	{
		*((_DWORD *)a1 + 2) = -1;
	}
	v5 = a2->field_24;
	if (v5 && (v6 = *(_DWORD *)(v5 + 8)) != 0)
		v7 = *(_DWORD *)(v6 + 304);
	else
		v7 = -1;
	*((_DWORD *)a1 + 1) = v7;
	*((_DWORD *)a1 + 3) = a2->field_28;
	*((_DWORD *)a1 + 4) = a2->field_2C;
	*((_DWORD *)a1 + 5) = a2->field_30;
	*((_DWORD *)a1 + 6) = a2->field_34;
	*((_DWORD *)a1 + 7) = a2->field_38;
	*((_DWORD *)a1 + 8) = a2->field_3C;
	*((_DWORD *)a1 + 9) = a2->field_40;
}

//----- (0041EE20) --------------------------------------------------------
void sub_41EE20(stru24 *a1, int a2, stru24_stru160 *a3)
{
	int v7; // eax@12
	stru24_stru160 *v8; // edi@13
	stru24_stru160 *v9; // eax@13
	char *v10; // edi@19
	stru24_EnemyNode *v11; // ecx@19
	int v12; // ecx@24
	int v13; // edx@26

    auto v5 = entityRepo->FindById(*(_DWORD *)(a2 + 4));
    auto v3 = entityRepo->FindById(*(_DWORD *)(a2 + 8));
    auto v6 = *(_DWORD *)(a2 + 8);

	if (v3 && (v7 = v3->_24_ai_node_per_player_side._0_ai_node_per_player_side[a1->_2A0_player_side]) != 0)
	{
		v8 = *(stru24_stru160 **)(v7 + 8);
		v9 = a3;
		if (v8)
		{
			a3->field_8 = v8;
			goto LABEL_19;
		}
	}
	else
	{
		if (v6 == -2)
		{
			v9 = a3;
			a3->field_8 = a1->field_24C;
			goto LABEL_19;
		}
		v9 = a3;
	}
	v9->field_8 = 0;
LABEL_19:
	v10 = (char *)&a1->enemy_list_108;
	v9->field_24 = 0;
	v11 = a1->enemy_list_108;
	if ((char *)v11 != v10)
	{
		while ((Entity *)v11->entity->entity_id != v5)
		{
			v11 = v11->next;
			if ((char *)v11 == v10)
				goto LABEL_24;
		}
		v9->field_24 = v11;
	}
LABEL_24:
	v9->field_28 = *(_DWORD *)(a2 + 12);
	v9->_2C_ai_importance = *(_DWORD *)(a2 + 16);
	v12 = *(_DWORD *)(a2 + 20);
	v9->field_30 = v12;
	if (v12 < 0)
		v9->field_30 = 0;
	v9->x_offset = *(_DWORD *)(a2 + 24);
	v9->y_offset = *(_DWORD *)(a2 + 28);
	v9->field_3C = *(_DWORD *)(a2 + 32);
	v13 = *(_DWORD *)(a2 + 36);
	v9->field_1C = 0;
	v9->field_40 = v13;
	v9->_C_next = &v9->_C_next;
	v9->_10_prev = &v9->_C_next;
}

//----- (00422500) --------------------------------------------------------
void GAME_ReadAppConfiguration()
{
    OsGetApplicationConfig(
        &game_installation_drive_letter,
        &is_minimal_install,
        game_data_installation_dir
    );
}

//----- (00412850) --------------------------------------------------------
int nullsub_3(void)
{
    return 1;
}


//----- (004267F0) --------------------------------------------------------
bool handler_4267F0(enum UNIT_ID unit_id, int x, int y, enum PLAYER_SIDE side)
{
	int v5; // edi@1
	Sprite *result; // eax@1
	int v7; // ecx@2

	result = sprite_create_scripted(
		unit_stats[unit_id].mobd_idx,
		0,
		unit_stats[unit_id].script_handler,
		SCRIPT_FUNCTION,
		0
    );

	if (result)
	{
		v7 = unit_id | ((int)side << 16) | 0x8000;
		result->x = x;
        result->y = y;
		result->field_88_unused = 1;
		result->cplc_ptr1 = 0;
		result->param = (void *)v7;
        return true;
	}
    return false;
}

//----- (00426860) --------------------------------------------------------
void _426860_4269B0_task_attachment_handler(_4269B0_task_attachment *a1)
{
	int v1; // eax@1

	v1 = a1->field_14;
	if (v1 <= 0)
	{
		if (a1->_24_iftrue__call_UNIT_Spawn__else__create_manually)
		{
			if (_4269B0_task_attachment__num_units_spawned > 0)
				--_4269B0_task_attachment__num_units_spawned;
		}
		else if (_4269B0_task_attachment__num_units_created_manually > 0)
		{
			--_4269B0_task_attachment__num_units_created_manually;
		}
		script_terminate(a1->task);
	}
	else
	{
		a1->stru53_54_55_unit_stats_idx_idx = 0;
		a1->handler = _4268B0_4269B0_task_attachment_handler;
		a1->field_14 = v1 - 1;
		_4268B0_4269B0_task_attachment_handler(a1);
	}
}

//----- (004268B0) --------------------------------------------------------
void _4268B0_4269B0_task_attachment_handler(_4269B0_task_attachment *a1)
{
	_4269B0_task_attachment *v1; // esi@1
	int v2; // eax@1
	enum UNIT_ID v3; // ebx@1
	int v4; // edi@4
	int v5; // ebp@4
	Sprite *v6; // eax@4
	int v7; // ecx@7
	int v8; // [sp+10h] [bp-4h]@4

	v1 = a1;
	v2 = a1->__468410_stru49_array_idx;
	v3 = _468410_stru49_array[v2].pstru_53_54_55->unit_stats_idx[a1->stru53_54_55_unit_stats_idx_idx];
	if (v3 == -1)
	{
		v7 = a1->field_14;
		v1->handler = _426860_4269B0_task_attachment_handler;
		if (v7 <= 0)
            script_sleep(v1->task, 1);
		else
            script_sleep(v1->task, _468410_stru49_array[v2]._8_some_task_flags);
	}
	else if (a1->_24_iftrue__call_UNIT_Spawn__else__create_manually)
	{
		spawn_unit(v3, a1->x, a1->y, player_side);
		++v1->stru53_54_55_unit_stats_idx_idx;
        script_sleep(v1->task, 6);
	}
	else
	{
		v4 = a1->field_28;
		v5 = a1->y;
		v8 = a1->x;
		v6 = sprite_create_scripted(unit_stats[v3].mobd_idx, 0, unit_stats[v3].script_handler, SCRIPT_FUNCTION, 0);
		if (v6)
		{
			v6->field_88_unused = 1;
			v6->x = v8;
			v6->y = v5;
			v6->cplc_ptr1 = 0;
			v6->param = (void *)(v3 | (v4 << 16) | 0x8000);
		}
		++v1->stru53_54_55_unit_stats_idx_idx;
        script_sleep(v1->task, 6);
	}
}

//----- (004269B0) --------------------------------------------------------
void task_4269B0_mobd_20_handler(Script *a1)
{
	Script *v1; // ebp@1
	_4269B0_task_attachment *v2; // esi@1
	Sprite *v3; // eax@3
	int v4; // edi@3
	unsigned int v5; // ebx@3
	__int32 v6; // eax@11
	stru53 *v7; // ebx@11
	int v8; // eax@19
	int v9; // eax@20
	int v10; // ecx@20
	int v11; // eax@24
	int v12; // ebx@26
	int v13; // ecx@26
	int v14; // edi@26
	int v15; // ebx@27
	int v16; // edx@35
	DrawJobDetails *v17; // [sp+10h] [bp-8h]@3
	DrawJobDetails *v18; // [sp+10h] [bp-8h]@26
	int v19; // [sp+14h] [bp-4h]@11
	int a1a; // [sp+1Ch] [bp+4h]@3

	v1 = a1;
	v2 = (_4269B0_task_attachment *)a1->param;
	if (v2 || (v2 = (_4269B0_task_attachment *)script_create_local_object(a1, 44)) == 0)
	{
		(v2->handler)(v2);
		return;
	}
	v3 = a1->sprite;
	a1a = v3->y;
	v4 = v3->cplc_ptr1_pstru20->param_18;
	v3->field_88_unused = 1;
	v5 = v1->sprite->x;
	v17 = &_47A010_mapd_item_being_drawn[0]->draw_job->job_details;
	if (v5 < (render_call_draw_handler_mode1(v17) + 0xFFFFC0) << 8)
	{
		if (v5 <= 0x40)
			v5 = 0;
	}
	else
	{
		v5 = (render_call_draw_handler_mode1(v17) << 8) - 64;
	}
	if (a1a < (unsigned int)((render_call_draw_handler_mode2(v17) + 0xFFFFC0) << 8))
	{
		if ((unsigned int)a1a <= 0x40)
			a1a = 0;
	}
	else
	{
		a1a = (render_call_draw_handler_mode2(v17) + 0xFFFFC0) << 8;
	}
	v1->param = v2;
	v6 = (player_side - 1) ^ 1;
	v2->__468410_stru49_array_idx = v4;
	v2->x = v5;
	v2->field_28 = v6 + 1;
	v2->stru53_54_55_unit_stats_idx_idx = 0;
	v2->y = a1a;
	v2->field_10 = ((player_side - 1) ^ 1) + 1;
	v19 = v4;
	v2->field_14 = _468410_stru49_array[v4].field_C;
	v2->field_18 = _468410_stru49_array[v4]._8_some_task_flags;
	v2->task = v1;
	v1->sprite->script = 0;
	sprite_list_remove(v1->sprite);
	v7 = _468410_stru49_array[v4].pstru_53_54_55;
	if (v7->unit_stats_idx[0] != -1)
	{
		if (sub_44CA50(v7->unit_stats_idx[0]))
		{
			if (!is_player_faction_evolved())
			{
				v2->_24_iftrue__call_UNIT_Spawn__else__create_manually = 1;
				goto LABEL_18;
			}
		}
		else if (is_player_faction_evolved())
		{
			v2->_24_iftrue__call_UNIT_Spawn__else__create_manually = 1;
			goto LABEL_18;
		}
		v2->_24_iftrue__call_UNIT_Spawn__else__create_manually = 0;
	}
LABEL_18:
	if (v7->unit_stats_idx[v2->stru53_54_55_unit_stats_idx_idx] != -1)
	{
		do
		{
			v8 = v2->stru53_54_55_unit_stats_idx_idx + 1;
			v2->stru53_54_55_unit_stats_idx_idx = v8;
		} while (v7->unit_stats_idx[v8] != -1);
	}
	v9 = v2->_24_iftrue__call_UNIT_Spawn__else__create_manually;
	v10 = v2->stru53_54_55_unit_stats_idx_idx;
	v2->stru53_54_55_unit_stats_idx_idx = 0;
	if (v9)
		++_4269B0_task_attachment__num_units_spawned;
	else
		++_4269B0_task_attachment__num_units_created_manually;
	if (_4269B0_task_attachment__4_some_task_flags > 0)
	{
		v11 = _4269B0_task_attachment__4_some_task_flags
			- _468410_stru49_array[v2->__468410_stru49_array_idx]._4_some_task_flags;
		if (v11 >= 0)
		{
			v12 = v2->field_18;
			v13 = 6 * v10;
			v18 = (DrawJobDetails *)(v11 % (v12 + v13));
			v14 = -1 - v11 / (v12 + v13) + v2->field_14;
			v2->field_14 = v14;
			if (v14 > 0)
			{
				if ((int)v18 >= v13 || v2->_24_iftrue__call_UNIT_Spawn__else__create_manually)
				{
					v15 = v12 - (_DWORD)v18;
				}
				else
				{
					if (v14 < _468410_stru49_array[v19].field_C)
						v2->field_14 = v14 + 1;
					v15 = 1;
				}
			}
			else
			{
				v15 = 1;
			}
			v2->handler = _426860_4269B0_task_attachment_handler;
            script_sleep(v1, v15);
		}
		else
		{
			v2->handler = _426860_4269B0_task_attachment_handler;
            script_sleep(v1, -v11);
		}
	}
	else
	{
		v16 = v2->__468410_stru49_array_idx;
		v2->handler = _426860_4269B0_task_attachment_handler;
        script_sleep(v1, _468410_stru49_array[v16]._4_some_task_flags);
	}
}

//----- (00427600) --------------------------------------------------------
void UNIT_Handler_MobileOutpost(Script *a1)
{
	Entity *v1; // esi@2
	int v2; // eax@4

	if (!_47C6DC_dont_execute_unit_handlers)
	{
		v1 = (Entity *)a1->param;
		if (!v1)
		{
			v1 = EntityFactory().Create(a1);
			entity_mobile_outpost_init(v1);
			entity_set_draw_handlers(v1);
		}
		v1->ExecMode();
		v2 = v1->_134_param__unitstats_after_mobile_outpost_plant;
		if (v2)
			v1->_134_param__unitstats_after_mobile_outpost_plant = v2 - 1;
	}
}

//----- (00427650) --------------------------------------------------------
void entity_mobile_outpost_init(Entity *a1)
{
	if (a1->sprite->cplc_ptr1)
	{
		a1->sprite->x = map_adjust_entity_in_tile_x(a1, a1->sprite->x);
		a1->sprite->y = map_adjust_entity_in_tile_y(a1, a1->sprite->y);

		a1->_A4_idx_in_tile = 0;
        a1->_A4_idx_in_tile = map_place_entity(
            a1,
            map_adjust_entity_in_tile_x(a1, a1->sprite->x),
            map_adjust_entity_in_tile_y(a1, a1->sprite->y),
            0
        );

		if (a1->_A4_idx_in_tile == ENTITY_TILE_POSITION_INVALID) {
            entity_mode_419760_infantry_destroyed(a1);
        } else {
            a1->sprite_x_2 = a1->sprite_x = a1->sprite->x;
            a1->sprite_y_2 = a1->sprite_y = a1->sprite->y;
			a1->SetOrder(ENTITY_ORDER_MOVE);
			a1->sprite_map_x = global2map(a1->sprite->x);
			a1->sprite_map_y = global2map(a1->sprite->y);
            a1->SetScriptEventHandler(MessageHandler_MobileOutpost);
			entity_mode_adjust_unit_placement_inside_tile(a1);
		}
    } else {
        if (!entity_413860_boxd(a1)) {
            entity_mode_419760_infantry_destroyed(a1);
        } else {
            a1->sprite_x_2 = a1->sprite_x = map_adjust_entity_in_tile_x(a1, map2global(a1->sprite_map_x));
            a1->sprite_y_2 = a1->sprite_y = map_adjust_entity_in_tile_y(a1, map2global(a1->sprite_map_y));
            a1->SetOrder(ENTITY_ORDER_MOVE);
            a1->_134_param__unitstats_after_mobile_outpost_plant = 0;
            a1->veterancy_level = 0;
            a1->SetScriptEventHandler(EventHandler_General_Scout);
            a1->SetReturnMode(entity_mode_4278C0_mobile_outpost);
            entity_4172D0(a1);
        }
    }
}

//----- (004278C0) --------------------------------------------------------
void entity_mode_4278C0_mobile_outpost(Entity *a1)
{
	a1->SetScriptEventHandler(MessageHandler_MobileOutpost);
	entity_mode_adjust_unit_placement_inside_tile(a1);
}

//----- (004278D0) --------------------------------------------------------
void MessageHandler_MobileOutpost(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param)
{
	Entity *v4; // esi@1

	v4 = (Entity *)receiver->param;
	if (!v4->destroyed)
	{
		switch (event)
		{
		case EVT_MSG_SELECTED:
			entity_selected_default(v4);
			break;
		case EVT_MSG_DESELECTED:
			entity_deselected_default(v4);
			break;
		case EVT_MSG_SHOW_UNIT_HINT:
			entity_show_hint(v4);
			break;
		case EVT_CMD_ENTITY_MOVE:
			entity_move(v4, (_47CAF0_task_attachment1_move_task *)param);
			break;

		case EVT_MSG_1507_stru11:
			entity_41A850_evt1507_mess_with_stru11(v4, param);
			break;
		case EVT_MSG_1509_stru11:
			entity_41A980_evt1509_unset_stru11(v4, param);
			break;
		case CMD_APPLY_DAMAGE:
			entity_do_damage(v4, (Sprite *)param);
			entity_410710_status_bar(v4);
			break;
		case MSG_ATTACKED:
			entity_on_attacked_default(v4, (Entity *)param);
			break;
		case EVT_MSG_1522_plan_building_construction:
			entity_4279E0_mobile_outpost_clanhall_wagon_plant(v4);
			break;
		default:
			return;
		}
	}
}

//----- (004279E0) --------------------------------------------------------
void entity_4279E0_mobile_outpost_clanhall_wagon_plant(Entity *a1)
{
	int initial_x_speed = a1->sprite->x_speed;
	int initial_y_speed = a1->sprite->y_speed;

    a1->sprite->x_speed = 0;
	a1->sprite->y_speed = 0;
	entity_40DEC0_boxd(a1, a1->sprite_map_x, a1->sprite_map_y, a1->_A4_idx_in_tile);
    
    a1->_134_param__unitstats_after_mobile_outpost_plant = a1->unit_id;
    a1->unit_id = a1->unit_id == UNIT_STATS_SURV_MOBILE_OUTPOST ? UNIT_STATS_SURV_OUTPOST : UNIT_STATS_MUTE_CLANHALL;
    a1->stru60.ptr_C->x_offset = -11776;
    a1->stru60.ptr_C->y_offset = -1280;
	sprite_408800_play_sound(a1->sprite, SOUND_MobileOutpost_ClanhallWagon_Planted, _4690A8_unit_sounds_volume, 0);

	if (entity_40DD00_boxd(a1))
	{
        // plant successful - make outpost

		script_trigger_event(a1->script, EVT_MSG_DESELECTED, 0, game_cursor_script);
		entity_deselected_default(a1);
        a1->SetScriptEventHandler(MessageHandler_MobileOutpostEmpty);

		if (a1->unit_id == UNIT_STATS_SURV_OUTPOST)
		{
            a1->sprite->mobd_id = MOBD_SURV_OUTPOST;
			sprite_4272E0_load_mobd_item(a1->sprite, 1232, 0);
		}
		else
		{
            a1->sprite->mobd_id = MOBD_MUTE_CLANHALL;
		}
		sprite_load_mobd(a1->sprite, 0);

		if (a1->unit_id == UNIT_STATS_SURV_OUTPOST)
		{
            a1->sprite->x = map_point_to_tile_global(a1->sprite->x + a1->stru60.ptr_C->x_offset) - a1->stru60.ptr_C->x_offset + 2048;
            a1->sprite->y = map_point_to_tile_global(a1->sprite->y + a1->stru60.ptr_C->y_offset) - a1->stru60.ptr_C->y_offset + 4096;
		}
		else
		{
            a1->sprite->x = map_point_to_tile_global(a1->sprite->x + a1->stru60.ptr_C->x_offset) - a1->stru60.ptr_C->x_offset + 7936;
            a1->sprite->y = map_point_to_tile_global(a1->sprite->y + a1->stru60.ptr_C->y_offset) - a1->stru60.ptr_C->y_offset + 3328;
		}

        a1->SetMode(entity_427C30_after_mobile_outpost_clanhall_wagon_plant);
		script_yield(a1->script, SCRIPT_FLAGS_20_10000000, 0);
	}
	else
	{
        // plant unsuccessful - restore entity
		a1->unit_id = (UNIT_ID)a1->_134_param__unitstats_after_mobile_outpost_plant;
		map_place_entity(a1, a1->sprite->x, a1->sprite->y, 0);
		a1->sprite->x_speed = initial_x_speed;
		a1->sprite->y_speed = initial_y_speed;
	}
}

//----- (00427BB0) --------------------------------------------------------
void entity_427BB0_mobile_outpost_clanhall_planting(Entity *a1)
{
    if (a1->unit_id == UNIT_STATS_SURV_OUTPOST) {
        sprite_4272E0_load_mobd_item(a1->sprite, 1232, 1);
    } else {
        sprite_4272E0_load_mobd_item(a1->sprite, 968, 1);
    }

	a1->SetMode(entity_mode_427BF0_mobile_outpost_clanhall_planting);
    script_sleep(a1->script, 30);
}

//----- (00427BF0) --------------------------------------------------------
void entity_mode_427BF0_mobile_outpost_clanhall_planting(Entity *a1)
{
    if (a1->unit_id == UNIT_STATS_SURV_OUTPOST) {
        sprite_4272E0_load_mobd_item(a1->sprite, 1232, 2);
    } else {
        sprite_4272E0_load_mobd_item(a1->sprite, 968, 2);
    }

	a1->SetMode(entity_427C30_after_mobile_outpost_clanhall_wagon_plant);
    script_sleep(a1->script, 30);
}

//----- (00427C30) --------------------------------------------------------
void entity_427C30_after_mobile_outpost_clanhall_wagon_plant(Entity *a1)
{
	Sprite *v4; // eax@1

	entity_40DDD0_boxd(a1);
	auto initial_unit_id = a1->unit_id;

	a1->unit_id = (UNIT_ID)a1->_134_param__unitstats_after_mobile_outpost_plant;
	v4 = spawn_unit(initial_unit_id, a1->sprite->x, a1->sprite->y, a1->player_side);
	if (v4)
	{
		if (initial_unit_id == UNIT_STATS_SURV_OUTPOST)
			v4->cplc_ptr1_pstru20 = &_468910_DataCplcItem_ptr1_stru20_outpost;
		else
			v4->cplc_ptr1_pstru20 = &_4688E0_DataCplcItem_ptr1_stru20_clanhall;
		v4->_80_entity__stru29__sprite__initial_hitpoints = (void *)a1->hitpoints;
	}

	a1->SetMode(entity_remove_unit_after_mobile_derrick_outpost_clanhall_plant);
    script_sleep(a1->script, 10);
}

//----- (00427CA0) --------------------------------------------------------
bool stru37_stru38_list_alloc(const int num_stru37s, const int num_stru38s)
{
    if (stru37_list = new stru37[num_stru37s]) {
        for (int i = 0; i < num_stru37s - 1; ++i)
        {
            stru37_list[i].next = &stru37_list[i + 1];
        }

        stru37_list[num_stru37s - 1].next = nullptr;
        stru37_list_free_pool = stru37_list;
        stru37_list_47A500 = (stru37 *)&stru37_list_47A500;
        stru37_list_47A504 = (stru37 *)&stru37_list_47A500;
    } else {
        return false;
    }


	if (stru38_list = new stru38[num_stru38s]) {
		for (int i = 0; i < num_stru38s - 1; ++i) {
            stru38_list[i].next = &stru38_list[i + 1];
		}

		stru38_list[num_stru38s - 1].next = nullptr;
        stru38_list_free_pool = stru38_list;
		stru38_list_47A4B0 = (stru38 *)&stru38_list_47A4B0;
		stru38_list_47A4B4 = (stru38 *)&stru38_list_47A4B0;

		return script_create_function(SCRIPT_TYPE_INVALID, script_4280A0_stru38_list__production_loop) != 0;
	}

    return false;
}

//----- (00427D60) --------------------------------------------------------
void stru37_list_427D60_enqueue_item(int *pcash, int *pcost, int cost_per_time_step, Script *production_task, void *production_task_param, int a6)
{
	stru37_list_427D80_enqueue_item(pcash, pcost, *pcost, cost_per_time_step, production_task, production_task_param, a6);
}

//----- (00427D80) --------------------------------------------------------
void stru37_list_427D80_enqueue_item(int *pcash, int *pcost, int cost, int cost_per_time_step, Script *production_task, void *production_task_param, int a7)
{
	stru37 *v7; // esi@1
	stru38 *v8; // ecx@6
	stru38 *v9; // eax@9
	stru37 *v10; // ecx@13
	stru38 *v11; // edx@13
	stru37 *v12; // eax@13

	v7 = stru37_list_free_pool;
	if (stru37_list_free_pool)
		stru37_list_free_pool = stru37_list_free_pool->next;
	else
		v7 = 0;
	if (v7)
	{
		v7->_14_pcost = pcost;
		v7->_18_pcash = pcash;
		v7->_28_production_task = production_task;
		v7->_C_cost_per_time_step = cost_per_time_step;
		v7->_8_cost_per_time_step = cost_per_time_step;
		v7->_10_cost = cost;
		v7->field_1C = 0;
		v7->_28_production_task_param = production_task_param;
		v7->_20_pcost_plus1 = 0;
		if (a7 == -1 || (v8 = stru38_list_47A4B0, (stru38 **)stru38_list_47A4B0 == &stru38_list_47A4B0))
		{
		LABEL_9:
			v9 = stru38_list_free_pool;
			if (stru38_list_free_pool)
				stru38_list_free_pool = stru38_list_free_pool->next;
			else
				v9 = 0;
			if (v9)
			{
				v10 = (stru37 *)&v9->pstru37;
				v9->field_34 = 0;
				v9->_C_pstru37 = (stru37 *)&v9->pstru37;
				v9->field_3C = a7;
				v10->next = v10;
				v9->field_40 = 1;
				v11 = stru38_list_47A4B0;
				v9->prev = (stru38 *)&stru38_list_47A4B0;
				v9->next = v11;
				stru38_list_47A4B0->prev = v9;
				stru38_list_47A4B0 = v9;
				v12 = v9->pstru37;
				v7->prev = v10;
				v7->next = v12;
				v10->next->prev = v7;
				v10->next = v7;
			}
		}
		else
		{
			while (v8->field_3C != a7)
			{
				v8 = v8->next;
				if ((stru38 **)v8 == &stru38_list_47A4B0)
					goto LABEL_9;
			}
			++v8->field_40;
			v7->next = v8->pstru37;
			v7->prev = (stru37 *)&v8->pstru37;
			v8->pstru37->prev = v7;
			for (v8->pstru37 = v7; (stru37 **)v7 != &v8->pstru37; v7 = v7->next)
				v7->_C_cost_per_time_step = v7->_8_cost_per_time_step / v8->field_40;
		}
	}
}

//----- (00427E90) --------------------------------------------------------
void stru37_list_427E90_enqueue_infantry(int *pcash, int *pcost, int cost_per_time_step, Script *production_task, void *production_task_param, int a6)
{
	stru37_list_427EB0_enqueue_infantry(
		pcash,
		pcost,
		*pcost,
		cost_per_time_step,
		production_task,
		production_task_param,
		a6);
}

//----- (00427EB0) --------------------------------------------------------
void stru37_list_427EB0_enqueue_infantry(int *pcash, int *pcost, int cost, int cost_per_time_step, Script *production_task, void *production_task_param, int a7)
{
	stru37 *v7; // esi@1
	stru38 *v8; // ecx@6
	stru38 *v9; // eax@9
	stru37 *v10; // ecx@13
	stru38 *v11; // edx@13
	stru37 *v12; // eax@13
	int v13; // eax@16

	v7 = stru37_list_free_pool;
	if (stru37_list_free_pool)
		stru37_list_free_pool = stru37_list_free_pool->next;
	else
		v7 = 0;
	if (v7)
	{
		v7->_14_pcost = pcost;
		v7->_18_pcash = pcash;
		v7->_10_cost = cost;
		v7->_20_pcost_plus1 = pcost + 1;
		v7->_C_cost_per_time_step = cost_per_time_step;
		v7->_8_cost_per_time_step = cost_per_time_step;
		v7->field_1C = 0;
		v7->_28_production_task = production_task;
		v7->_28_production_task_param = production_task_param;
		if (a7 == -1 || (v8 = stru38_list_47A4B0, (stru38 **)stru38_list_47A4B0 == &stru38_list_47A4B0))
		{
		LABEL_9:
			v9 = stru38_list_free_pool;
			if (stru38_list_free_pool)
				stru38_list_free_pool = stru38_list_free_pool->next;
			else
				v9 = 0;
			if (v9)
			{
				v10 = (stru37 *)&v9->pstru37;
				v9->field_34 = 0;
				v9->_C_pstru37 = (stru37 *)&v9->pstru37;
				v9->field_3C = a7;
				v10->next = v10;
				v9->field_40 = 1;
				v11 = stru38_list_47A4B0;
				v9->prev = (stru38 *)&stru38_list_47A4B0;
				v9->next = v11;
				stru38_list_47A4B0->prev = v9;
				stru38_list_47A4B0 = v9;
				v12 = v9->pstru37;
				v7->prev = v10;
				v7->next = v12;
				v10->next->prev = v7;
				v10->next = v7;
			}
		}
		else
		{
			while (v8->field_3C != a7)
			{
				v8 = v8->next;
				if ((stru38 **)v8 == &stru38_list_47A4B0)
					goto LABEL_9;
			}
			++v8->field_40;
			v7->next = v8->pstru37;
			v7->prev = (stru37 *)&v8->pstru37;
			v8->pstru37->prev = v7;
			for (v8->pstru37 = v7; (stru37 **)v7 != &v8->pstru37; v7 = v7->next)
			{
				v13 = v7->_8_cost_per_time_step / v8->field_40;
				v7->_C_cost_per_time_step = v13;
				if (v13 < 10)
					v7->_C_cost_per_time_step = 10;
			}
		}
	}
}

//----- (00427FD0) --------------------------------------------------------
void stru38_list_427FD0(int *pcost, int a2)
{
	stru38 *i; // esi@1
	stru37 *v3; // eax@2
	int v4; // eax@8
	stru38 *v5; // eax@9

	for (i = stru38_list_47A4B0; (stru38 **)i != &stru38_list_47A4B0; i = i->next)
	{
		v3 = i->pstru37;
		if ((stru37 **)v3 != &i->pstru37)
		{
			while (v3->_14_pcost != pcost)
			{
				v3 = v3->next;
				if ((stru37 **)v3 == &i->pstru37)
					goto LABEL_10;
			}
			if (a2)
				*v3->_18_pcash += v3->_10_cost - *v3->_14_pcost;
			v3->next->prev = v3->prev;
			v3->prev->next = v3->next;
			v3->next = stru37_list_free_pool;
			stru37_list_free_pool = v3;
			v4 = i->field_40 - 1;
			i->field_40 = v4;
			if (!v4)
			{
				v5 = i->prev;
				i->next->prev = v5;
				i->prev->next = i->next;
				i->next = stru38_list_free_pool;
				stru38_list_free_pool = i;
				i = v5;
			}
		}
	LABEL_10:
		;
	}
}

//----- (00428070) --------------------------------------------------------
void add_integer(int *a1, int a2)
{
	*a1 += a2;
}

//----- (00428080) --------------------------------------------------------
void stru37_stru38_list_free()
{
	free(stru37_list);
	free(stru38_list);
}

//----- (004280A0) --------------------------------------------------------
void script_4280A0_stru38_list__production_loop(Script *task)
{
	stru38 *v2; // edi@1
	stru37 *v3; // esi@2
	int v4; // ebp@2
	int *v5; // eax@3
	int *v6; // eax@10
	int v7; // ebx@14
	int *v8; // eax@16
	int *v9; // eax@20
	int v10; // ecx@20
	stru37 *v11; // eax@21
	int v12; // ecx@21
	stru38 *v13; // eax@22
	stru37 *j; // ecx@26
	stru37 *v15; // edx@31
	int v16; // eax@31
	stru37 *v17; // eax@32
	stru37 **v18; // ecx@33
	int v19; // eax@33
	stru38 *v20; // eax@34

	v2 = stru38_list_47A4B0;
	for (bool i = _44CDC0_sidebar_is_units_limit(); (stru38 **)v2 != &stru38_list_47A4B0; v2 = v2->next)
	{
		v3 = v2->pstru37;
		v4 = 0;
		if ((stru37 **)v3 != &v2->pstru37)
		{
			while (1)
			{
				v5 = v3->_18_pcash;
				if (v5 == (int *)((char *)&game_globals_per_player + 4 * player_side) && i && v3->_20_pcost_plus1)
					break;
				if (*v5)
				{
					v3->field_1C += v3->_C_cost_per_time_step;
					if (v3->field_1C >= 256)
					{
						if (*v3->_18_pcash)
						{
							while (*v3->_14_pcost > 0)
							{
								--*v3->_18_pcash;
								v6 = v3->_14_pcost;
								v3->field_1C -= 256;
								--*v6;
								if (!*v3->_14_pcost)
								{
									v7 = 0;
									if (v3->_28_production_task)
										script_trigger_event(
											task,
											EVT_MSG_PRODUCTION_READY,
											v3->_28_production_task_param,
											v3->_28_production_task);
									v8 = v3->_20_pcost_plus1;
									if (v8)
									{
										--*v8;
										if (*v3->_20_pcost_plus1 > 0)
											v7 = 1;
									}
									if (v7)
									{
										v9 = v3->_14_pcost;
										v10 = v3->_10_cost;
										v3->field_1C = 0;
										*v9 = v10;
									}
									else
									{
										v11 = v3->prev;
										v3->next->prev = v11;
										v3->prev->next = v3->next;
										v3->next = stru37_list_free_pool;
										stru37_list_free_pool = v3;
										v12 = v2->field_40 - 1;
										v2->field_40 = v12;
										if (v12)
										{
											v4 = 1;
											v3 = v11;
										}
										else
										{
											v13 = v2->prev;
											v3 = 0;
											v4 = 0;
											v2->next->prev = v13;
											v2->prev->next = v2->next;
											v2->next = stru38_list_free_pool;
											stru38_list_free_pool = v2;
											v2 = v13;
										}
									}
									break;
								}
								if (v3->field_1C < 256 || !*v3->_18_pcash)
									break;
							}
						}
					}
				}
				if (v3)
				{
					if (v4)
					{
						for (j = v2->pstru37; (stru37 **)j != &v2->pstru37; j = j->next)
							j->_C_cost_per_time_step = j->_8_cost_per_time_step / v2->field_40;
						v4 = 0;
					}
					v3 = v3->next;
					if ((stru37 **)v3 != &v2->pstru37)
						continue;
				}
				goto LABEL_35;
			}
			v15 = v3->prev;
			*v3->_20_pcost_plus1 = 0;
			*v3->_14_pcost = 0;
			v3->next->prev = v3->prev;
			v3->prev->next = v3->next;
			v3->next = stru37_list_free_pool;
			stru37_list_free_pool = v3;
			v16 = v2->field_40 - 1;
			v2->field_40 = v16;
			if (v16)
			{
				while (1)
				{
					v17 = v15;
					if ((stru37 **)v15 == &v2->pstru37)
						break;
					v18 = &v15->prev;
					v15 = v15->prev;
					*v17->_20_pcost_plus1 = 0;
					*v17->_14_pcost = 0;
					v17->next->prev = *v18;
					(*v18)->next = v17->next;
					v17->next = stru37_list_free_pool;
					stru37_list_free_pool = v17;
					v19 = v2->field_40 - 1;
					v2->field_40 = v19;
					if (!v19)
						goto LABEL_34;
				}
			}
			else
			{
			LABEL_34:
				v20 = v2->prev;
				v2->next->prev = v20;
				v2->prev->next = v2->next;
				v2->next = stru38_list_free_pool;
				stru38_list_free_pool = v2;
				v2 = v20;
			}
		}
	LABEL_35:
		;
	}
    script_sleep(task, 1);
}

//----- (00428730) --------------------------------------------------------
bool stru13construct_list_alloc()
{
	stru13construct *v0; // eax@1
	int v1; // ecx@2

	memset(num_units_in_group, 0, sizeof(num_units_in_group));
	v0 = (stru13construct *)malloc(0x400u);
	stru13construct_list = v0;
	if (v0)
	{
		stru13construct_list_free_pool = v0;
		v1 = 0;
		do
		{
			v0[v1].next = &v0[v1 + 1];
			v0 = stru13construct_list;
			++v1;
		} while (v1 < 31);
		stru13construct_list[31].next = 0;
		stru13construct_list_47A638 = (stru13construct *)&stru13construct_list_47A638;
		stru13construct_list_47A63C = (stru13construct *)&stru13construct_list_47A638;
        return true;
	}
    return false;
}

//----- (004287A0) --------------------------------------------------------
void stru13_list_free()
{
	free(stru13construct_list);
}

//----- (004287B0) --------------------------------------------------------
int stru13construct_list_get_saveload_packed_size()
{
	stru13construct *v0; // ecx@1
	int result; // eax@1

	v0 = stru13construct_list_47A638;
	for (result = 0; (stru13construct **)v0 != &stru13construct_list_47A638; result += 24)
		v0 = v0->next;
	return result;
}

//----- (004287D0) --------------------------------------------------------
bool stru13construct_list_saveload_pack(stru13constructSaveStruct *a1)
{
	stru13construct *v1; // eax@1
	char *v2; // ecx@2

	v1 = stru13construct_list_47A638;
	if ((stru13construct **)stru13construct_list_47A638 != &stru13construct_list_47A638)
	{
		v2 = (char *)&a1->field_8;
		do
		{
			*((_DWORD *)v2 - 2) = v1->field_8;
			*((_DWORD *)v2 - 1) = v1->field_C;
			*(_DWORD *)v2 = v1->field_10;
			*((_DWORD *)v2 + 1) = v1->_14_cost;
			*((_DWORD *)v2 + 2) = v1->_18_cost;
			*((_DWORD *)v2 + 3) = v1->_1C_cost_per_time_step;
			v1 = v1->next;
			v2 += 24;
		} while ((stru13construct **)v1 != &stru13construct_list_47A638);
	}
	return 1;
}

//----- (00428820) --------------------------------------------------------
bool stru13construct_list_saveload_unpack(int save_data, int save_data_size)
{
	int v2; // ebx@1
	int v3; // esi@2
	stru13construct *v4; // eax@3
	stru13construct *v5; // edx@7
	int v6; // ecx@7

	v2 = save_data_size;
	if (save_data_size)
	{
		v3 = save_data + 8;
		while (1)
		{
			v4 = stru13construct_list_free_pool;
			if (stru13construct_list_free_pool)
				stru13construct_list_free_pool = stru13construct_list_free_pool->next;
			else
				v4 = 0;
			if (!v4)
				break;
			v5 = stru13construct_list_47A638;
			v4->prev = (stru13construct *)&stru13construct_list_47A638;
			v4->next = v5;
			stru13construct_list_47A638->prev = v4;
			stru13construct_list_47A638 = v4;
			v4->field_8 = *(_DWORD *)(v3 - 8);
			v4->field_C = *(_DWORD *)(v3 - 4);
			v4->field_10 = *(_DWORD *)v3;
			v4->_14_cost = *(_DWORD *)(v3 + 4);
			v4->_1C_cost_per_time_step = *(_DWORD *)(v3 + 12);
			v6 = *(_DWORD *)(v3 + 8);
			v4->_18_cost = v6;
			if (v6)
				stru37_list_427D80_enqueue_item(
				(int *)&game_globals_per_player + v4->field_C,
					&v4->_18_cost,
					v4->_14_cost,
					v4->_1C_cost_per_time_step,
					0,
					0,
					-1);
			v3 += 24;
			v2 -= 24;
			if (!v2)
				return true;
		}
		return false;
	}
    return true;
}

//----- (004288D0) --------------------------------------------------------
bool is_building_or_tower_available(enum UNIT_ID unit_id)
{
	enum UNIT_ID v1; // esi@1

	v1 = unit_id;
	if ((int)unit_id < (int)UNIT_STATS_SURV_GUARD_TOWER
		|| (int)unit_id >(int)UNIT_STATS_MUTE_ROTARY_CANNON)
	{
		if (is_player_faction_evolved())
		{
			if (is_building_available(v1))
				return 1;
		}
		else if (is_building_available(v1))
		{
			return 1;
		}
	}
	else if (is_player_faction_evolved())
	{
		if (is_tower_available(v1))
			return 1;
	}
	else if (is_tower_available(v1))
	{
		return 1;
	}
	return 0;
}

//----- (0042C810) --------------------------------------------------------
bool sub_42C810(Sprite **sprite_list, int x, int y, int a4, int map_x, int a6, int a7)
{
	int v7; // ebx@1
	int v8; // ecx@1
	int v9; // edi@1
	int v10; // edx@1
	int v11; // ebp@2
	int v12; // esi@3
	Entity *v13; // eax@4
	int v14; // ecx@6
	enum UNIT_ID v15; // eax@10
	int v16; // eax@17
	int v17; // ebp@18
	int v18; // edi@19
	Sprite **v19; // esi@20
	int v21; // [sp+10h] [bp-14h]@1
	bool v22; // [sp+14h] [bp-10h]@1
	int v23; // [sp+18h] [bp-Ch]@1
	Sprite **v24; // [sp+20h] [bp-4h]@1
	int a3a; // [sp+28h] [bp+4h]@1
	int a4a; // [sp+2Ch] [bp+8h]@20
	int map_xa; // [sp+30h] [bp+Ch]@2

	v24 = sprite_list;
	v7 = y >> 13;
	v9 = (y >> 13) - 4;
	v22 = true;
	v21 = 0;
	v10 = x >> 13;
	v23 = v10;
	a3a = (y >> 13) + map_x;
	v8 = a3a;
	if (v9 < a3a + 3)
	{
		map_xa = v10 - 3;
		v11 = v10 + a4 + 3;
		do
		{
			v12 = map_xa;
			if (map_xa < v11)
			{
				while (1)
				{
					v13 = boxd_40EE10_prolly_get_building(v12, v9);
					if (v13)
					{
						if (v13->player_side == player_side)
						{
							v14 = v13->unit_id;
							if (v14 < (int)UNIT_STATS_SURV_GUARD_TOWER || v14 >(int)UNIT_STATS_MUTE_ROTARY_CANNON)
								break;
						}
					}
					if (++v12 >= v11)
						goto LABEL_15;
				}
				v15 = v13->unit_id;
				if (v15 != UNIT_STATS_SURV_DRILL_RIG && v15 != UNIT_STATS_MUTE_DRILL_RIG
					|| a6 >= (int)UNIT_STATS_SURV_GUARD_TOWER && a6 <= (int)UNIT_STATS_MUTE_ROTARY_CANNON)
				{
					v21 = 1;
				}
			}
		LABEL_15:
			++v9;
		} while (v9 < a3a + 3);
		v10 = v23;
		v8 = a3a;
	}
	v16 = 0;
	if (v7 < v8)
	{
		v17 = v10 + a4;
		do
		{
			v18 = v10;
			if (v10 < v17)
			{
				v19 = &v24[v16];
				a4a = v17 - v10 + v16;
				do
				{
					if (a7)
					{
						v22 = false;
						(*v19)->drawjob->flags |= 0x40000000u;
					}
					else
					{
						(*v19)->drawjob->flags &= 0xBFFFFFFF;
						if (boxd_40EE70(v18, v7) && v21)
						{
							sprite_load_mobd(*v19, 560);
						}
						else
						{
							sprite_load_mobd(*v19, 548);
							v22 = false;
						}
						(*v19)->field_88_unused = 1;
						(*v19)->x = v18 << 13;
						(*v19)->field_88_unused = 1;
						(*v19)->y = v7 << 13;
					}
					++v18;
					++v19;
				} while (v18 < v17);
				v10 = v23;
				v16 = a4a;
				v8 = a3a;
			}
			++v7;
		} while (v7 < v8);
	}
	return v22;
}

//----- (0042C9C0) --------------------------------------------------------
void sub_42C9C0(Sprite **sprite_list)
{
	Sprite **v1; // esi@1
	int v2; // edi@1

	v1 = sprite_list;
	v2 = 20;
	do
	{
		sprite_list_remove(*v1);
		++v1;
		--v2;
	} while (v2);
}

//----- (0042D030) --------------------------------------------------------
void script_42D030_sidebar_tooltips(Script *a1)
{
	const char *v1; // edi@2
	int v2; // esi@2
	void *v3; // ebx@2
	ScriptEvent *i; // eax@3
	int v5; // eax@9
	int v6; // eax@10
	int v7; // edx@13
	int v8; // eax@18
	int v9; // esi@23
	int v10; // eax@23
	RenderString *v11; // esi@23
	int v12; // edi@23
	ScriptEvent *j; // eax@24
	int v14; // [sp+10h] [bp-54h]@2
	char v15[80]; // [sp+14h] [bp-50h]@21

	dword_47A5A0 = 10;
	_47A734_sidebar_tooltips_task = a1;
	while (1)
	{
		v1 = 0;
		v2 = 0;
		v3 = 0;
		v14 = 0;
		do
		{
            script_wait_event(a1);
			for (i = script_get_next_event(a1); i; i = script_get_next_event(a1))
			{
				if (i->event == EVT_MSG_SELECTED)
				{
					v3 = i->param;
					v2 = 1;
				}
				script_discard_event(i);
			}
		} while (!v2);
		if (v3)
		{
			v5 = *((_DWORD *)v3 + 2);
			if (v5)
			{
				v6 = *(_DWORD *)(v5 + 60);
				if (v6 >= 0)
				{
					v7 = 1;
					if (v6 == 87)
					{
                        // _447310_minimap inlined?
						if (*(DataMobdItem **)(*((_DWORD *)v3 + 9) + 76) == &currently_running_lvl_mobd[*(_DWORD *)(*((_DWORD *)v3 + 9) + 12)].items[165])
							v7 = 0;
						v1 = 0;
					}
					if (v7)
					{
						v8 = v6;
						v1 = unit_stats[v8].name;
						v14 = unit_stats[v8].cost;
					}
				}
				else if (v6 >= -11)
				{
					v1 = sidebar_category_labels[-v6 - 1];
				}
			}
		}
		if (v1)
		{
			if (v14)
				sprintf(v15, aSD, v1, v14);
			else
				strcpy(v15, v1);
			v9 = _445C00_text(v15, 40);
			v10 = _445C80_text(v15, 40);
			*(_DWORD *)(*((_DWORD *)v3 + 9) + 136) = 1;
			v11 = render_string_create(
				0,
				currently_running_lvl_mobd[MOBD_FONT_27].items,
				(*(_DWORD *)(*((_DWORD *)v3 + 9) + 16) >> 8) - (8 * v10 + 8),
				(*(_DWORD *)(*((_DWORD *)v3 + 9) + 20) >> 8) + 22,
				v10 + 2,
				v9 + 2,
				0x20000005,
				8,
				8);
			v12 = 0;
			v11->field_18 = 0;
			v11->num_lines = 0;
			render_string_445770(v11, v15, 0);
			do
			{
                script_wait_event(a1);
				for (j = script_get_next_event(a1); j; j = script_get_next_event(a1))
				{
					if (j->event == EVT_MSG_DESELECTED)
						v12 = 1;
					script_discard_event(j);
				}
			} while (!v12);
			render_string_list_remove(v11);
		}
	}
}
// 47A5A0: using guessed type int dword_47A5A0;

//----- (0042D220) --------------------------------------------------------
void _41AC50_read_keyboard_input___42D220_handler(const char *a1, int a2)
{
	const char *v2; // esi@1

	v2 = a1;
	render_string_445AE0(_47A730_render_string);
	_47A730_render_string->field_18 = 0;
	_47A730_render_string->num_lines = 0;
	render_string_42D260(_47A730_render_string, v2, 0);
}

//----- (0042D260) --------------------------------------------------------
char render_string_42D260(RenderString *a1, const char *a2, DataMobdItem *a3)
{
	RenderString *v3; // edi@1
	const char *v4; // ebx@1
	DrawJob *v5; // ecx@1
	int v6; // eax@1
	int v7; // ebp@1
	int v8; // esi@1
	int v9; // ecx@5
	stru8 *v10; // ecx@6
	int v11; // edx@6
	int v12; // ebp@6
	int v13; // eax@6
	int v14; // edx@6
    DataMobdItem_stru0 *v15; // eax@12
    DataMobdItem_stru1 *v16; // eax@14
	bool v17; // zf@17
	int v19; // [sp+10h] [bp-Ch]@2
	int v20; // [sp+14h] [bp-8h]@6
	int v21; // [sp+18h] [bp-4h]@1

	v3 = a1;
	v4 = a2;
	v5 = a1->pstru8->drawjob;
	LOBYTE_HEXRAYS(v6) = *a2;
	v7 = v5->job_details.x + 8;
	v21 = v5->job_details.x + 8;
	v8 = v5->job_details.x + 8;
	while (*v4)
	{
		v6 = _443D60_strlen_before_newline(v4);
		v19 = v6;
		if (!v6)
			v19 = 1;
		if (*v4 == 10)
		{
			v8 = v7;
			v9 = v3->num_lines + 1;
			v3->field_18 = 0;
			v3->num_lines = v9;
			++v4;
		}
		else
		{
			v10 = v3->pstru8;
			v11 = v3->num_lines + 1;
			v12 = v3->field_18;
			v20 = v10->drawjob->job_details.y + 8 * v11;
			v13 = v11 * v3->field_C;
			v14 = v13 + v12 + 1;
			if (v13 + v12 != -1)
			{
				do
				{
					v10 = v10->next;
					--v14;
				} while (v14);
			}
			if (v12 > 1)
				v8 = v10->drawjob->job_details.x;
			LOBYTE_HEXRAYS(v6) = v19;
			if (v19)
			{
				do
				{
					if (a3)
						v15 = a3->_[*v4 + 1];
					else
						v15 = v3->mobd_font__see_sub405A60->_[1 + *v4];
					v10->drawjob->job_details.image = v15->sprt;
					v10->drawjob->job_details.y = v20 - v15->y_offset;
					v10->drawjob->job_details.x = v8 - v15->x_offset;
					v16 = v15->field_18;
					if (v16)
						v8 = v10->drawjob->job_details.x + (v16->x_offset >> 8);
					else
						v8 = v10->drawjob->job_details.x + 8;
					v10 = v10->next;
					++v4;
					v10->drawjob->job_details.x = v8;
					LOBYTE_HEXRAYS(v6) = v19 - 1;
					v17 = v19 == 1;
					++v3->field_18;
					--v19;
				} while (!v17);
			}
			v7 = v21;
		}
	}
	return v6;
}

//----- (0042D390) --------------------------------------------------------
void script_42D390_cursors(Script *a1)
{
	RenderString *v1; // eax@1
	void *v6; // eax@4
	int v7; // edx@4
	int v8; // ecx@4
	unsigned int v9; // kr04_4@4
	bool v10; // zf@5
	char v11[56]; // [sp+Ch] [bp-38h]@4

	memset(byte_47A5A8, 0, sizeof(byte_47A5A8));
	v1 = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_27].items, 144, 304, 42, 3, 0x20000005, 8, 8);
	_47A730_render_string = v1;
	if (!v1)
	{
		script_terminate(a1);
		v1 = _47A730_render_string;
	}
	render_string_445AE0(v1);
	_47A730_render_string->field_18 = 0;
	_47A730_render_string->num_lines = 0;
	render_string_42D260(_47A730_render_string, byte_47A5A8, 0);
	if (input_get_string(byte_47A5A8, 0x26u, _41AC50_read_keyboard_input___42D220_handler, 1, a1))
	{
        strcpy(v11, byte_47A5A8);

		v6 = __47CA80_array_idx_and_netz_player_side;
		v7 = 8 * (_DWORD)__47CA80_array_idx_and_netz_player_side;

		sprintf(byte_47A5A8, aSS_1, &netz_47A740[2].player_name[4 * (v7 - (_DWORD)v6)], v11);
		v9 = strlen(byte_47A5A8) + 1;
		v8 = v9 - 1;
		if (v9 != 1)
		{
			v10 = netz_47A834 == 0;
			byte_47A5A8[v8 + 1] = _468A58_sound_id;
			if (v10)
				netz_44A220(73, byte_47A5A8, v8 + 2);
			else
				netz_44A160(73, byte_47A5A8, v8 + 2);
			show_message(byte_47A5A8);
		}
	}
	render_string_list_remove(_47A730_render_string);
	_47A730_render_string = 0;
	script_terminate(a1);
}
// 42D390: using guessed type char var_38[56];


//----- (0042D560) --------------------------------------------------------
int _42D560_get_mobd_lookup_id_rotation(int x, int y)
{
	int result; // eax@4
	int v3; // edx@13
	int v4; // ecx@19
	int v5; // edx@23

    // 0 north
    // 64 east
    // 128 south
    // 192 west

	if (x)
	{
        if (!y)
        {
            if (x < 0)
            {
                return 192; // x < 0, y = 0 - west
            }
            else
            {
                return 64; // x > 0, y = 0 - east
            }
        }
        else
        {
			if (x < 0)
			{
				v4 = -x;
				if (y < 0)
				{
					v5 = -y;
					if (v4 < -y)
						return -_42D639_mobd_lookup(v4, v5) & 0xFF;
					else
						return _42D63B_mobd_do_lookup(v4, v5) + 192;
				}
				else if (v4 > y)
				{
					return 192 - _42D63B_mobd_do_lookup(v4, y);
				}
				else
				{
					return _42D639_mobd_lookup(v4, y) + 128;
				}
			}
			else if (y > 0)
			{
				if (x < y)
					return 128 - _42D639_mobd_lookup(x, y);
				else
					return _42D63B_mobd_do_lookup(x, y) + 64;
			}
			else
			{
				v3 = -y;
				if (x > -y)
					return 64 - _42D63B_mobd_do_lookup(x, v3);
				else
					return _42D639_mobd_lookup(x, v3);
			}
		}
	}
	else if (y)
	{
		if (y < 0)
			return 0; // x = 0, y < 0 - north
		else
			return 128; // x = 0, y > 0 - south
	}
	else
	{
        return 0;
	}
}

//----- (0042D639) --------------------------------------------------------
__int16 _42D639_mobd_lookup(int x, int y)
{
    return _42D63B_mobd_do_lookup(y, x);
}

//----- (0042D63B) --------------------------------------------------------
__int16 _42D63B_mobd_do_lookup(int x, int y)
{
	return _468A6C_mobd_lookups[(unsigned int)(y << 6) / (signed __int64)x];
}

//----- (0042D64D) --------------------------------------------------------
int math_42D64D_vec_length_2d(int x, int y)
{
    return math_42D669_sqrt(x * x + y * y);
}

//----- (0042D669) --------------------------------------------------------
unsigned int math_42D669_sqrt(unsigned int a1)
{
	unsigned int v1; // ecx@0
	unsigned int result; // eax@1
	unsigned int v3; // ecx@2
	unsigned int v4; // ebx@2
	int v5; // edx@2
	unsigned int v6; // edi@4

	result = a1;
	if (a1 >= 2)
	{
		_BitScanReverse((unsigned long *)&v1, a1);
		v3 = v1 >> 1;
		result = 1 << v3;
		v4 = 1 << v3;
		v5 = 1 << v3 << v3;
		while ((--v3 & 0x80000000) == 0)
		{
			v4 >>= 1;
			v6 = v5 + ((v4 + 2 * result) << v3);
			if (v6 <= a1)
			{
				result += v4;
				v5 = v6;
			}
		}
	}
	return result;
}

//----- (0042DE80) --------------------------------------------------------
void script_42DE80(Script *a1)
{
	stru24 *v1; // ebx@1
	stru24_AttackerNode *v2; // eax@1
	stru24_AttackerNode **v3; // edi@1
	stru24_AttackerNode *v4; // esi@3
	Entity *v5; // edi@4
	stru24_AttackerNode **v6; // ebp@4

	v1 = (stru24 *)a1->param;
	v2 = v1->attacker_list_48;
	v3 = &v1->attacker_list_48;
	if ((stru24_AttackerNode **)v2 != &v1->attacker_list_48)
	{
		if (entity_find_player_entity_in_radius(v2->entity, 300 * 256))
		{
			v4 = *v3;
			if ((stru24_AttackerNode **)*v3 != v3)
			{
				do
				{
					v5 = v4->entity;
					v6 = &v4->prev->next;
					entity_4258C0_init_palettes_inc_unit_counter(v4->entity, player_side);
					script_trigger_event_group(v5->script, EVT_MSG_1521_entity_created, v5, SCRIPT_TYPE_39030);
					entity_mode_adjust_unit_placement_inside_tile(v5);
					v4->next->prev = v4->prev;
					v4->prev->next = v4->next;
					v4->next = v1->attacker_list_free_pool;
					v1->attacker_list_free_pool = v4;
					v4 = *v6;
				} while ((stru24_AttackerNode **)*v6 != &v1->attacker_list_48);
			}
		}
	}
	stru24_42E070(v1);
    script_sleep(a1, 60);
}

//----- (0042DF20) --------------------------------------------------------
void script_42DF20(Script *a1)
{
	a1->handler = script_42DE80;
    script_sleep(a1, 60);
}

//----- (0042DF40) --------------------------------------------------------
Entity *stru24_42DF40(stru24 *a1, Entity *a2, int *a3)
{
	Entity *v3; // ebp@1
	Sprite *v4; // esi@1
	int v5; // eax@1
	int v6; // edx@1
	stru24 *v7; // ebx@2
	Entity *v8; // ecx@5
	Sprite *v9; // ecx@7
	int v10; // esi@7
	int v11; // esi@7
	bool v12; // zf@7
	bool v13; // sf@7
	Sprite *v14; // esi@7
	int v15; // ecx@8
	int v16; // esi@10
	int v17; // ebp@10
	int v18; // ecx@12
	int v20; // [sp+10h] [bp-10h]@1
	Entity *v21; // [sp+14h] [bp-Ch]@1
	Entity *v22; // [sp+18h] [bp-8h]@1
	char *v23; // [sp+1Ch] [bp-4h]@2

	v3 = a2;
	v22 = a2;
	v21 = 0;
	a2->sprite->field_88_unused = 1;
	v4 = a2->sprite;
	v5 = v4->x;
	v20 = v4->y;
	v6 = 0x7FFFFFFF;
	if (v3->unit_id != 19)
	{
		v7 = (stru24 *)a1->enemy_list_108;
		v23 = (char *)&a1->enemy_list_108;
		if ((stru24_EnemyNode **)v7 != &a1->enemy_list_108)
		{
			while (1)
			{
				v8 = v7->_8_entity;
				if (!v8->destroyed && v8->player_side != v3->player_side)
				{
					v8->sprite->field_88_unused = 1;
					v9 = v7->_8_entity->sprite;
					v10 = v9->x;
					v9->field_88_unused = 1;
					v11 = v10 - v5;
					v12 = v11 == 0;
					v13 = v11 < 0;
					v14 = v7->_8_entity->sprite;
					if (v13 || v12)
						v15 = v5 - v14->x;
					else
						v15 = v14->x - v5;
					v16 = v14->y;
					v17 = v16 - v20;
					if (v16 - v20 <= 0)
						v17 = v20 - v16;
					v18 = v17 + v15;
					if (v18 < v6)
					{
						v6 = v18;
						v21 = v7->_8_entity;
					}
				}
				v7 = v7->next;
				if ((char *)v7 == v23)
					break;
				v3 = v22;
			}
		}
	}
	*a3 = v6;
	return v21;
}

//----- (0042E030) --------------------------------------------------------
void stru24_42E030(stru24 *a1, Entity *a2)
{
	Entity *v2; // esi@1
	stru24 *v3; // edi@1
	Entity *v4; // eax@1
	int v5; // ecx@2
	Script *v6; // edx@2
	int v7; // [sp+8h] [bp-Ch]@1
	int v8; // [sp+Ch] [bp-8h]@2
	Entity *v9; // [sp+10h] [bp-4h]@2

	v2 = a2;
	v3 = a1;
	v4 = stru24_42DF40(a1, a2, &v7);
	if (v4)
	{
		v5 = v3->_2A0_player_side;
		v6 = v2->script;
		v9 = v4;
		v8 = v5;
		script_trigger_event(0, EVT_CMD_ENTITY_ATTACK, &v8, v6);
	}
}

//----- (0042E070) --------------------------------------------------------
void stru24_42E070(stru24 *a1)
{
	stru24 *v1; // ebp@1
	stru24_WandererNode *v2; // esi@1
	char *v3; // ebx@1
	Entity *v4; // edi@2
	int v5; // eax@2
	int v6; // eax@7
	stru24_WandererNode *v7; // ecx@9
	stru24_stru40 *i; // edi@11
	Entity *v9; // esi@12
	Entity *v10; // eax@15
	int a3; // [sp+10h] [bp-Ch]@4
    _47CAF0_task_attachment1_attack_task v14;

	v1 = a1;
	v2 = a1->wanderer_list_18;
	v3 = (char *)&a1->wanderer_list_18;
	if ((stru24_WandererNode **)v2 != &a1->wanderer_list_18)
	{
		do
		{
			v4 = v2->entity;
			v5 = v4->_12C_prison_bunker_spawn_type;
			if (v5)
			{
				if (v5 & 1 && stru24_42DF40(v1, v2->entity, &a3) && a3 < 51200)
					v4->_12C_prison_bunker_spawn_type = 1;
				v6 = v4->_12C_prison_bunker_spawn_type - 1;
				v4->_12C_prison_bunker_spawn_type = v6;
				if (!v6 && v4->unit_id != 19)
				{
					v7 = v2->prev;
					v2->next->prev = v7;
					v2->prev->next = v2->next;
					v2->next = (stru24_WandererNode *)v1->list_40_30;
					v2->prev = (stru24_WandererNode *)&v1->list_40_30;
					v1->list_40_30->prev = (stru24_stru40 *)v2;
					v1->list_40_30 = (stru24_stru40 *)v2;
					v2 = v7;
				}
			}
			v2 = v2->next;
		} while ((char *)v2 != v3);
	}
	for (i = v1->list_40_30; (stru24_stru40 **)i != &v1->list_40_30; i = i->next)
	{
		v9 = i->_C__entity;
		if (!v9->entity_8 && !v9->retaliation_target || v9->IsMode(entity_mode_default_idle))
		{
			v10 = stru24_42DF40(v1, i->_C__entity, &a3);
			if (v10)
			{
				v14.player_side = v1->_2A0_player_side;
                v14.target = v10;
				script_trigger_event(0, EVT_CMD_ENTITY_ATTACK, &v14, v9->script);
			}
		}
	}
}

//----- (00430F10) --------------------------------------------------------
void _430F10_unit_inits()
{
	memset(&_47B3E0_outpost_levels, 0, sizeof(_47B3E0_outpost_levels));
	_47B3E0_unit_int_outpost_clanhall = 0;
	_47B3D0_building_production_group = 0;
	_47B3B8_tower_production_group = 0;
	_47B3D4_aircraft_production_group = 0;
	memset(&_477378_clanhall, 0, sizeof(_477378_clanhall));
	_47B3C0_player_outposts_clanhalls[0] = 0;
	_47B3C0_player_outposts_clanhalls[1] = 0;
	max_outpost_level = 1;
	_47B3C0_player_outposts_clanhalls[2] = 0;
	max_clanhall_level = 1;
	_47B3C0_player_outposts_clanhalls[3] = 0;
}

//----- (00430F70) --------------------------------------------------------
void entity_register_player_main_building(Entity *a1)
{
	int v1; // edx@1
	Entity **v2; // eax@1

	v1 = 0;
	v2 = _47B3C0_player_outposts_clanhalls;
	while (*v2)
	{
		++v2;
		++v1;
		if ((int)v2 >= (int) & _47B3D0_building_production_group)
			return;
	}
	_47B3C0_player_outposts_clanhalls[v1] = a1;
}

//----- (00430F90) --------------------------------------------------------
void entity_430F90_clanhall(Entity *a1)
{
	ProductionGroup *v1; // esi@1
	int v2; // edx@2
	Entity **v3; // eax@2
	int v4; // ecx@7
	Entity **v5; // eax@7

	v1 = _47B3D4_aircraft_production_group;
	if (a1 == _47B3D4_aircraft_production_group->_C_entity)
	{
		v2 = 0;
		v3 = _47B3C0_player_outposts_clanhalls;
		while (*v3 != a1)
		{
			++v3;
			++v2;
			if ((int)v3 >= (int) & _47B3D0_building_production_group)
				goto LABEL_7;
		}
		_47B3C0_player_outposts_clanhalls[v2] = 0;
	LABEL_7:
		v4 = 0;
		v5 = _47B3C0_player_outposts_clanhalls;
		while (!*v5)
		{
			++v5;
			++v4;
			if ((int)v5 >= (int) & _47B3D0_building_production_group)
				return;
		}
		v1->_C_entity = _47B3C0_player_outposts_clanhalls[v4];
		_47B3D4_aircraft_production_group->outpost_clanhall = _47B3C0_player_outposts_clanhalls[v4];
	}
}

//----- (00431000) --------------------------------------------------------
int get_max_outpost_level()
{
	return max_outpost_level;
}
// 47B404: using guessed type int max_outpost_level;

//----- (00431010) --------------------------------------------------------
bool is_outpost_maxed()
{
	return max_outpost_level >= 5;
}
// 47B404: using guessed type int max_outpost_level;

//----- (00431020) --------------------------------------------------------
void entity_outpost_on_upgrade_complete(Script *receiver, Script *sender, enum SCRIPT_EVENT message, void *param)
{
	Script *v4; // ebp@1
	Entity *v5; // ebx@1
	EntityBuildingState *v6; // eax@1
	ProductionGroup *v7; // edi@1
	int new_building_level; // ecx@1
	int can_unlock_towers; // esi@4
	unsigned int v10; // ecx@10
	enum LEVEL_ID v11; // eax@12
	unsigned int v12; // ecx@17
	enum LEVEL_ID v13; // eax@19
	unsigned int v14; // eax@22
	int v15; // eax@26
	Script *a2a; // [sp+10h] [bp-4h]@1

	v4 = receiver;
	a2a = sender;
	v5 = (Entity *)receiver->param;
	v6 = (EntityBuildingState *)v5->state;
	v7 = v6->production_group;
	new_building_level = v6->num_upgrades + 1;
	v6->num_upgrades = new_building_level;
	if (new_building_level > 5)
		v6->num_upgrades = 5;
	if (v5->player_side == player_side)
	{
		can_unlock_towers = 0;
		--__47B3E0_outpost_levels_negindex[v6->num_upgrades];
		++_47B3E0_outpost_levels.num_buildings_by_level[v6->num_upgrades];
		if (v6->num_upgrades > max_outpost_level)
		{
			max_outpost_level = v6->num_upgrades;
			can_unlock_towers = 1;
		}
		switch (v6->num_upgrades)
		{
		case 2:
			if (!(levels[current_level_idx].disabled_units_mask & 0x200000))
				production_group_enable(v7, UNIT_STATS_SURV_FLAMER, 2880);
			if (can_unlock_towers)
			{
				sub_447000();
				v10 = levels[current_level_idx].disabled_units_mask;
				if (!(BYTE1(v10) & 8))
					production_group_enable(_47B3B8_tower_production_group, UNIT_STATS_SURV_GUARD_TOWER, 2400);
			}
			break;
		case 3:
			v11 = current_level_idx;
			if (!(levels[current_level_idx].disabled_units_mask & 0x400000))
			{
				production_group_enable(v7, UNIT_STATS_SURV_SABOTEUR, 2856);
				v11 = current_level_idx;
			}
			if (!(levels[v11].disabled_units_mask & 0x800000))
			{
				production_group_enable(v7, UNIT_STATS_SURV_SAPPER, 2864);
				v11 = current_level_idx;
			}
			if (can_unlock_towers)
			{
				v12 = levels[v11].disabled_units_mask;
				if (!(BYTE1(v12) & 1))
					production_group_enable(_47B3B8_tower_production_group, UNIT_STATS_SURV_MISSILE_BATTERY, 2384);
			}
			break;
		case 4:
			v13 = current_level_idx;
			if (!(levels[current_level_idx].disabled_units_mask & 0x1000000))
			{
				production_group_enable(v7, UNIT_STATS_SURV_RPG_LAUNCHER, 2840);
				v13 = current_level_idx;
			}
			if (can_unlock_towers)
			{
				v14 = levels[v13].disabled_units_mask;
				if (!(BYTE1(v14) & 2))
					production_group_enable(_47B3B8_tower_production_group, UNIT_STATS_SURV_CANNON_TOWER, 2392);
			}
			break;
		case 5:
			if (!(levels[current_level_idx].disabled_units_mask & 0x2000000))
				production_group_enable(v7, UNIT_STATS_SURV_SNIPER, 2832);
			LOBYTE_HEXRAYS(v15) = is_machine_shop_maxed();
			if (v15)
				attempt_unlock_aircraft();
			break;
		default:
			break;
		}
	}
	entity_4109A0_status_bar(v5);
	EventHandler_DefaultBuildingsHandler(v4, a2a, message, param);
}

//----- (00431270) --------------------------------------------------------
void EventHandler_Outpost(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param)
{
	Entity *v4; // esi@1

	v4 = (Entity *)receiver->param;
	if (!v4->destroyed)
	{
		switch (event)
		{
		case EVT_MSG_DESTROY:
			entity_402E40_destroy((Entity *)receiver->param, entity_mode_outpost_on_death);
			break;
		case EVT_MSG_PRODUCTION_READY:            // param = unit_stats_idx
			if (param == (void *)UNIT_STATS_SURV_BOMBER)// Bomber
			{
				if (v4->player_side == player_side)
				{
					show_message_ex(0, aAirStrikeReady);
					on_airstrike_ready();
				}
			}
			else
			{
				v4->sprite->field_88_unused = 1;
				if (spawn_unit(
					(enum UNIT_ID)(int)param,
					v4->sprite->x + v4->stru60.pstru4->x_offset,
					v4->sprite->y + v4->stru60.pstru4->y_offset,
					v4->player_side))
				{
					if (v4->player_side == player_side)
					{
						sound_play(SOUND_SURV_UNIT_READY, 0, _4690A8_unit_sounds_volume, 16, 0);
						show_message_ex(0, aUnitReady);
					}
				}
				else
				{
					show_message_ex(0, aCouldntCreateNewUnit);
				}
			}
			break;
		case CMD_APPLY_DAMAGE:
			entity_402E90_on_damage(v4, param, entity_mode_outpost_on_death);
			entity_410520_update_healthbar_color(v4);
			break;
		case EVT_MSG_SABOTAGE:
			entity_sabotage(v4, param, entity_mode_outpost_on_death);
			break;
		case EVT_MSG_UPGRADE_COMPLETE:
			entity_outpost_on_upgrade_complete(receiver, sender, event, param);
			break;
		default:
			EventHandler_DefaultBuildingsHandler(receiver, sender, event, param);
			break;
		}
	}
}

//----- (00431410) --------------------------------------------------------
void entity_mode_outpost_enable_basic_construction(Entity *a1)
{
	Entity *v1; // edi@1
	EntityBuildingState *v2; // esi@2
	enum LEVEL_ID v3; // eax@7
	int *v4; // esi@7

	v1 = a1;
	if (player_side == a1->player_side)
	{
		v2 = (EntityBuildingState *)a1->state;
		v2->same_buildings_count = 0;
		script_trigger_event_group(a1->script, EVT_MSG_BUILDING_COMPLETE, 0, SCRIPT_SURV_OUTPOST_HANDLER);
		if (!v2->same_buildings_count)
		{
			if (!_47B3E0_unit_int_outpost_clanhall && !_47B3D0_building_production_group)
				_47B3D0_building_production_group = entity_building_create_production_group(v1, PRODUCTION_GROUP_BUILDINGS);
			if (!_47B3B8_tower_production_group)
			{
				_47B3B8_tower_production_group = entity_building_create_production_group(v1, PRODUCTION_GROUP_TOWERS);
				v3 = current_level_idx;
				v4 = &surv_basic_buildings[0].mobd_lookup_table_offset;
				do
				{
					if (!(levels[v3].disabled_units_mask & *(v4 - 2)))
					{
						production_group_enable(_47B3D0_building_production_group, (enum UNIT_ID)*(v4 - 1), *v4);
						v3 = current_level_idx;
					}
					v4 += 3;
				} while ((int)v4 < (int)&surv_basic_infantry[0].unit_stats_idx);
				if (!_47B3D4_aircraft_production_group)
					_47B3D4_aircraft_production_group = entity_building_create_production_group(v1, PRODUCTION_GROUP_AIRCRAFT);
				max_outpost_level = 1;
				memset(&_47B3E0_outpost_levels, 0, sizeof(_47B3E0_outpost_levels));
			}
		}
	}
}

//----- (00431500) --------------------------------------------------------
void UNIT_Handler_Outpost(Script *a1)
{
	Entity *v1; // esi@1
	int v2; // ecx@4
	Entity **v3; // eax@4
	void *v4; // eax@12

	v1 = (Entity *)a1->param;
	if (!_47C6DC_dont_execute_unit_handlers)
	{
		if (!v1)
		{
			v1 = EntityFactory().Create(a1);
			if (v1->player_side == player_side)     // -- INLINED 00430F70 entity_register_player_base
			{
				v2 = 0;
				v3 = _47B3C0_player_outposts_clanhalls;
				while (*v3)
				{
					++v3;
					++v2;
					if ((int)v3 >= (int) & _47B3D0_building_production_group)
						goto LABEL_9;
				}
				_47B3C0_player_outposts_clanhalls[v2] = v1;
			}                                         // -- END OF INLINED
		LABEL_9:
			v1->script->event_handler = EventHandler_Outpost;
			map_reveal_fog_around_entity(v1);
			entity_initialize_building(
				v1,
				3,
				entity_mode_outpost_on_death_update_production,
				entity_mode_outpost_set_default_production);
			entity_mode_outpost_enable_basic_construction(v1);
			if (v1->sprite->cplc_ptr1_pstru20)
				v1->SetMode(entity_mode_431680_outpost_arrive);
			else
				entity_402BB0_set_arrive_handler(v1, entity_mode_431680_outpost_arrive);
			v4 = a1->sprite->_80_entity__stru29__sprite__initial_hitpoints;
			if (v4)
			{
				v1->hitpoints = (int)v4;
				entity_410520_update_healthbar_color(v1);
			}
		}
		v1->ExecMode();
	}
}
// 47C6DC: using guessed type int _47C6DC_dont_execute_unit_handlers;

//----- (004315D0) --------------------------------------------------------
void entity_mode_outpost_set_default_production(Entity *a1)
{
	Entity *v1; // esi@1
	enum PLAYER_SIDE v2; // eax@1
	EntityBuildingState *v3; // ebx@1
	ProductionGroup *v4; // eax@6
	ProductionGroup *v5; // edi@6
	int *v6; // esi@6
	enum LEVEL_ID v7; // eax@6

	v1 = a1;
	v2 = a1->player_side;
	v3 = (EntityBuildingState *)a1->state;
	if (v2 == player_side)
	{
		if (a1->mode_arrive == entity_mode_outpost_set_default_production)
		{
			entity_mode_outpost_enable_basic_construction(a1);
			v1->mode_arrive = 0;
			v1->SetMode(entity_mode_403650_building);
		}
		if (!v1->sprite->cplc_ptr1_pstru20)
			show_message_ex(0, aBuildingCompleted);
		v4 = entity_building_create_production_group(v1, PRODUCTION_GROUP_INFANTRY);
		v5 = v4;
		v6 = &surv_basic_infantry[0].mobd_lookup_table_offset;
		v3->production_group = v4;
		v7 = current_level_idx;
		do
		{
			if (!(levels[v7].disabled_units_mask & *(v6 - 2)))
			{
				production_group_enable(v5, (enum UNIT_ID)*(v6 - 1), *v6);
				v7 = current_level_idx;
			}
			v6 += 3;
		} while ((int)v6 < (int)&dword_468FDC);
		++_47B3E0_outpost_levels.num_buildings_by_level[1];
	}
	else if (v2 == 0)
	{
		a1->mode_arrive = entity_mode_outpost_set_default_production;
	}
}

//----- (00431680) --------------------------------------------------------
void entity_mode_431680_outpost_arrive(Entity *a1)
{
	Entity *v1; // esi@1
	EntityTurret *v2; // eax@5

	v1 = a1;
	a1->mode_arrive = 0;
	entity_mode_outpost_set_default_production(a1);
	if (player_side == v1->player_side && !v1->sprite->cplc_ptr1_pstru20 && !is_player_faction_evolved())
		sound_play(SOUND_SURV_BUILDING_COMPLETED, 0, _4690A8_unit_sounds_volume, 16, 0);
	v2 = v1->turret;
	if (v2)
		v2->turret_sprite->drawjob->flags &= 0xBFFFFFFF;
	v1->script->script_type = SCRIPT_SURV_OUTPOST_HANDLER;
	if (v1->sprite->cplc_ptr1_pstru20)
	{
		v1->SetMode(entity_mode_4034B0);
	}
	else
	{
		v1->SetMode(entity_mode_403650_building);
	}
    entity_mode_403650_building(v1);
}

//----- (00431710) --------------------------------------------------------
void entity_mode_outpost_on_death_update_production(Entity *a1)
{
	Entity *v1; // edi@1
	enum PLAYER_SIDE v2; // edx@1
	EntityBuildingState *v3; // ecx@1
	int v4; // esi@2
	enum LEVEL_ID v5; // ecx@5
	enum UNIT_ID v6; // edx@13
	int v7; // eax@18
	ProductionGroup *v8; // edx@28
	int v9; // ecx@29
	Entity **v10; // eax@29
	int v11; // ecx@34
	Entity **v12; // eax@34
	Entity *v13; // [sp+10h] [bp-4h]@1

	v1 = a1;
	v13 = a1;
	v2 = a1->player_side;
	v3 = (EntityBuildingState *)a1->state;
	if (player_side != v2)
		return;
	--_47B3E0_outpost_levels.num_buildings_by_level[v3->num_upgrades];
	v4 = v3->num_upgrades;
	if (v4 != max_outpost_level || _47B3E0_outpost_levels.num_buildings_by_level[v4])
		goto LABEL_22;
	if (v4 <= 0)
		goto LABEL_21;
	v5 = current_level_idx;
	do
	{
		if (v4 == 2)
		{
			if (levels[v5].disabled_units_mask & 0x800)
				goto LABEL_18;
			v6 = UNIT_STATS_SURV_GUARD_TOWER;
			goto LABEL_16;
		}
		if (v4 == 3)
		{
			if (levels[v5].disabled_units_mask & 0x100)
				goto LABEL_18;
			v6 = UNIT_STATS_SURV_MISSILE_BATTERY;
		LABEL_16:
			production_group_disable(_47B3B8_tower_production_group, v6);
		LABEL_17:
			v5 = current_level_idx;
			goto LABEL_18;
		}
		if (v4 == 4)
		{
			if (!(levels[v5].disabled_units_mask & 0x200))
				production_group_disable(_47B3B8_tower_production_group, UNIT_STATS_SURV_CANNON_TOWER);
			_447250_toggle_aircraft();
			goto LABEL_17;
		}
	LABEL_18:
		v7 = __47B3E0_outpost_levels_negindex[v4--];
	} while (!v7 && v4 > 0);
	v1 = v13;
LABEL_21:
	max_outpost_level = v4;
LABEL_22:
	if (building_limits_count(v1->unit_id) == 1)
	{
		if (_47B3D0_building_production_group)
		{
			production_group_4467E0(_47B3D0_building_production_group, UNIT_STATS_SURV_OUTPOST);
			_47B3E0_unit_int_outpost_clanhall = 1;
		}
		production_group_446860(_47B3B8_tower_production_group);
		_447250_toggle_aircraft();
		production_group_446860(_47B3D4_aircraft_production_group);
		_47B3D4_aircraft_production_group = 0;
		_47B3B8_tower_production_group = 0;
		disable_minimap();
	}
	else
	{
		if (max_outpost_level < 2)
			disable_minimap();
		v8 = _47B3D4_aircraft_production_group;
		if (v1 == _47B3D4_aircraft_production_group->_C_entity)
		{
			v9 = 0;
			v10 = _47B3C0_player_outposts_clanhalls;
			while (*v10 != v1)
			{
				++v10;
				++v9;
				if ((int)v10 >= (int) & _47B3D0_building_production_group)
					goto LABEL_34;
			}
			_47B3C0_player_outposts_clanhalls[v9] = 0;
		LABEL_34:
			v11 = 0;
			v12 = _47B3C0_player_outposts_clanhalls;
			while (!*v12)
			{
				++v12;
				++v11;
				if ((int)v12 >= (int) & _47B3D0_building_production_group)
					return;
			}
			v8->_C_entity = _47B3C0_player_outposts_clanhalls[v11];
			_47B3D4_aircraft_production_group->outpost_clanhall = _47B3C0_player_outposts_clanhalls[v11];
		}
	}
}

//----- (004318E0) --------------------------------------------------------
void _4318E0_free_building_production()
{
	if (_47B3D0_building_production_group)
	{
		production_group_446860(_47B3D0_building_production_group);
		_47B3D0_building_production_group = 0;
	}
}

//----- (00431900) --------------------------------------------------------
void entity_mode_outpost_on_death(Entity *a1)
{
	Entity *v1; // esi@1

	v1 = a1;
	entity_mode_outpost_on_death_update_production(a1);
	entity_mode_building_on_death_default(v1);
}

//----- (00431E60) --------------------------------------------------------
void script_431E60_mobd_20_input(Script *a1)
{
	int v1; // esi@1
	__int16 v2; // bx@3
	KeyboardInput out; // [sp+Ch] [bp-14h]@3

	v1 = 0;
	dword_47C6C4 = 0;
	a1->field_1C = 1;
    script_sleep(a1, 2);
	if (!script_create_coroutine(SCRIPT_TYPE_INVALID, script_425400, 0))
		game_state = GAME_STATE::GAME_3;
	while (1)
	{
        script_sleep(a1, 1);
		input_get_keyboard_state(&out);
		v2 = out.just_pressed_keys_mask;
		if (v1 > 0)
			--v1;
		if (out.just_pressed_keys_mask && !dword_47C6C4)
		{
			if (!v1 && out.just_pressed_keys_mask & INPUT_KEYBOARD_ESCAPE_MASK)
			{
				v1 = 4;
				script_trigger_event(a1, EVT_MSG_1530_OPEN_GAME_MENU, 0, task_47C028);
			}
			if (v2 & INPUT_KEYBOARD_TAB_MASK)
				script_44A700_minimap(a1);
		}
	}
}

//----- (00431F10) --------------------------------------------------------
void script_431F10_ingame_menu(Script *a1)
{
	Sprite *v1; // edi@1
	Sprite *v2; // eax@1
	Sprite *v3; // ebx@1
	void *v4; // eax@2
	bool v5; // zf@4
	int v6; // eax@4
	ScriptEvent *i; // eax@9
	int v8; // edx@10
	int v9; // edx@13
	int v10; // eax@19
	int v11; // ecx@19
	void *v12; // ecx@22
	int v13; // eax@22
	int v14; // ecx@23
	__int64 v15; // rax@28
	int sound_volume; // eax@28
	int v17; // [sp+10h] [bp-10Ch]@1
	int v18; // [sp+14h] [bp-108h]@1
	//char name[260]; // [sp+18h] [bp-104h]@36

	v1 = a1->sprite;
	a1->script_type = SCRIPT_TYPE_DA000001;
	v18 = 0;
	v17 = 0;
	v1->drawjob->on_update_handler = (DrawJobUpdateHandler)drawjob_update_handler_4483E0_sidebar;
	v1->z_index += 768;
	sprite_load_mobd(v1, 36);
	v2 = sprite_create(MOBD_INGAME_MENU_CONTROLS, 0, 0);
	v3 = v2;
	if (v2)
	{
		v2->drawjob->on_update_handler = (DrawJobUpdateHandler)drawjob_update_handler_4483E0_sidebar;
		sprite_load_mobd(v2, 48);
		v4 = v1->param;
		if (v4 == (void *)2)
		{
			v3->x = v1->x + dword_4690B4;
		}
		else
		{
			v5 = v4 == (void *)1;
			v6 = _4690A8_unit_sounds_volume;
			if (!v5)
				v6 = _4690AC_level_wav_sound_offset;
			v3->x = v1->x + ((v6 << 7) / 16 << 8);
		}
		v3->y = v1->y;
		v3->z_index = v1->x + 256;
	}
	do
	{
		if (script_yield_any_trigger(a1, 1) & SCRIPT_FLAGS_20_EVENT_TRIGGER)
		{
			for (i = script_get_next_event(a1); i; i = script_get_next_event(a1))
			{
				v8 = i->event;
				if (v8 > (int)EVT_MSG_SELECTED)
				{
					v9 = v8 - EVT_MSG_DESELECTED;
					if (v9)
					{
						if (v9 == 16)
							v18 = 1;
					}
					else
					{
						v17 = 0;
					}
				}
				else if (v8 == EVT_MSG_SELECTED)
				{
					v17 = 1;
				}
				script_discard_event(i);
			}
		}
		if (v17)
		{
			game_cursor_script->sprite->field_88_unused = 1;
			v10 = game_cursor_script->sprite->x;
			v3->x = v10;
			v11 = v1->x;
			if (v10 < v11 || (v11 += 0x8000, v10 > v11))
				v3->x = v11;
			v12 = v1->param;
			v13 = v3->x;
			if (v12 == (void *)2)
			{
				dword_4690B4 = v13 - v1->x;
				v14 = 32 - (dword_4690B4 >> 8) / 4;
				if (v14 < 1)
					v14 = 1;
				if (v14 >= 32)
					LOWORD_HEXRAYS(v14) = 32;
				input_428470(v14);
			}
			else
			{
				v15 = 16 * ((v13 - v1->x) >> 8);
				sound_volume = ((BYTE4(v15) & 0x7F) + (int)v15) >> 7;
				if (v12 == (void *)1)
				{
					_4690A8_unit_sounds_volume = sound_volume;
				}
				else
				{
					_4690AC_level_wav_sound_offset = sound_volume;
                    if (sound_volume) 
                    {
                        goto LABEL_44;
                    }
					if (_4690B0_sound_volume_previous && _47C5D4_sound_threaded_snd_id)
					{
						sound_stop(_47C5D4_sound_threaded_snd_id);
						sound_volume = _4690AC_level_wav_sound_offset;
					}
					if (sound_volume)
					{
                    LABEL_44:
						if (!_4690B0_sound_volume_previous)
						{
							sound_play_threaded(levels[current_level_idx].wav_filename, 1, _4690AC_level_wav_sound_offset, 16, 0);
							sound_volume = _4690AC_level_wav_sound_offset;
						}
						if (sound_volume) // sound volume in ingame menu
						{
							sound_threaded_set_volume(sound_volume);
							sound_volume = _4690AC_level_wav_sound_offset;
						}
					}
					_4690B0_sound_volume_previous = sound_volume;
				}
			}
		}
	} while (!v18);
	sprite_list_remove(v3);
	sprite_list_remove(v1);
	script_terminate(a1);
}

//----- (004321A0) --------------------------------------------------------
void script_4321A0_ingame_menu(Script *a1)
{
	Sprite *v1; // esi@1
	Sprite *v2; // eax@1
	Sprite *v3; // eax@3
	Script *v4; // ecx@4
	int v5; // ecx@4
	Sprite *v6; // eax@5
	Script *v7; // edx@6
	int v8; // ecx@6

	v1 = a1->sprite;
	dword_47C6C4 = 1;
	script_trigger_event_group(a1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_DA000002);
	_47C65C_render_string = render_string_create(
		0,
		currently_running_lvl_mobd[MOBD_FONT_ITALIC].items,
		248,
		88,
		22,
		8,
		0x200003E9,
		14,
		5);
	render_string_445AE0(_47C65C_render_string);
	_47C65C_render_string->field_18 = 0;
	_47C65C_render_string->num_lines = 0;
	render_string_443D80(_47C65C_render_string, aSfxVolumeMusicVolume, 0);
	v2 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1, script_433DB0_ingame_menu, SCRIPT_COROUTINE, 0);
	if (v2)
		v2->script->field_1C = 1;
	v3 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1, script_431F10_ingame_menu, SCRIPT_COROUTINE, 0);
	if (v3)
	{
		v4 = v3->script;
		v3->param = (void *)1;
		v4->field_1C = 1;
		v5 = v3->y;
		v3->x -= 12800;
		v3->y = v5 + 18432;
	}
	v6 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1, script_431F10_ingame_menu, SCRIPT_COROUTINE, 0);
	if (v6)
	{
		v7 = v6->script;
		v6->param = 0;
		v7->field_1C = 1;
		v8 = v6->y;
		v6->x -= 12800;
		v6->y = v8 + 35840;
	}
	else
	{
		game_state = GAME_STATE::GAME_3;
	}
}

//----- (004322D0) --------------------------------------------------------
void script_ingame_menu_mission_briefing(Script *script)
{
    Script *temp_script_1; // esi@1
    RenderString *render_string; // eax@1
    int num_lines; // edi@2
    int v4; // ebp@2
    char *current_mission_briefing; // esi@4
    int counter; // ecx@8
    char current_letter; // al@9
    Sprite *sprite; // eax@21
    int loop_counter; // [sp+10h] [bp-6Ch]@6
    Script *temp_script_2; // [sp+14h] [bp-68h]@1
    char text_line[512]; // [sp+18h] [bp-64h]@11

    temp_script_1 = script;
    temp_script_2 = script;
    script_trigger_event_group(script, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_DA000002);
    render_string = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 120, 70, 42, 15, 0x200003E9, 14, 5);
    _47C65C_render_string = render_string;
    if (render_string)
    {
        num_lines = 0;
        v4 = 5;
        // get current level mission briefing
        if (current_level_idx < LEVEL_SURV_16 || current_level_idx > LEVEL_MUTE_25)
            current_mission_briefing = mission_briefings[current_level_idx];
        else
            current_mission_briefing = *(char **)&aNoFreeLinks[4 * current_level_idx + 12];

        render_string_445AE0(render_string);
        loop_counter = 0;
        do
        {
            // if no mission briefing
            if (!*current_mission_briefing)
                break;

            // extract line of text into array
            counter = 0;
            while (1)
            {
                current_letter = *current_mission_briefing;
                if (*current_mission_briefing == '\n' || !current_letter)
                    break;
                text_line[counter++] = current_letter;
                ++current_mission_briefing;
            }
            text_line[counter] = 0;

            // skip new line character
            if (*current_mission_briefing == '\n')
                ++current_mission_briefing;

            // render text line
            _47C65C_render_string->field_18 = v4;
            _47C65C_render_string->num_lines = num_lines;
            render_string_443D80(_47C65C_render_string, text_line, 0);

            // calculate line number
            if (loop_counter)
            {
                ++num_lines;
            }
            else
            {
                num_lines += 2;
                v4 = 0;
            }
            ++loop_counter;
        } while (loop_counter < 11);
        temp_script_1 = temp_script_2;
    }
    sprite = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, temp_script_1->sprite, script_433D20_ingame_menu, SCRIPT_COROUTINE, 0);
    if (sprite)
        sprite->script->field_1C = 1;
    sprite_load_mobd(task_47C028->sprite, 12);
}

//----- (00432400) --------------------------------------------------------
void script_432400_ingame_menu_create_sprites(Script *a1)
{
	Sprite *v1; // esi@1
	Sprite *v2; // eax@1
	Sprite *v3; // eax@3
	Sprite *v4; // eax@5
	Sprite *v5; // eax@9
	Sprite *v6; // eax@11
	Sprite *v7; // eax@13
	Sprite *v8; // eax@15

	v1 = a1->sprite;
	v2 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, a1->sprite, script_433780_ingame_menu, SCRIPT_COROUTINE, 0);
	if (v2)
		v2->script->field_1C = 1;
	v3 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1, script_433A60_ingame_menu, SCRIPT_COROUTINE, 0);
	if (v3)
		v3->script->field_1C = 1;
	v4 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1, script_433960_ingame_menu, SCRIPT_COROUTINE, 0);
	if (v4)
		v4->script->field_1C = 1;
	if (single_player_game && !_47C6D8_use__466098_cost_multipliers)
	{
		v5 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1, script_433880_ingame_menu, SCRIPT_COROUTINE, 0);
		if (v5)
			v5->script->field_1C = 1;
		v6 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1, script_433810_ingame_menu, SCRIPT_COROUTINE, 0);
		if (v6)
			v6->script->field_1C = 1;
		v7 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1, script_4339F0_ingame_menu, SCRIPT_COROUTINE, 0);
		if (v7)
			v7->script->field_1C = 1;
		v8 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1, script_4338F0_ingame_menu, SCRIPT_COROUTINE, 0);
		if (v8)
			v8->script->field_1C = 1;
	}
	sprite_load_mobd(v1, 0);
}

//----- (00432510) --------------------------------------------------------
void script_432510_ingame_menu_create_sprites(Script *a1)
{
	Script *v1; // esi@1

	v1 = a1;
	sprite_create_scripted(MOBD_FONT_ITALIC, a1->sprite, script_432F00_ingame_menu, SCRIPT_COROUTINE, 0);
	sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1->sprite, script_434390_ingame_menu, SCRIPT_COROUTINE, 0);
	sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1->sprite, script_434220_ingame_menu, SCRIPT_COROUTINE, 0);
	sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1->sprite, script_434310_ingame_menu, SCRIPT_COROUTINE, 0);
	sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1->sprite, script_4342A0_ingame_menu, SCRIPT_COROUTINE, 0);
	sprite_create_scripted(MOBD_45, v1->sprite, script_434460_DA000007, SCRIPT_COROUTINE, 0);
	dword_47C6F8 = 1;
}

//----- (004325B0) --------------------------------------------------------
void script_4325B0_ingame_menu_trigger_events(Script *a1)
{
	Script *v1; // esi@1

	v1 = a1;
	dword_47C6F8 = 0;
	stru29_list_443BF0_remove_some();
	script_trigger_event_group(v1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_DA000006);
	script_trigger_event_group(v1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_DA000007);
	script_trigger_event_group(v1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_DA000008);
	script_trigger_event_group(v1, EVT_MSG_1546_repair_at_station, 0, SCRIPT_TYPE_1);
	script_trigger_event_group(v1, EVT_MSG_1546_repair_at_station, 0, SCRIPT_TYPE_19);
}
// 47C6F8: using guessed type int dword_47C6F8;


//----- (00432730) --------------------------------------------------------
void script_432730_ingame_menu(Script *a1)
{
	Script *v1; // edi@1
	Sprite *v2; // ebp@1
	int v3; // ebx@2
	int v4; // esi@2
	ScriptEvent *v5; // eax@3
	enum SCRIPT_EVENT v6; // ecx@4

	v1 = a1;
	v2 = a1->sprite;
	a1 = (Script *)a1->param;
	v2->drawjob->on_update_handler = (DrawUpdateHandler)drawjob_update_handler_4483E0_sidebar;
	sprite_load_mobd(v2, 696);
	_47C668_ingame_menu_sprites[(int)a1] = v1->sprite;
	while (1)
	{
		v3 = 0;
		v4 = 0;
		do
		{
            script_wait_event(v1);
			v5 = script_get_next_event(v1);
			if (v5)
			{
				while (1)
				{
					v6 = v5->event;
					if (v6 != EVT_MOUSE_HOVER)
					{
						if (v6 == EVT_MSG_SELECTED)
							goto LABEL_8;
						if (v6 == EVT_MSG_1528_cancel)
							break;
					}
				LABEL_9:
					script_discard_event(v5);
					v5 = script_get_next_event(v1);
					if (!v5)
						goto LABEL_10;
				}
				v3 = 1;
			LABEL_8:
				v4 = 1;
				goto LABEL_9;
			}
		LABEL_10:
			;
		} while (!v4);
		if (v3)
			break;
		script_trigger_event(v1, EVT_MSG_SELECTED, &a1, receiver);
	}
	_47C668_ingame_menu_sprites[(int)a1] = 0;
	sprite_list_remove(v2);
	script_terminate(v1);
}

//----- (00432800) --------------------------------------------------------
void script_432800_ingame_menu(Script *a1)
{
	Script *v1; // edi@1
	Sprite *v2; // ecx@1
	int v3; // ebp@2
	int v4; // ebx@2
	ScriptEvent *i; // esi@3
	enum SCRIPT_EVENT v6; // eax@4
	Sprite *v7; // [sp+10h] [bp-4h]@1

	v1 = a1;
	v2 = a1->sprite;
	a1 = (Script *)a1->param;
	v7 = v2;
	v2->drawjob->on_update_handler = (DrawUpdateHandler)drawjob_update_handler_4483E0_sidebar;
	sprite_load_mobd(v2, 696);
	_47C668_ingame_menu_sprites[(int)a1] = v1->sprite;
	while (1)
	{
		v3 = 0;
		v4 = 0;
		do
		{
            script_wait_event(v1);
			for (i = script_get_next_event(v1); i; i = script_get_next_event(v1))
			{
				v6 = i->event;
				switch (v6)
				{
				case 0xFFFFFFFE:
					stru29_list_443AE0_find_by_sprite(v1->sprite);
					break;
				case 0x5E7u:
					v4 = 1;
					break;
				case 0x5F8u:
					v3 = 1;
					v4 = 1;
					break;
				}
				script_discard_event(i);
			}
		} while (!v4);
		if (v3)
			break;
		script_trigger_event(v1, EVT_MSG_SELECTED, &a1, receiver);
	}
	_47C668_ingame_menu_sprites[(int)a1] = 0;
	sprite_list_remove(v7);
	script_terminate(v1);
}

//----- (004328F0) --------------------------------------------------------
void _41AC50_string_draw_handler(const char *a1, int cursor_pos)
{
	_47C65C_render_string->field_18 = 0;
	_47C65C_render_string->num_lines = 6;
	render_string_443D80(_47C65C_render_string, asc_46BB14, 0);
	_47C65C_render_string->field_18 = 0;
	render_string_443D80(_47C65C_render_string, a1, 0);
	_47C664_ingame_menu_sprite->field_88_unused = 1;
	_47C664_ingame_menu_sprite->x = render_string_443EE0(_47C65C_render_string, cursor_pos, 6) << 8;
	_47C664_ingame_menu_sprite->field_88_unused = 1;
	_47C664_ingame_menu_sprite->y = 0xC200;
}

//----- (00432990) --------------------------------------------------------
void script_ingame_menu_saveload(Script *a1, int a2, bool true_save_false_load)
{
	Sprite *v3; // esi@1
	int v4; // edi@1
	RenderString *v5; // eax@4
	int v6; // esi@8
	int v7; // edi@8
	Sprite *v8; // eax@10
	int v9; // edi@18
	int v10; // ebx@18
	stru175_savegame *v11; // esi@18
	int v13; // esi@30
	ScriptEvent *i; // eax@30
	int v17; // edx@32
	int v23; // [sp+10h] [bp-54h]@5
	int v24; // [sp+14h] [bp-50h]@4
	int v26; // [sp+1Ch] [bp-48h]@1
	Sprite *a1a; // [sp+20h] [bp-44h]@1
	int v30; // [sp+2Ch] [bp-38h]@1
	char a2a[12]; // [sp+30h] [bp-34h]@20

	v3 = a1->sprite;
	a1a = a1->sprite;
	v4 = a2 != 0 ? 256 : 96;
	v26 = 0;
	v30 = a2 != 0 ? 256 : 96;
	if (a2)
		a1->script_type = SCRIPT_TYPE_DA000008;
	else
		a1->script_type = SCRIPT_TYPE_DA000001;
	receiver = a1;
	v5 = render_string_create(
		0,
		currently_running_lvl_mobd[MOBD_FONT_ITALIC].items,
		216,
		a2 != 0 ? 240 : 80,
		22,
		10,
		0x200007D0,
		14,
		5);
	_47C65C_render_string = v5;
	_47C664_ingame_menu_sprite = v3;
	v24 = _47C050_current_savegame_idx - 4;
	if (_47C050_current_savegame_idx - 4 >= 0)
	{
		v23 = 4;
	}
	else
	{
		v24 = 0;
		v23 = _47C050_current_savegame_idx;
	}
	if (v5)
	{
		render_string_445AE0(v5);
		v6 = 0;
		v7 = (v4 + 14) << 8;
		do
		{
			if (a2)
				v8 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, 0, script_432800_ingame_menu, SCRIPT_COROUTINE, 0);
			else
				v8 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, 0, script_432730_ingame_menu, SCRIPT_COROUTINE, 0);
			if (v8)
			{
				v8->script->field_1C = 1;
				v8->script->param = (void *)v6;
				v8->x = 0xE800;
				v8->y = v7;
				v8->z_index = 2560;
				if (a2)
				{
					v8->script->script_type = SCRIPT_TYPE_DA000008;
					stru29_list_4439F0(v8, 0, 0, 1, 0);
				}
				else
				{
					v8->script->script_type = SCRIPT_TYPE_DA000001;
				}
			}
			++v6;
			v7 += 4096;
		} while (v6 < 5);
	}
	a1a->drawjob->on_update_handler = (DrawUpdateHandler)drawjob_update_handler_4483E0_sidebar;
	a1a->z_index = 1280;

    bool loading = false;
    bool saving = false;
    bool cancelling = false;
	while (1)
	{
		while (1)
		{
			while (1)
			{
				render_string_445AE0(_47C65C_render_string);
				_47C65C_render_string->field_18 = 0;
				_47C65C_render_string->num_lines = 0;
				a1a->x = 59392;
				a1a->y = (16 * v23 + v30 + 14) << 8;
				sprite_load_mobd(a1a, 1064);
				v9 = v24;
				v10 = 5;
				v11 = &_47C050_savegames[v24];
				do
				{
                    if (v24 >= 10) {
                        sprintf(a2a, "%d:", v9);
                    }
					else if (v24 >= 2)
					{
                        sprintf(a2a, " %d:", v9);
					}
					else
					{
						sprintf(a2a, "  %d:", v9);
					}
					render_string_443D80(_47C65C_render_string, a2a, 0);
					if (v11->name[0])
						render_string_443D80(_47C65C_render_string, v11->name, 0);
					render_string_443D80(_47C65C_render_string, asc_464C88, 0);
					++v9;
					++v11;
					--v10;
				} while (v10);
				do
				{
					if (v26 > 0)
						--v26;
				} while (!(script_yield_any_trigger(a1, 1) & SCRIPT_FLAGS_20_EVENT_TRIGGER));

				v13 = 0;
				loading = false;
                saving = false;
				for (i = script_get_next_event(a1); i; i = script_get_next_event(a1))
				{
					switch (i->event)
					{
					case EVT_MSG_SELECTED:
						v17 = *(_DWORD *)i->param;
						if (v17 < 5)
						{
							if (v26)
							{
								if (v26 > 85)
								{
									v26 = 0;
									if (v23 == v17)
										v13 = 1;
								}
								v23 = *(_DWORD *)i->param;
							}
							else
							{
								v26 = 100;
								v23 = *(_DWORD *)i->param;
							}
						}
						break;
					case EVT_MSG_SHOW_UNIT_HINT:
						if (v23 <= 0)
						{
							if (v24 > 0)
								--v24;
						}
						else
						{
							--v23;
						}
						break;
					case EVT_MSG_DESELECTED:
						if (v23 >= 4)
						{
							if (v24 < 15)
								++v24;
						}
						else
						{
							++v23;
						}
						break;
					case EVT_MSG_1549:
                        loading = true;
						break;
					case EVT_CMD_ENTITY_MOVE:
                        saving = true;
						break;
					case EVT_MSG_1528_cancel:
                        cancelling = true;
						break;
					default:
						break;
					}
					script_discard_event(i);
				}

				if (cancelling)
				{
					if (_47C65C_render_string)
					{
						render_string_list_remove(_47C65C_render_string);
						_47C65C_render_string = 0;
					}
					sprite_list_remove(a1a);
					script_terminate(a1);
				}
				_47C050_current_savegame_idx = v23 + v24;
				if (true_save_false_load)
					break;
				if ((v13 || loading) && _438740_update_save_lst_and_gamestate())
				{
					if (a2)
					{
						sub_43BAA0();
						script_deinit(_47C6E0_task);
						_47C6E0_task = 0;
						stru29_list_free();
					}
					else
					{
						script_trigger_event_group(a1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_DA000001);
						sprite_list_remove((Sprite *)task_47C028->param);
						if (a1 != task_47C028)
							script_trigger_event(a1, EVT_MSG_1522_plan_building_construction, 0, task_47C028);
					}
				}
			}
			if (!v13)
				break;
		LABEL_59:
			_47C664_ingame_menu_sprite->field_88_unused = 1;
			_47C664_ingame_menu_sprite->y = 0xC200;
			sprite_load_mobd(a1a, 1096);
			dword_47C6C4 = 1;
			if (input_get_string(
				_47C050_savegames[_47C050_current_savegame_idx].name,
				11,
				_41AC50_string_draw_handler,
				1,
                a1))
			{
                int slot = _47C050_current_savegame_idx;
                int v18 = savegame_fix_name(_47C050_current_savegame_idx);

//			LABEL_69:
				if (v18 > 0)
				{
					//memcpy(&_47C050_savegames[v22], v32, v18);
					_47C050_savegames[slot].level_id = current_level_idx;
					if (_438840_update_save_lst())
						script_trigger_event(a1, EVT_MSG_1530_OPEN_GAME_MENU, 0, task_47C028);
				}
			}
			dword_47C6C4 = 0;
		}
		if (saving)
		{
			goto LABEL_59;
		}
	}
}
// 47C6C4: using guessed type int dword_47C6C4;
// 432990: using guessed type char var_28[40];

//----- (00432F00) --------------------------------------------------------
void script_432F00_ingame_menu(Script *a1)
{
	script_ingame_menu_saveload(a1, 1, 0);
}

//----- (00433060) --------------------------------------------------------
void script_433060_ingame_menu_DA000000(Script *a1)
{
	Script *v1; // esi@1
	signed __int16 v2; // bp@1
	Sprite *v3; // edi@1
	DrawJob *v4; // ecx@1
	int v5; // eax@1
	ScriptEvent *i; // eax@7
	int v7; // edi@27
	ScriptEvent *j; // ebp@29
	Script *v9; // eax@33
	Sprite *v10; // eax@54
	Sprite *v11; // eax@56
	Sprite *v12; // eax@58
	Sprite *v13; // eax@60
	int v14; // [sp+10h] [bp-8h]@1
	Sprite *v15; // [sp+14h] [bp-4h]@1
	int a1a; // [sp+1Ch] [bp+4h]@5

	v1 = a1;
	v2 = 1;
	v3 = a1->sprite;
	task_47C028 = a1;
	a1->script_type = SCRIPT_TYPE_DA000000;
	v4 = v3->drawjob;
	v3->field_88_unused = 1;
	v5 = render_width;
	v3->field_88_unused = 1;
	LOBYTE_HEXRAYS(v5) = v5 & 0xFE;
	v3->y = 0x4000;
	v3->x = v5 << 7;
	v3->z_index = 1000;
	v4->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_4483E0_sidebar;
	a1->field_1C = 1;
	v14 = 0;
	v15 = v3;
	dword_47C030 = 0;
	script_4084A0_animation(a1);
	while (1)
	{
		if (single_player_game)
		{
			a1a = 0;
			is_async_execution_supported = 0;
			script_trigger_event(v1, EVT_MSG_1533, 0, game_cursor_script);
			sub_408460();
			sprite_load_mobd(v3, 60);
		}
		else
		{
			if (dword_47C030)
			{
				dword_47C030 = 0;
				script_trigger_event(v1, EVT_MSG_1533, 0, game_cursor_script);
				sprite_load_mobd(v3, 60);
			}
			a1a = 0;
			sub_408460();
		}
		do
		{
            script_yield_any_trigger(v1, 1);
			for (i = script_get_next_event(v1); i; i = script_get_next_event(v1))
			{
				if (i->event == EVT_MSG_1530_OPEN_GAME_MENU)
				{
					a1a = 1;
				}
				else if (i->event == 1531)
				{
					v14 = 1;
				}
				script_discard_event(i);
			}
			if (is_async_execution_supported)
				a1a = 1;
			if (v14)
				a1a = 0;
		} while (!a1a);
		if (single_player_game)
			break;
		if (!is_async_execution_supported)
		{
			script_trigger_event(v1, EVT_MSG_1532, 0, game_cursor_script);
			while (!is_async_execution_supported)
                script_sleep(v1, 1);
			if (dword_47050C == 1)
			{
				dword_47C030 = 1;
			LABEL_26:
				script_432400_ingame_menu_create_sprites(v1);
				goto LABEL_27;
			}
		}
		dword_47C030 = 0;
	LABEL_27:
		_408410_dim_palette();
		v7 = 1;
		do
		{
			if (script_yield_any_trigger(v1, 1) & SCRIPT_FLAGS_20_EVENT_TRIGGER)
			{
				for (j = script_get_next_event(v1); j; j = script_get_next_event(v1))
				{
					switch (j->event)
					{
					case EVT_MSG_1530_OPEN_GAME_MENU:
						switch (v7)
						{
						case 5:
							script_trigger_event_group(v1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_DA000001);
							if (!_47C65C_render_string)
								goto LABEL_45;
							render_string_list_remove(_47C65C_render_string);
							v9 = task_47C028;
							if (v1 != task_47C028)
								goto LABEL_46;
							goto LABEL_47;
						case 6:
							script_trigger_event_group(v1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_DA000001);
							sprite_list_remove((Sprite *)task_47C028->param);
							v9 = task_47C028;
							if (v1 != task_47C028)
								goto LABEL_46;
							goto LABEL_47;
						case 7:
							script_trigger_event_group(v1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_DA000001);
							sprite_list_remove((Sprite *)task_47C028->param);
							v9 = task_47C028;
							if (v1 != task_47C028)
								goto LABEL_46;
							goto LABEL_47;
						case 3:
						case 4:
							script_trigger_event_group(v1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_DA000003);
							if (!_47C65C_render_string)
								goto LABEL_45;
							render_string_list_remove(_47C65C_render_string);
							_47C65C_render_string = 0;
							if (v1 == task_47C028)
								goto LABEL_47;
							script_trigger_event(v1, EVT_MSG_1522_plan_building_construction, 0, task_47C028);
							v7 = 1;
							script_432400_ingame_menu_create_sprites(v1);
							goto LABEL_64;
						case 2:
							if (_47C65C_render_string)
							{
								render_string_list_remove(_47C65C_render_string);
								_47C65C_render_string = 0;
							}
							script_trigger_event_group(v1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_DA000001);
						LABEL_45:
							v9 = task_47C028;
							if (v1 != task_47C028)
								LABEL_46:
							script_trigger_event(v1, EVT_MSG_1522_plan_building_construction, 0, v9);
							goto LABEL_47;
						case 1:
							goto LABEL_51;
						default:
							goto LABEL_64;
						}
					case EVT_MSG_1522_plan_building_construction:
					LABEL_47:
						v7 = 1;
						script_432400_ingame_menu_create_sprites(v1);
						break;
					case EVT_MSG_1531:
						v14 = 1;
						a1a = 0;
						break;
					case EVT_CMD_ENTITY_MOVE:
						v7 = 2;
						script_4321A0_ingame_menu(v1);
						break;
					case EVT_MSG_1526_infiltrate:
						v7 = 5;
						script_ingame_menu_mission_briefing(v1);
						break;
					case EVT_MSG_1528_cancel:
					LABEL_51:
						if (single_player_game || dword_47C030)
							a1a = 0;
						break;
					case EVT_MSG_1527:
						v7 = 4;
						script_trigger_event_group(v1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_DA000002);
						_47C65C_render_string = render_string_create(
							0,
							currently_running_lvl_mobd[MOBD_FONT_ITALIC].items,
							256,
							96,
							22,
							8,
							0x200003E9,
							14,
							5);
						render_string_445AE0(_47C65C_render_string);
						_47C65C_render_string->field_18 = 0;
						_47C65C_render_string->num_lines = 0;
						render_string_443D80(_47C65C_render_string, aAreYouSureYouW, 0);
						v10 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1->sprite, script_433C30_ingame_menu, SCRIPT_COROUTINE, 0);
						if (v10)
							v10->script->field_1C = 1;
						v11 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1->sprite, script_433C90_ingame_menu, SCRIPT_COROUTINE, 0);
						if (v11)
							v11->script->field_1C = 1;
						break;
					case EVT_CMD_ENTITY_ATTACK:
						v7 = 3;
						script_trigger_event_group(v1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_DA000002);
						_47C65C_render_string = render_string_create(
							0,
							currently_running_lvl_mobd[MOBD_FONT_ITALIC].items,
							256,
							96,
							22,
							8,
							0x200003E9,
							14,
							5);
						render_string_445AE0(_47C65C_render_string);
						_47C65C_render_string->field_18 = 0;
						_47C65C_render_string->num_lines = 0;
						render_string_443D80(_47C65C_render_string, aAreYouSureYo_0, 0);
						v12 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1->sprite, script_433AF0_ingame_menu, SCRIPT_COROUTINE, 0);
						if (v12)
							v12->script->field_1C = 1;
						v13 = sprite_create_scripted(MOBD_INGAME_MENU_CONTROLS, v1->sprite, script_433BA0_ingame_menu, SCRIPT_COROUTINE, 0);
						if (v13)
							v13->script->field_1C = 1;
						break;
					case EVT_MSG_1509_stru11:
						v7 = 6;
						script_ingame_menu_create_load_dialog(v1);
						break;
					case EVT_MSG_1507_stru11:
						v7 = 7;
						script_ingame_menu_create_save_dialog(v1);
						break;
					default:
						break;
					}
				LABEL_64:
					script_discard_event(j);
				}
				v2 = 1;
			}
			if (!is_async_execution_supported)
				a1a = 0;
		} while (a1a);
		script_trigger_event_group(v1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_DA000002);
		v3 = v15;
	}
	is_async_execution_supported = v2;
	script_trigger_event(v1, EVT_MSG_1532, 0, game_cursor_script);
	goto LABEL_26;
}

//----- (00433640) --------------------------------------------------------
void script_433640(Script *a1, enum SCRIPT_TYPE event, int x_offset, int y_offset, int z_index_offset)
{
	Script *v5; // edi@1
	Sprite *v6; // esi@1
	Sprite *v7; // edx@1
	Sprite *v8; // eax@1
	int v9; // ebp@1
	Sprite *v10; // eax@1

	v5 = a1;
	v6 = a1->sprite;
	a1->script_type = event;
	v6->drawjob->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_4483E0_sidebar;
	v7 = v6->parent;
	v6->field_88_unused = 1;
	v7->field_88_unused = 1;
	v8 = v6->parent;
	v9 = v8->x;
	v6->field_88_unused = 1;
	v6->x = v9 + (x_offset << 8);
	v6->y = v8->y + (y_offset << 8);
	v6->z_index = v8->z_index + (z_index_offset << 8);
	v10 = sprite_create(MOBD_INGAME_MENU_CONTROLS, 0, 0);
	if (v10)
	{
		v10->drawjob->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_4483E0_sidebar;
		v10->x = v6->x;
		v10->y = v6->y;
		v10->z_index = v6->z_index + 256;
		v5->param = v10;
	}
}

//----- (004336E0) --------------------------------------------------------
void script_4336E0(Script *script, enum SCRIPT_TYPE type, int x_offset, int y_offset, int z_index_offset)
{
	Script *v5; // edi@1
	Sprite *v6; // esi@1
	Sprite *v7; // edx@1
	Sprite *v8; // eax@1
	int v9; // ebp@1
	Sprite *v10; // eax@1

	v5 = script;
	v6 = script->sprite;
	script->script_type = type;
	v6->drawjob->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_4483E0_sidebar;
	v7 = v6->parent;
	v6->field_88_unused = 1;
	v7->field_88_unused = 1;
	v8 = v6->parent;
	v9 = v8->x;
	v6->field_88_unused = 1;
	v6->x = v9 + (x_offset << 8);
	v6->y = v8->y + (y_offset << 8);
	v6->z_index = v8->z_index + (z_index_offset << 8);
	v10 = sprite_create(MOBD_45, 0, 0);
	if (v10)
	{
		v10->drawjob->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_4483E0_sidebar;
		v10->x = v6->x;
		v10->y = v6->y;
		v10->z_index = v6->z_index + 256;
		v5->param = v10;
	}
}

//----- (00433780) --------------------------------------------------------
void script_433780_ingame_menu(Script *a1)
{
	signed __int16 v1; // ax@2
	Sprite *v2; // edi@6

	if (!single_player_game || (v1 = 18, _47C6D8_use__466098_cost_multipliers))
		v1 = 66;
	script_433640(a1, SCRIPT_TYPE_DA000002, -92, v1, 1);
	if (script_434500(a1, CURSOR_MOBD_OFFSET_MISSION_ARROW_SW, 0, 0))
	{
		script_trigger_event(a1, EVT_CMD_ENTITY_MOVE, 0, task_47C028);
        script_sleep(a1, 1);
	}
	v2 = a1->sprite;
	sprite_list_remove((Sprite *)a1->param);
	sprite_list_remove(v2);
	script_terminate(a1);
}
// 468B5C: using guessed type int single_player_game;

//----- (00433810) --------------------------------------------------------
void script_433810_ingame_menu(Script *a1)
{
	Sprite *v1; // edi@3

	script_433640(a1, SCRIPT_TYPE_DA000002, -92, 42, 2);
	if (script_434500(a1, CURSOR_MOBD_OFFSET_888, 0, 0))
	{
		script_trigger_event(a1, EVT_MSG_1509_stru11, 0, task_47C028);
        script_sleep(a1, 1);
	}
	v1 = a1->sprite;
	sprite_list_remove((Sprite *)a1->param);
	sprite_list_remove(v1);
	script_terminate(a1);
}

//----- (00433880) --------------------------------------------------------
void script_433880_ingame_menu(Script *a1)
{
	Sprite *v1; // edi@3

	script_433640(a1, SCRIPT_TYPE_DA000002, -92, 66, 3);
	if (script_434500(a1, CURSOR_MOBD_OFFSET_900, 0, 0))
	{
		script_trigger_event(a1, EVT_MSG_1507_stru11, 0, task_47C028);
        script_sleep(a1, 1);
	}
	v1 = a1->sprite;
	sprite_list_remove((Sprite *)a1->param);
	sprite_list_remove(v1);
	script_terminate(a1);
}

//----- (004338F0) --------------------------------------------------------
void script_4338F0_ingame_menu(Script *a1)
{
	Sprite *v1; // edi@3

	script_433640(a1, SCRIPT_TYPE_DA000002, -92, 90, 4);
	if (script_434500(a1, CURSOR_MOBD_OFFSET_MISSION_ARROW_S_BLINK, 0, 0))
	{
		script_trigger_event(a1, EVT_MSG_1526_infiltrate, 0, task_47C028);
        script_sleep(a1, 1);
	}
	v1 = a1->sprite;
	sprite_list_remove((Sprite *)a1->param);
	sprite_list_remove(v1);
	script_terminate(a1);
}

//----- (00433960) --------------------------------------------------------
void script_433960_ingame_menu(Script *a1)
{
	signed __int16 v1; // ax@2
	Sprite *v2; // edi@6

	if (!single_player_game || (v1 = 114, _47C6D8_use__466098_cost_multipliers))
		v1 = 90;
	script_433640(a1, SCRIPT_TYPE_DA000002, -92, v1, 5);
	if (script_434500(a1, CURSOR_MOBD_OFFSET_BORDERLESS_CURSOR, 0, 0))
	{
		script_trigger_event(a1, EVT_MSG_1528_cancel, 0, task_47C028);
        script_sleep(a1, 1);
	}
	v2 = a1->sprite;
	sprite_list_remove((Sprite *)a1->param);
	sprite_list_remove(v2);
	script_terminate(a1);
}
// 468B5C: using guessed type int single_player_game;

//----- (004339F0) --------------------------------------------------------
void script_4339F0_ingame_menu(Script *a1)
{
	Sprite *v1; // edi@3

	script_433640(a1, SCRIPT_TYPE_DA000002, -92, 138, 6);
	if (script_434500(a1, CURSOR_MOBD_OFFSET_876, 0, 0))
	{
		script_trigger_event(a1, EVT_MSG_1527, 0, task_47C028);
        script_sleep(a1, 1);
	}
	v1 = a1->sprite;
	sprite_list_remove((Sprite *)a1->param);
	sprite_list_remove(v1);
	script_terminate(a1);
}

//----- (00433A60) --------------------------------------------------------
void script_433A60_ingame_menu(Script *a1)
{
	signed __int16 v1; // ax@2
	Sprite *v2; // edi@6

	if (!single_player_game || (v1 = 162, _47C6D8_use__466098_cost_multipliers))
		v1 = 114;
	script_433640(a1, SCRIPT_TYPE_DA000002, -92, v1, 7);
	if (script_434500(a1, CURSOR_MOBD_OFFSET_828, 0, 0))
	{
		script_trigger_event(a1, EVT_CMD_ENTITY_ATTACK, 0, task_47C028);
        script_sleep(a1, 1);
	}
	v2 = a1->sprite;
	sprite_list_remove((Sprite *)a1->param);
	sprite_list_remove(v2);
	script_terminate(a1);
}
// 468B5C: using guessed type int single_player_game;

//----- (00433AF0) --------------------------------------------------------
void script_433AF0_ingame_menu(Script *a1)
{
	Sprite *v1; // edi@7

	script_433640(a1, SCRIPT_TYPE_DA000003, -90, 120, 1);
	if (script_434500(a1, CURSOR_MOBD_OFFSET_780, 1, 0))
	{
		if (!single_player_game)
		{
			if (netz_468B50_available_units_denom <= 2)
				*(_DWORD *)&netz_47A740[2].str_0[0] = 1;
			netz_449FF0();
			is_async_execution_supported = 0;
			dword_47C030 = -1;
			dword_47050C = -1;
			dword_47A738 = 0;
			dword_47CB14 = -1;
			dword_47A180 = 6;
		}
		script_408500_anim(a1);
		script_47A3CC_die();
		game_state = GAME_STATE::GAME_3;
	}
	v1 = a1->sprite;
	sprite_list_remove((Sprite *)a1->param);
	sprite_list_remove(v1);
	script_terminate(a1);
}

//----- (00433BA0) --------------------------------------------------------
void script_433BA0_ingame_menu(Script *a1)
{
	Sprite *v1; // edi@6

	script_433640(a1, SCRIPT_TYPE_DA000003, 0, 120, 1);
	if (script_434500(a1, CURSOR_MOBD_OFFSET_UPGRADE_4_STILL, 1, 0))
	{
		script_trigger_event_group(0, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_DA000003);
		if (_47C65C_render_string)
		{
			render_string_list_remove(_47C65C_render_string);
			_47C65C_render_string = 0;
		}
		if (task_47C028)
			script_trigger_event(0, EVT_MSG_1522_plan_building_construction, 0, task_47C028);
	}
	v1 = a1->sprite;
	sprite_list_remove((Sprite *)a1->param);
	sprite_list_remove(v1);
	script_terminate(a1);
}

//----- (00433C30) --------------------------------------------------------
void script_433C30_ingame_menu(Script *a1)
{
	Sprite *v1; // edi@3

	script_433640(a1, SCRIPT_TYPE_DA000003, -90, 120, 1);
	if (script_434500(a1, CURSOR_MOBD_OFFSET_780, 1, 0))
		game_state = GAME_STATE::GAME_2;
	v1 = a1->sprite;
	sprite_list_remove((Sprite *)a1->param);
	sprite_list_remove(v1);
	script_terminate(a1);
}

//----- (00433C90) --------------------------------------------------------
void script_433C90_ingame_menu(Script *a1)
{
	Sprite *v1; // edi@6

	script_433640(a1, SCRIPT_TYPE_DA000003, 0, 120, 1);
	if (script_434500(a1, CURSOR_MOBD_OFFSET_UPGRADE_4_STILL, 1, 0))
	{
		script_trigger_event_group(0, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_DA000003);
		if (_47C65C_render_string)
		{
			render_string_list_remove(_47C65C_render_string);
			_47C65C_render_string = 0;
		}
		if (task_47C028)
			script_trigger_event(0, EVT_MSG_1522_plan_building_construction, 0, task_47C028);
	}
	v1 = a1->sprite;
	sprite_list_remove((Sprite *)a1->param);
	sprite_list_remove(v1);
	script_terminate(a1);
}

//----- (00433D20) --------------------------------------------------------
void script_433D20_ingame_menu(Script *a1)
{
	Sprite *v1; // edi@6

	script_433640(a1, SCRIPT_TYPE_DA000001, -55, 185, 3);
	if (script_434500(a1, CURSOR_MOBD_OFFSET_UPGRADE_4_RUNNING, 1, 0))
	{
		script_trigger_event_group(a1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_DA000001);
		if (_47C65C_render_string)
			render_string_list_remove(_47C65C_render_string);
		if (a1 != task_47C028)
			script_trigger_event(a1, EVT_MSG_1522_plan_building_construction, 0, task_47C028);
	}
	v1 = a1->sprite;
	sprite_list_remove((Sprite *)a1->param);
	sprite_list_remove(v1);
	script_terminate(a1);
}

//----- (00433DB0) --------------------------------------------------------
void script_433DB0_ingame_menu(Script *a1)
{
	Sprite *v1; // edi@6

	script_433640(a1, SCRIPT_TYPE_DA000001, -200, 153, 3);
    script_sleep(a1, 2);
	dword_47C6C4 = 0;
	if (script_434500(a1, CURSOR_MOBD_OFFSET_UPGRADE_4_RUNNING, 1, 0))
	{
		if (_47C65C_render_string)
		{
			render_string_list_remove(_47C65C_render_string);
			_47C65C_render_string = 0;
		}
		script_trigger_event_group(a1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_DA000001);
		if (a1 != task_47C028)
			script_trigger_event(a1, EVT_MSG_1522_plan_building_construction, 0, task_47C028);
	}
	v1 = a1->sprite;
	sprite_list_remove((Sprite *)a1->param);
	sprite_list_remove(v1);
	script_terminate(a1);
}
// 47C6C4: using guessed type int dword_47C6C4;


//----- (00434220) --------------------------------------------------------
void script_434220_ingame_menu(Script *a1)
{
	_438630_read_save_lst();
	script_4336E0(a1, SCRIPT_TYPE_DA000007, 100, 105, 3);
	stru29_list_4439F0(a1->sprite, 0, 0, 1, 0);
	while (true)
	{
        if (!script_434500(a1, CURSOR_MOBD_OFFSET_1764, 1, 1)) {
            break;
        }
		script_trigger_event(a1, EVT_MSG_1549, 0, receiver);
	}

	sprite_list_remove((Sprite *)a1->param);
	sprite_list_remove(a1->sprite);
	script_terminate(a1);
}

//----- (004342A0) --------------------------------------------------------
void script_4342A0_ingame_menu(Script *a1)
{
	script_4336E0(a1, SCRIPT_TYPE_DA000006, 10, 105, 3);
	stru29_list_4439F0(a1->sprite, 0, 0, 1, 0);
	while (true)
	{
		bool res = script_434500(a1, CURSOR_MOBD_OFFSET_1740, 2, 1);
		script_trigger_event(a1, EVT_MSG_SHOW_UNIT_HINT, 0, receiver);

        if (!res) {
            break;
        }
	}

	sprite_list_remove((Sprite *)a1->param);
	sprite_list_remove(a1->sprite);
	script_terminate(a1);
}

//----- (00434310) --------------------------------------------------------
void script_434310_ingame_menu(Script *a1)
{
	script_4336E0(a1, SCRIPT_TYPE_DA000006, 10, 139, 3);
	stru29_list_4439F0(a1->sprite, 0, 0, 1, 0);
	while (true)
	{
		bool res = script_434500(a1, CURSOR_MOBD_OFFSET_1728, 2, 1);
		script_trigger_event(a1, EVT_MSG_DESELECTED, 0, receiver);
        
        if (!res) {
            break;
        }
	};

	sprite_list_remove((Sprite *)a1->param);
	sprite_list_remove(a1->sprite);
	script_terminate(a1);
}

//----- (00434390) --------------------------------------------------------
void script_434390_ingame_menu(Script *a1)
{
	script_4336E0(a1, SCRIPT_TYPE_DA000007, 100, 139, 3);
	stru29_list_4439F0(a1->sprite, 0, 1, 1, 0);
	if (script_434500(a1, CURSOR_MOBD_OFFSET_1752, 1, 1))
	{
		dword_47C6F8 = 0;
		stru29_list_443BF0_remove_some();
		script_trigger_event_group(a1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_DA000006);
		script_trigger_event_group(a1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_DA000007);
		script_trigger_event_group(a1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_DA000008);
		script_trigger_event_group(a1, EVT_MSG_1546_repair_at_station, 0, SCRIPT_TYPE_1);
		script_trigger_event_group(a1, EVT_MSG_1546_repair_at_station, 0, SCRIPT_TYPE_19);
	}

	sprite_list_remove((Sprite *)a1->param);
	sprite_list_remove(a1->sprite);
	script_terminate(a1);
}
// 47C6F8: using guessed type int dword_47C6F8;

//----- (00434460) --------------------------------------------------------
void script_434460_DA000007(Script *a1)
{
	int v1; // edi@1
	Sprite *v2; // ebx@1
	int v3; // ecx@1
	int v4; // eax@1
	ScriptEvent *i; // eax@2

	v1 = 0;
	v2 = a1->sprite;
	a1->script_type = SCRIPT_TYPE_DA000007;
	v2->drawjob->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_4483E0_sidebar;
	v3 = v2->y;
	v4 = v2->z_index;
	v2->x += 25600;
	v2->y = v3 - 12800;
	v2->z_index = v4 + 1;
	sprite_load_mobd(v2, 1392);
	do
	{
        script_wait_event(a1);
		for (i = script_get_next_event(a1); i; i = script_get_next_event(a1))
		{
			if (i->event == EVT_MSG_1528_cancel)
				v1 = 1;
			script_discard_event(i);
		}
	} while (!v1);
	sprite_list_remove(v2);
	script_terminate(a1);
}

//----- (00434500) --------------------------------------------------------
bool script_434500(Script *a1, int mobd_offset, int a3, int a4)
{
	Script *v4; // ebp@1
	Sprite *v5; // edi@1
	int v6; // ebx@2
	ScriptEvent *i; // esi@4
	int v8; // eax@5
	int v9; // eax@12
	int v10; // ebx@22
	int v11; // esi@23
	ScriptEvent *j; // eax@24
	int v13; // edi@31
	int v14; // esi@32
	ScriptEvent *k; // eax@33
	int v17; // [sp+10h] [bp-8h]@1
	Sprite *v18; // [sp+14h] [bp-4h]@1

	v4 = a1;
	v17 = mobd_offset;
	v5 = a1->sprite;
	v18 = (Sprite *)a1->param;
	while (1)
	{
		while (1)
		{
			v6 = 0;
			if (script_yield_any_trigger(v4, 1) != 0x80000000)
				break;
			sprite_4272E0_load_mobd_item(v18, v17, 0);
			sprite_4272E0_load_mobd_item(v5, 720, a3);
		}
		for (i = script_get_next_event(v4); i; i = script_get_next_event(v4))
		{
			v8 = i->event;
			if (v8 > (int)EVT_MSG_SELECTED)
			{
				v9 = v8 - EVT_MSG_DESELECTED;
				if (v9)
				{
					if (v9 == 16)
						v6 |= 1u;
				}
				else
				{
					v6 |= 8u;
				}
			}
			else if (v8 == EVT_MSG_SELECTED)
			{
				v6 |= 4u;
			}
			else if (v8 == EVT_MOUSE_HOVER)
			{
				if (a4)
					stru29_list_443AE0_find_by_sprite(v5);
				v6 |= 0x10u;
			}
			script_discard_event(i);
		}
		if (v6 & 1)
			return 0;
		if (!dword_47C6C4)
		{
			if (v6 & 0x10)
			{
				sprite_4272E0_load_mobd_item(v18, v17, 2);
				sprite_4272E0_load_mobd_item(v5, 720, a3);
			}
			if (v6 & 4)
				break;
		}
	}
	sprite_4272E0_load_mobd_item(v18, v17, 1);
	sprite_4272E0_load_mobd_item(v5, 708, a3);
	v10 = 1;
	do
	{
		v11 = script_yield(v4, 0x50000000, 0);
		if (!(v11 & SCRIPT_FLAGS_20_10000000))
			break;
		for (j = script_get_next_event(v4); j; j = script_get_next_event(v4))
		{
			if (j->event == EVT_MSG_1528_cancel)
				v10 = 0;
			script_discard_event(j);
		}
		if (v10)
			goto LABEL_31;
	} while (!(v11 & SCRIPT_FLAGS_20_10000000));
	if (!v10)
		return 0;
LABEL_31:
	sprite_4272E0_load_mobd_item(v18, v17, 2);
	sprite_4272E0_load_mobd_item(v5, 720, a3);
	v13 = 1;
	do
	{
		v14 = script_yield(v4, 0x50000000, 0);
		if (!(v14 & SCRIPT_FLAGS_20_10000000))
			break;
		for (k = script_get_next_event(v4); k; k = script_get_next_event(v4))
		{
			if (k->event == EVT_MSG_1528_cancel)
				v13 = 0;
			script_discard_event(k);
		}
		if (v13)
			return 1;
	} while (!(v14 & SCRIPT_FLAGS_20_10000000));
	if (!v13)
		return 0;
	return 1;
}

//----- (00435790) --------------------------------------------------------
void EventHandler_PowerStation(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param)
{
	Script *v4; // edi@1
	Script *v5; // ebx@1
	Entity *v6; // esi@1
	EntityBuildingState *v7; // eax@4
	int v8; // ecx@4
	bool v9; // sf@4

	v4 = receiver;
	v5 = sender;
	v6 = (Entity *)receiver->param;
	if (event == CMD_APPLY_DAMAGE)
	{
		entity_402E90_on_damage(v6, param, entity_mode_powerstation_on_death);
		entity_410520_update_healthbar_color(v6);
	}
	else if (event == EVT_MSG_DESTROY)
	{
		entity_402E40_destroy((Entity *)receiver->param, entity_mode_powerstation_on_death);
	}
	else
	{
		if (event == EVT_MSG_UPGRADE_COMPLETE)
		{
			v7 = (EntityBuildingState *)v6->state;
			v8 = v7->num_upgrades + 1;
			v9 = v7->num_upgrades - 7 < 0;
			v7->num_upgrades = v8;
			if (!((unsigned __int8)(v9 ^ __OFSUB__(v8, 8)) | (v8 == 8)))
				v7->num_upgrades = 8;
			entity_4109A0_status_bar(v6);
		}
		EventHandler_DefaultBuildingsHandler(v4, v5, event, param);
	}
}

//----- (00435820) --------------------------------------------------------
void UNIT_Handler_PowerStation(Script *a1)
{
	Entity *v1; // esi@1

	v1 = (Entity *)a1->param;
	if (!_47C6DC_dont_execute_unit_handlers)
	{
		if (!v1)
		{
			v1 = EntityFactory().Create(a1);
			v1->script->event_handler = EventHandler_PowerStation;
			map_reveal_fog_around_entity(v1);
			v1->script->script_type = SCRIPT_POWER_STATION_HANDLER;
			entity_initialize_building(v1, 2, 0, 0);
			if (!v1->sprite->cplc_ptr1_pstru20)
			{
				entity_402BB0_set_arrive_handler(v1, entity_mode_powerstation_completed);
				v1->ExecMode();
				return;
			}
			v1->SetMode(entity_mode_powerstation_completed);
		}
		v1->ExecMode();
	}
}
// 47C6DC: using guessed type int _47C6DC_dont_execute_unit_handlers;

//----- (004358A0) --------------------------------------------------------
void entity_mode_powerstation_spawn_tanker(Entity *a1)
{
	Entity *v1; // esi@1
	Sprite *v2; // eax@5
	enum UNIT_ID v3; // ecx@5
	Sprite *v4; // eax@6
	int v5; // edx@6
	Sprite *v6; // eax@9
	int v7; // edx@9
	enum PLAYER_SIDE v8; // [sp-4h] [bp-8h]@6
	enum PLAYER_SIDE v9; // [sp-4h] [bp-8h]@9

	v1 = a1;
	if (a1->mode_arrive == entity_mode_powerstation_spawn_tanker)
	{
		a1->mode_arrive = 0;
		a1->SetMode(entity_mode_403650_building);
	}
	script_trigger_event_group(a1->script, EVT_MSG_1549, 0, SCRIPT_TYPE_CA000012);
	if (v1->player_side)
	{
		v2 = v1->sprite;
		v3 = v1->unit_id;
		if (v2->cplc_ptr1_pstru20)
		{
			v2->field_88_unused = 1;
			v4 = v1->sprite;
			v5 = v4->y;
			v8 = v1->player_side;
			if (v3 == UNIT_STATS_SURV_POWER_STATION)
				spawn_unit(UNIT_STATS_SURV_TANKER, v4->x, v5 + 24576, v8);
			else
				spawn_unit(UNIT_STATS_MUTE_TANKER, v4->x, v5 + 24576, v8);
		}
		else
		{
			v2->field_88_unused = 1;
			v6 = v1->sprite;
			v7 = v6->y;
			v9 = v1->player_side;
			if (v3 == UNIT_STATS_SURV_POWER_STATION)
				spawn_unit(UNIT_STATS_SURV_TANKER, v6->x - 0x2000, v7 + 0x2000, v9);
			else
				spawn_unit(UNIT_STATS_MUTE_TANKER, v6->x, v7 + 0x4000, v9);
		}
	}
	else
	{
		v1->mode_arrive = entity_mode_powerstation_spawn_tanker;
	}
}

//----- (00435980) --------------------------------------------------------
void entity_mode_powerstation_completed(Entity *a1)
{
	Entity *v1; // esi@1
	EntityTurret *v2; // eax@1
	enum SOUND_ID v3; // ecx@6
	int v4; // [sp-Ch] [bp-10h]@6

	v1 = a1;
	a1->mode_arrive = 0;
	entity_mode_powerstation_spawn_tanker(a1);
	v2 = v1->turret;
	if (v2)
		v2->turret_sprite->drawjob->flags &= 0xBFFFFFFF;
	if (player_side == v1->player_side && !v1->sprite->cplc_ptr1_pstru20)
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
	if (v1->sprite->cplc_ptr1_pstru20)
	{
		v1->SetMode(entity_mode_4034B0);
	}
	else
	{
		v1->SetMode(entity_mode_403650_building);
	}
    entity_mode_403650_building(v1);
}

//----- (00435A20) --------------------------------------------------------
void entity_mode_powerstation_on_death(Entity *a1)
{
	Entity *v1; // esi@1

	v1 = a1;
	script_trigger_event_group(a1->script, EVT_MSG_1539, 0, SCRIPT_TANKER_CONVOY_HANDLER);
	entity_mode_building_on_death_default(v1);
}

//----- (00437DA0) --------------------------------------------------------
int HUNK_FixPointers(void *data, RllcHunk *rllc)
{
	char *data_base; // esi@1
	unsigned int v3; // eax@1
	unsigned int *v4; // ebx@2
	void *addr; // ecx@3
	int *pdata_hunk; // ebp@4
	int v7; // edi@4
	stru2 *v8; // eax@5
	int(*v9)(void *, int); // ecx@6
	unsigned int num_rebases; // edx@9
	int **ptr; // ecx@9
	int v12; // edx@9
	int *v13; // edi@10
	int prev_data_hunk; // [sp+10h] [bp-10h]@1
	unsigned int v16; // [sp+14h] [bp-Ch]@1
	stru2 *v17 = 0; // [sp+18h] [bp-8h]@0
	unsigned int v18; // [sp+1Ch] [bp-4h]@1

	data_base = (char *)data;
	v3 = 0;
	v18 = rllc->num_relocations;
	prev_data_hunk = 0;
	v16 = 0;
	if (rllc->num_relocations)
	{
		v4 = &rllc->relocations;
		while (1)
		{
			addr = (void *)*v4;
			if (*v4 & 0x80000000)
			{
				pdata_hunk = (int *)&data_base[(unsigned int)addr & 0x7FFFFFFF];
				v7 = *pdata_hunk;
				if (*pdata_hunk == prev_data_hunk)
				{
					*pdata_hunk = (int)v17->draw_handler;
				}
				else
				{
					v8 = stru2_list_create(*pdata_hunk);
					v17 = v8;
					if (!v8)
						return 0;
					v9 = v8->draw_handler;
					v3 = v16;
					prev_data_hunk = v7;
					*pdata_hunk = (int)v9;
				}
			}
			else if ((unsigned int)addr & 0x40000000)
			{
				num_rebases = v4[1];
				++v4;
				ptr = (int **)&data_base[(unsigned int)addr & 0xBFFFFFFF];
				++v3;
				v12 = num_rebases + 1;
				do
				{
					v13 = *ptr;
					++ptr;
					--v12;
					*(ptr - 1) = (int *)((char *)v13 + (_DWORD)data_base);
				} while (v12);
			}
			else
			{
				*(_DWORD *)((char *)addr + (_DWORD)data_base) += (int)data_base;
			}
			++v3;
			++v4;
			v16 = v3;
			if (v3 >= v18)
				return 1;
		}
	}
	return 1;
}

//----- (004391D0) --------------------------------------------------------
void _4391D0_mapd_handler(Mapd_stru0 *a1, void *a2)
{
	a1->mapd_cplc_render_x = *((_DWORD *)a2 + 4) - (render_default_stru1->clip_z << 7);
	a1->mapd_cplc_render_y = *((_DWORD *)a2 + 5) - (render_default_stru1->clip_w << 7);
	a1->mapd_cplc_item0_ptr_field_C = *((_DWORD *)a2 + 6);
}

//----- (00439230) --------------------------------------------------------
bool LVL_InitMapd()
{
	DataMapd *v0; // eax@1
	int v2; // ecx@3
	Bitmap *v3; // eax@5
	int v4; // edx@7
	Bitmap *v5; // ecx@8

	v0 = LVL_FindMapd();
	currently_running_lvl_mapd = v0;
	if (v0)
	{
		v2 = 0;
		currently_running_lvl_mapd_num_items = 0;
		if (v0->items)
		{
			do
				currently_running_lvl_mapd_num_items = ++v2;
			while (v0[v2].items);
		}
		currently_running_lvl_mapd_valid = 1;
		v3 = (Bitmap *)malloc(0x140u);
		bitmap_list = v3;
		if (v3)
		{
			bitmap_list_free_pool = v3;
			v3->prev = (Bitmap *)&bitmap_list_free_pool;
			v4 = 15;
			do
			{
				v5 = v3;
				++v3;
				--v4;
				v5->next = v3;
			} while (v4);
			v3->next = (Bitmap *)&bitmap_list_free_pool;
			bitmap_list_47C364 = (Bitmap *)&bitmap_list_47C360;
			bitmap_list_47C360 = (Bitmap *)&bitmap_list_47C360;
			_47C390_mapd = 0;
			_47C380_mapd.mapd_cplc_item0_ptr_field_C = 0;
			_47C380_mapd.mapd_cplc_render_y = 0;
			_47C380_mapd.mapd_cplc_render_x = 0;
			mapd_j_4391D0_handler = _4391D0_mapd_handler;
			j_drawjob_update_handler_mapd_menu = drawjob_update_handler_mapd_menu;
            return true;
		}
        return false;
	}
	else
	{
		currently_running_lvl_mapd_valid = 0;
        return true;
	}
}

//----- (00439300) --------------------------------------------------------
Bitmap *MAPD_Draw(enum MAPD_ID mapd_idx, unsigned int image_id, int z_index)
{
	unsigned int imAge_id; // ebx@1
	Bitmap *result; // eax@2
	enum MAPD_ID mApd_idx; // edi@3
	DataMapdItem *v6; // eax@3
	Bitmap *v7; // esi@9
	DrawJob *v8; // ecx@10
	MapdScrlImage *img; // eax@10

	imAge_id = image_id;
	if (mapd_idx <= (unsigned int)currently_running_lvl_mapd_num_items)
	{
		mApd_idx = mapd_idx;
		v6 = currently_running_lvl_mapd[mapd_idx].items;
		if ((DataHunk *)v6 == currently_running_lvl)
		{
			result = 0;
		}
		else if (image_id <= v6->num_images)
		{
			if ((Bitmap **)bitmap_list_free_pool == &bitmap_list_free_pool)
			{
				result = 0;
			}
			else
			{
				v7 = bitmap_list_free_pool;
				result = (Bitmap *)draw_list_add(
					bitmap_list_free_pool,
					(DrawUpdateHandler)j_drawjob_update_handler_mapd_menu);
				v7->draw_job = (DrawJob *)result;
				if (result)
				{
					bitmap_list_free_pool = v7->next;
					v7->next = (Bitmap *)&bitmap_list_47C360;
					v7->prev = bitmap_list_47C364;
					bitmap_list_47C364->next = v7;
					bitmap_list_47C364 = v7;
					v8 = v7->draw_job;
					img = currently_running_lvl_mapd[mApd_idx].items->images[imAge_id];
					v7->draw_job_scrl = img;
					v8->job_details.image = img;
					v7->z_index = z_index;
					result = v7;
				}
			}
		}
		else
		{
			result = 0;
		}
	}
	else
	{
		result = 0;
	}
	return result;
}
// 47C37C: using guessed type int currently_running_lvl_mapd_num_items;

//----- (004393C0) --------------------------------------------------------
void bitmap_list_remove(Bitmap *a1)
{
	DrawJob *v1; // eax@1

	v1 = a1->draw_job;
	if (v1)
		v1->flags |= 0x80000000;
	a1->prev->next = a1->next;
	a1->next->prev = a1->prev;
	a1->next = bitmap_list_free_pool;
	bitmap_list_free_pool = a1;
}

//----- (004393F0) --------------------------------------------------------
void _4393F0_call_mapd()
{
	if (currently_running_lvl_mapd_valid && _47C390_mapd)
	{
		if (mapd_j_4391D0_handler)
			mapd_j_4391D0_handler(&_47C380_mapd, (void *)_47C390_mapd);
	}
}

//----- (00439420) --------------------------------------------------------
void bitmap_list_free()
{
	if (currently_running_lvl_mapd_valid)
	{
		if (bitmap_list)
			free(bitmap_list);
	}
}

//----- (0043BA40) --------------------------------------------------------
void script_43BA40(Script *a1, int a2, int(*a3)(void), int a4)
{
	int v4; // esi@1
	Script *v5; // edi@1
	int v6; // eax@2

	v4 = a2;
	v5 = a1;
	do
		v6 = a3();
	while (!script_443780(v5, v4, v6, a4));
}

//----- (0043BA70) --------------------------------------------------------
void script_netz_43BA70(Script *a1)
{
	script_408500_anim(a1);
	script_terminate(a1);
}

//----- (0043BA90) --------------------------------------------------------
Script *netz_43BA90_create_script_43BA70()
{
	return script_create_coroutine(SCRIPT_TYPE_INVALID, script_netz_43BA70, 0);
}

//----- (0043BAA0) --------------------------------------------------------
void sub_43BAA0()
{
	dword_47C6C4 = 1;
}
// 47C6C4: using guessed type int dword_47C6C4;

//----- (0043BAB0) --------------------------------------------------------
void _43BAB0_move_cursor(Sprite *a1)
{
	Sprite *v1; // esi@1
	enum SCRIPT_TYPE v2; // eax@1
	int v3; // eax@4
	int v4; // edx@4
	int v5; // eax@8
	int v6; // eax@9
	int v7; // ebx@21
	int v8; // eax@21

	v1 = _47C6E0_task->sprite;
	v2 = a1->script->script_type;
	if (v2 > SCRIPT_TYPE_14)
	{
		if (v2 > SCRIPT_TYPE_19)
		{
			if (v2 == SCRIPT_TYPE_DA000006 || v2 == SCRIPT_TYPE_DA000007)
			{
				v3 = 8704;
				v4 = 4096;
				goto LABEL_21;
			}
			if (v2 == SCRIPT_TYPE_DA000008)
			{
				v3 = 1024;
				v4 = 0;
				goto LABEL_21;
			}
		}
		else
		{
			if (v2 == SCRIPT_TYPE_19)
				goto LABEL_14;
			v5 = v2 - 15;
			if (!v5)
			{
				v3 = 6400;
				v4 = 10240;
				goto LABEL_21;
			}
			v6 = v5 - 1;
			if (!v6)
			{
				v3 = 512;
				v4 = 3072;
				goto LABEL_21;
			}
			if (v6 == 2)
			{
				v3 = 5120;
				v4 = 5120;
				goto LABEL_21;
			}
		}
		v3 = 15360;
		v4 = 10240;
		goto LABEL_21;
	}
	if (v2 == SCRIPT_TYPE_14)
	{
		v3 = 512;
		v4 = 0;
		goto LABEL_21;
	}
	if (v2 == 1)
	{
	LABEL_14:
		v3 = 29696;
		v4 = 6144;
		goto LABEL_21;
	}
	v3 = 15360;
	v4 = 10240;
LABEL_21:
	v1->field_88_unused = 1;
	v7 = v3 + a1->x;
	a1->field_88_unused = 1;
	v1->x = v7;
	v1->field_88_unused = 1;
	v8 = v4 + a1->y;
	v1->field_88_unused = 1;
	v1->y = v8;
	input_set_mouse_pos(v7 >> 8, v8 >> 8);
}

//----- (0043C040) --------------------------------------------------------
void script_43C040_cursors_handler(Script *a1)
{
	netz_47C6BC_mapd_idx = 0;
	netz_47C6C0_mapd_idx = 0;
	if (!_47C6E0_task)
	{
        stru29_list_alloc();
		sprite_create_scripted(MOBD_79, 0, script_mobd79__main_menu_mouse_handler, SCRIPT_COROUTINE, 0);
	}
	sprite_list_remove(a1->sprite);
	script_terminate(a1);
}

//----- (0043CD20) --------------------------------------------------------
void script_43CD20_mobd45_begin_surv_campaign(Script *a1)
{
	Sprite *v1; // eax@1
	Sprite *v2; // esi@1
	int v3; // ebx@1
	ScriptEvent *i; // eax@2
	enum SCRIPT_EVENT v5; // edx@3

	v1 = a1->sprite;
	v1->x = 48640;
	v1->y = 43008;
	v2 = a1->sprite;
	v2->parent = 0;
	a1->script_type = SCRIPT_TYPE_15;
	stru29_list_4439F0(v2, 0, 0, 0, 0);
	sprite_load_mobd(v2, 1380);
	v3 = 0;
	do
	{
        script_wait_event(a1);
		for (i = script_get_next_event(a1); i; i = script_get_next_event(a1))
		{
			v5 = i->event;
			switch (v5)
			{
			case EVT_MOUSE_HOVER:
                stru29_list_443AE0_find_by_sprite(a1->sprite);
				break;
			case EVT_MSG_SELECTED:
				v3 = 1;
				break;
			case EVT_MSG_1528_cancel:
				v3 = 1;
				break;
			}
			script_discard_event(i);
		}
	} while (!v3);
	player_side = SURVIVORS;
	current_level_idx = LEVEL_SURV_01_THE_NEXT_GENERATION;
	script_408500_anim(a1);
	_47C6D8_use__466098_cost_multipliers = 0;
	single_player_game = 1;
	netz_42E7F0();
	stru29_list_remove_all(a1);
	game_state = GAME_STATE::Mission;
	script_deinit(_47C6E0_task);
	_47C6E0_task = 0;
}

//----- (0043CE30) --------------------------------------------------------
void script_43CE30_mobd45_begin_mute_campaign(Script *a1)
{
	Sprite *v1; // eax@1
	Sprite *v2; // esi@1
	int v3; // ebx@1
	ScriptEvent *i; // eax@2
	enum SCRIPT_EVENT v5; // edx@3

	v1 = a1->sprite;
	v1->x = 0x1AC00;
	v1->y = 0xA800;
	v2 = a1->sprite;
	v2->parent = 0;
	a1->script_type = SCRIPT_TYPE_15;
	stru29_list_4439F0(v2, 0, 0, 0, 0);
	sprite_load_mobd(v2, 1380);
	v3 = 0;
	do
	{
        script_wait_event(a1);
		for (i = script_get_next_event(a1); i; i = script_get_next_event(a1))
		{
			v5 = i->event;
			switch (v5)
			{
			case EVT_MOUSE_HOVER:
                stru29_list_443AE0_find_by_sprite(a1->sprite);
			case EVT_MSG_SELECTED:
				v3 = 1;
				break;
			case EVT_MSG_1528_cancel:
				v3 = 1;
				break;
			}
			script_discard_event(i);
		}
	} while (!v3);
	player_side = EVOLVED;
	current_level_idx = LEVEL_MUTE_01;
	script_408500_anim(a1);
	_47C6D8_use__466098_cost_multipliers = 0;
	single_player_game = 1;
	netz_42E7F0();
	stru29_list_remove_all(a1);
	game_state = GAME_STATE::Mission;
	script_deinit(_47C6E0_task);
	_47C6E0_task = 0;
}

//----- (0043CF50) --------------------------------------------------------
void script_43CF50_mobd45(Script *a1)
{
	Sprite *v1; // edi@1
	Sprite *v2; // eax@1
	DataMapd *v5; // eax@7

	v1 = a1->sprite;
	v2 = sprite_create(MOBD_45, 0, a1->sprite);
	v1->mobd_id = MOBD_45;
	v1->parent = v2;
	v2->parent = 0;
	v2->z_index = 0;
	v1->z_index = 1;
	a1->script_type = SCRIPT_TYPE_17;
	stru29_list_4439F0(v1, 0, 1, 1, 0);
	while (!script_443780(a1, 2044, 1, 0))
		;
	netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
	netz_47C6C0_mapd_idx = 0;
	script_408500_anim(a1);
    stru29_list_realloc(a1);
	bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    script_sleep(a1, 3);
	v5 = LVL_FindMapd();
	_40E400_set_palette(v5->items->GetPalette());
	_47A010_mapd_item_being_drawn[0] = MAPD_Draw(MAPD_MAP, 0, -10);
	cplc_select(0);
	cplc_406320();
    script_sleep(a1, 1);
	script_4084A0_animation(a1);
	script_terminate(a1);
}
// 47C6C8: using guessed type int stru29_list_initialized;

//----- (0043D090) --------------------------------------------------------
void script_43D090_mobd45_directx_ipx(Script *a1)
{
	Sprite *v1; // edi@3
	Sprite *v2; // eax@3
	int v3; // eax@3
	int v4; // edi@3
	DataMapd *v7; // eax@11
	DWORD pcbBuffer; // [sp+Ch] [bp-4h]@2

	if (dword_46E404)
	{
        netz_default_player_name[0] = 0;

        auto username = OsGetUserName();
        strncat(netz_default_player_name, username.c_str(), 12);
		//pcbBuffer = 12;
		//GetUserNameA(netz_default_player_name, &pcbBuffer);
	}
	v1 = a1->sprite;
	v2 = sprite_create(MOBD_45, 0, a1->sprite);
	v1->mobd_id = MOBD_45;
	v1->parent = v2;
	v2->parent = 0;
	v2->z_index = 0;
	v1->z_index = 1;
	a1->script_type = SCRIPT_TYPE_2;
	stru29_list_4439F0(v1, 0, 0, 1, 0);
	v3 = netz_42FAC0(aDirectxIpx);
	v4 = v3;
	if (v3 != -1)
	{
		if (netz_468B6C_providers[v3].is_directplay_initialized)
		{
			while (!script_443780(a1, 1792, 1, 0))
				;
			_46E420_starting_cash_idx = 1280;
			if (netz_42E170(v4, netz_default_player_name))
			{
				netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
				netz_47C6C0_mapd_idx = 4;
				script_408500_anim(a1);
                stru29_list_realloc(a1);
				bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
                script_sleep(a1, 3);
				v7 = LVL_FindMapd();
				_40E400_set_palette(v7[4].items->GetPalette());
				_47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)4, 0, -10);
				cplc_select(4);
				cplc_406320();
                script_sleep(a1, 1);
				script_4084A0_animation(a1);
				script_terminate(a1);
			}
		}
		else
		{
			while (!script_443780(a1, 1792, 0, 0))
				;
		}
	}
}

//----- (0043D270) --------------------------------------------------------
void script_43D270_mobd45_directx_serial(Script *a1)
{
	Sprite *v1; // edi@1
	Sprite *v2; // eax@1
	int v3; // edi@1
	DataMapd *v6; // eax@9

	v1 = a1->sprite;
	v2 = sprite_create(MOBD_45, 0, a1->sprite);
	v1->mobd_id = MOBD_45;
	v1->parent = v2;
	v2->parent = 0;
	v2->z_index = 0;
	v1->z_index = 1;
	a1->script_type = SCRIPT_TYPE_2;
	stru29_list_4439F0(v1, 0, 0, 1, 0);
	v3 = netz_42FAC0(aDirectxSerial);
	if (v3 != -1)
	{
		if (netz_468B6C_providers[v3].is_directplay_initialized)
		{
			while (!script_443780(a1, 1904, 1, 0))
				;
			_46E420_starting_cash_idx = 1280;
			if (netz_42E170(v3, netz_default_player_name))
			{
				netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
				netz_47C6C0_mapd_idx = 5;
				script_408500_anim(a1);
                stru29_list_realloc(a1);
				bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
                script_sleep(a1, 3);
				v6 = LVL_FindMapd();
				_40E400_set_palette(v6[5].items->GetPalette());
				_47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)5, 0, -10);
				cplc_select(5);
				cplc_406320();
                script_sleep(a1, 1);
				script_4084A0_animation(a1);
				script_terminate(a1);
			}
		}
		else
		{
			while (!script_443780(a1, 1904, 0, 0))
				;
		}
	}
}
// 47C5FC: using guessed type int _46E420_starting_cash_idx;
// 47C6C8: using guessed type int stru29_list_initialized;

//----- (0043D430) --------------------------------------------------------
void script_43D430_mobd45_directx_modem(Script *a1)
{
	Sprite *v1; // edi@1
	Sprite *v2; // eax@1
	int v3; // edi@1
	DataMapd *v6; // eax@9

	v1 = a1->sprite;
	v2 = sprite_create(MOBD_45, 0, a1->sprite);
	v1->mobd_id = MOBD_45;
	v1->parent = v2;
	v2->parent = 0;
	v2->z_index = 0;
	v1->z_index = 1;
	a1->script_type = SCRIPT_TYPE_2;
	stru29_list_4439F0(v1, 0, 0, 1, 0);
	v3 = netz_42FAC0(aDirectxModem);
	if (v3 != -1)
	{
		if (netz_468B6C_providers[v3].is_directplay_initialized)
		{
			while (!script_443780(a1, 1888, 1, 0))
				;
			_46E420_starting_cash_idx = 1280;
			if (netz_42E170(v3, netz_default_player_name))
			{
				netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
				netz_47C6C0_mapd_idx = 6;
				script_408500_anim(a1);
                stru29_list_realloc(a1);
				bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
                script_sleep(a1, 3);
				v6 = LVL_FindMapd();
				_40E400_set_palette(v6[6].items->GetPalette());
				_47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)6, 0, -10);
				cplc_select(6);
				cplc_406320();
                script_sleep(a1, 1);
				script_4084A0_animation(a1);
				script_terminate(a1);
			}
		}
		else
		{
			while (!script_443780(a1, 1888, 0, 0))
				;
		}
	}
}
// 47C5FC: using guessed type int _46E420_starting_cash_idx;
// 47C6C8: using guessed type int stru29_list_initialized;

//----- (0043D5F0) --------------------------------------------------------
void script_43D5F0_mobd45(Script *a1)
{
	Sprite *v1; // edi@1
	Sprite *v2; // eax@1
	DataMapd *v5; // eax@7

	netz_free_provider_async();
	v1 = a1->sprite;
	v2 = sprite_create(MOBD_45, 0, a1->sprite);
	v1->mobd_id = MOBD_45;
	v1->parent = v2;
	v2->parent = 0;
	v2->z_index = 0;
	v1->z_index = 1;
	a1->script_type = SCRIPT_TYPE_17;
	stru29_list_4439F0(v1, 0, 1, 1, 0);
	while (!script_443780(a1, 2044, 1, 0))
		;
	netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
	netz_47C6C0_mapd_idx = 0;
	script_408500_anim(a1);
    stru29_list_realloc(a1);
	bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    script_sleep(a1, 3);
	v5 = LVL_FindMapd();
	_40E400_set_palette(v5->items->GetPalette());
	_47A010_mapd_item_being_drawn[0] = MAPD_Draw(MAPD_MAP, 0, -10);
	cplc_select(0);
	cplc_406320();
    script_sleep(a1, 1);
	script_4084A0_animation(a1);
	script_terminate(a1);
}
// 47C6C8: using guessed type int stru29_list_initialized;

//----- (0043D740) --------------------------------------------------------
void script_43D740_mobd45_evt17(Script *a1)
{
	Sprite *v1; // edi@1
	Sprite *v2; // eax@1
	DataMapd *v5; // eax@7

	v1 = a1->sprite;
	v2 = sprite_create(MOBD_45, 0, a1->sprite);
	v1->mobd_id = MOBD_45;
	v1->parent = v2;
	v2->parent = 0;
	v2->z_index = 0;
	v1->z_index = 1;
	a1->script_type = SCRIPT_TYPE_17;
	stru29_list_4439F0(v1, 0, 0, 1, 0);
	while (!script_443780(a1, 2044, 1, 0))
		;
	netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
	netz_47C6C0_mapd_idx = 6;
	script_408500_anim(a1);
    stru29_list_realloc(a1);
	bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    script_sleep(a1, 3);
	v5 = LVL_FindMapd();
	_40E400_set_palette(v5[6].items->GetPalette());
	_47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)6, 0, -10);
	cplc_select(6);
	cplc_406320();
    script_sleep(a1, 1);
	script_4084A0_animation(a1);
	script_terminate(a1);
}
// 47C6C8: using guessed type int stru29_list_initialized;

//----- (0043D890) --------------------------------------------------------
void script_43D890_mobd45(Script *a1)
{
	Sprite *v1; // edi@1
	Sprite *v2; // eax@1
	DataMapd *v5; // eax@7

	v1 = a1->sprite;
	v2 = sprite_create(MOBD_45, 0, a1->sprite);
	v1->mobd_id = MOBD_45;
	v1->parent = v2;
	v2->parent = 0;
	v2->z_index = 0;
	v1->z_index = 1;
	a1->script_type = SCRIPT_TYPE_17;
	stru29_list_4439F0(v1, 0, 1, 1, 0);
	while (!script_443780(a1, 2044, 1, 0))
		;
	netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
	netz_47C6C0_mapd_idx = 6;
	script_408500_anim(a1);
    stru29_list_realloc(a1);
	bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    script_sleep(a1, 3);
	v5 = LVL_FindMapd();
	_40E400_set_palette(v5[6].items->GetPalette());
	_47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)6, 0, -10);
	cplc_select(6);
	cplc_406320();
    script_sleep(a1, 1);
	script_4084A0_animation(a1);
	script_terminate(a1);
}
// 47C6C8: using guessed type int stru29_list_initialized;

//----- (0043D9E0) --------------------------------------------------------
void input_get_string_43D9E0_handler(const char *a1, int a2)
{
	const char *v2; // esi@1
	unsigned __int16 v3; // ST08_2@1
	stru8 *v4; // eax@1
	int v5; // ecx@1

	v2 = a1;
	v3 = a2;
	render_string_445AE0(_47C65C_render_string);
	_47C65C_render_string->field_18 = 0;
	_47C65C_render_string->num_lines = 0;
	render_string_443D80(_47C65C_render_string, v2, 0);
	_47C664_ingame_menu_sprite->field_88_unused = 1;
	v4 = _47C65C_render_string->pstru8;
	v5 = _47C65C_render_string->field_C + v3 + 1;
	if (_47C65C_render_string->field_C + v3 != -1)
	{
		do
		{
			v4 = v4->next;
			--v5;
		} while (v5);
	}
	_47C664_ingame_menu_sprite->x = v4->drawjob->job_details.x << 8;
	_47C664_ingame_menu_sprite->field_88_unused = 1;
	_47C664_ingame_menu_sprite->y = 46080;
}

//----- (0043DA80) --------------------------------------------------------
void script_43DA80_mobd45_modem(Script *a1)
{
	Sprite *v1; // esi@1
	netz_modem *v2; // ebx@1
	Sprite *v3; // edi@3
	RenderString *v4; // edx@3
	char *v5; // ebx@3
	int v6; // edi@4
	ScriptEvent *i; // eax@5
	enum SCRIPT_EVENT v8; // edx@6
	Sprite *v10; // eax@18
	int v11; // edx@18
	int v12; // ecx@18
	int v13; // esi@18
	char v14; // al@19

	v1 = a1->sprite;
	v2 = (netz_modem *)a1->param;
	_47C664_ingame_menu_sprite = sprite_create(MOBD_FONT_ITALIC, 0, a1->sprite);
	_47C65C_render_string = render_string_create(
		0,
		currently_running_lvl_mobd[MOBD_FONT_ITALIC].items,
		346,
		164,
		22,
		3,
		90,
		14,
		16);
	if (!_47C65C_render_string)
	{
		sprite_list_remove(v1);
		script_terminate(a1);
	}
	v1->x = 0x16800;
	v1->y = 0xB000;
	v1->z_index = 90;
	v3 = a1->sprite;
	v4 = _47C65C_render_string;
	v3->parent = 0;
	a1->script_type = SCRIPT_TYPE_18;
	stru29_list_4439F0(v3, v4, 0, 0, 0);
	sprite_load_mobd(v3, 1356);
	v5 = v2->name;
	v1->parent = _47C664_ingame_menu_sprite;
	while (1)
	{
		render_string_445AE0(_47C65C_render_string);
		_47C65C_render_string->field_18 = 0;
		_47C65C_render_string->num_lines = 0;
		render_string_443D80(_47C65C_render_string, v5, 0);
		v6 = 0;
		do
		{
            script_wait_event(a1);
			for (i = script_get_next_event(a1); i; i = script_get_next_event(a1))
			{
				v8 = i->event;
				switch (v8)
				{
				case EVT_MOUSE_HOVER:
                    stru29_list_443AE0_find_by_sprite(a1->sprite);
					break;
				case EVT_MSG_SELECTED:
					v6 = 1;
					break;
				case EVT_MSG_1528_cancel:
					v6 = 1;
					break;
				}
				script_discard_event(i);
			}
		} while (!v6);
		_47C664_ingame_menu_sprite->field_88_unused = 1;
		_47C664_ingame_menu_sprite->x = 92672;
		_47C664_ingame_menu_sprite->field_88_unused = 1;
		_47C664_ingame_menu_sprite->y = 46080;
		_47C664_ingame_menu_sprite->z_index = 10;
		sprite_load_mobd(_47C664_ingame_menu_sprite, 1096);
		dword_47C6C4 = 1;
		input_get_string(v5, 0xBu, input_get_string_43D9E0_handler, 1, a1);
		v10 = _47C6E0_task->sprite;
		v11 = v10->y >> 8;
		v12 = v10->x >> 8;
		v10->field_88_unused = 1;
		input_set_mouse_pos(v12, v11);
		dword_47C6C4 = 0;
		v13 = 0;
		do
		{
			v14 = v5[v13];
			if (!v14)
				break;
			if (!isalpha(v14) && !isdigit(v5[v13]))
				v5[v13] = 95;
			++v13;
		} while (v13 < 10);
		v5[11] = 0;
		_47C664_ingame_menu_sprite->field_88_unused = 1;
		_47C664_ingame_menu_sprite->x = 92672;
		_47C664_ingame_menu_sprite->field_88_unused = 1;
		_47C664_ingame_menu_sprite->y = 46080;
		sprite_release_mobd_item(_47C664_ingame_menu_sprite);
	}
}
// 47C6C4: using guessed type int dword_47C6C4;

//----- (0043DCF0) --------------------------------------------------------
void input_get_string_43DCF0_handler(const char *a1, int a2)
{
	const char *v2; // esi@1
	unsigned __int16 v3; // ST08_2@1
	stru8 *v4; // eax@1
	int v5; // ecx@1

	v2 = a1;
	v3 = a2;
	render_string_445AE0(_47C604_mission_briefing);
	_47C604_mission_briefing->field_18 = 0;
	_47C604_mission_briefing->num_lines = 0;
	render_string_443D80(_47C604_mission_briefing, v2, 0);
	_47C664_ingame_menu_sprite->field_88_unused = 1;
	v4 = _47C604_mission_briefing->pstru8;
	v5 = _47C604_mission_briefing->field_C + v3 + 1;
	if (_47C604_mission_briefing->field_C + v3 != -1)
	{
		do
		{
			v4 = v4->next;
			--v5;
		} while (v5);
	}
	_47C664_ingame_menu_sprite->x = v4->drawjob->job_details.x << 8;
	_47C664_ingame_menu_sprite->field_88_unused = 1;
	_47C664_ingame_menu_sprite->y = 60416;
}

//----- (0043DD90) --------------------------------------------------------
void script_43DD90_mobd45_modem(Script *a1)
{
	Script *v1; // ebx@1
	netz_modem *v2; // edi@1
	Sprite *v3; // esi@1
	int v4; // ebp@1
	Sprite *v5; // esi@3
	RenderString *v6; // edx@3
	const char *v7; // edi@3
	ScriptEvent *i; // eax@5
	enum SCRIPT_EVENT v9; // edx@6
	const char *v11; // esi@18
	int v12; // ebp@18
	int v13; // edx@22
	int v14; // ecx@22
	Sprite *v15; // eax@22
	int v16; // edx@22
	int v17; // ecx@22
	netz_modem *v18; // [sp+10h] [bp-10h]@1
	Script *v19; // [sp+14h] [bp-Ch]@18
	int v20; // [sp+18h] [bp-8h]@18
	int v21; // [sp+1Ch] [bp-4h]@18
	Script *a1a; // [sp+24h] [bp+4h]@3

	v1 = a1;
	v2 = (netz_modem *)a1->param;
	v3 = a1->sprite;
	v18 = (netz_modem *)a1->param;
	v4 = 0;
	_47C604_mission_briefing = render_string_create(
		0,
		currently_running_lvl_mobd[MOBD_FONT_ITALIC].items,
		320,
		220,
		22,
		3,
		90,
		14,
		16);
	if (!_47C604_mission_briefing)
	{
		sprite_list_remove(v3);
		script_terminate(a1);
	}
	v3->x = 85504;
	v3->y = 59392;
	v3->z_index = 90;
	v5 = a1->sprite;
	v6 = _47C604_mission_briefing;
	v5->parent = 0;
	a1->script_type = SCRIPT_TYPE_18;
	stru29_list_4439F0(v5, v6, 0, 0, 0);
	sprite_load_mobd(v5, 1356);
	v7 = v2->phone;
	a1a = (Script *)v7;
	while (1)
	{
		render_string_445AE0(_47C604_mission_briefing);
		_47C604_mission_briefing->field_18 = 0;
		_47C604_mission_briefing->num_lines = 0;
		render_string_443D80(_47C604_mission_briefing, v7, 0);
		do
		{
            script_wait_event(v1);
			for (i = script_get_next_event(v1); i; i = script_get_next_event(v1))
			{
				v9 = i->event;
				switch (v9)
				{
				case EVT_MOUSE_HOVER:
                    stru29_list_443AE0_find_by_sprite(v1->sprite);
					break;
				case EVT_MSG_SELECTED:
					v4 = 1;
					break;
				case EVT_MSG_1528_cancel:
					v4 = 1;
					break;
				}
				script_discard_event(i);
			}
		} while (!v4);
		_47C664_ingame_menu_sprite->field_88_unused = 1;
		_47C664_ingame_menu_sprite->x = 86016;
		_47C664_ingame_menu_sprite->field_88_unused = 1;
		_47C664_ingame_menu_sprite->y = 60416;
		_47C664_ingame_menu_sprite->z_index = 10;
		sprite_load_mobd(_47C664_ingame_menu_sprite, 1096);
		dword_47C6C4 = 1;
		input_get_string(v7, 0xBu, input_get_string_43DCF0_handler, 1, v1);
		v19 = 0;
		v11 = v7;
		v20 = 0;
		v12 = 0;
		v21 = 0;
		do
		{
			if (isdigit(*v11))
				*((_BYTE *)&v19 + v12++) = *v11;
			++v11;
		} while ((int)&v11[-20 - (_DWORD)v18] < 12);
		*((_BYTE *)&v19 + v12) = 0;
		v13 = v20;
		a1a->next = v19;
		v14 = v21;
		a1a->prev = (Script *)v13;
		a1a->locals_list = (ScriptLocalObject *)v14;
		v15 = _47C6E0_task->sprite;
		v16 = v15->y >> 8;
		v17 = v15->x >> 8;
		v15->field_88_unused = 1;
		input_set_mouse_pos(v17, v16);
		dword_47C6C4 = 0;
		_47C664_ingame_menu_sprite->field_88_unused = 1;
		_47C664_ingame_menu_sprite->x = 86016;
		_47C664_ingame_menu_sprite->field_88_unused = 1;
		_47C664_ingame_menu_sprite->y = 60416;
		sprite_release_mobd_item(_47C664_ingame_menu_sprite);
		v7 = (const char *)a1a;
		v4 = 0;
	}
}
// 47C6C4: using guessed type int dword_47C6C4;

//----- (0043E010) --------------------------------------------------------
void script_43E010_mobd45_modem(Script *a1)
{
	netz_modem *v1; // ebp@1
	Sprite *v2; // esi@1
	RenderString *v3; // ebx@1
	Sprite *v4; // esi@3
	Sprite *v5; // eax@3
	int v6; // eax@6
	char a2[12]; // [sp+10h] [bp-Ch]@4

	v1 = (netz_modem *)a1->param;
	v2 = a1->sprite;
	v3 = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 296, 274, 12, 3, 90, 14, 16);
	if (!v3)
	{
		sprite_list_remove(v2);
		script_terminate(a1);
	}
	v2->x = 32512;
	v2->y = 67584;
	v2->z_index = 90;
	v4 = a1->sprite;
	v5 = sprite_create(MOBD_45, 0, a1->sprite);
	v4->mobd_id = MOBD_45;
	v4->parent = v5;
	v5->parent = 0;
	v5->z_index = 0;
	v4->z_index = 1;
	a1->script_type = SCRIPT_TYPE_10;
	stru29_list_4439F0(v4, v3, 0, 1, 0);
	while (1)
	{
		render_string_445AE0(v3);
		v3->field_18 = 0;
		v3->num_lines = 0;
		_itoa(dword_46E408[v1->baud], a2, 10);
		render_string_443D80(v3, a2, 0);
		while (!script_443780(a1, 2008, 1, 0))
			;
		v6 = v1->baud + 1;
		v1->baud = v6;
		if (v6 >= 5)
			v1->baud = 0;
	}
}

//----- (0043E110) --------------------------------------------------------
int script_43E110_modem(Script *a1, netz_modem *param, int a3)
{
	netz_modem *v3; // ebx@1
	Script *v4; // ebp@1
	Sprite *v5; // eax@1
	Script *v6; // eax@2
	Sprite *v7; // eax@4
	Script *v8; // eax@5
	Sprite *v9; // eax@7
	Script *v10; // eax@8
	Sprite *v11; // esi@10
	Sprite *v12; // eax@10
	int v13; // edi@11
	int v14; // esi@11
	int v15; // esi@17
	int result; // eax@22

	v3 = param;
	v4 = a1;
	v5 = sprite_create_scripted(MOBD_45, 0, (void(*)(Script *))script_43E010_mobd45_modem, SCRIPT_COROUTINE, 0);
	if (v5)
	{
		v6 = v5->script;
		if (v6)
			v6->param = v3;
	}
	v7 = sprite_create_scripted(MOBD_45, 0, (void(*)(Script *))script_43DA80_mobd45_modem, SCRIPT_COROUTINE, 0);
	if (v7)
	{
		v8 = v7->script;
		if (v8)
			v8->param = v3;
	}
	v9 = sprite_create_scripted(MOBD_45, 0, (void(*)(Script *))script_43DD90_mobd45_modem, SCRIPT_COROUTINE, 0);
	if (v9)
	{
		v10 = v9->script;
		if (v10)
			v10->param = v3;
	}
	v11 = v4->sprite;
	v12 = sprite_create(MOBD_45, 0, v4->sprite);
	v11->mobd_id = MOBD_45;
	v11->parent = v12;
	v12->parent = 0;
	v12->z_index = 0;
	v11->z_index = 1;
	v4->script_type = SCRIPT_TYPE_10;
	stru29_list_4439F0(v11, 0, 1, 1, 0);
	do
	{
		v13 = 0;
		v14 = 0;
		while (!isalpha(v3->name[v14]))
		{
			if (++v14 >= 12)
				goto LABEL_16;
		}
		v13 = 1;
	LABEL_16:
		if (v13)
		{
			v13 = 0;
			v15 = 0;
			while (!isdigit(v3->phone[v15]))
			{
				if (++v15 >= 12)
					goto LABEL_22;
			}
			v13 = 1;
		}
	LABEL_22:
		result = script_443780(v4, a3, v13 != 0, 0);
	} while (!result);
	return result;
}

//----- (0043E230) --------------------------------------------------------
void script_43E230_mobd45_modems(Script *a1)
{
	Script *v1; // ebx@1
	netz_modem *v2; // edx@1
	int v3; // ebp@1
	int v4; // eax@5
	FILE *v5; // edi@6
	netz_modem *i; // esi@7
	int v7; // ecx@10
	DataMapd *v10; // eax@14
	netz_modem v11; // [sp+10h] [bp-24h]@1

	*(_DWORD *)&v11.phone[0] = 0;                 // INLINED memset`s
	v1 = a1;
	*(_DWORD *)&v11.name[0] = 0;
	*(_DWORD *)&v11.phone[4] = 0;
	*(_DWORD *)&v11.name[4] = 0;
	*(_DWORD *)&v11.phone[8] = 0;
	v11.baud = 0;
	*(_DWORD *)&v11.name[8] = 0;
	script_43E110_modem(a1, &v11, 1776);
	v2 = netz_modem_list_free_pool;
	v3 = v11.baud;
	if (netz_modem_list_free_pool)
		netz_modem_list_free_pool = netz_modem_list_free_pool->next;
	else
		v2 = 0;
	if (v2)
	{
		v4 = (int)v2->name;
		++netz_modem_list_used;
		*(_DWORD *)v4 = 0;
		*(_DWORD *)(v4 + 4) = 0;
		*(_DWORD *)(v4 + 8) = 0;
		strcpy(v2->name, v11.name);
		*(_DWORD *)&v2->phone[0] = 0;
		*(_DWORD *)&v2->phone[4] = 0;
		*(_DWORD *)&v2->phone[8] = 0;
		v1 = a1;
		strcpy(v2->phone, v11.phone);
		v2->baud = v3;
		v2->next = netz_modem_list;
		v2->prev = (netz_modem *)&netz_modem_list;
		netz_modem_list->prev = v2;
		netz_modem_list = v2;
	}
	v5 = fopen(aModem_lst, (const char *)aW);
	if (v5)
	{
		for (i = netz_modem_list; (netz_modem **)i != &netz_modem_list; i = i->next)
			fprintf(v5, format, i->name, i->phone, i->baud);
		fclose(v5);
	}
	v7 = netz_47C6C0_mapd_idx;
	netz_47C6C0_mapd_idx = 6;
	netz_47C6BC_mapd_idx = v7;
	script_408500_anim(v1);
    stru29_list_realloc(v1);
	bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    script_sleep(v1, 3);
	v10 = LVL_FindMapd();
	_40E400_set_palette(v10[6].items->GetPalette());
	_47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)6, 0, -10);
	cplc_select(6);
	cplc_406320();
    script_sleep(v1, 1);
	script_4084A0_animation(v1);
	script_terminate(v1);
}
// 47C6C8: using guessed type int stru29_list_initialized;

//----- (0043E470) --------------------------------------------------------
void script_43E470_mobd45_modems(Script *a1)
{
	netz_modem *v1; // eax@1
	int v2; // ecx@1
	netz_modem *v3; // ebx@4
	FILE *v4; // edi@5
	netz_modem *i; // esi@6
	int v6; // ecx@9
	DataMapd *v9; // eax@13
	netz_modem a2; // [sp+10h] [bp-24h]@5

	v1 = netz_modem_list;
	v2 = 0;
	if ((netz_modem **)netz_modem_list == &netz_modem_list)
	{
	LABEL_4:
		v3 = 0;
	}
	else
	{
		while (v2 != netz_modem_47C6CC_idx)
		{
			v1 = v1->next;
			++v2;
			if ((netz_modem **)v1 == &netz_modem_list)
				goto LABEL_4;
		}
		v3 = v1;
	}
	*(_DWORD *)&a2.name[0] = *(_DWORD *)&v3->name[0];
	*(_DWORD *)&a2.name[4] = *(_DWORD *)&v3->name[4];
	*(_DWORD *)&a2.name[8] = *(_DWORD *)&v3->name[8];
	*(_DWORD *)&a2.phone[0] = *(_DWORD *)&v3->phone[0];
	*(_DWORD *)&a2.phone[4] = *(_DWORD *)&v3->phone[4];
	*(_DWORD *)&a2.phone[8] = *(_DWORD *)&v3->phone[8];
	a2.baud = v3->baud;
	script_43E110_modem(a1, &a2, 1808);
	*(_DWORD *)&v3->name[0] = *(_DWORD *)&a2.name[0];
	*(_DWORD *)&v3->name[4] = *(_DWORD *)&a2.name[4];
	*(_DWORD *)&v3->name[8] = *(_DWORD *)&a2.name[8];
	*(_DWORD *)&v3->phone[0] = *(_DWORD *)&a2.phone[0];
	*(_DWORD *)&v3->phone[4] = *(_DWORD *)&a2.phone[4];
	*(_DWORD *)&v3->phone[8] = *(_DWORD *)&a2.phone[8];
	v3->baud = a2.baud;
	v4 = fopen(aModem_lst, (const char *)aW);
	if (v4)
	{
		for (i = netz_modem_list; (netz_modem **)i != &netz_modem_list; i = i->next)
			fprintf(v4, format, i->name, i->phone, i->baud);
		fclose(v4);
	}
	v6 = netz_47C6C0_mapd_idx;
	netz_47C6C0_mapd_idx = 6;
	netz_47C6BC_mapd_idx = v6;
	script_408500_anim(a1);
    stru29_list_realloc(a1);
	bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    script_sleep(a1, 3);
	v9 = LVL_FindMapd();
	_40E400_set_palette(v9[6].items->GetPalette());
	_47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)6, 0, -10);
	cplc_select(6);
	cplc_406320();
    script_sleep(a1, 1);
	script_4084A0_animation(a1);
	script_terminate(a1);
}

//----- (0043E670) --------------------------------------------------------
void script_43E670_mobd45(Script *a1)
{
	Sprite *v1; // edi@1
	Sprite *v2; // eax@1
	DataMapd *v5; // eax@7

	v1 = a1->sprite;
	v2 = sprite_create(MOBD_45, 0, a1->sprite);
	v1->mobd_id = MOBD_45;
	v1->parent = v2;
	v2->parent = 0;
	v2->z_index = 0;
	v1->z_index = 1;
	a1->script_type = SCRIPT_TYPE_17;
	stru29_list_4439F0(v1, 0, 1, 1, 0);
	while (!script_443780(a1, 2044, 1, 0))
		;
	netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
	netz_47C6C0_mapd_idx = 0;
	script_408500_anim(a1);
    stru29_list_realloc(a1);
	bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    script_sleep(a1, 3);
	v5 = LVL_FindMapd();
	_40E400_set_palette(v5->items->GetPalette());
	_47A010_mapd_item_being_drawn[0] = MAPD_Draw(MAPD_MAP, 0, -10);
	cplc_select(0);
	cplc_406320();
    script_sleep(a1, 1);
	script_4084A0_animation(a1);
	script_terminate(a1);
}
// 47C6C8: using guessed type int stru29_list_initialized;

//----- (0043E7B0) --------------------------------------------------------
void script_43E7B0_mobd45(Script *a1)
{
	Sprite *v1; // esi@1
	Sprite *v2; // eax@1

	v1 = a1->sprite;
	v2 = sprite_create(MOBD_45, 0, a1->sprite);
	v1->mobd_id = MOBD_45;
	v1->parent = v2;
	v2->parent = 0;
	v2->z_index = 0;
	v1->z_index = 1;
	a1->script_type = SCRIPT_TYPE_4;
	stru29_list_4439F0(v1, 0, 0, 1, 0);
	while (!script_443780(a1, 2068, 1, 0))
		;
}

//----- (0043E820) --------------------------------------------------------
void script_43E820_mobd45(Script *a1)
{
	Sprite *v1; // esi@1
	Sprite *v2; // eax@1

	v1 = a1->sprite;
	v2 = sprite_create(MOBD_45, 0, a1->sprite);
	v1->mobd_id = MOBD_45;
	v1->parent = v2;
	v2->parent = 0;
	v2->z_index = 0;
	v1->z_index = 1;
	a1->script_type = SCRIPT_TYPE_4;
	stru29_list_4439F0(v1, 0, 0, 1, 0);
	while (!script_443780(a1, 1996, 1, 0))
		;
}

//----- (0043E890) --------------------------------------------------------
void script_43E890_mobd45_modems(Script *a1)
{
	int v1; // ebx@1
	int v2; // esi@1
	int v3; // ebp@1
	int v4; // eax@2
	netz_modem *i; // esi@2
	Sprite **v6; // edi@6
	Sprite **v8; // ecx@15
	Sprite *v9; // edx@16
	ScriptEvent *j; // eax@22
	int v12; // [sp+10h] [bp-54h]@1
	char v13[80]; // [sp+14h] [bp-50h]@12

	v1 = 0;
	v2 = 0;
	v12 = 0;
	v3 = 0;
	netz_modem_47C6CC_idx = 0;
	sprite_load_mobd(_47C664_ingame_menu_sprite, 1080);
	while (1)
	{
		_47C664_ingame_menu_sprite->x = 43008;
		v4 = 0;
		_47C664_ingame_menu_sprite->y = (v2 << 12) + 30720;
		_47C664_ingame_menu_sprite->z_index = 10;
		for (i = netz_modem_list; v4 < v3; ++v4)
		{
			if ((netz_modem **)i == &netz_modem_list)
				break;
			i = i->next;
		}
		render_string_445AE0(_47C65C_render_string);
		_47C65C_render_string->field_18 = 0;
		_47C65C_render_string->num_lines = 0;
		if ((netz_modem **)i != &netz_modem_list)
		{
			v6 = _47C668_ingame_menu_sprites;
			do
			{
                stru29_list_clear_bit_by_sprite(*v6, 1);

				sprintf(v13, aSS_2, i->name, i->phone);
				render_string_443D80(_47C65C_render_string, v13, 0);
				render_string_443D80(_47C65C_render_string, asc_464C88, 0);
				i = i->next;
				++v6;
				++v1;
			} while ((int)v6 < (int)&unk_47C690 && (netz_modem **)i != &netz_modem_list);
		}
		if (v1 < 10)
		{
			v8 = &_47C668_ingame_menu_sprites[v1];
			do
			{
				v9 = *v8;
				++v8;
                stru29_list_set_bit_by_sprite(v9, 1);
				;
			} while ((int)v8 < (int)&unk_47C690);
		}
		v1 = 0;

        script_wait_event(a1);
		for (j = script_get_next_event(a1); j; j = script_get_next_event(a1))
		{
			switch (j->event)
			{
			case EVT_MSG_SHOW_UNIT_HINT:
				if (v3 > 0)
					--v3;
				break;
			case EVT_MSG_DESELECTED:
				if (v3 < netz_modem_list_used - 10)
					++v3;
				break;
			case EVT_MSG_SELECTED:
				if (*(_DWORD *)j->param < netz_modem_list_used)
					v12 = *(_DWORD *)j->param;
				break;
			case EVT_MSG_1513:
				if (v12 > 0)
					--v12;
				if (v3 >= netz_modem_list_used - 10)
				{
					v3 = netz_modem_list_used - 11;
					if (netz_modem_list_used - 11 < 0)
						v3 = 0;
				}
				break;
			default:
				break;
			}
			script_discard_event(j);
		}
		v2 = v12;
		netz_modem_47C6CC_idx = v3 + v12;
	}
}
// 47C6CC: using guessed type int netz_modem_47C6CC_idx;

//----- (0043EA90) --------------------------------------------------------
void script_43EA90_mobd45(Script *a1)
{
	Sprite *v1; // eax@1
	Sprite *v2; // esi@1
	int v3; // ebx@2
	ScriptEvent *i; // eax@3
	enum SCRIPT_EVENT v5; // edx@4

	v1 = a1->sprite;
	v1->x = 17408;
	v1->y = 43008;
	v2 = a1->sprite;
	v2->parent = 0;
	a1->script_type = SCRIPT_TYPE_15;
	stru29_list_4439F0(v2, 0, 0, 0, 0);
	sprite_load_mobd(v2, 1308);
	while (1)
	{
		v3 = 0;
		do
		{
            script_wait_event(a1);
			for (i = script_get_next_event(a1); i; i = script_get_next_event(a1))
			{
				v5 = i->event;
				switch (v5)
				{
				case EVT_MOUSE_HOVER:
                    stru29_list_443AE0_find_by_sprite(a1->sprite);
					break;
				case EVT_MSG_SELECTED:
					v3 = 1;
					break;
				case EVT_MSG_1528_cancel:
					v3 = 1;
					break;
				}
				script_discard_event(i);
			}
		} while (!v3);
		script_trigger_event(0, EVT_MSG_SHOW_UNIT_HINT, 0, _47C664_ingame_menu_sprite->script);
	}
}

//----- (0043EB80) --------------------------------------------------------
void script_43EB80_mobd45(Script *a1)
{
	Sprite *v1; // eax@1
	Sprite *v2; // esi@1
	int v3; // ebx@2
	ScriptEvent *i; // eax@3
	enum SCRIPT_EVENT v5; // edx@4

	v1 = a1->sprite;
	v1->x = 131584;
	v1->y = 40960;
	v2 = a1->sprite;
	v2->parent = 0;
	a1->script_type = SCRIPT_TYPE_15;
	stru29_list_4439F0(v2, 0, 0, 0, 0);
	sprite_load_mobd(v2, 1320);
	while (1)
	{
		v3 = 0;
		do
		{
            script_wait_event(a1);
			for (i = script_get_next_event(a1); i; i = script_get_next_event(a1))
			{
				v5 = i->event;
				switch (v5)
				{
				case EVT_MOUSE_HOVER:
                    stru29_list_443AE0_find_by_sprite(a1->sprite);
					break;
				case EVT_MSG_SELECTED:
					v3 = 1;
					break;
				case EVT_MSG_1528_cancel:
					v3 = 1;
					break;
				}
				script_discard_event(i);
			}
		} while (!v3);
		script_trigger_event(0, EVT_MSG_DESELECTED, 0, _47C664_ingame_menu_sprite->script);
	}
}

//----- (0043EC70) --------------------------------------------------------
void script_43EC70_mobd45(Script *a1)
{
	Script *v1; // edi@1
	Sprite *v2; // ecx@1
	Sprite *v3; // esi@1
	int v4; // ebx@2
	ScriptEvent *i; // eax@3
	enum SCRIPT_EVENT v6; // edx@4

	v1 = a1;
	v2 = a1->sprite;
	a1 = (Script *)a1->param;
	_47C668_ingame_menu_sprites[(int)a1] = v2;
	v3 = v1->sprite;
	v3->parent = 0;
	v1->script_type = SCRIPT_TYPE_16;
	stru29_list_4439F0(v3, 0, 0, 0, 0);
	sprite_load_mobd(v3, 1332);
	while (1)
	{
		v4 = 0;
		do
		{
            script_wait_event(v1);
			for (i = script_get_next_event(v1); i; i = script_get_next_event(v1))
			{
				v6 = i->event;
				switch (v6)
				{
				case EVT_MOUSE_HOVER:
                    stru29_list_443AE0_find_by_sprite(v1->sprite);
					break;
				case EVT_MSG_SELECTED:
					v4 = 1;
					break;
				case EVT_MSG_1528_cancel:
					v4 = 1;
					break;
				}
				script_discard_event(i);
			}
		} while (!v4);
		script_trigger_event(0, EVT_MSG_SELECTED, &a1, _47C664_ingame_menu_sprite->script);
	}
}

//----- (0043ED60) --------------------------------------------------------
void script_43ED60_mobd45_modems(Script *a1)
{
	Sprite *v1; // esi@1
	Sprite *v2; // eax@1
	netz_modem *v3; // eax@3
	int v4; // ecx@3
	FILE *v5; // edi@8
	netz_modem *i; // esi@9

	v1 = a1->sprite;
	v2 = sprite_create(MOBD_45, 0, a1->sprite);
	v1->mobd_id = MOBD_45;
	v1->parent = v2;
	v2->parent = 0;
	v2->z_index = 0;
	v1->z_index = 1;
	a1->script_type = SCRIPT_TYPE_7;
	stru29_list_4439F0(v1, 0, 0, 1, 0);
	while (1)
	{
		while (!script_443780(a1, 1952, netz_modem_list_used, 0))
			;
		v3 = netz_modem_list;
		v4 = 0;
		if ((netz_modem **)netz_modem_list != &netz_modem_list)
		{
			while (v4 != netz_modem_47C6CC_idx)
			{
				v3 = v3->next;
				++v4;
				if ((netz_modem **)v3 == &netz_modem_list)
					goto LABEL_8;
			}
			v3->next->prev = v3->prev;
			v3->prev->next = v3->next;
			v3->next = netz_modem_list_free_pool;
			netz_modem_list_free_pool = v3;
		}
	LABEL_8:
		--netz_modem_list_used;
		v5 = fopen(aModem_lst, (const char *)aW);
		if (v5)
		{
			for (i = netz_modem_list; (netz_modem **)i != &netz_modem_list; i = i->next)
				fprintf(v5, format, i->name, i->phone, i->baud);
			fclose(v5);
		}
		script_trigger_event(0, EVT_MSG_1513, 0, _47C664_ingame_menu_sprite->script);
	}
}
// 47C6CC: using guessed type int netz_modem_47C6CC_idx;

//----- (0043EE90) --------------------------------------------------------
void script_43EE90_mobd45(Script *a1)
{
	Script *v1; // edi@1
	void *v2; // ebx@1
	int v3; // esi@1
	Sprite *v4; // eax@2
	RenderString *v5; // eax@5
	Sprite *v6; // esi@7
	RenderString *v7; // ebx@7
	Sprite *v8; // eax@7
	int v9; // ecx@9
	DataMapd *v12; // eax@13
	Sprite *v13; // [sp+14h] [bp+4h]@1

	v1 = a1;
	v13 = a1->sprite;
	sprite_create_scripted(MOBD_45, 0, (void(*)(Script *))script_43EA90_mobd45, SCRIPT_COROUTINE, 0);
	sprite_create_scripted(MOBD_45, 0, (void(*)(Script *))script_43EB80_mobd45, SCRIPT_COROUTINE, 0);
	_47C664_ingame_menu_sprite = sprite_create_scripted(MOBD_FONT_ITALIC, 0, script_43E890_mobd45_modems, SCRIPT_COROUTINE, 0);
	v2 = 0;
	v3 = 30720;
	do
	{
		v4 = sprite_create_scripted(MOBD_45, 0, (void(*)(Script *))script_43EC70_mobd45, SCRIPT_COROUTINE, 0);
		if (v4)
		{
			v4->script->param = v2;
			v4->x = 43008;
			v4->y = v3;
			v4->z_index = 5;
		}
		v3 += 4096;
		v2 = (char *)v2 + 1;
	} while (v3 < 71680);
	v5 = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 160, 104, 42, 12, 90, 14, 16);
	_47C65C_render_string = v5;
	if (!v5)
	{
		sprite_list_remove(v13);
		script_terminate(v1);
		v5 = _47C65C_render_string;
	}
	v6 = v1->sprite;
	v7 = v5;
	v8 = sprite_create(MOBD_45, 0, v1->sprite);
	v6->mobd_id = MOBD_45;
	v6->parent = v8;
	v8->parent = 0;
	v8->z_index = 0;
	v6->z_index = 1;
	v1->script_type = SCRIPT_TYPE_7;
	stru29_list_4439F0(v6, v7, 0, 1, 0);
	v13->parent->parent = _47C664_ingame_menu_sprite;
	while (!script_443780(v1, 1920, netz_modem_list_used < 20, 0))
		;
	v9 = netz_47C6C0_mapd_idx;
	netz_47C6C0_mapd_idx = 9;
	netz_47C6BC_mapd_idx = v9;
	script_408500_anim(v1);
    stru29_list_realloc(v1);
	bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    script_sleep(v1, 3);
	v12 = LVL_FindMapd();
	_40E400_set_palette(v12[9].items->GetPalette());
	_47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)9, 0, -10);
	cplc_select(9);
	cplc_406320();
    script_sleep(v1, 1);
	script_4084A0_animation(v1);
	script_terminate(v1);
}
// 47C6C8: using guessed type int stru29_list_initialized;

//----- (0043F0E0) --------------------------------------------------------
void script_43F0E0_mobd45_modems(Script *a1)
{
	Sprite *v1; // esi@1
	Sprite *v2; // eax@1
	netz_modem *v3; // eax@3
	int i; // ecx@3
	int v5; // eax@8
	void *v6; // esi@9
	int v7; // eax@13
	int v8; // ecx@17
	DataMapd *v11; // eax@21
	int v12; // [sp+0h] [bp-Ch]@8

	v1 = a1->sprite;
	v2 = sprite_create(MOBD_45, 0, a1->sprite);
	v1->mobd_id = MOBD_45;
	v1->parent = v2;
	v2->parent = 0;
	v2->z_index = 0;
	v1->z_index = 1;
	a1->script_type = SCRIPT_TYPE_7;
	stru29_list_4439F0(v1, 0, 0, 1, 0);
	do
	{
		while (!script_443780(a1, 1856, netz_modem_list_used, 0))
			;
		v3 = netz_modem_list;
		for (i = 0; (netz_modem **)v3 != &netz_modem_list; ++i)
		{
			if (i == netz_modem_47C6CC_idx)
				break;
			v3 = v3->next;
		}

		v6 = (void *)netz_42F8E0(0);

		OsShowCursor(true);
		netz_42F9C0(0, 0);
		OsShowCursor(false);
	} while (v6);
	v8 = netz_47C6C0_mapd_idx;
	netz_47C6C0_mapd_idx = 8;
	netz_47C6BC_mapd_idx = v8;
	script_408500_anim(a1);
    stru29_list_realloc(a1);
	bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    script_sleep(a1, 3);
	v11 = LVL_FindMapd();
	_40E400_set_palette(v11[8].items->GetPalette());
	_47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)8, 0, -10);
	cplc_select(8);
	cplc_406320();
    script_sleep(a1, 1);
	script_4084A0_animation(a1);
	script_terminate(a1);
}

//----- (0043F330) --------------------------------------------------------
void script_43F330_mobd45(Script *a1)
{
	Sprite *v1; // esi@1
	Sprite *v2; // eax@1
	netz_modem *v3; // eax@3
	int i; // ecx@3
	int v5; // eax@8
	int v6; // esi@9
	int v7; // ecx@12
	DataMapd *v10; // eax@16
	int v11; // [sp+0h] [bp-Ch]@8

	v1 = a1->sprite;
	v2 = sprite_create(MOBD_45, 0, a1->sprite);
	v1->mobd_id = MOBD_45;
	v1->parent = v2;
	v2->parent = 0;
	v2->z_index = 0;
	v1->z_index = 1;
	a1->script_type = SCRIPT_TYPE_7;
	stru29_list_4439F0(v1, 0, 0, 1, 0);
	do
	{
		while (!script_443780(a1, 1840, netz_modem_list_used, 0))
			;
		v3 = netz_modem_list;
		for (i = 0; (netz_modem **)v3 != &netz_modem_list; ++i)
		{
			if (i == netz_modem_47C6CC_idx)
				break;
			v3 = v3->next;
		}

		OsShowCursor(true);
		v6 = netz_42F8E0(1);
		OsShowCursor(false);
	} while (v6);
	v7 = netz_47C6C0_mapd_idx;
	netz_47C6C0_mapd_idx = 7;
	netz_47C6BC_mapd_idx = v7;
	script_408500_anim(a1);
    stru29_list_realloc(a1);
	bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    script_sleep(a1, 3);
	v10 = LVL_FindMapd();
	_40E400_set_palette(v10[7].items->GetPalette());
	_47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)7, 0, -10);
	cplc_select(7);
	cplc_406320();
    script_sleep(a1, 1);
	script_4084A0_animation(a1);
	script_terminate(a1);
}

//----- (0043F520) --------------------------------------------------------
void script_43F520_mobd45(Script *a1)
{
	Sprite *v1; // edi@1
	Sprite *v2; // eax@1
	int v3; // ecx@3
	DataMapd *v6; // eax@7

	v1 = a1->sprite;
	v2 = sprite_create(MOBD_45, 0, a1->sprite);
	v1->mobd_id = MOBD_45;
	v1->parent = v2;
	v2->parent = 0;
	v2->z_index = 0;
	v1->z_index = 1;
	a1->script_type = SCRIPT_TYPE_7;
	stru29_list_4439F0(v1, 0, 0, 1, 0);
	while (!script_443780(a1, 1936, netz_modem_list_used, 0))
		;
	v3 = netz_47C6C0_mapd_idx;
	netz_47C6C0_mapd_idx = 10;
	netz_47C6BC_mapd_idx = v3;
	script_408500_anim(a1);
    stru29_list_realloc(a1);
	bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    script_sleep(a1, 3);
	v6 = LVL_FindMapd();
	_40E400_set_palette(v6[10].items->GetPalette());
	_47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)10, 0, -10);
	cplc_select(10);
	cplc_406320();
    script_sleep(a1, 1);
	script_4084A0_animation(a1);
	script_terminate(a1);
}

//----- (0043F670) --------------------------------------------------------
void script_43F670_mobd45(Script *a1)
{
	Sprite *v1; // edi@1
	Sprite *v2; // eax@1
	DataMapd *v5; // eax@7

	v1 = a1->sprite;
	v2 = sprite_create(MOBD_45, 0, a1->sprite);
	v1->mobd_id = MOBD_45;
	v1->parent = v2;
	v2->parent = 0;
	v2->z_index = 0;
	v1->z_index = 1;
	a1->script_type = SCRIPT_TYPE_17;
	stru29_list_4439F0(v1, 0, 1, 1, 0);
	while (!script_443780(a1, 2044, 1, 0))
		;
	netz_free_provider_async();
	netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
	netz_47C6C0_mapd_idx = 1;
	script_408500_anim(a1);
    stru29_list_realloc(a1);
	bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    script_sleep(a1, 3);
	v5 = LVL_FindMapd();
	_40E400_set_palette(v5[1].items->GetPalette());
	_47A010_mapd_item_being_drawn[0] = MAPD_Draw(MAPD_FOG_OF_WAR, 0, -10);
	cplc_select(1);
	cplc_406320();
    script_sleep(a1, 1);
	script_4084A0_animation(a1);
	script_terminate(a1);
}

//----- (0043F7C0) --------------------------------------------------------
void script_43F7C0(Script *a1)
{
	Script *v1; // ebx@1
	Sprite *v2; // esi@1
	RenderString *v3; // edi@3
	stru29 *v4; // eax@5
	bool v5; // zf@5
	bool v6; // sf@5
	int v7; // eax@9
	int v8; // ebx@13
	char *v9; // esi@13
	const char *v10; // edx@16
	ScriptEvent *i; // eax@24
	int v12; // [sp+0h] [bp-14h]@9
	int v13; // [sp+Ch] [bp-8h]@7
	int v14; // [sp+10h] [bp-4h]@1

	v1 = a1;
	v14 = 1;
	v2 = sprite_create(MOBD_FONT_ITALIC, a1, 0);
	if (!v2)
		script_terminate(a1);
	v3 = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 69, 219, 27, 10, 90, 14, 16);
	if (!v3)
	{
		sprite_list_remove(v2);
		script_terminate(a1);
	}
	v4 = stru29_list_4439F0(v2, v3, 0, 1, 0);
	v4->field_C |= 1u;
	sprite_load_mobd(v2, 1080);
	v2->x = 21248;
	v2->field_88_unused = 1;
	v2->y = 60160;
	v2->z_index = 77;
	v2->drawjob->flags |= 0x40000000u;
	v5 = dword_47C700 == 0;
	v6 = dword_47C700++ < 0;
	if (!v6 && !v5)
		dword_47C700 = 0;
	while (1)
	{
		v13 = script_yield_any_trigger(v1, 1);
		netz_42F9C0(0, 0);
		if (v14)
		{
			render_string_445AE0(v3);
			v8 = 0;
			v3->num_lines = 0;
			dword_47C6B8 = 0;
			v9 = (char *)&netz_47A740[3].ptr_4;
			do
			{
				if (*(v9 - 24) && *(_DWORD *)v9)
				{
					++v8;
					render_string_443D80(v3, v9 - 21, 0);
					v10 = aEvol;
					if (!*(v9 - 22))
						v10 = aSurv;
					render_string_443D80(v3, v10, 0);
					render_string_443D80(v3, player_colors[*(v9 - 23)], 0);
					render_string_445770(v3, asc_464C88, 0);
				}
				v9 += 28;
			} while ((int)v9 < (int)&netz_47A840);
			if (v8 > 1)
				dword_47C6B8 = v8 - 1;
			v1 = a1;
		}
		if (v13 & SCRIPT_FLAGS_20_EVENT_TRIGGER)
		{
			for (i = script_get_next_event(v1); i; i = script_get_next_event(v1))
			{
				if (i->event != EVT_MSG_MISSION_FAILED && i->event == EVT_MSG_1548_sidebar)
					v14 = 0;
				script_discard_event(i);
			}
		}
	}
}

//----- (0043F9E0) --------------------------------------------------------
void script_43F9E0_mobd45(Script *a1)
{
	Script *v1; // edi@1
	Sprite *v2; // ecx@1
	Sprite *v3; // esi@1
	int v4; // ebx@2
	ScriptEvent *i; // eax@3
	enum SCRIPT_EVENT v6; // edx@4

	v1 = a1;
	v2 = a1->sprite;
	a1 = (Script *)a1->param;
	_47C668_ingame_menu_sprites[(int)a1] = v2;
	v3 = v1->sprite;
	v3->parent = 0;
	v1->script_type = SCRIPT_TYPE_16;
	stru29_list_4439F0(v3, 0, 0, 0, 0);
	sprite_load_mobd(v3, 1344);
	while (1)
	{
		v4 = 0;
		do
		{
            script_wait_event(v1);
			for (i = script_get_next_event(v1); i; i = script_get_next_event(v1))
			{
				v6 = i->event;
				switch (v6)
				{
				case 0xFFFFFFFE:
                    stru29_list_443AE0_find_by_sprite(v1->sprite);
					break;
				case 0x5E7u:
					v4 = 1;
					break;
				case 0x5F8u:
					v4 = 1;
					break;
				}
				script_discard_event(i);
			}
		} while (!v4);
		script_trigger_event(0, EVT_MSG_SELECTED, &a1, _47C664_ingame_menu_sprite->script);
	}
}

//----- (0043FAD0) --------------------------------------------------------
void script_43FAD0_mobd45_evt5(Script *a1)
{
	void *v1; // edi@1
	Sprite *v2; // esi@1
	int v3; // esi@3
	Sprite *v4; // eax@4
	Sprite *v5; // esi@7
	RenderString *v6; // edi@7
	stru29 *v7; // eax@9
	int v8; // eax@10
	int v9; // ebx@10
	int v10; // eax@18
	int v11; // esi@21
	char *v12; // eax@23
	ScriptEvent *i; // eax@32
	int v14; // eax@40
	int v15; // [sp+0h] [bp-18h]@18
	int v16; // [sp+Ch] [bp-Ch]@1
	int v17; // [sp+10h] [bp-8h]@9
	Sprite *v18; // [sp+14h] [bp-4h]@1

	v1 = 0;
	v16 = 1;
	dword_47C608 = 0;
	dword_47C660 = 0;
	v2 = sprite_create(MOBD_FONT_ITALIC, a1, 0);
	v18 = v2;
	if (!v2)
		script_terminate(a1);
	_47C664_ingame_menu_sprite = v2;
	v3 = 38912;
	while (1)
	{
		v4 = sprite_create_scripted(MOBD_45, 0, (void(*)(Script *))script_43F9E0_mobd45, SCRIPT_COROUTINE, 0);
		if (v4)
		{
			v4->script->param = v1;
			v4->x = 50432;
			v4->y = v3;
			v4->z_index = 5;
		}
		v3 += 4096;
		v1 = (char *)v1 + 1;
		if (v3 >= 79872)
		{
			v5 = v18;
			v6 = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 183, 136, 20, 12, 90, 14, 16);
			if (!v6)
			{
				sprite_list_remove(v18);
				script_terminate(a1);
			}
			v7 = stru29_list_4439F0(v18, v6, 0, 1, 0);
			v7->field_C |= 1u;
			sprite_load_mobd(v5, 1080);
			v5->x = 50432;
			v5->field_88_unused = 1;
			v5->y = 38912;
			v5->z_index = 77;
			dword_47C5F8 = -1;
			v17 = 1;
			while (1)
			{
				v8 = -(v17 != 0);
				LOBYTE_HEXRAYS(v8) = v8 & 0x38;
				v9 = script_yield_any_trigger(a1, v8 + 300);
				if (netz_42E430(0))
					v17 = 0;
				if (v16 && dword_46E3F0 == -2)
				{
					if (v9 & 0x80000000 && !netz_47A834)
					{
						netz_47A934 = 1;
						netz_42F9C0(0, 0);
					}
					render_string_445AE0(v6);
					v11 = 0;
					v6->num_lines = 0;
					do
					{
						if (netz_42E430(v11))
						{
							v12 = netz_42E410(v11);
							v6->field_18 = 0;
							render_string_443D80(v6, v12, 0);
							render_string_445770(v6, asc_464C88, 0);
							++dword_47C660;
						}
						++v11;
					} while (v11 < 10);
					if (dword_47C660 != dword_47C5F8)
					{
						dword_47C5F8 = dword_47C660;
						script_trigger_event_group(a1, EVT_MSG_1528_cancel, 0, a1->script_type);
						if (dword_47C660)
						{
							if (dword_47C608 > dword_47C660 - 1)
								dword_47C608 = dword_47C660 - 1;
						}
						else
						{
							dword_47C608 = 0;
						}
					}
					v5 = v18;
				}
				if (v9 & SCRIPT_FLAGS_20_EVENT_TRIGGER)
				{
					for (i = script_get_next_event(a1); i; i = script_get_next_event(a1))
					{
						if (i->event != EVT_MSG_MISSION_FAILED)
						{
							if (i->event == EVT_MSG_SELECTED)
							{
								if (*(_DWORD *)i->param < dword_47C660)
									dword_47C608 = *(_DWORD *)i->param;
							}
							else if (i->event == EVT_MSG_1548_sidebar)
							{
								v16 = 0;
							}
						}
						script_discard_event(i);
					}
				}
				v14 = dword_47C608;
				v5->field_88_unused = 1;
				if (v14 <= 0)
					v5->y = 38912;
				else
					v5->y = (dword_47C608 << 12) + 38912;
			}
		}
	}
}

//----- (0043FDE0) --------------------------------------------------------
void script_43FDE0_mobd45(Script *a1)
{
	Sprite *v1; // edi@1
	Sprite *v2; // eax@1
	DataMapd *v5; // eax@7

	v1 = a1->sprite;
	v2 = sprite_create(MOBD_45, 0, a1->sprite);
	v1->mobd_id = MOBD_45;
	v1->parent = v2;
	v2->parent = 0;
	v2->z_index = 0;
	v1->z_index = 1;
	a1->script_type = SCRIPT_TYPE_17;
	stru29_list_4439F0(v1, 0, 1, 1, 0);
	while (!script_443780(a1, 2044, 1, 0))
		;
	netz_free_provider_async();
	netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
	netz_47C6C0_mapd_idx = 1;
	script_408500_anim(a1);
    stru29_list_realloc(a1);
	bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    script_sleep(a1, 3);
	v5 = LVL_FindMapd();
	_40E400_set_palette(v5[1].items->GetPalette());
	_47A010_mapd_item_being_drawn[0] = MAPD_Draw(MAPD_FOG_OF_WAR, 0, -10);
	cplc_select(1);
	cplc_406320();
    script_sleep(a1, 1);
	script_4084A0_animation(a1);
	script_terminate(a1);
}
// 47C6C8: using guessed type int stru29_list_initialized;

//----- (0043FF30) --------------------------------------------------------
void script_43FF30_mobd45(Script *a1)
{
	Sprite *v1; // esi@1
	Sprite *v2; // eax@1
	int v3; // eax@7
	Sprite *v4; // esi@10
	void *v5; // eax@10
	int v6; // eax@12
	void *v7; // ecx@13
	void *v8; // eax@15
	int v9; // esi@16
	int v10; // eax@22
	int v11; // eax@29
	DataMapd *v14; // eax@37
	int v15; // [sp+0h] [bp-Ch]@12
__debugbreak();
	v1 = a1->sprite;
	v2 = sprite_create(MOBD_45, 0, a1->sprite);
	v1->mobd_id = MOBD_45;
	v1->parent = v2;
	v2->parent = 0;
	v2->z_index = 0;
	v1->z_index = 1;
	a1->script_type = SCRIPT_TYPE_5;
	stru29_list_4439F0(v1, 0, 0, 1, 0);
	dword_47C5F8 = -1;
	if (!script_create_coroutine(SCRIPT_TYPE_5, script_43FAD0_mobd45_evt5, 0))
		game_state = GAME_STATE::GAME_3;
	while (1)
	{
		dword_46E3F0 = -2;
		do
			v3 = dword_47C660 && netz_42E430(dword_47C608) && dword_46E3F0 == -2;
		while (!script_443780(a1, 1824, v3, 0));
		v4 = a1->sprite;
		sprite_4272E0_load_mobd_item(v4->parent, 1692, 0);
		sprite_4272E0_load_mobd_item(v4, 1824, 3);
		dword_468B54 = -1;
		_46E420_starting_cash_idx = 1280;
		v7 = (void *)netz_42F9E0(dword_47C608);
		if (!v7)
		{
			v8 = (void *)-1;
			v9 = 0;
			dword_46E3F0 = -1;
			while ((dword_468B54 == -1 || v8 == (void *)-1) && v9 < 1800)
			{
                script_sleep(a1, 1);
				netz_42F9C0(0, 0);
				v8 = (void *)dword_46E3F0;
				++v9;
			}
			if (!v8)
				break;
		}
		dword_468B54 = -1;
		netz_42F650((void *)j_netz_430690());
	}
	netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
	netz_47C6C0_mapd_idx = 8;
	script_408500_anim(a1);
    stru29_list_realloc(a1);
	bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    script_sleep(a1, 3);
	v14 = LVL_FindMapd();
	_40E400_set_palette(v14[8].items->GetPalette());
	_47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)8, 0, -10);
	cplc_select(8);
	cplc_406320();
    script_sleep(a1, 1);
	script_4084A0_animation(a1);
	script_terminate(a1);
}

//----- (004402A0) --------------------------------------------------------
void script_4402A0_mobd45_evt5(Script *a1)
{
	Sprite *v1; // esi@1
	Sprite *v2; // eax@1
	int v3; // eax@4
	unsigned int v4; // eax@7
	void *v5; // eax@7
	int v6; // eax@9
	void *v7; // ecx@10
	int v8; // ecx@13
	DataMapd *v11; // eax@17
	int v12; // [sp+0h] [bp-Ch]@9

	v1 = a1->sprite;
	v2 = sprite_create(MOBD_45, 0, a1->sprite);
	v1->mobd_id = MOBD_45;
	v1->parent = v2;
	v2->parent = 0;
	v2->z_index = 0;
	v1->z_index = 1;
	a1->script_type = SCRIPT_TYPE_5;
	stru29_list_4439F0(v1, 0, 0, 1, 0);
	do
		v3 = dword_47C6EC && dword_46E3F0 == -2;
	while (!script_443780(a1, 1980, v3, 0));
	dword_47C6F4 = 1;
	v4 = clock();
	srand(v4);
	v5 = (void *)(strlen(netz_default_player_name) + 1);
	memcpy(
		netz_47A740[(int)__47CA80_array_idx_and_netz_player_side + 2].player_name,
		netz_default_player_name,
		(unsigned int)v5);

	v7 = (void *)netz_42F8E0(1);
	if (!v7)
	{
		v8 = netz_47C6C0_mapd_idx;
		netz_47C6C0_mapd_idx = 7;
		netz_47C6BC_mapd_idx = v8;
		script_408500_anim(a1);
        stru29_list_realloc(a1);
		bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
        script_sleep(a1, 3);
		v11 = LVL_FindMapd();
		_40E400_set_palette(v11[7].items->GetPalette());
		_47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)7, 0, -10);
		cplc_select(7);
		cplc_406320();
        script_sleep(a1, 1);
		script_4084A0_animation(a1);
		script_terminate(a1);
	}
}
// 46E3F0: using guessed type int dword_46E3F0;
// 477344: using guessed type int _477344_esp;
// 47734C: using guessed type int _47734C_coroutine_int;
// 47C6C8: using guessed type int stru29_list_initialized;
// 47C6F4: using guessed type int dword_47C6F4;

//----- (004404D0) --------------------------------------------------------
void script_4404D0_mobd45_evt8(Script *a1)
{
	Script *v1; // edi@1
	Sprite *v2; // ebx@1
	Sprite *v3; // eax@2
	Sprite *v4; // eax@4
	Sprite *v5; // eax@6
	unsigned int v6; // eax@9
	void *v7; // eax@9
	int v8; // eax@11
	Sprite *v9; // eax@15
	Script *v10; // eax@16
	Sprite *v11; // eax@19
	Sprite *v12; // eax@21
	Script *v13; // eax@22
	Sprite *v14; // eax@24
	Sprite *v15; // eax@28
	Sprite *v16; // eax@30
	Sprite *v17; // eax@32
	Script *v18; // eax@33
	int v19; // [sp+0h] [bp-Ch]@11

	v1 = a1;
	v2 = a1->sprite;
	a1->script_type = SCRIPT_TYPE_8;
	if (netz_47C6C0_mapd_idx == 15)
	{
		v3 = sprite_create_scripted(MOBD_45, v2, script_441FC0_mobd45_evt8, SCRIPT_COROUTINE, 0);
		if (v3)
		{
			v3->x = 10240;
			v3->y = 62976;
		}
		v4 = sprite_create_scripted(MOBD_45, v2, script_441780_mobd45_evt8, SCRIPT_COROUTINE, 0);
		if (v4)
		{
			v4->x = 45056;
			v4->y = 62976;
		}
		v5 = sprite_create_scripted(MOBD_45, v2, script_4421F0_mobd45_evt8, SCRIPT_COROUTINE, 0);
		if (v5)
		{
			v5->x = 83968;
			v5->y = 62976;
		}
	}
	else if (netz_47C6BC_mapd_idx != 4)
	{
		v6 = clock();
		srand(v6);
		v7 = (void *)(strlen(netz_default_player_name) + 1);
		memcpy(
			netz_47A740[(int)__47CA80_array_idx_and_netz_player_side + 2].player_name,
			netz_default_player_name,
			(unsigned int)v7);

		netz_42F8E0(1);
	}
	v9 = sprite_create_scripted(MOBD_45, v2, script_440810_mobd45, SCRIPT_COROUTINE, 0);
	if (v9)
	{
		v10 = v9->script;
		if (v10)
			v10->script_type = v1->script_type;
	}
	else
	{
		game_state = GAME_STATE::GAME_3;
	}
	v11 = sprite_create_scripted(MOBD_45, v2, script_441470_mobd45_evt8, SCRIPT_COROUTINE, 0);
	if (v11)
	{
		v11->x = 75264;
		v11->y = 17152;
	}
	v12 = sprite_create_scripted(MOBD_45, v2, script_440CA0_mobd45_evt8, SCRIPT_COROUTINE, 0);
	if (v12)
	{
		v12->x = 14080;
		v12->y = 27904;
		v13 = v12->script;
		if (v13)
			v13->script_type = v1->script_type;
	}
	v14 = sprite_create_scripted(MOBD_45, v2, script_441050_mobd45_evt8, SCRIPT_COROUTINE, 0);
	if (v14)
	{
		v14->x = 70656;
		v14->y = 27904;
	}
	if (netz_47C6C0_mapd_idx == 15)
	{
		BYTE1(_46E420_starting_cash_idx) = 5;
	}
	else
	{
		v15 = sprite_create_scripted(MOBD_45, v2, script_441680_mobd45_evt8, SCRIPT_COROUTINE, 0);
		if (v15)
		{
			v15->x = 97280;
			v15->y = 38400;
		}
	}
	v16 = sprite_create_scripted(MOBD_45, v2, script_441260_mobd45_evt8, SCRIPT_COROUTINE, 0);
	if (v16)
	{
		v16->x = 58368;
		v16->y = 38400;
	}
	v17 = sprite_create_scripted(MOBD_45, v2, script_440ED0_mobd45_evt8, SCRIPT_COROUTINE, 0);
	if (v17)
	{
		v17->x = 0x2000;
		v17->y = 38400;
		v18 = v17->script;
		if (v18)
			v18->script_type = v1->script_type;
	}
	sprite_list_remove(v2);
	script_terminate(v1);
}

//----- (00440770) --------------------------------------------------------
void input_get_string_440770_handler(const char *a1, int a2)
{
	const char *v2; // esi@1
	unsigned __int16 v3; // ST08_2@1
	stru8 *v4; // eax@1
	int v5; // ecx@1

	v2 = a1;
	v3 = a2;
	render_string_445AE0(_47C65C_render_string);
	_47C65C_render_string->field_18 = 0;
	_47C65C_render_string->num_lines = 0;
	render_string_443D80(_47C65C_render_string, v2, 0);
	_47C664_ingame_menu_sprite->field_88_unused = 1;
	v4 = _47C65C_render_string->pstru8;
	v5 = _47C65C_render_string->field_C + v3 + 1;
	if (_47C65C_render_string->field_C + v3 != -1)
	{
		do
		{
			v4 = v4->next;
			--v5;
		} while (v5);
	}
	_47C664_ingame_menu_sprite->x = v4->drawjob->job_details.x << 8;
	_47C664_ingame_menu_sprite->field_88_unused = 1;
	_47C664_ingame_menu_sprite->y = 22528;
}

//----- (00440810) --------------------------------------------------------
void script_440810_mobd45(Script *a1)
{
	Script *v1; // edi@1
	Sprite *v2; // ebx@1
	stru8 *v3; // eax@8
	int v4; // ecx@8
	Sprite *v5; // esi@10
	RenderString *v6; // edx@10
	char v7; // cl@14
	int v8; // ebx@17
	ScriptEvent *i; // eax@18
	enum SCRIPT_EVENT v10; // edx@19
	Sprite *v12; // eax@31
	int v13; // edx@31
	int v14; // ecx@31
	int v15; // esi@31
	char v16; // al@32
	int v17; // eax@41
	stru8 *v18; // ecx@44
	int v19; // eax@44
	int v20; // [sp+0h] [bp-Ch]@41

	v1 = a1;
	v2 = a1->sprite;
	_47C65C_render_string = render_string_create(
		0,
		currently_running_lvl_mobd[MOBD_FONT_ITALIC].items,
		144,
		72,
		14,
		3,
		9,
		14,
		16);
	if (!_47C65C_render_string)
	{
		sprite_list_remove(v2);
		script_terminate(a1);
	}
	_47C664_ingame_menu_sprite = sprite_create(MOBD_FONT_ITALIC, 0, v2);
	if (!_47C664_ingame_menu_sprite)
	{
		sprite_list_remove(v2);
		render_string_list_remove(_47C65C_render_string);
		script_terminate(a1);
	}
	if (netz_47C6C0_mapd_idx != LEVEL_MUTE_01 && !netz_47A834)
	{
		strcpy(netz_47A740[(int)__47CA80_array_idx_and_netz_player_side + 2].player_name, netz_default_player_name);
		v1 = a1;
	}
	render_string_445AE0(_47C65C_render_string);
	_47C65C_render_string->field_18 = 0;
	_47C65C_render_string->num_lines = 0;
	render_string_443D80(_47C65C_render_string, netz_default_player_name, 0);
	_47C664_ingame_menu_sprite->field_88_unused = 1;
	v3 = _47C65C_render_string->pstru8;
	v4 = _47C65C_render_string->field_C + 1;
	if (_47C65C_render_string->field_C != -1)
	{
		do
		{
			v3 = v3->next;
			--v4;
		} while (v4);
	}
	_47C664_ingame_menu_sprite->x = v3->drawjob->job_details.x << 8;
	_47C664_ingame_menu_sprite->field_88_unused = 1;
	_47C664_ingame_menu_sprite->y = 22528;
	v2->parent = _47C664_ingame_menu_sprite;
	v5 = v1->sprite;
	v6 = _47C65C_render_string;
	v5->parent = 0;
	v1->script_type = SCRIPT_TYPE_18;
	stru29_list_4439F0(v5, v6, 0, 0, 0);
	sprite_load_mobd(v5, 1368);
	v2->x = 40960;
	v2->field_88_unused = 1;
	v2->y = 22528;
	while (1)
	{
		if (netz_47C6C0_mapd_idx != 15)
		{
			if (netz_47A834)
				v7 = 65;
			else
				v7 = 66;
			netz_42E450(netz_47A834, 0, v7);
		}
		v8 = 0;
		do
		{
            script_wait_event(v1);
			for (i = script_get_next_event(v1); i; i = script_get_next_event(v1))
			{
				v10 = i->event;
				switch (v10)
				{
				case EVT_MOUSE_HOVER:
                    stru29_list_443AE0_find_by_sprite(v1->sprite);
					break;
				case EVT_MSG_SELECTED:
					v8 = 1;
					break;
				case EVT_MSG_1528_cancel:
					v8 = 1;
					break;
				}
				script_discard_event(i);
			}
		} while (!v8);
		_47C664_ingame_menu_sprite->field_88_unused = 1;
		_47C664_ingame_menu_sprite->x = 40960;
		_47C664_ingame_menu_sprite->field_88_unused = 1;
		_47C664_ingame_menu_sprite->y = 22528;
		_47C664_ingame_menu_sprite->z_index = 10;
		sprite_load_mobd(_47C664_ingame_menu_sprite, 1096);
		dword_47C6C4 = 1;
		input_get_string(netz_default_player_name, 8u, input_get_string_440770_handler, 1, v1);
		v12 = _47C6E0_task->sprite;
		v13 = v12->y >> 8;
		v14 = v12->x >> 8;
		v12->field_88_unused = 1;
		input_set_mouse_pos(v14, v13);
		v15 = 0;
		dword_47C6C4 = 0;
		do
		{
			v16 = netz_default_player_name[v15];
			if (!v16)
				break;
			if (!isalpha(v16) && !isdigit(netz_default_player_name[v15]))
				netz_default_player_name[v15] = 95;
			++v15;
		} while (v15 < 7);
		LOBYTE_HEXRAYS(dword_468CE8) = 0;
		_47C664_ingame_menu_sprite->field_88_unused = 1;
		_47C664_ingame_menu_sprite->x = 40960;
		_47C664_ingame_menu_sprite->field_88_unused = 1;
		_47C664_ingame_menu_sprite->y = 22528;
		sprite_release_mobd_item(_47C664_ingame_menu_sprite);
		if (netz_47C6C0_mapd_idx != 15 && netz_47A834)
		{
			j_netz_430670((int)netz_default_player_name);
		}
		strcpy((char *)(28 * (_DWORD)__47CA80_array_idx_and_netz_player_side + 4695939), netz_default_player_name);
		render_string_445AE0(_47C65C_render_string);
		_47C65C_render_string->field_18 = 0;
		_47C65C_render_string->num_lines = 0;
		render_string_443D80(_47C65C_render_string, netz_default_player_name, 0);
		_47C664_ingame_menu_sprite->field_88_unused = 1;
		v18 = _47C65C_render_string->pstru8;
		v19 = _47C65C_render_string->field_C + 1;
		if (_47C65C_render_string->field_C != -1)
		{
			do
			{
				v18 = v18->next;
				--v19;
			} while (v19);
		}
		_47C664_ingame_menu_sprite->x = v18->drawjob->job_details.x << 8;
		_47C664_ingame_menu_sprite->field_88_unused = 1;
		_47C664_ingame_menu_sprite->y = 22528;
		if (netz_47C6C0_mapd_idx != 15)
			netz_42E450((void *)netz_47C6C0_mapd_idx, 0, 65);
		v1 = a1;
	}
}

//----- (00440CA0) --------------------------------------------------------
void script_440CA0_mobd45_evt8(Script *a1)
{
	RenderString *v1; // edi@4
	Sprite *v2; // esi@4
	Sprite *v3; // eax@4
	bool v4; // sf@7
	unsigned __int8 v5; // of@7
	char v6; // dl@11
	void *v7; // ecx@14
	char *v8; // eax@14
	int v9; // eax@20
	int v10; // eax@23
	int v11; // esi@24
	char v12; // cl@27
	void *v13; // eax@29

	if (netz_47C6C0_mapd_idx == LEVEL_MUTE_01)
		byte_47C654 = 0;
	else
		byte_47C654 = netz_47A740[(int)__47CA80_array_idx_and_netz_player_side + 2].field_9;
	v1 = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 164, 116, 10, 3, 9, 14, 16);
	v2 = a1->sprite;
	v3 = sprite_create(MOBD_45, 0, a1->sprite);
	v2->mobd_id = MOBD_45;
	v2->parent = v3;
	v3->parent = 0;
	v3->z_index = 0;
	v2->z_index = 1;
	a1->script_type = SCRIPT_TYPE_8;
	stru29_list_4439F0(v2, v1, 0, 1, 0);
	while (1)
	{
		while (1)
		{
			while (1)
			{
				render_string_445AE0(v1);
				v1->field_18 = 0;
				v1->num_lines = 0;
				render_string_443D80(v1, player_colors[byte_47C654], 0);
				if (netz_47C6C0_mapd_idx != 15)
					break;
				while (!script_443780(a1, 2056, 1, 2))
					;
				v5 = __OFSUB__(byte_47C654 + 1, 15);
				v4 = (char)(byte_47C654++ - 14) < 0;
				if (!(v4 ^ v5))
					byte_47C654 = 0;
			}
			if (netz_47A834)
				break;
			do
			{
				v11 = script_443570(a1, 2056, 1, 2);
				render_string_445AE0(v1);
				v1->field_18 = 0;
				v1->num_lines = 0;
				render_string_443D80(v1, player_colors[byte_47C654], 0);
			} while (!v11);
			if (v11 == 300)
			{
				byte_47C654 = netz_47A740[(int)__47CA80_array_idx_and_netz_player_side + 2].field_9;
			}
			else
			{
				v12 = byte_47C654 + 1;
				v5 = __OFSUB__(byte_47C654 + 1, 15);
				v4 = (char)(byte_47C654++ - 14) < 0;
				if (!(v4 ^ v5))
				{
					v12 = 0;
					byte_47C654 = 0;
				}
				v13 = __47CA80_array_idx_and_netz_player_side;
				netz_47A740[(int)__47CA80_array_idx_and_netz_player_side + 2].field_9 = v12;
				netz_42E450(v13, 1, 69);
				byte_47C654 = netz_47A740[(int)__47CA80_array_idx_and_netz_player_side + 2].field_9;
			}
		}
		while (!script_443780(a1, 2056, 1, 2))
			;
		v6 = byte_47C654;
		do
		{
			if (++v6 >= 15)
				v6 = 0;
			v7 = 0;
			v8 = (char *)&netz_47A740[3].ptr_4;
			while (v7 == __47CA80_array_idx_and_netz_player_side || !*(v8 - 24) || !*(_DWORD *)v8 || *(v8 - 23) != v6)
			{
				v8 += 28;
				v7 = (char *)v7 + 1;
				if ((int)v8 >= (int)&netz_47A840)
				{
					v9 = 0;
					goto LABEL_22;
				}
			}
			v9 = 1;
		LABEL_22:
			;
		} while (v9);
		byte_47C654 = v6;
		v10 = 7 * (_DWORD)__47CA80_array_idx_and_netz_player_side;
		netz_47A740[4 * v10 / 0x1Cu + 2].field_9 = v6;
		netz_42E450((void *)v10, 0, 65);
	}
}
// 47A840: using guessed type int netz_47A840;
// 47C654: using guessed type char byte_47C654;

//----- (00440ED0) --------------------------------------------------------
void script_440ED0_mobd45_evt8(Script *a1)
{
	RenderString *v1; // ebp@4
	Sprite *v2; // edi@4
	Sprite *v3; // eax@4
	const char *v4; // edx@5
	void *v5; // eax@12
	bool v6; // zf@12
	int v7; // eax@15

	if (netz_47C6C0_mapd_idx == LEVEL_MUTE_01)
		_47C658_faction_index = 0;
	else
		_47C658_faction_index = netz_47A740[(int)__47CA80_array_idx_and_netz_player_side + 2].field_A;
	v1 = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 142, 156, 10, 3, 9, 14, 16);
	v2 = a1->sprite;
	v3 = sprite_create(MOBD_45, 0, a1->sprite);
	v2->mobd_id = MOBD_45;
	v2->parent = v3;
	v3->parent = 0;
	v3->z_index = 0;
	v2->z_index = 1;
	a1->script_type = SCRIPT_TYPE_8;
	stru29_list_4439F0(v2, v1, 0, 1, 0);
	while (1)
	{
		while (1)
		{
			v1->field_18 = 0;
			v1->num_lines = 0;
			v4 = aEvol_0;
			if (!_47C658_faction_index)
				v4 = a2;
			render_string_443D80(v1, v4, 0);
			if (netz_47C6C0_mapd_idx != 15)
				break;
			while (!script_443780(a1, 2032, 1, 2))
				;
			_47C658_faction_index ^= 1u;
		}
		if (netz_47A834)
			break;
		do
			v7 = script_443570(a1, 2032, 1, 2);
		while (!v7);
		if (v7 == 300)
		{
			_47C658_faction_index = netz_47A740[(int)__47CA80_array_idx_and_netz_player_side + 2].field_A;
		}
		else
		{
		LABEL_12:
			v5 = netz_47A834;
			v6 = netz_47A834 == 0;
			_47C658_faction_index ^= 1u;
			netz_47A740[(int)__47CA80_array_idx_and_netz_player_side + 2].field_A = _47C658_faction_index;
			if (v6)
				netz_42E450(v5, 0, 66);
			else
				netz_42E450(v5, 0, 65);
		}
	}
	while (!script_443780(a1, 2032, 1, 2))
		;
	goto LABEL_12;
}
// 47C658: using guessed type char _47C658_faction_index;

//----- (00441050) --------------------------------------------------------
void script_441050_mobd45_evt8(Script *a1)
{
	RenderString *v1; // edi@3
	Sprite *v2; // esi@3
	Sprite *v3; // eax@3
	bool v4; // sf@6
	unsigned __int8 v5; // of@6
	char a2; // [sp+10h] [bp-14h]@4

	if (netz_47C6C0_mapd_idx == 15)
		BYTE3(_46E420_starting_cash_idx) = 0;
	v1 = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 406, 116, 20, 3, 9, 14, 16);
	v2 = a1->sprite;
	v3 = sprite_create(MOBD_45, 0, a1->sprite);
	v2->mobd_id = MOBD_45;
	v2->parent = v3;
	v3->parent = 0;
	v3->z_index = 0;
	v2->z_index = 1;
	a1->script_type = SCRIPT_TYPE_8;
	stru29_list_4439F0(v2, v1, 0, 1, 0);
	while (1)
	{
		sprintf(&a2, aS_0, off_46C358[SBYTE3(_46E420_starting_cash_idx)]);
		v1->field_18 = 0;
		v1->num_lines = 0;
		render_string_445AE0(v1);
		render_string_443D80(v1, &a2, 0);
		while (!script_443780(a1, 2156, 1, 0))
			;
		v5 = __OFSUB__(BYTE3(_46E420_starting_cash_idx) + 1, 15);
		v4 = (char)(BYTE3(_46E420_starting_cash_idx)++ - 14) < 0;
		if (!(v4 ^ v5))
			BYTE3(_46E420_starting_cash_idx) = 0;
		if (netz_47C6C0_mapd_idx != 15)
			netz_44A2A0(64, (int)&_46E420_starting_cash_idx, 5);
	}
}
// 46C358: using guessed type char *off_46C358[15];
// 47C5FC: using guessed type int _46E420_starting_cash_idx;

//----- (00441150) --------------------------------------------------------
void script_441150_mobd45_evt8(Script *a1)
{
	int v1; // ebx@1
	RenderString *v2; // esi@1
	Sprite *v3; // edi@1
	Sprite *v4; // eax@1
	char v6[20]; // [sp+10h] [bp-14h]@7

	v1 = -1;
	v2 = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 406, 116, 20, 3, 9, 14, 16);
	v3 = a1->sprite;
	v4 = sprite_create(MOBD_45, 0, a1->sprite);
	v3->mobd_id = MOBD_45;
	v3->parent = v4;
	v4->parent = 0;
	v4->z_index = 0;
	v3->z_index = 1;
	a1->script_type = SCRIPT_TYPE_8;
	stru29_list_4439F0(v3, v2, 0, 1, 0);
    stru29_list_set_bit_by_sprite(a1->sprite, 1);
	while (1)
	{
		if (v1 != SBYTE3(_46E420_starting_cash_idx))
		{
			sprintf(v6, aS_0, off_46C358[SBYTE3(_46E420_starting_cash_idx)]);
			v2->field_18 = 0;
			v2->num_lines = 0;
			render_string_445AE0(v2);
			render_string_443D80(v2, v6, 0);
			v1 = SBYTE3(_46E420_starting_cash_idx);
		}
		script_443780(a1, 2156, 0, 0);
	}
}

//----- (00441240) --------------------------------------------------------
bool _441240_techbunker_should_create()
{
    bool result = false;
	if (_47C6D8_use__466098_cost_multipliers || (result = 1, !single_player_game))
		result = SBYTE2(_46E420_starting_cash_idx);
	return result;
}

//----- (00441260) --------------------------------------------------------
void script_441260_mobd45_evt8(Script *a1)
{
	RenderString *v1; // ebp@3
	Sprite *v2; // esi@3
	Sprite *v3; // eax@3
	const char *v4; // edx@4

	if (netz_47C6C0_mapd_idx == 15)
		BYTE2(_46E420_starting_cash_idx) = 0;
	v1 = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 340, 156, 10, 3, 9, 14, 16);
	v2 = a1->sprite;
	v3 = sprite_create(MOBD_45, 0, a1->sprite);
	v2->mobd_id = MOBD_45;
	v2->parent = v3;
	v3->parent = 0;
	v3->z_index = 0;
	v2->z_index = 1;
	a1->script_type = SCRIPT_TYPE_8;
	stru29_list_4439F0(v2, v1, 0, 1, 0);
	while (1)
	{
		v1->field_18 = 0;
		v1->num_lines = 0;
		v4 = "ON ";
		if (!BYTE2(_46E420_starting_cash_idx))
			v4 = "OFF";
		render_string_443D80(v1, v4, 0);
		while (!script_443780(a1, 2096, 1, 2))
			;
		BYTE2(_46E420_starting_cash_idx) ^= 1u;
		if (netz_47C6C0_mapd_idx != 15)
			netz_44A2A0(64, (int)&_46E420_starting_cash_idx, 5);
	}
}

//----- (00441340) --------------------------------------------------------
void script_441340_mobd45_evt8(Script *a1)
{
	RenderString *v1; // edi@1
	Sprite *v2; // esi@1
	Sprite *v3; // eax@1
	const char *v5; // edx@7
	int v6; // [sp+10h] [bp-4h]@1

	v6 = -1;
	v1 = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 340, 156, 10, 3, 9, 14, 16);
	v2 = a1->sprite;
	v3 = sprite_create(MOBD_45, 0, a1->sprite);
	v2->mobd_id = MOBD_45;
	v2->parent = v3;
	v3->parent = 0;
	v3->z_index = 0;
	v2->z_index = 1;
	a1->script_type = SCRIPT_TYPE_8;
	stru29_list_4439F0(v2, v1, 0, 1, 0);
    stru29_list_set_bit_by_sprite(a1->sprite, 1);
	while (1)
	{
		if (v6 != SBYTE2(_46E420_starting_cash_idx))
		{
			v1->field_18 = 0;
			v1->num_lines = 0;
			v5 = "ON ";
			if (!BYTE2(_46E420_starting_cash_idx))
				v5 = "OFF";
			render_string_443D80(v1, v5, 0);
			v6 = SBYTE2(_46E420_starting_cash_idx);
		}
		script_443780(a1, 2096, 0, 2);
	}
}
// 47C5FC: using guessed type int _46E420_starting_cash_idx;

//----- (00441430) --------------------------------------------------------
int get_current_level_starting_cash()
{
	if (!single_player_game || _47C6D8_use__466098_cost_multipliers)
		return atoi(_46E420_starting_cash[(char)_46E420_starting_cash_idx]);
	else
		return levels[current_level_idx].survivor_starting_cash;
}

//----- (00441470) --------------------------------------------------------
void script_441470_mobd45_evt8(Script *a1)
{
	RenderString *v1; // ebp@3
	Sprite *v2; // esi@3
	Sprite *v3; // eax@3

	if (netz_47C6C0_mapd_idx == LEVEL_MUTE_01)
		LOBYTE_HEXRAYS(_46E420_starting_cash_idx) = 0;
	v1 = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 424, 74, 10, 3, 9, 14, 16);
	v2 = a1->sprite;
	v3 = sprite_create(MOBD_45, 0, a1->sprite);
	v2->mobd_id = MOBD_45;
	v2->parent = v3;
	v3->parent = 0;
	v3->z_index = 0;
	v2->z_index = 1;
	a1->script_type = SCRIPT_TYPE_8;
	stru29_list_4439F0(v2, v1, 0, 1, 0);
	while (1)
	{
		v1->field_18 = 0;
		v1->num_lines = 0;
		render_string_443D80(v1, _46E420_starting_cash[(char)_46E420_starting_cash_idx], 0);
		while (!script_443780(a1, 2140, 1, 0))
			;
		LOBYTE_HEXRAYS(_46E420_starting_cash_idx) = (_46E420_starting_cash_idx + 1) & 7;
		if (netz_47C6C0_mapd_idx != 15)
			netz_44A2A0(64, (int)&_46E420_starting_cash_idx, 5);
	}
}
// 47C5FC: using guessed type int _46E420_starting_cash_idx;

//----- (00441550) --------------------------------------------------------
void script_441550_mobd45_evt8(Script *a1)
{
	int v1; // ebp@1
	RenderString *v2; // edi@1
	Sprite *v3; // esi@1
	Sprite *v4; // eax@1

	v1 = -1;
	v2 = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 424, 74, 10, 3, 9, 14, 16);
	v3 = a1->sprite;
	v4 = sprite_create(MOBD_45, 0, a1->sprite);
	v3->mobd_id = MOBD_45;
	v3->parent = v4;
	v4->parent = 0;
	v4->z_index = 0;
	v3->z_index = 1;
	a1->script_type = SCRIPT_TYPE_8;
	stru29_list_4439F0(v3, v2, 0, 1, 0);
    stru29_list_set_bit_by_sprite(a1->sprite, 1);
	while (1)
	{
		if (v1 != (char)_46E420_starting_cash_idx)
		{
			v2->field_18 = 0;
			v2->num_lines = 0;
			render_string_443D80(v2, _46E420_starting_cash[(char)_46E420_starting_cash_idx], 0);
			v1 = (char)_46E420_starting_cash_idx;
		}
		script_443780(a1, 2140, 0, 0);
	}
}
// 47C5FC: using guessed type int _46E420_starting_cash_idx;

//----- (00441630) --------------------------------------------------------
int _441630_get_current_level_field14__get_max_upgrade_level(int a1)
{
	int v1; // ecx@1
	int v2; // ecx@3
	int result; // eax@8

	v1 = a1 - 61;
	if (v1)
	{
		if (v1 == 1)
			v2 = 4;
		else
			v2 = 5;
	}
	else
	{
		v2 = 3;
	}
	if (!single_player_game || _47C6D8_use__466098_cost_multipliers)
		result = SBYTE1(_46E420_starting_cash_idx);
	else
		result = levels[current_level_idx].field_14;
	if (v2 < result)
		result = v2;
	return result;
}
// 468B5C: using guessed type int single_player_game;
// 47C5FC: using guessed type int _46E420_starting_cash_idx;

//----- (00441680) --------------------------------------------------------
void script_441680_mobd45_evt8(Script *a1)
{
	RenderString *v1; // ebx@3
	Sprite *v2; // esi@3
	Sprite *v3; // eax@3
	bool v4; // zf@6
	bool v5; // sf@6
	unsigned __int8 v6; // of@6
	char v7[8]; // [sp+10h] [bp-8h]@4

	if (netz_47C6C0_mapd_idx == 15)
		BYTE1(_46E420_starting_cash_idx) = 5;
	v1 = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 500, 156, 10, 3, 9, 14, 16);
	v2 = a1->sprite;
	v3 = sprite_create(MOBD_45, 0, a1->sprite);
	v2->mobd_id = MOBD_45;
	v2->parent = v3;
	v3->parent = 0;
	v3->z_index = 0;
	v2->z_index = 1;
	a1->script_type = SCRIPT_TYPE_8;
	stru29_list_4439F0(v2, v1, 0, 1, 0);
	while (1)
	{
		sprintf(v7, aD_2, SBYTE1(_46E420_starting_cash_idx));
		v1->field_18 = 0;
		v1->num_lines = 0;
		render_string_443D80(v1, v7, 0);
		while (!script_443780(a1, 2112, 1, 2))
			;
		v6 = __OFSUB__(BYTE1(_46E420_starting_cash_idx) + 1, 5);
		v4 = BYTE1(_46E420_starting_cash_idx) == 4;
		v5 = (char)(BYTE1(_46E420_starting_cash_idx)++ - 4) < 0;
		if (!((unsigned __int8)(v5 ^ v6) | v4))
			BYTE1(_46E420_starting_cash_idx) = 2;
		if (netz_47C6C0_mapd_idx != 15)
			netz_44A2A0(64, (int)&_46E420_starting_cash_idx, 5);
	}
}
// 47C5FC: using guessed type int _46E420_starting_cash_idx;

//----- (00441780) --------------------------------------------------------
void script_441780_mobd45_evt8(Script *a1)
{
	RenderString *v1; // ebp@2
	Sprite *v2; // esi@2
	Sprite *v3; // eax@2
	int i; // eax@2
	DataMobdItem *v5; // edx@8
	RenderString *v6; // edi@8
	Sprite *v7; // esi@8
	Sprite *v8; // eax@8
	char a2[4]; // [sp+10h] [bp-10h]@5
	char v11[8]; // [sp+18h] [bp-8h]@14

	if (netz_47C6C0_mapd_idx == LEVEL_MUTE_01)
	{
		v1 = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 284, 252, 10, 3, 9, 14, 16);
		v2 = a1->sprite;
		v3 = sprite_create(MOBD_45, 0, a1->sprite);
		v2->mobd_id = MOBD_45;
		v2->parent = v3;
		v3->parent = 0;
		v3->z_index = 0;
		v2->z_index = 1;
		a1->script_type = SCRIPT_TYPE_8;
		stru29_list_4439F0(v2, v1, 0, 1, 0);
		for (i = dword_46E3FC; ; i = dword_46E3FC++ + 1)
		{
			if (i > 3)
			{
				i = 1;
				dword_46E3FC = 1;
			}
			sprintf(a2, aD_2, i);
			v1->field_18 = 0;
			v1->num_lines = 0;
			render_string_443D80(v1, a2, 0);
			while (!script_443780(a1, 1656, 1, 2))
				;
		}
	}
	v5 = currently_running_lvl_mobd[MOBD_FONT_ITALIC].items;
	*(_DWORD *)a2 = -1;
	v6 = render_string_create(0, v5, 500, 156, 10, 3, 9, 14, 16);
	v7 = a1->sprite;
	v8 = sprite_create(MOBD_45, 0, a1->sprite);
	v7->mobd_id = MOBD_45;
	v7->parent = v8;
	v8->parent = 0;
	v8->z_index = 0;
	v7->z_index = 1;
	a1->script_type = SCRIPT_TYPE_8;
	stru29_list_4439F0(v7, v6, 0, 1, 0);
    stru29_list_set_bit_by_sprite(a1->sprite, 1);
	while (1)
	{
		if (*(_DWORD *)a2 != SBYTE1(_46E420_starting_cash_idx))
		{
			sprintf(v11, aD_2, SBYTE1(_46E420_starting_cash_idx));
			v6->field_18 = 0;
			v6->num_lines = 0;
			render_string_443D80(v6, v11, 0);
			*(_DWORD *)a2 = SBYTE1(_46E420_starting_cash_idx);
		}
		script_443780(a1, 2112, 0, 2);
	}
}

//----- (00441940) --------------------------------------------------------
void script_441940_mobd45_evt17(Script *a1)
{
	Sprite *v1; // edi@1
	Sprite *v2; // eax@1
	int v3; // edx@2
	DataMapd *v4; // eax@4
	int v5; // eax@7
	int v6; // eax@12
	DataMapd *v9; // eax@21
	int v10; // ecx@21
	int v11; // ecx@22
	DataMapd *v14; // eax@26
	int v15; // [sp+0h] [bp-Ch]@7

	v1 = a1->sprite;
	v2 = sprite_create(MOBD_45, 0, a1->sprite);
	v1->mobd_id = MOBD_45;
	v1->parent = v2;
	v2->parent = 0;
	v2->z_index = 0;
	v1->z_index = 1;
	a1->script_type = SCRIPT_TYPE_17;
	stru29_list_4439F0(v1, 0, 1, 1, 0);
	while (!script_443780(a1, 2044, 1, 0))
		;
	if (netz_47C6C0_mapd_idx == 15)
	{
		netz_47C6BC_mapd_idx = 15;
		netz_47C6C0_mapd_idx = 0;
		script_408500_anim(a1);
		stru29_list_remove_all(a1);
		stru29_list_alloc();
		bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
        script_sleep(a1, 3);
		v4 = LVL_FindMapd();
		_40E400_set_palette(v4->items->GetPalette());
		_47A010_mapd_item_being_drawn[0] = MAPD_Draw(MAPD_MAP, 0, -10);
		cplc_select(0);
		cplc_406320();
        script_sleep(a1, 1);
		script_4084A0_animation(a1);
		script_terminate(a1);
	}
	else
	{

		LOBYTE_HEXRAYS(v3) = 67;
		netz_42FA00(-1, v3, 0, 0, 1);
		netz_42F9C0(0, 0);
		netz_42F650((void *)j_netz_430690());
		netz_42F8E0(0);
	}
	if (netz_468B6C_providers_idx == 2 || netz_468B6C_providers_idx == 1)
	{
		v11 = netz_47C6C0_mapd_idx;
		netz_47C6C0_mapd_idx = 1;
		netz_47C6BC_mapd_idx = v11;
		script_408500_anim(a1);
        stru29_list_realloc(a1);
		bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
        script_sleep(a1, 3);
		v14 = LVL_FindMapd();
		_40E400_set_palette(v14[1].items->GetPalette());
		_47A010_mapd_item_being_drawn[0] = MAPD_Draw(MAPD_FOG_OF_WAR, 0, -10);
		v10 = 1;
	}
	else
	{
		netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
		netz_47C6C0_mapd_idx = 4;
		script_408500_anim(a1);
        stru29_list_realloc(a1);
		bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
        script_sleep(a1, 3);
		v9 = LVL_FindMapd();
		_40E400_set_palette(v9[4].items->GetPalette());
		_47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)4, 0, -10);
		v10 = 4;
	}
	cplc_select(v10);
	cplc_406320();
    script_sleep(a1, 1);
	script_4084A0_animation(a1);
	script_terminate(a1);
}

//----- (00441CE0) --------------------------------------------------------
void script_441CE0_mobd45_evt8(Script *a1)
{
	Script *v1; // esi@1
	Sprite *v2; // edi@1
	Sprite *v3; // eax@1
	void *v6; // eax@8
	Script *v7; // edx@8
	signed __int64 v8; // rtt@8
	int v9; // eax@11
	int v10; // eax@16
	int v11; // [sp+0h] [bp-Ch]@11

	v1 = a1;
	dword_47C6B8 = 0;
	v2 = a1->sprite;
	v3 = sprite_create(MOBD_45, 0, a1->sprite);
	v2->mobd_id = MOBD_45;
	v2->parent = v3;
	v3->parent = 0;
	v3->z_index = 0;
	v2->z_index = 1;
	v1->script_type = SCRIPT_TYPE_8;
	stru29_list_4439F0(v2, 0, 0, 1, 0);
	if (netz_47C6C0_mapd_idx == 15)
	{
		while (!script_443780(v1, 1872, 1, 0))
			;
	}
	else
	{
		if (!script_create_coroutine(SCRIPT_TYPE_8, script_43F7C0, 0))
			game_state = GAME_STATE::GAME_3;
		do
		{
			while (!script_443780(v1, 1872, dword_47C6B8, 0))
				;
		} while (!netz_42E7B0());
	}

    srand(clock());
	v8 = rand();
	v6 = (void *)(v8 / 0xFFFF);
	v7 = (Script *)(v8 % 0xFFFF);
	kknd_srand_debug((int)v7);
	if (netz_47C6C0_mapd_idx == 15)
	{
		_47C6D8_use__466098_cost_multipliers = 1;
		_47C6DC_dont_execute_unit_handlers = 1;
		single_player_game = 1;
		netz_42E7F0();
		v10 = kknd_rand();
		player_side = (PLAYER_SIDE)(2 * (v10 % 3) + 2);
		if (!_47C658_faction_index)
			player_side = (PLAYER_SIDE)(2 * (v10 % 3) + 1);
		current_level_idx = (LEVEL_ID)(SBYTE3(_46E420_starting_cash_idx) + 30);
		game_state = GAME_STATE::Mission;
		if (_47C6E0_task)
			script_deinit(_47C6E0_task);
	}
	else
	{
		a1 = v7;
		j_netz_430610();
		netz_44A2A0(71, (int)&a1, 4);
		_47C6D8_use__466098_cost_multipliers = 0;
		single_player_game = 0;
		_47C6DC_dont_execute_unit_handlers = 1;
		netz_42E7F0();
		current_level_idx = (LEVEL_ID)(SBYTE3(_46E420_starting_cash_idx) + 30);
		game_state = GAME_STATE::Mission;
		if (_47C6E0_task)
		{
			script_deinit(_47C6E0_task);
			_47C6E0_task = 0;
			return;
		}
	}
	_47C6E0_task = 0;
}

//----- (00441EF0) --------------------------------------------------------
void netz_441EF0(int a1)
{
	_46E420_starting_cash_idx = *(_DWORD *)a1;
	byte_47C600 = *(_BYTE *)(a1 + 4);
}

//----- (00441F10) --------------------------------------------------------
void script_441F10(Script *a1)
{
	int v1; // esi@1
	ScriptEvent *i; // esi@6

	while (1)
	{
		v1 = script_yield_any_trigger(a1, 1);
		if (netz_47A828)
		{
			netz_47A828 = 0;
			_47C6D8_use__466098_cost_multipliers = 0;
			single_player_game = 0;
			_47C6DC_dont_execute_unit_handlers = 1;
			netz_42E7F0();
			current_level_idx = (LEVEL_ID)(SBYTE3(_46E420_starting_cash_idx) + 30);
			game_state = GAME_STATE::Mission;
			if (_47C6E0_task)
				script_deinit(_47C6E0_task);
			_47C6E0_task = 0;
		}
		if (v1 & SCRIPT_FLAGS_20_EVENT_TRIGGER)
		{
			for (i = script_get_next_event(a1); i; i = script_get_next_event(a1))
			{
				if (i->event == EVT_MSG_MISSION_FAILED)
					script_terminate(a1);
				script_discard_event(i);
			}
		}
	}
}

//----- (00441FC0) --------------------------------------------------------
void script_441FC0_mobd45_evt8(Script *a1)
{
	RenderString *v1; // ebx@2
	Sprite *v2; // edi@2
	Sprite *v3; // eax@2
	int i; // eax@2
	Sprite *v5; // esi@8
	Sprite *v6; // edx@8
	Sprite *v7; // eax@8
	Script *v8; // eax@9
	Sprite *v9; // eax@12
	Script *v10; // eax@13
	Sprite *v11; // eax@15
	Script *v12; // eax@16
	Sprite *v13; // eax@18
	Sprite *v14; // eax@20
	Sprite *v15; // eax@22
	Sprite *v16; // eax@24
	char a2[8]; // [sp+10h] [bp-8h]@5

	if (netz_47C6C0_mapd_idx == LEVEL_MUTE_01)
	{
		v1 = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 150, 252, 10, 3, 9, 14, 16);
		v2 = a1->sprite;
		v3 = sprite_create(MOBD_45, 0, a1->sprite);
		v2->mobd_id = MOBD_45;
		v2->parent = v3;
		v3->parent = 0;
		v3->z_index = 0;
		v2->z_index = 1;
		a1->script_type = SCRIPT_TYPE_8;
		stru29_list_4439F0(v2, v1, 0, 1, 0);
		for (i = dword_46E3F8; ; i = dword_46E3F8++ + 1)
		{
			if (i > 2)
			{
				i = 0;
				dword_46E3F8 = 0;
			}
			sprintf(a2, aD_2, i);
			v1->field_18 = 0;
			v1->num_lines = 0;
			render_string_443D80(v1, a2, 0);
			while (!script_443780(a1, 1668, 1, 2))
				;
		}
	}
	v5 = a1->sprite;
	v6 = a1->sprite;
	a1->script_type = SCRIPT_TYPE_9;
	v7 = sprite_create_scripted(MOBD_45, v6, (void(*)(Script *))script_440810_mobd45, SCRIPT_COROUTINE, 0);
	if (v7)
	{
		v8 = v7->script;
		if (v8)
			v8->script_type = a1->script_type;
	}
	else
	{
		stru29_list_remove_all(a1);
		game_state = GAME_STATE::GAME_3;
	}
	v9 = sprite_create_scripted(MOBD_45, v5, (void(*)(Script *))script_440CA0_mobd45_evt8, SCRIPT_COROUTINE, 0);
	if (v9)
	{
		v9->x = 14080;
		v9->y = 27904;
		v10 = v9->script;
		if (v10)
			v10->script_type = a1->script_type;
	}
	v11 = sprite_create_scripted(MOBD_45, v5, (void(*)(Script *))script_440ED0_mobd45_evt8, SCRIPT_COROUTINE, 0);
	if (v11)
	{
		v11->x = 0x2000;
		v11->y = 38400;
		v12 = v11->script;
		if (v12)
			v12->script_type = a1->script_type;
	}
	v13 = sprite_create_scripted(MOBD_45, v5, (void(*)(Script *))script_441550_mobd45_evt8, SCRIPT_COROUTINE, 0);
	if (v13)
	{
		v13->x = 75264;
		v13->y = 17152;
	}
	v14 = sprite_create_scripted(MOBD_45, v5, (void(*)(Script *))script_441340_mobd45_evt8, SCRIPT_COROUTINE, 0);
	if (v14)
	{
		v14->x = 58368;
		v14->y = 38400;
	}
	v15 = sprite_create_scripted(MOBD_45, v5, (void(*)(Script *))script_441150_mobd45_evt8, SCRIPT_COROUTINE, 0);
	if (v15)
	{
		v15->x = 70656;
		v15->y = 27904;
	}
	v16 = sprite_create_scripted(MOBD_45, v5, (void(*)(Script *))script_441780_mobd45_evt8, SCRIPT_COROUTINE, 0);
	if (v16)
	{
		v16->x = 97280;
		v16->y = 38400;
	}
	sprite_list_remove(v5);
	script_terminate(a1);
}

//----- (004421F0) --------------------------------------------------------
void script_4421F0_mobd45_evt8(Script *a1)
{
	RenderString *v1; // esi@2
	Sprite *v2; // edi@2
	Sprite *v3; // eax@2
	int i; // eax@2
	Sprite *v5; // edi@6
	Sprite *v6; // eax@6
	int v7; // eax@13
	Sprite *v8; // eax@17
	int v9; // edx@17
	int v10; // ecx@17
	int v11; // ecx@20
	DataMapd *v12; // eax@20
	int v13; // ecx@20
	DataMapd *v16; // eax@25
	int v17; // [sp+0h] [bp-18h]@13
	char a2[12]; // [sp+Ch] [bp-Ch]@5

	if (netz_47C6C0_mapd_idx == 15)
	{
		v1 = render_string_create(0, currently_running_lvl_mobd[MOBD_FONT_ITALIC].items, 456, 252, 10, 3, 9, 14, 16);
		v2 = a1->sprite;
		v3 = sprite_create(MOBD_45, 0, a1->sprite);
		v2->mobd_id = MOBD_45;
		v2->parent = v3;
		v3->parent = 0;
		v3->z_index = 0;
		v2->z_index = 1;
		a1->script_type = SCRIPT_TYPE_8;
		stru29_list_4439F0(v2, v1, 0, 1, 0);
		for (i = _466098_cost_multiplier_idx; ; i = _466098_cost_multiplier_idx++ + 1)
		{
			if (i >= 3)
			{
				i = 0;
				_466098_cost_multiplier_idx = 0;
			}
			sprintf(a2, aS_0, difficulties[i]);
			v1->field_18 = 0;
			v1->num_lines = 0;
			render_string_443D80(v1, a2, 0);
			script_43BA40(a1, 1680, nullsub_3, 0);
		}
	}
	v5 = a1->sprite;
	v6 = sprite_create(MOBD_45, 0, a1->sprite);
	v5->mobd_id = MOBD_45;
	v5->parent = v6;
	v6->parent = 0;
	v6->z_index = 0;
	v5->z_index = 1;
	a1->script_type = SCRIPT_TYPE_17;
	stru29_list_4439F0(v5, 0, 1, 1, 0);
	if (!script_create_coroutine(SCRIPT_TYPE_9, script_43F7C0, 0))
		game_state = GAME_STATE::GAME_3;
	if (!script_create_coroutine(SCRIPT_TYPE_9, script_441F10, 0))
		game_state = GAME_STATE::GAME_3;
	while (!script_443780(a1, 2044, 1, 0))
		;
	netz_44A220(68, 0, 0);
	netz_42F9C0(0, 0);
	netz_42F650((void *)j_netz_430690());
	if (dword_47C6C4)
	{
		v8 = _47C6E0_task->sprite;
		v9 = v8->y >> 8;
		v10 = v8->x >> 8;
		v8->field_88_unused = 1;
		input_set_mouse_pos(v10, v9);
		dword_47C6C4 = 0;
		sprite_release_mobd_item(_47C664_ingame_menu_sprite);
	}
	if (netz_468B6C_providers_idx == 2 || netz_468B6C_providers_idx == 1)
	{
		netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
		netz_47C6C0_mapd_idx = 1;
		script_408500_anim(a1);
        stru29_list_realloc(a1);
		bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
        script_sleep(a1, 3);
		v16 = LVL_FindMapd();
		_40E400_set_palette(v16[1].items->GetPalette());
		_47A010_mapd_item_being_drawn[0] = MAPD_Draw(MAPD_FOG_OF_WAR, 0, -10);
		v13 = 1;
	}
	else
	{
		v11 = netz_47C6C0_mapd_idx;
		netz_47C6C0_mapd_idx = 4;
		netz_47C6BC_mapd_idx = v11;
		script_408500_anim(a1);
		stru29_list_remove_all(a1);
		stru29_list_alloc();
		bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
        script_sleep(a1, 3);
		v12 = LVL_FindMapd();
		_40E400_set_palette(v12[4].items->GetPalette());
		_47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)4, 0, -10);
		v13 = 4;
	}
	cplc_select(v13);
	cplc_406320();
    script_sleep(a1, 1);
	script_4084A0_animation(a1);
	script_terminate(a1);
}

//----- (00442580) --------------------------------------------------------
void script_442580_mobd45_evt17(Script *task)
{
	Sprite *v1; // edi@1
	Sprite *v2; // eax@1
	DataMapd *v5; // eax@7

	v1 = task->sprite;
	v2 = sprite_create(MOBD_45, 0, task->sprite);
	v1->mobd_id = MOBD_45;
	v1->parent = v2;
	v2->parent = 0;
	v2->z_index = 0;
	v1->z_index = 1;
	task->script_type = SCRIPT_TYPE_17;
	stru29_list_4439F0(v1, 0, 1, 1, 0);
	while (!script_443780(task, 2044, 1, 0))
		;
	netz_free_provider_async();
	netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
	netz_47C6C0_mapd_idx = 0;
	script_408500_anim(task);
    stru29_list_realloc(task);
	bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    script_sleep(task, 3);
	v5 = LVL_FindMapd();
	_40E400_set_palette(v5->items[0].GetPalette());
	_47A010_mapd_item_being_drawn[0] = MAPD_Draw(MAPD_MAP, 0, -10);
	cplc_select(0);
	cplc_406320();
    script_sleep(task, 1);
	script_4084A0_animation(task);
	script_terminate(task);
}
// 47C6C8: using guessed type int stru29_list_initialized;

//----- (004426D0) --------------------------------------------------------
void script_4426D0_mobd45_evt6(Script *a1)
{
	Sprite *v1; // edi@1
	Sprite *v2; // eax@1
	void *v3; // eax@2
	int v4; // eax@5
	int v5; // edi@6
	void *v6; // eax@6
	int v7; // edi@9
	int v8; // ecx@10
	DataMapd *v11; // eax@14
	int v12; // [sp+0h] [bp-Ch]@5
__debugbreak(); // what isn this script?
	v1 = a1->sprite;
	v2 = sprite_create(MOBD_45, 0, a1->sprite);
	v1->mobd_id = MOBD_45;
	v1->parent = v2;
	v2->parent = 0;
	v2->z_index = 0;
	v1->z_index = 1;
	a1->script_type = SCRIPT_TYPE_6;
	stru29_list_4439F0(v1, 0, 0, 1, 0);
	while (1)
	{
		do
			v3 = (void *)script_443780(a1, 1840, dword_47C6EC, 0);
		while (!v3);
		//_40E560_flip_gdi_update_syscolors();
		OsShowCursor(true);
		v5 = netz_42F8E0(1);
		OsShowCursor(false);
		_40E6B0_set_sys_colors();
		if (!v5)
			break;
		v7 = netz_468B6C_providers_idx;
		netz_free_provider_async();
		netz_42E170(v7, netz_default_player_name);
	}
	v8 = netz_47C6C0_mapd_idx;
	netz_47C6C0_mapd_idx = 7;
	netz_47C6BC_mapd_idx = v8;
	script_408500_anim(a1);
    stru29_list_realloc(a1);
	bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    script_sleep(a1, 3);
	v11 = LVL_FindMapd();
	_40E400_set_palette(v11[7].items->GetPalette());
	_47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)7, 0, -10);
	cplc_select(7);
	cplc_406320();
    script_sleep(a1, 1);
	script_4084A0_animation(a1);
	script_terminate(a1);
}

//----- (004428C0) --------------------------------------------------------
void script_4428C0_mobd45_evt6(Script *a1)
{
	Sprite *v1; // esi@1
	Sprite *v2; // eax@1
	void *v3; // eax@2
	int v4; // eax@5
	void *v5; // eax@6
	int v6; // eax@10
	int v7; // esi@11
	int v9; // eax@14
	int v10; // eax@20
	int v11; // esi@25
	DataMapd *v14; // eax@30
	int v15; // [sp+0h] [bp-Ch]@5
__debugbreak(); // what isn this script?

	v1 = a1->sprite;
	v2 = sprite_create(MOBD_45, 0, a1->sprite);
	v1->mobd_id = MOBD_45;
	v1->parent = v2;
	v2->parent = 0;
	v2->z_index = 0;
	v1->z_index = 1;
	a1->script_type = SCRIPT_TYPE_6;
	stru29_list_4439F0(v1, 0, 0, 1, 0);
	while (1)
	{
		do
			v3 = (void *)script_443780(a1, 2080, 1, 0);
		while (!v3);

		v5 = (void *)netz_42F8E0(0);
		netz_47A934 = 1;

		//_40E560_flip_gdi_update_syscolors();
		OsShowCursor(true);
		netz_42F9C0(0, 0);
		v7 = netz_42F9E0(0);
		OsShowCursor(false);
		_40E6B0_set_sys_colors();

		if (!v7)
		{
			v9 = -1;
			dword_46E3F0 = -1;
			while ((dword_468B54 == -1 || v9 == -1) && v7 < 1800)
			{
                script_sleep(a1, 1);
				netz_42F9C0(0, 0);
				v9 = dword_46E3F0;
				++v7;
			}
			if (!v9)
				break;
		}
		v11 = netz_468B6C_providers_idx;
		netz_free_provider_async();
		netz_42E170(v11, netz_default_player_name);
	}
	netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
	netz_47C6C0_mapd_idx = 8;
	script_408500_anim(a1);
    stru29_list_realloc(a1);
	bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    script_sleep(a1, 3);
	v14 = LVL_FindMapd();
	_40E400_set_palette(v14[8].items->GetPalette());
	_47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)8, 0, -10);
	cplc_select(8);
	cplc_406320();
    script_sleep(a1, 1);
	script_4084A0_animation(a1);
	script_terminate(a1);
}

//----- (00442BB0) --------------------------------------------------------
void script_442BB0_mobd46(Script *a1)
{
	Script *v1; // ebp@1
	Sprite *v2; // eax@1
	Script *v3; // ecx@1
	Sprite *v4; // esi@1
	Sprite *v5; // esi@2
	int v6; // edx@4
	unsigned __int8 v7; // al@10
	bool v8; // cf@10
	bool v9; // zf@10
	int v11; // ecx@17
	int v12; // ebx@18
	int v13; // edi@18
	ScriptEvent *v14; // eax@19
	enum SCRIPT_EVENT v15; // edx@20
	ScriptEvent *i; // eax@40
	int v18; // ecx@43
	Sprite *v19; // esi@43
	__int16 v20; // ax@46
	int v21; // edx@46
	unsigned __int16 v22; // bx@57
	int v24; // ecx@64
	int v25; // ebx@65
	int v26; // edi@65
	ScriptEvent *v27; // eax@66
	enum SCRIPT_EVENT v28; // edx@67
	ScriptEvent *v30; // eax@87
	Sprite *pstru6; // [sp+10h] [bp-4h]@1
	Script *a1a; // [sp+18h] [bp+4h]@1

	v1 = a1;
	v2 = a1->sprite;
	v3 = (Script *)v2->cplc_ptr1_pstru20;
	dword_47C6E8 = -1;
	v2->z_index = 1;
	v4 = a1->sprite;
	a1a = v3;
	v4->parent = 0;
	pstru6 = v2;
	v1->script_type = SCRIPT_TYPE_14;
	stru29_list_4439F0(v4, 0, 0, 1, 0);
	sprite_load_mobd(v4, 180);
    script_sleep(v1, 1);
	if (netz_47C6C0_mapd_idx == SCRIPT_TYPE_14)
	{
		v5 = pstru6;
		while (1)
		{
			while (1)
			{
				v6 = dword_47C6E4 ? _46E4C0_mobd_offsets[BYTE2(a1a->num_runs_to_skip)] : _46E4F0_mobd_offsets[BYTE2(a1a->num_runs_to_skip)];
				if (dword_47C6E8 >= 0)
				{
					if (dword_47C6E8 > 9)
						dword_47C6E8 = 9;
				}
				else
				{
					dword_47C6E8 = 0;
				}
				v7 = BYTE2(a1a->num_runs_to_skip);
				v8 = v7 < 9u;
				v9 = v7 == 9;
				if (!v8 && !v9)
					break;
                stru29_list_clear_bit_by_sprite(v5, 1);
				if (BYTE2(a1a->num_runs_to_skip) == dword_47C6E8)
				{
					_47C664_ingame_menu_sprite->field_88_unused = 1;
					v11 = v5->x;
					v5->field_88_unused = 1;
					_47C664_ingame_menu_sprite->x = v11;
					_47C664_ingame_menu_sprite->field_88_unused = 1;
					_47C664_ingame_menu_sprite->y = v5->y;
				}
				sprite_load_mobd(v5, v6);
				v12 = 1;
				v13 = 0;
				do
				{
                    script_wait_event(v1);
					v14 = script_get_next_event(v1);
					if (v14)
					{
						do
						{
							v15 = v14->event;
							switch (v15)
							{
							case EVT_MOUSE_HOVER:
                                stru29_list_443AE0_find_by_sprite(a1->sprite);
                                break;
							case EVT_MSG_SELECTED:
								v13 = 1;
								break;
							case EVT_MSG_1528_cancel:
								v13 = 1;
								v12 = 0;
								break;
							}

							script_discard_event(v14);
							v14 = script_get_next_event(v1);
						} while (v14);
						v5 = pstru6;
					}
				} while (!v13);
				if (v12)
					dword_47C6E8 = BYTE2(a1a->num_runs_to_skip);
			}
            stru29_list_set_bit_by_sprite(v5, 1);
			sprite_release_mobd_item(v5);
            script_wait_event(v1);
			for (i = script_get_next_event(v1); i; i = script_get_next_event(v1))
				script_discard_event(i);
		}
	}
	v18 = dword_47C6E8;
	v19 = pstru6;
	while (1)
	{
		while (1)
		{
			if (dword_47C6E4)
			{
				v20 = current_mute_level;
				v21 = _46E440_mobd_offsets[BYTE2(a1a->num_runs_to_skip)];
			}
			else
			{
				v21 = _46E480_mobd_offsets[BYTE2(a1a->num_runs_to_skip)];
				v20 = current_surv_level;
			}
			if (v18 == -1)
			{
				if ((unsigned __int16)v20 <= 0xEu)
					v18 = (unsigned __int16)v20;
				else
					v18 = 14;
				dword_47C6E8 = v18;
			}
			if (v18 < 0)
			{
				v18 = 0;
				dword_47C6E8 = 0;
			}
			if (v18 > 14)
			{
				v18 = 14;
				dword_47C6E8 = 14;
			}
			v22 = BYTE2(a1a->num_runs_to_skip);
			v8 = v22 < (unsigned __int16)v20;
			v9 = v22 == v20;
			if (v8 || v9)
				break;
            stru29_list_set_bit_by_sprite(v19, 1);
			sprite_release_mobd_item(v19);
            script_wait_event(v1);
			v30 = script_get_next_event(v1);
			if (v30)
			{
				do
				{
					script_discard_event(v30);
					v30 = script_get_next_event(v1);
				} while (v30);
				v18 = dword_47C6E8;
			}
			else
			{
			LABEL_44:
				v18 = dword_47C6E8;
			}
		}
        stru29_list_clear_bit_by_sprite(v19, 1);
		if (BYTE2(a1a->num_runs_to_skip) == v18)
		{
			_47C664_ingame_menu_sprite->field_88_unused = 1;
			v24 = v19->x;
			v19->field_88_unused = 1;
			_47C664_ingame_menu_sprite->x = v24;
			_47C664_ingame_menu_sprite->field_88_unused = 1;
			_47C664_ingame_menu_sprite->y = v19->y;
		}
		sprite_load_mobd(v19, v21);
		v25 = 1;
		v26 = 0;
		do
		{
            script_wait_event(v1);
			v27 = script_get_next_event(v1);
			if (v27)
			{
				do
				{
					v28 = v27->event;
					switch (v28)
					{
					case EVT_MOUSE_HOVER:
                        stru29_list_443AE0_find_by_sprite(v1->sprite);
						break;
					case EVT_MSG_SELECTED:
						v26 = 1;
						break;
					case EVT_MSG_1528_cancel:
						v26 = 1;
						v25 = 0;
						break;
					}

					script_discard_event(v27);
					v27 = script_get_next_event(v1);
				} while (v27);
				v19 = pstru6;
			}
		} while (!v26);
		if (!v25)
			goto LABEL_44;
		v18 = BYTE2(a1a->num_runs_to_skip);
		dword_47C6E8 = BYTE2(a1a->num_runs_to_skip);
	}
}

//----- (00443000) --------------------------------------------------------
void script_443000_mobd45(Script *a1)
{
	Sprite *v1; // edi@1
	Sprite *v2; // eax@1
	DataMapd *v5; // eax@7

	v1 = a1->sprite;
	v2 = sprite_create(MOBD_45, 0, a1->sprite);
	v1->mobd_id = MOBD_45;
	v1->parent = v2;
	v2->parent = 0;
	v2->z_index = 0;
	v1->z_index = 1;
	a1->script_type = SCRIPT_TYPE_17;
	stru29_list_4439F0(v1, 0, 0, 1, 0);
	while (!script_443780(a1, 2044, 1, 0))
		;
	netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
	netz_47C6C0_mapd_idx = 0;
	script_408500_anim(a1);
    stru29_list_realloc(a1);
	bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    script_sleep(a1, 3);
	v5 = LVL_FindMapd();
	_40E400_set_palette(v5->items->GetPalette());
	_47A010_mapd_item_being_drawn[0] = MAPD_Draw(MAPD_MAP, 0, -10);
	cplc_select(0);
	cplc_406320();
    script_sleep(a1, 1);
	script_4084A0_animation(a1);
	script_terminate(a1);
}

//----- (00443140) --------------------------------------------------------
void script_443140_mobd45(Script *a1)
{
	Sprite *v1; // ebx@1
	Sprite *v2; // eax@1
	Sprite *v3; // esi@4
	Sprite *v4; // eax@4
	enum LEVEL_ID v5; // eax@6

	v1 = a1->sprite;
	v2 = sprite_create(MOBD_FONT_ITALIC, 0, a1->sprite);
	_47C664_ingame_menu_sprite = v2;
	if (v2)
		sprite_load_mobd(v2, 1048);
	else
		game_state = GAME_STATE::GAME_3;
	v3 = a1->sprite;
	v4 = sprite_create(MOBD_45, 0, a1->sprite);
	v3->mobd_id = MOBD_45;
	v3->parent = v4;
	v4->parent = 0;
	v4->z_index = 0;
	v3->z_index = 1;
	a1->script_type = SCRIPT_TYPE_13;
	stru29_list_4439F0(v3, 0, 0, 1, 0);
	v1->parent->parent = _47C664_ingame_menu_sprite;
	while (!script_443780(a1, 1968, 1, 0))
		;
	v5 = (LEVEL_ID)dword_47C6E8;
	if (netz_47C6C0_mapd_idx == 14)
	{
		if (dword_47C6E8 < -1 || dword_47C6E8 > 9)
			v5 = (LEVEL_ID)0;
		if (dword_47C6E4)
		{
			player_side = EVOLVED;
			v5 = (LEVEL_ID)((int)v5 + 58);
		}
		else
		{
			player_side = SURVIVORS;
			v5 = (LEVEL_ID)((int)v5 + 48);
		}
	}
	else
	{
		if (dword_47C6E8 < -1 || dword_47C6E8 > 14)
			v5 = (LEVEL_ID)0;
		if (dword_47C6E4)
		{
			player_side = EVOLVED;
			v5 = (LEVEL_ID)((int)v5 + 15);
		}
		else
		{
			player_side = SURVIVORS;
		}
	}
	current_level_idx = v5;
	dword_47C6E8 = -1;
	_47C6D8_use__466098_cost_multipliers = 0;
	single_player_game = 1;
	script_deinit(_47C6E0_task);
	_47C6E0_task = 0;
	stru29_list_remove_all(a1);
	script_408500_anim(a1);
	game_state = GAME_STATE::Mission;
}

//----- (00443290) --------------------------------------------------------
void script_443290_mobd45(Script *a1)
{
	Sprite *v1; // esi@1
	Sprite *v2; // eax@1
	int v3; // esi@2
	int v4; // eax@4

	v1 = a1->sprite;
	v2 = sprite_create(MOBD_45, 0, a1->sprite);
	v1->mobd_id = MOBD_45;
	v1->parent = v2;
	v2->parent = 0;
	v2->z_index = 0;
	v1->z_index = 1;
	a1->script_type = SCRIPT_TYPE_13;
	stru29_list_4439F0(v1, 0, 1, 1, 0);
	while (1)
	{
		v3 = dword_47C6E4 != 0 ? 2020 : 2128;
		while (!script_443780(a1, v3, 1, 0))
			;
		v4 = 1 - dword_47C6E4;
		dword_47C6E4 = 1 - dword_47C6E4;
		if (netz_47C6C0_mapd_idx == 14)
		{
			dword_47C6E8 = 0;
			script_trigger_event_group(a1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_14);
		}
		else if (v4)
		{
			dword_47C6E8 = (unsigned __int16)current_mute_level;
			script_trigger_event_group(a1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_14);
		}
		else
		{
			dword_47C6E8 = (unsigned __int16)current_surv_level;
			script_trigger_event_group(a1, EVT_MSG_1528_cancel, 0, SCRIPT_TYPE_14);
		}
	}
}

//----- (00443380) --------------------------------------------------------
int script_443380(Script *a1, int lookup_table_offset, bool a3)
{
	Script *v3; // edi@1
	int v4; // ebx@1
	Sprite *v5; // esi@1
	Sprite *v6; // ebp@1
	int v7; // eax@2
	ScriptEvent *i; // eax@12
	int v10; // edx@13
	int v12; // edx@24
	int v13; // edx@25

	v3 = a1;
	v4 = 0;
	v5 = a1->sprite;
	v6 = v5->parent;
	do
	{
		while (1)
		{
			v7 = script_yield_any_trigger(v3, 1);
			stru29 *v8 = (stru29 *)v3->sprite->_80_entity__stru29__sprite__initial_hitpoints; // stru29 for main menu sprites
			if (v8 && v8->field_C & 2)
			{
				if (!dword_47C6EC || debug_unit_stats_supplied)
					v4 |= 0x20;
				else
					v4 &= ~0x20;
			}
			if (v7 != 0x80000000)
				break;
			if (v4 & 0x20)
			{
				sprite_load_mobd(v6, 0);
				sprite_4272E0_load_mobd_item(v5, lookup_table_offset, 3);
			}
			else
			{
				sprite_load_mobd(v6, 12);
				sprite_4272E0_load_mobd_item(v5, lookup_table_offset, 0);
			}
		}
		for (i = script_get_next_event(v3); i; i = script_get_next_event(v3))
		{
			v10 = i->event;
			if (v10 > (int)EVT_MSG_SELECTED)
			{
				v12 = v10 - EVT_MSG_DESELECTED;
				if (v12)
				{
					v13 = v12 - 14;
					if (v13)
					{
						if (v13 == 20)
							v4 |= 0x10u;
					}
					else
					{
						v4 |= 1u;
					}
				}
				else
				{
					v4 |= 4u;
				}
			}
			else if (v10 == EVT_MSG_SELECTED)
			{
				if (!a3)
					v4 |= 2u;
			}
			else if (v10 == EVT_MOUSE_HOVER)
			{
                stru29_list_443AE0_find_by_sprite(v5);
				v4 |= 8u;
			}

			script_discard_event(i);
		}
		if (v4 & 0x10)
			return 0;
		if (v4 & 1)
			return 2;
		if (v4 & 8 && !(v4 & 0x20))
		{
			if (v6->_inside_mobd_item == &currently_running_lvl_mobd[v6->mobd_id].items->_[2])
				sprite_4272E0_load_mobd_item(v5, lookup_table_offset, 1);
			else
				sprite_4272E0_load_mobd_item(v5, lookup_table_offset, 2);
		}
	} while (!(v4 & 2) || v4 & 0x20);
	v6->pstru7 = &_479D48_stru7;
	sprite_load_mobd(v6, 24);
	sprite_4272E0_load_mobd_item(v5, lookup_table_offset, 1);
	script_yield(v3, SCRIPT_FLAGS_20_10000000, 0);
	sprite_load_mobd(v6, 12);
	sprite_4272E0_load_mobd_item(v5, lookup_table_offset, 2);
	script_yield(v3, SCRIPT_FLAGS_20_10000000, 0);
	v6->pstru7 = _4640E0_stru7_array;
	return 1;
}

//----- (00443570) --------------------------------------------------------
int script_443570(Script *a1, int a2, int a3, int a4)
{
	Script *v4; // ebp@1
	Sprite *v5; // edi@1
	int v6; // ebx@1
	Sprite *v7; // esi@1
	int result; // eax@3
	int v9; // ebx@5
	ScriptEvent *i; // eax@5
	enum SCRIPT_EVENT v11; // edx@6
	unsigned __int32 v13; // edx@16
	int v14; // edx@17
	int lookup_table_offset; // [sp+10h] [bp-8h]@1
	Sprite *a1a; // [sp+14h] [bp-4h]@1

	v4 = a1;
	v5 = a1->sprite;
	v6 = a2;
	v7 = v5->parent;
	lookup_table_offset = a2;
	a1a = v5->parent;
	if (script_yield_any_trigger(a1, 1) == 0x80000000)
	{
		if (a3)
		{
			sprite_4272E0_load_mobd_item(v7, 1716, a4);
			sprite_4272E0_load_mobd_item(v5, v6, 0);
			result = 0;
		}
		else
		{
			sprite_4272E0_load_mobd_item(v7, 1692, a4);
			sprite_4272E0_load_mobd_item(v5, v6, 3);
			result = 0;
		}
	}
	else
	{
		v9 = 0;
		for (i = script_get_next_event(v4); i; i = script_get_next_event(v4))
		{
			v11 = i->event;
			if ((int)v11 > (int)EVT_MSG_SELECTED)
			{
				v13 = v11 - EVT_MSG_DESELECTED;
				if (v13)
				{
					v14 = v13 - 14;
					if (v14)
					{
						if (v14 == 23)
							return 300;
					}
					else
					{
						v9 |= 1u;
					}
				}
				else
				{
					v9 |= 4u;
				}
			}
			else if (v11 == EVT_MSG_SELECTED)
			{
				v9 |= 2u;
			}
			else if (v11 == EVT_MOUSE_HOVER)
			{
                stru29_list_443AE0_find_by_sprite(v5);
				v9 |= 8u;
			}
			script_discard_event(i);
		}
		if (a3)
		{
			if (v9 & 1)
				return 2;
			if (v9 & 8)
			{
				if (v7->_inside_mobd_item == &currently_running_lvl_mobd[v7->mobd_id].items->_[142])
					sprite_4272E0_load_mobd_item(v5, lookup_table_offset, 1);
				else
					sprite_4272E0_load_mobd_item(v5, lookup_table_offset, 2);
			}
			if (v9 & 2)
			{
				v7->pstru7 = &_479D48_stru7;
				sprite_4272E0_load_mobd_item(a1a, 1704, a4);
				sprite_4272E0_load_mobd_item(v5, lookup_table_offset, 1);
				script_yield(v4, SCRIPT_FLAGS_20_10000000, 0);
				sprite_4272E0_load_mobd_item(a1a, 1716, a4);
				sprite_4272E0_load_mobd_item(v5, lookup_table_offset, 2);
				script_yield(v4, SCRIPT_FLAGS_20_10000000, 0);
				a1a->pstru7 = _4640E0_stru7_array;
				return 2;
			}
		}
		else
		{
			sprite_load_mobd(v7, 96);
			sprite_4272E0_load_mobd_item(v5, lookup_table_offset, 3);
		}
		result = 0;
	}
	return result;
}

//----- (00443780) --------------------------------------------------------
int script_443780(Script *a1, int a2, int a3, int a4)
{
	Script *v4; // ebp@1
	Sprite *v5; // edi@1
	int v6; // ebx@1
	Sprite *v7; // esi@1
	int result; // eax@3
	int v9; // ebx@5
	ScriptEvent *i; // eax@5
	int v11; // edx@6
	int v13; // edx@16
	int v14; // [sp+10h] [bp-8h]@1
	Sprite *v15; // [sp+14h] [bp-4h]@1

	v4 = a1;
	v5 = a1->sprite;
	v6 = a2;
	v7 = v5->parent;
	v14 = a2;
	v15 = v5->parent;
	if (script_yield_any_trigger(a1, 1) == 0x80000000)
	{
		if (a3)
		{
			sprite_4272E0_load_mobd_item(v7, 1716, a4);
			sprite_4272E0_load_mobd_item(v5, v6, 0);
			result = 0;
		}
		else
		{
			sprite_4272E0_load_mobd_item(v7, 1692, a4);
			sprite_4272E0_load_mobd_item(v5, v6, 3);
			result = 0;
		}
	}
	else
	{
		v9 = 0;
		for (i = script_get_next_event(v4); i; i = script_get_next_event(v4))
		{
			v11 = i->event;
			if (v11 > (int)EVT_MSG_SELECTED)
			{
				v13 = v11 - EVT_MSG_DESELECTED;
				if (v13)
				{
					if (v13 == 14)
						v9 |= 1u;
				}
				else
				{
					v9 |= 4u;
				}
			}
			else if (v11 == EVT_MSG_SELECTED)
			{
				v9 |= 2u;
			}
			else if (v11 == EVT_MOUSE_HOVER)
			{
                stru29_list_443AE0_find_by_sprite(v5);
				v9 |= 8u;
			}
			script_discard_event(i);
		}
		if (a3)
		{
			if (v9 & 1)
				return 2;
			if (v9 & 8)
			{
				if (v7->_inside_mobd_item == &currently_running_lvl_mobd[v7->mobd_id].items->_[142])
					sprite_4272E0_load_mobd_item(v5, v14, 1);
				else
					sprite_4272E0_load_mobd_item(v5, v14, 2);
			}
			if (v9 & 2)
			{
				v7->pstru7 = &_479D48_stru7;
				sprite_4272E0_load_mobd_item(v15, 1704, a4);
				sprite_4272E0_load_mobd_item(v5, v14, 1);
				script_yield(v4, SCRIPT_FLAGS_20_10000000, 0);
				sprite_4272E0_load_mobd_item(v15, 1716, a4);
				sprite_4272E0_load_mobd_item(v5, v14, 2);
				script_yield(v4, SCRIPT_FLAGS_20_10000000, 0);
				v15->pstru7 = _4640E0_stru7_array;
				return 2;
			}
		}
		else
		{
			sprite_load_mobd(v7, 96);
			sprite_4272E0_load_mobd_item(v5, v14, 3);
		}
		result = 0;
	}
	return result;
}

//----- (00443C40) --------------------------------------------------------
void script_443C40(Script *a1, int cplc_item)
{
	enum MAPD_ID v2; // edi@1
	Script *v3; // esi@1
	DataMapd *v6; // eax@5

	v2 = (MAPD_ID)cplc_item;
	v3 = a1;
	netz_47C6BC_mapd_idx = netz_47C6C0_mapd_idx;
	netz_47C6C0_mapd_idx = cplc_item;
	script_408500_anim(a1);
    stru29_list_realloc(a1);
	bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    script_sleep(v3, 3);
	v6 = LVL_FindMapd();
	_40E400_set_palette(v6[v2].items->GetPalette());
	_47A010_mapd_item_being_drawn[0] = MAPD_Draw(v2, 0, -10);
	cplc_select(v2);
	cplc_406320();
    script_sleep(v3, 1);
	script_4084A0_animation(v3);
	if (netz_47C6BC_mapd_idx || v2 != 12)
		script_terminate(v3);
}
// 47C6C8: using guessed type int stru29_list_initialized;

//----- (00443D40) --------------------------------------------------------
void script_443D40_mobd20(Script *a1)
{
	sprite_list_remove(a1->sprite);
	script_terminate(a1);
}

//----- (00443D60) --------------------------------------------------------
int _443D60_strlen_before_newline(const char *str)
{
	char v1; // dl@1
	int result; // eax@1

	v1 = *str;
	for (result = 0; v1; v1 = str[result++ + 1])
	{
		if (v1 == '\n')
			break;
	}
	return result;
}

//----- (00443D80) --------------------------------------------------------
stru8 *render_string_443D80(RenderString *a1, const char *a2, DataMobdItem *a3)
{
	stru8 *result; // eax@1
	const char *v4; // edi@1
	char v5; // dl@1
	int v6; // ebp@1
	int v7; // esi@1
	char v8; // bl@5
	int v9; // edx@11
	int v10; // edx@12
	int v11; // ebp@12
	int v12; // ebx@12
	int v13; // edi@12
    DataMobdItem_stru0 *v14; // edi@19
    DataMobdItem_stru1 *v15; // edi@21
	bool v16; // zf@24
	const char *v17; // [sp+Ch] [bp-Ch]@1
	stru8 *v18; // [sp+10h] [bp-8h]@8
	int v19; // [sp+14h] [bp-4h]@1

	result = a1->pstru8;
	v4 = a2;
	v17 = a2;
	v5 = *a2;
	v6 = result->drawjob->job_details.x + 14;
	v19 = result->drawjob->job_details.x + 14;
	v7 = result->drawjob->job_details.x + 14;
	if (*v17)
	{
		while (1)
		{
			result = 0;
			if (v5)
			{
				v8 = v5;
				do
				{
					if (v8 == 10)
						break;
					v8 = v4[(_DWORD)result + 1];
					result = (stru8 *)((char *)result + 1);
				} while (v8);
			}
			v18 = result;
			if (!result)
				v18 = (stru8 *)1;
			if (v5 == 10)
			{
				v7 = v6;
				v9 = a1->num_lines + 1;
				++v4;
				a1->field_18 = 0;
				a1->num_lines = v9;
				v17 = v4;
			}
			else
			{
				result = a1->pstru8;
				v10 = (a1->num_lines + 1) * a1->field_C;
				v11 = 16 * (a1->num_lines + 1) + result->drawjob->job_details.y;
				v12 = a1->field_18;
				v13 = v10 + v12 + 1;
				if (v10 + v12 != -1)
				{
					do
					{
						result = result->next;
						--v13;
					} while (v13);
				}
				if (v12 > 1)
					v7 = result->drawjob->job_details.x;
				if (v18)
				{
					v4 = v17;
					do
					{
						if (a3)
							v14 = a3->_[*v4 + 1];
						else
							v14 = a1->mobd_font__see_sub405A60->_[1 + *v4];
						result->drawjob->job_details.image = v14->sprt;
						result->drawjob->job_details.y = v11 - v14->y_offset;
						result->drawjob->job_details.x = v7 - v14->x_offset;
						v15 = v14->field_18;
						if (v15)
							v7 = result->drawjob->job_details.x + (v15->x_offset >> 8);
						else
							v7 = result->drawjob->job_details.x + 14;
						result = result->next;
						v4 = v17++ + 1;
						result->drawjob->job_details.x = v7;
						v16 = v18 == (stru8 *)1;
						++a1->field_18;
						v18 = (stru8 *)((char *)v18 - 1);
					} while (!v16);
				}
				else
				{
					v4 = v17;
				}
			}
			v5 = *v4;
			if (!*v4)
				break;
			v6 = v19;
		}
	}
	return result;
}

//----- (00443EE0) --------------------------------------------------------
int render_string_443EE0(RenderString *a1, int a2, int a3)
{
	stru8 *v3; // eax@1
	int v4; // esi@1
	int v5; // ecx@1

	v3 = a1->pstru8;
	v4 = a1->field_C * (a3 + 1);
	v5 = v4 + a2 + 1;
	if (v4 + a2 != -1)
	{
		do
		{
			v3 = v3->next;
			--v5;
		} while (v5);
	}
	return v3->drawjob->job_details.x;
}

//----- (00443F10) --------------------------------------------------------
void netz_443F10()
{
	netz_44A160(64, (char *)&_46E420_starting_cash_idx, 5);
}
// 47C5FC: using guessed type int _46E420_starting_cash_idx;

//----- (00443F20) --------------------------------------------------------
int sub_443F20()
{
	int result; // eax@1
	char v1[20]; // [sp+10h] [bp-34h]@1
	char v2[28]; // [sp+24h] [bp-20h]@1
	__int16 v3; // [sp+40h] [bp-4h]@1

	memcpy(v1, aCLevelsMute1_wav, sizeof(v1));
	memset(v2, 0, sizeof(v2));
	v3 = 0;
	result = dword_47C6EC;
	if (dword_47C6EC)
	{
		result = _47A2E4_mess_with_game_dir;
		dword_47C6EC = 1;
	}
	return result;
}

//----- (00444080) --------------------------------------------------------
void sub_444080(int mapd_idx)
{
	int v1; // eax@2
	Sprite *v4; // eax@10

	switch (mapd_idx)
	{
	case 7:
	case 8:
		v1 = -(netz_468B6C_providers_idx != 0);
		LOBYTE_HEXRAYS(v1) = v1 & 0xFD;
		netz_47C6BC_mapd_idx = v1 + 4;
		break;
	case 4:
		netz_47C6BC_mapd_idx = 1;
		break;
	case 1:
		netz_47C6BC_mapd_idx = 0;
		break;
	default:
		break;
	}
	netz_47C6C0_mapd_idx = mapd_idx;
	if (!_47C6E0_task)
	{
        stru29_list_alloc();
		v4 = sprite_create_scripted(MOBD_79, 0, (void(*)(Script *))script_mobd79__main_menu_mouse_handler, SCRIPT_COROUTINE, 0);
		((Coroutine *)v4->script->handler)->resume();
	}
}

//----- (00445650) --------------------------------------------------------
void coroutine_main()
{
    Script *arg = task_creation_handler_arg;
    auto script_main = task_creation_handler;

    coroutine_current->yield_to->resume();

    log(
        "Coroutine #%u %s(%08X) start",
        coroutine_current->id, coroutine_current->debug_handler_name, arg
    );
    script_main(arg);

    log(
        "Coroutine #%u %s(%08X) end",
        coroutine_current->id, coroutine_current->debug_handler_name, arg
    );

    script_terminate(arg);
}

//----- (00445690) --------------------------------------------------------
bool render_string_list_alloc(const int num_stru8s, const int num_render_strings)
{
	if (stru8_list = new stru8[num_stru8s])
	{
		if (render_string_list = new RenderString[num_render_strings])
		{
			stru8_list_allocated = 1;
			stru8_list_size = num_stru8s;
			for (int i = 0; i < num_stru8s - 1; ++i)
			{
				stru8_list[i].next = &stru8_list[i + 1];
			}
			stru8_list[num_stru8s - 1].next = 0;
			stru8_list_head = stru8_list;


			for (int i = 0; i < num_render_strings - 1; ++i)
			{
				render_string_list[i].next = &render_string_list[i + 1];
			}
			render_string_list[num_render_strings - 1].next = 0;
			render_string_list_47C784 = 0;
			render_string_list_free_pool = render_string_list;
			return true;
		}
		else
		{
			free(stru8_list);
			stru8_list_allocated = 0;
			return false;
		}
	}
	else
	{
		stru8_list_allocated = 0;
		return false;
	}
}

//----- (00445770) --------------------------------------------------------
void render_string_445770(RenderString *a1, const char *text, DataMobdItem *a3)
{
	const char *v3; // edi@1
	char i; // bl@1
	int v5; // edx@2
	int v6; // esi@2
	char v7; // al@3
	int v8; // ebp@7
	int v9; // eax@11
	int v10; // esi@13
	stru8 *v11; // esi@17
	int j; // eax@17
	int v13; // eax@20
    DataMobdItem_stru0 *v14; // edx@22

	v3 = text;
	for (i = *text; *v3; i = *v3)
	{
		v5 = 0;
		v6 = 0;
		if (i != ' ')
		{
			v7 = i;
			do
			{
				if (!v7)
					break;
				if (v7 == 10)
					break;
				v7 = v3[v6++ + 1];
			} while (v7 != ' ');
		}
		v8 = v6;
		if (!v6)
			v8 = 1;
		if (i == '\n' || v8 > a1->field_C - a1->field_18 - 2)
		{
			v9 = a1->field_10;
			if (v9 > 1 && a1->num_lines >= v9 - 2)
				return;
			v10 = a1->num_lines;
			a1->field_18 = 0;
			a1->num_lines = v10 + 1;
			i = *v3;
			if (*v3 == 32)
				v5 = 1;
		}
		if (i == '\n' || v5)
		{
			++v3;
		}
		else
		{
			v11 = a1->pstru8;
			for (j = a1->field_18 + (a1->field_10 > 1) + a1->field_C * ((a1->field_10 > 1) + a1->num_lines); j; --j)
				v11 = v11->next;
			if (v8)
			{
				v13 = v8;
				do
				{
					if (a3)
						v14 = a3->_[*v3 + 1];
					else
						v14 = a1->mobd_font__see_sub405A60->_[*v3 + 1];
					++v3;
					v11->drawjob->job_details.image = v14->sprt;
					v11 = v11->next;
					--v13;
					++a1->field_18;
				} while (v13);
			}
		}
	}
}

//----- (00445870) --------------------------------------------------------
RenderString *render_string_create(stru1_draw_params *a1, DataMobdItem *custom_font, int a3, int a4, int a5, int a6, int z_index, int a8, int a9)
{
	DataMobdItem *v9; // ebp@1
	RenderString *result; // eax@2
	int v11; // edx@3
	RenderString *v12; // ecx@5
	stru8 *v13; // esi@6
	int v14; // edi@6
	int v15; // ebx@6
	DrawJob *v16; // eax@7
	DataMobdItem_stru0 *v17; // ecx@11
	stru8 *v18; // eax@28
	int v19; // [sp+10h] [bp-14h]@6
	int v20; // [sp+14h] [bp-10h]@3
	stru1_draw_params *v21; // [sp+1Ch] [bp-8h]@1
	RenderString *v22; // [sp+20h] [bp-4h]@5

	v9 = custom_font;
	v21 = a1;
	if (!stru8_list_allocated)
		return 0;
	v11 = a5 * a6;
	v20 = a5 * a6;
	if (a5 * a6 > stru8_list_size)
		return 0;
	result = render_string_list_free_pool;
	v12 = render_string_list_free_pool;
	v22 = render_string_list_free_pool;
	if (render_string_list_free_pool)
	{
		render_string_list_free_pool = render_string_list_free_pool->next;
		v13 = stru8_list_head;
		stru8_list_size -= v11;
		v19 = a4;
		v14 = a3;
		v15 = a3 + a8 * (a5 - 1);
		if (v11)
		{
			while (1)
			{
				v16 = draw_list_add(0, 0);
				v13->drawjob = v16;
				if (!v16)
					return 0;
				if (a6 == 1)
					break;
				if (v19 == a4)
				{
					if (v14 == a3)
					{
						v17 = v9->_[1];
					}
					else if (v14 == v15)
					{
						v17 = v9->_[3];
					}
					else
					{
						v17 = v9->_[2];
					}
					goto LABEL_26;
				}
				if (v19 == a4 + a9 * (a6 - 1))
				{
					if (v14 == a3)
					{
						v17 = v9->_[6];
					}
					else if (v14 == v15)
					{
						v17 = v9->_[8];
					}
					else
					{
						v17 = v9->_[7];
					}
					goto LABEL_26;
				}
				if (v14 == a3)
				{
					v17 = v9->_[4];
				}
				else
				{
					if (v14 != v15)
						break;
					v17 = v9->_[5];
				}
			LABEL_26:
				v16->job_details.image = v17->sprt;
				v13->drawjob->job_details.x = v14 - v17->x_offset;
				v13->drawjob->job_details.y = v19 - v17->y_offset;
				v13->drawjob->job_details.z_index = z_index;
				v13->drawjob->job_details.params = v21;
				v14 += a8;
				if (v14 > v15)
				{
					v14 = a3;
					v19 += a9;
				}
				v18 = v13;
				v13 = v13->next;
				if (!--v20)
				{
					v12 = v22;
					goto LABEL_32;
				}
			}
			v17 = v9->_[33];
			goto LABEL_26;
		}
		v18 = (stru8 *)a3;
	LABEL_32:
		v12->pstru8 = stru8_list_head;
		stru8_list_head = v13;
		v18->next = 0;
		v12->mobd_font__see_sub405A60 = v9;
		v12->field_C = a5;
		v12->field_10 = a6;
		v12->field_18 = 0;
		v12->num_lines = 0;
		v12->next = render_string_list_47C784;
		if (render_string_list_47C784)
			render_string_list_47C784->prev = v12;
		v12->prev = 0;
		render_string_list_47C784 = v12;
		result = v12;
	}
	return result;
}

//----- (00445A60) --------------------------------------------------------
void render_string_list_remove(RenderString *a1)
{
	stru8 *v1; // eax@1
	stru8 *v2; // edx@2
	RenderString *v3; // eax@5

	v1 = a1->pstru8;
	if (v1)
	{
		do
		{
			v1->drawjob->flags |= 0x80000000;
			v2 = v1;
			v1 = v1->next;
		} while (v1);
	}
	else
	{
		v2 = nullptr;
	}
	v2->next = stru8_list_head;
	stru8_list_head = a1->pstru8;
	stru8_list_size += a1->field_C * a1->field_10;
	v3 = a1->prev;
	if (v3)
		v3->next = a1->next;
	else
		render_string_list_47C784 = a1->next;
	if (a1->next)
		a1->next->prev = a1->prev;
	a1->next = render_string_list_free_pool;
	render_string_list_free_pool = a1;
}
// 47C76C: using guessed type int stru8_list_size;

//----- (00445AE0) --------------------------------------------------------
int render_string_445AE0(RenderString *a1)
{
	stru8 *v1; // edx@1
	int v2; // esi@1
	int result; // eax@1

	v1 = a1->pstru8;
	v2 = 0;
	for (result = 0; v1; v1 = v1->next)
	{
		if (v2 > 0 && v2 < a1->field_10 - 1 && result > 0 && result < a1->field_C - 1)
			v1->drawjob->job_details.image = a1->mobd_font__see_sub405A60->_[33]->sprt;
		if (++result >= a1->field_C)
		{
			result = 0;
			++v2;
		}
	}
	return result;
}

//----- (00445B30) --------------------------------------------------------
void render_string_list_free()
{
	stru8 **v0 = 0; // ecx@0
	RenderString *i; // edx@2
	stru8 *j; // eax@3
	RenderString **v3; // eax@5

	if (stru8_list_allocated)
	{
		for (i = render_string_list_47C784; render_string_list_47C784; i = render_string_list_47C784)
		{
			for (j = i->pstru8; j; j = j->next)
			{
				j->drawjob->flags |= 0x80000000;
				v0 = (stru8 **)j;
			}
			*v0 = stru8_list_head;
			stru8_list_head = i->pstru8;
			stru8_list_size += i->field_C * i->field_10;
			v3 = &i->prev->next;
			if (v3)
				*v3 = i->next;
			else
				render_string_list_47C784 = i->next;
			if (i->next)
				i->next->prev = i->prev;
			i->next = render_string_list_free_pool;
			render_string_list_free_pool = i;
		}
		free(stru8_list);
		free(render_string_list);
		stru8_list_allocated = 0;
	}
}
// 47C76C: using guessed type int stru8_list_size;
// 47C770: using guessed type int stru8_list_allocated;

//----- (00445C00) --------------------------------------------------------
int _445C00_text(const char *str, int num_bytes)
{
	char v2; // al@2
	int v3; // edx@3
	int v4; // edi@3
	int v5; // ebp@4
	int v6; // esi@4
	char v7; // bl@5
	int result; // eax@20
	int v9; // [sp+10h] [bp-4h]@1

	v9 = num_bytes;
	if (str && (v2 = *str) != 0)
	{
		v3 = 1;
		v4 = 0;
		do
		{
			v5 = 0;
			v6 = 0;
			if (v2 != ' ')
			{
				v7 = v2;
				do
				{
					if (!v7)
						break;
					if (v7 == '\n')
						break;
					v7 = str[v6++ + 1];
				} while (v7 != ' ');
			}
			if (!v6)
				v6 = 1;
			if (v2 == '\n' || v6 > v9 - v4)
			{
				v4 = 0;
				++v3;
				if (v2 == ' ')
					v5 = 1;
			}
			if (v2 == '\n' || v5)
			{
				++str;
			}
			else
			{
				v4 += v6;
				str += v6;
			}
			v2 = *str;
		} while (*str);
		result = v3;
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (00445C80) --------------------------------------------------------
int _445C80_text(const char *a1, int a2)
{
	char v2; // al@2
	int v3; // edi@3
	int v4; // edx@3
	int v5; // ebp@4
	int v6; // esi@4
	char v7; // bl@5
	int result; // eax@30
	int v9; // [sp+10h] [bp-8h]@3
	int v10; // [sp+14h] [bp-4h]@1

	v10 = a2;
	if (a1 && (v2 = *a1) != 0)
	{
		v3 = 0;
		v9 = 0;
		v4 = 0;
		do
		{
			v5 = 0;
			v6 = 0;
			if (v2 != ' ')
			{
				v7 = v2;
				do
				{
					if (!v7)
						break;
					if (v7 == '\n')
						break;
					v7 = a1[v6++ + 1];
				} while (v7 != ' ');
			}
			if (!v6)
				v6 = 1;
			if (v2 == '\n' || v6 > v10 - v3)
			{
				if (v4)
					--v3;
				if (v3 > v9)
					v9 = v3;
				v3 = 0;
				if (v2 == ' ')
					v5 = 1;
			}
			v4 = 0;
			if (v2 == '\n' || v5)
			{
				++a1;
			}
			else
			{
				if (v2 == ' ')
					v4 = 1;
				v3 += v6;
				a1 += v6;
			}
			v2 = *a1;
		} while (*a1);
		if (v4)
			--v3;
		if (v3 > v9)
			v9 = v3;
		result = v9;
	}
	else
	{
		result = 0;
	}
	return result;
}

//----- (00445D40) --------------------------------------------------------
bool entity_check_type(Entity *a1, int a2)
{
	int v2; // eax@2

	if (!_47C6D8_use__466098_cost_multipliers)
	{
		if (single_player_game)
		{
			if (player_side == 2)
			{
				v2 = 1;
				return v2 && a2 == 1 && a1->unit_id == UNIT_STATS_MUTE_BLACKSMITH;
			}
		}
		else if (netz_47A740[player_side + 1].field_A)
		{
			v2 = 1;
			return v2 && a2 == 1 && a1->unit_id == UNIT_STATS_MUTE_BLACKSMITH;
		}
		v2 = 0;
		return v2 && a2 == 1 && a1->unit_id == UNIT_STATS_MUTE_BLACKSMITH;
	}
	v2 = _47C658_faction_index;
	return v2 && a2 == 1 && a1->unit_id == UNIT_STATS_MUTE_BLACKSMITH;
}

//----- (00446420) --------------------------------------------------------
ProductionGroup *entity_building_create_production_group(Entity *a1, enum PRODUCTION_GROUP_ID production_group)
{
	enum PRODUCTION_GROUP_ID v2; // ebx@1
	ProductionGroup *v3; // esi@3
	PRODUCTION_GROUP_ID v5; // edi@8
	int v6; // ecx@8
	int v7; // eax@9
	int v8; // edx@20
	int v9; // eax@20
	int v10; // eax@26
	ProductionGroup *v11; // eax@36
	ProductionGroup *v12; // ecx@37
	ProductionGroup *v13; // ecx@41
	ProductionGroup *v14; // edx@44
	int v15; // eax@46
	Entity *a1a; // [sp+10h] [bp-8h]@1
	int sidebar_open_handler_called; // [sp+14h] [bp-4h]@1

	v2 = production_group;
	a1a = a1;
	sidebar_open_handler_called = 0;
	if (_47C990_production.sidebar_open_mask[production_group])
	{
		_470478_sidebar_button_open_handlers[production_group](0);
		sidebar_open_handler_called = 1;
	}
	v3 = production_group_free_pool;
	if (production_group_free_pool)
		production_group_free_pool = production_group_free_pool->next;
	else
		v3 = 0;
	if (!v3)
		return 0;
	v5 = v2;
	v6 = 1;
	if (_47C6D8_use__466098_cost_multipliers)
	{
		v7 = _47C658_faction_index;
		goto LABEL_16;
	}
	if (single_player_game)
	{
		if (player_side == 2)
		{
			v7 = 1;
			goto LABEL_16;
		}
	}
	else if (netz_47A740[player_side + 1].field_A)
	{
		v7 = 1;
		goto LABEL_16;
	}
	v7 = 0;
LABEL_16:
	if (v7 && v2 == 1 && a1a->unit_id == UNIT_STATS_MUTE_BLACKSMITH)
		v5 = PRODUCTION_GROUP_BLACKSMITH;
	v8 = _47C978_production.sidebar_open_mask[v5];
	v9 = 0;
	while (v8 & v6)
	{
		++v9;
		v6 *= 2;
		if (v9 >= 3)
			goto LABEL_25;
	}
	_47C978_production.sidebar_open_mask[v5] = v8 | v6;
LABEL_25:
	v3->_44_mobd_lookup_idx = v9;
	v3->_C_entity = a1a;
	v3->group_id = v2;
	v3->field_20 = -1;
	v3->field_40 = v9 + 16 * v2;
	v3->prev_option = (ProductionOption *)&v3->next_option;
	v3->next_option = (ProductionOption *)&v3->next_option;
	if (!_47C6D8_use__466098_cost_multipliers)
	{
		if (single_player_game)
		{
			if (player_side == 2)
			{
				v10 = 1;
				goto LABEL_33;
			}
		}
		else if (netz_47A740[player_side + 1].field_A)
		{
			v10 = 1;
			goto LABEL_33;
		}
		v10 = 0;
		goto LABEL_33;
	}
	v10 = _47C658_faction_index;
LABEL_33:
	if (v10
		&& v2 == 1
		&& a1a->unit_id == UNIT_STATS_MUTE_BLACKSMITH
		&& (v11 = ProductionGroupAccessor(PRODUCTION_GROUP_VEHICLES)->next,
            v11 != ProductionGroupAccessor(PRODUCTION_GROUP_VEHICLES)))
	{
		v12 = v11;
		if (v12 != ProductionGroupAccessor(PRODUCTION_GROUP_VEHICLES))
		{
			do
			{
				if (v11->_C_entity->unit_id == UNIT_STATS_MUTE_BLACKSMITH)
					break;
                v12 = v11;
				v11 = v11->next;
			} while (v11 != &_47C7E4_vehicles_pg);
		}
		if (v11 != v12)
		{
			v12->next = v3;
			v3->prev = v12;
			v3->next = v11;
			v11->prev = v3;
			goto LABEL_46;
		}
		v13 = v11->next;
		v3->prev = v11;
		v3->next = v13;
		if (v11->next)
			v11->next->prev = v3;
	}
	else
	{
		//v11 = (ProductionGroup *)&(&_47C798_infantry_production_group_first)[v2];
		//v14 = (&_47C798_infantry_production_group_first)[v2];
        v11 = ProductionGroupAccessor(v2);
        v14 = ProductionGroupAccessor(v2)->next;
		v3->next = v14;
		v3->prev = v11;
		v14->prev = v3;
	}
	v11->next = v3;
LABEL_46:
	v15 = a1a->unit_id;
	if (v15 >= (int)UNIT_STATS_SURV_OUTPOST && v15 <= (int)UNIT_STATS_MUTE_BEAST_ENCLOSURE)
		entity_410950(a1a, LOBYTE_HEXRAYS(_4701B8_mobd_lookups_per_ProductionGroup_field44[2 * v3->_44_mobd_lookup_idx]));
	v3->sprite = 0;
	if (sidebar_open_handler_called)
		_470490_sidebar_button_close_handlers[v2](0);
	return v3;
}

//----- (00446630) --------------------------------------------------------
void production_group_enable(ProductionGroup *a1, enum UNIT_ID unit_id, int mobd_lookup_table_offset)
{
	ProductionGroup *v3; // ebp@1
	enum UNIT_ID v4; // ebx@1
	ProductionOption *v5; // eax@1
	ProductionOption *end; // edi@1
	enum PRODUCTION_GROUP_ID v7; // eax@4
	ProductionOption *v8; // esi@6
	int v9; // edx@12
	int v10; // eax@12
	ProductionOption *v11; // eax@12
	int v12; // [sp+10h] [bp-4h]@1

	v3 = a1;
	v4 = unit_id;
	v5 = a1->next_option;
	end = (ProductionOption *)&a1->next_option;
	v12 = 0;
	if ((ProductionOption **)v5 == &a1->next_option)
	{
	LABEL_4:
		v7 = a1->group_id;
		if (_47C990_production.sidebar_open_mask[v7])
		{
			_470478_sidebar_button_open_handlers[v7](0);
			v12 = 1;
		}
		v8 = production_option_list_free_pool;
		if (production_option_list_free_pool)
			production_option_list_free_pool = production_option_list_free_pool->next;
		else
			v8 = 0;
		if (v8)
		{
			if (end->next == end)
				script_trigger_event(0, EVT_MSG_1514, 0, _47CA18_sidebar_production_buttons[v3->group_id]->task);
			v8->field_2C = v3->field_40;
			v9 = (int)v3->_C_entity;
			v8->mobd_lookup_table_offset = mobd_lookup_table_offset;
			v8->stru21prod_unit_id = (UNIT_ID)v9;
			v8->unit_id = v4;
			v8->_14_pcost = 0;
			v8->field_18 = 0;
			v8->field_1C = 0;
			v8->field_20 = 0;
			v8->cost = unit_stats[v4].cost;
			v10 = unit_stats[v4].production_time;
			v8->prev = end;
			v8->production_time_x60 = 60 * v10;
			v11 = end->next;
			v8->next = end->next;
			v11->prev = v8;
			end->next = v8;
			if (v12)
				_470490_sidebar_button_close_handlers[v3->group_id](0);
		}
	}
	else
	{
		while (v5->unit_id != unit_id)
		{
			v5 = v5->next;
			if (v5 == end)
				goto LABEL_4;
		}
	}
}

//----- (00446730) --------------------------------------------------------
void production_group_disable(ProductionGroup *a1, enum UNIT_ID unit_id)
{
	ProductionGroup *v2; // ebx@1
	int v3; // ecx@1
	ProductionOption *v4; // esi@1
	ProductionOption *v5; // edi@1
	int v6; // eax@1
	enum PRODUCTION_GROUP_ID v7; // eax@7

	v2 = a1;
	v3 = 0;
	v4 = v2->next_option;
	v5 = (ProductionOption *)&v2->next_option;
	v6 = 0;
	if ((ProductionOption **)v4 != &v2->next_option)
	{
		while (v4->unit_id != unit_id)
		{
			v4 = v4->next;
			if (v4 == v5)
				goto LABEL_6;
		}
		v6 = 1;
	}
LABEL_6:
	if (v6)
	{
		v7 = v2->group_id;
		if (_47C990_production.sidebar_open_mask[v7])
		{
			_470478_sidebar_button_open_handlers[v7](0);
			v3 = 1;
		}
		v4->next->prev = v4->prev;
		v4->prev->next = v4->next;
		v4->next = production_option_list_free_pool;
		production_option_list_free_pool = v4;
		if (v5->next == v5)
		{
			_47C990_production.sidebar_open_mask[v2->group_id] = 0;
			script_trigger_event(0, EVT_MSG_1548_sidebar, 0, _47CA18_sidebar_production_buttons[v2->group_id]->task);
		}
		else if (v3)
		{
			_470490_sidebar_button_close_handlers[v2->group_id](0);
		}
	}
}

//----- (004467E0) --------------------------------------------------------
void production_group_4467E0(ProductionGroup *a1, enum UNIT_ID unit_id)
{
	ProductionGroup *v2; // edi@1
	enum UNIT_ID v3; // esi@1
	enum PRODUCTION_GROUP_ID v4; // eax@1
	ProductionOption *i; // eax@3
	ProductionOption *v6; // ecx@5
	int v7; // [sp+10h] [bp-4h]@1

	v2 = a1;
	v3 = unit_id;
	v7 = 0;
	v4 = a1->group_id;
	if (_47C990_production.sidebar_open_mask[v4])
	{
		_470478_sidebar_button_open_handlers[v4](0);
		v7 = 1;
	}
	for (i = v2->next_option; (ProductionOption **)i != &v2->next_option; i = i->next)
	{
		if (i->unit_id != v3)
		{
			v6 = i->prev;
			i->next->prev = v6;
			i->prev->next = i->next;
			i->next = production_option_list_free_pool;
			production_option_list_free_pool = i;
			i = v6;
		}
	}
	if (v7)
		_470490_sidebar_button_close_handlers[v2->group_id](0);
}

//----- (00446860) --------------------------------------------------------
void production_group_446860(ProductionGroup *a1)
{
	ProductionGroup *v1; // edi@1
	enum PRODUCTION_GROUP_ID v2; // eax@1
	ProductionOption *v3; // esi@3
	ProductionOption **v4; // ebx@3
	int v5; // ecx@4
	int v6; // eax@5
	enum PRODUCTION_GROUP_ID v7; // eax@17
	int v8; // [sp+10h] [bp-4h]@1

	v1 = a1;
	v8 = 0;
	v2 = a1->group_id;
	if (_47C990_production.sidebar_open_mask[v2])
	{
		_470478_sidebar_button_open_handlers[v2](0);
		v8 = 1;
	}
	v3 = v1->next_option;
	v4 = &v1->next_option;
	if ((ProductionOption **)v3 != &v1->next_option)
	{
		do
		{
			v5 = v1->group_id;
			if (_47C6D8_use__466098_cost_multipliers)
			{
				v6 = _47C658_faction_index;
				goto LABEL_12;
			}
			if (single_player_game)
			{
				if (player_side == 2)
				{
					v6 = 1;
					goto LABEL_12;
				}
			}
			else if (netz_47A740[player_side + 1].field_A)
			{
				v6 = 1;
				goto LABEL_12;
			}
			v6 = 0;
		LABEL_12:
			if (v6 && v5 == 1 && v1->_C_entity->unit_id == UNIT_STATS_MUTE_BLACKSMITH)
				v5 = 5;
			_47C978_production.sidebar_open_mask[v5] &= ~_4701A8_sidebar_mask_per_44_mobd_lookup_idx[v1->_44_mobd_lookup_idx];
			stru38_list_427FD0(&v3->_14_pcost, 0);
			v3->next->prev = v3->prev;
			v3->prev->next = v3->next;
			v3->next = production_option_list_free_pool;
			production_option_list_free_pool = v3;
			v3 = *v4;
		} while ((ProductionOption **)*v4 != v4);
	}
	v1->next->prev = v1->prev;
	v1->prev->next = v1->next;
	v1->next = production_group_free_pool;
	production_group_free_pool = v1;
	v7 = v1->group_id;
    if (ProductionGroupAccessor(v7)->next == ProductionGroupAccessor(v7))
	{
		_47C990_production.sidebar_open_mask[v7] = 0;
		script_trigger_event(0, EVT_MSG_1548_sidebar, 0, _47CA18_sidebar_production_buttons[v1->group_id]->task);
	}
	else if (v8)
	{
		_470490_sidebar_button_close_handlers[v7](0);
	}
}

//----- (004469D0) --------------------------------------------------------
void sidebar_button_handler_options_open(SidebarButton *a1)
{
	script_trigger_event(0, EVT_MSG_1530_OPEN_GAME_MENU, 0, task_47C028);
}

//----- (00446E70) --------------------------------------------------------
void sidebar_button_handler_minimap_open(SidebarButton *a1)
{
    show_minimap_sprite();
}

//----- (00446E80) --------------------------------------------------------
void sidebar_button_handler_minimap_close(SidebarButton *a1)
{
    hide_minimap_sprite();
}

//----- (00446ED0) --------------------------------------------------------
void script_446ED0_sidebar_buttons(Script *a1)
{
	SidebarButton **v1; // esi@1

	_44A6B0_minimap(render_width - 32, 32);
    script_sleep(a1, 2);
	v1 = _47CA18_sidebar_production_buttons;
	do
	{
		script_trigger_event(0, EVT_MSG_1548_sidebar, 0, (*v1)->task);
		++v1;
	} while ((int)v1 < (int) & _47CA2C_should_airstrike_mess_with_sidebar);
	script_trigger_event(0, EVT_MSG_1548_sidebar, 0, _47CA10_sidebar_button_minimap->task);
	script_trigger_event(0, EVT_MSG_1548_sidebar, 0, _47CA08_sidebar_buttons[1]->task);
	while (1)
	{
		if (_47CA00_render_string)
		{
			sprintf(asc_470198, a8d, game_globals_per_player.cash[player_side]);
			_47CA00_render_string->field_18 = 0;
			_47CA00_render_string->num_lines = 0;
			render_string_445770(_47CA00_render_string, asc_470198, 0);
		}
        script_sleep(a1, 1);
	}
}

//----- (00446FB0) --------------------------------------------------------
bool is_player_faction_evolved()
{
	if (_47C6D8_use__466098_cost_multipliers)
		return _47C658_faction_index;
	if (single_player_game)
	{
		if (player_side == EVOLVED)
			return true;                                 // mute
	}
	else if (netz_47A740[player_side + 1].field_A)
	{
		return true;                                   // mute
	}
	return false;                                     // surv
}

//----- (00447070) --------------------------------------------------------
void attempt_unlock_aircraft()
{
	unsigned int v0; // ecx@2
	int v1; // eax@4
	enum UNIT_ID v2; // edx@11

	if (_47CA2C_should_airstrike_mess_with_sidebar)
		return;
	v0 = levels[current_level_idx].disabled_units_mask;
	if (BYTE1(v0) & 0x20)
		return;
	_47CA2C_should_airstrike_mess_with_sidebar = 1;
	if (!_47C6D8_use__466098_cost_multipliers)
	{
		if (single_player_game)
		{
			if (player_side == 2)
			{
				v1 = 1;
				goto LABEL_11;
			}
		}
		else if (netz_47A740[player_side + 1].field_A)
		{
			v1 = 1;
			goto LABEL_11;
		}
		v1 = 0;
		goto LABEL_11;
	}
	v1 = _47C658_faction_index;
LABEL_11:
	v2 = (UNIT_ID)43;
	if (!v1)
		v2 = (UNIT_ID)44;
	production_group_enable(_47B3D4_aircraft_production_group, v2, 2236);
	script_trigger_event(0, EVT_MSG_1514, 0, _47CA18_sidebar_production_buttons[4]->task);
}

//----- (00447120) --------------------------------------------------------
void on_airstrike_ready()
{
	int is_evolved; // eax@3
	enum SOUND_ID v1; // ecx@11
	int v2; // [sp-Ch] [bp-Ch]@11

	if (!_47CA2C_should_airstrike_mess_with_sidebar)
		return;
	if (!_47C6D8_use__466098_cost_multipliers)
	{
		if (single_player_game)
		{
			if (player_side == 2)
			{
				is_evolved = 1;
				goto LABEL_10;
			}
		}
		else if (netz_47A740[player_side + 1].field_A)
		{
			is_evolved = 1;
			goto LABEL_10;
		}
		is_evolved = 0;
		goto LABEL_10;
	}
	is_evolved = _47C658_faction_index;
LABEL_10:
	if (is_evolved)
	{
		v2 = _4690A8_unit_sounds_volume;
		v1 = SOUND_MUTE_AIRSTRIKE_READY;
	}
	else
	{
		v1 = SOUND_SURV_AIRSTRIKE_READY;
		v2 = _4690A8_unit_sounds_volume;
	}
	sound_play(v1, 0, v2, 16, 0);
	if (_47CA2C_should_airstrike_mess_with_sidebar)
	{
		script_trigger_event(0, EVT_MSG_1514, 0, _47CA08_sidebar_buttons[1]->task);
		script_trigger_event(0, EVT_MSG_SELECTED, 0, _47C970_sidebar_task);
	}
	++UNIT_num_player_units;
}
// 468B5C: using guessed type int single_player_game;
// 47C658: using guessed type char _47C658_faction_index;
// 47CA2C: using guessed type int _47CA2C_should_airstrike_mess_with_sidebar;
// 47DCC8: using guessed type int UNIT_num_player_units;

//----- (004471E0) --------------------------------------------------------
void _4471E0_send_sidebar_buttons_message()
{
	int v0; // esi@1

	v0 = 0;
	do
	{
		if (v0 != -1)
			script_trigger_event(0, EVT_MSG_DESELECTED, 0, _47CA08_sidebar_buttons[v0]->task);
		++v0;
	} while (v0 < 2);
	script_trigger_event(0, EVT_MSG_DESELECTED, 0, _47C970_sidebar_task);
	script_trigger_event(0, EVT_MSG_DESELECTED, 0, _47CA08_sidebar_buttons[1]->task);
	if (UNIT_num_player_units > 0)
		--UNIT_num_player_units;
}
// 47DCC8: using guessed type int UNIT_num_player_units;

//----- (00447250) --------------------------------------------------------
void _447250_toggle_aircraft()
{
	int v0; // eax@3

	if (_47CA2C_should_airstrike_mess_with_sidebar)
	{
		if (_47C6D8_use__466098_cost_multipliers)
		{
			v0 = _47C658_faction_index;
		LABEL_10:
			_47CA2C_should_airstrike_mess_with_sidebar = 0;
			production_group_disable(_47B3D4_aircraft_production_group, (enum UNIT_ID)(UNIT_STATS_SURV_BOMBER - (v0 != 0)));
			script_trigger_event(0, EVT_MSG_1548_sidebar, 0, _47CA18_sidebar_production_buttons[4]->task);
			script_trigger_event(0, EVT_MSG_1548_sidebar, 0, _47CA08_sidebar_buttons[1]->task);
			script_trigger_event(0, EVT_MSG_1548_sidebar, 0, _47C970_sidebar_task);
			return;
		}
		if (single_player_game)
		{
			if (player_side == 2)
			{
				v0 = 1;
				goto LABEL_10;
			}
		}
		else if (netz_47A740[player_side + 1].field_A)
		{
			v0 = 1;
			goto LABEL_10;
		}
		v0 = 0;
		goto LABEL_10;
	}
}

//----- (00447310) --------------------------------------------------------
Sprite *_447310_minimap()
{
	return (_47CA10_sidebar_button_minimap->sprite->_inside_mobd_item != &currently_running_lvl_mobd[_47CA10_sidebar_button_minimap->sprite->mobd_id].items->_[165]) ? _47CA10_sidebar_button_minimap->sprite : 0;
}

//----- (00447340) --------------------------------------------------------
void _447340_send_sidebar_buttons_message(int excluding_button_id)
{
	for (int i = 0; i < 2; ++i)
	{
        auto v3 = _47CA08_sidebar_buttons[i];
		if (i != excluding_button_id)
			script_trigger_event(0, EVT_MSG_DESELECTED, 0, v3->task);
	}
}


//----- (004488F0) --------------------------------------------------------
int entity_4488F0_is_in_firing_range(Entity *a1, Entity *a2, int entity_id)
{
	Entity *v3; // ebx@1
	Entity *v4; // ebp@1
	Sprite *v5; // edi@4
	Sprite *v6; // eax@4
	int v7; // esi@4
	int v8; // ecx@4
	int v9; // eax@4
	int v10; // edi@6
	int v11; // esi@7
	int result; // eax@11

	v3 = a2;
	v4 = a1;
	if (!a2 || a2->entity_id != entity_id || a2->destroyed)
		goto LABEL_15;
	v5 = a1->sprite;
	v6 = a2->sprite;
	v7 = v6->x;
	v8 = v6->y;
	v9 = v5->y - v8;
	if (v9 <= 0)
		v9 = v8 - v5->y;
	v10 = v5->x;
	v11 = v10 - v7 <= 0 ? v7 - v10 : v10 - v7;
	if ((int)math_42D64D_vec_length_2d(v11 >> 8, v9 >> 8) <= v4->stats->firing_range && entity_41B510(v4, v3))
		result = 1;
	else
		LABEL_15:
	result = 0;
	return result;
}

//----- (00448980) --------------------------------------------------------
void tower_attachment_handler_448980(EntityTurret *a1)
{
	EntityTurret *v1; // esi@1

	v1 = a1;
	sprite_4272E0_load_mobd_item(
		a1->turret_sprite,
		a1->stats_attachment_point->mobd_lookup_offset_idle,
		_47D3C4_entity_mobd_lookup_ids[a1->mobd_lookup_id + 1]);
	v1->handler = tower_attachment_handler_4489B0;
}

//----- (004489B0) --------------------------------------------------------
void tower_attachment_handler_4489B0(EntityTurret *a1)
{
	EntityTurret *v1; // esi@1
	Entity *v2; // ecx@1
	Entity *v4; // eax@5
	int v5; // edx@5
	Entity *v6; // eax@8
	Entity *v7; // ecx@9
	Sprite *v8; // eax@9
	int v9; // ebx@9
	UnitAttachmentPoint *v10; // eax@11
	int v11; // eax@11
	UnitAttachmentPoint *v12; // ecx@12
	int src; // [sp+Ch] [bp-4h]@11

	v1 = a1;
	v2 = a1->entity;
	if ((v2->GetOrder() == ENTITY_ORDER_ATTACK || v2->GetOrder() == ENTITY_ORDER_8)
		&& entity_4488F0_is_in_firing_range(v2, v2->retaliation_target, v2->retaliation_target_id)
		&& sub_44CE40(v1->entity->player_side, v1->entity->retaliation_target))
	{
		v4 = v1->entity;
		v1->_C_entity = v4->retaliation_target;
		v5 = v4->retaliation_target_id;
		goto LABEL_9;
	}
	if (entity_4488F0_is_in_firing_range(v1->entity, v1->entity->_E4_prev_attack_target, v1->entity->_E4_prev_attack_target_entity_id)
		&& is_enemy(v1->entity->player_side, v1->entity->_E4_prev_attack_target))
	{
		v6 = v1->entity;
		v1->_C_entity = v6->_E4_prev_attack_target;
		v5 = v6->_E4_prev_attack_target_entity_id;
	LABEL_9:
		v7 = v1->_C_entity;
		v8 = v1->turret_sprite;
		v1->_C_entity_idx = v5;
		v1->SetHandler(tower_attachment_handler_448B40);
		v9 = (signed __int16)_42D560_get_mobd_lookup_id_rotation(v7->sprite->x - v8->x, v7->sprite->y - v8->y);
        mobd_advance_anim(&v1->mobd_lookup_id, v9, v1->stats_attachment_point->mobd_frame_step);
		sprite_4272E0_load_mobd_item(
			v1->turret_sprite,
			v1->stats_attachment_point->mobd_lookup_offset_idle,
			_47D3C4_entity_mobd_lookup_ids[v1->mobd_lookup_id + 1]);
		if (v1->mobd_lookup_id == v9)
		{
			_42D560_get_mobd_lookup_id_rotation(
				v1->_C_entity->sprite->x - v1->turret_sprite->x,
				v1->_C_entity->sprite->y - v1->turret_sprite->y);
			sprite_4272E0_load_mobd_item(
				v1->turret_sprite,
				v1->stats_attachment_point->mobd_lookup_offset_attack,
				_47D3C4_entity_mobd_lookup_ids[v1->mobd_lookup_id + 1]);
			v1->SetHandler(tower_attachment_handler_448C40);
		}
		return;
	}
	v10 = v1->stats_attachment_point;
	src = v1->mobd_lookup_id;
	mobd_advance_anim(&src, v1->entity->GetCurrentAnimFrame(), v10->mobd_frame_step);
	v11 = src;
	if (src != v1->mobd_lookup_id)
	{
		v12 = v1->stats_attachment_point;
		v1->mobd_lookup_id = src;
		sprite_4273B0_load_mobd_item_sound(
			v1->turret_sprite,
			v12->mobd_lookup_offset_idle,
			_47D3C4_entity_mobd_lookup_ids[v11 + 1]);
	}
}

//----- (00448B40) --------------------------------------------------------
void tower_attachment_handler_448B40(EntityTurret *a1)
{
	EntityTurret *v1; // esi@1
	Entity *v2; // ecx@1
	Sprite *v3; // eax@1
	int v4; // ebx@1

	v1 = a1;
	v2 = a1->_C_entity;
	v3 = v1->turret_sprite;
	v1->SetHandler(tower_attachment_handler_448B40);
	v4 = (signed __int16)_42D560_get_mobd_lookup_id_rotation(v2->sprite->x - v3->x, v2->sprite->y - v3->y);
	mobd_advance_anim(&v1->mobd_lookup_id, v4, v1->stats_attachment_point->mobd_frame_step);
	sprite_4272E0_load_mobd_item(
		v1->turret_sprite,
		v1->stats_attachment_point->mobd_lookup_offset_idle,
		_47D3C4_entity_mobd_lookup_ids[v1->mobd_lookup_id + 1]);
	if (v1->mobd_lookup_id == v4)
	{
		_42D560_get_mobd_lookup_id_rotation(
			v1->_C_entity->sprite->x - v1->turret_sprite->x,
			v1->_C_entity->sprite->y - v1->turret_sprite->y);
		sprite_4272E0_load_mobd_item(
			v1->turret_sprite,
			v1->stats_attachment_point->mobd_lookup_offset_attack,
			_47D3C4_entity_mobd_lookup_ids[v1->mobd_lookup_id + 1]);
		v1->SetHandler(tower_attachment_handler_448C40);
	}
}

//----- (00448BF0) --------------------------------------------------------
void tower_attachment_handler_448BF0(EntityTurret *a1)
{
	EntityTurret *v1; // esi@1

	v1 = a1;
	_42D560_get_mobd_lookup_id_rotation(
		a1->_C_entity->sprite->x - a1->turret_sprite->x,
		a1->_C_entity->sprite->y - a1->turret_sprite->y);
	sprite_4272E0_load_mobd_item(
		v1->turret_sprite,
		v1->stats_attachment_point->mobd_lookup_offset_attack,
		_47D3C4_entity_mobd_lookup_ids[v1->mobd_lookup_id + 1]);
	v1->handler = tower_attachment_handler_448C40;
}

//----- (00448C40) --------------------------------------------------------
void tower_attachment_handler_448C40(EntityTurret *a1)
{
	EntityTurret *v1; // esi@1
	__int16 v2; // ax@5
	Sprite *v3; // ecx@5
	UnitDamageSource *v4; // edi@5
	Sprite *v5; // eax@8
	int v6; // edx@8
	Sprite *v7; // ebx@8
	Script *v8; // eax@10
	int v9; // edx@10
	UnitAttachmentPoint *v10; // eax@10
	int v11; // ecx@10
	Entity *v12; // ecx@12
	int v13; // eax@12
	Entity *v14; // edx@14
	Entity *v15; // eax@16

	v1 = a1;
	if (entity_4488F0_is_in_firing_range(a1->entity, a1->_C_entity, a1->_C_entity_idx))
	{
		if (sub_44CE40(v1->entity->player_side, v1->_C_entity))
		{
			v2 = _42D560_get_mobd_lookup_id_rotation(
				v1->_C_entity->sprite->x - v1->turret_sprite->x,
				v1->_C_entity->sprite->y - v1->turret_sprite->y);
			v3 = v1->turret_sprite;
			v1->mobd_lookup_id = v2;
			sprite_4273B0_load_mobd_item_sound(
				v3,
				v1->stats_attachment_point->mobd_lookup_offset_attack,
				_47D3C4_entity_mobd_lookup_ids[v2 + 1]);
			v4 = v1->stats_attachment_point->dmg_source;
			if (v4 && _47C048_num_attack_projectile_sprites < 200 && !v1->field_18)
			{
				++_47C048_num_attack_projectile_sprites;
				v5 = sprite_create_scripted(v4->mobd_id, v1->turret_sprite, v4->dmg_handler, SCRIPT_COROUTINE, v1->ptr_24);
				v6 = v4->mobd_lookup_offset_flying;
				v7 = v5;
				if (v6 != -1)
					sprite_4272E0_load_mobd_item(v5, v6, _47D3C4_entity_mobd_lookup_ids[v1->mobd_lookup_id + 1]);
				v8 = v7->script;
				v9 = v1->turret_sprite->z_index;
				v7->param = v4;
				v7->z_index = v9 + 768;
				v8->param = v1->_C_entity;
				v7->_80_entity__stru29__sprite__initial_hitpoints = v1->entity;
				v7->field_84 = v1->entity->entity_id;
				v7->field_8C_infantry_damage = LOWORD_HEXRAYS(v4->damage_infantry)
					+ (v4->damage_infantry * veterancy_damage_bonus[v1->entity->veterancy_level] >> 8);
				v7->field_8E_vehicle_damage = LOWORD_HEXRAYS(v4->damage_vehicle)
					+ (v4->damage_vehicle
						* veterancy_damage_bonus[v1->entity->veterancy_level] >> 8);
				v7->field_90_building_damage = LOWORD_HEXRAYS(v4->damage_building)
					+ (v4->damage_building
						* veterancy_damage_bonus[v1->entity->veterancy_level] >> 8);
				v7->parent = v1->turret_sprite->parent;
				script_trigger_event(v1->entity->script, MSG_ATTACKED, v1->entity, v1->_C_entity->script);
				v10 = v1->stats_attachment_point;
				v1->field_18 = v10->reload_time;
				v11 = v1->field_1C - 1;
				v1->field_1C = v11;
				if (!v11)
				{
					v1->field_18 += v10->reload2_time;
					v1->field_1C = v10->volley_size;
				}
			}
			v12 = v1->entity;
			v13 = v12->_DC_order;
			if (v13 == 2 || v13 == 8)
			{
				v14 = v12->retaliation_target;
				if (v1->_C_entity != v14)
				{
					if (entity_4488F0_is_in_firing_range(v12, v14, v12->retaliation_target_id))
					{
						v15 = v1->entity;
						v1->_C_entity = v15->retaliation_target;
						v1->_C_entity_idx = v15->retaliation_target_id;
						v1->handler = tower_attachment_handler_448B40;
					}
				}
			}
		}
		else
		{
			sprite_4272E0_load_mobd_item(
				v1->turret_sprite,
				v1->stats_attachment_point->mobd_lookup_offset_idle,
				_47D3C4_entity_mobd_lookup_ids[v1->mobd_lookup_id + 1]);
			v1->handler = tower_attachment_handler_4489B0;
		}
	}
	else
	{
		sprite_4272E0_load_mobd_item(
			v1->turret_sprite,
			v1->stats_attachment_point->mobd_lookup_offset_idle,
			_47D3C4_entity_mobd_lookup_ids[v1->mobd_lookup_id + 1]);
		v1->handler = tower_attachment_handler_4489B0;
	}
}
// 47C048: using guessed type int _47C048_num_attack_projectile_sprites;

//----- (00448E90) --------------------------------------------------------
void tower_attachment_handler_448E90(EntityTurret *a1)
{
	EntityTurret *v1; // esi@1

	v1 = a1;
	sprite_list_remove(a1->turret_sprite);
	script_terminate(v1->sprite_task);
	script_free_local_object(v1->entity->script, v1);
}

//----- (00448EC0) --------------------------------------------------------
void MessageHandler_448EC0(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param)
{
	int v4; // esi@1

	v4 = (int)receiver->param;
	if (event == EVT_MSG_MISSION_FAILED)
	{
		sprite_list_remove(*(Sprite **)(v4 + 4));
		script_terminate(*(Script **)v4);
		script_free_local_object(*(Script **)(*(_DWORD *)(v4 + 8) + 12), (void *)v4);
	}
}

//----- (00448EF0) --------------------------------------------------------
void MessageHandler_task4_evt39030(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param)
{
	_47CAF0_task_attachment1 *v4; // ecx@1
	_47CAF0_task_attachment1 *v5; // eax@2

	v4 = (_47CAF0_task_attachment1 *)receiver->param;
	if (event == EVT_MSG_DESELECTED)
	{
		v5 = v4->next;
		if (v4->next != v4)
		{
			while (v5->_8_script != sender)
			{
				v5 = v5->next;
				if (v5 == v4)
					return;
			}
			v5->next->prev = v5->prev;
			v5->prev->next = v5->next;
			v5->next = (_47CAF0_task_attachment1 *)v4->attach2_list_free_pool;
			v4->attach2_list_free_pool = (_47CAF0_task_attachment2 *)v5;
		}
	}
}

//----- (00449670) --------------------------------------------------------
bool UNIT_InitTasks()
{
	char *v0; // edi@1
	int v1; // eax@1
	int v2; // edi@1
	//char *v3; // ebp@1
	Script *v4; // eax@6
	_47CAF0_task_attachment1 *v5; // esi@6
	_47CAF0_task_attachment2 *v6; // eax@7
	int v7; // eax@9
	int *v9; // [sp+10h] [bp-8h]@1
	int v10; // [sp+14h] [bp-4h]@1

	memset(_47CA80_array, 0, 0x58u);
	v0 = (char *) & _47CA80_array[6].field_8 + 2;
	*(_WORD *)v0 = 0;
	v0[2] = 0;
	v10 = get_current_level_starting_cash();
	v1 = single_player_game;
	v2 = 0;
	v9 = dword_470510;
	//v3 = &netz_47A740[2].field_8;
    int v3 = 1;
	do
	{
		if (v1 == 0 && netz_47A740[v3].field_8 != 0 || v1 && v2 == player_side)
		{
			v4 = script_create_function(SCRIPT_TYPE_39030, script_evt39030_handler);
			_47CAF0_tasks_evt39030[v2] = v4;
			v4->field_1C = 1;
			_47CAF0_tasks_evt39030[v2]->event_handler = MessageHandler_task4_evt39030;
			v5 = (_47CAF0_task_attachment1 *)script_create_local_object(_47CAF0_tasks_evt39030[v2], 52);
			if (!v5)
				return 0;
			v6 = (_47CAF0_task_attachment2 *)script_create_local_object(_47CAF0_tasks_evt39030[v2], 1200);
			v5->attach2_list = v6;
			if (!v6)
				script_terminate(_47CAF0_tasks_evt39030[v2]);
			v7 = 0;
			v5->attach2_list_free_pool = v5->attach2_list;
			do
			{
				v5->attach2_list[v7].next = &v5->attach2_list[v7 + 1];
				++v7;
			} while (v7 < 99);
			v5->attach2_list[99].next = 0;
			v5->next = v5;
			v5->prev = v5;
			v5->selected_unit_player_side = (PLAYER_SIDE)v2;
			v5->attack_task.player_side = v2;
			v5->move_task.player_side = v2;
			v5->_1C_does_selected_unit_belong_to_player = false;
			v5->owning_task = _47CAF0_tasks_evt39030[v2];
			_47CAF0_tasks_evt39030[v2]->param = v5;
			game_globals_per_player.cash[v2] = v10;
			v1 = single_player_game;
			*v9 = 0;
		}
		else
		{
			_47CAF0_tasks_evt39030[v2] = 0;
		}
		//v3 += 28;
        v3++;
		++v2;
		++v9;
    }//while ((int)v3 < (int)&netz_47A844);
    while (v3 < 8);
	if (v1)
	{
		dword_47A830 = 1;
	}
	else
	{
        auto cr = script_create_coroutine(SCRIPT_TYPE_INVALID, script_449820_netz, 0);
		cr->field_1C = 1;
	}
    return true;
}

//----- (00449800) --------------------------------------------------------
void __47CAF0_tasks_evt39030_array_free()
{
	Script **v0; // esi@1

	v0 = _47CAF0_tasks_evt39030;
	do
	{
		if (*v0)
			script_deinit(*v0);
		++v0;
	} while ((int)v0 < (int)&dword_47CB0C);
}
// 47CB0C: using guessed type int dword_47CB0C;

//----- (0044BE60) --------------------------------------------------------
void script_44BE60_explosions(Script *a1)
{
	Sprite *v1; // esi@1
	DrawJob *v2; // edx@3
	int v3; // [sp+Ch] [bp-24h]@1
	int v4; // [sp+10h] [bp-20h]@1
	int v5; // [sp+14h] [bp-1Ch]@1
	int v6; // [sp+18h] [bp-18h]@1
	int v7; // [sp+1Ch] [bp-14h]@1
	int v8; // [sp+20h] [bp-10h]@1
	int v9; // [sp+24h] [bp-Ch]@1
	int v10; // [sp+28h] [bp-8h]@1
	int v11; // [sp+2Ch] [bp-4h]@1

	v1 = a1->sprite;
	v3 = 0;
	v4 = 0;
	v5 = 0;
	v6 = 0;
	v7 = 0;
	v8 = 0;
	v9 = 0;
	v10 = 0;
	v11 = 0;
	if (!v1->param)
		v1->param = &v3;
	sprite_408800_play_sound(v1, SOUND_3, _4690A8_unit_sounds_volume, 0);
	v2 = v1->drawjob;
	v1->z_index = 0;
	v2->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_4484A0_explosions;
	sprite_load_mobd(v1, 144);
	script_yield(a1, SCRIPT_FLAGS_20_10000000, 0);
	decrease_num_explosions();
	sprite_list_remove(a1->sprite);
	script_terminate(a1);
}

//----- (0044BF00) --------------------------------------------------------
void EntityTurret_44BF00_handler(EntityTurret *a1)
{
	EntityTurret *v1; // esi@1
	int *v2; // edi@1
	UnitAttachmentPoint *v3; // eax@1
	Entity *v4; // edx@1

	v1 = a1;
	v2 = &a1->mobd_lookup_id;
	sprite_4272E0_load_mobd_item(
		a1->turret_sprite,
		a1->stats_attachment_point->mobd_lookup_offset_idle,
		_47D3C4_entity_mobd_lookup_ids[a1->mobd_lookup_id + 1]);
	v3 = v1->stats_attachment_point;
	v4 = v1->entity;
	v1->SetHandler(EntityTurret_44BF70);
	mobd_advance_anim(v2, v4->GetCurrentAnimFrame(), v3->mobd_frame_step);
	sprite_4273B0_load_mobd_item_sound(
		v1->turret_sprite,
		v1->stats_attachment_point->mobd_lookup_offset_idle,
		_47D3C4_entity_mobd_lookup_ids[*v2 + 1]
    );
    script_yield_any_trigger(v1->sprite_task, 2);
}

//----- (0044BF70) --------------------------------------------------------
void EntityTurret_44BF70(EntityTurret *a1)
{
	EntityTurret *v1; // esi@1
	char *v2; // edi@1

	v1 = a1;
	v2 = (char *)&a1->mobd_lookup_id;
	mobd_advance_anim(
		&a1->mobd_lookup_id,
		a1->entity->GetCurrentAnimFrame(),
		a1->stats_attachment_point->mobd_frame_step
    );
	sprite_4273B0_load_mobd_item_sound(
		v1->turret_sprite,
		v1->stats_attachment_point->mobd_lookup_offset_idle,
		_47D3C4_entity_mobd_lookup_ids[*(_DWORD *)v2 + 1]
    );
    script_yield_any_trigger(v1->sprite_task, 2);
}

//----- (0044BFC0) --------------------------------------------------------
void sub_44BFC0(int a1)
{
	int v1; // esi@1

	v1 = a1;
	*(_DWORD *)(*(_DWORD *)(a1 + 4) + 124) = 0;
	sprite_list_remove(*(Sprite **)(a1 + 4));
	script_terminate(*(Script **)v1);
	script_free_local_object(*(Script **)(*(_DWORD *)(v1 + 8) + 12), (void *)v1);
}

//----- (0044BFF0) --------------------------------------------------------
void MessageHandler_EntityScript(Script *receiver, Script *sender, enum SCRIPT_EVENT event, void *param)
{
	int v4; // ecx@1

	v4 = (int)receiver->param;
	if (event == EVT_MSG_1500)
		*(_DWORD *)(v4 + 16) = (int)sub_44BFC0;
}

//----- (0044C010) --------------------------------------------------------
bool _44C010_init_mission_globals()
{
	int v0; // eax@1
	int v1; // ecx@1
	int player_idx; // ebx@3
	stru12_game_globals *v4; // eax@3
	int v5; // ebp@3
	int v6; // ecx@5
	int v7; // eax@8
	int v8; // esi@12
	char *v9; // ecx@13
	char *v10; // edx@13
	unsigned int v11; // eax@13
	unsigned __int8 *v12; // edi@17
	int v13; // ecx@18
	unsigned __int8 *v14; // esi@18
	int v15; // ecx@23
	int *v16; // eax@23
	int v17; // edx@24
	char *v18; // ecx@26
	int *v19; // eax@26
	stru12_game_globals *i; // [sp+10h] [bp-4h]@3

	v0 = 4;
	v1 = 0;
	do
	{
		++v1;
		_47D3C4_entity_mobd_lookup_ids[v1] = ((v0 + 4) / 16) & 0xF;
		__47CFC4_mobd_lookup_speeds[v1] = (v0 / 8) & 0x1F;
        v0++;
	} while (v0 - 4 < 256);
	player_idx = 0;
	memset(game_globals_cpu, 0, sizeof(game_globals_cpu));
	v4 = game_globals_cpu;
	v5 = 0;
	for (i = game_globals_cpu; ; v4 = i)
	{
		v6 = single_player_game;
		v4->cash[0] = 1;
		if (v6)
		{
			v7 = v4 != game_globals_cpu && player_idx != player_side;
			dword_470510[player_idx] = v7;
			if ((int)current_level_idx >= 48 && (int)current_level_idx <= 67)
			{
				v8 = player_idx + 2;
				if (player_idx + 2 < 7)
				{
					v9 = (char *)game_globals_cpu + 4 * (v5 + v8);
					v10 = (char *)&game_globals_cpu[2] + 4 * (player_idx + v5);
					v11 = (unsigned int)(8 - v8) >> 1;
					do
					{
						*(_DWORD *)v9 = 1;
						*(_DWORD *)v10 = 1;
						v9 += 8;
						v10 += 56;
						--v11;
					} while (v11);
				}
			}
		}
		else
		{
			dword_470510[player_idx] = 0;
		}
		v12 = (unsigned __int8 *)malloc(0x200u);
		per_player_sprite_palettes[player_idx] = v12;
		if (!v12)
			return 0;
		v13 = 0;
		v14 = player_sprite_palette_tmp;
		do
			*v14++ = 16 * player_idx + v13++;
		while (v13 < 16);
		for (; v13 < 256; ++v13)
			*v14++ = v13;
		copy_player_sprite_palette_aligned(player_sprite_palette_tmp, v12);
		++player_idx;
		v5 += 7;
		i = (stru12_game_globals *)((char *)i + 32);
		if (player_idx >= 7)
			break;
	}

	v15 = 1;
	v16 = &player_sprite_color_by_player_side[1];
	do
	{
		v17 = v15++ - 1;
		*v16 = v17;
		++v16;
	} while ((int)v16 < (int) & _47DCC4_entity_id_counter);
	player_sprite_color_by_player_side[0] = 3;
	if (!single_player_game)
	{
		v18 = &netz_47A740[2].field_9;
		v19 = &player_sprite_color_by_player_side[1];
		do
		{
			if (*(v18 - 1))
				*v19 = *v18;
			++v19;
			v18 += 28;
		} while ((int)v19 < (int) & _47DCC4_entity_id_counter);
	}
	_408550_multi_pal();
	return 1;
}

//----- (0044C1D0) --------------------------------------------------------
void per_player_sprite_palettes_47DC88_free()
{
    for (int i = 0; i < 7; ++i) {
        if (per_player_sprite_palettes[i]) {
            free(per_player_sprite_palettes[i]);
            per_player_sprite_palettes[i] = nullptr;
        }
    }
}

//----- (0044C1F0) --------------------------------------------------------
int UNIT_Init()
{
	int v1; // ecx@2
	stru11unit *v2; // eax@4
	int v3; // ecx@5
	UnitAttachmentPoint *v4; // ecx@7
	void (*v5)(Script *); // eax@8
	int v6; // edx@9
	int v7; // esi@9
	enum MOBD_ID v8; // eax@10
	int v9; // esi@11
	int v10; // eax@14
	int result; // eax@20

	_47DCC4_entity_id_counter = 0;
	_47C048_num_attack_projectile_sprites = 0;
	_4269B0_task_attachment__4_some_task_flags = 0;
	UNIT_num_player_units = 0;
	UNIT_num_nonplayer_units = 0;
	num_players_towers = 0;
	_47C04C_num_explosions_max20 = 0;
	_47A3D4_tanker_convoy_units_left = 0;
	_47A3D8_num_convoy_tankers_still_to_arrive = 0;
	_4269B0_task_attachment__num_units_spawned = 0;
	_4269B0_task_attachment__num_units_created_manually = 0;
	_430F10_unit_inits();

	v1 = 0;
	v2 = (stru11unit *)malloc(0x1770u);
	stru11unit_list = v2;
	if (!v2)
		return 0;
	stru11unit_list_head = v2;
	v3 = 0;
	do
	{
		v2[v3].next = &v2[v3 + 1];
		v2 = stru11unit_list;
		++v3;
	} while (v3 < 499);
	stru11unit_list[499].next = 0;
	stru11unit_list_47DC70 = (stru11unit *)&stru11unit_list_47DC70;
	stru11unit_list_47DC74 = (stru11unit *)&stru11unit_list_47DC70;
	dword_47DCE8 = 1;
	pscript_show_message_ex = script_create_coroutine(SCRIPT_TYPE_INVALID, script_show_message_ex, 0);
	pscript_show_message = script_create_coroutine(SCRIPT_TYPE_INVALID, script_show_message, 0);
	j_drawjob_update_handler_426C40_default_sprite_handler = drawjob_update_handler_44C430_default_sprite;
	v4 = (UnitAttachmentPoint *)&unit_stats[0].attach;
	do
	{
		v5 = v4->mode_attach;
		if (v5)
		{
			v6 = *((_DWORD *)v5 + 7) + *((_DWORD *)v5 + 5);
			v7 = v4[-2].field_24;                     // v7 = unit_stats[i].reload_time
		}
		else
		{
			v8 = v4->mobd_id;
			if (v4->mobd_id == MOBD_MUTE_ALCHEMY_HALL)
				goto LABEL_18;
			v9 = *(_DWORD *)(v8 + 32);
			if (!v9)
				goto LABEL_18;
			v6 = *(_DWORD *)(v9 + 20) + *(_DWORD *)(v9 + 28);
			v7 = (*(_DWORD *)(v8 + 16) + *(_DWORD *)(v8 + 12)) >> 1;
		}
		if (!v7)
			goto LABEL_18;
		v10 = v6 * (v4[-1].reload_time - 40) * v4[-2].mobd_lookup_offset_attack / v7 >> 8;
		v4->reload2_time = v10;
		if (v10 < 1)
			v4->reload2_time = 1;
		if ((int)v4 >= (int)&unit_stats[74].attach && v4->reload2_time > 0)
			LABEL_18:
		v4->reload2_time = 0;
		v4 = (UnitAttachmentPoint *)((char *)v4 + 100);
	} while ((int)v4 <= (int)&unit_stats[78].attach);
	game_cursor_script = 0;
	_438B40_reset_explosions();
	entity_scout = 0;
	dword_47A3DC = 0;
	result = UNIT_InitTasks();
	if (result)
	{
		result = UNIT_InitAiPlayers();
		if (result)
		{
			result = building_limits_list_alloc();
			if (result)
			{
				result = oilspot_list_alloc();
				if (result)
				{
					result = stru26_array_initialize();
					if (result)
					{
						result = stru27_array_initialize();
						if (result)
						{
							result = stru28_list_alloc();
							if (result)
							{
								if (!stru13construct_list_alloc())
									return 0;
								result = mapd_init_fog_of_war() != 0;
							}
						}
					}
				}
			}
		}
	}
	return result;
}

//----- (0044C4B0) --------------------------------------------------------
void _44C4B0_mess_with_turrets()
{
	Entity_stru60 *v1; // ebx@5
	DataMobdItem_stru0 *v2; // ecx@5
	DataMobdItem_stru1 *v3; // esi@6
	int j; // ecx@7
	EntityTurret *v5; // ecx@12
	DataMobdItem_stru0 *v6; // esi@13
	Entity_stru_dmg_related *v7; // esi@14

	if (dword_47DCE8)
	{
		if (!is_async_execution_supported)
			++_4269B0_task_attachment__4_some_task_flags;

        for (auto i: entityRepo->FindAll())
		{
			v1 = &i->stru60;
			memset32(&i->stru60, (int)&entity_default_stru60_ptr, 6u);
			v2 = i->sprite->_54_inside_mobd_ptr4;
			if (v2)
			{
				v3 = v2->field_18;
				if (v3)
				{
					for (j = v3->field_0; j != -1; v3 = (DataMobdItem_stru1 *)((char *)v3 + 16))
					{
						if (j < 6)
							*((_DWORD *)&i->stru60.ptr_0 + j) = (int)v3;
						j = v3->field_10;
					}
				}
			}
			if (!i->destroyed)
			{
				v5 = i->turret;
				if (v5)
				{
					v6 = v5->turret_sprite->_54_inside_mobd_ptr4;
					if (v6 && (v7 = (Entity_stru_dmg_related *)v6->field_18) != 0)
						v5->ptr_24 = v7;
					else
						v5->ptr_24 = (Entity_stru_dmg_related *)&entity_default_stru60_ptr;
					i->turret->turret_sprite->field_88_unused = 1;
					i->sprite->field_88_unused = 1;
					i->turret->turret_sprite->x = i->sprite->x + v1->ptr_0->x_offset;
					i->turret->turret_sprite->field_88_unused = 1;
					i->turret->turret_sprite->y = i->sprite->y + v1->ptr_0->y_offset;
				}
			}
		}
		mapd_44AE30_fog_of_war();
	}
}

//----- (0044C5C0) --------------------------------------------------------
void _44C5C0_level_cleanup()
{
	Entity *i; // eax@1
	enum PLAYER_SIDE v1; // ecx@2
	DrawJob *v2; // ecx@8

	stru13_list_free();
	minimap_free();
	stru28_list_free();
	stru26_stru27_free();
	oilspot_list_free();
	building_limits_list_free();
	UNIT_FreeAiPlayers();
	__47CAF0_tasks_evt39030_array_free();
	free(stru11unit_list);
    entityRepo->DeleteAll();
	dword_47DCE8 = 0;
}

//----- (00438990) --------------------------------------------------------
void stru28_list_free()
{
    free(stru28_list);
}

//----- (0044C910) --------------------------------------------------------
Sprite *spawn_unit(enum UNIT_ID unit_id, int x, int y, enum PLAYER_SIDE player_side)
{
	enum UNIT_ID v4; // esi@1
	int v5; // edi@1
	Sprite *result; // eax@1

	v4 = unit_id;
	v5 = x;
	result = sprite_create_scripted(
		unit_stats[unit_id].mobd_idx,
		0,
		unit_stats[unit_id].script_handler,
		SCRIPT_FUNCTION,
		0);
	if (result)
	{
		result->x = v5;
		result->field_88_unused = 1;
		result->y = y;
		result->cplc_ptr1 = 0;
		result->param = (void *)(v4 | (player_side << 16));
	}
	return result;
}

//----- (0044C970) --------------------------------------------------------
void entity_drag_selection_init(int y, int x, int z, int w)
{
	entity_drag_selection_y = y;
	entity_drag_selection_x = x;
	entity_drag_selection_list = entityRepo->FindAll();
	entity_drag_selection_z = z;
	entity_drag_selection_w = w;
}

//----- (0044C9A0) --------------------------------------------------------
Script *entity_drag_selection_get_next_entity()
{
    while (true)
    {
        auto it = entity_drag_selection_list.begin();
        if (it != entity_drag_selection_list.end())
        {
            auto entity = *it;
            entity_drag_selection_list.pop_front();

            if (!entity->destroyed)
            {
                auto v1 = entity->sprite;
                if (!entity->IsMode(entity_mode_418D20)
                    && !entity->IsMode(entity_mode_418B30)
                    && v1->x > entity_drag_selection_x
                    && v1->x <= entity_drag_selection_z
                    && v1->y > entity_drag_selection_y
                    && v1->y <= entity_drag_selection_w)
                {
                    return entity->script;
                }
            }
        }
        else
        {
            return nullptr;
        }
    }
}

//----- (0044CA50) --------------------------------------------------------
bool sub_44CA50(enum UNIT_ID id)
{
	return unit_stats[id].player_side == 1;
}

//----- (0044CA70) --------------------------------------------------------
Entity *entity_44CA70_find(Entity *a1, enum UNIT_ID a2, int player_side)
{
	int v4; // edx@1
	Sprite *v5; // eax@4
	Sprite *v6; // ebx@5
	int v7; // esi@5
	int v8; // esi@6
	int v9; // eax@8
	int v10; // ebx@8
	int v11; // ebx@9
	Entity *i; // [sp+0h] [bp-Ch]@1
	enum UNIT_ID v14; // [sp+4h] [bp-8h]@1
	Entity *v15; // [sp+8h] [bp-4h]@1

	v15 = a1;
	v14 = a2;
	v4 = 0x7FFFFFFF;
    i = 0;
	for (auto v3: entityRepo->FindAll())
	{
		if (v3->unit_id == v14 && v3->player_side == player_side)
		{
			v5 = v3->sprite;
			if (v5)
			{
				v6 = v15->sprite;
				v7 = v6->x;
				if (v5->x - v7 <= 0)
					v8 = v7 - v5->x;
				else
					v8 = v5->x - v7;
				v9 = v5->y;
				v10 = v6->y;
				if (v9 - v10 <= 0)
					v11 = v10 - v9;
				else
					v11 = v9 - v10;
				if (v11 + v8 < v4)
				{
					i = v3;
					v4 = v11 + v8;
				}
			}
		}
	}
	return i;
}

//----- (0044CB10) --------------------------------------------------------
bool show_message_ex(Entity *a1, const char *text)
{
    return script_trigger_event(
        a1 ? a1->script : nullptr,
        EVT_MSG_DESELECTED,
        (void *)text,
        pscript_show_message_ex
    );
}

//----- (0044CB40) --------------------------------------------------------
bool show_message(const char *text)
{
	return script_trigger_event(0, EVT_MSG_DESELECTED, (void *)text, pscript_show_message);
}

//----- (0044CB60) --------------------------------------------------------
int mobd_advance_anim(int *src_lookup_id, int dst, int step)
{
	int v3; // esi@1
	int result; // eax@2

	v3 = *src_lookup_id;
	if (dst == *src_lookup_id)
	{
		result = 0;
	}
	else if (v3 <= dst)
	{
		result = dst - v3;
		if (dst - v3 >= 128)
		{
			if (result <= 256 - step)
			{
				*src_lookup_id = (unsigned __int8)(v3 - step);
				result = 256 - result;
			}
			else
			{
				*src_lookup_id = dst;
				result = 256 - result;
			}
		}
		else if (result >= step)
		{
			*src_lookup_id = (unsigned __int8)(v3 + step);
		}
		else
		{
			*src_lookup_id = dst;
		}
	}
	else
	{
		result = v3 - dst;
		if (v3 - dst >= 128)
		{
			if (result <= 256 - step)
			{
				*src_lookup_id = (unsigned __int8)(v3 + step);
				result = 256 - result;
			}
			else
			{
				*src_lookup_id = dst;
				result = 256 - result;
			}
		}
		else if (result >= step)
		{
			*src_lookup_id = (unsigned __int8)(v3 - step);
		}
		else
		{
			*src_lookup_id = dst;
		}
	}
	return result;
}

//----- (0044CC40) --------------------------------------------------------
void script_show_message_ex(Script *a1)
{
	int v1; // ebx@1
	const char *text; // edi@2
	Script *v3; // esi@3
	ScriptEvent *i; // eax@5
	enum SCRIPT_EVENT v5; // ecx@6
	Script *sender; // ecx@8
	int v7; // esi@14
	int v8; // ebx@14
	unsigned int v9; // esi@14
	unsigned int v10; // ebx@14
	int v11; // ebp@23
	int v12; // eax@23
	RenderString *v13; // esi@23
	Sprite *sender_sprite = 0; // [sp+10h] [bp-4h]@0

	v1 = 0;
	while (1)
	{
		text = 0;
		if (v1)
		{
			v3 = a1;
		}
		else
		{
			v3 = a1;
            script_wait_event(a1);
		}
		v1 = 0;
		for (i = script_get_next_event(v3); i; i = script_get_next_event(v3))
		{
			v5 = i->event;
			if (v5 != EVT_MSG_SELECTED && v5 == EVT_MSG_DESELECTED)
			{
				sender = i->sender;
				text = (const char *)i->param;
				if (sender)
					sender_sprite = sender->sprite;
				else
					sender_sprite = 0;
			}
			script_discard_event(i);
		}
		if (text)
		{
			if (sender_sprite)
			{
				v7 = sender_sprite->x;
				v8 = sender_sprite->y;
				sender_sprite->field_88_unused = 1;
				v9 = (v7 - _47C380_mapd.mapd_cplc_render_x) >> 8;
				v10 = (v8 - _47C380_mapd.mapd_cplc_render_y) >> 8;
				if (v9 < 0x80)
					v9 = 128;
				if (v9 > render_width - 128)
					v9 = render_width - 128;
				if (v10 < 0x20)
					v10 = 32;
				if (v10 > render_height - 32)
					v10 = render_height - 32;
			}
			else
			{
				v9 = (unsigned int)render_width >> 1;
				v10 = (unsigned int)render_height >> 1;
			}
			v11 = _445C00_text(text, 128);
			v12 = _445C80_text(text, 128);
			v13 = render_string_create(
				0,
				currently_running_lvl_mobd[MOBD_FONT_27].items,
				v9 - (8 * (v12 + 2) >> 1),
				v10 - 32,
				v12 + 2,
				v11 + 2,
				0x20000005,
				8,
				8);
			render_string_445770(v13, text, 0);
			v1 = script_yield_any_trigger(a1, 4 * strlen(text)) & SCRIPT_FLAGS_20_EVENT_TRIGGER;
			render_string_list_remove(v13);
		}
	}
}

//----- (0044CDC0) --------------------------------------------------------
bool _44CDC0_sidebar_is_units_limit()
{
	int v0; // eax@2

	if (single_player_game)
		v0 = 549 / (_4778C8_singleplayer_available_units_denom + 1);
	else
		v0 = 549 / netz_468B50_available_units_denom;
	return UNIT_num_player_units > v0;
}

//----- (0044CE00) --------------------------------------------------------
bool is_enemy(PLAYER_SIDE player_side, Entity *entity)
{
    switch (entity->unit_id)
    {
        case UNIT_STATS_TECH_BUNKER:
            return false;

        case UNIT_STATS_HUT:
            return true;

        default:
            if (entity->player_side == PLAYER_SIDE_UNSPECIFIED)
                return false;

            return !game_globals_cpu[player_side].cash[entity->player_side];
    }
}

//----- (0044CE40) --------------------------------------------------------
bool sub_44CE40(enum PLAYER_SIDE player_side, Entity *a2)
{
	enum UNIT_ID v2; // eax@1
	enum PLAYER_SIDE v4; // eax@4

	v2 = a2->unit_id;
	if (v2 == 67)
		goto LABEL_12;
	if (v2 == 68)
		return 1;
	v4 = a2->player_side;
	if (v4 == player_side)
		return 1;
    if (v4 == 0 || game_globals_cpu[0].cash[v4 + 7 * player_side]) {
    LABEL_12:
        return false;
    }
    return true;
}

//----- (0044CE90) --------------------------------------------------------
void script_show_message(Script *a1)
{
	int v1; // edi@1
	const char *v2; // ebx@2
	Script *v3; // esi@3
	ScriptEvent *i; // eax@5
	Script *v5; // ecx@7
	int v6; // esi@13
	int v7; // edi@13
	int v8; // esi@13
	int v9; // edi@13
	int v10; // ebp@22
	int v11; // eax@22
	RenderString *v12; // esi@22
	Sprite *v13 = 0; // [sp+10h] [bp-4h]@0

	v1 = 0;
	while (1)
	{
		v2 = 0;
		if (v1)
		{
			v3 = a1;
		}
		else
		{
			v3 = a1;
            script_wait_event(a1);
		}
		v1 = 0;
		for (i = script_get_next_event(v3); i; i = script_get_next_event(v3))
		{
			if (i->event == EVT_MSG_DESELECTED)
			{
				v5 = i->sender;
				v2 = (const char *)i->param;
				if (v5)
					v13 = v5->sprite;
				else
					v13 = 0;
			}
			script_discard_event(i);
		}
		if (v2)
		{
			if (v13)
			{
				v6 = v13->x;
				v7 = v13->y;
				v13->field_88_unused = 1;
				v8 = (v6 - _47C380_mapd.mapd_cplc_render_x) >> 8;
				v9 = (v7 - _47C380_mapd.mapd_cplc_render_y) >> 8;
				if (v8 < 128)
					v8 = 128;
				if (v8 > render_width - 128)
					v8 = render_width - 128;
				if (v9 < 50)
					v9 = 50;
				if (v9 > render_height - 50)
					v9 = render_height - 50;
			}
			else
			{
				v8 = (unsigned int)render_width >> 1;
				v9 = (unsigned int)render_height >> 1;
			}
			v10 = _445C00_text(v2, 128);
			v11 = _445C80_text(v2, 128);
			v12 = render_string_create(
				0,
				currently_running_lvl_mobd[MOBD_FONT_27].items,
				v8 - (8 * (v11 + 2) >> 1),
				v9 - 32,
				v11 + 2,
				v10 + 2,
				536870917,
				8,
				8);
			render_string_445770(v12, v2, 0);
			v1 = script_yield_any_trigger(a1, 200) & SCRIPT_FLAGS_20_EVENT_TRIGGER;
			render_string_list_remove(v12);
		}
	}
}

//----- (0044D000) --------------------------------------------------------
int entity_44D000_boxd(Entity *a1)
{
	Entity *v1; // edi@1
	Sprite *v2; // eax@1
	int v3; // ebp@1
	int v4; // ecx@1
	int v5; // esi@1
	DataBoxd_stru0_per_map_unit *v6; // ebx@1
	int v7; // edx@3
	int v8; // eax@3
	int v9; // eax@7
	int v10; // ebx@11
	int result; // eax@12
	int v12; // esi@13
	int v13; // eax@13
	int v14; // ecx@14
	int v15; // edx@14
	Sprite *v16; // eax@31
	int v17; // ebp@32
	int v18; // eax@32
	UnitStat *v19; // eax@32
	int v20; // eax@33
	int v21; // ecx@35
	UnitStat *v22; // eax@35
	int v23; // eax@36
	int v24; // edx@38
	int v25; // [sp+10h] [bp-2Ch]@1
	int v26; // [sp+10h] [bp-2Ch]@13
	int v27; // [sp+14h] [bp-28h]@1
	int v28; // [sp+18h] [bp-24h]@13
	int v29[8]; // [sp+1Ch] [bp-20h]@7

	v1 = a1;
	v2 = a1->sprite;
	v3 = v2->y >> 13;
	v4 = v2->x >> 13;
	v5 = 0;
	v27 = v4;
	v25 = 0;
	v6 = boxd_get_tile(v4, v3);
	while (1)
	{
		v7 = v4 + _465708_x_offsets[v5];
		v8 = v3 + _465728_y_offsets[v5];
		if (v7 < 0 || v7 >= map_get_width() || v8 < 0 || v8 >= map_get_height())
		{
			v29[v5] = 0;
		}
		else
		{
			v9 = boxd_40EA50_classify_tile_objects(v1, v7, v8, &v6[_478BE8_map_info__see40E6E0[v5]]) == 2;
			v29[v5] = v9;
			if (!v9)
				v25 = 1;
		}
		++v5;
		if (v5 >= 8)
			break;
		v4 = v27;
	}
	v10 = 0;
	if (!v25)
		return 2;
	v26 = 0;
	v28 = 1;
	v12 = v1->field_D4 != 1 ? -1 : 1;
	v13 = ((unsigned __int8)(v1->field_D8 >> 5) - 2 * (_BYTE)v12) & 7;
	while (1)
	{
		v14 = v27 + _465708_x_offsets[v13];
		v15 = v3 + _465728_y_offsets[v13];
		if (v14 < 0 || v14 >= map_get_width() || v15 < 0 || v15 >= map_get_height())
			goto LABEL_27;
		if (!v29[v13])
		{
			if (!(v13 & 1) && v28)
				v28 = 0;
			goto LABEL_27;
		}
		if (!(v13 & 1))
			goto LABEL_29;
		if (v29[((_BYTE)v12 + (_BYTE)v13) & 7])
			break;
		LOBYTE_HEXRAYS(v13) = (v12 + v13) & 7;
	LABEL_27:
		v13 = ((_BYTE)v12 + (_BYTE)v13) & 7;
		if (++v10 >= 8)
			goto LABEL_30;
	}
	if (!v29[((_BYTE)v13 - (_BYTE)v12) & 7])
		goto LABEL_27;
LABEL_29:
	v26 = 1;
LABEL_30:
	if (v26)
	{
		v17 = _465728_y_offsets[v13] + v3;
		v18 = v27 + _465708_x_offsets[v13];
		v1->field_C8 = v17;
		v1->field_C4 = v18;
		v19 = v1->stats;
		if (v19->is_infantry)
			v20 = map_get_entity_placement_inside_tile_x(v1, v1->_A4_idx_in_tile);
		else
			v20 = v19->field_4C != 128 ? 7424 : 4096;
		v21 = v20 + (v1->field_C4 << 13);
		v22 = v1->stats;
		v1->sprite_x = v21;
		if (v22->is_infantry)
			v23 = map_get_entity_placement_inside_tile_y(v1, v1->_A4_idx_in_tile);
		else
			v23 = v22->field_4C != 128 ? 7424 : 4096;
		v24 = v23 + (v1->field_C8 << 13);
		result = 1;
		v1->sprite_y = v24;
	}
	else
	{
		v16 = v1->sprite;
		v1->field_C4 = v16->x >> 13;
		v1->field_C8 = v16->y >> 13;
		result = 0;
	}
	return result;
}
// 478AAC: using guessed type int map_get_height();
// 4793F8: using guessed type int map_get_width();
// 44D000: using guessed type int var_20[8];

//----- (0044D250) --------------------------------------------------------
_DWORD *boxd_44D250(_DWORD *a1, _DWORD *a2, int a3, Entity *a4, int *a5)
{
	_DWORD *v5; // edi@1
	int v6; // esi@1
	int v7; // ebx@1
	DataBoxd_stru0_per_map_unit *v8; // ebp@1
	int v9; // edx@3
	int v10; // eax@3
	bool v11; // sf@9
	unsigned __int8 v12; // of@9
	_DWORD *result; // eax@10
	_DWORD *v14; // [sp+10h] [bp-8h]@1
	int v15; // [sp+1Ch] [bp+4h]@1

	v5 = a2;
	v6 = a3 != 1 ? -1 : 1;
	v14 = a1;
	v7 = ((unsigned __int8)*a5 - 2 * (_BYTE)v6) & 7;
	v8 = boxd_get_tile(*a1, *a2);
	v15 = 0;
	while (1)
	{
		v9 = *a1 + _465708_x_offsets[v7];
		v10 = *v5 + _465728_y_offsets[v7];
		if (v9 >= 0
			&& v9 < map_get_width()
			&& v10 >= 0
			&& v10 < map_get_height()
			&& !(v7 & 1)
			&& boxd_40EA50_classify_tile_objects(a4, v9, v10, &v8[_478BE8_map_info__see40E6E0[v7]]) == 2)
		{
			break;
		}
		v7 = ((_BYTE)v6 + (_BYTE)v7) & 7;
		v12 = __OFSUB__(v15 + 1, 8);
		v11 = v15++ - 7 < 0;
		if (!(v11 ^ v12))
		{
			result = 0;
			goto LABEL_12;
		}
		a1 = v14;
	}
	result = (_DWORD *)1;
LABEL_12:
	if (result)
	{
		result = v14;
		*a5 = v7;
		*result += _465708_x_offsets[v7];
		*v5 += _465728_y_offsets[v7];
	}
	return result;
}

//----- (0044D340) --------------------------------------------------------
bool boxd_44D340(int *out_x, int *out_y, int a3, Entity *a1, int *out_idx)
{
	Entity *v5; // esi@2
	int v6; // eax@2
	int v7; // ebx@4
	int v8; // edi@4
	DataBoxd_stru0_per_map_unit *v9; // ebp@4
	int v10; // edx@6
	int v11; // ecx@6
	int v12; // eax@11
	int v13; // eax@12
	bool v14; // sf@23
	unsigned __int8 v15; // of@23
	int v16; // eax@25
	int v17; // ecx@26
	int v19; // eax@37
	char v20; // [sp+10h] [bp-10h]@2
	int v21; // [sp+14h] [bp-Ch]@4
	int *v22; // [sp+18h] [bp-8h]@1
	int *v23; // [sp+1Ch] [bp-4h]@1
	Entity *a1a; // [sp+28h] [bp+8h]@4

	v23 = out_y;
	v22 = out_x;
	if (a3 == 1)
	{
		v5 = a1;
		v20 = 1;
		v6 = a1->field_124 & 2;
	}
	else
	{
		v5 = a1;
		v20 = -1;
		v6 = a1->field_124 & 4;
	}
	a1a = (Entity *)v6;
	v7 = ((unsigned __int8)*out_idx - 2 * v20) & 7;
	v8 = 0;
	v21 = 0;
	v9 = boxd_get_tile(*out_x, *out_y);
	while (1)
	{
		v10 = *out_x + _465708_x_offsets[v7];
		v11 = *v23 + _465728_y_offsets[v7];
		if (v10 < 0 || v10 >= map_get_width() || v11 < 0 || v11 >= map_get_height() || v7 & 1)
			goto LABEL_23;
		v12 = boxd_40EA50_classify_tile_objects(v5, v10, v11, &v9[_478BE8_map_info__see40E6E0[v7]]) - 1;
		if (v12)
		{
			v13 = v12 - 1;
			if (!v13)
			{
				if (a1a)
					v5->field_124 &= ~(unsigned int)a1a;
			LABEL_21:
				v8 = 1;
				goto LABEL_22;
			}
			if (v13 == 1 && (!v5->pathing.field_50 || a1a))
				goto LABEL_21;
		}
		else if (v5->pathing.field_54 || a1a)
		{
			goto LABEL_21;
		}
	LABEL_22:
		if (v8)
			goto LABEL_25;
	LABEL_23:
		v7 = (v20 + (_BYTE)v7) & 7;
		v15 = __OFSUB__(v21 + 1, 8);
		v14 = v21++ - 7 < 0;
		if (!(v14 ^ v15))
			break;
		out_x = v22;
	}
	if (!v8)
		return 0;
LABEL_25:
	v16 = *v22 + _465708_x_offsets[v7];
	if (v16 == map_get_width() - 1)
	{
		v17 = a3;
		if (v7 || a3)
		{
			if (v7 == 4 && a3 == 1)
				return 0;
			goto LABEL_32;
		}
	}
	else
	{
		v17 = a3;
	LABEL_32:
		if (v16 || (v7 || v17 != 1) && (v7 != 4 || v17))
		{
			v19 = _465728_y_offsets[v7] + *v23;
			if ((v19 != map_get_height() - 1 || (v7 != 2 || v17) && (v7 != 6 || v17 != 1))
				&& (v19 || (v7 != 2 || v17 != 1) && (v7 != 6 || v17)))
			{
				*out_idx = v7;
				*v22 += _465708_x_offsets[v7];
				*v23 += _465728_y_offsets[v7];
				return 1;
			}
		}
	}
	return 0;
}



//----- (0044D5D0) --------------------------------------------------------
//int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
int main(int argc, char* argv[])
{
    OsInitConsole();
    OsInitTimer();

    GameFactory gameFactory;
    auto game = gameFactory.Create();

    game->Run();
    return 0;
}

//----- (00456560) --------------------------------------------------------
int nullsub_4()
{
	return 0;
}

//----- (0045A320) --------------------------------------------------------
FILE *j_fopen_weirdmode_3(const char *a1)
{
	return fopen(a1, aRbwbrBwB);
}
/*
//----- (0045A3C4) --------------------------------------------------------
int sub_45A3C4(int a1, char *a2)
{
	int v2; // edi@1
	char *v3; // esi@1
	char *v4; // esi@1
	char *v5; // esi@1
	int result; // eax@1

	v2 = dword_476AC0;
	*(_DWORD *)a2 = *(_DWORD *)&a2[dword_476AC0];
	v3 = &a2[a1];
	*(_DWORD *)v3 = *(_DWORD *)&v3[v2];
	v4 = &v3[a1];
	*(_DWORD *)v4 = *(_DWORD *)&v4[v2];
	v5 = &v4[a1];
	result = *(_DWORD *)&v5[v2];
	*(_DWORD *)v5 = result;
	return result;
}
// 476AC0: using guessed type int dword_476AC0;

//----- (0045A3E7) --------------------------------------------------------
int sub_45A3E7(int a1, char *a2, char *a3)
{
	char v3; // al@1
	char *v4; // ebx@1
	int v5; // edi@2
	char *v6; // esi@2
	char *v7; // esi@2
	char *v8; // esi@2
	int result; // eax@2

	v3 = *a2;
	v4 = a2 + 1;
	if (v3)
	{
		v5 = dword_476AC0 + *(_DWORD *)(dword_476AC4 + 4 * (unsigned __int8)v3);
		*(_DWORD *)a3 = *(_DWORD *)&a3[v5];
		v6 = &a3[a1];
		*(_DWORD *)v6 = *(_DWORD *)&v6[v5];
		v7 = &v6[a1];
		*(_DWORD *)v7 = *(_DWORD *)&v7[v5];
		v8 = &v7[a1];
		result = *(_DWORD *)&v8[v5];
		*(_DWORD *)v8 = result;
	}
	else
	{
		*(_DWORD *)a3 = *(_DWORD *)v4;
		*(_DWORD *)&a3[a1] = *((_DWORD *)v4 + 1);
		*(_DWORD *)&a3[2 * a1] = *((_DWORD *)v4 + 2);
		result = *((_DWORD *)v4 + 3);
		*(_DWORD *)&a3[3 * a1] = result;
	}
	return result;
}

//----- (0045A43F) --------------------------------------------------------
__int16 sub_45A43F(int a1, int a2, _BYTE *a3, char *a4)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = *a3;
	BYTE1(a1) = *a3;
	v4 = __ROR4__(a1, 8);
	BYTE1(v4) = v4;
	v5 = __ROR4__(v4, 8);
	BYTE1(v5) = v5;
	*(_DWORD *)a4 = v5;
	*(_DWORD *)&a4[a2] = v5;
	*(_DWORD *)&a4[2 * a2] = v5;
	*(_DWORD *)&a4[3 * a2] = v5;
	return v5;
}

//----- (0045A460) --------------------------------------------------------
int sub_45A460(__int16 a1, int a2, int a3)
{
	int v3; // eax@1
	int result; // eax@2

	v3 = *(_BYTE *)a3;
	if (v3 & 0xC0)
	{
		LOBYTE_HEXRAYS(a1) = *(_BYTE *)(a3 + 1);
		result = ((int(*)(int, __int16))off_476AC8[v3])(a2, a1);
	}
	else
	{
		result = ((int(*)(int, _WORD))off_476AC8[v3])(a2, *(_WORD *)(a3 + 1));
	}
	return result;
}

//----- (0045A48E) --------------------------------------------------------
_BYTE *sub_45A48E(unsigned __int16 a1, __int16 a2, _BYTE *a3, int a4, int a5, int a6, int a7, int a8)
{
	int v8; // esi@1
	_BYTE *v9; // ebx@1
	int v10; // eax@1
	int v11; // ecx@1
	int v12; // eax@3
	int v13; // eax@3
	int v14; // esi@3
	int v15; // eax@5
	char *v16; // esi@5
	int v17; // eax@5
	int v18; // ecx@5
	int v20; // [sp+Ch] [bp-Ch]@3
	int v21; // [sp+10h] [bp-8h]@1
	__int16 v22; // [sp+16h] [bp-2h]@2
	__int16 v23; // [sp+16h] [bp-2h]@3

	dword_476AC4 = a8;
	dword_476AC0 = a6 + a5 - a4;
	v8 = a4;
	v9 = a3;
	v10 = a1;
	LOWORD_HEXRAYS(v10) = 12 * a1;
	v21 = v10;
	v11 = a7;
LABEL_2:
	v22 = a1 >> 1;
	while (1)
	{
		v12 = *v9;
		v20 = v12;
		++v9;
		LOBYTE_HEXRAYS(v12) = (unsigned __int8)(v12 & 0xC0) >> 4;
		(*(void(__thiscall **)(int))((char *)off_476DC8 + v12))(v11);
		v13 = v20;
		LOBYTE_HEXRAYS(v13) = (unsigned __int8)(v20 & 0x30) >> 2;
		(*(int(**)())((char *)off_476DC8 + v13))();
		v14 = v8 + 8;
		v23 = v22 - 1;
		if (!v23)
		{
			v23 = a1 >> 1;
			v14 += v21;
			if (!--a2)
				return v9;
		}
		v15 = v20;
		LOBYTE_HEXRAYS(v15) = v20 & 0xC;
		(*(int(**)())((char *)off_476DC8 + v15))();
		v16 = (char *)(v14 + 4);
		v17 = v20;
		LOBYTE_HEXRAYS(v17) = v20 & 3;
		((void (__usercall *)(int@<ecx>, char *@<esi>))off_476DC8[v17])(v18, v16);
		v8 = (int)(v16 + 4);
		v22 = v23 - 1;
		if (!v22)
		{
			v8 += v21;
			if (--a2)
				goto LABEL_2;
			return v9;
		}
	}
}

//----- (0045A556) --------------------------------------------------------
__int16 sub_45A556(int a1, __int16 a2, int a3, char *a4)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045A594) --------------------------------------------------------
char sub_45A594(int a1, __int16 a2, int a3, char *a4)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v5) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045A5D2) --------------------------------------------------------
char sub_45A5D2(int a1, __int16 a2, int a3, char *a4)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(a1) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045A610) --------------------------------------------------------
char __usercall sub_45A610@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v5) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045A64E) --------------------------------------------------------
char __usercall sub_45A64E@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045A68C) --------------------------------------------------------
__int16 __usercall sub_45A68C@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(a1) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)a4 = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045A6CA) --------------------------------------------------------
char __usercall sub_45A6CA@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = HIBYTE_HEXRAYS(a2);
	BYTE1(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045A708) --------------------------------------------------------
char __usercall sub_45A708@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v5) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045A746) --------------------------------------------------------
char __usercall sub_45A746@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(a1) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045A784) --------------------------------------------------------
char __usercall sub_45A784@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(a1) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)a4 = v4;
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = HIBYTE_HEXRAYS(a2);
	BYTE1(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045A7C2) --------------------------------------------------------
char __usercall sub_45A7C2@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)&a4[a3] = v4;
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v5) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045A800) --------------------------------------------------------
char __usercall sub_45A800@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045A83E) --------------------------------------------------------
__int16 __usercall sub_45A83E@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(a1) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045A87C) --------------------------------------------------------
__int16 __usercall sub_45A87C@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045A8BA) --------------------------------------------------------
char __usercall sub_45A8BA@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v5) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045A8F8) --------------------------------------------------------
char __usercall sub_45A8F8@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045A936) --------------------------------------------------------
__int16 __usercall sub_45A936@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(a1) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045A974) --------------------------------------------------------
__int16 __usercall sub_45A974@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)&a4[a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045A9B2) --------------------------------------------------------
char __usercall sub_45A9B2@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v5) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045A9F0) --------------------------------------------------------
__int16 __usercall sub_45A9F0@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045AA2E) --------------------------------------------------------
char __usercall sub_45AA2E@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = HIBYTE_HEXRAYS(a2);
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045AA6C) --------------------------------------------------------
__int16 __usercall sub_45AA6C@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)&a4[a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045AAAA) --------------------------------------------------------
__int16 __usercall sub_45AAAA@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045AAE8) --------------------------------------------------------
char __usercall sub_45AAE8@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045AB26) --------------------------------------------------------
char __usercall sub_45AB26@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = HIBYTE_HEXRAYS(a2);
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045AB64) --------------------------------------------------------
char __usercall sub_45AB64@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v5) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045ABA2) --------------------------------------------------------
char __usercall sub_45ABA2@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045ABE0) --------------------------------------------------------
__int16 __usercall sub_45ABE0@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(a1) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)a4 = v4;
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045AC1E) --------------------------------------------------------
char __usercall sub_45AC1E@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = HIBYTE_HEXRAYS(a2);
	BYTE1(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045AC5C) --------------------------------------------------------
char __usercall sub_45AC5C@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(a1) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v5) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045AC9A) --------------------------------------------------------
char __usercall sub_45AC9A@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045ACD8) --------------------------------------------------------
char __usercall sub_45ACD8@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(a1) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v5) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045AD16) --------------------------------------------------------
char __usercall sub_45AD16@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045AD54) --------------------------------------------------------
__int16 __usercall sub_45AD54@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045AD92) --------------------------------------------------------
__int16 __usercall sub_45AD92@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = HIBYTE_HEXRAYS(a2);
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045ADD0) --------------------------------------------------------
__int16 __usercall sub_45ADD0@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045AE0E) --------------------------------------------------------
char __usercall sub_45AE0E@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v5) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045AE4C) --------------------------------------------------------
char __usercall sub_45AE4C@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(a1) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045AE8A) --------------------------------------------------------
__int16 __usercall sub_45AE8A@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(a1) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)a4 = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045AEC8) --------------------------------------------------------
char __usercall sub_45AEC8@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v5) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045AF06) --------------------------------------------------------
char __usercall sub_45AF06@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045AF44) --------------------------------------------------------
__int16 __usercall sub_45AF44@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045AF82) --------------------------------------------------------
__int16 __usercall sub_45AF82@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = HIBYTE_HEXRAYS(a2);
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045AFC0) --------------------------------------------------------
__int16 __usercall sub_45AFC0@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045AFFE) --------------------------------------------------------
char __usercall sub_45AFFE@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045B03C) --------------------------------------------------------
char __usercall sub_45B03C@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v5) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045B07A) --------------------------------------------------------
__int16 __usercall sub_45B07A@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(a1) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045B0B8) --------------------------------------------------------
char __usercall sub_45B0B8@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(a1) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045B0F6) --------------------------------------------------------
__int16 __usercall sub_45B0F6@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(a1) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)&a4[a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045B134) --------------------------------------------------------
char __usercall sub_45B134@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = HIBYTE_HEXRAYS(a2);
	BYTE1(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045B172) --------------------------------------------------------
char __usercall sub_45B172@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v5) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045B1B0) --------------------------------------------------------
char __usercall sub_45B1B0@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v5) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045B1EE) --------------------------------------------------------
char __usercall sub_45B1EE@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = HIBYTE_HEXRAYS(a2);
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045B22C) --------------------------------------------------------
__int16 __usercall sub_45B22C@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)a4 = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045B26A) --------------------------------------------------------
__int16 __usercall sub_45B26A@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = HIBYTE_HEXRAYS(a2);
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045B2A8) --------------------------------------------------------
char __usercall sub_45B2A8@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)a4 = v4;
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045B2E6) --------------------------------------------------------
char __usercall sub_45B2E6@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)&a4[a3] = v4;
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045B324) --------------------------------------------------------
char __usercall sub_45B324@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045B362) --------------------------------------------------------
char __usercall sub_45B362@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045B3A0) --------------------------------------------------------
__int16 __usercall sub_45B3A0@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = HIBYTE_HEXRAYS(a2);
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045B3DE) --------------------------------------------------------
char __usercall sub_45B3DE@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(a1) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = HIBYTE_HEXRAYS(a2);
	BYTE1(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045B41C) --------------------------------------------------------
char __usercall sub_45B41C@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v5) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045B45A) --------------------------------------------------------
char __usercall sub_45B45A@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v4) = a2;
	BYTE1(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	v5 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045B498) --------------------------------------------------------
char __usercall sub_45B498@<al>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	BYTE1(a1) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(a1) = HIBYTE_HEXRAYS(a2);
	v4 = __ROR4__(a1, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	LOBYTE_HEXRAYS(v4) = HIBYTE_HEXRAYS(a2);
	BYTE1(v4) = a2;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)&a4[2 * a3] = v4;
	BYTE1(v4) = a2;
	LOBYTE_HEXRAYS(v4) = a2;
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = HIBYTE_HEXRAYS(a2);
	LOBYTE_HEXRAYS(v5) = HIBYTE_HEXRAYS(a2);
	*(_DWORD *)(&a4[2 * a3] + a3) = v5;
	return v5;
}

//----- (0045B4D6) --------------------------------------------------------
__int16 __usercall sub_45B4D6@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a3 + a4 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = *(_BYTE *)(a3 + a4 + 1);
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a4 + 2 * a3 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = *(_BYTE *)(a4 + 2 * a3 + 1);
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v6 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v6) = a2;
	BYTE1(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045B51C) --------------------------------------------------------
int __usercall sub_45B51C@<eax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int result; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	*(_DWORD *)&a5[2 * a3] = *(_DWORD *)(a4 + 2 * a3);
	result = *(_DWORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = result;
	return result;
}

//----- (0045B54A) --------------------------------------------------------
char __usercall sub_45B54A@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	LOWORD_HEXRAYS(a1) = *(_WORD *)(a4 + 2);
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2 * a3 + 2);
	v6 = __ROR4__(v5, 16);
	BYTE1(v6) = a2;
	LOBYTE_HEXRAYS(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045B58B) --------------------------------------------------------
int __usercall sub_45B58B@<eax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int result; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	result = *(_DWORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = result;
	return result;
}

//----- (0045B5C1) --------------------------------------------------------
char __usercall sub_45B5C1@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	BYTE1(a1) = *(_BYTE *)(a4 + 3);
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = *(_BYTE *)(a3 + a4 + 3);
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = *(_BYTE *)(a4 + 2 * a3 + 3);
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	BYTE1(v5) = *(_BYTE *)(a3 + a4 + 2 * a3 + 3);
	LOBYTE_HEXRAYS(v5) = a2;
	v6 = __ROR4__(v5, 16);
	BYTE1(v6) = a2;
	LOBYTE_HEXRAYS(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045B606) --------------------------------------------------------
__int16 __usercall sub_45B606@<ax>(char a1@<dl>, int a2@<ecx>, int *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	v4 = *a3;
	*(_DWORD *)a4 = *a3;
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	*(_DWORD *)&a4[a2] = v4;
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	*(_DWORD *)&a4[2 * a2] = v4;
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a1;
	BYTE1(v5) = a1;
	*(_DWORD *)(&a4[2 * a2] + a2) = v5;
	return v5;
}

//----- (0045B63B) --------------------------------------------------------
char __usercall sub_45B63B@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, _BYTE *a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *a4;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a4[a3];
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a4[2 * a3];
	*(_DWORD *)&a5[2 * a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v6 = __ROR4__(v5, 16);
	BYTE1(v6) = a2;
	LOBYTE_HEXRAYS(v6) = *(&a4[2 * a3] + a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045B67C) --------------------------------------------------------
int __usercall sub_45B67C@<eax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int result; // eax@1

	BYTE1(a1) = *(_BYTE *)(a4 + 3);
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	v6 = *(_DWORD *)(a4 + 2 * a3);
	LOBYTE_HEXRAYS(v6) = a2;
	*(_DWORD *)&a5[2 * a3] = v6;
	result = *(_DWORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = result;
	return result;
}

//----- (0045B6AE) --------------------------------------------------------
char __usercall sub_45B6AE@<al>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	*(_DWORD *)a4 = *(_DWORD *)a3;
	v4 = *(_DWORD *)&a3[a2];
	LOBYTE_HEXRAYS(v4) = a1;
	*(_DWORD *)&a4[a2] = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)&a3[2 * a2 + 2];
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	*(_DWORD *)&a4[2 * a2] = v4;
	BYTE1(v4) = *(&a3[2 * a2 + 3] + a2);
	LOBYTE_HEXRAYS(v4) = a1;
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = a1;
	LOBYTE_HEXRAYS(v5) = a1;
	*(_DWORD *)(&a4[2 * a2] + a2) = v5;
	return v5;
}

//----- (0045B6E0) --------------------------------------------------------
char __usercall sub_45B6E0@<al>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	*(_DWORD *)a4 = *(_DWORD *)a3;
	v4 = __ROR4__(*(_DWORD *)&a3[a2], 16);
	BYTE1(v4) = a1;
	v4 = __ROR4__(v4, 16);
	*(_DWORD *)&a4[a2] = v4;
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = *(_WORD *)&a3[2 * a2];
	*(_DWORD *)&a4[2 * a2] = v4;
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = a1;
	LOBYTE_HEXRAYS(v5) = *(&a3[2 * a2] + a2);
	*(_DWORD *)(&a4[2 * a2] + a2) = v5;
	return v5;
}

//----- (0045B716) --------------------------------------------------------
int __usercall sub_45B716@<eax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, _BYTE *a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int result; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *a4;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)&a4[a3];
	*(_DWORD *)&a5[a3] = v5;
	v6 = __ROR4__(*(_DWORD *)&a4[2 * a3], 16);
	BYTE1(v6) = a2;
	v6 = __ROR4__(v6, 16);
	*(_DWORD *)&a5[2 * a3] = v6;
	result = *(_DWORD *)(&a4[2 * a3] + a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = result;
	return result;
}

//----- (0045B74C) --------------------------------------------------------
char __usercall sub_45B74C@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = *(_BYTE *)(a4 + 2 * a3 + 3);
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2 * a3 + 2);
	v6 = __ROR4__(v5, 16);
	BYTE1(v6) = a2;
	LOBYTE_HEXRAYS(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045B78D) --------------------------------------------------------
__int16 __usercall sub_45B78D@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	LOWORD_HEXRAYS(a1) = *(_WORD *)(a4 + 2);
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = *(_BYTE *)(a3 + a4 + 3);
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v6 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v6) = a2;
	BYTE1(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045B7CD) --------------------------------------------------------
__int16 __usercall sub_45B7CD@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, _WORD *a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = *a4;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *((_BYTE *)a4 + a3);
	*(_DWORD *)&a5[a3] = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v6 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v6) = a2;
	BYTE1(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045B80B) --------------------------------------------------------
__int16 __usercall sub_45B80B@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a4 + 2 * a3);
	*(_DWORD *)&a5[2 * a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v6 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045B84A) --------------------------------------------------------
char __usercall sub_45B84A@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2 * a3 + 2);
	v6 = __ROR4__(v5, 16);
	BYTE1(v6) = a2;
	LOBYTE_HEXRAYS(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045B88A) --------------------------------------------------------
__int16 __usercall sub_45B88A@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	LOWORD_HEXRAYS(a1) = *(_WORD *)(a4 + 2);
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v6 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v6) = a2;
	BYTE1(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045B8C9) --------------------------------------------------------
__int16 __usercall sub_45B8C9@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, char *a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)a4;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)&a4[a3];
	*(_DWORD *)&a5[a3] = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v6 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v6) = a2;
	BYTE1(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045B906) --------------------------------------------------------
__int16 __usercall sub_45B906@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3);
	*(_DWORD *)&a5[2 * a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v6 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045B944) --------------------------------------------------------
__int16 __usercall sub_45B944@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)&a5[a3] = *(_DWORD *)(a3 + a4);
	v6 = *(_DWORD *)(a4 + 2 * a3);
	*(_DWORD *)&a5[2 * a3] = v6;
	LOBYTE_HEXRAYS(v6) = a2;
	BYTE1(v6) = a2;
	v7 = __ROR4__(v6, 16);
	LOBYTE_HEXRAYS(v7) = a2;
	BYTE1(v7) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v7;
	return v7;
}

//----- (0045B972) --------------------------------------------------------
char __usercall sub_45B972@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // edi@1
	int v7; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = *(_BYTE *)(a4 + 2);
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = *(_BYTE *)(a4 + 1);
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a3 + a4 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = *(_BYTE *)(a3 + a4 + 1);
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a4 + 2 * a3 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = *(_BYTE *)(a4 + 2 * a3 + 1);
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	v6 = a3 + a4;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(v6 + 2 * a3 + 2);
	v7 = __ROR4__(v5, 16);
	BYTE1(v7) = *(_BYTE *)(v6 + 2 * a3 + 1);
	LOBYTE_HEXRAYS(v7) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v7;
	return v7;
}

//----- (0045B9BE) --------------------------------------------------------
__int16 __usercall sub_45B9BE@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	v6 = *(_DWORD *)(a3 + a4);
	*(_DWORD *)&a5[a3] = v6;
	LOBYTE_HEXRAYS(v6) = a2;
	BYTE1(v6) = a2;
	v6 = __ROR4__(v6, 16);
	LOBYTE_HEXRAYS(v6) = a2;
	BYTE1(v6) = a2;
	*(_DWORD *)&a5[2 * a3] = v6;
	LOBYTE_HEXRAYS(v6) = a2;
	BYTE1(v6) = a2;
	v7 = __ROR4__(v6, 16);
	LOBYTE_HEXRAYS(v7) = a2;
	BYTE1(v7) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v7;
	return v7;
}

//----- (0045B9F4) --------------------------------------------------------
__int16 __usercall sub_45B9F4@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	v6 = *(_DWORD *)(a4 + 2 * a3);
	*(_DWORD *)&a5[2 * a3] = v6;
	LOBYTE_HEXRAYS(v6) = a2;
	BYTE1(v6) = a2;
	v7 = __ROR4__(v6, 16);
	LOBYTE_HEXRAYS(v7) = a2;
	BYTE1(v7) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v7;
	return v7;
}

//----- (0045BA2A) --------------------------------------------------------
char __usercall sub_45BA2A@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = *(_BYTE *)(a4 + 1);
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = *(_BYTE *)(a3 + a4 + 1);
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = *(_BYTE *)(a4 + 2 * a3 + 1);
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v6 = __ROR4__(v5, 16);
	BYTE1(v6) = *(_BYTE *)(a3 + a4 + 2 * a3 + 1);
	LOBYTE_HEXRAYS(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045BA6F) --------------------------------------------------------
char __usercall sub_45BA6F@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = *(_BYTE *)(a4 + 2);
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a3 + a4 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a4 + 2 * a3 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a3 + a4 + 2 * a3 + 2);
	v6 = __ROR4__(v5, 16);
	BYTE1(v6) = a2;
	LOBYTE_HEXRAYS(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045BAB4) --------------------------------------------------------
int __usercall sub_45BAB4@<eax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int result; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a4 + 2 * a3 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = *(_BYTE *)(a4 + 2 * a3 + 1);
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	result = *(_DWORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = result;
	return result;
}

//----- (0045BAEE) --------------------------------------------------------
char __usercall sub_45BAEE@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	BYTE1(a1) = *(_BYTE *)(a4 + 3);
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	BYTE1(v5) = *(_BYTE *)(a3 + a4 + 2 * a3 + 3);
	LOBYTE_HEXRAYS(v5) = a2;
	v6 = __ROR4__(v5, 16);
	BYTE1(v6) = a2;
	LOBYTE_HEXRAYS(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045BB31) --------------------------------------------------------
__int16 __usercall sub_45BB31@<ax>(char a1@<dl>, int a2@<ecx>, _DWORD *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	v4 = *a3;
	*(_DWORD *)a4 = *a3;
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = *((_BYTE *)a3 + a2 + 2);
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = *((_BYTE *)a3 + a2 + 1);
	LOBYTE_HEXRAYS(v4) = a1;
	*(_DWORD *)&a4[a2] = v4;
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	*(_DWORD *)&a4[2 * a2] = v4;
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a1;
	BYTE1(v5) = a1;
	*(_DWORD *)(&a4[2 * a2] + a2) = v5;
	return v5;
}

//----- (0045BB6A) --------------------------------------------------------
char __usercall sub_45BB6A@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, _BYTE *a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *a4;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)&a4[a3];
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)&a4[2 * a3];
	*(_DWORD *)&a5[2 * a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v6 = __ROR4__(v5, 16);
	BYTE1(v6) = a2;
	LOBYTE_HEXRAYS(v6) = *(&a4[2 * a3] + a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045BBA9) --------------------------------------------------------
__int16 __usercall sub_45BBA9@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	LOWORD_HEXRAYS(a1) = *(_WORD *)(a4 + 2);
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = *(_BYTE *)(a3 + a4 + 3);
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a4 + 2 * a3);
	*(_DWORD *)&a5[2 * a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v6 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045BBEA) --------------------------------------------------------
char __usercall sub_45BBEA@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, _WORD *a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = *a4;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *((_BYTE *)a4 + a3);
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = HIBYTE_HEXRAYS(a4[a3 + 1]);
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)((char *)&a4[a3 + 1] + a3);
	v6 = __ROR4__(v5, 16);
	BYTE1(v6) = a2;
	LOBYTE_HEXRAYS(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045BC2B) --------------------------------------------------------
__int16 __usercall sub_45BC2B@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	LOWORD_HEXRAYS(a1) = *(_WORD *)(a4 + 2);
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3);
	*(_DWORD *)&a5[2 * a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v6 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045BC6A) --------------------------------------------------------
char __usercall sub_45BC6A@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // edi@1
	int v7; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a4 + 2 * a3 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = *(_BYTE *)(a4 + 2 * a3 + 1);
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	v6 = a3 + a4;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(v6 + 2 * a3 + 2);
	v7 = __ROR4__(v5, 16);
	BYTE1(v7) = *(_BYTE *)(v6 + 2 * a3 + 1);
	LOBYTE_HEXRAYS(v7) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v7;
	return v7;
}

//----- (0045BCB0) --------------------------------------------------------
__int16 __usercall sub_45BCB0@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v6 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v6) = a2;
	BYTE1(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045BCF0) --------------------------------------------------------
__int16 __usercall sub_45BCF0@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = *(_BYTE *)(a4 + 2);
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = *(_BYTE *)(a4 + 1);
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a3 + a4 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = *(_BYTE *)(a3 + a4 + 1);
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v6 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v6) = a2;
	BYTE1(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045BD34) --------------------------------------------------------
__int16 __usercall sub_45BD34@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4);
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3);
	*(_DWORD *)&a5[2 * a3] = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v6 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v6) = a2;
	BYTE1(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045BD72) --------------------------------------------------------
int __usercall sub_45BD72@<eax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int result; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = *(_BYTE *)(a4 + 2 * a3 + 3);
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a4 + 2 * a3);
	*(_DWORD *)&a5[2 * a3] = v5;
	result = *(_DWORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = result;
	return result;
}

//----- (0045BDAB) --------------------------------------------------------
char __usercall sub_45BDAB@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	LOWORD_HEXRAYS(a1) = *(_WORD *)(a4 + 2);
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = *(_BYTE *)(a3 + a4 + 3);
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = *(_BYTE *)(a4 + 2 * a3 + 3);
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2 * a3 + 2);
	v6 = __ROR4__(v5, 16);
	BYTE1(v6) = a2;
	LOBYTE_HEXRAYS(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045BDEE) --------------------------------------------------------
__int16 __usercall sub_45BDEE@<ax>(char a1@<dl>, int a2@<ecx>, _DWORD *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	v4 = *a3;
	*(_DWORD *)a4 = *a3;
	BYTE1(v4) = *((_BYTE *)a3 + a2 + 3);
	LOBYTE_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = *((_BYTE *)a3 + a2);
	*(_DWORD *)&a4[a2] = v4;
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	*(_DWORD *)&a4[2 * a2] = v4;
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a1;
	BYTE1(v5) = a1;
	*(_DWORD *)(&a4[2 * a2] + a2) = v5;
	return v5;
}

//----- (0045BE26) --------------------------------------------------------
__int16 __usercall sub_45BE26@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, _WORD *a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = *a4;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *((_BYTE *)a4 + a3);
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a4[a3];
	*(_DWORD *)&a5[2 * a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v6 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)((char *)&a4[a3] + a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045BE65) --------------------------------------------------------
char __usercall sub_45BE65@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // edi@1
	int v7; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	v6 = a3 + a4;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(v6 + 2 * a3 + 2);
	v7 = __ROR4__(v5, 16);
	BYTE1(v7) = *(_BYTE *)(v6 + 2 * a3 + 1);
	LOBYTE_HEXRAYS(v7) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v7;
	return v7;
}

//----- (0045BEA7) --------------------------------------------------------
__int16 __usercall sub_45BEA7@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = *(_BYTE *)(a3 + a4 + 3);
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = *(_BYTE *)(a4 + 2 * a3 + 3);
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v6 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v6) = a2;
	BYTE1(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045BEE9) --------------------------------------------------------
__int16 __usercall sub_45BEE9@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = *(_BYTE *)(a4 + 2);
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = *(_BYTE *)(a4 + 1);
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v6 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v6) = a2;
	BYTE1(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045BF29) --------------------------------------------------------
__int16 __usercall sub_45BF29@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a3 + a4);
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a4 + 2 * a3);
	*(_DWORD *)&a5[2 * a3] = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v6 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v6) = a2;
	BYTE1(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045BF69) --------------------------------------------------------
char __usercall sub_45BF69@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	BYTE1(a1) = *(_BYTE *)(a4 + 3);
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = *(_BYTE *)(a3 + a4 + 3);
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2 * a3 + 2);
	v6 = __ROR4__(v5, 16);
	BYTE1(v6) = a2;
	LOBYTE_HEXRAYS(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045BFAC) --------------------------------------------------------
int __usercall sub_45BFAC@<eax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int result; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	result = *(_DWORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = result;
	return result;
}

//----- (0045BFE3) --------------------------------------------------------
__int16 __usercall sub_45BFE3@<ax>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	v4 = *(_DWORD *)a3;
	*(_DWORD *)a4 = *(_DWORD *)a3;
	LOWORD_HEXRAYS(v4) = *(_WORD *)&a3[a2 + 2];
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	*(_DWORD *)&a4[a2] = v4;
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	*(_DWORD *)&a4[2 * a2] = v4;
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a1;
	BYTE1(v5) = a1;
	*(_DWORD *)(&a4[2 * a2] + a2) = v5;
	return v5;
}

//----- (0045C019) --------------------------------------------------------
char __usercall sub_45C019@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	LOWORD_HEXRAYS(a1) = *(_WORD *)(a4 + 2);
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = *(_BYTE *)(a4 + 2 * a3 + 3);
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	BYTE1(v5) = *(_BYTE *)(a3 + a4 + 2 * a3 + 3);
	LOBYTE_HEXRAYS(v5) = a2;
	v6 = __ROR4__(v5, 16);
	BYTE1(v6) = a2;
	LOBYTE_HEXRAYS(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045C05C) --------------------------------------------------------
__int16 __usercall sub_45C05C@<ax>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	v4 = *(_DWORD *)a3;
	*(_DWORD *)a4 = *(_DWORD *)a3;
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = *(_WORD *)&a3[a2];
	*(_DWORD *)&a4[a2] = v4;
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	*(_DWORD *)&a4[2 * a2] = v4;
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a1;
	BYTE1(v5) = a1;
	*(_DWORD *)(&a4[2 * a2] + a2) = v5;
	return v5;
}

//----- (0045C091) --------------------------------------------------------
char __usercall sub_45C091@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, char *a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)a4;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)&a4[a3];
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a4[2 * a3];
	*(_DWORD *)&a5[2 * a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v6 = __ROR4__(v5, 16);
	BYTE1(v6) = a2;
	LOBYTE_HEXRAYS(v6) = *(&a4[2 * a3] + a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045C0D0) --------------------------------------------------------
__int16 __usercall sub_45C0D0@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, _BYTE *a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *a4;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a4[a3];
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)&a4[2 * a3];
	*(_DWORD *)&a5[2 * a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v6 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)(&a4[2 * a3] + a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045C10F) --------------------------------------------------------
int __usercall sub_45C10F@<eax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int result; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3);
	*(_DWORD *)&a5[2 * a3] = v5;
	result = *(_DWORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = result;
	return result;
}

//----- (0045C145) --------------------------------------------------------
char __usercall sub_45C145@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // edi@1
	int v8; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = *(_BYTE *)(a4 + 2);
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = *(_BYTE *)(a4 + 1);
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)&a5[a3] = *(_DWORD *)(a3 + a4);
	v6 = *(_DWORD *)(a4 + 2 * a3);
	*(_DWORD *)&a5[2 * a3] = v6;
	v7 = a3 + a4;
	BYTE1(v6) = a2;
	LOBYTE_HEXRAYS(v6) = *(_BYTE *)(v7 + 2 * a3 + 2);
	v8 = __ROR4__(v6, 16);
	BYTE1(v8) = *(_BYTE *)(v7 + 2 * a3 + 1);
	LOBYTE_HEXRAYS(v8) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v8;
	return v8;
}

//----- (0045C179) --------------------------------------------------------
__int16 __usercall sub_45C179@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, _WORD *a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = *a4;
	*(_DWORD *)a5 = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a4[a3 + 1];
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = HIBYTE_HEXRAYS(a4[a3]);
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v6 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v6) = a2;
	BYTE1(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045C1BA) --------------------------------------------------------
__int16 __usercall sub_45C1BA@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = *(_BYTE *)(a4 + 2);
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = *(_BYTE *)(a4 + 1);
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = *(_BYTE *)(a4 + 2 * a3 + 3);
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v6 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v6) = a2;
	BYTE1(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045C1FD) --------------------------------------------------------
char __usercall sub_45C1FD@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, _WORD *a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = *a4;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *((_BYTE *)a4 + a3 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = *((_BYTE *)a4 + a3 + 1);
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	LOWORD_HEXRAYS(v5) = a4[a3 + 1];
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	BYTE1(v5) = *((_BYTE *)&a4[a3 + 1] + a3 + 1);
	LOBYTE_HEXRAYS(v5) = a2;
	v6 = __ROR4__(v5, 16);
	BYTE1(v6) = a2;
	LOBYTE_HEXRAYS(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045C241) --------------------------------------------------------
char __usercall sub_45C241@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, _BYTE *a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *a4;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)&a4[a3];
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a4[2 * a3 + 2];
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a4[2 * a3 + 1];
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(&a4[2 * a3 + 2] + a3);
	v6 = __ROR4__(v5, 16);
	BYTE1(v6) = a2;
	LOBYTE_HEXRAYS(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045C284) --------------------------------------------------------
char __usercall sub_45C284@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // edi@1
	int v7; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a3 + a4);
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3);
	*(_DWORD *)&a5[2 * a3] = v5;
	v6 = a3 + a4;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(v6 + 2 * a3 + 2);
	v7 = __ROR4__(v5, 16);
	BYTE1(v7) = *(_BYTE *)(v6 + 2 * a3 + 1);
	LOBYTE_HEXRAYS(v7) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v7;
	return v7;
}

//----- (0045C2C7) --------------------------------------------------------
char __usercall sub_45C2C7@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a3 + a4 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = *(_BYTE *)(a3 + a4 + 1);
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2 * a3 + 2);
	v6 = __ROR4__(v5, 16);
	BYTE1(v6) = a2;
	LOBYTE_HEXRAYS(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045C30A) --------------------------------------------------------
__int16 __usercall sub_45C30A@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = *(_BYTE *)(a4 + 2);
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = *(_BYTE *)(a4 + 1);
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4);
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a4 + 2 * a3);
	*(_DWORD *)&a5[2 * a3] = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v6 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v6) = a2;
	BYTE1(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045C34B) --------------------------------------------------------
char __usercall sub_45C34B@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	LOWORD_HEXRAYS(a1) = *(_WORD *)(a4 + 2);
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a3 + a4 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = *(_BYTE *)(a3 + a4 + 1);
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3);
	*(_DWORD *)&a5[2 * a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v6 = __ROR4__(v5, 16);
	BYTE1(v6) = a2;
	LOBYTE_HEXRAYS(v6) = *(_BYTE *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045C38E) --------------------------------------------------------
__int16 __usercall sub_45C38E@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	BYTE1(a1) = *(_BYTE *)(a4 + 3);
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a4 + 2 * a3 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = *(_BYTE *)(a4 + 2 * a3 + 1);
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v6 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045C3D2) --------------------------------------------------------
char __usercall sub_45C3D2@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // edi@1
	int v7; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = *(_BYTE *)(a3 + a4 + 3);
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	v6 = a3 + a4;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(v6 + 2 * a3 + 2);
	v7 = __ROR4__(v5, 16);
	BYTE1(v7) = *(_BYTE *)(v6 + 2 * a3 + 1);
	LOBYTE_HEXRAYS(v7) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v7;
	return v7;
}

//----- (0045C417) --------------------------------------------------------
__int16 __usercall sub_45C417@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	LOWORD_HEXRAYS(a1) = *(_WORD *)(a4 + 2);
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a3 + a4 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = *(_BYTE *)(a4 + 2 * a3 + 1);
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v6 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045C459) --------------------------------------------------------
int __usercall sub_45C459@<eax>(char a1@<dl>, int a2@<ecx>, _DWORD *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int result; // eax@1

	v4 = *a3;
	*(_DWORD *)a4 = *a3;
	BYTE1(v4) = *((_BYTE *)a3 + a2 + 3);
	LOBYTE_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = *((_BYTE *)a3 + a2);
	*(_DWORD *)&a4[a2] = v4;
	BYTE1(v4) = *((_BYTE *)a3 + 2 * a2 + 3);
	LOBYTE_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = *((_BYTE *)a3 + 2 * a2);
	*(_DWORD *)&a4[2 * a2] = v4;
	result = *(_DWORD *)((char *)a3 + 2 * a2 + a2);
	*(_DWORD *)(&a4[2 * a2] + a2) = result;
	return result;
}

//----- (0045C48C) --------------------------------------------------------
__int16 __usercall sub_45C48C@<ax>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	*(_DWORD *)a4 = *(_DWORD *)a3;
	v4 = *(_DWORD *)&a3[a2];
	*(_DWORD *)&a4[a2] = v4;
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	*(_DWORD *)&a4[2 * a2] = v4;
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a1;
	BYTE1(v5) = a1;
	*(_DWORD *)(&a4[2 * a2] + a2) = v5;
	return v5;
}

//----- (0045C4B9) --------------------------------------------------------
__int16 __usercall sub_45C4B9@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, char *a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)a4;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)&a4[a3];
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)&a4[2 * a3];
	*(_DWORD *)&a5[2 * a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v6 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)(&a4[2 * a3] + a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045C4F6) --------------------------------------------------------
__int16 __usercall sub_45C4F6@<ax>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	*(_DWORD *)a4 = *(_DWORD *)a3;
	*(_DWORD *)&a4[a2] = *(_DWORD *)&a3[a2];
	v4 = *(_DWORD *)&a3[2 * a2];
	*(_DWORD *)&a4[2 * a2] = v4;
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a1;
	BYTE1(v5) = a1;
	*(_DWORD *)(&a4[2 * a2] + a2) = v5;
	return v5;
}

//----- (0045C51B) --------------------------------------------------------
int __usercall sub_45C51B@<eax>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1
	int result; // eax@1

	v4 = __ROR4__(*(_DWORD *)a3, 16);
	BYTE1(v4) = a1;
	v4 = __ROR4__(v4, 16);
	*(_DWORD *)a4 = v4;
	v5 = __ROR4__(*(_DWORD *)&a3[a2], 16);
	BYTE1(v5) = a1;
	v5 = __ROR4__(v5, 16);
	*(_DWORD *)&a4[a2] = v5;
	v6 = __ROR4__(*(_DWORD *)&a3[2 * a2], 16);
	BYTE1(v6) = a1;
	v6 = __ROR4__(v6, 16);
	*(_DWORD *)&a4[2 * a2] = v6;
	v7 = __ROR4__(*(_DWORD *)(&a3[2 * a2] + a2), 16);
	BYTE1(v7) = a1;
	result = __ROR4__(v7, 16);
	*(_DWORD *)(&a4[2 * a2] + a2) = result;
	return result;
}

//----- (0045C558) --------------------------------------------------------
int __usercall sub_45C558@<eax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int result; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)&a5[a3] = *(_DWORD *)(a3 + a4);
	*(_DWORD *)&a5[2 * a3] = *(_DWORD *)(a4 + 2 * a3);
	result = *(_DWORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = result;
	return result;
}

//----- (0045C57E) --------------------------------------------------------
char __usercall sub_45C57E@<al>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1

	v4 = *(_DWORD *)a3;
	LOBYTE_HEXRAYS(v4) = a1;
	*(_DWORD *)a4 = v4;
	v5 = *(_DWORD *)&a3[a2];
	LOBYTE_HEXRAYS(v5) = a1;
	*(_DWORD *)&a4[a2] = v5;
	v6 = *(_DWORD *)&a3[2 * a2];
	LOBYTE_HEXRAYS(v6) = a1;
	*(_DWORD *)&a4[2 * a2] = v6;
	v7 = *(_DWORD *)(&a3[2 * a2] + a2);
	LOBYTE_HEXRAYS(v7) = a1;
	*(_DWORD *)(&a4[2 * a2] + a2) = v7;
	return v7;
}

//----- (0045C5A3) --------------------------------------------------------
__int16 __usercall sub_45C5A3@<ax>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	v4 = __ROR4__(*(_DWORD *)a3, 16);
	BYTE1(v4) = a1;
	v4 = __ROR4__(v4, 16);
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = *(_WORD *)&a3[a2];
	*(_DWORD *)&a4[a2] = v4;
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a3[2 * a2];
	*(_DWORD *)&a4[2 * a2] = v4;
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a1;
	BYTE1(v5) = a1;
	*(_DWORD *)(&a4[2 * a2] + a2) = v5;
	return v5;
}

//----- (0045C5E1) --------------------------------------------------------
int __usercall sub_45C5E1@<eax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int result; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a3 + a4);
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3);
	*(_DWORD *)&a5[2 * a3] = v5;
	v6 = __ROR4__(*(_DWORD *)(a3 + a4 + 2 * a3), 16);
	BYTE1(v6) = a2;
	result = __ROR4__(v6, 16);
	*(_DWORD *)(&a5[2 * a3] + a3) = result;
	return result;
}

//----- (0045C620) --------------------------------------------------------
char __usercall sub_45C620@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = *(_BYTE *)(a3 + a4 + 3);
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	v6 = *(_DWORD *)(a3 + a4 + 2 * a3);
	LOBYTE_HEXRAYS(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045C65B) --------------------------------------------------------
__int16 __usercall sub_45C65B@<ax>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	v4 = *(_DWORD *)a3;
	LOBYTE_HEXRAYS(v4) = a1;
	*(_DWORD *)a4 = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)&a3[a2 + 2];
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	*(_DWORD *)&a4[a2] = v4;
	BYTE1(v4) = a3[2 * a2 + 3];
	LOBYTE_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	*(_DWORD *)&a4[2 * a2] = v4;
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a1;
	BYTE1(v5) = a1;
	*(_DWORD *)(&a4[2 * a2] + a2) = v5;
	return v5;
}

//----- (0045C695) --------------------------------------------------------
__int16 __usercall sub_45C695@<ax>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	*(_DWORD *)a4 = *(_DWORD *)a3;
	*(_DWORD *)&a4[a2] = *(_DWORD *)&a3[a2];
	v4 = __ROR4__(*(_DWORD *)&a3[2 * a2], 16);
	BYTE1(v4) = a1;
	v4 = __ROR4__(v4, 16);
	*(_DWORD *)&a4[2 * a2] = v4;
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	v5 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(&a3[2 * a2] + a2);
	*(_DWORD *)(&a4[2 * a2] + a2) = v5;
	return v5;
}

//----- (0045C6C2) --------------------------------------------------------
int __usercall sub_45C6C2@<eax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, char *a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int result; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)a4;
	*(_DWORD *)a5 = v5;
	v6 = __ROR4__(*(_DWORD *)&a4[a3], 16);
	BYTE1(v6) = a2;
	v6 = __ROR4__(v6, 16);
	*(_DWORD *)&a5[a3] = v6;
	*(_DWORD *)&a5[2 * a3] = *(_DWORD *)&a4[2 * a3];
	result = *(_DWORD *)(&a4[2 * a3] + a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = result;
	return result;
}

//----- (0045C6EF) --------------------------------------------------------
int __usercall sub_45C6EF@<eax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = *(_WORD *)(a4 + 2);
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	v6 = *(_DWORD *)(a3 + a4);
	LOBYTE_HEXRAYS(v6) = a2;
	*(_DWORD *)&a5[a3] = v6;
	*(_DWORD *)&a5[2 * a3] = *(_DWORD *)(a4 + 2 * a3);
	result = *(_DWORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = result;
	return result;
}

//----- (0045C717) --------------------------------------------------------
char __usercall sub_45C717@<al>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	*(_DWORD *)a4 = *(_DWORD *)a3;
	*(_DWORD *)&a4[a2] = *(_DWORD *)&a3[a2];
	v4 = *(_DWORD *)&a3[2 * a2];
	LOBYTE_HEXRAYS(v4) = a1;
	*(_DWORD *)&a4[2 * a2] = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)(&a3[2 * a2 + 2] + a2);
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = a1;
	LOBYTE_HEXRAYS(v5) = a1;
	*(_DWORD *)(&a4[2 * a2] + a2) = v5;
	return v5;
}

//----- (0045C73F) --------------------------------------------------------
__int16 __usercall sub_45C73F@<ax>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	*(_DWORD *)a4 = *(_DWORD *)a3;
	v4 = *(_DWORD *)&a3[a2];
	*(_DWORD *)&a4[a2] = v4;
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = *(_WORD *)&a3[2 * a2];
	*(_DWORD *)&a4[2 * a2] = v4;
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	v5 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(&a3[2 * a2] + a2);
	*(_DWORD *)(&a4[2 * a2] + a2) = v5;
	return v5;
}

//----- (0045C76C) --------------------------------------------------------
int __usercall sub_45C76C@<eax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, char *a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int result; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)a4;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)&a4[a3];
	*(_DWORD *)&a5[a3] = v5;
	*(_DWORD *)&a5[2 * a3] = *(_DWORD *)&a4[2 * a3];
	result = *(_DWORD *)(&a4[2 * a3] + a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = result;
	return result;
}

//----- (0045C799) --------------------------------------------------------
int __usercall sub_45C799@<eax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = *(_WORD *)(a4 + 2);
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	*(_DWORD *)&a5[2 * a3] = *(_DWORD *)(a4 + 2 * a3);
	result = *(_DWORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = result;
	return result;
}

//----- (0045C7C8) --------------------------------------------------------
char __usercall sub_45C7C8@<al>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	*(_DWORD *)a4 = *(_DWORD *)a3;
	v4 = *(_DWORD *)&a3[a2];
	*(_DWORD *)&a4[a2] = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)&a3[2 * a2 + 2];
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	*(_DWORD *)&a4[2 * a2] = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)(&a3[2 * a2 + 2] + a2);
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = a1;
	LOBYTE_HEXRAYS(v5) = a1;
	*(_DWORD *)(&a4[2 * a2] + a2) = v5;
	return v5;
}

//----- (0045C7F7) --------------------------------------------------------
int __usercall sub_45C7F7@<eax>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int result; // eax@1

	v4 = *(_DWORD *)a3;
	*(_DWORD *)a4 = *(_DWORD *)a3;
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	*(_DWORD *)&a4[a2] = v4;
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	*(_DWORD *)&a4[2 * a2] = v4;
	result = *(_DWORD *)(&a3[2 * a2] + a2);
	*(_DWORD *)(&a4[2 * a2] + a2) = result;
	return result;
}

//----- (0045C824) --------------------------------------------------------
char __usercall sub_45C824@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // edi@1
	int v7; // eax@1

	BYTE1(a1) = *(_BYTE *)(a4 + 3);
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)a4;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = *(_BYTE *)(a3 + a4 + 3);
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a3 + a4);
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = *(_BYTE *)(a4 + 2 * a3 + 3);
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a4 + 2 * a3);
	*(_DWORD *)&a5[2 * a3] = v5;
	v6 = a3 + a4;
	BYTE1(v5) = *(_BYTE *)(v6 + 2 * a3 + 3);
	LOBYTE_HEXRAYS(v5) = a2;
	v7 = __ROR4__(v5, 16);
	BYTE1(v7) = a2;
	LOBYTE_HEXRAYS(v7) = *(_BYTE *)(v6 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = v7;
	return v7;
}

//----- (0045C86C) --------------------------------------------------------
int __usercall sub_45C86C@<eax>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int result; // eax@1

	v4 = *(_DWORD *)a3;
	*(_DWORD *)a4 = *(_DWORD *)a3;
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	*(_DWORD *)&a4[a2] = v4;
	*(_DWORD *)&a4[2 * a2] = *(_DWORD *)&a3[2 * a2];
	result = *(_DWORD *)(&a3[2 * a2] + a2);
	*(_DWORD *)(&a4[2 * a2] + a2) = result;
	return result;
}

//----- (0045C891) --------------------------------------------------------
int __usercall sub_45C891@<eax>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int result; // eax@1

	*(_DWORD *)a4 = *(_DWORD *)a3;
	v4 = *(_DWORD *)&a3[a2];
	*(_DWORD *)&a4[a2] = v4;
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	*(_DWORD *)&a4[2 * a2] = v4;
	result = *(_DWORD *)(&a3[2 * a2] + a2);
	*(_DWORD *)(&a4[2 * a2] + a2) = result;
	return result;
}

//----- (0045C8B6) --------------------------------------------------------
__int16 __usercall sub_45C8B6@<ax>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1

	v4 = *(_DWORD *)a3;
	BYTE1(v4) = a1;
	*(_DWORD *)a4 = v4;
	v5 = *(_DWORD *)&a3[a2];
	BYTE1(v5) = a1;
	*(_DWORD *)&a4[a2] = v5;
	v6 = *(_DWORD *)&a3[2 * a2];
	BYTE1(v6) = a1;
	*(_DWORD *)&a4[2 * a2] = v6;
	v7 = *(_DWORD *)(&a3[2 * a2] + a2);
	BYTE1(v7) = a1;
	*(_DWORD *)(&a4[2 * a2] + a2) = v7;
	return v7;
}

//----- (0045C8DB) --------------------------------------------------------
int __usercall sub_45C8DB@<eax>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1
	int result; // eax@1

	v4 = __ROR4__(*(_DWORD *)a3, 16);
	LOBYTE_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	*(_DWORD *)a4 = v4;
	v5 = __ROR4__(*(_DWORD *)&a3[a2], 16);
	LOBYTE_HEXRAYS(v5) = a1;
	v5 = __ROR4__(v5, 16);
	*(_DWORD *)&a4[a2] = v5;
	v6 = __ROR4__(*(_DWORD *)&a3[2 * a2], 16);
	LOBYTE_HEXRAYS(v6) = a1;
	v6 = __ROR4__(v6, 16);
	*(_DWORD *)&a4[2 * a2] = v6;
	v7 = __ROR4__(*(_DWORD *)(&a3[2 * a2] + a2), 16);
	LOBYTE_HEXRAYS(v7) = a1;
	result = __ROR4__(v7, 16);
	*(_DWORD *)(&a4[2 * a2] + a2) = result;
	return result;
}

//----- (0045C918) --------------------------------------------------------
__int16 __usercall sub_45C918@<ax>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	*(_DWORD *)a4 = *(_DWORD *)a3;
	v4 = *(_DWORD *)&a3[a2];
	*(_DWORD *)&a4[a2] = v4;
	BYTE1(v4) = a3[2 * a2 + 3];
	LOBYTE_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a3[2 * a2];
	*(_DWORD *)&a4[2 * a2] = v4;
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a1;
	BYTE1(v5) = a1;
	*(_DWORD *)(&a4[2 * a2] + a2) = v5;
	return v5;
}

//----- (0045C948) --------------------------------------------------------
int __usercall sub_45C948@<eax>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int result; // eax@1

	v4 = __ROR4__(*(_DWORD *)a3, 16);
	BYTE1(v4) = a1;
	v4 = __ROR4__(v4, 16);
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = *(_WORD *)&a3[a2];
	*(_DWORD *)&a4[a2] = v4;
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = *(_WORD *)&a3[2 * a2];
	*(_DWORD *)&a4[2 * a2] = v4;
	v5 = __ROR4__(*(_DWORD *)(&a3[2 * a2] + a2), 16);
	BYTE1(v5) = a1;
	result = __ROR4__(v5, 16);
	*(_DWORD *)(&a4[2 * a2] + a2) = result;
	return result;
}

//----- (0045C985) --------------------------------------------------------
int __usercall sub_45C985@<eax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int result; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = *(_BYTE *)(a3 + a4 + 3);
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a3 + a4);
	*(_DWORD *)&a5[a3] = v5;
	*(_DWORD *)&a5[2 * a3] = *(_DWORD *)(a4 + 2 * a3);
	result = *(_DWORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = result;
	return result;
}

//----- (0045C9B6) --------------------------------------------------------
char __usercall sub_45C9B6@<al>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	v4 = *(_DWORD *)a3;
	LOBYTE_HEXRAYS(v4) = a1;
	*(_DWORD *)a4 = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)&a3[a2 + 2];
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	*(_DWORD *)&a4[a2] = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)&a3[2 * a2 + 2];
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	*(_DWORD *)&a4[2 * a2] = v4;
	v5 = *(_DWORD *)(&a3[2 * a2] + a2);
	LOBYTE_HEXRAYS(v5) = a1;
	*(_DWORD *)(&a4[2 * a2] + a2) = v5;
	return v5;
}

//----- (0045C9E9) --------------------------------------------------------
char __usercall sub_45C9E9@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, char *a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1
	int v8; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)a4;
	*(_DWORD *)a5 = v5;
	v6 = __ROR4__(*(_DWORD *)&a4[a3], 16);
	BYTE1(v6) = a2;
	v6 = __ROR4__(v6, 16);
	*(_DWORD *)&a5[a3] = v6;
	v7 = *(_DWORD *)&a4[2 * a3];
	LOBYTE_HEXRAYS(v7) = a2;
	*(_DWORD *)&a5[2 * a3] = v7;
	LOWORD_HEXRAYS(v7) = *(_WORD *)(&a4[2 * a3 + 2] + a3);
	v8 = __ROR4__(v7, 16);
	BYTE1(v8) = a2;
	LOBYTE_HEXRAYS(v8) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v8;
	return v8;
}

//----- (0045CA21) --------------------------------------------------------
__int16 __usercall sub_45CA21@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1
	int v8; // eax@1

	LOWORD_HEXRAYS(a1) = *(_WORD *)(a4 + 2);
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	v6 = *(_DWORD *)(a3 + a4);
	LOBYTE_HEXRAYS(v6) = a2;
	*(_DWORD *)&a5[a3] = v6;
	v7 = __ROR4__(*(_DWORD *)(a4 + 2 * a3), 16);
	BYTE1(v7) = a2;
	v7 = __ROR4__(v7, 16);
	*(_DWORD *)&a5[2 * a3] = v7;
	BYTE1(v7) = a2;
	LOBYTE_HEXRAYS(v7) = a2;
	v8 = __ROR4__(v7, 16);
	LOWORD_HEXRAYS(v8) = *(_WORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = v8;
	return v8;
}

//----- (0045CA59) --------------------------------------------------------
char __usercall sub_45CA59@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, char *a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)a4;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)&a4[a3];
	*(_DWORD *)&a5[a3] = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)&a4[2 * a3 + 2];
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(&a4[2 * a3 + 2] + a3);
	v6 = __ROR4__(v5, 16);
	BYTE1(v6) = a2;
	LOBYTE_HEXRAYS(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045CA98) --------------------------------------------------------
char __usercall sub_45CA98@<al>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	char *v5; // edi@1
	int v6; // eax@1

	*(_DWORD *)a4 = *(_DWORD *)a3;
	v4 = *(_DWORD *)&a3[a2];
	*(_DWORD *)&a4[a2] = v4;
	BYTE1(v4) = a3[2 * a2 + 3];
	LOBYTE_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a3[2 * a2];
	*(_DWORD *)&a4[2 * a2] = v4;
	v5 = &a3[a2];
	BYTE1(v4) = v5[2 * a2 + 3];
	LOBYTE_HEXRAYS(v4) = a1;
	v6 = __ROR4__(v4, 16);
	BYTE1(v6) = a1;
	LOBYTE_HEXRAYS(v6) = v5[2 * a2];
	*(_DWORD *)(&a4[2 * a2] + a2) = v6;
	return v6;
}

//----- (0045CACB) --------------------------------------------------------
int __usercall sub_45CACB@<eax>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int result; // eax@1

	v4 = *(_DWORD *)a3;
	*(_DWORD *)a4 = *(_DWORD *)a3;
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = *(_WORD *)&a3[a2];
	*(_DWORD *)&a4[a2] = v4;
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = *(_WORD *)&a3[2 * a2];
	*(_DWORD *)&a4[2 * a2] = v4;
	result = *(_DWORD *)(&a3[2 * a2] + a2);
	*(_DWORD *)(&a4[2 * a2] + a2) = result;
	return result;
}

//----- (0045CAF8) --------------------------------------------------------
int __usercall sub_45CAF8@<eax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int result; // eax@1

	BYTE1(a1) = *(_BYTE *)(a4 + 3);
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)a4;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = *(_BYTE *)(a3 + a4 + 3);
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a3 + a4);
	*(_DWORD *)&a5[a3] = v5;
	*(_DWORD *)&a5[2 * a3] = *(_DWORD *)(a4 + 2 * a3);
	result = *(_DWORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = result;
	return result;
}

//----- (0045CB2A) --------------------------------------------------------
int __usercall sub_45CB2A@<eax>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int result; // eax@1

	v4 = *(_DWORD *)a3;
	*(_DWORD *)a4 = *(_DWORD *)a3;
	LOWORD_HEXRAYS(v4) = *(_WORD *)&a3[a2 + 2];
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	*(_DWORD *)&a4[a2] = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)&a3[2 * a2 + 2];
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	*(_DWORD *)&a4[2 * a2] = v4;
	result = *(_DWORD *)(&a3[2 * a2] + a2);
	*(_DWORD *)(&a4[2 * a2] + a2) = result;
	return result;
}

//----- (0045CB59) --------------------------------------------------------
__int16 __usercall sub_45CB59@<ax>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	*(_DWORD *)a4 = *(_DWORD *)a3;
	v4 = *(_DWORD *)&a3[a2];
	*(_DWORD *)&a4[a2] = v4;
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a3[2 * a2 + 2];
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a3[2 * a2 + 1];
	LOBYTE_HEXRAYS(v4) = a1;
	*(_DWORD *)&a4[2 * a2] = v4;
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a1;
	BYTE1(v5) = a1;
	*(_DWORD *)(&a4[2 * a2] + a2) = v5;
	return v5;
}

//----- (0045CB8A) --------------------------------------------------------
__int16 __usercall sub_45CB8A@<ax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, char *a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1
	int v8; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)a4;
	*(_DWORD *)a5 = v5;
	v6 = __ROR4__(*(_DWORD *)&a4[a3], 16);
	BYTE1(v6) = a2;
	v6 = __ROR4__(v6, 16);
	*(_DWORD *)&a5[a3] = v6;
	v7 = __ROR4__(*(_DWORD *)&a4[2 * a3], 16);
	BYTE1(v7) = a2;
	v7 = __ROR4__(v7, 16);
	*(_DWORD *)&a5[2 * a3] = v7;
	BYTE1(v7) = a2;
	LOBYTE_HEXRAYS(v7) = a2;
	v8 = __ROR4__(v7, 16);
	LOWORD_HEXRAYS(v8) = *(_WORD *)(&a4[2 * a3] + a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = v8;
	return v8;
}

//----- (0045CBC7) --------------------------------------------------------
int __usercall sub_45CBC7@<eax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int result; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a3 + a4 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = *(_BYTE *)(a3 + a4 + 1);
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	*(_DWORD *)&a5[2 * a3] = *(_DWORD *)(a4 + 2 * a3);
	result = *(_DWORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = result;
	return result;
}

//----- (0045CBF9) --------------------------------------------------------
char __usercall sub_45CBF9@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1
	int v8; // eax@1

	LOWORD_HEXRAYS(a1) = *(_WORD *)(a4 + 2);
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	v6 = *(_DWORD *)(a3 + a4);
	LOBYTE_HEXRAYS(v6) = a2;
	*(_DWORD *)&a5[a3] = v6;
	v7 = *(_DWORD *)(a4 + 2 * a3);
	LOBYTE_HEXRAYS(v7) = a2;
	*(_DWORD *)&a5[2 * a3] = v7;
	LOWORD_HEXRAYS(v7) = *(_WORD *)(a3 + a4 + 2 * a3 + 2);
	v8 = __ROR4__(v7, 16);
	BYTE1(v8) = a2;
	LOBYTE_HEXRAYS(v8) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v8;
	return v8;
}

//----- (0045CC2C) --------------------------------------------------------
char __usercall sub_45CC2C@<al>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	char *v5; // edi@1
	int v6; // eax@1

	*(_DWORD *)a4 = *(_DWORD *)a3;
	*(_DWORD *)&a4[a2] = *(_DWORD *)&a3[a2];
	v4 = *(_DWORD *)&a3[2 * a2];
	*(_DWORD *)&a4[2 * a2] = v4;
	v5 = &a3[a2];
	BYTE1(v4) = v5[2 * a2 + 3];
	LOBYTE_HEXRAYS(v4) = a1;
	v6 = __ROR4__(v4, 16);
	BYTE1(v6) = a1;
	LOBYTE_HEXRAYS(v6) = v5[2 * a2];
	*(_DWORD *)(&a4[2 * a2] + a2) = v6;
	return v6;
}

//----- (0045CC54) --------------------------------------------------------
int __usercall sub_45CC54@<eax>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int result; // eax@1

	*(_DWORD *)a4 = *(_DWORD *)a3;
	v4 = __ROR4__(*(_DWORD *)&a3[a2], 16);
	BYTE1(v4) = a1;
	v4 = __ROR4__(v4, 16);
	*(_DWORD *)&a4[a2] = v4;
	v5 = __ROR4__(*(_DWORD *)&a3[2 * a2], 16);
	BYTE1(v5) = a1;
	v5 = __ROR4__(v5, 16);
	*(_DWORD *)&a4[2 * a2] = v5;
	result = *(_DWORD *)(&a3[2 * a2] + a2);
	*(_DWORD *)(&a4[2 * a2] + a2) = result;
	return result;
}

//----- (0045CC81) --------------------------------------------------------
int __usercall sub_45CC81@<eax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int result; // eax@1

	BYTE1(a1) = *(_BYTE *)(a4 + 3);
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)a4;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)&a5[a3] = *(_DWORD *)(a3 + a4);
	*(_DWORD *)&a5[2 * a3] = *(_DWORD *)(a4 + 2 * a3);
	result = *(_DWORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = result;
	return result;
}

//----- (0045CCA8) --------------------------------------------------------
int __usercall sub_45CCA8@<eax>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int result; // eax@1

	*(_DWORD *)a4 = *(_DWORD *)a3;
	v4 = *(_DWORD *)&a3[a2];
	LOBYTE_HEXRAYS(v4) = a1;
	*(_DWORD *)&a4[a2] = v4;
	v5 = *(_DWORD *)&a3[2 * a2];
	LOBYTE_HEXRAYS(v5) = a1;
	*(_DWORD *)&a4[2 * a2] = v5;
	result = *(_DWORD *)(&a3[2 * a2] + a2);
	*(_DWORD *)(&a4[2 * a2] + a2) = result;
	return result;
}

//----- (0045CCC9) --------------------------------------------------------
__int16 __usercall sub_45CCC9@<ax>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // eax@1

	v4 = __ROR4__(*(_DWORD *)a3, 16);
	BYTE1(v4) = a1;
	v4 = __ROR4__(v4, 16);
	*(_DWORD *)a4 = v4;
	v5 = __ROR4__(*(_DWORD *)&a3[a2], 16);
	BYTE1(v5) = a1;
	v5 = __ROR4__(v5, 16);
	*(_DWORD *)&a4[a2] = v5;
	BYTE1(v5) = a1;
	LOBYTE_HEXRAYS(v5) = a1;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)&a3[2 * a2];
	*(_DWORD *)&a4[2 * a2] = v5;
	BYTE1(v5) = a1;
	LOBYTE_HEXRAYS(v5) = a1;
	v6 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)(&a3[2 * a2] + a2);
	*(_DWORD *)(&a4[2 * a2] + a2) = v6;
	return v6;
}

//----- (0045CD06) --------------------------------------------------------
__int16 __usercall sub_45CD06@<ax>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	*(_DWORD *)a4 = *(_DWORD *)a3;
	v4 = *(_DWORD *)&a3[a2];
	*(_DWORD *)&a4[a2] = v4;
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = *(_WORD *)&a3[2 * a2];
	*(_DWORD *)&a4[2 * a2] = v4;
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a1;
	BYTE1(v5) = a1;
	*(_DWORD *)(&a4[2 * a2] + a2) = v5;
	return v5;
}

//----- (0045CD33) --------------------------------------------------------
int __usercall sub_45CD33@<eax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int result; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4);
	*(_DWORD *)&a5[a3] = v5;
	*(_DWORD *)&a5[2 * a3] = *(_DWORD *)(a4 + 2 * a3);
	result = *(_DWORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = result;
	return result;
}

//----- (0045CD61) --------------------------------------------------------
int __usercall sub_45CD61@<eax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, char *a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1
	int result; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)a4;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)&a4[a3];
	*(_DWORD *)&a5[a3] = v5;
	v6 = __ROR4__(*(_DWORD *)&a4[2 * a3], 16);
	BYTE1(v6) = a2;
	v6 = __ROR4__(v6, 16);
	*(_DWORD *)&a5[2 * a3] = v6;
	v7 = __ROR4__(*(_DWORD *)(&a4[2 * a3] + a3), 16);
	BYTE1(v7) = a2;
	result = __ROR4__(v7, 16);
	*(_DWORD *)(&a5[2 * a3] + a3) = result;
	return result;
}

//----- (0045CD9E) --------------------------------------------------------
int __usercall sub_45CD9E@<eax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int result; // eax@1

	LOBYTE_HEXRAYS(a1) = a2;
	BYTE1(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	*(_DWORD *)&a5[2 * a3] = *(_DWORD *)(a4 + 2 * a3);
	result = *(_DWORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = result;
	return result;
}

//----- (0045CDCD) --------------------------------------------------------
char __usercall sub_45CDCD@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1

	LOWORD_HEXRAYS(a1) = *(_WORD *)(a4 + 2);
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	v6 = *(_DWORD *)(a4 + 2 * a3);
	LOBYTE_HEXRAYS(v6) = a2;
	*(_DWORD *)&a5[2 * a3] = v6;
	v7 = *(_DWORD *)(a3 + a4 + 2 * a3);
	LOBYTE_HEXRAYS(v7) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v7;
	return v7;
}

//----- (0045CE00) --------------------------------------------------------
char __usercall sub_45CE00@<al>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // eax@1

	v4 = *(_DWORD *)a3;
	LOBYTE_HEXRAYS(v4) = a1;
	*(_DWORD *)a4 = v4;
	v5 = *(_DWORD *)&a3[a2];
	LOBYTE_HEXRAYS(v5) = a1;
	*(_DWORD *)&a4[a2] = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)&a3[2 * a2 + 2];
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a1;
	LOBYTE_HEXRAYS(v5) = a1;
	*(_DWORD *)&a4[2 * a2] = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(&a3[2 * a2 + 2] + a2);
	v6 = __ROR4__(v5, 16);
	BYTE1(v6) = a1;
	LOBYTE_HEXRAYS(v6) = a1;
	*(_DWORD *)(&a4[2 * a2] + a2) = v6;
	return v6;
}

//----- (0045CE33) --------------------------------------------------------
__int16 __usercall sub_45CE33@<ax>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	*(_DWORD *)a4 = *(_DWORD *)a3;
	v4 = *(_DWORD *)&a3[a2];
	*(_DWORD *)&a4[a2] = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)&a3[2 * a2 + 2];
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	*(_DWORD *)&a4[2 * a2] = v4;
	LOBYTE_HEXRAYS(v4) = a1;
	BYTE1(v4) = a1;
	v5 = __ROR4__(v4, 16);
	LOBYTE_HEXRAYS(v5) = a1;
	BYTE1(v5) = a1;
	*(_DWORD *)(&a4[2 * a2] + a2) = v5;
	return v5;
}

//----- (0045CE61) --------------------------------------------------------
char __usercall sub_45CE61@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // edi@1
	int v7; // eax@1

	BYTE1(a1) = *(_BYTE *)(a4 + 3);
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)a4;
	*(_DWORD *)a5 = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOBYTE_HEXRAYS(v5) = a2;
	BYTE1(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	v6 = a3 + a4;
	BYTE1(v5) = *(_BYTE *)(v6 + 2 * a3 + 3);
	LOBYTE_HEXRAYS(v5) = a2;
	v7 = __ROR4__(v5, 16);
	BYTE1(v7) = a2;
	LOBYTE_HEXRAYS(v7) = *(_BYTE *)(v6 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = v7;
	return v7;
}

//----- (0045CEA3) --------------------------------------------------------
int __usercall sub_45CEA3@<eax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = *(_WORD *)(a4 + 2);
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	v6 = *(_DWORD *)(a3 + a4);
	*(_DWORD *)&a5[a3] = v6;
	BYTE1(v6) = *(_BYTE *)(a4 + 2 * a3 + 3);
	LOBYTE_HEXRAYS(v6) = a2;
	v6 = __ROR4__(v6, 16);
	BYTE1(v6) = a2;
	LOBYTE_HEXRAYS(v6) = *(_BYTE *)(a4 + 2 * a3);
	*(_DWORD *)&a5[2 * a3] = v6;
	result = *(_DWORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = result;
	return result;
}

//----- (0045CED4) --------------------------------------------------------
int __usercall sub_45CED4@<eax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int result; // eax@1

	BYTE1(a1) = *(_BYTE *)(a4 + 3);
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)a4;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4);
	*(_DWORD *)&a5[a3] = v5;
	v6 = __ROR4__(*(_DWORD *)(a4 + 2 * a3), 16);
	BYTE1(v6) = a2;
	v6 = __ROR4__(v6, 16);
	*(_DWORD *)&a5[2 * a3] = v6;
	result = *(_DWORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = result;
	return result;
}

//----- (0045CF0B) --------------------------------------------------------
int __usercall sub_45CF0B@<eax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = *(_WORD *)(a4 + 2);
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = *(_BYTE *)(a3 + a4 + 3);
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)(a3 + a4);
	*(_DWORD *)&a5[a3] = v5;
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3);
	*(_DWORD *)&a5[2 * a3] = v5;
	v6 = __ROR4__(*(_DWORD *)(a3 + a4 + 2 * a3), 16);
	BYTE1(v6) = a2;
	result = __ROR4__(v6, 16);
	*(_DWORD *)(&a5[2 * a3] + a3) = result;
	return result;
}

//----- (0045CF4C) --------------------------------------------------------
__int16 __usercall sub_45CF4C@<ax>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	v4 = *(_DWORD *)a3;
	LOBYTE_HEXRAYS(v4) = a1;
	*(_DWORD *)a4 = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)&a3[a2 + 2];
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	*(_DWORD *)&a4[a2] = v4;
	BYTE1(v4) = a3[2 * a2 + 3];
	LOBYTE_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a3[2 * a2];
	*(_DWORD *)&a4[2 * a2] = v4;
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	v5 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(&a3[2 * a2] + a2);
	*(_DWORD *)(&a4[2 * a2] + a2) = v5;
	return v5;
}

//----- (0045CF87) --------------------------------------------------------
char __usercall sub_45CF87@<al>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	char *v5; // edi@1
	int v6; // eax@1

	*(_DWORD *)a4 = *(_DWORD *)a3;
	v4 = *(_DWORD *)&a3[a2];
	LOBYTE_HEXRAYS(v4) = a1;
	*(_DWORD *)&a4[a2] = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)&a3[2 * a2 + 2];
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	*(_DWORD *)&a4[2 * a2] = v4;
	v5 = &a3[a2];
	BYTE1(v4) = v5[2 * a2 + 3];
	LOBYTE_HEXRAYS(v4) = a1;
	v6 = __ROR4__(v4, 16);
	BYTE1(v6) = a1;
	LOBYTE_HEXRAYS(v6) = v5[2 * a2];
	*(_DWORD *)(&a4[2 * a2] + a2) = v6;
	return v6;
}

//----- (0045CFBA) --------------------------------------------------------
__int16 __usercall sub_45CFBA@<ax>(char a1@<dl>, int a2@<ecx>, _DWORD *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // eax@1

	v4 = *a3;
	*(_DWORD *)a4 = *a3;
	BYTE1(v4) = *((_BYTE *)a3 + a2 + 3);
	LOBYTE_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = *((_BYTE *)a3 + a2);
	*(_DWORD *)&a4[a2] = v4;
	v5 = *(_DWORD *)((char *)a3 + 2 * a2);
	*(_DWORD *)&a4[2 * a2] = v5;
	BYTE1(v5) = a1;
	LOBYTE_HEXRAYS(v5) = a1;
	v6 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)((char *)a3 + 2 * a2 + a2);
	*(_DWORD *)(&a4[2 * a2] + a2) = v6;
	return v6;
}

//----- (0045CFEA) --------------------------------------------------------
int __usercall sub_45CFEA@<eax>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int result; // eax@1

	BYTE1(a1) = *(_BYTE *)(a4 + 3);
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *(_BYTE *)a4;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2);
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[a3] = v5;
	v6 = *(_DWORD *)(a4 + 2 * a3);
	LOBYTE_HEXRAYS(v6) = a2;
	*(_DWORD *)&a5[2 * a3] = v6;
	result = *(_DWORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(&a5[2 * a3] + a3) = result;
	return result;
}

//----- (0045D01C) --------------------------------------------------------
char __usercall sub_45D01C@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, _WORD *a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = *a4;
	*(_DWORD *)a5 = v5;
	BYTE1(v5) = *((_BYTE *)a4 + a3 + 3);
	LOBYTE_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = *((_BYTE *)a4 + a3);
	*(_DWORD *)&a5[a3] = v5;
	LOWORD_HEXRAYS(v5) = a4[a3 + 1];
	v5 = __ROR4__(v5, 16);
	BYTE1(v5) = a2;
	LOBYTE_HEXRAYS(v5) = a2;
	*(_DWORD *)&a5[2 * a3] = v5;
	v6 = *(_DWORD *)((char *)&a4[a3] + a3);
	LOBYTE_HEXRAYS(v6) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v6;
	return v6;
}

//----- (0045D057) --------------------------------------------------------
char __usercall sub_45D057@<al>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1

	v4 = __ROR4__(*(_DWORD *)a3, 16);
	BYTE1(v4) = a1;
	v4 = __ROR4__(v4, 16);
	*(_DWORD *)a4 = v4;
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = *(_WORD *)&a3[a2];
	*(_DWORD *)&a4[a2] = v4;
	BYTE1(v4) = a3[2 * a2 + 3];
	LOBYTE_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a3[2 * a2];
	*(_DWORD *)&a4[2 * a2] = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)(&a3[2 * a2 + 2] + a2);
	v5 = __ROR4__(v4, 16);
	BYTE1(v5) = a1;
	LOBYTE_HEXRAYS(v5) = a1;
	*(_DWORD *)(&a4[2 * a2] + a2) = v5;
	return v5;
}

//----- (0045D098) --------------------------------------------------------
char __usercall sub_45D098@<al>(char a1@<dl>, int a2@<ecx>, char *a3@<edi>, char *a4@<esi>)
{
	int v4; // eax@1
	char *v5; // edi@1
	int v6; // eax@1

	*(_DWORD *)a4 = *(_DWORD *)a3;
	v4 = __ROR4__(*(_DWORD *)&a3[a2], 16);
	BYTE1(v4) = a1;
	v4 = __ROR4__(v4, 16);
	*(_DWORD *)&a4[a2] = v4;
	BYTE1(v4) = a1;
	LOBYTE_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = *(_WORD *)&a3[2 * a2];
	*(_DWORD *)&a4[2 * a2] = v4;
	v5 = &a3[a2];
	BYTE1(v4) = v5[2 * a2 + 3];
	LOBYTE_HEXRAYS(v4) = a1;
	v6 = __ROR4__(v4, 16);
	BYTE1(v6) = a1;
	LOBYTE_HEXRAYS(v6) = v5[2 * a2];
	*(_DWORD *)(&a4[2 * a2] + a2) = v6;
	return v6;
}

//----- (0045D0D0) --------------------------------------------------------
char __usercall sub_45D0D0@<al>(int a1@<eax>, char a2@<dl>, int a3@<ecx>, char *a4@<edi>, char *a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1
	int v8; // eax@1

	BYTE1(a1) = a2;
	LOBYTE_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)a4;
	*(_DWORD *)a5 = v5;
	v6 = __ROR4__(*(_DWORD *)&a4[a3], 16);
	LOBYTE_HEXRAYS(v6) = a2;
	v6 = __ROR4__(v6, 16);
	*(_DWORD *)&a5[a3] = v6;
	v7 = *(_DWORD *)&a4[2 * a3];
	BYTE1(v7) = a2;
	*(_DWORD *)&a5[2 * a3] = v7;
	LOWORD_HEXRAYS(v7) = *(_WORD *)(&a4[2 * a3 + 2] + a3);
	v8 = __ROR4__(v7, 16);
	BYTE1(v8) = a2;
	LOBYTE_HEXRAYS(v8) = a2;
	*(_DWORD *)(&a5[2 * a3] + a3) = v8;
	return v8;
}

//----- (0045D108) --------------------------------------------------------
int __usercall sub_45D108@<eax>(int a1@<ecx>, int a2@<esi>)
{
	int v2; // edi@1
	int v3; // esi@1
	int v4; // esi@1
	int v5; // esi@1
	int result; // eax@1

	v2 = dword_476DD8;
	*(_DWORD *)a2 = *(_DWORD *)(dword_476DD8 + a2);
	*(_DWORD *)(a2 + 4) = *(_DWORD *)(v2 + a2 + 4);
	v3 = a1 + a2;
	*(_DWORD *)v3 = *(_DWORD *)(v2 + v3);
	*(_DWORD *)(v3 + 4) = *(_DWORD *)(v2 + v3 + 4);
	v4 = a1 + v3;
	*(_DWORD *)v4 = *(_DWORD *)(v2 + v4);
	*(_DWORD *)(v4 + 4) = *(_DWORD *)(v2 + v4 + 4);
	v5 = a1 + v4;
	*(_DWORD *)v5 = *(_DWORD *)(v2 + v5);
	result = *(_DWORD *)(v2 + v5 + 4);
	*(_DWORD *)(v5 + 4) = result;
	return result;
}
// 476DD8: using guessed type int dword_476DD8;

//----- (0045D147) --------------------------------------------------------
int __usercall sub_45D147@<eax>(int a1@<ecx>, char *a2@<ebx>, int a3@<esi>)
{
	char v3; // al@1
	char *v4; // ebx@1
	int v5; // edi@2
	int v6; // esi@2
	int v7; // esi@2
	int v8; // esi@2
	int result; // eax@2
	int v10; // edi@3

	v3 = *a2;
	v4 = a2 + 1;
	if (v3)
	{
		v5 = dword_476DD8 + *(_DWORD *)(dword_476DDC + 4 * (unsigned __int8)v3);
		*(_DWORD *)a3 = *(_DWORD *)(v5 + a3);
		*(_DWORD *)(a3 + 4) = *(_DWORD *)(v5 + a3 + 4);
		v6 = a1 + a3;
		*(_DWORD *)v6 = *(_DWORD *)(v5 + v6);
		*(_DWORD *)(v6 + 4) = *(_DWORD *)(v5 + v6 + 4);
		v7 = a1 + v6;
		*(_DWORD *)v7 = *(_DWORD *)(v5 + v7);
		*(_DWORD *)(v7 + 4) = *(_DWORD *)(v5 + v7 + 4);
		v8 = a1 + v7;
		*(_DWORD *)v8 = *(_DWORD *)(v5 + v8);
		result = *(_DWORD *)(v5 + v8 + 4);
		*(_DWORD *)(v8 + 4) = result;
	}
	else
	{
		v10 = 4;
		do
		{
			*(_DWORD *)a3 = *(_DWORD *)v4;
			result = *((_DWORD *)v4 + 1);
			*(_DWORD *)(a3 + 4) = result;
			a3 += a1;
			v4 += 8;
			--v10;
		} while (v10);
	}
	return result;
}
// 476DD8: using guessed type int dword_476DD8;
// 476DDC: using guessed type int dword_476DDC;

//----- (0045D25B) --------------------------------------------------------
void __usercall sub_45D25B(__int16 *a1@<ebx>)
{
	__int16 v1; // ax@1
	__int16 v2; // ax@1

	v1 = *a1;
	v2 = *a1;
	JUMPOUT(loc_45D267);
}

//----- (0045D288) --------------------------------------------------------
__int16 __usercall sub_45D288@<ax>(int a1@<eax>, int a2@<ecx>, _WORD *a3@<ebx>, int a4@<esi>)
{
	int v4; // edi@1
	int v5; // edi@1
	int v6; // ebx@1
	_WORD *v7; // ebx@1
	int v8; // eax@1

	v6 = *a3;
	LOWORD_HEXRAYS(v6) = 2 * v6;
	v7 = (_WORD *)(dword_476FE0 + v6);
	LOWORD_HEXRAYS(a1) = *v7;
	v8 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v8) = *v7;
	*(_DWORD *)a4 = v8;
	*(_DWORD *)(a4 + 4) = v8;
	*(_DWORD *)(a2 + a4) = v8;
	*(_DWORD *)(a2 + a4 + 4) = v8;
	v4 = 2 * a2;
	*(_DWORD *)(v4 + a4) = v8;
	*(_DWORD *)(v4 + a4 + 4) = v8;
	v5 = 3 * a2;
	*(_DWORD *)(v5 + a4) = v8;
	*(_DWORD *)(v5 + a4 + 4) = v8;
	return v8;
}
// 476FE0: using guessed type int dword_476FE0;

//----- (0045D2A4) --------------------------------------------------------
void __usercall sub_45D2A4(_BYTE *a1@<ebx>)
{
	int v1; // ebx@1
	__int16 v2; // ax@1
	__int16 v3; // ax@1

	v1 = *a1;
	v2 = word_476DE0[v1];
	v3 = word_476DE0[v1];
	JUMPOUT(&loc_45D267);
}
// 476DE0: using guessed type __int16 word_476DE0[];

//----- (0045D2C1) --------------------------------------------------------
int __usercall sub_45D2C1@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<ebx>)
{
	int v3; // eax@1
	int v4; // edx@2
	int result; // eax@2
	int v6; // edx@3

	v3 = *(_BYTE *)a3;
	if (v3 & 0xC0)
	{
		LOWORD_HEXRAYS(a1) = *(_WORD *)(a3 + 1);
		v6 = __ROL4__(a1, 16);
		LOWORD_HEXRAYS(v6) = *(_WORD *)(a3 + 1);
		result = ((int(*)(int, int))off_476FE4[v3])(a2, v6);
	}
	else
	{
		LOWORD_HEXRAYS(a1) = *(_WORD *)(a3 + 3);
		v4 = __ROL4__(a1, 16);
		LOWORD_HEXRAYS(v4) = *(_WORD *)(a3 + 1);
		result = ((int(*)(int, int))off_476FE4[v3])(a2, v4);
	}
	return result;
}
// 476DD8: using guessed type int dword_476DD8;
// 476FE4: using guessed type int (*off_476FE4[196])();

//----- (0045D2FE) --------------------------------------------------------
int __usercall sub_45D2FE@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<ebx>)
{
	int v3; // eax@1
	int v4; // edx@2
	int result; // eax@2
	int v6; // eax@3
	int v7; // edx@3

	v3 = *(_BYTE *)a3;
	if (v3 & 0xC0)
	{
		v6 = *(_WORD *)(a3 + 1);
		LOWORD_HEXRAYS(a1) = *(_WORD *)(dword_476FE0 + 2 * v6);
		v7 = __ROL4__(a1, 16);
		LOWORD_HEXRAYS(v7) = *(_WORD *)(dword_476FE0 + 2 * v6);
		result = ((int(*)(int, int))off_476FE4[*(_BYTE *)a3])(a2, v7);
	}
	else
	{
		LOWORD_HEXRAYS(a1) = *(_WORD *)(dword_476FE0 + 2 * *(_WORD *)(a3 + 3));
		v4 = __ROL4__(a1, 16);
		LOWORD_HEXRAYS(v4) = *(_WORD *)(dword_476FE0 + 2 * *(_WORD *)(a3 + 1));
		result = ((int(*)(int, int))off_476FE4[v3])(a2, v4);
	}
	return result;
}
// 476DD8: using guessed type int dword_476DD8;
// 476FE0: using guessed type int dword_476FE0;
// 476FE4: using guessed type int (*off_476FE4[196])();

//----- (0045D35B) --------------------------------------------------------
int __usercall sub_45D35B@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<ebx>)
{
	int v3; // eax@1
	int v4; // edx@2
	int result; // eax@2
	int v6; // eax@3
	int v7; // edx@3

	v3 = *(_BYTE *)a3;
	if (v3 & 0xC0)
	{
		v6 = *(_BYTE *)(a3 + 1);
		LOWORD_HEXRAYS(a1) = word_476DE0[v6];
		v7 = __ROL4__(a1, 16);
		LOWORD_HEXRAYS(v7) = word_476DE0[v6];
		result = ((int(*)(int, int))off_476FE4[*(_BYTE *)a3])(a2, v7);
	}
	else
	{
		LOWORD_HEXRAYS(a1) = word_476DE0[*(_BYTE *)(a3 + 2)];
		v4 = __ROL4__(a1, 16);
		LOWORD_HEXRAYS(v4) = word_476DE0[*(_BYTE *)(a3 + 1)];
		result = ((int(*)(int, int))off_476FE4[v3])(a2, v4);
	}
	return result;
}
// 476DD8: using guessed type int dword_476DD8;
// 476DE0: using guessed type __int16 word_476DE0[];
// 476FE4: using guessed type int (*off_476FE4[196])();

//----- (0045D3B8) --------------------------------------------------------
_BYTE *sub_45D3B8(unsigned __int16 a1, __int16 a2, _BYTE *a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
	int v9; // esi@6
	_BYTE *v10; // ebx@6
	int v11; // eax@6
	int v12; // ecx@6
	int v13; // eax@8
	int v14; // ST0C_4@8
	int v15; // eax@8
	int v16; // eax@8
	int v17; // esi@8
	int v18; // eax@8
	int v19; // ecx@8
	int v21; // [sp+10h] [bp-8h]@6
	__int16 v22; // [sp+16h] [bp-2h]@7

	if (a9 == 1)
	{
		off_4772E8[0] = (int(*)())&loc_45D1A4;
		off_4772EC[0] = (int(*)())sub_45D2A4;
		off_4772F0 = (int(*)())sub_45D35B;
	}
	else if (a9 == 2)
	{
		off_4772E8[0] = (int(*)())&loc_45D19B;
		off_4772EC[0] = (int(*)())sub_45D288;
		off_4772F0 = (int(*)())sub_45D2FE;
	}
	else
	{
		off_4772E8[0] = (int(*)())sub_45D147;
		off_4772EC[0] = (int(*)())sub_45D25B;
		off_4772F0 = (int(*)())sub_45D2C1;
	}
	dword_476DDC = a8;
	dword_476DD8 = 2 * a6 + a5 - a4;
	v9 = a4;
	v10 = a3;
	v11 = a1;
	LOWORD_HEXRAYS(v11) = 24 * a1;
	v21 = v11;
	v12 = 2 * a7;
	do
	{
		v22 = a1 >> 2;
		do
		{
			v13 = *v10;
			v14 = v13;
			++v10;
			LOBYTE_HEXRAYS(v13) = (unsigned __int8)(v13 & 0xC0) >> 4;
			(*(void(__thiscall **)(int))((char *)off_4772E4 + v13))(v12);
			v15 = v14;
			LOBYTE_HEXRAYS(v15) = (unsigned __int8)(v14 & 0x30) >> 2;
			(*(int(**)())((char *)off_4772E4 + v15))();
			v16 = v14;
			LOBYTE_HEXRAYS(v16) = v14 & 0xC;
			(*(int(**)())((char *)off_4772E4 + v16))();
			v17 = v9 + 24;
			v18 = v14;
			LOBYTE_HEXRAYS(v18) = v14 & 3;
			((void (__usercall *)(int@<ecx>, int@<esi>))off_4772E4[v18])(v19, v17);
			v9 = v17 + 8;
			--v22;
		} while (v22);
		v9 += v21;
		--a2;
	} while (a2);
	return v10;
}
// 476DD8: using guessed type int dword_476DD8;
// 476DDC: using guessed type int dword_476DDC;
// 4772E4: using guessed type int (*off_4772E4[4])();
// 4772E8: using guessed type int (*off_4772E8[3])();
// 4772EC: using guessed type int (*off_4772EC[2])();
// 4772F0: using guessed type int (*off_4772F0)();

//----- (0045D4D0) --------------------------------------------------------
__int16 __usercall sub_45D4D0@<ax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	*(_DWORD *)(a4 + 4) = v4;
	v5 = __ROL4__(a2, 16);
	*(_DWORD *)(a3 + a4 + 4) = v5;
	*(_DWORD *)(a3 + a4) = a2;
	v6 = __ROL4__(a2, 16);
	*(_DWORD *)(a4 + 2 * a3 + 4) = v6;
	*(_DWORD *)(a4 + 2 * a3) = a2;
	v7 = a3 + a4;
	v8 = __ROR4__(a2, 16);
	LOWORD_HEXRAYS(v8) = a2;
	*(_DWORD *)(v7 + 2 * a3) = v8;
	*(_DWORD *)(v7 + 2 * a3 + 4) = v8;
	return v8;
}

//----- (0045D511) --------------------------------------------------------
int __usercall sub_45D511@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // edx@1
	int v6; // esi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a3 + a4) = v4;
	*(_DWORD *)(a3 + a4 + 4) = v4;
	HIWORD_HEXRAYS(v4) = HIWORD_HEXRAYS(a2);
	v5 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v4) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)(a4 + 2 * a3 + 4) = v4;
	*(_DWORD *)(a4 + 2 * a3) = v4;
	v6 = a3 + a4;
	HIWORD_HEXRAYS(result) = HIWORD_HEXRAYS(v5);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(result) = v5;
	*(_DWORD *)(v6 + 2 * a3 + 4) = result;
	*(_DWORD *)(v6 + 2 * a3) = result;
	return result;
}

//----- (0045D55A) --------------------------------------------------------
__int16 __usercall sub_45D55A@<ax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // edx@1
	int v5; // esi@1
	int v6; // eax@1

	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(a1);
	v4 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a3 + 4) = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROL4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)a3 = v3;
	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(v4);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a2 + a3 + 4) = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROL4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)(a2 + a3) = v3;
	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(v4);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a3 + 2 * a2 + 4) = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROL4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)(a3 + 2 * a2) = v3;
	v5 = a2 + a3;
	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(v4);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(v5 + 2 * a2 + 4) = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v6 = __ROL4__(v3, 16);
	LOWORD_HEXRAYS(v6) = v4;
	*(_DWORD *)(v5 + 2 * a2) = v6;
	return v6;
}

//----- (0045D5CB) --------------------------------------------------------
int __usercall sub_45D5CB@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // esi@1
	int v6; // edx@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a3 + a4) = v4;
	*(_DWORD *)(a3 + a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a4 + 2 * a3) = v4;
	*(_DWORD *)(a4 + 2 * a3 + 4) = v4;
	v5 = a3 + a4;
	HIWORD_HEXRAYS(result) = HIWORD_HEXRAYS(a2);
	v6 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(result) = v6;
	*(_DWORD *)(v5 + 2 * a3 + 4) = result;
	*(_DWORD *)(v5 + 2 * a3) = result;
	return result;
}

//----- (0045D612) --------------------------------------------------------
__int16 __usercall sub_45D612@<ax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // eax@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1

	*(_DWORD *)(a3 + 4) = a1;
	v3 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v3) = a1;
	*(_DWORD *)a3 = v3;
	*(_DWORD *)(a2 + a3 + 4) = a1;
	v4 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a2 + a3) = v4;
	*(_DWORD *)(a3 + 2 * a2 + 4) = a1;
	v5 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a3 + 2 * a2) = v5;
	v6 = a2 + a3;
	*(_DWORD *)(v6 + 2 * a2 + 4) = a1;
	v7 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v7) = a1;
	*(_DWORD *)(v6 + 2 * a2) = v7;
	return v7;
}

//----- (0045D65F) --------------------------------------------------------
__int16 __usercall sub_45D65F@<ax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // edx@1
	int v5; // esi@1
	int v6; // eax@1

	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(a1);
	v4 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a3 + 4) = v3;
	*(_DWORD *)a3 = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROR4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)(a2 + a3) = v3;
	*(_DWORD *)(a2 + a3 + 4) = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROR4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)(a3 + 2 * a2) = v3;
	*(_DWORD *)(a3 + 2 * a2 + 4) = v3;
	v5 = a2 + a3;
	LOWORD_HEXRAYS(v3) = v4;
	v6 = __ROR4__(v3, 16);
	LOWORD_HEXRAYS(v6) = v4;
	*(_DWORD *)(v5 + 2 * a2) = v6;
	*(_DWORD *)(v5 + 2 * a2 + 4) = v6;
	return v6;
}

//----- (0045D6A6) --------------------------------------------------------
int __usercall sub_45D6A6@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1
	int v8; // esi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a4 + 4) = v4;
	v5 = __ROL4__(a2, 16);
	*(_DWORD *)a4 = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a4 + 4) = v5;
	v6 = __ROL4__(a2, 16);
	*(_DWORD *)(a3 + a4) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a4 + 2 * a3 + 4) = v6;
	v7 = __ROL4__(a2, 16);
	*(_DWORD *)(a4 + 2 * a3) = v7;
	v8 = a3 + a4;
	LOWORD_HEXRAYS(v7) = a2;
	v7 = __ROR4__(v7, 16);
	LOWORD_HEXRAYS(v7) = a2;
	*(_DWORD *)(v8 + 2 * a3 + 4) = v7;
	result = __ROL4__(a2, 16);
	*(_DWORD *)(v8 + 2 * a3) = result;
	return result;
}

//----- (0045D6FF) --------------------------------------------------------
int __usercall sub_45D6FF@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // edx@1
	int v5; // esi@1
	int result; // eax@1

	*(_DWORD *)(a3 + 4) = a1;
	v3 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v3) = a1;
	*(_DWORD *)a3 = v3;
	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(a1);
	v4 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a2 + a3 + 4) = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROL4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)(a2 + a3) = v3;
	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(v4);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a3 + 2 * a2 + 4) = v3;
	*(_DWORD *)(a3 + 2 * a2) = v4;
	v5 = a2 + a3;
	HIWORD_HEXRAYS(result) = HIWORD_HEXRAYS(v4);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(result) = v4;
	*(_DWORD *)(v5 + 2 * a2 + 4) = result;
	*(_DWORD *)(v5 + 2 * a2) = result;
	return result;
}

//----- (0045D757) --------------------------------------------------------
__int16 __usercall sub_45D757@<ax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // edx@1
	int v5; // esi@1
	int v6; // eax@1

	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(a1);
	v4 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a3 + 4) = v3;
	*(_DWORD *)a3 = v3;
	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(v4);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a2 + a3 + 4) = v3;
	*(_DWORD *)(a2 + a3) = v4;
	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(v4);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a3 + 2 * a2 + 4) = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROL4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)(a3 + 2 * a2) = v3;
	v5 = a2 + a3;
	*(_DWORD *)(v5 + 2 * a2 + 4) = v4;
	v6 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v6) = v4;
	*(_DWORD *)(v5 + 2 * a2) = v6;
	return v6;
}

//----- (0045D7AF) --------------------------------------------------------
int __usercall sub_45D7AF@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // edx@1
	int v5; // eax@1
	int v6; // esi@1
	int result; // eax@1

	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(a1);
	v4 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a3 + 4) = v3;
	*(_DWORD *)a3 = v3;
	v5 = __ROL4__(v4, 16);
	*(_DWORD *)(a2 + a3 + 4) = v5;
	HIWORD_HEXRAYS(v5) = HIWORD_HEXRAYS(v4);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v5) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a2 + a3) = v5;
	LOWORD_HEXRAYS(v5) = v4;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = v4;
	*(_DWORD *)(a3 + 2 * a2 + 4) = v5;
	HIWORD_HEXRAYS(v5) = HIWORD_HEXRAYS(v4);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v5) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a3 + 2 * a2) = v5;
	v6 = a2 + a3;
	LOWORD_HEXRAYS(v5) = v4;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = v4;
	*(_DWORD *)(v6 + 2 * a2 + 4) = v5;
	result = __ROL4__(v4, 16);
	*(_DWORD *)(v6 + 2 * a2) = result;
	return result;
}

//----- (0045D80D) --------------------------------------------------------
int __usercall sub_45D80D@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // edx@1
	int v7; // eax@1
	int v8; // esi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a4 + 4) = v4;
	v5 = __ROL4__(a2, 16);
	*(_DWORD *)a4 = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a4 + 4) = v5;
	HIWORD_HEXRAYS(v5) = HIWORD_HEXRAYS(a2);
	v6 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v5) = v6;
	v6 = __ROL4__(v6, 16);
	*(_DWORD *)(a3 + a4) = v5;
	v7 = __ROL4__(v6, 16);
	*(_DWORD *)(a4 + 2 * a3 + 4) = v7;
	HIWORD_HEXRAYS(v7) = HIWORD_HEXRAYS(v6);
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v7) = v6;
	v6 = __ROL4__(v6, 16);
	*(_DWORD *)(a4 + 2 * a3) = v7;
	v8 = a3 + a4;
	HIWORD_HEXRAYS(result) = HIWORD_HEXRAYS(v6);
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(result) = v6;
	*(_DWORD *)(v8 + 2 * a3 + 4) = result;
	*(_DWORD *)(v8 + 2 * a3) = result;
	return result;
}

//----- (0045D86B) --------------------------------------------------------
__int16 __usercall sub_45D86B@<ax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // edx@1
	int v8; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a3 + a4) = v4;
	*(_DWORD *)(a3 + a4 + 4) = v4;
	*(_DWORD *)(a4 + 2 * a3 + 4) = a2;
	v5 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a4 + 2 * a3) = v5;
	v6 = a3 + a4;
	HIWORD_HEXRAYS(v5) = HIWORD_HEXRAYS(a2);
	v7 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v5) = v7;
	v7 = __ROL4__(v7, 16);
	*(_DWORD *)(v6 + 2 * a3 + 4) = v5;
	LOWORD_HEXRAYS(v5) = v7;
	v8 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v8) = v7;
	*(_DWORD *)(v6 + 2 * a3) = v8;
	return v8;
}

//----- (0045D8BD) --------------------------------------------------------
__int16 __usercall sub_45D8BD@<ax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // edx@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1

	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(a1);
	v4 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a3 + 4) = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROL4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)a3 = v3;
	*(_DWORD *)(a2 + a3 + 4) = v4;
	v5 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v5) = v4;
	*(_DWORD *)(a2 + a3) = v5;
	LOWORD_HEXRAYS(v5) = v4;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = v4;
	*(_DWORD *)(a3 + 2 * a2) = v5;
	*(_DWORD *)(a3 + 2 * a2 + 4) = v5;
	v6 = a2 + a3;
	LOWORD_HEXRAYS(v5) = v4;
	v7 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v7) = v4;
	*(_DWORD *)(v6 + 2 * a2) = v7;
	*(_DWORD *)(v6 + 2 * a2 + 4) = v7;
	return v7;
}

//----- (0045D90F) --------------------------------------------------------
__int16 __usercall sub_45D90F@<ax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // edx@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a4 + 4) = v4;
	HIWORD_HEXRAYS(v4) = HIWORD_HEXRAYS(a2);
	v5 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v4) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)a4 = v4;
	LOWORD_HEXRAYS(v4) = v5;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = v5;
	*(_DWORD *)(a3 + a4 + 4) = v4;
	v6 = __ROL4__(v5, 16);
	*(_DWORD *)(a3 + a4) = v6;
	LOWORD_HEXRAYS(v6) = v5;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = v5;
	*(_DWORD *)(a4 + 2 * a3) = v6;
	*(_DWORD *)(a4 + 2 * a3 + 4) = v6;
	v7 = a3 + a4;
	LOWORD_HEXRAYS(v6) = v5;
	v8 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v8) = v5;
	*(_DWORD *)(v7 + 2 * a3) = v8;
	*(_DWORD *)(v7 + 2 * a3 + 4) = v8;
	return v8;
}

//----- (0045D964) --------------------------------------------------------
int __usercall sub_45D964@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // edx@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a3 + a4) = v4;
	*(_DWORD *)(a3 + a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a4 + 2 * a3 + 4) = v4;
	v5 = __ROL4__(a2, 16);
	*(_DWORD *)(a4 + 2 * a3) = v5;
	v6 = a3 + a4;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(v6 + 2 * a3 + 4) = v5;
	HIWORD_HEXRAYS(result) = HIWORD_HEXRAYS(a2);
	v7 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(result) = v7;
	*(_DWORD *)(v6 + 2 * a3) = result;
	return result;
}

//----- (0045D9B9) --------------------------------------------------------
__int16 __usercall sub_45D9B9@<ax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // edx@1
	int v6; // esi@1
	int v7; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a3 + a4) = v4;
	*(_DWORD *)(a3 + a4 + 4) = v4;
	HIWORD_HEXRAYS(v4) = HIWORD_HEXRAYS(a2);
	v5 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v4) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)(a4 + 2 * a3 + 4) = v4;
	LOWORD_HEXRAYS(v4) = v5;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = v5;
	*(_DWORD *)(a4 + 2 * a3) = v4;
	v6 = a3 + a4;
	HIWORD_HEXRAYS(v4) = HIWORD_HEXRAYS(v5);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v4) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)(v6 + 2 * a3 + 4) = v4;
	LOWORD_HEXRAYS(v4) = v5;
	v7 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v7) = v5;
	*(_DWORD *)(v6 + 2 * a3) = v7;
	return v7;
}

//----- (0045DA14) --------------------------------------------------------
__int16 __usercall sub_45DA14@<ax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // edx@1
	int v5; // esi@1
	int v6; // eax@1

	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(a1);
	v4 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a3 + 4) = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROL4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)a3 = v3;
	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(v4);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a2 + a3 + 4) = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROL4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)(a2 + a3) = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROR4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)(a3 + 2 * a2) = v3;
	*(_DWORD *)(a3 + 2 * a2 + 4) = v3;
	v5 = a2 + a3;
	LOWORD_HEXRAYS(v3) = v4;
	v6 = __ROR4__(v3, 16);
	LOWORD_HEXRAYS(v6) = v4;
	*(_DWORD *)(v5 + 2 * a2) = v6;
	*(_DWORD *)(v5 + 2 * a2 + 4) = v6;
	return v6;
}

//----- (0045DA6F) --------------------------------------------------------
__int16 __usercall sub_45DA6F@<ax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // edx@1
	int v6; // esi@1
	int v7; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a4 + 4) = v4;
	HIWORD_HEXRAYS(v4) = HIWORD_HEXRAYS(a2);
	v5 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v4) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)a4 = v4;
	LOWORD_HEXRAYS(v4) = v5;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = v5;
	*(_DWORD *)(a3 + a4 + 4) = v4;
	HIWORD_HEXRAYS(v4) = HIWORD_HEXRAYS(v5);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v4) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)(a3 + a4) = v4;
	LOWORD_HEXRAYS(v4) = v5;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = v5;
	*(_DWORD *)(a4 + 2 * a3) = v4;
	*(_DWORD *)(a4 + 2 * a3 + 4) = v4;
	v6 = a3 + a4;
	LOWORD_HEXRAYS(v4) = v5;
	v7 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v7) = v5;
	*(_DWORD *)(v6 + 2 * a3) = v7;
	*(_DWORD *)(v6 + 2 * a3 + 4) = v7;
	return v7;
}

//----- (0045DACA) --------------------------------------------------------
int __usercall sub_45DACA@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // edx@1
	int v6; // esi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a3 + a4) = v4;
	*(_DWORD *)(a3 + a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a4 + 2 * a3 + 4) = v4;
	HIWORD_HEXRAYS(v4) = HIWORD_HEXRAYS(a2);
	v5 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v4) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)(a4 + 2 * a3) = v4;
	v6 = a3 + a4;
	LOWORD_HEXRAYS(v4) = v5;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = v5;
	*(_DWORD *)(v6 + 2 * a3 + 4) = v4;
	HIWORD_HEXRAYS(result) = HIWORD_HEXRAYS(v5);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(result) = v5;
	*(_DWORD *)(v6 + 2 * a3) = result;
	return result;
}

//----- (0045DB25) --------------------------------------------------------
__int16 __usercall sub_45DB25@<ax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // edx@1
	int v6; // esi@1
	int v7; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	*(_DWORD *)(a4 + 4) = v4;
	HIWORD_HEXRAYS(v4) = HIWORD_HEXRAYS(a2);
	v5 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v4) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)(a3 + a4 + 4) = v4;
	*(_DWORD *)(a3 + a4) = v4;
	HIWORD_HEXRAYS(v4) = HIWORD_HEXRAYS(v5);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v4) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)(a4 + 2 * a3 + 4) = v4;
	*(_DWORD *)(a4 + 2 * a3) = v4;
	v6 = a3 + a4;
	LOWORD_HEXRAYS(v4) = v5;
	v7 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v7) = v5;
	*(_DWORD *)(v6 + 2 * a3) = v7;
	*(_DWORD *)(v6 + 2 * a3 + 4) = v7;
	return v7;
}

//----- (0045DB6E) --------------------------------------------------------
int __usercall sub_45DB6E@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // eax@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1
	int result; // eax@1

	v3 = __ROL4__(a1, 16);
	*(_DWORD *)(a3 + 4) = v3;
	*(_DWORD *)a3 = a1;
	v4 = __ROL4__(a1, 16);
	*(_DWORD *)(a2 + a3 + 4) = v4;
	*(_DWORD *)(a2 + a3) = a1;
	v5 = __ROL4__(a1, 16);
	*(_DWORD *)(a3 + 2 * a2 + 4) = v5;
	*(_DWORD *)(a3 + 2 * a2) = a1;
	v6 = a2 + a3;
	v7 = __ROL4__(a1, 16);
	*(_DWORD *)(v6 + 2 * a2 + 4) = v7;
	result = a1;
	*(_DWORD *)(v6 + 2 * a2) = a1;
	return result;
}

//----- (0045DBAB) --------------------------------------------------------
__int16 __usercall sub_45DBAB@<ax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // edx@1
	int v6; // esi@1
	int v7; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	*(_DWORD *)(a4 + 4) = v4;
	HIWORD_HEXRAYS(v4) = HIWORD_HEXRAYS(a2);
	v5 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v4) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)(a3 + a4 + 4) = v4;
	*(_DWORD *)(a3 + a4) = v4;
	LOWORD_HEXRAYS(v4) = v5;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = v5;
	*(_DWORD *)(a4 + 2 * a3) = v4;
	*(_DWORD *)(a4 + 2 * a3 + 4) = v4;
	v6 = a3 + a4;
	LOWORD_HEXRAYS(v4) = v5;
	v7 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v7) = v5;
	*(_DWORD *)(v6 + 2 * a3) = v7;
	*(_DWORD *)(v6 + 2 * a3 + 4) = v7;
	return v7;
}

//----- (0045DBF2) --------------------------------------------------------
__int16 __usercall sub_45DBF2@<ax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // edx@1
	int v6; // esi@1
	int v7; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a3 + a4) = v4;
	*(_DWORD *)(a3 + a4 + 4) = v4;
	HIWORD_HEXRAYS(v4) = HIWORD_HEXRAYS(a2);
	v5 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v4) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)(a4 + 2 * a3 + 4) = v4;
	*(_DWORD *)(a4 + 2 * a3) = v4;
	v6 = a3 + a4;
	LOWORD_HEXRAYS(v4) = v5;
	v7 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v7) = v5;
	*(_DWORD *)(v6 + 2 * a3) = v7;
	*(_DWORD *)(v6 + 2 * a3 + 4) = v7;
	return v7;
}

//----- (0045DC39) --------------------------------------------------------
int __usercall sub_45DC39@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // eax@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a4 + 4) = v4;
	*(_DWORD *)a4 = a2;
	v5 = __ROR4__(a2, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a4 + 4) = v5;
	*(_DWORD *)(a3 + a4) = a2;
	v6 = __ROR4__(a2, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a4 + 2 * a3 + 4) = v6;
	*(_DWORD *)(a4 + 2 * a3) = a2;
	v7 = a3 + a4;
	v8 = __ROR4__(a2, 16);
	LOWORD_HEXRAYS(v8) = a2;
	*(_DWORD *)(v7 + 2 * a3 + 4) = v8;
	result = a2;
	*(_DWORD *)(v7 + 2 * a3) = a2;
	return result;
}

//----- (0045DC86) --------------------------------------------------------
__int16 __usercall sub_45DC86@<ax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // eax@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1
	int v8; // eax@1

	v3 = __ROL4__(a1, 16);
	*(_DWORD *)(a3 + 4) = v3;
	LOWORD_HEXRAYS(v3) = a1;
	v3 = __ROL4__(v3, 16);
	LOWORD_HEXRAYS(v3) = a1;
	*(_DWORD *)a3 = v3;
	v4 = __ROL4__(a1, 16);
	*(_DWORD *)(a2 + a3 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a2 + a3) = v4;
	v5 = __ROL4__(a1, 16);
	*(_DWORD *)(a3 + 2 * a2 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a1;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a3 + 2 * a2) = v5;
	v6 = a2 + a3;
	v7 = __ROL4__(a1, 16);
	*(_DWORD *)(v6 + 2 * a2 + 4) = v7;
	LOWORD_HEXRAYS(v7) = a1;
	v8 = __ROL4__(v7, 16);
	LOWORD_HEXRAYS(v8) = a1;
	*(_DWORD *)(v6 + 2 * a2) = v8;
	return v8;
}

//----- (0045DCDF) --------------------------------------------------------
int __usercall sub_45DCDF@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // edx@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a3 + a4) = v4;
	*(_DWORD *)(a3 + a4 + 4) = v4;
	v5 = __ROL4__(a2, 16);
	*(_DWORD *)(a4 + 2 * a3 + 4) = v5;
	*(_DWORD *)(a4 + 2 * a3) = a2;
	v6 = a3 + a4;
	HIWORD_HEXRAYS(result) = HIWORD_HEXRAYS(a2);
	v7 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(result) = v7;
	*(_DWORD *)(v6 + 2 * a3 + 4) = result;
	*(_DWORD *)(v6 + 2 * a3) = result;
	return result;
}

//----- (0045DD24) --------------------------------------------------------
__int16 __usercall sub_45DD24@<ax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // edx@1
	int v5; // esi@1
	int v6; // eax@1

	*(_DWORD *)(a3 + 4) = a1;
	v3 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v3) = a1;
	*(_DWORD *)a3 = v3;
	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(a1);
	v4 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a2 + a3 + 4) = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROL4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)(a2 + a3) = v3;
	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(v4);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a3 + 2 * a2 + 4) = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROL4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)(a3 + 2 * a2) = v3;
	v5 = a2 + a3;
	*(_DWORD *)(v5 + 2 * a2 + 4) = v4;
	v6 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v6) = v4;
	*(_DWORD *)(v5 + 2 * a2) = v6;
	return v6;
}

//----- (0045DD83) --------------------------------------------------------
__int16 __usercall sub_45DD83@<ax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // edx@1
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // eax@1

	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(a1);
	v4 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a3 + 4) = v3;
	*(_DWORD *)a3 = v3;
	v5 = __ROL4__(v4, 16);
	*(_DWORD *)(a2 + a3 + 4) = v5;
	*(_DWORD *)(a2 + a3) = v4;
	v6 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v6) = v4;
	*(_DWORD *)(a3 + 2 * a2) = v6;
	*(_DWORD *)(a3 + 2 * a2 + 4) = v6;
	v7 = a2 + a3;
	LOWORD_HEXRAYS(v6) = v4;
	v8 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v8) = v4;
	*(_DWORD *)(v7 + 2 * a2) = v8;
	*(_DWORD *)(v7 + 2 * a2 + 4) = v8;
	return v8;
}

//----- (0045DDC8) --------------------------------------------------------
int __usercall sub_45DDC8@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // edx@1
	int v7; // esi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a4 + 4) = v4;
	v5 = __ROL4__(a2, 16);
	*(_DWORD *)a4 = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a4 + 4) = v5;
	HIWORD_HEXRAYS(v5) = HIWORD_HEXRAYS(a2);
	v6 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v5) = v6;
	v6 = __ROL4__(v6, 16);
	*(_DWORD *)(a3 + a4) = v5;
	LOWORD_HEXRAYS(v5) = v6;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = v6;
	*(_DWORD *)(a4 + 2 * a3 + 4) = v5;
	HIWORD_HEXRAYS(v5) = HIWORD_HEXRAYS(v6);
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v5) = v6;
	v6 = __ROL4__(v6, 16);
	*(_DWORD *)(a4 + 2 * a3) = v5;
	v7 = a3 + a4;
	LOWORD_HEXRAYS(v5) = v6;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = v6;
	*(_DWORD *)(v7 + 2 * a3 + 4) = v5;
	result = __ROL4__(v6, 16);
	*(_DWORD *)(v7 + 2 * a3) = result;
	return result;
}

//----- (0045DE2D) --------------------------------------------------------
int __usercall sub_45DE2D@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // edx@1
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int result; // eax@1

	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(a1);
	v4 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a3 + 4) = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROL4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)a3 = v3;
	*(_DWORD *)(a2 + a3 + 4) = v4;
	v5 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v5) = v4;
	*(_DWORD *)(a2 + a3) = v5;
	LOWORD_HEXRAYS(v5) = v4;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = v4;
	*(_DWORD *)(a3 + 2 * a2 + 4) = v5;
	v6 = __ROL4__(v4, 16);
	*(_DWORD *)(a3 + 2 * a2) = v6;
	v7 = a2 + a3;
	LOWORD_HEXRAYS(v6) = v4;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = v4;
	*(_DWORD *)(v7 + 2 * a2 + 4) = v6;
	HIWORD_HEXRAYS(result) = HIWORD_HEXRAYS(v4);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(result) = v4;
	*(_DWORD *)(v7 + 2 * a2) = result;
	return result;
}

//----- (0045DE8F) --------------------------------------------------------
__int16 __usercall sub_45DE8F@<ax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // edx@1
	int v6; // eax@1
	int v7; // eax@1
	int v8; // esi@1
	int v9; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a4 + 4) = v4;
	HIWORD_HEXRAYS(v4) = HIWORD_HEXRAYS(a2);
	v5 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v4) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)a4 = v4;
	LOWORD_HEXRAYS(v4) = v5;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = v5;
	*(_DWORD *)(a3 + a4 + 4) = v4;
	v6 = __ROL4__(v5, 16);
	*(_DWORD *)(a3 + a4) = v6;
	*(_DWORD *)(a4 + 2 * a3 + 4) = v5;
	v7 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v7) = v5;
	*(_DWORD *)(a4 + 2 * a3) = v7;
	v8 = a3 + a4;
	HIWORD_HEXRAYS(v7) = HIWORD_HEXRAYS(v5);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v7) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)(v8 + 2 * a3 + 4) = v7;
	LOWORD_HEXRAYS(v7) = v5;
	v9 = __ROL4__(v7, 16);
	LOWORD_HEXRAYS(v9) = v5;
	*(_DWORD *)(v8 + 2 * a3) = v9;
	return v9;
}

//----- (0045DEF1) --------------------------------------------------------
int __usercall sub_45DEF1@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // edx@1
	int v5; // esi@1
	int result; // eax@1

	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(a1);
	v4 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a3 + 4) = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROL4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)a3 = v3;
	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(v4);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a2 + a3 + 4) = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROL4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)(a2 + a3) = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROR4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)(a3 + 2 * a2 + 4) = v3;
	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(v4);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a3 + 2 * a2) = v3;
	v5 = a2 + a3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROR4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)(v5 + 2 * a2 + 4) = v3;
	HIWORD_HEXRAYS(result) = HIWORD_HEXRAYS(v4);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(result) = v4;
	*(_DWORD *)(v5 + 2 * a2) = result;
	return result;
}

//----- (0045DF62) --------------------------------------------------------
int __usercall sub_45DF62@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a3 + a4) = v4;
	*(_DWORD *)(a3 + a4 + 4) = v4;
	v5 = __ROL4__(a2, 16);
	*(_DWORD *)(a4 + 2 * a3 + 4) = v5;
	*(_DWORD *)(a4 + 2 * a3) = a2;
	v6 = a3 + a4;
	v7 = __ROL4__(a2, 16);
	*(_DWORD *)(v6 + 2 * a3 + 4) = v7;
	result = a2;
	*(_DWORD *)(v6 + 2 * a3) = a2;
	return result;
}

//----- (0045DFA3) --------------------------------------------------------
__int16 __usercall sub_45DFA3@<ax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // edx@1
	int v6; // esi@1
	int v7; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	*(_DWORD *)(a4 + 4) = v4;
	HIWORD_HEXRAYS(v4) = HIWORD_HEXRAYS(a2);
	v5 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v4) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)(a3 + a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = v5;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = v5;
	*(_DWORD *)(a3 + a4) = v4;
	HIWORD_HEXRAYS(v4) = HIWORD_HEXRAYS(v5);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v4) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)(a4 + 2 * a3 + 4) = v4;
	LOWORD_HEXRAYS(v4) = v5;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = v5;
	*(_DWORD *)(a4 + 2 * a3) = v4;
	v6 = a3 + a4;
	LOWORD_HEXRAYS(v4) = v5;
	v7 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v7) = v5;
	*(_DWORD *)(v6 + 2 * a3) = v7;
	*(_DWORD *)(v6 + 2 * a3 + 4) = v7;
	return v7;
}

//----- (0045DFFE) --------------------------------------------------------
__int16 __usercall sub_45DFFE@<ax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // eax@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1

	v3 = __ROL4__(a1, 16);
	*(_DWORD *)(a3 + 4) = v3;
	*(_DWORD *)a3 = a1;
	v4 = __ROL4__(a1, 16);
	*(_DWORD *)(a2 + a3 + 4) = v4;
	*(_DWORD *)(a2 + a3) = a1;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a3 + 2 * a2) = v5;
	*(_DWORD *)(a3 + 2 * a2 + 4) = v5;
	v6 = a2 + a3;
	LOWORD_HEXRAYS(v5) = a1;
	v7 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v7) = a1;
	*(_DWORD *)(v6 + 2 * a2) = v7;
	*(_DWORD *)(v6 + 2 * a2 + 4) = v7;
	return v7;
}

//----- (0045E03F) --------------------------------------------------------
__int16 __usercall sub_45E03F@<ax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // edx@1
	int v6; // esi@1
	int v7; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a3 + a4 + 4) = v4;
	HIWORD_HEXRAYS(v4) = HIWORD_HEXRAYS(a2);
	v5 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v4) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)(a3 + a4) = v4;
	LOWORD_HEXRAYS(v4) = v5;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = v5;
	*(_DWORD *)(a4 + 2 * a3 + 4) = v4;
	HIWORD_HEXRAYS(v4) = HIWORD_HEXRAYS(v5);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v4) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)(a4 + 2 * a3) = v4;
	v6 = a3 + a4;
	LOWORD_HEXRAYS(v4) = v5;
	v7 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v7) = v5;
	*(_DWORD *)(v6 + 2 * a3) = v7;
	*(_DWORD *)(v6 + 2 * a3 + 4) = v7;
	return v7;
}

//----- (0045E09A) --------------------------------------------------------
int __usercall sub_45E09A@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // edx@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a3 + a4) = v4;
	*(_DWORD *)(a3 + a4 + 4) = v4;
	*(_DWORD *)(a4 + 2 * a3 + 4) = a2;
	v5 = __ROL4__(a2, 16);
	*(_DWORD *)(a4 + 2 * a3) = v5;
	v6 = a3 + a4;
	HIWORD_HEXRAYS(result) = HIWORD_HEXRAYS(a2);
	v7 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(result) = v7;
	*(_DWORD *)(v6 + 2 * a3 + 4) = result;
	*(_DWORD *)(v6 + 2 * a3) = result;
	return result;
}

//----- (0045E0DF) --------------------------------------------------------
__int16 __usercall sub_45E0DF@<ax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // edx@1
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // eax@1

	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(a1);
	v4 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a3 + 4) = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROL4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)a3 = v3;
	*(_DWORD *)(a2 + a3 + 4) = v4;
	v5 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v5) = v4;
	*(_DWORD *)(a2 + a3) = v5;
	*(_DWORD *)(a3 + 2 * a2 + 4) = v4;
	v6 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v6) = v4;
	*(_DWORD *)(a3 + 2 * a2) = v6;
	v7 = a2 + a3;
	HIWORD_HEXRAYS(v6) = HIWORD_HEXRAYS(v4);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v6) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(v7 + 2 * a2 + 4) = v6;
	LOWORD_HEXRAYS(v6) = v4;
	v8 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v8) = v4;
	*(_DWORD *)(v7 + 2 * a2) = v8;
	return v8;
}

//----- (0045E13E) --------------------------------------------------------
__int16 __usercall sub_45E13E@<ax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // edx@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1

	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(a1);
	v4 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a3 + 4) = v3;
	*(_DWORD *)a3 = v3;
	*(_DWORD *)(a2 + a3 + 4) = v4;
	v5 = __ROL4__(v4, 16);
	*(_DWORD *)(a2 + a3) = v5;
	LOWORD_HEXRAYS(v5) = v4;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = v4;
	*(_DWORD *)(a3 + 2 * a2) = v5;
	*(_DWORD *)(a3 + 2 * a2 + 4) = v5;
	v6 = a2 + a3;
	LOWORD_HEXRAYS(v5) = v4;
	v7 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v7) = v4;
	*(_DWORD *)(v6 + 2 * a2) = v7;
	*(_DWORD *)(v6 + 2 * a2 + 4) = v7;
	return v7;
}

//----- (0045E183) --------------------------------------------------------
int __usercall sub_45E183@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // edx@1
	int v6; // eax@1
	int v7; // eax@1
	int v8; // esi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a4 + 4) = v4;
	HIWORD_HEXRAYS(v4) = HIWORD_HEXRAYS(a2);
	v5 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v4) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)a4 = v4;
	LOWORD_HEXRAYS(v4) = v5;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = v5;
	*(_DWORD *)(a3 + a4 + 4) = v4;
	v6 = __ROL4__(v5, 16);
	*(_DWORD *)(a3 + a4) = v6;
	LOWORD_HEXRAYS(v6) = v5;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = v5;
	*(_DWORD *)(a4 + 2 * a3 + 4) = v6;
	v7 = __ROL4__(v5, 16);
	*(_DWORD *)(a4 + 2 * a3) = v7;
	v8 = a3 + a4;
	LOWORD_HEXRAYS(v7) = v5;
	v7 = __ROR4__(v7, 16);
	LOWORD_HEXRAYS(v7) = v5;
	*(_DWORD *)(v8 + 2 * a3 + 4) = v7;
	HIWORD_HEXRAYS(result) = HIWORD_HEXRAYS(v5);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(result) = v5;
	*(_DWORD *)(v8 + 2 * a3) = result;
	return result;
}

//----- (0045E1E8) --------------------------------------------------------
int __usercall sub_45E1E8@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // esi@1
	int v6; // eax@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a3 + a4) = v4;
	*(_DWORD *)(a3 + a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a4 + 2 * a3) = v4;
	*(_DWORD *)(a4 + 2 * a3 + 4) = v4;
	v5 = a3 + a4;
	v6 = __ROL4__(a2, 16);
	*(_DWORD *)(v5 + 2 * a3 + 4) = v6;
	result = a2;
	*(_DWORD *)(v5 + 2 * a3) = a2;
	return result;
}

//----- (0045E22B) --------------------------------------------------------
__int16 __usercall sub_45E22B@<ax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	*(_DWORD *)(a4 + 4) = v4;
	*(_DWORD *)(a3 + a4 + 4) = a2;
	v5 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a4) = v5;
	*(_DWORD *)(a4 + 2 * a3 + 4) = a2;
	v6 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a4 + 2 * a3) = v6;
	v7 = a3 + a4;
	LOWORD_HEXRAYS(v6) = a2;
	v8 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v8) = a2;
	*(_DWORD *)(v7 + 2 * a3) = v8;
	*(_DWORD *)(v7 + 2 * a3 + 4) = v8;
	return v8;
}

//----- (0045E274) --------------------------------------------------------
__int16 __usercall sub_45E274@<ax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // eax@1
	int v5; // esi@1
	int v6; // eax@1

	v3 = __ROL4__(a1, 16);
	*(_DWORD *)(a3 + 4) = v3;
	*(_DWORD *)a3 = a1;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a2 + a3) = v4;
	*(_DWORD *)(a2 + a3 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a3 + 2 * a2) = v4;
	*(_DWORD *)(a3 + 2 * a2 + 4) = v4;
	v5 = a2 + a3;
	LOWORD_HEXRAYS(v4) = a1;
	v6 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v6) = a1;
	*(_DWORD *)(v5 + 2 * a2) = v6;
	*(_DWORD *)(v5 + 2 * a2 + 4) = v6;
	return v6;
}

//----- (0045E2B7) --------------------------------------------------------
__int16 __usercall sub_45E2B7@<ax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a3 + a4 + 4) = v4;
	v5 = __ROL4__(a2, 16);
	*(_DWORD *)(a3 + a4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a4 + 2 * a3 + 4) = v5;
	v6 = __ROL4__(a2, 16);
	*(_DWORD *)(a4 + 2 * a3) = v6;
	v7 = a3 + a4;
	LOWORD_HEXRAYS(v6) = a2;
	v8 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v8) = a2;
	*(_DWORD *)(v7 + 2 * a3) = v8;
	*(_DWORD *)(v7 + 2 * a3 + 4) = v8;
	return v8;
}

//----- (0045E306) --------------------------------------------------------
__int16 __usercall sub_45E306@<ax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // eax@1
	int v5; // edx@1
	int v6; // esi@1
	int v7; // eax@1

	*(_DWORD *)(a3 + 4) = a1;
	v3 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v3) = a1;
	*(_DWORD *)a3 = v3;
	*(_DWORD *)(a2 + a3 + 4) = a1;
	v4 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a2 + a3) = v4;
	HIWORD_HEXRAYS(v4) = HIWORD_HEXRAYS(a1);
	v5 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v4) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)(a3 + 2 * a2 + 4) = v4;
	LOWORD_HEXRAYS(v4) = v5;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = v5;
	*(_DWORD *)(a3 + 2 * a2) = v4;
	v6 = a2 + a3;
	HIWORD_HEXRAYS(v4) = HIWORD_HEXRAYS(v5);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v4) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)(v6 + 2 * a2 + 4) = v4;
	LOWORD_HEXRAYS(v4) = v5;
	v7 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v7) = v5;
	*(_DWORD *)(v6 + 2 * a2) = v7;
	return v7;
}

//----- (0045E365) --------------------------------------------------------
int __usercall sub_45E365@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // edx@1
	int v6; // esi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a3 + a4) = v4;
	*(_DWORD *)(a3 + a4 + 4) = v4;
	HIWORD_HEXRAYS(v4) = HIWORD_HEXRAYS(a2);
	v5 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v4) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)(a4 + 2 * a3 + 4) = v4;
	LOWORD_HEXRAYS(v4) = v5;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = v5;
	*(_DWORD *)(a4 + 2 * a3) = v4;
	v6 = a3 + a4;
	HIWORD_HEXRAYS(result) = HIWORD_HEXRAYS(v5);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(result) = v5;
	*(_DWORD *)(v6 + 2 * a3 + 4) = result;
	*(_DWORD *)(v6 + 2 * a3) = result;
	return result;
}

//----- (0045E3B7) --------------------------------------------------------
__int16 __usercall sub_45E3B7@<ax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // edx@1
	int v5; // esi@1
	int v6; // eax@1

	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(a1);
	v4 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a3 + 4) = v3;
	*(_DWORD *)a3 = v3;
	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(v4);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a2 + a3 + 4) = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROL4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)(a2 + a3) = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROR4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)(a3 + 2 * a2) = v3;
	*(_DWORD *)(a3 + 2 * a2 + 4) = v3;
	v5 = a2 + a3;
	LOWORD_HEXRAYS(v3) = v4;
	v6 = __ROR4__(v3, 16);
	LOWORD_HEXRAYS(v6) = v4;
	*(_DWORD *)(v5 + 2 * a2) = v6;
	*(_DWORD *)(v5 + 2 * a2 + 4) = v6;
	return v6;
}

//----- (0045E409) --------------------------------------------------------
__int16 __usercall sub_45E409@<ax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // edx@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1

	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(a1);
	v4 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a3 + 4) = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROL4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)a3 = v3;
	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(v4);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a2 + a3 + 4) = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROL4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)(a2 + a3) = v3;
	*(_DWORD *)(a3 + 2 * a2 + 4) = v4;
	v5 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v5) = v4;
	*(_DWORD *)(a3 + 2 * a2) = v5;
	v6 = a2 + a3;
	*(_DWORD *)(v6 + 2 * a2 + 4) = v4;
	v7 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v7) = v4;
	*(_DWORD *)(v6 + 2 * a2) = v7;
	return v7;
}

//----- (0045E468) --------------------------------------------------------
__int16 __usercall sub_45E468@<ax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // edx@1
	int v5; // esi@1
	int v6; // eax@1

	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(a1);
	v4 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a3 + 4) = v3;
	*(_DWORD *)a3 = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROR4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)(a2 + a3 + 4) = v3;
	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(v4);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a2 + a3) = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROR4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)(a3 + 2 * a2) = v3;
	*(_DWORD *)(a3 + 2 * a2 + 4) = v3;
	v5 = a2 + a3;
	LOWORD_HEXRAYS(v3) = v4;
	v6 = __ROR4__(v3, 16);
	LOWORD_HEXRAYS(v6) = v4;
	*(_DWORD *)(v5 + 2 * a2) = v6;
	*(_DWORD *)(v5 + 2 * a2 + 4) = v6;
	return v6;
}

//----- (0045E4BA) --------------------------------------------------------
int __usercall sub_45E4BA@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // edx@1
	int v6; // eax@1
	int v7; // esi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a4 + 4) = v4;
	HIWORD_HEXRAYS(v4) = HIWORD_HEXRAYS(a2);
	v5 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v4) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)a4 = v4;
	LOWORD_HEXRAYS(v4) = v5;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = v5;
	*(_DWORD *)(a3 + a4 + 4) = v4;
	HIWORD_HEXRAYS(v4) = HIWORD_HEXRAYS(v5);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v4) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)(a3 + a4) = v4;
	LOWORD_HEXRAYS(v4) = v5;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = v5;
	*(_DWORD *)(a4 + 2 * a3 + 4) = v4;
	v6 = __ROL4__(v5, 16);
	*(_DWORD *)(a4 + 2 * a3) = v6;
	v7 = a3 + a4;
	LOWORD_HEXRAYS(v6) = v5;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = v5;
	*(_DWORD *)(v7 + 2 * a3 + 4) = v6;
	result = __ROL4__(v5, 16);
	*(_DWORD *)(v7 + 2 * a3) = result;
	return result;
}

//----- (0045E51F) --------------------------------------------------------
int __usercall sub_45E51F@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // eax@1
	int v7; // edx@1
	int v8; // esi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a4 + 4) = v4;
	v5 = __ROL4__(a2, 16);
	*(_DWORD *)a4 = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a4 + 4) = v5;
	v6 = __ROL4__(a2, 16);
	*(_DWORD *)(a3 + a4) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a4 + 2 * a3 + 4) = v6;
	HIWORD_HEXRAYS(v6) = HIWORD_HEXRAYS(a2);
	v7 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v6) = v7;
	v7 = __ROL4__(v7, 16);
	*(_DWORD *)(a4 + 2 * a3) = v6;
	v8 = a3 + a4;
	LOWORD_HEXRAYS(v6) = v7;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = v7;
	*(_DWORD *)(v8 + 2 * a3 + 4) = v6;
	HIWORD_HEXRAYS(result) = HIWORD_HEXRAYS(v7);
	v7 = __ROL4__(v7, 16);
	LOWORD_HEXRAYS(result) = v7;
	*(_DWORD *)(v8 + 2 * a3) = result;
	return result;
}

//----- (0045E584) --------------------------------------------------------
int __usercall sub_45E584@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // edx@1
	int v6; // esi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a3 + a4) = v4;
	*(_DWORD *)(a3 + a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a4 + 2 * a3 + 4) = v4;
	HIWORD_HEXRAYS(v4) = HIWORD_HEXRAYS(a2);
	v5 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v4) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)(a4 + 2 * a3) = v4;
	v6 = a3 + a4;
	HIWORD_HEXRAYS(result) = HIWORD_HEXRAYS(v5);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(result) = v5;
	*(_DWORD *)(v6 + 2 * a3 + 4) = result;
	*(_DWORD *)(v6 + 2 * a3) = result;
	return result;
}

//----- (0045E5D6) --------------------------------------------------------
int __usercall sub_45E5D6@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // edx@1
	int v5; // esi@1
	int v6; // eax@1
	int result; // eax@1

	v3 = __ROL4__(a1, 16);
	*(_DWORD *)(a3 + 4) = v3;
	*(_DWORD *)a3 = a1;
	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(a1);
	v4 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a2 + a3 + 4) = v3;
	*(_DWORD *)(a2 + a3) = v3;
	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(v4);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a3 + 2 * a2 + 4) = v3;
	*(_DWORD *)(a3 + 2 * a2) = v3;
	v5 = a2 + a3;
	v6 = __ROL4__(v4, 16);
	*(_DWORD *)(v5 + 2 * a2 + 4) = v6;
	result = v4;
	*(_DWORD *)(v5 + 2 * a2) = v4;
	return result;
}

//----- (0045E61B) --------------------------------------------------------
__int16 __usercall sub_45E61B@<ax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // edx@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a4 + 4) = v4;
	HIWORD_HEXRAYS(v4) = HIWORD_HEXRAYS(a2);
	v5 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v4) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)a4 = v4;
	LOWORD_HEXRAYS(v4) = v5;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = v5;
	*(_DWORD *)(a3 + a4) = v4;
	*(_DWORD *)(a3 + a4 + 4) = v4;
	v6 = __ROL4__(v5, 16);
	*(_DWORD *)(a4 + 2 * a3 + 4) = v6;
	*(_DWORD *)(a4 + 2 * a3) = v5;
	v7 = a3 + a4;
	v8 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v8) = v5;
	*(_DWORD *)(v7 + 2 * a3) = v8;
	*(_DWORD *)(v7 + 2 * a3 + 4) = v8;
	return v8;
}

//----- (0045E669) --------------------------------------------------------
__int16 __usercall sub_45E669@<ax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // edx@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1

	v3 = __ROL4__(a1, 16);
	*(_DWORD *)(a3 + 4) = v3;
	*(_DWORD *)a3 = a1;
	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(a1);
	v4 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a2 + a3 + 4) = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROL4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)(a2 + a3) = v3;
	*(_DWORD *)(a3 + 2 * a2 + 4) = v4;
	v5 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v5) = v4;
	*(_DWORD *)(a3 + 2 * a2) = v5;
	v6 = a2 + a3;
	LOWORD_HEXRAYS(v5) = v4;
	v7 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v7) = v4;
	*(_DWORD *)(v6 + 2 * a2) = v7;
	*(_DWORD *)(v6 + 2 * a2 + 4) = v7;
	return v7;
}

//----- (0045E6B9) --------------------------------------------------------
__int16 __usercall sub_45E6B9@<ax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // edx@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a4 + 4) = v4;
	HIWORD_HEXRAYS(v4) = HIWORD_HEXRAYS(a2);
	v5 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v4) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)a4 = v4;
	v6 = __ROL4__(v5, 16);
	*(_DWORD *)(a3 + a4 + 4) = v6;
	*(_DWORD *)(a3 + a4) = v5;
	HIWORD_HEXRAYS(v6) = HIWORD_HEXRAYS(v5);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v6) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)(a4 + 2 * a3 + 4) = v6;
	LOWORD_HEXRAYS(v6) = v5;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = v5;
	*(_DWORD *)(a4 + 2 * a3) = v6;
	v7 = a3 + a4;
	*(_DWORD *)(v7 + 2 * a3 + 4) = v5;
	v8 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v8) = v5;
	*(_DWORD *)(v7 + 2 * a3) = v8;
	return v8;
}

//----- (0045E714) --------------------------------------------------------
__int16 __usercall sub_45E714@<ax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // edx@1
	int v7; // eax@1
	int v8; // esi@1
	int v9; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a4 + 4) = v4;
	v5 = __ROL4__(a2, 16);
	*(_DWORD *)a4 = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a4 + 4) = v5;
	HIWORD_HEXRAYS(v5) = HIWORD_HEXRAYS(a2);
	v6 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v5) = v6;
	v6 = __ROL4__(v6, 16);
	*(_DWORD *)(a3 + a4) = v5;
	v7 = __ROL4__(v6, 16);
	*(_DWORD *)(a4 + 2 * a3 + 4) = v7;
	*(_DWORD *)(a4 + 2 * a3) = v6;
	v8 = a3 + a4;
	HIWORD_HEXRAYS(v7) = HIWORD_HEXRAYS(v6);
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v7) = v6;
	v6 = __ROL4__(v6, 16);
	*(_DWORD *)(v8 + 2 * a3 + 4) = v7;
	LOWORD_HEXRAYS(v7) = v6;
	v9 = __ROL4__(v7, 16);
	LOWORD_HEXRAYS(v9) = v6;
	*(_DWORD *)(v8 + 2 * a3) = v9;
	return v9;
}

//----- (0045E772) --------------------------------------------------------
int __usercall sub_45E772@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // edx@1
	int v7; // esi@1
	int v8; // eax@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a2;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)(a3 + a4 + 4) = v4;
	v5 = __ROL4__(a2, 16);
	*(_DWORD *)(a3 + a4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a4 + 2 * a3 + 4) = v5;
	HIWORD_HEXRAYS(v5) = HIWORD_HEXRAYS(a2);
	v6 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v5) = v6;
	v6 = __ROL4__(v6, 16);
	*(_DWORD *)(a4 + 2 * a3) = v5;
	v7 = a3 + a4;
	v8 = __ROL4__(v6, 16);
	*(_DWORD *)(v7 + 2 * a3 + 4) = v8;
	result = v6;
	*(_DWORD *)(v7 + 2 * a3) = v6;
	return result;
}

//----- (0045E7C5) --------------------------------------------------------
__int16 __usercall sub_45E7C5@<ax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // edx@1
	int v9; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	*(_DWORD *)(a4 + 4) = v4;
	v5 = __ROL4__(a2, 16);
	*(_DWORD *)(a3 + a4 + 4) = v5;
	*(_DWORD *)(a3 + a4) = a2;
	v6 = __ROR4__(a2, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a4 + 2 * a3) = v6;
	*(_DWORD *)(a4 + 2 * a3 + 4) = v6;
	v7 = a3 + a4;
	HIWORD_HEXRAYS(v6) = HIWORD_HEXRAYS(a2);
	v8 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v6) = v8;
	v8 = __ROL4__(v8, 16);
	*(_DWORD *)(v7 + 2 * a3 + 4) = v6;
	LOWORD_HEXRAYS(v6) = v8;
	v9 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v9) = v8;
	*(_DWORD *)(v7 + 2 * a3) = v9;
	return v9;
}

//----- (0045E813) --------------------------------------------------------
__int16 __usercall sub_45E813@<ax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // eax@1
	int v5; // edx@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // eax@1

	v3 = __ROL4__(a1, 16);
	*(_DWORD *)(a3 + 4) = v3;
	*(_DWORD *)a3 = a1;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a2 + a3 + 4) = v4;
	HIWORD_HEXRAYS(v4) = HIWORD_HEXRAYS(a1);
	v5 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v4) = v5;
	v5 = __ROL4__(v5, 16);
	*(_DWORD *)(a2 + a3) = v4;
	LOWORD_HEXRAYS(v4) = v5;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = v5;
	*(_DWORD *)(a3 + 2 * a2 + 4) = v4;
	v6 = __ROL4__(v5, 16);
	*(_DWORD *)(a3 + 2 * a2) = v6;
	v7 = a2 + a3;
	LOWORD_HEXRAYS(v6) = v5;
	v8 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v8) = v5;
	*(_DWORD *)(v7 + 2 * a2) = v8;
	*(_DWORD *)(v7 + 2 * a2 + 4) = v8;
	return v8;
}

//----- (0045E866) --------------------------------------------------------
int __usercall sub_45E866@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // edx@1
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int result; // eax@1

	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(a1);
	v4 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a3 + 4) = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROL4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)a3 = v3;
	v5 = __ROL4__(v4, 16);
	*(_DWORD *)(a2 + a3 + 4) = v5;
	*(_DWORD *)(a2 + a3) = v4;
	v6 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v6) = v4;
	*(_DWORD *)(a3 + 2 * a2 + 4) = v6;
	HIWORD_HEXRAYS(v6) = HIWORD_HEXRAYS(v4);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v6) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a3 + 2 * a2) = v6;
	v7 = a2 + a3;
	LOWORD_HEXRAYS(v6) = v4;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = v4;
	*(_DWORD *)(v7 + 2 * a2 + 4) = v6;
	result = __ROL4__(v4, 16);
	*(_DWORD *)(v7 + 2 * a2) = result;
	return result;
}

//----- (0045E8C4) --------------------------------------------------------
int __usercall sub_45E8C4@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // edx@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1
	int result; // eax@1

	*(_DWORD *)(a3 + 4) = a1;
	v3 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v3) = a1;
	*(_DWORD *)a3 = v3;
	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(a1);
	v4 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a2 + a3 + 4) = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROL4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)(a2 + a3) = v3;
	v5 = __ROL4__(v4, 16);
	*(_DWORD *)(a3 + 2 * a2 + 4) = v5;
	*(_DWORD *)(a3 + 2 * a2) = v4;
	v6 = a2 + a3;
	v7 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v7) = v4;
	*(_DWORD *)(v6 + 2 * a2 + 4) = v7;
	HIWORD_HEXRAYS(result) = HIWORD_HEXRAYS(v4);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(result) = v4;
	*(_DWORD *)(v6 + 2 * a2) = result;
	return result;
}

//----- (0045E91F) --------------------------------------------------------
int __usercall sub_45E91F@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // edx@1
	int v7; // esi@1
	int v8; // eax@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v4 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v4) = a2;
	*(_DWORD *)a4 = v4;
	*(_DWORD *)(a4 + 4) = v4;
	*(_DWORD *)(a3 + a4 + 4) = a2;
	v5 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a4) = v5;
	HIWORD_HEXRAYS(v5) = HIWORD_HEXRAYS(a2);
	v6 = __ROL4__(a2, 16);
	LOWORD_HEXRAYS(v5) = v6;
	v6 = __ROL4__(v6, 16);
	*(_DWORD *)(a4 + 2 * a3 + 4) = v5;
	LOWORD_HEXRAYS(v5) = v6;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = v6;
	*(_DWORD *)(a4 + 2 * a3) = v5;
	v7 = a3 + a4;
	v8 = __ROL4__(v6, 16);
	*(_DWORD *)(v7 + 2 * a3 + 4) = v8;
	result = v6;
	*(_DWORD *)(v7 + 2 * a3) = v6;
	return result;
}

//----- (0045E96F) --------------------------------------------------------
int __usercall sub_45E96F@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>)
{
	int v3; // eax@1
	int v4; // edx@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1
	int result; // eax@1

	HIWORD_HEXRAYS(v3) = HIWORD_HEXRAYS(a1);
	v4 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v3) = v4;
	v4 = __ROL4__(v4, 16);
	*(_DWORD *)(a3 + 4) = v3;
	LOWORD_HEXRAYS(v3) = v4;
	v3 = __ROL4__(v3, 16);
	LOWORD_HEXRAYS(v3) = v4;
	*(_DWORD *)a3 = v3;
	v5 = __ROL4__(v4, 16);
	*(_DWORD *)(a2 + a3 + 4) = v5;
	LOWORD_HEXRAYS(v5) = v4;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = v4;
	*(_DWORD *)(a2 + a3) = v5;
	LOWORD_HEXRAYS(v5) = v4;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = v4;
	*(_DWORD *)(a3 + 2 * a2 + 4) = v5;
	*(_DWORD *)(a3 + 2 * a2) = v4;
	v6 = a2 + a3;
	v7 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v7) = v4;
	*(_DWORD *)(v6 + 2 * a2 + 4) = v7;
	HIWORD_HEXRAYS(result) = HIWORD_HEXRAYS(v4);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(result) = v4;
	*(_DWORD *)(v6 + 2 * a2) = result;
	return result;
}

//----- (0045E9D1) --------------------------------------------------------
__int16 __usercall sub_45E9D1@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 4);
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3 + 4);
	*(_DWORD *)(a5 + 2 * a3 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3 + 2);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v5;
	v6 = a3 + a5;
	LOWORD_HEXRAYS(v5) = a2;
	v7 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v7) = a2;
	*(_DWORD *)(v6 + 2 * a3) = v7;
	*(_DWORD *)(v6 + 2 * a3 + 4) = v7;
	return v7;
}

//----- (0045EA30) --------------------------------------------------------
int __usercall sub_45EA30@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // esi@1
	int v7; // edi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5) = v5;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	*(_DWORD *)(a5 + 2 * a3 + 4) = *(_DWORD *)(a4 + 2 * a3 + 4);
	*(_DWORD *)(a5 + 2 * a3) = *(_DWORD *)(a4 + 2 * a3);
	v6 = a3 + a5;
	v7 = a3 + a4;
	*(_DWORD *)(v6 + 2 * a3 + 4) = *(_DWORD *)(v7 + 2 * a3 + 4);
	result = *(_DWORD *)(v7 + 2 * a3);
	*(_DWORD *)(v6 + 2 * a3) = result;
	return result;
}

//----- (0045EA71) --------------------------------------------------------
__int16 __usercall sub_45EA71@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // eax@1
	int v9; // eax@1

	v4 = *(_DWORD *)(a3 + 4);
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)a4 = v4;
	v5 = *(_DWORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a1;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a2 + a4) = v5;
	v6 = *(_DWORD *)(a3 + 2 * a2 + 4);
	*(_DWORD *)(a4 + 2 * a2 + 4) = v6;
	LOWORD_HEXRAYS(v6) = a1;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a1;
	*(_DWORD *)(a4 + 2 * a2) = v6;
	v7 = a2 + a4;
	v8 = *(_DWORD *)(a2 + a3 + 2 * a2 + 4);
	*(_DWORD *)(v7 + 2 * a2 + 4) = v8;
	LOWORD_HEXRAYS(v8) = a1;
	v9 = __ROL4__(v8, 16);
	LOWORD_HEXRAYS(v9) = a1;
	*(_DWORD *)(v7 + 2 * a2) = v9;
	return v9;
}

//----- (0045EAC5) --------------------------------------------------------
int __usercall sub_45EAC5@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // esi@1
	int v7; // edi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5) = v5;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v5;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v5;
	v6 = a3 + a5;
	v7 = a3 + a4;
	*(_DWORD *)(v6 + 2 * a3 + 4) = *(_DWORD *)(v7 + 2 * a3 + 4);
	result = *(_DWORD *)(v7 + 2 * a3);
	*(_DWORD *)(v6 + 2 * a3) = result;
	return result;
}

//----- (0045EB08) --------------------------------------------------------
__int16 __usercall sub_45EB08@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1

	LOWORD_HEXRAYS(a1) = *(_WORD *)(a4 + 6);
	v5 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 6);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3 + 6);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v5;
	v6 = a3 + a5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2 * a3 + 6);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(v6 + 2 * a3 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v7 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v7) = a2;
	*(_DWORD *)(v6 + 2 * a3) = v7;
	return v7;
}

//----- (0045EB78) --------------------------------------------------------
__int16 __usercall sub_45EB78@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // esi@1
	int v6; // eax@1

	*(_DWORD *)(a4 + 4) = *(_DWORD *)(a3 + 4);
	v4 = *(_DWORD *)a3;
	*(_DWORD *)a4 = *(_DWORD *)a3;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a2 + a4) = v4;
	*(_DWORD *)(a2 + a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a4 + 2 * a2) = v4;
	*(_DWORD *)(a4 + 2 * a2 + 4) = v4;
	v5 = a2 + a4;
	LOWORD_HEXRAYS(v4) = a1;
	v6 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v6) = a1;
	*(_DWORD *)(v5 + 2 * a2) = v6;
	*(_DWORD *)(v5 + 2 * a2 + 4) = v6;
	return v6;
}

//----- (0045EBB9) --------------------------------------------------------
__int16 __usercall sub_45EBB9@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)a4;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)&a4[a3];
	*(_DWORD *)(a3 + a5) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)&a4[2 * a3];
	*(_DWORD *)(a5 + 2 * a3) = v5;
	v6 = a3 + a5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(v6 + 2 * a3 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v7 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v7) = *(_WORD *)(&a4[2 * a3] + a3);
	*(_DWORD *)(v6 + 2 * a3) = v7;
	return v7;
}

//----- (0045EC25) --------------------------------------------------------
int __usercall sub_45EC25@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1
	int v8; // esi@1
	int v9; // edi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = *(_WORD *)(a4 + 6);
	v5 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	v6 = *(_DWORD *)(a3 + a4 + 4);
	*(_DWORD *)(a3 + a5 + 4) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a3 + a5) = v6;
	v7 = *(_DWORD *)(a4 + 2 * a3 + 4);
	*(_DWORD *)(a5 + 2 * a3 + 4) = v7;
	LOWORD_HEXRAYS(v7) = *(_WORD *)(a4 + 2 * a3 + 2);
	v7 = __ROL4__(v7, 16);
	LOWORD_HEXRAYS(v7) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v7;
	v8 = a3 + a5;
	v9 = a3 + a4;
	*(_DWORD *)(v8 + 2 * a3 + 4) = *(_DWORD *)(v9 + 2 * a3 + 4);
	result = *(_DWORD *)(v9 + 2 * a3);
	*(_DWORD *)(v8 + 2 * a3) = result;
	return result;
}

//----- (0045EC7C) --------------------------------------------------------
__int16 __usercall sub_45EC7C@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1

	*(_DWORD *)(a4 + 4) = *(_DWORD *)(a3 + 4);
	*(_DWORD *)a4 = *(_DWORD *)a3;
	v4 = *(_DWORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a2 + a3 + 2);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a2 + a4) = v4;
	v5 = *(_DWORD *)(a3 + 2 * a2 + 4);
	*(_DWORD *)(a4 + 2 * a2 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a1;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a4 + 2 * a2) = v5;
	v6 = a2 + a4;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a2 + a3 + 2 * a2 + 6);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(v6 + 2 * a2 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a1;
	v7 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v7) = a1;
	*(_DWORD *)(v6 + 2 * a2) = v7;
	return v7;
}

//----- (0045ECD2) --------------------------------------------------------
__int16 __usercall sub_45ECD2@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // eax@1

	*(_DWORD *)(a4 + 4) = *(_DWORD *)(a3 + 4);
	v4 = *(_DWORD *)a3;
	*(_DWORD *)a4 = *(_DWORD *)a3;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4 + 4) = v4;
	v5 = *(_DWORD *)(a2 + a3);
	*(_DWORD *)(a2 + a4) = v5;
	LOWORD_HEXRAYS(v5) = a1;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a4 + 2 * a2 + 4) = v5;
	v6 = *(_DWORD *)(a3 + 2 * a2);
	*(_DWORD *)(a4 + 2 * a2) = v6;
	v7 = a2 + a4;
	LOWORD_HEXRAYS(v6) = a1;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a1;
	*(_DWORD *)(v7 + 2 * a2 + 4) = v6;
	LOWORD_HEXRAYS(v6) = a1;
	v8 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v8) = *(_WORD *)(a2 + a3 + 2 * a2);
	*(_DWORD *)(v7 + 2 * a2) = v8;
	return v8;
}

//----- (0045ED25) --------------------------------------------------------
int __usercall sub_45ED25@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	char *v8; // edi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)a4;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	v6 = *(_DWORD *)&a4[a3];
	*(_DWORD *)(a3 + a5) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)&a4[2 * a3 + 4];
	*(_DWORD *)(a5 + 2 * a3 + 4) = v6;
	*(_DWORD *)(a5 + 2 * a3) = *(_DWORD *)&a4[2 * a3];
	v7 = a3 + a5;
	v8 = &a4[a3];
	*(_DWORD *)(v7 + 2 * a3 + 4) = *(_DWORD *)&v8[2 * a3 + 4];
	result = *(_DWORD *)&v8[2 * a3];
	*(_DWORD *)(v7 + 2 * a3) = result;
	return result;
}

//----- (0045ED79) --------------------------------------------------------
__int16 __usercall sub_45ED79@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1
	int v8; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5) = v5;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3 + 6);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v5;
	v6 = a3 + a5;
	v7 = *(_DWORD *)(a3 + a4 + 2 * a3 + 4);
	*(_DWORD *)(v6 + 2 * a3 + 4) = v7;
	LOWORD_HEXRAYS(v7) = a2;
	v8 = __ROL4__(v7, 16);
	LOWORD_HEXRAYS(v8) = a2;
	*(_DWORD *)(v6 + 2 * a3) = v8;
	return v8;
}

//----- (0045EDCD) --------------------------------------------------------
__int16 __usercall sub_45EDCD@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // esi@1
	int v6; // eax@1

	v4 = *(_DWORD *)(a3 + 4);
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)a4 = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a2 + a3 + 6);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a2 + a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a2 + a4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a4 + 2 * a2) = v4;
	*(_DWORD *)(a4 + 2 * a2 + 4) = v4;
	v5 = a2 + a4;
	LOWORD_HEXRAYS(v4) = a1;
	v6 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v6) = a1;
	*(_DWORD *)(v5 + 2 * a2) = v6;
	*(_DWORD *)(v5 + 2 * a2 + 4) = v6;
	return v6;
}

//----- (0045EE20) --------------------------------------------------------
__int16 __usercall sub_45EE20@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	v6 = *(_DWORD *)a4;
	*(_DWORD *)a5 = *(_DWORD *)a4;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)&a4[a3];
	*(_DWORD *)(a3 + a5) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v6;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v6;
	v7 = a3 + a5;
	LOWORD_HEXRAYS(v6) = a2;
	v8 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v8) = a2;
	*(_DWORD *)(v7 + 2 * a3) = v8;
	*(_DWORD *)(v7 + 2 * a3 + 4) = v8;
	return v8;
}

//----- (0045EE71) --------------------------------------------------------
int __usercall sub_45EE71@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // esi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5) = v5;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3);
	*(_DWORD *)(a5 + 2 * a3) = v5;
	v6 = a3 + a5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(v6 + 2 * a3 + 4) = v5;
	result = *(_DWORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(v6 + 2 * a3) = result;
	return result;
}

//----- (0045EEC3) --------------------------------------------------------
__int16 __usercall sub_45EEC3@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // eax@1
	int v9; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5) = v5;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	v6 = *(_DWORD *)(a4 + 2 * a3 + 4);
	*(_DWORD *)(a5 + 2 * a3 + 4) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v6;
	v7 = a3 + a5;
	v8 = *(_DWORD *)(a3 + a4 + 2 * a3 + 4);
	*(_DWORD *)(v7 + 2 * a3 + 4) = v8;
	LOWORD_HEXRAYS(v8) = a2;
	v9 = __ROL4__(v8, 16);
	LOWORD_HEXRAYS(v9) = a2;
	*(_DWORD *)(v7 + 2 * a3) = v9;
	return v9;
}

//----- (0045EF10) --------------------------------------------------------
__int16 __usercall sub_45EF10@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1

	v4 = *(_DWORD *)(a3 + 4);
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)a4 = v4;
	v5 = *(_DWORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a1;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a2 + a4) = v5;
	LOWORD_HEXRAYS(v5) = a1;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a4 + 2 * a2) = v5;
	*(_DWORD *)(a4 + 2 * a2 + 4) = v5;
	v6 = a2 + a4;
	LOWORD_HEXRAYS(v5) = a1;
	v7 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v7) = a1;
	*(_DWORD *)(v6 + 2 * a2) = v7;
	*(_DWORD *)(v6 + 2 * a2 + 4) = v7;
	return v7;
}

//----- (0045EF5C) --------------------------------------------------------
__int16 __usercall sub_45EF5C@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1
	int v8; // esi@1
	int v9; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	v6 = *(_DWORD *)a4;
	*(_DWORD *)a5 = *(_DWORD *)a4;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v6;
	v7 = *(_DWORD *)&a4[a3];
	*(_DWORD *)(a3 + a5) = v7;
	LOWORD_HEXRAYS(v7) = a2;
	v7 = __ROR4__(v7, 16);
	LOWORD_HEXRAYS(v7) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v7;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v7;
	v8 = a3 + a5;
	LOWORD_HEXRAYS(v7) = a2;
	v9 = __ROR4__(v7, 16);
	LOWORD_HEXRAYS(v9) = a2;
	*(_DWORD *)(v8 + 2 * a3) = v9;
	*(_DWORD *)(v8 + 2 * a3 + 4) = v9;
	return v9;
}

//----- (0045EFA6) --------------------------------------------------------
int __usercall sub_45EFA6@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5) = v5;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v5;
	v6 = *(_DWORD *)(a4 + 2 * a3);
	*(_DWORD *)(a5 + 2 * a3) = v6;
	v7 = a3 + a5;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(v7 + 2 * a3 + 4) = v6;
	result = *(_DWORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(v7 + 2 * a3) = result;
	return result;
}

//----- (0045EFF1) --------------------------------------------------------
__int16 __usercall sub_45EFF1@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	*(_DWORD *)(a3 + a5 + 4) = *(_DWORD *)(a3 + a4 + 4);
	*(_DWORD *)(a3 + a5) = *(_DWORD *)(a3 + a4);
	*(_DWORD *)(a5 + 2 * a3 + 4) = *(_DWORD *)(a4 + 2 * a3 + 4);
	v6 = *(_DWORD *)(a4 + 2 * a3);
	*(_DWORD *)(a5 + 2 * a3) = v6;
	v7 = a3 + a5;
	LOWORD_HEXRAYS(v6) = a2;
	v8 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v8) = a2;
	*(_DWORD *)(v7 + 2 * a3) = v8;
	*(_DWORD *)(v7 + 2 * a3 + 4) = v8;
	return v8;
}

//----- (0045F032) --------------------------------------------------------
__int16 __usercall sub_45F032@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // esi@1
	int v7; // edi@1
	int v8; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 4);
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 4);
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3 + 4);
	*(_DWORD *)(a5 + 2 * a3 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3 + 2);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v5;
	v6 = a3 + a5;
	v7 = a3 + a4;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(v7 + 2 * a3 + 4);
	*(_DWORD *)(v6 + 2 * a3 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(v7 + 2 * a3 + 2);
	v8 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v8) = a2;
	*(_DWORD *)(v6 + 2 * a3) = v8;
	return v8;
}

//----- (0045F0A9) --------------------------------------------------------
__int16 __usercall sub_45F0A9@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	*(_DWORD *)(a3 + a5 + 4) = *(_DWORD *)(a3 + a4 + 4);
	v6 = *(_DWORD *)(a3 + a4);
	*(_DWORD *)(a3 + a5) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v6;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v6;
	v7 = a3 + a5;
	LOWORD_HEXRAYS(v6) = a2;
	v8 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v8) = a2;
	*(_DWORD *)(v7 + 2 * a3) = v8;
	*(_DWORD *)(v7 + 2 * a3 + 4) = v8;
	return v8;
}

//----- (0045F0EC) --------------------------------------------------------
__int16 __usercall sub_45F0EC@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5) = v5;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	*(_DWORD *)(a5 + 2 * a3 + 4) = *(_DWORD *)(a4 + 2 * a3 + 4);
	v6 = *(_DWORD *)(a4 + 2 * a3);
	*(_DWORD *)(a5 + 2 * a3) = v6;
	v7 = a3 + a5;
	LOWORD_HEXRAYS(v6) = a2;
	v8 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v8) = a2;
	*(_DWORD *)(v7 + 2 * a3) = v8;
	*(_DWORD *)(v7 + 2 * a3 + 4) = v8;
	return v8;
}

//----- (0045F12F) --------------------------------------------------------
__int16 __usercall sub_45F12F@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3 + 2);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v5;
	v6 = a3 + a5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(v6 + 2 * a3 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2 * a3 + 2);
	v7 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v7) = a2;
	*(_DWORD *)(v6 + 2 * a3) = v7;
	return v7;
}

//----- (0045F19F) --------------------------------------------------------
__int16 __usercall sub_45F19F@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 4);
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 4);
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3 + 4);
	*(_DWORD *)(a5 + 2 * a3 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v5;
	v6 = a3 + a5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2 * a3 + 4);
	*(_DWORD *)(v6 + 2 * a3 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v7 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v7) = a2;
	*(_DWORD *)(v6 + 2 * a3) = v7;
	return v7;
}

//----- (0045F20F) --------------------------------------------------------
int __usercall sub_45F20F@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // esi@1
	int v7; // edi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5) = v5;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3 + 4);
	*(_DWORD *)(a5 + 2 * a3 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3 + 2);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v5;
	v6 = a3 + a5;
	v7 = a3 + a4;
	*(_DWORD *)(v6 + 2 * a3 + 4) = *(_DWORD *)(v7 + 2 * a3 + 4);
	result = *(_DWORD *)(v7 + 2 * a3);
	*(_DWORD *)(v6 + 2 * a3) = result;
	return result;
}

//----- (0045F25F) --------------------------------------------------------
__int16 __usercall sub_45F25F@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1
	int v8; // esi@1
	int v9; // eax@1

	LOWORD_HEXRAYS(a1) = *(_WORD *)(a4 + 6);
	v5 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	v6 = *(_DWORD *)(a3 + a4 + 4);
	*(_DWORD *)(a3 + a5 + 4) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a3 + a5) = v6;
	v7 = *(_DWORD *)(a4 + 2 * a3 + 4);
	*(_DWORD *)(a5 + 2 * a3 + 4) = v7;
	LOWORD_HEXRAYS(v7) = a2;
	v7 = __ROL4__(v7, 16);
	LOWORD_HEXRAYS(v7) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v7;
	v8 = a3 + a5;
	LOWORD_HEXRAYS(v7) = *(_WORD *)(a3 + a4 + 2 * a3 + 6);
	v7 = __ROL4__(v7, 16);
	LOWORD_HEXRAYS(v7) = a2;
	*(_DWORD *)(v8 + 2 * a3 + 4) = v7;
	LOWORD_HEXRAYS(v7) = a2;
	v9 = __ROL4__(v7, 16);
	LOWORD_HEXRAYS(v9) = a2;
	*(_DWORD *)(v8 + 2 * a3) = v9;
	return v9;
}

//----- (0045F2C1) --------------------------------------------------------
__int16 __usercall sub_45F2C1@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // esi@1
	int v6; // eax@1

	*(_DWORD *)(a4 + 4) = *(_DWORD *)(a3 + 4);
	v4 = *(_DWORD *)a3;
	*(_DWORD *)a4 = *(_DWORD *)a3;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a2 + a3 + 2);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a2 + a4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a4 + 2 * a2) = v4;
	*(_DWORD *)(a4 + 2 * a2 + 4) = v4;
	v5 = a2 + a4;
	LOWORD_HEXRAYS(v4) = a1;
	v6 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v6) = a1;
	*(_DWORD *)(v5 + 2 * a2) = v6;
	*(_DWORD *)(v5 + 2 * a2 + 4) = v6;
	return v6;
}

//----- (0045F30F) --------------------------------------------------------
__int16 __usercall sub_45F30F@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1
	int v8; // esi@1
	int v9; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)a4;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	v6 = *(_DWORD *)&a4[a3];
	*(_DWORD *)(a3 + a5) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v6;
	v7 = *(_DWORD *)&a4[2 * a3];
	*(_DWORD *)(a5 + 2 * a3) = v7;
	v8 = a3 + a5;
	LOWORD_HEXRAYS(v7) = a2;
	v7 = __ROR4__(v7, 16);
	LOWORD_HEXRAYS(v7) = a2;
	*(_DWORD *)(v8 + 2 * a3 + 4) = v7;
	LOWORD_HEXRAYS(v7) = a2;
	v9 = __ROL4__(v7, 16);
	LOWORD_HEXRAYS(v9) = *(_WORD *)(&a4[2 * a3] + a3);
	*(_DWORD *)(v8 + 2 * a3) = v9;
	return v9;
}

//----- (0045F36D) --------------------------------------------------------
int __usercall sub_45F36D@<eax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // esi@1
	int result; // eax@1

	v4 = *(_DWORD *)(a3 + 4);
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)a4 = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a2 + a3 + 6);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a2 + a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a2 + a4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a4 + 2 * a2 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a3 + 2 * a2);
	*(_DWORD *)(a4 + 2 * a2) = v4;
	v5 = a2 + a4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(v5 + 2 * a2 + 4) = v4;
	result = *(_DWORD *)(a2 + a3 + 2 * a2);
	*(_DWORD *)(v5 + 2 * a2) = result;
	return result;
}

//----- (0045F3CD) --------------------------------------------------------
__int16 __usercall sub_45F3CD@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // eax@1
	int v9; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	v6 = *(_DWORD *)a4;
	*(_DWORD *)a5 = *(_DWORD *)a4;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)&a4[a3];
	*(_DWORD *)(a3 + a5) = v6;
	LOWORD_HEXRAYS(v6) = *(_WORD *)&a4[2 * a3 + 6];
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v6;
	v7 = a3 + a5;
	v8 = *(_DWORD *)(&a4[2 * a3 + 4] + a3);
	*(_DWORD *)(v7 + 2 * a3 + 4) = v8;
	LOWORD_HEXRAYS(v8) = a2;
	v9 = __ROL4__(v8, 16);
	LOWORD_HEXRAYS(v9) = a2;
	*(_DWORD *)(v7 + 2 * a3) = v9;
	return v9;
}

//----- (0045F42D) --------------------------------------------------------
int __usercall sub_45F42D@<eax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int result; // eax@1

	v4 = *(_DWORD *)(a3 + 4);
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)a4 = v4;
	v5 = *(_DWORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a1;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a2 + a4) = v5;
	LOWORD_HEXRAYS(v5) = a1;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a4 + 2 * a2 + 4) = v5;
	v6 = *(_DWORD *)(a3 + 2 * a2);
	*(_DWORD *)(a4 + 2 * a2) = v6;
	v7 = a2 + a4;
	LOWORD_HEXRAYS(v6) = a1;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a1;
	*(_DWORD *)(v7 + 2 * a2 + 4) = v6;
	result = *(_DWORD *)(a2 + a3 + 2 * a2);
	*(_DWORD *)(v7 + 2 * a2) = result;
	return result;
}

//----- (0045F47F) --------------------------------------------------------
__int16 __usercall sub_45F47F@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // esi@1
	int v7; // edi@1
	int v8; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5) = v5;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3 + 4);
	*(_DWORD *)(a5 + 2 * a3 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3 + 2);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v5;
	v6 = a3 + a5;
	v7 = a3 + a4;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(v7 + 2 * a3 + 4);
	*(_DWORD *)(v6 + 2 * a3 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(v7 + 2 * a3 + 2);
	v8 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v8) = a2;
	*(_DWORD *)(v6 + 2 * a3) = v8;
	return v8;
}

//----- (0045F4DE) --------------------------------------------------------
__int16 __usercall sub_45F4DE@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1
	int v8; // esi@1
	int v9; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	v6 = *(_DWORD *)(a3 + a4 + 4);
	*(_DWORD *)(a3 + a5 + 4) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a3 + a5) = v6;
	v7 = *(_DWORD *)(a4 + 2 * a3 + 4);
	*(_DWORD *)(a5 + 2 * a3 + 4) = v7;
	LOWORD_HEXRAYS(v7) = a2;
	v7 = __ROL4__(v7, 16);
	LOWORD_HEXRAYS(v7) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v7;
	v8 = a3 + a5;
	LOWORD_HEXRAYS(v7) = a2;
	v9 = __ROR4__(v7, 16);
	LOWORD_HEXRAYS(v9) = a2;
	*(_DWORD *)(v8 + 2 * a3) = v9;
	*(_DWORD *)(v8 + 2 * a3 + 4) = v9;
	return v9;
}

//----- (0045F52B) --------------------------------------------------------
__int16 __usercall sub_45F52B@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 4);
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 4);
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v5;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v5;
	v6 = a3 + a5;
	LOWORD_HEXRAYS(v5) = a2;
	v7 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v7) = a2;
	*(_DWORD *)(v6 + 2 * a3) = v7;
	*(_DWORD *)(v6 + 2 * a3 + 4) = v7;
	return v7;
}

//----- (0045F588) --------------------------------------------------------
__int16 __usercall sub_45F588@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1
	int v8; // esi@1
	int v9; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	v6 = *(_DWORD *)(a3 + a4);
	*(_DWORD *)(a3 + a5) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v6;
	v7 = *(_DWORD *)(a4 + 2 * a3);
	*(_DWORD *)(a5 + 2 * a3) = v7;
	v8 = a3 + a5;
	LOWORD_HEXRAYS(v7) = a2;
	v9 = __ROR4__(v7, 16);
	LOWORD_HEXRAYS(v9) = a2;
	*(_DWORD *)(v8 + 2 * a3) = v9;
	*(_DWORD *)(v8 + 2 * a3 + 4) = v9;
	return v9;
}

//----- (0045F5D3) --------------------------------------------------------
int __usercall sub_45F5D3@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // esi@1
	int v7; // edi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5) = v5;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3 + 6);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3);
	*(_DWORD *)(a5 + 2 * a3) = v5;
	v6 = a3 + a5;
	v7 = a3 + a4;
	*(_DWORD *)(v6 + 2 * a3 + 4) = *(_DWORD *)(v7 + 2 * a3 + 4);
	result = *(_DWORD *)(v7 + 2 * a3);
	*(_DWORD *)(v6 + 2 * a3) = result;
	return result;
}

//----- (0045F622) --------------------------------------------------------
__int16 __usercall sub_45F622@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // esi@1
	int v6; // eax@1
	int v7; // eax@1

	v4 = *(_DWORD *)(a3 + 4);
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)a4 = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a2 + a3 + 6);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a2 + a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a2 + a4) = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a3 + 2 * a2 + 6);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a4 + 2 * a2 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a4 + 2 * a2) = v4;
	v5 = a2 + a4;
	v6 = *(_DWORD *)(a2 + a3 + 2 * a2 + 4);
	*(_DWORD *)(v5 + 2 * a2 + 4) = v6;
	LOWORD_HEXRAYS(v6) = a1;
	v7 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v7) = a1;
	*(_DWORD *)(v5 + 2 * a2) = v7;
	return v7;
}

//----- (0045F684) --------------------------------------------------------
__int16 __usercall sub_45F684@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // esi@1
	int v6; // eax@1

	*(_DWORD *)(a4 + 4) = *(_DWORD *)(a3 + 4);
	v4 = *(_DWORD *)a3;
	*(_DWORD *)a4 = *(_DWORD *)a3;
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a2 + a3 + 6);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a2 + a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a2 + a3);
	*(_DWORD *)(a2 + a4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a4 + 2 * a2) = v4;
	*(_DWORD *)(a4 + 2 * a2 + 4) = v4;
	v5 = a2 + a4;
	LOWORD_HEXRAYS(v4) = a1;
	v6 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v6) = a1;
	*(_DWORD *)(v5 + 2 * a2) = v6;
	*(_DWORD *)(v5 + 2 * a2 + 4) = v6;
	return v6;
}

//----- (0045F6D1) --------------------------------------------------------
int __usercall sub_45F6D1@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	v6 = *(_DWORD *)a4;
	*(_DWORD *)a5 = *(_DWORD *)a4;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)&a4[a3];
	*(_DWORD *)(a3 + a5) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)&a4[2 * a3];
	*(_DWORD *)(a5 + 2 * a3) = v6;
	v7 = a3 + a5;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(v7 + 2 * a3 + 4) = v6;
	result = *(_DWORD *)(&a4[2 * a3] + a3);
	*(_DWORD *)(v7 + 2 * a3) = result;
	return result;
}

//----- (0045F781) --------------------------------------------------------
__int16 __usercall sub_45F781@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 6);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3 + 6);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v5;
	v6 = a3 + a5;
	LOWORD_HEXRAYS(v5) = a2;
	v7 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v7) = a2;
	*(_DWORD *)(v6 + 2 * a3) = v7;
	*(_DWORD *)(v6 + 2 * a3 + 4) = v7;
	return v7;
}

//----- (0045F7DC) --------------------------------------------------------
__int16 __usercall sub_45F7DC@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 4);
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5) = v5;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v5;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v5;
	v6 = a3 + a5;
	LOWORD_HEXRAYS(v5) = a2;
	v7 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v7) = a2;
	*(_DWORD *)(v6 + 2 * a3) = v7;
	*(_DWORD *)(v6 + 2 * a3 + 4) = v7;
	return v7;
}

//----- (0045F82C) --------------------------------------------------------
__int16 __usercall sub_45F82C@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4);
	*(_DWORD *)(a3 + a5) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3);
	*(_DWORD *)(a5 + 2 * a3) = v5;
	v6 = a3 + a5;
	LOWORD_HEXRAYS(v5) = a2;
	v7 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v7) = a2;
	*(_DWORD *)(v6 + 2 * a3) = v7;
	*(_DWORD *)(v6 + 2 * a3 + 4) = v7;
	return v7;
}

//----- (0045F885) --------------------------------------------------------
__int16 __usercall sub_45F885@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // eax@1
	int v9; // eax@1

	LOWORD_HEXRAYS(a1) = *(_WORD *)(a4 + 6);
	v5 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 6);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5) = v5;
	v6 = *(_DWORD *)(a4 + 2 * a3 + 4);
	*(_DWORD *)(a5 + 2 * a3 + 4) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v6;
	v7 = a3 + a5;
	v8 = *(_DWORD *)(a3 + a4 + 2 * a3 + 4);
	*(_DWORD *)(v7 + 2 * a3 + 4) = v8;
	LOWORD_HEXRAYS(v8) = a2;
	v9 = __ROL4__(v8, 16);
	LOWORD_HEXRAYS(v9) = a2;
	*(_DWORD *)(v7 + 2 * a3) = v9;
	return v9;
}

//----- (0045F8E7) --------------------------------------------------------
int __usercall sub_45F8E7@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // edi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5) = v5;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	v6 = *(_DWORD *)(a4 + 2 * a3 + 4);
	*(_DWORD *)(a5 + 2 * a3 + 4) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v6;
	v7 = a3 + a5;
	v8 = a3 + a4;
	*(_DWORD *)(v7 + 2 * a3 + 4) = *(_DWORD *)(v8 + 2 * a3 + 4);
	result = *(_DWORD *)(v8 + 2 * a3);
	*(_DWORD *)(v7 + 2 * a3) = result;
	return result;
}

//----- (0045F92E) --------------------------------------------------------
__int16 __usercall sub_45F92E@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // esi@1
	int v6; // eax@1

	*(_DWORD *)(a4 + 4) = *(_DWORD *)(a3 + 4);
	*(_DWORD *)a4 = *(_DWORD *)a3;
	v4 = *(_DWORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a2 + a4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a4 + 2 * a2) = v4;
	*(_DWORD *)(a4 + 2 * a2 + 4) = v4;
	v5 = a2 + a4;
	LOWORD_HEXRAYS(v4) = a1;
	v6 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v6) = a1;
	*(_DWORD *)(v5 + 2 * a2) = v6;
	*(_DWORD *)(v5 + 2 * a2 + 4) = v6;
	return v6;
}

//----- (0045F973) --------------------------------------------------------
__int16 __usercall sub_45F973@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1

	v4 = *(_DWORD *)(a3 + 4);
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)a4 = v4;
	v5 = *(_DWORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a1;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a2 + a4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + 2 * a2 + 6);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a4 + 2 * a2 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a1;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a4 + 2 * a2) = v5;
	v6 = a2 + a4;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a2 + a3 + 2 * a2 + 6);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(v6 + 2 * a2 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a1;
	v7 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v7) = a1;
	*(_DWORD *)(v6 + 2 * a2) = v7;
	return v7;
}

//----- (0045F9D5) --------------------------------------------------------
__int16 __usercall sub_45F9D5@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1

	*(_DWORD *)(a4 + 4) = *(_DWORD *)(a3 + 4);
	v4 = *(_DWORD *)a3;
	*(_DWORD *)a4 = *(_DWORD *)a3;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a2 + a4 + 4) = v4;
	v5 = *(_DWORD *)(a2 + a3);
	*(_DWORD *)(a2 + a4) = v5;
	LOWORD_HEXRAYS(v5) = a1;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a4 + 2 * a2) = v5;
	*(_DWORD *)(a4 + 2 * a2 + 4) = v5;
	v6 = a2 + a4;
	LOWORD_HEXRAYS(v5) = a1;
	v7 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v7) = a1;
	*(_DWORD *)(v6 + 2 * a2) = v7;
	*(_DWORD *)(v6 + 2 * a2 + 4) = v7;
	return v7;
}

//----- (0045FA19) --------------------------------------------------------
__int16 __usercall sub_45FA19@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1
	int v8; // esi@1
	int v9; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	v6 = *(_DWORD *)a4;
	*(_DWORD *)a5 = *(_DWORD *)a4;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v6;
	v7 = *(_DWORD *)&a4[a3];
	*(_DWORD *)(a3 + a5) = v7;
	LOWORD_HEXRAYS(v7) = a2;
	v7 = __ROR4__(v7, 16);
	LOWORD_HEXRAYS(v7) = a2;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v7;
	LOWORD_HEXRAYS(v7) = a2;
	v7 = __ROL4__(v7, 16);
	LOWORD_HEXRAYS(v7) = *(_WORD *)&a4[2 * a3];
	*(_DWORD *)(a5 + 2 * a3) = v7;
	v8 = a3 + a5;
	LOWORD_HEXRAYS(v7) = a2;
	v7 = __ROR4__(v7, 16);
	LOWORD_HEXRAYS(v7) = a2;
	*(_DWORD *)(v8 + 2 * a3 + 4) = v7;
	LOWORD_HEXRAYS(v7) = a2;
	v9 = __ROL4__(v7, 16);
	LOWORD_HEXRAYS(v9) = *(_WORD *)(&a4[2 * a3] + a3);
	*(_DWORD *)(v8 + 2 * a3) = v9;
	return v9;
}

//----- (0045FA77) --------------------------------------------------------
int __usercall sub_45FA77@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)a4;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)&a4[a3];
	*(_DWORD *)(a3 + a5) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v5;
	v6 = *(_DWORD *)&a4[2 * a3];
	*(_DWORD *)(a5 + 2 * a3) = v6;
	v7 = a3 + a5;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(v7 + 2 * a3 + 4) = v6;
	result = *(_DWORD *)(&a4[2 * a3] + a3);
	*(_DWORD *)(v7 + 2 * a3) = result;
	return result;
}

//----- (0045FAD5) --------------------------------------------------------
int __usercall sub_45FAD5@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // esi@1
	int v7; // edi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5) = v5;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v5;
	*(_DWORD *)(a5 + 2 * a3) = *(_DWORD *)(a4 + 2 * a3);
	v6 = a3 + a5;
	v7 = a3 + a4;
	*(_DWORD *)(v6 + 2 * a3 + 4) = *(_DWORD *)(v7 + 2 * a3 + 4);
	result = *(_DWORD *)(v7 + 2 * a3);
	*(_DWORD *)(v6 + 2 * a3) = result;
	return result;
}

//----- (0045FB1B) --------------------------------------------------------
__int16 __usercall sub_45FB1B@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // edi@1
	int v9; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 4);
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a3 + a5 + 4) = *(_DWORD *)(a3 + a4 + 4);
	*(_DWORD *)(a3 + a5) = *(_DWORD *)(a3 + a4);
	*(_DWORD *)(a5 + 2 * a3 + 4) = *(_DWORD *)(a4 + 2 * a3 + 4);
	v6 = *(_DWORD *)(a4 + 2 * a3);
	*(_DWORD *)(a5 + 2 * a3) = v6;
	v7 = a3 + a5;
	v8 = a3 + a4;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)(v8 + 2 * a3 + 4);
	*(_DWORD *)(v7 + 2 * a3 + 4) = v6;
	LOWORD_HEXRAYS(v6) = *(_WORD *)(v8 + 2 * a3 + 2);
	v9 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v9) = a2;
	*(_DWORD *)(v7 + 2 * a3) = v9;
	return v9;
}

//----- (0045FB74) --------------------------------------------------------
__int16 __usercall sub_45FB74@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, _DWORD *a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	v6 = *a4;
	*(_DWORD *)a5 = *a4;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a3 + a5) = v6;
	*(_DWORD *)(a3 + a5 + 4) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = *((_WORD *)a4 + a3 + 2);
	*(_DWORD *)(a5 + 2 * a3 + 4) = v6;
	LOWORD_HEXRAYS(v6) = *((_WORD *)a4 + a3 + 1);
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v6;
	v7 = a3 + a5;
	LOWORD_HEXRAYS(v6) = a2;
	v8 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v8) = a2;
	*(_DWORD *)(v7 + 2 * a3) = v8;
	*(_DWORD *)(v7 + 2 * a3 + 4) = v8;
	return v8;
}

//----- (0045FBC8) --------------------------------------------------------
__int16 __usercall sub_45FBC8@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 4);
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	v6 = *(_DWORD *)(a3 + a4 + 4);
	*(_DWORD *)(a3 + a5 + 4) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a3 + a5) = v6;
	LOWORD_HEXRAYS(v6) = *(_WORD *)(a4 + 2 * a3 + 6);
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v6;
	v7 = a3 + a5;
	LOWORD_HEXRAYS(v6) = a2;
	v8 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v8) = a2;
	*(_DWORD *)(v7 + 2 * a3) = v8;
	*(_DWORD *)(v7 + 2 * a3 + 4) = v8;
	return v8;
}

//----- (0045FC27) --------------------------------------------------------
__int16 __usercall sub_45FC27@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1
	int v8; // esi@1
	int v9; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	v6 = *(_DWORD *)a4;
	*(_DWORD *)a5 = *(_DWORD *)a4;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)&a4[a3 + 4];
	*(_DWORD *)(a3 + a5 + 4) = v6;
	LOWORD_HEXRAYS(v6) = *(_WORD *)&a4[a3 + 2];
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a3 + a5) = v6;
	v7 = *(_DWORD *)&a4[2 * a3 + 4];
	*(_DWORD *)(a5 + 2 * a3 + 4) = v7;
	LOWORD_HEXRAYS(v7) = a2;
	v7 = __ROL4__(v7, 16);
	LOWORD_HEXRAYS(v7) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v7;
	v8 = a3 + a5;
	LOWORD_HEXRAYS(v7) = *(_WORD *)(&a4[2 * a3 + 6] + a3);
	v7 = __ROL4__(v7, 16);
	LOWORD_HEXRAYS(v7) = a2;
	*(_DWORD *)(v8 + 2 * a3 + 4) = v7;
	LOWORD_HEXRAYS(v7) = a2;
	v9 = __ROL4__(v7, 16);
	LOWORD_HEXRAYS(v9) = a2;
	*(_DWORD *)(v8 + 2 * a3) = v9;
	return v9;
}

//----- (0045FC8A) --------------------------------------------------------
__int16 __usercall sub_45FC8A@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // eax@1
	int v9; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)a4;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	v6 = *(_DWORD *)&a4[a3];
	*(_DWORD *)(a3 + a5) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)&a4[2 * a3 + 4];
	*(_DWORD *)(a5 + 2 * a3 + 4) = v6;
	LOWORD_HEXRAYS(v6) = *(_WORD *)&a4[2 * a3 + 2];
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v6;
	v7 = a3 + a5;
	v8 = *(_DWORD *)(&a4[2 * a3 + 4] + a3);
	*(_DWORD *)(v7 + 2 * a3 + 4) = v8;
	LOWORD_HEXRAYS(v8) = a2;
	v9 = __ROL4__(v8, 16);
	LOWORD_HEXRAYS(v9) = a2;
	*(_DWORD *)(v7 + 2 * a3) = v9;
	return v9;
}

//----- (0045FCEC) --------------------------------------------------------
__int16 __usercall sub_45FCEC@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // edi@1
	int v9; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4);
	*(_DWORD *)(a3 + a5) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v5;
	v6 = *(_DWORD *)(a4 + 2 * a3);
	*(_DWORD *)(a5 + 2 * a3) = v6;
	v7 = a3 + a5;
	v8 = a3 + a4;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)(v8 + 2 * a3 + 4);
	*(_DWORD *)(v7 + 2 * a3 + 4) = v6;
	LOWORD_HEXRAYS(v6) = *(_WORD *)(v8 + 2 * a3 + 2);
	v9 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v9) = a2;
	*(_DWORD *)(v7 + 2 * a3) = v9;
	return v9;
}

//----- (0045FD4B) --------------------------------------------------------
__int16 __usercall sub_45FD4B@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1
	int v8; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 4);
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v5;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v5;
	v6 = a3 + a5;
	v7 = *(_DWORD *)(a3 + a4 + 2 * a3 + 4);
	*(_DWORD *)(v6 + 2 * a3 + 4) = v7;
	LOWORD_HEXRAYS(v7) = a2;
	v8 = __ROL4__(v7, 16);
	LOWORD_HEXRAYS(v8) = a2;
	*(_DWORD *)(v6 + 2 * a3) = v8;
	return v8;
}

//----- (0045FDA1) --------------------------------------------------------
__int16 __usercall sub_45FDA1@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 4);
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	v6 = *(_DWORD *)(a3 + a4);
	*(_DWORD *)(a3 + a5) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)(a4 + 2 * a3);
	*(_DWORD *)(a5 + 2 * a3) = v6;
	v7 = a3 + a5;
	LOWORD_HEXRAYS(v6) = a2;
	v8 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v8) = a2;
	*(_DWORD *)(v7 + 2 * a3) = v8;
	*(_DWORD *)(v7 + 2 * a3 + 4) = v8;
	return v8;
}

//----- (0045FDFE) --------------------------------------------------------
__int16 __usercall sub_45FDFE@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1

	v4 = *(_DWORD *)(a3 + 4);
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)a4 = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a2 + a3 + 2);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a2 + a4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a4 + 2 * a2 + 4) = v4;
	v5 = *(_DWORD *)(a3 + 2 * a2);
	*(_DWORD *)(a4 + 2 * a2) = v5;
	v6 = a2 + a4;
	LOWORD_HEXRAYS(v5) = a1;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(v6 + 2 * a2 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a1;
	v7 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v7) = *(_WORD *)(a2 + a3 + 2 * a2);
	*(_DWORD *)(v6 + 2 * a2) = v7;
	return v7;
}

//----- (0045FE60) --------------------------------------------------------
int __usercall sub_45FE60@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = *(_WORD *)(a4 + 6);
	v5 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	v6 = *(_DWORD *)(a3 + a4 + 4);
	*(_DWORD *)(a3 + a5 + 4) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a3 + a5) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)(a4 + 2 * a3 + 4);
	*(_DWORD *)(a5 + 2 * a3 + 4) = v6;
	LOWORD_HEXRAYS(v6) = *(_WORD *)(a4 + 2 * a3 + 2);
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v6;
	v7 = a3 + a5;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(v7 + 2 * a3 + 4) = v6;
	result = *(_DWORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(v7 + 2 * a3) = result;
	return result;
}

//----- (0045FEC3) --------------------------------------------------------
__int16 __usercall sub_45FEC3@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // edi@1
	int v9; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 6);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5) = v5;
	v6 = *(_DWORD *)(a4 + 2 * a3 + 4);
	*(_DWORD *)(a5 + 2 * a3 + 4) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v6;
	v7 = a3 + a5;
	v8 = a3 + a4;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)(v8 + 2 * a3 + 4);
	*(_DWORD *)(v7 + 2 * a3 + 4) = v6;
	LOWORD_HEXRAYS(v6) = *(_WORD *)(v8 + 2 * a3 + 2);
	v9 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v9) = a2;
	*(_DWORD *)(v7 + 2 * a3) = v9;
	return v9;
}

//----- (0045FF24) --------------------------------------------------------
int __usercall sub_45FF24@<eax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // esi@1
	int result; // eax@1

	v4 = *(_DWORD *)(a3 + 4);
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)a4 = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a2 + a4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a4 + 2 * a2 + 4) = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a3 + 2 * a2 + 2);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a4 + 2 * a2) = v4;
	v5 = a2 + a4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(v5 + 2 * a2 + 4) = v4;
	result = *(_DWORD *)(a2 + a3 + 2 * a2);
	*(_DWORD *)(v5 + 2 * a2) = result;
	return result;
}

//----- (0045FF85) --------------------------------------------------------
int __usercall sub_45FF85@<eax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // esi@1
	int v6; // edi@1
	int result; // eax@1

	*(_DWORD *)(a4 + 4) = *(_DWORD *)(a3 + 4);
	v4 = *(_DWORD *)a3;
	*(_DWORD *)a4 = *(_DWORD *)a3;
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a2 + a3 + 6);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a2 + a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a2 + a3);
	*(_DWORD *)(a2 + a4) = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a3 + 2 * a2 + 6);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a4 + 2 * a2 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a3 + 2 * a2);
	*(_DWORD *)(a4 + 2 * a2) = v4;
	v5 = a2 + a4;
	v6 = a2 + a3;
	*(_DWORD *)(v5 + 2 * a2 + 4) = *(_DWORD *)(v6 + 2 * a2 + 4);
	result = *(_DWORD *)(v6 + 2 * a2);
	*(_DWORD *)(v5 + 2 * a2) = result;
	return result;
}

//----- (0045FFDC) --------------------------------------------------------
__int16 __usercall sub_45FFDC@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // esi@1
	int v6; // eax@1

	*(_DWORD *)(a4 + 4) = *(_DWORD *)(a3 + 4);
	*(_DWORD *)a4 = *(_DWORD *)a3;
	*(_DWORD *)(a2 + a4 + 4) = *(_DWORD *)(a2 + a3 + 4);
	v4 = *(_DWORD *)(a2 + a3);
	*(_DWORD *)(a2 + a4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a4 + 2 * a2) = v4;
	*(_DWORD *)(a4 + 2 * a2 + 4) = v4;
	v5 = a2 + a4;
	LOWORD_HEXRAYS(v4) = a1;
	v6 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v6) = a1;
	*(_DWORD *)(v5 + 2 * a2) = v6;
	*(_DWORD *)(v5 + 2 * a2 + 4) = v6;
	return v6;
}

//----- (0046001B) --------------------------------------------------------
int __usercall sub_46001B@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1
	int v8; // eax@1
	int v9; // esi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	v6 = *(_DWORD *)a4;
	*(_DWORD *)a5 = *(_DWORD *)a4;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v6;
	v7 = *(_DWORD *)&a4[a3];
	*(_DWORD *)(a3 + a5) = v7;
	LOWORD_HEXRAYS(v7) = a2;
	v7 = __ROR4__(v7, 16);
	LOWORD_HEXRAYS(v7) = a2;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v7;
	v8 = *(_DWORD *)&a4[2 * a3];
	*(_DWORD *)(a5 + 2 * a3) = v8;
	v9 = a3 + a5;
	LOWORD_HEXRAYS(v8) = a2;
	v8 = __ROR4__(v8, 16);
	LOWORD_HEXRAYS(v8) = a2;
	*(_DWORD *)(v9 + 2 * a3 + 4) = v8;
	result = *(_DWORD *)(&a4[2 * a3] + a3);
	*(_DWORD *)(v9 + 2 * a3) = result;
	return result;
}

//----- (0046006B) --------------------------------------------------------
__int16 __usercall sub_46006B@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // esi@1
	int v6; // eax@1

	*(_DWORD *)(a4 + 4) = *(_DWORD *)(a3 + 4);
	*(_DWORD *)a4 = *(_DWORD *)a3;
	*(_DWORD *)(a2 + a4 + 4) = *(_DWORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4) = *(_DWORD *)(a2 + a3);
	*(_DWORD *)(a4 + 2 * a2 + 4) = *(_DWORD *)(a3 + 2 * a2 + 4);
	v4 = *(_DWORD *)(a3 + 2 * a2);
	*(_DWORD *)(a4 + 2 * a2) = v4;
	v5 = a2 + a4;
	LOWORD_HEXRAYS(v4) = a1;
	v6 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v6) = a1;
	*(_DWORD *)(v5 + 2 * a2) = v6;
	*(_DWORD *)(v5 + 2 * a2 + 4) = v6;
	return v6;
}

//----- (004600A8) --------------------------------------------------------
int __usercall sub_4600A8@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1
	int v8; // eax@1
	int v9; // esi@1
	int v10; // edi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 4);
	*(_DWORD *)(a5 + 4) = v5;
	v6 = *(_DWORD *)a4;
	*(_DWORD *)a5 = *(_DWORD *)a4;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)(a3 + a4 + 4);
	*(_DWORD *)(a3 + a5 + 4) = v6;
	v7 = *(_DWORD *)(a3 + a4);
	*(_DWORD *)(a3 + a5) = v7;
	LOWORD_HEXRAYS(v7) = a2;
	v7 = __ROL4__(v7, 16);
	LOWORD_HEXRAYS(v7) = *(_WORD *)(a4 + 2 * a3 + 4);
	*(_DWORD *)(a5 + 2 * a3 + 4) = v7;
	v8 = *(_DWORD *)(a4 + 2 * a3);
	*(_DWORD *)(a5 + 2 * a3) = v8;
	v9 = a3 + a5;
	v10 = a3 + a4;
	LOWORD_HEXRAYS(v8) = a2;
	v8 = __ROL4__(v8, 16);
	LOWORD_HEXRAYS(v8) = *(_WORD *)(v10 + 2 * a3 + 4);
	*(_DWORD *)(v9 + 2 * a3 + 4) = v8;
	result = *(_DWORD *)(v10 + 2 * a3);
	*(_DWORD *)(v9 + 2 * a3) = result;
	return result;
}

//----- (004600FF) --------------------------------------------------------
int __usercall sub_4600FF@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // esi@1
	int v7; // edi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	*(_DWORD *)(a3 + a5 + 4) = *(_DWORD *)(a3 + a4 + 4);
	*(_DWORD *)(a3 + a5) = *(_DWORD *)(a3 + a4);
	*(_DWORD *)(a5 + 2 * a3 + 4) = *(_DWORD *)(a4 + 2 * a3 + 4);
	*(_DWORD *)(a5 + 2 * a3) = *(_DWORD *)(a4 + 2 * a3);
	v6 = a3 + a5;
	v7 = a3 + a4;
	*(_DWORD *)(v6 + 2 * a3 + 4) = *(_DWORD *)(v7 + 2 * a3 + 4);
	result = *(_DWORD *)(v7 + 2 * a3);
	*(_DWORD *)(v6 + 2 * a3) = result;
	return result;
}

//----- (0046013E) --------------------------------------------------------
__int16 __usercall sub_46013E@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // edi@1
	int v9; // eax@1
	int v10; // eax@1

	v4 = *(_DWORD *)(a3 + 4);
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a3 + 2);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)a4 = v4;
	v5 = *(_DWORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a2 + a3 + 2);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a2 + a4) = v5;
	v6 = *(_DWORD *)(a3 + 2 * a2 + 4);
	*(_DWORD *)(a4 + 2 * a2 + 4) = v6;
	LOWORD_HEXRAYS(v6) = *(_WORD *)(a3 + 2 * a2 + 2);
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a1;
	*(_DWORD *)(a4 + 2 * a2) = v6;
	v7 = a2 + a4;
	v8 = a2 + a3;
	v9 = *(_DWORD *)(v8 + 2 * a2 + 4);
	*(_DWORD *)(v7 + 2 * a2 + 4) = v9;
	LOWORD_HEXRAYS(v9) = *(_WORD *)(v8 + 2 * a2 + 2);
	v10 = __ROL4__(v9, 16);
	LOWORD_HEXRAYS(v10) = a1;
	*(_DWORD *)(v7 + 2 * a2) = v10;
	return v10;
}

//----- (00460199) --------------------------------------------------------
__int16 __usercall sub_460199@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1
	int v8; // esi@1
	int v9; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 4);
	*(_DWORD *)(a5 + 4) = v5;
	v6 = *(_DWORD *)a4;
	*(_DWORD *)a5 = *(_DWORD *)a4;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v6;
	v7 = *(_DWORD *)(a3 + a4);
	*(_DWORD *)(a3 + a5) = v7;
	LOWORD_HEXRAYS(v7) = a2;
	v7 = __ROR4__(v7, 16);
	LOWORD_HEXRAYS(v7) = a2;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v7;
	LOWORD_HEXRAYS(v7) = a2;
	v7 = __ROL4__(v7, 16);
	LOWORD_HEXRAYS(v7) = *(_WORD *)(a4 + 2 * a3);
	*(_DWORD *)(a5 + 2 * a3) = v7;
	v8 = a3 + a5;
	LOWORD_HEXRAYS(v7) = a2;
	v9 = __ROR4__(v7, 16);
	LOWORD_HEXRAYS(v9) = a2;
	*(_DWORD *)(v8 + 2 * a3) = v9;
	*(_DWORD *)(v8 + 2 * a3 + 4) = v9;
	return v9;
}

//----- (004601EE) --------------------------------------------------------
int __usercall sub_4601EE@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // edi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4);
	*(_DWORD *)(a3 + a5) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v5;
	v6 = *(_DWORD *)(a4 + 2 * a3);
	*(_DWORD *)(a5 + 2 * a3) = v6;
	v7 = a3 + a5;
	v8 = a3 + a4;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)(v8 + 2 * a3 + 4);
	*(_DWORD *)(v7 + 2 * a3 + 4) = v6;
	result = *(_DWORD *)(v8 + 2 * a3);
	*(_DWORD *)(v7 + 2 * a3) = result;
	return result;
}

//----- (00460245) --------------------------------------------------------
__int16 __usercall sub_460245@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // edi@1
	int v9; // eax@1
	int v10; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 6);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5) = v5;
	v6 = *(_DWORD *)(a4 + 2 * a3 + 4);
	*(_DWORD *)(a5 + 2 * a3 + 4) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v6;
	v7 = a3 + a5;
	v8 = a3 + a4;
	v9 = *(_DWORD *)(v8 + 2 * a3 + 4);
	*(_DWORD *)(v7 + 2 * a3 + 4) = v9;
	LOWORD_HEXRAYS(v9) = *(_WORD *)(v8 + 2 * a3 + 2);
	v10 = __ROL4__(v9, 16);
	LOWORD_HEXRAYS(v10) = a2;
	*(_DWORD *)(v7 + 2 * a3) = v10;
	return v10;
}

//----- (0046029F) --------------------------------------------------------
__int16 __usercall sub_46029F@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1

	v4 = *(_DWORD *)(a3 + 4);
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a3 + 2);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)a4 = v4;
	v5 = *(_DWORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a1;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a2 + a4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + 2 * a2 + 6);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a4 + 2 * a2 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a1;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a4 + 2 * a2) = v5;
	v6 = a2 + a4;
	LOWORD_HEXRAYS(v5) = a1;
	v7 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v7) = a1;
	*(_DWORD *)(v6 + 2 * a2) = v7;
	*(_DWORD *)(v6 + 2 * a2 + 4) = v7;
	return v7;
}

//----- (004602F7) --------------------------------------------------------
int __usercall sub_4602F7@<eax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // esi@1
	int result; // eax@1

	*(_DWORD *)(a4 + 4) = *(_DWORD *)(a3 + 4);
	*(_DWORD *)a4 = *(_DWORD *)a3;
	*(_DWORD *)(a2 + a4 + 4) = *(_DWORD *)(a2 + a3 + 4);
	v4 = *(_DWORD *)(a2 + a3);
	*(_DWORD *)(a2 + a4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a3 + 2 * a2 + 4);
	*(_DWORD *)(a4 + 2 * a2 + 4) = v4;
	v5 = *(_DWORD *)(a3 + 2 * a2);
	*(_DWORD *)(a4 + 2 * a2) = v5;
	v6 = a2 + a4;
	LOWORD_HEXRAYS(v5) = a1;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(v6 + 2 * a2 + 4) = v5;
	result = *(_DWORD *)(a2 + a3 + 2 * a2);
	*(_DWORD *)(v6 + 2 * a2) = result;
	return result;
}

//----- (0046033E) --------------------------------------------------------
int __usercall sub_46033E@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	char *v8; // edi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	v6 = *(_DWORD *)a4;
	*(_DWORD *)a5 = *(_DWORD *)a4;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)&a4[a3 + 4];
	*(_DWORD *)(a3 + a5 + 4) = v6;
	*(_DWORD *)(a3 + a5) = *(_DWORD *)&a4[a3];
	*(_DWORD *)(a5 + 2 * a3 + 4) = *(_DWORD *)&a4[2 * a3 + 4];
	*(_DWORD *)(a5 + 2 * a3) = *(_DWORD *)&a4[2 * a3];
	v7 = a3 + a5;
	v8 = &a4[a3];
	*(_DWORD *)(v7 + 2 * a3 + 4) = *(_DWORD *)&v8[2 * a3 + 4];
	result = *(_DWORD *)&v8[2 * a3];
	*(_DWORD *)(v7 + 2 * a3) = result;
	return result;
}

//----- (00460386) --------------------------------------------------------
int __usercall sub_460386@<eax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // edi@1
	int result; // eax@1

	v4 = *(_DWORD *)(a3 + 4);
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)a4 = v4;
	v5 = *(_DWORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a2 + a3 + 2);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a2 + a4) = v5;
	*(_DWORD *)(a4 + 2 * a2 + 4) = *(_DWORD *)(a3 + 2 * a2 + 4);
	*(_DWORD *)(a4 + 2 * a2) = *(_DWORD *)(a3 + 2 * a2);
	v6 = a2 + a4;
	v7 = a2 + a3;
	*(_DWORD *)(v6 + 2 * a2 + 4) = *(_DWORD *)(v7 + 2 * a2 + 4);
	result = *(_DWORD *)(v7 + 2 * a2);
	*(_DWORD *)(v6 + 2 * a2) = result;
	return result;
}

//----- (004603D0) --------------------------------------------------------
__int16 __usercall sub_4603D0@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // esi@1
	int v6; // eax@1
	int v7; // eax@1

	*(_DWORD *)(a4 + 4) = *(_DWORD *)(a3 + 4);
	*(_DWORD *)a4 = *(_DWORD *)a3;
	*(_DWORD *)(a2 + a4 + 4) = *(_DWORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4) = *(_DWORD *)(a2 + a3);
	v4 = *(_DWORD *)(a3 + 2 * a2 + 4);
	*(_DWORD *)(a4 + 2 * a2 + 4) = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a3 + 2 * a2 + 2);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a4 + 2 * a2) = v4;
	v5 = a2 + a4;
	v6 = *(_DWORD *)(a2 + a3 + 2 * a2 + 4);
	*(_DWORD *)(v5 + 2 * a2 + 4) = v6;
	LOWORD_HEXRAYS(v6) = a1;
	v7 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v7) = a1;
	*(_DWORD *)(v5 + 2 * a2) = v7;
	return v7;
}

//----- (00460419) --------------------------------------------------------
int __usercall sub_460419@<eax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // esi@1
	int result; // eax@1

	*(_DWORD *)(a4 + 4) = *(_DWORD *)(a3 + 4);
	*(_DWORD *)a4 = *(_DWORD *)a3;
	*(_DWORD *)(a2 + a4 + 4) = *(_DWORD *)(a2 + a3 + 4);
	v4 = *(_DWORD *)(a2 + a3);
	*(_DWORD *)(a2 + a4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a4 + 2 * a2 + 4) = v4;
	v5 = *(_DWORD *)(a3 + 2 * a2);
	*(_DWORD *)(a4 + 2 * a2) = v5;
	v6 = a2 + a4;
	LOWORD_HEXRAYS(v5) = a1;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(v6 + 2 * a2 + 4) = v5;
	result = *(_DWORD *)(a2 + a3 + 2 * a2);
	*(_DWORD *)(v6 + 2 * a2) = result;
	return result;
}

//----- (0046045E) --------------------------------------------------------
int __usercall sub_46045E@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	char *v8; // edi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	v6 = *(_DWORD *)a4;
	*(_DWORD *)a5 = *(_DWORD *)a4;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v6;
	*(_DWORD *)(a3 + a5) = *(_DWORD *)&a4[a3];
	*(_DWORD *)(a5 + 2 * a3 + 4) = *(_DWORD *)&a4[2 * a3 + 4];
	*(_DWORD *)(a5 + 2 * a3) = *(_DWORD *)&a4[2 * a3];
	v7 = a3 + a5;
	v8 = &a4[a3];
	*(_DWORD *)(v7 + 2 * a3 + 4) = *(_DWORD *)&v8[2 * a3 + 4];
	result = *(_DWORD *)&v8[2 * a3];
	*(_DWORD *)(v7 + 2 * a3) = result;
	return result;
}

//----- (004604A4) --------------------------------------------------------
int __usercall sub_4604A4@<eax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // edi@1
	int result; // eax@1

	v4 = *(_DWORD *)(a3 + 4);
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)a4 = v4;
	v5 = *(_DWORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a1;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a2 + a4) = v5;
	*(_DWORD *)(a4 + 2 * a2 + 4) = *(_DWORD *)(a3 + 2 * a2 + 4);
	*(_DWORD *)(a4 + 2 * a2) = *(_DWORD *)(a3 + 2 * a2);
	v6 = a2 + a4;
	v7 = a2 + a3;
	*(_DWORD *)(v6 + 2 * a2 + 4) = *(_DWORD *)(v7 + 2 * a2 + 4);
	result = *(_DWORD *)(v7 + 2 * a2);
	*(_DWORD *)(v6 + 2 * a2) = result;
	return result;
}

//----- (004604EC) --------------------------------------------------------
__int16 __usercall sub_4604EC@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // esi@1
	int v6; // eax@1
	int v7; // eax@1

	*(_DWORD *)(a4 + 4) = *(_DWORD *)(a3 + 4);
	*(_DWORD *)a4 = *(_DWORD *)a3;
	*(_DWORD *)(a2 + a4 + 4) = *(_DWORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4) = *(_DWORD *)(a2 + a3);
	v4 = *(_DWORD *)(a3 + 2 * a2 + 4);
	*(_DWORD *)(a4 + 2 * a2 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a4 + 2 * a2) = v4;
	v5 = a2 + a4;
	v6 = *(_DWORD *)(a2 + a3 + 2 * a2 + 4);
	*(_DWORD *)(v5 + 2 * a2 + 4) = v6;
	LOWORD_HEXRAYS(v6) = a1;
	v7 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v7) = a1;
	*(_DWORD *)(v5 + 2 * a2) = v7;
	return v7;
}

//----- (00460533) --------------------------------------------------------
int __usercall sub_460533@<eax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // esi@1
	int v6; // edi@1
	int result; // eax@1

	*(_DWORD *)(a4 + 4) = *(_DWORD *)(a3 + 4);
	v4 = *(_DWORD *)a3;
	*(_DWORD *)a4 = *(_DWORD *)a3;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a2 + a4) = v4;
	*(_DWORD *)(a2 + a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a4 + 2 * a2) = v4;
	*(_DWORD *)(a4 + 2 * a2 + 4) = v4;
	v5 = a2 + a4;
	v6 = a2 + a3;
	*(_DWORD *)(v5 + 2 * a2 + 4) = *(_DWORD *)(v6 + 2 * a2 + 4);
	result = *(_DWORD *)(v6 + 2 * a2);
	*(_DWORD *)(v5 + 2 * a2) = result;
	return result;
}

//----- (00460572) --------------------------------------------------------
__int16 __usercall sub_460572@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // esi@1
	int v7; // edi@1
	int v8; // eax@1

	LOWORD_HEXRAYS(a1) = *(_WORD *)(a4 + 6);
	v5 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)a4;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 6);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4);
	*(_DWORD *)(a3 + a5) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3 + 6);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 2 * a3);
	*(_DWORD *)(a5 + 2 * a3) = v5;
	v6 = a3 + a5;
	v7 = a3 + a4;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(v7 + 2 * a3 + 6);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(v6 + 2 * a3 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v8 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v8) = *(_WORD *)(v7 + 2 * a3);
	*(_DWORD *)(v6 + 2 * a3) = v8;
	return v8;
}

//----- (004605E5) --------------------------------------------------------
int __usercall sub_4605E5@<eax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // esi@1
	int v6; // edi@1
	int result; // eax@1

	*(_DWORD *)(a4 + 4) = *(_DWORD *)(a3 + 4);
	v4 = *(_DWORD *)a3;
	*(_DWORD *)a4 = *(_DWORD *)a3;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a2 + a4) = v4;
	*(_DWORD *)(a2 + a4 + 4) = v4;
	*(_DWORD *)(a4 + 2 * a2 + 4) = *(_DWORD *)(a3 + 2 * a2 + 4);
	*(_DWORD *)(a4 + 2 * a2) = *(_DWORD *)(a3 + 2 * a2);
	v5 = a2 + a4;
	v6 = a2 + a3;
	*(_DWORD *)(v5 + 2 * a2 + 4) = *(_DWORD *)(v6 + 2 * a2 + 4);
	result = *(_DWORD *)(v6 + 2 * a2);
	*(_DWORD *)(v5 + 2 * a2) = result;
	return result;
}

//----- (00460622) --------------------------------------------------------
int __usercall sub_460622@<eax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // esi@1
	int v6; // edi@1
	int result; // eax@1

	*(_DWORD *)(a4 + 4) = *(_DWORD *)(a3 + 4);
	*(_DWORD *)a4 = *(_DWORD *)a3;
	*(_DWORD *)(a2 + a4 + 4) = *(_DWORD *)(a2 + a3 + 4);
	v4 = *(_DWORD *)(a2 + a3);
	*(_DWORD *)(a2 + a4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a4 + 2 * a2) = v4;
	*(_DWORD *)(a4 + 2 * a2 + 4) = v4;
	v5 = a2 + a4;
	v6 = a2 + a3;
	*(_DWORD *)(v5 + 2 * a2 + 4) = *(_DWORD *)(v6 + 2 * a2 + 4);
	result = *(_DWORD *)(v6 + 2 * a2);
	*(_DWORD *)(v5 + 2 * a2) = result;
	return result;
}

//----- (0046065F) --------------------------------------------------------
__int16 __usercall sub_46065F@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // edi@1
	int v9; // eax@1
	int v10; // eax@1

	v4 = *(_DWORD *)(a3 + 4);
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = *(_WORD *)a3;
	*(_DWORD *)a4 = v4;
	v5 = *(_DWORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a1;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a2 + a3);
	*(_DWORD *)(a2 + a4) = v5;
	v6 = *(_DWORD *)(a3 + 2 * a2 + 4);
	*(_DWORD *)(a4 + 2 * a2 + 4) = v6;
	LOWORD_HEXRAYS(v6) = a1;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)(a3 + 2 * a2);
	*(_DWORD *)(a4 + 2 * a2) = v6;
	v7 = a2 + a4;
	v8 = a2 + a3;
	v9 = *(_DWORD *)(v8 + 2 * a2 + 4);
	*(_DWORD *)(v7 + 2 * a2 + 4) = v9;
	LOWORD_HEXRAYS(v9) = a1;
	v10 = __ROL4__(v9, 16);
	LOWORD_HEXRAYS(v10) = *(_WORD *)(v8 + 2 * a2);
	*(_DWORD *)(v7 + 2 * a2) = v10;
	return v10;
}

//----- (004606B6) --------------------------------------------------------
int __usercall sub_4606B6@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1
	int v8; // eax@1
	int v9; // esi@1
	int v10; // edi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = *(_WORD *)(a4 + 6);
	v5 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	v6 = *(_DWORD *)a4;
	*(_DWORD *)a5 = *(_DWORD *)a4;
	LOWORD_HEXRAYS(v6) = *(_WORD *)(a3 + a4 + 6);
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v6;
	v7 = *(_DWORD *)(a3 + a4);
	*(_DWORD *)(a3 + a5) = v7;
	LOWORD_HEXRAYS(v7) = *(_WORD *)(a4 + 2 * a3 + 6);
	v7 = __ROL4__(v7, 16);
	LOWORD_HEXRAYS(v7) = a2;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v7;
	v8 = *(_DWORD *)(a4 + 2 * a3);
	*(_DWORD *)(a5 + 2 * a3) = v8;
	v9 = a3 + a5;
	v10 = a3 + a4;
	LOWORD_HEXRAYS(v8) = *(_WORD *)(v10 + 2 * a3 + 6);
	v8 = __ROL4__(v8, 16);
	LOWORD_HEXRAYS(v8) = a2;
	*(_DWORD *)(v9 + 2 * a3 + 4) = v8;
	result = *(_DWORD *)(v10 + 2 * a3);
	*(_DWORD *)(v9 + 2 * a3) = result;
	return result;
}

//----- (0046070D) --------------------------------------------------------
__int16 __usercall sub_46070D@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // esi@1
	int v6; // eax@1

	*(_DWORD *)(a4 + 4) = *(_DWORD *)(a3 + 4);
	*(_DWORD *)a4 = *(_DWORD *)a3;
	*(_DWORD *)(a2 + a4 + 4) = *(_DWORD *)(a2 + a3 + 4);
	v4 = *(_DWORD *)(a2 + a3);
	*(_DWORD *)(a2 + a4) = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a3 + 2 * a2 + 6);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a4 + 2 * a2 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a3 + 2 * a2);
	*(_DWORD *)(a4 + 2 * a2) = v4;
	v5 = a2 + a4;
	LOWORD_HEXRAYS(v4) = a1;
	v6 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v6) = a1;
	*(_DWORD *)(v5 + 2 * a2) = v6;
	*(_DWORD *)(v5 + 2 * a2 + 4) = v6;
	return v6;
}

//----- (00460758) --------------------------------------------------------
int __usercall sub_460758@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1
	int v8; // eax@1
	int v9; // esi@1
	int v10; // edi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 4);
	*(_DWORD *)(a5 + 4) = v5;
	v6 = *(_DWORD *)a4;
	*(_DWORD *)a5 = *(_DWORD *)a4;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v6;
	v7 = *(_DWORD *)(a3 + a4);
	*(_DWORD *)(a3 + a5) = v7;
	LOWORD_HEXRAYS(v7) = a2;
	v7 = __ROR4__(v7, 16);
	LOWORD_HEXRAYS(v7) = a2;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v7;
	v8 = *(_DWORD *)(a4 + 2 * a3);
	*(_DWORD *)(a5 + 2 * a3) = v8;
	v9 = a3 + a5;
	v10 = a3 + a4;
	LOWORD_HEXRAYS(v8) = a2;
	v8 = __ROL4__(v8, 16);
	LOWORD_HEXRAYS(v8) = *(_WORD *)(v10 + 2 * a3 + 4);
	*(_DWORD *)(v9 + 2 * a3 + 4) = v8;
	result = *(_DWORD *)(v10 + 2 * a3);
	*(_DWORD *)(v9 + 2 * a3) = result;
	return result;
}

//----- (004607AB) --------------------------------------------------------
int __usercall sub_4607AB@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // esi@1
	int v7; // edi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 6);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4);
	*(_DWORD *)(a3 + a5) = v5;
	*(_DWORD *)(a5 + 2 * a3 + 4) = *(_DWORD *)(a4 + 2 * a3 + 4);
	*(_DWORD *)(a5 + 2 * a3) = *(_DWORD *)(a4 + 2 * a3);
	v6 = a3 + a5;
	v7 = a3 + a4;
	*(_DWORD *)(v6 + 2 * a3 + 4) = *(_DWORD *)(v7 + 2 * a3 + 4);
	result = *(_DWORD *)(v7 + 2 * a3);
	*(_DWORD *)(v6 + 2 * a3) = result;
	return result;
}

//----- (004607F8) --------------------------------------------------------
__int16 __usercall sub_4607F8@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // edi@1
	int v9; // eax@1
	int v10; // eax@1

	v4 = *(_DWORD *)(a3 + 4);
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a3 + 2);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)a4 = v4;
	v5 = *(_DWORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a1;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a2 + a4) = v5;
	v6 = *(_DWORD *)(a3 + 2 * a2 + 4);
	*(_DWORD *)(a4 + 2 * a2 + 4) = v6;
	LOWORD_HEXRAYS(v6) = a1;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a1;
	*(_DWORD *)(a4 + 2 * a2) = v6;
	v7 = a2 + a4;
	v8 = a2 + a3;
	v9 = *(_DWORD *)(v8 + 2 * a2 + 4);
	*(_DWORD *)(v7 + 2 * a2 + 4) = v9;
	LOWORD_HEXRAYS(v9) = *(_WORD *)(v8 + 2 * a2 + 2);
	v10 = __ROL4__(v9, 16);
	LOWORD_HEXRAYS(v10) = a1;
	*(_DWORD *)(v7 + 2 * a2) = v10;
	return v10;
}

//----- (0046084F) --------------------------------------------------------
__int16 __usercall sub_46084F@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1
	int v8; // esi@1
	int v9; // eax@1
	int v10; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	v6 = *(_DWORD *)a4;
	*(_DWORD *)a5 = *(_DWORD *)a4;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)&a4[a3 + 4];
	*(_DWORD *)(a3 + a5 + 4) = v6;
	*(_DWORD *)(a3 + a5) = *(_DWORD *)&a4[a3];
	v7 = *(_DWORD *)&a4[2 * a3 + 4];
	*(_DWORD *)(a5 + 2 * a3 + 4) = v7;
	LOWORD_HEXRAYS(v7) = *(_WORD *)&a4[2 * a3 + 2];
	v7 = __ROL4__(v7, 16);
	LOWORD_HEXRAYS(v7) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v7;
	v8 = a3 + a5;
	v9 = *(_DWORD *)(&a4[2 * a3 + 4] + a3);
	*(_DWORD *)(v8 + 2 * a3 + 4) = v9;
	LOWORD_HEXRAYS(v9) = a2;
	v10 = __ROL4__(v9, 16);
	LOWORD_HEXRAYS(v10) = a2;
	*(_DWORD *)(v8 + 2 * a3) = v10;
	return v10;
}

//----- (004608A5) --------------------------------------------------------
int __usercall sub_4608A5@<eax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int result; // eax@1

	v4 = *(_DWORD *)(a3 + 4);
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)a4 = v4;
	v5 = *(_DWORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a2 + a3 + 2);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a2 + a4) = v5;
	LOWORD_HEXRAYS(v5) = a1;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + 2 * a2 + 4);
	*(_DWORD *)(a4 + 2 * a2 + 4) = v5;
	v6 = *(_DWORD *)(a3 + 2 * a2);
	*(_DWORD *)(a4 + 2 * a2) = v6;
	v7 = a2 + a4;
	LOWORD_HEXRAYS(v6) = a1;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a1;
	*(_DWORD *)(v7 + 2 * a2 + 4) = v6;
	result = *(_DWORD *)(a2 + a3 + 2 * a2);
	*(_DWORD *)(v7 + 2 * a2) = result;
	return result;
}

//----- (004608FB) --------------------------------------------------------
__int16 __usercall sub_4608FB@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1
	int v8; // esi@1
	int v9; // eax@1
	int v10; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	v6 = *(_DWORD *)a4;
	*(_DWORD *)a5 = *(_DWORD *)a4;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v6;
	*(_DWORD *)(a3 + a5) = *(_DWORD *)&a4[a3];
	v7 = *(_DWORD *)&a4[2 * a3 + 4];
	*(_DWORD *)(a5 + 2 * a3 + 4) = v7;
	LOWORD_HEXRAYS(v7) = a2;
	v7 = __ROL4__(v7, 16);
	LOWORD_HEXRAYS(v7) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v7;
	v8 = a3 + a5;
	v9 = *(_DWORD *)(&a4[2 * a3 + 4] + a3);
	*(_DWORD *)(v8 + 2 * a3 + 4) = v9;
	LOWORD_HEXRAYS(v9) = a2;
	v10 = __ROL4__(v9, 16);
	LOWORD_HEXRAYS(v10) = a2;
	*(_DWORD *)(v8 + 2 * a3) = v10;
	return v10;
}

//----- (0046094D) --------------------------------------------------------
__int16 __usercall sub_46094D@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // esi@1
	int v6; // edi@1
	int v7; // eax@1

	*(_DWORD *)(a4 + 4) = *(_DWORD *)(a3 + 4);
	*(_DWORD *)a4 = *(_DWORD *)a3;
	*(_DWORD *)(a2 + a4 + 4) = *(_DWORD *)(a2 + a3 + 4);
	v4 = *(_DWORD *)(a2 + a3);
	*(_DWORD *)(a2 + a4) = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a3 + 2 * a2 + 6);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a4 + 2 * a2 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a3 + 2 * a2);
	*(_DWORD *)(a4 + 2 * a2) = v4;
	v5 = a2 + a4;
	v6 = a2 + a3;
	LOWORD_HEXRAYS(v4) = *(_WORD *)(v6 + 2 * a2 + 6);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(v5 + 2 * a2 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v7 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v7) = *(_WORD *)(v6 + 2 * a2);
	*(_DWORD *)(v5 + 2 * a2) = v7;
	return v7;
}

//----- (004609A4) --------------------------------------------------------
int __usercall sub_4609A4@<eax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // edi@1
	int result; // eax@1

	*(_DWORD *)(a4 + 4) = *(_DWORD *)(a3 + 4);
	v4 = *(_DWORD *)a3;
	*(_DWORD *)a4 = *(_DWORD *)a3;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a2 + a4 + 4) = v4;
	v5 = *(_DWORD *)(a2 + a3);
	*(_DWORD *)(a2 + a4) = v5;
	LOWORD_HEXRAYS(v5) = a1;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a4 + 2 * a2 + 4) = v5;
	*(_DWORD *)(a4 + 2 * a2) = *(_DWORD *)(a3 + 2 * a2);
	v6 = a2 + a4;
	v7 = a2 + a3;
	*(_DWORD *)(v6 + 2 * a2 + 4) = *(_DWORD *)(v7 + 2 * a2 + 4);
	result = *(_DWORD *)(v7 + 2 * a2);
	*(_DWORD *)(v6 + 2 * a2) = result;
	return result;
}

//----- (004609E9) --------------------------------------------------------
int __usercall sub_4609E9@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // esi@1
	int v7; // edi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = *(_WORD *)(a4 + 6);
	v5 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)a4;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 6);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4);
	*(_DWORD *)(a3 + a5) = v5;
	*(_DWORD *)(a5 + 2 * a3 + 4) = *(_DWORD *)(a4 + 2 * a3 + 4);
	*(_DWORD *)(a5 + 2 * a3) = *(_DWORD *)(a4 + 2 * a3);
	v6 = a3 + a5;
	v7 = a3 + a4;
	*(_DWORD *)(v6 + 2 * a3 + 4) = *(_DWORD *)(v7 + 2 * a3 + 4);
	result = *(_DWORD *)(v7 + 2 * a3);
	*(_DWORD *)(v6 + 2 * a3) = result;
	return result;
}

//----- (00460A40) --------------------------------------------------------
int __usercall sub_460A40@<eax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // edi@1
	int result; // eax@1

	*(_DWORD *)(a4 + 4) = *(_DWORD *)(a3 + 4);
	*(_DWORD *)a4 = *(_DWORD *)a3;
	v4 = *(_DWORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a2 + a4) = v4;
	v5 = *(_DWORD *)(a3 + 2 * a2 + 4);
	*(_DWORD *)(a4 + 2 * a2 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a1;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a4 + 2 * a2) = v5;
	v6 = a2 + a4;
	v7 = a2 + a3;
	*(_DWORD *)(v6 + 2 * a2 + 4) = *(_DWORD *)(v7 + 2 * a2 + 4);
	result = *(_DWORD *)(v7 + 2 * a2);
	*(_DWORD *)(v6 + 2 * a2) = result;
	return result;
}

//----- (00460A87) --------------------------------------------------------
__int16 __usercall sub_460A87@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // esi@1
	int v6; // eax@1

	*(_DWORD *)(a4 + 4) = *(_DWORD *)(a3 + 4);
	*(_DWORD *)a4 = *(_DWORD *)a3;
	*(_DWORD *)(a2 + a4 + 4) = *(_DWORD *)(a2 + a3 + 4);
	v4 = *(_DWORD *)(a2 + a3);
	*(_DWORD *)(a2 + a4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a3 + 2 * a2 + 4);
	*(_DWORD *)(a4 + 2 * a2 + 4) = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a3 + 2 * a2 + 2);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a4 + 2 * a2) = v4;
	v5 = a2 + a4;
	LOWORD_HEXRAYS(v4) = a1;
	v6 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v6) = a1;
	*(_DWORD *)(v5 + 2 * a2) = v6;
	*(_DWORD *)(v5 + 2 * a2 + 4) = v6;
	return v6;
}

//----- (00460AD3) --------------------------------------------------------
int __usercall sub_460AD3@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1
	int v8; // eax@1
	int v9; // esi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	v6 = *(_DWORD *)a4;
	*(_DWORD *)a5 = *(_DWORD *)a4;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)&a4[a3 + 4];
	*(_DWORD *)(a3 + a5 + 4) = v6;
	v7 = *(_DWORD *)&a4[a3];
	*(_DWORD *)(a3 + a5) = v7;
	LOWORD_HEXRAYS(v7) = a2;
	v7 = __ROL4__(v7, 16);
	LOWORD_HEXRAYS(v7) = *(_WORD *)&a4[2 * a3 + 4];
	*(_DWORD *)(a5 + 2 * a3 + 4) = v7;
	v8 = *(_DWORD *)&a4[2 * a3];
	*(_DWORD *)(a5 + 2 * a3) = v8;
	v9 = a3 + a5;
	LOWORD_HEXRAYS(v8) = a2;
	v8 = __ROR4__(v8, 16);
	LOWORD_HEXRAYS(v8) = a2;
	*(_DWORD *)(v9 + 2 * a3 + 4) = v8;
	result = *(_DWORD *)(&a4[2 * a3] + a3);
	*(_DWORD *)(v9 + 2 * a3) = result;
	return result;
}

//----- (00460B27) --------------------------------------------------------
int __usercall sub_460B27@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // esi@1
	int v7; // edi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 4);
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + a4 + 2);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5) = v5;
	*(_DWORD *)(a5 + 2 * a3 + 4) = *(_DWORD *)(a4 + 2 * a3 + 4);
	*(_DWORD *)(a5 + 2 * a3) = *(_DWORD *)(a4 + 2 * a3);
	v6 = a3 + a5;
	v7 = a3 + a4;
	*(_DWORD *)(v6 + 2 * a3 + 4) = *(_DWORD *)(v7 + 2 * a3 + 4);
	result = *(_DWORD *)(v7 + 2 * a3);
	*(_DWORD *)(v6 + 2 * a3) = result;
	return result;
}

//----- (00460B75) --------------------------------------------------------
__int16 __usercall sub_460B75@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // eax@1
	int v9; // eax@1

	v4 = *(_DWORD *)(a3 + 4);
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)a4 = v4;
	v5 = *(_DWORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a2 + a3 + 2);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a2 + a4) = v5;
	v6 = *(_DWORD *)(a3 + 2 * a2 + 4);
	*(_DWORD *)(a4 + 2 * a2 + 4) = v6;
	LOWORD_HEXRAYS(v6) = *(_WORD *)(a3 + 2 * a2 + 2);
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a1;
	*(_DWORD *)(a4 + 2 * a2) = v6;
	v7 = a2 + a4;
	v8 = *(_DWORD *)(a2 + a3 + 2 * a2 + 4);
	*(_DWORD *)(v7 + 2 * a2 + 4) = v8;
	LOWORD_HEXRAYS(v8) = a1;
	v9 = __ROL4__(v8, 16);
	LOWORD_HEXRAYS(v9) = a1;
	*(_DWORD *)(v7 + 2 * a2) = v9;
	return v9;
}

//----- (00460BCD) --------------------------------------------------------
__int16 __usercall sub_460BCD@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // esi@1
	int v6; // edi@1
	int v7; // eax@1

	*(_DWORD *)(a4 + 4) = *(_DWORD *)(a3 + 4);
	*(_DWORD *)a4 = *(_DWORD *)a3;
	*(_DWORD *)(a2 + a4 + 4) = *(_DWORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4) = *(_DWORD *)(a2 + a3);
	*(_DWORD *)(a4 + 2 * a2 + 4) = *(_DWORD *)(a3 + 2 * a2 + 4);
	v4 = *(_DWORD *)(a3 + 2 * a2);
	*(_DWORD *)(a4 + 2 * a2) = v4;
	v5 = a2 + a4;
	v6 = a2 + a3;
	LOWORD_HEXRAYS(v4) = *(_WORD *)(v6 + 2 * a2 + 6);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(v5 + 2 * a2 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v7 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v7) = *(_WORD *)(v6 + 2 * a2);
	*(_DWORD *)(v5 + 2 * a2) = v7;
	return v7;
}

//----- (00460C16) --------------------------------------------------------
int __usercall sub_460C16@<eax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // edi@1
	int result; // eax@1

	*(_DWORD *)(a4 + 4) = *(_DWORD *)(a3 + 4);
	v4 = *(_DWORD *)a3;
	*(_DWORD *)a4 = *(_DWORD *)a3;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4 + 4) = v4;
	v5 = *(_DWORD *)(a2 + a3);
	*(_DWORD *)(a2 + a4) = v5;
	LOWORD_HEXRAYS(v5) = a1;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + 2 * a2 + 4);
	*(_DWORD *)(a4 + 2 * a2 + 4) = v5;
	*(_DWORD *)(a4 + 2 * a2) = *(_DWORD *)(a3 + 2 * a2);
	v6 = a2 + a4;
	v7 = a2 + a3;
	*(_DWORD *)(v6 + 2 * a2 + 4) = *(_DWORD *)(v7 + 2 * a2 + 4);
	result = *(_DWORD *)(v7 + 2 * a2);
	*(_DWORD *)(v6 + 2 * a2) = result;
	return result;
}

//----- (00460C5F) --------------------------------------------------------
int __usercall sub_460C5F@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // esi@1
	int v7; // edi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = *(_WORD *)(a4 + 6);
	v5 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)a4;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a3 + a5 + 4) = *(_DWORD *)(a3 + a4 + 4);
	*(_DWORD *)(a3 + a5) = *(_DWORD *)(a3 + a4);
	*(_DWORD *)(a5 + 2 * a3 + 4) = *(_DWORD *)(a4 + 2 * a3 + 4);
	*(_DWORD *)(a5 + 2 * a3) = *(_DWORD *)(a4 + 2 * a3);
	v6 = a3 + a5;
	v7 = a3 + a4;
	*(_DWORD *)(v6 + 2 * a3 + 4) = *(_DWORD *)(v7 + 2 * a3 + 4);
	result = *(_DWORD *)(v7 + 2 * a3);
	*(_DWORD *)(v6 + 2 * a3) = result;
	return result;
}

//----- (00460CA8) --------------------------------------------------------
int __usercall sub_460CA8@<eax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // edi@1
	int result; // eax@1

	*(_DWORD *)(a4 + 4) = *(_DWORD *)(a3 + 4);
	*(_DWORD *)a4 = *(_DWORD *)a3;
	v4 = *(_DWORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a2 + a3 + 2);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a2 + a4) = v4;
	v5 = *(_DWORD *)(a3 + 2 * a2 + 4);
	*(_DWORD *)(a4 + 2 * a2 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a3 + 2 * a2 + 2);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a4 + 2 * a2) = v5;
	v6 = a2 + a4;
	v7 = a2 + a3;
	*(_DWORD *)(v6 + 2 * a2 + 4) = *(_DWORD *)(v7 + 2 * a2 + 4);
	result = *(_DWORD *)(v7 + 2 * a2);
	*(_DWORD *)(v6 + 2 * a2) = result;
	return result;
}

//----- (00460CF3) --------------------------------------------------------
int __usercall sub_460CF3@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1
	int v8; // eax@1
	int v9; // esi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a4 + 4);
	*(_DWORD *)(a5 + 4) = v5;
	v6 = *(_DWORD *)a4;
	*(_DWORD *)a5 = *(_DWORD *)a4;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = *(_WORD *)(a3 + a4 + 4);
	*(_DWORD *)(a3 + a5 + 4) = v6;
	v7 = *(_DWORD *)(a3 + a4);
	*(_DWORD *)(a3 + a5) = v7;
	LOWORD_HEXRAYS(v7) = a2;
	v7 = __ROR4__(v7, 16);
	LOWORD_HEXRAYS(v7) = a2;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v7;
	v8 = *(_DWORD *)(a4 + 2 * a3);
	*(_DWORD *)(a5 + 2 * a3) = v8;
	v9 = a3 + a5;
	LOWORD_HEXRAYS(v8) = a2;
	v8 = __ROR4__(v8, 16);
	LOWORD_HEXRAYS(v8) = a2;
	*(_DWORD *)(v9 + 2 * a3 + 4) = v8;
	result = *(_DWORD *)(a3 + a4 + 2 * a3);
	*(_DWORD *)(v9 + 2 * a3) = result;
	return result;
}

//----- (00460D46) --------------------------------------------------------
__int16 __usercall sub_460D46@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // esi@1
	int v7; // eax@1

	*(_DWORD *)(a4 + 4) = *(_DWORD *)(a3 + 4);
	*(_DWORD *)a4 = *(_DWORD *)a3;
	*(_DWORD *)(a2 + a4 + 4) = *(_DWORD *)(a2 + a3 + 4);
	v4 = *(_DWORD *)(a2 + a3);
	*(_DWORD *)(a2 + a4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a4 + 2 * a2 + 4) = v4;
	v5 = *(_DWORD *)(a3 + 2 * a2);
	*(_DWORD *)(a4 + 2 * a2) = v5;
	v6 = a2 + a4;
	LOWORD_HEXRAYS(v5) = a1;
	v7 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v7) = a1;
	*(_DWORD *)(v6 + 2 * a2) = v7;
	*(_DWORD *)(v6 + 2 * a2 + 4) = v7;
	return v7;
}

//----- (00460D88) --------------------------------------------------------
int __usercall sub_460D88@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // esi@1
	int v7; // edi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	*(_DWORD *)(a3 + a5) = *(_DWORD *)(a3 + a4);
	*(_DWORD *)(a5 + 2 * a3 + 4) = *(_DWORD *)(a4 + 2 * a3 + 4);
	*(_DWORD *)(a5 + 2 * a3) = *(_DWORD *)(a4 + 2 * a3);
	v6 = a3 + a5;
	v7 = a3 + a4;
	*(_DWORD *)(v6 + 2 * a3 + 4) = *(_DWORD *)(v7 + 2 * a3 + 4);
	result = *(_DWORD *)(v7 + 2 * a3);
	*(_DWORD *)(v6 + 2 * a3) = result;
	return result;
}

//----- (00460DCC) --------------------------------------------------------
int __usercall sub_460DCC@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, char *a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // eax@1
	int v8; // eax@1
	int v9; // esi@1
	char *v10; // edi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	v6 = *(_DWORD *)a4;
	*(_DWORD *)a5 = *(_DWORD *)a4;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROR4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a3 + a5 + 4) = v6;
	v7 = *(_DWORD *)&a4[a3];
	*(_DWORD *)(a3 + a5) = v7;
	LOWORD_HEXRAYS(v7) = a2;
	v7 = __ROL4__(v7, 16);
	LOWORD_HEXRAYS(v7) = *(_WORD *)&a4[2 * a3 + 4];
	*(_DWORD *)(a5 + 2 * a3 + 4) = v7;
	v8 = *(_DWORD *)&a4[2 * a3];
	*(_DWORD *)(a5 + 2 * a3) = v8;
	v9 = a3 + a5;
	v10 = &a4[a3];
	LOWORD_HEXRAYS(v8) = a2;
	v8 = __ROL4__(v8, 16);
	LOWORD_HEXRAYS(v8) = *(_WORD *)&v10[2 * a3 + 4];
	*(_DWORD *)(v9 + 2 * a3 + 4) = v8;
	result = *(_DWORD *)&v10[2 * a3];
	*(_DWORD *)(v9 + 2 * a3) = result;
	return result;
}

//----- (00460E20) --------------------------------------------------------
int __usercall sub_460E20@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // edi@1
	int result; // eax@1

	LOWORD_HEXRAYS(a1) = a2;
	v5 = __ROR4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)a5 = v5;
	*(_DWORD *)(a5 + 4) = v5;
	v6 = *(_DWORD *)(a3 + a4 + 4);
	*(_DWORD *)(a3 + a5 + 4) = v6;
	LOWORD_HEXRAYS(v6) = a2;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a2;
	*(_DWORD *)(a3 + a5) = v6;
	*(_DWORD *)(a5 + 2 * a3 + 4) = *(_DWORD *)(a4 + 2 * a3 + 4);
	*(_DWORD *)(a5 + 2 * a3) = *(_DWORD *)(a4 + 2 * a3);
	v7 = a3 + a5;
	v8 = a3 + a4;
	*(_DWORD *)(v7 + 2 * a3 + 4) = *(_DWORD *)(v8 + 2 * a3 + 4);
	result = *(_DWORD *)(v8 + 2 * a3);
	*(_DWORD *)(v7 + 2 * a3) = result;
	return result;
}

//----- (00460E65) --------------------------------------------------------
__int16 __usercall sub_460E65@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // edi@1
	int v9; // eax@1
	int v10; // eax@1

	v4 = *(_DWORD *)(a3 + 4);
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)a4 = v4;
	v5 = *(_DWORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a1;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a2 + a4) = v5;
	v6 = *(_DWORD *)(a3 + 2 * a2 + 4);
	*(_DWORD *)(a4 + 2 * a2 + 4) = v6;
	LOWORD_HEXRAYS(v6) = *(_WORD *)(a3 + 2 * a2 + 2);
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a1;
	*(_DWORD *)(a4 + 2 * a2) = v6;
	v7 = a2 + a4;
	v8 = a2 + a3;
	v9 = *(_DWORD *)(v8 + 2 * a2 + 4);
	*(_DWORD *)(v7 + 2 * a2 + 4) = v9;
	LOWORD_HEXRAYS(v9) = *(_WORD *)(v8 + 2 * a2 + 2);
	v10 = __ROL4__(v9, 16);
	LOWORD_HEXRAYS(v10) = a1;
	*(_DWORD *)(v7 + 2 * a2) = v10;
	return v10;
}

//----- (00460EBD) --------------------------------------------------------
__int16 __usercall sub_460EBD@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // eax@1
	int v6; // eax@1
	int v7; // esi@1
	int v8; // eax@1
	int v9; // eax@1

	v4 = *(_DWORD *)(a3 + 4);
	*(_DWORD *)(a4 + 4) = v4;
	LOWORD_HEXRAYS(v4) = *(_WORD *)(a3 + 2);
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)a4 = v4;
	v5 = *(_DWORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4 + 4) = v5;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(a2 + a3 + 2);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a1;
	*(_DWORD *)(a2 + a4) = v5;
	v6 = *(_DWORD *)(a3 + 2 * a2 + 4);
	*(_DWORD *)(a4 + 2 * a2 + 4) = v6;
	LOWORD_HEXRAYS(v6) = a1;
	v6 = __ROL4__(v6, 16);
	LOWORD_HEXRAYS(v6) = a1;
	*(_DWORD *)(a4 + 2 * a2) = v6;
	v7 = a2 + a4;
	v8 = *(_DWORD *)(a2 + a3 + 2 * a2 + 4);
	*(_DWORD *)(v7 + 2 * a2 + 4) = v8;
	LOWORD_HEXRAYS(v8) = a1;
	v9 = __ROL4__(v8, 16);
	LOWORD_HEXRAYS(v9) = a1;
	*(_DWORD *)(v7 + 2 * a2) = v9;
	return v9;
}

//----- (00460F14) --------------------------------------------------------
__int16 __usercall sub_460F14@<ax>(__int16 a1@<dx>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
	int v4; // eax@1
	int v5; // esi@1
	int v6; // eax@1

	*(_DWORD *)(a4 + 4) = *(_DWORD *)(a3 + 4);
	*(_DWORD *)a4 = *(_DWORD *)a3;
	*(_DWORD *)(a2 + a4 + 4) = *(_DWORD *)(a2 + a3 + 4);
	*(_DWORD *)(a2 + a4) = *(_DWORD *)(a2 + a3);
	v4 = *(_DWORD *)(a3 + 2 * a2 + 4);
	*(_DWORD *)(a4 + 2 * a2 + 4) = v4;
	LOWORD_HEXRAYS(v4) = a1;
	v4 = __ROL4__(v4, 16);
	LOWORD_HEXRAYS(v4) = a1;
	*(_DWORD *)(a4 + 2 * a2) = v4;
	v5 = a2 + a4;
	LOWORD_HEXRAYS(v4) = a1;
	v6 = __ROR4__(v4, 16);
	LOWORD_HEXRAYS(v6) = a1;
	*(_DWORD *)(v5 + 2 * a2) = v6;
	*(_DWORD *)(v5 + 2 * a2 + 4) = v6;
	return v6;
}

//----- (00460F57) --------------------------------------------------------
__int16 __usercall sub_460F57@<ax>(int a1@<eax>, __int16 a2@<dx>, int a3@<ecx>, int a4@<edi>, int a5@<esi>)
{
	int v5; // eax@1
	int v6; // esi@1
	int v7; // edi@1
	int v8; // eax@1

	LOWORD_HEXRAYS(a1) = *(_WORD *)(a4 + 6);
	v5 = __ROL4__(a1, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = *(_WORD *)a4;
	*(_DWORD *)a5 = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a3 + a5) = v5;
	*(_DWORD *)(a3 + a5 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v5 = __ROR4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(a5 + 2 * a3) = v5;
	*(_DWORD *)(a5 + 2 * a3 + 4) = v5;
	v6 = a3 + a5;
	v7 = a3 + a4;
	LOWORD_HEXRAYS(v5) = *(_WORD *)(v7 + 2 * a3 + 6);
	v5 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v5) = a2;
	*(_DWORD *)(v6 + 2 * a3 + 4) = v5;
	LOWORD_HEXRAYS(v5) = a2;
	v8 = __ROL4__(v5, 16);
	LOWORD_HEXRAYS(v8) = *(_WORD *)(v7 + 2 * a3);
	*(_DWORD *)(v6 + 2 * a3) = v8;
	return v8;
}*/