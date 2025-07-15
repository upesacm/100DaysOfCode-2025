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
struct Node* removeEveryKthNode(struct Node* head, int k) 
{
    if (head == NULL || k <= 0)
        return head;
    if (k == 1) 
    {
        struct Node* temp;
        while (head != NULL) 
        {
            temp = head;
            head = head->next;
            free(temp);
        }
        return NULL;
    }
    struct Node* current = head;
    struct Node* prev = NULL;
    int count = 1;
    while (current != NULL) 
    {
        if (count % k == 0)
        {
            prev->next = current->next;
            free(current);
            current = prev->next;
        } else 
        {
            prev = current;
            current = current->next;
        }
        count++;
    }
    return head;
}
void printList(struct Node* head) 
{
    printf("Linked List: ");
    while (head != NULL) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
int main() 
{
    struct Node* head = NULL;
    int n, val, k;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        head = insertEnd(head, val);
    }
    printf("Enter value of k (remove every k-th node): ");
    scanf("%d", &k);
    head = removeEveryKthNode(head, k);
    printList(head);
    return 0;
}
