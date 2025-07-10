#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure of a node
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to reverse a linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr) {
        struct ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

// Function to check if the linked list is a palindrome
bool isPalindrome(struct ListNode* head) {
    if (!head || !head->next) return true;

    // Step 1: Find middle of the list
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half of the list
    struct ListNode* secondHalf = reverseList(slow);
    struct ListNode* secondCopy = secondHalf; // to restore later (optional)

    // Step 3: Compare both halves
    struct ListNode* firstHalf = head;
    while (secondHalf) {
        if (firstHalf->val != secondHalf->val) {
            // Optional: reverse back the list before returning
            reverseList(secondCopy);
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    // Optional: restore the list
    reverseList(secondCopy);
    return true;
}

// Helper function to print the list (for testing)
void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// Driver code to test
int main() {
    // Example: 1 -> 2 -> 1 -> 1 -> 2 -> 1
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(1);
    head->next->next->next = createNode(1);
    head->next->next->next->next = createNode(2);
    head->next->next->next->next->next = createNode(1);

    printList(head);
    if (isPalindrome(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is NOT a palindrome.\n");
    }

    return 0;
}
