#include <stdio.h>

#define MAX 100

// Define the Queue structure
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

// Function to enqueue elements
void enqueue(Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    q->items[++(q->rear)] = value;
}

// Function to calculate size of the queue
int size(Queue *q) {
    if (q->rear < q->front)
        return 0;  // Queue is empty
    return (q->rear - q->front + 1);
}

// Example usage
int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);

    printf("Size of queue: %d\n", size(&q));  // Output: 4

    return 0;
}
