#include "src/Coroutine.h"

#include <cstdlib>
#include <iterator>

Coroutine::Coroutine() 
{
    static int _id = 0;

    id = _id++;
    yield_to = nullptr;
    context = nullptr;
    stack = 0;
    next_depricated = nullptr; // next = nullptr;
    debug_handler_name = nullptr;
}

Coroutine::~Coroutine()
{
}
std::list<Coroutine*> coroutine_list;
Coroutine *volatile coroutine_current = nullptr;
int coroutine_current_stack = 0; // weak

//----- (00402910) --------------------------------------------------------
// alloc coroutine list
bool coroutine_list_alloc() 
{
    //add one empty coroutine to list
    Coroutine *c = new Coroutine();
    coroutine_list.push_back(c);
   
    return true;
}

//----- (00402A40) --------------------------------------------------------
// release all coroutine list elements and remove them from list
void coroutine_list_free() 
{
    for (auto coroutine : coroutine_list) {
        coroutine_list_clear(coroutine);
    }
    coroutine_list.clear();
}

//----- (00402A00) --------------------------------------------------------
// release coroutine resource and remove it from list
void coroutine_list_remove(Coroutine *coroutine)
{
    if (coroutine == nullptr) {
        return;
    }

    if (coroutine->context) {
        free(coroutine->context);
    }

    coroutine_list.remove(coroutine);
}

// release coroutine resource
void coroutine_list_clear(Coroutine *coroutine)
{
    if (coroutine == nullptr) {
        return;
    }

    if (coroutine->context) {
        free(coroutine->context);
    }
}

// get first element in coroutine list
Coroutine *coroutine_list_get_head()
{
    if (coroutine_list.empty())
    {
        return nullptr;
    }

    return *coroutine_list.begin();
}

void nullsub() {}
//----- (00402980) --------------------------------------------------------
// create coroutine instance
Coroutine *couroutine_create(void(*function)(), const char *debug_handler_name)
{
    Coroutine *coroutine = new Coroutine();
    if (coroutine == nullptr) {
        return nullptr;
    }
    coroutine_list.push_back(coroutine);

    size_t stack_size = 1048576;
    int *result = (int *)malloc(stack_size);
    if (result == nullptr) {
        return nullptr;
    }

    coroutine->context = result;
    coroutine->debug_handler_name = debug_handler_name;
    int SP = stack_size >> 2;
    coroutine->context[SP - 1] = (int)nullsub;
    coroutine->context[SP - 2] = 0;
    coroutine->context[SP - 3] = (int)function;
    coroutine->context[SP - 4] = (int)&coroutine->context[SP - 4];
    coroutine->stack = (int)&coroutine->context[SP - 7];

    return coroutine;
}

//----- (00402A60) --------------------------------------------------------
__declspec(naked) int coroutine_yield_asm(Coroutine *self) 
{
  __asm {
    push    ebp
    mov     ebp, esp
    push    ebx
    push    esi
    push    edi
    mov     coroutine_current_stack, esp
  }
  coroutine_current->stack = coroutine_current_stack;
  self->yield_to = coroutine_current;
  coroutine_current = self;
  coroutine_current_stack = self->stack;
  __asm {
    mov     esp, coroutine_current_stack
    xor     eax, eax
    pop     edi
    pop     esi
    pop     ebx
    pop     ebp
    retn
  }
}

int Coroutine::resume() 
{
  return coroutine_yield_asm(this);
}

