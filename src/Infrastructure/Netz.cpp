#include "src/kknd.h"

#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"

#include "Infrastructure/Netz.h"
#include "src/Random.h"
#include "src/Script.h"
#include "src/ScriptEvent.h"
#include "src/Cursor.h"




netz_stru6_per_player netz_47A740[8];
int(*netz_pfn_47A838)(netz_stru_3 *);

netz_stru_4 netz_47A8E4;
netz_stru_5 netz_47A940[8];
netz_stru1 netz_47AAA0[8];

int netz_468B6C_providers_idx = -1; // weak
netz_provider netz_468B6C_providers[3] =
{
    {
        NULL,
        "DirectX IPX",
        "DirectX IPX",
        "DirectX IPX",
        0,
        0,
        0,
        &nullsub_3,
        &nullsub_4,
        &nullsub_4,
        &nullsub_4,
        &nullsub_4,
        &nullsub_4,
        &nullsub_4,
        &nullsub_1,
        &nullsub_4,
        &netz_nullsub_5,
        &nullsub_4,
        &nullsub_4,
        &nullsub_4,
        &nullsub_4,
        &nullsub_1,
        &nullsub_4,
        &nullsub_4,
        &nullsub_1,
        &nullsub_1
    },
    {
        NULL,
        "DirectX serial",
        "DirectX serial",
        "DirectX serial",
        0,
        0,
        0,
        &nullsub_3,
        &nullsub_4,
        &nullsub_4,
        &nullsub_4,
        &nullsub_4,
        &nullsub_4,
        &nullsub_4,
        &nullsub_1,
        &nullsub_4,
        &netz_nullsub_5,
        &nullsub_4,
        &nullsub_4,
        &nullsub_4,
        &nullsub_4,
        &nullsub_1,
        &nullsub_4,
        &nullsub_4,
        &nullsub_1,
        &nullsub_1
    },
    {
        NULL,
        "DirectX modem",
        "DirectX modem",
        "DirectX modem",
        0,
        0,
        0,
        &nullsub_3,
        &nullsub_4,
        &nullsub_4,
        &nullsub_4,
        &nullsub_4,
        &nullsub_4,
        &nullsub_4,
        &nullsub_1,
        &nullsub_4,
        &netz_nullsub_5,
        &nullsub_4,
        &nullsub_4,
        &nullsub_4,
        &nullsub_4,
        &nullsub_1,
        &nullsub_4,
        &nullsub_4,
        &nullsub_1,
        &nullsub_1
    }
};
char aDirectxModem[] = "DirectX modem"; // idb
char aDirectxSerial[] = "DirectX serial"; // idb
char aDirectxIpx[] = "DirectX IPX"; // idb
char *netz_468CD8_datetime[2] = { "Oct 23 1997", "17:00:00" };
char netz_default_player_name[7] = "PLAYER";



//----- (0042E170) --------------------------------------------------------
int netz_42E170(int a1, char *a2)
{
    char *v2; // eax@1
    int v4; // esi@3
    void *v5; // edx@3
    void *v6; // ecx@9
    char *v7; // eax@9
    int v8; // esi@14
    int v9; // edx@14
    char v10; // cl@19
    const char *v11; // edi@20
    _BYTE *v12; // edx@20
    void *v13; // eax@20
    int v14; // ecx@20
    int v15; // eax@22
    void *v16; // ecx@23
    int result; // eax@26
    int v18; // eax@29
    void *v19; // ecx@30
    int v20; // [sp+0h] [bp-50h]@22
    int v21[15]; // [sp+Ch] [bp-44h]@9
    int netz_provider_id; // [sp+48h] [bp-8h]@1
    char *v23; // [sp+4Ch] [bp-4h]@1

    v23 = a2;
    netz_provider_id = a1;
    netz_47A82C = 0;
    netz_47A828 = 0;
    netz_468B50_available_units_denom = 0;
    v2 = (char *)&netz_47A740[3].ptr_4;
    do
    {
        *(v2 - 24) = 0;
        *(_DWORD *)v2 = 1;
        v2 += 28;
    } while ((int)v2 < (int)&netz_47A840);
    srand(clock());
    v4 = 0;
    v5 = (void *)(rand() % 6);
    while (netz_47A740[(int)v5 + 2].field_8)
    {
        v5 = (char *)v5 + 1;
        if (v5 == (void *)6)
            v5 = 0;
        if (++v4 >= 6)
        {
            v5 = (void *)-1;
            break;
        }
    }
    __47CA80_array_idx_and_netz_player_side = v5;
    memset(v21, 0, sizeof(v21));
    v6 = 0;
    v7 = &netz_47A740[2].field_9;
    do
    {
        if (*(v7 - 1) && v6 != v5)
            v21[*v7] = 1;
        v7 += 28;
        v6 = (char *)v6 + 1;
    } while ((int)v7 < (int)&netz_47A828 + 1);
    v8 = 0;
    v9 = rand() % 15;
    while (v21[v9])
    {
        if (++v9 == 15)
            v9 = 0;
        if (++v8 >= 15)
        {
            v10 = 0;
            goto LABEL_20;
        }
    }
    v10 = v9;
LABEL_20:
    v11 = v23;
    v12 = (_BYTE *)(28 * (_DWORD)__47CA80_array_idx_and_netz_player_side);
    v12[(_DWORD)&netz_47A740[2] + 9] = v10;
    v12[(_DWORD)&netz_47A740[2] + 8] = 2;
    v12[(_DWORD)&netz_47A740[2] + 10] = 0;
    v13 = (void *)(strlen(v11) + 1);
    v23 = &v12[(_DWORD)&netz_47A740[2] + 11];
    memcpy(&v12[(_DWORD)&netz_47A740[2] + 11], v11, (unsigned int)v13);
    v14 = netz_468B50_available_units_denom;
    *(_DWORD *)&v12[(_DWORD)&netz_47A740[3] + 4] = 1;
    netz_468B50_available_units_denom = v14 + 1;
    v16 = (void *)netz_42F930_switch_provider(netz_provider_id);
    if (v16)
    {
        result = 0;
    }
    else
    {
        v19 = (void *)netz_42F8C0(0);
        result = v19 == 0;
    }
    return result;
}

//----- (0042E390) --------------------------------------------------------
bool netz_free_provider_async()
{
    int v1; // eax@3
    char _0; // [sp+0h] [bp+0h]@3

    netz_free_provider();
    return 1;
}

//----- (0042E400) --------------------------------------------------------
void *netz_42E400(void *a1)
{
    void *result; // eax@1

    result = a1;
    if (a1)
        netz_47A2C8 = (int)a1;
    else
        result = 0;
    return result;
}
// 47A2C8: using guessed type int netz_47A2C8;

//----- (0042E410) --------------------------------------------------------
char *netz_42E410(int a1)
{
    void *v1; // eax@1
    char *result; // eax@5

    v1 = netz_47A88C;
    if (!netz_47A88C)
        goto LABEL_9;
    do
    {
        if (!a1)
            break;
        v1 = (void *)*((_DWORD *)v1 + 11);
        --a1;
    } while (v1);
    if (v1)
        result = (char *)v1 + 28;
    else
        LABEL_9:
    result = 0;
    return result;
}

//----- (0042E430) --------------------------------------------------------
bool netz_42E430(int a1)
{
    void *i; // eax@1

    for (i = netz_47A88C; i; --a1)
    {
        if (!a1)
            break;
        i = (void *)*((_DWORD *)i + 11);
    }
    return i != 0;
}

//----- (0042E450) --------------------------------------------------------
void *netz_42E450(void *a1, char a2, char a3)
{
    int v3; // eax@3
    unsigned int v4; // eax@5
    char *v5; // ebx@5
    char *v6; // edx@5
    char *v7; // edi@8
    char *v8; // esi@8
    char v9; // cl@8
    void *v10; // edi@11
    int v11; // esi@11
    int v12; // ecx@14
    int v13; // ebx@21
    int v14; // edx@21
    int v15; // esi@21
    char v16; // cl@21
    int v17; // ecx@21
    int v19; // [sp+0h] [bp-80h]@3
    int a3a; // [sp+Ch] [bp-74h]@4
    int v21; // [sp+10h] [bp-70h]@14
    char v22; // [sp+14h] [bp-6Ch]@21
    char v23[12]; // [sp+15h] [bp-6Bh]@21
    char v24; // [sp+21h] [bp-5Fh]@5
    char v25[78]; // [sp+22h] [bp-5Eh]@21
    int v26; // [sp+70h] [bp-10h]@21
    char *v27; // [sp+74h] [bp-Ch]@4
    char *v28; // [sp+78h] [bp-8h]@4
    char v29; // [sp+7Eh] [bp-2h]@1
    char *a2a; // [sp+7Fh] [bp-1h]@1

    v29 = a2;
    LOBYTE_HEXRAYS(a2a) = a3;

    v27 = (char *)timeGetTime();
    memset(&a3a, 0, 0x64u);
    v28 = (char *)10000;
    if (netz_47A834)
    {
        v4 = netz_468B50_available_units_denom;
        v5 = &v24;
        a3a = netz_468B50_available_units_denom;
        v6 = (char *)&netz_47A740[3].ptr_4;
        do
        {
            if (*(v6 - 24) && *(_DWORD *)v6)
            {
                strcpy(v5 - 12, v6 - 21);
                v4 = strlen(v6 - 21) + 1;
                v28 = v5 - 12;
                *(v5 - 13) = 1;
                //qmemcpy(v5 - 12, v6 - 21, 4 * (v4 >> 2));
                v8 = &v6[4 * (v4 >> 2) - 21];
                v7 = &v5[4 * (v4 >> 2) - 12];
                v9 = v4;
                LOBYTE_HEXRAYS(v4) = *(v6 - 22);
                //qmemcpy(v7, v8, v9 & 3);
                *v5 = *(v6 - 23);
                v5[1] = v4;
            }
            else
            {
                *(v5 - 13) = 0;
            }
            v6 += 28;
            v5 += 15;
        } while ((int)v6 < (int)&netz_47A840);
        v10 = 0;
        v11 = (int)&netz_47A740[2].field_18;
        do
        {
            if (*(_BYTE *)(v11 - 16) && v10 != __47CA80_array_idx_and_netz_player_side)
            {
                LOBYTE_HEXRAYS(v6) = (_BYTE)a2a;
                v12 = *(_DWORD *)v11;
                v21 = (int)v10;
                v4 = netz_42FA00(v12, (int)v6, &a3a, 100, 1);
            }
            v11 += 28;
            v10 = (char *)v10 + 1;
        } while (v11 < (int)&netz_pfn_47A838);
        LOBYTE_HEXRAYS(v4) = v29;
        if (v29)
        {
            v4 = netz_468B50_available_units_denom - 1;
            for (dword_47CB10 = netz_468B50_available_units_denom - 1; dword_47CB10 > 0; v4 = dword_47CB10)
            {
                v4 = timeGetTime() - (_DWORD)v27;
                if (v4 >= 0x2710)
                    break;
                netz_42F9C0(0, 0);
            }
        }
    }
    else
    {
        v13 = (int)__47CA80_array_idx_and_netz_player_side;
        memset(&a3a, 0, 0x64u);
        v14 = 28 * (_DWORD)__47CA80_array_idx_and_netz_player_side;
        v26 = 15 * (_DWORD)__47CA80_array_idx_and_netz_player_side;
        *(&v22 + 15 * (_DWORD)__47CA80_array_idx_and_netz_player_side) = 1;
        v27 = &v23[15 * v13];
        strcpy(v27, &netz_47A740[2].player_name[v14]);
        v15 = v26;
        v16 = *(&netz_47A740[2].field_9 + v14);
        LOBYTE_HEXRAYS(v14) = *(&netz_47A740[2].field_A + v14);
        *(&v24 + v26) = v16;
        v17 = dword_468B54;
        v25[v15] = v14;
        LOBYTE_HEXRAYS(v14) = (_BYTE)a2a;
        v21 = v13;
        v4 = netz_42FA00(v17, v14, &a3a, 100, 1);
        LOBYTE_HEXRAYS(v4) = v29;
        if (v29)
        {
            dword_47CB10 = 1;
            do
            {
                v4 = (unsigned int)v28;
                if ((int)v28 <= 0)
                    break;
                netz_42F9C0(0, 0);
                v4 = dword_47CB10;
                --v28;
            } while (dword_47CB10 > 0);
        }
    }
    return (void *)v4;
}

