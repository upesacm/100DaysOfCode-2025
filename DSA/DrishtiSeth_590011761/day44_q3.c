
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

int is_empty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, int value) {
    if (q->rear < MAX) {
        q->data[q->rear++] = value;
    }
}

int main() {
    Queue q;
    init(&q);
    printf("%d\n", is_empty(&q));
    enqueue(&q, 1);
    printf("%d\n", is_empty(&q));
    return 0;
}
