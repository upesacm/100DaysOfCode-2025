#include <stdio.h>
#include <string.h>
#define CHAR_RANGE 256 
int longestUniqueSubstring(char *str) 
{
    int n = strlen(str);
    int lastIndex[CHAR_RANGE]; 
    for (int i = 0; i < CHAR_RANGE; i++)
        lastIndex[i] = -1;
    int maxLen = 0;
    int start = 0; 
    for (int end = 0; end < n; end++) 
    {
        if (lastIndex[(unsigned char)str[end]] >= start) 
        {
            start = lastIndex[(unsigned char)str[end]] + 1;
        }
        lastIndex[(unsigned char)str[end]] = end;
        int windowLen = end - start + 1;
        if (windowLen > maxLen)
            maxLen = windowLen;
    }
    return maxLen;
}
int main()
{
    char str[1000];
    printf("Enter a string: ");
    scanf("%[^\n]", str); 
    int result = longestUniqueSubstring(str);
    printf("Length of longest substring without repeating characters = %d\n", result);
    return 0;
}
