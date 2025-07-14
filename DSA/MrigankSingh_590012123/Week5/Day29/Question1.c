#include <stdio.h>

int main() 
{
    int n;

    printf("Enter an integer: ");
    if (scanf("%d", &n) != 1) 
    {
        printf("Invalid input\n");
        return 1;
    }

    if (n & 1) 
    {
        printf("Odd\n");
    } 
    else 
    {
        printf("Even\n");
    }

    return 0;
}