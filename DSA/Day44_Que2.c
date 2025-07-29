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

int queueSize(struct Queue* q) {
    if (q->rear < q->front) {
        return 0;
    }
    return q->rear - q->front + 1;
}

int main() {
    struct Queue q;
    init(&q);


    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    printf("Size of queue: %d\n", queueSize(&q));  


    init(&q);
    enqueue(&q, 7);
    printf("Size of queue: %d\n", queueSize(&q));  

    return 0;
}
