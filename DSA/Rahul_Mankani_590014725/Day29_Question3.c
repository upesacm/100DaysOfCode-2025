#include <stdio.h>

int bit(int n, int i) 
{
    // Create mask with 1 at position i (1 << i)
    int mask = 1 << i;
    // Set i-th bit to 1 using OR and return result
    return n | mask;
}
int main() 
{
    int n, i;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Enter bit position (0-indexed): ");
    scanf("%d", &i);
    int result = bit(n, i);
    printf("After setting bit %d, %d becomes: %d\n", i, n, result);
    return 0;
}
