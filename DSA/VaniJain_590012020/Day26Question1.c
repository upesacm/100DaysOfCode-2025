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
void printList(struct Node* head) 
{
    while (head != NULL) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
int getLength(struct Node* head) 
{
    int count = 0;
    while (head != NULL) 
    {
        count++;
        head = head->next;
    }
    return count;
}
void swapKthNode(struct Node** head_ref, int k) 
{
    int n = getLength(*head_ref);
    if (k > n) 
    {
        printf("Invalid k: greater than length\n");
        return;
    }
    if (2 * k - 1 == n) return;
    struct Node *prevX = NULL, *currX = *head_ref;
    struct Node *prevY = NULL, *currY = *head_ref;
    for (int i = 1; i < k; i++) {
        prevX = currX;
        currX = currX->next;
    }
    for (int i = 1; i < n - k + 1; i++) 
    {
        prevY = currY;
        currY = currY->next;
    }
    if (prevX) prevX->next = currY;
    else *head_ref = currY;
    if (prevY) prevY->next = currX;
    else *head_ref = currX;
    struct Node* temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;
}

int main() 
{
    int n, k, val;
    struct Node* head = NULL;
    struct Node* tail = NULL;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) 
        {
            head = tail = newNode;
        } else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    printf("Enter k: ");
    scanf("%d", &k);
    printf("Original list: ");
    printList(head);
    swapKthNode(&head, k);
    printf("Modified list after swapping kth nodes: ");
    printList(head);
    return 0;
}
