#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to create a new node with a given value
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

/*
Task 1:
Bug: if (head = NULL)
This is an assignment, not a comparison.
Fix: Use '==' instead of '=' in the condition.
*/
struct ListNode* removeDuplicates(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }

    struct ListNode* current = head;

    while (current->next != NULL) {
        if (current->val == current->next->val) {
            // Duplicate node found
            struct ListNode* duplicate = current->next;
            current->next = current->next->next;
            free(duplicate); // Free the memory of the removed node
        } else {
             /*
            Task 2:
            Reason for current = current->next only in the else block:
            - We only move current forward when there is no duplicate.
            - If a duplicate is removed, current still needs to check the new current->next,
              because it might also be a duplicate.
            */
            current = current->next;
        }
    }

    return head;
}

// Function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Creating the sorted linked list: 1 -> 1 -> 2 -> 3 -> 3
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
