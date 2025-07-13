1. What is the bug in the condition if (head = NULL)?
  In this line: if (head = NULL)
  I used '=' which means assignment, not comparison. It was setting head to NULL by mistake.
Fix:
  I changed it to '==' which checks if head is actually NULL or not. So now it is: if (head == NULL).

  
  2. Why is current = current->next; placed only inside the else block?
  I kept 'current = current->next;' only in the else part, because if I find a duplicate, I remove it first and then I want to check the new next node again.
If I move current forward even after deleting, It might skip checking some values that are also duplicates.
  So, I move to the next node only when no duplicate is found.

3. Debug the code for the correct output.
  
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


