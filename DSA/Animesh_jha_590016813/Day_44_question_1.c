#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }

    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    int value = q->data[q->front];

    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }

    return value;
}

void displayQueue(Queue *q) {
    Queue temp;
    initQueue(&temp);

    while (!isEmpty(q)) {
        int val = dequeue(q);
        printf("%d ", val);
        enqueue(&temp, val);
    }

    while (!isEmpty(&temp)) {
        enqueue(q, dequeue(&temp));
    }
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Queue elements: ");
    displayQueue(&q);

    return 0;
}
