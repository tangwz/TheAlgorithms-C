Linked_List list_init() {
    Linked_List L;

    L = (Linked_List)malloc(sizeof(struct Node));
    L->next = NULL;

    return L;
}

void list_free(Linked_List list) {
    Linked_List current = list->next;
    Linked_List next;
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }

    free(list);
}

int list_size(Linked_List list) {
    int size = 0;

    Linked_List current = list->next;
    while (current) {
        size++;
        current = current->next;
    }

    return size;
}

bool list_empty(Linked_List list) {
    return list->next == NULL;
}

void list_push_front(Linked_List list, ElementType value) {
    Linked_List node = (Linked_List)malloc(sizeof(struct Node));
    node->data = value;
    node->next = list->next;
    list->next = node;
}

void list_push_back(Linked_List list, ElementType value) {
    Linked_List current = list;
    while (current->next) {
        current = current->next;
    }

    Linked_List node = (Linked_List)malloc(sizeof(struct Node));
    node->data = value;
    current->next = node;
    node->next = NULL;
}

ElementType list_front(Linked_List list) {
    if (list_empty(list)) {
        printf("Cannot get front of empty list\n");
        exit(EXIT_FAILURE);
    }

    return list->next->data;
}

ElementType list_back(Linked_List list) {
    if (list_empty(list)) {
        printf("Cannot get back of empty list\n");
        exit(EXIT_FAILURE);
    }

    Linked_List current = list->next;
    while (current->next) {
        current = current->next;
    }
    return current->data;
}

ElementType list_pop_front(Linked_List list) {
    if (list_empty(list)) {
        printf("Cannot pop front of empty list\n");
        exit(EXIT_FAILURE);
    }

    Linked_List tmp = list->next;
    list->next = tmp->next;
    ElementType data = tmp->data;
    free(tmp);
    return data;
}

ElementType list_pop_back(Linked_List list) {
    if (list_empty(list)) {
        printf("Cannot pop back of empty list\n");
        exit(EXIT_FAILURE);
    }

    Linked_List current = list;
    while (current->next->next) {
        current = current->next;
    }

    Linked_List tmp = current->next;
    current->next = tmp->next;
    ElementType data = tmp->data;
    free(tmp);
    return data;
}

int list_find(Linked_List list, ElementType value) {
    Linked_List current = list->next;
    int n = 0;
    while (current->data != value) {
        ++n;
        current = current->next;
    }

    return n;
}

ElementType list_value_at(Linked_List list, int index) {
    Linked_List current = list->next;

    int n = 0;
    while (index > n && current) {
        ++n;
        current = current->next;
    }

    if (n < index || current == NULL) {
        printf("Index out of bounds\n");
        exit(EXIT_FAILURE);
    }

    return current->data;
}

void list_erase(Linked_List list, int index) {
    if (list_empty(list)) {
        printf("Cannot erase empty list\n");
        exit(EXIT_FAILURE);
    }

    Linked_List current = list->next;
    Linked_List last = list->next;

    int n = 0;
    while (index > n && current) {
        ++n;
        last = current;
        current = current->next;
    }

    if (n < index) {
        printf("Index out of bounds\n");
        exit(EXIT_FAILURE);
    }

    if (n == 0) {
        list->next = current->next;
    } else {
        last->next = current->next;
    }

    free(current);
}

void list_reverse(Linked_List list) {
    Linked_List prev = NULL;
    Linked_List current = list->next;
    Linked_List next = NULL;

    while (current) {
        next = current->next;
        current->next = prev;
        prev= current;
        current = next;
    }

    list->next = prev;
}

void list_print(Linked_List list) {
    Linked_List current = list->next;

    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n\n");
}