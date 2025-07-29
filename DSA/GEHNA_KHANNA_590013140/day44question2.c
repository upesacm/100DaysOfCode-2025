#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

struct Queue {
    int items[SIZE];
    int front;
    int rear;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

int isFull(struct Queue* q) {
    return q->rear == SIZE - 1;
}

void enqueue(struct Queue* q, int value) {
    if (isFull(q)) return;
    if (isEmpty(q)) q->front = 0;
    q->items[++q->rear] = value;
}

int getSize(struct Queue* q) {
    if (isEmpty(q)) return 0;
    return q->rear - q->front + 1;
}

int main() {
    struct Queue q;
    initQueue(&q);
    int n, val;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }
    printf("%d\n", getSize(&q));
    return 0;
}
