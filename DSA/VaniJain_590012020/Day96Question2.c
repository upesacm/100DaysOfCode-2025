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
int main() 
{
    int n, sum;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of the array:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter target sum: ");
    scanf("%d", &sum);
    if (isSubsetSum(arr, n, sum))
        printf("Subset with the given sum exists.\n");
    else
        printf("No subset with the given sum exists.\n");
    return 0;
}
