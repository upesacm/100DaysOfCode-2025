#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void push(Stack* s, int val) {
    s->data[++s->top] = val;
}

int pop(Stack* s) {
    return s->data[s->top--];
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

typedef struct {
    int data[MAX];
    int front;
    int rear;
    int size;
} Queue;

void enqueue(Queue* q, int val) {
    q->data[q->rear++] = val;
    q->size++;
}

int dequeue(Queue* q) {
    q->size--;
    return q->data[q->front++];
}

void reverseFirstK(Queue* q, int k) {
    Stack s;
    s.top = -1;

    for (int i = 0; i < k; i++) {
        push(&s, dequeue(q));
    }

    while (!isEmpty(&s)) {
        enqueue(q, pop(&s));
    }

    for (int i = 0; i < q->size - k; i++) {
        enqueue(q, dequeue(q));
    }
}

void printQueue(Queue* q) {
    for (int i = q->front; i < q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    q.front = 0;
    q.rear = 0;
    q.size = 0;

    int n, k, val;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    reverseFirstK(&q, k);
    printQueue(&q);

    return 0;
}
