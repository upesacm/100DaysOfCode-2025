#include <stdio.h>
#include <stdbool.h>

bool hasPairWithSum(int arr[], int n, int target) 
{
    // Quick sanity check: can't find a pair if the array has fewer than 2 elements
    if (n < 2) return false;

    int left = 0;
    int right = n - 1; 
    // Task 1: Bug fix — right was originally set to `n`, which is off by one.
    // Arrays are 0-indexed, so the last valid element is at index `n - 1`.

    while (left < right) 
    {
        // Task 2: Loop should be left < right, not <=.
        // Why? If left == right, we'd be using the same element twice,
        // which doesn't count as a valid "pair" in this context.
        
        int sum = arr[left] + arr[right];

        if (sum == target) 
        {
            return true; // Found a valid pair
        } 
        else if (sum < target) 
        {
            left++; // Sum too small? Move left forward to try something bigger.
        } 
        else 
        {
            right--; // Sum too big? Move right backward to try something smaller.
        }
    }
    return false; // Checked all possibilities, no matching pair found
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
