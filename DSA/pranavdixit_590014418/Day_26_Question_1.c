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

struct Node* swapKthNode(struct Node* head, int k) {
    int count = 0;
    struct Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    if (k > count || 2 * k - 1 == count)
        return head;

    struct Node* x_prev = NULL;
    struct Node* x = head;
    for (int i = 1; i < k; i++) {
        x_prev = x;
        x = x->next;
    }

    struct Node* y_prev = NULL;
    struct Node* y = head;
    for (int i = 1; i < count - k + 1; i++) {
        y_prev = y;
        y = y->next;
    }

    if (x_prev)
        x_prev->next = y;
    if (y_prev)
        y_prev->next = x;

    struct Node* temp2 = x->next;
    x->next = y->next;
    y->next = temp2;

    if (k == 1)
        head = y;
    if (k == count)
        head = x;

    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    struct Node* head = createList(arr, 4);
    head = swapKthNode(head, 1);
    printList(head);  
    return 0;
}
