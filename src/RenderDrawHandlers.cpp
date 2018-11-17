#include "src/RenderDrawHandlers.h"

#include "src/_unsorted_data.h"



void (*j_drawjob_update_handler_426C40_default_sprite_handler)(Sprite *param, DrawJob *job) = nullptr;
void (*j_drawjob_update_handler_mapd_menu)(Bitmap *param, DrawJob *job) = nullptr;



//----- (00448880) --------------------------------------------------------
void drawjob_update_draw_handler_aircraft(Entity *param, DrawJob *job)
{
    Sprite *v2; // esi@1
    int v3; // eax@1
    char *v4; // ecx@1
    int v5; // eax@1

    v2 = param->sprite;
    v3 = *(_DWORD *)(param->stru60.ptr_8 + 4);
    v4 = (char *)&param->pfn_render_DrawUnitsAndUi;
    job->job_details.x = (v2->x + v3 - _47C380_mapd.mapd_cplc_render_x - 4096) >> 8;
    v5 = *(_DWORD *)(*((_DWORD *)v4 - 138) + 20)
        - (*(_DWORD *)(*((_DWORD *)v4 - 138) + 24) >> 1)
        - _47C380_mapd.mapd_cplc_render_y;
    job->job_details.z_index = 0x400000;
    job->job_details.image = v4;
    job->job_details.y = (v5 - 1024) >> 8;
    job->job_details.params = render_default_stru1;
}


//----- (00448750) --------------------------------------------------------
void drawjob_update_handler_448750_infantry(Entity *a1, DrawJob *job)
{
    Sprite *v2; // eax@1
    char *v3; // ecx@1
    int v4; // esi@1
    int v5; // eax@1

    v2 = a1->sprite;
    v3 = (char *)&a1->pfn_render_DrawUnitsAndUi;
    job->job_details.x = (v2->x - _47C380_mapd.mapd_cplc_render_x - 2048) >> 8;
    v4 = _47C380_mapd.mapd_cplc_render_y;
    v5 = *(_DWORD *)(*((_DWORD *)v3 - 138) + 20);
    job->job_details.z_index = 0x200000;
    job->job_details.image = v3;
    job->job_details.y = (v5 - v4 - 6400) >> 8;
    job->job_details.params = render_default_stru1;
}


//----- (004487B0) --------------------------------------------------------
void drawjob_update_handler_4487B0_vehicles_buildings(Entity *a1, DrawJob *job)
{
    int v2; // esi@1
    int v3; // eax@1
    char *v4; // ecx@1
    int v5; // esi@1
    int v6; // eax@1

    v2 = a1->stru60.ptr_8;
    v3 = a1->sprite->x;
    v4 = (char *)&a1->pfn_render_DrawUnitsAndUi;
    job->job_details.x = (*(_DWORD *)(v2 + 4) + v3 - _47C380_mapd.mapd_cplc_render_x - 4096) >> 8;
    v5 = _47C380_mapd.mapd_cplc_render_y;
    v6 = *(_DWORD *)(*((_DWORD *)v4 - 135) + 8) + *(_DWORD *)(*((_DWORD *)v4 - 138) + 20);
    job->job_details.z_index = 0x200000;
    job->job_details.image = v4;
    job->job_details.y = (v6 - v5 - 1024) >> 8;
    job->job_details.params = render_default_stru1;
}

//----- (004486D0) --------------------------------------------------------
void drawjob_update_handler_4486D0_building(Entity *param, DrawJob *job)
{
    int v2; // eax@1
    int v3; // eax@2

    job->job_details.x = (*(_DWORD *)(param->stru60.ptr_8 + 4) + param->sprite->x - _47C380_mapd.mapd_cplc_render_x - 8448) >> 8;
    v2 = *(_DWORD *)(param->stru60.ptr_8 + 8) + param->sprite->y;
    if (v2 - 3840 >= 0)
        v3 = v2 - _47C380_mapd.mapd_cplc_render_y - 3840;
    else
        v3 = 1024 - _47C380_mapd.mapd_cplc_render_y;
    job->job_details.y = v3 >> 8;
    job->job_details.z_index = 0x200000;
    job->job_details.image = &param->pfn_render_DrawUnitsAndUi;
    job->job_details.params = render_default_stru1;
}

//----- (00448820) --------------------------------------------------------
void drawjob_update_handler_oiltanker(Entity *param, DrawJob *job)
{
    Sprite *v2; // eax@1
    char *v3; // ecx@1
    int v4; // esi@1
    int v5; // eax@1

    v2 = param->sprite;
    v3 = (char *)&param->pfn_render_DrawUnitsAndUi;
    job->job_details.x = (v2->x - _47C380_mapd.mapd_cplc_render_x - 4096) >> 8;
    v4 = _47C380_mapd.mapd_cplc_render_y;
    v5 = *(_DWORD *)(*((_DWORD *)v3 - 138) + 20);
    job->job_details.z_index = 0x200000;
    job->job_details.image = v3;
    job->job_details.y = (v5 - v4 - 6400) >> 8;
    job->job_details.params = render_default_stru1;
}

