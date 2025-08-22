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

int isFull(struct Queue* q) {
    return q->rear == SIZE - 1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void insertFront(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }

    if (isEmpty(q)) {
        q->front = q->rear = 0;
        q->items[q->front] = value;
    } else {
        for (int i = q->rear + 1; i > q->front; i--) {
            q->items[i] = q->items[i - 1];
        }
        q->items[q->front] = value;
        q->rear++;
    }
}

void printQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);

    int n, value;

    printf("Enter number of elements in the queue: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        if (isEmpty(&q)) {
            q.front = q.rear = 0;
        } else {
            q.rear++;
        }
        q.items[q.rear] = value;
    }

    printf("Enter element to insert at front: ");
    scanf("%d", &value);
    insertFront(&q, value);

    printf("Updated Queue: ");
    printQueue(&q);

    return 0;
}
