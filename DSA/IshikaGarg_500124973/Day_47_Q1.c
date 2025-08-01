#include <stdio.h>
#define MAX 100

// Define the queue structure
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

// Check if the queue is full
int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Insert element at rear
void insertAtRear(Queue *q, int value) {
    if (isFull(q)) {
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

// Display the queue elements
void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: [");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d", q->data[i]);
        if (i < q->rear) printf(", ");
    }
    printf("]\n");
}

// Main function to test
int main() {
    Queue q;
    initializeQueue(&q);

    insertAtRear(&q, 1);
    insertAtRear(&q, 2);
    insertAtRear(&q, 3);
    displayQueue(&q);  // Output: [1, 2, 3]

    initializeQueue(&q);
    insertAtRear(&q, 4);
    insertAtRear(&q, 5);
    insertAtRear(&q, 6);
    displayQueue(&q);  // Output: [4, 5, 6]

    return 0;
}

