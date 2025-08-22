#include <stdio.h>
#include <stdbool.h>

bool hasPairWithSum(int arr[], int n, int target) 
{
    int left = 0;
    int right = n;
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

// Tasks:
// 1. Identify the off-by-one error in right initialization.
// it should be < and not <=
// 2. Why is the loop condition left < right instead of <=?
// becase we dont want to go to n but n-1
// 3. Debug the code to work correctly for all valid inputs.
// Pair exists