#include <stdio.h>
#include <string.h>

int compare(int a[], int b[]) {
    for(int i = 0; i < 26; i++)
        if(a[i] != b[i])
            return 0;
    return 1;
}

int main() {
    char text[1000], pattern[1000];
    printf("enter text\n");
    scanf("%s", text);
    printf("enter text\n");
    scanf("%s", pattern);

    int len_text = strlen(text), len_pat = strlen(pattern);
    int count = 0;
    int freq_pat[26] = {0}, freq_window[26] = {0};

    for(int i = 0; i < len_pat; i++)
        freq_pat[pattern[i] - 'a']++;

    for(int i = 0; i < len_text; i++) {
        freq_window[text[i] - 'a']++;

        if(i >= len_pat)
            freq_window[text[i - len_pat] - 'a']--;

        if(i >= len_pat - 1)
            if(compare(freq_pat, freq_window))
                count++;
    }

    printf("%d", count);
    return 0;
}
