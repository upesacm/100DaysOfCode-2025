1. Bug in the condition: if (head = NULL)
Do this : if (head == NULL)

2.
If we remove a duplicate, we do not move to the next node immediately, 
because current->next has changed and we want to check again with the new current->next.
If there's no duplicate, then we move forward to the next node.

3.
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

struct ListNode* removeDuplicates(struct ListNode* head) {
    if (head == NULL) {  
        return head;
    }

    struct ListNode* current = head;
    while (current->next != NULL) {
        if (current->val == current->next->val) {
            struct ListNode* duplicate = current->next;
            current->next = current->next->next;
            free(duplicate); 
        } else {
            current = current->next; 
        }
    }
    return head;
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
    struct ListNode* head = createNode(1);
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(3);

    printf("Original list: ");
    printList(head);

    head = removeDuplicates(head);

    printf("After removing duplicates: ");
    printList(head);
    return 0;
}
