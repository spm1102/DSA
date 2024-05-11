#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stdbool.h>

#define STACK_ARRAY_MAX_SIZE        50

typedef struct {
    int stack[STACK_ARRAY_MAX_SIZE];
    unsigned int peak;
    unsigned int size;
}  stack_array_t;

static void STACK_ARRAY_Constructor(stack_array_t* p_stack);
static void STACK_ARRAY_Destructor(stack_array_t* p_stack);

static bool STACK_ARRAY_IsEmpty(stack_array_t* p_stack);
static bool STACK_ARRAY_IsFull(stack_array_t* p_stack);

static void STACK_ARRAY_Push(stack_array_t* p_stack, int value);
static int STACK_ARRAY_Pop(stack_array_t* p_stack);




inline void STACK_ARRAY_Constructor(stack_array_t* p_stack) {
    p_stack->peak = 0;
    p_stack->size = 0;
}

inline void STACK_ARRAY_Destructor(stack_array_t* p_stack) {
    p_stack->peak = 0;
    p_stack->size = 0;
}

inline bool STACK_ARRAY_IsEmpty(stack_array_t* p_stack) {
    return (p_stack->size == 0);
}

inline bool STACK_ARRAY_IsFull(stack_array_t* p_stack) {
    return (p_stack->size == STACK_ARRAY_MAX_SIZE);
}

inline void STACK_ARRAY_Push(stack_array_t* p_stack, int value) {
    if (STACK_ARRAY_IsFull(p_stack)) return;

    p_stack->stack[p_stack->peak++] = value;
    p_stack->size++;
}

inline int STACK_ARRAY_Pop(stack_array_t* p_stack) {
    if (STACK_ARRAY_IsEmpty(p_stack)) return 0;

    p_stack->size--;
    return p_stack->stack[--p_stack->peak];
}

#endif