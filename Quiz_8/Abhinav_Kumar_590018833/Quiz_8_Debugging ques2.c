// // 

// The following C code is supposed to check if there exists a pair in a sorted array that sums to target using the two-pointer technique, but it has errors. Fix them.  

// #include <stdio.h>
// #include <stdbool.h>

// bool hasPairWithSum(int arr[], int n, int target) 
// {
//     int left = 0;
//     int right = n;
//     while (left <= right) 
//     {
//         int sum = arr[left] + arr[right];
//         if (sum == target) 
//        {
//             return true;
//         } 
//        else if (sum < target) 
//        {
//             left++;
//         } 
//        else
//        {
//             right--;
//         }
//     }
//     return false;
// }

// int main() 
// {
//     int arr[] = {1, 2, 4, 5, 6, 8};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int target = 10;
//     if (hasPairWithSum(arr, n, target)) 
//     {
//         printf("Pair exists\n");
//     } 
//     else 
//     {
//         printf("No such pair\n");
//     }
//     return 0;
// }

// Tasks:
// 1. Identify the off-by-one error in right initialization.

// 2. Why is the loop condition left < right instead of <=?

// 3. Debug the code to work correctly for all valid inputs.

#include <stdio.h>
#include <stdbool.h>

bool hasPairWithSum(int arr[], int n, int target) 
{
    int left = 0;
    // Bug 1 Fixed: Initialize 'right' to the last valid index.
    int right = n - 1;

    // Bug 2 Fixed: Loop only while the pointers haven't crossed.
    while (left < right) 
    {
        int sum = arr[left] + arr[right];

        if (sum == target) 
        {
            printf("Pair found: (%d, %d)\n", arr[left], arr[right]);
            return true;
        } 
        else if (sum < target) 
        {
            // Sum is too small, need a larger number.
            left++;
        } 
        else // sum > target
        {
            // Sum is too large, need a smaller number.
            right--;
        }
    }
    return false;
}

int main() 
{
    int arr[] = {1, 2, 4, 5, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10; // The pair is (4, 6)

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