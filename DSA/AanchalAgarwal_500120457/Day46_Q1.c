#include <stdio.h>
#define MAX 100

typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front > q->rear;
}

void enqueue(Queue* q, int value) {
    if (q->rear < MAX - 1) {
        q->items[++(q->rear)] = value;
    }
}

int dequeue(Queue* q) {
    if (!isEmpty(q)) {
        return q->items[(q->front)++];
    }
    return -1;
}

int getSize(Queue* q) {
    return q->rear - q->front + 1;
}

int findMinInQueue(Queue* q) {
    int min = 2147483647;
    int size = getSize(q);

    for (int i = 0; i < size; i++) {
        int val = dequeue(q);
        if (val < min) min = val;
        enqueue(q, val);  // Restore
    }

    return min;
}

