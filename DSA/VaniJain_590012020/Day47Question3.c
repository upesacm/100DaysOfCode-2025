#include <stdio.h>
#define MAX 100
typedef struct 
{
    int items[MAX];
    int front;
    int rear;
} Queue;
void initQueue(Queue *q) 
{
    q->front = -1;
    q->rear = -1;
}
int isEmpty(Queue *q) 
{
    return q->front == -1 || q->front > q->rear;
}
void enqueue(Queue *q, int value) 
{
    if (q->rear == MAX - 1) 
    {
        printf("Queue Overflow!\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->items[++q->rear] = value;
}
void getFrontAndRear(Queue *q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is empty. No front and rear elements.\n");
        return;
    }
    printf("Front element: %d\n", q->items[q->front]);
    printf("Rear element: %d\n", q->items[q->rear]);
}
int main() 
{
    Queue q;
    initQueue(&q);
    int n, val;
    printf("Enter number of elements in the queue: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        enqueue(&q, val);
    }
    getFrontAndRear(&q);
    return 0;
}
