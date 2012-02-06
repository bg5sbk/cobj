#ifndef CO_STACK_H
#define CO_STACK_H

#include "co.h"

#define STACK_BLOCK_SIZE    64

typedef struct _co_stack {
    int top, max;
    void **elements;
} co_stack;

extern bool co_stack_init(co_stack * stack);

extern bool co_stack_push(co_stack * stack, const void *element, int size);

extern bool co_stack_pop(co_stack * stack);

extern bool co_stack_top(const co_stack * stack, void **element);

extern bool co_stack_is_empty(const co_stack * stack);

extern bool co_stack_destory(co_stack * stack);

extern void **co_stack_base(const co_stack * stack);

extern int co_stack_count(const co_stack * stack);

#define CO_STACK_APPLY_TYPE_TOPDOWN 1
#define CO_STACK_APPLY_TYPE_BOTTOMUP 2
extern void co_stack_apply(co_stack * stack, int type, int (*apply_function) (void *element));

#endif
