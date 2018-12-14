#include "src/Map.h"

#include "src/_unsorted_data.h"
#include "src/_unsorted_functions.h"
#include "src/RenderDrawHandlers.h"
#include "src/Script.h"
#include "src/ScriptEvent.h"
#include "src/Sprite.h"
#include "src/Sidebar.h"
#include "src/Engine/Entity.h"

#include "src/Engine/Infrastructure/EntityRepository.h"

using Engine::Infrastructure::EntityRepository;



int dword_470588[] = { 1, 0, 0, 0xC0000000 };
int dword_470598 = 0; // weak
int dword_47059C = 0; // weak
int *_4705A8_minimap_smthn = dword_470588; // weak

MobdSprtImage _47CBA0_MobdSprtImage_fog_of_war;
DataMobdItem_stru0 _4705B0_minimap = { 0, 0, 0, &_47CBA0_MobdSprtImage_fog_of_war, NULL, SOUND_0, NULL }; // weak


int _4793F8_map_width; // weak
int _478AAC_map_height; // weak
int _478AB4_map_width_shl_13; // weak
int _478FF0_map_height_shl_13; // weak

MapdScrlImageTile *dword_47CFC0; // weak
MapdScrlImageTile *fog_of_war_tile_15;
int __478AAC_map_height_plus4; // weak
MapdScrlImage *fog_of_war_scrl_source;
int minimap_height; // weak
MapdScrlImageTile *fog_of_war_tile_1;
MapdScrlImageTile *fog_of_war_tile_10;
MapdScrlImageTile *fog_of_war_tile_14;
MapdScrlImageTile *fog_of_war_tile_4;
MapdScrlImage *map_fog_of_war_scrl;
char minimap_fog_of_war_color; // weak
char byte_47CB50[8];
Sprite *_47CB58_minimap_sprite;
MapdScrlImageTile *fog_of_war_tile_11;
MapdScrlImageTile *fog_of_war_tile_7;
MapdScrlImageTile *fog_of_war_tile_3;
int dword_47CB68; // weak
int dword_47CB6C; // weak
MapdScrlImageTile *fog_of_war_tile_13;
void *minimap_revealed_pixels; // idb
MapdScrlImageTile *fog_of_war_tile_6;
int minimap_width; // weak
int __4793F8_map_width_plus4; // weak
MapdScrlImageTile *fog_of_war_tile_8;
void *minimap_fog_of_war_pixels; // idb
DrawHandlerData_Units *_47CB8C_fow;
MapdScrlImageTile *fog_of_war_tile_5;
MapdScrlImageTile *fog_of_war_tile_12;
void *minimap_pixels;
int dword_47CBAC; // weak
Bitmap *fog_of_war_bitmap;
MapdScrlImageTile **map_fog_of_war_scrl_tiles;
MapdScrlImageTile *fog_of_war_tile_9;
MapdScrlImageTile *fog_of_war_tile_2;




//----- (00447000) --------------------------------------------------------
void enable_minimap()
{
    if (!is_game_loading() && _447310_minimap() != 0)
    {
        script_trigger_event(0, EVT_MSG_1514, 0, _47CA10_sidebar_button_minimap->task);
    }
}

//----- (00447050) --------------------------------------------------------
void disable_minimap()
{
    hide_minimap_sprite();
    script_trigger_event(0, EVT_MSG_1548_sidebar, 0, _47CA10_sidebar_button_minimap->task);
}

//----- (0044A500) --------------------------------------------------------
void script_44A500_fog_of_war(Script *a1)
{
    Script *v1; // esi@1
    ScriptEvent *i; // ebp@1
    DrawJobDetails *v3; // ebx@3
    int v4; // esi@3
    int v5; // edi@3
    MouseInput v6; // [sp+10h] [bp-20h]@3

    while (1)
    {
        v1 = a1;
        script_yield_any_trigger(a1, 1);
        for (i = script_get_next_event(a1); i; i = script_get_next_event(v1))
        {
            if (i->event == EVT_MSG_SELECTED)
            {
                v3 = &_47A010_mapd_item_being_drawn[0]->draw_job->job_details;
                input_get_mouse_state(&v6);
                _47CB58_minimap_sprite->field_88_unused = 1;
                v4 = 16 * (v6.cursor_x_x256 - _47CB58_minimap_sprite->x) - (render_width << 7);
                v5 = 16 * (v6.cursor_y_x256 - _47CB58_minimap_sprite->y) - (render_height << 7);
                if (v4 >= 0)
                {
                    if (v4 > (32 - render_width + render_call_draw_handler_mode1(v3)) << 8)
                        v4 = (32 - render_width + render_call_draw_handler_mode1(v3)) << 8;
                }
                else
                {
                    v4 = 0;
                }
                if (v5 >= 0)
                {
                    if (v5 > (render_call_draw_handler_mode2(v3) - render_height) << 8)
                        v5 = (render_call_draw_handler_mode2(v3) - render_height) << 8;
                }
                else
                {
                    v5 = 0;
                }
                _47C380_mapd.mapd_cplc_render_x = v4;
                v1 = a1;
                _47C380_mapd.mapd_cplc_render_y = v5;
            }
            script_discard_event(i);
        }
        dword_47CB68 = _47C380_mapd.mapd_cplc_render_x >> 12;
        dword_47CB6C = _47C380_mapd.mapd_cplc_render_y >> 12;
    }
}

//----- (0044A650) --------------------------------------------------------
void show_minimap_sprite()
{
    _47CB58_minimap_sprite->drawjob->flags &= 0xBFFFFFFF;
    _4705B0_minimap.ptr_10 = (Sprite_stru58 *)&_4705A8_minimap_smthn;
    _47CB58_minimap_sprite->pstru58 = (Sprite_stru58 *)& _4705A8_minimap_smthn;
}

//----- (0044A680) --------------------------------------------------------
void hide_minimap_sprite()
{
    _47CB58_minimap_sprite->drawjob->flags |= 0x40000000u;
    _4705B0_minimap.ptr_10 = 0;
    _47CB58_minimap_sprite->pstru58 = 0;
}
// 4705B0: using guessed type DataMobdItem_stru0 _4705B0_minimap;

//----- (0044A6B0) --------------------------------------------------------
void _44A6B0_minimap(int x, int y)
{
    _47CB58_minimap_sprite->field_88_unused = 1;
    _47CB58_minimap_sprite->x = (x - minimap_width - 4) << 8;
    _47CB58_minimap_sprite->field_88_unused = 1;
    _47CB58_minimap_sprite->y = y << 8;
}
// 47CB7C: using guessed type int minimap_width;

//----- (0044A700) --------------------------------------------------------
void script_44A700_minimap(Script *a1)
{
    Script *script; // edi@1
    Sprite *minimap_sprite; // esi@1

    script = a1;
    minimap_sprite = _447310_minimap();
    if (minimap_sprite)
    {
        if (_47CB58_minimap_sprite)
        {
            script_trigger_event(0, EVT_MSG_SELECTED, 0, minimap_sprite->script);
            script_trigger_event(0, EVT_MOUSE_HOVER, 0, minimap_sprite->script);
            script_sleep(script, 1);
            script_trigger_event(0, EVT_MSG_DESELECTED, 0, minimap_sprite->script);
            script_trigger_event(0, EVT_MOUSE_HOVER, 0, minimap_sprite->script);
        }
    }
}

