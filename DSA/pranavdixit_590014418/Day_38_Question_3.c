#include <stdio.h>
#include <string.h>

#define MAX 100

int isRedundant(char* expr) {
    char stack[MAX];
    int top = -1;

    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];

        if (ch == ')' ) {
            int count = 0;
            while (top != -1 && stack[top] != '(') {
                stack[top--];
                count++;
            }
            top--; 
            if (count <= 1)
                return 1;
        } else {
            stack[++top] = ch;
        }
    }
    return 0;
}

int main() {
    char expr[] = "((a+b))";

    if (isRedundant(expr))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
