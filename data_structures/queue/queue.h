#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef PROJECT_C_QUEUE_H
#define PROJECT_C_QUEUE_H

typedef int ElementType;
struct Node {
    ElementType data;
    struct Node* next;
};

struct QNode {
    struct Node* head;
    struct Node* tail;
};
typedef struct QNode *Queue;

// Create new queue
Queue queue_create();
// Returns true if queue is empty
bool is_empty(Queue queue);
// Adds value at end of available storage
void enqueue(Queue queue, ElementType value);
// Returns value of least recently added element and removes it
ElementType dequeue(Queue queue);

#endif //PROJECT_C_QUEUE_H
