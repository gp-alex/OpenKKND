#include "src/_unsorted_data.h"
#include "src/_unsorted_functions.h"
#include "src/kknd.h"
#include "src/Map.h"
#include "src/Pathfind.h"
#include "src/Sprite.h"
#include "src/stru31.h"

#include "src/Infrastructure/Log.h"
#include "src/Infrastructure/PlatformSpecific/OsTools.h"


//----- (00422F60) --------------------------------------------------------
void GAME_PrepareLevel()
{
    enum LEVEL_ID v0; // edx@1
                      //char *v1; // eax@3
                      //const char *v2; // ST10_4@16
                      //char *v3; // eax@16
    DataHunk *level_lvl; // eax@16
                         //int v5; // eax@24
    DataMapd *v6; // eax@28
                  //char filename[120]; // [sp+8h] [bp-78h]@3

    v0 = current_level_idx;
    if (current_level_idx != prev_level_idx)
    {
        prev_level_idx = current_level_idx;
        if (!sprites_lvl)
        {
            sprites_lvl = LVL_LoadLevel("sprites.lvl");
            if (!sprites_lvl)
            {
                LVL_Deinit();
                netz_deinit();
                GAME_Deinit();
                log(aSpriteLoadFail);
                exit(0);
            }
            v0 = current_level_idx;
        }
        if (_47A2E4_mess_with_game_dir
            || !is_minimal_install
            || (v0 < LEVEL_SURV_01_THE_NEXT_GENERATION || v0 > LEVEL_MUTE_15) && (v0 < LEVEL_SURV_16 || v0 > LEVEL_MUTE_25))
        {
            strcpy(game_data_root_dir, game_data_installation_dir);
        }
        else
        {
            sprintf(game_data_root_dir, aC, game_installation_drive_letter);
            v0 = current_level_idx;
        }

        level_lvl = LVL_LoadLevel(levels[v0].lvl_filename);
        current_level_lvl = level_lvl;
        if (!level_lvl)
        {
            LVL_Deinit();
            netz_deinit();
            GAME_Deinit();
            log("LVL_LoadLevel(%s) failed\n", levels[v0].lvl_filename);
            exit(0);
        }
        if (!LVL_SubstHunk(level_lvl, sprites_lvl, (const char *)MOBD))
        {
            LVL_Deinit();
            netz_deinit();
            GAME_Deinit();
            log("LVL_SubstHunk( ) failed\n");
            exit(0);
        }
    }

    LVL_LoadSlv(slvs[is_player_faction_evolved()]);
    if (!LVL_RunLevel(current_level_lvl))
    {
        netz_deinit();
        GAME_Deinit();
        log("LVL_RunLevel() failed\n");
        exit(0);
    }
    stru1_408480_reset_animation();
    v6 = LVL_FindMapd();
    _40E400_set_palette((Palette *)&v6->items[1]);
    sidebar_button_list_alloc();
    boxd_40E6E0();
    _44C010_init_mission_globals();
    sidebar_initialize();
    stru31_list_alloc();
    if (!UNIT_Init())
    {
        netz_deinit();
        GAME_Deinit();
        log(aUnit_initFaile);
        exit(0);
    }
    stru37_stru38_list_alloc();
    nullsub_3();
    if (_4690AC_level_wav_sound_offset)
    {
        _47A01C_sound_id = sound_play_threaded(levels[current_level_idx].wav_filename, 1, _4690AC_level_wav_sound_offset, 16, 0);
    }
    render_default_stru1->field_8 &= 0xBFFFFFFF;
    _47A010_mapd_item_being_drawn[0] = MAPD_Draw(MAPD_MAP, 0, 0);
    _47A010_mapd_item_being_drawn[1] = MAPD_Draw(MAPD_MAP, 1u, 0x20000000);
    _47A010_mapd_item_being_drawn[1]->draw_job->on_update_handler = drawjob_update_handler_level_background;
    MAPD_44BD50_alter_tile_flags();
    render_default_stru1->clip_z = render_width;
    render_default_stru1->clip_y = 0;
    render_default_stru1->clip_w = render_height;
    sprite_47A400.pstru7 = array_466028;
    if (is_game_loading())
    {
        prev_level_idx = -1;
        cplc_init_scripts();
        if (!GAME_Load())
        {
            LVL_Deinit();
            netz_deinit();
            GAME_Deinit();
            log(aLoadgamestateF);
            exit(0);
        }
        game_state = GAME_STATE::MainMenu;
    }
    else
    {
        cplc_init_sripts_with_reinit();
    }
}


