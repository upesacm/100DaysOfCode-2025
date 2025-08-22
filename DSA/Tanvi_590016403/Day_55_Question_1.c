#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ------------ 1. Longest Subarray with Sum K ------------
int longestSubarraySumK(int arr[], int n, int k) {
    int maxLen = 0;
    int prefixSum = 0;

    // Using hash map simulation with arrays
    int *map = (int*)malloc(sizeof(int) * (n*100)); // big enough for example
    for (int i = 0; i < n*100; i++) map[i] = -2; // initialize
    
    map[0 + n*50] = -1; // prefix sum 0 occurs at index -1

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int idx = prefixSum - k + n*50;
        if (idx >= 0 && idx < n*100 && map[idx] != -2) {
            int length = i - map[idx];
            if (length > maxLen) maxLen = length;
        }

        int sumIndex = prefixSum + n*50;
        if (sumIndex >= 0 && sumIndex < n*100 && map[sumIndex] == -2) {
            map[sumIndex] = i;
        }
    }
    free(map);
    return maxLen;
}

// ------------ 2. Longest Substring with All Distinct Characters ------------
int longestUniqueSubstring(char *s) {
    int lastIndex[256];
    for (int i = 0; i < 256; i++) lastIndex[i] = -1;

    int maxLen = 0, start = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (lastIndex[(unsigned char)s[i]] >= start) {
            start = lastIndex[(unsigned char)s[i]] + 1;
        }
        lastIndex[(unsigned char)s[i]] = i;
        if (i - start + 1 > maxLen) maxLen = i - start + 1;
    }
    return maxLen;
}

// ------------ 3. Binary Subarray with Sum ------------
int countBinarySubarraysWithSum(int nums[], int n, int goal) {
    int *count = (int*)calloc(n+goal+5, sizeof(int));
    int prefixSum = 0, result = 0;
    count[0] = 1; // prefix sum 0 appears once

    for (int i = 0; i < n; i++) {
        prefixSum += nums[i];
        if (prefixSum - goal >= 0) {
            result += count[prefixSum - goal];
        }
        count[prefixSum]++;
    }
    free(count);
    return result;
}

// ------------ Main Menu ------------
int main() {
    int choice;
    printf("Choose a problem to solve:\n");
    printf("1. Longest Subarray with Sum K\n");
    printf("2. Longest Substring with All Distinct Characters\n");
    printf("3. Binary Subarray with Sum\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int n, k;
        printf("Enter array size: ");
        scanf("%d", &n);
        int arr[n];
        printf("Enter array elements: ");
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        printf("Enter K: ");
        scanf("%d", &k);
        printf("Length of longest subarray = %d\n", longestSubarraySumK(arr, n, k));
    }
    else if (choice == 2) {
        char str[1000];
        printf("Enter string: ");
        scanf("%s", str);
        printf("Length of longest unique substring = %d\n", longestUniqueSubstring(str));
    }
    else if (choice == 3) {
        int n, goal;
        printf("Enter binary array size: ");
        scanf("%d", &n);
        int nums[n];
        printf("Enter binary array elements: ");
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        printf("Enter goal: ");
        scanf("%d", &goal);
        printf("Count of binary subarrays with sum = %d\n", countBinarySubarraysWithSum(nums, n, goal));
    }
    else {
        printf("Invalid choice!\n");
    }

    return 0;
}
