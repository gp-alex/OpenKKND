#include "stru31.h"


stru31 *stru31_list_477300 = nullptr;
stru31 *stru31_list_477304 = nullptr;
stru31 *stru31_list = nullptr;
stru31 *stru31_list_free_pool = nullptr;


//----- (00401000) --------------------------------------------------------
int stru31_list_alloc()
{
    stru31 *v0; // eax@1
    int v1; // ecx@2
    int result; // eax@4

    v0 = (stru31 *)malloc(0x2D0u);
    stru31_list = v0;
    if (v0)
    {
        stru31_list_free_pool = v0;
        v1 = 0;
        do
        {
            *(char **)((char *)&v0->next + v1) = (char *)v0 + v1 + 12;
            v0 = stru31_list;
            v1 += 12;
        } while (v1 < 708);
        stru31_list[25].param__entity__int = 0;
        stru31_list_477300 = (stru31 *)&stru31_list_477300;
        stru31_list_477304 = (stru31 *)&stru31_list_477300;
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (00401060) --------------------------------------------------------
void stru31_list_free()
{
    free(stru31_list);
}

//----- (00401070) --------------------------------------------------------
void entity_401070_stru31(Entity *a1)
{
    stru31 *v1; // eax@1

    v1 = stru31_list_free_pool;
    if (stru31_list_free_pool)
        stru31_list_free_pool = stru31_list_free_pool->next;
    else
        v1 = 0;
    if (v1)
    {
        v1->param__entity__int = a1;
        v1->next = stru31_list_477300;
        v1->prev = (stru31 *)&stru31_list_477300;
        stru31_list_477300->prev = v1;
        stru31_list_477300 = v1;
    }
}