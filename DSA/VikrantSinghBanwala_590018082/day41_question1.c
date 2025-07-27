#include<stdio.h>
#include<string.h>
void removeAdjacentDuplicates(char *s) {
    int len = strlen(s);
    char stack[len + 1];
    int top = -1;
    for (int i = 0; i < len; i++) {
        if (top >= 0 && stack[top] == s[i]) {
            top--;
        } else {
            stack[++top] = s[i];
        }
    }
    stack[top + 1] = '\0';
    strcpy(s, stack);
}
int main() {
    char str1[] = "abbaca";
    removeAdjacentDuplicates(str1);
    printf("%s\n", str1);
    char str2[] = "azxxzy";
    removeAdjacentDuplicates(str2);
    printf("%s\n", str2);
    return 0;
}