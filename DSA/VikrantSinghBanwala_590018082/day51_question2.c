#include<stdio.h>
#include<limits.h>
int smallestSubarrayWithSumGreaterThanX(int *arr, int n, int x) {
    int minLength = INT_MAX;
    int currentSum = 0;
    int left = 0;
    for (int right = 0; right < n; right++) {
        currentSum += arr[right];
        while (currentSum > x) {
            minLength = (right - left + 1 < minLength) ? (right - left + 1) : minLength;
            currentSum -= arr[left];
            left++;
        }
    }
    return (minLength == INT_MAX) ? 0 : minLength;
}
int main() {
    int arr1[] = {1, 4, 45, 6, 0, 19};
    int x1 = 51;
    printf("%d\n", smallestSubarrayWithSumGreaterThanX(arr1, 6, x1));
    int arr2[] = {1, 10, 5, 2, 7};
    int x2 = 9;
    printf("%d\n", smallestSubarrayWithSumGreaterThanX(arr2, 5, x2));
    return 0;
}