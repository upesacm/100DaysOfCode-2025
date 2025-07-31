#include <stdio.h>
#define SIZE 200

typedef struct {
    int data[SIZE];
    int front, rear;
} Queue;

void enqueue(Queue *q, int val) {
    q->data[q->rear++] = val;
}

void displayQueue(Queue q) {
    for (int i = q.front; i < q.rear; i++)
        printf("%d ", q.data[i]);
    printf("\n");
}

Queue mergeQueues(Queue q1, Queue q2) {
    Queue merged = {.front = 0, .rear = 0};
    for (int i = q1.front; i < q1.rear; i++)
        enqueue(&merged, q1.data[i]);
    for (int i = q2.front; i < q2.rear; i++)
        enqueue(&merged, q2.data[i]);
    return merged;
}

int main() {
    Queue q1 = {.front = 0, .rear = 0};
    Queue q2 = {.front = 0, .rear = 0};
    int n1, n2, val;

    printf("Enter number of elements in first queue: ");
    scanf("%d", &n1);
    printf("Enter %d elements:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        enqueue(&q1, val);
    }

    printf("Enter number of elements in second queue: ");
    scanf("%d", &n2);
    printf("Enter %d elements:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        enqueue(&q2, val);
    }

    Queue merged = mergeQueues(q1, q2);

    printf("Merged Queue: ");
    displayQueue(merged);

    return 0;
}
