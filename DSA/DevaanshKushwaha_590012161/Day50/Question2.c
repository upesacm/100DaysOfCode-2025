#include <stdio.h>
#include <string.h>

int main() {
    char text[1000], pattern[1000];
    printf("Enter the text: ");
    scanf("%s", text);
    printf("Enter the pattern: ");
    scanf("%s", pattern);

    int count = 0;
    int len_text = strlen(text);
    int len_pat = strlen(pattern);
    int freq_pat[26] = {0}, freq_window[26] = {0};

    for (int i = 0; i < len_pat; i++) freq_pat[pattern[i] - 'a']++;
    for (int i = 0; i < len_pat; i++) freq_window[text[i] - 'a']++;

    int match = 1;
    for (int i = 0; i < 26; i++) if (freq_pat[i] != freq_window[i]) match = 0;
    if (match) count++;

    for (int i = len_pat; i < len_text; i++) {
        freq_window[text[i] - 'a']++;
        freq_window[text[i - len_pat] - 'a']--;
        match = 1;
        for (int j = 0; j < 26; j++) if (freq_pat[j] != freq_window[j]) match = 0;
        if (match) count++;
    }

    printf("Number of anagram occurrences: %d", count);
    return 0;
}
