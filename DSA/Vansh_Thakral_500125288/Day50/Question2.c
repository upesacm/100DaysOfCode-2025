#include <stdio.h>
#include <string.h>

#define CHAR_COUNT 256

int countAnagrams(char* text, char* pattern) {
    int textLen = strlen(text);
    int patLen = strlen(pattern);

    if (textLen < patLen) return 0;

    int count = 0;
    int textFreq[CHAR_COUNT] = {0};
    int patFreq[CHAR_COUNT] = {0};


    for (int i = 0; i < patLen; i++) {
        patFreq[(int)pattern[i]]++;
        textFreq[(int)text[i]]++;
    }

 
    int compareArrays(int* a, int* b) {
        for (int i = 0; i < CHAR_COUNT; i++) {
            if (a[i] != b[i]) return 0;
        }
        return 1;
    }

 
    for (int i = patLen; i < textLen; i++) {
        if (compareArrays(patFreq, textFreq)) count++;


        textFreq[(int)text[i]]++;
        textFreq[(int)text[i - patLen]]--;
    }


    if (compareArrays(patFreq, textFreq)) count++;

    return count;
}

int main() {
    char text[] = "forxxorfxdofr";
    char pattern[] = "for";

    printf("Count of anagram occurrences: %d\n", countAnagrams(text, pattern));
    return 0;
}

