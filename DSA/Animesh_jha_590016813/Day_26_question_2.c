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

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void insertIntoArray(struct Node* head, int* arr, int* size) {
    while (head) {
        arr[(*size)++] = head->data;
        head = head->next;
    }
}

int removeDuplicates(int* arr, int n) {
    if (n == 0) return 0;
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    return j + 1;
}

struct Node* createListFromArray(int* arr, int n) {
    if (n == 0) return NULL;
    struct Node* head = newNode(arr[0]);
    struct Node* temp = head;
    for (int i = 1; i < n; i++) {
        temp->next = newNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

struct Node* makeUnion(struct Node* head1, struct Node* head2) {
    int arr[1000], size = 0;

    insertIntoArray(head1, arr, &size);
    insertIntoArray(head2, arr, &size);

    qsort(arr, size, sizeof(int), compare);

    int newSize = removeDuplicates(arr, size);

    return createListFromArray(arr, newSize);
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* l1 = newNode(9);
    l1->next = newNode(6);
    l1->next->next = newNode(4);
    l1->next->next->next = newNode(2);
    l1->next->next->next->next = newNode(3);
    l1->next->next->next->next->next = newNode(8);

    struct Node* l2 = newNode(1);
    l2->next = newNode(2);
    l2->next->next = newNode(8);
    l2->next->next->next = newNode(6);
    l2->next->next->next->next = newNode(2);

    struct Node* result = makeUnion(l1, l2);

    printf("Union: ");
    printList(result);

    return 0;
}
