#include<stdio.h>
typedef struct Queue {
    int data[100];
    int front;
    int rear;
} Queue;
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}
int isEmpty(Queue *q) {
    return q->front == q->rear;
}
void enqueue(Queue *q, int value) {
    q->data[q->rear++] = value;
}
int dequeue(Queue *q) {
    return q->data[q->front++];
}
void countEvenOdd(Queue *q, int *evenCount, int *oddCount) {
    *evenCount = 0;
    *oddCount = 0;
    int size = q->rear - q->front;
    for (int i = 0; i < size; i++) {
        int value = q->data[q->front + i];
        if (value % 2 == 0) {
            (*evenCount)++;
        } else {
            (*oddCount)++;
        }
    }
}
int main() {
    Queue q;
    initQueue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    int evenCount, oddCount;
    countEvenOdd(&q, &evenCount, &oddCount);
    printf("Even: %d, Odd: %d\n", evenCount, oddCount);   
    return 0;
}