#include <stdio.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int front, rear;
} Queue;


void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}


int isEmpty(Queue *q) {
    return q->front > q->rear;
}


void enqueue(Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    q->data[++q->rear] = value;
}


int queueSize(Queue *q) {
    if (isEmpty(q)) return 0;
    return q->rear - q->front + 1;
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);

    printf("Queue Size: %d\n", queueSize(&q)); 

    return 0;
}

