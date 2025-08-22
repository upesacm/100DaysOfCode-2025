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

void printFrontRear(Queue* q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Front: %d, Rear: %d\n", q->data[q->front], q->data[q->rear]);
    }
}

int main() {
    Queue q1;
    q1.front = -1;
    q1.rear = -1;
    enqueue(&q1, 10);
    enqueue(&q1, 20);
    enqueue(&q1, 30);
    printFrontRear(&q1);

    Queue q2;
    q2.front = -1;
    q2.rear = -1;
    printFrontRear(&q2);

    return 0;
}
