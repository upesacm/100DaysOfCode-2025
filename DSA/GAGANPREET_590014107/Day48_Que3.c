#include<stdio.h>
#include<stdlib.h>
#define HASH_SIZE 1000
typedef struct Queue {
    int *array;
    int front;
    int rear;
    int capacity;
} Queue;
typedef struct Frequency {
    int value;
    int count;
} Frequency;
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = 0;
    queue->array = (int*)malloc(capacity * sizeof(int));
    return queue;
}
void enqueue(Queue* queue, int item) {
    if (queue->rear < queue->capacity) {
        queue->array[queue->rear++] = item;
    }
}
void countOccurrences(Queue* queue) {
    int hashTable[HASH_SIZE] = {0};
    for (int i = queue->front; i < queue->rear; i++) {
        int value = queue->array[i];
        if (value < 0) {
            value = -value;
        }
        if (value < HASH_SIZE) {
            hashTable[value]++;
        }
    }
    for (int i = 0; i < HASH_SIZE; i++) {
        if (hashTable[i] > 0) {
            printf("%d: %d\n", i, hashTable[i]);
        }
    }
}
void printQueue(Queue* queue) {
    for (int i = queue->front; i < queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}
int main() {
    Queue* queue = createQueue(10);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 1);
    enqueue(queue, 1);
    printf("Queue: ");
    printQueue(queue);
    printf("Frequency Distribution:\n");
    countOccurrences(queue);
    queue->front = 0;
    queue->rear = 0;
    enqueue(queue, 5);
    enqueue(queue, 5);
    enqueue(queue, 7);
    enqueue(queue, 8);
    enqueue(queue, 7);
    printf("Queue: ");
    printQueue(queue);
    printf("Frequency Distribution:\n");
    countOccurrences(queue);
    free(queue->array);
    free(queue);
    return 0;
}
