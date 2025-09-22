#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
void precomputePalindrome(char s[], int n, bool palindrome[n][n]) 
{
    for (int i = 0; i < n; i++) 
    {
        palindrome[i][i] = true; 
    }
    for (int len = 2; len <= n; len++) 
    {
        for (int i = 0; i <= n - len; i++) 
        {
            int j = i + len - 1;
            if (s[i] == s[j]) 
            {
                if (len == 2) 
                    palindrome[i][j] = true; 
                else 
                    palindrome[i][j] = palindrome[i + 1][j - 1];
            } 
            else 
            {
                palindrome[i][j] = false;
            }
        }
    }
}
int minPalindromeCuts(char s[]) 
{
    int n = strlen(s);
    bool palindrome[n][n];
    precomputePalindrome(s, n, palindrome);
    int cuts[n]; 
    for (int i = 0; i < n; i++) 
    {
        if (palindrome[0][i]) 
        {
            cuts[i] = 0; 
        }
        else 
        {
            cuts[i] = INT_MAX;
            for (int j = 0; j < i; j++) 
            {
                if (palindrome[j + 1][i] && cuts[j] + 1 < cuts[i]) 
                {
                    cuts[i] = cuts[j] + 1;
                }
            }
        }
    }

    return cuts[n - 1]; 
}
int main() 
{
    char s[100];
    printf("Enter a string: ");
    scanf("%s", s);
    int result = minPalindromeCuts(s);
    printf("Minimum cuts needed for palindromic partitioning = %d\n", result);
    return 0;
}
