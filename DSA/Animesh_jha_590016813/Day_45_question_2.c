#include <stdio.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, int val) {
    if (q->rear < MAX) {
        q->data[q->rear++] = val;
    }
}

int dequeue(Queue *q) {
    if (!isEmpty(q)) {
        return q->data[q->front++];
    }
    return -1; 
}

int size(Queue *q) {
    return q->rear - q->front;
}

int compareQueues(Queue *q1, Queue *q2) {
    int n1 = size(q1);
    int n2 = size(q2);

    if (n1 != n2)
        return 0; 

    int equal = 1;

    for (int i = 0; i < n1; i++) {
        int val1 = dequeue(q1);
        int val2 = dequeue(q2);

        if (val1 != val2)
            equal = 0;

        enqueue(q1, val1);
        enqueue(q2, val2);
    }

    return equal;
}

int main() {
    Queue q1, q2;
    initQueue(&q1);
    initQueue(&q2);

    enqueue(&q1, 1);
    enqueue(&q1, 2);
    enqueue(&q1, 3);

    enqueue(&q2, 1);
    enqueue(&q2, 2);
    enqueue(&q2, 3);

    if (compareQueues(&q1, &q2))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
