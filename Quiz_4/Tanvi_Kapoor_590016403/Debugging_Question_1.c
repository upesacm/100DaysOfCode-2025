#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to remove duplicates from a sorted linked list
struct ListNode* removeDuplicates(struct ListNode* head) {
    // ✅ Fixed bug: changed = to ==
    if (head == NULL) {
        return head;
    }

    struct ListNode* current = head;
    while (current->next != NULL) {
        if (current->val == current->next->val) {
            // Remove the duplicate node
            struct ListNode* duplicate = current->next;
            current->next = current->next->next;
            free(duplicate);  // Free memory
        } else {
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

// Main function to test
int main() {
    // Create sorted linked list: 1 → 1 → 2 → 3 → 3
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
