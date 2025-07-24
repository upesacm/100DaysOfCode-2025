#include <stdio.h>

#define MAX 100

int price[MAX], span[MAX], stack[MAX], top = -1;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &price[i]);

    for (int i = 0; i < n; i++)
    {
        while (top != -1 && price[stack[top]] <= price[i])
            top--;
        if (top == -1)
            span[i] = i + 1;
        else
            span[i] = i - stack[top];
        stack[++top] = i;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", span[i]);

    return 0;
}
