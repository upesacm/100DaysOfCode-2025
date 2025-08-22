#include <stdio.h>
#include <stdbool.h>

bool hasPairWithSum(int arr[], int n, int target) 
{
    // Corrected initialization of the right pointer to the last index
    int left = 0;
    int right = n - 1; 

    // Corrected loop condition to prevent the pointers from crossing or pointing to the same element
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