//----- (0044A780) --------------------------------------------------------
_BYTE *_44A780_gof_of_war()
{
    int v0; // edx@1
    _BYTE *result; // eax@1
    _BYTE *v2; // ecx@1
    int v3; // ebx@1
    MapdScrlImageTile **v4; // ebp@1
    int v5; // esi@2
    int v6; // edi@3
    char v7; // dl@5
    _BYTE *v8; // eax@5

    v0 = map_get_width();
    result = (char *)minimap_fog_of_war_pixels;
    v2 = (char *)minimap_revealed_pixels;
    v3 = 0;
    v4 = &map_fog_of_war_scrl_tiles[2 * map_get_width() + 10];
    if (map_get_height() > 0)
    {
        v5 = minimap_width;
        do
        {
            v6 = 0;
            if (v0 > 0)
            {
                do
                {
                    if (*v4 == (MapdScrlImageTile *)dword_47CFC0)
                    {
                        result[v5] = v2[v5];
                        v8 = result + 1;
                        v8[minimap_width] = v2[minimap_width + 1];
                        *(v8 - 1) = *v2;
                        v7 = *v2;
                    }
                    else
                    {
                        result[v5] = minimap_fog_of_war_color;
                        result[minimap_width + 1] = minimap_fog_of_war_color;
                        *result = minimap_fog_of_war_color;
                        v7 = minimap_fog_of_war_color;
                        v8 = result + 1;
                    }
                    *v8 = v7;
                    v0 = map_get_width();
                    v5 = minimap_width;
                    result = v8 + 1;
                    ++v6;
                    ++v4;
                    v2 += 2;
                } while (v6 < map_get_width());
            }
            ++v3;
            v4 += 4;
            v2 += v5;
            result += v5;
        } while (v3 < map_get_height());
    }
    return result;
}

