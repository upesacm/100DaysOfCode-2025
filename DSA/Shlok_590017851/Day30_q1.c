#include<stdio.h>
int clearBit(intn,inti)
{
    return n & (~(1<<i));
}
int main()
{
    int n,i;
    printf("Enter the number(n): ");
    scanf("%d",&n);
    printf("Enter the bit position to clear(i): ");
    scanf("%d",&i);

    int result = clearBit(n, i);
    printf("Result after clearing bit %d:%d\n",i,result);
    return 0;
}
