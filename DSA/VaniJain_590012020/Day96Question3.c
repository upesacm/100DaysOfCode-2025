#include <stdio.h>
#include <stdbool.h>
bool isSubsetSum(int arr[], int n, int sum) 
{
    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++) 
    {
        dp[i][0] = true; 
    }
    for (int j = 1; j <= sum; j++) 
    {
        dp[0][j] = false;
    }
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= sum; j++) 
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}
bool canPartition(int arr[], int n) 
{
    int totalSum = 0;
    for (int i = 0; i < n; i++) 
    {
        totalSum += arr[i];
    }
    if (totalSum % 2 != 0) 
    {
        return false;
    }
    return isSubsetSum(arr, n, totalSum / 2);
}
int main() 
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of the array:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    if (canPartition(arr, n))
        printf("Array can be partitioned into two subsets of equal sum.\n");
    else
        printf("Array cannot be partitioned into two subsets of equal sum.\n");
    return 0;
}
