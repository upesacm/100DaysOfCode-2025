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
        printf("Queue is full.\n");
        return;
    }
    if (isEmpty(q)) 
    {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }
    q->items[q->rear] = value;
}
int dequeue(Queue* q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is empty.\n");
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
void displayQueue(Queue q) 
{
    if (isEmpty(&q)) 
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements (front to rear): ");
    int i = q.front;
    while (1) 
    {
        printf("%d ", q.items[i]);
        if (i == q.rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
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
    displayQueue(q);
    printf("Verifying queue is intact (dequeue all): ");
    while (!isEmpty(&q)) 
    {
        printf("%d ", dequeue(&q));
    }
    printf("\n");
    return 0;
}
