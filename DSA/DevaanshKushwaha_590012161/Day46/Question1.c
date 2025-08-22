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

int findMin(Queue* q) {
    if (isEmpty(q)) return -1;
    int size = (q->rear >= q->front) ? (q->rear - q->front + 1) : (MAX - q->front + q->rear + 1);
    int min = q->data[q->front];
    for (int i = 0; i < size; ++i) {
        int val = dequeue(q);
        if (val < min) min = val;
        enqueue(q, val);
    }
    return min;
}

int main() {
    Queue q;
    q.front = -1;
    q.rear = -1;

    enqueue(&q, 4);
    enqueue(&q, 2);
    enqueue(&q, 7);
    enqueue(&q, 1);

    printf("%d\n", findMin(&q));

    Queue q2;
    q2.front = -1;
    q2.rear = -1;

    enqueue(&q2, 9);
    enqueue(&q2, 3);

    printf("%d\n", findMin(&q2));

    return 0;
}
