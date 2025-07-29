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

int isEmpty(struct Queue* q) {
    return q->front > q->rear;
}

void enqueue(struct Queue* q, int val) {
    if (q->rear < MAX - 1) {
        q->data[++(q->rear)] = val;
    } else {
        printf("Queue Overflow\n");
    }
}

void displayQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    init(&q);


    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    displayQueue(&q);

    init(&q);
    enqueue(&q, 5);
    enqueue(&q, 15);
    displayQueue(&q); 

    return 0;
}