//----- (00439200) --------------------------------------------------------
void drawjob_update_handler_mapd_menu(Bitmap *a1, DrawJob *a2)
{
    a2->job_details.image = a1->draw_job_scrl;
    a2->job_details.z_index = a1->z_index;
    a2->job_details.x = -(_47C380_mapd.mapd_cplc_render_x >> 8);
    a2->job_details.y = -(_47C380_mapd.mapd_cplc_render_y >> 8);
    a2->job_details.params = render_default_stru1;
}

//----- (00426C40) --------------------------------------------------------
void drawjob_update_handler_426C40_mobd(Sprite *a1, DrawJob *a2)
{
    DataMobdItem_stru0 *v2; // eax@1

    a2->job_details.z_index = a1->z_index;
    v2 = a1->_54_inside_mobd_ptr4;
    if (v2)
    {
        a2->job_details.x = (a1->x >> 8) - (_47C380_mapd.mapd_cplc_render_x >> 8) - v2->x_offset;
        a2->job_details.y = (a1->y >> 8) - (_47C380_mapd.mapd_cplc_render_y >> 8) - a1->_54_inside_mobd_ptr4->y_offset;
        a2->job_details.image = a1->_54_inside_mobd_ptr4->sprt;
        a2->job_details.params = render_default_stru1;
    }
    else
    {
        a2->job_details.image = 0;
        a2->job_details.params = render_default_stru1;
    }
}

//----- (0044C430) --------------------------------------------------------
void drawjob_update_handler_44C430_default_sprite(Sprite *a1, DrawJob *a2)
{
    DataMobdItem_stru0 *v2; // eax@1

    v2 = a1->_54_inside_mobd_ptr4;
    if (v2)
    {
        a2->job_details.x = (a1->x >> 8) - (_47C380_mapd.mapd_cplc_render_x >> 8) - v2->x_offset;
        a2->job_details.y = (a1->y >> 8)
            - (_47C380_mapd.mapd_cplc_render_y >> 8)
            - (a1->z_index >> 9)
            - a1->_54_inside_mobd_ptr4->y_offset;
        a2->job_details.z_index = (a1->z_index + a1->y) >> 8;
        a2->job_details.image = a1->_54_inside_mobd_ptr4->sprt;
        a2->job_details.params = render_default_stru1;
    }
    else
    {
        a2->job_details.image = 0;
        a2->job_details.params = render_default_stru1;
    }
}

//----- (00448580) --------------------------------------------------------
void drawjob_update_handler_448580_entity_aircraft_turret(Sprite *sprite, DrawJob *job)
{
    DataMobdItem_stru0 *v2; // eax@1
    int v3; // eax@2
    int v4; // edi@2

    v2 = sprite->_54_inside_mobd_ptr4;
    if (v2)
    {
        job->job_details.x = (sprite->x >> 8) - (_47C380_mapd.mapd_cplc_render_x >> 8) - v2->x_offset;
        v3 = (sprite->y >> 8) - (sprite->z_index >> 9) - (_47C380_mapd.mapd_cplc_render_y >> 8);
        v4 = sprite->_54_inside_mobd_ptr4->y_offset;
        job->job_details.z_index = 0x200001;
        job->job_details.y = v3 - v4;
        job->job_details.image = sprite->_54_inside_mobd_ptr4->sprt;
        job->job_details.params = render_default_stru1;
    }
    else
    {
        job->job_details.image = 0;
        job->job_details.params = render_default_stru1;
    }
}

//----- (004483E0) --------------------------------------------------------
void drawjob_update_handler_4483E0_ui(Sprite *a1, DrawJob *a2)
{
    DataMobdItem_stru0 *v2; // eax@1

    v2 = a1->_54_inside_mobd_ptr4;
    if (v2)
    {
        a2->job_details.x = (a1->x >> 8) - v2->x_offset;
        a2->job_details.y = (a1->y >> 8) - a1->_54_inside_mobd_ptr4->y_offset;
        a2->job_details.image = a1->_54_inside_mobd_ptr4->sprt;
    }
    else
    {
        a2->job_details.image = 0;
    }
    a2->job_details.z_index = a1->z_index + 0x20000000;
    a2->job_details.params = render_default_stru1;
}

//----- (00448430) --------------------------------------------------------
void drawjob_update_handler_cursors(Sprite *a1, DrawJob *a2)
{
    DataMobdItem_stru0 *v2; // eax@1

    v2 = a1->_54_inside_mobd_ptr4;
    if (v2)
    {
        a2->job_details.x = (a1->x >> 8) - (_47C380_mapd.mapd_cplc_render_x >> 8) - v2->x_offset;
        a2->job_details.y = (a1->y >> 8) - (_47C380_mapd.mapd_cplc_render_y >> 8) - v2->y_offset;
        a2->job_details.image = v2->sprt;
    }
    else
    {
        a2->job_details.image = 0;
    }
    a2->job_details.z_index = a1->z_index + 0x40000000;
    a2->job_details.params = render_default_stru1;
}

