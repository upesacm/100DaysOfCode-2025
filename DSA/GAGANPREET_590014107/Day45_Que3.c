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


int findMax(struct Queue* q) {
    if (q->rear < q->front) {
        printf("Queue is empty\n");
        return -1;
    }

    int max = q->data[q->front];
    for (int i = q->front + 1; i <= q->rear; i++) {
        if (q->data[i] > max) {
            max = q->data[i];
        }
    }

    return max;
}

int main() {
    struct Queue q;
    init(&q);

    
    enqueue(&q, 3);
    enqueue(&q, 5);
    enqueue(&q, 1);
    enqueue(&q, 2);

    printf("Maximum element: %d\n", findMax(&q));


    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 7);
    enqueue(&q, 4);

    printf("Maximum element: %d\n", findMax(&q));

    return 0;
}
