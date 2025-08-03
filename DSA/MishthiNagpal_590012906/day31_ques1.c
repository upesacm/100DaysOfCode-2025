#include <stdio.h>

int isPowerOfTwo(int n)
{
    return (n > 0) && ((n & (n - 1)) == 0);
}
int main()
{
    int n;
    printf("enter a number");
    scanf("%d", &n);
    if (isPowerOfTwo(n))
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
}