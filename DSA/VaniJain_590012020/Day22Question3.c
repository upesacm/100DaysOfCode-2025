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
    if (newNode == NULL) 
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void printList(struct Node* head) 
{
    struct Node* current = head;
    while (current != NULL) 
    {
        printf("%d ", current->data);
        current = current->next;
    }
}
int main() 
{
    int n, value;
    struct Node *head = NULL, *tail = NULL;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (head == NULL) 
        {
            head = tail = newNode;
        } else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    printf("Linked list elements: ");
    printList(head);
    printf("\n");
    return 0;
}
