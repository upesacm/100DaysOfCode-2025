#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define HASH_SIZE 1000  // Adjust as needed for input range

// Queue structure
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

// Count frequency of each element
void countFrequencies(Queue *q) {
    int hash[HASH_SIZE] = {0};  // Hash array for frequency counting

    // Count frequencies
    for (int i = q->front; i <= q->rear; i++) {
        int val = q->data[i];
        hash[val]++;
    }

    // Display frequency map
    printf("Frequency Distribution:\n{");
    int first = 1;
    for (int i = 0; i < HASH_SIZE; i++) {
        if (hash[i] > 0) {
            if (!first) printf(", ");
            printf("%d: %d", i, hash[i]);
            first = 0;
        }
    }
    printf("}\n");
}

// Main function
int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 1);
    enqueue(&q, 1);

    printf("Queue: ");
    displayQueue(&q);
    countFrequencies(&q);

    initQueue(&q);
    enqueue(&q, 5);
    enqueue(&q, 5);
    enqueue(&q, 7);
    enqueue(&q, 8);
    enqueue(&q, 7);

    printf("\nQueue: ");
    displayQueue(&q);
    countFrequencies(&q);

    return 0;
}

