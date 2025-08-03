#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

typedef struct {
    int data[SIZE];
    int front, rear;
} Queue;

void enqueue(Queue *q, int val) {
    q->data[q->rear++] = val;
}

bool areQueuesEqual(Queue q1, Queue q2) {
    if ((q1.rear - q1.front) != (q2.rear - q2.front))
        return false;

    for (int i = 0; i < q1.rear - q1.front; i++) {
        if (q1.data[q1.front + i] != q2.data[q2.front + i])
            return false;
    }
    return true;
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

    if (areQueuesEqual(q1, q2))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
