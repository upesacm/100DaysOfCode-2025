#include <stdio.h>
int main() 
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int carry = 1; 
    while (n & carry) 
    {
        n = n ^ carry;       
        carry = carry << 1; 
    }
    n = n ^ carry;
    printf("Result after adding 1: %d\n", n);
    return 0;
}
