#include "bin_tree.h"
#include "bin_tree.c"


int main(int argc, char* argv[]) {
    BinTree root = NULL;
    const int SIZE = 10;
    int *a = malloc(sizeof(int) * SIZE);

    for (int j = 0; j < SIZE; ++j) {
        a[j] = rand() % 10000;
        printf("%d ", a[j]);
    }

    for (int i = 0; i < 10; ++i) {
        root = insert(root, a[i]);
    }

    printf("\n");
    preorder_traversal(root);
    printf("\n");
    inorder_traversal(root);
    printf("\n");
    postorder_traversal(root);
    printf("\n");
    levelorder_traversal(root);

    return EXIT_SUCCESS;
}