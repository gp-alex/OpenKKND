#include "src/kknd.h"

#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"

#include "src/Script.h"
#include "src/ScriptEvent.h"



ScriptEvent *script_event_list_free_pool;
ScriptEvent *script_event_list;


//----- (004237F0) --------------------------------------------------------
bool script_event_list_alloc()
{
    script_event_list = (ScriptEvent *)malloc(0x3E80u);
    if (script_event_list)
    {
        int v1 = 0;
        do
        {
            script_event_list[v1].next = &script_event_list[v1 + 1];
            ++v1;
        } while (v1 < 999);
        script_event_list[999].next = 0;
        script_event_list_free_pool = script_event_list;
    }
    return script_event_list != nullptr;
}

//----- (00423840) --------------------------------------------------------
bool script_trigger_event(Script *sender, enum SCRIPT_EVENT event, void *param, Script *receiver)
{
    ScriptEvent *result; // eax@1
    void(*event_handler)(Script *, Script *, enum SCRIPT_EVENT, void *); // edi@2

    if (receiver->routine_type == SCRIPT_FUNCTION && (event_handler = receiver->event_handler) != 0)
    {
        event_handler(receiver, sender, event, param);
    }
    else
    {
        result = script_event_list_free_pool;
        if (!script_event_list_free_pool)
            return false;
        script_event_list_free_pool = script_event_list_free_pool->next;
        result->next = 0;
        result->sender = 0;
        result->event = (SCRIPT_EVENT)0;
        result->param = 0;
        result->sender = sender;
        result->event = event;
        result->param = param;
        result->next = receiver->event_list;
        receiver->event_list = result;
    }
    receiver->flags_20 |= SCRIPT_FLAGS_20_EVENT_TRIGGER;
    receiver->flags_24 |= receiver->flags_20;
    return true;
}

//----- (004238C0) --------------------------------------------------------
bool script_trigger_event_group(Script *sender, enum SCRIPT_EVENT event, void *param, enum SCRIPT_TYPE receiver_type)
{
    Script *self; // esi@1
    ScriptEvent *v7; // eax@3
    ScriptEvent *v9; // eax@12

    self = script_execute_list;
    if (receiver_type == SCRIPT_TYPE_ANY)
    {
        if ((Script **)script_execute_list != &script_execute_list)
        {
            do
            {
                v7 = script_event_list_free_pool;
                if (self->routine_type == SCRIPT_FUNCTION && self->event_handler)
                {
                    self->event_handler(self, sender, event, param);
                }
                else
                {
                    if (!script_event_list_free_pool)
                        return 0;
                    script_event_list_free_pool = script_event_list_free_pool->next;
                    v7->next = 0;
                    v7->sender = 0;
                    v7->event = (SCRIPT_EVENT)0;
                    v7->param = 0;
                    v7->sender = sender;
                    v7->param = param;
                    v7->event = event;
                    v7->next = self->event_list;
                    self->event_list = v7;
                }
                self->flags_20 |= SCRIPT_FLAGS_20_EVENT_TRIGGER;
                self->flags_24 |= self->flags_20;
                self = self->next;
            } while ((Script **)self != &script_execute_list);
        }
    }
    else if ((Script **)script_execute_list != &script_execute_list)
    {
        do
        {
            if (self->script_type == receiver_type)
            {
                if (self->routine_type == SCRIPT_FUNCTION && self->event_handler)
                {
                    self->event_handler(self, sender, event, param);
                }
                else
                {
                    v9 = script_event_list_free_pool;
                    if (!script_event_list_free_pool)
                        return 0;
                    script_event_list_free_pool = script_event_list_free_pool->next;
                    v9->next = 0;
                    v9->sender = 0;
                    v9->event = (SCRIPT_EVENT)0;
                    v9->param = 0;
                    v9->sender = sender;
                    v9->param = param;
                    v9->event = event;
                    v9->next = self->event_list;
                    self->event_list = v9;
                }
                self->flags_20 |= SCRIPT_FLAGS_20_EVENT_TRIGGER;
                self->flags_24 |= self->flags_20;
            }
            self = self->next;
        } while ((Script **)self != &script_execute_list);
    }
    return 1;
}

//----- (00423A00) --------------------------------------------------------
ScriptEvent *script_get_next_event(Script *a1)
{
    ScriptEvent *result; // eax@1

    result = a1->event_list;
    if (result)
    {
        a1->event_list = result->next;
        result->next = 0;
    }
    return result;
}

//----- (00423A20) --------------------------------------------------------
void script_discard_event(ScriptEvent *a1)
{
    a1->next = script_event_list_free_pool;
    script_event_list_free_pool = a1;
}

//----- (00423A30) --------------------------------------------------------
void script_discard_all_events(Script *a1)
{
    ScriptEvent *i; // eax@1

    for (i = a1->event_list; i; i = a1->event_list)
    {
        a1->event_list = i->next;
        i->next = script_event_list_free_pool;      // INLINED  423A20  script_discard_event
        script_event_list_free_pool = i;
    }
}

//----- (00423A60) --------------------------------------------------------
void script_event_list_free()
{
    free(script_event_list);
}