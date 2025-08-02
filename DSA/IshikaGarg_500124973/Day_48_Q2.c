#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define HASH_SIZE 1000  // For hash array size

// Queue structure
typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

// Initialize queue
void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

// Check if queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Check if queue is full
int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

// Enqueue operation
void enqueue(Queue *q, int val) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = val;
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

// Check if all elements in the queue are unique
int areAllUnique(Queue *q) {
    int hash[HASH_SIZE] = {0};  // Simple hash array for frequency

    for (int i = q->front; i <= q->rear; i++) {
        int val = q->data[i];
        if (hash[val] > 0) {
            return 0;  // Duplicate found
        }
        hash[val]++;
    }
    return 1;  // All elements unique
}

// Main function
int main() {
    Queue q;
    initQueue(&q);

    // Example 1: Unique Elements
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);

    printf("Queue: ");
    displayQueue(&q);
    printf("All elements unique? %s\n", areAllUnique(&q) ? "True" : "False");

    // Example 2: Duplicate Elements
    initQueue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 2);
    enqueue(&q, 3);

    printf("\nQueue: ");
    displayQueue(&q);
    printf("All elements unique? %s\n", areAllUnique(&q) ? "True" : "False");

    return 0;
}

