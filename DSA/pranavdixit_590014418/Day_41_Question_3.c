#include <stdio.h>
#include <string.h>

#define MAX 10000

void removeKdigits(char* num, int k) {
    char stack[MAX];
    int top = -1, len = strlen(num);

    for (int i = 0; i < len; i++) {
        while (top >= 0 && k > 0 && stack[top] > num[i]) {
            top--;
            k--;
        }
        stack[++top] = num[i];
    }

    while (k-- > 0)
        top--;

    int start = 0;
    while (start <= top && stack[start] == '0')
        start++;

    if (start > top)
        printf("0\n");
    else {
        stack[top + 1] = '\0';
        printf("Result: %s\n", stack + start);
    }
}

int main() {
    char num[] = "1432219";
    int k = 3;
    removeKdigits(num, k);
    return 0;
}
