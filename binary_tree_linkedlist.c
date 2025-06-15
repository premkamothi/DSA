#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node * createNode(int data){
    //n=node
    struct node * n= (struct node *)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
};

void preOrder(struct node * root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);

    }
}

void inOrder(struct node * root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);

    }
}

void postOrder(struct node * root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}

//function for tree is bst or not
int isBST(struct node * root){
    static struct node * prev;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

//function for find the element
struct node * search(struct node * root,int key){
    if(root==NULL){
        return NULL;
    }
    if(key==root->data){
        return root;
    }
    else if(key < root->data){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}

// Function to insert a node in the BST
struct node * insert(struct node *root, int key) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(key);
    }
    if(root->data==key){
        printf("\ncan not insert %d, already in exist",key);
    }
    // Otherwise, recursively insert the node in the correct subtree
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    return root;
}

//function for find node in left subtree
struct node * findMininum(struct node * root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
};

struct node * delete(struct node * root, int value){
    if(root==NULL){
        return NULL;
    }
    if(value<root->data){
        root->left=delete(root->left,value);
    }
    else if(value>root->data){
        root->right=delete(root->right,value);
    }
    else{
        //root has no child
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        //root has one child
        else if(root->left==NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        //root has 2 child
        struct node * temp = findMininum(root->right);  // Find in-order successor
        root->data = temp->data;                        // Replace data with the successor's data
        root->right = delete(root->right, temp->data);
    }
    return root;
};ss

int main()
{
//    //root node
//    struct node * p= (struct node *)malloc(sizeof(struct node));
//    p->data=2;
//    p->left=NULL;
//    p->right=NULL;
//
//    //second node
//    struct node * p1= (struct node *)malloc(sizeof(struct node));
//    p->data=3;
//    p1->left=NULL;
//    p1->right=NULL;
//
//    //third node
//    struct node * p2= (struct node *)malloc(sizeof(struct node));
//    p->data=4;
//    p2->left=NULL;
//    p2->right=NULL;

    struct node * p= createNode(15);
    struct node * p1= createNode(10);
    struct node * p2= createNode(20);
    struct node * p3= createNode(5);
    struct node * p4= createNode(11);
    struct node * p5= createNode(22);
    struct node * p6= createNode(1);
    struct node * p7= createNode(5);
    struct node * p8= createNode(14);
    struct node * p9= createNode(21);
    struct node * p10= createNode(23);


//        15
//       /  \
//     10    20
//    /  \     \
//   5   11    22
//  / \   \     / \
// 1   6   14  21 23

    // Link nodes
    p->left = p1;   // 15 -> 10
    p->right = p2;  // 15 -> 20
    p1->left = p3;  // 10 -> 5
    p1->right = p4; // 10 -> 11
    p3->left = p6;  // 5 -> 1
    p3->right = p7; // 5 -> 6
    p4->right = p8; // 11 -> 14
    p2->right = p5; // 20 -> 22
    p5->left = p9;  // 22 -> 21
    p5->right = p10; // 22 -> 23


    preOrder(p);
    printf("\n");

    postOrder(p);
    printf("\n");

    inOrder(p);
    printf("\n");

    printf("%d",isBST(p));
    printf("\n");

    struct node * n = search(p,10);
    if(n!=NULL){
        printf("found :%d",n->data);
    }
    else{
        printf("element not found");
    }


    insert(p, 10);
    insert(p, 2);
    insert(p, 2);
    insert(p, 5);


    printf("\nInOrder before deletion: ");
    inOrder(p);
    printf("\n");

    // Deleting node with different cases
    p = delete(p, 3); // Deleting node with two children
    printf("InOrder after deleting 3: ");
    inOrder(p);
    printf("\n");

    p = delete(p, 1); // Deleting a leaf node
    printf("InOrder after deleting 1: ");
    inOrder(p);
    printf("\n");

    p = delete(p, 6); // Deleting a node with one child
    printf("InOrder after deleting 6: ");
    inOrder(p);
    printf("\n");



   return 0;

}
