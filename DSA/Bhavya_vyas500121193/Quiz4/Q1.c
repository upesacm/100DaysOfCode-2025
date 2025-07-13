#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to find the middle element using two-pointer approach
int findMiddle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow != NULL)
        return slow->data;

    return -1; // If list is empty
}

// Function to build the linked list
struct Node* buildList(int arr[], int n) {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        struct Node* newNode = createNode(arr[i]);
        if (head == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }

    return head;
}

// Main function
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node* head = buildList(arr, n);
    int middle = findMiddle(head);

    printf("Middle element is: %d\n", middle);

    return 0;
}
