// The following C code is supposed to remove duplicates from a sorted linked list, but it contains bugs. Find and fix the errors. 

#include <stdio.h>
#include <stdlib.h>
//Here's the code that i corrected.

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
    if (head ==NULL)// used == instead of = ; this was the main bug here in the code.
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
// HERE INSTEAD OF head = NULL, it should be head == NULL
// Otherwise, it will always evaluate to true, causing the function to return immediately without processing the list.
// Also, the condition in the if statement should use '==' for comparison, not '=' which is an assignment operator.
// Additionally, the code should include proper memory management and checks for NULL pointers.
// ques 2> why is current=currrent->next; in the else block?
// The line `current = current->next;` in the else block is necessary to move to the next node in the list when no duplicate is found.