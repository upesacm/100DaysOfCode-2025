
#include <stdio.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

void init(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

void enqueue(Queue* q, int value) {
    if (q->rear < MAX) {
        q->data[q->rear++] = value;
    }
}

int size(Queue* q) {
    return q->rear - q->front;
}

int main() {
    Queue q;
    init(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    printf("%d\n", size(&q));
    return 0;
}
