#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue {
    int data[MAX];
    int front;
    int rear;
};

void init(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
}

void enqueue(struct Queue* q, int val) {
    if (q->rear < MAX - 1) {
        q->data[++(q->rear)] = val;
    } else {
        printf("Queue Overflow\n");
    }
}

int sumOfQueue(struct Queue* q) {
    int sum = 0;
    for (int i = q->front; i <= q->rear; i++) {
        sum += q->data[i];
    }
    return sum;
}

int main() {
    struct Queue q;
    init(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("Sum of queue: %d\n", sumOfQueue(&q)); 

    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("Sum of queue: %d\n", sumOfQueue(&q));  

    return 0;
}
