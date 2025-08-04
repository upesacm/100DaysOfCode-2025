#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

void enqueue(Queue* q, int val) {
    if ((q->rear + 1) % MAX == q->front) return;
    if (q->front == -1) q->front = 0;
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = val;
}

int dequeue(Queue* q) {
    if (q->front == -1) return -1;
    int val = q->data[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return val;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void mergeQueues(Queue* q1, Queue* q2) {
    if (isEmpty(q2)) return;
    int size = (q2->rear >= q2->front) ? (q2->rear - q2->front + 1) : (MAX - q2->front + q2->rear + 1);
    for (int i = 0; i < size; ++i) {
        int val = dequeue(q2);
        enqueue(q1, val);
    }
}

void printQueue(Queue* q) {
    if (isEmpty(q)) return;
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
    enqueue(&q1, 1);
    enqueue(&q1, 2);

    Queue q2;
    q2.front = -1;
    q2.rear = -1;
    enqueue(&q2, 3);
    enqueue(&q2, 4);

    mergeQueues(&q1, &q2);
    printQueue(&q1);

    Queue q3;
    q3.front = -1;
    q3.rear = -1;
    enqueue(&q3, 5);

    Queue q4;
    q4.front = -1;
    q4.rear = -1;
    enqueue(&q4, 6);
    enqueue(&q4, 7);

    mergeQueues(&q3, &q4);
    printQueue(&q3);

    return 0;
}