//----- (0042E690) --------------------------------------------------------
void *netz_42E690(void *a1, char a2)
{
    int v2; // eax@3
    char *v3; // ebx@4
    char *v5; // edx@4
    int v9; // edi@10
    char *v10; // esi@10
    int v11; // ecx@14
    int v13; // [sp+0h] [bp-78h]@3
    int v14; // [sp+Ch] [bp-6Ch]@4
    int v15; // [sp+10h] [bp-68h]@14
    char v16; // [sp+21h] [bp-57h]@4
    char *v17; // [sp+70h] [bp-8h]@7
    char v18; // [sp+77h] [bp-1h]@1

    v18 = a2;
    v3 = &v16;
    memset(&v14, 0, 0x64u);
    int v4 = netz_468B50_available_units_denom;
    v5 = (char *)&netz_47A740[3].ptr_4;
    v14 = netz_468B50_available_units_denom;
    do
    {
        if ((_BYTE)*(v5 - 24) && *(_DWORD *)v5)
        {
            strcpy(v3 - 12, v5 - 21);

            v17 = v3 - 12;
            *(v3 - 13) = 1;

            *v3 = *(v5 - 23);
            v3[1] = *(v5 - 22);
        }
        else
        {
            *(v3 - 13) = 0;
        }
        v5 += 28;
        v3 += 15;
    } while ((int)v5 < (int)&netz_47A840);
    v9 = 0;
    v10 = (char *)&netz_47A740[3].ptr_4;
    do
    {
        if (*(v10 - 24) == 1)
        {
            if (*(_DWORD *)v10)
            {
                v4 = *((_DWORD *)v10 - 1);
                if (!v4)
                {
                    LOBYTE_HEXRAYS(v5) = v18;
                    v11 = *((_DWORD *)v10 - 2);
                    v15 = v9;
                    v4 = netz_42FA00(v11, (int)v5, &v14, 100, 1);
                }
            }
        }
        v10 += 28;
        ++v9;
    } while ((int)v10 < (int)&netz_47A840);
    return (void *)v4;
}

//----- (0042E7B0) --------------------------------------------------------
bool netz_42E7B0()
{
    char *v1; // ecx@4

    bool result = true;
    if (netz_47A834 && !single_player_game)
    {
        if (netz_468B50_available_units_denom != 1)
        {
            v1 = (char *)&netz_47A740[3].ptr_4;
            while (*(v1 - 24) != 1 || *(_DWORD *)v1)
            {
                v1 += 28;
                if ((int)v1 >= (int)&netz_47A840)
                    return result;
            }
        }
        result = false;
    }
    return result;
}

//----- (0042E7F0) --------------------------------------------------------
void netz_42E7F0()
{
    netz_47A82C = 1;
    dword_47A830 = 1;
    if (!single_player_game)
        player_side = (enum PLAYER_SIDE)((int)__47CA80_array_idx_and_netz_player_side + 1);
}

