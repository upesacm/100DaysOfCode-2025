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

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % SIZE;
    }
    return value;
}

void displayQueue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    struct Queue temp;
    initQueue(&temp);

    int count = (q->rear >= q->front) ? (q->rear - q->front + 1)
                                      : (SIZE - q->front + q->rear + 1);

    for (int i = 0; i < count; ++i) {
        int val = dequeue(q);
        printf("%d ", val);
        enqueue(&temp, val);
    }
    printf("\n");

    for (int i = 0; i < count; ++i) {
        enqueue(q, dequeue(&temp));
    }
}

int main() {
    struct Queue q;
    initQueue(&q);

    int n, value;
    printf("Enter number of elements to enqueue: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &value);
        enqueue(&q, value);
    }

    printf("Queue elements (front to rear):\n");
    displayQueue(&q);

    return 0;
}
