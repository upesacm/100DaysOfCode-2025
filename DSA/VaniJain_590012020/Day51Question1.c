#include <stdio.h>
#include <string.h>
#define MAX_LEN 1000
#define CHAR_RANGE 256
int longestSubstringWithKUnique(char *str, int k) 
{
    int freq[CHAR_RANGE] = {0};
    int start = 0, end = 0;
    int maxLen = 0;
    int uniqueCount = 0;
    int len = strlen(str);
    while (end < len) 
    {

        if (freq[(int)str[end]] == 0) 
        {
            uniqueCount++;
        }
        freq[(int)str[end]]++;
        end++;
        while (uniqueCount > k) 
        {
            freq[(int)str[start]]--;
            if (freq[(int)str[start]] == 0) 
            {
                uniqueCount--;
            }
            start++;
        }
        if (uniqueCount == k) 
        {
            int windowLen = end - start;
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
    char str[MAX_LEN];
    int k;
    printf("Enter the string: ");
    scanf("%s", str);
    printf("Enter the value of k (number of unique characters): ");
    scanf("%d", &k);
    int result = longestSubstringWithKUnique(str, k);
    if (result > 0) 
    {
        printf("Length of longest substring with exactly %d unique characters: %d\n", k, result);
    } 
    else 
    {
        printf("No substring with exactly %d unique characters found.\n", k);
    }
    return 0;
}
