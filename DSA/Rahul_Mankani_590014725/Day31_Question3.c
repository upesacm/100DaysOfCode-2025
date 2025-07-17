#include <stdio.h>

int div(int n) 
{
    return n >> 1;
}
int main() 
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("%d divided by 2 is %d\n", n, div(n));
    return 0;
}
