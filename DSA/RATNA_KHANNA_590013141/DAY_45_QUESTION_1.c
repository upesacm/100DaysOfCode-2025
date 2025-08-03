#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue {
    int data[MAX];
    int front, rear;
};

void initQueue(struct Queue *q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue *q) {
    return q->front == -1;
}

int isFull(struct Queue *q) {
    return (q->rear + 1) % MAX == q->front;
}

void enqueue(struct Queue *q, int val) {
    if (isFull(q)) return;
    if (isEmpty(q)) q->front = 0;
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = val;
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) return -1;
    int val = q->data[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % MAX;
    return val;
}

int size(struct Queue *q) {
    if (isEmpty(q)) return 0;
    if (q->rear >= q->front) return q->rear - q->front + 1;
    return MAX - q->front + q->rear + 1;
}

int sumQueue(struct Queue *q) {
    int total = 0, n = size(q);
    for (int i = 0; i < n; i++) {
        int val = dequeue(q);
        total += val;
        enqueue(q, val);
    }
    return total;
}

int main() {
    struct Queue q;
    initQueue(&q);
    int n, x;
    printf("enter number of elements\n");
    scanf("%d", &n);
    printf("enter the elements\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(&q, x);
    }
    printf("%d\n", sumQueue(&q));
    return 0;
}
