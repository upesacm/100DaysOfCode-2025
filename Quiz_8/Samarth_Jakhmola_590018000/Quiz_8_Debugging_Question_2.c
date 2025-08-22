// 1. 'right' should be initialized to 'n - 1' and not 'n', since array indices go from 0 to n - 1. If we set 'right = n', we'll access
//     out-of-bounds memory.

// 2. The loop condition is '<' instead of '<=' because when 'left == right', both pointers point to the same element, which cannot form a
//    valid pair as it needs two distinct elements.

// 3. Debugged code :

/*
#include <stdio.h>
#include <stdbool.h>

bool hasPairWithSum(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;  // Fixed off-by-one error
    while (left < right)  // Changed '<=' to '<'
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
*/
