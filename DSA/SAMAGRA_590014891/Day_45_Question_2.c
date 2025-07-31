#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front1 = NULL;
struct Node* rear1 = NULL;
struct Node* front2 = NULL;
struct Node* rear2 = NULL;

void enqueue(struct Node** front, struct Node** rear, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

bool compareQueues(struct Node* f1, struct Node* f2) {
    while (f1 != NULL && f2 != NULL) {
        if (f1->data != f2->data)
            return false;
        f1 = f1->next;
        f2 = f2->next;
    }
    return f1 == NULL && f2 == NULL;
}

int main() {
    int n1, n2, val;
    printf("Enter number of elements in Queue 1: ");
    scanf("%d", &n1);
    printf("Enter %d elements for Queue 1:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        enqueue(&front1, &rear1, val);
    }

    printf("Enter number of elements in Queue 2: ");
    scanf("%d", &n2);
    printf("Enter %d elements for Queue 2:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        enqueue(&front2, &rear2, val);
    }

    if (compareQueues(front1, front2))
        printf("Queues are identical.\n");
    else
        printf("Queues are not identical.\n");

    return 0;
}
