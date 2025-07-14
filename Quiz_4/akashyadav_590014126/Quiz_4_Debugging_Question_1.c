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
    while (current != NULL && current->next != NULL) {
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

//the bug in using assignment operator = instead of the comparison operator == which could wipe out our list and lead to undefined behavior.
//current = current->next is placed only inside the else block as if current->val == current->next->val, we're removing the next node, so we don’t advance current — because there can be more duplicates with the same value as well.