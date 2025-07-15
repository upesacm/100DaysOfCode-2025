#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

int kthFromEnd(struct Node* head, int k) {
    struct Node* fast = head;
    struct Node* slow = head;
    for (int i = 0; i < k; i++) {
        if (fast == NULL)
            return -1;
        fast = fast->next;
    }
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow ? slow->data : -1;
}

int main() {
    struct Node* head = NULL;
    int n, val, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&head, val);
    }
    scanf("%d", &k);
    printf("%d\n", kthFromEnd(head, k));
    return 0;
}
