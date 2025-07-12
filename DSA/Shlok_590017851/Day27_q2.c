#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
struct Node* reverseList(struct Node* head) 
{
    struct Node* temp = NULL;
    struct Node* current = head;

    while (current != NULL) 
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
        head = temp->prev;
    return head;
}
void printList(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL) 
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" <-> ");
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    struct Node* head = createNode(75);
    struct Node* second = createNode(122);
    struct Node* third = createNode(59);
    struct Node* fourth = createNode(196);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    printf("Original List:\n");
    printList(head);

    head = reverseList(head);
    printf("Reversed List:\n");
    printList(head);
    return 0;
}
