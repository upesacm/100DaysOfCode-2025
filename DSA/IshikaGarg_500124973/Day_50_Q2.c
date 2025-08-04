#include <stdio.h>
#include <string.h>

#define CHAR_COUNT 256

int areSame(int arr1[], int arr2[]) {
    for (int i = 0; i < CHAR_COUNT; i++) {
        if (arr1[i] != arr2[i])
            return 0;
    }
    return 1;
}

int countAnagramOccurrences(char* text, char* pattern) {
    int count = 0;
    int len_text = strlen(text);
    int len_pat = strlen(pattern);

    if (len_pat > len_text)
        return 0;

    int countP[CHAR_COUNT] = {0};
    int countTW[CHAR_COUNT] = {0};

    // Fill frequency of pattern and first window
    for (int i = 0; i < len_pat; i++) {
        countP[(int)pattern[i]]++;
        countTW[(int)text[i]]++;
    }

    // Slide the window
    for (int i = len_pat; i < len_text; i++) {
        if (areSame(countP, countTW))
            count++;

        // Add next char to window
        countTW[(int)text[i]]++;
        // Remove first char of previous window
        countTW[(int)text[i - len_pat]]--;
    }

    // Check last window
    if (areSame(countP, countTW))
        count++;

    return count;
}

int main() {
    char text1[] = "forxxorfxdofr";
    char pattern1[] = "for";
    printf("Occurrences: %d\n", countAnagramOccurrences(text1, pattern1));

    char text2[] = "aabaabaa";
    char pattern2[] = "aaba";
    printf("Occurrences: %d\n", countAnagramOccurrences(text2, pattern2)); 

    return 0;
}

