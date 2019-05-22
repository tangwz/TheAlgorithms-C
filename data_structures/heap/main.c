#include <assert.h>
#include "heap.h"
#include "max_heap.c"

int main(int argc, char* argv[]) {
    MaxHeap h = creat(10);

    insert(h, 4);
    assert(h->size == 1);
    insert(h, 14);
    assert(h->size == 2);
    insert(h, 34);
    assert(h->size == 3);
    insert(h, 15);
    insert(h, 5);
    insert(h, 12);
    insert(h, 46);
    insert(h, 17);
    insert(h, 11);
    insert(h, 17);

    print_data(h);

    assert(get_max(h) == 46);
    assert(extract_max(h) == 46);
    assert(extract_max(h) == 34);
    assert(extract_max(h) == 17);
    assert(extract_max(h) == 17);
    assert(extract_max(h) == 15);
    print_data(h);

    return EXIT_SUCCESS;
}