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

int areQueuesEqual(struct Queue *q1, struct Queue *q2) {
    int n1 = size(q1);
    int n2 = size(q2);
    if (n1 != n2) return 0;

    int equal = 1;

    for (int i = 0; i < n1; i++) {
        int val1 = dequeue(q1);
        int val2 = dequeue(q2);
        if (val1 != val2) equal = 0;
        enqueue(q1, val1);
        enqueue(q2, val2);
    }

    return equal;
}

int main() {
    struct Queue q1, q2;
    initQueue(&q1);
    initQueue(&q2);

    int n, x;
    printf("enter number of elements in queue 1\n");
    scanf("%d", &n);
    printf("enter the elements in queue1\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(&q1, x);
    }
    printf("enter number of elements in queue 2\n");
    scanf("%d", &n);
    printf("enter the elements in queue2\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(&q2, x);
    }

    if (areQueuesEqual(&q1, &q2))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
