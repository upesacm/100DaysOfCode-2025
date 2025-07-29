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

// Function to enqueue an element
void enqueue(Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    q->items[++(q->rear)] = value;
}

// Function to display elements without modifying the queue
void displayQueue(Queue q) {
    if (q.front > q.rear) {
        printf("Queue is empty\n");
        return;
    }

    for (int i = q.front; i <= q.rear; i++) {
        printf("%d ", q.items[i]);
    }
    printf("\n");
}

// Example usage
int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Queue elements:\n");
    displayQueue(q);  // Pass by value to preserve original queue

    return 0;
}
