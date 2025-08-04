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
void mergeQueues(Queue *q1, Queue *q2) {
    int size = q2->rear - q2->front;
    for (int i = 0; i < size; i++) {
        enqueue(q1, q2->data[q2->front + i]);
    }
}
void printQueue(Queue *q) {
    for (int i = q->front; i < q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}
int main() {
    Queue q1, q2;
    initQueue(&q1);
    initQueue(&q2);
    enqueue(&q1, 1);
    enqueue(&q1, 2);
    enqueue(&q2, 3);
    enqueue(&q2, 4);
    mergeQueues(&q1, &q2);
    printQueue(&q1);   
    return 0;
}