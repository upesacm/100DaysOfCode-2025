#include <stdio.h>

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int res = n & (-n);
    printf("Result: %d\n", res);
    return 0;
}
