 //1.  Identify the off-by-one error in `right` initialization.
// Bug -The `right` pointer is initialized with `int right = n;`. In a C array of size `n`, valid indices range from `0` to `n-1`. Initializing `right` to `n` points it one position beyond the end of the array, leading to an out-of-bounds memory access (`arr[n]`) and undefined behavior.
// Solution -  The `right` pointer must be initialized to the index of the last element, which is `n - 1`.

// 2.  Why is the loop condition `left < right` instead of `<=`?
//Solution - The goal is to find a **pair** of elements.
//      The condition `left < right` ensures that the `left` and `right` pointers always point to two **distinct** elements.
//      The buggy condition `left <= right` allows the loop to run one extra time when `left == right`. In this case, the code checks if `arr[left] + arr[left]` equals the target, which is incorrect as it's checking a single element with itself, not a pair. The loop should terminate when the pointers cross or meet.

//  3. correct code 
#include <stdio.h>
#include <stdbool.h>
bool hasPairWithSum(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
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

int main() {
    int arr[] = {1, 2, 4, 5, 6, 8}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    if (hasPairWithSum(arr, n, target)) {
        printf("Pair exists\n");
    } else {
        printf("No such pair\n");
    }
    
    int target2 = 15;
    if (hasPairWithSum(arr, n, target2)) {
        printf("Pair exists\n");
    } else {
        printf("No such pair\n");
    }
   
    
    return 0;
}
