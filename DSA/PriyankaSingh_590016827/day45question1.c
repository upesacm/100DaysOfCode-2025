#include <stdio.h>

#define SIZE 100

typedef struct {
    int data[SIZE];
    int front, rear;
} Queue;

void enqueue(Queue *q, int val) {
    q->data[q->rear++] = val;
}

int sumQueue(Queue q) {
    int sum = 0;
    for (int i = q.front; i < q.rear; i++)
        sum += q.data[i];
    return sum;
}

int main() {
    Queue q = {.front = 0, .rear = 0};
    int n, val;

    printf("Enter number of elements in queue: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    printf("Sum of queue elements: %d\n", sumQueue(q));

    return 0;
}
