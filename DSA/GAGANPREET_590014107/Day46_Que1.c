#include<stdio.h>
#include<limits.h>
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
int getMin(Queue *q) {
    int min = INT_MAX;
    int size = q->rear - q->front;
    for (int i = 0; i < size; i++) {
        int value = q->data[q->front + i];
        if (value < min) {
            min = value;
        }
    }
    return min;
}
int main() {
    Queue q;
    initQueue(&q);
    enqueue(&q, 4);
    enqueue(&q, 2);
    enqueue(&q, 7);
    enqueue(&q, 1);
    printf("%d\n", getMin(&q));
    return 0;
}
