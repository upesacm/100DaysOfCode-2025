1. Identify the off-by-one error in right initialization.
  In the given code: int right = n;
This is wrong because array indexes go from 0 to n-1.
If we set right = n, then arr[right] will try to access an out-of-bounds element.
here is the fix:
int right = n - 1;

2. Why is the loop condition left < right instead of <=?
we use,
while (left < right)
because,If left == right, it means both pointers are on the same element.

We can’t use the same element twice to form the sum.

So, we stop when left meets or crosses right.

If we use <=, the loop will check the same element twice and may give incorrect results.

3. Debug the code to work correctly for all valid inputs.
#include <stdio.h>
#include <stdbool.h>

bool hasPairWithSum(int arr[], int n, int target) 
{
    int left = 0;
    int right = n - 1;  

    while (left < right) 
    {
        int sum = arr[left] + arr[right];

        if (sum == target) 
        {
            return true; 
        } 
        else if (sum < target) 
        {
            left++; 
        } 
        else 
        {
            right--; 
        }
    }
    return false;
}

int main() 
{
    int arr[] = {1, 2, 4, 5, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    if (hasPairWithSum(arr, n, target)) 
    {
        printf("Pair exists\n");
    } 
    else 
    {
        printf("No such pair\n");
    }

    return 0;
}
It will give output: Pair exists

