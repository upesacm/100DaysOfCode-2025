#include <stdio.h>

int main()
{
    int n, i;
    scanf("%d %d", &n, &i);
    int res = n | (1 << i);
    printf("%d\n", res);
    return 0;
}
