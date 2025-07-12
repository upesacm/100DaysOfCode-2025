#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
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

// Function to insert a node at the end of the list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to remove every k'th node
struct Node* removeEveryKthNode(struct Node* head, int k) {
    if (head == NULL || k <= 1) {
        return NULL; // If list is empty or k is 1, we remove all nodes
    }
    
    struct Node* current = head;
    struct Node* prev = NULL;
    int count = 1;
    
    while (current != NULL) {
        if (count % k == 0) {
            // Remove the k'th node
            prev->next = current->next;
            free(current);
            current = prev->next;
        } else {
            // Move to next node
            prev = current;
            current = current->next;
        }
        count++;
    }
    
    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function to test the implementation
int main() {
    struct Node* head = NULL;
    
    // Create the list 1->2->3->4->5->6->7->8
    for (int i = 1; i <= 8; i++) {
        insertEnd(&head, i);
    }
    
    printf("Original list (k=2): ");
    printList(head);
    
    // Remove every 2nd node
    head = removeEveryKthNode(head, 2);
    printf("After removing every 2nd node: ");
    printList(head);
    
    freeList(head);
    head = NULL;
    
    // Create another list 1->2->3->4->5->6->7->8->9->10
    for (int i = 1; i <= 10; i++) {
        insertEnd(&head, i);
    }
    
    printf("\nOriginal list (k=3): ");
    printList(head);
    
    // Remove every 3rd node
    head = removeEveryKthNode(head, 3);
    printf("After removing every 3rd node: ");
    printList(head);
    
    freeList(head);
    
    return 0;
}
