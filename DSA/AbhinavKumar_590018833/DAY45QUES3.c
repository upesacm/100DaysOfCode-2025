// . Find Maximum Element in a Queue
// A problem that teaches queue optimization techniques and demonstrates maximum value detection using efficient traversal algorithms for extremum finding in linear data structures.

// Given a queue of integers, find and return the maximum element present without altering the queue structure. This operation is fundamental in optimization problems and data analysis where you need to identify peak values within queue datasets. The technique requires understanding comparative traversal methods that track maximum values while processing queue elements sequentially. This concept is essential in performance monitoring, threshold detection, and data mining where maximum value identification enables decision making and analytical insights from queue-based data streams.

// This teaches extremum detection algorithms and comparative traversal techniques that are essential for optimization analysis and efficient maximum value identification in queue structures.

// Your task: Implement queue traversal with maximum tracking to identify the largest element while preserving queue state and maintaining efficiency.

// Examples
// Input:

// [3, 5, 1, 2]
// Output:

// 5
// Input:

// [10, 7, 4]
// Output:

// 10

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


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

bool isFull(Queue* queue) { return (queue->size == queue->capacity); }
bool isEmpty(Queue* queue) { return (queue->size == 0); }

void enqueue(Queue* queue, int item) {
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int findMaxInQueue(Queue* queue) {
    if (isEmpty(queue)) {
        fprintf(stderr, "Error: Queue is empty\n");
        return INT_MIN;
    }

    int max_element = INT_MIN;
    int n = queue->size;

    for (int i = 0; i < n; i++) {
        int current = dequeue(queue);

        if (current > max_element) {
            max_element = current;
        }

        enqueue(queue, current);
    }
    return max_element;
}

void printQueue(Queue* queue) {
    printf("[");
    for (int i = 0; i < queue->size; i++) {
        int index = (queue->front + i) % queue->capacity;
        printf("%d", queue->array[index]);
        if (i < queue->size - 1) {
            printf(", ");
        }
    }
    printf("]");
}

int main() {
    Queue* q1 = createQueue(10);
    enqueue(q1, 3);
    enqueue(q1, 5);
    enqueue(q1, 1);
    enqueue(q1, 2);

    printf("Input: ");
    printQueue(q1);
    printf("\n");
    
    int max1 = findMaxInQueue(q1);
    printf("Output: %d\n", max1);

    printf("Queue after operation: ");
    printQueue(q1); 
    printf("\n\n");
    
    Queue* q2 = createQueue(10);
    enqueue(q2, 10);
    enqueue(q2, 7);
    enqueue(q2, 4);

    printf("Input: ");
    printQueue(q2);
    printf("\n");
    
    int max2 = findMaxInQueue(q2);
    printf("Output: %d\n", max2);

    printf("Queue after operation: ");
    printQueue(q2); 
    printf("\n");

    free(q1->array);
    free(q1);
    free(q2->array);
    free(q2);

    return 0;
}