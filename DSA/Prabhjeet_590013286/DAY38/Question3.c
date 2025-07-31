#include <stdio.h>
#include <string.h>

int func(char *str) {
    char stack[1000];
    int top = -1;
    for(int i = 0; str[i]; i++) {
        if(str[i] == ')') {
            int cnt = 0;
            while(top != -1 && stack[top] != '(') {
                if(stack[top] == '+' || stack[top] == '-' || stack[top] == '*' || stack[top] == '/')
                    cnt++;
                top--;
            }
            if(cnt == 0) return 1;
            if(top != -1) top--;
        } else {
            stack[++top] = str[i];
        }
    }
    return 0;
}

int main() {
    char s[1000];
    scanf("%s", s);
    if(func(s)) printf("Yes\n");
    else printf("No\n");
    return 0;
}
