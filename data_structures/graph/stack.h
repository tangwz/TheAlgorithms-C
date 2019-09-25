#ifndef PROJECT_C_GRAPH_H
#define PROJECT_C_GRAPH_H

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

#endif //PROJECT_C_GRAPH_H
