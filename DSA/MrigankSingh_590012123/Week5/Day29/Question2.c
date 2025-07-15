#include <stdio.h>

int i_bit(int n, int i) {
    return (n >> i) & 1;
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
    if (scanf("%d", &i) != 1 || i < 0 || i >= 32) 
    { 
        printf("Error: Invalid bit position. Must be non-negative and < 32.\n");
        return 1;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    int result = i_bit(n, i);

    printf("%d\n", result);

    return 0;
}