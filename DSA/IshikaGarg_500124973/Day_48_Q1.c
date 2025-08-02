#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Define the Queue structure
typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

// Initialize the queue
void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Check if the queue is full
int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

// Enqueue operation
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = value;
}

// Dequeue operation
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int removed = q->data[q->front];
    if (q->front == q->rear) {
        // Queue becomes empty
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return removed;
}

// Remove all occurrences of x from the queue
void removeAllOccurrences(Queue *q, int x) {
    Queue temp;
    initQueue(&temp);

    while (!isEmpty(q)) {
        int val = dequeue(q);
        if (val != x) {
            enqueue(&temp, val);
        }
    }

    // Copy elements back to original queue
    *q = temp;
}

// Display the queue
void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("[]\n");
        return;
    }
    printf("[");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d", q->data[i]);
        if (i != q->rear) printf(", ");
    }
    printf("]\n");
}

// Main function
int main() {
    Queue q;
    initQueue(&q);

    // Example 1
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 2);
    enqueue(&q, 4);

    printf("Original Queue: ");
    displayQueue(&q);

    int x = 2;
    removeAllOccurrences(&q, x);

    printf("Queue after removing %d: ", x);
    displayQueue(&q);

    // Example 2
    initQueue(&q);
    enqueue(&q, 5);
    enqueue(&q, 5);
    enqueue(&q, 5);

    printf("\nOriginal Queue: ");
    displayQueue(&q);

    x = 5;
    removeAllOccurrences(&q, x);

    printf("Queue after removing %d: ", x);
    displayQueue(&q);

    return 0;
}

