//right in right initialization
//right is set to n, which is past the last index. It should be n - 1

//want two distinct indices for the pair. left < right ensures we never use the same element twice
//and stops when the two pointers cross.

//correct code 
#include <stdio.h>
#include <stdbool.h>

bool hasPairWithSum(int arr[], int n, int target) 
{
    if (n < 2) return false;
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
