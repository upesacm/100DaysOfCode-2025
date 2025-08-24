#include <stdio.h>

int canPartition(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    if (sum % 2 != 0) return 0;
    int target = sum / 2;
    int dp[target + 1];
    for (int i = 0; i <= target; i++) dp[i] = 0;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = target; j >= arr[i]; j--) {
            if (dp[j - arr[i]]) dp[j] = 1;
        }
    }
    return dp[target];
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("%s\n", canPartition(arr, n) ? "true" : "false");
    return 0;
}
