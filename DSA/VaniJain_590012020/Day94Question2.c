#include <stdio.h>
#include <string.h>
int max(int a, int b) 
{
    return (a > b) ? a : b;
}
int main() 
{
    char str1[1000], str2[1000];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    int m = strlen(str1);
    int n = strlen(str2);
    int dp[m+1][n+1];
    for (int i = 0; i <= m; i++) 
    {
        for (int j = 0; j <= n; j++) 
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    printf("Length of Longest Common Subsequence = %d\n", dp[m][n]);
    return 0;
}
