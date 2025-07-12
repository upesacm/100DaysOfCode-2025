#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void insert(struct Node** head_ref, int data) {
    struct Node* temp = newNode(data);
    temp->next = *head_ref;
    *head_ref = temp;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

struct Node* makeUnion(struct Node* head1, struct Node* head2) {
    int arr[1000], n = 0;
    struct Node *temp = head1, *unionList = NULL;

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

    int last = -1;
    for (int i = 0; i < n; i++) {
        if (i == 0 || arr[i] != last) {
            struct Node* new_node = newNode(arr[i]);
            if (!unionList) {
                unionList = new_node;
                temp = unionList;
            } else {
                temp->next = new_node;
                temp = temp->next;
            }
            last = arr[i];
        }
    }
    return unionList;
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

    struct Node* unionList = makeUnion(L1, L2);
    printList(unionList);

    return 0;
}
