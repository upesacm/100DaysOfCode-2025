//Bug in this question 
//1. Condition in if (head = NULL || k == 0)
//it should be 
//if (head == NULL || k == 0)

//2.Is it necessary to check fast != NULL inside the loop?
//Yes, it's important to check fast != NULL to avoid segmentation fault in shorter lists.

//correct code 

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

int findKthFromEnd(struct ListNode* head, int k) {
    if (head == NULL || k == 0)
        return -1;

    struct ListNode* fast = head;
    for (int i = 0; i < k; i++) {
        if (fast == NULL)
            return -1;
        fast = fast->next;
    }

    struct ListNode* second = head;
    while (fast != NULL) {
        fast = fast->next;
        second = second->next;
    }

    return second->val;
}

void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct ListNode* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);

    printf("Original list: ");
    printList(head);

    int k = 2;
    int result = findKthFromEnd(head, k);

    if (result != -1)
        printf("The %d-th node from end is: %d\n", k, result);
    else
        printf("Invalid k or empty list.\n");

    return 0;
}


