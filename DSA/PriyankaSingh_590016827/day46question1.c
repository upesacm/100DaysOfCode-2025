#include <stdio.h>
#define SIZE 100

typedef struct {
    int data[SIZE];
    int front, rear;
} Queue;

void enqueue(Queue *q, int val) {
    q->data[q->rear++] = val;
}

int findMin(Queue q) {
    if (q.front == q.rear) return -1;

    int min = q.data[q.front];
    for (int i = q.front + 1; i < q.rear; i++) {
        if (q.data[i] < min)
            min = q.data[i];
    }
    return min;
}

int main() {
    Queue q = {.front = 0, .rear = 0};
    int n, val;

    printf("Enter number of elements in the queue: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    printf("Minimum element: %d\n", findMin(q));
    return 0;
}
