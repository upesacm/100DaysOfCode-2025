#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
    int items[SIZE];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int value) {
    if (q->rear == SIZE - 1)
        return;
    if (isEmpty(q))
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q))
        return -1;
    int val = q->items[q->front];
    if (q->front == q->rear)
        initQueue(q);
    else
        q->front++;
    return val;
}

int findMax(Queue *q) {
    if (isEmpty(q))
        return -1;
    int max = -2147483648;
    Queue temp;
    initQueue(&temp);
    while (!isEmpty(q)) {
        int val = dequeue(q);
        if (val > max)
            max = val;
        enqueue(&temp, val);
    }
    while (!isEmpty(&temp))
        enqueue(q, dequeue(&temp));
    return max;
}

int main() {
    Queue q;
    initQueue(&q);
    int n, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }
    int result = findMax(&q);
    printf("Maximum element: %d\n", result);
    return 0;
}
