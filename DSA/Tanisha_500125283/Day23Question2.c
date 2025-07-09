// Problem Statement:Given a singly linked list that is already sorted, the task is to remove duplicates (nodes with 
// duplicate values) from the given list if they exist. This operation is fundamental in data 
// cleaning and deduplication applications where you need to eliminate redundant entries 
// while preserving the original order. The challenge involves understanding how to properly 
// link nodes while skipping duplicates and managing memory efficiently. 
// Task: Remove duplicate nodes from a sorted linked list while maintaining proper node 
// connections. 
// Examples Input: LinkedList: 2->2->4->5 
// Output:  2 -> 4 -> 5 


#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

void removeDuplicates(struct Node* head) {
    struct Node* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
          
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp); 
        } else {
            current = current->next;
        }
    }
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
   
    struct Node* head = createNode(2);
    head->next = createNode(2);
    head->next->next = createNode(4);
    head->next->next->next = createNode(5);
    printf("Linked list:");
    printList(head);

    removeDuplicates(head);
    printList(head);

    return 0;
}
