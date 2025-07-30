#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct 
{
    int items[MAX];
    int front, rear;
} Queue;
void initQueue(Queue* q) 
{
    q->front = -1;
    q->rear = -1;
}
int isEmpty(Queue* q) 
{
    return q->front == -1;
}
int isFull(Queue* q) 
{
    return (q->rear + 1) % MAX == q->front;
}
void enqueue(Queue* q, int value) 
{
    if (isFull(q)) 
    {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(q)) 
    {
        q->front = q->rear = 0;
    } 
    else 
    {
        q->rear = (q->rear + 1) % MAX;
    }
    q->items[q->rear] = value;
}
int countQueueElements(Queue* q) 
{
    if (isEmpty(q)) 
    {
        return 0;
    }
    if (q->rear >= q->front) 
    {
        return q->rear - q->front + 1;
    } 
    else 
    {
        return (MAX - q->front) + (q->rear + 1);
    }
}
int main() 
{
    Queue q;
    initQueue(&q);
    int n, value;
    printf("Enter the number of elements to enqueue: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &value);
        enqueue(&q, value);
    }
    int count = countQueueElements(&q);
    printf("Number of elements in the queue: %d\n", count);
    return 0;
}
