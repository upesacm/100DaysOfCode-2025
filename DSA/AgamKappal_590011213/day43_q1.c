#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue {
    int data[MAX];
    int front, rear;
};

struct Stack {
    int data[MAX];
    int top;
};

void enqueue(struct Queue *q, int value) {
    if (q->rear == MAX - 1) return;
    q->data[++q->rear] = value;
    if (q->front == -1) q->front = 0;
}

int dequeue(struct Queue *q) {
    if (q->front == -1 || q->front > q->rear) return -1;
    return q->data[q->front++];
}

void push(struct Stack *s, int value) {
    if (s->top == MAX - 1) return;
    s->data[++s->top] = value;
}

int pop(struct Stack *s) {
    if (s->top == -1) return -1;
    return s->data[s->top--];
}

void reverseFirstK(struct Queue *q, int k) {
    struct Stack s;
    s.top = -1;
    int i;
    for (i = 0; i < k; i++) push(&s, dequeue(q));
    while (s.top != -1) enqueue(q, pop(&s));
    int size = q->rear - q->front + 1;
    for (i = 0; i < size - k; i++) enqueue(q, dequeue(q));
}

void printQueue(struct Queue q) {
    for (int i = q.front; i <= q.rear; i++) printf("%d ", q.data[i]);
    printf("\n");
}

int main() {
    struct Queue q;
    q.front = q.rear = -1;
    int arr[] = {1, 2, 3, 4, 5}, k = 3;
    for (int i = 0; i < 5; i++) enqueue(&q, arr[i]);
    reverseFirstK(&q, k);
    printQueue(q);
    return 0;
}