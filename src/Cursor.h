#pragma once

#pragma pack(push, 1)
struct stru209
{
    char type;
    int param;
    int param2;
    int param3;
    char _is_free;
};
/* 421 */
struct task_428940_attach__cursors
{
    task_428940_attach__cursors *next;
    stru209 _stru209;
    char field_12;
    char field_13;
};

/* 422 */
struct task_428940_attach__cursors_2
{
    task_428940_attach__cursors_2 *next;
    task_428940_attach__cursors_2 *prev;
    Script *_8_task;
};

#pragma pack(pop)


void cursor_drag_selection(_428940_local *a1, int x, int y); // idb
void cursor_classify_selected_unit(_428940_local *a1, Entity *entity);


task_428940_attach__cursors *_428940_list_get();
void _428940_list_return(task_428940_attach__cursors *item);

stru209 *_47A660_list_get();
void _428940_list_do_stuff(stru209 *a1);



extern task_428940_attach__cursors *task_428940_attach__cursors_list;
extern task_428940_attach__cursors *task_428940_attach__cursors_list_free_pool;

extern task_428940_attach__cursors _47A714;

extern stru209 _47A660_array[10];

extern stru209 stru_47CAE0; // weak