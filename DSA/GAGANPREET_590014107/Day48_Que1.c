#include<stdio.h>
#include<stdlib.h>
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
int dequeue(Queue* queue) {
    if (!isEmpty(queue)) {
        return queue->array[queue->front++];
    }
    return -1;
}
void removeOccurrences(Queue* queue, int x) {
    int newRear = 0;
    for (int i = queue->front; i < queue->rear; i++) {
        if (queue->array[i] != x) {
            queue->array[newRear++] = queue->array[i];
        }
    }
    queue->rear = newRear;
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
    enqueue(queue, 2);
    enqueue(queue, 4);
    printf("Original Queue: ");
    printQueue(queue);
    removeOccurrences(queue, 2);
    printf("Updated Queue: ");
    printQueue(queue);
    free(queue->array);
    free(queue);
    return 0;
}
