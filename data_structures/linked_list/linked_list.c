int size(Linked_List head) {
    int size = 0;

    Linked_List current = head->next;
    while (current != NULL) {
        size++;
        current = current->next;
    }

    return size;
}

bool empty(Linked_List head) {
    return head->next == NULL;
}