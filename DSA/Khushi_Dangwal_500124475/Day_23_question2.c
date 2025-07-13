#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

// remove duplicates from sorted list
struct ListNode* removeDuplicates(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    
    struct ListNode* current = head;
    
    while (current->next != NULL) {
        if (current->val == current->next->val) {
            // Duplicate found - remove the next node
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp); // Free memory of duplicate node
        } else {
            // No duplicate - move to next node
            current = current->next;
        }
    }
    
    return head;
}

// Helper function to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Helper function to print the list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL) {
            printf(" -> ");
        }
        head = head->next;
    }
    printf("\n");
}

// Main function to test the code
int main() {
    // Create example linked list: 2->2->4->5
    struct ListNode* head = newNode(2);
    head->next = newNode(2);
    head->next->next = newNode(4);
    head->next->next->next = newNode(5);
    
    printf("Original list: ");
    printList(head);
    
    head = removeDuplicates(head);
    printf("List after removing duplicates: ");
    printList(head);
    
    // Create another example: 2->2->2->2->2
    struct ListNode* head2 = newNode(2);
    head2->next = newNode(2);
    head2->next->next = newNode(2);
    head2->next->next->next = newNode(2);
    head2->next->next->next->next = newNode(2);
    
    printf("\nOriginal list: ");
    printList(head2);
    
    head2 = removeDuplicates(head2);
    printf("List after removing duplicates: ");
    printList(head2);
    
    return 0;
}
