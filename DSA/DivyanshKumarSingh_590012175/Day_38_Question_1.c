#include <stdio.h>

#define MAX 100

int main()
{
    int n, a[MAX], res[MAX], stack[MAX], top = -1;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = n - 1; i >= 0; i--)
    {
        while (top != -1 && stack[top] <= a[i])
            top--;
        if (top == -1)
            res[i] = -1;
        else
            res[i] = stack[top];
        stack[++top] = a[i];
    }

    printf("Next Greater Elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", res[i]);
    printf("\n");

    return 0;
}
