#include <stdio.h>

int canPartition(int arr[], int n) {
    int sum = 0, i, j;
    for(i = 0; i < n; i++) sum += arr[i];
    if(sum % 2 != 0) return 0;
    int target = sum / 2;
    int dp[target + 1];
    for(i = 0; i <= target; i++) dp[i] = 0;
    dp[0] = 1;
    for(i = 0; i < n; i++) {
        for(j = target; j >= arr[i]; j--) {
            if(dp[j - arr[i]]) dp[j] = 1;
        }
    }
    return dp[target];
}

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);
    if(canPartition(arr, n)) printf("true\n");
    else printf("false\n");
    return 0;
}
