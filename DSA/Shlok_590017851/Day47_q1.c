#include <stdio.h>
#include <stdlib.h>
#define MAX 100 //Maximum size of the queue

struct Queue 
{
    int items[MAX];
    int front;
    int rear;
};
void initQueue(struct Queue*q) 
{
    q->front=-1;
    q->rear=-1;
}
int isFull(struct Queue*q) 
{
    return q->rear==MAX-1;
}
int isEmpty(struct Queue*q) 
{
    return q->front==-1||q->front>q->rear;
}

void insertAtRear(struct Queue*q,int value) 
{
    if (isFull(q))
    {
        printf("Queue is full. Cannot insert %d\n",value);
        return;
    }
    if (isEmpty(q)) 
    {
        q->front=0;
    }
    q->rear++;
    q->items[q->rear]=value;
}
void display(struct Queue*q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is empty.\n");
        return;
    }
    for (int i=q->front;i<=q->rear;i++) 
    {
        printf("%d",q->items[i]);
    }
    printf("\n");
}
int main()
{
    struct Queue q;
    initQueue(&q);
    insertAtRear(&q,1);
    insertAtRear(&q,2);
    insertAtRear(&q,3);
    printf("Queue after insertion:");
    display(&q);  
    return 0;
}
