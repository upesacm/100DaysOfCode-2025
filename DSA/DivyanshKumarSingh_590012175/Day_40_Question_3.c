#include <stdio.h>

#define MAX 100

int stack[MAX], maxStack[MAX];
int top = -1, maxTop = -1;

void push(int x)
{
    stack[++top] = x;
    if (maxTop == -1 || x >= maxStack[maxTop])
        maxStack[++maxTop] = x;
    printf("Pushed %d\n", x);
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }
    int val = stack[top--];
    if (val == maxStack[maxTop])
        maxTop--;
    printf("Popped %d\n", val);
}

int getMax()
{
    if (maxTop == -1)
        return -1;
    return maxStack[maxTop];
}

int main()
{
    int n, op, x;
    printf("Enter number of operations: ");
    scanf("%d", &n);

    printf("\nInstructions:\n");
    printf("1 x - Push x to stack\n");
    printf("2   - Pop from stack\n");
    printf("3   - Print current maximum\n\n");

    for (int i = 0; i < n; i++)
    {
        printf("Operation %d: ", i + 1);
        scanf("%d", &op);
        if (op == 1)
        {
            printf("Enter value to push: ");
            scanf("%d", &x);
            push(x);
        }
        else if (op == 2)
        {
            pop();
        }
        else if (op == 3)
        {
            int max = getMax();
            if (max == -1)
                printf("Stack is empty. No maximum.\n");
            else
                printf("Current maximum: %d\n", max);
        }
        else
        {
            printf("Invalid operation. Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}
