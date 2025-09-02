#include <stdio.h>
#include <string.h>
#define CHAR_SET 256 
int longestUniqueSubstring(char *str) 
{
    int n = strlen(str);
    int lastIndex[CHAR_SET];   
    for (int i = 0; i < CHAR_SET; i++)
        lastIndex[i] = -1;
    
    int maxLen = 0;  
    int left = 0;    
    for (int right = 0; right < n; right++) 
    {
        char ch = str[right];
        if (lastIndex[(int)ch] >= left) 
        {
            left = lastIndex[(int)ch] + 1;
        }
        lastIndex[(int)ch] = right;
        int windowLen = right - left + 1;
        if (windowLen > maxLen)
            maxLen = windowLen;
    }
    return maxLen;
}
int main() 
{
    char str1[] = "abcabcbb";
    char str2[] = "bbbbb";
    char str3[] = "pwwkew";
    printf("Input: %s -> Longest unique substring length = %d\n", str1, longestUniqueSubstring(str1));
    printf("Input: %s -> Longest unique substring length = %d\n", str2, longestUniqueSubstring(str2));
    printf("Input: %s -> Longest unique substring length = %d\n", str3, longestUniqueSubstring(str3));
    return 0;
}
