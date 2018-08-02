#include "src/kknd.h"


//----- (00423ED0) --------------------------------------------------------
char GAME_ParseCommandLine()
{
    char *v0; // eax@1
    char *v1; // edi@1
    char *v2; // edx@1
    char i; // cl@1
    char v4; // cl@7
    char j; // cl@12
    char *v6; // edx@13
    char v7; // cl@19
    char v8; // cl@28
    char **v9; // esi@36
    char *v10; // ecx@36
    bool v11; // cf@37
    int v12; // ecx@41
    char **v13; // esi@45
    char *v14; // ecx@45
    bool v15; // cf@46
    int v16; // ecx@50

    dword_47A2BC = 0;
    v0 = GetCommandLineA();
    v1 = v0;
    v2 = global_console_argv;
    global_cmd_line = v0;
    for (i = *v0; *v1; i = *v1)
    {
        if (i == ' ')
            break;
        if (i == '\r')
            break;
        if (i == '\n')
            break;
        if (i == '\t')
            break;
        *v2++ = i;
        global_cmd_line = ++v1;
    }
    while (1)
    {
        v4 = *v1;
        if (*v1 != ' ' && v4 != '\r' && v4 != '\n' && v4 != '\t')
            break;
        global_cmd_line = ++v1;
    }
    *v2 = 0;
    for (j = *v1; *v1; j = *v1)
    {
        v6 = global_console_argv;
        if (j)
        {
            do
            {
                if (j == ' ')
                    break;
                if (j == '\r')
                    break;
                if (j == '\n')
                    break;
                if (j == '\t')
                    break;
                *v6++ = j;
                global_cmd_line = ++v1;
                j = *v1;
            } while (*v1);
        }
        while (1)
        {
            v7 = *v1;
            if (*v1 != ' ' && v7 != '\r' && v7 != '\n' && v7 != '\t')
                break;
            global_cmd_line = ++v1;
        }
        *v6 = 0;
        if (!strcmp(global_console_argv, (const char *)console_switch_stats))
        {
            if (*v1)
            {
                printf((const char *)errmsg_no_stats_file_specified);
                exit(1);
            }
            while (1)
            {
                v8 = *v1;
                if (*v1 != ' ' && v8 != '\r' && v8 != '\n' && v8 != '\t')
                    break;
                global_cmd_line = ++v1;
            }
            global_console_argv[0] = 0;
            v0 = (char *)_424560_parse_unit_stats_table(global_console_argv);
            if (!v0)
                exit(1);
            v1 = global_cmd_line;
            units_stats_parsed_from_argv = 1;
        }
        else
        {
            v9 = (char **)console_switch_noblack;
            v10 = global_console_argv;
            while (1)
            {
                LOBYTE_HEXRAYS(v0) = *v10;
                v11 = (unsigned __int8)*v10 < *(_BYTE *)v9;
                if (*v10 != *(_BYTE *)v9)
                    break;
                if (!*v10)
                    goto LABEL_41;
                LOBYTE_HEXRAYS(v0) = v10[1];
                v11 = (unsigned __int8)v0 < *((_BYTE *)v9 + 1);
                if ((_BYTE)v0 != *((_BYTE *)v9 + 1))
                    break;
                v10 += 2;
                v9 = (char **)((char *)v9 + 2);
                if (!(_BYTE)v0)
                {
                LABEL_41:
                    v12 = 0;
                    goto LABEL_43;
                }
            }
            v12 = -v11 - (v11 - 1);
        LABEL_43:
            if (v12)
            {
                v13 = (char **)console_switch_nocd;
                v14 = global_console_argv;
                while (1)
                {
                    LOBYTE_HEXRAYS(v0) = *v14;
                    v15 = (unsigned __int8)*v14 < *(_BYTE *)v13;
                    if (*v14 != *(_BYTE *)v13)
                        break;
                    if (!*v14)
                        goto LABEL_50;
                    LOBYTE_HEXRAYS(v0) = v14[1];
                    v15 = (unsigned __int8)v0 < *((_BYTE *)v13 + 1);
                    if ((_BYTE)v0 != *((_BYTE *)v13 + 1))
                        break;
                    v14 += 2;
                    v13 = (char **)((char *)v13 + 2);
                    if (!(_BYTE)v0)
                    {
                    LABEL_50:
                        v16 = 0;
                        goto LABEL_52;
                    }
                }
                v16 = -v15 - (v15 - 1);
            LABEL_52:
                if (!v16)
                    nocd = 1;
            }
            else
            {
                _47A2EC_noblack = 1;
            }
        }
    }
    return (unsigned int)v0;
}

