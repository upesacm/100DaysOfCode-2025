 #include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int findKthFromEnd(struct Node* head, int k) {
    struct Node *first = head, *second = head;
    int count = 0;
    while (count < k) {
        if (first == NULL) return -1;
        first = first->next;
        count++;
    }
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }
    return second ? second->data : -1;
}

int main() {
    int n, val, k;
    struct Node *head = NULL, *tail = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &k);
    int result = findKthFromEnd(head, k);
    printf("%d\n", result);
    return 0;
}
