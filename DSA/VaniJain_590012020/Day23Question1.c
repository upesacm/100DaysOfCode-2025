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
    if (!newNode) 
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int findKthFromEnd(struct Node* head, int k) 
{
    struct Node *first = head, *second = head;
    for (int i = 0; i < k; i++) {
        if (first == NULL)
            return -1; 
        first = first->next;
    }
    while (first != NULL) 
    {
        first = first->next;
        second = second->next;
    }
    return (second != NULL) ? second->data : -1;
}
int main() 
{
    int n, k, value;
    struct Node *head = NULL, *tail = NULL;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
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
    printf("Enter the value of k: ");
    scanf("%d", &k);
    int result = findKthFromEnd(head, k);
    if (result == -1)
        printf("Output: -1 (k is larger than number of nodes)\n");
    else
        printf("Output: %d (The %d-th node from the end)\n", result, k);
    return 0;
}
