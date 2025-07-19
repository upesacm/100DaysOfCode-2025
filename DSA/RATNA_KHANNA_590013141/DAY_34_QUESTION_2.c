#include <stdio.h>
int main() 
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int borrow = 1;
    while ((n & borrow) == 0) 
    {
        n = n ^ borrow;
        borrow = borrow << 1;
    }
    n = n ^ borrow;
    printf("Result after subtracting 1: %d\n", n);
    return 0;
}
