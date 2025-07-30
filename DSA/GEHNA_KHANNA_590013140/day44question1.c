#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

struct Queue {
    int items[SIZE];
    int front;
    int rear;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

int isFull(struct Queue* q) {
    return q->rear == SIZE - 1;
}

void enqueue(struct Queue* q, int value) {
    if (isFull(q)) return;
    if (isEmpty(q)) q->front = 0;
    q->items[++q->rear] = value;
}

void displayQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);
    int n, val;
    printf("enter no. of elements in queue\n");
    scanf("%d", &n);
    printf("enter elements\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }
    displayQueue(&q);
    return 0;
}
