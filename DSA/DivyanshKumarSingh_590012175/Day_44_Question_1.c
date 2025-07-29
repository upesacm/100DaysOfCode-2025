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

void displayQueue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
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


    displayQueue();
    
    return 0;
}
