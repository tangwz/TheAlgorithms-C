#include "stack.h"

Stack stack_create() {
    Stack stack = (Stack)malloc(sizeof(struct LNode));
    stack->next = NULL;

    return stack;
}

bool stack_is_empty(Stack stack) {
    if (!stack->next)
        return true;
    return false;
}

bool stack_push(Stack stack, ElementType x) {
    Linked_List tmp = (Linked_List)malloc(sizeof(struct LNode));
    tmp->data = x;
    tmp->next = stack->next;
    stack->next = tmp;
    return true;
}

ElementType stack_pop(Stack stack) {
    if (stack_is_empty(stack)) {
        printf("Cannot pop from an empty stack.");
        exit(EXIT_FAILURE);
    }

    Linked_List tmp = stack->next;
    ElementType result = tmp->data;
    stack->next = tmp->next;
    free(tmp);
    return result;
}

ElementType stack_top(Stack stack) {
    if (stack_is_empty(stack)) {
        printf("Cannot pop from an empty stack.");
        exit(EXIT_FAILURE);
    }

    return stack->next->data;
}

