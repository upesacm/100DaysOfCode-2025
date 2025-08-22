#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define CHAR 256
bool compare(int *arr1, int *arr2) 
{
    for (int i = 0; i < CHAR; i++) 
    {
        if (arr1[i] != arr2[i])
            return false;
    }
    return true;
}
int countAnagramOccurrences(char *text, char *pattern) 
{
    int text_len = strlen(text);
    int pat_len = strlen(pattern);

    if (pat_len > text_len)
        return 0;

    int pat_count[CHAR] = {0};
    int win_count[CHAR] = {0};

    for (int i = 0; i < pat_len; i++) 
    {
        pat_count[(int)pattern[i]]++;
        win_count[(int)text[i]]++;
    }
    int count = 0;
    for (int i = pat_len; i < text_len; i++)
      {
        if (compare(pat_count, win_count))
            count++;

        win_count[(int)text[i]]++;
        win_count[(int)text[i - pat_len]]--;
    }
    if (compare(pat_count, win_count))
        count++;
    return count;
}
int main()
{
    char text1[] = "forxxorfxdofr";
    char pattern1[] = "for";
    printf("Count: %d\n", countAnagramOccurrences(text1, pattern1)); 

    char text2[] = "aabaabaa";
    char pattern2[] = "aaba";
    printf("Count: %d\n", countAnagramOccurrences(text2, pattern2));  
    return 0;
}
