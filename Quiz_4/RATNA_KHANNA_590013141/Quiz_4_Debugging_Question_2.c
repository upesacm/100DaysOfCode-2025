//1.
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

// Function to find the k-th node from the end
int findKthFromEnd(struct ListNode* head, int k) {
    if (head == NULL || k <= 0) {
        return -1;
    }

    struct ListNode* first = head;
    struct ListNode* second = head;

    // Move first pointer k steps ahead
    for (int i = 0; i < k; i++) {
        if (first == NULL) {
            return -1;  // k is greater than list length
        }
        first = first->next;
    }

    // Move both pointers until first reaches end
    while (first != NULL) {
        first = first->next;
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
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original list: ");
    printList(head);

    int k = 2;
    int result = findKthFromEnd(head, k);

    if (result != -1) {
        printf("The %dth node from end is: %d\n", k, result);
    } else {
        printf("Invalid k or empty list\n");
    }

    return 0;
}
//2.Yes, it's necessary because:It ensures that k is not greater than the length of the list.
If you try to move first k steps and it becomes NULL before reaching k, that means the list is too short → should return -1.
