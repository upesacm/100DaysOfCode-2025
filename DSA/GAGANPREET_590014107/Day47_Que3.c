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
    queue->rear = -1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}
void enqueue(Queue* queue, int item) {
    if (queue->rear == queue->capacity - 1) {
        return;
    }
    queue->array[++queue->rear] = item;
}
void findFrontAndRear(Queue* queue) {
    if (queue->front > queue->rear) {
        printf("Queue is empty\n");
    } else {
        printf("Front: %d, Rear: %d\n", queue->array[queue->front], queue->array[queue->rear]);
    }
}
void printQueue(Queue* queue) {
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}
int main() {
    Queue* queue = createQueue(10);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    findFrontAndRear(queue);
    Queue* emptyQueue = createQueue(10);
    findFrontAndRear(emptyQueue);   
    free(queue->array);
    free(queue);
    free(emptyQueue->array);
    free(emptyQueue);
    return 0;
}
