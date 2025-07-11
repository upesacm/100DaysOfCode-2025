#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* newNode(int data) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
int countNodes(struct Node* head)
{
    int count = 0;
    while (head) 
    {
        count++;
        head = head->next;
    }
    return count;
}
struct Node* swapKthNode(struct Node* head, int k)
{
    int n = countNodes(head);
    if (k > n) return head;

    if (2 * k - 1 == n) return head; 
    struct Node *x = head, *x_prev = NULL;
    for (int i = 1; i < k; i++) 
    {
        x_prev = x;
        x = x->next;
    }
    struct Node *y = head, *y_prev = NULL;
    for (int i = 1; i < n - k + 1; i++) 
    {
        y_prev = y;
        y = y->next;
    }
    if (x_prev)
        x_prev->next = y;
    else
        head = y;

    if (y_prev)
        y_prev->next = x;
    else
        head = x;

    struct Node* temp = x->next;
    x->next = y->next;
    y->next = temp;
    return head;
}
void printList(struct Node* head)
{
    while (head) 
    {
        printf("%d", head->data);
        if (head->next) printf("->");
        head = head->next;
    }
    printf("\n");
}
int main() 
{
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    int k = 2;
    printf("Original List: ");
    printList(head);

    head = swapKthNode(head, k);
    printf("Modified List: ");
    printList(head);
    return 0;
}
