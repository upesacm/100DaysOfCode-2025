/*
1. There's a bug in the line for(int i = 0; i <= k; i++) with the conditional operator. It moves 'first' k + 1 times which is one extra to 
   what's required. Therefore, it can be fixed by putting a '<' sign instead of the '<=' sign.

   Debugged code : 

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

    for (int i = 0; i < k; i++)  // FIXED: < instead of <=
    {  
        if (first == NULL)
        {
            return -1;  // k is larger than list length
        }
        first = first->next;
    }

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

2. Yes, it is necessary to check 'first == NULL' inside the loop because if k > length of list, then 'first' will hit 'NULL' before 
   completing k steps and the problem asks to return -1 if k is invalid.

   */
