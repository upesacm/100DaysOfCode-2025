#include <stdio.h>

int even(int n) 
{
    // If n & 1 is 0 - number is even, if 1 - number is odd
    return (n & 1) == 0;
}
int main() 
{
    int n; 
    printf("Enter a number: ");
    scanf("%d", &n);
    if (even(n)) 
    {
        printf("%d is even\n", n);
    } 
    else 
    {
        printf("%d is odd\n", n);
    }
    return 0;
}
