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


void enqueue(Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    q->data[++q->rear] = value;
}

int compareQueues(Queue *q1, Queue *q2) {
    int size1 = q1->rear - q1->front + 1;
    int size2 = q2->rear - q2->front + 1;

    if (size1 != size2)
        return 0;  

    for (int i = 0; i < size1; i++) {
        if (q1->data[q1->front + i] != q2->data[q2->front + i])
            return 0;  
    }
    return 1;  
}

int main() {
    Queue q1, q2;
    initQueue(&q1);
    initQueue(&q2);

    enqueue(&q1, 1);
    enqueue(&q1, 2);
    enqueue(&q1, 3);

    enqueue(&q2, 1);
    enqueue(&q2, 2);
    enqueue(&q2, 3);

    if (compareQueues(&q1, &q2))
        printf("Queues are identical\n");
    else
        printf("Queues are different\n");

    return 0;
}