//----- (0042E820) --------------------------------------------------------
int netz_42E820(netz_stru_3 *a1)
{
    netz_stru_3 *v1; // ebp@1
    int v2; // edx@4
    char *v3; // eax@4
    int v4; // ecx@9
    char *v5; // eax@9
    int v6; // ebx@13
    const char *v7; // edi@14
    void *v12; // eax@21
    int v13; // ecx@21
    char *v14; // eax@21
    int v15; // esi@26
    int v16; // edx@26
    int v17; // ecx@32
    int v18; // eax@32
    netz_stru6_per_player *v19; // eax@32
    _DWORD *v20; // esi@34
    int result; // eax@34
    int v22; // eax@37
    const char *v23; // ebp@40
    void *v24; // edx@40
    int v25; // ebp@40
    int v26; // ebx@41
    int v27; // edx@42
    const char *v28; // esi@47
    unsigned int v29; // kr14_4@47
    int v30; // eax@51
    int v31; // ecx@51
    int v32; // edx@57
    int v33; // eax@57
    void *v34; // eax@57
    void *v35; // eax@58
    int v36; // ecx@63
    char *v37; // eax@63
    int v38; // eax@67
    netz_stru6_per_player *v39; // eax@70
    const char *v40; // eax@72
    int v41; // edx@72
    char *v42; // eax@72
    int v43; // ebx@74
    char *v44; // esi@74
    int v45; // esi@76
    char *v46; // eax@76
    int v47; // ebp@77
    int v48; // ebx@78
    int v49; // edx@79
    char *v50; // eax@84
    int v51; // edx@84
    int v52; // ecx@84
    int v53; // eax@88
    int v54; // ecx@92
    _47CA80_global *v55; // eax@93
    const char *v56; // eax@95
    int v57; // edx@95
    _BYTE *v58; // eax@95
    int v59; // ecx@96
    _47CA80_global *v60; // ecx@96
    int v61; // esi@96
    const char *v62; // ebp@98
    int v63; // edi@98
    char v64; // dl@98
    int v65; // esi@99
    int v66; // ecx@99
    int v67; // eax@99
    int v68; // ecx@114
    char *v69; // eax@114
    int v70; // eax@118
    int v71; // ecx@128
    int v72; // edx@128
    char *v73; // eax@128
    int v74; // eax@134
    int *v75; // esi@134
    const char *v76; // edx@140
    int v77; // ecx@141
    int v78; // et1@142
    int v79; // esi@154
    int v80; // edx@154
    int v81; // eax@161
    int v82; // ecx@165
    int v83; // edx@165
    char *v84; // eax@165
    char *v85; // eax@174
    int v86; // eax@180
    int a3; // [sp+10h] [bp-4Ch]@4
    int v88; // [sp+14h] [bp-48h]@40
    const char *v89; // [sp+18h] [bp-44h]@40
    char *v90; // [sp+1Ch] [bp-40h]@42
    int v91[15]; // [sp+20h] [bp-3Ch]@21

    v1 = a1;
    netz_47A740[2].ptr_4 = (int)a1;
    switch (a1->field_C)
    {
    case 1:
        if (a1->field_24)
            goto LABEL_183;
        switch (LOWORD_HEXRAYS(a1->field_28))
        {
        case 31:
            v2 = 0;
            v3 = (char *)&netz_47A740[3].ptr_4;
            a3 = 6;
            do
            {
                if (*(v3 - 24) && !*(_DWORD *)v3)
                    ++v2;
                v3 += 28;
            } while ((int)v3 < (int)&netz_47A840);
            v4 = 0;
            v5 = (char *)&netz_47A740[2].field_18;
            while (*(v5 - 16) != 1 || *(_DWORD *)v5 != v1->field_2C)
            {
                v5 += 28;
                ++v4;
                if ((int)v5 >= (int)&netz_pfn_47A838)
                {
                    v6 = -1;
                    goto LABEL_14;
                }
            }
            v6 = v4;
        LABEL_14:
            a3 = v6;
            v7 = v1->str_34;
            if (v2 <= 1
                && netz_47A834
                && !dword_47CB20
                && (!v7 || !strcmp(v7 + 12, netz_468CD8_datetime[0]) && !strcmp(v7 + 24, netz_468CD8_datetime[1])))
            {
                if (v6 == -1)
                    goto LABEL_183;
                ++netz_468B50_available_units_denom;

                strcpy(netz_47A740[v6 + 2].player_name, v7);

                v12 = __47CA80_array_idx_and_netz_player_side;
                netz_47A740[v6 + 2].field_9 = netz_47A740[(int)v12 + 2].field_9;
                memset(v91, 0, sizeof(v91));
                v13 = 0;
                v14 = &netz_47A740[2].field_9;
                do
                {
                    if (*(v14 - 1) && v13 != v6)
                        v91[*v14] = 1;
                    v14 += 28;
                    ++v13;
                } while ((int)v14 < 4696105);
                v15 = 0;
                v16 = rand() % 15;
                while (v91[v16])
                {
                    if (++v16 == 15)
                        v16 = 0;
                    if (++v15 >= 15)
                    {
                        LOBYTE_HEXRAYS(v16) = 0;
                        break;
                    }
                }
                v17 = a3;
                a3 = 6;
                v18 = v17;
                netz_47A740[v18 + 2].field_9 = v16;
                netz_47A740[v18 + 2].field_A = 1;
                v19 = &netz_47A740[3];
                do
                {
                    *(_DWORD *)&v19->str_0[0] = 0;
                    ++v19;
                } while ((int)v19 < (int)&dword_47A83C);
                v20 = (_DWORD *)(28 * v17 + 4695960);
                netz_47A740[v17 + 3].ptr_4 = 1;
                netz_42E690(v19, 57);
                netz_443F10();
                *v20 = 0;
                return 0;
            }
            if (netz_47A834)
            {
                netz_42FA00(v1->field_2C, 76, 0, 0, 1);
                netz_430D70(*(_DWORD *)(netz_47A740[2].ptr_4 + 44));
                if (a3 != -1)
                {
                    v22 = a3;
                    netz_47A740[v22 + 2].field_18 = -1;
                    netz_47A740[v22 + 2].field_8 = 0;
                    return 0;
                }
            }
            goto LABEL_183;
        case 76:
            dword_46E3F0 = 1;
            return 0;
        case 50:
            netz_47A828 = 1;
            goto LABEL_40;
        case 57:
        LABEL_40:
            dword_46E3F0 = 0;
            v23 = a1->str_34;
            v89 = v23;
            v88 = 0;
            netz_468B50_available_units_denom = *(_DWORD *)v23;
            v24 = (void *)*((_DWORD *)v23 + 1);
            v25 = 0;
            __47CA80_array_idx_and_netz_player_side = v24;
            a3 = 0;
            do
            {
                v26 = (int)(&v89[12 * v25] + 3 * v25);
                if (*(_BYTE *)(v26 + 8))
                {
                    v27 = v25;
                    netz_47A740[v25 + 2].field_8 = 3;
                    v90 = netz_47A740[v25 + 2].player_name;
                    strcpy(v90, (const char *)(v26 + 9));
                    netz_47A740[v27 + 2].field_9 = *(_BYTE *)(v26 + 21);
                    netz_47A740[v27 + 2].field_A = *(_BYTE *)(v26 + 22);
                    ++v88;
                }
                else
                {
                    netz_47A740[v25 + 2].field_8 = 0;
                }
                a3 = ++v25;
            } while (v25 < 6);
            if (v88 == netz_468B50_available_units_denom)
                goto LABEL_183;
            netz_430D70(dword_468B54);
            game_state = GAME_STATE::GAME_3;
            return 0;
        case 73:
            memset(netz_47A740, 0, 0x38u);
            v28 = a1->str_34;
            v29 = strlen(a1->str_34) + 1;
            memcpy(netz_47A740, v28, v29 - 1 + 2);
            if (netz_47A740[0].str_0[v29] != (_BYTE)_468A58_sound_id)
                goto LABEL_183;
            if (netz_47A834)
                netz_44A160(73, (char *)netz_47A740, v29 - 1 + 2);
            show_message((const char *)netz_47A740);
            return 0;
        case 68:
            v30 = (int)&netz_47A740[2].field_18;
            a1->field_2C = a1->field_2C;
            v31 = 0;
            while (*(_BYTE *)(v30 - 16) != 1 || *(_DWORD *)v30 != *(_DWORD *)(netz_47A740[2].ptr_4 + 44))
            {
                v30 += 28;
                ++v31;
                if (v30 >= (int)&netz_pfn_47A838)
                {
                    v31 = -1;
                    break;
                }
            }
            a3 = v31;
            if (v31 == -1)
                goto LABEL_183;
            netz_42FA00(v31, 56, 0, 0, 1);
            v32 = netz_47A740[2].ptr_4;
            --dword_47C6F4;
            v33 = a3;
            netz_47A740[v33 + 2].field_18 = -1;
            netz_47A740[v33 + 2].field_8 = 0;
            --netz_468B50_available_units_denom;
            v34 = (void *)netz_430D70(*(_DWORD *)(v32 + 44));
            netz_42E450(v34, 0, 57);
            return 0;
        case 72:
            v35 = (void *)script_trigger_event_group(0, EVT_MSG_1526_infiltrate, 0, SCRIPT_TYPE_17);
            netz_42F650(v35);
            return 0;
        case 67:
            if (dword_468B54 < 0)
                goto LABEL_183;
            script_trigger_event_group(0, EVT_MSG_1526_infiltrate, 0, SCRIPT_TYPE_17);
            return 0;
        case 71:
            kknd_srand_debug(*(_DWORD *)a1->str_34);
            goto LABEL_62;
        case 70:
        LABEL_62:
            netz_42FA00(dword_468B54, 55, 0, 0, 1);
            netz_43BA90_create_script_43BA70();
            sub_43BAA0();
            return 0;
        case 55:
            v36 = 0;
            v37 = (char *)&netz_47A740[2].field_18;
            while (*(v37 - 16) != 1 || *(_DWORD *)v37 != v1->field_2C)
            {
                v37 += 28;
                ++v36;
                if ((int)v37 >= (int)&netz_pfn_47A838)
                {
                    v38 = -1;
                    goto LABEL_69;
                }
            }
            v38 = v36;
        LABEL_69:
            if (v38 != -1)
            {
                v39 = (netz_stru6_per_player *)((char *)&netz_47A740[v38 + 3] + 4);
                if (!*(_DWORD *)&v39->str_0[0])
                    goto LABEL_122;
            }
            goto LABEL_123;
        case 66:
            v40 = a1->str_34;
            v41 = *((_DWORD *)v40 + 1);
            a3 = v41;
            v42 = (char *)(&v40[12 * v41] + 3 * v41);
            v90 = v42;
            if (v42[8] && v41 < 7)
            {
                v43 = v41;
                strcpy(netz_47A740[v41 + 2].player_name, v42 + 9);
                v44 = v90;
                netz_47A740[v43 + 2].field_9 = v90[21];
                netz_47A740[v43 + 2].field_A = v44[22];
            }
            else
            {
                netz_47A740[v41 + 2].field_8 = 0;
                netz_430D70(a1->field_2C);
                v41 = a3;
            }
            v45 = netz_47A740[v41 + 3].ptr_4;
            v46 = (char *)&netz_47A740[v41 + 3].ptr_4;
            *(_DWORD *)v46 = 1;
            netz_42E450(v46, 0, 65);
            result = 0;
            netz_47A740[a3 + 3].ptr_4 = v45;
            return result;
        case 65:
            v47 = 0;
            v89 = a1->str_34;
            a3 = 0;
            do
            {
                v48 = (int)(&v89[12 * v47] + 3 * v47);
                if (*(_BYTE *)(v48 + 8))
                {
                    v49 = v47;
                    v90 = netz_47A740[v47 + 2].player_name;
                    strcpy(netz_47A740[v47 + 2].player_name, (const char *)(v48 + 9));
                    netz_47A740[v49 + 2].field_9 = *(_BYTE *)(v48 + 21);
                    netz_47A740[v49 + 2].field_A = *(_BYTE *)(v48 + 22);
                }
                a3 = ++v47;
            } while (v47 < 6);
            if (dword_47CB10 <= 0)
                goto LABEL_183;
            --dword_47CB10;
            return 0;
        case 74:
        case 75:
            nullsub_1();
            return 0;
        case 52:
            v50 = (char *)&netz_47A740[2].field_18;
            a1->field_2C = a1->field_2C;
            v51 = netz_47A740[2].ptr_4;
            v52 = 0;
            while (*(v50 - 16) != 1 || *(_DWORD *)v50 != *(_DWORD *)(netz_47A740[2].ptr_4 + 44))
            {
                v50 += 28;
                ++v52;
                if ((int)v50 >= (int)&netz_pfn_47A838)
                {
                    v53 = -1;
                    goto LABEL_90;
                }
            }
            v53 = v52;
        LABEL_90:
            a3 = v53;
            if (v53 == -1 || *(_DWORD *)&netz_47A740[v53 + 3].str_0[0])
                goto LABEL_183;
            *(_DWORD *)&netz_47A740[v53 + 3].str_0[0] = 1;
            v54 = *(_DWORD *)(v51 + 52);
            if (*(_BYTE *)v54)
            {
                v55 = &_47CA80_array[v53];
                v55->field_0 = *(_DWORD *)v54;
                v55->field_4 = *(_DWORD *)(v54 + 4);
                v55->field_8 = *(_DWORD *)(v54 + 8);
                v55->field_C = *(_BYTE *)(v54 + 12);
                --dword_47CB14;
                result = 0;
            }
            else
            {
                LOBYTE_HEXRAYS(_47CA80_array[v53].field_0) = 0;
                --dword_47CB14;
                result = 0;
            }
            return result;
        case 51:
            dword_47CB14 = 0;
            v56 = a1->str_34;
            v57 = *v56;
            v58 = (char *)v56 + 1;
            if (v57 <= 0)
                goto LABEL_183;
            do
            {
                v59 = *v58;
                a3 = v59;
                v60 = &_47CA80_array[v59];
                v61 = (int)(v58 + 1);
                v58 += 14;
                --v57;
                v60->field_0 = *(_DWORD *)v61;
                v60->field_4 = *(_DWORD *)(v61 + 4);
                v60->field_8 = *(_DWORD *)(v61 + 8);
                v60->field_C = *(_BYTE *)(v61 + 12);
            } while (v57);
            return 0;
        case 69:
            v62 = a1->str_34;
            v63 = *((_DWORD *)v62 + 1);
            v64 = *(&v62[12 * v63 + 21] + 3 * v63);
            do
            {
                v65 = 0;
                v66 = 0;
                v67 = (int)&netz_47A740[3].ptr_4;
                while (v66 == v63 || !*(_BYTE *)(v67 - 24) || !*(_DWORD *)v67 || *(_BYTE *)(v67 - 23) != v64)
                {
                    v67 += 28;
                    ++v66;
                    if (v67 >= (int)&netz_47A840)
                        goto LABEL_107;
                }
                v65 = 1;
            LABEL_107:
                if (!v65)
                    break;
                v67 = v64 + 1;
                if (v67 < 15)
                    ++v64;
                else
                    v64 = 0;
            } while (v65);
            netz_47A740[v63 + 2].field_9 = v64;
            netz_42E450((void *)v67, 0, 65);
            return 0;
        case 59:
            if (!netz_47A82C)
                goto LABEL_183;
            v68 = 0;
            v1->field_2C = v1->field_2C;
            v69 = (char *)&netz_47A740[2].field_18;
            while (*(v69 - 16) != 1 || *(_DWORD *)v69 != *(_DWORD *)(netz_47A740[2].ptr_4 + 44))
            {
                v69 += 28;
                ++v68;
                if ((int)v69 >= (int)&netz_pfn_47A838)
                {
                    v70 = -1;
                    goto LABEL_120;
                }
            }
            v70 = v68;
        LABEL_120:
            if (v70 == -1 || (v39 = &netz_47A740[v70 + 3], *(_DWORD *)&v39->str_0[0]))
            {
            LABEL_183:
                result = 0;
            }
            else
            {
            LABEL_122:
                *(_DWORD *)&v39->str_0[0] = 1;
            LABEL_123:
                --dword_47CB10;
                result = 0;
            }
            return result;
        case 56:
            goto LABEL_123;
        case 64:
            netz_441EF0((int)a1->str_34);
            netz_42FA00(dword_468B54, 55, 0, 0, 1);
            return 0;
        case 60:
            dword_47A830 = 1;
            return 0;
        case 61:
            dword_47A738 = 0;
            dword_47CB18 = 1;
            *(_DWORD *)&netz_47A740[2].str_0[0] = 1;
            is_coroutine_list_initialization_failed = 0;
            dword_47CB1C = 0;
            dword_47A180 = 2;
            game_state = GAME_STATE::GAME_3;
            dword_47CB14 = -1;
            return 0;
        case 62:
            if (netz_468B50_available_units_denom <= 2)
            {
                is_coroutine_list_initialization_failed = 0;
                *(_DWORD *)&netz_47A740[2].str_0[0] = 1;
                dword_47CB18 = 1;
                dword_47A738 = 0;
                dword_47CB1C = 0;
                dword_47CB14 = -1;
                dword_47A180 = 2;
                game_state = GAME_STATE::GAME_3;
                return 0;
            }
            v71 = 0;
            v1->field_2C = v1->field_2C;
            v72 = netz_47A740[2].ptr_4;
            v73 = (char *)&netz_47A740[2].field_18;
            break;
        case 63:
            v76 = a1->str_34;
            if (!netz_47A740[*(_DWORD *)v76 + 2].field_8)
                goto LABEL_183;
            v77 = netz_468B50_available_units_denom;
            netz_47A740[*(_DWORD *)v76 + 2].field_8 = 0;
            result = 0;
            netz_468B50_available_units_denom = v77 - 1;
            return result;
        default:
            goto LABEL_183;
        }
        while (*(v73 - 16) != 1 || *(_DWORD *)v73 != *(_DWORD *)(netz_47A740[2].ptr_4 + 44))
        {
            v73 += 28;
            ++v71;
            if ((int)v73 >= (int)&netz_pfn_47A838)
            {
                v71 = -1;
                break;
            }
        }
        a3 = v71;
        if (v71 != -1)
        {
            v74 = v71;
            netz_47A740[v74 + 2].field_18 = -1;
            netz_47A740[v74 + 2].field_8 = 0;
            netz_430D70(*(_DWORD *)(v72 + 44));
            --netz_468B50_available_units_denom;
            --dword_47CB14;
            v75 = &netz_47A740[2].field_18;
            do
            {
                if (*((_BYTE *)v75 - 16) == 1)
                    netz_42FA00(*v75, 63, &a3, 4, 1);
                v75 += 7;
            } while ((int)v75 < (int)&netz_pfn_47A838);
        }
        dword_47C030 = 1;
        dword_47050C = 1;
        script_trigger_event(0, EVT_MSG_1530_OPEN_GAME_MENU, 0, task_47C028);
        return 0;
    case 2:
        v78 = a1->field_24;
        return 0;
    case 3:
        if (!a1->field_24)
        {
            if (netz_47A834 || netz_47A82C)
            {
                netz_430D70(a1->field_2C);
                result = 0;
            }
            else
            {
                result = 0;
                dword_468B54 = a1->field_2C;
            }
            return result;
        }
        if (!netz_47A834 && dword_468B54 == -1)
        {
            dword_468B54 = -2;
            return 0;
        }
        goto LABEL_183;
    case 4:
        if (a1->field_24)
            goto LABEL_183;
        if (!netz_47A834 || netz_47A82C)
        {
            netz_42FA00(a1->field_2C, 76, 0, 0, 1);
            netz_430D70(*(_DWORD *)(netz_47A740[2].ptr_4 + 44));
            return 0;
        }
        v79 = 0;
        v80 = kknd_rand() % 6;
        while (netz_47A740[v80 + 2].field_8)
        {
            if (++v80 == 6)
                v80 = 0;
            if (++v79 >= 6)
            {
                v80 = -1;
                break;
            }
        }
        a3 = v80;
        if (v80 == -1)
        {
            netz_42FA00(*(_DWORD *)(netz_47A740[2].ptr_4 + 44), 76, 0, 0, 1);
            netz_430D70(*(_DWORD *)(netz_47A740[2].ptr_4 + 44));
            result = 0;
        }
        else
        {
            v81 = v80;
            netz_47A740[v81 + 2].field_18 = *(_DWORD *)(netz_47A740[2].ptr_4 + 44);
            netz_47A740[v81 + 2].field_8 = 1;
            netz_47A740[v81 + 3].ptr_4 = 0;
            result = 0;
        }
        return result;
    case 7:
        if (netz_47A834)
        {
            v82 = 0;
            v1->field_2C = v1->field_2C;
            v83 = netz_47A740[2].ptr_4;
            v84 = (char *)&netz_47A740[2].field_18;
            while (*(v84 - 16) != 1 || *(_DWORD *)v84 != *(_DWORD *)(netz_47A740[2].ptr_4 + 44))
            {
                v84 += 28;
                ++v82;
                if ((int)v84 >= (int)&netz_pfn_47A838)
                    goto LABEL_178;
            }
            goto LABEL_179;
        }
        if (dword_468B54 < 0)
            goto LABEL_182;
        if (dword_468B54 == a1->field_2C)
        {
            dword_468B54 = -1;
            return 0;
        }
        goto LABEL_183;
    case 6:
        if (!netz_47A834)
        {
            if (dword_468B54 == a1->field_2C)
                LABEL_182:
            dword_468B54 = -1;
            goto LABEL_183;
        }
        v85 = (char *)&netz_47A740[2].field_18;
        a1->field_2C = a1->field_2C;
        v83 = netz_47A740[2].ptr_4;
        v82 = 0;
        break;
    default:
        goto LABEL_183;
    }
    while (*(v85 - 16) != 1 || *(_DWORD *)v85 != *(_DWORD *)(netz_47A740[2].ptr_4 + 44))
    {
        v85 += 28;
        ++v82;
        if ((int)v85 >= (int)&netz_pfn_47A838)
        {
        LABEL_178:
            v82 = -1;
            break;
        }
    }
LABEL_179:
    a3 = v82;
    if (v82 == -1)
        goto LABEL_183;
    v86 = v82;
    netz_47A740[v86 + 2].field_18 = -1;
    netz_47A740[v86 + 2].field_8 = 0;
    netz_430D70(*(_DWORD *)(v83 + 44));
    --netz_468B50_available_units_denom;
    return 0;
}

//----- (0042F620) --------------------------------------------------------
void netz_42F620()
{
    dword_47CB1C = 0;
    dword_47CB14 = -1;
    dword_47A180 = 2;
    game_state = GAME_STATE::GAME_3;
}

