#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// Create a linked list from user input
struct ListNode* createList(int n) {
    struct ListNode *head = NULL, *tail = NULL, *node;
    int val;
    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = val;
        node->next = NULL;
        if (head == NULL)
            head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

// Remove duplicates from sorted list
struct ListNode* removeDuplicates(struct ListNode* head) {
    struct ListNode* current = head;
    while (current && current->next) {
        if (current->val == current->next->val) {
            struct ListNode* temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    return head;
}

// Print list
void printList(struct ListNode* head) {
    printf("List: ");
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    struct ListNode* head = createList(n);
    printf("Original ");
    printList(head);
    head = removeDuplicates(head);
    printf("After removing duplicates ");
    printList(head);
    return 0;
}
