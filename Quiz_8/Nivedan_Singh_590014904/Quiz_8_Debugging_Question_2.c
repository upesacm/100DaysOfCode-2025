#include <stdio.h>
#include <stdbool.h>

bool hasPairWithSum(int arr[], int n, int target) 
{
    int left = 0;
    int right = n-1; //we're using n but we should just use till n-1 as using till n will cause indexing error because in array indexong starts from 0 to n-1.
    while (left <= right) 
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

Tasks:
1. Identify the off-by-one error in right initialization.

2. Why is the loop condition left < right instead of <=?
  //Because we dont want two same elements to be used twice which might happen is we use the "=" sign.

3. Debug the code to work correctly for all valid inputs
