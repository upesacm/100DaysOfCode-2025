#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue {
    char data[MAX];
    int front, rear;
};

struct Stack {
    char data[MAX];
    int top;
};

void enqueue(struct Queue *q, char value) {
    q->data[++q->rear] = value;
    if (q->front == -1) q->front = 0;
}

char dequeue(struct Queue *q) {
    return q->data[q->front++];
}

void push(struct Stack *s, char value) {
    s->data[++s->top] = value;
}

char pop(struct Stack *s) {
    return s->data[s->top--];
}

int isPalindrome(struct Queue q) {
    struct Stack s;
    s.top = -1;
    for (int i = q.front; i <= q.rear; i++) push(&s, q.data[i]);
    for (int i = q.front; i <= q.rear; i++) {
        if (q.data[i] != pop(&s)) return 0;
    }
    return 1;
}

int main() {
    struct Queue q;
    q.front = q.rear = -1;
    char input[] = {'r', 'a', 'c', 'e', 'c', 'a', 'r'};
    for (int i = 0; i < 7; i++) enqueue(&q, input[i]);
    if (isPalindrome(q)) printf("Yes\n");
    else printf("No\n");
    return 0;
}