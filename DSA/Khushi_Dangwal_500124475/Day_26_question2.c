#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Insert node in sorted order (used for result)
void insertSorted(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    struct Node* prev = NULL;

    // If list is empty or new node should be first
    while (current != NULL && current->data < data) {
        prev = current;
        current = current->next;
    }

    // If duplicate, do not insert
    if (current != NULL && current->data == data)
        return;

    // Create and insert node
    struct Node* temp = newNode(data);
    if (prev == NULL) {
        temp->next = *head_ref;
        *head_ref = temp;
    } else {
        temp->next = prev->next;
        prev->next = temp;
    }
}

// Function to perform union of two linked lists
struct Node* makeUnion(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL;

    while (head1 != NULL) {
        insertSorted(&result, head1->data);
        head1 = head1->next;
    }

    while (head2 != NULL) {
        insertSorted(&result, head2->data);
        head2 = head2->next;
    }

    return result;
}

// Function to print linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Sample driver code
int main() {
    // L1: 9->6->4->2->3->8
    struct Node* L1 = newNode(9);
    L1->next = newNode(6);
    L1->next->next = newNode(4);
    L1->next->next->next = newNode(2);
    L1->next->next->next->next = newNode(3);
    L1->next->next->next->next->next = newNode(8);

    // L2: 1->2->8->6->2
    struct Node* L2 = newNode(1);
    L2->next = newNode(2);
    L2->next->next = newNode(8);
    L2->next->next->next = newNode(6);
    L2->next->next->next->next = newNode(2);

    struct Node* unionList = makeUnion(L1, L2);
    printf("Union of linked lists:\n");
    printList(unionList);

    return 0;
}
