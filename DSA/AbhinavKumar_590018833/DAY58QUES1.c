#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// --- Data Structure & Helpers ---

typedef struct {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;

Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

bool isQueueEmpty(Queue* queue) { return (queue->size == 0); }
bool isQueueFull(Queue* queue) { return (queue->size == queue->capacity); }

void enqueue(Queue* queue, int item) {
    if (isQueueFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

void printQueue(const char* label, Queue* queue) {
    printf("%s", label);
    if (isQueueEmpty(queue)) {
        printf("[]\n");
        return;
    }
    printf("[");
    for (int i = 0; i < queue->size; i++) {
        int index = (queue->front + i) % queue->capacity;
        printf("%d", queue->array[index]);
        if (i < queue->size - 1) printf(", ");
    }
    printf("]\n");
}

// --- Core Logic ---

/**
 * Merges two queues into a new queue by taking elements alternately.
 * Note: This function consumes the input queues.
 */
Queue* mergeQueuesAlternately(Queue* q1, Queue* q2) {
    Queue* result = createQueue(q1->capacity + q2->capacity);
    while (!isQueueEmpty(q1) || !isQueueEmpty(q2)) {
        if (!isQueueEmpty(q1)) {
            enqueue(result, dequeue(q1));
        }
        if (!isQueueEmpty(q2)) {
            enqueue(result, dequeue(q2));
        }
    }
    return result;
}


int main() {
    Queue* q_a = createQueue(10);
    enqueue(q_a, 11);
    enqueue(q_a, 12);
    enqueue(q_a, 13);
    
    Queue* q_b = createQueue(10);
    enqueue(q_b, 91);
    enqueue(q_b, 92);
    enqueue(q_b, 93);
    enqueue(q_b, 94);
    
    printQueue("Queue A: ", q_a);
    printQueue("Queue B: ", q_b);
    
    Queue* merged = mergeQueuesAlternately(q_a, q_b);
    printQueue("Merged:  ", merged);
    printQueue("Queue A after merge: ", q_a);
    printQueue("Queue B after merge: ", q_b);

    // Free memory
    free(q_a->array);
    free(q_a);
    free(q_b->array);
    free(q_b);
    free(merged->array);
    free(merged);

    return 0;
}