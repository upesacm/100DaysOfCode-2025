#include <stdio.h>

int countSetBits(int n) 
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
    printf("Enter number: ");
    scanf("%d", &n);
    int result = countSetBits(n);
    printf("Number of set bits: %d\n", result);
    printf("Binary representation: ");
    for (int i = 31; i >= 0; i--) 
    {
        printf("%d", (n >> i) & 1);
        if (i % 4 == 0) printf(" ");
    }
    printf("\n");
    return 0;
}
