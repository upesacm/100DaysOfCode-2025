#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

bool isQueueEmpty() {
    return front == NULL;
}

void displayQueue() {
    struct Node* temp = front;
    if (isQueueEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, value;

    if (isQueueEmpty())
        printf("Initially: Queue is empty: true\n");

    printf("Enter number of elements to enqueue: ");
    scanf("%d", &n);

    printf("Enter %d element(s):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    printf("Queue elements: ");
    displayQueue();

    if (isQueueEmpty())
        printf("Queue is empty: true\n");
    else
        printf("Queue is empty: false\n");

    return 0;
}
