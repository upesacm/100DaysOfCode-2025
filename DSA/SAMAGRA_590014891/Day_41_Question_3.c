#include <stdio.h>
#include <string.h>

void removeKdigits(char* num, int k) {
    char stack[10001];
    int top = -1, i = 0;

    while (num[i]) {
        while (top >= 0 && k > 0 && stack[top] > num[i]) {
            top--;
            k--;
        }
        stack[++top] = num[i];
        i++;
    }

    top -= k;
    int start = 0;
    while (start <= top && stack[start] == '0') start++;

    if (start > top) printf("0\n");
    else {
        for (i = start; i <= top; i++) putchar(stack[i]);
        printf("\n");
    }
}

int main() {
    char num[10001];
    int k;
    scanf("%s %d", num, &k);
    removeKdigits(num, k);
    return 0;
}
