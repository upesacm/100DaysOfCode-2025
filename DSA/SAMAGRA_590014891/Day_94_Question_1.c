#include <stdio.h>

int lengthOfLIS(int arr[], int n) {
    int dp[n], max = 1;
    for (int i = 0; i < n; i++) dp[i] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
        if (dp[i] > max) max = dp[i];
    }
    return max;
}

int main() {
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("LIS length = %d\n", lengthOfLIS(arr, n));
    return 0;
}
