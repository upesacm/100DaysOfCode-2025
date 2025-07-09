#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node 
{
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert node at the end
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

// Function to delete N nodes after skipping M nodes
void deleteNAfterM(struct Node* head, int M, int N) 
{
    struct Node* current = head;
    struct Node* temp;

    while (current) 
    {
        // Skip M nodes
        for (int i = 1; i < M && current != NULL; i++) 
        {
            current = current->next;
        }

        // If we've reached the end, break
        if (current == NULL)
            break;

        // Start deletion from next node
        temp = current->next;

        // Delete N nodes
        for (int i = 0; i < N && temp != NULL; i++)
        {
            struct Node* del = temp;
            temp = temp->next;
            free(del);
        }

        // Connect current to the node after the deleted ones
        current->next = temp;

        // Move current to next node for next iteration
        current = temp;
    }
}

// Function to print the linked list
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
    int n, value, M, N;

    printf("Enter the number of nodes in the list: ");
    scanf("%d", &n);

    printf("Enter %d node values:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &value);
        head = insertNode(head, value);
    }

    printf("Enter M (nodes to skip): ");
    scanf("%d", &M);

    printf("Enter N (nodes to delete): ");
    scanf("%d", &N);

    printf("Original Linked List:\n");
    printList(head);

    deleteNAfterM(head, M, N);

    printf("Modified Linked List:\n");
    printList(head);

    return 0;
}
