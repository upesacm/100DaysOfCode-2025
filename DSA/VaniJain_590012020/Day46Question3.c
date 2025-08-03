#include <stdio.h>
#include <stdlib.h>
#define MAX 200  
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
void displayQueue(Queue *q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->items[i]);
    printf("\n");
}
void mergeQueues(Queue *q1, Queue *q2) 
{
    for (int i = q2->front; i <= q2->rear; i++) 
    {
        enqueue(q1, q2->items[i]);
    }
}

int main() 
{
    Queue q1, q2;
    initQueue(&q1);
    initQueue(&q2);
    int n1, n2, val;
    printf("Enter number of elements in first queue: ");
    scanf("%d", &n1);
    printf("Enter %d elements for first queue:\n", n1);
    for (int i = 0; i < n1; i++) 
    {
        scanf("%d", &val);
        enqueue(&q1, val);
    }
    printf("Enter number of elements in second queue: ");
    scanf("%d", &n2);
    printf("Enter %d elements for second queue:\n", n2);
    for (int i = 0; i < n2; i++) 
    {
        scanf("%d", &val);
        enqueue(&q2, val);
    }
    mergeQueues(&q1, &q2);
    printf("\nMerged Queue:\n");
    displayQueue(&q1);
    return 0;
}
