#include <stdio.h>
#include <string.h>

int compare(int* a, int* b) {
    for (int i = 0; i < 256; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}

int main() {
    char text[1000], pattern[1000];
    scanf("%s %s", text, pattern);

    int count = 0;
    int len_text = strlen(text), len_pat = strlen(pattern);
    int freq_pat[256] = {0}, freq_window[256] = {0};

    for (int i = 0; i < len_pat; i++)
        freq_pat[(int)pattern[i]]++;

    for (int i = 0; i < len_text; i++) {
        freq_window[(int)text[i]]++;
        if (i >= len_pat)
            freq_window[(int)text[i - len_pat]]--;

        if (i >= len_pat - 1)
            if (compare(freq_pat, freq_window))
                count++;
    }

    printf("%d\n", count);
    return 0;
}
