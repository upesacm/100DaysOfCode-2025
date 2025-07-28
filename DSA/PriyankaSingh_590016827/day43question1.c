#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
    int data[SIZE];
    int front, rear;
} Queue;

typedef struct {
    int data[SIZE];
    int top;
} Stack;

void enqueue(Queue *q, int val) {
    q->data[q->rear++] = val;
}

int dequeue(Queue *q) {
    return q->data[q->front++];
}

void push(Stack *s, int val) {
    s->data[++s->top] = val;
}

int pop(Stack *s) {
    return s->data[s->top--];
}

void reverseFirstK(Queue *q, int k) {
    Stack s = {.top = -1};

    for (int i = 0; i < k; i++)
        push(&s, dequeue(q));

    int temp[SIZE], idx = 0;

    while (s.top != -1)
        temp[idx++] = pop(&s);

    while (q->front != q->rear)
        temp[idx++] = dequeue(q);

    q->front = q->rear = 0;

    for (int i = 0; i < idx; i++)
        enqueue(q, temp[i]);
}

void printQueue(Queue *q) {
    for (int i = q->front; i < q->rear; i++)
        printf("%d ", q->data[i]);
    printf("\n");
}

int main() {
    Queue q = {.front = 0, .rear = 0};
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    int k = 3;
    reverseFirstK(&q, k);
    printQueue(&q);  
    return 0;
}
