#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to delete the x-th node (1-based)
struct ListNode* deleteAtPosition(struct ListNode* head, int x) {
    // Case 1: Empty list or invalid position
    if (head == NULL || x <= 0) {
        return head;
    }

    // Case 2: Delete head node (position 1)
    if (x == 1) {
        struct ListNode* newHead = head->next;
        free(head);
        return newHead;
    }

    // Case 3: Delete other positions
    struct ListNode* current = head;
    int count = 1;
    
    // Traverse to the node before the target
    while (current != NULL && count < x - 1) {
        current = current->next;
        count++;
    }

    // If we reached end before position or next is NULL
    if (current == NULL || current->next == NULL) {
        return head; // Position exceeds list length
    }

    // Delete the node
    struct ListNode* temp = current->next;
    current->next = temp->next;
    free(temp);
    
    return head;
}

// Helper function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d", temp->val);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Helper function to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Helper function to free the entire list
void freeList(struct ListNode* head) {
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Example 1: 1 -> 3 -> 4, x = 3
    struct ListNode* head1 = newNode(1);
    head1->next = newNode(3);
    head1->next->next = newNode(4);
    
    printf("Original list 1: ");
    printList(head1);
    
    head1 = deleteAtPosition(head1, 3);
    
    printf("Modified list 1: ");
    printList(head1);
    
    // Example 2: 1 -> 5 -> 2 -> 9, x = 2
    struct ListNode* head2 = newNode(1);
    head2->next = newNode(5);
    head2->next->next = newNode(2);
    head2->next->next->next = newNode(9);
    
    printf("\nOriginal list 2: ");
    printList(head2);
    
    head2 = deleteAtPosition(head2, 2);
    
    printf("Modified list 2: ");
    printList(head2);
    
    // Free memory
    freeList(head1);
    freeList(head2);
    
    return 0;
}
