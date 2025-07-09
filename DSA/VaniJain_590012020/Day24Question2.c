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
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}
void skipMdeleteN(struct Node* head, int m, int n) {
    struct Node* current = head;
    struct Node* temp;

    while (current) 
    {
        for (int i = 1; i < m && current != NULL; i++) 
        {
            current = current->next;
        }
        if (current == NULL)
            return;
        temp = current->next;
        for (int i = 0; i < n && temp != NULL; i++) 
        {
            struct Node* del = temp;
            temp = temp->next;
            free(del);
        }
        current->next = temp;
        current = temp;
    }
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
    int n, value, m, k;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }
    printf("Enter number of nodes to skip (m): ");
    scanf("%d", &m);
    printf("Enter number of nodes to delete (n): ");
    scanf("%d", &k);
    printf("Original list: ");
    printList(head);
    skipMdeleteN(head, m, k);
    printf("Modified list: ");
    printList(head);
    return 0;
}
