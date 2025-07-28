#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

void enqueue(Queue* q, int x) {
    if (q->rear == MAX - 1) return;
    q->arr[++q->rear] = x;
    if (q->front == -1) q->front = 0;
}

int dequeue(Queue* q) {
    if (q->front == -1 || q->front > q->rear) return -1;
    return q->arr[q->front++];
}

void printQueue(Queue* q) {
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->arr[i]);
    printf("\n");
}

void reverseK(Queue* q, int k) {
    int stack[MAX], top = -1;
    for (int i = 0; i < k; i++)
        stack[++top] = dequeue(q);
    while (top != -1)
        enqueue(q, stack[top--]);
    int n = q->rear - q->front + 1 - k;
    for (int i = 0; i < n; i++)
        enqueue(q, dequeue(q));
}

int main() {
    Queue q = {{0}, -1, -1};
    int n, k, temp;
    printf("Enter number of elements in queue: ");
    scanf("%d", &n);
    printf("Enter the queue elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        enqueue(&q, temp);
    }
    printf("Enter k: ");
    scanf("%d", &k);
    reverseK(&q, k);
    printf("Queue after reversing first %d elements:\n", k);
    printQueue(&q);
    return 0;
}
