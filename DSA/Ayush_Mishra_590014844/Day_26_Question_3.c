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

struct Node* sortList(struct Node* head) {
    int count[3] = {0};
    struct Node* curr = head;
    while (curr) {
        count[curr->data]++;
        curr = curr->next;
    }
    curr = head;
    for (int i = 0; i < 3; i++) {
        while (count[i]--) {
            curr->data = i;
            curr = curr->next;
        }
    }
    return head;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, val;
    struct Node* head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = insert(head, val);
    }
    head = sortList(head);
    printList(head);
    return 0;
}
