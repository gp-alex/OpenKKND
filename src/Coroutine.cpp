#include "src/Coroutine.h"

#include <cstdlib>
#include <list>

Coroutine::Coroutine() {
  static int _id = 0;

  id = _id++;
  yield_to = nullptr;
  context = nullptr;
  stack = 0;
  // next = nullptr;
  debug_handler_name = nullptr;
}

Coroutine::~Coroutine() {
}


//std::list<Coroutine*> coroutine_list_next;
// Coroutine* coroutine_list_head;
std::list<Coroutine*> coroutine_list;
Coroutine *volatile coroutine_current = nullptr;
int coroutine_current_stack = 0; // weak

//----- (00402910) --------------------------------------------------------
bool coroutine_list_alloc() {

    // 
    //coroutine_list = new Coroutine[2000];
    //for (int i = 0; i < 2000; ++i) {
    //  coroutine_list[i].next = &coroutine_list[i + 1];
    //}
    //coroutine_list[1999].next = 0;
    //coroutine_list_head = coroutine_list;
    //coroutine_list_next = coroutine_list + 1;

    for (int i = 0; i < 2000; i++) {
        Coroutine *c = new Coroutine();
        coroutine_list.push_front(c);
    }
    return true;
}

//----- (00402A40) --------------------------------------------------------
void coroutine_list_free() {
    //delete[] coroutine_list;
    //coroutine_list = nullptr;
    //coroutine_list_next = nullptr;

    for (auto coroutine : coroutine_list) {
        coroutine_list_remove(coroutine);
    }
    coroutine_list.clear();
}

void nullsub() {}

//----- (00402980) --------------------------------------------------------
Coroutine *couroutine_create(void(*function)(), const char *debug_handler_name) {
    //if (coroutine_list_next == nullptr) {
    //return nullptr;
    //}

    size_t stack_size = 1048576;
    int *result = (int *)malloc(stack_size);
    if (result == nullptr) {
        return nullptr;
    }
    Coroutine *coroutine = new Coroutine();
    
    /* Coroutine *coroutine = coroutine_list_next;
    coroutine_list_next = coroutine_list_next->next;*/

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

//----- (00402A00) --------------------------------------------------------
void coroutine_list_remove(Coroutine *coroutine) {
    //if (coroutine == nullptr) {
    //  return;
    //}

    if (coroutine->context) {
        free(coroutine->context);
    }

    //coroutine->next = coroutine_list_next;
    //coroutine_list_next = coroutine;

    coroutine_list.remove(coroutine);
}

//----- (00402A60) --------------------------------------------------------
__declspec(naked) int coroutine_yield_asm(Coroutine *self) {
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

int Coroutine::resume() {
  return coroutine_yield_asm(this);
}

