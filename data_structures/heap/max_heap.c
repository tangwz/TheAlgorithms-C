#include "heap.h"

MaxHeap creat(int MaxSize) {
    MaxHeap H = (MaxHeap)malloc(sizeof(struct HNode));
    H->elements = malloc((MaxSize + 1) * sizeof(ElementType));
    H->size = 0;
    H->capacity = MaxSize;
    /* heap[0] is greater than the value of all possible elements. */
    H->elements[0] = MaxData

    return H;
}

void insert(MaxHeap heap, ElementType value) {
    int i;
    if (is_full(heap)) {
        printf("Cannot insert to the full heap\n");
        exit(EXIT_FAILURE);
    }

    i = ++heap->size; /* Insert in the last position. */
    /* Adjust its position */
    for ( ; heap->elements[i/2] < value; i /= 2)
        heap->elements[i] = heap->elements[i/2];
    heap->elements[i] = value;
}

bool is_empty(MaxHeap heap) {
    return (heap->size == 0);
}

bool is_full(MaxHeap heap) {
    return (heap->size == heap->capacity);
}

ElementType get_max(MaxHeap heap) {
    return heap->elements[1];
}

ElementType extract_max(MaxHeap heap) {
    int parent, child;
    ElementType max, tmp;
    if (is_empty(heap)) {
        printf("heap is empty!\n");
        exit(EXIT_FAILURE);
    }

    /* heap[1] is the maximum element. So we remove heap[1]. Size of the heap is increased.
     * Now heap[1] has to be filled. We put the last element in its place and see if it fits.
     * If it does not fit, take maximum element among both its children and replaces parent with it.
     * Again see if the last element fits in that place. */
    max = heap->elements[1];
    tmp = heap->elements[heap->size--];
    /* parent refers to the index at which we are now. */
    for (parent = 1; parent*2 <= heap->size; parent=child) {
        child = parent*2;
        /* child != heapSize because heap[heapSize+1] does not exist, which means it has only one
         * child */
        if ((child != heap->size) && (heap->elements[child] < heap->elements[child+1]))
            child++;
        /* To check if the last element fits or not.
         * It suffices to check if the tmp is bigger than the maximum element among both the children */
        if (tmp > heap->elements[child]) break;
        else
            heap->elements[parent] = heap->elements[child];
    }
    heap->elements[parent] = tmp;

    return max;
}

void print_data(MaxHeap heap) {
    for (int i = 1; i <= heap->size; ++i) {
        printf("%4d |", heap->elements[i]);
    }
    putchar('\n');
}

