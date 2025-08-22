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

// Check if queue is empty
int isEmpty(Queue* q) {
    return q->front > q->rear;
}

// Insert at rear
void enqueue(Queue* q, int value) {
    if (q->rear < MAX - 1) {
        q->items[++(q->rear)] = value;
    } else {
        printf("Queue is full.\n");
    }
}

// Retrieve front and rear elements
void getFrontAndRear(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Front: %d, Rear: %d\n", q->items[q->front], q->items[q->rear]);
    }
}

// Main to test
int main() {
    Queue q;
    initQueue(&q);

    // Test case 1
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    getFrontAndRear(&q);  // Output: Front: 10, Rear: 30

    // Test case 2
    Queue emptyQ;
    initQueue(&emptyQ);
    getFrontAndRear(&emptyQ);  // Output: Queue is empty

    return 0;
}

