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

// Check if queue is empty
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
    return -1;
}

// Get size of queue
int getSize(Queue* q) {
    return q->rear - q->front + 1;
}

// Function to calculate sum without modifying the queue
int sumQueue(Queue* q) {
    int total = 0;
    int size = getSize(q);

    for (int i = 0; i < size; i++) {
        int val = dequeue(q);
        total += val;
        enqueue(q, val); // Restore the queue
    }

    return total;
}

// Main function
int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    int sum = sumQueue(&q);
    printf("Sum of queue elements: %d\n", sum);  // Output: 60

    return 0;
}
