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

int isFull(struct Queue *q) {
    return q->rear == SIZE - 1;
}

int isEmpty(struct Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(struct Queue *q, int value) {
    if (isFull(q))
        return;
    if (q->front == -1)
        q->front = 0;
    q->items[++q->rear] = value;
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
        enqueue(&q, val);
    }

    printf("Enter element to insert at rear: ");
    scanf("%d", &insert);
    enqueue(&q, insert);

    printf("Updated Queue: ");
    display(&q);

    return 0;
}
