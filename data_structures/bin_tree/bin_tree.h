#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../queue/queue.h"

#ifndef PROJECT_C_BIN_TREE_H
#define PROJECT_C_BIN_TREE_H

typedef int ElementType;

typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode {
    ElementType data;
    BinTree left;
    BinTree right;
};

BinTree insert(BinTree root, int value);
void preorder_traversal(BinTree root);
void inorder_traversal(BinTree root);
void postorder_traversal(BinTree root);
void levelorder_traversal(BinTree root);

#endif //PROJECT_C_BIN_TREE_H
