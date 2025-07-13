#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Reverse linked list
struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Check if list is palindrome
bool isPalindrome(struct Node* head) {
    if (!head || !head->next) return true;

    struct Node* slow = head;
    struct Node* fast = head;

    // Find middle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    struct Node* secondHalf = reverse(slow);
    struct Node* temp = secondHalf;
    struct Node* firstHalf = head;

    // Compare both halves
    while (temp) {
        if (firstHalf->data != temp->data)
            return false;
        firstHalf = firstHalf->next;
        temp = temp->next;
    }

    return true;
}

// Build list from array
struct Node* buildList(int arr[], int n) {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    for (int i = 0; i < n; i++) {
        struct Node* node = createNode(arr[i]);
        if (!head) head = node;
        else tail->next = node;
        tail = node;
    }
    return head;
}

int main() {
    int arr[] = {1, 2, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node* head = buildList(arr, n);

    if (isPalindrome(head))
        printf("The list is a palindrome.\n");
    else
        printf("The list is not a palindrome.\n");

    return 0;
}
