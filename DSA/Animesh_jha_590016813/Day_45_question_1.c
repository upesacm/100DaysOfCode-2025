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

int findMax(Queue *q) {
    int n = size(q);
    if (n == 0) return -1; 

    int maxVal = dequeue(q);
    enqueue(q, maxVal); 

    for (int i = 1; i < n; i++) {
        int val = dequeue(q);
        if (val > maxVal)
            maxVal = val;
        enqueue(q, val); 
    }

    return maxVal;
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 3);
    enqueue(&q, 5);
    enqueue(&q, 1);
    enqueue(&q, 2);

    int maxElement = findMax(&q);
    printf("Maximum element in queue: %d\n", maxElement);

    return 0;
}
