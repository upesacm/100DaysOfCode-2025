#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int k_node(struct Node* head, int k) {
    struct Node *first = head, *second = head;
    int i;
    for (i = 0; i < k; i++) {
        if (first == NULL)
            return -1;
        first = first->next;
    }
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }
    if (second != NULL)
        return second->data;
    else
        return -1;
}

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main() {
    int n, k, value;
    struct Node *head = NULL, *tail = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter linked list values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* temp = newNode(value);
        if (head == NULL)
            head = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    printf("Enter k: ");
    scanf("%d", &k);

    int result = k_node(head, k);
    printf("Output: %d\n", result);

    return 0;
}
