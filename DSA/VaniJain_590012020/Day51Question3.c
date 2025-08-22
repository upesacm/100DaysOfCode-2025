#include <stdio.h>
#include <string.h>
#include <limits.h>
#define CHAR_RANGE 256
void minWindowSubstring(char *s, char *t) 
{
    int lenS = strlen(s);
    int lenT = strlen(t);
    if (lenS == 0 || lenT == 0 || lenT > lenS) 
    {
        printf("No valid window exists.\n");
        return;
    }
    int required[CHAR_RANGE] = {0};  
    int window[CHAR_RANGE] = {0}; 
    for (int i = 0; i < lenT; i++) 
    {
        required[(int)t[i]]++;
    }
    int start = 0, minLen = INT_MAX, minStart = 0;
    int count = 0; 
    for (int end = 0; end < lenS; end++) 
    {
        char ch = s[end];
        window[(int)ch]++;
        if (required[(int)ch] > 0 && window[(int)ch] <= required[(int)ch]) 
        {
            count++;
        }
        while (count == lenT) 
        {
            if (end - start + 1 < minLen) 
            {
                minLen = end - start + 1;
                minStart = start;
            }
            char leftChar = s[start];
            window[(int)leftChar]--;
            if (required[(int)leftChar] > 0 && window[(int)leftChar] < required[(int)leftChar]) 
            {
                count--;
            }
            start++;
        }
    }
    if (minLen == INT_MAX) 
    {
        printf("No valid window exists.\n");
    } 
    else 
    {
        printf("Minimum window substring: ");
        for (int i = minStart; i < minStart + minLen; i++) 
        {
            printf("%c", s[i]);
        }
        printf("\n");
    }
}
int main() 
{
    char s[1000], t[1000];
    printf("Enter string s: ");
    scanf("%s", s);
    printf("Enter string t: ");
    scanf("%s", t);
    minWindowSubstring(s, t);
    return 0;
}
