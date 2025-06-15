#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Utility function to create a new node
struct node* createNode(int data) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Utility function to print spaces
void printSpaces(int count) {
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
}

// Function to print tree in the specific format
void printFormattedTree(struct node* root, int level) {
    if (root == NULL)
        return;

    // Print current level
    if (level == 1) {
        printSpaces(7);
        printf("%d\n", root->data);
    } else if (level == 2) {
        printSpaces(5);
        printf("%d    %d\n", root->left->data, root->right->data);
    } else if (level == 3) {
        printSpaces(3);
        printf("%d   %d", root->left->left->data, root->left->right->data);
        printSpaces(4);
        printf("%d\n", root->right->right->data);
    } else if (level == 4) {
        printSpaces(1);
        printf("%d   %d", root->left->left->left->data, root->left->left->right->data);
        printSpaces(6);
        printf("%d", root->left->right->right->data);
        printSpaces(5);
        printf("%d   %d\n", root->right->right->left->data, root->right->right->right->data);
    }
}

int main() {
    // Manually creating the tree as shown in the example
    struct node *p = createNode(15);
    struct node *p1 = createNode(10);
    struct node *p2 = createNode(20);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(11);
    struct node *p5 = createNode(22);
    struct node *p6 = createNode(1);
    struct node *p7 = createNode(6);
    struct node *p8 = createNode(14);
    struct node *p9 = createNode(21);
    struct node *p10 = createNode(23);

    // Constructing the tree
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p3->left = p6;
    p3->right = p7;
    p4->right = p8;
    p2->right = p5;
    p5->left = p9;
    p5->right = p10;

    // Print each level of the tree in specified format
    printFormattedTree(p, 1); // Level 1
    printf("      /  \\\n");
    printFormattedTree(p, 2); // Level 2
    printf("    /  \\     \\\n");
    printFormattedTree(p, 3); // Level 3
    printf("   / \\    \\    / \\\n");
    printFormattedTree(p, 4); // Level 4

    return 0;
}
