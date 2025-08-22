/*
1.The variable right should be initialized to n - 1 instead of n. 
This is because array indices start from 0, so last index of array is n - 1.

2.Why the loop condition is left < right instead of <=?
 The condition should be left < right to ensure that two pointers do not point to same element. 
 If they do, it would mean that we are trying to use same element twice, which is not allowed when looking for a pair.
 
 correct code*/
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
