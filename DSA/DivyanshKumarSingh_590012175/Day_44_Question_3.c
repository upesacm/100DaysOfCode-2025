#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int val)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = val;
}

int isQueueEmpty()
{
    return (front == -1 || front > rear);
}

int main()
{
    int n, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d queue elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        enqueue(val);
    }


    if (isQueueEmpty())
        printf("True\n");
    else
        printf("False\n");

    return 0;
}