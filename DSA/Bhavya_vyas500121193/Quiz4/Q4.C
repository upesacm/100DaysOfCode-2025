#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Delete k-th node from end
struct Node* deleteKthFromEnd(struct Node* head, int k) {
    struct Node* fast = head;
    struct Node* slow = head;
    struct Node* prev = NULL;

    // Move fast pointer k steps ahead
    for (int i = 0; i < k; i++) {
        if (fast == NULL) return head;  // k > length
        fast = fast->next;
    }

    // If fast is NULL after moving k steps, delete head
    if (fast == NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // Move both pointers
    while (fast != NULL) {
        fast = fast->next;
        prev = slow;
        slow = slow->next;
    }

    // Delete slow node
    prev->next = slow->next;
    free(slow);

    return head;
}

// Print linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Main
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        struct Node* newNode = createNode(arr[i]);
        if (head == NULL) head = newNode;
        else tail->next = newNode;
        tail = newNode;
    }

    printf("Original List:\n");
    printList(head);

    head = deleteKthFromEnd(head, 2);

    printf("After deleting 2nd node from end:\n");
    printList(head);

    return 0;
}
