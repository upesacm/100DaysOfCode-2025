#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;       
    struct Node* current = head;   
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;      
        current->next = prev;      
        prev = current;             
        current = next;             
    }

    return prev;  
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    printf("Original Chain: ");
    printList(head);

    head = reverseList(head);

    printf("Reversed Chain: ");
    printList(head);

    return 0;
}
