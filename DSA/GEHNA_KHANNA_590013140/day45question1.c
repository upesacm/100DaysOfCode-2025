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
    int value = q->items[q->front];
    if (q->front == q->rear)
        initQueue(q);
    else
        q->front++;
    return value;
}

int sumQueue(Queue *q) {
    int sum = 0;
    Queue temp;
    initQueue(&temp);
    while (!isEmpty(q)) {
        int val = dequeue(q);
        sum += val;
        enqueue(&temp, val);
    }
    while (!isEmpty(&temp)) {
        enqueue(q, dequeue(&temp));
    }
    return sum;
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
    int result = sumQueue(&q);
    printf("Sum of queue elements: %d\n", result);
    return 0;
}
