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

int isEmpty(struct Queue* q) {
    return q->front > q->rear;
}

int main() {
    struct Queue q;
    init(&q);

    if (isEmpty(&q)) {
        printf("Queue is empty: True\n");
    } else {
        printf("Queue is empty: False\n");
    }

    enqueue(&q, 1);
    enqueue(&q, 2);
    if (isEmpty(&q)) {
        printf("Queue is empty: True\n");
    } else {
        printf("Queue is empty: False\n"); 
    }

    return 0;

  
}
