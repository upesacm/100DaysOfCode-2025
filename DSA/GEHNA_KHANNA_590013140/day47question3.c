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

void findFrontRear(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front: %d, Rear: %d\n", q->items[q->front], q->items[q->rear]);
}

int main() {
    struct Queue q;
    initQueue(&q);
    int n, val;

    printf("Enter number of elements in the queue: ");
    scanf("%d", &n);

    if (n == 0) {
        findFrontRear(&q);
        return 0;
    }

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    findFrontRear(&q);

    return 0;
}
