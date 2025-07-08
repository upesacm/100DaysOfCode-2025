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
    if (!newNode) 
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void removeDuplicates(struct Node* head) 
{
    struct Node* current = head;
    while (current != NULL && current->next != NULL) 
    {
        if (current->data == current->next->data) 
        {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp); 
        } else 
        {
            current = current->next;
        }
    }
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
    printf("Enter number of elements in the sorted list: ");
    scanf("%d", &n);
    if (n == 0)
    {
        printf("Empty list.\n");
        return 0;
    }
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (head == NULL)
            head = tail = newNode;
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    removeDuplicates(head);
    printf("List after removing duplicates: ");
    printList(head);
    printf("\n");
    return 0;
}
