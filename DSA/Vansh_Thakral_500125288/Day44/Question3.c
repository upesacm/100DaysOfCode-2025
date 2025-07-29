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

int main() {
    Queue q;
    initQueue(&q);

    printf("Is Queue Empty? %s\n", isEmpty(&q) ? "True" : "False");

    enqueue(&q, 5);
    enqueue(&q, 15);

    printf("Is Queue Empty? %s\n", isEmpty(&q) ? "True" : "False");

    return 0;
}

