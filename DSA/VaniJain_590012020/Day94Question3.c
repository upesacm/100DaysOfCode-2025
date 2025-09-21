#include <stdio.h>
#include <string.h>
int min(int a, int b, int c) 
{
    int temp = (a < b) ? a : b;
    return (temp < c) ? temp : c;
}
int main() 
{
    char word1[1000], word2[1000];
    printf("Enter first string: ");
    scanf("%s", word1);
    printf("Enter second string: ");
    scanf("%s", word2);
    int m = strlen(word1);
    int n = strlen(word2);
    int dp[m+1][n+1];
    for (int i = 0; i <= m; i++) 
    {
        for (int j = 0; j <= n; j++) 
        {
            if (i == 0)
                dp[i][j] = j;  
            else if (j == 0)
                dp[i][j] = i;  
            else if (word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
        }
    }
    printf("Minimum edit operations = %d\n", dp[m][n]);
    return 0;
}
