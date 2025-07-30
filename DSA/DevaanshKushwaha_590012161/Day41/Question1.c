#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char input[1000];
    scanf("%s", input);

    char* stack = (char*)malloc(strlen(input) + 1);
    int top = -1;

    for (int i = 0; i < strlen(input); i++) {
        if (top != -1 && stack[top] == input[i]) {
            top--;
        } else {
            stack[++top] = input[i];
        }
    }

    if (top == -1) {
        printf("\n");
    } else {
        stack[top + 1] = '\0';
        printf("%s\n", stack);
    }

    free(stack);

    return 0;
}
