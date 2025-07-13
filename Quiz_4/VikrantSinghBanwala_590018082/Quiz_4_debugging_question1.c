/* 
1. What is the bug in the condition if (head = NULL)?
-- (head = NULL) is an assignment, not a comparison. It sets head to NULL, which breaks the logic.
2. Why is current = current->next; placed only inside the else block?
-- Reason: If a duplicate is removed, we should NOT move `current` forward yet,because the new `current->next` might also be a duplicate.
   Moving `current` only when no duplicate is found ensures correctness.
3, Debug the code for the correct output.
*/
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
    if (head == NULL) {  // ✅ Fixed comparison
        return head;
    }

    struct ListNode* current = head;
    while (current->next != NULL) {
        if (current->val == current->next->val) {
            struct ListNode* duplicate = current->next;
            current->next = current->next->next;
            free(duplicate);  // ✅ Free memory of removed node
        } else {
            current = current->next;  // ✅ Advance only if no duplicate
        }
    }
    return head;
}

void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
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
