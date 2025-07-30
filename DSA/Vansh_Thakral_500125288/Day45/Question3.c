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

int findMaxInQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    int max = q->data[q->front];
    for (int i = q->front + 1; i <= q->rear; i++) {
        if (q->data[i] > max)
            max = q->data[i];
    }
    return max;
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 3);
    enqueue(&q, 5);
    enqueue(&q, 1);
    enqueue(&q, 2);

    printf("Maximum Element: %d\n", findMaxInQueue(&q));  

    return 0;
}

