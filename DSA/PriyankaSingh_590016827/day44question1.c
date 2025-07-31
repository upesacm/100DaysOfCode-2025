#include <stdio.h>

#define SIZE 100

typedef struct {
    int data[SIZE];
    int front, rear;
} Queue;

void enqueue(Queue *q, int val) {
    q->data[q->rear++] = val;
}

void displayQueue(Queue q) {
    for (int i = q.front; i < q.rear; i++)
        printf("%d ", q.data[i]);
    printf("\n");
}

int main() {
    Queue q = {.front = 0, .rear = 0};
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    displayQueue(q);  // Output: 10 20 30

    return 0;
}
