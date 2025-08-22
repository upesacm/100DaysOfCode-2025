#include <stdio.h>
#include <stdlib.h>
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
int main() 
{
    Queue q;
    initQueue(&q);
    int n, num, evenCount = 0, oddCount = 0;
    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &num);
        enqueue(&q, num);
    }
    while (!isEmpty(&q)) 
    {
        int val = dequeue(&q);
        if (val % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }
    printf("Number of even elements: %d\n", evenCount);
    printf("Number of odd elements: %d\n", oddCount);
    return 0;
}
