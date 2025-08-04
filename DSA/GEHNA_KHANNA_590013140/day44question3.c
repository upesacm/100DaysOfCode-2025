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

void enqueue(struct Queue* q, int value) {
    if (q->rear == SIZE - 1) return;
    if (isEmpty(q)) q->front = 0;
    q->items[++q->rear] = value;
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
    if (isEmpty(&q))
        printf("True\n");
    else
        printf("False\n");
    return 0;
}
