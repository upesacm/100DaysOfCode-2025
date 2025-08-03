#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

typedef struct {
    int arr[MAX];
    int top;
} Stack;


void enqueue(Queue *q, int val) {
    q->arr[q->rear++] = val;
}

int dequeue(Queue *q) {
    return q->arr[q->front++];
}

int isQueueEmpty(Queue *q) {
    return q->front == q->rear;
}


void push(Stack *s, int val) {
    s->arr[++s->top] = val;
}

int pop(Stack *s) {
    return s->arr[s->top--];
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

void reverseFirstK(Queue *q, int k) {
    Stack s = {.top = -1};
    Queue tempQ = {.front = 0, .rear = 0};

    for (int i = 0; i < k; i++) {
        push(&s, dequeue(q));
    }

    
    while (!isStackEmpty(&s)) {
        enqueue(&tempQ, pop(&s));
    }


    while (!isQueueEmpty(q)) {
        enqueue(&tempQ, dequeue(q));
    }

   
    *q = tempQ;
}

void printQueue(Queue *q) {
    for (int i = q->front; i < q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}


int main() {
    Queue q = {.front = 0, .rear = 0};
    int arr[] = {1, 2, 3, 4, 5}, k = 3;

    for (int i = 0; i < 5; i++)
        enqueue(&q, arr[i]);

    reverseFirstK(&q, k);
    printQueue(&q);  

    return 0;
}
