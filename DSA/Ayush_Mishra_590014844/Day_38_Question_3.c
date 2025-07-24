#include <stdio.h>
#include <string.h>
#define MAX 100

int main() {
    char expr[MAX];
    char stack[MAX];
    int top = -1;

    printf("Enter expression: ");
    scanf("%s", expr);

    for(int i = 0; expr[i]; i++) {
        if(expr[i] == ')') {
            int flag = 1;
            while(stack[top] != '(') {
                if(stack[top] == '+' || stack[top] == '-' || stack[top] == '*' || stack[top] == '/') {
                    flag = 0;
                }
                top--;
            }
            top--;
            if(flag) {
                printf("Yes\n");
                return 0;
            }
        } else {
            stack[++top] = expr[i];
        }
    }

    printf("No\n");
    return 0;
}
