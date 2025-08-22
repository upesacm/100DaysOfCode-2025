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
//Array indices in C are 0-based, meaning for an array of size n, the valid indices are from 0 to n-1. The code initializes right to n, which points to a memory location outside the array's bounds. The correct initial value for the right pointer should be n-1
//The goal of the two-pointer approach is to find a pair of distinct elements. If left and right become equal, it means all possible pairs have been checked without finding a solution.