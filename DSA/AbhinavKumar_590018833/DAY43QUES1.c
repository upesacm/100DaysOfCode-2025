// 1. Reverse First K Elements of Queue
// A problem that demonstrates partial queue manipulation techniques and teaches selective element reversal using auxiliary data structures while preserving the First-In-First-Out principle for remaining elements.

// Given a queue and an integer k, reverse the first k elements of the queue while maintaining the order of the rest of the elements. This operation challenges traditional queue behavior by requiring selective modification of specific positions without disrupting the overall FIFO structure. The technique is fundamental in data stream processing and buffer management where you need to reorder specific segments while preserving the sequence of unaffected elements. Understanding this concept is crucial for packet processing, task scheduling, and priority queue modifications where partial reordering optimizes processing efficiency without complete restructuring.

// This teaches selective queue manipulation algorithms and partial reversal techniques that are essential for stream processing and efficient queue segment modification operations.

// Your task: Use auxiliary data structures to reverse the first k queue elements while maintaining FIFO order for the remaining elements.

// Examples
// Input:

// Queue = [1, 2, 3, 4, 5], k = 3
// Output:

// [3, 2, 1, 4, 5]
// Input:

// Queue = [10, 20, 30], k = 2
// Output:

// [20, 10, 30]

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* items;
    int front, rear, size, capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->items = (int*)malloc(q->capacity * sizeof(int));
    return q;
}

bool isFull(Queue* q) { return (q->size == q->capacity); }
bool isEmpty(Queue* q) { return (q->size == 0); }

void enqueue(Queue* q, int item) {
    if (isFull(q)) return;
    q->rear = (q->rear + 1) % q->capacity;
    q->items[q->rear] = item;
    q->size++;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) return -1;
    int item = q->items[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}

void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: [");
    for (int i = 0; i < q->size; i++) {
        printf("%d", q->items[(q->front + i) % q->capacity]);
        if (i < q->size - 1) printf(", ");
    }
    printf("]\n");
}

void reverseFirstK(Queue* q, int k) {
    if (q == NULL || k <= 0 || k > q->size) {
        printf("Invalid input or k is out of bounds.\n");
        return;
    }

    int* stack = (int*)malloc(k * sizeof(int));
    int top = -1;

    for (int i = 0; i < k; i++) {
        stack[++top] = dequeue(q);
    }

    while (top != -1) {
        enqueue(q, stack[top--]);
    }

    for (int i = 0; i < q->size - k; i++) {
        enqueue(q, dequeue(q));
    }
    
    free(stack);
}

int main() {
    printf("--- Example 1 ---\n");
    Queue* q1 = createQueue(10);
    enqueue(q1, 1);
    enqueue(q1, 2);
    enqueue(q1, 3);
    enqueue(q1, 4);
    enqueue(q1, 5);
    
    printf("Original ");
    printQueue(q1);
    
    reverseFirstK(q1, 3);
    
    printf("Modified ");
    printQueue(q1);
    
    printf("\n--- Example 2 ---\n");
    Queue* q2 = createQueue(10);
    enqueue(q2, 10);
    enqueue(q2, 20);
    enqueue(q2, 30);

    printf("Original ");
    printQueue(q2);

    reverseFirstK(q2, 2);

    printf("Modified ");
    printQueue(q2);

    free(q1->items);
    free(q1);
    free(q2->items);
    free(q2);
    
    return 0;
}