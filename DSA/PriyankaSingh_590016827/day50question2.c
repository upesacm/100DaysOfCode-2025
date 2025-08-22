#include <stdio.h>
#include <string.h>

#define CHAR 256

int compare(int *count1, int *count2) {
    for (int i = 0; i < CHAR; i++)
        if (count1[i] != count2[i])
            return 0;
    return 1;
}

int main() {
    char text[100], pattern[100];
    int countP[CHAR] = {0}, countT[CHAR] = {0}, i, res = 0;

    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter pattern: ");
    scanf("%s", pattern);

    int N = strlen(text);
    int M = strlen(pattern);

    for(i = 0; i < M; i++) {
        countP[pattern[i]]++;
        countT[text[i]]++;
    }

    for(i = M; i < N; i++) {
        if(compare(countP, countT))
            res++;

        countT[text[i]]++;
        countT[text[i - M]]--;
    }

    if(compare(countP, countT))
        res++;

    printf("Number of anagram occurrences: %d\n", res);
    return 0;
}
