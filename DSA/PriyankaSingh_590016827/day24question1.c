#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node 
{
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at the end
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

// Function to reverse the linked list
struct Node* reverseList(struct Node* head) 
{
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) 
    {
        next = current->next;   // store next node
        current->next = prev;   // reverse current node's pointer
        prev = current;         // move prev to current
        current = next;         // move current to next node
    }
    return prev; // New head of the reversed list
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
    int n, value;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &value);
        head = insertNode(head, value);
    }

    printf("Original Linked List:\n");
    printList(head);

    head = reverseList(head);

    printf("Reversed Linked List:\n");
    printList(head);

    return 0;
}
