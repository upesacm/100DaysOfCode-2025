#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int findKthFromEnd(struct Node* head, int k1) {
    struct Node *first = head, *second = head;

    for (int i = 0; i < k1; i++) {
        if (first == NULL) return -1;
        first = first->next;
    }

    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    return second ? second->data : -1;
}

void append(struct Node** headRef, int data) {
    struct Node* temp = newNode(data);
    if (*headRef == NULL) {
        *headRef = temp;
        return;
    }
    struct Node* curr = *headRef;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
}

int main() {
    struct Node* head = NULL;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int k1 = 2;

    for (int i = 0; i < n1; i++) append(&head, arr1[i]);

    int result1 = findKthFromEnd(head, k1);
    if (result1 != -1)
        printf("Kth node from end is: %d\n1", result1);
    else
        printf("K is more than the number of nodes.\n1");
    int arr2[] = {10,5,100,5};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int k2 = 5;

    for (int i = 0; i < n1; i++) append(&head, arr2[i]);

    int result2 = findKthFromEnd(head, k2);
    if (result2 != -1)
        printf("Kth node from end is: %d\n1", result2);
    else
        printf("K is more than the number of nodes.\n1");    

    return 0;
}
