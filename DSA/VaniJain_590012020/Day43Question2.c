#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
#define SIZE 32 
typedef struct 
{
    char items[MAX][SIZE];
    int front, rear;
} Queue;
void initQueue(Queue *q) 
{
    q->front = 0;
    q->rear = -1;
}
int isEmpty(Queue *q) 
{
    return q->front > q->rear;
}
void enqueue(Queue *q, char *value) 
{
    if (q->rear < MAX - 1) 
    {
        strcpy(q->items[++q->rear], value);
    }
}
char* dequeue(Queue *q) 
{
    if (!isEmpty(q)) 
    {
        return q->items[q->front++];
    }
    return NULL;
}
void generateBinary(int n) 
{
    Queue q;
    initQueue(&q);
    enqueue(&q, "1");
    printf("Binary numbers from 1 to %d:\n", n);
    for (int i = 1; i <= n; i++) 
    {
        char *current = dequeue(&q);
        printf("%s\n", current);
        char temp0[SIZE], temp1[SIZE];
        strcpy(temp0, current);
        strcpy(temp1, current);
        strcat(temp0, "0");
        strcat(temp1, "1");
        enqueue(&q, temp0);
        enqueue(&q, temp1);
    }
}
int main() 
{
    int n;
    printf("Enter a number n: ");
    scanf("%d", &n);
    if (n <= 0) 
    {
        printf("Please enter a positive number.\n");
        return 1;
    }
    generateBinary(n);
    return 0;
}
