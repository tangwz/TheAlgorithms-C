#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef PROJECT_C_STACK_H
#define PROJECT_C_STACK_H

typedef int ElementType;
typedef int Position;
struct ANode {
    ElementType *data;
    Position size;
    int capacity;
};
typedef struct ANode *ArrayStack;

ArrayStack array_stack_create(int capacity);
bool array_stack_is_full(ArrayStack stack);
bool array_stack_is_empty(ArrayStack stack);
bool array_stack_push(ArrayStack stack, ElementType x);
ElementType array_stack_pop(ArrayStack stack);
ElementType array_stack_top(ArrayStack stack);

typedef struct LNode *Linked_List;
struct LNode {
    ElementType data;
    Linked_List next;
};
typedef Linked_List Stack;

Stack stack_create();
bool stack_is_empty(Stack stack);
bool stack_push(Stack stack, ElementType x);
ElementType stack_pop(Stack stack);
ElementType stack_top(Stack stack);

#endif //PROJECT_C_STACK_H
