// Solution 2: Pair Sum in Sorted Array (Two-Pointer Technique)

#include <stdio.h>
#include <stdbool.h>

// Function to check if a pair exists that sums to target
bool hasPairWithSum(int arr[], int n, int target) 
{
    int left = 0;
    // BUG FIX: right should be last index, not n
    int right = n - 1;

    // BUG FIX: loop should run while left < right, not <=
    // because if left == right, we are pointing to the same element
    while (left < right) 
    {
        int sum = arr[left] + arr[right];

        if (sum == target) 
        {
            return true; // Pair found
        } 
        else if (sum < target) 
        {
            left++; // Need a bigger sum → move left pointer rightwards
        } 
        else
        {
            right--; // Need a smaller sum → move right pointer leftwards
        }
    }

    return false; // No pair found
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
Explanation of fixes & answers to tasks:
Task 1:
1. Off-by-one error: `right = n` → changed to `right = n - 1` so it points to the last valid index.
Task 2:
2. Loop condition: should be `left < right` so we never use the same element twice.
Task 3:
3. Code now works correctly for all valid inputs using O(n) two-pointer technique.
*/

