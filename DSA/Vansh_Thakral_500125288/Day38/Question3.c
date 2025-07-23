#include <stdio.h>
#include <string.h>

#define MAX 100

int isRedundant(char *expr) {
    char stack[MAX];
    int top = -1;

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (ch == ')') {
            int count = 0;
            while (top != -1 && stack[top] != '(') {
                char temp = stack[top--];
                if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
                    count++;
            }

            if (top == -1) return 0; 
            top--; 

            if (count == 0)
                return 1; 
        } else {
            stack[++top] = ch;
        }
    }
    return 0;
}


int main() {
    char expr1[] = "((a+b))";
    char expr2[] = "(a+b)";

    printf("Input: %s => Output: %s\n", expr1, isRedundant(expr1) ? "Yes" : "No");
    printf("Input: %s => Output: %s\n", expr2, isRedundant(expr2) ? "Yes" : "No");

    return 0;
}

