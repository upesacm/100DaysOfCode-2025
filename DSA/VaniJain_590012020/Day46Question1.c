#include <stdio.h>
#include <limits.h>
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
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->items[++q->rear] = value;
}
int dequeue(Queue *q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue Underflow\n");
        return -1;
    }
    return q->items[q->front++];
}
int findMinimum(Queue *q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is empty.\n");
        return -1;
    }
    int min = INT_MAX;
    int size = q->rear - q->front + 1;
    for (int i = 0; i < size; i++) 
    {
        int val = dequeue(q);
        if (val < min)
            min = val;
        enqueue(q, val); 
    }
    return min;
}
int main() 
{
    Queue q;
    initQueue(&q);
    int n, num;
    printf("Enter number of elements in the queue: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &num);
        enqueue(&q, num);
    }
    int min = findMinimum(&q);
    printf("Minimum element in the queue: %d\n", min);
    return 0;
}
