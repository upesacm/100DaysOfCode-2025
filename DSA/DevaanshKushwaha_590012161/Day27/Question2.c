#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Append a node at the end
struct Node* append(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Function to remove every kᵗʰ node
struct Node* removeKthNode(struct Node* head, int k) {
    if (head == NULL || k <= 0) return head;

    struct Node* curr = head;
    struct Node* prev = NULL;
    int count = 1;

    while (curr != NULL) {
        if (count % k == 0) {
            // Remove current node
            if (prev != NULL) {
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
            } else {
                // Deleting the head node
                head = curr->next;
                free(curr);
                curr = head;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
        count++;
    }

    return head;
}

// Driver code
int main() {
    struct Node* head = NULL;
    int k = 3;

    // Create the linked list: 1 -> 2 -> ... -> 10
    for (int i = 1; i <= 10; i++)
        head = append(head, i);

    printf("Original List:\n");
    printList(head);

    head = removeKthNode(head, k);

    printf("List after removing every %dth node:\n", k);
    printList(head);

    return 0;
}
