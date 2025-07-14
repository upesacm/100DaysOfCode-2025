#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to reverse a linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *current = head;
    struct ListNode *next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

// Function to check if a linked list is palindrome
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    
    // Step 1: Find the middle of the linked list
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Step 2: Reverse the second half of the list
    struct ListNode *secondHalf = reverseList(slow->next);
    struct ListNode *firstHalf = head;
    
    // Step 3: Compare the first half and reversed second half
    bool result = true;
    struct ListNode *temp = secondHalf;
    while (temp != NULL) {
        if (firstHalf->val != temp->val) {
            result = false;
            break;
        }
        firstHalf = firstHalf->next;
        temp = temp->next;
    }
    
    // Step 4: Restore the list (optional)
    slow->next = reverseList(secondHalf);
    
    return result;
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
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Test case 1: 1->2->1->1->2->1 (palindrome)
    struct ListNode* head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(1);
    head1->next->next->next = newNode(1);
    head1->next->next->next->next = newNode(2);
    head1->next->next->next->next->next = newNode(1);
    
    printf("List 1: ");
    printList(head1);
    printf("Is palindrome? %s\n", isPalindrome(head1) ? "true" : "false");
    
    // Test case 2: 1->2->3->4 (not palindrome)
    struct ListNode* head2 = newNode(1);
    head2->next = newNode(2);
    head2->next->next = newNode(3);
    head2->next->next->next = newNode(4);
    
    printf("List 2: ");
    printList(head2);
    printf("Is palindrome? %s\n", isPalindrome(head2) ? "true" : "false");
    
    return 0;
}
