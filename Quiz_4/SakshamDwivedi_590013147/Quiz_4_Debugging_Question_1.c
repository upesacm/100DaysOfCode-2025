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
    if (head == NULL) //This was (head = NULL), which is an assignment operation, which is always TRUE
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
            current = current->next; /*The main reason of current pointer moving only in else condition is that if a duplicate value is found
            the current pointer should remain there as the next node will be changed after deletion and the upcoming next node needs to be
            compared.*/
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
