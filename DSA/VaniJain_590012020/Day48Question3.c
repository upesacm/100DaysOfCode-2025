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
void countFrequencies(struct Queue* q) 
{
    int freqVals[MAX];  
    int freqCount[MAX];
    int freqSize = 0;
    for (int i = q->front; i <= q->rear; i++) 
    {
        int found = 0;
        for (int j = 0; j < freqSize; j++) 
        {
            if (freqVals[j] == q->items[i]) 
            {
                freqCount[j]++;
                found = 1;
                break;
            }
        }
        if (!found) 
        {
            freqVals[freqSize] = q->items[i];
            freqCount[freqSize] = 1;
            freqSize++;
        }
    }
    printf("Frequency distribution:\n");
    for (int i = 0; i < freqSize; i++) 
    {
        printf("%d -> %d\n", freqVals[i], freqCount[i]);
    }
}
int main() 
{
    struct Queue q;
    initQueue(&q);
    int n, val;
    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        enqueue(&q, val);
    }
    countFrequencies(&q);
    return 0;
}
