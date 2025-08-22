#include <stdio.h>
#define MAX 100

// Define queue structure
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

// Initialize the queue
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

// Check if queue is full
int isFull(Queue* q) {
    return q->rear == MAX - 1;
}

// Check if queue is empty
int isEmpty(Queue* q) {
    return q->front > q->rear;
}

// Insert at rear (standard enqueue)
void insertRear(Queue* q, int value) {
    if (!isFull(q)) {
        q->items[++(q->rear)] = value;
    }
}

// Insert at front
void insertFront(Queue* q, int value) {
    if (q->front == 0 && q->rear != -1) {
        printf("No space to insert at front.\n");
        return;
    }

    // If queue is empty
    if (isEmpty(q)) {
        q->front = q->rear = 0;
        q->items[q->front] = value;
    } else {
        q->items[--(q->front)] = value;
    }
}

// Display queue elements
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
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

    // Test: Queue = [2, 3, 4], Insert 1 at front
    insertRear(&q, 2);
    insertRear(&q, 3);
    insertRear(&q, 4);
    insertFront(&q, 1);
    displayQueue(&q);  // Output: [1, 2, 3, 4]

    // Reset and try: Queue = [7, 8], Insert 6
    initQueue(&q);
    insertRear(&q, 7);
    insertRear(&q, 8);
    insertFront(&q, 6);
    displayQueue(&q);  // Output: [6, 7, 8]

    return 0;
}

