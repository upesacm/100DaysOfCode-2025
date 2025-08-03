#include <stdio.h>

int Bit(int n) 
{
    return n & (-n); // AND with two's complement isolates rightmost set bit
}
int main() 
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int result = Bit(n);
    printf("Isolated rightmost set bit: %d\n", result);
    return 0;
}
