#include <stdio.h>
#include <stdbool.h>

// Function to check if there exists a pair in a sorted array summing to target
bool hasPairWithSum(int arr[], int n, int target) 
{
    int left = 0;         // Start pointer at the first element
    int right = n - 1;    // FIX: Last valid index is n - 1

    // Check pairs until pointers cross
    while (left < right)  // FIX: Only check while left < right
    {
        int sum = arr[left] + arr[right];

        if (sum == target) 
        {
            // Found a valid pair
            return true;
        } 
        else if (sum < target) 
        {
            // Sum too small → move left pointer right to increase sum
            left++;
        } 
        else 
        {
            // Sum too large → move right pointer left to decrease sum
            right--;
        }
    }

    // No pair found
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
