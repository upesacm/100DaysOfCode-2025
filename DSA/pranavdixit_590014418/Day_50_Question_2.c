#include <stdio.h>
#include <string.h>

#define CHAR 256

int countAnagrams(char* text, char* pattern) {
    int count = 0;
    int lenT = strlen(text), lenP = strlen(pattern);

    int countP[CHAR] = {0}, countW[CHAR] = {0};

    for (int i = 0; i < lenP; i++) {
        countP[pattern[i]]++;
        countW[text[i]]++;
    }

    for (int i = lenP; i < lenT; i++) {
        int match = 1;
        for (int j = 0; j < CHAR; j++) {
            if (countP[j] != countW[j]) {
                match = 0;
                break;
            }
        }
        if (match) count++;

        countW[text[i]]++;
        countW[text[i - lenP]]--;
    }

    int match = 1;
    for (int j = 0; j < CHAR; j++) {
        if (countP[j] != countW[j]) {
            match = 0;
            break;
        }
    }
    if (match) count++;

    return count;
}

int main() {
    char text[] = "forxxorfxdofr";
    char pattern[] = "for";

    int result = countAnagrams(text, pattern);
    printf("Anagram occurrences: %d\n", result);
    return 0;
}
