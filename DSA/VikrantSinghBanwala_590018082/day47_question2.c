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
void insertAtFront(Queue* queue, int item) {
    if (queue->rear == queue->capacity - 1) {
        return; 
    }
    for (int i = queue->rear; i >= queue->front; i--) {
        queue->array[i + 1] = queue->array[i];
    }
    queue->array[queue->front] = item;
    queue->rear++;
}
void printQueue(Queue* queue) {
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}
int main() {
    Queue* queue = createQueue(10);
    insertAtFront(queue, 2);
    insertAtFront(queue, 3);
    insertAtFront(queue, 4);
    insertAtFront(queue, 1); 
    printQueue(queue); 
    insertAtFront(queue, 6); 
    printQueue(queue);    
    free(queue->array);
    free(queue);
    return 0;
}