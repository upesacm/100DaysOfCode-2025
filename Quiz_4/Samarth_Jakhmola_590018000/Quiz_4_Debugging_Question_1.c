/*
1. The bug in the condition if(head = NULL) is that there is an assignment operator where a comparison operator should have been.

2. current = current->next is placed only inside the else block as if we remove a duplicate, we don't move forward yet and we need to check
   the new current->next value again in the next iteration. And if no duplicate is found, we move to the next node.

3. Debugged code : 

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

struct ListNode* removeDuplicates(struct ListNode* head)
{
    if (head == NULL)   // FIXED: == instead of =
    {
        return head;
    }

    struct ListNode* current = head;
    while (current->next != NULL)
    {
        if (current->val == current->next->val)
        {
            struct ListNode* duplicate = current->next;
            current->next = current->next->next;
            free(duplicate);
        }
        else
        {
            current = current->next;
        }
    }
    return head;
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
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(3);

    printf("Original list: ");
    printList(head);
     
    head = removeDuplicates(head);

    printf("After removing duplicates: ");
    printList(head);
    return 0;
}
    */
