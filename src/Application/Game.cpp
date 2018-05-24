#define _CRT_SECURE_NO_WARNINGS
#include "Application/Game.h"

#include "src/kknd.h"

#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"

#include "src/Random.h"
#include "src/Render.h"
#include "src/stru29.h"
#include "src/Script.h"
#include "src/ScriptEvent.h"
#include "src/Cursor.h"
#include "src/Coroutine.h"

#include "Engine/Entity.h"

#include "Infrastructure/File.h"
#include "Infrastructure/Input.h"

using Application::Game;

//----- (00423460) --------------------------------------------------------
void Game::Run() {
    int mapd_idx; // ecx@5
    Bitmap **v3; // esi@27

    WaitScreen();

    if (VIDEO_Play(0))
    {
    LABEL_5:
        REND_DirectDrawClearScreen(1);
        mapd_idx = 0;
        netz_47A82C = 0;
        if (!single_player_game)
        {
            if (*(_DWORD *)&netz_47A740[2].str_0[0])
            {
                if (netz_47A834)
                {
                    j_netz_430640();
                    mapd_idx = 7;
                }
                else
                {
                    mapd_idx = 8;
                }
            }
            else
            {
                mapd_idx = netz_468B6C_providers_idx != 0 ? 1 : 4;
            }
        }
        GAME_PrepareSuperLvl(mapd_idx);
        game_state = 0;
        do
        {
            sprite_list_init_mobd_items();
            sprite_list_update_positions();
            input_update_keyboard();
            input_update_mouse();
            _43A370_process_sound();
            stru1_animate();
            script_list_update();
            _4393F0_call_mapd();
            VIDEO_DoFrame();
            draw_list_update_and_draw();
            TimedMessagePump();
        } while (!_47DCF4_wm_quit_received && !game_state);

        for (int mapd_item = 0; mapd_item < 3; ++mapd_item)
        {
            if (_47A010_mapd_item_being_drawn[mapd_item])
            {
                bitmap_list_remove(_47A010_mapd_item_being_drawn[mapd_item]);
                _47A010_mapd_item_being_drawn[mapd_item] = 0;
            }
        }

        LVL_Deinit();
        dword_47A180 = 0;
        free(current_level_lvl);
        free(sprites_lvl);
        sprites_lvl = 0;
        if (is_game_loading())
        {
            prev_level_idx = -1;
            current_level_idx = get_saveload_level_id();
            set_player_side_by_level();
        }
        if (game_state != 3)
        {
            while (1)
            {
                REND_DirectDrawClearScreen(1);
                if (!is_game_loading())
                {
                    if (current_level_idx < LEVEL_SURV_16 || current_level_idx > LEVEL_MUTE_25)
                    {
                        //VIDEO_Play(1);
                    }
                    else
                    {
                        GAME_PrepareSuperLvl(13);
                        game_state = 0;
                        do
                        {
                            sprite_list_init_mobd_items();
                            sprite_list_update_positions();
                            input_update_keyboard();
                            input_update_mouse();
                            _43A370_process_sound();
                            stru1_animate();
                            script_list_update();
                            _4393F0_call_mapd();
                            VIDEO_DoFrame();
                            draw_list_update_and_draw();
                            TimedMessagePump();
                        } while (!_47DCF4_wm_quit_received && !game_state);
                        v3 = _47A010_mapd_item_being_drawn;
                        do
                        {
                            if (*v3)
                            {
                                bitmap_list_remove(*v3);
                                *v3 = 0;
                            }
                            ++v3;
                        } while ((int)v3 < (int)& _47A01C_sound_id);
                        LVL_Deinit();
                        dword_47A180 = 0;
                        free(current_level_lvl);
                        free(sprites_lvl);
                        sprites_lvl = 0;
                        if (is_game_loading())
                        {
                            prev_level_idx = -1;
                            current_level_idx = get_saveload_level_id();
                            set_player_side_by_level();
                        }
                    }
                    if (_47DCF4_wm_quit_received)
                        break;
                }
                GAME_PrepareLevel();
                game_state = 0;
                do
                {
                    if (!single_player_game)
                        is_coroutine_list_initialization_failed = dword_47A738 != 0;
                    sprite_list_init_mobd_items();
                    sprite_list_update_positions();
                    input_update_keyboard();
                    input_update_mouse();
                    _43A370_process_sound();
                    stru1_animate();
                    boxd_40EA20();
                    _44C4B0_mess_with_turrets();
                    script_list_update();
                    _4393F0_call_mapd();
                    draw_list_update_and_draw();
                    TimedMessagePump();
                    if (is_game_saving())
                    {
                        sound_list_43A800(0);
                        if (!GAME_Save())
                            GAME_OnSaveFailed();
                        sound_list_43A800(_4690AC_level_wav_sound_offset);
                    }
                } while (!_47DCF4_wm_quit_received && !game_state);
                if (!on_level_finished())
                {
                    dword_47CB0C = 0;
                    VIDEO_Play(2);
                    if (!_47DCF4_wm_quit_received)
                        goto LABEL_5;
                    break;
                }
            }
        }
        netz_deinit();
        free(wait_lvl);
        sound_free_sounds();
        GAME_Deinit();
        timeEndPeriod(1u);
    }
    else
    {
        free(wait_lvl);
        sound_free_sounds();
        GAME_Deinit();
    }
}


//----- (00422610) --------------------------------------------------------
void Game::WaitScreen() {
    int v0; // eax@12
    DataMapd *v4; // eax@24
    int v5; // esi@24

    GAME_ReadRegistry();
    _4240E0_kknd_sve_read(pKknd_sve);
    GAME_ParseCommandLine();
    if (!LVL_SysInit())
    {
        log("LVL_SysInit() failed\n");
        Terminate();
    }

    REND_SetRoutines();

    if (nocd)
        strcpy(app_root_dir, a_);
    else
        sprintf(app_root_dir, aC, game_installation_drive_letter);

    v0 = netz_init(-1, nullsub_1, (int(*)(int))netz_42E820);
    if (v0)
    {
        log("NETZ_Init() failed %02x: %s\n", v0, netz_get_error_string(v0));
        Terminate();
    }

    wait_lvl = LVL_LoadLevel("wait.lvl");
    if (!wait_lvl)
    {
        log("LVL_LoadLevel(wait.lvl) failed\n");
        Terminate();
    }
    _47A010_mapd_item_being_drawn[0] = 0;
    _47A010_mapd_item_being_drawn[1] = 0;
    _47A010_mapd_item_being_drawn[2] = 0;
    message_pump();
    if (!LVL_RunLevel(wait_lvl))
    {
        log("Wait LVL_RunLevel() failed\n");
        Terminate();
    }
    v4 = LVL_FindMapd();
    _40E400_set_palette(&v4->items->palette);
    _47A010_mapd_item_being_drawn[0] = MAPD_Draw(MAPD_MAP, 0, 0);
    _47C380_mapd.mapd_cplc_render_y = 0x1EA00;     // 490
    v5 = 1;
    do
    {
        draw_list_update_and_draw();
        TimedMessagePump();
        --v5;
    } while (v5);
    bitmap_list_remove(_47A010_mapd_item_being_drawn[0]);
    LVL_Deinit();
}

void Game::Terminate() {
    netz_deinit();
    GAME_Deinit();
}