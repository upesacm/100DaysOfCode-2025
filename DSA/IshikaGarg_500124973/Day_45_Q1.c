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

// Enqueue
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->items[++q->rear] = value;
}

// Dequeue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

// Function to calculate sum without modifying queue
int sumQueue(Queue *q) {
    int sum = 0;
    int n = q->rear - q->front + 1;

    for (int i = 0; i < n; i++) {
        int val = dequeue(q);   // Remove element
        sum += val;             // Add to sum
        enqueue(q, val);        // Put it back
    }
    return sum;
}

// Driver code
int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    int total = sumQueue(&q);
    printf("Sum: %d\n", total);  // Output: 6

    return 0;
}
