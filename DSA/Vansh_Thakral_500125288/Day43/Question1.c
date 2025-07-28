#include <stdio.h>
#include <stdlib.h>

#define MAX 100


typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void enqueue(Queue *q, int val) {
    if (q->rear == MAX - 1) return;
    q->data[++q->rear] = val;
    if (q->front == -1) q->front = 0;
}

int dequeue(Queue *q) {
    if (q->front == -1 || q->front > q->rear) return -1;
    return q->data[q->front++];
}

int isEmptyQueue(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

typedef struct {
    int data[MAX];
    int top;
} Stack;

void push(Stack *s, int val) {
    if (s->top == MAX - 1) return;
    s->data[++s->top] = val;
}

int pop(Stack *s) {
    if (s->top == -1) return -1;
    return s->data[s->top--];
}


void reverseKElements(Queue *q, int k) {
    Stack s;
    s.top = -1;


    for (int i = 0; i < k; i++) {
        push(&s, dequeue(q));
    }

    
    while (s.top != -1) {
        enqueue(q, pop(&s));
    }

    int size = q->rear - q->front + 1;
    for (int i = 0; i < size - k; i++) {
        enqueue(q, dequeue(q));
    }
}


void printQueue(Queue q) {
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d ", q.data[i]);
    }
    printf("\n");
}


int main() {
    Queue q = {.front = -1, .rear = -1};

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    int k = 3;
    reverseKElements(&q, k);

    printQueue(q); 

    return 0;
}
