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
int isFull(Queue *q) 
{
    return q->rear == MAX - 1;
}
int isEmpty(Queue *q) 
{
    return q->front == -1 || q->front > q->rear;
}
void enqueueRear(Queue *q, int value) 
{
    if (isFull(q)) 
    {
        printf("Queue Overflow!\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->items[++q->rear] = value;
}
void enqueueFront(Queue *q, int value) 
{
    if (q->front == 0) 
    {
        printf("Cannot insert at front. No space at front.\n");
        return;
    }
    if (isEmpty(q)) 
    {
        q->front = q->rear = 0;
        q->items[q->front] = value;
    } 
    else 
    {
        q->items[--q->front] = value;
    }
}
void displayQueue(Queue *q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) 
    {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}
int main() 
{
    Queue q;
    initQueue(&q);
    int n, val;
    printf("Enter number of initial elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        enqueueRear(&q, val);
    }
    printf("Enter an element to insert at the front: ");
    scanf("%d", &val);
    enqueueFront(&q, val);
    displayQueue(&q);
    return 0;
}