//----- (0042F650) --------------------------------------------------------
void *netz_42F650(void *a1)
{
    int v1; // eax@3
    int v2; // edi@4
    char *v3; // esi@4
    int v5; // esi@6
    int v6; // edx@6
    void *v7; // ebx@11
    void *v8; // ecx@12
    char *v9; // eax@12
    int v10; // esi@17
    int v11; // edx@17
    char v12; // al@22
    _BYTE *v13; // edx@24
    void *v14; // eax@24
    void *v15; // ecx@24
    const char *v16; // edi@24
    void *v21; // eax@24
    int v23; // [sp+0h] [bp-4Ch]@3
    int v24[15]; // [sp+Ch] [bp-40h]@12
    char *v25; // [sp+48h] [bp-4h]@24

    dword_468B54 = -1;
    netz_47A82C = 0;
    netz_47A828 = 0;
    netz_468B50_available_units_denom = 0;
    v2 = 0;
    v3 = (char *)&netz_47A740[3].ptr_4;
    do
    {
        *(v3 - 24) = 0;
        *(_DWORD *)v3 = 1;
        netz_430D70(v2);
        v3 += 28;
        ++v2;
    } while ((int)v3 < (int)&netz_47A840);
    srand(clock());
    v5 = 0;
    v6 = rand() % 6;
    while (netz_47A740[v6 + 2].field_8)
    {
        if (++v6 == 6)
            v6 = 0;
        if (++v5 >= 6)
        {
            v7 = (void *)-1;
            goto LABEL_12;
        }
    }
    v7 = (void *)v6;
LABEL_12:
    memset(v24, 0, sizeof(v24));
    v8 = 0;
    v9 = &netz_47A740[2].field_9;
    do
    {
        if (*(v9 - 1) && v8 != v7)
            v24[*v9] = 1;
        v9 += 28;
        v8 = (char *)v8 + 1;
    } while ((int)v9 < (int)&netz_47A828 + 1);
    v10 = 0;
    v11 = rand() % 15;
    while (v24[v11])
    {
        if (++v11 == 15)
            v11 = 0;
        if (++v10 >= 15)
        {
            v12 = 0;
            goto LABEL_24;
        }
    }
    v12 = v11;
LABEL_24:
    v13 = (_BYTE *)(28 * (_DWORD)v7);
    v13[(_DWORD)&netz_47A740[2] + 9] = v12;
    v14 = __47CA80_array_idx_and_netz_player_side;
    v15 = __47CA80_array_idx_and_netz_player_side;
    v13[(_DWORD)&netz_47A740[2] + 8] = 2;
    v13[(_DWORD)&netz_47A740[2] + 10] = 0;
    v16 = &netz_47A740[2].player_name[4 * (8 * (_DWORD)v15 - (_DWORD)v14)];
    v25 = netz_47A740[(int)v7 + 2].player_name;
    __47CA80_array_idx_and_netz_player_side = v7;

    strcpy(v25, v16);

    v21 = (void *)(netz_468B50_available_units_denom + 1);
    *(_DWORD *)&v13[(_DWORD)&netz_47A740[3] + 4] = 1;
    netz_468B50_available_units_denom = (int)v21;
    return v21;
}

//----- (0042F820) --------------------------------------------------------
int __stdcall netz_nullsub_5(int a1, int a2)
{
    return 0;
}

//----- (0042F830) --------------------------------------------------------
int netz_init(int netz_provider_id, void(*a2)(), int(*a3)(int))
{
    int v3; // ebx@1
    int result; // eax@2

    v3 = netz_provider_id;
    if (a3)
    {
        netz_pfn_47A838 = (int(*)(netz_stru_3 *))a3;

        for (int i = 0; i < 3; ++i)
        {
            netz_468B6C_providers[i].is_directplay_initialized = netz_create_direct_play(i) >= 0;
        }
        if (v3 < 0)
            goto LABEL_16;
        if (v3 < 3 && netz_468B6C_providers[v3].is_directplay_initialized)
        {
            if (netz_468B6C_providers_idx != -1)
                netz_cleanup();
            netz_468B6C_providers_idx = v3;
            result = netz_42FB60_init_provider(v3);
        }
        else
        {
            result = 0xFE0004;
        }
        if (!result)
            LABEL_16:
        result = 0;
    }
    else
    {
        result = 0xFE000E;
    }
    return result;
}

//----- (0042F8C0) --------------------------------------------------------
int netz_42F8C0(int a1)
{
    int v2; // eax@10

    if (netz_468B6C_providers_idx == -1)
        return 16646158;
    netz_47A834 = (void *)(a1 != 0);
    netz_468D20 = -1;
    netz_430CE0();
    if (netz_47A834)
    {
        if (!netz_430910_dplay())
            return -1;
        if (!netz_430B10(1, 0))
            return -1;
    }
    else
    {
        if (!netz_430910_dplay())
            return 1;
        v2 = netz_47A898_object;
        if (netz_47A898_object)
        {
            if (netz_47A890)
            {
                (*(void(__stdcall **)(int, int))(*(_DWORD *)netz_47A898_object + 36))(netz_47A898_object, netz_47A890);
                v2 = netz_47A898_object;
                netz_47A890 = 0;
            }
            (*(void(__stdcall **)(int))(*(_DWORD *)v2 + 16))(v2);
        }
    }
    netz_47A934 = 0;
    return 0;
}

//----- (0042F8E0) --------------------------------------------------------
int netz_42F8E0(int a1)
{
    int result; // eax@1

    result = 0;
    if (netz_468B6C_providers_idx == -1)
    {
        result = 0xFE000E;
    }
    else if (netz_47A834 != (void *)(a1 != 0))
    {
        result = netz_4300C0((int)netz_47A834);
        if (!result)
            netz_47A834 = (void *)(netz_47A834 == 0);
    }
    return result;
}
// 468B68: using guessed type int netz_468B6C_providers_idx;

//----- (0042F930) --------------------------------------------------------
int netz_42F930_switch_provider(int netz_provider_id)
{
    int v1; // esi@1
    int result; // eax@6

    v1 = netz_provider_id;
    if (netz_provider_id < 3 && netz_provider_id >= 0 && netz_468B6C_providers[netz_provider_id].is_directplay_initialized)
    {
        if (netz_468B6C_providers_idx != -1)
            netz_cleanup();
        netz_468B6C_providers_idx = v1;
        result = netz_42FB60_init_provider(v1);
    }
    else
    {
        result = 0xFE0004;
    }
    return result;
}
// 468B68: using guessed type int netz_468B6C_providers_idx;

//----- (0042F980) --------------------------------------------------------
void netz_free_provider()
{
    if (netz_468B6C_providers_idx != -1)
    {
        netz_cleanup();
        netz_468B6C_providers_idx = -1;
    }
}
// 468B68: using guessed type int netz_468B6C_providers_idx;

//----- (0042F9A0) --------------------------------------------------------
void netz_deinit()
{
    if (netz_468B6C_providers_idx != -1)        // INLINED  42F980  netz_free_provider
    {
        netz_cleanup();
        netz_468B6C_providers_idx = -1;
    }
    netz_cleanup();
}
// 468B68: using guessed type int netz_468B6C_providers_idx;

//----- (0042F9C0) --------------------------------------------------------
int netz_42F9C0(int a1, int a2)
{
    int v2; // esi@1

    v2 = a1;
    if (netz_468B6C_providers_idx != -1)
    {
        netz_42FD30(a2);
        netz_430DA0(v2);
    }
    return 0;
}
// 468B68: using guessed type int netz_468B6C_providers_idx;

//----- (0042F9E0) --------------------------------------------------------
int netz_42F9E0(int a1)
{
    int result; // eax@2
    int v2; // ebx@3

    if (netz_468B6C_providers_idx == -1)
    {
        result = 0xFE000E;
    }
    else
    {
        v2 = netz_4301E0(a1);
        netz_468D20 = v2;
        if (v2 == -1)
        {
            result = 1;
        }
        else
        {
            *(_DWORD *)&netz_47A868.player_name[0] = *(_DWORD *)netz_default_player_name;
            *(_DWORD *)&netz_47A868.player_name[4] = *(_DWORD *)&netz_default_player_name[4];
            netz_47A868.field_8 = dword_468CE8;
            strcpy(netz_47A868.date, netz_468CD8_datetime[0]);
            strcpy(netz_47A868.time, netz_468CD8_datetime[1]);
            netz_42FF10(v2, 31, &netz_47A868, 0x21u, 1);
            result = 0;
        }
    }
    return result;
}
// 468B68: using guessed type int netz_468B6C_providers_idx;
// 468CE8: using guessed type int dword_468CE8;
// 468D20: using guessed type int netz_468D20;

//----- (0042FA00) --------------------------------------------------------
int netz_42FA00(int a1, int a2, void *a3, int a4, int a5)
{
    int result; // eax@3
    int v6; // edi@9
    netz_stru_5 *v7; // esi@9
    char a2a; // [sp+13h] [bp-1h]@1

    a2a = a2;
    if (a1 == -1)
        goto LABEL_18;
    if (netz_468B6C_providers_idx == -1)
        return 0xFE000E;
    if (!netz_47A940[a1].field_28)
        return 0xFE0005;
    if (netz_47A940[a1].field_0 != 2)
        return 0xFE0003;
    if (a1 != -1)
    {
        result = netz_42FF10(a1, a2, a3, a4, a5);
    }
    else
    {
    LABEL_18:
        v6 = 0;
        v7 = netz_47A940;
        do
        {
            if (v7->field_28)
            {
                if (v7->field_0 == 2)
                    netz_42FF10(v6, a2a, a3, a4, a5);
            }
            ++v7;
            ++v6;
        } while ((int)v7 < (int)netz_47AAA0);
        result = 0;
    }
    return result;
}
// 468B68: using guessed type int netz_468B6C_providers_idx;

//----- (0042FAC0) --------------------------------------------------------
int netz_42FAC0(const char *provider)
{
    int v1; // ebp@1
    char *v2; // ebx@1
    int v3; // esi@2
    const char **v4; // edi@2
    char *v6; // [sp+10h] [bp-4h]@1

    v6 = (char *)provider;
    v1 = 0;
    v2 = (char *)&netz_468B6C_providers[0].string_8;
    while (2)
    {
        v3 = 0;
        v4 = (const char **)v2;
        do
        {
            if (!_strcmpi(v6, *v4))
                return v1;
            ++v3;
            ++v4;
        } while (v3 < 2);
        v2 += 104;
        ++v1;
        if ((int)v2 < (int)&aDirectxModem[4])
            continue;
        break;
    }
    return -1;
}

//----- (0042FB60) --------------------------------------------------------
bool netz_42FB60_init_provider(int provider_id)
{
    int v1; // ecx@2
    BOOL result; // eax@4
    int v3; // eax@5
    int v4; // edx@5
    int v5; // [sp+Ch] [bp-10h]@5
    int v6; // [sp+10h] [bp-Ch]@5
    int v7; // [sp+14h] [bp-8h]@5
    int v8; // [sp+18h] [bp-4h]@5

    if (provider_id)
    {
        v1 = provider_id - 1;
        if (v1)
        {
            if (v1 != 1)
                return 1;
            v5 = netz_468D00;
            v7 = netz_468D08;
            v8 = netz_468D0C;
            v3 = netz_47A8DC;
            v4 = netz_47A8DC;
            v6 = netz_468D04;
            if (netz_47A8DC)
            {
                while (memcmp((const void *)(v4 + 4), &v5, 0x10u))
                {
                    v4 = *(_DWORD *)(v4 + 24);
                    if (!v4)
                        goto LABEL_16;
                }
                goto LABEL_17;
            }
        }
        else
        {
            v7 = netz_468D18;
            v3 = netz_47A8DC;
            v6 = netz_468D14;
            v5 = netz_468D10;
            v4 = netz_47A8DC;
            v8 = netz_468D1C;
            if (netz_47A8DC)
            {
                while (memcmp((const void *)(v4 + 4), &v5, 0x10u))
                {
                    v4 = *(_DWORD *)(v4 + 24);
                    if (!v4)
                        goto LABEL_16;
                }
                goto LABEL_17;
            }
        }
    }
    else
    {
        v5 = netz_468CF0;
        v6 = netz_468CF4;
        v3 = netz_47A8DC;
        v8 = netz_468CFC;
        v4 = netz_47A8DC;
        v7 = netz_468CF8;
        if (netz_47A8DC)
        {
            while (memcmp((const void *)(v4 + 4), &v5, 0x10u))
            {
                v4 = *(_DWORD *)(v4 + 24);
                if (!v4)
                    goto LABEL_16;
            }
            goto LABEL_17;
        }
    }
LABEL_16:
    v4 = 0;
LABEL_17:
    if (v4)
    {
        for (; v3; v3 = *(_DWORD *)(v3 + 24))
            *(_DWORD *)v3 = v3 == v4;
        result = 0;
    }
    else
    {
        result = 1;
    }
    return result;
}
// 468CF0: using guessed type int netz_468CF0;
// 468CF4: using guessed type int netz_468CF4;
// 468CF8: using guessed type int netz_468CF8;
// 468CFC: using guessed type int netz_468CFC;
// 468D00: using guessed type int netz_468D00;
// 468D04: using guessed type int netz_468D04;
// 468D08: using guessed type int netz_468D08;
// 468D0C: using guessed type int netz_468D0C;
// 468D10: using guessed type int netz_468D10;
// 468D14: using guessed type int netz_468D14;
// 468D18: using guessed type int netz_468D18;
// 468D1C: using guessed type int netz_468D1C;
// 47A8DC: using guessed type int netz_47A8DC;

