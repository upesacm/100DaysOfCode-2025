#include <stdio.h>
#include <limits.h>

#define MAX 100000

int longestSubarraySumK(int arr[], int n, int k) {
    int prefixSum[MAX * 2];
    for (int i = 0; i < MAX * 2; i++) prefixSum[i] = INT_MIN;

    int sum = 0, maxLen = 0;
    prefixSum[MAX] = -1;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == k) maxLen = i + 1;

        int needed = sum - k + MAX;
        if (needed >= 0 && needed < MAX * 2 && prefixSum[needed] != INT_MIN) {
            if (i - prefixSum[needed] > maxLen)
                maxLen = i - prefixSum[needed];
        }
        if (prefixSum[sum + MAX] == INT_MIN)
            prefixSum[sum + MAX] = i;
    }
    return maxLen;
}

int main() {
    int n, k;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter K: ");
    scanf("%d", &k);
    printf("Longest length: %d\n", longestSubarraySumK(arr, n, k));
    return 0;
}
