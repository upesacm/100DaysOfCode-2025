#include <stdio.h>

#define SIZE 100

typedef struct
{
    int data[SIZE];
    int front, rear;
} Queue;

void init(Queue *q)
{
    q->front = q->rear = -1;
}

int empty(Queue *q)
{
    return q->front == -1;
}

void add(Queue *q, int val)
{
    if (q->rear == SIZE - 1)
        return;
    if (empty(q))
        q->front = 0;
    q->data[++q->rear] = val;
}

int max(Queue q)
{
    if (empty(&q))
        return -1;
    int m = q.data[q.front];
    for (int i = q.front + 1; i <= q.rear; i++)
    {
        if (q.data[i] > m)
            m = q.data[i];
    }
    return m;
}

int main()
{
    Queue q;
    init(&q);
    int n, x;
    printf("Enter number of elements in the queue: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        add(&q, x);
    }
    printf("Maximum element in the queue = %d\n", max(q));
    return 0;
}
