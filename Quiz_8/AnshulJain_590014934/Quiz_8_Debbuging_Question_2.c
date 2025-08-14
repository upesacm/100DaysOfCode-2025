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
/*
1. Off-by-one error: right was initialized to n; it should be n - 1.
2. Loop condition: use left < right (not <=) to avoid using the same element twice and to ensure we're checking pairs of distinct indices.
3. Debugged: fixed right initialization and loop condition. The corrected program works for all valid inputs.
*/