//----- (00422860) --------------------------------------------------------
void GAME_PrepareSuperLvl(int mapd_idx)
{
    int mApd_idx; // ebp@1
                  //char *v2; // eax@1
    enum LEVEL_ID v3; // ebx@5
    int v4; // ecx@5
    char *v5; // edi@5
    bool v6; // zf@7
    unsigned int v7; // ecx@8
    char v8; // dl@8
    char *v9; // esi@8
    char *v10; // edi@8
    char *v11; // esi@8
    char v12; // cl@8
    unsigned int v13; // ecx@11
    char v14; // al@11
    char *v15; // esi@11
               //char *v16; // eax@12
    DataHunk *v17; // eax@12
    DataMapd *v18; // eax@24
                   //char v19[120]; // [sp+10h] [bp-78h]@1

    mApd_idx = mapd_idx;
    sprites_lvl = LVL_LoadLevel("supspr.lvl");
    if (!sprites_lvl)
    {
        LVL_Deinit();
        netz_deinit();
        GAME_Deinit();
        log("super sprite load failed\n");
        exit(0);
    }

    v3 = current_level_idx;
    v4 = -1;
    v5 = game_data_installation_dir;
    current_level_idx = LEVEL_INVALID;
    if (_47A2E4_mess_with_game_dir)
    {
        do
        {
            if (!v4)
                break;
            v6 = *v5++ == 0;
            --v4;
        } while (!v6);
        v7 = ~v4;
        v8 = v7;
        v9 = &v5[-(int)v7];
        v7 >>= 2;
        memcpy(game_data_root_dir, v9, 4 * v7);
        v11 = &v9[4 * v7];
        v10 = &game_data_root_dir[4 * v7];
        v12 = v8;
    }
    else
    {
        do
        {
            if (!v4)
                break;
            v6 = *v5++ == 0;
            --v4;
        } while (!v6);
        v13 = ~v4;
        v14 = v13;
        v15 = &v5[-(int)v13];
        v13 >>= 2;
        memcpy(game_data_root_dir, v15, 4 * v13);
        v11 = &v15[4 * v13];
        v10 = &game_data_root_dir[4 * v13];
        v12 = v14;
    }
    memcpy(v10, v11, v12 & 3);

    current_level_idx = v3;
    v17 = LVL_LoadLevel("super.lvl");
    current_level_lvl = v17;
    if (!v17)
    {
        LVL_Deinit();
        netz_deinit();
        GAME_Deinit();
        log("LVL_LoadLevel(%s) failed\n", "super.lvl");
        exit(0);
    }
    if (!LVL_SubstHunk(v17, sprites_lvl, (const char *)MOBD))
    {
        LVL_Deinit();
        netz_deinit();
        GAME_Deinit();
        log("LVL_SubstHunk( ) failed\n");
        exit(0);
    }
    if (!LVL_RunLevel(current_level_lvl))
    {
        netz_deinit();
        GAME_Deinit();
        log("LVL_RunLevel() failed\n");
        exit(0);
    }
    v18 = LVL_FindMapd();
    _40E400_set_palette(v18[mApd_idx].items->GetPalette());
    render_default_stru1->field_8 &= 0xBFFFFFFF;
    _47A010_mapd_item_being_drawn[0] = MAPD_Draw((enum MAPD_ID)mApd_idx, 0, 0);
    render_default_stru1->clip_z = render_width;
    render_default_stru1->clip_y = 0;
    render_default_stru1->clip_w = render_height;
    sprite_47A400.pstru7 = array_466028;
    if (mApd_idx && mApd_idx != 13)
        sub_444080(mApd_idx);
    cplc_select(mApd_idx);
    cplc_406320();
}

