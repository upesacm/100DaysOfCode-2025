#include <stdio.h>

#define SIZE 100

typedef struct {
    int data[SIZE];
    int front, rear;
} Queue;

void enqueue(Queue *q, int val) {
    q->data[q->rear++] = val;
}

int queueSize(Queue *q) {
    return q->rear - q->front;
}

int main() {
    Queue q = {.front = 0, .rear = 0};
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);

    printf("%d\n", queueSize(&q));  // Output: 4

    return 0;
}
