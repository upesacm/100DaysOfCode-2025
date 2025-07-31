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

int same(Queue q1, Queue q2)
{
    if ((q1.rear - q1.front) != (q2.rear - q2.front))
        return 0;
    for (int i = 0; i <= q1.rear - q1.front; i++)
    {
        if (q1.data[q1.front + i] != q2.data[q2.front + i])
            return 0;
    }
    return 1;
}

int main()
{
    Queue q1, q2;
    init(&q1);
    init(&q2);
    int n1, n2, x;

    printf("Enter number of elements in Queue 1: ");
    scanf("%d", &n1);
    printf("Enter %d elements for Queue 1: ", n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &x);
        add(&q1, x);
    }

    printf("Enter number of elements in Queue 2: ");
    scanf("%d", &n2);
    printf("Enter %d elements for Queue 2: ", n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &x);
        add(&q2, x);
    }

    if (same(q1, q2))
        printf("The two queues are IDENTICAL.\n");
    else
        printf("The two queues are DIFFERENT.\n");

    return 0;
}
