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
struct Node* insertEnd(struct Node* head, int data) 
{
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}
struct Node* deleteAtPosition(struct Node* head, int pos) 
{
    if (head == NULL || pos <= 0) 
    {
        printf("Invalid position or empty list.\n");
        return head;
    }
    struct Node* temp = head;
    int i = 1;
    while (temp != NULL && i < pos) 
    {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) 
    {
        printf("Position exceeds list length.\n");
        return head;
    }
    if (temp->prev == NULL) 
    {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
    }
    else 
    {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }
    free(temp);
    return head;
}
void printList(struct Node* head) 
{
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() 
{
    struct Node* head = NULL;
    int n, val, pos;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        head = insertEnd(head, val);
    }
    printf("Enter position to delete (starting from 1): ");
    scanf("%d", &pos);
    head = deleteAtPosition(head, pos);
    printList(head);
    return 0;
}
