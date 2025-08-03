#include <stdio.h>

void swap(int *a, int *b) 
{
    *a = *a ^ *b; // a now holds a XOR b
    *b = *a ^ *b; // b becomes original a
    *a = *a ^ *b; // a becomes original b
}
int main() 
{
    int x, y;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap: x = %d, y = %d\n", x, y);
    return 0;
}
