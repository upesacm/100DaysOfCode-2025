#include <stdio.h>
#define MAX 100

// Define the Queue structure
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

// Initialize a queue
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(Queue *q) {
    return q->front > q->rear;
}

// Enqueue operation
void enqueue(Queue *q, int value) {
    if (q->rear < MAX - 1) {
        q->items[++(q->rear)] = value;
    }
}

// Dequeue operation
int dequeue(Queue *q) {
    if (!isEmpty(q)) {
        return q->items[(q->front)++];
    }
    return -1; // Invalid value if queue is empty
}

// Get the size of a queue
int getSize(Queue *q) {
    return q->rear - q->front + 1;
}

// Compare two queues for equality
int compareQueues(Queue *q1, Queue *q2) {
    if (getSize(q1) != getSize(q2)) {
        return 0; // Sizes differ, not equal
    }

    int size = getSize(q1);
    int isEqual = 1;

    for (int i = 0; i < size; i++) {
        int val1 = dequeue(q1);
        int val2 = dequeue(q2);

        if (val1 != val2) {
            isEqual = 0; // Mismatch
        }

        // Re-enqueue to preserve original queue
        enqueue(q1, val1);
        enqueue(q2, val2);
    }

    return isEqual;
}

// Main function
int main() {
    Queue q1, q2;
    initQueue(&q1);
    initQueue(&q2);

    // Example 1: Equal queues
    enqueue(&q1, 1);
    enqueue(&q1, 2);
    enqueue(&q1, 3);

    enqueue(&q2, 1);
    enqueue(&q2, 2);
    enqueue(&q2, 3);

    if (compareQueues(&q1, &q2)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    // Example 2: Unequal queues
    initQueue(&q1);
    initQueue(&q2);

    enqueue(&q1, 1);
    enqueue(&q1, 2);

    enqueue(&q2, 2);
    enqueue(&q2, 1);

    if (compareQueues(&q1, &q2)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
