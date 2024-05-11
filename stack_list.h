#ifndef STACK_LIST_H
#define STACK_LIST_H

#include "list.h"

typedef struct {
    list_t list;
    unsigned int size;
} stack_list_t;

static void STACK_LIST_Constructor(stack_list_t* p_stack);
static void STACK_LIST_Destructor(stack_list_t* p_stack);

static bool STACK_LIST_IsEmpty(stack_list_t* p_stack);

static void STACK_LIST_Push(stack_list_t* p_stack, int value);
static int STACK_LIST_Pop(stack_list_t* p_stack);




inline void STACK_LIST_Constructor(stack_list_t* p_stack) {
    LIST_Constructor(&p_stack->list);
    p_stack->size = 0;
}

inline void STACK_LIST_Destructor(stack_list_t* p_stack) {
    LIST_Destructor(&p_stack->list);
    p_stack->size = 0;
}

inline bool STACK_LIST_IsEmpty(stack_list_t* p_stack) {
    return (p_stack->size == 0);
}

inline void STACK_LIST_Push(stack_list_t* p_stack, int value) {
    LIST_PushBack(&p_stack->list, value);
    p_stack->size++;
}

inline int STACK_LIST_Pop(stack_list_t* p_stack) {
    if (LIST_IsEmpty(&p_stack->list)) return 0;
    
    return LIST_PopBack(&p_stack->list);
}

#endif