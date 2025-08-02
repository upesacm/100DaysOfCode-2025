#include <stdio.h>

#define SIZE 100

struct Queue {
    int items[SIZE];
    int front, rear;
};

void initQueue(struct Queue *q) {
    q->front = SIZE / 2;
    q->rear = SIZE / 2 - 1;
}

int isFullFront(struct Queue *q) {
    return q->front == 0;
}

int isFullRear(struct Queue *q) {
    return q->rear == SIZE - 1;
}

int isEmpty(struct Queue *q) {
    return q->front > q->rear;
}

void enqueueRear(struct Queue *q, int value) {
    if (isFullRear(q))
        return;
    q->items[++q->rear] = value;
}

void enqueueFront(struct Queue *q, int value) {
    if (isFullFront(q))
        return;
    q->items[--q->front] = value;
}

void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->items[i]);
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);
    int n, val, insert;

    printf("Enter number of elements in the queue: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueueRear(&q, val);
    }

    printf("Enter element to insert at front: ");
    scanf("%d", &insert);
    enqueueFront(&q, insert);

    printf("Updated Queue: ");
    display(&q);

    return 0;
}
