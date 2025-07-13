#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Utility function to create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Utility function to print the list
void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Append node to end of list
void append(struct Node** head_ref, int new_data) {
    struct Node* temp = newNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = temp;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next) last = last->next;
    last->next = temp;
}

// 1. Swap Kth Nodes from Ends
void swapKth(struct Node** head_ref, int k) {
    int n = 0;
    struct Node* temp = *head_ref;
    while (temp) {
        n++;
        temp = temp->next;
    }
    if (k > n) return;
    if (2 * k - 1 == n) return;

    struct Node *x = *head_ref, *x_prev = NULL;
    for (int i = 1; i < k; i++) {
        x_prev = x;
        x = x->next;
    }

    struct Node *y = *head_ref, *y_prev = NULL;
    for (int i = 1; i < n - k + 1; i++) {
        y_prev = y;
        y = y->next;
    }

    if (x_prev) x_prev->next = y;
    if (y_prev) y_prev->next = x;

    struct Node* temp_ptr = x->next;
    x->next = y->next;
    y->next = temp_ptr;

    if (k == 1) *head_ref = y;
    if (k == n) *head_ref = x;
}

// 2. Union of Two Linked Lists
int exists(struct Node* head, int val) {
    while (head) {
        if (head->data == val) return 1;
        head = head->next;
    }
    return 0;
}

struct Node* makeUnion(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL;
    struct Node* temp = head1;

    // Add all unique elements from head1
    while (temp) {
        if (!exists(result, temp->data)) append(&result, temp->data);
        temp = temp->next;
    }

    // Add all unique elements from head2
    temp = head2;
    while (temp) {
        if (!exists(result, temp->data)) append(&result, temp->data);
        temp = temp->next;
    }

    // Sort result list using Bubble Sort (for simplicity)
    struct Node *i, *j;
    for (i = result; i && i->next; i = i->next) {
        for (j = i->next; j; j = j->next) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    return result;
}

// 3. Sort linked list of 0s, 1s and 2s
void sort012(struct Node* head) {
    int count[3] = {0, 0, 0};
    struct Node* temp = head;

    // Count 0s, 1s and 2s
    while (temp) {
        count[temp->data]++;
        temp = temp->next;
    }

    temp = head;
    int i = 0;
    while (temp) {
        if (count[i] == 0)
            ++i;
        else {
            temp->data = i;
            --count[i];
            temp = temp->next;
        }
    }
}
