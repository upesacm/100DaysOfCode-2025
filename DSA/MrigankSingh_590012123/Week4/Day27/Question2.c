#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) 
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int data) 
{
    Node* newNode = createNode(data);
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

Node* reverseList(Node* head) 
{
    Node* current = head;
    Node* temp = NULL;
    
    while (current != NULL) 
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    if (temp != NULL) 
    {
        head = temp->prev;
    }
    return head;
}

void printList(Node* head) 
{
    Node* temp = head;
    while (temp != NULL) 
    {
        printf("%d", temp->data);
        if (temp->next != NULL) 
        {
            printf(" <-> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

void freeList(Node* head) 
{
    Node* temp;
    while (head != NULL) 
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() 
{
    int size, data;
    Node* head = NULL;

    printf("Enter the size of the linked list (must be > 0): ");
    scanf("%d", &size);
    if (size <= 0) 
    {
        fprintf(stderr, "Invalid size. Size must be greater than 0.\n");
        return EXIT_FAILURE;
    }

    printf("Enter the elements of the linked list: ");
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    printf("Original list: ");
    printList(head);

    head = reverseList(head);

    printf("Reversed list: ");
    printList(head);

    freeList(head);

    return EXIT_SUCCESS;
}