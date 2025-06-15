#include <stdio.h>
#include <stdlib.h>

// Define the structure for the node
struct node
{
    int data;
    struct node* next;
};

// Define the structure for the header node
struct headerNode
{
    int size;  // To store the size of the linked list
    struct node* head;  // Pointer to the first node of the list
};

// Function to display linked list elements
void linkedListT(struct headerNode* header)
{
    struct node* ptr = header->head;
    while (ptr != NULL)
    {
        printf("element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Function to insert a new node at the beginning of the list
struct headerNode* insertAtBegin(struct headerNode* header, int data)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->next = header->head;
    ptr->data = data;
    header->head = ptr;
    header->size++;  // Increment the size
    return header;
}

// Function to insert a new node at the end of the list
struct headerNode* insertAtEnd(struct headerNode* header, int data)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = header->head;

    ptr->data = data;
    ptr->next = NULL;

    if (p == NULL)    // If the list is empty
    {
        header->head = ptr;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
    }
    header->size++;  // Increment the size
    return header;
}

// Function to insert a new node at a specific index
struct headerNode* insertAtIndex(struct headerNode* header, int index, int data)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = header->head;
    int i = 0;

    if (index == 0)    // If inserting at the beginning
    {
        return insertAtBegin(header, data);
    }

    while (p != NULL && i < index - 1)
    {
        p = p->next;
        i++;
    }

    if (p == NULL)
    {
        printf("Index out of bounds\n");
        free(ptr);
        return header;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    header->size++;  // Increment the size
    return header;
}

// Function to delete a node at a specific index
struct headerNode* deleteAtIndex(struct headerNode* header, int index)
{
    if (header->head == NULL)
    {
        printf("List is empty\n");
        return header;
    }

    struct node* p = header->head;
    struct node* q = NULL;

    if (index == 0)    // If deleting the first node
    {
        header->head = p->next;
        free(p);
        header->size--;  // Decrement the size
        return header;
    }

    for (int i = 0; i < index && p != NULL; i++)
    {
        q = p;
        p = p->next;
    }

    if (p == NULL)
    {
        printf("Index out of bounds\n");
        return header;
    }

    q->next = p->next;
    free(p);
    header->size--;  // Decrement the size
    return header;
}

// Function to delete the last node
struct headerNode* deleteTheLastNode(struct headerNode* header)
{
    if (header->head == NULL)
    {
        printf("List is empty\n");
        return header;
    }

    struct node* p = header->head;
    struct node* q = NULL;

    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }

    if (q == NULL)    // If there is only one node
    {
        header->head = NULL;
    }
    else
    {
        q->next = NULL;
    }
    free(p);
    header->size--;  // Decrement the size
    return header;
}

// Function to delete a node by its value
struct headerNode* deleteGivenValue(struct headerNode* header, int value)
{
    struct node* p = header->head;
    struct node* q = NULL;

    while (p != NULL && p->data != value)
    {
        q = p;
        p = p->next;
    }

    if (p == NULL)
    {
        printf("Value not found in the list\n");
        return header;
    }

    if (q == NULL)    // If the node to delete is the head
    {
        header->head = p->next;
    }
    else
    {
        q->next = p->next;
    }

    free(p);
    header->size--;  // Decrement the size
    return header;
}

// Function to initialize the header node
struct headerNode* createHeaderNode()
{
    struct headerNode* header = (struct headerNode*)malloc(sizeof(struct headerNode));
    header->size = 0;
    header->head = NULL;
    return header;
}

// Main function
int main()
{
    // Create the header node
    struct headerNode* header = createHeaderNode();

    // Insert nodes
    header = insertAtBegin(header, 7);
    header = insertAtEnd(header, 45);
    header = insertAtEnd(header, 66);

    // Display the linked list
    printf("Insertion\n\n");
    linkedListT(header);
    printf("Size of linked list: %d\n", header->size);
    printf("\n");

    // Insert more nodes
    header = insertAtBegin(header, 99);
    header = insertAtIndex(header, 2, 76);
    header = insertAtEnd(header, 1000);

    // Display the linked list again
    linkedListT(header);
    printf("Size of linked list: %d\n", header->size);
    printf("\n");

    // Deletion operations
    printf("\nDeletion\n\n");
    header = deleteAtIndex(header, 0);
    linkedListT(header);
    printf("Size of linked list: %d\n", header->size);
    printf("\n");

    header = deleteAtIndex(header, 1);
    linkedListT(header);
    printf("Size of linked list: %d\n", header->size);
    printf("\n");

    header = deleteTheLastNode(header);
    linkedListT(header);
    printf("Size of linked list: %d\n", header->size);
    printf("\n");

    header = deleteGivenValue(header, 45);
    linkedListT(header);
    printf("Size of linked list: %d\n", header->size);
    printf("\n");

    // Free the header
    free(header);

    return 0;
}
