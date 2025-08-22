#include <stdio.h>
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
int areAllUnique(struct Queue* q) 
{
    for (int i = q->front; i <= q->rear; i++) 
    {
        for (int j = i + 1; j <= q->rear; j++) 
        {
            if (q->items[i] == q->items[j]) 
            {
                return 0; 
            }
        }
    }
    return 1;
}
int main() 
{
    struct Queue q;
    initQueue(&q);
    int n, element;
    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &element);
        enqueue(&q, element);
    }
    if (areAllUnique(&q)) 
    {
        printf("True (All elements are unique)\n");
    } else 
    {
        printf("False (Duplicates found)\n");
    }
    return 0;
}
