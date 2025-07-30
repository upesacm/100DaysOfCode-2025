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


int compareQueues(struct Queue* q1, struct Queue* q2) {
    int size1 = q1->rear - q1->front + 1;
    int size2 = q2->rear - q2->front + 1;

    if (size1 != size2) {
        return 0; 
    }

    for (int i = 0; i < size1; i++) {
        if (q1->data[q1->front + i] != q2->data[q2->front + i]) {
            return 0; 
        }
    }

    return 1; 
}

int main() {
    struct Queue q1, q2;
    init(&q1);
    init(&q2);

    
    enqueue(&q1, 1);
    enqueue(&q1, 2);
    enqueue(&q1, 3);

    enqueue(&q2, 1);
    enqueue(&q2, 2);
    enqueue(&q2, 3);

    if (compareQueues(&q1, &q2)) {
        printf("Queues are identical: Yes\n");
    } else {
        printf("Queues are identical: No\n");
    }

    init(&q1);
    init(&q2);

    enqueue(&q1, 1);
    enqueue(&q1, 2);

    enqueue(&q2, 2);
    enqueue(&q2, 1);

    if (compareQueues(&q1, &q2)) {
        printf("Queues are identical: Yes\n");
    } else {
        printf("Queues are identical: No\n");
    }

    return 0;
}
