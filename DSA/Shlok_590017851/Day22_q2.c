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
void removeDuplicates(struct Node* head) 
{
    struct Node* current = head;
    while (current != NULL && current->next != NULL)
      {
        if (current->data == current->next->data)
        {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp); 
        } 
        else
        {
            current = current->next; 
        }
    }
}
void printList(struct Node* head) 
{
    while (head != NULL) 
    {
        printf("%d", head->data);
        if (head->next != NULL) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}
int main() 
{
    struct Node* head1 = NULL;
    int values1[] = {2, 2, 4, 5};
    for (int i = 0; i < 4; i++) 
    {
        appendNode(&head1, values1[i]);
    }
    printf("Original List 1: ");
    printList(head1);
    removeDuplicates(head1);
    printf("After Removing Duplicates: ");
    printList(head1);

    struct Node* head2 = NULL;
    int values2[] = {2, 2, 2, 2, 2};
    for (int i = 0; i < 5; i++) 
    {
        appendNode(&head2, values2[i]);
    }
    printf("\nOriginal List 2: ");
    printList(head2);
    removeDuplicates(head2);
    printf("After Removing Duplicates: ");
    printList(head2);
    return 0;
}
