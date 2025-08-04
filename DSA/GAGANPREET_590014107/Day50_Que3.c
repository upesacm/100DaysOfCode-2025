#include <stdio.h>
#include <string.h>

#define CHAR_COUNT 256  


int areSame(int *arr1, int *arr2) {
    for (int i = 0; i < CHAR_COUNT; i++) {
        if (arr1[i] != arr2[i]) {
            return 0;
        }
    }
    return 1;
}


int countAnagramOccurrences(char *text, char *pattern) {
    int textLen = strlen(text);
    int patLen = strlen(pattern);
    if (patLen > textLen) return 0;

    int count = 0;
    int patFreq[CHAR_COUNT] = {0};
    int windowFreq[CHAR_COUNT] = {0};


    for (int i = 0; i < patLen; i++) {
        patFreq[(int)pattern[i]]++;
        windowFreq[(int)text[i]]++;
    }


    for (int i = patLen; i < textLen; i++) {
        if (areSame(patFreq, windowFreq)) {
            count++;
        }

        
        windowFreq[(int)text[i]]++;
        windowFreq[(int)text[i - patLen]]--;
    }

    
    if (areSame(patFreq, windowFreq)) {
        count++;
    }

    return count;
}

int main() {
    
    char text1[] = "forxxorfxdofr";
    char pattern1[] = "for";
    printf("Anagram count (Example 1): %d\n", countAnagramOccurrences(text1, pattern1));  // ➜ 3

    
    char text2[] = "aabaabaa";
    char pattern2[] = "aaba";
    printf("Anagram count (Example 2): %d\n", countAnagramOccurrences(text2, pattern2));  // ➜ 4

    return 0;
}
