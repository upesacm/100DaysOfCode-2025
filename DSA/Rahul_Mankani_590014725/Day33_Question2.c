#include <stdio.h>

int Bit(int n) 
{
    return n & (n - 1); // AND with (n-1) clears rightmost set bit
}
int main() 
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int result = Bit(n);
    printf("Number after clearing rightmost set bit: %d\n", result);
    return 0;
}