//----- (00423320) --------------------------------------------------------
bool on_level_finished()
{
    Bitmap **v0; // esi@1
    void *v1; // eax@12

    v0 = _47A010_mapd_item_being_drawn;
    do
    {
        if (*v0)
        {
            bitmap_list_remove(*v0);
            *v0 = 0;
        }
        ++v0;
    } while ((int)v0 < (int)& _47A01C_sound_id);
    nullsub_1();
    stru37_stru38_list_free();
    _44C5C0_level_cleanup();
    stru31_list_free();
    sidebar_deinit();
    per_player_sprite_palettes_47DC88_free();
    boxd_40EA30_cleanup();
    sidebar_list_free();
    if (game_state != GAME_STATE::GAME_2 || current_level_idx >= LEVEL_SURV_16 && current_level_idx <= LEVEL_MUTE_25)
    {
        LVL_Deinit();
        sound_free_sounds();
        free(current_level_lvl);
        free(sprites_lvl);
        sprites_lvl = 0;
        prev_level_idx = -1;
    }
    else
    {
        prev_level_idx = current_level_idx;
        cplc_4060F0();
        LVL_Deinit();
        sound_free_sounds();
    }
    if (!single_player_game && !*(_DWORD *)&netz_47A740[2].str_0[0])
    {
        v1 = (void *)j_netz_430690();
        netz_42F650(v1);
        netz_42F8E0(0);
    }
    if (game_state != GAME_STATE::Mission)
    {
        if (game_state != GAME_STATE::GAME_2)
            return 0;
        return 1;
    }
    if (is_game_loading())
    {
        prev_level_idx = -1;
        current_level_idx = get_saveload_level_id();
        set_player_side_by_level();
        return 1;
    }
    if (current_level_idx < LEVEL_SURV_16 || current_level_idx > LEVEL_MUTE_25)
    {
        if (current_level_idx != LEVEL_MUTE_15 && current_level_idx != LEVEL_SURV_15)
        {
            current_level_idx = (LEVEL_ID)((int)current_level_idx + 1);
            set_player_side_by_level();
            return 1;
        }
        _47A18C_probably_play_outro_movie = 1;
    }
    return 0;
}

