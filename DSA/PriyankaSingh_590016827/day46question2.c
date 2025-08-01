#include <stdio.h>
#define SIZE 100

typedef struct {
    int data[SIZE];
    int front, rear;
} Queue;

void enqueue(Queue *q, int val) {
    q->data[q->rear++] = val;
}

void countEvenOdd(Queue q, int *even, int *odd) {
    *even = 0;
    *odd = 0;
    for (int i = q.front; i < q.rear; i++) {
        if (q.data[i] % 2 == 0)
            (*even)++;
        else
            (*odd)++;
    }
}

int main() {
    Queue q = {.front = 0, .rear = 0};
    int n, val, even, odd;

    printf("Enter number of elements in the queue: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    countEvenOdd(q, &even, &odd);

    printf("Even: %d, Odd: %d\n", even, odd);
    return 0;
}
