//1:Debug code
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

    for (int i = 0; i < k; i++)
    {  
        if (first == NULL)
        {
            return -1;  
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

//2: Yes, it is necessary.
//Why?
//If k is greater than the length of the list, advancing first k times will eventually make it NULL.

//Without the check, you will get a segmentation fault when trying to do first = first->next.
