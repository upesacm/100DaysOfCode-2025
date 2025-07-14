#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}


struct Node* deleteNode(struct Node* head, int x) {
    if (head == NULL || x <= 0) return head;

    struct Node* temp = head;
    int count = 1;

    
    while (temp != NULL && count < x) {
        temp = temp->next;
        count++;
    }

    
    if (temp == NULL) return head;

    // If deleting head
    if (temp->prev == NULL) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
    }
    // If deleting tail
    else if (temp->next == NULL) {
        temp->prev->next = NULL;
    }
    // Deleting middle node
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
    return head;
}


void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" <--> ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = createNode(1);
    struct Node* second = createNode(3);
    struct Node* third = createNode(4);

    // Connect nodes
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    printf("Original List: ");
    printList(head);

    int pos = 3; // Delete 3rd node
    head = deleteNode(head, pos);

    printf("After Deletion at position %d: ", pos);
    printList(head);

    return 0;
}
