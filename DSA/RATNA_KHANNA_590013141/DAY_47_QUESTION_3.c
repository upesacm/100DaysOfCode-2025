#include <stdio.h>
#define SIZE 100

struct Queue {
    int items[SIZE];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

void getFrontAndRear(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Front: %d, Rear: %d\n", q->items[q->front], q->items[q->rear]);
    }
}

int main() {
    struct Queue q;
    initQueue(&q);

    int n, value;

    printf("Enter number of elements in the queue: ");
    scanf("%d", &n);

    if (n == 0) {
        getFrontAndRear(&q);
        return 0;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(&q, value);
    }

    getFrontAndRear(&q);

    return 0;
}
