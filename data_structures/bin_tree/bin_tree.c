Position insert(Position root, int value) {
    if (!root) {
        root = malloc(sizeof(struct TreeNode));
        root->data = value;
        root->left = NULL;
        root->right = NULL;

        return root;
    }

    Position node = (Position)malloc(sizeof(struct TreeNode));
    node->data = value;
    if (value < root->data) {
        node->left = root->left;
        node->right = root;
        root->left = NULL;
    } else {
        node->right = root->right;
        node->left = root;
        root->right = NULL;
    }

    return node;
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


void levelorder_traversal(BinTree root) {
    Queue queue = queue_create();

    enqueue(queue, root);
    while (!is_empty(queue)) {
        Position node = (Position)dequeue(queue);
        printf("%d ", node->data);
        if (node->left) {
            enqueue(queue, node->left);
        }
        if (node->right) {
            enqueue(queue, node->right);
        }
    }
}