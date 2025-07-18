#include <stdio.h>

int OppSigns(int a, int b) 
{
    return (a ^ b) < 0; // XOR sign bits, negative if different
}
int main() 
{
    int x, y;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    if (OppSigns(x, y)) 
    {
        printf("%d and %d have opposite signs\n", x, y);
    } 
    else 
    {
        printf("%d and %d have same signs\n", x, y);
    }
    return 0;
}
