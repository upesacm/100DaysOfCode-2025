#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void push(int stack[], int *top, int value) 
{
    stack[++(*top)] = value;
}
int pop(int stack[], int *top) 
{
    return stack[(*top)--];
}
void enqueue(int queue[], int *rear, int value) 
{
    queue[++(*rear)] = value;
}
int dequeue(int queue[], int *front) 
{
    return queue[(*front)++];
}
int main() 
{
    int queue[MAX], stack[MAX];
    int front = 0, rear = -1, top = -1;
    int n, k;
    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);
    if (n > MAX) 
    {
        printf("Queue size exceeds limit!\n");
        return 1;
    }
    printf("Enter the elements of the queue:\n");
    for (int i = 0; i < n; i++) 
    {
        int x;
        scanf("%d", &x);
        enqueue(queue, &rear, x);
    }
    printf("Enter value of k (number of elements to reverse): ");
    scanf("%d", &k);
    if (k > n || k < 0) 
    {
        printf("Invalid value of k!\n");
        return 1;
    }
    for (int i = 0; i < k; i++) 
    {
        push(stack, &top, dequeue(queue, &front));
    }
    int tempRear = -1, tempQueue[MAX];
    while (top != -1) 
    {
        enqueue(tempQueue, &tempRear, pop(stack, &top));
    }
    while (front <= rear) 
    {
        enqueue(tempQueue, &tempRear, dequeue(queue, &front));
    }
    printf("Queue after reversing first %d elements:\n", k);
    for (int i = 0; i <= tempRear; i++) 
    {
        printf("%d ", tempQueue[i]);
    }
    return 0;
}
