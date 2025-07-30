#include <stdio.h>

#define SIZE 100

typedef struct {
    int data[SIZE];
    int front, rear;
} Queue;

void enqueue(Queue *q, int val) {
    q->data[q->rear++] = val;
}

int findMax(Queue q) {
    if (q.front == q.rear)
        return -1; // Assuming negative values not allowed
    int max = q.data[q.front];
    for (int i = q.front + 1; i < q.rear; i++) {
        if (q.data[i] > max)
            max = q.data[i];
    }
    return max;
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

    printf("Maximum element in queue: %d\n", findMax(q));

    return 0;
}
