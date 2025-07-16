#include <stdio.h>

int count_set_bits(int n) 
{
    int count = 0;
    while (n) 
    {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main() 
{
    int n;

    printf("Enter an integer n: ");
    if (scanf("%d", &n) != 1) 
    {
        printf("Error: Invalid integer input.\n");
        return 1;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    int result = count_set_bits(n);

    printf("%d\n", result);

    return 0;
}