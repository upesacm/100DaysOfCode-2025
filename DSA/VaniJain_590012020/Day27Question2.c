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
struct Node* reverseDLL(struct Node* head) 
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
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        head = insertEnd(head, val);
    }
    printf("Original ");
    printList(head);
    head = reverseDLL(head);
    printf("Reversed ");
    printList(head);
    return 0;
}
