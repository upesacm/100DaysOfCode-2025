#include <stdio.h>

#define SIZE 100

struct Queue {
    int items[SIZE];
    int front, rear;
};

void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(struct Queue *q, int value) {
    if (q->rear == SIZE - 1)
        return;
    if (q->front == -1)
        q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(struct Queue *q) {
    if (isEmpty(q))
        return -1;
    return q->items[q->front++];
}

void countEvenOdd(struct Queue *q, int *even, int *odd) {
    *even = 0;
    *odd = 0;
    int count = q->rear - q->front + 1;
    for (int i = 0; i < count; i++) {
        int data = dequeue(q);
        if (data % 2 == 0)
            (*even)++;
        else
            (*odd)++;
        enqueue(q, data);
    }
    for (int i = 0; i < q->rear - q->front + 1; i++) {
        int temp = dequeue(q);
        enqueue(q, temp);
    }
}

int main() {
    struct Queue q;
    initQueue(&q);
    int n, val, even, odd;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }
    countEvenOdd(&q, &even, &odd);
    printf("Even: %d, Odd: %d\n", even, odd);
    return 0;
}
