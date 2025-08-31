#include <stdio.h>
#include <stdbool.h>
bool isSubsetSum(int arr[], int n, int target) 
{
    bool dp[n+1][target+1];
    for (int i = 0; i <= n; i++) 
    {
        for (int j = 0; j <= target; j++) 
        {
            if (j == 0)
                dp[i][j] = true;   
            else if (i == 0)
                dp[i][j] = false;  
        }
    }
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= target; j++) 
        {
            if (arr[i-1] <= j)  
                dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
            else
                dp[i][j] = dp[i-1][j];  
        }
    }
    return dp[n][target];
}
bool canPartition(int arr[], int n) 
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    if (sum % 2 != 0)
        return false;
    return isSubsetSum(arr, n, sum / 2);
}

int main() 
{
    int arr[] = {1, 5, 11, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    if (canPartition(arr, n))
        printf("Array can be divided into two equal-sum subsets.\n");
    else
        printf("Array cannot be divided into two equal-sum subsets.\n");

    return 0;
}
