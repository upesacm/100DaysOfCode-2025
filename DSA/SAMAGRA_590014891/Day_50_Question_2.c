#include <stdio.h>
#include <string.h>
#define CHAR 256

int compare(int a[], int b[]) {
    for (int i = 0; i < CHAR; i++)
        if (a[i] != b[i]) return 0;
    return 1;
}

int countAnagramOccurrences(char *text, char *pattern) {
    int count = 0;
    int lenT = strlen(text), lenP = strlen(pattern);
    if (lenT < lenP) return 0;

    int freqP[CHAR] = {0}, freqT[CHAR] = {0};

    for (int i = 0; i < lenP; i++) {
        freqP[(int)pattern[i]]++;
        freqT[(int)text[i]]++;
    }

    for (int i = lenP; i < lenT; i++) {
        if (compare(freqP, freqT)) count++;
        freqT[(int)text[i]]++;
        freqT[(int)text[i - lenP]]--;
    }

    if (compare(freqP, freqT)) count++;

    return count;
}

int main() {
    char text[] = "aabaabaa";
    char pattern[] = "aaba";
    printf("%d\n", countAnagramOccurrences(text, pattern));
    return 0;
}
