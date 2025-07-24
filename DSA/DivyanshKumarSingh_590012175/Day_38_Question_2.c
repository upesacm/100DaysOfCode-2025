#include <stdio.h>

#define MAX 100

int stack[MAX], minStack[MAX], top = -1, minTop = -1;

void push(int x)
{
    stack[++top] = x;
    if (minTop == -1 || x <= minStack[minTop])
        minStack[++minTop] = x;
}

int pop()
{
    int x = stack[top--];
    if (x == minStack[minTop])
        minTop--;
    return x;
}

int getMin()
{
    if (minTop == -1)
        return -1;
    return minStack[minTop];
}

int main()
{
    int m, n, x, choice;

    printf("Enter initial number of elements: ");
    scanf("%d", &m);
    printf("Enter %d elements:\n", m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &x);
        push(x);
    }

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("1. Push  2. Pop  3. Get Min: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter value to push: ");
            scanf("%d", &x);
            push(x);
        }
        else if (choice == 2)
        {
            if (top == -1)
                printf("Stack is empty\n");
            else
                printf("Popped: %d\n", pop());
        }
        else if (choice == 3)
        {
            x = getMin();
            if (x == -1)
                printf("Stack is empty\n");
            else
                printf("Min: %d\n", x);
        }
    }

    return 0;
}
