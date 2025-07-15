#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int arr[], int n) {
    struct Node* head = NULL, * tail = NULL;
    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;
        if (!head)
            head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next)
            printf(" → ");
        head = head->next;
    }
    printf("\n");
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

struct Node* makeUnion(struct Node* head1, struct Node* head2) {
    int arr[10000], n = 0;
    struct Node* temp = head1;
    while (temp) {
        arr[n++] = temp->data;
        temp = temp->next;
    }
    temp = head2;
    while (temp) {
        arr[n++] = temp->data;
        temp = temp->next;
    }

    qsort(arr, n, sizeof(int), compare);

    struct Node* newHead = NULL, * tail = NULL;
    for (int i = 0; i < n; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = arr[i];
            newNode->next = NULL;
            if (!newHead)
                newHead = tail = newNode;
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    return newHead;
}

int main() {
    int arr1[] = {9, 6, 4, 2, 3, 8};
    int arr2[] = {1, 2, 8, 6, 2};
    struct Node* head1 = createList(arr1, 6);
    struct Node* head2 = createList(arr2, 5);
    struct Node* result = makeUnion(head1, head2);
    printList(result);  
    return 0;
}
