#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef PROJECT_C_LINKED_LIST_H
#define PROJECT_C_LINKED_LIST_H

typedef int ElementType;

typedef struct Node *Linked_List;
struct Node {
    ElementType data;
    Linked_List next;
};

// Create a new linked list.
Linked_List list_init();
// Frees memory for given linked list.
void list_free(Linked_List list);
// Returns number of data elements in list.
int list_size(Linked_List list);
// Returns true if list is empty
bool list_empty(Linked_List list);
// Adds the given value to the front of the list.
void list_push_front(Linked_List list, ElementType value);
// Adds the given value to the back of the list.
void list_push_back(Linked_List list, ElementType value);
// Return the value of the front of the list.
ElementType list_front(Linked_List list);
// Return the value of the back of the list.
ElementType list_back(Linked_List list);
// Removes the item from front and return it.
ElementType list_pop_front(Linked_List list);
// Removes the item from back and Return it.
ElementType list_pop_back(Linked_List list);
// find the given value in the list.
int list_find(Linked_List list, ElementType value);
// Return the value of nth item.
ElementType list_value_at(Linked_List list, int index);
// Removes node at given index
void list_erase(Linked_List list, int index);
// Reverse the values stored in the list.
void list_reverse(Linked_List list);
// Prints the elements in the list for debugging purposes.
void list_print(Linked_List list);

#endif //PROJECT_C_LINKED_LIST_H
