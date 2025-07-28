#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void reverseFirstK(int queue[], int n, int k)
{
    int stack[MAX], top = -1;
    int result[MAX], idx = 0;

    for (int i = 0; i < k; i++)
    {
        stack[++top] = queue[i];
    }

    while (top != -1)
    {
        result[idx++] = stack[top--];
    }

    for (int i = k; i < n; i++)
    {
        result[idx++] = queue[i];
    }

    printf("Resulting Queue: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main()
{
    int queue1[] = {1, 2, 3, 4, 5};
    reverseFirstK(queue1, 5, 3);

    int queue2[] = {10, 20, 30};
    reverseFirstK(queue2, 3, 2);

    return 0;
}
