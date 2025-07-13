#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int val)
{
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

int findKthFromEnd(struct ListNode* head, int k)
{
    if (head == NULL || k <= 0)
    {
        return -1;
    }

    struct ListNode* first = head;
    struct ListNode* second = head;

    // Task 1: Fix the loop condition (i < k instead of i <= k)
    // Reason: We need to move 'first' k steps ahead, not k+1.
    for (int i = 0; i < k; i++)
    {  
        if (first == NULL)
        {
            return -1;  // Handle cases where k > list length
        }
        first = first->next;
    }

    // Task 2: The NULL check inside the loop is necessary to handle cases where k > list length.
    // However, it's already handled above, so no need to repeat it here.
    while (first != NULL)
    {
        first = first->next;
        second = second->next;
    }

    return second->val;  
}

void printList(struct ListNode* head)
{
    struct ListNode* current = head;
    while (current != NULL)
    {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original list: ");
    printList(head);

    int k = 2;
    int result = findKthFromEnd(head, k);

    if (result != -1)
    {
        printf("The %dth node from end is: %d\n", k, result);
    }
    else
    {
        printf("Invalid k or empty list\n");
    }

    return 0;
}