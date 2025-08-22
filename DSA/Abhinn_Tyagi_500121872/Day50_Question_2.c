#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool compareFreq(int *a, int *b) {
    for (int i = 0; i < 26; i++)
        if (a[i] != b[i])
            return false;
    return true;
}

int countAnagramOccurrences(char *text, char *pattern) {
    int textLen = strlen(text), patLen = strlen(pattern);
    if (patLen > textLen) return 0;

    int count = 0;
    int patFreq[26] = {0}, windowFreq[26] = {0};

    for (int i = 0; i < patLen; i++) {
        patFreq[pattern[i] - 'a']++;
        windowFreq[text[i] - 'a']++;
    }

    if (compareFreq(patFreq, windowFreq)) count++;

    for (int i = patLen; i < textLen; i++) {
        windowFreq[text[i] - 'a']++;
        windowFreq[text[i - patLen] - 'a']--;
        if (compareFreq(patFreq, windowFreq)) count++;
    }

    return count;
}

int main() {
    printf("Occurrences: %d\n", countAnagramOccurrences("forxxorfxdofr", "for"));  
    printf("Occurrences: %d\n", countAnagramOccurrences("aabaabaa", "aaba"));      
    return 0;
}
