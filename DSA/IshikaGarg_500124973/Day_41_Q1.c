#include <stdio.h>
#include <string.h>

void removeAdjacentDuplicates(char *s) {
    char stack[strlen(s)];
    int top = -1;

    for (int i = 0; s[i]; i++) {
        if (top >= 0 && stack[top] == s[i]) {
            top--;  // pop
        } else {
            stack[++top] = s[i];  // push
        }
    }

    stack[top + 1] = '\0';
    printf("%s\n", stack);
}

int main() {
    char s1[] = "abbaca";
    char s2[] = "azxxzy";

    printf("Output 1: ");
    removeAdjacentDuplicates(s1);  

    printf("Output 2: ");
    removeAdjacentDuplicates(s2); 

    return 0;
}
