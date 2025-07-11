// Problem Statement: Given the head of a linked list, the task is to reverse this list and return the reversed head. 
// This is one of the most fundamental operations in linked list manipulation and appears 
// frequently in interviews and real-world applications like implementing undo functionality, 
// reversing data streams, or processing data in reverse order. You can solve this iteratively by 
// changing the links between nodes, or recursively by processing nodes from the end. 
// Understanding pointer manipulation is crucial for this problem. 
// Task: Reverse the direction of a linked list by changing node connections using efficient 
// pointer manipulation. 
// Examples Input: head: 1 -> 2 -> 3 -> 4 -> NULL 
// Output: head: 4 -> 3 -> 2 -> 1 -> NULL


#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}


void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL) printf(" -> ");
        head = head->next;
    }
    printf(" -> NULL\n");
}


struct ListNode* reverseIterative(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev; 
}

struct ListNode* reverseRecursive(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}


int main() {
   
    struct ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    printList(head);

    head = reverseIterative(head);
    printList(head);


    return 0;
}