//----- (0044A840) --------------------------------------------------------
bool minimap_init()
{
    int v2; // eax@4
    MapdScrlImageTile **v4; // ebx@6
    int v5; // esi@6
    char *v7; // edi@9
    int v10; // ecx@10
    int v11; // ebx@11
    int v12; // esi@12
    unsigned char *v13; // edx@12
    int v16; // eax@15
    char v17; // dl@17
    char v18; // cl@17
    int v22; // edx@31
    int v23; // esi@31
    char *v24; // ebp@32
    char *v25; // eax@34
    int v26; // ecx@35
    char *v27; // ebp@37
    char *v28; // eax@39
    int v29; // ecx@40
    int v30; // eax@42
    char *v31; // ebx@42
    char *v32; // eax@44
    int v33; // ecx@45
    int v34; // ebp@47
    char *v35; // eax@49
    int v36; // ecx@50
    int v37; // ecx@52
    char v39; // dl@53
    Sprite *v40; // eax@54
    char *v41; // [sp+10h] [bp-24h]@9
    MapdScrlImageTile **v42; // [sp+14h] [bp-20h]@10
    char v44; // [sp+1Ch] [bp-18h]@17
    int v50; // [sp+30h] [bp-4h]@42

    DataMapd *v1 = LVL_FindMapd();
    if (v1)
    {
        fog_of_war_bitmap = MAPD_Draw(MAPD_FOG_OF_WAR, 0, 0x10000000);
        if (fog_of_war_bitmap)
        {
            fog_of_war_bitmap->draw_job->on_update_handler = (DrawJobUpdateHandler)drawjob_update_handler_448390_fog_of_war;
            fog_of_war_scrl_source = (MapdScrlImage *)fog_of_war_bitmap->draw_job->job_details.image;
            __4793F8_map_width_plus4 = map_get_width() + 4;
            __478AAC_map_height_plus4 = map_get_height() + 4;
            map_fog_of_war_scrl = (MapdScrlImage *)malloc(4 * (map_get_width() + 4) * (map_get_height() + 4) + 20);
            if (map_fog_of_war_scrl)
            {
                map_fog_of_war_scrl->on_draw_handler = fog_of_war_scrl_source->on_draw_handler;
                map_fog_of_war_scrl->tile_x_size = fog_of_war_scrl_source->tile_x_size;
                map_fog_of_war_scrl->tile_y_size = fog_of_war_scrl_source->tile_y_size;
                map_fog_of_war_scrl->num_x_tiles = __4793F8_map_width_plus4;
                map_fog_of_war_scrl->num_y_tiles = __478AAC_map_height_plus4;
                map_fog_of_war_scrl_tiles = map_fog_of_war_scrl->tiles;
                dword_47CFC0 = 0;
                fog_of_war_tile_1 = fog_of_war_scrl_source->tiles[1];
                fog_of_war_tile_2 = fog_of_war_scrl_source->tiles[2];
                fog_of_war_tile_3 = fog_of_war_scrl_source->tiles[3];
                fog_of_war_tile_4 = fog_of_war_scrl_source->tiles[4];
                fog_of_war_tile_5 = fog_of_war_scrl_source->tiles[5];
                fog_of_war_tile_6 = fog_of_war_scrl_source->tiles[6];
                fog_of_war_tile_7 = fog_of_war_scrl_source->tiles[7];
                fog_of_war_tile_8 = fog_of_war_scrl_source->tiles[8];
                fog_of_war_tile_9 = fog_of_war_scrl_source->tiles[9];
                fog_of_war_tile_10 = fog_of_war_scrl_source->tiles[10];
                fog_of_war_tile_11 = fog_of_war_scrl_source->tiles[11];
                fog_of_war_tile_12 = fog_of_war_scrl_source->tiles[12];
                fog_of_war_tile_13 = fog_of_war_scrl_source->tiles[13];
                fog_of_war_tile_14 = fog_of_war_scrl_source->tiles[14];
                v2 = 0;
                for (fog_of_war_tile_15 = fog_of_war_scrl_source->tiles[15];
                    v2 < __4793F8_map_width_plus4 * __478AAC_map_height_plus4;
                    ++v2)
                {
                    map_fog_of_war_scrl_tiles[v2] = fog_of_war_tile_1;
                }

                fog_of_war_bitmap->draw_job->job_details.image = map_fog_of_war_scrl;
                minimap_fog_of_war_color = fog_of_war_tile_1->pixels[0];
                minimap_width = 2 * map_get_width();
                minimap_height = 2 * map_get_height();
                int num_minimap_pixels = minimap_width * minimap_height;
                v4 = v1->items[0].images[0]->tiles;
                v5 = 4 * (minimap_width + minimap_height) + 16;
                minimap_revealed_pixels = malloc(num_minimap_pixels);
                if (minimap_revealed_pixels)
                {
                    minimap_fog_of_war_pixels = malloc(num_minimap_pixels);
                    if (minimap_fog_of_war_pixels)
                    {
                        _47CB8C_fow = (DrawHandlerData_Units *)malloc(v5 + num_minimap_pixels + 12);
                        if (_47CB8C_fow)
                        {
                            _47CB8C_fow->type = 0;
                            v7 = (char *)minimap_revealed_pixels;
                            v41 = (char *)_47CB8C_fow->sprite_data;
                            dword_47CBAC = (int)(&_47CB8C_fow[1].type + 2 * minimap_width);

                            for (int v8 = 0; v8 < minimap_height; ++v8)
                            {
                                v42 = v4;
                                v10 = 16 * (v8 & 1);
                                v11 = (v8 & 1) << 9;
                                for (int v9 = 0; v9 < minimap_width; ++v9)
                                {
                                    v12 = 16 * (v9 & 1);
                                    v13 = &(*v42)->pixels[v11 + v12];
                                    if (*v42)
                                    {
                                        memset(_47CBC0_fow, 0, sizeof(_47CBC0_fow));
                                        for (int v14 = 16; v14 > 0; --v14)
                                        {
                                            for (int v15 = 16; v15 > 0; --v15)
                                            {
                                                v16 = *v13++;
                                                ++_47CBC0_fow[v16];
                                            }
                                            v13 += 16;
                                        }
                                        v17 = 0;
                                        v18 = 1;
                                        v44 = 0;
                                        for (int v19 = 1; v19 < sizeof(_47CBC0_fow); ++v19)
                                        {
                                            if (_47CBC0_fow[v19] > _47CBC0_fow[(unsigned __int8)v44])
                                            {
                                                v17 = v18;
                                                v44 = v18;
                                            }
                                            ++v19;
                                            ++v18;
                                        }
                                        *v7 = v17;
                                    }
                                    else
                                    {
                                        *v7 = 1;
                                    }
                                    if (v12 == 16)
                                        ++v42;
                                    ++v7;
                                }

                                if (v10 == 16)
                                {
                                    v4 += map_get_width();
                                }
                            }

                            memset(minimap_fog_of_war_pixels, minimap_fog_of_war_color, num_minimap_pixels);
                            //memset32(minimap_fog_of_war_pixels, v21, v3 >> 2);
                            //memset(&v20[4 * (v3 >> 2)], v4, v3 & 3);
                            v22 = minimap_width + 4;
                            v23 = minimap_height + 4;
                            if (minimap_width + 4 <= 2)
                            {
                                v24 = v41;
                            }
                            else
                            {
                                v24 = v41;
                                memset(v41, 0xA6u, minimap_width + 2);
                            }
                            v25 = v24;
                            if (v23 > 2)
                            {
                                v26 = v23 - 2;
                                do
                                {
                                    *v25 = -90; // A6 = white viewport border
                                    v25 += v22;
                                    --v26;
                                } while (v26);
                            }
                            v27 = &v24[v22 + 1];
                            if (v22 > 3)
                                memset(v27, 0xA0u, v22 - 3);
                            v28 = v27;
                            if (v23 > 3)
                            {
                                v29 = v23 - 3;
                                do
                                {
                                    *v28 = -96; // A0
                                    v28 += v22;
                                    --v29;
                                } while (v29);
                            }
                            v30 = v22 * (v23 - 1);
                            v31 = &v41[v30];
                            v50 = (int)&v41[v30];
                            if (v22 > 2)
                                memset(&v41[v30 + 1], 0xA0u, v22 - 2);
                            v32 = &v41[2 * v22 - 1];
                            if (v23 > 2)
                            {
                                v33 = v23 - 2;
                                do
                                {
                                    *v32 = -96;
                                    v32 += v22;
                                    --v33;
                                } while (v33);
                            }
                            v34 = (int)&v41[v22 * (v23 - 2)];
                            if (v22 > 3)
                            {
                                memset((void *)(v34 + 2), 0xA6u, v22 - 3); // A6 = white viewport border
                                v31 = (char *)v50;
                            }
                            v35 = &v41[2 * v22 - 2] + v22;
                            if (v23 > 3)
                            {
                                v36 = v23 - 3;
                                do
                                {
                                    *v35 = -90; // A6 = white viewport border
                                    v35 += v22;
                                    --v36;
                                } while (v36);
                            }
                            v37 = 1;
                            v41[v22 - 1] = -93;
                            v41[2 * v22 - 2] = -93;
                            *(_BYTE *)(v34 + 1) = -93;
                            *v31 = -93;
                            int v38 = 1;// &player_sprite_color_by_player_side[1];
                            do
                            {
                                v39 = (_BYTE)player_sprite_color_by_player_side[v38];
                                ++v38;
                                byte_47CB50[v37++] = 16 * v39 + 12;
                            } while (v38 < 7);// ((int)v38 < (int)&UNIT_num_player_units);
                            _47CB8C_fow->width = minimap_width + 4;
                            _47CB8C_fow->height = minimap_height + 4;
                            _47CBA0_MobdSprtImage_fog_of_war.data = _47CB8C_fow;
                            dword_470598 = (minimap_width + 4) << 8;
                            _47CBA0_MobdSprtImage_fog_of_war.flags = 0;
                            _47CBA0_MobdSprtImage_fog_of_war.handler = render_sprt_draw_handler;
                            dword_47059C = (minimap_height + 4) << 8;
                            v40 = sprite_create_scripted(MOBD_MUTE_ALCHEMY_HALL, 0, script_44A500_fog_of_war, SCRIPT_COROUTINE, 0);
                            _47CB58_minimap_sprite = v40;
                            v40->_54_inside_mobd_ptr4 = &_4705B0_minimap;
                            _47CB58_minimap_sprite->drawjob->on_update_handler = (void(*)(void *, DrawJob *))drawjob_update_handler_4483E0_ui;
                            _47CB58_minimap_sprite->script->script_type = SCRIPT_TYPE_47802_fog_of_war;
                            _47CB58_minimap_sprite->drawjob->flags |= 0x40000000u;
                            minimap_pixels = minimap_fog_of_war_pixels;
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

//----- (0044AE30) --------------------------------------------------------
void mapd_44AE30_fog_of_war()
{
    int tmp_minimap_width; // edx@2
    _BYTE *source; // esi@2
    int row_counter; // edi@2
    _BYTE *destination; // eax@2
    int i; // ebp@2
    int line_counter; // ecx@3
    int faction_main_building_level; // eax@7
    Sprite *v8; // eax@12
    int v9; // ecx@12
    int v10; // eax@12
    int v11; // eax@16
    int v12; // edi@18
    int v13; // ecx@19
    Sprite *v15; // eax@26
    int v16; // ecx@26
    int v17; // eax@26
    int v18; // eax@30
    int v19; // edi@32
    int v20; // esi@33
    int v21; // esi@39
    int v22; // edi@40
    _BYTE *v23; // edx@41
    unsigned int v24; // ecx@42
    _BYTE *v25; // edi@42
    int v26; // eax@44
    int v27; // eax@47
    int v28; // eax@50
    int v29; // [sp+10h] [bp-8h]@2
    unsigned int v30; // [sp+14h] [bp-4h]@2

    if (_47CB58_minimap_sprite->pstru58)
    {
        tmp_minimap_width = minimap_width;
        source = (char *)minimap_pixels;
        row_counter = 0;
        v29 = (unsigned int)(render_width - 32) >> 4;
        v30 = (unsigned int)render_height >> 4;
        destination = (_BYTE *)dword_47CBAC;
        for (i = minimap_width + 4; row_counter < minimap_height; destination += 4)
        {
            line_counter = 0;
            if (tmp_minimap_width > 0)
            {
                do
                {
                    *destination = *source;
                    tmp_minimap_width = minimap_width;
                    ++destination;
                    ++source;
                    ++line_counter;
                } while (line_counter < minimap_width);
            }
            ++row_counter;
        }
        if (is_player_faction_evolved())
            faction_main_building_level = get_max_clanhall_level();
        else
            faction_main_building_level = get_max_outpost_level();
        switch (faction_main_building_level)
        {
        case 1:
        case 2:
            for (auto j : entityRepo->FindAll())
            {
                if (j->player_side == player_side)
                {
                    j->sprite->field_88_unused = 1;
                    v8 = j->sprite;
                    v9 = 2 * global2map(v8->x);
                    v10 = 2 * global2map(v8->y);
                    if (v9 >= 0 && v9 < minimap_width && v10 >= 0 && v10 < minimap_height)
                    {
                        v11 = dword_47CBAC + v9 + i * v10;
                        if (*(_BYTE *)v11 != (_BYTE)minimap_fog_of_war_color || *(_BYTE *)(v11 + 1) != (_BYTE)minimap_fog_of_war_color)
                        {
                            v12 = 2;
                            do
                            {
                                v13 = 2;
                                do
                                {
                                    ++v11;
                                    --v13;
                                    *(_BYTE *)(v11 - 1) = byte_47CB50[j->player_side];
                                } while (v13);
                                --v12;
                                v11 = v11 + i - 2;
                            } while (v12);
                        }
                    }
                }
            }
            break;
        case 3:
        case 4:
        case 5:
            for (auto k : entityRepo->FindAll())
            {
                if (k->player_side)
                {
                    k->sprite->field_88_unused = 1;
                    v15 = k->sprite;
                    v16 = 2 * global2map(v15->x);
                    v17 = 2 * global2map(v15->y);
                    if (v16 >= 0 && v16 < minimap_width && v17 >= 0 && v17 < minimap_height)
                    {
                        v18 = dword_47CBAC + v16 + i * v17;
                        if (*(_BYTE *)v18 != (_BYTE)minimap_fog_of_war_color || *(_BYTE *)(v18 + 1) != (_BYTE)minimap_fog_of_war_color)
                        {
                            v19 = 2;
                            do
                            {
                                v20 = 2;
                                do
                                {
                                    ++v18;
                                    --v20;
                                    *(_BYTE *)(v18 - 1) = byte_47CB50[k->player_side];
                                } while (v20);
                                --v19;
                                v18 = v18 + i - 2;
                            } while (v19);
                        }
                    }
                }
            }
            break;
        default:
            break;
        }
        if (dword_47CB68 >= 0 && dword_47CB6C >= 0)
        {
            v21 = v29;
            if (dword_47CB68 <= minimap_width - v29)
            {
                v22 = v30;
                if (dword_47CB6C <= (int)(minimap_height - v30))
                {
                    v23 = (_BYTE *)(dword_47CBAC + dword_47CB68 + dword_47CB6C * i);
                    if (v29 > 1)
                    {
                        v24 = (unsigned int)(v29 - 1) >> 2;
                        memset(v23, 0xA6u, 4 * v24);
                        v25 = &v23[4 * v24];
                        v23 += v29 - 1;
                        v21 = v29;
                        memset(v25, -90, ((_BYTE)v29 - 1) & 3);
                        v22 = v30;
                    }
                    if (v22 > 1)
                    {
                        v26 = v22 - 1;
                        do
                        {
                            *v23 = -90;
                            v23 += i;
                            --v26;
                        } while (v26);
                    }
                    if (v21 > 1)
                    {
                        v27 = v21 - 1;
                        do
                        {
                            *v23-- = -90;
                            --v27;
                        } while (v27);
                    }
                    if (v22 > 1)
                    {
                        v28 = v22 - 1;
                        do
                        {
                            *v23 = -90;
                            v23 -= i;
                            --v28;
                        } while (v28);
                    }
                }
            }
        }
    }
}

//----- (0044B0D0) --------------------------------------------------------
bool is_map_revealed_at(int x, int y)
{
    return *(&map_fog_of_war_scrl_tiles[(x >> 13) + 2] + __4793F8_map_width_plus4 * ((y >> 13) + 2)) != fog_of_war_tile_1;
}

//----- (0044B100) --------------------------------------------------------
void map_reveal_fog_around_entity(Entity *a1)
{
    Sprite *v1; // edx@2
    int v2; // ecx@2
    int v3; // eax@2
    int v4; // edi@2
    int v5; // ecx@3
    int v6; // ecx@5
    int v7; // ebp@6
    int v8; // esi@9
    int v9; // eax@11
    int v10; // ebx@13
    int v11; // ecx@13
    int v12; // edi@15
    int v13; // ecx@15
    char *v14; // edx@15
    char *v15; // ecx@15
    int v16; // esi@18
    int v17; // eax@21
    int v18; // esi@21
    int v19; // edx@21
    int v20; // ebx@21
    int v21; // ecx@27
    bool v22; // zf@27
    bool v23; // sf@27
    unsigned __int8 v24; // of@27
    int v25; // ecx@27
    MapdScrlImageTile **v26; // esi@32
    MapdScrlImageTile *v27; // eax@32
    MapdScrlImageTile *v28; // eax@44
    MapdScrlImageTile *v29; // eax@48
    MapdScrlImageTile *v30; // eax@50
    MapdScrlImageTile *v31; // eax@56
    MapdScrlImageTile *v32; // eax@67
    int v33; // esi@79
    int v34; // ecx@79
    int v35; // edx@80
    MapdScrlImageTile *v36; // eax@81
    MapdScrlImageTile *v37; // eax@93
    MapdScrlImageTile *v38; // eax@98
    MapdScrlImageTile *v39; // edi@110
    int v40; // eax@110
    MapdScrlImageTile *v41; // edi@116
    MapdScrlImageTile *v42; // edi@122
    MapdScrlImageTile *v43; // edi@133
    MapdScrlImageTile *v44; // edi@137
    MapdScrlImageTile *v45; // edx@141
    MapdScrlImageTile **v46; // eax@145
    int v47; // edi@146
    MapdScrlImageTile *v48; // esi@147
    MapdScrlImageTile *v49; // esi@159
    int v50; // eax@163
    int v51; // esi@164
    MapdScrlImageTile *v52; // esi@166
    MapdScrlImageTile *v53; // esi@178
    MapdScrlImageTile *v54; // esi@183
    MapdScrlImageTile *v55; // esi@195
    MapdScrlImageTile *v56; // ecx@200
    MapdScrlImageTile *v57; // esi@201
    MapdScrlImageTile *v58; // esi@207
    MapdScrlImageTile *v59; // esi@218
    int v60; // eax@230
    int v61; // ecx@231
    MapdScrlImageTile *v62; // esi@232
    MapdScrlImageTile *v63; // edx@244
    MapdScrlImageTile *v64; // esi@249
    MapdScrlImageTile *v65; // ecx@253
    MapdScrlImageTile *v66; // esi@261
    MapdScrlImageTile *v67; // edx@265
    MapdScrlImageTile *v68; // esi@267
    MapdScrlImageTile *v69; // esi@273
    MapdScrlImageTile *v70; // esi@283
    int v71; // [sp+0h] [bp-18h]@5
    int v72; // [sp+0h] [bp-18h]@79
    int v73; // [sp+4h] [bp-14h]@29
    int v74; // [sp+8h] [bp-10h]@2
    int v75; // [sp+8h] [bp-10h]@25
    int v76; // [sp+Ch] [bp-Ch]@2
    int v77; // [sp+Ch] [bp-Ch]@22
    int v78; // [sp+10h] [bp-8h]@16
    int v79; // [sp+10h] [bp-8h]@30
    int v80; // [sp+14h] [bp-4h]@32

    if (a1->player_side == player_side)
    {
        a1->sprite->field_88_unused = 1;
        v1 = a1->sprite;
        v2 = a1->stats->view_range;
        v3 = 2 * (v1->x >> 13);
        v4 = 2 * (v1->y >> 13);
        v76 = 2 * (v1->x >> 13);
        v74 = 2 * (v1->y >> 13);
        if (v2 <= 128)
            v5 = 4;
        else
            v5 = v2 >> 5;
        v6 = 2 * v5;
        v71 = v6;
        if (v3 >= v6)
            v7 = v3 - v6;
        else
            v7 = 0;
        if (v4 >= v6)
            v8 = v4 - v6;
        else
            v8 = 0;
        v9 = v6 + v3;
        if (v9 > minimap_width)
            v9 = minimap_width;
        v10 = minimap_height;
        v11 = v4 + v6;
        if (v11 <= minimap_height)
            v10 = v11;
        v12 = minimap_width + v7 - v9;
        v13 = v7 + minimap_width * v8;
        v14 = (char *)minimap_fog_of_war_pixels + v13;
        v15 = (char *)minimap_revealed_pixels + v13;
        if (v8 < v10)
        {
            v78 = v10 - v8;
            do
            {
                if (v7 < v9)
                {
                    v16 = v9 - v7;
                    do
                    {
                        *v14++ = *v15++;
                        --v16;
                    } while (v16);
                }
                v14 += v12;
                v15 += v12;
                --v78;
            } while (v78);
        }
        v17 = v71 / 2;
        v18 = v76 / 2;
        v19 = v71 / 2 - 1;
        v20 = v74 / 2;
        if (v76 / 2 >= v19)
            v77 = v18 - v17 + 2;
        else
            v77 = 1;
        if (v20 >= v19)
            v75 = v20 - v17 + 2;
        else
            v75 = 1;
        v21 = v17 + v18 + 4;
        v24 = __OFSUB__(v21, __4793F8_map_width_plus4);
        v22 = v21 == __4793F8_map_width_plus4;
        v23 = v21 - __4793F8_map_width_plus4 < 0;
        v25 = __4793F8_map_width_plus4 - 2;
        if ((unsigned __int8)(v23 ^ v24) | v22)
            v25 = v17 + v18 + 2;
        v73 = v25;
        if (v17 + v20 + 4 <= __478AAC_map_height_plus4)
            v79 = v17 + v20 + 2;
        else
            v79 = __478AAC_map_height_plus4 - 2;
        v26 = &map_fog_of_war_scrl_tiles[v77 + __4793F8_map_width_plus4 * v75];
        v80 = v77 - v25 + __4793F8_map_width_plus4 - 1;
        v27 = *(&map_fog_of_war_scrl_tiles[v77] + __4793F8_map_width_plus4 * v75 - __4793F8_map_width_plus4);
        if (v27 == fog_of_war_tile_1 || v27 == fog_of_war_tile_4 || v27 == fog_of_war_tile_9 || v27 == fog_of_war_tile_8)
        {
            v32 = *(v26 - 1);
            if (v32 == fog_of_war_tile_1 || v32 == fog_of_war_tile_3 || v32 == fog_of_war_tile_8 || v32 == fog_of_war_tile_7)
            {
                v29 = fog_of_war_tile_6;
            LABEL_78:
                *v26 = v29;
                goto LABEL_79;
            }
            if (v32 == fog_of_war_tile_6
                || v32 == fog_of_war_tile_2
                || v32 == fog_of_war_tile_11
                || v32 == fog_of_war_tile_14)
            {
                *v26 = fog_of_war_tile_2;
            }
            else
            {
                *v26 = (MapdScrlImageTile *)dword_47CFC0;
            }
        }
        else
        {
            if (v27 == fog_of_war_tile_6
                || v27 == fog_of_war_tile_5
                || v27 == fog_of_war_tile_13
                || v27 == fog_of_war_tile_14)
            {
                v31 = *(v26 - 1);
                if (v31 == fog_of_war_tile_1
                    || v31 == fog_of_war_tile_3
                    || v31 == fog_of_war_tile_8
                    || v31 == fog_of_war_tile_7)
                {
                    *v26 = fog_of_war_tile_5;
                    goto LABEL_79;
                }
                if (v31 == fog_of_war_tile_6
                    || v31 == fog_of_war_tile_2
                    || v31 == fog_of_war_tile_11
                    || v31 == fog_of_war_tile_14)
                {
                    *v26 = fog_of_war_tile_10;
                    goto LABEL_79;
                }
                v29 = (MapdScrlImageTile *)dword_47CFC0;
                goto LABEL_78;
            }
            if (v27 != fog_of_war_tile_7
                && v27 != fog_of_war_tile_3
                && v27 != fog_of_war_tile_12
                && v27 != fog_of_war_tile_15)
            {
                v28 = *(v26 - 1);
                if (v28 == fog_of_war_tile_9
                    || v28 == fog_of_war_tile_4
                    || v28 == fog_of_war_tile_12
                    || v28 == fog_of_war_tile_15)
                {
                    *v26 = fog_of_war_tile_13;
                    goto LABEL_79;
                }
                v29 = (MapdScrlImageTile *)dword_47CFC0;
                goto LABEL_78;
            }
            v30 = *(v26 - 1);
            if (v30 == fog_of_war_tile_9
                || v30 == fog_of_war_tile_4
                || v30 == fog_of_war_tile_12
                || v30 == fog_of_war_tile_15)
            {
                *v26 = fog_of_war_tile_14;
            }
            else
            {
                *v26 = fog_of_war_tile_11;
            }
        }
    LABEL_79:
        v33 = (int)(v26 + 1);
        v34 = v77 + 1;
        v72 = v77 + 1;
        if (v77 + 1 < v73)
        {
            v35 = v73 - v34;
            do
            {
                v36 = *(MapdScrlImageTile **)(v33 - 4 * __4793F8_map_width_plus4);
                if (v36 == fog_of_war_tile_1
                    || v36 == fog_of_war_tile_4
                    || v36 == fog_of_war_tile_9
                    || v36 == fog_of_war_tile_8)
                {
                    v37 = fog_of_war_tile_2;
                }
                else if (v36 == fog_of_war_tile_6
                    || v36 == fog_of_war_tile_5
                    || v36 == fog_of_war_tile_13
                    || v36 == fog_of_war_tile_14)
                {
                    v37 = fog_of_war_tile_10;
                }
                else if (v36 == fog_of_war_tile_7
                    || v36 == fog_of_war_tile_3
                    || v36 == fog_of_war_tile_12
                    || v36 == fog_of_war_tile_15)
                {
                    v37 = fog_of_war_tile_11;
                }
                else
                {
                    v37 = (MapdScrlImageTile *)dword_47CFC0;
                }
                *(_DWORD *)v33 = (int)v37;
                v33 += 4;
                --v35;
            } while (v35);
        }
        v38 = *(MapdScrlImageTile **)(v33 - 4 * __4793F8_map_width_plus4);
        if (v38 == fog_of_war_tile_1 || v38 == fog_of_war_tile_4 || v38 == fog_of_war_tile_9 || v38 == fog_of_war_tile_8)
        {
            v43 = *(MapdScrlImageTile **)(v33 + 4);
            v40 = v33 + 4;
            if (v43 == fog_of_war_tile_1 || v43 == fog_of_war_tile_5 || v43 == fog_of_war_tile_9 || v43 == fog_of_war_tile_6)
            {
                v45 = fog_of_war_tile_7;
            }
            else
            {
                v44 = *(MapdScrlImageTile **)(v33 - 4);
                if (v44 == fog_of_war_tile_6
                    || v44 == fog_of_war_tile_2
                    || v44 == fog_of_war_tile_11
                    || v44 == fog_of_war_tile_14)
                {
                    *(_DWORD *)v33 = (int)fog_of_war_tile_2;
                    goto LABEL_145;
                }
                v45 = (MapdScrlImageTile *)dword_47CFC0;
            }
            *(_DWORD *)v33 = (int)v45;
        }
        else if (v38 == fog_of_war_tile_7
            || v38 == fog_of_war_tile_3
            || v38 == fog_of_war_tile_12
            || v38 == fog_of_war_tile_15)
        {
            v42 = *(MapdScrlImageTile **)(v33 + 4);
            v40 = v33 + 4;
            if (v42 == fog_of_war_tile_1 || v42 == fog_of_war_tile_5 || v42 == fog_of_war_tile_9 || v42 == fog_of_war_tile_6)
            {
                v34 = v77 + 1;
                *(_DWORD *)v33 = (int)fog_of_war_tile_3;
            }
            else if (v42 == fog_of_war_tile_7
                || v42 == fog_of_war_tile_2
                || v42 == fog_of_war_tile_10
                || v42 == fog_of_war_tile_15)
            {
                v34 = v77 + 1;
                *(_DWORD *)v33 = (int)fog_of_war_tile_11;
            }
            else
            {
                *(_DWORD *)v33 = (int)dword_47CFC0;
                v34 = v77 + 1;
            }
        }
        else if (v38 == fog_of_war_tile_6
            || v38 == fog_of_war_tile_5
            || v38 == fog_of_war_tile_13
            || v38 == fog_of_war_tile_14)
        {
            v41 = *(MapdScrlImageTile **)(v33 + 4);
            v40 = v33 + 4;
            if (v41 == fog_of_war_tile_8
                || v41 == fog_of_war_tile_4
                || v41 == fog_of_war_tile_13
                || v41 == fog_of_war_tile_14)
            {
                v34 = v77 + 1;
                *(_DWORD *)v33 = (int)fog_of_war_tile_15;
            }
            else
            {
                *(_DWORD *)v33 = (int)fog_of_war_tile_10;
                v34 = v77 + 1;
            }
        }
        else
        {
            v39 = *(MapdScrlImageTile **)(v33 + 4);
            v40 = v33 + 4;
            if (v39 == fog_of_war_tile_8
                || v39 == fog_of_war_tile_4
                || v39 == fog_of_war_tile_13
                || v39 == fog_of_war_tile_14)
            {
                v34 = v77 + 1;
                *(_DWORD *)v33 = (int)fog_of_war_tile_12;
            }
            else
            {
                *(_DWORD *)v33 = (int)dword_47CFC0;
                v34 = v77 + 1;
            }
        }
    LABEL_145:
        v46 = (MapdScrlImageTile **)(4 * v80 + v40);
        if (v75 + 1 < v79)
        {
            v47 = v79 - (v75 + 1);
            do
            {
                v48 = *(v46 - 1);
                if (v48 == fog_of_war_tile_1
                    || v48 == fog_of_war_tile_3
                    || v48 == fog_of_war_tile_8
                    || v48 == fog_of_war_tile_7)
                {
                    v49 = fog_of_war_tile_5;
                }
                else if (v48 == fog_of_war_tile_6
                    || v48 == fog_of_war_tile_2
                    || v48 == fog_of_war_tile_11
                    || v48 == fog_of_war_tile_14)
                {
                    v49 = fog_of_war_tile_10;
                }
                else if (v48 == fog_of_war_tile_9
                    || v48 == fog_of_war_tile_4
                    || v48 == fog_of_war_tile_12
                    || v48 == fog_of_war_tile_15)
                {
                    v49 = fog_of_war_tile_13;
                }
                else
                {
                    v49 = (MapdScrlImageTile *)dword_47CFC0;
                }
                *v46 = v49;
                v50 = (int)(v46 + 1);
                if (v34 < v73)
                {
                    v51 = v73 - v34;
                    do
                    {
                        *(_DWORD *)v50 = (int)dword_47CFC0;
                        v50 += 4;
                        --v51;
                    } while (v51);
                }
                v52 = *(MapdScrlImageTile **)(v50 + 4);
                if (v52 == fog_of_war_tile_1
                    || v52 == fog_of_war_tile_5
                    || v52 == fog_of_war_tile_9
                    || v52 == fog_of_war_tile_6)
                {
                    v53 = fog_of_war_tile_3;
                }
                else if (v52 == fog_of_war_tile_7
                    || v52 == fog_of_war_tile_2
                    || v52 == fog_of_war_tile_10
                    || v52 == fog_of_war_tile_15)
                {
                    v53 = fog_of_war_tile_11;
                }
                else if (v52 == fog_of_war_tile_8
                    || v52 == fog_of_war_tile_4
                    || v52 == fog_of_war_tile_13
                    || v52 == fog_of_war_tile_14)
                {
                    v53 = fog_of_war_tile_12;
                }
                else
                {
                    v53 = (MapdScrlImageTile *)dword_47CFC0;
                }
                *(_DWORD *)v50 = (int)v53;
                v46 = (MapdScrlImageTile **)(4 * v80 + v50 + 4);
                --v47;
            } while (v47);
        }
        v54 = v46[__4793F8_map_width_plus4];
        if (v54 == fog_of_war_tile_1 || v54 == fog_of_war_tile_2 || v54 == fog_of_war_tile_6 || v54 == fog_of_war_tile_7)
        {
            v59 = *(v46 - 1);
            if (v59 != fog_of_war_tile_1 && v59 != fog_of_war_tile_3 && v59 != fog_of_war_tile_8 && v59 != fog_of_war_tile_7)
            {
                if (v59 == fog_of_war_tile_9
                    || v59 == fog_of_war_tile_4
                    || v59 == fog_of_war_tile_12
                    || v59 == fog_of_war_tile_15)
                {
                    *v46 = fog_of_war_tile_4;
                }
                else
                {
                    *v46 = (MapdScrlImageTile *)dword_47CFC0;
                }
            LABEL_230:
                v60 = (int)(v46 + 1);
                if (v72 < v73)
                {
                    v61 = v73 - v72;
                    do
                    {
                        v62 = *(MapdScrlImageTile **)(v60 + 4 * __4793F8_map_width_plus4);
                        if (v62 == fog_of_war_tile_1
                            || v62 == fog_of_war_tile_2
                            || v62 == fog_of_war_tile_6
                            || v62 == fog_of_war_tile_7)
                        {
                            v63 = fog_of_war_tile_4;
                        }
                        else if (v62 == fog_of_war_tile_9
                            || v62 == fog_of_war_tile_5
                            || v62 == fog_of_war_tile_10
                            || v62 == fog_of_war_tile_15)
                        {
                            v63 = fog_of_war_tile_13;
                        }
                        else if (v62 == fog_of_war_tile_8
                            || v62 == fog_of_war_tile_3
                            || v62 == fog_of_war_tile_11
                            || v62 == fog_of_war_tile_14)
                        {
                            v63 = fog_of_war_tile_12;
                        }
                        else
                        {
                            v63 = (MapdScrlImageTile *)dword_47CFC0;
                        }
                        *(_DWORD *)v60 = (int)v63;
                        v60 += 4;
                        --v61;
                    } while (v61);
                }
                v64 = *(MapdScrlImageTile **)(v60 + 4 * __4793F8_map_width_plus4);
                if (v64 == fog_of_war_tile_1
                    || v64 == fog_of_war_tile_2
                    || v64 == fog_of_war_tile_6
                    || v64 == fog_of_war_tile_7)
                {
                    v70 = *(MapdScrlImageTile **)(v60 + 4);
                    if (v70 == fog_of_war_tile_1
                        || v70 == fog_of_war_tile_5
                        || v70 == fog_of_war_tile_9
                        || v70 == fog_of_war_tile_6)
                    {
                        v67 = fog_of_war_tile_8;
                        goto LABEL_295;
                    }
                    if (v70 == fog_of_war_tile_8
                        || v70 == fog_of_war_tile_4
                        || v70 == fog_of_war_tile_13
                        || v70 == fog_of_war_tile_14)
                    {
                        *(_DWORD *)v60 = (int)fog_of_war_tile_4;
                        goto LABEL_296;
                    }
                    v65 = (MapdScrlImageTile *)dword_47CFC0;
                }
                else
                {
                    v65 = fog_of_war_tile_3;
                    if (v64 != fog_of_war_tile_8
                        && v64 != fog_of_war_tile_3
                        && v64 != fog_of_war_tile_11
                        && v64 != fog_of_war_tile_14)
                    {
                        if (v64 == fog_of_war_tile_9
                            || v64 == fog_of_war_tile_5
                            || v64 == fog_of_war_tile_10
                            || v64 == fog_of_war_tile_15)
                        {
                            v68 = *(MapdScrlImageTile **)(v60 + 4);
                            if (v68 != fog_of_war_tile_7
                                && v68 != fog_of_war_tile_2
                                && v68 != fog_of_war_tile_10
                                && v68 != fog_of_war_tile_15)
                            {
                                v67 = fog_of_war_tile_13;
                                goto LABEL_295;
                            }
                            *(_DWORD *)v60 = (int)fog_of_war_tile_14;
                        }
                        else
                        {
                            v66 = *(MapdScrlImageTile **)(v60 + 4);
                            if (v66 != fog_of_war_tile_7
                                && v66 != fog_of_war_tile_2
                                && v66 != fog_of_war_tile_10
                                && v66 != fog_of_war_tile_15)
                            {
                                v67 = (MapdScrlImageTile *)dword_47CFC0;
                            LABEL_295:
                                *(_DWORD *)v60 = (int)v67;
                                goto LABEL_296;
                            }
                            *(_DWORD *)v60 = (int)fog_of_war_tile_11;
                        }
                    LABEL_296:
                        sub_44BC80(v77, v73, v75, v79);
                        return;
                    }
                    v69 = *(MapdScrlImageTile **)(v60 + 4);
                    if (v69 != fog_of_war_tile_1
                        && v69 != fog_of_war_tile_5
                        && v69 != fog_of_war_tile_9
                        && v69 != fog_of_war_tile_6)
                    {
                        if (v69 == fog_of_war_tile_8
                            || v69 == fog_of_war_tile_4
                            || v69 == fog_of_war_tile_13
                            || v69 == fog_of_war_tile_14)
                        {
                            v67 = fog_of_war_tile_12;
                            goto LABEL_295;
                        }
                        *(_DWORD *)v60 = (int)dword_47CFC0;
                        goto LABEL_296;
                    }
                }
                *(_DWORD *)v60 = (int)v65;
                goto LABEL_296;
            }
            v56 = fog_of_war_tile_9;
        }
        else if (v54 == fog_of_war_tile_9
            || v54 == fog_of_war_tile_5
            || v54 == fog_of_war_tile_10
            || v54 == fog_of_war_tile_15)
        {
            v58 = *(v46 - 1);
            if (v58 == fog_of_war_tile_1 || v58 == fog_of_war_tile_3 || v58 == fog_of_war_tile_8 || v58 == fog_of_war_tile_7)
            {
                *v46 = fog_of_war_tile_5;
                goto LABEL_230;
            }
            if (v58 != fog_of_war_tile_9
                && v58 != fog_of_war_tile_4
                && v58 != fog_of_war_tile_12
                && v58 != fog_of_war_tile_15)
            {
                *v46 = (MapdScrlImageTile *)dword_47CFC0;
                goto LABEL_230;
            }
            v56 = fog_of_war_tile_13;
        }
        else if (v54 == fog_of_war_tile_8
            || v54 == fog_of_war_tile_3
            || v54 == fog_of_war_tile_11
            || v54 == fog_of_war_tile_14)
        {
            v57 = *(v46 - 1);
            if (v57 != fog_of_war_tile_6
                && v57 != fog_of_war_tile_2
                && v57 != fog_of_war_tile_11
                && v57 != fog_of_war_tile_14)
            {
                *v46 = fog_of_war_tile_12;
                goto LABEL_230;
            }
            v56 = fog_of_war_tile_15;
        }
        else
        {
            v55 = *(v46 - 1);
            if (v55 != fog_of_war_tile_6
                && v55 != fog_of_war_tile_2
                && v55 != fog_of_war_tile_11
                && v55 != fog_of_war_tile_14)
            {
                *v46 = (MapdScrlImageTile *)dword_47CFC0;
                goto LABEL_230;
            }
            v56 = fog_of_war_tile_10;
        }
        *v46 = v56;
        goto LABEL_230;
    }
}

//----- (0044BC00) --------------------------------------------------------
void minimap_free()
{
    fog_of_war_bitmap->draw_job->job_details.image = 0;
    bitmap_list_remove(fog_of_war_bitmap);
    _47CB58_minimap_sprite->drawjob->job_details.image = 0;
    sprite_list_remove(_47CB58_minimap_sprite);
    free(_47CB8C_fow);
    free(minimap_fog_of_war_pixels);
    free(minimap_revealed_pixels);
    free(map_fog_of_war_scrl);
}

//----- (0044BC80) --------------------------------------------------------
int sub_44BC80(int a1, int a2, int a3, int a4)
{
    int v4; // edi@1
    int v5; // ecx@1
    MapdScrlImage *v6; // edx@1
    int v7; // edi@1
    MapdScrlImage *v8; // ebx@1
    int result; // eax@1
    bool v10; // sf@1
    int i; // ebp@9
    MapdScrlImageTile **v12; // esi@10
    MapdScrlImageTile **v13; // edi@10
    int v14; // ebx@11
    MapdScrlImage *v15; // [sp+10h] [bp-4h]@1
    int v16; // [sp+18h] [bp+4h]@1
    int v17; // [sp+1Ch] [bp+8h]@1

    v4 = a2;
    v5 = a1 - 2;
    v6 = (MapdScrlImage *)_47A010_mapd_item_being_drawn[0]->draw_job->job_details.image;
    v7 = v4 + 2;
    v8 = (MapdScrlImage *)_47A010_mapd_item_being_drawn[1]->draw_job->job_details.image;
    result = a3 - 2;
    v15 = (MapdScrlImage *)_47A010_mapd_item_being_drawn[1]->draw_job->job_details.image;
    v10 = a3 - 2 < 0;
    v17 = a4 + 2;
    v16 = v7;
    if (v10)
        result = 0;
    if (v5 < 0)
        v5 = 0;
    if (v7 >= v6->num_x_tiles)
        v16 = v6->num_x_tiles;
    if (v17 >= v6->num_y_tiles)
        v17 = v6->num_y_tiles;
    for (i = result; i < v17; ++i)
    {
        v12 = &v6->tiles[v5 + v6->num_x_tiles * i];
        v13 = &v8->tiles[v5 + v8->num_x_tiles * i];
        if (v5 < v16)
        {
            v14 = v16 - v5;
            do
            {
                if (*v12)
                    (*v12)->flags &= 0xFFFFFFFD;
                if (*v13)
                    (*v13)->flags &= 0xFFFFFFFD;
                ++v12;
                ++v13;
                --v14;
            } while (v14);
            v8 = v15;
        }
        result = v17;
    }
    return result;
}


//----- (00448360) --------------------------------------------------------
void drawjob_update_handler_level_background(void *a1, DrawJob *a2)
{
    if (_47A010_mapd_item_being_drawn[0])
    {
        a2->job_details.x = _47A010_mapd_item_being_drawn[0]->draw_job->job_details.x;
        a2->job_details.y = _47A010_mapd_item_being_drawn[0]->draw_job->job_details.y;
    }
    a2->job_details.z_index = 0xFFFFF;
}

//----- (00448390) --------------------------------------------------------
void drawjob_update_handler_448390_fog_of_war(Sprite *, DrawJob *a2)
{
    if (_47A010_mapd_item_being_drawn[0])
    {
        a2->job_details.x = _47A010_mapd_item_being_drawn[0]->draw_job->job_details.x - 2 * map_fog_of_war_scrl->tile_x_size;
        a2->job_details.y = _47A010_mapd_item_being_drawn[0]->draw_job->job_details.y - 2 * map_fog_of_war_scrl->tile_y_size;
    }

    // quick fix - minimap background
    if (a2->job_details.x < -10000) 
        a2->job_details.x = 0;
    if (a2->job_details.y < -10000) 
        a2->job_details.y = 0;

    a2->job_details.z_index = 0x10000000;
}

//----- (0044BD50) --------------------------------------------------------
int MAPD_44BD50_alter_tile_flags()
{
    int v0; // ebx@1
    MapdScrlImage *v1; // ecx@1
    MapdScrlImage *v2; // ebp@1
    int result; // eax@1
    int v4; // eax@2
    MapdScrlImageTile **v5; // esi@2
    MapdScrlImageTile **v6; // edi@2
    int v7; // edx@2

    v0 = 0;
    v1 = (MapdScrlImage *)_47A010_mapd_item_being_drawn[0]->draw_job->job_details.image;
    v2 = (MapdScrlImage *)_47A010_mapd_item_being_drawn[1]->draw_job->job_details.image;
    result = v1->num_y_tiles;
    if (result > 0)
    {
        do
        {
            v4 = v1->num_x_tiles;
            v5 = &v1->tiles[v4 * v0];
            v6 = &v2->tiles[v2->num_x_tiles * v0];
            v7 = 0;
            if (v4 > 0)
            {
                do
                {
                    if (*v5)
                        (*v5)->flags |= 2u;
                    if (*v6)
                        (*v6)->flags |= 2u;
                    ++v5;
                    ++v6;
                    ++v7;
                } while (v7 < v1->num_x_tiles);
            }
            result = v1->num_y_tiles;
            ++v0;
        } while (v0 < result);
    }
    return result;
}




//----- (0040F0A0) --------------------------------------------------------
int map_get_entity_placement_inside_tile_x(Entity *a1, int tile_offset)
{
    if (entity_is_regular_vehicle(a1)) {
        return 4096;
    }

    if (entity_is_xl_vehicle(a1)) {
        return 7424;
    }

    if (a1->IsInfantry() && entity_is_infantry(a1))
    {
        switch (tile_offset)
        {
            case ENTITY_TILE_POSITION_1:
            case ENTITY_TILE_POSITION_3:
                return tile2global(8);

            case ENTITY_TILE_POSITION_2:
            case ENTITY_TILE_POSITION_4:
                return tile2global(24);

            default:
                return tile2global(16);
        }
    }

    return 0;
}

//----- (0040F100) --------------------------------------------------------
int map_get_entity_placement_inside_tile_y(Entity *a1, int tile_offset)
{
    if (entity_is_regular_vehicle(a1)) {
        return 4096;
    }

    if (entity_is_xl_vehicle(a1)) {
        return 7424;
    }

    if (a1->IsInfantry() && entity_is_infantry(a1))
    {
        switch (tile_offset)
        {
            case ENTITY_TILE_POSITION_1:
            case ENTITY_TILE_POSITION_4:
                return tile2global(8);

            case ENTITY_TILE_POSITION_2:
            case ENTITY_TILE_POSITION_3:
                return tile2global(24);

            default:
                return tile2global(16);
        }
    }

    return 0;
}



int map_adjust_entity_in_tile_x(Entity *entity, int x) {
    return map_point_to_tile_global(x)
        + map_get_entity_placement_inside_tile_x(entity, entity->_A4_idx_in_tile);
}

int map_adjust_entity_in_tile_y(Entity *entity, int y) {
    return map_point_to_tile_global(y)
        + map_get_entity_placement_inside_tile_y(entity, entity->_A4_idx_in_tile);
}

// rare special case to separate infantry from rest
int map_adjust_entity_in_tile_x_2(Entity *entity, int x) {
    if (entity->IsInfantry()) {
        return map_adjust_entity_in_tile_x(entity, x);
    }
    return 7424 + map_point_to_tile_global(x);
}

// rare special case to separate infantry from rest
int map_adjust_entity_in_tile_y_2(Entity *entity, int y) {
    if (entity->IsInfantry()) {
        return map_adjust_entity_in_tile_y(entity, y);
    }
    return 7424 + map_point_to_tile_global(y);
}
