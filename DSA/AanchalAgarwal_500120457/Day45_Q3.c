#include <stdio.h>
#define MAX 100

// Define the Queue structure
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

// Initialize the queue
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front > q->rear;
}

// Enqueue operation
void enqueue(Queue* q, int value) {
    if (q->rear < MAX - 1) {
        q->items[++(q->rear)] = value;
    }
}

// Dequeue operation
int dequeue(Queue* q) {
    if (!isEmpty(q)) {
        return q->items[(q->front)++];
    }
    return -1; // Sentinel for empty queue
}

// Get the current size of the queue
int getSize(Queue* q) {
    return q->rear - q->front + 1;
}

// Function to find the maximum element in the queue
int findMaxInQueue(Queue* q) {
    int max = -2147483648; // Smallest integer
    int size = getSize(q);

    for (int i = 0; i < size; i++) {
        int val = dequeue(q);
        if (val > max) {
            max = val;
        }
        enqueue(q, val); // Restore original structure
    }

    return max;
}

// Main function to demonstrate
int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 3);
    enqueue(&q, 5);
    enqueue(&q, 1);
    enqueue(&q, 2);

    int max = findMaxInQueue(&q);
    printf("Maximum element in the queue: %d\n", max);  // Output: 5

    return 0;
}
