#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List Node
typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

// Singly Linked List Node
typedef struct SNode {
    int data;
    struct SNode* next;
} SNode;

// Function to create a new Doubly Linked List node
DNode* createDNode(int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the end of a doubly linked list
DNode* insertDoublyEnd(DNode* head, int data) {
    DNode* newNode = createDNode(data);
    if (!head) return newNode;
    DNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Function to delete a node at position 'pos' in a doubly linked list
DNode* deleteAtPosition(DNode* head, int pos) {
    if (!head || pos <= 0) return head;
    DNode* temp = head;
    int count = 1;
    while (temp && count < pos) {
        temp = temp->next;
        count++;
    }
    if (!temp) return head; // position out of range

    if (temp->prev) temp->prev->next = temp->next;
    else head = temp->next; // deleting head

    if (temp->next) temp->next->prev = temp->prev;

    free(temp);
    return head;
}

// Function to reverse a doubly linked list
DNode* reverseDoubly(DNode* head) {
    DNode *temp = NULL, *current = head;
    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp) head = temp->prev;
    return head;
}

// Function to print doubly linked list
void printDoubly(DNode* head) {
    DNode* temp = head;
    while (temp) {
        printf("%d", temp->data);
        if (temp->next) printf(" <-> ");
        temp = temp->next;
    }
    printf("\n");
}

// Function to create a singly linked list node
SNode* createSNode(int data) {
    SNode* newNode = (SNode*)malloc(sizeof(SNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the end of singly linked list
SNode* insertSinglyEnd(SNode* head, int data) {
    SNode* newNode = createSNode(data);
    if (!head) return newNode;
    SNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

// Function to remove every kth node from singly linked list
SNode* removeEveryKth(SNode* head, int k) {
    if (k <= 0 || !head) return head;
    SNode* temp = head;
    SNode* prev = NULL;
    int count = 1;
    while (temp) {
        if (count % k == 0) {
            if (prev) prev->next = temp->next;
            else head = temp->next; // deleting head
            SNode* toDelete = temp;
            temp = temp->next;
            free(toDelete);
            count++;
            continue;
        }
        prev = temp;
        temp = temp->next;
        count++;
    }
    return head;
}

// Function to print singly linked list
void printSingly(SNode* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// ------------------ MAIN ------------------
int main() {
    // Task 1: Delete node at position in Doubly Linked List
    DNode* dll1 = NULL;
    dll1 = insertDoublyEnd(dll1, 1);
    dll1 = insertDoublyEnd(dll1, 5);
    dll1 = insertDoublyEnd(dll1, 2);
    dll1 = insertDoublyEnd(dll1, 9);
    printf("Original Doubly Linked List:\n");
    printDoubly(dll1);
    dll1 = deleteAtPosition(dll1, 1);
    printf("After Deletion at Position 1:\n");
    printDoubly(dll1);

    // Task 2: Reverse a Doubly Linked List
    DNode* dll2 = NULL;
    dll2 = insertDoublyEnd(dll2, 3);
    dll2 = insertDoublyEnd(dll2, 4);
    dll2 = insertDoublyEnd(dll2, 5);
    printf("\nOriginal Doubly Linked List:\n");
    printDoubly(dll2);
    dll2 = reverseDoubly(dll2);
    printf("Reversed Doubly Linked List:\n");
    printDoubly(dll2);

    // Task 3: Remove every kth node from Singly Linked List
    SNode* sll = NULL;
    for (int i = 1; i <= 10; i++) {
        sll = insertSinglyEnd(sll, i);
    }
    printf("\nOriginal Singly Linked List:\n");
    printSingly(sll);
    sll = removeEveryKth(sll, 3);
    printf("After Removing every 3rd node:\n");
    printSingly(sll);

    return 0;
}
