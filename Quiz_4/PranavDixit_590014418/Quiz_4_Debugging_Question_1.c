/*
    Name: Pranav Dixit
    Task: Debugging a C Program to Remove Duplicates from a Sorted Linked List

    Answer 1:
    - There was a bug in the line `if (head = NULL)`.
    - It used a single `=` which is assignment, not comparison.
    - So I changed it to `==` like this: `if (head == NULL)`.

    Answer 2:
    - The line `current = current->next;` was only written in the else part.
    - That's actually correct because when we delete a duplicate node,
      we don’t want to move forward immediately — we need to check again in case there are more duplicates.
    - So I didn’t change its position.

    Answer 3:
    - After fixing the `=` bug, the rest of the code was working fine.
    - The logic for deleting duplicates and updating the list was correct.
*/

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
            // duplicate found, so delete it
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
