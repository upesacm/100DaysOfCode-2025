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

// Find k-th node from end
int findKthFromEnd(struct ListNode* head, int k) {
    struct ListNode *first = head, *second = head;
    for (int i = 0; i < k; i++) {
        if (!first) return -1;
        first = first->next;
    }
    while (first) {
        first = first->next;
        second = second->next;
    }
    return second ? second->val : -1;
}

int main() {
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    struct ListNode* head = createList(n);
    printf("Enter k (position from end): ");
    scanf("%d", &k);
    int result = findKthFromEnd(head, k);
    if (result != -1)
        printf("The %d-th node from the end is: %d\n", k, result);
    else
        printf("Invalid input or list too short.\n");
    return 0;
}
