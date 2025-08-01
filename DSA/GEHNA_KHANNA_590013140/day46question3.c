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

void mergeQueues(struct Queue *q1, struct Queue *q2, struct Queue *merged) {
    for (int i = q1->front; i <= q1->rear; i++)
        enqueue(merged, q1->items[i]);
    for (int i = q2->front; i <= q2->rear; i++)
        enqueue(merged, q2->items[i]);
}

void display(struct Queue *q) {
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->items[i]);
    printf("\n");
}

int main() {
    struct Queue q1, q2, merged;
    initQueue(&q1);
    initQueue(&q2);
    initQueue(&merged);
    int n1, n2, val;

    printf("Enter number of elements in Queue 1: ");
    scanf("%d", &n1);
    printf("Enter elements in Queue 1:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        enqueue(&q1, val);
    }

    printf("Enter number of elements in Queue 2: ");
    scanf("%d", &n2);
    printf("Enter elements in Queue 2:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        enqueue(&q2, val);
    }

    mergeQueues(&q1, &q2, &merged);

    printf("Merged Queue: ");
    display(&merged);

    return 0;
}
