#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

void insertFront(Queue* q, int val) {
    if ((q->rear + 1) % MAX == q->front) return;
    if (q->front == -1) {
        q->front = 0;
        q->rear = 0;
        q->data[q->front] = val;
    } else {
        q->front = (q->front - 1 + MAX) % MAX;
        q->data[q->front] = val;
    }
}

void enqueue(Queue* q, int val) {
    if ((q->rear + 1) % MAX == q->front) return;
    if (q->front == -1) q->front = 0;
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = val;
}

void printQueue(Queue* q) {
    if (q->front == -1) return;
    int i = q->front;
    while (1) {
        printf("%d ", q->data[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Queue q1;
    q1.front = -1;
    q1.rear = -1;
    enqueue(&q1, 2);
    enqueue(&q1, 3);
    enqueue(&q1, 4);
    insertFront(&q1, 1);
    printQueue(&q1);

    Queue q2;
    q2.front = -1;
    q2.rear = -1;
    enqueue(&q2, 7);
    enqueue(&q2, 8);
    insertFront(&q2, 6);
    printQueue(&q2);

    return 0;
}
