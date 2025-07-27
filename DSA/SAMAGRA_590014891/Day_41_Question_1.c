#include <stdio.h>
#include <string.h>

void removeAdjacentDuplicates(char* s) {
    char temp[10001], stack[10001];
    int changed = 1;

    while (changed) {
        int top = -1, i = 0;
        changed = 0;
        while (s[i]) {
            if (top != -1 && stack[top] == s[i]) {
                top--;
                changed = 1;
            } else {
                stack[++top] = s[i];
            }
            i++;
        }
        stack[top + 1] = '\0';
        strcpy(s, stack);
    }

    printf("%s\n", s);
}

int main() {
    char s[10001];
    scanf("%s", s);
    removeAdjacentDuplicates(s);
    return 0;
}
