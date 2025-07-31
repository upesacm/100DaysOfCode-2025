#include <stdio.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

int isFull(Queue *q) {
    return q->rear == MAX;
}

void enqueue(Queue *q, int value) {
    if (!isFull(q)) {
        q->data[q->rear++] = value;
    }
}

int dequeue(Queue *q) {
    if (!isEmpty(q)) {
        return q->data[q->front++];
    }
    return -1; 
}

int size(Queue *q) {
    return q->rear - q->front;
}

int sumQueue(Queue *q) {
    int n = size(q);
    int sum = 0;

    for (int i = 0; i < n; i++) {
        int val = dequeue(q);
        sum += val;
        enqueue(q, val);
    }

    return sum;
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    int total = sumQueue(&q);
    printf("Sum of elements in queue: %d\n", total);

    return 0;
}
