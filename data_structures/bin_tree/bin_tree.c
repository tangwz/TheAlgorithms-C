BinTree insert(BinTree root, int value) {
    if (!root) {
        root = malloc(sizeof(BinTree));
        root->data = value;
        root->left = NULL;
        root->right = NULL;
    } else if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

void preorder_traversal(BinTree root) {
    if (root) {
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void inorder_traversal(BinTree root) {
    if (root) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

void postorder_traversal(BinTree root) {
    if (root) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}