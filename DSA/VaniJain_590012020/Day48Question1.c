#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Queue 
{
    int items[MAX];
    int front, rear;
};
void initQueue(struct Queue* q) 
{
    q->front = 0;
    q->rear = -1;
}
int isEmpty(struct Queue* q) 
{
    return q->front > q->rear;
}
void enqueue(struct Queue* q, int value) 
{
    if (q->rear == MAX - 1) 
    {
        printf("Queue is full!\n");
        return;
    }
    q->rear++;
    q->items[q->rear] = value;
}
int dequeue(struct Queue* q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->items[q->front++];
}
void display(struct Queue* q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Updated Queue: ");
    for (int i = q->front; i <= q->rear; i++) 
    {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}
void removeOccurrences(struct Queue* q, int x) 
{
    struct Queue temp;
    initQueue(&temp);
    while (!isEmpty(q)) 
    {
        int val = dequeue(q);
        if (val != x) {
            enqueue(&temp, val);
        }
    }
    *q = temp;
}
int main() 
{
    struct Queue q;
    initQueue(&q);
    int n, x, element;
    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &element);
        enqueue(&q, element);
    }
    printf("Enter the value to remove: ");
    scanf("%d", &x);
    removeOccurrences(&q, x);
    display(&q);
    return 0;
}
