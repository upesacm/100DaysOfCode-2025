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
    int value = q->items[q->front];
    if (q->front == q->rear) 
    {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}
int sumQueue(Queue *q) 
{
    if (isEmpty(q)) return 0;
    Queue temp;
    initializeQueue(&temp);
    int sum = 0;
    while (!isEmpty(q)) 
    {
        int val = dequeue(q);
        sum += val;
        enqueue(&temp, val); 
    }
    while (!isEmpty(&temp)) 
    {
        int val = dequeue(&temp);
        enqueue(q, val);
    }
    return sum;
}
int main() 
{
    Queue q;
    initializeQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    int result = sumQueue(&q);
    printf("Sum of queue elements: %d\n", result);
    return 0;
}