//----- (0042FCA0) --------------------------------------------------------
void netz_cleanup()
{
    int v0; // eax@1
    void *v1; // esi@5
    void *v2; // eax@6
    void *v3; // esi@8
    void *v4; // eax@9

    v0 = netz_47A898_object;
    if (netz_47A898_object)
    {
        if (netz_47A890)
        {
            (*(void(__stdcall **)(int, int))(*(_DWORD *)netz_47A898_object + 36))(netz_47A898_object, netz_47A890);
            v0 = netz_47A898_object;
            netz_47A890 = 0;
        }
        (*(void(__stdcall **)(int))(*(_DWORD *)v0 + 16))(v0);
        (*(void(__stdcall **)(int))(*(_DWORD *)netz_47A898_object + 8))(netz_47A898_object);
        netz_47A898_object = 0;
    }
    v1 = netz_47A88C;
    if (netz_47A88C)
    {
        do
        {
            v2 = v1;
            v1 = (void *)*((_DWORD *)v1 + 11);
            free(v2);
        } while (v1);
        netz_47A88C = 0;
    }
    v3 = dword_47A8E0;
    if (dword_47A8E0)
    {
        do
        {
            v4 = v3;
            v3 = (void *)*((_DWORD *)v3 + 9);
            free(v4);
        } while (v3);
        dword_47A8E0 = 0;
    }
}
// 47A890: using guessed type int netz_47A890;
// 47A898: using guessed type int netz_47A898_object;

//----- (0042FD30) --------------------------------------------------------
void netz_42FD30(int a1)
{
    __debugbreak();
    /*	_DWORD *v1; // ebp@7
    void *v2; // ebx@7
    int v3; // edx@7
    _DWORD *v4; // eax@7
    int v5; // ecx@9
    _DWORD *i; // eax@9
    void *v7; // edx@13
    void *v8; // esi@22
    void *v9; // eax@23
    void *v10; // esi@25
    void *v11; // eax@26
    void *v12; // esi@29
    void *v13; // eax@30
    const char *v14; // esi@31
    int v15[12]; // [sp+1Ch] [bp-ACh]@7
    netz_stru_3 v16; // [sp+6Ch] [bp-5Ch]@1

    memset(&v16, 0, sizeof(v16));
    if (a1)
    {
    while (!netz_430340())
    ;
    }
    else
    {
    netz_430340();
    }
    if (netz_47A934)
    {
    v1 = (int *)netz_47A88C;
    memset(v15, 0, 0x50u);
    v15[6] = 0x87824EC0;
    v15[9] = 0x5CC2B8F6;
    v15[8] = 0x40009C83;
    netz_47A934 = 0;
    netz_47A88C = 0;
    v15[0] = 80;
    v15[7] = 0x11D0BB31;
    (*(void(__stdcall **)(int, int *, _DWORD, BOOL(__stdcall *)(int, int, char, int), _DWORD, int))(*(_DWORD *)netz_47A898_object + 52))(
    netz_47A898_object,
    v15,
    0,
    netz_4309A0,
    0,
    2);
    v2 = netz_47A88C;
    v3 = 0;
    v4 = (int *)netz_47A88C;
    if (netz_47A88C)
    {
    do
    {
    v4 = (_DWORD *)v4[11];
    ++v3;
    } while (v4);
    }
    v5 = 0;
    for (i = v1; i; ++v5)
    i = (_DWORD *)i[11];
    if (v5 == v3)
    {
    if (netz_47A88C)
    {
    while (1)
    {
    v7 = v1;
    if (v1)
    {
    while (memcmp(v7, v2, 0x10u))
    {
    v7 = (void *)*((_DWORD *)v7 + 11);
    if (!v7)
    goto LABEL_18;
    }
    strcpy((char *)v7 + 28, (const char *)v2 + 28);
    }
    LABEL_18:
    if (!v7)
    break;
    v2 = (void *)*((_DWORD *)v2 + 11);
    if (!v2)
    goto LABEL_25;
    }
    if (v1)
    {
    v8 = v1;
    do
    {
    v9 = v8;
    v8 = (void *)*((_DWORD *)v8 + 11);
    free(v9);
    } while (v8);
    v1 = 0;
    }
    }
    LABEL_25:
    v10 = netz_47A88C;
    netz_47A88C = v1;
    while (v10)
    {
    v11 = v10;
    v10 = (void *)*((_DWORD *)v10 + 11);
    free(v11);
    }
    }
    else if (v1)
    {
    v12 = v1;
    do
    {
    v13 = v12;
    v12 = (void *)*((_DWORD *)v12 + 11);
    free(v13);
    } while (v12);
    }
    v14 = (const char *)netz_47A88C;
    if (netz_47A88C)
    {
    do
    {
    v16.field_C = 1;
    LOWORD_HEXRAYS(v16.field_28) = 30;
    v16.field_24 = 0;
    v16.str_34 = v14;
    netz_pfn_47A838(&v16);
    v14 = (const char *)*((_DWORD *)v14 + 11);
    } while (v14);
    }
    }*/
}

//----- (0042FF10) --------------------------------------------------------
bool netz_42FF10(int a1, char a2, void *a3, unsigned int a4, int a5)
{
    int v5; // eax@1
    int v6; // edi@1
    int v7; // esi@2

    v5 = a1;
    netz_47AAA0[a1].field_3 = a2;
    memcpy(&netz_47AAA0[a1].stru0, a3, a4);
    v6 = netz_47A890;
    if (a1 == -1)
        v7 = 0;
    else
        v7 = netz_47A940[a1].field_24;
    netz_47AAA0[v5].field_2 = netz_47AAA0[v5].field_1++;
    netz_47AAA0[v5].field_11C = a4 + 2;
    return (*(int(__stdcall **)(int, int, int, _DWORD, char *, unsigned int))(*(_DWORD *)netz_47A898_object + 104))(
        netz_47A898_object,
        v6,
        v7,
        a5 != 0,
        &netz_47AAA0[v5].field_2,
        a4 + 2) != 0;
}

bool j_netz_42FFB0(int a1, int a2)
{
    return netz_42FFB0(a1, a2);
}

//----- (0042FFB0) --------------------------------------------------------
bool netz_42FFB0(int a1, int a2)
{
    int v2; // esi@2

    if (a1 == -1)
        v2 = 0;
    else
        v2 = netz_47A940[a1].field_24;
    return (*(int(__stdcall **)(int, int, int, _DWORD, char *, int))(*(_DWORD *)netz_47A898_object + 104))(
        netz_47A898_object,
        netz_47A890,
        v2,
        a2 != 0,
        &netz_47AAA0[a1].field_2,
        netz_47AAA0[a1].field_11C) != 0;
}
// 47A890: using guessed type int netz_47A890;
// 47A898: using guessed type int netz_47A898_object;

//----- (004300C0) --------------------------------------------------------
int netz_4300C0(int a1)
{
    int v2; // eax@4

    netz_468D20 = -1;
    if (!a1)
    {
        if (!netz_430910_dplay())
            return -1;
        if (!netz_430B10(1, 0))
            return -1;
        goto LABEL_12;
    }
    if (!netz_430910_dplay())
        return 1;
    v2 = netz_47A898_object;
    if (!netz_47A898_object)
    {
    LABEL_12:
        netz_47A934 = 0;
        return 0;
    }
    if (netz_47A890)
    {
        (*(void(__stdcall **)(int, int))(*(_DWORD *)netz_47A898_object + 36))(netz_47A898_object, netz_47A890);
        v2 = netz_47A898_object;
        netz_47A890 = 0;
    }
    (*(void(__stdcall **)(int))(*(_DWORD *)v2 + 16))(v2);
    netz_47A934 = 0;
    return 0;
}

//----- (004301E0) --------------------------------------------------------
int netz_4301E0(int a1)
{
    _DWORD *v1; // edx@1
    int v3; // ebx@8
    int v4; // edi@8
    void *v5; // esi@9
    void *v6; // eax@10
    _DWORD *v7; // esi@12
    char v8; // [sp+29h] [bp-69h]@13
    int v9; // [sp+2Ah] [bp-68h]@13
    int v10; // [sp+2Eh] [bp-64h]@8
    int v11; // [sp+32h] [bp-60h]@8
    netz_stru_3 v12; // [sp+36h] [bp-5Ch]@17

    __debugbreak();
    /*v1 = (int *)netz_47A88C;
    if (!netz_47A88C)
    return -1;
    do
    {
    if (!a1)
    break;
    v1 = (_DWORD *)v1[11];
    --a1;
    } while (v1);
    if (!v1)
    return -1;
    if (!netz_430B10(0, (int)v1))
    return -1;
    v3 = netz_430D10();
    v10 = v3;
    v4 = v3;
    v11 = v4 * 44;
    netz_47A940[v4].field_0 = 2;
    netz_47A940[v4].field_24 = 0;
    if (v3 != -1)
    {
    v5 = dword_47A8E0;
    if (dword_47A8E0)
    {
    do
    {
    v6 = v5;
    v5 = (void *)*((_DWORD *)v5 + 9);
    free(v6);
    } while (v5);
    dword_47A8E0 = 0;
    }
    (*(void(__stdcall **)(int, _DWORD, BOOL(__stdcall *)(int, int, int, char, int), _DWORD, _DWORD))(*(_DWORD *)netz_47A898_object + 48))(
    netz_47A898_object,
    0,
    netz_430A70,
    0,
    0);
    v7 = (int *)dword_47A8E0;
    if (!dword_47A8E0)
    return -1;
    do
    {
    v8 = byte_47A938;
    v9 = 1;
    (*(void(__stdcall **)(int, _DWORD, char *, int *, _DWORD))(*(_DWORD *)netz_47A898_object + 80))(
    netz_47A898_object,
    v7[8],
    &v8,
    &v9,
    0);
    if (v8 == 83)
    break;
    v7 = (_DWORD *)v7[9];
    } while (v7);
    v3 = v10;
    if (!v7)
    return -1;
    *(int *)((char *)&netz_47A940[0].field_24 + v11) = v7[8];
    memset(&v12, 0, sizeof(v12));
    v12.field_C = 3;
    v12.field_2C = v3;
    if (v12.field_20)
    {
    ((void(__thiscall *)(netz_stru_3 *))v12.field_20)(&v12);
    return v3;
    }
    netz_pfn_47A838(&v12);
    }
    return v3;*/
    return 0;
}

//----- (00430340) --------------------------------------------------------
int netz_430340()
{
    __debugbreak();
    /*	int v0; // ebp@1
    int v2; // eax@16
    int v3; // ecx@17
    int v4; // edx@20
    int v5; // edi@24
    netz_stru_5 *v6; // esi@24
    int v7; // ecx@30
    int v8; // edx@30
    char *v9; // eax@30
    char v10; // al@37
    int v11; // [sp+Ch] [bp-1ECh]@4
    int v12; // [sp+18h] [bp-1E0h]@2
    int v13; // [sp+1Ch] [bp-1DCh]@1
    int v14; // [sp+20h] [bp-1D8h]@2
    netz_stru_3 v15; // [sp+24h] [bp-1D4h]@10
    netz_stru_3 v16; // [sp+80h] [bp-178h]@16
    char v17; // [sp+DCh] [bp-11Ch]@2
    char v18; // [sp+DDh] [bp-11Bh]@10
    char v19; // [sp+DEh] [bp-11Ah]@10

    v0 = 0;
    v13 = 280;
    if (!netz_47A898_object)
    return 1;
    v14 = 0;
    if ((*(int(__stdcall **)(int, int *, int *, int, char *, int *))(*(_DWORD *)netz_47A898_object + 100))(
    netz_47A898_object,
    &v14,
    &v12,
    1,
    &v17,
    &v13)
    || !v14)
    {
    return 1;
    }
    if (&v11 != (int *)-12)
    v0 = v14;
    if (v14 == netz_47A890 || v12 && v12 != netz_47A890)
    return 1;
    v15.field_24 = 0;
    v15.field_C = 1;
    LOWORD_HEXRAYS(v15.field_28) = v18;
    v15.str_34 = &v19;
    v15.field_38 = v13;
    v15.field_30 = v0;
    if (v18 < 50 && v18)
    {
    if (v18 == 30)
    {
    if (!netz_47A834)
    {
    v4 = netz_430D10();
    if (v4 != -1)
    {
    netz_47A940[v4].field_0 = 2;
    memset(&v16, 0, sizeof(v16));
    v16.field_2C = v4;
    v16.field_C = 4;
    if (v16.field_20)
    ((void(__thiscall *)(netz_stru_3 *))v16.field_20)(&v16);
    else
    netz_pfn_47A838(&v16);
    }
    netz_47A844 = *(_DWORD *)&netz_default_player_name[4];
    netz_47A848 = dword_468CE8;
    netz_47A840 = *(_DWORD *)netz_default_player_name;
    strcpy((char *)&unk_47A84C, netz_468CD8_datetime[0]);
    strcpy((char *)&unk_47A858, netz_468CD8_datetime[1]);
    v5 = 0;
    v6 = netz_47A940;
    do
    {
    if (v6->field_28 && v6->field_0 == 2)
    netz_42FF10(v5, 31, &netz_47A840, 0x21u, 1);
    ++v6;
    ++v5;
    } while ((int)v6 < (int)netz_47AAA0);
    netz_47A934 = 0;
    }
    }
    else if (v18 == 31 && netz_47A834)
    {
    if (netz_468D20 == -1)
    {
    memset(&v16, 0, sizeof(v16));
    v16.field_C = 4;
    v2 = netz_430D10();
    if (v2 != -1)
    {
    v16.field_2C = v2;
    v3 = v2;
    netz_47A940[v3].field_24 = v0;
    netz_47A940[v3].field_28 = 1;
    netz_47A940[v3].field_0 = 2;
    netz_pfn_47A838(&v16);
    }
    }
    else
    {
    LOWORD_HEXRAYS(v15.field_28) = 0;
    }
    }
    }
    v7 = 0;
    v8 = -1;
    v15.field_2C = -1;
    v9 = (char *)&netz_47A940[0].field_24;
    while (!*((_DWORD *)v9 + 1) || *(_DWORD *)v9 != v0)
    {
    v9 += 44;
    ++v7;
    if ((int)v9 >= (int)&netz_47AAA0[0].stru0.time[8])
    goto LABEL_36;
    }
    v8 = v7;
    v15.field_2C = v7;
    LABEL_36:
    if (v8 == -1)
    goto LABEL_39;
    v10 = netz_47AAA0[v8].field_0;
    if (v10 == v17)
    {
    netz_47AAA0[v8].field_0 = v10 + 1;
    LABEL_39:
    if (SLOWORD_HEXRAYS(v15.field_28) >= 30)
    netz_pfn_47A838(&v15);
    }
    return 0;*/
    return 0;
}

