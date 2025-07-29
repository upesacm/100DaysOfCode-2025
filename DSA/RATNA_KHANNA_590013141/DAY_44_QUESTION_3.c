#include <stdio.h>
#define SIZE 100

struct Queue {
    int data[SIZE];
    int front;
    int rear;
};

void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue *q) {
    return q->front == -1;
}

int isFull(struct Queue *q) {
    return (q->rear + 1) % SIZE == q->front;
}

void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % SIZE;
    q->data[q->rear] = value;
}

int main() {
    struct Queue q;
    initQueue(&q);

    int n, value;
    printf("Enter number of elements to enqueue: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("Output: True\n");
        return 0;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &value);
        enqueue(&q, value);
    }

    if (isEmpty(&q))
        printf("Output: True\n");
    else
        printf("Output: False\n");

    return 0;
}
