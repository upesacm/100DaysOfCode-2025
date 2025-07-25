#include <stdio.h>

#define MAX 100

int main()
{
    int n, h[MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &h[i]);

    int stack[MAX], top = -1, max = 0, i = 0;

    while (i < n)
    {
        if (top == -1 || h[i] >= h[stack[top]])
            stack[++top] = i++;
        else
        {
            int ht = h[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            int area = ht * width;
            if (area > max)
                max = area;
        }
    }

    while (top != -1)
    {
        int ht = h[stack[top--]];
        int width = (top == -1) ? i : i - stack[top] - 1;
        int area = ht * width;
        if (area > max)
            max = area;
    }

    printf("%d\n", max);
    return 0;
}
