#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to reverse the linked list iteratively
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *current = head;
    struct ListNode *next = NULL;
    
    while (current != NULL) {
        // Store the next node
        next = current->next;
        
        // Reverse the current node's pointer
        current->next = prev;
        
        // Move pointers forward
        prev = current;
        current = next;
    }
    
    // Prev is now the new head
    return prev;
}

// Helper function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Helper function to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

int main() {
    // Example 1: 1 -> 2 -> 3 -> 4 -> NULL
    struct ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    
    printf("Original list: ");
    printList(head);
    
    head = reverseList(head);
    
    printf("Reversed list: ");
    printList(head);
    
    // Free memory (in a real program)
    
    return 0;
}
