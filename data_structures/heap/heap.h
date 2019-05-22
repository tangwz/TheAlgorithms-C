#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#ifndef PROJECT_C_HEAP_H
#define PROJECT_C_HEAP_H

typedef int ElementType;
#define MaxData INT_MAX;

typedef struct HNode *Heap;
struct HNode {
    ElementType *elements;
    int size;
    int capacity;
};
typedef Heap MaxHeap;

// Insert the given value into the heap.
void insert(MaxHeap heap, ElementType value);
// Returns the maximum item of a max-heap.
ElementType get_max(MaxHeap heap);
// Returns the node of maximum value from a max heap after removing it from the heap.
ElementType extract_max(MaxHeap heap);

//  return true if the heap is empty, false otherwise.
bool is_empty(MaxHeap heap);
// Returns true if heap is full.
bool is_full(MaxHeap heap);

// Output the elements of the data in array.
void print_data(MaxHeap heap);

#endif //PROJECT_C_HEAP_H
