//1. right should be n - 1 not n, because array indices go from 0 to n - 1.
//2. We use left < right to ensure we don’t use the same element twice.
//If left == right, both pointers point to the same element, which isn’t allowed for a distinct pair.
// Corrected code -



#include <stdio.h>
#include <stdbool.h>

bool hasPairWithSum(int arr[], int n, int target) 
{
    int left = 0;
    int right = n-1;
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
