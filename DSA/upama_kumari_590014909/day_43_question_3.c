#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue {
    char items[MAX];
    int front, rear;
};

struct Stack {
    char items[MAX];
    int top;
};

void initQueue(struct Queue *q) {
    q->front = 0;
    q->rear = -1;
}

void enqueue(struct Queue *q, char ch) {
    if (q->rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    q->items[++(q->rear)] = ch;
}

char dequeue(struct Queue *q) {
    if (q->front > q->rear) {
        printf("Queue is empty\n");
        exit(1);
    }
    return q->items[(q->front)++];
}

void initStack(struct Stack *s) {
    s->top = -1;
}

void push(struct Stack *s, char ch) {
    if (s->top == MAX - 1) {
        printf("Stack is full\n");
        return;
    }
    s->items[++(s->top)] = ch;
}

char pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

int isPalindrome(struct Queue q) {
    struct Stack s;
    initStack(&s);

    for (int i = q.front; i <= q.rear; i++) {
        push(&s, q.items[i]);
    }

    for (int i = q.front; i <= q.rear; i++) {
        if (q.items[i] != pop(&s)) {
            return 0;
        }
    }

    return 1; 
}

int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 'r');
    enqueue(&q, 'a');
    enqueue(&q, 'c');
    enqueue(&q, 'e');
    enqueue(&q, 'c');
    enqueue(&q, 'a');
    enqueue(&q, 'r');

    if (isPalindrome(q))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
