#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

typedef struct {
    char data[SIZE];
    int front, rear;
} Queue;

typedef struct {
    char data[SIZE];
    int top;
} Stack;

void enqueue(Queue *q, char ch) {
    q->data[q->rear++] = ch;
}

char dequeue(Queue *q) {
    return q->data[q->front++];
}

void push(Stack *s, char ch) {
    s->data[++s->top] = ch;
}

char pop(Stack *s) {
    return s->data[s->top--];
}

bool isPalindrome(Queue *q) {
    Stack s = {.top = -1};
    int len = q->rear - q->front;

    for (int i = q->front; i < q->rear; i++)
        push(&s, q->data[i]);

    for (int i = q->front; i < q->rear; i++) {
        if (q->data[i] != pop(&s))
            return false;
    }
    return true;
}

int main() {
    Queue q = {.front = 0, .rear = 0};
    char input[] = {'r', 'a', 'c', 'e', 'c', 'a', 'r'};

    for (int i = 0; i < 7; i++)
        enqueue(&q, input[i]);

    if (isPalindrome(&q))
        printf("Yes\n"); 
    else
        printf("No\n");

    return 0;
}
