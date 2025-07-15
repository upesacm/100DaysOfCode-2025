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
struct Node* deleteNode(struct Node* head, int x) 
{
    if (head == NULL || x <= 0)
        return head;

    struct Node* temp = head;

    if (x == 1)
    {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return head;
    }
    for (int i = 1; temp != NULL && i < x; i++) 
    {
        temp = temp->next;
    }
    if (temp == NULL)
        return head;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    return head;
}
void printList(struct Node* head) 
{
    struct Node* temp = head;
    while (temp != NULL)
      {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" <--> ");
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    struct Node* head = createNode(1);
    struct Node* second = createNode(5);
    struct Node* third = createNode(2);
    struct Node* fourth = createNode(9);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    printf("Original List:\n");
    printList(head);

    int x = 1; 
    head = deleteNode(head, x);
    printf("After deleting node at position %d:\n", x);
    printList(head);
    return 0;
}
