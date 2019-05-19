#include "heap.h"

MaxHeap creat(int MaxSize)
{
    /* 创建容量为 MaxSize 的空的最大堆 */
    MaxHeap H = (MaxHeap)malloc(sizeof(struct HNode));
    H->elements = malloc((MaxSize + 1) * sizeof(ElementType));
    H->size = 0;
    H->capacity = MaxSize;
    /* 定义"哨兵"为大于堆中所有可能元素的值，便于以后更快操作 */
    H->elements[0] = MaxData;

    return H;
}

void insert(MaxHeap heap, ElementType value) {
    int i;
    if (is_full(heap)) {
        printf("Cannot insert to the full heap\n");
        exit(EXIT_FAILURE);
    }

    i = ++heap->size;
    heap->elements[i] = value;

    sift_up(heap, heap->size);
}

bool is_full(MaxHeap heap) {
    return (heap->size == heap->capacity);
}

ElementType extract_max(MaxHeap heap) {
    ElementType max = heap->elements[1];
    heap->size--;

    sift_down(heap, 1);
    return max;
}

void sift_up(MaxHeap heap, int i) {
    ElementType tmp;
    for ( ; heap->elements[i/2] < heap->elements[i]; i /= 2) {
        tmp = heap->elements[i];
        heap->elements[i] = heap->elements[i/2];
        heap->elements[i/2] = tmp;
    }
}

void sift_down(MaxHeap heap, int i) {
    ElementType x = heap->elements[heap->size];
    int parent, child;
    for (parent = i; parent*2 < heap->size; parent = child) {
        child = parent * 2;
        if ((child != heap->size) && (heap->elements[child] < heap->elements[child+1]))
            child++;
        if (x >= heap->elements[child]) break;
        else
            heap->elements[parent] = heap->elements[child];
    }
    heap->elements[parent] = x;
}

void print_data(MaxHeap heap) {
    for (int i = 1; i <= heap->size; ++i) {
        printf("%4d |", heap->elements[i]);
    }
    putchar('\n');
}

