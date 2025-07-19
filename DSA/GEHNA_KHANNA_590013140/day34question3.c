#include <stdio.h>
int main() 
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int left = 31; 
    while (((n >> left) & 1) == 0 && left > 0) 
    {
        left--; 
    }
    int right = 0; 
    int isPalindrome = 1;
    while (left > right) 
    {
        int leftBit = (n >> left) & 1;
        int rightBit = (n >> right) & 1;
        if (leftBit != rightBit) 
        {
            isPalindrome = 0; 
            break;
        }
        left--;
        right++;
    }
    if (isPalindrome)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
