#include <stdio.h>

int main() {
    char s[1000], stack[1000];
    int top = -1;

    printf("Enter string: ");
    scanf("%s", s);

    for (int i = 0; s[i] != '\0'; i++) {
        top++;
        stack[top] = s[i];
    }

    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = stack[top];
        top--;
    }

    printf("Reversed string: %s\n", s);
    return 0;
}
