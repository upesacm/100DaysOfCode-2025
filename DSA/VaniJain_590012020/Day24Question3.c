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
struct Node* insertEnd(struct Node* head, int data) 
{
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}
struct Node* deleteAtPosition(struct Node* head, int x) 
{
    if (head == NULL || x <= 0) 
    {
        printf("Invalid position or empty list.\n");
        return head;
    }
    if (x == 1) 
    {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* current = head;
    for (int i = 1; current != NULL && i < x - 1; i++) 
    {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) 
    {
        printf("Position out of range.\n");
        return head;
    }
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}
void printList(struct Node* head) 
{
    struct Node* temp = head;
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
    int n, value, pos;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }
    printf("Enter position to delete (1-based): ");
    scanf("%d", &pos);
    printf("Original list: ");
    printList(head);
    head = deleteAtPosition(head, pos);
    printf("Modified list: ");
    printList(head);
    return 0;
}