//----- (00423A70) --------------------------------------------------------
void script_custom_mission_briefing_loop(Script *a1)
{
    int v2; // edi@4
    KeyboardInput keys_state; // [sp+10h] [bp-118h]@5
                              //char name[260]; // [sp+24h] [bp-104h]@4

    if (current_level_idx > LEVEL_SURV_25)
    {
        _47A1AC_is_custom_surv_mission = 0;
        _47A1A8_custom_mission_idx = current_level_idx - LEVEL_MUTE_16;
    }
    else
    {
        _47A1AC_is_custom_surv_mission = 1;
        _47A1A8_custom_mission_idx = current_level_idx - LEVEL_SURV_16;
    }
    a1->script_type = SCRIPT_TYPE_17;

    srand(OsGetTime());
    _47C380_mapd.mapd_cplc_render_y = 122880 * (rand() % 6);

    script_4084A0_animation(a1);
    _47C65C_render_string = render_string_create(0, currently_running_lvl_mobd[80].items, 84, 84, 39, 19, 90, 14, 16);
    render_string_445AE0(_47C65C_render_string);
    _47C65C_render_string->field_18 = 0;
    _47C65C_render_string->num_lines = 0;
    _47A1B0_custom_mission_briefing_ui = 0;
    _47A1A4_custom_mission_briefing_line = 0;
    dword_47A1A0 = 480;
    _423C60_custom_mission_make_briefing_lines(0);
    dword_47A19C = 0;
    v2 = 0;
    _47A198_custom_mission_briefing_sound_id = sound_play_threaded(custom_missions[_47A1A8_custom_mission_idx + 10 * _47A1AC_is_custom_surv_mission].wav_filename, 0, 16, 16, 0);
    while (1)
    {
        do
        {
            script_sleep(a1, 1);
            input_get_keyboard_state(&keys_state);
            if (keys_state.just_pressed_keys_mask & INPUT_KEYBOARD_ESCAPE_MASK)
            {
                sound_stop(_47A198_custom_mission_briefing_sound_id);
                _47A198_custom_mission_briefing_sound_id = 0;
                render_string_list_remove(_47C65C_render_string);
                _47C65C_render_string = 0;
                a1->sprite->script = 0;
                goto LABEL_12;
            }
            ++v2;
        } while (v2 != 2);
        v2 = 0;
        ++_47A1B0_custom_mission_briefing_ui;
        if (dword_47A19C)
        {
            if (!--dword_47A19C)
                break;
        }
        _423C60_custom_mission_make_briefing_lines(1);
    }
    sound_stop(_47A198_custom_mission_briefing_sound_id);
    _47A198_custom_mission_briefing_sound_id = 0;
    render_string_list_remove(_47C65C_render_string);
    _47C65C_render_string = 0;
    a1->sprite->script = 0;
LABEL_12:
    sprite_list_remove(a1->sprite);
    script_408500_anim(a1);
    game_state = GAME_STATE::GAME_3;
}

//----- (00423C60) --------------------------------------------------------
void _423C60_custom_mission_make_briefing_lines(int a1)
{
    int v1; // edx@1
    int v2; // ebx@4
    int v3; // eax@4
    char *briefing; // edi@4
    int line_type; // ebp@9
    int v6; // esi@17
    int y; // esi@19
    int v8; // ebp@20
    int v9; // eax@22
    bool v10; // sf@24
    unsigned __int8 v11; // of@24
    int v12; // [sp+10h] [bp-8h]@1
    int v13; // [sp+14h] [bp-4h]@1

    v1 = 0;
    v13 = a1;
    v12 = 0;
    do
    {
        if (!v13 || render_string_4059C0(_47C65C_render_string, v1, 0))
        {
            v2 = 0;
            v3 = _47A1A4_custom_mission_briefing_line;
            briefing = (char *)custom_missions[_47A1A8_custom_mission_idx + 10 * _47A1AC_is_custom_surv_mission].briefing[_47A1A4_custom_mission_briefing_line];
            if (briefing)
            {
                v3 = _47A1A4_custom_mission_briefing_line++ + 1;
            }
            else
            {
                if (!dword_47A19C)
                    dword_47A19C = 490;
                briefing = asc_464C60;
            }
            line_type = 0;
            if (*briefing == '%')
            {
                v2 = 1;
                ++briefing;
                line_type = 1;
            }
            if (*briefing == '~')
            {
                v2 = 1;
                ++briefing;
                line_type = 2;
            }
            if (v2 && v3 && line_type != 1 && line_type == 2)
            {
                v6 = dword_47A1A0 + 30;
                dword_47A1A0 += 30;
            }
            else
            {
                v6 = dword_47A1A0;
            }
            y = v6 - _47A1B0_custom_mission_briefing_ui;
            render_string_405A20(_47C65C_render_string, v12, y);
            _47C65C_render_string->num_lines = v12;
            _47C65C_render_string->field_18 = 0;
            render_string_405A60(_47C65C_render_string, asc_464C60, 0, y);
            _47C65C_render_string->field_18 = 0;
            render_string_405A60(_47C65C_render_string, briefing, 0, y);
            render_string_405A60(_47C65C_render_string, asc_464C88, 0, y);
            if (v2)
            {
                v8 = line_type - 1;
                if (!v8)
                {
                    v9 = dword_47A1A0 + 30;
                    goto LABEL_23;
                }
                if (v8 != 1)
                    goto LABEL_24;
            }
            v9 = dword_47A1A0 + 20;
        LABEL_23:
            dword_47A1A0 = v9;
        }
    LABEL_24:
        v1 = v12 + 1;
        v11 = __OFSUB__(v12 + 1, 17);
        v10 = v12++ - 16 < 0;
    } while (v10 ^ v11);
}

