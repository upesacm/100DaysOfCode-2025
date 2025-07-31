
#include <stdio.h>

int isRedundant(char* str) {
    char stack[1000];
    int top = -1;
    for (int i = 0; str[i]; i++) {
        if (str[i] == ')') {
            int cnt = 0;
            while (top != -1 && stack[top] != '(') {
                cnt++;
                top--;
            }
            top--;
            if (cnt <= 1) return 1;
        } else {
            stack[++top] = str[i];
        }
    }
    return 0;
}

int main() {
    char expr[] = "((a+b))";
    if (isRedundant(expr)) printf("Yes\n");
    else printf("No\n");
    return 0;
}
