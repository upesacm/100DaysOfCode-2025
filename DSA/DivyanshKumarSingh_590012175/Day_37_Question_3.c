#include <stdio.h>

#define MAX 100

int stack[MAX], top = -1;

void push(int x) { stack[++top] = x; }
int pop() { return stack[top--]; }

void deleteMid(int i, int mid)
{
    if (top == -1)
        return;
    int x = pop();
    if (i != mid)
        deleteMid(i - 1, mid);
    else
        deleteMid(i - 1, mid);
    if (i != mid)
        push(x);
}

int main()
{
    int n, x;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements (top to bottom): ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        push(x);
    }

    int mid = top / 2;
    deleteMid(top, mid);

    printf("Stack after deleting middle (top to bottom): ");
    while (top != -1)
        printf("%d ", pop());
    printf("\n");

    return 0;
}
