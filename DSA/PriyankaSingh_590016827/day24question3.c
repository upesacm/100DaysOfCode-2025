#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node 
{
    int data;
    struct Node* next;
};

// Creating a new node
struct Node* createNode(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Inserting a node at the end
struct Node* insertNode(struct Node* head, int value) 
{
    struct Node* newNode = createNode(value);
    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Deleting node at position x (1-based index)
struct Node* deleteAtPosition(struct Node* head, int x) 
{
    if (head == NULL) 
    {
        printf("List is empty.\n");
        return NULL;
    }

    // Deleting the head node
    if (x == 1) 
    {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* current = head;
    for (int i = 1; current != NULL && i < x - 1; i++) 
    {
        current = current->next;
    }

    // If position is invalid
    if (current == NULL || current->next == NULL) 
    {
        printf("Invalid position.\n");
        return head;
    }

    // Deleting the node at position x
    struct Node* nodeToDelete = current->next;
    current->next = nodeToDelete->next;
    free(nodeToDelete);

    return head;
}

// Print the linked list
void printList(struct Node* head) 
{
    struct Node* temp = head;
    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() 
{
    struct Node* head = NULL;
    int n, value, x;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d node values:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &value);
        head = insertNode(head, value);
    }

    printf("Enter the position (x) to delete (1-based index): ");
    scanf("%d", &x);

    printf("Original Linked List:\n");
    printList(head);

    head = deleteAtPosition(head, x);

    printf("Linked List after deletion:\n");
    printList(head);

    return 0;
}
