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

void countEvenOdd(Queue* q, int* even, int* odd) {
    *even = 0;
    *odd = 0;
    if (isEmpty(q)) return;
    int size = (q->rear >= q->front) ? (q->rear - q->front + 1) : (MAX - q->front + q->rear + 1);
    for (int i = 0; i < size; ++i) {
        int val = dequeue(q);
        if (val % 2 == 0) (*even)++;
        else (*odd)++;
        enqueue(q, val);
    }
}

int main() {
    Queue q1;
    q1.front = -1;
    q1.rear = -1;
    enqueue(&q1, 1);
    enqueue(&q1, 2);
    enqueue(&q1, 3);
    enqueue(&q1, 4);
    enqueue(&q1, 5);
    int even1, odd1;
    countEvenOdd(&q1, &even1, &odd1);
    printf("Even: %d, Odd: %d\n", even1, odd1);

    Queue q2;
    q2.front = -1;
    q2.rear = -1;
    enqueue(&q2, 6);
    enqueue(&q2, 8);
    enqueue(&q2, 10);
    int even2, odd2;
    countEvenOdd(&q2, &even2, &odd2);
    printf("Even: %d, Odd: %d\n", even2, odd2);

    return 0;
}
