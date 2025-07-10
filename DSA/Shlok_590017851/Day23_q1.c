#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int kthFromEnd(struct Node* head, int k) 
{
    struct Node *first = head, *second = head;
    for (int i = 0; i < k; i++) 
    {
        if (first == NULL) return -1; 
        first = first->next;
    }
    while (first != NULL) 
    {
        first = first->next;
        second = second->next;
    }
    return (second != NULL) ? second->data : -1;
}
void appendNode(struct Node** headRef, int data) 
{
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) 
    {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
int main() 
{
    struct Node* head = NULL;
    int values1[] = {1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < 9; i++) 
    {
        appendNode(&head, values1[i]);
    }
    int k1 = 2;
    printf("Output 1: %d\n", kthFromEnd(head, k1));  
    struct Node* head2 = NULL;
    int values2[] = {10, 5, 100, 5};
    for (int i = 0; i < 4; i++) 
    {
        appendNode(&head2, values2[i]);
    }
    int k2 = 5;
    printf("Output 2: %d\n", kthFromEnd(head2, k2));  
    return 0;
}
