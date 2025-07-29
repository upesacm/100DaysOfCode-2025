#include <stdio.h>
#include <stdbool.h>
#define SIZE 100

struct Queue {
    int items[SIZE];
    int front;
    int rear;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

bool isQueueEmpty(struct Queue* q) {
    return q->front == -1;
}

int main() {
    struct Queue q;
    initQueue(&q);

    q.front = 0;
    q.rear = 1;
    q.items[0] = 1;
    q.items[1] = 2;

    if (isQueueEmpty(&q)) {
        printf("True");
    } else {
        printf("False\n");
    }

    return 0;
}
