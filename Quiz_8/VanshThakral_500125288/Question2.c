// 1. Off-by-one error
// right was initialized as n. Arrays are indexed 0..n-1, so right must be n - 1. Using n causes an out-of-bounds access.

// 2. Why left < right (not <=)
// We want two distinct elements (a pair). If we use <=, when left == right the code would sum the same element twice. That can produce a false positive when 2*arr[i] == target but there is only one occurrence of that element. Using left < right avoids this and also avoids unnecessary extra iteration.

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

        if (sum == target) {
           
            return true;
        } 
        else if (sum < target) {
            left++;
        } 
        else {
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


