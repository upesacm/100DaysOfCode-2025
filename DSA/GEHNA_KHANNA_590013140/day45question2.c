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

int size(Queue *q) {
    if (isEmpty(q)) return 0;
    return q->rear - q->front + 1;
}

int compareQueues(Queue *q1, Queue *q2) {
    if (size(q1) != size(q2))
        return 0;
    Queue temp1, temp2;
    initQueue(&temp1);
    initQueue(&temp2);
    int equal = 1;
    while (!isEmpty(q1) && !isEmpty(q2)) {
        int v1 = dequeue(q1);
        int v2 = dequeue(q2);
        if (v1 != v2)
            equal = 0;
        enqueue(&temp1, v1);
        enqueue(&temp2, v2);
    }
    while (!isEmpty(&temp1))
        enqueue(q1, dequeue(&temp1));
    while (!isEmpty(&temp2))
        enqueue(q2, dequeue(&temp2));
    return equal;
}

int main() {
    Queue q1, q2;
    initQueue(&q1);
    initQueue(&q2);
    int n1, n2, val;
    printf("Enter number of elements in Queue 1: ");
    scanf("%d", &n1);
    printf("Enter %d elements:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        enqueue(&q1, val);
    }
    printf("Enter number of elements in Queue 2: ");
    scanf("%d", &n2);
    printf("Enter %d elements:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        enqueue(&q2, val);
    }
    if (compareQueues(&q1, &q2))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
