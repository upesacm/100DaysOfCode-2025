#include <stdio.h>
#include <stdbool.h>

bool hasPairWithSum(int arr[], int n, int target) 
{
    if (n < 2) return false;        // need at least two elements
    int left = 0;
    int right = n - 1;              //Fixed: right = n; as indices go till n-1, it should be n-1 and not n.

    while (left < right)            //We use left < right instead of left <= right, as we need distinct pairs.
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
