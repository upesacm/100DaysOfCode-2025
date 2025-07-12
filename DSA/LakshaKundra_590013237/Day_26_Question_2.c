#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insert(struct Node** head, int data) {
    struct Node* temp = newNode(data);
    temp->next = *head;
    *head = temp;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* toArray(struct Node* head, int* size) {
    int* arr = (int*)malloc(1000 * sizeof(int));
    *size = 0;
    while (head) {
        arr[(*size)++] = head->data;
        head = head->next;
    }
    return arr;
}

struct Node* makeUnion(struct Node* head1, struct Node* head2) {
    int size1, size2, i, j = 0, k = 0;
    int* arr1 = toArray(head1, &size1);
    int* arr2 = toArray(head2, &size2);
    int* arr = (int*)malloc((size1 + size2) * sizeof(int));
    for (i = 0; i < size1; i++) arr[j++] = arr1[i];
    for (i = 0; i < size2; i++) arr[j++] = arr2[i];
    qsort(arr, j, sizeof(int), compare);
    struct Node* result = NULL;
    for (i = 0; i < j; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            insert(&result, arr[i]);
        }
    }
    struct Node* prev = NULL;
    struct Node* curr = result;
    struct Node* next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* L1 = NULL;
    struct Node* L2 = NULL;

    insert(&L1, 8);
    insert(&L1, 3);
    insert(&L1, 2);
    insert(&L1, 4);
    insert(&L1, 6);
    insert(&L1, 9);

    insert(&L2, 2);
    insert(&L2, 6);
    insert(&L2, 8);
    insert(&L2, 2);
    insert(&L2, 1);

    struct Node* unionList1 = makeUnion(L1, L2);
    printList(unionList1);

    L1 = L2 = NULL;
    insert(&L1, 5);
    insert(&L1, 2);
    insert(&L1, 2);
    insert(&L1, 1);
    insert(&L1, 5);
    insert(&L1, 1);

    insert(&L2, 1);
    insert(&L2, 7);
    insert(&L2, 6);
    insert(&L2, 5);
    insert(&L2, 4);

    struct Node* unionList2 = makeUnion(L1, L2);
    printList(unionList2);

    return 0;
}
