#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to sort the linked list of 0s, 1s and 2s
void sortList(struct Node* head) {
    int count[3] = {0, 0, 0};
    struct Node* ptr = head;

    // Count 0s, 1s and 2s
    while (ptr != NULL) {
        count[ptr->data]++;
        ptr = ptr->next;
    }

    ptr = head;
    int i = 0;
    while (ptr != NULL) {
        if (count[i] == 0) {
            i++;
        } else {
            ptr->data = i;
            count[i]--;
            ptr = ptr->next;
        }
    }
}

// Helper to print the list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Sample driver code
int main(
