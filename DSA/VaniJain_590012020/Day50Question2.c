#include <stdio.h>
#include <string.h>
#define CHAR_COUNT 256 
int areEqual(int a[], int b[]) 
{
    for (int i = 0; i < CHAR_COUNT; i++) 
    {
        if (a[i] != b[i])
            return 0;
    }
    return 1;
}
int countAnagramOccurrences(char *text, char *pattern) 
{
    int count = 0;
    int lenText = strlen(text);
    int lenPattern = strlen(pattern);
    if (lenPattern > lenText) 
    {
        return 0;
    }
    int freqPattern[CHAR_COUNT] = {0};
    int freqWindow[CHAR_COUNT] = {0};
    for (int i = 0; i < lenPattern; i++) 
    {
        freqPattern[(int)pattern[i]]++;
        freqWindow[(int)text[i]]++;
    }
    if (areEqual(freqPattern, freqWindow)) 
    {
        count++;
    }
    for (int i = lenPattern; i < lenText; i++) 
    {
        freqWindow[(int)text[i]]++;              
        freqWindow[(int)text[i - lenPattern]]--;  
        if (areEqual(freqPattern, freqWindow)) 
        {
            count++;
        }
    }
    return count;
}
int main() 
{
    char text[1000], pattern[100];
    printf("Enter the text: ");
    scanf("%s", text);
    printf("Enter the pattern: ");
    scanf("%s", pattern);
    int result = countAnagramOccurrences(text, pattern);
    printf("Number of anagram occurrences: %d\n", result);
    return 0;
}
