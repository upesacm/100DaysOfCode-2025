#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
typedef struct 
{
    int items[SIZE];
    int front;
    int rear;
} Queue;
void initializeQueue(Queue *q) 
{
    q->front = -1;
    q->rear = -1;
}
int isEmpty(Queue *q) 
{
    return q->front == -1;
}
void enqueue(Queue *q, int value) 
{
    if (q->rear == SIZE - 1) 
    {
        printf("Queue overflow\n");
        return;
    }
    if (isEmpty(q))
        q->front = 0;
    q->items[++q->rear] = value;
}
int dequeue(Queue *q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue underflow\n");
        return -1;
    }
    int val = q->items[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return val;
}
int areQueuesIdentical(Queue *q1, Queue *q2) 
{
    Queue temp1, temp2;
    initializeQueue(&temp1);
    initializeQueue(&temp2);
    int identical = 1;
    while (!isEmpty(q1) && !isEmpty(q2)) 
    {
        int val1 = dequeue(q1);
        int val2 = dequeue(q2);
        if (val1 != val2)
            identical = 0;
        enqueue(&temp1, val1);
        enqueue(&temp2, val2);
    }
    if (!isEmpty(q1) || !isEmpty(q2))
        identical = 0;
    while (!isEmpty(&temp1))
        enqueue(q1, dequeue(&temp1));
    while (!isEmpty(&temp2))
        enqueue(q2, dequeue(&temp2));
    return identical;
}
int main() 
{
    Queue q1, q2;
    initializeQueue(&q1);
    initializeQueue(&q2);
    enqueue(&q1, 10);
    enqueue(&q1, 20);
    enqueue(&q1, 30);
    enqueue(&q2, 10);
    enqueue(&q2, 20);
    enqueue(&q2, 30);
    if (areQueuesIdentical(&q1, &q2))
        printf("Queues are identical.\n");
    else
        printf("Queues are NOT identical.\n");
    return 0;
}
