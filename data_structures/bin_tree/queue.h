#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef PROJECT_C_BIN_TREE_QUEUE_H
#define PROJECT_C_BIN_TREE_QUEUE_H

struct Node {
    void *data;
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
void enqueue(Queue queue, void* value);
// Returns value of least recently added element and removes it
void* dequeue(Queue queue);

#endif //PROJECT_C_BIN_TREE_QUEUE_H
