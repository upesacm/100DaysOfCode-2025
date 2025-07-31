#include <stdio.h>
#include <string.h>

void removeAdjacentDuplicates(char *s) {
    char stack[strlen(s)];
    int top = -1;

    for (int i = 0; s[i]; i++) {
        if (top != -1 && stack[top] == s[i]) {
            top--; 
        } else {
            stack[++top] = s[i];
        }
    }

    stack[++top] = '\0';
    printf("Output: %s\n", stack);
}


int main() {
    char str1[] = "abbaca";
    char str2[] = "azxxzy";

    removeAdjacentDuplicates(str1); 
    removeAdjacentDuplicates(str2); 

    return 0;
}

