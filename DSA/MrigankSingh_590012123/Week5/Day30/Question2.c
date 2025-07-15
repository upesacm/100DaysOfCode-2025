#include <stdio.h>
#include <limits.h>

int toggle_i_bit(int n, int i) 
{
    return n ^ (1 << i);
}

int main() 
{
    int n, i;

    printf("Enter an integer n: ");
    if (scanf("%d", &n) != 1) 
    {
        printf("Error: Invalid integer input.\n");
        return 1;
    }

    printf("Enter bit position i (0-indexed): ");
    if (scanf("%d", &i) != 1 || i < 0 || i >= sizeof(int) * CHAR_BIT) 
    {
        printf("Error: Invalid bit position. Must be non-negative and < %zu.\n", sizeof(int) * CHAR_BIT);
        return 1;
    }

    int result = toggle_i_bit(n, i);
    printf("%d\n", result);

    return 0;
}