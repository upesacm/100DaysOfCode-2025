#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to find intersection of two sorted linked lists
struct ListNode* findIntersection(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* result = NULL;      // Head of the result list
    struct ListNode** tail = &result;    // Pointer to the last node's next pointer
    
    while (list1 != NULL && list2 != NULL) {
        if (list1->val == list2->val) {
            // Found a common element, add to result list
            *tail = newNode(list1->val);
            tail = &((*tail)->next);
            
            // Move both pointers forward
            list1 = list1->next;
            list2 = list2->next;
        }
        else if (list1->val < list2->val) {
            // Move list1 pointer forward
            list1 = list1->next;
        }
        else {
            // Move list2 pointer forward
            list2 = list2->next;
        }
    }
    
    return result;
}

// Function to print a linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL) {
            printf("->");
        }
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Test case 1
    struct ListNode* list1 = newNode(1);
    list1->next = newNode(2);
    list1->next->next = newNode(3);
    list1->next->next->next = newNode(4);
    list1->next->next->next->next = newNode(6);
    
    struct ListNode* list2 = newNode(2);
    list2->next = newNode(4);
    list2->next->next = newNode(6);
    list2->next->next->next = newNode(8);
    
    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);
    
    struct ListNode* intersection = findIntersection(list1, list2);
    printf("Intersection: ");
    printList(intersection);
    
    // Test case 2
    struct ListNode* list3 = newNode(10);
    list3->next = newNode(20);
    list3->next->next = newNode(40);
    list3->next->next->next = newNode(50);
    
    struct ListNode* list4 = newNode(15);
    list4->next = newNode(40);
    
    printf("\nList 3: ");
    printList(list3);
    printf("List 4: ");
    printList(list4);
    
    struct ListNode* intersection2 = findIntersection(list3, list4);
    printf("Intersection: ");
    printList(intersection2);
    
    return 0;
}
