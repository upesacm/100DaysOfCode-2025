#include<stdio.h>
#include<stdlib.h>
typedef struct Queue {
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
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}
int isEmpty(Queue* queue) {
    return (queue->size == 0);
}
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}
int dequeue(Queue* queue) {
    if (isEmpty(queue)) return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}
void reverseFirstKElements(Queue* queue, int k) {
    if (isEmpty(queue) || k <= 0 || k > queue->size) return;
    int* stack = (int*)malloc(k * sizeof(int));
    int top = -1;
    for (int i = 0; i < k; i++) {
        stack[++top] = dequeue(queue);
    }
    while (top != -1) {
        enqueue(queue, stack[top--]);
    }
    for (int i = 0; i < queue->size - k; i++) {
        enqueue(queue, dequeue(queue));
    }
    free(stack);
}
void printQueue(Queue* queue) {
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->array[(queue->front + i) % queue->capacity]);
    }
    printf("\n");
}
int main() {
    Queue* queue = createQueue(5);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    printf("Original Queue: ");
    printQueue(queue);
    int k = 3;
    reverseFirstKElements(queue, k);
    printf("Queue after reversing first %d elements: ", k);
    printQueue(queue);
    free(queue->array);
    free(queue);
    return 0;
}