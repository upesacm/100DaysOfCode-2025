#include <stdio.h>

int main()
{
    int n, count = 0;
    scanf("%d", &n);
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    printf("%d\n", count);
    return 0;
}
