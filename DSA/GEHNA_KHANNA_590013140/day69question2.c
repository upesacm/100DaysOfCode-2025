#include <stdio.h>
#include <stdbool.h>

bool can_partition(int* arr, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) total += arr[i];
    if (total % 2 != 0) return false;
    int target = total / 2;
    bool dp[target + 1];
    for (int i = 0; i <= target; i++) dp[i] = false;
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = target; j >= arr[i]; j--) {
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }
    return dp[target];
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("%s\n", can_partition(arr, n) ? "true" : "false");
    return 0;
}
