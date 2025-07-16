#include <stdio.h>

int power_2(int n) 
{
    return (n > 0) && ((n & (n - 1)) == 0);
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

    int result = power_2(n);

    printf("%s\n", result ? "Yes" : "No");

    return 0;
}