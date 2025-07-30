#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char num[1000];
    int k;
    scanf("%s", num);
    scanf("%d", &k);

    int n = strlen(num);
    char* stack = (char*)malloc(n + 1);
    int top = -1;

    for (int i = 0; i < n; i++) {
        char digit = num[i];
        while (top != -1 && digit < stack[top] && k > 0) {
            top--;
            k--;
        }
        stack[++top] = digit;
    }

    while (k > 0 && top != -1) {
        top--;
        k--;
    }

    int leadingZeros = 0;
    while (leadingZeros <= top && stack[leadingZeros] == '0') {
        leadingZeros++;
    }

    if (leadingZeros > top) {
        printf("0\n");
    } else {
        stack[top + 1] = '\0';
        printf("%s\n", stack + leadingZeros);
    }

    free(stack);

    return 0;
}
