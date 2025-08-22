#include <stdio.h>
#include <string.h>
#define CHAR 256  

int compare(int *a, int *b) {
    for (int i = 0; i < CHAR; i++) {
        if (a[i] != b[i])
            return 0;
    }
    return 1;
}

int countAnagrams(char *text, char *pattern) {
    int count = 0;
    int len_text = strlen(text);
    int len_pat = strlen(pattern);

    if (len_pat > len_text) return 0;

    int freq_pat[CHAR] = {0};
    int freq_window[CHAR] = {0};

    for (int i = 0; i < len_pat; i++) {
        freq_pat[(int)pattern[i]]++;
        freq_window[(int)text[i]]++;
    }

    for (int i = len_pat; i < len_text; i++) {
        if (compare(freq_pat, freq_window))
            count++;

        freq_window[(int)text[i]]++;                   
        freq_window[(int)text[i - len_pat]]--;     
    }

    if (compare(freq_pat, freq_window))
        count++;

    return count;
}

int main() {
    char text[] = "forxxorfxdofr";
    char pattern[] = "for";

    int result = countAnagrams(text, pattern);
    printf("Number of anagram occurrences: %d\n", result);

    return 0;
}
