#pragma once
#include <list>

/* 290 */
class Coroutine {
 public:
  Coroutine();
  virtual ~Coroutine();

  int resume();

  Coroutine *yield_to;
  int *context;
  int stack;
  Coroutine *next;

  int         id;
  const char *debug_handler_name;
};

//extern Coroutine* coroutine_list_head;
extern std::list<Coroutine*> coroutine_list;
extern Coroutine *volatile coroutine_current;

bool coroutine_list_alloc();
Coroutine *couroutine_create(void(*function)(), const char *debug_handler_name);
void coroutine_list_remove(Coroutine *a1);
void coroutine_list_free();
