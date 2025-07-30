#include <stdio.h>
#include <stdlib.h>

#define MAX 100


typedef struct {
    char data[MAX];
    int front, rear;
} CharQueue;

typedef struct {
    char data[MAX];
    int top;
} CharStack;

void enqueueChar(CharQueue *q, char c) {
    if (q->rear == MAX - 1) return;
    q->data[++q->rear] = c;
    if (q->front == -1) q->front = 0;
}

char dequeueChar(CharQueue *q) {
    if (q->front == -1 || q->front > q->rear) return '\0';
    return q->data[q->front++];
}

void pushChar(CharStack *s, char c) {
    if (s->top == MAX - 1) return;
    s->data[++s->top] = c;
}

char popChar(CharStack *s) {
    if (s->top == -1) return '\0';
    return s->data[s->top--];
}

int isPalindromeQueue(CharQueue q) {
    CharStack s = {.top = -1};

    for (int i = q.front; i <= q.rear; i++) {
        pushChar(&s, q.data[i]);
    }


    for (int i = q.front; i <= q.rear; i++) {
        if (q.data[i] != popChar(&s)) {
            return 0;
        }
    }

    return 1;
}


int main() {
    CharQueue q = {.front = -1, .rear = -1};
    char input[] = {'r', 'a', 'c', 'e', 'c', 'a', 'r'};
    int n = sizeof(input) / sizeof(input[0]);

    for (int i = 0; i < n; i++) {
        enqueueChar(&q, input[i]);
    }

    if (isPalindromeQueue(q)) {
        printf("Yes\n"); 
    } else {
        printf("No\n");
    }

    return 0;
}

