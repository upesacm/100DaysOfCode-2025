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
void enqueue(Queue *q, int value) 
{
    if (isFull(q)) 
    {
        printf("Queue Overflow! Cannot insert more elements.\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->items[++q->rear] = value;
    printf("Inserted %d at rear of the queue.\n", value);
}
void displayQueue(Queue *q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() 
{
    Queue q;
    initQueue(&q);
    int n, value;
    printf("Enter number of elements to insert initially: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &value);
        enqueue(&q, value);
    }
    printf("Enter element to insert at the rear of the queue: ");
    scanf("%d", &value);
    enqueue(&q, value);
    displayQueue(&q);
    return 0;
}
