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
  void *next_depricated; // Coroutine *next;

  int         id;
  const char *debug_handler_name;
};

extern std::list<Coroutine*> coroutine_list;
extern Coroutine *volatile coroutine_current;

bool coroutine_list_alloc();
void coroutine_list_free();
void coroutine_list_remove(Coroutine *a1);
void coroutine_list_clear(Coroutine *coroutine);
Coroutine *coroutine_list_get_head();
Coroutine *couroutine_create(void(*function)(), const char *debug_handler_name);