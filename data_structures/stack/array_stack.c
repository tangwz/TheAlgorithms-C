#include "stack.h"

ArrayStack array_stack_create(int capacity) {
    ArrayStack stack = (ArrayStack)malloc(sizeof(struct ANode));
    stack->data = (ElementType *)malloc(capacity * sizeof(ElementType));
    if (!stack->data) {
        free(stack);
        return NULL;
    }
    stack->size = -1;
    stack->capacity = capacity;
    return stack;
}

bool array_stack_is_full(ArrayStack stack) {
    return (stack->size == stack->capacity);
}

bool array_stack_is_empty(ArrayStack stack) {
    return (stack->size == -1);
}

bool array_stack_push(ArrayStack stack, ElementType x) {
    if (array_stack_is_full(stack)) {
        printf("Cannot push in a full stack.\n");
        return false;
    }

    stack->data[++(stack->size)] = x;
    return true;
}

ElementType array_stack_pop(ArrayStack stack) {
    if (array_stack_is_empty(stack)) {
        printf("Cannot pop from an empty stack.\n");
        exit(EXIT_FAILURE);
    }

    return stack->data[(stack->size)--];
}

ElementType array_stack_top(ArrayStack stack) {
    if (array_stack_is_empty(stack)) {
        printf("Cannot get data from an empty stack.\n");
        exit(EXIT_FAILURE);
    }

    return stack->data[stack->size];
}
