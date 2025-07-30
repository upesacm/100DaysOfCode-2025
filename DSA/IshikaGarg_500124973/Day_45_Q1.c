#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

int isFull(Queue *q) {
    return (q->rear + 1) % MAX == q->front;
}

void enqueue(Queue *q, int val) {
    if (isFull(q)) return;
    if (isEmpty(q))
        q->front = q->rear = 0;
    else
        q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = val;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) return -1;
    int val = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % MAX;
    return val;
}

int queueSize(Queue *q) {
    if (isEmpty(q)) return 0;
    if (q->rear >= q->front)
        return q->rear - q->front + 1;
    return MAX - q->front + q->rear + 1;
}

int sumQueue(Queue *q) {
    int sum = 0;
    int size = queueSize(q);
    for (int i = 0; i < size; i++) {
        int val = dequeue(q);
        sum += val;
        enqueue(q, val);  // Restore
    }
    return sum;
}

// Usage example
int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Sum: %d\n", sumQueue(&q)); // Output: 60
    return 0;
}

