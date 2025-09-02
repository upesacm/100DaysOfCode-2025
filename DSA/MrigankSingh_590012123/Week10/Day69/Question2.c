#include <stdio.h>
#include <stdbool.h>

bool canSplitArray(int arr[], int n) {
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }
    
    if (totalSum % 2 != 0) {
        return false;
    }
    
    int target = totalSum / 2;
    
    // Dynamic programming approach for subset sum
    bool dp[target + 1];
    for (int i = 0; i <= target; i++) {
        dp[i] = false;
    }
    dp[0] = true;
    
    for (int i = 0; i < n; i++) {
        for (int j = target; j >= arr[i]; j--) {
            if (dp[j - arr[i]]) {
                dp[j] = true;
            }
        }
    }
    
    return dp[target];
}

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Can split into equal sum: %s\n", 
           canSplitArray(arr, n) ? "true" : "false");
    return 0;
}
