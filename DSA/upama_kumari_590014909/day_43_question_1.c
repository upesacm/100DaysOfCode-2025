#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue {
    int items[MAX];
    int front, rear;
};

void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue *q) {
    return q->front == -1;
}
void enqueue(struct Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q))
        q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        exit(1);
    }
    int item = q->items[q->front++];
    if (q->front > q->rear)
        initQueue(q);
    return item;
}

void display(struct Queue q) {
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d ", q.items[i]);
    }
    printf("\n");
}

void reverseFirstK(struct Queue *q, int k) {
    int stack[MAX], top = -1;

    for (int i = 0; i < k; i++) {
        stack[++top] = dequeue(q);
    }

    while (top >= 0) {
        enqueue(q, stack[top--]);
    }

    int size = q->rear - q->front + 1;
    for (int i = 0; i < size - k; i++) {
        enqueue(q, dequeue(q));
    }
}

int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    int k = 3;

    printf("Original Queue: ");
    display(q);

    reverseFirstK(&q, k);

    printf("Modified Queue: ");
    display(q);

    return 0;
}
