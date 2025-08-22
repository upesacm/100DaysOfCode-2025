#include<stdio.h>
#include<stdlib.h>
#define HASH_SIZE 1000
typedef struct Queue {
    int *array;
    int front;
    int rear;
    int capacity;
} Queue;
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = 0;
    queue->array = (int*)malloc(capacity * sizeof(int));
    return queue;
}
int isEmpty(Queue* queue) {
    return queue->front == queue->rear;
}
void enqueue(Queue* queue, int item) {
    if (queue->rear < queue->capacity) {
        queue->array[queue->rear++] = item;
    }
}
int checkUnique(Queue* queue) {
    int hashTable[HASH_SIZE] = {0};
    for (int i = queue->front; i < queue->rear; i++) {
        int value = queue->array[i];
        if (value < 0) {
            value = -value;
        }
        if (value >= HASH_SIZE) {
            return 0;
        }
        if (hashTable[value] > 0) {
            return 0;
        }
        hashTable[value]++;
    }
    return 1;
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
    enqueue(queue, 3);
    enqueue(queue, 4);
    printf("Queue: ");
    printQueue(queue);
    printf("All elements unique: %s\n", checkUnique(queue) ? "True" : "False");
    queue->front = 0;
    queue->rear = 0;
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 2);
    enqueue(queue, 3);
    printf("Queue: ");
    printQueue(queue);
    printf("All elements unique: %s\n", checkUnique(queue) ? "True" : "False");
    free(queue->array);
    free(queue);
    return 0;
}
