#include <stdio.h>

int mul(int n) 
{
    return n << 1;
}
int main() 
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("%d multiplied by 2 is %d\n", n, mul(n));
    return 0;
}