int j_netz_430610()
{
    return netz_430610();
}

//----- (00430610) --------------------------------------------------------
int netz_430610()
{
    int result; // eax@1

    result = netz_47A898_object;
    if (netz_47A898_object)
    {
        netz_47A8E4.field_4 |= 0x21u;
        result = (*(int(__stdcall **)(int, netz_stru_4 *, _DWORD))(*(_DWORD *)netz_47A898_object + 124))(
            netz_47A898_object,
            &netz_47A8E4,
            0);
    }
    return result;
}

int j_netz_430640()
{
    return netz_430640();
}

//----- (00430640) --------------------------------------------------------
int netz_430640()
{
    int result; // eax@1

    result = netz_47A898_object;
    if (netz_47A898_object)
    {
        netz_47A8E4.field_4 &= 0xFFFFFFDE;
        result = (*(int(__stdcall **)(int, netz_stru_4 *, _DWORD))(*(_DWORD *)netz_47A898_object + 124))(
            netz_47A898_object,
            &netz_47A8E4,
            0);
    }
    return result;
}

int j_netz_430670(int a1)
{
    return netz_430670(a1);
}

//----- (00430670) --------------------------------------------------------
int netz_430670(int a1)
{
    int result; // eax@1

    result = netz_47A898_object;
    if (netz_47A898_object)
    {
        netz_47A8E4.field_30 = a1;
        result = (*(int(__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)netz_47A898_object + 124))(
            netz_47A898_object,
            (int)&netz_47A8E4,
            0);
    }
    return result;
}

int j_netz_430690()
{
    return netz_430690();
}

//----- (00430690) --------------------------------------------------------
int netz_430690()
{
    int result; // eax@1

    result = netz_47A898_object;
    if (netz_47A898_object)
    {
        if (netz_47A890)
        {
            (*(void(__stdcall **)(int, int))(*(_DWORD *)netz_47A898_object + 36))(netz_47A898_object, netz_47A890);
            result = netz_47A898_object;
            netz_47A890 = 0;
        }
        result = (*(int(__stdcall **)(int))(*(_DWORD *)result + 16))(result);
    }
    return result;
}

//----- (004306C0) --------------------------------------------------------
bool __stdcall DirectPlayEnumerateACallback(void *lpguidSP, char *lpSPName, __int32 dwMajorVersion, __int32 dwMinorVersion, void *lpContext) {
    return false;
}
//BOOL __stdcall DirectPlayEnumerateACallback(LPGUID lpguidSP, LPSTR lpSPName, DWORD dwMajorVersion, DWORD dwMinorVersion, LPVOID lpContext)
//{
//    HLOCAL v5; // eax@1
//    int v6; // ebx@1
//    char *v7; // edx@2
//    int v8; // ecx@2
//    int i; // eax@4
//
//    v5 = LocalAlloc(0, 0x1Cu);
//    v6 = (int)v5;
//    if (v5)
//    {
//        *(GUID *)((char *)v5 + 4) = *lpguidSP;
//        v7 = (char *)LocalAlloc(0, strlen(lpSPName) + 1);
//        *(_DWORD *)(v6 + 20) = (int)v7;
//        strcpy(v7, lpSPName);
//        v8 = netz_47A8DC;
//        if (!netz_47A8DC)
//        {
//            netz_47A8DC = v6;
//            *(_DWORD *)(v6 + 24) = 0;
//            return 1;
//        }
//        for (i = *(_DWORD *)(netz_47A8DC + 24); i; i = *(_DWORD *)(i + 24))
//            v8 = i;
//        *(_DWORD *)(v8 + 24) = v6;
//        *(_DWORD *)(v6 + 24) = 0;
//    }
//    return 1;
//}

//----- (00430780) --------------------------------------------------------
int netz_create_direct_play(int a1)
{
    /*	int v1; // eax@1
    int v2; // ebp@1
    int v3; // edi@2
    LPDIRECTPLAY lpDP; // [sp+10h] [bp-14h]@3
    int v6; // [sp+14h] [bp-10h]@12
    int v7; // [sp+18h] [bp-Ch]@12
    int v8; // [sp+1Ch] [bp-8h]@12
    int v9; // [sp+20h] [bp-4h]@12

    v1 = netz_47A8DC;
    v2 = a1;
    if (!netz_47A8DC)
    {
    DirectPlayEnumerateA(DirectPlayEnumerateACallback, 0);
    v1 = netz_47A8DC;
    v3 = netz_47A8DC;
    if (netz_47A8DC)
    {
    do
    {
    lpDP = 0;
    if (DirectPlayCreate((LPGUID)(v3 + 4), &lpDP, 0))
    {
    *(_DWORD *)(v3 + 4) = 0;
    *(_DWORD *)(v3 + 8) = 0;
    *(_DWORD *)(v3 + 12) = 0;
    *(_DWORD *)(v3 + 16) = 0;
    }
    else
    {
    (*((void(__stdcall **)(_DWORD))lpDP->lpVtbl + 2))(lpDP);
    }
    v3 = *(_DWORD *)(v3 + 24);
    } while (v3);
    v1 = netz_47A8DC;
    }
    }
    if (v2)
    {
    if (v2 == 1)
    {
    v6 = netz_468D10;
    v7 = netz_468D14;
    v8 = netz_468D18;
    v9 = netz_468D1C;
    if (v1)
    {
    while (memcmp((const void *)(v1 + 4), &v6, 0x10u))
    {
    v1 = *(_DWORD *)(v1 + 24);
    if (!v1)
    return -1;
    }
    return (v1 != 0) - 1;
    }
    }
    else
    {
    if (v2 != 2)
    return -1;
    v6 = netz_468D00;
    v7 = netz_468D04;
    v8 = netz_468D08;
    v9 = netz_468D0C;
    if (v1)
    {
    while (memcmp((const void *)(v1 + 4), &v6, 0x10u))
    {
    v1 = *(_DWORD *)(v1 + 24);
    if (!v1)
    return -1;
    }
    return (v1 != 0) - 1;
    }
    }
    }
    else
    {
    v6 = netz_468CF0;
    v7 = netz_468CF4;
    v8 = netz_468CF8;
    v9 = netz_468CFC;
    if (v1)
    {
    while (memcmp((const void *)(v1 + 4), &v6, 0x10u))
    {
    v1 = *(_DWORD *)(v1 + 24);
    if (!v1)
    goto LABEL_23;
    }
    return (v1 != 0) - 1;
    }
    }
    LABEL_23:
    v1 = 0;
    return (v1 != 0) - 1;*/
    return 0;
}

//----- (00430910) --------------------------------------------------------
bool netz_430910_dplay()
{
    __debugbreak();
    return 0;
    /*	int v0; // eax@1
    int v1; // esi@6
    LPDIRECTPLAY lpDP; // [sp+Ch] [bp-4h]@6

    v0 = netz_47A8DC;
    if (netz_47A8DC)
    {
    do
    {
    if (*(_DWORD *)v0)
    break;
    v0 = *(_DWORD *)(v0 + 24);
    } while (v0);
    if (v0)
    {
    if (netz_47A898_object)
    return 1;
    v1 = v0 + 4;
    if (!DirectPlayCreate((LPGUID)(v0 + 4), &lpDP, 0))
    {
    (*(void(__stdcall **)(_DWORD, _DWORD, _DWORD))lpDP->lpVtbl)(lpDP, &netz_463DE0, &netz_47A898_object);
    (*((void(__stdcall **)(_DWORD))lpDP->lpVtbl + 2))(lpDP);
    netz_47A89C = *(_DWORD *)v1;
    netz_47A8A0 = *(_DWORD *)(v1 + 4);
    netz_47A8A4 = *(_DWORD *)(v1 + 8);
    netz_47A8A8 = *(_DWORD *)(v1 + 12);
    return 1;
    }
    }
    }
    return 0;*/
}

//----- (004309A0) --------------------------------------------------------
bool __stdcall netz_4309A0(int a1, int a2, char a3, int a4)
{
    int v4; // eax@3
    void *v5; // eax@5
    _BYTE *v6; // esi@5
    _DWORD *v7; // ecx@6
    int i; // eax@7

    if (!a1 || a3 & 1)
        return 0;
    v4 = *(_DWORD *)(a1 + 4);
    if ((*(_BYTE *)(a1 + 4) & 1) == 1)
        return 1;
    if ((v4 & 0x20) == 32)
        return 1;
    v5 = malloc(0x30u);
    v6 = (char *)v5;
    if (!v5)
        return 1;
    *(_DWORD *)v5 = *(_DWORD *)(a1 + 8);
    *((_DWORD *)v5 + 1) = *(_DWORD *)(a1 + 12);
    *((_DWORD *)v5 + 2) = *(_DWORD *)(a1 + 16);
    *((_DWORD *)v5 + 3) = *(_DWORD *)(a1 + 20);
    strncpy((char *)v5 + 28, *(const char **)(a1 + 48), 0x10u);
    v6[43] = 0;
    *((_DWORD *)v6 + 4) = *(_DWORD *)(a1 + 40);
    *((_DWORD *)v6 + 5) = *(_DWORD *)(a1 + 44);
    *((_DWORD *)v6 + 6) = *(_DWORD *)(a1 + 4);
    *((_DWORD *)v6 + 11) = 0;
    v7 = (int *)netz_47A88C;
    if (!netz_47A88C)
    {
        netz_47A88C = v6;
        return 1;
    }
    for (i = *((_DWORD *)netz_47A88C + 11); i; i = *(_DWORD *)(i + 44))
        v7 = (_DWORD *)i;
    v7[11] = (int)v6;
    return 1;
}

//----- (00430A70) --------------------------------------------------------
bool __stdcall netz_430A70(int a1, int a2, int a3, char a4, int a5)
{
    void *v6; // esi@3
    _DWORD *v7; // ecx@4
    int i; // eax@5

    if (a4 & 8)
        return 1;
    v6 = malloc(0x28u);
    if (!v6)
        return 1;
    strncpy((char *)v6, *(const char **)(a3 + 12), 0x10u);
    *((_BYTE *)v6 + 15) = 0;
    strncpy((char *)v6 + 16, *(const char **)(a3 + 8), 0x10u);
    *((_BYTE *)v6 + 31) = 0;
    *((_DWORD *)v6 + 8) = a1;
    *((_DWORD *)v6 + 9) = 0;
    v7 = (int *)dword_47A8E0;
    if (!dword_47A8E0)
    {
        dword_47A8E0 = v6;
        return 1;
    }
    for (i = *((_DWORD *)dword_47A8E0 + 9); i; i = *(_DWORD *)(i + 36))
        v7 = (_DWORD *)i;
    v7[9] = (int)v6;
    return 1;
}

