#include "hash_table.h"
#include "hash_table.c"

#include <stdio.h>


int main() {
    HashTable *ht = hashCreate(100);
    assert(hashGet(ht, 5) == NULL);
    hashInsert(ht, 5, 50);
    Node* x = hashGet(ht, 5);
    assert(x != NULL);
    printf("%d\n", x->val);

    hashInsert(ht, 105, 1050);
    Node* x1 = hashGet(ht, 105);
    assert(x1 != NULL);
    printf("%d\n", x1->val);

    hashDelete(ht, 5);
    assert(hashGet(ht, 5) == NULL);
    hashDestroy(ht);
}
