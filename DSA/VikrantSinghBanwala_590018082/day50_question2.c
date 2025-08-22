#include <stdio.h>
#include <string.h>
#define ALPHABET_SIZE 256
int areSame(int count1[], int count2[]) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (count1[i] != count2[i]) {
            return 0;
        }
    }
    return 1;
}
int countAnagrams(char *text, char *pattern) {
    int len_text = strlen(text);
    int len_pattern = strlen(pattern);
    if (len_text < len_pattern) {
        return 0;
    }
    int count_pattern[ALPHABET_SIZE] = {0};
    int count_window[ALPHABET_SIZE] = {0};
    for (int i = 0; i < len_pattern; i++) {
        count_pattern[(int)pattern[i]]++;
        count_window[(int)text[i]]++;
    }
    int result = 0;
    if (areSame(count_pattern, count_window)) {
        result++;
    }
    for (int i = len_pattern; i < len_text; i++) {
        count_window[(int)text[i]]++;
        count_window[(int)text[i - len_pattern]]--;
        if (areSame(count_pattern, count_window)) {
            result++;
        }
    }
    return result;
}
int main() {
    char text1[] = "forxxorfxdofr";
    char pattern1[] = "for";
    printf("%d\n", countAnagrams(text1, pattern1));
    char text2[] = "aabaabaa";
    char pattern2[] = "aaba";
    printf("%d\n", countAnagrams(text2, pattern2));
    return 0;
}