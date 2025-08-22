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

void removeAllOccurrences(Queue* q, int x) {
    if (isEmpty(q)) return;
    int size = (q->rear >= q->front) ? (q->rear - q->front + 1) : (MAX - q->front + q->rear + 1);
    for (int i = 0; i < size; ++i) {
        int val = dequeue(q);
        if (val != x) enqueue(q, val);
    }
}

void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("[]\n");
        return;
    }
    printf("[");
    int i = q->front;
    while (1) {
        printf("%d", q->data[i]);
        if (i == q->rear) break;
        printf(", ");
        i = (i + 1) % MAX;
    }
    printf("]\n");
}

int main() {
    Queue q1;
    q1.front = -1;
    q1.rear = -1;
    enqueue(&q1, 1);
    enqueue(&q1, 2);
    enqueue(&q1, 3);
    enqueue(&q1, 2);
    enqueue(&q1, 4);
    removeAllOccurrences(&q1, 2);
    printQueue(&q1);

    Queue q2;
    q2.front = -1;
    q2.rear = -1;
    enqueue(&q2, 5);
    enqueue(&q2, 5);
    enqueue(&q2, 5);
    removeAllOccurrences(&q2, 5);
    printQueue(&q2);

    return 0;
}
