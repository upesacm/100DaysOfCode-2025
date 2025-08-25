#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

struct CharFreq {
    char character;
    int frequency;
};

int compare(const void *a, const void *b) {
    return ((struct CharFreq *)b)->frequency - ((struct CharFreq *)a)->frequency;
}

char* rearrangeCharacters(char* str) {
    int n = strlen(str);
    int freq[MAX_CHAR] = {0};
    for (int i = 0; i < n; i++) {
        freq[str[i]]++;
    }

    struct CharFreq charFreq[MAX_CHAR];
    int uniqueChars = 0;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] > 0) {
            charFreq[uniqueChars].character = (char)i;
            charFreq[uniqueChars].frequency = freq[i];
            uniqueChars++;
        }
    }

    qsort(charFreq, uniqueChars, sizeof(struct CharFreq), compare);

    char* result = (char*)malloc(n + 1);
    int index = 0;

    while (index < n) {
        for (int i = 0; i < uniqueChars; i++) {
            if (charFreq[i].frequency > 0) {
                result[index++] = charFreq[i].character;
                charFreq[i].frequency--;
                if (index < n && charFreq[i].frequency > 0) {
                    // Sort again to maintain order after decrement
                    qsort(charFreq, uniqueChars, sizeof(struct CharFreq), compare);
                }
                break;
            }
        }
        if (index > 1 && result[index - 1] == result[index - 2]) {
            free(result);
            return "";
        }
    }

    result[n] = '\0';
    return result;
}

int main() {
    char str1[] = "aab";
    char* result1 = rearrangeCharacters(str1);
    printf("%s\n", result1);
    free(result1);

    char str2[] = "aaab";
    char* result2 = rearrangeCharacters(str2);
    printf("%s\n", result2);
    free(result2);

    return 0;
}
