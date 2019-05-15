#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef PROJECT_C_LINKED_LIST_H
#define PROJECT_C_LINKED_LIST_H

typedef int ElementType;

typedef struct Node *Linked_List;
struct Node {
    ElementType data;
    Linked_List next;
};

#endif //PROJECT_C_LINKED_LIST_H
