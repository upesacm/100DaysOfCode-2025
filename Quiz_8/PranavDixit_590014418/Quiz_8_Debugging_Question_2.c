/*
  Debugging Question: Two-Pointer Pair Sum

  Task 1:
  - Bug: `right` was initialized to `n` (off-by-one).
  - Fix: It should be `n - 1` because valid indices are 0..n-1.

  Task 2:
  - Why `left < right` (not `<=`):
    If `left == right` we'd be using the same element twice.
    We want two distinct indices, so the loop must run while left < right.
*/

#include <stdio.h>
#include <stdbool.h>

bool hasPairWithSum(int arr[], int n, int target)
{
    if (n < 2) return false;

    int left = 0;
    int right = n - 1;   // fixed off-by-one here

    while (left < right) // use < so we don't pair an element with itself
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
