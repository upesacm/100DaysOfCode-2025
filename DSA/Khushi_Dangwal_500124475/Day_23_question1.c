#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to find the kth node from end
int findKthFromEnd(struct ListNode* head, int k) {
    if (head == NULL || k <= 0) {
        return -1;
    }
    
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    
    // Move fast pointer k nodes ahead
    for (int i = 0; i < k; i++) {
        if (fast == NULL) {
            return -1; 
        }
        fast = fast->next;
    }
    
    // Move both pointers until fast reaches end
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow->val;
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

// Main function to test the code
int main() {
    // example linked list: 1->2->3->4->5->6->7->8->9
    struct ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(6);
    head->next->next->next->next->next->next = newNode(7);
    head->next->next->next->next->next->next->next = newNode(8);
    head->next->next->next->next->next->next->next->next = newNode(9);
    
    printf("Original list: ");
    printList(head);
    
    int k = 2;
    int result = findKthFromEnd(head, k);
    printf("%dth node from end: %d\n", k, result);
    
    k = 5;
    result = findKthFromEnd(head, k);
    printf("%dth node from end: %d\n", k, result);
    
    k = 10; // Test case where k > list length
    result = findKthFromEnd(head, k);
    printf("%dth node from end: %d\n", k, result);
    
    return 0;
}
