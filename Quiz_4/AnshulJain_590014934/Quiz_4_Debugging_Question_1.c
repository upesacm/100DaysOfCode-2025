#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* removeDuplicates(struct ListNode* head) {
    if (head == NULL)
    {
        return head;
    }

    struct ListNode* current = head;
    while (current != NULL && current->next != NULL)
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

void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL)
    {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

int main() {
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

/*
Answers of the  Tasks Question :

1. Bug in "if (head = NULL)":
   - This is an assignment, not a comparison.
   - It should be "if (head == NULL)" to check for NULL.

2. Why "current = current->next;" is only in the else block:
   - When a duplicate is found and deleted, we do NOT move to the next node
     because the new current->next node may still be a duplicate.
   - Only advance current when no deletion is done.

3. Debug Summary:
   - Fixed 'if (head = NULL)' to 'if (head == NULL)'
   - Added 'current != NULL' in the while loop condition for safety
*/
