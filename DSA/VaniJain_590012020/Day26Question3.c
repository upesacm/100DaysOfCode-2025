#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* createNode(int val) 
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
void insertEnd(struct Node** head, int val) 
{
    struct Node* newNode = createNode(val);
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
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
void sortList(struct Node** head_ref) 
{
    struct Node *zeroHead = NULL, *zeroTail = NULL;
    struct Node *oneHead = NULL, *oneTail = NULL;
    struct Node *twoHead = NULL, *twoTail = NULL;
    struct Node* curr = *head_ref;
    while (curr != NULL) 
    {
        if (curr->data == 0) 
        {
            if (!zeroHead)
                zeroHead = zeroTail = curr;
            else {
                zeroTail->next = curr;
                zeroTail = curr;
            }
        } else if (curr->data == 1) 
        {
            if (!oneHead)
                oneHead = oneTail = curr;
            else 
            {
                oneTail->next = curr;
                oneTail = curr;
            }
        } else 
        {
            if (!twoHead)
                twoHead = twoTail = curr;
            else 
            {
                twoTail->next = curr;
                twoTail = curr;
            }
        }
        curr = curr->next;
    }
    if (zeroTail) zeroTail->next = oneHead ? oneHead : twoHead;
    if (oneTail) oneTail->next = twoHead;
    if (twoTail) twoTail->next = NULL;
    if (zeroHead)
        *head_ref = zeroHead;
    else if (oneHead)
        *head_ref = oneHead;
    else
        *head_ref = twoHead;
}

int main() 
{
    struct Node* head = NULL;
    int n, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements (only 0s, 1s and 2s):\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        if (val < 0 || val > 2) 
        {
            printf("Invalid input! Only 0, 1, or 2 allowed.\n");
            i--;
            continue;
        }
        insertEnd(&head, val);
    }
    printf("Original list: ");
    printList(head);
    sortList(&head);
    printf("Sorted list (0s->1s->2s): ");
    printList(head);
    return 0;
}
