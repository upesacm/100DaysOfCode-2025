#include <stdio.h>

#define MAX 100

int stack[MAX], top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int isEmpty()
{
    return top == -1;
}

void insertBottom(int x)
{
    if (isEmpty())
    {
        push(x);
        return;
    }
    int a = pop();
    insertBottom(x);
    push(a);
}

void reverse()
{
    if (isEmpty())
        return;
    int x = pop();
    reverse();
    insertBottom(x);
}

int main()
{
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        push(x);
    }
    reverse();
    for (int i = 0; i < n; i++)
        printf("%d ", stack[i]);
    return 0;
}
