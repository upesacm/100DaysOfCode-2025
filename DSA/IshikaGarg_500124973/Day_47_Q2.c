#include <stdio.h>
#define MAX 100

// Queue structure definition
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

// Insert element at front
void insertAtFront(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot insert at front.\n");
        return;
    }

    if (isEmpty(q)) {
        q->front = q->rear = 0;
        q->data[q->front] = value;
    } else if (q->front > 0) {
        q->front--; // Space available before current front
        q->data[q->front] = value;
    } else {
        // Shift all elements right to make space at front
        for (int i = q->rear; i >= q->front; i--) {
            q->data[i + 1] = q->data[i];
        }
        q->rear++;
        q->data[q->front] = value;
    }
}

// Display the queue
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

// Main to test
int main() {
    Queue q;
    initializeQueue(&q);

    // Example 1
    insertAtFront(&q, 4);
    insertAtFront(&q, 3);
    insertAtFront(&q, 2);
    insertAtFront(&q, 1);
    displayQueue(&q);  // Output: [1, 2, 3, 4]

    // Reset and try second example
    initializeQueue(&q);
    insertAtFront(&q, 8);
    insertAtFront(&q, 7);
    insertAtFront(&q, 6);
    displayQueue(&q);  // Output: [6, 7, 8]

    return 0;
}

