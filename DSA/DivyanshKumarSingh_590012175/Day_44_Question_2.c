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

int queueSize()
{
    if (front == -1 || front > rear)
        return 0;
    return rear - front + 1;
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

    printf("%d\n", queueSize());

    return 0;
}