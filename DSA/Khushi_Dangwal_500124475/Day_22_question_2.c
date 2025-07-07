#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to count occurrences of a key in the linked list
int countOccurrences(struct ListNode* head, int key) {
    int count = 0;
    struct ListNode* current = head;
    
    while (current != NULL) {
        if (current->val == key) {
            count++;
        }
        current = current->next;
    }
    
    return count;
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
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d", current->val);
        if (current->next != NULL) {
            printf("->");
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Example 1: 1->2->1->2->1->3->1, key = 1
    struct ListNode* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(1);
    list1->next->next->next = createNode(2);
    list1->next->next->next->next = createNode(1);
    list1->next->next->next->next->next = createNode(3);
    list1->next->next->next->next->next->next = createNode(1);
    
    printf("List 1: ");
    printList(list1);
    
    int key1 = 1;
    int count1 = countOccurrences(list1, key1);
    printf("Occurrences of %d: %d\n\n", key1, count1);
    
    // Example 2: 1->2->1->2->1, key = 3
    struct ListNode* list2 = createNode(1);
    list2->next = createNode(2);
    list2->next->next = createNode(1);
    list2->next->next->next = createNode(2);
    list2->next->next->next->next = createNode(1);
    
    printf("List 2: ");
    printList(list2);
    
    int key2 = 3;
    int count2 = countOccurrences(list2, key2);
    printf("Occurrences of %d: %d\n", key2, count2);
    
    // Free allocated memory (not shown in full for brevity)
    // In practice, you should free all allocated nodes
    
    return 0;
}


