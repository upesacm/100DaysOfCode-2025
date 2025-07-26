
#include <stdio.h>
#include <string.h>

#define MAX 1000

void removeAdjDuplicates(char *str) {
    char stack[MAX];
    int top = -1;

    for (int i = 0; str[i]; i++) {
        if (top != -1 && stack[top] == str[i]) {
            top--;
        } else {
            stack[++top] = str[i];
        }
    }

    stack[top + 1] = '\0';
    printf("Result: %s\n", stack);
}

int main() {
    char str[MAX];
    printf("Enter string: ");
    scanf("%s", str);
    removeAdjDuplicates(str);
    return 0;
}
