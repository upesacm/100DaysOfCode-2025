#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode* next;
};


int countOccurrences(struct ListNode* head, int key) {
    int count = 0;
    while (head != NULL) {
        if (head->val == key) {
            count++;
        }
        head = head->next;
    }
    return count;
}


struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}


void appendNode(struct ListNode** headRef, int val) {
    struct ListNode* newNode = createNode(val);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct ListNode* current = *headRef;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

int main() {
    struct ListNode* head = NULL;

    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 2);
    appendNode(&head, 4);
    appendNode(&head, 2);

    int key = 2;
    int count = countOccurrences(head, key);
    printf("The key %d appears %d times in the linked list.\n", key, count);  

    return 0;
}
