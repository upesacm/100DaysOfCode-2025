#include <stdio.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int front, rear;
} Queue;


void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}


int isEmpty(Queue *q) {
    return q->front > q->rear;
}


int isFull(Queue *q) {
    return q->rear == MAX - 1;
}


void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    q->data[++q->rear] = value;
}


void displayQueue(Queue *q) {
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


int queueSize(Queue *q) {
    if (isEmpty(q)) return 0;
    return q->rear - q->front + 1;
}

int main() {
    Queue q;
    initQueue(&q);


    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);


    displayQueue(&q);  

   
    printf("Queue Size: %d\n", queueSize(&q));  


    printf("Is Queue Empty? %s\n", isEmpty(&q) ? "True" : "False");  

    Queue q2;
    initQueue(&q2);
    displayQueue(&q2); 
    printf("Queue Size: %d\n", queueSize(&q2)); 
    printf("Is Queue Empty? %s\n", isEmpty(&q2) ? "True" : "False");  

    return 0;
}


