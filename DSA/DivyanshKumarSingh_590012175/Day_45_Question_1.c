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

int sum(Queue q)
{
    int s = 0;
    for (int i = q.front; i <= q.rear; i++)
        s += q.data[i];
    return s;
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
    printf("Sum of all elements in the queue = %d\n", sum(q));
    return 0;
}
