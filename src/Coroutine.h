#pragma once
#include <list>
#include <memory>

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

//extern Coroutine* coroutine_list_head;
extern std::list<std::shared_ptr<Coroutine>> coroutine_list;
extern Coroutine *volatile coroutine_current;

bool coroutine_list_alloc();
std::shared_ptr<Coroutine> couroutine_create(void(*function)(), const char *debug_handler_name);
void coroutine_list_remove(std::shared_ptr<Coroutine> a1);
void coroutine_list_clear(std::shared_ptr<Coroutine> coroutine);
void coroutine_list_free();
Coroutine *coroutine_list_get_head();
