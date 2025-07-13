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
struct Node* deleteMiddle(struct Node* head) 
{
    if (head == NULL || head->next == NULL) 
    {
        free(head);
        return NULL;
    }
    struct Node *slow = head, *fast = head, *prev = NULL;
    while (fast != NULL && fast->next != NULL) 
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    prev->next = slow->next;
    free(slow);
    return head;
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
    printf("Enter number of elements in the list: ");
    scanf("%d", &n);
    if (n <= 0) 
    {
        printf("List is empty.\n");
        return 0;
    }
    printf("Enter %d elements:\n", n);
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
    head = deleteMiddle(head);
    printf("List after deleting the middle node: ");
    printList(head);
    printf("\n");
    return 0;
}
