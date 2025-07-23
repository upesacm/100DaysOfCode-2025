#include <stdio.h>
#include <string.h>
#define MAX 1000

int main() {
    char str[MAX], stack[MAX];
    int top = -1;
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        stack[++top] = str[i];
    }
    for (int i = 0; i < len; i++) {
        str[i] = stack[top--];
    }
    printf("%s\n", str);
    return 0;
}