#include <stdio.h>
#include <limits.h>

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

int findMinimum(struct Queue *q) {
    if (isEmpty(q))
        return -1;

    int min = INT_MAX;
    int count = q->rear - q->front + 1;

    for (int i = 0; i < count; i++) {
        int data = dequeue(q);
        if (data < min)
            min = data;
        enqueue(q, data);
    }

    for (int i = 0; i < q->rear - q->front + 1; i++) {
        int temp = dequeue(q);
        enqueue(q, temp);
    }

    return min;
}

int main() {
    struct Queue q;
    initQueue(&q);
    int n, val;
    printf("Enter no. of elements in queue\n ");
    scanf("%d", &n);
    printf("Enter elements \n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }
    printf("Minimum element %d\n", findMinimum(&q));
    return 0;
}