//----- (004484A0) --------------------------------------------------------
void drawjob_update_handler_4484A0_explosions(Sprite *a1, DrawJob *a2)
{
    DataMobdItem_stru0 *v2; // eax@1

    v2 = a1->_54_inside_mobd_ptr4;
    if (v2)
    {
        a2->job_details.x = (a1->x >> 8) - (_47C380_mapd.mapd_cplc_render_x >> 8) - v2->x_offset;
        a2->job_details.y = (a1->y >> 8) - (_47C380_mapd.mapd_cplc_render_y >> 8) - a1->_54_inside_mobd_ptr4->y_offset;
        a2->job_details.image = a1->_54_inside_mobd_ptr4->sprt;
    }
    else
    {
        a2->job_details.image = 0;
    }
    a2->job_details.z_index = a1->z_index + 0x10000000;
    a2->job_details.params = render_default_stru1;
}

//----- (00448510) --------------------------------------------------------
void drawjob_update_handler_448510_aircraft(Sprite *sprite, DrawJob *job)
{
    DataMobdItem_stru0 *v2; // eax@1

    v2 = sprite->_54_inside_mobd_ptr4;
    if (v2)
    {
        job->job_details.x = (sprite->x >> 8) - (_47C380_mapd.mapd_cplc_render_x >> 8) - v2->x_offset;
        job->job_details.y = (sprite->y >> 8)
            - (sprite->z_index >> 9)
            - (_47C380_mapd.mapd_cplc_render_y >> 8)
            - sprite->_54_inside_mobd_ptr4->y_offset;
        job->job_details.image = sprite->_54_inside_mobd_ptr4->sprt;
    }
    else
    {
        job->job_details.image = 0;
    }
    job->job_details.z_index = sprite->z_index + 0x200000;
    job->job_details.params = render_default_stru1;
}

//----- (00448600) --------------------------------------------------------
void drawjob_update_handler_448600_oilspot(Sprite *a1, DrawJob *a2)
{
    DataMobdItem_stru0 *v2; // eax@1
    MobdSprtImage *v3; // eax@2

    v2 = a1->_54_inside_mobd_ptr4;
    if (v2)
    {
        a2->job_details.x = (a1->x >> 8) - (_47C380_mapd.mapd_cplc_render_x >> 8) - v2->x_offset;
        a2->job_details.y = (a1->y >> 8)
            - (a1->z_index >> 9)
            - (_47C380_mapd.mapd_cplc_render_y >> 8)
            - a1->_54_inside_mobd_ptr4->y_offset;
        v3 = a1->_54_inside_mobd_ptr4->sprt;
        a2->job_details.z_index = 1;
        a2->job_details.image = v3;
        a2->job_details.params = render_default_stru1;
    }
    else
    {
        a2->job_details.image = 0;
        a2->job_details.z_index = 1;
        a2->job_details.params = render_default_stru1;
    }
}

//----- (00448680) --------------------------------------------------------
void drawjob_update_handler_448680_repair(Sprite *param, DrawJob *job)
{
    if (param->_54_inside_mobd_ptr4)
    {
        job->job_details.x = (param->x - _47C380_mapd.mapd_cplc_render_x) >> 8;
        job->job_details.y = (param->y - _47C380_mapd.mapd_cplc_render_y) >> 8;
        job->job_details.image = param->_54_inside_mobd_ptr4->sprt;
    }
    else
    {
        job->job_details.image = 0;
    }
    job->job_details.z_index = param->z_index + 0x20000000;
    job->job_details.params = render_default_stru1;
}

//----- (0044BDC0) --------------------------------------------------------
void drawjob_update_handler_44BDC0_entity_turret(Sprite *a1, DrawJob *a2)
{
    _DWORD *v2; // eax@1
    int v3; // eax@2
    DataMobdItem_stru0 *v4; // esi@2

    v2 = (int *)a1->param;
    if (v2)
    {
        v3 = v2[2];
        v4 = a1->_54_inside_mobd_ptr4;
        if (v4)
        {
            a2->job_details.x = ((*(_DWORD *)(*(_DWORD *)(v3 + 96) + 4)
                + *(_DWORD *)(*(_DWORD *)(v3 + 92) + 16)
                - _47C380_mapd.mapd_cplc_render_x) >> 8)
                - v4->x_offset;
            a2->job_details.y = ((*(_DWORD *)(*(_DWORD *)(v3 + 96) + 8)
                + *(_DWORD *)(*(_DWORD *)(v3 + 92) + 20)
                - _47C380_mapd.mapd_cplc_render_y) >> 8)
                - a1->_54_inside_mobd_ptr4->y_offset;
            a2->job_details.z_index = ((*(_DWORD *)(*(_DWORD *)(v3 + 92) + 24) + *(_DWORD *)(*(_DWORD *)(v3 + 92) + 20)) >> 8)
                + 1;
            a2->job_details.image = a1->_54_inside_mobd_ptr4->sprt;
            a2->job_details.params = render_default_stru1;
        }
        else
        {
            a2->job_details.image = 0;
            a2->job_details.params = render_default_stru1;
        }
    }
}
