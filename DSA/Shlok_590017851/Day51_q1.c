#include <stdio.h>
#include <string.h>

#define MAX_CHARS 256

int longestSubstringWithKUniqueChars(char *str, int k) 
{
    int n = strlen(str);
    if (n == 0 || k == 0) return 0;

    int count[MAX_CHARS] = {0};
    int unique = 0, maxLen = 0;
    int start = 0;

    for (int end = 0; end < n; end++) 
    {
        if (count[str[end]] == 0) 
        {
            unique++;
        }
        count[str[end]]++;
        while (unique > k) 
        {
            count[str[start]]--;
            if (count[str[start]] == 0) 
            {
                unique--;
            }
            start++;
        }
        if (unique == k) 
        {
            int windowLen = end - start + 1;
            if (windowLen > maxLen) 
            {
                maxLen = windowLen;
            }
        }
    }
    return maxLen;
}
int main() 
{
    char str1[] = "aabacbebebe";
    int k1 = 3;
    printf("Output: %d\n", longestSubstringWithKUniqueChars(str1, k1)); 
    char str2[] = "aaaa";
    int k2 = 2;
    printf("Output: %d\n", longestSubstringWithKUniqueChars(str2, k2)); 
    return 0;
}
