#include <stdio.h>

int smallestSubarray(int arr[], int n, int x) {
    int sum = 0, minLen = n + 1, left = 0;
    for (int right = 0; right < n; right++) {
        sum += arr[right];
        while (sum > x) {
            if (right - left + 1 < minLen) minLen = right - left + 1;
            sum -= arr[left++];
        }
    }
    return minLen == n + 1 ? 0 : minLen;
}

int main() {
    int arr[] = {1, 4, 45, 6, 0, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 51;
    printf("%d", smallestSubarray(arr, n, x));
    return 0;
}
