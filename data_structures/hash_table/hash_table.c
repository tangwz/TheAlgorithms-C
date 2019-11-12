HashTable* hashCreate(const int size) {
    HashTable* ht = malloc(sizeof(HashTable));
    assert(ht != NULL);
    ht->table = malloc(sizeof(Node) * size);
    assert(ht->table != NULL);

    for (int i = 0; i < size; i++) ht->table[i] = NULL;
    ht->size = size;
    return ht;
}

void hashDestroy(HashTable* ht) {
    for (int i = 0; i < ht->size; ++i) {
        if (ht->table[i]) {
            free(ht->table[i]);
        }
    }
    free(ht->table);
    free(ht);
}

int hash(const int key, const int n) {
    return key % n;
}

Node* hashGet(HashTable *ht, const int key) {
    int index = hash(key, ht->size);
    int original_index = index;

    while (ht->table[index] != NULL) {
        if (ht->table[index]->key == key) {
            return ht->table[index];
        }

        index = (index + 1) % ht->size;
        if (index == original_index) {
            return NULL;
        }
    }
    return NULL;
}

int hashInsert(HashTable *ht, const int key, const int value) {
    int index = hash(key, ht->size);
    int original_index = index;
    int found = 0;
    while (ht->table[index] != NULL) {
        if (ht->table[index]->key == key) {
            found = 1;
            break;
        }

        index = (index + 1) % ht->size;
        if (index == original_index) {
            return HASH_ERR;
        }
    }

    if (found > 0) {
        ht->table[index]->val = value;
        return HASH_OK;
    }

    if (ht->table[index] == NULL) {
        ht->table[index] = malloc(sizeof(Node));
    }

    ht->table[index]->key = key;
    ht->table[index]->val = value;
    return HASH_OK;
}

Node *hashDelete(HashTable *ht, const int key) {
    int index = hash(key, ht->size);
    int original_index = index;

    Node *res = NULL;
    while (ht->table[index] != NULL) {
        if (ht->table[index]->key == key) {
            res = ht->table[index];
            ht->table[index] = NULL;
            break;
        }

        index = (index + 1) % ht->size;
        if (index == original_index) {
            return NULL;
        }
    }
    return res;
}

