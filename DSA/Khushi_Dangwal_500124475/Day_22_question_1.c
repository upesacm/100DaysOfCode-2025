#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to find the middle node of a linked list
struct ListNode* findMiddle(struct ListNode* head) {
    if (head == NULL) {
        return NULL; 
    }
    
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;         
        fast = fast->next->next;    
    }
    
    return slow;
}

// Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print the linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Example 1: 1->2->3->4->5
    struct ListNode* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(3);
    list1->next->next->next = createNode(4);
    list1->next->next->next->next = createNode(5);
    
    printf("List 1: ");
    printList(list1);
    
    struct ListNode* middle1 = findMiddle(list1);
    printf("Middle node: %d\n\n", middle1->val);
    
    // Example 2: 2->4->6->7->5->1
    struct ListNode* list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);
    list2->next->next->next = createNode(7);
    list2->next->next->next->next = createNode(5);
    list2->next->next->next->next->next = createNode(1);
    
    printf("List 2: ");
    printList(list2);
    
    struct ListNode* middle2 = findMiddle(list2);
    printf("Middle node: %d\n", middle2->val);
    
    // Free allocated memory (not shown in full for brevity)
    
    return 0;
}
