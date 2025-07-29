#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Queue {
    int front, rear, size;
    unsigned capacity;
    char** array;
} Queue;
Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (char**)malloc(queue->capacity * sizeof(char*));
    return queue;
}
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}
int isEmpty(Queue* queue) {
    return (queue->size == 0);
}
void enqueue(Queue* queue, const char* item) {
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = strdup(item);
    queue->size++;
}
char* dequeue(Queue* queue) {
    if (isEmpty(queue)) return NULL;
    char* item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}
void generateBinaryNumbers(int n) {
    Queue* queue = createQueue(n);
    enqueue(queue, "1");
    for (int i = 1; i <= n; i++) {
        char* binary = dequeue(queue);
        printf("%s\n", binary);
        char zero[100], one[100];
        sprintf(zero, "%s0", binary);
        sprintf(one, "%s1", binary);
        enqueue(queue, zero);
        enqueue(queue, one);
        free(binary);
    }
    free(queue->array);
    free(queue);
}
int main() {
    int n = 5;
    printf("Binary numbers from 1 to %d:\n", n);
    generateBinaryNumbers(n);
    return 0;
}