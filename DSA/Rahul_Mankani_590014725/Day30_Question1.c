#include <stdio.h>

int clearBit(int n, int i) 
{
    int mask = ~(1 << i);
    return n & mask;
}
int main() 
{
    int n, i;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("Enter bit position to clear (0-based): ");
    scanf("%d", &i);
    if (i < 0 || i > 31) 
    {
        printf("Invalid bit position! Use 0-31.\n");
        return 1;
    }
    int result = clearBit(n, i);
    printf("Number after clearing bit %d: %d\n", i, result);
    printf("Binary (before): ");
    for (int j = 31; j >= 0; j--) 
    {
        printf("%d", (n >> j) & 1);
        if (j % 4 == 0) printf(" ");
    }
    printf("\nBinary (after) : ");
    for (int j = 31; j >= 0; j--) 
    {
        printf("%d", (result >> j) & 1);
        if (j % 4 == 0) printf(" ");
    }
    printf("\n");
    return 0;
}
