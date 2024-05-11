#include <stdio.h>

// #define TEST_STACK_ARRAY
#define TEST_STACK_LIST
// #define TEST_LIST

#ifdef TEST_LIST

#include "list.h"

void LIST_Print(list_t* p_list) {
    node_t* head = p_list->head;
    if (!head) return;

    do {
        printf("%d ", head->value);
        head = head->next;
    } while (head);
}

int main() {
    list_t int_list;
    LIST_Constructor(&int_list);

    LIST_PushBack(&int_list, 1);
    LIST_PushBack(&int_list, 2);
    LIST_PushBack(&int_list, 3);
    LIST_PopBack(&int_list);
    LIST_PushFront(&int_list, 4);
    LIST_PopFront(&int_list);
    LIST_Print(&int_list);

    LIST_Destructor(&int_list);
}

#endif

#ifdef TEST_STACK_ARRAY

#include "stack_array.h"

void STACK_ARRAY_Print(stack_array_t* p_stack) {
    for (unsigned int i = 0; i < p_stack->size; i++) {
        printf("%d ", p_stack->stack[i]);
    }
}

int main() {
    stack_array_t stack;
    STACK_ARRAY_Constructor(&stack);
    STACK_ARRAY_Push(&stack, 1);
    STACK_ARRAY_Push(&stack, 2);
    STACK_ARRAY_Push(&stack, 3);

    STACK_ARRAY_Print(&stack);

    STACK_ARRAY_Destructor(&stack);
}

#endif

#ifdef TEST_STACK_LIST

#include "stack_list.h"

void STACK_LIST_Print(stack_list_t* p_stack) {
    node_t* element = p_stack->list.head;

    while (element) {
        printf("%d ", element->value);
        element = element->next;
    }
}

int main() {
    stack_list_t stack;
    STACK_LIST_Constructor(&stack);
    STACK_LIST_Push(&stack, 1);
    STACK_LIST_Push(&stack, 2);
    STACK_LIST_Push(&stack, 3);
    STACK_LIST_Pop(&stack);

    STACK_LIST_Print(&stack);

    STACK_LIST_Destructor(&stack);
}

#endif