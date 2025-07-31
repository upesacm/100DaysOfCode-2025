#include <stdio.h>
#define MAX 100

// Queue structure
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

// Initialize queue
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

// Check if queue is full
int isFull(Queue* q) {
    return q->rear == MAX - 1;
}

// Insert at rear (Enqueue)
void insertRear(Queue* q, int value) {
    if (!isFull(q)) {
        q->items[++(q->rear)] = value;
    } else {
        printf("Queue is full. Cannot insert.\n");
    }
}

// Display queue elements
void displayQueue(Queue* q) {
    if (q->front > q->rear) {
        printf("Queue is empty.\n");
        return;
    }

    printf("[");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d", q->items[i]);
        if (i < q->rear) printf(", ");
    }
    printf("]\n");
}

// Main to test
int main() {
    Queue q;
    initQueue(&q);

    // Example 1: [1, 2], insert 3
    insertRear(&q, 1);
    insertRear(&q, 2);
    insertRear(&q, 3);
    displayQueue(&q);  // Output: [1, 2, 3]

    // Reset and test again
    initQueue(&q);
    insertRear(&q, 4);
    insertRear(&q, 5);
    insertRear(&q, 6);
    displayQueue(&q);  // Output: [4, 5, 6]

    return 0;
}

