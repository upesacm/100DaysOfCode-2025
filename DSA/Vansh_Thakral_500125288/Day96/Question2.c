#include <stdio.h>

int subsetSum(int arr[], int n, int sum) {
    int dp[n+1][sum+1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1; // Sum 0 always possible (empty subset)
    for (int j = 1; j <= sum; j++)
        dp[0][j] = 0; // No items, positive sum not possible

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i-1] <= j)
                dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main() {
    int arr1[] = {3,34,4,12,5,2};
    printf("%s\n", subsetSum(arr1, 6, 9) ? "Yes" : "No"); // Output: Yes

    int arr2[] = {1,2,3};
    printf("%s\n", subsetSum(arr2, 3, 7) ? "Yes" : "No"); // Output: No
    return 0;
}

//Time Complexity: O(n*sum)
// Space Complexity: O(n*sum)
