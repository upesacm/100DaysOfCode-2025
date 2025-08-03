#include <stdio.h>

int Power(unsigned int n) 
{
    return n && !(n & (n - 1));
}
int main() 
{
    unsigned int n;
    printf("Enter a number: ");
    scanf("%u", &n);
    if (Power(n))
        printf("%u is a power of 2\n", n);
    else
        printf("%u is not a power of 2\n", n);
    return 0;
}
