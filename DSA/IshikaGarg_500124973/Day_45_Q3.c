#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
    int items[SIZE];
    int front;
    int rear;
} Queue;

// Initialize queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Check if queue is full
int isFull(Queue *q) {
    return q->rear == SIZE - 1;
}

// Enqueue operation
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(q))
        q->front = 0;
    q->items[++q->rear] = value;
}

// Dequeue operation
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return item;
}

// Get number of elements in the queue
int size(Queue *q) {
    if (isEmpty(q))
        return 0;
    return q->rear - q->front + 1;
}

// Find maximum element without altering queue
int findMax(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    int maxVal = -2147483648;  // Minimum value for int
    int n = size(q);

    for (int i = 0; i < n; i++) {
        int val = dequeue(q);
        if (val > maxVal)
            maxVal = val;
        enqueue(q, val);  // Restore original state
    }

    return maxVal;
}

// Driver code
int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 3);
    enqueue(&q, 5);
    enqueue(&q, 1);
    enqueue(&q, 2);

    printf("Maximum element: %d\n", findMax(&q));  // Output: 5

    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 7);
    enqueue(&q, 4);

    printf("Maximum element: %d\n", findMax(&q));  // Output: 10

    return 0;
}

