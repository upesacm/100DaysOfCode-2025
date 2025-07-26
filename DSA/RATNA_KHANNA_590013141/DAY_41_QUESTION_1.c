#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void removeAdjacentDuplicates(char* str) {
    bool changed;
    int len;

    do {
        len = strlen(str);
        char stack[len + 1];
        int top = -1;
        changed = false;

        for (int i = 0; i < len; i++) {
            if (top != -1 && stack[top] == str[i]) {
                top--;
                changed = true;
            } else {
                stack[++top] = str[i];
            }
        }

        stack[top + 1] = '\0';
        strcpy(str, stack);

    } while (changed);
}

int main() {
    char str[1001];
    printf("enter word\n");
    scanf("%1000s", str);
    removeAdjacentDuplicates(str);
    printf("%s\n", str);
    return 0;
}
