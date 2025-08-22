#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

void enqueue(Queue* q, int val) {
    if ((q->rear + 1) % MAX == q->front) return;
    if (q->front == -1) q->front = 0;
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = val;
}

int dequeue(Queue* q) {
    if (q->front == -1) return -1;
    int val = q->data[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return val;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

int isUnique(Queue* q) {
    if (isEmpty(q)) return 1;
    int seen[MAX] = {0};
    int size = (q->rear >= q->front) ? (q->rear - q->front + 1) : (MAX - q->front + q->rear + 1);
    for (int i = 0; i < size; ++i) {
        int val = dequeue(q);
        if (seen[val]) {
            enqueue(q, val);
            for (++i; i < size; ++i) {
                enqueue(q, dequeue(q));
            }
            return 0;
        }
        seen[val] = 1;
        enqueue(q, val);
    }
    return 1;
}

int main() {
    Queue q1;
    q1.front = -1;
    q1.rear = -1;
    enqueue(&q1, 1);
    enqueue(&q1, 2);
    enqueue(&q1, 3);
    enqueue(&q1, 4);
    printf("%s\n", isUnique(&q1) ? "True" : "False");

    Queue q2;
    q2.front = -1;
    q2.rear = -1;
    enqueue(&q2, 1);
    enqueue(&q2, 2);
    enqueue(&q2, 2);
    enqueue(&q2, 3);
    printf("%s\n", isUnique(&q2) ? "True" : "False");

    return 0;
}
