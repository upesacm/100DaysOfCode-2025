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
void printQueue(Queue* queue) {
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}
int main() {
    Queue* queue = createQueue(10);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    printQueue(queue);   
    free(queue->array);
    free(queue);
    return 0;
}
