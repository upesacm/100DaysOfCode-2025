#include <stdio.h>
#define MAX 100

// Queue structure
typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

// Initialize the queue
void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Insert at rear (enqueue) — helper for testing
void insertAtRear(Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue is full. Cannot insert %d.\n", value);
        return;
    }

    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }

    q->data[q->rear] = value;
}

// Function to print front and rear
void printFrontAndRear(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Front: %d, Rear: %d\n", q->data[q->front], q->data[q->rear]);
    }
}

// Main for testing
int main() {
    Queue q;
    initializeQueue(&q);

    // Example 1
    insertAtRear(&q, 10);
    insertAtRear(&q, 20);
    insertAtRear(&q, 30);
    printFrontAndRear(&q); // Output: Front: 10, Rear: 30

    // Example 2 (empty queue)
    Queue q2;
    initializeQueue(&q2);
    printFrontAndRear(&q2); // Output: Queue is empty

    return 0;
}
