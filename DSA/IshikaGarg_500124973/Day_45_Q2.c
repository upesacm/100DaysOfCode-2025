#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
    int items[SIZE];
    int front;
    int rear;
} Queue;

// Initialize queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Check if queue is full
int isFull(Queue *q) {
    return q->rear == SIZE - 1;
}

// Enqueue operation
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(q))
        q->front = 0;
    q->items[++q->rear] = value;
}

// Dequeue operation
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return item;
}

// Get number of elements in queue
int size(Queue *q) {
    if (isEmpty(q))
        return 0;
    return q->rear - q->front + 1;
}

// Compare two queues
const char* compareQueues(Queue *q1, Queue *q2) {
    if (size(q1) != size(q2))
        return "No";

    int n = size(q1);
    int match = 1;

    for (int i = 0; i < n; i++) {
        int val1 = dequeue(q1);
        int val2 = dequeue(q2);

        if (val1 != val2)
            match = 0;

        enqueue(q1, val1);  // Restore
        enqueue(q2, val2);  // Restore
    }

    return match ? "Yes" : "No";
}

// Driver code
int main() {
    Queue q1, q2;
    initQueue(&q1);
    initQueue(&q2);

    // Test case 1
    enqueue(&q1, 1);
    enqueue(&q1, 2);
    enqueue(&q1, 3);

    enqueue(&q2, 1);
    enqueue(&q2, 2);
    enqueue(&q2, 3);

    printf("Are queues equal? %s\n", compareQueues(&q1, &q2)); 

    // Test case 2
    initQueue(&q1);
    initQueue(&q2);

    enqueue(&q1, 1);
    enqueue(&q1, 2);

    enqueue(&q2, 2);
    enqueue(&q2, 1);

    printf("Are queues equal? %s\n", compareQueues(&q1, &q2));

    return 0;
}

