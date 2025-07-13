#include <stdio.h>
#include <stdlib.h>

// Definition of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append node at the end
void append(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to find kth node from end
int kthFromEnd(struct Node* head, int k) {
    struct Node *first = head, *second = head;
    int count = 0;

    // Move first pointer k steps ahead
    while (count < k) {
        if (first == NULL)
            return -1; // k is greater than number of nodes
        first = first->next;
        count++;
    }

    // Move both pointers until first reaches end
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    return second ? second->data : -1;
}

int main() {
    struct Node* head = NULL;
    int n, k, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        append(&head, value);
    }

    printf("Enter value of k: ");
    scanf("%d", &k);

    int result = kthFromEnd(head, k);
    if (result == -1)
        printf("Invalid k (greater than number of nodes)\n");
    else
        printf("The %dth node from the end is: %d\n", k, result);

    return 0;
}
