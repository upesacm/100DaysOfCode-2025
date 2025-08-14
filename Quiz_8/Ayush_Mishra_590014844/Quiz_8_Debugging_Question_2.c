#include<stdio.h>
#include<stdbool.h>

bool hasPairWithSum(int arr[], int n, int target) 
{
    if (n < 2) return false;   // No pair possible

    int left = 0;
    int right = n - 1;         // fix - last valid index

    while (left < right) {     // fix - strict < ensures distinct elements
        int sum = arr[left] + arr[right];

        if (sum == target) {
            return true;
        } else if (sum < target) {
            left++;
        } else {
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

    if (hasPairWithSum(arr, n, target)) {
        printf("Pair exists\n");
    } else {
        printf("No such pair\n");
    }
    return 0;
}
