
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

struct Node* makeUnion(struct Node* head1, struct Node* head2) {
    int arr[1000], i = 0;
    struct Node* temp = head1;
    while (temp) {
        arr[i++] = temp->data;
        temp = temp->next;
    }
    temp = head2;
    while (temp) {
        arr[i++] = temp->data;
        temp = temp->next;
    }
    qsort(arr, i, sizeof(int), compare);

    struct Node *res = NULL, *tail = NULL;
    for (int j = 0; j < i; j++) {
        if (j > 0 && arr[j] == arr[j-1]) continue;
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[j];
        newNode->next = NULL;
        if (!res) res = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return res;
}
