#include <stdio.h>

int main()
{
    int n, val, result = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        result ^= val;
    }
    printf("%d\n", result);
    return 0;
}
