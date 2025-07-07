#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node 
{
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) 
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(struct Node** head, int value) 
{
    struct Node* newNode = createNode(value);
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to print all elements of the linked list
void printList(struct Node* head) 
{
    while (head != NULL) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() 
{
    struct Node* head = NULL;
    int n, value;

    printf("Enter number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("Linked List Elements: ");
    printList(head);

    return 0;
}