//----- (00423DD0) --------------------------------------------------------
void cplc_init_sripts_with_reinit()
{
    int v0; // esi@1

    v0 = 0;
    do
    {
        if (v0 != 84)                             //  46EE08  Script4  MOBD_20
            cplc_init_script_do_reinit(v0);
        ++v0;
    } while (v0 < 196);
}

//----- (00423DF0) --------------------------------------------------------
void cplc_init_scripts()
{
    int v0; // esi@1

    v0 = 0;
    do
    {
        if (v0 != 84)                             // 46EE08  Script4  MOBD_20
        {
            if (v0 == 6                              // 46E6B8  Script4  MOBD_6_some_letters_and_symbols
                || v0 == 75                             // 46ED30  Script4  MOBD_20                     task_431E60_mobd_20_input
                || v0 == 77                             // 46ED60  Script4  MOBD_INGAME_MENU_CONTROLS   task_433060_ingame_menu
                || v0 == 78                             // 46ED78  Script4  MOBD_SIDEBAR_BUTTONS        task_446ED0_sidebar_buttons
                || v0 == 9                              // 46E700  Script4  MOBD_MISSION_OUTCOME_MODAL
                || v0 == 79                             // 46ED90  Script4  MOBD_MISSION_OUTCOME_MODAL  task_424CE0_mission_outcome_modal
                || v0 == 80                             // 46EDA8  Script4  MOBD_CURSORS                task_428940_cursors_handler
                || v0 == 85                             // 46EE20  Script2  MOBD_46                     task_442BB0_mobd_46
                || v0 == 122                            // 46F3E0  Script1  MOBD_20                     task_4269B0_mobd_20_handler
                || v0 == 81                             // 46EDC0  Script4  MOBD_FONT_27                task_42D030_mobd_font_27_handler
                || v0 == 73)                           // 46ED00  Script4  MOBD_FONT_ITALIC
            {
                if (v0 != 84)
                    cplc_init_script_do_reinit(v0);
            }
            else
            {
                cplc_init_script_dont_reinit(v0);
            }
        }
        ++v0;
    } while (v0 < 196);
}

//----- (00423E50) --------------------------------------------------------
void set_player_side_by_level()
{
    int surv_main_campaign; // ecx@3
    int surv_xtreme_campaign; // eax@7
    int v2; // ecx@13
    int v3; // eax@17

    surv_main_campaign = current_level_idx >= LEVEL_SURV_01_THE_NEXT_GENERATION && current_level_idx <= LEVEL_SURV_15;
    surv_xtreme_campaign = current_level_idx >= LEVEL_SURV_16 && current_level_idx <= LEVEL_SURV_25;
    if (surv_main_campaign | surv_xtreme_campaign)
    {
        player_side = SURVIVORS;
        current_surv_level = current_level_idx;
    }
    else
    {
        v2 = current_level_idx >= LEVEL_MUTE_01 && current_level_idx <= LEVEL_MUTE_15;
        v3 = current_level_idx >= LEVEL_MUTE_16 && current_level_idx <= LEVEL_MUTE_25;
        if (v2 | v3)
        {
            player_side = EVOLVED;
            current_mute_level = current_level_idx - 15;
        }
    }
}