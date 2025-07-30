// 2. Compare Two Queues
// A problem that demonstrates queue1 comparison algorithms and teaches element-by-element equality checking using systematic traversal methods for data structure validation and verification operations.

// Given two queues, check if they are identical in order and content through systematic comparison. This operation is fundamental in data validation and queue1 synchronization where you need to verify data consistency between different queue1 instances. The technique involves understanding parallel traversal methods that compare corresponding elements while maintaining queue1 structures. This concept is essential in testing frameworks, data replication, and quality assurance where queue1 equality verification ensures data integrity and system correctness across distributed or replicated queue1 systems.

// This introduces queue1 comparison algorithms and parallel traversal techniques that are crucial for data validation and efficient queue1 equality verification operations.

// Your task: Implement systematic queue1 comparison using parallel element traversal to verify complete structural and content equality between queue1 instances.

// Examples
// Input:

// Q1 = [1, 2, 3], Q2 = [1, 2, 3]
// Output:

// Yes
// Input:

// Q1 = [1, 2], Q2 = [2, 1]
// Output:

// No

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

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

bool isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

bool isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

bool areQueuesEqual(Queue* q1, Queue* q2) {
    if (q1->size != q2->size) {
        return false;
    }

    bool isEqual = true;
    int n = q1->size;

    for (int i = 0; i < n; i++) {
        int elem1 = dequeue(q1);
        int elem2 = dequeue(q2);

        if (elem1 != elem2) {
            isEqual = false;
        }

        enqueue(q1, elem1);
        enqueue(q2, elem2);
    }

    return isEqual;
}

void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("[]");
        return;
    }
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
    enqueue(q1, 1);
    enqueue(q1, 2);
    enqueue(q1, 3);

    Queue* q2 = createQueue(10);
    enqueue(q2, 1);
    enqueue(q2, 2);
    enqueue(q2, 3);
    
    printf("Input:\nQ1 = ");
    printQueue(q1);
    printf(", Q2 = ");
    printQueue(q2);
    printf("\n\nOutput:\n");
    if (areQueuesEqual(q1, q2)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    printf("\n-----------------------------------\n");


    Queue* q3 = createQueue(10);
    enqueue(q3, 1);
    enqueue(q3, 2);
    
    Queue* q4 = createQueue(10);
    enqueue(q4, 2);
    enqueue(q4, 1);

    printf("Input:\nQ1 = ");
    printQueue(q3);
    printf(", Q2 = ");
    printQueue(q4);
    printf("\n\nOutput:\n");
    if (areQueuesEqual(q3, q4)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    free(q1->array);
    free(q1);
    free(q2->array);
    free(q2);
    free(q3->array);
    free(q3);
    free(q4->array);
    free(q4);

    return 0;
}
