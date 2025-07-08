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
struct Node* deleteMiddle(struct Node* head) 
{
    if (head == NULL || head->next == NULL) 
    {
        free(head);
        return NULL;
    }
    struct Node *slow = head, *fast = head;
    struct Node *prev = NULL;

    while (fast != NULL && fast->next != NULL) 
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    if (prev != NULL) 
    {
        prev->next = slow->next;
        free(slow);
    }
    return head;
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
    int values1[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) 
    {
        appendNode(&head1, values1[i]);
    }
    printf("Original List 1: ");
    printList(head1);
    head1 = deleteMiddle(head1);
    printf("After Deleting Middle: ");
    printList(head1);

    struct Node* head2 = NULL;
    int values2[] = {2, 4, 6, 7, 5, 1};
    for (int i = 0; i < 6; i++)
      {
        appendNode(&head2, values2[i]);
    }
    printf("\nOriginal List 2: ");
    printList(head2);
    head2 = deleteMiddle(head2);
    printf("After Deleting Middle: ");
    printList(head2);
    return 0;
}