//----- (00430B10) --------------------------------------------------------
int netz_430B10(int a1, int a2)
{
    int v2; // ebx@1
    int result; // eax@2
    int v4; // esi@6
    int v5; // ecx@10
    int v6; // eax@11
    DWORD pcbBuffer; // [sp+Ch] [bp-24h]@3
    int v8; // [sp+10h] [bp-20h]@10
    int v9; // [sp+14h] [bp-1Ch]@10
    char *v10; // [sp+18h] [bp-18h]@10
    char *v11; // [sp+1Ch] [bp-14h]@10
    char username[256]; // [sp+20h] [bp-10h]@3

    v2 = a2;
    if (netz_47A898_object)
    {
        strcpy(username, OsGetUserName().c_str());
        //pcbBuffer = 15;
        //if (!GetUserNameA(username, &pcbBuffer))
        //    strcpy(username, aUnknown);
        memset(&netz_47A8E4, 0, sizeof(netz_47A8E4));
        netz_47A8E4.field_18 = 0x87824EC0;
        netz_47A8E4.field_0 = 80;
        netz_47A8E4.field_1C = 0x11D0BB31;
        netz_47A8E4.field_20 = 0x40009C83;
        netz_47A8E4.field_24 = 0x5CC2B8F6;
        netz_47A8E4.field_4 = 0;
        if (v2)
        {
            v4 = 1;
            netz_47A8E4.field_8 = *(_DWORD *)v2;
            netz_47A8E4.field_C = *(_DWORD *)(v2 + 4);
            netz_47A8E4.field_10 = *(_DWORD *)(v2 + 8);
            netz_47A8E4.field_14 = *(_DWORD *)(v2 + 12);
        }
        else
        {
            netz_47A8E4.field_8 = netz_47A89C;
            v4 = 2;
            netz_47A8E4.field_C = netz_47A8A0;
            netz_47A8E4.field_10 = netz_47A8A4;
            netz_47A8E4.field_14 = netz_47A8A8;
            netz_47A8E4.field_28 = 6;
            netz_47A8E4.field_30 = (int)netz_default_player_name;
        }
        if ((*(int(__stdcall **)(int, netz_stru_4 *, int))(*(_DWORD *)netz_47A898_object + 96))(
            netz_47A898_object,
            &netz_47A8E4,
            v4))
        {
            result = 0;
        }
        else
        {
            v10 = username;
            v8 = 16;
            v9 = 0;
            v11 = username;
            v5 = *(_DWORD *)netz_47A898_object;
            if (v2)
                v6 = (*(int(__stdcall **)(int, int *, int *, _DWORD, char *, int, _DWORD))(v5 + 24))(
                    netz_47A898_object,
                    &netz_47A890,
                    &v8,
                    0,
                    aC_0,
                    1,
                    0);
            else
                v6 = (*(int(__stdcall **)(int, int *, int *, _DWORD, char *, int, _DWORD))(v5 + 24))(
                    netz_47A898_object,
                    &netz_47A890,
                    &v8,
                    0,
                    aS_1,
                    1,
                    0);
            if (v6)
            {
                result = 0;
            }
            else
            {
                if (v4 == 2)
                {
                    netz_47A8E4.field_40 = netz_47A890;
                    (*(void(__stdcall **)(int, netz_stru_4 *, _DWORD))(*(_DWORD *)netz_47A898_object + 124))(
                        netz_47A898_object,
                        &netz_47A8E4,
                        0);
                }
                result = 1;
            }
        }
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (00430CE0) --------------------------------------------------------
int netz_430CE0()
{
    char *v0; // eax@1

    v0 = (char *)&netz_47A940[0].field_28;
    do
    {
        *(_DWORD *)v0 = 0;
        v0 += 44;
    } while ((int)v0 < (int)&netz_47AAA0[0].field_25[3]);
    netz_47B3A0 = 0;
    return 0;
}
// 47B3A0: using guessed type int netz_47B3A0;

//----- (00430D10) --------------------------------------------------------
int netz_430D10()
{
    int v0; // ecx@1
    char *v1; // eax@1
    int result; // eax@4
    int v3; // ecx@6

    v0 = 0;
    v1 = (char *)&netz_47A940[0].field_28;
    while (*(_DWORD *)v1)
    {
        v1 += 44;
        ++v0;
        if ((int)v1 >= (int)&netz_47AAA0[0].field_25[3])
        {
            result = -1;
            goto LABEL_5;
        }
    }
    result = v0;
LABEL_5:
    if (result != -1)
    {
        netz_47A940[result].field_28 = 1;
        v3 = result;
        netz_47AAA0[v3].field_0 = 0;
        netz_47AAA0[v3].field_1 = 0;
        netz_47AAA0[v3].field_11C = 0;
        ++netz_47B3A0;
    }
    return result;
}
// 47B3A0: using guessed type int netz_47B3A0;

//----- (00430D70) --------------------------------------------------------
int netz_430D70(int a1)
{
    if (netz_47A940[a1].field_28)
    {
        netz_47A940[a1].field_28 = 0;
        --netz_47B3A0;
    }
    return 0;
}
// 47B3A0: using guessed type int netz_47B3A0;

//----- (00430DA0) --------------------------------------------------------
int netz_430DA0(unsigned int a1)
{
    unsigned int v1; // edi@1
    int v2; // ecx@1
    int v3; // esi@2
    int v4; // eax@4
    void(*v5)(void); // eax@7

    v1 = a1;
    v2 = nezt_47B3B0;
    if (nezt_47B3B0)
    {
        do
        {
            v3 = *(_DWORD *)(v2 + 4);
            if (*(_DWORD *)v2 && *(_DWORD *)(v2 + 16) <= v1)
            {
                v4 = *(_DWORD *)(v2 + 20);
                if (v4)
                    *(_DWORD *)(v2 + 20) = v4 - 1;
                if (!*(_DWORD *)(v2 + 20))
                {
                    v5 = *(void(**)(void))(v2 + 24);
                    if (v5)
                        v5();
                }
            }
            v2 = v3;
        } while (v3);
    }
    return 0;
}
// 47B3B0: using guessed type int nezt_47B3B0;

//----- (00430DF0) --------------------------------------------------------
char *netz_get_error_string(int error_code)
{
    char *result; // eax@4
    char *(*get_error_name)(); // eax@26

    if (error_code > 0xFE0000)
    {
        switch (error_code)
        {
        case 0xFE0005:
            result = aLinkNotOpen;
            break;
        case 0xFE0001:
            result = aLinkInUseAlrea;
            break;
        case 0xFE0002:
            result = aNoFreeLinks;
            break;
        case 0xFE0003:
            result = aLinkIsNotConne;
            break;
        case 0xFE0004:
            result = aProtocolIsNotP;
            break;
        case 0xFE0007:
            result = aWrongTypeOfLin;
            break;
        case 0xFE0008:
            result = aPortSocketInUs;
            break;
        case 0xFE0009:
            result = aInternalResour;
            break;
        case 0xFE000A:
            result = aPacketIsTooBig;
            break;
        case 0xFE000B:
            result = aCouldNotCreate;
            break;
        case 0xFE000C:
            result = aWrongModeForNe;
            break;
        case 0xFE000D:
            result = aNameIsNotUniqu;
            break;
        case 0xFE000E:
            result = aFailed;
            break;
        case 0xFE000F:
            result = aOperatingSyste;
            break;
        case 0xFE0010:
            result = aNetzRequiresA4;
            break;
        case 0xFE0011:
            result = aLinkLost;
            break;
        case 0xFE0012:
            result = aDisabled;
            break;
        case 0xFE0013:
            result = aNotYetImplemen;
            break;
        default:
            goto LABEL_25;
        }
    }
    else if (error_code == 0xFE0000)
    {
        result = aOutOfMemory;
    }
    else if (error_code)
    {
    LABEL_25:
        if (netz_468B6C_providers_idx == -1)
        {
            result = aUnknownNetzE_0;
        }
        else
        {
            get_error_name = netz_468B6C_providers[netz_468B6C_providers_idx + 1].get_error_name;
            if (get_error_name)
                result = get_error_name();
            else
                result = aUnknownNetzErr;
        }
    }
    else
    {
        result = aNoError;
    }
    return result;
}


//----- (00449820) --------------------------------------------------------
void script_449820_netz(Script *a1)
{
    void *v1; // eax@1
    int v2; // edx@1
    netz_stru6_per_player *v3; // eax@2
    DWORD v4; // ebx@4
    DWORD v5; // edi@4
    void *v6; // eax@4
    int v7; // eax@7
    netz_stru6_per_player *v8; // eax@11
    stru209 *v9; // eax@20
    void *v10; // edx@20
    _47CA80_global *v11; // ecx@22
    _BYTE *v12; // esi@24
    _47CA80_global *v13; // eax@24
    _47A780_global *v14; // ecx@24
    int v15; // edi@27
    void *v16; // ebx@29
    int *v17; // edi@29
    int v18; // eax@34
    _BYTE *v19; // edx@35
    netz_stru6_per_player *v20; // eax@43
    int v21; // edx@47
    int v22; // esi@47
    _47CA80_global *v23; // eax@48
    char *v24; // ecx@48
    int v25; // eax@64
    int v26; // ecx@67
    int v27; // edx@76
    stru209 *v28; // eax@76
    int v29; // eax@83
    void *v30; // esi@87
    Script *v31; // [sp-Ch] [bp-7Ch]@40
    Script *v32; // [sp-Ch] [bp-7Ch]@74
    int v33; // [sp-8h] [bp-78h]@85
    int v34; // [sp-4h] [bp-74h]@40
    int v35; // [sp-4h] [bp-74h]@74
    int v36; // [sp+0h] [bp-70h]@7
    _BYTE a3[92]; // [sp+Ch] [bp-64h]@24
    int v38; // [sp+68h] [bp-8h]@24
    int v39; // [sp+6Ch] [bp-4h]@24

    *(_DWORD *)&netz_47A740[2].str_0[0] = 0;
    dword_47CB1C = 1;
    dword_47953C = 0;
    sub_408460();
    dword_47CB0C = 1;
    v1 = (void *)_47A660_list_reset();
    if (netz_47A834)
    {
        dword_47A830 = 1;
        dword_47CB10 = netz_468B50_available_units_denom - 1;
        v3 = &netz_47A740[3];
        do
        {
            *(_DWORD *)&v3->str_0[0] = 0;
            ++v3;
        } while ((int)v3 < (int)&dword_47A83C);
        netz_42E690(v3, 50);
        v4 = timeGetTime();
        v5 = timeGetTime();
        v6 = (void *)dword_47CB10;
        if (dword_47CB10)
        {
            while (1)
            {
                netz_42F9C0(0, 1);
                if (timeGetTime() - v5 > 0x7530)
                {
                    v8 = &netz_47A740[3];
                    dword_47CB10 = netz_468B50_available_units_denom - 1;
                    do
                    {
                        *(_DWORD *)&v8->str_0[0] = 0;
                        ++v8;
                    } while ((int)v8 < (int)&dword_47A83C);
                    netz_42E690(v8, 50);
                    v5 = timeGetTime();
                }
                if (timeGetTime() - v4 > 0x1D4C0)
                    break;
                v6 = (void *)dword_47CB10;
                if (!dword_47CB10)
                    goto LABEL_18;
            }
            dword_47CB18 = 1;
            dword_47CB1C = 0;
        }
    LABEL_18:
        if (dword_47CB1C == 1)
        {
            while (1)
            {
                if (dword_47CB0C)
                {
                    v9 = _47A660_list_get();
                    v10 = __47CA80_array_idx_and_netz_player_side;
                    if (v9)
                    {
                        v11 = &_47CA80_array[(_DWORD)__47CA80_array_idx_and_netz_player_side];
                        memcpy(v11, v9, 12);
                    }
                    else
                    {
                        LOBYTE_HEXRAYS(_47CA80_array[(_DWORD)__47CA80_array_idx_and_netz_player_side].field_0) = 0;
                    }
                }
                else
                {
                    v10 = __47CA80_array_idx_and_netz_player_side;
                }
                v12 = &a3[1];
                v38 = 0;
                v39 = 0;
                v13 = _47CA80_array;
                v14 = (_47A780_global *)&netz_47A740[2].field_8;
                do
                {
                    if (LOBYTE_HEXRAYS(v14->field_0) && LOBYTE_HEXRAYS(v13->field_0))
                    {
                        *v12 = v39;
                        v15 = (int)(v12 + 1);
                        v12 += 14;
                        *(_DWORD *)v15 = v13->field_0;
                        *(_DWORD *)(v15 + 4) = v13->field_4;
                        *(_DWORD *)(v15 + 8) = v13->field_8;
                        *(_BYTE *)(v15 + 12) = v13->field_C;
                        ++v38;
                        v10 = __47CA80_array_idx_and_netz_player_side;
                    }
                    ++v14;
                    ++v13;
                    ++v39;
                } while ((int)v14 < (int)&netz_47A828);
                LOBYTE_HEXRAYS(v13) = v38;
                v16 = 0;
                a3[0] = v38;
                v17 = &netz_47A740[2].field_18;
                do
                {
                    if (*((_BYTE *)v17 - 16) == 1 && v16 != v10)
                    {
                        v19 = a3;
                        LOBYTE_HEXRAYS(v19) = 51;
                        v13 = (_47CA80_global *)netz_42FA00(*v17, (int)v19, a3, v12 - a3, 0);
                        v10 = __47CA80_array_idx_and_netz_player_side;
                    }
                    v17 += 7;
                    v16 = (char *)v16 + 1;
                } while ((int)v17 < (int)&netz_pfn_47A838);
                if (dword_47CB0C)
                {
                    v34 = 4;
                    v31 = a1;
                }
                else
                {
                    v34 = 1;
                    v31 = a1;
                }
                script_sleep(v31, v34);
                if (dword_47CB1C != 1)
                    break;
                dword_47CB14 = netz_468B50_available_units_denom - 1;
                v20 = &netz_47A740[3];
                do
                {
                    *(_DWORD *)&v20->str_0[0] = 0;
                    ++v20;
                } while ((int)v20 < (int)&dword_47A83C);
                if (netz_449E00(&dword_47CB14, 0x9C40u, aWaitingForPlay))
                {
                    dword_47A738 = 0;
                    is_coroutine_list_initialization_failed = 0;
                    netz_42F620();
                    dword_47CB14 = -1;
                    dword_47CB18 = 1;
                    *(_DWORD *)&netz_47A740[2].str_0[0] = 0;
                    break;
                }
                if (dword_47CB1C != 1)
                    break;
                v21 = netz_468B50_available_units_denom;
                v22 = -1;
                dword_47050C = -1;
                if (netz_468B50_available_units_denom > 0)
                {
                    v23 = _47CA80_array;
                    v24 = &netz_47A740[2].field_8;
                    do
                    {
                        if (*v24 == 1 && LOBYTE_HEXRAYS(v23->field_0) == 15)
                        {
                            if (v22 == -1)
                                v22 = 1;
                            else
                                LOBYTE_HEXRAYS(v23->field_0) = 17;
                        }
                        v24 += 28;
                        ++v23;
                        --v21;
                    } while (v21);
                    dword_47050C = v22;
                }
            }
        }
    }
    else
    {
        LOBYTE_HEXRAYS(v2) = 59;
        netz_42FA00(dword_468B54, v2, 0, 0, 1);
        v26 = dword_47CB1C;
        if (dword_47CB1C == 1)
        {
            while (dword_468B54 != -1 && netz_47A940[dword_468B54].field_28)
            {
                if (v26 != 1)
                    goto LABEL_57;
                dword_47CB14 = 1;
                if (netz_449E00(&dword_47CB14, 0x9C40u, aWaitingForServ))
                {
                    dword_47A738 = 0;
                    is_coroutine_list_initialization_failed = 0;
                    netz_42F620();
                    dword_47CB14 = -1;
                    dword_47CB18 = 1;
                    *(_DWORD *)&netz_47A740[2].str_0[0] = 0;
                    goto LABEL_57;
                }
                if (dword_47CB1C != 1)
                    goto LABEL_57;
                if (dword_47CB0C)
                {
                    v35 = 4;
                    v32 = a1;
                }
                else
                {
                    v35 = 1;
                    v32 = a1;
                }
                script_sleep(v32, v35);
                v28 = (stru209 *)dword_47CB1C;
                if (dword_47CB1C != 1)
                    goto LABEL_57;
                if (dword_47CB0C)
                {
                    v28 = _47A660_list_get();
                    if (v28)
                    {
                        memcpy(&stru_47CAE0, v28, sizeof(stru_47CAE0));
                        v27 = *(int *)((char *)&v28->param + 3);
                    }
                    else
                    {
                        stru_47CAE0.type = stru209_TYPE_0;
                    }
                }
                if (stru_47CAE0.type)
                    v33 = 13;
                else
                    v33 = 1;
                LOBYTE_HEXRAYS(v27) = 52;
                v30 = (void *)netz_42FA00(dword_468B54, v27, &stru_47CAE0, v33, 0);
                netz_42E400(v30);
                if (v30)
                    break;
                v26 = dword_47CB1C;
                if (dword_47CB1C != 1)
                    goto LABEL_57;
            }
            dword_47CB18 = 1;
        }
    }
LABEL_57:
    dword_47C6F4 = 0;
    if (dword_47CB18)
    {
        script_47A3CC_die();
        dword_47CB18 = 0;
    }
    if (netz_468B50_available_units_denom <= 2)
        *(_DWORD *)&netz_47A740[2].str_0[0] = 1;
    script_terminate(a1);
}

//----- (00449E00) --------------------------------------------------------
bool netz_449E00(_DWORD *a1, unsigned int a2, const char *a3)
{
    _DWORD *v3; // ebx@1
    DWORD v4; // esi@1
    void *v5; // eax@2
    int v6; // eax@5
    char *v7; // esi@12
    int v8; // eax@18
    int v9; // eax@25
    BOOL result; // eax@32
    int v11; // [sp+0h] [bp-14h]@5
    unsigned int v12; // [sp+Ch] [bp-8h]@1
    DWORD v13; // [sp+10h] [bp-4h]@1

    v12 = a2;
    v3 = a1;
    v4 = timeGetTime();
    v13 = timeGetTime();
    if (!*v3)
        goto LABEL_36;
    do
    {
        v5 = (void *)(timeGetTime() - v13);
        if ((unsigned int)v5 >= v12)
            break;
        netz_42F9C0(0, 1);
        if (*v3 == -1 || dword_47CB1C != 1)
            break;
        if (timeGetTime() - v4 > 0x1F4)
        {
            if (netz_47A834)
            {
                v7 = &netz_47A740[2].field_8;
                do
                {
                    if ((*v7 == 1 || *v7 == 3) && !*((_DWORD *)v7 + 5))
                    {
                        j_netz_42FFB0(*((_DWORD *)v7 + 4), 0);
                    }
                    v7 += 28;
                } while ((int)v7 < (int)&netz_47A828);
            }
            else
            {
                j_netz_42FFB0(netz_47A740[dword_468B54 + 2].field_18, 0);
            }
            v4 = timeGetTime();
        }
    } while (*v3);
    if (*v3 && *v3 != -1)
        result = 1;
    else
        LABEL_36:
    result = 0;
    return result;
}

//----- (00449FF0) --------------------------------------------------------
void netz_449FF0()
{
    void *v0; // eax@1
    int *v1; // esi@2
    int v2; // eax@6
    void *v3; // eax@14
    int v4; // eax@17
    int v5; // [sp+0h] [bp-8h]@6

    v0 = netz_47A834;
    if (netz_47A834)
    {
        *(_DWORD *)&netz_47A740[2].str_0[0] = 1;
        v1 = &netz_47A740[2].field_18;
        do
        {
            if (*((_BYTE *)v1 - 16) == 1)
            {
                netz_42FA00(*v1, 61, 0, 0, 1);
                v0 = (void *)netz_42F9C0(0, 0);
            }
            v1 += 7;
        } while ((int)v1 < (int)&netz_pfn_47A838);
    }
    else
    {
        if (netz_468B50_available_units_denom == 2)
            *(_DWORD *)&netz_47A740[2].str_0[0] = 1;
        v3 = __47CA80_array_idx_and_netz_player_side;
        LOBYTE_HEXRAYS(v3) = netz_47A740[(int)__47CA80_array_idx_and_netz_player_side + 2].field_8;
        if ((_BYTE)v3)
        {
            netz_42FA00(dword_468B54, 62, &netz_47A740[(int)__47CA80_array_idx_and_netz_player_side + 2].field_8, 28, 1);
            netz_42F9C0(0, 0);
        }
    }
    dword_47CB18 = 1;
    dword_47CB1C = 0;
    dword_47CB14 = -1;
}

//----- (0044A160) --------------------------------------------------------
void netz_44A160(char a1, char *a2, int a3)
{
    void *v3; // eax@1
    void *v4; // edi@2
    int *v5; // esi@2
    int v6; // eax@7
    int v7; // [sp-Ch] [bp-14h]@7
    int a3a; // [sp+0h] [bp-8h]@1
    char *a2a; // [sp+7h] [bp-1h]@1

    v3 = netz_47A834;
    a3a = (int)a2;
    LOBYTE_HEXRAYS(a2a) = a1;
    if (netz_47A834)
    {
        v4 = 0;
        v5 = &netz_47A740[2].field_18;
        do
        {
            LOBYTE_HEXRAYS(v3) = *((_BYTE *)v5 - 16);
            if ((_BYTE)v3 && v4 != __47CA80_array_idx_and_netz_player_side)
            {
                LOBYTE_HEXRAYS(a2) = (_BYTE)a2a;
                v3 = (void *)netz_42FA00(*v5, (int)a2, (void *)a3a, a3, 1);
            }
            v5 += 7;
            v4 = (char *)v4 + 1;
        } while ((int)v5 < (int)&netz_pfn_47A838);
    }
}

//----- (0044A220) --------------------------------------------------------
void *netz_44A220(char a1, char *a2, int a3)
{
    void *result; // eax@1
    int v4; // eax@4
    char *v5; // ST00_4@5

    result = netz_47A834;
    if (!netz_47A834)
    {
        v5 = a2;
        LOBYTE_HEXRAYS(a2) = a1;
        result = (void *)netz_42FA00(dword_468B54, (int)a2, v5, a3, 1);
    }
    return result;
}

//----- (0044A2A0) --------------------------------------------------------
void netz_44A2A0(char a1, int a2, int a3)
{
    DWORD(__stdcall *v3)(); // esi@1
    DWORD v4; // ebx@1
    int *v5; // eax@1
    void *v6; // eax@3
    void *v7; // edi@4
    int *v8; // esi@4
    int v9; // eax@9
    int v10; // edx@10
    void *v11; // eax@16
    int v12; // eax@19
    netz_stru6_per_player *v13; // eax@23
    void *v14; // eax@25
    void *v15; // edi@26
    int *v16; // esi@26
    int v17; // eax@31
    int v18; // edx@32
    int v19; // [sp+0h] [bp-18h]@9
    DWORD v20; // [sp+Ch] [bp-Ch]@1
    void *v21; // [sp+10h] [bp-8h]@1
    char v22; // [sp+17h] [bp-1h]@1

    v3 = timeGetTime;
    v21 = (void *)a2;
    v22 = a1;
    v4 = timeGetTime();
    v20 = timeGetTime();
    dword_47CB20 = 1;
    dword_47CB10 = netz_468B50_available_units_denom - 1;
    v5 = (int *)&netz_47A740[3];
    do
    {
        *v5 = 0;
        v5 += 7;
    } while ((int)v5 < (int)&dword_47A83C);
    v6 = netz_47A834;
    if (netz_47A834)
    {
        v7 = 0;
        v8 = &netz_47A740[2].field_18;
        do
        {
            LOBYTE_HEXRAYS(v6) = *((_BYTE *)v8 - 16);
            if ((_BYTE)v6 && v7 != __47CA80_array_idx_and_netz_player_side)
            {
                v10 = (int)v21;
                LOBYTE_HEXRAYS(v10) = v22;
                v6 = (void *)netz_42FA00(*v8, v10, v21, a3, 1);
            }
            v8 += 7;
            v7 = (char *)v7 + 1;
        } while ((int)v8 < (int)&netz_pfn_47A838);
        v3 = timeGetTime;
    }
    while (dword_47CB10 > 0)
    {
        v11 = (void *)(v3() - v20);
        if ((unsigned int)v11 >= 0x9C40)
            break;
        netz_42F9C0(0, 0);
        if (v3() - v4 > 0x1F4)
        {
            dword_47CB10 = netz_468B50_available_units_denom - 1;
            v13 = &netz_47A740[3];
            do
            {
                *(_DWORD *)&v13->str_0[0] = 0;
                ++v13;
            } while ((int)v13 < (int)&dword_47A83C);
            v14 = netz_47A834;
            if (netz_47A834)
            {
                v15 = 0;
                v16 = &netz_47A740[2].field_18;
                do
                {
                    LOBYTE_HEXRAYS(v14) = *((_BYTE *)v16 - 16);
                    if ((_BYTE)v14 && v15 != __47CA80_array_idx_and_netz_player_side)
                    {
                        v18 = (int)v21;
                        LOBYTE_HEXRAYS(v18) = v22;
                        v14 = (void *)netz_42FA00(*v16, v18, v21, a3, 1);
                    }
                    v16 += 7;
                    v15 = (char *)v15 + 1;
                } while ((int)v16 < (int)&netz_pfn_47A838);
                v3 = timeGetTime;
            }
            v4 = v3();
        }
    }
    dword_47CB20 = 0;
}