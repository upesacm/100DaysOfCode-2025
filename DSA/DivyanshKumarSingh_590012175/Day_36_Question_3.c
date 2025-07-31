#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val)
{
    stack[++top] = val;
}

int pop()
{
    return stack[top--];
}

void insertBottom(int x)
{
    if (top == -1)
    {
        push(x);
        return;
    }
    int y = pop();
    insertBottom(x);
    push(y);
}

int main()
{
    int n, x;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter stack elements (top to bottom): ");
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        push(a);
    }

    printf("Enter element to insert at bottom: ");
    scanf("%d", &x);

    insertBottom(x);

    printf("Stack after insertion (top to bottom): ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");

    return 0;
}
