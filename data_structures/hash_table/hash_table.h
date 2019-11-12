#ifndef PROJECT_C_HASH_H
#define PROJECT_C_HASH_H

#include <stdlib.h>
#include <assert.h>

#define HASH_OK 0
#define HASH_ERR 1

typedef int ElementType;
typedef struct Node {
    ElementType key;
    ElementType val;
} Node;

typedef struct HashTable {
    Node** table;
    int size;
} HashTable;

HashTable* hashCreate(const int size);
void hashDestroy(HashTable* ht);
int hash(const int key, const int n);
Node* hashGet(HashTable *ht, const int key);
int hashInsert(HashTable *ht, const int key, const int value);
Node *hashDelete(HashTable *ht, const int key);

#endif //PROJECT_C_HASH_H
