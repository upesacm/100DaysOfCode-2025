#include <stdio.h>
int main() 
{
    int N;
    printf("Enter number of steps: ");
    scanf("%d", &N);
    if (N < 0) 
    {
        printf("Invalid input! N must be non-negative.\n");
        return 0;
    }
    if (N == 0) 
    {
        printf("Number of ways to reach step 0 = 1\n");
        return 0;
    }
    int dp[N+1];  
    dp[0] = 1;   
    dp[1] = 1;    
    for (int i = 2; i <= N; i++) 
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    printf("Number of ways to reach step %d = %d\n", N, dp[N]);
    return 0;
}
