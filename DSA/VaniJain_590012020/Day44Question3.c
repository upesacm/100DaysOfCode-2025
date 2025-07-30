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
int isQueueEmpty(Queue* q) 
{
    return (q->front == -1);
}
int isQueueFull(Queue* q) 
{
    return ((q->rear + 1) % MAX == q->front);
}
void enqueue(Queue* q, int value) 
{
    if (isQueueFull(q)) 
    {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }
    if (isQueueEmpty(q)) 
    {
        q->front = q->rear = 0;
    } else 
    {
        q->rear = (q->rear + 1) % MAX;
    }
    q->items[q->rear] = value;
}
int dequeue(Queue* q) 
{
    if (isQueueEmpty(q)) 
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) 
    {
        q->front = q->rear = -1;
    } 
    else 
    {
        q->front = (q->front + 1) % MAX;
    }
    return value;
}
int main() 
{
    Queue q;
    initQueue(&q);
    int n, value;
    printf("Is queue empty? %s\n", isQueueEmpty(&q) ? "Yes" : "No");
    printf("Enter the number of elements to enqueue: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &value);
        enqueue(&q, value);
    }
    printf("Is queue empty after enqueue? %s\n", isQueueEmpty(&q) ? "Yes" : "No");
    printf("Dequeuing all elements...\n");
    while (!isQueueEmpty(&q)) 
    {
        printf("Dequeued: %d\n", dequeue(&q));
    }
    printf("Is queue empty after dequeue? %s\n", isQueueEmpty(&q) ? "Yes" : "No");
    return 0;
}
