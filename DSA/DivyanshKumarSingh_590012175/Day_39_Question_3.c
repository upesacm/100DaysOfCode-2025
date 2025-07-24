#include <stdio.h>

#define MAX 100

int arr[MAX], top1 = -1, top2 = MAX;

void push1(int x)
{
    if (top1 + 1 < top2)
    {
        arr[++top1] = x;
        printf("Pushed %d to Stack1\n", x);
    }
    else
    {
        printf("Stack Overflow in Stack1\n");
    }
}

void push2(int x)
{
    if (top1 + 1 < top2)
    {
        arr[--top2] = x;
        printf("Pushed %d to Stack2\n", x);
    }
    else
    {
        printf("Stack Overflow in Stack2\n");
    }
}

void pop1()
{
    if (top1 >= 0)
    {
        printf("Popped %d from Stack1\n", arr[top1--]);
    }
    else
    {
        printf("Stack Underflow in Stack1\n");
    }
}

void pop2()
{
    if (top2 < MAX)
    {
        printf("Popped %d from Stack2\n", arr[top2++]);
    }
    else
    {
        printf("Stack Underflow in Stack2\n");
    }
}

void print1()
{
    printf("Stack1: ");
    if (top1 == -1)
    {
        printf("Empty");
    }
    else
    {
        for (int i = 0; i <= top1; i++)
            printf("%d ", arr[i]);
    }
    printf("\n");
}

void print2()
{
    printf("Stack2: ");
    if (top2 == MAX)
    {
        printf("Empty");
    }
    else
    {
        for (int i = top2; i < MAX; i++)
            printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n, op, st, x;

    printf("Enter number of operations: ");
    scanf("%d", &n);

    printf("\nInstructions:\n");
    printf("To PUSH: Enter 1 <stack_number> <value>\n");
    printf("To POP:  Enter 2 <stack_number>\n\n");

    for (int i = 0; i < n; i++)
    {
        printf("Operation %d: ", i + 1);
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d %d", &st, &x);
            if (st == 1)
                push1(x);
            else if (st == 2)
                push2(x);
            else
                printf("Invalid stack number!\n");
        }
        else if (op == 2)
        {
            scanf("%d", &st);
            if (st == 1)
                pop1();
            else if (st == 2)
                pop2();
            else
                printf("Invalid stack number!\n");
        }
        else
        {
            printf("Invalid operation code!\n");
        }
    }

    printf("\nFinal Stack Status:\n");
    print1();
    print2();

    return 0;
}
