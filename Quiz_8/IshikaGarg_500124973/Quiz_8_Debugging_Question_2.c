1)
Off-by-one error
right is initialized as n. Valid indices are 0 to n-1. So right = n is out-of-bounds and
leads to undefined behavior (reading arr[n]).
Fix: int right = n - 1;

2) 
Why left < right (not <=)
We want two distinct indices (a pair of different elements). If left == right you would be using
the same element twice (arr[i] + arr[i]), which is not a valid pair unless the problem explicitly allows 
pairing an element with itself. Using left < right ensures we only consider pairs of distinct positions 
and stops once the pointers meet or cross.
3)
#include <stdio.h>
#include <stdbool.h>

bool hasPairWithSum(int arr[], int n, int target)
{
    if (n < 2) return false;        // no pair possible

    int left = 0;
    int right = n - 1;              // CORRECT: last valid index

    while (left < right) {          // stop when pointers meet
        int sum = arr[left] + arr[right];

        if (sum == target) {
            return true;
        } else if (sum < target) {
            left++;                 // need a larger sum -> move left rightward
        } else {
            right--;                // sum too large -> move right leftward
        }
    }
    return false;
}

int main()
{
    int arr[] = {1, 2, 4, 5, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    if (hasPairWithSum(arr, n, target)) {
        printf("Pair exists\n");
    } else {
        printf("No such pair\n");
    }

    return 0;
}
