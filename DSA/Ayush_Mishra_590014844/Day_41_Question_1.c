#include <stdio.h>
#include <string.h>

void removeAdjacentDuplicates(char* s) {
    char stack[1000];
    int top = -1;
    for (int i = 0; s[i]; i++) {
        if (top >= 0 && stack[top] == s[i]) top--;
        else stack[++top] = s[i];
    }
    stack[++top] = '\0';
    printf("%s\n", stack);
}

int main() {
    char str[1000];
    printf("Enter the string: ");
    scanf("%s", str);
    removeAdjacentDuplicates(str);
    return 0;
}
