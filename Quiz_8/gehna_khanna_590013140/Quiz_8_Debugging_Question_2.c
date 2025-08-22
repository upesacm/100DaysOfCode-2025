//1.Off-by-one bug
int right = n; is wrong. Array last valid index is n - 1, so it should be:int right = n - 1;
With right = n the code reads arr[n] (out of bounds).
//2.Why left < right (not <=) We want two distinct indices for the pair. left < right ensures the pointers point to two different elements. 
//Using <= would let left == right and test the same element twice (usually not allowed) and can give incorrect results. 
// Also, left < right is the natural termination when the pointers cross (no pair found).
//3.#include <stdio.h>
#include <stdbool.h>

bool hasPairWithSum(int arr[], int n, int target) 
{
    if (n < 2) return false;      // nothing to pair
    int left = 0;
    int right = n - 1;            // <-- fixed

    while (left < right)          // use < so indices are distinct
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
        printf("Pair exists\n");
    else 
        printf("No such pair\n");
    return 0;
}
