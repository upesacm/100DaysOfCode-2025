#include <stdio.h>
#include <stdlib.h>


struct ListNode
{
    int val;
    struct ListNode* next;
};

// Function to create a new node
struct ListNode* createNode(int val)
{
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to remove duplicates from a sorted linked list
struct ListNode* removeDuplicates(struct ListNode* head)
{
    /*
      Task 1: 
      if (head = NULL)
    Here = is used which is for assignment here we need comparison so we changed it to ==
    */
    if (head == NULL)
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
            free(duplicate); // Delete the duplicate and free its memory
        }
        else
        {
            /*
             Task 2: Why we only move current forward inside the else block
              because when we remove a duplicate, current->next is updated to a new node.
             That new node could also be a duplicate of the current node.
             So, if we were to move forward immediately after deletion,
             we might skip over duplicates.
             By advancing 'current' only when no deletion occurs,
             we make sure all consecutive duplicates are checked properly.
            */
            current = current->next;
        }
    }

    return head;
}

// Function to print the linked list
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

// Driver code
int main()
{
    
    struct ListNode* head = createNode(1);
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(3);

    printf("Original list: ");
    printList(head);

    // Remove duplicates
    head = removeDuplicates(head);

    printf("After removing duplicates: ");
    printList(head);

    return 0;
}
