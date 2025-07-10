#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to delete n nodes after skipping m nodes
struct ListNode* deleteNodes(struct ListNode* head, int m, int n) {
    if (head == NULL || m <= 0) {
        return head; // Handle empty list or invalid m
    }

    struct ListNode *current = head;
    struct ListNode *prev = NULL;
    
    while (current != NULL) {
        // Skip m nodes
        for (int i = 0; i < m && current != NULL; i++) {
            prev = current;
            current = current->next;
        }
        
        // Delete n nodes
        for (int j = 0; j < n && current != NULL; j++) {
            struct ListNode *temp = current;
            current = current->next;
            free(temp); // Free memory of deleted node
        }
        
        // Link the previous node to current after deletion
        if (prev != NULL) {
            prev->next = current;
        }
    }
    
    return head;
}

// Helper function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d", temp->val);
        if (temp->next != NULL) {
            printf("->");
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
    // Example 1: 9->1->3->5->9->4->10->1, m=2, n=1
    struct ListNode* head1 = newNode(9);
    head1->next = newNode(1);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(5);
    head1->next->next->next->next = newNode(9);
    head1->next->next->next->next->next = newNode(4);
    head1->next->next->next->next->next->next = newNode(10);
    head1->next->next->next->next->next->next->next = newNode(1);
    
    printf("Original list 1: ");
    printList(head1);
    
    head1 = deleteNodes(head1, 2, 1);
    
    printf("Modified list 1: ");
    printList(head1);
    
    // Example 2: 1->2->3->4->5->6, m=6, n=1
    struct ListNode* head2 = newNode(1);
    head2->next = newNode(2);
    head2->next->next = newNode(3);
    head2->next->next->next = newNode(4);
    head2->next->next->next->next = newNode(5);
    head2->next->next->next->next->next = newNode(6);
    
    printf("\nOriginal list 2: ");
    printList(head2);
    
    head2 = deleteNodes(head2, 6, 1);
    
    printf("Modified list 2: ");
    printList(head2);
    
    // Free memory
    freeList(head1);
    freeList(head2);
    
    return 0;
}
