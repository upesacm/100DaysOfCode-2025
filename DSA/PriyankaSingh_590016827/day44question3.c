#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

typedef struct {
    int data[SIZE];
    int front, rear;
} Queue;

bool isEmpty(Queue *q) {
    return q->front == q->rear;
}

int main() {
    Queue q1 = {.front = 0, .rear = 0};
    Queue q2 = {.front = 0, .rear = 0};

    q2.data[q2.rear++] = 1;
    q2.data[q2.rear++] = 2;

    printf("%s\n", isEmpty(&q1) ? "True" : "False");  // Output: True
    printf("%s\n", isEmpty(&q2) ? "True" : "False");  // Output: False

    return 0;
}
