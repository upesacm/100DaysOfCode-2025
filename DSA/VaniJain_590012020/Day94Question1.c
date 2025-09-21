#include <stdio.h>
int max(int a, int b) 
{
    return (a > b) ? a : b;
}
int main() 
{
    int N;
    printf("Enter size of the array: ");
    scanf("%d", &N);
    if (N <= 0) 
    {
        printf("Array size must be positive.\n");
        return 0;
    }
    int arr[N];
    printf("Enter array elements:\n");
    for (int i = 0; i < N; i++) 
    {
        scanf("%d", &arr[i]);
    }
    int dp[N];
    for (int i = 0; i < N; i++) dp[i] = 1; 
    for (int i = 1; i < N; i++) 
    {
        for (int j = 0; j < i; j++) 
        {
            if (arr[i] > arr[j]) 
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int lisLength = dp[0];
    for (int i = 1; i < N; i++)
        if (dp[i] > lisLength)
            lisLength = dp[i];
    printf("Length of Longest Increasing Subsequence = %d\n", lisLength);
    return 0;
}
