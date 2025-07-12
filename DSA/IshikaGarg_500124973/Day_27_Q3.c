#include <stdio.h>
#include <stdlib.h>

// Node structure
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

// Function to remove every k-th node
struct Node* removeKthNode(struct Node* head, int k) {
    if (head == NULL || k <= 0) return head;
    if (k == 1) {
        // Remove all nodes
        while (head != NULL) {
            struct Node* temp = head;
            head = head->next;
            free(temp);
        }
        return NULL;
    }

    struct Node* current = head;
    struct Node* prev = NULL;
    int count = 1;

    while (current != NULL) {
        if (count % k == 0) {
            // Delete current node
            struct Node* temp = current;
            if (prev != NULL)
                prev->next = current->next;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
        count++;
    }

    return head;
}

// Function to print the list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test
int main() {
    // Linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
    struct Node* head = createNode(1);
    struct Node* current = head;
    for (int i = 2; i <= 8; i++) {
        current->next = createNode(i);
        current = current->next;
    }

    printf("Original List:\n");
    printList(head);

    int k = 2;
    head = removeKthNode(head, k);

    printf("After removing every %d-th node:\n", k);
    printList(head);

    return 0;
}