//----- (00424560) --------------------------------------------------------
bool _424560_parse_unit_stats_table(const char *filename)
{
    const char *v1; // esi@1
    FILE *v2; // eax@1
    FILE *v3; // ebx@1
    char *v4; // esi@3
    UnitNameId *v5; // ebp@3
    const char *v6; // eax@6
    UnitStat *unit_stat; // edi@10
    char *v8; // eax@10
    int v9; // eax@12
    char *v10; // eax@16
    int v11; // esi@18
    unsigned int v12; // edx@20
    char *v13; // eax@22
    int v14; // eax@24
    char *v15; // eax@28
    int v16; // eax@30
    char *v17; // eax@37
    int v18; // eax@39
    UnitAttachmentPoint *v19; // ecx@42
    char *v20; // eax@45
    int v21; // eax@47
    UnitAttachmentPoint *v22; // ecx@50
    char *v23; // eax@54
    int v24; // eax@56
    UnitAttachmentPoint *v25; // ecx@59
    char *v26; // eax@62
    int v27; // eax@64
    char *v28; // eax@68
    int v29; // eax@70
    char *v30; // eax@74
    int v31; // eax@76
    char *v32; // eax@80
    int v33; // eax@82
    UnitAttachmentPoint *v34; // ecx@85
    UnitDamageSource *v35; // ecx@86
    char *v36; // eax@89
    int v37; // eax@91
    UnitAttachmentPoint *v38; // ecx@94
    UnitDamageSource *v39; // ecx@95
    char *v40; // eax@98
    int v41; // eax@100
    UnitAttachmentPoint *v42; // ecx@103
    UnitDamageSource *v43; // ecx@104
    BOOL result; // eax@110
    char line[1024]; // [sp+8h] [bp-400h]@2

    v1 = filename;
    v2 = fopen(filename, "rb");
    v3 = v2;
    if (v2)
    {
        if (fgets(line, 1024, v2))
        {
            do
            {
                v4 = strtok(line, asc_space);
                v5 = unit_name_id_lut;
                if (line[0] != '\n' && line[0] != '\r' && line[0] != ';')
                {
                    v6 = unit_name_id_lut[0].unit_name;
                    if (unit_name_id_lut[0].unit_name)
                    {
                        while (strcmp(v6, v4))
                        {
                            v6 = v5[1].unit_name;
                            ++v5;
                            if (!v6)
                                goto LABEL_107;
                        }
                        unit_stat = &unit_stats[v5->id];
                        v8 = strtok(0, _4681EC_whitespace);
                        v4 = v8;
                        if (v8)
                        {
                            if (*v8 != '-')
                            {
                                v9 = atoi(v8);
                                if (v9 >= 1 && v9 <= 60000)
                                    unit_stat->cost = v9;
                                else
                                    printf(errmsg_unit_out_of_range, v5->unit_name, cost, 1, 60000);
                            }
                            v10 = strtok(0, _4681EC_whitespace);
                            v4 = v10;
                            if (v10)
                            {
                                if (*v10 != '-')
                                {
                                    v11 = atoi(v10);
                                    if (v11 >= 1 && v11 <= (unit_stat->cost << 8) / 60)
                                    {
                                        unit_stat->production_time = v11;
                                    }
                                    else
                                    {
                                        v12 = (int)((unit_stat->cost << 8)
                                            + ((unsigned __int64)(0xFFFFFFFF88888889i64 * (unit_stat->cost << 8)) >> 32)) >> 5;
                                        printf(errmsg_unit_out_of_range, v5->unit_name, aProductionTime, 1, (v12 >> 31) + v12);
                                    }
                                }
                                v13 = strtok(0, _4681EC_whitespace);
                                v4 = v13;
                                if (v13)
                                {
                                    if (*v13 != '-')
                                    {
                                        v14 = atoi(v13);
                                        if (v14 >= 1 && v14 <= 0x7FFFFFFF)
                                            unit_stat->hitpoints = v14;
                                        else
                                            printf(errmsg_unit_out_of_range, v5->unit_name, aHitpoints, 1, 0x7FFFFFFF);
                                    }
                                    v15 = strtok(0, _4681EC_whitespace);
                                    v4 = v15;
                                    if (v15)
                                    {
                                        if (*v15 != '-')
                                        {
                                            v16 = atoi(v15);
                                            if (!v16 || unit_stat->speed)
                                            {
                                                if (v16 >= 1 && v16 <= 500)
                                                    unit_stat->speed = v16;
                                                else
                                                    printf(errmsg_unit_out_of_range, v5->unit_name, aSpeed, 1, 500);
                                            }
                                            else
                                            {
                                                printf(aWarningUnitSIs, v5->unit_name);
                                            }
                                        }
                                        v17 = strtok(0, _4681EC_whitespace);
                                        v4 = v17;
                                        if (v17)
                                        {
                                            if (*v17 != '-')
                                            {
                                                v18 = atoi(v17);
                                                if (v18 >= 0 && v18 <= 10000)
                                                {
                                                    v19 = unit_stat->attach;
                                                    if (v19 && v19->dmg_source)
                                                        v19->reload_time = v18;
                                                }
                                                else
                                                {
                                                    printf(errmsg_unit_out_of_range, v5->unit_name, aReloadTime, 0, 10000);
                                                }
                                            }
                                            v20 = strtok(0, _4681EC_whitespace);
                                            v4 = v20;
                                            if (v20)
                                            {
                                                if (*v20 != 45)
                                                {
                                                    v21 = atoi(v20);
                                                    if (v21 >= 5 && v21 <= 10000)
                                                    {
                                                        v22 = unit_stat->attach;
                                                        if (v22 && v22->dmg_source)
                                                            v22->reload2_time = v21;
                                                        else
                                                            unit_stat->reload_time = v21;
                                                    }
                                                    else
                                                    {
                                                        printf(errmsg_unit_out_of_range, v5->unit_name, aReload2Time, 5, 10000);
                                                    }
                                                }
                                                v23 = strtok(0, _4681EC_whitespace);
                                                v4 = v23;
                                                if (v23)
                                                {
                                                    if (*v23 != 45)
                                                    {
                                                        v24 = atoi(v23);
                                                        if (v24 >= 1 && v24 <= 10000)
                                                        {
                                                            v25 = unit_stat->attach;
                                                            if (v25 && v25->dmg_source)
                                                                v25->volley_size = v24;
                                                        }
                                                        else
                                                        {
                                                            printf(errmsg_unit_out_of_range, v5->unit_name, aVolleySize, 1, 10000);
                                                        }
                                                    }
                                                    v26 = strtok(0, _4681EC_whitespace);
                                                    v4 = v26;
                                                    if (v26)
                                                    {
                                                        if (*v26 != 45)
                                                        {
                                                            v27 = atoi(v26);
                                                            if (v27 >= 1 && v27 <= 64)
                                                                unit_stat->turning_speed = v27;
                                                            else
                                                                printf(errmsg_unit_out_of_range, v5->unit_name, aTurningSpeed, 1, 64);
                                                        }
                                                        v28 = strtok(0, _4681EC_whitespace);
                                                        v4 = v28;
                                                        if (v28)
                                                        {
                                                            if (*v28 != '-')
                                                            {
                                                                v29 = atoi(v28);
                                                                if (v29 >= 32 && v29 <= 320)
                                                                    unit_stat->firing_range = v29;
                                                                else
                                                                    printf(errmsg_unit_out_of_range, v5->unit_name, aFiringVisualRa, 32, 320);
                                                            }
                                                            v30 = strtok(0, _4681EC_whitespace);
                                                            v4 = v30;
                                                            if (v30)
                                                            {
                                                                if (*v30 != '-')
                                                                {
                                                                    v31 = atoi(v30);
                                                                    if (v31 >= 50 && v31 <= 100)
                                                                        unit_stat->accuracy = v31;
                                                                    else
                                                                        printf(errmsg_unit_out_of_range, v5->unit_name, aAccuracy, 50, 100);
                                                                }
                                                                v32 = strtok(0, _4681EC_whitespace);
                                                                v4 = v32;
                                                                if (v32)
                                                                {
                                                                    if (*v32 != 45)
                                                                    {
                                                                        v33 = atoi(v32);
                                                                        if (v33 >= 1 && v33 <= 60000)
                                                                        {
                                                                            v34 = unit_stat->attach;
                                                                            if (v34 && (v35 = v34->dmg_source) != 0 || (v35 = unit_stat->dmg_source) != 0)
                                                                                v35->damage_infantry = v33;
                                                                        }
                                                                        else
                                                                        {
                                                                            printf(errmsg_unit_out_of_range, v5->unit_name, aDamageToInfant, 1, 60000);
                                                                        }
                                                                    }
                                                                    v36 = strtok(0, _4681EC_whitespace);
                                                                    v4 = v36;
                                                                    if (v36)
                                                                    {
                                                                        if (*v36 != '-')
                                                                        {
                                                                            v37 = atoi(v36);
                                                                            if (v37 >= 1 && v37 <= 60000)
                                                                            {
                                                                                v38 = unit_stat->attach;
                                                                                if (v38 && (v39 = v38->dmg_source) != 0 || (v39 = unit_stat->dmg_source) != 0)
                                                                                    v39->damage_vehicle = v37;
                                                                            }
                                                                            else
                                                                            {
                                                                                printf(errmsg_unit_out_of_range, v5->unit_name, aDamageToVehicl, 1, 60000);
                                                                            }
                                                                        }
                                                                        v40 = strtok(0, _4681EC_whitespace);
                                                                        v4 = v40;
                                                                        if (v40 && *v40 != '-')
                                                                        {
                                                                            v41 = atoi(v40);
                                                                            if (v41 >= 1 && v41 <= 60000)
                                                                            {
                                                                                v42 = unit_stat->attach;
                                                                                if (v42 && (v43 = v42->dmg_source) != 0 || (v43 = unit_stat->dmg_source) != 0)
                                                                                    v43->damage_building = v41;
                                                                            }
                                                                            else
                                                                            {
                                                                                printf(errmsg_unit_out_of_range, v5->unit_name, aDamageToBuildi, 1, 60000);
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
                        }
                    }
                LABEL_107:
                    if (!v5->unit_name)
                        printf((const char *)errmsg_unrecognized_name, v4);
                }
            } while (fgets(line, 1024, v3));
        }
        fclose(v3);
        result = 1;
    }
    else
    {
        printf((const char *)errmsg_could_not_open_file, v1);
        result = 0;
    }
    return result;
}