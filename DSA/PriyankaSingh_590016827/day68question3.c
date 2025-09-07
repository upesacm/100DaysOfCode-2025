#include <stdio.h>
#include <stdlib.h>

// A helper function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// A helper function to sort an array
void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Max Sum After K Negations
int largestSumAfterKNegations(int nums[], int n, int k) {
    sort(nums, n);
    
    for (int i = 0; i < n; i++) {
        if (nums[i] < 0 && k > 0) {
            nums[i] = -nums[i];
            k--;
        }
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }
    
    if (k % 2 == 1) {
        sort(nums, n);
        sum -= 2 * nums[0];
    }
    
    return sum;
}

int main() {
    // Example 1
    int nums1[] = {4, 2, 3};
    int k1 = 1;
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Maximum sum after %d negations: %d\n", k1, largestSumAfterKNegations(nums1, n1, k1));

    // Example 2
    int nums2[] = {3, -1, 0, 2};
    int k2 = 3;
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Maximum sum after %d negations: %d\n", k2, largestSumAfterKNegations(nums2, n2, k2));

    return 0;
}
