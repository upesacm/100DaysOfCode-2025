#include <stdio.h>

int bit(int n, int i) 
{
    // Create mask with 1 at position i (1 << i)
    int mask = 1 << i;
    // Return 1 if i-th bit is set, 0 otherwise
    return (n & mask) != 0;
}
int main() 
{
    int n, i; 
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Enter bit position (0-indexed): ");
    scanf("%d", &i);
    int bit = bit(n, i);
    printf("Bit at position %d in %d is: %d\n", i, n, bit);
    return 0;
}
