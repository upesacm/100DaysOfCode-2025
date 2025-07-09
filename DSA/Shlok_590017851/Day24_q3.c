#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void printList(struct Node* head) 
{
    while (head != NULL)
      {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf(" -> NULL\n");
}
struct Node* deleteNode(struct Node* head, int x) 
{
    if (head == NULL || x <= 0)
        return head;
    if (x == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* current = head;
    for (int i = 1; i < x - 1 && current != NULL; i++)
        current = current->next;
    if (current == NULL || current->next == NULL)
        return head;

    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}
int main() 
{
    struct Node* head = createNode(1);
    head->next = createNode(5);
    head->next->next = createNode(2);
    head->next->next->next = createNode(9);

    int x = 2;
    printf("Original List:\n");
    printList(head);

    head = deleteNode(head, x);
    printf("Modified List after deleting node at position %d:\n", x);
    printList(head);
    return 0;
}
