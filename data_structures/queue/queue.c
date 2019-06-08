#include "queue.h"
#include "../linked_list/linked_list.h"

Queue queue_create() {
    Queue queue = (Queue)malloc(sizeof(struct Node));
    queue->head = NULL;
    queue->tail = NULL;

    return queue;
}

bool is_empty(Queue queue) {
    return queue->head == NULL;
}

void enqueue(Queue queue, ElementType value) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;

    if (queue->tail) {
        queue->tail->next = node;
    }

    queue->tail = node;

    if(!queue->head) {
        queue->head = node;
    }
}

ElementType dequeue(Queue queue) {
    if (is_empty(queue)) {
        printf("Unable to dequeue. Queue is empty.\n");
        exit(EXIT_FAILURE);
    }

    struct Node *tmp = queue->head;
    if (queue->head == queue->tail) {
        queue->tail = NULL;
    }
    queue->head = queue->head->next;
    ElementType value = tmp->data;
    free(tmp);

    return value;
}