#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insert(struct Node* head, int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    if (!head) return temp;
    struct Node* curr = head;
    while (curr->next) curr = curr->next;
    curr->next = temp;
    return head;
}

void mergeArrays(int* arr, int n1, int* brr, int n2, int* res, int* size) {
    int temp[1000], count = 0;
    for (int i = 0; i < n1; i++) temp[count++] = arr[i];
    for (int i = 0; i < n2; i++) temp[count++] = brr[i];

    int freq[1001] = {0};
    for (int i = 0; i < count; i++) freq[temp[i]] = 1;

    for (int i = 0; i < 1001; i++) {
        if (freq[i]) {
            res[(*size)++] = i;
        }
    }
}

struct Node* makeUnion(struct Node* head1, struct Node* head2) {
    int a[1000], b[1000], c[2000], size = 0;
    int n1 = 0, n2 = 0;
    while (head1) {
        a[n1++] = head1->data;
        head1 = head1->next;
    }
    while (head2) {
        b[n2++] = head2->data;
        head2 = head2->next;
    }
    mergeArrays(a, n1, b, n2, c, &size);

    struct Node* res = NULL;
    for (int i = 0; i < size; i++) {
        res = insert(res, c[i]);
    }
    return res;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n1, n2, val;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        head1 = insert(head1, val);
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        head2 = insert(head2, val);
    }
    struct Node* res = makeUnion(head1, head2);
    printList(res);
    return 0;
}
