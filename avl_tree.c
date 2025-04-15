#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
    int height;
};

int max(int a, int b) {
    return a > b ? a : b;
}

int getHeight(struct node *n) {
    if (n == NULL) {
        return 0;
    }
    return n->height;
}

struct node *createNode(int data) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    n->height = 1; // New node has height 1
    return n;
}

int getBalanceFactor(struct node *n) {
    if (n == NULL) {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

void preOrder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Right Rotation
struct node *rightRotation(struct node *y) {
    struct node *x = y->left;
    struct node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // Return new root
    return x;
}

// Left Rotation
struct node *leftRotation(struct node *x) {
    struct node *y = x->right;
    struct node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // Return new root
    return y;
}

// Insert a node
struct node *insert(struct node *root, int key) {
    // 1. Perform normal BST insertion
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    } else {
        // Duplicate keys are not allowed in AVL tree
        return root;
    }

    // 2. Update the height of this ancestor node
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // 3. Get the balance factor of this ancestor node
    int balance = getBalanceFactor(root);

    // 4. If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && key < root->left->data) {
        return rightRotation(root);
    }

    // Right Right Case
    if (balance < -1 && key > root->right->data) {
        return leftRotation(root);
    }

    // Left Right Case
    if (balance > 1 && key > root->left->data) {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    // Right Left Case
    if (balance < -1 && key < root->right->data) {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

int main() {
    struct node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 8);
    root = insert(root, 9);
    root = insert(root, 10);

    printf("PreOrder traversal of the constructed AVL tree: \n");
    preOrder(root);

    return 0;
}
