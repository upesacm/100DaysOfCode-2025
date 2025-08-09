#include <stdio.h>
#include <stdlib.h>

int longestSubarraySumK(int* arr, int n, int k) {
    int maxLen = 0, sum = 0;
    int* map = (int*)malloc(sizeof(int) * 100000);
    for (int i = 0; i < 100000; i++) map[i] = -2;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == k) maxLen = i + 1;
        if (map[sum - k + 50000] != -2)
            if (i - map[sum - k + 50000] > maxLen)
                maxLen = i - map[sum - k + 50000];
        if (map[sum + 50000] == -2)
            map[sum + 50000] = i;
    }
    free(map);
    return maxLen;
}

int main() {
    int n, k;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter target sum k: ");
    scanf("%d", &k);
    int result = longestSubarraySumK(arr, n, k);
    printf("Length of longest subarray with sum %d is: %d\n", k, result);
    return 0;
}
